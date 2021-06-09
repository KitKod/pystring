cmake_minimum_required(VERSION 3.19)
project(pystring C)

set(CMAKE_C_STANDARD 11)

add_library(pystring pystring.c pystring.h)
#add_executable(test_smth pystring.c)