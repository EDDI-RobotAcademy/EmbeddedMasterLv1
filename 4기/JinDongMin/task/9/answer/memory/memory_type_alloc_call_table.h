#ifndef __MEMORY_TYPE_ALLOC_CALL_TABLE_H__
#define __MEMORY_TYPE_ALLOC_CALL_TABLE_H__

#include "../data_structure/list/array_list.h"
#include "../common/common.h"

#define CALL_BUFFER_COUNT   ((TYPENAME_OTHER) + (1))
#define CALL_BUFFER         (TYPENAME_OTHER)

typedef array_list_metadata *(* memory_type_alloc_call_ptr_t) (void);

const memory_type_alloc_call_ptr_t memory_type_alloc_call_table[CALL_BUFFER_COUNT] = {
    [0 ... CALL_BUFFER] = NULL,
    #include "memory_type_alloc_call_table_map.h"  
};

#endif // __MEMORY_TYPE_ALLOC_CALL_TABLE_H__