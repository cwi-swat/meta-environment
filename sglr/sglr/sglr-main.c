/*  $Id$  */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include <MEPT-utils.h>
#include <asfix2.h>
#include <conversion.h>

#ifndef WIN32
#include <atb-tool.h>
#include "sglr.tif.h"
#endif

#include "getopt.h"
#include "forest.h"
#include "sglr.h"
#include "rsrc-usage.h"

#define program_name "sglr"

int     outputflag                 = ATtrue;
int     binaryflag                 = ATtrue;
int     filterflag                 = ATtrue;
int     filter_associativityflag   = ATtrue;
int     filter_directeagernessflag = ATtrue;
int     filter_eagernessflag       = ATtrue;
int     filter_injectioncountflag  = ATtrue;
int     filter_priorityflag        = ATtrue;
int     filter_rejectflag          = ATtrue;
int     cycleflag                  = ATtrue;
int     verboseflag                = ATfalse;
int     debugflag                  = ATfalse;
int     statisticsflag             = ATfalse;
int     supplexflag                = ATfalse;
int     printprodsflag             = ATfalse;
int     ambiguityerrorflag         = ATfalse;
int     asfix2meflag               = ATtrue;

char   *input_file_name   = "-";
char   *output_file_name  = "-";
char   *start_symbol      = NULL;
char   *parse_table_name  = NULL;


/*
 *  ToolBus stubs
 */

ATerm parse_file(int conn, ATerm L, char *G, char *FN)
{
  return SGparseFile(program_name, L, G?(*G?G:0):NULL, FN);
}

ATerm parse_string(int conn, ATerm L, char *G, char *S)
{
  return SGparseStringAsAsFix2(L, G, S);
}

ATerm parse_string_as_asfix2me(int conn, ATerm L, char *G, char *S)
{
  return SGparseStringAsAsFix2ME(L, G, S);
}

ATerm open_language_from_term(int conn, ATerm L, ATerm tbl)
{
  return SGopenLanguageFromTerm(program_name, L, tbl);
}

ATerm open_language(int conn, ATerm L, char *FN)
{
  return SGopenLanguage(program_name, L, FN);
}

ATerm close_language(int conn, ATerm L)
{
  return SGcloseLanguage(program_name, L);
}

ATerm reopen_language(int conn, ATerm L, char *FN)
{
  return SGreOpenLanguage(program_name, L, FN);
}

void term_to_file(ATerm t, char *FN)
{
  SGtermToFile(program_name, t, FN);
}


/*
 The function |SG_Usage| writes a short summary of the usage of the program.
 */

#define DEFAULTMODE(b) (b ? "on" : "off")

