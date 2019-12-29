cmake_minimum_required(VERSION 3.15)
project(MulPolyMPI)
find_package(MPI)
include_directories(${MPI_INCLUDE_PATH})
set(CMAKE_CXX_STANDARD 14)

add_executable(MulPolyMPI main.cpp)
target_compile_options(MulPolyMPI PRIVATE ${MPI_CXX_COMPILE_FLAGS})
target_link_libraries(MulPolyMPI ${MPI_CXX_LIBRARIES} ${MPI_CXX_LINK_FLAGS})