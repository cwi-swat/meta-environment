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

#include <mept.h>
#include <asfix2.h>
#include "conversion.h"

ATbool char_to_string = ATfalse;
 
static ATerm flattenTerm(ATerm);
static ATerm flattenLayout(ATerm t);
static ATerm flattenLexical(ATerm t);
static ATerm flattenVar(ATerm t);
static ATerm flattenProd(ATerm prod);

static ATermList flattenArgs(ATermList tl)
{
  ATerm newTerm;

  if (ATisEmpty(tl)) {
    return ATempty;
  }

  newTerm = flattenTerm(ATgetFirst(tl));
  if (newTerm) {
    return ATinsert(flattenArgs(ATgetNext(tl)), newTerm);
  }
  else {
    return flattenArgs(ATgetNext(tl));
  }
}

static ATerm makeCharFromInt(ATermInt i)
{
  if (char_to_string) {
    char strbuf[2];  
    
    strbuf[0] = (char)ATgetInt(i);
    strbuf[1] = '\0';
    return ATmake("<str>", strbuf);
  }
  else {
    return (ATerm) i;
  }
}

static ATermList flattenLexicalList(ATerm t, ATermList tail)
{
  ATerm     prod;
  ATermList list;

  if (!PT_isTreeAppl(t)) {
    ATerror("flattenLexicalList: not an application: %t\n", t);
  } 
  
  prod = PT_getTreeProd(t);
  list = PT_getTreeArgs(t);

  if (!isLexicalListProd(prod)) {
    ATerm newTerm;
    newTerm = flattenTerm(t);
    if (newTerm) {
      return ATinsert(tail, newTerm);
    }
    else {
      return tail;
    }
  }  

  if (ATisEmpty(list)) {
    return tail;
  }

  if (ATgetLength(list) == 1) {
    return flattenLexicalList(ATgetFirst(list), tail);
  }
  
  if (ATgetLength(list) == 2) {
    ATerm leftBranch = ATelementAt(list,0);
    ATerm rightBranch = ATelementAt(list,1);

    tail = flattenLexicalList(rightBranch, tail);
    tail = flattenLexicalList(leftBranch, tail);

    return tail;
  }
  
  ATerror("flattenLexicalList: illegal list: %t\n", t);
  return NULL;
}

static ATermList flattenCharClassList(ATerm t, ATermList tail)
{
  ATerm     prod;
  ATermList list;

  if (ATgetType(t) == AT_INT) {
    return ATinsert(tail, makeCharFromInt((ATermInt) t));
  }

  if (!PT_isTreeAppl(t)) { 
    ATerror("flattenCharClassList: not an application: %t\n", t);
  }
  
  prod = PT_getTreeProd(t);
  list = PT_getTreeArgs(t);

  if (!isCharClassListProd(prod)) {
    ATerm newTerm;
    newTerm = flattenTerm(t);
    if (newTerm) {
      return ATinsert(tail, newTerm);
    }
    else {
      return tail;
    }
  }

  if (ATisEmpty(list)) {
    return tail;
  }

  if (ATgetLength(list) == 1) {
    return flattenCharClassList(ATgetFirst(list), tail);
  }

  if (ATgetLength(list) == 2) {
    ATerm leftBranch = ATelementAt(list,0);
    ATerm rightBranch = ATelementAt(list,1);

    tail = flattenCharClassList(rightBranch, tail);
    tail = flattenCharClassList(leftBranch, tail);

    return tail;
  }                 

  ATerror("flattenCharClassList: illegal list: %t\n", t);
  return NULL;
}

static ATermList flattenList(ATerm t, ATermList tail)
{
  ATerm     prod;
  ATermList list;

  if (!PT_isTreeAppl(t)) {
    ATerror("flattenList: not an application: %t\n", t);
  }

  prod = PT_getTreeProd(t);
  list = PT_getTreeArgs(t);

  if (!isListProd(prod)) {
    ATerm newTerm = flattenTerm(t);
    if (newTerm) {
      return ATinsert(tail, newTerm);
    }
    else {
      return tail;
    }
  }
   
  if (ATisEmpty(list)) {  
    return tail;
  }

  if (ATgetLength(list) == 1) {
    return flattenList(ATgetFirst(list), tail);
  }                                    
  
  if (ATgetLength(list) == 3) {
    ATerm leftBranch = ATgetFirst(list);
    ATerm layoutAfterLeft = ATelementAt(list,1);
    ATerm rightBranch = ATelementAt(list,2);
  
    tail = flattenList(rightBranch, tail);
    tail = ATinsert(tail, flattenLayout(layoutAfterLeft));
    tail = flattenList(leftBranch, tail);
  
    return tail;
  }

  ATerror("flattenList: illegal list: %t\n", t);
  return NULL;
}

