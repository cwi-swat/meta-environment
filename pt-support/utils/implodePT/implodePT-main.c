/*  $Id$  */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <aterm2.h>

#include <MEPT-utils.h>

static char myname[] = "implodePT";
static char myversion[] = "1.1";

/*
 The argument vector: list of option letters, colons denote option
 arguments.  See Usage function, immediately below, for option
 explanation.
 */

static char myarguments[] = "aAbchi:lOo:pPtvILVqX";

/*
 Usage: displays helpful usage information
 */
void usage(void)
{
  fprintf(stderr,
	  "Usage: %s [%s]\n"
          "Options:\n"
	  "\t-a              keep annotations (default yes)\n"
	  "\t-A              interpret alternatives\n"
          "\t-b              output terms in BAF format (default)\n"
          "\t-c              interpret `cons' attributes\n"
          "\t-h              display help information (usage)\n"
          "\t-i filename     input from file (default stdin)\n"
          "\t-l              remove layout\n"
          "\t-o filename     output to file (default stdout)\n"
          "\t-O              interpret optionals\n"
          "\t-p              remove parsetree\n"
	  "\t-P              interpret layout-place-holder annotation\n"
          "\t-t              output terms in plaintext format\n"
          "\t-v              verbose mode\n"
          "\t-I              remove injections\n"
          "\t-L              remove literals\n"
          "\t-V              reveal program version (i.e. %s)\n"
          "\t-q              interpret sequences\n"
          "\t-X              implode lexicals\n"
	  "\n"
	  "Note that if none of the [AclopILqX] switches are given,\n"
          "they are all activated by default. If you give any of them,\n"
	  "the others are off by default until you switch them on.\n" ,
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
  extern ATbool interpret_alt;
  extern ATbool interpret_seq;
  extern ATbool interpret_opt;
  extern ATbool interpret_layout_place_holder;

  /*  Commandline mode  */

  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'a':  keep_annotations = ATfalse;             break;
      case 'A':  interpret_alt = ATtrue;                 break;
      case 'b':  bafmode = ATtrue;                       break;
      case 'c':  interpret_cons = ATtrue;                break;
      case 'i':  input=optarg;                           break;
      case 'l':  remove_layout = ATtrue;                 break;
      case 'o':  output=optarg;                          break;
      case 'O':  interpret_opt = ATtrue;                 break;
      case 'p':  remove_parsetree = ATtrue;              break;
      case 'P':  interpret_layout_place_holder = ATtrue; break;
      case 't':  bafmode = ATfalse;                      break;
      case 'v':  verbose = ATtrue;                       break;
      case 'I':  remove_injections = ATtrue;             break;
      case 'L':  remove_literals = ATtrue;               break;
      case 'V':  version(); proceed=ATfalse;             break;
      case 'q':  interpret_seq = ATtrue;                 break;
      case 'X':  implode_lexicals = ATtrue;              break;

      case 'h':
      default:   usage(); proceed=ATfalse;               break;
    }
  }

  ATinit(argc, argv, &bottomOfStack);     
  PT_initMEPTApi();

  if(!interpret_cons &&
     !remove_layout &&
     !remove_literals &&
     !remove_injections &&
     !remove_parsetree &&
     !implode_lexicals &&
     !interpret_alt &&
     !interpret_seq &&
     !interpret_opt 
     ) {
    interpret_cons = ATtrue;
    remove_layout = ATtrue;
    remove_literals = ATtrue;
    remove_injections = ATtrue;
    remove_parsetree = ATtrue;
    implode_lexicals = ATtrue;
    interpret_alt = ATtrue;
    interpret_seq = ATtrue;
    interpret_opt = ATtrue;
  }

  if (proceed) {
    ATerm inputTerm;
    PT_ParseTree tree;
    ATerm implodedTree;

    inputTerm = ATreadFromNamedFile(input);

    if (inputTerm != NULL) {
      tree = PT_makeParseTreeFromTerm(inputTerm);
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
