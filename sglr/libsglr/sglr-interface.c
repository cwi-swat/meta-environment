/*

    SGLR - the Scannerless Generalized LR parser.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
/*  $Id$  */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include <aterm1.h>
#include <atb-tool.h>
#include <AsFix.h>

#include <a2toa1.h>
#include <tree-to-dot.h>

#include "sglr.h"
#include "sglr-strings.h"
#include "mem-alloc.h"
#include "parser.h"
#include "forest.h"
#include "rsrc-usage.h"


ATerm  SG_TermToToolbus(ATerm t);
size_t SG_FileSize(char *prg, char *FN);
void   SG_PrintToken(FILE *out, token c);
void   SG_Validate(char *caller);
char  *SG_ReadFile(char *prg, char *err, char *fnam, size_t *fsize);
int    SG_GetCharFromString(void);


/*
 Controlling global behaviour: verbosity, debugging mode, dot
 output of parse forests/parse stacks, and so on.
 */

int  _SG_Mode = 0;

/*  Globals that are private to sglr-interface  */

static char *SG_theText;
static int   SG_textIndex;
static char *the_in_buf_start;
static char *the_in_buf_cur;
static char *the_in_buf_end;

/*
    |SGinitParser| initializes the parser's operating mode to a
    sensible default
 */

void  SGinitParser(ATbool toolbus_mode)
{
  if(toolbus_mode) {
    SG_TOOLBUS_ON();
  }
  SG_OUTPUT_ON();
  SG_FILTER_ON();
  SG_BINARY_ON();
  SG_CYCLE_ON();
/*
  SG_POSINFO_ON();
 */
}

void SGshowMode()
{
  ATfprintf(stderr, "TOOLBUS:     %s\n", SG_TOOLBUS?"y":"n");
  ATfprintf(stderr, "ERROR:       %s\n", SG_ERROR?"y":"n");
  ATfprintf(stderr, "VERBOSE:     %s\n", SG_VERBOSE?"y":"n");
  ATfprintf(stderr, "DEBUG:       %s\n", SG_DEBUG?"y":"n");
  ATfprintf(stderr, "SHOWSTAT:    %s\n", SG_SHOWSTAT?"y":"n");
  ATfprintf(stderr, "OUTPUT:      %s\n", SG_OUTPUT?"y":"n");
  ATfprintf(stderr, "ASFIX1:      %s\n", SG_ASFIX1?"y":"n");
  ATfprintf(stderr, "BINARY:      %s\n", SG_BINARY?"y":"n");
  ATfprintf(stderr, "DOTOUT:      %s\n", SG_DOTOUT?"y":"n");
  ATfprintf(stderr, "NOLEX:       %s\n", SG_NOLEX?"y":"n");
  ATfprintf(stderr, "SHOWSTACK:   %s\n", SG_SHOWSTACK?"y":"n");
  ATfprintf(stderr, "FILTER:      %s\n", SG_FILTER?"y":"n");
  ATfprintf(stderr, "STARTSYMBOL: %s\n", SG_STARTSYMBOL?"y":"n");
  ATfprintf(stderr, "GC:          %s\n", SG_GC?"y":"n");
  ATfprintf(stderr, "CYCLE:       %s\n", SG_CYCLE?"y":"n");
  ATfprintf(stderr, "POSINFO:     %s\n", SG_POSINFO?"y":"n");
}

/**  The ToolBus API functions  **/

ATerm SGgetTopSymbols(char *L)
{
  parse_table *pt = NULL;
  production   pr;
  int          l;
  char	    *sort;
  ATerm      ret = (ATerm) ATempty;

  if(!(pt = SG_LookupParseTable(L))) {
    return SG_TOOLBUS
      ? SG_TermToToolbus(ATmake("language-not-available(<str>)", L))
      : (ATerm) NULL;
  }


  for(l=SG_PROD_START; l < (SG_PROD_START + pt->numprods); l++) {
    if((pr = SG_LookupProduction(pt, SG_SETLABEL(l)))) {
      sort = SG_ProdSort(pr);
      if(strcmp(sort, SG_SAFE_STRING(NULL))) {
        IF_DEBUG(ATfprintf(SG_log(), "Start symbol: %s\n", sort));
        ret = (ATerm) ATinsert((ATermList) ret,
                               ATmake("startsymbol(<str>)", sort));
      }
    }
  }
  ret = ATmake("startsymbols(<str>,[<list>])", L, ret);

  return SG_TOOLBUS
    ? SG_TermToToolbus(ret)
    :                  ret;
}


/*
 The function |SGopenLanguageFromTerm| initializes the parse table for
 language |L| from the term |tbl|.
 */

