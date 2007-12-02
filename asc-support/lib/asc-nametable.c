/* $Id$ */

#include <stdio.h>
#include <stdlib.h>

#include <aterm2.h>
#include "asc-support-me.h"

/*{{{  declarations */

#define MAX_STORE 10240
#define MAGIC_HASH_CONST_APPL 3001
#define MAGIC_HASH_CONST_LIST 4507

#define HASH_PROD(prod, size) (((unsigned)(((int)(prod))>>2)) % (size))
#define HASH_SYM(sym, size) (((unsigned)(((int)(sym))>>2)) % (size))

typedef struct bucket
{
  struct bucket *next_prod;
  struct bucket *next_sym;
  ATerm prod;
  funcptr func;
  Symbol sym;
} bucket;

/* Data structures for storing the MuASF names and the
 * corresponding AsFix names.
 */
static int nr_entries = 0;
static int table_size = 0;
static bucket **prod_table = NULL;
static bucket **sym_table = NULL;


/*}}}  */

/*{{{  void c_rehash(int newsize) */

/*
 * Create a new (larger?) hash table for register and 
 * resolve of function names and rehash all  old the entries.
 */

void c_rehash(int newsize)
{
  int i; 
  unsigned int hnr;
  bucket **newprodtable, **newsymtable, *b, *next;

  /* Allocate new hash tables */
  newprodtable = (bucket **)calloc(newsize, sizeof(bucket *));
  newsymtable = (bucket **)calloc(newsize, sizeof(bucket *));
  if(!newsymtable || !newprodtable) {
    ATabort("out of memory in c_rehash(%d)", newsize);
  }

  /* Rehash all the old buckets. */
  if(prod_table) {
    for(i=0; i<table_size; i++) {
      b = prod_table[i];
      while(b) {
	next = b->next_prod;
	hnr = HASH_PROD(b->prod, newsize);
	b->next_prod = newprodtable[hnr];
	newprodtable[hnr] = b;
	b = next;
      }
      b = sym_table[i];
      while(b) {
	next = b->next_sym;
	hnr = HASH_SYM(b->sym, newsize);
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

/*{{{  void register_prod(ATerm prod, funcptr func, Symbol sym) */

void register_prod(ATerm prod, funcptr func, Symbol sym)
{
  unsigned int hnr; /* hash number */
  bucket *b; /* single bucket */

  /* Heuristics for deciding when to rehash */
  if((nr_entries*100)/table_size > MAX_LOAD) {
    c_rehash(table_size*2);
  }

  hnr = HASH_PROD(prod, table_size);

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
  hnr = HASH_SYM(sym, table_size);
  b->next_sym = sym_table[hnr];
  sym_table[hnr] = b;

  /* The prod field of the bucket is protected against 
   * the gc.
   */
  b->prod = prod;
  ATprotect((ATerm*)&(b->prod));
  b->func = func;
  b->sym  = sym;
}

/*}}}  */

void unregister_all() {
  free(prod_table);
  prod_table = NULL;
  free(sym_table);
  sym_table = NULL;
}

/*{{{  funcptr lookup_func_given_sym(Symbol sym) */

funcptr lookup_func_given_sym(Symbol sym)
{
  bucket *b;
  unsigned int hnr;

  hnr = HASH_SYM(sym, table_size);

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
/*{{{  funcptr basic_lookup_func(ATerm prod) */

funcptr basic_lookup_func(ATerm prod)
{
  bucket *b;
  unsigned int hnr;

  hnr = HASH_PROD(prod, table_size);

  b = prod_table[hnr];

  while(b) {
    if(ATisEqual(b->prod, prod))
      return b->func;
    b = b->next_prod;
  } 

  return (funcptr) NULL;
}

/*}}}  */
/*{{{  funcptr basic_lookup_func(ATerm prod) */

funcptr prefix_lookup_func(PT_Symbols lhs)
{
  unsigned int hnr;

  for (hnr = 0; hnr < table_size; hnr++) { 
    bucket *b = prod_table[hnr];

    for ( ; b; b = b->next_prod) {
      PT_Production p = (PT_Production) b->prod;

      if (PT_isEqualSymbols(lhs, PT_getProductionLhs(p))) {
	return b->func;
      }
    }
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
  unsigned int hnr;

  hnr = HASH_PROD(prod, table_size);

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
  unsigned int hnr;

  hnr = HASH_SYM(sym, table_size);

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
