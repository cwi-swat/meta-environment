/* $Id$ */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <aterm2.h>

#include <MEPT-utils.h>

static char myname[] = "unparsePT";
static char myversion[] = "1.0";

/*
 The argument vector: list of option letters, colons denote option
 arguments.  See Usage function, immediately below, for option
 explanation.
 */

static char myarguments[] = "hi:o:vV";

void usage(void)
{
  ATwarning("Usage: %s [%s]\n"
            "Options:\n"
            "\t-h              display help information (usage)\n"
            "\t-i filename     input from file (default stdin)\n"
            "\t-o filename     output to file (default stdout)\n"
            "\t-v              verbose mode\n"
            "\t-V              reveal program version (i.e. %s)\n",
            myname, myarguments, myversion);
}

void version(void)
{
  fprintf(stderr, "%s v%s\n", myname, myversion);
}


int main(int argc, char **argv)
{
  int c;
  ATerm bottomOfStack;

  /*  Configuration items  */
  char   *inputName = "-";
  char   *outputName = "-";
  FILE *outputFile = NULL; 
  ATbool verbose = ATfalse;
  ATbool proceed = ATtrue;

  extern char *optarg;
  extern int   optind;

  /*  Commandline mode  */

  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'i':  inputName = optarg;             break;
      case 'o':  outputName = optarg;            break;
      case 'v':  verbose = ATtrue;               break;
      case 'V':  version(); proceed = ATfalse;   break;

      case 'h':
      default:   usage(); proceed = ATfalse;     break;
    }
  }
  argc -= optind;
  argv += optind;

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();

  if (proceed) {
    ATerm term;

    if (!strcmp(outputName, "") || !strcmp(outputName, "-")) {
      outputFile = stdout;
    } 
    else if (!(outputFile = fopen(outputName, "wb"))) {
      ATerror("%s: cannot open %s for writing\n", argv[0], outputName);
    }

    term = ATreadFromNamedFile(inputName);
    if (term == NULL) {
      ATerror("asource: parse error in input term.\n");
    }
    else {
      char *text = PT_yieldProduction(PT_ProductionFromTerm(term));
      fprintf(outputFile, "%s", text);
      fclose(outputFile);
   }
  }

  return 0;
}
