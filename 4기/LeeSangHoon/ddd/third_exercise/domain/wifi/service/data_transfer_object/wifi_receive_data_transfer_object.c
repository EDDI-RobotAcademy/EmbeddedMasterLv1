#include "wifi_receive_data_transfer_object.h"

void config_wifi_receive_data_transfer_object (int scale_order, int sub_order)
{
    wifi_receive_dto.scale_order = scale_order;
    wifi_receive_dto.sub_order = sub_order;
}
