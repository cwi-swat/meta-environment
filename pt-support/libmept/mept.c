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

#include "mept.h"

static ATerm asfix_appl_pattern = NULL;
static ATerm asfix_prod_pattern = NULL;
static ATerm asfix_parsetree_pattern = NULL;
static ATerm asfix_lit_pattern = NULL;
static ATerm asfix_lex_pattern = NULL;
static ATerm asfix_cf_pattern = NULL;
static ATerm asfix_opt_pattern = NULL;
static ATerm asfix_sort_pattern = NULL;
static ATerm asfix_layout_pattern = NULL;

static void init_asfix_patterns()
{
  ATprotect(&asfix_appl_pattern);
  asfix_appl_pattern =
    ATparse("appl(<term>,[<list>])");

  ATprotect(&asfix_prod_pattern);
  asfix_prod_pattern =
    ATparse("prod(<term>,<term>,<term>)");

  ATprotect(&asfix_parsetree_pattern);
  asfix_parsetree_pattern =
    ATparse("parsetree(<term>,<term>)");

  ATprotect(&asfix_lit_pattern);
  asfix_lit_pattern =
    ATparse("lit(<str>)");

  ATprotect(&asfix_lex_pattern);
  asfix_lex_pattern =
    ATparse("lex(<term>)");

  ATprotect(&asfix_cf_pattern);
  asfix_cf_pattern =
    ATparse("cf(<term>)");

  ATprotect(&asfix_opt_pattern);
  asfix_opt_pattern =
    ATparse("opt(<term>)");

  ATprotect(&asfix_sort_pattern);
  asfix_sort_pattern =
    ATparse("sort(<term>)");

  ATprotect(&asfix_layout_pattern);
  asfix_layout_pattern =
    ATparse("layout");

}

static void init_patterns(void)
{
  static ATbool patterns_initialized = ATfalse;

  if (patterns_initialized) {
    return;
  }
  patterns_initialized = ATtrue;

  init_asfix_patterns();
}

ATerm PT_makeParseTreeTree(ATerm tree, ATerm cnt)
{
  return ATmakeTerm(asfix_parsetree_pattern, tree, cnt);
}

ATerm PT_makeTreeAppl(ATerm prod, ATermList args)
{
  return ATmakeTerm(asfix_appl_pattern, prod, args);
}

ATerm PT_makeSymbolLit(char *str)
{
  return ATmakeTerm(asfix_lit_pattern, str);
}

ATerm PT_makeSymbolLex(ATerm symbol)
{
  return ATmakeTerm(asfix_lex_pattern, symbol);
}

ATerm PT_makeSymbolCf(ATerm symbol)
{
  return ATmakeTerm(asfix_cf_pattern, symbol);
}

ATerm PT_makeSymbolOpt(ATerm symbol)
{
  return ATmakeTerm(asfix_opt_pattern, symbol);
}

ATerm PT_makeSymbolSort(ATerm symbol)
{
  return ATmakeTerm(asfix_sort_pattern, symbol);
}

ATerm PT_makeSymbolLayout()
{
  return ATmakeTerm(asfix_layout_pattern);
}

ATbool PT_isParseTreeTree(ATerm tree)
{
  return ATmatchTerm(tree, asfix_parsetree_pattern, NULL, NULL);
}

ATbool PT_isTreeAppl(ATerm tree)
{
  return ATmatchTerm(tree, asfix_appl_pattern, NULL, NULL);
}

ATbool PT_isProductionDefault(ATerm tree)
{
  return ATmatchTerm(tree, asfix_prod_pattern, NULL, NULL, NULL);
}

ATbool PT_isSymbolLit(ATerm tree)
{
  return ATmatchTerm(tree, asfix_lit_pattern, NULL);
}

ATbool PT_isSymbolLex(ATerm tree)
{
  return ATmatchTerm(tree, asfix_lex_pattern, NULL);
}

ATbool PT_isSymbolCf(ATerm tree)
{
  return ATmatchTerm(tree, asfix_cf_pattern, NULL);
}

ATbool PT_isSymbolOpt(ATerm tree)
{
  return ATmatchTerm(tree, asfix_opt_pattern, NULL);
}

ATbool PT_isSymbolSort(ATerm tree)
{
  return ATmatchTerm(tree, asfix_sort_pattern, NULL);
}

ATbool PT_isSymbolLayout(ATerm tree)
{
  return ATmatchTerm(tree, asfix_layout_pattern);
}


ATerm PT_getParseTreeTree(ATerm tree)
{
  ATerm newTree;

  if (PT_isParseTreeTree(tree)) {
    ATmatchTerm(tree, asfix_parsetree_pattern, &newTree, NULL);
    return newTree;
  }

  ATerror("PT_getParseTreeTree: not a parsetree: %t\n", tree);
  return NULL;
}

