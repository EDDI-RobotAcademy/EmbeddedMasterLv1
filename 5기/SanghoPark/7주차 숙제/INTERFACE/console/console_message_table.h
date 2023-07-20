#ifndef __CONSOLE_MESSAGE_TABLE_H__
#define __CONSOLE_MESSAGE_TABLE_H__

#include <stdio.h>
#include "console.h"

typedef void* (*console_message_ptr_t) (void);

void* console_handler_not_implemented (void)
{
    printf("미구현 스펙 입니다.\n");

    return (void*)-1;
}

const console_message_ptr_t console_message_table[CONSOLE_MSG_BUFFER_COUNT] = {
    [0 ... CONSOLE_MSG_BUFFER] = &console_handler_not_implemented,
    #include "console_message_table_mapper.h"
};

#endif