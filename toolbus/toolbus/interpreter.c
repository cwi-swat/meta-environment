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
#include "procs.h"
#include "tools.h"
#include "match.h"
#include "utils.h"
#include "interpreter.h"
#include "monitor.h"
#include "typecheck.h"
#include <math.h>
#include <time.h>
#include <sys/signal.h>
#include <signal.h>

/*}}}  */
/*{{{  typedefs */

typedef term note;
typedef term_list note_list;
typedef term subs;
typedef term_list subs_list;
typedef term procs;

/*}}}  */
/*{{{  variables */

static int nproc = 0;                /* # of ToolBus processes */

time_t startup_time;                 /* used in main.c */

static time_t current_time = 0;
static time_t next_abs_delay = 0;
static time_t next_abs_timeout = 0;

static proc_inst *current_ProcInst;  /* PROTECTED */

#define update_env_of_atom(Atom,Env) if(!at_env(Atom)) at_env(Atom) = Env

/* Not static for debug purposes */
procs *AllProcesses = NULL;  /* PROTECTED */

proc_def_list *Definitions = NULL;  /* PROTECTED */
/* used in calls.c */

int atomic_step_count = 0;


/*}}}  */

/*{{{  static functions */

static ap_form *expand(proc *P, env *Env);
static term *itp(term *T, proc_inst *ProcInst);
static TBbool find_comm(atom *Atom1, atom **Atom2, proc **P2,
			proc_inst **comm_ProcInst, term *Processes);

/*}}}  */

/*{{{  proc_def *definition(sym_idx sym) */

proc_def *definition(sym_idx sym)
{
  proc_def_list *pdl;

  for(pdl = Definitions ; pdl; pdl = next(pdl)){    
    if(pd_name(first(pdl)) == sym)
      return first(pdl);
  }
  return NULL;
}

/*}}}  */

/*{{{  void add_proc_def(char *pname,  term_list *formals, term_list *vars, proc *p, */

void add_proc_def(char *pname,  term_list *formals, term_list *vars, proc *p,
		  term *script_name, int lino)
{
  if(definition(TBlookup(pname)))
    tc_double_decl("process name", pname, script_name, lino);
  else {
    proc_def *pd = mk_proc_def(pname, formals, vars, p);
    check_formals_vars(formals, vars, script_name, lino);

    Definitions = mk_list(pd, Definitions);
  }
}

/*}}}  */

static proc *propagate_env(proc *P, env *e);
proc *replace_formals(proc *p, env *e);

/*{{{  static proc_id *create_process(sym_idx pname, term_list *args,  */

static proc_id *create_process(sym_idx pname, term_list *args, 
			       tool_id *parent_db, subs_list *parent_subs,
			       note_list *parent_notes)
{
  proc_def *pd = definition(pname);
  env *Env1, *Env2;
  proc *body;
  ap_form *AP;
  proc_inst *ProcInst;
  proc_id *pid;

  if(!pd) {
    err_fatal("process %s not defined\n", get_txt(pname));
  }

  if(TBverbose) {
    fprintf(stderr, "create_process %d: %s\n", nproc, get_txt(pname));
  }

  pid = mk_int(nproc);
  Env1 = NULL;
  Env2 = create_env(pd_formals(pd), get_txt(pd_name(pd)), args, Env1);

  body = pd_body(pd);
  body = replace_formals(body, Env2);
  ProcInst = mk_proc_inst((ap_form *)NULL,
			  Env1, 
			  list_copy(parent_subs), 
			  list_copy(parent_notes), 
			  mk_str(get_txt(pname)), 
			  pid,




			  parent_db);
  AP = expand(propagate_env(mk_dot(body, Delta), Env1), Env1);
  if(!is_list(AP))
    AP = mk_list(AP, NULL);
  pi_alts(ProcInst) = AP;

  AllProcesses = mk_list(ProcInst, AllProcesses);
  nproc++;
  return pid;
}

/*}}}  */
/*{{{  void create_toolbus(term *monitor) */

void create_toolbus(term *monitor)
{ 
  extern proc *initial_toolbus_proc;  /*created by parser */

  if(monitor){
    assert(is_monitor(monitor));
    initial_toolbus_proc =
      mk_dot(mk_atom(a_rec_connect,
		     mk_list1(mk_result_var("Mid", "INIT", mk_appl(fun_sym(monitor), NULL))),
		     NULL),
	     initial_toolbus_proc);
  }
  add_proc_def("INIT", NULL, NULL, initial_toolbus_proc, mk_str("INIT"), 0);
  create_process(TBlookup("INIT"), NULL, monitor, NULL, NULL);
}

/*}}}  */

/*{{{  static atom *attach_cond(atom *Atom, term *Cond) */

static atom *attach_cond(atom *Atom, term *Cond)
{
  term *old, *new;
  atom *new_atom;  

  assert(is_atom(Atom));
  old = at_conds(Atom);
  if(old){
    new = mk_conds(conds_abs_delay(old),
		   conds_abs_timeout(old),
		   mk_appl2(e_and, conds_test(old), Cond));

  } else
    new = mk_conds(-1,-1,Cond);
  new_atom = mk_atom(at_fun(Atom), at_args(Atom), at_coords(Atom));
  at_env(new_atom) = at_env(Atom);
  at_conds(new_atom) = new;
  has_conds(new_atom) = TBtrue;
  /* TBmsg("attach_cond (old): %t\n", Atom); */
  /* TBmsg("attach_cond (new): %t\n", new_atom); */
  return new_atom;
}

/*}}}  */
/*{{{  static void def_next_timer(time_t abs_delay, time_t abs_timeout) */

static void def_next_timer(time_t abs_delay, time_t abs_timeout)
{
  if((abs_delay >= current_time) &&
     ((next_abs_delay < 0) || ((abs_delay > 0) && (abs_delay < next_abs_delay))))
    next_abs_delay = abs_delay;

  if((next_abs_timeout < 0) || 
     ((abs_timeout > 0) && (abs_timeout < next_abs_timeout) && (abs_timeout > current_time)))
    next_abs_timeout = abs_timeout;
}

/*}}}  */
/*{{{  static atom *attach_timer(atom *Atom, time_t abs_delay, time_t abs_timeout) */

static atom *attach_timer(atom *Atom, time_t abs_delay, time_t abs_timeout)
{
  term *old;

  assert(is_atom(Atom));
  old = at_conds(Atom);
  if(old){
    conds_abs_delay(old) = abs_delay;
    conds_abs_timeout(old) = abs_timeout;
  } else {
    at_conds(Atom) = mk_conds(abs_delay,abs_timeout,True);
    has_conds(Atom) = TBtrue;
  }
  /* TBmsg("attach_timer(%d,%d): %d %t\n", abs_delay, abs_timeout, current_time, Atom); */

  if((abs_delay > 0) && (abs_timeout > 0) && (abs_delay > abs_timeout))
    TBmsg("%t: delay %d exceeds timeout %d\n", Atom, abs_delay, abs_timeout);

  def_next_timer(abs_delay, abs_timeout);
  return Atom;
}

/*}}}  */
/*{{{  static time_t mk_abs_time(term_list *tl) */

