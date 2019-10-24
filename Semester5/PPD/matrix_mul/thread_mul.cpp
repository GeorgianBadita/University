//
// Created by georg on 10/15/2019.
//
#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
#include <thread>

#define MAX_NUM 10

std::vector<std::vector<int>> createMatrix(int n, bool empty){
    std::vector<std::vector<int>> matrix;
    for(int i = 0; i<n; i++){
        std::vector<int> line(n);
        for(int j = 0; j<n; j++){
            if(!empty) {
                line[j] = rand() % MAX_NUM;
            }else{
                line[j] = 0;
            }
        }
        matrix.push_back(line);
    }

    return matrix;
}

void printMatrix(const std::vector<std::vector<int>>& matrix){
    for(const auto& line : matrix){
        for(const auto& elem : line){
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }
}

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

void matrixMulSequential(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B,
                         std::vector<std::vector<int>>& C, int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int sum = 0;
            for(int k = 0; k<n; k++){
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

void matrixSumSquential(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B,
                        std::vector<std::vector<int>>& C, int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
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

int main(){
    srand(time(nullptr));
    int n, numThreads;
    std::cout << "Matrix dimension:";
    std::cin >> n;
    std::cout << '\n';
    std::cout << "Number of threads:";
    std::cin >> numThreads;
    auto A = createMatrix(n, false);
    auto B = createMatrix(n, false);
    auto C = createMatrix(n, true);
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
    C = createMatrix(n, true);
    auto start1 = std::chrono::steady_clock::now();
    matrixMulSequential(A, B, C, n);
    auto end1 = std::chrono::steady_clock::now();
    auto diff1 = end1 - start1;
    std::cout << "Sequential time for matrix mul: " << std::chrono::duration <double, std::milli> (diff1).count()*0.001 << " s" << std::endl;
    //SUM

    C = createMatrix(n, true);
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
    C = createMatrix(n, true);
    auto start3 = std::chrono::steady_clock::now();
    matrixSumSquential(A, B, C, n);
    auto end3 = std::chrono::steady_clock::now();
    auto diff3 = end3 - start3;
    std::cout << "Sequential time for matrix sum: " << std::chrono::duration <double, std::milli> (diff3).count()*0.001 << " s" << std::endl;

    return 0;
}