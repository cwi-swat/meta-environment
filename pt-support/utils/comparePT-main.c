#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aterm2.h"
#include <MEPT-utils.h>

static char version[] = "1.1";
static ATbool modLayout = ATtrue;

/*{{{  static void usage(const char *prg) */

static void usage(const char *prg)
{
  fprintf(stderr, "Compares to parse trees modulo layout.\n\n");
  fprintf(stderr, "Usage: %s -[hVl] <file1> <file2>\n", prg);
  fprintf(stderr, "Parameters:\n");
  fprintf(stderr, "\t-l\t: ignore layout-trees while comparing\t\t\t[%s]\n", modLayout ? "on" : "off");
  exit(2);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  ATerm t1 = NULL, t2 = NULL;
  int i;
  int result = 0;

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
    else if (strcmp(argv[i], "-l") == 0) {
      modLayout = !modLayout; 
    }
    else {
      if (t1 == NULL) {
	t1 = ATreadFromNamedFile(argv[i]);
	if (t1 == NULL) {
	  ATerror("Failed to read from %s\n", argv[i]);
	}
      }
      else if (t2 == NULL) {
	t2 = ATreadFromNamedFile(argv[i]);
	if (t2 == NULL) {
	  ATerror("Failed to read from %s\n", argv[i]);
	}
      }
      else {
	usage(argv[0]);
      }
    }
  }
  
  result = PT_compareTree(PT_getParseTreeTop(PT_ParseTreeFromTerm(t1)), 
			  PT_getParseTreeTop(PT_ParseTreeFromTerm(t2)),
                          modLayout);

  if (result < 0) {
    return -1;
  }
  if (result > 0) {
    return 1;
  }

  return 0;
}

/*}}}  */
