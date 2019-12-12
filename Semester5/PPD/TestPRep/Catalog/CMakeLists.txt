cmake_minimum_required(VERSION 3.15)
project(Catalog)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

add_executable(Catalog main.cpp Node.cpp Node.h LinkedList.cpp LinkedList.h Student.cpp Student.h)