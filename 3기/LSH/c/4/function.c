#include <stdio.h>

// 함수를 방법

// 1. 리턴(반환)타입을 작성한다.
// 2. 함수의 이름을 작성한다.
// 3. 소괄호에 입력(파라메터)을 작성한다.
// 4. 중괄호 내부에 이 함수가 할 일을 작성한다.

int test_func(int num)
{
	return num * 2;
}

int main (void)
{
	int num = 3;
	int result = test_func(num);

	printf("result = %d\n", result);

	return 0;
}
