#include <aterm2.h>
#include <deprecated.h>
#include "ASF.h"

/*{{{  typedefs */

typedef struct ATerm _ASF_Production;
typedef struct ATerm _ASF_Implies;
typedef struct ATerm _ASF_TagId;
typedef struct ATerm _ASF_Conditions;
typedef struct ATerm _ASF_ConditionList;
typedef struct ATerm _ASF_Equations;
typedef struct ATerm _ASF_CondEquationList;
typedef struct ATerm _ASF_CondEquation;
typedef struct ATerm _ASF_Tag;
typedef struct ATerm _ASF_Tree;
typedef struct ATerm _ASF_CHARList;
typedef struct ATerm _ASF_Equation;
typedef struct ATerm _ASF_Condition;
typedef struct ATerm _ASF_CHAR;

/*}}}  */

/*{{{  void ASF_initASFApi(void) */

void ASF_initASFApi(void)
{
  init_ASF_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  ASF_Production ASF_makeProductionFromTerm(ATerm t) */

ASF_Production ASF_makeProductionFromTerm(ATerm t)
{
  return (ASF_Production)t;
}

/*}}}  */
/*{{{  ATerm ASF_makeTermFromProduction(ASF_Production arg) */

ATerm ASF_makeTermFromProduction(ASF_Production arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Implies ASF_makeImpliesFromTerm(ATerm t) */

ASF_Implies ASF_makeImpliesFromTerm(ATerm t)
{
  return (ASF_Implies)t;
}

/*}}}  */
/*{{{  ATerm ASF_makeTermFromImplies(ASF_Implies arg) */

ATerm ASF_makeTermFromImplies(ASF_Implies arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_TagId ASF_makeTagIdFromTerm(ATerm t) */

ASF_TagId ASF_makeTagIdFromTerm(ATerm t)
{
  return (ASF_TagId)t;
}

/*}}}  */
/*{{{  ATerm ASF_makeTermFromTagId(ASF_TagId arg) */

ATerm ASF_makeTermFromTagId(ASF_TagId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Conditions ASF_makeConditionsFromTerm(ATerm t) */

ASF_Conditions ASF_makeConditionsFromTerm(ATerm t)
{
  return (ASF_Conditions)t;
}

/*}}}  */
/*{{{  ATerm ASF_makeTermFromConditions(ASF_Conditions arg) */

ATerm ASF_makeTermFromConditions(ASF_Conditions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_makeConditionListFromTerm(ATerm t) */

ASF_ConditionList ASF_makeConditionListFromTerm(ATerm t)
{
  return (ASF_ConditionList)t;
}

/*}}}  */
/*{{{  ATerm ASF_makeTermFromConditionList(ASF_ConditionList arg) */

ATerm ASF_makeTermFromConditionList(ASF_ConditionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Equations ASF_makeEquationsFromTerm(ATerm t) */

ASF_Equations ASF_makeEquationsFromTerm(ATerm t)
{
  return (ASF_Equations)t;
}

/*}}}  */
/*{{{  ATerm ASF_makeTermFromEquations(ASF_Equations arg) */

ATerm ASF_makeTermFromEquations(ASF_Equations arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_makeCondEquationListFromTerm(ATerm t) */

ASF_CondEquationList ASF_makeCondEquationListFromTerm(ATerm t)
{
  return (ASF_CondEquationList)t;
}

/*}}}  */
/*{{{  ATerm ASF_makeTermFromCondEquationList(ASF_CondEquationList arg) */

ATerm ASF_makeTermFromCondEquationList(ASF_CondEquationList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_makeCondEquationFromTerm(ATerm t) */

ASF_CondEquation ASF_makeCondEquationFromTerm(ATerm t)
{
  return (ASF_CondEquation)t;
}

/*}}}  */
/*{{{  ATerm ASF_makeTermFromCondEquation(ASF_CondEquation arg) */

ATerm ASF_makeTermFromCondEquation(ASF_CondEquation arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Tag ASF_makeTagFromTerm(ATerm t) */

ASF_Tag ASF_makeTagFromTerm(ATerm t)
{
  return (ASF_Tag)t;
}

/*}}}  */
/*{{{  ATerm ASF_makeTermFromTag(ASF_Tag arg) */

ATerm ASF_makeTermFromTag(ASF_Tag arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Tree ASF_makeTreeFromTerm(ATerm t) */

ASF_Tree ASF_makeTreeFromTerm(ATerm t)
{
  return (ASF_Tree)t;
}

/*}}}  */
/*{{{  ATerm ASF_makeTermFromTree(ASF_Tree arg) */

ATerm ASF_makeTermFromTree(ASF_Tree arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_makeCHARListFromTerm(ATerm t) */

ASF_CHARList ASF_makeCHARListFromTerm(ATerm t)
{
  return (ASF_CHARList)t;
}

/*}}}  */
/*{{{  ATerm ASF_makeTermFromCHARList(ASF_CHARList arg) */

ATerm ASF_makeTermFromCHARList(ASF_CHARList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Equation ASF_makeEquationFromTerm(ATerm t) */

ASF_Equation ASF_makeEquationFromTerm(ATerm t)
{
  return (ASF_Equation)t;
}

/*}}}  */
/*{{{  ATerm ASF_makeTermFromEquation(ASF_Equation arg) */

ATerm ASF_makeTermFromEquation(ASF_Equation arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Condition ASF_makeConditionFromTerm(ATerm t) */

ASF_Condition ASF_makeConditionFromTerm(ATerm t)
{
  return (ASF_Condition)t;
}

/*}}}  */
/*{{{  ATerm ASF_makeTermFromCondition(ASF_Condition arg) */

ATerm ASF_makeTermFromCondition(ASF_Condition arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_CHAR ASF_makeCHARFromTerm(ATerm t) */

ASF_CHAR ASF_makeCHARFromTerm(ATerm t)
{
  return (ASF_CHAR)t;
}

/*}}}  */
/*{{{  ATerm ASF_makeTermFromCHAR(ASF_CHAR arg) */

ATerm ASF_makeTermFromCHAR(ASF_CHAR arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  ASF_Production ASF_makeProductionLexicalConstructor(char * formalName, ASF_Symbol symbol) */

ASF_Production ASF_makeProductionLexicalConstructor(char * formalName, ASF_Symbol symbol)
{
  return (ASF_Production)ATmakeTerm(ASF_patternProductionLexicalConstructor, formalName, symbol);
}

/*}}}  */
/*{{{  ASF_Implies ASF_makeImpliesDefault(char * lex) */

ASF_Implies ASF_makeImpliesDefault(char * lex)
{
  return (ASF_Implies)ATmakeTerm(ASF_patternImpliesDefault, lex);
}

/*}}}  */
/*{{{  ASF_TagId ASF_makeTagIdOneChar(char * lex) */

ASF_TagId ASF_makeTagIdOneChar(char * lex)
{
  return (ASF_TagId)ATmakeTerm(ASF_patternTagIdOneChar, lex);
}

/*}}}  */
/*{{{  ASF_TagId ASF_makeTagIdManyChars(char * lex) */

ASF_TagId ASF_makeTagIdManyChars(char * lex)
{
  return (ASF_TagId)ATmakeTerm(ASF_patternTagIdManyChars, lex);
}

/*}}}  */
/*{{{  ASF_Conditions ASF_makeConditionsDefault(ASF_ConditionList list) */

ASF_Conditions ASF_makeConditionsDefault(ASF_ConditionList list)
{
  return (ASF_Conditions)ATmakeTerm(ASF_patternConditionsDefault, list);
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_makeConditionListSingle(ASF_Condition head) */

ASF_ConditionList ASF_makeConditionListSingle(ASF_Condition head)
{
  return (ASF_ConditionList)ATmakeTerm(ASF_patternConditionListSingle, head);
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_makeConditionListMany(ASF_Condition head, char * wsAfterFirst, char * sep, char * wsAfterSep, ASF_ConditionList tail) */

ASF_ConditionList ASF_makeConditionListMany(ASF_Condition head, char * wsAfterFirst, char * sep, char * wsAfterSep, ASF_ConditionList tail)
{
  return (ASF_ConditionList)ATmakeTerm(ASF_patternConditionListMany, head, wsAfterFirst, sep, wsAfterSep, tail);
}

/*}}}  */
/*{{{  ASF_Equations ASF_makeEquationsAbsent() */

ASF_Equations ASF_makeEquationsAbsent()
{
  return (ASF_Equations)ATmakeTerm(ASF_patternEquationsAbsent);
}

/*}}}  */
/*{{{  ASF_Equations ASF_makeEquationsPresent(char * wsAfterEquations, ASF_CondEquationList list) */

ASF_Equations ASF_makeEquationsPresent(char * wsAfterEquations, ASF_CondEquationList list)
{
  return (ASF_Equations)ATmakeTerm(ASF_patternEquationsPresent, wsAfterEquations, list);
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_makeCondEquationListEmpty() */

ASF_CondEquationList ASF_makeCondEquationListEmpty()
{
  return (ASF_CondEquationList)ATmakeTerm(ASF_patternCondEquationListEmpty);
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_makeCondEquationListSingle(ASF_CondEquation head) */

ASF_CondEquationList ASF_makeCondEquationListSingle(ASF_CondEquation head)
{
  return (ASF_CondEquationList)ATmakeTerm(ASF_patternCondEquationListSingle, head);
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_makeCondEquationListMany(ASF_CondEquation head, char * wsAfterFirst, ASF_CondEquationList tail) */

ASF_CondEquationList ASF_makeCondEquationListMany(ASF_CondEquation head, char * wsAfterFirst, ASF_CondEquationList tail)
{
  return (ASF_CondEquationList)ATmakeTerm(ASF_patternCondEquationListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_makeCondEquationSimple(ASF_Tag Tag, char * wsAfterTag, ASF_Equation Equation) */

ASF_CondEquation ASF_makeCondEquationSimple(ASF_Tag Tag, char * wsAfterTag, ASF_Equation Equation)
{
  return (ASF_CondEquation)ATmakeTerm(ASF_patternCondEquationSimple, Tag, wsAfterTag, Equation);
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_makeCondEquationImplies(ASF_Tag Tag, char * wsAfterTag, ASF_Conditions Conditions, char * wsAfterConditions, ASF_Implies Implies, char * wsAfterImplies, ASF_Equation Equation) */

ASF_CondEquation ASF_makeCondEquationImplies(ASF_Tag Tag, char * wsAfterTag, ASF_Conditions Conditions, char * wsAfterConditions, ASF_Implies Implies, char * wsAfterImplies, ASF_Equation Equation)
{
  return (ASF_CondEquation)ATmakeTerm(ASF_patternCondEquationImplies, Tag, wsAfterTag, Conditions, wsAfterConditions, Implies, wsAfterImplies, Equation);
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_makeCondEquationWhen(ASF_Tag Tag, char * wsAfterTag, ASF_Equation Equation, char * wsAfterEquation, char * wsAfterWhen, ASF_Conditions Conditions) */

ASF_CondEquation ASF_makeCondEquationWhen(ASF_Tag Tag, char * wsAfterTag, ASF_Equation Equation, char * wsAfterEquation, char * wsAfterWhen, ASF_Conditions Conditions)
{
  return (ASF_CondEquation)ATmakeTerm(ASF_patternCondEquationWhen, Tag, wsAfterTag, Equation, wsAfterEquation, wsAfterWhen, Conditions);
}

/*}}}  */
/*{{{  ASF_Tag ASF_makeTagEmpty(char * wsAfterBracketOpen) */

ASF_Tag ASF_makeTagEmpty(char * wsAfterBracketOpen)
{
  return (ASF_Tag)ATmakeTerm(ASF_patternTagEmpty, wsAfterBracketOpen);
}

/*}}}  */
/*{{{  ASF_Tag ASF_makeTagNotEmpty(char * wsAfterBracketOpen, ASF_TagId TagId, char * wsAfterTagId) */

ASF_Tag ASF_makeTagNotEmpty(char * wsAfterBracketOpen, ASF_TagId TagId, char * wsAfterTagId)
{
  return (ASF_Tag)ATmakeTerm(ASF_patternTagNotEmpty, wsAfterBracketOpen, TagId, wsAfterTagId);
}

/*}}}  */
/*{{{  ASF_Tree ASF_makeTreeLexicalConstructor(char * formalName, ASF_Symbol symbol, ASF_Tree name, char * wsAfterName, char * wsAfterParenOpen, ASF_CHARList list, char * wsAfterList) */

ASF_Tree ASF_makeTreeLexicalConstructor(char * formalName, ASF_Symbol symbol, ASF_Tree name, char * wsAfterName, char * wsAfterParenOpen, ASF_CHARList list, char * wsAfterList)
{
  return (ASF_Tree)ATmakeTerm(ASF_patternTreeLexicalConstructor, formalName, symbol, name, wsAfterName, wsAfterParenOpen, list, wsAfterList);
}

/*}}}  */
/*{{{  ASF_CHARList ASF_makeCHARListEmpty() */

ASF_CHARList ASF_makeCHARListEmpty()
{
  return (ASF_CHARList)ATmakeTerm(ASF_patternCHARListEmpty);
}

/*}}}  */
/*{{{  ASF_CHARList ASF_makeCHARListSingle(ASF_CHAR head) */

ASF_CHARList ASF_makeCHARListSingle(ASF_CHAR head)
{
  return (ASF_CHARList)ATmakeTerm(ASF_patternCHARListSingle, head);
}

/*}}}  */
/*{{{  ASF_CHARList ASF_makeCHARListMany(ASF_CHAR head, char * wsAfterFirst, ASF_CHARList tail) */

ASF_CHARList ASF_makeCHARListMany(ASF_CHAR head, char * wsAfterFirst, ASF_CHARList tail)
{
  return (ASF_CHARList)ATmakeTerm(ASF_patternCHARListMany, head, wsAfterFirst, tail);
}

/*}}}  */
/*{{{  ASF_Equation ASF_makeEquationDefault(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, char * wsAfterLhs, char * wsAfterEquals, ASF_Tree rhs) */

ASF_Equation ASF_makeEquationDefault(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, char * wsAfterLhs, char * wsAfterEquals, ASF_Tree rhs)
{
  return (ASF_Equation)ATmakeTerm(ASF_patternEquationDefault, lhsSymbol, rhsSymbol, lhs, wsAfterLhs, wsAfterEquals, rhs);
}

/*}}}  */
/*{{{  ASF_Condition ASF_makeConditionPositive(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, char * wsAfterLhs, char * wsAfterEquals, ASF_Tree rhs) */

ASF_Condition ASF_makeConditionPositive(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, char * wsAfterLhs, char * wsAfterEquals, ASF_Tree rhs)
{
  return (ASF_Condition)ATmakeTerm(ASF_patternConditionPositive, lhsSymbol, rhsSymbol, lhs, wsAfterLhs, wsAfterEquals, rhs);
}

/*}}}  */
/*{{{  ASF_Condition ASF_makeConditionNegative(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, char * wsAfterLhs, char * wsAfterUnequal, ASF_Tree rhs) */

ASF_Condition ASF_makeConditionNegative(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, char * wsAfterLhs, char * wsAfterUnequal, ASF_Tree rhs)
{
  return (ASF_Condition)ATmakeTerm(ASF_patternConditionNegative, lhsSymbol, rhsSymbol, lhs, wsAfterLhs, wsAfterUnequal, rhs);
}

/*}}}  */
/*{{{  ASF_CHAR ASF_makeCHARDefault(char * lex) */

ASF_CHAR ASF_makeCHARDefault(char * lex)
{
  return (ASF_CHAR)ATmakeTerm(ASF_patternCHARDefault, lex);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool ASF_isEqualProduction(ASF_Production arg0, ASF_Production arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualImplies(ASF_Implies arg0, ASF_Implies arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualTagId(ASF_TagId arg0, ASF_TagId arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualConditions(ASF_Conditions arg0, ASF_Conditions arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualConditionList(ASF_ConditionList arg0, ASF_ConditionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualEquations(ASF_Equations arg0, ASF_Equations arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualCondEquationList(ASF_CondEquationList arg0, ASF_CondEquationList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualCondEquation(ASF_CondEquation arg0, ASF_CondEquation arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualTag(ASF_Tag arg0, ASF_Tag arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualTree(ASF_Tree arg0, ASF_Tree arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualCHARList(ASF_CHARList arg0, ASF_CHARList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualEquation(ASF_Equation arg0, ASF_Equation arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualCondition(ASF_Condition arg0, ASF_Condition arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualCHAR(ASF_CHAR arg0, ASF_CHAR arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  ASF_Production accessors */

/*{{{  ATbool ASF_isValidProduction(ASF_Production arg) */

ATbool ASF_isValidProduction(ASF_Production arg)
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_isProductionLexicalConstructor(ASF_Production arg) */

ATbool ASF_isProductionLexicalConstructor(ASF_Production arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternProductionLexicalConstructor, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_hasProductionFormalName(ASF_Production arg) */

ATbool ASF_hasProductionFormalName(ASF_Production arg)
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getProductionFormalName(ASF_Production arg) */

char * ASF_getProductionFormalName(ASF_Production arg)
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 0)));
  }

  ATabort("Production has no FormalName: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_Production ASF_setProductionFormalName(ASF_Production arg, char * formalName) */

ASF_Production ASF_setProductionFormalName(ASF_Production arg, char * formalName)
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return (ASF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)ATmakeAppl0(ATmakeAFun(formalName, 0, ATtrue)), 0), 0), 2);
  }

  ATabort("Production has no FormalName: %t\n", arg);
  return (ASF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasProductionSymbol(ASF_Production arg) */

ATbool ASF_hasProductionSymbol(ASF_Production arg)
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getProductionSymbol(ASF_Production arg) */

ASF_Symbol ASF_getProductionSymbol(ASF_Production arg)
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return (ASF_Symbol)ATgetArgument((ATermAppl)arg, 6);
  }

  ATabort("Production has no Symbol: %t\n", arg);
  return (ASF_Symbol)NULL;
}

/*}}}  */
/*{{{  ASF_Production ASF_setProductionSymbol(ASF_Production arg, ASF_Symbol symbol) */

ASF_Production ASF_setProductionSymbol(ASF_Production arg, ASF_Symbol symbol)
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return (ASF_Production)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 6);
  }

  ATabort("Production has no Symbol: %t\n", arg);
  return (ASF_Production)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Implies accessors */

/*{{{  ATbool ASF_isValidImplies(ASF_Implies arg) */

ATbool ASF_isValidImplies(ASF_Implies arg)
{
  if (ASF_isImpliesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_isImpliesDefault(ASF_Implies arg) */

ATbool ASF_isImpliesDefault(ASF_Implies arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternImpliesDefault, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_hasImpliesLex(ASF_Implies arg) */

ATbool ASF_hasImpliesLex(ASF_Implies arg)
{
  if (ASF_isImpliesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getImpliesLex(ASF_Implies arg) */

char * ASF_getImpliesLex(ASF_Implies arg)
{
  if (ASF_isImpliesDefault(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("Implies has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_Implies ASF_setImpliesLex(ASF_Implies arg, char * lex) */

ASF_Implies ASF_setImpliesLex(ASF_Implies arg, char * lex)
{
  if (ASF_isImpliesDefault(arg)) {
    return (ASF_Implies)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("Implies has no Lex: %t\n", arg);
  return (ASF_Implies)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_TagId accessors */

/*{{{  ATbool ASF_isValidTagId(ASF_TagId arg) */

ATbool ASF_isValidTagId(ASF_TagId arg)
{
  if (ASF_isTagIdOneChar(arg)) {
    return ATtrue;
  }
  else if (ASF_isTagIdManyChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_isTagIdOneChar(ASF_TagId arg) */

ATbool ASF_isTagIdOneChar(ASF_TagId arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternTagIdOneChar, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_isTagIdManyChars(ASF_TagId arg) */

ATbool ASF_isTagIdManyChars(ASF_TagId arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternTagIdManyChars, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_hasTagIdLex(ASF_TagId arg) */

ATbool ASF_hasTagIdLex(ASF_TagId arg)
{
  if (ASF_isTagIdOneChar(arg)) {
    return ATtrue;
  }
  else if (ASF_isTagIdManyChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getTagIdLex(ASF_TagId arg) */

char * ASF_getTagIdLex(ASF_TagId arg)
{
  if (ASF_isTagIdOneChar(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (ASF_isTagIdManyChars(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("TagId has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_TagId ASF_setTagIdLex(ASF_TagId arg, char * lex) */

ASF_TagId ASF_setTagIdLex(ASF_TagId arg, char * lex)
{
  if (ASF_isTagIdOneChar(arg)) {
    return (ASF_TagId)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }
  else if (ASF_isTagIdManyChars(arg)) {
    return (ASF_TagId)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("TagId has no Lex: %t\n", arg);
  return (ASF_TagId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Conditions accessors */

/*{{{  ATbool ASF_isValidConditions(ASF_Conditions arg) */

ATbool ASF_isValidConditions(ASF_Conditions arg)
{
  if (ASF_isConditionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_isConditionsDefault(ASF_Conditions arg) */

ATbool ASF_isConditionsDefault(ASF_Conditions arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternConditionsDefault, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionsList(ASF_Conditions arg) */

ATbool ASF_hasConditionsList(ASF_Conditions arg)
{
  if (ASF_isConditionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_getConditionsList(ASF_Conditions arg) */

ASF_ConditionList ASF_getConditionsList(ASF_Conditions arg)
{
  if (ASF_isConditionsDefault(arg)) {
    return (ASF_ConditionList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), 2);
  }

  ATabort("Conditions has no List: %t\n", arg);
  return (ASF_ConditionList)NULL;
}

/*}}}  */
/*{{{  ASF_Conditions ASF_setConditionsList(ASF_Conditions arg, ASF_ConditionList list) */

ASF_Conditions ASF_setConditionsList(ASF_Conditions arg, ASF_ConditionList list)
{
  if (ASF_isConditionsDefault(arg)) {
    return (ASF_Conditions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0), (ATerm)list, 2), 0), 2);
  }

  ATabort("Conditions has no List: %t\n", arg);
  return (ASF_Conditions)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ConditionList accessors */

/*{{{  ATbool ASF_isValidConditionList(ASF_ConditionList arg) */

ATbool ASF_isValidConditionList(ASF_ConditionList arg)
{
  if (ASF_isConditionListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_isConditionListSingle(ASF_ConditionList arg) */

ATbool ASF_isConditionListSingle(ASF_ConditionList arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternConditionListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_isConditionListMany(ASF_ConditionList arg) */

ATbool ASF_isConditionListMany(ASF_ConditionList arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternConditionListMany, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionListHead(ASF_ConditionList arg) */

ATbool ASF_hasConditionListHead(ASF_ConditionList arg)
{
  if (ASF_isConditionListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Condition ASF_getConditionListHead(ASF_ConditionList arg) */

ASF_Condition ASF_getConditionListHead(ASF_ConditionList arg)
{
  if (ASF_isConditionListSingle(arg)) {
    return (ASF_Condition)ATelementAt((ATermList)arg, 0);
  }
  else if (ASF_isConditionListMany(arg)) {
    return (ASF_Condition)ATelementAt((ATermList)arg, 0);
  }

  ATabort("ConditionList has no Head: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_setConditionListHead(ASF_ConditionList arg, ASF_Condition head) */

ASF_ConditionList ASF_setConditionListHead(ASF_ConditionList arg, ASF_Condition head)
{
  if (ASF_isConditionListSingle(arg)) {
    return (ASF_ConditionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (ASF_isConditionListMany(arg)) {
    return (ASF_ConditionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ConditionList has no Head: %t\n", arg);
  return (ASF_ConditionList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionListWsAfterFirst(ASF_ConditionList arg) */

ATbool ASF_hasConditionListWsAfterFirst(ASF_ConditionList arg)
{
  if (ASF_isConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getConditionListWsAfterFirst(ASF_ConditionList arg) */

char * ASF_getConditionListWsAfterFirst(ASF_ConditionList arg)
{
  if (ASF_isConditionListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("ConditionList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_setConditionListWsAfterFirst(ASF_ConditionList arg, char * wsAfterFirst) */

ASF_ConditionList ASF_setConditionListWsAfterFirst(ASF_ConditionList arg, char * wsAfterFirst)
{
  if (ASF_isConditionListMany(arg)) {
    return (ASF_ConditionList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("ConditionList has no WsAfterFirst: %t\n", arg);
  return (ASF_ConditionList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionListSep(ASF_ConditionList arg) */

ATbool ASF_hasConditionListSep(ASF_ConditionList arg)
{
  if (ASF_isConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getConditionListSep(ASF_ConditionList arg) */

char * ASF_getConditionListSep(ASF_ConditionList arg)
{
  if (ASF_isConditionListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
  }

  ATabort("ConditionList has no Sep: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_setConditionListSep(ASF_ConditionList arg, char * sep) */

ASF_ConditionList ASF_setConditionListSep(ASF_ConditionList arg, char * sep)
{
  if (ASF_isConditionListMany(arg)) {
    return (ASF_ConditionList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("ConditionList has no Sep: %t\n", arg);
  return (ASF_ConditionList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionListWsAfterSep(ASF_ConditionList arg) */

ATbool ASF_hasConditionListWsAfterSep(ASF_ConditionList arg)
{
  if (ASF_isConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getConditionListWsAfterSep(ASF_ConditionList arg) */

char * ASF_getConditionListWsAfterSep(ASF_ConditionList arg)
{
  if (ASF_isConditionListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), 0)));
  }

  ATabort("ConditionList has no WsAfterSep: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_setConditionListWsAfterSep(ASF_ConditionList arg, char * wsAfterSep) */

ASF_ConditionList ASF_setConditionListWsAfterSep(ASF_ConditionList arg, char * wsAfterSep)
{
  if (ASF_isConditionListMany(arg)) {
    return (ASF_ConditionList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterSep, 0, ATtrue)), 0), 3);
  }

  ATabort("ConditionList has no WsAfterSep: %t\n", arg);
  return (ASF_ConditionList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionListTail(ASF_ConditionList arg) */

ATbool ASF_hasConditionListTail(ASF_ConditionList arg)
{
  if (ASF_isConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_getConditionListTail(ASF_ConditionList arg) */

ASF_ConditionList ASF_getConditionListTail(ASF_ConditionList arg)
{
  if (ASF_isConditionListMany(arg)) {
    return (ASF_ConditionList)ATgetTail((ATermList)arg, 4);
  }

  ATabort("ConditionList has no Tail: %t\n", arg);
  return (ASF_ConditionList)NULL;
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_setConditionListTail(ASF_ConditionList arg, ASF_ConditionList tail) */

ASF_ConditionList ASF_setConditionListTail(ASF_ConditionList arg, ASF_ConditionList tail)
{
  if (ASF_isConditionListMany(arg)) {
    return (ASF_ConditionList)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("ConditionList has no Tail: %t\n", arg);
  return (ASF_ConditionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Equations accessors */

/*{{{  ATbool ASF_isValidEquations(ASF_Equations arg) */

ATbool ASF_isValidEquations(ASF_Equations arg)
{
  if (ASF_isEquationsAbsent(arg)) {
    return ATtrue;
  }
  else if (ASF_isEquationsPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_isEquationsAbsent(ASF_Equations arg) */

ATbool ASF_isEquationsAbsent(ASF_Equations arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternEquationsAbsent);
}

/*}}}  */
/*{{{  ATbool ASF_isEquationsPresent(ASF_Equations arg) */

ATbool ASF_isEquationsPresent(ASF_Equations arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternEquationsPresent, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationsWsAfterEquations(ASF_Equations arg) */

ATbool ASF_hasEquationsWsAfterEquations(ASF_Equations arg)
{
  if (ASF_isEquationsPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getEquationsWsAfterEquations(ASF_Equations arg) */

char * ASF_getEquationsWsAfterEquations(ASF_Equations arg)
{
  if (ASF_isEquationsPresent(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Equations has no WsAfterEquations: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_Equations ASF_setEquationsWsAfterEquations(ASF_Equations arg, char * wsAfterEquations) */

ASF_Equations ASF_setEquationsWsAfterEquations(ASF_Equations arg, char * wsAfterEquations)
{
  if (ASF_isEquationsPresent(arg)) {
    return (ASF_Equations)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterEquations, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Equations has no WsAfterEquations: %t\n", arg);
  return (ASF_Equations)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationsList(ASF_Equations arg) */

ATbool ASF_hasEquationsList(ASF_Equations arg)
{
  if (ASF_isEquationsPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_getEquationsList(ASF_Equations arg) */

ASF_CondEquationList ASF_getEquationsList(ASF_Equations arg)
{
  if (ASF_isEquationsPresent(arg)) {
    return (ASF_CondEquationList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), 2);
  }

  ATabort("Equations has no List: %t\n", arg);
  return (ASF_CondEquationList)NULL;
}

/*}}}  */
/*{{{  ASF_Equations ASF_setEquationsList(ASF_Equations arg, ASF_CondEquationList list) */

ASF_Equations ASF_setEquationsList(ASF_Equations arg, ASF_CondEquationList list)
{
  if (ASF_isEquationsPresent(arg)) {
    return (ASF_Equations)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2), (ATerm)list, 2), 2), 2);
  }

  ATabort("Equations has no List: %t\n", arg);
  return (ASF_Equations)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_CondEquationList accessors */

/*{{{  ATbool ASF_isValidCondEquationList(ASF_CondEquationList arg) */

ATbool ASF_isValidCondEquationList(ASF_CondEquationList arg)
{
  if (ASF_isCondEquationListEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_isCondEquationListEmpty(ASF_CondEquationList arg) */

ATbool ASF_isCondEquationListEmpty(ASF_CondEquationList arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternCondEquationListEmpty);
}

/*}}}  */
/*{{{  ATbool ASF_isCondEquationListSingle(ASF_CondEquationList arg) */

ATbool ASF_isCondEquationListSingle(ASF_CondEquationList arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternCondEquationListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_isCondEquationListMany(ASF_CondEquationList arg) */

ATbool ASF_isCondEquationListMany(ASF_CondEquationList arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternCondEquationListMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationListHead(ASF_CondEquationList arg) */

ATbool ASF_hasCondEquationListHead(ASF_CondEquationList arg)
{
  if (ASF_isCondEquationListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_getCondEquationListHead(ASF_CondEquationList arg) */

ASF_CondEquation ASF_getCondEquationListHead(ASF_CondEquationList arg)
{
  if (ASF_isCondEquationListSingle(arg)) {
    return (ASF_CondEquation)ATelementAt((ATermList)arg, 0);
  }
  else if (ASF_isCondEquationListMany(arg)) {
    return (ASF_CondEquation)ATelementAt((ATermList)arg, 0);
  }

  ATabort("CondEquationList has no Head: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_setCondEquationListHead(ASF_CondEquationList arg, ASF_CondEquation head) */

ASF_CondEquationList ASF_setCondEquationListHead(ASF_CondEquationList arg, ASF_CondEquation head)
{
  if (ASF_isCondEquationListSingle(arg)) {
    return (ASF_CondEquationList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (ASF_isCondEquationListMany(arg)) {
    return (ASF_CondEquationList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("CondEquationList has no Head: %t\n", arg);
  return (ASF_CondEquationList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationListWsAfterFirst(ASF_CondEquationList arg) */

ATbool ASF_hasCondEquationListWsAfterFirst(ASF_CondEquationList arg)
{
  if (ASF_isCondEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getCondEquationListWsAfterFirst(ASF_CondEquationList arg) */

char * ASF_getCondEquationListWsAfterFirst(ASF_CondEquationList arg)
{
  if (ASF_isCondEquationListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("CondEquationList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_setCondEquationListWsAfterFirst(ASF_CondEquationList arg, char * wsAfterFirst) */

ASF_CondEquationList ASF_setCondEquationListWsAfterFirst(ASF_CondEquationList arg, char * wsAfterFirst)
{
  if (ASF_isCondEquationListMany(arg)) {
    return (ASF_CondEquationList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("CondEquationList has no WsAfterFirst: %t\n", arg);
  return (ASF_CondEquationList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationListTail(ASF_CondEquationList arg) */

ATbool ASF_hasCondEquationListTail(ASF_CondEquationList arg)
{
  if (ASF_isCondEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_getCondEquationListTail(ASF_CondEquationList arg) */

ASF_CondEquationList ASF_getCondEquationListTail(ASF_CondEquationList arg)
{
  if (ASF_isCondEquationListMany(arg)) {
    return (ASF_CondEquationList)ATgetTail((ATermList)arg, 2);
  }

  ATabort("CondEquationList has no Tail: %t\n", arg);
  return (ASF_CondEquationList)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_setCondEquationListTail(ASF_CondEquationList arg, ASF_CondEquationList tail) */

ASF_CondEquationList ASF_setCondEquationListTail(ASF_CondEquationList arg, ASF_CondEquationList tail)
{
  if (ASF_isCondEquationListMany(arg)) {
    return (ASF_CondEquationList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("CondEquationList has no Tail: %t\n", arg);
  return (ASF_CondEquationList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_CondEquation accessors */

/*{{{  ATbool ASF_isValidCondEquation(ASF_CondEquation arg) */

ATbool ASF_isValidCondEquation(ASF_CondEquation arg)
{
  if (ASF_isCondEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_isCondEquationSimple(ASF_CondEquation arg) */

ATbool ASF_isCondEquationSimple(ASF_CondEquation arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternCondEquationSimple, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_isCondEquationImplies(ASF_CondEquation arg) */

ATbool ASF_isCondEquationImplies(ASF_CondEquation arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternCondEquationImplies, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_isCondEquationWhen(ASF_CondEquation arg) */

ATbool ASF_isCondEquationWhen(ASF_CondEquation arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternCondEquationWhen, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationTag(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationTag(ASF_CondEquation arg)
{
  if (ASF_isCondEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tag ASF_getCondEquationTag(ASF_CondEquation arg) */

ASF_Tag ASF_getCondEquationTag(ASF_CondEquation arg)
{
  if (ASF_isCondEquationSimple(arg)) {
    return (ASF_Tag)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return (ASF_Tag)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return (ASF_Tag)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("CondEquation has no Tag: %t\n", arg);
  return (ASF_Tag)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationTag(ASF_CondEquation arg, ASF_Tag Tag) */

ASF_CondEquation ASF_setCondEquationTag(ASF_CondEquation arg, ASF_Tag Tag)
{
  if (ASF_isCondEquationSimple(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Tag, 0), 2);
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Tag, 0), 2);
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Tag, 0), 2);
  }

  ATabort("CondEquation has no Tag: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationWsAfterTag(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationWsAfterTag(ASF_CondEquation arg)
{
  if (ASF_isCondEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getCondEquationWsAfterTag(ASF_CondEquation arg) */

char * ASF_getCondEquationWsAfterTag(ASF_CondEquation arg)
{
  if (ASF_isCondEquationSimple(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("CondEquation has no WsAfterTag: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationWsAfterTag(ASF_CondEquation arg, char * wsAfterTag) */

ASF_CondEquation ASF_setCondEquationWsAfterTag(ASF_CondEquation arg, char * wsAfterTag)
{
  if (ASF_isCondEquationSimple(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterTag, 0, ATtrue)), 0), 1), 2);
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterTag, 0, ATtrue)), 0), 1), 2);
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterTag, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("CondEquation has no WsAfterTag: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationEquation(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationEquation(ASF_CondEquation arg)
{
  if (ASF_isCondEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Equation ASF_getCondEquationEquation(ASF_CondEquation arg) */

ASF_Equation ASF_getCondEquationEquation(ASF_CondEquation arg)
{
  if (ASF_isCondEquationSimple(arg)) {
    return (ASF_Equation)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return (ASF_Equation)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 6);
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return (ASF_Equation)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("CondEquation has no Equation: %t\n", arg);
  return (ASF_Equation)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationEquation(ASF_CondEquation arg, ASF_Equation Equation) */

ASF_CondEquation ASF_setCondEquationEquation(ASF_CondEquation arg, ASF_Equation Equation)
{
  if (ASF_isCondEquationSimple(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Equation, 2), 2);
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Equation, 6), 2);
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Equation, 2), 2);
  }

  ATabort("CondEquation has no Equation: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationConditions(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationConditions(ASF_CondEquation arg)
{
  if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Conditions ASF_getCondEquationConditions(ASF_CondEquation arg) */

ASF_Conditions ASF_getCondEquationConditions(ASF_CondEquation arg)
{
  if (ASF_isCondEquationImplies(arg)) {
    return (ASF_Conditions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return (ASF_Conditions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 6);
  }

  ATabort("CondEquation has no Conditions: %t\n", arg);
  return (ASF_Conditions)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationConditions(ASF_CondEquation arg, ASF_Conditions Conditions) */

ASF_CondEquation ASF_setCondEquationConditions(ASF_CondEquation arg, ASF_Conditions Conditions)
{
  if (ASF_isCondEquationImplies(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Conditions, 2), 2);
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Conditions, 6), 2);
  }

  ATabort("CondEquation has no Conditions: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationWsAfterConditions(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationWsAfterConditions(ASF_CondEquation arg)
{
  if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getCondEquationWsAfterConditions(ASF_CondEquation arg) */

char * ASF_getCondEquationWsAfterConditions(ASF_CondEquation arg)
{
  if (ASF_isCondEquationImplies(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("CondEquation has no WsAfterConditions: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationWsAfterConditions(ASF_CondEquation arg, char * wsAfterConditions) */

ASF_CondEquation ASF_setCondEquationWsAfterConditions(ASF_CondEquation arg, char * wsAfterConditions)
{
  if (ASF_isCondEquationImplies(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterConditions, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("CondEquation has no WsAfterConditions: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationImplies(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationImplies(ASF_CondEquation arg)
{
  if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Implies ASF_getCondEquationImplies(ASF_CondEquation arg) */

ASF_Implies ASF_getCondEquationImplies(ASF_CondEquation arg)
{
  if (ASF_isCondEquationImplies(arg)) {
    return (ASF_Implies)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("CondEquation has no Implies: %t\n", arg);
  return (ASF_Implies)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationImplies(ASF_CondEquation arg, ASF_Implies Implies) */

ASF_CondEquation ASF_setCondEquationImplies(ASF_CondEquation arg, ASF_Implies Implies)
{
  if (ASF_isCondEquationImplies(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)Implies, 4), 2);
  }

  ATabort("CondEquation has no Implies: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationWsAfterImplies(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationWsAfterImplies(ASF_CondEquation arg)
{
  if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getCondEquationWsAfterImplies(ASF_CondEquation arg) */

char * ASF_getCondEquationWsAfterImplies(ASF_CondEquation arg)
{
  if (ASF_isCondEquationImplies(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("CondEquation has no WsAfterImplies: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationWsAfterImplies(ASF_CondEquation arg, char * wsAfterImplies) */

ASF_CondEquation ASF_setCondEquationWsAfterImplies(ASF_CondEquation arg, char * wsAfterImplies)
{
  if (ASF_isCondEquationImplies(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterImplies, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("CondEquation has no WsAfterImplies: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationWsAfterEquation(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationWsAfterEquation(ASF_CondEquation arg)
{
  if (ASF_isCondEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getCondEquationWsAfterEquation(ASF_CondEquation arg) */

char * ASF_getCondEquationWsAfterEquation(ASF_CondEquation arg)
{
  if (ASF_isCondEquationWhen(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("CondEquation has no WsAfterEquation: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationWsAfterEquation(ASF_CondEquation arg, char * wsAfterEquation) */

ASF_CondEquation ASF_setCondEquationWsAfterEquation(ASF_CondEquation arg, char * wsAfterEquation)
{
  if (ASF_isCondEquationWhen(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterEquation, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("CondEquation has no WsAfterEquation: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationWsAfterWhen(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationWsAfterWhen(ASF_CondEquation arg)
{
  if (ASF_isCondEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getCondEquationWsAfterWhen(ASF_CondEquation arg) */

char * ASF_getCondEquationWsAfterWhen(ASF_CondEquation arg)
{
  if (ASF_isCondEquationWhen(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("CondEquation has no WsAfterWhen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationWsAfterWhen(ASF_CondEquation arg, char * wsAfterWhen) */

ASF_CondEquation ASF_setCondEquationWsAfterWhen(ASF_CondEquation arg, char * wsAfterWhen)
{
  if (ASF_isCondEquationWhen(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterWhen, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("CondEquation has no WsAfterWhen: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Tag accessors */

/*{{{  ATbool ASF_isValidTag(ASF_Tag arg) */

ATbool ASF_isValidTag(ASF_Tag arg)
{
  if (ASF_isTagEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_isTagEmpty(ASF_Tag arg) */

ATbool ASF_isTagEmpty(ASF_Tag arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternTagEmpty, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_isTagNotEmpty(ASF_Tag arg) */

ATbool ASF_isTagNotEmpty(ASF_Tag arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternTagNotEmpty, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_hasTagWsAfterBracketOpen(ASF_Tag arg) */

ATbool ASF_hasTagWsAfterBracketOpen(ASF_Tag arg)
{
  if (ASF_isTagEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getTagWsAfterBracketOpen(ASF_Tag arg) */

char * ASF_getTagWsAfterBracketOpen(ASF_Tag arg)
{
  if (ASF_isTagEmpty(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (ASF_isTagNotEmpty(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Tag has no WsAfterBracketOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_Tag ASF_setTagWsAfterBracketOpen(ASF_Tag arg, char * wsAfterBracketOpen) */

ASF_Tag ASF_setTagWsAfterBracketOpen(ASF_Tag arg, char * wsAfterBracketOpen)
{
  if (ASF_isTagEmpty(arg)) {
    return (ASF_Tag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBracketOpen, 0, ATtrue)), 0), 1), 2);
  }
  else if (ASF_isTagNotEmpty(arg)) {
    return (ASF_Tag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterBracketOpen, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Tag has no WsAfterBracketOpen: %t\n", arg);
  return (ASF_Tag)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTagTagId(ASF_Tag arg) */

ATbool ASF_hasTagTagId(ASF_Tag arg)
{
  if (ASF_isTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_TagId ASF_getTagTagId(ASF_Tag arg) */

ASF_TagId ASF_getTagTagId(ASF_Tag arg)
{
  if (ASF_isTagNotEmpty(arg)) {
    return (ASF_TagId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 2);
  }

  ATabort("Tag has no TagId: %t\n", arg);
  return (ASF_TagId)NULL;
}

/*}}}  */
/*{{{  ASF_Tag ASF_setTagTagId(ASF_Tag arg, ASF_TagId TagId) */

ASF_Tag ASF_setTagTagId(ASF_Tag arg, ASF_TagId TagId)
{
  if (ASF_isTagNotEmpty(arg)) {
    return (ASF_Tag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)TagId, 2), 2);
  }

  ATabort("Tag has no TagId: %t\n", arg);
  return (ASF_Tag)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTagWsAfterTagId(ASF_Tag arg) */

ATbool ASF_hasTagWsAfterTagId(ASF_Tag arg)
{
  if (ASF_isTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getTagWsAfterTagId(ASF_Tag arg) */

char * ASF_getTagWsAfterTagId(ASF_Tag arg)
{
  if (ASF_isTagNotEmpty(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Tag has no WsAfterTagId: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_Tag ASF_setTagWsAfterTagId(ASF_Tag arg, char * wsAfterTagId) */

ASF_Tag ASF_setTagWsAfterTagId(ASF_Tag arg, char * wsAfterTagId)
{
  if (ASF_isTagNotEmpty(arg)) {
    return (ASF_Tag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterTagId, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Tag has no WsAfterTagId: %t\n", arg);
  return (ASF_Tag)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Tree accessors */

/*{{{  ATbool ASF_isValidTree(ASF_Tree arg) */

ATbool ASF_isValidTree(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_isTreeLexicalConstructor(ASF_Tree arg) */

ATbool ASF_isTreeLexicalConstructor(ASF_Tree arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternTreeLexicalConstructor, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeFormalName(ASF_Tree arg) */

ATbool ASF_hasTreeFormalName(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getTreeFormalName(ASF_Tree arg) */

char * ASF_getTreeFormalName(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 2), 0), 0)));
  }

  ATabort("Tree has no FormalName: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeFormalName(ASF_Tree arg, char * formalName) */

ASF_Tree ASF_setTreeFormalName(ASF_Tree arg, char * formalName)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 2), 0), (ATerm)ATmakeAppl0(ATmakeAFun(formalName, 0, ATtrue)), 0), 0), 2), 0);
  }

  ATabort("Tree has no FormalName: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeSymbol(ASF_Tree arg) */

ATbool ASF_hasTreeSymbol(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getTreeSymbol(ASF_Tree arg) */

ASF_Symbol ASF_getTreeSymbol(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Symbol)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 6);
  }

  ATabort("Tree has no Symbol: %t\n", arg);
  return (ASF_Symbol)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeSymbol(ASF_Tree arg, ASF_Symbol symbol) */

ASF_Tree ASF_setTreeSymbol(ASF_Tree arg, ASF_Symbol symbol)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)symbol, 6), 0);
  }

  ATabort("Tree has no Symbol: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeName(ASF_Tree arg) */

ATbool ASF_hasTreeName(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tree ASF_getTreeName(ASF_Tree arg) */

ASF_Tree ASF_getTreeName(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Tree has no Name: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeName(ASF_Tree arg, ASF_Tree name) */

ASF_Tree ASF_setTreeName(ASF_Tree arg, ASF_Tree name)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)name, 0), 2);
  }

  ATabort("Tree has no Name: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeWsAfterName(ASF_Tree arg) */

ATbool ASF_hasTreeWsAfterName(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getTreeWsAfterName(ASF_Tree arg) */

char * ASF_getTreeWsAfterName(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Tree has no WsAfterName: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterName(ASF_Tree arg, char * wsAfterName) */

ASF_Tree ASF_setTreeWsAfterName(ASF_Tree arg, char * wsAfterName)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterName, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Tree has no WsAfterName: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeWsAfterParenOpen(ASF_Tree arg) */

ATbool ASF_hasTreeWsAfterParenOpen(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getTreeWsAfterParenOpen(ASF_Tree arg) */

char * ASF_getTreeWsAfterParenOpen(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Tree has no WsAfterParenOpen: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterParenOpen(ASF_Tree arg, char * wsAfterParenOpen) */

ASF_Tree ASF_setTreeWsAfterParenOpen(ASF_Tree arg, char * wsAfterParenOpen)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterParenOpen, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Tree has no WsAfterParenOpen: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeList(ASF_Tree arg) */

ATbool ASF_hasTreeList(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_getTreeList(ASF_Tree arg) */

ASF_CHARList ASF_getTreeList(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_CHARList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), 2);
  }

  ATabort("Tree has no List: %t\n", arg);
  return (ASF_CHARList)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeList(ASF_Tree arg, ASF_CHARList list) */

ASF_Tree ASF_setTreeList(ASF_Tree arg, ASF_CHARList list)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4), (ATerm)list, 2), 4), 2);
  }

  ATabort("Tree has no List: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeWsAfterList(ASF_Tree arg) */

ATbool ASF_hasTreeWsAfterList(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getTreeWsAfterList(ASF_Tree arg) */

char * ASF_getTreeWsAfterList(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), 0)));
  }

  ATabort("Tree has no WsAfterList: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterList(ASF_Tree arg, char * wsAfterList) */

ASF_Tree ASF_setTreeWsAfterList(ASF_Tree arg, char * wsAfterList)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 5), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterList, 0, ATtrue)), 0), 5), 2);
  }

  ATabort("Tree has no WsAfterList: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_CHARList accessors */

/*{{{  ATbool ASF_isValidCHARList(ASF_CHARList arg) */

ATbool ASF_isValidCHARList(ASF_CHARList arg)
{
  if (ASF_isCHARListEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isCHARListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isCHARListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_isCHARListEmpty(ASF_CHARList arg) */

ATbool ASF_isCHARListEmpty(ASF_CHARList arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternCHARListEmpty);
}

/*}}}  */
/*{{{  ATbool ASF_isCHARListSingle(ASF_CHARList arg) */

ATbool ASF_isCHARListSingle(ASF_CHARList arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternCHARListSingle, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_isCHARListMany(ASF_CHARList arg) */

ATbool ASF_isCHARListMany(ASF_CHARList arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternCHARListMany, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_hasCHARListHead(ASF_CHARList arg) */

ATbool ASF_hasCHARListHead(ASF_CHARList arg)
{
  if (ASF_isCHARListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isCHARListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CHAR ASF_getCHARListHead(ASF_CHARList arg) */

ASF_CHAR ASF_getCHARListHead(ASF_CHARList arg)
{
  if (ASF_isCHARListSingle(arg)) {
    return (ASF_CHAR)ATelementAt((ATermList)arg, 0);
  }
  else if (ASF_isCHARListMany(arg)) {
    return (ASF_CHAR)ATelementAt((ATermList)arg, 0);
  }

  ATabort("CHARList has no Head: %t\n", arg);
  return (ASF_CHAR)NULL;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_setCHARListHead(ASF_CHARList arg, ASF_CHAR head) */

ASF_CHARList ASF_setCHARListHead(ASF_CHARList arg, ASF_CHAR head)
{
  if (ASF_isCHARListSingle(arg)) {
    return (ASF_CHARList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (ASF_isCHARListMany(arg)) {
    return (ASF_CHARList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("CHARList has no Head: %t\n", arg);
  return (ASF_CHARList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCHARListWsAfterFirst(ASF_CHARList arg) */

ATbool ASF_hasCHARListWsAfterFirst(ASF_CHARList arg)
{
  if (ASF_isCHARListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getCHARListWsAfterFirst(ASF_CHARList arg) */

char * ASF_getCHARListWsAfterFirst(ASF_CHARList arg)
{
  if (ASF_isCHARListMany(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), 0)));
  }

  ATabort("CHARList has no WsAfterFirst: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_setCHARListWsAfterFirst(ASF_CHARList arg, char * wsAfterFirst) */

ASF_CHARList ASF_setCHARListWsAfterFirst(ASF_CHARList arg, char * wsAfterFirst)
{
  if (ASF_isCHARListMany(arg)) {
    return (ASF_CHARList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterFirst, 0, ATtrue)), 0), 1);
  }

  ATabort("CHARList has no WsAfterFirst: %t\n", arg);
  return (ASF_CHARList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCHARListTail(ASF_CHARList arg) */

ATbool ASF_hasCHARListTail(ASF_CHARList arg)
{
  if (ASF_isCHARListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_getCHARListTail(ASF_CHARList arg) */

ASF_CHARList ASF_getCHARListTail(ASF_CHARList arg)
{
  if (ASF_isCHARListMany(arg)) {
    return (ASF_CHARList)ATgetTail((ATermList)arg, 2);
  }

  ATabort("CHARList has no Tail: %t\n", arg);
  return (ASF_CHARList)NULL;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_setCHARListTail(ASF_CHARList arg, ASF_CHARList tail) */

ASF_CHARList ASF_setCHARListTail(ASF_CHARList arg, ASF_CHARList tail)
{
  if (ASF_isCHARListMany(arg)) {
    return (ASF_CHARList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("CHARList has no Tail: %t\n", arg);
  return (ASF_CHARList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Equation accessors */

/*{{{  ATbool ASF_isValidEquation(ASF_Equation arg) */

ATbool ASF_isValidEquation(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_isEquationDefault(ASF_Equation arg) */

ATbool ASF_isEquationDefault(ASF_Equation arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternEquationDefault, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationLhsSymbol(ASF_Equation arg) */

ATbool ASF_hasEquationLhsSymbol(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getEquationLhsSymbol(ASF_Equation arg) */

ASF_Symbol ASF_getEquationLhsSymbol(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 2), 0);
  }

  ATabort("Equation has no LhsSymbol: %t\n", arg);
  return (ASF_Symbol)NULL;
}

/*}}}  */
/*{{{  ASF_Equation ASF_setEquationLhsSymbol(ASF_Equation arg, ASF_Symbol lhsSymbol) */

ASF_Equation ASF_setEquationLhsSymbol(ASF_Equation arg, ASF_Symbol lhsSymbol)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Equation)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 2), (ATerm)lhsSymbol, 0), 2), 0);
  }

  ATabort("Equation has no LhsSymbol: %t\n", arg);
  return (ASF_Equation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationRhsSymbol(ASF_Equation arg) */

ATbool ASF_hasEquationRhsSymbol(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getEquationRhsSymbol(ASF_Equation arg) */

ASF_Symbol ASF_getEquationRhsSymbol(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 2), 4);
  }

  ATabort("Equation has no RhsSymbol: %t\n", arg);
  return (ASF_Symbol)NULL;
}

/*}}}  */
/*{{{  ASF_Equation ASF_setEquationRhsSymbol(ASF_Equation arg, ASF_Symbol rhsSymbol) */

ASF_Equation ASF_setEquationRhsSymbol(ASF_Equation arg, ASF_Symbol rhsSymbol)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Equation)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 2), (ATerm)rhsSymbol, 4), 2), 0);
  }

  ATabort("Equation has no RhsSymbol: %t\n", arg);
  return (ASF_Equation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationLhs(ASF_Equation arg) */

ATbool ASF_hasEquationLhs(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tree ASF_getEquationLhs(ASF_Equation arg) */

ASF_Tree ASF_getEquationLhs(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Equation has no Lhs: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Equation ASF_setEquationLhs(ASF_Equation arg, ASF_Tree lhs) */

ASF_Equation ASF_setEquationLhs(ASF_Equation arg, ASF_Tree lhs)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Equation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)lhs, 0), 2);
  }

  ATabort("Equation has no Lhs: %t\n", arg);
  return (ASF_Equation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationWsAfterLhs(ASF_Equation arg) */

ATbool ASF_hasEquationWsAfterLhs(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getEquationWsAfterLhs(ASF_Equation arg) */

char * ASF_getEquationWsAfterLhs(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Equation has no WsAfterLhs: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_Equation ASF_setEquationWsAfterLhs(ASF_Equation arg, char * wsAfterLhs) */

ASF_Equation ASF_setEquationWsAfterLhs(ASF_Equation arg, char * wsAfterLhs)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Equation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLhs, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Equation has no WsAfterLhs: %t\n", arg);
  return (ASF_Equation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationWsAfterEquals(ASF_Equation arg) */

ATbool ASF_hasEquationWsAfterEquals(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getEquationWsAfterEquals(ASF_Equation arg) */

char * ASF_getEquationWsAfterEquals(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Equation has no WsAfterEquals: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_Equation ASF_setEquationWsAfterEquals(ASF_Equation arg, char * wsAfterEquals) */

ASF_Equation ASF_setEquationWsAfterEquals(ASF_Equation arg, char * wsAfterEquals)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Equation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterEquals, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Equation has no WsAfterEquals: %t\n", arg);
  return (ASF_Equation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationRhs(ASF_Equation arg) */

ATbool ASF_hasEquationRhs(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tree ASF_getEquationRhs(ASF_Equation arg) */

ASF_Tree ASF_getEquationRhs(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Equation has no Rhs: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Equation ASF_setEquationRhs(ASF_Equation arg, ASF_Tree rhs) */

ASF_Equation ASF_setEquationRhs(ASF_Equation arg, ASF_Tree rhs)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Equation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)rhs, 4), 2);
  }

  ATabort("Equation has no Rhs: %t\n", arg);
  return (ASF_Equation)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Condition accessors */

/*{{{  ATbool ASF_isValidCondition(ASF_Condition arg) */

ATbool ASF_isValidCondition(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_isConditionPositive(ASF_Condition arg) */

ATbool ASF_isConditionPositive(ASF_Condition arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternConditionPositive, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_isConditionNegative(ASF_Condition arg) */

ATbool ASF_isConditionNegative(ASF_Condition arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternConditionNegative, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionLhsSymbol(ASF_Condition arg) */

ATbool ASF_hasConditionLhsSymbol(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getConditionLhsSymbol(ASF_Condition arg) */

ASF_Symbol ASF_getConditionLhsSymbol(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 2), 0);
  }
  else if (ASF_isConditionNegative(arg)) {
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 2), 0);
  }

  ATabort("Condition has no LhsSymbol: %t\n", arg);
  return (ASF_Symbol)NULL;
}

/*}}}  */
/*{{{  ASF_Condition ASF_setConditionLhsSymbol(ASF_Condition arg, ASF_Symbol lhsSymbol) */

ASF_Condition ASF_setConditionLhsSymbol(ASF_Condition arg, ASF_Symbol lhsSymbol)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 2), (ATerm)lhsSymbol, 0), 2), 0);
  }
  else if (ASF_isConditionNegative(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 2), (ATerm)lhsSymbol, 0), 2), 0);
  }

  ATabort("Condition has no LhsSymbol: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionRhsSymbol(ASF_Condition arg) */

ATbool ASF_hasConditionRhsSymbol(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getConditionRhsSymbol(ASF_Condition arg) */

ASF_Symbol ASF_getConditionRhsSymbol(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 2), 4);
  }
  else if (ASF_isConditionNegative(arg)) {
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 2), 4);
  }

  ATabort("Condition has no RhsSymbol: %t\n", arg);
  return (ASF_Symbol)NULL;
}

/*}}}  */
/*{{{  ASF_Condition ASF_setConditionRhsSymbol(ASF_Condition arg, ASF_Symbol rhsSymbol) */

ASF_Condition ASF_setConditionRhsSymbol(ASF_Condition arg, ASF_Symbol rhsSymbol)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 2), (ATerm)rhsSymbol, 4), 2), 0);
  }
  else if (ASF_isConditionNegative(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 2), (ATerm)rhsSymbol, 4), 2), 0);
  }

  ATabort("Condition has no RhsSymbol: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionLhs(ASF_Condition arg) */

ATbool ASF_hasConditionLhs(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tree ASF_getConditionLhs(ASF_Condition arg) */

ASF_Tree ASF_getConditionLhs(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }
  else if (ASF_isConditionNegative(arg)) {
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 0);
  }

  ATabort("Condition has no Lhs: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Condition ASF_setConditionLhs(ASF_Condition arg, ASF_Tree lhs) */

ASF_Condition ASF_setConditionLhs(ASF_Condition arg, ASF_Tree lhs)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)lhs, 0), 2);
  }
  else if (ASF_isConditionNegative(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)lhs, 0), 2);
  }

  ATabort("Condition has no Lhs: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionWsAfterLhs(ASF_Condition arg) */

ATbool ASF_hasConditionWsAfterLhs(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getConditionWsAfterLhs(ASF_Condition arg) */

char * ASF_getConditionWsAfterLhs(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }
  else if (ASF_isConditionNegative(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), 0)));
  }

  ATabort("Condition has no WsAfterLhs: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_Condition ASF_setConditionWsAfterLhs(ASF_Condition arg, char * wsAfterLhs) */

ASF_Condition ASF_setConditionWsAfterLhs(ASF_Condition arg, char * wsAfterLhs)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLhs, 0, ATtrue)), 0), 1), 2);
  }
  else if (ASF_isConditionNegative(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 1), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterLhs, 0, ATtrue)), 0), 1), 2);
  }

  ATabort("Condition has no WsAfterLhs: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionWsAfterEquals(ASF_Condition arg) */

ATbool ASF_hasConditionWsAfterEquals(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getConditionWsAfterEquals(ASF_Condition arg) */

char * ASF_getConditionWsAfterEquals(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Condition has no WsAfterEquals: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_Condition ASF_setConditionWsAfterEquals(ASF_Condition arg, char * wsAfterEquals) */

ASF_Condition ASF_setConditionWsAfterEquals(ASF_Condition arg, char * wsAfterEquals)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterEquals, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Condition has no WsAfterEquals: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionRhs(ASF_Condition arg) */

ATbool ASF_hasConditionRhs(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tree ASF_getConditionRhs(ASF_Condition arg) */

ASF_Tree ASF_getConditionRhs(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }
  else if (ASF_isConditionNegative(arg)) {
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 4);
  }

  ATabort("Condition has no Rhs: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Condition ASF_setConditionRhs(ASF_Condition arg, ASF_Tree rhs) */

ASF_Condition ASF_setConditionRhs(ASF_Condition arg, ASF_Tree rhs)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)rhs, 4), 2);
  }
  else if (ASF_isConditionNegative(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)rhs, 4), 2);
  }

  ATabort("Condition has no Rhs: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionWsAfterUnequal(ASF_Condition arg) */

ATbool ASF_hasConditionWsAfterUnequal(ASF_Condition arg)
{
  if (ASF_isConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getConditionWsAfterUnequal(ASF_Condition arg) */

char * ASF_getConditionWsAfterUnequal(ASF_Condition arg)
{
  if (ASF_isConditionNegative(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), 0)));
  }

  ATabort("Condition has no WsAfterUnequal: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_Condition ASF_setConditionWsAfterUnequal(ASF_Condition arg, char * wsAfterUnequal) */

ASF_Condition ASF_setConditionWsAfterUnequal(ASF_Condition arg, char * wsAfterUnequal)
{
  if (ASF_isConditionNegative(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 2), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 2), 3), (ATerm)ATmakeAppl0(ATmakeAFun(wsAfterUnequal, 0, ATtrue)), 0), 3), 2);
  }

  ATabort("Condition has no WsAfterUnequal: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_CHAR accessors */

/*{{{  ATbool ASF_isValidCHAR(ASF_CHAR arg) */

ATbool ASF_isValidCHAR(ASF_CHAR arg)
{
  if (ASF_isCHARDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_isCHARDefault(ASF_CHAR arg) */

ATbool ASF_isCHARDefault(ASF_CHAR arg)
{
  return ATmatchTerm((ATerm)arg, ASF_patternCHARDefault, NULL);
}

/*}}}  */
/*{{{  ATbool ASF_hasCHARLex(ASF_CHAR arg) */

ATbool ASF_hasCHARLex(ASF_CHAR arg)
{
  if (ASF_isCHARDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getCHARLex(ASF_CHAR arg) */

char * ASF_getCHARLex(ASF_CHAR arg)
{
  if (ASF_isCHARDefault(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("CHAR has no Lex: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  ASF_CHAR ASF_setCHARLex(ASF_CHAR arg, char * lex) */

ASF_CHAR ASF_setCHARLex(ASF_CHAR arg, char * lex)
{
  if (ASF_isCHARDefault(arg)) {
    return (ASF_CHAR)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(lex, 0, ATtrue)), 0);
  }

  ATabort("CHAR has no Lex: %t\n", arg);
  return (ASF_CHAR)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  ASF_Production ASF_visitProduction(ASF_Production arg, char * (*acceptFormalName)(char *), ASF_Symbol (*acceptSymbol)(ASF_Symbol)) */

ASF_Production ASF_visitProduction(ASF_Production arg, char * (*acceptFormalName)(char *), ASF_Symbol (*acceptSymbol)(ASF_Symbol))
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return ASF_makeProductionLexicalConstructor(
        acceptFormalName ? acceptFormalName(ASF_getProductionFormalName(arg)) : ASF_getProductionFormalName(arg),
        acceptSymbol ? acceptSymbol(ASF_getProductionSymbol(arg)) : ASF_getProductionSymbol(arg));
  }
  ATabort("not a Production: %t\n", arg);
  return (ASF_Production)NULL;
}

/*}}}  */
/*{{{  ASF_Implies ASF_visitImplies(ASF_Implies arg, char * (*acceptLex)(char *)) */

ASF_Implies ASF_visitImplies(ASF_Implies arg, char * (*acceptLex)(char *))
{
  if (ASF_isImpliesDefault(arg)) {
    return ASF_makeImpliesDefault(
        acceptLex ? acceptLex(ASF_getImpliesLex(arg)) : ASF_getImpliesLex(arg));
  }
  ATabort("not a Implies: %t\n", arg);
  return (ASF_Implies)NULL;
}

/*}}}  */
/*{{{  ASF_TagId ASF_visitTagId(ASF_TagId arg, char * (*acceptLex)(char *)) */

ASF_TagId ASF_visitTagId(ASF_TagId arg, char * (*acceptLex)(char *))
{
  if (ASF_isTagIdOneChar(arg)) {
    return ASF_makeTagIdOneChar(
        acceptLex ? acceptLex(ASF_getTagIdLex(arg)) : ASF_getTagIdLex(arg));
  }
  if (ASF_isTagIdManyChars(arg)) {
    return ASF_makeTagIdManyChars(
        acceptLex ? acceptLex(ASF_getTagIdLex(arg)) : ASF_getTagIdLex(arg));
  }
  ATabort("not a TagId: %t\n", arg);
  return (ASF_TagId)NULL;
}

/*}}}  */
/*{{{  ASF_Conditions ASF_visitConditions(ASF_Conditions arg, ASF_ConditionList (*acceptList)(ASF_ConditionList)) */

ASF_Conditions ASF_visitConditions(ASF_Conditions arg, ASF_ConditionList (*acceptList)(ASF_ConditionList))
{
  if (ASF_isConditionsDefault(arg)) {
    return ASF_makeConditionsDefault(
        acceptList ? acceptList(ASF_getConditionsList(arg)) : ASF_getConditionsList(arg));
  }
  ATabort("not a Conditions: %t\n", arg);
  return (ASF_Conditions)NULL;
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_visitConditionList(ASF_ConditionList arg, ASF_Condition (*acceptHead)(ASF_Condition), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *)) */

ASF_ConditionList ASF_visitConditionList(ASF_ConditionList arg, ASF_Condition (*acceptHead)(ASF_Condition), char * (*acceptWsAfterFirst)(char *), char * (*acceptSep)(char *), char * (*acceptWsAfterSep)(char *))
{
  if (ASF_isConditionListSingle(arg)) {
    return ASF_makeConditionListSingle(
        acceptHead ? acceptHead(ASF_getConditionListHead(arg)) : ASF_getConditionListHead(arg));
  }
  if (ASF_isConditionListMany(arg)) {
    return ASF_makeConditionListMany(
        acceptHead ? acceptHead(ASF_getConditionListHead(arg)) : ASF_getConditionListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(ASF_getConditionListWsAfterFirst(arg)) : ASF_getConditionListWsAfterFirst(arg),
        acceptSep ? acceptSep(ASF_getConditionListSep(arg)) : ASF_getConditionListSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(ASF_getConditionListWsAfterSep(arg)) : ASF_getConditionListWsAfterSep(arg),
        ASF_visitConditionList(ASF_getConditionListTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a ConditionList: %t\n", arg);
  return (ASF_ConditionList)NULL;
}

/*}}}  */
/*{{{  ASF_Equations ASF_visitEquations(ASF_Equations arg, char * (*acceptWsAfterEquations)(char *), ASF_CondEquationList (*acceptList)(ASF_CondEquationList)) */

ASF_Equations ASF_visitEquations(ASF_Equations arg, char * (*acceptWsAfterEquations)(char *), ASF_CondEquationList (*acceptList)(ASF_CondEquationList))
{
  if (ASF_isEquationsAbsent(arg)) {
    return ASF_makeEquationsAbsent();
  }
  if (ASF_isEquationsPresent(arg)) {
    return ASF_makeEquationsPresent(
        acceptWsAfterEquations ? acceptWsAfterEquations(ASF_getEquationsWsAfterEquations(arg)) : ASF_getEquationsWsAfterEquations(arg),
        acceptList ? acceptList(ASF_getEquationsList(arg)) : ASF_getEquationsList(arg));
  }
  ATabort("not a Equations: %t\n", arg);
  return (ASF_Equations)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_visitCondEquationList(ASF_CondEquationList arg, ASF_CondEquation (*acceptHead)(ASF_CondEquation), char * (*acceptWsAfterFirst)(char *)) */

ASF_CondEquationList ASF_visitCondEquationList(ASF_CondEquationList arg, ASF_CondEquation (*acceptHead)(ASF_CondEquation), char * (*acceptWsAfterFirst)(char *))
{
  if (ASF_isCondEquationListEmpty(arg)) {
    return ASF_makeCondEquationListEmpty();
  }
  if (ASF_isCondEquationListSingle(arg)) {
    return ASF_makeCondEquationListSingle(
        acceptHead ? acceptHead(ASF_getCondEquationListHead(arg)) : ASF_getCondEquationListHead(arg));
  }
  if (ASF_isCondEquationListMany(arg)) {
    return ASF_makeCondEquationListMany(
        acceptHead ? acceptHead(ASF_getCondEquationListHead(arg)) : ASF_getCondEquationListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(ASF_getCondEquationListWsAfterFirst(arg)) : ASF_getCondEquationListWsAfterFirst(arg),
        ASF_visitCondEquationList(ASF_getCondEquationListTail(arg), acceptHead, acceptWsAfterFirst));
  }
  ATabort("not a CondEquationList: %t\n", arg);
  return (ASF_CondEquationList)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_visitCondEquation(ASF_CondEquation arg, ASF_Tag (*acceptTag)(ASF_Tag), char * (*acceptWsAfterTag)(char *), ASF_Equation (*acceptEquation)(ASF_Equation), ASF_Conditions (*acceptConditions)(ASF_Conditions), char * (*acceptWsAfterConditions)(char *), ASF_Implies (*acceptImplies)(ASF_Implies), char * (*acceptWsAfterImplies)(char *), char * (*acceptWsAfterEquation)(char *), char * (*acceptWsAfterWhen)(char *)) */

ASF_CondEquation ASF_visitCondEquation(ASF_CondEquation arg, ASF_Tag (*acceptTag)(ASF_Tag), char * (*acceptWsAfterTag)(char *), ASF_Equation (*acceptEquation)(ASF_Equation), ASF_Conditions (*acceptConditions)(ASF_Conditions), char * (*acceptWsAfterConditions)(char *), ASF_Implies (*acceptImplies)(ASF_Implies), char * (*acceptWsAfterImplies)(char *), char * (*acceptWsAfterEquation)(char *), char * (*acceptWsAfterWhen)(char *))
{
  if (ASF_isCondEquationSimple(arg)) {
    return ASF_makeCondEquationSimple(
        acceptTag ? acceptTag(ASF_getCondEquationTag(arg)) : ASF_getCondEquationTag(arg),
        acceptWsAfterTag ? acceptWsAfterTag(ASF_getCondEquationWsAfterTag(arg)) : ASF_getCondEquationWsAfterTag(arg),
        acceptEquation ? acceptEquation(ASF_getCondEquationEquation(arg)) : ASF_getCondEquationEquation(arg));
  }
  if (ASF_isCondEquationImplies(arg)) {
    return ASF_makeCondEquationImplies(
        acceptTag ? acceptTag(ASF_getCondEquationTag(arg)) : ASF_getCondEquationTag(arg),
        acceptWsAfterTag ? acceptWsAfterTag(ASF_getCondEquationWsAfterTag(arg)) : ASF_getCondEquationWsAfterTag(arg),
        acceptConditions ? acceptConditions(ASF_getCondEquationConditions(arg)) : ASF_getCondEquationConditions(arg),
        acceptWsAfterConditions ? acceptWsAfterConditions(ASF_getCondEquationWsAfterConditions(arg)) : ASF_getCondEquationWsAfterConditions(arg),
        acceptImplies ? acceptImplies(ASF_getCondEquationImplies(arg)) : ASF_getCondEquationImplies(arg),
        acceptWsAfterImplies ? acceptWsAfterImplies(ASF_getCondEquationWsAfterImplies(arg)) : ASF_getCondEquationWsAfterImplies(arg),
        acceptEquation ? acceptEquation(ASF_getCondEquationEquation(arg)) : ASF_getCondEquationEquation(arg));
  }
  if (ASF_isCondEquationWhen(arg)) {
    return ASF_makeCondEquationWhen(
        acceptTag ? acceptTag(ASF_getCondEquationTag(arg)) : ASF_getCondEquationTag(arg),
        acceptWsAfterTag ? acceptWsAfterTag(ASF_getCondEquationWsAfterTag(arg)) : ASF_getCondEquationWsAfterTag(arg),
        acceptEquation ? acceptEquation(ASF_getCondEquationEquation(arg)) : ASF_getCondEquationEquation(arg),
        acceptWsAfterEquation ? acceptWsAfterEquation(ASF_getCondEquationWsAfterEquation(arg)) : ASF_getCondEquationWsAfterEquation(arg),
        acceptWsAfterWhen ? acceptWsAfterWhen(ASF_getCondEquationWsAfterWhen(arg)) : ASF_getCondEquationWsAfterWhen(arg),
        acceptConditions ? acceptConditions(ASF_getCondEquationConditions(arg)) : ASF_getCondEquationConditions(arg));
  }
  ATabort("not a CondEquation: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ASF_Tag ASF_visitTag(ASF_Tag arg, char * (*acceptWsAfterBracketOpen)(char *), ASF_TagId (*acceptTagId)(ASF_TagId), char * (*acceptWsAfterTagId)(char *)) */

ASF_Tag ASF_visitTag(ASF_Tag arg, char * (*acceptWsAfterBracketOpen)(char *), ASF_TagId (*acceptTagId)(ASF_TagId), char * (*acceptWsAfterTagId)(char *))
{
  if (ASF_isTagEmpty(arg)) {
    return ASF_makeTagEmpty(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(ASF_getTagWsAfterBracketOpen(arg)) : ASF_getTagWsAfterBracketOpen(arg));
  }
  if (ASF_isTagNotEmpty(arg)) {
    return ASF_makeTagNotEmpty(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(ASF_getTagWsAfterBracketOpen(arg)) : ASF_getTagWsAfterBracketOpen(arg),
        acceptTagId ? acceptTagId(ASF_getTagTagId(arg)) : ASF_getTagTagId(arg),
        acceptWsAfterTagId ? acceptWsAfterTagId(ASF_getTagWsAfterTagId(arg)) : ASF_getTagWsAfterTagId(arg));
  }
  ATabort("not a Tag: %t\n", arg);
  return (ASF_Tag)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_visitTree(ASF_Tree arg, char * (*acceptFormalName)(char *), ASF_Symbol (*acceptSymbol)(ASF_Symbol), char * (*acceptWsAfterName)(char *), char * (*acceptWsAfterParenOpen)(char *), ASF_CHARList (*acceptList)(ASF_CHARList), char * (*acceptWsAfterList)(char *)) */

ASF_Tree ASF_visitTree(ASF_Tree arg, char * (*acceptFormalName)(char *), ASF_Symbol (*acceptSymbol)(ASF_Symbol), char * (*acceptWsAfterName)(char *), char * (*acceptWsAfterParenOpen)(char *), ASF_CHARList (*acceptList)(ASF_CHARList), char * (*acceptWsAfterList)(char *))
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ASF_makeTreeLexicalConstructor(
        acceptFormalName ? acceptFormalName(ASF_getTreeFormalName(arg)) : ASF_getTreeFormalName(arg),
        acceptSymbol ? acceptSymbol(ASF_getTreeSymbol(arg)) : ASF_getTreeSymbol(arg),
        ASF_visitTree(ASF_getTreeName(arg), acceptFormalName, acceptSymbol, acceptWsAfterName, acceptWsAfterParenOpen, acceptList, acceptWsAfterList),
        acceptWsAfterName ? acceptWsAfterName(ASF_getTreeWsAfterName(arg)) : ASF_getTreeWsAfterName(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(ASF_getTreeWsAfterParenOpen(arg)) : ASF_getTreeWsAfterParenOpen(arg),
        acceptList ? acceptList(ASF_getTreeList(arg)) : ASF_getTreeList(arg),
        acceptWsAfterList ? acceptWsAfterList(ASF_getTreeWsAfterList(arg)) : ASF_getTreeWsAfterList(arg));
  }
  ATabort("not a Tree: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_visitCHARList(ASF_CHARList arg, ASF_CHAR (*acceptHead)(ASF_CHAR), char * (*acceptWsAfterFirst)(char *)) */

ASF_CHARList ASF_visitCHARList(ASF_CHARList arg, ASF_CHAR (*acceptHead)(ASF_CHAR), char * (*acceptWsAfterFirst)(char *))
{
  if (ASF_isCHARListEmpty(arg)) {
    return ASF_makeCHARListEmpty();
  }
  if (ASF_isCHARListSingle(arg)) {
    return ASF_makeCHARListSingle(
        acceptHead ? acceptHead(ASF_getCHARListHead(arg)) : ASF_getCHARListHead(arg));
  }
  if (ASF_isCHARListMany(arg)) {
    return ASF_makeCHARListMany(
        acceptHead ? acceptHead(ASF_getCHARListHead(arg)) : ASF_getCHARListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(ASF_getCHARListWsAfterFirst(arg)) : ASF_getCHARListWsAfterFirst(arg),
        ASF_visitCHARList(ASF_getCHARListTail(arg), acceptHead, acceptWsAfterFirst));
  }
  ATabort("not a CHARList: %t\n", arg);
  return (ASF_CHARList)NULL;
}

/*}}}  */
/*{{{  ASF_Equation ASF_visitEquation(ASF_Equation arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), char * (*acceptWsAfterLhs)(char *), char * (*acceptWsAfterEquals)(char *), ASF_Tree (*acceptRhs)(ASF_Tree)) */

ASF_Equation ASF_visitEquation(ASF_Equation arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), char * (*acceptWsAfterLhs)(char *), char * (*acceptWsAfterEquals)(char *), ASF_Tree (*acceptRhs)(ASF_Tree))
{
  if (ASF_isEquationDefault(arg)) {
    return ASF_makeEquationDefault(
        acceptLhsSymbol ? acceptLhsSymbol(ASF_getEquationLhsSymbol(arg)) : ASF_getEquationLhsSymbol(arg),
        acceptRhsSymbol ? acceptRhsSymbol(ASF_getEquationRhsSymbol(arg)) : ASF_getEquationRhsSymbol(arg),
        acceptLhs ? acceptLhs(ASF_getEquationLhs(arg)) : ASF_getEquationLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getEquationWsAfterLhs(arg)) : ASF_getEquationWsAfterLhs(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(ASF_getEquationWsAfterEquals(arg)) : ASF_getEquationWsAfterEquals(arg),
        acceptRhs ? acceptRhs(ASF_getEquationRhs(arg)) : ASF_getEquationRhs(arg));
  }
  ATabort("not a Equation: %t\n", arg);
  return (ASF_Equation)NULL;
}

/*}}}  */
/*{{{  ASF_Condition ASF_visitCondition(ASF_Condition arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), char * (*acceptWsAfterLhs)(char *), char * (*acceptWsAfterEquals)(char *), ASF_Tree (*acceptRhs)(ASF_Tree), char * (*acceptWsAfterUnequal)(char *)) */

ASF_Condition ASF_visitCondition(ASF_Condition arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), char * (*acceptWsAfterLhs)(char *), char * (*acceptWsAfterEquals)(char *), ASF_Tree (*acceptRhs)(ASF_Tree), char * (*acceptWsAfterUnequal)(char *))
{
  if (ASF_isConditionPositive(arg)) {
    return ASF_makeConditionPositive(
        acceptLhsSymbol ? acceptLhsSymbol(ASF_getConditionLhsSymbol(arg)) : ASF_getConditionLhsSymbol(arg),
        acceptRhsSymbol ? acceptRhsSymbol(ASF_getConditionRhsSymbol(arg)) : ASF_getConditionRhsSymbol(arg),
        acceptLhs ? acceptLhs(ASF_getConditionLhs(arg)) : ASF_getConditionLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getConditionWsAfterLhs(arg)) : ASF_getConditionWsAfterLhs(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(ASF_getConditionWsAfterEquals(arg)) : ASF_getConditionWsAfterEquals(arg),
        acceptRhs ? acceptRhs(ASF_getConditionRhs(arg)) : ASF_getConditionRhs(arg));
  }
  if (ASF_isConditionNegative(arg)) {
    return ASF_makeConditionNegative(
        acceptLhsSymbol ? acceptLhsSymbol(ASF_getConditionLhsSymbol(arg)) : ASF_getConditionLhsSymbol(arg),
        acceptRhsSymbol ? acceptRhsSymbol(ASF_getConditionRhsSymbol(arg)) : ASF_getConditionRhsSymbol(arg),
        acceptLhs ? acceptLhs(ASF_getConditionLhs(arg)) : ASF_getConditionLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getConditionWsAfterLhs(arg)) : ASF_getConditionWsAfterLhs(arg),
        acceptWsAfterUnequal ? acceptWsAfterUnequal(ASF_getConditionWsAfterUnequal(arg)) : ASF_getConditionWsAfterUnequal(arg),
        acceptRhs ? acceptRhs(ASF_getConditionRhs(arg)) : ASF_getConditionRhs(arg));
  }
  ATabort("not a Condition: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */
/*{{{  ASF_CHAR ASF_visitCHAR(ASF_CHAR arg, char * (*acceptLex)(char *)) */

ASF_CHAR ASF_visitCHAR(ASF_CHAR arg, char * (*acceptLex)(char *))
{
  if (ASF_isCHARDefault(arg)) {
    return ASF_makeCHARDefault(
        acceptLex ? acceptLex(ASF_getCHARLex(arg)) : ASF_getCHARLex(arg));
  }
  ATabort("not a CHAR: %t\n", arg);
  return (ASF_CHAR)NULL;
}

/*}}}  */

/*}}}  */
