#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <MEPT-utils.h>

#include "pandora.h"

static char* myname = "pandora";
static char* myversion = VERSION;
static char* myarguments = "i:o:vVhs:";
static ATbool run_verbose = ATfalse;

/*{{{  void usage(void) */

/*
 *     Usage: displays helpful usage information
 */

static void usage(void)
{
  ATwarning(
	    "Usage: %s [options]\n"
	    "Options:\n"
	    "\t-h              display help information\n"
	    "\t-i filename     input (parsed) file                [stdin]\n"
	    "\t-o filename     output (parsed) file               [stdout]\n"
	    "\t-s filename     input (parsed) syntax definition   [obligatory]\n"
	    "\t-v              verbose mode\n"
	    "\t-V              reveal program version (i.e. %s)\n",
	    myname, myversion);
}

/*}}}  */
/*{{{  void version(void) */

static void version(void)
{
  ATwarning("%s v%s\n", myname, myversion);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[]) 
{
  ATerm bottomOfStack;
  char *input = "-";
  char *output = "-";
  int c;

  ATerm at_tree;
  PT_ParseTree tree;

  BOX_BoxList boxlist;

  ATinit(argc, argv, &bottomOfStack); 
  PT_initMEPTApi(); 
  BOX_initBoxApi();

  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'i':  input=optarg; break;
      case 'o':  output=optarg; break;
      case 'v':  run_verbose = ATtrue; break;
      case 'V':  version(); exit(0);
      case 'h':  usage(); exit(0);
      default:   usage(); exit(1); 
    }
  }

  at_tree = ATreadFromNamedFile(input);

  if (at_tree != NULL) {

    tree = PT_ParseTreeFromTerm(at_tree);

    boxlist = pandora(tree);

    ATwriteToNamedBinaryFile(BOX_BoxListToTerm(boxlist), output);

    return 0;
  }

  ATwarning("No such file: %s\n", input); 
  return 1; 
}

/*}}}  */
