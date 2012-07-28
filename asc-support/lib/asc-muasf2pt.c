/* $Id$ */

/*{{{  standard includes */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/*}}}  */
/*{{{  meta includes */

#include <MEPT-utils.h>
#include <ASFME-utils.h>

/*}}}  */
/*{{{  local includes */

#include "asc-support-me.h"
#include "asc-muasf2pt.h"
#include "asc-termstore.h"

/*}}}  */

/*{{{  globals */

#define TREE_TABLE_INITIAL_SIZE        4096
#define TREE_TABLE_MAX_LOAD_PERCENTAGE 75
static ATermTable treeTable = NULL;


static PT_Tree defaultLayout  = NULL;
extern ATbool keep_layout;
/*}}}  */

/*{{{  local functions */

static PT_Tree termToTree(ATerm tree);
static PT_Tree listToTree(PT_Production prod, ATermList elems);
static PT_Args termsToArgs(PT_Symbols args, ATermAppl appl);


/*}}}  */


/*{{{  static PT_Tree restoreLiteral(PT_Symbol symbol) */

static PT_Tree restoreLiteral(PT_Symbol symbol)
{
  PT_Tree result;

  result = PT_makeTreeLit(PT_getSymbolString(symbol));
  return result;
}

/*}}}  */
/*{{{  static PT_Tree restoreCiliteral(PT_Symbol symbol) */

static PT_Tree restoreCiliteral(PT_Symbol symbol)
{
  PT_Tree result;
  
  result = PT_makeTreeCilit(PT_getSymbolString(symbol));
  return result;

}

/*}}}  */
/*{{{  static PT_Tree listToTree(PT_Production prod, ATermList elems) */

static PT_Tree listToTree(PT_Production prod, ATermList elems)
{
  PT_Tree layout = defaultLayout;
  PT_Tree sepTree = NULL;
  PT_Symbol rhs;
  PT_Args args = PT_makeArgsEmpty();
  ATbool contextfree;
  int sepLength = 0;
  int i;
  
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
    sepLength = contextfree ? 3 : 1;
  }

  if (!ATisEmpty(elems)) {
    /* get a free part of the term store */
    TERM_STORE_FRAME(ATgetLength(elems),

    for (i = 0; !ATisEmpty(elems); elems = ATgetNext(elems)) {
      PT_Tree newTree = termToTree(ATgetFirst(elems));
      /* Note that TERM_STORE contains a reference to a global
       * that may be updated by termToTree, so do not remove the
       * newTree temporary variable and do not inline the call to termToTree
       * in the following assignment. 
       */
      TERM_STORE_CHECK(i);
      TERM_STORE[i] = (ATerm) newTree;
      i++;
    } 

    while(--i >= 0) {
      args = PT_makeArgsMany((PT_Tree) TERM_STORE[i], args);

      if (i != 0) {
        if (sepTree) {
	  if (!keep_layout && contextfree) {
	    args = PT_makeArgsMany(layout, args);
	  }

	  if (!keep_layout) {
	    args = PT_makeArgsMany(sepTree, args);
	  }
        }

        if (!keep_layout && contextfree) {
	  args = PT_makeArgsMany(layout, args);
        }
      }
    }
    )
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

    if (!keep_layout && PT_isOptLayoutSymbol(symbol)) {
      tree = defaultLayout;
    }
    else if (!keep_layout && PT_isSymbolLit(symbol)) {
      tree = restoreLiteral(symbol);
    }
    else if (!keep_layout && PT_isSymbolCilit(symbol)) {
      tree = restoreCiliteral(symbol);
    }
    else { 
      /*assert(j >= 0 && j < arity && "not enough arguments, or too much");*/
      if (j < 0 || j >= arity) {
	ATwarning("assert failed, not enough arguments, or too much");
	ATwarning("\tj: %d\n\tarity: %d\n\tsymbols: %t\n\tappl: %t\n\n", 
		  j, arity, args, appl);
      }

      arg = ATgetArgument(appl, j--);
      tree = termToTree(arg);
      assert(tree != NULL);
    }

    if (tree != NULL) {
      result = PT_makeArgsMany(tree ,result);
    }
  }

  return result;
}

/*}}}  */
/*{{{  static PT_Tree termToTree(ATerm tree) */

static PT_Tree termToTree(ATerm tree)
{
  PT_Tree result = NULL;
  ATerm prod = NULL;
  PT_Production ptProd = NULL;
  PT_Symbols formalargs = NULL;
  PT_Args actualargs = NULL;

  result = (PT_Tree) ATtableGet(treeTable,tree); 

  if (result == NULL) {
    ATerm annos = ATgetAnnotations(tree);

    if(ATgetType(tree) == AT_APPL) {

      prod = lookup_prod(ATgetSymbol((ATermAppl)tree));
      if(!prod) {
	ATabort("unknown production symbol: %s\n",
		ATgetName(ATgetSymbol((ATermAppl) tree)));
      }

      ptProd = PT_ProductionFromTerm(prod);
     
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

    if (annos != NULL) {
      result = PT_setTreeAnnotations(result, annos);
    }

    ATtablePut(treeTable, tree, (ATerm) result);
  }

  return result;
}

/*}}}  */

/*{{{  PT_Tree muASFToTreeWithLayout(ATerm tree, PT_Tree layout) */

PT_Tree muASFToTreeWithLayout(ATerm tree, PT_Tree layout)
{
  PT_Tree result;

  assert(tree != NULL && layout != NULL && "parameter check");

  treeTable = ATtableCreate(TREE_TABLE_INITIAL_SIZE,
			    TREE_TABLE_MAX_LOAD_PERCENTAGE);

  ATprotect((ATerm*) ((void*) &defaultLayout));
  defaultLayout = layout;

  result = termToTree(tree);

  ATtableDestroy(treeTable);
  treeTable = NULL;
  ATunprotect((ATerm*) ((void*) &defaultLayout));
  defaultLayout = NULL;

  return result;
}

/*}}}  */
/*{{{  PT_Tree muASFToTree(ATerm tree, PT_Tree layout) */

PT_Tree muASFToTree(ATerm tree) 
{
  return muASFToTreeWithLayout(tree,  (PT_Tree) ASF_makeLayoutSpace());
}

/*}}}  */
