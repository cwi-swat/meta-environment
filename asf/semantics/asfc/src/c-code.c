/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <MEPT-utils.h>

/*}}}  */

/*{{{  static void make_header(FILE *file, const char* compiler_version) */

static void make_header(FILE *file, const char* compiler_version)
{
  ATfprintf(file, 
    "/* This C code is generated by the asf compiler version %s */\n\n",
     compiler_version);
}

/*}}}  */
/*{{{  static void make_main(ATbool keep_annos, const char *name, ATbool parseTable, FILE *file) */

static void make_main(ATbool parse_io, ATbool keep_annos, 
		      ATbool keep_layout, const char *name, 
		      ATbool parseTable, FILE *file)
{

  ATfprintf(file, "#ifdef ASF_MAIN\n");

  ATfprintf(file,
	    "int main(int argc, char *argv[])                         \n"
	    "{                                                        \n"
	    "  ATerm bottom;\n"
	    "  setKeepAnnotations(%s);\n"
	    "  setKeepLayout(%s);\n"
	    "  return asc_support_main(&bottom, argc, argv,           \n"
	    "                          register_%s,                   \n"
            "                          resolve_%s,                    \n"
	    "                          init_%s",
	    keep_annos ? "ATtrue" : "ATfalse",
	    keep_layout ? "ATtrue" : "ATfalse",
	    name, name, 
	    name);

  if (parseTable) {
    ATfprintf(file,
	      ", %s_parsetable_baf, %s_parsetable_size", name, name);
  }
  else {
    ATfprintf(file,
	      ", NULL, -1");
  }

  ATfprintf(file, ", %s\n", parse_io ? "ATtrue" : "ATfalse");

  /* \todo remove this statement and update asc-support, etc */
  ATfprintf(file, ", NULL);\n"); /* for backward compatibility */

  ATfprintf(file, "}\n#endif\n");

}

/*}}}  */
  /*{{{  static void make_parsetable(const char *name, FILE *file, ATerm parsetable) */

static size_t make_parsetable(const char *name, FILE *file, ATerm parsetable)
{
  int size;
  unsigned const char *data;
  int rowlength = 8;
  int i;

  if (parsetable != NULL) {
    data = ATwriteToBinaryString(parsetable, &size);

    if (size > 1) {
      fprintf(file, "size_t %s_parsetable_size = %d;\n", name, size);
      fprintf(file, "unsigned const char %s_parsetable_baf[%d] = {\n\t", name, size); 

      for (i = 0; i < size - 1; i++) {
	fprintf(file,"0x%02X, ", (unsigned char) data[i]);

	if (i % rowlength == rowlength-1) {
	  fprintf(file, "\n\t");
	}
      }
    
      fprintf(file, "0x%02X\n};\n", (unsigned char) data[i]);

      return size;
    }
  }

  return 0;
}

/*}}}  */

/*{{{  void ToC_code(name, ptCcode, file, version) */

void ToC_code(ATbool parse_io,
	      ATbool keep_annos,
	      ATbool keep_layout,
	      const char *name, PT_ParseTree ptCcode, ATerm parsetable,
	      FILE *file, const char* compiler_version)
{
  int c, prev = ' ';
  int instring = 0;
  int escaped = 0;
  int firststring = 1;
  size_t tableSize = 0;
  static char *buf = NULL;
  char *bp;
  int size3 = 0, size;

  make_header(file, compiler_version);

  buf = PT_yieldParseTreeToString(ptCcode, ATfalse);
  size = strlen(buf);

  bp = buf;
  do {
    size3++;
    c = *bp++;
    if ((bp-buf) >= size) {
      fprintf(stderr, "could not find '#' marker, "
              "maybe the reduction failed?\n");
      fprintf(file, buf);
      return;
    }
  } while(c != '#');

  while(c != '"') {
    fputc(c, file);
    size3++;
    c = *bp++;
  }
  fputc(' ', file);
  fputc(c, file);
  size3++;    
  c = *bp++;

  while(c != '"') {
    fputc(c, file);
    size3++;
    c = *bp++;
  }
  fputs("\"\n", file);

  do {
    size3++;
    c = *bp++;
    if(c >= 0) {
      if(!instring && c == '\n')
        c = ' ';
      if(!(instring || prev != ' ' || c != ' '))
        ;
      else  
        fputc(c, file);
      prev = c;
    }
    if(instring) {
      if(!escaped && c == '"') {
        instring = 0;
        if(firststring) {
          firststring = 0;
          fputc('\n', file);
        }
      }
      escaped = 0;
      if(!escaped && c == '\\')
        escaped = 1;
    } else {
      if(c == '"')
        instring = 1;
      else {   
        if(c == ';' || c == '}' || c == '{') {
          fputc('\n', file);
          prev = ' ';
        }
      }
    }
  } while(size3 != size);

  tableSize = make_parsetable(name, file, parsetable);
  make_main(parse_io, keep_annos, keep_layout,
		  name, parsetable != NULL ? ATtrue : ATfalse, file);
}        

/*}}}  */
