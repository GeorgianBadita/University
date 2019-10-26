//
// Created by georg on 10/12/2019.
//

#include <iostream>
#include <thread>
#include <pthread.h>
#include <utility>
#include <vector>

void foo(std::vector<int>* result, int pl, std::vector<int>* num){
    (*result)[0] = -1;
    std::cout << pl << '\n';
}

int maasqdin(){
    std::vector<int> v{1,2,3,4};
    int n = 5;
    std::thread th(foo, &v, 1999, &v);
    th.join();
    for(const auto& elem : v){
        std::cout << elem << '\n';
    }
    return 0;
}