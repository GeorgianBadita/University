cmake_minimum_required(VERSION 3.15)
project(lab1_cpp)

set(CMAKE_CXX_STANDARD 14)



add_executable(lab1_cpp main.cpp BigNum.cpp BigNum.h test_threads.cpp BigNumParal.cpp BigNumParal.h Helper.cpp Helper.h)