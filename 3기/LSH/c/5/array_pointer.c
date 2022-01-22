#include <stdio.h>

int main(void)
{
	int i, j;
	int double_arr[4][2] = {
		{ 1, 3 }, { 4, 5 },
		{ 6, 7 }, { 8, 9 }
	};

	int *p2[3];		// 포인터 배열
	int (*p)[3];	// 배열 포인터
	// (int[3] *) p <<<--- 실제로 이와 같은 형태를 가짐

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("double_arr[%d][%d] = %d\n", i, j, double_arr[i][j]);
		}
	}

	p = double_arr;

	printf("p[0] = %d\n", *p[0]);
	printf("p[1] = %d\n", *p[1]);
	printf("p[2] = %d\n", *p[2]);

	return 0;
}
