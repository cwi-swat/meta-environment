#include "_asc-support.h"

PT_Tree
ASC_applyFunctionToArgs(char *function, char* module, char* sort, PT_Args args)
{
  PT_Tree   layoutTree   = PT_makeTreeLayout("");
  PT_Symbol layoutSymbol = PT_makeSymbolEmptyLayout();
  PT_Tree   commaTree   = PT_makeTreeUnquotedLiteral(",");
  PT_Symbol commaSymbol = PT_makeSymbolQuotedLiteral(",");
  PT_Tree   boTree   = PT_makeTreeUnquotedLiteral("(");
  PT_Symbol boSymbol = PT_makeSymbolQuotedLiteral("(");
  PT_Tree   bcTree   = PT_makeTreeUnquotedLiteral(")");
  PT_Symbol bcSymbol = PT_makeSymbolQuotedLiteral(")");
  PT_Tree   functionTree   = PT_makeTreeUnquotedLiteral(function);
  PT_Symbol functionSymbol = PT_makeSymbolQuotedLiteral(function);
  PT_Symbol rhs = PT_makeSymbolSort(sort);
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

  prod = PT_makeProductionDefault(module, symbolList, rhs, attributes);

  return PT_makeTreeAppl(prod, argList);


}

PT_Tree
ASC_applyFunction(char *function, char* module, char* sort, int nArgs, ...)
{
  PT_Args ptArgs = PT_makeArgsEmpty();
  va_list args;

  va_start(args, nArgs);

  while(nArgs-- > 0) {
    PT_Tree arg = va_arg(args, PT_Tree);
    ptArgs = PT_appendArgs(ptArgs, arg);
  }

  va_end(args);

  return ASC_applyFunctionToArgs(function, module, sort, ptArgs);
}


