#include "my_own_nm.h"

int		elf_sym_d(char *name, Elf64_Sym sym)
{
	if (!strcmp(name, ".data") ||
		!strcmp(name, ".data1") ||
		sym.st_shndx & 3)
		return (1);
	return (0);
}

int 	elf_sym_t(char *name, Elf64_Shdr *sec)
{
	if (!strcmp(name, ".text"))
		return (1);
	if ((sec->sh_flags & 6) && !(sec->sh_flags & 1))
		return (1);
	return (0);
}

int 	elf_sym_r(Elf64_Shdr *sec)
{
	if ((sec->sh_flags & 1) || (sec->sh_flags & 4))
		return (0);
	if (sec->sh_flags & 2)
		return (1);
	return (0);
}