static time_t mk_abs_time(term_list *tl)
{
  struct tm *t = localtime(&current_time);
  term_list *args;
  int h, m, s, n, k;
  time_t tm;

  n = list_length(tl);
  if((n > 6) || (n < 3)){
    err_warn("absolute time wrong number of arguments in: %t", tl);
    return 0;
  }

  for(args = tl; args; args = next(args)){
    if(!is_int(first(args))){
      err_warn("arguments of absolute time definition must be integer in: %t", tl);
      return 0;
    }
  }
  if(n == 6){                 /* year */
    k = int_val(first(tl));
    if(!(k >= 95)){
      err_warn("wrong value for year in: %t", tl);
      return 0;
    }
    t->tm_year = k;
    tl = next(tl);
    n--;
  }
  if(n == 5){                 /* month */
    k = int_val(first(tl));
    if(!((k >= 1) && (k <= 12))){
      err_warn("wrong value for month in: %t", tl);
      return 0;
    }
    t->tm_mon = k;
    tl = next(tl);
    n--;
  }
  if(n == 4){                /* day in month */
    k = int_val(first(tl));
    if(!((k >= 1) && (k <= 31))){
      err_warn("wrong value for day in %t", tl);
      return 0;
    }
    t->tm_mday = k;
    tl = next(tl);
    n--;
  }
  h = int_val(elm1(tl));
  if(!((h >= 0) && (h < 23))){
    err_warn("wrong value for hour in: %t", tl);
    return 0;
  }
  t->tm_hour = h;
  m = int_val(elm2(tl));
  if(!((m >= 0) && (m <= 59))){
    err_warn("wrong value for minutes in: %t", tl);
    return 0;
  }
  t->tm_min = m;
  s = int_val(elm3(tl));
  if(!((s >= 0) && (s <= 61))){
    err_warn("wrong value for seconds in: %t", tl);
    return 0;
  }
  t->tm_sec = s;

  tm = mktime(t);
  if(tm == -1)
    err_fatal("cannot convert time");
  return tm;
}

/*}}}  */
/*{{{  static term *mk_current_time(void) */

static term *mk_current_time(void)
{
  struct tm *t = localtime(&current_time);

  return mk_list6(mk_int(t->tm_year), mk_int(t->tm_mon + 1), mk_int(t->tm_mday), 
		  mk_int(t->tm_hour), mk_int(t->tm_min), mk_int(t->tm_sec));
}

/*}}}  */

#define is_enabled(Atom, ProcInst) (!has_conds(Atom) || do_is_enabled(Atom,ProcInst))

/*{{{  static TBbool do_is_enabled(atom *Atom, proc_inst *ProcInst) */

static TBbool do_is_enabled(atom *Atom, proc_inst *ProcInst)
{
  /* TBmsg("is_enabled(%t), pi_env=%t\n", Atom, pi_env(ProcInst)); */
  assert(is_atom(Atom));

  if(has_conds(Atom)){
    term *conds = at_conds(Atom);
    term *test = conds_test(conds);
    term *test_res;
    test_res = itp(test, ProcInst);
    if(is_bool(test_res)){
      time_t abs_delay = conds_abs_delay(conds);
      time_t abs_timeout = conds_abs_timeout(conds);
      TBbool b = bool_val(test_res) && 
	((abs_delay < 0) || (current_time >= abs_delay)) &&
	((abs_timeout < 0) || (current_time < abs_timeout));

      def_next_timer(abs_delay, abs_timeout);
      /* TBmsg("condition = %s\n", (b) ? "true" : "false");*/
      return b;
    } else
      return TBfalse;        
  }
  return TBtrue; 
}

/*}}}  */

/*--- expand  ----------------------------------*/

/* sum: computes a process expression of the
 * form: p1 + p2 + p3 + ...
 * The arguments are interchanged randomly.
 */

#define CHOICE (rand() & 01)

/*{{{  static proc *sum(proc *p1, proc *p2) */

static proc *sum(proc *p1, proc *p2)
{
  if(CHOICE){
    proc *p3 = p1;
    p1 = p2;
    p2 = p3;
  }
  if(is_delta(p1))                 /* sum(delta, AP) = AP */
    return p2;
  if(is_delta(p2))                 /* sum(AP, delta) = AP */
    return p1;
  if(is_list(p1) && is_list(p2))   /* sum(<OAPs1>, <OAPs2>) = <OAPs1 + OAPs2> */
    return list_concat(p1, p2);
  if(is_atom(p1) && is_list(p2)){  /* sum(Atom, <OAPs>) = <Atom + OAPs> */
    return mk_list(p1, p2);
  }
  if(is_semi(p1) && is_list(p2)){  /* sum(Atom;P, <OAPs>) = <Atom;P + OAPs> */
    return mk_list(p1, p2);
  }
  if(is_list(p1) && is_atom(p2)){  /* sum(<OAPs>, Aom) = <Atom, OAPs> */
    return mk_list(p2, p1);
  }
  if(is_list(p1) && is_semi(p2)){   /* sum(<OAPs>, Atom;P>) = <Atom;P + OAPs> */
    return mk_list(p2, p1);
  }
  return                           /* sum(AP1, AP2) = <AP1 + AP2> */
    mk_list2(p1,p2);
}

/*}}}  */
/*{{{  static ap_form *dot(ap_form *AP, proc *P2) */

static ap_form *dot(ap_form *AP, proc *P2)
{
  if(is_list(AP)){
    term_list *res = NULL;

    for( ; AP; AP = next(AP)){
      ap_form *Q = first(AP);
      if(is_semi(Q)){          /* dot(<Atom;P1 + OAPs>, P2) =
				  sum(Atom;(P1.P2), dot(<OAPs>, P2) */
	res = sum(mk_semi(left(Q), mk_dot(right(Q), P2)), res);
      } else if(is_delta(Q))
	continue;
      else if(is_atom(Q)){
	res = sum(mk_semi(Q, P2), res);
      } else
	err_fatal("dot (1): %t", Q);
    }
    return res;
  } else {
    switch(pkind(AP)){
      case a_delta:	       /* dot(delta, P2) = delta */
	return AP;
      case p_semi:               /* dot(Atom;P1, P2) = Atom;(P1.P2) */
	return mk_semi(left(AP), mk_dot(right(AP), P2));
      default:
	if(is_atom(AP)){
	  return mk_semi(AP, P2);
	} else
	  err_fatal("dot (2) %t", AP);
	return Delta; /* pedantic */
    }
  }
}

/*}}}  */
/*{{{  static ap_form *lmerge(ap_form *AP, proc *P) */

static ap_form *lmerge(ap_form *AP, proc *P)
{
  if(is_list(AP)){
    term_list *res = NULL;

    for( ; AP; AP = next(AP)){ /* lmerge(<AP + OAPs>, P)  =
				  sum(lmerge(AP, P), lmerge(<OAPs>, P)) */
      ap_form *Q = first(AP);
      if(is_delta(Q))
	continue;
      else
	res = sum(lmerge(Q, P), res);
    }
    return res;
  } else {
    switch(pkind(AP)){
      case a_delta:	       /* lmerge(delta, P2) = delta */
	return AP;
      case p_semi:               /* lmerge(Atom;P1, P2) = Atom;(P1 || P2) */
	return mk_semi(left(AP), mk_fmerge(right(AP), P));
      default:
	if(is_atom(AP)){          /* lmerge(Atom, P2) = Atom;P2 */
	  return mk_semi(AP, P);
	} else
	  err_fatal("lmerge: %t", AP);
	return Delta; /* pedantic */
    }
  }
}

/*}}}  */
/*{{{  static ap_form *add_cond(term *T, ap_form *AP) */

static ap_form *add_cond(term *T, ap_form *AP)
{
  /* TBmsg("add_cond: T = %t, AP = %t\n", T, AP); */
  if(is_list(AP)) {
    term_list *res = NULL;
    for( ; AP; AP = next(AP)){
      ap_form *Q = first(AP);
      if(is_semi(Q)){
	res = mk_list(mk_semi(attach_cond(left(Q), T), right(Q)), res);
      } else
	if(is_atom(Q)){
	  res = mk_list(attach_cond(Q,T), res);
	}
	else
	  err_fatal("add_cond (1): %t", Q);
    }
    /* TBmsg("res = %t\n\n", res); */
    return res;
  } else {
    switch(pkind(AP)){
      case a_delta:
	return AP;
      case p_semi:
	return mk_semi(attach_cond(left(AP), T), right(AP));
      default:
	if(is_atom(AP)){
	  return attach_cond(AP, T);
	} else
	  err_fatal("add_cond (2): %t", AP);
	return Delta; /* pedantic */
    }
  }
}

