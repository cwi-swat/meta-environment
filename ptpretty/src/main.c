#include <SDFME-utils.h>
#include <MEPT-utils.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pretty.h"

static char* myname = "ptpretty";
static char* myversion = "0.1";
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
  char *syntax = "";
  int c;

  ATerm at_sdf;
  ATerm at_tree;
  PT_ParseTree tree;
  SDF_SDF sdf;

  ATinit(argc, argv, &bottomOfStack); 
  PT_initMEPTApi(); 
  SDF_initSDFMEApi(); 

  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'i':  input=optarg; break;
      case 's':  syntax=optarg; break;
      case 'o':  output=optarg; break;
      case 'v':  run_verbose = ATtrue; break;
      case 'V':  version(); exit(0);
      case 'h':  usage(); exit(0);
      default:   usage(); exit(1); 
    }
  }

  if (!strcmp(syntax,"")) {
    ATwarning("%s: You forgot to specify a syntax definition.\n", myname);
    usage();
    exit(1);
  }


  ATsetChecking(ATtrue);

  at_sdf = ATreadFromNamedFile(syntax);
  at_tree   = ATreadFromNamedFile(input);

  tree = PT_ParseTreeFromTerm(at_tree);
  sdf = SDF_SDFFromTerm((ATerm) PT_getParseTreeTree(PT_ParseTreeFromTerm(at_sdf)));

  tree = pretty(sdf, tree);

  ATwriteToNamedBinaryFile(PT_ParseTreeToTerm(tree), output);
  
  return 0;
}

/*}}}  */
