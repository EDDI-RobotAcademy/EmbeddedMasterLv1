cmake_minimum_required(VERSION 3.0)

project(ddd C)
set(CMAKE_C_STANDARD 99)
set(HEADER_DIR command)
file(GLOB HEADER_FILES ${HEADER_DIR}/*.h)

set(SOURCE main/how_to_malloc.c member/member_handler.c 
        ${HEADER_FILES} command/command_handler.c main/main.c)

add_executable(${PROJECT_NAME} ${SOURCE})