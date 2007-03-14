/*  $Id$  */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <MEPT.h>
#include <MEPT-utils.h>
#include <Error-utils.h>
#include <Error-manager.h>
#include <stdio.h>
#include <unistd.h>
#include <logging.h>
#include <mainOptions.h>
#include <filterOptions.h>
#include <parserOptions.h>

#include "sglrInterface.h"
#include "parseTableDB.h"
#include "options.h"
#include "toolbusInterface.h"
#include "filters.h"
#include "inputStringBuilder.h"


static const char programName[] = "sglr";
static const char myArguments[] = "2Abdf::hi:lno:p:s:tvV";
static const char myVersion[]   = VERSION;

static const char *flag(ATbool value) {
  static const char on[]  = "on";
  static const char off[] = "off";

  return value ? on : off;
}

static void usage() {
  int outputFlag                = PARSER_getOutputFlag();
  int textualOutputFlag         = MAIN_getTextualOutputFlag();
  int filterFlag                = FLT_getFilterFlag();
  int filterDirectPreferenceFlag = FLT_getDirectPreferenceFlag();
  int filterIndirectPreferenceFlag = FLT_getIndirectPreferenceFlag();
  int filterPreferenceCountFlag  = FLT_getPreferenceCountFlag();
  int filterInjectionCountFlag  = FLT_getInjectionCountFlag();
  int filterPriorityFlag        = FLT_getPriorityFlag();
  int filterRejectFlag          = FLT_getRejectFlag();
  int filterRemoveCyclesFlag    = FLT_getRemoveCyclesFlag();
  int filterTopSort             = FLT_getSelectTopNonterminalFlag();
  int verboseFlag               = PARSER_getVerboseFlag();
  int debugFlag                 = PARSER_getDebugFlag;
  int statisticsFlag            = PARSER_getStatsFlag();
  int ambiguityErrorFlag        = PARSER_getAmbiguityErrorFlag();
  int flattenFlag               = MAIN_getFlattenTreeFlag();

  fprintf(stderr,
	  "%s: parses a file using a parse table and outputs a parse forest.\n"
	  "\n"
	  "Options:\t                                          [default]\n"
	  "\t-2          : flatten to AsFix2ME                  [%s]\n"
	  "\t-A          : ambiguities are treated as errors    [%s]\n"
	  "\t-d          : toggle debug mode                    [%s]\n"
	  "\t-f[cdeipr]  : toggle filtering, or specific filter [%s]\n"
	  "\t  c         : remove cycles                        [%s]\n"
      "\t  t         : direct preference                    [%s]\n"
      "\t  d         : indirect preference                  [%s]\n"
	  "\t  e         : preference count                     [%s]\n"
	  "\t  i         : injection count                      [%s]\n"
	  "\t  p         : priority                             [%s]\n"
	  "\t  r         : reject                               [%s]\n"
	  "\t-h          : display usage information\n"
	  "\t-i file     : input from |file|                    [stdin]\n"
	  "\t-l          : toggle statistics logging            [%s]\n"
	  "\t-n          : toggle parse tree creation           [%s]\n"
	  "\t-o file     : output to |file|                     [stdout]\n"
	  "\t-p file     : use parse table |file| (required)\n"
	  "\t-s symbol   : select tree with start symbol        [%s]\n"
	  "\t-t          : output AsFix in textual format       [%s]\n"
	  "\t-v          : toggle verbose mode                  [%s]\n"
	  "\t-V          : reveal program version\n"
	  ,
          programName,
	  flag(flattenFlag),
	  flag(ambiguityErrorFlag),
	  flag(debugFlag), 
	  flag(filterFlag),
      flag(filterRemoveCyclesFlag),
	  flag(filterDirectPreferenceFlag),
	  flag(filterIndirectPreferenceFlag),
	  flag(filterPreferenceCountFlag),
	  flag(filterInjectionCountFlag),
	  flag(filterPriorityFlag),
	  flag(filterRejectFlag),
	  flag(statisticsFlag),
	  flag(outputFlag),
      flag(filterTopSort),
	  flag(textualOutputFlag),
	  flag(verboseFlag)
	  );
}

static void handleFilterOptions(const char *arg) {
  int filterFlag                = FLT_getFilterFlag();
  int filterDirectPreferenceFlag= FLT_getDirectPreferenceFlag();
  int filterIndirectPreferenceFlag = FLT_getIndirectPreferenceFlag();
  int filterPreferenceCountFlag = FLT_getPreferenceCountFlag();
  int filterInjectionCountFlag  = FLT_getInjectionCountFlag();
  int filterPriorityFlag        = FLT_getPriorityFlag();
  int filterRejectFlag          = FLT_getRejectFlag();
  int filterRemoveCyclesFlag    = FLT_getRemoveCyclesFlag();

  if (arg == NULL) {
    filterFlag = !filterFlag;
  }
  else {
    if (strlen(arg) == 1) {
      switch(arg[0]) {
        case 'c': 
          filterRemoveCyclesFlag = !filterRemoveCyclesFlag;
          break;
        case 'd':
          filterIndirectPreferenceFlag = !filterIndirectPreferenceFlag;
          break;
        case 'e':
          filterPreferenceCountFlag = !filterPreferenceCountFlag;
          break;
        case 'i':
          filterInjectionCountFlag = !filterInjectionCountFlag;
          break;
        case 'p':
          filterPriorityFlag = !filterPriorityFlag;
	      break;
        case 'r':
          filterRejectFlag = !filterRejectFlag;
          break;
       case 't':
          filterDirectPreferenceFlag = !filterDirectPreferenceFlag;
          break;
        default:
          usage(); 
          exit(1);
      }
    }
    else {
      fprintf(stderr, "%s: filter option %s is not recognized.\n",
	      programName, arg);
      usage(); 
      exit(1);
    }
  }

  FLT_setFilterFlag(filterFlag);
  FLT_setDirectPreferenceFlag(filterDirectPreferenceFlag);
  FLT_setIndirectPreferenceFlag(filterIndirectPreferenceFlag);
  FLT_setPreferenceCountFlag(filterPreferenceCountFlag);
  FLT_setInjectionCountFlag(filterInjectionCountFlag);
  FLT_setPriorityFlag(filterPriorityFlag);
  FLT_setRejectFlag(filterRejectFlag);
  FLT_setRemoveCyclesFlag(filterRemoveCyclesFlag);
}

