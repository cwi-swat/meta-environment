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
#include "toolbus.h"
#include <string.h>
#include "terms.h"
#include "symbol.h"
#include "procs.h"

#define TERMDB(x)

static void mark_terms(void);
static char *resolve(char *, const char *);

/* Simple Garbage Collector */


/* Memory is divided in segments i=0,...NSEGMENT-1, each containing
   an array of segment_size(i) terms.  All free terms are maintained
   in a linked list pointed to by free_list.
*/

#define NSEGMENT 8192               /* Max. # of segments */
static term *segments[NSEGMENT];    /* pointers to the segments */
static int nsegment = 0;            /* number of segments in use */
static int nterm;                   /* total number of terms */

                                    /* size of each segment */
#define segment_size(n) ((n < 50) ? 2000 : 5000)

static term_list *free_list;        /* linked list of free terms */
static int nfree;                   /* number of free terms */

/* Marking of the memory starts in a number of ``roots'' maintained
   as an array of pointers to the actual term pointers.
   During marking a mark_stack is maintained for pointers still
   to be followed.
*/

#define NROOT 8192                  /* max. # of roots */
static int nroot = 0;               /* number of roots in use */
static term **mark_roots[NROOT];    /* array of roots */
#define NMARK 16384                 /* max. size of mark stack */
static term **mark_sp;              /* stack pointer into mark stack */
static term *mark_stack[NMARK];

static TBbool can_extend = TBtrue;  /* false after first malloc failure */

/* Add a memory segment */

static TBbool add_segment(void)
{
  term *t;
  int nelem = segment_size(nsegment);

  /* fprintf(stderr, "ADDING SEGMENT %d\n", nsegment);*/

  if((nsegment == NSEGMENT) || !can_extend)
    return TBfalse;
  
  segments[nsegment] = (term *) malloc(nelem * sizeof(term));

  if(!segments[nsegment]){
    if(nelem == 0){
      err_sys_fatal("Cannot allocate initial memory segment");
    } else {
      can_extend = TBfalse;
      return TBfalse;      /* give up, continue with current segments */
    }
  }

  for(t = &segments[nsegment][0]; t < &segments[nsegment][nelem]; t++){
    t->trm_kind = t_list;
    mark(t) = TBtrue;
    first(t) = NULL;
    next(t) = free_list;
    free_list = t;
  }
  nfree += nelem;
  nterm += nelem;
  nsegment++;

  return TBtrue;
}

static void init_term_store(void)
{ 
  free_list = NULL;
  nsegment = nfree =  nterm = 0;
  add_segment();
}

void TBprotect(term **pt)
{
  int i;

  for(i=0; i<nroot; i++) {
    if(!mark_roots[i]) {
      mark_roots[i] = pt;
      return;
    }
  }
  if(nroot < NROOT)
    mark_roots[nroot++] = pt;
  else
    err_fatal("Too many mark_roots (%d)", NROOT);
}

void TBunprotect(term **pt)
{
  int i;

  for(i = 0; i < nroot; i++)
    if(mark_roots[i] == pt){
      mark_roots[i] = NULL;
      return;
    }
  err_warn("TBunprotect called with unknown root\n");
}

/* Allocate a new term: either take it from the free list or add
   a memory segment. Note that we do *not* force a garbage collection
   in this case, because that would require a regime in which *all*
   C functions should protect/unprotect their newly created terms
   that are not yet accessible from some root. By calling the
   garbage collector frequently, and by maintaining an appropriate
   amount of free space all the time, this should not occur very often.
*/

#define new_term(t)  if(!free_list){\
			if(!add_segment())\
			   err_fatal("new_term: cannot add a segment");\
		     }\
                     t = free_list;\
                     free_list = next(free_list);\
                     nfree--;


/* Push a term to be marked on the mark_stack */

#define push_term(t) if(t && !mark(t)){\
                        mark(t) = TBtrue;\
                       if(contains_pointers(t)){\
			  if(mark_sp < &mark_stack[NMARK])\
                             *mark_sp++ = t;\
                          else\
                             err_fatal("stack overflow during garbage collection");\
		       }\
		     }

/*
   Fri Dec 19 11:43:06 MET 1997:
     Replaced the old version of TBcollect with a new one which
     has been contributed by Jan Friso Groote. This new version
     fixes a number of problems with the old algorithm, which was
     much too memory inefficient.
*/
/* Perform a complete garbage collection:
   - push all roots on the mark_stack
   - mark all terms that can be reached from there
   - visit the complete memory and for each term
     . remove its mark bit, or
     . add it to the free_list
*/

