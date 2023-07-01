cmake_minimum_required(VERSION 3.0)

project(ddd C)
set(CMAKE_C_STANDARD 99)
set(SOURCE main/main.c main/how_to_malloc.c)

add_executable(${PROJECT_NAME} ${SOURCE})