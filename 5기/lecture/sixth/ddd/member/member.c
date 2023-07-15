#include "member.h"

#define INITIAL_ALLOC           10

void init_member_info_table (void)
{
    member_info_table = (member *)malloc(sizeof(member) * INITIAL_ALLOC);
}