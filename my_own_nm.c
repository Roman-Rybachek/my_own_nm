#include "my_own_nm.h"

int 	error_return(const char *err)
{
	printf("%s\n", err);
	exit(1);
}

t_data	data;

int		main(int argc, char **argv)
{
	if (argc != 2)
		error_return("error: bad number of arguments");
	if ((data.fd = open(argv[1], O_RDONLY)) < 0)
		error_return("error: bad argument");
	if (fstat(data.fd, &data.file) < 0) {
		close(data.fd);
		error_return("error: fstat error");
	}
}
