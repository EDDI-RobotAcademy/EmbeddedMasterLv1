#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "pre_allocated_memory.h"

void init_pre_allocated_memory_0arg (void)
{
    set_pre_allocated_max_memory_size(DEFAULT_BASE_MEMORY_SIZE);
    alloc_pre_allocated_memory();
}

void init_pre_allocated_memory_1arg (int allocated_max_memory_size)
{
    set_pre_allocated_max_memory_size(allocated_max_memory_size);
    alloc_pre_allocated_memory();
}

void alloc_pre_allocated_memory (void)
{
    int i;
    int idx = (enum slab_idx)SLAB_32;

    pre_allocated_memory.allocated_memory = (void ***)malloc(sizeof(void **) * PREALLOC_COUNT);

    if (pre_allocated_memory.allocated_memory == NULL)
    {
        printf("Pre Allocated Memory 관리 메모리 생성 실패!\n");
        return;
    }

    for (i = 0; i < PREALLOC_COUNT; i++)
    {
        pre_allocated_memory.allocated_memory[i] = (void **)malloc(sizeof(1 << idx) * pre_allocated_memory.allocated_max_memory_size);
        if (pre_allocated_memory.allocated_memory[i] == NULL)
        {
            printf("Pre Allocated Memory 할당 실패!\n");
            return;
        }

        idx = idx << 1;
    }
}

void set_pre_allocated_max_memory_size (int request_max_memory_size)
{
    assert(request_max_memory_size < MEMORY_SIZE_LIMIT);

    pre_allocated_memory.allocated_max_memory_size = request_max_memory_size;
}

#define DOUBLE_PRESENTATION_WITH_INTEGER                2
#define EXPONENT_IDX                                    1
#define DOUBLE_PREICISION_BIAS                          1023
#define FOCUS_EXPONENT                                  20

int find_fit_slab_index(int request_memory_size)
{
    int exponent_number;
    union
    {
        double ieee754_double_value;
        int trick_shift_system[DOUBLE_PRESENTATION_WITH_INTEGER];
    }
    ieee754;

    ieee754.ieee754_double_value = request_memory_size;
    exponent_number = (ieee754.trick_shift_system[EXPONENT_IDX] >> FOCUS_EXPONENT) - DOUBLE_PREICISION_BIAS;
    return exponent_number + ((request_memory_size & (request_memory_size - (1 << exponent_number))) ? 1 : 0);
}