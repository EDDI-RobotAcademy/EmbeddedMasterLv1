#include <stdio.h>
#include <stdlib.h>

#include "data_structure/list/array_list.h"
#include "common/common.h"

#define LIST_ALLOC_SIZE 6

int main(void)
{
    array_list_obj *variant_list;

    if (init_array_list(&variant_list, LIST_ALLOC_SIZE) == MEMORY_ALLOC_FAILURE)
    {
        printf("메모리 할당 실패!\n");
        exit(-1);
    }

    array_list_add(&variant_list, 10);
    array_list_add(&variant_list, "purple");
    array_list_add(&variant_list, (double []){37.7});

    print_array_list(variant_list);

    // 동적 할당된 리스트를 해제하는 함수는 생략

    return 0;
}