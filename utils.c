#include "my_own_nm.h"

int 		is_elf(void *void_pointer)
{
	char *p;

	p = (char*)void_pointer;
	if (p[EI_MAG0] == 127 && p[EI_MAG1] == 'E' && p[EI_MAG2] == 'L' && p[EI_MAG3] == 'F')
		return (1);
	return (0);
}

/*
 * There a lot of code, but it is readable.
 */
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

int			cmpadr(char *s1, char *s2)
{
	int isNull[2];

	isNull[0] = strncmp("                ", s1, 16);
	isNull[1] = strncmp("                ", s2, 16);
	if (isNull[0] == 0 && isNull[1] == 0)
		return (0);
	else if (isNull[0] == 0)
		return (-1);
	else if (isNull[1] == 0)
		return (1);
	else if (strtoll(s1, NULL, 16) > strtoll(s2, NULL, 16))
		return (1);
	else if (strtoll(s1, NULL, 16) < strtoll(s2, NULL, 16))
		return (-1);
	else
		return (0);
}
/*
char		**sort(char **table, int(*)(char*, char*))
{
	char **sorted = (char**)malloc(sizeof(char*) * )
}*/