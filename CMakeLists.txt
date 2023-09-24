cmake_minimum_required(VERSION 3.26)
project(dynamic_cpp)

set(CMAKE_CXX_STANDARD 20)
set(HEADER_FILES headers/ladder.h)

add_executable(dynamic_cpp main.cpp
        headers/ladder.h
        n-k_ladders/ladder.cpp
        min_jumps/jumps.cpp
        headers/jumps.h
        threads/thread.cpp
        headers/threads.h
        dynamic/dynamic.cpp)
