cmake_minimum_required(VERSION 2.8.4)
project(HashTable)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(HashTable ${SOURCE_FILES})