void SG_Usage(FILE *stream, ATbool long_message)
{
  const char usage[] = "Usage:\n\t%s\t-p file [-2?bcdhlmnPtvV] "
  "[-f[adeirp]] [-i file] [-o file] \\"
  "\n\t\t[-s sort]\n";

  ATfprintf(stream, usage, program_name);
  if(long_message) {
    ATfprintf(stream,
              "Parameters:\n"
              "\t-2         : use AsFix2 output format             [%s]\n"
              "\t-A         : ambiguities are treated as errors    [%s]\n"
              "\t-b         : output AsFix in binary format (BAF)  [%s]\n"
              "\t-c         : toggle cycle detection               [%s]\n"
              "\t-d         : toggle debug mode                    [%s]\n"
              "\t-f[adeipr] : toggle filtering, or specific filter [%s]\n"
              "\t  a : associativity                               [%s]\n"
              "\t  d : direct eagerness                            [%s]\n"
              "\t  e : eagerness                                   [%s]\n"
              "\t  i : injection count                             [%s]\n"
              "\t  p : priority                                    [%s]\n"
              "\t  r : reject                                      [%s]\n"
              "\t-h, -?     : display usage information\n"
              "\t-i file    : input from |file|                    [%s]\n"
              "\t-l         : toggle statistics logging            [%s]\n"
              "\t-m         : use AsFix2ME output format           [%s]\n"
              "\t-n         : toggle parse tree creation           [%s]\n"
              "\t-o file    : output to |file|                     [%s]\n"
              "\t-p file    : use parse table |file| (required)    [%s]\n"
              "\t-s symbol  : define start symbol                  [%s]\n"
              "\t-t         : output AsFix in textual format       [%s]\n"
              "\t-v         : toggle verbose mode                  [%s]\n"
              "\t-V         : reveal program version (i.e. %s)\n",
              DEFAULTMODE(!asfix2meflag),
              DEFAULTMODE(ambiguityerrorflag),
              DEFAULTMODE(binaryflag), 
              DEFAULTMODE(cycleflag),
              DEFAULTMODE(debugflag), 
              DEFAULTMODE(filterflag),
              DEFAULTMODE(filter_associativityflag),
              DEFAULTMODE(filter_directeagernessflag),
              DEFAULTMODE(filter_eagernessflag),
              DEFAULTMODE(filter_injectioncountflag),
              DEFAULTMODE(filter_priorityflag),
              DEFAULTMODE(filter_rejectflag),
              input_file_name, 
              DEFAULTMODE(statisticsflag),
              DEFAULTMODE(asfix2meflag),
              DEFAULTMODE(outputflag),
              output_file_name,
              parse_table_name?parse_table_name:"unspecified",
              start_symbol ? start_symbol:"any", 
              DEFAULTMODE(!binaryflag),
              DEFAULTMODE(verboseflag),
              VERSION
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
  {"ambiguity-error", no_argument,       &ambiguityerrorflag,  ATtrue},
  {"binary-output",   no_argument,       &binaryflag,          ATtrue},
  {"asfix2",          no_argument,       &asfix2meflag,        ATtrue},
  {"debug",           no_argument,       &debugflag,           ATtrue},
  {"no-filter",       optional_argument, &filterflag,          ATfalse},
  {"cycle-detect",    no_argument,       &cycleflag,           ATtrue},
  {"help",            no_argument,       NULL,                 'h'},
  {"input",           required_argument, NULL,                 'i'},
  {"log",             no_argument,       NULL,                 'l'},
  {"no-output",       no_argument,       &outputflag,          ATfalse}, 
  {"output",          required_argument, NULL,                 'o'},
  {"parse-table",     required_argument, NULL,                 'p'},
  {"start-symbol",    required_argument, NULL,                 's'},
  {"statistics",      no_argument,       &statisticsflag,      ATfalse},
  {"asfix2me",        no_argument,       &asfix2meflag,        ATfalse},
  {"text-output",     no_argument,       &binaryflag,          ATfalse},
  {"verbose",         no_argument,       &verboseflag,         ATtrue},
  {"version",         no_argument,       NULL,                 'V'},
  {0, 0, 0, 0}
};

void handle_filter_options(void)
{
  if (optarg == NULL) {
    filterflag = !filterflag;
  }
  else {
    if (strlen(optarg) == 1) {
      switch(optarg[0]) {
	case 'a':
          filter_associativityflag = !filter_associativityflag;
          break; 
        case 'd':
          filter_directeagernessflag = !filter_directeagernessflag;
          break;
        case 'e':
          filter_eagernessflag = !filter_eagernessflag;
          break;
        case 'i':
          filter_injectioncountflag = !filter_injectioncountflag;
          break;
        case 'p':
          filter_priorityflag = !filter_priorityflag;
	  break;
        case 'r':
          filter_rejectflag = !filter_rejectflag;
          break;
        default:
          SG_Usage(stderr, ATfalse); 
          exit(1);
      }
    }
    else {
      SG_Usage(stderr, ATfalse); 
      exit(1);
    }
  }
}

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
                          "12?Abcdf::hi:lmno:p:s:S:tvV",
                          longopts, NULL))
         != EOF) {
    switch (c) {
      case 0:   break;
      case '2':   asfix2meflag     = ATfalse;             break;
      case '?':   show_help        = ATtrue;              break;
      case 'A':   ambiguityerrorflag = !ambiguityerrorflag; break;
      case 'b':   binaryflag       = ATtrue;              break;
      case 'c':   cycleflag        = !cycleflag;          break;
      case 'd':   debugflag        = !debugflag;          break;
      case 'f':   handle_filter_options();                break;     
      case 'h':   show_help        = ATtrue;              break;
      case 'i':   input_file_name  = optarg;              break;
      case 'l':   statisticsflag   = !statisticsflag;     break;
      case 'm':   asfix2meflag     = ATtrue;              break;
      case 'n':   outputflag       = !outputflag;         break;  
      case 'o':   output_file_name = optarg;              break;
      case 'p':   parse_table_name = optarg;              break;
      case 's':   start_symbol     = optarg;              break;
      case 't':   binaryflag       = ATfalse;             break;
      case 'v':   verboseflag      = !verboseflag;        break;
      case 'V':   show_version     = ATtrue;              break;
      default:    SG_Usage(stderr, ATfalse);              exit(1);
    }
  }
  if(show_help) {
    SG_Usage(stdout, ATtrue);
    exit(0);
  }
  if(show_version) {
    ATfprintf(stderr, "%s v%s\n", program_name, VERSION);
    exit(0);
  }
}

