#include "member_handler.h"
#include "member.h"

#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <termios.h>

char print_id_msg[] = "아이디를 입력하세요: ";
char print_password_msg[] = "비밀번호를 입력하세요: ";

void input_hidden_password(char *password, int max_length) {
    struct termios oldt, newt;
    int length = 0;
    char ch;

    // 현재 터미널 설정 가져오기
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // 비밀번호 입력 시 터미널 설정 변경: 입력 문자를 화면에 표시하지 않음
    newt.c_lflag &= ~(ECHO);

    // 새로운 터미널 설정 적용
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // 비밀번호 입력 받기
    read(0, password, max_length);
    length = strlen(password);
    password[length] = '\0'; // 문자열 마지막에 null 문자 추가

    // 터미널 설정을 원래대로 복원
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

void member_register (void)
{
    char user_input[MAX_USER_INPUT] = { 0 };
    char message[] = "회원 가입을 진행합니다!\n";
    int message_length = strlen(message);
    
    write(1, message, message_length);
    write(1, print_id_msg, strlen(print_id_msg));
    read(0, user_input, MAX_USER_INPUT);

    member_info_table->id = (char *)malloc(sizeof(char) * strlen(print_id_msg) + 1);
    strncpy(member_info_table->id, user_input, strlen(print_id_msg));
    
    memset(user_input, 0x0, strlen(print_id_msg) + 1);
    write(1, print_password_msg, strlen(print_password_msg));
    input_hidden_password(user_input, MAX_USER_INPUT);
    printf("\n");

    strncpy(member_info_table->password, user_input, strlen(print_id_msg));

    member_info_table->unique_value = unique_member_value_count;
    unique_member_value_count++;
}

void member_login (void)
{
    char user_id[MAX_USER_INPUT] = { 0 };
    char user_password[MAX_USER_INPUT] = { 0 };
    char message[] = "로그인 시퀀스를 진행합니다!\n";
    int message_length = strlen(message);
    
    write(1, message, message_length);
    write(1, print_id_msg, strlen(print_id_msg));
    read(0, user_id, MAX_USER_INPUT);
    
    write(1, print_password_msg, strlen(print_password_msg));
    input_hidden_password(user_password, MAX_USER_INPUT);
    printf("\n");

    if (strncmp(member_info_table->id, user_id, strlen(user_id)) != 0) {
        printf("아이디 혹은 비밀번호를 잘못 입력하였습니다!\n");
        return;
    }

    if (strncmp(member_info_table->password, user_password, strlen(user_password)) != 0) {
        printf("아이디 혹은 비밀번호를 잘못 입력하였습니다!\n");
        return;
    }

    printf("로그인 성공!\n");
}

void member_list (void)
{
    printf("unique value: %d\n", unique_member_value_count);
    //printf("id: %s", member_info_table[0].id)
}