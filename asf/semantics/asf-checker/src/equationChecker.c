/* $Id$ */

#include <ctype.h>

#include <Error.h>
#include "equationChecker.h"
#include "statistics.h"

/*{{{  static int ASF_getASFConditionsListLength(ASF_ASFConditionsList l) */

static int ASF_getASFConditionsListLength(ASF_ASFConditionList l)
{
  return (ATgetLength((ATermList) l) / 4) + 1;
}

/*}}}  */

/*{{{  static ERR_SubjectList treeToSubjectList(PT_Tree tree) */

static ERR_SubjectList treeToSubjectList(PT_Tree tree)
{
  ERR_SubjectList subjects = ERR_makeSubjectListEmpty();
  LOC_Location location = PT_getTreeLocation(tree);

  if (location != NULL) {
    char *yield = PT_yieldTree(tree);
    ERR_Subject sub = ERR_makeSubjectLocalized(yield, (ERR_Location) location);
    subjects = ERR_makeSubjectListSingle(sub);
  }

  return subjects;
}

/*}}}  */

/*{{{  ERR_Error makeMessage(const char *msg, ATerm subject) */

ERR_Error makeMessage(const char *msg, ATerm subject)
{
  return ERR_makeErrorError(msg, treeToSubjectList(PT_TreeFromTerm(subject)));
}

/*}}}  */
/*{{{  ERR_Error makeWarning(const char *msg, ATerm subject) */

ERR_Error makeWarning(const char *msg, ATerm subject)
{
  return ERR_makeErrorWarning(msg, treeToSubjectList(PT_TreeFromTerm(subject)));
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

    if (ATisEqualModuloAnnotations((ATerm) tree, (ATerm) variable)) {
      return ATtrue;
    }

    variables = PT_getArgsTail(variables);
  }
  return ATfalse;
}

/*}}}  */

/*{{{  static void normalizeSortname(char *name) */

static void normalizeSortname(char *name)
{
  int from,to;
  int len = strlen(name);

  for (from = 0, to = 0; from < len; from++, to++) {
    name[to] = tolower(name[from]);

    if (!isalpha((int) name[from])) {
      to--;
    }
  }
}

/*}}}  */

/*{{{  static ERR_ErrorList checkForPossibleVariables(PT_Tree lexical) */

static ERR_ErrorList checkForPossibleVariables(PT_Tree lexical)
{
  ERR_ErrorList messages = ERR_makeErrorListEmpty();
  PT_Production prod = PT_getTreeProd(lexical);
  PT_Symbol rhs = PT_getProductionRhs(prod);
  char *treeString = strdup(PT_yieldTree(lexical));
  char *symbolString = strdup(PT_yieldSymbol(rhs));
  char message[1024];

  normalizeSortname(treeString); 
  normalizeSortname(symbolString);

  if (strcmp(treeString, symbolString) == 0) {
    sprintf(message, "Lexical probably intended to be a variable: %s",
	    PT_yieldTree(lexical));
    messages = ERR_makeErrorListSingle(
      makeWarning(message, PT_TreeToTerm(lexical)));
  }

  free(treeString);
  free(symbolString);

  return messages;
}

/*}}}  */
/*{{{  static ERR_ErrorList locatePossibleVariables(PT_Tree tree) */

static ERR_ErrorList locatePossibleVariables(PT_Tree tree)
{
  ERR_ErrorList messages = ERR_makeErrorListEmpty();

  if (PT_isTreeLexical(tree)) {
    return checkForPossibleVariables(tree);
  }

  if (PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);

    while (!PT_isArgsEmpty(args)) {
      PT_Tree arg = PT_getArgsHead(args);

      messages = ERR_concatErrorList(messages, locatePossibleVariables(arg));

      args = PT_getArgsTail(args);
    }
  }

  return messages;
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
				     checkTreeGivenVariables(tag, 
							     arg, variables));
      messages = ERR_concatErrorList(messages, locatePossibleVariables(arg));

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
    return PT_makeArgsMany(tree, varList);
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

static ATbool isContextFreeSingleton(PT_Tree tree) 
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

    if (PT_isLexicalProd(prod)) {
      return ATfalse;
    }
    else if (PT_isProductionList(prod)) {
      if (PT_getArgsLength(args) == 1) {
	return !PT_isTreeVar(PT_getArgsHead(args));
      }
    }
    else {
      if (PT_isProductionInjection(prod)) {
	return isContextFreeSingleton(PT_getArgsHead(args));
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
					     ASF_ASFConditionToTerm(condition)));
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

  messages = ERR_makeErrorListSingle(makeWarning("Deprecated condition syntax \"=\". Please use either \"==\" for equality, or \":=\" for matching (Hint: see the Upgrade menu)",
						 ASF_ASFConditionToTerm(condition)));

  if (noNewVariables((PT_Tree) lhsCond, *variables)) {
    *variables = collectVariables((PT_Tree)rhsCond, *variables);
    messages = ERR_concatErrorList(messages, 
				   locatePossibleVariables((PT_Tree) rhsCond));
    return messages;
  }
  else if (noNewVariables((PT_Tree) rhsCond, *variables)) {
    *variables = collectVariables((PT_Tree)lhsCond, *variables);
    messages = ERR_concatErrorList(messages, 
				   locatePossibleVariables((PT_Tree) lhsCond));
    return messages;
  }
  else {
    return ERR_makeErrorListMany(makeMessage("uninstantiated variables in both sides of condition",
					     ASF_ASFConditionToTerm(condition)),
				 messages);
  }


}

