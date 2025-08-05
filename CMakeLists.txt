cmake_minimum_required(VERSION 3.31)
project(dsa)

set(CMAKE_CXX_STANDARD 20)

add_executable(dsa main.cpp
        LinkedList.cpp
        LinkedList.h
        Stack.cpp
        Stack.h
        Queue.cpp
        Queue.h
        BST.cpp
        BST.h)
