#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "evaluator.h"
#include "matching.h"
#include "reduction.h" 
#include "environment.h"
#include "values.h"
#include "traversalfunctions.h"
#include "debug.h"
#include "errors.h"

/*
#ifdef USE_TIDE
#include "debug.h"
#endif
*/

/* This algorithm matches a term against an ASF equation.
 *
 * Because list matching requires backtracking, the algorithm is modelled in 
 * a specific manner. Backtracking is achieved by using the C stack. Care is 
 * taken that every choicepoint is still on the stack. 
 * This is done by making ONLY TAIL CALLS to the other functions.
 * There is only one choicepoint (where the length of a slice is decided) that
 * loops while the rest of the match fails.
 */

/*{{{  local function declarations */

ATerm matchCondition(ASF_ASFCondition cond, ASF_ASFConditionList conds,
			    ATerm env, int depth);
static ATerm matchNegativeCondition(ASF_ASFCondition cond,
				    PT_Tree lhs, PT_Tree rhs, 
				    ASF_ASFConditionList conds,
				    ATerm env, 
				    int depth);
static ATerm matchPositiveCondition(ASF_ASFCondition cond,
				    PT_Tree lhs, PT_Tree rhs, 
				    ASF_ASFConditionList conds,
				    ATerm env, int depth);
static ATerm matchArguments(ATerm env, ASF_ASFConditionList conds,
			    PT_Args args1, PT_Args args2, 
			    ATerm lhs_posinfo, int depth);
static ATerm matchListVariable(ATerm env, PT_Tree listvar,
		  PT_Production listProd, PT_Args elems1, PT_Args elems2,
		  ASF_ASFConditionList conds,
		  PT_Args args1, PT_Args args2,
		  ATerm lhs_posinfo, int depth);
static ATerm matchList(ATerm env, PT_Production listProd,
		       PT_Args elems1, PT_Args elems2,
		       ASF_ASFConditionList conds, 
		       PT_Args args1, PT_Args args2,
		       ATerm lhs_posinfo, int depth);
static ATerm matchArgument(ATerm env, 
			   PT_Tree arg1, PT_Tree arg2,
			   ASF_ASFConditionList conds,
			   PT_Args orgargs1, PT_Args orgargs2,
			   ATerm lhs_posinfo, int depth);

/*}}}  */

/* Retrieve the sign (= or !=) part of a condition as a term.
 * Note that this function uses MEPT specific knowledge because
 * apigen is not good enough (yet) to generate getters for literals!
 *
 * This function is only used to make it possible to retrieve the
 * position information of the sign for debugging using tide!
 */

/*{{{  ATerm getConditionSign(ASF_ASFCondition cond) */

ATerm getConditionSign(ASF_ASFCondition cond)
{
  PT_Tree tree = PT_TreeFromTerm(ASF_ASFConditionToTerm(cond));

  PT_Args args = PT_getTreeArgs(tree);
  PT_Tree sign = PT_getArgsHead(PT_getArgsTail(PT_getArgsTail(args)));

  return PT_TreeToTerm(sign);
}

/*}}}  */

/*{{{  static ATerm matchEqualityCondition(ASF_ASFCondition cond, */

static ATerm matchEqualityCondition(ASF_ASFCondition cond,
				    PT_Tree lhs, PT_Tree rhs, 
				    ASF_ASFConditionList conds,
				    ATerm env, 
				    int depth)
{
  PT_Tree lhstrm, rhstrm;

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

  TIDE_STEP(getConditionSign(cond), env, depth);
  if (isAsFixEqual(lhstrm, rhstrm)) {
    return matchConditions(conds, env, depth);
  }

  return fail_env;
}

/*}}}  */
/*{{{  static ATerm matchNegativeCondition(PT_Tree lhs, PT_Tree rhs,  */

static ATerm matchNegativeCondition(ASF_ASFCondition cond,
				    PT_Tree lhs, PT_Tree rhs, 
				    ASF_ASFConditionList conds,
				    ATerm env, 
				    int depth)
{
  PT_Tree lhstrm, rhstrm;

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

  TIDE_STEP(getConditionSign(cond), env, depth);
  if (isAsFixEqual(lhstrm, rhstrm)) {
    return fail_env;
  }

  return matchConditions(conds, env, depth);
}

/*}}}  */
/*{{{  static ATerm matchMatchCondition(ASF_ASFCondition cond, PT_Tree lhs, PT_Tree rhs,  */

