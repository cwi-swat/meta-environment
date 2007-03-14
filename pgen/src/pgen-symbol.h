#ifndef SYMBOL_H
#define SYMBOL_H

#include <aterm1.h>
#include <MEPT.h>

void initSymbols();
void destroySymbols();

int internSymbol(PT_Symbol symbol);
PT_Symbol getSymbol(int index);

#endif
