/*

    MEPT -- The Meta-Environment Parse Tree library

    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
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

#include <aterm2.h>
#include <deprecated.h>

#include <mept.h>
#include "conversion.h"

/* Function prototypes (only the badly needed ones) */

static ATerm termToAsFix1(ATerm);

/*  patterns  */

/* Definition of AsFix2 patterns and their initialization */

static ATerm asfix2_opt_layout_pattern = NULL;
static ATerm asfix2_prod_pattern = NULL;
static ATerm asfix2_attrs_pattern = NULL;
static ATerm asfix2_cons_pattern = NULL;
static ATerm asfix2_aterm_cons_pattern = NULL;
static ATerm asfix2_atr_pattern = NULL;
static ATerm asfix2_id_pattern = NULL;
static ATerm asfix2_appl_starlist_sep_pattern = NULL;
static ATerm asfix2_appl_pluslist_sep_pattern = NULL;
static ATerm asfix2_appl_starlist_pattern = NULL;
static ATerm asfix2_appl_pluslist_pattern = NULL;
static ATerm asfix2_START_pattern = NULL;
static ATerm asfix1_iter_pattern = NULL;
static ATerm asfix1_itersep_pattern = NULL;
static ATerm asfix1_iter_star_pattern = NULL;
static ATerm asfix1_iter_plus_pattern = NULL;
static ATerm asfix1_itersep_star_pattern = NULL;
static ATerm asfix1_itersep_plus_pattern = NULL;
static ATerm asfix1_ws_pattern = NULL;
static ATerm asfix1_sep_pattern = NULL;

static ATerm pattern_asfix_l;
static ATerm pattern_asfix_lexterm;
static ATerm pattern_asfix_varterm;
static ATerm pattern_asfix_ws_term;
static ATerm pattern_asfix_appl;
static ATerm pattern_asfix_ews;
static ATerm pattern_asfix_ql;
static ATerm pattern_asfix_list;

/*  pattern initializations  */

static void init_asfix_patterns();

static void init_patterns(void)
{
  static ATbool patterns_initialized = ATfalse;

  if (patterns_initialized) {
    return;
  }
  patterns_initialized = ATtrue;

  init_asfix_patterns();
}

static void init_asfix_patterns()
{
  ATprotect(&asfix2_opt_layout_pattern);
  ATprotect(&asfix2_prod_pattern);
  ATprotect(&asfix2_attrs_pattern);
  ATprotect(&asfix2_cons_pattern);
  ATprotect(&asfix2_aterm_cons_pattern);
  ATprotect(&asfix2_atr_pattern);
  ATprotect(&asfix2_id_pattern);
  ATprotect(&asfix2_appl_starlist_sep_pattern);
  ATprotect(&asfix2_appl_pluslist_sep_pattern);
  ATprotect(&asfix2_appl_starlist_pattern);
  ATprotect(&asfix2_appl_pluslist_pattern);
  ATprotect(&asfix2_START_pattern);
  ATprotect(&asfix1_iter_pattern);
  ATprotect(&asfix1_itersep_pattern);
  ATprotect(&asfix1_iter_star_pattern);
  ATprotect(&asfix1_iter_plus_pattern);
  ATprotect(&asfix1_itersep_star_pattern);
  ATprotect(&asfix1_itersep_plus_pattern);
  ATprotect(&asfix1_ws_pattern);
  ATprotect(&asfix1_sep_pattern);
  ATprotect(&pattern_asfix_l);
  ATprotect(&pattern_asfix_lexterm);
  ATprotect(&pattern_asfix_varterm);
  ATprotect(&pattern_asfix_ws_term);
  ATprotect(&pattern_asfix_appl);
  ATprotect(&pattern_asfix_ews);
  ATprotect(&pattern_asfix_ql);
  ATprotect(&pattern_asfix_list);

  asfix2_opt_layout_pattern = ATparse("opt(layout)");
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
  asfix2_appl_starlist_sep_pattern =
    ATparse("appl(prod([<list>],cf(iter-star-sep(<term>,lit(<str>)))," \
            "<term>),[<list>])");
  asfix2_appl_pluslist_sep_pattern =
    ATparse("appl(prod([<list>],cf(iter-sep(<term>,lit(<str>)))," \
            "<term>),[<list>])");
  asfix2_appl_starlist_pattern =
    ATparse("appl(prod([<list>],cf(iter-star(<term>)),<term>),[<list>])");
  asfix2_appl_pluslist_pattern =
    ATparse("appl(prod([<list>],cf(iter(<term>)),<term>),[<list>])");
  asfix2_START_pattern =
    ATparse("appl(prod([cf(opt(layout)),<term>,cf(opt(layout))]," \
             "sort(\"<START>\"),no-attrs),[<list>])");  
  asfix1_iter_pattern =
    ATparse("iter(<term>,w(\"\"),l(\"*\"))");
  asfix1_itersep_pattern =
    ATparse("iter-sep(l(\"{\"),w(\"\"),<term>,w(\"\"),ql(<str>)," \
            "w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))");
  asfix1_iter_star_pattern =
    ATparse("iter(<term>,w(\"\"),l(\"*\"))");
  asfix1_iter_plus_pattern =
    ATparse("iter(<term>,w(\"\"),l(\"+\"))");
  asfix1_itersep_star_pattern =
    ATparse("iter-sep(l(\"{\"),w(\"\"),<term>,w(\"\"),ql(<str>)," \
            "w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))");
  asfix1_itersep_plus_pattern =
    ATparse("iter-sep(l(\"{\"),w(\"\"),<term>,w(\"\"),ql(<str>)," \
            "w(\"\"),l(\"}\"),w(\"\"),l(\"+\"))");
  asfix1_ws_pattern = ATparse("w(<term>)");
  pattern_asfix_l = ATparse("l(<str>)");
  pattern_asfix_lexterm = ATparse("lex(<term>,<term>)");
  pattern_asfix_varterm = ATparse("var(<term>,<term>)");
  pattern_asfix_ws_term = ATparse("w(<term>)");
  pattern_asfix_appl = ATparse("appl(<term>,<term>,[<list>])");
  pattern_asfix_ews = ATparse("w(\"\")");
  pattern_asfix_ql = ATparse("ql(<str>)");
  pattern_asfix_list = ATparse("list(<term>,<term>,[<list>])");

 asfix1_sep_pattern = ATparse("sep(<str>)");
}

