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

   $Id$
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

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>

/*}}}  */

#define TCDB(x)

/*
   The following typechecks on ToolBus scripts are implemented here:
   - Process names appearing in calls and creates have been defined.
   - The number of formals and actuals correspond.
   - There are no recursive calls.
   - The function symbols appearing in ``expressions'', i.e. the rhs
   of an assignment are defined.

   Potential further checks that are not yet implemented:
   - ensure that variables get a value before use along every control path
   - infer types of variables from their use.
   - infer the types of expressions.
   */

/*{{{  variables */

term_list *calls = NULL;         /* all call atoms */
term_list *closure_calls = NULL; /* transitive closure of calls */
term_list *tc_atoms = NULL;      /* atoms to be typechecked */

static int nerror = 0;           /* # of errors found */

/*}}}  */

/* Represent procedure calls as triples of the form [pname, call, coordinates]
   where
   - pname is the name of the process definition i  whcih the call occurs
   - call is the call itself of the form call(P, Arg1, Arg2, ...)
   - coordinates define the textual location of the call.
   */

/*{{{  void tc_call(char *pname, atom *Atom, coords *c) */

void tc_call(char *pname, atom *Atom, coords *c)
{
  calls = mk_list(mk_list3(mk_str(pname), Atom, c), calls);

  closure_calls = mk_list(mk_list2(mk_int(TBlookup(pname)), 
				   mk_int(fun_sym(first(fun_args(Atom))))),
			  closure_calls);
}

/*}}}  */
/*{{{  void tc_create(atom *Atom) */

void tc_create(atom *Atom)
{
  tc_atoms = mk_list(Atom, tc_atoms);
}

/*}}}  */
/*{{{  void tc_execute(proc *p) */

void tc_execute(proc *p)
{
  tc_atoms = mk_list(p, tc_atoms);
}

/*}}}  */

/*{{{  void pr_coords(coords *c) */

void pr_coords(coords *c)
{ 
  assert(is_coords(c));
  TBprintf(stderr, "%t, line %t: ", elm1(c), elm2(c));
}

/*}}}  */
/*{{{  void tc_printf(atom *Atom) */

void tc_printf(atom *Atom)
{
  if(!require_type(Str, elm1(at_args(Atom))))
  {
    pr_coords(at_coords(Atom));
    TBprintf(stderr, "first argument of printf should be a string\n");
    nerror++;
  }
}

/*}}}  */

/*{{{  TBbool req_nargs(atom *a, int nargs) */

TBbool req_nargs(atom *a, int nargs)
{
  if(list_length(at_args(a)) != nargs){  
    pr_coords(at_coords(a));
    TBprintf(stderr, "%s: %d arguments required\n", get_txt(at_fun(a)), nargs);
    nerror++;
    return TBfalse;
  } else
    return TBtrue;
}

/*}}}  */
/*{{{  TBbool req_arg1_tool_id(atom *a, TBbool var_only) */

TBbool req_arg1_tool_id(atom *a, TBbool var_only)
{
  term *the_tool_id, *the_tool_type;
  coords *c = at_coords(a);

  if(list_length(at_args(a)) < 1){  
    pr_coords(c);
    TBprintf(stderr, "%s: too few arguments\n", get_txt(at_fun(a)));
    nerror++;
    return TBfalse;
  }
  the_tool_id = elm1(at_args(a));
  if(var_only){
    if(is_var(the_tool_id))
      the_tool_type = var_type(the_tool_id);
    else {
      pr_coords(c);
      TBprintf(stderr, "%s: argument 1 should be a variable\n", get_txt(at_fun(a)));
      nerror++;
      return TBfalse;
    }
  } else {
    if(is_appl(the_tool_id) &&  (list_length(fun_args(the_tool_id)) == 0))
      the_tool_type = the_tool_id;
    else {
      pr_coords(c);
      TBprintf(stderr, "%s: argument 1 should be a tool name\n", get_txt(at_fun(a)));
      nerror++;
      return TBfalse;
    }
  }

  if(!find_tool_def(fun_sym(the_tool_type))){
    pr_coords(c);
    TBprintf(stderr, "%s: type of argument 1 (`%t') not declared as tool name\n",
	     get_txt(at_fun(a)), type_of(the_tool_type));
    nerror++;
    return TBfalse;
  }
  return TBtrue;
}

