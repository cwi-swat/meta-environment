/*  $Id$  */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <aterm2.h>

#include <MEPT-utils.h>

static char myname[] = "implodePT";
static char myversion[] = "1.0";

/*
 The argument vector: list of option letters, colons denote option
 arguments.  See Usage function, immediately below, for option
 explanation.
 */

static char myarguments[] = "bchi:o:tvV";

/*
 Usage: displays helpful usage information
 */
void usage(void)
{
  ATwarning("Usage: %s [%s]\n"
            "Options:\n"
            "\t-b              output terms in BAF format (default)\n"
            "\t-c              interpret `cons' attributes\n"
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

  /*  Configuration items  */
  char   *input="-";
  char   *output="-";
  ATbool bafmode=ATtrue;
  ATbool verbose=ATfalse;
  ATbool proceed=ATtrue;
  ATbool interpret_cons=ATfalse;

  extern char *optarg;
  extern int   optind;

  /*  Commandline mode  */

  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'b':  bafmode = ATtrue;                       break;
      case 'c':  interpret_cons = ATtrue;                break;
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

  ATinit(argc, argv, &bottomOfStack);       /* Initialize Aterm library */
  PT_initMEPTApi();

  if(proceed) {
    PT_ParseTree tree = PT_makeParseTreeFromTerm(ATreadFromNamedFile(input));
    PT_ParseTree implodedTree = implodeParseTree(tree);

    if(!implodedTree) {
      ATerror("%s implosion conversion failed.", myname);
    }
    if(bafmode) {
      ATwriteToNamedBinaryFile(PT_makeTermFromParseTree(implodedTree), output);
    }
    else {
      ATwriteToNamedTextFile(PT_makeTermFromParseTree(implodedTree), output);
    }
  }

  return 0;
}
