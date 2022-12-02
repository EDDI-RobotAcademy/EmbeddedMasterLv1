#include <stdlib.h>
#include <stdio.h>

void init_pre_allocated_slab(void)
{
    int i;
    int idx = (enum slab_idx)SLAB_32;
    pre_allocated_slab = (void ***)malloc(sizeof(void **) * PREALLOC_COUNT);

    for (i = 0; i < PREALLOC_COUNT; i++)
    {
        pre_allocated_slab[i] = (void **)malloc(sizeof(1 << idx) * BASE_MEMORY_COUNT);
        idx = idx << 1;
    }
}

int find_fit_slab_index(int s)
{
    int m;
    union {
        double x;
        int b[2];
    } ieee754;

    ieee754.x = s;
    m = (ieee754.b[1] >> 20) - 1023;
    return m + ((s & (s - (1 << m))) ? 1 : 0);
}

int check_free_chunck(int idx)
{
    int i;

    for (i = 0; i < BASE_MEMORY_COUNT; i++)
    {
        if (pre_allocated_slab_free_state[idx][i] == FREE_STATE)
        {
            return i;
        }
    }

    printf("관리 메모리 증설 필요!\n");
}

int check_pre_allocated_slab_free_state(int mem_size_idx, int mem_loc_idx)
{
    return pre_allocated_slab_free_state[mem_size_idx - ARRAY_BIAS][mem_loc_idx];
}

int get_pre_allocated_slab_chunck(int memory_size_idx, void *pre_allocated_memory)
{
    int real_idx = memory_size_idx - ARRAY_BIAS;
    int free_chunck_idx = check_free_chunck(real_idx);

    pre_allocated_slab_free_state[real_idx][free_chunck_idx] = ASSIGN_STATE;

    pre_allocated_memory = pre_allocated_slab[real_idx][free_chunck_idx];

    return free_chunck_idx;
}

#if 0
void *place_pre_allocated_slab(int memory_size)
{
    int idx = find_fit_slab_index(memory_size);
    return get_pre_allocated_slab_chunck(idx);
}
#endif

void free_pre_allocated_slab_chunck(int mem_size_idx, int mem_loc_idx)
{
    //memset(&pre_allocated_slab[mem_size_idx][mem_loc_idx], 1 << (mem_size_idx + ARRAY_BIAS), 0x00);

    pre_allocated_slab_free_state[mem_size_idx - ARRAY_BIAS][mem_loc_idx] = FREE_STATE;
}