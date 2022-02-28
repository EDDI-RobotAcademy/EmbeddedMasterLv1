#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _employee emp;

struct _employee
{
	char name[32];
	int pay;
};

char name[5][32] = { "이경수", "박지완", "강지훈", "김지환", "조민현" };

emp *init_employee(void)
{
	int i;

	emp *tmp = (emp *)malloc(sizeof(emp) * 5);

	for (i = 0; i < 5; i++)
	{
		strcpy(tmp[i].name, name[i]);
		tmp[i].pay = rand() % 501 + 3000;
	}

	return tmp;
}

void print_employee(emp *e)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("name = %s, pay = %d\n", e[i].name, e[i].pay);
	}
}

void years_ago(emp *e, int year)
{
	int i, j;

	for (i = 0; i < year; i++)
	{
		printf("%d 년차\n", i + 1);

		for (j = 0; j < 5; j++)
		{
			e[j].pay = e[j].pay + e[j].pay * (((rand() % 10) + 1) / 100.0);
		}

		print_employee(e);
	}
}

emp find_max(emp *e)
{
	int i, max_idx, max = 0;

	for (i = 0; i < 5; i++)
	{
		if (max < e[i].pay)
		{
			max = e[i].pay;
			max_idx = i;
		}
	}

	return e[max_idx];
}

int main(void)
{
	emp max;

	srand(time(NULL));

	emp *e = init_employee();

	print_employee(e);

	years_ago(e, 10);

	max = find_max(e);
	printf("10년후 가장 연봉이 높은 사원은 %s, %d\n", max.name, max.pay);

	return 0;
}
