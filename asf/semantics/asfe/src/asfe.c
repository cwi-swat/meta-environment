/*{{{  file header */

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

/*}}}  */

/*{{{  asfe.c */

/*
   A first version of an INTERPRETER in ToolBus C.
   This program is written by Mark van den Brand.

   The interpreter has its own database in which per module the
   equations are stored plus all equations of the transitive
   closure of the imported modules. The equations are sorted on
   the outermost function symbol (ofs) of the left-hand side
   of the equation.

   equations_db = [[M_1,[Ofs_11,[Eq_111,...,Eq_11i]],
                        [Ofs_12,[Eq_121,...,Eq_12j]],
                        ...,
                        [Ofs_1k,[Eq_1k1,...,Eq_1kl]]],
                   ...,
                   [M_n,[Ofs_n1,[Eq_n11,...,Eq_n1q]],
                        ...,
                        [Ofs_np,[Eq_np1,...,Eq_npr]]]]
   When adding a new set of equations in the database with the
   function ``add_equations'' some layout is removed (the layout
   between the arguments of an ``appl'' and between the elements
   of a ``list''), the separators in the lists with separators
   is removed, and the lexicals are expanded to become lists of
   single characters. This is performed via the function
   ``remove_layout_from_equations''.
   The equations are sorted on ofs and stored in the database.

   Before the rewriting of a term starts he layout is removed,
   the separators in the lists with separators
   is removed, and the lexicals are expanded to become lists of
   single characters as well. Based on the module over which the
   term is to be reduced the appropriate set of rewrite rule is
   selected and assigned to ``active_rules''. A global variable
   which contains only the active rewrite rules.
   The rewriting is performed by the function ``interpret''.

   To be done or improved:
   1. Preprocessing, so to detected whether conditions
      introduce fresh variables, and modify the operator
      of the condition: ``='', ``!='', and ``=:''.
   2. Describe the semantics of the rewriter:
      a. Innermost rewriting.
      b. No new variables in ``!=''-condition.
      c. No instantiated and uninstantiated variables on
         the same side of a ``assignment-condition''.
      d. All rules are applied in arbitrary order.
      e. Defaults are always applied as last rules.
      f. General list matching mechanism.
   3. No hashing, sharing, or caching.
*/

/*}}}  */

/*{{{  includes */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <aterm2.h>
#include <AsFix.h>
#include <AsFix-access.h>
#include <AsFix2src.h>
#include <atb-tool.h>
#include <string.h>
#include <sys/times.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
#include <deprecated.h>

#include "preparation.h"
#include "asfe.tif.h"
#include "asfix_utils.h"
#include "asfe.h"
#include "memotable.h"

#include "traversals.h"
#ifdef TRAVERSALS
ATbool traversals_on = ATtrue;
#else
ATbool traversals_on = ATfalse;
#endif

#ifdef USE_TIDE
#include "eval-tide.h"
#endif

/*}}}  */
/*{{{  defines */

#define MAX_DEPTH 2000

#ifdef PROFILING
#define PROF_REWRITE		rewrite_steps++
#define TICK2SEC(t)		(((double)(t))/CLK_TCK)
#else
#define PROF_REWRITE
#endif

#ifdef USE_TIDE
#define TIDE_STEP(posinfo, env, depth) Tide_step(posinfo, env, depth)
#else
#define TIDE_STEP(posinfo, env, depth)
#endif

/*}}}  */
/*{{{  globals */

static unsigned rewrite_steps = 0;
ATerm tagCurrentRule = NULL;

ATbool run_verbose = ATfalse;

/* rewrite_error contains the first error encountered during evaluation.
 * this error is later sent to the ToolBus (or dumped to stderr in case of 
 * standalone evaluator)
 */
ATerm rewrite_error = NULL;

/*
 *  The argument vector: list of option letters, colons denote option
 *  arguments.  See Usage function, immediately below, for option
 *  explanation.
 */

ATerm fail_env;
ATerm posinfo;

AFun list_var, plain_var;
AFun traversal_afun, analyzer_afun, combination_afun, index_afun, tuple_afun;

ATerm equations_db = NULL;
static MemoTable memo_table = NULL;

static char error_buf[BUFSIZ];

static ATbool aborted = ATfalse;

/*}}}  */

/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */
/*{{{  void RWclearError() */

void RWclearError()
{
  static ATbool is_protected = ATfalse;

  if (!is_protected) {
    is_protected = ATtrue;
    rewrite_error = NULL;
    ATprotect(&rewrite_error);
  }

  rewrite_error = NULL;
}

/*}}}  */
/*{{{  void RWsetError(const char *message, ATerm subject) */

void RWsetError(const char *message, ATerm subject)
{
  if (rewrite_error == NULL) {
    RWclearError(); /* Protect rewrite_error if necessary */
    rewrite_error = ATmake("[<str>,<term>,<term>])", 
													 message, tagCurrentRule, subject);
  }
  aborted = ATtrue;
}

/*}}}  */
/*{{{  ATerm RWgetError() */

ATerm RWgetError()
{
  return rewrite_error;
}

/*}}}  */

/*{{{  void debugging(int conn, ATerm on) */

/**
 * Switch debugging on/off
 */

void debugging(int conn, ATerm on)
{
#ifdef USE_TIDE
  if(ATmatch(on, "on")) {
    /* Switch on debugging */
    fprintf(stderr, "switching on debugging!\n");
    Tide_connect();
  } else {
    /* Switch off debugging */
    fprintf(stderr, "switching off debugging.\n");
    Tide_disconnect();
  }
#else
  fprintf(stderr, "*** SORRY, NO DEBUGGING SUPPORT AVAILABLE "
					"(you might want to try configure --with-tide)\n");
#endif
}