ATerm SGopenLanguageFromTerm(char *prgname, char *L, ATerm tbl)
{
  parse_table *pt = NULL;

  if(!(pt = SG_LookupParseTable(L))) {
    IF_STATISTICS(fprintf(SG_log(), "Language: %s\n", L); SG_Timer());

    pt = SG_BuildParseTable((ATermAppl) tbl);

    IF_STATISTICS(fprintf(SG_log(),
                          "Obtaining parse table for %s took %.4fs\n",
                          L, SG_Timer()));

    if(pt)
      SG_SaveParseTable(L, pt);
  }

  IF_DEBUG(SGgetTopSymbols(L));

  return SG_TOOLBUS
    ? SG_TermToToolbus(ATmake(pt ?  "language-opened(<str>,<str>)"
                                 :  "language-not-opened(<str>,<str>)",
                               L, L))
    : (ATerm) (pt ? ATempty : NULL);
}


/*
 The function |SGopenLanguage| initializes the parse table for language |L|
 from the file |FN|.
 */

ATerm SGopenLanguage(char *prgname, char *L, char *FN)
{
  parse_table *pt;

  if(!L || !FN) {
    return SG_TOOLBUS
      ? SG_TermToToolbus(ATmake("language-not-opened(<str>,<str>)", "", ""))
      : (ATerm) NULL;
  }

  SG_Validate("SGopenLanguage");
  IF_VERBOSE(
    if(FN) ATwarning("%s: opening parse table %s\n", prgname, SG_SAFE_STRING(FN))
  );
  if(!(pt = SG_LookupParseTable(L))) {
    pt = SG_AddParseTable(prgname, L, FN);
  }

  IF_DEBUG(SGgetTopSymbols(L));

  return SG_TOOLBUS
    ? SG_TermToToolbus(ATmake(pt ?  "language-opened(<str>,<str>)"
                                 :  "language-not-opened(<str>,<str>)",
                               L, FN))
    : (ATerm) (pt ? ATempty : NULL);
}

/*
 |SGcloseLanguage| discards the parse table for language |L|
 */

ATerm SGcloseLanguage(char *prgname, char *L)
{
  SG_Validate("SGcloseLanguage");
  if(SG_LookupParseTable(L)) {
    IF_VERBOSE(ATwarning("%s: closing language %s\n", prgname, SG_SAFE_STRING(L)));
    SG_RemoveParseTable(L);
    return SG_TermToToolbus(ATmake("language-closed(<str>)", SG_SAFE_STRING(L)));
  }
  return SG_TermToToolbus(ATmake("language-not-open(<str>)", SG_SAFE_STRING(L)));
}

/*
 The function |SGreOpenLanguage| initializes the parse table for language |L|
 from the file |FN|.
 */

ATerm SGreOpenLanguage(char *prgname, char *L, char *FN)
{
  SG_Validate("SGreOpenLanguage");
  IF_VERBOSE(
    if(FN) ATwarning("%s: (re)opening parse table %s\n", prgname, SG_SAFE_STRING(L))
  );
  SGcloseLanguage(prgname, L);
  return SGopenLanguage(prgname, L, FN);
}


/*
 The function |SGparseString| parses the text in string |S| with the
 parse table for language |L|.  The string is saved in the global
 variable |SG_theText|, which is accessed through the function
 |SG_GetCharFromString|.  This the function that is passed to the
 parser.  The end of string character |'\0'| is converted into the end
 of file value |SG_EOF|.

 Because the string passed to |SGparseString| might be a string that was
 contained in a term, we have to save it from being garbage collected.
 This is done by duplicating it.
 */

ATerm SGparseString(char *L, char *G, char *S)
{
  ATerm t;
  parse_table *pt;

  if(!(pt = SG_LookupParseTable(L))) {
    return NULL;
  }
  SG_Validate("SGparseString");
  SG_theText   = strdup(S);
  SG_textIndex = 0;
  t = (ATerm) SG_Parse(pt, G?(*G?G:NULL):NULL, SG_GetCharFromString);
  free(SG_theText);
  return t;
}


ATerm SGparseStringAsAsFix2(char *L, char *G, char *S)
{
  ATerm t;

  SG_ASFIX1_OFF();
  t = SGparseString(L, G, S);

  return SG_TermToToolbus(ATBpack(t));
}

ATerm SGparseStringAsAsFix1(char *L, char *G, char *S)
{
  ATerm t;

  SG_ASFIX1_ON();

  t = SGparseString(L, G, S);

  if(!SGisParseError(t)) {
    t = (ATerm) ATmakeAppl1(SG_ParseTreeAF1_AFun, ATBpack(t));
  }

  return SG_TermToToolbus(t);
}