/*}}}  */
/*{{{  static proc *force_null_env(proc *P) */

static proc *force_null_env(proc *P)
{  
  /* TBmsg("force_null_env: %t\n", P); */
  if(!P)
    return P;
  if(is_atom(P)){
    at_env(P) = NULL;
    return P;
  } else {
    switch(pkind(P)){

      case p_fmerge:
      case p_lmerge:
      case p_plus:
      case p_star:
      case p_semi:
      case p_dot:
	left(P) = force_null_env(left(P));
	right(P) = force_null_env(right(P));
	return P;
      case p_if:
	if_then(P) = force_null_env(if_then(P));
	if_else(P) = force_null_env(if_else(P));	
	return P;

      case p_let:
	let_env(P) = NULL;
	return P;

      case p_timer:
	at_env(timer_atom(P)) = NULL;
	return P;

      case p_call:
      case p_execute:

	return P;
      default:
	err_fatal("force_null_env: %t", P);
	return NULL; /* pedantic */
    }
  }
}

/*}}}  */
/*{{{  static proc *propagate_env(proc *P, env *Env) */

static proc *propagate_env(proc *P, env *Env)
{ 
  /* TBmsg("propagate: %t, %t\n", P, Env); */
  if(!P)
    return P;
  if(is_atom(P)){
    /* TBmsg("propagate, before: %t\n", P); */
    update_env_of_atom(P,Env);
    /* TBmsg("propagate, updated: %t\n", P);*/
    return P;
  } else {
    switch(pkind(P)){

      case p_fmerge:
      case p_lmerge:
      case p_plus:
      case p_star:
      case p_semi:
      case p_dot:
	left(P) = propagate_env(left(P), Env);
	right(P) = propagate_env(right(P), Env);
	return P;

      case p_if:
	if_then(P) = propagate_env(if_then(P),Env);
	if_else(P) = propagate_env(if_else(P),Env);	
	return P;

      case p_let:
	if(!let_env(P))
	  let_env(P) = Env;
	return P;

      case p_timer:
	if(!at_env(timer_atom(P)))
	  at_env(timer_atom(P)) = Env;
	return P;

      case p_execute: /* TREAT THESE TWO CASES PROPERLY, WHERE DO WE PUT THE ENV? */
	return P;

      case p_call:  /* Should not appear, is already expanded */
      default:
	err_fatal("propagate_env: %t", P);
	return NULL; /* pedantic */
    }
  }    
}

/*}}}  */

/*{{{  static ap_form *expand(proc *P, env *Env) */

static ap_form *expand(proc *P, env *Env)
{
  proc *P1, *P2, *res;

  /* TBmsg("expand: %t\n", P); */

  assert(P);

  if(is_atom(P)){
    return P;
  } else {    

    P1 = left(P);
    switch(pkind(P)){

      case p_dot:
	switch(pkind(P1)){
	  case p_dot:                  /* exp((P1.P2).P3) = exp(P1.(P2.P3)) */

	    return expand(mk_dot(left(P1), mk_dot(right(P1), right(P))), Env);

	  case p_call:                 /* exp(Pnm(OptTs) . P2) = dot(expand(Pnm(OptTs)), P2) */

	    err_fatal("expand -- unexpected call: %t", P);
	    res = dot(expand(P1, Env), right(P));
	    return res;
	  case p_if:
	    res = dot(expand(P1, Env), right(P));
	    return res;

	  case p_star:                  /* exp( P1 . P2) = left(P1) . (left(P1) * right(P1)) . P2 +  right(P1) . P2
					 *
					 / \
					 left(P1)   right(P1)
					 */
	    P2 = right(P);
	    return sum(expand(mk_dot(left(P1), mk_dot(mk_star(left(P1), right(P1)), P2)), Env), 
		       expand(mk_dot(right(P1), P2), Env));


	  default:                     /* exp(P1.P2) = dot(expand(P1),P2) */

	    return dot(expand(P1,Env),right(P));
	}


      case p_plus:                   /* exp((P1+P2)) = sum(exp(P1), exp(P2)) */

	return sum(expand(P1, Env), expand(right(P), Env));

      case p_star:                   /* exp( P ) = sum(exp(P1.P1*P2), exp(P2))
				      *
				      /  \
				      P1    P2 */

	P2 = right(P);
	return sum(expand(mk_dot(P1, mk_star(P1, P2)), Env), 
		   expand(P2, Env));

      case p_fmerge:
	{ ap_form *res;

	  P2 = right(P);
	  if(is_fmerge(P1)){        /*  exp( P1 || P2) = exp(left(P1) || (right(P1) || P2))
					||
					/ \
					left(P1)   right(P2) */

	    res = expand(mk_fmerge(left(P1), mk_fmerge(right(P1), P2)), Env);

	  } else {                      /* exp(P1 || P2) = sum(exp(P1 ||_ P2), exp(P2 ||_ P1)) */
	    if(term_equal(P1, P2))
	      res = expand(P1, Env);
	    else  {   
	      res = sum(expand(mk_lmerge(P1, P2), Env), 
			expand(mk_lmerge(P2, P1), Env));
	    }
	  }
	  /*	
		TBprintf(stderr, "*** fmerge: arg1 = %t\n", P1);
		TBprintf(stderr, "*** fmerge: arg2 = %t\n", P2);
		print_alts(res);
		*/

	  return res;
	}

      case p_lmerge:
	P2 = right(P);
	if(is_lmerge(P1))            /* exp((P1 ||_ P2) ||_ P3) = exp(P1 ||_ (P2 ||_ P3)) */

	  return expand(mk_lmerge(left(P1), mk_lmerge(right(P1), P2)), Env);
	else                         /* exp(P1 ||_ P2) = lmerge(exp(P1), P2) */

	  return lmerge(expand(P1, Env), P2);

      case p_if:
	{ term *test = if_test(P);
	  proc *th = if_then(P), *el = if_else(P);
	  if(el){
	    res =
	      sum(expand(mk_if(test, th, NULL), Env), 
		  expand(mk_if(mk_appl1(e_not, test), el, NULL), Env));

	    return res;
	  } else {
	    res = add_cond(test, expand(th, Env));
	    return res;
	  }
	}

      case p_let:
	{
	  term_list *vars = let_vars(P);
	  proc *B = let_body(P);
	  env *LetEnv = let_env(P);
	  /* TBmsg("p_let, %t, Env= %t\n", vars, LetEnv);  */
	  B = force_null_env(B);

	  LetEnv = define(vars, LetEnv);
	  B = propagate_env(B, LetEnv);
	  B = expand(B, LetEnv);
	  /* TBmsg("let returns: %t\n", B); */
	  return B;
	}

      case p_execute:
	{ term_list *args = fun_args(P);
	  term *creator; var *v; coords *c;
	  atom *Atom, *Atom2;

	  assert(list_length(args) == 3);
	  creator = substitute(elm1(args), Env);  assert(is_appl(creator));
	  v = elm2(args);        assert(is_result_var(v));
	  c = elm3(args);        assert(is_coords(c));
	  Atom = mk_atom(a_snd_execute_to_tool, mk_list1(creator), c);
	  update_env_of_atom(Atom, Env);
	  Atom2 = mk_atom(a_rec_connect, mk_list1(v), c);
	  update_env_of_atom(Atom2, Env);
	  return mk_semi(Atom, Atom2);
	}
      case p_timer:
	{ atom *Atom = timer_atom(P);
	  term *delay = timer_delay(P); 
	  term *timeout = timer_timeout(P);
	  int delay_t = -1, timeout_t = -1;
	  term *val;

	  /* time(&current_time); */
	  switch(pkind(delay))
	  {
	    case p_no_delay: break;
	    case p_abs_delay:
			     delay_t = mk_abs_time(itp(first(fun_args(delay)), current_ProcInst)); /** << */
			     break;
	    case p_delay:
			     val = itp(left(delay), current_ProcInst); /** << */
			     assert(is_int(val));
			     delay_t = int_val(val) + current_time;
			     break;
	    default:
			     err_fatal("illegal delay kind");
	  }
	  switch(pkind(timeout))
	  { 
	    case p_no_timeout: break;
	    case p_abs_timeout:
			       timeout_t = mk_abs_time(itp(first(fun_args(timeout)), current_ProcInst)); /** << */
			       break;
	    case p_timeout:
			       val = itp(left(timeout), current_ProcInst);  /** << */
			       assert(is_int(val));
			       timeout_t = int_val(val) + current_time;
			       break;
	    default:
			       err_fatal("illegal timeout kind");
	  }	
	  attach_timer(Atom, delay_t, timeout_t);
	  update_env_of_atom(Atom, Env);
	  return Atom;
	}

      default:

	err_fatal("expand, top level: %t", P);
	return Delta; /* pedantic */
    }
  }
}

