/* $Id$ */

/*{{{  includes */

#include <time.h>

#define TICK2SEC(t)             (((double)(t))/CLK_TCK)

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <aterm2.h>

#include <MEPT.h>
#include <PTMEPT.h>
#include <ASFME.h>
#include <ASFAPI.h>

#include "asfe.tif.h"
#include "evaluator.h"
#include "errors.h"

#ifdef USE_TIDE
#include "debug.h"
#endif

/*}}}  */
/*{{{  variables */

static char myarguments[] = "abde:hi:lmo:w:tvV";
static char myname[] = "asfe";
static char myversion[] = "0.6";

/* global tool id for ToolBus purposes */
int toolbus_id = -1;

/*}}}  */

/*{{{  void usage(char *prg, ATbool is_err) */

/*     Usage: displays helpful usage information
 */

void usage(char *prg, ATbool is_err)
{
  ATwarning("Usage: %s [options]\n"
	    "Options:\n"
	    "\t-a              allow ambiguous trees as input (default off)\n"
	    "\t-b              output terms in BAF format (default)\n"
#ifdef USE_TIDE
	    "\t-d              connect to the tide debugger\n"
#endif
	    "\t-t              output terms in plaintext format\n"
	    "\t-h              display help information (usage)\n"
	    "\t-e file         use the equations |file|\n"
	    "\t-i filename     input from file (default stdin)\n"
	    "\t-l              replace all layout by a single space\n"
	    "\t-m              mark new layout for pretty printing\n"
	    "\t-o filename     output to file (default stdout)\n"
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
  RWsetError("aborted by user", (ATerm) ATempty);
}

/*}}}  */

/* ToolBus interfacing */
/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */
/*{{{  void rec_ack_event(int cid, ATerm t) */

void rec_ack_event(int cid, ATerm t)
{
  /* do nothing */
}

/*}}}  */
/*{{{  ATerm interpret(int cid, char *modname, ATerm trm, ATerm tide) */

ATerm interpret(int cid, char *modname, ATerm eqs, ATerm trm, ATerm tide)
{
  PT_ParseTree parseTree;
  ASF_CondEquationList eqsList;
  ATerm result;
  ATbool debug;

  if (ATmatch(tide, "on")) {
    debug = ATtrue;
#ifdef USE_TIDE
    Tide_connect();
#endif
  }
  else {
    debug = ATfalse;
  }

  /*ATfprintf(stderr, "equations: %t\n", eqs);*/
  eqsList = ASF_makeCondEquationListFromTerm(eqs);
  parseTree = PT_makeParseTreeFromTerm(trm);

  result = evaluator(modname, parseTree, eqsList, debug, ATfalse, ATfalse,
		     ATtrue);

  if (RWgetError() == NULL) {
    return ATmake("snd-value(rewrite-result(<term>))", ATBpack(result));
  }
  else {
    return ATmake("snd-value(rewrite-errors([<term>]))", RWgetError());
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
  int bafmode = 1;
  ATbool use_tide = ATfalse;
  ATbool remove_layout = ATfalse;
  ATbool mark_new_layout = ATfalse;
  ATbool allow_ambs = ATfalse;
  char *name = "Standalone";
  int returncode = 0;
  ATerm eqs, term, result;
  ASF_CondEquationList eqsList;
  PT_ParseTree parseTree;

  /*  Check whether we're a ToolBus process  */
  for (c = 1; !toolbus_mode && c < argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  signal(SIGUSR1, abort_handler);

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  PTPT_initPTMEPTApi();
  ASF_initASFMEApi();
  AA_initASFAPIApi();

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
	case 't': bafmode = 0;                     break;
	case 'v': runVerbose = ATtrue;             break;
	case 'e': eqsfile = optarg;                break;
	case 'i': input = optarg;                  break;
        case 'l': remove_layout=ATtrue;            break;		  
        case 'm': mark_new_layout=ATtrue;          break;		  
	case 'o': output = optarg;                 break;
	case 'd': use_tide = ATtrue;		   break;
	case 'V': version(argv[0]);                break;
	case 'h': usage(argv[0], ATfalse);         break;
	default: usage(argv[0], ATtrue);           break;
      }
    }

    /* Get the equations from file */
    if (!(iofile = fopen(eqsfile, "rb"))) {
      ATerror("%s: cannot open %s\n", myname, eqsfile);
    }

    eqs = ATreadFromFile(iofile);
    eqsList = ASF_makeCondEquationListFromTerm(eqs);
    fclose(iofile);

    /* Get the term from file */
    if (!strcmp(input, "") || !strcmp(input, "-")) {
      iofile = stdin;
    } else if (!(iofile = fopen(input, "rb"))) {
      ATerror("%s: cannot open %s\n", myname, input);
    }

    term = ATreadFromFile(iofile);
    parseTree = PT_makeParseTreeFromTerm(term);
    fclose(iofile);

    /* Optionally connect to the tide debugger */
    if (use_tide) {
#ifdef USE_TIDE
      ATBinit(argc, argv, &bottomOfStack);
      Tide_connect();
#else
      ATwarning("tide support is not enabled! (try configuring --with-tide)\n");
      exit(1);
#endif
    }

    /* Rewrite the term */
    result = evaluator(name, parseTree, eqsList, use_tide, 
		       remove_layout, mark_new_layout, allow_ambs);

    /* If we have collected errors, pretty print them now */
    returncode = (RWgetError() == NULL) ? 0 : 1;

    if (RWgetError() != NULL) {
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

#ifdef USE_TIDE
  if (use_tide) {
    Tide_disconnect();
  }
#endif

  return returncode;
}

/*}}}  */
