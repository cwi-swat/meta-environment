/* A first version of an INTERPRETER in ToolBus C.
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

#include <aterm.h>
#include <asfix.h>
#include <tool.h>
#include <string.h>
#include <sys/times.h>
#include <limits.h>
#include "preparation.h"
#include "evaluator.tif.c"

#ifdef PROFILING
#define PROF_REWRITE		rewrite_steps++
#define TICK2SEC(t)		(((double)(t))/CLK_TCK)
#else
#define PROF_REWRITE
#endif
static unsigned rewrite_steps = 0;

FATAL_ERROR


aterm_list *equations_db;
aterm_list *active_rules;
aterm_list *fail_env;
arena Ar;

aterm_list *sort_and_filter_on_ofs(aterm *name,aterm *firstofs,aterm_list *eqs);
aterm *rewrite(aterm *trm,aterm_list *env);
aterm_list *list_matching(aterm *sym, aterm_list *env,
                          aterm_list *elems1,aterm_list *elems2,
                          aterm_list *conds,
                          aterm_list *args1,aterm_list *args2);
aterm_list *args_matching(aterm_list *env,aterm_list *conds,
                         aterm_list *args1,aterm_list *args2);
aterm_list *conds_satisfied(aterm_list *conds,aterm_list *env);

void rec_terminate(int cid, aterm *t)
{
  exit(0);
}

/* Auxilary functions to manipulate the variable environment. 
   The function ``apply_rule'' returns a structure containing
   a term as well as a variable environment. The function
   ``get_env'' retrieves the variable environment of the
   structure whereas the function ``get_term'' retrieves 
   the term. */
aterm_list *get_env(aterm *complexenv)
{
  aterm *trm;
  aterm_list *env;
  
  if(Tmatch(complexenv,"[<term>,<list>]",&trm,&env))
    return env;
  else
    return t_empty(NULL);
}

aterm *get_term(aterm *complexenv)
{
  aterm *trm;
  aterm_list *env;
   
  if(Tmatch(complexenv,"[<term>,<list>]",&trm,&env))
    return trm;
  else
    return t_empty(NULL);
}

/* The variable environment consists either of a list of
   variable-term-pairs, [[V1,T1],...,[Vn,Tn]], or a
   fail environment, [fail].
   The fail environment is needed to indicate
   that the rewriting was not successful. 
   
   The function ``is_fail_env'' checks whether the environment is
   a fail environment. */
Tbool is_fail_env(aterm_list *env)
{
  if(t_equal(env,fail_env))
    return Ttrue;
  else 
    return Tfalse;
}

/* The function ``v_lookup'' retrieves from the variable environment
   the term for a given variable. */
aterm *v_lookup(aterm *var,aterm_list *env)
{
  return TdictGet(env,var);
}

/* Functions to be called by the ToolBus:
   - ``exists'' checks whether the equations for a certain module are
     available.
   - ``create_equations_db'' to initialize the database. 
   - ``clear_equations_db'' to re-initialize the database. 
   - ``add_equations'' to add a set of equations for a certain module.
   - ``interpret'' to rewrite a given term over a given module.  */

aterm *exists(int cid, aterm *name)
{
  aterm *result;

  if(TdictGet(equations_db,name))
    result = Tmake(&Ar,"snd-value(result(exists(<term>)))", name);
  else 
    result = Tmake(&Ar,"snd-value(result(notexists(<term>)))", name);
  return result;
}

void create_equations_db(int cid)
{
  equations_db = t_empty(NULL);
  Tprotect(equations_db);
}

void change_equations_db(aterm_list *db)
{
  Tunprotect(equations_db);
  equations_db = db;
  Tprotect(equations_db);
}
 
void change_active_rules(aterm_list *ar)
{
  Tunprotect(active_rules);
  active_rules = ar;
  Tprotect(active_rules);
}

void clear_equations_db(int cid)
{
  change_equations_db(t_empty(NULL));
}

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
aterm *add_equations(int cid,aterm *name,aterm_list *equs)
{
  aterm_list *newequs;
  aterm *eq,*lhs,*firstofs;
  int l;
  
  newequs = RWprepareEqs(&Ar, equs);
  l = TlistSize(newequs);
  change_equations_db(TdictPut(&Ar,equations_db,name,t_empty(NULL)));
  while(!t_is_empty(newequs)) {
    eq = t_list_first(newequs);
    lhs = asfix_get_equ_lhs(eq);
    firstofs = asfix_get_appl_ofs(lhs);
    newequs = sort_and_filter_on_ofs(name,firstofs,newequs);
  };
Tprintf(stderr,"Processing %d equations of module %t\n",l,name);
  return Tmake(&Ar,"snd-value(equ-added(<term>))",name);
}

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
  
