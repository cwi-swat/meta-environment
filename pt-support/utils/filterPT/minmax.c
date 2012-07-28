#include <MEPT-utils.h>
#include "minmax.h"

typedef unsigned long Count;

static ATbool minimize = ATfalse;
static PT_Symbol symbol = NULL;
static Count countAmbs = 0;

static PT_Tree minmaxTree(PT_Tree tree, Count *counter);

/*{{{  static void minmaxProd(PT_Production prod, Count *counter) */

static void minmaxProd(PT_Production prod, Count *counter)
{
  PT_Symbol rhs = PT_getProductionRhs(prod);

  if (PT_isEqualSymbol(rhs, symbol)) {
    *counter += 1;
  }
}

/*}}}  */

/*{{{  static PT_Args minmaxAmb(PT_Args ambs, Count *counter) */

static PT_Args minmaxAmb(PT_Args ambs, Count *counter)
{
  PT_Args newAmbs = PT_makeArgsEmpty();
  Count extreme = 0;

  for ( ; !PT_isArgsEmpty(ambs); ambs = PT_getArgsTail(ambs)) {
    PT_Tree arg = PT_getArgsHead(ambs);
    Count count = 0;

    arg = minmaxTree(arg, &count); 

    if (PT_isArgsEmpty(newAmbs)) {
      extreme = count;
      newAmbs = PT_makeArgsSingle(arg);
    }
    else {
      if (count == extreme) {
	newAmbs = PT_makeArgsMany(arg, newAmbs);
      }
      else {
	if (minimize && count < extreme) {
	  newAmbs = PT_makeArgsSingle(arg);
	  extreme = count;
	}
	else if (!minimize && count > extreme) {
	  newAmbs = PT_makeArgsSingle(arg);
	  extreme = count;
	}
      }
    }
  }

  *counter = extreme;

  /* reverse is not necessary, but we want to return the same
   * tree if we do nothing, such that we can check if anything
   * happened at all using the atdiff tool.
   */
  return PT_reverseArgs(newAmbs);
}

/*}}}  */
/*{{{  static PT_Args minmaxArgs(PT_Args args, Count *counter) */

static PT_Args minmaxArgs(PT_Args args, Count *counter)
{
  Count sum = 0;
  PT_Args newArgs = PT_makeArgsEmpty();

  for ( ; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
    PT_Tree arg = PT_getArgsHead(args);
    Count count = 0;

    arg = minmaxTree(arg, &count); 
    sum += count;
    newArgs = PT_makeArgsMany(arg, newArgs);
  }

  *counter = sum;
  return PT_reverseArgs(newArgs);
}

/*}}}  */
/*{{{  static PT_Tree minmaxTree(PT_Tree tree, Count *counter) */

static PT_Tree minmaxTree(PT_Tree tree, Count *counter)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Args args = PT_getTreeArgs(tree);
    args = minmaxArgs(args, counter);
    minmaxProd(prod, counter);
    return PT_setTreeArgs(tree, args);
  }
  else if (PT_isTreeAmb(tree)) {
    PT_Args ambs = PT_getTreeArgs(tree);
    ambs = minmaxAmb(ambs, counter);
    if (PT_getArgsLength(ambs) == 1) {
      return PT_getArgsHead(ambs);
    }
    else {
      countAmbs++;
      return PT_setTreeArgs(tree, ambs);
    }
  }
  else {
    return tree;
  }
}

/*}}}  */

/*{{{  PT_ParseTree minmax(PT_ParseTree input, ATbool minimizeInsteadOfMaximize) */

PT_ParseTree minmax(PT_ParseTree input, PT_Symbol sort,
		    ATbool minimizeInsteadOfMaximize)
{
  PT_Tree top = PT_getParseTreeTop(input);
  Count count = 0;
  minimize = minimizeInsteadOfMaximize;
  symbol = sort;
  countAmbs = 0;

  top = minmaxTree(top, &count);

  return PT_makeParseTreeTop(top, countAmbs);
}

/*}}}  */
