/*

    MEPT -- The Meta-Environment Parse Tree library        

    Copyright (C) 2001  Stichting Mathematisch Centrum, Amsterdam,
                        The Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

    $Id$
*/

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "MEPT-utils.h"

static int
lengthOfSymbol(PT_Symbol symbol)
{
  if (PT_isSymbolLit(symbol)) {
    char *str = PT_getSymbolString(symbol);
    return strlen(str) + 2;
  }
  if (PT_isSymbolSort(symbol)) {
    char *str = PT_getSymbolString(symbol);
    return strlen(str);
  }
  if (PT_isSymbolOpt(symbol)) {
    PT_Symbol newSymbol = PT_getSymbolSymbol(symbol);
    return lengthOfSymbol(newSymbol) + 1;
  }
  if (PT_isSymbolCf(symbol) 
      ||
      PT_isSymbolLex(symbol)) {
    PT_Symbol newSymbol = PT_getSymbolSymbol(symbol);
    return lengthOfSymbol(newSymbol);
  }
  if (PT_isSymbolAlt(symbol)) {
    PT_Symbol leftSymbol = PT_getSymbolLeft(symbol);
    PT_Symbol rightSymbol = PT_getSymbolRight(symbol);
    return lengthOfSymbol(leftSymbol) + 3 + lengthOfSymbol(rightSymbol);
  }
  if (PT_isSymbolIterPlus(symbol) 
      ||
      PT_isSymbolIterStar(symbol)) {
    PT_Symbol newSymbol = PT_getSymbolSymbol(symbol);
    return lengthOfSymbol(newSymbol) + 1;
  }
  if (PT_isSymbolIterPlusSep(symbol) 
      ||
      PT_isSymbolIterStarSep(symbol)) {
    PT_Symbol newSymbol = PT_getSymbolSymbol(symbol);
    PT_Symbol separator = PT_getSymbolSeparator(symbol);
    return lengthOfSymbol(newSymbol) + lengthOfSymbol(separator) + 4;
  }
ATwarning("lengthOfSymbol: unknown symbol: %t\n", symbol);
  return 0;
}

static int
lengthOfSymbols(PT_Symbols symbols)
{
  int length = 0;

  while (PT_hasSymbolsHead(symbols)) {
    length = length + lengthOfSymbol(PT_getSymbolsHead(symbols)) + 1;
    symbols = PT_getSymbolsTail(symbols);
  }

  return length;
}

static int
lengthOfAttributes(PT_Attributes attrs)
{
  return 0;
}


static int  
lengthOfProd(PT_Production prod)
{
  PT_Symbols lhs = PT_getProductionLhs(prod);
  PT_Symbol rhs = PT_getProductionRhs(prod);
  PT_Attributes attrs = PT_getProductionAttrs(prod);

  return lengthOfSymbols(lhs) + 4 +
         lengthOfSymbol(rhs) +
         lengthOfAttributes(attrs);
}