/*}}}  */

/*{{{  ATerm v_lookup_plain(ATerm env, ATerm var) */

/**
	* Retrieve the value of a variable
	*/

ATerm v_lookup_plain(ATerm env, ATerm var)
{
  ATermList list = (ATermList)env;

  if(AT_getAnnotations(var) != NULL)
    var = AT_removeAnnotations(var);

  while(!ATisEmpty(list)) {
    ATermAppl tuple = (ATermAppl)ATgetFirst(list);
    if(ATisEqual(ATgetArgument(tuple, 0), var)) {
      assert(ATgetAFun(tuple) == plain_var);
      return ATgetArgument(tuple, 1);
    }

    list = ATgetNext(list);
  }

  return NULL;
}

/*}}}  */
/*{{{  ATermAppl v_lookup_list(ATerm env, ATerm var) */

/**
	* Retrieve the value of a list variable
	*/

ATermAppl v_lookup_list(ATerm env, ATerm var)
{
  ATermList list = (ATermList)env;

  while(!ATisEmpty(list)) {
    ATermAppl tuple = (ATermAppl)ATgetFirst(list);
    if(ATisEqual(ATgetArgument(tuple, 0), var)) {
      assert(ATgetAFun(tuple) == list_var);
      return tuple;
    }

    list = ATgetNext(list);
  }

  return NULL;
}

/*}}}  */
/*{{{  void v_print_slice(ATerm slice) */

void v_print_slice(ATerm slice)
{
  ATermList begin, end;
  assert(v_is_slice(slice));

  begin = v_get_first(slice);
  end = v_get_last(slice);

  ATwarning("\n\n[ ");

  if(!ATisEmpty(begin)) {
    ATwarning("%t", ATgetFirst(begin));
    begin = ATgetNext(begin);
  }

  for(; begin != end; begin = ATgetNext(begin)) {
    ATwarning(", %t", ATgetFirst(begin));
  }
	
  ATwarning(" ]\n\n");
  return;
}

/*}}}  */

/*{{{  ATbool v_is_bound(ATerm env, ATerm var) */

/**
	* See if a variable is bound.
	*/

