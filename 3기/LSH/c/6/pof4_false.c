#include <stdio.h>

int *wanna_ret_array (void)
{
	int test[4] = { 77, 33, 44 };

	return test;
}

int main (void)
{
	printf("test[0] = %d\n", wanna_ret_array());

	return 0;
}
