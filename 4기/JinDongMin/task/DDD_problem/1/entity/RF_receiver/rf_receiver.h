#ifndef __RF_RECEIVER_H__
#define __RF_RECEIVER_H__

#define CHANNEL_NUMBER_COUNT    8

#define MIN_NUMBER_OF_RF_RECEIVER   600
#define MAX_NUMBER_OF_RF_RECEIVER   1400

#define MIN_CHANNEL_NUMBER  0
#define MAX_CHANNEL_NUMBER  ((CHANNEL_NUMBER_COUNT) - 1)

typedef struct _rf_receiver rf_receiver;

struct _rf_receiver
{
    int channel_number;
    int data;
};

static rf_receiver *rf_receiver_p;

void initialize_rf_receiver(rf_receiver *);
void listen_rf_receiver(rf_receiver *); // 데이터가 수신되면 그 데이터에는 정보와 채널 값이 들어있다고 가정
void register_current_rf_receiver(const rf_receiver *);
int get_data_from_rf_receiver(const rf_receiver);


#endif // __RF_RECEIVER_H__