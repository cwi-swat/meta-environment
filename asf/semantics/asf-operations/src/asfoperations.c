#include <atb-tool.h>
#include "asfoperations.tif.h"

#include <stdio.h>
#include <stdlib.h>  
#include <assert.h>
#include <ctype.h>
#include <unistd.h>

#include <MEPT-utils.h>
#include <PTMEPT.h>
#include <ASFME-utils.h>
#include <asfnormalization.h>

/*{{{  globals */

static char *name;

ATbool run_verbose;

static char myname[] = "asfoperations";
static char myversion[] = "1.0";
static char myarguments[] = "hVi:lo:";

/* TODO: see if another solution can be found to optimize this */
static ATermTable cache = NULL;

/*}}}  */
/*{{{  ATerm extract_equations(int cid, ATerm modules) */

ATerm extract_equations(int cid, ATerm modules)
{
  ATermList list = (ATermList) modules;
  ASF_ASFConditionalEquationList eqsList;

  eqsList = ASF_makeASFConditionalEquationListEmpty();

  for(;!ATisEmpty(list); list = ATgetNext(list)) {
    ATerm head = ATBunpack(ATgetFirst(list));
    ASF_ASFModule module = ASF_getStartTopASFModule(ASF_StartFromTerm(head));

    eqsList = ASF_unionASFConditionalEquationList(eqsList, ASF_makeLayoutNewline(),
		  ASF_getASFModuleEquationList(module));
  }

  return ATmake("snd-value(extract-equations-result(<term>))",
		ATBpack(ASF_ASFConditionalEquationListToTerm(eqsList)));
}

/*}}}  */
/*{{{  ATerm extract_tests(int cid, ATerm modules) */

ATerm extract_tests(int cid, ATerm modules)
{
  ATermList list = (ATermList) modules;
  ASF_ASFTestEquationTestList testList;
  ASF_OptLayout ws = ASF_makeLayoutNewline();

  testList = ASF_makeASFTestEquationTestListEmpty();

  while (!ATisEmpty(list)) {
    ATerm head = ATBunpack(ATgetFirst(list));
    ASF_ASFModule module = ASF_getStartTopASFModule(ASF_StartFromTerm(head));

    testList = ASF_concatASFTestEquationTestList(testList,
						 ws,
						 ASF_getASFModuleTestList(module));
   
    list = ATgetNext(list);
  }

  return ATmake("snd-value(extract-tests-result(<term>))",
		ATBpack(ASF_ASFTestEquationTestListToTerm(testList)));
}

/*}}}  */
/*{{{  ATerm normalize_module(int cid, ATerm module) */

ATerm normalize_module(int cid, ATerm module)
{
  ASF_Start start = ASF_StartFromTerm(ATBunpack(module));
  ASF_ASFModule mod = ASF_getStartTopASFModule(start);
  ASF_ASFModule result;

  if (cache == NULL) {
    cache = ATtableCreate(1024, 75);
  }

  result = ASF_ASFModuleFromTerm(ATtableGet(cache, (ATerm) mod));

  if (result == NULL) {
    result = normalize(mod);
    ATtablePut(cache, (ATerm) mod, (ATerm) result);
  }

  assert(result != NULL);

  start = ASF_makeStartASFModule(ASF_getStartWsBefore(start),
				 result,
				 ASF_getStartWsAfter(start),
				 ASF_getStartAmbCnt(start));

  return ATmake("snd-value(normalized-module(<term>))", 
		ATBpack(ASF_StartToTerm(start)));
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
    "A ToolBus tool to service operations on ASF modules.\n"
    "On the commandline it can be used to normalize an ASF module\n"
    "which is practical for bootstrapping purposes\n\n"
    "Usage: %s -h -V . . .\n"
    "Options:\n"
    "\t-h              display help information (usage)\n"
    "\t-i              input file for ASF normalizer\n"
    "\t-l              only lift user-defined syntax, no normalization\n"
    "\t-o              output of normalizer\n"
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
  char *inputFile = "-";
  char *outputFile = "-";
  ATbool onlyLift = ATfalse;
  ATerm input;
  ATerm output;
  name = argv[0];

/*  Check whether we're a ToolBus process  */
  for(c=1; !toolbus_mode && c<argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  PTPT_initPTMEPTApi();
  ASF_initASFMEApi();

  if (toolbus_mode) {
    ATBinit(argc, argv, &bottomOfStack);  
    cid = ATBconnect(NULL, NULL, -1, asfoperations_handler);
    ATBeventloop();
  }
  else {
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
        case 'V':  version(); exit(0);                     break;
	case 'i':  inputFile = optarg; break;
	case 'l':  onlyLift = ATtrue; break;
	case 'o':  outputFile = optarg; break;
        case 'h':
        default:   usage(); exit(0);                       break;
      }
    }

    input = ATreadFromNamedFile(inputFile);

    if (input != NULL) {
      ASF_Start start = ASF_StartFromTerm(input);
      ASF_ASFModule mod = (ASF_ASFModule) PT_getParseTreeTree((PT_ParseTree) start);
      ASF_ASFModule result;

      if (!onlyLift) {
	result = normalize(mod);
      }
      else {
	result = ASF_liftModule(mod);
      }

      start = (ASF_Start) PT_setParseTreeTree((PT_ParseTree) start, (PT_Tree) result);
      output = ASF_StartToTerm(start);
      ATwriteToNamedTextFile(output, outputFile);
    }
    else {
      ATerror("could not read input file\n");
    }

  }
  return 0;
}

/*}}}  */
