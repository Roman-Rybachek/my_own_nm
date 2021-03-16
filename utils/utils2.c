#include "shared.h"

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
