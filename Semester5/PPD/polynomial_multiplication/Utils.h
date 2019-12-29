//
// Created by georg  on 11/6/19.
//

#ifndef POLYNOMIAL_MULTIPLICATION_UTILS_H
#define POLYNOMIAL_MULTIPLICATION_UTILS_H


#include <vector>
#include <algorithm>
#include "Polynomial.h"
#include <time.h>

class Utils {
private:
    static bool isPowerOf2(int n){
        return (n & (n - 1)) == 0;
    }
public:

    /**
     * Function to generate a random polynomial
     * @param n - degree
     * @param min - minimum coefficient
     * @param max - maximum coefficient
     * @return - a polynomial of degree equal with 2^d, where 2^d is the closest power of 2 to n
     */
    static Polynomial getRandomPoly(int n, int min, int max){
        srand(time(nullptr));
        while(!isPowerOf2(n)){
            n ++;
        }
        std::vector<int> coeffs;
        for(int i = 0; i<n; i++){
            int currCoeff = rand()%(max - min) + min;
            coeffs.push_back(currCoeff);
        }

        return Polynomial(coeffs);
    }
};


#endif //POLYNOMIAL_MULTIPLICATION_UTILS_H
