#include "toolbus.h"
#include "terms.h"
#include "env.h"
#include "match.h"
#include "procs.h"
#include "tools.h"
#include "utils.h"
#include "interpreter.h"

#define CALLSDB(x)

extern proc_def_list *Definitions; /* defined in interpreter.c */

static int n_expanded_calls = 0;


term_list *replace_formals_list(term_list *tl, env *e);

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

term_list *expand_calls_list(term_list *tl);

proc *expand_calls(proc *P)
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
      CALLSDB(TBmsg("into %t\n", P1);)
      return P1;
    } else {
      return mk_appl(fun_sym(P), expand_calls_list(fun_args(P)));
    }
  case t_list:
    return expand_calls_list(P);

  default: err_fatal("expand_body: %t", P);
    return NULL; /* pedantic */
  }
}

term_list *expand_calls_list(term_list *tl)
{
  term head, *prev;
  assert(is_list(tl));

  /* CALLSDB(TBmsg("expand_calls_list(%t) ... \n", tl);) */
  prev = &head;
  for(next(&head) = tl; tl; tl = next(tl)){
    next(prev) = mk_list(expand_calls(first(tl)), next(tl));
    prev = next(prev);
  }
  /* CALLSDB(TBmsg("expand_calls_list returns %t\n", next(&head));) */

  return next(&head);
}

void expand_all_calls()
{  proc_def_list *pdl;
   proc_def *pd;
   int nexp;

   for(nexp = -1, n_expanded_calls = 0; nexp != n_expanded_calls; ){
     nexp = n_expanded_calls;

     for(pdl = Definitions ; pdl; pdl = next(pdl)){
       pd = first(pdl);
       CALLSDB(TBmsg("Before[%d]: %t\n\n", n_expanded_calls, pd);)
       pd_body(pd) = expand_calls(pd_body(pd));
       CALLSDB(TBmsg("After[%d]: %t\n", n_expanded_calls, pd);)
     }
   }
}

