#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX			10
#define BIT_ALIGN	32

int main(void)
{
	int i, num;

	srand(time(NULL));

	for (i = 0; i < MAX; i++)
	{
		// 501 ~ 1000
		num = rand() % 500 + 501;
		// AND NOT
		printf("정렬전 결과 = %d, bit 정렬 결과 = %d\n", num, num & ~(BIT_ALIGN - 1));
	}

	return 0;
}
