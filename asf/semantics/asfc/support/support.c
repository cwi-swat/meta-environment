
/**
  * Library support for muASF2C compiled modules.
  *
  * Pieter Olivier
  * Thu Aug 14 11:36:34 MET DST 1997
  */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include <asfix.h>
#include <tb-tool.h>

#include "support.h"



/*{{{  globals */

typedef struct bucket
{
  struct bucket *next_prod;
  struct bucket *next_sym;
  aterm *prod;
  funcptr func;
  asymbol *sym;
} bucket;

#define MAX_STORE 1024
static aterm *term_store[MAX_STORE];

static int nr_entries = 0;
static int table_size = 0;
static bucket **prod_table = NULL;
static bucket **sym_table = NULL;
aworld *w;
aterm *c_true;
aterm *c_false;

asymbol *oksym;
asymbol *nullsym;

aterm *pattern_asfix_term = NULL;
static aterm *pattern_asfix_appl = NULL;
static aterm *pattern_asfix_prod = NULL;
static aterm *pattern_asfix_list = NULL;
static aterm *pattern_asfix_lex  = NULL;
static aterm *pattern_asfix_l    = NULL;
static aterm *pattern_asfix_ql   = NULL;
static aterm *pattern_asfix_ws   = NULL;
static aterm *pattern_asfix_sort = NULL;
static aterm *pattern_listtype   = NULL;
static aterm *pattern_listtype_sep = NULL;
static aterm *pattern_char       = NULL;
static aterm *pattern_lexical_constructor = NULL;
static aterm *pattern_caller_id = NULL;
static aterm *ws = NULL;

/*}}}  */

/*{{{  void c_rehash(int newsize) */

/**
  * Create a new (larger?) hash table and rehash all old the entries.
  */

void c_rehash(int newsize)
{
  int i, hnr;
  bucket **newprodtable, **newsymtable, *b, *next;

  /* Allocate new hash tables */
  newprodtable = (bucket **)malloc(sizeof(bucket *)*newsize);
  newsymtable = (bucket **)malloc(sizeof(bucket *)*newsize);
  if(!newsymtable || !newprodtable)
    fatal_error("out of memory in c_rehash(%d)", newsize);

  /* Initialize the new hash tables */
  for(i=0; i<newsize; i++) {
    newprodtable[i] = NULL;
    newsymtable[i] = NULL;
  }

  /* Rehash all the old buckets. */
  if(prod_table) {
    for(i=0; i<table_size; i++) {
      b = prod_table[i];
      while(b) {
	next = b->next_prod;
	hnr = b->prod->hnr % newsize;
	b->next_prod = newprodtable[hnr];
	newprodtable[hnr] = b;
	b = next;
      }
      b = sym_table[i];
      while(b) {
	next = b->next_sym;
	hnr = b->sym->hnr % newsize;
	b->next_sym = newsymtable[hnr];
	newsymtable[hnr] = b;
	b = next;
      }
    }
  }

  prod_table = newprodtable;
  sym_table = newsymtable;
  table_size = newsize;
}

/*}}}  */
/*{{{  void register_prod(aterm *prod, funcptr func, asymbol *sym) */

void register_prod(aterm *prod, funcptr func, asymbol *sym)
{
  int hnr;
  bucket *b;

  if((nr_entries*100)/table_size > MAX_LOAD)
    c_rehash(table_size*2);

  hnr = prod->hnr % table_size;

  /* Find out if this function has already been registered */
  b = prod_table[hnr];
  while(b && !t_equal(b->prod, prod))
    b = b->next_prod;
  if(b)
    return;
    /*fatal_error("duplicate function registered: %t\n", prod);*/

  /* Add a new bucket */
  b = malloc(sizeof(bucket));
  if(!b)
    fatal_error("out of memory in register.\n");
  b->next_prod = prod_table[hnr];
  prod_table[hnr] = b;

  /* Add it to the sym table also. */
  hnr = sym->hnr % table_size;
  b->next_sym = sym_table[hnr];
  sym_table[hnr] = b;

  b->prod = prod;
  b->func = func;
  b->sym  = sym;
  t_protect(b->prod);

 
}

/*}}}  */
/*{{{  funcptr lookup_func(aterm *prod) */

funcptr lookup_func(aterm *prod)
{
  int hnr = prod->hnr % table_size;
  bucket *b = prod_table[hnr];

  while(b) {
    if(t_equal(b->prod, prod))
      return b->func;
    b = b->next_prod;
  }
  fatal_error("unknown function: %t\n", prod);
  return NULL; /* silence the compiler, we never get here. */
}

/*}}}  */
/*{{{  asymbol *lookup_sym(aterm *prod) */

asymbol *lookup_sym(aterm *prod)
{
  int hnr = prod->hnr % table_size;
  bucket *b = prod_table[hnr];

  while(b) {
    if(t_equal(b->prod, prod))
      return b->sym;
    b = b->next_prod;
  }
  fatal_error("unknown function: %t\n", prod);
  return NULL; /* silence the compiler, we never get here. */
}

/*}}}  */
/*{{{  aterm *lookup_prod(asymbol *sym) */

