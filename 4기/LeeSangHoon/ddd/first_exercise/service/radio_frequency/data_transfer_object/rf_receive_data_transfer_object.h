#ifndef __RF_RECEIVE_DATA_TRANSFER_OBJECT_H__
#define __RF_RECEIVE_DATA_TRANSFER_OBJECT_H__

typedef struct _rf_receive_data_transfer_object rf_receive_data_transfer_object;

struct _rf_receive_data_transfer_object
{
    int channel_data;
    int channel_scale_order;
    int channel_sub_order;
};

rf_receive_data_transfer_object rf_receive_dto;

void config_rf_receive_data_transfer_object (int, int, int);

#endif
