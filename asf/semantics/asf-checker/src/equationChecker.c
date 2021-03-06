/* $Id$ */

/* TODO: Aren't error messages slightly off-topic in this file?
** TODO: Refactor checkTree() away?
**       (by makinbg it part of checkVariables())
** TODO: See whether we can eliminate some other *Variables() functions?
** TODO: checkVariables() delivers a listof newly introduced variables
**       These can be shown in an error message
** TODO: Add error-messages for used wild's in reportUsedWildVariables()
** TODO: Add error-messages for unused strict's in reportUnusedVariables()
** TODO: Delete is done by creating a new list, which is kind of expensive
** TODO: Do we want a single error message with a single subject for each single variable,
**       or a single message for each variable? (in generateVariablesMessage())
** TODO: A lot of functions do not use their formal parameter 'tag'
*/

#include <ctype.h>
#include <assert.h>

#include <Error.h>
#include <asfnormalization.h>
#include "equationChecker.h"
#include "statistics.h"

static ERR_Location currentLocation = NULL;

/*{{{  static ATbool isCHARinjection(PT_Tree tree) */

static ATbool isCHARinjection(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
      PT_Attr attr = 
	PT_makeAttrTerm(ATparse("lexical-constructor-character-injection"));

    return PT_hasProductionCertainAttr(prod, attr) ? ATtrue : ATfalse;
  }

  return ATfalse;
}

/*}}}  */

/*{{{  static ATbool isLayoutBracket(PT_Tree tree) */

static ATbool isLayoutBracket(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Attr attr = PT_makeAttrTerm(ATparse("layout-bracket"));

    return PT_hasProductionCertainAttr(prod, attr);
  }

  return ATfalse;
}

/*}}}  */
/*{{{  static ATbool isLexicalConstructor(PT_Tree tree) */

static ATbool isLexicalConstructor(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Attr attr = PT_makeAttrTerm(ATparse("lexical-constructor"));

    return PT_hasProductionCertainAttr(prod, attr);
  }

  return ATfalse;
}

/*}}}  */

/*{{{  static PT_Symbol getOuterCharacterClass(PT_Production prod) */

static PT_Symbol getOuterCharacterClass(PT_Production prod)
{
  PT_Symbol rhs = PT_getProductionRhs(prod);
  PT_Symbol cf = PT_getSymbolSymbol(rhs);
  PT_Symbol param = PT_getSymbolsHead(PT_getSymbolParameters(cf));

  return param;
}

/*}}}  */
/*{{{  static PT_Symbol getInnerCharacterClass(PT_Production prod) */

static PT_Symbol getInnerCharacterClass(PT_Production prod)
{
  PT_Symbol lhs = PT_getSymbolsHead(PT_getProductionLhs(prod));
  PT_Symbol cf = PT_getSymbolSymbol(lhs);
  PT_Symbol param = PT_getSymbolsHead(PT_getSymbolParameters(cf));

  return param;
}

/*}}}  */

/*{{{  static ERR_ErrorList checkCHARinjection(PT_Tree tree) */

static ERR_ErrorList checkCHARinjection(PT_Tree tree)
{
  PT_Production outerProd = PT_getTreeProd(tree);
  PT_Symbol outerCC = getOuterCharacterClass(outerProd);
  PT_Tree inner = PT_getArgsHead(PT_getTreeArgs(tree));

  if (PT_isTreeAppl(inner)) {
    PT_Production innerProd = PT_getTreeProd(inner);
    PT_Attr varAttr = 
      PT_makeAttrTerm(ATparse("lexical-constructor-character"));

    if (PT_hasProductionCertainAttr(innerProd, varAttr)) {
      /* A variable that ranges over a lexical */
      PT_Symbol innerCC = getInnerCharacterClass(innerProd);

      assert(PT_isSymbolCharClass(innerCC));
      assert(PT_isSymbolCharClass(outerCC));

      if (!PT_subsetOfCharClass(innerCC, outerCC)) {
	const char* innerCCstr = PT_yieldSymbol(innerCC);
	ERR_Subject innerSub = ERR_makeSubjectSubject(innerCCstr);
	const char* outerCCstr = PT_yieldSymbol(outerCC);
	ERR_Subject outerSub = ERR_makeSubjectSubject(outerCCstr);
	ERR_Error error = makeMessage(
	   "lexical variable accepts more characters than allowed in this context"
	   , (ATerm) tree);
	ERR_SubjectList subjects = ERR_getErrorList(error);
	subjects = ERR_makeSubjectListMany(innerSub, subjects);
	subjects = ERR_makeSubjectListMany(outerSub, subjects);
	error = ERR_setErrorList(error, subjects);
	return ERR_makeErrorListSingle(error);
      }
    }
    else {
      /* We do not have a variable, but a character, encoded in
       * the SDF character class style
       */
      PT_Tree normalized = normalizeCharacter(tree);

      assert(PT_isTreeChar(normalized));

      if (!PT_elementOfCharClass(normalized, outerCC)) {
	const char* outerCCstr = PT_yieldSymbol(outerCC);
	ERR_Subject outerSub = ERR_makeSubjectSubject(outerCCstr);
	ERR_Error error = makeMessage(
	   "character is not allowed in this context", (ATerm) tree);
	ERR_SubjectList subjects = ERR_getErrorList(error);
	subjects = ERR_makeSubjectListMany(outerSub, subjects);
	error = ERR_setErrorList(error, subjects);
	return ERR_makeErrorListSingle(error);
      }
    }
  }

  return ERR_makeErrorListEmpty();

}

