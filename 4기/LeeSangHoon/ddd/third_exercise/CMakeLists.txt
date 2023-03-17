cmake_minimum_required(VERSION 3.17)
project(third_exercise C)

set(CMAKE_C_STANDARD 99)

add_executable(third_exercise main.c domain/radio_frequency/service/data_transfer_object/rf_receiver_data_transfer_object.h domain/radio_frequency/service/data_transfer_object/rf_receiver_data_transfer_object.c domain/dc_motor/service/dc_motor_service.h domain/wifi/entity/wifi_receive.h domain/wifi/entity/wifi_receive.c domain/common/utility/common.h domain/dc_motor/entity/dc_motor_control_data.h domain/dc_motor/entity/dc_motor_control_data.c)
