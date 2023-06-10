#include <stdio.h>

int main(void)
{
    int num1=5;
    int num2=11;

    printf("5 and 11 =%d\n",num1 & num2);
    printf("5 or 11 =%d\n",num1 | num2);
    printf("not 5 =%b\n",~num1);
    printf("5 xor 11 =%d\n",num1 ^ num2);

    return 0;
}

