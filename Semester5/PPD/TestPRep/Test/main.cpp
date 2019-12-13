#include <iostream>
#include <thread>
#include <vector>
#include <condition_variable>
#include <queue>
#include <atomic>
#include "LinkedList.h"

LinkedList<int, bool> parkingList;


std::atomic<int> maxNumObj;
int producers, consumers;
int numItAdd = 300;
int numItDel = 250;
std::atomic_bool doneAdd;
std::atomic_bool doneDelete;
std::atomic<int> cnt;
std::mutex itLock;
std::mutex itLock1;
std::mutex mtx;
std::condition_variable cv;
std::condition_variable cv1;

std::queue<bool> band;


void producersFunction(int numIt){
    std::cout << "Producer thread started...\n";
    while(numIt > 0) {
        std::cout << "Producer thread at iteration " << numIt << '\n';
        itLock.lock();
        numIt -= 1;
        itLock.unlock();
        std::unique_lock<std::mutex> lk(mtx);
        cv.wait(lk, [] { return band.size() < maxNumObj;});
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        //itLock.lock();
        parkingList.pushBack(cnt, true);
        cnt ++;
        band.push(true);
        cv1.notify_all();
        std::cout << "Producer pushed: " << true << " at iteration: " << numIt + 1 << '\n';
        //itLock.unlock();
        lk.unlock();
    }

    doneAdd = true;
    cv1.notify_all();

}

void consumersFunction(int numIt){
    std::cout << "Consumer thread started...\n";
    while(numIt > 0) {
        std::cout << "Consumer thread at iteration " << numIt << '\n';
        itLock1.lock();
        numIt -= 1;
        itLock1.unlock();
        std::unique_lock<std::mutex> lk(mtx);
        cv1.wait(lk, [] { return band.size() > 0;});
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
        //itLock1.lock();
        parkingList.pushBack(cnt, false);
        cnt ++;
        auto val = band.front();
        band.pop();
        cv.notify_all();
        std::cout << "Consumer popped: " << val << " at iteration: " << numIt + 1 << '\n';
        //itLock1.unlock();
        lk.unlock();
    }
    doneDelete = true;
    cv.notify_all();
}

void printing_free_spots(){
    while(!doneAdd || !doneDelete) {
        std::this_thread::sleep_for(std::chrono::milliseconds(5));

        int spots = 0;
        auto head = parkingList.getHead();
        while (head != nullptr) {
            if (head->getValue()) {
                spots += 1;
            } else {
                spots -= 1;
            }
            head = head->getNext();
        }

        std::cout << "There are " << maxNumObj - spots << " free spots\n";

    }
}


int main() {
    std::vector<std::thread> threads;
    cnt = 0;
    producers = 2;
    consumers = 2;
    maxNumObj = 100;
    doneDelete = false;
    doneAdd = false;
    for(int i = 0; i < producers; i++){
        std::thread th(producersFunction, numItAdd);
        threads.push_back(std::move(th));
    }

    for(int i = 0; i < consumers; i++){
        std::thread th(consumersFunction, numItDel);
        threads.push_back(std::move(th));
    }
    std::thread printer(printing_free_spots);

    for(auto& x : threads){
        x.join();
    }

    doneDelete = true;
    doneAdd = true;
    printer.join();
    printing_free_spots();
    std::cout << band.size();
    return 0;
}
