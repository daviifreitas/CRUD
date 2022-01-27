cmake_minimum_required(VERSION 3.21)
project(CRUD C)

set(CMAKE_C_STANDARD 99)

add_executable(CRUD main.c func.c func.h)

add_executable(main main.c)