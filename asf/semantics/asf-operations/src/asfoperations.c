#ifndef WIN32
/* These files can not be included in Windows NT*/
#include <atb-tool.h>
#include "asfoperations.tif.h"
#endif

#include <stdio.h>
#include <stdlib.h>     /* used for exit(0) */
#include <assert.h>
#include <ctype.h>
#include <unistd.h>

#include <MEPT-utils.h>
#include <ASFME-utils.h>

/*{{{  globals */

static char *name;

ATbool run_verbose;

static char myname[] = "asfoperations";
static char myversion[] = "0.0";
static char myarguments[] = "hV";

/*}}}  */
/*{{{  ATerm extract_equations(int cid, ATerm modules) */

ATerm extract_equations(int cid, ATerm modules)
{
  ATermList list = (ATermList) modules;
  ASF_ASFConditionalEquationList eqsList;

  eqsList = ASF_makeASFConditionalEquationListEmpty();

  for(;!ATisEmpty(list); list = ATgetNext(list)) {
    ATerm head = ATBunpack(ATgetFirst(list));
    ASF_ASFEquations eqs = ASF_getStartTopASFEquations(ASF_StartFromTerm(head));
   
    if (ASF_hasASFEquationsList(eqs)) {
      eqsList = ASF_unionASFConditionalEquationList(ASF_getASFEquationsList(eqs), eqsList);
    }
  }

  return ATmake("snd-value(extract-equations-result(<term>))",
		ATBpack(ASF_ASFConditionalEquationListToTerm(eqsList)));
}

/*}}}  */
/*{{{  ATerm extract_tests(int cid, ATerm modules) */

ATerm extract_tests(int cid, ATerm modules)
{
  ATermList list = (ATermList) modules;
  ASF_ASFTestEquationTestList eqsList;

  eqsList = ASF_makeASFTestEquationTestListEmpty();

  for(;!ATisEmpty(list); list = ATgetNext(list)) {
    ATerm head = ATBunpack(ATgetFirst(list));
    ASF_ASFEquations eqs = ASF_getStartTopASFEquations(ASF_StartFromTerm(head));
   
    if (ASF_hasASFEquationsTestList(eqs)) {
      eqsList = ASF_concatASFTestEquationTestList(
	          ASF_getASFEquationsTestList(eqs), eqsList);
    }
  }

  return ATmake("snd-value(extract-tests-result(<term>))",
		ATBpack(ASF_ASFTestEquationTestListToTerm(eqsList)));
}

/*}}}  */

/*{{{  void rec_terminate(int cid, ATerm arg) */

void rec_terminate(int cid, ATerm arg)
{
  exit(0);
}

/*}}}  */

/*{{{  static void usage(void) */

static void usage(void)
{
  ATwarning(
    "Usage: %s -h -V . . .\n"
    "Options:\n"
    "\t-h              display help information (usage)\n"
    "\t-V              reveal program version (i.e. %s)\n",
    myname, myversion);
}

/*}}}  */
/*{{{  static void version(void) */

static void version(void)
{
  ATwarning("%s v%s\n", myname, myversion);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int cid;
  int c, toolbus_mode = 0;
  ATerm bottomOfStack;
  name = argv[0];

/*  Check whether we're a ToolBus process  */
  for(c=1; !toolbus_mode && c<argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  ASF_initASFMEApi();

  if (toolbus_mode) {
    #ifndef WIN32 /* Code with Toolbus calls, non Windows */
      ATBinit(argc, argv, &bottomOfStack);  /* Initialize the Aterm library */
      cid = ATBconnect(NULL, NULL, -1, asfoperations_handler);
      ATBeventloop();
    #else
      ATwarning("asfoperations: Toolbus cannot be used in Windows.\n");
    #endif
  }
  else {
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
        case 'V':  version(); exit(0);                     break;
  
        case 'h':
        default:   usage(); exit(0);                       break;
      }
    }
  }
  return 0;
}

/*}}}  */