/*}}}  */

/* ------------------ Notes ----------------------------*/

/*{{{  static term_list *del_pat(term *T, term_list *Ts) */

static term_list *del_pat(term *T, term_list *Ts)
{
  term_list head, *prev;

  assert(is_list(Ts));
  prev = &head;
  for(next(&head) = Ts; Ts; Ts = next(Ts)){
    if(cmatchp(T, first(Ts))){
      next(prev) = next(Ts);
    }
    prev = Ts;
  }
  return next(&head);
}

/*}}}  */
/*{{{  static TBbool match_note(term *Note, note_list **Notes) */

static TBbool match_note(term *Note, note_list **Notes)
{
  note_list head, *prev;
  note_list *Notes1 = *Notes;
  term *ClosNote = substitute(Note, pi_env(current_ProcInst));

  /* TBmsg("match_note: %t in %t\n", Note, Notes1); */

  assert(is_list(Notes1));
  prev = &head;
  for(next(&head) = Notes1; Notes1; Notes1 = next(Notes1)){
    if(cmatchp(ClosNote, first(Notes1))){
      next(prev) = next(Notes1);
      *Notes = next(&head);
      /* TBmsg("returns true\n"); */
      return TBtrue;
    }
    prev = Notes1;
  }
  /* TBmsg("returns false\n"); */
  return TBfalse;
}

/*}}}  */
/*{{{  static TBbool no_note(term *Note, note_list *Notes) */

static TBbool no_note(term *Note, note_list *Notes)
{

  /* TBmsg("no_note: %t, %t\n", Note, Notes); */

  assert(is_list(Notes));
  for( ; Notes; Notes = next(Notes)){
    if(cmatchp(Note, first(Notes))){
      /* TBmsg("no_note: false\n"); */
      return TBfalse;
    }
  }
  /* TBmsg("no_note: true\n"); */
  return TBtrue;
}

/*}}}  */
/*{{{  static TBbool matching_subscription(term *T, subs_list *Subscriptions) */

static TBbool matching_subscription(term *T, subs_list *Subscriptions)
{
  while(Subscriptions){
    if(cmatchp(first(Subscriptions), T))
      return TBtrue;
    Subscriptions = next(Subscriptions);
  }
  return TBfalse;
}

/*}}}  */
/*{{{  static void distr_note(term *Note) */

static void distr_note(term *Note)
{
  procs * Processes;
  proc_inst *ProcInst;

  for(Processes = AllProcesses; Processes; Processes = next(Processes)){
    ProcInst = first(Processes);
    if(matching_subscription(Note, pi_subs(ProcInst))){
      pi_notes(ProcInst) = list_concat_term(pi_notes(ProcInst), Note);
    }
  }
}

/*}}}  */

/* ----------------------- expressions ------------*/

static proc_inst *itp_ProcInst = NULL;         /* PROTECTED */
static term *itp1(term *);

/*{{{  static term *itp(term *T, proc_inst *ProcInst) */

static term *itp(term *T, proc_inst *ProcInst)
{
  itp_ProcInst = ProcInst;
  return itp1(T);
}

/*}}}  */

/*{{{  static term *itp1(register term *T) */