static ATermList argsToAsFix1(ATermList tl)
{
  if (ATisEmpty(tl)) {
    return tl;
  }
  else {
    return ATinsert(argsToAsFix1(ATgetNext(tl)), termToAsFix1(ATgetFirst(tl)));
  }
}
static ATerm separatorToAsFix1(ATerm t)
{
  if (PT_isSymbolLit(t)) {
    return  ATmakeTerm(asfix1_sep_pattern, PT_getLitString(t));
  }

  ATerror("separatorToAsFix1: not a literal pattern: %t\n", t);
  return NULL;
}

static ATermList listToAsFix1(ATermList list)
{
  ATerm     newTerm;
  ATermList newList = ATempty;

  ATermList argList = (ATermList)ATgetFirst(list);

  while (!ATisEmpty(argList)) {
    ATerm elem = ATgetFirst(argList);
    if (PT_isSymbolLit(elem)) {
      newTerm = separatorToAsFix1(elem);
    }
    else {
      newTerm = termToAsFix1(elem);
    }
    newList = ATappend(newList, newTerm);
    argList = ATgetNext(argList);
  }
  return newList;
}

static ATerm removeCfLexSymbol(ATerm t)
{
  if (PT_isSymbolCf(t)) {        
    return PT_getCfSymbol(t);
  }

  if (PT_isSymbolLex(t)) {
    return PT_getLexSymbol(t);
  }

  return t; 
}

static char *escape_str(char *s)
{
  static size_t dstsize = 0;
  static char   *dst = NULL;
  char          *d;
  size_t        len, backslashes = 0;

  if(s == NULL)
    return NULL;

  /* Count the number of backslashes to be escaped  */
  for(d = s; *d; d++) {
    switch(*d) {
      case '\t':
      case '\n':
      case '\\':
        backslashes++;
        break;
      default:
        break;
    }
  }

  if(backslashes == 0)
    return s;
  
  /*
   Determine new len, and allocate a buffer to accomodate it;
   reuse the existing buffer whenever sufficiently large
   */
  len = strlen(s) + backslashes;
  if(len > dstsize) {
    if(dst != NULL)
      free(dst);
    dst = (char *) malloc(len);
    dstsize = len;
  }

  for(d = dst; *s; s++) {
    switch(*s) {
      case '\t':
        *d++ = '\\';
        *d++ = 't';
        break;
      case '\n':
        *d++ = '\\';
        *d++ = 'n';
        break;
      case '\\':
        *d++ = '\\';
        *d++ = '\\';
        break;
      default:
        *d++ = *s;
        break;
    }
  }
  *d = '\0';
  return(dst);
}

