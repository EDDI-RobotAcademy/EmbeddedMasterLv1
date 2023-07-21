#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../console/console.h"
#include "../console/console_handler.h"
#include "../console/console_message_table.h"

#include "../member/member.h"
#include "../member/member_register_handler.h"
#include "../member/member_register_call_table.h"

int main (void)
{
    member_data* currentUser = NULL;
    bool is_finished = false;

    for(; !is_finished;)
    {
        if(currentUser == NULL)
        {
            char* selected_menu = NULL;
            char* consoleId = NULL;
            char* consolePassword = NULL;

            console_message_table[CONSOLE_MSG_WELCOME]();
            console_message_table[CONSOLE_MSG_SIGN_OUT_MENU]();
            
            selected_menu = console_message_table[CONSOLE_MSG_SELECT_NUMBER]();
            switch(*(selected_menu) - 0x30)
            {
                case CONSOLE_MENU_REPEAT:
                    console_message_table[CONSOLE_MSG_SIGN_OUT_MENU]();
                break;
                case CONSOLE_MENU_SIGN_IN:
                    printf("접속을 시도합니다.\n");
                    consoleId = console_message_table[CONSOLE_MSG_REQ_ID]();
                    consolePassword = console_message_table[CONSOLE_MSG_REQ_PASSWORD]();

                    currentUser = member_register_call_table[MEMBER_SIGN_IN](consoleId, consolePassword);
                    if(currentUser != NULL)
                    {
                        printf("%s 님 환영합니다!\n", currentUser->id);
                    }
                    else
                    {
                        printf("접속 실패, 다시 시도하여 주십시오.\n");

                        currentUser = NULL;
                    }

                    free(consoleId);
                    free(consolePassword);
                break;
                case CONSOLE_MENU_SIGN_UP:
                    printf("회원 가입을 진행합니다.\n");
                    consoleId = console_message_table[CONSOLE_MSG_REQ_ID]();
                    consolePassword = console_message_table[CONSOLE_MSG_REQ_PASSWORD]();

                    if(!(unsigned int*)member_register_call_table[MEMBER_SIGN_UP](consoleId, consolePassword))
                    {
                        printf("%s 님 환영합니다! 로그인하여 이용해주십시오.\n", consoleId);
                    }
                    else
                    {
                        printf("생성 실패, 다시 시도하여 주십시오.\n");
                    }

                    free(consoleId);
                    free(consolePassword);
                break;
                default:
                    printf("존재하지 않는 작업 입니다.\n\n");
                break;
            }

            free(selected_menu);
        }
        else
        {
            char* selected_menu = NULL;
            char* consoleId = NULL;
            char* consolePassword = NULL;

            console_message_table[CONSOLE_MSG_SIGN_IN_MENU]();
            
            selected_menu = console_message_table[CONSOLE_MSG_SELECT_NUMBER]();
            switch(*(selected_menu) - 0x30)
            {
                case CONSOLE_MENU_REPEAT:
                    console_message_table[CONSOLE_MSG_SIGN_IN_MENU]();
                break;
                case CONSOLE_MENU_SIGN_OUT:
                    printf("접속을 종료합니다.\n");

                    if(!(unsigned int*)member_register_call_table[MEMBER_SIGN_OUT](currentUser->id, currentUser->password))
                    {
                        currentUser = NULL;
                    }
                break;
                case CONSOLE_MENU_WITHDRAW:
                    printf("회원 탈퇴를 진행합니다.\n");
                    consolePassword = console_message_table[CONSOLE_MSG_REQ_PASSWORD]();

                    if(!(unsigned int*)member_register_call_table[MEMBER_WITHDRAW](currentUser->id, consolePassword))
                    {
                        currentUser = NULL;
                    }

                    free(consolePassword);
                break;
                default:
                    printf("존재하지 않는 작업 입니다.\n\n");
                break;
            }

            free(selected_menu);
        }
    }

    return 0;
}