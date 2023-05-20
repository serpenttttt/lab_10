cmake_minimum_required(VERSION 3.24)
project(unique C)

set(CMAKE_C_STANDARD 11)

add_executable(unique main.c struct.h functions.c functions.h)