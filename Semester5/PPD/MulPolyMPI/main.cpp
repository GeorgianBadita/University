#include <mpi.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#define MASTER_RANK 0
#define N 4
#define MAX 10
#define MIN 0

/**
 * Function to check if a number is power of 2
 * @param n - integer
 * @return - true if n is 2^k, false otherwise
 */
bool isPowerOf2(int n){
    return (n & (n - 1)) == 0;
}

/**
 * Function to generate a random polynomial
 * @param n - degree of the polynomial
 * @param min - min value for coefficients
 * @param max - max value for coefficients
 * @return - the generated polynomial
 */
std::vector<int> getRandomPoly(int n, int min, int max) {
    while (!isPowerOf2(n)) {
        n++;
    }
    std::vector<int> coeffs;
    for (int i = 0; i < n; i++) {
        int currCoeff = rand() % (max - min) + min;
        coeffs.push_back(currCoeff);
    }

    return coeffs;
}

/**
 * Function to print a polynomial
 * @param number - polynomial represented as a vector of integer
 */
void printPolynomial(std::vector<int> number){
    for(int i = number.size() - 1; i>=0; --i){
        if(i == number.size() - 2 && number[i + 1] == 0){
            if(number[i] > 0){
                std::cout << number[i] << "x^" << std::to_string(i);
            }else{
                std::cout << std::abs(number[i]) << "x^" << std::to_string(i);
            }
        }
        if(number[i] != 0 && i != 0) {
            if(i == number.size() - 1) {
                if(number[i] > 0) {
                    std::cout << number[i] << "x^" << std::to_string(i);
                }else{
                    std::cout << "-" << std::abs(number[i]) << "x^" << std::to_string(i);
                }
            }else{
                if(number[i] > 0){
                    std::cout << " + " << number[i] << "x^" << std::to_string(i);
                }else{
                    std::cout << " - " << std::abs(number[i]) << "x^" << std::to_string(i);
                }
            }
        }else if(i == 0 && number[i] != 0){
            if(number[i] > 0){
                std::cout << " + " << number[i];
            }else{
                std::cout << " - " << std::abs(number[i]);
            }
        }
    }
}


