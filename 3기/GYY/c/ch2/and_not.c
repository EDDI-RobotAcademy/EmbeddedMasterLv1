#include <stdio.h>
//비트 정렬 
#include <time.h>
#include <stdlib.h>
#define MAX	10
#define BIT_ALIGN	32
int main(void)
{
	int num;
	int i;
	srand(time(NULL));

	for (i=0;i<MAX;i++)
	{
		num=rand()%500+501;//501~1000
		//AND NOT
		printf("bit 정렬전 결과 = %d, bit 정렬 결과 = %d\n", num, num&~(BIT_ALIGN-1));
	}


	return 0;
}
