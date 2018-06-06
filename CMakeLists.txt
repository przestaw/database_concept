cmake_minimum_required(VERSION 3.5)

project(Estate)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11 -O3 -Wall -Iinclude")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

file(GLOB SOURCES "src/*.cpp")

include_directories(include)

add_library(Estate ${SOURCES})

add_executable(ex3 ex3.cpp)

target_link_libraries(ex3 Estate)

add_executable(ex3-test test/ex3-test.cpp)

target_link_libraries(ex3-test Estate)

