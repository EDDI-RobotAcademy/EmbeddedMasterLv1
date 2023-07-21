#ifndef __MEMBER_H__
#define __MEMBER_H__
#define MAX_USER_INPUT  17
#define MAX_MEMBER   10

typedef struct _member member;

struct _member
{
    char *id;
    char pw[MAX_USER_INPUT];
};

extern member *member_info_table;

void init_member_info_table (void);


#endif