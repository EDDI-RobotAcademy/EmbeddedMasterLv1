#include <stdio.h>

#define MAX			6

unsigned int arr[MAX] = { 1, 2, 3, 4, 5 };
unsigned int other_arr[MAX];

void print_arr_info(unsigned int *arr)
{
	int i;

	for (i = 0; i < MAX; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

void can_I_execute_asm (void)
{
	/*
	register unsigned int x1 asm("x1") = 0;
	register unsigned int x2 asm("x2") = 0;
	register unsigned int x3 asm("x3") = 0;
	register unsigned int x4 asm("x4") = 0;
	register unsigned int *x5 asm("x5") = 0;

	x5 = arr; */

	register unsigned int *x8 asm("x8") = 0;
	x8 = arr;

	asm volatile("mov w1, #0x3");

	//asm volatile ("mov w2, w1, lsl #2");
	asm volatile("lsl w2, w1, #0x2");
	asm volatile("mov w4, #0x2");

	//asm volatile ("add w3, w1, w2, lsl w4")
    asm volatile("lsl w3, w2, w4");
    asm volatile("add w3, w3, w1");

	//asm volatile ("stmia w5, {w1, w2, w3}");
	asm volatile("str w1, [x8]");
    asm volatile("str x2, [x8, #0x4]");
    asm volatile("str w3, [x8, #0x8]");

	print_arr_info(arr);
}

void yes_you_can_execute_asm (void)
{
    register unsigned int w0 asm ("w0") = 0;
    register unsigned int *x8 asm ("x8") = NULL;

    x8 = arr;

    asm volatile("mov w2, #0x8");

    //asm volatile("ldr x0, [x1, x2]");
    asm volatile("add x4, x8, x2");
    asm volatile("ldur w0, [x4]");
    asm volatile("stur w0, [x29, #-0x4]");

    printf("w0 = %u\n", w0);
}

int main (void)
{
	can_I_execute_asm();
	yes_you_can_execute_asm();

	return 0;
}
