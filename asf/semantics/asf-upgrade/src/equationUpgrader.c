#include <aterm2.h>
#include <ASFME-utils.h>
#include <MEPT-utils.h>

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

/*{{{  static ATermList upgradeTreeGivenVariables(ASF_ASFTag tag,  */

static ATermList upgradeTreeGivenVariables(ASF_ASFTag tag, 
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
                          upgradeTreeGivenVariables(tag, arg, variables));

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

/*{{{  static ATermList upgradePositiveCondition(ASF_ASFCondition condition, PT_Args *variables)  */

static ASF_ASFCondition upgradePositiveCondition(ASF_ASFCondition condition, PT_Args *variables) 
{
  ASF_Symbol sym = ASF_getASFConditionLhsSymbol(condition);
  ASF_Tree lhsCond = ASF_getASFConditionLhs(condition);
  ASF_Tree rhsCond = ASF_getASFConditionRhs(condition);
  ASF_OptLayout l1 = ASF_getASFConditionWsAfterLhs(condition);
  ASF_OptLayout l2 = ASF_getASFConditionWsAfterEquals(condition);

  ATbool noNewLhs = noNewVariables((PT_Tree) lhsCond, *variables);
  ATbool noNewRhs = noNewVariables((PT_Tree) rhsCond, *variables);

  if (noNewLhs && noNewRhs) {
    return ASF_makeASFConditionEquality(sym,sym,lhsCond,l1,l2,rhsCond);
  }
  else if (noNewLhs) {
    return ASF_makeASFConditionMatch(sym,sym,rhsCond,l1,l2,lhsCond);
  }
  else if (noNewRhs) {
    return ASF_makeASFConditionMatch(sym,sym,lhsCond,l1,l2,rhsCond);
  }

  return condition;
}

/*}}}  */

/*{{{  static ASF_ASFCondition upgradeCondition(ASF_ASFCondition condition, PT_Args *variables)  */

static ASF_ASFCondition upgradeCondition(ASF_ASFCondition condition, PT_Args *variables) 
{
  if (ASF_isASFConditionPositive(condition)) {
    condition =  upgradePositiveCondition(condition, variables);
  }

  return condition;
}

/*}}}  */

/*{{{  static ASF_ASFConditions upgradeConditions(ASF_ASFTag tag, ASF_ASFConditions conditions, PT_Args *variables)  */

static ASF_ASFConditions upgradeConditions(ASF_ASFConditions conditions, PT_Args *variables) 
{
  ASF_ASFConditionList conditionList = ASF_getASFConditionsList(conditions);
  ASF_ASFConditionList new = NULL;
  ASF_OptLayout l1 = NULL;
  ASF_OptLayout l2 = NULL;

  while (ASF_hasASFConditionListHead(conditionList)) {
    ASF_ASFCondition condition = ASF_getASFConditionListHead(conditionList);

    condition = upgradeCondition(condition, variables);

    if (new == NULL) {
      new = ASF_makeASFConditionListSingle(condition);
    }
    else {
      new = ASF_makeASFConditionListMany(condition, l2,",",l1, new);

    }

    if (!ASF_hasASFConditionListTail(conditionList)) {
      break;
    }
    else {
      l1 = ASF_getASFConditionListWsAfterFirst(conditionList);
      l2 = ASF_getASFConditionListWsAfterSep(conditionList);
    }

    conditionList = ASF_getASFConditionListTail(conditionList);
  }

  new = (ASF_ASFConditionList) ATreverse((ATermList) new);

  return ASF_makeASFConditionsDefault(new);
}

/*}}}  */

/*{{{  static ASF_ASFConditionalEquation upgradeEquation(ASF_ASFConditionalEquation condEquation)  */

static ASF_ASFConditionalEquation upgradeEquation(ASF_ASFConditionalEquation condEquation) 
{
  ASF_ASFEquation eq = ASF_getASFConditionalEquationASFEquation(condEquation);
  ASF_Tree lhsEq = ASF_getASFEquationLhs(eq);
  PT_Args variables = collectVariables((PT_Tree)lhsEq, PT_makeArgsEmpty());

  if (ASF_hasASFConditionalEquationASFConditions(condEquation)) {
    ASF_ASFConditions conds = ASF_getASFConditionalEquationASFConditions(
				condEquation);
    condEquation = ASF_setASFConditionalEquationASFConditions(condEquation,
						 upgradeConditions(conds, 
								   &variables));
  }

  return condEquation;
}

/*}}}  */

/*{{{  ASF_ASFConditionalEquationList upgradeASFConditionalEquationList(ASF_ASFConditionalEquationList condEquationList)  */

ASF_ASFConditionalEquationList upgradeASFConditionalEquationList(ASF_ASFConditionalEquationList condEquationList) 
{
  ASF_ASFConditionalEquationList new = NULL;
  ASF_OptLayout l = NULL;
  
  while (!ASF_isASFConditionalEquationListEmpty(condEquationList)) {
    ASF_ASFConditionalEquation condEquation =
      ASF_getASFConditionalEquationListHead(condEquationList);
    
    condEquation = upgradeEquation(condEquation);

    if (new == NULL) {
      new = ASF_makeASFConditionalEquationListSingle(condEquation);
    }
    else {
      new = ASF_makeASFConditionalEquationListMany(condEquation,l,new);
    }

    if (!ASF_hasASFConditionalEquationListTail(condEquationList)) {
      break;
    }
    else {
      l = ASF_getASFConditionalEquationListWsAfterFirst(condEquationList);
    }

    condEquationList = ASF_getASFConditionalEquationListTail(condEquationList);
  }

  return (ASF_ASFConditionalEquationList) ATreverse((ATermList) new);
}

/*}}}  */

/*{{{  ASF_ASFEquations upgradeEquations(ASF_ASFEquations equations)  */

ASF_ASFEquations upgradeEquations(ASF_ASFEquations equations) 
{
  if (ASF_hasASFEquationsList(equations)) {
    ASF_ASFConditionalEquationList condEquationList = ASF_getASFEquationsList(equations);
  
    equations = ASF_setASFEquationsList(equations,
					upgradeASFConditionalEquationList(condEquationList));
  }

   return equations;
}

/*}}}  */
