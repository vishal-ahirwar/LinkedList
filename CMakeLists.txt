cmake_minimum_required(VERSION 3.28)
project(LinkedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(LinkedList main.cpp
        linkedlist.cuh
        adt.cuh
        colors.cuh)
