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

/*
 In this section we define an application of the parse table and
 parse functions defined in the previous sections. The program can
 run in two modes:

 (1) As a standalone tool that reads a parse table and parses
 the text in a file given that parse table.

 (2) Connected to the ToolBus. In this mode several parse tables
 can be read in and several strings can be parsed using any of
 the parse tables. This enables reuse of the parse table between
 consecutive parses.
 */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include <AsFix.h>
#include <tree-to-dot.h>

#ifndef WIN32  /*  Limited platform  */
#include <atb-tool.h>
#include "sglr.tif.c"
#else
void intel_inside(void)
{
  char x[4]={0xf0,0x0f,0xc7,0xc8};
  void(*fun)()=(void *)x;
  fun();
}
#endif

#include "getopt.h"
#include "forest.h"
#include "sglr.h"
#include "rsrc-usage.h"

#define program_name "sglr"

int     outputflag        = ATtrue;
int     binaryflag        = ATtrue;
int     filterflag        = ATtrue;
int     cycleflag         = ATtrue;
int     posinfoflag       = ATfalse;
int     verboseflag       = ATfalse;
int     debugflag         = ATfalse;
int     statisticsflag    = ATfalse;
int     supplexflag       = ATfalse;
#ifndef NO_A2TOA1
int   asfix1flag        = ATfalse;
#endif
#if !defined(HAVE_BOEHMGC)
int     gcflag          = ATtrue;
#endif

char   *input_file_name   = "-";
char   *output_file_name  = "-";
char   *start_symbol      = NULL;
char   *parse_table_name  = NULL;
char   *dotoutput         = NULL;
char   *stackoutput       = NULL;


/*
 *  ToolBus stubs
 */

ATerm parse_file(int conn, char *L, char *G, char *FN)
{
  return SGparseFile(program_name, conn, L, G?(*G?G:0):NULL, FN);
}

ATerm parse_string(int conn, char *L, char *G, char *S)
{
  return SGparseStringAsAsFix2(conn, L, G, S);
}

ATerm parse_string_as_asfix1(int conn, char *L, char *G, char *S)
{
  return SGparseStringAsAsFix1(conn, L, G, S);
}

ATerm open_language(int conn, char *L, char *FN)
{
  return SGopenLanguage(program_name, conn, L, FN);
}

ATerm close_language(int conn, char *L)
{
  return SGcloseLanguage(program_name, conn, L);
}

ATerm reopen_language(int conn, char *L, char *FN)
{
  return SGreOpenLanguage(program_name, conn, L, FN);
}

void term_to_file(ATerm t, char *FN)
{
  SGtermToFile(program_name, t, FN);
}

FILE *open_file(char *std_error, char *FN)
{
  return SGopenFile(program_name, std_error, FN);
}


/*
 The function |SG_Usage| writes a short summary of the usage of the program.
 */

#define DEFAULTMODE(b) (b ? "on" : "off")

void SG_Usage(FILE *stream, ATbool long_message)
{
  const char usage[] = "Usage:\n\t%s\t-p file [-"
#ifndef NO_A2TOA1
  "12"
#endif
  "?bcdf"
#if !defined(HAVE_BOEHMGC)
  "g"
#endif
  "hlnPtvVx] [-i file] [-o file] \\"
  "\n\t\t[-D file] [-s sort] [-S file]\n";

  ATfprintf(stream, usage, program_name);
  if(long_message) {
    ATfprintf(stream,
              "Parameters:\n"
#if !defined(NO_A2TOA1)
              "\t-1       : use AsFix1 output format             [%s]\n"
              "\t-2       : use AsFix2 output format             [%s]\n"
#endif
              "\t-b       : use Binary AsFix (BAF) output format [%s]\n"
              "\t-c       : toggle cycle detection               [%s]\n"
              "\t-d       : toggle debug mode                    [%s]\n"
              "\t-D file  : generate dot output for parse tree   [%s]\n"
              "\t-f       : toggle filtering                     [%s]\n"
#if !defined(HAVE_BOEHMGC)
              "\t-g       : perform garbage collection           [%s]\n"
#endif
              "\t-h, -?   : display usage information\n"
              "\t-i file  : input from |file|                    [%s]\n"
              "\t-l       : toggle statistics logging            [%s]\n"
              "\t-n       : toggle tree output                   [%s]\n"
              "\t-o file  : output to |file|                     [%s]\n"
              "\t-p file  : use parse table |file| (required)    [%s]\n"
              "\t-P       : toggle position information          [%s]\n"
              "\t-s symbol: define start symbol                  [%s]\n"
              "\t-S file  : trace stack history in dot |file|s   [%s]\n"
              "\t-t       : use PlainText AsFix output format    [%s]\n"
              "\t-v       : toggle verbose mode                  [%s]\n"
              "\t-V       : reveal program version (i.e. %s)\n"
              "\t-x       : toggle inclusion of lexicals in dot  [%s]\n",
#if !defined(NO_A2TOA1)
              DEFAULTMODE(asfix1flag), DEFAULTMODE(!asfix1flag),
#endif
              DEFAULTMODE(binaryflag), DEFAULTMODE(cycleflag),
              DEFAULTMODE(debugflag), dotoutput ? dotoutput : "<off>",
              DEFAULTMODE(filterflag),
#if !defined(HAVE_BOEHMGC)
              DEFAULTMODE(gcflag),
#endif
              input_file_name, DEFAULTMODE(statisticsflag),
              DEFAULTMODE(!outputflag), output_file_name,
              parse_table_name?parse_table_name:"<unspecified>",
              DEFAULTMODE(posinfoflag),
              start_symbol?start_symbol:"<any>", stackoutput?stackoutput:"<off>",
              DEFAULTMODE(!binaryflag), DEFAULTMODE(verboseflag),
              VERSION, DEFAULTMODE(!supplexflag)
    );
  }
}