/*}}}  */

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
  ERR_Location location = PT_getTreeLocation(tree);
  const char *yield = PT_yieldTreeToString(tree, ATfalse);
  ERR_Subject sub;

  if (location != NULL) {
    sub = ERR_makeSubjectLocalized(yield, (ERR_Location) location);
  }
  else {
    sub = ERR_makeSubjectLocalized(yield, (ERR_Location) currentLocation);
  }

  subjects = ERR_makeSubjectListSingle(sub);

  return subjects;
}

/*}}}  */

/*{{{  ERR_Error makeMessage(const char *msg, ATerm subject) */

ERR_Error makeMessage(const char *msg, ATerm subject)
{
  return ERR_makeErrorError(msg, treeToSubjectList(PT_TreeFromTerm(subject)));
}

/*}}}  */
/*{{{  ERR_Error makeMessage2(const char *msg, ATerm subject1, ATerm subject2) */

ERR_Error makeMessage2(const char *msg, ATerm subject1, ATerm subject2)
{
  ERR_SubjectList l1 = treeToSubjectList(PT_TreeFromTerm(subject1));
  ERR_SubjectList l2 = treeToSubjectList(PT_TreeFromTerm(subject2));

  return ERR_makeErrorError(msg, ERR_concatSubjectList(l1, l2));
}

/*}}}  */
/*{{{  ERR_Error makeMessage3(const char *msg, ATerm subject1, ATerm subject2, ATerm subject3) */

ERR_Error makeMessage3(const char *msg, ATerm subject1, ATerm subject2, ATerm subject3)
{
  ERR_SubjectList l1 = treeToSubjectList(PT_TreeFromTerm(subject1));
  ERR_SubjectList l2 = treeToSubjectList(PT_TreeFromTerm(subject2));
  ERR_SubjectList l3 = treeToSubjectList(PT_TreeFromTerm(subject2));

  return ERR_makeErrorError(msg, 
	    ERR_concatSubjectList(ERR_concatSubjectList(l1, l2), l3));
}

/*}}}  */
/*{{{  ERR_Error makeWarning(const char *msg, ATerm subject) */

ERR_Error makeWarning(const char *msg, ATerm subject)
{
  return ERR_makeErrorWarning(msg, treeToSubjectList(PT_TreeFromTerm(subject)));
}

/*}}}  */

/*{{{  static ATbool findVariableAttr(PT_Tree var, PT_Attr attr) */

static ATbool findVariableAttr(PT_Tree var, PT_Attr attr)
{
  PT_Args args;
  PT_Tree arg;

  assert(PT_isTreeAppl(var));

  args = PT_getTreeArgs(var);

  assert(!PT_isArgsEmpty(args));

  arg = PT_getArgsHead(args);

  assert(PT_isArgsEmpty(PT_getArgsTail(args)));

  return PT_hasProductionCertainAttr(PT_getTreeProd(arg), attr);
}

/*}}}  */
/*{{{  static ATbool isStrictVariable(PT_Tree var) */

static ATbool isStrictVariable(PT_Tree var)
{
  PT_Attr strictAttr = PT_makeAttrTerm(ATparse("strict"));

  return findVariableAttr(var, strictAttr);
}

/*}}}  */
/*{{{  static ATbool isWildVariable(PT_Tree var) */

static ATbool isWildVariable(PT_Tree var)
{
  PT_Attr wildAttr = PT_makeAttrTerm(ATparse("wild"));

  return findVariableAttr(var, wildAttr);
}

