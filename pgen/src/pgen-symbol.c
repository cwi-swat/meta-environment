
#include <aterm2.h>

#include "pgen-symbol.h"

static ATermIndexedSet symbol_set = NULL;

/*{{{  void initSymbols() */

void initSymbols()
{
  symbol_set = ATindexedSetCreate(512, 75);
}

/*}}}  */
/*{{{  void destroySymbols() */

void destroySymbols()
{
  ATindexedSetDestroy(symbol_set);
  symbol_set = NULL;
}

/*}}}  */
/*{{{  int internSymbol(ATerm symbol) */

int internSymbol(ATerm symbol)
{
  return ATindexedSetPut(symbol_set, symbol, NULL);
}

/*}}}  */
/*{{{  ATerm getSymbol(int index) */

ATerm getSymbol(int index)
{
  return ATindexedSetGetElem(symbol_set, index);
}

/*}}}  */

