#include "stdio.h"

#define  MAX	6


unsigned int arr[MAX] = {1, 2, 3, 4, 5};
//unsinged int other_err[MAX];

void print_arr_info(unsigned int *arr)
{
	int i = 0;

	for(i = 0; i < MAX; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

void can_I_execute_asm (void)
{
	unsigned int var1 = 0;
	unsigned int var2 = 0;
	unsigned int var3 = 0;
	unsigned int var4 = 0;
	unsigned int *var5 = NULL;

	var5 = arr;
	
	var1 = 3;
	var2 = var1 << 2;
	var4 = 2;
	var3 = var1 + (var2 << var4);
	*(var5) = var1;
	*(var5 + 1) = var2;
	*(var5 + 2) = var3;

	print_arr_info(arr);
}

void yes_you_can_execute_asm (void)
{
	unsigned int var0 = 0;
	unsigned int *var1 = NULL;

	var1 = arr;

	var0 = *(var1 + 2);

	printf("var0 = %u\n", var0);
}

int main (void)
{
	can_I_execute_asm();
	yes_you_can_execute_asm();
	
	return 0;
}
