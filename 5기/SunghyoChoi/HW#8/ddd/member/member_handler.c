#include "member_handler.h"
#include "member.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int member_count=0;

char print_id_msg[] = "아이디를 입력하세요: ";
char print_pw_msg[] = "비밀번호를 입력하세요: ";

void member_register (void)
{   
        
    char *user_input = (char *) malloc(MAX_USER_INPUT);
    memset(user_input, 0, MAX_USER_INPUT);
    char message[] = "\n회원 가입을 진행합니다!\n ";
    int message_length = strlen(message);
    
    write(1, message, message_length);
    write(1, print_id_msg, strlen(print_id_msg));
    read(0, user_input, MAX_USER_INPUT );    

    member_info_table[member_count].id = user_input;
    
    
    write(1, print_pw_msg, strlen(print_pw_msg));
    read(0, member_info_table[member_count].pw, MAX_USER_INPUT);

   
    
    member_count++;
 
}

void member_login (void)
{
    char user_id_input[MAX_USER_INPUT] = { 0 };
    char user_pw_input[MAX_USER_INPUT] = { 0 };
 
    char message[] = "\n로그인을 진행합니다!\n ";
    int message_length = strlen(message);
    int is_login=0;
    write(1, message, message_length);
    write(1, print_id_msg, strlen(print_id_msg));
    read(0, user_id_input, MAX_USER_INPUT );

    for(int i=0;i<member_count; i++)
    {     
         if ( strcmp(user_id_input, member_info_table[i].id)==0 )
         {
            write(1, print_pw_msg, strlen(print_pw_msg));
            read(0, user_pw_input, MAX_USER_INPUT );   
            if ( strcmp(user_pw_input,member_info_table[i].pw)==0 )
            {
                is_login=1;
            }else{
                is_login=-1;
            }

         }
            
    }
    if(is_login==1)
    {
        printf("login success\n");
    }
    else if(is_login==-1)
    {
        printf("password is wrong\n");
    }
    else if(is_login==0)
    {
        printf("unregistered user\n");
    }

}
