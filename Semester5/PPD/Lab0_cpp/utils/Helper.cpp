//
// Created by georg on 10/1/2019.
//

#include "Helper.h"
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <sstream>

void Helper::createRandomFile(std::string &path, int size, int min, int max) {
    std::ofstream outfile(path);
    std::vector<int> numbers;
    srand(time(nullptr));
    std::generate_n(std::back_inserter(numbers), size, [&](){
        return min + rand() % (max - min + 1);
    });
    std::for_each(numbers.begin(), numbers.end(), [&](int n){
        outfile << n << ' ';
    });

    outfile.close();
}

bool Helper::compareFiles(std::string &path1, std::string &path2, std::string& dtype) {
    std::ifstream infile1(path1);
    std::ifstream infile2(path2);

    if(dtype == "real"){
        double x1, x2;
        double eps=1e-8;
        while(infile1 >> x1 && infile2 >> x2){
            if(std::abs(x2 - x1) > eps){
                return false;
            }
        }
        return !(!infile1.eof() or !infile2.eof());
    }else{
        int x1, x2;
        while(infile1 >> x1 && infile2 >> x2){
            if(x1 != x2){
                return false;
            }
        }
        return !(!infile1.eof() or !infile2.eof());
    }
    return false;
}

void Helper::addLineToExcel(std::string &path, std::string &line) {
    std::ofstream outfile(path, std::fstream::app);
    outfile << "\n" << line;
    outfile.close();
}