void TBcollect()
{
  register term *t;
  register int i, nf;
  register term_list *fl;
  static int l=0;

  if ((nterm - nfree) < 1.5*l) /* de La Poutre regel */
    return;

  mark_sp = &mark_stack[0];

  for(i = 0; i < nroot; i++){
    if(mark_roots[i]) {
      t = *mark_roots[i];
      push_term(t);
    }
  }
  mark_terms();

  fl = NULL;
  nf = 0;
  for(i = 0; i < nsegment; i++){
    register term *endt = &segments[i][segment_size(i)];

    for(t = &segments[i][0]; t < endt; t++){
      if(mark(t)){
        mark(t) = TBfalse;
      } else {
        if(is_str(t))
          free(str_val(t));
        else
          if(is_bstr(t))
            free(bstr_val(t));

        t->trm_kind = t_list;
        first(t) = NULL;
        next(t) = fl;
        fl = t;
        nf++;
      }
    }
  }
  free_list = fl;
  nfree = nf;
  l=nterm-nfree;

/*
  {  extern char *tool_name;
     fprintf(stderr, "%s: TBcollect. completed (%d total, %d free)\n", 
	  tool_name, nterm, nfree);
   }
*/
}

void add_free_list(term *tl)
{ term *t, *nextt;

  /* TBmsg("add_free_list(%d)\n", list_length(tl)); */

  for(; tl; tl = nextt){

    switch(tkind(tl)){
    case t_env:
      t = tl;
      nextt = env_next(t);
      goto case_list;

    case t_list:
      t = first(tl);
      nextt = next(tl);
    case_list:
      t->trm_kind = t_list;
      first(t) = NULL;
      next(t) = free_list;
      free_list = t;
      nfree++;
      continue;
    default:
      err_fatal("add_free_list");
      nextt = NULL; /* pedantic */
    }
  }
}

static void mark_terms(void)
{  
  register term *t, *t1;
  register term_list *ts;

  while(mark_sp > mark_stack){
    t = *--mark_sp;

    /* TBprintf(stderr, "Marking: %t\n", t); */

    switch(tkind(t)){  
			case t_bool:
			case t_int:
			case t_real:
			case t_str:
			case t_bstr:
				break;
				
			case t_var:
				t = var_type(t);  push_term(t); break;
			case t_placeholder:
				t = placeholder_type(t); push_term(t); break;
			case t_appl:
				for(ts = fun_args(t); ts; ts = next(ts)){
					mark(ts) = TBtrue;
					t = first(ts);
					push_term(t);
				}
				break;
			case t_list:
				for(ts = t; ts; ts = next(ts)){
					mark(ts) = TBtrue;
					t = first(ts);
					push_term(t);
				}
				break;
				
			case t_env:
				t1 = env_var(t); push_term(t1);
				t1 = env_val(t); push_term(t1);
				t1 = env_next(t); push_term(t1);
				break;

			case t_anno:
				t1 = anno_val(t); push_term(t1);
				t1 = anno_term(t); push_term(t1);
				break;
				
			default: err_fatal("mark_terms: illegal term encountered. check if " \
												 " all of your protected terms are legal or NULL!");
    }
  }
}

/*----------------------------------------------*/

#ifndef HAVE_STRDUP
char *strdup(register const char *s)
{
  register char *r = malloc(strlen(s)+1); /* char's followed by '\0' */

  if(!r)
    err_sys_fatal("strdup: can't malloc");
  return strcpy(r, s);
}
#endif

TBbool streq(register const char *s1, register const char *s2)
{ 
  return s1 && s2 && (strcmp(s1, s2) == 0);
}

/* Compare an ``unresolved'' name un with a ``resolved'' name rn
   of the form un$ProcName
*/

TBbool streq_unres(register char *un, register char *rn)
{
  while(*un){
    if(*un != *rn)
      return TBfalse;
    un++; rn++;
  }
  return (*rn == '$') ? TBtrue : TBfalse;    
}

TBbool bstreq(bstr *bs1, bstr *bs2)
{
  register char *rs1, *rs2, *end;
  register int n;

  assert(is_bstr(bs1) && is_bstr(bs2));

  n = bstr_len(bs1);
  if(n != bstr_len(bs2))
    return TBfalse;
  rs1 = bstr_val(bs1);
  rs2 = bstr_val(bs2);
  end = &rs1[n];

  if(rs1 == rs2)
    return TBtrue;
  if(rs1 && rs2){
    while(rs1 < end){
      if(*rs1++ != *rs2++)
	return TBfalse;
    }
    return TBtrue;
  } else
    return TBfalse;
}

term *mk_bool(TBbool b)
{
  register term *t;
  new_term(t);
  t->trm_kind = t_bool;
  mark(t) = has_conds(t) = TBfalse;
  bool_val(t) = b;
  return t;
}

term *mk_int(int n)
{
  register term *t;
  new_term(t);

  t->trm_kind = t_int;
  mark(t) = has_conds(t) = TBfalse;
  int_val(t) = n;
  return t;
}

term *mk_real(double d)
{
  register term *t;
  new_term(t);

  t->trm_kind = t_real;
  mark(t) = has_conds(t) = TBfalse;
  real_val(t) = d;
  return t;
}

term *mk_str(char *s)
{
  register term *t;
  new_term(t); 
  t->trm_kind = t_str;
  mark(t) = has_conds(t) = TBfalse;
  str_val(t) = strdup(s);
  /* fprintf(stderr, "mk_str: %s\n", s); */
  return t;
}

