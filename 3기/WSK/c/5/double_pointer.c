#include <stdio.h>

void i_wanna_get_double_pointer (int **dp)
{
	printf("이렇게 이중 포인터로 처리하는 방법도 존재함!\n");

	**dp = 7;
}

int main(void)
{
	int num = 3;
	int *p = &num;

	printf("num = %d\n", num);
	
	i_wanna_get_double_pointer(&p);

	printf("num = %d\n", num);

	return 0;
}
