#include "console_handler.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_USER_ID_SIZE 30
#define MAX_USER_PASSWORD_SIZE 30

void* console_print_welcome_message(void)
{
    const char welcom_message[] = "\n저희 시스템을 찾아주셔서 감사합니다.\n";
    const char not_loggedined_option_message[] = "아래 메뉴에서 원하는 작업을 선택해주세요.\n";

    int welcome_message_length = strlen(welcom_message);
    int option_message_length = strlen(not_loggedined_option_message);
    int message_length = welcome_message_length + option_message_length + 1;

    char* message = (char *)malloc(sizeof(char) * message_length);

    strncat(message, welcom_message, welcome_message_length);
    strncat(message, not_loggedined_option_message, option_message_length);

    printf("%s", message);

    return 0;
}

void* console_get_menu_selected_number(void)
{
    void* selected_number = malloc(sizeof(char) + 1);

    char message[] = "원하는 동작을 입력하세요 : ";
    int message_length = strlen(message);

    write(1, message, message_length);
    //read(0, selected_number, sizeof(char) + 1);
    scanf("%s", (char*)selected_number);

    return selected_number;
}

void* console_print_sign_out_menu(void)
{
    printf("\n====================\n");
    printf("1. 계정 접속\n");
    printf("2. 계정 등록\n");
    printf("0. 메뉴 다시 보기\n");
    printf("====================\n\n");

    return 0;
}

void* console_print_sign_in_menu(void)
{
    printf("\n====================\n");
    printf("1. 접속 종료\n");
    printf("2. 계정 탈퇴\n");
    printf("0. 메뉴 다시 보기\n");
    printf("====================\n\n");

    return 0;
}

void* console_request_id_message(void)
{
    void* userId = malloc(sizeof(char) * (MAX_USER_ID_SIZE + 1));

    char message[] = "ID를 입력해주세요 : ";
    int message_length = strlen(message);

    write(1, message, message_length);
    //read(0, userId, MAX_USER_ID_SIZE + 1);
    scanf("%s", (char*)userId);

    return userId;
}

void* console_request_password_message(void)
{
    void* userPassword = malloc(sizeof(char) * (MAX_USER_PASSWORD_SIZE + 1));

    char message[] = "PASSWORD를 입력해주세요 : ";
    int message_length = strlen(message);

    write(1, message, message_length);
    //read(0, userPassword, MAX_USER_PASSWORD_SIZE + 1);
    scanf("%s", (char*)userPassword);

    return userPassword;
}