/*

    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 

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

*/
/*
  $Id$
 */

#include <stdio.h>
#include <stdlib.h>
#include <aterm2.h>
#include <AsFix.h>
#include <AsFix-access.h>
#include <AsFix2src.h>
#include <assert.h>
#include <deprecated.h>
#include "asfix_utils.h"
#include "evaluator.h"
#include "traversals.h"

extern ATerm pattern_asfix_noattrs;
extern ATerm pattern_asfix_attrs;
extern ATerm pattern_asfix_prod;
extern ATbool run_verbose;

/* select_traversed_arg
 *
 * input: a traversal appl
 * output: The first argument term of this appl. 
 *
 * note: This function depends on the quoted prefix syntax of traversal
 *       prods and the fact that the first argument is always traversed.
 */
ATerm select_traversed_arg(ATermList args)
{
	return ATelementAt(args, TRAVERSED_POS);
}

/* create_traversal_pattern
 *
 * input: an asfix appl.
 * output: a Traversal struct, containing the original traversal term
 *         and an indication if it is a transformer or an analyzer.
 * 
 */
Traversal create_traversal_pattern(ATerm term)
{
	ATerm prod;
	ATermList args;
	ATermList symbols;
	ATerm symbol;
	ATerm traversed;
	Traversal traversal;

	prod = asfix_get_appl_prod(term);
	args = asfix_get_appl_args(term);

	symbols = (ATermList) AFgetProdSymbols(prod);
	symbol = AFgetProdSymbol(prod);
	traversed = ATelementAt(symbols, TRAVERSED_SYMBOL_POS);
	
	traversal.type = ATisEqual(traversed, symbol) ? TRANSFORMER : ANALYZER;
	traversal.prod = prod;
	traversal.symbols = symbols;
	traversal.args = args;

	return traversal;
}

/* make_traversal_appl
 *
 * input: an appl and a traversal pattern (made by create_traversal_patten)
 * output: the traversal pattern instantiated by the symbol and the term 
 *         of the first argument.
 */
ATerm make_traversal_appl(ATerm appl, Traversal traversal)
{
  ATerm prod;
	ATermList args;
	ATerm sort; 
	ATerm newappl;
	ATermList symbols;

	sort = AFgetProdSymbol(asfix_get_appl_prod(appl)); 
	symbols = ATreplace(traversal.symbols, sort, TRAVERSED_SYMBOL_POS);
	prod = AFsetProdSymbols(traversal.prod, symbols);
	args = ATreplace(traversal.args, appl, TRAVERSED_POS);

	if(traversal.type == TRANSFORMER) {
		prod = AFsetProdSymbol(prod, sort);	
	}

	newappl = AFmakeAppl(prod,args);
	
	return newappl;
}

/* update_accumulator
 *
 * Changes the second argument of the traversal pattern. This is used
 * as a value environment for traversals.
 */
Traversal update_accumulator(Traversal traversal, ATerm newarg)
{
	assert(traversal.type == ANALYZER);

	traversal.args = ATreplace(traversal.args, newarg, ACCUMULATED_POS);
	
	return traversal;
}

/* choose_normalform
 *
 * depending on the type of traversal, constructs a normal form.
 * This function is used after the toplevel traversal prod returns.
 */
ATerm choose_normalform(ATerm term, Traversal traversal) 
{
	switch(traversal.type) {
	case TRANSFORMER:
		/* we just return the term */
		break;
	case ANALYZER:
		/* we only return the accumulated value */
		term = ATelementAt(traversal.args, ACCUMULATED_POS);
		break;
	default:
		ATerror("Unknown traversal type");
		break;
	}

	return term;
}

