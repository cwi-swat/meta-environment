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
#include <assert.h>

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
/*{{{  globals */

static ATerm filename = NULL;
static int line;
static int col;
static int pos;

static AFun symbol_area;
static ATerm label_pos;
static ATbool inited = ATfalse;

/*}}}  */
/*{{{  functions */

static void posInfoElems(ATermList elems);
static void posInfoArgs(ATermList args);

/*}}}  */

/*{{{  static ATerm buildPosInfo(l1, c1, p1, l2, c2, p2) */

/**
	* Retrieve current positional information
	*/

static ATerm buildPosInfo(int l1, int c1, int p1, int l2, int c2, int p2)
{
	/* Ignoring p1 and p2 for now... */
	return (ATerm)ATmakeAppl(symbol_area, filename,
													 (ATerm)ATmakeInt(l1), (ATerm)ATmakeInt(c1),
													 (ATerm)ATmakeInt(l2), (ATerm)ATmakeInt(c2));
}

/*}}}  */
/*{{{  static void posInfo(char *txt) */

/**
	* Update positional information for a text string
	*/

static void posInfo(char *txt)
{
	while(*txt) {
		if(*txt++ == '\n') {
			col = 0;
			line++;
		} else {
			col++;
		}
		pos++;
	}
}

/*}}}  */
/*{{{  static void posInfoLit(ATerm lit) */

/**
	* Update positional information for literals
	*/

static void posInfoLit(ATerm lit)
{
	char *txt;
	if(ATgetAFun((ATermAppl)lit) != symbol_l)
		ATerror("expected a literal, got: %t\n", lit);
	
	txt = ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)lit, 0)));
	posInfo(txt);
}

/*}}}  */
/*{{{  static void posInfoSep(ATerm sep) */

/**
	* Update positional information for separators
	*/

static void posInfoSep(ATerm sep)
{
	char *txt;
	if(ATgetAFun((ATermAppl)sep) != symbol_sep)
		ATerror("expected a separator, got: %t\n", sep);
	
	txt = ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)sep, 0)));
	posInfo(txt);
}

/*}}}  */
/*{{{  static void posInfoLex(ATerm lex) */

/**
	* Update positional information for lexicals
	*/

static void posInfoLex(ATerm lex)
{
	char *txt;
	if(ATgetAFun((ATermAppl)lex) != symbol_lex)
		ATerror("expected a lexical, got: %t\n", lex);
	
	txt = ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)lex, 0)));
	posInfo(txt);
}

/*}}}  */
/*{{{  static void posInfoWS(ATerm ws) */

/**
	* Update positional information for literals
	*/

static void posInfoWS(ATerm ws)
{
	char *txt;
	assert(ATgetAFun((ATermAppl)ws) == symbol_w);
	
	txt = ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ws, 0)));
	posInfo(txt);
}

/*}}}  */

/*{{{  static void posInfoElem(ATerm elem) */

/**
	* Update positional information for a list element.
	*/ 

static void posInfoElem(ATerm elem)
{
	ATerm prod, w, sort, iter;
	ATermList args, elems;
	char *txt;

	if(ATmatchTerm(elem, pattern_asfix_sep, &txt)) {
		posInfo(txt);
	} else if(ATmatchTerm(elem, pattern_asfix_appl, &prod, &w, &args)) {
		posInfoArgs(args);
	} else if(ATmatchTerm(elem, pattern_asfix_var, &txt, &sort)) {
		posInfo(txt);
	} else if(ATmatchTerm(elem, pattern_asfix_list, &iter, &w, &elems)) {
		posInfoElems(elems);
	} else if(ATmatchTerm(elem, pattern_asfix_lex, &txt, &sort)) {
		posInfo(txt);
	} else {
		ATerror("strange list element: %t\n", elem);
	}
}

/*}}}  */
/*{{{  static void posInfoElems(ATermList elems) */

/**
	* Handle positional information for elems of a list
	*/

static void posInfoElems(ATermList elems)
{
	ATerm elem, w;

	while(!ATisEmpty(elems)) {
		elem = ATgetFirst(elems);
		posInfoElem(elem);
		elems = ATgetNext(elems);
		if(!ATisEmpty(elems)) {
			w = ATgetFirst(elems);
			posInfoWS(w);
			elems = ATgetNext(elems);
		}
	}
}

/*}}}  */
/*{{{  static void posInfoArg(ATerm arg) */

/**
	* Update positional information for an argument of an appl.
	*/

