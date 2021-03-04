//
// Created by rinne on 24.01.2021.
//

#ifndef MY_OWN_NM_H
# define MY_OWN_NM_H

// # include "system_headers/elf.h"
# include <elf.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/mman.h>
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

int					is_arch(void *void_pointer);
int 				is_elf(void *p);

void				arch_handler(void *file);

char				**elf_handler(void *file);
Elf64_Shdr			*getSHdr(void *PtrToELF, int index);
char				*getSName(void *PtrToElf, int index);

char				*ft_itoa_hex(size_t n);
int					ft_darr_len(char **arr);
int					cmpadr(char *s1, char *s2);
int					cmpname(char *s1, char *s2);
void 				sort(char **table, int(*cmp)(char*, char*));
char**			get_bin_files(int argc, char **argv, int *fd);
int 				find_option(int argc, char **argv, char option);
int					ft_tolower(int c);
char				**add_to_darr(char ***darr, char *add);
char				*ft_substr(char const *s, unsigned int start, size_t len);


int					elf_sym_d(Elf64_Shdr *sec);
int 				elf_sym_t(char *name, Elf64_Shdr *sec);
int 				elf_sym_r(Elf64_Shdr *sec);
void 				elf_all_sym_info(void *file, Elf64_Shdr *sec, Elf64_Sym sym);

#endif