ATbool set_global_options(void)
{
  if(debugflag)                  SG_DEBUG_ON();
  if(verboseflag)                SG_VERBOSE_ON();
  if(filterflag)                 SG_FILTER_ON();
  if(filter_associativityflag)   SG_FILTER_ASSOCIATIVITY_ON();
  if(filter_directeagernessflag) SG_FILTER_DIRECTEAGERNESS_ON();
  if(filter_eagernessflag)       SG_FILTER_EAGERNESS_ON();
  if(filter_injectioncountflag)  SG_FILTER_INJECTIONCOUNT_ON();
  if(filter_priorityflag)        SG_FILTER_PRIORITY_ON();
  if(filter_rejectflag)          SG_FILTER_REJECT_ON();
  if(cycleflag)                  SG_CYCLE_ON();
  if(start_symbol)               SG_STARTSYMBOL_ON();
  if(statisticsflag)             SG_SHOWSTAT_ON();
  if(outputflag)                 SG_OUTPUT_ON();
  if(asfix2meflag)               SG_ASFIX2ME_ON();
  if(binaryflag)                 SG_BINARY_ON();
  if(ambiguityerrorflag)         SG_AMBIGUITY_ERROR_ON();

  if(!parse_table_name) {
    SG_DEBUG_OFF();
    SG_SHOWSTAT_OFF();
  }

  if(SG_STATISTICS) {
    SG_OpenLog(program_name, SG_DEBUG?".sglr-log":"sglr-stats.txt");
  }

  /*  Return whether a possibly runnable instantiation has been obtained...  */
  if(parse_table_name) {
    return ATtrue;
  }
  else {
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

  parse_tree = SGparseFileUsingTable(program_name, 
                                     parse_table_name, 
                                     start_symbol,
                                     input_file_name, 
                                     output_file_name);
  if (!SG_OUTPUT) {
    return 0;
  }

  if (!parse_tree) {
    ATwarning("%s: error in %s: unexpected error\n",
              program_name, input_file_name);
    return 2;
  }

  if (SGisParseError(parse_tree)) {
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

    if (err == SG_EOF_Error_AFun) {
      ATwarning("%s: error in %s, line %d, col %d: end of file unexpected\n",
                program_name, input_file_name, line, col);
    }
    else if (err == SG_Plain_Error_AFun) {
      if (isprint(c)) {
        ATwarning("%s: error in %s, line %d, col %d: character `%c' (\\x%2.2x)"
                  " unexpected\n",
                  program_name, input_file_name, line, col, c, c);
      }
      else {
        ATwarning("%s: error in %s, line %d, col %d: character \\x%2.2x"
                  " unexpected\n",
                  program_name, input_file_name, line, col, c);
      }
    } 
    else if (err == SG_Cycle_Error_AFun) {
      ATwarning("%s: error in %s, line %d, col %d: cycle detected, productions: %t\n",
                program_name, 
                input_file_name, 
                line, 
                col, 
                ATgetArgument(errcode, 0));
    }
    else if (err == SG_Amb_Error_AFun) {
      int ambiescount = ATgetInt((ATermInt) ATgetArgument(errcode,0));
      ATwarning("%s: error in %s, line %d, col %d: cannot represent %d ambiguit%s\n",
                program_name, 
                input_file_name, 
                line, 
                col, 
                ambiescount,
                (ambiescount > 1) ? "ies" : "y" );
    }
    else {
      ATwarning("%s: error in %s, line %d, col %d: unknown error",
                program_name, input_file_name, line, col);
    }
    return 1;
  }
  else if(!SGisParseTree(parse_tree)) {
    ATwarning("%s: error: neither parse tree nor parse error for %s\n",
              program_name, input_file_name);
    return 1;
  }

  IF_VERBOSE(
    int  nrambs;
    char *sort;

    nrambs = SGnrAmb(SG_NR_ASK);
    sort   = SGsort(SG_GET, NULL);
    ATwarning("%s: %s parsed %s as sort %s, with %d ambiguit%s\n",
              program_name, parse_table_name, input_file_name,
              sort ? sort : "[undetermined]",
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
    SG_TOOLBUS_ON();

    ATBinit(argc, argv, &bottomOfStack);    /* Initialize Aterm library */
    PT_initMEPTApi();
    PT_initAsFix2Api(); 
    IF_STATISTICS(
      fprintf(SG_log(), "[mem] initial ATerm memory: %ld\n", SG_Allocated());
      if (maxrss) {
        fprintf(SG_log(), "[mem] ATerm init: %ld before, %ld after\n",
                maxrss, SG_ResidentSetSize());
      }
    )
    cid = ATBconnect(NULL, NULL, -1, sglr_handler);
    ATBeventloop();
#endif
  } else {
    char  *ATlibArgv[] = { program_name,
	"-at-silent",   /* Choose sensible options here */
	"-at-afuntable", "15",
	"-at-termtable", "18"
    };
    ATbool have_complete_config;

    ATinit(6, ATlibArgv, &bottomOfStack);   /* Initialize Aterm library */
    PT_initMEPTApi();
    PT_initAsFix2Api(); 

    handle_options(argc, argv);
    have_complete_config = set_global_options();
    SG_TOOLBUS_OFF();

    IF_STATISTICS(
      fprintf(SG_log(), "[mem] initial ATerm memory: %ld\n", SG_Allocated());
      if(maxrss) {
        fprintf(SG_log(), "[mem] ATerm init: %ld before, %ld after\n",
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
    fprintf(SG_log(), "[mem] exiting: %ld\n", maxrss)
  );

  return retval;
}
