/* $Id$ */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <aterm2.h>
#include <sglrInterface.h>
#include <filterOptions.h>
#include <inputStringBuilder.h>

#include <atb-tool.h>
#include <ASFME.h>
#include <ParsedRStore.h>
#include <RStore.h>

#include "asc-support2-me.h"
#include "Library.h"
#include "builtin-common.h"
#include "options.h"
#include "asc-options.h"
#include "asc-support-me.h"
#include "asc-client.h"

#ifndef streq
#define streq(s1,s2) (!strcmp(s1,s2))
#endif
#define MAX_ARGS 32
#define MAX_STRINGARGUMENT_LENGTH 10000

static const char myArguments[] = "hf:i:s:o:mr:Stv";
PT_ParseTree inputs[MAX_ARGS]; /* Global? */

static void initApis() {
  PT_initMEPTApi();
  ASF_initASFMEApi();
  ASC_initRunTime(INITIAL_TABLE_SIZE);
  PT_initAsFix2Api();
  PRS_initParsedRStoreApi();
  RS_initRStoreApi();
}

static void printStats() {
  struct rusage usage;
  FILE *file;
  char buf[BUFSIZ];
  int size, resident, shared, trs, lrs, drs, dt;

  sprintf(buf, "/proc/%d/statm", (int) getpid());
  file = fopen(buf, "r");
  if (file) {
    fscanf(file, "%d %d %d %d %d %d %d",
	   &size, &resident, &shared, &trs, &lrs, &drs, &dt);
    fprintf(stderr, "memory used : %d kb\n", drs*4);
  } else {
    fprintf(stderr, "could not open %s\n", buf);
    perror("");
  }
  if (getrusage(RUSAGE_SELF, &usage) == -1) {
    perror("rusage");
  } else {
    fprintf(stderr, "utime       : %ld.%06d sec.\n",
	    (long)usage.ru_utime.tv_sec, (int)usage.ru_utime.tv_usec);
    fprintf(stderr, "stime       : %ld.%06d sec.\n",
	    (long)usage.ru_stime.tv_sec, (int)usage.ru_stime.tv_usec);
  }
}

static ATbool toolbusMode(int argc, char* argv[]) {
  int i;

  for (i=1; i < argc; i++) {
    if (!strcmp(argv[i], "-TB_TOOL_NAME")) {
      return ATtrue;
    }
  }

  return ATfalse;
}

static void initParsetable(unsigned const char* tableBaf, size_t tableSize) {
  if (tableBaf != NULL) {
    ATerm parseTable = ATreadFromBinaryString(tableBaf, tableSize);
    if (parseTable != NULL) {
      setParseTable(PTBL_ParseTableFromTerm(parseTable));
    }
  }
}

static PT_ParseTree parsetreeFromString(const char *string) {
  CO_OptLayout layout = CO_makeOptLayoutAbsent();
  return (PT_ParseTree)
    CO_makeStartStrCon(layout, CO_makeStrCon(string), layout, 0);
}

static PT_ParseTree parsetreeFromATermFile(const char *filename) {
  ATerm term = NULL;
    
  term = ATreadFromNamedFile(filename);

  if (term != NULL && ATmatch(term, "parsetree(<term>,<int>)", NULL, NULL)) {
    return PT_ParseTreeFromTerm(term);
  }

  ATerror("asc-main: can not read parse tree from file %s\n", filename);
  return NULL;
}

static PT_ParseTree parsetreeFromTextFile(const char *filename) {
  PT_ParseTree parseResult = NULL;
  InputString inputString;
  
  FLT_setInjectionCountFlag(ATfalse);
  FLT_setPreferenceCountFlag(ATfalse);

  if (loadParseTable()) {
    inputString = IS_createInputStringFromFile(filename);
    parseResult = SGLR_parse(inputString, getParseTableID());
  }
  else {
    ATerror("asc-main: parse table not loaded.");
  }

  if (parseResult != NULL) {
    return parseResult;
  }
  else {
    ATerror("asc-main: unknown error while parsing %s\n", filename);
    exit(1);
  }
  
  return NULL;
}

static PT_ParseTree parsetreeFromFile(const char* filename, ATbool parse) {
  if (parse) {
    return parsetreeFromTextFile(filename);
  }
  else {
    return parsetreeFromATermFile(filename);
  }
}

static PT_ParseTree applyFunction(const char *function, const char *sort, int nInputs, PT_ParseTree inputs[MAX_ARGS]) {
  PT_Args args = PT_makeArgsEmpty();

  for (--nInputs; nInputs >= 0; nInputs--) {
    PT_Tree parseTree = PT_getParseTreeTree(inputs[nInputs]);
    args = PT_makeArgsMany(parseTree, args);
  }

  return PT_applyFunctionToArgsParseTree(function, sort, args);
}