/*
 The function |SGparseFile| parses the text in file |FN| with the
 parse table for language |L|.  The function |SG_GetChar| returns
 the next char from a file buffer, and |SG_UnGetChar| is its counterpart.
 These functions are used to instantiate the buffer parameter function
 for the parser, and for lookahead restriction handling.
 */


/*
 If either no filename or `-' is specified, standard input is used.
 */

ATerm SGparseFile(char *prgname, char *L, char *G, char *FN)
{
  forest ret;
  size_t ntok;
  parse_table *pt;

  SG_Validate("SGparseFile");
  if((pt = SG_LookupParseTable(L)) == NULL) {
    IF_VERBOSE(ATwarning("no such parse table (%s)\n", SG_SAFE_STRING(L)));
    return NULL;
  }

  if((the_in_buf_start = SG_ReadFile(prgname, NULL, FN, &ntok)) == NULL) {
    return NULL;
  }
  the_in_buf_end = the_in_buf_cur = the_in_buf_start;
  the_in_buf_end += ntok;

  IF_VERBOSE(ATwarning("%s: parsing file %s (%d tokens)\n", prgname, FN, ntok));
  ret = SG_Parse(pt, G?(*G?G:0):NULL, SG_GetChar);
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

  if(!SGopenLanguage(prg, ptblfil, ptblfil)) {
    return NULL;
  }
  return SGtermToFile(prg, SGparseFile(prg, ptblfil, sort, infil), outfil);
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


/*
  A few privates...
 */


int SG_GetCharFromString(void)
{
  if (SG_theText[SG_textIndex] == '\0')
    return SG_EOF;

  return (unsigned char) SG_theText[SG_textIndex++];
}

/*
 The ToolBus interface...
 */

ATerm SG_TermToToolbus(ATerm t)
{
  SG_InitPTGlobals();  /*  Make REALLY sure the PT globals are initialised  */

  return SG_TOOLBUS
    ? (ATerm) ATmakeAppl1(SG_SndValue_AFun, t)
    : t;
}


FILE  *SG_Log = NULL;

FILE  *SG_OpenLog(char *prg, char *fnam)
{
  if (SG_Log)
    return SG_Log;

  if (!fnam || !strcmp(fnam, ""))
    fnam = ".sglr-log";
  if (!(SG_Log = fopen(fnam, "w"))) {
    ATerror("%s%sCannot create logfile %s\n",  SG_COND_STRING(prg), prg?": ":"", fnam);
  }
  IF_VERBOSE(ATwarning("%s%slogging to %s\n",  SG_COND_STRING(prg), prg?": ":"", fnam));
  return SG_Log;
}

FILE  *SG_log(void)
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

/*
 |SG_PrintToken| prints token |c| on file |out|
 */

void SG_PrintToken(FILE *out, token c)
{
  int i = SG_GETTOKEN(c);

  if(i != SG_EOF &&isgraph(i)) {
    fprintf(out, "%c", i);
  } else {
    switch(i) {
      case SG_EOF:
        fprintf(out, "EOF");
        break;
      case '\t':
        fprintf(out, "\\t");
        break;
      case '\n':
        fprintf(out, "\\n");
        break;
      case '\r':
        fprintf(out, "\\r");
        break;
      default:
        fprintf(out, "\\%d", i);
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
    if(!SG_log()) {
      ATwarning("Warning: implicitly opening logfile\n");
      SG_OpenLog(caller, ".sglr-log");
    }
  );
  if(SG_SHOWSTACK && !SG_StackDotOut(NULL)) {
    ATwarning("Warning: implicitly choosing naming scheme for stack dotfiles\n");
    SG_StackDotOut("stk-");
  }
}


/*  The function |SGopenFile| tries to open a named file for reading.  */

FILE *SG_OpenFile(char *prgname, char *std_error, char *FN)
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

char *SG_ReadFile(char *prg, char *err, char *fnam, size_t *fsize)
{
  FILE   *in;
  char   *buf;

  IF_STATISTICS(SG_Timer());

  *fsize = 0L;
  if((in = SG_OpenFile(prg, err, fnam)) == NULL) {
    return NULL;
  }
  if(in != stdin) {
    *fsize = SG_FileSize(prg, fnam);
    buf = SG_Malloc(1, *fsize);
    if(*fsize != fread(buf, 1, *fsize, in)) {
      ATerror("%s: error reading %s\n", prg, fnam);
    }
    SG_CloseFile(in);
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
  IF_STATISTICS(fprintf(SG_log(), "Read %ld input tokens from %s in %.6fs\n",
                        (long) *fsize, fnam, SG_Timer()));

  return buf;
}

void SG_CloseFile(FILE *fd)
{
  if(fd != stdin)
    fclose(fd);
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
