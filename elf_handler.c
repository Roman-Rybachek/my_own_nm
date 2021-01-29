#include "my_own_nm.h"



static void getSymbols()
{
	char *output;

	for (Elf64_Xword i = 1; i < data.sym_shdr->sh_size / data.sym_shdr->sh_entsize; ++i) {
		if (data.syms[i].st_name) {
			if (ELF64_ST_TYPE(data.syms[i].st_info) != 4)
			{
				output = data.file + data.shdr[data.sym_shdr->sh_link].sh_offset + data.syms[i].st_name;
				printf("%s\n", output);
			}
		}
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
		}
	}
}