static ATermList flattenSepList(ATerm t, ATermList tail)
{
  ATerm     prod;
  ATermList list;

  if (!PT_isTreeAppl(t)) {
    ATerror("flattenSepList: not an application: %t\n", t);
  }

  prod = PT_getTreeProd(t);
  list = PT_getTreeArgs(t);

  if (!isSepListProd(prod)) {
    ATerm newTerm = flattenTerm(t);
    if (newTerm) {
      return ATinsert(tail, newTerm);
    }
    else {
      return tail;
    }
  }

  if (ATisEmpty(list)) {
    return tail;
  }

  if (ATgetLength(list) == 1) {
    return flattenSepList(ATgetFirst(list), tail);
  }

  if (ATgetLength(list) == 5) {
    ATerm leftBranch      = ATgetFirst(list);
    ATerm layoutAfterLeft = ATelementAt(list,1);
    ATerm separator       = ATelementAt(list,2);
    ATerm layoutAfterSep  = ATelementAt(list,3); 
    ATerm rightBranch     = ATelementAt(list,4); 

    tail = flattenSepList(rightBranch, tail);
    tail = ATinsert(tail, flattenLayout(layoutAfterSep));
    tail = ATinsert(tail, flattenTerm(separator));
    tail = ATinsert(tail, flattenLayout(layoutAfterLeft));
    tail = flattenSepList(leftBranch, tail);
  
    return tail;
  }

  ATerror("flattenSepList: illegal list: %t\n", t);
  return NULL;
}

static ATerm flattenProd(ATerm prod)
{
  if(!PT_isProductionDefault(prod)) {
    ATerror("flattenProd: not a production: %t\n", prod);
  }
  return prod;
}

static ATerm flattenLexical(ATerm t)
{
  ATerm outerProd;
  ATermList args;
  ATermList newArgs = ATempty;

  if (PT_isTreeAppl(t)) {
    outerProd = PT_getTreeProd(t);
    args      = PT_getTreeArgs(t);

    while (!ATisEmpty(args)) {
      ATerm arg = ATgetFirst(args);
      ATerm newTerm = flattenTerm(arg);

      if (newTerm) {
        newArgs = ATappend(newArgs, newTerm);
      }
      args = ATgetNext(args);
    }
    return PT_makeTreeAppl(flattenProd(outerProd), newArgs);
  }
  else { 
    return t;
  }
}

static ATermList flattenLayoutList(ATermList args, ATermList tail)
{
  ATerm     arg, prod;
  ATermList list;

  while (!ATisEmpty(args)) {
    arg = ATgetFirst(args);

    if (ATgetType(arg) == AT_INT) {
      tail = ATinsert(tail, makeCharFromInt((ATermInt) arg));
    }
    else if (PT_isTreeAppl(arg)) {
      prod = PT_getTreeProd(arg);
      list = PT_getTreeArgs(arg);
  
      if (PT_prodHasLexLayoutAsRhs(prod)
          ||
          PT_prodHasCfLayoutAsRhs(prod)) {
        tail = flattenLayoutList(ATreverse(list), tail);
      }
      else {
        ATerm newArg = flattenTerm(arg);
        if (newArg) {
          tail = ATinsert(tail, newArg);
        }
      }
    }
    args = ATgetNext(args);
  }
  return tail;
}

static ATerm flattenLayout(ATerm t)
{
  ATermList args;

  if (PT_isTreeAppl(t)) {
    ATermList newArgs;

    args = PT_getTreeArgs(t);
    newArgs = flattenLayoutList(args, ATempty);

    return PT_makeLayout(newArgs);
  }
  ATerror("flattenLayout: not an application: %t\n", t);
  return NULL;
}