static void posInfoArg(ATerm arg)
{
	ATerm prod, w, sort, iter;
	ATermList args, elems;
	char *txt;

	if(ATmatchTerm(arg, pattern_asfix_l, &txt)) {
		posInfo(txt);
	} else if(ATmatchTerm(arg, pattern_asfix_ql, &txt)) {
		posInfo(txt);
	} else if(ATmatchTerm(arg, pattern_asfix_appl, &prod, &w, &args)) {
		posInfoArgs(args);
	} else if(ATmatchTerm(arg, pattern_asfix_var, &txt, &sort)) {
		posInfo(txt);
	} else if(ATmatchTerm(arg, pattern_asfix_list, &iter, &w, &elems)) {
		posInfoElems(elems);
	} else if(ATmatchTerm(arg, pattern_asfix_lex, &txt, &sort)) {
		posInfo(txt);
	} else {
		ATerror("strange argument term: %t\n", arg);
	}
}

/*}}}  */
/*{{{  static void posInfoArgs(ATermList args) */

/**
	* Handle positional information for arguments
	*/

static void posInfoArgs(ATermList args)
{
	ATerm arg, w;

	while(!ATisEmpty(args)) {
		arg = ATgetFirst(args);
		posInfoArg(arg);
		args = ATgetNext(args);
		if(!ATisEmpty(args)) {
			w = ATgetFirst(args);
			posInfoWS(w);
			args = ATgetNext(args);
		}
	}
}

/*}}}  */

/*{{{  static ATermList AFaddPosInfoToTerm(ATerm term) */

/**
	* Add positional information to a term
	*/

static ATerm AFaddPosInfoToTerm(ATerm term)
{
	ATerm prod, w, sort, iter, pinfo;
	ATermList args, elems;
	char *var, *txt;
	int start_line, start_col, start_pos;

	start_line = line;
	start_col  = col;
	start_pos  = pos;

	if(ATmatchTerm(term, pattern_asfix_appl, &prod, &w, &args)) {
		/*posInfoWS(w); <PO> bogus whitespace? */
		posInfoArgs(args);
		pinfo = buildPosInfo(start_line, start_col, start_pos, line, col, pos);
		return ATsetAnnotation(term, label_pos, pinfo);
	} else if(ATmatchTerm(term, pattern_asfix_var, &var, &sort)) {
		posInfo(var);
		pinfo = buildPosInfo(start_line, start_col, start_pos, line, col, pos);
		return ATsetAnnotation(term, label_pos, pinfo);
	} else if(ATmatchTerm(term, pattern_asfix_list, &iter, &w, &elems)) {
		posInfoElems(args);
		pinfo = buildPosInfo(start_line, start_col, start_pos, line, col, pos);
		return ATsetAnnotation(term, label_pos, pinfo);
	} else if(ATmatchTerm(term, pattern_asfix_lex, &txt, &sort)) {
		posInfo(txt);
		pinfo = buildPosInfo(start_line, start_col, start_pos, line, col, pos);
		return ATsetAnnotation(term, label_pos, pinfo);
	} else {
		ATerror("strange term: %t\n", term);
		return NULL;
	}
}

/*}}}  */

/*{{{  static ATerm AFaddPosInfoToCond(ATerm cond) */

/**
	* Add positional information to a condition
	*/

static ATerm AFaddPosInfoToCond(ATerm cond)
{
	ATerm lhs, rhs, w[2], l, pinfo;
	int start_line, start_col, start_pos;

	if(ATmatchTerm(cond, pattern_asfix_condition, 
								 &lhs, &w[0], &l, &w[1], &rhs)) {
		start_line = line;
		start_col  = col;
		start_pos  = pos;
		lhs = AFaddPosInfoToTerm(lhs);
		posInfoWS(w[0]);
		posInfoLit(l);
		posInfoWS(w[1]);
		rhs = AFaddPosInfoToTerm(rhs);
		cond = ATmakeTerm(pattern_asfix_condition, lhs, w[0], l, w[1], rhs);
		pinfo = buildPosInfo(start_line, start_col, start_pos, line, col, pos);
		return ATsetAnnotation(cond, label_pos, pinfo);
	}

	ATerror("not a condition: %t\n", cond);
	return NULL;
}

/*}}}  */
/*{{{  static ATermList AFaddPosInfoToConds(ATermList conds) */

/**
	* Add positional information to a list of conditions
	*/