static char cbuf[256];

static char *resolve(char *id, const char *pname)
{
  if(*pname){
    /* only resolve, if non-empty pname */
    sprintf(cbuf, "%s$%s", id, pname);
    return cbuf;
  } else
    return id;
}

var *mk_var(char *s, char *pname, type *tp)
{
  register term *t;
  new_term(t);
  t->trm_kind = t_var;
  mark(t) = has_conds(t) = TBfalse;
  var_sym(t) = TBlookup(resolve(s, pname));
  var_type(t) = tp;
  var_formal(t) = var_result(t) = TBfalse;
  return t;
}

var *mk_var_idx(sym_idx n, type *tp)
{
  register term *t;
  new_term(t);
  t->trm_kind = t_var;
  mark(t) = has_conds(t) = TBfalse;
  var_sym(t) = n;
  var_type(t) = tp;
  var_formal(t) = var_result(t) = TBfalse;
  return t;
}

var *mk_result_var(char *s, char *pname, type *tp)
{
  register var *v = mk_var(s, pname, tp);
  var_result(v) = TBtrue;
  return v;
}

var *mk_result_var_idx(sym_idx n, type *tp)
{  
  register var *v = mk_var_idx(n, tp);
  var_result(v) = TBtrue;
  return v;
}

term *mk_formal(char *s, char *pname, type *tp)
{  
  register var *v = mk_var(s, pname, tp);
  var_formal(v) = TBtrue;
  return v;
}

term *mk_placeholder(type *tp)
{
  register term *t;
  new_term(t);

  t->trm_kind = t_placeholder;
  mark(t) = has_conds(t) = TBfalse;
  placeholder_type(t) = tp;
  return t;
}

term *mk_appl(sym_idx sym, term *args)
{
  register term *t;
  new_term(t);

  assert(is_list(args));
  t->trm_kind = t_appl;
  mark(t) = has_conds(t) = fun_str_sym(t) = TBfalse;
  fun_sym(t) = sym;
  fun_args(t) = args;
  return t;
}

term *mk_anno(term *an, term *at)
{  
  register term *t;
  new_term(t);

  t->trm_kind = t_anno;
  mark(t) = has_conds(t) = TBfalse;
  anno_val(t) = an;
  anno_term(t) = at;
  return t;
}

term *mk_list(register term *fst, register term *nxt)
{  
  register term *t;
  new_term(t);

  assert(is_list(nxt));
  t->trm_kind = t_list;
  mark(t) = has_conds(t) = TBfalse;
  first(t) = fst;
  next(t) = nxt;
  return t;
}

env *mk_env(var *v, term *t, env *e)
{ register env *re;
  new_term(re);
  re->trm_kind = t_env;
  mark(re) = has_conds(re) = TBfalse;
  env_sym(re) = var_sym(v);
  env_var(re) = v;
  env_val(re) = t;
  env_next(re) = e;
  return re;
}

/* MP_ bgn  is the address of the first char in the string and
       size is the maximum number of chars copied into the newly
       allocated string.
       Note: looks a lot like posix' `strndup', but is slightly different.
       it always allocates exactly _size_+1 octets, whereas strndup
       will allocate only strlen(bgn) if that's less than _size_.
*/
char *str_ndup(register char *bgn, int size)
{
  register char *r,  *s, *end;
  r = s = (char *) malloc(sizeof(*bgn) * (size + 1));
  if(!r)
    err_sys_fatal("str_ndup: can't malloc");
  end = &bgn[size];
  while(bgn < end)
    *s++ = *bgn++;
  *s = '\0';
  return r;
}

term *mk_bstr(char *s, int n)
{
  term *t;
  new_term(t);

  t->trm_kind = t_bstr;
  bstr_len(t) = n;
  bstr_val(t) = str_ndup(s, n);
  return t;
}

/* We use the following representation for binary strings:

	" STRING_MARK D D D D D D D D  STRING_MARK B B B B B ... "
                      <------------->              <-------  ...
		            N                         N bytes                     

   where the L's represent a field of LENSPEC bytes (ascii digits)
   giving the length N of the binary data field (the B's).

   The length of a binary string of N bytes is thus:
       2 (quotes) + 2 (STRING_MARKs) + LENSPEC (length field) + N (data bytes)

   (Based on earlier description by Simon Gray)
*/

void print_bstr(const char *s, int len)
{
  char len_spec[LENSPEC+2];

  printn("\"", 1);
  sprintf(len_spec, "%c%-.*d%c", STRING_MARK, LENSPEC, len, STRING_MARK);

  printn(len_spec, strlen(len_spec));
  printn(s, len);
  printn("\"", 1);
}

void esc_char(char c)
{

}

void print_str(const char *s)
{
  printn("\"", 1);
  while(*s){
    switch(*s){ 
    case '\\': printn("\\\\", 2); break;
    case '"': printn("\\\"", 2); break;
    default: printn(s, 1);
    }
    s++;
  }
  printn("\"", 1);
}

