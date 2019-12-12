cmake_minimum_required(VERSION 3.15)
project(Mursa231)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

add_executable(Mursa231 main.cpp Friendships/Node.h Friendships/Node.cpp Friendships/Friendships.cpp Friendships/Friendships.h ThreadSafeQueue.h)