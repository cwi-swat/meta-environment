#include <assert.h>

#include "ksdf2table.h"
#include "characters.h"
#include "pgen-symbol.h"
#include "first.h"

extern int MAX_PROD;

extern ATerm *nr_prod_table;

static int max_first_sets = 0;
static CC_Class **first_sets = NULL;

#if 0
/*{{{  static void printFirstSets() */

static void printFirstSets()
{
  int i;

  for (i=0; i<max_first_sets; i++) {
    if (first_sets[i] != NULL) {
      ATwarning("first_set of %t (%d): %t\n",
		getSymbol(i), i, CC_ClassToTerm(first_sets[i]));
    }
  }
}

/*}}}  */
#endif

/*{{{  ATbool contains_epsilon(ATermList set)  */

ATbool contains_epsilon(ATermList set)
{
  if(ATindexOf(set,empty_set,0) >= 0)
    return ATtrue;
  else
    return ATfalse;
}

/*}}}  */
/*{{{  ATermList remove_epsilon(ATermList set)  */

ATermList remove_epsilon(ATermList set)
{
  return ATremoveElement(set, empty_set);
}

/*}}}  */

/*{{{  void first(CC_Class *cc, ATermList symbols, CC_Class *firstset) */

static void first(CC_Class *cc, ATermList symbols)
{
  ATerm symbol;
  CC_Class *set;

  while(!ATisEmpty(symbols)) {
    symbol = ATgetFirst(symbols);
    symbols = ATgetNext(symbols);

    set = get_first_set(symbol, ATtrue);
    CC_union(cc, set, cc);
    if (!CC_containsChar(set, CC_EPSILON)) {
      CC_removeChar(cc, CC_EPSILON);
      return;
    }
  }
  CC_addChar(cc, CC_EPSILON);
}

/*}}}  */
/*{{{  CC_Class *first_no_epsilon(ATermList symbols) */

CC_Class *first_no_epsilon(ATermList symbols)
{
  CC_Class *result;

  result = CC_makeClassEmpty();
  first(result, symbols);
  CC_removeChar(result, CC_EPSILON);

  return result;
}

/*}}}  */

/*{{{  void calc_first_table() */

/**
  * Calculation of the first set of the grammar
  **/

void calc_first_table()
{
  int ip;
  ATermList symbols;
  CC_Class *firstset, copy;
  ATerm symbol;
  ATerm prod;
  ATbool changed = ATtrue;

  while(changed) {
    changed = ATfalse;
    for(ip=MIN_PROD;ip<MAX_PROD;ip++) {
      prod = nr_prod_table[ip];

      assert(IS_PROD(prod));
      symbols = GET_LIST_ARG(prod,0);
      symbol  = GET_ARG(prod,1);
      firstset = get_first_set(symbol, ATfalse);

      if(firstset) {
	CC_copy(firstset, &copy);
	first(firstset, symbols);
	CC_union(firstset, &copy, firstset);

	changed |= !CC_isEqual(&copy, firstset);
      }
      else {
	firstset = get_first_set(symbol, ATtrue);
	first(firstset, symbols);
	changed = ATtrue;
      }
    }
  }
}

/*}}}  */
/*{{{  void init_prod_first(ATerm prod) */
/**
 * Initialize the symbol table in order to be
 * able to perform the first calculation.
 **/


void init_prod_first(ATerm prod)
{
  ATermList symbols;
  ATerm symbol;
  CC_Class *set, *newset;

  symbols = GET_LIST_ARG(prod, 0);
  while(!ATisEmpty(symbols)) {
    symbol = ATgetFirst(symbols);

    set = get_first_set(symbol, ATtrue);
    newset = CC_getCharClass(symbol);

    /*assert(CC_isEmpty(set) || CC_isEqual(set, newset));*/

    CC_copy(newset, set);

    symbols = ATgetNext(symbols);
  }
}

/*}}}  */

/*{{{  void init_first() */

void init_first()
{
  max_first_sets = 512;
  first_sets = (CC_Class **)calloc(max_first_sets, sizeof(CC_Class *));
  if (!first_sets) {
    ATerror("out of memory in CC_init (2) %d\n", max_first_sets);
  }
}

/*}}}  */
/*{{{  void destroy_first() */

void destroy_first()
{
  int i;

  for (i=0; i<max_first_sets; i++) {
    if (first_sets[i] != NULL) {
      CC_free(first_sets[i]);
    }
  }

  free(first_sets);
  first_sets = NULL;
  max_first_sets = 0;
}

/*}}}  */

/*{{{  CC_Class *get_first_set(ATerm symbol) */

CC_Class *get_first_set(ATerm symbol, ATbool create)
{
  long index;
  int old_size;

  index = internSymbol(symbol);
  if (index >= max_first_sets) {
    old_size = max_first_sets;
    max_first_sets *= 2;
    first_sets = (CC_Class **)realloc(first_sets, max_first_sets*sizeof(CC_Class *));
    if (!first_sets) {
      ATerror("out of memory in get_first_set %d\n", max_first_sets);
    }
    memset(&first_sets[old_size], 0, old_size*sizeof(CC_Class *));
  }
  if (create && first_sets[index] == NULL) {
    first_sets[index] = CC_makeClassEmpty();
  }

  return first_sets[index];
}

/*}}}  */

