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

  for(i=strlen(s)-1; i>=0; i--) {
    result = ATinsert(result,make_char((int)s[i]));
  }
  return result;
}
/*}}}  */
/*{{{  static Aterm call(Symbol sym, ATermList args) */

static ATerm call(Symbol sym, ATermList args)
{
  funcptr func = lookup_func_given_sym(sym);
  ATerm result = NULL;
  ATerm arg[32];

  assert(func);
  switch(ATgetLength(args)) {
    case 0: result = (*func)();
      break;
    case 1: 
	arg[0] = ATgetFirst(args);
	result = (*func)(arg[0]);
      	break;

    case 2: 
	arg[0] = ATgetFirst(args);
	arg[1] = ATelementAt(args,1);
	result = (*func)(arg[0],arg[1]);
        break;
    case 3: 
	arg[0] = ATgetFirst(args);
	arg[1] = ATelementAt(args, 1);
	arg[2] = ATelementAt(args, 2);
        result = (*func)(arg[0],arg[1],arg[2]);
        break;
    case 4: 
	arg[0] = ATgetFirst(args);
	arg[1] = ATelementAt(args, 1);
	arg[2] = ATelementAt(args, 2);
	arg[3] = ATelementAt(args, 3);
        result = (*func)(arg[0],arg[1],arg[2],arg[3]);
        break;
    case 5: 
	arg[0] = ATgetFirst(args);
	arg[1] = ATelementAt(args, 1);
	arg[2] = ATelementAt(args, 2);
	arg[3] = ATelementAt(args, 3);
	arg[4] = ATelementAt(args, 4);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],arg[4]);
        break;
    case 6: 
	arg[0] = ATgetFirst(args);
	arg[1] = ATelementAt(args, 1);
	arg[2] = ATelementAt(args, 2);
	arg[3] = ATelementAt(args, 3);
	arg[4] = ATelementAt(args, 4);
	arg[5] = ATelementAt(args, 5);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5]);
        break;
    case 7:  
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6]);
        break;
    case 8:   
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7]);
        break;
    case 9:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8]);
        break;
    case 10:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9]);
        break;
    case 11:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10]);
        break;
    case 12:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11]);
        break;
    case 13:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12]);
        break;
    case 14:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13]);
        break;
    case 15:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14]);
        break;
    case 16:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15]);
        break;;
    case 17:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16]);
        break;
    case 18:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        arg[17] = ATelementAt(args, 17);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16],arg[17]);
        break;
    case 19:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        arg[17] = ATelementAt(args, 17);
        arg[18] = ATelementAt(args, 18);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16],arg[17],arg[18]);
        break;
    case 20:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        arg[17] = ATelementAt(args, 17);
        arg[18] = ATelementAt(args, 18);
        arg[19] = ATelementAt(args, 19);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16],arg[17],arg[18],arg[19]);
        break;
    case 21:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        arg[17] = ATelementAt(args, 17);
        arg[18] = ATelementAt(args, 18);
        arg[19] = ATelementAt(args, 19);
        arg[20] = ATelementAt(args, 20);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16],arg[17],arg[18],arg[19],
                         arg[20]);
        break;
    case 22:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        arg[17] = ATelementAt(args, 17);
        arg[18] = ATelementAt(args, 18);
        arg[19] = ATelementAt(args, 19);
        arg[20] = ATelementAt(args, 20);
        arg[21] = ATelementAt(args, 21);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16],arg[17],arg[18],arg[19],
                         arg[20],arg[21]);
        break;
    case 23:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        arg[17] = ATelementAt(args, 17);
        arg[18] = ATelementAt(args, 18);
        arg[19] = ATelementAt(args, 19);
        arg[20] = ATelementAt(args, 20);
        arg[21] = ATelementAt(args, 21);
        arg[22] = ATelementAt(args, 22);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16],arg[17],arg[18],arg[19],
                         arg[20],arg[21],arg[22]);
        break;
    case 24:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        arg[17] = ATelementAt(args, 17);
        arg[18] = ATelementAt(args, 18);
        arg[19] = ATelementAt(args, 19);
        arg[20] = ATelementAt(args, 20);
        arg[21] = ATelementAt(args, 21);
        arg[22] = ATelementAt(args, 22);
        arg[23] = ATelementAt(args, 23);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16],arg[17],arg[18],arg[19],
                         arg[20],arg[21],arg[22],arg[23]);
        break;
    case 25:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        arg[17] = ATelementAt(args, 17);
        arg[18] = ATelementAt(args, 18);
        arg[19] = ATelementAt(args, 19);
        arg[20] = ATelementAt(args, 20);
        arg[21] = ATelementAt(args, 21);
        arg[22] = ATelementAt(args, 22);
        arg[23] = ATelementAt(args, 23);
        arg[24] = ATelementAt(args, 24);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16],arg[17],arg[18],arg[19],
                         arg[20],arg[21],arg[22],arg[23],
                         arg[24]);
        break;
    case 26:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        arg[17] = ATelementAt(args, 17);
        arg[18] = ATelementAt(args, 18);
        arg[19] = ATelementAt(args, 19);
        arg[20] = ATelementAt(args, 20);
        arg[21] = ATelementAt(args, 21);
        arg[22] = ATelementAt(args, 22);
        arg[23] = ATelementAt(args, 23);
        arg[24] = ATelementAt(args, 24);
        arg[25] = ATelementAt(args, 25);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16],arg[17],arg[18],arg[19],
                         arg[20],arg[21],arg[22],arg[23],
                         arg[24],arg[25]);
        break;
  case 27:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        arg[17] = ATelementAt(args, 17);
        arg[18] = ATelementAt(args, 18);
        arg[19] = ATelementAt(args, 19);
        arg[20] = ATelementAt(args, 20);
        arg[21] = ATelementAt(args, 21);
        arg[22] = ATelementAt(args, 22);
        arg[23] = ATelementAt(args, 23);
        arg[24] = ATelementAt(args, 24);
        arg[25] = ATelementAt(args, 25);
        arg[26] = ATelementAt(args, 26);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16],arg[17],arg[18],arg[19],
                         arg[20],arg[21],arg[22],arg[23],
                         arg[24],arg[25],arg[26]);
        break;
    case 28:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        arg[17] = ATelementAt(args, 17);
        arg[18] = ATelementAt(args, 18);
        arg[19] = ATelementAt(args, 19);
        arg[20] = ATelementAt(args, 20);
        arg[21] = ATelementAt(args, 21);
        arg[22] = ATelementAt(args, 22);
        arg[23] = ATelementAt(args, 23);
        arg[24] = ATelementAt(args, 24);
        arg[25] = ATelementAt(args, 25);
        arg[26] = ATelementAt(args, 26);
        arg[27] = ATelementAt(args, 27);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16],arg[17],arg[18],arg[19],
                         arg[20],arg[21],arg[22],arg[23],
                         arg[24],arg[25],arg[26],arg[27]);
        break;
    case 29:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        arg[17] = ATelementAt(args, 17);
        arg[18] = ATelementAt(args, 18);
        arg[19] = ATelementAt(args, 19);
        arg[20] = ATelementAt(args, 20);
        arg[21] = ATelementAt(args, 21);
        arg[22] = ATelementAt(args, 22);
        arg[23] = ATelementAt(args, 23);
        arg[24] = ATelementAt(args, 24);
        arg[25] = ATelementAt(args, 25);
        arg[26] = ATelementAt(args, 26);
        arg[27] = ATelementAt(args, 27);
        arg[28] = ATelementAt(args, 28);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16],arg[17],arg[18],arg[19],
                         arg[20],arg[21],arg[22],arg[23],
                         arg[24],arg[25],arg[26],arg[27],
                         arg[28]);
        break;
    case 30:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        arg[17] = ATelementAt(args, 17);
        arg[18] = ATelementAt(args, 18);
        arg[19] = ATelementAt(args, 19);
        arg[20] = ATelementAt(args, 20);
        arg[21] = ATelementAt(args, 21);
        arg[22] = ATelementAt(args, 22);
        arg[23] = ATelementAt(args, 23);
        arg[24] = ATelementAt(args, 24);
        arg[25] = ATelementAt(args, 25);
        arg[26] = ATelementAt(args, 26);
        arg[27] = ATelementAt(args, 27);
        arg[28] = ATelementAt(args, 28);
        arg[29] = ATelementAt(args, 29);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16],arg[17],arg[18],arg[19],
                         arg[20],arg[21],arg[22],arg[23],
                         arg[24],arg[25],arg[26],arg[27],
                         arg[28],arg[29]);
        break;
    case 31:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        arg[17] = ATelementAt(args, 17);
        arg[18] = ATelementAt(args, 18);
        arg[19] = ATelementAt(args, 19);
        arg[20] = ATelementAt(args, 20);
        arg[21] = ATelementAt(args, 21);
        arg[22] = ATelementAt(args, 22);
        arg[23] = ATelementAt(args, 23);
        arg[24] = ATelementAt(args, 24);
        arg[25] = ATelementAt(args, 25);
        arg[26] = ATelementAt(args, 26);
        arg[27] = ATelementAt(args, 27);
        arg[28] = ATelementAt(args, 28);
        arg[29] = ATelementAt(args, 29);
        arg[30] = ATelementAt(args, 30);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16],arg[17],arg[18],arg[19],
                         arg[20],arg[21],arg[22],arg[23],
                         arg[24],arg[25],arg[26],arg[27],
                         arg[28],arg[29],arg[30]);
        break;
    case 32:
        arg[0] = ATgetFirst(args);
        arg[1] = ATelementAt(args, 1);
        arg[2] = ATelementAt(args, 2);
        arg[3] = ATelementAt(args, 3);
        arg[4] = ATelementAt(args, 4);
        arg[5] = ATelementAt(args, 5);
        arg[6] = ATelementAt(args, 6);
        arg[7] = ATelementAt(args, 7);
        arg[8] = ATelementAt(args, 8);
        arg[9] = ATelementAt(args, 9);
        arg[10] = ATelementAt(args, 10);
        arg[11] = ATelementAt(args, 11);
        arg[12] = ATelementAt(args, 12);
        arg[13] = ATelementAt(args, 13);
        arg[14] = ATelementAt(args, 14);
        arg[15] = ATelementAt(args, 15);
        arg[16] = ATelementAt(args, 16);
        arg[17] = ATelementAt(args, 17);
        arg[18] = ATelementAt(args, 18);
        arg[19] = ATelementAt(args, 19);
        arg[20] = ATelementAt(args, 20);
        arg[21] = ATelementAt(args, 21);
        arg[22] = ATelementAt(args, 22);
        arg[23] = ATelementAt(args, 23);
        arg[24] = ATelementAt(args, 24);
        arg[25] = ATelementAt(args, 25);
        arg[26] = ATelementAt(args, 26);
        arg[27] = ATelementAt(args, 27);
        arg[28] = ATelementAt(args, 28);
        arg[29] = ATelementAt(args, 29);
        arg[30] = ATelementAt(args, 30);
        arg[31] = ATelementAt(args, 31);
        result = (*func)(arg[0],arg[1],arg[2],arg[3],
                         arg[4],arg[5],arg[6],arg[7],
                         arg[8],arg[9],arg[10],arg[11],
                         arg[12],arg[13],arg[14],arg[15],
                         arg[16],arg[17],arg[18],arg[19],
                         arg[20],arg[21],arg[22],arg[23],
                         arg[24],arg[25],arg[26],arg[27],
                         arg[28],arg[29],arg[30],arg[31]);
        break;
    default:
      ATerror("too many arguments: %d\n", ATgetLength(args));
  }
  return result;
}
/*}}}  */

/**
  * Build a list from type and args.
  */

/*{{{  static ATerm innermost( ATerm t) */

ATerm innermost(ATerm t)
{
	int i;

  if(ATgetType(t) == AT_APPL) {
    ATermAppl appl = (ATermAppl)t;
    Symbol sym = ATgetSymbol(appl);
		ATermList list = ATempty;
		for(i=ATgetArity(sym); i>=0; --i)
			list = ATinsert(list, innermost(ATgetArgument(appl, i)));

    return call(sym, list);
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
