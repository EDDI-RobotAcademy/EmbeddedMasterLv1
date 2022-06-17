#include <stdio.h>

int main(void)
{
	int i;
	int num1 = 3, num2 = 7, num3 = 33, num4 = 77, num5 = 333;
	int *p_arr[] = { &num1, &num2, &num3, &num4, &num5 };

	for(i = 0; i < 5; i++)
	{
		printf("p_arr[%d] = %d\n", i, *p_arr[i]);
		printf("p_arr[%d] = 0x%x\n", i, p_arr[i]);
	}

	return 0;
}
