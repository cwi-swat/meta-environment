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
AsFix abbreviations

The abbreviation mechanism will probably be abandoned when
most tools can cope with sharing.

\subsection{Abbreviations}
*/

#include <stdio.h>
#include <assert.h>
#include "aterm1.h"
#include "aterm2.h"
#include "deprecated.h"
#include "AsFix.h"
#include "aterm-macs.h"
static int count = 0;

ATermList expand_generic_list(ATermList l, ATermList abbrevs);

ATerm expand_generic(ATerm t, ATermList abbrevs)
{
  if(t_is_asfix_list(t))
    return (ATerm) expand_generic_list((ATermList) t, abbrevs);
  if(!ATgetType(t) == AT_APPL)
    ATerror("not an appl: %t\n", t);

  if(ATmatchTerm(t, pattern_aprod, NULL)) {
    t = ATdictGet((ATerm) abbrevs, t);
  } else {
    ATermList args = expand_generic_list(ATgetArguments((ATermAppl) t),
                                         abbrevs);
    t = (ATerm) ATmakeApplList(ATgetSymbol((ATermAppl) t), args);
  }
  return t;
}

ATermList expand_generic_list(ATermList l, ATermList abbrevs)
{
  int idx = ATgetLength(l)-1;

  ATerm el;
  ATermList expanded = ATempty;

  for( ; idx >= 0; idx--) {
     el = ATelementAt(l, idx);
     expanded = ATinsert(expanded,expand_generic(el, abbrevs));
  }
  return expanded;
}

/* Expand all abbreviations in a list of arguments. */

ATerm expand_appl(ATerm appl, ATermList abbrevs);

ATermList expand_args(ATermList args, ATermList abbrevs)
{
  ATerm arg, layout;
  ATermList newargs = ATempty;

  while(!ATisEmpty(args)) {
    arg = expand_appl(ATgetFirst(args), abbrevs);
    newargs = ATappend(newargs, arg);
    args = ATgetNext(args);
    if(!ATisEmpty(args)) {
      layout = ATgetFirst(args);
      newargs = ATappend(newargs, layout);
      args = ATgetNext(args);
    }
  }
  return newargs;
}

/*
Expand the abbreviations in all elements of an AsFix list.
*/

ATermList expand_elems(ATerm sym, ATermList elems, ATermList abbrevs)
{
  ATerm elem;
  ATermList newelems = ATempty;

  int idx = ATgetLength(elems)-1;

  for( ; idx >= 0; idx--) {
    elem = ATelementAt(elems, idx);
    if(!asfix_is_whitespace(elem) && !asfix_is_list_sep(elem)) {
      elem = expand_appl(elem, abbrevs);
    }
    newelems = ATinsert(newelems,elem);
  }
  return newelems;
}

/*
Expand all abbreviations in an AsFix application.
*/

ATerm expand_appl(ATerm appl, ATermList abbrevs)
{
  ATerm w, prod, sym, result;
  ATermList args, elems;
  
  if(ATmatchTerm(appl, pattern_appl, &prod, &w, &args)) {
    if(ATmatchTerm(prod, pattern_aprod, NULL)) {
      prod = ATdictGet((ATerm) abbrevs, prod);
      args = expand_args(args, abbrevs);
      result = ATmakeTerm(pattern_appl, prod, w, args);
    }
    else
      result = appl;
  }
  else {
    if(asfix_is_list(appl)) {
    elems = asfix_get_list_elems(appl);
    sym = asfix_get_list_sym(appl);
    result = (ATerm) asfix_put_list_elems(appl,
                (ATerm) expand_elems(sym, elems, abbrevs));
  }
  else
    result = appl;
  }
  return result;
}

/*
Expand a list of conditions.
*/

ATermList expand_conds(ATermList conds, ATermList abbrevs)
{
  ATerm lhs, rhs, cond;
  ATerm w[2], lit;
  ATermList newconds = ATempty;

  while(!ATisEmpty(conds)) {
    cond = ATgetFirst(conds);
    if(ATmatchTerm(cond, pattern_cond, &lhs, &w[0], &lit, &w[1], &rhs)) {
      lhs = expand_appl(lhs, abbrevs);
      rhs = expand_appl(rhs, abbrevs);
      cond = ATmakeTerm(pattern_cond, lhs, w[0], lit, w[1], rhs);
      newconds = ATappend(newconds,cond);
      conds = ATgetNext(conds);
      if(!ATisEmpty(conds)) {
        cond = ATgetFirst(conds);
        while(asfix_is_whitespace(cond) || asfix_is_list_sep(cond)) {
          newconds = ATappend(newconds,cond);
          conds = ATgetNext(conds);
          cond = ATgetFirst(conds);
        }
      }
    }
    else {
      ATerror("not a condition: %t\n", cond);
    }
  }
  return newconds;
}

