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

#include <MEPT-utils.h>
#include <asfix2.h>
#include "conversion.h"

ATbool char_to_string = ATfalse;
 
static PT_Tree flattenTerm(PT_Tree t);
static PT_Tree flattenLayout(PT_Tree t);

static PT_Args flattenArgs(PT_Args tl)
{
  PT_Tree newTerm;

  if (PT_isArgsEmpty(tl)) {
    return tl;
  }

  newTerm = flattenTerm(PT_getArgsHead(tl));
  if (newTerm) {
    return PT_makeArgsList(newTerm, flattenArgs(PT_getArgsTail(tl)));
  }
  else {
    return flattenArgs(PT_getArgsTail(tl));
  }
}

static PT_Tree makeCharFromInt(PT_Tree i)
{
  if (char_to_string) {
    char strbuf[2];  
    
    strbuf[0] = (char)ATgetInt((ATermInt)i);
    strbuf[1] = '\0';
    return (PT_Tree)ATmake("<str>", strbuf);
  }
  else {
    return i;
  }
}

static PT_Args flattenLexicalList(PT_Tree t, PT_Args tail)
{
  PT_Production prod;
  PT_Args       args;
  PT_Tree       leftBranch, rightBranch;

  if (!PT_isTreeAppl(t)) {
    ATerror("flattenLexicalList: not an application: %t\n", t);
  } 
  
  prod = PT_getTreeProd(t);
  args = PT_getTreeArgs(t);

  if (!isLexicalListProd(prod)) {
    PT_Tree newTerm = flattenTerm(t);
    if (newTerm) {
      return PT_makeArgsList(newTerm, tail);
    }
    else {
      return tail;
    }
  }  

  if (PT_isArgsEmpty(args)) {
    return tail;
  }

  leftBranch = PT_getArgsHead(args);
  args = PT_getArgsTail(args);

  if (PT_isArgsEmpty(args)) {
    return flattenLexicalList(leftBranch, tail);
  }
  
  rightBranch = PT_getArgsHead(args);
  args = PT_getArgsTail(args);

  if (PT_isArgsEmpty(args)) {
    tail = flattenLexicalList(rightBranch, tail);
    tail = flattenLexicalList(leftBranch, tail);

    return tail;
  }
  
  ATerror("flattenLexicalList: illegal list: %t\n", t);
  return PT_makeArgsEmpty();
}

static PT_Args flattenCharClassList(PT_Tree tree, PT_Args tail)
{
  PT_Production prod;
  PT_Args       args;
  PT_Tree       leftBranch, rightBranch;

  if (PT_isTreeAppl(tree)) { 
    prod = PT_getTreeProd(tree);
    args = PT_getTreeArgs(tree);

    if (!isCharClassListProd(prod)) {
      PT_Tree newTerm = flattenTerm(tree);
      if (newTerm) {
        return PT_makeArgsList(newTerm, tail);
      }
      else {
        return tail;
      }
    }
  
    if (PT_isArgsEmpty(args)) {
      return tail;
    }
  
    leftBranch = PT_getArgsHead(args);
    args = PT_getArgsTail(args);

    if (PT_isArgsEmpty(args)) {
      return flattenCharClassList(leftBranch, tail);
    }
  
    rightBranch = PT_getArgsHead(args);
    args = PT_getArgsTail(args);

    if (PT_isArgsEmpty(args)) {
      tail = flattenCharClassList(rightBranch, tail);
      tail = flattenCharClassList(leftBranch, tail);

      return tail;
    }                 

    ATerror("flattenCharClassList: illegal list: %t\n", tree);
    return PT_makeArgsEmpty();
  }
  else /*if (ATgetType(t) == AT_INT)*/ {
    return PT_makeArgsList(makeCharFromInt(tree), tail);
  }
}

