cmake_minimum_required(VERSION 3.9)
project(lab6)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab6 main.cpp domain/movie.cpp domain/movie.h utils/tests.cpp utils/tests.h  repositroy/repository.cpp repositroy/repository.h service/service.cpp service/service.h ui/user_interface.cpp ui/user_interface.h domain/validator.cpp domain/validator.h utils/helper.cpp utils/helper.h domain/cart.cpp domain/cart.h domain/export.cpp domain/export.h domain/undo.cpp domain/undo.h)

include(CodeCoverage.cmake)
APPEND_COVERAGE_COMPILER_FLAGS()