/*
Expand the abbreviations in a single equation.
*/

ATerm expand_equation(ATerm equ, ATermList abbrevs)
{
  ATerm w[6], l[2], modname;
  ATerm tag, lhs, rhs;
  ATermList conds;

  if(ATmatchTerm(equ, pattern_ceq_equ,
        &modname, &w[0], &tag, &w[1], &lhs, &w[2], &l[0], &w[3], &rhs)) {
    lhs = expand_appl(lhs, abbrevs);
    rhs = expand_appl(rhs, abbrevs);

    return ATmakeTerm(pattern_ceq_equ,
        modname, w[0], tag, w[1], lhs, w[2], l[0], w[3], rhs);
  }
  
  if(ATmatchTerm(equ, pattern_ceq_impl, &modname,&w[0],&tag,
      &w[1], &conds, &w[2], &l[0], &w[3], &lhs, &w[4], &l[1], &w[5], &rhs)) {
    lhs = expand_appl(lhs, abbrevs);
    rhs = expand_appl(rhs, abbrevs);
    conds = expand_conds(conds, abbrevs);

    return ATmakeTerm(pattern_ceq_impl, modname, w[0],tag,
        w[1], conds, w[2], l[0], w[3], lhs, w[4], l[1], w[5], rhs);
  }
  if(!ATmatchTerm(equ, pattern_ceq_when, &modname, &w[0],
        &tag, &w[1], &lhs, &w[2], &l[0], &w[3],&rhs,&w[4],&l[1],&w[5],&conds))
  {
    ATprintf("No such equation type: %t\n", equ);
    assert(0);
  }
  lhs = expand_appl(lhs, abbrevs);
  rhs = expand_appl(rhs, abbrevs);
  conds = expand_conds(conds, abbrevs);

  return ATmakeTerm(pattern_ceq_when, modname, w[0], tag,w[1],
        lhs, w[2], l[0], w[3], rhs, w[4], l[1], w[5], conds);
}

/*
Expand all equations in an equation section.
*/

ATerm AFexpandEqs(ATerm equations, ATermList abbrevs)
{
  ATerm equ, layout, t[2];
  ATermList eqs, neweqs = ATempty;

  if(ATmatch(equations, "no-equations"))
    return equations;

  if(ATmatch(equations, "equations(<term>,<term>,[<list>])",
             &t[0],&t[1],&eqs)) {
    while(!ATisEmpty(eqs)) {
      equ = ATgetFirst(eqs);
      neweqs = ATappend(neweqs, expand_equation(equ, abbrevs));
      eqs = ATgetNext(eqs);
      if(!ATisEmpty(eqs)) {
        layout = ATgetFirst(eqs);
        neweqs = ATappend(neweqs, layout);
        eqs = ATgetNext(eqs);
      }
    }
    return ATmake("equations(<term>,<term>,[<list>])", t[0], t[1], neweqs);
  } else {
    ATerror("not equations: %t\n", equations);
		return NULL;
  }
}

/* Expansion of the priorities in the syntax definition. */

