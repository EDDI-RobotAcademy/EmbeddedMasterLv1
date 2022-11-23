#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "2-3.h"
void print_member(member_handler *mem_handler, int command)
{

}
member* add_member(member_handler *mem_handler)
{
    member *mem;
    char name[STRING_MAX_LENGH];
    char address[STRING_MAX_LENGH];
    char phone_number[STRING_MAX_LENGH];
    int age;
    int str_len;
    static int add_member_cnt  = 1;


    mem = (member*)malloc(sizeof(member));
    printf("이름을 입력 하세요 : ");
    scanf("%s",name);
    str_len = strlen(name);
    mem->name =(char *)malloc(sizeof(char) * (str_len + 1));
    mem_handler->mem_array[add_member_cnt]->name = name;

    printf("나이을 입력 하세요 : ");
    scanf("%d",&age);
    mem_handler->mem_array[add_member_cnt]->age = age;
    
    printf("주소을 입력 하세요 : ");
    scanf("%s",address);
    str_len = strlen(address);
    mem->address =(char *)malloc(sizeof(char) * (str_len + 1));
    mem_handler->mem_array[add_member_cnt]->address = address;

    printf("전화번호을 입력 하세요 : ");
    scanf("%s",phone_number);
    str_len = strlen(phone_number);
    mem->phone_number =(char *)malloc(sizeof(char) * (str_len + 1));
    mem_handler->mem_array[add_member_cnt]->phone_number = phone_number;

    mem_handler->add_member_cnt = add_member_cnt++;

    return mem;
}
void menu_select(member_handler *mem_handler)
{
    member *mem;

    int command = 0;
    printf("메뉴를 입력하세요\n");
    printf("1 : 10대 회원 출력\n");
    printf("2 : 20대 회원 출력\n");
    printf("3 : 30대 회원 출력\n");
    printf("4 : 모든 회원 출력\n");
    printf("5 : 회원 추가 입력\n");
    scanf(" %d", &command);
    switch(command)
    {
        case COMMAND_PRINTF_10S:
            printf("COMMAND_PRINTF_10S in\n");
            break;

        case COMMAND_PRINTF_20S:
            printf("COMMAND_PRINTF_20S in\n");
            break;

        case COMMAND_PRINTF_30S:
            printf("COMMAND_PRINTF_30S in\n");
            break;

        case COMMAND_PRINTF_ALL:
            printf("COMMAND_PRINTF_ALL in\n");
            break;

        case COMMAND_ADD_MEMBER:
            printf("COMMAND_ADD_MEMBER in\n");
            mem = mem_handler->tbl->add_member(mem_handler);
            printf("add_member_cnt : %d\n",mem_handler->add_member_cnt);
            break;
    }
    

}
member_handler *allocate_member_handler(void)
{
    member_handler *mem_handler;
    member_handler_method_table *tbl = NULL;
    int member_max_num;
    int i = 0;
    printf("관리할 회원 수 입력 : ");
    scanf("%d",&member_max_num);

    //mem_handler 동적 할당
    mem_handler = (member_handler*)malloc(sizeof(mem_handler));
    if (mem_handler == NULL)
    {
        printf("member_handler 동적할당 실패!\n");
        exit(-1);
    }

    //member_handler_method_table 동적할당
    tbl = (member_handler_method_table*)malloc(sizeof(member_handler_method_table));
    if (mem_handler == NULL)
    {
        printf("member_handler_method_table 동적할당 실패!\n");
        exit(-1);
    }

    tbl->add_member = add_member;
    tbl->menu_select = menu_select;
    tbl->print_member = print_member;

    //mem_handler->mem_array 동적 할당
    for(i; i < member_max_num; i++)
    {
        mem_handler->mem_array[i] = (member *)malloc(sizeof(member) * member_max_num);
    }
    if (mem_handler->mem_array == NULL)
    {
        printf("mem_handler->mem_array 동적할당 실패!\n");
        exit(-1);
    }
    mem_handler->tbl = tbl;

    return mem_handler;
}

int main (void)
{
    member_handler *mem_handler;
    mem_handler = allocate_member_handler();
    while(1)
    {
        mem_handler->tbl->menu_select(mem_handler);
    }
    //mem_handler->mem_array[i] = (member* )malloc(member) );


    return 0;
}