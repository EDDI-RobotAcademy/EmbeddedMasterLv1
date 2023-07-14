#include "member_register_handler.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "member.h"

member_data* memberTableHead = NULL;

void* proc_member_signUp(char* id, char* password)
{
    if(id == NULL || password == NULL)
    {
        printf("유효하지 않는 입력 값입니다.\n");

        return -1;
    }

    if(memberTableHead == NULL)
    {
        memberTableHead = (member_data*)malloc(sizeof(member_data));

        memberTableHead->id = (char*)malloc(strlen(id) + 1);
        strncpy(memberTableHead->id, id, strlen(id));

        memberTableHead->password = (char*)malloc(strlen(password) + 1);
        strncpy(memberTableHead->password, password, strlen(password));

        memberTableHead->link = NULL;

        printf("%s 계정이 등록되었습니다!\n", memberTableHead->id);

        return 0;
    }
    else
    {
        member_data* prevMember = memberTableHead;
        while(prevMember->link != NULL)
        {
            if(!strncmp(prevMember->id, id, strlen(id)))
            {
                printf("중복되는 ID 입니다.\n");

                return -1;
            }
            else
            {
                prevMember = prevMember->link;
            }
        }

        member_data* newMember = (member_data*)malloc(sizeof(member_data));

        newMember->id = (char*)malloc(strlen(id) + 1);
        strncpy(newMember->id, id, strlen(id));

        newMember->password = (char*)malloc(strlen(password) + 1);
        strncpy(newMember->password, password, strlen(password));

        prevMember->link = newMember;
        newMember->link = NULL;

        printf("%s 계정이 등록되었습니다!\n", newMember->id);

        return 0;
    }
}

void* proc_member_withdraw(char* id, char* password)
{
    if(id == NULL || password == NULL)
    {
        printf("유효하지 않는 계정 정보입니다.\n");

        return -1;
    }

    if(memberTableHead == NULL)
    {
        printf("계정 정보가 존재하지 않습니다.\n");

        return -1;
    }

    member_data* searchMemberData = memberTableHead;
    member_data* prevMember;
    do
    {
        if(!strncmp(searchMemberData->id, id, strlen(id)) && !strncmp(searchMemberData->password, password, strlen(password)))
        {
            if(!strncmp(memberTableHead->id, id, strlen(id)))
            {
                memberTableHead = searchMemberData->link;
            }
            else
            {
                prevMember->link = searchMemberData->link;
            }

            printf("%s 계정이 삭제 되었습니다.\n", searchMemberData->id);
            free(searchMemberData);

            return 0;
        }
        else
        {
            prevMember = searchMemberData;

            searchMemberData = searchMemberData->link;
        }
    }
    while(searchMemberData->link != NULL);

    printf("유효하지 않는 계정 정보입니다.\n");

    return -1;
}

void* proc_member_signIn(char* id, char* password)
{
    if(id == NULL || password == NULL)
    {
        printf("유효하지 않는 계정 정보입니다.\n");

        return NULL;
    }

    if(memberTableHead == NULL)
    {
        printf("계정 정보가 존재하지 않습니다.\n");

        return NULL;
    }

    member_data* searchMemberData = memberTableHead;
    
    do
    {
        if(strncmp(searchMemberData->id, id, strlen(id)))
        {
            if(searchMemberData == memberTableHead)
            {
                printf("유효하지 않는 계정 정보입니다.\n");

                return NULL;
            }
            else
            {
                searchMemberData = searchMemberData->link;
                continue;
            }
        }

        if(strncmp(searchMemberData->password, password, strlen(password)))
        {
            printf("Password가 일치하지 않습니다.\n");

            return NULL;
        }

        if(!searchMemberData->activate)
        {
            searchMemberData->activate = true;

            printf("접속 성공, 환영합니다!\n");

            return searchMemberData;
        }
        else
        {
            printf("이미 접속중인 계정입니다.\n");

            return NULL;
        }
    }
    while(searchMemberData->link != NULL);

    printf("계정 정보가 존재하지 않습니다.\n");

    return -1;
}

void* proc_member_signOut(char* id, char* password)
{
    if(id == NULL || password == NULL)
    {
        printf("유효하지 않는 계정 정보입니다.\n");

        return -1;
    }

    if(memberTableHead == NULL)
    {
        printf("계정 정보가 존재하지 않습니다.\n");

        return -1;
    }

    member_data* searchMemberData = memberTableHead;
    do
    {
        if(strncmp(searchMemberData->id, id, strlen(id)))
        {
            searchMemberData = searchMemberData->link;
            continue;
        }

        if(strncmp(searchMemberData->password, password, strlen(password)))
        {
            printf("Password가 일치하지 않습니다.\n");

            return -1;
        }
        
        if(searchMemberData->activate)
        {
            searchMemberData->activate = false;

            printf("접속 종료, 안녕히 가십시오.\n");

            return 0;
        }
        else
        {
            printf("확인되지 않은 접속 정보\n");

            return -1;
        }
    }
    while(searchMemberData->link != NULL);
}
