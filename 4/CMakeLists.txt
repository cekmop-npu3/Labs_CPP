cmake_minimum_required(VERSION 3.10)

project(Array VERSION 0.0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)

include_directories(include src ../3/src ../3/include)

add_subdirectory(../3 ../3/build)

add_executable(main src/main.cpp)

target_link_libraries(main PRIVATE clocklib)

add_dependencies(main clock)