aterm *interpret(int cid,aterm *modname, aterm *trm)
{
  aterm *newtrm,*newatrm,*result;
  aterm *atrm,*exptrm,*realtrm;

  struct tms start, rule_selection, rewriting, restoration;
  clock_t user, system;
 
  exptrm = AFexpandTerm(&Ar, trm);
  atrm = asfix_get_term(exptrm);
  realtrm = RWprepareTerm(&Ar, atrm);

  rewrite_steps = 0;
  times(&start);
  change_active_rules(TdictGet(equations_db,modname));
  times(&rule_selection);
  newtrm = rewrite(realtrm,t_empty(NULL));
  times(&rewriting);
  newatrm = RWrestoreTerm(&Ar, newtrm);
  result = asfix_put_term(&Ar,exptrm,newatrm);
  times(&restoration);

#ifdef PROFILING
  fprintf(stdout, "rewriting took %d rewrite steps.\n", rewrite_steps);
  user = rule_selection.tms_utime - start.tms_utime;
  system = rule_selection.tms_stime - start.tms_stime;
  fprintf(stdout, "rule selection: %f user, %f system.\n", TICK2SEC(user), TICK2SEC(system));
  user = rewriting.tms_utime - rule_selection.tms_utime;
  system = rewriting.tms_stime - rule_selection.tms_stime;
  fprintf(stdout, "rewriting: %f user, %f system (%f steps/sec)\n", 
	TICK2SEC(user), TICK2SEC(system), 
	((double)rewrite_steps)/(TICK2SEC(user)+TICK2SEC(system)));
  user = restoration.tms_utime - rewriting.tms_utime;
  system = restoration.tms_stime - rewriting.tms_stime;
  fprintf(stdout, "restoration: %f user, %f system.\n", TICK2SEC(user), TICK2SEC(system));
#endif

  return Tmake(&Ar,"snd-value(result(<term>))",result);
}

/* The function ``filter_on_ofs'' selects the rewrite rules 
   with the same outermost function symbol in their left hand side.
   This function gets a module name, an outermost function symbol,
   and a list of equations. Equations with the same ofs as the 
   argument ofs are added to a new list and removed from the argument
   list. If all equations in the argument list are inspected the
   new constructed list is added to the equation database in the
   entry of the module name. The function returns the argument list
   without the filtered equations. */
aterm_list *sort_and_filter_on_ofs(aterm *name,aterm *firstofs,aterm_list *eqs)
{
  aterm *eq,*lhs,*ofs,*pair;
  aterm_list *oldpairs,*newpairs;
  aterm_list *sameofs = t_empty(NULL);
  aterm_list *neweqs = t_empty(NULL);

  while(!t_is_empty(eqs)) {
    eq = t_list_first(eqs);
    lhs = asfix_get_equ_lhs(eq);
    ofs = asfix_get_appl_ofs(lhs);
    if(t_equal(firstofs,ofs)) {
      if(AFisDefaultEquation(eq))
        sameofs = TlistAppend(&Ar,sameofs,eq);
      else
        sameofs = TlistInsert(&Ar,sameofs, 0, eq);
    }
    else
      neweqs = TlistAppend(&Ar,neweqs,eq);
    eqs = t_list_next(eqs);
  };

/* Create a pair of the ofs and the list of equations
   with the same ofs in the left hand side.
   Update the entry in the equation-database */
  pair = Tmake(&Ar,"[<term>,<list>]",firstofs,sameofs);
  oldpairs = TdictGet(equations_db,name);
  newpairs = TlistAppend(&Ar,oldpairs,pair);
  change_equations_db(TdictPut(&Ar,equations_db,name,newpairs));
  
  return neweqs;
}

/* A predicate which checks whether a term introduces new
   variables. This functions is used when dealing with the
   conditions of equations. */
