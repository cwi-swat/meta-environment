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

#include "conversion.h"

ATbool flatten_lexical = ATtrue;
ATbool interpret_cons = ATfalse;
ATbool flatten_layout = ATtrue;
ATbool remove_layout = ATfalse;
ATbool flatten_list = ATtrue;
ATbool char_to_string = ATfalse;
ATbool lexical_to_string = ATfalse;
ATbool layout_to_string = ATfalse;
ATbool remove_literals = ATfalse;
 
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

static ATerm asfix2_prod_pattern = NULL;
static ATerm asfix2_attrs_pattern = NULL;
static ATerm asfix2_cons_pattern = NULL;
static ATerm asfix2_aterm_cons_pattern = NULL;
static ATerm asfix2_atr_pattern = NULL;
static ATerm asfix2_id_pattern = NULL;
static ATerm asfix_appl_pattern = NULL;
static ATerm asfix2_list_pattern = NULL;
static ATerm asfix2_parsetree_pattern = NULL;
static ATerm asfix2_amb_pattern = NULL;
static ATerm asfix2_prod_lit_pattern = NULL;
static ATerm asfix2_prod_lex_layout_pattern = NULL;
static ATerm asfix2_prod_cf_layout_pattern = NULL;
static ATerm asfix2_prod_optlayout_pattern = NULL;
static ATerm asfix2_prod_lexical_pattern = NULL;
static ATerm asfix2_prod_var_pattern = NULL;
static ATerm asfix2_prod_varsym_pattern = NULL;
static ATerm asfix2_START_pattern = NULL;
static ATerm asfix1_lit_pattern = NULL;
static ATerm asfix1_list_pattern = NULL;
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
  ATprotect(&asfix2_prod_pattern);
  ATprotect(&asfix2_attrs_pattern);
  ATprotect(&asfix2_cons_pattern);
  ATprotect(&asfix2_aterm_cons_pattern);
  ATprotect(&asfix2_atr_pattern);
  ATprotect(&asfix2_id_pattern);
  ATprotect(&asfix2_list_pattern);
  ATprotect(&asfix2_parsetree_pattern);
  ATprotect(&asfix2_amb_pattern);
  ATprotect(&asfix2_prod_lit_pattern);
  ATprotect(&asfix2_prod_lex_layout_pattern);
  ATprotect(&asfix2_prod_cf_layout_pattern);
  ATprotect(&asfix2_prod_optlayout_pattern);
  ATprotect(&asfix2_prod_lexical_pattern);
  ATprotect(&asfix2_prod_var_pattern);
  ATprotect(&asfix2_prod_varsym_pattern);
  ATprotect(&asfix2_START_pattern);
  ATprotect(&asfix1_lit_pattern);
  ATprotect(&asfix1_list_pattern);
  ATprotect(&asfix1_layout_pattern);
  ATprotect(&asfix_appl_pattern);

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
  
  asfix2_prod_pattern =
    ATparse("prod(<term>,<term>,<term>)");
  asfix2_attrs_pattern =
    ATparse("attrs([<list>])");
  asfix2_cons_pattern =
    ATparse("cons(<str>)");
  asfix2_aterm_cons_pattern =
    ATparse("aterm(cons(<str>))");
  asfix2_atr_pattern =
    ATparse("atr(<str>)");
  asfix2_id_pattern =
    ATparse("id(<str>)");
  asfix_appl_pattern =
    ATparse("appl(<term>,[<list>])");
  asfix2_list_pattern =
    ATparse("[<list>]");
  asfix2_parsetree_pattern =
    ATparse("parsetree(<term>,<term>)");
  asfix2_amb_pattern =
    ATparse("amb([<list>])");
  asfix2_prod_lit_pattern =
    ATparse("prod([<list>],lit(<str>),no-attrs)");
  asfix2_prod_lex_layout_pattern =
    ATparse("prod([<list>],lex(layout),<term>)");
  asfix2_prod_cf_layout_pattern =
    ATparse("prod([<list>],cf(layout),<term>)");
  asfix2_prod_optlayout_pattern =
    ATparse("prod([<list>],cf(opt(layout)),no-attrs)");
  asfix2_prod_lexical_pattern =
    ATparse("prod([<list>],lex(sort(<term>)),<term>)");
  asfix2_prod_var_pattern =
    ATparse("prod([varsym(<term>)],cf(<term>),<term>)");
  asfix2_prod_varsym_pattern =
    ATparse("prod([<list>],varsym(<term>),<term>)");
  asfix2_START_pattern =
    ATparse("appl(prod([cf(opt(layout)),<term>,cf(opt(layout))]," \
             "sort(\"<START>\"),no-attrs),[<list>])");
  asfix1_lit_pattern =
    ATparse("lit(<str>)");
  asfix1_layout_pattern =
    ATparse("layout([<list>])");
  asfix1_list_pattern =
    ATparse("list([<list>])");
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

  if (!ATmatchTerm(t, asfix_appl_pattern, &prod, &list)) {
    ATerror("flattenLexicalList: not an appl pattern: %t\n", t);
    return NULL;
  } 
  
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

  if (!ATmatchTerm(t, asfix_appl_pattern, &prod, &list)) {
    ATerror("flattenCharClassList: not an appl pattern: %t\n", t);
  }
  
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

  if (!ATmatchTerm(t, asfix_appl_pattern, &prod, &list)) {
    ATerror("flattenList: not an appl pattern: %t\n", t);
    return NULL;
  }

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
    if (!remove_layout) {
      tail = ATinsert(tail, flattenLayout(layoutAfterLeft));
    }
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

  if (!ATmatchTerm(t, asfix_appl_pattern, &prod, &list)) {
    ATerror("flattenSepList: not an appl pattern: %t\n", t);
    return NULL;
  }

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
    if (!remove_layout) {
      tail = ATinsert(tail, flattenLayout(layoutAfterSep));
    } 
    if (!remove_literals) {
      tail = ATinsert(tail, flattenTerm(separator));
    }
    if (!remove_layout) {
      tail = ATinsert(tail, flattenLayout(layoutAfterLeft));
    } 
    tail = flattenSepList(leftBranch, tail);
  
    return tail;
  }

  ATerror("flattenSepList: illegal list: %t\n", t);
  return NULL;
}

