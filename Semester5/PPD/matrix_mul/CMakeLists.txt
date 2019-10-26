cmake_minimum_required(VERSION 3.15)
project(matrix_mul)

set(CMAKE_CXX_STANDARD 14)

add_executable(matrix_mul thread_mul.cpp Tasks.cpp Tasks.h mul_thread_pool.cpp Utils.cpp Utils.h)