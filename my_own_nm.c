#include "my_own_nm.h"

int 	error_return(void *file, int fd, struct stat info, const char *err)
{
	printf("%s\n", err);

	if (file != NULL)
		munmap(file, info.st_size);
	if (fd > 0)
		close(fd);
	exit(1);
}

int		main(int argc, char **argv)
{
	int			fd;
	void		*file;
	struct stat	info;
	char 		**table;

	if (argc != 2)
		error_return(file, fd, info, "error: bad number of arguments");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		error_return(file, fd, info,"error: bad argument");
	if (fstat(fd, &info) < 0)
		error_return(file, fd, info,"error: fstat error");
	file = mmap(NULL, info.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (file == MAP_FAILED)
		error_return(file, fd, info,"error: mmap error");
	if (is_elf(file))
		table = elf_handler(file);
	for (int i = 0; table[i]; ++i) {
		printf("%s\n", table[i]);
	}

	munmap(file, info.st_size);
	close(fd);
	return (0);
}