ATbool v_is_bound(ATerm env, ATerm var)
{
  ATermList list = (ATermList)env;

  if(AT_getAnnotations(var) != NULL)
    var = AT_removeAnnotations(var);

  while(!ATisEmpty(list)) {
    ATermAppl tuple = (ATermAppl)ATgetFirst(list);
    if(ATisEqual(ATgetArgument(tuple, 0), var))
      return ATtrue;
    list = ATgetNext(list);
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATermList prepend_slice(ATermAppl slice, ATermList list) */

/**
	* Prepend a slice to the front of a list
	*/

ATermList prepend(ATermList first, ATermList last, ATermList list)
{
  ATermList temp;
  ATerm elem;

  if(first == last) {
    return list;
  }

  elem = ATgetFirst(first);
  temp = prepend(ATgetNext(first),last,list);
	
  if(keep_layout && ATisEmpty(temp) && 
     (asfix_is_list_sep(elem) || asfix_is_whitespace(elem))) {
    return ATempty;
  }

  temp = ATinsert(temp, elem);

  return temp;
}

ATermList prepend_slice(ATermAppl slice, ATermList list)
{
  ATermList first = v_get_first(slice);
  ATermList last  = v_get_last(slice);
	
  return prepend(first, last, list);
}

/*}}}  */
/*{{{  ATermList append_slice(ATermList list, ATermAppl slice) */

/**
	* Append a slice to a list
	*/

ATermList append_slice(ATermList list, ATermAppl slice)
{
  return ATconcat(list, prepend_slice(slice, ATempty));
}

/*}}}  */

/*{{{  ATerm exists(int cid, ATerm name) */

/* Functions to be called by the ToolBus:
   - ``exists'' checks whether the equations for a certain module are
     available.
   - ``create_equations_db'' to initialize the database.
   - ``clear_equations_db'' to re-initialize the database.
   - ``add_equations'' to add a set of equations for a certain module.
   - ``interpret'' to rewrite a given term over a given module.  */

ATerm equations_available(int cid, char *name)
{
  if(find_module(name))
    return ATmake("snd-value(eqs-available(<str>))", name);
  else
    return ATmake("snd-value(eqs-not-available(<str>))", name);
}

/*}}}  */
/*{{{  void add_equations(int cid, char *modname, ATerm equs) */

/* The procedure ``add_equations'' takes care of adding a new list
   of equations that is added to the internal database. The arguments
   of this function are a module name and a list of equations.
   Before this list of equations is added to the database some
   preprocessing is needed.
   Layout and list separators are removed, and the lexicals are
   expanded to a list of lexical characters.
*/
void add_equations(int cid, char *modname, ATerm equs)
{
  ATermList newequs;
  int l;

  if(run_verbose) {
    ATwarning("preparing equations...\n");
  }
  newequs = RWprepareEqs((ATermList) equs);
  l = ATgetLength(newequs);
	
  enter_equations(modname, newequs);

  if(run_verbose) {
    ATwarning("Processing %d equations of module %s\n",l,modname);
  }

}


/*}}}  */
/*{{{  void remove_equations(int cid, char *modname) */

void remove_equations(int cid, char *modname)
{
  if(run_verbose) {
    ATwarning("removing equations for module: %s\n", modname);
  }

  delete_equations(modname);
}

/*}}}  */
/*{{{  ATerm interpret(int cid,ATerm modname, ATerm trm) */

/* The function ``interpret'' recieves a module name and
   the string (term) that has to be written within the
   context of the given module.
   1. The term is preprocessed. The abbreviations are expanded.
      Next the layout and separators are
      removed and lexicals are expanded to list of lexical
      characters.
   2. The appropriate set of equations is actived this is
      done be retrieving from the equation database the
      equations over the given module and assign the list
      of equations to the global variable ``active_rules''.
   3. The term is rewritten via ``rewrite'' with an empty
      variable environment.
   4. The result of rewriting is processed in order to
      be visualized: layout and list separators are added and
      the list of lexical characters are mapped into lexicals
      again. */

ATerm interpret(int cid, char *modname, ATerm trm)
{
	ATerm result = evaluator(modname, trm);

	if (RWgetError() == NULL) {
    return ATmake("snd-value(rewrite-result(<term>))", ATBpack(result));
  } else {
    return ATmake("snd-value(rewrite-errors([<term>]))", RWgetError());
  }
}

ATerm evaluator(char *name, ATerm term)
{
  ATerm result, original_term = term;
  struct tms start, rewriting;

#ifdef PROFILING
  clock_t user, system;
#endif

  term = ATremoveAllAnnotations(term);
  term = asfix_get_term(term);
  term = RWprepareTerm(term);

  rewrite_steps = 0;
  RWclearError();
  tagCurrentRule = NULL;
	memo_table = MemoTableCreate();
  aborted = ATfalse;

  select_equations(name);
	
  if(run_verbose) {
    ATwarning("rewriting...\n");
  }

  times(&start);
  result = rewrite(term,(ATerm) ATempty, 0);
  times(&rewriting);

  result = RWrestoreTerm(result);
  result = asfix_put_term(original_term,result);

	MemoTableDestroy(memo_table);

#ifdef PROFILING
  if(run_verbose) {
    ATwarning("rewriting took %d rewrite steps.\n", rewrite_steps);
  }
  user = rewriting.tms_utime - start.tms_utime;
  system = rewriting.tms_stime - start.tms_stime;
  if(run_verbose) {
    ATwarning("rewriting: %f user, %f system (%f steps/sec)\n",
							TICK2SEC(user), TICK2SEC(system),
							((double)rewrite_steps)/(TICK2SEC(user)+TICK2SEC(system)));
  }
#endif

	return result;
}


/*{{{  ATbool no_new_vars(ATerm trm,ATermList env) */

/* A predicate which checks whether a term introduces new
   variables. This functions is used when dealing with the
   conditions of equations. */
ATbool no_new_vars(ATerm trm, ATerm env)
{
  ATerm arg;
  ATermList args;
  ATbool existing;

  if(asfix_is_var(trm)) {
    if(v_is_bound(env,trm))
      return ATtrue;
    else
      return ATfalse;
  }
  else if(asfix_is_appl(trm)) {
    existing = ATtrue;
    args = (ATermList) asfix_get_appl_args(trm);
    while(existing && !ATisEmpty(args)) {
      arg = ATgetFirst(args);
      existing = no_new_vars(arg,env);
      args = ATgetNext(args);
    };
    return existing;
  }
  else if(asfix_is_list(trm)) {
    existing = ATtrue;
    args = (ATermList) asfix_get_list_elems(trm);
    while(existing && !ATisEmpty(args)) {
      arg = ATgetFirst(args);
      existing = no_new_vars(arg,env);
      args = ATgetNext(args);
    };
    return existing;
  } else
    return ATtrue;
}


/*}}}  */
/*{{{  ATermList arg_matching(env, arg1, arg2, conds, orgargs1, orgargs2, lp, depth) */

/* Function which tries to match two arguments.
   First it is checked whether one of the arguments is a variable
   and the other is not. If one is a variable it is checked
   whether it is a fresh one. If the variable is in the environment
   its value is retrieved and compared with the other argument.
   If they are equal the matching can proceed otherwise the matching
   must be aborted.  If the variable is a fresh one it is
   stored in the variable environment
   with the term of the other argument.

   If both arguments are ``appls'' their arguments should match.

   If both arguments are ``lists'' their elements shoudl match.

   Otherwise the arguments should be equal. If the do not
   match the matching should be aborted. */

ATerm arg_matching(ATerm env, ATerm arg1, ATerm arg2,
									 ATermList conds,
									 ATermList orgargs1, ATermList orgargs2,
									 ATerm lhs_posinfo, int depth)
{
  ATerm trm, prod1, prod2, sym1, sym2;
  ATermList args1, args2;
  ATermList elems1, elems2;
  ATerm newenv = env;

  if(run_verbose) {
    ATwarning("%t:matching arguments: %t\nwith\n%t\n\n",asource(tagCurrentRule), arg1,arg2);
  }

  if(!keep_layout && isAsFixEqual(arg1,arg2)) {
    /* we don't test for equality with whitespace, because we might need some
     * skipping in case of lists. */
    return args_matching(newenv,conds,orgargs1,orgargs2,lhs_posinfo,depth);
  } else if(asfix_is_appl(arg1) && asfix_is_appl(arg2)) {
    prod1 = asfix_get_appl_prod(arg1);
    prod2 = asfix_get_appl_prod(arg2);
    if(ATisEqual(prod1,prod2)) {
      args1 = (ATermList) asfix_get_appl_args(arg1);
      args2 = (ATermList) asfix_get_appl_args(arg2);
      args1 = ATconcat(args1,orgargs1);
      args2 = ATconcat(args2,orgargs2);

      newenv = (ATerm) args_matching(newenv, conds, args1, args2,
																		 lhs_posinfo, depth);
    }
    else {
      return fail_env; 
      if(run_verbose) { 
				ATwarning("*** fail_env on line %d\n", __LINE__); 
      }
    }
  } else if(asfix_is_list(arg1) && asfix_is_list(arg2)) {
    ATbool ok = ATfalse;
    sym1 = asfix_get_list_sym(arg1);
    sym2 = asfix_get_list_sym(arg2);
    if(asfix_is_iter(sym1) && asfix_is_iter(sym2)) {
      ok = (asfix_get_iter_sort(sym1) == asfix_get_iter_sort(sym2));
    } else if(asfix_is_itersep(sym1) && asfix_is_itersep(sym2)) {
      ok = (asfix_get_itersep_sort(sym1) == asfix_get_itersep_sort(sym2));
      ok = ok && (asfix_get_itersep_sep(sym1) == asfix_get_itersep_sep(sym2));
    }

    if(ok) {
      elems1 = (ATermList) asfix_get_list_elems(arg1);
      elems2 = (ATermList) asfix_get_list_elems(arg2);

      newenv = list_matching(sym1,newenv,elems1,elems2,
														 conds,orgargs1,orgargs2, lhs_posinfo, depth);
    }
    else {
      newenv = fail_env; 
      if(run_verbose) { 
				ATwarning("*** fail_env on line %d\n", __LINE__); 
      }
    }
  } else if(asfix_is_var(arg1)) {
    trm = v_lookup_plain(newenv, arg1);
    if(trm) {
      if(isAsFixEqual(arg2,trm)) {
        newenv = args_matching(newenv, conds, orgargs1, orgargs2,
															 lhs_posinfo, depth);
      } else {
        newenv = fail_env; 
				if(run_verbose) { 
					ATwarning("*** fail_env on line %d\n", __LINE__); 
				}
      }
    }
    else {
      if(AT_getAnnotations(arg1) != NULL)
        arg1 = AT_removeAnnotations(arg1);

      newenv = v_put(newenv,arg1,arg2);
      newenv = args_matching(newenv, conds, orgargs1, orgargs2,
														 lhs_posinfo, depth);
    }
  } else { /* terms are not any of the above, and not equal */
    if(keep_layout) {
      /* we didn't test for equality if rewriting with ws, so do it now */
      /* NOTE: is this still necessary? */
      if(isEqualModuloWhitespace(arg1,arg2)) {
				return args_matching(newenv, conds, orgargs1, orgargs2,
														 lhs_posinfo, depth);
      } else {
				newenv = fail_env; 
				if(run_verbose) { 
					ATwarning("*** fail_env on line %d\n", __LINE__); 
				}
      }
    } else { 
      newenv = fail_env; 
      if(run_verbose) { 
				ATwarning("*** fail_env on line %d\n", __LINE__); 
      }
    }
  }
  return newenv;
}

/*}}}  */
/*{{{  ATerm args_matching(env, conds, args1, args2) */

/* Two arguments lists are matched. As long as there are arguments
   to be matched this is performed if both argument lists are empty
   the conditions are inspected. */
ATerm args_matching(ATerm env, ATermList conds,
                    ATermList args1, ATermList args2, 
										ATerm lhs_posinfo, int depth)
{
  ATerm arg1, arg2;
  ATerm newenv = env;

  if(!ATisEmpty(args1)) {
    arg1 = ATgetFirst(args1);
    args1 = ATgetNext(args1);
    if(!ATisEmpty(args2)) {
      arg2 = ATgetFirst(args2);
      args2 = ATgetNext(args2);
      newenv = arg_matching(newenv,arg1,arg2,conds,args1,args2,
														lhs_posinfo, depth);
    }
    else {
      newenv = fail_env; 
      if(run_verbose) { 
				ATwarning("*** fail_env on line %d\n", __LINE__); 
      }
    }
  }
  else {
    if(!ATisEmpty(args2)) {
      newenv = fail_env; 
      if(run_verbose) { 
				ATwarning("*** fail_env on line %d\n", __LINE__); 
      }
    } else {
      if(lhs_posinfo) {
				TIDE_STEP(lhs_posinfo, newenv, depth);
      }
      newenv = conds_satisfied(conds, newenv, depth);
    }
  }

  return newenv;
}

/*}}}  */
/*{{{  ATbool compare_lists(ATermAppl tuple, ATermList list) */

ATbool compare_lists(ATermAppl tuple, ATermList list)
{
  ATermList first, last;

  assert(ATgetAFun(tuple) == list_var);
  first  = v_get_first(tuple);
  last   = v_get_last(tuple);

  while(first != last) {
    ATerm elem1, elem2;

    if(ATisEmpty(list))
      return ATfalse;

    elem1 = ATgetFirst(first);
    elem2 = ATgetFirst(list);

    if(!isAsFixEqual(elem1, elem2))
      return ATfalse;

    first = ATgetNext(first);
    list  = ATgetNext(list);
  }

  return ATisEmpty(list);
}

/*}}}  */
/*{{{  ATermList compare_sub_lists(ATermAppl elems1, ATermList elems2) */

ATermList compare_sub_lists(ATermAppl tuple, ATermList elems2)
{
  ATerm elem1, elem2;
  ATermList first, last;
  ATbool match = ATtrue;

  assert(ATgetAFun(tuple) == list_var);
  first = v_get_first(tuple);
  last  = v_get_last(tuple);

  if(keep_layout) {
    first = skipWhitespace(first);
    elems2 = skipWhitespace(elems2);

    assert(isValidSlice(first, last));
    assert(isValidList(elems2));
  }

  while(first != last && match) {
    if(keep_layout) {
      first = skipWhitespace(first);
      assert(isValidSlice(first, last));
    }

    elem1 = ATgetFirst(first);
    if(!ATisEmpty(elems2)) {
      elem2 = ATgetFirst(elems2);
      match = isAsFixEqual(elem1,elem2);

      if(keep_layout) {
				elems2 = skipWhitespace(ATgetNext(elems2));
				assert(isValidList(elems2));
      } else {
				elems2 = ATgetNext(elems2);
      }
    }
    else {
      match = ATfalse;
    }
		
    first = ATgetNext(first);
  }
	
  if(match) {
    assert(isValidList(elems2));
    return elems2;
  } else {
    return NULL;
  }
}


/*}}}  */
/*{{{  ATermList sub_list_matching(ar,sym,env,elem,elems1,elems2,conds,args1,args2,lp,d) */

/* sub_list_matching
 *
 * Tries different sizes for a single list variable.
 */
ATerm sub_list_matching(ATerm asym, ATerm env, ATerm elem,
                        ATermList elems1, ATermList elems2,
                        ATermList conds,
                        ATermList args1, ATermList args2,
												ATerm lhs_posinfo, int depth)
{
  ATerm subenv, newenv;
  ATermList last;

  if(AT_getAnnotations(elem) != NULL)
    elem = AT_removeAnnotations(elem);

  if(asfix_is_star_var(elem)) {
    /* try to match with zero elements for star variable */
    newenv = v_put_list(env, elem, ATempty, ATempty);
    subenv = list_matching(asym,newenv,elems1,elems2,conds,args1,args2,
													 lhs_posinfo, depth);
  } else {
    /* if plus variable, do not try to match with zero elements */
    subenv = fail_env; 
    if(run_verbose) { 
      ATwarning("*** fail_env on line %d\n", __LINE__); 
    }
  }

  if(keep_layout) {
    /* Make sure we begin at a regular element */
    elems2 = skipWhitespace(elems2);
    assert(isValidList(elems2));
  }

  /* If the star variable didn't match or we have a plus variable
   * we continue matching with increasing length while possible.
   */
	 
  if(!ATisEmpty(elems2)) {
    for(last = ATgetNext(elems2); /* create a singleton */           
				is_fail_env(subenv); 
				last = ATgetNext(keep_layout ? skipWhitespace(last) : last)) /* add an elem */ 
      {
				assert(isValidSlice(elems2, last));  
				newenv = v_put_list(env, elem, elems2, last);
				subenv = list_matching(asym,newenv,elems1,last,conds,args1,args2,
															 lhs_posinfo, depth);

				if(ATisEmpty(last)) {
					/* the entire list has been tried now */
					break;
				}
      }
  }
	
  return subenv;
}

/*}}}  */
/*{{{  ATermList list_matching(ar,sym,env,elems1,elems2,conds,args1,args2,lp,d) */

ATerm list_matching(ATerm sym,
                    ATerm env,ATermList elems1, ATermList elems2,
                    ATermList conds, ATermList args1, ATermList args2,
										ATerm lhs_posinfo, int depth)
{
  ATerm elem1, elem2 = NULL;
  ATerm newenv;
  ATerm newarg1, newarg2;
  ATermList newargs1, newargs2;

  assert(isValidList(skipWhitespace(elems1)));
  assert(isValidList(skipWhitespace(elems2)));

  if(keep_layout) {
    elems1 = skipWhitespace(elems1);
    assert(isValidList(elems1));		
    elems2 = skipWhitespace(elems2);
    assert(isValidList(elems2));
  }
	

  if(!ATisEmpty(elems1)) {
    elem1 = ATgetFirst(elems1);
		
    if(ATgetLength(elems1) == 1) {
      if(asfix_is_list_var(elem1)) {
				ATermAppl trms = v_lookup_list(env, elem1);
        if(trms) {
          if(compare_lists(trms, elems2)) {
            newenv = args_matching(env, conds, args1, args2,
																	 lhs_posinfo, depth);
					} else {
            newenv = fail_env; 
						if(run_verbose) { 
							ATwarning("*** fail_env on line %d\n", __LINE__); 
						}
					}
        } else { /* TdictGet(env,elem1) == Tfalse */
          if(asfix_is_plus_var(elem1) && ATisEmpty(elems2)) {
						newenv = fail_env; 
						if(run_verbose) { 
							ATwarning("*** fail_env on line %d\n", __LINE__); 
						}
					} else {
            if(AT_getAnnotations(elem1) != NULL)
              elem1 = AT_removeAnnotations(elem1);
						
						if(keep_layout) {
							elems2 = skipWhitespace(elems2);						
							assert(isValidList(elems2));
						}
						
						if(!ATisEmpty(elems2)) {
							elem2 = ATgetFirst(elems2);
						}
						
						assert(isValidSlice(elems2, ATempty));
						newenv = v_put_list(env, elem1, (ATerm)elems2, ATempty);
						newenv = args_matching(newenv, conds, args1, args2,
																	 lhs_posinfo, depth);
					}
        }
      } else { /*is_list_var(elem1) == Tfalse */
        if(ATgetLength(elems2) == 1) {
          elem2 = ATgetFirst(elems2);
          newenv = arg_matching(env, elem1, elem2, conds, args1, args2,
																lhs_posinfo, depth);
        } else {
          newenv = fail_env; 
					if(run_verbose) { 
						ATwarning("*** fail_env on line %d\n", __LINE__); 
					}
				}
      }
    } else { /* TlistSize(elems1) != 1 */
      elems1 = ATgetNext(elems1);
			
      if(asfix_is_list_var(elem1)) {
				ATermAppl trms = v_lookup_list(env, elem1);
        if(trms) {
          elems2 = compare_sub_lists(trms,elems2);
          if(elems2) {
            newenv = list_matching(sym, env, elems1, elems2, conds,
																	 args1, args2, lhs_posinfo, depth);
          } else {
            newenv = fail_env; 
						if(run_verbose) { 
							ATwarning("*** fail_env on line %d\n", __LINE__); 
						}
					}
        } else  {/* TdictGet(env,elem1) == Tfalse */
          newenv = sub_list_matching(sym,env,elem1,elems1,elems2,
                                     conds, args1, args2, lhs_posinfo, depth);
				}
      } else { /*is_list_var(elem1) == Tfalse */
				if(keep_layout) {
					elems2 = skipWhitespace(elems2);
					assert(isValidList(elems2));
				}
        if(!ATisEmpty(elems2)) {
          elem2 = ATgetFirst(elems2);
          
					if(keep_layout) {
						elems2 = skipWhitespace(ATgetNext(elems2));
						assert(isValidList(elems2));
					} else {
						elems2 = ATgetNext(elems2);
					}
					
          newarg1 = asfix_make_list(sym,elems1); /* contains the vars */
          newarg2 = asfix_make_list(sym,elems2);
          newargs1 = ATinsert(args1, newarg1);
          newargs2 = ATinsert(args2, newarg2);
          newenv = arg_matching(env, elem1, elem2, conds, newargs1, newargs2,
																lhs_posinfo, depth);
        } else {
					newenv = fail_env; 
					if(run_verbose) { 
						ATwarning("*** fail_env on line %d\n", __LINE__); 
					}
				}
      }
    }
  } else {/* !elems1 */
    if(!ATisEmpty(elems2)) {
      newenv = fail_env; 
      if(run_verbose) { 
				ATwarning("*** fail_env on line %d\n", __LINE__); 
      }
    } else {
      newenv = args_matching(env, conds, args1, args2,
														 lhs_posinfo, depth);
    }
  }
	
  return newenv;
}

/*}}}  */

/*{{{  ATermList conds_satisfied(ATermList conds, ATermList env, int depth) */

/* Function ``conds_satisfied'' check whether the conditions
   of an equation can be satisfied.
   Remark access functions needed to retrieve the operator,
   lhs, and rhs. */
ATerm conds_satisfied(ATermList conds, ATerm env, int depth)
{
  ATerm cond;
  ATerm lhs, rhs, lhstrm, rhstrm;
  ATerm newenv = env;

  if(!ATisEmpty(conds)) {
    cond = ATgetFirst(conds);
		
    conds = ATgetNext(conds);
    lhs = AFTgetCondLHS(cond);
    rhs = AFTgetCondRHS(cond);
    if(AFTisEqualityCond(cond)) {
      /* <PO:opt> couldn't we determine this statically? */
      if(no_new_vars(lhs,newenv)) {
				TIDE_STEP(ATgetAnnotation(lhs, posinfo), newenv, depth);
        lhstrm = rewrite(lhs, newenv, depth+1);
				TIDE_STEP(ATgetAnnotation(rhs, posinfo), newenv, depth);
        if(no_new_vars(rhs,newenv)) {
          rhstrm = rewrite(rhs, newenv, depth+1);
					TIDE_STEP(ATgetAnnotation(cond, posinfo), newenv, depth);
					if(isAsFixEqual(lhstrm,rhstrm)) {
						newenv = conds_satisfied(conds, newenv, depth);
					} else {
            newenv = fail_env; 
						if(run_verbose) { 
							ATwarning("*** fail_env on line %d\n", __LINE__); 
						}
					}
        }
        else {
					TIDE_STEP(ATgetAnnotation(cond, posinfo), newenv, depth);
          newenv = arg_matching(newenv,rhs,lhstrm,conds,ATempty,ATempty,
																NULL, depth);
        }
      }
      else {
				TIDE_STEP(ATgetAnnotation(lhs, posinfo), newenv, depth);
				TIDE_STEP(ATgetAnnotation(rhs, posinfo), newenv, depth);
        if(no_new_vars(rhs,newenv)) {
          rhstrm = rewrite(rhs, newenv, depth+1);
					TIDE_STEP(ATgetAnnotation(cond, posinfo), newenv, depth);
          newenv = arg_matching(newenv,lhs,rhstrm,conds,ATempty,ATempty,
																NULL, depth);
        }
        else {
					RWsetError("Both sides of condition introduce new variables.", 
										 cond);
          newenv = fail_env; 
					if(run_verbose) { 
						ATwarning("*** fail_env on line %d\n", __LINE__); 
					}
        }
      }
    }
    else {
      if(!no_new_vars(lhs,newenv) || !no_new_vars(rhs,newenv)) {
        RWsetError("Negative condition introduces new variables.",cond);
        newenv = fail_env; 
				if(run_verbose) { 
					ATwarning("*** fail_env on line %d\n", __LINE__); 
				}
      }
      else {
				TIDE_STEP(ATgetAnnotation(lhs, posinfo), newenv, depth);
        lhstrm = rewrite(lhs, newenv, depth+1);
				TIDE_STEP(ATgetAnnotation(rhs, posinfo), newenv, depth);
        rhstrm = rewrite(rhs, newenv, depth+1);
				TIDE_STEP(ATgetAnnotation(cond, posinfo), newenv, depth);
        if(isAsFixEqual(lhstrm,rhstrm)) {
          newenv = fail_env; 
					if(run_verbose) { 
						ATwarning("*** fail_env on line %d\n", __LINE__); 
					}
        } else {
          newenv = conds_satisfied(conds, newenv, depth);
				}
      }
    }
  }

  return newenv;
}


/*}}}  */
/*{{{  ATerm apply_rule(ATerm trm, int depth) */

/* The function ``apply_rule'' tries to rewrite a term
   given a list of equations. As long as there is no
   success a new equation is tried. The arguments of
   the term and the arguments of the left hand side of
   the equation are matched.
*/

ATerm apply_rule(ATerm trm, int depth)
{
  ATerm top_ofs, first_ofs;
  ATermList termargs, equargs, tmpargs;
  ATerm env;
  ATermList conds;
  equation_entry *entry = NULL;

  top_ofs = asfix_get_appl_ofs(trm);
  termargs = (ATermList) asfix_get_appl_args(trm);

  tmpargs = termargs;
  while(!ATisEmpty(tmpargs) && !asfix_is_appl(ATgetFirst(tmpargs)))
    tmpargs = ATgetNext(tmpargs);

  if(!ATisEmpty(tmpargs)) {
    first_ofs = asfix_get_appl_ofs(ATgetFirst(tmpargs));

    /* <PO:opt> we could build a table for each ofs in the
       specification, containing an entry for each first_ofs.
       Each entry consists of all the equations for this combination.
    */
    while((entry = find_equation(entry, top_ofs, first_ofs))) {

      if(run_verbose)
				ATwarning("Trying equation: %t.\n",asource(entry->tag));

      tagCurrentRule = entry->tag;

      conds = entry->conds;
      equargs = (ATermList) asfix_get_appl_args(entry->lhs);

      env = args_matching((ATerm) ATempty, conds, equargs, termargs,
													ATgetAnnotation(entry->lhs, posinfo), depth);
      tagCurrentRule = entry->tag;

      if(!is_fail_env(env)) {
				TIDE_STEP(ATgetAnnotation(entry->rhs, posinfo), env, depth);
				if(run_verbose) {
					ATwarning("Equation %t was successful.\n",asource(entry->tag));
				}

        rewrite_steps++;
        return (ATerm) make_cenv(entry->rhs, env);
      } else if(run_verbose) {
				ATwarning("Equation %t failed.\n",asource(entry->tag));
      }
			
    }
  }

  while((entry = find_equation(entry, top_ofs, (ATerm) ATempty))) {

    if(run_verbose)
      ATwarning("Trying equation: %t.\n",asource(entry->tag));

    tagCurrentRule = entry->tag;

    conds = entry->conds;
    equargs = (ATermList) asfix_get_appl_args(entry->lhs);

    env = args_matching((ATerm) ATempty, conds, equargs, termargs,
												ATgetAnnotation(entry->lhs, posinfo), depth);
    tagCurrentRule = entry->tag;

    if(!is_fail_env(env)) {
      TIDE_STEP(ATgetAnnotation(entry->rhs, posinfo), env, depth);
      if(run_verbose) {
				ATwarning("Equation: %t was successful.\n",asource(entry->tag));
      }

      rewrite_steps++;
      return (ATerm) make_cenv(entry->rhs, env);
    } else if(run_verbose) {
      ATwarning("Equation %t failed.\n",asource(entry->tag));
    }
  }
	
  return (ATerm) make_cenv(trm, fail_env);
}

/*}}}  */
/*{{{  ATerm select_and_rewrite(ATerm trm, int depth) */

/* The function ``select_and_rewrite'' selects the
   the set of rewrite rules from the active rules and
   tries to rewrite the term via the function ``apply_rule''.
*/

ATerm select_and_rewrite(ATerm trm, int depth)
{
  ATerm newtrm, complexenv;
  ATerm env;

  complexenv = apply_rule(trm, depth);
  env = get_env((ATermList) complexenv);
  if(!is_fail_env(env)) {
    newtrm = get_term((ATermList) complexenv);
    trm = rewrite(newtrm, env, depth+1);
  }

  return trm;
}


/*}}}  */
/*{{{  ATermList rewrite_args(ATermList args, ATerm env, int depth) */

/* The list of arguments is rewritten and a new argumentlist
   is constructed. */

ATermList rewrite_args(ATermList args, ATerm env, int depth)
{
  ATerm arg, newarg;
  ATermList newargs = ATempty;
  int len = ATgetLength(args);

  if(len > 32) {
    while(!ATisEmpty(args)) {
      arg = ATgetFirst(args);
      if(asfix_is_appl(arg) || asfix_is_var(arg) ||
         asfix_is_list(arg) || asfix_is_lex(arg)) {
        newarg = rewrite(arg, env, depth+1);
      } else {
        newarg = arg;
      }
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

				newarg_table[i] = rewrite(arg, env, depth+1);
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

/*}}}  */
/*{{{  ATermList rewrite_elems(ATerm sym, ATermList elems, ATerm env, int depth) */

/* The list of elements is rewritten and a new elementlist
   is constructed. */

ATermList rewrite_elems(ATerm sym, ATermList elems, ATerm env, int depth)
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
				if(keep_layout && v_is_empty_slice(tuple)) {
					newelems = skipWhitespace(newelems);
					assert(isValidList(newelems));
				} else {
					newelems = append_slice(newelems, tuple);
				}
      } else {
				newelem = rewrite(elem, env, depth+1);
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
				if (newelem_table[i] == NULL) {
					RWsetError("variable not initialized", elem);
					return NULL;
				}
      } else {
				newelem_table[i] = rewrite(elem, env, depth+1);
      }
      elems = ATgetNext(elems);
      i++;
    }

    for(--i; i>=0; i--) {
      newelem = newelem_table[i];
      if(ATgetAFun((ATermAppl)newelem) == list_var) {

				if(keep_layout && v_is_empty_slice(newelem)) {
					newelems = skipWhitespace(newelems);
					assert(isValidList(newelems));
				} else {
					assert(isValidList(skipWhitespace(newelems)));
					newelems = prepend_slice((ATermAppl)newelem, newelems);
					assert(isValidList(newelems));
				}
      } else {
				if(!(keep_layout && ATisEmpty(newelems) &&
						 (asfix_is_list_sep(newelem) || asfix_is_whitespace(newelem)))) {
					newelems = ATinsert(newelems, newelem);
					assert(isValidList(skipWhitespace(newelems)));
				}
      }
    }
  }

  return newelems;
}

/*}}}  */
/*{{{  ATerm rewrite(ATerm trm, ATerm env, int depth) */

/* The core function. It is checked whether the term
   is an application, a variable, or a list. And the
   appropriate actions are performed.
   For non-constant functions the arguments should first
   be rewritten, conform the innermost reduction strategy.
   The resulting term can then be rewritten.
   REMARK: comments should be improved.
*/

ATerm rewrite(ATerm trm, ATerm env, int depth)
{
  ATerm newtrm, sym, rewtrm;
  ATermList args, newargs;
  ATermList elems, newelems;

  if (aborted) {
    return trm;
  }

  if (depth > MAX_DEPTH) {   
    sprintf(error_buf, "maximum stack depth (%d) exceeded.", MAX_DEPTH);
    RWsetError(error_buf, (ATerm)ATempty);
    return trm;
  }

  if(asfix_is_appl(trm)) {
    args = (ATermList) asfix_get_appl_args(trm);
    newargs = rewrite_args(args, env, depth);
    
		if(asfix_is_bracket_func(trm)) { /* bracket function */
      newtrm = ATgetFirst(keep_layout ? 
													skipWhitespace(ATgetNext(newargs)) :
													ATgetNext(newargs));
      rewtrm = newtrm;

    } else if(traversals_on && AFisTraverseAppl(trm)) {
      Traversal traversal;

      if(run_verbose) {
				ATwarning("Traversal...\n");
			}
			
			if (AFisMemoAppl(trm)) { /* traversal and memo function */
				newtrm = (ATerm) asfix_put_appl_args(trm,newargs);
				assert(memo_table != NULL);
				rewtrm = MemoTableLookup(memo_table, newtrm);

				if(!rewtrm) {
					traversal = create_traversal_pattern(newtrm); 

					newtrm    = select_traversed_arg(newargs);
					rewtrm    = rewrite_traversal(newtrm, (ATerm) ATempty, depth, &traversal);
					rewtrm    = choose_normalform(rewtrm, traversal);
					memo_table = MemoTableAdd(memo_table, newtrm, rewtrm);
				}
			} else { /* traversal, not memo function */
				newtrm    = (ATerm) asfix_put_appl_args(trm,newargs);

				traversal = create_traversal_pattern(newtrm); 

				newtrm    = select_traversed_arg(newargs);
				rewtrm    = rewrite_traversal(newtrm, (ATerm) ATempty, depth, &traversal);
				rewtrm    = choose_normalform(rewtrm, traversal);
			}
		} else if (AFisMemoAppl(trm)) { /* memo, not traversal function */
			newtrm = (ATerm) asfix_put_appl_args(trm,newargs);
			assert(memo_table != NULL);
			rewtrm = MemoTableLookup(memo_table, newtrm);
			
			if(!rewtrm) {
				rewtrm = select_and_rewrite(newtrm,depth);
				memo_table = MemoTableAdd(memo_table, newtrm, rewtrm);
			}
    } else { /* all other function types */
      newtrm = (ATerm) asfix_put_appl_args(trm,newargs);
      rewtrm = select_and_rewrite(newtrm,depth);
    }

  } else if(asfix_is_var(trm)) {
    rewtrm = v_lookup_plain(env, trm);

    if(!rewtrm) {
      rewtrm = trm;
    }
  } else if(asfix_is_list(trm)) {
    elems = (ATermList) asfix_get_list_elems(trm);
    sym = asfix_get_list_sym(trm);
    newelems = rewrite_elems(sym, elems, env, depth);
    if (newelems) {
      assert(isValidList(newelems));
      rewtrm = (ATerm) asfix_put_list_elems(trm, (ATerm) newelems);
    } else {
      rewtrm = trm;
    }
  }

  else {
    rewtrm = trm;
  }

  return rewtrm;
}


/*}}}  */
