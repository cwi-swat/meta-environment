#ifndef SYMBOL_H
#define SYMBOL_H

#include <aterm1.h>

void initSymbols();
void destroySymbols();

int internSymbol(ATerm symbol);
ATerm getSymbol(int index);

#endif
