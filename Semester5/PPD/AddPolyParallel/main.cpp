#include <iostream>
#include "Polynomial/Polynomial.h"
#include <fstream>
#include <vector>
#include <thread>
std::mutex mtx;


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
    pol->addMonomial(coeff, degree);
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
        pol->addMonomial(coeff, degree);
    }
    return pol;
}

/**
 *
 * @param source
 * @param destination
 */
void threadFunction(Polynomial* source, Polynomial* destination){
    auto* tmp = (*source).getHead();
    while(tmp != nullptr){
        mtx.lock();
        (*destination).addMonomial(tmp->getCoefficient(), tmp->getDegree());
        mtx.unlock();
        tmp = tmp->next;
    }
}

int main() {
    //reset the seed
    srand(time(nullptr));

    //path to polynomials file
    std::string pathToPoly = R"(C:\Users\georg\Desktop\University\Semester5\PPD\AddPolyParallel\polynomials.txt)";
    //number of polynomials
    int numPolys = 20;
    int maxDegree = 15;

    //generate polynomials
    generatePolynomials(pathToPoly, numPolys, maxDegree);

    //result polynomial
    auto result = Polynomial();
    //threads vector
    std::vector<std::thread> threads(numPolys);
    //polynomials vector
    std::vector<Polynomial*> polys(numPolys);

    //read polynomials from file (one on each line)
    for(int i = 0; i<numPolys; i++){
        auto* currPoly =  readPoly(pathToPoly, i + 1);
        std::cout << *currPoly << '\n';
        polys[i] = currPoly;
    }

    //thread work
    auto start = std::chrono::steady_clock::now(); //start time
    for(int i = 0; i<numPolys; i++){

        std::thread th(threadFunction, polys[i], &result);
        threads[i] = std::move(th);
    }

    //join threads
    for(auto& t : threads){
        t.join();
    }
    auto stop = std::chrono::steady_clock::now();
    auto diff = stop - start;
    auto time = std::chrono::duration <double, std::milli> (diff).count();
    time = time*0.001;
    std::cout << "Time for adding polynomials: " << time << '\n';

    //delete polynomials
    for(auto& pol : polys){
        delete pol;
    }

    //result
    std::cout << result << '\n';

}


