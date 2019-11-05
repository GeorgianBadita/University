//
// Created by georg on 10/26/2019.
//

#ifndef MATRIX_MUL_UTILS_H
#define MATRIX_MUL_UTILS_H


#include <vector>
#include <ctime>
#include <time.h>
#include <random>
#include <iostream>

class Utils {
public:
    static std::vector<std::vector<int>> createMatrix(int n, bool empty, int max_num){
        std::vector<std::vector<int>> matrix;
        for(int i = 0; i<n; i++){
            std::vector<int> line(n);
            for(int j = 0; j<n; j++){
                if(!empty) {
                    line[j] = rand() % max_num;
                }else{
                    line[j] = 0;
                }
            }
            matrix.push_back(line);
        }

        return matrix;
    }

    static void printMatrix(const std::vector<std::vector<int>>& matrix){
        for(const auto& line : matrix){
            for(const auto& elem : line){
                std::cout << elem << ' ';
            }
            std::cout << '\n';
        }
    }

    static void matrixMulSequential(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B,
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

    static void matrixSumSquential(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B,
                                   std::vector<std::vector<int>>& C, int n){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                C[i][j] = A[i][j] + B[i][j];
            }
        }
    }

    static bool compareMatrices(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B){
        for(int i = 0; i<A.size(); i++){
            for(int j = 0; j<A[0].size(); j++){
                if(A[i][j] != B[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};


#endif //MATRIX_MUL_UTILS_H
