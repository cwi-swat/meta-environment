/*

    AsFix -- The AsFix (ASF+SDF Prefix) library
    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
                             The  Netherlands.

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

/*{{{  includes */

#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>

#include "AsFix.h"
#include "AsFix-abbrevs.h"
#include "AsFix-access.h"
#include "aterm2.h"
#include "deprecated.h"

/*}}}  */
/*{{{  external patterns */

extern ATerm pattern_asfix_sep;
extern ATerm pattern_asfix_appl;
extern ATerm pattern_asfix_var;
extern ATerm pattern_asfix_list;
extern ATerm pattern_asfix_lex;
extern ATerm pattern_asfix_l;
extern ATerm pattern_asfix_ql;
extern ATerm pattern_asfix_condition;
extern ATerm pattern_asfix_ceqequ;
extern ATerm pattern_asfix_ceqimpl;
extern ATerm pattern_asfix_ceqwhen;
extern ATerm pattern_asfix_equations;
extern ATerm pattern_asfix_noequations;
extern ATerm pattern_asfix_module;
extern ATerm pattern_asfix_term;

extern AFun symbol_w;

/*}}}  */

/*{{{  ATermList AFTgetEqs(ATerm mod) */

/**
 * Get the equation section of a module
 **/

ATermList AFTgetEqs(ATerm mod)
{
  ATerm lit[2], w[4], id, section, list, abbrevs;
  ATermList eqs = ATempty; 

  if(ATisEqual(mod,ATparse("unavailable")) |
     ATisEqual(mod,ATparse("error")) |
     ATisEqual(mod,ATparse("no-equations")))
    return eqs;

  if(ATmatchTerm(mod, pattern_asfix_term, &lit[0], &w[0], &lit[1],
                 &w[1], &id, &w[2], &section, &w[3], &abbrevs)) {

    if(AFTisEmptyEquSection(section))
      return eqs;

    if(!AFTisEquSection(section))
      ATerror("expected equ-section, got %t\n", section); 
 
    list = AFTgetEquSectionEqList(section); 

    if(!AFTisList(list))
      ATerror("not a list: %t\n", list); 

    eqs = AFTgetListElements(list); 

    return eqs;
    
  }
  else {
    ATerror("This is the asfix I know of: %t\n", mod);
    return ATempty;
  }
}

/*}}}  */
/*{{{  ATbool AFTisDefaultTag(ATerm tag) */

/**
	* Check if a tag indicates a default equation.
	*/

ATbool AFTisDefaultTag(ATerm tag)
{
	ATerm lex, name;

	if(!AFTcheckAppl(tag, af_prod_tag)) 
		ATerror("not a tag: %t\n", tag);

	lex = AFgetApplArg(tag, 2);
	name = ATgetArgument(lex, 0);

	if(strncmp(ATgetName(ATgetAFun(name)), "default-", 8) == 0)
		return ATtrue;
	else
		return ATfalse;
}

/*}}}  */
/*{{{  ATerm AFTgetEquLhs(ATerm equation) */

/**
  * Get the left hand side of an equation, independent of its type.
  */

ATerm AFTgetEquLhs(ATerm equation)
{
  ATerm equ, lhs = NULL;

  if(AFTisSimpleCondEqu(equation)) { 
    equ = AFTgetSimpleCondEquEqu(equation);

    lhs = AFTgetSimpleEquLHS(equ); 
  }
  else if(AFTisImpliesCondEqu(equation)) { 
    equ = AFTgetImpliesCondEquEqu(equation); 

    lhs = AFTgetSimpleEquLHS(equ); 
  }
  else if(AFTisWhenCondEqu(equation)) { 
    equ = AFTgetWhenCondEquEqu(equation); 

    lhs = AFTgetSimpleEquLHS(equ);
  }
  else
    ATerror("Strange equation %t\n",equation);

  return lhs;
}

/*}}}  */
/*{{{  ATermList AFTgetSections(ATerm mod) */

/**
 * Get the sections of a module
 **/