/*}}}  */
/*{{{  static ERR_ErrorList checkEqualityCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ERR_ErrorList checkEqualityCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  ERR_ErrorList messages;

  messages = locatePossibleVariables((PT_Tree) lhsCond);
  messages = ERR_concatErrorList(messages,
				 locatePossibleVariables((PT_Tree) rhsCond));

  if (!noNewVariables((PT_Tree) lhsCond, *variables) || 
      !noNewVariables((PT_Tree) rhsCond, *variables)) {
    messages = ERR_concatErrorList(messages,
				   ERR_makeErrorListSingle(
				 makeMessage(
			    "uninstantiated variables in equality condition",
			     ASF_ASFConditionToTerm(condition))));
  }

  return messages;
}

/*}}}  */
/*{{{  static ERR_ErrorList checkMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ERR_ErrorList checkMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  ERR_ErrorList messages = ERR_makeErrorListEmpty();

  if (!noNewVariables((PT_Tree) rhsCond, *variables)) {
    return ERR_makeErrorListSingle(
	 makeMessage(
	     "right-hand side of matching condition introduces variables",
	     ASF_ASFConditionToTerm(condition)));
  }

  if (noNewVariables((PT_Tree) lhsCond, *variables)) {
    return ERR_makeErrorListSingle(
	 makeMessage(
	     "matching condition does not introduce new variables",
		     ASF_ASFConditionToTerm(condition)));
  }
  else {
    *variables = collectVariables((PT_Tree)lhsCond, *variables);
    messages = ERR_concatErrorList(messages, 
				   locatePossibleVariables((PT_Tree) lhsCond));
  }

  return messages;
}

/*}}}  */
/*{{{  static ERR_ErrorList checkNoMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables)  */

static ERR_ErrorList checkNoMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *variables) 
{
  if (noNewVariables((PT_Tree) lhsCond, *variables)) {
    return ERR_makeErrorListSingle(makeMessage("matching condition does not use new variables",
					       ASF_ASFConditionToTerm(condition)));
  }

  if (!noNewVariables((PT_Tree) rhsCond, *variables)) {
    return ERR_makeErrorListSingle(makeMessage("right-hand side of matching condition introduces variables",
					       ASF_ASFConditionToTerm(condition)));
  }

  return ERR_makeErrorListEmpty();
}

/*}}}  */
/*{{{  static ERR_ErrorList checkCondition(ASF_ASFTag tag, ASF_ASFCondition condition, PT_Args *variables)  */

static ERR_ErrorList checkCondition(ASF_ASFTag tag, ASF_ASFCondition condition, PT_Args *variables) 
{

  SCOUNT(nrConditions);

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
      SCOUNT(nrInequalityConditions);
      return checkNegativeCondition(tag, condition, lhsCond, rhsCond, variables);
    }
    else if (ASF_isASFConditionPositive(condition)) {
      SCOUNT(nrEqualityConditions);
      return checkPositiveCondition(tag, condition, lhsCond, rhsCond, variables);
    }
    else if (ASF_isASFConditionMatch(condition)) {
      SCOUNT(nrAssignmentConditions);
      return checkMatchCondition(tag, condition, lhsCond, rhsCond, variables);
    }
    else if (ASF_isASFConditionNoMatch(condition)) {
      SCOUNT(nrNonAssignmentConditions);
      return checkNoMatchCondition(tag, condition, lhsCond, rhsCond, variables);
    }
    else if (ASF_isASFConditionEquality(condition)) {
      SCOUNT(nrEqualityConditions);
      return checkEqualityCondition(tag, condition, lhsCond, rhsCond, variables);
    }
    else {
      return ERR_makeErrorListSingle(makeMessage("strange condition encountered", 
						 ASF_ASFConditionToTerm(condition)));
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

    SMAX(maxNrConditionsPerEquation, 
	 ASF_getASFConditionsListLength(conditionList));

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
    SADD(outermostFunctions, PT_getTreeProd(ptTree));

    if (PT_hasProductionConstructorAttr(PT_getTreeProd(ptTree))) {
      ERR_Error message = 
	makeWarning(
    "constructor not expected as outermost function symbol of left hand side", 
    PT_TreeToTerm(ptTree));
      return ERR_makeErrorListSingle(message);
    }
    else if (isContextFreeSingleton(ptTree)) {
      ERR_Error message = 
          makeMessage(
          "Left hand side is contained in a list", PT_TreeToTerm(ptTree));
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

  SCOUNT(nrEquations);

  if (ASF_isTagDefault(ASF_getASFConditionalEquationASFTag(condEquation))) {
    SCOUNT(nrDefaultEquations);
  }

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
      messages = ERR_concatErrorList(messages, 
				     locatePossibleVariables((PT_Tree)lhsEq));

      if (ASF_hasASFConditionalEquationASFConditions(condEquation)) {
	SCOUNT(nrEquationsWithConditions);
	messages = ERR_concatErrorList(messages,
					  checkConditions(tag,
							  ASF_getASFConditionalEquationASFConditions(condEquation),
							  &variables));
      }

      messages =  ERR_concatErrorList(messages,
				      checkTreeGivenVariables(tag, 
							      (PT_Tree)rhsEq, 
								 variables));
      messages = ERR_concatErrorList(messages, 
				     locatePossibleVariables((PT_Tree) rhsEq));

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
      messages = ERR_concatErrorList(messages, 
				     locatePossibleVariables((PT_Tree)rhsCond));
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
