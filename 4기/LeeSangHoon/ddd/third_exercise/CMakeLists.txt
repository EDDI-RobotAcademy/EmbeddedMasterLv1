cmake_minimum_required(VERSION 3.23)
project(third_exercise C)

set(CMAKE_C_STANDARD 99)

add_executable(third_exercise main.c domain/radio_frequency/service/data_transfer_object/rf_receiver_data_transfer_object.h domain/radio_frequency/service/data_transfer_object/rf_receiver_data_transfer_object.c domain/dc_motor/repository/dc_motor_repository.h domain/dc_motor/repository/dc_motor_repository.c domain/dc_motor/service/dc_motor_service.h domain/wifi/entity/wifi_receive.h domain/wifi/entity/wifi_receive.c domain/common/utility/common.h)
