//
// Created by oem on 22. 11. 20..
//

#ifndef FIRST_EXERCISE_RF_RECEIVE_DTO_TABLE_H
#define FIRST_EXERCISE_RF_RECEIVE_DTO_TABLE_H

#include "../service/radio_frequency/rf_receive_data_scale.h"

typedef int (* rf_receive_data_scale_call_ptr_t)(void);

const rf_receive_data_scale_call_ptr_t rf_receive_data_scale_call_table[RF_SCALE_END] = {
        (rf_receive_data_scale_call_ptr_t const) rf_scale_dc_motor,
        (rf_receive_data_scale_call_ptr_t const) rf_scale_servo_motor,
        (rf_receive_data_scale_call_ptr_t const) rf_scale_led
};

#endif //FIRST_EXERCISE_RF_RECEIVE_DTO_TABLE_H
