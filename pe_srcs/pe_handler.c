#include "pe_header.h"
#include "pe_sys.h"

char **pe_handler(void *file)
{
	IMAGE_NT_HEADERS64      *hdr;
	DWORD					sym_num;
	IMAGE_SYMBOL        	*sym_tab_sec;
	IMAGE_SYMBOL        	*sym_start;
    IMAGE_SECTION_HEADER    *sec = (IMAGE_SECTION_HEADER*)(file + 0x138);

	hdr = file + ((IMAGE_DOS_HEADER*)file)->e_lfanew;
	sym_num = hdr->FileHeader.NumberOfSymbols;


	sym_tab_sec = file + hdr->FileHeader.PointerToSymbolTable;
	sym_start = sym_tab_sec;
//    printf("%d", hdr->OptionalHeader.Magic);

//	printf("%d\n", sym_num);

    for (DWORD i = 0; i < sym_num; ++i) {
    	if (sym_tab_sec[i].N.Name.Short != 0)
		{
			for (int j = 0; j < 8 && sym_tab_sec[i].N.ShortName[j] != '\0'; ++j) {
				write(1, &sym_tab_sec[i].N.ShortName[j], 1);
			}
			write(1, "\n", 1);
		}
    	else
		{
			printf("%s\n", ((char*)sym_tab_sec) + sym_num * IMAGE_SIZEOF_SYMBOL + sym_tab_sec[i].N.Name.Long);
		}
    	int z = 0;
		for (uint8_t j = 0; j < sym_tab_sec[i].NumberOfAuxSymbols; ++j) {
			z++;
		}
		i += z;
	}
//
//    WORD sec_num = hdr->FileHeader.NumberOfSections;
//    for (int i = 2; i < sec_num; ++i) {
//        printf("%s\n", sec[i].Name);
//    }
	return NULL;
}
