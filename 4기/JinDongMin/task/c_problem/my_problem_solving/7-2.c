#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// 생성할 숫자 개수
#define NUMBER  10

int get_random_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

bool check_number_in_array(int *arr, int arr_len, int num)
{
    int i;
    
    for (i = 0; i < arr_len; i++)
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    
    return false;
}

int main(void)
{
    int i;
    int random_int_array[NUMBER] = { 0 };

    srand(time(NULL));

    for (i = 0; i < NUMBER; i++)
    {
        int tmp;
        while (1)
        {
            tmp = get_random_int(1, 10);

            if (!check_number_in_array(random_int_array, i, tmp))
            {
                break;
            }
        }

        random_int_array[i] = tmp;
    }

    for (i = 0; i < NUMBER; i++)
    {
        printf("random_int_array[%d] = %d\n", i, random_int_array[i]);
    }
    
    return 0;
}