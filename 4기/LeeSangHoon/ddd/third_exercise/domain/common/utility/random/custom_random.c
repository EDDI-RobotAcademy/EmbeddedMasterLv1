#include "custom_random.h"

#include <stdlib.h>
#include <time.h>

void init_random(void)
{
    srand(time(NULL));
}

int custom_random(int min, int max)
{
    return rand() % (max - min + 1) + min;
}