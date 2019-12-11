cmake_minimum_required(VERSION 3.15)
project(HamiltonianCycleParallel)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

add_executable(HamiltonianCycleParallel main.cpp)