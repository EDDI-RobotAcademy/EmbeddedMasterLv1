cmake_minimum_required(VERSION 3.16)
project(first C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

set(CMAKE_BUILD_TYPE Debug)

add_executable(
        first main.c
        data_structure/list/list.h
        command/command.h command/command_call_table.h command/command_call_table_mapper.h
        command/command_handler.h command/command_handler.c command/command.c
        member/entity/member.h member/entity/member.c member/controller/member_command_call_table.h
        member/controller/member_command.h member/controller/member_command_call_table_mapper.h member/controller/member_command.c
        member/controller/member_command_handler.h member/controller/member_command_handler.c
        member/service/request/member_request.h member/service/request/member_request.c
        member/service/member_service_command.h member/service/member_service_command_table.h
        member/service/member_service_command_table_mapper.h member/service/member_service_handler.h
        member/service/member_service_handler.c member/repository/member_repository_command.h 
        member/repository/member_repository_command_table.h member/repository/member_repository_command_table_mapper.h 
        member/repository/member_repository_handler.h member/repository/member_repository_handler.c
        utility/ui/console/input_process.h utility/ui/console/input_process.c)
