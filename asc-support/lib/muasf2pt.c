/* $Id$ */

#include <stdio.h>

#include <MEPT-utils.h>
#include "asc-support-me.h"

static PT_Args termsToArgs(PT_Symbols args, ATermAppl appl);

/*{{{  PT_Tree termToTree(ATerm tree) */

PT_Tree termToTree(ATerm tree)
{
  PT_Tree result = NULL;
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
      ATerror("lists not supported yet\n");
      return NULL;
    }

    result = PT_makeTreeAppl(ptProd,actualargs);
  }
  else {
    ATabort("cannot handle term type: %d\n", ATgetType(tree));
  }

  return result;
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
  
  for(i=len-1; i>=0; i--) {
    PT_Symbol symbol = PT_getSymbolsSymbolAt(args,i);
    PT_Tree tree = NULL;

    if (PT_isSymbolLayout(symbol)) {
        result = PT_makeArgsList(PT_makeTreeLayoutFromString(" "), result);
    }
    else if(PT_isSymbolLit(symbol)) {
      char *str = PT_getSymbolString(symbol);
      tree = PT_makeTreeLit(str);
    } 
    else { 
      ATerm arg = ATgetArgument(appl, j--);
      tree = termToTree(arg);
    }

    result = PT_makeArgsList(tree ,result);
  }

  return result;
}

/*}}}  */