aterm *lookup_prod(asymbol *sym)
{
  int hnr = sym->hnr % table_size;
  bucket *b = sym_table[hnr];

  while(b) {
    if(b->sym == sym)
      return b->prod;
    b = b->next_sym;
  }
  fatal_error("unknown symbol: %s\n", t_sym_name(sym));
  return NULL; /* silence the compiler, we never get here. */
}

/*}}}  */
/*{{{  aterm_list *string2list(arena *ar,char *s) */

/**
  * Translate a string to a list of integers (characters)
  */

aterm_list *string2list(arena *ar,char *s)
{
  int i;
  aterm_list *tmp, *old, *result = t_empty(t_world(*ar));
  t_protect(result);

  for(i=strlen(s)-1; i>=0; i--) {
    old = result;
    tmp = TbuildInt(w,s[i]);
    result = TbuildList(w,tmp, result);
    t_unprotect(tmp);
    t_unprotect(old);
  }

  Tadd2Arena(ar,result);
  t_unprotect(result);
  return result;
}

/*}}}  */

/*{{{  static aterm *call(aterm *prod, aterm_list *args) */

static aterm *call(arena *ar, aterm *prod, aterm_list *args)
{
  funcptr func = lookup_func(prod);
  aterm *result = NULL;
  aterm *arg[8];

  assert(func);
  switch(TlistSize(args)) {
    case 0: result = (*func)();
      break;
    case 1: 
	arg[0] = t_list_first(args);
	t_protect(arg[0]);
	result = (*func)(arg[0]);
      	break;

    case 2: 
	arg[0] = t_list_first(args);
	arg[1] = t_list_first(t_list_next(args));
	t_protect(arg[0]);
	t_protect(arg[1]);
	result = (*func)(arg[0],arg[1]);
        break;
    case 3: 
	arg[0] = t_list_first(args);
	arg[1] = TlistIndex(args, 1);
	arg[2] = TlistIndex(args, 2);
	t_protect(arg[0]);
	t_protect(arg[1]);
	t_protect(arg[2]);
        result = (*func)(arg[0],arg[1],arg[2]);
        break;
    case 4: 
	arg[0] = t_list_first(args);
	arg[1] = TlistIndex(args, 1);
	arg[2] = TlistIndex(args, 2);
	arg[3] = TlistIndex(args, 3);
	t_protect(arg[0]);
	t_protect(arg[1]);
	t_protect(arg[2]);
	t_protect(arg[3]);
        result = (*func)(arg[0],arg[1],arg[2],arg[3]);
        break;
    case 5: 
	arg[0] = t_list_first(args);
	arg[1] = TlistIndex(args, 1);
	arg[2] = TlistIndex(args, 2);
	arg[3] = TlistIndex(args, 3);
	arg[4] = TlistIndex(args, 4);
	t_protect(arg[0]);
	t_protect(arg[1]);
	t_protect(arg[2]);
	t_protect(arg[3]);
	t_protect(arg[4]);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4]);
        break;
    case 6: 
	arg[0] = t_list_first(args);
	arg[1] = TlistIndex(args, 1);
	arg[2] = TlistIndex(args, 2);
	arg[3] = TlistIndex(args, 3);
	arg[4] = TlistIndex(args, 4);
	arg[5] = TlistIndex(args, 5);
	t_protect(arg[0]);
	t_protect(arg[1]);
	t_protect(arg[2]);
	t_protect(arg[3]);
	t_protect(arg[4]);
	t_protect(arg[5]);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5]);
        break;
    case 7:  
        arg[0] = t_list_first(args);
        arg[1] = TlistIndex(args, 1);
        arg[2] = TlistIndex(args, 2);
        arg[3] = TlistIndex(args, 3);
        arg[4] = TlistIndex(args, 4);
        arg[5] = TlistIndex(args, 5);
        arg[6] = TlistIndex(args, 6);
        t_protect(arg[0]);
        t_protect(arg[1]);
        t_protect(arg[2]);
        t_protect(arg[3]);
        t_protect(arg[4]);
        t_protect(arg[5]);
        t_protect(arg[6]);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6]);
        break;
    case 8:   
        arg[0] = t_list_first(args);
        arg[1] = TlistIndex(args, 1);
        arg[2] = TlistIndex(args, 2);
        arg[3] = TlistIndex(args, 3);
        arg[4] = TlistIndex(args, 4);
        arg[5] = TlistIndex(args, 5);
        arg[6] = TlistIndex(args, 6);
        arg[7] = TlistIndex(args, 7);
        t_protect(arg[0]);
        t_protect(arg[1]);
        t_protect(arg[2]);
        t_protect(arg[3]);
        t_protect(arg[4]);
        t_protect(arg[5]);
        t_protect(arg[6]);
        t_protect(arg[7]);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7]);
        break;
    default:
      fatal_error("too many arguments: %d\n", TlistSize(args));
  }
  Tadd2Arena(ar, result);
  t_unprotect(result);
  return result;
}

/*}}}  */
/*{{{  static aterm *make_caller_prod(arena *ar,aterm *sort) */

