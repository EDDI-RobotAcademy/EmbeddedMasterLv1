#include <stdio.h>

#include "domain/common/utility/random/custom_random.h"
#include "domain/common/utility/alarm/custom_alarm.h"

#include "domain/radio_frequency/entity/rf_receiver.h"

int main (void)
{
    init_random();

#if __RF__
    init_custom_alarm(receive_rf_signal);

    for (;;)
    {
        if (is_all_rf_channel_set() == EVERY_RF_CHANNEL_SET)
        {
            print_rf_channel_data();

            config_rf_receive_data_transfer_object(CHANNEL1, RF_SCALE_DC_MOTOR, CLOCK_WISE);
            rf_signal_scale2dc_motor();
            printf("ch1: %d, ", dc_motor_control_data.control_data);
        }
    }
#elif __WIFI__
    init_custom_alarm(receive_wifi_data);

    for (;;)
    {
        print_wifi_data();

        config_wifi_receive_data_transfer_object(RF_SCALE_DC_MOTOR, CLOCK_WISE);
        wifi_data_scale2dc_motor();
        printf("ch1: %d, ", dc_motor_control_data.control_data);
    }
#endif

    return 0;
}
