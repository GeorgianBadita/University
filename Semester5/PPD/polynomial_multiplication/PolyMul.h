//
// Created by georg on 11/14/2019.
//

#ifndef POLYNOMIAL_MULTIPLICATION_POLYMUL_H
#define POLYNOMIAL_MULTIPLICATION_POLYMUL_H


#include <vector>
#include "Polynomial.h"

/**
 * Function for multiplying two polynomials in parallel
 * @param a - first polynomial
 * @param b - second polynomial
 * @param result - result polynomial
 * @param threadNum  - number of threads
 */
void multiplyPolyParallelNaive(std::vector<int> *a, std::vector<int> *b, std::vector<int> *result, int threadNum);

/**
 * Function to multiply two polynomials using karatsuba's algorithm
 * @param A - first polynomial
 * @param B - second polynomial
 * @return - polynomial
 */
std::vector<int> karatsubaSequential(std::vector<int> A, std::vector<int> B);


/**
 * Function to multiply two polynomials in parallel using a naive approach
 * @param A - first Polynomial
 * @param B - second Polynomial
 * @param numThreads - number of threads
 * @param execTime - execution time
 * @return - product of A and B
 */
Polynomial naiveParallelMul(Polynomial A, Polynomial B, int numThreads, double &execTime);

/**
 * Function which multiplies two polynomials using karatsuba's algorithm sequentially
 * @param A - first polynomial
 * @param B - second polynomial
 * @param execTime - execution time
 * @return - product of A and B
 */
Polynomial karatsubaSequentialMul(Polynomial A, Polynomial B, double &execTime);


/**
 * Function to multiply two polynomials using karatsuba's algorithm
 * @param A - first polynomial
 * @param B - second polynomial
 * @param numThreads - number of threads
 * @param execTime - execution time
 * @return product of A and B
 */
Polynomial karatsubaParallelMul(Polynomial A, Polynomial B, int numThreads, double &execTime);

#endif //POLYNOMIAL_MULTIPLICATION_POLYMUL_H
