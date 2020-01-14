#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <cuda_runtime.h>
#include <array>
#include <assert.h>
#include <iostream>
#include <numeric>
#define checkCudaErrors(val) assert(cudaSuccess == val)

const int NUM_CHANNELS = 3;
const int KERNEL_DIM = 5;
const int KERNEL_RADIUS = (KERNEL_DIM - 1) / 2;
__device__ __constant__ float d_KERNEL[KERNEL_DIM];
texture<uint8_t, cudaTextureType2D> TEXTURE8U;


// Loop unrolling templates for maximixing instruction-level parallelism
template<int i>//, bool row>
__device__ float convolutionUnroll(const float x, const float y)
{
    float xValRow = x + (float)NUM_CHANNELS * (float)(KERNEL_RADIUS - i);
    float yValCol = y + (float)KERNEL_RADIUS - (float)i;

    return (float)tex2D(TEXTURE8U, xValRow, y) * d_KERNEL[i] +
        (float)tex2D(TEXTURE8U, x, yValCol) * d_KERNEL[i] +
        convolutionUnroll<i-1>(x,y);
}

// Loop unrolling base case template specialization
template<>
__device__ float convolutionUnroll<-1>(const float x, const float y)
{
    return 0;
}




// Texture convolution
__global__ void convolution(uint8_t* dst, const int imgWidth,
                            const int imgHeight)
{
    const int xIdx = threadIdx.x + blockIdx.x * blockDim.x;
    const int yIdx = threadIdx.y + blockIdx.y * blockDim.y;
    const float x = (float)xIdx + 0.5f;
    const float y = (float)yIdx + 0.5f;
    const int i = 2 * KERNEL_RADIUS;

    if (xIdx < imgWidth && yIdx < imgHeight)
    {
        dst[yIdx * imgWidth + xIdx] =
            (uint8_t)roundf(convolutionUnroll<i>(x, y));
//            (uint8_t)roundf(convolutionUnrollCol<i>(x, y));
    }
}


cv::Mat createLOGKernel1D(int ksize, float sigma)
{
    using namespace cv;

    float std2 = sigma * sigma;
    std::vector<float> seq(ksize);
    std::iota(begin(seq), end(seq), -(ksize-1)/2);
    Mat_<float> kSeq(1, ksize, seq.data());

    Mat XX;
    multiply(kSeq, kSeq, XX);

    Mat H = -(XX / (2.*std2));
    exp(H, H);

    double minVal, maxVal;
    minMaxIdx(H, &minVal, &maxVal);
    Mat mask = H < std::numeric_limits<float>::epsilon()*maxVal;
    H.setTo(0, mask);

    float sumh = sum(H)[0];
    if (sumh != 0) H /= sumh;

    Mat H1;
    multiply(H, (XX - 2.*std2)/(std2 * std2), H1);
    H = H1 - sum(H1)[0] / ksize;
    return H;
}


// Calculates Laplace of Gaussian kernel
cv::Mat createLOGKernel2D(int ksize, double sigma)
{
    using namespace cv;
    using namespace std;

    Mat kernel(ksize, ksize, CV_64F);
    Mat X(ksize, ksize, CV_64F);
    Mat Y(ksize, ksize, CV_64F);
    int siz = (ksize-1)/2;
    double std2 = sigma*sigma;

    vector<double> seq(ksize);
    iota(begin(seq), end(seq), -siz);
    Mat seqX(1, ksize, CV_64F, seq.data());
    Mat seqY(ksize, 1, CV_64F, seq.data());
    repeat(seqX, ksize, 1, X);
    repeat(seqY, 1, ksize, Y);

    Mat XX, YY;
    multiply(X, X, XX);
    multiply(Y, Y, YY);

    Mat H = -(XX + YY) / (2.*std2);
    exp(H, H);

    double minVal, maxVal;
    minMaxIdx(H, &minVal, &maxVal);
    Mat mask = H < numeric_limits<double>::epsilon()*maxVal;
    H.setTo(0, mask);

    double sumh = sum(H)[0];
    if (sumh != 0) H /= sumh;

    Mat H1;
    multiply(H, (XX + YY - 2*std2) / (std2*std2), H1);
    H = H1 - sum(H1)[0] / (ksize*ksize);
    return H;
}


