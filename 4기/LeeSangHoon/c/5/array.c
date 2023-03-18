#include <stdio.h>

int main (void)
{
	int array[5] = { 1, 2, 3, 4, 5};
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}

	return 0;
}
