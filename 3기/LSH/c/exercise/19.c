#include <math.h>
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

typedef struct _statistics stat;

struct _statistics
{
	float mean;
	float std_dev;
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

float calc_mean(emp *e, int num)
{
	int i;
	float sum = 0;

	for (i = 0; i < num; i++)
	{
		sum += e[i].pay;
	}

	return sum / (float)num;
}

float calc_std_dev(emp *e, int num, float mean)
{
	int i;
	float sum = 0;

	for (i = 0; i < num; i++)
	{
		sum += pow((e[i].pay - mean), 2);
	}

	return sum / num;
}

void record_statistics(emp *e, int idx, stat *s)
{
	int i;
	float mean = calc_mean(e, 5);

	s[idx].mean = mean;
	s[idx].std_dev = sqrt(calc_std_dev(e, 5, mean));
}

void print_statistics(stat *s, int idx)
{
	printf("평균 = %f, 표준편차 = %f\n", s[idx].mean, s[idx].std_dev);
}

void years_ago(emp *e, int year, stat *s)
{
	int i, j;

	for (i = 0; i < year; i++)
	{
		printf("%d 년차\n", i + 1);

		for (j = 0; j < 5; j++)
		{
			e[j].pay = e[j].pay + e[j].pay * (((rand() % 10) + 1) / 100.0);
		}

		record_statistics(e, i, s);

		print_employee(e);
		print_statistics(s, i);
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

stat *init_statistics(void)
{
	stat *tmp = (stat *)malloc(sizeof(stat) * 10);

	return tmp;
}

int main(void)
{
	stat *s;
	emp max;

	srand(time(NULL));

	s = init_statistics();
	emp *e = init_employee();

	print_employee(e);

	years_ago(e, 10, s);

	max = find_max(e);
	printf("10년후 가장 연봉이 높은 사원은 %s, %d\n", max.name, max.pay);

	return 0;
}
