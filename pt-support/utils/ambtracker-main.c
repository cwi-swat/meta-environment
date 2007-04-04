/* $Id$ */

/*{{{  standard includes */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*}}}  */
/*{{{  meta includes */

#include <aterm2.h>
#include "MEPT-utils.h"
#include <Error-utils.h>
#include <ambiguity-reporter.h>

/*}}}  */
/*{{{  globals */

static char myname[]    = "ambtracker";
static char myversion[] = "2.0";
static char myarguments[] = "ahi:o:V";

/*}}}  */

/*{{{  void usage(void) */

void usage(void)
{
    fprintf(stderr,
        "Usage: %s -ah -i arg -o arg -V . . .\n"
        "Options:\n"
        "\t-a              output in ATerm format\n"
        "\t-h              display help information (usage)\n"
        "\t-i filename     input from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myname, myversion);
}

/*}}}  */

void rec_terminate(int cid, ATerm message) {
  exit(0);
}

/*{{{  ATerm report_ambiguities(int cid, ATerm parseTree, const char* path) */

ATerm report_ambiguities(int cid, ATerm parseTree, const char* path)
{
  ERR_Summary summary = (ERR_Summary) PT_reportParseTreeAmbiguities(path,
			      PT_ParseTreeFromTerm(ATBunpack(parseTree)));

  assert(summary != NULL);
  return ATmake("snd-value(ambiguity-report(<term>))", summary);
}

/*}}}  */

/*{{{  int main (int argc, char **argv) */

int main (int argc, char **argv)
{
  int c; 
  ATerm bottomOfStack;
  PT_ParseTree parsetree;
  ATerm ambiguities;
  ATbool atermformat = ATfalse;
  char   *input_file_name  = "-";
  char   *output_file_name = "-";
  ATbool use_toolbus = ATfalse;
  int i;

  for (i=1; !use_toolbus && i < argc; i++) {
    use_toolbus = !strcmp(argv[i], "-TB_TOOL_NAME");
  }

  if (use_toolbus) {
    int cid;
    ATBinit(argc, argv, &bottomOfStack);
    initErrorApi();
    PT_initMEPTApi();

    cid = ATBconnect(NULL, NULL, -1, ambiguity_reporter_handler);
    ATBeventloop();
  }
  else { 
    while ((c = getopt(argc, argv, myarguments)) != EOF)
      switch (c) {
	case 'a':  atermformat = ATtrue;         break;
	case 'h':  usage();                      exit(0);
	case 'i':  input_file_name  = optarg;    break;
	case 'o':  output_file_name = optarg;    break;
	case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
		   exit(0);
	default :  usage();                      exit(1);
      }

    ATinit(argc, argv, &bottomOfStack);
    initErrorApi();
    PT_initMEPTApi();

    parsetree = PT_ParseTreeFromTerm(ATreadFromNamedFile(input_file_name));

    if (parsetree == NULL) {
      ATerror("%s: could not read term from input file %s\n", 
	      myname, input_file_name);
    }

    ambiguities = PT_reportParseTreeAmbiguities(input_file_name, parsetree);

    if (ambiguities) {
      if (!atermformat) {
	FILE *fp = stdout;

	if (!strcmp(output_file_name, "") || !strcmp(output_file_name,"-")) {
	  fp = stdout;
	} else if (!(fp = fopen(output_file_name, "wb"))) {
	  ATerror("%s: could not open %s for output.\n", myname, output_file_name);
	  return 1;
	}

	ERR_fdisplaySummary(fp, (ERR_Summary) ambiguities);

	fclose(fp);
      } else {
	ATwriteToNamedTextFile(ambiguities, output_file_name);
      }
    }
  }

  return 0;
}

/*}}}  */
