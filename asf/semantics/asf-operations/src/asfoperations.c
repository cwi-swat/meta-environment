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
#include <SDFME-utils.h>

#include "renaming-symbols.h"

/*{{{  globals */

static char *name;

ATbool run_verbose;

static char myname[] = "asfoperations";
static char myversion[] = "0.0";
static char myarguments[] = "hV";

/*}}}  */
/*{{{  ATerm get_equation_list(int cid, ATerm eqsTree) */

ATerm get_equation_list(int cid, ATerm eqsPTree)
{
  ASF_CondEquationList asfEqsList = ASF_makeCondEquationListEmpty();
  PT_Tree eqsTree = PT_getParseTreeTree(PT_makeParseTreeFromTerm(eqsPTree));
  ASF_Equations asfEqs = ASF_makeEquationsFromTerm(PT_makeTermFromTree(eqsTree));
  if (ASF_isEquationsPresent(asfEqs)) {
    asfEqsList = ASF_getEquationsList(asfEqs);
  }
  return ATmake("snd-value(equations(<term>))", 
		ATBpack(ASF_makeTermFromCondEquationList(asfEqsList)));
}

/*}}}  */
/*{{{  ATerm rename_in_equations(int cid, ATerm atRenamings, ATerm eqsPTree) */
 
ATerm rename_in_equations(int cid, ATerm atRenamings, ATerm eqsPTree)
{
  ASF_CondEquationList asfEqsList = ASF_makeCondEquationListEmpty();
  SDF_Renamings renamings = SDF_makeRenamingsFromTerm(atRenamings);
  PT_Tree eqsTree = PT_getParseTreeTree(PT_makeParseTreeFromTerm(eqsPTree));
  ASF_Equations asfEqs = ASF_makeEquationsFromTerm(PT_makeTermFromTree(eqsTree));

  if (ASF_isEquationsPresent(asfEqs)) {
    asfEqsList = ASF_getEquationsList(asfEqs);
    asfEqsList = renameSymbolsInEquations(asfEqsList, renamings);
  }
 
  return ATmake("snd-value(equations(<term>))",
                ATBpack(ASF_makeTermFromCondEquationList(asfEqsList)));
}
 
/*}}}  */ 
/*{{{  ATerm union_equations(int cid, ATerm eqsList1, eqsList2) */
 
ATerm union_equations(int cid, ATerm eqsList1, ATerm eqsList2)
{
  ASF_CondEquationList asfEqsList1 = ASF_makeCondEquationListFromTerm(eqsList1);
  ASF_CondEquationList asfEqsList2 = ASF_makeCondEquationListFromTerm(eqsList2);
  ASF_CondEquationList newAsfEqsList = ASF_unionCondEquationList(asfEqsList1, asfEqsList2);
 
  return ATmake("snd-value(equations(<term>))",
                ATBpack(ASF_makeTermFromCondEquationList(newAsfEqsList)));
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
  SDF_initSDFMEApi();
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
