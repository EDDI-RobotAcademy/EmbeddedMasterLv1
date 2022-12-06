#include "rf_receiver.h"

void rf_ch_set(void)
{
    rf_receive_object *rf_r_handler_ch1;
    rf_receive_object *rf_r_handler_ch2;
    rf_receive_object *rf_r_handler_ch3;
    
    rf_r_handler_ch1 = (rf_receive_object*) malloc(sizeof(rf_receive_object));
    rf_r_handler_ch2 = (rf_receive_object*) malloc(sizeof(rf_receive_object));
    rf_r_handler_ch3 = (rf_receive_object*) malloc(sizeof(rf_receive_object));

}
void rf_receive_signal(rf_receive_object *rf_r_handler)
{
    rf_r_handler->rf_receive_signal;
}

void rf_receive_data_print(data_transfer_object *dto)
{

}