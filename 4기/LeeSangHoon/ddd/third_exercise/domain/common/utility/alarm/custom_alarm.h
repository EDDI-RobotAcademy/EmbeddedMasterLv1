#ifndef __CUSTOM_ALARM_H__
#define __CUSTOM_ALARM_H__

#include <unistd.h>

void init_custom_alarm (void);
void config_custom_alarm (void);
void custom_alarm_handler (int);

#endif
