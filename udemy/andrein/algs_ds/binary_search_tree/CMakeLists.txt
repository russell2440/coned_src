cmake_minimum_required(VERSION 3.10)

#set the project name and vesion.
project(bst)

#specify the c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add the executible
add_executable(bst bst_t.cpp bst_t_test.cpp)
