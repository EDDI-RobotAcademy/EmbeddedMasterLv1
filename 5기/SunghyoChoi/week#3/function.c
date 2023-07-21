#include <stdio.h>

int multiply_two(int num)
{
	return 2*num;
}
	
int main(void)
{
	int num=3;
	int result=multiply_two(num);
	printf("result is %d\n",result);
	return 0;
}
