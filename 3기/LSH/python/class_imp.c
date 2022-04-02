#include <stdio.h>
#include <stdlib.h>

typedef struct _person person;
typedef struct _person_method_table person_method_table;

struct _person
{
	int age;
	char *name;

	person_method_table *tbl;
};

struct _person_method_table
{
	void (* test) (void);
};

void print_person (void)
{
	printf("Hello, I'm Person\n");
}

person *init_person(void)
{
	person *tmp;

	tmp = (person *)malloc(sizeof(person));
	tmp->tbl = (person_method_table *)malloc(sizeof(person_method_table));
	tmp->tbl->test = print_person;

	return tmp;
}

int main (void)
{
	person *p = init_person();
	p->tbl->test();

	return 0;
}
