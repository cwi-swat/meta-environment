/* $Id$ */

/*{{{  standard includes */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/*}}}  */
/*{{{  meta includes */

#include <MEPT-utils.h>

/*}}}  */
/*{{{  local includes */

#include "asc-support-me.h"
#include "muasf2pt.h"

/*}}}  */

/*{{{  globals */

#define TREE_TABLE_INITIAL_SIZE        4096
#define TREE_TABLE_MAX_LOAD_PERCENTAGE 75
static ATermTable treeTable = NULL;

#define TERM_STORE_INITIAL_SIZE    512
#define TERM_STORE (term_store+term_store_begin)
#define ASSERT_VALID_INDEX(i) assert(term_store_begin + (i) <= term_store_end)

static size_t term_store_begin; 
static size_t term_store_end;   
static size_t term_store_size;
static PT_Tree* term_store = NULL;

/*}}}  */

/*{{{  local functions */

static PT_Tree termToTree(ATerm tree);
static PT_Tree listToTree(PT_Production prod, ATermList elems);
static PT_Args termsToArgs(PT_Symbols args, ATermAppl appl);

static size_t getTermStore(size_t size);
static void createTermStore(void);
static void destroyTermStore(void);

/*}}}  */

/* This term_store is built to cope with a recursive function. Each
 * of its calls needs its own term_store, but we want to reuse allocated
 * memory. It works somewhat like a stack using getTermStore as a push and
 * resetTermStore as a pop. Term_store_end holds the top of the stack.
 */
/*{{{  static void createTermStore(void) */

static void createTermStore(void)
{
  term_store_size = TERM_STORE_INITIAL_SIZE;
  term_store_begin = -1;
  term_store_end = -1;

  term_store = (PT_Tree*) calloc(term_store_size, sizeof(PT_Tree));

  if (term_store == NULL) {
    ATerror("createTermStore: unable to allocate memory for %d Trees",
	    term_store_size);
  }

  ATprotectArray((ATerm*) term_store, term_store_size);
}

/*}}}  */
/*{{{  static size_t getTermStore(size_t size) */

static size_t getTermStore(size_t size)
{
  size_t old_begin;

  assert(size > 0);

  if (term_store_size <= size + term_store_end) {
    size_t old_size = term_store_size;
    ATunprotectArray((ATerm*) term_store);

    /* Allocate at least enough memory for the request, and then
     * some more to prevent this from happening too often.
     */
    term_store_size = size + term_store_end + 1 + TERM_STORE_INITIAL_SIZE;
    term_store = (PT_Tree *) realloc(term_store,
				     term_store_size * sizeof(PT_Tree));

    if (term_store == NULL) {
      ATerror("resizeTermStore: unable to allocate memory for %d PT_Trees",
	      term_store_size);
      return -1;
    }

    /* Make sure 0 is in the uninitialized part of the array */
    memset(term_store + old_size, 0, 
	   (term_store_size - old_size) * sizeof(PT_Tree));

    ATprotectArray((ATerm*) term_store, term_store_size);
  }

  /* begin and end are both inclusive boundaries */
  old_begin        = term_store_begin;
  term_store_begin = term_store_end + 1;
  term_store_end   = term_store_begin + size - 1;
  return old_begin;
}

/*}}}  */
/*{{{  static void resetTermStoreTo(size_t index) */

static void resetTermStoreTo(size_t index)
{
  term_store_end = term_store_begin - 1;
  term_store_begin = index;
}

/*}}}  */
/*{{{  static void destroyTermStore(void) */

static void destroyTermStore(void)
{
  ATunprotectArray((ATerm*) term_store);

  free(term_store);
  term_store_size = 0;
  term_store = NULL;
}

/*}}}  */

/*{{{  static PT_Tree listToTree(PT_Production prod, ATermList elems) */

