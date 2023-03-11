#ifndef __SAVE_TO_VOID_POINTER_ARRAY_CALL_TABLE_H__
#define __SAVE_TO_VOID_POINTER_ARRAY_CALL_TABLE_H__

#include <stdio.h>
#include "../../data_type.h"

#define CALL_BUFFER_COUNT   ((TYPENAME_OTHER) + (1))
#define CALL_BUFFER         (TYPENAME_OTHER)

typedef void (* save_to_void_pointer_array_call_table_ptr_t)(void *[]);

const save_to_void_pointer_array_call_table_ptr_t save_to_void_pointer_array_call_table[CALL_BUFFER_COUNT] = {
    [0 ... CALL_BUFFER] = NULL,
    #include "save_to_void_pointer_array_call_table_map.h"
};

#endif // __SAVE_TO_VOID_POINTER_ARRAY_CALL_TABLE_H__