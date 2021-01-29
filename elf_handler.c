#include "my_own_nm.h"


void elf_handler()
{
	Elf64_Ehdr	*header = data.file;
	Elf64_Shdr	*start = data.file + header->e_shoff + header->e_shentsize;
	Elf64_Shdr	*curr = start;

	char *str = NULL;

	for (int i = 0; i < header->e_shnum; ++i) {
		str = (char*)data.file + (start + header->e_shstrndx - 1)->sh_offset + curr->sh_name;
		//str = (char*)(start + (header->e_shstrndx - 1)) + curr->sh_name;
		printf ("%s\n", str);
		curr += 1;
	}

}