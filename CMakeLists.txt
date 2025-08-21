cmake_minimum_required(VERSION 3.30)
project(AED2)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)

add_executable(AED2
    include/utils.h
    src/main.cpp
    src/main.h
    src/utils.cpp
    .gitignore
    README.md)
