#ifndef __MEMORY_TYPE_ALLOC_CALL_TABLE_MAP_H__
#define __MEMORY_TYPE_ALLOC_CALL_TABLE_MAP_H__

#define __MEMORY_TYPE_ALLOC_CALL_TABLE(nr, sym) [nr] = sym,

#include "memory_alloc.h"

__MEMORY_TYPE_ALLOC_CALL_TABLE(0, bool_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(1, char_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(2, unsigned_char_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(3, short_int_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(4, unsigned_short_int_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(5, int_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(6, unsigend_int_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(7, long_int_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(8, unsigned_long_int_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(9, long_long_int_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(10, unsigned_long_long_int_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(11, float_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(12, double_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(13, long_double_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(14, char_pointer_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(15, int_pointer_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(16, double_pointer_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(17, void_pointer_alloc)
__MEMORY_TYPE_ALLOC_CALL_TABLE(18, other_alloc)

#endif // __MEMORY_TYPE_ALLOC_CALL_TABLE_MAP_H__