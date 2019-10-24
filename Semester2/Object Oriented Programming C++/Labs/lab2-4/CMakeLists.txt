cmake_minimum_required(VERSION 3.9)
project(lab2_generic_dyn C)

set(CMAKE_C_STANDARD 99)

add_executable(lab2_generic_dyn main.c utils/DynamicVector.c utils/DynamicVector.h utils/UserInterfaceVal.c utils/UserInterfaceVal.h domain/Transaction.c domain/Transaction.h repository/Repository.c repository/Repository.h ui/UserInterface.c ui/UserInterface.h service/Service.c service/Service.h utils/undo.c utils/undo.h)
