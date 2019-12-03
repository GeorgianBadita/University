#include <iostream>
#include "Polynomial/Polynomial.h"
#include <fstream>
#include <vector>
#include <thread>
#include "ThreadSafeQueue.h"

/**
 * Function to generate random polynomials
 * @param path - path where to save the polynomials
 * @param numPolys - number of polynomials
 * @param maxDegree - maximum degree
 */
void generatePolynomials(const std::string& path, const int& numPolys, const int& maxDegree){
    std::ofstream out(path);
    //range[-20, 20]
    for(int i = 0; i<numPolys; ++i){
        for(int j = 0; j<maxDegree; ++j){
            int degree = j;
            int coeff = rand() % 21;
            if(rand() % 2 == 1){
                coeff *= -1;
            }
            out << coeff << "," << degree;
            if(j < maxDegree - 1){
                out << ' ';
            }
            else{
                out << '\n';
            }
        }
    }
}

/**
 * Function to read a polynomial from file
 * @param path - path to polynomial file
 * @param index - index of polynomial
 * @return - polynomial at index index
 */
Polynomial* readPoly(const std::string& path, const int& index){
    int lineCnt = 0;
    std::ifstream in(path);
    std::string line;
    while (lineCnt != index && getline(in, line)) {
        lineCnt ++;
    }
    bool negative = false;
    int firstCommaPoz = 0;
    if(line[firstCommaPoz] == '-'){
        firstCommaPoz ++;
        negative = true;
    }
    int coeff = 0;
    int degree = 0;
    while(line[firstCommaPoz] != ','){
        coeff = coeff * 10 + (line[firstCommaPoz] - '0');
        firstCommaPoz ++;
    }
    firstCommaPoz += 1;
    while(line[firstCommaPoz] != ' '){
        degree = degree * 10 + (line[firstCommaPoz] - '0');
        firstCommaPoz ++;
    }
    firstCommaPoz ++;
    auto* pol = new Polynomial();
    if(negative){
        coeff *= -1;
        negative = !negative;
    }
    pol->addMonomialListLock(coeff, degree);
    while(firstCommaPoz < line.size()){
        int currPoz = firstCommaPoz;
        coeff = 0;
        degree = 0;
        if(line[currPoz] == '-'){
            currPoz ++;
            negative = true;
        }
        while(line[currPoz] != ',' && currPoz < line.size()){
            coeff = coeff* 10 + (line[currPoz] - '0');
            currPoz ++;
        }
        currPoz ++;
        while(line[currPoz] != ' ' && line[currPoz] != '\n' && currPoz < line.size()){
            degree = degree * 10 + (line[currPoz] - '0');
            currPoz ++;
        }
        currPoz ++;
        firstCommaPoz = currPoz;
        if(negative){
            coeff *= -1;
            negative = !negative;
        }
        pol->addMonomialListLock(coeff, degree);
    }
    return pol;
}

/**
 * Function to add a Polynomial to another using threads
 */
void readerWork(ThreadSafeQueue* queue, int numPolys, int degree, const std::string& path){
   // std::cout << "Started reading polynomials" << '\n';
    for(int i = 0; i<numPolys; i++){
        auto* currPoly = readPoly(path, i + 1);
        auto head = currPoly->getHead();
        while(head != nullptr){
            queue->push(*head);
            head = head->next;
        }
    }

    auto endMonomial = new Monomial(0, -1);
    queue->push(*endMonomial);
}


void worker(ThreadSafeQueue* queue, Polynomial* result){
    //std::cout << "Started wokring" << '\n';
    auto monomial =  Monomial(0, 0);
    do{
        queue->wait_and_pop(monomial);
        result->addMonomialListLock(monomial.getCoefficient(), monomial.getDegree());
        //std::cout << monomial->getDegree();
    }while(monomial.getDegree() != -1);

}

double addWithQueue(ThreadSafeQueue* queue, int numPolys, int maxDegree, int numThreads, const std::string& path){
    auto start = std::chrono::steady_clock::now();
    auto result = Polynomial();
    std::vector<std::thread> threads(numThreads);
    std::thread reader;
    reader = std::thread(readerWork, queue, numPolys, maxDegree, path);
    for(int i = 0; i < numThreads; i++){
        std::thread th = std::thread(worker, queue, &result);
        threads[i] = std::move(th);
    }
    reader.join();
    for(int i = 0; i < numThreads; i++){
        threads[i].join();
    }

    auto stop = std::chrono::steady_clock::now();
    auto diff = stop - start;
    auto time = std::chrono::duration<double , std::milli>(diff).count();
    time *= 0.001;
    std::cout << result << '\n';
    return time;
}


int main() {
    //reset the seed
    srand(time(nullptr));

    //path to polynomials file
    std::string pathToPoly = R"(C:\Users\georg\Desktop\University\Semester5\PPD\AddPolyParallelQueue\polynomials.txt)";
    //number of polynomials
    int numPolys = 2;
    int maxDegree = 2;
    int numThreads = 2;

    generatePolynomials(pathToPoly, numPolys, maxDegree);

    auto* queue = new  ThreadSafeQueue(false);
    auto execTime = addWithQueue(queue, numPolys, maxDegree, numThreads, pathToPoly);
    std::cout << "Took: " << execTime << '\n';
    return 0;
}