ATermList AFexpandSyntax(ATermList sections, ATermList abbrevs)
{
  ATerm section, newsection; 
  ATerm lit[4], ws[4], prod;
  ATermList priors, subsections, lits, prods;
  ATermList newsections = ATempty;

  while(!ATisEmpty(sections)) {
    section = ATgetFirst(sections);
    sections = ATgetNext(sections);
    if(ATmatch(section, "hiddens(<term>,<term>,[<list>])",
               &lit[0], &ws[0], &subsections)) {
      newsection = ATmake("hiddens(<term>,<term>,[<list>])",
                          lit[0], ws[0], 
                          AFexpandSyntax(subsections, abbrevs));
    }
    else if(ATmatch(section, "exports(<term>,<term>,[<list>])",
                     &lit[0], &ws[0], &subsections)) {
      newsection = ATmake("exports(<term>,<term>,[<list>])",
                          lit[0], ws[0], 
                          AFexpandSyntax(subsections, abbrevs));
    }
    else if(ATmatch(section, "priorities(<term>,<term>,[<list>])",
                     &lit[0], &ws[0], &priors)) {
      newsection = ATmake("priorities(<term>,<term>,[<list>])",
                          lit[0], ws[0], 
                          AFexpandSyntax(priors, abbrevs));
    }
    else if(ATmatch(section, "incr-chain([<list>])", &prods)) {
      newsection = ATmake("incr-chain([<list>])",
                          AFexpandSyntax(prods, abbrevs));
    }
    else if(ATmatch(section, "decr-chain([<list>])", &prods)) {
      newsection = ATmake("decr-chain([<list>])",
                          AFexpandSyntax(prods, abbrevs));
    } 
    else if(ATmatch(section, "prod-skel([<list>],<term>,<term>)",
                   &lits,&ws[0],&prod)) {
      newsection = ATmake("prod-skel([<list>],<term>,<term>)",
                          lits,ws[0],expand_generic(prod, abbrevs));
    } 
    else if(ATmatch(section, "group(<term>,<term>,[<list>],<term>,<term>)",
                    &lit[0],&ws[0],&prods,&ws[1],&lit[1])) {
      newsection = ATmake("group(<term>,<term>,[<list>],<term>,<term>)",
                          lit[0],ws[0],
                          AFexpandSyntax(prods, abbrevs),ws[1],lit[1]);
    }
    else if(ATmatch(section,
                    "agroup(<term>,<term>,<term>,<term>,<term>,<term>, " \
                              "[<list>],<term>,<term>)",
                     &lit[0],&ws[0],&lit[1],&ws[1],&lit[2],&ws[2],
                     &prods,&ws[3],&lit[3])) {
      newsection = ATmake("agroup(<term>,<term>,<term>,<term>,<term>,<term>," \
                          "[<list>],<term>,<term>)",
                          lit[0],ws[0],lit[1],ws[1],lit[2],ws[2],
                          AFexpandSyntax(prods, abbrevs),ws[3],lit[3]);
    }
    else
      newsection = section;
    newsections = ATappend(newsections, newsection);
  }
  return newsections;
}

/*
Expand priorities and equations in a module.
*/

ATerm AFexpandModule(ATerm module)
{
  ATerm equations, abbrevs, newequations, t[6];
  ATermList syntax, newsyntax;
  ATermList abbrevlist;

  if(ATmatch(module,
                 "module(<term>,<term>,<term>,<term>,<term>,<term>,<term>," \
                 "<term>,<term>)",
                 &t[0], &t[1], &t[2], &t[3], &syntax, &t[4], 
                 &equations, &t[5], &abbrevs)) {
    newequations = equations;
    newsyntax = syntax;
  
    if(ATmatch(abbrevs, "abbreviations([<list>])", &abbrevlist)) {
      newsyntax = AFexpandSyntax(syntax, abbrevlist);
      if(!ATmatch(equations, "no-equations")) {
        newequations = AFexpandEqs(equations, abbrevlist);
      }
    }
    return ATmake("module(<term>,<term>,<term>,<term>,<term>,<term>," \
                          "<term>,<term>,abbreviations([]))",
          t[0], t[1], t[2], t[3], newsyntax, t[4], newequations, t[5]);
  }
  else {
    ATerror("not a module: %t\n", module);
    return NULL; /* Silence the compiler */
  }
}

/*
Expand a term.
*/

ATerm AFexpandTerm(ATerm term)
{
  ATerm t[7], trm, abbrevs, newtrm;
  ATermList abbrevlist;

  if(!ATmatch(term, "term(<term>,<term>,<term>,<term>,<term>," \
              "<term>,<term>,<term>,<term>)",
              &t[0], &t[1], &t[2], &t[3], &t[4], &t[5], 
              &trm, &t[6], &abbrevs))
    ATerror("AFexpandTerm not a term: %t\n", term);
  newtrm = trm;
  if(ATmatch(abbrevs, "abbreviations([<list>])", &abbrevlist)) {
    if(!ATisEmpty(abbrevlist))
      newtrm = expand_appl(trm, abbrevlist);
  }
  return ATmake("term(<term>,<term>,<term>,<term>,<term>,<term>," \
                "<term>,<term>,abbreviations([]))",
                t[0], t[1], t[2], t[3], t[4], t[5], newtrm, t[6]);
}

