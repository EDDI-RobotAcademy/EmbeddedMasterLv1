#include <stdio.h>
#include <stdlib.h>

void input_info(char *name, int *age, char *phone, char *city, char *street, char *detail)
{
	printf("회원 정보를 입력해주세요.\n이름: ");
	scanf("%s", name);

	printf("나이: ");
	scanf("%d", age);

	printf("전화 번호: ");
	scanf("%s", phone);

	printf("도시: ");
	scanf("%s", city);

	printf("도로명: ");
	scanf("%s", street);

	printf("상세 주소: ");
	scanf("%s", detail);
}

int main(void)
{
	int age;
	char name[32] = { 0 };
	char phone[32] = { 0 };
	char city[32] = { 0 };
	char street[128] = { 0 };
	char detail[128] = { 0 };

	input_info(name, &age, phone, city, street, detail);

	printf("이름: %s, 나이: %d, 전화번호: %s\n거주지: %s시 %s %s\n",
		name, age, phone, city, street, detail);
}