void print_fsym(TBbool is_str_sym, const char *s)
{  
  if(is_str_sym)         
    print_str(s);         /* function symbol is arbitrary string */
  else
    printn(s, strlen(s)); /* it is an identifier */
}

void pr_type(type *tp)
{
  printn(":", 1); pr_term(tp);
}

void pr_term(const term *t)
{ char cbuf[100], *ftxt;

  if(!t){
    printn("[]",2);
    return;
  }
  switch(tkind(t)){
  case t_bool:
    if(bool_val(t)) printn("true", 4); else printn("false",5); break;
  case t_int:
    sprintf(cbuf, "%d", int_val(t));
    printn(cbuf, strlen(cbuf)); break;
  case t_real:
    sprintf(cbuf, "%f", real_val(t));
    printn(cbuf, strlen(cbuf)); break;
  case t_str:
    print_str(str_val(t)); break;
  case t_bstr:
    print_bstr(bstr_val(t), bstr_len(t)); break;
  case t_var:
    ftxt = get_txt(var_sym(t));
    printn(ftxt, strlen(ftxt));
    pr_type(var_type(t));
    if(var_result(t))
      printn("?",1);
    break;  
  case t_placeholder:
    printn("<", 1); pr_term(placeholder_type(t)); printn(">",1);
    break;
  case t_appl:
    ftxt = get_txt(fun_sym(t));
    print_fsym(fun_str_sym(t), ftxt);
    if(fun_args(t) != NULL
       || (!fun_str_sym(t) && isupper((int)ftxt[0]))){
      /* Note: something fishy is going on here:
	 (a) Currently, Process names are also permitted as funcion symbol 
	     (although there start with an uppercase letter.
	 (b) We want to avoid that applications of the form
	     - a string function symbol
	     - no arguments
	     are printed as "@@@"() instead of "@@@"
      */
      printn("(",1);
      pr_term_list(fun_args(t));
      printn(")", 1);
    }
    break;
  case t_anno:
    pr_term(anno_term(t));printn("{", 1);pr_term_list(anno_val(t)); printn("}", 1);
    break;
  case t_list:
    printn("[", 1); pr_term_list(t); printn("]", 1);
    break;
  case t_env:
    pr_env(t);
    break;
	  
  default: err_fatal("pr_term: kind=%d", tkind(t));
  }
}

void pr_term_list(const term_list *tl)
{
  TBbool first_one = TBtrue;

  for( ; tl; tl = next(tl)){
    assert(is_list(tl));    
    if(first_one)
      first_one = TBfalse;
    else
      printn(",", 1);
    pr_term(first(tl));
  }
}

void pr_env(const env *e)
{
  TBbool first_one = TBtrue;

  printn("[", 1);
  for( ; e; e = env_next(e)){
    assert(is_env(e));    
    if(first_one)
      first_one = TBfalse;
    else
      printn(",", 1);
    printn("[", 1);
    pr_term(env_var(e));
    printn(",", 1);
    pr_term(env_val(e));
    printn("]",1);
  }
  printn("]", 1);
}

void pr_term_unquoted(const term *t)
{
  if(is_str(t))
    printn(str_val(t), strlen(str_val(t)));
  else
    pr_term(t);
}

/*-------------------- types ----------------------------------*/

TBbool has_no_vars(term *T)
{
  term_list *args;

  if(!T)
    return TBtrue;
  switch(tkind(T))
    {
    case t_bool: case t_int: case t_real: case t_str: case t_bstr:
      return TBtrue;
    case t_var:
      return TBfalse;
    case t_placeholder:
      return has_no_vars(placeholder_type(T));
    case t_appl:
      args = fun_args(T);
    case_appl:
      for( ; args; args = next(args)){
	if(!has_no_vars(first(args)))
	  return TBfalse;
      }
      return TBtrue;
    case t_anno:
      return has_no_vars(anno_term(T));
    case t_list:
      args = T;
      goto case_appl;
    case t_env:
      return has_no_vars(env_val(T)) && has_no_vars(env_next(T));
    default:
      err_fatal("has_no_vars");
    }
  return TBtrue; /* dummy */
}

TBbool has_result_vars(term *T)
{
  term_list *args;

  if(!T)
    return TBfalse;
  switch(tkind(T))
    {
    case t_bool: case t_int: case t_real: case t_str: case t_bstr:
      return TBfalse;
    case t_var:
      return var_result(T);
    case t_placeholder:
      return TBfalse;
    case t_appl:
      args = fun_args(T);
    case_appl:
      for( ; args; args = next(args)){
	if(has_result_vars(first(args)))
	  return TBtrue;
      }
      return TBfalse;
    case t_anno:
      return has_result_vars(anno_term(T));
    case t_list:
      args = T;
      goto case_appl;
    case t_env:
      return has_result_vars(env_val(T)) || has_result_vars(env_next(T));
    default:
      err_fatal("has_result_vars");
      return TBfalse; /* pedantic */
    }   
}

