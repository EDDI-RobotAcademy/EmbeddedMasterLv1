cmake_minimum_required(VERSION 3.16)
project(second_exercise C)

set(CMAKE_C_STANDARD 99)

add_executable(second_exercise main.c domain/pre_allocated_memory/entity/pre_allocated_memory.c
        domain/pre_allocated_memory/service/pre_allocated_memory_service.c)
