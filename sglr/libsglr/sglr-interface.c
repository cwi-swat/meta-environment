/*  $Id$  */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include <aterm1.h>
#include <AsFix.h>

#include <a2toa1.h>
#include <tree-to-dot.h>

#include "sglr.h"
#include "mem-alloc.h"
#include "parser.h"
#include "forest.h"
#include "rsrc-usage.h"

ATerm SG_TermToToolbus(ATerm t);

/*
 Controlling global behaviour: verbosity, debugging mode, dot
 output of parse forests/parse stacks, and so on.
 */

int _SG_Mode = 0;

void  SGinitParser(void)
{
  SG_OUTPUT_ON();
  SG_FILTER_ON();
  SG_BINARY_ON();
  SG_CYCLE_ON();
/*
  SG_POSINFO_ON();
 */
}

/*
 |SG_PrintToken| prints token |c| on file |out|
 */

void SG_PrintToken(FILE *out, token c)
{
  int i = SG_GETTOKEN(c);

  if(i != SG_EOF && isprint(i)) {
    fprintf(out, "'%c'", i);
  } else {
    switch(i) {
      case SG_EOF:
        fprintf(out, "EOF");
        break;
      case '\t':
        fprintf(out, "'\\t'");
        break;
      case '\n':
        fprintf(out, "'\\n'");
        break;
      case '\r':
        fprintf(out, "'\\r'");
        break;
      default:
        fprintf(out, "'\\%d'", i);
        break;
    }
  }
}

/*
 SG_Validate: check the `mode' bits, to make sure that no
 debugging/statistics output is written unless the logging
 file is opened, &c.
 */

void SG_Validate(char *caller)
{
  IF_STATISTICS(
    if(!SGlog()) {
      ATwarning("Warning: implicitly opening logfile\n");
      SGopenLog(caller, ".sglr-log");
    }
  );
  if(SG_SHOWSTACK && !SG_StackDotOut(NULL)) {
    ATwarning("Warning: implicitly choosing naming scheme for stack dotfiles\n");
    SG_StackDotOut("stk-");
  }
}

FILE    *SG_Log = NULL;

FILE  *SGopenLog(char *prg, char *fnam)
{
  if (SG_Log)
    return SG_Log;

  if (!fnam || !strcmp(fnam, ""))
    fnam = ".sglr-log";
  if (!(SG_Log = fopen(fnam, "w"))) {
    ATerror("%s%sCannot create logfile %s\n",  prg?prg:"", prg?": ":"", fnam);
  }
  IF_VERBOSE(ATwarning("%s%slogging to %s\n",  prg?prg:"", prg?": ":"", fnam));
  return SG_Log;
}

FILE  *SGlog(void)
{
  return SG_Log;
}

void SG_CloseLog(void)
{
  if(SG_Log) fclose(SG_Log);
}

size_t SG_FileSize(char *prg, char *FN)
{
  struct stat  statbuf;

  if (!FN || !strcmp(FN, "") || !strcmp(FN, "-"))
    return -1;  /*  We can't tell how many tokens to read  */

  if(stat(FN, &statbuf) < 0) {
    return -1;  /*  We can't tell how many tokens to read, and
    may not be able to read anything... */
  }
  return statbuf.st_size;
}

/*  The function |SGopenFile| tries to open a named file for reading.  */

FILE *SGopenFile(char *prgname, char *std_error, char *FN)
{
  FILE *file;

  if (!FN || !strcmp(FN, "") || !strcmp(FN, "-")) {
    if (!std_error || (FN && !strcmp(FN, "-")))
      return stdin;

    return NULL;
  }

  if (!(file = fopen(FN, "r"))) {
    return NULL;
  }
  return file;
}

/*
 |SGreadFile| opens a named file and reads it into a buffer.
 The buffer is allocated here, but must be disposed by the caller.
 Also returned is the number of bytes actually read, in its fsize
 parameter.
 */

#define SG_BUFCHUNK  65536

char *SGreadFile(char *prg, char *err, char *fnam, size_t *fsize)
{
  FILE   *in;
  char   *buf;

  IF_STATISTICS(SG_Timer());

  *fsize = 0L;
  if((in = SGopenFile(prg, err, fnam)) == NULL) {
    return NULL;
  }
  if(in != stdin) {
    *fsize = SG_FileSize(prg, fnam);
    buf = SG_Malloc(1, *fsize);
    if(*fsize != fread(buf, 1, *fsize, in)) {
      ATerror("%s: error reading %s\n", prg, fnam);
    }
    SGcloseFile(in);
  } else {
    size_t curbufsize = SG_BUFCHUNK;
    register int    c;

    buf = SG_Malloc(1, SG_BUFCHUNK);
    while((c = getc(in)) != EOF) {
      if(*fsize >= curbufsize) {
        curbufsize += SG_BUFCHUNK;
        buf = SG_Realloc(buf, curbufsize, sizeof(char));
      }
      buf[*fsize] = c;
      (*fsize)++;
    }
    buf = SG_Realloc(buf, *fsize, sizeof(char));
  }
  IF_STATISTICS(fprintf(SGlog(), "Read %ld input tokens from %s in %.6fs\n",
                        (long) *fsize, fnam, SG_Timer()));

  return buf;
}

