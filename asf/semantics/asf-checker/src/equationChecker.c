#include "equationChecker.h"

/*{{{  static ATerm makeMessage(const char *msg, ASF_ASFTag tag, ATerm subject) */

static ATerm makeMessage(const char *msg, ASF_ASFTag tag, ATerm subject)
{
 return ATmake("[<str>,<term>,<term>]",
	       msg,
	       ASF_makeTermFromASFTag(tag),
	       subject);
}

/*}}}  */

/*{{{  static ATermList makeAmbiguityMessage() */

static ATermList makeAmbiguityMessage()
{
 return ATmakeList1(ATmake("[<str>]","Equations contain ambiguity/ies"));
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

/*{{{  static ATermList checkTreeGivenVariables(ASF_ASFTag tag,  */

static ATermList checkTreeGivenVariables(ASF_ASFTag tag, 
                                         PT_Tree tree, 
                                         PT_Args variables)
{
  ATerm message;
  ATermList messages = ATempty;

  if (PT_isTreeAmb(tree)) {
    return makeAmbiguityMessage();
  }
  if (PT_isTreeVar(tree)) {
    if (!lookupVariable(tree, variables)) {
      message = makeMessage("uninstantiated variable occurrence", tag, 
			    PT_TreeToTerm(tree));
      return ATmakeList1(message);
    }
  }
  
  if (PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);

    while (!PT_isArgsEmpty(args)) {
      PT_Tree arg = PT_getArgsHead(args);

      messages = ATconcat(messages,
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

/*{{{  static ATermList checkNegativeCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ATermList checkNegativeCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  ATermList messages = ATempty;
  
  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_TreeToTerm(lhsCond)))) {
    return makeAmbiguityMessage();
  }
  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_TreeToTerm(rhsCond)))) {
    return makeAmbiguityMessage();
  }
  if (!noNewVariables((PT_Tree)lhsCond, *variables) ||
      !noNewVariables((PT_Tree)rhsCond, *variables)) {
    return ATmakeList1(
            makeMessage(
              "negative condition introduces variable(s)", 
	      tag,
	      ASF_makeTermFromASFCondition(condition)));
  }
  else {
    return messages;
  }
}

/*}}}  */

/*{{{  static ATermList checkPositiveCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ATermList checkPositiveCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  ATermList messages = ATempty;

  messages = ATmakeList1(
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
    return ATinsert(messages,
	       makeMessage(
		   "uninstantiated variables in both sides of condition",
		   tag,
		   ASF_makeTermFromASFCondition(condition)));
  }


}

/*}}}  */
/*{{{  static ATermList checkEqualityCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ATermList checkEqualityCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  if (!noNewVariables((PT_Tree) lhsCond, *variables) || 
      !noNewVariables((PT_Tree) rhsCond, *variables)) {
    return ATmakeList1(
	       makeMessage(
		   "uninstantiated variables in equality condition",
		   tag,
		   ASF_makeTermFromASFCondition(condition)));
  }

  return ATempty;
}

/*}}}  */
/*{{{  static ATermList checkMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ATermList checkMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  if (noNewVariables((PT_Tree) lhsCond, *variables)) {
    return ATmakeList1(
	       makeMessage(
		   "matching condition does not introduce new variables",
		   tag,
		   ASF_makeTermFromASFCondition(condition)));
  }
  else {
    *variables = collectVariables((PT_Tree)lhsCond, *variables);
  }

  if (!noNewVariables((PT_Tree) rhsCond, *variables)) {
    return ATmakeList1(
	       makeMessage(
		   "right-hand side of matching condition introduces variables",
		   tag,
		   ASF_makeTermFromASFCondition(condition)));
  }

  return ATempty;
}

/*}}}  */

/*{{{  static ATermList checkCondition(ASF_ASFTag tag, ASF_ASFCondition condition, PT_Args *variables)  */

static ATermList checkCondition(ASF_ASFTag tag, ASF_ASFCondition condition, PT_Args *variables) 
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
    else if (ASF_isASFConditionEquality(condition)) {
      return checkEqualityCondition(tag, condition, lhsCond, rhsCond, variables);
    }
    else {
      return ATmakeList1(
              makeMessage(
                "strange condition encountered", 
	        tag,
	        ASF_makeTermFromASFCondition(condition)));
    }
  }
}

/*}}}  */

/*{{{  static ATermList checkConditions(ASF_ASFTag tag, ASF_ASFConditions conditions, PT_Args *variables)  */

static ATermList checkConditions(ASF_ASFTag tag, ASF_ASFConditions conditions, PT_Args *variables) 
{
  ATermList messages = ATempty;

  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ASFConditionsToTerm(conditions)))) {
    return makeAmbiguityMessage();
  }
  else {
    ASF_ASFConditionList conditionList = ASF_getASFConditionsList(conditions);

    while (ASF_hasASFConditionListHead(conditionList)) {
      ASF_ASFCondition condition =
        ASF_getASFConditionListHead(conditionList);

      messages = ATconcat(messages,
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

/*{{{  static ATermList checkLhs(ASF_ASFTag tag, ASF_Tree asfTree)  */

static ATermList checkLhs(ASF_ASFTag tag, ASF_Tree asfTree) 
{

  PT_Tree ptTree = PT_TreeFromTerm(ASF_TreeToTerm(asfTree));
  if (PT_isTreeAmb(ptTree)) {
    return makeAmbiguityMessage();
  }
  else {
    if (PT_hasProductionConstructorAttr(PT_getTreeProd(ptTree))) {
      ATerm message = makeMessage("constructor not allowed as outermost function symbol of left hand side", tag, PT_TreeToTerm(ptTree));
      return ATmakeList1(message);
    }
    else {
      return ATempty;
    }
  }
}

/*}}}  */

/*{{{  static ATermList checkEquation(ASF_ASFConditionalEquation condEquation)  */

static ATermList checkEquation(ASF_ASFConditionalEquation condEquation) 
{
  ATermList messages = ATempty;

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

      messages = ATconcat(messages, checkLhs(tag, lhsEq));

      if (ASF_hasASFConditionalEquationASFConditions(condEquation)) {
        messages = ATconcat(messages,
			    checkConditions(tag,
				    ASF_getASFConditionalEquationASFConditions(condEquation),
				    &variables));
      }

      messages =  ATconcat(messages,
		           checkTreeGivenVariables(tag, 
					           (PT_Tree)rhsEq, 
					           variables));
      return messages;
    }
  }
}

/*}}}  */

/*{{{  static ATermList checkTest(ASF_ASFTestEquation testEquation)  */

static ATermList checkTest(ASF_ASFTestEquation testEquation) 
{
  ATerm message;
  ATermList messages = ATempty;

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
        messages = ATinsert(messages, message);
	variables = PT_makeArgsEmpty();
      }
      messages = ATconcat(messages, checkLhs(tag, lhsCond));

      if (ASF_hasASFTestEquationASFConditions(testEquation)) {
        messages = ATconcat(messages,
			    checkConditions(tag,
				    ASF_getASFTestEquationASFConditions(testEquation),
				    &variables));
      }

      messages =  ATconcat(messages,
		           checkTreeGivenVariables(tag, 
					           (PT_Tree)rhsCond, 
					           variables));
      return messages;
    }
  }
}

