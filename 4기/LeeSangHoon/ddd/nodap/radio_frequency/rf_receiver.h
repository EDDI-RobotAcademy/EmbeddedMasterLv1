#ifndef __RF_RECEIVER_H__
#define __RF_RECEIVER_H__

#define RF_RECEIVE_TIME_INTERVAL    20

#define EVERY_RF_CHANNEL_SET        1
#define SOME_RF_CHANNEL_SET         0

enum rf_channel {
    CHANNEL1,
    CHANNEL2,
    CHANNEL3,
    CHANNEL4,
    CHANNEL5,
    CHANNEL6,
    CHANNEL7,
    CHANNEL8,
    CHANNEL_END
};

typedef struct _rf_receive_object rf_receive_object;

struct _rf_receive_object
{
    int channel[RF_CHANNEL_MAX];
};

rf_receive_object rf_receive_object_data;
int current_rf_channel;

void receive_rf_signal (void);
int handle_rf_channel_data (void);
void print_rf_channel_data (void);
int is_all_rf_channel_set (void);
void rf_data_handle (void);

#endif
