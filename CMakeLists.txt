cmake_minimum_required(VERSION 3.13)
project(hw2)

SET(CMAKE_CXX_COMPILER mpicxx)
SET(CMAKE_C_COMPILER  mpicc)
find_package(MPI REQUIRED)
include_directories("/usr/include/mpich/")

add_executable(hw2 test.cpp)