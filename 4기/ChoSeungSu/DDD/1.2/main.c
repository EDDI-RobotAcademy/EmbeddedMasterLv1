#include "Utility/Random/custom_random.h"
#include "Utility/Alarm/custom_alarm.h"
#include "RF/rf_receiver.h"
#include "Service/rf_receive_data_scale.h"
#include "Service/rf_receive_data_transfer_object.h"
#include "Common/common.h"
#include "Common/rf_receive_dto_table.h"

#include <stdio.h>

int main(void)
{
    init_rarndom();
    init_custom_alarm();

    for (;;)
    {
        if (is_all_rf_channel_set()== ALL_RF_CHANNEL_SET)
        {
            print_rf_channel_data();

            config_rf_recevie_data_transfer_object(CHANNEL1, RF_SCALE_DC_MOTOR, CLOCK_WISE);
            printf("CH1 :%d\n", rf_receive_data_scale_call_table[RF_SCALE_DC_MOTOR]());
          
            config_rf_recevie_data_transfer_object(CHANNEL2, RF_SCALE_SERVO_MOTOR, DO_NOTHING);
            printf("CH2 :%d\n", rf_receive_data_scale_call_table[RF_SCALE_DC_MOTOR]());

            config_rf_recevie_data_transfer_object(CHANNEL3, RF_SCALE_LED, DO_NOTHING);
            printf("CH3 :%s\n", rf_receive_data_scale_call_table[RF_SCALE_DC_MOTOR]() ? "On" : "Off");
        }
    }

    return 0;
}