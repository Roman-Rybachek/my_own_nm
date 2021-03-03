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
	if (!table || !*table)
		return ;
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
	char		**files = NULL;
	char 		**table = NULL;

	if (!(files = get_bin_files(argc, argv, &fd)))
	{
		printf("%s\n", "error: no program name");
		exit(1);
	}
	for (int i = 0; i < ft_darr_len(files); i++)
	{

		if ((fd = open(files[i], O_RDONLY)) < 0)
		{
			printf("%s\n", "error: bad argument");
			continue ;
		}
		if (ft_darr_len(files) > 1)
			printf("\n%s:\n", files[i]);
		if (fstat(fd, &info) < 0)
			error_return(file, fd, info,"error: fstat error");
		file = mmap(NULL, info.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
		if (file == MAP_FAILED)
			error_return(file, fd, info,"error: mmap error");
	// Сделать обработку arch файлов
		if (is_elf(file))
			table = elf_handler(file);
		sort(table, cmpname);
		if (find_option(argc, argv, 'n'))
			sort(table, cmpadr);
		print_table(table);
		free(table);
		munmap(file, info.st_size);
		close(fd);
	}
	free(files);
	
	return (0);
}