/* 
Functions to look for the production rules given an aprod number.
*/

ATerm lookup_aprod(ATerm prod, ATermList *abbrevs)
{
  ATermList pair, list = *abbrevs;
  ATerm abbrev, full;
  char buf[16];

  /* Lookup the prod in the current list of abbreviations */
  while(!ATisEmpty(list)) {
    pair = (ATermList) ATgetFirst(list);
    list = ATgetNext(list);
    abbrev = ATgetFirst(pair);
    full = ATgetFirst(ATgetNext(pair));
    if(ATisEqual(full, prod))
      return abbrev;
  }
  /* We need a new abbreviation */
  sprintf(buf, "%d", ++count);

  abbrev = ATmakeTerm(pattern_aprod, buf);
  pair = (ATermList) ATmake("[<term>,<term>]", abbrev, prod); 
  *abbrevs = ATinsert(*abbrevs, (ATerm) pair);
  return abbrev;
}

ATermList collapse_generic_list(ATermList l, ATermList *abbrevs);
ATerm collapse_generic(ATerm t, ATermList *abbrevs)
{
  if(t_is_asfix_list(t))
    return (ATerm) collapse_generic_list((ATermList) t, abbrevs);
  if(!t_is_asfix_appl(t))
    ATprintf("not an appl: %t\n", t);

  if(ATmatch(t,"prod(<terms>)", NULL)) {
    t = lookup_aprod(t, abbrevs);
  } 
  else {
    ATermList args = collapse_generic_list(ATgetArguments((ATermAppl) t),
                                           abbrevs);
    t = (ATerm) ATmakeApplList(ATgetSymbol((ATermAppl) t), args);
  }
  return t;
}

ATermList collapse_generic_list(ATermList l, ATermList *abbrevs)
{
  ATerm el;
  ATermList collapseed = ATempty;

  while(!ATisEmpty(l)) {
    el = ATgetFirst(l);
    l = ATgetNext(l);
    collapseed = ATappend(collapseed, collapse_generic(el, abbrevs));
  }
  return collapseed;
}


/*
Collapse all abbreviations in a list of arguments.
*/

ATerm collapse_appl(ATerm appl, ATermList *abbrevs);

ATermList collapse_args(ATermList args, ATermList *abbrevs)
{
  ATerm arg, layout;
  ATermList newargs = ATempty;

  while(!ATisEmpty(args)) {
    arg = collapse_appl(ATgetFirst(args), abbrevs);
    newargs = ATappend(newargs, arg);
    args = ATgetNext(args);
    if(!ATisEmpty(args)) {
      layout = ATgetFirst(args);
      newargs = ATappend(newargs, layout);
      args = ATgetNext(args);
    }
  }
  return newargs;
}

/*
Collapse the abbreviations in all elements of an AsFix list.
*/

ATermList collapse_elems(ATerm sym, ATermList elems, ATermList *abbrevs)
{
  ATerm elem;
  ATermList newelems = ATempty;

  while(!ATisEmpty(elems)) {
    elem = collapse_appl(ATgetFirst(elems), abbrevs);
    newelems = ATappend(newelems, elem);
    elems = ATgetNext(elems);
    if(!ATisEmpty(elems)) {
      elem = ATgetFirst(elems);
      while(asfix_is_whitespace(elem) || asfix_is_list_sep(elem)) {
        newelems = ATappend(newelems, elem);
	elems = ATgetNext(elems);
	elem = ATgetFirst(elems);
      }
    }
  }
  return newelems;
}

/*
Collapse all abbreviations in an AsFix application.
*/

ATerm collapse_appl(ATerm appl, ATermList *abbrevs)
{
  ATerm w, prod, sym, result = NULL;
  ATermList args, elems;

  if(ATmatchTerm(appl, pattern_appl, &prod, &w, &args)) {
    if(ATmatchTerm(prod, pattern_aprod, NULL)) {
      return appl;
    } else {
      prod = lookup_aprod(prod, abbrevs);
      args = collapse_args(args, abbrevs);
      result = ATmakeTerm(pattern_appl, prod, w, args);
    }
  } else if(asfix_is_list(appl)) {
    elems = asfix_get_list_elems(appl);
    sym = asfix_get_list_sym(appl);
    result = (ATerm) asfix_put_list_elems(appl, 
             (ATerm) collapse_elems(sym, elems, abbrevs));
  } else {
    return appl;
  }
  return result;
}

