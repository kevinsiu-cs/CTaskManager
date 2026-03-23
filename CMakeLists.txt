cmake_minimum_required(VERSION 3.20)
project(ctaskmanager C)

set(CMAKE_C_STANDARD 99)

add_executable(ctaskmanager
        main.c
        src/gantt.c
        include/input.h
        src/input.c
        include/teamMember.h
        src/teamMember.c
)

target_include_directories(ctaskmanager PRIVATE include)