/*}}}  */
/*{{{  TBbool req_arg2_appl(atom *a) */

TBbool req_arg2_appl(atom *a)
{
  coords *c = at_coords(a);

  if(list_length(at_args(a)) != 2){	  
    pr_coords(c);
    TBprintf(stderr, "%s: 2 arguments required\n", get_txt(at_fun(a)));
    nerror++;
    return TBfalse;
  } else {
    term *arg2 = elm2(at_args(a));
    if(!is_appl(arg2)){
      pr_coords(c);
      TBprintf(stderr, "%s: argument 2 should be a function application\n",
	       get_txt(at_fun(a)));
      nerror++;
      return TBfalse;
    }
    return TBtrue;
  }
}

/*}}}  */

/*{{{  void warn_res_vars(atom *a, TBbool want_res_vars) */

void warn_res_vars(atom *a, TBbool want_res_vars)
{
  coords *c = at_coords(a);
  term_list *tl;
  int nresvars = 0;
  TBbool has_vars = TBfalse;

  for(tl = next(at_args(a)); tl; tl = next(tl)){
    if(has_result_vars(first(tl)))
      nresvars++;
    has_vars = has_vars || !has_no_vars(first(tl));
  }
  if(want_res_vars){
    if(nresvars == 0 && has_vars){
      /* This warning is not valid. Often we only need confirmation
       * from a tool without any obtained information.
       *
       * pr_coords(c);
       * TBprintf(stderr, "warning: arguments of %s do not contain result variables\n",
      *       get_txt(at_fun(a)));
      */
    }
  } else {    
    if(nresvars > 0){
      pr_coords(c);
      TBprintf(stderr, "warning: arguments of %s contain result variables\n",
	       get_txt(at_fun(a)));
    }
  }
}

/*}}}  */

/*{{{  void tc_tool_atom(atom *a) */

void tc_tool_atom(atom *a)
{
  tc_atoms = mk_list(a, tc_atoms);
}

/*}}}  */

/*{{{  TBbool tc_tool_atom2(atom *a) */

TBbool tc_tool_atom2(atom *a)
{
  switch(at_fun(a))
  {
    case a_rec_connect:
      return req_arg1_tool_id(a, TBtrue) && req_nargs(a, 1);
    case a_rec_disconnect:
      return req_arg1_tool_id(a, TBtrue) && req_nargs(a, 1);
    case a_rec_value:
      if(req_arg1_tool_id(a, TBtrue)){
	if (req_arg2_appl(a)) {
	  warn_res_vars(a, TBtrue);
	  return TBtrue;
	} else {
	  return TBfalse;
	}
      } else {
	return TBfalse;
      }
    case a_rec_event:
      if(req_arg1_tool_id(a, TBtrue)){
	warn_res_vars(a, TBtrue);
	return TBtrue;
      } else {
	return TBfalse;
      }

    case a_snd_terminate:
      return req_arg1_tool_id(a, TBtrue) && req_nargs(a, 2);

    case a_snd_ack_event:
      if(req_arg1_tool_id(a, TBtrue) && req_nargs(a, 2)){
	warn_res_vars(a, TBfalse);
	return TBtrue;
      } else
	return TBfalse;
    case a_snd_eval:
    case a_snd_cancel:
    case a_snd_do:
      if(req_arg1_tool_id(a,TBtrue) && req_arg2_appl(a)){
	warn_res_vars(a, TBfalse);
	return TBtrue;
      } else
	return TBfalse; 
  }
  return TBfalse;
}

