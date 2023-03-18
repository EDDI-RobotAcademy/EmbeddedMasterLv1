#ifndef ASSEMBLYTEST_MENU_CALL_H
#define ASSEMBLYTEST_MENU_CALL_H

#include "menu.h"

#define __MENU_CALL(nr, sym)    [nr] = sym,

//__MENU_CALL(0, menu_not_impl)
__MENU_CALL(1, proc_member_join)
__MENU_CALL(2, proc_make_folder)
__MENU_CALL(3, proc_make_file)
__MENU_CALL(4, proc_view_file)
__MENU_CALL(5, proc_all_member_print)




#endif