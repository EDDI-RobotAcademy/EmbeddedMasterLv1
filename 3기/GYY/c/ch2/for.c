#include <stdio.h>

#define MAX	7

int main(void)
{
	//C 표준의 경우엔 for문 내부에 int i 형식으로 선언이 불가함
	int i;
	//왜 7로 안하고 MAX 적을까 ?
	//유지보수 차원에서 사용하는 것임(향후 확장성을 위함)
	for (i=0;i < MAX; i++)
	{
		printf("%d\n",i);
	}
	return 0;
}
