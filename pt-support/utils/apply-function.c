/*
 * $Id$
 */

#include <stdio.h>
#include <aterm1.h>
#include <aterm2.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <MEPT-utils.h>

static char myname[]    = "apply-function";
static char myversion[] = "1.2";
static char myarguments[] = "f:s:m:hi:o:V";

#define MAX_ARGS 32
/*
    Usage: displays helpful usage information
 */
void 
usage(void)
{
    fprintf(stderr,
	"\nApply-function encapsulates parsed terms with a quoted or unquoted prefix function.\n\n"
        "Usage: apply-function -h -f <name> -s <sort> -m <modulename>\n"
        "                      -i <file> -o <file> -V . . .\n"
        "Options:\n"
        "\t-h              display help information (usage)\n"
	"\t-f name         name of prefix function\n"
	"\t-s sort         result sort of function\n"
	"\t-m module       module where function is defined\n"
        "\t-i filename     input argument tree from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-V              reveal program version (i.e. %s)\n"
        "\n"
        "Supply a -i <file> option for each argument from left to right.\n",
        myversion);
}

int 
main (int argc, char **argv)
{
  int c; /* option character */
  ATerm bottomOfStack;
  PT_ParseTree parseTree = NULL, newParseTree = NULL;
  char *inputs[MAX_ARGS] = { "-" };
  int  nInputs = 0;
  char *output = "-";
  char *function = "";
  char *sort = "";
  PT_Args args;
 
  if(argc == 1) { /* no arguments */
    usage();
    exit(1);
  }

  while ((c = getopt(argc, argv, myarguments)) != EOF)
    switch (c) {
    case 'h':  
      usage();                      
      exit(0);
    case 'i':
      if (nInputs < MAX_ARGS) {
      inputs[nInputs++] = strdup(optarg);  
      } else {
        ATerror("Maximum number of %s arguments exceeded.\n", MAX_ARGS);
      }
      break;
    case 'o':  
      output = strdup(optarg);    
      break;
    case 'f':  function = optarg;            break;  
    case 's':  sort = optarg;                break;
    case 'V':  fprintf(stdout, "%s %s\n", myname, myversion);
      exit(0);
    default :  usage();                      exit(1);
    }
 
  if (nInputs == 0) {
    nInputs = 1;
    inputs[0] = strdup("-");
  }

  /* check if all needed arguments were supplied */
  if(!function || !strcmp(function, "") || 
     !sort || !strcmp(sort,"")) {
    usage();
    exit(1);
  }

  ATinit(argc, argv, &bottomOfStack); 
  PT_initMEPTApi();

  args = PT_makeArgsEmpty(); 

  if (!strcmp(inputs[0],"-")) {
    nInputs++;
  }

  for (--nInputs; nInputs >= 0; nInputs--) {
    parseTree = PT_makeParseTreeFromTerm(ATreadFromNamedFile(inputs[nInputs]));
    if (parseTree == NULL) {
      ATerror("Unable to read in %s\n", inputs[nInputs]);
      exit(1);
    }
    free(inputs[nInputs]);
    args = PT_makeArgsList(PT_getParseTreeTree(parseTree), args);
  }
 
  newParseTree = PT_applyFunctionToArgsParseTree(function, sort, args);

  ATwriteToNamedBinaryFile(PT_makeTermFromParseTree(newParseTree), output);
 
  return 0;
}
