#include "toolbus.h"
#include "terms.h"
#include "env.h"
#include "match.h"

#define MATCHDB(x)

/*--- substitution -----------------------------*/

TBbool is_closed(term *t);

term *substitute(term *t, env *loc_env)
{
  term *t2;

  if(is_closed(t))
    return t;

  switch(tkind(t)){
  case t_bool: case t_int: case t_real: case t_str: case t_bstr:     
    return t;
  case t_var:      
    return var_result(t) ? t : value(t, loc_env);
    /* return value(t, loc_env); */
  case t_placeholder:
    return t;
  case t_appl:
    if(!fun_args(t))
      return t;
    else
      t2 = mk_appl(fun_sym(t), substitute_list(fun_args(t), loc_env));
      fun_str_sym(t2) = fun_str_sym(t);
      return t2;
  case t_anno:
    return mk_anno(anno_val(t), substitute(anno_term(t), loc_env));
  case t_list:
    return substitute_list(t, loc_env);
  default: err_fatal("substitute");
  }
  return NULL;
}

term *substitute_list(term *tl, env *loc_env)
{
  assert(is_list(tl));
  if(tl)
    return mk_list(substitute(first(tl), loc_env), 
		   substitute_list(next(tl), loc_env));
  else
    return NULL;
}

TBbool is_closed(term *t)
{
  if(!t)
    return TBtrue;

  switch(tkind(t)) {
    case t_bool: case t_int: case t_real: case t_str: case t_bstr:
      return TBtrue;
    case t_var:
      return var_result(t);
      break;
    case t_placeholder:
      return TBtrue;
    case t_appl:
      return is_closed(fun_args(t));
    case t_anno:
      return is_closed(anno_term(t));
    case t_list:
      return is_closed(first(t)) && is_closed(next(t));
    default: err_fatal("is_closed");
  }
  return TBfalse; /* silence the compiler */
}

env *Bindings1;          /* PROTECTED: bindings for t1 in match */
env *Bindings2;          /* PROTECTED: bindings for t2 in match */

TBbool match(term *t1,                 /* pattern */
             term *t2,   /* subject to be matched */
             env *l1,    /* local env for pattern */
             env *l2)    /* local env for subject */
{
  TBbool b;

  Bindings1 = NULL;
  Bindings2 = NULL;
  
  MATCHDB(TBmsg("match(%t,%t, %t,%t) ... \n", t1, t2, l1, l2));

  b = match1(substitute(t1, l1), substitute(t2, l2));

  MATCHDB(TBmsg(" ... %s\n", (b) ? "true" : "false"));
  return b;
}

static TBbool match1(term *t1, term *t2)
{
  term *v1, *v2;
  
  MATCHDB(TBmsg("match1(%t, %t)\n", t1, t2));
  if(t1 == t2)
    return TBtrue;

  if(is_anno(t2))
    return match1(t1, anno_term(t2));

  switch(tkind(t1)){
  case t_bool: 
    if(is_bool(t2))
      return (bool_val(t1) == bool_val(t2));
    else
      goto t2_is_result_var;
  case t_int:
    if(is_int(t2))
      return (int_val(t1) == int_val(t2));
    else
      goto t2_is_result_var;
  case t_real:
    if(is_real(t2))
      return (real_val(t1) == real_val(t2));
    else
      goto t2_is_result_var;
  case t_str:
    if(is_str(t2))
      return (streq(str_val(t1), str_val(t2)));
    else goto t2_is_result_var;

  case t_bstr:
    if(is_bstr(t2))
      return bstreq(t1, t2);
    else goto t2_is_result_var;
      
  case t_var:
    if(is_result_var(t1)){
      v1 = value(t1, Bindings1);
      if(v1 != t1)
	return match1(v1,t2);
      if(require_type(var_type(v1), t2)){
	Bindings1 = mk_env(v1, t2, Bindings1);
	return TBtrue;
      } else
	return TBfalse;
    } else if(is_var(t2)) {
      return var_type(t1) == var_type(t2);
    } else
      return TBfalse;
  case t_placeholder:                     /* !!! case t2 is placeholder not treated */
    return require_type(placeholder_type(t1), t2);
  case t_appl:
    if(is_appl(t2)){
      if(fun_sym(t1) != fun_sym(t2))
	return TBfalse;
      return match_list(fun_args(t1), fun_args(t2));
    } else
      goto t2_is_result_var;
  case t_anno:
    return match1(anno_term(t1), t2);
  case t_list:
    if(is_list(t2))
      return match_list(t1, t2);
    else
      goto t2_is_result_var;
  default:
    err_fatal("match1");
  }
 t2_is_result_var:
  if(is_result_var(t2)){
    v2 = value(t2, Bindings2);
    if(v2 != t2)
      return match1(t1, v2);    
    if(require_type(var_type(v2), t1)){
      Bindings2 = mk_env(v2, t1, Bindings2);
      return TBtrue;
    } else
      return TBfalse;
  } else
    return TBfalse;
}

static TBbool match_list(term *tl1, term *tl2)
{
  assert(is_list(tl1));
  assert(is_list(tl2));
  while(tl1){
    if(!tl2)
      return TBfalse;
    if(!match1(first(tl1), first(tl2)))
      return TBfalse;
    tl1 = next(tl1);
    tl2 = next(tl2);
  }
  return (tl2) ? TBfalse : TBtrue;
}

TBbool cmatchp(term *t1, term *t2)
{
  TBbool b;
  Bindings1 = NULL;
  Bindings2 = NULL;

  MATCHDB(TBprintf(stderr, "cmatchp(%t, %t)", t1, t2));
  b = match1(t1, t2);
  MATCHDB(TBprintf(stderr, " ... %s\n", (b) ? "true" : "false"));
  return b;
}


void init_match(void){
  TBprotect(&Bindings1);
  TBprotect(&Bindings2);
}