static ATermList AFaddPosInfoToConds(ATermList conds)
{
	ATerm ws, sep;
	ATermList result = ATempty;
	char *txt;

	while(!ATisEmpty(conds)) {
		ATerm cond = ATgetFirst(conds);
		cond = AFaddPosInfoToCond(cond);
		result = ATinsert(result, cond);

		conds = ATgetNext(conds);
		if(!ATisEmpty(conds)) {
			/* Strip whitespace */
			ws = ATgetFirst(conds);
			conds = ATgetNext(conds);
			posInfoWS(ws);
			result = ATinsert(result, ws);
			sep = ATgetFirst(conds);
			conds = ATgetNext(conds);
			txt = ATgetName(ATgetAFun(ATgetArgument((ATermAppl)sep, 0)));
			posInfo(txt);
			result = ATinsert(result, sep);
			ws = ATgetFirst(conds);
			conds = ATgetNext(conds);
			posInfoWS(ws);
			result = ATinsert(result, ws);
		}
	}

	return ATreverse(result);
}

/*}}}  */

/*{{{  static ATerm AFaddPosInfoToEquation(ATerm eq) */

/**
	* Add positional information to a single equation
	*/

static ATerm AFaddPosInfoToEquation(ATerm eq)
{
	ATerm id, w[6], l[3], lhs, rhs, pinfo;
	ATermList conds;
	int start_line, start_col, start_pos;

	start_line = line;
	start_col = col;
	start_pos = pos;

	if(ATmatchTerm(eq, pattern_asfix_ceqequ, &id, &w[0], &l[0], &w[1], &lhs,
								 &w[2], &l[1], &w[3], &rhs)) {
		posInfoWS(w[0]);
		posInfoLit(l[0]);
		posInfoWS(w[1]);
		lhs = AFaddPosInfoToTerm(lhs);
		posInfoWS(w[2]);
		posInfoLit(l[1]);
		posInfoWS(w[3]);
		rhs = AFaddPosInfoToTerm(rhs);
		eq = ATmakeTerm(pattern_asfix_ceqequ, id, w[0], l[0], w[1], lhs,
										w[2], l[1], w[3], rhs);
		pinfo = buildPosInfo(start_line, start_col, start_pos, line, col, pos);
		return ATsetAnnotation(eq, label_pos, pinfo);
	}

	if(ATmatchTerm(eq, pattern_asfix_ceqimpl, &id, &w[0], &l[0], &w[1], &conds,
								 &w[2], &l[1], &w[3], &lhs, &w[4], &l[2], &w[5], &rhs)) {
		posInfoWS(w[0]);
		posInfoLit(l[0]);
		posInfoWS(w[1]);
		conds = AFaddPosInfoToConds(conds);
		posInfoWS(w[2]);
		posInfoLit(l[1]);
		posInfoWS(w[3]);
		lhs = AFaddPosInfoToTerm(lhs);
		posInfoWS(w[4]);
		posInfoLit(l[2]);
		posInfoWS(w[5]);
		rhs = AFaddPosInfoToTerm(rhs);
		eq = ATmakeTerm(pattern_asfix_ceqimpl, id, w[0], l[0], w[1], conds,
										w[2], l[1], w[3], lhs, w[4], l[2], w[5], rhs);
		pinfo = buildPosInfo(start_line, start_col, start_pos, line, col, pos);
		return ATsetAnnotation(eq, label_pos, pinfo);
	}

	if(ATmatchTerm(eq, pattern_asfix_ceqwhen, &id, &w[0], &l[0], &w[1], &lhs,
								 &w[2], &l[1], &w[3], &rhs, &w[4], &l[2], &w[5], &conds)) {
		posInfoWS(w[0]);
		posInfoLit(l[0]);
		posInfoWS(w[1]);
		lhs = AFaddPosInfoToTerm(lhs);
		posInfoWS(w[2]);
		posInfoLit(l[1]);
		posInfoWS(w[3]);
		rhs = AFaddPosInfoToTerm(rhs);
		posInfoWS(w[4]);
		posInfoLit(l[2]);
		posInfoWS(w[5]);
		conds = AFaddPosInfoToConds(conds);
		eq = ATmakeTerm(pattern_asfix_ceqwhen, id, w[0], l[0], w[1], lhs,
										w[2], l[1], w[3], rhs, w[4], l[2], w[5], conds);
		pinfo = buildPosInfo(start_line, start_col, start_pos, line, col, pos);
		return ATsetAnnotation(eq, label_pos, pinfo);
	}

	ATerror("not an equation: %t\n", eq);
	return NULL;
}

