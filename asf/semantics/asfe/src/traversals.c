/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <aterm2.h>
#include <assert.h>
#include <deprecated.h>
#include "asfix_utils.h"
#include "asfe.h"
#include "traversals.h"

/*}}}  */

/*{{{  structures */

typedef struct PositionSymbolTuple_tag {
  int pos;
  PT_Symbol symbol;
} PositionSymbolTuple;

typedef struct PositionTreeTuple_tag {
  int pos;
  PT_Tree tree;
} PositionTreeTuple;


/*}}}  */
/*{{{  externals */

extern ATbool run_verbose;

/*}}}  */

/*{{{  PT_Symbol getSymbol(PT_Symbol symbol, PT_SymbolVisitorData data) */

PT_Symbol getSymbol(PT_Symbol symbol, PT_SymbolVisitorData data)
{
  if (((PositionSymbolTuple*)data)->pos == 0) {
    ((PositionSymbolTuple*)data)->symbol = symbol;
  }

  ((PositionSymbolTuple*)data)->pos--;
 
  return symbol;
}

/*}}}  */

/*{{{  PT_Symbol replaceSymbol(PT_Symbol symbol, PT_SymbolVisitorData data) */

PT_Symbol replaceSymbol(PT_Symbol symbol, PT_SymbolVisitorData data)
{
  if (((PositionSymbolTuple*)data)->pos == 0) {
    symbol = ((PositionSymbolTuple*)data)->symbol;
  }

  ((PositionSymbolTuple*)data)->pos--;
  return symbol;
}

/*}}}  */
/*{{{  PT_Tree getTree(PT_Tree tree, PT_TreeVisitorData data) */

PT_Tree getTree(PT_Tree tree, PT_TreeVisitorData data)
{
  if (((PositionSymbolTuple*)data)->pos == 0) {
    ((PositionTreeTuple*)data)->tree = tree;
  }

  ((PositionTreeTuple*)data)->pos--;

  return tree;
}

/*}}}  */
/*{{{  PT_Tree replaceTree(PT_Tree tree, PT_TreeVisitorData data) */

PT_Tree replaceTree(PT_Tree tree, PT_TreeVisitorData data)
{
  if (((PositionTreeTuple*)data)->pos == 0) {
    tree = ((PositionTreeTuple*)data)->tree;
  }

  ((PositionTreeTuple*)data)->pos--;
  return tree;
}

/*}}}  */
/*{{{  PT_Tree selectTree(PT_Args args, int pos) */

/* selectTree
 *
 * input: a traversal appl
 * output: The argument term at pos of this appl. 
 *
 */

PT_Tree selectTree(PT_Args args, int pos)
{
  PositionTreeTuple data;

  data.pos = pos;
  data.tree = NULL;

  PT_foreachTreeInArgs(args, getTree, (PT_TreeVisitorData) &data);

  assert(data.tree);

  return data.tree;
}

/*}}}  */

/*{{{  Traversal createTraversalPattern(PT_Tree term) */

/* create_traversal_pattern
 *
 * input: a PT_TreeAppl
 * output: a Traversal struct, containing the original traversal term
 *         and an indication if it is a transformer or an analyzer.
 * 
 */

