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
