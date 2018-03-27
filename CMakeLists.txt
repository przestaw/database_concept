cmake_minimum_required(VERSION 3.9)
project(database_for_estate)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "$(CMAKE_CXX_FLAGS) -std=c++11 -O3 -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

file(GLOB SOURCES "src/*.cpp")

project(database_concept)

include_directories(include)

add_executable(database_concept ${SOURCES} ../include/database.hpp ../include/estate.hpp)