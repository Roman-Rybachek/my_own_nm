#include "my_own_nm.h"

int 	error_return(const char *err)
{
	printf("%s\n", err);

	if (data.file != NULL)
		munmap(data.file, data.info.st_size);
	if (data.fd > 0)
		close(data.fd);
	exit(1);
}

int		main(int argc, char **argv)
{
	int			fd;
	void		*file;
	struct stat	info;

	if (argc != 2)
		error_return("error: bad number of arguments");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		error_return("error: bad argument");
	if (fstat(fd, &info) < 0)
		error_return("error: fstat error");
	file = mmap(NULL, info.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (file == MAP_FAILED)
		error_return("error: mmap error");
	if (is_elf(file))
		elf_handler(file);

	munmap(file, info.st_size);
	close(fd);
	return (0);
}
