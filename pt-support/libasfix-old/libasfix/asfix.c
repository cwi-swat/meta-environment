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
/*
\section{AsFix library}

On top of the basic aterm library, we have build the asfix
library. 
*/

#include <stdio.h>
#include <assert.h>
#include "AsFix.h"
#include "deprecated.h"
#include "aterm-macs.h"
#include "aterm2.h"
#include "AsFix-init-patterns.h"

/*
Some often used symbols are stored here.
*/

Symbol symbol_w;
Symbol symbol_l;
Symbol symbol_ceq_equ;
Symbol symbol_ceq_when;
Symbol symbol_ceq_impl;
Symbol symbol_asfix_appl;
Symbol symbol_term;
Symbol symbol_prod;
Symbol symbol_appl;
Symbol symbol_term;
Symbol symbol_lex;
Symbol symbol_asfix_list;
Symbol symbol_iter_sep;
Symbol symbol_iter;
Symbol symbol_asfix_var;
Symbol symbol_sep;
Symbol symbol_attrs;

/*
We build some patterns for quick matching.
*/

ATerm pattern_appl = NULL;
ATerm pattern_prod = NULL;
ATerm pattern_aprod = NULL;
ATerm pattern_attrs = NULL;
ATerm pattern_attr = NULL;
ATerm pattern_lex = NULL;
ATerm pattern_list = NULL;
ATerm pattern_list_w = NULL;
ATerm pattern_itersep = NULL;
ATerm pattern_iter = NULL;
ATerm pattern_var = NULL;
ATerm pattern_whitespace = NULL;
ATerm pattern_empty_ws = NULL;
ATerm pattern_literal = NULL;
ATerm pattern_sep = NULL;
ATerm pattern_iter_plus = NULL;
ATerm pattern_itersep_plus = NULL;
ATerm pattern_iter_star = NULL;
ATerm pattern_itersep_star = NULL;
ATerm pattern_lex_constructor = NULL;
ATerm pattern_equality_cond = NULL;
ATerm pattern_cond = NULL;
ATerm pattern_ceq_equ = NULL;
ATerm pattern_ceq_impl = NULL;
ATerm pattern_ceq_when = NULL;
ATerm pattern_fun_str = NULL;

extern int AFinitPosInfo();

void AFinitialize(int argc, char *argv[])
{
  ATerm bottom;

  AFinit(argc, argv, &bottom);
}

/*
Initialize the asfix library. Memorize some symbols and patterns.
*/

