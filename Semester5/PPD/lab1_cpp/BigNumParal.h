//
// Created by georg on 10/12/2019.
//

#ifndef LAB1_CPP_BIGNUMPARAL_H
#define LAB1_CPP_BIGNUMPARAL_H

#include <vector>
#include "BigNum.h"

void addBigNumsAuxBad(std::vector<int>* a, std::vector<int>* b, std::vector<int>* result, std::vector<int>* aux, int numThreads);
void addBigNumAuxGood(std::vector<int>* a, std::vector<int>* b, std::vector<int>* result, int numThreads);


BigNum addNumsParallelBad(BigNum a, BigNum b, int numThreads, double &execTime);


BigNum addNumsParallelGood(BigNum a, BigNum b, int numThreads, double &execTime);

#endif //LAB1_CPP_BIGNUMPARAL_H
