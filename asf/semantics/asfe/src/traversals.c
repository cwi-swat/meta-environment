/*

    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
/*
  $Id$
 */

#include <stdio.h>
#include <stdlib.h>
#include <aterm2.h>
#include <assert.h>
#include <deprecated.h>
#include "asfix_utils.h"
#include "asfe.h"
#include "traversals.h"

typedef struct PositionSymbolTuple_tag {
  int pos;
  PT_Symbol symbol;
} PositionSymbolTuple;

typedef struct PositionTreeTuple_tag {
  int pos;
  PT_Tree tree;
} PositionTreeTuple;

extern ATbool run_verbose;

/* first we define a number of visitors for Tree and Symbol */
PT_Symbol getSymbol(PT_Symbol symbol, PT_SymbolVisitorData data)
{
  if (((PositionSymbolTuple*)data)->pos == 0) {
    ((PositionSymbolTuple*)data)->symbol = symbol;
  }

  ((PositionSymbolTuple*)data)->pos--;
 
  return symbol;
}

PT_Symbol replaceSymbol(PT_Symbol symbol, PT_SymbolVisitorData data)
{
  if (((PositionSymbolTuple*)data)->pos == 0) {
    symbol = ((PositionSymbolTuple*)data)->symbol;
  }

  ((PositionSymbolTuple*)data)->pos--;
  return symbol;
}

PT_Tree getTree(PT_Tree tree, PT_TreeVisitorData data)
{
  if (((PositionSymbolTuple*)data)->pos == 0) {
    ((PositionTreeTuple*)data)->tree = tree;
  }

  ((PositionTreeTuple*)data)->pos--;

  return tree;
}

PT_Tree replaceTree(PT_Tree tree, PT_TreeVisitorData data)
{
  if (((PositionTreeTuple*)data)->pos == 0) {
    tree = ((PositionTreeTuple*)data)->tree;
  }

  ((PositionTreeTuple*)data)->pos--;
  return tree;
}

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

/* create_traversal_pattern
 *
 * input: a PT_TreeAppl
 * output: a Traversal struct, containing the original traversal term
 *         and an indication if it is a transformer or an analyzer.
 * 
 */
Traversal
createTraversalPattern(PT_Tree term)
{
  PT_Production prod;
  PT_Args args;
  PT_Symbols symbols;
  PT_Symbol symbol;
  PT_Symbol traversed;
  PositionSymbolTuple symbolVisitorData;
  Traversal traversal;

  prod = PT_getTreeProd(term);
  args = PT_getTreeArgs(term);

  symbols = PT_getProductionLhs(prod);
  symbol = PT_getProductionRhs(prod);

  /* get the symbol of the traversed arg */
  symbolVisitorData.pos = TRAVERSED_SYMBOL_POS;
  symbolVisitorData.symbol = NULL;
  PT_foreachSymbolInSymbols(symbols, getSymbol, 
                         (PT_SymbolVisitorData) &symbolVisitorData); 
  traversed = symbolVisitorData.symbol;
  assert(traversed != NULL);
 
  traversal.type = PT_isEqualSymbol(traversed, symbol) ? TRANSFORMER : ANALYZER;
  traversal.prod = prod;
  traversal.args = args;
  traversal.symbols = symbols;

  return traversal;
}



/* make_traversal_appl
 *
 * input: an appl and a traversal pattern (made by create_traversal_patten)
 * output: the traversal pattern instantiated by the symbol and the term 
 *         of the first argument.
 */
PT_Tree
makeTraversalAppl(PT_Tree appl, Traversal traversal)
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

  if (traversal.type == TRANSFORMER) {
    prod = PT_setProductionRhs(prod, symbol);
  }

  newappl = PT_setTreeProd(appl, prod);
  newappl = PT_setTreeArgs(newappl, args);

  return newappl;
}

/* update_accumulator
 *
 * Changes the second argument of the traversal pattern. This is used
 * as a value environment for traversals.
 */
Traversal
updateAccumulator(Traversal traversal, PT_Tree newarg)
{
  PositionTreeTuple data;
  data.pos = ACCUMULATED_ARG_POS;
  data.tree = newarg;

  assert(traversal.type == ANALYZER);

  traversal.args = PT_foreachTreeInArgs(traversal.args, replaceTree,
                                     (PT_TreeVisitorData) &data);

  return traversal;
}

/* chooseNormalform
 *
 * depending on the type of traversal, constructs a normal form.
 * This function is used after the toplevel traversal prod returns.
 */
PT_Tree
chooseNormalform(PT_Tree term, Traversal traversal)
{
  switch (traversal.type) {
  case TRANSFORMER:
    /* we just return the term */
    break;
  case ANALYZER:
    /* we only return the accumulated value */
    term = selectAccumulatedArg(traversal.args);
    break;
  default:
    ATerror("Unknown traversal type");
    break;
  }

  return term;
}