static PT_Args flattenList(PT_Tree tree, PT_Args tail)
{
  PT_Production prod;
  PT_Args       args;
  PT_Tree       leftBranch, layoutAfterLeft, rightBranch;

  if (!PT_isTreeAppl(tree)) {
    ATerror("flattenList: not an application: %t\n", tree);
  }

  prod = PT_getTreeProd(tree);
  args = PT_getTreeArgs(tree);

  if (!isListProd(prod)) {
    PT_Tree newTerm = flattenTerm(tree);
    if (newTerm) {
      return PT_makeArgsList(newTerm, tail);
    }
    else {
      return tail;
    }
  }
   
  if (PT_isArgsEmpty(args)) {  
    return tail;
  }

  leftBranch = PT_getArgsHead(args);
  args = PT_getArgsTail(args);

  if (PT_isArgsEmpty(args)) {
    return flattenList(leftBranch, tail);
  }                                    
  
  layoutAfterLeft = PT_getArgsHead(args);
  args = PT_getArgsTail(args);

  if (PT_hasArgsHead(args)) {
    rightBranch = PT_getArgsHead(args);
    args = PT_getArgsTail(args);

    if (PT_isArgsEmpty(args)) {
      tail = flattenList(rightBranch, tail);
      tail = PT_makeArgsList(flattenLayout(layoutAfterLeft), tail);
      tail = flattenList(leftBranch, tail);
  
      return tail;
    }
  }

  ATerror("flattenList: illegal list: %t\n", tree);
  return PT_makeArgsEmpty();
}

static PT_Args flattenSepList(PT_Tree tree, PT_Args tail)
{
  PT_Production prod;
  PT_Args       args;
  PT_Tree       leftBranch, layoutAfterLeft, 
                separator, layoutAfterSep, rightBranch;

  if (!PT_isTreeAppl(tree)) {
    ATerror("flattenSepList: not an application: %t\n", tree);
  }

  prod = PT_getTreeProd(tree);
  args = PT_getTreeArgs(tree);

  if (!isSepListProd(prod)) {
    PT_Tree newTerm = flattenTerm(tree);
    if (newTerm) {
      return PT_makeArgsList(newTerm, tail);
    }
    else {
      return tail;
    }
  }

  if (PT_isArgsEmpty(args)) {  
    return tail;
  }

  leftBranch = PT_getArgsHead(args);
  args = PT_getArgsTail(args);

  if (PT_isArgsEmpty(args)) {
    return flattenSepList(leftBranch, tail);
  }                                    

  layoutAfterLeft = PT_getArgsHead(args);
  args = PT_getArgsTail(args);

  if (PT_hasArgsHead(args)) {
    separator = PT_getArgsHead(args);
    args = PT_getArgsTail(args);

    if (PT_hasArgsHead(args)) {
      layoutAfterSep = PT_getArgsHead(args);
      args = PT_getArgsTail(args);

      if (PT_hasArgsHead(args)) {
        rightBranch = PT_getArgsHead(args);
        args = PT_getArgsTail(args);

        if (PT_isArgsEmpty(args)) {
          tail = flattenSepList(rightBranch, tail);
          tail = PT_makeArgsList(flattenLayout(layoutAfterSep), tail);
          tail = PT_makeArgsList(flattenTerm(separator), tail);
          tail = PT_makeArgsList(flattenLayout(layoutAfterLeft), tail);
          tail = flattenSepList(leftBranch, tail);

          return tail;
        }
      }
    }
  }

  ATerror("flattenSepList: illegal list: %t\n", tree);
  return PT_makeArgsEmpty();
}

static PT_Production flattenProd(PT_Production prod)
{
  if (!PT_isProductionDefault(prod)) {
    ATerror("flattenProd: not a production: %t\n", prod);
  }
  return prod;
}

static PT_Tree flattenLexical(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production outerProd = PT_getTreeProd(tree);
    PT_Args       args      = PT_getTreeArgs(tree);
    PT_Args       newArgs   = PT_makeArgsEmpty();

    while (PT_hasArgsHead(args)) {
      PT_Tree arg = PT_getArgsHead(args);
      PT_Tree newTerm = flattenTerm(arg);

      if (newTerm) {
        newArgs = PT_appendArgs(newArgs, newTerm);
      }
      args = PT_getArgsTail(args);
    }
    return PT_makeTreeAppl(flattenProd(outerProd), newArgs);
  }
  else { 
    return tree;
  }
}

static PT_Args flattenLayoutList(PT_Args args, PT_Args tail)
{
  while (PT_hasArgsHead(args)) {
    PT_Tree arg = PT_getArgsHead(args);

    if (PT_isTreeAppl(arg)) {
      PT_Production prod = PT_getTreeProd(arg);
      PT_Args       list = PT_getTreeArgs(arg);
  
      if (PT_prodHasLexLayoutAsRhs(prod)
          ||
          PT_prodHasCfLayoutAsRhs(prod)) {
        tail = flattenLayoutList(PT_reverseArgs(list), tail);
      }
/*
      else if (isCharClassListProd(prod)) {
        tail = flattenCharClassList(arg, tail);
      }
*/
      else {
        PT_Tree newArg = flattenTerm(arg);
        if (newArg) {
          tail = PT_makeArgsList(newArg, tail);
        }
      }
    }
    else /* if (PT_isTreeChar(arg)) */ {
      tail = PT_makeArgsList(makeCharFromInt(arg), tail);
    }
    args = PT_getArgsTail(args);
  }
  return tail;
}

