#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "member_account.h"



void set_account_number(void)
{
    mem_account = (member_account*) malloc (sizeof(member_account) * MEMBER_ACCOUNT);
    printf("회원 계정 동적할당 완료\n");
}

bool id_duplication_check(void)
{
    int i = 0;
    i = 0;
    printf("id_duplication_check in\n");
    printf("member_account_count :%d\n", member_account_count);
    for(i; i < member_account_count; i++)
    {
        printf("id[%d] :%s\n", i,  mem_account[i].id);
        if( (strcmp(mem_account[member_account_count].id, mem_account[i].id)) == 0)
        {
            printf("중복 된 ID입니다 다시 입력 해 주세요\n");
            return ID_DUPLICATION;
        }
    }
    printf("사용 할 수 있는 ID 입니다.\n");
    return ID_NOT_DUPLICATION;       
}

void create_account(void)
{
    char* id;
    char* password;
    int str_len = 0;
    id = (char*)malloc(sizeof(char) * ID_MAX_LENGTH);
    password = (char*)malloc(sizeof(char) * PASSWORD_MAX_LENGTH);
    //printf("회원가입 페이지 입니다.\n");
    printf("member_account_count :%d\n", member_account_count);
redo_id_input:

    printf("id를 입력해주세요 : ");
    scanf(" %s", id);
    str_len = strlen(id);
    mem_account[member_account_count].id = (char*) malloc (sizeof(char) * str_len + 1);
    strncpy(mem_account[member_account_count].id, id, str_len);

    if(id_duplication_check())
    {
        goto redo_id_input;
    }
    
    printf("password를 입력해주세요 : ");
    scanf(" %s", password);
    str_len = strlen(password);
    mem_account[member_account_count].password = (char*) malloc (sizeof(char) * str_len + 1);
    strncpy(mem_account[member_account_count].password, password, str_len);

    member_account_count++;
    free(id);
    free(password);
}

void print_all_member_account(void)
{
    int i = 0;
    for(i; i < member_account_count; i++)
    {
        printf("id : %s\n", mem_account->id);
    }
}

