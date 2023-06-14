#include <stdio.h>
//vi에서 입력시 'a','i'입력
//저장시 esc 입력후 :wq, 저장안할시 :qa!(강제종료) 
// 저장 안할실 :q 
//
//컴파일 하고싶은경우 "gcc file_name.c" 
//이후 ls입력 하면 a.out 파일 확인가능
//"./a.o"으로 실행 할수 있음
// :w 파일명 (다른이름으로 저장)
//"./"는 현재 위치에 있는 것을 의미
// 실행 파일명을 변경하기 위해서 "gcc -o 실행파일명소스코드"
int main(void)
{
	int variable=3; 
	printf("variable is %d\n",variable);
	return 0;
}