type *type_of(term *T)
{
  if(!T)
    return List;
  switch(tkind(T))
    {
    case t_bool: return Bool;
    case t_int: return Int;
    case t_real: return Real;
    case t_str:return Str;
    case t_bstr:return Bstr;
    case t_list:return List;
    case t_var:
      return var_type(T);
    case t_appl:
      return mk_appl(fun_sym(T), NULL);
    case t_anno:
      return type_of(anno_term(T));
    default:
      err_fatal("type_of: %t", T);
      return Term; /* pedantic */
    }
}

/* tp1 is the desired type, tp2 is the type acually given.
   Yield true is they are comparable.
   Ex.  int        vs int        -> true
        int        vs real       -> false
        [int, int] vs [int, int] -> true
        list(int)  vs [int, int] -> true
        list       vs [int, int] -> true
        list(int)  vs list       -> true
        [int, int] vs list(int)  -> true
        [int, int] vs list       -> true
	f          vs f(<int.))  -> true
*/

TBbool comp_type(type *tp1, type *tp2)
{
  /* TBmsg("comp_type(%t,%t)\n", tp1, tp2); */

  if(term_equal(tp1, tp2))
    return TBtrue;  /* desired type is equal to given type */

  if(is_anno(tp1))
    return comp_type(anno_term(tp1), tp2);

  if(is_anno(tp2))
    return comp_type(tp1, anno_term(tp2));

  if(is_appl(tp1) && is_appl(tp2) && (fun_sym(tp1) == fun_sym(tp2)) &&
     !fun_args(tp1))
    return TBtrue; /* desired type is less precise than given type */

  /* treat all [...]/list combinations */

  if(is_appl(tp2)){
    type *tp3 = tp1; 
    tp1 = tp2; tp2 = tp3;
  }
  if(is_appl(tp1) && fun_sym(tp1) == TBlookup("list")){
    if(is_appl(tp2) && fun_sym(tp2) == TBlookup("list")){
      if(fun_args(tp1) && fun_args(tp2))
	return term_equal(first(fun_args(tp1)), first(fun_args(tp2)));
      else
	return TBtrue;
    }
    if(!is_list(tp2))
      return TBfalse;
    if(!fun_args(tp1))
      return TBtrue;
    else { 
      term *req_tp = first(fun_args(tp1));
      term_list *targs;

      for(targs = tp2; targs; targs = next(targs)){
	if(!comp_type(req_tp, first(targs)))
	  return TBfalse;
      }
      return TBtrue;
    }
  }
  return TBfalse;
}

TBbool require_type(register type *tp, register term *T)
{
  register term_list *targs, *args;

  /* TBmsg("require_type(%t, %t)\n", tp, T); */
  if(is_anno(tp))
    return require_type(anno_term(tp), T);
  if(is_anno(T))
    return require_type(tp, anno_term(T));
  if(is_var(T))
    return comp_type(tp, var_type(T));
  if(is_placeholder(tp))
    return require_type(placeholder_type(tp), T);
  if(is_placeholder(T))
    return comp_type(tp, placeholder_type(T));
  else if(is_list(tp)){
    if(is_list(T)){
      targs = T;
      for(args = tp; args; args = next(args)){
	if(!targs || !require_type(first(args), first(targs)))
	  return TBfalse;
	targs = next(targs);
      }
      return targs ? TBfalse : TBtrue;	
    } else
      return TBfalse;
  } else if(is_appl(tp)) {
    switch(fun_sym(tp)){
    case type_bool:
      if(!fun_args(tp)){
	if(is_bool(T) ||
	   (is_appl(T) && !fun_args(T) && 
	    (fun_sym(T) == TBlookup("true") || fun_sym(T) == TBlookup("false"))))
	  return TBtrue;
	else
	  return TBfalse;
      } else goto case_appl;
    case type_int:
      if(is_int(T) && !fun_args(tp))
	return TBtrue;
      else goto case_appl;
    case type_real:
      if(is_real(T) && !fun_args(tp))
	return TBtrue;
      else
	goto case_appl;
    case type_str:
      if(is_str(T) && !fun_args(tp))
	return TBtrue;
      else goto case_appl;
    case type_bstr:
      if(is_bstr(T) && !fun_args(tp))
	return TBtrue;
      else goto case_appl;
    case type_list:
      if(is_list(T)){
	if(!fun_args(tp))
	  return TBtrue;
	else {
	  term *req_tp = first(fun_args(tp));

	  for(targs = T; targs; targs = next(targs)){
	    if(!require_type(req_tp, first(targs)))
	      return TBfalse;
	  }
	  return TBtrue;
	}
      } else
	return TBfalse;
    case type_term:
      return TBtrue;

    default:
    case_appl:
      
      if(!is_appl(T) ||(fun_sym(tp) != fun_sym(T)))
	return TBfalse;
      if(!fun_args(tp))
	return TBtrue;
      targs = fun_args(T);
      for(args = fun_args(tp); args; args = next(args)){
	if(!targs || !require_type(first(args), first(targs)))
	  return TBfalse;
	targs = next(targs);
      }
      return targs ? TBfalse : TBtrue;
    }
  } else
    return term_equal(tp, T);
}

/*--------------------- term utilities ------------------------*/