void AFinit(int argc, char *argv[], ATerm *bottomOfStack)
{
  ATinit(argc, argv, bottomOfStack);
  
  symbol_w = ATmakeSymbol("w", 1, ATfalse);
  ATprotectSymbol(symbol_w);
  symbol_l = ATmakeSymbol("l", 1, ATfalse);
  ATprotectSymbol(symbol_l);
  symbol_ceq_equ = ATmakeSymbol("ceq-equ", 9, ATfalse);
  ATprotectSymbol(symbol_ceq_equ);
  symbol_ceq_when = ATmakeSymbol("ceq-when", 13, ATfalse);
  ATprotectSymbol(symbol_ceq_when);
  symbol_ceq_impl = ATmakeSymbol("ceq-impl", 13, ATfalse);
  ATprotectSymbol(symbol_ceq_impl);
  symbol_asfix_appl = ATmakeSymbol("appl", 3, ATfalse);
  ATprotectSymbol(symbol_asfix_appl);
  symbol_prod = ATmakeSymbol("prod", 9, ATfalse);
  ATprotectSymbol(symbol_prod);
  symbol_appl = ATmakeSymbol("appl", 3, ATfalse);
  ATprotectSymbol(symbol_appl);
  symbol_term = ATmakeSymbol("term", 9, ATfalse);
  ATprotectSymbol(symbol_term);
  symbol_lex = ATmakeSymbol("lex", 2, ATfalse);
  ATprotectSymbol(symbol_lex);
  symbol_asfix_list = ATmakeSymbol("list", 3, ATfalse);
  ATprotectSymbol(symbol_asfix_list);
  symbol_iter_sep = ATmakeSymbol("iter-sep", 9, ATfalse);
  ATprotectSymbol(symbol_iter_sep);
  symbol_iter = ATmakeSymbol("iter", 3, ATfalse);
  ATprotectSymbol(symbol_iter);
  symbol_asfix_var = ATmakeSymbol("var", 2, ATfalse);
  ATprotectSymbol(symbol_asfix_var);
  symbol_sep = ATmakeSymbol("sep", 1, ATfalse);
  ATprotectSymbol(symbol_sep);
  symbol_attrs = ATmakeSymbol("attrs", 5, ATfalse);
  ATprotectSymbol(symbol_attrs);

  ATprotect(&pattern_appl);
  ATprotect(&pattern_prod);
  ATprotect(&pattern_aprod);
  ATprotect(&pattern_attrs);
  ATprotect(&pattern_attr);
  ATprotect(&pattern_lex);
  ATprotect(&pattern_list);
  ATprotect(&pattern_list_w);
  ATprotect(&pattern_itersep);
  ATprotect(&pattern_iter);
  ATprotect(&pattern_var);
  ATprotect(&pattern_whitespace);
  ATprotect(&pattern_empty_ws);
  ATprotect(&pattern_literal);
  ATprotect(&pattern_sep);
  ATprotect(&pattern_iter_plus);
  ATprotect(&pattern_itersep_plus);
  ATprotect(&pattern_iter_star);
  ATprotect(&pattern_itersep_star);
  ATprotect(&pattern_lex_constructor);
  ATprotect(&pattern_equality_cond);
  ATprotect(&pattern_cond);
  ATprotect(&pattern_ceq_equ);
  ATprotect(&pattern_ceq_impl);
  ATprotect(&pattern_ceq_when);
  ATprotect(&pattern_fun_str);
  pattern_appl = ATparse("appl(<term>,<term>,[<list>])");
  pattern_prod = ATparse("prod(<term>,<term>,[<list>],<term>," \
	"<term>,<term>,<term>,<term>,<term>)");
  pattern_aprod = ATparse("aprod(<str>)");
  pattern_attrs = ATparse(
		 "attrs(l(\"{\"),<term>,[<list>],<term>,l(\"}\"))");
  pattern_attr = ATparse("l(\"bracket\")");
  pattern_lex = ATparse("lex(<str>,<term>)");
  pattern_list = ATparse("list(<term>,<term>,[<list>])");
  pattern_list_w = ATparse("list(<term>,w(\" \"),[<list>])");
  pattern_itersep = ATparse("iter-sep(<list>)");
  pattern_iter = ATparse("iter(<term>,<term>,<term>)");
  pattern_var = ATparse("var(<str>,<term>)");
  pattern_whitespace = ATparse("w(<str>)");
	pattern_empty_ws   = ATparse("w(\"\")");
  pattern_literal = ATparse("l(<str>)");
  pattern_sep = ATparse("sep(<str>)");
  pattern_iter_plus = ATparse("iter(<term>,<term>,l(\"+\"))");
  pattern_itersep_plus = ATparse("iter-sep(<term>,<term>,<term>,<term>," \
				"<term>,<term>,<term>,<term>,l(\"+\"))");
  pattern_iter_star = ATparse("iter(<term>,<term>,l(\"*\"))");
  pattern_itersep_star = ATparse("iter-sep(<term>,<term>,<term>,<term>," \
				"<term>,<term>,<term>,<term>,l(\"*\"))");
  pattern_lex_constructor = ATparse("appl(prod(id(\"caller\"),<list>),<term>,[<list>])");
  pattern_equality_cond = ATparse("condition(<term>,<term>,l(\"=\"),<term>,<term>)");  
  pattern_cond = ATparse("condition(<term>,<term>,<term>,<term>,<term>)");

  pattern_ceq_equ = ATparse("ceq-equ(<term>,<term>,<term>,<term>,<term>,<term>," \
	"<term>,<term>,<term>)");
  pattern_ceq_impl = ATparse("ceq-impl(<term>,<term>,<term>," \
	"<term>,[<list>],<term>,<term>,<term>,<term>,<term>,<term>,<term>," \
	"<term>)");
  pattern_ceq_when = ATparse("ceq-when(<term>,<term>,<term>," \
	"<term>,<term>,<term>,<term>,<term>,<term>,<term>,<term>,<term>," \
        "[<list>])");
  pattern_fun_str = ATparse("<appl(<str>)>");

  AFinitAsFixPatterns();
  AFinitPosInfo();
}

/*
\subsection{Predicates}

Test for a layout term.
*/