Tbool no_new_vars(aterm *trm,aterm_list *env)
{
  aterm *arg;
  aterm_list *args;
  Tbool existing;

  if(asfix_is_var(trm)) {
    if(TdictGet(env,trm))
      return Ttrue;
    else
      return Tfalse;
    }
  else if(asfix_is_appl(trm)) {
    existing = Ttrue;
    args = asfix_get_appl_args(trm);
    while(existing && !t_is_empty(args)) {
      arg = t_list_first(args);
      existing = no_new_vars(arg,env);
      args = t_list_next(args);
    };
    return existing;
  }
  else if(asfix_is_list(trm)) {
    existing = Ttrue;
    args = asfix_get_list_elems(trm);
    while(existing && !t_is_empty(args)) {
      arg = t_list_first(args);
      existing = no_new_vars(arg,env);
      args = t_list_next(args);
    };
    return existing;
  }
  else
    return Ttrue;
}

/* Functions which take care of the matching of arguments of
   ``appls'' and ``lists''. 
   The matching is a very recursive process. This is needed to
   take care of the backtracking needed when dealing with
   list matching. */
aterm_list *elems_matching(aterm *sym, aterm_list *env,
                           aterm_list *elems1,aterm_list *elems2,
                           aterm_list *conds,
                           aterm_list *args1,aterm_list *args2)
{
  if(AFcontainsVars(elems1))
    return list_matching(sym,env,elems1,elems2,conds,args1,args2);
  else
    return list_matching(sym,env,elems2,elems1,conds,args1,args2);
}

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
  
aterm_list *arg_matching(aterm_list *env, aterm *arg1, aterm *arg2,
                        aterm_list *conds, 
                        aterm_list *orgargs1, aterm_list *orgargs2)
{
  aterm *trm,*prod1,*prod2,*sym1,*sym2;
  aterm_list *args1,*args2;
  aterm_list *elems1,*elems2;
  aterm_list *newenv = env;

  if(asfix_is_var(arg1) && !asfix_is_var(arg2)) {
    if(TdictGet(newenv,arg1)) {
      trm = v_lookup(arg1,newenv);
      if(t_equal(arg2,trm))
        newenv = args_matching(newenv,conds,orgargs1,orgargs2);
      else
        newenv = fail_env;
    }
    else {
      newenv = TdictPut(&Ar,newenv,arg1,arg2);
      newenv = args_matching(newenv,conds,orgargs1,orgargs2);
    }
  }
  else if(!asfix_is_var(arg1) && asfix_is_var(arg2)) {
    if(TdictGet(newenv,arg2)) {
      trm = v_lookup(arg2,newenv);
      if(t_equal(arg1,trm))
        newenv = args_matching(newenv,conds,orgargs1,orgargs2);
      else
        newenv = fail_env;
    }
    else {
      newenv = TdictPut(&Ar,newenv,arg2,arg1);
      newenv = args_matching(newenv,conds,orgargs1,orgargs2);
    }
  }
  else if(asfix_is_appl(arg1) && asfix_is_appl(arg2)) {
    prod1 = asfix_get_appl_prod(arg1);
    prod2 = asfix_get_appl_prod(arg2);
    if(t_equal(prod1,prod2)) {
      args1 = asfix_get_appl_args(arg1);
      args2 = asfix_get_appl_args(arg2);
      args1 = TlistConcat(&Ar,args1,orgargs1);
      args2 = TlistConcat(&Ar,args2,orgargs2);
      newenv = args_matching(newenv,conds,args1,args2);
    }
    else
      newenv = fail_env;
  }
  else if(asfix_is_list(arg1) && asfix_is_list(arg2)) {
    sym1 = asfix_get_list_sym(arg1);
    sym2 = asfix_get_list_sym(arg2);
    if(t_equal(sym1,sym2)) {
      elems1 = asfix_get_list_elems(arg1);
      elems2 = asfix_get_list_elems(arg2);
      newenv = elems_matching(sym1,newenv,elems1,elems2,
                              conds,orgargs1,orgargs2);
    }
    else
      newenv = fail_env;
  }
  else {
    if(t_equal(arg1,arg2))
      newenv = args_matching(newenv,conds,orgargs1,orgargs2);
    else
      newenv = fail_env;
  }
  return newenv;
}

/* Two arguments lists are matched. As long as there are arguments
   to be matched this is performed if both argument lists are empty
   the conditions are inspected. */
