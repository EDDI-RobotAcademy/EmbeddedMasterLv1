#include <stdio.h>

int sum(int x, int y);

int main(void)
{
	int a=2;
	int b=3;
	int i;
	i = sum(a,b);
	printf("sum의 값은 : %d\n", i);
	return 0;
}

int sum(int x, int y)
{
	return x+y;
}

