#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX			10

int rand_arr[MAX];

bool dup_check(int num)
{
	int i;

	for (i = 0; i < num; i++)
	{
		if (rand_arr[i] == rand_arr[num])
		{
			return true;
		}
	}

	return false;
}

void init_rand_num(void)
{
	int i;

	for (i = 0; i < MAX; i++)
	{
redo:
		rand_arr[i] = rand() % 10 + 1;

		if (dup_check(i))
		{
			goto redo;
		}
	}
}

void print_rand_arr(void)
{
	int i;

	for (i = 0; i < MAX; i++)
	{
		printf("rand_arr[%d] = %d\n", i, rand_arr[i]);
	}
}

int main(void)
{
	srand(time(NULL));

	init_rand_num();

	print_rand_arr();

	return 0;
}
