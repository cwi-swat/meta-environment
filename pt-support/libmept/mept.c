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
static ATerm asfix_amb_pattern = NULL;
static ATerm asfix_prod_pattern = NULL;
static ATerm asfix_parsetree_pattern = NULL;
static ATerm asfix_lit_pattern = NULL;
static ATerm asfix_lex_pattern = NULL;
static ATerm asfix_cf_pattern = NULL;
static ATerm asfix_opt_pattern = NULL;
static ATerm asfix_iter_pattern = NULL;
static ATerm asfix_iterstar_pattern = NULL;
static ATerm asfix_itersep_pattern = NULL;
static ATerm asfix_iterstarsep_pattern = NULL;
static ATerm asfix_sort_pattern = NULL;
static ATerm asfix_varsym_pattern = NULL;
static ATerm asfix_layout_pattern = NULL;
static ATerm asfix_flatlayout_pattern = NULL;

static void init_asfix_patterns()
{
  ATprotect(&asfix_appl_pattern);
  asfix_appl_pattern =
    ATparse("appl(<term>,[<list>])");

  ATprotect(&asfix_amb_pattern);
  asfix_amb_pattern =
    ATparse("amb([<list>])");

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

  ATprotect(&asfix_iter_pattern);
  asfix_iter_pattern =
    ATparse("iter(<term>)");

  ATprotect(&asfix_iterstar_pattern);
  asfix_iterstar_pattern =
    ATparse("iter-star(<term>)");

  ATprotect(&asfix_itersep_pattern);
  asfix_itersep_pattern =
    ATparse("iter-sep(<term>,<term>)");

  ATprotect(&asfix_iterstarsep_pattern);
  asfix_iterstarsep_pattern =
    ATparse("iter-star-sep(<term>,<term>)");

  ATprotect(&asfix_sort_pattern);
  asfix_sort_pattern =
    ATparse("sort(<term>)");

  ATprotect(&asfix_varsym_pattern);
  asfix_varsym_pattern =
    ATparse("varsym(<term>)");

  ATprotect(&asfix_layout_pattern);
  asfix_layout_pattern =
    ATparse("layout");

  ATprotect(&asfix_flatlayout_pattern);
  asfix_flatlayout_pattern =
    ATparse("flatlayout([<list>])");

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

ATerm PT_makeTreeAmb(ATermList args)
{
  return ATmakeTerm(asfix_amb_pattern, args);
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

ATerm PT_makeSymbolVarSym(ATerm symbol)
{
  return ATmakeTerm(asfix_varsym_pattern, symbol);
}

ATerm PT_makeSymbolLayout()
{
  return ATmakeTerm(asfix_layout_pattern);
}

ATerm PT_makeLayout(ATermList args)
{
  return ATmakeTerm(asfix_flatlayout_pattern, args);
}

ATbool PT_isParseTreeTree(ATerm tree)
{
  return ATmatchTerm(tree, asfix_parsetree_pattern, NULL, NULL);
}

ATbool PT_isTreeAppl(ATerm tree)
{
  return ATmatchTerm(tree, asfix_appl_pattern, NULL, NULL);
}

ATbool PT_isTreeAmb(ATerm tree)
{
  return ATmatchTerm(tree, asfix_amb_pattern, NULL);
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

ATbool PT_isSymbolIterPlus(ATerm tree)
{
  return ATmatchTerm(tree, asfix_iter_pattern, NULL);
}

ATbool PT_isSymbolIterStar(ATerm tree)
{
  return ATmatchTerm(tree, asfix_iterstar_pattern, NULL);
}

ATbool PT_isSymbolIterPlusSep(ATerm tree)
{
  return ATmatchTerm(tree, asfix_itersep_pattern, NULL, NULL);
}

ATbool PT_isSymbolIterStarSep(ATerm tree)
{
  return ATmatchTerm(tree, asfix_iterstarsep_pattern, NULL, NULL);
}

ATbool PT_isSymbolSort(ATerm tree)
{
  return ATmatchTerm(tree, asfix_sort_pattern, NULL);
}

ATbool PT_isSymbolVarSym(ATerm tree)
{
  return ATmatchTerm(tree, asfix_varsym_pattern, NULL);
}

ATbool PT_isSymbolLayout(ATerm tree)
{
  return ATmatchTerm(tree, asfix_layout_pattern);
}

ATbool PT_isLayout(ATerm tree)
{
  return ATmatchTerm(tree, asfix_flatlayout_pattern, NULL);
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

ATermList PT_getAmbArgs(ATerm tree)
{
  ATermList args;

  if (PT_isTreeAmb(tree)) {
    ATmatchTerm(tree, asfix_amb_pattern, &args);
    return args;
  }

  ATerror("PT_getAmbArgs: not an ambiguity: %t\n", tree);
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

ATermList PT_getProductionLhs(ATerm tree)
{
  ATermList lhs;

  if (PT_isProductionDefault(tree)) {
    ATmatchTerm(tree, asfix_prod_pattern, &lhs, NULL, NULL);
    return lhs;
  }

  ATerror("PT_getProductionLhs: not a production: %t\n", tree);
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
        
ATerm PT_getIterPlusSymbol(ATerm tree)
{
  ATerm symbol;

  if (PT_isSymbolIterPlus(tree)) {
    ATmatchTerm(tree, asfix_iter_pattern, &symbol);
    return symbol;
  }

  ATerror("PT_getIterPlusSymbol: not an iter symbol: %t\n", tree);
  return NULL;
}
 
ATerm PT_getIterStarSymbol(ATerm tree)
{
  ATerm symbol;

  if (PT_isSymbolIterStar(tree)) {
    ATmatchTerm(tree, asfix_iterstar_pattern, &symbol);
    return symbol;
  }

  ATerror("PT_getIterStarSymbol: not an iter-star symbol: %t\n", tree);
  return NULL;
} 

ATerm PT_getIterPlusSepSymbol(ATerm tree)
{
  ATerm symbol;

  if (PT_isSymbolIterPlusSep(tree)) {
    ATmatchTerm(tree, asfix_itersep_pattern, &symbol, NULL);
    return symbol;
  }

  ATerror("PT_getIterPlusSepSymbol: not an iter-sep symbol: %t\n", tree);
  return NULL;
}

ATerm PT_getIterStarSepSymbol(ATerm tree)
{
  ATerm symbol;

  if (PT_isSymbolIterStarSep(tree)) {
    ATmatchTerm(tree, asfix_iterstarsep_pattern, &symbol, NULL);
    return symbol;
  }

  ATerror("PT_getIterStarSepSymbol: not an iter-star-sep symbol: %t\n", tree);
  return NULL;
}   

ATerm PT_getIterPlusSepSeparator(ATerm tree)
{
  ATerm symbol;

  if (PT_isSymbolIterPlusSep(tree)) {
    ATmatchTerm(tree, asfix_itersep_pattern, NULL, &symbol);
    return symbol;
  }

  ATerror("PT_getIterPlusSepSeparator: not an iter-sep symbol: %t\n", tree);
  return NULL;
}

ATerm PT_getIterStarSepSeparator(ATerm tree)
{
  ATerm symbol;

  if (PT_isSymbolIterStarSep(tree)) {
    ATmatchTerm(tree, asfix_iterstarsep_pattern, NULL, &symbol);
    return symbol;
  }

  ATerror("PT_getIterStarSepSeparator: not an iter-star-sep symbol: %t\n", tree);
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

ATerm PT_getVarSymSymbol(ATerm tree)
{                                   
  ATerm symbol;

  if (PT_isSymbolVarSym(tree)) {
    ATmatchTerm(tree, asfix_varsym_pattern, &symbol);
    return symbol;
  }

  ATerror("PT_getVarSymSymbol: not a varsym: %t\n", tree);
  return NULL;
}  

ATermList PT_getLayoutElems(ATerm tree)
{
  ATermList elems;
  
  if (PT_isLayout(tree)) {
    ATmatchTerm(tree, asfix_flatlayout_pattern, &elems);
    return elems;
  }
 
  ATerror("PT_getLayoutElems: not layout: %t\n", tree);
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

ATbool PT_prodHasCfOptLayoutAsRhs(ATerm  prod)
{
  /* This implements: "prod([<list>],cf(layout),<term>)" */
  if (PT_isProductionDefault(prod)) {
    ATerm rhs = PT_getProductionRhs(prod);
    if (PT_isSymbolCf(rhs)) {
      ATerm cfsym = PT_getCfSymbol(rhs);
      if (PT_isSymbolOpt(cfsym)) {
        ATerm optsym = PT_getOptSymbol(cfsym);
        return PT_isSymbolLayout(optsym);
      }
    }
    return ATfalse;
  }

  ATerror("PT_prodHasCfLayoutAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_prodHasVarSymAsRhs(ATerm prod)
{
  /* This implements: "prod([<list>],varsym(<str>),no-attrs)" */
  if (PT_isProductionDefault(prod)) {
    ATerm rhs = PT_getProductionRhs(prod);
    return PT_isSymbolVarSym(rhs);
  }

  ATerror("PT_prodHasVarSymAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_prodHasVarSymAsLhs(ATerm prod)
{
  /* This implements: "prod([varsym(<term>)],cf(<term>),<term>)" */
  if (PT_isProductionDefault(prod)) {
    ATermList lhs = PT_getProductionLhs(prod);
    ATerm rhs = PT_getProductionRhs(prod);
    if (PT_isSymbolCf(rhs) && ATgetLength(lhs) == 1) {
      ATerm lhssym = ATgetFirst(lhs);
      return PT_isSymbolVarSym(lhssym);
    }
    return ATfalse;
  }

  ATerror("PT_prodHasVarSymAsLhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_prodHasLexAsLhs(ATerm prod)
{
  /* This implements: "prod([lex(<term>)],cf(<term>),<term>)" */
  if (PT_isProductionDefault(prod)) {
    ATermList lhs = PT_getProductionLhs(prod);
    ATerm rhs = PT_getProductionRhs(prod);
    if (PT_isSymbolCf(rhs) && ATgetLength(lhs) == 1) {
      ATerm lhssym = ATgetFirst(lhs);
      return PT_isSymbolLex(lhssym);
    }
    return ATfalse;
  }

  ATerror("PT_prodHasVarSymAsLhs: not a production: %t\n", prod);
  return ATfalse;
}

void PT_initMEPTApi()
{
  init_patterns();
}
