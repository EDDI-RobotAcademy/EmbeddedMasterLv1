#include <stdio.h>

int main(void)
{
	// 1. 데이터 타입을 작성 (int, char, float, double, int *, char *)
	// 2. 변수명을 작성한다.
	// 3. 필요하다면 초기화를 한다.
	int num = 3;

	// if 문을 작성하는 방법
	// 1. if 를 작성하고 괄호를 열고 닫는다.
	// 2. 중괄호를 열고 닫는다.
	// 3. 괄호 내부에 조건을 작성한다.
	// 4. 조건이 만족된다면 if 에 걸쳐져 있는 중괄호 내부로 진입
	// 5. 만약 조건이 만족되지 않으면 else 파트로 진입
	if (num > 7)
	{
		printf("3 > 7\n");
	}
	else
	{
		printf("3 < 7\n");
	}

	return 0;
}
