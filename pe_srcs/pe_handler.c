#include "pe_header.h"
#include "pe_sys.h"

char **pe_handler(void *file)
{
	IMAGE_NT_HEADERS64      *hdr;
	DWORD					sym_num;
	IMAGE_SYMBOL        	*sym_tab_sec;
    IMAGE_SECTION_HEADER    *sec = (IMAGE_SECTION_HEADER*)(file + 0x138);
    char                    *names;
    DWORD                   str_tab_len;
	hdr = file + ((IMAGE_DOS_HEADER*)file)->e_lfanew;
	sym_num = hdr->FileHeader.NumberOfSymbols;

	sym_tab_sec = file + hdr->FileHeader.PointerToSymbolTable;

	names = file + hdr->FileHeader.PointerToSymbolTable + hdr->FileHeader.NumberOfSymbols * IMAGE_SIZEOF_SYMBOL;
	str_tab_len = (DWORD)names;
    for (int i = 2; i < str_tab_len; ) {
//        write(1, &names[i], 1);
        i += printf("%s\n", &names[i]);
//        int f = strlen(&names[i]);
//        i += f;
//        printf("%d\n", f);
    }
	return NULL;
}
