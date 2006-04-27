/*{{{  includes */

#include <time.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <aterm2.h>

#include <MEPT.h>
#include <PTMEPT.h>
#include <ASFME.h>
#include <Error.h>
#include <Location.h>
#include <asc-support-me.h>
#include <MEPT-utils.h>

#include "asfe.tif.h"
#include "evaluator.h"
#include "errors.h"
#include "test-runner.h"
#include "debug.h"

/*}}}  */
/*{{{  defines */

#define TICK2SEC(t)             (((double)(t))/CLK_TCK)
#include "asc-support-me.h"
#include "debug.h"

/*}}}  */
/*{{{  variables */

static char myarguments[] = "abd:e:hi:lmo:p:tvV";
static char myname[] = "asfe";
static char myversion[] = "0.8";

int toolbus_id = -1;
ATerm acknowledgement = NULL;
static int tide_port;
/*}}}  */

/*{{{  void usage(char *prg, ATbool is_err) */

/*     Usage: displays helpful usage information
 */

void usage(char *prg, ATbool is_err)
{
  ATwarning("Rewrites a parse tree according to a parsed ASF+SDF "
	    "specification.\n"
	    "Usage: %s [options]\n"
	    "Options:\n"
	    "\t-a              allow ambiguous trees as input (default off)\n"
	    "\t-b              output terms in BAF format (default)\n"
	    "\t-d port         connect to the tide debugger at a port\n"
	    "\t-t              output terms in plaintext format\n"
	    "\t-h              display help information (usage)\n"
	    "\t-e file         use the equations |file|\n"
	    "\t-i filename     input from file (default stdin)\n"
	    "\t-l              replace all layout by a single space\n"
	    "\t-m              mark new layout for pretty printing\n"
	    "\t-o filename     output to file (default stdout)\n"
	    "\t-p filename     input parse table (not necessary)\n"
	    "\t-v              verbose mode\n"
	    "\t-V              reveal program version (i.e. %s)\n",
	    prg, 
	    myversion);
  exit(is_err ? 1 : 0);
}

/*}}}  */
/*{{{  void version(char *prg) */

void version(char *prg)
{
  ATwarning("%s v%s\n", prg, myversion);
  exit(1);
}

/*}}}  */
/*{{{  void abort_handler(int signal) */

void abort_handler(int signal)
{
  RWaddError("aborted by user", "");
}

/*}}}  */

/* ToolBus interfacing */
/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  if (useTide) {
    Tide_disconnect();
  }
  exit(0);
}

/*}}}  */
/*{{{  void rec_ack_event(int cid, ATerm t) */

void rec_ack_event(int cid, ATerm t)
{
  /* Post acknowlegdment in global variable such that builtin can
   * take it
   */

  acknowledgement = t;
}

/*}}}  */
/*{{{  ATerm interpret(int cid, char *modname, ATerm trm, ATerm tide) */

ATerm interpret(int cid, const char *modname, ATerm eqs, ATerm parseTable, 
		ATerm trm, ATerm tide)
{
  PT_ParseTree parseTree;
  ASF_ASFConditionalEquationList eqsList;
  ATerm result;
  ATbool debug;

  if (!ATmatch(parseTable, "none")) {
    setParseTable(parseTable); 
  }

  setCid(cid);		// render cid accessible from the outside

  /* connect to TIDE debugger in case TIDE support is currently active */
  if (ATmatch(tide, "on")) {
    debug = ATtrue;
    Tide_connect(ATBgetPort(cid));
  }
  else {
    debug = ATfalse;
  }

  eqs = ATBunpack(eqs);
  eqsList = ASF_ASFConditionalEquationListFromTerm(eqs);

  trm = ATBunpack(trm);
  parseTree = PT_ParseTreeFromTerm(trm);

  result
    = evaluator(modname, parseTree, eqsList, debug, ATfalse, ATfalse, ATtrue);

  if (RWgetErrors() == NULL || ERR_isErrorListEmpty(RWgetErrors())) {
    return ATmake("snd-value(rewrite-result(<term>))", ATBpack(result));
  }
  else {
    return ATmake("snd-value(rewrite-errors(<term>))", RWgetErrors());
  }
}

/*}}}  */
/*{{{  ATerm run_tests(int cid, ATerm eqs, ATerm tests, ATerm tide) */

