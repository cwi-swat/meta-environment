
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

#define MIN(a,b) ((a) > (b) ? (b) : (a))
#define MAX_STORE 10240
static aterm *term_store[MAX_STORE];

static int nr_entries = 0;
static int table_size = 0;
static bucket **prod_table = NULL;
static bucket **sym_table = NULL;
aworld *w;
aterm *c_true;
aterm *c_false;
aterm *char_table[256];

asymbol *oksym;
asymbol *tuplesym;
asymbol *tuple2sym;
asymbol *tuple3sym;
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
    tmp = make_char(s[i]);
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

static int get_list_length(aterm_list *chars)
{
  int len = 0;
  while(!t_is_empty(chars)) {
    aterm *el = t_list_first(chars);
    chars = t_list_next(chars);
    if(t_is_list(el))
      len += get_list_length(el);
    else
      len++;
  }
  return len;
}

static char *get_chars_from_list(char *buf, aterm_list *chars)
{
  while(!t_is_empty(chars)) {
    aterm *el = t_list_first(chars);
    chars = t_list_next(chars);
    if(t_is_list(el))
      buf = get_chars_from_list(buf, el);
    else
      *buf++ = t_int_val(el);
  }
  return buf;
}

static aterm *make_asfix_lex(arena *ar, aterm_list *chars, aterm *sort)
{
  char *buf, *end;
  aterm *result;
  int len = get_list_length(chars);

  buf = malloc(len+1);
  if(!buf) {
    fatal_error("out of memory trying to allocate lex of %d chars\n", len);
    exit(1);
  }
  end = get_chars_from_list(buf, chars);
  *end = '\0';
  result = TmakeTerm(ar, pattern_asfix_lex, buf, sort);
  free(buf);
  return result;
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
    if(TmatchTerm(tmp, pattern_asfix_ws, NULL)) {
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
  int i;

  pattern_asfix_term = TmakeSimple(ar, "term(<term>,<term>,<term>," \
				   "<term>,<term>,<term>,<term>,<term>,<term>)");
  pattern_asfix_appl = TmakeSimple(ar, "appl(<term>,<term>,<list>)");
  pattern_asfix_prod = TmakeSimple(ar, "prod(<term>,<term>,<term>,<term>," \
				   "<term>,<term>,<term>,<term>,<term>)");
  pattern_asfix_list = TmakeSimple(ar, "list(<term>,<term>,<list>)");
  pattern_asfix_lex  = TmakeSimple(ar, "lex(<str>,<term>)");
  pattern_asfix_l    = TmakeSimple(ar, "l(<str>)");
  pattern_asfix_ql   = TmakeSimple(ar, "ql(<str>)");
  pattern_asfix_ws   = TmakeSimple(ar, "w(<str>)");
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

  /* make characters */
  for(i=0; i<256; i++) {
    char_table[i] = TbuildInt(w, i);
    t_protect(char_table[i]);
  }

}

/*}}}  */

/*{{{  internal boolean functions */
aterm *t()
{
  t_protect(c_true);
  return c_true;
}

aterm *f()
{
  t_protect(c_false);
  return c_false;
}

aterm *or(aterm *t0,aterm *t1)
{
  t_protect(c_true);
  if(term_equal(t0,c_true)) {
    t_unprotect(t1);
    t_protect(c_true);
    return c_true;
  }
  else {
    return t1;
  }
}
/*}}}  */
/*{{{  list access functions */

aterm *null()
{
  t_protect(t_empty(w));
  return t_empty(w);
}

#ifndef DONT_NORMALIZE_LISTS
/*{{{  Version with list normalization */

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
  aterm_list *old, *oldl1 = l1, *result;
  int i, len;

  if(t_is_empty(l2)) {
    /* For efficiency reasons, no need to traverse l1 when l2 is empty */
    t_unprotect(l2);
    return l1;
  }

  result = l2;  
  len = MIN(MAX_STORE, TlistSize(l1));
  for(i=0; i<len; i++) {
    term_store[i] = t_list_first(l1);
    l1 = t_list_next(l1);
  }

  for(i=TlistSize(l1)-1; i>=0; i--) {
    old = result;
    result = TbuildList(w, TlistIndex(l1, i), result);
    t_unprotect(old);
  }

  for(i=len-1; i>=0; i--) {
    old = result;
    result = TbuildList(w, term_store[i], result);
    t_unprotect(old);
  }

  t_unprotect(oldl1);
  return result;
}

