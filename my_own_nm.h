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

typedef struct	s_data
{
	int			fd;
	struct stat	info;
	void 		*file;
}				t_data;

#endif //MY_OWN_NM_MY_OWN_NM_H
