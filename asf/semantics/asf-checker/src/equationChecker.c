#include "equationChecker.h"

static ATerm makeMessage(const char *msg, ASF_Tag tag, ATerm subject)
{
 return ATmake("[<str>,<term>,<term>]",
	       msg,
	       ASF_makeTermFromTag(tag),
	       subject);
}

static ATermList makeAmbiguityMessage()
{
 return ATmakeList1(ATmake("[<str>]","Equations contain ambiguity/ies"));
}

static ATbool lookupVariable(PT_Tree tree, PT_Args variables)
{
  while (!PT_isArgsEmpty(variables)) {
    PT_Tree variable = PT_getArgsHead(variables);

    if (PT_isEqualTree(tree, variable)) {
      return ATtrue;
    }

    variables = PT_getArgsTail(variables);
  }
  return ATfalse;
}

static ATermList checkTreeGivenVariables(ASF_Tag tag, 
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

static ATermList checkNegativeCondition(ASF_Tag tag,
					ASF_Condition condition,
                                        ASF_Tree lhsCond,
					ASF_Tree rhsCond,
                                        PT_Args *variables) 
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
	      ASF_makeTermFromCondition(condition)));
  }
  else {
    return messages;
  }
}

static ATermList checkPositiveCondition(ASF_Tag tag, 
					ASF_Condition condition,
                                        ASF_Tree lhsCond,
					ASF_Tree rhsCond,
                                        PT_Args *variables) 
{
  ATermList messages = ATempty;

  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_TreeToTerm(lhsCond)))) {
    return makeAmbiguityMessage();
  }
  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_TreeToTerm(rhsCond)))) {
    return makeAmbiguityMessage();
  }
  if (noNewVariables((PT_Tree) lhsCond, *variables)) {
    *variables = collectVariables((PT_Tree)rhsCond, *variables);
    return messages;
  }
  else if (noNewVariables((PT_Tree) rhsCond, *variables)) {
    *variables = collectVariables((PT_Tree)lhsCond, *variables);
    return messages;
  }
  else {
    return ATmakeList1(
	       makeMessage(
		   "uninstantiated variables in both sides of condition",
		   tag,
		   ASF_makeTermFromCondition(condition)));
  }
}

static ATermList checkCondition(ASF_Tag tag,
                                ASF_Condition condition,
                                PT_Args *variables) 
{
  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ConditionToTerm(condition)))) {
    return makeAmbiguityMessage();
  }
  else {
    ASF_Tree lhsCond = ASF_getConditionLhs(condition);
    ASF_Tree rhsCond = ASF_getConditionRhs(condition);

    if (ASF_isConditionNegative(condition)) {
      return checkNegativeCondition(tag, condition, lhsCond, rhsCond, variables);
    }
    else if (ASF_isConditionPositive(condition)) {
      return checkPositiveCondition(tag, condition, lhsCond, rhsCond, variables);
    }
    else {
    ATwarning("condition = %t\n", condition);
      return ATmakeList1(
              makeMessage(
                "strange condition encountered", 
	        tag,
	        ASF_makeTermFromCondition(condition)));
    }
  }
}

static ATermList checkConditions(ASF_Tag tag,
				 ASF_Conditions conditions,
				 PT_Args *variables) 
{
  ATermList messages = ATempty;

  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_ConditionsToTerm(conditions)))) {
    return makeAmbiguityMessage();
  }
  else {
    ASF_ConditionList conditionList = ASF_getConditionsList(conditions);

    while (ASF_hasConditionListHead(conditionList)) {
      ASF_Condition condition =
        ASF_getConditionListHead(conditionList);

      messages = ATconcat(messages,
			  checkCondition(tag, condition, variables));

      if (!ASF_hasConditionListTail(conditionList)) {
        break;
      }
      conditionList = ASF_getConditionListTail(conditionList);
    }

    return messages;
  }
}

static ATermList checkEquation(ASF_CondEquation condEquation) 
{
  ATermList messages = ATempty;

  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_CondEquationToTerm(condEquation)))) {
    return makeAmbiguityMessage();
  }
  else {
    ASF_Tag tag = ASF_getCondEquationTag(condEquation);

    ASF_Equation equation = ASF_getCondEquationEquation(condEquation);
  
    if (PT_isTreeAmb(PT_TreeFromTerm(ASF_EquationToTerm(equation)))) {
      return makeAmbiguityMessage();
    }
    else {
      ASF_Tree lhsEq = ASF_getEquationLhs(equation);
      ASF_Tree rhsEq = ASF_getEquationRhs(equation);
      PT_Args variables = collectVariables((PT_Tree)lhsEq, 
				           PT_makeArgsEmpty());

      if (ASF_hasCondEquationConditions(condEquation)) {
        messages = ATconcat(messages,
			    checkConditions(tag,
				    ASF_getCondEquationConditions(condEquation),
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

ATermList checkCondEquationList(ASF_CondEquationList condEquationList) 
{
  ATermList messages = ATempty;
  
  while (!ASF_isCondEquationListEmpty(condEquationList)) {
    ASF_CondEquation condEquation =
      ASF_getCondEquationListHead(condEquationList);
    
    messages = ATconcat(messages,
                        checkEquation(condEquation));

    if (!ASF_hasCondEquationListTail(condEquationList)) {
      break;
    }
    condEquationList = ASF_getCondEquationListTail(condEquationList);
  }
  return messages;
}

ATermList checkEquations(ASF_Equations equations) 
{
  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_EquationsToTerm(equations)))) {
    return makeAmbiguityMessage();
  }
  if (ASF_isEquationsPresent(equations)) {
    ASF_CondEquationList condEquationList = 
      ASF_getEquationsList(equations);
  
    return checkCondEquationList(condEquationList);
  }
  return ATempty;
}
