cmake_minimum_required(VERSION 3.0) # CMake 버전은 최소 3.0 이상을 사용

project(interface C) # 프로젝트 이름
set(CMAKE_C_STANDARD 99)
set(SOURCE main/main.c main/add_on_lib.c
        protocol/protocol_handler.c
        receiver/receiver.c
        protocol/camera/camera_handler.c)
#set(SOURCE main/main.c)

add_executable(${PROJECT_NAME} ${SOURCE}) 
# PROJECT_NAME으로 실행파일을 만든다. 
# 만드는데 위에 설정한 Source들을 가지고 만들겠다라는 의미.