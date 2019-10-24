cmake_minimum_required(VERSION 3.14)
project(Lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab1 main.cpp Color.h Geometry.h Image.h Intersection.h Light.h Line.h lodepng.cpp lodepng.h Material.h Scene.h Sphere.cpp Sphere.h Vector.h)