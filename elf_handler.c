#include "my_own_nm.h"

static void getSymbols(Elf64_Sym *syms)
{
	void	*end;
	char	*str;

	end = data.file + data.curr_shdr->sh_offset + data.curr_shdr->sh_size;
	str = NULL;
	syms++;
	while ((void*)syms < end)
	{
		str = data.file + (data.start_shdr + data.hdr->e_shstrndx - 1)->sh_offset + syms->st_name;
		printf ("%s\n", str);
		syms++;
	}
}

//		str = (char*)data.file + (data.start_shdr + data.hdr->e_shstrndx - 1)->sh_offset + data.curr_shdr->sh_name;
//		printf ("%d)%s\n", i,str);

void elf_handler()
{
	Elf64_Sym	*syms = NULL;

	data.hdr = data.file;
	data.start_shdr = data.file + data.hdr->e_shoff + data.hdr->e_shentsize;
	data.curr_shdr = data.start_shdr;
	char *str = NULL;

	for (int i = 1; i < data.hdr->e_shnum;  ++i) {
		if (data.curr_shdr->sh_type == SHT_SYMTAB) {
			syms = data.file + data.curr_shdr->sh_offset;
			getSymbols(syms);
		}
		data.curr_shdr += 1;
	}

}