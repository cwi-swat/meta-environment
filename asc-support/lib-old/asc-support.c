/**
  * Library support for AsFix2C compiled modules.
  *
  * Mark van den Brand, Pieter Olivier, Jurgen Vinju
  * $Id$
  */

/*{{{  includes */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>

#include <AsFix.h>
#include <AsFix2src.h>
#include <aterm2.h>

#include <deprecated.h>
#include <aterm-macs.h>

#include "asc-support.h"

#ifndef streq
#  define streq(s,t)    (!(strcmp(s,t)))
#endif

/*}}}  */
/*{{{  types needed for registering and resolving
 *      MuASF function names. 
 */

typedef struct bucket
{
  struct bucket *next_prod;
  struct bucket *next_sym;
  ATerm prod;
  funcptr func;
  Symbol sym;
} bucket;

/*}}}  */
/*{{{  defines */

#define MAX_STORE 10240

/*}}}  */
/*{{{  global variables */

/* This term_store is used for temporary storage of
 * list elements, e.g. used in slice.
 */
static ATerm term_store[MAX_STORE];

/* Data structures for storing the MuASF names and the
 * corresponding AsFix names.
 */
static int nr_entries = 0;
static int table_size = 0;
static bucket **prod_table = NULL;
static bucket **sym_table = NULL;

/* Name speaks for itself, a temporary buffer to store
 * strings.
 */
static char conversionbuf[1024];

/* Variables used for profiling. */
unsigned int rewrite_steps = 0;

#ifdef MEMO_PROFILING
ATermTable prof_table = NULL;
Symbol record_sym = -1;
#endif

/* This can be removed after regression testing (15-2-2000)!
ATerm c_true = NULL;
ATerm c_false = NULL;
*/

/* A table to convert characters to ATermInts. 
 */
ATerm char_table[256] = {NULL};

/* This is a temporary hack and should be improved in the
 * near future. This table is used to store the priority
 * relations of context-free functions in order to restore
 * brackets after reducing.
 */
ATermTable priority_table;

/* These quoted symbols are used in combination with
 * outermost evaluation! So, to enlighten Jurgen
 * "if" Bool "then" S "else" S "fi" -> S {delay2, delay3}
 * Symbols are quoted to prevent innermost reduction of
 * functions. Also symbols related to list (matching)
 * have to be quoted: make_listsym, concsym and conssym.
 */
Symbol sym_quote0;
Symbol sym_quote1;
Symbol sym_quote2;
Symbol sym_quote3;
Symbol sym_quote4;
Symbol sym_quote5;
Symbol sym_quote6;
Symbol sym_quote7;
Symbol make_listsym;

/* These symbols are used in combination with lists
 * "conssym" should be removed in the near future! 
 */
Symbol concsym;
Symbol conssym;

/* These patterns should be declared in a separate 
 * AsFix library.
 */
static ATerm pattern_asfix_term               = NULL;
static ATerm pattern_asfix_appl               = NULL;
static ATerm pattern_asfix_prod               = NULL;
static ATerm pattern_asfix_list               = NULL;
static ATerm pattern_asfix_lex                = NULL;
static ATerm pattern_asfix_l                  = NULL;
static ATerm pattern_asfix_ql                 = NULL;
static ATerm pattern_asfix_ws                 = NULL;
static ATerm pattern_asfix_sort               = NULL;
static ATerm pattern_listtype                 = NULL;
static ATerm pattern_listtype_sep             = NULL;
static ATerm pattern_char                     = NULL;
static ATerm pattern_lexical_constructor      = NULL;
static ATerm pattern_term_lexical_constructor = NULL;
static ATerm pattern_caller_id                = NULL;
static ATerm ws                               = NULL;
static ATerm spws                             = NULL;

/* Pieter? Why this symbol is used is for the moment unknown!
 */
static Symbol symbol_asfix_lex;

/* Function symbols associated with the priority handling.
 */
AFun afun_non_assoc_prio = 0;
AFun afun_gtr_prio = 0;
AFun afun_left_prio = 0;
AFun afun_right_prio = 0;
AFun afun_assoc_prio = 0;

/* Declarations of static functions. */
static ATermList innermost_list(ATermList l);
static funcptr basic_lookup_func(ATerm prod);
static ATerm call(ATerm prod, ATermList args);
static ATerm make_list_type(ATerm type, ATermList args);
static ATermList innermost_list(ATermList l);
static ATerm term_to_asfix(ATerm t, ATerm sort);
static ATerm make_asfix_list(ATermList l, char *sort);
static ATerm make_asfix_list_sep(ATermList l, char *sort, char *sep);
static int get_list_length(ATermList chars);
static ATermList terms_to_asfix(ATermList a, ATermAppl t, ATerm sort);
static int slice_length(ATerm l1, ATerm l2);

/*}}}  */
/*{{{  void c_rehash(int newsize) */

/**
  * Create a new (larger?) hash table for register and 
  * resolve of context-free function names and rehash all 
  * old the entries.
  */

void c_rehash(int newsize)
{
  int i; 
  unsigned int hnr;
  bucket **newprodtable, **newsymtable, *b, *next;

  /* Allocate new hash tables */
  /* Pieter? Why not use calloc instead of malloc, so we can skip
   * explicit initialization to NULL ?
   */
  newprodtable = (bucket **)malloc(sizeof(bucket *)*newsize);
  newsymtable = (bucket **)malloc(sizeof(bucket *)*newsize);
  if(!newsymtable || !newprodtable)
    ATabort("out of memory in c_rehash(%d)", newsize);

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
	hnr = (((int) &(b->prod))>>2);
        hnr %= newsize;
	b->next_prod = newprodtable[hnr];
	newprodtable[hnr] = b;
	b = next;
      }
      b = sym_table[i];
      while(b) {
	next = b->next_sym;
	hnr = (((int) &(b->sym))>>2);
        hnr %= newsize;
	b->next_sym = newsymtable[hnr];
	newsymtable[hnr] = b;
	b = next;
      }
    }
  }

  if(prod_table) {
    free(prod_table);
    free(sym_table);
  }
  prod_table = newprodtable;
  sym_table = newsymtable;
  table_size = newsize;
}

