#include <iostream>
#include <vector>
#include <chrono>
#include "Polynomial.h"
#include "PolyMul.h"
#include "Utils.h"

int main() {

    double extime;
    Polynomial poly = Utils::getRandomPoly(65536, 1, 10);
    Polynomial poly1 = Utils::getRandomPoly(65536, 1, 10);
//    std::cout << poly << '\n';
//    std::cout << poly1 << '\n';
    auto startTime = std::chrono::steady_clock::now();
    auto rez = poly * poly1;
    auto stopTime = std::chrono::steady_clock::now();
    auto diff = stopTime - startTime;
    auto time = std::chrono::duration<double, std::milli>(diff).count();
    time = time * 0.001;
    std::cout << "Time for sequential O(n^2) algorithm: " << time << '\n';
    rez = naiveParallelMul(poly, poly1, 8, extime);
    std::cout << "Time for parallel O(n^2) algorithm: " << extime << '\n';
    rez = karatsubaSequentialMul(poly, poly1, extime);
    std::cout << "Time for karatsuba's sequential algorithm: " << extime << '\n';
    rez = karatsubaParallelMul(poly, poly1, 8, extime);
    std::cout << "Time for karatsuba's parallel algorithm: " << extime << '\n';

    return 0;
}