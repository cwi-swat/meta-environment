#line 89 "evaluator.c.nw"
#include <aterm.h>
#include <asfix.h>
#include <tb-tool.h>
#include <string.h>
#include <sys/times.h>
#include <limits.h>
#include "preparation.h"
#include "evaluator.tif.c"
#line 103 "evaluator.c.nw"
#ifdef PROFILING
#define PROF_REWRITE            rewrite_steps++
#define TICK2SEC(t)             (((double)(t))/CLK_TCK)
#else
#define PROF_REWRITE
#endif
static unsigned rewrite_steps = 0;

FATAL_ERROR


aterm_list *equations_db;
aterm_list *active_rules;
aterm_list *fail_env;
arena Ar;
aterm *tmp1, *tmp2, *tmp3;

#define is_fail_env(env)        (t_equal(env,fail_env))
#define v_lookup(var,env)       (TdictGet(env,var))
#define get_term(cenv)          (t_list_first(cenv))
#define get_env(cenv)           (t_list_first(t_list_next(cenv)))
#define make_cenv(ar,t,e)       (TmkList_n(ar, 2, t, e))
#line 131 "evaluator.c.nw"
aterm_list *sort_and_filter_on_ofs(aterm *name,aterm *firstofs,aterm_list *eqs);
aterm *rewrite(arena *ar, aterm *trm,aterm_list *env);
aterm_list *list_matching(arena *ar, aterm *sym, aterm_list *env,
                          aterm_list *elems1,aterm_list *elems2,
                          aterm_list *conds,
                          aterm_list *args1,aterm_list *args2);
aterm_list *args_matching(arena *ar, aterm_list *env,aterm_list *conds,
                         aterm_list *args1,aterm_list *args2);
aterm_list *conds_satisfied(arena *ar, aterm_list *conds,aterm_list *env);

