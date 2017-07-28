cmake_minimum_required(VERSION 2.5)

file(GLOB sourceFiles *.cpp)
add_library(desktopenvironment ${sourceFiles})
