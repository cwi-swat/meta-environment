#include <stdio.h>
#include <string.h>
#include <MEPT-utils.h>

void ToC_code(PT_ParseTree ptCcode, FILE *file, const char* compiler_version)
{
  int c, prev = ' ';
  int instring = 0;
  int escaped = 0;
  int firststring = 1;
  static char *buf = NULL;
  char *bp;
  int size3 = 0, size;

  ATfprintf(file, 
    "/* This C code is generated by the AsfSdfCompiler version %s */\n\n",
     compiler_version);
  buf = PT_yieldParseTree(ptCcode);
  size = strlen(buf);

  bp = buf;
  do {
    size3++;
    c = *bp++;
    if ((bp-buf) >= size) {
      fprintf(stderr, "could not find '#' marker, "
              "maybe the reduction failed?\n");
      exit (1);
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
}        