/*}}}  */
/*{{{  ERR_ErrorList makeAmbiguityMessage(void *subject) */

ERR_ErrorList makeAmbiguityMessage(void *subject)
{
  return ERR_makeErrorListSingle(makeMessage("equations contain ambiguities",
						(ATerm) subject));
}

/*}}}  */

/*{{{  static ERR_ErrorList reportUnusedVariables(ASF_ASFTag tag, PT_Args definedVars) */

static ERR_ErrorList reportUnusedVariables(ASF_ASFTag tag, PT_Args definedVars)
{
  ERR_ErrorList messages = ERR_makeErrorListEmpty();
  ERR_Error message;

  while (!PT_isArgsEmpty(definedVars)) {
    PT_Tree variable = PT_getArgsHead(definedVars);

    if (isStrictVariable(variable)) {
      message = makeWarning("\"strict\" variable must be used at least once", 
			    PT_TreeToTerm(variable));
      messages = ERR_concatErrorList(messages,
				   ERR_makeErrorListSingle(message));
    }

    definedVars = PT_getArgsTail(definedVars);
  }

  return messages;
}

/*}}}  */
/*{{{  static ERR_ErrorList reportUsedWildVariables(ASF_ASFTag tag, PT_Args usedVars) */

static ERR_ErrorList reportUsedWildVariables(ASF_ASFTag tag, PT_Args usedVars)
{
  ERR_ErrorList messages = ERR_makeErrorListEmpty();
  ERR_Error message;

  while (!PT_isArgsEmpty(usedVars)) {
    PT_Tree variable = PT_getArgsHead(usedVars);

    if (isWildVariable(variable)) {
      message = makeWarning("\"wild\" variable may not be used", 
			    PT_TreeToTerm(variable));
      messages = ERR_concatErrorList(messages,
				   ERR_makeErrorListSingle(message));
    }

    usedVars = PT_getArgsTail(usedVars);
  }

  return messages;
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

/*{{{  static PT_Args deleteVariable(PT_Tree tree, PT_Args variables) */

static PT_Args deleteVariable(PT_Tree tree, PT_Args variables)
{
  PT_Args newVariables = PT_makeArgsEmpty();

  while (!PT_isArgsEmpty(variables)) {
    PT_Tree variable = PT_getArgsHead(variables);

    if (!ATisEqualModuloAnnotations((ATerm) tree, (ATerm) variable)) {
      newVariables = PT_makeArgsMany(variable,newVariables);
    }

    variables = PT_getArgsTail(variables);
  }
  return newVariables;
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

/*{{{  static ATbool isIgnored(PT_Tree tree) */

static ATbool isIgnored(PT_Tree tree)
{
  if (PT_isTreeVar(tree)) {
    return ATfalse;
  }
  else if (isLexicalConstructor(tree)) {
    return ATfalse;
  }
  else if (isLayoutBracket(tree)) { 
    return ATfalse;
  }

  if (PT_hasTreeArgs(tree)) {
    PT_Args args = PT_getTreeArgs(tree);

    for ( ;!PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
      PT_Tree arg = PT_getArgsHead(args);

      if (!isIgnored(arg)) {
	return ATfalse;
      }
    }
  }

  return ATtrue;
}

/*}}}  */

/*{{{  static ATbool isLexicalTree(PT_Tree tree) */

static ATbool isLexicalTree(PT_Tree tree)
{
  if (PT_isTreeLexical(tree)) {
    return ATtrue;
  }
  else if (PT_hasTreeProd(tree) 
	   && PT_isProductionInjection(PT_getTreeProd(tree))) {
    return isLexicalTree(PT_getArgsHead(PT_getTreeArgs(tree)));
  }
  else {
    return ATfalse;
  }
}

/*}}}  */

/*{{{  static ATbool isCHARSSymbol(PT_Symbol symbol) */

static ATbool isCHARSSymbol(PT_Symbol symbol)
{
  if (PT_isSymbolCf(symbol)) {
    symbol = PT_getSymbolSymbol(symbol);
  }

  if (PT_isSymbolParameterizedSort(symbol)) {
    return !strcmp(PT_getSymbolSort(symbol), "CHARS");
  }

  return ATfalse;
}

/*}}}  */

/*{{{  static ERR_ErrorList checkNoOrphanCharVar(PT_Tree tree)  */

ERR_ErrorList checkNoOrphanCharVar(PT_Tree tree) 
{
  if (PT_isTreeAppl(tree)) {
    PT_Symbols symbols = PT_getProductionLhs(PT_getTreeProd(tree));

    if (PT_getSymbolsLength(symbols) == 1) {
      if (isCHARSSymbol(PT_getSymbolsHead(symbols))) {
	PT_Tree arg = PT_getArgsHead(PT_getTreeArgs(tree));

	if (PT_isTreeAppl(arg)) {
	  PT_Symbols lhs = PT_getProductionLhs(PT_getTreeProd(arg));

	  if (PT_getSymbolsLength(lhs) == 1) {
	    PT_Symbol var = PT_getSymbolsHead(lhs);

	    if (PT_isSymbolVarSym(var)) {
	      if (isCHARSSymbol(PT_getSymbolSymbol(var))) {
		ERR_Error err = makeMessage("Illegal use of lexical variable used outside of lexical constructor context", (ATerm) tree);
		return ERR_makeErrorListSingle(err);
	      }
	    }
	  }
	}
      }
    }
  }

  return ERR_makeErrorListEmpty();
}

/*}}}  */
/*{{{  static ERR_ErrorList checkIgnoredLayout(PT_Tree tree) */

static ERR_ErrorList checkIgnoredLayout(PT_Tree tree)
{
  ERR_ErrorList messages = ERR_makeErrorListEmpty();
  PT_Production prod = PT_getTreeProd(tree);
  PT_Args args = PT_getTreeArgs(tree);
  PT_Symbol rhs = PT_getProductionRhs(prod);
  ATbool separated = PT_isIterSepSymbol(rhs);
  ERR_Error message;

  if (!PT_isSymbolCf(rhs)) {
    return messages;
  }

  while (!PT_isArgsEmpty(args)) {
    PT_Tree arg = PT_getArgsHead(args);
    PT_Tree next = NULL;
    const char *msg = "layout surrounding a star variable "
      "is always ignored, use a plus variable";
    ATbool nextIsStarVar = ATfalse;

    if (PT_getArgsLength(args) >= (separated ? 5 : 3)) {
      next = PT_getArgsTreeAt(args, separated ? 4 : 2);
      if (PT_isTreeVarListStar(next)) {
	nextIsStarVar = ATtrue;
      }
    }


    if (nextIsStarVar || PT_isTreeVarListStar(arg)) {
      if (!separated) {
	if (PT_getArgsLength(args) >= 2) {
	  PT_Tree layout = PT_getArgsTreeAt(args, 1);

	  assert(PT_isTreeLayout(layout));

	  if (!isIgnored(layout)) {
	    message = makeMessage2(msg, 
				  PT_TreeToTerm(nextIsStarVar ? next : arg ),
				  PT_TreeToTerm(layout));
	    messages = ERR_concatErrorList(messages,
					   ERR_makeErrorListSingle(message));
	  }
	}
      }
      else { /* separated */
	if (PT_getArgsLength(args) >= 4) {
	  PT_Tree layoutBeforeSep = PT_getArgsTreeAt(args, 1);
	  PT_Tree layoutAfterSep = PT_getArgsTreeAt(args, 3);

	  assert(PT_isTreeLayout(layoutAfterSep));
	  assert(PT_isTreeLayout(layoutBeforeSep));

	  if (!isIgnored(layoutBeforeSep)) {

	    message = makeMessage2(msg, 
				  PT_TreeToTerm(nextIsStarVar ? next : arg),
				  PT_TreeToTerm(layoutBeforeSep));
	    messages = ERR_concatErrorList(messages,
					   ERR_makeErrorListSingle(message));
	  }
	  if (!isIgnored(layoutAfterSep)) {
	    message = makeMessage2(msg, 
				  PT_TreeToTerm(nextIsStarVar ? next : arg),
				  PT_TreeToTerm(layoutAfterSep));
	    messages = ERR_concatErrorList(messages,
					   ERR_makeErrorListSingle(message));
	  }
	}
      }
    }

    if (separated && PT_getArgsLength(args) >= 4) {
      args = PT_getArgsTail(PT_getArgsTail(PT_getArgsTail(args)));
    }
    else if (PT_getArgsLength(args) >= 2) {
      args = PT_getArgsTail(PT_getArgsTail(args));
    }
    else {
      break;
    }
  }

  return messages;
}

/*}}}  */
/*{{{  static ERR_ErrorList checkForPossibleVariables(PT_Tree lexical) */

static ERR_ErrorList checkForPossibleVariables(PT_Tree lexical)
{
  ERR_ErrorList messages = ERR_makeErrorListEmpty();
  PT_Production prod = PT_getTreeProd(lexical);
  PT_Symbol rhs = PT_getProductionRhs(prod);
  char *treeString = strdup(PT_yieldTreeToString(lexical, ATfalse));
  char *symbolString = strdup(PT_yieldSymbol(rhs));
  char message[1024];

  normalizeSortname(treeString); 
  normalizeSortname(symbolString);

  if (strlen(treeString) > 0
      && strcmp(treeString, symbolString) == 0) {
    sprintf(message, "Lexical probably intended to be a variable: %s",
	    PT_yieldTreeToString(lexical, ATfalse));
    messages = ERR_makeErrorListSingle(
      makeWarning(message, PT_TreeToTerm(lexical)));
  }

  free(treeString);
  free(symbolString);

  return messages;
}

/*}}}  */
/*{{{  static ERR_ErrorList checkTree(PT_Tree tree) */

static ERR_ErrorList checkTree(PT_Tree tree, ATbool inLexicalConstructor)
{
  ERR_ErrorList messages = ERR_makeErrorListEmpty();

  if (isLexicalTree(tree)) {
    messages = checkForPossibleVariables(tree);
  }

  if (isCHARinjection(tree)) {
    messages = checkCHARinjection(tree);
  }

  if (PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);

    /*messages = ERR_concatErrorList(messages, checkNoOrphanCharVar(tree));*/

    while (!PT_isArgsEmpty(args)) {
      PT_Tree arg = PT_getArgsHead(args);
      ATbool lexicalConstructor = isLexicalConstructor(arg);

      messages = ERR_concatErrorList(messages, checkTree(arg, 
							 lexicalConstructor));

      args = PT_getArgsTail(args);
    }
  }

  /* we check if star variables are surrounded by layout patterns */
  if (!inLexicalConstructor && PT_isTreeApplList(tree)) {
    messages = ERR_concatErrorList(checkIgnoredLayout(tree), messages);
  }

  return messages;
}

/*}}}  */

/* {{{ static ERR_ErrorList generateVariablesMessage(char *msg, PT_Args vars) */

static ERR_ErrorList generateVariablesMessage(char *msg, PT_Args vars)
{
  ERR_Error message;
  ERR_ErrorList messages = ERR_makeErrorListEmpty();

  while(!PT_isArgsEmpty(vars)) {
    PT_Tree variable = PT_getArgsHead(vars);

    message = makeMessage(msg, PT_TreeToTerm(variable));
    messages = ERR_concatErrorList(messages,
					     ERR_makeErrorListSingle(message));

    vars = PT_getArgsTail(vars);
  }

  return messages;
}
/*}}} */

/*{{{  static PT_Args checkVariables(PT_Tree tree, PT_Args *pDefVars, PT_Args *pUsedVars, ATbool *containsVariables) */

static PT_Args checkVariables(PT_Tree tree, PT_Args *pDefVars, PT_Args *pUsedVars)
{
  PT_Tree arg;
  PT_Args args, newVars;

  if (PT_isTreeAmb(tree)) {
    return PT_makeArgsEmpty();
  }
  if (PT_isTreeVar(tree)) {
    if(lookupVariable(tree, *pUsedVars)) {
      return PT_makeArgsEmpty();
    }
    if(!lookupVariable(tree, *pDefVars)) {
      *pDefVars = PT_makeArgsMany(tree, *pDefVars);
      return PT_makeArgsMany(tree, PT_makeArgsEmpty());
    }
    /* defined and not used -> move the var */
    *pDefVars = deleteVariable(tree, *pDefVars);
    *pUsedVars = PT_makeArgsMany(tree,*pUsedVars);
    return PT_makeArgsEmpty();
  }
  else if (PT_isTreeAppl(tree)) {
    newVars = PT_makeArgsEmpty();
    args = PT_getTreeArgs(tree);
    while (PT_hasArgsHead(args)) {
      arg = PT_getArgsHead(args);

      newVars = PT_concatArgs(checkVariables(arg, pDefVars, pUsedVars ),
					     
                               newVars);

      args = PT_getArgsTail(args);
    };

    return newVars;
  }
  else {
    return PT_makeArgsEmpty();
  }
}

/*}}}  */
/*{{{  static ATbool isConstant(PT_Tree tree) */

static ATbool isConstant(PT_Tree tree)
{
  ATbool result = ATtrue;

  /* TODO: add something for builtins with no arguments (they are
   * not necessarily constants due to side-effects) */

  if (PT_isTreeVar(tree)) {
    result = ATfalse;
  }
  else if (PT_hasTreeArgs(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    while (result && PT_hasArgsHead(args)) {
      PT_Tree arg = PT_getArgsHead(args);

      result = isConstant(arg);
      args = PT_getArgsTail(args);
    };
  }

  return result;
}

/*}}}  */


/* 1. The call to checkTree() is not needed in the function
 *    (after each call to checkTreeGivenVariables, checkTree 
 *    is also called, and the latter also recursively descends the tree)
 * 2. 'tag' is not used here
 */
/*{{{  static ERR_ErrorList checkTreeGivenVariables(ASF_ASFTag tag, PT_Tree tree,  */

static ERR_ErrorList checkTreeGivenVariables(ASF_ASFTag tag, PT_Tree tree, 
					PT_Args *pDefVars, PT_Args *pUsedVars)
{
  PT_Args newVars;

  if (PT_isTreeAmb(tree)) {
    return makeAmbiguityMessage(tree);
  }

  newVars=checkVariables(tree,pDefVars,pUsedVars);

  return generateVariablesMessage("uninstantiated variable occurrence",
						newVars);
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
	PT_Tree head = PT_getArgsHead(args);

	if (PT_isTreeVar(head)) {
	  return ATfalse;
	}

	/* a function returning a list is always a singleton, so no warning */
	if (PT_hasTreeProd(head)) {
	  PT_Production prod = PT_getTreeProd(head);

	  if (PT_prodHasIterSepAsRhs(prod) || PT_prodHasIterAsRhs(prod)) {
	    return ATfalse;
	  }
	}

	return ATtrue;
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

/*{{{  static ERR_ErrorList checkNegativeCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *pDefVars, PT_Args *pUsedVars)  */

static ERR_ErrorList checkNegativeCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *pDefVars, PT_Args *pUsedVars) 
{
  PT_Args lhsNewVars;
  PT_Args rhsNewVars;
  ERR_ErrorList messages = ERR_makeErrorListEmpty();

  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_TreeToTerm(lhsCond)))) {
    return makeAmbiguityMessage(lhsCond);
  }
  if (PT_isTreeAmb(PT_TreeFromTerm(ASF_TreeToTerm(rhsCond)))) {
    return makeAmbiguityMessage(rhsCond);
  }

  lhsNewVars = checkVariables((PT_Tree)lhsCond, pDefVars, pUsedVars );
			      
  rhsNewVars = checkVariables((PT_Tree)rhsCond, pDefVars, pUsedVars);
			      

  if (!PT_isArgsEmpty(lhsNewVars) || !PT_isArgsEmpty(rhsNewVars)) {
    return ERR_makeErrorListSingle(
                        makeMessage("negative condition introduces variable(s)", 
				    ASF_ASFConditionToTerm(condition)));
  }
  else if (isConstant((PT_Tree) lhsCond) && isConstant((PT_Tree) rhsCond)) {
    return ERR_makeErrorListSingle(
                        makeMessage("constant negative condition "
				    "(has no variables)",
				    ASF_ASFConditionToTerm(condition)));
  }

  return messages;
}

