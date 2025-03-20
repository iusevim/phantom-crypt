cmake_minimum_required(VERSION 3.30)
project(phantom_crypt C)

set(CMAKE_C_STANDARD 11)

add_executable(phantom_crypt main.c
        validation.c
        validation.h
        xor_encryption.c
        xor_encryption.h
        generate_key.c
        generate_key.h)
