#ifndef _ASF_H
#define _ASF_H

/*{{{  includes */

#include <aterm1.h>
#include "ASF_dict.h"

/*}}}  */

/*{{{  prologue */

typedef ATerm ASF_Layout;
typedef ATerm ASF_Separator;
typedef ATerm ASF_Lexical;
typedef ATerm ASF_Symbol;

/*}}}  */
/*{{{  typedefs */

typedef struct _ASF_Implies *ASF_Implies;
typedef struct _ASF_TagId *ASF_TagId;
typedef struct _ASF_Conditions *ASF_Conditions;
typedef struct _ASF_ConditionList *ASF_ConditionList;
typedef struct _ASF_Equations *ASF_Equations;
typedef struct _ASF_CondEquationList *ASF_CondEquationList;
typedef struct _ASF_CondEquation *ASF_CondEquation;
typedef struct _ASF_Tag *ASF_Tag;
typedef struct _ASF_Tree *ASF_Tree;
typedef struct _ASF_CHARList *ASF_CHARList;
typedef struct _ASF_Equation *ASF_Equation;
typedef struct _ASF_Condition *ASF_Condition;
typedef struct _ASF_CHAR *ASF_CHAR;

/*}}}  */

void ASF_initASFApi(void);

/*{{{  term conversion functions */

ASF_Implies ASF_makeImpliesFromTerm(ATerm t);
ATerm ASF_makeTermFromImplies(ASF_Implies arg);
ASF_TagId ASF_makeTagIdFromTerm(ATerm t);
ATerm ASF_makeTermFromTagId(ASF_TagId arg);
ASF_Conditions ASF_makeConditionsFromTerm(ATerm t);
ATerm ASF_makeTermFromConditions(ASF_Conditions arg);
ASF_ConditionList ASF_makeConditionListFromTerm(ATerm t);
ATerm ASF_makeTermFromConditionList(ASF_ConditionList arg);
ASF_Equations ASF_makeEquationsFromTerm(ATerm t);
ATerm ASF_makeTermFromEquations(ASF_Equations arg);
ASF_CondEquationList ASF_makeCondEquationListFromTerm(ATerm t);
ATerm ASF_makeTermFromCondEquationList(ASF_CondEquationList arg);
ASF_CondEquation ASF_makeCondEquationFromTerm(ATerm t);
ATerm ASF_makeTermFromCondEquation(ASF_CondEquation arg);
ASF_Tag ASF_makeTagFromTerm(ATerm t);
ATerm ASF_makeTermFromTag(ASF_Tag arg);
ASF_Tree ASF_makeTreeFromTerm(ATerm t);
ATerm ASF_makeTermFromTree(ASF_Tree arg);
ASF_CHARList ASF_makeCHARListFromTerm(ATerm t);
ATerm ASF_makeTermFromCHARList(ASF_CHARList arg);
ASF_Equation ASF_makeEquationFromTerm(ATerm t);
ATerm ASF_makeTermFromEquation(ASF_Equation arg);
ASF_Condition ASF_makeConditionFromTerm(ATerm t);
ATerm ASF_makeTermFromCondition(ASF_Condition arg);
ASF_CHAR ASF_makeCHARFromTerm(ATerm t);
ATerm ASF_makeTermFromCHAR(ASF_CHAR arg);

/*}}}  */
/*{{{  constructors */

