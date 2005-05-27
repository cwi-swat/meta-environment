/*{{{  header */

/*

   ToolBus -- The ToolBus Application Architecture
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

*/

/*}}}  */

/*{{{  includes */

#include "toolbus.h"
#include "terms.h"
#include "env.h"
#include "match.h"
#include "procs.h"
#include "tools.h"
#include "utils.h"
#include "interpreter.h"
#include "partners.h"
#include "typecheck.h"

/*}}}  */

#define CALLSDB(x)

extern proc_def_list *Definitions; /* defined in interpreter.c */

static int n_expanded_calls = 0;

term_list *replace_formals_list(term_list *tl, env *e);

/*{{{  proc *replace_formals(proc *p, env *e) */

proc *replace_formals(proc *p, env *e)
{
  switch(tkind(p)){
    case t_bool:
    case t_int:
    case t_real:
    case t_str:
    case t_bstr:
    case t_placeholder:
      return p;
    case t_var:
      {
	term * t = value(p, e);
	if(is_result_var(t) && !is_result_var(p)){
	  t = mk_var_idx(var_sym(t), var_type(t));
	}
	return t;
      }
    case t_appl:
      return mk_appl(fun_sym(p), replace_formals_list(fun_args(p), e));
    case t_list:
      return replace_formals_list(p, e);
    default: err_fatal("expand_body: %t, %t", p, e);
	     return NULL; /* pedantic */
  }
}

/*}}}  */
/*{{{  term_list *replace_formals_list(term_list *tl, env *e) */

term_list *replace_formals_list(term_list *tl, env *e)
{
  term head, *prev;
  assert(is_list(tl));

  /* CALLSDB(TBmsg("replace_formals_list(%t,%t) ... \n", tl, e);) */
  prev = &head;
  for(next(&head) = tl; tl; tl = next(tl)){
    next(prev) = mk_list(replace_formals(first(tl), e), next(tl));
    prev = next(prev);
  }
  /* CALLSDB(TBmsg("replace_formals_list returns %t\n", next(&head));) */

  return next(&head);
}

/*}}}  */

term_list *expand_calls_list(sym_idx procName, term_list *tl);

/*{{{  proc *expand_calls(proc *P) */

proc *expand_calls(sym_idx procName, proc *P)
{
  switch(tkind(P)){
    case t_bool:
    case t_int:
    case t_real:
    case t_str:
    case t_bstr:
    case t_placeholder:
    case t_var:
      return P;
    case t_appl:
      if(is_call(P)){
	env *e;
	proc *P1;
	proc_def *pd = definition(var_sym(first(fun_args(P))));

	if(!pd)
	  err_fatal("expand_calls -- undefined process name %s", get_txt(var_sym(first(fun_args(P)))));
	n_expanded_calls++;
	CALLSDB(TBmsg("expanding %t\n", P);)
	  e = create_env(pd_formals(pd), get_txt(pd_name(pd)), next(fun_args(P)), NULL);
	P1 = replace_formals(pd_body(pd), e);
	CPC_join(pd_name(pd), procName);
	
	CALLSDB(TBmsg("into %t\n", P1);)
	  return P1;
      } else {
	return mk_appl(fun_sym(P), expand_calls_list(procName, fun_args(P)));
      }
    case t_list:
      return expand_calls_list(procName, P);

    default: err_fatal("expand_body: %t", P);
	     return NULL; /* pedantic */
  }
}

/*}}}  */
/*{{{  proc *expand_dyncall(sym_idx procName, proc *P, env *Env) */

proc *expand_dyncall(sym_idx procName, proc *P, env *Env)
{   env *e;
    proc *P1;
    char *proc_name;

    term *Name = elm1(fun_args(P));
    term *args = elm2(fun_args(P));
    coords *c = elm3(fun_args(P));
    term *Val;
    proc_def *pd;
					
    assert(is_str(Name) || is_var(Name));
    Val = is_str(Name) ? Name : value(Name, Env);

    if(!is_str(Val))
         err_fatal("expand_dyncall -- process name should be a string instead of '%t' in %t\n", Val, P);

    proc_name = str_val(Val);
    pd = definition(TBlookup(proc_name));

    if(!pd)
	err_fatal("Cannot create process name %s", proc_name);
    n_expanded_calls++;
    CALLSDB(TBmsg("expanding %t\n", P);)
    if(check_formal_actual(TBlookup(proc_name), c, proc_name, pd_formals(pd), args)) {
	e = create_env(pd_formals(pd), get_txt(pd_name(pd)), args, Env);
	P1 = replace_formals(pd_body(pd), e);
	CPC_join(pd_name(pd), procName);
	CALLSDB(TBmsg("into %t\n", P1);)
	    return P1;
    } else
       err_fatal("Cannot create process %s since formals/actuals do not match", proc_name);
    return Delta;
}

/*}}}  */

/*{{{  term_list *expand_calls_list(sym_idx procName, term_list *tl) */

term_list *expand_calls_list(sym_idx procName, term_list *tl)
{
  term head, *prev;
  assert(is_list(tl));

  /* CALLSDB(TBmsg("expand_calls_list(%t) ... \n", tl);) */
  prev = &head;
  for(next(&head) = tl; tl; tl = next(tl)){
    next(prev) = mk_list(expand_calls(procName, first(tl)), next(tl));
    prev = next(prev);
  }
  /* CALLSDB(TBmsg("expand_calls_list returns %t\n", next(&head));) */

  return next(&head);
}

/*}}}  */
/*{{{  void expand_all_calls() */

void expand_all_calls()
{
  proc_def_list *pdl;
  proc_def *pd;
  int nexp;

  for(nexp = -1, n_expanded_calls = 0; nexp != n_expanded_calls; ){
    nexp = n_expanded_calls;

    for(pdl = Definitions ; pdl; pdl = next(pdl)){
      pd = first(pdl);
      CALLSDB(TBmsg("Before[%d]: %t\n\n", n_expanded_calls, pd);)
	pd_body(pd) = expand_calls(pd_name(pd), pd_body(pd));
      CALLSDB(TBmsg("After[%d]: %t\n", n_expanded_calls, pd);)
    }
  }
}

/*}}}  */
