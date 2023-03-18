#include <stdio.h>

int (* arr_return_test(void))[2]
{
	static int arr[2][2] =
	{
		{ 1, 2 },
		{ 3, 4 }
	};

	return arr;
}

int main (void)
{
	int (*p)[2] = arr_return_test();
	int i;

	for (i = 0; i < 2; i++)
	{
		printf("*p[%d] = %d\n", i, *p[i]);
	}

	return 0;
}
