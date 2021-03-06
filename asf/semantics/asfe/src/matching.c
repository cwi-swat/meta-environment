/* $Id$ */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <asc-ambiguity.h>

#include "evaluator.h"
#include "matching.h"
#include "reduction.h" 
#include "environment.h"
#include "values.h"
#include "traversalfunctions.h"
#include "debug.h"
#include "errors.h"

/* This algorithm matches a term against an ASF equation.
 *
 * Because list matching requires backtracking, the algorithm is modelled in 
 * a specific manner. Backtracking is achieved by using the C stack. Care is 
 * taken that every choicepoint is still on the stack. 
 * This is done by making ONLY TAIL CALLS to the other functions.
 * There is only one choicepoint (where the length of a slice is decided) that
 * loops while the rest of the match fails.
 */


ATerm matchCondition(ASF_ASFCondition cond, ASF_ASFConditionList conds, ATerm env, int depth);

static ATerm matchNegativeCondition(ASF_ASFCondition cond,
				    PT_Tree lhs, PT_Tree rhs, 
				    ASF_ASFConditionList conds,
				    ATerm env, 
				    int depth);

static ATerm matchArguments(ATerm env, ASF_ASFConditionList conds,
			    PT_Args args1, PT_Args args2, 
			    ATerm lhs_posinfo, int depth);

static ATerm matchListVariable(ATerm env, PT_Tree listvar,
		  PT_Production listProd, PT_Args elems1, PT_Args elems2,
		  ASF_ASFConditionList conds,
		  PT_Args args1, PT_Args args2,
		  ATerm lhs_posinfo, int depth);

static ATerm matchList(ATerm env, PT_Production listProd,
		       ATbool skipLayout,
		       PT_Args elems1, PT_Args elems2,
		       ASF_ASFConditionList conds, 
		       PT_Args args1, PT_Args args2,
		       ATerm lhs_posinfo, int depth);

static ATerm matchArgument(ATerm env, 
			   PT_Tree arg1, PT_Tree arg2,
			   ASF_ASFConditionList conds,
			   PT_Args orgargs1, PT_Args orgargs2,
			   ATerm lhs_posinfo, int depth);



static ATerm matchEqualityCondition(ASF_ASFCondition cond, PT_Tree lhs, PT_Tree rhs, ASF_ASFConditionList conds, ATerm env, int depth) {
  PT_Tree lhstrm, rhstrm;
  equation_entry *cur = currentRule;

  /* assuming that none of the sides introduce new variables */

  TIDE_STEP(lhs, env, depth);
  lhstrm = rewriteInnermost(lhs, env, depth + 1, NO_TRAVERSAL);

  if (!lhstrm) {
    return fail_env;
  }

  TIDE_STEP(rhs, env, depth);
  rhstrm = rewriteInnermost(rhs, env, depth + 1, NO_TRAVERSAL);

  if (!rhstrm) {
    return fail_env;
  }

  currentRule = cur;
  TIDE_STEP((PT_Tree) cond, env, depth);
  if (isAsFixEqual(lhstrm, rhstrm)) {
    return matchConditions(conds, env, depth);
  }

  return fail_env;
}


static ATerm matchNegativeCondition(ASF_ASFCondition cond, PT_Tree lhs, PT_Tree rhs, ASF_ASFConditionList conds, ATerm env, int depth) {
  PT_Tree lhstrm, rhstrm;
  equation_entry *cur = currentRule;

  /* assuming that none of the sides introduce new variables */

  TIDE_STEP(lhs, env, depth);
  lhstrm = rewriteInnermost(lhs, env, depth + 1, NO_TRAVERSAL);

  if (!lhstrm) {
    return fail_env;
  }

  TIDE_STEP(rhs, env, depth);
  rhstrm = rewriteInnermost(rhs, env, depth + 1, NO_TRAVERSAL);

  if (!rhstrm) {
    return fail_env;
  }

  currentRule = cur;
  TIDE_STEP((PT_Tree) cond, env, depth);
  if (isAsFixEqual(lhstrm, rhstrm)) {
    return fail_env;
  }

  return matchConditions(conds, env, depth);
}