ATermList AFTgetSections(ATerm mod)
{
  ATerm lit[2], w[4], id, module, abbrevs, sections, list;
  ATermList sectionlist;

  if(ATmatchTerm(mod, pattern_asfix_term, &lit[0], &w[0], &lit[1],
                 &w[1], &id, &w[2], &module, &w[3], &abbrevs)) {

    if(!AFTisModule(module))
      ATerror("expected module, got %t\n", module);

    sections = AFTgetModuleSections(module);

    if(!AFTisSections(sections))
      ATerror("expected sections, got %t\n", sections);

    list = AFTgetSectionsList(sections); 

    if(!AFTisList(list))
      ATerror("not a list: %t\n", list); 

    sectionlist = AFTgetListElements(list); 

    return sectionlist;

  }
  else {
    ATerror("In AFTgetSorts: this is the asfix I know of: %t\n", mod);
    return ATempty;
  }
}

/*}}}  */
/*{{{  ATermList AFTmakeGrammarList(ATerm grammar) */

/**
 * Transform the "binary" grammar section into an ATermList.
 **/

ATermList AFTmakeGrammarList(ATerm grammar)
{
  ATermList list1, list2;

  if(AFTisGrammars(grammar)) {
    list1 = AFTmakeGrammarList(AFTgetGrammarSection1(grammar));
    list2 = AFTmakeGrammarList(AFTgetGrammarSection2(grammar));
    return ATconcat(list1,list2);
  }
  else {
    return ATmakeList1(grammar);
  }
}

/*}}}  */
/*{{{  ATermList AFTgetGrammarList(ATerm mod) */

/**
 * Get the list of grammars defined in a module.
 **/

ATermList AFTgetGrammarList(ATerm mod)
{
  ATerm section, grammars;
  ATermList sectionlist;
  ATermList grammarlist = ATempty; 
 
  sectionlist = AFTgetSections(mod);  

  while(!ATisEmpty(sectionlist)) {
    section = ATgetFirst(sectionlist); 
    sectionlist = ATgetNext(sectionlist);
    if(!AFTisWS(section)) {
      if(AFTisExportsSection(section)) {
        grammars = AFTgetSectionGrammar(section); 
        grammarlist = ATconcat(grammarlist,AFTmakeGrammarList(grammars));
      }
      else if(AFTisHiddensSection(section)) {
        grammars = AFTgetSectionGrammar(section); 
        grammarlist = ATconcat(grammarlist,AFTmakeGrammarList(grammars));
      }
      else { 
        ATerror("expected export or hidden section, got %t\n", section); 
      }  
    }
  }

  return grammarlist;
}

/*}}}  */
/*{{{  ATermList AFTgetSorts(ATerm mod) */

/**
 * Get the sorts of a module.
 **/

ATermList AFTgetSorts(ATerm mod)
{
  ATerm grammar, symbols, symbollist;
  ATermList grammarlist;
  ATermList sorts = ATempty;
 
  grammarlist = AFTgetGrammarList(mod);  

  while(!ATisEmpty(grammarlist)) {
    grammar = ATgetFirst(grammarlist);
    grammarlist = ATgetNext(grammarlist);
    if(AFTisSortsGrammar(grammar)) {
      symbols = AFTgetSortsSymbols(grammar);

      if(!AFTisSymbols(symbols))
        ATerror("expected symbols, got %t\n", symbols);

      symbollist = AFTgetSymbolsList(symbols);

      if(!AFTisList(symbollist))
        ATerror("not a list: %t\n", symbollist);
          
      sorts = ATconcat(sorts,AFTgetListElements(symbollist));
    } 
  }

  return sorts;
}

/*}}}  */
/*{{{  ATermList AFTgetLexFunctions(ATerm mod) */

/**
 * Get the lexical functions of a module
 **/

