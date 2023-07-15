#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "how_to_malloc.h"

//#include "../receiver/receiver.h"
/*

    F7 : Build
    Shift + F5 : Run
    Ctrl + F5 : Debug
    Ctrl + N : New file

*/
const char *welcome_message = "저희 시스템을 찾아주셔서 환영합니다!\n";
//const char welcome_message[] = "저희 시스템을 찾아주셔서 환영합니다!\n";
const char *not_loggedin_option_message = "1번(회원가입), 2번(로그인 중 원하는 작업을 선택해주세요)\n";

int count = 0;

void print_welcome_message(void)
{
    int option_message_length = strlen(not_loggedin_option_message);
    int welcome_message_length = strlen(welcome_message);
    int message_length = option_message_length + welcome_message_length + 1;

    char *message = (char *)malloc(sizeof(char) + message_length);
    strncat(message, welcome_message, welcome_message_length);
    strncat(message, not_loggedin_option_message, option_message_length);

    printf(message);
}

char get_user_selected_number (void)
{
    char selected_number = 0;
    char message[] = "원하는 동작을 입력하세요: ";
    int message_length = strlen(message);

    write(1,message,message_length);
    //read(0, selected_number, 2);
    selected_number = getchar();
    getchar();

    return selected_number;
}

int main(void)
{
    //printf("First Test\n");
    //iam_add_on();

    bool isFinished = false;

    printf("malloc() 동적 할당 테스트\n");
    how_to_malloc_data();
    //recv_command_from_outbound();

    for (; !isFinished;)
    {
        // TODO : 특정 파일을 읽어서 로그인 여부를 판정합니다.
        //      [MALLOC-MEMBER-6]
        bool isLogedIn = false;

        if (!isLogedIn){
            print_welcome_message();
        }
        //get_user_selected_number();
        printf("selected number = %d\n",get_user_selected_number());
    }

    return 0;
    
}