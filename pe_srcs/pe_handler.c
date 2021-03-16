#include "pe_header.h"
#include "pe_sys.h"

char **pe_handler(void *file)
{
	IMAGE_NT_HEADERS64 *hdr;
	DWORD					sym_num;
	void					*sym_tab;

	hdr = file + ((IMAGE_DOS_HEADER*)file)->e_lfanew;
	sym_num = hdr->FileHeader.NumberOfSymbols;
	sym_tab = file + hdr->FileHeader.PointerToSymbolTable;
	printf("%d\n", sym_num);
	return NULL;
}