ATbool AFisLayout(ATerm t)
{
  /* Avoid Tmatch for efficiency */

  if(t_is_appl(t) && ATgetSymbol(t) == symbol_w) {
    ATerm arg = ATgetArgument((ATermAppl) t,0);
    if(t_is_appl(arg)) {
      Symbol sym = ATgetSymbol((ATermAppl) arg);
      if(ATgetArity(sym) == 0 && ATisQuoted(sym))
        return ATtrue;
    }
  }
  return ATfalse;
}

/*
Test for a layout term.
*/

ATbool AFnotLayout(ATerm t)
{
  /* Avoid Tmatch for efficiency */
  if(t_is_appl(t) && ATgetSymbol(t) == symbol_w) {
    ATerm arg = ATgetArgument((ATermAppl) t,0);
    if(t_is_appl(arg)) {
      Symbol sym = ATgetSymbol((ATermAppl) arg);
      if(ATgetArity(sym) == 0 && ATisQuoted(sym))
        return ATfalse;
    }
  }
  return ATtrue;
}

ATbool AFisLiteral(ATerm t)
{
  /* Avoid Tmatch for efficiency */
  if(t_is_appl(t) && ATgetSymbol(t) == symbol_l) {
    ATerm arg = ATgetArgument((ATermAppl) t,0);
    if(t_is_appl(arg)) {
      Symbol sym = ATgetSymbol((ATermAppl) arg);
      if(ATgetArity(sym) == 0 && ATisQuoted(sym))
        return ATtrue;
    }
  }
  return ATfalse;
}

/*
Check if {\tt tag} is a default tag.
*/

ATbool AFisDefaultTag(ATerm tag)
{
  if(ATgetType(tag) == AT_APPL) {
    ATerm arg = ATgetArgument((ATermAppl) tag,0);
    if(strprefix(ATgetName(ATgetSymbol(arg)), "[default-"))
      return ATtrue;
  }
  return ATfalse;
}

/*
Check if an equation is a default equation.
*/

ATbool AFisDefaultEquation(ATerm equation)
{
  Symbol s;

  if(ATgetType(equation) == AT_APPL) {
    s = ATgetSymbol(equation);
    if(s == symbol_ceq_equ || s == symbol_ceq_when || s == symbol_ceq_impl) {
      return AFisDefaultTag(ATgetArgument((ATermAppl) equation,2));
    }
  }
  assert(0);
  ATprintf("Equation: %t not supported\n", equation);
  return ATfalse;
}

/*
Check if an AsFix term contains variables.
*/

ATbool AFcontainsVars(ATermList l)
{
  ATerm el;

  while(!ATisEmpty(l)) {
    el = ATgetFirst(l);

    if(asfix_is_var(el))
      return ATtrue;

    if(asfix_is_appl(el)) {
      if(AFcontainsVars((ATermList) asfix_get_appl_args(el)))
        return ATtrue;
    } else if(asfix_is_list(el)) {
      if(AFcontainsVars((ATermList) asfix_get_list_elems(el)))
				return ATtrue;
    }
    l  = ATgetNext(l);
  }
  return ATfalse;  
}

/*
Check if a context-free function is a bracket function.
*/

ATbool AFisBracketCfFunc(ATerm prod)
{
  ATerm attrs, attr;
  ATermList attrlist;
  ATbool found;

  if(ATgetType(prod) == AT_APPL && 
		ATgetSymbol((ATermAppl)prod) == symbol_prod) {
    ATermAppl appl = (ATermAppl)prod;
    attrs = ATgetArgument(appl, 8);	
		if(ATgetType(attrs) == AT_APPL &&
			 ATgetSymbol((ATermAppl)attrs) == symbol_attrs) {
			appl = (ATermAppl)attrs;
			attrlist = (ATermList)ATgetArgument(attrs, 2);
      found = ATfalse;
      while(!ATisEmpty(attrlist) && !found) {
        attr = ATgetFirst(attrlist);
        while(asfix_is_whitespace(attr) || asfix_is_list_sep(attr)) {
          attrlist = ATgetNext(attrlist);
          attr = ATgetFirst(attrlist);
        };
        if(ATisEqual(attr, pattern_attr))
          found = ATtrue;
        attrlist = ATgetNext(attrlist);
      };
      return found;
    }
  }
  return ATfalse;
}

/*
Check whether the function of an AsFix application is a bracket function.
*/

