// 실수와 정수를 입력받고 그 값을 함수의 인자로 넘겨 두 수의 곱을 실수형으로 반환하여 출력하라
#include <stdio.h>

#define INTEGER_NUM			3
#define FLOAT_NUM			3.7f

float multiply_float_and_integer(int integer_num, float float_num)
{
	return integer_num * float_num;
}

int main (void)
{
	printf("result = %f\n", multiply_float_and_integer(INTEGER_NUM, FLOAT_NUM));
	return 0;
}
