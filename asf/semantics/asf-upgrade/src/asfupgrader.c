#include <atb-tool.h>
#include "asfupgrader.tif.h"

#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include <ctype.h>
#include <unistd.h>

#include <MEPT-utils.h>
#include <ASFME-utils.h>

#include "equationUpgrader.h"

/*{{{  globals */

static char *name;

ATbool run_verbose;

static char myname[] = "asfchecker";
static char myversion[] = "0.1";
static char myarguments[] = "hi:o:vV";

/*}}}  */

/*{{{  static ATermList checkAsf(ATerm term) */

static ATerm upgradeAsf(ATerm term)
{
  if (ATgetType(term) == AT_LIST) {
    ASF_ASFConditionalEquationList rules = ASF_makeASFConditionalEquationListFromTerm(term);
    return (ATerm) upgradeASFConditionalEquationList(rules);
  }
  else {
    PT_ParseTree parseTree = PT_ParseTreeFromTerm(term);
    PT_Tree ptRules = PT_getParseTreeTree(parseTree);
    ASF_ASFModule module = ASF_ASFModuleFromTerm(
				      PT_makeTermFromTree(ptRules));
      return (ATerm) PT_setParseTreeTree(parseTree, (PT_Tree) upgradeModule(module));
  }
}

/*}}}  */

/*{{{  ATerm check_asf(int cid, ATerm term) */

ATerm upgrade(int cid, ATerm term)
{
  term  = upgradeAsf(ATBunpack(term));    

  return ATmake("snd-value(upgraded(<term>))", term);
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
    "\t-o filename     output to file (default stdout)\n"
    "\t-v              verbose mode\n"
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
  char *input = "-";
  char *output = "-";
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
  /*SDF_initSDFMEApi();*/
  ASF_initASFMEApi();

  if (toolbus_mode) {
    #ifndef WIN32 /* Code with Toolbus calls, non Windows */
      ATBinit(argc, argv, &bottomOfStack);  /* Initialize the Aterm library */
      cid = ATBconnect(NULL, NULL, -1, asfupgrader_handler);
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
        case 'o':  output=optarg;                           break;
        case 'V':  version(); exit(0);                     break;
  
        case 'h':
        default:   usage(); exit(0);                       break;
      }
    }
    argc -= optind;
    argv += optind;

    rules = ATreadFromNamedFile(input);

    rules = upgradeAsf(rules);

    ATwriteToNamedTextFile(rules, output);
  }

  return 0;
}

/*}}}  */
