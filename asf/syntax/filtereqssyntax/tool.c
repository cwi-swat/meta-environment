/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <aterm2.h>
#include <atb-tool.h>
#include <MEPT-utils.h>
#include <ASFME-utils.h>

#include "filtereqssyntax.h"
#include "filtereqssyntaxtool.tif.h"

/*}}}  */

/*{{{  globals  */

static char myname[] = "filtereqssyntaxtool";
static char myversion[] = "0.1";

static ATbool run_verbose;

/*}}}  */

/*{{{  static void usage(void) */

static void usage(void)
{
  ATwarning("This tool can only be used a a toolbus application.\n"
	    "\n"
	    "Usage: %s -hvV\n"
	    "Options:\n"
	    "\t-h           display this usage message\n"
	    "\t-v           print verbose messages\n"
	    "\t-V           print version number (i.e. %s)\n"
	    "\n"
	    "Type %s -at-help for ATerm library options.\n",
	    myname, myversion);
}

/*}}}  */

/*{{{  static void version(void) */

static void version(void)
{
  ATwarning("%s v%s\n", myname, myversion);
}

/*}}}  */

/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */

/*{{{  ATerm filtereqssyntax(int cid, ATerm term) */

ATerm filtereqssyntax(int cid, ATerm term)
{
  PT_ParseTree parsetree = PT_ParseTreeFromTerm(term);
  PT_Tree tree = PT_getParseTreeTree(parsetree);
  ATerm ambiguities;
  int count;
  
  if (run_verbose) {
    ATwarning("BEFORE FILTERING:\n%t\n", PT_reportTreeAmbiguities(tree));
  }

  tree = (PT_Tree) filterEquationSyntax((ASF_ASFEquations) tree);
  ambiguities = PT_reportTreeAmbiguities(tree);
  
  if (ATmatch(ambiguities,"ambiguities(<int>,[<list>])", &count, NULL)) {
    if (run_verbose) {
        ATwarning("AFTER FILTERING:\n%t\n", ambiguities);
    }
    
    parsetree = PT_setParseTreeTree(parsetree, tree);
    parsetree = PT_setParseTreeAmbCnt(parsetree, count);
  }   
  else {
    ATerror("filter: unexpected ambiguity report: %t\n", ambiguities);
    return NULL;                               
  }   
  
  return ATmake("snd-value(filtereqssyntax(<term>,<term>))",
		PT_ParseTreeToTerm(parsetree),
		ambiguities);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  int cid;
  int i;

  run_verbose = ATfalse;

  for (i = 0; i < argc; i++) {
    if (!strcmp(argv[i],"-h")) {
      usage();
      return 0;
    }
    else if (!strcmp(argv[i],"-v")) {
      run_verbose = ATtrue;
    }
    else if (!strcmp(argv[i],"-V")) {
      version();
      return 0;
    }
  }

  ATBinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  ASF_initASFMEApi();

  cid = ATBconnect(NULL,NULL,-1, filtereqssyntaxtool_handler);
  ATBeventloop();

  return 0;
}

/*}}}  */
