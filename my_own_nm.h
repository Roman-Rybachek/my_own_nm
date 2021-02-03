//
// Created by rinne on 24.01.2021.
//

#ifndef MY_OWN_NM_H
# define MY_OWN_NM_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/mman.h>
# include <elf.h>
# include <string.h>

typedef struct		s_list
{
	void 			*content;
	struct s_list	*next;
}					t_list;


t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void 				ft_lst_clear(t_list **list);
int					ft_lstsize(t_list *lst);

int 				is_elf(void *p);
char				**elf_handler(void *file);
char				*ft_itoa_hex(size_t n);
Elf64_Shdr			*getSHdr(void *PtrToELF, int index);
char				*getSName(void *PtrToElf, int index);

#endif
