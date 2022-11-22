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

    mem = (member*)malloc(sizeof(member));

    



    return mem;
}
void menu_select(member_handler *mem_handler)
{
    member_handler *mem;

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
            mem_handler->tbl->add_member(mem_handler);
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

    mem_handler = (member_handler*)malloc(sizeof(mem_handler));
    if (mem_handler == NULL)
    {
        printf("member_handler 동적할당 실패!\n");
        exit(-1);
    }

    tbl = (member_handler_method_table*)malloc(sizeof(member_handler_method_table));
    if (mem_handler == NULL)
    {
        printf("member_handler_method_table 동적할당 실패!\n");
        exit(-1);
    }

    tbl->add_member = add_member;
    tbl->menu_select = menu_select;
    tbl->print_member = print_member;

    
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