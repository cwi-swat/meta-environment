#ifndef WIN32
        /* These files can not be included in Windows NT*/
        #include <atb-tool.h>
        #include "asfsdfchecker.tif.h"
#endif

#include <stdio.h>
#include <stdlib.h>     /* used for exit(0) */
#include <assert.h>
#include <ctype.h>
#include <unistd.h>

#include <asc-support2-me.h>
#include <MEPT-utils.h>
#include <SDFME-utils.h>
#include <Error-utils.h>

static char *name;

ATbool run_verbose;

static char myname[] = "asfsdfchecker";
static char myversion[] = "1.0";

/*
 * The argument vector: list of option letters, colons denote option
 * arguments.  See Usage function, immediately below, for option
 * explanation.
 * */

static char myarguments[] = "hi:vV";

void init_patterns();
void c_rehash(int newsize);

extern void register_AsfSdf_Checker();
extern void resolve_AsfSdf_Checker();
extern void init_AsfSdf_Checker();


/*{{{  static PT_Tree addSdfCheckerFunction(PT_ParseTree parseTree) */

static PT_Tree addAsfSdfCheckerFunction(PT_ParseTree parseTree, 
                                        const char *str )
{
  PT_Tree newTree = NULL;

  SDF_ModuleId strCon = SDF_makeModuleId((char *)str);
  if (PT_isValidParseTree(parseTree)) {
    PT_Tree ptSyntax = PT_getParseTreeTree(parseTree);

    newTree = PT_applyFunctionToTree("check-asfsdf", "Summary", 2, ptSyntax,
				     SDF_ModuleIdToTerm(strCon));
  }
  else {
    ATerror("addSdfCheckerFunction: not a proper parse tree: %t\n",
            (ATerm) parseTree);
  }

  return newTree;
}

/*}}}  */

static ATerm checkAsfSdf(ATerm term, const char *name)
{
  PT_ParseTree parseTree;
  PT_Tree ptApplied;
  ATerm reduct;
  PT_ParseTree asfix;

  setKeepAnnotations(ATtrue);
  parseTree = PT_ParseTreeFromTerm(term);
  ptApplied = addAsfSdfCheckerFunction(parseTree, name);
  reduct = innermost(ptApplied);
  asfix = toasfix(reduct);

  return PT_ParseTreeToTerm(asfix);
}

static void displayMessages(ATerm term)
{
  PERR_Start pStart = PERR_StartFromTerm(term);
  PERR_Summary pSummary = PERR_getStartTopSummary(pStart);
  ERR_Summary summary = PERR_lowerSummary(pSummary);
  ERR_displaySummary(summary);
}

ATerm check_asfsdf(int cid, ATerm term, const char *name)
{
  ATerm output = checkAsfSdf(ATBunpack(term), name);

  return ATmake("snd-value(feedback(<term>))", output);
}

void rec_terminate(int cid, ATerm arg)
{
  exit(0);
}

static void usage(void)
{
  ATwarning(
    "Usage: %s -h -i file -vV . . .\n"
    "Options:\n"
    "\t-h              display help information (usage)\n"
    "\t-i filename     input from file (default stdin)\n"
    "\t-v              verbose mode\n"
    "\t-V              reveal program version (i.e. %s)\n",
    myname, myversion);
}

static void version(void)
{
  ATwarning("%s v%s\n", myname, myversion);
}

int main(int argc, char *argv[])
{
  ATerm syntax = NULL, msgs = NULL;
  char *input = "-";
  int cid;
  int c, toolbus_mode = 0;
  ATerm bottomOfStack;
  name = argv[0];

/*  Check whether we're a ToolBus process  */
  for(c=1; !toolbus_mode && c<argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  ATinit(argc, argv, &bottomOfStack);
  SDF_initSDFMEApi();
  initErrorApi();

  ASC_initRunTime(INITIAL_TABLE_SIZE);

  register_AsfSdf_Checker();
  resolve_AsfSdf_Checker();
  init_AsfSdf_Checker();

  if (toolbus_mode) {
    #ifndef WIN32 /* Code with Toolbus calls, non Windows */
      ATBinit(argc, argv, &bottomOfStack);  /* Initialize the Aterm library */
      cid = ATBconnect(NULL, NULL, -1, asfsdfchecker_handler);
      ATBeventloop();
    #else
      ATwarning("asfsdfchecker: Toolbus cannot be used in Windows.\n");
    #endif
  }
  else {
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
        case 'v':  run_verbose = ATtrue;                   break;
        case 'i':  input=optarg;                           break;
        case 'V':  version(); exit(0);                     break;
  
        case 'h':
        default:   usage(); exit(0);                       break;
      }
    }
    argc -= optind;
    argv += optind;

    syntax = ATreadFromNamedFile(input);

    msgs = checkAsfSdf(syntax, input);

    displayMessages(msgs);
  }
  return 0;
}
