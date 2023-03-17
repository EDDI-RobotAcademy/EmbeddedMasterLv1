#include <stdio.h>

#define MAX			10

int main(void)
{
	int i = 0;
	int a = 2;
	float b = 3.2f;
	double c = 8.8, d = 2.2;

	// while 문을 작성하는 방법
	// 1. while을 적고 괄호를 열고 닫고 중괄호를 열고 닫는다.
	// 2. 괄호 내부에 조건을 작성합니다.
	// 3. 어떤 작업을 반복시킬 것인지 중괄호 내부에 작성합니다.
	while (i < MAX)
	{
		printf("i = %d\n", i++);
	}

	return 0;
}
