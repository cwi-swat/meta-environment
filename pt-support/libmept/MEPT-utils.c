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

ATbool PT_prodHasLitAsRhs(PT_Production prod)
{
  /* This implements: "prod([<list>],lit(<str>),no-attrs)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);

    return PT_isSymbolLit(rhs);
  }

  ATerror("PT_prodHasLitAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_isLexicalProd(PT_Production prod)
{
  /* This implements: "prod([<list>],lex(sort(<term>)),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolLex(rhs)) {
      PT_Symbol symbol = PT_getSymbolSymbol(rhs);
      return PT_isSymbolSort(symbol);
    }
    return ATfalse;
  }

  ATerror("PT_prodHasLexSortAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_prodHasLexLayoutAsRhs(PT_Production  prod)
{
  /* This implements: "prod([<list>],lex(layout),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolLex(rhs)) {
      PT_Symbol symbol = PT_getSymbolSymbol(rhs);
      return PT_isSymbolLayout(symbol);
    }
    return ATfalse;
  }

  ATerror("PT_prodHasLexLayoutAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_prodHasCfLayoutAsRhs(PT_Production prod)
{
  /* This implements: "prod([<list>],cf(layout),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolCf(rhs)) {
      PT_Symbol symbol = PT_getSymbolSymbol(rhs);
      return PT_isSymbolLayout(symbol);
    }
    return ATfalse;
  }

  ATerror("PT_prodHasCfLayoutAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_isOptLayoutProd(PT_Production  prod)
{
  /* This implements: "prod([<list>],cf(opt(layout)),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    return PT_isOptLayoutSymbol(rhs);
  }

  ATerror("PT_isOptLayoutProd: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_prodHasVarSymAsRhs(PT_Production prod)
{
  /* This implements: "prod([<list>],varsym(<str>),no-attrs)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    return PT_isSymbolVarSym(rhs);
  }

  ATerror("PT_prodHasVarSymAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_isVarDefault(PT_Production prod)
{
  /* This implements: "prod([varsym(<term>)],cf(<term>),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbols lhs = PT_getProductionLhs(prod);
    PT_Symbol rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolCf(rhs) && PT_hasSymbolsHead(lhs)) {
      PT_Symbol lhssym = PT_getSymbolsHead(lhs);
      PT_Symbols tail = PT_getSymbolsTail(lhs);
      return PT_isSymbolsEmpty(tail) && PT_isSymbolVarSym(lhssym);
    }
    return ATfalse;
  }

  ATerror("PT_isVarDefault: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_prodHasLexAsLhsAndCfAsRhs(PT_Production prod)
{
  /* This implements: "prod([lex(<term>)],cf(<term>),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbols lhs = PT_getProductionLhs(prod);
    PT_Symbol rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolCf(rhs) && PT_hasSymbolsHead(lhs)) {
      PT_Symbol lhssym = PT_getSymbolsHead(lhs);
      PT_Symbols tail = PT_getSymbolsTail(lhs);
      return PT_isSymbolsEmpty(tail) && PT_isSymbolLex(lhssym);
    }
    return ATfalse;
  }

  ATerror("PT_prodHasVarSymAsLhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_prodHasIterSepAsRhs(PT_Production prod)
{
  /* This implements: 
   * "prod([<list>],cf(iter-star-sep(<term>,lit(<str>))),<term>)" and
   * "prod([<list>],cf(iter-sep(<term>,lit(<str>))),<term>)" 
   */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    if (PT_isSymbolCf(rhs)) {
      PT_Symbol listsym = PT_getSymbolSymbol(rhs);
      return PT_isSymbolIterPlusSep(listsym) || PT_isSymbolIterStarSep(listsym);
    }
  }

  ATabort("PT_prodHasIterSepAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_prodHasIterAsRhs(PT_Production prod)
{
  /* This implements: 
   * "prod([<list>],cf(iter-star(<term>,lit(<str>))),<term>)"
   * "prod([<list>],cf(iter(<term>,lit(<str>))),<term>)"
   */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    if (PT_isSymbolCf(rhs)) {
      PT_Symbol listsym = PT_getSymbolSymbol(rhs);
      return PT_isSymbolIterPlus(listsym) || PT_isSymbolIterStar(listsym);
    }
  }

  ATerror("PT_prodHasListSepAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_prodHasSTARTAsRhs(PT_Production prod)
{
  /* This implements: 
   * "prod([<list>],sort(\"<START>\"),no-attrs)"
   */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    if (PT_isSymbolSort(rhs)) {
      char *startsym = PT_getSymbolString(rhs);
      return strcmp(startsym,"<START>") == 0;
    }
  }

  ATerror("PT_prodHasSTARTAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_isOptLayoutSymbol(PT_Symbol symbol)
{
  /* This implements: "cf(opt(layout))" */
  if (PT_isSymbolCf(symbol)) {
    PT_Symbol cfsym = PT_getSymbolSymbol(symbol);
    if (PT_isSymbolOpt(cfsym)) {
      PT_Symbol optsym = PT_getSymbolSymbol(cfsym);
      return PT_isSymbolLayout(optsym);
    }
    return ATfalse;
  }
  return ATfalse;
}

PT_Args PT_concatArgs(PT_Args args1, PT_Args args2)
{
  return PT_makeArgsFromTerm((ATerm)ATconcat(
                                      (ATermList)PT_makeTermFromArgs(args1),
                                      (ATermList)PT_makeTermFromArgs(args2)));
}

PT_Args PT_appendArgs(PT_Args args, PT_Tree arg)
{
  return PT_makeArgsFromTerm((ATerm)ATappend(
                                      (ATermList)PT_makeTermFromArgs(args),
                                      (ATerm)PT_makeTermFromTree(arg)));
}

PT_Args PT_reverseArgs(PT_Args args)
{
  return PT_makeArgsFromTerm(
           (ATerm)ATreverse(
                    (ATermList)PT_makeTermFromArgs(args)));
}
