#ifndef WIN32
        /* These files can not be included in Windows NT*/
        #include <atb-tool.h>
        #include "sdfchecker.tif.h"
#endif

#include <stdio.h>
#include <stdlib.h>     /* used for exit(0) */
#include <assert.h>
#include <ctype.h>
#include <unistd.h>

#include <asc-support2-me.h>
#include <MEPT-utils.h>
#include <SDFME-utils.h>


static char *name;

ATbool run_verbose;

static char myname[] = "sdfchecker";
static char myversion[] = "0.0";

/*
 *     The argument vector: list of option letters, colons denote option
 *         arguments.  See Usage function, immediately below, for option
 *             explanation.
 *              */

static char myarguments[] = "hi:vV";

void init_patterns();
void c_rehash(int newsize);

extern void register_Sdf_Checker();
extern void resolve_Sdf_Checker();
extern void init_Sdf_Checker();


static PT_Tree addSdfCheckerFunction(PT_ParseTree parseTree)
{
  PT_Tree newTree = NULL;

  if (PT_isValidParseTree(parseTree)) {
    PT_Tree ptSyntax = PT_getParseTreeTree(parseTree);

    newTree = PT_applyFunctionToTree("check-sdf", "Messages", 1, ptSyntax);
  }
  else {
    ATerror("addSdfCheckerFunction: not a proper parse tree: %t\n",
            (ATerm) parseTree);
  }

  return newTree;
}

static ATerm checkSdf(ATerm term)
{
  PT_ParseTree parseTree = PT_makeParseTreeFromTerm(term);
  PT_Tree ptApplied      = addSdfCheckerFunction(parseTree);
  ATerm reduct           = innermost(ptApplied);
  PT_ParseTree asfix     = toasfix(reduct);

  return PT_makeTermFromParseTree(asfix);
}

static ATermList processMessages(ATerm term)
{
  ATermList resultMsgs = ATempty;
  ATerm newMsg;

  PT_ParseTree parseTree = PT_makeParseTreeFromTerm(term);

  if (PT_isValidParseTree(parseTree)) {
    PT_Tree ptMsgs = PT_getParseTreeTree(parseTree);
    PT_Args msgsArgs = PT_getTreeArgs(ptMsgs);
    PT_Tree msgs = PT_getArgsArgumentAt(msgsArgs, 2);
    if (PT_isTreeApplList(msgs)) {
      PT_Args msgsList = PT_getTreeArgs(msgs);

      while (PT_hasArgsHead(msgsList)) {
	PT_Tree msg = PT_getArgsHead(msgsList);
        if (!PT_isTreeLayout(msg)) {
          newMsg = ATmake("<str>", PT_yieldTree(msg));
	  resultMsgs = ATappend(resultMsgs, newMsg);
        }
	msgsList = PT_getArgsTail(msgsList);
      }
    }
  }
  return resultMsgs;
}

static void displayMessages(ATerm term)
{
  char *errorStr;

  ATermList errorList = processMessages(term);
  while (!ATisEmpty(errorList)) {
    ATerm error = ATgetFirst(errorList);
    if (ATmatch(error, "<str>", &errorStr)) {
      ATwarning("%s\n", errorStr);
    }
    errorList = ATgetNext(errorList);
  }
}

ATerm check_sdf(int cid, ATerm term)
{
  ATerm  output = checkSdf(ATBunpack(term));
  ATermList errorList = processMessages(output);

  return ATmake("snd-value(messages(<term>))", errorList);
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

  ASC_initRunTime(INITIAL_TABLE_SIZE);

  register_Sdf_Checker();
  resolve_Sdf_Checker();
  init_Sdf_Checker();

  if (toolbus_mode) {
    #ifndef WIN32 /* Code with Toolbus calls, non Windows */
      ATBinit(argc, argv, &bottomOfStack);  /* Initialize the Aterm library */
      cid = ATBconnect(NULL, NULL, -1, sdfchecker_handler);
      ATBeventloop();
    #else
      ATwarning("removevarsyntax: Toolbus cannot be used in Windows.\n");
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

    msgs = checkSdf(syntax);

    displayMessages(msgs);
  }
  return 0;
}
