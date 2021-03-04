#include "my_own_nm.h"

int 		is_elf(void *void_pointer)
{
	char *p;

	p = (char*)void_pointer;
	if (p[EI_MAG0] == 127 && p[EI_MAG1] == 'E' && p[EI_MAG2] == 'L' && p[EI_MAG3] == 'F')
		return (1);
	return (0);
}

int			is_arch(void *void_pointer)
{
	if (!strncmp("!<arch>", (char*)void_pointer, 7))
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
	return name;
}

int			ft_darr_len(char **arr)
{
	int height;

	height = 0;
	while (arr && *arr)
	{
		arr++;
		height++;
	}
	return (height);
}

char **add_to_darr(char ***darr, char *add)
{
	char **new_darr = NULL;

	if (!darr || !*darr)
	{
 		if (!(new_darr = (char**)malloc(2)))
			return (NULL);
		new_darr[0] = add;
		new_darr[1] = NULL;
		return (new_darr);
	}
	else if (!(new_darr = (char**)malloc(ft_darr_len(*darr) + 2)))
		return (NULL);
	for (int i = 0; i < ft_darr_len(*darr); i++)
		new_darr[i] = (*darr)[i];
	new_darr[ft_darr_len(*darr)] = add;
	new_darr[ft_darr_len(*darr) + 1] = NULL;
	return(new_darr);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*start_p;
	size_t	len_s;

	if (!s)
		return (0);
	len_s = strlen(s);
	if (len)
	{
		if (len > len_s - start && start < len_s)
			len = len_s - start;
		else if (start >= len_s)
			len = 0;
	}
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
	{
		free(result);
		return (0);
	}
	start_p = result;
	while (len-- && *s)
		*result++ = s[start++];
	*result = '\0';
	return (start_p);
}