/*}}}  */
/*{{{  static ERR_ErrorList checkEqualityCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *pDefVars, PT_Args *pUsedVars)  */

static ERR_ErrorList checkEqualityCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *pDefVars, PT_Args *pUsedVars) 
{
  ERR_Error message;
  ERR_ErrorList messages;
  PT_Args lhsNewVars;
  PT_Args rhsNewVars;

  messages = checkTree((PT_Tree) lhsCond, ATfalse);
  messages = ERR_concatErrorList(messages,
				 checkTree((PT_Tree) rhsCond, ATfalse));

  lhsNewVars = checkVariables((PT_Tree) lhsCond, pDefVars, pUsedVars);
			      
  rhsNewVars = checkVariables((PT_Tree) rhsCond, pDefVars, pUsedVars);
			      

  if (!PT_isArgsEmpty(lhsNewVars) || !PT_isArgsEmpty(rhsNewVars)) {

    message = makeMessage("uninstantiated variables in equality condition",
			        ASF_ASFConditionToTerm(condition));
    messages = ERR_concatErrorList(messages,
				           ERR_makeErrorListSingle(message));
  }
  else if (isConstant((PT_Tree) lhsCond) && isConstant((PT_Tree) rhsCond)) {
    return ERR_makeErrorListSingle(
                        makeMessage("constant positive condition "
				    "(has no variables)",
				    ASF_ASFConditionToTerm(condition)));
  }
  

  return messages;
}

