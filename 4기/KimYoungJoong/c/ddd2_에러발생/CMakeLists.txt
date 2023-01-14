cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(main main.c entity/member/member_account.c utility/menu/menu.c)

set(CPACK_PROJECT_NAME ${PROJECT_VERSIONPROJECT_NAME})
set(CPACK_PROJECT_VERSION ${})
include(CPack)
