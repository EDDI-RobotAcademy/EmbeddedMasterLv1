#ifndef __PIN_REPOSITORY_TABLE_H__
#define __PIN_REPOSITORY_TABLE_H__

#include "pin_repository.h"

typedef void (* pin_repository_call_ptr_t) (struct _pin_request);

const pin_repository_call_ptr_t pin_repository_call_table[] = {
    set_direction
};

#endif // __PIN_REPOSITORY_TABLE_H__
