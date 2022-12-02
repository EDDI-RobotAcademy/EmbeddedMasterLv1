#ifndef __RF_RECEIVER_DATA_TRANSFER_OBJECT_H__
#define __RF_RECEIVER_DATA_TRANSFER_OBJECT_H__

typedef struct _rf_receiver_data_transfer_object rf_receiver_data_transfer_object;

struct _rf_receiver_data_transfer_object
{
    int channel_data;
    int channel_scale_order;
    int channel_sub_order;
};

rf_receiver_data_transfer_object rf_receiver_dto;

void config_rf_receiver_data_transfer_object (int, int, int);

#endif
