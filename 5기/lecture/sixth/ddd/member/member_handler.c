#include "member_handler.h"
#include "member.h"

#include <stdio.h>
#include <string.h>

#include <unistd.h>

char print_id_msg[] = "아이디를 입력하세요: ";
char print_password_msg[] = "비밀번호를 입력하세요: ";

void member_register (void)
{
    char user_input[MAX_USER_INPUT] = { 0 };
    char message[] = "회원 가입을 진행합니다!\n";
    int message_length = strlen(message);
    
    write(1, message, message_length);
    write(1, print_id_msg, strlen(print_id_msg));
    read(0, user_input, MAX_USER_INPUT);

    write(1, print_password_msg, strlen(print_password_msg));
    read(0, user_input, MAX_USER_INPUT);
}

void member_login (void)
{
    printf("로그인 시퀀스를 진행합니다!\n");
}