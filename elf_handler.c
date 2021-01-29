#include "my_own_nm.h"

static void getSymbols()
{
	int count = data.sym_shdr->sh_size / data.sym_shdr->sh_entsize;
	for (int i = 1; i < count; ++i) {
		printf("%s\n", data.file + data.shdr[data.hdr->e_shstrndx].sh_offset + data.syms[i].st_name);
	}
}

void elf_handler()
{
	data.hdr = (Elf64_Ehdr*)data.file;
	data.shdr = (Elf64_Shdr*)(data.file + data.hdr->e_shoff);

	for (int i = 1; i < data.hdr->e_shnum; ++i) {
//		printf("%s\n", data.file + data.shdr[data.hdr->e_shstrndx].sh_offset + data.shdr[i].sh_name);
		if (data.shdr[i].sh_type == SHT_SYMTAB) {
			data.sym_shdr = &data.shdr[i];
			data.syms = (Elf64_Sym*)(data.file + data.shdr[i].sh_offset);
			getSymbols();
			return ;
		}
	}
}
