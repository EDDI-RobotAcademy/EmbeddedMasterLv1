#include <stdio.h>

int main(void)
{
	const int MAX = 7;
	int arr[7] = { 0 };

	for(int i = 0; i < MAX; i++)
	{
		arr[i] = 2 * (i + 1);
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	return 0;
}

