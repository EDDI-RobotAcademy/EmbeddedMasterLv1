#include <stdio.h>

int main(void)
{
	int num = 3;
	int *p = &num;

	*p = 7;

	printf("num = %d\n", num);
	printf("*p = %d\n", *p);

	return 0;
}
