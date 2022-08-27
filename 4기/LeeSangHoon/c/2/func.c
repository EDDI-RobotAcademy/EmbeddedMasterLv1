#include <stdio.h>

int mult2(int num)
{
	return num << 1;
}

int main(void)
{
	int data = 3;
	int result = mult2(data);
	printf("result = %d\n", result):

	return 0;
}