static term *itp1(register term *T)
{
  term *V[3];
  struct expr_sign *es;
  term_list *args;
  int i;

  /* TBmsg("itp1(%t)\n", T); */

  if(!T)
    return T;

  switch(tkind(T)){
    case t_bool: case t_int: case t_real: case t_str:
      return T;
    case t_var:
      V[0] = value(T, pi_env(itp_ProcInst));
      if(V[0] == T){
	err_warn("%t: undefined value\n", T); 
	return NULL;
      } else
	return V[0];

    case t_list:
      { term_list head, *prev;

	prev = &head;
	for(next(&head) = T; T; T = next(T)){
	  next(prev) = mk_list(itp1(first(T)), next(T));
	  prev = next(prev);
	}
	return next(&head);
      }
    case t_appl:

      if(!is_expr_fun(T)){    
	if(fun_args(T))
	  err_warn("undefined function: %t\n", T);
	return T;
      }
      es = get_expr_sign(fun_sym(T));
      if(list_length(fun_args(T)) != es->nargs){
	err_warn("%t: %d argument(s) required\n", T, es->nargs);\
	  return NULL;
      }
      args = fun_args(T);
      if(es->evargs){
	for(i = 0; i < es->nargs; i++){
	  V[i] = itp1(first(args));
	  args = next(args);
	  if(!require_type(es->argtype[i], V[i])){
	    err_warn("%t: argument %d has wrong type\n", T, i+1);
	    return NULL;
	  }
	}
      }		  

      if(es->func)
	return (*es->func)(es->nargs, V, itp_ProcInst);

      switch(fun_sym(T)){
	case e_is_bool:
	  return is_bool(V[0]) ? True : False;
	case e_is_int:
	  return is_int(V[0]) ? True : False;
	case e_is_real:
	  return is_real(V[0]) ? True : False;
	case e_is_str:
	  return is_str(V[0]) ? True : False;
	case e_is_bstr:  
	  return is_bstr(V[0]) ? True : False;   
	case e_is_appl:
	  return is_appl(V[0]) ? True : False;
	case e_fun:
	  return is_appl(V[0]) ? mk_str(get_txt(fun_sym(V[0]))) : mk_str("");
	case e_args:    
	  return is_appl(V[0]) ? fun_args(V[0]) : NULL;
	case e_is_list:
	  return is_list(V[0]) ? True : False;
	case e_is_empty:
	  return V[0] ? False : True;

	case e_is_var:
	  return is_var(first(fun_args(T))) ? True : False;
	case e_is_result_var:
	  return is_result_var(first(fun_args(T))) ? True : False;
	case e_is_formal:
	  return is_formal(first(fun_args(T))) ? True : False;

	case e_true:
	  return True;
	case e_false:
	  return False;
	case e_quote:
	  return substitute(first(fun_args(T)), pi_env(itp_ProcInst));
	case e_not: 
	  return bool_val(V[0]) ? False : True;   
	case e_and: 
	  return (bool_val(V[0]) && bool_val(V[1])) ? True : False;
	case e_or: 
	  return (bool_val(V[0]) || bool_val(V[1])) ? True : False;
	case e_equal: 
	  return term_equal(V[0], V[1]) ? True : False;
	case e_not_equal: 
	  return term_equal(V[0], V[1]) ? False : True;

	case e_add: 
	  return mk_int(int_val(V[0]) + int_val(V[1]));
	case e_sub: 
	  return mk_int(int_val(V[0]) - int_val(V[1]));
	case e_mul: 
	  return mk_int(int_val(V[0]) * int_val(V[1]));
	case e_div:
	  return mk_int(int_val(V[0]) / int_val(V[1]));      
	case e_mod: 
	  return mk_int(int_val(V[0]) % int_val(V[1]));
	case e_abs: 
	  return mk_int(abs(int_val(V[0])));
	case e_less: 
	  return (int_val(V[0]) < int_val(V[1])) ? True : False;
	case e_less_equal: 
	  return (int_val(V[0]) <= int_val(V[1])) ? True : False;
	case e_greater: 
	  return (int_val(V[0]) > int_val(V[1])) ? True : False;
	case e_greater_equal: 
	  return (int_val(V[0]) >= int_val(V[1])) ? True : False;


	case e_radd: 
	  return mk_real(real_val(V[0]) + real_val(V[1]));
	case e_rsub: 
	  return mk_real(real_val(V[0]) - real_val(V[1]));
	case e_rmul: 
	  return mk_real(real_val(V[0]) * real_val(V[1]));
	case e_rdiv:
	  return mk_real(real_val(V[0]) / real_val(V[1]));
	case e_rless: 
	  return (real_val(V[0]) < real_val(V[1])) ? True : False;
	case e_rless_equal: 
	  return (real_val(V[0]) <= real_val(V[1])) ? True : False;
	case e_rgreater: 
	  return (real_val(V[0]) > real_val(V[1])) ? True : False;
	case e_rgreater_equal: 
	  return (real_val(V[0]) >= real_val(V[1])) ? True : False;
	case e_sin:
	  return mk_real((double) sin(real_val(V[0])));
	case e_cos:
	  return mk_real(cos(real_val(V[0])));
	case e_atan:
	  return mk_real(atan(real_val(V[0])));
	case e_atan2:
	  return mk_real(atan2(real_val(V[0]), real_val(V[1])));
	case e_exp:
	  return mk_real(exp(real_val(V[0])));
	case e_log:
	  return mk_real(log(real_val(V[0])));
	case e_log10:
	  return mk_real(log10(real_val(V[0])));
	case e_sqrt:
	  return mk_real(sqrt(real_val(V[0])));
	case e_rabs:
	  return mk_real(fabs(real_val(V[0])));

	case e_size:
	  return mk_int(list_length(V[0]));
	case e_index:
	  return list_index(V[0], int_val(V[1]));
	case e_replace:
	  return list_replace(V[0], int_val(V[1]), V[2]);
	case e_get:
	  return list_get(V[0], V[1]);
	case e_put:
	  return list_put(V[0], V[1], V[2]);

	case e_first:
	  return (V[0]) ? first(V[0]) : NULL;

	case e_next:
	  return (V[0]) ? next(V[0]) : NULL;

	case e_member:
	  return list_elem(V[0], V[1]) ? True : False;
	case e_subset:
	  return list_subset(V[0], V[1]) ? True : False;

	case e_diff: 
	  return list_diff(V[0], V[1]);
	case e_inter: 
	  return list_inter(V[0], V[1]);
	case e_join:
	  return list_join(V[0], V[1]);
	  /* <PO> this is done in the system module now.
	     case e_functions:
	     return mk_functions();
	     */

	  /* Note: in the following two lines a mysterious divide by 10
	     is necessary, why??
	     */
	case e_sec:
	  return V[0];
	case e_msec:
	  return mk_int(int_val(V[0])/1000);
	case e_current_time:
	  return mk_current_time();

	case e_process_id:
	  return pi_pid(itp_ProcInst);
	case e_process_name:
	  return pi_name(itp_ProcInst);
      }

    default:
      err_fatal("itp1");
      return False; /* pedantic */
  }
}

/*}}}  */


/* ----------------------- atomic_steps -----------*/

/*{{{  static TBbool simple_atomic_step(atom *Atom) */

static TBbool simple_atomic_step(atom *Atom)
{
  switch(at_fun(Atom)){

    case a_tau:
      return TBtrue;
    case a_rec_note:
      { note_list *Notes = pi_notes(current_ProcInst);
	term *arg = substitute(first(at_args(Atom)), pi_env(current_ProcInst));

	if(match_note((note *) arg, &Notes)){
	  pi_notes(current_ProcInst) = Notes;
	  pi_env(current_ProcInst) = update(pi_env(current_ProcInst), Bindings1);
	  add_free_list(Bindings1); Bindings1 = NULL;
	  return TBtrue;
	} else
	  return TBfalse;
      }
    case a_no_note:
      { note_list *Notes = pi_notes(current_ProcInst);
	term *arg = substitute(first(at_args(Atom)), pi_env(current_ProcInst));

	return no_note((note *) arg, Notes);	
      }
    case a_subscribe:
      { term *NotePat = substitute(first(at_args(Atom)), pi_env(current_ProcInst));

	if(has_no_vars(NotePat)){
	  pi_subs(current_ProcInst) = mk_list(NotePat,  pi_subs(current_ProcInst));
	  return TBtrue;
	} else {
	  err_warn("subscription pattern %t may not contain variables", NotePat);
	  /** attach_cond(Atom, False); werkt niet, want geeft copie **/
	  return TBfalse;
	}
      }
    case a_unsubscribe:
      { term *NotePat = substitute(first(at_args(Atom)), pi_env(current_ProcInst));

	pi_subs(current_ProcInst) = del_pat(NotePat,  pi_subs(current_ProcInst));
	pi_notes(current_ProcInst) = del_pat(NotePat, pi_notes(current_ProcInst));
	return TBtrue;
      }				      
    case a_printf:
      { term_list *args = substitute_list(at_args(Atom), pi_env(current_ProcInst));
	term *format = first(args);
	assert(is_str(format));
	tbgen_printf(str_val(format),next(args));
	/* add_free_list(args); */
	return TBtrue;
      }
    case a_read:
      { term_list *args = substitute_list(at_args(Atom), pi_env(current_ProcInst));
	term *prompt;
	term *pat, *inp;
	int cnt;

	assert(list_length(args) == 2);
	prompt = elm1(args);
	pat = elm2(args);
	for(cnt = 0; cnt < 10; cnt++){
	  inp = read_and_parse_from_stdin(prompt, pat);
	  if(match(pat, inp, pi_env(current_ProcInst), NULL)){
	    pi_env(current_ProcInst) = update(pi_env(current_ProcInst), Bindings1);
	    return TBtrue;
	  }
	  err_warn("read: given input does not match %t, retry", pat);
	  if(cnt == 3){
	    TBprintf(stderr, "\n*** HELP: Input for this read command:\n");
	    TBprintf(stderr, "(1) should fit on a single line ending with a newline character\n");
	    TBprintf(stderr, "(2) the complete line should match %t\n", pat);
	    TBprintf(stderr, "Do not forget [ and ] surrounding lists and , to separate list elements\n");   
	    TBprintf(stderr, "Do not forget double quotes surrounding strings\n");
	    TBprintf(stderr, "*** END OF HELP, trying to get new input ...\n\n");
	  }
	}
	err_warn("read: giving up after %d attempts\n", cnt);
	return TBfalse;
      }

    case a_snd_eval: case a_snd_do: case a_snd_ack_event:
      { term_list *args = substitute_list(at_args(Atom), pi_env(current_ProcInst));
	TBbool res = write_to_tool(at_fun(Atom), args);
	/* add_free_list(args); */
	return res;
      }

    case  a_create:
      { term_list *args = at_args(Atom);
	term *pcall;
	var *v; proc_id *pid;

	assert(list_length(args) == 2);
	pcall = substitute(first(args), pi_env(current_ProcInst));
	assert(is_appl(pcall));

	v = first(next(args));
	assert(is_result_var(v));
	/* Create the process; Note: changes AllProcesses! */
	pid = create_process(fun_sym(pcall),
			     fun_args(pcall),
			     pi_mon(current_ProcInst),   /* inherit of current process */
			     pi_subs(current_ProcInst),
			     pi_notes(current_ProcInst));
	pi_env(current_ProcInst) = assign(v, pid, pi_env(current_ProcInst));
	/* add_free_list(args); */
	return TBtrue;
      }
    case a_snd_execute_to_tool:
      { term_list *args = substitute_list(at_args(Atom), pi_env(current_ProcInst));
	term *arg;
	TBbool create_tool(term *);
	assert(list_length(args) == 1);
	assert(is_appl(first(args)));
	arg = first(args);
	/* add_free_list(args); */
	
	return create_tool(arg) ? TBtrue : TBfalse;
      }
    case a_snd_terminate:
      { term_list *args = substitute_list(at_args(Atom), pi_env(current_ProcInst));
	TBbool res = write_to_tool(a_snd_terminate, args);
	/* add_free_list(args); */
	return res;
      }
    case a_snd_monitor:         

      /* Note: no substitutions should be made in snd_monitor's arguments,
	 otherwise variables occurring in its environment component would be
	 substituted away.
	 */
      return write_to_tool(a_snd_monitor, at_args(Atom));

    case a_assign:
      {
	term *args = at_args(Atom); var *v; term *val;

	assert(list_length(args) == 2);
	v = first(args);
	val = itp(first(next(args)), current_ProcInst);
	if(require_type(var_type(v), val)){
	  pi_env(current_ProcInst) = assign(v, val, pi_env(current_ProcInst));
	  return TBtrue;
	} else {
	  TBmsg("type mismatch in assignment: %t := %t\n", v, val);
	  return TBfalse;
	}
      }

    case a_shutdown:
      {
	term *args = substitute_list(at_args(Atom), pi_env(current_ProcInst));
	extern void bus_shutdown(term *);

	assert(list_length(args) == 1);
	bus_shutdown(first(args));
	return TBtrue; /* never executed */
      }

    default:
      return TBfalse;
  }
}

