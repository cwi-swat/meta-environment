/*
 * $Id$
 */

/*{{{  includes */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <aterm2.h>
#include <MEPT-utils.h>
#include <ASFME-utils.h>

#include "filtereqssyntax.h"

/*}}}  */
/*{{{  globals */

static char myname[]    = "filterasfsyntax";
static char myversion[] = "0.1";
static char myarguments[] = "hi:o:vV";
static ATbool run_verbose;

/*}}}  */

/*{{{  void usage(void) */

void usage(void)
{
    fprintf(stderr,
        "Usage: %s -h -i arg -o arg -vV . . .\n"
        "Options:\n"
        "\t-h              display help information (usage)\n"
        "\t-i filename     input from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-v              print verbose messages\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myname, myversion);
}

/*}}}  */

/*{{{  static PT_ParseTree filter(PT_ParseTree parsetree) */

static PT_ParseTree filter(PT_ParseTree parsetree)
{
  PT_Tree tree = PT_getParseTreeTree(parsetree);
  ATerm ambiguities;
  int count;

  if (run_verbose) {
    ATwarning("BEFORE FILTERING:\n%t\n", PT_reportTreeAmbiguities(tree));
  }

  tree = (PT_Tree) filterEquationSyntax((ASF_ASFEquations) tree);
  ambiguities = PT_reportTreeAmbiguities(tree);

  if (ATmatch(ambiguities,"ambiguities(<int>,[<list>])", &count, NULL)) {
    if (run_verbose) {
	ATwarning("AFTER FILTERING:\n%t\n", ambiguities);
    }

    parsetree = PT_setParseTreeTree(parsetree, tree);
    parsetree = PT_setParseTreeAmbCnt(parsetree, count);
  }
  else {
    ATerror("filter: unexpected ambiguity report: %t\n", ambiguities);
    return NULL;
  }

  return parsetree;
}

/*}}}  */

/*{{{  int main (int argc, char **argv) */

int main (int argc, char **argv)
{
  int c; 
  ATerm bottomOfStack;
  PT_ParseTree parsetree;
  char   *input_file_name  = "-";
  char   *output_file_name = "-";

  ATinit(argc, argv, &bottomOfStack);    /* Initialize Aterm library */
  PT_initMEPTApi();
  ASF_initASFMEApi();

  run_verbose = ATfalse;

  while ((c = getopt(argc, argv, myarguments)) != EOF)
    switch (c) {
      case 'h':  usage();                      exit(0);
      case 'i':  input_file_name  = optarg;    break;
      case 'o':  output_file_name = optarg;    break;
      case 'v':  run_verbose = ATtrue;         break;
      case 'V':  fprintf(stdout, "%s %s\n", myname, myversion);
                                               exit(0);
      default :  usage();                      exit(1);
  }

  ATinit(argc, argv, &bottomOfStack);    /* Initialize Aterm library */
  PT_initMEPTApi();
  ASF_initASFMEApi();

  parsetree = PT_ParseTreeFromTerm(ATreadFromNamedFile(input_file_name));

  if(parsetree == NULL) {
    ATerror("%s: could not read term from input file %s\n", 
	    myname, input_file_name);
  }

  parsetree = filter(parsetree);


  ATwriteToNamedBinaryFile((ATerm) parsetree, output_file_name);

  return 0;
}

/*}}}  */
