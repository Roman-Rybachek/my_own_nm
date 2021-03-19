#include "pe_header.h"
#include "pe_sys.h"

char **pe_handler(void *file)
{
	IMAGE_NT_HEADERS64      *hdr;
	DWORD					sym_num;
	IMAGE_SYMBOL        	*sym_tab_sec;
    IMAGE_SECTION_HEADER    *sec = (IMAGE_SECTION_HEADER*)(file + 0x138);

	hdr = file + ((IMAGE_DOS_HEADER*)file)->e_lfanew;
	sym_num = hdr->FileHeader.NumberOfSymbols;


	sym_tab_sec = file + sizeof(IMAGE_DOS_HEADER) + sizeof(IMAGE_NT_HEADERS64) + sizeof(IMAGE_OPTIONAL_HEADER64) +sizeof(IMAGE_FILE_HEADER)+ hdr->FileHeader.PointerToSymbolTable;

    printf("%d", hdr->OptionalHeader.Magic);

//	printf("%d\n", sym_num);

//    for (DWORD i = 0; i < sym_num; ++i) {
//        if (ft_isprint( sym_tab_sec[i].N.ShortName[0]))
//            printf("%s\n", sym_tab_sec[i].N.ShortName);
//        sym_tab_sec += 1;
//    }
//
//    WORD sec_num = hdr->FileHeader.NumberOfSections;
//    for (int i = 2; i < sec_num; ++i) {
//        printf("%s\n", sec[i].Name);
//    }
	return NULL;
}
