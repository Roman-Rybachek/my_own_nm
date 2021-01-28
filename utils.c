#include "my_own_nm.h"

int 	is_elf(void *void_pointer)
{
	char *p;

	p = (char*)void_pointer;
	if (p[EI_MAG0] == 127 && p[EI_MAG1] == 'E' && p[EI_MAG2] == 'L' && p[EI_MAG3] == 'F')
		return (1);
	return (0);
}