Traversal createTraversalPattern(PT_Tree term)
{
  PT_Production prod;
  PT_Args args;
  PT_Symbols symbols;
  PT_Symbol symbol, cleanSymbol;
  PT_Symbol traversed;
  PT_Symbol accumulated = NULL;
  PositionSymbolTuple symbolVisitorData;
  Traversal traversal;

  prod = PT_getTreeProd(term);
  args = PT_getTreeArgs(term);

  symbols = PT_getProductionLhs(prod);
  symbol = PT_getProductionRhs(prod);
  cleanSymbol = PT_getSymbolSymbol(symbol);

  /* get the symbol of the traversed arg */
  symbolVisitorData.pos = TRAVERSED_SYMBOL_POS;
  symbolVisitorData.symbol = NULL;
  PT_foreachSymbolInSymbols(symbols, getSymbol, 
                         (PT_SymbolVisitorData) &symbolVisitorData); 
  traversed = symbolVisitorData.symbol;
  assert(traversed != NULL);

  /* get the symbol of the accumulated arg */
  symbolVisitorData.pos = ACCUMULATED_SYMBOL_POS;
  symbolVisitorData.symbol = NULL;
  PT_foreachSymbolInSymbols(symbols, getSymbol, 
                         (PT_SymbolVisitorData) &symbolVisitorData); 
 
  if (symbolVisitorData.symbol != NULL) {
    accumulated = PT_getSymbolSymbol(symbolVisitorData.symbol);
  }
 

  traversal.type = UNDEFINED;
 
  if (PT_isEqualSymbol(traversed, symbol)) {
    traversal.type = TRANSFORMER;
  } 
  else if(accumulated != NULL) {
    if(PT_isEqualSymbol(accumulated, cleanSymbol)) {
      traversal.type = ACCUMULATOR;
    }
    else if(accumulated != NULL && PT_isSymbolPair(cleanSymbol)) {
      PT_Symbol lhs = PT_getSymbolLhs(cleanSymbol);
      PT_Symbol rhs = PT_getSymbolRhs(cleanSymbol);
      
      if (PT_isEqualSymbol(PT_getSymbolSymbol(traversed),lhs) &&
	  PT_isEqualSymbol(accumulated,rhs)) {
	traversal.type = COMBINATION;
      }
    }
  }
  
  traversal.prod = prod;
  traversal.accumulated = accumulated;
  traversal.args = args;
  traversal.symbols = symbols;

  return traversal;
}

/*}}}  */
/*{{{  PT_Tree makeTraversalAppl(PT_Tree appl, Traversal traversal) */

/* make_traversal_appl
 *
 * input: an appl and a traversal pattern (made by create_traversal_patten)
 * output: the traversal pattern instantiated by the symbol and the term 
 *         of the first argument.
 */

PT_Tree makeTraversalAppl(PT_Tree appl, Traversal traversal)
{
  PT_Production prod;
  PT_Args args;
  PT_Symbol symbol;
  PT_Tree newappl;
  PT_Symbols symbols;
  PositionSymbolTuple symbolVisitorData;
  PositionTreeTuple treeVisitorData;

  symbol = PT_getProductionRhs(PT_getTreeProd(appl));

  symbolVisitorData.pos = TRAVERSED_SYMBOL_POS;
  symbolVisitorData.symbol = symbol;
  symbols = PT_foreachSymbolInSymbols(traversal.symbols, 
                                      replaceSymbol, 
                                      (PT_SymbolVisitorData) 
                                        &symbolVisitorData);

  prod = PT_setProductionLhs(traversal.prod, symbols);
  treeVisitorData.pos = TRAVERSED_ARG_POS;
  treeVisitorData.tree = appl;

  args = PT_foreachTreeInArgs(traversal.args, replaceTree, 
                              (PT_TreeVisitorData) &treeVisitorData); 

  switch(traversal.type) {
  case TRANSFORMER:
    prod = PT_setProductionRhs(prod, symbol);
    break;
  case COMBINATION:
    prod = PT_setProductionRhs(prod, 
                               PT_makeSymbolCf(
                                 PT_makeSymbolPair(PT_getSymbolSymbol(symbol), 
                                                   traversal.accumulated)));
    break;
  case ACCUMULATOR:
  case UNDEFINED:
  default:
    /* do nothing */

    /* Not putting "break" here implied the "default:" just seen is
     * a label, which causes a warning in gcc-3.0.1:
     *   warning: deprecated use of label at end of compound statement
     */
    break;
  }

  newappl = PT_setTreeProd(appl, prod);
  newappl = PT_setTreeArgs(newappl, args);

  return newappl;
}

/*}}}  */
/*{{{  Traversal updateAccumulator(Traversal traversal, PT_Tree newarg) */

/* update_accumulator
 *
 * Changes the second argument of the traversal pattern. This is used
 * as a value environment for traversals.
 */