static int 
yieldSymbol(PT_Symbol symbol, int idx, char *buf, int bufSize)
{
  int i;

  assert(idx <= bufSize); 

  if (PT_isSymbolLit(symbol)) {
    char *str = PT_getSymbolString(symbol);
    int len = strlen(str);

    buf[idx++] = '"';
    for (i = 0; i < len; i++) {
      buf[idx++] = str[i];
    }
    buf[idx++] = '"';

    return idx;
  }
  if (PT_isSymbolSort(symbol)) {
    char *str = PT_getSymbolString(symbol);
    int len = strlen(str);

    for (i = 0; i < len; i++) {
      buf[idx++] = str[i];
    }

    return idx; 
  }
  if (PT_isSymbolOpt(symbol)) {
    PT_Symbol newSymbol = PT_getSymbolSymbol(symbol);
    idx = yieldSymbol(newSymbol, idx, buf, bufSize);
    buf[idx++] = '?';
    return idx;
  }
  if (PT_isSymbolCf(symbol) 
      ||
      PT_isSymbolLex(symbol)) {
    PT_Symbol newSymbol = PT_getSymbolSymbol(symbol);
    idx = yieldSymbol(newSymbol, idx, buf, bufSize);

    return idx;
  }
  if (PT_isSymbolAlt(symbol)) {
    PT_Symbol leftSymbol = PT_getSymbolLeft(symbol);
    PT_Symbol rightSymbol = PT_getSymbolRight(symbol);

    idx = yieldSymbol(leftSymbol, idx, buf, bufSize);
    buf[idx++] = ' ';
    buf[idx++] = '|';
    buf[idx++] = ' ';
    idx = yieldSymbol(rightSymbol, idx, buf, bufSize);

    return idx;
  }
  if (PT_isSymbolIterPlus(symbol)) {
    PT_Symbol newSymbol = PT_getSymbolSymbol(symbol);
    idx = yieldSymbol(newSymbol, idx, buf, bufSize);
    buf[idx++] = '+';

    return idx;
  }
  if (PT_isSymbolIterStar(symbol)) {
    PT_Symbol newSymbol = PT_getSymbolSymbol(symbol);
    idx = yieldSymbol(newSymbol, idx, buf, bufSize);
    buf[idx++] = '*';

    return idx;
  }
  if (PT_isSymbolIterPlusSep(symbol)) {
    PT_Symbol newSymbol = PT_getSymbolSymbol(symbol);
    PT_Symbol separator = PT_getSymbolSeparator(symbol);
    buf[idx++] = '{';
    idx = yieldSymbol(newSymbol, idx, buf, bufSize);
    buf[idx++] = ' ';
    idx = yieldSymbol(separator, idx, buf, bufSize);
    buf[idx++] = '}';
    buf[idx++] = '+';

    return idx;
  }
  if (PT_isSymbolIterStarSep(symbol)) {
    PT_Symbol newSymbol = PT_getSymbolSymbol(symbol);
    PT_Symbol separator = PT_getSymbolSeparator(symbol);
    buf[idx++] = '{';
    idx = yieldSymbol(newSymbol, idx, buf, bufSize);
    buf[idx++] = ' ';
    idx = yieldSymbol(separator, idx, buf, bufSize);
    buf[idx++] = '}';
    buf[idx++] = '*';

    return idx;
  }
ATwarning("lengthOfSymbol: unknown symbol: %t\n", symbol);
  return idx;
}

static int 
yieldSymbols(PT_Symbols symbols, int idx, char *buf, int bufSize)
{
  while (PT_hasSymbolsHead(symbols)) {
    idx = yieldSymbol(PT_getSymbolsHead(symbols), idx, buf, bufSize);
    buf[idx++] = ' ';
    symbols = PT_getSymbolsTail(symbols);
  }

  return idx;
}

static int 
yieldAttributes(PT_Attributes attrs, int idx, char *buf, int bufSize)
{
  return idx;
}

static int 
yieldProd(PT_Production prod, int idx, char *buf, int bufSize)
{
  PT_Symbols lhs = PT_getProductionLhs(prod);
  PT_Symbol rhs = PT_getProductionRhs(prod);
  PT_Attributes attrs = PT_getProductionAttrs(prod);

  idx = yieldSymbols(lhs, idx, buf, bufSize);
  buf[idx++] = '-';
  buf[idx++] = '>';
  buf[idx++] = ' ';
  idx = yieldSymbol(rhs, idx, buf, bufSize);
  idx = yieldAttributes(attrs, idx, buf, bufSize);

  return idx;
}

char *PT_yieldProduction(PT_Production prod)
{
  static char *buffer = NULL;
  static int   bufferSize = 0;
  int          idx = 0;
  int          len;

  len = lengthOfProd(prod)+1;

ATwarning("len = %d\n", len);
  if (len > bufferSize) {
    buffer = (char *)realloc(buffer, len*sizeof(char));
    bufferSize = len;
  }

  idx = yieldProd(prod, 0, buffer, len);

  buffer[idx++] = '\0';
/*  assert(idx == len);*/

  return buffer;
}
