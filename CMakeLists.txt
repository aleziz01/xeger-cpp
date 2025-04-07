cmake_minimum_required(VERSION 3.20)
project(projectname)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(lib SHARED xegerCPP.cpp)
add_executable(test test.cpp)

target_link_libraries(test PRIVATE lib)