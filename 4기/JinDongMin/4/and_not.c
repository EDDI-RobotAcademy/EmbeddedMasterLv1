#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAGIC	16

int main(void)
{
	int i, data;

	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		data = rand() % 4096 + 4096; // 범위는 [4096, 8191]

		printf("data = %d, data & ~(MAGIC - 1) = %d\n", data, data & ~(MAGIC - 1));
	}

	return 0;
}