/*}}}  */
/*{{{  static ATermList AFaddPosInfoToEquations(ATermList eqs) */

/**
	* Add positional information to a list of equations
	*/

static ATermList AFaddPosInfoToEquations(ATermList eqs)
{
  ATermList result = ATempty;

	while(!ATisEmpty(eqs)) {
		ATerm eq = AFaddPosInfoToEquation(ATgetFirst(eqs));
		result = ATinsert(result, eq);
		eqs = ATgetNext(eqs);
		if(!ATisEmpty(eqs)) {
			ATerm ws = ATgetFirst(eqs);
			posInfoWS(ws);
			result = ATinsert(result, ws);
			eqs = ATgetNext(eqs);
		}
	}

	return ATreverse(result);
}

/*}}}  */
/*{{{  static ATerm AFaddPosInfoToEqSection(ATerm eqs) */

/**
	* Add positional information to an equation section
	*/

static ATerm AFaddPosInfoToEqSection(ATerm eqsection)
{
	ATerm lit, w;
	ATermList eqs;

	if(ATmatchTerm(eqsection, pattern_asfix_noequations))
		return eqsection;
	
	if(ATmatchTerm(eqsection, pattern_asfix_equations, &lit, &w, &eqs)) {
		posInfoLit(lit);
		posInfoWS(w);
		eqs = AFaddPosInfoToEquations(eqs);
		return ATmakeTerm(pattern_asfix_equations, lit, w, eqs);
	}
	
	ATerror("not an equation section: %t\n", eqsection);
	return NULL;
}

/*}}}  */

/*{{{  static ATerm AFTaddPosInfoToCond(ATerm cond) */

/**
	* Add positional information to a condition
	*/

static ATerm AFTaddPosInfoToCond(ATerm cond)
{
	ATerm prod, lhs, w[2], lit, rhs, pinfo;
	int start_line, start_col, start_pos;

	if(AFTisCond(cond)) {
		prod = AFTgetCondProd(cond);
		lhs  = AFTgetCondLHS(cond);
		lhs  = AFaddPosInfoToTerm(lhs);
		w[0] = AFTgetCondWS0(cond);
		posInfoWS(w[0]);

		start_line = line;
		start_col  = col;
		start_pos  = pos;
		lit  = AFTgetCondLit(cond);
		posInfoLit(lit);
		pinfo = buildPosInfo(start_line, start_col, start_pos, line, col, pos);

		w[1] = AFTgetCondWS1(cond);
		posInfoWS(w[1]);
		rhs  = AFTgetCondRHS(cond);
		rhs  = AFaddPosInfoToTerm(rhs);

		cond = AFTbuildCond(prod, lhs, w[0], lit, w[1], rhs);
		return ATsetAnnotation(cond, label_pos, pinfo);
	}

	ATerror("expected condition, got: %t\n", cond);
	return NULL;
}

/*}}}  */
/*{{{  static ATerm AFTaddPosInfoToCondList(ATerm conds) */

static ATerm AFTaddPosInfoToCondList(ATerm conds)
{
	ATermList result = ATempty, list;
	ATerm w, wl, sep, cond, iter;

	if(!AFTisList(conds))
		ATerror("expected condition list, got: %t\n", conds);

	iter = AFTgetListIter(conds);
  wl   = AFTgetListWS(conds);
	list = AFTgetListElements(conds);

	while(!ATisEmpty(list)) {
		cond = ATgetFirst(list);
		list = ATgetNext(list);
		cond = AFTaddPosInfoToCond(cond);
		result = ATinsert(result, cond);
		if(!ATisEmpty(list)) {
			w = ATgetFirst(list);
			posInfoWS(w);
			list = ATgetNext(list);
			result = ATinsert(result, w);
			sep = ATgetFirst(list);
			posInfoSep(sep);
			list = ATgetNext(list);
			result = ATinsert(result, sep);
			w = ATgetFirst(list);
			posInfoWS(w);
			list = ATgetNext(list);
			result = ATinsert(result, w);
		}
	}

	list = ATreverse(result);
	conds = AFTbuildList(iter, wl, list);

	return conds;
}

/*}}}  */
/*{{{  static ATerm AFTaddPosInfoToConds(ATerm conds) */