aterm *make_caller_prod(arena *ar,aterm *sort)
{
  aterm *prod;
  char *text;
  int i;

  assertp(TmatchTerm(sort, pattern_asfix_sort, &text));
  text = strdup(text);
  if(!text) {
    fprintf(stderr,"Not enough memory\n");
    exit(1);
  }
  for(i=0; text[i]; i++)
    text[i] = tolower(text[i]);
  prod = TmakeTerm(ar, pattern_lexical_constructor, text, sort);
  free(text);
  return prod;
}

/*}}}  */
/*{{{  static aterm *make_list_type(arena *ar, aterm *type, aterm *args) */

/**
  * Build a list from type and args.
  */

static aterm *make_list_type(arena *ar, aterm *type, aterm_list *args)
{
  aterm *tsort, *tsep;
  aterm_list *iterargs;
  char *sort, *sep;
  char symbol_buf[256];
  asymbol *sym;

  if(TmatchTerm(type, pattern_iter, &tsort, NULL, NULL)) {
    TmatchTerm(tsort, pattern_asfix_sort, &sort);
    sprintf(symbol_buf, "listtype(sort(\"%s\"))", sort);
    sym = TmkSymbol(symbol_buf, SYM_STRING);
    return TmkAppl_s(ar, sym, TmkList(ar, args, t_empty(t_world(args))));
  } else if(TmatchTerm(type, pattern_itersep, &iterargs)) {
    tsort = TlistIndex(iterargs, 2);
    tsep  = TlistIndex(iterargs, 4);
    TmatchTerm(tsort, pattern_asfix_sort, &sort);
    TmatchTerm(tsep, pattern_asfix_ql, &sep);
    sprintf(symbol_buf, "listtype(sort(\"%s\"),ql(\"%s\"))", sort, sep);
    sym = TmkSymbol(symbol_buf, SYM_STRING);
    return TmkAppl_s(ar, sym, TmkList(ar, args, t_empty(t_world(args))));
  } else {
    fatal_error("illegal list type: %t\n", type);
    return NULL; /* silence the compiler */
  }
}

/*}}}  */
/*{{{  static aterm *innermost(arena *ar, aterm *t) */

static aterm *innermost_list(arena *ar, aterm_list *l);

aterm *innermost(arena *ar, aterm *t)
{
  aterm *prod, *ws, *args, *sort, *list, *result;
  char *lex;

  if(TmatchTerm(t, pattern_asfix_appl, &prod, &ws, &args)) {
    if(AFisBracketCfFunc(prod))
      result = innermost(ar, TlistIndex(args, 2));
    else {
      result = call(ar,prod, innermost_list(ar, args));
    }
  }
  else if(TmatchTerm(t,pattern_asfix_lex, &lex, &sort)) {
    aterm_list *l = string2list(ar, lex);
    arena global;
    TinitArena(NULL, &global);
    prod = make_caller_prod(&global, sort);
    result = call(ar,prod,
                Tmake(ar,
                      "[\"listtype(sort(\\\"CHAR\\\"))\"(<term>)]",
                      l));
    TdestroyArena(&global);
  }
  else if(TmatchTerm(t, pattern_asfix_list, &list, &ws, &args)) {
    aterm_list *newargs = innermost_list(ar, args);
    result = make_list_type(ar, list, newargs);
  }
  else
    result = NULL;
  return result;
}

/*}}}  */
/*{{{  static aterm *innermost_list(aterm_list *l) */

static aterm *innermost_list(arena *ar, aterm_list *l)
{
  aterm *el;
  aterm_list *result = t_empty(w);

  while(!t_is_empty(l)) {
    el = innermost(ar, t_list_first(l));
    if(el)
      result = TlistAppend(ar, result, el);
    l = t_list_next(l);
  }
  return result;
}

/*}}}  */
/*{{{  static aterm *make_asfix_list(arena *ar, aterm_list *l, char *sort) */

static aterm *term_to_asfix(arena *ar, aterm *t, aterm *sort);

static aterm *make_asfix_list(arena *ar, aterm_list *l, char *sort)
{
  aterm *tsort = TmakeTerm(ar, pattern_asfix_sort, sort);
  aterm *iter = TmakeTerm(ar, pattern_iter_star, tsort, ws);
  aterm *list = t_empty(t_world(*ar));
  aterm *tmp;

  int i, len = TlistSize(l);
  if(len > 0) {
    tmp = term_to_asfix(ar,TlistIndex(l, len-1),tsort);
    list = TmkList(ar, tmp, list);
    for(i = len-2; i >= 0; i--) {
      list = TmkList(ar, ws, list);
      tmp = term_to_asfix(ar,TlistIndex(l, i),tsort);
      list = TmkList(ar, tmp, list);
    }
  }
  return TmakeTerm(ar, pattern_asfix_list, iter, ws, list);  
}

/*}}}  */
/*{{{  static aterm *make_asfix_list_sep(arena *ar, aterm_list *l, sort,sep) */

