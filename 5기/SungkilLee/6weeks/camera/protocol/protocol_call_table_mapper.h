#ifndef __PROTOCOL_CALL_TABLE_MAPPER_H__
#define __PROTOCOL_CALL_TABLE_MAPPER_H__

#include "protocol_handler.h"

#define __PROTOCOL_CALL_TABLE(nr, sym) [nr] = sym,

__PROTOCOL_CALL_TABLE(0, proc_picture)
__PROTOCOL_CALL_TABLE(1, proc_video)
__PROTOCOL_CALL_TABLE(2, proc_timelapse)
__PROTOCOL_CALL_TABLE(3, proc_slow_motion)
__PROTOCOL_CALL_TABLE(4, proc_cinematic)
__PROTOCOL_CALL_TABLE(5, proc_panorama)

#endif