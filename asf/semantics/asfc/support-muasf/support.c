/**
  * Library support for muASF2C compiled modules.
  *
  * Pieter Olivier
  * Thu Aug 14 11:36:34 MET DST 1997
  */

/*{{{  includes */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>

/*#include <atb-tool.h>*/
#include <AsFix.h>
#include <AsFix2src.h>
#include <aterm2.h>

#include "support.h"
#include "deprecated.h"
#include "aterm-macs.h"

/*}}}  */
/*{{{  types */

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
/*{{{  globals */

static ATerm term_store[MAX_STORE];

static int nr_entries = 0;
static int table_size = 0;
static bucket **prod_table = NULL;
static bucket **sym_table = NULL;

ATerm c_true = NULL;
ATerm c_false = NULL;
ATerm char_table[256] = {NULL};

/*}}}  */

/*{{{  void c_rehash(int newsize) */

/**
  * Create a new (larger?) hash table and rehash all old the entries.
  */

void c_rehash(int newsize)
{
  int i; 
  unsigned int hnr;
  bucket **newprodtable, **newsymtable, *b, *next;

  /* Allocate new hash tables */
  newprodtable = (bucket **)malloc(sizeof(bucket *)*newsize);
  newsymtable = (bucket **)malloc(sizeof(bucket *)*newsize);
  if(!newsymtable || !newprodtable)
    ATerror("out of memory in c_rehash(%d)", newsize);

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
	/*hnr = b->prod->hnr % newsize;*/
        hnr = (((int) &(b->prod))>>2);
        hnr %= newsize;
	b->next_prod = newprodtable[hnr];
	newprodtable[hnr] = b;
	b = next;
      }
      b = sym_table[i];
      while(b) {
	next = b->next_sym;
	/*hnr = b->sym->hnr % newsize;*/
        hnr = (((int) &(b->sym))>>2);
        hnr %= newsize;
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
/*{{{  void register_prod(ATerm prod, funcptr func, Symbol sym) */

void register_prod(ATerm prod, funcptr func, Symbol sym)
{
  unsigned int hnr;
  bucket *b;

  if((nr_entries*100)/table_size > MAX_LOAD)
    c_rehash(table_size*2);

  /*hnr = prod->hnr % table_size;*/
  hnr = (((int) prod)>>2);
  hnr %= table_size;

  /* Find out if this function has already been registered */
  b = prod_table[hnr];
  while(b && !ATisEqual(b->prod, prod))
    b = b->next_prod;
  if(b)
    return;
    /*ATerror("duplicate function registered: %t\n", prod);*/

  /* Add a new bucket */
  b = malloc(sizeof(bucket));
  if(!b)
    ATerror("out of memory in register.\n");
  b->next_prod = prod_table[hnr];
  prod_table[hnr] = b;

  /* Add it to the sym table also. */
  /*hnr = sym->hnr % table_size;*/
  hnr = (((int) sym)>>2);
  hnr %= table_size;
  b->next_sym = sym_table[hnr];
  sym_table[hnr] = b;

  b->prod = prod;
  ATprotect(&b->prod);
  b->func = func;
  b->sym  = sym;
}
/*}}}  */
/*{{{  funcptr lookup_func(ATerm prod) */

funcptr lookup_func(ATerm prod)
{
  bucket *b;
  /* int hnr = prod->hnr % table_size;*/
  unsigned int hnr = (((int) prod)>>2);
  hnr %= table_size;
  b = prod_table[hnr];

  while(b) {
    if(ATisEqual(b->prod, prod))
      return b->func;
    b = b->next_prod;
  }
  ATerror("unknown function: %t\n", prod);
  return NULL; /* silence the compiler, we never get here. */
}
/*}}}  */
/*{{{  Symbol lookup_sym(ATerm prod) */

Symbol lookup_sym(ATerm prod)
{
  bucket *b;
  /* int hnr = prod->hnr % table_size;*/
  unsigned int hnr = (((int) prod)>>2);
  hnr %= table_size;

  b = prod_table[hnr];

  while(b) {
    if(ATisEqual(b->prod, prod))
      return b->sym;
    b = b->next_prod;
  }
  ATerror("Unknown function: %t\n", prod);
  return 0; /* silence the compiler, we never get here. */
}

/*}}}  */
/*{{{  ATerm lookup_prod(Symbol sym) */

ATerm lookup_prod(Symbol sym)
{
  bucket *b;
  /* int hnr = prod->hnr % table_size;*/
  unsigned int hnr = (((int) sym)>>2);
  hnr %= table_size;

  b = sym_table[hnr];

  while(b) {
    if(b->sym == sym)
      return b->prod;
    b = b->next_sym;
  }
  ATerror("unknown symbol: %s\n", ATgetName(sym));
  return (ATerm) NULL; /* silence the compiler, we never get here. */
}
/*}}}  */
/*{{{  ATerm lookup_prod(Symbol sym) */

funcptr lookup_func_given_sym(Symbol sym)
{
  bucket *b;
  /* int hnr = prod->hnr % table_size;*/
  unsigned int hnr = (((int) sym)>>2);
  hnr %= table_size;

  b = sym_table[hnr];

  while(b) {
    if(b->sym == sym)
      return b->func;
    b = b->next_sym;
  }
  ATerror("unknown symbol: %s\n", ATgetName(sym));
  return NULL; /* silence the compiler, we never get here. */
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

  for(i=strlen(s)-1; i>=0; i--)
    result = ATinsert(result,make_char((int)s[i]));

  return result;
}
/*}}}  */

/**
  * Build a list from type and args.
  */

/*{{{  static ATerm innermost( ATerm t) */

ATerm innermost(ATerm t)
{
  if(ATgetType(t) == AT_APPL) {
    ATermAppl appl = (ATermAppl)t;
    Symbol sym = ATgetSymbol(appl);
		funcptr func = lookup_func_given_sym(sym);
		switch(ATgetArity(sym)) {
			/*{{{  case 0..33 */
#define A(i)  (innermost(ATgetArgument(appl,(i))))
    case  0: return (*func)();
    case  1: return (*func)(A(0));
    case  2: return (*func)(A(0),A(1));
    case  3: return (*func)(A(0),A(1),A(2));
    case  4: return (*func)(A(0),A(1),A(2),A(3));
    case  5: return (*func)(A(0),A(1),A(2),A(3),A(4));
    case  6: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5));
    case  7: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6));
    case  8: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7));
    case  9: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8));
    case 10: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9));
    case 11: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10));
    case 12: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11));
    case 13: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12));
    case 14: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13));
    case 15: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14));
    case 16: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15));
    case 17: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16));
    case 18: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17));
    case 19: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17),A(18));
    case 20: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17),A(18),A(19));
    case 21: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17),A(18),A(19),A(20));
    case 22: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17),A(18),A(19),A(20),A(21));
    case 23: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17),A(18),A(19),A(20),A(21),A(22));
    case 24: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17),A(18),A(19),A(20),A(21),A(22),A(23));
    case 25: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17),A(18),A(19),A(20),A(21),A(22),A(23),A(24));
    case 26: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17),A(18),A(19),A(20),A(21),A(22),A(23),A(24),
														A(25));
    case 27: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17),A(18),A(19),A(20),A(21),A(22),A(23),A(24),
														A(25),A(26));
    case 28: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17),A(18),A(19),A(20),A(21),A(22),A(23),A(24),
														A(25),A(26),A(27));
    case 29: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17),A(18),A(19),A(20),A(21),A(22),A(23),A(24),
														A(25),A(26),A(27),A(28));
    case 30: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17),A(18),A(19),A(20),A(21),A(22),A(23),A(24),
														A(25),A(26),A(27),A(28),A(29));
    case 31: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17),A(18),A(19),A(20),A(21),A(22),A(23),A(24),
														A(25),A(26),A(27),A(28),A(29),A(30));
    case 32: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17),A(18),A(19),A(20),A(21),A(22),A(23),A(24),
														A(25),A(26),A(27),A(28),A(29),A(30),A(31));
    case 33: return (*func)(A(0),A(1),A(2),A(3),A(4),A(5),A(6),A(7),A(8),
														A(9),A(10),A(11),A(12),A(13),A(14),A(15),A(16),
														A(17),A(18),A(19),A(20),A(21),A(22),A(23),A(24),
														A(25),A(26),A(27),A(28),A(29),A(30),A(31),A(32));
