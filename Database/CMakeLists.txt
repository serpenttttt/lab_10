cmake_minimum_required(VERSION 3.24)
project(city_database C)

set(CMAKE_C_STANDARD 11)

add_executable(city_database main.c HT.h functions.h functions.c HT_functions.c HT_functions.h)