#include <stdio.h>

int mult2(int num)
{
	// shift 연산자(오른쪽 쉬프트는 무조건 2^n을 곱하는 효과가 있음
	// 현재 << 1이므로 2^1을 곱하는 것과 같은 역할임.
	return num << 1;
}

int main(void)
{
	int data = 3;
	int result = mult2(data);
	printf("result = %d\n", result);

	return 0;
}
