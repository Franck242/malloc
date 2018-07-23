cmake_minimum_required(VERSION 3.10)
project(PSU_2017_malloc C)

set(CMAKE_C_STANDARD 11)

include_directories(header)

add_executable(PSU_2017_malloc
        header/malloc.h
        src/all_functions.c
        src/calloc.c
        src/malloc_fit.c
        src/show_alloc_mem.c)
