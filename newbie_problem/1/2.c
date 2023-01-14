// 두 개의 정수(num1, num2)를 입력받고 num1 << num2 값을 구하는 함수를 작성하라
// 최종적으로 결과값을 출력하도록 만드시오
#include <stdio.h>

int main (void)
{
	int num1, num2;

	printf("두 개의 숫자를 입력하세요: ");
	scanf("%d %d", &num1, &num2);
	printf("num1 << num2 = %d\n", num1 << num2);

	return 0;
}
