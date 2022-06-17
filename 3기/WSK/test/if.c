#include <stdio.h>

int main()
{
	int num1 = 1, num2 = 2;

	if(num1 > num2)
		printf("num1이 num2보다 큽니다!\n");
	else if(num1 < num2)
		printf("num2가 num1보다 큽니다!\n");
	else
		printf("num1 과 num2가 같습니다!\n");

	return 0;
}