ATerm run_tests(int cid, ATerm eqs, ATerm tests, ATerm tide)
{
  ASF_ASFConditionalEquationList eqsList;
  ASF_ASFTestEquationTestList testList;
  ATerm result;
  ATbool debug;

  /* connect to TIDE debugger in case TIDE support is currently active */
  if (ATmatch(tide, "on")) {
    debug = ATtrue;
    Tide_connect(ATBgetPort(cid));
  }
  else {
    debug = ATfalse;
  }

  eqs = ATBunpack(eqs);
  eqsList = ASF_ASFConditionalEquationListFromTerm(eqs);

  tests = ATBunpack(tests);
  testList = ASF_ASFTestEquationTestListFromTerm(tests);

  result = (ATerm) runTests(eqsList, testList, debug);

  if (debug) {
    Tide_disconnect();
  }

  result = (ATerm) runTests(eqsList, testList, debug);

  if (debug) {
    Tide_disconnect();
  }

  if (RWgetErrors() == NULL || !ERR_isErrorListEmpty(RWgetErrors())) {
    return ATmake("snd-value(<term>)", result);
  }
  else {
    return ATmake("snd-value(rewrite-errors(<term>))", RWgetErrors());
  }
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  FILE *iofile;
#ifdef PROFILING
  struct tms start, rewriting;
  clock_t user, system;
#endif
  int c, toolbus_mode = 0;
  char *input = "-";
  char *output = "-";
  char *eqsfile = "-";
  char *parsetable = NULL;
  int bafmode = 1;
  ATbool use_tide = ATfalse;
  ATbool remove_layout = ATfalse;
  ATbool mark_new_layout = ATfalse;
  ATbool allow_ambs = ATfalse;
  char *name = "Standalone";
  int returncode = 0;
  ATerm eqs, term, result;
  ASF_ASFConditionalEquationList eqsList;
  PT_ParseTree parseTree;

  /*  Check whether we're a ToolBus process  */
  for (c = 1; !toolbus_mode && c < argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  signal(SIGUSR1, abort_handler);

  ATinit(argc, argv, &bottomOfStack);
  /*ATsetChecking(ATtrue);*/
  PT_initMEPTApi();
  ERR_initErrorApi();
  LOC_initLocationApi();
  PTPT_initPTMEPTApi();
  ASF_initASFMEApi();

  if (toolbus_mode) {
#ifndef WIN32			/* Code with Toolbus calls, non Windows */
    ATBinit(argc, argv, &bottomOfStack);
    toolbus_id = ATBconnect(NULL, NULL, -1, asfe_handler);
    ATBeventloop();
#else
    ATwarning("asfe: Toolbus cannot be used in Windows.\n");
#endif
  }
  else {
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
	case 'a': allow_ambs = ATtrue;             break;
	case 'b': bafmode = 1;                     break;
	case 'd': 
		  use_tide = ATtrue;
		  tide_port = atoi(optarg);
		  break;
	case 't': bafmode = 0;                     break;
	case 'v': runVerbose = ATtrue;             break;
	case 'e': eqsfile = optarg;                break;
	case 'i': input = optarg;                  break;
        case 'l': remove_layout=ATtrue;            break;		  
        case 'm': mark_new_layout=ATtrue;          break;		  
	case 'o': output = optarg;                 break;
	case 'p': parsetable = optarg;             break;
	case 'V': version(argv[0]);                break;
	case 'h': usage(argv[0], ATfalse);         break;
	default: usage(argv[0], ATtrue);           break;
      }
    }

    /* Get the equations from file */
    if (!(iofile = fopen(eqsfile, "rb"))) {
      ATerror("%s: cannot open %s\n", myname, eqsfile);
    }

    if (parsetable != NULL) {
      ATerm pt = ATreadFromNamedFile(parsetable);
      if (pt != NULL) {
	setParseTable(pt);
      }
      else {
	ATerror("%s: cannot open %s\n", myname, parsetable);
      }
    }

    eqs = ATreadFromFile(iofile);
    eqsList = ASF_ASFConditionalEquationListFromTerm(eqs);

    if (fileno(iofile) != fileno(stdin)) {
      fclose(iofile);
    }

    /* Get the term from file */
    if (!strcmp(input, "") || !strcmp(input, "-")) {
      iofile = stdin;
    } else if (!(iofile = fopen(input, "rb"))) {
      ATerror("%s: cannot open %s\n", myname, input);
    }

    term = ATreadFromFile(iofile);

    if (term == NULL) {
      ATerror("%s: input file %s is not an ATerm\n", myname, input);
    }

    parseTree = PT_ParseTreeFromTerm(term);


    if (fileno(iofile) != fileno(stdin)) {
      fclose(iofile);
    }

    /* Optionally connect to the tide debugger, but always initialize
     * the ToolBus layer, just in case somebody uses a builtin that
     * connects to the ToolBus
     */
    ATBinit(argc, argv, &bottomOfStack);
    if (use_tide) {
      Tide_connect(tide_port);
    }

    /*ATsetChecking(ATtrue);*/
    /* Rewrite the term */
    result = evaluator(name, parseTree, eqsList, use_tide, 
		       remove_layout, mark_new_layout, allow_ambs);

    /* If we have collected errors, pretty print them now */
    returncode = (RWgetErrors() == NULL || 
		  !ERR_isErrorListEmpty(RWgetErrors())) ? 0 : 1;

    if (RWgetErrors() != NULL &&
	!ERR_isErrorListEmpty(RWgetErrors())) {
      printErrors();
    }

    /* Communicate the reduct out of here */
    if (!strcmp(output, "") || !strcmp(output, "-")) {
      iofile = stdout;
    }
    else if (!(iofile = fopen(output, "wb"))) {
      ATerror("%s: cannot open %s\n", myname, output);
    }

    if (bafmode) {
      ATwriteToBinaryFile(result, iofile);
    }
    else {
      ATwriteToTextFile(result, iofile);
    }

    fclose(iofile);
  }

  if (use_tide) {
    Tide_disconnect();
  }

  return returncode;
}

/*}}}  */
