#include <assert.h>

#include "ksdf2table.h"
#include "characters.h"
#include "follow.h"
#include "priorities.h"
#include "first.h"

extern ATerm empty_set;
extern int MAX_PROD;

static ATermList *local_follow_table = NULL;

CC_Class  **follow_table = NULL;
static ATermList *dependencies = NULL;
static ATermList *depend_closure = NULL;
static ATermList *initial_follow_sets = NULL;

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

/*{{{  ATermList calc_first(ATermList symbols, int prodnr) */

ATermList calc_first(ATermList symbols, int prodnr)
{
  ATermList set, lset, followset, newset = ATempty;
  ATerm symbol;

  followset = local_follow_table[prodnr];
  if (!followset)
    followset = ATempty;

  if (ATisEmpty(symbols))
    return followset;
  else {
    while (!ATisEmpty(symbols)) {
      symbol = ATgetFirst(symbols);
      symbols = ATgetNext(symbols);

      set = (ATermList)ATtableGet(first_table,symbol);
      if (contains_epsilon(set)) {
	lset = remove_epsilon(set);
	newset = ATunion(newset, lset);
      }
      else {
	return ATunion(newset, set);
      }
    }
    return ATunion(newset,followset);
  }
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
    if (IS_CHARCLASS(elem))
      break;

    orgdep = (ATermList)ATtableGet(rhs_prods_pairs, elem);
    if (!orgdep)
      break; /* Declared sort with no RHS, this should not happen! */

    while (!ATisEmpty(orgdep)) {
      dep = ATgetFirst(orgdep);
      orgdep = ATgetNext(orgdep);
      if (!conflicts(IT_createItemDot(prodid, idx), dep)) {
	depends = ATaddElement(depends, dep);
      }
    }

    if (!contains_epsilon((ATermList)ATtableGet(first_table, elem)))
      break;
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
  if (!dependencies)
    ATerror("out of memory!\n");
  ATprotectArray((ATerm *)(dependencies+MIN_PROD), MAX_PROD-MIN_PROD);

  for(i=MIN_PROD; i<MAX_PROD; i++) {
    dependencies[i] = init_dependency(i);
  }
}

/*}}}  */

/*{{{  static void closure_dependencies() */

/**
 * Calculate the closure of all the dependencies
 */

static void closure_dependencies()
{
  int *queue;
  int prodid, start, end;
  ATbool *in_queue;
  ATermList depends, closure;

  /*{{{  Initialize depend_closure elements */

  depend_closure = (ATermList *)calloc(MAX_PROD, sizeof(ATermList));
  if (!depend_closure)
    ATerror("out of memory!\n");
  ATprotectArray((ATerm *)(depend_closure+MIN_PROD), MAX_PROD-MIN_PROD);

  for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
    depend_closure[prodid] = ATmakeList1((ATerm)ATmakeInt(prodid));
  }

  /*}}}  */
  /*{{{  Initialize queue and in_queue */

  queue = (int *)malloc(sizeof(int)*MAX_PROD);
  if (!queue)
    ATerror("out of memory!\n");

  start = 0;
  end   = 0;

  in_queue = (ATbool *)calloc(MAX_PROD, sizeof(int));
  if (!in_queue)
    ATerror("out of memory!\n");

  /*}}}  */
  /*{{{  Initially, put all prods in the queue */

  for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
    queue[end++] = prodid;
    in_queue[prodid] = ATtrue;
  }

  /*}}}  */

  while (start != end) {
    prodid = queue[start];
    in_queue[prodid] = ATfalse;
    start = (start+1)%MAX_PROD;

    depends = dependencies[prodid];
    while (!ATisEmpty(depends)) {
      int child = ATgetInt((ATermInt)ATgetFirst(depends));
      depends = ATgetNext(depends);

      closure = ATunion(depend_closure[child], depend_closure[prodid]);
      if (ATgetLength(closure) > ATgetLength(depend_closure[child])) {
	depend_closure[child] = closure;
	if (!in_queue[child]) {
	  in_queue[child] = ATtrue;
	  queue[end] = child;
	  end = (end+1)%MAX_PROD;
	  assert(end != start);
	}
      }
    }
  }
  free(queue);
  free(in_queue);   
}

