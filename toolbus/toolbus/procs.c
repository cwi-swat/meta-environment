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

/*}}}  */

/*{{{  variables */

proc *Delta;           /* PROTECTED */
proc *Tau;             /* PROTECTED */

/*}}}  */

/*{{{  void print_process(term *proc) */

void print_process(term *proc)
{
  TBprintf(stderr, "printing process %t:\n", pi_name(proc));
  print_alternatives(pi_alts(proc), 0);
}

/*}}}  */
/*{{{  void print_process(term *proc) */

/*{{{  void print_process_snd_msgs_only(term *proc) */

void print_process_snd_msgs_only(term *proc)
{
  TBprintf(stderr, "printing process %t:\n", pi_name(proc));
  print_alternatives(pi_alts(proc), 1);
}

/*}}}  */

/*}}}  */
/*{{{  void print_alternatives(term_list *alts) */

void print_alternatives(term_list *alts, int snd_msgs_only)
{
  for (; alts; alts=next(alts)) {
    print_alternative(first(alts), snd_msgs_only);
  }
}

/*}}}  */
/*{{{  void print_alternative(term *t) */

void print_alternative(term *t, int snd_msgs_only)
{
  char *fun = get_txt(fun_sym(t));
  term *atom = first(fun_args(t));
  char *atom_fun = get_txt(fun_sym(atom));
  term_list *args = first(fun_args(atom));

  if (!snd_msgs_only || !strcmp(atom_fun, "snd-msg")) {
    TBprintf(stderr, "  %s(%s(%l))\n", fun, atom_fun, args);
  }
}

/*}}}  */

/*{{{  TBbool communicate(sym_idx a1, sym_idx a2) */

TBbool communicate(sym_idx a1, sym_idx a2)
{
  switch(a1)
  {
    case a_rec_msg:        return a2 == a_snd_msg;
    case a_snd_msg:        return a2 == a_rec_msg;

    case a_rec_value:      return a2 == a_snd_value;
    case a_snd_value:      return a2 == a_rec_value;

    case a_rec_event:      return a2 == a_snd_event;
    case a_snd_event:      return a2 == a_rec_event;

    case a_rec_connect:    return a2 == a_snd_connect;
    case a_snd_connect:    return a2 == a_rec_connect;

    case a_rec_disconnect: return a2 == a_snd_disconnect;
    case a_snd_disconnect: return a2 == a_rec_disconnect;

    case a_rec_continue:   return a2 == a_snd_continue;
    case a_snd_continue:   return a2 == a_rec_continue;

    default:
			   return TBfalse;
  }
}

/*}}}  */
/*{{{  sym_idx reverse_role(sym_idx f) */

sym_idx reverse_role(sym_idx f)
{
  switch(f){

    case a_snd_eval:            return a_rec_eval;
    case a_rec_eval:            return a_snd_eval;

    case a_snd_value:           return a_rec_value;
    case a_rec_value:           return a_snd_value;

    case a_snd_cancel:          return a_rec_cancel;
    case a_rec_cancel:          return a_snd_cancel;

    case a_snd_do:              return a_rec_do;
    case a_rec_do:              return a_snd_do;

    case a_rec_event:           return a_snd_event;
    case a_snd_event:           return a_rec_event;

    case a_snd_ack_event:       return a_rec_ack_event;
    case a_rec_ack_event:       return a_snd_ack_event;

    case a_rec_connect:         return a_snd_connect;
    case a_snd_connect:         return a_rec_connect;

    case a_rec_disconnect:      return a_snd_disconnect;
    case a_snd_disconnect:      return a_rec_disconnect;

    case a_snd_terminate :      return a_rec_terminate;
    case a_rec_terminate:       return a_snd_terminate;

    case a_snd_monitor:         return a_rec_monitor;
    case a_rec_monitor:         return a_snd_monitor;

    case a_rec_continue:        return a_snd_continue;
    case a_snd_continue:        return a_rec_continue;

    case a_snd_attach_monitor:  return a_rec_attach_monitor;
    case a_rec_attach_monitor:  return a_snd_attach_monitor;

    case a_snd_detach_monitor: return a_rec_detach_monitor;
    case a_rec_detach_monitor: return a_snd_detach_monitor;

    default:
			       err_fatal("reverse_role: %d", f);
			       return a_delta; /* pedantic */
  }
}

/*}}}  */

/*{{{  proc *mk_create(char *proc_name, term_list *args, var *v, coords *c) */