ATermList AFTgetLexFunctions(ATerm mod)
{
  ATerm grammar, prods, prodlist;
  ATermList grammarlist;
  ATermList lexfuncs = ATempty;
 
  grammarlist = AFTgetGrammarList(mod);  

  while(!ATisEmpty(grammarlist)) {
    grammar = ATgetFirst(grammarlist);
    grammarlist = ATgetNext(grammarlist);
    if(AFTisLexicalFuncsGrammar(grammar)) {
      prods = AFTgetLexicalFuncsProds(grammar);
  
    if(!AFTisProds(prods))
        ATerror("expected prods, got %t\n", prods);

    prodlist = AFTgetProdsList(prods);

    if(!AFTisList(prodlist))
        ATerror("not a list: %t\n", prodlist);
          
      lexfuncs = ATconcat(lexfuncs,AFTgetListElements(prodlist));
          
    }
  }
  return lexfuncs;
}

/*}}}  */
/*{{{  ATermList AFTgetLexFunctions(ATerm mod) */

/**
 * Get the context-free functions of a module
 **/

ATermList AFTgetCFFunctions(ATerm mod)
{
  ATerm grammar, prods, prodlist;
  ATermList grammarlist;
  ATermList cffuncs = ATempty;
 
  grammarlist = AFTgetGrammarList(mod);  

  while(!ATisEmpty(grammarlist)) {
    grammar = ATgetFirst(grammarlist);
    grammarlist = ATgetNext(grammarlist);
    if(AFTisContextFreeFuncsGrammar(grammar)) {
      prods = AFTgetContextFreeFuncsProds(grammar);
  
    if(!AFTisProds(prods))
        ATerror("expected prods, got %t\n", prods);

    prodlist = AFTgetProdsList(prods);

    if(!AFTisList(prodlist))
        ATerror("not a list: %t\n", prodlist);
          
      cffuncs = ATconcat(cffuncs,AFTgetListElements(prodlist));
          
    }
  }
  return cffuncs;
}

/*}}}  */
/*{{{  ATerm AFTgetProdRhs(ATerm prod) */

/**
 * Get the right hand side of a production rule.
 **/

ATerm AFTgetProdRhs(ATerm prod)
{
  ATerm sort = NULL;

  if(AFTisProd(prod)) {
    sort = AFTgetProdSymbol(prod); 
  }
  else
    ATerror("expected prod, got %t\n", prod);

  return sort;
}

/*}}}  */
/*{{{  ATermList AFTgetImports(ATerm mod) */

/**
 * Get the imports of a module. 
 **/

ATermList AFTgetImports(ATerm mod)
{
  ATerm lit[2], w[4], id, module, importslist, abbrevs;
  ATermList imports;

  if(ATmatchTerm(mod, pattern_asfix_term, &lit[0], &w[0], &lit[1],
                 &w[1], &id, &w[2], &module, &w[3], &abbrevs)) {
    if(!AFTisModule(module))
      ATerror("expected module, got %t\n", module);
    importslist = AFTgetModuleImportList(module);
    if(!AFTisList(importslist))
      ATerror("not a list: %t\n", importslist);

    imports = AFTgetListElements(importslist);
    return imports;
  }
  else {
    ATerror("In AFTgetImports: this is the asfix I know of: %t\n", mod);
    return ATempty;
  }
}
/*}}}  */
/*{{{  ATerm AFTflattenSdf2Sort(ATerm sort) */

/**
 * Converts a sort.
 **/
ATerm AFTflattenSdf2Sort(ATerm sort)
{
  char *str;
  ATerm newsort = NULL;

  if(ATmatchTerm(sort,pattern_asfix_lex, &str, NULL)) { 
    newsort = ATmakeTerm(pattern_asfix_sort,str);
  }
  return newsort;
}

/*}}}  */
/*{{{  ATerm AFTflattenSdf2Attr(ATerm attr) */

/** 
 * Convert one attribute.
 **/
ATerm AFTflattenSdf2Attr(ATerm attr)
{
  ATerm assocattr, newattr = NULL;

  if(AFTisAssocAttr(attr)) {
    assocattr = AFTgetAssocAttr(attr);
    if(AFTisLeftAssoc(assocattr) ||
       AFTisRightAssoc(assocattr) ||
       AFTisAssocAssoc(assocattr) ||
       AFTisNonAssocAssoc(assocattr)) {
      newattr = AFTgetArgAssoc(assocattr);
    }
  }
  else if(AFTisBracketAssoc(attr) ||
          AFTisConstructorAssoc(attr) ||
          AFTisMemoAssoc(attr) ||
          AFTisRejectAttr(attr) ||
          AFTisPreferAttr(attr) ||
          AFTisUneagerAttr(attr)) {
    newattr = AFTgetArgAssoc(attr);
  }
  else 
    ATerror("expected attribute, got %t\n", attr); 
  return newattr;
}

