#include "my_own_nm.h"

void 	get_prog_name(int argc, char **argv, int *fd)
{
	if (argc < 2)
	{
		printf("%s\n", "error: bad number of arguments");
		exit(1);
	}
	for (int i = 1; i < argc; ++i) {
		if (argv[i][0] != '-')
		{
			if ((*fd = open(argv[i], O_RDONLY)) < 0)
			{
				printf("%s\n", "error: bad argument");
				exit(1);
			}
			return ;
		}
	}
	printf("%s\n", "error: no program name");
	exit(1);
}

int 	find_option(int argc, char **argv, char option)
{
	for (int i = 1; i < argc; ++i) {
		if (argv[i][0] != '-' || argv[i][1] == '-' || strlen(argv[i]) == 1)
			continue ;
		if (strchr(argv[i] + 1, option))
			return (1);
	}
	return (0);
}