static ATerm matchMatchCondition(ASF_ASFCondition cond, PT_Tree lhs, PT_Tree rhs, ASF_ASFConditionList conds, ATerm env, int depth) {
  PT_Tree rhstrm = NULL;
  equation_entry *cur = currentRule;

  TIDE_STEP(rhs, env, depth);
  rhstrm = rewriteInnermost(rhs, env, depth + 1, NO_TRAVERSAL);

  if (!rhstrm) {
    return fail_env;
  }

  currentRule = cur;
  TIDE_STEP((PT_Tree) cond, env, depth);

  env = matchArgument(env, lhs, rhstrm, conds, 
		      PT_makeArgsEmpty(), PT_makeArgsEmpty(), 
		      NULL, depth);


  return env;
}


static ATerm matchNoMatchCondition(ASF_ASFCondition cond, PT_Tree lhs, PT_Tree rhs, ASF_ASFConditionList conds,  ATerm env, int depth) {
  PT_Tree rhstrm = NULL;
  ATerm oldEnv = env;
  ATerm result = fail_env;
  equation_entry *cur = currentRule;

  TIDE_STEP(rhs, env, depth);
  rhstrm = rewriteInnermost(rhs, env, depth + 1, NO_TRAVERSAL);

  if (!rhstrm) {
    return fail_env;
  }

  TIDE_STEP(lhs, env, depth);
  result = matchArgument(env, lhs, rhstrm, NULL, 
			 PT_makeArgsEmpty(), PT_makeArgsEmpty(), 
			 NULL, depth);

  currentRule = cur;
  TIDE_STEP((PT_Tree) cond, result, depth);

  if (is_fail_env(result)) {
    return matchConditions(conds, oldEnv, depth);
  }
  else {
    return fail_env;
  }
}



ATerm matchCondition(ASF_ASFCondition cond, ASF_ASFConditionList conds, ATerm env, int depth) {
  PT_Tree lhs = ASFtoPT(ASF_getASFConditionLhs(cond));
  PT_Tree rhs = ASFtoPT(ASF_getASFConditionRhs(cond));

  if (ASF_isASFConditionMatch(cond)) {
    return matchMatchCondition(cond, lhs, rhs, conds, env, depth);
  }
  else if (ASF_isASFConditionEquality(cond)) {
    return matchEqualityCondition(cond, lhs, rhs, conds, env, depth);
  }
  else if (ASF_isASFConditionNegative(cond)) {
    return matchNegativeCondition(cond, lhs, rhs, conds, env, depth);
  }
  else {
    return matchNoMatchCondition(cond, lhs, rhs, conds, env, depth);
  }
}

ATerm matchConditions(ASF_ASFConditionList conds, ATerm env, int depth) {
  ASF_ASFCondition cond;
  ATerm newenv = env;

  if (conds == NULL) {
    return env;
  }

  if (ASF_hasASFConditionListHead(conds)) {
    cond = ASF_getASFConditionListHead(conds);

    if (ASF_hasASFConditionListTail(conds)) {
      conds = ASF_getASFConditionListTail(conds);
    }
    else {
      conds = NULL;
    }

    newenv = matchCondition(cond, conds, env, depth);

  }

  return newenv;
}


static ATerm matchList(ATerm env, PT_Production listProd, ATbool skipWhitespace,PT_Args elems1, PT_Args elems2, ASF_ASFConditionList conds, PT_Args args1, PT_Args args2, ATerm lhs_posinfo, int depth) {
  PT_Tree elem1;
  ATerm newenv = fail_env;

  if (skipWhitespace || PT_isArgsEmpty(elems2)) {
    elems1 = skipWhitespaceAndSeparator(elems1,listProd);
    elems2 = skipWhitespaceAndSeparator(elems2,listProd);
  }

  if (PT_isArgsEmpty(elems1) && PT_isArgsEmpty(elems2)) {
    newenv = matchArguments(env, conds, args1, args2, lhs_posinfo, depth);
  }
  else {
    if (PT_hasArgsHead(elems1)) {
      elem1 = PT_getArgsHead(elems1);
      elems1 = PT_getArgsTail(elems1);
      
      if (PT_isTreeVarList(elem1)) {
	Slice slice = getListVariableValue(env, elem1);
	if (slice != NULL) {
	  newenv = matchList(env, listProd, 
			     PT_isTreeVarListStar(elem1),
			     prependSlice(slice, elems1), 
			     elems2, conds,
			     args1, args2,
			     lhs_posinfo, depth);
	}
	else {
	  newenv = matchListVariable(env, elem1, 
				     listProd, elems1, elems2,
				     conds, args1, args2, 
				     lhs_posinfo, depth);
	}
      }
      else {
	if (PT_hasArgsHead(elems2)) {
	  PT_Tree elem2 = PT_getArgsHead(elems2);
	  elems2 = PT_getArgsTail(elems2); 

	  newenv=  matchArgument(env, elem1, elem2, conds,
				 addElemsToArgs(listProd, elems1, args1),
				 addElemsToArgs(listProd, elems2, args2),
				 lhs_posinfo, depth);
	}
      }
    }
  }

  return newenv;
}



