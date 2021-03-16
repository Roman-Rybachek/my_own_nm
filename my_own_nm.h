#ifndef MY_OWN_NM_H
# define MY_OWN_NM_H

# include "shared.h"

int					is_arch(void *void_pointer);
int 				is_elf(void *p);
int 				is_pe(void *void_pointer);

void				arch_handler(void *file);
char				**elf_handler(void *file);
char				**pe_handler(void *file);

#endif