/*}}}  */
/*{{{  unsigned in calc_hash(ATerm prod) */

#ifdef NO_SHARING
/**
  * Calculate hash function of a term.
  */

unsigned int calc_hash(ATerm t)
{
  unsigned int hnr = 0;

  switch(ATgetType(t)) {
  case AT_APPL:
    {
      ATermAppl appl = (ATermAppl)t;
      AFun sym = ATgetAFun(appl);
      int i, arity = ATgetArity(sym);
      hnr = AT_hashSymbol(ATgetName(sym), arity);

      for(i=0; i<arity; i++) {
	/* Pieter? constante in je code? */
	hnr = hnr * 3001 + calc_hash(ATgetArgument(appl, i));
      }
    }
    break;

  case AT_INT:
    hnr = ATgetInt((ATermInt)t);
    break;

  case AT_LIST:
    {
      ATermList list = (ATermList)t;
      hnr = 123;
      while(!ATisEmpty(list)) {
	/* Pieter? constante in je code? */
	hnr = hnr * 4507 + calc_hash(ATgetFirst(list));
	list = ATgetNext(list);
      }
    }
    break;
  }

  return hnr;
}
#endif

/*}}}  */

/*{{{  void register_prod(ATerm prod, funcptr func, Symbol sym) */

void register_prod(ATerm prod, funcptr func, Symbol sym)
{
  unsigned int hnr; /* hash number */
  bucket *b; /* single bucket */

  /* Heuristics for deciding when to rehash */
  if((nr_entries*100)/table_size > MAX_LOAD)
    c_rehash(table_size*2);

#ifdef NO_SHARING
  hnr = calc_hash(prod);
  /* Pieter? Why is this mod not included in calc_hash? */
  hnr %= table_size;
#else
  /* Pieter? Create macros for simple hash operations? */
  hnr = (((int) prod)>>2);
  hnr %= table_size;
#endif

  /* Find out if this function has already been registered */
  b = prod_table[hnr];
  while(b && !ATisEqual(b->prod, prod))
    b = b->next_prod;

  /* if already registered, we are done */
  if(b)
    return;

  /* Else we should add a new bucket */
  b = malloc(sizeof(bucket));
  if(!b)
    ATabort("out of memory in register.\n");
  b->next_prod = prod_table[hnr];
  prod_table[hnr] = b;

  /* Add it to the sym table also. */
  hnr = (((int) sym)>>2);
  hnr %= table_size;
  b->next_sym = sym_table[hnr];
  sym_table[hnr] = b;

  /* The prod field of the bucket is protected against 
   * the gc.
   */
  b->prod = prod;
  ATprotect(&b->prod);
  b->func = func;
  b->sym  = sym;
}

/*}}}  */

/* The following functions are used to convert from symbols
 * to function pointers or from prods to function pointers.
 * And from symbols to prods. This functionality is used when
 * converting back a normal form to AsFix.
 */

/*{{{  funcptr lookup_func_given_sym(Symbol sym)) */

funcptr lookup_func_given_sym(Symbol sym)
{
  bucket *b;
  /* Pieter? Create macros for simple hash operations? */
  unsigned int hnr = (((int) sym)>>2);
  hnr %= table_size;

  b = sym_table[hnr];

  while(b) {
    if(b->sym == sym)
      return b->func;
    b = b->next_sym;
  }
  ATabort("unknown symbol: %s\n", ATgetName(sym));
  return (funcptr) NULL; /* silence the compiler, we never get here. */
}
/*}}}  */
/*{{{  static funcptr basic_lookup_func(ATerm prod) */

/* Changed this function to static 15-02-2000, await regression test */
static funcptr basic_lookup_func(ATerm prod)
{
  bucket *b;

#ifdef NO_SHARING
  unsigned int hnr = calc_hash(prod);
  hnr %= table_size;
#else
  unsigned int hnr = (((int) prod)>>2);
  hnr %= table_size;
#endif
  
  b = prod_table[hnr];

  while(b) {
    if(ATisEqual(b->prod, prod))
      return b->func;
    b = b->next_prod;
  } 

  return (funcptr) NULL;
}
/*}}}  */
/*{{{  funcptr lookup_func(ATerm prod) */

funcptr lookup_func(ATerm prod)
{
  funcptr f = basic_lookup_func(prod);
  if(!f) {
    ATabort("unknown function: %t\n", prod);
    return (funcptr) NULL; /* silence the compiler, we never get here. */
  }
  else return f;
}
/*}}}  */
/*{{{  Symbol lookup_sym(ATerm prod) */

Symbol lookup_sym(ATerm prod)
{
  bucket *b;

#ifdef NO_SHARING
  unsigned int hnr = calc_hash(prod);
  hnr %= table_size;
#else
  unsigned int hnr = (((int) prod)>>2);
  hnr %= table_size;
#endif
  
  b = prod_table[hnr];

  while(b) {
    if(ATisEqual(b->prod, prod))
      return b->sym;
    b = b->next_prod;
  }
  ATabort("Unknown function: %t\n", prod);
  return (Symbol) 0; /* silence the compiler, we never get here. */
}

/*}}}  */
/*{{{  ATerm lookup_prod(Symbol sym) */

