cmake_minimum_required(VERSION 3.1...3.29)
project(bf-interpreter)

add_executable(
        bf-interpreter
        stack.c
        bf-interpreter.c
        main.c
)

target_include_directories(bf-interpreter PRIVATE .)