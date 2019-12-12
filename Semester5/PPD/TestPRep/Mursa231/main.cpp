#include <iostream>
#include <algorithm>
#include "Friendships/Friendships.h"
#include <thread>
#include <atomic>
#include <condition_variable>


std::vector<std::pair<std::string, std::string>> adds;
std::atomic_int processed_messages;
bool third_turn;
bool first_second_turn;
std::mutex mtx;
std::condition_variable cv;
std::condition_variable cv1;
int k = 2;
bool finished = false;


std::string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

void generate_adds(int n){
    for(int i = 0; i<n; i++){
        adds.emplace_back(random_string(5), random_string(5));
    }

}

void worker_thread_function(int id, Friendships* fr, int start, int stop){
    std::cout << "Thread " << id << " started.. \n";
    std::unique_lock<std::mutex> lock(mtx);
    cv1.wait(lock, []{return first_second_turn;});
    while(start < stop){
        processed_messages ++;
        std::cout << "Add " << adds[start].first << " and " << adds[start].second << " by thread: " << id << '\n';
        fr->addNodeListLock(adds[start].first, adds[start].second);
        if(processed_messages == k){
            processed_messages = 0;
            third_turn = true;
            std::cout << "Thread 3 starts, notified by thread: " << id << '\n';
            cv.notify_all();
            std::cout << "Threads 1 and 2, waiting... \n";
            first_second_turn = false;
            cv1.notify_all();
        }
        start ++;
    }
    if(id == 2){
        finished = true;
        cv.notify_one();
    }
}

void printer_thread_function(int id, Friendships* fr){
    while(!finished) {
        std::cout << "Thread 3 started and waiting...\n";
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return third_turn; });
        std::cout << "Thread 3 starts working...\n";
        third_turn = false;
        first_second_turn = true;
        std::cout << "Thread 3 notifies threads 1 and 2\n";
        fr->printFriendships();
        cv1.notify_all();

    }
}

int main() {

    auto fr = Friendships();
    int n = 6;
    generate_adds(n);
    int per_thread = n / 2;
    int first_thread_work = per_thread;
    int second_thread_work = per_thread;
    if(n % 2 == 1){
        first_thread_work ++;
    }
    first_second_turn = true;
    int id = 1;
    std::thread th1(worker_thread_function, id, &fr, 0, first_thread_work);
    std::thread th2(worker_thread_function, id + 1, &fr, first_thread_work, first_thread_work +  second_thread_work);
    std::thread th3(printer_thread_function, id + 2, &fr);
    th1.join();
    th2.join();
    th3.join();
    return 0;
}
