cmake_minimum_required(VERSION 3.17)
project(first_exercise C)

set(CMAKE_C_STANDARD 99)

add_executable(first_exercise main.c utility/random/custom_random.c entity/radio_frequency/rf_receiver.c
        utility/alarm/custom_alarm.c service/radio_frequency/data_transfer_object/rf_receive_data_transfer_object.c
        service/radio_frequency/rf_receive_data_scale.c)