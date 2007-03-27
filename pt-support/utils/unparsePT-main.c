/*{{{  includes */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <aterm2.h>
#include <MEPT-utils.h>

#ifndef WITHOUT_TOOLBUS
#include "unparser.h"
#endif

/*}}}  */

/*{{{  variables */

static char myname[] = "unparsePT";
static char myversion[] = "1.4";
static char myarguments[] = "hi:o:vV";

/*}}}  */

/*{{{  void usage(void) */

void usage(void)
{
  fprintf(stderr,
	  "Yields the string that the input parse tree derives, \n"
	  "including each an every whitespace character.\n"
	  "This is *not* a pretty-printer, just an unparser.\n\n" 
	  "Usage: %s [%s]\n"
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
/*{{{  ATerm unparse_asfix(int cid, ATerm t) */

ATerm unparse_asfix(int cid, ATerm t)
{
  char *text = NULL;

  text = PT_yieldAnyToString(ATBunpack(t), ATfalse);

  return ATmake("snd-value(unparsed-text(<str>))", text);
}

/*}}}  */


/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int c;
  ATerm bottomOfStack;
  char *ATlibArgv[] = { "unparsePT", "-at-termtable", "21" };
  char *inputName = "-";
  char *outputName = "-";
  FILE *outputFile = NULL; 
  ATbool proceed = ATtrue;
  ATbool verbose = ATfalse;
  ATbool visualAmbs = ATfalse;

#ifndef WITHOUT_TOOLBUS
  ATbool use_toolbus = ATfalse;
  int i;

  for (i=1; !use_toolbus && i < argc; i++) {
    use_toolbus = !strcmp(argv[i], "-TB_TOOL_NAME");
  }

  if (use_toolbus) {
    int cid;
    ATBinit(argc, argv, &bottomOfStack);
    PT_initMEPTApi();
    cid = ATBconnect(NULL, NULL, -1, unparser_handler);
    ATBeventloop();
  }
  else
#endif
  {
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
	case 'a':
	  visualAmbs = ATtrue;
	  break;
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
	case 'h': /* fallthrough intended */
	default:
	  usage();
	  proceed = ATfalse;
	  break;
      }
    }

    ATinit(sizeof(ATlibArgv)/sizeof(char *), ATlibArgv, &bottomOfStack);
    PT_initMEPTApi();
  }


  if (proceed) {
    ATerm term;

    if (!strcmp(outputName, "") || !strcmp(outputName, "-")) {
      outputFile = stdout;
    } 
    else if (!(outputFile = fopen(outputName, "wb"))) {
      ATerror("%s: cannot open %s for writing\n", myname, outputName);
    }

    term = ATreadFromNamedFile(inputName);
    if (term == NULL) {
      ATerror("%s: cannot read term file: %s\n", myname, inputName);
    }
    else {
      PT_yieldAnyToFile(term, outputFile, visualAmbs);
      if (outputFile == stdout) {
	fflush(outputFile);
      }
      else {
	fclose(outputFile);
      }
    }
  }

  return 0;
}

/*}}}  */
