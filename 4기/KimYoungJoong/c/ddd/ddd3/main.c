#include <stdio.h>
#include <stdlib.h>

#include "common/util/custom_random.h"
#include "common/util/custom_alarm.h"
#include "entity/receive/rf_receive.h"
#include "domain_service/dto/dto.h"



int main (void)
{
    printf("program strat!!\n");
    rf_ch_init();

    custom_random_init();
    timer_init();
    //init_custom_alarm();
    
    while(1)
    {
        //servo_data_trans_object(RF, CHANNEL1);
        //dc_motor_data_trans_object(RF, CHANNEL2, rf_receive_object_data->dc_motor_sub_order);
        //led_data_trans_object(RF,CHANNEL3);
        //printf_rf_signal();
        
    }
    return 0;
}