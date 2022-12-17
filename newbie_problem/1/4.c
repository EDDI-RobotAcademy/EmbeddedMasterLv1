// float과 double 자료형의 저장 방식에 대해서 서술하시오.
// 이론적으로만 본다면 아래 링크 참고
// https://www.miltonmarketing.com/coding/programming-concepts/floating-point-number-representation/
#include <stdio.h>

#define FLOAT_DATA		8.0f
#define DOUBLE_DATA		1.5

#define BYTE_BIT		8

void analysis_float_number (float float_number)
{
	int i, j;
	char *byte_look = &float_number;

	for (i = sizeof(float) - 1; i >= 0; i--)
	{
		for (j = BYTE_BIT - 1; j >= 0; j--)
		{
			printf("%d", byte_look[i] >> j & 1);

			if (j == BYTE_BIT - 1 && i == sizeof(float) - 1)
			{
				printf(" ");
			}

			if (j == BYTE_BIT - 1 && i == sizeof(float) - 2)
			{
				printf(" ");
			}
		}
	}
	printf("\n");
}

void analysis_double_number (double double_number)
{
	int i, j;
	char *byte_look = &double_number;

	for (i = sizeof(double) - 1; i >= 0; i--)
	{
		for (j = BYTE_BIT - 1; j >= 0; j--)
		{
			printf("%d", byte_look[i] >> j & 1);

			if (j == BYTE_BIT - 1 && i == sizeof(double) - 1)
			{
				printf(" ");
			}

			if (j == BYTE_BIT - 4 && i == sizeof(double) - 2)
			{
				printf(" ");
			}
		}
	}
	printf("\n");
}



int main (void)
{
	float float_num = FLOAT_DATA;
	double double_num = DOUBLE_DATA;

	analysis_float_number(float_num);
	analysis_double_number(double_num);

	return 0;
}
