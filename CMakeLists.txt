cmake_minimum_required(VERSION 2.5)
project(DesktopEnvironments)

set(CMAKE_CXX_STANDARD 98)

add_subdirectory(src)

add_executable(libde_demo demo.cpp)
target_link_libraries(libde_demo desktopenvironment)