static PT_Tree listToTree(PT_Production prod, ATermList elems)
{
  PT_Tree layout = PT_makeTreeLayoutFromString(" ");
  PT_Tree sepTree = NULL;
  PT_Symbol rhs;
  PT_Args args = PT_makeArgsEmpty();
  ATbool contextfree;
  int i;
  size_t index;
  
  rhs = PT_getProductionRhs(prod);

  if (PT_isSymbolCf(rhs)) {
    rhs = PT_getSymbolSymbol(rhs);
    contextfree = ATtrue;
  } else if (PT_isSymbolLex(rhs)) {
    rhs = PT_getSymbolSymbol(rhs);
    contextfree = ATfalse;
  } else {
    contextfree = ATfalse;
  }

  if (PT_hasSymbolSeparator(rhs)) {
    PT_Symbol sepSym = PT_getSymbolSeparator(rhs);
    assert(PT_isSymbolLit(sepSym));
    sepTree = PT_makeTreeLit(PT_getSymbolString(sepSym));
  }

  if (!ATisEmpty(elems)) {
    /* get a free part of the term store */
    index = getTermStore(ATgetLength(elems));

    for (i = 0; !ATisEmpty(elems); elems = ATgetNext(elems)) {
      ASSERT_VALID_INDEX(i);
      TERM_STORE[i++] = termToTree(ATgetFirst(elems));
    } 

    while(--i >= 0) {
      args = PT_makeArgsList(TERM_STORE[i], args);

      if (i != 0) {
        if (sepTree) {
	  if (contextfree) {
	    args = PT_makeArgsList(layout, args);
	  }
	  args = PT_makeArgsList(sepTree, args);
        }

        if (contextfree) {
	  args = PT_makeArgsList(layout, args);
        }
      }
    }

    /* release my part of the term store */
    resetTermStoreTo(index);
  }

  return PT_makeTreeAppl(prod, args);
}

/*}}}  */
/*{{{  static PT_Args termsToArgs(PT_Symbols args, ATermAppl appl) */

static PT_Args termsToArgs(PT_Symbols args, ATermAppl appl)
{
  PT_Args result = PT_makeArgsEmpty();
  int arity = ATgetArity(ATgetSymbol(appl));
  int i;
  int j = arity-1; 
  int len = PT_getSymbolsLength(args);
  ATerm arg;

  for(i=len-1; i>=0; i--) {
    PT_Symbol symbol = PT_getSymbolsSymbolAt(args,i);
    PT_Tree tree = NULL;

    if (PT_isOptLayoutSymbol(symbol)) {
      tree = PT_makeTreeLayoutFromString(" ");
    }
    else if(PT_isSymbolLit(symbol)) {
      char *str = PT_getSymbolString(symbol);
      tree = PT_makeTreeLit(str);
      assert(tree != NULL);
    } 
    else { 
      assert(j >= 0 && j < arity);
      arg = ATgetArgument(appl, j--);
      tree = termToTree(arg);
      assert(tree != NULL);
    }

    result = PT_makeArgsList(tree ,result);
  }

  return result;
}

/*}}}  */
/*{{{  PT_Tree termToTree(ATerm tree) */

static PT_Tree termToTree(ATerm tree)
{
  PT_Tree result = NULL;
  ATerm prod = NULL;
  PT_Production ptProd = NULL;
  PT_Symbols formalargs = NULL;
  PT_Args actualargs = NULL;

  result = (PT_Tree) ATtableGet(treeTable,tree); 

  if (result == NULL) {
#ifdef KEEP_ANNOTATIONS
    ATerm annos = ATgetAnnotations(tree);
#endif
    if(ATgetType(tree) == AT_APPL) {
      prod = lookup_prod(ATgetSymbol((ATermAppl)tree));
      if(!prod) {
	ATabort("unknown production symbol: %s\n",
		ATgetName(ATgetSymbol((ATermAppl) tree)));
      }

      ptProd = PT_makeProductionFromTerm(prod);
     
      if (PT_isProductionDefault(ptProd)) { 
	formalargs = PT_getProductionLhs(ptProd);
	actualargs = termsToArgs(formalargs, (ATermAppl)tree);
        result     = PT_makeTreeAppl(ptProd,actualargs);
      }
      else { /* a list */
	result = listToTree(ptProd,
			    (ATermList) ATgetArgument((ATermAppl)tree,0));
      }
    } 
    else {
      assert(ATgetType(tree) == AT_INT);
      result = (PT_Tree) tree;
    }

#ifdef KEEP_ANNOTATIONS
    if (annos != NULL) {
      result = PT_setTreeAnnotations(result, annos);
    }
#endif

    ATtablePut(treeTable, tree, (ATerm) result);
  }

  return result;
}

/*}}}  */

/*{{{  PT_Tree yieldTree(ATerm tree) */

PT_Tree muASFToTree(ATerm tree)
{
  PT_Tree result;

  treeTable = ATtableCreate(TREE_TABLE_INITIAL_SIZE,
			    TREE_TABLE_MAX_LOAD_PERCENTAGE);

  createTermStore();

  result = termToTree(tree);

  ATtableDestroy(treeTable);
  treeTable = NULL;
  destroyTermStore();

  return result;
}

/*}}}  */
