// Overflow와 Underflow는 어떤 경우에 나는지 기술하시오.
#include <stdio.h>

int main (void)
{
	char overflow = 127;
	char underflow = -128;

	printf("overflow = %d\n", ++overflow);
	printf("underflow = %d\n", --underflow);

	return 0;
}
