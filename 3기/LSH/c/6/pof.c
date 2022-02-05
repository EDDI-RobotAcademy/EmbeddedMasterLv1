#include <stdio.h>

void print_test (void)
{
	printf("Hello Test\n");
}

int main (void)
{
	// int (*p)[3] vs int *p[3]
	// C 문법 만든 사람들(켄 톰슨, 데니스 리치)이
	// 문법을 만들다보니까 배열 인덱스를 데이터타입 뒤에 배치할 수 없었음
	// 그러다보니 괄호를 치고 배열 인덱스를 넣으면
	// 자동으로 배열을 앞쪽으로 배치하여 처리하는 형식을 가져가게 하였음
	// int (*p)[3] ---> int[3] *p

	// 함수 포인터에서는 조금 더 독특한 규칙이 적용됨
	// 괄호와 파라미터 지정 혹은 인덱스가 만나는 경우면
	// 일단 뒤쪽 닫는 괄호를 풀고 인덱스나 파라미터를 옮기고 그 앞에 다시 괄호를 닫는다.
	void (*p)(void) = print_test;
	// void (*p)(void) ---> void (*)(void) p
	p();
	//print_test();

	return 0;
}
