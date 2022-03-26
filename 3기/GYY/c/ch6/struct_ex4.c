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

void set_both_link(list *target1, list *target2)
{
	target1->link = target2;
	target2->link = target1;
}

int main(void)
{
	int cnt = 0;
	// 1.
	struct array_list test1 = { 3, NULL };
	// 2.	
	list test2 = { 7, NULL };

	set_both_link(&test1, &test2);

	print_list_struct(test1);
	print_list_struct(test2);

	while(test1.link && cnt++ < 10)
	{
		printf("data = %d\n", test1.link->data);
		test1.link = test1.link->link;
	}
	// 처음 한번만 test1.link, 0x200의 data, 즉 7이 출력되고
	// test1.link 안으로 0x200 내부의 link, 즉 0x100이 들어가고
	// 그 다음부터 test1.link, 0x100의 data 즉 3이 출력되고
	// test1.link 안으로 0x100 내부의 link, 즉 0x100이 그대로 들어가 
	// 계속 반복만 됨
	return 0;
}


