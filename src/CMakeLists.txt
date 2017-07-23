cmake_minimum_required(VERSION 3.0)

file(GLOB sourceFiles *.cpp)
add_library(desktopenvironment ${sourceFiles})
