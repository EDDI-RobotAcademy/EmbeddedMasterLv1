#ifndef __MEMORY_ALLOC_H__
#define __MEMORY_ALLOC_H__

#include "../data_structure/list/array_lists.h"

array_list_metadata *bool_type_alloc(void);
array_list_metadata *unsigned_char_alloc(void);
array_list_metadata *char_alloc(void);
array_list_metadata *short_int_alloc(void);
array_list_metadata *unsigned_short_int_alloc(void);
array_list_metadata *int_alloc(void);
array_list_metadata *unsigned_int_alloc(void);
array_list_metadata *long_int_alloc(void);
array_list_metadata *unsigned_long_int_alloc(void);
array_list_metadata *long_long_int_alloc(void);
array_list_metadata *unsigned_long_long_int_alloc(void);
array_list_metadata *float_alloc(void);
array_list_metadata *double_alloc(void);
array_list_metadata *long_double_alloc(void);
array_list_metadata *char_pointer_alloc(void);
array_list_metadata *void_pointer_alloc(void);
array_list_metadata *int_pointer_alloc(void);
array_list_metadata *double_pointer_alloc(void);
array_list_metadata *other_alloc(void);

typedef array_list_metadata *(* memory_type_alloc_call_ptr_t)(void);

const memory_type_alloc_call_ptr_t memory_type_alloc_call_table[TYPENAME_OTHER + 1] = {
        (memory_type_alloc_call_ptr_t const) bool_type_alloc,
        (memory_type_alloc_call_ptr_t const) unsigned_char_alloc,
        (memory_type_alloc_call_ptr_t const) char_alloc,
        (memory_type_alloc_call_ptr_t const) short_int_alloc,
        (memory_type_alloc_call_ptr_t const) unsigned_short_int_alloc,
        (memory_type_alloc_call_ptr_t const) int_alloc,
        (memory_type_alloc_call_ptr_t const) unsigned_int_alloc,
        (memory_type_alloc_call_ptr_t const) long_int_alloc,
        (memory_type_alloc_call_ptr_t const) unsigned_long_int_alloc,
        (memory_type_alloc_call_ptr_t const) long_long_int_alloc,
        (memory_type_alloc_call_ptr_t const) unsigned_long_long_int_alloc,
        (memory_type_alloc_call_ptr_t const) float_alloc,
        (memory_type_alloc_call_ptr_t const) double_alloc,
        (memory_type_alloc_call_ptr_t const) long_double_alloc,
        (memory_type_alloc_call_ptr_t const) char_pointer_alloc,
        (memory_type_alloc_call_ptr_t const) void_pointer_alloc,
        (memory_type_alloc_call_ptr_t const) int_pointer_alloc,
        (memory_type_alloc_call_ptr_t const) double_pointer_alloc,
        (memory_type_alloc_call_ptr_t const) other_alloc
};

#endif
