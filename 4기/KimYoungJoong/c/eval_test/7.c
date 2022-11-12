/*7. 1 ~ 10 사이의 숫자를 중복되지 않게 10개 생성하시오.  */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN    1
#define MAX    10
#define ARR_SIZE 10

int num[ARR_SIZE] = {0, };


bool check_random_num(int index)
{
    int i;

    for (i = 0; i < index; i++)
    {
        if(num[i] == num[index])
        {
            return true;
        }
    }
    return false;
}

void custom_random(int min, int max)
{
    int i = 0;
    
    for(i; i < MAX; i++)
    {
redo:
        num[i] = rand() % ( max - min +1 ) + 1;
        if(check_random_num(i))
        {
            goto redo;
        
        }
    }

}

void print_rendom_number()
{
    int i = 0;
    for(i; i < MAX; i++)
    {
        printf("num[%d] : %d\n", i, num[i]);
    }
    
}

int main(void)
{
    srand(time(NULL));

    custom_random(MIN, MAX);

    print_rendom_number();


    


    return 0;
}
