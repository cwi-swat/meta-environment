/*
  $Id$
 */

/*{{{   evaluator.c */
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
#include <aterm2.h>
#include <AsFix.h>
#include <AsFix-access.h>
#include <atb-tool.h>
#include <string.h>
#include <sys/times.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
#include "preparation.h"
#include "deprecated.h"
#include "evaluator.tif.c"

/*}}}  */
/*{{{  defines */

#ifdef PROFILING
#define PROF_REWRITE		rewrite_steps++
#define TICK2SEC(t)		(((double)(t))/CLK_TCK)
#else
#define PROF_REWRITE
#endif

#define is_fail_env(env)	(ATisEqual(env,fail_env))
/*#define v_lookup(env,var)	(ATdictGet(env,var))*/
#define v_is_slice(val)   (ATgetAFun((ATermAppl)val) == list_var)
#define v_get_first(val)  ((ATermList)ATgetArgument((ATermAppl)val, 1))
#define v_get_last(val)  ((ATermList)ATgetArgument((ATermAppl)val, 2))
#define v_put(env,var,val) ((ATerm)ATinsert((ATermList)env, \
													(ATerm)ATmakeAppl2(plain_var, var,val)))
#define v_put_list(env,var,start,end) \
  ((ATerm)ATinsert((ATermList)env, \
		 (ATerm)ATmakeAppl3(list_var, var, (ATerm)start, (ATerm)end)))
#define get_term(cenv)		(ATgetFirst(cenv))
#define get_env(cenv)		(ATgetFirst(ATgetNext(cenv)))
#define make_cenv(t,e)		(ATmakeList(2, t, e))

/*}}}  */
/*{{{  globals */

static unsigned rewrite_steps = 0;


ATerm fail_env;
ATerm tmp1, tmp2, tmp3;

AFun list_var, plain_var;

ATerm equations_db = NULL;

/*}}}  */
/*{{{  function declarations */

ATermList sort_and_filter_on_ofs(ATerm name,ATerm firstofs,ATermList eqs);
ATerm rewrite(ATerm trm, ATerm env);
ATerm list_matching(ATerm sym, ATerm env,
                        ATermList elems1,ATermList elems2,
                        ATermList conds,
                        ATermList args1,ATermList args2);
ATerm args_matching(ATerm env,ATermList conds,
                        ATermList args1,ATermList args2);
ATerm conds_satisfied(ATermList conds,ATerm env);

/*}}}  */
/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */
/*{{{  void create_equations_db(int cid) */

