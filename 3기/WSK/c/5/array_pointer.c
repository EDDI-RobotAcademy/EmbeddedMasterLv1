#include <stdio.h>

int main(void)
{
	int i, j;
	int double_arr[4][2] = {
		{ 1, 3 }, { 4, 5 },
		{ 6, 7 }, { 8, 9 }
	};

	int *p[3];
	int (*p)[3];

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("double_arr[%d][%d] = %d\n", i, j, double_arr[i][j]);
		}
	}

	return 0;
}

