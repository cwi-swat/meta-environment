#include "equationChecker.h"
#include "ErrorAPI.h"

/*{{{  static ERR_Feedback makeMessage(const char *msg, ASF_ASFTag tag, ATerm subject) */

ERR_Feedback makeMessage(char *msg, ASF_ASFTag tag, ATerm subject)
{
  ERR_SubjectList subjects = ERR_makeSubjectListEmpty();
  ERR_Subject sub;
  ERR_Area area;
  ERR_Location location;
  int startLine, endLine, startColumn, endColumn;
  char *path;

  if (PT_getTreePosInfo((PT_Tree) subject,
      &path, &startLine, &startColumn, &endLine, &endColumn)) {
    area = ERR_makeAreaArea(startLine, startColumn, endLine, endColumn);
    location = ERR_makeLocationLocation(path, area);
    sub = ERR_makeSubjectSubject(PT_yieldTree((PT_Tree) subject), 
				     location);
    subjects = ERR_makeSubjectListSingle(sub);
  }
  
  return ERR_makeFeedbackError("asf-checker", msg, subjects);
}

/*}}}  */

/*{{{  static ERR_FeedbackList makeAmbiguityMessage() */

static ERR_FeedbackList makeAmbiguityMessage()
{
  return ERR_makeFeedbackListSingle(makeMessage("Equations contain ambiguities",NULL,NULL));
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

/*{{{  static ERR_FeedbackList checkTreeGivenVariables(ASF_ASFTag tag,  */

static ERR_FeedbackList checkTreeGivenVariables(ASF_ASFTag tag, 
						PT_Tree tree, 
						PT_Args variables)
{
  ERR_Feedback message;
  ERR_FeedbackList messages = ERR_makeFeedbackListEmpty();

  if (PT_isTreeAmb(tree)) {
    return makeAmbiguityMessage();
  }
  if (PT_isTreeVar(tree)) {
    if (!lookupVariable(tree, variables)) {
      message = makeMessage("uninstantiated variable occurrence", tag, 
			    PT_TreeToTerm(tree));
      return ERR_makeFeedbackListSingle(message);
    }
  }

  if (PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);

    while (!PT_isArgsEmpty(args)) {
      PT_Tree arg = PT_getArgsHead(args);

      messages = ERR_concatFeedbackList(messages,
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

/*{{{  static ERR_FeedbackList checkNegativeCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ERR_FeedbackList checkNegativeCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  ERR_FeedbackList messages = ERR_makeFeedbackListEmpty();

  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_TreeToTerm(lhsCond)))) {
    return makeAmbiguityMessage();
  }
  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_TreeToTerm(rhsCond)))) {
    return makeAmbiguityMessage();
  }
  if (!noNewVariables((PT_Tree)lhsCond, *variables) ||
      !noNewVariables((PT_Tree)rhsCond, *variables)) {
    return ERR_makeFeedbackListSingle(makeMessage(
					     "negative condition introduces variable(s)", 
					     tag,
					     ASF_makeTermFromASFCondition(condition)));
  }
  else {
    return messages;
  }
}

/*}}}  */

/*{{{  static ERR_FeedbackList checkPositiveCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ERR_FeedbackList checkPositiveCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  ERR_FeedbackList messages = ERR_makeFeedbackListEmpty();

  messages = ERR_makeFeedbackListSingle(
				   makeMessage("Deprecated condition syntax \"=\". Please use either \"==\" for equality, or \":=\" for matching (Hint: see the Upgrade menu)", tag, ASF_makeTermFromASFCondition(condition)));

  if (noNewVariables((PT_Tree) lhsCond, *variables)) {
    *variables = collectVariables((PT_Tree)rhsCond, *variables);
    return messages;
  }
  else if (noNewVariables((PT_Tree) rhsCond, *variables)) {
    *variables = collectVariables((PT_Tree)lhsCond, *variables);
    return messages;
  }
  else {
    return ERR_makeFeedbackListMany(
				    makeMessage(
						"uninstantiated variables in both sides of condition",
						tag,
						ASF_makeTermFromASFCondition(condition)), messages);
  }


}

/*}}}  */
/*{{{  static ERR_FeedbackList checkEqualityCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ERR_FeedbackList checkEqualityCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  if (!noNewVariables((PT_Tree) lhsCond, *variables) || 
      !noNewVariables((PT_Tree) rhsCond, *variables)) {
    return ERR_makeFeedbackListSingle(
				 makeMessage(
					     "uninstantiated variables in equality condition",
					     tag,
					     ASF_makeTermFromASFCondition(condition)));
  }

  return ERR_makeFeedbackListEmpty();
}

/*}}}  */
/*{{{  static ERR_FeedbackList checkMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ERR_FeedbackList checkMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  if (noNewVariables((PT_Tree) lhsCond, *variables)) {
    return ERR_makeFeedbackListSingle(
				 makeMessage(
					     "matching condition does not introduce new variables",
					     tag,
					     ASF_makeTermFromASFCondition(condition)));
  }
  else {
    *variables = collectVariables((PT_Tree)lhsCond, *variables);
  }

  if (!noNewVariables((PT_Tree) rhsCond, *variables)) {
    return ERR_makeFeedbackListSingle(
				 makeMessage(
					     "right-hand side of matching condition introduces variables",
					     tag,
					     ASF_makeTermFromASFCondition(condition)));
  }

  return ERR_makeFeedbackListEmpty();
}

/*}}}  */
/*{{{  static ERR_FeedbackList checkNoMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ERR_FeedbackList checkNoMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  if (noNewVariables((PT_Tree) lhsCond, *variables)) {
    return ERR_makeFeedbackListSingle(
				 makeMessage(
					     "matching condition does not use new variables",
					     tag,
					     ASF_makeTermFromASFCondition(condition)));
  }

  if (!noNewVariables((PT_Tree) rhsCond, *variables)) {
    return ERR_makeFeedbackListSingle(
				 makeMessage(
					     "right-hand side of matching condition introduces variables",
					     tag,
					     ASF_makeTermFromASFCondition(condition)));
  }

  return ERR_makeFeedbackListEmpty();
}

/*}}}  */

/*{{{  static ERR_FeedbackList checkCondition(ASF_ASFTag tag, ASF_ASFCondition condition, PT_Args *variables)  */

static ERR_FeedbackList checkCondition(ASF_ASFTag tag, ASF_ASFCondition condition, PT_Args *variables) 
{
  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ASFConditionToTerm(condition)))) {
    return makeAmbiguityMessage();
  }
  else {
    ASF_Tree lhsCond = ASF_getASFConditionLhs(condition);
    ASF_Tree rhsCond = ASF_getASFConditionRhs(condition);

    if (PT_isTreeAmb(PT_TreeFromTerm(ASF_TreeToTerm(lhsCond)))) {
      return makeAmbiguityMessage();
    }
    if (PT_isTreeAmb(PT_TreeFromTerm(ASF_TreeToTerm(rhsCond)))) {
      return makeAmbiguityMessage();
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
      return ERR_makeFeedbackListSingle(
				   makeMessage(
					       "strange condition encountered", 
					       tag,
					       ASF_makeTermFromASFCondition(condition)));
    }
  }
}

/*}}}  */

/*{{{  static ERR_FeedbackList checkConditions(ASF_ASFTag tag, ASF_ASFConditions conditions, PT_Args *variables)  */

static ERR_FeedbackList checkConditions(ASF_ASFTag tag, ASF_ASFConditions conditions, PT_Args *variables) 
{
  ERR_FeedbackList messages = ERR_makeFeedbackListEmpty();

  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ASFConditionsToTerm(conditions)))) {
    return makeAmbiguityMessage();
  }
  else {
    ASF_ASFConditionList conditionList = ASF_getASFConditionsList(conditions);

    while (ASF_hasASFConditionListHead(conditionList)) {
      ASF_ASFCondition condition =
	ASF_getASFConditionListHead(conditionList);

      messages = ERR_concatFeedbackList(messages,
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

/*{{{  static ERR_FeedbackList checkLhs(ASF_ASFTag tag, ASF_Tree asfTree)  */

static ERR_FeedbackList checkLhs(ASF_ASFTag tag, ASF_Tree asfTree) 
{

  PT_Tree ptTree = PT_TreeFromTerm(ASF_TreeToTerm(asfTree));
  if (PT_isTreeAmb(ptTree)) {
    return makeAmbiguityMessage();
  }
  else {
    if (PT_hasProductionConstructorAttr(PT_getTreeProd(ptTree))) {
      ERR_Feedback message = makeMessage("constructor not allowed as outermost function symbol of left hand side", tag, PT_TreeToTerm(ptTree));
      return ERR_makeFeedbackListSingle(message);
    }
    else {
      return ERR_makeFeedbackListEmpty();
    }
  }
}

/*}}}  */

/*{{{  static ERR_FeedbackList checkEquation(ASF_ASFConditionalEquation condEquation)  */

static ERR_FeedbackList checkEquation(ASF_ASFConditionalEquation condEquation) 
{
  ERR_FeedbackList messages = ERR_makeFeedbackListEmpty();

  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ASFConditionalEquationToTerm(condEquation)))) {
    return makeAmbiguityMessage();
  }
  else {
    ASF_ASFTag tag = ASF_getASFConditionalEquationASFTag(condEquation);

    ASF_ASFEquation equation = ASF_getASFConditionalEquationASFEquation(condEquation);

    if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ASFEquationToTerm(equation)))) {
      return makeAmbiguityMessage();
    }
    else {
      ASF_Tree lhsEq = ASF_getASFEquationLhs(equation);
      ASF_Tree rhsEq = ASF_getASFEquationRhs(equation);
      PT_Args variables = collectVariables((PT_Tree)lhsEq, 
					   PT_makeArgsEmpty());

      messages = ERR_concatFeedbackList(messages, checkLhs(tag, lhsEq));

      if (ASF_hasASFConditionalEquationASFConditions(condEquation)) {
	messages = ERR_concatFeedbackList(messages,
					  checkConditions(tag,
							  ASF_getASFConditionalEquationASFConditions(condEquation),
							  &variables));
      }

      messages =  ERR_concatFeedbackList(messages,
					 checkTreeGivenVariables(tag, 
								 (PT_Tree)rhsEq, 
								 variables));
      return messages;
    }
  }
}

