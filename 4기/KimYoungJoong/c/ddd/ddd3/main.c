#include <stdio.h>

#include "common/util/custom_random.h"

int main (void)
{
    int random_num = 0;

    custom_random_init();
    for(;;)
    {
        random_num = custom_random_generator(RANDOM_DATA_MAX, RANDOM_DATA_MIN);
        printf("random_num : %d\n", random_num);
    }

    return 0;
}