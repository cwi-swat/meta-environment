/*
 * $Id$
 */

/*{{{  standard includes */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*}}}  */
/*{{{  meta includes */

#include <aterm2.h>
#include <MEPT-utils.h>
#include <PTMEPT-utils.h>

/*}}}  */
/*{{{  globals */

static char myname[]    = "parsePT";
static char myversion[] = "1.0";
static char myarguments[] = "ahi:o:V";

/*}}}  */

/*{{{  void usage(void) */

void usage(void)
{
    fprintf(stderr,
        "Usage: %s -h -i arg -o arg -V . . .\n"
        "Options:\n"
	"\t-a              explode to parsed ATerm always, not AsFix\n"
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
  ATerm input = NULL;
  ATerm output = NULL;
  ATbool aterms = ATfalse;
  char   *input_file_name  = "-";
  char   *output_file_name = "-";
  
  while ((c = getopt(argc, argv, myarguments)) != EOF)
    switch (c) {
      case 'a':  aterms = ATtrue;         break;
      case 'h':  usage();                      exit(0);
      case 'i':  input_file_name  = optarg;    break;
      case 'o':  output_file_name = optarg;    break;
      case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
                                               exit(0);
      default :  usage();                      exit(1);
  }

  ATinit(argc, argv, &bottomOfStack);    /* Initialize Aterm library */
  PT_initMEPTApi();
  PTPT_initPTMEPTApi();

  ATsetChecking(ATtrue);
  input = ATreadFromNamedFile(input_file_name);

  if(input == NULL) {
    ATerror("%s: could not read term from input file %s\n", 
	    myname, input_file_name);
    return 1;
  }

  if (!aterms && ATmatch(input, "parsetree(<term>,<term>)",NULL,NULL)) {
    output = (ATerm) PTPT_explodeParseTree((PT_ParseTree) input);
  }
  else if (!aterms && ATmatch(input, "appl(<term>,<term>)", NULL, NULL)) {
    output = (ATerm) PTPT_explodeTree((PT_Tree) input);
  }
  else {
    output = (ATerm) PTPT_explodeATerm(input);
  }

  if(output != NULL) {
    ATwriteToNamedTextFile(output, output_file_name);
  }
  else {
    ATwarning("explode: something went wrong\n");
    return 1;
  }

  return 0;
}

/*}}}  */
