cmake_minimum_required(VERSION 3.26)
project(Lab5_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab5_2
        client.cpp
        client.h
        main.cpp)
