#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX		10
#define MIN		1

int main(void)
{
	int i = 0;
	int rand_num;

	srand(time(NULL));

	// 1500 ~ 2000 / 100 -> 15 ~ 20
	// case 15, 16, 17, 18, 19, blablabla break;

	for ( ; i < 10; i++)
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