static ATermList prodArgsToAsFix1(ATermList args)
{
  ATerm t, sort;
  ATermList res = ATempty;
  char *sepname, *litname;

  while (!ATisEmpty(args)) {
    t = ATgetFirst(args);
    args = ATgetNext(args);

    t = removeCfLexSymbol(t);
    if (ATmatchTerm(t, asfix2_opt_layout_pattern)) {
      t = pattern_asfix_ews;
    }
    else if (PT_isSymbolIterPlus(t)) {
      sort = PT_getIterPlusSymbol(t);
      if (PT_isSymbolSort(sort)) {
        t = ATmakeTerm(asfix1_iter_plus_pattern, sort);
      }
      ATerror("prodArgsToAsFix1: not a sort %t\n", sort);
    }
    else if (PT_isSymbolIterStar(t)) {
      sort = PT_getIterStarSymbol(t);
      if (PT_isSymbolSort(sort)) {
        t = ATmakeTerm(asfix1_iter_star_pattern,sort);
      }
      ATerror("prodArgsToAsFix1: not a sort %t\n", sort);
    }
    else if (PT_isSymbolIterPlusSep(t)) {
      sort = PT_getIterPlusSepSymbol(t);
      sepname = PT_getLitString(PT_getIterPlusSepSeparator(t));
      if (PT_isSymbolSort(sort)) {
        t = ATmakeTerm(asfix1_itersep_plus_pattern, sort, sepname);
      }
      ATerror("prodArgsToAsFix1: not a sort %t\n", sort);
    }
    else if (PT_isSymbolIterStarSep(t)) {
      sort = PT_getIterStarSepSymbol(t);
      sepname = PT_getLitString(PT_getIterStarSepSeparator(t));
      if (PT_isSymbolSort(sort)) {
        t = ATmakeTerm(asfix1_itersep_star_pattern,sort,sepname);
      }
      ATerror("prodArgsToAsFix1: not a sort %t\n", sort);
    }
    else if (PT_isSymbolLit(t)) {
      litname = PT_getLitString(t);
      t = ATmakeTerm(pattern_asfix_ql, escape_str(litname));
    }
    res = ATappend(res,t);
  }
  return res;
}

static ATerm cons_str(char *str)
{
  char *buf1, *buf2;
  ATerm cons;

  buf1  = escape_str(str);
  buf2 = malloc(strlen(buf1) + strlen("cons()") + 1);
  sprintf(buf2, "cons(%s)", buf1);
  cons = ATmakeTerm(pattern_asfix_ql, buf2);
  free(buf2);
  return cons;
}