ASF_Implies ASF_makeImpliesDefault(ASF_Lexical lex);
ASF_TagId ASF_makeTagIdOneChar(ASF_Lexical lex);
ASF_TagId ASF_makeTagIdManyChars(ASF_Lexical lex);
ASF_Conditions ASF_makeConditionsDefault(ASF_ConditionList list);
ASF_ConditionList ASF_makeConditionListSingle(ASF_Condition head);
ASF_ConditionList ASF_makeConditionListMany(ASF_Condition head, ASF_Layout wsAfterFirst, ASF_Separator sep, ASF_Layout wsAfterSep, ASF_ConditionList tail);
ASF_Equations ASF_makeEquationsAbsent();
ASF_Equations ASF_makeEquationsPresent(ASF_Layout wsAfterEquations, ASF_CondEquationList list);
ASF_CondEquationList ASF_makeCondEquationListEmpty();
ASF_CondEquationList ASF_makeCondEquationListSingle(ASF_CondEquation head);
ASF_CondEquationList ASF_makeCondEquationListMany(ASF_CondEquation head, ASF_Layout wsAfterFirst, ASF_CondEquationList tail);
ASF_CondEquation ASF_makeCondEquationSimple(ASF_Tag Tag, ASF_Layout wsAfterTag, ASF_Equation Equation);
ASF_CondEquation ASF_makeCondEquationImplies(ASF_Tag Tag, ASF_Layout wsAfterTag, ASF_Conditions Conditions, ASF_Layout wsAfterConditions, ASF_Implies Implies, ASF_Layout wsAfterImplies, ASF_Equation Equation);
ASF_CondEquation ASF_makeCondEquationWhen(ASF_Tag Tag, ASF_Layout wsAfterTag, ASF_Equation Equation, ASF_Layout wsAfterEquation, ASF_Layout wsAfterWhen, ASF_Conditions Conditions);
ASF_Tag ASF_makeTagEmpty(ASF_Layout wsAfterBracketOpen);
ASF_Tag ASF_makeTagNotEmpty(ASF_Layout wsAfterBracketOpen, ASF_TagId TagId, ASF_Layout wsAfterTagId);
ASF_Tree ASF_makeTreeLexicalConstructor(ASF_Symbol symbolName, ASF_Symbol symbol, ASF_Tree name, ASF_Layout wsAfterName, ASF_Layout wsAfterParenOpen, ASF_CHARList list, ASF_Layout wsAfterList);
ASF_CHARList ASF_makeCHARListEmpty();
ASF_CHARList ASF_makeCHARListSingle(ASF_CHAR head);
ASF_CHARList ASF_makeCHARListMany(ASF_CHAR head, ASF_Layout wsAfterFirst, ASF_CHARList tail);
ASF_Equation ASF_makeEquationDefault(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_Layout wsAfterLhs, ASF_Layout wsAfterEquals, ASF_Tree rhs);
ASF_Condition ASF_makeConditionPositive(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_Layout wsAfterLhs, ASF_Layout wsAfterEquals, ASF_Tree rhs);
ASF_Condition ASF_makeConditionNegative(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_Layout wsAfterLhs, ASF_Layout wsAfterUnequal, ASF_Tree rhs);
ASF_CHAR ASF_makeCHARDefault(ASF_Lexical lex);

/*}}}  */
/*{{{  equality functions */

ATbool ASF_isEqualImplies(ASF_Implies arg0, ASF_Implies arg1);
ATbool ASF_isEqualTagId(ASF_TagId arg0, ASF_TagId arg1);
ATbool ASF_isEqualConditions(ASF_Conditions arg0, ASF_Conditions arg1);
ATbool ASF_isEqualConditionList(ASF_ConditionList arg0, ASF_ConditionList arg1);
ATbool ASF_isEqualEquations(ASF_Equations arg0, ASF_Equations arg1);
ATbool ASF_isEqualCondEquationList(ASF_CondEquationList arg0, ASF_CondEquationList arg1);
ATbool ASF_isEqualCondEquation(ASF_CondEquation arg0, ASF_CondEquation arg1);
ATbool ASF_isEqualTag(ASF_Tag arg0, ASF_Tag arg1);
ATbool ASF_isEqualTree(ASF_Tree arg0, ASF_Tree arg1);
ATbool ASF_isEqualCHARList(ASF_CHARList arg0, ASF_CHARList arg1);
ATbool ASF_isEqualEquation(ASF_Equation arg0, ASF_Equation arg1);
ATbool ASF_isEqualCondition(ASF_Condition arg0, ASF_Condition arg1);
ATbool ASF_isEqualCHAR(ASF_CHAR arg0, ASF_CHAR arg1);

/*}}}  */
/*{{{  ASF_Implies accessors */