/*}}}  */

/*{{{  static void pr_unresolved(char *s) */

static void pr_unresolved(char *s)
{
  while(*s && (*s != '$')){
    fputc(*s++, stderr);
  }
}

/*}}}  */

/*{{{  void tc_double_decl(char *cat, char *name, term *script_name, int lino) */

void tc_double_decl(char *cat, char *name, term *script_name, int lino)
{
  TBprintf(stderr, "%t, line %d: double declaration of %s `", script_name, lino, cat);
  pr_unresolved(name);
  TBprintf(stderr, "'\n");
  nerror++;
}

/*}}}  */
/*{{{  void tc_not_decl(char *cat, char *name, term *script_name, int lino) */

void tc_not_decl(char *cat, char *name, term *script_name, int lino)
{
  TBprintf(stderr, "%t, line %d: undeclared %s `", script_name, lino, cat);
  pr_unresolved(name);
  TBprintf(stderr, "'\n");
  nerror++;
}

/*}}}  */
/*{{{  void tc_ill_result(char *cat, char *name, term *script_name, int lino) */

void tc_ill_result(char *cat, char *name, term *script_name, int lino)
{
  TBprintf(stderr, "%t, line %d: illegal result %s `", script_name, lino, cat);
  pr_unresolved(name);
  TBprintf(stderr, "'\n");
  nerror++;
}

/*}}}  */
/*{{{  void tc_undef(char *cat, char *name , term *script_name, int lino) */

void tc_undef(char *cat, char *name , term *script_name, int lino)
{
  TBprintf(stderr, "%t, line %d: %s `%s' undefined\n", script_name, lino, cat, name);
  nerror++;
}

/*}}}  */

/*{{{  type *tc_expr(term *T, coords *c) */

type *tc_expr(term *T, coords *c)
{
  type *TK[3];
  struct expr_sign *es;
  term_list *args;
  int i;

  TCDB(TBmsg("tc_expr: %t\n", T);)

    if(!T)
      return List;

  switch(tkind(T)){
    case t_bool:
      return Bool;
    case t_int:
      return Int;
    case t_real:
      return Real;
    case t_str:
      return Str;
    case t_bstr:
      return Bstr;
    case t_var:
      return var_type(T);
    case t_list:
      { term_list head, *prev;
	prev = &head;
	for( ; T; T = next(T)){
	  next(prev) = mk_list(tc_expr(first(T), c), NULL);
	  prev = next(prev);
	}
	return next(&head);
      }
    case t_appl:

      if(!is_expr_fun(T)){    
	if(fun_args(T))
	  tc_undef("function", get_txt(fun_sym(T)), elm1(c), int_val(elm2(c)));
	return Term;
      }
      es = get_expr_sign(fun_sym(T));
      if(list_length(fun_args(T)) != es->nargs){
	TBprintf(stderr, "%t, line %d: function `%s': %d argument(s) required\n",
		 elm1(c), int_val(elm2(c)), get_txt(fun_sym(T)), es->nargs);	       
	nerror++;
	return NULL;
      }
      args = fun_args(T);

      if(es->evargs){
	for(i = 0; i < es->nargs; i++){
	  TK[i] = tc_expr(first(args), c);
	  args = next(args);
	  if(!term_equal(es->argtype[i], Term) && !comp_type(es->argtype[i], TK[i])){
	    TBprintf(stderr, "%t, line %d: function `%s': wrong type for argument %d\n", 
		     elm1(c), int_val(elm2(c)),   
		     get_txt(fun_sym(T)), i + 1);	 
	    nerror++;
	    return NULL;
	  }
	}
      }

      return es->restype;
    default:
      err_fatal("tc_expr");
      return Term; /* pedantic */
  }
}

/*}}}  */

/*{{{  void tc_cond(term *t, coords *c) */

