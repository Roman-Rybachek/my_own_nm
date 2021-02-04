#include "my_own_nm.h"

int 		is_elf(void *void_pointer)
{
	char *p;

	p = (char*)void_pointer;
	if (p[EI_MAG0] == 127 && p[EI_MAG1] == 'E' && p[EI_MAG2] == 'L' && p[EI_MAG3] == 'F')
		return (1);
	return (0);
}
Elf64_Shdr	*getSHdr(void *PtrToELF, int index)
{
	Elf64_Ehdr *elf_header;
	Elf64_Shdr *section_array;
	Elf64_Shdr *section;

	elf_header = (Elf64_Ehdr*)PtrToELF;
	section_array = (Elf64_Shdr*)(PtrToELF + elf_header->e_shoff);
	section = &(section_array[index]);
	return (section);
}
char		*getSName(void *PtrToElf, int index)
{
	Elf64_Ehdr *elf_header;
	Elf64_Shdr *section;
	char *name;

	section = getSHdr(PtrToElf, index);
	elf_header = (Elf64_Ehdr*)PtrToElf;
	name = PtrToElf + getSHdr(PtrToElf, elf_header->e_shstrndx)->sh_offset + section->sh_name;
	printf("%s\n", name);
	return name;
}
int			ft_darr_len(char **arr)
{
	int height;

	height = 0;
	while (*arr)
	{
		arr++;
		height++;
	}
	return (height);
}