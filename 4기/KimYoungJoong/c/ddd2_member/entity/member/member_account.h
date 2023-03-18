#ifndef __MEMBER_ACCOUNT_H_
#define __MEMBER_ACCOUNT_H_

#define MEMBER_ACCOUNT  100

#define ID_MAX_LENGTH       15
#define PASSWORD_MAX_LENGTH 15

#define ID_DUPLICATION      1
#define ID_NOT_DUPLICATION  0

#define LOGIN_SUCCCESS  1
#define LOGIN_FAIL      0

typedef struct _member_account member_account;

struct _member_account
{
    char* id;
    char* password;
};

member_account *mem_account;
int member_account_count = 0;




#endif