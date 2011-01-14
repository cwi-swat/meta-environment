/*  $Id: main.c,v 1.1.2.3 2004/10/19 06:22:35 uid507 Exp $  */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <aterm2.h>
#include <MEPT-utils.h>

#include "minmax.h"
#include "flattenAgain.h"

static char myname[] = "filterPT";
static char myversion[] = "0.1";
static char myarguments[] = "hi:n:N:o:V";

/*{{{  void usage(void) */

void usage(void)
{
  fprintf(stderr,
	  "A tool for filtering parse forests.\n"
	  "Usage: %s [%s]\n"
          "Options:\n"
          "\t-h              display help information (usage)\n"
          "\t-i filename     input from file (default stdin)\n"
          "\t-o filename     output to file (default stdout)\n"
	  "\t-n sort-name    minimize occurrences of this sort name\n"
	  "\t-N sort-name    maximize occurrences of this sort name\n"
          "\t-V              reveal program version (i.e. %s)\n"
	  "\n",
          myname, myarguments, myversion);
}

/*}}}  */
/*{{{  void version(void) */

void version(void)
{
  fprintf(stderr, "%s v%s\n", myname, myversion);
}

/*}}}  */

#define XOR(a1, a2) ((a1 || a2) && !(a1 && a2))

/*{{{  int main(int argc, char **argv) */

int main(int argc, char **argv)
{
  int c;
  ATerm bottomOfStack;
  char   *input="-";
  char   *output="-";
  char   *argument = NULL;
  ATbool minimizeSort = ATfalse;
  ATbool maximizeSort = ATfalse;
  ATerm inputTerm = NULL;
  ATerm outputTerm = NULL;
  PT_ParseTree inputTree = NULL;
  PT_ParseTree outputTree = NULL;

  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'i':  
	input=optarg;
	break;
      case 'n':
	minimizeSort = ATtrue;
	argument = optarg;
	break;
      case 'N':
	maximizeSort = ATtrue;
	argument = optarg;
	break;
      case 'o':  
	output=optarg;     
	break;
      case 'V':  
	version();
	return 0;
      case 'h':
	usage();
	return 0;
      default:   
	usage();
	return 1;
    }
  }

  ATinit(argc, argv, &bottomOfStack);     
  PT_initMEPTApi();

  inputTerm = ATreadFromNamedFile(input);
  inputTree = PT_ParseTreeFromTerm(inputTerm);

  if (inputTerm != NULL) {
    /* The tool will always execute one filter at a time, such that the user
     * can implement his own scheduling by repeatedly using this tool.
     * Please do not change this behavior.
     */
    if (XOR(minimizeSort, maximizeSort) && argument != NULL) {
      PT_Symbol sort = PT_makeSymbolCf(PT_makeSymbolSort(argument));
      outputTree = minmax(inputTree, sort, minimizeSort);
    }
    else {
      usage();
      return 1;
    }

    if (outputTree != NULL) {
      outputTree = flattenAgain(outputTree);
      outputTerm = PT_ParseTreeToTerm(outputTree);

      ATwriteToNamedTextFile(outputTerm, output);
    }
    else {
      fprintf(stderr, "%s: filtering failed unexpectedly\n", myname);
      return 1;
    }
  }
  else {
    fprintf(stderr,"%s: could not open file %s\n", myname, input);
    return 1;
  }

  return 0;
}

/*}}}  */
