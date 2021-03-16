//
// Created by rinne on 16.03.2021.
//

#ifndef MY_OWN_NM_PE_H
#define MY_OWN_NM_PE_H
#include <stdint.h>

#define IMAGE_DOS_SIGNATURE    0x5A4D     /* MZ   */
#define IMAGE_OS2_SIGNATURE    0x454E     /* NE   */
#define IMAGE_OS2_SIGNATURE_LE 0x454C     /* LE   */
#define IMAGE_OS2_SIGNATURE_LX 0x584C     /* LX */
#define IMAGE_VXD_SIGNATURE    0x454C     /* LE   */
#define IMAGE_NT_SIGNATURE     0x00004550 /* PE00 */

#define uint16_t WORD
#difine uint32_t DWORD

typedef struct 	_IMAGE_DOS_HEADER {
	WORD  		e_magic;      /* 00: MZ Header signature */
	WORD 		e_cblp;       /* 02: Bytes on last page of file */
	WORD  		e_cp;         /* 04: Pages in file */
	WORD  		e_crlc;       /* 06: Relocations */
	WORD  		e_cparhdr;    /* 08: Size of header in paragraphs */
	WORD  		e_minalloc;   /* 0a: Minimum extra paragraphs needed */
	WORD  		e_maxalloc;   /* 0c: Maximum extra paragraphs needed */
	WORD  		e_ss;         /* 0e: Initial (relative) SS value */
	WORD  		e_sp;         /* 10: Initial SP value */
	WORD  		e_csum;       /* 12: Checksum */
	WORD  		e_ip;         /* 14: Initial IP value */
	WORD  		e_cs;         /* 16: Initial (relative) CS value */
	WORD  		e_lfarlc;     /* 18: File address of relocation table */
	WORD  		e_ovno;       /* 1a: Overlay number */
	WORD  		e_res[4];     /* 1c: Reserved words */
	WORD  		e_oemid;      /* 24: OEM identifier (for e_oeminfo) */
	WORD  		e_oeminfo;    /* 26: OEM information; e_oemid specific */
	WORD  		e_res2[10];   /* 28: Reserved words */
	DWORD 		e_lfanew;     /* 3c: Offset to extended header */
} 				IMAGE_DOS_HEADER;



#endif //MY_OWN_NM_PE_H