void tc_cond(term *t, coords *c)
{
  type *tp = tc_expr(t, c);

  if(term_equal(Bool, tp))
    return;
  else {	
    TBprintf(stderr, "%t, line %d: type of condition should be bool\n", 
	     elm1(c), int_val(elm2(c)));
    nerror++;
  }
}

/*}}}  */

/*{{{  TBbool assign_compatible(type *vtp, type *atp) */

TBbool assign_compatible(type *vtp, type *atp)
{
  TCDB(TBmsg("assign_compatible(%t,%t)\n", vtp, atp);)
    if(require_type(vtp, atp)    /* rhs is of required type of lhs */
       || comp_type(vtp, atp)
       || term_equal(vtp, Term)  /* var at lhs is of type term */
       || term_equal(atp, Term)  /* var type != term, expr type = term or list
				    delay typecheck till run-time */
       || term_equal(atp, List))
      return TBtrue;
    else return TBfalse;
}

/*}}}  */

/*{{{  void tc_assign(atom *Atom) */

void tc_assign(atom *Atom)
{
  coords *c = at_coords(Atom);
  type *tp = tc_expr(elm2(at_args(Atom)), c);
  var *v   = elm1(at_args(Atom));
  type *vt = var_type(v);

  TCDB(TBmsg("tc_assign, atom=%,tp=%t, vt=%t\n", Atom, tp, vt);)
    if(assign_compatible(vt, tp)){
      if(is_formal(v) && !var_result(v)) {  
	TBprintf(stderr, "%t, line %d: illegal assignment to formal parameter\n", 
		 elm1(c), int_val(elm2(c)));
	nerror++;
      }
      return;
    } else {    
      TBprintf(stderr, "%t, line %d: type mismatch in assignment\n", 
	       elm1(c), int_val(elm2(c)));
      nerror++;
    }

}

/*}}}  */

/* Transitive closure functions */

/* Is there already a call n1 -> n2 ? */

/*{{{  TBbool has_call(term *n1, term *n2) */

TBbool has_call(term *n1, term *n2)
{
  term_list *ccalls1;
  term_list *ccall;

  for(ccalls1 = closure_calls; ccalls1; ccalls1 = next(ccalls1)){
    ccall = first(ccalls1);
    if((int_val(n1) == int_val(elm1(ccall))) && (int_val(n2) == int_val(elm2(ccall))))
      return TBtrue;
  }
  return TBfalse;
}

/*}}}  */

/* Can we extend the call relation for n1 using n2,
   i.e. is there already a relation n2->n3 such that
   we can add n1 -> n3?
   */

/*{{{  TBbool add_call(term *n1, term *n2) */

TBbool add_call(term *n1, term *n2)
{
  term_list *ccalls1;
  term_list *ccall;

  for(ccalls1 = closure_calls; ccalls1; ccalls1 = next(ccalls1)){
    ccall = first(ccalls1);
    if(int_val(elm1(ccall)) == int_val(n2)){
      if(!has_call(n1, elm2(ccall))){
	closure_calls = mk_list(mk_list2(n1, elm2(ccall)), closure_calls);
	return TBtrue; 
      }
    }
  }

  return TBfalse;  
}

/*}}}  */

/*{{{  void pr_recursive(sym_idx n) */

void pr_recursive(sym_idx n)
{
  term_list *calls1, *triple;
  coords *c;
  term_list *call;
  sym_idx name_idx;

  for(calls1 = calls; calls1; calls1 = next(calls1)){
    triple = first(calls1);
    call = elm2(triple);
    c = elm3(triple);
    name_idx = fun_sym(first(fun_args(call)));
    if(name_idx == n){
      pr_coords(c);
      TBprintf(stderr, "(indirect) recursive call of process `%s'\n", get_txt(n));
      nerror++;
    }
  }
}

/*}}}  */

/*{{{  void closure(void) */

