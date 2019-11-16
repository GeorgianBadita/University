//
// Created by georg on 10/9/2019.
//

#include <iostream>
#include "Polynomial.h"


std::ostream &operator<<(std::ostream &os, const Polynomial &dt) {
    std::vector<int> number = dt.poly;
    for(int i = number.size() - 1; i>=0; --i){
        if(i == number.size() - 2 && number[i + 1] == 0){
            if(number[i] > 0){
                os << number[i] << "x^" << std::to_string(i);
            }else{
                os << std::abs(number[i]) << "x^" << std::to_string(i);
            }
        }
        if(number[i] != 0 && i != 0) {
            if(i == number.size() - 1) {
                if(number[i] > 0) {
                    os << number[i] << "x^" << std::to_string(i);
                }else{
                    os << "-" << std::abs(number[i]) << "x^" << std::to_string(i);
                }
            }else{
                if(number[i] > 0){
                    os << " + " << number[i] << "x^" << std::to_string(i);
                }else{
                    os << " - " << std::abs(number[i]) << "x^" << std::to_string(i);
                }
            }
        }else if(i == 0 && number[i] != 0){
            if(number[i] > 0){
                os << " + " << number[i];
            }else{
                os << " - " << std::abs(number[i]);
            }
        }
    }
    return os;
}


Polynomial Polynomial::operator*(const Polynomial &other) {
    auto A = this->poly;
    auto B = other.poly;
    auto degree = A.size() + B.size() - 1;
    auto result = std::vector<int>(degree, 0);
    for(int i = 0; i<A.size(); ++i){
        for(int j = 0; j<B.size(); j++){
            result[i + j] += A[i]*B[j];
        }
    }

    return Polynomial(result);
}


