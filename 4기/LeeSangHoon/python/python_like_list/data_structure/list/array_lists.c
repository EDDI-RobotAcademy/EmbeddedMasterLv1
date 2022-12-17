//
// Created by user2 on 2022-11-09.
//

#include <stdlib.h>
#include <stdio.h>

#include "array_lists.h"
#include "../../memory/memory_alloc.h"

int init_array_list (array_list_obj **obj, int size)
{
    int i;
    *obj = (array_list_obj *)malloc(sizeof(array_list_obj));

    if (obj == NULL) { return MEMORY_ALLOC_FAILURE; }

    (*obj)->array_list_obj_items = (array_list_metadata **)malloc(sizeof(array_list_metadata) * size);

    if ((*obj)->array_list_obj_items == NULL) { return MEMORY_ALLOC_FAILURE; }

    for (i = 0; i < size; i++) {
        (*obj)->array_list_obj_items[i] = (array_list_metadata *)malloc(sizeof(array_list_metadata));
        (*obj)->array_list_obj_items[i]->type = TYPENAME_OTHER;
    }

    (*obj)->allocated_memory_size = size;
    (*obj)->current_idx = 0;

    return MEMORY_ALLOC_SUCCESS;
}

void print_array_list (array_list_obj *obj)
{
    int i;
    int type;
    int size = obj->allocated_memory_size;

    for (i = 0; i < size; i++)
    {
        type = obj->array_list_obj_items[i]->type;

        switch (type) {
            case TYPENAME_INT:
                printf("data: %d\n", obj->array_list_obj_items[i]->data);
                break;
            case TYPENAME_POINTER_TO_CHAR:
                printf("data: %s\n", obj->array_list_obj_items[i]->data);
                break;
            case TYPENAME_POINTER_TO_DOUBLE:
                printf("data: %lf\n", *(double *)obj->array_list_obj_items[i]->data);
                break;
        }
    }
}

void array_list_add_impl(array_list_obj **obj, void *data, int type)
{
    int current_idx = (*obj)->current_idx++;

    (*obj)->array_list_obj_items[current_idx] = memory_type_alloc_call_table[type]();
    (*obj)->array_list_obj_items[current_idx]->data = data;
}