// A Laplacian morphological operation boils down to the convolution
// of a Laplacian-- Laplacian of Gaussian (LoG) in this case kernel over
// the image data. Separable texture-based convolution is a quick way
// to perform convolutions in CUDA, but Laplacian kernels are not
// separable. To get around this, I perform separate vertical and
// horizontal convolutions with a 1D LoG kernel and its transpose
// and summing the results.
int main(int argc, char** argv)
{
    using namespace cv;
    using namespace std;

    if (argc < 4)
    {
        cout << "Usage: laplacefilter <image path> <image width> <image height> [gaussian sigma]\n";
        return -1;
    }

    bool saveImages = true;
    float sigma = 0.5;

    if (argc >= 5) sigma = atof(argv[4]);

    // Load image
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);
    int numBytes = 6 * (width*height)/4;
    unsigned char bytes[numBytes];
    ifstream in(argv[1], ifstream::binary|ifstream::in);
    in.read((char*)bytes, numBytes);
    Mat yuv(height+height/2, width, CV_8UC1, bytes);
    Mat img(height, width, CV_8UC3);
    cvtColor(yuv, img, COLOR_YUV420p2RGB);
    int fullWidth = img.channels() * img.cols;

    if (img.empty())
    {
        cout << "Empty image!\n";
        return -1;
    }

    assert(img.rows == height);
    assert(img.cols == width);
    assert(img.channels() == NUM_CHANNELS);

    // Calculate grid and block sizes.
    int numImgBytes = img.step[0] * img.rows;
    dim3 threads(16, 12); // 6 * 32 (warp size)
    dim3 blocks(ceil((float)fullWidth/threads.x), ceil((float)img.rows/threads.y));

    cout << img.cols << " " << img.rows << " " << img.channels() << endl;
    cout << "num Bytes: " << numImgBytes << endl;
    cout << "grid: (" << blocks.x << ", " << blocks.y << ") block: (" << threads.x << ", " << threads.y << ")\n";

    Mat logKernel = createLOGKernel1D(KERNEL_DIM, sigma);
//    Mat logKernel = createLOGKernel2D(KERNEL_DIM, sigma);
    vector<uint8_t> h_result(numImgBytes);
    uint8_t *d_result;
    cudaArray* cu_imgArray;
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    // Allocate array memory & bind
    cudaChannelFormatDesc channelDesc =
        cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindUnsigned);
    checkCudaErrors(cudaMallocArray(&cu_imgArray, &channelDesc, fullWidth, img.rows));
    checkCudaErrors(cudaBindTextureToArray(TEXTURE8U, cu_imgArray));
    checkCudaErrors(cudaMalloc((void**)&d_result, numImgBytes));
    checkCudaErrors(cudaMemset(d_result, 0, numImgBytes));

    // Copy everything to the device
    checkCudaErrors(cudaMemcpyToSymbol(d_KERNEL, logKernel.data, KERNEL_DIM * sizeof(float)));
    checkCudaErrors(cudaMemcpyToArray(cu_imgArray, 0, 0, img.data, numImgBytes, cudaMemcpyHostToDevice));

    // Run & time kernel
    cudaEventRecord(start);
    convolution<<<blocks, threads>>>(d_result, fullWidth, img.rows);
    cudaEventRecord(stop);
    cudaEventSynchronize(stop);

    // Copy & free gpu mempory
    checkCudaErrors(cudaMemcpy(h_result.data(), d_result, numImgBytes, cudaMemcpyDeviceToHost));
    checkCudaErrors(cudaFree(d_result));
    checkCudaErrors(cudaFreeArray(cu_imgArray));

    // Record run duration & throughput
    float time;
    cudaEventElapsedTime(&time, start, stop);
    cout << "Kernel runtime: " << time << " ms\n";
    cout << "Bandwidth: " << numImgBytes*2/time/1e6 << " GB/s\n";
    cout << width * height * 1e-6 / (0.001 * time) << " MPixels/s\n";

    // Display & save
    Mat resultImg(img.rows, img.cols, img.type(), h_result.data());
    Mat bgr[img.channels()];
    split(resultImg, bgr);
    vector<string> channelNames = {"redChannel", "greenChannel", "blueChannel"};

    for (int i=0; i<img.channels(); ++i)
    {
        int idx = img.channels() - i - 1;
        namedWindow(channelNames[idx], WINDOW_NORMAL);
        imshow(channelNames[idx], bgr[i]);
        if (saveImages) imwrite(channelNames[idx] + ".jpg", bgr[i]);
    }

    if (saveImages) imwrite("allChannels.jpg", resultImg);
    namedWindow("All Channels", WINDOW_NORMAL);
    imshow("All Channels", resultImg);
    waitKey(0);

    return 0;
}
