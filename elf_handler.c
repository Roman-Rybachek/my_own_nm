#include "my_own_nm.h"

t_elf elf;

void elf_handler()
{
	Elf64_Ehdr *header = (Elf64_Ehdr*)data.file;
	data.class = header->e_ident[EI_CLASS];
	data.endian = header->e_ident[EI_DATA];

}