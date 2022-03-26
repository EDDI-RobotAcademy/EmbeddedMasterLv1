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
	}
}

// 안되는 이유
// set_both_link 라는 함수 아래 만들어진 
// target1, target2는 
// 원래 함수의 test1, test2와 엄연히 다르다. 
// set_both_link 함수 수행 중, target1과 target2는 
// stack 안에서 만들어지고 다시 사라진다.
// p target1, p target2
// p &target1, p &target2를 수행하며 
// set_both_link 안에서 
// data값이 변경되는 것을 확인할 수 있지만 함수가 종료되면 그 세상은 사라진다. 
// 처음부터 아무일도 없었던 것처럼.

void set_both_link(list target1, list target2)
{
	target1.link = &target2;
	target2.link = &target1;
}

int main(void)
{
	// 1.
	struct array_list test1 = { 3, NULL };
	// 2.	
	list test2 = { 7, NULL };

	set_both_link(test1, test2);

	print_list_struct(test1);
	print_list_struct(test2);

	return 0;
}


