project(my_own_nm)

cmake_minimum_required(VERSION 3.17)

INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(system_headers)
INCLUDE_DIRECTORIES(elf_srcs)

ADD_EXECUTABLE(my_own_nm    my_own_nm.c
                            utils/argv_handler.c
                            utils/ft_itoa_hex.c
                            utils/lists.c
                            utils/sort.c
                            utils/utils.c
                            utils/utils2.c
                            elf_srcs/elf_handler.c
                            elf_srcs/elf_utils.c
                            elf_srcs/elf_symbols.c
        )