term *convert_to_sign(term *t)
{
  if(!t)
    return t;
  switch(tkind(t))
    {
    case t_bool:
      return mk_placeholder(Bool);
    case t_int:
      return mk_placeholder(Int);
    case t_real:
      return mk_placeholder(Real);
    case t_str:
      return mk_placeholder(Str);
    case t_bstr:
      return mk_placeholder(Bstr);
    case t_var:
      return mk_placeholder(var_type(t));

    case t_list:
      { term_list *nw_list = NULL;
	for( ; t; t = next(t)){
	  nw_list = list_concat_term(nw_list, convert_to_sign(first(t)));
	}
	return nw_list;
      }
    case t_appl:
      { term_list * nw_args = NULL, *args;
	for(args=fun_args(t); args; args = next(args)){
	  nw_args = list_concat_term(nw_args, convert_to_sign(first(args)));
	}
	return mk_appl(fun_sym(t), nw_args);
      }
    case t_anno:
      return convert_to_sign(anno_term(t));
    default: return t;
    }
}

int list_length(term *tl)
{
  register int n = 0;
  register term *head;

  assert(is_list(tl));
  for(head = tl; head; head = next(head)){
    assert(is_list(tl));
    n++;
  }
  return n;
}

TBbool term_equal(register term *t1, register term *t2)
{
  /* TBmsg("term_equal(%t,%t)\n", t1, t2); */
  if(t1 == t2) {
    return TBtrue;
  }

  if(tkind(t1) != tkind(t2)) {
    if(tkind(t1) == t_anno) {
      return term_equal(anno_term(t1), t2);
    }
    else if(tkind(t2) == t_anno) {
      return term_equal(t1, anno_term(t2));
    }
    else {
      return TBfalse;
    }
  }

  switch(tkind(t1)){
  case t_bool:
    return bool_val(t1) == bool_val(t2);
  case t_int:
    return int_val(t1) == int_val(t2);
  case t_real:
    return real_val(t1) == real_val(t2);
  case t_str:
    return streq(str_val(t1), str_val(t2));
  case t_bstr:
    return bstreq(t1, t2);
  case t_var:
    return var_sym(t1) == var_sym(t2);
  case t_appl:
    if(fun_sym(t1) == fun_sym(t2))
       return list_equal(fun_args(t1), fun_args(t2));
    else
      return TBfalse;
  case t_list:
    return list_equal(t1, t2);
  case t_placeholder:
    return term_equal(placeholder_type(t1),placeholder_type(t2));
  case t_env:
    return TBfalse;
  default:
    err_fatal("term_equal(%t,%t)", t1, t2);
  }
  return TBfalse; /* dummy */
}

TBbool list_equal(register term *t1, register term *t2)
{    
  while(t1){
    if(!t2)
      return TBfalse;
    assert(is_list(t1)); assert(is_list(t2));
    if(!term_equal(first(t1), first(t2)))
      return TBfalse;
    t1 = next(t1);
    t2 = next(t2);
  }
  return (t2) ? TBfalse : TBtrue;
}

/* copy toplevel of list; elements are shared */

term_list *list_copy(term_list *tl)
{
  term head, *prev;
  assert(is_list(tl));

  /* TBmsg("list_copy(%t) ... ", tl); */
  prev = &head;
  for(next(&head) = tl; tl; tl = next(tl)){
    next(prev) = mk_list(first(tl), next(tl));
    prev = next(prev);
  }
  /* TBmsg("%t\n", next(&head)); */

  return next(&head);
}

/* concatenate tl2 at the end of list tl; tl is changed */
     
term *list_concat(term_list *tl, term_list *tl2)
{ term head, *prev = &head;

  assert(is_list(tl) && is_list(tl2));
  prev = &head;
  for(next(&head) = tl; tl; tl = next(tl)){
    assert(is_list(tl));
    prev = next(prev);
  }
  next(prev) = tl2;
  return next(&head);
}

/* concatenate t at the end of list tl; tl is changed */

term* list_concat_term(term_list *tl, term *t)
{
  return list_concat(tl, mk_list(t, NULL));
}

/* append tl2 at the end of list tl; tl is copied */
     
term *list_append(term_list *tl, term_list *tl2)
{ term head, *prev;

  prev = &head;
  for(next(&head) = tl; tl; tl = next(tl)){
    next(prev) = mk_list(first(tl), next(tl));
    prev = next(prev);
  }
  next(prev) = tl2;
  return next(&head);
}

/* get n-element of list */

term *list_index(term_list *tl, int n)
{
  term_list *tl1 = tl;
  int i = n;

  while(i > 1 && tl1) {
    tl1 = next(tl1);
    i--;
  }
  if(tl1 && (i == 1))
    return first(tl1);
  else {
    err_warn("index %d out of range in %t\n", n, tl);
    return NULL;
  }
}

/* replace n-element of list */

