#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

enum menu_enum {
    START,
    MEMBER_JOIN,
    MAKE_FOLDER,
    MAKE_FILE,
    VIEW_FILE,
    ALL_MEMBER_PRINT,
    END
};

#define MENU_CALL_BUFFER_COUNT      (END)
#define MENU_CALL_BUFFER            ((END) - (1))


//void (*) (void) -> menu_call_ptr_t으로 대체
typedef  void (* menu_call_ptr_t) (void);

void menu_not_impl(void)
{
    printf("아직 구현되지 않은 스펙입니다.\n");
}

const menu_call_ptr_t menu_call_table[MENU_CALL_BUFFER_COUNT] = {
    [0 ... MENU_CALL_BUFFER] = menu_not_impl,
    #include "menu_call.h"
    //[nr] = sym
    //menu_call_table[1] = proc_member_join
    //menu_call_table[2] = proc_make_folder
};

void proc_member_join(void)
{
    printf("proc_make_folder in\n");
    create_account();
}

void proc_make_folder(void)
{
    member_login();
    printf("proc_make_folder in\n");
    creat_folder();
}

void proc_make_file(void)
{
    member_login();
    printf("proc_make_file in\n");
}

void proc_view_file(void)
{
    member_login();
    printf("proc_view_file in\n");
}

void proc_all_member_print(void)
{
    printf("proc_all_member_print in\n");
    print_all_member_account();
}

void menu_select(void)
{
    int num = 0;

redo_menu_select:

    printf("메뉴를 선택해주세요\n");
    printf("1 : 회원 입력\n");
    printf("2 : 회원 폴더 생성\n");
    printf("3 : 회원 파일 생성\n");
    printf("4 : 회원 파일 조회\n");
    printf("5 : 모든 회원 출력\n");
    scanf("%d", &num);
    if(num < MENU_MIN || num > MENU_MAX)
    {
        printf("잘못 입력하였습니다\n");
        num = 0;
        getchar();
        goto redo_menu_select;
    }
    menu_call_table[num]();
    getchar();
}