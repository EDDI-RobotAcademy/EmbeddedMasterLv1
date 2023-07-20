#include "member.h"

#include <stdlib.h>

#define INITIAL_ALLOC           10

member *member_info_table;
int unique_member_value_count = 0;

void init_member_info_table (void)
{
    member_info_table = (member *)malloc(sizeof(member) * INITIAL_ALLOC);
}