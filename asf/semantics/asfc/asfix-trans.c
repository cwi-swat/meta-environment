#include <tb-tool.h>
#include <string.h>
#include <asfix.h>
#include <term-list.h>
#include <abbrevs.h>
#include <ctype.h>

extern aterm *pattern_asfix_cbo_symbol;
extern aterm *pattern_asfix_cbc_symbol;
extern aterm *pattern_asfix_plus_symbol;
extern aterm *pattern_asfix_star_symbol;
extern aterm *pattern_asfix_comma_symbol;
extern aterm *pattern_asfix_arrow_symbol;
extern aterm *pattern_asfix_assign_symbol;
extern aterm *pattern_asfix_equal_symbol;
extern aterm *pattern_asfix_notequal_symbol;
extern aterm *pattern_asfix_ws;
extern aterm *pattern_asfix_ews;
extern aterm *pattern_asfix_nlws;
extern aterm *pattern_asfix_ws_pattern;
extern aterm *pattern_asfix_prod;
extern aterm *pattern_asfix_prodskel;
extern aterm *pattern_asfix_group;
extern aterm *pattern_asfix_agroup;
extern aterm *pattern_asfix_incrchain;
extern aterm *pattern_asfix_decrchain;
extern aterm *pattern_asfix_appl;
extern aterm *pattern_asfix_list;
extern aterm *pattern_asfix_simplelist;
extern aterm *pattern_asfix_iter;
extern aterm *pattern_asfix_itersep;
extern aterm *pattern_asfix_neg;
extern aterm *pattern_asfix_lex;
extern aterm *pattern_asfix_var;
extern aterm *pattern_asfix_term;
extern aterm *pattern_asfix_asfcons;
extern aterm *pattern_asfix_cat;
extern aterm *pattern_asfix_cat2;
extern aterm *pattern_asfix_str;
extern aterm *pattern_asfix_int;
extern aterm *pattern_asfix_sort;
extern aterm *pattern_asfix_l;
extern aterm *pattern_asfix_ql;
extern aterm *pattern_asfix_charclass;
extern aterm *pattern_asfix_sep;
extern aterm *pattern_asfix_noattrs;
extern aterm *pattern_asfix_attrs;
extern aterm *pattern_asfix_contextfreesyntax;
extern aterm *pattern_asfix_lexicalsyntax;
extern aterm *pattern_asfix_variables;
extern aterm *pattern_asfix_sorts;
extern aterm *pattern_asfix_priorities;
extern aterm *pattern_asfix_imports;
extern aterm *pattern_asfix_exports;
extern aterm *pattern_asfix_hiddens;
extern aterm *pattern_asfix_id;
extern aterm *pattern_asfix_CHAR;
extern aterm *pattern_asfix_ceqequ;
extern aterm *pattern_asfix_ceqimpl;
extern aterm *pattern_asfix_ceqwhen;
extern aterm *pattern_asfix_noequations;
extern aterm *pattern_asfix_equations;
extern aterm *pattern_asfix_condition;
extern aterm *pattern_asfix_module;

aterm_list *localvars;
aterm_list *allvars;
aterm_list *localconds;

int is_sep(aterm *sep);

aterm *unique_var(arena *ar,aterm *var)
{
  char *text, *newtext;
  aterm *term,*newvar;
  int n = 1;

  assertp(TmatchTerm(var,pattern_asfix_var,&text,&term));
  newtext = malloc(strlen(text)+6);
  sprintf(newtext,"%s%d",text,n);
  newvar = TmakeTerm(ar,pattern_asfix_var,newtext,term);
  while(TlistSearch(allvars,newvar) != -1) {
    n++;
    sprintf(newtext,"%s%d",text,n);
    newvar = TmakeTerm(ar,pattern_asfix_var,newtext,term);
  }
  free(newtext);
/*Tprintf(stderr,"Unique new var: %t\n", newvar);*/
  return newvar;
}

aterm *mll_in_argslist(arena *ar, aterm *arglist);
aterm *mll_in_appl(arena *ar, aterm *appl)
{
  aterm *prod, *w, *applargs, *newapplargs;

  assertp(TmatchTerm(appl,pattern_asfix_appl,&prod,&w,&applargs));
  newapplargs = mll_in_argslist(ar,applargs);
  return TmakeTerm(ar,pattern_asfix_appl,prod,w,newapplargs);
}