ATerm lookup_prod(Symbol sym)
{
  bucket *b;
  unsigned int hnr = (((int) sym)>>2);
  hnr %= table_size;

  b = sym_table[hnr];

  while(b) {
    if(b->sym == sym)
      return b->prod;
    b = b->next_sym;
  }
  ATabort("unknown symbol: %s\n", ATgetName(sym));
  return (ATerm) NULL; /* silence the compiler, we never get here. */
}
/*}}}  */
/*{{{  ATermList string2list(char *s) */

/**
  * Translate a string to a list of integers (characters)
  */

ATermList string2list(char *s)
{
  int i;
  ATermList result = ATempty;

  for(i=strlen(s)-1; i>=0; i--) {
    result = ATinsert(result,make_char((int)s[i]));
  }

  return result;
}
/*}}}  */
/*{{{  static Aterm call(ATerm prod, ATermList args) */

/* This function is used in innermost to call a c function for
 * a given AsFix production. Note that the arguments are in normal form
 * because of the innermost reduction strategy. Apparently there is
 * an upper limit on the number of arguments of a production (32)!
 *
 * The functionality of this function is to convert the argument list in
 * ATermList form to a c function call and to lookup the actual funcptr.
 */

static ATerm call(ATerm prod, ATermList args)
{
  funcptr func = lookup_func(prod);
  ATermList list;
  /* Pieter? Please explain/define this arbitrary constant */
  ATerm arg[33];

  int idx = 0;
  list = args;
  while(!ATisEmpty(list)) {
    arg[idx++] = ATgetFirst(list);
    list = ATgetNext(list);
  }

  /* Pieter? Can't this be written more concisely using a va_list? 
   */
  switch(ATgetLength(args)) {
  case  0: return (*func)();
  case  1: return (*func)(arg[0]);
  case  2: return (*func)(arg[0],arg[1]);
  case  3: return (*func)(arg[0],arg[1],arg[2]);
  case  4: return (*func)(arg[0],arg[1],arg[2],arg[3]);
  case  5: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4]);
  case  6: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5]);
  case  7: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6]);
  case  8: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7]);
  case  9: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8]);
  case 10: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9]);
  case 11: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10]);
  case 12: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11]);
  case 13: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12]);
  case 14: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13]);
  case 15: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14]);
  case 16: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15]);
  case 17: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16]);
  case 18: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17]);
  case 19: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18]);
  case 20: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19]);
  case 21: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20]);
  case 22: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21]);
  case 23: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22]);
  case 24: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23]);
  case 25: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24]);
  case 26: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25]);
  case 27: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25],arg[26]);
  case 28: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25],arg[26],arg[27]);
  case 29: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25],arg[26],arg[27],arg[28]);
  case 30: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25],arg[26],arg[27],arg[28],arg[29]);
  case 31: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11]
			  ,arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25],arg[26],arg[27],arg[28],arg[29],
			  arg[30]);
  case 32: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25],arg[26],arg[27],arg[28],arg[29],
			  arg[30],arg[31]);
  case 33: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25],arg[26],arg[27],arg[28],arg[29],
			  arg[30],arg[31],arg[32]);
  default:
    ATabort("too many arguments: %d\n", ATgetLength(args));
  }
  return NULL;
}

/*}}}  */
/*{{{  static ATerm make_list_type(ATerm type, ATerm args) */

/* This function is also used by innermost. It maps the AsFix representation
 * of a list to the C runtime representation of lists. The arguments are
 * already in normal form due to the innermost reduction strategy. A list
 * can never occur as an outermost function symbol (it's a builtin), so
 * no 'call' is needed.
 * 
 */

static ATerm make_list_type(ATerm type, ATermList args)
{
  ATerm listsort, listsep;
  ATermList iterargs;
  char *sort, *sep;
  char symbol_buf[256];
  Symbol sym;

  /* The list has no separator. */
  if(ATmatchTerm(type, pattern_iter, &listsort, NULL, NULL)) {
    ATmatchTerm(listsort, pattern_asfix_sort, &sort);
    sprintf(symbol_buf, "listtype(sort(\"%s\"))", sort);
    sym = ATmakeSymbol(symbol_buf, 1, ATtrue);
    
    return (ATerm) ATmakeApplList(sym, ATmakeList1((ATerm)args));

  } /* Or the list has a separator defined. */
  else if(ATmatchTerm(type, pattern_itersep, &iterargs)) {
    listsort = ATelementAt(iterargs, 2);
    listsep  = ATelementAt(iterargs, 4);
    ATmatchTerm(listsort, pattern_asfix_sort, &sort);
    ATmatchTerm(listsep, pattern_asfix_ql, &sep);
    sprintf(symbol_buf, "listtype(sort(\"%s\"),ql(\"%s\"))", sort, sep);
    sym = ATmakeSymbol(symbol_buf, 1, ATtrue);
    
    return (ATerm) ATmakeApplList(sym, ATmakeList1((ATerm)args));
  }
  else {
    ATabort("illegal list type: %t\n", type);
    return (ATerm) NULL; /* silence the compiler */
  }
}
/*}}}  */

/*{{{  ATerm innermost( ATerm t) */

/* This function is the core of the innermost reduction strategy. Given the
 * AsFIx representation of a term to be reduced the c functions for rewriting
 * are called in an innermost manner.  Here we use the "call-by-value" mechanism
 * of C to implement the innermost strategy.
 */