ATerm rewrite_traversal(ATerm trm, ATerm env, int depth, Traversal *traversal)
{
  ATerm newtrm, sym, rewtrm, travtrm;
  ATermList args, newargs;
  ATermList elems, newelems;

  if(asfix_is_appl(trm)) {
		if(asfix_is_bracket_func(trm)) {
			args = (ATermList) asfix_get_appl_args(trm);
			newargs = rewrite_args_traversal(args,env, depth, traversal);
      newtrm = ATgetFirst(ATgetNext(newargs));
      rewtrm = newtrm;
    } else {
			/* check for a match */
			travtrm = make_traversal_appl(trm, *traversal);
			rewtrm = select_and_rewrite(travtrm, depth);

			if(ATisEqual(rewtrm, travtrm)) {
				/* if no match, traverse down to the children */
				args = (ATermList) asfix_get_appl_args(trm);
				newargs = rewrite_args_traversal(args,env,depth,traversal);
        /* on the way back, we check for new redices */
				rewtrm = select_and_rewrite(asfix_put_appl_args(trm,newargs), depth);
			 
			} else { /* reduction occurred, we need postprocessing */

				if(traversal->type == ANALYZER) {
					/* We update the traversal with the rhs */
					*traversal = update_accumulator(*traversal, rewtrm);
					/* We just return the input to construct a well-formed term */
					rewtrm = trm;
				} 
			}
		}
  } else if(asfix_is_var(trm)) {
      rewtrm = v_lookup_plain(env, trm);
      if(!rewtrm)
	rewtrm = trm;
  } else if(asfix_is_list(trm)) {
    elems = (ATermList) asfix_get_list_elems(trm);
    sym = asfix_get_list_sym(trm);
    newelems = rewrite_elems_traversal(sym, elems, env, depth,  traversal); 
    rewtrm = (ATerm) asfix_put_list_elems(trm, (ATerm) newelems);
  }
  else {
    rewtrm = trm;
  }
  return rewtrm;
}

ATermList rewrite_args_traversal(ATermList args, ATerm env, int depth, 
																 Traversal *traversal)
{
  ATerm arg, newarg;
  ATermList newargs = ATempty;
  int len = ATgetLength(args);

  if(len > 32) {
    while(!ATisEmpty(args)) {
      arg = ATgetFirst(args);
      if(asfix_is_appl(arg) || asfix_is_var(arg) ||
         asfix_is_list(arg) || asfix_is_lex(arg))
        newarg = rewrite_traversal(arg,env, depth + 1, traversal);
      else
        newarg = arg;
      newargs = ATappend(newargs, newarg);
      args = ATgetNext(args);
    }
  } else {
    ATerm newarg_table[32];
    int i = 0;
    while(!ATisEmpty(args)) {
      arg = ATgetFirst(args);
      if(asfix_is_appl(arg) || asfix_is_var(arg) ||
         asfix_is_list(arg) || asfix_is_lex(arg)) {
				newarg_table[i] = rewrite_traversal(arg, env, depth + 1, traversal);
			} else {
        newarg_table[i] = arg;
			}
      args = ATgetNext(args);
      ++i;
    }
    assert(i==len);
    for(--i; i >= 0; i--)
      newargs = ATinsert(newargs,newarg_table[i]);
  }
  return newargs;
}


ATermList rewrite_elems_traversal(ATerm sym, ATermList elems, ATerm env, int depth,
																	Traversal *traversal)
{
  ATerm elem, newelem;
  ATermList newelems = ATempty;
  int len = ATgetLength(elems);

	/* <PO:opt> why not first do the first len-32 elements and then
     the last 32 using the 'fast' method below? */
  if(len >= 32) {
    while(!ATisEmpty(elems)) {
      elem = ATgetFirst(elems);
			if(asfix_is_list_var(elem)) {
				ATermAppl tuple = v_lookup_list(env, elem);
				assert(tuple);
				newelems = append_slice(newelems, tuple);
			} else {
				newelem = rewrite_traversal(elem, env, depth + 1, traversal);
        newelems = ATappend(newelems, newelem);
			}
      elems = ATgetNext(elems);
    }
  } else {
    ATerm newelem_table[32];
    int i = 0;
    while(!ATisEmpty(elems)) {
			elem = ATgetFirst(elems);
			if(asfix_is_list_var(elem)) {
				newelem_table[i] = (ATerm)v_lookup_list(env, elem);
				assert(newelem_table[i]);
			} else {
				newelem_table[i] = rewrite_traversal(elem, env, depth + 1, traversal);
			}
      elems = ATgetNext(elems);
			i++;
    }

    for(--i; i>=0; i--) {
      newelem = newelem_table[i];
      if(ATgetAFun((ATermAppl)newelem) == list_var) {
				if(keep_layout && v_is_empty_slice(newelem)) {
					newelems = skipWhitespace(newelems);
				} else {
					newelems = prepend_slice((ATermAppl)newelem, newelems);
				}
			} else {
				if(!(keep_layout && ATisEmpty(newelems) &&
						 (asfix_is_list_sep(newelem) || asfix_is_whitespace(newelem)))) {												newelems = ATinsert(newelems, newelem);
				}
			}
		}
  }

  return newelems;
}

