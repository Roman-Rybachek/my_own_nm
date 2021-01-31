#include "my_own_nm.h"

static char *fillAddr(Elf64_Addr value)
{
	char 	*hex;
	char 	*ret;
	int		len;

	ret = calloc(17, 1);
	ret[16] = '\0';
	if (!value)
	{
		memset(ret, ' ', 16);
		return ret;
	}
	hex = ft_itoa_hex_t(value);
	len = strlen(hex);
	memset(ret, '0', 16);
	for (int i = 0; i < len; ++i) {
		ret[16 - len + i] = hex[i];
	}
	free(hex);
	return ret;
}

static char *createOutput(char **adr, char symbolType, char **name)
{
	char *str;

	str = malloc(strlen(*adr) + 3 + strlen(*name) + 1);
	str[strlen(*adr) + 3 + strlen(*name)] = '\0';
	memcpy(str, *adr, 16);
	memcpy(str + 16, "   ", 3);
	str[17] = symbolType;
	memcpy(str + 19, *name, strlen(*name));
	free(*name);
	free(*adr);
	return str;
}

static void getSymbols()
{
	int 			count;
	char			*name;
	char			*adr;
	char 			*output;

	count = data.sym_shdr->sh_size / data.sym_shdr->sh_entsize;
	data.table = (char**)malloc(sizeof(char*) * count);
	for (int i = 1; i < count; ++i) {
		if (data.syms[i].st_name) {
			if (ELF64_ST_TYPE(data.syms[i].st_info) != 4)
			{
				name = strdup(data.file + data.shdr[data.sym_shdr->sh_link].sh_offset + data.syms[i].st_name);
				adr = fillAddr(data.shdr[data.syms[i].st_shndx].sh_addr);
				output = createOutput(&adr, 'X', &name);
				printf("%s\n", output);
				free(output);
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
