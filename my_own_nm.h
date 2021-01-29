//
// Created by rinne on 24.01.2021.
//

#ifndef MY_OWN_NM_H
# define MY_OWN_NM_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/mman.h>
# include <elf.h>
# include <string.h>


typedef struct	s_data
{
	int			fd;
	struct stat	info;
	void 		*file;
}				t_data;

int 	is_elf(void *p);
void 	elf_handler();

t_data	data;

#endif
