/* $Id$ */ 

#include <atb-tool.h>
#include "sdfchecker.h"

#include <stdio.h>
#include <stdlib.h>     /* used for exit(0) */
#include <assert.h>
#include <ctype.h>
#include <unistd.h>

#include <asc-support2-me.h>
#include <MEPT-utils.h>
#include <Error-utils.h>
#include <SDFME-utils.h>

static char *name;

ATbool run_verbose;

static char myname[] = "sdfchecker";
static char myversion[] = "1.0";

/* The argument vector: list of option letters, colons denote option
 * arguments. See Usage function, immediately below, for option explanation. */
static char myarguments[] = "m:hi:vV";

void init_patterns();
void c_rehash(int newsize);

extern void register_Sdf_Checker();
extern void resolve_Sdf_Checker();
extern void init_Sdf_Checker();


static PT_Tree addSdfCheckerFunction(const char *name, PT_ParseTree parseTree) {
  SDF_ModuleId sdfModuleId = SDF_makeModuleId(name);
  PT_Tree ptModuleId = PT_TreeFromTerm(SDF_ModuleIdToTerm(sdfModuleId));
  PT_Tree newTree = NULL;

  if (PT_isValidParseTree(parseTree)) {
    PT_Tree ptSyntax = PT_getParseTreeTree(parseTree);

    newTree = PT_applyFunctionToTree("check-sdf", "Summary", 2, ptSyntax, ptModuleId);
  }
  else {
    ATerror("addSdfCheckerFunction: not a proper parse tree: %t\n",
            (ATerm) parseTree);
  }

  return newTree;
}

static ATerm checkSdf(const char *name, ATerm term) {
  PT_ParseTree parseTree;
  PT_Tree ptApplied;
  ATerm reduct;
  PT_Tree asfix;

  setKeepAnnotations(ATtrue);
  parseTree = PT_ParseTreeFromTerm(term);
  ptApplied = addSdfCheckerFunction(name, parseTree);
  reduct    = innermost(ptApplied);
  asfix     = toasfix(reduct);

  return PT_ParseTreeToTerm(PT_makeValidParseTreeFromTree(asfix));
}

static void displayMessages(ATerm term) {
  PERR_Start pStart;
  PERR_Summary pSummary;
  ERR_Summary summary;

  pStart = PERR_StartFromTerm(term);
  pSummary = PERR_getStartTopSummary(pStart);
  summary = PERR_lowerSummary(pSummary);
  ERR_displaySummary(summary);
}

ATerm check_sdf(int cid, ATerm term) {
  ATerm  output = checkSdf("Main", ATBunpack(term));

  return ATmake("snd-value(feedback(<term>))", output);
}

void rec_terminate(int cid, ATerm arg) {
  exit(0);
}

static void usage(void) {
  ATwarning(
    "Usage: %s -m file -h -i file -vV . . .\n"
    "Options:\n"
    "\t-h              display help information (usage)\n"
    "\t-m module       topmodule of specification (default: Main)\n"
    "\t-i filename     input from file (default stdin)\n"
    "\t-v              verbose mode\n"
    "\t-V              reveal program version (i.e. %s)\n",
    myname, myversion);
}

static void version(void) {
  ATwarning("%s v%s\n", myname, myversion);
}

int main(int argc, char *argv[]) {
  ATerm syntax = NULL, msgs = NULL;
  char *moduleName = "Main";
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
  initErrorApi();

  ASC_initRunTime(INITIAL_TABLE_SIZE);
  SDF_initSDFMEApi();
  ERR_initErrorApi();
  PERR_initParsedErrorApi();

  register_Sdf_Checker();
  resolve_Sdf_Checker();
  init_Sdf_Checker();

  if (toolbus_mode) {
    ATBinit(argc, argv, &bottomOfStack);  /* Initialize the Aterm library */
    cid = ATBconnect(NULL, NULL, -1, sdfchecker_handler);
    ATBeventloop();
  }
  else {
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
        case 'm':  moduleName=optarg;                      break;
        case 'v':  run_verbose = ATtrue;                   break;
        case 'i':  input=optarg;                           break;
        case 'V':  version(); exit(0);                     break;
  
        case 'h':  usage(); exit(0);                       break;
        default:   usage(); exit(1);                       break;
      }
    }
    argc -= optind;
    argv += optind;

    syntax = ATreadFromNamedFile(input);

    msgs = checkSdf(moduleName, syntax);
    
    displayMessages(msgs);
  }
  return 0;
}
