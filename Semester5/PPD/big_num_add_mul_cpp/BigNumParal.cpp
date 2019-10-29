//
// Created by georg on 10/12/2019.
//
#include "BigNumParal.h"
#include "BigNum.h"
#include <thread>
#include <iostream>


void thrStep1(std::vector<int>* a, std::vector<int>* b, std::vector<int>* result,int start, int step){
    int sum;
    while(start < (*a).size()){
        sum = (*a)[start] + (*b)[start];
        if(sum > 9){
            (*result)[start] = 2;
        }
        else if(sum == 9){
            (*result)[start]  = 1;
        }else{
            (*result)[start] = 0;
        }
        start += step;
    }

}

void thrStep2(std::vector<int>* result, int start, int step){
    while(start < (*result).size()){
        if(start != 0){
            if((*result)[start] == 1){
                (*result)[start] = (*result)[start - 1];
            }
        }

        start += step;
    }
}

void thrStep3(std::vector<int>* result, std::vector<int>* aux, int start, int step){
    while(start < (*result).size() - 1){
        if((*result)[start] == 2){
            (*aux)[start + 1] = 1;
            int startCopy = start + 1;

            while(startCopy < (*result).size() - 1 && (*result)[startCopy] == 1){
                (*result)[startCopy] = -5;
                (*aux)[startCopy + 1] = 1;
                startCopy += 1;
            }
        }else if((*result)[start] != -5){
            (*aux)[start + 1] = 0;
        }
        (*aux)[0] = 0;

        start += step;
    }
}

void thrStep4(std::vector<int>* a, std::vector<int>* b, std::vector<int>* result, std::vector<int>* aux, int start, int step, bool *extra){
    while(start < (*a).size()){
        int sum = (*a)[start] + (*b)[start] + (*aux)[start];
        if(start == (*a).size() - 1 && sum > 9){
            *extra = true;
        }
        if(sum > 9){
            sum %= 10;
        }
        (*result)[start] = sum;
        start += step;
    }
}

void addBigNumsAuxBad(std::vector<int>* a, std::vector<int>* b, std::vector<int>* result, std::vector<int>* aux, int numThreads){
    std::vector<std::thread> threads;
    //2 - C,
    //1 - M,
    //0 - N
    for(int i = 0; i<numThreads; i++){
        std::thread th(thrStep1, a, b, result, i, numThreads);
        threads.push_back(std::move(th));
    }
    for(auto& x : threads){
        x.join();
    }
    threads.clear();
    /*
    std::cout << '\n';
    for(const auto& elem : *result){
        elem == 2 ? std::cout << "C " : elem == 1 ? std::cout << "M " : std::cout << "N ";
    }
    std::cout << '\n';*/
    for(int i = 0; i<numThreads; i++){
        std::thread th(thrStep2, result, i, numThreads);
        threads.push_back(std::move(th));
    }
    /*
    for(const auto& elem : *result){
        elem == 2 ? std::cout << "C " : elem == 1 ? std::cout << "M " : std::cout << "N ";
    }
    std::cout << '\n';*/
    for(auto& x : threads){
        x.join();
    }
    threads.clear();

    for(int i = 0; i<numThreads; i++){
        std::thread th(thrStep3, result, aux, i, numThreads);
        threads.push_back(std::move(th));
    }

    for(auto& x : threads){
        x.join();
    }
    threads.clear();
    /*
    for(const auto& elem : *aux){
        std::cout << elem << ' ';
    }
    std::cout << '\n';
    */
    bool extra = false;
    for(int i = 0; i<numThreads; i++){
        std::thread th(thrStep4, a, b, result, aux, i, numThreads, &extra);
        threads.push_back(std::move(th));
    }
    for(auto& x : threads){
        x.join();
    }
    threads.clear();
    if(extra){
        (*result).push_back(1);
    }
    /*
    for(const auto& elem : *result){
        std::cout << elem << ' ';
    }
    std::cout << '\n';*/
}

BigNum addNumsParallelBad(BigNum a, BigNum b, int numThreads, double& execTime) {
    std::vector<int> A = a.getNum();
    std::vector<int> B = b.getNum();
    int len1 = A.size();
    int len2 = B.size();
    if(len1 > len2){
        for(int i = 0; i<len1 - len2; i++){
            B.push_back(0);
        }
    }else {
        for (int i = 0; i < len2 - len1; i++) {
            A.push_back(0);
        }
    }
    std::vector<int> result(A.size());
    std::vector<int> aux(A.size());
    auto start = std::chrono::steady_clock::now();
    addBigNumsAuxBad(&A, &B, &result, &aux, numThreads);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    auto time = std::chrono::duration <double, std::milli> (diff).count();
    execTime = time*0.001;
    std::string strNum;
    BigNum final = BigNum(strNum);
    final.setNum(result);
    return final;
}

/*** GOOD THREAD SUM ***/


