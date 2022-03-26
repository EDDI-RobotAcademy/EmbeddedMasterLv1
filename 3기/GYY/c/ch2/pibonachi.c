#include <stdio.h>

int main(void)
{
	int n_0=0, n_1=1;
	int a, temp, i;

	printf("피보나치 수열의 몇 번째 열까지 출력할까요?\n");
	scanf("%d", &a);

	printf("피보나치 수열의 %d번째 열까지 출력하겠습니다.\n", a);

	for(i=0;i<a;i++)
	{
		printf("\t%7d", n_1);
		temp=n_1;
		n_1=n_1+n_0;
		n_0=temp;
		
		if((i+1)%5==0)
		{
			printf("\n");
		}
	}
	return 0;
}