static ATerm AFTaddPosInfoToConds(ATerm conds)
{
	if(AFTisConds(conds)) {
		ATerm condlist = AFTgetCondsCondList(conds);
		condlist = AFTaddPosInfoToCondList(condlist);
		return AFTbuildConds(condlist);
	}

	ATerror("expected conds, got: %t\n", conds);
	return NULL;
}

/*}}}  */

/*{{{  static ATerm AFTaddPosInfoToSimpleEqu(ATerm eq) */

/**
	* Add positional information to an equation
	*/

static ATerm AFTaddPosInfoToSimpleEqu(ATerm equ)
{
	ATerm prod, w[2], l, lhs, rhs;

	if(AFTisSimpleEqu(equ)) {
		prod = AFTgetSimpleEquProd(equ);
		lhs  = AFTgetSimpleEquLHS(equ);
		lhs  = AFaddPosInfoToTerm(lhs);
		w[0] = AFTgetSimpleEquWS0(equ);
		posInfoWS(w[0]);

		l = AFTgetSimpleEquLit(equ);
		posInfoLit(l);

		w[1] = AFTgetSimpleEquWS1(equ);
		posInfoWS(w[1]);

		rhs  = AFTgetSimpleEquRHS(equ);
		rhs  = AFaddPosInfoToTerm(rhs);
		
		equ = AFTbuildSimpleEqu(prod, lhs, w[0], l, w[1], rhs); 

		return equ;
	}

	ATerror("expected simple equ, got %t\n", equ);
	return NULL;
}

/*}}}  */
/*{{{  static ATerm AFTaddPosInfoToCondEqu(ATerm eq) */

/**
	* Add positional information to an equation
	*/

static ATerm AFTaddPosInfoToCondEqu(ATerm condEqu)
{
	ATerm tag, equ, lex, lit, w[3], list, pinfo; 
	int start_line, start_col, start_pos;

	start_line = line;
	start_col = col;
	start_pos = pos;

	if(AFTisSimpleCondEqu(condEqu)) {
		/*{{{  We are dealing with a simple conditional equation */

		tag  = AFTgetSimpleCondEquTag(condEqu);
		tag  = AFaddPosInfoToTerm(tag);
		w[0] = AFTgetSimpleCondEquWS(condEqu);
		posInfoWS(w[0]);
		equ  = AFTgetSimpleCondEquEqu(condEqu);
		equ  = AFTaddPosInfoToSimpleEqu(equ);
		
		condEqu = AFTbuildSimpleCondEqu(tag, w[0], equ);
		pinfo = buildPosInfo(start_line, start_col, start_pos, line, col, pos);
		return ATsetAnnotation(condEqu, label_pos, pinfo);

		/*}}}  */
	}

	if(AFTisImpliesCondEqu(condEqu)) {
		/*{{{  We are dealing with an Implies equation */

		tag  = AFTgetImpliesCondEquTag(condEqu);
		tag  = AFaddPosInfoToTerm(tag);
		w[0] = AFTgetImpliesCondEquWS0(condEqu);
		posInfoWS(w[0]);

		list = AFTgetImpliesCondEquConds(condEqu);
		list = AFTaddPosInfoToConds(list);
		w[1] = AFTgetImpliesCondEquWS1(condEqu);
		posInfoWS(w[1]);
		lex  = AFTgetImpliesCondEquBarLex(condEqu);
		posInfoLex(lex);
		w[2] = AFTgetImpliesCondEquWS2(condEqu);
		posInfoWS(w[2]);
		equ  = AFTgetImpliesCondEquEqu(condEqu);
		equ  = AFTaddPosInfoToSimpleEqu(equ);

		condEqu = AFTbuildImpliesCondEqu(tag, w[0], list, w[1], lex, w[2], equ);
		pinfo = buildPosInfo(start_line, start_col, start_pos, line, col, pos);
		return ATsetAnnotation(condEqu, label_pos, pinfo);

		/*}}}  */
	}

	if(AFTisWhenCondEqu(condEqu)) {
		/*{{{  We are dealing with a WHEN equation */

		tag  = AFTgetWhenCondEquTag(condEqu);
		tag  = AFaddPosInfoToTerm(tag);
		w[0] = AFTgetWhenCondEquWS0(condEqu);
		posInfoWS(w[0]);
		equ  = AFTgetWhenCondEquEqu(condEqu);
		equ  = AFTaddPosInfoToSimpleEqu(equ);
		w[1] = AFTgetWhenCondEquWS1(condEqu);
		posInfoWS(w[1]);
		lit  = AFTgetWhenCondEquLit(condEqu);
		posInfoLit(lit);
		w[2] = AFTgetWhenCondEquWS2(condEqu);
		posInfoWS(w[2]);
		list = AFTgetWhenCondEquConds(condEqu);
		list = AFTaddPosInfoToConds(list);

		condEqu = AFTbuildWhenCondEqu(tag, w[0], equ, w[1], lit, w[2], list);
		pinfo = buildPosInfo(start_line, start_col, start_pos, line, col, pos);
		return ATsetAnnotation(condEqu, label_pos, pinfo);

		/*}}}  */
	}

	ATerror("expected cond-equ, got %t\n", condEqu);
	return NULL;
}

