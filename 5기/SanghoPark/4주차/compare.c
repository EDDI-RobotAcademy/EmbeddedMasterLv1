#include "stdio.h"

int main ()
{
	int num = 10;

	for(int count = 0; count < num; count++)
	{
		if(count % 2 == 1)
			printf("%d", count);
		else
			printf(" ");
	}

	return 0;
}