Traversal updateAccumulator(Traversal traversal, PT_Tree newarg)
{
  PositionTreeTuple data;
  data.pos = ACCUMULATED_ARG_POS;
  data.tree = newarg;

  assert(traversal.type == ACCUMULATOR || traversal.type == COMBINATION);

  traversal.args = PT_foreachTreeInArgs(traversal.args, replaceTree,
                                     (PT_TreeVisitorData) &data);

  return traversal;
}

/*}}}  */
/*{{{  PT_Tree getTupleFirst(PT_Tree tuple) */

PT_Tree getTupleFirst(PT_Tree tuple)
{
   PT_Args args = PT_getTreeArgs(tuple);

   return PT_getArgsArgumentAt(args, TUPLE_FIRST_POS);
}

/*}}}  */
/*{{{  PT_Tree getTupleSecond(PT_Tree tuple) */

PT_Tree getTupleSecond(PT_Tree tuple)
{
   PT_Args args = PT_getTreeArgs(tuple);

   return PT_getArgsArgumentAt(args, TUPLE_SECOND_POS);
}

/*}}}  */

/*{{{  static PT_Tree makeTuple(PT_Tree tree, PT_Tree accu) */

static PT_Tree makeTuple(PT_Tree tree, PT_Tree accu)
{
   PT_Symbol treeSymbol = PT_getProductionRhs(PT_getTreeProd(tree));
   PT_Symbol accuSymbol = PT_getProductionRhs(PT_getTreeProd(accu));
   PT_Symbol layoutSymbol  = PT_makeSymbolCf(
                            PT_makeSymbolOpt(PT_makeSymbolLayout()));

   PT_Symbols lhs = PT_makeSymbolsList(
                      PT_makeSymbolLit("<"),
                    PT_makeSymbolsList(
                      layoutSymbol, 
                    PT_makeSymbolsList(
                      treeSymbol,
                    PT_makeSymbolsList(
                      layoutSymbol,
                    PT_makeSymbolsList(
                      PT_makeSymbolLit(","),
                    PT_makeSymbolsList(
                      layoutSymbol,
                    PT_makeSymbolsList(
                      accuSymbol,
                    PT_makeSymbolsList(
                      layoutSymbol,
                    PT_makeSymbolsList(
                      PT_makeSymbolLit(">"),
                    PT_makeSymbolsEmpty())))))))));
                       
   PT_Symbol rhs = PT_makeSymbolPair(treeSymbol, accuSymbol);
   PT_Attributes attrs = PT_makeAttributesNoAttrs();
   PT_Production prod = PT_makeProductionDefault(lhs,rhs,attrs);
                     
   PT_Tree layoutTree = PT_makeTreeLayoutEmpty();
   PT_Args args = PT_makeArgsList(
                    PT_makeTreeLit("<"),
		  PT_makeArgsList(
		    layoutTree, 
		  PT_makeArgsList(
		    tree,
		  PT_makeArgsList(
		    layoutTree,
		  PT_makeArgsList(
		    PT_makeTreeLit(","),
		  PT_makeArgsList(
		    layoutTree,
		  PT_makeArgsList(
		    accu,
		  PT_makeArgsList(
		    layoutTree,
		  PT_makeArgsList(
		    PT_makeTreeLit(">"),
		  PT_makeArgsEmpty())))))))));

   return PT_makeTreeAppl(prod,args);
}

/*}}}  */
/*{{{  PT_Tree chooseNormalform(PT_Tree term, Traversal traversal) */

/* chooseNormalform
 *
 * depending on the type of traversal, constructs a normal form.
 * This function is used after the toplevel traversal prod returns.
 */

PT_Tree chooseNormalform(PT_Tree term, Traversal traversal)
{
  switch (traversal.type) {
  case TRANSFORMER:
    /* we just return the term */
    break;
  case ACCUMULATOR:
    /* we only return the accumulated value */
    term = selectAccumulatedArg(traversal.args);
    break;
  case COMBINATION:
    term = makeTuple(term, selectAccumulatedArg(traversal.args));
    break;
  case UNDEFINED:
  default:
    ATerror("Unknown traversal type: %d", traversal.type);
    break;
  }

  return term;
}

/*}}}  */
