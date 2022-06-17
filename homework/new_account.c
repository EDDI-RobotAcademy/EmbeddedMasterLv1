#include <stdio.h>

typedef struct information
{
	char name[5];
	unsigned int age;
	char phone_num[15];
	char residence[10];
}info;

void print_age(info *person, int *num)
{
	int i = 0;

	printf("\n10대 :\n");
	for(i = 0; i <= *num; i++)
		if((10 <= person[i].age) && (person[i].age < 20))
			printf("\n이름 : %s\n나이 : %u\n전화번호 : %s\n거주지 : %s\n", person[i].name, person[i].age, person[i].phone_num, person[i].residence);
		else
			continue;

	printf("\n20대 :\n");
	for(i = 0; i <= *num; i++)
		if((20 <= person[i].age) && (person[i].age < 30))
			printf("\n이름 : %s\n나이 : %u\n전화번호 : %s\n거주지 : %s\n", person[i].name, person[i].age, person[i].phone_num, person[i].residence);
		else
			continue;

	printf("\n30대 :\n");
	for(i = 0; i <= *num; i++)
		if((30 <= person[i].age) && (person[i].age < 40))
			printf("\n이름 : %s\n나이 : %u\n전화번호 : %s\n거주지 : %s\n", person[i].name, person[i].age, person[i].phone_num, person[i].residence);
		else
			continue;

}
void print_same_residence(int *num)
{
	int i = 0;
}
void check_continue(int *j)
{
		int k = 1;
		char c;
		while(k)
		{
			getchar();
			printf("회원가입을 계속하시겠습니까?(y/n) : ");
			scanf("%c", &c);
			if( (c == 'n') || (c == 'N'))
			{
				k = 0;
				*j = 0;
			}
			else if( (c == 'y') || (c == 'Y'))
				k = 0;
			else
				printf("올바르지 않은 문자입니다. 다시 입력하세요.\n");
		}
}
void get_info(info *person, int *num, int *j)
{
	while(*j)
	{
		printf("\n회원가입\n");
		printf("이름을 입력하세요 : ");
		scanf("%s",person[*num].name);
		printf("나이를 입력하세요 : ");
		scanf("%u", &person[*num].age);
		printf("전화번호를 입력하세요 : ");
		scanf("%s", person[*num].phone_num);
		printf("거주지를 입력하세요 : ");
		scanf("%s", person[*num].residence);

		*num += 1;
		check_continue(j);
	}
}
int main()
{
	//100명 회원가입 가능
	info person[50];
	int i = 0;
	int j = 1;

	get_info(person, &i, &j);
	print_age(person, &i);
		
	return 0;

}