/*
Collapse a list of conditions.
*/

ATermList collapse_conds(ATermList conds, ATermList *abbrevs)
{
  ATerm lhs, rhs, cond;
  ATerm w[2], lit;
  ATermList newconds = ATempty;

  while(!ATisEmpty(conds)) {
    cond = ATgetFirst(conds);
    if(ATmatch(cond, "condition(<term>,<term>,<term>,<term>,<term>)",
				&lhs, &w[0], &lit, &w[1], &rhs)) {
      lhs = collapse_appl(lhs, abbrevs);
      rhs = collapse_appl(rhs, abbrevs);
      cond = ATmake("condition(<term>,<term>,<term>,<term>,<term>)",
				  lhs, w[0], lit, w[1], rhs);
      newconds = ATappend(newconds, cond);
      conds = ATgetNext(conds);
      if(!ATisEmpty(conds)) {
        cond = ATgetFirst(conds);
        while(asfix_is_whitespace(cond) || asfix_is_list_sep(cond)) {
	  newconds = ATappend(newconds, cond);
	  conds = ATgetNext(conds);
	  cond = ATgetFirst(conds);
        }
      }
    }
    else {
      ATerror("not a condition %t\n", cond);
    }
  }
  return newconds;
}

/*
Collapse the abbreviations in a single equation.
*/

ATerm collapse_equation(ATerm equ, ATermList *abbrevs)
{
  ATerm w[6], l[2], modname;
  ATerm tag, lhs, rhs;
  ATermList conds;

  if(ATmatch(equ, "ceq-equ(<term>,<term>,<term>,<term>,<term>,<term>," \
	     "<term>,<term>,<term>)", 
	&modname, &w[0], &tag, &w[1], &lhs, &w[2], &l[0], &w[3], &rhs)) {
    lhs = collapse_appl(lhs, abbrevs);
    rhs = collapse_appl(rhs, abbrevs);

    return ATmake("ceq-equ(<term>,<term>,<term>,<term>,<term>,<term>," \
	"<term>,<term>,<term>)", modname, w[0], tag, w[1], lhs, w[2], l[0], w[3], rhs);
  }

  if(ATmatch(equ, "ceq-impl(<term>,<term>,<term>,<term>,[<list>],<term>," \
      "<term>,<term>,<term>,<term>,<term>,<term>,<term>)", &modname,&w[0],&tag,
      &w[1], &conds, &w[2], &l[0], &w[3], &lhs, &w[4], &l[1], &w[5], &rhs)) {
    lhs = collapse_appl(lhs, abbrevs);
    rhs = collapse_appl(rhs, abbrevs);
    conds = collapse_conds(conds, abbrevs);

    return ATmake("ceq-impl(<term>,<term>,<term>,<term>,[<list>],<term>," \
	"<term>,<term>,<term>,<term>,<term>,<term>,<term>)", modname, w[0],tag,
	w[1], conds, w[2], l[0], w[3], lhs, w[4], l[1], w[5], rhs);
  }

  if(!ATmatch(equ, "ceq-when(<term>,<term>,<term>,<term>,<term>," \
	"<term>,<term>,<term>,<term>,<term>,<term>,<term>,[<list>])", &modname, &w[0],
	&tag, &w[1], &lhs, &w[2], &l[0], &w[3],&rhs,&w[4],&l[1],&w[5],&conds))
  {
    ATprintf("no such equation type: %t\n", equ);
    assert(0);
  }
  lhs = collapse_appl(lhs, abbrevs);
  rhs = collapse_appl(rhs, abbrevs);
  conds = collapse_conds(conds, abbrevs);

  return ATmake("ceq-when(<term>,<term>,<term>,<term>,<term>,<term>,"\
	"<term>,<term>,<term>,<term>,<term>,<term>,[<list>])", modname, w[0], tag,w[1],
	lhs, w[2], l[0], w[3], rhs, w[4], l[1], w[5], conds);
}

/*
Collapse all equations in an equation section.
*/

