//
// Created by georg on 10/9/2019.
//

#include <iostream>
#include "BigNum.h"

std::vector<int> BigNum::stringToNum(std::string &numString) {
    std::vector<int> number;
    for(int i = numString.size() - 1; i >= 0; i--){
        number.push_back(numString[i] - '0');
    }

    return number;
}

std::ostream &operator<<(std::ostream &os, const BigNum &dt) {
    std::vector<int> number = dt.num;
    for(int i = number.size() - 1; i>=0; i--){
        os << number[i];
    }
    return os;
}

BigNum BigNum::operator+(const BigNum &other) {
    int T = 0;
    std::vector<int> result;
    std::vector<int> A = this->num;
    std::vector<int> B = other.num;
    int len1 = A.size();
    int len2 = B.size();
    int max = -1;
    if(len1 > len2){
        max = len1;
        for(int i = 0; i<len1 - len2; i++){
            B.push_back(0);
        }
    }else {
        max = len2;
        for (int i = 0; i < len2 - len1; i++) {
            A.push_back(0);
        }
    }

    for(int i = 0; i<max; i++){
        int val = A[i] + B[i] + T;
        if(val > 9){
            T = 1;
        }else{
            T = 0;
        }
        result.push_back(val % 10);
    }
    if(T) {
        result.push_back(T);
    }
    std::string strNum = "";
    BigNum final = BigNum(strNum);
    final.setNum(result);
    return final;
}

BigNum BigNum::operator*(const BigNum &other) {
    int resDim = this->getNum().size() + other.getNum().size() - 1;
    std::vector<int> result(resDim);

    auto A = this->getNum();
    auto B = other.getNum();

    for(int i = 0; i<A.size(); i++){
        for(int j = 0; j<B.size(); j++){
            result[i + j] += A[i] * B[j];
        }
    }
    int T = 0;
    for(int i = 0; i<result.size(); i++){
        T = (result[i] += T) / 10;
        result[i] %= 10;
    }

    if(T) {result.push_back(T);}

    std::string str = "";
    BigNum final = BigNum(str);
    final.setNum(result);
    return final;
}