aterm_list *args_matching(aterm_list *env,aterm_list *conds,
                         aterm_list *args1, aterm_list *args2)
{
  aterm *arg1,*arg2; 
  aterm_list *newenv = env;

  if(!t_is_empty(args1)) {
    arg1 = t_list_first(args1);
    args1 = t_list_next(args1);
    if(!t_is_empty(args2)) {
      arg2 = t_list_first(args2);
      args2 = t_list_next(args2);
      newenv = arg_matching(newenv,arg1,arg2,conds,args1,args2);
    } 
    else 
      newenv = fail_env;
  }
  else {
    if(!t_is_empty(args2)) 
      newenv = fail_env;
    else 
      newenv = conds_satisfied(conds,newenv);
  };
  return newenv;
}

aterm_list *compare_sub_lists(aterm_list *elems1, aterm_list *elems2)
{
  aterm *elem1,*elem2;
  Tbool match = Ttrue;

  while(!t_is_empty(elems1) && match) {
    elem1 = t_list_first(elems1);
    if(!t_is_empty(elems2)) {
      elem2 = t_list_first(elems2);
      match = t_equal(elem1,elem2);
      elems2 = t_list_next(elems2);
    }
    else
      match = Tfalse;
    elems1 = t_list_next(elems1);
  };
  if(!t_is_empty(elems2)) {
    elem2 = t_list_first(elems2);
  };
  if(match)
    return elems2;
  else
    return fail_env;
}

aterm_list *sub_list_matching(aterm *sym,aterm_list *env,aterm *elem,
                             aterm_list *elems1, aterm_list *elems2,
                             aterm_list *conds, 
                             aterm_list *args1, aterm_list *args2)
{
  aterm *elem2;
  aterm_list *subenv,*newenv;
  aterm_list *subelems = t_empty(NULL);
 
  if(asfix_is_star_var(elem)) {
    newenv = TdictPut(&Ar,env,elem,subelems);
    subenv = list_matching(sym,newenv,elems1,elems2,conds,args1,args2);
  }
  else
/* A plus variable should at least contain one element! */
    subenv = fail_env;
  while(is_fail_env(subenv) && !t_is_empty(elems2)) {
    if(!t_is_empty(elems2)) {
      elem2 = t_list_first(elems2);
      subelems = TlistAppend(&Ar,subelems,elem2);
      elems2 = t_list_next(elems2);
      newenv = TdictPut(&Ar,env,elem,subelems);
      subenv = list_matching(sym,newenv,elems1,elems2,conds,args1,args2);
   }
   else
     subenv = fail_env;
  };
  return subenv;
}

aterm_list *list_matching(aterm *sym,
                         aterm_list *env,aterm_list *elems1, aterm_list *elems2,
                         aterm_list *conds, aterm_list *args1, aterm_list *args2)
{
  aterm *elem1,*elem2;
  aterm_list *trms,*rlist;
  aterm_list *newenv;
  aterm *newarg1,*newarg2;
  aterm_list *newargs1,*newargs2;

  if(!t_is_empty(elems1)) {
    elem1 = t_list_first(elems1);
    if(TlistSize(elems1) == 1) {
      if(asfix_is_list_var(elem1)) {
        if(TdictGet(env,elem1)) {
          trms = v_lookup(elem1,env);
          rlist = compare_sub_lists(trms,elems2);
          if(t_is_empty(rlist)) {
            newenv = args_matching(env,conds,args1,args2);
          }
          else
            newenv = fail_env;
        } 
        else { /* TdictGet(env,elem1) == Tfalse */
          if(asfix_is_plus_var(elem1)) {
            if(!t_is_empty(elems2)) {
              newenv = TdictPut(&Ar,env,elem1,elems2);
              newenv = args_matching(newenv,conds,args1,args2);
            }
            else
              newenv = fail_env;
          }
          else {
            newenv = TdictPut(&Ar,env,elem1,elems2);
            newenv = args_matching(newenv,conds,args1,args2);
          }
        }
      } 
      else { /*is_list_var(elem1) == Tfalse */
        if(TlistSize(elems2) == 1) {
          elem2 = t_list_first(elems2);
          newenv = arg_matching(env,elem1,elem2,conds,args1,args2);
        }
        else 
          newenv = fail_env;
      }
    }
    else { /* TlistSize(elems1) != 1 */
      elems1 = t_list_next(elems1);
      if(asfix_is_list_var(elem1)) {
        if(TdictGet(env,elem1)) {
          trms = v_lookup(elem1,env);
          elems2 = compare_sub_lists(trms,elems2);
          if(!is_fail_env(elems2)) 
            newenv = list_matching(sym,env,elems1,elems2,conds,args1,args2);
          else
            newenv = fail_env;
        } 
        else /* TdictGet(env,elem1) == Tfalse */
          newenv = sub_list_matching(sym,env,elem1,elems1,elems2,
                                     conds,args1,args2);
      } 
      else { /*is_list_var(elem1) == Tfalse */
        if(!t_is_empty(elems2)) {
          elem2 = t_list_first(elems2);
          elems2 = t_list_next(elems2);
          newarg1 = asfix_make_list(&Ar,sym,elems1);
          newarg2 = asfix_make_list(&Ar,sym,elems2);
          newargs1 = TlistInsert(&Ar,args1, 0, newarg1);
          newargs2 = TlistInsert(&Ar,args2, 0, newarg2);
          newenv = arg_matching(env,elem1,elem2,conds,newargs1,newargs2);
        }
        else
          newenv = fail_env;
      }
    }
  }
  else /* !elems1 */
    if(!t_is_empty(elems2))
      newenv = fail_env;
    else {
      newenv = args_matching(env,conds,args1,args2);
    }
  return newenv;
}

