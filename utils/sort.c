#include "my_own_nm.h"

int			cmpadr(char *s1, char *s2)
{
	int isNull[2];

	isNull[0] = strncmp("                ", s1, 16);
	isNull[1] = strncmp("                ", s2, 16);
	if (isNull[0] == 0 && isNull[1] == 0)
		return (0);
	else if (isNull[0] == 0)
		return (-1);
	else if (isNull[1] == 0)
		return (1);
	else if (strtoll(s1, NULL, 16) > strtoll(s2, NULL, 16))
		return (1);
	else if (strtoll(s1, NULL, 16) < strtoll(s2, NULL, 16))
		return (-1);
	else
		return (0);
}

int				ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	else
		return (c);
}

static int 		is_end(char *t1, char *t2)
{
	if (!*t1 && !*t2)
		return (0);
	else if (!*t1)
		return (-1);
	else if (!*t2)
		return (1);
	else
		return 2;
}

int				cmpname(char *s1, char *s2)
{
	char 	*t1 = s1 + 19;
	char 	*t2 = s2 + 19;
	while (*t1 && *t2)
	{
		while (*t1 == '_' || *t1 == '.')
			t1++;
		while (*t2 == '_' || *t2 == '.')
			t2++;
		if (is_end(t1, t2) != 2)
			return (is_end(t1, t2));
		if (ft_tolower(*t1) < ft_tolower(*t2))
			return (-1);
		else if (ft_tolower(*t1) > ft_tolower(*t2))
			return (1);
		t1++;
		t2++;
	}
	if (is_end(t1, t2) != 2)
		return (is_end(t1, t2));
	return (0);
}

void 		sort(char **table, int(*cmp)(char*, char*))
{
	char	*tmp		= NULL;
	int 	len			= ft_darr_len(table);

	for (int i = 1; i < len; ++i) {
		int j = i;
		while (j && cmp(table[j], table[j - 1]) < 0)
		{
			tmp = table[j];
			table[j] = table[j - 1];
			table[j - 1] = tmp;
			j--;
		}
	}
}
