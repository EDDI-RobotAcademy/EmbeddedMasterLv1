#include "custom_alarm.h"

#include <signal.h>

void (* alarm_internal_handler)(void);

void init_custom_alarm (void (* handler)(void))
{
    signal(SIGALRM, custom_alarm_handler);
    alarm_internal_handler = handler;
    config_custom_alarm();
}

void config_custom_alarm (void)
{
    ualarm(RF_RECEIVE_TIME_INTERVAL, 0);
}

void custom_alarm_handler (int signal_number)
{
    config_custom_alarm();
    alarm_internal_handler();
}