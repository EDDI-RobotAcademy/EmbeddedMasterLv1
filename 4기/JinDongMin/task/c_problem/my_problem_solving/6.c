#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 생성할 숫자 개수
#define NUMBER  30

int get_random_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main(void)
{
    int i;
    int random_int_array[NUMBER] = { 0 };
    
    srand(time(NULL));

    for (i = 0; i < NUMBER; i++)
    {
        random_int_array[i] = get_random_int(1, 10);
    }

    for (i = 0; i < NUMBER; i++)
    {
        printf("random_int_array[%d] = %d\n", i, random_int_array[i]);
    }

    return 0;
}