ATerm AFcollapseEqs(ATerm equations, ATermList *abbrevs)
{
  ATerm equ, layout, t[2];
  ATermList eqs, neweqs = ATempty;

  if(ATmatch(equations, "no-equations"))
    return equations;

  if(ATmatch(equations,"equations(<term>,<term>,[<list>])",&t[0],&t[1],&eqs)) {
    while(!ATisEmpty(eqs)) {
      equ = ATgetFirst(eqs);
      neweqs = ATappend(neweqs, collapse_equation(equ, abbrevs));
      eqs = ATgetNext(eqs);
      if(!ATisEmpty(eqs)) {
        layout = ATgetFirst(eqs);
        neweqs = ATappend(neweqs, layout);
        eqs = ATgetNext(eqs);
      }
    }
    return ATmake("equations(<term>,<term>,[<list>])", t[0], t[1], neweqs);
  } else {
    ATerror("not equations: %t\n", equations);
		return NULL;
  }
}

ATermList AFcollapseSyntax(ATermList sections, ATermList *abbrevs)
{
  ATerm section, newsection;
  ATerm lit, ws;
  ATermList priors, subsections, newsections = ATempty;

  while(!ATisEmpty(sections)) {
    section = ATgetFirst(sections);
    sections = ATgetNext(sections);
    if(ATmatch(section, "hiddens(<term>,<term>,[<list>])", &lit, &ws, &subsections)) {
      newsection = ATmake("hiddens(<term>,<term>,[<list>])", 
		   lit, ws, AFcollapseSyntax(subsections, abbrevs));
    } else if(ATmatch(section, "exports(<term>,<term>,[<list>])", &lit, &ws, &subsections)) {
      newsection = ATmake("exports(<term>,<term>,[<list>])",
		   lit, ws, AFcollapseSyntax(subsections, abbrevs));
    } else if(ATmatch(section, "priorities(<term>,<term>,[<list>])", &lit, &ws, &priors)) {
      newsection = ATmake("priorities(<term>,<term>,[<list>])",
			  lit, ws, collapse_generic_list(priors, abbrevs));
    } else
      newsection = collapse_generic(section, abbrevs);
    newsections = ATappend(newsections, newsection);
  }
  return newsections;
}

/*
Collapse an asfix module by introducing abbreviations.
*/

ATerm AFcollapseModule(ATerm module)
{
  ATerm equations, abbrevs, newequations, t[6];
  ATermList syntax, newsyntax;
  ATermList abbrevlist = ATempty;

  count = 0;
  if(ATmatch(module,
             "module(<term>,<term>,<term>,<term>,<term>,<term>,"\
             "<term>,<term>,<term>)",
             &t[0], &t[1], &t[2], &t[3], &syntax, &t[4], &equations, 
             &t[5], &abbrevs)) {
    newequations = equations;
    newsyntax = syntax;
    ATmatch(abbrevs, "abbreviations([<list>])", &abbrevlist);
    newsyntax = AFcollapseSyntax(syntax, &abbrevlist);
    if(!ATmatch(equations, "no-equations")) {
      newequations = AFcollapseEqs(equations, &abbrevlist);
    }
    return ATmake("module(<term>,<term>,<term>,<term>,<term>,<term>," \
			  "<term>,<term>,abbreviations(<term>))",
	t[0], t[1], t[2], t[3], newsyntax, t[4], newequations, t[5], abbrevlist);
  } else {
    ATerror("not a module: %t\n", module);
		return NULL;
  }
}

/*
Collapse an AsFix term.
*/

ATerm AFcollapseTerm(ATerm term)
{
  ATerm t[7], trm, abbrevs, newtrm;
  ATermList abbrevlist = ATempty;

  if(!ATmatch(term, "term(<term>,<term>,<term>,<term>,<term>," \
	"<term>,<term>,<term>,<term>)", 
	&t[0], &t[1], &t[2], &t[3], &t[4], &t[5], &trm, &t[6], &abbrevs)) {
    ATerror("AFcollapseTerm not a term: %t\n", term);
  }
  newtrm = trm;
  ATmatch(abbrevs, "abbreviations([<list>])", &abbrevlist);
  newtrm = collapse_appl(trm, &abbrevlist);

  return ATmake("term(<term>,<term>,<term>,<term>,<term>,<term>," \
	"<term>,<term>,abbreviations(<term>))", 
	t[0], t[1], t[2], t[3], t[4], t[5], newtrm, t[6], abbrevlist);
}
