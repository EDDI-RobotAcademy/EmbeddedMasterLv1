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
	register unsigned int w1 asm("w1") = 0;
	register unsigned int w2 asm("w2") = 0;
	register unsigned int w3 asm("w3") = 0;
	register unsigned int w4 asm("w4") = 0;
	register unsigned int *w5 asm("w5") = 0;

	w5 = arr;

	asm volatile("mov w1, #3");
	asm volatile("mov w2, w1, lsl #2");
	asm volatile("mov w4, #2");
	asm volatile("add w3, w1, w2, lsl #2");
	asm volatile("str w1, [x5]");
	asm volatile("str w2, [x5, #4]");
	asm volatile("str w3, [x5, #8]");

	print_arr_info(arr);
}

void yes_you_can_execute_asm (void)
{
	register unsigned int w0 asm("w0") = 0;
	register unsigned int *w1 asm("w1") = NULL;

	w1 = arr;

	asm volatile("mov w2, #0x8");
	asm volatile("ldr w0, [x1, x2]");

	printf("w0 = %u\n", w0);
}

int main (void)
{
	can_I_execute_asm();
	yes_you_can_execute_asm();
	
	return 0;
}
