/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <aterm2.h>
#include <assert.h>
#include <deprecated.h>
#include "asfix_utils.h"
#include "asfe.h"
#include "traversals.h"

#include <MEPT-utils.h>
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

/*{{{  static PT_Attr isAttrTraversal(PT_Attr attr, PT_AttrVisitorData data) */

static PT_Attr isAttrTraversal(PT_Attr attr, PT_AttrVisitorData data)
{
  ATbool* bool;

  bool = (ATbool*) data;

  if (PT_isAttrTerm(attr)) {
    ATerm term = PT_getAttrTerm(attr);

    if (ATgetType(term) == AT_APPL) {
      char *fun = ATgetName(ATgetSymbol(term));

      if (!strcmp(fun,"traverse") ||
	  !strcmp(fun,"traversal")) {
	*bool = ATtrue;
      }
    }
  }

  return attr;
}

/*}}}  */
/*{{{  static PT_Attr getTraversalAttr(PT_Attr attr, PT_AttrVisitorData data) */

static PT_Attr getTraversalAttr(PT_Attr attr, PT_AttrVisitorData data)
{
  ATbool bool = ATfalse;
  PT_Attr* thisattr;

  thisattr = (PT_Attr*) data;

  isAttrTraversal(attr, (PT_AttrVisitorData)  &bool);

  if (bool) {
    *thisattr = attr;
  }

  return attr;
}

/*}}}  */

/*{{{  ATbool isTreeTraversal(PT_Tree trm) */

ATbool isTreeTraversal(PT_Tree trm)
{
  if (PT_hasTreeProd(trm)) {
    PT_Production prod = PT_getTreeProd(trm);
    
    if (PT_hasProductionAttributes(prod)) {
      PT_Attributes attributes = PT_getProductionAttributes(prod);

      if (PT_hasAttributesAttrs(attributes)) {
	PT_Attrs attrs = PT_getAttributesAttrs(attributes);
        ATbool data = ATfalse;

	PT_foreachAttrInAttrs(attrs, isAttrTraversal, 
			      (PT_AttrVisitorData*) &data);

        return data;
      }
    } 
  }

  return ATfalse;
}

/*}}}  */

/*{{{  static Traversal computeTraversalType(Traversal trav) */

static Traversal computeTraversalType(Traversal trav)
{
  PT_Symbol symbol;
  PT_Symbol cleanSymbol;

  symbol = PT_getProductionRhs(trav.prod);
  cleanSymbol = PT_getSymbolSymbol(symbol);

  if (PT_isEqualSymbol(trav.traversed, symbol)) {
    trav.type = TRANSFORMER;
  } 
  else if(trav.accumulated != NULL) {
    if(PT_isEqualSymbol(trav.accumulated, cleanSymbol)) {
      trav.type = ACCUMULATOR;
    }
    else if(trav.accumulated != NULL && PT_isSymbolPair(cleanSymbol)) {
      PT_Symbol lhs = PT_getSymbolLhs(cleanSymbol);
      PT_Symbol rhs = PT_getSymbolRhs(cleanSymbol);
      
      if (PT_isEqualSymbol(PT_getSymbolSymbol(trav.traversed),lhs) &&
	  PT_isEqualSymbol(trav.accumulated,rhs)) {
	trav.type = COMBINATION;
      }
    }
    
  }

  /* Warn about deprecated use of old traversal attribute */
  ATwarning("WARNING: using deprecated traversal syntax \"traverse\" "
            "in production:\n%s\n", PT_yieldProduction(trav.prod));

  switch(trav.type) {
    case TRANSFORMER:
      ATwarning("Please use \"traversal(trafo, top-down)\"\n");
      break;
    case ACCUMULATOR:
      ATwarning("Please use \"traversal(accu, top-down)\"\n");
      break;
    case COMBINATION:
       ATwarning("Please use \"traversal(accu,trafo,top-down)\"\n");
       break;
    case UNDEFINED_TYPE:
    default:
      RWsetError("Illegal traversal syntax in production.", 
  	         (ATerm) PT_makeTreeLit("")); 
       break;
  }

  return trav;
}

/*}}}  */

/*{{{  static ATbool checkTraversalType(Traversal trav) */

static ATbool checkTraversalType(Traversal trav)
{
  PT_Symbol symbol = PT_getProductionRhs(trav.prod);
  PT_Symbol cleanSymbol = PT_getSymbolSymbol(symbol);

  if (trav.type == TRANSFORMER) {
    if (!PT_isEqualSymbol(trav.traversed, symbol)) {
      RWsetError("First argument sort should be equal to result sort", 
		 (ATerm) PT_makeTreeLit(""));
      return ATfalse;
    }
  }
  else if (trav.type == ACCUMULATOR) {
    if (!PT_isEqualSymbol(trav.accumulated, cleanSymbol)) {
      RWsetError("Second argument sort should be equal to result sort", 
		 (ATerm) PT_makeTreeLit(""));
      return ATfalse;
    }
  }
  else if (trav.type == COMBINATION) {
    if (!PT_isSymbolPair(cleanSymbol)) {
      RWsetError("Result sort should be a tuple", (ATerm) PT_makeTreeLit("")); 
      return ATfalse;
    }
    else {
      PT_Symbol lhs = PT_getSymbolLhs(cleanSymbol);
      PT_Symbol rhs = PT_getSymbolRhs(cleanSymbol);

      if (!PT_isEqualSymbol(PT_getSymbolSymbol(trav.traversed),lhs)) {
	RWsetError("First argument sort should be equal to the first sort"
		  " of the tuple", (ATerm) PT_makeTreeLit(""));
        return ATfalse;
      }
      if (!PT_isEqualSymbol(trav.accumulated, rhs)) {
	RWsetError("Second argument sort should be equal to second sort"
		   "of the tuple", (ATerm) PT_makeTreeLit(""));
        return ATfalse;
      }
    }
  }
  else {
    return ATfalse;
  }

  return ATtrue;
}

