cmake_minimum_required(VERSION 3.6)
project(Assignment_5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BasicShape.cpp BasicShape.h Circle.cpp Circle.h Rectangle.cpp Rectangle.h)
add_executable(Assignment_5 ${SOURCE_FILES})