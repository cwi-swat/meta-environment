/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <aterm2.h>
#include <assert.h>

#include "asc-traversals.h"

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

/*{{{  PT_Symbol replaceSymbol(PT_Symbol symbol, PT_SymbolVisitorData data) */

static PT_Symbol replaceSymbol(PT_Symbol symbol, PT_SymbolVisitorData data)
{
  if (((PositionSymbolTuple*)data)->pos == 0) {
    symbol = ((PositionSymbolTuple*)data)->symbol;
  }

  ((PositionSymbolTuple*)data)->pos--;
  return symbol;
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

/*{{{  static TraversalType computeType(PT_Production prod) */

static TraversalType computeType(PT_Production prod)
{
  PT_Attributes attributes = PT_getProductionAttributes(prod);
  TraversalType type = UNDEFINED_TYPE; 

  if (PT_hasAttributesAttrs(attributes)) {
    PT_Attrs attrs = PT_getAttributesAttrs(attributes);
    PT_Attr attr = NULL;
    ATermList args;

    PT_foreachAttrInAttrs(attrs, getTraversalAttr, (PT_AttrVisitorData) &attr);

    args = ATgetArguments((ATermAppl) PT_getAttrTerm(attr));

    for(;!ATisEmpty(args);args = ATgetNext(args)) {
      ATerm arg = ATgetFirst(args);

      if (ATisEqual(ATparse("trafo"),arg)) {
	if (type == ACCUMULATOR || type == COMBINATION) {
	  type = COMBINATION;
	}
	else {
	  type = TRANSFORMER;
	}
      }
      else if (ATisEqual(ATparse("accu"), arg)) {
	if (type == TRANSFORMER || type == COMBINATION) {
	  type = COMBINATION;
	}
	else {
	  type = ACCUMULATOR;
	}
      }
    }
  }

  return type;
}

/*}}}  */

/*{{{  PT_Tree transformTraversalFunction(PT_Tree tree) */

PT_Tree ASC_transformTraversalFunction(PT_Tree tree)
{
  PT_Production prod;
  PT_Symbols symbols;
  TraversalType type;
  PositionSymbolTuple symbolVisitorData;

  prod = PT_getTreeProd(tree);
  type = computeType(prod);

  /* replace the traversed symbol by a generic one */
  symbols = PT_getProductionLhs(prod);
  symbolVisitorData.pos = TRAVERSED_SYMBOL_POS;
  symbolVisitorData.symbol = PT_makeSymbolSort(GEN_TRAVERSED_SORT);
  symbols = PT_foreachSymbolInSymbols(symbols, replaceSymbol, 
				  (PT_SymbolVisitorData) &symbolVisitorData);

  prod = PT_setProductionLhs(prod, symbols);

  /* replace the right-hand side accordingly */  
  if (type == TRANSFORMER) {
    prod = PT_setProductionRhs(prod, PT_makeSymbolSort(GEN_TRAVERSED_SORT));
  }
  else if (type == COMBINATION) {
    PT_Symbol rhs = PT_getSymbolSymbol(PT_getProductionRhs(prod));
    PT_Symbols accu = PT_getSymbolRest(rhs);
    prod = PT_setProductionRhs(prod, PT_makeSymbolCf(
                                     PT_makeSymbolTuple(
                                     PT_makeSymbolSort(GEN_TRAVERSED_SORT),
                                     accu)));
  }
  return PT_setTreeProd(tree, prod);
}

/*}}}  */
