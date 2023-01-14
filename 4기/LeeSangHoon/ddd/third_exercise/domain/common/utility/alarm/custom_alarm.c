#include "custom_alarm.h"

#include <signal.h>

void (* alarm_internal_handler)(void);
int alarm_interval_time;

void init_custom_alarm (void (* handler)(void), int interval_time)
{
    signal(SIGALRM, custom_alarm_handler);
    alarm_internal_handler = handler;
    alarm_interval_time = interval_time;
    config_custom_alarm();
}

void config_custom_alarm (void)
{
    ualarm(alarm_interval_time, 0);
}

void custom_alarm_handler (int signal_number)
{
    config_custom_alarm();
    alarm_internal_handler();
}