#ifndef __RF_RECEIVER_H__
#define __RF_RECEIVER_H__

#define RF_CHANNEL_MAX              8

#define RF_MIN                      600
#define RF_MAX                      1400

#define RF_RECEIVE_TIME_INTERVAL    10

#define EVERY_RF_CHANNEL_SET        1
#define SOME_RF_CHANNEL_SET         0

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

#endif
