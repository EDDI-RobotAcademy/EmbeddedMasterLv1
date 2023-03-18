#include <stdio.h>

int main(void)
{
	// 아래와 같이 타입이 같은 변수는
	// ','를 통해 변수 이름만 구분하여 작성이 가능합니다.
	int num1 = 3, num2 = 7;
	int result;

	result = num1 + num2;
	printf("%d + %d = %d\n", num1, num2, num1 + num2);

	// 한 줄 복사: yy (커맨드 모드에서 사용해야함)
	result = num1 - num2;
	printf("%d - %d = %d\n", num1, num2, num1 - num2);
	
	result = num1 * num2;
	printf("%d * %d = %d\n", num1, num2, num1 * num2);

	result = num1 / num2;
	printf("%d / %d = %d\n", num1, num2, num1 / num2);

	result = num1 % num2;
	printf("%d %c %d = %d\n", num1, 0x25, num2, num1 % num2);

	return 0;
}