#line 146 "evaluator.c.nw"
void rec_terminate(int cid, aterm *t)
{
  exit(0);
}
#line 164 "evaluator.c.nw"
aterm *exists(int cid, aterm *name)
{
  aterm *result;

  if(TdictGet(equations_db,name))
    result = Tmake(&Ar,"snd-value(result(exists(<term>)))", name);
  else 
    result = Tmake(&Ar,"snd-value(result(notexists(<term>)))", name);
  return result;
}
#line 180 "evaluator.c.nw"
void create_equations_db(int cid)
{
  equations_db = t_empty(NULL);
  active_rules = t_empty(NULL);
  t_protect(equations_db);
  t_protect(active_rules);
}
#line 193 "evaluator.c.nw"
void change_equations_db(aterm_list *db)
{
  t_unprotect(equations_db);
  equations_db = db;
  t_protect(equations_db);
}
#line 205 "evaluator.c.nw"
void change_active_rules(aterm_list *ar)
{
  t_unprotect(active_rules);
  active_rules = ar;
  t_protect(active_rules);
}
#line 217 "evaluator.c.nw"
void clear_equations_db(int cid)
{
  change_equations_db(t_empty(NULL));
}
#line 241 "evaluator.c.nw"
aterm *add_equations(int cid,aterm *name,aterm_list *equs)
{
  aterm_list *newequs;
  aterm *eq,*lhs,*firstofs;
  int l;
  
  Tprintf(stderr, "preparing equations...\n");
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
#line 284 "evaluator.c.nw"
aterm *interpret(int cid,aterm *modname, aterm *trm)
{
  aterm *newtrm,*newatrm,*result;
  aterm *atrm,*exptrm,*realtrm;

  struct tms start, rule_selection, rewriting, restoration;
  clock_t user, system;

  TflushArena(&Ar);

  Tprintf(stderr, "before AFexpandTerm\n");
  exptrm = AFexpandTerm(&Ar, trm);
  Tprintf(stderr, "after AFexpandTerm\n");
  atrm = asfix_get_term(exptrm);
  realtrm = RWprepareTerm(&Ar, atrm);

  rewrite_steps = 0;
  times(&start);
  change_active_rules(TdictGet(equations_db,modname));
  times(&rule_selection);

  Tprintf(stderr, "rewriting...\n");
  newtrm = rewrite(&Ar, realtrm,t_empty(NULL));
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
#line 345 "evaluator.c.nw"
aterm_list *sort_and_filter_on_ofs(aterm *name,aterm *firstofs,aterm_list *eqs)
{
  aterm *eq,*lhs,*ofs,*pair;
  aterm_list *oldpairs,*newpairs;
  aterm_list *sameofs = t_empty(NULL);
  aterm_list *neweqs = t_empty(NULL);
  arena local;

  TinitArena(t_world(name), &local);

  while(!t_is_empty(eqs)) {
    eq = t_list_first(eqs);
    lhs = asfix_get_equ_lhs(eq);
    ofs = asfix_get_appl_ofs(lhs);
    if(t_equal(firstofs,ofs)) {
      if(AFisDefaultEquation(eq))
        sameofs = TlistAppend(&local,sameofs,eq);
      else
        sameofs = TlistInsert(&local,sameofs, 0, eq);
    }
    else
      neweqs = TlistAppend(&local,neweqs,eq);
    eqs = t_list_next(eqs);

    Tprotect(neweqs);
    Tprotect(sameofs);
    TflushArena(&local);
    Tadd2Arena(&local, neweqs);
    Tadd2Arena(&local, sameofs);
    Tunprotect(neweqs);   
    Tunprotect(sameofs);
  };

/* Create a pair of the ofs and the list of equations
   with the same ofs in the left hand side.
   Update the entry in the equation-database */
  pair = Tmake(&local,"[<term>,<list>]",firstofs,sameofs);
  oldpairs = TdictGet(equations_db,name);
  newpairs = TlistAppend(&local,oldpairs,pair);
  change_equations_db(TdictPut(&Ar,equations_db,name,newpairs));

  Tadd2Arena(&Ar, neweqs);  
  TdestroyArena(&local);

  return neweqs;
}
#line 400 "evaluator.c.nw"
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
#line 446 "evaluator.c.nw"
aterm_list *elems_matching(arena *ar, aterm *sym, aterm_list *env,
                           aterm_list *elems1,aterm_list *elems2,
                           aterm_list *conds,
                           aterm_list *args1,aterm_list *args2)
{
  if(AFcontainsVars(elems1))
    return list_matching(ar,sym,env,elems1,elems2,conds,args1,args2);
  else
    return list_matching(ar,sym,env,elems2,elems1,conds,args1,args2);
}
#line 479 "evaluator.c.nw"
aterm_list *arg_matching(arena *ar, aterm_list *env, aterm *arg1, aterm *arg2,
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
        newenv = args_matching(ar,newenv,conds,orgargs1,orgargs2);
      else
        newenv = fail_env;
    }
    else {
      newenv = TdictPut(ar,newenv,arg1,arg2);
      newenv = args_matching(ar,newenv,conds,orgargs1,orgargs2);
    }
  }
  else if(!asfix_is_var(arg1) && asfix_is_var(arg2)) {
    if(TdictGet(newenv,arg2)) {
      trm = v_lookup(arg2,newenv);
      if(t_equal(arg1,trm))
        newenv = args_matching(ar,newenv,conds,orgargs1,orgargs2);
      else
        newenv = fail_env;
    }
    else {
      newenv = TdictPut(ar,newenv,arg2,arg1);
      newenv = args_matching(ar,newenv,conds,orgargs1,orgargs2);
    }
  }
  else if(asfix_is_appl(arg1) && asfix_is_appl(arg2)) {
    prod1 = asfix_get_appl_prod(arg1);
    prod2 = asfix_get_appl_prod(arg2);
    if(t_equal(prod1,prod2)) {
      args1 = asfix_get_appl_args(arg1);
      args2 = asfix_get_appl_args(arg2);
      args1 = TlistConcat(ar,args1,orgargs1);
      args2 = TlistConcat(ar,args2,orgargs2);
      newenv = args_matching(ar,newenv,conds,args1,args2);
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
      newenv = elems_matching(ar,sym1,newenv,elems1,elems2,
                              conds,orgargs1,orgargs2);
    }
    else
      newenv = fail_env;
  }
  else {
    if(t_equal(arg1,arg2))
      newenv = args_matching(ar,newenv,conds,orgargs1,orgargs2);
    else
      newenv = fail_env;
  }
  return newenv;
}
#line 556 "evaluator.c.nw"
aterm_list *args_matching(arena *ar, aterm_list *env,aterm_list *conds,
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
      newenv = arg_matching(ar,newenv,arg1,arg2,conds,args1,args2);
    } 
    else 
      newenv = fail_env;
  }
  else {
    if(!t_is_empty(args2)) 
      newenv = fail_env;
    else 
      newenv = conds_satisfied(ar,conds,newenv);
  };
  return newenv;
}
#line 587 "evaluator.c.nw"
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
#line 617 "evaluator.c.nw"
aterm_list *sub_list_matching(arena *ar, aterm *sym,aterm_list *env,aterm *elem,
                             aterm_list *elems1, aterm_list *elems2,
                             aterm_list *conds, 
                             aterm_list *args1, aterm_list *args2)
{
  aterm *elem2;
  aterm_list *subenv,*newenv;
  aterm_list *subelems = t_empty(NULL);
 
  if(asfix_is_star_var(elem)) {
    newenv = TdictPut(ar,env,elem,subelems);
    subenv = list_matching(ar,sym,newenv,elems1,elems2,conds,args1,args2);
  }
  else
/* A plus variable should at least contain one element! */
    subenv = fail_env;
  while(is_fail_env(subenv) && !t_is_empty(elems2)) {
    if(!t_is_empty(elems2)) {
      elem2 = t_list_first(elems2);
      subelems = TlistAppend(ar,subelems,elem2);
      elems2 = t_list_next(elems2);
      newenv = TdictPut(ar,env,elem,subelems);
      subenv = list_matching(ar,sym,newenv,elems1,elems2,conds,args1,args2);
   }
   else
     subenv = fail_env;
  };
  return subenv;
}
#line 652 "evaluator.c.nw"
aterm_list *list_matching(arena *ar, aterm *sym,
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
            newenv = args_matching(ar,env,conds,args1,args2);
          }
          else
            newenv = fail_env;
        } 
        else { /* TdictGet(env,elem1) == Tfalse */
          if(asfix_is_plus_var(elem1)) {
            if(!t_is_empty(elems2)) {
              newenv = TdictPut(ar,env,elem1,elems2);
              newenv = args_matching(ar,newenv,conds,args1,args2);
            }
            else
              newenv = fail_env;
          }
          else {
            newenv = TdictPut(ar,env,elem1,elems2);
            newenv = args_matching(ar,newenv,conds,args1,args2);
          }
        }
      } 
      else { /*is_list_var(elem1) == Tfalse */
        if(TlistSize(elems2) == 1) {
          elem2 = t_list_first(elems2);
          newenv = arg_matching(ar,env,elem1,elem2,conds,args1,args2);
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
            newenv = list_matching(ar,sym,env,elems1,elems2,conds,args1,args2);
          else
            newenv = fail_env;
        } 
        else /* TdictGet(env,elem1) == Tfalse */
          newenv = sub_list_matching(ar,sym,env,elem1,elems1,elems2,
                                     conds,args1,args2);
      } 
      else { /*is_list_var(elem1) == Tfalse */
        if(!t_is_empty(elems2)) {
          elem2 = t_list_first(elems2);
          elems2 = t_list_next(elems2);
          newarg1 = asfix_make_list(ar,sym,elems1);
          newarg2 = asfix_make_list(ar,sym,elems2);
          newargs1 = TlistInsert(ar,args1, 0, newarg1);
          newargs2 = TlistInsert(ar,args2, 0, newarg2);
          newenv = arg_matching(ar,env,elem1,elem2,conds,newargs1,newargs2);
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
      newenv = args_matching(ar,env,conds,args1,args2);
    }
  return newenv;
}
#line 747 "evaluator.c.nw"
aterm_list *conds_satisfied(arena *ar, aterm_list *conds, aterm_list *env)
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
        lhstrm = rewrite(ar,lhs,newenv);
        if(no_new_vars(rhs,newenv)) {
          rhstrm = rewrite(ar,rhs,newenv);
          newenv = arg_matching(ar,newenv,lhstrm,rhstrm,conds,t_empty(NULL),t_empty(NULL));
        }
        else {
          newenv = arg_matching(ar,newenv,lhstrm,rhs,conds,t_empty(NULL),t_empty(NULL));
        }
      }
      else {
        if(no_new_vars(rhs,newenv)) {
          rhstrm = rewrite(ar,rhs,newenv);
          newenv = arg_matching(ar,newenv,lhs,rhstrm,conds,t_empty(NULL),t_empty(NULL));
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
        lhstrm = rewrite(ar,lhs,newenv);
        rhstrm = rewrite(ar,rhs,newenv);
        if(t_equal(lhstrm,rhstrm)) 
          newenv = fail_env;
        else
          newenv = conds_satisfied(ar,conds,newenv);
      }
    }
  }
  return newenv;
}
#line 810 "evaluator.c.nw"
aterm *apply_rule(arena *ar, aterm_list *rules,aterm *trm)
{
  aterm *rule;
  aterm_list *termargs,*ruleargs;
  aterm_list *env,*conds;

  while(!t_is_empty(rules)) {
    rule = t_list_first(rules);
    conds = asfix_get_equ_conds(rule);
    termargs = asfix_get_appl_args(trm);
    ruleargs = asfix_get_appl_args(asfix_get_equ_lhs(rule));
    env = args_matching(ar, t_empty(NULL),conds,termargs,ruleargs);
    if(is_fail_env(env) == Tfalse) {
      rewrite_steps++;       
      return make_cenv(ar, asfix_get_equ_rhs(rule), env);
    }
    rules = t_list_next(rules);
  }; 
  return make_cenv(ar, trm, fail_env);
}
#line 840 "evaluator.c.nw"
aterm *select_and_rewrite(arena *ar, aterm *trm)
{
  aterm *ofs,*newtrm, *complexenv;
  aterm_list *rules,*env;

  ofs = asfix_get_appl_ofs(trm);
/* select the appropriate set of rewrite rules. */
  rules = TdictGet(active_rules,ofs);
  if(!rules)
    return trm;
  complexenv = apply_rule(ar, rules, trm);
  env = get_env(complexenv);
  if(!is_fail_env(env)) {
    newtrm = get_term(complexenv);
    trm = rewrite(ar, newtrm, env);
  }
  return trm;
}
#line 866 "evaluator.c.nw"
aterm_list *rewrite_args(arena *ar, aterm_list *args,aterm_list *env)
{
  aterm *arg,*newarg;
  aterm_list *newargs = t_empty(NULL);
  int len = TlistSize(args);

  if(len > 32) {
    while(!t_is_empty(args)) {
      arg = t_list_first(args);
      if(asfix_is_appl(arg) || asfix_is_var(arg) ||
         asfix_is_list(arg) || asfix_is_lex(arg)) 
        newarg = rewrite(ar, arg,env);
      else
        newarg = arg;
      newargs = TlistAppend(ar, newargs, newarg);
      args = t_list_next(args);
    }
  } else {
    aterm *newarg_table[32];
    int i = 0;
    Tprotect(newargs);
    while(!t_is_empty(args)) {
      arg = t_list_first(args);
      if(asfix_is_appl(arg) || asfix_is_var(arg) ||
         asfix_is_list(arg) || asfix_is_lex(arg)) 
        newarg_table[i] = rewrite(ar, arg,env);
      else
        newarg_table[i] = arg;
      args = t_list_next(args);
      ++i;
    }
    assert(i==len);
    for(--i; i > 0; i--) {
      newarg_table[i] = TbuildList(the_world, newarg_table[i], newargs);
      Tunprotect(newargs);
      newargs = newarg_table[i];
    }
    newargs = TmkList(ar, newarg_table[0], newargs);
  }
  return newargs;
}
#line 915 "evaluator.c.nw"
aterm_list *rewrite_elems(arena *ar, aterm *sym,aterm_list *elems,aterm_list *env)
{
  aterm *elem,*newelem;
  aterm_list *newelems = t_empty(NULL);
  int len = TlistSize(elems);

  if(len >= 0) {
    while(!t_is_empty(elems)) {
      elem = t_list_first(elems);
      newelem = rewrite(ar, elem, env);
      if(t_is_list(newelem))
        newelems = TlistConcat(ar, newelems, newelem);
      else
        newelems = TlistAppend(ar, newelems, newelem);
      elems = t_list_next(elems);
    }
  } else {
    aterm *newelem_table[32];
    int i = 0;
    Tprotect(newelems);
    while(!t_is_empty(elems)) {
      elem = t_list_first(elems);
      newelem_table[i] = rewrite(ar, elem, env);
      elems = t_list_next(elems);
      i++;
    }
    for(--i; i>0; i--) {
      newelem = newelem_table[i];
      if(t_is_list(newelem)) {
        newelem = TlistConcat(ar, newelem, newelems);
        Tprotect(newelem);
      } else {
        newelem = TbuildList(the_world, newelem, newelems);
      }
      Tunprotect(newelems);
      newelems = newelem;
    }
    newelem = newelem_table[i];
    if(t_is_list(newelem))
      newelems = TlistConcat(ar, newelem, newelems);
    else
      newelems = TmkList(ar, newelem, newelems);
  }
  return newelems;
}
#line 974 "evaluator.c.nw"
aterm *rewrite(arena *ar, aterm *trm,aterm_list *env)
{
  aterm *newtrm,*sym,*rewtrm;
  aterm_list *args,*newargs;
  aterm_list *elems,*newelems;
  arena local;

  TinitArena(NULL, &local);

  if(asfix_is_appl(trm)) {
    args = asfix_get_appl_args(trm);
    if(!args)
      Tprintf(stderr, "trm = %t\n", trm);
    newargs = rewrite_args(&local, args,env);
    if(asfix_is_bracket_func(trm)) {
      newtrm = t_list_first(t_list_next(newargs));
      return newtrm;
    }
    else {
      newtrm = asfix_put_appl_args(&local,trm,newargs);
      t_protect(newtrm);
      TflushArena(&local);
      Tadd2Arena(&local, newtrm);
      t_unprotect(newtrm);
      rewtrm = select_and_rewrite(&local, newtrm);
    }
  }
  else if(asfix_is_var(trm)) {
    if(TdictGet(env,trm))
      rewtrm = v_lookup(trm,env);
    else 
      rewtrm = trm;
  }
  else if(asfix_is_list(trm)) {
    elems = asfix_get_list_elems(trm);
    sym = asfix_get_list_sym(trm);
    newelems = rewrite_elems(&local, sym, elems, env);
    rewtrm = asfix_put_list_elems(&local, trm, newelems);
  }
  else
    rewtrm = trm;
  Tadd2Arena(ar, rewtrm);
  TdestroyArena(&local);
  return rewtrm;
}

#line 1026 "evaluator.c.nw"
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
  t_protect(fail_env);
  TBeventloop();

  return 0;
}