static aterm *make_asfix_list_sep(arena *ar, aterm_list *l, 
				  char *sort, char *sep)
{
  aterm *accolopen = TmakeSimple(ar, "l(\"{\")");
  aterm *accolclose = TmakeSimple(ar, "l(\"}\")");
  aterm *qsep = Tmake(ar, "ql(<str>)", sep);
  aterm *listsep = Tmake(ar, "sep(<str>)", sep);
  aterm *list = t_empty(t_world(*ar));
  aterm *tmp;
  int i;

  aterm *tsort = TmakeTerm(ar, pattern_asfix_sort, sort);
  aterm *iter = TmakeTerm(ar, pattern_itersep_star, accolopen, ws, tsort, ws,
			  qsep, ws, accolclose, ws);

  int len = TlistSize(l);
  if(len > 0) {
    tmp = term_to_asfix(ar,TlistIndex(l, len-1),tsort);
    list = TmkList(ar, tmp, list);
    for(i = len-2; i >= 0; i--) {
      list = TmkList(ar, ws, list);
      list = TmkList(ar, listsep, list);
      list = TmkList(ar, ws, list);
      tmp = term_to_asfix(ar,TlistIndex(l, i),tsort);
      list = TmkList(ar, tmp, list);
    }
  }

  return TmakeTerm(ar, pattern_asfix_list, iter, ws, list);  
}

/*}}}  */
/*{{{  static aterm *make_asfix_lex(arena *ar, aterm_list *chars, aterm *sort) */

/**
  * Build an asfix lex from a list of characters.
  */

static aterm *make_asfix_lex(arena *ar, aterm_list *chars, aterm *sort)
{
  char *buf;
  int i, len = TlistSize(chars);
  buf = malloc(len+1);
  if(!buf) {
    fatal_error("out of memory trying to allocate lex of %d chars\n", len);
    exit(1);
  }
  i = 0;
  while(!t_is_empty(chars)) {
    buf[i++] = t_int_val(t_list_first(chars));
    chars = t_list_next(chars);
  }
  buf[i] = '\0';

  return TmakeTerm(ar, pattern_asfix_lex, buf, sort);
}

/*}}}  */
/*{{{  static aterm *toasfix(arena *ar, aterm *t, aterm *f, aterm *n) */

static aterm_list *terms_to_asfix(arena *ar, aterm_list *a, aterm_list *t, aterm *sort);

aterm *toasfix(arena *ar, aterm *t, aterm *f, aterm *n)
{
  aterm *newterm;
  arena local;
 
  TinitArena(t_world(*ar), &local);
  newterm =  Tmake(ar, "term(l(\"term\"),w(\" \"),<term>,w(\"\"),<term>," \
	               "w(\"\\n\"),<term>,w(\"\\n\"),abbreviations([]))",
                       f, n, term_to_asfix(ar, t, NULL));
  
  Tadd2Arena(ar,newterm);
  TdestroyArena(&local);
  return newterm;
}

/*}}}  */
/*{{{  static aterm *term_to_asfix(arena *ar, aterm *t) */

static aterm *term_to_asfix(arena *ar, aterm *t, aterm *sort)
{
  aterm *result, *prod, *mod, *fargs, *lexsort;
  char *listsort, *sep;
  arena local;

  TinitArena(t_world(*ar), &local);
/*Tprintf(stderr, "term_to_asfix: %t\n", t);*/
  if(t_is_appl(t)) {
    prod = lookup_prod(t_appl_sym(t));
    if(!prod) {
      fatal_error("unknown production symbol: %s\n", t_sym_name(t_appl_sym(t)));
    }
    if(TmatchTerm(prod, pattern_lexical_constructor, NULL, &lexsort)) {
      return term_to_asfix(&local, t_list_first(t_appl_args(t)), lexsort);
    } if(TmatchTerm(prod, pattern_asfix_prod, &mod, NULL, &fargs, NULL, NULL, 
		  NULL, &sort, NULL, NULL)) {
      
      aterm *args = terms_to_asfix(&local, fargs, t_appl_args(t), sort);
      if(t_equal(mod, pattern_caller_id)) 
        result = t_list_first(args);
      else
        result = TmakeTerm(&local, pattern_asfix_appl, prod, ws, args);
    } else if(TmatchTerm(prod, pattern_listtype, &listsort)) {
      if(streq(listsort, "CHAR")) {
	result = make_asfix_lex(&local, t_list_first(t_appl_args(t)), sort);
      } else {
	result = make_asfix_list(&local, t_list_first(t_appl_args(t)), listsort);
      }
    } else if(TmatchTerm(prod, pattern_listtype_sep, &listsort, &sep)) {
      result = make_asfix_list_sep(&local, t_list_first(t_appl_args(t)), 
				   listsort, sep);
    } else {
      fatal_error("cannot handle production: %t\n", prod);
      exit(1);
    }
  } else {
    fatal_error("cannot handle term type: %t\n", t);
    exit(1);
  }

  Tadd2Arena(ar,result);
  TdestroyArena(&local);
  return result;
}

/*}}}  */
/*{{{  static aterm_list *terms_to_asfix(arena *ar, aterm_list *args, aterm_list *terms, sort) */

/**
  * Translate a list of arguments back to asfix.
  */

