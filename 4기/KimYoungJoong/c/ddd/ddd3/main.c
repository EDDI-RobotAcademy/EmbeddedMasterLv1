#include <stdio.h>
#include <stdlib.h>

#include "common/util/custom_random.h"
#include "entity/receive/rf_receive.h"


int main (void)
{
    rf_init();
    custom_random_init();
    for (current_rf_channel; current_rf_channel < RF_CH_NUMBER; current_rf_channel++)
    {

        rf_receive_object_data[current_rf_channel].data = custom_random_generator(RANDOM_DATA_MAX, RANDOM_DATA_MIN);
 
        printf("rf_receive_object_data[%d].data : %d\n", current_rf_channel, rf_receive_object_data[current_rf_channel].data);
    }

    return 0;
}