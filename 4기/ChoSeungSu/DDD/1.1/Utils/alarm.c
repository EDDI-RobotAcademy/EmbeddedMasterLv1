#include <time.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include "random.h"


void timer_handler(void)
{

}

void timer_init (void)
{
    struct sigaction sa;
    struct itimerspec timer;

    /* set up signal handler*/
    memset (&sa, 0 , sizeoof (sa));
    sa.sa_sigaction = timer_handler;
    sigaction(SIGVTALRM, &sa, NULL);

    /* keep going */

}