/*}}}  */

/*{{{  static ERR_FeedbackList checkTest(ASF_ASFTestEquation testEquation)  */

static ERR_FeedbackList checkTest(ASF_ASFTestEquation testEquation) 
{
  ERR_Feedback message;
  ERR_FeedbackList messages = ERR_makeFeedbackListEmpty();

  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ASFTestEquationToTerm(testEquation)))) {
    return makeAmbiguityMessage();
  }
  else {
    ASF_ASFTag tag = ASF_getASFTestEquationASFTag(testEquation);

    ASF_ASFCondition condition = ASF_getASFTestEquationASFCondition(testEquation);

    if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ASFConditionToTerm(condition)))) {
      return makeAmbiguityMessage();
    }
    else {
      ASF_Tree lhsCond = ASF_getASFConditionLhs(condition);
      ASF_Tree rhsCond = ASF_getASFConditionRhs(condition);
      PT_Args variables = collectVariables((PT_Tree)lhsCond, 
					   PT_makeArgsEmpty());

      if (!PT_isArgsEmpty(variables)) {
	message = makeMessage("no variables may be introduced in left hand side of test", tag, ASF_TreeToTerm(lhsCond));
	messages = ERR_makeFeedbackListMany(message, messages);
	variables = PT_makeArgsEmpty();
      }

      if (ASF_hasASFTestEquationASFConditions(testEquation)) {
	messages = ERR_concatFeedbackList(messages,
					  checkConditions(tag,
							  ASF_getASFTestEquationASFConditions(testEquation),
							  &variables));
      }

      messages =  ERR_concatFeedbackList(messages,
					 checkTreeGivenVariables(tag, 
								 (PT_Tree)rhsCond, 
								 variables));
      return messages;
    }
  }
}

