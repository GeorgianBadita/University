#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <queue>
#include "Utils.h"

std::mutex mtx;
std::condition_variable cv;
std::vector<std::vector<int>> A;
std::vector<std::vector<int>> B;
std::vector<std::vector<int>> C;
std::vector<std::vector<int>> E;
std::vector<std::vector<int>> D;
std::queue<std::vector<int>> queue;
std::vector<bool> fullLinesProd;
std::vector<bool> fullLinesCons;
int numLines;
int numConsumers;
int numProducers;
int MAX_NUM = 10;

/* Consumer */
void consume(){
    std::unique_lock<std::mutex> lck(mtx);
    while(queue.empty()) cv.wait(lck);
    auto front = queue.front();
    auto lineInd = front[0];
    auto line = E[lineInd];
    for(int i = 0; i < numLines; i++){
        int sum = 0;
        for(int j = 0; j < numLines; j++){
            sum += line[j] * C[j][i];
        }
        D[lineInd][i] = sum;
        //Utils::printMatrix(D);
        //std::cout << "\n";
    }
    bool toEnd = true;
    fullLinesCons[lineInd] = true;
    for(const auto& x : fullLinesCons){
        if(x == false){
            toEnd = false;
            break;
        }
    }
    if(toEnd){
        return;
    }

    queue.pop();
}

/* Producer */
void produce(int i, int n, std::vector<std::vector<int>>* A, std::vector<std::vector<int>>* B, int step){

    int tNum = i;

    int line = tNum / n;
    int col = tNum % n;

    while(line < n){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += (*A)[line][j] * (*B)[j][col];
        }
        E[line][col] = sum;
        for(int i = 0; i<E.size(); i++){
            bool lineIsFull = true;
            for(int j = 0; j<E[0].size(); j++){
                if(E[i][j] == 0){
                    lineIsFull = false;
                    break;
                }
            }
            if(lineIsFull && fullLinesProd[i] == false){
                fullLinesProd[i] = true;
                std::unique_lock<std::mutex> lck(mtx);
                queue.push({i});
                cv.notify_one();
            }
        }
        tNum += step;
        line = tNum / n;
        col = tNum % n;
    }

}

int main(){

    std::cout << "Give the number of lines:\n";
    std::cin >> numLines;
    std::cout << "Give the number of producers:\n";
    std::cin >> numProducers;
    std::cout << "Give the number of consumers:\n";
    std::cin >> numConsumers;

    std::thread producers[numProducers];
    std::thread consumers[numConsumers];
    A = Utils::createMatrix(numLines, false, MAX_NUM);
    B = Utils::createMatrix(numLines, false, MAX_NUM);
    C = Utils::createMatrix(numLines, false, MAX_NUM);

    E = Utils::createMatrix(numLines, true, MAX_NUM);
    D = Utils::createMatrix(numLines, true, MAX_NUM);

    Utils::printMatrix(A);
    std::cout << "\n";
    Utils::printMatrix(B);
    std::cout << "\n";
    Utils::printMatrix(C);
    std::cout << "\n";


    for(int i = 0; i<numLines; i++){
        fullLinesProd.push_back(false);
        fullLinesCons.push_back(false);
    }
    for (int order = 0; order < numProducers; order++) {
        producers[order] = std::thread(produce, order, numLines, &A, &B, numProducers);
    }
    for(int order = 0; order <numConsumers; order ++){
        consumers[order] = std::thread(consume);
    }

    /* Join the threads to the main threads */
    for (int order = 0; order < numProducers; order++) {
        producers[order].join();
    }

    for(int order = 0; order < numConsumers; order ++){
        consumers[order].join();
    }

    Utils::printMatrix(D);
    std::cout << '\n';

    return 0;
}

