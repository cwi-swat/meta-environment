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
#include <ctype.h>
#include <assert.h>

#include "MEPT-utils.h"

static int lengthOfInteger(int ch)
{
  if (isalnum((char) ch)) {
    return 1;
  }
  else if (isprint((char) ch) ||
           ch == '\n' ||
           ch == '\t' ||
           ch == ' ') {
    return 2;
  }
 
  return 4;
}

static int lengthOfCharRange(PT_CharRange charRange)
{
  if (PT_isCharRangeCharacter(charRange)) {
    int ch = PT_getCharRangeInteger(charRange);
    return lengthOfInteger(ch);  
  }
  else if (PT_isCharRangeRange(charRange)) {
    int ch1 = PT_getCharRangeStart(charRange);
    int ch2 = PT_getCharRangeEnd(charRange);
    
    return lengthOfInteger(ch1) + lengthOfInteger(ch2) + 1;
  }
   
  ATwarning("lengthOfCharRange: unknown charRange: %t\n", charRange);
  return 0; 
}

static int lengthOfCharRanges(PT_CharRanges charRanges)
{
  int length = 0;

  while (PT_hasCharRangesHead(charRanges)) {
    PT_CharRange charRange = PT_getCharRangesHead(charRanges);
    length += lengthOfCharRange(charRange);
    charRanges = PT_getCharRangesTail(charRanges);
  }

  return length;
}

static int
lengthOfSymbol(PT_Symbol symbol)
{
  if (PT_isOptLayoutSymbol(symbol)) {
    return 0;
  }
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
  if (PT_isSymbolVarSym(symbol)) {
    PT_Symbol newSymbol = PT_getSymbolSymbol(symbol);
    return lengthOfSymbol(newSymbol);
  }
  if (PT_isSymbolCf(symbol) 
      ||
      PT_isSymbolLex(symbol)) {
    PT_Symbol newSymbol = PT_getSymbolSymbol(symbol);
    return lengthOfSymbol(newSymbol);
  }
  if (PT_isSymbolAlt(symbol)) {
    PT_Symbol leftSymbol = PT_getSymbolLhs(symbol);
    PT_Symbol rightSymbol = PT_getSymbolRhs(symbol);
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
  if (PT_isSymbolCharClass(symbol)) {
    return lengthOfCharRanges(PT_getSymbolRanges(symbol)) + 2;
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
  PT_Attributes attrs = PT_getProductionAttributes(prod);

  return lengthOfSymbols(lhs) + 4 +
         lengthOfSymbol(rhs) +
         lengthOfAttributes(attrs);
}

static int yieldInteger(int ch, int idx, char *buf, int bufSize)
{
  assert(idx <= bufSize);

  if (isalnum(ch)) {
    buf[idx++] = (char) ch;
    return idx;
  }
  else if (isprint(ch)) {
    buf[idx++] = '\\';
    buf[idx++] = (char) ch;
    return idx;
  } 
  else if (ch == '\n') {
    buf[idx++] = '\\';
    buf[idx++] = 'n';
    return idx;
  }
  else if (ch == '\t') {
    buf[idx++] = '\\';
    buf[idx++] = 't';
    return idx;
  }
  else if (ch == ' ') {
    buf[idx++] = '\\';
    buf[idx++] = ' ';
    return idx;
  }
  
  /* create escaped octal number */
  buf[idx++] = '\\';
  sprintf(buf+idx,"%0o",ch);
  idx += 3;

  return idx;
}

static int yieldCharRange(PT_CharRange charRange, int idx, char *buf, int bufSize)
{
  assert(idx <= bufSize);

  if (PT_isCharRangeCharacter(charRange)) {
    int ch = PT_getCharRangeInteger(charRange);
    idx = yieldInteger(ch, idx, buf, bufSize);
    return idx;
  }
  else if (PT_isCharRangeRange(charRange)) {
    int ch1 = PT_getCharRangeStart(charRange);
    int ch2 = PT_getCharRangeEnd(charRange);
    idx = yieldInteger(ch1, idx, buf, bufSize);
    buf[idx++] = (char) '-';
    idx = yieldInteger(ch2, idx, buf, bufSize);

    return idx;
  }

  ATwarning("yieldCharRange: unknown charRange: %t\n", charRange);
  return idx;
}

static int yieldCharRanges(PT_CharRanges charRanges, int idx, char *buf, int bufSize)
{
  assert(idx <= bufSize);

  while (PT_hasCharRangesHead(charRanges)) {
    PT_CharRange charRange = PT_getCharRangesHead(charRanges);
    idx = yieldCharRange(charRange, idx, buf, bufSize);
    charRanges = PT_getCharRangesTail(charRanges);
  }

  return idx;
}

static int 
yieldSymbol(PT_Symbol symbol, int idx, char *buf, int bufSize)
{
  int i;

  assert(idx <= bufSize); 

  if (PT_isOptLayoutSymbol(symbol)) {
    return idx;
  }
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
  if (PT_isSymbolVarSym(symbol)) {
    PT_Symbol newSymbol = PT_getSymbolSymbol(symbol);
    idx = yieldSymbol(newSymbol, idx, buf, bufSize);

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
    PT_Symbol leftSymbol = PT_getSymbolLhs(symbol);
    PT_Symbol rightSymbol = PT_getSymbolRhs(symbol);

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
  if (PT_isSymbolCharClass(symbol)) {
    PT_CharRanges charRanges = PT_getSymbolRanges(symbol);
    buf[idx++] = '[';
    idx = yieldCharRanges(charRanges,idx,buf,bufSize);
    buf[idx++] = ']';

    return idx;
  }

  ATwarning("yieldSymbol: unknown symbol: %t\n", symbol);
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
  PT_Attributes attrs = PT_getProductionAttributes(prod);

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

  if (len > bufferSize) {
    buffer = (char *)realloc(buffer, len*sizeof(char));
    bufferSize = len;
  }

  idx = yieldProd(prod, 0, buffer, len);

  buffer[idx++] = '\0';

  return buffer;
}

char *PT_yieldSymbol(PT_Symbol symbol)
{
  static char *buffer = NULL;
  static int   bufferSize = 0;
  int          idx = 0;
  int          len;

  len = lengthOfSymbol(symbol)+1;

  if (len > bufferSize) {
    buffer = (char *)realloc(buffer, len*sizeof(char));
    bufferSize = len;
  }

  idx = yieldSymbol(symbol, 0, buffer, len);

  assert(idx <= len); 
  buffer[idx++] = '\0';

  return buffer;
}                                