static ATerm flattenProd(ATerm prod)
{
  ATerm         attr;
  ATermList     attrs;
  char          *lit;

  if(!ATmatchTerm(prod, asfix2_prod_pattern, NULL, NULL, &attr)) {
    ATerror("flattenProd: not a production: %t\n", prod);
  }

  if (ATmatchTerm(attr, asfix2_attrs_pattern, &attrs)) {
    if (interpret_cons) {
      while(!ATisEmpty(attrs)) {
        attr = ATgetFirst(attrs);
        attrs = ATgetNext(attrs);
        if(ATmatchTerm(attr, asfix2_cons_pattern, &lit))
          return ATmake("<str>",lit);
        else if(ATmatchTerm(attr, asfix2_aterm_cons_pattern, &lit))
          return ATmake("<str>",lit);
      }
    }
  }

  return prod;
}

static int lengthOfLexicals(ATermList lexicals)
{
  ATermList  args;
  char      *lit;
  int        length = 0;

  if (ATisEmpty(lexicals)) {
    return 0;
  }

  while (!ATisEmpty(lexicals)) {
    ATerm lex = ATgetFirst(lexicals);
    lexicals = ATgetNext(lexicals);

    if (ATgetType(lex) == AT_INT) {
      length++;
    }
    else if (ATgetType(lex) == AT_LIST) {
      length = length + lengthOfLexicals((ATermList)lex);
    }
    else if (ATmatchTerm(lex, asfix_appl_pattern, NULL, &args)) {
      length = length + lengthOfLexicals(args);
    }
    else if (ATmatchTerm(lex, asfix1_lit_pattern, &lit)) {
      length = length + strlen(lit);
    }
    else {
      ATerror("lengthOfLexicals: unknown term %t\n", lex);
      return 0;
    }
  }
  return length;
}

static int lexicalsToStringRecursive(ATermList lexicals,
                                     int idx, char *buf, int bufSize)
{
  ATermList  args;
  char      *lit;

  while (!ATisEmpty(lexicals)) {
    ATerm lex = ATgetFirst(lexicals);
    lexicals = ATgetNext(lexicals);

    assert(idx <= bufSize);

    if (ATgetType(lex) == AT_INT) {
      buf[idx++] = (char)ATgetInt((ATermInt)lex);
    }
    else if (ATgetType(lex) == AT_LIST) {
      idx = lexicalsToStringRecursive((ATermList)lex, idx, buf, bufSize);
    }
    else if (ATmatchTerm(lex, asfix_appl_pattern, NULL, &args)) {
      idx = lexicalsToStringRecursive(args, idx, buf, bufSize);
    }
    else if (ATmatchTerm(lex, asfix1_lit_pattern, &lit)) {
      int i, len = strlen(lit);

      for (i = 0; i < len; i++) {
        buf[idx++] = lit[i];
      }
    }
    else {
      ATerror("lexicalsToStringRecursive: unknown term %t\n", lex);
    }
  }
  return idx;
}       

static ATerm lexicalsToString(ATermList lexicals)
{
  char *buf = NULL;
  int   len = 0;

  ATerm strTerm;
  int   idx = 0;

  if (ATisEmpty(lexicals)) {
    return ATparse("\"\"");
  }

  len = lengthOfLexicals(lexicals);

  buf = (char *) calloc(len+1, sizeof(char));

  idx = lexicalsToStringRecursive(lexicals, 0, buf, len);

  assert(idx == len);

  /* terminate string */
  buf[idx++] = '\0';

  strTerm = ATmake("<str>", buf);

  free(buf);

  return strTerm;
}    