void SGcloseFile(FILE *fd)
{
  if(fd != stdin)
    fclose(fd);
}

/*
 The function |SGopenLanguage| initializes the parse table for language |L|
 from the file |FN|.
 */

ATerm SGopenLanguage(char *prgname, int conn, char *L, char *FN)
{
  parse_table *table;

  SG_Validate("SGopenLanguage");
  IF_VERBOSE(if(FN) ATwarning("%s: opening parse table %s\n", prgname, FN));
  if(!(table = SG_LookupParseTable(L, ATtrue)))
    table = SG_AddParseTable(prgname, L, FN);

  return SG_TermToToolbus(ATmake(table ?  "language-opened(<str>,<str>)"
                                       :  "language-not-opened(<str>,<str>)",
                                 L, FN));
}

/*
 |SGcloseLanguage| discards the parse table for language |L|
 */

ATerm SGcloseLanguage(char *prgname, int conn, char *L)
{
  SG_Validate("SGcloseLanguage");
  if(SG_LookupParseTable(L, ATtrue)) {
    IF_VERBOSE(ATwarning("%s: closing language %s\n", prgname, L));
    SG_RemoveParseTable(L);
    return SG_TermToToolbus(ATmake("language-closed(<str>)", L));
  }
  return SG_TermToToolbus(ATmake("language-not-open(<str>)", L));
}

/*
 The function |SGreOpenLanguage| initializes the parse table for language |L|
 from the file |FN|.
 */

ATerm SGreOpenLanguage(char *prgname, int conn, char *L, char *FN)
{
  SG_Validate("SGreOpenLanguage");
  IF_VERBOSE(if(FN) ATwarning("%s: (re)opening parse table %s\n", prgname, FN));
  SGcloseLanguage(prgname, conn, L);
  return SGopenLanguage(prgname, conn, L, FN);
}


void SG_Dump_ATtable(ATermTable t, char *s)
{
  ATerm     key;
  ATermList keys;
  int       i=0;

  if(s)
    ATwarning("%s\n", s);

  if(t) for(keys = ATtableKeys(t); keys && !ATisEmpty(keys);
            keys=ATgetNext(keys)) {
    key = ATgetFirst(keys);
    if(ATgetType(key) != AT_INT)
      ATwarning("%d\t%t: %t\n", i++, key,
                SG_AmbTable(SG_AMBTBL_LOOKUP_CLUSTER,
                            SG_AmbTable(SG_AMBTBL_LOOKUP_INDEX, key, NULL),
                            NULL));
  }
}

/*
 The function |SGparseString| parses the text in string |S| with the
 parse table for language |L|.  The string is saved in the global
 variable |SG_theText|, which is accessed through the function
 |SG_GetCharFromString|.  This the function that is passed to the
 parser.  The end of string character |'\0'| is converted into the end
 of file value |EOF|.
 */

static char *SG_theText;
int         SG_textIndex;

int SG_GetCharFromString(void)
{
  if (SG_theText[SG_textIndex] == '\0')
    return SG_EOF;

  return (unsigned char) SG_theText[SG_textIndex++];
}

/*
 Because the string passed to |SGparseString| might be a string that was
 contained in a term we have to save it from being garbage collected.
 This is done now by making a duplicate of it, which is neither efficient
 nor clean.
 */

ATerm SGparseString(int conn, char *L, char *G, char *S)
{
  ATerm t;

  SG_Validate("SGparseString");
  SG_theText   = strdup(S);
  SG_textIndex = 0;
  t = (ATerm) SG_Parse(SG_LookupParseTable(L,ATfalse), G?(*G?G:NULL):NULL,
                       SG_GetCharFromString);
  free(SG_theText);
  return t;
}

/*
 The ToolBus interface functions...
 */

ATerm SG_TermToToolbus(ATerm t)
{
  return (ATerm) ATmakeAppl1(SG_SndValue_AFun, t);
}

ATerm SGparseStringAsAsFix2(int conn, char *L, char *G, char *S)
{
  SG_ASFIX1_OFF();
  return SG_TermToToolbus(SGparseString(conn, L, G, S));
}

