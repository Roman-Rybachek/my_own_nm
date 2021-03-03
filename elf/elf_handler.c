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
	hex = ft_itoa_hex(value);
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

	if (!(str = malloc(strlen(*adr) + 3 + strlen(*name) + 1)))
        exit(1);
	str[strlen(*adr) + 3 + strlen(*name)] = '\0';
	if (!strchr("U", symbolType))
		memcpy(str, *adr, 16);
	else
		memset(str, ' ', 16);
	memcpy(str + 16, "   ", 3);
	str[17] = symbolType;
	memcpy(str + 19, *name, strlen(*name));
	free(*name);
	free(*adr);
	return str;
}
static char symbolType(void *file, Elf64_Sym *sym, int i)
{
	char *name = getSName(file, sym[i].st_shndx);
	int	bind = ELF64_ST_BIND(sym[i].st_info);
	int type = ELF64_ST_TYPE(sym[i].st_info);
	char ret = '!';
	Elf64_Shdr *sec = getSHdr(file, sym[i].st_shndx);

	if (elf_sym_d(sec))
		ret = 'D';
	if (elf_sym_t(name, sec))
		ret = 'T';
	if (elf_sym_r(sec))
		ret = 'R';
	if (sym[i].st_shndx == SHN_UNDEF)
		ret = 'U';
	if (sym[i].st_shndx == SHN_ABS)
		ret = 'A';
	if (sym[i].st_shndx == SHN_COMMON)
		ret = 'C';
	if (bind == 2 && type == 1)
		ret = 'V';
	if (bind == 2 && type != 1)
		ret = 'W';
	if(!strcmp(name, ".bss"))
		ret = 'B';
	if(!strcmp(name, ".debug"))
		ret = 'N';

	if (bind == 0 || (bind == 2 && !sym[i].st_value))
		ret = ft_tolower(ret);

	// g G i N p s S u - ?

	return ret;
}
static void getSymbols(void *file, Elf64_Sym *sym, int curSHdr, t_list **lst)
{
	int 			count;
	char			*name;
	char			*adr;
	char 			*output;
	Elf64_Shdr 		*shdr;

	shdr = getSHdr(file, curSHdr);
	count = shdr->sh_size / shdr->sh_entsize;
	for (int i = 1; i < count; ++i) {
		if (sym[i].st_name) {
			if (ELF64_ST_TYPE(sym[i].st_info) != 4)
			{
				name = strdup(file + getSHdr(file, shdr->sh_link)->sh_offset + sym[i].st_name);
				adr = fillAddr(sym[i].st_value);
				output = createOutput(&adr, symbolType(file, sym, i), &name);
				ft_lstadd_back(lst, ft_lstnew(output));
			}
		}
	}
}
char **create_table(t_list **lst)
{
	char		**table;
	t_list		*tmp_list;

	if (!(table = (char**)malloc(sizeof(char*) * (ft_lstsize(*lst) + 1))))
		exit(1);
	table[ft_lstsize(*lst)] = NULL;
	tmp_list = *lst;
	for (int i = 0; i < ft_lstsize(*lst); ++i) {
		table[i] = (char*)tmp_list->content;
		tmp_list = tmp_list->next;
	}
	ft_lst_clear(lst);
	return table;
}
char **elf_handler(void *file)
{
	Elf64_Ehdr	*hdr;
	Elf64_Sym	*sym;
	t_list		*lst;

	lst = NULL;
	hdr = (Elf64_Ehdr*)file;
	sym = NULL;
	for (int i = 1; i < hdr->e_shnum; ++i) {
		Elf64_Shdr *c = getSHdr(file, i);
		if (c->sh_type == SHT_SYMTAB) {
			sym = (Elf64_Sym*)(file + getSHdr(file, i)->sh_offset);
			getSymbols(file, sym, i, &lst);
		}
	}
	return (create_table(&lst));
}
