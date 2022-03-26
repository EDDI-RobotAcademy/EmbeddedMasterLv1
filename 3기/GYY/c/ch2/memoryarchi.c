#include <stdio.h>
#include <stdlib.h>

const int constval = 30;	//상수

int uninitial;	//초기화되지 않는 전역변수
int initial = 30;	//초기화된 전역변수

static int staticval = 70;	//정적변수

int function(){
	return 0;
}

int main(void){
	int localval1 = 30;	//지역변수 1
	int localval2 = 20;	//지역변수 2

	printf(" 상수 Memory Address : \t\t %p \n", &constval);
	printf(" 비초기화 변수 Memory Address :\t %p \n", &uninitial);
	printf(" 초기화 변수 Memory Address : \t %p \n", &initial);
	printf(" 정적 변수 Memory Address : \t %p \n", &staticval);
	printf(" 함수 Memory Address : \t\t %p \n", &function);
	printf(" 지역변수1 Memory Address : \t %p \n", &localval1);
	printf(" 지역변수2 Memory Address : \t %p \n", &localval2);

	return 0;
}// 실행 후, 각 변수가 메모리에 할당되는 주소(위치)의 차이를 확인할 수 있음