ATerm innermost(ATerm t)
{
  ATerm prod, sort, list, result = NULL, listterm;
  ATermList newargs, args, lexlist;
  funcptr f;
  char *lex;

  if(ATgetType(t) == AT_APPL) {
    ATermAppl appl = (ATermAppl)t;
    Symbol sym = ATgetSymbol(appl);
    
    /* Either it is a function appl. */
    if(sym == symbol_asfix_appl) {
      prod = ATgetArgument(appl, 0);
      args = (ATermList)ATgetArgument(appl, 2);

      /* Bracket functions have no runtime semantics */
      if(AFisBracketCfFunc(prod))
      	result = innermost(ATelementAt(args, 2));
      else
        result = call(prod, innermost_list(args));

    } /* Or it is a lexical constructor */ 
    else if(sym == symbol_asfix_lex) {
      lex = ATgetName(ATgetSymbol((ATermAppl)ATgetArgument(appl, 0)));
      sort = ATgetArgument(appl, 1);

      lexlist = string2list(lex);
      listterm = ATmake("[\"listtype(sort(\\\"CHAR\\\"))\"([<list>])]", lexlist);

      /* This conversion is needed to be able to access the equations with a 
       * lexical constructor function as outmost function symbol in the left hand side.
       *
       * The following code takes care of the distinction between "module-asfix" 
       * and "term-asfix" in case of "module-asfix" the lexical is converted
       * into a caller function otherwise it is a term_caller. The difference
       * between these two is the module name: "caller" versus "GEN-LexConsFuncs".
       *
       * If there is no lexical constructor function defined for the "module-asfix"
       * representation then we are processing "term-asfix" and the appropriate
       * lexical constructor function is then called.
       * 
       * Of course this code should be adapted as soon as we do not need to
       * support the "module-asfix" anymore.
       */
      prod = make_caller_prod(sort);
      f = basic_lookup_func(prod);
      if(f) {
        result = call(prod, (ATermList)listterm);
      }
      else {
        prod = make_term_caller_prod(sort);
        result = call(prod, (ATermList)listterm);
      }
    
    } /* Or it is a list, for list no "call" is needed. Only the elements of the
       * list need to be normalized.
       */ 
    else if(sym == symbol_asfix_list) {
      list = ATgetArgument(appl, 0);
      args = (ATermList)ATgetArgument(appl, 2);
      newargs = innermost_list(args);
      result = make_list_type(list, newargs);
    }
  }

  return result;
}

/*}}}  */
/*{{{  static ATerm innermost_list(ATermList l) */

/* The function inntermost_list takes care of the normalization
 * of the elements of a list (of arguments) with respect to the innermost
 * reduction strategy. Here we use the "call-by-value" mechanism
 * of C to implement the innermost strategy.
 */

static ATermList innermost_list(ATermList l)
{
  ATermList result = ATempty;
  int length = ATgetLength(l);
  ATerm el;
 
  /* When a list is shorter than 16 elements, we assume that
     it is not worth it to malloc a buffer. We use ATreverse
     to restore the correct list order. */
  if(length < 16) {
    while(!ATisEmpty(l)) {
      el = innermost(ATgetFirst(l));
      if(el)  
	result = ATinsert(result, el); 
      l = ATgetNext(l);
    }
    return ATreverse(result);
  } else {

    /* Pieter? Why not use the "term_store" instead of allocating
     * and freeing a list each time?
     */
    int idx = 0;
    ATerm *elems = (ATerm *)malloc(sizeof(ATerm)*length);
    if(!elems)
      ATabort("innermost_list: no room for %d elements.\n", length);

    while(!ATisEmpty(l)) {
      elems[idx++] = ATgetFirst(l);
      l = ATgetNext(l);
    }
    assert(idx == length);

    for(--idx; idx>=0; idx--) {
      el = innermost(elems[idx]);
      if(el)
	result = ATinsert(result, el);
    }
		
    free(elems);
    return result;
  }
}

/*}}}  */
/*{{{  ATerm unquote(ATerm t) */

/* Code to unqoute delayed reduction of terms, in order to implement
 * the outermost strategy. This algorithm is known to be 'not optimal'.
 * We refer to the work of Wan Fokkink, Pum Walters and Jasper Kamperman
 * for better implementation ideas.
 */

ATerm unquote(ATerm t)
{
  Symbol s;
  ATerm a0,a1,a2,a3,a4,a5,a6;

  if (ATmatch(t,"quote(<int>)",&s)) {
    funcptr func = lookup_func_given_sym(s);
    return (*func)();
  }
  if (ATmatch(t,"quote(<int>,<term>)",&s,&a0)) {
    if (s == make_listsym)
      return make_list(unquote(a0));
    else {
      funcptr func = lookup_func_given_sym(s);
      return (*func)(unquote(a0));
    }
  }
  if (ATmatch(t,"quote(<int>,<term>,<term>)",&s,&a0,&a1)) {
    if (s == concsym || s == conssym)
      return (ATerm)ATconcat((ATermList)unquote(a0),(ATermList)unquote(a1));
    else {
      funcptr func = lookup_func_given_sym(s);
      return (*func)(unquote(a0),unquote(a1));
    }
  }
  if (ATmatch(t,"quote(<int>,<term>,<term>,<term>)",&s,&a0,&a1,&a2)) {
    funcptr func = lookup_func_given_sym(s);
    return (*func)(unquote(a0),unquote(a1),unquote(a2));
  }
  if (ATmatch(t,"quote(<int>,<term>,<term>,<term>,<term>)",
              &s,&a0,&a1,&a2,&a3)) {
    funcptr func = lookup_func_given_sym(s);
    return (*func)(unquote(a0),unquote(a1),unquote(a2),unquote(a3));
  }
  if (ATmatch(t,"quote(<int>,<term>,<term>,<term>,<term>,<term>)",
              &s,&a0,&a1,&a2,&a3,&a4)) {
    funcptr func = lookup_func_given_sym(s);
    return (*func)(unquote(a0),unquote(a1),unquote(a2),unquote(a3),unquote(a4));
  }
  if (ATmatch(t,"quote(<int>,<term>,<term>,<term>,<term>,<term>,<term>)",
              &s,&a0,&a1,&a2,&a3,&a4,&a5)) {
    funcptr func = lookup_func_given_sym(s);
    return (*func)(unquote(a0),unquote(a1),unquote(a2),unquote(a3),unquote(a4),unquote(a5));
  }
  if (ATmatch(t,"quote(<int>,<term>,<term>,<term>,<term>,<term>,<term>,<term>)",
              &s,&a0,&a1,&a2,&a3,&a4,&a5,&a6)) {
    funcptr func = lookup_func_given_sym(s);
    return (*func)(unquote(a0),unquote(a1),unquote(a2),unquote(a3),unquote(a4),unquote(a5),unquote(a6));
  }

  return t;
}

