// and, or, xor, not 동작 방식에 대해 기술하고
// 예를 들어서 각각을 연산해보도록 하자!
#include <stdio.h>

int main (void)
{
	int num1 = 5, num2 = 12;

	printf("num1 and num2 = %d\n", num1 & num2);
	printf("num1 or num2 = %d\n", num1 | num2);
	printf("num1 xor num2 = %d\n", num1 ^ num2);

	printf("not num1 = %d\n", ~num1);

	return 0;
}