/*}}}  */
/*{{{  static ERR_ErrorList checkMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *pDefVars, PT_Args *pUsedVars)  */

static ERR_ErrorList checkMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *pDefVars, PT_Args *pUsedVars) 
{
  ERR_ErrorList messages = ERR_makeErrorListEmpty();
  PT_Args newVars;

  newVars = checkVariables((PT_Tree) rhsCond, pDefVars, pUsedVars);
  if (!PT_isArgsEmpty(newVars)) {
    return ERR_makeErrorListSingle(
	 makeMessage(
	     "right-hand side of matching condition introduces variables",
	     ASF_ASFConditionToTerm(condition)));
  }

  newVars = checkVariables((PT_Tree) lhsCond, pDefVars, pUsedVars);
  if (PT_isArgsEmpty(newVars)) {
    return ERR_makeErrorListSingle(
	 makeMessage("matching condition does not introduce new variables",
		     ASF_ASFConditionToTerm(condition)));
  }
  else {
    /* variables already collected */
    messages = ERR_concatErrorList(messages, 
				   checkTree((PT_Tree) lhsCond, ATfalse));
  }

  return messages;
}

/*}}}  */
/*{{{  static ERR_ErrorList checkNoMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *pDefVars, PT_Args *pUsedVars)  */

static ERR_ErrorList checkNoMatchCondition(ASF_ASFTag tag, ASF_ASFCondition condition, ASF_Tree lhsCond, ASF_Tree rhsCond, PT_Args *pDefVars, PT_Args *pUsedVars) 
{
  PT_Args newVars;

  newVars = checkVariables((PT_Tree) lhsCond, pDefVars, pUsedVars);
  if (PT_isArgsEmpty(newVars)) {
    return ERR_makeErrorListSingle(
				 makeMessage(
					     "matching condition does not use new variables",
					     ASF_ASFConditionToTerm(condition)));
  }

  newVars = checkVariables((PT_Tree) rhsCond, pDefVars, pUsedVars);
  if (!PT_isArgsEmpty(newVars)) {
    return ERR_makeErrorListSingle(
			 makeMessage("right-hand side of matching condition introduces variables",
					 ASF_ASFConditionToTerm(condition)));
  }
  
  if (isConstant((PT_Tree) rhsCond)) {
    return ERR_makeErrorListSingle(
			 makeWarning("right-hand side of matching condition is constant",
					 ASF_TreeToTerm(rhsCond)));

  }

  return ERR_makeErrorListEmpty();
}