static ATerm prodToAsFix1(ATerm t)
{
  ATerm         res, attr, result, id = NULL, res_attr = NULL;
  ATermList     attrs, args;
  char          *lit;

  if (!ATmatchTerm(t, asfix2_prod_pattern, &args, &res, &attr)) {
    ATerror("prodToAsFix1: not a production: %t\n", t);
  }

  /*
   We can  only have  one `atr'  attribute (left,  right, assoc, ...) in 
   asfix1.2, so we'll just take the first one of these.

   For  proper modularization  however,  `id(Name)' can  (must?)
   also appear  in attrs, and  must be handled properly.   So we
   iterate over all terms in  the `attrs' list, either selecting
   or discarding them.
   */

  if (ATmatchTerm(attr, asfix2_attrs_pattern, &attrs)) {
    while(!ATisEmpty(attrs)) {
      attr = ATgetFirst(attrs);
      attrs = ATgetNext(attrs);

      if (ATmatchTerm(attr, asfix2_cons_pattern, &lit)
         || ATmatchTerm(attr, asfix2_aterm_cons_pattern, &lit)) {
        ATerm cons = cons_str(lit);

        if(!res_attr) {
          res_attr = (ATerm)ATmakeList1(cons);
        }
        else {
          res_attr =
            (ATerm)ATconcat((ATermList)res_attr,
                            (ATermList)ATmake("[w(\"\"),sep(\",\"),w(\"\"),"
                                              "<term>]", cons));
        }
      }
      else if (ATmatchTerm(attr, asfix2_atr_pattern, &lit)) {
        /* a common attribute (left, right, ...) */
        if (!res_attr) {     /* first attr */
          res_attr = (ATerm)ATmakeList1(ATmake("l(<str>)",lit));
        } 
        else {            /* consecutive atts */
          res_attr =
            (ATerm)ATconcat((ATermList)res_attr,
                            (ATermList)ATmake("[w(\"\"),sep(\",\"),w(\"\"),"
                                              "l(<str>)]", lit));
        }
      }
      else if(ATmatchTerm(attr, asfix2_id_pattern, NULL)) {
        /* the ModuleName identifier */
        id = attr;
      }
      else if(ATmatchTerm(attr,ATparse("traverse"))) {
        if(!res_attr) { /* first attr */
           res_attr = (ATerm) ATmakeList1(ATmake("l(\"traverse\")"));
        } else {
           res_attr =
             (ATerm) ATconcat((ATermList) res_attr,
                              (ATermList) ATmake("[w(\"\"),sep(\",\"),w(\"\"),"
                                                 "l(\"traverse\")]", lit));
        }
      }
      else {
        /* unrecognized ATerm */
        ATerror("prodToAsFix1: strange attribute %t\n", attr);
      }
    }
  }
  else if (!ATmatch(attr, "no-attrs")) {
    ATerror("prodToAsFix1: strange attrs \"%t\"\n", attrs);
  }

  if (res_attr) {
    res_attr = ATmake("attrs(l(\"{\"),w(\"\"),<term>,w(\"\"),l(\"}\"))",
                      (ATerm)res_attr);
  }
  else {
    res_attr = ATparse("no-attrs");
  }

  if (!id) {
    ATwarning("prodToAsFix1: id(<ModuleName>) required in attrs list\n");
    id = ATparse("id(\"Unknown\")");
  }
  result = ATmake("prod(<term>,w(\"\"),<term>,w(\"\"),"
                  "l(\"->\"),w(\"\"),<term>,w(\"\"),<term>)",
                  id, prodArgsToAsFix1(args), removeCfLexSymbol(res), res_attr);

  return result;
}

