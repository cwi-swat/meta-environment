/*{{{  includes */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <aterm1.h>
#include "atb-tool.h"
/*}}}  */

static char myname[] = "tbunpack";
static char myversion[] = "1.0";
static char myarguments[] = "hi:o:V";

/*{{{  void usage(void) */

void usage(void)
{
  fprintf(stderr,
	  "Recursively unpacks all packed subterms in an ATerm\n"
	  "Usage: %s [%s]\n"
	  "Options:\n"
	  "\t-h              display help information (usage)\n"
	  "\t-i filename     input from file (default stdin)\n"
	  "\t-o filename     output to file (default stdout)\n"
	  "\t-V              reveal program version (i.e. %s)\n",
	  myname, myarguments, myversion);
}

/*}}}  */
/*{{{  void version(void) */

void version(void)
{
  fprintf(stderr, "%s v%s\n", myname, myversion);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int c;
  ATerm bottomOfStack;
  ATerm term;
  char   *inputName = "-";
  char   *outputName = "-";

  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'i':
	inputName = optarg;
	break;
      case 'o':
	outputName = optarg;
	break;
      case 'V':
	version();
	break;
      case 'h':
	usage();
	return 0;
      default:
	usage();
	return 1;
    }
  }

  ATBinit(argc, argv, &bottomOfStack);

  term = ATreadFromNamedFile(inputName);
  term = ATBunpack(term);
  ATwriteToNamedTextFile(term, outputName);

  return 0;
}

/*}}}  */