static void handleOptions (int argc, char **argv) {
  int c;

  int outputflag         = PARSER_getOutputFlag();
  int textualflag        = MAIN_getTextualOutputFlag();
  int verboseflag        = PARSER_getVerboseFlag();
  int debugflag          = PARSER_getDebugFlag;
  int statisticsflag     = PARSER_getStatsFlag();
  int ambiguityerrorflag = PARSER_getAmbiguityErrorFlag();
  int flattenFlag        = MAIN_getFlattenTreeFlag();
  int startSymbolFlag    = FLT_getSelectTopNonterminalFlag();
  
  char *startSymbol     = NULL;
  char *inputFileName   = "-";
  char *outputFileName  = "-";
  char *parseTableName  = NULL;
  
  ATbool showHelp    = ATfalse;
  ATbool showVersion = ATfalse;

  while ((c = getopt(argc, argv, myArguments)) != -1) {
    switch (c) {
      case 0:   break;
      case '2':   flattenFlag        = !flattenFlag;        break;
      case 'A':   ambiguityerrorflag = !ambiguityerrorflag; break;
      case 'd':   debugflag          = !debugflag;          break;
      case 'f':   handleFilterOptions(optarg);              break;     
      case 'h':   showHelp           = !showHelp;           break;
      case 'i':   inputFileName      = optarg;              break;
      case 'l':   statisticsflag     = !statisticsflag;     break;
      case 'n':   outputflag         = !outputflag;         break;  
      case 'o':   outputFileName     = optarg;              break;
      case 'p':   parseTableName     = optarg;              break;
      case 's':   
          startSymbolFlag = ! startSymbolFlag;
          startSymbol = optarg;              
          break;
      case 't':   textualflag        = !textualflag;         break;
      case 'v':   verboseflag        = !verboseflag;        break;
      case 'V':   showVersion        = !showVersion;        break;
      default:    usage();              exit(1);
    }
  }

  if(showHelp) {
    usage();
    exit(0);
  }

  if(showVersion) {
    ATfprintf(stderr, "%s v%s\n", programName, myVersion);
    exit(0);
  }

  if(!parseTableName) {
    ATfprintf(stderr, "%s: Parse table argument missing.\n", programName);
    usage();
    exit(1);
  }

  PARSER_setDebugFlag(debugflag);
  PARSER_setVerboseFlag(verboseflag);
  PARSER_setStatsFlag(statisticsflag);
  PARSER_setOutputFlag(outputflag);
  MAIN_setFlattenTreeFlag(flattenFlag);
  MAIN_setTextualOutputFlag(textualflag);
  MAIN_setOutputFileName(outputFileName);
  MAIN_setInputFileName(inputFileName);
  MAIN_setParseTableName(parseTableName);
  FLT_setSelectTopNonterminalFlag(startSymbolFlag);
  if (startSymbol) {
    FLT_setTopNonterminal(startSymbol);
  }
  PARSER_setAmbiguityErrorFlag(ambiguityerrorflag);

  /** \todo This does not belong here. (sglr-interface initialisation?)
   * Should separate the debug and stats output files.*/
  if(PARSER_getStatsFlag() || PARSER_getDebugFlag) {
    LOG_OpenLog(programName, PARSER_getDebugFlag ?".sglr-log":"sglr-stats.txt");
  }
}

static void outputResult(ATerm result, const char *fileName){
  if (PARSER_getOutputFlag()) {
    if(MAIN_getTextualOutputFlag()) {
      ATwriteToNamedTextFile(result, fileName);
    }
    else {
      ATwriteToNamedBinaryFile(result, fileName);
    }
  }
}

/* When executed from the command line the program reads a parse table from 
 * file and uses it to parse text from the input file. The result is written 
 * to the specified output file. The file names should be specified as
 * command line options, which are parsed by |handleOptions()|.
 */
int runCommandLineTool (int argc, char **argv) {
  PT_ParseTree parse_tree;
  InputString inputString;

  handleOptions(argc, argv);

  /** \todo Need to allow the input string to be read from stdin if the option 
   * is blank or - is used. */
  inputString = IS_createInputStringFromFile(MAIN_getInputFileName());
  if (SG_AddParseTable(MAIN_getParseTableName()) == NULL) {
    outputResult(ERR_SummaryToTerm(SGLR_PTBL_makeErrorSummary("parse table")), MAIN_getOutputFileName());
    return 1;
  }

  parse_tree = SGLR_parse(inputString, MAIN_getParseTableName());

  if (parse_tree != NULL) {
    outputResult(PT_ParseTreeToTerm(parse_tree), MAIN_getOutputFileName());
    return 0;
  }
  else {
    outputResult(ERR_SummaryToTerm(ERR_getManagerSummary()), 
        MAIN_getOutputFileName());
    return 1;
  }

}


