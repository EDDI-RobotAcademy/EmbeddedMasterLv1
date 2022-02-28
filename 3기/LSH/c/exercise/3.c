#include <stdio.h>
#include <stdlib.h>
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

member_info *init_member_info(void)
{
	member_info *tmp = (member_info *)malloc(sizeof(member_info) * 64);
}

void input_info(member_info *mi)
{
	bool run = true;
	int num;

	while (run)
	{
		printf("회원 정보를 계속 입력하시겠습니까 ? 1(yes), 0(no)\n");
		scanf("%d", &num);

		switch (num)
		{
			case 1:
				printf("회원 정보를 입력해주세요.\n이름: ");
				scanf("%s", mi[total_member].name);

				printf("나이: ");
				scanf("%d", &mi[total_member].age);

				printf("전화 번호: ");
				scanf("%s", mi[total_member].phone);

				printf("도시: ");
				scanf("%s", mi[total_member].city);

				printf("도로명: ");
				scanf("%s", mi[total_member].street);

				printf("상세 주소: ");
				scanf("%s", mi[total_member].detail);

				total_member++;

				break;

			case 0:
				printf("회원 입력을 종료합니다.\n");
				run = false;
				break;
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

	print_member_info(mi);

	free(mi);
}