/*}}}  */

/* The following set of functions take care of the "translation" back from
 * the C/MuASF representation of terms to the AsFix representation.
 * This conversion back is only needed when the normal form is obtained.
 */

/*{{{  static ATerm make_asfix_list( ATermList l, char *sort) */

/* A list is converted back into an AsFix list. 
   Pieter? Why is the term_store not used here? Can this be more efficient?
   The elements of the list are recursively converted to AsFix.
 */

static ATerm make_asfix_list(ATermList l, char *sort)
{
  ATerm listsort = ATmakeTerm(pattern_asfix_sort, sort);
  ATerm iter = ATmakeTerm(pattern_iter_star, listsort, ws);
  ATermList list = ATempty;
  ATerm tmp;

  int i, len = ATgetLength(l);
  if(len > 0) {
    tmp = term_to_asfix(ATelementAt(l, len-1), listsort);
    list = ATinsert(list, tmp);
    for(i = len-2; i >= 0; i--) {
      list = ATinsert(list, ws);
      tmp = term_to_asfix(ATelementAt(l, i), listsort);
      list = ATinsert(list, tmp);
    }
  }
  return ATmakeTerm(pattern_asfix_list, iter, ws, list);  
}

/*}}}  */
/*{{{  static ATerm make_asfix_list_sep( ATermList l, sort,sep) */

/* The same as the previous function, but now with a separated list.
 */

static ATerm make_asfix_list_sep(ATermList l, char *sort, char *sep)
{
  ATerm accolopen = ATmake("l(\"{\")");
  ATerm accolclose = ATmake("l(\"}\")");
  ATerm qsep = ATmake("ql(<str>)", sep);
  ATerm listsep = ATmake("sep(<str>)", sep);
  ATermList list = ATempty;
  ATerm tmp;
  int i;

  ATerm listsort = ATmakeTerm(pattern_asfix_sort, sort);
  ATerm iter = ATmakeTerm(pattern_itersep_star, accolopen, ws, listsort, ws,
			  qsep, ws, accolclose, ws);

  int len = ATgetLength(l);
  if(len > 0) {
    tmp = term_to_asfix(ATelementAt(l, len-1), listsort);
    list = ATinsert(list, tmp);
    for(i = len-2; i >= 0; i--) {
      list = ATinsert(list, spws);
      list = ATinsert(list, listsep);
      list = ATinsert(list, ws);
      tmp = term_to_asfix(ATelementAt(l, i), listsort);
      list = ATinsert(list, tmp);
    }
  }

  return ATmakeTerm(pattern_asfix_list, iter, ws, list);  
}

/*}}}  */
/*{{{  static int get_list_length(ATermList chars) */

/*
 * Calculates the length of a list of characters. 
 * Pieter? According to Jurgen and me this code can
 * be tremendously simplified. We assume that character
 * lists have a nested structure.
 */

static int get_list_length(ATermList chars)
{
  int len = 0;
  while(!ATisEmpty(chars)) {
    ATerm el = ATgetFirst(chars);
    chars = ATgetNext(chars);
    if(t_is_asfix_list(el))
      len += get_list_length((ATermList) el);
    else
      len++;
  }
  return len;
}

/*}}}  */
/*{{{  static char *get_chars_from_list(char *buf, ATermList chars) */

static char *get_chars_from_list(char *buf, ATermList chars)
{
  while(!ATisEmpty(chars)) {
    ATerm el = ATgetFirst(chars);
    chars = ATgetNext(chars);
    if(t_is_asfix_list(el))
      buf = get_chars_from_list(buf,(ATermList) el);
    else
      *buf++ = (char)ATgetInt((ATermInt) el);
  }
  return buf;
}

/*}}}  */
/*{{{  static ATerm make_asfix_lex(ATermList chars, ATerm sort) */

static ATerm make_asfix_lex(ATermList chars, ATerm sort)
{
  char *buf, *end;
  ATerm result;
  int len = get_list_length(chars);

  buf = malloc(len+1);
  if(!buf) {
    ATabort("out of memory trying to allocate lex of %d chars\n", len);
    return NULL;
  }
  end = get_chars_from_list(buf, chars);
  *end = '\0';
  result = ATmakeTerm(pattern_asfix_lex, buf, sort);
  free(buf);
  return result;
}

/*}}}  */

/*{{{  ATerm toasfix(ATerm t, ATerm f, ATerm n) */

/* The top function for converting back
 */

ATerm toasfix(ATerm term, ATerm filename, ATerm termname)
{ 
  return ATmake("term(l(\"term\"),w(\" \"),<term>,w(\"\"),<term>," \
	        "w(\"\\n\"),<term>,w(\"\\n\"),abbreviations([]))",
                filename, termname, term_to_asfix(term, NULL));
}

