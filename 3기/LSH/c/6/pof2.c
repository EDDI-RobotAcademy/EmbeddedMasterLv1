#include <stdio.h>

int ret_int_test (void)
{
	return 3;
}

int main (void)
{
	int (*p)(void) = ret_int_test;
	printf("res = %d\n", p());

	return 0;
}
