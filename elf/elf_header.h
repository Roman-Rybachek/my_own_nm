#ifndef MY_OWN_NM_ELF_HEADER_H
#define MY_OWN_NM_ELF_HEADER_H

# include <elf.h>
# include "shared.h"

Elf64_Shdr	*getSHdr(void *PtrToELF, int index);
char		*getSName(void *PtrToElf, int index);

int			elf_sym_d(Elf64_Shdr *sec);
int 		elf_sym_t(char *name, Elf64_Shdr *sec);
int 		elf_sym_r(Elf64_Shdr *sec);
void 		elf_all_sym_info(void *file, Elf64_Shdr *sec, Elf64_Sym sym);

#endif //MY_OWN_NM_ELF_HEADER_H
