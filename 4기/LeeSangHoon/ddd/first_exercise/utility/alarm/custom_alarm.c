#include "custom_alarm.h"
#include "../../radio_frequency/rf_receiver.h"
#include <stdio.h>

#include <signal.h>

void init_custom_alarm (void)
{
    signal(SIGALRM, custom_alarm_handler);
    config_custom_alarm();
}

void config_custom_alarm (void)
{
    ualarm(RF_RECEIVE_TIME_INTERVAL, 0);
}

void custom_alarm_handler (int signal_number)
{
    printf("Interrupt!\n");
    config_custom_alarm();
    receive_rf_signal();
}