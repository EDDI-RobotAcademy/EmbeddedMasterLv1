#include <stdio.h>

#include "entity/member/member_account.h"
#include "utility/menu/menu.h"
#include "utility/menu/menu_call.h"


int main (void)
{
    set_account_number();
    for( ; ; )
    {
        create_account();
    }   
    return 0;
}