/*}}}  */
/*{{{  static void nu(atom *Atom, proc *P, proc_inst *ProcInst1, proc_inst *ProcInst2) */

static void nu(atom *Atom, proc *P, proc_inst *ProcInst1, proc_inst *ProcInst2)
{
  term *mon;
  extern atom *mk_snd_monitor(term *, atom *, proc *P, proc_inst *, proc_inst *);

  if((mon = pi_mon(ProcInst1)) && 
     (at_fun(Atom) != a_snd_monitor) && (at_fun(Atom) != a_rec_continue) &&
     !((pi_pid(ProcInst1) == 0) && (at_fun(Atom) == a_rec_connect))){

    assert(is_monitor(mon));
    switch(fun_sym(mon)){
      case mon_logger:
	/* pi_alts(ProcInst1) = 
	   mk_list(mk_semi(mk_snd_monitor(mon, Atom, P, ProcInst1, ProcInst2), 
	   P), NULL);
	   return; */
      case mon_viewer:

	P = mk_semi(mk_snd_monitor(mon, Atom, P, ProcInst1, ProcInst2),
		    mk_dot(mk_atom(a_rec_continue, mk_list2(mon, pi_pid(ProcInst1)), NULL),
			   P)),
	/* TBmsg("nu, P = %t\n", P); */
	P = propagate_env(P, at_env(Atom));
	pi_alts(ProcInst1) = mk_list(P, NULL);
	return;

      case mon_controller:
	err_fatal("controller not yet implemented");
      default:
	err_fatal("nu -- illegal monitor kind: %t", mon);
    }
  } else { 
    ap_form *AP;
    /* Atom may have modified pi_env(ProcInst1), e.g. by a let construct
     * Propagate Atom's initial environment.
     */

    P = propagate_env(P, at_env(Atom)); /* <<< */
    AP = expand(P, pi_env(ProcInst1)); /* << which Env should we use here? **/
    if(!is_list(AP))
      AP = mk_list(AP, NULL);

    pi_alts(ProcInst1) = AP;
    return;
  }
}

/*}}}  */

/*{{{  static void atomic_steps(void) */

static void atomic_steps(void)
{   
  TBbool work = TBtrue;
  term *Processes, *Previous, *all_alts, *alts, *alt;
  proc *P;
  atom *Atom;
  ap_form *AP;

  while(work){
    work = TBfalse;

    Previous = NULL;
    atomic_step_count++;
    for(Processes = AllProcesses; Processes; Previous = Processes, Processes = next(Processes)){
      TBcollect();
      current_ProcInst = first(Processes);

#if 0
      if (atomic_step_count > 580) {
	fprintf(stderr, "atomic_step_count: %d\n", atomic_step_count);
	print_process(current_ProcInst);
      }
#endif

      /* TBmsg("Process: %t\n", current_ProcInst); */
      /* TBmsg("Process: %d, %t\n", int_val(pi_pid(current_ProcInst)), pi_env(current_ProcInst));
	 print_alts(pi_alts(current_ProcInst));*/

      for(all_alts = alts = pi_alts(current_ProcInst); alts; alts = next(alts)){
	assert(is_list(alts));
	alt = first(alts);

	/* TBmsg("\nalt: %t\n", alt); */

	if(is_delta(alt)){
	  if(list_length(all_alts) == 1){
	    /* Remove current  process if it can only do a delta */
	    if(Previous){
	      next(Previous) = next(Processes);
	      Processes = AllProcesses;
	    } else {
	      if(next(AllProcesses)) {
		AllProcesses = next(AllProcesses);
		Processes = AllProcesses;
	      } else {
		extern void bus_shutdown(term *);
		/* shutdown when removing the last process */
		bus_shutdown(NULL);
	      }
	    }
	    work = TBtrue;
	    goto next_proc;
	  } 
	  continue;
	}
	if(is_semi(alt)){
	  Atom = left(alt);
	  assert(is_atom(Atom));
	  P = right(alt);
	} else {
	  assert(is_atom(alt));
	  Atom = alt;
	  P = Delta;
	}
	/* TBmsg("Atom = %t\n", Atom); */
	pi_env(current_ProcInst) = at_env(Atom);
	if(!is_enabled(Atom, current_ProcInst))
	  continue;
	/* TBmsg("Atom = %t is enabled\n", Atom); */
	if(simple_atomic_step(Atom)){
	  nu(Atom, P, current_ProcInst, NULL);
	  work = TBtrue;
	  /* TBmsg("simple_atomic_step: %t\n", Atom); */
	  add_free_list(all_alts);
	  if(rand() & 0111){     /* randomly exchange current process with next one */
	    /* TBmsg("reshuffle after %t\n", Atom); */
	    if(next(Processes)){
	      first(Processes) = first(next(Processes));
	      first(next(Processes)) = current_ProcInst;	    
	    } else {
	      if(Previous){
		next(Previous) = NULL;
		AllProcesses = mk_list(current_ProcInst, AllProcesses);
	      }
	    }
	  }
	  goto next_proc;
	} else {
	  switch(at_fun(Atom)){

	    case a_endlet:
	      pi_env(current_ProcInst) = undefine(at_args(Atom), pi_env(current_ProcInst));
	      P = propagate_env(P, pi_env(current_ProcInst));
	      AP = expand(P, pi_env(current_ProcInst));
	      /* Now merge the alternatives following endlet with the current
		 list of alternatives for this process */
	      if(!is_list(AP))
		AP = mk_list(AP, NULL);
	      if(alts == all_alts)
		pi_alts(current_ProcInst) = all_alts = alts = list_concat(AP, next(alts));
	      else {
		term *alts1 = list_concat(AP, next(alts));
		first(alts) = first(alts1);
		next(alts) = next(alts1);
	      }
	      /*
		 if(is_list(AP)){
		 if(alts == all_alts)
		 pi_alts(current_ProcInst) = all_alts = alts = list_concat(AP, next(alts));
		 else
		 alts = list_concat(AP, next(alts));
		 } else
		 first(alts) = AP;
		 */
	       work = TBtrue; 
	       goto next_proc;
	    case  a_snd_msg: case  a_rec_msg:
	      {
		proc_inst *comm_ProcInst; proc *P2; atom *Atom2;

		if(next(Processes) && find_comm(Atom, &Atom2, &P2, &comm_ProcInst,
						next(Processes)))
		{
		  nu(Atom, P, current_ProcInst, comm_ProcInst);
		  nu(Atom2, P2, comm_ProcInst, current_ProcInst);
		  /*TBmsg("current_ProcInst = %t\n\n", current_ProcInst);*/
		  /*TBmsg("comm_ProcInst = %t\n\n", comm_ProcInst);*/
		  work = TBtrue;
		  add_free_list(all_alts);
		  /* move current_ProcInst and comm_ProcInst to adjacent positions in the process list,
		     unless they are already next to each other */
		  if(comm_ProcInst != first(next(Processes))){
		    if(Previous)
		      next(Previous) = mk_list(comm_ProcInst, Processes);
		    else
		      AllProcesses = mk_list(comm_ProcInst, Processes);
		  }		
		  goto next_proc;
		}
		continue;
	      }
	    case  a_snd_note:	   
	      distr_note(substitute(first(at_args(Atom)), pi_env(current_ProcInst)));
	      nu(Atom, P, current_ProcInst, NULL);
	      work = TBtrue;
	      add_free_list(all_alts);
	      goto next_proc;	    
	    default:;

	  }
	}
      }
next_proc:;
    }
  }
}