term_list *list_replace(term_list *tl, int n, term *v)
{ 
  
  term_list head, *prev, *tl1 = tl;
  int i = n;

  prev = &head;
  next(&head) = tl1;
  while(i > 1 && tl1) {
    next(prev) = mk_list(first(tl1),next(tl1));
    prev = next(prev);
    tl1 = next(tl1);
    i--;
  }
  /*TBmsg("i = %d, tl1 = %t\n", i, tl1);*/
  if(i == 1 && tl1){
    next(prev) = mk_list(v,next(tl1));
    return next(&head);
  } else {
    err_warn("replace: index %d out of range in %t\n", n, tl);
    return tl;
  }
}


/* is t element of list tl? */

TBbool list_elem(term *t, term_list *tl)
{
  assert(is_list(tl));
  for( ; tl; tl = next(tl)){
    if(term_equal(t, first(tl)))
      return TBtrue;
  }
  return TBfalse;
}

/* delete t from ts; modifies ts */

term_list *list_delete(term_list *ts, term *t)
{
  term head, *prev;

  assert(is_list(ts));
  /* TBmsg("list_delete(%t,%t)\n", ts, t); */

  prev = &head;
  for(next(&head) = ts; ts; ts = next(ts)){
    if(term_equal(t, first(ts))){
      next(prev) = next(ts);
      /* TBmsg("list_delete returns: %t\n", next(&head));*/
      return next(&head);
    }
    prev = ts;
  }
  /* TBmsg("list_delete returns: %t\n", next(&head)); */
  return next(&head);
}

/* is sub a subset of sup? */

TBbool list_subset(term_list *sub, term_list *sup)
{
  term_list *sup1;

  assert(is_list(sub)); 
  assert(is_list(sup));

  sup1 = list_copy(sup);
  for( ; sub; sub = next(sub))
    if(!list_elem(first(sub), sup1))
      return TBfalse;
    else
      sup1 = list_delete(sup1, first(sub));
    
  return TBtrue;
}

/* Create the set difference sup - sub as a new list */

term_list *list_diff(term_list *sup, term_list *sub)
{
  term_list *sup1;

  assert(is_list(sub)); 
  assert(is_list(sup));

  /* TBmsg("diff(%t,%t)\n", sup, sub); */

  if(sub){
    sup1 = list_copy(sup);
    for( ; sub; sub = next(sub))
      sup1 = list_delete(sup1, first(sub));
    
    return sup1;
  } else
    return sup;     
}

/* Reverse a list L, modifies L */

term_list *list_reverse(term_list *L)
{
  term_list *prev = NULL, *cur, *nxt;

  cur = L;
  while(cur){
    nxt = next(cur);
    next(cur) = prev;
    prev = cur;
    cur = nxt;
  }
  return prev;
}

/* Create the intersection of L and M as a new list */

term_list *list_inter(term_list *L, term_list *M)
{
  assert(is_list(L)); 
  assert(is_list(M));

  if(L && M){
    term_list *res = NULL, *M1 = list_copy(M);

    for( ; L; L = next(L)){
      if(list_elem(first(L), M1)){
	M1 = list_delete(M1, first(L));
	res = mk_list(first(L), res);
      }
    }    
    return list_reverse(res);
  } else
    return NULL;    
}

/* Union of list tl1 and tl2; modifies tl1 */

term *list_union(term_list *tl1, term_list *tl2)
{

  for( ; tl2; tl2 = next(tl2))
    if(!list_elem(first(tl2), tl1))
      tl1 = list_concat_term(tl1, first(tl2));
  return tl1;	
}

term_list *list_join(term *L, term *M)
{
  if(is_list(L)){
    if(is_list(M))
      return list_append(L, M);
    else
      return list_append(L, mk_list(M, NULL));
  } else {
    if(is_list(M))
      return mk_list(L, M);
    else
      return mk_list(L, mk_list(M, NULL));
  }
}

/* return term v if list tl contains an immdediate sublist [key,v] */
/* return [] otherwise */

term *list_get(term_list *tl, term *key)
{ term_list *pair;

  for( ; tl; tl = next(tl)){
    assert(is_list(tl));
    pair = first(tl);
    if(pair && is_list(pair)){
      if(term_equal(first(pair), key))
	return first(next(pair));
    }
  }
  return NULL;
}

/* if list tl contains an immediate sublist [key, v], */
/* then replace it by [key, val]                      */
/* If not, add the pair [key, val] to tl              */
/* tl is partially copied                             */

term_list *list_put(term_list *tl, term *key, term *val)
{
  term_list head, *prev = &head, *pair;
 

  for(next(&head) = tl; tl; tl = next(tl)){
    assert(is_list(tl));
    pair = first(tl);
    if(pair && is_list(pair)){
      if(term_equal(first(pair), key)){
	tl = next(tl);
	goto add_pair;
      } else {
	next(prev) = mk_list(first(tl), next(tl));
	prev = next(prev);
      }
    }
  }

 add_pair:
  next(prev) = mk_list(mk_list(key, mk_list(val, NULL)), tl);
  return next(&head);
}

/* return the value of variable v in term_list e. This function resembles */
/* get_list but applies the same rules as the function value (see env.c)  */
/* concerning variable binding and formal parameters                      */
/* Returns v itself if no binding is found                                */

