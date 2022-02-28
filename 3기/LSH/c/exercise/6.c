#include <stdio.h>

int arr[30] = { 1, 6, 2 };

int find_series(int num)
{
	int i;

	for (i = 3; i < num; i++)
	{
		if (i % 2)
		{
			arr[i] = arr[i - 1] + arr[i - 3];
			printf("홀 ");
		}
		else
		{
			arr[i] = arr[i - 1] - arr[i - 3];
			printf("짝 ");
		}

		printf("검토용 arr[%d] = %d\n", i, arr[i]);
	}

	return arr[num - 1];
}

int main(void)
{
	int res = find_series(20);

	printf("res = %d\n", res);
}
