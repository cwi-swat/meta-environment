/*{{{  includes */

#ifndef WIN32
#include <atb-tool.h>
#include "asfchecker.tif.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <unistd.h>

#include <MEPT-utils.h>
#include <ASFME-utils.h>
#include <Error-utils.h>

#include "equationChecker.h"
#include "statistics.h"

/*}}}  */

/*{{{  globals */

static char *name;

ATbool run_verbose;
ATbool statistics;

static char myname[] = "asfchecker";
static char myversion[] = "0.1";
static char myarguments[] = "hi:svV";

/*}}}  */

/*{{{  static ERR_ErrorList checkAsf(ATerm term) */

static ERR_ErrorList checkAsf(ATerm term)
{
  ERR_ErrorList result = NULL;
  initStatistics();

  if (ATgetType(term) == AT_LIST) {
    ASF_ASFConditionalEquationList rules = ASF_makeASFConditionalEquationListFromTerm(term);
    result = checkASFConditionalEquationList(rules);
  }
  else {
    PT_ParseTree parseTree = PT_ParseTreeFromTerm(term);
    int ambs = PT_getParseTreeAmbCnt(parseTree);
    if (ambs == 0) {
      ASF_ASFModule module = ASF_getStartTopASFModule((ASF_Start) parseTree);
      ASF_ASFConditionalEquationList rules = ASF_getASFModuleEquationList(module);
      ASF_ASFTestEquationTestList tests = ASF_getASFModuleTestList(module);

      result = ERR_concatErrorList(checkEquations(rules), checkTests(tests));
    }
    else {
      result = makeAmbiguityMessage(PT_getParseTreeTop(parseTree));
    }
  }


  if (statistics) {
    printStatistics();
  }

  cleanStatistics();

  return result;
}

/*}}}  */

/*{{{  ATerm check_asf(int cid, ATerm term) */

ATerm check_asf(int cid, ATerm term)
{
  ERR_ErrorList errorList = checkAsf(ATBunpack(term));    

  return ATmake("snd-value(messages(<term>))", (ATerm) errorList);
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
    "Usage: %s -h -i file -vV . . .\n"
    "Options:\n"
    "\t-h              display help information (usage)\n"
    "\t-i filename     input from file (default stdin)\n"
    "\t-v              verbose mode\n"
    "\t-s              print statistics\n"
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
  ATerm rules = NULL; 
  ERR_ErrorList msgs = ERR_makeErrorListEmpty();
  char *input = "-";
  int cid;
  int c, toolbus_mode = 0;
  ATerm bottomOfStack;
  name = argv[0];

  statistics = ATfalse;
  run_verbose = ATfalse;

  /*  Check whether we're a ToolBus process  */
  for(c=1; !toolbus_mode && c<argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  ASF_initASFMEApi();
  initErrorApi();

  if (toolbus_mode) {
    #ifndef WIN32 /* Code with Toolbus calls, non Windows */
      ATBinit(argc, argv, &bottomOfStack);  /* Initialize the Aterm library */
      cid = ATBconnect(NULL, NULL, -1, asfchecker_handler);
      ATBeventloop();
    #else
      ATwarning("asfchecker: Toolbus cannot be used in Windows.\n");
    #endif
  }
  else {
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
        case 'v':  run_verbose = ATtrue;                   break;
        case 'i':  input=optarg;                           break;
	case 's':  statistics=ATtrue;                      break;
        case 'V':  version(); exit(0);                     break;
  
        case 'h':
        default:   usage(); exit(0);                       break;
      }
    }
    argc -= optind;
    argv += optind;

    rules = ATreadFromNamedFile(input);

    msgs = checkAsf(rules);

    if (!ATisEmpty(msgs)) {
      ERR_Summary sum = ERR_makeSummarySummary("asfchecker",input,msgs);
      ERR_displaySummary(sum);
      return 1;
    }
  }

  return 0;
}

/*}}}  */