/*}}}  */

/*{{{  static ERR_ErrorList checkCondition(ASF_ASFTag tag, ASF_ASFCondition condition, PT_Args *pDefVars, PT_Args *pUsedVars)  */

static ERR_ErrorList checkCondition(ASF_ASFTag tag, ASF_ASFCondition condition, PT_Args *pDefVars, PT_Args *pUsedVars) 
{

  SCOUNT(nrConditions);
  currentLocation = PT_getTreeLocation((PT_Tree) condition);

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
      return checkNegativeCondition(tag, condition, lhsCond, rhsCond,
                                    pDefVars, pUsedVars);
    }
    else if (ASF_isASFConditionMatch(condition)) {
      SCOUNT(nrAssignmentConditions);
      return checkMatchCondition(tag, condition, lhsCond, rhsCond,
                                 pDefVars, pUsedVars);
    }
    else if (ASF_isASFConditionNoMatch(condition)) {
      SCOUNT(nrNonAssignmentConditions);
      return checkNoMatchCondition(tag, condition, lhsCond, rhsCond,
                                   pDefVars, pUsedVars);
    }
    else if (ASF_isASFConditionEquality(condition)) {
      SCOUNT(nrEqualityConditions);
      return checkEqualityCondition(tag, condition, lhsCond, rhsCond,
                                    pDefVars, pUsedVars);
    }
    else {
      return ERR_makeErrorListSingle(makeMessage("strange condition encountered", 
						 ASF_ASFConditionToTerm(condition)));
    }
  }
}

