#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aterm2.h"
#include <MEPT-utils.h>

static char version[] = "1.0";

/*{{{  static void usage(const char *prg) */

static void usage(const char *prg)
{
  fprintf(stderr, "Orders the alternatives of ambiguity clusters in a\n"
	  "canonical fashion. This can be used to compare trees that are\n"
	  "produced by different versions of a parser or a parse table.\n\n\n");
  fprintf(stderr, "Usage: %s -[hV] -i <input> -o <output>\n", prg);
  fprintf(stderr, "Parameters:\n");
  fprintf(stderr, "-i <file>  input tree [default stdin]\n");
  fprintf(stderr, "-o <file>  output tree [default stdout]\n");
  exit(2);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  int i;
  char *input = "-";
  char *output = "-";
  PT_ParseTree inputTree;
  PT_ParseTree outputTree;
  ATerm in = NULL;
  ATerm out = NULL;

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();

  if (argc < 3 || argc > 7) {
    usage(argv[0]);
  }

  for (i=1; i < argc; i++) {
    if (strcmp(argv[i], "-h") == 0) {
      usage(argv[0]);
    } 
    else if (strcmp(argv[i], "-V") == 0) {
      fprintf(stderr, "%s v%s\n", argv[0], version);
    }
    else if (strcmp(argv[i], "-i") == 0) {
      input = argv[++i];
    }
    else if (strcmp(argv[i], "-o") == 0) {
      output = argv[++i];
    }

  }

  in = ATreadFromNamedFile(input);

  if (in == NULL) {
    ATabort("could not read input file");
  }

  inputTree = PT_ParseTreeFromTerm(in);
  outputTree = PT_setParseTreeTree(inputTree,
				   PT_orderAmbiguities(
				     PT_getParseTreeTree(inputTree)));
  out = PT_ParseTreeToTerm(outputTree);

  ATwriteToNamedSharedTextFile(out, output);
  return 0;
}

/*}}}  */
