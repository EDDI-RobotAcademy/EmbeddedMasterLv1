#include "rf_receiver.h"
#include "../../utility/random/custom_random.h"

#include <math.h>
#include <stdio.h>

void receive_rf_signal (void)
{
    rf_receive_object_data.channel[current_rf_channel++] = handle_rf_channel_data();

    if (current_rf_channel == RF_CHANNEL_MAX) { current_rf_channel = 0; }
}

int handle_rf_channel_data (void)
{
    return custom_random(RF_MIN, RF_MAX);
}

void print_rf_channel_data (void)
{
    int i;

    printf("ch1 = %d, ch2 = %d, ch3 = %d, ch4 = %d, ch5 = %d, ch6 = %d, ch7 = %d, ch8 = %d\n",
           rf_receive_object_data.channel[0], rf_receive_object_data.channel[1],
           rf_receive_object_data.channel[2], rf_receive_object_data.channel[3],
           rf_receive_object_data.channel[4], rf_receive_object_data.channel[5],
           rf_receive_object_data.channel[6], rf_receive_object_data.channel[7]);
}

int is_all_rf_channel_set (void)
{
    int i;

    if (current_rf_channel == 0) { return EVERY_RF_CHANNEL_SET; }
    else { return SOME_RF_CHANNEL_SET; }
}