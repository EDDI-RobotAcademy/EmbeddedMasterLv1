#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "custom_random.h"

void custom_random_init(void)
{
    srand(time(NULL));
}

int custom_random_generator(int MAX, int MIN)
{
    return rand() % (MAX - MIN + 1) + MIN;
}