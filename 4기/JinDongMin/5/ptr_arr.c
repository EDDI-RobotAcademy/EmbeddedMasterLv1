#include <stdio.h>

int main(void)
{
	int num1 = 3, num2 = 7, num3 = 33;
	int* arr_pointer[] = { &num1, &num2, &num3 };
	int i;

	for (i = 0; i < 3; i++)
	{
		// 우선순위: [] > *
		printf("*arr_pointer[%d] = %d\n", i, *arr_pointer[i]);
	}

	return 0;
}