/* Function ``conds_satisfied'' check whether the conditions
   of an equation can be satisfied. 
   Remark access functions needed to retrieve the operator,
   lhs, and rhs. */
aterm_list *conds_satisfied(aterm_list *conds, aterm_list *env)
{
  aterm *cond;
  aterm *lhs,*rhs,*lhstrm,*rhstrm;
  aterm_list *newenv = env;

  if(!t_is_empty(conds)) {
    cond = t_list_first(conds);
    conds = t_list_next(conds);
    lhs = asfix_get_cond_lhs(cond);
    rhs = asfix_get_cond_rhs(cond);
    if(asfix_is_equality_cond(cond)) {
      if(no_new_vars(lhs,newenv)) {
        lhstrm = rewrite(lhs,newenv);
        if(no_new_vars(rhs,newenv)) {
          rhstrm = rewrite(rhs,newenv);
          newenv = arg_matching(newenv,lhstrm,rhstrm,conds,t_empty(NULL),t_empty(NULL));
        }
        else {
          newenv = arg_matching(newenv,lhstrm,rhs,conds,t_empty(NULL),t_empty(NULL));
        }
      }
      else {
        if(no_new_vars(rhs,newenv)) {
          rhstrm = rewrite(rhs,newenv);
          newenv = arg_matching(newenv,lhs,rhstrm,conds,t_empty(NULL),t_empty(NULL));
        }
        else {
          Tprintf(stderr,
                   "Both sides of a condition introduces new variables.\n");
          newenv = fail_env;
        }
      }
    }
    else {
      if(!no_new_vars(lhs,newenv) || !no_new_vars(rhs,newenv)) {
        Tprintf(stderr,"Negative condition introduces new variables.\n");
        newenv = fail_env;
      }
      else {
        lhstrm = rewrite(lhs,newenv);
        rhstrm = rewrite(rhs,newenv);
        if(t_equal(lhstrm,rhstrm)) 
          newenv = fail_env;
        else
          newenv = conds_satisfied(conds,newenv);
      }
    }
  }
  return newenv;
}

/* The function ``apply_rule'' tries to rewrite a term
   given a list of equations. As long as there is no
   success a new equation is tried. The arguments of
   the term and the arguments of the left hand side of 
   the equation are matched.
*/
aterm *apply_rule(aterm_list *rules,aterm *trm)
{
  aterm *rule,*newtrm;
  aterm_list *termargs,*ruleargs;
  aterm_list *env,*newenv,*conds;
  Tbool match = Tfalse;

  while(!match && !t_is_empty(rules)) {
    rule = t_list_first(rules);
    conds = asfix_get_equ_conds(rule);
    termargs = asfix_get_appl_args(trm);
    ruleargs = asfix_get_appl_args(asfix_get_equ_lhs(rule));
    env = args_matching(t_empty(NULL),conds,termargs,ruleargs);
    if(is_fail_env(env) == Tfalse) {
      newtrm = asfix_get_equ_rhs(rule);
      match = Ttrue;
    };
    rules = t_list_next(rules);
  }; 
  if(match) {
    newenv = Tmake(&Ar,"[<term>,<list>]",newtrm,env);
    PROF_REWRITE;
  }
  else {
    env = fail_env;
    newenv = Tmake(&Ar,"[<term>,<list>]",trm,env);
  };
  return newenv;
}