/*}}}  */

/*{{{  static Traversal setTraversalTypeAndStrategy(PT_Production prod) */

static Traversal setTraversalTypeAndStrategy(Traversal trav)
{
  PT_Attributes attributes = PT_getProductionAttributes(trav.prod);

  trav.type = UNDEFINED_TYPE;
  trav.strategy = UNDEFINED_STRATEGY;

  if (PT_hasAttributesAttrs(attributes)) {
    PT_Attrs attrs = PT_getAttributesAttrs(attributes);
    PT_Attr attr = NULL;
    ATermList args;


    PT_foreachAttrInAttrs(attrs, getTraversalAttr, (PT_AttrVisitorData) &attr);

    args = ATgetArguments((ATermAppl) PT_getAttrTerm(attr));

    for(;!ATisEmpty(args);args = ATgetNext(args)) {
      ATerm arg = ATgetFirst(args);

      if (ATisEqual(ATparse("\"trafo\""),arg)) {
	if (trav.type == ACCUMULATOR || trav.type == COMBINATION) {
	  trav.type = COMBINATION;
	}
	else {
	  trav.type = TRANSFORMER;
	}
      }
      else if (ATisEqual(ATparse("\"accu\""), arg)) {
	if (trav.type == TRANSFORMER || trav.type == COMBINATION) {
	  trav.type = COMBINATION;
	}
	else {
	  trav.type = ACCUMULATOR;
	}
      }
      else if (ATisEqual(ATparse("\"bottom-up\""), arg)) {
	if (trav.strategy == TOPDOWN) {
	  RWsetError("Ambiguous traversal attribute in production.",
		     (ATerm) PT_makeTreeLit(PT_yieldProduction(trav.prod)));
	}
	else {
	  trav.strategy = BOTTOMUP;
	}
      }
      else if (ATisEqual(ATparse("\"top-down\""), arg)) {
	if (trav.strategy == BOTTOMUP) {
	  RWsetError("Ambiguous traversal attribute in production.",
		     (ATerm) PT_makeTreeLit(PT_yieldProduction(trav.prod)));
	}
	else {
	  trav.strategy = TOPDOWN;
	}
      }
      else if (ATisEqual(ATparse("\"generate-syntax\""), arg)) {
	; /* do nothing */
      }
      else {
	RWsetError("Unknown traversal specifier in production.",
		   (ATerm) PT_makeTreeLit(PT_yieldProduction(trav.prod)));
      }
    }
  }

  /* default strategy behaviour */
  if (trav.strategy == UNDEFINED_STRATEGY) {
    if (trav.type == UNDEFINED_TYPE) { /* old style traversals */
      trav.strategy = TOPDOWN;
    }
    else {
      trav.strategy = BOTTOMUP;
    }
  }

  return trav;
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
  PositionSymbolTuple symbolVisitorData;
  Traversal trav;

  trav.accumulated = NULL;
  trav.traversed = NULL;
  trav.prod = PT_getTreeProd(term);
  trav.args = PT_getTreeArgs(term);
  trav.symbols = PT_getProductionLhs(trav.prod);

  /* get the symbol of the traversed arg */
  symbolVisitorData.pos = TRAVERSED_SYMBOL_POS;
  symbolVisitorData.symbol = NULL;
  PT_foreachSymbolInSymbols(trav.symbols, getSymbol, 
                         (PT_SymbolVisitorData) &symbolVisitorData); 
  trav.traversed = symbolVisitorData.symbol;
  assert(trav.traversed != NULL);

  /* get the symbol of the accumulated arg */
  symbolVisitorData.pos = ACCUMULATED_SYMBOL_POS;
  symbolVisitorData.symbol = NULL;
  PT_foreachSymbolInSymbols(trav.symbols, getSymbol, 
                         (PT_SymbolVisitorData) &symbolVisitorData); 
 
  if (symbolVisitorData.symbol != NULL) {
    trav.accumulated = PT_getSymbolSymbol(symbolVisitorData.symbol);
  }
 
  trav = setTraversalTypeAndStrategy(trav);
  
  if (trav.type == UNDEFINED_TYPE) { /* backward compatibility */
    trav = computeTraversalType(trav);
  }

  if (!checkTraversalType(trav)) {
    trav.type = UNDEFINED_TYPE;
    trav.strategy = UNDEFINED_STRATEGY;
  }

  return trav;
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
  case UNDEFINED_TYPE:
  default:
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
  case UNDEFINED_TYPE:
  default:
    ATerror("Unknown traversal type: %d", traversal.type);
    break;
  }

  return term;
}

/*}}}  */

/*{{{  PT_Tree makeTraversalReduct(PT_Tree orig, PT_Tree rhs, Traversal* traversal) */

PT_Tree makeTraversalReduct(PT_Tree orig, PT_Tree rhs, Traversal* traversal)
{
  PT_Tree reduct;

  if (traversal->type == ACCUMULATOR) {
    *traversal = updateAccumulator(*traversal, rhs);
    reduct = orig;
  } 
  else if (traversal->type == COMBINATION) {
    *traversal = updateAccumulator(*traversal, getTupleSecond(rhs));
    reduct = getTupleFirst(rhs); 
  } 
  else {
    reduct = rhs;
  }

  return reduct;
}

/*}}}  */


