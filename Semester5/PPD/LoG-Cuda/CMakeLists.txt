cmake_minimum_required(VERSION 3.15)
project(LoG_Cuda)

set(CMAKE_CXX_FLAGS "--std=c++14 ${CMAKE_CXX_FLAGS}")



cmake_minimum_required(VERSION 2.8)
set(PROJECT laplacefilter)


find_package(CUDA REQUIRED)
find_package(OpenCV REQUIRED)

list(APPEND CUDA_NVCC_FLAGS "-arch=sm_30;-std=c++14;-O3;-DVERBOSE")
set(CUDA_PROPOGATE_HOST_FLAGS OFF)

cuda_add_executable(${PROJECT} LaplaceFilter.cu)
target_link_libraries(${PROJECT} ${OpenCV_LIBS})