/*}}}  */

/* A number of function to calculate whether there are conflicts
 * between production rules. If there are conflicts brackets
 * should be added. This functionality should move to a separate
 * tool in the near future.
 */


/* This is commented out because it doesn't work and apparently is 
 *  never used -- Tobias
 */

#ifdef CNF
/*{{{  static ATbool cnf(ATerm prod1, int iptr, int len, ATerm prod2) */

static ATbool cnf(ATerm prod1, int iptr, int len, ATerm prod2)
{
  ATerm priorel, entry;

  if(iptr == 0) {
    if(len > 1) {
      priorel = (ATerm)ATmakeAppl2(afun_right_prio, prod1, prod2);
      entry = ATtableGet(priority_table,priorel);
      if(entry)
        return ATtrue;
      else {
        priorel = (ATerm)ATmakeAppl2(afun_gtr_prio, prod1, prod2);
        entry = ATtableGet(priority_table,priorel);
        if(entry)
          return ATtrue;
        else {
          priorel = (ATerm)ATmakeAppl2(afun_non_assoc_prio, prod1, prod2);
          entry = ATtableGet(priority_table,priorel);
          if(entry)
            return ATtrue;
          else
            return ATfalse;
        }
      }
    }
    else {
      priorel = (ATerm)ATmakeAppl2(afun_gtr_prio, prod1, prod2);
      entry = ATtableGet(priority_table,priorel);
      if(entry)
        return ATtrue;
      else
        return ATfalse;
    }
  }
  else {
    if(len > 1) {
      priorel = (ATerm)ATmakeAppl2(afun_left_prio, prod1, prod2);
      entry = ATtableGet(priority_table,priorel);
      if(entry)
        return ATtrue;
      else {
        priorel = (ATerm)ATmakeAppl2(afun_gtr_prio, prod1, prod2);
        entry = ATtableGet(priority_table,priorel);
        if(entry)
          return ATtrue;
        else {
          priorel = (ATerm)ATmakeAppl2(afun_assoc_prio, prod1, prod2);
          entry = ATtableGet(priority_table,priorel);
          if(entry)
            return ATtrue;
          else {
            priorel = (ATerm)ATmakeAppl2(afun_non_assoc_prio, prod1, prod2);
            entry = ATtableGet(priority_table,priorel);
            if(entry)
              return ATtrue;
            else
              return ATfalse;
          }
        }
      }
    }
    else {
      priorel = (ATerm)ATmakeAppl2(afun_gtr_prio, prod1, prod2);
      entry = ATtableGet(priority_table,priorel);
      if(entry)
        return ATtrue;
      else
        return ATfalse;
    }
  }
}

/*}}}  */
/*{{{  static ATermList conflict_on_args(ATerm prod, ATermList args) */

static ATerm add_brackets(ATerm appl);

static ATermList conflict_on_args(ATerm prod, ATermList args)
{
  ATerm prod2, ws;
  ATermList args2, result = ATempty;
  int i, len = ATgetLength(args);

  for(i=len-1; i>=0; i--) {
    ATerm tmp = ATelementAt(args,i);
    if(ATmatchTerm(tmp, pattern_asfix_appl, &prod2, &ws, &args2)) {
      if(cnf(prod, i, len, prod2))
        tmp = add_brackets(tmp);
      result = ATinsert(result, tmp);
    }
    else {
      result = ATinsert(result, tmp);
    }
  }

  return result;
}
#endif

/*}}}  */
/*{{{  static ATerm term_to_asfix( ATerm t) */

static ATerm term_to_asfix(ATerm t, ATerm sort)
{
  ATerm result = NULL;
  ATerm prod, modname, lexsort;
  ATermList formalargs, actualargs;
  char *listsort, *sep;

  if(ATgetType(t) == AT_APPL) {
    ATermAppl appl;
    Symbol sym;
    prod = lookup_prod(ATgetSymbol((ATermAppl)t));
    if(!prod) {
      ATabort("unknown production symbol: %s\n",
              ATgetName(ATgetSymbol((ATermAppl) t)));
    }
    assert(ATgetType(prod) == AT_APPL);
    appl = (ATermAppl)prod;
    sym = ATgetSymbol(appl);
    
    /* Lexical constructors need not be restored in the resulting
     * AsFix representation of a term. This is the alternative
     * for "module-asfix" the next "elsif" is for "term-asfix".
     */
    if(ATmatchTerm(prod, pattern_lexical_constructor, NULL, &lexsort)) {
      return term_to_asfix(ATgetArgument((ATermAppl) t, 0), lexsort);
    } 
    else if(ATmatchTerm(prod, pattern_term_lexical_constructor, 
                        NULL, &lexsort)) {
      return term_to_asfix(ATgetArgument((ATermAppl) t,0), lexsort);
    } 
    /* An ordinary production rule is processed. 
     */
    else if(sym == symbol_prod) {
      modname = ATgetArgument(appl, 0);
      formalargs = (ATermList)ATgetArgument(appl, 2);
      sort = ATgetArgument(appl, 6);
      actualargs = terms_to_asfix(formalargs, (ATermAppl)t, sort);

      /* This check obsolete! */
      /* 
      if(ATisEqual(modname, pattern_caller_id)) 
        result = ATgetFirst(actualargs);
      else 
      */
        result = ATmakeTerm(pattern_asfix_appl, prod, ws, actualargs);
    } 
    /* We are converting a list without separators back to AsFix.
     * Lists without separators may be lists of characters which need
     * a special treatment.
     */
    else if(ATmatchTerm(prod, pattern_listtype, &listsort)) {
      if(streq(listsort, "CHAR"))
      	result = make_asfix_lex((ATermList)ATgetArgument((ATermAppl) t,0),
                                sort);
      else
      	result = make_asfix_list((ATermList)ATgetArgument((ATermAppl) t,0),
                                 listsort);
    } 
    /* Conversion of list with separators to AsFix.
     */
    else if(ATmatchTerm(prod, pattern_listtype_sep, &listsort, &sep))
      result = make_asfix_list_sep((ATermList) ATgetArgument((ATermAppl) t,0), 
                                   listsort, sep);
    else 
      ATabort("cannot handle production: %t\n", prod);
  }
  else {
    ATabort("cannot handle term type: %t\n", t);
  }

  return result;
}

