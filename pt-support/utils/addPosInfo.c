#include <stdio.h>
#include <assert.h>
#include "MEPT-utils.h"
#include <stdlib.h>
#include <string.h>

static char version[] = "1.2";

#define streq(str1, str2) (!strcmp(str1, str2))

static void usage(const char *myname, const char* myversion)
{
   fprintf (stderr,
        "Usage: %s [<options>]\n"
        "Options:\n"
        "  -i <input>     - Read input from file <input>            (Default: stdin)\n"
        "  -o <output>    - Write output to file <output>           (Default: stout)\n"
        "  -p <path>      - Path of file (obligatory)\n"
        "  -d <int>       - Maximum tree depth to traverse          (Default: unlimited)\n"
        "  -h             - Display help information (usage)\n"
        "  -V             - Print version information (i.e. %s)\n",
        myname, myversion);
}

static void requireArgument(int argc, char *argv[], int arg)
{
   if (arg > argc) {
     fprintf(stderr,
             "%s: %s option requires an argument.\n", argv[0], argv[arg]);
     exit(1);
   }
}

int main(int argc, char *argv[])
{
  ATerm     bottomOfStack;
  ATerm     contents;
  char   *input  = "-";
  FILE   *output = stdout;
  char   *path = NULL;
  int depth = -1;
  PT_ParseTree parseTree;
  int lcv;

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  
  if (argc == 1) {
    /* no arguments */
    usage(argv[0], version);
    exit(1);
  }

  /* Parse commandline arguments */
  for (lcv = 1; lcv < argc; lcv++) {
    if (streq(argv[lcv], "-i")) {
      requireArgument(argc, argv, lcv);
      input = strdup(argv[++lcv]);
      if (input == NULL) {
        ATerror("MRF");
      }
    }
    else if (streq(argv[lcv], "-o")) {
      requireArgument(argc, argv, lcv);
      output = fopen(argv[++lcv], "wb");
      if (output == NULL) {
        ATerror("%s: unable to open %s for writing.\n", argv[0], argv[lcv]);
      }
    }
    else if (streq(argv[lcv], "-p")) {
      requireArgument(argc, argv, lcv);
      path = strdup(argv[++lcv]);
      if(path == NULL) {
        ATerror("%s: not enough memory.\n", argv[0]);
        exit(1);
      }
    }
    else if (streq(argv[lcv], "-d")) {
      requireArgument(argc, argv, lcv);
      depth = atoi(argv[++lcv]);
    }
    else if (streq(argv[lcv], "-h")) {
      usage(argv[0],version);
      exit(0);
    }
    else if (streq(argv[lcv], "-V")) {
      fprintf(stderr, "%s v%s\n", argv[0], version);
      exit(0);
    }
  }

  contents = ATreadFromNamedFile(input);
  assert(contents != NULL);

  parseTree =  PT_makeParseTreeFromTerm(contents);

  if (depth == -1) { 
    parseTree = PT_addParseTreePosInfo(path, parseTree);
  } 
  else {
    parseTree = PT_addParseTreePosInfoToDepth(path, parseTree, depth);
  }

  ATwriteToTextFile(PT_makeTermFromParseTree(parseTree), output);

  return 0;
}