int slice_length(aterm_list *l1, aterm_list *l2)
{
  int size = 0;
  aterm *old = l1;
  while(l1 != l2) {
    assert(l1);
    if(t_is_empty(l1))
      Tprintf(stderr, "sorry, %t not in %t\n", l2, old);
    size++;
    l1 = t_list_next(l1);
  }
  return size;
}

aterm_list *append(aterm_list *l, aterm *t)
{
  int idx = TlistSize(l)-1;
  aterm_list *old, *result = TbuildList(w, t, t_empty(w));
  for( ; idx >= 0; idx--) {
    old = result;
    result = TbuildList(w, TlistIndex(l, idx), result);
    t_unprotect(old);
  }
  return result;
}

aterm_list *slice(aterm_list *l1, aterm_list *l2)
{
  aterm_list *result, *old, *oldl1 = l1;
  int i, len;

  if(t_is_empty(l2)) {
    t_unprotect(l2);
    return l1;
  }

  len = MIN(MAX_STORE, slice_length(l1, l2));
  for(i=0; i<len; i++) {
    term_store[i] = t_list_first(l1);
    l1 = t_list_next(l1);
  }

  result = t_empty(w);
  t_protect(result);

  while(l1 != l2) {
    old = result;
    result = append(result, t_list_first(l1));
    l1 = t_list_next(l1); 
    t_unprotect(old);
  }

  for(i=len-1; i>=0; i--) {
    old = result;
    result = TbuildList(w, term_store[i], result);
    t_unprotect(old);
  }
 
  t_unprotect(oldl1);
  t_unprotect(l2);
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
#else
/*{{{  Version without list normalization */

/*{{{  aterm *list_head(aterm_list *l) */

aterm *list_head(aterm_list *l)
{
  aterm_list *tmp = l;

  while(t_is_list(tmp))
    tmp = t_list_first(tmp);

  t_protect(tmp);
  t_unprotect(l);
  return tmp;
}

/*}}}  */
/*{{{  aterm_list *list_tail(aterm_list *l) */

static aterm_list *get_tail(aterm_list *l)
{
  if(t_is_list(t_list_first(l))) {
    aterm_list *tail = get_tail(t_list_first(l));
    if(t_is_empty(tail)) {
      /* The first list consists of a single element, wrapped in a number
	 of lists. We can just return the tail of the list. */
      t_protect(t_list_next(l));
      t_unprotect(tail);
      return t_list_next(l);
    } else {
      return TbuildList(w, tail, t_list_next(l));
    }
  }
  /* We can now remove the first element, which is not a list. */
  t_protect(t_list_next(l));
  return t_list_next(l);
}

aterm_list *list_tail(aterm_list *l)
{
  aterm_list *result;
  if(t_is_empty(l))
    return l;

  result = get_tail(l); 
  t_unprotect(l);
  return result;
}

/*}}}  */
/*{{{  aterm_list *cons(aterm_list *l1, aterm_list *l2) */

aterm_list *cons(aterm_list *l1, aterm_list *l2)
{
  aterm_list *result;

  if(t_is_empty(l1)) {
    t_unprotect(l1);
    return l2;
  } 
  if(t_is_empty(l2)) {
    t_unprotect(l2);
    return l1;
  }
  result = TbuildList(w, l1, l2);
  t_unprotect(l1);
  t_unprotect(l2);
  return result;
}

/*}}}  */
/*{{{  static aterm *get_last(aterm_list *l) */

static aterm *get_last(aterm_list *l)
{
  while(!t_is_empty(t_list_next(l)))
    l = t_list_next(l);
  return t_list_first(l);
}

/*}}}  */
/*{{{  aterm *list_last(aterm_list *l) */

aterm *list_last(aterm_list *l)
{
  aterm_list *tmp = l;

  while(t_is_list(tmp))
    tmp = get_last(tmp);
  t_protect(tmp);
  t_unprotect(l);
  return tmp;
}

/*}}}  */
/*{{{  static aterm_list *replace_last(aterm_list *l, aterm *t) */

static aterm_list *replace_last(aterm_list *l, aterm *t)
{
  aterm_list *old, *result;
  int i, entries, len;
  
  result = TbuildList(w, t, t_empty(w));

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

  return result;  
}

/*}}}  */
/*{{{  static aterm_list *delete_last(aterm_list *l) */

static aterm_list *delete_last(aterm_list *l)
{
  aterm_list *old, *result;
  int i, entries, len;
  
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

  return result;
}

/*}}}  */
/*{{{  aterm_list *get_prefix(aterm_list *l) */

aterm_list *get_prefix(aterm_list *l)
{
  aterm_list *last;

  last = get_last(l);
  if(t_is_list(last)) {
    aterm_list *prefix = get_prefix(last);
    if(!t_is_empty(prefix))
      return replace_last(l, prefix);
  }
  return delete_last(l);
}

/*}}}  */
/*{{{  aterm_list *list_prefix(aterm_list *l) */

aterm_list *list_prefix(aterm_list *l)
{
  aterm_list *result;
  if(t_is_empty(l))
    return l;

  result = get_prefix(l);
  t_unprotect(l);
  return result;
}

/*}}}  */

/*}}}  */
#endif

/*}}}  */
/*{{{  Tbool term_equal(aterm *t1, aterm *t2) */

/* Test for equality on terms. */

#ifndef DONT_NORMALIZE_LISTS
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
#else

static Tbool list_equality(aterm *t1, aterm *t2);

static Tbool equality(aterm *t1, aterm *t2)
{
  if(t_equal(t1,t2))
    return Ttrue;

  if(t_type(t1) != t_type(t2))
    return Tfalse;

  switch(t_type(t1)) {
    case trm_appl: return (t_appl_sym(t1) == t_appl_sym(t2)) &&
		          equality(t_appl_args(t1), t_appl_args(t2));
    case trm_list: return list_equality(t1, t2);

    default: return t_equal(t1, t2);
  }
  return 0;
}

static aterm *get_list_element(aterm_list *l, int idx)
{
  while(1) {
    aterm *head = t_list_first(l);
    l = t_list_next(l);
    if(t_is_list(head)) {
      int size = get_list_length(head);
      if(idx >= size) {
	idx -= size;
      } else {
	l = head;
      }
    } else {
      if(idx-- == 0)
	return head;
    }
  }
}

static Tbool list_equality(aterm *t1, aterm *t2)
{
  int i, size = get_list_length(t1);
  if(get_list_length(t2) != size)
    return Tfalse;

  for(i=0; i<size; i++) {
    if(!equality(get_list_element(t1, i), get_list_element(t2, i)))
      return Tfalse;
  }
  return Ttrue;
}

/*
static Tbool list_equality(aterm *t1, aterm *t2)
{
  int idx = 0;

  do {
    count = fill_store(idx, 0, MAX_STORE/2, t1);
    if(fill_store(idx, MAX_STORE/2, MAX_STORE, t2) != count)
      return Tfalse;

    for(i=0; i<count; i++) {
      if(!equality(term_store[i], term_store[MAX_STORE/2+i]))
	return Tfalse;
    }

    idx += count;
  } while(count == MAX_STORE/2);
  return Ttrue;
}
*/

extern Tbool term_equal(aterm *t1, aterm *t2)
{
  Tbool result = equality(t1, t2);
  t_unprotect(t1);
  t_unprotect(t2);
  return result;
}
#endif

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

#ifndef DONT_NORMALIZE_LISTS
Tbool is_single_element(aterm_list *l)
{

  if(t_is_list(l) && (!t_is_empty(l) && t_is_empty(t_list_next(l)))) {
    t_unprotect(l);
    return Ttrue;
  }
  t_unprotect(l);
  return Tfalse;
}
#else
Tbool is_single_element(aterm_list *l)
{
  aterm *tail;
  Tbool result;
  if(!t_is_list(l) || t_is_empty(l)) {
    t_unprotect(l);
    return Tfalse;
  } 
  tail = list_tail(l);
  result = t_is_empty(tail);
  t_unprotect(tail);
  return result;
}
#endif

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
/*{{{  aterm *tuple(aterm *t0,aterm *t1) */

aterm *tuple(aterm *t0,aterm *t1)
{
  aterm *result, *args2;
  aterm_list *args = TbuildList(w, t1, t_empty(w));
  t_unprotect(t1);
  args2 = TbuildList(w, t0, args);
  t_unprotect(args);
  t_unprotect(t0);
  result = TbuildAppl(w, tuplesym, args2);
  t_unprotect(args2);
  return result;
}

aterm *tuple2(aterm *t0,aterm *t1)
{
  aterm *result, *args2;
  aterm_list *args = TbuildList(w, t1, t_empty(w));
  t_unprotect(t1);
  args2 = TbuildList(w, t0, args);
  t_unprotect(args);
  t_unprotect(t0);
  result = TbuildAppl(w, tuple2sym, args2);
  t_unprotect(args2);
  return result;
}

aterm *tuple3(aterm *t0,aterm *t1,aterm *t2)
{
  aterm *result, *args2, *args3;
  aterm_list *args = TbuildList(w, t2, t_empty(w));
  t_unprotect(t2);
  args2 = TbuildList(w, t1, args);
  t_unprotect(args);
  t_unprotect(t1);
  args3 = TbuildList(w, t0, args2);
  t_unprotect(args2);
  t_unprotect(t0);
  result = TbuildAppl(w, tuple3sym, args3);
  t_unprotect(args3);
  return result;
}
/*}}}  */

/*{{{  Make normal forms */

/*{{{  aterm *make_nf0(asymbol *s) */

aterm *make_nf0(asymbol *s)
{
  aterm *result = TbuildAppl(w, s, t_empty(w));
  return result;
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
  aterm *result, *args2;
  aterm_list *args = TbuildList(w, t1, t_empty(w));
  t_unprotect(t1);
  args2 = TbuildList(w, t0, args);
  t_unprotect(args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args2);
  t_unprotect(args2);
  return result;
}

/*}}}  */
/*{{{  aterm *make_nf3(asymbol *s, aterm *t0, aterm *t1, aterm *t2) */

aterm *make_nf3(asymbol *s, aterm *t0, aterm *t1, aterm *t2)
{
  aterm *result, *args2;
  aterm_list *args = TbuildList(w, t2, t_empty(w));
  t_unprotect(t2);
  args2 = TbuildList(w, t1, args);
  t_unprotect(args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args2);
  t_unprotect(args2);
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
  aterm *result, *args2;
  aterm_list *args = TbuildList(w, t3, t_empty(w));
  t_unprotect(t3);
  args2 = TbuildList(w, t2, args);
  t_unprotect(args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args2);
  t_unprotect(args2);
  t_unprotect(t1);
  args2 = TbuildList(w, t0, args);
  t_unprotect(args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args2);
  t_unprotect(args2);
  return result;
}

/*}}}  */
/*{{{  make_nf5 */

aterm *make_nf5(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4)
{
  aterm *result, *args2;
  aterm_list *args = TbuildList(w, t4, t_empty(w));
  t_unprotect(t4);
  args2 = TbuildList(w, t3, args);
  t_unprotect(args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args2);
  t_unprotect(args2);
  t_unprotect(t2);
  args2 = TbuildList(w, t1, args);
  t_unprotect(args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args2);
  t_unprotect(args2);
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
  aterm *result, *args2;
  aterm_list *args = TbuildList(w, t5, t_empty(w));
  t_unprotect(t5);
  args2 = TbuildList(w, t4, args);
  t_unprotect(args);
  t_unprotect(t4);
  args = TbuildList(w, t3, args2);
  t_unprotect(args2);
  t_unprotect(t3);
  args2 = TbuildList(w, t2, args);
  t_unprotect(args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args2);
  t_unprotect(args2);
  t_unprotect(t1);
  args2 = TbuildList(w, t0, args);
  t_unprotect(args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args2);
  t_unprotect(args2);
  return result;
}

/*}}}  */
/*{{{  make_nf7 */

aterm *make_nf7(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4, aterm *t5, aterm *t6)
{
  aterm *result, *args2;
  aterm_list *args = TbuildList(w, t6, t_empty(w));
  t_unprotect(t6);
  args2 = TbuildList(w, t5, args);
  t_unprotect(args);
  t_unprotect(t5);
  args = TbuildList(w, t4, args2);
  t_unprotect(args2);
  t_unprotect(t4);
  args2 = TbuildList(w, t3, args);
  t_unprotect(args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args2);
  t_unprotect(args2);
  t_unprotect(t2);
  args2 = TbuildList(w, t1, args);
  t_unprotect(args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args2);
  t_unprotect(args2);
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
  aterm *result, *args2;
  aterm_list *
  args = TbuildList(w, t7, t_empty(w));
  t_unprotect(t7);
  args2 = TbuildList(w, t6, args);
  t_unprotect(args);
  t_unprotect(t6);
  args = TbuildList(w, t5, args2);
  t_unprotect(args2);
  t_unprotect(t5);
  args2 = TbuildList(w, t4, args);
  t_unprotect(args);
  t_unprotect(t4);
  args = TbuildList(w, t3, args2);
  t_unprotect(args2);
  t_unprotect(t3);
  args2 = TbuildList(w, t2, args);
  t_unprotect(args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args2);
  t_unprotect(args2);
  t_unprotect(t1);
  args2 = TbuildList(w, t0, args);
  t_unprotect(args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args2);
  t_unprotect(args2);
  return result;
}

/*}}}  */
/*{{{  make_nf9 */

aterm *make_nf9(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8)
{
  aterm *result, *args2;
  aterm_list *
  args = TbuildList(w, t8, t_empty(w));
  t_unprotect(t8);
  args2 = TbuildList(w, t7, args);
  t_unprotect(args);
  t_unprotect(t7);
  args = TbuildList(w, t6, args2);
  t_unprotect(args2);
  t_unprotect(t6);
  args2 = TbuildList(w, t5, args);
  t_unprotect(args);
  t_unprotect(t5);
  args = TbuildList(w, t4, args2);
  t_unprotect(args2);
  t_unprotect(t4);
  args2 = TbuildList(w, t3, args);
  t_unprotect(args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args2);
  t_unprotect(args2);
  t_unprotect(t2);
  args2 = TbuildList(w, t1, args);
  t_unprotect(args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args2);
  t_unprotect(args2);
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
  aterm *result, *args2;
  aterm_list *
  args = TbuildList(w, t9, t_empty(w));
  t_unprotect(t9);
  args2 = TbuildList(w, t8, args);
  t_unprotect(args);
  t_unprotect(t8);
  args = TbuildList(w, t7, args2);
  t_unprotect(args2);
  t_unprotect(t7);
  args2 = TbuildList(w, t6, args);
  t_unprotect(args);
  t_unprotect(t6);
  args = TbuildList(w, t5, args2);
  t_unprotect(args2);
  t_unprotect(t5);
  args2 = TbuildList(w, t4, args);
  t_unprotect(args);
  t_unprotect(t4);
  args = TbuildList(w, t3, args2);
  t_unprotect(args2);
  t_unprotect(t3);
  args2 = TbuildList(w, t2, args);
  t_unprotect(args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args2);
  t_unprotect(args2);
  t_unprotect(t1);
  args2 = TbuildList(w, t0, args);
  t_unprotect(args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args2);
  t_unprotect(args2);
  return result;
}

/*}}}  */
/*{{{  make_nf11 */

aterm *make_nf11(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8,
		 aterm *t9, aterm *t10)
{
  aterm *result, *args2;
  aterm_list *
  args = TbuildList(w, t10, t_empty(w));
  t_unprotect(t10);
  args2 = TbuildList(w, t9, args);
  t_unprotect(args);
  t_unprotect(t9);
  args = TbuildList(w, t8, args2);
  t_unprotect(args2);
  t_unprotect(t8);
  args2 = TbuildList(w, t7, args);
  t_unprotect(args);
  t_unprotect(t7);
  args = TbuildList(w, t6, args2);
  t_unprotect(args2);
  t_unprotect(t6);
  args2 = TbuildList(w, t5, args);
  t_unprotect(args);
  t_unprotect(t5);
  args = TbuildList(w, t4, args2);
  t_unprotect(args2);
  t_unprotect(t4);
  args2 = TbuildList(w, t3, args);
  t_unprotect(args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args2);
  t_unprotect(args2);
  t_unprotect(t2);
  args2 = TbuildList(w, t1, args);
  t_unprotect(args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args2);
  t_unprotect(args2);
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
  aterm *result, *args2;
  aterm_list *
  args = TbuildList(w, t11, t_empty(w));
  t_unprotect(t11);
  args2 = TbuildList(w, t10, args);
  t_unprotect(args);
  t_unprotect(t10);
  args = TbuildList(w, t9, args2);
  t_unprotect(args2);
  t_unprotect(t9);
  args2 = TbuildList(w, t8, args);
  t_unprotect(args);
  t_unprotect(t8);
  args = TbuildList(w, t7, args2);
  t_unprotect(args2);
  t_unprotect(t7);
  args2 = TbuildList(w, t6, args);
  t_unprotect(args);
  t_unprotect(t6);
  args = TbuildList(w, t5, args2);
  t_unprotect(args2);
  t_unprotect(t5);
  args2 = TbuildList(w, t4, args);
  t_unprotect(args);
  t_unprotect(t4);
  args = TbuildList(w, t3, args2);
  t_unprotect(args2);
  t_unprotect(t3);
  args2 = TbuildList(w, t2, args);
  t_unprotect(args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args2);
  t_unprotect(args2);
  t_unprotect(t1);
  args2 = TbuildList(w, t0, args);
  t_unprotect(args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args2);
  t_unprotect(args2);
  return result;
}

/*}}}  */
/*{{{  make_nf13 */

aterm *make_nf13(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8,
		 aterm *t9, aterm *t10, aterm *t11, aterm *t12)
{
  aterm *result, *args2;
  aterm_list *
  args = TbuildList(w, t12, t_empty(w));
  t_unprotect(t12);
  args2 = TbuildList(w, t11, args);
  t_unprotect(args);
  t_unprotect(t11);
  args = TbuildList(w, t10, args2);
  t_unprotect(args2);
  t_unprotect(t10);
  args2 = TbuildList(w, t9, args);
  t_unprotect(args);
  t_unprotect(t9);
  args = TbuildList(w, t8, args2);
  t_unprotect(args2);
  t_unprotect(t8);
  args2 = TbuildList(w, t7, args);
  t_unprotect(args);
  t_unprotect(t7);
  args = TbuildList(w, t6, args2);
  t_unprotect(args2);
  t_unprotect(t6);
  args2 = TbuildList(w, t5, args);
  t_unprotect(args);
  t_unprotect(t5);
  args = TbuildList(w, t4, args2);
  t_unprotect(args2);
  t_unprotect(t4);
  args2 = TbuildList(w, t3, args);
  t_unprotect(args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args2);
  t_unprotect(args2);
  t_unprotect(t2);
  args2 = TbuildList(w, t1, args);
  t_unprotect(args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args2);
  t_unprotect(args2);
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
  aterm *result, *args2;
  aterm_list *
  args = TbuildList(w, t13, t_empty(w));
  t_unprotect(t13);
  args2 = TbuildList(w, t12, args);
  t_unprotect(args);
  t_unprotect(t12);
  args = TbuildList(w, t11, args2);
  t_unprotect(args2);
  t_unprotect(t11);
  args2 = TbuildList(w, t10, args);
  t_unprotect(args);
  t_unprotect(t10);
  args = TbuildList(w, t9, args2);
  t_unprotect(args2);
  t_unprotect(t9);
  args2 = TbuildList(w, t8, args);
  t_unprotect(args);
  t_unprotect(t8);
  args = TbuildList(w, t7, args2);
  t_unprotect(args2);
  t_unprotect(t7);
  args2 = TbuildList(w, t6, args);
  t_unprotect(args);
  t_unprotect(t6);
  args = TbuildList(w, t5, args2);
  t_unprotect(args2);
  t_unprotect(t5);
  args2 = TbuildList(w, t4, args);
  t_unprotect(args);
  t_unprotect(t4);
  args = TbuildList(w, t3, args2);
  t_unprotect(args2);
  t_unprotect(t3);
  args2 = TbuildList(w, t2, args);
  t_unprotect(args);
  t_unprotect(t2);
  args = TbuildList(w, t1, args2);
  t_unprotect(args2);
  t_unprotect(t1);
  args2 = TbuildList(w, t0, args);
  t_unprotect(args);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args2);
  t_unprotect(args2);
  return result;
}

