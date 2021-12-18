#include <stdio.h>

int main(void)
{
	int num = 3;

	// num % 2는 num을 2로 나눈 나머지
	// if ()의 동작 조건은 ?
	// 참이면 중괄호 내부를 실행
	// 거짓이면 제끼거나 else를 실행
	// C의 경우 0은 거짓, 0이 아니면 참(음수도 참이됨)
	if (num % 2)
	{
		printf("홀수\n");
	}
	else
	{
		printf("짝수\n");
	}

	return 0;
}
