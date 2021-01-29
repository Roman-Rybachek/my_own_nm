#include "my_own_nm.h"


void elf_handler()
{
	Elf64_Ehdr	*header = data.file;
	Elf64_Shdr	*cur_sec = data.file + header->e_shoff;
	Elf64_Shdr x;

	int sym = 0;
	int str = 0;

	for (int i = 0; i < header->e_shnum; ++i) {
		x = cur_sec[i];
		if (x.sh_type == SHT_SYMTAB)
			sym++;
		if (x.sh_type == SHT_STRTAB)
			str++;
	}

}