/*}}}  */
/*{{{  make_nf15 */

aterm *make_nf15(asymbol *s, aterm *t0, aterm *t1, aterm *t2, aterm *t3,
		aterm *t4, aterm *t5, aterm *t6, aterm *t7, aterm *t8,
		 aterm *t9, aterm *t10, aterm *t11, aterm *t12, aterm *t13,
		 aterm *t14)
{
  aterm *result, *args2;
  aterm_list *
  args = TbuildList(w, t14, t_empty(w));
  t_unprotect(t14);
  args2 = TbuildList(w, t13, args);
  t_unprotect(args);
  t_unprotect(t13);
  args = TbuildList(w, t12, args2); 
  t_unprotect(args2);
  t_unprotect(t12);
  args2 = TbuildList(w, t11, args);
  t_unprotect(args);
  t_unprotect(t11);
  args = TbuildList(w, t10, args2);
  t_unprotect(args2);
  t_unprotect(t10);
  args2 = TbuildList(w, t9, args);
  t_unprotect(args);
  t_unprotect(t9);
  args = TbuildList(w, t8, args2);
  t_unprotect(args2);
  t_unprotect(t8);
  args2 = TbuildList(w, t7, args);
  t_unprotect(args);
  t_unprotect(t7);
  args = TbuildList(w, t6, args2);
  t_unprotect(args2);
  t_unprotect(t6);
  args2 = TbuildList(w, t5, args);
  t_unprotect(args);
  t_unprotect(t5);
  args = TbuildList(w, t4, args2);
  t_unprotect(args2);
  t_unprotect(t4);
  args2 = TbuildList(w, t3, args);
  t_unprotect(args);
  t_unprotect(t3);
  args = TbuildList(w, t2, args2);
  t_unprotect(args2);
  t_unprotect(t2);
  args2 = TbuildList(w, t1, args);
  t_unprotect(args);
  t_unprotect(t1);
  args = TbuildList(w, t0, args2);
  t_unprotect(args2);
  t_unprotect(t0);
  result = TbuildAppl(w, s, args);
  t_unprotect(args);
  return result;
}

