
#include "PT-utils.h"

ATbool PT_isSymbolIter(PT_Symbol arg)
{
  return PT_isSymbolIterStarSep(arg) ||
         PT_isSymbolIterStar(arg)    ||
         PT_isSymbolIterPlusSep(arg) ||
         PT_isSymbolIterPlus(arg);
}

ATbool PT_isListVar(PT_Tree arg) 
{
  if (PT_isTreeVar(arg)) {
    PT_Symbol symbol = PT_getVarSymbol(PT_getTreeVar(arg));
   
    return PT_isSymbolIter(symbol); 
  }

  return ATfalse;
}

ATbool PT_isStarVar(PT_Tree arg) 
{
  if (PT_isTreeVar(arg)) {
    PT_Symbol symbol = PT_getVarSymbol(PT_getTreeVar(arg));
   
    return PT_isSymbolIterStar(symbol) || PT_isSymbolIterStarSep(symbol); 
  }

  return ATfalse;
}

ATbool PT_isPlusVar(PT_Tree arg) 
{
  if (PT_isTreeVar(arg)) {
    PT_Symbol symbol = PT_getVarSymbol(PT_getTreeVar(arg));
   
    return PT_isSymbolIterPlus(symbol) || PT_isSymbolIterPlusSep(symbol); 
  }

  return ATfalse;
}

PT_Args PT_concatArgs(PT_Args args1, PT_Args args2)
{
  return PT_makeArgsFromTerm((ATerm)ATconcat(
                                      (ATermList)PT_makeTermFromArgs(args1),
                                      (ATermList)PT_makeTermFromArgs(args2)));
}

