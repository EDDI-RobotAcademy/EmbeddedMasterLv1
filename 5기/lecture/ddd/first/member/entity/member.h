#ifndef __MEMBER_H__
#define __MEMBER_H__

#define MAX_USER_INPUT          17

typedef struct _member member;
struct _member
{
    int unique_value;
    char *id;
    char password[MAX_USER_INPUT];
};

extern int unique_member_value_count;

member *init_member (char *id, char *password);
void print_member (member *member_object);
void free_member (member *member_object);

#endif