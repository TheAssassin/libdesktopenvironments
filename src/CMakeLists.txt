cmake_minimum_required(VERSION 2.5)

file(GLOB sourceFiles *.cpp)
add_library(libdesktopenvironments ${sourceFiles} ../include/desktopenvironments.h)
target_include_directories(libdesktopenvironments PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
set_target_properties(libdesktopenvironments PROPERTIES PREFIX "")