static ATerm flattenLexical(ATerm t)
{
  ATerm outerProd;
  ATermList args;
  ATermList newArgs = ATempty;

  if (flatten_lexical) {
    if (ATmatchTerm(t, asfix_appl_pattern, &outerProd, &args)) {

      while (!ATisEmpty(args)) {
        ATerm arg = ATgetFirst(args);
        ATerm newTerm = flattenTerm(arg);

        if (newTerm) {
          newArgs = ATappend(newArgs, newTerm);
        }
        args = ATgetNext(args);
      }
    }
    if (lexical_to_string) {
      return lexicalsToString(newArgs);
    }
    else {
      return ATmakeTerm(asfix_appl_pattern, flattenProd(outerProd), newArgs);
    }
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
    else if (ATmatchTerm(arg, asfix_appl_pattern, &prod, &list)) {
  
      if (ATmatchTerm(prod, asfix2_prod_lex_layout_pattern, NULL, NULL)
          ||
          ATmatchTerm(prod, asfix2_prod_cf_layout_pattern, NULL, NULL)) {
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

  if (flatten_layout) {
    if (ATmatchTerm(t, asfix_appl_pattern, NULL, &args)) {
      ATermList newArgs = flattenLayoutList(args, ATempty);

      if (layout_to_string) {
        ATermList layoutString = ATmakeList1(lexicalsToString(newArgs));
        return ATmakeTerm(asfix1_layout_pattern, layoutString);
      }
      else {
        return ATmakeTerm(asfix1_layout_pattern, newArgs);
      }
    }
    ATerror("flattenLayout: not an appl pattern: %t\n\n", t);
    return NULL;
  }
  else {
    return t;
  }
}

static ATerm flattenLiteral(ATerm prod)
{
  char *lit;

  if (remove_literals) {
    return NULL;
  }

  if (ATmatchTerm(prod, asfix2_prod_lit_pattern, NULL, &lit)) {
    return ATmakeTerm(asfix1_lit_pattern, lit);
  } 

  ATerror("flattenLiteral: not a literal prod: %t\n", prod);
  return NULL;
}

static ATerm flattenVar(ATerm t)
{
  ATerm prodVarsymOuter, prodVarsymInner;
  ATermList argsOuter, argsInner;

  if (ATmatchTerm(t, asfix_appl_pattern, &prodVarsymOuter, &argsOuter)) {
    if (ATmatchTerm(prodVarsymOuter, asfix2_prod_var_pattern,
                    NULL, NULL, NULL)) {
      ATerm arg = ATgetFirst(argsOuter);

      if (ATmatchTerm(arg, asfix_appl_pattern, &prodVarsymInner, &argsInner)) {
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
          newVarArg = ATmakeList1(ATmakeTerm(asfix_appl_pattern,
                                             flattenProd(prodVarsymInner),
                                             newVarArgs));
          return ATmakeTerm(asfix_appl_pattern,
                            flattenProd(prodVarsymOuter),
                            newVarArg);
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

  if (!ATmatchTerm(t, asfix_appl_pattern, &prod, &args)) {
    ATerror("flattenTerm: not an appl pattern: %t\n", t);
    return NULL;
  }

  /* Literal */
  if (ATmatchTerm(prod, asfix2_prod_lit_pattern, NULL, NULL)) {
    return flattenLiteral(prod);
  }

  /* Layout */
  if (ATmatchTerm(prod, asfix2_prod_optlayout_pattern, NULL)) {
    if (!remove_layout) {
      return flattenLayout(t);
    }
    else {
      return NULL;
    }
  }

  /* Lexical */
  if (ATmatchTerm(prod, asfix2_prod_lexical_pattern, NULL, NULL, NULL)) {
    return flattenLexical(t);
  }

  /* Variable */
  if (ATmatchTerm(prod, asfix2_prod_var_pattern, NULL, NULL, NULL)) {
    return flattenVar(t);
  }

  /* Lists */
  if (flatten_list) {
    if (isSepListProd(prod)) {
      ATermList newList = ATmakeList1((ATerm)flattenSepList(t, ATempty));
      return ATmakeTerm(asfix_appl_pattern, flattenProd(prod), newList);
    }

    if (isListProd(prod)) {
      ATermList newList = ATmakeList1((ATerm)flattenList(t, ATempty));
      return ATmakeTerm(asfix_appl_pattern, flattenProd(prod), newList);
    }

    if (isLexicalListProd(prod)) {
      return (ATerm)flattenLexicalList(t, ATempty);
    }

    if (isCharClassListProd(prod)) {
      return (ATerm)flattenCharClassList(t, ATempty);
    }
  }

  /* Default: application */
  return ATmakeTerm(asfix_appl_pattern, flattenProd(prod), flattenArgs(args));
}

static ATerm flattenParseTree(ATerm tree)
{
  ATerm  newTree, ambCnt;

  if (ATmatchTerm(tree, asfix2_parsetree_pattern, &newTree, &ambCnt)) {
    return ATmakeTerm(asfix2_parsetree_pattern, flattenTerm(newTree), ambCnt);
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
