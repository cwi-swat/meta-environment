/* $Id$ */

/*{{{  includes */

#include <Error.h>
#include "equationChecker.h"

/*}}}  */

/*{{{  ERR_Error makeMessage(const char *msg, ATerm subject) */

ERR_Error makeMessage(const char *msg, ATerm subject)
{
  ERR_SubjectList subjects = ERR_makeSubjectListEmpty();
  ERR_Subject sub;
  ERR_Location location = PT_getTreeLocation((PT_Tree) subject);

  if (location != NULL) {
    sub = ERR_makeSubjectLocalized(PT_yieldTree((PT_Tree) subject), location);
    subjects = ERR_makeSubjectListSingle(sub);
  }
  
  return ERR_makeErrorError(msg, subjects);
}

/*}}}  */
/*{{{  ERR_Error makeWarning(char *msg, ATerm subject) */

ERR_Error makeWarning(char *msg, ATerm subject)
{
  ERR_SubjectList subjects = ERR_makeSubjectListEmpty();
  ERR_Subject sub;
  ERR_Location location = PT_getTreeLocation((PT_Tree) subject);

  if (location != NULL) {
    sub = ERR_makeSubjectLocalized(PT_yieldTree((PT_Tree) subject), location);
    subjects = ERR_makeSubjectListSingle(sub);
  }
  
  return ERR_makeErrorWarning(msg, subjects);
}

/*}}}  */

/*{{{  ERR_ErrorList makeAmbiguityMessage(void *subject) */

ERR_ErrorList makeAmbiguityMessage(void *subject)
{
  return ERR_makeErrorListSingle(makeMessage("equations contain ambiguities",
						(ATerm) subject));
}

/*}}}  */

/*{{{  static ATbool lookupVariable(PT_Tree tree, PT_Args variables) */

static ATbool lookupVariable(PT_Tree tree, PT_Args variables)
{
  while (!PT_isArgsEmpty(variables)) {
    PT_Tree variable = PT_getArgsHead(variables);

    if (PT_isEqualTree(PT_removeTreeAnnotations(tree), 
		       PT_removeTreeAnnotations(variable))) {
      return ATtrue;
    }

    variables = PT_getArgsTail(variables);
  }
  return ATfalse;
}

/*}}}  */

/*{{{  static ERR_ErrorList checkTreeGivenVariables(ASF_ASFTag tag,  */

static ERR_ErrorList checkTreeGivenVariables(ASF_ASFTag tag, 
						PT_Tree tree, 
						PT_Args variables)
{
  ERR_Error message;
  ERR_ErrorList messages = ERR_makeErrorListEmpty();

  if (PT_isTreeAmb(tree)) {
    return makeAmbiguityMessage(tree);
  }
  if (PT_isTreeVar(tree)) {
    if (!lookupVariable(tree, variables)) {
      message = makeMessage("uninstantiated variable occurrence",  
			    PT_TreeToTerm(tree));
      return ERR_makeErrorListSingle(message);
    }
  }

  if (PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);

    while (!PT_isArgsEmpty(args)) {
      PT_Tree arg = PT_getArgsHead(args);

      messages = ERR_concatErrorList(messages,
					checkTreeGivenVariables(tag, arg, variables));

      args = PT_getArgsTail(args);
    }
  }

  return messages;
}

/*}}}  */

/*{{{  static PT_Args collectVariables(PT_Tree tree, PT_Args varList) */

static PT_Args collectVariables(PT_Tree tree, PT_Args varList)
{
  if (PT_isTreeAmb(tree)) {
    return varList;
  }
  if (PT_isTreeVar(tree)) {
    return PT_makeArgsList(tree, varList);
  }

  if (PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);

    while (!PT_isArgsEmpty(args)) {
      PT_Tree arg = PT_getArgsHead(args);

      varList = collectVariables(arg, varList);

      args = PT_getArgsTail(args);
    }
  }

  return varList;
}

/*}}}  */

