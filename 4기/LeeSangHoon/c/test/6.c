#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX			30

int rand_arr[MAX];

void init_rand_num(void)
{
	int i;

	for (i = 0; i < MAX; i++)
	{
		rand_arr[i] = rand() % 10 + 1;
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
