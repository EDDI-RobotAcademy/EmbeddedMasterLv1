#include <stdio.h>

int main(void)
{
	int i = 0, j, a = 0, b = 1, tmp;

	printf("피보나치 수열 개수 지정 : ");
	scanf("%d", &j);

	for(i; i<j; i++)
	{
		printf("%d ", b);
		tmp = b;
		b += a;
		a = tmp;
	}

	printf("\n");

	return 0;
}
		



