#include "rf_receiver_data_transfer_object.h"
#include "../../entity/rf_receiver.h"

void config_rf_receiver_data_transfer_object
        (int channel_number, int channel_scale_order)
{
    rf_receiver_dto.channel_data = rf_receive_object_data.channel[channel_number];
    rf_receiver_dto.channel_scale_order = channel_scale_order;
}