void create_equations_db(int cid)
{
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
	if(first == last)
		return list;

	return ATinsert(prepend(ATgetNext(first), last, list), ATgetFirst(first));
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

ATerm equations_available(int cid, ATerm name)
{
  if(find_module(name))
    return ATmake("snd-value(eqs-available(<term>))", name);
  else
    return ATmake("snd-value(eqs-not-available(<term>))", name);
}


/*}}}  */
/*{{{  ATerm add_equations(int cid, ATerm name, ATermList equs) */

/* The function ``add_equations'' takes care of adding a new list
   of equations is added to the internal database. The arguments
   of this function is a module name and a list of equations.
   Before this list of equations is added to the database some
   preprocessing is needed.
   1. Layout and list separators are removed, and the lexicals are
      expanded to a list of lexical characters.
   2. The equations are ``sorted'' on outermost function symbols.
      This is performed by the function ``sort_and_filter_on_ofs''.
      This function adds the equations with the same ofs in the
      left hand side of an equation to the database, and returns
      the original list of equations minus the equations which
      where stored. Therefore the function ``add_equations''
      contains a loop. */
ATerm add_equations(int cid, ATerm name, ATerm equs)
{
  ATermList newequs;
  int l;

  ATfprintf(stderr, "preparing equations...\n");
  newequs = RWprepareEqs((ATermList) equs);
  l = ATgetLength(newequs);

  enter_equations(name, newequs);

  ATfprintf(stderr,"Processing %d equations of module %t\n",l,name);
  return ATmake("snd-value(equ-added(<term>))",name);
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

ATerm interpret(int cid,ATerm modname, ATerm trm)
{
  ATerm newtrm, newatrm, result;
  ATerm atrm, realtrm;

  struct tms start, rewriting;
  clock_t user, system;

  trm = ATremoveAllAnnotations(trm);
  atrm = asfix_get_term(trm);
  realtrm = RWprepareTerm(atrm);

  rewrite_steps = 0;
  select_equations(modname);

  ATfprintf(stderr, "rewriting...\n");
  times(&start);
  newtrm = rewrite(realtrm,(ATerm) ATempty);
  times(&rewriting);

  newatrm = RWrestoreTerm(newtrm);
  result = asfix_put_term(trm,newatrm);
/*
  ATfprintf(stderr,"result = %t\n", result);
*/

#ifdef PROFILING
  ATfprintf(stdout, "rewriting took %d rewrite steps.\n", rewrite_steps);
  user = rewriting.tms_utime - start.tms_utime;
  system = rewriting.tms_stime - start.tms_stime;
  ATfprintf(stdout, "rewriting: %f user, %f system (%f steps/sec)\n",
	TICK2SEC(user), TICK2SEC(system),
	((double)rewrite_steps)/(TICK2SEC(user)+TICK2SEC(system)));
#endif

  return ATmake("snd-value(result(<term>))",result);
}


/*}}}  */
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
/*{{{  ATermList arg_matching(env, arg1, arg2, conds, orgargs1, orgargs2) */

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
                       ATermList orgargs1, ATermList orgargs2)
{
  ATerm trm, prod1, prod2, sym1, sym2;
  ATermList args1, args2;
  ATermList elems1, elems2;
  ATerm newenv = env;

/*
ATfprintf(stderr, "arg_matching: %t\n with %t\n\n", arg1, arg2);
*/

  if(ATisEqual(arg1,arg2))
    return args_matching(newenv,conds,orgargs1,orgargs2);
  else if(asfix_is_appl(arg1) && asfix_is_appl(arg2)) {
    prod1 = asfix_get_appl_prod(arg1);
    prod2 = asfix_get_appl_prod(arg2);
    if(ATisEqual(prod1,prod2)) {
      args1 = (ATermList) asfix_get_appl_args(arg1);
      args2 = (ATermList) asfix_get_appl_args(arg2);
      args1 = ATconcat(args1,orgargs1);
      args2 = ATconcat(args2,orgargs2);
      newenv = (ATerm) args_matching(newenv,conds,args1,args2);
    }
    else
      newenv = fail_env;
  }
  else if(asfix_is_list(arg1) && asfix_is_list(arg2)) {
		ATbool ok = ATfalse;
    sym1 = asfix_get_list_sym(arg1);
    sym2 = asfix_get_list_sym(arg2);
		if(asfix_is_iter(sym1) && asfix_is_iter(sym2)) {
			ok = (asfix_get_iter_sort(sym1) == asfix_get_iter_sort(sym2));
		} else if(asfix_is_itersep(sym1) && asfix_is_itersep(sym2)) {
			ok = (asfix_get_itersep_sort(sym1) == asfix_get_itersep_sort(sym2));
			ok &= (asfix_get_itersep_sep(sym1) == asfix_get_itersep_sep(sym2));
		}

		if(ok) {
      elems1 = (ATermList) asfix_get_list_elems(arg1);
      elems2 = (ATermList) asfix_get_list_elems(arg2);
      newenv = list_matching(sym1,newenv,elems1,elems2,
                             conds,orgargs1,orgargs2);
    }
    else
      newenv = fail_env;
  }
  else if(asfix_is_var(arg1)) {
    trm = v_lookup_plain(newenv, arg1);
    if(trm) {
      if(ATisEqual(arg2,trm))
        newenv = args_matching(newenv,conds,orgargs1,orgargs2);
      else
        newenv = fail_env;
    }
    else {
      if(AT_getAnnotations(arg1) != NULL)
        arg1 = AT_removeAnnotations(arg1);

      newenv = v_put(newenv,arg1,arg2);
      newenv = args_matching(newenv,conds,orgargs1,orgargs2);
    }
  }
  else {
    newenv = fail_env;
  }
  return newenv;
}

/*}}}  */
/*{{{  ATerm args_matching(env, conds, args1, args2) */

/* Two arguments lists are matched. As long as there are arguments
   to be matched this is performed if both argument lists are empty
   the conditions are inspected. */
ATerm args_matching(ATerm env, ATermList conds,
                    ATermList args1, ATermList args2)
{
  ATerm arg1, arg2;
  ATerm newenv = env;

  if(!ATisEmpty(args1)) {
    arg1 = ATgetFirst(args1);
    args1 = ATgetNext(args1);
    if(!ATisEmpty(args2)) {
      arg2 = ATgetFirst(args2);
      args2 = ATgetNext(args2);
      newenv = arg_matching(newenv,arg1,arg2,conds,args1,args2);
    }
    else
      newenv = fail_env;
  }
  else {
    if(!ATisEmpty(args2))
      newenv = fail_env;
    else
      newenv = conds_satisfied(conds, newenv);
  };
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

		if(!ATisEqual(elem1, elem2))
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

  while(first != last && match) {
    elem1 = ATgetFirst(first);
    if(!ATisEmpty(elems2)) {
      elem2 = ATgetFirst(elems2);
      match = ATisEqual(elem1,elem2);
      elems2 = ATgetNext(elems2);
    }
    else
      match = ATfalse;
    first = ATgetNext(first);
  };

  if(match)
    return elems2;
  else
    return NULL;
}


/*}}}  */
/*{{{  ATermList sub_list_matching(ar,sym,env,elem,elems1,elems2,conds,args1,args2) */

ATerm sub_list_matching(ATerm asym, ATerm env, ATerm elem,
                        ATermList elems1, ATermList elems2,
                        ATermList conds,
                        ATermList args1, ATermList args2)
{
  ATerm subenv, newenv;
  ATermList last;

  if(asfix_is_star_var(elem)) {
    if(AT_getAnnotations(elem) != NULL)
      elem = AT_removeAnnotations(elem);

    newenv = v_put_list(env, elem, ATempty, ATempty);
    subenv = list_matching(asym,newenv,elems1,elems2,conds,args1,args2);
  }
  else {
		/* A plus variable should at least contain one element! */
    subenv = fail_env;
	}
	last  = elems2;
  while(is_fail_env(subenv) && !ATisEmpty(last)) {
    if(AT_getAnnotations(elem) != NULL)
      elem = AT_removeAnnotations(elem);

    last   = ATgetNext(last);
    newenv = v_put_list(env, elem, elems2, last);
    subenv = list_matching(asym,newenv,elems1,last,conds,args1,args2);
  };

  return subenv;
}

/*}}}  */
/*{{{  ATermList list_matching(ar,sym,env,elems1,elems2,conds,args1,args2) */

ATerm list_matching(ATerm sym,
                    ATerm env,ATermList elems1, ATermList elems2,
                    ATermList conds, ATermList args1, ATermList args2)
{
  ATerm elem1, elem2;
  ATerm newenv;
  ATerm newarg1, newarg2;
  ATermList newargs1, newargs2;

  if(!ATisEmpty(elems1)) {
    elem1 = ATgetFirst(elems1);
    if(ATgetLength(elems1) == 1) {
      if(asfix_is_list_var(elem1)) {
				ATermAppl trms = v_lookup_list(env, elem1);
        if(trms) {
          if(compare_lists(trms, elems2))
            newenv = args_matching(env,conds,args1,args2);
          else
            newenv = fail_env;
        }
        else { /* TdictGet(env,elem1) == Tfalse */
          if(asfix_is_plus_var(elem1) && ATisEmpty(elems2)) {
	    newenv = fail_env;
	  } else {
            if(AT_getAnnotations(elem1) != NULL)
              elem1 = AT_removeAnnotations(elem1);

	    newenv = v_put_list(env, elem1, (ATerm)elems2, ATempty);
	    newenv = args_matching(newenv,conds,args1,args2);
					}
        }
      }
      else { /*is_list_var(elem1) == Tfalse */
        if(ATgetLength(elems2) == 1) {
          elem2 = ATgetFirst(elems2);
          newenv = arg_matching(env,elem1,elem2,conds,args1,args2);
        }
        else
          newenv = fail_env;
      }
    }
    else { /* TlistSize(elems1) != 1 */
      elems1 = ATgetNext(elems1);
      if(asfix_is_list_var(elem1)) {
	ATermAppl trms = v_lookup_list(env, elem1);
        if(trms) {
          elems2 = compare_sub_lists(trms,elems2);
          if(elems2)
            newenv = list_matching(sym,env,elems1,elems2,conds,args1,args2);
          else
            newenv = fail_env;
        }
        else /* TdictGet(env,elem1) == Tfalse */
          newenv = sub_list_matching(sym,env,elem1,elems1,elems2,
                                     conds,args1,args2);
      }
      else { /*is_list_var(elem1) == Tfalse */
        if(!ATisEmpty(elems2)) {
          elem2 = ATgetFirst(elems2);
          elems2 = ATgetNext(elems2);
          newarg1 = asfix_make_list(sym,elems1); /* contains the vars */
          newarg2 = asfix_make_list(sym,elems2);
          newargs1 = ATinsert(args1, newarg1);
          newargs2 = ATinsert(args2, newarg2);
          newenv = arg_matching(env,elem1,elem2,conds,newargs1,newargs2);
        }
        else
          newenv = fail_env;
      }
    }
  }
  else /* !elems1 */
    if(!ATisEmpty(elems2))
      newenv = fail_env;
    else {
      newenv = args_matching(env,conds,args1,args2);
    }
  return newenv;
}

/*}}}  */
/*{{{  ATermList conds_satisfied(ATermList conds, ATermList env) */

/* Function ``conds_satisfied'' check whether the conditions
   of an equation can be satisfied.
   Remark access functions needed to retrieve the operator,
   lhs, and rhs. */
ATerm conds_satisfied(ATermList conds, ATerm env)
{
  ATerm cond;
  ATerm lhs, rhs, lhstrm, rhstrm;
  ATerm newenv = env;


  if(!ATisEmpty(conds)) {
		/* <PO:opt> we could do with iteration instead of recursion on the
			 list of conditions! */

    cond = ATgetFirst(conds);

/*
ATfprintf(stderr,"conds_satisfied entered with %t\n and %t\n", cond, env);
*/

    conds = ATgetNext(conds);
		lhs = AFTgetCondLHS(cond);
		rhs = AFTgetCondRHS(cond);
    if(AFTisEqualityCond(cond)) {
			/* <PO:opt> couldn't we determine this statically? */
      if(no_new_vars(lhs,newenv)) {
        lhstrm = rewrite(lhs,newenv);
        if(no_new_vars(rhs,newenv)) {
          rhstrm = rewrite(rhs,newenv);
          if(ATisEqual(lhstrm,rhstrm))
            newenv = conds_satisfied(conds,newenv);
          else
            newenv = fail_env;
        }
        else {
          newenv = arg_matching(newenv,rhs,lhstrm,conds,ATempty,ATempty);
        }
      }
      else {
        if(no_new_vars(rhs,newenv)) {
          rhstrm = rewrite(rhs,newenv);
          newenv = arg_matching(newenv,lhs,rhstrm,conds,ATempty,ATempty);
        }
        else {
          ATfprintf(stderr,
                   "Both sides of a condition introduces new variables:%t\n", cond);
          newenv = fail_env;
        }
      }
    }
    else {
      if(!no_new_vars(lhs,newenv) || !no_new_vars(rhs,newenv)) {
        ATfprintf(stderr,"Negative condition introduces new variables.\n");
        newenv = fail_env;
      }
      else {
        lhstrm = rewrite(lhs,newenv);
        rhstrm = rewrite(rhs,newenv);
        if(ATisEqual(lhstrm,rhstrm))
          newenv = fail_env;
        else
          newenv = conds_satisfied(conds,newenv);
      }
    }
  }
  return newenv;
}


/*}}}  */
/*{{{  ATerm apply_rule(ATerm trm) */

/* The function ``apply_rule'' tries to rewrite a term
   given a list of equations. As long as there is no
   success a new equation is tried. The arguments of
   the term and the arguments of the left hand side of
   the equation are matched.
*/

ATerm apply_rule(ATerm trm)
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


/*ATfprintf(stderr,"Trying equation: %t\n",entry->tag);*/

      conds = entry->conds;
      equargs = (ATermList) asfix_get_appl_args(entry->lhs);

      env = args_matching((ATerm) ATempty, conds, equargs, termargs);
      if(!is_fail_env(env)) {

/*ATfprintf(stderr,"Equation: %t was successful\n",entry->tag);*/

        rewrite_steps++;
        return (ATerm) make_cenv(entry->rhs, env);
      }
/*
      else {
        ATfprintf(stderr,"Equation: %t failed\n",entry->tag);
      }
*/
    }
  }

  while((entry = find_equation(entry, top_ofs, (ATerm) ATempty))) {


/*ATfprintf(stderr,"Trying equation: %t\n",entry->tag);*/

    conds = entry->conds;
    equargs = (ATermList) asfix_get_appl_args(entry->lhs);

    env = args_matching((ATerm) ATempty, conds, equargs, termargs);
    if(!is_fail_env(env)) {

/*ATfprintf(stderr,"Equation: %t was successful\n",entry->tag);*/

      rewrite_steps++;
      return (ATerm) make_cenv(entry->rhs, env);
    }
/*
    else {
ATfprintf(stderr,"Equation: %t failed\n",entry->tag);
    }
*/
  }

  return (ATerm) make_cenv(trm, fail_env);
}