/*
 To parse the option strings passed to the main program the GNU
 package |getopt| is used. The |longopts| array contains the `long'
 names for the options and the corresponding abbreviations. Long
 options can be called using two hyphens. For instance, |-i file|
 is an abbreviation for |--input file|.
 */

struct option longopts[] =
{
  {"binary-output", no_argument,       &binaryflag,        ATtrue},
#ifndef NO_A2TOA1
  {"asfix1",        no_argument,       &asfix1flag,        ATtrue},
  {"asfix2",        no_argument,       &asfix1flag,        ATfalse},
#endif
  {"debug",         no_argument,       &debugflag,         ATtrue},
  {"dot",           required_argument, NULL,               'D'},
  {"no-filter",     no_argument,       &filterflag,        ATfalse},
  {"cycle-detect",  no_argument,       &cycleflag,         ATtrue},
#if !defined(HAVE_BOEHMGC)
  {"no-gc",         no_argument,       &gcflag,            ATfalse},
#endif
  {"help",          no_argument,       NULL,               'h'},
  {"input",         required_argument, NULL,               'i'},
  {"log",           no_argument,       NULL,               'l'},
  {"no-output",     no_argument,       &outputflag,        ATfalse},
  {"output",        required_argument, NULL,               'o'},
  {"parse-table",   required_argument, NULL,               'p'},
  {"position-info", no_argument,       &posinfoflag,       'P'},
  {"start-symbol",  required_argument, NULL,               's'},
  {"stack",         required_argument, NULL,               'S'},
  {"statistics",    no_argument,       &statisticsflag,    ATfalse},
  {"text-output",   no_argument,       &binaryflag,        ATfalse},
  {"verbose",       no_argument,       &verboseflag,       ATtrue},
  {"version",       no_argument,       NULL,               'V'},
  {"suppress",      no_argument,       &supplexflag,       'x'},
  {0, 0, 0, 0}
};


/*
 The actual argument interpretation is done by the function
 |getopt_long|, which returns an option character for each option. The
 string declares the short names of the options. A colon indicates a
 required argument for an option.
 */