/*{{{  static ATbool noNewVariables(PT_Tree tree, PT_Args varList) */

static ATbool noNewVariables(PT_Tree tree, PT_Args varList)
{
  PT_Tree arg;
  PT_Args args;
  ATbool existing;

  if (PT_isTreeAmb(tree)) {
    return ATfalse;
  }
  if (PT_isTreeVar(tree)) {
    return lookupVariable(tree, varList);
  }
  else if (PT_isTreeAppl(tree)) {
    existing = ATtrue;
    args = PT_getTreeArgs(tree);
    while (existing && PT_hasArgsHead(args)) {
      arg = PT_getArgsHead(args);

      existing = noNewVariables(arg, varList);

      args = PT_getArgsTail(args);
    };

    return existing;
  }
  else {
    return ATtrue;
  }
}

/*}}}  */

/*{{{  static ATbool instantiatedVariables(PT_Tree tree, PT_Args varList) */

static ATbool instantiatedVariables(PT_Tree tree, PT_Args varList)
{
  PT_Tree arg;
  PT_Args args;
  ATbool instantiated;

  if (PT_isTreeAmb(tree)) {
    return ATfalse;
  }
  if (PT_isTreeVar(tree)) {
    return lookupVariable(tree, varList);
  }
  else if (PT_isTreeAppl(tree)) {
    instantiated = ATfalse;
    args = PT_getTreeArgs(tree);
    while (!instantiated && PT_hasArgsHead(args)) {
      arg = PT_getArgsHead(args);

      instantiated = instantiatedVariables(arg, varList);

      args = PT_getArgsTail(args);
    };

    return instantiated;
  }
  else {
    return ATfalse;
  }
}

/*}}}  */

/*{{{  static ATbool isSingleton(PT_Tree tree)  */

static ATbool isSingleton(PT_Tree tree) 
{
  /* This function checks for trees that look like this:
   *    S* -> S-List, list(S*), [S]   or this:
   *    list(S*), [S]
   *
   *    So direct singletons, or singletons wrapped in a single injection.
   */

  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Args args = PT_getTreeArgs(tree);

    if (PT_isProductionList(prod)) {
      if (PT_getArgsLength(args) == 1) {
	return ATtrue;
      }
    }
    else {
      if (PT_isProductionInjection(prod)) {
	return isSingleton(PT_getArgsHead(args));
      }
    }
  }

  return ATfalse;
}

/*}}}  */

/*{{{  static ERR_ErrorList checkNegativeCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ERR_ErrorList checkNegativeCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  ERR_ErrorList messages = ERR_makeErrorListEmpty();

  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_TreeToTerm(lhsCond)))) {
    return makeAmbiguityMessage(lhsCond);
  }
  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_TreeToTerm(rhsCond)))) {
    return makeAmbiguityMessage(rhsCond);
  }
  if (!noNewVariables((PT_Tree)lhsCond, *variables) ||
      !noNewVariables((PT_Tree)rhsCond, *variables)) {
    return ERR_makeErrorListSingle(makeMessage(
					     "negative condition introduces variable(s)", 
					     ASF_makeTermFromASFCondition(condition)));
  }
  else {
    return messages;
  }
}

/*}}}  */