/*}}}  */

/*{{{  static TBbool find_comm(atom *Atom1, atom **Atom2, proc **P2, */

static TBbool find_comm(atom *Atom1, atom **Atom2, proc **P2,
			proc_inst **comm_ProcInst, term *Processes)
{
  proc_inst *ProcInst;
  register atom *Atom;
  register ap_form *all_alts, *alt, *alts;
  term_list *Previous = NULL;

  for( ; Processes; Previous = Processes, Processes = next(Processes)){
    assert(is_list(Processes));
    ProcInst = first(Processes);

    for(all_alts = alts = pi_alts(ProcInst); alts; alts = next(alts)){
      assert(is_list(alts));
      alt = first(alts);

      /* TBmsg("alt: %t\n", alt); */
      if(is_delta(alt))
	continue;
      if(is_semi(alt)){
	Atom = left(alt);
	assert(is_atom(Atom));
      } else {
	assert(is_atom(alt));
	Atom = alt;
      }
      pi_env(ProcInst) = at_env(Atom);

      if(!is_enabled(Atom, ProcInst) || !communicate(at_fun(Atom1), at_fun(Atom)))
	continue;

      if(match(at_args(Atom1), at_args(Atom), pi_env(current_ProcInst), pi_env(ProcInst))){
	pi_env(current_ProcInst) = update(pi_env(current_ProcInst), Bindings1);
	pi_env(ProcInst) = update(pi_env(ProcInst), Bindings2);

	/* TBmsg("pi_env(current_ProcInst) = %t\n",  pi_env(current_ProcInst)); */
	/* TBmsg("pi_env(ProcInst)         = %t\n",  pi_env(ProcInst)); */

	add_free_list(Bindings1); Bindings1 = NULL;
	add_free_list(Bindings2); Bindings2 = NULL;
	*comm_ProcInst = ProcInst;
	*Atom2 = Atom;
	*P2 = right(alt);
	add_free_list(all_alts);
	/* remove this ProcInst from process list, unless it is the first one */
	if(Previous)
	  next(Previous) = next(Processes);
	return TBtrue;	  
      }
    }
  }
  return TBfalse;
}

/*}}}  */

/*--- rec_from_tool_step -----------------------*/

/*{{{  static TBbool in_selection(proc_inst *ProcInst, term *sel) */

static TBbool in_selection(proc_inst *ProcInst, term *sel)
{
  if(is_list(sel))
    return list_elem(pi_name(ProcInst), sel) || list_elem(pi_pid(ProcInst), sel);
  else
    return TBfalse;
  /* option permit "all" to select all processes */
}

/*}}}  */

/* Pending: list of not yet serviced events from tools, each element has the form
   [tool-inst, event]
   */

static term_list *Pending = NULL;

/*{{{  static TBbool rec_from_tool_step1(tool_inst *ti, term *Inp, int next_phase) */

static TBbool rec_from_tool_step1(tool_inst *ti, term *Inp, int next_phase)
{
  proc_inst *ProcInst;
  atom *Atom2;
  ap_form *alt, *alts;
  proc *P2;
  int next_phase1;
  procs *Processes;
  mon_method mkind;
  term_list *sel;
  term *mon;

  /*TBmsg("rec_from_tool_step1(%t,%t, %d)\n", ti, Inp, next_phase); */
  switch(fun_sym(Inp))
  {
    case a_snd_attach_monitor:
      assert(list_length(fun_args(Inp)) == 2);
      mkind = fun_sym(elm1(fun_args(Inp)));
      sel = elm2(fun_args(Inp));
      assert(is_list(sel));
      if((mkind == mon_logger) || (mkind == mon_viewer) || (mkind == mon_controller)){	
	mon = mk_appl(mkind, ti_tid(ti));
      } else {
	err_warn("illegal monitor kind: %s", get_txt(mkind));
	return TBfalse;
      }	

      for(Processes = AllProcesses; Processes; Processes = next(Processes)){
	ProcInst = first(Processes);
	if(in_selection(ProcInst, sel) && !pi_mon(ProcInst))
	  pi_mon(ProcInst) = ti_tid(ti);
      }
      ti_phase(ti) = next_phase;
      return TBtrue;

    case a_snd_detach_monitor:
      assert(list_length(fun_args(Inp)) == 1);
      sel = elm1(fun_args(Inp));
      assert(is_list(sel));

      for(Processes = AllProcesses; Processes; Processes = next(Processes)){
	ProcInst = first(Processes);
	if(in_selection(ProcInst, sel))
	  pi_mon(ProcInst) = NULL;
      }
      ti_phase(ti) = next_phase;
      return TBtrue;

    case a_snd_void:
      ti_phase(ti) = next_phase;
      return TBtrue;

    default:

      for(Processes = AllProcesses; Processes; Processes = next(Processes)){
	ProcInst = first(Processes);

	for(alts = pi_alts(ProcInst); alts; alts = next(alts)){
	  /* print_alts(alts); */
	  assert(is_list(alts));
	  alt = first(alts);
	  if(is_delta(alt))
	    continue;

	  assert(is_semi(alt));
	  Atom2 = left(alt); P2 = right(alt);
	  pi_env(ProcInst) = at_env(Atom2);
	  if(!is_enabled(Atom2, ProcInst) || !communicate(fun_sym(Inp), at_fun(Atom2)))
	    continue;
	  /* TBmsg("rec_from_tool_step, Atom2 = %t\n", Atom2);
	     TBmsg("env = %t\n", pi_env(ProcInst));*/

	  if(match(fun_args(Inp), at_args(Atom2), NULL, pi_env(ProcInst))){
	    /* Call TCP_transition to update ti, rather than updating
	       ti_phase directly. This takes care of the event/ack-event case where the list
	       of pending events has to be updated as well.
	       */
	    next_phase1 = TCP_transition(ti, Inp, TBtrue);
	    assert(next_phase == next_phase1);
	    pi_env(ProcInst) = update(pi_env(ProcInst), Bindings2);
	    nu(Atom2, P2, ProcInst, NULL);
	    if(fun_sym(Inp) == a_snd_disconnect){
	      extern tool_inst_list *Tools;

	      destroy_ports_for_tool(ti);
	      Tools = list_delete(Tools, ti);
	    } else if(fun_sym(Inp) == a_snd_connect){
	      tool_def *td = find_tool_def(fun_sym(first(fun_args(Inp))));

	      assert(td != NULL);
	      write_to_tool(a_snd_do,
			    mk_list2(mk_appl1(fun_sym(first(fun_args(Inp))), ti_tid(ti)),
				     mk_appl2(TBlookup("signature"), 
					      td_in_sign(td), 
					      td_out_sign(td))));
	    }
	    return TBtrue;	  
	  }
	}
      }
  }
  return TBfalse;
}