/*}}}  */
/*{{{  static void deslash(char *str, char *buf) */

/*
 * Remove one level of escaping from a string.
 */

void deslash(char *str, char *buf)
{
  while(*str) {
    switch(*str) {
      case '\\':
        str++;
        switch(*str) {
          case '\\':
            break;
          default:
            *buf++ = '\\';
          }
        *buf++ = *str;
        break;
      default:
        *buf++ = *str;
    }
    str++;
  }
  *buf++ = '\0';
}

/*}}}  */

/*{{{  static ATermList terms_to_asfix( ATermList args, ATermAppl appl, sort) */

/*
 * Translate a list of C/MuASF terms back to AsFix. Starting at the end of
 * the list of terms, each term is transformed into an AsFix term. There
 * are four different alternatives:
 * 1. It is a whitespace.
 * 2. It is a quoted literal, in that case extra backslashes should be removed.
 * 3. It is a literal, which can be inserted without further processing.
 * 4. It is an application, in this case the sort is retrieved from the 
 *    the list of formal arguments and given this sort the term is transformed
 *    into an AsFix term.
 */

static ATermList terms_to_asfix(ATermList args, ATermAppl appl, ATerm sort) 
{
  ATermList result = ATempty;
  int arity = ATgetArity(ATgetSymbol(appl));
  int i, j = arity-1, len = ATgetLength(args);
  ATerm tmp2;
  char *str;

  for(i=len-1; i>=0; i--) {
    ATerm tmp = ATelementAt(args,i);
    if(ATmatchTerm(tmp, pattern_asfix_ws, NULL)) {
      result = ATinsert(result, spws);
    } 
    else if(ATmatchTerm(tmp,pattern_asfix_ql, &str)) {
      deslash(str, conversionbuf);
      tmp2 = ATmakeTerm(pattern_asfix_l, conversionbuf);
      result = ATinsert(result, tmp2);
    }
    else if(ATmatchTerm(tmp, pattern_asfix_l, &str)) {
      result = ATinsert(result, tmp);
    } 
    else {
      ATerm tmp2, tmp3 = ATgetArgument(appl, j);
      tmp2 = term_to_asfix(tmp3, sort);
      result = ATinsert(result, tmp2);
      j--;
    }
  }

  return result;
}
/*}}}  */
/*{{{  void write_memo_profile() */

/*
 * Write memo profiling info to the file "memo.prof"
 */

#ifdef MEMO_PROFILING
void write_memo_profile()
{
  FILE *f = fopen("memo.prof", "w");
  ATermList keys;

  if(!f)
    ATabort("cannot create file 'memo.prof'\n");

  keys = ATtableKeys(prof_table);

  while(!ATisEmpty(keys)) {
    ATerm key = ATgetFirst(keys);
    ATermAppl stats = (ATermAppl)ATtableGet(prof_table, key);
    ATerm asfix = lookup_prod(ATgetSymbol((ATermAppl)key));
		
    ATfprintf(f, "%t ", stats);
    AFsourceToFile(asfix, f);
    ATfprintf(f, "\n");
    keys = ATgetNext(keys);
  }
  ATfprintf(f, "\n");

  fclose(f);
}
#endif

/*}}}  */
/*{{{  void init_patterns() */

/* Part of the initialization code in this function should
 * move to the AsFix library. Constants used during rewriting
 * are initialized here.
 */

