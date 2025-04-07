cmake_minimum_required(VERSION 3.20)
project(projectname)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test test.cpp)
add_library(lib SHARED xegerCPP.cpp)