/*}}}  */

/*
 * occurs_in_out_sign_of_tool checks that Inp occurs in a given
 * output signature of a tool. Checked before queuing
 * Inp on the pending_events list in order to catch
 * unexpected output of tools.
 *
 */

/*{{{  static TBbool occurs_in_out_sign_of_tool(term *Inp, term_list *outsigs) */

static TBbool occurs_in_out_sign_of_tool(term *Inp, term_list *outsigs)
{
  for( ; outsigs; outsigs = next(outsigs)){
    if(fun_sym(Inp) == at_fun(first(outsigs)))
      if(cmatchp(fun_args(first(outsigs)), fun_args(Inp)))
	return TBtrue;
  }
  return TBfalse;
}

/*}}}  */
/*{{{  static TBbool pending_events(void) */

static TBbool pending_events(void)
{
  term_list *events = Pending;
  term_list head, *prev = &head;
  int k = 0;

  for(next(&head) = events; events; events = next(events)){
    term_list *ev_pair = first(events);
    tool_inst *ti1;
    term *ev1;
    int next_phase;

    assert(is_list(ev_pair));
    ti1 = first(ev_pair);
    ev1 = first(next(ev_pair));
    next_phase = TCP_transition(ti1, ev1, TBfalse);

    /*
       TBmsg("pending_events, considering %t\n", ev1);
       TBmsg("tool_instance = %t\n", ti1);
       TBmsg("next_phase = %d\n", next_phase);
       */

    if((next_phase >= 0) && rec_from_tool_step1(ti1, ev1, next_phase)){
      if(TBverbose)TBmsg("DEQUEU EVENT: %t\n", ev1);
      next(prev) = next(events);
      k++;
    } else {
      prev = events;
    }
  }
  Pending = next(&head);
  return k > 0;
}

/*}}}  */

/*{{{  void rec_from_tool_step(tool_inst *ti, term *Inp) */

void rec_from_tool_step(tool_inst *ti, term *Inp)
{
  int next_phase;

  pending_events();

  if(TBverbose) TBmsg("rec_from_tool_step(%t,%t)\n", ti, Inp);
  if(!is_legal_from_tool(fun_sym(Inp))){
    err_warn("%t: illegal function received from tool -- %t\n", Inp);
    return;
  }

  if((next_phase = TCP_transition(ti, Inp, TBfalse)) < 0){
    err_warn("**** %t: PROTOCOL ERROR -- %t\n", ti, Inp);
    return;
  }

  if(!rec_from_tool_step1(ti, Inp, next_phase)){
    tool_def *td = find_tool_def(ti_name(ti));

    assert(td);

    if(occurs_in_out_sign_of_tool(Inp, td_out_sign(td))){
      if(fun_sym(Inp) == a_snd_disconnect){
	extern tool_inst_list *Tools;

	ti_phase(ti) = next_phase;
	destroy_ports_for_tool(ti);
	Tools = list_delete(Tools, ti);
      } 
      if(TBverbose)TBmsg("QUEUED EVENT: %t FROM TOOL %t\n", Inp, ti);
      Pending = list_append(Pending, mk_list(mk_list2(ti, Inp), NULL));
    } else  {
      TBmsg("UNEXPECTED INPUT %t FROM TOOL %t IGNORED (sig=%t)\n",
	    Inp, ti, td_out_sign(td));
    }
  } else {
    if(TBverbose)TBmsg("new ti = %t\n", ti);
    pending_events();
  }
}

/*}}}  */

static struct timeval timeout;

/*{{{  struct timeval *get_timeout(void) */

struct timeval *get_timeout(void)
{
  /* fprintf(stderr, "\nget_timeout: current_time = %ld, next_abs_delay = %ld\n",
     (long)current_time, (long)next_abs_delay); */

  if(current_time <= next_abs_delay){
    double delta_t = next_abs_delay - current_time;
    /* difftime is not available everywhere */
    if(delta_t >= 1){
      timeout.tv_sec = delta_t;
      timeout.tv_usec = 0;
      /* fprintf(stderr, "get_timeout: %f sec, %f usec (delta_t = %f)\n",   
	 timeout.tv_sec, timeout.tv_usec, delta_t); */
      return &timeout;
    }
  }
  return NULL;
}

/*}}}  */

/*{{{  static void alarm_handler(int sig) */

static void alarm_handler(int sig)
{
  time(&current_time);
  if((next_abs_timeout > 0) && (current_time > next_abs_timeout)){
    err_warn("***** Alarm: timeout expired");
  }
  alarm(1);
}

/*}}}  */

/*{{{  void all_internal_steps(void) */

void all_internal_steps(void)
{  
  struct sigaction act;
  struct sigaction oact;

  act.sa_handler = alarm_handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;

#ifdef SA_INTERRUPT
  act.sa_flags = SA_INTERRUPT;	/* SunOS */
#endif

  sigaction(SIGALRM, &act, &oact);
  time(&current_time);
  next_abs_delay = -1;
  do {
    if(TBverbose)
      fprintf(stderr, "current_time = %ld, next_abs_delay = %ld\n", 
	      (long)current_time, (long)next_abs_delay);
    next_abs_delay = -1;
    alarm(1);

    atomic_steps();
    time(&current_time);
  } while(((next_abs_delay != -1) && (next_abs_delay <= current_time)) ||
	  pending_events());
  alarm(0);
  /* reset alarm */
  sigaction(SIGALRM, &oact, NULL);
}

/*}}}  */

/*--- interpreter ------------------------------*/

/*{{{  static void prompt(void) */

static void prompt(void)
{
  if(stand_alone)
    fprintf(stdout, "%s", single_prompt);
}

/*}}}  */
/*{{{  void interpreter(void) */

void interpreter(void)
{
  term * e;
  tool_id *tid;

  if(TBverbose)
    fprintf(stderr, "Starting ToolBus interpreter ...\n");

  all_internal_steps();
  prompt();
  while(TBtrue){
    if((e = read_term(&tid))){
      /* TBmsg("read_term succeeded: e=%t\n", e); */
      rec_from_tool_step(tid, e);
      /* TBmsg("rec-from_tool_step done\n");*/
      all_internal_steps();
      /* TBmsg("all_internal_steps done\n");*/
    }
    prompt();
  }
}

/*}}}  */

/*{{{  void init_interpreter(void) */

void init_interpreter(void)
{
  extern proc *initial_toolbus_proc;  /*created by parser */

  TBprotect(&Definitions);
  TBprotect(&AllProcesses);
  TBprotect(&current_ProcInst);
  TBprotect(&itp_ProcInst);
  TBprotect(&Pending);  
  TBprotect(&initial_toolbus_proc);
}

/*}}}  */
