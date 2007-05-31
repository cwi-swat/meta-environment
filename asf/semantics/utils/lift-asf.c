/* $Id$ */

#include <stdio.h>
#include <aterm1.h>
#include <aterm2.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <ASFME-utils.h>
#include <MEPT-utils.h>
#include <PTMEPT-utils.h>

static char myname[]    = "lift-asf";
static char myversion[] = "2.0";
static char myarguments[] = "hli:o:tV";

void usage(void)
{
    fprintf(stderr,
        "Tool that lifts the user-defined terms in a parsed ASF spec.\n"
	"This tool is used for debugging and bootstrapping the ASF compiler."
	"\n\n"
        "Usage: lift-asf -h -l -i <input> -o <output> -V"
        "Options:\n"
        "\t-h              display help information (usage)\n"
	"\t-l              lower instead of lift\n"
        "\t-i filename     input from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-V              reveal program version (i.e. %s)\n"
        "\n",
        myversion);
}

int main (int argc, char **argv)
{
  int c; /* option character */
  ATerm bottomOfStack;
  ATbool lower = ATfalse;
  ATbool text = ATfalse;
  char *input = "-";
  char *output = "-";
  ATerm in, out;

  if(argc == 1) { /* no arguments */
    usage();
    exit(1);
  }

  while ((c = getopt(argc, argv, myarguments)) != EOF) {
    switch (c) {
    case 'h':  
      usage();                      
      exit(0);
    case 'i':  
      input = strdup(optarg);    
      break;
    case 'l':
      lower = ATtrue;
      break;
    case 'o':  
      output = strdup(optarg);    
      break;
    case 't':
      text = ATtrue;
      break;
    case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
      exit(0);
    default:
      usage();
      exit(1);
    }
  }

  ATinit(argc, argv, &bottomOfStack); 
  PT_initMEPTApi();
  PTPT_initPTMEPTApi();
  ASF_initASFMEApi();

  /*ATsetChecking(ATtrue);*/

  in = ATreadFromNamedFile(input);

  if (ATgetType(in) == AT_APPL) {
    ASF_ASFModule module = ASF_ASFModuleFromTerm((ATerm) PT_getParseTreeTree((PT_ParseTree) in));

    if (lower) {
      module = ASF_lowerModule(module, NULL);
    }
    else {
      module = ASF_liftModule(module, NULL, NULL);
    }

    out = (ATerm) PT_setParseTreeTree((PT_ParseTree) in, (PT_Tree) module);
  }
  else if (ATgetType(in) == AT_LIST) {
    ASF_ASFConditionalEquationList list = ASF_ASFConditionalEquationListFromTerm(in);

    if (lower) {
      list = ASF_lowerEquations(list, NULL);
    }
    else {
      list = ASF_liftEquations(list, NULL, NULL);
    }

    out = ASF_ASFConditionalEquationListToTerm(list);
  }
  else {
    out = in;
    ATwarning("lift-asf: unexpected input\n");
  }

  if (!text) {
    ATwriteToNamedBinaryFile(out, output);
  }
  else {
    ATwriteToNamedSharedTextFile(out, output);
  }
  
  return 0;
}
