#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include "random.h"

void timer_handler(int signum)
{   
    static int count = 0;
    static int rf_data;

    random_init();
    rf_data = custom_random_make(RANDOM_DATA_MAX, RANDOM_DATA_MIN);
    printf("timer data is %d\n", rf_data);
}

void timer_init(void)
{
    struct sigaction sa;
    struct itimerval timer;

    /* Install timer_handler as the signal handler for SIGVTALRM.*/
    memset (&sa, 0 , sizeof(sa));
    sa.sa_handler = timer_handler;
    sigaction(SIGVTALRM, &sa, NULL);

    /* Configure the timer to expire after 250 msec */
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 250000;

    /* every 250msec after that */
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_sec = 250000;

    /* Start virtual timer. It counts down whenever this process is executing */
    setitimer(ITIMER_VIRTUAL, &timer, NULL);

}