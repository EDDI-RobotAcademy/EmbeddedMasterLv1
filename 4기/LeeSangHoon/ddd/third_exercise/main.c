#include <stdio.h>

#include "domain/common/utility/common.h"
#include "domain/common/utility/random/custom_random.h"
#include "domain/common/utility/alarm/custom_alarm.h"

#include "domain/radio_frequency/entity/rf_receiver.h"
#include "domain/wifi/entity/wifi_receive.h"

#include "domain/radio_frequency/service/rf_receiver_service.h"
#include "domain/radio_frequency/service/data_transfer_object/rf_receiver_data_transfer_object.h"

#include "domain/wifi/service/wifi_receive_service.h"
#include "domain/wifi/service/data_transfer_object/wifi_receive_data_transfer_object.h"

#include "domain/dc_motor/entity/dc_motor_control_data.h"
#include "domain/servo_motor/entity/servo_motor_control_data.h"
#include "domain/led/entity/led_control_data.h"

int main (void)
{
    init_random();

#if 1
    init_custom_alarm(receive_rf_signal, RF_RECEIVE_TIME_INTERVAL);

    for (;;)
    {
        if (check_all_rf_channel_set() == EVERY_RF_CHANNEL_SET)
        {
            print_rf_channel_data();

            config_rf_receiver_data_transfer_object(CHANNEL1, RF_SCALE_DC_MOTOR);
            rf_receive_data_scale_call_table[RF_SCALE_DC_MOTOR]();

            config_rf_receiver_data_transfer_object(CHANNEL2, RF_SCALE_SERVO_MOTOR);
            rf_receive_data_scale_call_table[RF_SCALE_SERVO_MOTOR]();

            config_rf_receiver_data_transfer_object(CHANNEL3, RF_SCALE_LED);
            rf_receive_data_scale_call_table[RF_SCALE_LED]();

            printf("ch1: %d, ch2: %d, ch3: %s\n",
                   dc_motor_control_data.control_data, servo_motor_control_data.control_data,
                   led_control_data.control_data ? "LED ON" : "LED OFF");
        }
    }
#endif

#if 0
    init_custom_alarm(receive_wifi_data, WIFI_RECEIVE_TIME_INTERVAL);

    for (;;)
    {
        print_wifi_data();

        config_wifi_receive_data_transfer_object(WIFI_SCALE_DC_MOTOR, CLOCK_WISE);
        wifi_data_scale2dc_motor();
        printf("ch1: %d, ", dc_motor_control_data.control_data);
    }
#endif

    return 0;
}