void closure(void)
{
  TBbool change = TBtrue;
  term_list *ccalls1, *ccall;
  term *n1, *n2;

  while(change) {
    change = TBfalse;
    for(ccalls1 = closure_calls; ccalls1; ccalls1 = next(ccalls1)){
      ccall = first(ccalls1);
      n1 = elm1(ccall);
      n2 = elm2(ccall);
      change = add_call(n1, n2) || change;
    }
  }
  for(ccalls1 = closure_calls; ccalls1; ccalls1 = next(ccalls1)){ 

    ccall = first(ccalls1);
    n1 = elm1(ccall);
    n2 = elm2(ccall);
    if(int_val(n1) == int_val(n2))
      pr_recursive(int_val(n1));
  }
}

/*}}}  */

/*{{{  void tc_warn_redef(char *kind, char *var, term *script_name, int lino) */

void tc_warn_redef(char *kind, char *var, term *script_name, int lino)
{
  TBprintf(stderr, "%t, line %d: (warning) variable `", script_name, lino);
  pr_unresolved(var);
  TBprintf(stderr, "' redefines %s in enclosing scope\n", kind);
}

/*}}}  */

/*{{{  TBbool check_let_vars(term_list *formals, term_list *outer_vars, term_list *locals, */

TBbool check_let_vars(term_list *formals, term_list *outer_vars, term_list *locals,
		      term *script_name, int lino)
{
  term_list *ls;
  int sv_nerror = nerror;

  for(ls = locals; ls; ls = next(ls)){
    if(list_elem(first(ls), next(ls)))
      tc_double_decl("let variable", get_txt(var_sym(first(ls))), script_name, lino);
    if(list_elem(first(ls), outer_vars))
      tc_warn_redef("let variable", get_txt(var_sym(first(ls))), script_name, lino);
    if(list_elem(first(ls), formals))
      tc_warn_redef("formal", get_txt(var_sym(first(ls))), script_name, lino);
  }
  return sv_nerror == nerror;
}

/*}}}  */
/*{{{  TBbool check_formals_vars(term_list *formals, term_list *vars, term *script_name, */

TBbool check_formals_vars(term_list *formals, term_list *vars, term *script_name,
			  int lino)
{
  term_list *fs, *vs;
  int sv_nerror = nerror;

  /* TBprintf(stderr, "check_formals_vars(%t,%t)\n", formals, vars); */

  for(fs = formals; fs; fs = next(fs)){
    if(list_elem(first(fs), next(fs)))
      tc_double_decl("formal", get_txt(var_sym(first(fs))), script_name, lino);
  }
  for(vs = vars; vs; vs = next(vs)){
    if(list_elem(first(vs), next(vs)))     
      tc_double_decl("variable", get_txt(var_sym(first(vs))), script_name, lino);

    for(fs = formals; fs; fs = next(fs)){
      if(var_sym(first(vs)) == var_sym(first(fs)))
	tc_double_decl("variable", get_txt(var_sym(first(vs))), script_name, lino);
    }
  }
  return sv_nerror == nerror;
}

/*}}}  */

/*{{{  TBbool check_formal_actual(sym_idx name_idx, coords *c, char *p_or_t, */

