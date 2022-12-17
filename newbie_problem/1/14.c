// 2개를 숫자를 입력 받아서
// 누가 더 큰지 혹은 같은지 판별할 수 있는 프로그램을 작성하시오.
// 제어문을 사용하지 않고 구현하도록함!
// printf는 여러번 사용해도 무방!
#include <stdio.h>

void find_max(int num1, int num2)
{
	if (num1 > num2)
	{
		printf("num1이 더 크다\n");
	}
	else if (num1 < num2)
	{
		printf("num2가 더 크다\n");
	}
	else
	{
		printf("둘은 같다\n");
	}
}

int main (void)
{
	int num1, num2;

	printf("2개의 숫자를 입력하세요: ");
	scanf("%d %d", &num1, &num2);

	find_max(num1, num2);

	return 0;
}