proc *mk_create(char *proc_name, term_list *args, var *v, coords *c)
{
  return mk_atom(a_create, mk_list2(mk_appl(TBlookup(proc_name), args), v), c);
} 

/*}}}  */
/*{{{  proc *mk_proc_call(char *id, term_list *args) */

proc *mk_proc_call(char *id, term_list *args)
{
  return mk_appl(p_call, mk_list(mk_var(id, "", t_term), args));
}

/*}}}  */

/*{{{  void pr_atom(proc *a) */

void pr_atom(proc *a)
{
  assert(is_atom(a));

  fprintf(stderr, "%s", get_txt(at_fun(a)));
  if(at_args(a)){
    fprintf(stderr, "(");
    pr_term_list(at_args(a));
    fprintf(stderr, ")");
  }
}

/*}}}  */

/*{{{  proc_def *mk_proc_def(char *name, */

proc_def *mk_proc_def(char *name,
		      term_list *formals,
		      term_list *vars,
		      proc *p)
{ 
  assert(is_list(formals));

  return mk_appl4(s_proc_def, mk_var(name, "", t_term), formals, vars, p);
}

/*}}}  */

/*{{{  void pr_proc_def(proc_def *pd) */

void pr_proc_def(proc_def *pd)
{
  assert(is_proc_def(pd));

  fprintf(stderr, "\nprocess %s", get_txt(pd_name(pd)));
  fprintf(stderr, "(");  pr_term_list(pd_formals(pd));   fprintf(stderr, ") =\n"); 
  pr_term(pd_body(pd));
  fprintf(stderr, "\n");
}

/*}}}  */

/*{{{  difficult #define */

#define EXPDEF(str, sym, _restype, _evargs, _nargs, _arg0type, _arg1type, _arg2type)\
{ expr_sign *sig; \
  SYMDEF(str,sym);\
    sig		= malloc(sizeof(struct expr_sign)); \
    sig->argtype     = malloc(sizeof(type *)*3); \
    sig->name	= sym;\
    sig->restype	= _restype;\
    sig->evargs	= _evargs;\
    sig->nargs	= _nargs;\
    sig->argtype[0]	= _arg0type;\
    sig->argtype[1]	= _arg1type;\
    sig->argtype[2]	= _arg2type; \
    sig->func	= NULL; \
    sig->descr       = "empty"; \
    register_function(str, system_module, sig); \
}

/*}}}  */
/*{{{  void init_procs(void) */