void usage(char *prg) {
  fprintf(stderr, 
	  "Usage: %s -h -f <name> -i <file> -s <string> -o <file> -m -r <sort> -S"
	  " -s -t -v\n"
	  "Options:\n"
	  "\t-h              display help information (usage)\n"
	  "\t-f name         apply prefix function to input terms\n"
	  "\t-i filename     input from file (default stdin)\n"
	  "\t-s string       input string as input term \n"
	  "\t                (will be converted to a StrCon tree)\n"
	  "\t-o filename     output to file (default stdout)\n"
	  "\t-m              mute: produce no output\n"
	  "\t-r sort         result sort name of prefix function\n"
	  "\t-S              print statistics\n"
	  "\t-t              output textual term instead of baf\n"
	  "\t-v              verbose mode\n"
	  "\nMore than one -i option can be supplied.\n"
	  "\nUse %s -at-help to get more aterm options.\n", prg, prg);
  exit(1);
}

void handleOptions(int argc, char *argv[], ATbool parseInput) {
  int c;
  ATbool produce_output = ASC_getOutputFlag();
  ATbool verbose = ASC_getVerboseFlag();
  ATbool printStats = ASC_getStatsFlag();
  ATbool bafmode = ASC_getBafmodeFlag();
  int nInputs = ASC_getNumberOfParseTrees();

  while ((c = getopt(argc, argv, myArguments)) != -1) {
    switch (c) {
      case 0:                                       break;
      case 'h': usage(argv[0]);                     break;
      case 'v': ASC_setVerboseFlag(!verbose);       break;
      case 'f': ASC_setPrefixFunction(optarg);      break;
      case 'o': ASC_setOutputFilename(optarg);      break;
      case 'r': ASC_setResultNonTermName(optarg);   break;
      case 'S': ASC_setStatsFlag(!printStats);      break;
      case 't': ASC_setBafmodeFlag(!bafmode);       break;
      case 'm': ASC_setOutputFlag(!produce_output); break;
      case 'i': assert(nInputs <= MAX_ARGS);
                inputs[nInputs++] = parsetreeFromFile(optarg, parseInput);
                break;
      case 's': assert(nInputs <= MAX_ARGS);
                inputs[nInputs++] = parsetreeFromString(optarg);
                break;
      default:  usage(argv[0]);
    }
  }

  ASC_setNumberOfParseTrees(nInputs);
}

int asc_support_main(ATerm *bottomOfStack, int argc, char *argv[], void (*register_all)(), void (*resolve_all)(), void (*init_all)(), unsigned const char* tableBaf, size_t tableSize, ATbool parseInput, ATBhandler handler) {

  PT_ParseTree pt = NULL;
  PT_Tree asfix;
  PT_Tree trm;
  PT_ParseTree rpt = NULL;
  ATerm reduct;
  const char *outputFilename;
  int numberOfInputs;

  ATinit(argc, argv, bottomOfStack);
  initApis();

  register_all();
  resolve_all();
  init_all();

  initParsetable(tableBaf, tableSize);
  SGLR_initialize();

  OPT_initialize();
  ASC_initializeDefaultOptions();

  /*  Check whether we're a ToolBus process  */
  if (toolbusMode(argc, argv)) {
    ATBinit(argc, argv, bottomOfStack);
    ATBconnect(NULL, NULL, -1, asf_toolbus_handler);
    ATBeventloop();
  }
  else {    
    handleOptions(argc, argv, parseInput);

    numberOfInputs = ASC_getNumberOfParseTrees();
    outputFilename = ASC_getOutputFilename();

    if (!streq(ASC_getPrefixFunction(),"")) {
      pt = applyFunction((const char*) ASC_getPrefixFunction(), 
			 (const char*) ASC_getResultNonTermName(), numberOfInputs, inputs);
    } 
    else {
      if (numberOfInputs == 0) {
	pt = parsetreeFromFile("-", parseInput);
      }
      else if (numberOfInputs == 1) {
	pt = inputs[0];
      }
      else if (numberOfInputs != 1) {
	ATerror("Can only process one argument if no -f and -r option "
		"are supplied.\n"
		"Did a -s argument eat up your -f or -r option?\n");
	return 1;
      }
    }

    if (PT_isValidParseTree(pt)) {
      trm = PT_getParseTreeTop(pt);

      if (ASC_getVerboseFlag()) { ATfprintf(stderr,"Reducing ...\n"); }

      reduct = innermost(trm);

      if (ASC_getVerboseFlag()) { ATfprintf(stderr,"Reducing finished.\n"); }
      if (ASC_getStatsFlag())  { printStats(); }

      if (ASC_getOutputFlag()) {
	asfix = toasfix(reduct);
	rpt = PT_makeParseTreeTop(asfix, 0);

	if (parseInput) {
	  FILE *fp = NULL;

	  if (!strcmp(outputFilename, "-")) {
	    fp = stdout;
	  }
	  else {
	    fp = fopen(outputFilename, "wb");
	  }

	  if (fp != NULL) {
	    PT_yieldParseTreeToFile(rpt, fp, ATfalse);
	  }
	  else {
	    ATerror("asc-main: unable to open %s for writing\n", outputFilename);
	  }
	}
	else {
	  if (ASC_getBafmodeFlag()) {
	    ATwriteToNamedBinaryFile(PT_ParseTreeToTerm(rpt),outputFilename);
	  }
	  else {
	    ATwriteToNamedTextFile(PT_ParseTreeToTerm(rpt),outputFilename);
	  }
	}
      }
    }
  }

  return 0;
}

