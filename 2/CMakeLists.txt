cmake_minimum_required(VERSION 3.10)

project(StringLib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include src)

add_library(String STATIC src/string.cpp)

add_subdirectory(tests)