/*}}} */
/*{{{  ATerm AFTflattenSdf2Attrs(ATerm attrs) */

/**
 * Converts the attributes.
 **/
ATerm AFTflattenSdf2Attrs(ATerm attrs)
{
  ATerm attrlist, attr, newattr, resultattr;
  ATermList attrelems, newattrlist = ATempty;

  if(AFTisEmptyAttrs(attrs))
    return ATparse("no-attrs");
  else if(AFTisAttrs(attrs)) {
    attrlist = AFTgetAttrsList(attrs);

    if(!AFTisList(attrlist))
      ATerror("not a list: %t\n", attrlist);

    attrelems = AFTgetListElements(attrlist);

    while(!ATisEmpty(attrelems)) {
      attr = ATgetFirst(attrelems);
      attrelems = ATgetNext(attrelems);
      if(!AFTisWS(attr) && !AFTisSep(attr)) {
        newattr = AFTflattenSdf2Attr(attr);
        if(!ATisEmpty(newattrlist)) {
          newattrlist = ATappend(newattrlist,ATparse("w(\"\")"));
          newattrlist = ATappend(newattrlist,ATparse("sep(\",\")"));
          newattrlist = ATappend(newattrlist,ATparse("w(\"\")"));
        }
        newattrlist = ATappend(newattrlist,newattr);
      }
    }
    resultattr = ATmake("attrs(l(\"{\"),w(\"\"),<term>,w(\"\"),l(\"}\"))",
                        (ATerm) newattrlist);
    return (ATerm) resultattr;
  }
  else 
    ATerror("expected attributes, got %t\n", attrs);
    return NULL;
}

/*}}}  */
/*{{{  ATerm AFTflattenSdf2Literal(ATerm literal) */

/**
 * Converts a literal.
 **/

char *unquote_str(char *s)
{
  int len = strlen(s);
  char *rs = (char *)malloc(len);

  if(s[0] == '\"' && s[len-1] == '\"') {
    if(!strncpy(rs,++s,len-2))
      ATerror("Run out of memory!\n");
    rs[len-2] = '\0';
    return rs;
  }
  return s;
}

ATerm AFTflattenSdf2Literal(ATerm literal)
{
  char *str;
  ATerm uqliteral, sort;
  ATerm newliteral = NULL;

  if(AFTisUQLiteralSymbol(literal)) {
    uqliteral = AFTgetUQLiteralLiteral(literal);
    if(ATmatchTerm(uqliteral,pattern_asfix_lex, &str, &sort)) {
      if(ATisEqual(sort,ATparse("sort(\"Literal\")"))) 
        newliteral = ATmakeTerm(pattern_asfix_ql,unquote_str(str)); 
      else
        newliteral = ATmakeTerm(pattern_asfix_ql,unquote_str(str));
    }
  }
  else if(ATmatchTerm(literal,pattern_asfix_lex, &str, &sort)) {
    if(ATisEqual(sort,ATparse("sort(\"Literal\")"))) 
      newliteral = ATmakeTerm(pattern_asfix_ql,unquote_str(str)); 
    else
      newliteral = ATmakeTerm(pattern_asfix_ql,unquote_str(str));
  }
  else
    ATerror("expected literal, got %t\n", literal);
  return newliteral;
}

/*}}}  */
/*{{{  ATerm AFTflattenSdf2Symbol(ATerm symbol) */

/**
 * Converts a single symbol.
 **/
