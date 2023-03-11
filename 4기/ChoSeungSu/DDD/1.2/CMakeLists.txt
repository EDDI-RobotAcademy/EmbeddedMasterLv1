cmake_minimum_required(VERSION 3.16)
project (first_DDD)

set(CMAKE_C_STANDARD 99)

add_executable(1.2 main.c RF/rf_receiver.c Utility/Alarm/custom_alarm.c Utility/Random/custom_random.c Service/rf_receive_data_scale.c Service/rf_receive_data_transfer_object.c)

