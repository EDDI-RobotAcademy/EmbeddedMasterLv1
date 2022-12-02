#ifndef __PRE_ALLOCATED_MEMORY_MANAGER_H__
#define __PRE_ALLOCATED_MEMORY_MANAGER_H__

enum slab_idx
{
    SLAB_32 = 5,
    SLAB_64,
    SLAB_128,
    SLAB_256,
    SLAB_512,
    SLAB_1K,
    SLAB_2K,
    SLAB_4K,
    SLAB_8K,
    SLAB_16K,
    SLAB_32K,
    SLAB_64K,
    SLAB_128K,
    SLAB_256K,
    END
};

#define ARRAY_BIAS                  (5)
#define PREALLOC_COUNT              ((END) - (ARRAY_BIAS))

#define BASE_MEMORY_COUNT           16

#define FREE_STATE                  0
#define ASSIGN_STATE                1

void ***pre_allocated_slab;
int pre_allocated_slab_free_state[PREALLOC_COUNT][BASE_MEMORY_COUNT];

void init_pre_allocated_slab(void);
int find_fit_slab_index(int s);
int check_free_chunck(int idx);
int check_pre_allocated_slab_free_state(int mem_size_idx, int mem_loc_idx);
int get_pre_allocated_slab_chunck(int memory_size_idx, void *pre_allocated_memory);
//void *place_pre_allocated_slab(int memory_size);
void free_pre_allocated_slab_chunck(int mem_size_idx, int mem_loc_idx);

#endif