TBbool check_formal_actual(sym_idx name_idx, coords *c, char *p_or_t,
			   term_list *formals, term_list *actuals)
{
  int n = 1, sv_nerror = nerror;
  type *ft;
  term *act;

  for( ; formals; formals = next(formals), actuals = next(actuals)){
    if(!actuals){
      pr_coords(c);
      TBprintf(stderr, "%s `%f': too few actuals\n", p_or_t, get_txt(name_idx)); 
      nerror++;
      return TBfalse;
    }
    ft = var_type(first(formals));
    act = first(actuals);

    if(!assign_compatible(ft, act)){
      pr_coords(c);
      TBprintf(stderr, "%s `%f': type mismatch for argument %d\n", p_or_t, get_txt(name_idx), n);
      nerror++;
    }
    if(var_result(first(formals)) && !(is_var(act) && var_result(act))){
      pr_coords(c);
      TBprintf(stderr, "%s `%f': result variable required for argument %d\n", p_or_t, get_txt(name_idx), n);
      nerror++;
    }
    if(!var_result(first(formals)) && (is_var(act) && var_result(act))){
      pr_coords(c);
      TBprintf(stderr, "%s `%f': result variable not allowed for argument %d\n", p_or_t, get_txt(name_idx), n);
      TBmsg("formals = %t, actuals =%t\n", formals, actuals);
      nerror++;
    }
    n++;     
  }
  if(actuals){     
    pr_coords(c);
    TBprintf(stderr, "%s `%f': too many actuals\n", p_or_t, get_txt(name_idx)); 
    nerror++;
  }
  return sv_nerror == nerror;
}

/*}}}  */

/*{{{  TBbool check_proc_use(sym_idx name_idx, term_list *args, coords *c) */

TBbool check_proc_use(sym_idx name_idx, term_list *args, coords *c)
{
  proc_def *def  = definition(name_idx);

  if(!def){
    tc_not_decl("process name", get_txt(name_idx), elm1(c), int_val(elm2(c)));
    return TBfalse;
  }
  return check_formal_actual(name_idx, c, "process", pd_formals(def), args);
}

/*}}}  */

/*{{{  TBbool check_tool_use(sym_idx name_idx, term_list *args, coords *c) */

TBbool check_tool_use(sym_idx name_idx, term_list *args, coords *c)
{
  tool_def *def  = find_tool_def(name_idx);

  if(!def){
    tc_not_decl("tool name", get_txt(name_idx), elm1(c), int_val(elm2(c)));
    return TBfalse;
  }
  return check_formal_actual(name_idx, c, "tool", td_formals(def), args);
}

/*}}}  */

/*{{{  char *add_suffix(char *name, char *suf) */

char *add_suffix(char *name, char *suf)
{
  static char filename[_POSIX_PATH_MAX];

  int n = strlen(name);
  if((n > 3) && (name[n-3] == '.') && (name[n-2] == 't') && (name[n-1] == 'b')){
    strncpy(filename, name, n-3);
    strcpy(&filename[n-3], suf);
  }  else {
    strcpy(filename, name);
    strcpy(&filename[n], suf);
  }
  return filename;
}

/*}}}  */

/*{{{  term_list *replace_more_specific(term *t, term_list *sig_list) */

term_list *replace_more_specific(term *t, term_list *sig_list)
{
  term_list *cur, *prev;

  prev = NULL;
  for (cur = sig_list; cur; cur = next(cur)) {
    if (cmatchp(t, first(cur))) {
      if (prev != NULL) {
	next(prev) = next(cur);
      } else {
	sig_list = next(cur);
      }
    } else if (cmatchp(first(cur), t)) {
      return sig_list;
    } else {
      prev = cur;
    }
  }

  return mk_list(t, sig_list);
}

/*}}}  */

/* The actual typecheck function:
   - check that used process names are defined
   - check formal/actual correspondence
   - check recursive calls
   */

/*{{{  int typecheck(char *script, TBbool gen_tifs) */

