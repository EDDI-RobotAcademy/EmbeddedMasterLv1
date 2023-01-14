cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

set(CMAKE_C_STANDARD 99)

include(CTest)
enable_testing()

add_executable(main main.c common/util/custom_random.c entity/receive/rf_receive.c common/util/custom_alarm.c domain_service/dto/dto.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
