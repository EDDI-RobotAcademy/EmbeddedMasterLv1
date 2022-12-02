#include "utility/random/custom_random.h"
#include "utility/alarm/custom_alarm.h"
#include "entity/radio_frequency/rf_receiver.h"
#include "service/radio_frequency/rf_receive_data_scale.h"
#include "service/radio_frequency/data_transfer_object/rf_receive_data_transfer_object.h"
#include "common/common.h"
#include "common/rf_receive_dto_table.h"

#include <stdio.h>

int main (void)
{
    init_random();
    init_custom_alarm();

    for (;;)
    {
        if (is_all_rf_channel_set() == EVERY_RF_CHANNEL_SET)
        {
            print_rf_channel_data();

            config_rf_receive_data_transfer_object(CHANNEL1, RF_SCALE_DC_MOTOR, CLOCK_WISE);
            printf("ch1: %d, ", rf_receive_data_scale_call_table[RF_SCALE_DC_MOTOR]());

            config_rf_receive_data_transfer_object(CHANNEL2, RF_SCALE_SERVO_MOTOR, DO_NOTHING);
            printf("ch2: %d, ", rf_receive_data_scale_call_table[RF_SCALE_SERVO_MOTOR]());

            config_rf_receive_data_transfer_object(CHANNEL3, RF_SCALE_LED, DO_NOTHING);
            printf("ch3: %s\n", (rf_receive_data_scale_call_table[RF_SCALE_LED]() ? "On" : "Off"));
        }
    }

    return 0;
}
