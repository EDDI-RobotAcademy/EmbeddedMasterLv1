// x & ~(2의 y승 - 1)의 의미에 대해 서술하시오.
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST_MIN_NUM		17
#define TEST_MAX_NUM		189

#define MAGIC				((1 << 4) - 1)

int custom_random (int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int main (void)
{
	srand(time(NULL));

	int number = custom_random(TEST_MIN_NUM, TEST_MAX_NUM);

	printf("result = %d\n", number & ~(MAGIC));

	return 0;
}
