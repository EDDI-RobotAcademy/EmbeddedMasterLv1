#include <stdio.h>

int test_func(int num)
{
	return num * 2;
}

int main(void)
{
	int num = 3;
	int result = test_func(num);

	printf("result = %d\n", result);

	return 0;
}
