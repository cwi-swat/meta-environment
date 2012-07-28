#include <assert.h>

#include "characters.h"
#include "pgen-symbol.h"
#include "parseTable-data.h"
#include "first.h"

static int max_first_sets = 0;
static CC_Class **first_sets = NULL;

#if 0

static void printFirstSets() {
  int i;

  for (i=0; i<max_first_sets; i++) {
    if (first_sets[i] != NULL) {
      ATwarning("first_set of %t (%d): %t\n",
		getSymbol(i), i, CC_ClassToTerm(first_sets[i]));
    }
  }
}

#endif


ATbool contains_epsilon(ATermList set) {
  PT_Symbol epsilon = PT_makeSymbolEmpty();
  
  if(ATindexOf(set,(ATerm)epsilon,0) >= 0)
    return ATtrue;
  else
    return ATfalse;
}

ATermList remove_epsilon(ATermList set) {
  PT_Symbol epsilon = PT_makeSymbolEmpty();
  return ATremoveElement(set, (ATerm)epsilon);
}

static void first(CC_Class *cc, PT_Symbols symbols) {
  PT_Symbol symbol;
  CC_Class *set;

  while(!PT_isSymbolsEmpty(symbols)) {
    symbol = PT_getSymbolsHead(symbols);
    symbols = PT_getSymbolsTail(symbols);

    set = get_first_set(symbol, ATtrue);
    CC_union(cc, set, cc);
    if (!CC_containsChar(set, CC_EPSILON)) {
      CC_removeChar(cc, CC_EPSILON);
      return;
    }
  }
  CC_addChar(cc, CC_EPSILON);
}

CC_Class *first_no_epsilon(PT_Symbols symbols) {
  CC_Class *result;

  result = CC_makeClassEmpty();
  first(result, symbols);
  CC_removeChar(result, CC_EPSILON);

  return result;
}

/* For each production, get its first set. */
void calc_first_table() {
  CC_Class *firstset;
  CC_Class  copy;
  PT_Symbol  symbol;
  PT_Symbols symbols;
  PT_Production prod;
  ATbool changed = ATtrue;
  int ip;

  while(changed) {
    changed = ATfalse;
    for(ip = MIN_PROD_NUM; ip < PGEN_getMaxProductionNumber(); ip++) {
      prod = PGEN_getProductionOfProductionNumber(ip);

      assert(PT_isValidProduction(prod));
      symbols = PT_getProductionLhs(prod);
      symbol  = PT_getProductionRhs(prod);
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

/* For each symbol on the left hand side of the given production rule, if the 
 * symbol is a non-terminal initialise the symbol's first set to empty, 
 * otherwise if the symbol is a terminal or the end-of-string symbol, 
 * initialise the symbol's first set to the symbol. */ 
void init_prod_first(PT_Production prod) {
  PT_Symbols symbols;
  PT_Symbol symbol;
  CC_Class *set; 
  CC_Class *newset;

  symbols = PT_getProductionLhs(prod);
  while(!PT_isSymbolsEmpty(symbols)) {
    symbol = PT_getSymbolsHead(symbols);

    set = get_first_set(symbol, ATtrue);
    newset = CC_getCharClass(symbol);
    
    /*assert(CC_isEmpty(set) || CC_isEqual(set, newset));*/

    CC_copy(newset, set);
    symbols = PT_getSymbolsTail(symbols);
  }
}

void init_first() {
  max_first_sets = 512;
  first_sets = (CC_Class **)calloc(max_first_sets, sizeof(CC_Class *));
  if (!first_sets) {
    ATerror("out of memory in CC_init (2) %d\n", max_first_sets);
  }
}

void destroy_first() {
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

CC_Class *get_first_set(PT_Symbol symbol, ATbool create) {
  long index;
  int old_size;

  /* Associate a unique integer with a symbol. */
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

