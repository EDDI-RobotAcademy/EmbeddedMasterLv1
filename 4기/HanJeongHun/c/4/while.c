#include <stdio.h>

#define MAX			10

int main(void)
{
	int i = 0;
	int a = 2;
	float b = 3.2f;
	double c = 8.8, d = 2.2;

	while (i < MAX)
	{
		printf("i = %d\n", i++);
	}

	return 0;
}