ATerm SGparseStringAsAsFix1(int conn, char *L, char *G, char *S)
{
  ATerm t;

  SG_ASFIX1_ON();

  if(!SGisParseError(t = SGparseString(conn, L, G, S)))
    t = (ATerm) ATmakeAppl1(SG_ParseTreeAF1_AFun, t);

  return SG_TermToToolbus(t);
}

/*
 The function |SGparseFile| parses the text in file |FN| with the
 parse table for language |L|.  The function |SG_GetChar| returns
 the next char from a file buffer, and |SG_UnGetChar| is its counterpart.
 These functions are used to instantiate the buffer parameter function
 for the parser, and for lookahead restriction handling.
 */

char *the_in_buf_start;
char *the_in_buf_cur;
char *the_in_buf_end;

int SG_GetChar(void)
{
  if(the_in_buf_cur >= the_in_buf_end)
    return SG_EOF;

  return (unsigned char) *the_in_buf_cur++;
}

void SG_UnGetChar(void)
{
  assert(the_in_buf_cur > the_in_buf_start);
  the_in_buf_cur--;
}

void SG_ReportErrLine(int line, int col)
{
  char *errmsg = the_in_buf_cur, linestr[16];
  int  currlen=0, maxlen, prefixlen;

  snprintf(linestr, 16, "%d", line);
  prefixlen=strlen(linestr)+2;
  maxlen=80-prefixlen;

  if(*errmsg == '\n') {
    errmsg--;
  }
  while(currlen<maxlen && errmsg>the_in_buf_start && *errmsg!='\n') {
    currlen++; errmsg--;
  }

  fprintf(stderr, "%d: ", line);
  while(errmsg <= the_in_buf_end && *errmsg != '\n' && maxlen--)
    fprintf(stderr, "%c", *errmsg++);
  fprintf(stderr, "\n%*.*s%*s\n", prefixlen, prefixlen, "", col, "^");
}

/*
 If either no filename or `-' is specified, standard input is used.
 */

ATerm SGparseFile(char *prgname, int conn, char *L, char *G, char *FN)
{
  forest ret;
  size_t ntok;

  SG_Validate("SGparseFile");
  if((the_in_buf_start = SGreadFile(prgname, NULL, FN, &ntok)) == NULL) {
    return NULL;
  }
  the_in_buf_end = the_in_buf_cur = the_in_buf_start;
  the_in_buf_end += ntok;
  IF_VERBOSE(ATwarning("%s: parsing file %s (%d tokens)\n", prgname, FN, ntok));
  ret = SG_Parse(SG_LookupParseTable(L, ATfalse), G?(*G?G:0):NULL, SG_GetChar);
  SG_Free(the_in_buf_start);
  return (ATerm) ret;
}

/*
 Opening a file for writing and write a term to it.
 */

ATerm SGtermToFile(char *prgname, ATerm t, char *FN)
{
  FILE *output_file;

  if(t == NULL) {
    return NULL;
  }

  if (SG_OUTPUT && strcmp(FN, "/dev/null")) {
    if (!strcmp(FN, "") || !strcmp(FN, "-"))
      output_file = stdout;
    else if (!(output_file = fopen(FN, "w"))) {
      ATerror("%s: cannot create %s\n", prgname, FN);
    } IF_VERBOSE(ATwarning("%s: writing %s to %s\n", prgname,
                           SG_ERROR?"error output":"parse result", FN));
    if(SG_BINARY) {
      ATwriteToBinaryFile(t, output_file);
    } else {
      ATwriteToTextFile(t, output_file);
      putc('\n', output_file);                /*  For convenience; sosumi!  */
    }

    if(output_file != stdout)
      fclose(output_file);
    else
      fflush(output_file);                    /*  Avoid mixing stdout/stderr  */
  }
  return t;
}

/*
 Parse using Language File -- the core function for stand-alone use.
 It opens (or reuses) the parse table, parses the input file, writes
 the parse tree to the output file and returns the parse result.
 */

ATerm SGparseFileUsingTable(char *prg, char *ptblfil, char *sort,
                            char *infil, char *outfil)
{
  if(infil && *infil && strcmp(infil,"-") && (int)SG_FileSize(prg, infil)<0) {
    ATerror("%s: cannot open %s\n", prg, infil);
  }

  SGopenLanguage(prg, 0, ptblfil, ptblfil);
  return SGtermToFile(prg, SGparseFile(prg, 0, ptblfil, sort, infil), outfil);
}

/*
 Check parser output to see if it's a valid parse tree, or a parse error
 */

ATbool SGisParseTree(ATerm t)
{
  if(SG_ASFIX1)
    return ATgetAFun(t) == SG_Term_AFun;
  else
    return ATgetAFun(t) == SG_ParseTree_AFun;

}

ATbool SGisParseError(ATerm t)
{
  return ATgetAFun(t) == SG_ParseError_AFun;
}
