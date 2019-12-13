#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

int maxNumObj, producers, consumers;
int numIt = 100;
int cnt = 0;
bool done = false;
std::mutex itLock;
std::mutex mtx;
std::condition_variable cv;
std::condition_variable cv1;
std::queue<int> band;


void producersFunction(){
    std::cout << "Worker thread started...\n";
    while(numIt > 0) {
        std::cout << "Worker thread at iteration " << numIt << '\n';
        itLock.lock();
        numIt -= 1;
        itLock.unlock();
        std::unique_lock<std::mutex> lk(mtx);
        cv.wait(lk, [] { return band.size() < maxNumObj - 4; });
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        itLock.lock();
        band.push(cnt);
        band.push(cnt + 1);
        band.push(cnt + 2);
        band.push(cnt + 3);
        cv1.notify_one();

        std::cout << "Pushed: " << cnt << ' ' << cnt + 1 << ' ' << cnt + 2 << ' ' << cnt + 3 << " at iteration: " << numIt + 1 << '\n';
        itLock.unlock();
        cnt += 4;
        lk.unlock();
    }

    done = true;
    cv1.notify_all();
}

void consumersFunction(){
    std::cout << "Consumer thread started...\n";
    while(!done){
        std::unique_lock<std::mutex> lk(mtx);
        cv1.wait(lk, [] {return band.size() >= 3;});
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
        auto a = band.front();
        band.pop();
        auto b = band.front();
        band.pop();
        auto c = band.front();
        band.pop();
        std::cout << "Consumer popped: " << a << ' ' << b << ' ' << c << '\n';
    }
}

int main() {
        std::vector<std::thread> threads;
        producers = 10;
        consumers = 10;
        maxNumObj = 10000;

        for(int i = 0; i < producers; i++){
            std::thread th(producersFunction);
            threads.push_back(std::move(th));
        }

        for(int i = 0; i < consumers; i++){
            std::thread th(consumersFunction);
            threads.push_back(std::move(th));
        }

        for(auto& x : threads){
            x.join();
        }

        return 0;
}
