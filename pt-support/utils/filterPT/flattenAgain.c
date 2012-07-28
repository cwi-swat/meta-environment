#include <MEPT-utils.h>

/* flattens filtered AsFix2ME parse forests. After filtering you
 * can end up with nested lists that should have been flattened!
 */

static PT_Tree flattenTreeAgain(PT_Tree tree);


/*{{{  static PT_Args flattenListAgain(PT_Production prod, PT_Args elems) */

static PT_Args flattenListAgain(PT_Production prod, PT_Args elems)
{
  PT_Args newElems = PT_makeArgsEmpty();

  for ( ; !PT_isArgsEmpty(elems); elems = PT_getArgsTail(elems)) {
    PT_Tree arg = PT_getArgsHead(elems);

    if (PT_hasTreeProd(arg)) {
      ATbool nested = ATfalse;
      PT_Production argProd = PT_getTreeProd(arg);

      if (PT_isEqualProduction(prod, argProd)) {
	nested = ATtrue;
      }
      else if (PT_isProductionList(argProd)) {
	PT_Symbol rhs = PT_getProductionRhs(prod);
	PT_Symbol rhsArg = PT_getProductionRhs(argProd);

	if (PT_isSymbolCf(rhs) || PT_isSymbolLex(rhs)) {
	  rhs = PT_getSymbolSymbol(rhs);
	}

	if (PT_isSymbolCf(rhsArg) || PT_isSymbolLex(rhsArg)) {
	  rhsArg = PT_getSymbolSymbol(rhsArg);
	}

	if (PT_isSymbolIterStar(rhs) 
	    && PT_isSymbolIterPlus(rhsArg) 
	    && PT_isEqualSymbol(PT_getSymbolSymbol(rhs),
				PT_getSymbolSymbol(rhsArg))) {
	nested = ATtrue;
	}
      }

      if (nested) {	
	PT_Args nestedElems = PT_getTreeArgs(arg);
	newElems = PT_concatArgs(PT_reverseArgs(nestedElems), newElems);
	continue;
      }
    }
    
    newElems = PT_makeArgsMany(arg, newElems);
  }

  return PT_reverseArgs(newElems);
}

/*}}}  */
/*{{{  static PT_Args flattenArgsAgain(PT_Args args) */

static PT_Args flattenArgsAgain(PT_Args args)
{
  PT_Args newArgs = PT_makeArgsEmpty();

  for ( ; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
    PT_Tree arg = PT_getArgsHead(args);
    newArgs = PT_makeArgsMany(flattenTreeAgain(arg), newArgs);
  }

  return PT_reverseArgs(newArgs);
}

/*}}}  */
/*{{{  static PT_Tree flattenTreeAgain(PT_Tree tree) */

static PT_Tree flattenTreeAgain(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Args args = PT_getTreeArgs(tree);

    args = flattenArgsAgain(args);

    if (PT_isProductionList(prod)) {
      args = flattenListAgain(prod, args);
    }

    return PT_setTreeArgs(tree, args);
  }
  else if (PT_isTreeAmb(tree)) {
    PT_Args ambs = PT_getTreeArgs(tree);
    ambs = flattenArgsAgain(ambs);
    return PT_setTreeArgs(tree, ambs);
  }

  return tree;
}

/*}}}  */

/*{{{  PT_ParseTree flattenAgain(PT_ParseTree input) */

PT_ParseTree flattenAgain(PT_ParseTree input)
{
  PT_Tree top = PT_getParseTreeTop(input);

  top = flattenTreeAgain(top);

  return PT_setParseTreeTop(input, top);
}

/*}}}  */
