//
// Created by rinne on 24.01.2021.
//

#ifndef MY_OWN_NM_H
# define MY_OWN_NM_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/mman.h>
# include <elf.h>
# include <string.h>

int 				is_elf(void *p);
void 				elf_handler(void *file);
char				*ft_itoa_hex_t(size_t n);
Elf64_Shdr	*getSHdr(void *PtrToELF, int index);
char			*getSName(void *PtrToElf, int index);

#endif
