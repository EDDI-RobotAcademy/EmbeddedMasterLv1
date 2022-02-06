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
	list *tmp = &test1;

	set_both_link(&test1, &test2);

	print_list_struct(test1);
	print_list_struct(test2);

	while(tmp && cnt++ < 10)
	{
		printf("data = %d\n", tmp->data);
		tmp = tmp->link;
	}
	return 0;
}


