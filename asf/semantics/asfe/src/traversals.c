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

extern AFun list_var;
extern AFun fail_env;
extern ATerm pattern_asfix_noattrs;
extern ATerm pattern_asfix_attrs;
extern ATerm pattern_asfix_prod;
extern ATbool run_verbose;

/* is_traversal_prod
 *
 * Predicate to determine if a production has the "traverse" attribute
 */
ATbool is_traversal_prod(ATerm prod) 
{
	ATerm attrs;

	if(ATmatchTerm(prod,pattern_asfix_prod,
						 NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&attrs)) {

		if(ATmatchTerm(attrs,pattern_asfix_noattrs)) {
			return ATfalse;
		} else {
			ATermList list;
		
			if(ATmatchTerm(attrs,pattern_asfix_attrs,NULL,NULL,&list,NULL,NULL)) {
				for(;!ATisEmpty(list);list = ATgetNext(list)) {
					if(ATmatch(ATgetFirst(list),"l(\"traverse\")")) {
						return ATtrue;
					}
				}
			}
		}
	}

	return ATfalse;
}

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
	int traversed_pos = keep_layout ? 4 : 2;
	
	return ATelementAt(args, traversed_pos);
}

/* create_traversal_pattern
 *
 * input: an asfix appl.
 * output: an asfix appl with placeholders in both the prod and
 *         the args. 
 * 
 * note: the number and location of the placeholders depends on the
 *       type of traversal. The type of traversals is computed from
 *       the form of the production. 
 */
ATerm create_traversal_pattern(ATerm term)
{
	ATerm prod;
	ATermList symbols;
	ATerm symbol;
	ATerm name;
	ATerm traversed;
	ATerm tail;
	ATerm ws = ATparse("w(\"\")");
	ATerm arrow;
	ATerm id;
	ATerm attrs;
	ATerm placeholder = ATparse("<term>");
	ATermList args;
	int traversed_pos = keep_layout ? 4 : 2;
	int accumulated_pos = keep_layout ? 6 : 3;
	
	if(run_verbose) ATwarning("Creating traversal pattern: ");

	prod = asfix_get_appl_prod(term);
	args = asfix_get_appl_args(term);

	if(ATmatchTerm(prod,pattern_asfix_prod,&id,NULL,&symbols,NULL,&arrow,NULL,
								 &symbol,NULL,&attrs)) {

		if(ATmatch((ATerm) symbols,"[<term>,<term>,ql(\"(\"),<term>,<term>,<list>]",
							 &name,NULL,NULL,&traversed,&tail)) {

			if(symbol == traversed) { /* then it is a sort preserving traversal */
				if(run_verbose) ATwarning("transform pattern.\n");
				symbols = ATreplace(symbols,placeholder,4);
				prod = ATmakeTerm(pattern_asfix_prod,id,ws,symbols,ws,arrow,ws,
															placeholder,ws,attrs);
				args = ATreplace(args,placeholder,traversed_pos);
				term = ATmake("traversal(<term>)",AFmakeAppl(prod,args));

			} else { /* otherwise we have an analyzer */
				if(run_verbose) ATwarning("analyze pattern.\n");
				symbols = ATreplace(symbols,placeholder,4);
				args = ATreplace(args,placeholder,traversed_pos); /* traversed argument */
				prod = ATmakeTerm(pattern_asfix_prod,id,ws,symbols,ws,arrow,ws,
															symbol,ws,attrs);
				term = ATmake("analyzer(<term>)",AFmakeAppl(prod,args));
	
			}
		}
	}

	return term;
}

/* make_traversal_appl
 *
 * input: an appl and a traversal pattern (made by create_traversal_patten)
 * output: the traversal pattern instantiated by the symbol and the term 
 *         of the first argument.
 */
ATerm make_traversal_appl(ATerm appl, ATerm traversal)
{
  ATerm prod;
	ATermList args;
	ATerm sort; 
	ATerm newappl;
	ATerm travprod;
	ATerm tuple = NULL;

	/* kan netter */

	if(run_verbose) ATwarning("Generating traversal appl.\n");

	sort = AFgetProdSort(asfix_get_appl_prod(appl)); 
	
	if(ATmatch(traversal,"traversal(<term>)", &travprod)) {
		prod = asfix_get_appl_prod(travprod);
		prod = ATmakeTerm(prod, sort, sort);
		
		args = asfix_get_appl_args(travprod);
		args = (ATermList) ATmakeTerm((ATerm) args, appl);
		
		newappl = AFmakeAppl(prod,args);
		
		return newappl;
		
	} else if(ATmatch(traversal,"analyzer(<term>)",&travprod) || 
		        ATmatch(traversal,"combination(<term>,tuple(<term>))",&travprod, &tuple)) {
		prod = asfix_get_appl_prod(travprod);
		prod = ATmakeTerm(prod, sort);
		
		args = asfix_get_appl_args(travprod);
		args = (ATermList) ATmakeTerm((ATerm) args, appl);
		
		newappl = AFmakeAppl(prod,args);
	
		return newappl;
	}
	
	ATerror("Unknown traversal function type\n");
	return NULL;
}

/* change_traversal_appl
 *
 * Changes the second argument of the traversal pattern. This is used
 * as a value environment for traversals.
 */
