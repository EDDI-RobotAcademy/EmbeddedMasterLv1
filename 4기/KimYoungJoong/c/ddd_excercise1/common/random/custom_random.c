

#include <stdio.h>
#include <time.h>

#include "custom_random.h"

void init_random_generator(void)
{
    srand(time(NULL));
    
}
int random_generator_data(void)
{
    return rand() % (RF_DATA_MAX - RF_DATA_MIN + 1 ) + RF_DATA_MIN;
}