/*}}}  */

/*{{{  ATermList calculate_first(ATermList symbols) */

ATermList calculate_first(ATermList symbols)
{
  ATermList set, lset, followset, newset = ATempty;
  ATerm symbol;

  followset = ATempty;

  if (ATisEmpty(symbols))
    return followset;
  else {
    while (!ATisEmpty(symbols)) {
      symbol = ATgetFirst(symbols);
      symbols = ATgetNext(symbols);

      set = (ATermList)ATtableGet(first_table,symbol);
      if (contains_epsilon(set)) {
	lset = remove_epsilon(set);
	newset = ATunion(newset, lset);
      }
      else {
	return ATunion(newset, set);
      }
    }
    return ATunion(newset,followset);
  }
}

/*}}}  */
/*{{{  static void init_follow_set(int prodid) */

static void init_follow_set(int prodid)
{
  ATerm prod, symbol;
  ATermList sets, symbols, follow, prods;
  int iptr, len;

  prod = nr_prod_table[prodid];
  assert(prod);
  symbols = GET_LIST_ARG(prod, 0);

  iptr = 0;
  len  = ATgetLength(symbols);
  while (!ATisEmpty(symbols)) {
    symbol = ATgetFirst(symbols);
    symbols = ATgetNext(symbols);
    if (!IS_CHARCLASS(symbol)) {
      if (!ATisEmpty(symbols)) {
	prods = (ATermList)ATtableGet(rhs_prods_pairs, symbol);
	if (prods) {
	  follow = calculate_first(symbols);
	  while (!ATisEmpty(prods)) {
	    ATerm lhs_prodnr = ATgetFirst(prods);
	    prods = ATgetNext(prods);
	    if (!conflicts(IT_createItemDot(prodid, iptr), lhs_prodnr)) {
	      int lhs_prodid = ATgetInt((ATermInt)lhs_prodnr);
	      sets = initial_follow_sets[lhs_prodid];
	      sets = ATinsert(sets, (ATerm)follow);
	      initial_follow_sets[lhs_prodid] = sets;
	    }
	  }
	}
      }
    }
    iptr++;
  }
}

/*}}}  */
/*{{{  static void init_follow_sets() */

/**
 * Initialize all the follow sets
 */

static void init_follow_sets()
{
  int prodid;
  ATermList set;

  initial_follow_sets = (ATermList *)calloc(MAX_PROD, sizeof(ATermList));
  if (!initial_follow_sets)
    ATerror("out of memory!\n");
  ATprotectArray((ATerm *)(initial_follow_sets+MIN_PROD), MAX_PROD-MIN_PROD);

  for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
    initial_follow_sets[prodid] = ATempty;
  }

  for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
    init_follow_set(prodid);
  }

  for(prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
    set = initial_follow_sets[prodid];
    set = ATunionSetList(set);
    set = ATremoveElement(set, empty_set);
    initial_follow_sets[prodid] = set;
  }
}

/*}}}  */

/*{{{  static void union_follow_sets() */

/**
 * Union all follow sets found in the dependency closure
 */

static void union_follow_sets()
{
  ATermList result, follows, deps;
  int prodid;

  follow_table = (CC_Class **)malloc(MAX_PROD*sizeof(CC_Class *));
  if (!follow_table) {
    ATerror("out of memory!\n");
  }

  for (prodid=MIN_PROD; prodid<MAX_PROD; prodid++) {
    result = ATmakeList1((ATerm)initial_follow_sets[prodid]);
    deps = depend_closure[prodid];
    while (!ATisEmpty(deps)) {
      int depid = ATgetInt((ATermInt)ATgetFirst(deps));
      deps = ATgetNext(deps);
      follows = initial_follow_sets[depid];
      result = ATinsert(result, (ATerm)follows);
    }
    result = ATunionSetList(result);
    follow_table[prodid] = charclassExtraction(result);
  }
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