aterm *mll_in_list(arena *ar, aterm *list)
{
  aterm *term, *w, *listargs, *newlistargs;
 
  assertp(TmatchTerm(list,pattern_asfix_list,&term,&w,&listargs));
  newlistargs = mll_in_argslist(ar,listargs);
  return TmakeTerm(ar,pattern_asfix_list,term,w,newlistargs);
}

aterm *mll_in_var(arena *ar, aterm *var)
{
  aterm *newvar;
  aterm *newcond;

  if(TlistSearch(localvars,var) == -1) {
    localvars = TlistAppend(ar,localvars,var);
    return var;
  }
  else {
    newvar = unique_var(ar,var);
    localvars = TlistAppend(ar,localvars,newvar);
    newcond = TmakeTerm(ar,pattern_asfix_condition,
                        var,pattern_asfix_ws,
                        pattern_asfix_equal_symbol,
                        pattern_asfix_ws,newvar);
    localconds = TlistAppend(ar,localconds,newcond);
    return newvar;
  }
}

aterm *mll_in_term(arena *ar, aterm *term)
{
  char *text;
  aterm *t[3];

  if(TmatchTerm(term,pattern_asfix_appl,&t[0],&t[1],&t[2]))
    return mll_in_appl(ar,term);
  else if(TmatchTerm(term,pattern_asfix_var,&text,&t[0]))
    return mll_in_var(ar,term);
  else if(TmatchTerm(term,pattern_asfix_list,&t[0],&t[1],&t[2]))
    return mll_in_list(ar,term);
  else
    return term;
}

aterm_list *mll_in_args(arena *ar, aterm_list *args)
{
  aterm *arg, *newarg;
  aterm_list *newargs = t_empty(NULL);

  if(!t_is_empty(args)) {
    arg = t_list_first(args);
    if(AFnotLayout(arg) && !is_sep(arg))
      newarg = mll_in_term(ar,arg);
    else
      newarg = arg;
    newargs = TlistAppend(ar,newargs,newarg);
    args = t_list_next(args);
    return TlistConcat(ar,newargs,mll_in_args(ar,args));
  }
  else
    return newargs;
}

aterm *mll_in_argslist(arena *ar, aterm *arglist)
{
  aterm_list *args, *newargs;

  assertp(TmatchTerm(arglist,pattern_asfix_simplelist,&args));
  if(!t_is_empty(args)) {
    newargs = mll_in_args(ar,args);
    return TmakeTerm(ar,pattern_asfix_simplelist,newargs);
  }
  else 
    return arglist;
}  

aterm_list *mll_in_cond(arena *ar, aterm *cond)
{
  aterm *lhs,*rhs,*w[2],*l;
  aterm *newrhs, *newcond;
  aterm_list *newconds;

  assertp(TmatchTerm(cond,pattern_asfix_condition,
                     &lhs,&w[0],&l,&w[1],&rhs));
  newconds = t_empty(NULL);
  if(TmatchTerm(l,pattern_asfix_assign_symbol)) {
    localconds = t_empty(NULL);
    newrhs = mll_in_term(ar,rhs);
    if(!t_is_empty(localconds)) {
      newcond = TmakeTerm(ar,pattern_asfix_condition,
                          lhs,w[0],pattern_asfix_assign_symbol,w[1],newrhs);
      newconds = TlistConcat(ar, newconds, 
                             TmkList_n(ar,4,
                                       newcond,
                                       pattern_asfix_ws,
                                       TmakeTerm(ar,pattern_asfix_sep,","),
                                       pattern_asfix_nlws));
      newconds = TlistConcat(ar, newconds, localconds);
    }
    else
      newconds = TlistAppend(ar, newconds, cond);
  }
  else
    newconds = TlistAppend(ar, newconds, cond);
  return newconds;
}

