#include <stdio.h>
#include <stdlib.h>

#include "rf_receive.h"
#include "../../common/util/custom_random.h"



void rf_ch_init (void)
{
    rf_receive_object_data = (rf_receive_object*)malloc(sizeof(rf_receive_object_data) * RF_CH_NUMBER);
    if(rf_receive_object_data == NULL)
    {
        printf("RF 수신기 동적할당 실패!!\n");
    }
}

void receive_rf_signal (void)
{
        rf_receive_object_data[current_rf_channel++].data = custom_random_generator(RANDOM_DATA_MAX, RANDOM_DATA_MIN);    
        if(current_rf_channel == RF_CH_NUMBER + 1) { current_rf_channel = 0; }
        printf("current_rf_channel : %d\n", current_rf_channel);
        

}

void printf_rf_signal (void)
{    
    current_rf_channel = 0;
    printf("rf_ch1 : %d, ", rf_receive_object_data[current_rf_channel++].data);
    printf("rf_ch2 : %d, ", rf_receive_object_data[current_rf_channel++].data);
    printf("rf_ch3 : %d, ", rf_receive_object_data[current_rf_channel++].data);
    printf("rf_ch4 : %d, ", rf_receive_object_data[current_rf_channel++].data);
    printf("rf_ch5 : %d, ", rf_receive_object_data[current_rf_channel++].data);
    printf("rf_ch6 : %d, ", rf_receive_object_data[current_rf_channel++].data);
    printf("rf_ch7 : %d, ", rf_receive_object_data[current_rf_channel++].data);
    printf("rf_ch8 : %d" , rf_receive_object_data[current_rf_channel].data);
    printf("\n");
    
    if(current_rf_channel == RF_CH_NUMBER + 1) current_rf_channel = 0;
}