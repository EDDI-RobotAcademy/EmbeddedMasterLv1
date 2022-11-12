#ifndef ASSEMBLYTEST_POLYMORPHISM_CALL_H
#define ASSEMBLYTEST_POLYMORPHISM_CALL_H

#include "device.h"

#define __POLYMORPHISM_CALL(nr, sym) [nr] = sym,

__POLYMORPHISM_CALL(0, proc_handle1)
__POLYMORPHISM_CALL(1, proc_handle2)
__POLYMORPHISM_CALL(2, proc_handle3)
__POLYMORPHISM_CALL(3, proc_handle4)
__POLYMORPHISM_CALL(4, proc_handle5)
__POLYMORPHISM_CALL(5, proc_handle6)
__POLYMORPHISM_CALL(6, proc_handle7)
__POLYMORPHISM_CALL(7, proc_handle8)
__POLYMORPHISM_CALL(8, proc_handle9)


#endif //ASSEMBLYTEST_POLYMORPHISM_CALL_H