/*
 * $Id$
 */

#include <stdio.h>
#include <aterm1.h>
#include <aterm2.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <MEPT-utils.h>

static char myname[]    = "apply-function";
static char myversion[] = "1.2";
static char myarguments[] = "f:s:m:hi:o:V";


/*
    Usage: displays helpful usage information
 */
void 
usage(void)
{
    fprintf(stderr,
	"\nApply-function encapsulates parsed terms with a quoted or unquoted prefix function.\n\n"
        "Usage: apply-function -h -f <name> -s <sort> -m <modulename>\n"
        "                      -i <file> -o <file> -V . . .\n"
        "Options:\n"
        "\t-h              display help information (usage)\n"
	"\t-f name         name of prefix function\n"
	"\t-s sort         result sort of function\n"
	"\t-m module       module where function is defined\n"
        "\t-i filename     input argument tree from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-V              reveal program version (i.e. %s)\n"
        "\n"
        "Supply a -i <file> option for each argument from left to right.\n",
        myversion);
}

#define MAX_ARGS 256

static PT_Tree
applyFunctionToArgs(char *function, char* module, char* sort, PT_Args args)
{
  PT_Tree   layoutTree   = PT_makeTreeLayoutEmpty();
  PT_Symbol layoutSymbol = PT_makeOptLayoutSymbol();
  PT_Tree   commaTree   = PT_makeTreeLit(",");
  PT_Symbol commaSymbol = PT_makeSymbolLit(",");
  PT_Tree   boTree   = PT_makeTreeLit("(");
  PT_Symbol boSymbol = PT_makeSymbolLit("(");
  PT_Tree   bcTree   = PT_makeTreeLit(")");
  PT_Symbol bcSymbol = PT_makeSymbolLit(")");
  PT_Tree   functionTree   = PT_makeTreeLit(function);
  PT_Symbol functionSymbol = PT_makeSymbolLit(function);
  PT_Symbol rhs = PT_makeSymbolCf(PT_makeSymbolSort(sort));
  PT_Production prod;
  PT_Attributes attributes = PT_makeAttributesNoAttrs();

  /* initialize with empty symbols and trees */
  PT_Args argList = PT_makeArgsEmpty();
  PT_Symbols symbolList = PT_makeSymbolsEmpty();

  /* make symbols and trees for args, inserting layout nodes */
  while(PT_hasArgsHead(args)) {
    PT_Tree arg = PT_getArgsHead(args);
    PT_Symbol symbol = PT_getProductionRhs(PT_getTreeProd(arg));

    /* add layout sep layout if needed */
    if (!PT_isArgsEmpty(argList)) {
      argList = PT_appendArgs(argList, layoutTree);
      symbolList = PT_appendSymbols(symbolList, layoutSymbol);
      argList = PT_appendArgs(argList, commaTree);
      symbolList = PT_appendSymbols(symbolList, commaSymbol);
      argList = PT_appendArgs(argList, layoutTree);
      symbolList = PT_appendSymbols(symbolList, layoutSymbol);
    }

    argList = PT_appendArgs(argList, arg);
    symbolList = PT_appendSymbols(symbolList, symbol);

    args = PT_getArgsTail(args);
  }

  /* append closing bracket to symbols and trees */
  argList = PT_appendArgs(argList, layoutTree);
  symbolList = PT_appendSymbols(symbolList, layoutSymbol);
  argList = PT_appendArgs(argList, bcTree);
  symbolList = PT_appendSymbols(symbolList, bcSymbol);

  /* insert opening bracket before symbols and trees */
  argList = PT_makeArgsList(layoutTree, argList);
  symbolList = PT_makeSymbolsList(layoutSymbol, symbolList);

  argList = PT_makeArgsList(boTree, argList);
  symbolList = PT_makeSymbolsList(boSymbol, symbolList);

  argList = PT_makeArgsList(layoutTree, argList);
  symbolList = PT_makeSymbolsList(layoutSymbol, symbolList); 

  /* insert function literal before symbols and trees */
  argList = PT_makeArgsList(functionTree, argList);
  symbolList = PT_makeSymbolsList(functionSymbol, symbolList);

  prod = PT_makeProductionDefault(symbolList, rhs, attributes);

  return PT_makeTreeAppl(prod, argList);


}

static PT_Symbols
makeNewLhs(char *sort, PT_Symbols lhs)
{
  PT_Symbol symbol;
  PT_Symbol sortSymbol = PT_makeSymbolCf(PT_makeSymbolSort(sort));
  PT_Symbols newLhs = PT_makeSymbolsEmpty();

  while (PT_hasSymbolsHead(lhs)) {
    symbol = PT_getSymbolsHead(lhs);
    if (PT_isOptLayoutSymbol(symbol)) {
      newLhs = PT_appendSymbols(newLhs, symbol);
    }
    else {
      newLhs = PT_appendSymbols(newLhs, sortSymbol);
    }
    lhs = PT_getSymbolsTail(lhs);
  }
  return newLhs;
}

int 
main (int argc, char **argv)
{
  int c; /* option character */
  ATerm bottomOfStack;
  PT_ParseTree parseTree = NULL, newParseTree = NULL;
  PT_Tree newTree;
  char *inputs[MAX_ARGS] = { "-" };
  int  nInputs = 0;
  char *output = "-";
  char *function = "";
  char *sort = "";
  char *module = "";
  PT_Args args;
  PT_Symbols lhs, newLhs;
 
  if(argc == 1) { /* no arguments */
    usage();
    exit(1);
  }

  while ((c = getopt(argc, argv, myarguments)) != EOF)
    switch (c) {
    case 'h':  
      usage();                      
      exit(0);
    case 'i':
      if (nInputs < MAX_ARGS) {
      inputs[nInputs++] = strdup(optarg);  
      } else {
        ATerror("Maximum number of %s arguments exceeded.\n", MAX_ARGS);
      }
      break;
    case 'o':  
      output = strdup(optarg);    
      break;
    case 'f':  function = optarg;            break;  
    case 's':  sort = optarg;                break;
    case 'm':  module = optarg;              break;
    case 'V':  fprintf(stdout, "%s %s\n", myname, myversion);
      exit(0);
    default :  usage();                      exit(1);
    }
 
  if (nInputs == 0) {
    nInputs = 1;
    inputs[0] = strdup("-");
  }

  /* check if all needed arguments were supplied */
  if(!function || !strcmp(function, "") || 
     !sort || !strcmp(sort,"") ||
     !module || !strcmp(module,"")) {
    usage();
    exit(1);
  }

  ATinit(argc, argv, &bottomOfStack); 
  PT_initMEPTApi();

  args = PT_makeArgsEmpty(); 
  for (--nInputs; nInputs >= 0; nInputs--) {
    parseTree = PT_makeParseTreeFromTerm(ATreadFromNamedFile(inputs[nInputs]));
    if (parseTree == NULL) {
      ATerror("Unable to read in %s\n", inputs[nInputs]);
      exit(1);
    }
    free(inputs[nInputs]);
    args = PT_makeArgsList(PT_getParseTreeTree(parseTree), args);
  }
 
  lhs = PT_getParseTreeLhs(parseTree);
  newLhs = makeNewLhs(sort, lhs);
  newTree = applyFunctionToArgs(function, module, sort, args);
  newParseTree = PT_setParseTreeTree(parseTree, newTree);
  newParseTree = PT_setParseTreeLhs(newParseTree, newLhs);

  ATwriteToNamedBinaryFile(PT_makeTermFromParseTree(newParseTree), output);
 
  return 0;
}
