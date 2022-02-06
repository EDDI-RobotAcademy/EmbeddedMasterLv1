#include <stdio.h>

int main(void)
{
	//포인터란 ?
	//엄밀하게 포인터 변수란 ?
	//변수 <<<--- 특정 데이터 타입을 저장할 수 있는 메모리 공간
	//포인터 == 주소
	//포인터 변수는 ?
	//특정 데이터 타입의 주소를 저장할 수 있는 메모리 공간
	
	int num_arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int *p_arr = NULL;
	int i;
	int len = sizeof(num_arr) / sizeof(int);
	//포인터가 배열을 받을 수 있을까 ?
	//배열의 이름은 ? 배열의 시작 주소
	p_arr = num_arr;

	for(i=0;i<len;i++)
	{
		//현재 p_arr는 배열의 시작 주소를 저장했음
		//여기서 p_arr[0]은 결국 num_arr[0]과 같은 값을 가짐
		//다음으로 p_arr[1]은 역시 num_arr[1]과 같은 값을 가지므로
		//배열의 주소를 저장한 포인터를 활용하여 배열을 제어할 수 있음
		printf("p_arr[%d] = %d\n", i, p_arr[i]);
	}
	return 0;
}