/*}}}  */

/*}}}  */
/*{{{  Converting back to readable C-code */
void ToC_code(aterm *asfix, FILE *file)
{
  int c, prev = ' ';
  int instring = 0;
  int escaped = 0;
  int firststring = 1;
  static char *buf = NULL;
  char *bp;
  static int bufsize = -1;

  int size3 = 0, size2, size = AFsourceSize(asfix);
  if(size > bufsize) {
    if(buf)
      free(buf);
    buf = (char *)malloc(size+1);
    if(!buf)
      fatal_error("out of memory in PrettyPrint");
    bufsize = size;
  }
  size2 = AFsource(asfix, buf);
  if(size2 != size)
    fatal_error("sizes don't match: %d != %d in PrettyPrint", size, size2);

  bp = buf;
  do {
    size3++;
    c = *bp++;
  } while(c != '#');

  while(c != '"') {
    fputc(c, file);
    size3++;
    c = *bp++;
  }
  fputc(' ', file);
  fputc(c, file);
  size3++;
  c = *bp++;

   while(c != '"') {
    fputc(c, file);
    size3++;
    c = *bp++;
  }
  fputs("\"\n", file);

  do {
    size3++;
    c = *bp++;
    if(c >= 0) {
      if(!instring && c == '\n')
        c = ' ';
      if(!(instring || prev != ' ' || c != ' '))
        ;
      else
        fputc(c, file);
      prev = c;
    }
    if(instring) {
      if(!escaped && c == '"') {
        instring = 0;
        if(firststring) {
          firststring = 0;
          fputc('\n', file);
        }
      }
      escaped = 0;
      if(!escaped && c == '\\')
        escaped = 1;
    } else {
      if(c == '"')
        instring = 1;
      else {
        if(c == ';' || c == '}' || c == '{') {
          fputc('\n', file);
          prev = ' ';
        }
      }
    }
  } while(size3 != size);
}
/*}}}  */