ATbool AFisBracketAppl(ATerm appl)
{
  ATerm w,prod;
  ATermList args;

  if(ATmatchTerm(appl, pattern_appl, &prod, &w, &args)) {
    return AFisBracketCfFunc(prod);
  }
  return ATfalse;
}

/*
\subsection{Access functions}

Some access macros need some help, otherwise they get to long.
*/

ATerm AFgetEquLhs(ATerm equ)
{
  Symbol s = ATgetSymbol(equ);

  if(s == symbol_ceq_equ)
    return ATgetArgument((ATermAppl) equ,4);
  if(s == symbol_ceq_impl)
    return ATgetArgument((ATermAppl) equ,8);
  if(s == symbol_ceq_when)
    return ATgetArgument((ATermAppl) equ,4);

  assert(0);
  return NULL; /* silence the compiler */
}

ATerm AFgetEquRhs(ATerm equ)
{
  Symbol s = ATgetSymbol(equ);

  if(s == symbol_ceq_equ)
    return ATgetArgument((ATermAppl) equ, 8);
  if(s == symbol_ceq_impl)
    return ATgetArgument((ATermAppl) equ, 12);
  if(s == symbol_ceq_when)
    return ATgetArgument((ATermAppl) equ, 8);

  assert(0);
  return NULL; /* silence the compiler */
}

ATerm AFgetEquConds(ATerm equ)
{
  Symbol s = ATgetSymbol(equ);

  if(s == symbol_ceq_equ)
    return (ATerm) ATempty;
  if(s == symbol_ceq_impl)
    return ATgetArgument((ATermAppl) equ, 4);
  if(s == symbol_ceq_when)
    return ATgetArgument((ATermAppl) equ, 12);

  assert(0);
  return NULL; /* silence the compiler */
}

ATerm AFputEquConds(ATerm equ, ATermList conds)
{
  Symbol s = ATgetSymbol(equ);
  ATermList args = ATgetArguments((ATermAppl) equ);

  if(s == symbol_ceq_equ)
    return equ;
  if(s == symbol_ceq_impl) {
    args = ATreplace(args, (ATerm) conds, 4);
    return (ATerm) ATmakeApplList(s, args);
  }
  if(s == symbol_ceq_when) {
    args = ATreplace(args, (ATerm) conds, 12);
    return (ATerm) ATmakeApplList(s, args);
  }

  assert(0);
  return NULL; /* silence the compiler */
}

ATerm AFgetModuleEqs(ATerm mod)
{
  ATerm equations;
  ATermList eqs;

  if(!ATmatch(mod, "module(<term>,<term>,<term>,<term>,<term>," \
							"<term>,<term>,<term>,<term>)",
							NULL, NULL, NULL, NULL, NULL, NULL, &equations, NULL, NULL)) {
		ATerror("AFgetModuleEqs: not an asfix module: %t\n", mod);
	}
  if(ATmatch(equations, "no-equations"))
    return (ATerm) ATempty;
  if(!ATmatch(equations, "equations(<term>,<term>,[<list>])",NULL,NULL,&eqs))
		ATerror("AFgetModuleEqs: improper equations: %t\n", equations);
  return (ATerm) eqs;
}

ATerm AFputModuleEqs(ATerm mod, ATermList eqs)
{
  ATerm eqname, nlsp, equations;
  ATermList args = ATgetArguments((ATermAppl) mod);
  ATerm t[2], eq;

  if(ATisEmpty(eqs))
    eq = ATparse("no-equations");
  else {
    if(!ATmatch(mod, "module(<term>,<term>,<term>,<term>,<term>," \
				  "<term>,<term>,<term>,<term>)",
								NULL, NULL, NULL, NULL, NULL, NULL, &equations, NULL, NULL)) {
			ATerror("AFputModuleEqs: not a module %t\n", mod);
		}
    if(ATmatch(equations, "no-equations")) {
      eqname = ATparse("l(\"equations\")");
      nlsp = ATparse("w(\"\\n\")");
      eq = ATmake("equations(<term>,<term>,[<list>])", eqname, nlsp, eqs);
    }
    else {
      if(!ATmatch(equations, "equations(<term>,<term>,[<list>])",
									&t[0], &t[1], NULL))
				ATerror("illegal equation section: %t\n", equations);
      eq = ATmake("equations(<term>,<term>,[<list>])", t[0], t[1], eqs);
    }
  }
  
  args = ATreplace(args, eq, 6);
  return (ATerm) ATmakeApplList(ATgetSymbol((ATermAppl) mod), args);
}

