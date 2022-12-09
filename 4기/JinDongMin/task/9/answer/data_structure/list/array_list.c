#include <stdio.h>
#include <stdlib.h>

#include "../../common/common.h"

// 왜 include 해야만 하는가?
#include "../../memory/memory_alloc.h"

#include "../../memory/memory_type_alloc_call_table.h"

int init_array_list(array_list_obj **obj, int size)
{
    int i;
    *obj = (array_list_obj *)malloc(sizeof(array_list_obj));

    // 메모리 할당 실패를 위한 예외처리
    if (*obj == NULL)
    {
        return MEMORY_ALLOC_FAILURE;
    }

    (*obj)->array_list_obj_items = (array_list_metadata **)malloc(sizeof(array_list_metadata *) * size);

    // 메모리 할당 실패를 위한 예외처리
    if ((*obj)->array_list_obj_items == NULL)
    {
        return MEMORY_ALLOC_FAILURE;
    }

    // 중복 할당을 방지하기 위해 for문을 주석처리 하였음
    // for (i = 0; i < size; i++)
    // {
    //     (*obj)->array_list_obj_items[i] = (array_list_metadata *)malloc(sizeof(array_list_metadata));

    //     // 메모리 할당 실패를 위한 예외처리
    //     if ((*obj)->array_list_obj_items[i])
    //     {
    //         return MEMORY_ALLOC_FAILURE;
    //     }

    //     (*obj)->array_list_obj_items[i]->type = TYPENAME_OTHER;
    // }
    
    (*obj)->allocated_memory_size = size;
    (*obj)->current_idx = 0;

    return MEMORY_ALLOC_SUCCESS;
}

void print_array_list(array_list_obj *obj)
{
    int i;
    int type;
    // 잠재적인 오류를 가진 코드를 주석처리 하였음
    // int size = obj->allocated_memory_size;
    int size = obj->current_idx;

    for (i = 0; i < size; i++)
    {
        type = obj->array_list_obj_items[i]->type;

        switch (type)
        {
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
    // 선 연산, 후 증가
    int current_idx = (*obj)->current_idx++;

    (*obj)->array_list_obj_items[current_idx] = memory_type_alloc_call_table[type]();

    // 추가한 코드
    // 할당 실패 시 그냥 오류문장 출력 후, 함수 반환
    if ((*obj)->array_list_obj_items[current_idx] == NULL)
    {
        printf("array_list_add_impl 함수에서 array_list_metadata 동적 할당 실패!\n");
        return;
    }

    (*obj)->array_list_obj_items[current_idx]->data = data;
}