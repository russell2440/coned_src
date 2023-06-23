cmake_minimum_required(VERSION 3.10)

#set the project name and vesion.
project(ht)

#specify the c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add the executible
add_executable(is insertion_sort.cpp insertion_sort_test.cpp)