/*}}}  */

/*{{{  ATermList checkASFConditionalEquationList(ASF_ASFConditionalEquationList condEquationList)  */

ATermList checkASFConditionalEquationList(ASF_ASFConditionalEquationList condEquationList) 
{
  ATermList messages = ATempty;
  
  while (!ASF_isASFConditionalEquationListEmpty(condEquationList)) {
    ASF_ASFConditionalEquation condEquation =
      ASF_getASFConditionalEquationListHead(condEquationList);
    
    messages = ATconcat(messages,
                        checkEquation(condEquation));

    if (!ASF_hasASFConditionalEquationListTail(condEquationList)) {
      break;
    }
    condEquationList = ASF_getASFConditionalEquationListTail(condEquationList);
  }
  return messages;
}

/*}}}  */

/*{{{  ATermList checkASFTestEquationList(ASF_ASFTestEquationTestList testEquationList)  */

ATermList checkASFTestEquationList(ASF_ASFTestEquationTestList testEquationList) 
{
  ATermList messages = ATempty;
  
  while (!ASF_isASFTestEquationTestListEmpty(testEquationList)) {
    ASF_ASFTestEquation testEquation =
      ASF_getASFTestEquationTestListHead(testEquationList);
    
    messages = ATconcat(messages,
                        checkTest(testEquation));

    if (!ASF_hasASFTestEquationTestListTail(testEquationList)) {
      break;
    }
    testEquationList = ASF_getASFTestEquationTestListTail(testEquationList);
  }
  return messages;
}

/*}}}  */

/*{{{  ATermList checkEquations(ASF_ASFEquations equations)  */

ATermList checkEquations(ASF_ASFEquations equations) 
{
  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ASFEquationsToTerm(equations)))) {
    return makeAmbiguityMessage();
  }
  if (ASF_isASFEquationsPresent(equations)) {
    ASF_ASFConditionalEquationList condEquationList = 
      ASF_getASFEquationsList(equations);
  
    return checkASFConditionalEquationList(condEquationList);
  }
  else if (ASF_isASFEquationsPresentWithTests(equations)) {
    ASF_ASFConditionalEquationList condEquationList = 
      ASF_getASFEquationsList(equations);
    ASF_ASFTestEquationTestList testEquationList = 
      ASF_getASFEquationsTestList(equations);
  
    return ATconcat(checkASFConditionalEquationList(condEquationList),
                    checkASFTestEquationList(testEquationList));
  }
  return ATempty;
}

/*}}}  */