static int lengthOfLexicals(ATermList lexicals)
{
  ATermList  args;
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
    /*else if (ATmatchTerm(lex, asfix2_appl_pattern, NULL, &args)) {*/
    else if (PT_isTreeAppl(lex)) {
      args = PT_getTreeArgs(lex);
      length = length + lengthOfLexicals(args);
    }
    else if (PT_isSymbolLit(lex)) {
      length = length + strlen(PT_getLitString(lex));
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
    /*else if (ATmatchTerm(lex, asfix2_appl_pattern, NULL, &args)) {*/
    else if (PT_isTreeAppl(lex)) {                                       
      args = PT_getTreeArgs(lex);
      idx = lexicalsToStringRecursive(args, idx, buf, bufSize);
    }
    else if (PT_isSymbolLit(lex)) {
      int i, len;
      lit = PT_getLitString(lex);
      len = strlen(lit);

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

static ATerm layoutToAsFix1(ATerm t)
{
  if (PT_isLayout(t)) {
    ATermList args = PT_getLayoutElems(t);
    ATerm lexTree = lexicalsToString(args);
    return ATmakeTerm(asfix1_ws_pattern, lexTree);
  }
  ATerror("layoutToAsFix1: not a layout pattern: %t\n", t);
  return NULL;
}

static ATerm parseTreeToAsFix1(ATerm t)
{
  ATerm  arg[3];
  ATermList args;

  /* Parse tree */
  if (PT_isParseTreeTree(t)) {
    t = PT_getParseTreeTree(t);

    if (ATmatchTerm(t, asfix2_START_pattern, NULL, &args)) {
      arg[0] = ATgetFirst(args);
      arg[1] = ATelementAt(args,1);
      arg[2] = ATelementAt(args,2);
      return ATmake("term(l(\"term\"),w(\" \"),l(\"X\"),w(\" \"),id(\"X\"),"
                    "<term>,<term>,<term>,no-abbreviations)",
                    layoutToAsFix1(arg[0]),
                    termToAsFix1(arg[1]), 
                    layoutToAsFix1(arg[2]));
    }
    /* Yawn -- not an interesting top-level case */
    else {
      return termToAsFix1(t);
    }
  }
  else {
    return termToAsFix1(t);
  }
}

static ATerm literalToAsFix1(ATerm t)
{
  if (PT_isSymbolLit(t)) {
    return  ATmakeTerm(pattern_asfix_l, PT_getLitString(t));
  }

  ATerror("literalToAsFix1: not a literal pattern: %t\n", t);
  return NULL;
}

static ATerm applicationToAsFix1(ATerm t)
{
  ATerm sort;
  char *sep, *lit;

  ATerm prod = PT_getTreeProd(t);
  ATermList args = PT_getTreeArgs(t);

  if (PT_prodHasLexAsLhs(prod)) {
    sort = PT_getCfSymbol(PT_getProductionRhs(prod));
    return ATmakeTerm(pattern_asfix_lexterm, lexicalsToString(args), sort);
  }

  if (PT_prodHasVarSymAsLhs(prod)) {
    ATerm varTerm = lexicalsToString(args);
    ATerm sort_or_iter = PT_getCfSymbol(PT_getProductionRhs(prod));

    if (PT_isSymbolIterPlus(sort_or_iter)) {
      sort = PT_getIterPlusSymbol(sort_or_iter);
      if (PT_isSymbolSort(sort)) {
        sort_or_iter = ATmakeTerm(asfix1_iter_plus_pattern,sort);
      }
      ATerror("applicationToAsFix1: not a sort %t\n", sort);
    }
    else if (PT_isSymbolIterStar(sort_or_iter)) {
      sort = PT_getIterStarSymbol(sort_or_iter);
      if (PT_isSymbolSort(sort)) {
        sort_or_iter = ATmakeTerm(asfix1_iter_star_pattern,sort);
      }
      ATerror("applicationToAsFix1: not a sort %t\n", sort);
    }
    else if (PT_isSymbolIterPlusSep(sort_or_iter)) {
      sort = PT_getIterPlusSepSymbol(sort_or_iter);
      sep = PT_getLitString(PT_getIterPlusSepSeparator(sort_or_iter));
      if (PT_isSymbolSort(sort)) {
        sort_or_iter = ATmakeTerm(asfix1_itersep_plus_pattern,sort,sep);
      }
      ATerror("applicationToAsFix1: not a sort %t\n", sort);
    }
    else if (PT_isSymbolIterStarSep(sort_or_iter)) {
      sort = PT_getIterStarSepSymbol(sort_or_iter);
      sep = PT_getLitString(PT_getIterStarSepSeparator(sort_or_iter));
      if (PT_isSymbolSort(sort)) {
        sort_or_iter = ATmakeTerm(asfix1_itersep_star_pattern,sort,sep);
      }
      ATerror("applicationToAsFix1: not a sort %t\n", sort);
    }

    return ATmakeTerm(pattern_asfix_varterm, varTerm, sort_or_iter);
  }

  /* Star list with separator */
  if (ATmatchTerm(t, asfix2_appl_starlist_sep_pattern,
                       NULL, &sort, &lit, NULL, &args)
           ||
           ATmatchTerm(t, asfix2_appl_pluslist_sep_pattern,
                       NULL, &sort, &lit, NULL, &args)) {
    ATerm itersep = ATmakeTerm(asfix1_itersep_pattern,sort, escape_str(lit));
    return  ATmakeTerm(pattern_asfix_list,
                       itersep, pattern_asfix_ews,
                       listToAsFix1(args));
  }

  /* Star list without separator */
  if (ATmatchTerm(t, asfix2_appl_starlist_pattern,
                       NULL, &sort, NULL, &args)
           ||
           ATmatchTerm(t, asfix2_appl_pluslist_pattern,
                       NULL, &sort, NULL, &args)) {
    ATerm iter = ATmakeTerm(asfix1_iter_pattern,sort);
    return  ATmakeTerm(pattern_asfix_list,
                       iter, pattern_asfix_ews,
                       listToAsFix1(args));
  }

  /* Default: application */
  return  ATmakeTerm(pattern_asfix_appl,
                     prodToAsFix1(prod),
                     pattern_asfix_ews, argsToAsFix1(args));
}

static ATerm termToAsFix1(ATerm t)
{
  ATermList args;

  if (PT_isTreeAmb(t)) {
    args = PT_getAmbArgs(t);
    return PT_makeTreeAmb(argsToAsFix1(args));
  }

  if (PT_isSymbolLit(t)) {
    return literalToAsFix1(t);
  }

  if (PT_isLayout(t)) {
    return layoutToAsFix1(t);
  }

  if (!PT_isTreeAppl(t)) {
    ATerror("termToAsFix1: not an application term: %t\n", t);
    return  NULL;
  }

  return applicationToAsFix1(t);
}

ATerm a2metoa1(ATerm t)
{
  init_patterns();
  return parseTreeToAsFix1(t);
}
