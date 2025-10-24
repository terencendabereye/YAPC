cmake_minimum_required(VERSION 3.10)

project(demo)

add_executable(demo src/main.cpp)

target_compile_options(demo PRIVATE -g)
