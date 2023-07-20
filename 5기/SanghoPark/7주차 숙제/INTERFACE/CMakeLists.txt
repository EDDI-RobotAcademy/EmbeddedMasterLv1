cmake_minimum_required(VERSION 3.0)

project(interface C)
set(CMAKE_C_STANDARD 99)
set(SOURCE main/main.c member/member_register_handler.c console/console_handler.c)

add_executable(${PROJECT_NAME} ${SOURCE})