/*{{{  static ERR_ErrorList checkPositiveCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ERR_ErrorList checkPositiveCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  ERR_ErrorList messages = ERR_makeErrorListEmpty();

  messages = ERR_makeErrorListSingle(
				   makeWarning("Deprecated condition syntax \"=\". Please use either \"==\" for equality, or \":=\" for matching (Hint: see the Upgrade menu)", ASF_makeTermFromASFCondition(condition)));

  if (noNewVariables((PT_Tree) lhsCond, *variables)) {
    *variables = collectVariables((PT_Tree)rhsCond, *variables);
    return messages;
  }
  else if (noNewVariables((PT_Tree) rhsCond, *variables)) {
    *variables = collectVariables((PT_Tree)lhsCond, *variables);
    return messages;
  }
  else {
    return ERR_makeErrorListMany(
				    makeMessage(
						"uninstantiated variables in both sides of condition",
						ASF_makeTermFromASFCondition(condition)), messages);
  }


}

/*}}}  */
/*{{{  static ERR_ErrorList checkEqualityCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ERR_ErrorList checkEqualityCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  if (!noNewVariables((PT_Tree) lhsCond, *variables) || 
      !noNewVariables((PT_Tree) rhsCond, *variables)) {
    return ERR_makeErrorListSingle(
				 makeMessage(
					     "uninstantiated variables in equality condition",
					     ASF_makeTermFromASFCondition(condition)));
  }

  return ERR_makeErrorListEmpty();
}

/*}}}  */
/*{{{  static ERR_ErrorList checkMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ERR_ErrorList checkMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  if (!noNewVariables((PT_Tree) rhsCond, *variables)) {
    return ERR_makeErrorListSingle(
	 makeMessage(
	     "right-hand side of matching condition introduces variables",
	     ASF_makeTermFromASFCondition(condition)));
  }

  if (noNewVariables((PT_Tree) lhsCond, *variables)) {
    return ERR_makeErrorListSingle(
	 makeMessage(
	     "matching condition does not introduce new variables",
		     ASF_makeTermFromASFCondition(condition)));
  }
  else {
    *variables = collectVariables((PT_Tree)lhsCond, *variables);
  }

  return ERR_makeErrorListEmpty();
}

/*}}}  */
/*{{{  static ERR_ErrorList checkNoMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ERR_ErrorList checkNoMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  if (noNewVariables((PT_Tree) lhsCond, *variables)) {
    return ERR_makeErrorListSingle(
				 makeMessage(
					     "matching condition does not use new variables",
					     ASF_makeTermFromASFCondition(condition)));
  }

  if (!noNewVariables((PT_Tree) rhsCond, *variables)) {
    return ERR_makeErrorListSingle(
				 makeMessage(
					     "right-hand side of matching condition introduces variables",
					     ASF_makeTermFromASFCondition(condition)));
  }

  return ERR_makeErrorListEmpty();
}

/*}}}  */
/*{{{  static ERR_ErrorList checkCondition(ASF_ASFTag tag, ASF_ASFCondition condition, PT_Args *variables)  */

static ERR_ErrorList checkCondition(ASF_ASFTag tag, ASF_ASFCondition condition, PT_Args *variables) 
{
  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ASFConditionToTerm(condition)))) {
    return makeAmbiguityMessage(condition);
  }
  else {
    ASF_Tree lhsCond = ASF_getASFConditionLhs(condition);
    ASF_Tree rhsCond = ASF_getASFConditionRhs(condition);

    if (PT_isTreeAmb(PT_TreeFromTerm(ASF_TreeToTerm(lhsCond)))) {
      return makeAmbiguityMessage(lhsCond);
    }
    if (PT_isTreeAmb(PT_TreeFromTerm(ASF_TreeToTerm(rhsCond)))) {
      return makeAmbiguityMessage(rhsCond);
    }

    if (ASF_isASFConditionNegative(condition)) {
      return checkNegativeCondition(tag, condition, lhsCond, rhsCond, variables);
    }
    else if (ASF_isASFConditionPositive(condition)) {
      return checkPositiveCondition(tag, condition, lhsCond, rhsCond, variables);
    }
    else if (ASF_isASFConditionMatch(condition)) {
      return checkMatchCondition(tag, condition, lhsCond, rhsCond, variables);
    }
    else if (ASF_isASFConditionNoMatch(condition)) {
      return checkNoMatchCondition(tag, condition, lhsCond, rhsCond, variables);
    }
    else if (ASF_isASFConditionEquality(condition)) {
      return checkEqualityCondition(tag, condition, lhsCond, rhsCond, variables);
    }
    else {
      return ERR_makeErrorListSingle(
				   makeMessage(
					       "strange condition encountered", 
					       ASF_makeTermFromASFCondition(condition)));
    }
  }
}

