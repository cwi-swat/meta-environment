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

static char myarguments[] = "bchi:lo:ptvILVX";

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
            "\t-l              remove layout\n"
            "\t-o filename     output to file (default stdout)\n"
            "\t-p              remove parsetree\n"
            "\t-t              output terms in plaintext format\n"
            "\t-v              verbose mode\n"
            "\t-I              remove injections\n"
            "\t-L              remove literals\n"
            "\t-V              reveal program version (i.e. %s)\n",
            "\t-X              implode lexicals\n",
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
  extern ATbool interpret_cons;
  extern ATbool remove_layout;
  extern ATbool remove_literals;
  extern ATbool remove_injections;
  extern ATbool remove_parsetree;
  extern ATbool implode_lexicals;

  extern char *optarg;
  extern int   optind;

  /*  Commandline mode  */

  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'b':  bafmode = ATtrue;                       break;
      case 'c':  interpret_cons = ATtrue;                break;
      case 'i':  input=optarg;                           break;
      case 'l':  remove_layout = ATtrue;                 break;
      case 'o':  output=optarg;                          break;
      case 'p':  remove_parsetree = ATtrue;              break;
      case 't':  bafmode = ATfalse;                      break;
      case 'v':  verbose = ATtrue;                       break;
      case 'I':  remove_injections = ATtrue;             break;
      case 'L':  remove_literals = ATtrue;               break;
      case 'V':  version(); proceed=ATfalse;             break;
      case 'X':  implode_lexicals = ATtrue;              break;

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
    ATerm implodedTree = implodeParseTree(tree);

    if(!implodedTree) {
      ATerror("%s implosion conversion failed.", myname);
    }
    if(bafmode) {
      ATwriteToNamedBinaryFile(implodedTree, output);
    }
    else {
      ATwriteToNamedTextFile(implodedTree, output);
    }
  }

  return 0;
}
