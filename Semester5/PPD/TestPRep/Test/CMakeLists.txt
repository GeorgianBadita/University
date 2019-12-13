cmake_minimum_required(VERSION 3.15)
project(Test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

add_executable(Test main.cpp LinkedList.cpp LinkedList.h Node.cpp Node.h ThreadSafeQueue.h)