static ATerm flattenLiteral(ATerm prod)
{
  ATerm rhs = PT_getProductionRhs(prod);
  char *lit = PT_getLitString(rhs);

  return PT_makeSymbolLit(lit);
}

static ATerm flattenVar(ATerm t)
{
  ATerm prodVarsymOuter, prodVarsymInner;
  ATermList argsOuter, argsInner;
  ATerm outerArg;

  if (!PT_isTreeAppl(t)) {
    ATerror("flattenVar: not an application: %t\n", t);
  }

  prodVarsymOuter = PT_getTreeProd(t);
  argsOuter       = PT_getTreeArgs(t);

  if (!PT_prodHasVarSymAsLhs(prodVarsymOuter)) {
    ATerror("flattenVar: illegal var symbol: %t\n", t);
  }

  outerArg = ATgetFirst(argsOuter);

  if (PT_isTreeAppl(outerArg)) {
    prodVarsymInner = PT_getTreeProd(outerArg);
    argsInner       = PT_getTreeArgs(outerArg);

    if (PT_prodHasVarSymAsRhs(prodVarsymInner)) {
      ATermList newVarArg;
      ATermList newVarArgs = ATempty;

      while (!ATisEmpty(argsInner)) {
        ATerm arg = ATgetFirst(argsInner);
        ATerm newArg = flattenTerm(arg);
        if (newArg) {
          newVarArgs = ATappend(newVarArgs, newArg);
        }
        argsInner = ATgetNext(argsInner);
      }
      newVarArg = ATmakeList1(PT_makeTreeAppl(flattenProd(prodVarsymInner),
                                              newVarArgs));
      return PT_makeTreeAppl(flattenProd(prodVarsymOuter), newVarArg);
    }
  }
  return NULL;
}

static ATerm flattenTerm(ATerm t)
{
  ATerm prod;
  ATermList args;

  if (ATgetType(t) == AT_INT) {
    return makeCharFromInt((ATermInt) t);
  }

  if (PT_isTreeAmb(t)) {
    args = PT_getAmbArgs(t);
    return PT_makeTreeAmb(flattenArgs(args));
  }

  if (!PT_isTreeAppl(t)) {
    ATerror("flattenTerm: not an appl pattern: %t\n", t);
    return NULL;
  }
  prod = PT_getTreeProd(t);
  args = PT_getTreeArgs(t);

  if (PT_prodHasLitAsRhs(prod)) {
    return flattenLiteral(prod);
  }

  /* Layout */
  if (PT_prodHasCfOptLayoutAsRhs(prod)) {
    return flattenLayout(t);
  }

  /* Lexical */
  if (PT_prodHasLexSortAsRhs(prod)) {
    return flattenLexical(t);
  }

  /* Variable */
  if (PT_prodHasVarSymAsLhs(prod)) {
    return flattenVar(t);
  }

  /* Lists */
  if (isSepListProd(prod)) {
    ATermList newList = ATmakeList1((ATerm)flattenSepList(t, ATempty));
    return PT_makeTreeAppl(flattenProd(prod), newList);
  }

  if (isListProd(prod)) {
    ATermList newList = ATmakeList1((ATerm)flattenList(t, ATempty));
    return PT_makeTreeAppl(flattenProd(prod), newList);
  }

  if (isLexicalListProd(prod)) {
    return (ATerm)flattenLexicalList(t, ATempty);
  }

  if (isCharClassListProd(prod)) {
    return (ATerm)flattenCharClassList(t, ATempty);
  }

  /* Default: application */
  return PT_makeTreeAppl(flattenProd(prod), flattenArgs(args));
}

ATerm flattenPT(ATerm tree)
{
  if (PT_isParseTreeTree(tree)) {
    ATerm newTree = PT_getParseTreeTree(tree);
    ATerm ambCnt = PT_getParseTreeAmbCnt(tree);

    return PT_makeParseTreeTree(flattenTerm(newTree), ambCnt);
  }

  ATerror("flattenParseTree: not a parsetree: %t\n", tree);
  return NULL;
}