ATerm AFTflattenSdf2Symbol(ATerm symbol)
{
  ATerm sort, literal, newsort, newliteral, newsymbol = NULL;

  if(AFTisSortSymbol(symbol)) {
    sort = AFTgetSortSymbol(symbol);
    newsymbol = AFTflattenSdf2Sort(sort);
  }
  else if(AFTisLiteralSymbol(symbol)) {
    literal = AFTgetLiteralSymbol(symbol);
    newsymbol = AFTflattenSdf2Literal(literal);
  }
  else if(AFTisStarListSymbol(symbol)) { 
    sort = AFTgetStarListSort(symbol); 
    newsort = AFTflattenSdf2Symbol(sort); 
    newsymbol = ATmakeTerm(pattern_asfix_iter_star,newsort);
  }
  else if(AFTisPlusListSymbol(symbol)) {
    sort = AFTgetPlusListSort(symbol); 
    newsort = AFTflattenSdf2Symbol(sort); 
    newsymbol = ATmakeTerm(pattern_asfix_iter_plus,newsort);
  }
  else if(AFTisStarSepListSymbol(symbol)) {
    sort = AFTgetStarSepListSort(symbol);
    literal = AFTgetStarSepListSep(symbol);
    newsort = AFTflattenSdf2Symbol(sort);
    newliteral = AFTflattenSdf2Symbol(literal);
    newsymbol = ATmakeTerm(pattern_asfix_itersep_star,newsort,newliteral);
  }
  else if(AFTisPlusSepListSymbol(symbol)) {
    sort = AFTgetPlusSepListSort(symbol);
    literal = AFTgetPlusSepListSep(symbol);
    newsort = AFTflattenSdf2Symbol(sort);
    newliteral = AFTflattenSdf2Symbol(literal);
    newsymbol = ATmakeTerm(pattern_asfix_itersep_plus,newsort,newliteral);
  }
  else
    ATerror("expected symbol, got %t\n", symbol);

  return newsymbol;
}

/*}}}  */
/*{{{  ATerm AFTflattenSdf2Symbollist(ATerm symbollist) */

/**
 * Converts a list of symbols.
 **/
ATermList AFTflattenSdf2Symbollist(ATerm symbollist)
{
  ATerm symbol, newsymbol;
  ATermList symbolelems, newsymbollist = ATempty;

  if(!AFTisList(symbollist))
    ATerror("not a list: %t\n", symbollist);

  symbolelems = AFTgetListElements(symbollist);

  while(!ATisEmpty(symbolelems)) {
    symbol = ATgetFirst(symbolelems);
    symbolelems = ATgetNext(symbolelems);
    if(!AFTisWS(symbol) && !AFTisSep(symbol)) {
      newsymbol = AFTflattenSdf2Symbol(symbol);
      if(!ATisEmpty(newsymbollist)) {
        newsymbollist = ATappend(newsymbollist,ATparse("w(\"\")"));
        newsymbollist = ATappend(newsymbollist,ATparse("ql(\",\")"));
        newsymbollist = ATappend(newsymbollist,ATparse("w(\"\")"));
      }
      newsymbollist = ATappend(newsymbollist,newsymbol);
    }
  }
  return newsymbollist;
}

/*}}}  */
/*{{{  ATerm AFTflattenSdf2Symbols(ATerm symbols) */

/**
 * Converts a list of symbols.
 **/
ATermList AFTflattenSdf2Symbols(ATerm symbols)
{
  ATerm symbollist, symbol, newsymbol;
  ATermList symbolelems, newsymbollist = ATempty;

  if(!AFTisSymbols(symbols))
    ATerror("expected symbols, got %t\n", symbols);

  symbollist = AFTgetSymbolsList(symbols);

  if(!AFTisList(symbollist))
    ATerror("not a list: %t\n", symbollist);

  symbolelems = AFTgetListElements(symbollist);

  while(!ATisEmpty(symbolelems)) {
    symbol = ATgetFirst(symbolelems);
    symbolelems = ATgetNext(symbolelems);
    if(!AFTisWS(symbol)) {
      newsymbol = AFTflattenSdf2Symbol(symbol);
      if(!ATisEmpty(newsymbollist))
        newsymbollist = ATappend(newsymbollist,ATparse("w(\"\")"));
      newsymbollist = ATappend(newsymbollist,newsymbol);
    }
  }
  return newsymbollist;
}

/*}}}  */
/*{{{  ATerm AFTflattenSdf2Prod(ATerm modname, ATerm prod) */