void threadFunction(std::vector<int>* a, std::vector<int>* b, std::vector<int>* result, int start, int stop, bool* isExtra){
    while(start < stop){
        if(((*a)[start] + (*b)[start]) > 9){
            if(start + 1 < (*result).size()){
                (*result)[start + 1] = ((*a)[start + 1] + (*b)[start + 1] + 1) % 10;
            }else if(start + 1 == (*result).size()) {
                *isExtra = true;
                return;
            }
            start += 1;
            while(((*a)[start] + (*b)[start]) == 9){
                if(start + 1 < (*result).size()){
                    (*result)[start + 1] = ((*a)[start + 1] + (*b)[start + 1] +  1) % 10;
                }
                else if(start + 1 == (*result).size()){
                    *isExtra = true;
                    return;
                }

                start += 1;
            }
        }
        else{
            if(start + 1 < (*result).size() && (*result)[start + 1] == -1){
                (*result)[start + 1] = ((*a)[start + 1] + (*b)[start + 1]) % 10;
            }
            start += 1;
        }
    }
}

void addBigNumAuxGood(std::vector<int>* a, std::vector<int>* b, std::vector<int> *result, int numThreads) {
    std::vector<std::thread> threads;
    bool extra = false;

    int perThread = (int)result->size() / numThreads;
    int diff = (int)result->size() % numThreads;
    int start = 0;
    int stop = 0;
    for(int i = 0; i<numThreads; i++){
        stop = start + perThread;
        if(diff > 0){
            stop ++;
            diff --;
        }

        std::thread th(threadFunction, a, b, result, start, stop, &extra);
        threads.push_back(std::move(th));
        start = stop;
    }

    for(auto& x : threads){
        x.join();
    }

    (*result)[0] = ((*a)[0] + (*b)[0]) % 10;
    if(extra){
        (*result).push_back(1);
    }
}

BigNum addNumsParallelGood(BigNum a, BigNum b, int numThreads, double &execTime) {
    std::vector<int> A = a.getNum();
    std::vector<int> B = b.getNum();
    int len1 = A.size();
    int len2 = B.size();
    if(len1 > len2){
        for(int i = 0; i<len1 - len2; i++){
            B.push_back(0);
        }
    }else {
        for (int i = 0; i < len2 - len1; i++) {
            A.push_back(0);
        }
    }
    std::vector<int> result(A.size(), -1);
    auto start = std::chrono::steady_clock::now();
    addBigNumAuxGood(&A, &B, &result, numThreads);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    auto time = std::chrono::duration <double, std::milli> (diff).count();
    execTime = time*0.001;
    std::string strNum;
    BigNum final = BigNum(strNum);
    final.setNum(result);
    return final;
}


void thread_mul_func(std::vector<int>* a, std::vector<int>* b, std::vector<int>* result, int start, int stop){
    for(int i = start; i<stop; i++){
        int carry = 0;
        for(int j = 0; j<a->size(); j++){
            int prod = (*a)[j] * (*b)[i] + carry;
            carry = prod / 10;
            prod = prod % 10;

            (*result)[i + j] += prod;
        }
        if(carry){
            (*result)[i + b->size()] = carry;
        }
    }
    int carry = 0;
    for(int & i : *result){
        i += carry;
        carry = i / 10;
        i %= 10;
    }
}


void addBigNumsSequential(std::vector<int> A, std::vector<int> B, std::vector<int>& result){
    int c = 0, sum = 0;
    for(int i=0;i<A.size();i++){
        sum = A[i] + B[i] + c;
        result[i] = sum%10;
        c = sum/10;
    }
    if(c){
        result.push_back(1);
    }
}

void multiplyBigNumParallel(std::vector<int> *a, std::vector<int> *b, std::vector<int> *result, int threadNum) {
    int perThread = b->size() / threadNum;
    int rem = b->size()  % threadNum;

    int start = 0, stop = 0;
    std::vector<std::thread> threads(threadNum);
    std::vector<int> threadResults[threadNum];
    for(int i = 0; i<threadNum; i++){
        threadResults[i] = std::vector<int>(a->size()*2, 0);
    }

    for(int th_index = 0; th_index < threadNum; th_index ++){
        stop = start + perThread;
        if(rem){
            stop += 1;
            rem -= 1;
        }

        threads[th_index] = std::thread(thread_mul_func, a, b, &threadResults[th_index], start, stop);
        start = stop;
    }

    for(int th_index = 0; th_index < threadNum; th_index ++){
        threads[th_index].join();
    }

    for(int th_index = 0; th_index < threadNum; th_index ++){
        addBigNumsSequential(*result, threadResults[th_index], *result);
    }
}

BigNum mulNumsParallel(BigNum a, BigNum b, int numThreads, double &execTime) {
    auto A = a.getNum();
    auto B = b.getNum();
    std::vector<int> rez(2*A.size(), 0);
    auto start = std::chrono::steady_clock::now();
    multiplyBigNumParallel(&A, &B, &rez, numThreads);
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration <double, std::milli> (end - start).count();
    execTime = time * 0.001;
    return BigNum(rez);
}
