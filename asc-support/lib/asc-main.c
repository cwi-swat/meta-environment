/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#include <atb-tool.h>
#include <ASFME.h>

#include "asc-support2-me.h"
#include "Library.h"
#include "builtin-common.h"

/*}}}  */
/*{{{  globals */

#ifndef streq
#define streq(s1,s2) (!strcmp(s1,s2))
#endif
#define MAX_ARGS 32
#define MAX_STRINGARGUMENT_LENGTH 10000
/*}}}  */

/*{{{  void usage(char *prg) */


void usage(char *prg)
{
  fprintf(stderr, "Usage: %s -h -f <name> -i <file> -s <string> -o <file> -m -r <sort> -S"
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
/*}}}  */

/*{{{  static void initAPIs() */

static void initApis()
{
  PT_initMEPTApi();
  ASF_initASFMEApi();
  ASC_initRunTime(INITIAL_TABLE_SIZE);
  PT_initAsFix2Api();
}

/*}}}  */
/*{{{  static void printStats()  */

static void printStats() 
{
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

/*}}}  */
/*{{{  static void initParsetable() */

static void initParsetable(const char* tableBaf, size_t tableSize)
{
  if (tableBaf != NULL) {
    ATerm parseTable = ATreadFromBinaryString((char*) tableBaf, tableSize);
    if (parseTable != NULL) {
      setParseTable(parseTable);
    }
  }
}

/*}}}  */
/*{{{  static ATbool toolbusMode(int argc, char* argv[]) */

static ATbool toolbusMode(int argc, char* argv[])
{
  int i;

  for (i=1; i < argc; i++) {
    if (!strcmp(argv[i], "-TB_TOOL_NAME")) {
      return ATtrue;
    }
  }

  return ATfalse;
}

/*}}}  */

/*{{{  static ATerm parsetreeFromString(const char *string) */

static PT_ParseTree parsetreeFromString(const char *string)
{
  CO_OptLayout layout = CO_makeOptLayoutAbsent();
  return (PT_ParseTree)
    CO_makeStartStrCon(layout, CO_makeStrCon(string), layout, 0);
}

/*}}}  */
/*{{{  static PT_ParseTree parsetreeFromATermFile(const char *filename) */

static PT_ParseTree parsetreeFromATermFile(const char *filename)
{
  ATerm term = NULL;
    
  term = ATreadFromNamedFile(filename);

  if (term != NULL && ATmatch(term, "parsetree(<term>,<int>)", NULL, NULL)) {
    return PT_ParseTreeFromTerm(term);
  }

  ATerror("asc-main: can not read parse tree from file %s\n", filename);
  return NULL;
}

/*}}}  */
/*{{{  static PT_ParseTree parsetreeFromTextFile(const char *filename) */

static PT_ParseTree parsetreeFromTextFile(const char *filename)
{
  ATerm parseResult = NULL;

  if (getParseTable() != NULL) {
    char toolname[] = "asc-main";

    initParser(toolname, filename);

    parseResult = SGparseFile(toolname, ATparse(toolname), NULL, filename);

    if (parseResult != NULL) {
     
      if (SGisParseTree(parseResult)) {
	return (PT_ParseTree) parseResult;
      }
      else {
	ATerror("asc-main: %t\n", parseResult);
	return NULL;
      }
    }
    else {
      ATerror("asc-main: unknown error while parsing %s\n", filename);
    }
  }
  
  return NULL;
}

/*}}}  */
/*{{{  static PT_ParseTree parsetreeFromFile(const char* filename, ATbool parse) */

static PT_ParseTree parsetreeFromFile(const char* filename, ATbool parse)
{
  if (parse) {
    return parsetreeFromTextFile(filename);
  }
  else {
    return parsetreeFromATermFile(filename);
  }
}

/*}}}  */
/*{{{  static PT_ParseTree applyFunction(ATerm inputs[MAX_ARGS]) */

static PT_ParseTree applyFunction(const char *function, const char *sort, 
				  int nInputs, PT_ParseTree inputs[MAX_ARGS])
{
  PT_Args args = PT_makeArgsEmpty();

  for (--nInputs; nInputs >= 0; nInputs--) {
    PT_Tree parseTree = PT_getParseTreeTree(inputs[nInputs]);
    args = PT_makeArgsMany(parseTree, args);
  }

  return PT_applyFunctionToArgsParseTree(function, sort, args);
}

/*}}}  */

/*{{{  int asc_support_main(int argc, char *argv[],  */

int asc_support_main(ATerm *bottomOfStack, int argc, char *argv[], 
		     void (*register_all)(), 
		     void (*resolve_all)(),
		     void (*init_all)(),
		     char* tableBaf,
		     size_t tableSize, 
		     ATbool parseInput,
		     ATBhandler handler
		     )
{
  PT_ParseTree pt = NULL;
  PT_ParseTree asfix;
  PT_Tree trm;
  ATerm reduct;
  ATbool produce_output = ATtrue;
  ATbool run_verbose = ATfalse;
  ATbool printstats = ATfalse;
  ATbool bafmode = ATtrue;
  PT_ParseTree inputs[MAX_ARGS];
  int nInputs = 0;
  char *output = "-";
  char *function = "";
  char *result = "";
  int i;

  ATinit(argc, argv, bottomOfStack);
  initApis();

  register_all();
  resolve_all();
  init_all();

  initParsetable(tableBaf, tableSize);

  /*  Check whether we're a ToolBus process  */

  if (toolbusMode(argc, argv)) {
     ATBinit(argc, argv, bottomOfStack);
     ATBconnect(NULL, NULL, -1, handler);
     ATBeventloop();
  }
  else {
    for(i=1; i<argc; i++) {
      if(streq(argv[i], "-v")) {
	run_verbose = ATtrue;
      } 
      else if(streq(argv[i], "-h")) {
	usage(argv[0]);
      } 
      else if(streq(argv[i], "-f")) {
	function = argv[++i];
      }
      else if(streq(argv[i], "-i")) {
	assert(nInputs <= MAX_ARGS);
	inputs[nInputs++] = parsetreeFromFile(argv[++i], parseInput);
      } 
      else if(streq(argv[i], "-s")) {
	assert(nInputs <= MAX_ARGS);
	inputs[nInputs++] = parsetreeFromString(argv[++i]);
      }
      else if(streq(argv[i], "-o")) {
	output = argv[++i];
      }
      else if(streq(argv[i], "-r")) {
	result = argv[++i];
      }
      else if(streq(argv[i], "-S")) {
	printstats = ATtrue;
      }
      else if(streq(argv[i], "-t")) {
	bafmode = ATfalse;
      }
      else if(streq(argv[i], "-m")) {
	produce_output = ATfalse;
      }
    }

    if (!streq(function,"")) {
      pt = applyFunction((const char*) function, (const char*) result, 
			 nInputs, inputs);
    } 
    else {
      if (nInputs == 0) {
	pt = parsetreeFromFile("-", parseInput);
      }
      else if (nInputs == 1) {
	pt = inputs[0];
      }
      else if (nInputs != 1) {
	ATerror("Can only process one argument if no -f and -r option "
		"are supplied.\n"
		"Did a -s argument eat up your -f or -r option?\n");
	return 1;
      }
    }

    if (PT_isValidParseTree(pt)) {
      trm = PT_getParseTreeTree(pt);

      if(run_verbose) {
	ATfprintf(stderr,"Reducing ...\n");
      }

      reduct = innermost(trm);

      if(run_verbose) {
	ATfprintf(stderr,"Reducing finished.\n");
      }

      if (printstats) {
	printStats();
      }

      if (produce_output) {
	asfix = toasfix(reduct);

	if (parseInput) {
	  FILE *fp = NULL;

	  if (!strcmp(output, "-")) {
	    fp = stdout;
	  }
	  else {
	    fp = fopen(output, "wb");
	  }

	  if (fp != NULL) {
	    PT_yieldParseTreeToFile(asfix, fp, ATfalse);
	  }
	  else {
	    ATerror("asc-main: unable to open %s for writing\n", output);
	  }
	}
	else {
	  if (bafmode) {
	    ATwriteToNamedBinaryFile(PT_ParseTreeToTerm(asfix),output);
	  }
	  else {
	    ATwriteToNamedTextFile(PT_ParseTreeToTerm(asfix),output);
	  }
	}
      }
    }
  }

  return 0;
}

/*}}}  */