static PT_Tree flattenLayout(PT_Tree tree)
{
  PT_Production prod = PT_getTreeProd(tree);

  if (PT_isOptLayoutProd(prod)) {
    PT_Args args       = PT_getTreeArgs(tree);
    PT_Args newArgs    = flattenLayoutList(args, PT_makeArgsEmpty());

    return PT_makeTreeAppl(prod, newArgs);
  }

  ATerror("flattenLayout: not layout: %t\n", tree);
  return (PT_Tree)NULL;
}

static PT_Tree flattenLiteral(PT_Production prod)
{
  PT_Symbol  rhs = PT_getProductionRhs(prod);
  char      *lit = PT_getSymbolString(rhs);

  return PT_makeTreeLit(lit);
}

static PT_Tree flattenVar(PT_Tree tree)
{
  PT_Production prodVarsymOuter = PT_getTreeProd(tree);
  PT_Args       argsOuter       = PT_getTreeArgs(tree);

  PT_Tree outerArg = PT_getArgsHead(argsOuter);

  if (PT_isTreeAppl(outerArg)) {
    PT_Production prodVarsymInner = PT_getTreeProd(outerArg);
    PT_Args       argsInner       = PT_getTreeArgs(outerArg);

    if (PT_prodHasVarSymAsRhs(prodVarsymInner)) {
      PT_Args newVarArg = PT_makeArgsEmpty();
      PT_Args newVarArgs = PT_makeArgsEmpty();

      while (PT_hasArgsHead(argsInner)) {
        PT_Tree arg = PT_getArgsHead(argsInner);
        PT_Tree newArg = flattenTerm(arg);
        if (newArg) {
          newVarArgs = PT_appendArgs(newVarArgs, newArg);
        }
        argsInner = PT_getArgsTail(argsInner);
      }
      newVarArg = PT_makeArgsList(PT_makeTreeAppl(flattenProd(prodVarsymInner),
                                                  newVarArgs),
                                  newVarArg);
      return PT_makeTreeAppl(flattenProd(prodVarsymOuter), newVarArg);
    }
  }
  return (PT_Tree)NULL;
}

static PT_Tree flattenTerm(PT_Tree tree)
{
  PT_Production prod;
  PT_Args args;

  if (PT_isTreeChar(tree)) {
    return makeCharFromInt(tree);
  }

  if (PT_isTreeAmb(tree)) {
    args = PT_getTreeArgs(tree);
    return PT_makeTreeAmb(flattenArgs(args));
  }

  if (!PT_isTreeAppl(tree)) {
    ATerror("flattenTerm: not an appl pattern: %t\n", tree);
    return (PT_Tree)NULL;
  }
  prod = PT_getTreeProd(tree);
  args = PT_getTreeArgs(tree);

  if (PT_prodHasLitAsRhs(prod)) {
    return flattenLiteral(prod);
  }

  if (PT_isOptLayoutProd(prod)) {
    return flattenLayout(tree);
  }

  if (PT_isLexicalProd(prod)) {
    return flattenLexical(tree);
  }

  if (PT_isVarDefault(prod)) {
    return flattenVar(tree);
  }

  /* Lists */
  if (isSepListProd(prod)) {
    return PT_makeTreeList(flattenSepList(tree, PT_makeArgsEmpty()));
  }

  if (isListProd(prod)) {
    return PT_makeTreeList(flattenList(tree, PT_makeArgsEmpty()));
  }

  if (isLexicalListProd(prod)) {
    return PT_makeTreeList(flattenLexicalList(tree, PT_makeArgsEmpty()));
  }

  if (isCharClassListProd(prod)) {
    return PT_makeTreeList(flattenCharClassList(tree, PT_makeArgsEmpty()));
  }

  /* Default: application */
  return PT_makeTreeAppl(flattenProd(prod), flattenArgs(args));
}

PT_ParseTree flattenPT(PT_ParseTree tree)
{
  if (PT_isParseTreeTree(tree)) {
    PT_Tree newTree = PT_getParseTreeTree(tree);

    return PT_setParseTreeTree(tree, flattenTerm(newTree));
  }

  ATerror("flattenParseTree: not a parsetree: %t\n", tree);
  return NULL;
}

PT_Tree flattenTree(PT_Tree tree)
{
  return flattenTerm(tree);
}