/*}}}  */
/*{{{  static ERR_ErrorList checkConditions(ASF_ASFTag tag, ASF_ASFConditions conditions, PT_Args *variables)  */

static ERR_ErrorList checkConditions(ASF_ASFTag tag, ASF_ASFConditions conditions, PT_Args *variables) 
{
  ERR_ErrorList messages = ERR_makeErrorListEmpty();

  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ASFConditionsToTerm(conditions)))) {
    return makeAmbiguityMessage(conditions);
  }
  else {
    ASF_ASFConditionList conditionList = ASF_getASFConditionsList(conditions);

    while (ASF_hasASFConditionListHead(conditionList)) {
      ASF_ASFCondition condition =
	ASF_getASFConditionListHead(conditionList);

      messages = ERR_concatErrorList(messages,
					checkCondition(tag, condition, variables));

      if (!ASF_hasASFConditionListTail(conditionList)) {
	break;
      }
      conditionList = ASF_getASFConditionListTail(conditionList);
    }

    return messages;
  }
}

/*}}}  */
/*{{{  static ERR_ErrorList checkLhs(ASF_ASFTag tag, ASF_Tree asfTree)  */

static ERR_ErrorList checkLhs(ASF_ASFTag tag, ASF_Tree asfTree) 
{
  PT_Tree ptTree = PT_TreeFromTerm(ASF_TreeToTerm(asfTree));
  if (PT_isTreeAmb(ptTree)) {
    return makeAmbiguityMessage(ptTree);
  }
  else {
    if (PT_hasProductionConstructorAttr(PT_getTreeProd(ptTree))) {
      ERR_Error message = 
	makeWarning(
    "constructor not expected as outermost function symbol of left hand side", 
    PT_TreeToTerm(ptTree));
      return ERR_makeErrorListSingle(message);
    }
    else if (isSingleton(ptTree)) {
      ERR_Error message = 
          makeWarning(
          "Left hand side only matches singleton lists", PT_TreeToTerm(ptTree));
      return ERR_makeErrorListSingle(message);
    }
    else {
      return ERR_makeErrorListEmpty();
    }
  }
}

/*}}}  */
/*{{{  static ERR_ErrorList checkEquation(ASF_ASFConditionalEquation condEquation)  */

static ERR_ErrorList checkEquation(ASF_ASFConditionalEquation condEquation) 
{
  ERR_ErrorList messages = ERR_makeErrorListEmpty();

  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ASFConditionalEquationToTerm(condEquation)))) {
    return makeAmbiguityMessage(condEquation);
  }
  else {
    ASF_ASFTag tag = ASF_getASFConditionalEquationASFTag(condEquation);

    ASF_ASFEquation equation = ASF_getASFConditionalEquationASFEquation(condEquation);

    if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ASFEquationToTerm(equation)))) {
      return makeAmbiguityMessage(equation);
    }
    else {
      ASF_Tree lhsEq = ASF_getASFEquationLhs(equation);
      ASF_Tree rhsEq = ASF_getASFEquationRhs(equation);
      PT_Args variables = collectVariables((PT_Tree)lhsEq, 
					   PT_makeArgsEmpty());

      messages = ERR_concatErrorList(messages, checkLhs(tag, lhsEq));

      if (ASF_hasASFConditionalEquationASFConditions(condEquation)) {
	messages = ERR_concatErrorList(messages,
					  checkConditions(tag,
							  ASF_getASFConditionalEquationASFConditions(condEquation),
							  &variables));
      }

      messages =  ERR_concatErrorList(messages,
					 checkTreeGivenVariables(tag, 
								 (PT_Tree)rhsEq, 
								 variables));
      return messages;
    }
  }
}

/*}}}  */
/*{{{  static ERR_ErrorList checkTest(ASF_ASFTestEquation testEquation)  */

