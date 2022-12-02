#include "rf_receive_data_transfer_object.h"
#include "../../../entity/radio_frequency/rf_receiver.h"

void config_rf_receive_data_transfer_object
    (int channel_number, int channel_scale_order, int channel_sub_order)
{
    rf_receive_dto.channel_data = rf_receive_object_data.channel[channel_number];
    rf_receive_dto.channel_scale_order = channel_scale_order;
    rf_receive_dto.channel_sub_order = channel_sub_order;
}