void init_patterns()
{
  int i;

  ATprotect(&pattern_asfix_term);
  ATprotect(&pattern_asfix_appl);
  ATprotect(&pattern_asfix_prod);
  ATprotect(&pattern_asfix_list);
  ATprotect(&pattern_asfix_lex);
  ATprotect(&pattern_asfix_l);
  ATprotect(&pattern_asfix_ql);
  ATprotect(&pattern_asfix_ws);
  ATprotect(&pattern_asfix_sort);
  ATprotect(&pattern_listtype);
  ATprotect(&pattern_listtype_sep);
  ATprotect(&pattern_char);
  ATprotect(&pattern_lexical_constructor);
  ATprotect(&pattern_term_lexical_constructor);
  ATprotect(&pattern_caller_id);

  symbol_asfix_lex  = ATmakeSymbol("lex", 2, ATfalse);
  ATprotectSymbol(symbol_asfix_lex);

  pattern_asfix_term = ATparse("term(<term>,<term>,<term>," \
				   "<term>,<term>,<term>,<term>,<term>,<term>)");
  pattern_asfix_appl = ATparse("appl(<term>,<term>,[<list>])");
  pattern_asfix_prod = ATparse("prod(<term>,<term>,<term>,<term>," \
				   "<term>,<term>,<term>,<term>,<term>)");
  pattern_asfix_list = ATparse("list(<term>,<term>,[<list>])");
  pattern_asfix_lex  = ATparse("lex(<str>,<term>)");
  pattern_asfix_l    = ATparse("l(<str>)");
  pattern_asfix_ql   = ATparse("ql(<str>)");
  pattern_asfix_ws   = ATparse("w(<str>)");
  pattern_asfix_sort = ATparse("sort(<str>)");
  pattern_listtype   = ATparse("listtype(sort(<str>))");
  pattern_listtype_sep = ATparse("listtype(sort(<str>),ql(<str>))");
  pattern_char       = ATparse("\"CHAR\"");
  pattern_lexical_constructor = ATparse(
     "prod(id(\"caller\"),w(\"\"),[l(<str>),w(\"\"),ql(\"(\"),w(\"\")," \
     "iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")]," \
     "w(\"\"),l(\"->\"),w(\"\"),<term>,w(\"\"),no-attrs)");
  pattern_term_lexical_constructor = ATparse(
     "prod(id(\"GEN-LexConsFuncs\"),w(\"\"),[ql(<str>),w(\"\"),ql(\"(\")," \
     "w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")]," \
     "w(\"\"),l(\"->\"),w(\"\"),<term>,w(\"\"),no-attrs)");
  pattern_caller_id   = ATparse("id(\"caller\")");

  ATprotect(&ws);
  ws = ATparse("w(\"\\n\")");
  ATprotect(&spws);
  spws = ATparse("w(\" \")");
 
  /* make characters */
  for(i=0; i<256; i++) {
    ATprotect(&char_table[i]);
    char_table[i] = (ATerm) ATmakeInt(i);
  }

  sym_quote0 = ATmakeSymbol("quote", 1, ATfalse);
  ATprotectSymbol(sym_quote0);
  sym_quote1 = ATmakeSymbol("quote", 2, ATfalse);
  ATprotectSymbol(sym_quote1);
  sym_quote2 = ATmakeSymbol("quote", 3, ATfalse);
  ATprotectSymbol(sym_quote2);
  sym_quote3 = ATmakeSymbol("quote", 4, ATfalse);
  ATprotectSymbol(sym_quote3);
  sym_quote4 = ATmakeSymbol("quote", 5, ATfalse);
  ATprotectSymbol(sym_quote4);
  sym_quote5 = ATmakeSymbol("quote", 6, ATfalse);
  ATprotectSymbol(sym_quote5);
  sym_quote6 = ATmakeSymbol("quote", 7, ATfalse);
  ATprotectSymbol(sym_quote6);
  sym_quote7 = ATmakeSymbol("quote", 8, ATfalse);
  ATprotectSymbol(sym_quote7);
  make_listsym = ATmakeSymbol("make_list", 1, ATfalse);
  ATprotectSymbol(make_listsym);
  concsym = ATmakeSymbol("conc", 2, ATfalse);
  ATprotectSymbol(concsym);
  conssym = ATmakeSymbol("cons", 2, ATfalse);
  ATprotectSymbol(conssym);

  afun_left_prio = ATmakeAFun("left-prio", 2, ATfalse);
  ATprotectAFun(afun_left_prio);
  afun_right_prio = ATmakeAFun("right-prio", 2, ATfalse);
  ATprotectAFun(afun_right_prio);
  afun_assoc_prio = ATmakeAFun("assoc-prio", 2, ATfalse);
  ATprotectAFun(afun_assoc_prio);
  afun_non_assoc_prio = ATmakeAFun("non-assoc-prio", 2, ATfalse);
  ATprotectAFun(afun_non_assoc_prio);
  afun_gtr_prio = ATmakeAFun("gtr-prio", 2, ATfalse);
  ATprotectAFun(afun_gtr_prio);

  priority_table = ATtableCreate(100,75);

#ifdef MEMO_PROFILING
  prof_table = ATtableCreate(2048, 80);
  record_sym = ATmakeSymbol("stats", 2, ATfalse);
  ATprotectSymbol(record_sym);

   atexit(write_memo_profile);
#endif

}
/*}}}  */
/*{{{  static int slice_length(ATerm l1, ATerm l2) */

/* Calculates the length of a slice.
 */

static int slice_length(ATerm l1, ATerm l2)
{
  int size = 0;
  ATermList old = (ATermList)l1;

  while(!ATisEqual(l1,l2)) {
    assert(l1);
    if(ATisEmpty((ATermList)l1))
      ATwarning("sorry, %t not in %t\n", l2, old);
    size++;
    l1 = (ATerm)ATgetNext((ATermList)l1);
  }

  return size;
}

/*}}}  */
/*{{{  ATerm slice(ATerm l1, ATerm l2) */

/* Constructs the slice of a list starting at index "l1" and ending at 
 * index "l2". If the slice fits into the term_store a fast way of
 * copying can be used, otherwise the term_store is filled and the
 * rest is processed in a less efficient way.
 */

ATerm slice(ATerm l1, ATerm l2)
{
  ATermList result;
  int i, len;

  if(ATisEmpty((ATermList)l2)) {
    return l1;
  }

  len = slice_length(l1, l2);
  if( MAX_STORE < len )
     len = MAX_STORE;

  for(i=0; i<len; i++) {
    term_store[i] = ATgetFirst((ATermList)l1);
    l1 = (ATerm)ATgetNext((ATermList)l1);
  }

  result = ATempty;

  while(l1 != l2) {
    result = ATappend(result, ATgetFirst((ATermList)l1));
    l1 = (ATerm)ATgetNext((ATermList)l1); 
  }

  for(i=len-1; i>=0; i--) {
    result = ATinsert(result, term_store[i]);
  }
 
  return (ATerm)result;
}

/*}}}  */
/*{{{  ATerm make_list(ATerm t) */

/* Transforms a term into a list. If the term is already a list this
 * list is returned.
 */

ATerm make_list(ATerm t)
{
  if(ATgetType(t) == AT_LIST) 
    return t;
  else
    return  singleton(t);
}

/*}}}  */


