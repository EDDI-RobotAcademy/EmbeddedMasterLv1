#include "custom_random_int.h"

void initialize_random(void)
{
    srand(time(NULL));
}

int generate_random_int_within_specific_range(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}