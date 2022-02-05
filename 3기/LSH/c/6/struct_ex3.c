#include <stdio.h>
#include <stdlib.h>

typedef struct array_list list;

struct array_list
{
	int data;
	struct array_list *link;
};

void print_list_struct (list target)
{
	printf("target.data = %d\n", target.data);
	printf("target.link = %d\n", target.link);

	if (target.link != NULL)
	{
		printf("target.link->data = %d\n", target.link->data);
	}
}

void set_both_link (list *target1, list *target2)
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
