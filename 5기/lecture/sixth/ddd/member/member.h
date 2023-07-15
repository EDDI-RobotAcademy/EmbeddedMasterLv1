#ifndef __MEMBER_H__
#define __MEMBER_H__

#define MAX_USER_INPUT          17

typedef struct _member member;
struct _member 
{
    char *id;
    char password[MAX_USER_INPUT];
};

member *member_info_table;

void init_member_info_table (void);

#endif