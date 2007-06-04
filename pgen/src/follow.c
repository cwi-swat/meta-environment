/* $Id$ */

/**
 * \file
 *
 * Calculates and stores the follow sets of all productions in a grammar. 
 * The original implementation is based on the description given in Eelco 
 * Visser's thesis. 
 */

#include <assert.h>

#include "characters.h"
#include "follow.h"
#include "priorities.h"
#include "first.h"
#include "intset.h"
#include "parseTable-data.h"
#include "atsets.h"

static CC_Class  **follow_table = NULL;
static ATermList *dependencies = NULL; /**< For each production x, it contains 
                                         * the production numbers of the 
                                         * non-terminals that the follow set of 
                                         * x depends on. */
static IS_IntSet *depend_closure = NULL; /**< The dependency_closure is an 
                                           * array of length maxProductionNumber
                                           * of IntSets. 
                                           */
static CC_Class **initial_follow_sets = NULL;

#if 0
static void printFollowTable() {
  int prodid;
  ATerm follow; 
  for (prodid = MIN_PROD_NUM; prodid<PGEN_getMaxProductionNumber(); prodid++) {
    if (follow_table[prodid]) {
      follow = (ATerm)CC_ClassToPTCharRanges(follow_table[prodid]);
    }
    else {
      follow = (ATerm)ATempty;
    }
    
    ATwarning("follow_table[%d] = %t\n", prodid, follow);
  }
}
#endif

CC_Class *PGEN_getFollowSet(int prodNumber) {
  return follow_table[prodNumber];
}

/** 
 * Find the production numbers that the given production depends on. 
 * A production (\alpha \beta -> A) depends on the rightmost non-terminals 
 * \beta that derive epsilon and don't have a priority conflict with the given 
 * production. 
 * 
 * \param prodid 
 * 
 * \return 
 */
static ATermList init_dependency(int prodid) {
  ATerm prodnr; 
  ATerm dep;
  PT_Production prod;
  PT_Symbols symbols;
  ATermList depends; 
  ATermList orgdep;

  prodnr = (ATerm)ATmakeInt(prodid);
  prod = PGEN_getProductionOfProductionNumber(prodid);
  assert(prod);
  symbols = PT_getProductionLhs(prod);
  
  depends = ATempty;
  symbols = PT_reverseSymbols(symbols);
  
  while (!PT_isSymbolsEmpty(symbols)) {
    PT_Symbol elem = PT_getSymbolsHead(symbols);
    symbols = PT_getSymbolsTail(symbols);
    
    orgdep = PGEN_getProductionNumbersOfRhsNonTerminal(elem);
    if (!orgdep) {
      break; /* Symbol is a terminal. */
    }
    
    while (!ATisEmpty(orgdep)) {
      dep = ATgetFirst(orgdep);
      orgdep = ATgetNext(orgdep);
      if (!PGEN_isPriorityConflict(IT_createItemDot(prodid, PT_getSymbolsLength(symbols)), ATgetInt((ATermInt)dep))) {
        depends = ATaddElement(depends, dep);
      }
    }

    /* If the first set of elem does not contain an epsilon then do not 
     * continue finding the dependencies. */
    if (!CC_containsChar(get_first_set(elem, ATtrue), CC_EPSILON)) {
      break; 
    }
  }

  /* Remove yourself if present */
  depends = ATremoveElement(depends, prodnr);

  return depends;
}

/** 
 * Calculate dependencies (which prod's followset depends on which prod's 
 * followset). 
 */
static void init_dependencies() {
  int i;
  int maxProductionNumber = PGEN_getMaxProductionNumber();
  
  dependencies = (ATermList *)calloc(maxProductionNumber, sizeof(ATermList));
  if (!dependencies) {
    ATerror("out of memory!\n");
  }
  ATprotectArray((ATerm *)(dependencies+MIN_PROD_NUM),maxProductionNumber-MIN_PROD_NUM);

  for(i = MIN_PROD_NUM; i < maxProductionNumber; i++) {
    dependencies[i] = init_dependency(i);
  }
}

/** 
 * Find all productions that are dependant on another production. 
 * 
 * \param prodid 
 * \param forward_depends 
 * \param set 
 */
static void find_closure(int prodid, ATermList *forward_depends, IS_IntSet set) {
  ATermList productionsDepenantOnProdId = forward_depends[prodid];

  if (productionsDepenantOnProdId) {
    while (!ATisEmpty(productionsDepenantOnProdId)) {
      int productionDependantOnProdId = ATgetInt((ATermInt)ATgetFirst(productionsDepenantOnProdId));
      if (IS_add(set, productionDependantOnProdId)) {
        find_closure(productionDependantOnProdId, forward_depends, set);
      }
      productionsDepenantOnProdId = ATgetNext(productionsDepenantOnProdId);
    }
  }
}

/** 
 * Calculate the forward dependencies - the productions that are depended on
 * by another production - and then calculate the dependency closure. 
 */