static aterm_list *terms_to_asfix(arena *ar, aterm_list *args, 
                                  aterm_list *terms, aterm *sort)
{
  aterm_list *result = t_empty(t_world(*ar));
  int i, j = TlistSize(terms)-1, len = TlistSize(args);
  char *str;

  for(i=len-1; i>=0; i--) {
    aterm *tmp = TlistIndex(args,i);
    if(Tmatch(tmp,"w(<str>)",NULL)) {
      result = TmkList(ar, tmp, result);
    } else if(TmatchTerm(tmp,pattern_asfix_ql,&str)) {
      aterm *tmp2 = TmakeTerm(ar,pattern_asfix_l,str);
      result = TmkList(ar, tmp2, result);
    } else if(TmatchTerm(tmp, pattern_asfix_l, &str)) {
      result = TmkList(ar, tmp, result);
    } else {
      aterm *tmp2 = term_to_asfix(ar, TlistIndex(terms,j), sort);
      result = TmkList(ar, tmp2, result);
      j--;
    }
  }

  return result;
}

/*}}}  */

/*{{{  void init_patterns(arena *ar) */

void init_patterns(arena *ar)
{
  pattern_asfix_term = TmakeSimple(ar, "term(<term>,<term>,<term>," \
				   "<term>,<term>,<term>,<term>,<term>,<term>)");
  pattern_asfix_appl = TmakeSimple(ar, "appl(<term>,<term>,<list>)");
  pattern_asfix_prod = TmakeSimple(ar, "prod(<term>,<term>,<term>,<term>," \
				   "<term>,<term>,<term>,<term>,<term>)");
  pattern_asfix_list = TmakeSimple(ar, "list(<term>,<term>,<list>)");
  pattern_asfix_lex  = TmakeSimple(ar, "lex(<str>,<term>)");
  pattern_asfix_l    = TmakeSimple(ar, "l(<str>)");
  pattern_asfix_ql   = TmakeSimple(ar, "ql(<str>)");
  pattern_asfix_ws   = TmakeSimple(ar, "ws(<str>)");
  pattern_asfix_sort = TmakeSimple(ar, "sort(<str>)");
  pattern_listtype   = TmakeSimple(ar, "listtype(sort(<str>))");
  pattern_listtype_sep = TmakeSimple(ar, "listtype(sort(<str>),ql(<str>))");
  pattern_char       = TmakeSimple(ar, "\"CHAR\"");
  pattern_lexical_constructor = TmakeSimple(ar, 
     "prod(id(\"caller\"),w(\"\"),[l(<str>),w(\"\"),ql(\"(\"),w(\"\")," \
     "iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")]," \
     "w(\"\"),l(\"->\"),w(\"\"),<term>,w(\"\"),no-attrs)");
  pattern_caller_id   = TmakeSimple(ar, "id(\"caller\")");

  ws = TmakeSimple(ar, "w(\"\n\")");
 
  c_true = TmakeSimple(ar,"true");
  c_false = TmakeSimple(ar,"false");

  t_protect(pattern_asfix_term);
  t_protect(pattern_asfix_appl);
  t_protect(pattern_asfix_prod);
  t_protect(pattern_asfix_list);
  t_protect(pattern_asfix_lex);
  t_protect(pattern_asfix_l);
  t_protect(pattern_asfix_ql);
  t_protect(pattern_asfix_ws);
  t_protect(pattern_asfix_sort);
  t_protect(pattern_listtype);
  t_protect(pattern_listtype_sep);
  t_protect(pattern_char);
  t_protect(pattern_lexical_constructor);
  t_protect(pattern_caller_id);
 
  t_protect(ws);

  t_protect(c_true);
  t_protect(c_false);
}

/*}}}  */

/*{{{  list access functions */
aterm *null()
{
  t_protect(t_empty(w));
  return t_empty(w);
}

aterm *list_head(aterm_list *l)
{
  t_protect(t_list_first(l));
  t_unprotect(l);
  return t_list_first(l);
}

aterm_list *list_tail(aterm_list *l)
{
  t_protect(t_list_next(l));
  t_unprotect(l);
  return t_list_next(l);
}

aterm_list *cons(aterm_list *l1, aterm_list *l2)
{
  aterm_list *old, *result;
  int i;

  if(t_is_empty(l2)) {
    /* For efficiency reasons, no need to traverse l1 when l2 is empty */
    t_unprotect(l2);
    return l1;
  }

  result = l2;
  for(i=TlistSize(l1)-1; i>=0; i--) {
    old = result;
    result = TbuildList(w, TlistIndex(l1, i), result);
    t_unprotect(old);
  }
  t_unprotect(l1);
  return result;
}

aterm *list_last(aterm_list *l)
{
  aterm_list *org = l,*tail = l; aterm *el;
/*Tprintf(stderr,"list_last entered with %t\n",l);*/
  do {
    l = tail;
    tail = t_list_next(l);
  } while(!t_is_empty(tail));
  el = t_list_first(l);
/*Tprintf(stderr,"list_last selects from %t\nelement %t\n",l,el);*/
  t_protect(el);
  t_unprotect(org);
  return el;
}

