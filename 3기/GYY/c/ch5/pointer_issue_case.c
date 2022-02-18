#include <stdio.h>

void i_wanna_get_double_pointer(int **dp)
{
	//전달된 메모리는 단일 포인터인
	//(int *) p의 메모리 주소값이므로
	//(int **) 형식을 취한 것임
	//
	//한마디로 &를 사용하면
	//이것을 상쇄하는 녀석이 *이라는 것을 볼 수 있음
	printf("이렇게 이중 포인터로 처리하는 방법도 존재함 !\n");

	**dp=7;
}
//어떤 case 에 적용하냐
//가운데 값 즉 p를 바꾸지 않고 
//num을 바꾸고자 할 때 사용함


int main(void)
{
	int num=4;
	int *p = &num;
	
	printf("num = %d\n", num);	
	//현재 p의 데이터타입은 int * 이다.
	//이 상태에서 p의 주소값(메모리 값)을 전달함
	i_wanna_get_double_pointer(&p);
	printf("num = %d\n", num);

	return 0;
}