static void closure_dependencies() {
  int maxProductionNumber = PGEN_getMaxProductionNumber();
  int prodid;
  ATermList depends;
  ATermList *forward_depends;
  IS_IntSet set;

  depend_closure = (IS_IntSet *)calloc(maxProductionNumber, sizeof(IS_IntSet));
  if (!depend_closure) {
    ATerror("out of memory!\n");
  }

  forward_depends = (ATermList *)calloc(maxProductionNumber, sizeof(ATermList));
  if (!forward_depends) {
    ATerror("out of memory in closure_dependencies (1)\n");
  }
  ATprotectArray((ATerm *)forward_depends, maxProductionNumber);

  /* For each production (prod), and for each of the productions that it 
   * depends on (fwd_prod) add prod to the fwd_prod. In other words, find the 
   * productions that are depended on by another production. */
  for(prodid = MIN_PROD_NUM; prodid < maxProductionNumber; prodid++) {
    ATerm prod = (ATerm)ATmakeInt(prodid);
    depends = dependencies[prodid];
    while (!ATisEmpty(depends)) {
      int fwd_prod = ATgetInt((ATermInt)ATgetFirst(depends));
      if (forward_depends[fwd_prod] == NULL) {
        forward_depends[fwd_prod] = ATmakeList1(prod);
      } else {
        forward_depends[fwd_prod] = ATinsert(forward_depends[fwd_prod], prod);
      }
      depends = ATgetNext(depends);
    }
  }

  /* For each production */
  for(prodid = MIN_PROD_NUM; prodid < maxProductionNumber; prodid++) {
    set = IS_create(maxProductionNumber);
    IS_add(set, prodid);
    find_closure(prodid, forward_depends, set);
    depend_closure[prodid] = set;
  }

  ATunprotectArray((ATerm *)forward_depends);
  free(forward_depends);
}

/** 
 * For a production of the form (B /alpha -> A) calculate the follow set of B, 
 * by getting the first set of /alpha, minus the epsilon. However, if there is 
 * an epsilon in the first set of /alpha then the follow set of A should be 
 * added to the follow set of B. It does not appear to do this here! Is this
 * case handled by the dependencies? 
 * 
 * \param prodid 
 */
static void init_follow_set(int prodid) {
  PT_Production prod;
  ATermList prods;
  PT_Symbol symbol;
  PT_Symbols symbols; 
  CC_Class *follow;
  CC_Class *set;
  int iptr = 0;

  prod = PGEN_getProductionOfProductionNumber(prodid);
  assert(prod);
  symbols = PT_getProductionLhs(prod);

  /* Iterate over the left hand side symbols and for each non-terminal add 
   * the first set, minus the epsilon, of the remaining symbols to its follow 
   * set. */
  while (!PT_isSymbolsEmpty(symbols)) {
    symbol = PT_getSymbolsHead(symbols);
    symbols = PT_getSymbolsTail(symbols);

    if (!ATisEmpty(symbols)) {
      prods = PGEN_getProductionNumbersOfRhsNonTerminal(symbol);
      /* If symbol is a non-terminal... */
      if (prods) {
        follow = first_no_epsilon(symbols);
        while (!ATisEmpty(prods)) {
          int lhs_prodnr = ATgetInt((ATermInt)ATgetFirst(prods));
          prods = ATgetNext(prods);
          if (!PGEN_isPriorityConflict(IT_createItemDot(prodid, iptr), lhs_prodnr)) {
            set = initial_follow_sets[lhs_prodnr];
            CC_union(set, follow, set);
          }
        }
        CC_free(follow);
      }
    }

    iptr++;
  }
}

static void init_follow_sets() {
  int maxProductionNumber = PGEN_getMaxProductionNumber();
  int prodid;

  initial_follow_sets = (CC_Class **)calloc(maxProductionNumber, sizeof(CC_Class *));
  if (!initial_follow_sets) {
    ATerror("out of memory!\n");
  }

  for(prodid = MIN_PROD_NUM; prodid < maxProductionNumber; prodid++) {
    initial_follow_sets[prodid] = CC_makeClassEmpty();
  }

  for(prodid = MIN_PROD_NUM; prodid < maxProductionNumber; prodid++) {
    init_follow_set(prodid);
  }
}

/** 
 * For each production, get the rules that are needed to calculate the follow 
 * set of that production (the dependencies) and add the initial follow set of 
 * the dependencies to the follow set of the rule. 
 */
static void union_follow_sets() {
  int maxProductionNumber = PGEN_getMaxProductionNumber();
  int prodid, i;
  IS_IntSet deps;

  /* TODO: This should probably be a malloc since follow_table is initialized 
   * below. */
  follow_table = (CC_Class **)calloc(maxProductionNumber, sizeof(CC_Class *));
  if (!follow_table) {
    ATerror("out of memory!\n");
  }

  for (prodid = MIN_PROD_NUM; prodid < maxProductionNumber; prodid++) {
    follow_table[prodid] = CC_makeClassEmpty();
    deps = depend_closure[prodid];
   
    for (i = maxProductionNumber-1; i >= MIN_PROD_NUM; i--) {
      if (IS_contains(deps, i)) {
        CC_union(follow_table[prodid], initial_follow_sets[i], follow_table[prodid]);
      }
    }
    IS_destroy(deps);
    if (CC_isEmpty(follow_table[prodid])) {
      CC_free(follow_table[prodid]);
      follow_table[prodid] = NULL;
    }
  }
  free(depend_closure);
}

void calc_follow_table() {

  init_dependencies();	
  closure_dependencies();
  init_follow_sets();
  union_follow_sets();

  ATunprotectArray((ATerm *)(dependencies+MIN_PROD_NUM));
  free(dependencies);
}

void destroy_follow_table() {
  int i;

  for (i = 0; i < PGEN_getMaxProductionNumber(); i++) {
    if (follow_table[i] != NULL) {
      CC_free(follow_table[i]);
    }
    if (initial_follow_sets[i] != NULL) {
      CC_free(initial_follow_sets[i]);
    }
  }
  free(follow_table);
  follow_table = NULL;
  free(initial_follow_sets);
  initial_follow_sets = NULL;
}

