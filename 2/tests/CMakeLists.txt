add_executable(main_test test.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fsanitize=address")

target_link_libraries(main_test PRIVATE String)

enable_testing()

add_test(NAME StringTest COMMAND main_test)

