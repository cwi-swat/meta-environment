/* $Id$ */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <aterm2.h>

#include <MEPT-utils.h>

static char myname[] = "flattenPT";
static char myversion[] = "1.0";

/*
 The argument vector: list of option letters, colons denote option
 arguments.  See Usage function, immediately below, for option
 explanation.
 */

static char myarguments[] = "bhi:o:tvV";

/*
 Usage: displays helpful usage information
 */
void usage(void)
{
  ATwarning("Usage: %s [%s]\n"
            "Options:\n"
            "\t-b              output terms in BAF format (default)\n"
            "\t-h              display help information (usage)\n"
            "\t-i filename     input from file (default stdin)\n"
            "\t-o filename     output to file (default stdout)\n"
            "\t-t              output terms in plaintext format\n"
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
  PT_ParseTree tree, flatTree;

  /*  Configuration items  */
  char   *input="-";
  char   *output="-";
  ATbool bafmode=ATtrue;
  ATbool verbose=ATfalse;
  ATbool proceed=ATtrue;

  extern char *optarg;
  extern int   optind;

  /*  Commandline mode  */

  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'b':  bafmode = ATtrue;                       break;
      case 'i':  input=optarg;                           break;
      case 'o':  output=optarg;                          break;
      case 't':  bafmode = ATfalse;                      break;
      case 'v':  verbose = ATtrue;                       break;
      case 'V':  version(); proceed=ATfalse;             break;

      case 'h':
      default:   usage(); proceed=ATfalse;                     break;
    }
  }
  argc -= optind;
  argv += optind;

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  PT_initAsFix2Api();

  if(proceed) {
    tree = PT_ParseTreeFromTerm(ATreadFromNamedFile(input));
    flatTree = flattenPT(tree);

    if(!flatTree) {
      ATerror("%s: conversion failed.", myname);
    }
    if(bafmode) {
      ATwriteToNamedBinaryFile(PT_ParseTreeToTerm(flatTree), output);
    }
    else {
      ATwriteToNamedTextFile(PT_ParseTreeToTerm(flatTree), output);
    }
  }

  return 0;
}
