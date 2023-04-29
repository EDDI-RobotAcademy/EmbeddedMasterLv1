#ifndef __PIN_REPOSITORY_H__
#define __PIN_REPOSITORY_H__

#include "../service/request/pin_request.h"

enum pin_repository {
    SET_DIRECTION,
    PIN_REPOSITORY_END
};

void set_direction (struct _pin_request);

#endif // __PIN_REPOSITORY_H__
