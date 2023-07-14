#ifndef __MEMBER_REGISTER_HANDLER_H__
#define __MEMBER_REGISTER_HANDLER_H__

void* proc_member_signUp(char* id, char* password);
void* proc_member_withdraw(char* id, char* password);

void* proc_member_signIn(char* id, char* password);
void* proc_member_signOut(char* id, char* password);

#endif