ATermList AFgetModuleSections(ATerm mod)
{
  ATermList sections;

  if(ATmatch(mod, "module(<term>,<term>,<term>,<term>,[<list>]," \
				"<term>,<term>,<term>,<term>)",
		NULL, NULL, NULL, NULL, &sections, NULL, NULL, NULL, NULL))
    return sections;
  else {
    ATerror("not a module %t\n", mod);
		return NULL;
  }
}

ATerm AFputModuleSections(ATerm mod, ATermList sections)
{
  ATermList args = ATgetArguments((ATermAppl) mod);

  args = ATreplace(args, (ATerm) sections, 4);
  return (ATerm) ATmakeApplList(ATgetSymbol((ATermAppl) mod), args);
}

ATerm AFgetModuleName(ATerm mod)
{
  ATerm mname;

  if(!ATmatch(mod, "module(<term>,<term>,<term>,<term>,[<list>]," \
							"<term>,<term>,<term>,<term>)",
							NULL, NULL, &mname, NULL, NULL, NULL, NULL, NULL, NULL)) {
		ATerror("AFgetModuleName: not a module: %t\n", mod);
	}
	return mname;
}

ATerm AFputModuleName(ATerm mod, ATerm mname)
{
  ATermList args = ATgetArguments((ATermAppl) mod);

  args = ATreplace(args, mname, 2);
  return (ATerm) ATmakeApplList(ATgetSymbol((ATermAppl) mod), args);
}

ATermList AFgetModuleCFfuncs(ATerm mod)
{
  ATermList sections, subsections, funcs;
  ATerm section, subsection;
  ATermList cffuncs = ATempty;

  sections = AFgetModuleSections(mod);
 
  while(!ATisEmpty(sections)) {
    section = ATgetFirst(sections);
    if(ATmatch(section, "exports(<term>,<term>,[<list>])",
              NULL, NULL, &subsections) ||
       ATmatch(section, "hiddens(<term>,<term>,[<list>])",
              NULL, NULL, &subsections)) {
      while(!ATisEmpty(subsections)) {
        subsection = ATgetFirst(subsections);
        if(ATmatch(subsection, "context-free-syntax(<term>,<term>,[<list>])",
                  NULL, NULL, &funcs)) {
          cffuncs = ATconcat(cffuncs,funcs);
        }
        subsections = ATgetNext(subsections);
      }
    }
    sections = ATgetNext(sections);
  }
  return cffuncs;
}

ATermList AFgetModuleSorts(ATerm mod)
{
  ATermList sections, subsections, idlist;
  ATerm section, subsection;
  ATermList sorts = ATempty;

  sections = AFgetModuleSections(mod);

  while(!ATisEmpty(sections)) {
    section = ATgetFirst(sections);
    if(ATmatch(section, "exports(<term>,<term>,[<list>])",
              NULL, NULL, &subsections) ||
       ATmatch(section, "hiddens(<term>,<term>,[<list>])",
              NULL, NULL, &subsections)) {
      while(!ATisEmpty(subsections)) {
        subsection = ATgetFirst(subsections);
        if(ATmatch(subsection, "sorts(<term>,<term>,[<list>])",
                  NULL, NULL, &idlist)) {
          sorts = ATconcat(sorts,idlist);
        }
        subsections = ATgetNext(subsections);
      }
    }
    sections = ATgetNext(sections);
  }
  return sorts;
}

ATermList AFgetModuleLexfuncs(ATerm mod)
{
  ATermList sections, subsections, funcs;
  ATerm section, subsection;
  ATermList lexfuncs = ATempty;

  sections = AFgetModuleSections(mod);

  while(!ATisEmpty(sections)) {
    section = ATgetFirst(sections);
    if(ATmatch(section, "exports(<term>,<term>,[<list>])",
              NULL, NULL, &subsections) ||
       ATmatch(section, "hiddens(<term>,<term>,[<list>])",
              NULL, NULL, &subsections)) {
      while(!ATisEmpty(subsections)) {
        subsection = ATgetFirst(subsections);
        if(ATmatch(subsection, "lexical-syntax(<term>,<term>,[<list>])",
                  NULL, NULL, &funcs)) {
          lexfuncs = ATconcat(lexfuncs,funcs);
        }
        subsections = ATgetNext(subsections);
      }
    }
    sections = ATgetNext(sections);
  }
  return lexfuncs;
}

