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

/*}}}  */
/*{{{  globals */

#define streq(str1,str2) (!strcmp((str1),(str2)))
#define MAX_ARGS 32
/*}}}  */

/*{{{  void usage(char *prg) */


void usage(char *prg)
{
  fprintf(stderr, "Usage: %s -h -f <name> -i <file> -o <file> -m -r <sort>"
	          " -s -v\n"
                  "Options:\n"
                  "\t-h              display help information (usage)\n"
                  "\t-f name         apply prefix function to input terms\n"
                  "\t-i filename     input tree from file (default stdin)\n"
                  "\t-o filename     output tree from file (default stdout)\n"
                  "\t-m              mute: produce no output\n"
                  "\t-r sort         result sort name of prefix function\n"
		  "\t-s              print statistics\n"
                  "\t-v              verbose mode\n"
		  "\nMore than one -i option can be supplied.\n"
                  "\nUse %s -at-help to get more aterm options.\n", prg, prg);
  exit(1);
}
/*}}}  */

/*{{{  int asc_support_main(int argc, char *argv[],  */

int asc_support_main(int argc, char *argv[], 
		     void (*register_all)(), 
		     void (*resolve_all)(),
		     void (*init_all)())
{
  ATerm bottomOfStack;
  PT_ParseTree pt;
  PT_ParseTree asfix;
  PT_Tree trm;
  ATerm t; 
  ATerm reduct;
  ATbool produce_output = ATtrue;
  ATbool run_verbose = ATfalse;
  ATbool printstats = ATfalse;
  char *inputs[MAX_ARGS] = { "-" };
  int nInputs = 0;
  char *output = "-";
  char *function = "";
  char *result = "";
  int i;

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
      if (nInputs <= MAX_ARGS) {
        inputs[nInputs++] = strdup(argv[++i]);
      }
      else {
	ATerror("%s: Maximum number of %d \'-i\' arguments exceeded.\n", 
		argv[0], MAX_ARGS);
      }
    } 
    else if(streq(argv[i], "-o")) {
      output = argv[++i];
    }
    else if(streq(argv[i], "-r")) {
      result = argv[++i];
    }
    else if(streq(argv[i], "-s")) {
      printstats = ATtrue;
    }
    else if(streq(argv[i], "-m")) {
      produce_output = ATfalse;
    }
  }
 
  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  ASF_initASFMEApi();
  ASC_initRunTime(INITIAL_TABLE_SIZE);

  register_all();
  resolve_all();
  init_all();

  if (!streq(function,"")) {
    PT_Args args = PT_makeArgsEmpty();
    
    if (streq(inputs[0],"-")) {
      nInputs++;
    }

    for (--nInputs; nInputs >= 0; nInputs--) {
      PT_ParseTree parseTree = PT_makeParseTreeFromTerm(
                                 ATreadFromNamedFile(inputs[nInputs]));

      if (parseTree == NULL) {
	ATerror("Unable to read in %s\n", inputs[nInputs]);
	exit(1);
      }

      args = PT_makeArgsList(PT_getParseTreeTree(parseTree), args);
    }

    pt = PT_applyFunctionToArgsParseTree(function, result, args);
  } 
  else {
    if (nInputs != 1 && (!streq(inputs[0], "-"))) {
      ATerror("Can only process one argument if no -f and -r option "
	      "are supplied.\n");
      return 1;
    }

    t = ATreadFromNamedFile(inputs[0]);
    pt = PT_makeParseTreeFromTerm(t);
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
	/*
	fprintf(stderr, "size     = %d kb\n", size*4);
	fprintf(stderr, "resident = %d kb\n", resident*4);
	fprintf(stderr, "shared   = %d kb\n", shared*4);
	fprintf(stderr, "trs      = %d kb\n", trs*4);
	fprintf(stderr, "lrs      = %d kb\n", lrs*4);
	*/
	fprintf(stderr, "memory used : %d kb\n", drs*4);
	/*fprintf(stderr, "dt       = %d kb\n", dt*4);*/
      } else {
	fprintf(stderr, "could not open %s\n", buf);
	perror("");
      }
      if (getrusage(RUSAGE_SELF, &usage) == -1) {
	perror("rusage");
      } else {
	/*fprintf(stderr, "rusage statistics (see 'man getrusage')\n");*/
	fprintf(stderr, "utime       : %ld.%06d sec.\n",
		(long)usage.ru_utime.tv_sec, (int)usage.ru_utime.tv_usec);
	fprintf(stderr, "stime       : %ld.%06d sec.\n",
		(long)usage.ru_stime.tv_sec, (int)usage.ru_stime.tv_usec);
#if 0
	/* The following rusage stats do not work yet */
	fprintf(stderr, "maxrss   : %ld\n", usage.ru_maxrss);
	fprintf(stderr, "ixrss    : %ld\n", usage.ru_ixrss);
	fprintf(stderr, "idrss    : %ld\n", usage.ru_idrss);
	fprintf(stderr, "isrss    : %ld\n", usage.ru_isrss);
	fprintf(stderr, "minflt   : %ld\n", usage.ru_minflt);
	fprintf(stderr, "majflt   : %ld\n", usage.ru_majflt);
	fprintf(stderr, "nswap    : %ld\n", usage.ru_nswap);
	fprintf(stderr, "\n");
	fprintf(stderr, "inblock  : %ld\n", usage.ru_nswap);
	fprintf(stderr, "oublock  : %ld\n", usage.ru_nswap);
	fprintf(stderr, "msgsnd   : %ld\n", usage.ru_nswap);
	fprintf(stderr, "msgrcv   : %ld\n", usage.ru_nswap);
	fprintf(stderr, "nsignals : %ld\n", usage.ru_nswap);
	fprintf(stderr, "nvcsw    : %ld\n", usage.ru_nswap);
	fprintf(stderr, "nivcsw   : %ld\n", usage.ru_nswap);
#endif
      }
    }
 
    if (produce_output) {
      asfix = toasfix(reduct);
      ATwriteToNamedBinaryFile(PT_makeTermFromParseTree(asfix),output);
    }
  }

  return 0;
}

/*}}}  */

