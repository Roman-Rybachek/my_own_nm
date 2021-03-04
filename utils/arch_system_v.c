#include "my_own_nm.h"

/*
	Смотрим, архив ли.
	Если да, смотрим, есть ли длинные имена. Если есть, берем длину всего участка с этими именами,
	и запоминаем указатель на начало имен.

	Если имя файла начинается с '/', то значит ее имя лежит вначале

	1. Вообщем, мы пропускаем длинные имена, прибавив к указателю их длину. Они начинаются с 8 байта.
	Если там '//', то считываем длину атоем. Затем доходим до '`' и прибавляем два символа, 
	чтобы оказаться в теле.
	2. Далее, мы смотрим длину конкретного файла, т.к. она задана в его "хедере"
	3. Отдаем этот указатель в обработчик. Перепрыгиваем на это число байт и идем дальше.
*/

static int	handle_file(char *p, char *names, int names_len)
{
	int ret_len = 0;
	char *name = NULL;

	if (names)
	{
		name = ft_substr(names + atoi(p), strchr(names + atoi(p), '/'));
		printf("\n%s:\n", name);

		free(name);
	}
}

void			arch_handler(void *file)
{
	char	*long_names = NULL;
	char	*p = (char*)file;
	int 	len_long_names = 0;

	if (!strncmp("//", p + 8, 2))
	{
		len_long_names = atoi(p + 56);
		long_names = p + 68;
		p = p + 68 + len_long_names;
	}
}