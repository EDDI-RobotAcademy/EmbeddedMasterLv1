#include <stdio.h>

int main (void)
{
	// 배열의 선언 방법
	// 1. 데이터 타입 작성(int, float, double 등등)
	// 2. 변수 선언하듯이 이름 작성
	// 3. 대괄호 열고 몇 개를 만들지 숫자를 작성
	// 4. 필요하다면 { } 중괄호 내부에 배치할 값들을 작성
	int array[5] = { 1, 2, 3, 4 };
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}

	return 0;
}