/**
 * Converts the term representation of a production into the production rule
 * itself.
 **/

ATerm AFTflattenSdf2Prod(ATerm modname, ATerm prod)
{
  ATerm symbols = NULL, symbol, newsymbol = NULL, attrs, newattrs = NULL, 
        literal, newliteral, newprod;
  ATermList newsymbollist = ATempty;

  if(AFTisProd(prod)) {
    symbols = AFTgetProdSymbols(prod); 
    symbol = AFTgetProdSymbol(prod); 
    attrs = AFTgetProdAttrs(prod);
  
    newsymbollist = AFTflattenSdf2Symbols(symbols); 
    newsymbol = AFTflattenSdf2Symbol(symbol); 
    newattrs = AFTflattenSdf2Attrs(attrs); 
 
    return ATmake("prod(<term>,w(\"\"),[<list>],w(\"\"),"
                  "l(\"->\"),w(\"\"),<term>,w(\"\"),<term>)",
                  modname, newsymbollist, newsymbol, newattrs);
  }
  else if(AFTisPrefixProd(prod)) {
    literal = AFTgetPrefixProdLiteral(prod); 
    symbols = AFTgetPrefixProdSymbols(prod); 
    symbol = AFTgetPrefixProdSymbol(prod); 
    attrs = AFTgetPrefixProdAttrs(prod);
  
    newliteral = AFTflattenSdf2Literal(literal); 
    newsymbollist = AFTflattenSdf2Symbollist(symbols);
    newsymbol = AFTflattenSdf2Symbol(symbol); 
    newattrs = AFTflattenSdf2Attrs(attrs); 

    newsymbollist = ATappend(newsymbollist, ATmake("w(\"\")"));
    newsymbollist = ATappend(newsymbollist, ATmake("ql(\")\")"));
    newsymbollist = ATinsert(newsymbollist, ATmake("w(\"\")"));
    newsymbollist = ATinsert(newsymbollist, ATmake("ql(\"(\")"));
    newsymbollist = ATinsert(newsymbollist, ATmake("w(\"\")"));
    newsymbollist = ATinsert(newsymbollist, newliteral);
    newprod = ATmake("prod(<term>,w(\"\"),[<list>],w(\"\"),"
                     "l(\"->\"),w(\"\"),<term>,w(\"\"),<term>)",
                     modname, newsymbollist, newsymbol, newattrs);
    return newprod;
  }
  else {
    ATabort("In flatten prod: expected prod, got %t\n", prod); 
    return NULL;
  }

}

/*}}}   */
/*{{{  ATerm AFTmakeCallerProd(ATerm sort) */

/**
 * Converts the term representation of a production into the production rule
 * itself.
 **/

ATerm AFTmakeCallerProd(ATerm sort)
{
  ATerm prod, name, sortname, newsort;
  char *text;
  int i;

  if(AFTisSortSymbol(sort)) {
    sortname = AFTgetSortSymbol(sort);

    if(ATmatchTerm(sortname, pattern_asfix_lex, &text, NULL)) {
      newsort = ATmakeTerm(pattern_asfix_sort,text);
      text = strdup(text);
      if(!text) {
        ATerror("Not enough memory\n"); 
      }
      for(i=0; text[i]; i++)
        text[i] = tolower(text[i]);
      name = ATmakeTerm(pattern_asfix_ql, text);
      free(text);
      prod = ATmakeTerm(pattern_asfix_lex_cons, name, newsort);
      return prod;
    }
    else {   
      ATerror("AFTmakeCallerProd: not an asfix sort: %t\n", sort);
      return NULL;
    }
  }
  else {   
    ATerror("AFTmakeCallerProd: not an asfix sort: %t\n", sort);
    return NULL;
  } 
}

/*}}}   */
/*{{{  ATerm AFTmakeEmptyAttrs() */

/**
 * Creates empty attributes.
 **/

ATerm AFTmakeEmptyAttrs()
{
  return ATmakeTerm(pattern_asfix_appl, af_prod_empty_attrs,
                    ATparse("w(\"\")"),ATempty);
}

/*}}}   */