void handle_options (int argc, char **argv)
{
  int c;
  ATbool show_help = ATfalse, show_version = ATfalse;

  while ((c = getopt_long(argc, argv,
#ifndef NO_A2TOA1
                          "12"
#endif
                          "?bcdD:f"
#if !defined(HAVE_BOEHMGC)
                          "g"
#endif
                          "hi:lno:p:Ps:S:tvVx",
                          longopts, NULL))
         != EOF) {
    switch (c) {
      case 0:   break;
#ifndef NO_A2TOA1
      case '1':   asfix1flag       = ATtrue;              break;
      case '2':   asfix1flag       = ATfalse;             break;
#endif
      case '?':   show_help        = ATtrue;              break;
      case 'b':   binaryflag       = ATtrue;              break;
      case 'c':   cycleflag        = !cycleflag;          break;
      case 'd':   debugflag        = !debugflag;          break;
      case 'D':   dotoutput        = optarg;              break;
      case 'f':   filterflag       = !filterflag;         break;
#if !defined(HAVE_BOEHMGC)
      case 'g':   gcflag           = ATfalse;             break;
#endif
      case 'h':   show_help        = ATtrue;              break;
      case 'i':   input_file_name  = optarg;              break;
      case 'l':   statisticsflag   = !statisticsflag;     break;
      case 'n':   outputflag       = !outputflag;         break;
      case 'o':   output_file_name = optarg;              break;
      case 'p':   parse_table_name = optarg;              break;
      case 'P':   posinfoflag      = !posinfoflag;        break;
      case 's':   start_symbol     = optarg;              break;
      case 'S':   stackoutput = optarg; SG_StackDotOut(stackoutput);
        break;
      case 't':   binaryflag       = ATfalse;             break;
      case 'v':   verboseflag      = !verboseflag;        break;
      case 'V':   show_version     = ATtrue;              break;
      case 'x':   supplexflag      = ATtrue;              break;
      default:    SG_Usage(stderr, ATfalse);              exit(1);
    }
  }
  if(show_help) {
    SG_Usage(stdout, ATtrue);
    exit(0);
  }
  if(show_version) {
    ATfprintf(stdout, "%s v%s\n", program_name, VERSION);
    exit(0);
  }
}

ATbool set_global_options(void)
{
  if(debugflag)      SG_DEBUG_ON();
  if(verboseflag)    SG_VERBOSE_ON();
  if(filterflag)     SG_FILTER_ON();
  if(cycleflag)      SG_CYCLE_ON();
  if(start_symbol)   SG_STARTSYMBOL_ON();
  if(statisticsflag) SG_SHOWSTAT_ON();
  if(stackoutput)    SG_SHOWSTACK_ON();
  if(outputflag)     SG_OUTPUT_ON();
#ifndef NO_A2TOA1
  if(asfix1flag)     SG_ASFIX1_ON();
#endif
  if(binaryflag)     SG_BINARY_ON();
  if(dotoutput)      SG_DOTOUT_ON();
  if(supplexflag)    SG_NOLEX_ON();
#if !defined(HAVE_BOEHMGC)
  if(gcflag)         SG_GC_ON();
#endif
  if(posinfoflag)    SG_POSINFO_ON();

  if(!parse_table_name) {
    SG_DEBUG_OFF();
    SG_SHOWSTAT_OFF();
  }
  if(SG_STATISTICS)
    SGopenLog(program_name, SG_DEBUG?".sglr-log":"sglr-stats.txt");

  /*  Return whether a possibly runnable instantiation has been obtained...  */
  if(parse_table_name) {
    return ATtrue;
  } else {
    return ATfalse;
  }
}

/*
 On receipt of a termination request the program exits with code 0.
 */

void rec_terminate(int conn, ATerm t)
{
  exit(0);
}

/*
 In batch mode the program reads a parse table from file and uses
 it to parse a text from the input file. The result is written to
 the specified output file. The filenames should be specified as
 command line options, which are parsed by |handle_options|.
 */

