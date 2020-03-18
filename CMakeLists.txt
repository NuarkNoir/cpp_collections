cmake_minimum_required(VERSION 3.15)
project(cpp_collections)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp_collections
        container.h
        main.cpp
        queue.h
        vector.h stack.h containers.h)
