/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <unistd.h>
#include <aterm2.h>

#include "Error-utils.h"

/*}}}  */
/*{{{  globals */

static char myname[]    = "lower-error";
static char myversion[] = "1.0";
static char myarguments[] = "hi:o:tV";

/*}}}  */

/*{{{  void usage(void) */

void usage(void)
{
    fprintf(stderr,
	"This tool lowers parsed errors to abstract errors\n"
        "Usage: %s -h -i arg -o arg -Vt . . .\n"
        "Options:\n"
        "\t-h              display help information (usage)\n"
        "\t-i filename     input from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
	"\t-t              output textual instead of binary (default off)\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myname, myversion);
}

/*}}}  */

/*{{{  int main (int argc, char *argv[]) */

int main (int argc, char *argv[])
{
  int c; 
  ATerm bottomOfStack;
  ATerm input = NULL;
  ATerm output = NULL;
  ATbool textual = ATfalse;
  char *input_file_name = "-";
  char *output_file_name = "-";
  
  while ((c = getopt(argc, argv, myarguments)) != EOF)
    switch (c) {
      case 'h':  usage();                      exit(0);
      case 'i':  input_file_name  = optarg;    break;
      case 'o':  output_file_name = optarg;    break;
      case 't':  textual = ATtrue; break;
      case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
                                               exit(0);
      default :  usage();                      exit(1);
  }

  ATinit(argc, argv, &bottomOfStack);
  initErrorApi();

  input = ATreadFromNamedFile(input_file_name);

  if(input == NULL) {
    ATerror("%s: could not read term from input file %s\n", 
	    myname, input_file_name);
    return 1;
  }

  output = (ATerm) PERR_lowerError(PERR_ErrorFromTerm(input));

  if(output != NULL) {
    if (textual) {
      ATwriteToNamedTextFile(output, output_file_name);
    }
    else {
      ATwriteToNamedBinaryFile(output, output_file_name);
    }
  }
  else {
    ATwarning("%s: something went wrong\n", myname);
    return 1;
  }

  return 0;
}

/*}}}  */
