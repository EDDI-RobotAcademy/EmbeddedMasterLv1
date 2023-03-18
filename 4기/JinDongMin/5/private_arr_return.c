#include <stdio.h>

int (* arr_return_test(void))[2]
{
	static int arr[2][2] = {
		{ 1, 2 },
		{ 3, 4 }
	};

	return arr;
}

int main(void)
{
	int (*p)[2] = arr_return_test();
	int i, j;

	for (i = 0; i < 2; i++)
	{
		printf("*p[%d] = %d\n", i, *p[i]);
	}

	//arr[0][0] = 7;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("p[%d][%d] = %d\n", i, j, p[i][j]);
		}
	}

	return 0;
}
