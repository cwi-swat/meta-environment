#ifndef _C_CODE_H
#define _C_CODE_H

void ToC_code(ATbool parse_io,
	      ATbool keep_annos,
	      const char* name, PT_ParseTree ptCcode, ATerm parsetable,
	      FILE *file, const char* compiler_version);

#endif

