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
#include "conversion.h"

ATbool char_to_string = ATfalse;
 
static ATerm flattenTerm(ATerm);
static ATerm flattenLayout(ATerm t);
static ATerm flattenLexical(ATerm t);
static ATerm flattenVar(ATerm t);
static ATerm flattenProd(ATerm prod);

/*  patterns  */

/* Patterns to deal with unflattened lists for charclasses */
static ATerm asfix2_empty_to_star_lex_charclass = NULL;
static ATerm asfix2_single_to_plus_lex_charclass = NULL;
static ATerm asfix2_plus_to_star_lex_charclass = NULL;
static ATerm asfix2_plus_plus_to_plus_lex_charclass = NULL;
static ATerm asfix2_star_star_to_star_lex_charclass = NULL;
static ATerm asfix2_star_plus_to_plus_lex_charclass = NULL;
static ATerm asfix2_plus_star_to_plus_lex_charclass = NULL;

/* Patterns to deal with unflattened lists for lexicals */
static ATerm asfix2_empty_to_star_lex_sort = NULL;
static ATerm asfix2_single_to_plus_lex_sort = NULL;
static ATerm asfix2_plus_to_star_lex_sort = NULL;
static ATerm asfix2_plus_plus_to_plus_lex_sort = NULL;
static ATerm asfix2_star_star_to_star_lex_sort = NULL;
static ATerm asfix2_star_plus_to_plus_lex_sort = NULL;
static ATerm asfix2_plus_star_to_plus_lex_sort = NULL;

/* Patterns to deal with unflattened lists without separators */
static ATerm asfix2_empty_to_star = NULL;
static ATerm asfix2_single_to_plus = NULL;
static ATerm asfix2_plus_to_star = NULL;
static ATerm asfix2_plus_plus_to_plus = NULL;
static ATerm asfix2_star_star_to_star = NULL;
static ATerm asfix2_star_plus_to_plus = NULL;
static ATerm asfix2_plus_star_to_plus = NULL;

/* Patterns to deal with unflattened lists with separators */
static ATerm asfix2_empty_to_star_sep = NULL;
static ATerm asfix2_single_to_plus_sep = NULL;
static ATerm asfix2_plus_sep_to_star_sep = NULL;
static ATerm asfix2_plus_sep_plus_sep_to_plus_sep = NULL;
static ATerm asfix2_star_sep_star_sep_to_star_sep = NULL;
static ATerm asfix2_star_sep_plus_sep_to_plus_sep = NULL;
static ATerm asfix2_plus_sep_star_sep_to_plus_sep = NULL;

static ATerm asfix2_amb_pattern = NULL;
static ATerm asfix2_prod_lex_layout_pattern = NULL;
static ATerm asfix2_prod_cf_layout_pattern = NULL;
static ATerm asfix2_prod_optlayout_pattern = NULL;
static ATerm asfix2_prod_var_pattern = NULL;
static ATerm asfix2_prod_varsym_pattern = NULL;
static ATerm asfix2_START_pattern = NULL;
static ATerm asfix1_layout_pattern = NULL;

/*  pattern initializations  */

