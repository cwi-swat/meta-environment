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

/*}}}  */
/*{{{  globals */

static char myname[]    = "filterasfsyntax";
static char myversion[] = "0.1";
static char myarguments[] = "hi:o:V";

/*}}}  */

#define filterEquationSyntax(a) (a)

/*{{{  void usage(void) */

void usage(void)
{
    fprintf(stderr,
        "Usage: %s -h -i arg -o arg -V . . .\n"
        "Options:\n"
        "\t-h              display help information (usage)\n"
        "\t-i filename     input from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myname, myversion);
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
  
  while ((c = getopt(argc, argv, myarguments)) != EOF)
    switch (c) {
      case 'h':  usage();                      exit(0);
      case 'i':  input_file_name  = optarg;    break;
      case 'o':  output_file_name = optarg;    break;
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

  parsetree = filterEquationSyntax(parsetree);

  ATwriteToNamedBinaryFile((ATerm) parsetree, output_file_name);

  return 0;
}

/*}}}  */
