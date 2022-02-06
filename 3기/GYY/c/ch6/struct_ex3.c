#include <stdio.h>
#include <stdlib.h>

typedef struct array_list list;

struct array_list
{
	int data;
	struct array_list *link;
};

void print_list_struct(list target)
{
	printf("target.data = %d\n", target.data);
	printf("target.link = %d\n", target.link);

	if(target.link != NULL)
	{
		printf("target.link->data = %d\n", target.link->data);
		// 여기서 test1에 link 에는 test2의 주소값이,
		// test2에 link 에는 test1의 주소값이 들어가 있으므로
		// 주소값을 통해 구조체 내부에 data에 접근한다.
	}
}

// 되는 이유
// test1, test2의 주소값을 받아 접근한다.
// set_both_link 함수는 struct 타입 변수의 주소값을 저장하는 매개변수를 입력 받는다.
// 여기서 target1, target2는 그냥 주소값을 갖고있는 변수 한 칸이다.
// 그 안에 구조체 내부로 접근하는 경우엔 '->' 사용 
// 이로써 main 함수의 구조체 test1, test2 
// 주소로 직접 접근하여 데이터를 바꿀 수 있었다.

void set_both_link(list *target1, list *target2)
{
	// 포인터 변수를 통해 구조체 내부에 접근하는 경우엔 '->' 연산자를 사용합니다.
	target1->link = target2;
	target2->link = target1;
}

int main(void)
{
	// 1.
	struct array_list test1 = { 3, NULL };
	// 2.	
	list test2 = { 7, NULL };

	set_both_link(&test1, &test2);

	print_list_struct(test1);
	print_list_struct(test2);

	return 0;
}