aterm_list *mll_in_conds(arena *ar, aterm_list *conds)
{
  aterm *cond;
  aterm_list *newcond;
  aterm_list *newconds = t_empty(NULL);
  arena local;

  TinitArena(t_world(*ar), &local);
  while(!t_is_empty(conds)) {
    cond = t_list_first(conds);
    if(AFnotLayout(cond) && !is_sep(cond)) {
      newcond = mll_in_cond(&local,cond);
      newconds = TlistConcat(&local, newconds, newcond);
    }
    else
      newconds = TlistAppend(&local, newconds, cond);
    conds = t_list_next(conds);
  }
  Tadd2Arena(ar,newconds);
  TdestroyArena(&local);
  return newconds;
}

aterm *mll_in_eq(arena *ar, aterm *eq)
{
  aterm *lhs, *newlhs;
  aterm_list *conds, *newconds;
  aterm *id,*l[3],*w[4],*rhs;
  aterm *neweq;

/* The new created conditions are stored globally.
   The global variable list is used when creating
   new variables names to ensure uniqueness. */
  localconds = t_empty(NULL);
  allvars = localvars;
  localvars = t_empty(NULL);
  lhs = asfix_get_equ_lhs(eq);
  newlhs = mll_in_term(ar,lhs);
  conds = AFgetEquConds(eq);
  newconds = t_empty(NULL);
  if(!t_is_empty(conds)) {
    if(!t_is_empty(localconds)) {
      newconds = TlistConcat(ar,newconds,localconds);
      newconds = TlistConcat(ar, newconds, 
                             TmkList_n(ar,3,
                                       pattern_asfix_ws,
                                       TmakeTerm(ar,pattern_asfix_sep,"\",\""),
                                       pattern_asfix_nlws));
    }
    newconds = TlistConcat(ar,newconds,mll_in_conds(ar,conds));
    neweq = AFputEquConds(ar,eq,newconds);
    return neweq;
  }
  else {
    if(!t_is_empty(localconds)) {
      TmatchTerm(eq, pattern_asfix_ceqequ,
                 &id,&w[0],&l[0],&w[1],&lhs,&w[2],&l[1],&w[3],&rhs);
      newconds = TlistConcat(ar,newconds,localconds);
      return TmakeTerm(ar, pattern_asfix_ceqimpl,
                       id,w[0],l[0],w[1],newconds,
                       pattern_asfix_nlws,
                       TmakeTerm(ar,pattern_asfix_l,"======="),
                       pattern_asfix_nlws,
                       newlhs,w[2],l[1],w[3],rhs);
    }
    else
      return eq;
 }
}

void mac_argslist(arena *ar, aterm *args);
void mac_appl(arena *ar, aterm *appl)
{
  aterm *prod, *w, *applargs;

  assertp(TmatchTerm(appl,pattern_asfix_appl,&prod,&w,&applargs));
  mac_argslist(ar,applargs);
}

void mac_list(arena *ar, aterm *list)
{
  aterm *term,*w,*listargs;
  
  assertp(TmatchTerm(list,pattern_asfix_list,&term,&w,&listargs));
  mac_argslist(ar,listargs);
}

void mac_var(arena *ar, aterm *var)
{
  if(TlistSearch(localvars,var) == -1)
    localvars = TlistAppend(ar,localvars,var);
}

void mac_term(arena *ar, aterm *term)
{
  char *text;
  aterm *t[3];

  if(TmatchTerm(term,pattern_asfix_appl,&t[0],&t[1],&t[2]))
    mac_appl(ar,term);
  else if(TmatchTerm(term,pattern_asfix_var,&text,&t[0]))
    mac_var(ar,term);
  else if(TmatchTerm(term,pattern_asfix_list,&t[0],&t[1],&t[2]))
    mac_list(ar,term);
}

void mac_args(arena *ar, aterm *args)
{
  aterm *arg;

  if(!t_is_empty(args)) {
    arg = t_list_first(args);
    if(AFnotLayout(arg) && !is_sep(arg))
      mac_term(ar,arg);
    args = t_list_next(args);
    mac_args(ar,args);
  }
}

void mac_argslist(arena *ar, aterm *arglist)
{
  aterm_list *args;

  assertp(TmatchTerm(arglist,pattern_asfix_simplelist,&args));
  if(!t_is_empty(args))
    mac_args(ar,args);
}

