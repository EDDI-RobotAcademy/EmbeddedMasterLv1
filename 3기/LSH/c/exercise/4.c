#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _member_info member_info;

struct _member_info
{
	int age;
	char name[32];
	char phone[32];
	char city[32];
	char street[128];
	char detail[128];
};

int total_member;

int age[64] = { 10, 11, 12, 15, 16,
				18, 20, 21, 24, 27,
				33, 34, 32, 36, 38, 39 };
char name[64][32] = { "김윤환", "김택용", "이영호", "조기석", "임요환",
					"마주작", "진영수", "염보성", "김명운", "임홍구",
					"박경수", "이영수", "김성환", "이재호", "김창수", "도재욱" };
char phone[64][32] = { "010-1111-1234", "010-1111-1234", "010-1111-1234", "010-1111-1234", "010-1111-1234",
					"010-1111-1234", "010-1111-1234", "010-1111-1234", "010-1111-1234", "010-1111-1234",
					"010-1111-1234", "010-1111-1234", "010-1111-1234", "010-1111-1234", "010-1111-1234", "010-1111-1234" };
char city[64][32] = { "서울", "서울", "서울", "부산", "서울",
				"대전", "대전", "대구", "전주", "대구",
				"전주", "대전", "서울", "서울", "대전", "서울" };
char street[64][128] = { 0 };
char detail[64][128] = { 0 };

member_info *init_member_info(void)
{
	member_info *tmp = (member_info *)malloc(sizeof(member_info) * 64);
}

void input_info(member_info *mi)
{
	bool run = true;
	int num;
	int i;

	for (i = 0; i < 16; i++)
	{
		mi[i].age = age[i];

		strcpy(mi[i].name, name[i]);
		strcpy(mi[i].phone, phone[i]);
		strcpy(mi[i].city, city[i]);
		strcpy(mi[i].street, street[i]);
		strcpy(mi[i].detail, detail[i]);
	}

	total_member = 16;
}

void print_condition_member_info(member_info *mi, int num)
{
	int i;

	if (mi->name)
	{
		for (i = 0; i < total_member; i++)
		{
			if ((mi[i].age / num) == 1)
			{
				printf("이름: %s, 나이: %d, 전화번호: %s\n거주지: %s시 %s %s\n",
					mi[i].name, mi[i].age, mi[i].phone,
					mi[i].city, mi[i].street, mi[i].detail);
			}
			else
			{
				continue;
			}
		}
	}
}

void print_member_info(member_info *mi)
{
	int i;

	if (mi->name)
	{
		for (i = 0; i < total_member; i++)
		{
			printf("이름: %s, 나이: %d, 전화번호: %s\n거주지: %s시 %s %s\n",
				mi[i].name, mi[i].age, mi[i].phone,
				mi[i].city, mi[i].street, mi[i].detail);
		}
	}
}

int main(void)
{

	member_info *mi;

	mi = init_member_info();
	input_info(mi);

	printf("10대만 출력\n");
	print_condition_member_info(mi, 10);

	free(mi);
}
