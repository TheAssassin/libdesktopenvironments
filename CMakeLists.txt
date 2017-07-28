cmake_minimum_required(VERSION 3.0)
project(DesktopEnvironments)

set(CMAKE_CXX_STANDARD 98)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")

include_directories(include)

add_subdirectory(src)

add_executable(demo demo.cpp)
target_link_libraries(demo desktopenvironment)
