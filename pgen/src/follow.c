#include <assert.h>

#include "ksdf2table.h"
#include "characters.h"
#include "follow.h"
#include "priorities.h"
#include "first.h"
#include "intset.h"

extern int MAX_PROD;

CC_Class  **follow_table = NULL;
static ATermList *dependencies = NULL;
static IS_IntSet *depend_closure = NULL;
static CC_Class **initial_follow_sets = NULL;

extern ATermTable first_table;
extern ATermTable priority_table;

/*{{{  ATermList charclassExtraction(ATermList followset) */

/* This calculation should be performed once and not each time */
CC_Class *charclassExtraction(ATermList followset)
{
  ATerm felem;
  CC_Class *newClass = CC_makeClassEmpty();

  while (!ATisEmpty(followset)) {
    CC_Class *fcc;
    felem = ATgetFirst(followset);
    followset = ATgetNext(followset);

    fcc = CC_ClassFromTerm(felem);

    if (IS_CHARCLASS(felem)) {
      CC_union(newClass, fcc, newClass);
    }

    CC_free(fcc);
  }
  if (CC_isEmpty(newClass)) {
    CC_free(newClass);
    return NULL;
  }

  return newClass;
}

/*}}}  */

/*{{{  ATermList followset_filtering(ATermList followset) */

ATermList followset_filtering(ATermList followset)
{
  ATerm felem;
  ATermList newfollowset = ATempty;

  while (!ATisEmpty(followset)) {
    felem = ATgetFirst(followset);
    followset = ATgetNext(followset);

    if (IS_CHARCLASS(felem))
      newfollowset = ATinsert(newfollowset, felem);
  }
  return newfollowset;
}

/*}}}  */

/*{{{  static ATermList init_dependency(int prod) */

/**
 * Initialize the dependency of a single production.
 */

static ATermList init_dependency(int prodid)
{
  static ATerm *elems = NULL;
  static int max_elems = 0;

  ATerm prodnr, prod, dep;
  ATermList depends, symbols, orgdep;
  int idx, nr_elems;

  prodnr = (ATerm)ATmakeInt(prodid);
  prod = nr_prod_table[prodid];
  assert(prod);
  symbols = GET_LIST_ARG(prod, 0);

  nr_elems = ATgetLength(symbols);
  if (nr_elems > max_elems) {
    elems = (ATerm *)realloc(elems, sizeof(ATerm)*nr_elems);
    if (!elems)
      ATerror("out of memory!\n");
    max_elems = nr_elems;
  }

  idx = 0;
  while (!ATisEmpty(symbols)) {
    elems[idx++] = ATgetFirst(symbols);
    symbols = ATgetNext(symbols);
  }

  depends = ATempty;
  for(--idx; idx>=0; idx--) {
    ATerm elem = elems[idx];

    orgdep = (ATermList)ATtableGet(rhs_prods_pairs, elem);
    if (!orgdep)
      break; /* Declared sort with no productions, this should not happen! */

    while (!ATisEmpty(orgdep)) {
      dep = ATgetFirst(orgdep);
      orgdep = ATgetNext(orgdep);
      if (!conflicts(IT_createItemDot(prodid, idx), dep)) {
	depends = ATaddElement(depends, dep);
      }
    }

    if (!CC_containsChar(get_first_set(elem, ATtrue), CC_EPSILON)) {
      break;
    }
    /*
    if (!contains_epsilon((ATermList)ATtableGet(first_table, elem)))
      break;
      */
  }

  /* Remove yourself if present */
  depends = ATremoveElement(depends, prodnr);

  return depends;
}

/*}}}  */
/*{{{  static void init_dependencies() */

/**
 * Calculate dependencies (which prods followset depends on which prods followset)
 */

static void init_dependencies()
{
  int i;

  dependencies = (ATermList *)calloc(MAX_PROD, sizeof(ATermList));
  if (!dependencies) {
    ATerror("out of memory!\n");
  }
  ATprotectArray((ATerm *)(dependencies+MIN_PROD), MAX_PROD-MIN_PROD);

  for(i=MIN_PROD; i<MAX_PROD; i++) {
    dependencies[i] = init_dependency(i);
  }
}

/*}}}  */

/*{{{  static void find_closure(int prodid, ATermList *deps, IS_IntSet set) */

static void find_closure(int prodid, ATermList *dependencies, IS_IntSet set)
{
  ATermList deps = dependencies[prodid];

  if (deps) {
    while (!ATisEmpty(deps)) {
      int dep = ATgetInt((ATermInt)ATgetFirst(deps));
      if (IS_add(set, dep)) {
	find_closure(dep, dependencies, set);
      }
      deps = ATgetNext(deps);
    }
  }
}

/*}}}  */

#if 0
/*{{{  static ATermList extract_prods(IS_IntSet set) */

