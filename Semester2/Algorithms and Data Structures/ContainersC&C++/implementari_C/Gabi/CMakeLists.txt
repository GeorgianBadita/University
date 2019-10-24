cmake_minimum_required(VERSION 3.9)
project(Gabi C)

set(CMAKE_C_STANDARD 99)

add_executable(Gabi main.c DynVect.h DynVect.c Repo.c Repo.h Service.c Service.h UI.c UI.h Validator.c Validator.h Tests.c Tests.h Fotbalist.c Fotbalist.h)