/*}}}  */
/*{{{  static ATermList AFTaddPosInfoToEqs(ATermList eqs) */

/**
	* Add positional information to a list of equations
	*/

static ATermList AFTaddPosInfoToEqs(ATermList eqs)
{
	ATermList result = ATempty;

	while(!ATisEmpty(eqs)) {
		ATerm w, eq;
		eq = ATgetFirst(eqs);
		eqs = ATgetNext(eqs); 
		eq = AFTaddPosInfoToCondEqu(eq);
		result = ATinsert(result, eq);
		if(!ATisEmpty(eqs)) {
			w = ATgetFirst(eqs);
			posInfoWS(w);
			eqs = ATgetNext(eqs);
			result = ATinsert(result, w);
		}
	}

	return ATreverse(result);
}

/*}}}  */
/*{{{  static ATerm AFTaddPosInfoToEquSection(ATerm section) */

/**
	* Add positional information to an equation section
	*/

static ATerm AFTaddPosInfoToEquSection(ATerm section)
{
	ATerm w[2], lit, iter, list;
	ATermList eqs;

  if(AFTisEmptyEquSection(section))
    return section;

	if(!AFTisEquSection(section))
	  ATerror("Posinfo: expected equ-section, got %t\n", section);

	lit  = AFTgetEquSectionLit(section);
	posInfoLit(lit);
	w[0] = AFTgetEquSectionWS(section);
	posInfoWS(w[0]);
	list = AFTgetEquSectionEqList(section);

	if(!AFTisList(list))
		ATerror("not a list: %t\n", list);

	iter = AFTgetListIter(list);
  w[1] = AFTgetListWS(list);
	eqs  = AFTgetListElements(list);

	eqs  = AFTaddPosInfoToEqs(eqs);
	list = AFTbuildList(iter, w[1], eqs);
  section = AFTbuildEquSection(lit, w[0], list);

  return section;
}

/*}}}  */
/*{{{  ATerm AFaddPosInfoToModule(char *path, ATerm mod) */

/**
	* Add positional information to a module
	*/

ATerm AFaddPosInfoToModule(char *path, ATerm mod)
{
  ATerm lit[2], w[4], id, sections, eqs, abbrevs, trm;
	
  filename = ATmake("<str>", path);

  line = 1;
  col  = 0;
  pos  = 0;
  if(ATmatchTerm(mod, pattern_asfix_module, &lit[0], &w[0], &id, &w[1], 
  		 &sections, &w[2], &eqs, &w[3], &abbrevs)) {
    eqs = AFaddPosInfoToEqSection(eqs);
    return ATmakeTerm(pattern_asfix_module, lit[0], w[0], id, w[1], sections,
      	  	            w[2], eqs, w[3], abbrevs);
  } else if(ATmatchTerm(mod, pattern_asfix_term, &lit[0], &w[0], &lit[1],
          	    	       	&w[1], &id, &w[2], &trm, &w[3], &abbrevs)) {
    trm = AFTaddPosInfoToEquSection(trm);
    mod = ATmakeTerm(pattern_asfix_term, lit[0], w[0], lit[1], w[1],
											id, w[2], trm, w[3], abbrevs);
    return mod;
  }

  ATerror("this is not the asfix I know of: %t\n", mod);
  return NULL;
}

/*}}}  */
/*{{{  void AFinitPosInfo() */

void AFinitPosInfo()
{
	if(!inited) {
		inited = ATtrue;
		symbol_area = ATmakeAFun("area", 5, ATfalse);
		ATprotectAFun(symbol_area);
		label_pos  = ATparse("pos-info");
		ATprotect(&label_pos);
		ATprotect(&filename);
	}
}


/*}}}  */