static ATermList extract_prods(IS_IntSet set)
{
  ATermList result = ATempty;
  int i;

  for (i=MAX_PROD-1; i>=0; i--) {
    while (i % 32 == 31 && set[i/32] == 0) {
      i -= 32;
      if (i == -1) {
	return result;
      }
    }
    if (IS_contains(set, i)) {
      result = ATinsert(result, (ATerm)ATmakeInt(i));
    }
  }

  return result;
}

/*}}}  */
/*{{{  static void add_prods(IS_IntSet set, ATermList prods) */

static void add_prods(IS_IntSet set, ATermList prods)
{
  ATwarning("adding prods: %t\n", prods);
  while (!ATisEmpty(prods)) {
    int prodid = ATgetInt((ATermInt)ATgetFirst(prods));
    IS_add(set, prodid);
    prods = ATgetNext(prods);
  }
}

/*}}}  */
#endif

/*{{{  static void closure_dependencies() */

static void closure_dependencies()
{
  int prodid;
  ATermList depends;
  ATermList *forward_depends;
  IS_IntSet set;

  /*{{{  Initialize depend_closure elements */

  depend_closure = (IS_IntSet *)calloc(MAX_PROD, sizeof(IS_IntSet));
  if (!depend_closure) {
    ATerror("out of memory!\n");
  }

  forward_depends = (ATermList *)calloc(MAX_PROD, sizeof(ATermList));
  if (!forward_depends) {
    ATerror("out of memory in closure_dependencies (1)\n");
  }
  ATprotectArray((ATerm *)forward_depends, MAX_PROD);

  /*}}}  */

  for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
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

  for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
    set = IS_create(MAX_PROD);
    IS_add(set, prodid);
    find_closure(prodid, forward_depends, set);
    depend_closure[prodid] = set;
  }

  ATunprotectArray((ATerm *)forward_depends);
  free(forward_depends);
}

/*}}}  */

/*{{{  static void init_follow_set(int prodid) */

static void init_follow_set(int prodid)
{
  ATerm prod, symbol;
  ATermList symbols, prods;
  CC_Class *follow;
  CC_Class *set;
  int iptr, len;

  prod = nr_prod_table[prodid];
  assert(prod);
  symbols = GET_LIST_ARG(prod, 0);

  iptr = 0;
  len  = ATgetLength(symbols);
  while (!ATisEmpty(symbols)) {
    symbol = ATgetFirst(symbols);
    symbols = ATgetNext(symbols);

    if (!ATisEmpty(symbols)) {
	prods = (ATermList)ATtableGet(rhs_prods_pairs, symbol);
	if (prods) {
	  follow = first_no_epsilon(symbols);
	  while (!ATisEmpty(prods)) {
	    ATerm lhs_prodnr = ATgetFirst(prods);
	    prods = ATgetNext(prods);
	    if (!conflicts(IT_createItemDot(prodid, iptr), lhs_prodnr)) {
	      int lhs_prodid = ATgetInt((ATermInt)lhs_prodnr);
	      set = initial_follow_sets[lhs_prodid];
	      CC_union(set, follow, set);
	    }
	  }
	  CC_free(follow);
	}
      }

    iptr++;
  }
}

/*}}}  */
/*{{{  static void init_follow_sets() */

static void init_follow_sets()
{
  int prodid;

  initial_follow_sets = (CC_Class **)calloc(MAX_PROD, sizeof(CC_Class *));
  if (!initial_follow_sets) {
    ATerror("out of memory!\n");
  }

  for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
    initial_follow_sets[prodid] = CC_makeClassEmpty();
  }

  for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
    init_follow_set(prodid);
  }
}

/*}}}  */

/*{{{  static void union_follow_sets() */

/**
 * Union all follow sets found in the dependency closure
 */

static void union_follow_sets()
{
  int prodid, i;
  ATbool done;
  IS_IntSet deps;

  follow_table = (CC_Class **)calloc(MAX_PROD, sizeof(CC_Class *));
  if (!follow_table) {
    ATerror("out of memory!\n");
  }

  for (prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
    follow_table[prodid] = CC_makeClassEmpty();
    deps = depend_closure[prodid];
    done = ATfalse;
    for (i=MAX_PROD-1; !done && i>=MIN_PROD; i--) {
      while (i % 32 == 31 && deps[i/32] == 0) {
	i -= 32;
	if (i == -1) {
	  done = ATtrue;
	  break;
	}
      }
      if (!done && IS_contains(deps, i)) {
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

  /*
  for (prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
    ATwarning("follow_table[%d] = %t\n", prodid,
	      follow_table[prodid] ? CC_ClassToTerm(follow_table[prodid]) : ATempty);
  }
  */
}

/*}}}  */

/*{{{  void calc_follow_table() */

void calc_follow_table()
{
  /*
     int i;
     */

  init_dependencies();	

  closure_dependencies();

  init_follow_sets();

  union_follow_sets();

  ATunprotectArray((ATerm *)(dependencies+MIN_PROD));
  free(dependencies);
}

/*}}}  */
/*{{{  void destroy_follow_table() */

void destroy_follow_table()
{
  int i;

  for (i=0; i<MAX_PROD; i++) {
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

/*}}}  */
