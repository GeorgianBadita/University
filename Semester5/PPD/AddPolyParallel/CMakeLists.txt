cmake_minimum_required(VERSION 3.15)
project(AddPolyParallel)

set(CMAKE_CXX_STANDARD 14)

add_executable(AddPolyParallel main.cpp Polynomial/Monomial.cpp Polynomial/Monomial.h
        Polynomial/Polynomial.cpp Polynomial/Polynomial.h)