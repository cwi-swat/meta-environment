/*
 * $Id$
 */

#include <stdio.h>
#include <aterm1.h>
#include <aterm2.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <ASFME-utils.h>
#include <MEPT-utils.h>

static char myname[]    = "concat-asf";
static char myversion[] = "1.0";
static char myarguments[] = "ho:V";


/*
    Usage: displays helpful usage information
 */
void 
usage(void)
{
    fprintf(stderr,
	"\nConcat-asf concatenates parse trees of asf modules creating a\n"
	"single list of equations. This list can be given to the evaluator.\n\n"
        "Usage: concat-asf -h <file-1> ... <file-n> -o <output> -V"
        "Options:\n"
        "\t-h              display help information (usage)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-V              reveal program version (i.e. %s)\n"
        "\n"
	"For example:\n" 
	"concat-asf -o Module.eqs.baf Hoi.asf.asfix1 Hallo.asf.asfix1\n\n",
        myversion);
}

#define MAX_MODULES 2500

int 
main (int argc, char **argv)
{
  int c; /* option character */
  ATerm bottomOfStack;
  char *inputs[MAX_MODULES] = { "-" };
  int  nInputs = 0;
  char *output = "-";
  ATermList list;
  ASF_CondEquationList alleqs;
  int i;

  if(argc == 1) { /* no arguments */
    usage();
    exit(1);
  }

  while ((c = getopt(argc, argv, myarguments)) != EOF) {
    switch (c) {
    case 'h':  
      usage();                      
      exit(0);
    case 'o':  
      output = strdup(optarg);    
      break;
    case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
      exit(0);
    default:
      usage();
      exit(1);
    }
  }

  /* The optind variable indicates where getopt has stopped */
  for(i = optind; i < argc; i++) {
    if (nInputs < MAX_MODULES) {
      inputs[nInputs++] = strdup(argv[i]);  
    } else {
      ATerror("Maximum number of %s modules exceeded.\n", MAX_MODULES);
      exit(1);
    }
  }

  if (nInputs == 0) {
    nInputs = 1;
    inputs[0] = strdup("-");
  }

  ATinit(argc, argv, &bottomOfStack); 
  PT_initMEPTApi();
  ASF_initASFMEApi();

 
  list = ATempty;
  for (--nInputs; nInputs >= 0; nInputs--) {
    ATerm p = ATreadFromNamedFile(inputs[nInputs]); 

    if (p == NULL) {
      ATwarning("concat-asf: Unable to read anything from %s\n", 
		inputs[nInputs]);
    }
    else {
      list = ATinsert(list, p);
    }
    free(inputs[nInputs]);
  }

  alleqs = ASF_makeCondEquationListFromParseTrees(list);
 
  ATwriteToNamedBinaryFile(ASF_makeTermFromCondEquationList(alleqs), output);
 
  return 0;
}
