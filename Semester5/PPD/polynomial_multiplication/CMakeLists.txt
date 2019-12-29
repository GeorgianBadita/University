cmake_minimum_required(VERSION 3.15)
project(polynomial_multiplication)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

include_directories(.)

add_executable(polynomial_multiplication
        main.cpp
        Polynomial.cpp
        Polynomial.h
        Utils.cpp
        Utils.h
        PolyMul.cpp
        Polynomial.h
        NumberDiff.cpp
        NumberDiff.h)