/* *** CHANGE, since env structure was changes */

term *get_list_as_env(register var *v, term_list *e)
{
  register term_list *e1;
  register sym_idx sym = var_sym(v);
  term *entry;
  term *entry_var;

  /* TBmsg("value of %t\n", v); */

  for(e1 = e; e1; e1 = next(e1)){
    entry = first(e1);
    assert(is_list(entry) && (list_length(entry) == 2));
    entry_var = elm1(entry);
    if(sym == var_sym(entry_var)){
      register term *val = elm2(entry);
      /* TBmsg("val = %t\n", val); */
      if(is_var(val)){
	v = val;
	sym = var_sym(v);
      } else
	return val;
    }
  }
  return v;
}

/*------------------------------------------------------------*/

/* find the first subterm in t with fsym as function symbol. */

static term *first_function_sym(sym_idx fsym, term *t)
{
  term *t1;
  term_list *elems;

  if(!t)
    return NULL;

  switch(tkind(t)){
  case t_appl:
    if(fun_sym(t) == fsym)
      return t;
    elems=fun_args(t);
  case_args:
    for( ; elems; elems = next(elems)){
      t1 = first_function_sym(fsym, first(elems));
      if(t1)
	return t1;
    }
    return NULL;
  case t_list:
    elems = t;
    goto case_args;
  case t_anno:
    return first_function_sym(fsym, anno_term(t));
  default:
    return NULL;
  }
}

term *first_function(char *fname, term *t){
  return first_function_sym(TBlookup(fname), t);
}

/* find all subterms in t with function symbol fname. */
/* return a list */

static term *all_functions_sym(sym_idx fsym, term *t)
{
  term *t1;
  term_list *elems, *res = NULL;

  if(!t)
    return NULL;

  switch(tkind(t)){
  case t_appl:
    if(fun_sym(t) == fsym)
      return mk_list1(t);
    elems = fun_args(t);
  case_args:
    for( ; elems; elems = next(elems)){
      t1 = all_functions_sym(fsym, first(elems));
      if(t1)
	res = list_concat_term(res, t1);
    }
    return res;
  case t_list:
    elems = t;
    goto case_args;
  case t_anno:
    return all_functions_sym(fsym, anno_term(t));
  default:
    return NULL;
  }
}

term *all_functions(char *fname, term *t){
  return all_functions_sym(TBlookup(fname), t);
}


/* Perform an innermost traversal of t and replace all subterms s in t with
 * function symbol fsym by R(s).
 * Returns (a possibly modified) term t.
 */

static term *all_functions_do_sym(sym_idx fsym, term *t, term *(*R)(term *))
{
  term_list *elems;

  if(!t)
    return NULL;

  switch(tkind(t)){
  case t_appl:
    for(elems = fun_args(t); elems; elems = next(elems))
      first(elems) = all_functions_do_sym(fsym, first(elems), R);
      
      return (fun_sym(t) == fsym) ? (*R)(t) : t;
  case t_list:
    for(elems = t; elems; elems = next(elems))
      first(elems) = all_functions_do_sym(fsym, first(elems), R);
    return t;
  case t_anno:
    anno_term(t) = all_functions_do_sym(fsym, anno_term(t), R);
    return t;
  default:
    return t;
  }
}

term *all_functions_do(char *fname, term *t, term *(*R)(term *)){
  return all_functions_do_sym(TBlookup(fname), t, R);
}

/*------------------------------------------------------------*/

term *True;          /* PROTECTED */
term *False;         /* PROTECTED */

term *Bool;          /* PROTECTED */
term *Int;           /* PROTECTED */
term *Real;          /* PROTECTED */
term *Str;           /* PROTECTED */
term *Bstr;          /* PROTECTED */
term *List;          /* PROTECTED */
term *Term;          /* PROTECTED */
term *Undefined;     /* PROTECTED */

void init_terms(void)
{
  sym_idx idx;

  init_term_store();

  SYMDEF("bool", type_bool);
  SYMDEF("int", type_int);
  SYMDEF("real", type_real);
  SYMDEF("str", type_str);
  SYMDEF("bstr", type_bstr);
  SYMDEF("list", type_list);
  SYMDEF("term", type_term);
  SYMDEF("undefined", sym_undefined);
  

  True = mk_bool(TBtrue);       TBprotect(&True);
  False = mk_bool(TBfalse);     TBprotect(&False);
  Bool = mk_appl(type_bool, NULL); TBprotect(&Bool);
  Int = mk_appl(type_int, NULL);   TBprotect(&Int);
  Real = mk_appl(type_real, NULL);   TBprotect(&Real);
  Str = mk_appl(type_str, NULL);   TBprotect(&Str);
  Bstr = mk_appl(type_bstr, NULL); TBprotect(&Bstr);
  List = mk_appl(type_list, NULL); TBprotect(&List);
  Term = mk_appl(type_term, NULL); TBprotect(&Term);
  Undefined = mk_appl(sym_undefined, NULL); TBprotect(&Undefined);
}
