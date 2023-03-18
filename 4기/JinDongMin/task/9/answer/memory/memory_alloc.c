#include <stdio.h>
#include <stdlib.h>

#include "../data_structure/list/array_list.h"
#include "../common/common.h"

array_list_metadata *bool_alloc(void) { }
array_list_metadata *char_alloc(void) { }
array_list_metadata *unsigned_char_alloc(void) { }
array_list_metadata *short_int_alloc(void) { }
array_list_metadata *unsigned_short_int_alloc(void) { }

array_list_metadata *int_alloc(void)
{
    printf("int_alloc() called\n");

    array_list_metadata *tmp = (array_list_metadata *)malloc(sizeof(array_list_metadata));
    tmp->type = TYPENAME_INT;

    return tmp;
}

array_list_metadata *unsigend_int_alloc(void) { }
array_list_metadata *long_int_alloc(void) { }
array_list_metadata *unsigned_long_int_alloc(void) { }
array_list_metadata *long_long_int_alloc(void) { }
array_list_metadata *unsigned_long_long_int_alloc(void) { }
array_list_metadata *float_alloc(void) { }

array_list_metadata *double_alloc(void)
{
    printf("double_alloc() called\n");

    array_list_metadata *tmp = (array_list_metadata *)malloc(sizeof(array_list_metadata));
    tmp->type = TYPENAME_DOUBLE;

    return tmp;
}

array_list_metadata *long_double_alloc(void) { }

array_list_metadata *char_pointer_alloc(void)
{
    printf("char_pointer_alloc() called\n");

    array_list_metadata *tmp = (array_list_metadata *)malloc(sizeof(array_list_metadata));
    tmp->type = TYPENAME_POINTER_TO_CHAR;

    return tmp;
}

array_list_metadata *int_pointer_alloc(void) { }

array_list_metadata *double_pointer_alloc(void)
{
    printf("double_pointer_alloc() called\n");

    array_list_metadata *tmp = (array_list_metadata *)malloc(sizeof(array_list_metadata));
    tmp->type = TYPENAME_POINTER_TO_DOUBLE;

    return tmp;
}

array_list_metadata *void_pointer_alloc(void) { }
array_list_metadata *other_alloc(void) { }