ATerm PT_getParseTreeAmbCnt(ATerm tree)
{
  ATerm ambCnt;

  if (PT_isParseTreeTree(tree)) {
    ATmatchTerm(tree, asfix_parsetree_pattern, NULL, &ambCnt);
    return ambCnt;
  }

  ATerror("PT_getParseTreeAmbCnt: not a parsetree: %t\n", tree);
  return NULL;
}

ATerm PT_getTreeProd(ATerm tree)
{
  ATerm prod;

  if (PT_isTreeAppl(tree)) {
    ATmatchTerm(tree, asfix_appl_pattern, &prod, NULL);
    return prod;
  }

  ATerror("PT_getTreeProd: not an appl: %t\n", tree);
  return NULL;
}

ATermList PT_getTreeArgs(ATerm tree)
{
  ATermList args;

  if (PT_isTreeAppl(tree)) {
    ATmatchTerm(tree, asfix_appl_pattern, NULL, &args);
    return args;
  }

  ATerror("PT_getTreeArgs: not an appl: %t\n", tree);
  return NULL;
}

ATerm PT_getProductionRhs(ATerm tree)
{
  ATerm rhs;

  if (PT_isProductionDefault(tree)) {
    ATmatchTerm(tree, asfix_prod_pattern, NULL, &rhs, NULL);
    return rhs;
  }

  ATerror("PT_getProductionRhs: not a production: %t\n", tree);
  return NULL;
}

char *PT_getLitString(ATerm tree)
{
  char *str;

  if (PT_isSymbolLit(tree)) {
    ATmatchTerm(tree, asfix_lit_pattern, &str);
    return str;
  }

  ATerror("PT_getLitString: not a literal: %t\n", tree);
  return NULL;
}

ATerm PT_getLexSymbol(ATerm tree)
{                                   
  ATerm symbol;

  if (PT_isSymbolLex(tree)) {
    ATmatchTerm(tree, asfix_lex_pattern, &symbol);
    return symbol;
  }

  ATerror("PT_getLexSymbol: not a lexical symbol: %t\n", tree);
  return NULL;
}  

ATerm PT_getCfSymbol(ATerm tree)
{
  ATerm symbol;

  if (PT_isSymbolCf(tree)) {
    ATmatchTerm(tree, asfix_cf_pattern, &symbol);
    return symbol;
  }

  ATerror("PT_getCfSymbol: not a context-free symbol: %t\n", tree);
  return NULL;
}
 
ATerm PT_getOptSymbol(ATerm tree)
{
  ATerm symbol;

  if (PT_isSymbolOpt(tree)) {
    ATmatchTerm(tree, asfix_opt_pattern, &symbol);
    return symbol;
  }

  ATerror("PT_getOptSymbol: not a optional symbol: %t\n", tree);
  return NULL;
}
        
ATerm PT_getSortSymbol(ATerm tree)
{                                   
  ATerm symbol;

  if (PT_isSymbolSort(tree)) {
    ATmatchTerm(tree, asfix_sort_pattern, &symbol);
    return symbol;
  }

  ATerror("PT_getSortSymbol: not a sort: %t\n", tree);
  return NULL;
}  

ATbool PT_prodHasLitAsRhs(ATerm prod)
{
  /* This implements: "prod([<list>],lit(<str>),no-attrs)" */
  if (PT_isProductionDefault(prod)) {
    ATerm rhs = PT_getProductionRhs(prod);
    return PT_isSymbolLit(rhs);
  }

  ATerror("PT_prodHasLitAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_prodHasLexSortAsRhs(ATerm prod)
{
  /* This implements: "prod([<list>],lex(sort(<term>)),<term>)" */
  if (PT_isProductionDefault(prod)) {
    ATerm rhs = PT_getProductionRhs(prod);
    if (PT_isSymbolLex(rhs)) {
      ATerm symbol = PT_getLexSymbol(rhs);
      return PT_isSymbolSort(symbol);
    }
    return ATfalse;
  }

  ATerror("PT_prodHasLexSortAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_prodHasLexLayoutAsRhs(ATerm  prod)
{
  /* This implements: "prod([<list>],lex(layout),<term>)" */
  if (PT_isProductionDefault(prod)) {
    ATerm rhs = PT_getProductionRhs(prod);
    if (PT_isSymbolLex(rhs)) {
      ATerm symbol = PT_getLexSymbol(rhs);
      return PT_isSymbolLayout(symbol);
    }
    return ATfalse;
  }

  ATerror("PT_prodHasLexLayoutAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_prodHasCfLayoutAsRhs(ATerm  prod)
{
  /* This implements: "prod([<list>],cf(layout),<term>)" */
  if (PT_isProductionDefault(prod)) {
    ATerm rhs = PT_getProductionRhs(prod);
    if (PT_isSymbolCf(rhs)) {
      ATerm symbol = PT_getCfSymbol(rhs);
      return PT_isSymbolLayout(symbol);
    }
    return ATfalse;
  }

  ATerror("PT_prodHasCfLayoutAsRhs: not a production: %t\n", prod);
  return ATfalse;
}



void PT_initMEPTApi()
{
  init_patterns();
}
