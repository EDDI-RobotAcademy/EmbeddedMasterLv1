#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "2-3.h"

#define interface_print_member(mem_handler,idx)                                     \
{                                                                                   \
            printf("ID       : %d\n", mem_handler->mem_array[idx].member_id);       \
            printf("이름     : %s \n", mem_handler->mem_array[idx].name);               \
            printf("나이     : %d \n", mem_handler->mem_array[idx].age);                \
            printf("주소     : %s \n", mem_handler->mem_array[idx].address);            \
            printf("전화번호 : %s \n", mem_handler->mem_array[idx].phone_number);   \
            printf("\n\n");                                                         \
}                                                                                   \



void sort_member(member_handler *mem_handler, int command)
{
    int age_min, age_max, i = 0;
    switch(command)
    {
        case COMMAND_PRINTF_10S:
            age_min = 10;
            age_max = 20;       
            break;
        
        case COMMAND_PRINTF_20S:
            age_min = 20;
            age_max = 30;
            break;

        case COMMAND_PRINTF_30S:
            age_min = 30;
            age_max = 40;
            break;

        case COMMAND_PRINTF_ALL:
            age_min = 0;
            age_max = 100;
            break;
    }

    for (i; i < mem_handler->add_member_cnt; i++)
    {
        if(mem_handler->mem_array[i].age >= age_min && mem_handler->mem_array[i].age < age_max )
        {
            interface_print_member(mem_handler, i);
        }
    }

}
member* add_member(member_handler *mem_handler)
{
    member *mem;
    char name[STRING_MAX_LENGH];
    char address[STRING_MAX_LENGH];
    char phone_number[STRING_MAX_LENGH];
    int age;
    int str_len;
    static int add_member_cnt = 0;

    
    printf("총 관리 회원 %d명 중 %d명 사용 %d명 남음.\n", mem_handler->max_member_number, mem_handler->add_member_cnt, (mem_handler->max_member_number - mem_handler->add_member_cnt));
    if(!(mem_handler->max_member_number - mem_handler->add_member_cnt))
    {
        printf("관리할 회원이 꽉찼습니다.\n");
        return mem;
    }

    mem = (member*)malloc(sizeof(member));

    printf("이름을 입력 하세요 : ");
    scanf("%s",name);
    str_len = strlen(name);
    
    
    mem_handler->mem_array[add_member_cnt].name = (char *)malloc(sizeof(char) * (str_len + 1));
    strncpy(mem_handler->mem_array[add_member_cnt].name, name, str_len);
    

    printf("나이을 입력 하세요 : ");
    scanf("%d",&age);
    //mem_handler->mem_array[add_member_cnt].age = age;
    mem_handler->mem_array[add_member_cnt].age = age;
    

    
    
    printf("주소을 입력 하세요 : ");
    scanf("%s",address);
    str_len = strlen(address);
    mem_handler->mem_array[add_member_cnt].address = (char *)malloc(sizeof(char) * (str_len + 1));
    //mem_handler->mem_array[add_member_cnt].address = address;
    strncpy(mem_handler->mem_array[add_member_cnt].address, address, str_len);

    printf("전화번호을 입력 하세요 : ");
    scanf("%s",phone_number);
    str_len = strlen(phone_number);
    mem_handler->mem_array[add_member_cnt].phone_number = (char *)malloc(sizeof(char) * (str_len + 1));
    //mem_handler->mem_array[add_member_cnt].phone_number = phone_number;
    strncpy(mem_handler->mem_array[add_member_cnt].phone_number, phone_number,  str_len);

    //mem_handler->mem_array[add_member_cnt].member_id = add_member_cnt;
    mem_handler->mem_array[add_member_cnt].member_id = add_member_cnt + 1;
    

    mem_handler->add_member_cnt = ++add_member_cnt;

    return mem;
}
void menu_select(member_handler *mem_handler)
{
    member *mem;
    int min_age, max_age;
    int command = 0;
    int idx;
    printf("총 관리 회원 %d명 중 %d명 사용 %d명 남음.\n", mem_handler->max_member_number, mem_handler->add_member_cnt, (mem_handler->max_member_number - mem_handler->add_member_cnt));

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

            //mem_handler->tbl->print_member(mem_handler, age);
            //interface_print_member(mem_handler, idx,  min_age, max_age);
            sort_member(mem_handler, command);
            break;

        case COMMAND_PRINTF_20S:
            printf("COMMAND_PRINTF_20S in\n");
            //mem_handler->tbl->print_member(mem_handler, age);
            //interface_print_member(mem_handler, idx,  min_age, max_age);
            sort_member(mem_handler, command);
            break;

        case COMMAND_PRINTF_30S:
            printf("COMMAND_PRINTF_30S in\n");
            //mem_handler->tbl->print_member(mem_handler, age);
            //interface_print_member(mem_handler, idx,  min_age, max_age);
            sort_member(mem_handler, command);
            break;

        case COMMAND_PRINTF_ALL:
            printf("COMMAND_PRINTF_ALL in\n");
            //mem_handler->tbl->print_member(mem_handler, age);
            //interface_print_member(mem_handler, idx, min_age, max_age);
            sort_member(mem_handler, command);
            break;

        case COMMAND_ADD_MEMBER:
            //printf("COMMAND_ADD_MEMBER in\n");
            //mem_handler->mem_array[mem_handler->add_member_cnt] = mem_handler->tbl->add_member(mem_handler);
            //mem_handler->mem_array[mem_handler->add_member_cnt] = mem_handler->tbl->add_member(mem_handler);
            mem_handler->tbl->add_member(mem_handler);
            printf("add_member_cnt : %d\n",mem_handler->add_member_cnt);
            break;
    }
    //printf("menu :mem_handler->mem_array[0].name :%s\n", mem_handler->mem_array[0]->name);
    //mem_handler->add_member_cnt = add_member_cnt++;

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
    mem_handler = (member_handler*)malloc(sizeof(mem_handler) + sizeof(member) * member_max_num);
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
    tbl->sort_member = sort_member;
/*
    mem_handler->mem_array = (member*)malloc(sizeof(member)*member_max_num);
    if (mem_handler->mem_array == NULL)
    {
        printf("mem_handler->mem_array 동적할당 실패!\n");
        exit(-1);
    }
*/
    
    mem_handler->tbl = tbl;
    mem_handler->max_member_number = member_max_num;
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
    


    return 0;
}