
/*{{{  includes */

#include <stdlib.h>

#include "sort.h"

/*}}}  */

/*{{{  ATbool isStartSymbol(char *sort, SE_SymbolList symbols) */

ATbool isStartSymbol(char *sort, SE_SymbolList symbols)
{
  AFun fun = ATmakeAFun(sort, 0, ATtrue);
  ATerm sort_term = (ATerm)ATmakeAppl0(fun);
  return ATindexOf((ATermList)SE_makeTermFromSymbolList(symbols), sort_term, 0) != -1;
}

/*}}}  */
