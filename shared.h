#ifndef MY_OWN_NM_SHARED_H
#define MY_OWN_NM_SHARED_H


# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/mman.h>
# include <string.h>

// # include "system_headers/elf.h"

typedef struct		s_list
{
	void 			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void 				ft_lst_clear(t_list **list);
int					ft_lstsize(t_list *lst);

char				*ft_itoa_hex(size_t n);
int					ft_darr_len(char **arr);
int					ft_tolower(int c);
char				**add_to_darr(char ***darr, char *add);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int		            ft_isprint(int c);

int					cmpadr(char *s1, char *s2);
int					cmpname(char *s1, char *s2);
void 				sort(char **table, int(*cmp)(char*, char*));
char**				get_bin_files(int argc, char **argv, int *fd);
int 				find_option(int argc, char **argv, char option);
char 				**create_table(t_list **lst);

#endif //MY_OWN_NM_SHARED_H
