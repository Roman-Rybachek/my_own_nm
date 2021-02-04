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

static void 	print_table(char **table)
{
	for (int i = 0; table[i]; ++i) {
		printf("%s\n", table[i]);
		free(table[i]);
	}
}

int		main(int argc, char **argv)
{
	int			fd;
	struct stat	info;
	void		*file = NULL;
	char 		**table = NULL;

	get_prog_name(argc, argv, &fd);
	if (fstat(fd, &info) < 0)
		error_return(file, fd, info,"error: fstat error");
	file = mmap(NULL, info.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (file == MAP_FAILED)
		error_return(file, fd, info,"error: mmap error");
	if (is_elf(file))
		table = elf_handler(file);
	if (find_option(argc, argv, 'n'))
		sort(table, cmpadr);
	print_table(table);
	free(table);
	munmap(file, info.st_size);
	close(fd);
	return (0);
}
