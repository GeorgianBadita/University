//
// Created by georg on 10/15/2019.
//
#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
#include <thread>
#include "Utils.h"

#define MAX_NUM 10


void matrixMulParallel(int ind, std::vector<std::vector<int>>* A, std::vector<std::vector<int>>* B,
        std::vector<std::vector<int>>* C, int n, int step){
    int tNum = ind;

    int line = tNum / n;
    int col = tNum % n;

    while(line < n){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += (*A)[line][j] * (*B)[j][col];
        }

        (*C)[line][col] = sum;
        tNum += step;
        line = tNum / n;
        col = tNum % n;
    }
}



void matrixSumParallel(int ind, std::vector<std::vector<int>>* A, std::vector<std::vector<int>>* B,
                       std::vector<std::vector<int>>* C, int n, int step){
    int tNum = ind;

    int line = tNum / n;
    int col = tNum % n;

    while(line < n){
        (*C)[line][col] = (*A)[line][col] + (*B)[line][col];
        tNum += step;
        line = tNum / n;
        col = tNum % n;
    }
}

int main1(){
    srand(time(nullptr));
    int n, numThreads;


    std::cout << "Matrix dimension:";
    std::cin >> n;
    std::cout << '\n';
    std::cout << "Number of threads:";
    std::cin >> numThreads;

    auto A = Utils::createMatrix(n, false, MAX_NUM);
    auto B = Utils::createMatrix(n, false, MAX_NUM);
    auto C = Utils::createMatrix(n, true, MAX_NUM);
    std::vector<std::thread> threads;
    auto start = std::chrono::steady_clock::now();
    for(int i = 0; i<numThreads; i++){
        std::thread th(matrixMulParallel, i, &A, &B, &C, n, numThreads);
        threads.push_back(std::move(th));
    }
    for(auto& x : threads){
        x.join();
    }

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << "Parallel time for matrix mul: " << std::chrono::duration <double, std::milli> (diff).count()*0.001 << " s" << std::endl;
    /*
    printMatrix(A);
    std::cout << '\n';
    printMatrix(B);
    std::cout << '\n';
    printMatrix(C);
     */
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
        std::thread th(matrixSumParallel, i, &A, &B, &C, n, numThreads);
        threadSum.push_back(std::move(th));
    }
    for(auto& x : threadSum){
        x.join();
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

    return 0;
}