void init_procs(void)
{
  sym_idx idx;

  SYMDEF("system", system_module);
  register_module("system");
  SYMDEF("delta", a_delta);
  SYMDEF("tau", a_tau);
  SYMDEF("snd-msg", a_snd_msg);
  SYMDEF("rec-msg", a_rec_msg);

  SYMDEF("snd-note", a_snd_note);
  SYMDEF("rec-note", a_rec_note);
  SYMDEF("no-note", a_no_note);
  SYMDEF("subscribe", a_subscribe);
  SYMDEF("unsubscribe", a_unsubscribe);

  SYMDEF("snd-eval", a_snd_eval);
  SYMDEF("rec-value", a_rec_value);
  SYMDEF("snd-cancel", a_snd_cancel);
  SYMDEF("snd-do", a_snd_do);

  SYMDEF("rec-event", a_rec_event);
  SYMDEF("snd-ack-event", a_snd_ack_event);

  SYMDEF("create", a_create);

  SYMDEF("rec-connect", a_rec_connect);
  SYMDEF("rec-disconnect", a_rec_disconnect);
  SYMDEF("snd-execute-to-tool", a_snd_execute_to_tool);
  SYMDEF("snd-terminate", a_snd_terminate);
  SYMDEF("shutdown", a_shutdown);

  SYMDEF("assign", a_assign);
  SYMDEF("endlet", a_endlet);
  SYMDEF("printf", a_printf);
  SYMDEF("read", a_read);

  SYMDEF("rec-attach-monitor", a_rec_attach_monitor);
  SYMDEF("rec-detach-monitor", a_rec_detach_monitor);
  SYMDEF("snd-monitor", a_snd_monitor);
  SYMDEF("rec-continue", a_rec_continue);

  SYMDEF("snd-connect", a_snd_connect);
  SYMDEF("snd-value", a_snd_value);
  SYMDEF("snd-void", a_snd_void);
  SYMDEF("snd-event", a_snd_event);
  SYMDEF("snd-continue", a_snd_continue);
  SYMDEF("snd-attach-monitor", a_snd_attach_monitor);
  SYMDEF("snd-detach-monitor", a_snd_detach_monitor);
  SYMDEF("snd-reconfigure", a_snd_reconfigure);
  SYMDEF("snd-disconnect", a_snd_disconnect);

  SYMDEF("rec-eval",  a_rec_eval);
  SYMDEF("rec-cancel", a_rec_cancel);
  SYMDEF("rec-do", a_rec_do);
  SYMDEF("rec-ack-event", a_rec_ack_event);
  SYMDEF("rec-terminate", a_rec_terminate);
  SYMDEF("rec-monitor", a_rec_monitor);

  SYMDEF("plus", p_plus);
  SYMDEF("dot", p_dot);
  SYMDEF("star", p_star);
  SYMDEF("call", p_call);
  SYMDEF("semi", p_semi);
  SYMDEF("fmerge", p_fmerge);
  SYMDEF("lmerge", p_lmerge);

  SYMDEF("if", p_if);
  SYMDEF("let", p_let);
  SYMDEF("execute", p_execute);
  SYMDEF("timer", p_timer);
  SYMDEF("delay", p_delay);
  SYMDEF("abs-delay", p_abs_delay);
  SYMDEF("timeout", p_timeout);
  SYMDEF("abs-timeout", p_abs_timeout);
  SYMDEF("timeout", p_timeout);
  SYMDEF("no-delay", p_no_delay);
  SYMDEF("no-timeout", p_no_timeout);  

  SYMDEF("proc-def", s_proc_def);
  SYMDEF("proc-inst", s_proc_inst);
  SYMDEF("tool-inst", s_tool_inst);

  SYMDEF("logger", mon_logger);
  SYMDEF("viewer", mon_viewer);
  SYMDEF("controller", mon_controller);

  EXPDEF("is-bool",       e_is_bool,       Bool, TBtrue, 1, Term, NULL, NULL);
  EXPDEF("is-int",        e_is_int,        Bool, TBtrue, 1, Term, NULL, NULL);
  EXPDEF("is-real",       e_is_real,       Bool, TBtrue, 1, Term, NULL, NULL);
  EXPDEF("is-str",        e_is_str,        Bool, TBtrue, 1, Term, NULL, NULL);
  EXPDEF("is-bstr",       e_is_bstr,       Bool, TBtrue, 1, Term, NULL, NULL);
  EXPDEF("is-appl",       e_is_appl,       Bool, TBtrue, 1, Term, NULL, NULL);
  EXPDEF("is-list",       e_is_list,       Bool, TBtrue, 1, Term, NULL, NULL);
  EXPDEF("is-empty",      e_is_empty,      Bool, TBtrue, 1, Term, NULL, NULL);
  EXPDEF("is-var",        e_is_var,        Bool, TBfalse, 1, Term, NULL, NULL);
  EXPDEF("is-result-var", e_is_result_var, Bool, TBfalse, 1, Term, NULL, NULL);
  EXPDEF("is-formal",     e_is_formal,     Bool, TBfalse, 1, Term, NULL, NULL);
  EXPDEF("fun",           e_fun,           Str,  TBtrue, 1, Term, NULL, NULL);  
  EXPDEF("args",          e_args,          List, TBtrue, 1, Term, NULL, NULL);

  EXPDEF("true",          e_true,          Bool, TBfalse, 0, NULL, NULL, NULL);
  EXPDEF("false",         e_false,         Bool, TBfalse, 0, NULL, NULL, NULL);
  EXPDEF("not",           e_not,           Bool, TBtrue, 1, Bool, NULL, NULL);
  EXPDEF("and",           e_and,           Bool, TBtrue, 2, Bool, Bool, NULL);
  EXPDEF("or",            e_or,            Bool, TBtrue, 2, Bool, Bool, NULL);
  EXPDEF("equal",         e_equal,         Bool, TBtrue, 2, Term, Term, NULL);
  EXPDEF("not-equal",     e_not_equal,     Bool, TBtrue, 2, Term, Term, NULL);

  EXPDEF("add",           e_add,           Int,  TBtrue, 2, Int, Int, NULL);
  EXPDEF("sub",           e_sub,           Int,  TBtrue, 2, Int, Int, NULL);
  EXPDEF("mul",           e_mul,           Int,  TBtrue, 2, Int, Int, NULL);
  EXPDEF("div",           e_div,           Int,  TBtrue, 2, Int, Int, NULL);
  EXPDEF("mod",           e_mod,           Int,  TBtrue, 2, Int, Int, NULL);
  EXPDEF("abs",           e_abs,           Int,  TBtrue, 1, Int, NULL, NULL);
  EXPDEF("less",          e_less,          Bool, TBtrue, 2, Int, Int, NULL);
  EXPDEF("less-equal",    e_less_equal,    Bool, TBtrue, 2, Int, Int, NULL);
  EXPDEF("greater",       e_greater,       Bool, TBtrue, 2, Int, Int, NULL);
  EXPDEF("greater-equal", e_greater_equal, Bool, TBtrue, 2, Int, Int, NULL);

  EXPDEF("radd",           e_radd,           Real,  TBtrue, 2, Real, Real, NULL);
  EXPDEF("rsub",           e_rsub,           Real,  TBtrue, 2, Real, Real, NULL);
  EXPDEF("rmul",           e_rmul,           Real,  TBtrue, 2, Real, Real, NULL);
  EXPDEF("rdiv",           e_rdiv,           Real,  TBtrue, 2, Real, Real, NULL);
  EXPDEF("rless",          e_rless,          Bool, TBtrue, 2, Real, Real, NULL);
  EXPDEF("rless-equal",    e_rless_equal,    Bool, TBtrue, 2, Real, Real, NULL);
  EXPDEF("rgreater",       e_rgreater,       Bool, TBtrue, 2, Real, Real, NULL);
  EXPDEF("rgreater-equal", e_rgreater_equal, Bool, TBtrue, 2, Real, Real, NULL);
  EXPDEF("sin",            e_sin,            Real, TBtrue, 1, Real, NULL, NULL);
  EXPDEF("cos",            e_cos,            Real, TBtrue, 1, Real, NULL, NULL);
  EXPDEF("atan",           e_atan,           Real, TBtrue, 1, Real, NULL, NULL);
  EXPDEF("atan2",          e_atan2,          Real, TBtrue, 2, Real, Real, NULL);
  EXPDEF("exp",            e_exp,            Real, TBtrue, 1, Real, NULL, NULL);
  EXPDEF("log",            e_log,            Real, TBtrue, 1, Real, NULL, NULL);
  EXPDEF("log10",          e_log10,          Real, TBtrue, 1, Real, NULL, NULL);
  EXPDEF("sqrt",           e_sqrt,           Real, TBtrue, 1, Real, NULL, NULL);
  EXPDEF("rabs",           e_rabs,           Real, TBtrue, 1, Real, NULL, NULL);

  EXPDEF("size",           e_size,           Int,  TBtrue, 1, List, NULL, NULL);

  EXPDEF("index",          e_index,          Term, TBtrue, 2, List, Int, NULL);
  EXPDEF("replace",        e_replace,        List, TBtrue, 3, List, Int, Term);

  EXPDEF("get",           e_get,           Term, TBtrue, 2, List, Term, NULL);
  EXPDEF("put",           e_put,           List, TBtrue, 3, List, Term, Term);

  EXPDEF("first",         e_first,         Term, TBtrue, 1, List, NULL, NULL);
  EXPDEF("next",          e_next,          List, TBtrue, 1, List, NULL, NULL);

  EXPDEF("member",        e_member,        Bool, TBtrue, 2, Term, List, NULL);
  EXPDEF("subset",        e_subset,        Bool, TBtrue, 2, List, List, NULL); 
  EXPDEF("diff",          e_diff,          List, TBtrue, 2, List, List, NULL);
  EXPDEF("inter",         e_inter,         List, TBtrue, 2, List, List, NULL);
  EXPDEF("join",          e_join,          List, TBtrue, 2, Term, Term, NULL);
  EXPDEF("functions",     e_functions,     List, TBfalse,0, NULL, NULL, NULL);

  EXPDEF("process-id",    e_process_id,    Int,  TBfalse, 0, NULL, NULL, NULL);
  EXPDEF("process-name",  e_process_name,  Str,  TBfalse, 0, NULL, NULL, NULL);
  EXPDEF("quote",         e_quote,         Term, TBfalse, 1, Term, NULL, NULL);
  EXPDEF("current-time",  e_current_time,  List,  TBfalse, 0, NULL, NULL, NULL);
  EXPDEF("sec",           e_sec,           Int,  TBtrue,  1, Int, NULL, NULL);
  EXPDEF("msec",          e_msec,          Int,  TBtrue,  1, Int, NULL, NULL);  

  Delta = mk_atom(a_delta, NULL, NULL);
  Tau = mk_atom(a_tau, NULL, NULL);

  TBprotect(&Delta);
  TBprotect(&Tau);
}

/*}}}  */
