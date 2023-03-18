#include <stdio.h>

int main(void)
{
	int i;
	int arr[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};

	// 배열 포인터
	int (*p)[4] = arr;

	for (i = 0; i < 3; i++)
	{
		printf("p[%d] = %d\n", i, *p[i]);
	}

	return 0;
}
