#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

#define max  10
#define min  1


int Num_input()
{
    return rand() % (max - min + 1) + min;
}


// 동적 할당으로 숫자 30개 메모리에 넣고 출력하고 메모리 해제하기 

int main()
{
    srand(time(NULL));

    int i = 0;

    int *p = (int *)malloc(sizeof(i*30));

    for (; i<30 ; i++)
    {   
        int num = Num_input();
        *(p+i) = num;
        printf("num = %d\n", *(p+i));
    }

    free(p);
}