cmake_minimum_required(VERSION 3.23)
project(nodap C)

set(CMAKE_C_STANDARD 99)

add_executable(nodap main.c radio_frequency/rf_receiver.h radio_frequency/rf_receiver.c)
