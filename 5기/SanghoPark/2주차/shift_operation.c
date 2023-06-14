#include "stdio.h"

int main (void)
{
	int num1 = 5;
	int num2 = 10;

	printf("5 AND 10 = %d \n", num1 & num2);
	printf("5 OR 10 = %d \n", num1 | num2);
	printf("NOT 5 = %d\n", ~num1);
	printf("5 XOR 10 = %d \n", num1 ^ num2);

	return 0;
}