aterm_list *list_prefix(aterm_list *l)
{
  aterm_list *result, *old, *oldl;
  int len, entries;
  int i;

  oldl = l;
  result = t_empty(w);
  t_protect(result);

  len = TlistSize(l)-1;
  entries = MIN(len, MAX_STORE);
  for(i=0; i<entries; i++) {
    term_store[i] = t_list_first(l);
    l = t_list_next(l);
  }

  for(i=TlistSize(l)-2; i>=0; i--) {
    old = result;
    result = TbuildList(w, TlistIndex(l, i), result);
    t_unprotect(old);
  }

  for(i=entries-1; i>=0; i--) {
    old = result;
    result = TbuildList(w, term_store[i], result);
    t_unprotect(old);
  }

  t_unprotect(oldl);
  return result;
}

/*}}}  */
/*{{{  aterm *term_equal(aterm *t1, aterm *t2) */

/* Test for equality on terms. */

extern Tbool term_equal(aterm *t1, aterm *t2)
{
  if(t_equal(t1, t2)) {
    t_unprotect(t1);
    t_unprotect(t2);
    return Ttrue;
  }
  t_unprotect(t1);
  t_unprotect(t2);
  return Tfalse;
}

/*}}}  */
/*{{{  Tbool not_empty_list(aterm *l) */

/**
  * Check that a term does not represent the empty list.
  */

Tbool not_empty_list(aterm *l)
{
  if(t_is_empty(l)) {
    t_unprotect(l);
    return Tfalse;
  }
  t_unprotect(l);
  return Ttrue;
}

/*}}}  */
/*{{{  Tbool is_single_element(aterm_list *l) */

/**
  * Check if a list is a singleton list.
  */

Tbool is_single_element(aterm_list *l)
{
  if(t_is_list(l) && (!t_is_empty(l) && t_is_empty(t_list_next(l)))) {
    t_unprotect(l);
    return Ttrue;
  }
  t_unprotect(l);
  return Tfalse;
}

/*}}}  */
/*{{{  aterm_list *make_list(aterm *t) */

/**
  * Build a list from a term.
  */

aterm_list *make_list(aterm *t)
{
  aterm *result;

  if(t_is_list(t)) {
    return t;
  }
  result = singleton(t);
  t_unprotect(t);
  return result;
}

/*}}}  */
/*{{{  aterm *ok(aterm *t) */

aterm *ok(aterm *t)
{
  aterm *result, *tmp = TbuildList(w, t, t_empty(w));
  result = TbuildAppl(w, oksym, tmp);
  t_unprotect(tmp);
  t_unprotect(t);
  return result;
}

/*}}}  */

/*{{{  Make normal forms */

/*{{{  aterm *make_nf0(asymbol *s) */

aterm *make_nf0(asymbol *s)
{
  return TbuildAppl(w, s, t_empty(w));
}

/*}}}  */
/*{{{  aterm *make_nf1(asymbol *s, aterm *t0) */