/*}}}  */

/*{{{  ERR_FeedbackList checkASFConditionalEquationList(ASF_ASFConditionalEquationList condEquationList)  */

ERR_FeedbackList checkASFConditionalEquationList(ASF_ASFConditionalEquationList condEquationList) 
{
  ERR_FeedbackList messages = ERR_makeFeedbackListEmpty();

  while (!ASF_isASFConditionalEquationListEmpty(condEquationList)) {
    ASF_ASFConditionalEquation condEquation =
      ASF_getASFConditionalEquationListHead(condEquationList);

    messages = ERR_concatFeedbackList(messages,
				      checkEquation(condEquation));

    if (!ASF_hasASFConditionalEquationListTail(condEquationList)) {
      break;
    }
    condEquationList = ASF_getASFConditionalEquationListTail(condEquationList);
  }

  return messages;
}

/*}}}  */

/*{{{  ERR_FeedbackList checkASFTestEquationList(ASF_ASFTestEquationTestList testEquationList)  */

ERR_FeedbackList checkASFTestEquationList(ASF_ASFTestEquationTestList testEquationList) 
{
  ERR_FeedbackList messages = ERR_makeFeedbackListEmpty();

  while (!ASF_isASFTestEquationTestListEmpty(testEquationList)) {
    ASF_ASFTestEquation testEquation =
      ASF_getASFTestEquationTestListHead(testEquationList);

    messages = ERR_concatFeedbackList(messages,
				      checkTest(testEquation));

    if (!ASF_hasASFTestEquationTestListTail(testEquationList)) {
      break;
    }
    testEquationList = ASF_getASFTestEquationTestListTail(testEquationList);
  }
  return messages;
}

/*}}}  */

/*{{{  ERR_FeedbackList checkEquations(ASF_ASFEquations equations)  */

ERR_FeedbackList checkEquations(ASF_ASFConditionalEquationList equations) 
{
  if (PT_isTreeAmb(PT_TreeFromTerm((ATerm) equations))) {
    return makeAmbiguityMessage();
  }

  return checkASFConditionalEquationList(equations);
}

/*}}}  */
/*{{{  ERR_FeedbackList checkTests(ASF_ASFTestEquationTestList tests)  */

ERR_FeedbackList checkTests(ASF_ASFTestEquationTestList tests) 
{
  if (PT_isTreeAmb(PT_TreeFromTerm((ATerm) tests))) {
    return makeAmbiguityMessage();
  }

  return checkASFTestEquationList(tests);
}

/*}}}  */
