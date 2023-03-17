#include <stdio.h>

void foo(void)
{
    int *ptr = NULL;
    *ptr = 7;
}

int main(void)
{
    foo();

    return 0;
}