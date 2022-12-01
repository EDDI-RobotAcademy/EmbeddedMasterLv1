cmake_minimum_required(VERSION 3.23)
project(third_exercise C)

set(CMAKE_C_STANDARD 99)

add_executable(third_exercise main.c domain/radio_frequency/service/data_transfer_object/rf_receiver_data_transfer_object.h domain/radio_frequency/service/data_transfer_object/rf_receiver_data_transfer_object.c)