ATbool ASF_isValidImplies(ASF_Implies arg);
ATbool ASF_isImpliesDefault(ASF_Implies arg);
ATbool ASF_hasImpliesLex(ASF_Implies arg);
ASF_Lexical ASF_getImpliesLex(ASF_Implies arg);
ASF_Implies ASF_setImpliesLex(ASF_Implies arg, ASF_Lexical lex);

/*}}}  */
/*{{{  ASF_TagId accessors */

ATbool ASF_isValidTagId(ASF_TagId arg);
ATbool ASF_isTagIdOneChar(ASF_TagId arg);
ATbool ASF_isTagIdManyChars(ASF_TagId arg);
ATbool ASF_hasTagIdLex(ASF_TagId arg);
ASF_Lexical ASF_getTagIdLex(ASF_TagId arg);
ASF_TagId ASF_setTagIdLex(ASF_TagId arg, ASF_Lexical lex);

/*}}}  */
/*{{{  ASF_Conditions accessors */

ATbool ASF_isValidConditions(ASF_Conditions arg);
ATbool ASF_isConditionsDefault(ASF_Conditions arg);
ATbool ASF_hasConditionsList(ASF_Conditions arg);
ASF_ConditionList ASF_getConditionsList(ASF_Conditions arg);
ASF_Conditions ASF_setConditionsList(ASF_Conditions arg, ASF_ConditionList list);

/*}}}  */
/*{{{  ASF_ConditionList accessors */

ATbool ASF_isValidConditionList(ASF_ConditionList arg);
ATbool ASF_isConditionListSingle(ASF_ConditionList arg);
ATbool ASF_isConditionListMany(ASF_ConditionList arg);
ATbool ASF_hasConditionListHead(ASF_ConditionList arg);
ASF_Condition ASF_getConditionListHead(ASF_ConditionList arg);
ASF_ConditionList ASF_setConditionListHead(ASF_ConditionList arg, ASF_Condition head);
ATbool ASF_hasConditionListWsAfterFirst(ASF_ConditionList arg);
ASF_Layout ASF_getConditionListWsAfterFirst(ASF_ConditionList arg);
ASF_ConditionList ASF_setConditionListWsAfterFirst(ASF_ConditionList arg, ASF_Layout wsAfterFirst);
ATbool ASF_hasConditionListSep(ASF_ConditionList arg);
ASF_Separator ASF_getConditionListSep(ASF_ConditionList arg);
ASF_ConditionList ASF_setConditionListSep(ASF_ConditionList arg, ASF_Separator sep);
ATbool ASF_hasConditionListWsAfterSep(ASF_ConditionList arg);
ASF_Layout ASF_getConditionListWsAfterSep(ASF_ConditionList arg);
ASF_ConditionList ASF_setConditionListWsAfterSep(ASF_ConditionList arg, ASF_Layout wsAfterSep);
ATbool ASF_hasConditionListTail(ASF_ConditionList arg);
ASF_ConditionList ASF_getConditionListTail(ASF_ConditionList arg);
ASF_ConditionList ASF_setConditionListTail(ASF_ConditionList arg, ASF_ConditionList tail);

/*}}}  */
/*{{{  ASF_Equations accessors */

ATbool ASF_isValidEquations(ASF_Equations arg);
ATbool ASF_isEquationsAbsent(ASF_Equations arg);
ATbool ASF_isEquationsPresent(ASF_Equations arg);
ATbool ASF_hasEquationsWsAfterEquations(ASF_Equations arg);
ASF_Layout ASF_getEquationsWsAfterEquations(ASF_Equations arg);
ASF_Equations ASF_setEquationsWsAfterEquations(ASF_Equations arg, ASF_Layout wsAfterEquations);
ATbool ASF_hasEquationsList(ASF_Equations arg);
ASF_CondEquationList ASF_getEquationsList(ASF_Equations arg);
ASF_Equations ASF_setEquationsList(ASF_Equations arg, ASF_CondEquationList list);

/*}}}  */
/*{{{  ASF_CondEquationList accessors */

