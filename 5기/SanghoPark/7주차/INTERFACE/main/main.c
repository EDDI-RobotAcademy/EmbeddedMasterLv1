#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "how_to_malloc.h"

const char welcom_message[] = "저희 시스템을 찾아주셔서 감사합니다.\n";
const char not_loggedined_option_message[] = "1번 (회원가입) 2번 (로그인) 중 원하는 작업을 선택해주세요.\n";

void print_welcome_message(void)
{
    int welcome_message_length = strlen(welcom_message);
    int option_message_length = strlen(not_loggedined_option_message);
    int message_length = welcome_message_length + option_message_length + 1;

    char* message = (char *)malloc(sizeof(char) * message_length);

    strncat(message, welcom_message, welcome_message_length);
    strncat(message, not_loggedined_option_message, option_message_length);

    printf(message);
}

int get_user_selected_number(void)
{
    char selected_number = 0;
    char message[] = "원하는 동작을 입력하세요 : ";
    int message_length = strlen(message);

    //selected_number = getchar();

    write(1, message, message_length);
    read(0, &selected_number, 2);

    printf("selected Number = %d\n", selected_number - 0x30);

    return selected_number;
}

int main (void)
{
    // F7 : Build
    // Shift + F5 : Run;
    // Ctrl + F5 : Debug
    bool is_finished = false;

    printf("malloc 동적 할당 테스트\n");

	how_to_malloc_data();

    for(; !is_finished;)
    {
        // TODO : 특정 파일을 읽어서 로그인 여부를 판정합니다.
        //        [MALLOC-MEMBER-6]
        bool is_loged_in = false;

        if(!is_loged_in)
        {
            print_welcome_message();
        }

        get_user_selected_number();
    }

    return 0;
}