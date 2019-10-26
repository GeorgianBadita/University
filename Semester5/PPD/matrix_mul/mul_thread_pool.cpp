//
// Created by georg on 10/26/2019.
//

#include <future>
#include <vector>
#include <iostream>
#include "Tasks.h"
#include "Utils.h"


#define MAX_NUM 10

int main(){
    srand(time(nullptr));
    int n, numThreads;


    std::cout << "Matrix dimension:";
    std::cin >> n;
    std::cout << '\n';
    std::cout << "Number of threads:";
    std::cin >> numThreads;

    std::vector< std::future<int> > results;
    ThreadPool pool(numThreads);


    auto A = Utils::createMatrix(n, false, MAX_NUM);
    auto B = Utils::createMatrix(n, false, MAX_NUM);
    auto C = Utils::createMatrix(n, true, MAX_NUM);

    auto start = std::chrono::steady_clock::now();
    for(int i = 0; i<numThreads; i++){
        int step = numThreads;
        results.emplace_back(
                pool.enqueue([i, n, &A, &B, &C, step](){
                    int tNum = i;

                    int line = tNum / n;
                    int col = tNum % n;

                    while(line < n){
                        int sum = 0;
                        for(int j = 0; j < n; j++){
                            sum += A[line][j] * B[j][col];
                        }

                        C[line][col] = sum;
                        tNum += step;
                        line = tNum / n;
                        col = tNum % n;
                    }
                    return -1;
                })
        );
    }
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << "Parallel time for matrix mul: " << std::chrono::duration <double, std::milli> (diff).count()*0.001 << " s" << std::endl;
//    Utils::printMatrix(A);
//    Utils::printMatrix(B);
//    Utils::printMatrix(C);

    C = Utils::createMatrix(n, true, MAX_NUM);
    auto start1 = std::chrono::steady_clock::now();
    Utils::matrixMulSequential(A, B, C, n);
    auto end1 = std::chrono::steady_clock::now();
    auto diff1 = end1 - start1;
    std::cout << "Sequential time for matrix mul: " << std::chrono::duration <double, std::milli> (diff1).count()*0.001 << " s" << std::endl;
    //SUM

    C = Utils::createMatrix(n, true, MAX_NUM);
    std::vector<std::thread> threadSum;
    auto start2 = std::chrono::steady_clock::now();
    for(int i = 0; i<numThreads; i++){
        int step = numThreads;
        results.emplace_back(
                pool.enqueue([i, n, &A, &B, &C, step](){
                    int tNum = i;

                    int line = tNum / n;
                    int col = tNum % n;

                    while(line < n){
                        C[line][col] = A[line][col] + B[line][col];
                        tNum += step;
                        line = tNum / n;
                        col = tNum % n;
                    }
                    return -1;
                })
        );
    }
    auto end2 = std::chrono::steady_clock::now();
    auto diff2 = end2 - start2;
    std::cout << "Parallel time for matrix sum: " << std::chrono::duration <double, std::milli> (diff2).count()*0.001 << " s" << std::endl;

    C = Utils::createMatrix(n, true, MAX_NUM);
    auto start3 = std::chrono::steady_clock::now();
    Utils::matrixSumSquential(A, B, C, n);
    auto end3 = std::chrono::steady_clock::now();
    auto diff3 = end3 - start3;
    std::cout << "Sequential time for matrix sum: " << std::chrono::duration <double, std::milli> (diff3).count()*0.001 << " s" << std::endl;

}