ATbool ASF_isValidCondEquationList(ASF_CondEquationList arg);
ATbool ASF_isCondEquationListEmpty(ASF_CondEquationList arg);
ATbool ASF_isCondEquationListSingle(ASF_CondEquationList arg);
ATbool ASF_isCondEquationListMany(ASF_CondEquationList arg);
ATbool ASF_hasCondEquationListHead(ASF_CondEquationList arg);
ASF_CondEquation ASF_getCondEquationListHead(ASF_CondEquationList arg);
ASF_CondEquationList ASF_setCondEquationListHead(ASF_CondEquationList arg, ASF_CondEquation head);
ATbool ASF_hasCondEquationListWsAfterFirst(ASF_CondEquationList arg);
ASF_Layout ASF_getCondEquationListWsAfterFirst(ASF_CondEquationList arg);
ASF_CondEquationList ASF_setCondEquationListWsAfterFirst(ASF_CondEquationList arg, ASF_Layout wsAfterFirst);
ATbool ASF_hasCondEquationListTail(ASF_CondEquationList arg);
ASF_CondEquationList ASF_getCondEquationListTail(ASF_CondEquationList arg);
ASF_CondEquationList ASF_setCondEquationListTail(ASF_CondEquationList arg, ASF_CondEquationList tail);

/*}}}  */
/*{{{  ASF_CondEquation accessors */

