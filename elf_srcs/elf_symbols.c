#include "elf_header.h"

int		elf_sym_d(Elf64_Shdr *sec)
{
	if (sec->sh_flags & 3)
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
void 	elf_all_sym_info(void *file, Elf64_Shdr *sec, Elf64_Sym sym)
{
	printf("Symbol:\n");
	printf("Value: %lu\n", sym.st_value);
	printf("Size: %lu\n", sym.st_size);
	printf("Bind: %i\n", ELF64_ST_BIND(sym.st_info));
	printf("(sym)Type: %i\n", ELF64_ST_TYPE(sym.st_info));
	printf("Other %i\n", sym.st_other);
	printf("Shndx: %i\n", sym.st_shndx);

	printf("Section: \n");
	printf("Name: %s\n", getSName(file, sym.st_shndx));
	printf("(sec)Type: %i\n", sec->sh_type);
	printf("Flags: %lu\n", sec->sh_flags);
	printf("Size: %lu\n", sec->sh_size);
	printf("Link: %i\n\n", sec->sh_link);
}