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

#include "asc-support2-me.h"
#include <ASFME.h>
#include "Library.h"

#include <atb-tool.h>
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
                  "\t-i filename     input tree from file (default stdin)\n"
                  "\t-s string       input string as input term \n"
		  "\t                (will be converted to a StrCon tree)\n"
                  "\t-o filename     output tree to file (default stdout)\n"
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

/*{{{  int asc_support_main(int argc, char *argv[],  */

int asc_support_main(ATerm *bottomOfStack, int argc, char *argv[], 
		     void (*register_all)(), 
		     void (*resolve_all)(),
		     void (*init_all)(),
		     char* tableBaf,
		     size_t tableSize, 
		     ATBhandler handler
		     )
{
  CO_OptLayout layout;
  PT_ParseTree pt = NULL;
  PT_ParseTree asfix;
  PT_Tree trm;
  ATerm t; 
  ATerm reduct;
  ATbool toolbus_mode = ATfalse;
  ATbool produce_output = ATtrue;
  ATbool run_verbose = ATfalse;
  ATbool printstats = ATfalse;
  ATbool bafmode = ATtrue;
  ATerm inputs[MAX_ARGS];
  int nInputs = 0;
  char *output = "-";
  char *function = "";
  char *result = "";
  int i;

  ATinit(argc, argv, bottomOfStack);
  PT_initMEPTApi();
  ASF_initASFMEApi();
  ASC_initRunTime(INITIAL_TABLE_SIZE);
  PT_initAsFix2Api();


  register_all();
  resolve_all();
  init_all();

  if (tableBaf != NULL) {
    ATerm parseTable = ATreadFromBinaryString(tableBaf, tableSize);
    if (parseTable != NULL) {
      setParseTable(parseTable);
    }
  }

  layout = CO_makeOptLayoutAbsent();

  /*  Check whether we're a ToolBus process  */
  for(i=1; !toolbus_mode && i<argc; i++) {
    if(!strcmp(argv[i], "-TB_TOOL_NAME")) {
      toolbus_mode = ATtrue;
    }
  }

  if (toolbus_mode) {
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
	inputs[nInputs] = ATreadFromNamedFile(argv[++i]);
	if (inputs[nInputs] == NULL) {
	  ATerror("Unable to read in %s\n", inputs[nInputs]);
	  exit(1);
	}

	nInputs++;
      } 
      else if(streq(argv[i], "-s")) {
	char buf[MAX_STRINGARGUMENT_LENGTH];

	snprintf(buf, MAX_STRINGARGUMENT_LENGTH, "\"%s\"", argv[++i]);
	assert(nInputs <= MAX_ARGS);
	inputs[nInputs] = (ATerm) CO_makeStartStrCon(layout,
					     CO_makeStrConDefault(buf),
					     layout, 0);
	nInputs++;
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
      PT_Args args = PT_makeArgsEmpty();

      for (--nInputs; nInputs >= 0; nInputs--) {
	PT_ParseTree parseTree = PT_ParseTreeFromTerm(inputs[nInputs]);
	args = PT_makeArgsList(PT_getParseTreeTree(parseTree), args);
      }

      pt = PT_applyFunctionToArgsParseTree(function, result, args);
    } 
    else {
      if (nInputs == 0) {
	t = ATreadFromNamedFile("-");
	pt = PT_makeParseTreeFromTerm(t);
      }
      else if (nInputs != 1) {
	ATerror("Can only process one argument if no -f and -r option "
		"are supplied.\n");
	return 1;
      }
    }

    if (pt == NULL) {
      ATerror("Input could not be recognized");
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
	struct rusage usage;
	FILE *file;
	char buf[BUFSIZ];
	int size, resident, shared, trs, lrs, drs, dt;

	sprintf(buf, "/proc/%d/statm", getpid());
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

      if (produce_output) {
	asfix = toasfix(reduct);
	if (bafmode) {
	  ATwriteToNamedBinaryFile(PT_makeTermFromParseTree(asfix),output);
	}
	else {
	  ATwriteToNamedTextFile(PT_makeTermFromParseTree(asfix),output);
	}

      }
    }
  }

  return 0;
}

/*}}}  */