#undef A
/*}}}  */
			default:
				ATerror("innermost: too many arguments: %d\n", ATgetArity(sym));
		}
  }
	return NULL;
}

/*}}}  */

/*{{{  void init_patterns() */

void init_patterns()
{
  int i;

  ATprotect(&c_true);
  ATprotect(&c_false);
  c_true = ATparse("true");
  c_false = ATparse("false");

  /* make characters */
  for(i=0; i<256; i++) {
    ATprotect(&char_table[i]);
    char_table[i] = (ATerm) ATmakeInt(i);
  }
}
/*}}}  */
/*{{{  ATerm slice(ATerm l1, ATerm l2) */

int slice_length(ATerm l1, ATerm l2)
{
  int size = 0;
  ATermList old = (ATermList)l1;
  while(!ATisEqual(l1,l2)) {
    assert(l1);
    if(ATisEmpty((ATermList)l1))
      ATfprintf(stderr, "sorry, %t not in %t\n", l2, old);
    size++;
    l1 = (ATerm)ATgetNext((ATermList)l1);
  }
  return size;
}

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
    result = ATinsert(result, ATgetFirst((ATermList)l1));
    l1 = (ATerm)ATgetNext((ATermList)l1); 
  }
	result = ATreverse(result);

  for(i=len-1; i>=0; i--) {
    result = ATinsert(result, term_store[i]);
  }
 
  return (ATerm)result;
}

/*}}}  */
