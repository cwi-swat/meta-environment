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

/*}}}  */
/*{{{  globals */

static char *name; 

#define streq(str1,str2) (!strcmp((str1),(str2)))
/*}}}  */

/*{{{  void usage(char *prg) */


void usage(char *prg)
{
  fprintf(stderr, "Usage: %s -h -i <file> -o <file> -n <name> -m -s -v\n",prg);
  fprintf(stderr, "Options:\n");
  fprintf(stderr, "\t-h              display help information (usage)\n");
  fprintf(stderr, "\t-i filename     input tree from file (default stdin)\n");
  fprintf(stderr, "\t-o filename     output tree from file (default stdout)\n");
  fprintf(stderr, "\t-m              mute: produce no output\n");
  fprintf(stderr, "\t-s              print statistics\n");
  fprintf(stderr, "\t-v              verbose mode\n");
  fprintf(stderr, "\t-n name         set name of specification\n");
  fprintf(stderr, "\nuse %s -at-help to get more aterm options.\n", prg);
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
  ATbool printstats = ATfalse;
  ATbool produce_output = ATtrue;
  ATbool run_verbose = ATfalse;
  char *input = "-";
  char *output = "-";
  int i;

  name = argv[0];

  for(i=1; i<argc; i++) {
    if(streq(argv[i], "-s")) {
      printstats = ATtrue;
    } 
    else if(streq(argv[i], "-n")) {
      name = argv[++i];
    } 
    else if(streq(argv[i], "-v")) {
      run_verbose = ATtrue;
    } 
    else if(streq(argv[i], "-h")) {
      usage(argv[0]);
    } 
    else if(streq(argv[i], "-i")) {
      input = argv[++i];
    } 
    else if(streq(argv[i], "-o")) {
      output = argv[++i];
    }
    else if(streq(argv[i], "-m")) {
      produce_output = ATfalse;
    }
  }
 
  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  ASC_initRunTime(INITIAL_TABLE_SIZE);

  register_all();
  resolve_all();
  init_all();

  t = ATreadFromNamedFile(input);
  pt = PT_makeParseTreeFromTerm(t);

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