static ATerm matchMatchCondition(ASF_ASFCondition cond, PT_Tree lhs, PT_Tree rhs, 
				    ASF_ASFConditionList conds,
				    ATerm env, int depth)
{
  PT_Tree rhstrm = NULL;

  TIDE_STEP(rhs, env, depth);
  rhstrm = rewriteInnermost(rhs, env, depth + 1, NO_TRAVERSAL);

  if (!rhstrm) {
    return fail_env;
  }

  TIDE_STEP(lhs, env, depth);
  env = matchArgument(env, lhs, rhstrm, conds, 
		      PT_makeArgsEmpty(), PT_makeArgsEmpty(), 
		      NULL, depth);

  TIDE_STEP(getConditionSign(cond), env, depth);

  if (!is_fail_env(env)) {
    return matchConditions(conds, env, depth);
  }
  else {
    return fail_env;
  }
}

/*}}}  */
/*{{{  static ATerm matchNoMatchCondition(ASF_ASFCondition cond, PT_Tree lhs, PT_Tree rhs,  */

static ATerm matchNoMatchCondition(ASF_ASFCondition cond, PT_Tree lhs, PT_Tree rhs, 
				    ASF_ASFConditionList conds,
				    ATerm env, int depth)
{
  PT_Tree rhstrm = NULL;
  ATerm oldEnv = env;
  ATerm result = fail_env;

  TIDE_STEP(rhs, env, depth);
  rhstrm = rewriteInnermost(rhs, env, depth + 1, NO_TRAVERSAL);

  if (!rhstrm) {
    return fail_env;
  }

  TIDE_STEP(lhs, env, depth);
  result = matchArgument(env, lhs, rhstrm, conds, 
			 PT_makeArgsEmpty(), PT_makeArgsEmpty(), 
			 NULL, depth);

  TIDE_STEP(getConditionSign(cond), result, depth);

  if (is_fail_env(result)) {
    return matchConditions(conds, oldEnv, depth);
  }
  else {
    return fail_env;
  }
}

/*}}}  */
/* deprecated syntax "=", still supported for now but will dissappear */
/*{{{  static ATerm matchPositiveCondition(PT_Tree lhs, PT_Tree rhs,  */

static ATerm matchPositiveCondition(ASF_ASFCondition cond, PT_Tree lhs, PT_Tree rhs, 
				    ASF_ASFConditionList conds,
				    ATerm env, int depth)
{
  PT_Tree lhstrm, rhstrm;

  /* assuming that not both sides have new vars */

  if (!no_new_vars(rhs,env)) { /* a matching condition */
    TIDE_STEP(lhs, env, depth);
    lhstrm = rewriteInnermost(lhs, env, depth + 1, NO_TRAVERSAL);
    if (!lhstrm) {
      return fail_env;
    }
    TIDE_STEP(rhs, env, depth);
    TIDE_STEP(getConditionSign(cond), env, depth);
    return matchArgument(env, rhs, lhstrm, conds, 
			 PT_makeArgsEmpty(), PT_makeArgsEmpty(), 
			 NULL, depth);
  }
  else if (!no_new_vars(lhs, env)) { /* flip the sides */
    return matchPositiveCondition(cond, rhs, lhs, conds, env, depth);
  }
  else { /* an equality condition */
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

    TIDE_STEP(getConditionSign(cond), env, depth);
    if (isAsFixEqual(lhstrm, rhstrm)) {
      return matchConditions(conds, env, depth);
    }
    else {
      return fail_env;
    }
  }
}

/*}}}  */

/*{{{  static ATerm matchCondition(ASF_ASFCondition cond, ASF_ASFConditionList conds, */

ATerm matchCondition(ASF_ASFCondition cond, ASF_ASFConditionList conds,
		     ATerm env, int depth)
{
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
  else if (ASF_isASFConditionPositive(cond)) {
    return matchPositiveCondition(cond, lhs, rhs, conds, env, depth);
  }
  else {
    return matchNoMatchCondition(cond, lhs, rhs, conds, env, depth);
  }
}