aterm *mac_in_cond(arena *ar, aterm *cond)
{
  aterm *lhs,*rhs,*w[2],*l;
  aterm_list *oldvars;
  
  assertp(TmatchTerm(cond,pattern_asfix_condition,
                     &lhs,&w[0],&l,&w[1],&rhs));
  if(TmatchTerm(l,pattern_asfix_notequal_symbol))
    return cond;
  else if(TmatchTerm(l,pattern_asfix_assign_symbol)) {
    mac_term(ar,rhs);
    return cond;
  }
  else {
    assertp(TmatchTerm(l,pattern_asfix_equal_symbol));
    oldvars = localvars;
    mac_term(ar,lhs);
    if(t_equal(oldvars,localvars)) {
      oldvars = localvars;
      mac_term(ar,rhs);
      if(t_equal(oldvars,localvars))
        return cond;
      else 
        return TmakeTerm(ar,pattern_asfix_condition,
                         lhs,w[0],pattern_asfix_assign_symbol,w[1],rhs);
    }
    else {
      oldvars = localvars;
      mac_term(ar,rhs);
      if(t_equal(oldvars,localvars))
        return TmakeTerm(ar,pattern_asfix_condition,
                         rhs,w[0],pattern_asfix_assign_symbol,w[1],lhs);
      else {
        Tprintf(stderr,
                "Both sides of the condition %t introduce new variables.\n",
                cond);
        exit(1);
      }
    }
    return cond;
  }
}

aterm_list *mac_in_conds(arena *ar, aterm_list *conds)
{
  aterm *cond,*newcond;
  aterm_list *newconds = t_empty(NULL);
  arena local;
  
  TinitArena(t_world(*ar), &local);
  while(!t_is_empty(conds)) {
    cond = t_list_first(conds);
    if(AFnotLayout(cond) && !is_sep(cond)) {
      newcond = mac_in_cond(&local,cond);
      newconds = TlistAppend(&local, newconds, newcond);
    }
    else
      newconds = TlistAppend(&local, newconds, cond);
    conds = t_list_next(conds);
  }
  Tadd2Arena(ar,newconds);
  TdestroyArena(&local);
  return newconds;
}

aterm *mac_in_eq(arena *ar, aterm *eq)
{
  aterm *lhs;
  aterm_list *conds, *newconds;

  localvars = t_empty(NULL);
  lhs = asfix_get_equ_lhs(eq);
  mac_term(ar,lhs);
  conds = AFgetEquConds(eq);
  if(!t_is_empty(conds)) {
    newconds = mac_in_conds(ar,conds);
    return AFputEquConds(ar,eq,newconds);
  }
  else
    return eq;
}

aterm *trans_in_eq(arena *ar, aterm *eq)
{
  aterm *maceq;
  
  maceq = mac_in_eq(ar, eq);
  return mll_in_eq(ar, maceq);
}

aterm_list *trans_in_eqs(arena *ar, aterm_list *eqs)
{
  aterm *eq,*neweq;
  aterm_list *neweqs = t_empty(NULL);
  arena local;
  
  TinitArena(t_world(*ar), &local);
  while(!t_is_empty(eqs)) {
    eq = t_list_first(eqs);
    if(AFnotLayout(eq)) {
      neweq = trans_in_eq(&local,eq);
      neweqs = TlistAppend(&local, neweqs, neweq);
    }
    else
      neweqs = TlistAppend(&local,neweqs,eq);
    eqs = t_list_next(eqs);
  }
  Tadd2Arena(ar,neweqs);
  TdestroyArena(&local);
  return neweqs;
}

aterm *asfix_trans(arena *ar,aterm *mod)
{
  aterm *newmod;
  aterm_list *eqs, *neweqs;
  arena local;
  
  eqs = AFgetModuleEqs(mod);
  if(!t_is_empty(eqs)) {
    TinitArena(t_world(*ar), &local);
    neweqs = trans_in_eqs(&local,eqs);
    newmod = AFputModuleEqs(&local,mod,neweqs);
    Tadd2Arena(ar,newmod);
    TdestroyArena(&local);
    return newmod;
  }
  else
    return mod;
}