aterm *make_nf1(asymbol *s, aterm *t0)
{
  aterm *result;
  aterm_list *args = TbuildList(w, t0, t_empty(w));
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */
/*{{{  aterm *make_nf2(asymbol *s, aterm *t0, aterm *t1) */

aterm *make_nf2(asymbol *s, aterm *t0, aterm *t1)
{
  aterm *result;
  aterm_list *args = TbuildList(w, t1, t_empty(w));
  t_unprotect(t1);
  args = TbuildList(w, t0, args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */
/*{{{  aterm *make_nf3(asymbol *s, aterm *t0, aterm *t1, aterm *t2) */

aterm *make_nf3(asymbol *s, aterm *t0, aterm *t1, aterm *t2)
{
  aterm *result;
  aterm_list *args = TbuildList(w, t2, t_empty(w));
  t_unprotect(t2);
  args = TbuildList(w, t1, args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */
/*{{{  aterm *make_nf4(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3)
 */

aterm *make_nf4(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3)
{
  aterm *result;
  aterm_list *args = TbuildList(w, t3, t_empty(w));
  t_unprotect(t3);
  args = TbuildList(w, t2, args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */
/*{{{  make_nf5 */

aterm *make_nf5(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4)
{
  aterm *result;
  aterm_list *args = TbuildList(w, t4, t_empty(w));
  t_unprotect(t4);
  args = TbuildList(w, t3, args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */
/*{{{  make_nf6 */

aterm *make_nf6(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4, aterm *t5)
{
  aterm *result;
  aterm_list *args = TbuildList(w, t5, t_empty(w));
  t_unprotect(t5);
  args = TbuildList(w, t4, args);
  t_unprotect(t4);
  args = TbuildList(w, t3, args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */
/*{{{  make_nf7 */

aterm *make_nf7(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4, aterm *t5, aterm *t6)
{
  aterm *result;
  aterm_list *args = TbuildList(w, t6, t_empty(w));
  t_unprotect(t6);
  args = TbuildList(w, t5, args);
  t_unprotect(t5);
  args = TbuildList(w, t4, args);
  t_unprotect(t4);
  args = TbuildList(w, t3, args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */
/*{{{  make_nf8 */

aterm *make_nf8(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4, aterm *t5, aterm *t6, aterm *t7)
{
  aterm *result;
  aterm_list *
  args = TbuildList(w, t7, t_empty(w));
  t_unprotect(t7);
  args = TbuildList(w, t6, args);
  t_unprotect(t6);
  args = TbuildList(w, t5, args);
  t_unprotect(t5);
  args = TbuildList(w, t4, args);
  t_unprotect(t4);
  args = TbuildList(w, t3, args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */
/*{{{  make_nf9 */

aterm *make_nf9(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8)
{
  aterm *result;
  aterm_list *
  args = TbuildList(w, t8, t_empty(w));
  t_unprotect(t8);
  args = TbuildList(w, t7, t_empty(w));
  t_unprotect(t7);
  args = TbuildList(w, t6, args);
  t_unprotect(t6);
  args = TbuildList(w, t5, args);
  t_unprotect(t5);
  args = TbuildList(w, t4, args);
  t_unprotect(t4);
  args = TbuildList(w, t3, args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */
/*{{{  make_nf10 */

aterm *make_nf10(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8,
		 aterm *t9)
{
  aterm *result;
  aterm_list *
  args = TbuildList(w, t9, t_empty(w));
  t_unprotect(t9);
  args = TbuildList(w, t8, t_empty(w));
  t_unprotect(t8);
  args = TbuildList(w, t7, t_empty(w));
  t_unprotect(t7);
  args = TbuildList(w, t6, args);
  t_unprotect(t6);
  args = TbuildList(w, t5, args);
  t_unprotect(t5);
  args = TbuildList(w, t4, args);
  t_unprotect(t4);
  args = TbuildList(w, t3, args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */
/*{{{  make_nf11 */

aterm *make_nf11(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8,
		 aterm *t9, aterm *t10)
{
  aterm *result;
  aterm_list *
  args = TbuildList(w, t10, t_empty(w));
  t_unprotect(t10);
  args = TbuildList(w, t9, t_empty(w));
  t_unprotect(t9);
  args = TbuildList(w, t8, t_empty(w));
  t_unprotect(t8);
  args = TbuildList(w, t7, t_empty(w));
  t_unprotect(t7);
  args = TbuildList(w, t6, args);
  t_unprotect(t6);
  args = TbuildList(w, t5, args);
  t_unprotect(t5);
  args = TbuildList(w, t4, args);
  t_unprotect(t4);
  args = TbuildList(w, t3, args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */
/*{{{  make_nf12 */

aterm *make_nf12(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8,
		 aterm *t9, aterm *t10, aterm *t11)
{
  aterm *result;
  aterm_list *
  args = TbuildList(w, t11, t_empty(w));
  t_unprotect(t11);
  args = TbuildList(w, t10, t_empty(w));
  t_unprotect(t10);
  args = TbuildList(w, t9, t_empty(w));
  t_unprotect(t9);
  args = TbuildList(w, t8, t_empty(w));
  t_unprotect(t8);
  args = TbuildList(w, t7, t_empty(w));
  t_unprotect(t7);
  args = TbuildList(w, t6, args);
  t_unprotect(t6);
  args = TbuildList(w, t5, args);
  t_unprotect(t5);
  args = TbuildList(w, t4, args);
  t_unprotect(t4);
  args = TbuildList(w, t3, args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */
/*{{{  make_nf13 */

aterm *make_nf13(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8,
		 aterm *t9, aterm *t10, aterm *t11, aterm *t12)
{
  aterm *result;
  aterm_list *
  args = TbuildList(w, t12, t_empty(w));
  t_unprotect(t12);
  args = TbuildList(w, t11, t_empty(w));
  t_unprotect(t11);
  args = TbuildList(w, t10, t_empty(w));
  t_unprotect(t10);
  args = TbuildList(w, t9, t_empty(w));
  t_unprotect(t9);
  args = TbuildList(w, t8, t_empty(w));
  t_unprotect(t8);
  args = TbuildList(w, t7, t_empty(w));
  t_unprotect(t7);
  args = TbuildList(w, t6, args);
  t_unprotect(t6);
  args = TbuildList(w, t5, args);
  t_unprotect(t5);
  args = TbuildList(w, t4, args);
  t_unprotect(t4);
  args = TbuildList(w, t3, args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */
/*{{{  make_nf14 */

aterm *make_nf14(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8,
		 aterm *t9, aterm *t10, aterm *t11, aterm *t12, aterm *t13)
{
  aterm *result;
  aterm_list *
  args = TbuildList(w, t13, t_empty(w));
  t_unprotect(t13);
  args = TbuildList(w, t12, t_empty(w));
  t_unprotect(t12);
  args = TbuildList(w, t11, t_empty(w));
  t_unprotect(t11);
  args = TbuildList(w, t10, t_empty(w));
  t_unprotect(t10);
  args = TbuildList(w, t9, t_empty(w));
  t_unprotect(t9);
  args = TbuildList(w, t8, t_empty(w));
  t_unprotect(t8);
  args = TbuildList(w, t7, t_empty(w));
  t_unprotect(t7);
  args = TbuildList(w, t6, args);
  t_unprotect(t6);
  args = TbuildList(w, t5, args);
  t_unprotect(t5);
  args = TbuildList(w, t4, args);
  t_unprotect(t4);
  args = TbuildList(w, t3, args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */
/*{{{  make_nf15 */

aterm *make_nf15(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8,
		 aterm *t9, aterm *t10, aterm *t11, aterm *t12, aterm *t13,
		 aterm *t14)
{
  aterm *result;
  aterm_list *
  args = TbuildList(w, t14, t_empty(w));
  t_unprotect(t14);
  args = TbuildList(w, t13, t_empty(w));
  t_unprotect(t13);
  args = TbuildList(w, t12, t_empty(w));
  t_unprotect(t12);
  args = TbuildList(w, t11, t_empty(w));
  t_unprotect(t11);
  args = TbuildList(w, t10, t_empty(w));
  t_unprotect(t10);
  args = TbuildList(w, t9, t_empty(w));
  t_unprotect(t9);
  args = TbuildList(w, t8, t_empty(w));
  t_unprotect(t8);
  args = TbuildList(w, t7, t_empty(w));
  t_unprotect(t7);
  args = TbuildList(w, t6, args);
  t_unprotect(t6);
  args = TbuildList(w, t5, args);
  t_unprotect(t5);
  args = TbuildList(w, t4, args);
  t_unprotect(t4);
  args = TbuildList(w, t3, args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */

/*}}}  */
/*{{{  Select arguments of application */

#define tail_1(l) (t_list_next(l))
#define tail_2(l) (t_list_next(tail_1(l)))
#define tail_3(l) (t_list_next(tail_2(l)))
#define tail_4(l) (t_list_next(tail_3(l)))
#define tail_5(l) (t_list_next(tail_4(l)))
#define tail_6(l) (t_list_next(tail_5(l)))
#define tail_7(l) (t_list_next(tail_6(l)))
#define tail_8(l) (t_list_next(tail_7(l)))
#define tail_9(l) (t_list_next(tail_8(l)))
#define tail_10(l) (t_list_next(tail_9(l)))
#define tail_11(l) (t_list_next(tail_10(l)))
#define tail_12(l) (t_list_next(tail_11(l)))
#define tail_13(l) (t_list_next(tail_12(l)))
#define tail_14(l) (t_list_next(tail_13(l)))
#define tail_15(l) (t_list_next(tail_14(l)))

aterm *arg_0(aterm *appl)
{
  aterm *result = t_list_first(t_appl_args(appl));
  t_protect(result);
  return result;
}

aterm *arg_1(aterm *appl)
{
  aterm *result = t_list_first(tail_1(t_appl_args(appl)));
  t_protect(result);
  return result;
}

aterm *arg_2(aterm *appl)
{
  aterm *result = t_list_first(tail_2(t_appl_args(appl)));
  t_protect(result);
  return result;
}

aterm *arg_3(aterm *appl)
{
  aterm *result = t_list_first(tail_3(t_appl_args(appl)));
  t_protect(result);
  return result;
}

aterm *arg_4(aterm *appl)
{
  aterm *result = t_list_first(tail_4(t_appl_args(appl)));
  t_protect(result);
  return result;
}

aterm *arg_5(aterm *appl)
{
  aterm *result = t_list_first(tail_5(t_appl_args(appl)));
  t_protect(result);
  return result;
}

aterm *arg_6(aterm *appl)
{
  aterm *result = t_list_first(tail_6(t_appl_args(appl)));
  t_protect(result);
  return result;
}

aterm *arg_7(aterm *appl)
{
  aterm *result = t_list_first(tail_7(t_appl_args(appl)));
  t_protect(result);
  return result;
}

aterm *arg_8(aterm *appl)
{
  aterm *result = t_list_first(tail_8(t_appl_args(appl)));
  t_protect(result);
  return result;
}

aterm *arg_9(aterm *appl)
{
  aterm *result = t_list_first(tail_9(t_appl_args(appl)));
  t_protect(result);
  return result;
}

aterm *arg_10(aterm *appl)
{
  aterm *result = t_list_first(tail_3(t_appl_args(appl)));
  t_protect(result);
  return result;
}

aterm *arg_11(aterm *appl)
{
  aterm *result = t_list_first(tail_11(t_appl_args(appl)));
  t_protect(result);
  return result;
}

aterm *arg_12(aterm *appl)
{
  aterm *result = t_list_first(tail_12(t_appl_args(appl)));
  t_protect(result);
  return result;
}

aterm *arg_13(aterm *appl)
{
  aterm *result = t_list_first(tail_13(t_appl_args(appl)));
  t_protect(result);
  return result;
}

aterm *arg_14(aterm *appl)
{
  aterm *result = t_list_first(tail_14(t_appl_args(appl)));
  t_protect(result);
  return result;
}

aterm *arg_15(aterm *appl)
{
  aterm *result = t_list_first(tail_15(t_appl_args(appl)));
  t_protect(result);
  return result;
}

/*}}}  */
