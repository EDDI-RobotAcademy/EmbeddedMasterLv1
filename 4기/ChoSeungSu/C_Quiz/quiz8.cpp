#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_num(){
    return rand() % 6;
}

int main()
{
    int dice[6] = {1,2,3,4,5,6};
    
    int i, j;

    int p_num;
    printf("몇번 던질건가요?: \n");
    scanf("%d", &p_num);

    for (j =0 ; j<p_num ; j++)
    {
        int i = rand() % 6;
        printf("dice : %d\n", dice[i]);
    }
}
