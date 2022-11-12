cmake_minimum_required(VERSION 3.23)
project(test_list_proj C)

set(CMAKE_C_STANDARD 99)

add_executable(test_list_proj main.c data_structure/list/array_lists.c data_structure/list/array_lists.h common/common.h memory/memory_alloc.h memory/memory_alloc.c)
