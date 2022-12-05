cmake_minimum_required(VERSION 3.17)
project(second_exercise C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_BUILD_TYPE Debug)

add_executable(second_exercise main.c domain/pre_allocated_memory/entity/pre_allocated_memory.c
        domain/pre_allocated_memory/value_object/free_memory_table.c domain/pre_allocated_memory/value_object/usage_memory_table.h domain/pre_allocated_memory/value_object/usage_memory_table.c)
