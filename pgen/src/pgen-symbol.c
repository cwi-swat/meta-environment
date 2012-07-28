/* $Id$ */
#include <aterm2.h>

#include "pgen-symbol.h"

static ATermIndexedSet symbol_set = NULL;

void initSymbols() {
  symbol_set = ATindexedSetCreate(512, 75);
}

void destroySymbols() {
  ATindexedSetDestroy(symbol_set);
  symbol_set = NULL;
}

int internSymbol(PT_Symbol symbol) {
  return ATindexedSetPut(symbol_set, (ATerm)symbol, NULL);
}

PT_Symbol getSymbol(int index) {
  return (PT_Symbol)ATindexedSetGetElem(symbol_set, index);
}