/* Tries different sizes for a single list variable. */
static ATerm matchListVariable(ATerm env, PT_Tree listvar, PT_Production listProd, PT_Args elems1, PT_Args elems2, ASF_ASFConditionList conds, PT_Args args1, PT_Args args2, ATerm lhs_posinfo, int depth) {
  ATerm newenv = fail_env;
  PT_Args last;
  ATbool skipLayout = ATfalse;

  if (PT_isTreeVarListStar(listvar)) {
    skipLayout = ATtrue;
    last = elems2;
  }
  else {
    if (PT_hasArgsHead(elems2)) {
      last = PT_getArgsTail(skipWhitespaceAndSeparator(elems2, listProd));
    }
    else {
      return fail_env;
    }
  }

  while (is_fail_env(newenv)) {
    newenv = putListVariableValue(env, listvar, elems2, last);

    newenv = matchList(newenv, listProd, skipLayout,
		       elems1, last,
		       conds, args1, args2,
		       lhs_posinfo, depth);

    if (PT_hasArgsHead(last)) {
      last = PT_getArgsTail(skipWhitespaceAndSeparator(last, listProd));
    }
    else {
      break;
    }

  }

  return newenv;
}


static ATerm matchArguments(ATerm env, ASF_ASFConditionList conds, PT_Args args1, PT_Args args2, ATerm lhs_posinfo, int depth) {
  PT_Tree arg1, arg2;
  ATerm newenv = env;

  assert(PT_getArgsLength(args1) == PT_getArgsLength(args2) &&
	 "if prods are equal, then the number of arguments should be too");

  if (PT_hasArgsHead(args1)) {
    arg1 = PT_getArgsHead(args1);
    args1 = PT_getArgsTail(args1);
    arg2 = PT_getArgsHead(args2);
    args2 = PT_getArgsTail(args2);

    newenv = matchArgument(newenv, arg1, arg2, conds, args1, args2, 
			   lhs_posinfo, depth);
  }
  else {
    if (lhs_posinfo) {
      TIDE_STEP(lhs_posinfo, newenv, depth);
    }

    newenv = matchConditions(conds, newenv, depth);
  }

  return newenv;
}


static ATerm matchVariable(ATerm env, PT_Tree var, PT_Tree arg2, ASF_ASFConditionList conds, PT_Args orgargs1, PT_Args orgargs2, ATerm lhs_posinfo, int depth) {
  PT_Tree trm = getVariableValue(env, var);
  ATerm newenv = fail_env;


  if (trm != NULL) {
    if (isAsFixEqual(arg2, trm)) {
      newenv = matchArguments(env, conds, orgargs1, orgargs2,
			      lhs_posinfo, depth);
    }
    else {
      newenv = fail_env;
    }
  }
  else {
    if (PT_isTreeChar(arg2)) {
      PT_Production prod = PT_getTreeProd(var);
      PT_Symbol type = PT_getProductionRhs(prod);

      if (PT_isSymbolCharClass(type)) {
	if (!PT_elementOfCharClass(arg2, type)) {
	  return fail_env;
	}
      }
      else {
	return fail_env;
      }
    }

    newenv = putVariableValue(env, var, arg2);
    newenv = matchArguments(newenv, conds, orgargs1, orgargs2, lhs_posinfo, 
			    depth);
  }

  return newenv;
}


