#include <stdio.h>

void print_test (void)
{
	printf("Hello Test\n");
}

int main (void)
{
	void (*p)(void) = print_test;
	p();
	
	return 0;
}
