cmake_minimum_required(VERSION 3.20)
project(xeger VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================================

## Find dependencies
find_package(re2 REQUIRED)

file(GLOB SRC_FILES "src/*.cpp")
## Create main executable
add_executable(xeger ${SRC_FILES})
target_include_directories(xeger
  PRIVATE 
    "${CMAKE_CURRENT_LIST_DIR}/source"
)
target_link_libraries(
  xeger
  PRIVATE
    re2::re2
)

# ============================================================


target_include_directories(xeger PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_BINARY_DIR})