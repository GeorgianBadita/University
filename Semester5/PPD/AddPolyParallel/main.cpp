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
 * @param source - source Polynomial
 * @param destination - destination Polynomial
 * @param type - if type is True, the list lock is used else the node lock is used
 * @result: destination = source + destination
 */
void threadFunction(Polynomial* source, Polynomial* destination, bool type){
    auto* tmp = (*source).getHead();
    while(tmp != nullptr){
        if(type) {
            (*destination).addMonomialListLock(tmp->getCoefficient(), tmp->getDegree());
        }else{
            (*destination).addMonomialNodeLock(tmp->getCoefficient(), tmp->getDegree());
        }
        tmp = tmp->next;
    }
}

/**
 * Function to add all polynomials using listLock
 * @param numPolys - number of polynomials
 * @param pathToPoly - path to the file where the polynomials are stored
 * @param execTime - execution time
 */
Polynomial addWithListLock(int numPolys, std::vector<Polynomial*> polys, const std::string& pathToPoly, double& execTime){
    //result polynomial
    auto result = Polynomial();
    //threads vector
    std::vector<std::thread> threads(numPolys);


    //thread work
    auto start = std::chrono::steady_clock::now(); //start time
    for(int i = 0; i<numPolys; i++){

        std::thread th(threadFunction, polys[i], &result, true);
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
    execTime = time;



    return result;

}

/**
 * Function to add all polynomials using listLock
 * @param numPolys - number of polynomials
 * @param pathToPoly - path to the file where the polynomials are stored
 * @param execTime - execution time
 */
Polynomial addWithNodeLock(int numPolys, std::vector<Polynomial*> polys, const std::string& pathToPoly, double& execTime){
    //result polynomial
    auto result = Polynomial();
    //threads vector
    std::vector<std::thread> threads(numPolys);


    //thread work
    auto start = std::chrono::steady_clock::now(); //start time
    for(int i = 0; i<numPolys; i++){
        std::thread th(threadFunction, polys[i], &result, false);
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
    execTime = time;

    return result;

}



int main() {
    //reset the seed
    srand(time(nullptr));

    //path to polynomials file
    std::string pathToPoly = R"(C:\Users\georg\Desktop\University\Semester5\PPD\AddPolyParallel\polynomials.txt)";
    //number of polynomials
    int numPolys = 5;
    int maxDegree = 100;

    //generate polynomials
    generatePolynomials(pathToPoly, numPolys, maxDegree);

    //polynomials vector
    std::vector<Polynomial*> polys(numPolys);

    //read polynomials from file (one on each line)
    for(int i = 0; i<numPolys; i++){
        auto* currPoly =  readPoly(pathToPoly, i + 1);
        //std::cout << *currPoly << '\n';
        polys[i] = currPoly;
    }


    double execTime = 0.0;
    auto res = addWithNodeLock(numPolys, polys, pathToPoly, execTime);
    std::cout << "Execution time with node lock: " << execTime << '\n';
    //std::cout << res << '\n';
    res = addWithListLock(numPolys, polys, pathToPoly, execTime);
    std::cout << "Execution time with list lock: " << execTime << '\n';
    //std::cout << res << '\n';
    return 0;
}


