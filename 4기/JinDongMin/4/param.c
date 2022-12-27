#include <stdio.h>

// 매개변수 4개
int func(int num1, int num2, int num3, int num4)
{
	return num1 + num2 + num3 + num4;
}

// 매개변수 9개
int func2(int num1, int num2, int num3, int num4, int num5, int num6, int num7, int num8, int num9)
{
	return num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8 + num9;
}

int main(void)
{
	// 총 int형 변수 10개
	int num = 2, num2 = 3, num3 = 4, num4 = 5, num5 = 6;
	int num6 = 7, num7 = 8, num8 = 9, num9 = 10, res;

	res = func(num, num2, num3, num4);
	printf("res = %d\n", res); // 14

	res = func2(num, num2, num3, num4, num5, num6, num7, num8, num9);
	printf("res = %d\n", res); // 54

	return 0;
}
