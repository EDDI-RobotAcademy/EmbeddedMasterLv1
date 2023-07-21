#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <unistd.h>

#include "how_to_malloc.h"

#include "../member/member.h"
#include "../member/member_handler.h"

#include "../command/command_handler.h"
#include "../command/command_call_table.h"

#define ASCII_BIAS          (0x30)
// F7: Build
// Shift + F5: Run
// Ctrl + F5: Debug

// Ctrl + N: New file
const char welcome_message[] = "저희 시스템을 찾아주셔서 감사합니다!\n";
const char not_loggedin_option_message[] = "0번(종료), 1번(회원가입), 2번(로그인), 3번(회원정보) 중 원하는 작업을 선택해주세요!\n";

void print_welcome_message (void)
{
    int option_message_length = strlen(not_loggedin_option_message);
    int welcome_message_length = strlen(welcome_message);
    int message_length = option_message_length + welcome_message_length + 1;

    char *message = (char *)malloc(sizeof(char) * message_length);
    strncat(message, welcome_message, welcome_message_length);
    strncat(message, not_loggedin_option_message, option_message_length);

    printf(message);
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

#define USER_COMMAND_BUFFER_SIZE            3

char get_user_selected_number (void)
{
    char selected_number[USER_COMMAND_BUFFER_SIZE] = { 0 };
    char message[] = "원하는 동작을 입력하세요: ";
    int message_length = strlen(message);
    
    write(1, message, message_length);
    read(0, selected_number, USER_COMMAND_BUFFER_SIZE);

    return atoi(selected_number);
}

int main (void)
{
    bool is_finished = false;

    printf("malloc() 동적 할당 테스트\n");
    how_to_malloc_data();
    init_member_info_table();

    for (; !is_finished;)
    {
        // TODO: 특정 파일을 읽어서 로그인 여부를 판정합니다
        //       [MALLOC-MEMBER-6]
        bool is_logged_in = false;
        int command_idx;

        if (!is_logged_in) {
            print_welcome_message();
        }

        command_idx = get_user_selected_number();
        printf("selected number = %d\n", command_idx);

        if (command_idx < 0) {
            printf("올바른 명령을 입력해주세요!\n");
            continue;
        }

        if (command_idx == 0) {
            is_finished = true;
        }

        if (command_idx < 4) {
            command_call_table[command_idx]();
        }
    }

    return 0;
}