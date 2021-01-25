#include "my_own_nm.h"

t_data	data;

int 	error_return(const char *err)
{
	printf("%s\n", err);

	if (data.file != NULL)
		munmap(data.file, data.info.st_size);
	if (data.fd > 0)
		close(data.fd);
	exit(1);
}

void 	main_logic()
{
	Elf64_Ehdr *header = (Elf64_Ehdr*)data.file;
	header->
}

int		main(int argc, char **argv)
{
	data.fd = 0;
	data.file = NULL;


	if (argc != 2)
		error_return("error: bad number of arguments");
	if ((data.fd = open(argv[1], O_RDONLY)) < 0)
		error_return("error: bad argument");
	if (fstat(data.fd, &data.info) < 0)
		error_return("error: fstat error");
	data.file = mmap(NULL, data.info.st_size, PROT_READ, MAP_PRIVATE, data.fd, 0);
	if (data.file == MAP_FAILED)
		error_return("error: mmap error");

	main_logic();

	munmap(data.file, data.info.st_size);
	close(data.fd);
}
