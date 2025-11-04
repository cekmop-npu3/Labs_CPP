cmake_minimum_required(VERSION 3.10)

project(Clock VERSION 0.0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)

include_directories(include src)

add_library(clocklib 
    src/clock.cpp 
    src/electronic_clock.cpp 
    src/floor_clock.cpp 
    src/mechanical_clock.cpp 
    src/smart_watch.cpp 
    src/wrist_watch.cpp
)

add_executable(clock src/main.cpp)

target_link_libraries(clock PRIVATE clocklib)