/* The function ``select_and_rewrite'' selects the
   the set of rewrite rules from the active rules and
   tries to rewrite the term via the function ``apply_rule''.
*/
aterm *select_and_rewrite(aterm *trm)
{
  aterm *ofs,*newtrm, *complexenv;
  aterm_list *rules,*env;

  ofs = asfix_get_appl_ofs(trm);
/* select the appropriate set of rewrite rules. */
  rules = TdictGet(active_rules,ofs);
  if(!rules)
    return trm;
  complexenv = apply_rule(rules,trm);
  env = get_env(complexenv);
  if(!is_fail_env(env)) {
    newtrm = get_term(complexenv);
    trm = rewrite(newtrm,env);
  }
  return trm;
}

/* The list of arguments is rewritten and a new argumentlist
   is constructed. */
aterm_list *rewrite_args(aterm_list *args,aterm_list *env)
{
  aterm *arg,*newarg;
  aterm_list *newargs = t_empty(NULL);

  while(!t_is_empty(args)) {
    arg = t_list_first(args);
    if(asfix_is_appl(arg) || asfix_is_var(arg) ||
       asfix_is_list(arg) || asfix_is_lex(arg)) 
      newarg = rewrite(arg,env);
    else
      newarg = arg;
    newargs = TlistAppend(&Ar,newargs,newarg);
    args = t_list_next(args);
  };
  return newargs;
}

/* The list of elements is rewritten and a new elementlist
   is constructed. */
aterm_list *rewrite_elems(aterm *sym,aterm_list *elems,aterm_list *env)
{
  aterm *elem,*newelem;
  aterm_list *newelems = t_empty(NULL);
  
  while(!t_is_empty(elems)) {
    elem = t_list_first(elems);
    newelem = rewrite(elem,env);
    if(t_is_list(newelem))
      newelems = TlistConcat(&Ar,newelems,newelem);
    else
      newelems = TlistAppend(&Ar,newelems,newelem);
    elems = t_list_next(elems);
  };
  return newelems;
}

/* The core function. It is checked whether the term
   is an application, a variable, or a list. And the
   appropriate actions are performed.
   For non-constant functions the arguments should first
   be rewritten, conform the innermost reduction strategy.
   The resulting term can then be rewritten.
   REMARK: comments should be improved.
*/ 
aterm *rewrite(aterm *trm,aterm_list *env)
{
  aterm *newtrm,*sym,*rewtrm;
  aterm_list *args,*newargs;
  aterm_list *elems,*newelems;

  if(asfix_is_appl(trm)) {
    args = asfix_get_appl_args(trm);
    if(!args)
      Tprintf(stderr, "trm = %t\n", trm);
    newargs = rewrite_args(args,env);
    if(asfix_is_bracket_func(trm)) {
      newtrm = t_list_first(t_list_next(newargs));
      return newtrm;
    }
    else {
      newtrm = asfix_put_appl_args(&Ar,trm,newargs);
      rewtrm = select_and_rewrite(newtrm);
      Tprotect(rewtrm);
      TflushArena(&Ar);
      Tadd2Arena(&Ar, rewtrm);
      Tunprotect(rewtrm);
      return rewtrm;
    }
  }
  else if(asfix_is_var(trm)) {
    if(TdictGet(env,trm))
      return v_lookup(trm,env);
    else 
      return trm;
  }
  else if(asfix_is_list(trm)) {
    elems = asfix_get_list_elems(trm);
    sym = asfix_get_list_sym(trm);
    newelems = rewrite_elems(sym,elems,env);
    newtrm = asfix_put_list_elems(&Ar,trm,newelems);
    return newtrm;
  }
  else
    return trm;
}

int main(int argc, char **argv)
{
  int cid;

  TBinit(argc,argv);
  AFinit(NULL);
  cid = TBnewConnection(NULL,NULL,NULL,-1,
                        evaluator_handler,evaluator_check_in_sign);
  TinitArena(NULL,&Ar);
  TBconnect(cid);
  fail_env = Tmake(&Ar,"[fail]");
  Tprotect(fail_env);
  TBeventloop();

  return 0;
}
