// 실수 하나를 입력받아 소수점만 분리하고
// 또 정수 부분만 분리하는 함수를 작성하시오
// (함수 총 2개를 작성하면됨)
#include <stdio.h>

#define REAL_NUMBER		7.333

int separate_integer_number (double real_number)
{
	return real_number;
}

double separate_decimal_point (double real_number)
{
	return real_number - (int)real_number;
}

int main (void)
{
	printf("%d\n", separate_integer_number(REAL_NUMBER));
	printf("%.3lf\n", separate_decimal_point(REAL_NUMBER));

	return 0;
}
