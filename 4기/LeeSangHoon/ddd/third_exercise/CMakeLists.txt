cmake_minimum_required(VERSION 3.17)
project(third_exercise C)

set(CMAKE_C_STANDARD 99)

add_executable(third_exercise main.c
        domain/radio_frequency/service/data_transfer_object/rf_receiver_data_transfer_object.c
        domain/radio_frequency/service/rf_receiver_service.c
        domain/wifi/entity/wifi_receive.c
        domain/dc_motor/entity/dc_motor_control_data.c
        domain/common/utility/random/custom_random.c
        domain/common/utility/alarm/custom_alarm.c
        domain/wifi/service/data_transfer_object/wifi_receive_data_transfer_object.c
        domain/wifi/service/wifi_receive_service.c
        domain/radio_frequency/entity/rf_receiver.c
        domain/led/entity/led_control_data.c
        domain/common/utility/scale/custom_scale.c
        domain/servo_motor/entity/servo_motor_control_data.c
        )
