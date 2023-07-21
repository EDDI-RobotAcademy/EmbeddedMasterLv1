#ifndef __MEMBER_REGISTER_CALL_TABLE_MAPPER_H__
#define __MEMBER_REGISTER_CALL_TABLE_MAPPER_H__

#include "member_register_handler.h"

#define __MEMBER_REGISTER_CALL_TABLE(nr, sym) [nr] = sym,

__MEMBER_REGISTER_CALL_TABLE(MEMBER_SIGN_UP, proc_member_signUp)
__MEMBER_REGISTER_CALL_TABLE(MEMBER_WITHDRAW, proc_member_withdraw)
__MEMBER_REGISTER_CALL_TABLE(MEMBER_SIGN_IN, proc_member_signIn)
__MEMBER_REGISTER_CALL_TABLE(MEMBER_SIGN_OUT, proc_member_signOut)

#endif