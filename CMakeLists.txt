project(my_own_nm)

cmake_minimum_required(VERSION 3.17)

INCLUDE_DIRECTORIES(./)

ADD_EXECUTABLE(my_own_nm    my_own_nm.c
                            elf_handler.c
                            utils/utils.c
                            utils/ft_itoa_hex.c
                            utils/lists.c
                            utils/sort.c
                            utils/argv_handler.c)