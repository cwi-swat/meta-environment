/*
   %% $Id$
   %%
   %% Main program source for the Scannerless Generalized LR Parser SGLR.

   \section{An Application (main.c)}
   \label{main.c}

   In this section we define an application of the parse table and
   parse functions defined in the previous sections. The program can
   run in two modes: (1) As a standalone tool that reads a parse table
   and parses the text in a file given that parse table. (2) Connected
   to the ToolBus. In this mode several parse tables can be read in
   and several strings can be parsed using any of the parse
   tables. This saves the time of loading the parse table for each
   string.

*/

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#include <aterm1.h>
#include <AsFix.h>

#include "getopt.h"
#include "sglr.h"

#include "parser.h"
#include "tree-to-dot.h"


/*
    Controlling global behaviour: verbosity, debugging mode, dot
    output of parse forests/parse stacks, and so on
 */

int SG_Mode;

/*
    SG_Validate: check the `mode' bits, to make sure that no
    debugging/statistics output is written unless the logging
    file is opened, &c.
 */

void SG_Validate(char *caller)
{
  if((SG_DEBUG || SG_SHOWSTAT) && !SGlog()) {
    ATfprintf(stderr, "Warning: implicitly opening logfile\n");
    SGopenLog(caller, ".implicit-log");
  }
  if(SG_SHOWSTACK && !SG_StackDotOut(NULL)) {
    ATfprintf(stderr, "Warning: implicitly choosing naming scheme for stack dotfiles\n");
    SG_StackDotOut("stk-");
  }

}

/*
  \paragraph{Open Log}
*/

FILE    *SG_Log = NULL;

FILE  *SGopenLog(char *prg, char *fnam)
{
  if (SG_Log != NULL) return SG_Log;
  if (fnam == NULL || strcmp(fnam, "") == 0)
    fnam = ".parse-log";
  if ((SG_Log = fopen(fnam, "w")) == NULL) {
    ATfprintf(stderr, "%s%sCannot create logfile %s\n",
              prg?prg:"", prg?": ":"", fnam);
    exit(1);
  }
  if(SG_VERBOSE)
    ATfprintf(stderr, "%s%slogging to %s\n",  prg?prg:"", prg?": ":"", fnam);
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

  if (FN == NULL || strcmp(FN, "") == 0 || !strcmp(FN, "-"))
    return -1;	/*  We can't tell how many tokens to read  */

  if(stat(FN, &statbuf) < 0) {
/*
    ATfprintf(stderr, "%s: cannot stat() %s\n", prg, FN);
 */
    return -1;  /*  We can't tell how many tokens to read  */
                /*  We probably will not be able to open it either.. */
  }
  return statbuf.st_size;
}

/*
  \paragraph{Open File}

  The function |SGopenFile| tries to open a named file for reading and
  gives an appropriate error message if this fails.
*/
FILE *SGopenFile(char *prgname, char *std_error, char *FN)
{
  FILE *file;

  if (FN == NULL || strcmp(FN, "") == 0 || !strcmp(FN, "-")) {
      if (std_error == NULL || (FN && !strcmp(FN, "-")))
        return stdin;

      ATfprintf(stderr,"%s: %s\n", prgname, std_error);
      exit(1);
  }

  if ((file = fopen(FN, "r")) == NULL) {
      ATfprintf(stderr, "%s: cannot open %s\n", prgname, FN);
      exit(1);
  }
  return file;
}

void SGcloseFile(FILE *fd)
{
  if(fd != stdin) fclose(fd);
}

/*
  \paragraph{Open Language}

  The function |SGopenLanguage| initializes the parse table for language |L|
  from the file |FN|.
*/
ATerm SGopenLanguage(char *prgname, int conn, char *L, char *FN)
{
  FILE *input_file;
  parse_table *table;

  SG_Validate("SGopenLanguage");
  if (SG_VERBOSE && (FN != NULL))
    ATfprintf(stderr, "%s: opening parse table %s\n", prgname, FN);
  if((table = SG_LookupParseTable(L, ATtrue)) == NULL) {
    input_file = SGopenFile(prgname, "parse table not specified", FN);
    if (SG_DEBUG)
      ATfprintf(SGlog(), "Reading parse table for language %s\n", L);
    table = SG_BuildParseTable(ATreadFromFile(input_file));
    SGcloseFile(input_file);
    if(table != NULL)
      SG_SaveParseTable(L, table);
  }

  return ATmake(
    (table != NULL)
      ?  "snd-value(language-opened(<str>,<str>))"
      :  "snd-value(open-language-failed(<str>,<str>))",
    L, FN);
}