/*}}}  */
/*{{{  ATerm matchConditions(ASF_ASFConditionList conds, ATerm env, int depth) */
ATerm matchConditions(ASF_ASFConditionList conds, ATerm env, int depth)
{
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
/*}}}  */

/*{{{  static ATerm matchList(ATerm env, PT_Production listProd, */

static ATerm matchList(ATerm env, PT_Production listProd,
		       PT_Args elems1, PT_Args elems2,
		       ASF_ASFConditionList conds, 
		       PT_Args args1, PT_Args args2,
		       ATerm lhs_posinfo, int depth)
{
  PT_Tree elem1;
  ATerm newenv = fail_env;

  elems1 = skipWhitespaceAndSeparator(elems1,listProd);
  elems2 = skipWhitespaceAndSeparator(elems2,listProd);

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

/*}}}  */
/*{{{  static ATerm matchListVariable(env, el, listProd, e1, e2, cnds, a1, a2, pos, d) */


/* matchListVariable
 *
 * Tries different sizes for a single list variable.
 */

static ATerm matchListVariable(ATerm env, PT_Tree listvar,
		  PT_Production listProd, PT_Args elems1, PT_Args elems2,
		  ASF_ASFConditionList conds,
		  PT_Args args1, PT_Args args2,
		  ATerm lhs_posinfo, int depth)
{
  ATerm newenv = fail_env;
  PT_Args last;

  if (PT_isTreeVarListStar(listvar)) {
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

    newenv = matchList(newenv, listProd, elems1, last,
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


/*}}}  */

/*{{{  static ATerm matchArguments(ATerm env, ASF_ASFConditionList conds, */

static ATerm matchArguments(ATerm env, ASF_ASFConditionList conds,
			    PT_Args args1, PT_Args args2, 
			    ATerm lhs_posinfo, int depth)
{
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

/*}}}  */
/*{{{  static ATerm matchVariable(ATerm env, */

static ATerm matchVariable(ATerm env,
			   PT_Tree var,
			   PT_Tree arg2,
			   ASF_ASFConditionList conds,
			   PT_Args orgargs1, PT_Args orgargs2,
			   ATerm lhs_posinfo, int depth)
{
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
    newenv = putVariableValue(env, var, arg2);
    newenv = matchArguments(newenv, conds, orgargs1, orgargs2, lhs_posinfo, 
			    depth);
  }

  return newenv;
}

/*}}}  */
/*{{{  static ATerm matchAppl(ATerm env, */

static ATerm matchAppl(ATerm env,
		       PT_Tree arg1,
		       PT_Tree arg2,
		       ASF_ASFConditionList conds,
		       PT_Args orgargs1, PT_Args orgargs2,
		       ATerm lhs_posinfo, int depth)
{
  PT_Production prod1 = PT_getTreeProd(arg1);
  PT_Production prod2 = PT_getTreeProd(arg2);
  ATerm newenv;

  if (PT_isEqualProduction(prod1, prod2)) {
    PT_Args args1 = PT_getTreeArgs(arg1);
    PT_Args args2 = PT_getTreeArgs(arg2);

    newenv = matchArguments(env, conds, 
			    PT_concatArgs(args1, orgargs1),
			    PT_concatArgs(args2, orgargs2),
			    lhs_posinfo, depth);
  }
  else {
    newenv = fail_env;
  }

  return newenv;
}

/*}}}  */
/*{{{  static ATerm matchArgument(ATerm env,  */

static ATerm matchArgument(ATerm env, 
			   PT_Tree arg1, PT_Tree arg2,
			   ASF_ASFConditionList conds,
			   PT_Args orgargs1, PT_Args orgargs2,
			   ATerm lhs_posinfo, int depth)
{
  ATerm newenv = fail_env;

  if (depth > MAX_DEPTH / 2) {
    char tmp[256];
    sprintf(tmp, "maximum stack depth during matching (%d) exceeded.", 
	    MAX_DEPTH / 2);
    RWsetError(tmp, PT_makeTreeLit(""));
    return fail_env;
  }

  /* equality check is cheap, so try this first */
  if (PT_isEqualTree(PT_removeTreeAnnotations(arg1),
		     PT_removeTreeAnnotations(arg2))) {
    newenv = matchArguments(env, conds, orgargs1, orgargs2, lhs_posinfo, depth);
  }
  else if (PT_isTreeLayout(arg1)) {
    newenv = matchArguments(env, conds, orgargs1, orgargs2, lhs_posinfo, depth);
  }
  else if (PT_isTreeApplList(arg1) &&
	   PT_isTreeApplList(arg2)) {
    PT_Args elems1 = PT_getTreeArgs(arg1);
    PT_Args elems2 = PT_getTreeArgs(arg2);
    PT_Production prod1 = PT_getTreeProd(arg1);

    newenv = matchList(env, prod1, elems1, elems2, conds, orgargs1, orgargs2, 
		       lhs_posinfo, depth);
  }
  else if (PT_isTreeVar(arg1)) {
    newenv = matchVariable(env, arg1, arg2, conds, orgargs1, orgargs2,
			   lhs_posinfo, depth);
  }
  else if (PT_isTreeAppl(arg1)) {
    newenv = matchAppl(env, arg1, arg2, conds, orgargs1, orgargs2,
		       lhs_posinfo, depth);
  }

  return newenv;
}

/*}}}  */

/*{{{  ATerm matchEquation(equation_entry *entry, PT_Tree trm, int depth) */

ATerm matchEquation(equation_entry *entry, PT_Tree trm, int depth)
{
  return matchArgument((ATerm) ATempty, entry->lhs, trm, entry->conds,
		       PT_makeArgsEmpty(), PT_makeArgsEmpty(),
		       PT_TreeToTerm(entry->lhs), depth);
}

/*}}}  */
