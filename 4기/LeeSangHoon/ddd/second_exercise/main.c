#include <stdio.h>

#include "domain/pre_allocated_memory/entity/pre_allocated_memory.h"
#include "domain/pre_allocated_memory/service/pre_allocated_memory_service.h"

int main(void)
{
    int i;
    int memory_idx;
    int *number_array;

    init_pre_allocated_memory(20);
    init_pre_allocated_memory();

    memory_idx = find_pre_allocated_memory_array_index(127);
    printf("memory_idx = %d\n", memory_idx);

#if 0
    number_array = pre_allocated_slab_chunk_alloc(sizeof(int) * 5);
    for (i = 0; i < 5; i++)
    {
        printf("number_array[%d] = %d\n", i, number_array[i]);
    }
#endif

    return 0;
}