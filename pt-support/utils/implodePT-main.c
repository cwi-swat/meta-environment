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

static char myarguments[] = "abchi:lo:ptvILVX";

/*
 Usage: displays helpful usage information
 */
void usage(void)
{
  fprintf(stderr,
	  "Usage: %s [%s]\n"
          "Options:\n"
	  "\t-a              keep annotations (default yes)\n"
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
          "\t-V              reveal program version (i.e. %s)\n"
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
  extern ATbool keep_annotations;

  /*  Commandline mode  */

  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'a':  keep_annotations = ATfalse;             break;
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
      default:   usage(); proceed=ATfalse;               break;
    }
  }

  ATinit(argc, argv, &bottomOfStack);     
  PT_initMEPTApi();

  if (proceed) {
    ATerm inputTerm;
    PT_ParseTree tree;
    ATerm implodedTree;

    inputTerm = ATreadFromNamedFile(input);

    if (inputTerm != NULL) {
      tree = PT_makeParseTreeFromTerm(ATreadFromNamedFile(input));
      implodedTree = implodeParseTree(tree);

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
    else {
      fprintf(stderr,"%s: could not open file %s\n", myname, input);
    }
  }

  return 0;
}
