#ifndef __MEMBER_H__
#define __MEMBER_H__

typedef struct _member_data member_data;
struct _member_data
{
    char* id;
    char* password;
    bool activate;
    struct _member_data* link;
};

enum member_register
{
    MEMBER_SIGN_UP,
    MEMBER_WITHDRAW,
    MEMBER_SIGN_IN,
    MEMBER_SIGN_OUT,
    END
};

#define MEMBER_REGISTER_CALL_BUFFER_COUNT  (END)
#define MEMBER_REGISTER_CALL_BUFFER        ((END) - 1)

#endif