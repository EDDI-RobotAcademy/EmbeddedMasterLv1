#ifndef __ARRAY_LISTS_H__
#define __ARRAY_LISTS_H__

#include <string.h>

#include "../../common/common.h"

typedef struct _array_list_metadata array_list_metadata;

struct _array_list_metadata
{
    void *data;
    unsigned int type;
};

typedef struct _array_list_obj array_list_obj;

struct _array_list_obj
{
    array_list_metadata **array_list_obj_items;
    unsigned int allocated_memory_size;
    unsigned int current_idx;
};

#define array_list_add(obj, data)                                   \
{                                                                   \
    int type = typecheck(data);                                     \
    printf("type: %d\n", type);                                     \
    array_list_add_impl(obj, data, type);                           \
}

int init_array_list (array_list_obj **, int);
void print_array_list (array_list_obj *);
void array_list_add_impl(array_list_obj **, void *, int);

#endif