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

#include <MEPT-utils.h>
#include "conversion.h"

/* Function prototypes (only the badly needed ones) */

static ATerm termToAsFix1(PT_Tree, ATbool inList);
static ATerm iterToAsFix1(PT_Symbol sym, PT_Args args);
static ATerm iterSepToAsFix1(PT_Symbol sym, PT_Args args);

/*  patterns  */

/* Definition of AsFix2 patterns and their initialization */

static ATerm asfix2_attrs_pattern = NULL;
static ATerm asfix2_cons_pattern = NULL;
static ATerm asfix2_aterm_cons_pattern = NULL;
static ATerm asfix2_atr_pattern = NULL;
static ATerm asfix2_id_pattern = NULL;
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

static void
init_patterns(void)
{
  static ATbool patterns_initialized = ATfalse;

  if (patterns_initialized) {
    return;
  }
  patterns_initialized = ATtrue;

  init_asfix_patterns();
}

static void
init_asfix_patterns()
{
  ATprotect(&asfix2_attrs_pattern);
  ATprotect(&asfix2_cons_pattern);
  ATprotect(&asfix2_aterm_cons_pattern);
  ATprotect(&asfix2_atr_pattern);
  ATprotect(&asfix2_id_pattern);
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

  asfix2_attrs_pattern = ATparse("attrs([<list>])");
  asfix2_cons_pattern = ATparse("cons(<str>)");
  asfix2_aterm_cons_pattern = ATparse("aterm(cons(<str>))");
  asfix2_atr_pattern = ATparse("atr(<str>)");
  asfix2_id_pattern = ATparse("id(<str>)");
  asfix1_iter_star_pattern = ATparse("iter(<term>,w(\"\"),l(\"*\"))");
  asfix1_iter_plus_pattern = ATparse("iter(<term>,w(\"\"),l(\"+\"))");
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

static ATermList
argsToAsFix1(PT_Symbols symbols, PT_Args args)
{
  if (PT_isArgsEmpty(args)) {
    return ATempty;
  }
  else {
    PT_Symbol symbol = PT_getSymbolsHead(symbols);
    PT_Tree   arg    = PT_getArgsHead(args);

    if (PT_isIterSymbol(symbol) &&
        PT_isTreeList(arg)) {
      return ATinsert(argsToAsFix1(PT_getSymbolsTail(symbols),
                                   PT_getArgsTail(args)),
                      iterToAsFix1(PT_getSymbolSymbol(symbol), 
                                   PT_getTreeArgs(arg)));
    }
    else if (PT_isIterSepSymbol(symbol) &&
             PT_isTreeList(arg)) {
      return ATinsert(argsToAsFix1(PT_getSymbolsTail(symbols),
                                   PT_getArgsTail(args)),
                      iterSepToAsFix1(PT_getSymbolSymbol(symbol),
                                      PT_getTreeArgs(arg)));
    }
    else {
      return ATinsert(argsToAsFix1(PT_getSymbolsTail(symbols),
                                   PT_getArgsTail(args)),
		      termToAsFix1(arg, ATfalse));
    }
  }
}

static ATerm
separatorToAsFix1(PT_Tree t)
{
  char *lit = PT_getTreeString(t);

  return ATmakeTerm(asfix1_sep_pattern, lit);
}

static ATermList
listToAsFix1(PT_Args argList)
{
  ATerm newTerm;
  ATermList newList = ATempty;

  while (PT_hasArgsHead(argList)) {
    PT_Tree elem = PT_getArgsHead(argList);

    if (PT_isTreeLit(elem)) {
      newTerm = separatorToAsFix1(elem);
    }
    else {
      newTerm = termToAsFix1(elem, ATtrue);
    }
    newList = ATappend(newList, newTerm);

    argList = PT_getArgsTail(argList);
  }
  return newList;

}

static PT_Symbol
removeCfLexSymbol(PT_Symbol s)
{
  if (PT_isSymbolCf(s) || PT_isSymbolLex(s)) {
    return PT_getSymbolSymbol(s);
  }

  return s;
}

static char *
escape_str(char *s)
{
  static size_t dstsize = 0;
  static char *dst = NULL;
  char *d;
  size_t len, backslashes = 0;

  if (s == NULL)
    return NULL;

  /* Count the number of backslashes to be escaped  */
  for (d = s; *d; d++) {
    switch (*d) {
    case '\t':
    case '\n':
    case '\\':
      backslashes++;
      break;
    default:
      break;
    }
  }

  if (backslashes == 0)
    return s;

  /*
     Determine new len, and allocate a buffer to accomodate it;
     reuse the existing buffer whenever sufficiently large
   */
  len = strlen(s) + backslashes;
  if (len > dstsize) {
    if (dst != NULL)
      free(dst);
    dst = (char *) malloc(len);
    dstsize = len;
  }

  for (d = dst; *s; s++) {
    switch (*s) {
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
  return (dst);
}

static ATermList
prodArgsToAsFix1(PT_Symbols symbols)
{
  ATerm t = NULL;
  PT_Symbol sort, symbol;
  ATermList res = ATempty;
  char *sep, *lit;

  while (PT_hasSymbolsHead(symbols)) {
    symbol = PT_getSymbolsHead(symbols);
    symbols = PT_getSymbolsTail(symbols);

    symbol = removeCfLexSymbol(symbol);

    if (PT_isSymbolOpt(symbol)) {
      PT_Symbol optsym = PT_getSymbolSymbol(symbol);
      if (PT_isSymbolLayout(optsym)) {
	t = pattern_asfix_ews;
      }
      else {
	ATerror("prodArgsToAsFix1: not an optional layout symbol %t\n",
		symbol);
      }
    }
    else if (PT_isSymbolIterPlus(symbol)) {
      sort = PT_getSymbolSymbol(symbol);
      if (PT_isSymbolSort(sort)) {
	t = ATmakeTerm(asfix1_iter_plus_pattern, sort);
      }
      else {
	ATerror("prodArgsToAsFix1: not a sort %t\n", sort);
      }
    }
    else if (PT_isSymbolIterStar(symbol)) {
      sort = PT_getSymbolSymbol(symbol);
      if (PT_isSymbolSort(sort)) {
	t = ATmakeTerm(asfix1_iter_star_pattern, sort);
      }
      else {
	ATerror("prodArgsToAsFix1: not a sort %t\n", sort);
      }
    }
    else if (PT_isSymbolIterPlusSep(symbol)) {
      sort = PT_getSymbolSymbol(symbol);
      sep = PT_getSymbolString(PT_getSymbolSeparator(symbol));

      if (PT_isSymbolSort(sort)) {
	t = ATmakeTerm(asfix1_itersep_plus_pattern, sort, sep);
      }
      else {
	ATerror("prodArgsToAsFix1: not a sort %t\n", sort);
      }
    }
    else if (PT_isSymbolIterStarSep(symbol)) {
      sort = PT_getSymbolSymbol(symbol);
      sep = PT_getSymbolString(PT_getSymbolSeparator(symbol));

      if (PT_isSymbolSort(sort)) {
	t = ATmakeTerm(asfix1_itersep_star_pattern, sort, sep);
      }
      else {
	ATerror("prodArgsToAsFix1: not a sort %t\n", sort);
      }
    }
    else if (PT_isSymbolLit(symbol)) {
      lit = PT_getSymbolString(symbol);
      t = ATmakeTerm(pattern_asfix_ql, escape_str(lit));
    }
    else {
      t = PT_makeTermFromSymbol(symbol);
    }

    res = ATappend(res, t);
  }

  return res;
}

static ATerm
cons_str(char *str)
{
  char *buf1, *buf2;
  ATerm cons;

  buf1 = escape_str(str);
  buf2 = malloc(strlen(buf1) + strlen("cons()") + 1);
  sprintf(buf2, "cons(%s)", buf1);
  cons = ATmakeTerm(pattern_asfix_ql, buf2);
  free(buf2);
  return cons;
}

static ATerm
prodToAsFix1(PT_Production prod)
{
  ATerm attr, result, id = NULL, res_attr = NULL;
  PT_Symbol rhs;
  PT_Symbols lhsArgs;
  PT_Attributes prodAttrs;
  ATermList attrs;
  char *lit;

  if (!PT_isProductionDefault(prod)) {
    ATerror("prodToAsFix1: not a production: %t\n", prod);
  }
  lhsArgs = PT_getProductionLhs(prod);
  rhs = PT_getProductionRhs(prod);
  prodAttrs = PT_getProductionAttributes(prod);

  /*
     We can  only have  one `atr'  attribute (left,  right, assoc, ...) in 
     asfix1.2, so we'll just take the first one of these.

     For  proper modularization  however,  `id(Name)' can  (must?)
     also appear  in attrs, and  must be handled properly.   So we
     iterate over all terms in  the `attrs' list, either selecting
     or discarding them.
   */

  if (ATmatchTerm((ATerm) prodAttrs, asfix2_attrs_pattern, &attrs)) {
    while (!ATisEmpty(attrs)) {
      attr = ATgetFirst(attrs);
      attrs = ATgetNext(attrs);

      if (ATmatchTerm(attr, asfix2_cons_pattern, &lit)
	  || ATmatchTerm(attr, asfix2_aterm_cons_pattern, &lit)) {
	ATerm cons = cons_str(lit);

	if (!res_attr) {
	  res_attr = (ATerm) ATmakeList1(cons);
	}
	else {
	  res_attr =
	    (ATerm) ATconcat((ATermList) res_attr,
			     (ATermList) ATmake("[w(\"\"),sep(\",\"),w(\"\"),"
						"<term>]", cons));
	}
      }
      else if (ATmatchTerm(attr, asfix2_atr_pattern, &lit)) {
	/* a common attribute (left, right, ...) */
	if (!res_attr) {	/* first attr */
	  res_attr = (ATerm) ATmakeList1(ATmake("l(<str>)", lit));
	}
	else {			/* consecutive atts */
	  res_attr =
	    (ATerm) ATconcat((ATermList) res_attr,
			     (ATermList) ATmake("[w(\"\"),sep(\",\"),w(\"\"),"
						"l(<str>)]", lit));
	}
      }
      else if (ATmatchTerm(attr, asfix2_id_pattern, NULL)) {
	/* the ModuleName identifier */
	id = attr;
      }
      else if (ATmatchTerm(attr, ATparse("traverse"))) {
	if (!res_attr) {	/* first attr */
	  res_attr = (ATerm) ATmakeList1(ATmake("l(\"traverse\")"));
	}
	else {
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
  else if (!ATmatch((ATerm) prodAttrs, "no-attrs")) {
    ATerror("prodToAsFix1: strange attrs \"%t\"\n", attrs);
  }

  if (res_attr) {
    res_attr = ATmake("attrs(l(\"{\"),w(\"\"),<term>,w(\"\"),l(\"}\"))",
		      (ATerm) res_attr);
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
		  id, prodArgsToAsFix1(lhsArgs),
		  removeCfLexSymbol(rhs), res_attr);

  return result;
}

static ATerm
treeToString(PT_Tree tree)
{
  return ATmake("<str>", PT_yieldTree(tree));
}

static ATerm
layoutToAsFix1(PT_Tree tree)
{
  ATerm lexTree = treeToString(tree);

  return ATmakeTerm(asfix1_ws_pattern, lexTree);
}

static ATerm
parseTreeToAsFix1(PT_ParseTree pt)
{
  PT_Tree layoutBeforeTree, applTree, layoutAfterTree;

  /* Parse tree */
  if (PT_isParseTreeTree(pt)) {
    layoutBeforeTree = PT_getParseTreeLayoutBeforeTree(pt);
    applTree         = PT_getParseTreeTree(pt);
    layoutAfterTree  = PT_getParseTreeLayoutAfterTree(pt);

    return ATmake("term(l(\"term\"),w(\"\"),l(\"X\"),w(\"\"),id(\"X\"),"
		  "<term>,<term>,<term>,no-abbreviations)",
		  layoutToAsFix1(layoutBeforeTree),
		  termToAsFix1(applTree, ATfalse),
                  layoutToAsFix1(layoutAfterTree));
  }
  else {
    ATerror("parseTreeToAsFix1: expected parse tree, got %t\n", pt);
    return NULL;
  }
}

static ATerm
literalToAsFix1(PT_Tree t)
{
  return ATmakeTerm(pattern_asfix_l, PT_getTreeString(t));
}

static ATerm
varSymbolToAsFix1(PT_Tree tree, ATbool inList)
{
  PT_Symbol     sort;
  char         *sep;
  PT_Production prod = PT_getTreeProd(tree);
  ATerm         newSortOrIter = NULL;
  ATerm         varTerm = treeToString(tree);
  ATerm         newVarTerm;
  PT_Symbol     sortOrIter = PT_getSymbolSymbol(PT_getProductionRhs(prod));

  if (PT_isSymbolIterPlus(sortOrIter)) {
    sort = PT_getSymbolSymbol(sortOrIter);

    if (PT_isSymbolSort(sort)) {
      newSortOrIter = ATmakeTerm(asfix1_iter_plus_pattern, sort);
    }
    else {
      ATerror("varSymbolToAsFix1: not a sort %t\n", sort);
    }
    newVarTerm = ATmakeTerm(pattern_asfix_varterm, varTerm, newSortOrIter);
    if (inList) {
      return newVarTerm;
    }
    else {
      return ATmakeTerm(pattern_asfix_list, 
                        newSortOrIter, pattern_asfix_ews,
                        ATmakeList1(newVarTerm));
    }
  }
  else if (PT_isSymbolIterStar(sortOrIter)) {
    sort = PT_getSymbolSymbol(sortOrIter);

    if (PT_isSymbolSort(sort)) {
      newSortOrIter = ATmakeTerm(asfix1_iter_star_pattern, sort);
    }
    else {
      ATerror("varSymbolToAsFix1: not a sort %t\n", sort);
    }
    newVarTerm = ATmakeTerm(pattern_asfix_varterm, varTerm, newSortOrIter);
    if (inList) {
      return newVarTerm;
    }
    else {
      return ATmakeTerm(pattern_asfix_list, 
                        newSortOrIter, pattern_asfix_ews,
                        ATmakeList1(newVarTerm));
    }
  }
  else if (PT_isSymbolIterPlusSep(sortOrIter)) {
    sort = PT_getSymbolSymbol(sortOrIter);
    sep = PT_getSymbolString(PT_getSymbolSeparator(sortOrIter));

    if (PT_isSymbolSort(sort)) {
      newSortOrIter = ATmakeTerm(asfix1_itersep_plus_pattern, sort, sep);
    }
    else {
      ATerror("varSymbolToAsFix1: not a sort %t\n", sort);
    }
    newVarTerm = ATmakeTerm(pattern_asfix_varterm, varTerm, newSortOrIter);
    if (inList) {
      return newVarTerm;
    }
    else {
      return ATmakeTerm(pattern_asfix_list, 
                        newSortOrIter, pattern_asfix_ews,
                        ATmakeList1(newVarTerm));
    }
  }
  else if (PT_isSymbolIterStarSep(sortOrIter)) {
    sort = PT_getSymbolSymbol(sortOrIter);
    sep = PT_getSymbolString(PT_getSymbolSeparator(sortOrIter));

    if (PT_isSymbolSort(sort)) {
      newSortOrIter = ATmakeTerm(asfix1_itersep_star_pattern, sort, sep);
    }
    else {
      ATerror("varSymbolToAsFix1: not a sort %t\n", sort);
    }
    newVarTerm = ATmakeTerm(pattern_asfix_varterm, varTerm, newSortOrIter);
    if (inList) {
      return newVarTerm;
    }
    else {
      return ATmakeTerm(pattern_asfix_list, 
                        newSortOrIter, pattern_asfix_ews,
                        ATmakeList1(newVarTerm));
    }
  }
  else {
    newSortOrIter = PT_makeTermFromSymbol(sortOrIter);
    return ATmakeTerm(pattern_asfix_varterm, varTerm, newSortOrIter);
  }
}

static ATerm
iterSepToAsFix1(PT_Symbol iter, PT_Args args)
{
  PT_Symbol sort = PT_getSymbolSymbol(iter);
  char *sep = PT_getSymbolString(PT_getSymbolSeparator(iter));

  ATerm newIterSep = ATmakeTerm(asfix1_itersep_star_pattern, sort,
				escape_str(sep));

  return ATmakeTerm(pattern_asfix_list,
		    newIterSep, pattern_asfix_ews, listToAsFix1(args));
}

static ATerm
iterToAsFix1(PT_Symbol iter, PT_Args args)
{
  PT_Symbol sort = PT_getSymbolSymbol(iter);

  ATerm newIter = ATmakeTerm(asfix1_iter_star_pattern,
			     PT_makeTermFromSymbol(sort));

  return ATmakeTerm(pattern_asfix_list,
		    newIter, pattern_asfix_ews, listToAsFix1(args));
}

static ATerm
applicationToAsFix1(PT_Tree tree, ATbool inList)
{
  PT_Production prod = PT_getTreeProd(tree);
  PT_Args args = PT_getTreeArgs(tree);

  if (PT_isOptLayoutProd(prod)) {
    return layoutToAsFix1(tree);
  }

  if (PT_prodHasLexAsLhsAndCfAsRhs(prod)) {
    PT_Symbol sort = PT_getSymbolSymbol(PT_getProductionRhs(prod));
    return ATmakeTerm(pattern_asfix_lexterm,
		      treeToString(tree), PT_makeTermFromSymbol(sort));
  }

  if (PT_isVarDefault(prod)) {
    return varSymbolToAsFix1(tree, inList);
  }

  return ATmakeTerm(pattern_asfix_appl,
		    prodToAsFix1(prod),
		    pattern_asfix_ews, argsToAsFix1(PT_getProductionLhs(prod),
                                                    args));
}

static ATerm
termToAsFix1(PT_Tree tree, ATbool inList)
{
  if (PT_isTreeAmb(tree)) {
    ATerror("termToAsFix1: ambiguities can not be converted to AsFix1: %t\n",
	    tree);
    return NULL;
  }

  if (PT_isTreeLit(tree)) {
    return literalToAsFix1(tree);
  }

  if (!PT_isTreeAppl(tree)) {
    ATerror("termToAsFix1: not an application term: %t\n", tree);
    return NULL;
  }

  return applicationToAsFix1(tree, inList);
}

static ATerm
treeToAsFix1(PT_Tree tree)
{
  return termToAsFix1(tree, ATfalse);
}

ATerm
a2metoa1(PT_ParseTree ptree)
{
  init_patterns();
  return parseTreeToAsFix1(ptree);
}

ATerm
tree2a1(PT_Tree tree)
{
  init_patterns();
  return treeToAsFix1(tree);
}
