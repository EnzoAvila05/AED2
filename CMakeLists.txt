cmake_minimum_required(VERSION 3.30)
project(AED2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(src)

add_executable(AED2
        src/main.cpp
        src/utils.cpp
)