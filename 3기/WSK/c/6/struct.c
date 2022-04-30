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
}

int main(void)
{
	// 1.
	struct array_list test1 = { 3, NULL };
	// 2.
	list test2 = { 7, NULL };

	print_list_struct(test1);
	print_list_struct(test2);
	
	return 0;
}
