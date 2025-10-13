cmake_minimum_required(VERSION 3.10)

project(String VERSION 0.0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include src)

add_library(String STATIC src/string.cpp)

set_target_properties(String
    PROPERTIES PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/include/string.hpp
)

include(GNUInstallDirs)

install(TARGETS String
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

configure_file(cmake/String.pc.in String.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)

add_subdirectory(tests)

