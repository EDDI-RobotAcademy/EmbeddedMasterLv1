#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

#define RF_CHANNEL_MAX              8

#define RF_MIN                      600
#define RF_MIDDLE                   1000
#define RF_MAX                      1400

void init_random(void)
{
    srand(time(NULL));
}

int custom_random(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void config_custom_alarm (void)
{
    ualarm(RF_RECEIVE_TIME_INTERVAL, 0);
}

void custom_alarm_handler (int signal_number)
{
    config_custom_alarm();
    receive_rf_signal();
}

void init_custom_alarm (void)
{
    signal(SIGALRM, custom_alarm_handler);
    config_custom_alarm();
}

int main() {
    init_random();
    init_custom_alarm();

    for (;;)
    {
        if (is_all_rf_channel_set() == EVERY_RF_CHANNEL_SET)
        {
            print_rf_channel_data();

            rf_data_handle();
        }
    }

    return 0;
}