/*}}}  */
/*{{{  ATerm select_and_rewrite(ATerm trm) */

/* The function ``select_and_rewrite'' selects the
   the set of rewrite rules from the active rules and
   tries to rewrite the term via the function ``apply_rule''.
*/

ATerm select_and_rewrite(ATerm trm)
{
  ATerm newtrm, complexenv;
  ATerm env;

  complexenv = apply_rule(trm);
  env = get_env((ATermList) complexenv);
  if(!is_fail_env(env)) {
    newtrm = get_term((ATermList) complexenv);
    trm = rewrite(newtrm, env);
  }
  return trm;
}


/*}}}  */
/*{{{  ATermList rewrite_args(ATermList args, ATerm env) */

/* The list of arguments is rewritten and a new argumentlist
   is constructed. */

ATermList rewrite_args(ATermList args, ATerm env)
{
  ATerm arg, newarg;
  ATermList newargs = ATempty;
  int len = ATgetLength(args);

  if(len > 32) {
    while(!ATisEmpty(args)) {
      arg = ATgetFirst(args);
      if(asfix_is_appl(arg) || asfix_is_var(arg) ||
         asfix_is_list(arg) || asfix_is_lex(arg))
        newarg = rewrite(arg,env);
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
         asfix_is_list(arg) || asfix_is_lex(arg))
        newarg_table[i] = rewrite(arg, env);
      else
        newarg_table[i] = arg;
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
/*{{{  ATermList rewrite_elems(ATerm sym, ATermList elems, ATerm env) */

/* The list of elements is rewritten and a new elementlist
   is constructed. */

ATermList rewrite_elems(ATerm sym, ATermList elems, ATerm env)
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
				newelem = rewrite(elem, env);
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
				newelem_table[i] = rewrite(elem, env);
			}
      elems = ATgetNext(elems);
      i++;
    }
    for(--i; i>=0; i--) {
      newelem = newelem_table[i];
      if(ATgetAFun((ATermAppl)newelem) == list_var) {
        newelems = prepend_slice((ATermAppl)newelem, newelems);
      } else {
        newelems = ATinsert(newelems, newelem);
      }
    }
  }
  return newelems;
}

