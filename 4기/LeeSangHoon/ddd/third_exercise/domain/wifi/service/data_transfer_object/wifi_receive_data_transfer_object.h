#ifndef __WIFI_RECEIVE_DATA_TRANSFER_OBJECT_H__
#define __WIFI_RECEIVE_DATA_TRANSFER_OBJECT_H__

typedef struct _wifi_receive_data_transfer_object wifi_receive_data_transfer_object;

struct _wifi_receive_data_transfer_object
{
    int scale_order;
    int sub_order;
};

wifi_receive_data_transfer_object wifi_receive_dto;

void config_rf_receiver_data_transfer_object (int, int, int);

#endif