ATbool ASF_isValidCondEquation(ASF_CondEquation arg);
ATbool ASF_isCondEquationSimple(ASF_CondEquation arg);
ATbool ASF_isCondEquationImplies(ASF_CondEquation arg);
ATbool ASF_isCondEquationWhen(ASF_CondEquation arg);
ATbool ASF_hasCondEquationTag(ASF_CondEquation arg);
ASF_Tag ASF_getCondEquationTag(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationTag(ASF_CondEquation arg, ASF_Tag Tag);
ATbool ASF_hasCondEquationWsAfterTag(ASF_CondEquation arg);
ASF_Layout ASF_getCondEquationWsAfterTag(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationWsAfterTag(ASF_CondEquation arg, ASF_Layout wsAfterTag);
ATbool ASF_hasCondEquationEquation(ASF_CondEquation arg);
ASF_Equation ASF_getCondEquationEquation(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationEquation(ASF_CondEquation arg, ASF_Equation Equation);
ATbool ASF_hasCondEquationConditions(ASF_CondEquation arg);
ASF_Conditions ASF_getCondEquationConditions(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationConditions(ASF_CondEquation arg, ASF_Conditions Conditions);
ATbool ASF_hasCondEquationWsAfterConditions(ASF_CondEquation arg);
ASF_Layout ASF_getCondEquationWsAfterConditions(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationWsAfterConditions(ASF_CondEquation arg, ASF_Layout wsAfterConditions);
ATbool ASF_hasCondEquationImplies(ASF_CondEquation arg);
ASF_Implies ASF_getCondEquationImplies(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationImplies(ASF_CondEquation arg, ASF_Implies Implies);
ATbool ASF_hasCondEquationWsAfterImplies(ASF_CondEquation arg);
ASF_Layout ASF_getCondEquationWsAfterImplies(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationWsAfterImplies(ASF_CondEquation arg, ASF_Layout wsAfterImplies);
ATbool ASF_hasCondEquationWsAfterEquation(ASF_CondEquation arg);
ASF_Layout ASF_getCondEquationWsAfterEquation(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationWsAfterEquation(ASF_CondEquation arg, ASF_Layout wsAfterEquation);
ATbool ASF_hasCondEquationWsAfterWhen(ASF_CondEquation arg);
ASF_Layout ASF_getCondEquationWsAfterWhen(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationWsAfterWhen(ASF_CondEquation arg, ASF_Layout wsAfterWhen);

/*}}}  */
/*{{{  ASF_Tag accessors */

ATbool ASF_isValidTag(ASF_Tag arg);
ATbool ASF_isTagEmpty(ASF_Tag arg);
ATbool ASF_isTagNotEmpty(ASF_Tag arg);
ATbool ASF_hasTagWsAfterBracketOpen(ASF_Tag arg);
ASF_Layout ASF_getTagWsAfterBracketOpen(ASF_Tag arg);
ASF_Tag ASF_setTagWsAfterBracketOpen(ASF_Tag arg, ASF_Layout wsAfterBracketOpen);
ATbool ASF_hasTagTagId(ASF_Tag arg);
ASF_TagId ASF_getTagTagId(ASF_Tag arg);
ASF_Tag ASF_setTagTagId(ASF_Tag arg, ASF_TagId TagId);
ATbool ASF_hasTagWsAfterTagId(ASF_Tag arg);
ASF_Layout ASF_getTagWsAfterTagId(ASF_Tag arg);
ASF_Tag ASF_setTagWsAfterTagId(ASF_Tag arg, ASF_Layout wsAfterTagId);

/*}}}  */
/*{{{  ASF_Tree accessors */

ATbool ASF_isValidTree(ASF_Tree arg);
ATbool ASF_isTreeLexicalConstructor(ASF_Tree arg);
ATbool ASF_hasTreeSymbolName(ASF_Tree arg);
ASF_Symbol ASF_getTreeSymbolName(ASF_Tree arg);
ASF_Tree ASF_setTreeSymbolName(ASF_Tree arg, ASF_Symbol symbolName);
ATbool ASF_hasTreeSymbol(ASF_Tree arg);
ASF_Symbol ASF_getTreeSymbol(ASF_Tree arg);
ASF_Tree ASF_setTreeSymbol(ASF_Tree arg, ASF_Symbol symbol);
ATbool ASF_hasTreeName(ASF_Tree arg);
ASF_Tree ASF_getTreeName(ASF_Tree arg);
ASF_Tree ASF_setTreeName(ASF_Tree arg, ASF_Tree name);
ATbool ASF_hasTreeWsAfterName(ASF_Tree arg);
ASF_Layout ASF_getTreeWsAfterName(ASF_Tree arg);
ASF_Tree ASF_setTreeWsAfterName(ASF_Tree arg, ASF_Layout wsAfterName);
ATbool ASF_hasTreeWsAfterParenOpen(ASF_Tree arg);
ASF_Layout ASF_getTreeWsAfterParenOpen(ASF_Tree arg);
ASF_Tree ASF_setTreeWsAfterParenOpen(ASF_Tree arg, ASF_Layout wsAfterParenOpen);
ATbool ASF_hasTreeList(ASF_Tree arg);
ASF_CHARList ASF_getTreeList(ASF_Tree arg);
ASF_Tree ASF_setTreeList(ASF_Tree arg, ASF_CHARList list);
ATbool ASF_hasTreeWsAfterList(ASF_Tree arg);
ASF_Layout ASF_getTreeWsAfterList(ASF_Tree arg);
ASF_Tree ASF_setTreeWsAfterList(ASF_Tree arg, ASF_Layout wsAfterList);

/*}}}  */
/*{{{  ASF_CHARList accessors */

ATbool ASF_isValidCHARList(ASF_CHARList arg);
ATbool ASF_isCHARListEmpty(ASF_CHARList arg);
ATbool ASF_isCHARListSingle(ASF_CHARList arg);
ATbool ASF_isCHARListMany(ASF_CHARList arg);
ATbool ASF_hasCHARListHead(ASF_CHARList arg);
ASF_CHAR ASF_getCHARListHead(ASF_CHARList arg);
ASF_CHARList ASF_setCHARListHead(ASF_CHARList arg, ASF_CHAR head);
ATbool ASF_hasCHARListWsAfterFirst(ASF_CHARList arg);
ASF_Layout ASF_getCHARListWsAfterFirst(ASF_CHARList arg);
ASF_CHARList ASF_setCHARListWsAfterFirst(ASF_CHARList arg, ASF_Layout wsAfterFirst);
ATbool ASF_hasCHARListTail(ASF_CHARList arg);
ASF_CHARList ASF_getCHARListTail(ASF_CHARList arg);
ASF_CHARList ASF_setCHARListTail(ASF_CHARList arg, ASF_CHARList tail);

/*}}}  */
/*{{{  ASF_Equation accessors */

ATbool ASF_isValidEquation(ASF_Equation arg);
ATbool ASF_isEquationDefault(ASF_Equation arg);
ATbool ASF_hasEquationLhsSymbol(ASF_Equation arg);
ASF_Symbol ASF_getEquationLhsSymbol(ASF_Equation arg);
ASF_Equation ASF_setEquationLhsSymbol(ASF_Equation arg, ASF_Symbol lhsSymbol);
ATbool ASF_hasEquationRhsSymbol(ASF_Equation arg);
ASF_Symbol ASF_getEquationRhsSymbol(ASF_Equation arg);
ASF_Equation ASF_setEquationRhsSymbol(ASF_Equation arg, ASF_Symbol rhsSymbol);
ATbool ASF_hasEquationLhs(ASF_Equation arg);
ASF_Tree ASF_getEquationLhs(ASF_Equation arg);
ASF_Equation ASF_setEquationLhs(ASF_Equation arg, ASF_Tree lhs);
ATbool ASF_hasEquationWsAfterLhs(ASF_Equation arg);
ASF_Layout ASF_getEquationWsAfterLhs(ASF_Equation arg);
ASF_Equation ASF_setEquationWsAfterLhs(ASF_Equation arg, ASF_Layout wsAfterLhs);
ATbool ASF_hasEquationWsAfterEquals(ASF_Equation arg);
ASF_Layout ASF_getEquationWsAfterEquals(ASF_Equation arg);
ASF_Equation ASF_setEquationWsAfterEquals(ASF_Equation arg, ASF_Layout wsAfterEquals);
ATbool ASF_hasEquationRhs(ASF_Equation arg);
ASF_Tree ASF_getEquationRhs(ASF_Equation arg);
ASF_Equation ASF_setEquationRhs(ASF_Equation arg, ASF_Tree rhs);

/*}}}  */
/*{{{  ASF_Condition accessors */

ATbool ASF_isValidCondition(ASF_Condition arg);
ATbool ASF_isConditionPositive(ASF_Condition arg);
ATbool ASF_isConditionNegative(ASF_Condition arg);
ATbool ASF_hasConditionLhsSymbol(ASF_Condition arg);
ASF_Symbol ASF_getConditionLhsSymbol(ASF_Condition arg);
ASF_Condition ASF_setConditionLhsSymbol(ASF_Condition arg, ASF_Symbol lhsSymbol);
ATbool ASF_hasConditionRhsSymbol(ASF_Condition arg);
ASF_Symbol ASF_getConditionRhsSymbol(ASF_Condition arg);
ASF_Condition ASF_setConditionRhsSymbol(ASF_Condition arg, ASF_Symbol rhsSymbol);
ATbool ASF_hasConditionLhs(ASF_Condition arg);
ASF_Tree ASF_getConditionLhs(ASF_Condition arg);
ASF_Condition ASF_setConditionLhs(ASF_Condition arg, ASF_Tree lhs);
ATbool ASF_hasConditionWsAfterLhs(ASF_Condition arg);
ASF_Layout ASF_getConditionWsAfterLhs(ASF_Condition arg);
ASF_Condition ASF_setConditionWsAfterLhs(ASF_Condition arg, ASF_Layout wsAfterLhs);
ATbool ASF_hasConditionWsAfterEquals(ASF_Condition arg);
ASF_Layout ASF_getConditionWsAfterEquals(ASF_Condition arg);
ASF_Condition ASF_setConditionWsAfterEquals(ASF_Condition arg, ASF_Layout wsAfterEquals);
ATbool ASF_hasConditionRhs(ASF_Condition arg);
ASF_Tree ASF_getConditionRhs(ASF_Condition arg);
ASF_Condition ASF_setConditionRhs(ASF_Condition arg, ASF_Tree rhs);
ATbool ASF_hasConditionWsAfterUnequal(ASF_Condition arg);
ASF_Layout ASF_getConditionWsAfterUnequal(ASF_Condition arg);
ASF_Condition ASF_setConditionWsAfterUnequal(ASF_Condition arg, ASF_Layout wsAfterUnequal);

/*}}}  */
/*{{{  ASF_CHAR accessors */

ATbool ASF_isValidCHAR(ASF_CHAR arg);
ATbool ASF_isCHARDefault(ASF_CHAR arg);
ATbool ASF_hasCHARLex(ASF_CHAR arg);
ASF_Lexical ASF_getCHARLex(ASF_CHAR arg);
ASF_CHAR ASF_setCHARLex(ASF_CHAR arg, ASF_Lexical lex);

/*}}}  */
/*{{{  sort visitors */

ASF_Implies ASF_visitImplies(ASF_Implies arg, ASF_Lexical (*acceptLex)(ASF_Lexical));
ASF_TagId ASF_visitTagId(ASF_TagId arg, ASF_Lexical (*acceptLex)(ASF_Lexical));
ASF_Conditions ASF_visitConditions(ASF_Conditions arg, ASF_ConditionList (*acceptList)(ASF_ConditionList));
ASF_ConditionList ASF_visitConditionList(ASF_ConditionList arg, ASF_Condition (*acceptHead)(ASF_Condition), ASF_Layout (*acceptWsAfterFirst)(ASF_Layout), ASF_Separator (*acceptSep)(ASF_Separator), ASF_Layout (*acceptWsAfterSep)(ASF_Layout));
ASF_Equations ASF_visitEquations(ASF_Equations arg, ASF_Layout (*acceptWsAfterEquations)(ASF_Layout), ASF_CondEquationList (*acceptList)(ASF_CondEquationList));
ASF_CondEquationList ASF_visitCondEquationList(ASF_CondEquationList arg, ASF_CondEquation (*acceptHead)(ASF_CondEquation), ASF_Layout (*acceptWsAfterFirst)(ASF_Layout));
ASF_CondEquation ASF_visitCondEquation(ASF_CondEquation arg, ASF_Tag (*acceptTag)(ASF_Tag), ASF_Layout (*acceptWsAfterTag)(ASF_Layout), ASF_Equation (*acceptEquation)(ASF_Equation), ASF_Conditions (*acceptConditions)(ASF_Conditions), ASF_Layout (*acceptWsAfterConditions)(ASF_Layout), ASF_Implies (*acceptImplies)(ASF_Implies), ASF_Layout (*acceptWsAfterImplies)(ASF_Layout), ASF_Layout (*acceptWsAfterEquation)(ASF_Layout), ASF_Layout (*acceptWsAfterWhen)(ASF_Layout));
ASF_Tag ASF_visitTag(ASF_Tag arg, ASF_Layout (*acceptWsAfterBracketOpen)(ASF_Layout), ASF_TagId (*acceptTagId)(ASF_TagId), ASF_Layout (*acceptWsAfterTagId)(ASF_Layout));
ASF_Tree ASF_visitTree(ASF_Tree arg, ASF_Symbol (*acceptSymbolName)(ASF_Symbol), ASF_Symbol (*acceptSymbol)(ASF_Symbol), ASF_Layout (*acceptWsAfterName)(ASF_Layout), ASF_Layout (*acceptWsAfterParenOpen)(ASF_Layout), ASF_CHARList (*acceptList)(ASF_CHARList), ASF_Layout (*acceptWsAfterList)(ASF_Layout));
ASF_CHARList ASF_visitCHARList(ASF_CHARList arg, ASF_CHAR (*acceptHead)(ASF_CHAR), ASF_Layout (*acceptWsAfterFirst)(ASF_Layout));
ASF_Equation ASF_visitEquation(ASF_Equation arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_Layout (*acceptWsAfterLhs)(ASF_Layout), ASF_Layout (*acceptWsAfterEquals)(ASF_Layout), ASF_Tree (*acceptRhs)(ASF_Tree));
ASF_Condition ASF_visitCondition(ASF_Condition arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_Layout (*acceptWsAfterLhs)(ASF_Layout), ASF_Layout (*acceptWsAfterEquals)(ASF_Layout), ASF_Tree (*acceptRhs)(ASF_Tree), ASF_Layout (*acceptWsAfterUnequal)(ASF_Layout));
ASF_CHAR ASF_visitCHAR(ASF_CHAR arg, ASF_Lexical (*acceptLex)(ASF_Lexical));

/*}}}  */

#endif /* _ASF_H */
