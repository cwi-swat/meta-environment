/**
  * Library support for rewriting terms.
  *
  * Pieter Olivier
  * Thu Aug 14 11:36:34 MET DST 1997
  */

/*{{{  includes */

#ifndef WIN32
	/* These files can not be included in Windows NT*/
	#include <atb-tool.h>
	#include "rewriter.tif.h"
#else
	#include <stdlib.h>	/* used for exit(0) */
#endif

#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include <AsFix.h>
#include <AsFix-expand.h>
#include <AsFix-init-patterns.h>
#include <deprecated.h>
/* #include <gc.h> */

#include "asc-support.h"

/*}}}  */

/*{{{  globals */

static char *name; 

extern ATerm pattern_asfix_term;

ATerm innermost(ATerm t);
ATerm toasfix(ATerm t, ATerm f, ATerm n);
void init_patterns();
void c_rehash(int newsize);

/*}}}  */
/*{{{  ATerm *get_name(int cid) */

ATerm get_name(int cid)
{
  return ATmake("snd-value(name(<str>))", name);
}

/*}}}  */
/*{{{  ATerm *reduce(int cid, ATerm *t) */

ATerm reduce(int cid, ATerm t)
{
  ATerm reduct, asfix = NULL, file, modname, trm;

ATfprintf(stderr,"reducing entered\n");
  t = AFexpandTerm(t);
  if(ATmatchTerm(t, pattern_asfix_term, NULL, NULL,
                &file, NULL, &modname, NULL, &trm, NULL, NULL)) {
    reduct = innermost(trm);
    asfix = toasfix(reduct, file, modname);
  } else
    ATerror("not an asfix term: %t\n", t);
ATfprintf(stderr,"reducing finished\n");
  return ATmake("snd-value(reduct(<term>))", asfix);
}

/*}}}  */
/*{{{  ATerm reduce_and_asource(int cid, ATerm t, char *name, char *ext) */
ATerm reduce_and_asource(int cid, ATerm t, char *name, char *ext)
{
  FILE *file;
  char full[1024];
  ATerm reduct, asfix = NULL, filename, modname, trm; 

ATfprintf(stderr,"reducing entered\n");
  t = AFexpandTerm(t);
  if(ATmatchTerm(t, pattern_asfix_term, NULL, NULL,
                 &filename, NULL, &modname, NULL, &trm, NULL, NULL)) {
    reduct = innermost(trm);
    asfix = toasfix(reduct, filename, modname);
  } else
    ATerror("not an asfix term: %t\n", t);

ATfprintf(stderr,"reducing finished\n");
  strcpy(full, name);
  strcat(full, ".");
  strcat(full, ext);
  file = fopen(full, "w");
  if (!file) 
    ATerror("asource: Could not open %s\n", full);
  AFsourceToFile(asfix, file); 
  fclose(file);
  return ATmake("snd-value(reduction-finished(<str>))",full);
}

/*}}}  */
/*{{{  void rec_terminate(int cid) */

void rec_terminate(int cid, ATerm arg)
{
  exit(0);
}

/*}}}  */
/*{{{  void usage(char *prg) */

/**
 * Print usage information and exit
 */

void usage(char *prg)
{
  fprintf(stderr, "usage: %s [aterm-options] [toolbus-options] [options]",prg);
  fprintf(stderr, "options:\n");
  fprintf(stderr, "  -stats/-s:        print statistics.\n");
  fprintf(stderr, "  -name/-n <name>   set the name of the specifications.\n");
  fprintf(stderr, "  -verbose/-v       verbose mode.\n");
  fprintf(stderr, "use %s -at-help to get more aterm/toolbus options.\n", prg);
  exit(1);
}

/*}}}  */
/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm t, trm, reduct, asfix, file, modname;
  ATbool printstats = ATfalse, use_toolbus = ATfalse,
         run_verbose = ATfalse;
  int i, cid;
  ATerm bottomOfStack;
  name = argv[0];

  for(i=1; i<argc; i++) {
    if(streq(argv[i], "-stats") || streq(argv[i], "-s")) {
      printstats = ATtrue;
    } else if(streq(argv[i], "-TB_TOOL_NAME") || streq(argv[i], "-at-help")) {
      use_toolbus = ATtrue;
    } else if(streq(argv[i], "-name") || streq(argv[i], "-n")) {
      name = argv[++i];
    } else if(streq(argv[i], "-v")) {
      run_verbose = ATtrue;
    } else if(streq(argv[i], "-h")) {
      usage(argv[0]);
    }
  }
 
  if(use_toolbus) {
  	#ifndef WIN32 /* Code with Toolbus calls, non Windows */
  		ATBinit(argc, argv, &bottomOfStack);  /* Initialize the Aterm library */
  		cid = ATBconnect(NULL, NULL, -1, rewriter_handler);
  	#else
  		fprintf(stderr, "asource: Toolbus cannot be used in Windows.\n");
  	#endif
  }

  AFinit(argc, argv, &bottomOfStack);

  init_patterns();
  AFinitAsFixPatterns();

  c_rehash(INITIAL_TABLE_SIZE);
  register_all();
  resolve_all();
  init_all();

  if(use_toolbus) {
  	#ifndef WIN32 /* Code with Toolbus calls, non Windows */
  		ATBeventloop();
  	#endif
  } 
  else {
    t = ATreadFromFile(stdin);
    t = AFexpandTerm(t);

    if(ATmatchTerm(t, pattern_asfix_term, NULL, NULL,
                 &file, NULL, &modname, NULL, &trm, NULL, NULL)) {
      if(run_verbose) ATfprintf(stderr,"Reducing ...\n");
      reduct = innermost(trm);
      if(run_verbose) ATfprintf(stderr,"Reducing finished.\n");
      asfix = toasfix(reduct, file, modname);
      ATwriteToBinaryFile(asfix,stdout);
      /*ATwriteToTextFile(asfix,stdout);*/
    }
    else { /* Alex added {} after 'else' for readability */
      ATfprintf(stderr, "not an asfix term: %t\n", t);
    }
  }
  return 0;
}

/*}}}  */

