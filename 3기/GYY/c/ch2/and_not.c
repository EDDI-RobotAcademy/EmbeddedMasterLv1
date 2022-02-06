#include <stdio.h>
//비트 정렬 
#include <time.h>	//time()함수 포함 라이브러리
#include <stdlib.h>	//rand()함수 포함 라이브러리
#define MAX	10
#define BIT_ALIGN	32
int main(void)
{
	int num;
	int i;
	srand(time(NULL));	//매번 다른 시드값 생성

	for (i=0;i<MAX;i++)
	{
		num=rand()%500+501;//501~1000 
		//rand()%a+b	b ~ (a-1)+b 사이의 난수를 생성
	
		printf("bit 정렬전 결과 = %d, bit 정렬 결과 = %d\n", num, num&~(BIT_ALIGN-1));
	}
	return 0;
}

