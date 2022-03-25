cmake_minimum_required(VERSION 3.21)
project(linked_list C)

set(CMAKE_C_STANDARD 99)


include_directories(src/headers)

add_executable(linked_list main.c src/list.c src/headers/list.h src/tree.c src/headers/tree.h)






