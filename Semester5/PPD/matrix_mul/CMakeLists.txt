cmake_minimum_required(VERSION 3.15)
project(matrix_mul)

set(CMAKE_CXX_STANDARD 14)

add_executable(matrix_mul main.c thread_mul.cpp)