ATerm change_traversal_appl(ATerm traversal, ATerm newarg)
{
	ATermList args;
	ATerm term;
	ATerm appl;
	ATerm tuple;

	if(ATmatch(traversal,"analyzer(<term>)", &appl)) {
		args = asfix_get_appl_args(appl);
		args = ATreplace(args, newarg, keep_layout ? 8 : 4);
		traversal = ATmake("analyzer(<term>)", asfix_put_appl_args(appl, args));	
	}
	if(ATmatch(traversal,"combination(<term>,tuple(<term>))",&appl,&tuple)) {
		args = asfix_get_appl_args(appl);
		args = ATreplace(args, newarg, keep_layout ? 8 : 4);
		traversal = ATmake("combination(<term>,tuple(<term>))",asfix_put_appl_args(appl,args),tuple);
	}
	
	return traversal;
}

/* choose_normalform
 *
 * depending on the type of traversal, constructs a normal form.
 * This function is used after the toplevel traversal prod returns.
 */
ATerm choose_normalform(ATerm term, ATerm traversal) 
{
	ATermList args;
	ATerm appl;
	ATerm tuple;
	ATerm second;
	ATerm firstsort, secondsort;
	ATerm ws;

	if(ATmatch(traversal,"traversal(<term>)", &appl)) {
		/* we return the tree */
		return term;
	}
	if(ATmatch(traversal,"analyzer(<term>)", &appl)) {
		/* we only return the accumulated value */
		args = asfix_get_appl_args(appl);
		return ATelementAt(args, keep_layout ? 8 : 4);
	}
	if(ATmatch(traversal,"combination(<term>,tuple(<term>))",&appl, &tuple)) {
		/* we take the current tree, and the accumulated value and create a nice
		 * tuple for it using the tuple template in traversal.
		 */
		ws = ATparse("w(\" \")");
		args = asfix_get_appl_args(appl);
		second = ATelementAt(args,keep_layout ? 8 : 4);
		firstsort = AFgetProdSort(asfix_get_appl_prod(term));
		secondsort = AFgetProdSort(asfix_get_appl_prod(second));
		return keep_layout ? ATmakeTerm(tuple,firstsort,secondsort,ws,term,ws,ws,second,ws) :
		                         ATmakeTerm(tuple,firstsort,secondsort,term,second);
	}

	ATerror("Unknown traversal type");
	return NULL;
}

/* get_first
 *
 * Projection function which abstracts from tuple layout using a tuple pattern
 * with placeholders.
 */
ATerm get_first(ATerm tuple, ATerm combination) 
{
	ATerm prod, ctuple, first, second;
	
	/* We extract the first element of the tuple using the template in the 
	 * combination argument 
	 */

	if(ATmatch(combination,"combination(<term>,tuple(<term>))",&prod, &ctuple)) {
		if(( keep_layout && ATmatchTerm(tuple,ctuple,NULL,NULL,NULL,&first,NULL,NULL,&second,NULL,NULL)) ||
			 (!keep_layout && ATmatchTerm(tuple,ctuple,NULL,NULL,&first,&second))) {
			return first;
		}
	}
	
	ATerror("Unable to retrieve first from tuple.\n");
	return NULL;
}

/* get_second
 *
 * Projection function which abstracts from tuple layout using a tuple pattern
 * with placeholders.
 */
ATerm get_second(ATerm tuple, ATerm combination)
{
	ATerm prod, ctuple, first, second, stub1, stub2;
	
	/* We extract the second element of the tuple using the template in 
	 * the combination argument
	 */
	
	if(ATmatch(combination,"combination(<term>,tuple(<term>))",&prod,&ctuple)) {
 		if(( keep_layout && ATmatchTerm(tuple,ctuple,NULL,NULL,NULL,&first,NULL,NULL,&second,NULL)) ||
			 (!keep_layout &&	ATmatchTerm(tuple,ctuple,NULL,NULL,&first,&second))) {
			return second;
		}
	}
	
	ATerror("Unable to retrieve second from tuple.\n");
	return NULL;
}

ATerm rewrite_traversal(ATerm trm, ATerm env, int depth, ATerm *traversal)
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
    } 
    else {
			/* check for a match */
			travtrm = make_traversal_appl(trm, *traversal);
			rewtrm = select_and_rewrite(travtrm, depth);
			
			if(ATisEqual(rewtrm, travtrm)) {
				/* if no match, traverse down to the children */
				args = (ATermList) asfix_get_appl_args(trm);
				newargs = rewrite_args_traversal(args,env,depth,traversal);
				rewtrm = (ATerm) asfix_put_appl_args(trm,newargs);
			}  else {
				if(is_analyzer(*traversal)) {
					/* We update the traversal with the rhs */
					*traversal = change_traversal_appl(*traversal, rewtrm);
					/* We just return the input to construct a well-formed term */
					rewtrm = newtrm;
				} 
				if(is_combination(*traversal)) {
					ATerm second;
					/* We retrieve the accumulator to update the traversal */
					second = get_second(rewtrm, *traversal);
					second = select_and_rewrite(second, depth + 1);
					*traversal = change_traversal_appl(*traversal, second);
					/* We retrieve the tree to construct a well-formed term */
					rewtrm = get_first(rewtrm,*traversal);
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

ATermList rewrite_args_traversal(ATermList args, ATerm env, int depth, ATerm *traversal)
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
																	ATerm *traversal)
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

