#include <stdio.h>

int main(void){
	
	int num;
	printf("정수를 입력하시오\n");
	scanf("%d", &num);

	printf("10진수 출력 : %d\n", num);
	printf(" 8진수 출력 : %#o\n", num);
	printf("16진수 출력 : %#x\n", num);

	return 0;
}

