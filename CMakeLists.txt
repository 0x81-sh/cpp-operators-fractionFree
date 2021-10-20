cmake_minimum_required(VERSION 3.21)
project(FractionFree)

set(CMAKE_CXX_STANDARD 23)
add_compile_options(-Wall)

add_executable(FractionFree main.cpp Fraction.cpp Fraction.h)
