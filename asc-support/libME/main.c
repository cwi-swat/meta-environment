/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "asc-support2-me.h"


/*}}}  */
/*{{{  globals */

static char *name; 

#define streq(str1,str2) (!strcmp((str1),(str2)))
/*}}}  */

/*{{{  void usage(char *prg) */


void usage(char *prg)
{
  fprintf(stderr, "Usage: %s -h -i <file> -o <file> -n <name> -sv",prg);
  fprintf(stderr, "Options:\n");
  fprintf(stderr, "\t-h              display help information (usage)\n");
  fprintf(stderr, "\t-i filename     input tree from file (default stdin)\n");
  fprintf(stderr, "\t-o filename     output tree from file (default stdout)\n");
  fprintf(stderr, "\t-s              print statistics\n");
  fprintf(stderr, "\t-n name         set name of specification\n");
  fprintf(stderr, "use %s -at-help to get more aterm/toolbus options.\n", prg);
  exit(1);
}
/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  PT_ParseTree pt;
  PT_ParseTree asfix;
  PT_Tree trm;
  ATerm t; 
  ATerm reduct;
  ATbool printstats = ATfalse;
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

    asfix = toasfix(reduct);

    ATwriteToNamedBinaryFile(PT_makeTermFromParseTree(asfix),output);
  }

  return 0;
}

/*}}}  */

