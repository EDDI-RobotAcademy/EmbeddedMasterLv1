#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>

#include "custom_alarm.h"
#include "../../entity/receive/rf_receive.h"
#include "../../domain_service/dto/dto.h"
/*
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
*/
void timer_handler (int signum)
{
    static int count = 0;
    //printf("timer expired %d timers\n", ++count);
    receive_rf_signal();

    printf_rf_signal();
    servo_data_trans_object(RF, CHANNEL1);
    dc_motor_data_trans_object(RF, CHANNEL2, rf_receive_object_data->dc_motor_sub_order);
    led_data_trans_object(RF,CHANNEL3);
    
}

void timer_init (void)
{
    struct sigaction sa;
    struct itimerval timer;

    /* Install timer_handler as the signal handler for SIGVTALRM. */
    memset (&sa, 0, sizeof (sa));
    sa.sa_handler = &timer_handler;
    sigaction (SIGVTALRM, &sa, NULL);

    /* Configure the timer to expire after 250 msec... */
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 250000;

    /* ... and every 250 msec after that. */
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 250000;

    /* Start a virtual timer. It counts down whenever this process is executing. */
    setitimer (ITIMER_VIRTUAL, &timer, NULL);
}