void init_asfix2_patterns()
{
  ATprotect(&asfix2_empty_to_star_lex_sort);
  ATprotect(&asfix2_single_to_plus_lex_sort);
  ATprotect(&asfix2_plus_to_star_lex_sort);
  ATprotect(&asfix2_plus_plus_to_plus_lex_sort);
  ATprotect(&asfix2_star_star_to_star_lex_sort);
  ATprotect(&asfix2_star_plus_to_plus_lex_sort);
  ATprotect(&asfix2_plus_star_to_plus_lex_sort);
  ATprotect(&asfix2_empty_to_star_lex_charclass);
  ATprotect(&asfix2_single_to_plus_lex_charclass);
  ATprotect(&asfix2_plus_to_star_lex_charclass);
  ATprotect(&asfix2_plus_plus_to_plus_lex_charclass);
  ATprotect(&asfix2_star_star_to_star_lex_charclass);
  ATprotect(&asfix2_star_plus_to_plus_lex_charclass);
  ATprotect(&asfix2_plus_star_to_plus_lex_charclass);
  ATprotect(&asfix2_empty_to_star);
  ATprotect(&asfix2_single_to_plus);
  ATprotect(&asfix2_plus_to_star);
  ATprotect(&asfix2_plus_plus_to_plus);
  ATprotect(&asfix2_star_star_to_star);
  ATprotect(&asfix2_star_plus_to_plus);
  ATprotect(&asfix2_plus_star_to_plus);
  ATprotect(&asfix2_empty_to_star_sep);
  ATprotect(&asfix2_single_to_plus_sep);
  ATprotect(&asfix2_plus_sep_to_star_sep);
  ATprotect(&asfix2_plus_sep_plus_sep_to_plus_sep);
  ATprotect(&asfix2_star_sep_star_sep_to_star_sep);
  ATprotect(&asfix2_star_sep_plus_sep_to_plus_sep);
  ATprotect(&asfix2_plus_sep_star_sep_to_plus_sep);
  ATprotect(&asfix2_amb_pattern);
  ATprotect(&asfix2_prod_lex_layout_pattern);
  ATprotect(&asfix2_prod_cf_layout_pattern);
  ATprotect(&asfix2_prod_optlayout_pattern);
  ATprotect(&asfix2_prod_var_pattern);
  ATprotect(&asfix2_prod_varsym_pattern);
  ATprotect(&asfix2_START_pattern);
  ATprotect(&asfix1_layout_pattern);

  asfix2_empty_to_star_lex_sort  =
    ATparse("prod([],lex(iter-star(sort(<term>))),no-attrs)");
  asfix2_single_to_plus_lex_sort =
    ATparse("prod([lex(sort(<term>))],lex(iter(sort(<term>))),no-attrs)");
  asfix2_plus_to_star_lex_sort =
    ATparse("prod([lex(iter(sort(<term>)))],lex(iter-star(sort(<term>))),no-attrs)");
  asfix2_plus_plus_to_plus_lex_sort =
    ATparse("prod([lex(iter(sort(<term>))),lex(iter(sort(<term>)))]," \
            "lex(iter(sort(<term>))),<term>)");
  asfix2_star_star_to_star_lex_sort =
    ATparse("prod([lex(sort(iter-star(<term>)))," \
            "lex(iter-star(sort(<term>)))]," \
            "lex(iter-star(sort(<term>))),<term>)");
  asfix2_star_plus_to_plus_lex_sort =
    ATparse("prod([lex(iter-star(sort(<term>))),lex(iter(sort(<term>)))]," \
            "lex(iter(sort(<term>))),<term>)");
  asfix2_plus_star_to_plus_lex_sort =
    ATparse("prod([lex(iter(sort(<term>))),lex(iter-star(sort(<term>)))]," \
            "lex(iter(sort(<term>))),<term>)");

  asfix2_empty_to_star_lex_charclass  =
    ATparse("prod([],lex(iter-star(char-class(<term>))),no-attrs)");
  asfix2_single_to_plus_lex_charclass =
    ATparse("prod([char-class(<term>)]," \
            "lex(iter(char-class(<term>))),no-attrs)");
  asfix2_plus_to_star_lex_charclass =
    ATparse("prod([lex(iter(char-class(<term>)))]," \
            "lex(iter-star(char-class(<term>))),no-attrs)");
  asfix2_plus_plus_to_plus_lex_charclass =
    ATparse("prod([lex(iter(char-class(<term>)))," \
            "lex(iter(char-class(<term>)))]," \
            "lex(iter(char-class(<term>))),<term>)");
  asfix2_star_star_to_star_lex_charclass =
    ATparse("prod([lex(iter-star(char-class(<term>)))," \
            "lex(iter-star(char-class(<term>)))]," \
            "lex(iter-star(char-class(<term>))),<term>)");
  asfix2_star_plus_to_plus_lex_charclass =
    ATparse("prod([lex(iter-star(char-class(<term>)))," \
            "lex(iter(char-class(<term>)))]," \
            "lex(iter(char-class(<term>))),<term>)");
  asfix2_plus_star_to_plus_lex_charclass =
    ATparse("prod([lex(iter(char-class(<term>)))," \
            "lex(iter-star(char-class(<term>)))]," \
            "lex(iter(char-class(<term>))),<term>)");

  asfix2_empty_to_star  =
    ATparse("prod([],cf(iter-star(<term>)),no-attrs)");
  asfix2_single_to_plus =
    ATparse("prod([cf(<term>)],cf(iter(<term>)),no-attrs)");
  asfix2_plus_to_star =
    ATparse("prod([cf(iter(<term>))],cf(iter-star(<term>)),no-attrs)");
  asfix2_plus_plus_to_plus =
    ATparse("prod([cf(iter(<term>)),cf(opt(layout)),cf(iter(<term>))]," \
            "cf(iter(<term>)),<term>)");
  asfix2_star_star_to_star =
    ATparse("prod([cf(iter-star(<term>)),cf(opt(layout))," \
            "cf(iter-star(<term>))],cf(iter-star(<term>)),<term>)");
  asfix2_star_plus_to_plus =
    ATparse("prod([cf(iter-star(<term>)),cf(opt(layout)),cf(iter(<term>))]," \
            "cf(iter(<term>)),<term>)");
  asfix2_plus_star_to_plus =
    ATparse("prod([cf(iter(<term>)),cf(opt(layout)),cf(iter-star(<term>))]," \
            "cf(iter(<term>)),<term>)");

  asfix2_empty_to_star_sep =
    ATparse("prod([],cf(iter-star-sep(<term>,<term>)),no-attrs)");
  asfix2_single_to_plus_sep =
    ATparse("prod([cf(<term>)],cf(iter-sep(<term>,<term>)),no-attrs)");
  asfix2_plus_sep_to_star_sep =
    ATparse("prod([cf(iter-sep(<list>))],cf(iter-star-sep(<list>)),no-attrs)");
  asfix2_plus_sep_plus_sep_to_plus_sep =
    ATparse("prod([cf(iter-sep(<list>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-sep(<list>))],cf(iter-sep(<list>))," \
            "<term>)");
  asfix2_star_sep_star_sep_to_star_sep =
    ATparse("prod([cf(iter-star-sep(<list>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-star-sep(<list>))]," \
            "cf(iter-star-sep(<list>)),<term>)");
  asfix2_star_sep_plus_sep_to_plus_sep =
    ATparse("prod([cf(iter-star-sep(<list>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-sep(<list>))],cf(iter-sep(<list>))," \
            "<term>)");
  asfix2_plus_sep_star_sep_to_plus_sep =
    ATparse("prod([cf(iter-sep(<list>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-star-sep(<list>))],cf(iter-sep(<list>))," \
            "<term>)");
  
  asfix2_amb_pattern =
    ATparse("amb([<list>])");
  asfix2_prod_lex_layout_pattern =
    ATparse("prod([<list>],lex(layout),<term>)");
  asfix2_prod_cf_layout_pattern =
    ATparse("prod([<list>],cf(layout),<term>)");
  asfix2_prod_optlayout_pattern =
    ATparse("prod([<list>],cf(opt(layout)),no-attrs)");
  asfix2_prod_var_pattern =
    ATparse("prod([varsym(<term>)],cf(<term>),<term>)");
  asfix2_prod_varsym_pattern =
    ATparse("prod([<list>],varsym(<term>),<term>)");
  asfix2_START_pattern =
    ATparse("appl(prod([cf(opt(layout)),<term>,cf(opt(layout))]," \
             "sort(\"<START>\"),no-attrs),[<list>])");
  asfix1_layout_pattern =
    ATparse("layout([<list>])");
}