void nSqAlg(int argc, char** argv){
    int rank, numProc;
    int* forProcessFirst;
    int* forProcessSecond;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &numProc);
    if(rank == MASTER_RANK){
        auto firstPoly = getRandomPoly(N, MIN, MAX);
        auto secondPoly = getRandomPoly(N, MIN, MAX);
        int* finalResult = (int*)malloc((2*N - 1)* sizeof(int));
        std::cout << "MASTER PROCESS GENERATED: \n";
        printPolynomial(firstPoly);
        std::cout << '\n';
        printPolynomial(secondPoly);
        std::cout << '\n';
        numProc--; //the master processes only reads and distributes the numbers there are num_proc - 1 proceses for calculation
        int perProcess = N / numProc; //per process
        int rem = N % numProc; //rem

        int start = 0, stop = 0;
        forProcessFirst = (int*)malloc(sizeof(int)*(N + 1)); //allocate memory for for_process_a
        forProcessSecond = (int*)malloc(sizeof(int)*(perProcess + 1)); //allocate memory for for_process_b
        for(int i = 0; i < firstPoly.size(); i++){
            forProcessFirst[i] = firstPoly[i];
        }

        for (int i = 1; i <= numProc; i++) {
            stop = start + perProcess;
            if (rem > 0) {
                stop += 1;
                rem -= 1;
            }

            for (int j = start; j < stop; j++) {
                forProcessSecond[j - start] = secondPoly[j]; //copy digits of b
            }
            /*
            std::cout << "SENT TO " << i << '\n';
            std::cout << "FIRST: \n";
            for(int k = 0; k < firstPoly.size(); k++){
                std::cout << forProcessFirst[k] << ' ';
            }
            std::cout << "\nSECOND: \n";
            for(int k = 0; k < stop - start; k++){
                std::cout << forProcessSecond[k] << ' ';
            }
            std::cout << '\n';
            */
            int count_b = stop - start; //number of digits between start and stop
            int count_a = firstPoly.size();
            int resultSize = 2 * N - 1;
            int* localResult = (int*)malloc(resultSize * sizeof(int));
            MPI_Send(&resultSize, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Send(&count_a, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Send(&count_b, 1, MPI_INT, i, 0, MPI_COMM_WORLD); //sending number of digits
            MPI_Send(forProcessFirst, count_a, MPI_INT, i, 0, MPI_COMM_WORLD); //sending count digits from a
            MPI_Send(forProcessSecond, count_b, MPI_INT, i, 0, MPI_COMM_WORLD); //sending count digits from b
            MPI_Send(&start, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Recv(localResult, resultSize, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //recv the calculated result
            for(int p = 0; p<resultSize; p++){
                finalResult[p] += localResult[p];
            }
            std::cout << '\n';
            start = stop;
            free(localResult);
        }
        std::vector<int> fnRes;
        for(int i = 0; i< 2 * N -  1; i++){
            fnRes.push_back(finalResult[i]);
        }
        printPolynomial(fnRes);
        std::cout << '\n';
        free(finalResult);
        free(forProcessFirst);
        free(forProcessSecond);
    }else{
        int count_b;
        int count_a;
        int start;
        int resultSize;
        MPI_Recv(&resultSize, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&count_a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //recv number of digits
        MPI_Recv(&count_b, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //recv number of digits
        int* recvFirst = (int*)malloc(sizeof(int) * count_b); //allocate memory
        int* recvSecond = (int*)malloc(sizeof(int) * count_b);
        int* result = (int*)malloc(sizeof(int)* resultSize);
        MPI_Recv(recvFirst, count_a, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //recv the digits from a
        MPI_Recv(recvSecond, count_b, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //recv the digits from b
        MPI_Recv(&start, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        /*std::cout << "Process with rank " << rank << " received: \n";
        std::cout << "First Recv: \n";
        for(int i = 0; i<count_a; i++){
            std::cout << recvFirst[i] << ' ';
        }

        std::cout << "\nSecond Recv:\n";
        for(int i = 0; i<count_b; i++){
            std::cout << recvSecond[i] << ' ';
        }
        std::cout << '\n';*/
        for(int i = 0; i<count_b; i++){
            for(int j = 0; j<count_a; j++){
                int prod = recvFirst[j] * recvSecond[i];
                result[start + i + j] += prod;
            }
        }
        MPI_Send(result, resultSize, MPI_INT, 0, 0, MPI_COMM_WORLD); //sending the local_res
        free(result);
        free(recvFirst);
        free(recvSecond);
    }
    MPI_Finalize();
}

std::vector<int> karatsuba(std::vector<int> A, std::vector<int> B){

    std::vector<int> product = std::vector<int>(2*B.size(), 0);

    if(B.size() == 1){
        product[0] = A[0]*B[0];
        return product;
    }

    int halfSize = A.size() / 2;

    //Arrays for halved factors
    auto aLow = std::vector<int>(halfSize, 0);
    auto aHigh = std::vector<int>(halfSize, 0);
    auto bLow = std::vector<int>(halfSize, 0);
    auto bHigh = std::vector<int>(halfSize, 0);

    auto aLowHigh = std::vector<int>(halfSize, 0);
    auto bLowHigh = std::vector<int>(halfSize, 0);
    //A - multiplicand, B - multiplier
    //Fill low and high arrays
    for(int i = 0; i<halfSize; ++i){
        aLow[i] = A[i];
        aHigh[i] = A[halfSize + i];
        aLowHigh[i] = aHigh[i] + aLow[i];

        bLow[i] = B[i];
        bHigh[i] = B[halfSize + i];
        bLowHigh[i] = bHigh[i] + bLow[i];
    }

    //Recursively call method on smaller arrays
    auto productLow = karatsuba(aLow, bLow);
    auto productHigh = karatsuba(aHigh, bHigh);

    auto productLowHigh = karatsuba(aLowHigh, bLowHigh);

    //Construct middle portion of the product
    auto productMiddle = std::vector<int>(A.size(), 0);
    for(int i = 0; i<A.size(); ++i){
        productMiddle[i] = productLowHigh[i] - productLow[i] - productHigh[i];
    }

    //Assemble the product from the low, middle and high parts
    int midOffset = A.size() / 2;
    for(int i = 0; i < A.size(); ++i){
        product[i] += productLow[i];
        product[i + A.size()] += productHigh[i];
        product[i + midOffset] += productMiddle[i];
    }

    return product;
}

int main(int argc, char *argv[]){

    //nSqAlg(argc, argv);
    MPI_Init(&argc, &argv);
    int rank, numProc;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &numProc);
    if(rank == MASTER_RANK) {
        auto firstPoly = getRandomPoly(N, MIN, MAX);
        auto secondPoly = getRandomPoly(N, MIN, MAX);
        std::cout << "FROM MASTER PROCESS: \n";
        printPolynomial(firstPoly);
        std::cout << '\n';
        printPolynomial(secondPoly);
        std::cout << '\n';
        int* firstPolyCpy = (int*)malloc(firstPoly.size() * sizeof(int));
        int* secondPolyCpy = (int*)malloc(secondPoly.size() * sizeof(int));
        for(int i = 0; i<firstPoly.size(); i++){
            firstPolyCpy[i] = firstPoly[i];
            secondPolyCpy[i] = secondPoly[i];
        }
        int count = N;
        int resultSize = 2 * N;
        int* finalRes = (int*)malloc(resultSize * sizeof(int));
        MPI_Send(&count, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(firstPolyCpy, count, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(secondPolyCpy, count, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(finalRes, resultSize, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::vector<int> fnRes;
        fnRes.reserve(resultSize);
        for(int k = 0; k<resultSize; k++){
            fnRes.push_back(finalRes[k]);
        }
        std::cout << "RESULT: \n";
        printPolynomial(fnRes);
        std::cout << '\n';
        free(finalRes);
    }else{
        int count;
        MPI_Recv(&count, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //recv number of digits
        int* recvFirst = (int*)malloc(sizeof(int) * count); //allocate memory
        int* recvSecond = (int*)malloc(sizeof(int) * count); //allocate memory
        MPI_Recv(recvFirst, count, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //recv the digits from a
        MPI_Recv(recvSecond, count, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //recv the digits from b
        std::vector<int> a;
        std::vector<int> b;
        for(int i = 0; i<count; i++){
            a.push_back(recvFirst[i]);
            b.push_back(recvSecond[i]);
        }
        std::cout << "RECV FROM MASTER: \n";
        printPolynomial(a);
        std::cout << '\n';
        printPolynomial(b);
        std::cout << '\n';
        auto result = karatsuba(a, b);
//        std::cout << "RESULT CALCULATED: \n";
//        printPolynomial(result);
        std::cout << '\n';
        int* finRes = (int*)malloc(result.size() * sizeof(int));
        for(int i = 0; i<result.size(); i++){
            finRes[i] = result[i];
        }
        MPI_Send(finRes, result.size(), MPI_INT, 0, 0, MPI_COMM_WORLD);
        free(finRes);
        free(recvFirst);
        free(recvSecond);
    }
    return 0;
}