ATerm AFputSectionArgs(ATerm section, ATermList secargs)
{
  ATermList args = ATgetArguments((ATermAppl) section);

  args = ATreplace(args, (ATerm) secargs, 2);
  return (ATerm) ATmakeApplList(ATgetSymbol(section), args);
}

ATerm AFinitModule()
{
  ATermList elist;
  ATerm nlsp, esp, wsp;
  ATerm mod, mname, noeq, abbrevs;

  mod = ATparse("l(\"module\")");
  nlsp = ATparse("w(\"\\n\")");
  esp = ATparse("w(\"\")");
  wsp = ATparse("w(\" \")");
  mname = ATparse("id(\"Unknown\")");
  noeq = ATparse("no-equations");
  elist = ATempty;
  abbrevs = ATmake("abbreviations([<list>])",elist);

  return ATmake("module(<term>,<term>,<term>,<term>,[<list>],<term>,<term>,<term>,<term>)",
		  mod, wsp, mname, nlsp, elist, nlsp, noeq, esp, abbrevs);
}

ATerm AFinitExportSection()
{
  ATermList elist;
  ATerm nlsp;
  ATerm export;

  export = ATparse("l(\"exports\")");
  nlsp = ATparse("w(\"\\n\")");
  elist = ATempty;

  return ATmake("exports(<term>,<term>,[<list>])",
               export, nlsp, elist);              
}

ATerm AFinitContextFreeSyntaxSection()
{
  ATermList elist;
  ATerm nlsp;
  ATerm cfsyntax;

  cfsyntax = ATparse("l(\"context-free syntax\")");
  nlsp = ATparse("w(\"\\n\")");
  elist = ATempty;

  return ATmake("context-free-syntax(<term>,<term>,[<list>])",
               cfsyntax, nlsp, elist);              
}

ATerm AFinitLexicalSyntaxSection()
{
  ATermList elist;
  ATerm nlsp;
  ATerm syntax;

  syntax = ATparse("l(\"lexical syntax\")");
  nlsp = ATparse("w(\"\\n\")");
  elist = ATempty;

  return ATmake("lexical-syntax(<term>,<term>,[<list>])",
               syntax, nlsp, elist);
}

ATerm AFgetProdSort(ATerm prod)
{
  ATerm sort;

  if(ATmatchTerm(prod,pattern_prod,
                 NULL,NULL,NULL,NULL,NULL,NULL,&sort,NULL,NULL))
    return sort;
  else {
    ATerror("Not a prod %t\n", prod);
    return NULL; /* Silence the compiler */
  }
}

ATerm AFmakeProd(ATerm mname, ATermList args, ATerm sort, ATerm attrs)
{
  ATerm esp, arrow;

  esp = ATmakeTerm(pattern_whitespace, "");
  arrow = ATmakeTerm(pattern_literal, "->");

  return ATmakeTerm(pattern_prod, mname,esp,args,esp,
										arrow,esp,sort,esp,attrs);
}

ATerm AFmakeAppl(ATerm prod, ATermList args)
{
	return (ATerm)ATmakeAppl3(symbol_appl, prod, 
														pattern_empty_ws, (ATerm)args);
}

ATerm AFmakeLex(char *sym, ATerm sort)
{
  int len,i,j;
  char *newsym;
  ATerm result;

  len = strlen(sym) * 2;
  newsym = malloc(len + 3);
  if(!newsym) {
    ATerror("Not enough memory\n");
  } 
  newsym[0] = '"';
  for (j=1,i=0; sym[i]; i++) {
    switch(sym[i]) {
      case '\n': newsym[j++] = '\\';
                 newsym[j++] = 'n';
                 break;
      case '\r': newsym[j++] = '\\';
                 newsym[j++] = 'r';
                 break;
      case '\t': newsym[j++] = '\\';
                 newsym[j++] = 't';
                 break;
      case '\\':
      case '"': newsym[j++] = '\\';
      default: newsym[j++] = sym[i];
    }
  }
  newsym[j++] = '"';
  newsym[j] = '\0';

  result = ATmakeTerm(pattern_lex, newsym, sort);
  free(newsym);
  return result;
}
