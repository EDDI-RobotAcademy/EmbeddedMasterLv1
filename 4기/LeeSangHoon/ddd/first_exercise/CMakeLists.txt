cmake_minimum_required(VERSION 3.17)
project(first_exercise C)

set(CMAKE_C_STANDARD 99)

add_executable(first_exercise main.c utility/random/custom_random.c radio_frequency/rf_receiver.c utility/alarm/custom_alarm.c)