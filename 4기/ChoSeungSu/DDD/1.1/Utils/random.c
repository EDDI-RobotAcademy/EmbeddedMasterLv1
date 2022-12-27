#include <stdlib.h>
#include <time.h>

void random_init(void)
{
    srand(time(NULL));
}

int custom_random_make(int max, int min)
{
    return rand() % (max - min + 1) + min;  // min ~ max make random  
}