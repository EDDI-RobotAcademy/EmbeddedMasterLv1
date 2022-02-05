#include <stdio.h>

int ret_int_test (void);
// 위임자
// int (*)(void) arbiter (void)
int (* arbiter (void))(void);

int (* arbiter (void))(void)
{
	printf("조건이 만족되었으므로 이 포인터를 리턴합니다!\n");

	return ret_int_test;
}

// int(*)(void) 
int ret_int_test (void)
{
	return 3;
}

int main (void)
{
	//int (*p)(void) = ret_int_test;
	printf("res = 0x%x\n", arbiter()());
	// arbiter() ===> ret_int_test
	// arbiter()() ===> ret_int_test()
	printf("res = 0x%x\n", arbiter());

	return 0;
}
