/* $Id$ */

/*{{{  standard includes */

#include <stdio.h>
#include <assert.h>

/*}}}  */
/*{{{  meta includes */

#include <MEPT-utils.h>

/*}}}  */
/*{{{  local includes */

#include "asc-support-me.h"
#include "muasf2pt.h"

/*}}}  */

/*{{{  static PT_Tree listToTree(PT_Production prod, ATermList elems) */

static PT_Tree listToTree(PT_Production prod, ATermList elems)
{
  PT_Tree layout = PT_makeTreeLayoutFromString(" ");
  PT_Symbol sepSym = NULL;
  PT_Tree sepTree = NULL;
  PT_Symbol rhs;
  PT_Args args = PT_makeArgsEmpty();
  ATbool contextfree;

  rhs = PT_getProductionRhs(prod);

  if (PT_isSymbolCf(rhs)) {
    rhs = PT_getSymbolSymbol(rhs);
    contextfree = ATtrue;
  } else if (PT_isSymbolLex(rhs)) {
    rhs = PT_getSymbolSymbol(rhs);
    contextfree = ATfalse;
  } else {
    contextfree = ATfalse;
  }

  if (PT_hasSymbolSeparator(rhs)) {
    sepSym = PT_getSymbolSeparator(rhs);
    assert(PT_isSymbolLit(sepSym));
    sepTree = PT_makeTreeLit(PT_getSymbolString(sepSym));
  }

  for (;!ATisEmpty(elems); elems = ATgetNext(elems)) {
    if (contextfree && !PT_isArgsEmpty(args)) {
      args = PT_makeArgsList(layout,args);
    }
    args = PT_makeArgsList(termToTree(ATgetFirst(elems)), args); 
    if (sepTree != NULL && !ATisEmpty(ATgetNext(elems))) {
      args = PT_makeArgsList(sepTree, args);
    }
  } 

  return PT_makeTreeAppl(prod, (PT_Args) ATreverse((ATermList)args));
}

/*}}}  */
/*{{{  static PT_Args termsToArgs(PT_Symbols args, ATermAppl appl) */

static PT_Args termsToArgs(PT_Symbols args, ATermAppl appl)
{
  PT_Args result = PT_makeArgsEmpty();
  int arity = ATgetArity(ATgetSymbol(appl));
  int i;
  int j = arity-1; 
  int len = PT_getSymbolsLength(args);
  ATerm arg;

  for(i=len-1; i>=0; i--) {
    PT_Symbol symbol = PT_getSymbolsSymbolAt(args,i);
    PT_Tree tree = NULL;

    if (PT_isOptLayoutSymbol(symbol)) {
      tree = PT_makeTreeLayoutFromString(" ");
    }
    else if(PT_isSymbolLit(symbol)) {
      char *str = PT_getSymbolString(symbol);
      tree = PT_makeTreeLit(str);
      assert(tree != NULL);
    } 
    else { 
      assert(j >= 0 && j < arity);
      arg = ATgetArgument(appl, j--);
      tree = termToTree(arg);
      assert(tree != NULL);
    }

    result = PT_makeArgsList(tree ,result);
  }

  return result;
}

/*}}}  */
/*{{{  PT_Tree termToTree(ATerm tree) */

PT_Tree termToTree(ATerm tree)
{
  PT_Tree result = (PT_Tree) tree;
  ATerm prod = NULL;
  PT_Production ptProd = NULL;
  PT_Symbols formalargs = NULL;
  PT_Args actualargs = NULL;
  
  if(ATgetType(tree) == AT_APPL) {
    prod = lookup_prod(ATgetSymbol((ATermAppl)tree));
    if(!prod) {
      ATabort("unknown production symbol: %s\n",
              ATgetName(ATgetSymbol((ATermAppl) tree)));
    }

    ptProd = PT_makeProductionFromTerm(prod);
   
    if (PT_isProductionDefault(ptProd)) { 
      formalargs = PT_getProductionLhs(ptProd);
      actualargs = termsToArgs(formalargs, (ATermAppl)tree);
    }
    else { /* a list */
      return listToTree(ptProd,(ATermList) ATgetArgument((ATermAppl)tree,0));
    }

    result = PT_makeTreeAppl(ptProd,actualargs);
  }

  return result;
}

/*}}}  */

