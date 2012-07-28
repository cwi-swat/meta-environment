/* $Id$ */

/*{{{  standard includes */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*}}}  */
/*{{{  meta includes */

#include <aterm2.h>
#include <MEPT-utils.h>
#include <PTMEPT-utils.h>

/*}}}  */
/*{{{  globals */

static char myname[]    = "parsePT";
static char myversion[] = "2.0";
static char myarguments[] = "ahi:lo:tV";

/*}}}  */

/*{{{  void usage(void) */

void usage(void)
{
    fprintf(stderr,
	"This tool can do several operations on AsFix and ATerms:\n"
	"\t* lift an ATerm to a parse tree of an ATerm\n"
	"\t* lower a parse tree of an ATerm to a ATerm\n"
	"\t* lift a parse tree to a parse tree of a parse tree\n"
	"\t* lower a parse tree of a parse tree to a parse tree\n\n"
	"The tool will always lift a parse tree to a parse tree unless the\n"
	"-a option is provided. Other ATerms are lifted to parsed ATerms.\n\n"
        "Usage: %s -h -i arg -o arg -V . . .\n"
        "Options:\n"
	"\t-a              lift to parsed ATerm always, not AsFix (default off)\n"
        "\t-h              display help information (usage)\n"
        "\t-i filename     input from file (default stdin)\n"
	"\t-l              lower instead of lift\n"
        "\t-o filename     output to file (default stdout)\n"
	"\t-t              output textual instead of binary (default off)\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myname, myversion);
}

/*}}}  */

/*{{{  int main (int argc, char **argv) */

int main (int argc, char **argv)
{
  int c; 
  ATerm bottomOfStack;
  ATerm input = NULL;
  ATerm output = NULL;
  ATbool aterms = ATfalse;
  ATbool textual = ATfalse;
  ATbool lower = ATfalse;
  char   *input_file_name  = "-";
  char   *output_file_name = "-";
  
  while ((c = getopt(argc, argv, myarguments)) != EOF)
    switch (c) {
      case 'a':  aterms = ATtrue;         break;
      case 'h':  usage();                      exit(0);
      case 'i':  input_file_name  = optarg;    break;
      case 'l':  lower = ATtrue; break;
      case 'o':  output_file_name = optarg;    break;
      case 't':  textual = ATtrue; break;
      case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
                                               exit(0);
      default :  usage();                      exit(1);
  }

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  PTPT_initPTMEPTApi();

  input = ATreadFromNamedFile(input_file_name);

  if(input == NULL) {
    ATerror("%s: could not read term from input file %s\n", 
	    myname, input_file_name);
    return 1;
  }

  if (!lower) {
    if (!aterms && ATmatch(input, "parsetree(<term>,<term>)",NULL,NULL)) {
      output = (ATerm) PTPT_liftParseTree((PT_ParseTree) input);
    }
    else if (!aterms && ATmatch(input, "appl(<term>,<term>)", NULL, NULL)) {
      output = (ATerm) PTPT_liftTree((PT_Tree) input);
    }
    else if (!aterms && ATmatch(input, "amb(<term>)", NULL)) {
      output = (ATerm) PTPT_liftTree((PT_Tree) input);
    }
    else {
      output = (ATerm) PTPT_liftATerm(input);
    }
  
    if(output != NULL) {
      output = (ATerm) PT_makeValidParseTreeFromTree((PT_Tree) output);
    }
  }
  else {
    PT_ParseTree pt = PT_ParseTreeFromTerm(input);
    PT_Tree tree = PT_getParseTreeTree(pt);
    
    if (PT_hasTreeProd(tree)) {
      PT_Symbol sym = PT_getProductionRhs(PT_getTreeProd(tree));

      if (PT_isEqualSymbol(sym, PT_makeSymbolCf(PT_makeSymbolSort("ATerm")))) {
	output = PTPT_lowerATerm((PTPT_ATerm) tree);
      }
      else if (PT_isEqualSymbol(sym,
				PT_makeSymbolCf(PT_makeSymbolSort("Tree")))) {
	output = (ATerm) PTPT_lowerTree((PTPT_Tree) tree);
      }
      else if (PT_isEqualSymbol(sym,
				PT_makeSymbolCf(PT_makeSymbolSort("ParseTree")))) {
	output = (ATerm) PTPT_lowerParseTree((PTPT_ParseTree) tree);
      }
      else {
	ATwarning("File is not in a format that can be lowered\n");
      }
    }
  }
    

  if(output != NULL) {
    if (textual) {
      ATwriteToNamedTextFile(output, output_file_name);
    }
    else {
      ATwriteToNamedBinaryFile(output, output_file_name);
    }
  }
  else {
    ATwarning("lift: something went wrong\n");
    return 1;
  }

  return 0;
}

/*}}}  */
