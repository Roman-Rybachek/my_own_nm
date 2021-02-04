#include "my_own_nm.h"

t_list			*ft_lstnew(void *content)
{
	t_list		*element;

	if (!(element = (t_list*)malloc(sizeof(t_list) * 1)))
		return (0);
	element->content = content;
	element->next = 0;
	return (element);
}
void			ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	p = *lst;
	if (lst && *lst)
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
	else if (lst)
		*lst = new;
}
void 			ft_lst_clear(t_list **list)
{
	t_list *tmp = NULL;

	while (*list)
	{
		tmp = *list;
		(*list) = (*list)->next;
		free(tmp);
	}
}
int				ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		count;

	p = lst;
	count = 0;
	if (lst)
		count = 1;
	else
		return (count);
	while (p->next)
	{
		count++;
		p = p->next;
	}
	return (count);
}