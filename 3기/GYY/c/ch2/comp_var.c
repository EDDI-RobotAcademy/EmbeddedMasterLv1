#include <stdio.h>

int main(void){

	int a=0;
	int b=0;

	printf("1~100 사이의 정수만 입력하시오.\n");
	printf("a의 값을 입력하시오 : \n");
	scanf("%d", &a);	
	printf("b의 값을 입력하시오 : \n");
	scanf("%d", &b);

	if(a>b)
	{
		printf("%d > %d, a가 b보다 더 큰 수 입니다.\n", a, b);
	}
	else if(a=b)
	{

		printf("%d = %d, a가 b의 값이 동일 합니다.\n", a, b);
	}
	else if(b>a)
	{
	
		printf("%d > %d, b가 a보다 더 큰 수 입니다.\n", b, a);
	}
	return 0;
}



