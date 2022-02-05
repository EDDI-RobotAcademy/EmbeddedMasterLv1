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

// 이 부분은 잘못 만들어진 부분입니다!
// 요런 실수를 하면 안되니 예로 남겨두겠습니다.
void set_both_link (list target1, list target2)
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
