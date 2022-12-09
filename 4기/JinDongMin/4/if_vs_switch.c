#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN	1
#define MAX	10

int main(void)
{
	int rand_num, i;

	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		rand_num = rand() % (MAX - MIN + 1) + MIN;
		
		if (rand_num > 5)
		{
			printf("5보다 크다: %d\n", rand_num);
		}
		else if (rand_num > 9)
		{
			printf("9보다 크다: %d\n", rand_num);
		}
		else if (rand_num > 3)
		{
			printf("3보다 크다: %d\n", rand_num);
		}
	}

	return 0;
}
