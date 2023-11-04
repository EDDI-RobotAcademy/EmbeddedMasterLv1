#include "member.h"
#include <stdlib.h>


member *member_info_table;

void init_member_info_table (void)
{
    member_info_table= (member *)malloc(sizeof(member) * MAX_MEMBER );
}





