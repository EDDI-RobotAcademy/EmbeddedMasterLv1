#ifndef __RF_RECEIVE_H__
#define __RF_RECEIVE_H__

#define RANDOM_DATA_MIN 600
#define RANDOM_DATA_MAX 1400
#define RF_CH_NUMBER    8


enum rf_chanel {
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
    int data;
};
rf_receive_object *rf_receive_object_data;
int current_rf_channel;


void rf_ch_init (void);
void receive_rf_signal (void);
void printf_rf_signal (void);


#endif 