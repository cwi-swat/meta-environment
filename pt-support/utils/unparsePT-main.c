/*{{{  includes */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <aterm2.h>
#include <atb-tool.h>
#include <MEPT-utils.h>

#include "unparsePT.tif.h"

/*}}}  */

/*{{{  variables */

static char myname[] = "unparsePT";
static char myversion[] = "1.0";

static char myarguments[] = "hi:o:vV";

/*}}}  */

/*{{{  void usage(void) */

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

/*}}}  */
/*{{{  void version(void) */

void version(void)
{
  fprintf(stderr, "%s v%s\n", myname, myversion);
}

/*}}}  */

/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */
/*{{{  void rec_terminate(int cid, ATerm t) */

ATerm unparse_asfix(int cid, ATerm t)
{
  char *text = PT_yieldParseTree(PT_makeParseTreeFromTerm(t));
  return ATmake("snd-value(unparsed-text(<str>))", text);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int c;
  ATerm bottomOfStack;

  /*  Configuration items  */
  char   *inputName = "-";
  char   *outputName = "-";
  FILE *outputFile = NULL; 
  ATbool use_toolbus = ATfalse;
  ATbool proceed = ATtrue;
  ATbool verbose = ATfalse;
  int i, cid;

  for (i=1; !use_toolbus && i < argc; i++) {
    use_toolbus = !strcmp(argv[i], "-TB_TOOL_NAME");
  }

  if (use_toolbus) {
    ATBinit(argc, argv, &bottomOfStack);
    PT_initMEPTApi();
    cid = ATBconnect(NULL, NULL, -1, unparsePT_handler);
    ATBeventloop();
  }
  else {
    extern char *optarg;
    extern int   optind;

    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
	case 'i':
	  inputName = optarg;
	  break;
	case 'o':
	  outputName = optarg;
	  break;
	case 'v':
	  verbose = ATtrue;
	  break;
	case 'V':
	  version();
	  proceed = ATfalse;
	  break;
	case 'h':
	default:
	  usage();
	  proceed = ATfalse;
	  break;
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
      else if (!(outputFile = fopen(outputName, "w"))) {
	ATerror("%s: cannot open %s for writing\n", argv[0], outputName);
      }

      term = ATreadFromNamedFile(inputName);
      if (term == NULL) {
	ATerror("%s: parse error in input term.\n", argv[0]);
      }
      else {
	char *text = PT_yieldParseTree(PT_makeParseTreeFromTerm(term));
	fprintf(outputFile, "%s", text);
	fclose(outputFile);
     }
    }
  }

  return 0;
}

/*}}}  */
