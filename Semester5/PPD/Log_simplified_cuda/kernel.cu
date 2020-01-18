
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;


__global__ void applyFilterGPU(int* in, int* out, int lines, int cols, int channels) {

	int id = blockDim.x * blockIdx.x + threadIdx.x;
	if (id < lines*cols*channels) {
		//out[id] = in[id]+20;

		//apply kernel
		int line = id / (cols*channels);
		int col = (id % (cols*channels)) / channels;
		int channel = id % channels;
		
			
		int value = 0;
		if (line > 1 && line < (lines-2) && col > 1 && col < (cols-2)) {
			//center
			value += 16*in[id];
			
			//north
			value += -2*in[id - cols*channels];

			//east
			value += -2*in[id+channels];

			//south
			value += -2*in[id+cols*channels];

			//west
			value += -2*in[id-channels];
			
			//north west
			value += -1*in[id - cols*channels - channels];

			//north east
			value += -1*in[id - cols*channels + channels];

			//south east
			value += -1*in[id + cols*channels + channels];

			//south west
			value += -1*in[id + cols*channels - channels];
			
			//3rd level convolutions
			//top

			value += 0 *in[id - 2* cols * channels - 2*channels];
			value += 0 * in[id - 2 * cols * channels -  channels];
			value += -1 * in[id - 2 * cols * channels];
			value += 0 * in[id - 2 * cols * channels + channels];
			value += 0 * in[id - 2 * cols * channels + 2 * channels];

			//right
			value += 0* in[id - 1 * cols * channels + 2 * channels];
			value += -1 * in[id - 0 * cols * channels + 2 * channels];
			value += 0 * in[id + 1 * cols * channels + 2 * channels];

			//left
			value += 0 * in[id - 1 * cols * channels - 2 * channels];
			value += -1 * in[id - 0 * cols * channels - 2 * channels];
			value += 0 * in[id + 1 * cols * channels - 2 * channels];


			//down
			value += 0 * in[id + 2 * cols * channels - 2 * channels];
			value += 0 * in[id + 2 * cols * channels - channels];
			value += -1 * in[id + 2 * cols * channels];
			value += 0 * in[id + 2 * cols * channels + channels];
			value += 0 * in[id + 2 * cols * channels + 2 * channels];

			value = value / 1;
		}
		else {
			value = 0;
		}

		out[id] = value;
	}
}



int* flatten(int*** matrix, int lines, int cols, int channels) {

	int* flat = (int*)malloc(lines*cols*channels * sizeof(int));
	int id = 0;
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < cols; j++) {
			for (int c = 0; c < channels; c++) {
				flat[id] = matrix[i][j][c];
				id++;
			}
		}
	}
	return flat;
}

int*** unflatten(int* arr, int lines, int cols, int channels) {
	int*** img = (int***)malloc(lines * sizeof(int**));
	int id = 0;

	for (int i = 0; i < lines; i++) {
		img[i] = (int**)malloc(cols * sizeof(int*));

		for (int j = 0; j < cols; j++) {
			img[i][j] = (int*)malloc(channels * sizeof(int));

			for (int c = 0; c < channels; c++) {
				img[i][j][c] = arr[id];
				id++;
			}
		}
	}
	return img;
}

void applyFilter() {

	//read the matrix
	ifstream in("pixels.txt");
	int lines, cols, channels;
	in >> lines >> cols >> channels;

	int BLOCK_SIZE = 1000;

	int blockCount = ((lines*cols*channels) / BLOCK_SIZE) + 1;
	

	//matrix read
	int*** matrix = (int***)malloc(lines * sizeof(int**));
	for (int i = 0; i < lines; i++) {
		matrix[i] = (int**)malloc(cols * sizeof(int*));

		for (int j = 0; j < cols; j++) {
			int* line = (int*)malloc(channels * sizeof(int));

			in >> line[0] >> line[1] >> line[2];
			
			matrix[i][j] = line;
		}
	}

	int size = lines * cols*channels;
	//flatten matrix
	int* flatMatrix = flatten(matrix, lines, cols, channels);
	int* result = (int*)malloc(size * sizeof(int));

	//copy flatMatrix to the device array
	int* deviceMatrix, *deviceResult;
	cudaMalloc(&deviceMatrix, size * sizeof(int));
	cudaMalloc(&deviceResult, size * sizeof(int));

	cudaMemcpy(
		deviceMatrix, flatMatrix,
		size * sizeof(int),
		cudaMemcpyHostToDevice
	);

	//call the filter function
	applyFilterGPU <<< blockCount,1000 >>> (deviceMatrix, deviceResult, lines, cols, channels);

	//copy from deviceResult in result
	cudaMemcpy(
		result, deviceResult,
		size * sizeof(int),
		cudaMemcpyDeviceToHost
	);

	int*** img = unflatten(result, lines, cols, channels);





	ofstream out("pixels.txt");
	out << lines << " " << cols << " " << channels << "\n";
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < cols; j++) {
			for (int k = 0; k < channels; k++) {
				out << img[i][j][k] << " ";
			}
			out << "\n";
		}
	}

	out.close();
}
int main()
{
	char* inImgPath = "/home/geo/Programming/University/Semester5/PPD/Log_simplified_cuda/dia.jpg";
	char* outImgPath = "/home/geo/Programming/University/Semester5/PPD/Log_simplified_cuda/dia.jpg";
	char* inCommand = "conda activate ai & python in.py /home/geo/Programming/University/Semester5/PPD/Log_simplified_cuda/dia.jpg" ;
	char* outCommand = "conda activate ai & python out.py /home/geo/Programming/University/Semester5/PPD/Log_simplified_cuda/dia1.jpg" ;
	
	//system(inCommand);			//read pixel values to pixels.txt

	applyFilter();
	
	//system(outCommand);			//write pixel values to image



	return 0;
}