/*}}}  */
/*{{{  ATerm rewrite(ATerm trm, ATerm env) */

/* The core function. It is checked whether the term
   is an application, a variable, or a list. And the
   appropriate actions are performed.
   For non-constant functions the arguments should first
   be rewritten, conform the innermost reduction strategy.
   The resulting term can then be rewritten.
   REMARK: comments should be improved.
*/

ATerm rewrite(ATerm trm, ATerm env)
{
  ATerm newtrm, sym, rewtrm;
  ATermList args, newargs;
  ATermList elems, newelems;

  if(asfix_is_appl(trm)) {
    args = (ATermList) asfix_get_appl_args(trm);
    /*if(!args)
      ATfprintf(stderr, "trm = %t\n", trm);*/
    newargs = rewrite_args(args,env);
    if(asfix_is_bracket_func(trm)) {
      newtrm = ATgetFirst(ATgetNext(newargs));
      rewtrm = newtrm;
    }
    else {
      newtrm = (ATerm) asfix_put_appl_args(trm,newargs);
      rewtrm = select_and_rewrite(newtrm);
    }
  } else if(asfix_is_var(trm)) {
      rewtrm = v_lookup_plain(env, trm);
      if(!rewtrm)
	rewtrm = trm;
  } else if(asfix_is_list(trm)) {
    elems = (ATermList) asfix_get_list_elems(trm);
    sym = asfix_get_list_sym(trm);
    newelems = rewrite_elems(sym, elems, env);
    rewtrm = (ATerm) asfix_put_list_elems(trm, (ATerm) newelems);
  }
  else {
    rewtrm = trm;
  }
  return rewtrm;
}

/*}}}  */

/*{{{  int main(int argc, char **argv) */

int main(int argc, char **argv)
{
  int cid;
  ATerm bottomOfStack;

  ATBinit(argc, argv, &bottomOfStack);
  AFinit(argc, argv, &bottomOfStack);
  cid = ATBconnect(NULL, NULL, -1,evaluator_handler);

  equations_db = ATdictCreate();
  ATprotect(&equations_db);

  fail_env = ATparse("[fail]");
	ATprotect(&fail_env);

	list_var  = ATmakeAFun("*list-var*", 3, ATtrue);
	plain_var = ATmakeAFun("*plain-var*", 2, ATtrue);
	ATprotectAFun(list_var);
	ATprotectAFun(plain_var);

  ATBeventloop();

  return 0;
}


/*}}}  */
