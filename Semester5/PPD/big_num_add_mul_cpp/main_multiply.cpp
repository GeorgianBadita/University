//
// Created by georg on 10/26/2019.
//
#include <iostream>
#include <vector>
#include <chrono>
#include "BigNum.h"
#include "BigNumParal.h"
#include "Helper.h"

int main(){
    auto help = Helper();
    std::string pathToA = R"(C:\Users\georg\Desktop\University\Semester5\PPD\big_num_add_mul_cpp\num_file_a.txt)";
    std::string pathToB = R"(C:\Users\georg\Desktop\University\Semester5\PPD\big_num_add_mul_cpp\num_file_b.txt)";
    std::vector<int> A = help.readBigFromFile(pathToA);
    std::vector<int> B = help.readBigFromFile(pathToB);

    auto num = BigNum(A);
    auto num1 = BigNum(B);
    double execTime = 0.0;
    auto start = std::chrono::steady_clock::now();
    auto rez = num * num1;
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    auto time = std::chrono::duration <double, std::milli> (diff).count();
    time = time*0.001;

    std::cout << "Sequential multiplication " << time << '\n';

    mulNumsParallel(num, num1, 100, execTime);
    std::cout << "Parallel multiplication: " << execTime << '\n';

    return 0;

}
