#include <stdio.h>

#define MAX 6

unsigned int arr[MAX] = { 1, 2, 3, 4, 5 };
//unsigned int other_arr[MAX];

void print_arr_info(unsigned int *arr){
	int i;

	for (i = 0; i < MAX; i++)
	{
		printf("arr[%d] = %d\n",i, arr[i]);
	}
}

void can_I_execute_asm (void)
{
	register unsigned int r1 asm("r1") = 0;
	register unsigned int r2 asm("r2") = 0;
	register unsigned int r3 asm("r3") = 0;
	register unsigned int r4 asm("r4") = 0;
	register unsigned int *r5 asm("r5") = 0;

	r5 = arr;

	asm volatile("mov r1, #3");
	asm volatile("mov r2, r1, lsl #2");
	asm volatile("mov r4, #2");
	asm volatile("add r3, r1, r2, lsl r4");
	asm volatile("stmia r5, {r1, r2, r3}");
	print_arr_info(arr);
}

void yes_you_can_execute_asm (void)
{
	register unsigned int r0 asm ("r0") = 0;
	register unsigned int *r1 asm ("r1") = NULL;

	r1 = arr;
	
	asm volatile("mov r2, #0x0");
	asm volatile("ldr r0, [r1, r2]");

	printf("r0 = %u\n", r0);
}

int main(void){
	can_I_execute_asm();
	yes_you_can_execute_asm();
	return 0;
}