int SG_Batch (int argc, char **argv)
{
  ATerm      parse_tree;

  parse_tree = SGparseFileUsingTable(program_name, parse_table_name, start_symbol,
                                     input_file_name, output_file_name);
  if(!parse_tree) {
    ATwarning("%s: error in %s: unexpected error\n",
              program_name, input_file_name);
    return 2;
  }

  if(SGisParseError(parse_tree)) {
    ATermList errlist;
    ATerm     errcode;
    AFun      err;
    int      c, line, col;

    errlist = (ATermList) ATgetArgument((ATermAppl) parse_tree, 0);
    errcode = ATgetArgument((ATermAppl) parse_tree, 1);
    c    = ATgetInt((ATermInt) ATgetArgument(ATelementAt(errlist, 0), 0));
    line = ATgetInt((ATermInt) ATgetArgument(ATelementAt(errlist, 1), 0));
    col  = ATgetInt((ATermInt) ATgetArgument(ATelementAt(errlist, 2), 0));
    err  = ATgetAFun(errcode);

    /*
     if(err == SG_Plain_Error_AFun) {
       SG_ReportErrLine(line, col);
     }
     */
    if(err == SG_EOF_Error_AFun) {
      ATwarning("%s: error in %s, line %d, col %d: end of file unexpected\n",
                program_name, input_file_name, line, col);
    } else if(err == SG_Plain_Error_AFun) {
      if(isprint(c)) {
        ATwarning("%s: error in %s, line %d, col %d: character `%c'"
                  " (`\\x%2.2x') unexpected\n",
                  program_name, input_file_name, line, col, c, c);
      } else {
        ATwarning("%s: error in %s, line %d, col %d: character `\\x%2.2x' unexpected\n",
                  program_name, input_file_name, line, col, c);
      }
    } else if(err == SG_Cycle_Error_AFun) {
      ATwarning("%s: error in %s, line %d, col %d: cycle detected, productions: %t\n",
                program_name, input_file_name, line, col, ATgetArgument(errcode, 0));
    } else if(err == SG_Amb_Error_AFun) {
      ATwarning("%s: error in %s, line %d, col %d: cannot represent %t ambiguit(y|ies)\n",
                program_name, input_file_name, line, col, ATgetArgument(errcode, 0));
    } else {
      ATwarning("%s: error in %s, line %d, col %d: unknown error",
                program_name, input_file_name, line, col);
    }
    return 1;
  } else if(!SGisParseTree(parse_tree)) {
    ATwarning("%s: error: neither parse tree nor parse error for %s\n",
              program_name, input_file_name);
    return 1;
  }

  if(SG_DOTOUT) {
    if(SG_ASFIX1) {
      ATwarning("%s: cannot create dot output from AsFix1 parse tree\n",
                program_name);
    } else {
      SGtreeToDotFile(program_name, dotoutput, parse_tree, SG_NOLEX);
    }
  }

  IF_VERBOSE(
    int  nrambs;
    char *sort;

    nrambs = SG_OUTPUT||SG_DOTOUT ?
    SGnrAmb(SG_NR_ASK)
                                  : SG_MaxNrAmb(SG_NR_ASK);
    sort   = SGsort(SG_GET, NULL);
    ATwarning("%s: %s parsed %s as sort %s, %s %d ambiguit%s\n",
              program_name, parse_table_name, input_file_name,
              sort ? sort : "[undetermined]",
              SG_OUTPUT||SG_DOTOUT||!SG_MaxNrAmb(SG_NR_ASK) ?
              "exactly"
                                                            : "at most",
              nrambs, (nrambs==1)?"y":"ies");
  );

  return 0;
}


/*
 If the program is called from the ToolBus, the connection with is
 initialized by |ATBinit| and the eventloop subsequently handles
 request from the Bus. The interface functions called by the eventloop
 are defined below. If the program is not called from the ToolBus,
 the function |SG_Batch| handles the parse request specified on the
 command line.
 */

int main (int argc, char **argv)
{
  int    i, cid, retval = 0;
  ATerm  bottomOfStack;
  ATbool use_toolbus = ATfalse;
  long maxrss = 0L;

  maxrss = SG_ResidentSetSize();

  for(i=1; !use_toolbus && i<argc; i++)
    use_toolbus = !strcmp(argv[i], "-TB_TOOL_NAME");

  if(use_toolbus) {
#ifndef WIN32  /*  Sufficient functionality?  */
    set_global_options();
    ATBinit(argc, argv, &bottomOfStack);    /* Initialize Aterm library */
    IF_STATISTICS(
                  fprintf(SGlog(), "[mem] initial ATerm memory: %ld\n", SG_Allocated());
                  if(maxrss) {
                    fprintf(SGlog(), "[mem] ATerm init: %ld before, %ld after\n",
                            maxrss, SG_ResidentSetSize());
                  }
                  )
      cid = ATBconnect(NULL, NULL, -1, sglr_handler);
    ATBeventloop();
#else  /*  Limited platform  */
    /*  intel_inside();  */
    ATerror("%s: platform lacks ToolBus functionality\n", argv[0]);
#endif
  } else {
    char  *ATlibArgv[] = { program_name,
      "-at-silent",   /* Choose sensible options here */
      "-at-symboltable", "32768",
      "-at-termtable", "18"
    };
    ATbool have_complete_config;

    AFinit(6, ATlibArgv, &bottomOfStack);   /* Initialize Aterm library */
    handle_options(argc, argv);
    have_complete_config = set_global_options();

    IF_STATISTICS(
      fprintf(SGlog(), "[mem] initial ATerm memory: %ld\n", SG_Allocated());
      if(maxrss) {
        fprintf(SGlog(), "[mem] ATerm init: %ld before, %ld after\n",
                maxrss, SG_ResidentSetSize());
      }
    );

    if(!have_complete_config) {
      SG_Usage(stderr, SG_VERBOSE);
      retval = 1;
    } else {
      retval = SG_Batch(argc, argv);
    }
  }

  IF_STATISTICS(
    maxrss = SG_ResidentSetSize();
    if(maxrss)
    fprintf(SGlog(), "[mem] exiting: %ld\n", maxrss)
  );

  return retval;
}