/*}}}  */

/*{{{  static ERR_ErrorList checkConditions(ASF_ASFTag tag, ASF_ASFConditions conditions, PT_Args *pDefVars, PT_Args *pUsedVars)  */

static ERR_ErrorList checkConditions(ASF_ASFTag tag, ASF_ASFConditions conditions, PT_Args *pDefVars, PT_Args *pUsedVars) 
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
					checkCondition(tag, condition,
                                                       pDefVars, pUsedVars));

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

  currentLocation = PT_getTreeLocation((PT_Tree) asfTree);

  if (PT_isTreeAmb(ptTree)) {
    return makeAmbiguityMessage(ptTree);
  }
  else {
    SADD(outermostFunctions, PT_getTreeProd(ptTree));

    if (PT_hasProductionConstructorAttr(PT_getTreeProd(ptTree))) {
      ERR_Error message = makeWarning("unexpected constructor as "
				      "outermost function symbol "
				      "of left-hand side", 
				      PT_TreeToTerm(ptTree));
      return ERR_makeErrorListSingle(message);
    }
    else if (isContextFreeSingleton(ptTree)) {
      ERR_Error message = 
          makeMessage(
          "rewrite rule will only match singleton lists "
	  "(the left-hand side is a function that does not return a list, "
	  "but the right-hand side is a list.)", PT_TreeToTerm(ptTree));
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

  currentLocation = PT_getTreeLocation((PT_Tree) condEquation);

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

      PT_Args definedVars = PT_makeArgsEmpty(); /* defined but not used */
      PT_Args usedVars    = PT_makeArgsEmpty(); /* defined and used */

      /* collect variables of lhs */
      checkVariables((PT_Tree)lhsEq, &definedVars, &usedVars);

      messages = ERR_concatErrorList(messages, checkLhs(tag, lhsEq));

      messages = ERR_concatErrorList(messages, 
				     checkTree((PT_Tree)lhsEq, ATfalse));

      if (ASF_hasASFConditionalEquationASFConditions(condEquation)) {
	SCOUNT(nrEquationsWithConditions);
	messages = ERR_concatErrorList(messages,
			  checkConditions(tag,
					  ASF_getASFConditionalEquationASFConditions(condEquation),
					  &definedVars, &usedVars));
      }

      currentLocation = PT_getTreeLocation((PT_Tree) rhsEq);

      messages =  ERR_concatErrorList(messages,
		          checkTreeGivenVariables(tag, (PT_Tree)rhsEq, 
					&definedVars, &usedVars));
      messages = ERR_concatErrorList(messages, 
			  checkTree((PT_Tree) rhsEq, ATfalse));

      /* for variables defined and not used, report an error */
      messages = ERR_concatErrorList(messages,
				     reportUnusedVariables(tag,definedVars));
      /* for used dummy variables, report an error */
      messages = ERR_concatErrorList(messages,
				     reportUsedWildVariables(tag,usedVars));
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

  currentLocation = PT_getTreeLocation((PT_Tree) testEquation);

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
      PT_Args definedVars=PT_makeArgsEmpty();
      PT_Args usedVars=PT_makeArgsEmpty();
      
      checkVariables((PT_Tree)lhsCond, &definedVars, &usedVars);

      if (!PT_isArgsEmpty(definedVars) || !PT_isArgsEmpty(usedVars)) {
	message = makeMessage("no variables may be introduced in "
			      "left-hand side of test", 
			      ASF_TreeToTerm(lhsCond));
	messages = ERR_makeErrorListMany(message, messages);
        definedVars=PT_makeArgsEmpty();
        usedVars=PT_makeArgsEmpty();
      }

      if (ASF_hasASFTestEquationASFConditions(testEquation)) {
	messages = ERR_concatErrorList(messages,
			  checkConditions(tag,
					  ASF_getASFTestEquationASFConditions(testEquation),
					  &definedVars, &usedVars));
      }

      messages =  ERR_concatErrorList(messages,
		          checkTreeGivenVariables(tag, (PT_Tree)rhsCond, 
						  &definedVars, &usedVars));
      messages = ERR_concatErrorList(messages, 
				     checkTree((PT_Tree)rhsCond, ATfalse));

      /* for variables defined and not used, report an error */
      messages = ERR_concatErrorList(messages,
				     reportUnusedVariables(tag,definedVars));
      /* for used dummy variables, report an error */
      messages = ERR_concatErrorList(messages,
				     reportUsedWildVariables(tag,usedVars));
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
  ERR_protectLocation(&currentLocation);

  if (PT_isTreeAmb(PT_TreeFromTerm((ATerm) equations))) {
    return makeAmbiguityMessage(equations);
  }

  return checkASFConditionalEquationList(equations);
}

/*}}}  */
/*{{{  ERR_ErrorList checkTests(ASF_ASFTestEquationTestList tests)  */

ERR_ErrorList checkTests(ASF_ASFTestEquationTestList tests) 
{
  ERR_protectLocation(&currentLocation);

  if (PT_isTreeAmb(PT_TreeFromTerm((ATerm) tests))) {
    return makeAmbiguityMessage(tests);
  }

  return checkASFTestEquationList(tests);
}

/*}}}  */
