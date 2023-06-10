#include <stdio.h>

int main(void)
{
	int variable = 10;
	int num = 0;

	for(int i = 0;i < variable;i++)
	{
		printf("%d + ",i);
		num += i;
	}
	
	printf("%d = ",variable);
	num += variable;
	printf("%d\n",num);

	return 0;
}