int typecheck(char *script, TBbool gen_tifs, char *output)
{
  term *triple, *call, *creator;
  term_list *calls1, *args;
  sym_idx name_idx;
  term_list *ats;
  atom *at;
  coords *c;
  char *tifs_name = ""; /* pedantic */
  int tifs = -1;

  if(gen_tifs){
    if (output == NULL)  {
      tifs_name = add_suffix(script, ".tifs");
    }
    else {
      tifs_name = output;
    }

    tifs = creat(tifs_name, 0666);
    if(tifs < 0){
      TBmsg("Can't create %s", tifs_name);
      gen_tifs = TBfalse;
    } else {
      tool_def *def = find_tool_def(TBlookup("viewer"));
      if(def)
	TBwrite(tifs, TBmake("rec-monitor(<viewer>,<term>)"));
      def = find_tool_def(TBlookup("logger"));
      if(def)
	TBwrite(tifs, TBmake("rec-monitor(<logger>,<term>)"));
    }
  }

  calls = list_reverse(calls);
  for(calls1 = calls; calls1; calls1 = next(calls1)){
    triple = first(calls1);
    call = elm2(triple);
    name_idx = var_sym(first(fun_args(call)));
    args = next(fun_args(call));
    check_proc_use(name_idx, args, elm3(triple));
  }
  closure();

  for(ats = list_reverse(tc_atoms); ats; ats = next(ats)){
    at = first(ats);
    switch(at_fun(at))
    { case a_create:

      call = first(at_args(at));
      name_idx = fun_sym(call);
      args = fun_args(call);
      if(check_proc_use(name_idx, args, at_coords(at))){
	var *v = elm2(at_args(at));
	if(!require_type(Int, v)){
	  pr_coords(at_coords(at));
	  TBprintf(stderr, "argument 2 of `create' should be integer\n");
	  nerror++;
	}
      }
      break;

      case p_execute:

      creator = elm1(fun_args(at));
      name_idx = fun_sym(creator);
      args = fun_args(creator);
      c =  elm3(fun_args(at));
      if(check_tool_use(name_idx, args, c)){
	var *v = elm2(fun_args(at));
	if(!require_type(type_of(creator), v)){
	  pr_coords(c);
	  TBprintf(stderr, "argument 2 of `execute' should be of type `%f'\n",
		   get_txt(fun_sym(creator)));
	  nerror++;
	}
      }
      break;

      default:

      if(tc_tool_atom2(at)){
	tool_def *td;
	atom *at1;

	/* construct element for signature:
	   - replace constants by place holders
	   - force second arg of snd-ack-event to be of type <term>
	   - delegate a_snd_connect and a_rec_terminate to complete_tool_sigs
	   - stripp of coords
	   */
	if(at_fun(at) == a_snd_ack_event){
	  at1 = mk_appl2(a_rec_ack_event, first(at_args(at)),
			 mk_placeholder(Term));
	} else
	  at1 = mk_appl(reverse_role(fun_sym(at)), at_args(at));

	at1 = convert_to_sign(at1);
	td = find_tool_def(fun_sym(type_of(first(at_args(at)))));
	if(td && ((fun_sym(at1) != a_snd_connect)
		  && (fun_sym(at1) != a_rec_terminate))){

	  if(is_to_tool_atom(at1)){
	    td_in_sign(td) = replace_more_specific(at1, td_in_sign(td));
	    /*if(!occurs(at1, td_in_sign(td))){
	      td_in_sign(td) = mk_list(at1, td_in_sign(td));
	      }*/
	  } else {	
	    td_out_sign(td) = replace_more_specific(at1, td_out_sign(td));
	    /*if(!occurs(at1, td_out_sign(td))){
	      td_out_sign(td) = mk_list(at1, td_out_sign(td));
	      }*/
	  }
	}
      }
    }
  }
  complete_tool_sigs(tifs);
  if(gen_tifs) {
    term_list *td_list;
    for (td_list = get_tool_defs(); td_list; td_list = next(td_list)) {
      term *td = first(td_list);
      term_list *sign;
      for (sign = td_in_sign(td); sign; sign = next(sign)) {
	TBwrite(tifs, first(sign));
      }
      for (sign = td_out_sign(td); sign; sign = next(sign)) {
	TBwrite(tifs, first(sign));
      }
    }
    TBwrite(tifs, TBmake("end-of-tifs"));
    if(close(tifs) < 0)
      err_sys_fatal("Can't close `%s'", tifs_name);
    TBprintf(stdout, "Tool interfaces written to `%s'\n", tifs_name);
  }
  return nerror == 0;
}

/*}}}  */
