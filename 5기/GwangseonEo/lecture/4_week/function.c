#include <stdio.h>

int multiply_two (int num)
{
	return num * 2;
}

int main(void)
{
	int num = 3;
	int result = multiply_two(num);
	printf("result = %d\n", result);
	return 0;
}
