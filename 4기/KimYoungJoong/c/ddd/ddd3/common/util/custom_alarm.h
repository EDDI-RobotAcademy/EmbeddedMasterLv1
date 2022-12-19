#ifndef __CUSTOM_ALARM_H__
#define __CUSTOM_ALARM_H__

#define RF_RECEIVE_TIME_INTERVAL    20

#include <unistd.h>

void init_custom_alarm (void);
void config_custom_alarm (void);
void custom_alarm_handler (int);


#endif