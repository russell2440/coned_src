cmake_minimum_required(VERSION 3.10)

#set the project name and vesion.
project(qs)

#specify the c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add the executible
add_executable(qs quick_sort_t.cpp quick_sort_test.cpp)