static ATerm matchAppl(ATerm env, PT_Tree arg1, PT_Tree arg2, ASF_ASFConditionList conds, PT_Args orgargs1, PT_Args orgargs2, ATerm lhs_posinfo, int depth) {
  PT_Production prod1 = PT_getTreeProd(arg1);
  PT_Production prod2 = PT_getTreeProd(arg2);
  ATerm newenv;

  /*ATwarning("MATCH?:\n\t%t\n\t\%t\n", prod1, prod2);*/

  if (PT_isEqualProduction(prod1, prod2)) {
    PT_Args args1 = PT_getTreeArgs(arg1);
    PT_Args args2 = PT_getTreeArgs(arg2);

    /*ATwarning("RECURRING\n");*/
    newenv = matchArguments(env, conds, 
			    PT_concatArgs(args1, orgargs1),
			    PT_concatArgs(args2, orgargs2),
			    lhs_posinfo, depth);
  }
  else {
    /*ATwarning("NO MATCH!:\n\t%t\n\t\%t\n", prod1, prod2);*/
    newenv = fail_env;
  }

  return newenv;
}


static ATerm matchArgument(ATerm env, PT_Tree arg1, PT_Tree arg2,  ASF_ASFConditionList conds, PT_Args orgargs1, PT_Args orgargs2, ATerm lhs_posinfo, int depth) {
  ATerm newenv = fail_env;

    /*TIDE_STEP(arg1, env, depth);*/

  if (depth > MAX_DEPTH / 2) {
    char tmp[256];
    sprintf(tmp, "maximum stack depth during matching (%d) exceeded.", 
	    MAX_DEPTH / 2);
    RWaddDoubleLocatedError(tmp, 
			    PT_yieldTree(arg1), PT_getTreeLocation(arg1),
			    PT_yieldTree(arg2), PT_getTreeLocation(arg2));
    return fail_env;
  }

  /* equality check is cheap, so try this first */
  if (arg1 == arg2) {
    newenv = matchArguments(env, conds, orgargs1, orgargs2, lhs_posinfo, depth);
  }
  else if (PT_isTreeLit(arg1) || PT_isTreeCilit(arg1)) {
    /* Literals always match */
    newenv = matchArguments(env, conds, orgargs1, orgargs2, lhs_posinfo, depth);
  }
  else if (PT_isTreeApplList(arg1) &&
	   PT_isTreeApplList(arg2)) {
    PT_Args elems1 = PT_getTreeArgs(arg1);
    PT_Args elems2 = PT_getTreeArgs(arg2);
    PT_Production prod1 = PT_getTreeProd(arg1);

    newenv = matchList(env, prod1, ATfalse,
		       elems1, elems2, conds, orgargs1, orgargs2, 
		       lhs_posinfo, depth);
  }
  else if (PT_isTreeVar(arg1)) {
    newenv = matchVariable(env, arg1, arg2, conds, orgargs1, orgargs2,
			   lhs_posinfo, depth);
  }
  else if (PT_isTreeAppl(arg1)) {
    assert(!PT_isTreeLit(arg1));

    if (PT_isTreeAmb(arg2)) {
      arg2 = ASC_ambToConstructor(arg2);
    }

    newenv = matchAppl(env, arg1, arg2, conds, orgargs1, orgargs2,
		       lhs_posinfo, depth);
  }
  else if (PT_isTreeCycle(arg1)) {
    /* we assume here cycles are always the same, which does
     * not influence anything since a cycle never has any
     * characters as child
     */
    if (PT_isTreeCycle(arg2)) {
      return newenv;
    }
    else {
      return fail_env;
    }
  }

  return newenv;
}


ATerm matchEquation(equation_entry *entry, PT_Tree trm, int depth) {
  /*ATwarning("trying %s\n", PT_yieldTree(entry->equation));*/
  return matchArgument((ATerm) ATempty, entry->lhs, trm, entry->conds,
		       PT_makeArgsEmpty(), PT_makeArgsEmpty(),
		       PT_TreeToTerm(entry->lhs), depth);
}

