#include "pe_header.h"



int 		is_pe(void *void_pointer)
{
	char *p;

	p = (char*)void_pointer;
	if (p[0] == 'M' && p[1] == 'Z')
		return (1);
	return (0);
}
