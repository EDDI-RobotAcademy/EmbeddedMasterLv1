#include <stdio.h>
#include <stdlib.h>

#include "common/util/custom_random.h"
#include "common/util/custom_alarm.h"
#include "entity/receive/rf_receive.h"



int main (void)
{
    printf("program strat!!\n");
    rf_ch_init();

    custom_random_init();
    init_custom_alarm();
    
    while(1)
    {
        //printf_rf_signal();
    }
    return 0;
}