void SG_Dump_ATtable(ATermTable t, char *s)
{
  ATerm     key;
  ATermList keys;

  if(t) for(keys = ATtableKeys(t); keys && !ATisEmpty(keys);
            keys=ATgetNext(keys)) {
    key = ATgetFirst(keys);
    ATfprintf(stderr,"%s%s%t: %t\n", s?s:"", s?" ":"", key, ATtableGet(t, key));
  }
}

/*
   \paragraph{Parse String}

   The function |parse_string| parses the text in string |S| with the
   parse table for language |L|. The string is saved in the global
   variable |the_text|, which is accessed through the function
   |getchar_from_string|. This the function that is passed to the
   parser. The end of string character |'\0'| is converted into the
   end of file value |EOF|.
*/
static char *SG_theText;
int         SG_textIndex;

int SG_GetCharFromString(void)
{
  if (SG_theText[SG_textIndex] == '\0') return EOF;
  return SG_theText[SG_textIndex++];
}

/*
  Because the string passed to |parse_string| might be a string that was
  contained in a term we have to save it from being garbage collected.
  This is done now by making a duplicate of it, which is not efficient
  and clean.
*/
ATerm SGparseString(int conn, char *L, char *G, char *S)
{
  ATerm ret;

  SG_Validate("SGparseString");
  SG_theText   = strdup(S);
  SG_textIndex = 0;
  ret = SG_Parse(SG_LookupParseTable(L,ATfalse), G?(*G?G:NULL):NULL,
                 SG_GetCharFromString);
  return ATmake("snd-value(<term>)", ret ? ret : (ATerm) ATempty);
}

/*
   \paragraph{Parse File}

   The function |parse_file| parses the text in file |FN| with the
   parse table for language |L|.  The function |getchar_from_input|
   calls |getc|. The function is used to instantiate the buffer
   parameter function for the parser.

*/
FILE *SG_inputFile;

int SG_GetChar(void)
{
  return getc(SG_inputFile);
}

/*
  If no filename is specified (|FN| is |""|), standard input
  is used.
*/
ATerm SGparseFile(char *prgname, int conn, char *L, char *G, char *FN)
{
  ATerm ret;

  SG_Validate("SGparseFile");
  sg_numtokens = SG_FileSize(prgname, FN);
  if((SG_DEBUG || SG_SHOWSTAT) && sg_numtokens >= 0)
    ATfprintf(SGlog(), "File %s contains %d input tokens\n", FN, sg_numtokens);
  SG_inputFile = SGopenFile(prgname, NULL, FN);
  if (SG_VERBOSE) {
    if (sg_numtokens != -1) {
      ATfprintf(stderr, "%s: parsing file %s (%d tokens)\n",
                prgname, FN, sg_numtokens);
    } else {
      ATfprintf(stderr, "%s: parsing file %s\n", prgname, FN);
    }
  }
  ret = SG_Parse(SG_LookupParseTable(L, ATfalse), G?(*G?G:0):NULL, SG_GetChar);
  SGcloseFile(SG_inputFile);
  return ret ? ret : (ATerm) ATempty;
}

/*
  \paragraph{Term to File}

  Opening a file for writing and write a term to it.

*/
ATerm SGtermToFile(char *prgname, ATerm t, char *FN)
{
  FILE *output_file;

  if (SG_OUTPUT) {
    if (strcmp(FN, "") == 0 || strcmp(FN, "-") == 0) output_file = stdout;
    else if ((output_file = fopen(FN, "w")) == NULL) {
      ATfprintf(stderr, "%s: cannot create %s\n", prgname, FN);
      exit(1);
    } if (SG_VERBOSE)
      ATfprintf(stderr, "%s: writing parse result to %s\n", prgname, FN);
    if(SG_BINARY)
      ATwriteToBinaryFile(t, output_file);
    else
      ATwriteToTextFile(t, output_file);

    if(output_file != stdout) fclose(output_file);
    else {
      if(! SG_BINARY) putc('\n', output_file);    /* For convenience */
      fflush(output_file);      /* To avoid mixing stdout/stderr when redirected */
    }
  }
  return t;
}


/*
    Parse using Language File -- the core function for stand-alone
    use.  It opens (or reuses) the parse table, parses the input
    file, writes the parse tree to the output file and returns it.
 */

ATerm SGparseFileUsingTable(char *prg, char *ptblfil, char *sort,
                            char *infil, char *outfil)
{
  SGopenLanguage(prg, 0, ptblfil, ptblfil);
  return SGtermToFile(prg, SGparseFile(prg, 0, ptblfil, sort, infil), outfil);
}