static ERR_ErrorList checkTest(ASF_ASFTestEquation testEquation) 
{
  ERR_Error message;
  ERR_ErrorList messages = ERR_makeErrorListEmpty();

  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ASFTestEquationToTerm(testEquation)))) {
    return makeAmbiguityMessage(testEquation);
  }
  else {
    ASF_ASFTag tag = ASF_getASFTestEquationASFTag(testEquation);

    ASF_ASFCondition condition = ASF_getASFTestEquationASFCondition(testEquation);

    if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ASFConditionToTerm(condition)))) {
      return makeAmbiguityMessage(condition);
    }
    else {
      ASF_Tree lhsCond = ASF_getASFConditionLhs(condition);
      ASF_Tree rhsCond = ASF_getASFConditionRhs(condition);
      PT_Args variables = collectVariables((PT_Tree)lhsCond, 
					   PT_makeArgsEmpty());

      if (!PT_isArgsEmpty(variables)) {
	message = makeMessage("no variables may be introduced in left hand side of test", ASF_TreeToTerm(lhsCond));
	messages = ERR_makeErrorListMany(message, messages);
	variables = PT_makeArgsEmpty();
      }

      if (ASF_hasASFTestEquationASFConditions(testEquation)) {
	messages = ERR_concatErrorList(messages,
					  checkConditions(tag,
							  ASF_getASFTestEquationASFConditions(testEquation),
							  &variables));
      }

      messages =  ERR_concatErrorList(messages,
					 checkTreeGivenVariables(tag, 
								 (PT_Tree)rhsCond, 
								 variables));
      return messages;
    }
  }
}

/*}}}  */

/*{{{  ERR_ErrorList checkASFConditionalEquationList(ASF_ASFConditionalEquationList condEquationList)  */

ERR_ErrorList checkASFConditionalEquationList(ASF_ASFConditionalEquationList condEquationList) 
{
  ERR_ErrorList messages = ERR_makeErrorListEmpty();

  while (!ASF_isASFConditionalEquationListEmpty(condEquationList)) {
    ASF_ASFConditionalEquation condEquation =
      ASF_getASFConditionalEquationListHead(condEquationList);

    messages = ERR_concatErrorList(messages,
				      checkEquation(condEquation));

    if (!ASF_hasASFConditionalEquationListTail(condEquationList)) {
      break;
    }
    condEquationList = ASF_getASFConditionalEquationListTail(condEquationList);
  }

  return messages;
}

/*}}}  */
/*{{{  ERR_ErrorList checkASFTestEquationList(ASF_ASFTestEquationTestList testEquationList)  */

ERR_ErrorList checkASFTestEquationList(ASF_ASFTestEquationTestList testEquationList) 
{
  ERR_ErrorList messages = ERR_makeErrorListEmpty();

  while (!ASF_isASFTestEquationTestListEmpty(testEquationList)) {
    ASF_ASFTestEquation testEquation =
      ASF_getASFTestEquationTestListHead(testEquationList);

    messages = ERR_concatErrorList(messages,
				      checkTest(testEquation));

    if (!ASF_hasASFTestEquationTestListTail(testEquationList)) {
      break;
    }
    testEquationList = ASF_getASFTestEquationTestListTail(testEquationList);
  }
  return messages;
}

/*}}}  */

/*{{{  ERR_ErrorList checkEquations(ASF_ASFEquations equations)  */

ERR_ErrorList checkEquations(ASF_ASFConditionalEquationList equations) 
{
  if (PT_isTreeAmb(PT_TreeFromTerm((ATerm) equations))) {
    return makeAmbiguityMessage(equations);
  }

  return checkASFConditionalEquationList(equations);
}

/*}}}  */
/*{{{  ERR_ErrorList checkTests(ASF_ASFTestEquationTestList tests)  */

ERR_ErrorList checkTests(ASF_ASFTestEquationTestList tests) 
{
  if (PT_isTreeAmb(PT_TreeFromTerm((ATerm) tests))) {
    return makeAmbiguityMessage(tests);
  }

  return checkASFTestEquationList(tests);
}

/*}}}  */