void init_a2toa1_patterns(void)
{
  static ATbool patterns_initialized = ATfalse;

  if (patterns_initialized) {
    return;
  }
  patterns_initialized = ATtrue;

  init_asfix2_patterns();
}

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

static ATbool isLexicalListProd(ATerm prod) 
{
  ATerm sort1, sort2, sort3;

  if (ATmatchTerm(prod, asfix2_empty_to_star_lex_sort, NULL)) {
    return ATtrue;
  }
 
  if (ATmatchTerm(prod, asfix2_single_to_plus_lex_sort, &sort1, &sort2)
      ||
      ATmatchTerm(prod, asfix2_plus_to_star_lex_sort, &sort1, &sort2)) {
    return ATisEqual(sort1, sort2);
  } 
 
  if (ATmatchTerm(prod, asfix2_plus_plus_to_plus_lex_sort,
                  &sort1, &sort2, &sort3, NULL)
      ||
      ATmatchTerm(prod, asfix2_star_star_to_star_lex_sort,
                  &sort1, &sort2, &sort3, NULL)
      ||
      ATmatchTerm(prod, asfix2_star_plus_to_plus_lex_sort,
                  &sort1, &sort2, &sort3, NULL)
      ||
      ATmatchTerm(prod, asfix2_plus_star_to_plus_lex_sort,
                  &sort1, &sort2, &sort3, NULL)) {
    return ATisEqual(sort1, sort2) && ATisEqual(sort1, sort3);
  }
  
  return ATfalse; 
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
    ATerror("flattenLexicalList: not an appl pattern: %t\n", t);
    return NULL;
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

static ATbool isCharClassListProd(ATerm prod) 
{
  ATerm cc1, cc2, cc3;

  if (ATmatchTerm(prod, asfix2_empty_to_star_lex_charclass, NULL)) {
    return ATtrue;
  }
 
  if (ATmatchTerm(prod, asfix2_single_to_plus_lex_charclass, &cc1, &cc2)
      ||
      ATmatchTerm(prod, asfix2_plus_to_star_lex_charclass, &cc1, &cc2)) {
    return ATisEqual(cc1, cc2);
  } 
 
  if (ATmatchTerm(prod, asfix2_plus_plus_to_plus_lex_charclass,
                  &cc1, &cc2, &cc3, NULL)
      ||
      ATmatchTerm(prod, asfix2_star_star_to_star_lex_charclass,
                  &cc1, &cc2, &cc3, NULL)
      ||
      ATmatchTerm(prod, asfix2_star_plus_to_plus_lex_charclass,
                  &cc1, &cc2, &cc3, NULL)
      ||
      ATmatchTerm(prod, asfix2_plus_star_to_plus_lex_charclass,
                  &cc1, &cc2, &cc3, NULL)) {
    return ATisEqual(cc1, cc2) && ATisEqual(cc1, cc3);
  }
  
  return ATfalse; 
}

static ATermList flattenCharClassList(ATerm t, ATermList tail)
{
  ATerm     prod;
  ATermList list;

  if (ATgetType(t) == AT_INT) {
    return ATinsert(tail, makeCharFromInt((ATermInt) t));
  }

  if (!PT_isTreeAppl(t)) { 
    ATerror("flattenCharClassList: not an appl pattern: %t\n", t);
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

static ATbool isListProd(ATerm prod) 
{
  ATerm sort1, sort2, sort3;

  if (ATmatchTerm(prod, asfix2_empty_to_star, NULL)) {
    return ATtrue;
  }
 
  if (ATmatchTerm(prod, asfix2_single_to_plus, &sort1, &sort2)
      ||
      ATmatchTerm(prod, asfix2_plus_to_star, &sort1, &sort2)) {
    return ATisEqual(sort1, sort2);
  } 
 
  if (ATmatchTerm(prod, asfix2_plus_plus_to_plus,
                  &sort1, &sort2, &sort3, NULL)
      ||
      ATmatchTerm(prod, asfix2_star_star_to_star,
                  &sort1, &sort2, &sort3, NULL)
      ||
      ATmatchTerm(prod, asfix2_star_plus_to_plus,
                  &sort1, &sort2, &sort3, NULL)
      ||
      ATmatchTerm(prod, asfix2_plus_star_to_plus,
                  &sort1, &sort2, &sort3, NULL)) {
    return ATisEqual(sort1, sort2) && ATisEqual(sort1, sort3);
  }
  
  return ATfalse; 
}

static ATermList flattenList(ATerm t, ATermList tail)
{
  ATerm     prod;
  ATermList list;

  if (!PT_isTreeAppl(t)) {
    ATerror("flattenList: not an appl pattern: %t\n", t);
    return NULL;
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

static ATbool isSepListProd(ATerm prod) 
{
  ATerm sort1, sort2;
  ATermList sortSep1, sortSep2, sortSep3;

  if (ATmatchTerm(prod, asfix2_empty_to_star_sep, NULL, NULL)) {
    return ATtrue;
  }
 
  if (ATmatchTerm(prod, asfix2_single_to_plus_sep, &sort1, &sort2, NULL)) {
    return ATisEqual(sort1, sort2);
  } 
 
  if (ATmatchTerm(prod, asfix2_plus_sep_to_star_sep, &sortSep1, &sortSep2, NULL)) {
    return ATisEqual(sortSep1, sortSep2);
  } 
 
  if (ATmatchTerm(prod, asfix2_plus_sep_plus_sep_to_plus_sep,
                  &sortSep1, NULL, &sortSep2, &sortSep3, NULL)
      ||
      ATmatchTerm(prod, asfix2_star_sep_star_sep_to_star_sep,
                  &sortSep1, NULL, &sortSep2, &sortSep3, NULL)
      ||
      ATmatchTerm(prod, asfix2_star_sep_plus_sep_to_plus_sep,
                  &sortSep1, NULL, &sortSep2, &sortSep3, NULL)
      ||
      ATmatchTerm(prod, asfix2_plus_sep_star_sep_to_plus_sep,
                  &sortSep1, NULL, &sortSep2, &sortSep3, NULL)) {
    return ATisEqual(sortSep1, sortSep2) && ATisEqual(sortSep1, sortSep3);
  }
  
  return ATfalse; 
}

static ATermList flattenSepList(ATerm t, ATermList tail)
{
  ATerm     prod;
  ATermList list;

  if (!PT_isTreeAppl(t)) {
    ATerror("flattenSepList: not an appl pattern: %t\n", t);
    return NULL;
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

    return ATmakeTerm(asfix1_layout_pattern, newArgs);
  }
  ATerror("flattenLayout: not an appl pattern: %t\n\n", t);
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

  if (PT_isTreeAppl(t)) {
    prodVarsymOuter = PT_getTreeProd(t);
    argsOuter       = PT_getTreeArgs(t);

    if (ATmatchTerm(prodVarsymOuter, asfix2_prod_var_pattern,
                    NULL, NULL, NULL)) {
      ATerm arg = ATgetFirst(argsOuter);

      if (PT_isTreeAppl(arg)) {
        prodVarsymInner = PT_getTreeProd(arg);
        argsInner       = PT_getTreeArgs(arg);

        if (ATmatchTerm(prodVarsymInner, asfix2_prod_varsym_pattern,
                        NULL, NULL, NULL)) {
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
    }
  }
  ATerror("flattenVar: not an appl pattern: %t\n\n", t);
  return NULL;
}

static ATerm flattenTerm(ATerm t)
{
  ATerm prod;
  ATermList args;

  if (ATgetType(t) == AT_INT) {
    return makeCharFromInt((ATermInt) t);
  }

  if (ATmatchTerm(t, asfix2_amb_pattern, &args)) {
    return ATmakeTerm(asfix2_amb_pattern, flattenArgs(args));
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
  if (ATmatchTerm(prod, asfix2_prod_optlayout_pattern, NULL)) {
    return flattenLayout(t);
  }

  /* Lexical */
  if (PT_prodHasLexSortAsRhs(prod)) {
    return flattenLexical(t);
  }

  /* Variable */
  if (ATmatchTerm(prod, asfix2_prod_var_pattern, NULL, NULL, NULL)) {
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

static ATerm flattenParseTree(ATerm tree)
{
  if (PT_isParseTreeTree(tree)) {
    ATerm newTree = PT_getParseTreeTree(tree);
    ATerm ambCnt = PT_getParseTreeAmbCnt(tree);

    return PT_makeParseTreeTree(flattenTerm(newTree), ambCnt);
  }

  ATerror("flattenParseTree: not a parsetree: %t\n", tree);
  return NULL;
}

ATerm flattenPT(ATerm t)
{
  ATerm newTree;

  init_a2toa1_patterns();
  newTree = flattenParseTree(t);
  return newTree;
}
