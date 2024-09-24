cmake_minimum_required(VERSION 3.29)
project(introToCpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(introToCpp
    helloWorld.cpp
    helloWorld.h)
