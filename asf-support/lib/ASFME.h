#ifndef _ASFME_H
#define _ASFME_H

/*{{{  includes */

#include <aterm1.h>
#include "ASFME_dict.h"

/*}}}  */

/*{{{  prologue */

typedef struct _ASF_CHARLIST *ASF_CHARLIST;

ATbool ASF_isValidCHARLIST(ASF_CHARLIST arg);
ATbool ASF_isCHARLISTString(ASF_CHARLIST arg);
char*  ASF_getCHARLISTString(ASF_CHARLIST arg);
ASF_CHARLIST  ASF_setCHARLISTString(ASF_CHARLIST arg, char *str);
ATerm  ASF_CHARLISTToTerm(ASF_CHARLIST arg);
ASF_CHARLIST ASF_CHARLISTFromTerm(ATerm trm);
ASF_CHARLIST ASF_makeCHARLISTString(char *str);
typedef ATerm ASF_Symbol;

/*}}}  */
/*{{{  typedefs */

typedef struct _ASF_Production *ASF_Production;
typedef struct _ASF_CHAR *ASF_CHAR;
typedef struct _ASF_ASFCondition *ASF_ASFCondition;
typedef struct _ASF_ASFConditions *ASF_ASFConditions;
typedef struct _ASF_ASFConditionList *ASF_ASFConditionList;
typedef struct _ASF_Tree *ASF_Tree;
typedef struct _ASF_TreeAmbs *ASF_TreeAmbs;
typedef struct _ASF_CHARList *ASF_CHARList;
typedef struct _ASF_ASFImplies *ASF_ASFImplies;
typedef struct _ASF_ASFConditionalEquation *ASF_ASFConditionalEquation;
typedef struct _ASF_ASFEquation *ASF_ASFEquation;
typedef struct _ASF_ASFModule *ASF_ASFModule;
typedef struct _ASF_ASFSectionList *ASF_ASFSectionList;
typedef struct _ASF_ASFSection *ASF_ASFSection;
typedef struct _ASF_ASFConditionalEquationList *ASF_ASFConditionalEquationList;
typedef struct _ASF_ASFTestEquationTestList *ASF_ASFTestEquationTestList;
typedef struct _ASF_ASFTagId *ASF_ASFTagId;
typedef struct _ASF_ASFTag *ASF_ASFTag;
typedef struct _ASF_ASFTestEquation *ASF_ASFTestEquation;
typedef struct _ASF_Start *ASF_Start;
typedef struct _ASF_OptLayout *ASF_OptLayout;

/*}}}  */

void ASF_initASFMEApi(void);

/*{{{  term conversion functions */

#define ASF_makeProductionFromTerm(t) (ASF_ProductionFromTerm(t))
ASF_Production ASF_ProductionFromTerm(ATerm t);
#define ASF_makeTermFromProduction(t) (ASF_ProductionToTerm(t))
ATerm ASF_ProductionToTerm(ASF_Production arg);
#define ASF_makeCHARFromTerm(t) (ASF_CHARFromTerm(t))
ASF_CHAR ASF_CHARFromTerm(ATerm t);
#define ASF_makeTermFromCHAR(t) (ASF_CHARToTerm(t))
ATerm ASF_CHARToTerm(ASF_CHAR arg);
#define ASF_makeASFConditionFromTerm(t) (ASF_ASFConditionFromTerm(t))
ASF_ASFCondition ASF_ASFConditionFromTerm(ATerm t);
#define ASF_makeTermFromASFCondition(t) (ASF_ASFConditionToTerm(t))
ATerm ASF_ASFConditionToTerm(ASF_ASFCondition arg);
#define ASF_makeASFConditionsFromTerm(t) (ASF_ASFConditionsFromTerm(t))
ASF_ASFConditions ASF_ASFConditionsFromTerm(ATerm t);
#define ASF_makeTermFromASFConditions(t) (ASF_ASFConditionsToTerm(t))
ATerm ASF_ASFConditionsToTerm(ASF_ASFConditions arg);
#define ASF_makeASFConditionListFromTerm(t) (ASF_ASFConditionListFromTerm(t))
ASF_ASFConditionList ASF_ASFConditionListFromTerm(ATerm t);
#define ASF_makeTermFromASFConditionList(t) (ASF_ASFConditionListToTerm(t))
ATerm ASF_ASFConditionListToTerm(ASF_ASFConditionList arg);
#define ASF_makeTreeFromTerm(t) (ASF_TreeFromTerm(t))
ASF_Tree ASF_TreeFromTerm(ATerm t);
#define ASF_makeTermFromTree(t) (ASF_TreeToTerm(t))
ATerm ASF_TreeToTerm(ASF_Tree arg);
#define ASF_makeTreeAmbsFromTerm(t) (ASF_TreeAmbsFromTerm(t))
ASF_TreeAmbs ASF_TreeAmbsFromTerm(ATerm t);
#define ASF_makeTermFromTreeAmbs(t) (ASF_TreeAmbsToTerm(t))
ATerm ASF_TreeAmbsToTerm(ASF_TreeAmbs arg);
#define ASF_makeCHARListFromTerm(t) (ASF_CHARListFromTerm(t))
ASF_CHARList ASF_CHARListFromTerm(ATerm t);
#define ASF_makeTermFromCHARList(t) (ASF_CHARListToTerm(t))
ATerm ASF_CHARListToTerm(ASF_CHARList arg);
#define ASF_makeASFImpliesFromTerm(t) (ASF_ASFImpliesFromTerm(t))
ASF_ASFImplies ASF_ASFImpliesFromTerm(ATerm t);
#define ASF_makeTermFromASFImplies(t) (ASF_ASFImpliesToTerm(t))
ATerm ASF_ASFImpliesToTerm(ASF_ASFImplies arg);
#define ASF_makeASFConditionalEquationFromTerm(t) (ASF_ASFConditionalEquationFromTerm(t))
ASF_ASFConditionalEquation ASF_ASFConditionalEquationFromTerm(ATerm t);
#define ASF_makeTermFromASFConditionalEquation(t) (ASF_ASFConditionalEquationToTerm(t))
ATerm ASF_ASFConditionalEquationToTerm(ASF_ASFConditionalEquation arg);
#define ASF_makeASFEquationFromTerm(t) (ASF_ASFEquationFromTerm(t))
ASF_ASFEquation ASF_ASFEquationFromTerm(ATerm t);
#define ASF_makeTermFromASFEquation(t) (ASF_ASFEquationToTerm(t))
ATerm ASF_ASFEquationToTerm(ASF_ASFEquation arg);
#define ASF_makeASFModuleFromTerm(t) (ASF_ASFModuleFromTerm(t))
ASF_ASFModule ASF_ASFModuleFromTerm(ATerm t);
#define ASF_makeTermFromASFModule(t) (ASF_ASFModuleToTerm(t))
ATerm ASF_ASFModuleToTerm(ASF_ASFModule arg);
#define ASF_makeASFSectionListFromTerm(t) (ASF_ASFSectionListFromTerm(t))
ASF_ASFSectionList ASF_ASFSectionListFromTerm(ATerm t);
#define ASF_makeTermFromASFSectionList(t) (ASF_ASFSectionListToTerm(t))
ATerm ASF_ASFSectionListToTerm(ASF_ASFSectionList arg);
#define ASF_makeASFSectionFromTerm(t) (ASF_ASFSectionFromTerm(t))
ASF_ASFSection ASF_ASFSectionFromTerm(ATerm t);
#define ASF_makeTermFromASFSection(t) (ASF_ASFSectionToTerm(t))
ATerm ASF_ASFSectionToTerm(ASF_ASFSection arg);
#define ASF_makeASFConditionalEquationListFromTerm(t) (ASF_ASFConditionalEquationListFromTerm(t))
ASF_ASFConditionalEquationList ASF_ASFConditionalEquationListFromTerm(ATerm t);
#define ASF_makeTermFromASFConditionalEquationList(t) (ASF_ASFConditionalEquationListToTerm(t))
ATerm ASF_ASFConditionalEquationListToTerm(ASF_ASFConditionalEquationList arg);
#define ASF_makeASFTestEquationTestListFromTerm(t) (ASF_ASFTestEquationTestListFromTerm(t))
ASF_ASFTestEquationTestList ASF_ASFTestEquationTestListFromTerm(ATerm t);
#define ASF_makeTermFromASFTestEquationTestList(t) (ASF_ASFTestEquationTestListToTerm(t))
ATerm ASF_ASFTestEquationTestListToTerm(ASF_ASFTestEquationTestList arg);
#define ASF_makeASFTagIdFromTerm(t) (ASF_ASFTagIdFromTerm(t))
ASF_ASFTagId ASF_ASFTagIdFromTerm(ATerm t);
#define ASF_makeTermFromASFTagId(t) (ASF_ASFTagIdToTerm(t))
ATerm ASF_ASFTagIdToTerm(ASF_ASFTagId arg);
#define ASF_makeASFTagFromTerm(t) (ASF_ASFTagFromTerm(t))
ASF_ASFTag ASF_ASFTagFromTerm(ATerm t);
#define ASF_makeTermFromASFTag(t) (ASF_ASFTagToTerm(t))
ATerm ASF_ASFTagToTerm(ASF_ASFTag arg);
#define ASF_makeASFTestEquationFromTerm(t) (ASF_ASFTestEquationFromTerm(t))
ASF_ASFTestEquation ASF_ASFTestEquationFromTerm(ATerm t);
#define ASF_makeTermFromASFTestEquation(t) (ASF_ASFTestEquationToTerm(t))
ATerm ASF_ASFTestEquationToTerm(ASF_ASFTestEquation arg);
#define ASF_makeStartFromTerm(t) (ASF_StartFromTerm(t))
ASF_Start ASF_StartFromTerm(ATerm t);
#define ASF_makeTermFromStart(t) (ASF_StartToTerm(t))
ATerm ASF_StartToTerm(ASF_Start arg);
#define ASF_makeOptLayoutFromTerm(t) (ASF_OptLayoutFromTerm(t))
ASF_OptLayout ASF_OptLayoutFromTerm(ATerm t);
#define ASF_makeTermFromOptLayout(t) (ASF_OptLayoutToTerm(t))
ATerm ASF_OptLayoutToTerm(ASF_OptLayout arg);

/*}}}  */
/*{{{  constructors */

ASF_Production ASF_makeProductionLexicalConstructor(char * formalName, ASF_Symbol symbol);
ASF_CHAR ASF_makeCHARDefault(ASF_CHARLIST chars);
ASF_ASFCondition ASF_makeASFConditionPositive(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquals, ASF_Tree rhs);
ASF_ASFCondition ASF_makeASFConditionNegative(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterUnequal, ASF_Tree rhs);
ASF_ASFCondition ASF_makeASFConditionEquality(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquality, ASF_Tree rhs);
ASF_ASFCondition ASF_makeASFConditionMatch(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterMatch, ASF_Tree rhs);
ASF_ASFCondition ASF_makeASFConditionNoMatch(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterMatch, ASF_Tree rhs);
ASF_ASFConditions ASF_makeASFConditionsDefault(ASF_ASFConditionList list);
ASF_ASFConditionList ASF_makeASFConditionListSingle(ASF_ASFCondition head);
ASF_ASFConditionList ASF_makeASFConditionListMany(ASF_ASFCondition head, ASF_OptLayout wsAfterFirst, char * sep, ASF_OptLayout wsAfterSep, ASF_ASFConditionList tail);
ASF_Tree ASF_makeTreeAmbiguityConstructor(ASF_Symbol amb, ASF_Symbol symbol, ASF_OptLayout wsAfterAmb, ASF_OptLayout wsAfterParenOpen, ASF_Symbol listSymbol, ASF_TreeAmbs ambs, ASF_OptLayout wsAfterAmbs);
ASF_Tree ASF_makeTreeLexicalConstructor(char * formalName, ASF_Symbol symbol, ASF_Tree name, ASF_OptLayout wsAfterName, ASF_OptLayout wsAfterParenOpen, ASF_CHARList list, ASF_OptLayout wsAfterList);
ASF_TreeAmbs ASF_makeTreeAmbsEmpty();
ASF_TreeAmbs ASF_makeTreeAmbsSingle(ASF_Tree head);
ASF_TreeAmbs ASF_makeTreeAmbsMany(ASF_Tree head, ASF_OptLayout wsAfterFirst, char * sep, ASF_OptLayout wsAfterSep, ASF_TreeAmbs tail);
ASF_CHARList ASF_makeCHARListEmpty();
ASF_CHARList ASF_makeCHARListSingle(ASF_CHAR head);
ASF_CHARList ASF_makeCHARListMany(ASF_CHAR head, ASF_OptLayout wsAfterFirst, ASF_CHARList tail);
ASF_ASFImplies ASF_makeASFImpliesDefault(ASF_CHARLIST chars);
ASF_ASFConditionalEquation ASF_makeASFConditionalEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation);
ASF_ASFConditionalEquation ASF_makeASFConditionalEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFEquation ASFEquation);
ASF_ASFConditionalEquation ASF_makeASFConditionalEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation, ASF_OptLayout wsAfterASFEquation, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions);
ASF_ASFEquation ASF_makeASFEquationDefault(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquals, ASF_Tree rhs);
ASF_ASFModule ASF_makeASFModuleDefault(ASF_ASFSectionList list);
ASF_ASFSectionList ASF_makeASFSectionListEmpty();
ASF_ASFSectionList ASF_makeASFSectionListSingle(ASF_ASFSection head);
ASF_ASFSectionList ASF_makeASFSectionListMany(ASF_ASFSection head, ASF_OptLayout wsAfterFirst, ASF_ASFSectionList tail);
ASF_ASFSection ASF_makeASFSectionEquations(ASF_OptLayout wsAfterEquations, ASF_ASFConditionalEquationList list);
ASF_ASFSection ASF_makeASFSectionTests(ASF_OptLayout wsAfterTests, ASF_ASFTestEquationTestList testList);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListEmpty();
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListSingle(ASF_ASFConditionalEquation head);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListMany(ASF_ASFConditionalEquation head, ASF_OptLayout wsAfterFirst, ASF_ASFConditionalEquationList tail);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestListEmpty();
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestListSingle(ASF_ASFTestEquation head);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestListMany(ASF_ASFTestEquation head, ASF_OptLayout wsAfterFirst, ASF_ASFTestEquationTestList tail);
ASF_ASFTagId ASF_makeASFTagIdOneChar(ASF_CHARLIST chars);
ASF_ASFTagId ASF_makeASFTagIdManyChars(ASF_CHARLIST chars);
ASF_ASFTag ASF_makeASFTagEmpty(ASF_OptLayout wsAfterBracketOpen);
ASF_ASFTag ASF_makeASFTagNotEmpty(ASF_OptLayout wsAfterBracketOpen, ASF_ASFTagId ASFTagId, ASF_OptLayout wsAfterASFTagId);
ASF_ASFTestEquation ASF_makeASFTestEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFCondition ASFCondition);
ASF_ASFTestEquation ASF_makeASFTestEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFCondition ASFCondition);
ASF_ASFTestEquation ASF_makeASFTestEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFCondition ASFCondition, ASF_OptLayout wsAfterASFCondition, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions);
ASF_Start ASF_makeStartASFTestEquation(ASF_OptLayout wsBefore, ASF_ASFTestEquation topASFTestEquation, ASF_OptLayout wsAfter, int ambCnt);
ASF_Start ASF_makeStartASFTag(ASF_OptLayout wsBefore, ASF_ASFTag topASFTag, ASF_OptLayout wsAfter, int ambCnt);
ASF_Start ASF_makeStartASFTagId(ASF_OptLayout wsBefore, ASF_ASFTagId topASFTagId, ASF_OptLayout wsAfter, int ambCnt);
ASF_Start ASF_makeStartASFSection(ASF_OptLayout wsBefore, ASF_ASFSection topASFSection, ASF_OptLayout wsAfter, int ambCnt);
ASF_Start ASF_makeStartASFModule(ASF_OptLayout wsBefore, ASF_ASFModule topASFModule, ASF_OptLayout wsAfter, int ambCnt);
ASF_Start ASF_makeStartASFConditionalEquation(ASF_OptLayout wsBefore, ASF_ASFConditionalEquation topASFConditionalEquation, ASF_OptLayout wsAfter, int ambCnt);
ASF_Start ASF_makeStartASFEquation(ASF_OptLayout wsBefore, ASF_ASFEquation topASFEquation, ASF_OptLayout wsAfter, int ambCnt);
ASF_Start ASF_makeStartASFImplies(ASF_OptLayout wsBefore, ASF_ASFImplies topASFImplies, ASF_OptLayout wsAfter, int ambCnt);
ASF_Start ASF_makeStartTree(ASF_OptLayout wsBefore, ASF_Tree topTree, ASF_OptLayout wsAfter, int ambCnt);
ASF_Start ASF_makeStartASFConditions(ASF_OptLayout wsBefore, ASF_ASFConditions topASFConditions, ASF_OptLayout wsAfter, int ambCnt);
ASF_Start ASF_makeStartASFCondition(ASF_OptLayout wsBefore, ASF_ASFCondition topASFCondition, ASF_OptLayout wsAfter, int ambCnt);
ASF_OptLayout ASF_makeOptLayoutAbsent();
ASF_OptLayout ASF_makeOptLayoutPresent(ASF_CHARLIST chars);

/*}}}  */
/*{{{  equality functions */

ATbool ASF_isEqualProduction(ASF_Production arg0, ASF_Production arg1);
ATbool ASF_isEqualCHAR(ASF_CHAR arg0, ASF_CHAR arg1);
ATbool ASF_isEqualASFCondition(ASF_ASFCondition arg0, ASF_ASFCondition arg1);
ATbool ASF_isEqualASFConditions(ASF_ASFConditions arg0, ASF_ASFConditions arg1);
ATbool ASF_isEqualASFConditionList(ASF_ASFConditionList arg0, ASF_ASFConditionList arg1);
ATbool ASF_isEqualTree(ASF_Tree arg0, ASF_Tree arg1);
ATbool ASF_isEqualTreeAmbs(ASF_TreeAmbs arg0, ASF_TreeAmbs arg1);
ATbool ASF_isEqualCHARList(ASF_CHARList arg0, ASF_CHARList arg1);
ATbool ASF_isEqualASFImplies(ASF_ASFImplies arg0, ASF_ASFImplies arg1);
ATbool ASF_isEqualASFConditionalEquation(ASF_ASFConditionalEquation arg0, ASF_ASFConditionalEquation arg1);
ATbool ASF_isEqualASFEquation(ASF_ASFEquation arg0, ASF_ASFEquation arg1);
ATbool ASF_isEqualASFModule(ASF_ASFModule arg0, ASF_ASFModule arg1);
ATbool ASF_isEqualASFSectionList(ASF_ASFSectionList arg0, ASF_ASFSectionList arg1);
ATbool ASF_isEqualASFSection(ASF_ASFSection arg0, ASF_ASFSection arg1);
ATbool ASF_isEqualASFConditionalEquationList(ASF_ASFConditionalEquationList arg0, ASF_ASFConditionalEquationList arg1);
ATbool ASF_isEqualASFTestEquationTestList(ASF_ASFTestEquationTestList arg0, ASF_ASFTestEquationTestList arg1);
ATbool ASF_isEqualASFTagId(ASF_ASFTagId arg0, ASF_ASFTagId arg1);
ATbool ASF_isEqualASFTag(ASF_ASFTag arg0, ASF_ASFTag arg1);
ATbool ASF_isEqualASFTestEquation(ASF_ASFTestEquation arg0, ASF_ASFTestEquation arg1);
ATbool ASF_isEqualStart(ASF_Start arg0, ASF_Start arg1);
ATbool ASF_isEqualOptLayout(ASF_OptLayout arg0, ASF_OptLayout arg1);

/*}}}  */
/*{{{  ASF_Production accessors */

ATbool ASF_isValidProduction(ASF_Production arg);
inline ATbool ASF_isProductionLexicalConstructor(ASF_Production arg);
ATbool ASF_hasProductionFormalName(ASF_Production arg);
char * ASF_getProductionFormalName(ASF_Production arg);
ASF_Production ASF_setProductionFormalName(ASF_Production arg, char * formalName);
ATbool ASF_hasProductionSymbol(ASF_Production arg);
ASF_Symbol ASF_getProductionSymbol(ASF_Production arg);
ASF_Production ASF_setProductionSymbol(ASF_Production arg, ASF_Symbol symbol);

/*}}}  */
/*{{{  ASF_CHAR accessors */

ATbool ASF_isValidCHAR(ASF_CHAR arg);
inline ATbool ASF_isCHARDefault(ASF_CHAR arg);
ATbool ASF_hasCHARChars(ASF_CHAR arg);
ASF_CHARLIST ASF_getCHARChars(ASF_CHAR arg);
ASF_CHAR ASF_setCHARChars(ASF_CHAR arg, ASF_CHARLIST chars);

/*}}}  */
/*{{{  ASF_ASFCondition accessors */

ATbool ASF_isValidASFCondition(ASF_ASFCondition arg);
inline ATbool ASF_isASFConditionPositive(ASF_ASFCondition arg);
inline ATbool ASF_isASFConditionNegative(ASF_ASFCondition arg);
inline ATbool ASF_isASFConditionEquality(ASF_ASFCondition arg);
inline ATbool ASF_isASFConditionMatch(ASF_ASFCondition arg);
inline ATbool ASF_isASFConditionNoMatch(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionLhsSymbol(ASF_ASFCondition arg);
ASF_Symbol ASF_getASFConditionLhsSymbol(ASF_ASFCondition arg);
ASF_ASFCondition ASF_setASFConditionLhsSymbol(ASF_ASFCondition arg, ASF_Symbol lhsSymbol);
ATbool ASF_hasASFConditionRhsSymbol(ASF_ASFCondition arg);
ASF_Symbol ASF_getASFConditionRhsSymbol(ASF_ASFCondition arg);
ASF_ASFCondition ASF_setASFConditionRhsSymbol(ASF_ASFCondition arg, ASF_Symbol rhsSymbol);
ATbool ASF_hasASFConditionLhs(ASF_ASFCondition arg);
ASF_Tree ASF_getASFConditionLhs(ASF_ASFCondition arg);
ASF_ASFCondition ASF_setASFConditionLhs(ASF_ASFCondition arg, ASF_Tree lhs);
ATbool ASF_hasASFConditionWsAfterLhs(ASF_ASFCondition arg);
ASF_OptLayout ASF_getASFConditionWsAfterLhs(ASF_ASFCondition arg);
ASF_ASFCondition ASF_setASFConditionWsAfterLhs(ASF_ASFCondition arg, ASF_OptLayout wsAfterLhs);
ATbool ASF_hasASFConditionWsAfterEquals(ASF_ASFCondition arg);
ASF_OptLayout ASF_getASFConditionWsAfterEquals(ASF_ASFCondition arg);
ASF_ASFCondition ASF_setASFConditionWsAfterEquals(ASF_ASFCondition arg, ASF_OptLayout wsAfterEquals);
ATbool ASF_hasASFConditionRhs(ASF_ASFCondition arg);
ASF_Tree ASF_getASFConditionRhs(ASF_ASFCondition arg);
ASF_ASFCondition ASF_setASFConditionRhs(ASF_ASFCondition arg, ASF_Tree rhs);
ATbool ASF_hasASFConditionWsAfterUnequal(ASF_ASFCondition arg);
ASF_OptLayout ASF_getASFConditionWsAfterUnequal(ASF_ASFCondition arg);
ASF_ASFCondition ASF_setASFConditionWsAfterUnequal(ASF_ASFCondition arg, ASF_OptLayout wsAfterUnequal);
ATbool ASF_hasASFConditionWsAfterEquality(ASF_ASFCondition arg);
ASF_OptLayout ASF_getASFConditionWsAfterEquality(ASF_ASFCondition arg);
ASF_ASFCondition ASF_setASFConditionWsAfterEquality(ASF_ASFCondition arg, ASF_OptLayout wsAfterEquality);
ATbool ASF_hasASFConditionWsAfterMatch(ASF_ASFCondition arg);
ASF_OptLayout ASF_getASFConditionWsAfterMatch(ASF_ASFCondition arg);
ASF_ASFCondition ASF_setASFConditionWsAfterMatch(ASF_ASFCondition arg, ASF_OptLayout wsAfterMatch);

/*}}}  */
/*{{{  ASF_ASFConditions accessors */

ATbool ASF_isValidASFConditions(ASF_ASFConditions arg);
inline ATbool ASF_isASFConditionsDefault(ASF_ASFConditions arg);
ATbool ASF_hasASFConditionsList(ASF_ASFConditions arg);
ASF_ASFConditionList ASF_getASFConditionsList(ASF_ASFConditions arg);
ASF_ASFConditions ASF_setASFConditionsList(ASF_ASFConditions arg, ASF_ASFConditionList list);

/*}}}  */
/*{{{  ASF_ASFConditionList accessors */

ATbool ASF_isValidASFConditionList(ASF_ASFConditionList arg);
inline ATbool ASF_isASFConditionListSingle(ASF_ASFConditionList arg);
inline ATbool ASF_isASFConditionListMany(ASF_ASFConditionList arg);
ATbool ASF_hasASFConditionListHead(ASF_ASFConditionList arg);
ASF_ASFCondition ASF_getASFConditionListHead(ASF_ASFConditionList arg);
ASF_ASFConditionList ASF_setASFConditionListHead(ASF_ASFConditionList arg, ASF_ASFCondition head);
ATbool ASF_hasASFConditionListWsAfterFirst(ASF_ASFConditionList arg);
ASF_OptLayout ASF_getASFConditionListWsAfterFirst(ASF_ASFConditionList arg);
ASF_ASFConditionList ASF_setASFConditionListWsAfterFirst(ASF_ASFConditionList arg, ASF_OptLayout wsAfterFirst);
ATbool ASF_hasASFConditionListSep(ASF_ASFConditionList arg);
char * ASF_getASFConditionListSep(ASF_ASFConditionList arg);
ASF_ASFConditionList ASF_setASFConditionListSep(ASF_ASFConditionList arg, char * sep);
ATbool ASF_hasASFConditionListWsAfterSep(ASF_ASFConditionList arg);
ASF_OptLayout ASF_getASFConditionListWsAfterSep(ASF_ASFConditionList arg);
ASF_ASFConditionList ASF_setASFConditionListWsAfterSep(ASF_ASFConditionList arg, ASF_OptLayout wsAfterSep);
ATbool ASF_hasASFConditionListTail(ASF_ASFConditionList arg);
ASF_ASFConditionList ASF_getASFConditionListTail(ASF_ASFConditionList arg);
ASF_ASFConditionList ASF_setASFConditionListTail(ASF_ASFConditionList arg, ASF_ASFConditionList tail);

/*}}}  */
/*{{{  ASF_Tree accessors */

ATbool ASF_isValidTree(ASF_Tree arg);
inline ATbool ASF_isTreeAmbiguityConstructor(ASF_Tree arg);
inline ATbool ASF_isTreeLexicalConstructor(ASF_Tree arg);
ATbool ASF_hasTreeAmb(ASF_Tree arg);
ASF_Symbol ASF_getTreeAmb(ASF_Tree arg);
ASF_Tree ASF_setTreeAmb(ASF_Tree arg, ASF_Symbol amb);
ATbool ASF_hasTreeSymbol(ASF_Tree arg);
ASF_Symbol ASF_getTreeSymbol(ASF_Tree arg);
ASF_Tree ASF_setTreeSymbol(ASF_Tree arg, ASF_Symbol symbol);
ATbool ASF_hasTreeWsAfterAmb(ASF_Tree arg);
ASF_OptLayout ASF_getTreeWsAfterAmb(ASF_Tree arg);
ASF_Tree ASF_setTreeWsAfterAmb(ASF_Tree arg, ASF_OptLayout wsAfterAmb);
ATbool ASF_hasTreeWsAfterParenOpen(ASF_Tree arg);
ASF_OptLayout ASF_getTreeWsAfterParenOpen(ASF_Tree arg);
ASF_Tree ASF_setTreeWsAfterParenOpen(ASF_Tree arg, ASF_OptLayout wsAfterParenOpen);
ATbool ASF_hasTreeListSymbol(ASF_Tree arg);
ASF_Symbol ASF_getTreeListSymbol(ASF_Tree arg);
ASF_Tree ASF_setTreeListSymbol(ASF_Tree arg, ASF_Symbol listSymbol);
ATbool ASF_hasTreeAmbs(ASF_Tree arg);
ASF_TreeAmbs ASF_getTreeAmbs(ASF_Tree arg);
ASF_Tree ASF_setTreeAmbs(ASF_Tree arg, ASF_TreeAmbs ambs);
ATbool ASF_hasTreeWsAfterAmbs(ASF_Tree arg);
ASF_OptLayout ASF_getTreeWsAfterAmbs(ASF_Tree arg);
ASF_Tree ASF_setTreeWsAfterAmbs(ASF_Tree arg, ASF_OptLayout wsAfterAmbs);
ATbool ASF_hasTreeFormalName(ASF_Tree arg);
char * ASF_getTreeFormalName(ASF_Tree arg);
ASF_Tree ASF_setTreeFormalName(ASF_Tree arg, char * formalName);
ATbool ASF_hasTreeName(ASF_Tree arg);
ASF_Tree ASF_getTreeName(ASF_Tree arg);
ASF_Tree ASF_setTreeName(ASF_Tree arg, ASF_Tree name);
ATbool ASF_hasTreeWsAfterName(ASF_Tree arg);
ASF_OptLayout ASF_getTreeWsAfterName(ASF_Tree arg);
ASF_Tree ASF_setTreeWsAfterName(ASF_Tree arg, ASF_OptLayout wsAfterName);
ATbool ASF_hasTreeList(ASF_Tree arg);
ASF_CHARList ASF_getTreeList(ASF_Tree arg);
ASF_Tree ASF_setTreeList(ASF_Tree arg, ASF_CHARList list);
ATbool ASF_hasTreeWsAfterList(ASF_Tree arg);
ASF_OptLayout ASF_getTreeWsAfterList(ASF_Tree arg);
ASF_Tree ASF_setTreeWsAfterList(ASF_Tree arg, ASF_OptLayout wsAfterList);

/*}}}  */
/*{{{  ASF_TreeAmbs accessors */

ATbool ASF_isValidTreeAmbs(ASF_TreeAmbs arg);
inline ATbool ASF_isTreeAmbsEmpty(ASF_TreeAmbs arg);
inline ATbool ASF_isTreeAmbsSingle(ASF_TreeAmbs arg);
inline ATbool ASF_isTreeAmbsMany(ASF_TreeAmbs arg);
ATbool ASF_hasTreeAmbsHead(ASF_TreeAmbs arg);
ASF_Tree ASF_getTreeAmbsHead(ASF_TreeAmbs arg);
ASF_TreeAmbs ASF_setTreeAmbsHead(ASF_TreeAmbs arg, ASF_Tree head);
ATbool ASF_hasTreeAmbsWsAfterFirst(ASF_TreeAmbs arg);
ASF_OptLayout ASF_getTreeAmbsWsAfterFirst(ASF_TreeAmbs arg);
ASF_TreeAmbs ASF_setTreeAmbsWsAfterFirst(ASF_TreeAmbs arg, ASF_OptLayout wsAfterFirst);
ATbool ASF_hasTreeAmbsSep(ASF_TreeAmbs arg);
char * ASF_getTreeAmbsSep(ASF_TreeAmbs arg);
ASF_TreeAmbs ASF_setTreeAmbsSep(ASF_TreeAmbs arg, char * sep);
ATbool ASF_hasTreeAmbsWsAfterSep(ASF_TreeAmbs arg);
ASF_OptLayout ASF_getTreeAmbsWsAfterSep(ASF_TreeAmbs arg);
ASF_TreeAmbs ASF_setTreeAmbsWsAfterSep(ASF_TreeAmbs arg, ASF_OptLayout wsAfterSep);
ATbool ASF_hasTreeAmbsTail(ASF_TreeAmbs arg);
ASF_TreeAmbs ASF_getTreeAmbsTail(ASF_TreeAmbs arg);
ASF_TreeAmbs ASF_setTreeAmbsTail(ASF_TreeAmbs arg, ASF_TreeAmbs tail);

/*}}}  */
/*{{{  ASF_CHARList accessors */

ATbool ASF_isValidCHARList(ASF_CHARList arg);
inline ATbool ASF_isCHARListEmpty(ASF_CHARList arg);
inline ATbool ASF_isCHARListSingle(ASF_CHARList arg);
inline ATbool ASF_isCHARListMany(ASF_CHARList arg);
ATbool ASF_hasCHARListHead(ASF_CHARList arg);
ASF_CHAR ASF_getCHARListHead(ASF_CHARList arg);
ASF_CHARList ASF_setCHARListHead(ASF_CHARList arg, ASF_CHAR head);
ATbool ASF_hasCHARListWsAfterFirst(ASF_CHARList arg);
ASF_OptLayout ASF_getCHARListWsAfterFirst(ASF_CHARList arg);
ASF_CHARList ASF_setCHARListWsAfterFirst(ASF_CHARList arg, ASF_OptLayout wsAfterFirst);
ATbool ASF_hasCHARListTail(ASF_CHARList arg);
ASF_CHARList ASF_getCHARListTail(ASF_CHARList arg);
ASF_CHARList ASF_setCHARListTail(ASF_CHARList arg, ASF_CHARList tail);

/*}}}  */
/*{{{  ASF_ASFImplies accessors */

ATbool ASF_isValidASFImplies(ASF_ASFImplies arg);
inline ATbool ASF_isASFImpliesDefault(ASF_ASFImplies arg);
ATbool ASF_hasASFImpliesChars(ASF_ASFImplies arg);
ASF_CHARLIST ASF_getASFImpliesChars(ASF_ASFImplies arg);
ASF_ASFImplies ASF_setASFImpliesChars(ASF_ASFImplies arg, ASF_CHARLIST chars);

/*}}}  */
/*{{{  ASF_ASFConditionalEquation accessors */

ATbool ASF_isValidASFConditionalEquation(ASF_ASFConditionalEquation arg);
inline ATbool ASF_isASFConditionalEquationSimple(ASF_ASFConditionalEquation arg);
inline ATbool ASF_isASFConditionalEquationImplies(ASF_ASFConditionalEquation arg);
inline ATbool ASF_isASFConditionalEquationWhen(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg);
ASF_ASFTag ASF_getASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg, ASF_ASFTag ASFTag);
ATbool ASF_hasASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg);
ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFTag);
ATbool ASF_hasASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg);
ASF_ASFEquation ASF_getASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg, ASF_ASFEquation ASFEquation);
ATbool ASF_hasASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg);
ASF_ASFConditions ASF_getASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg, ASF_ASFConditions ASFConditions);
ATbool ASF_hasASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg);
ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFConditions);
ATbool ASF_hasASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg);
ASF_ASFImplies ASF_getASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg, ASF_ASFImplies ASFImplies);
ATbool ASF_hasASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg);
ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFImplies);
ATbool ASF_hasASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg);
ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFEquation);
ATbool ASF_hasASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg);
ASF_OptLayout ASF_getASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterWhen);

/*}}}  */
/*{{{  ASF_ASFEquation accessors */

ATbool ASF_isValidASFEquation(ASF_ASFEquation arg);
inline ATbool ASF_isASFEquationDefault(ASF_ASFEquation arg);
ATbool ASF_hasASFEquationLhsSymbol(ASF_ASFEquation arg);
ASF_Symbol ASF_getASFEquationLhsSymbol(ASF_ASFEquation arg);
ASF_ASFEquation ASF_setASFEquationLhsSymbol(ASF_ASFEquation arg, ASF_Symbol lhsSymbol);
ATbool ASF_hasASFEquationRhsSymbol(ASF_ASFEquation arg);
ASF_Symbol ASF_getASFEquationRhsSymbol(ASF_ASFEquation arg);
ASF_ASFEquation ASF_setASFEquationRhsSymbol(ASF_ASFEquation arg, ASF_Symbol rhsSymbol);
ATbool ASF_hasASFEquationLhs(ASF_ASFEquation arg);
ASF_Tree ASF_getASFEquationLhs(ASF_ASFEquation arg);
ASF_ASFEquation ASF_setASFEquationLhs(ASF_ASFEquation arg, ASF_Tree lhs);
ATbool ASF_hasASFEquationWsAfterLhs(ASF_ASFEquation arg);
ASF_OptLayout ASF_getASFEquationWsAfterLhs(ASF_ASFEquation arg);
ASF_ASFEquation ASF_setASFEquationWsAfterLhs(ASF_ASFEquation arg, ASF_OptLayout wsAfterLhs);
ATbool ASF_hasASFEquationWsAfterEquals(ASF_ASFEquation arg);
ASF_OptLayout ASF_getASFEquationWsAfterEquals(ASF_ASFEquation arg);
ASF_ASFEquation ASF_setASFEquationWsAfterEquals(ASF_ASFEquation arg, ASF_OptLayout wsAfterEquals);
ATbool ASF_hasASFEquationRhs(ASF_ASFEquation arg);
ASF_Tree ASF_getASFEquationRhs(ASF_ASFEquation arg);
ASF_ASFEquation ASF_setASFEquationRhs(ASF_ASFEquation arg, ASF_Tree rhs);

/*}}}  */
/*{{{  ASF_ASFModule accessors */

ATbool ASF_isValidASFModule(ASF_ASFModule arg);
inline ATbool ASF_isASFModuleDefault(ASF_ASFModule arg);
ATbool ASF_hasASFModuleList(ASF_ASFModule arg);
ASF_ASFSectionList ASF_getASFModuleList(ASF_ASFModule arg);
ASF_ASFModule ASF_setASFModuleList(ASF_ASFModule arg, ASF_ASFSectionList list);

/*}}}  */
/*{{{  ASF_ASFSectionList accessors */

ATbool ASF_isValidASFSectionList(ASF_ASFSectionList arg);
inline ATbool ASF_isASFSectionListEmpty(ASF_ASFSectionList arg);
inline ATbool ASF_isASFSectionListSingle(ASF_ASFSectionList arg);
inline ATbool ASF_isASFSectionListMany(ASF_ASFSectionList arg);
ATbool ASF_hasASFSectionListHead(ASF_ASFSectionList arg);
ASF_ASFSection ASF_getASFSectionListHead(ASF_ASFSectionList arg);
ASF_ASFSectionList ASF_setASFSectionListHead(ASF_ASFSectionList arg, ASF_ASFSection head);
ATbool ASF_hasASFSectionListWsAfterFirst(ASF_ASFSectionList arg);
ASF_OptLayout ASF_getASFSectionListWsAfterFirst(ASF_ASFSectionList arg);
ASF_ASFSectionList ASF_setASFSectionListWsAfterFirst(ASF_ASFSectionList arg, ASF_OptLayout wsAfterFirst);
ATbool ASF_hasASFSectionListTail(ASF_ASFSectionList arg);
ASF_ASFSectionList ASF_getASFSectionListTail(ASF_ASFSectionList arg);
ASF_ASFSectionList ASF_setASFSectionListTail(ASF_ASFSectionList arg, ASF_ASFSectionList tail);

/*}}}  */
/*{{{  ASF_ASFSection accessors */

ATbool ASF_isValidASFSection(ASF_ASFSection arg);
inline ATbool ASF_isASFSectionEquations(ASF_ASFSection arg);
inline ATbool ASF_isASFSectionTests(ASF_ASFSection arg);
ATbool ASF_hasASFSectionWsAfterEquations(ASF_ASFSection arg);
ASF_OptLayout ASF_getASFSectionWsAfterEquations(ASF_ASFSection arg);
ASF_ASFSection ASF_setASFSectionWsAfterEquations(ASF_ASFSection arg, ASF_OptLayout wsAfterEquations);
ATbool ASF_hasASFSectionList(ASF_ASFSection arg);
ASF_ASFConditionalEquationList ASF_getASFSectionList(ASF_ASFSection arg);
ASF_ASFSection ASF_setASFSectionList(ASF_ASFSection arg, ASF_ASFConditionalEquationList list);
ATbool ASF_hasASFSectionWsAfterTests(ASF_ASFSection arg);
ASF_OptLayout ASF_getASFSectionWsAfterTests(ASF_ASFSection arg);
ASF_ASFSection ASF_setASFSectionWsAfterTests(ASF_ASFSection arg, ASF_OptLayout wsAfterTests);
ATbool ASF_hasASFSectionTestList(ASF_ASFSection arg);
ASF_ASFTestEquationTestList ASF_getASFSectionTestList(ASF_ASFSection arg);
ASF_ASFSection ASF_setASFSectionTestList(ASF_ASFSection arg, ASF_ASFTestEquationTestList testList);

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList accessors */

ATbool ASF_isValidASFConditionalEquationList(ASF_ASFConditionalEquationList arg);
inline ATbool ASF_isASFConditionalEquationListEmpty(ASF_ASFConditionalEquationList arg);
inline ATbool ASF_isASFConditionalEquationListSingle(ASF_ASFConditionalEquationList arg);
inline ATbool ASF_isASFConditionalEquationListMany(ASF_ASFConditionalEquationList arg);
ATbool ASF_hasASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg);
ASF_ASFConditionalEquation ASF_getASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg);
ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation head);
ATbool ASF_hasASFConditionalEquationListWsAfterFirst(ASF_ASFConditionalEquationList arg);
ASF_OptLayout ASF_getASFConditionalEquationListWsAfterFirst(ASF_ASFConditionalEquationList arg);
ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListWsAfterFirst(ASF_ASFConditionalEquationList arg, ASF_OptLayout wsAfterFirst);
ATbool ASF_hasASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg);
ASF_ASFConditionalEquationList ASF_getASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg);
ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquationList tail);

/*}}}  */
/*{{{  ASF_ASFTestEquationTestList accessors */

ATbool ASF_isValidASFTestEquationTestList(ASF_ASFTestEquationTestList arg);
inline ATbool ASF_isASFTestEquationTestListEmpty(ASF_ASFTestEquationTestList arg);
inline ATbool ASF_isASFTestEquationTestListSingle(ASF_ASFTestEquationTestList arg);
inline ATbool ASF_isASFTestEquationTestListMany(ASF_ASFTestEquationTestList arg);
ATbool ASF_hasASFTestEquationTestListHead(ASF_ASFTestEquationTestList arg);
ASF_ASFTestEquation ASF_getASFTestEquationTestListHead(ASF_ASFTestEquationTestList arg);
ASF_ASFTestEquationTestList ASF_setASFTestEquationTestListHead(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquation head);
ATbool ASF_hasASFTestEquationTestListWsAfterFirst(ASF_ASFTestEquationTestList arg);
ASF_OptLayout ASF_getASFTestEquationTestListWsAfterFirst(ASF_ASFTestEquationTestList arg);
ASF_ASFTestEquationTestList ASF_setASFTestEquationTestListWsAfterFirst(ASF_ASFTestEquationTestList arg, ASF_OptLayout wsAfterFirst);
ATbool ASF_hasASFTestEquationTestListTail(ASF_ASFTestEquationTestList arg);
ASF_ASFTestEquationTestList ASF_getASFTestEquationTestListTail(ASF_ASFTestEquationTestList arg);
ASF_ASFTestEquationTestList ASF_setASFTestEquationTestListTail(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquationTestList tail);

/*}}}  */
/*{{{  ASF_ASFTagId accessors */

ATbool ASF_isValidASFTagId(ASF_ASFTagId arg);
inline ATbool ASF_isASFTagIdOneChar(ASF_ASFTagId arg);
inline ATbool ASF_isASFTagIdManyChars(ASF_ASFTagId arg);
ATbool ASF_hasASFTagIdChars(ASF_ASFTagId arg);
ASF_CHARLIST ASF_getASFTagIdChars(ASF_ASFTagId arg);
ASF_ASFTagId ASF_setASFTagIdChars(ASF_ASFTagId arg, ASF_CHARLIST chars);

/*}}}  */
/*{{{  ASF_ASFTag accessors */

ATbool ASF_isValidASFTag(ASF_ASFTag arg);
inline ATbool ASF_isASFTagEmpty(ASF_ASFTag arg);
inline ATbool ASF_isASFTagNotEmpty(ASF_ASFTag arg);
ATbool ASF_hasASFTagWsAfterBracketOpen(ASF_ASFTag arg);
ASF_OptLayout ASF_getASFTagWsAfterBracketOpen(ASF_ASFTag arg);
ASF_ASFTag ASF_setASFTagWsAfterBracketOpen(ASF_ASFTag arg, ASF_OptLayout wsAfterBracketOpen);
ATbool ASF_hasASFTagASFTagId(ASF_ASFTag arg);
ASF_ASFTagId ASF_getASFTagASFTagId(ASF_ASFTag arg);
ASF_ASFTag ASF_setASFTagASFTagId(ASF_ASFTag arg, ASF_ASFTagId ASFTagId);
ATbool ASF_hasASFTagWsAfterASFTagId(ASF_ASFTag arg);
ASF_OptLayout ASF_getASFTagWsAfterASFTagId(ASF_ASFTag arg);
ASF_ASFTag ASF_setASFTagWsAfterASFTagId(ASF_ASFTag arg, ASF_OptLayout wsAfterASFTagId);

/*}}}  */
/*{{{  ASF_ASFTestEquation accessors */

ATbool ASF_isValidASFTestEquation(ASF_ASFTestEquation arg);
inline ATbool ASF_isASFTestEquationSimple(ASF_ASFTestEquation arg);
inline ATbool ASF_isASFTestEquationImplies(ASF_ASFTestEquation arg);
inline ATbool ASF_isASFTestEquationWhen(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationASFTag(ASF_ASFTestEquation arg);
ASF_ASFTag ASF_getASFTestEquationASFTag(ASF_ASFTestEquation arg);
ASF_ASFTestEquation ASF_setASFTestEquationASFTag(ASF_ASFTestEquation arg, ASF_ASFTag ASFTag);
ATbool ASF_hasASFTestEquationWsAfterASFTag(ASF_ASFTestEquation arg);
ASF_OptLayout ASF_getASFTestEquationWsAfterASFTag(ASF_ASFTestEquation arg);
ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFTag(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFTag);
ATbool ASF_hasASFTestEquationASFCondition(ASF_ASFTestEquation arg);
ASF_ASFCondition ASF_getASFTestEquationASFCondition(ASF_ASFTestEquation arg);
ASF_ASFTestEquation ASF_setASFTestEquationASFCondition(ASF_ASFTestEquation arg, ASF_ASFCondition ASFCondition);
ATbool ASF_hasASFTestEquationASFConditions(ASF_ASFTestEquation arg);
ASF_ASFConditions ASF_getASFTestEquationASFConditions(ASF_ASFTestEquation arg);
ASF_ASFTestEquation ASF_setASFTestEquationASFConditions(ASF_ASFTestEquation arg, ASF_ASFConditions ASFConditions);
ATbool ASF_hasASFTestEquationWsAfterASFConditions(ASF_ASFTestEquation arg);
ASF_OptLayout ASF_getASFTestEquationWsAfterASFConditions(ASF_ASFTestEquation arg);
ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFConditions(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFConditions);
ATbool ASF_hasASFTestEquationASFImplies(ASF_ASFTestEquation arg);
ASF_ASFImplies ASF_getASFTestEquationASFImplies(ASF_ASFTestEquation arg);
ASF_ASFTestEquation ASF_setASFTestEquationASFImplies(ASF_ASFTestEquation arg, ASF_ASFImplies ASFImplies);
ATbool ASF_hasASFTestEquationWsAfterASFImplies(ASF_ASFTestEquation arg);
ASF_OptLayout ASF_getASFTestEquationWsAfterASFImplies(ASF_ASFTestEquation arg);
ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFImplies(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFImplies);
ATbool ASF_hasASFTestEquationWsAfterASFCondition(ASF_ASFTestEquation arg);
ASF_OptLayout ASF_getASFTestEquationWsAfterASFCondition(ASF_ASFTestEquation arg);
ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFCondition(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFCondition);
ATbool ASF_hasASFTestEquationWsAfterWhen(ASF_ASFTestEquation arg);
ASF_OptLayout ASF_getASFTestEquationWsAfterWhen(ASF_ASFTestEquation arg);
ASF_ASFTestEquation ASF_setASFTestEquationWsAfterWhen(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterWhen);

/*}}}  */
/*{{{  ASF_Start accessors */

ATbool ASF_isValidStart(ASF_Start arg);
inline ATbool ASF_isStartASFTestEquation(ASF_Start arg);
inline ATbool ASF_isStartASFTag(ASF_Start arg);
inline ATbool ASF_isStartASFTagId(ASF_Start arg);
inline ATbool ASF_isStartASFSection(ASF_Start arg);
inline ATbool ASF_isStartASFModule(ASF_Start arg);
inline ATbool ASF_isStartASFConditionalEquation(ASF_Start arg);
inline ATbool ASF_isStartASFEquation(ASF_Start arg);
inline ATbool ASF_isStartASFImplies(ASF_Start arg);
inline ATbool ASF_isStartTree(ASF_Start arg);
inline ATbool ASF_isStartASFConditions(ASF_Start arg);
inline ATbool ASF_isStartASFCondition(ASF_Start arg);
ATbool ASF_hasStartWsBefore(ASF_Start arg);
ASF_OptLayout ASF_getStartWsBefore(ASF_Start arg);
ASF_Start ASF_setStartWsBefore(ASF_Start arg, ASF_OptLayout wsBefore);
ATbool ASF_hasStartTopASFTestEquation(ASF_Start arg);
ASF_ASFTestEquation ASF_getStartTopASFTestEquation(ASF_Start arg);
ASF_Start ASF_setStartTopASFTestEquation(ASF_Start arg, ASF_ASFTestEquation topASFTestEquation);
ATbool ASF_hasStartWsAfter(ASF_Start arg);
ASF_OptLayout ASF_getStartWsAfter(ASF_Start arg);
ASF_Start ASF_setStartWsAfter(ASF_Start arg, ASF_OptLayout wsAfter);
ATbool ASF_hasStartAmbCnt(ASF_Start arg);
int ASF_getStartAmbCnt(ASF_Start arg);
ASF_Start ASF_setStartAmbCnt(ASF_Start arg, int ambCnt);
ATbool ASF_hasStartTopASFTag(ASF_Start arg);
ASF_ASFTag ASF_getStartTopASFTag(ASF_Start arg);
ASF_Start ASF_setStartTopASFTag(ASF_Start arg, ASF_ASFTag topASFTag);
ATbool ASF_hasStartTopASFTagId(ASF_Start arg);
ASF_ASFTagId ASF_getStartTopASFTagId(ASF_Start arg);
ASF_Start ASF_setStartTopASFTagId(ASF_Start arg, ASF_ASFTagId topASFTagId);
ATbool ASF_hasStartTopASFSection(ASF_Start arg);
ASF_ASFSection ASF_getStartTopASFSection(ASF_Start arg);
ASF_Start ASF_setStartTopASFSection(ASF_Start arg, ASF_ASFSection topASFSection);
ATbool ASF_hasStartTopASFModule(ASF_Start arg);
ASF_ASFModule ASF_getStartTopASFModule(ASF_Start arg);
ASF_Start ASF_setStartTopASFModule(ASF_Start arg, ASF_ASFModule topASFModule);
ATbool ASF_hasStartTopASFConditionalEquation(ASF_Start arg);
ASF_ASFConditionalEquation ASF_getStartTopASFConditionalEquation(ASF_Start arg);
ASF_Start ASF_setStartTopASFConditionalEquation(ASF_Start arg, ASF_ASFConditionalEquation topASFConditionalEquation);
ATbool ASF_hasStartTopASFEquation(ASF_Start arg);
ASF_ASFEquation ASF_getStartTopASFEquation(ASF_Start arg);
ASF_Start ASF_setStartTopASFEquation(ASF_Start arg, ASF_ASFEquation topASFEquation);
ATbool ASF_hasStartTopASFImplies(ASF_Start arg);
ASF_ASFImplies ASF_getStartTopASFImplies(ASF_Start arg);
ASF_Start ASF_setStartTopASFImplies(ASF_Start arg, ASF_ASFImplies topASFImplies);
ATbool ASF_hasStartTopTree(ASF_Start arg);
ASF_Tree ASF_getStartTopTree(ASF_Start arg);
ASF_Start ASF_setStartTopTree(ASF_Start arg, ASF_Tree topTree);
ATbool ASF_hasStartTopASFConditions(ASF_Start arg);
ASF_ASFConditions ASF_getStartTopASFConditions(ASF_Start arg);
ASF_Start ASF_setStartTopASFConditions(ASF_Start arg, ASF_ASFConditions topASFConditions);
ATbool ASF_hasStartTopASFCondition(ASF_Start arg);
ASF_ASFCondition ASF_getStartTopASFCondition(ASF_Start arg);
ASF_Start ASF_setStartTopASFCondition(ASF_Start arg, ASF_ASFCondition topASFCondition);

/*}}}  */
/*{{{  ASF_OptLayout accessors */

ATbool ASF_isValidOptLayout(ASF_OptLayout arg);
inline ATbool ASF_isOptLayoutAbsent(ASF_OptLayout arg);
inline ATbool ASF_isOptLayoutPresent(ASF_OptLayout arg);
ATbool ASF_hasOptLayoutChars(ASF_OptLayout arg);
ASF_CHARLIST ASF_getOptLayoutChars(ASF_OptLayout arg);
ASF_OptLayout ASF_setOptLayoutChars(ASF_OptLayout arg, ASF_CHARLIST chars);

/*}}}  */
/*{{{  sort visitors */

ASF_Production ASF_visitProduction(ASF_Production arg, char * (*acceptFormalName)(char *), ASF_Symbol (*acceptSymbol)(ASF_Symbol));
ASF_CHAR ASF_visitCHAR(ASF_CHAR arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST));
ASF_ASFCondition ASF_visitASFCondition(ASF_ASFCondition arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquals)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterUnequal)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquality)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterMatch)(ASF_OptLayout));
ASF_ASFConditions ASF_visitASFConditions(ASF_ASFConditions arg, ASF_ASFConditionList (*acceptList)(ASF_ASFConditionList));
ASF_ASFConditionList ASF_visitASFConditionList(ASF_ASFConditionList arg, ASF_ASFCondition (*acceptHead)(ASF_ASFCondition), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout), char * (*acceptSep)(char *), ASF_OptLayout (*acceptWsAfterSep)(ASF_OptLayout));
ASF_Tree ASF_visitTree(ASF_Tree arg, ASF_Symbol (*acceptAmb)(ASF_Symbol), ASF_Symbol (*acceptSymbol)(ASF_Symbol), ASF_OptLayout (*acceptWsAfterAmb)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterParenOpen)(ASF_OptLayout), ASF_Symbol (*acceptListSymbol)(ASF_Symbol), ASF_TreeAmbs (*acceptAmbs)(ASF_TreeAmbs), ASF_OptLayout (*acceptWsAfterAmbs)(ASF_OptLayout), char * (*acceptFormalName)(char *), ASF_OptLayout (*acceptWsAfterName)(ASF_OptLayout), ASF_CHARList (*acceptList)(ASF_CHARList), ASF_OptLayout (*acceptWsAfterList)(ASF_OptLayout));
ASF_TreeAmbs ASF_visitTreeAmbs(ASF_TreeAmbs arg, ASF_Tree (*acceptHead)(ASF_Tree), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout), char * (*acceptSep)(char *), ASF_OptLayout (*acceptWsAfterSep)(ASF_OptLayout));
ASF_CHARList ASF_visitCHARList(ASF_CHARList arg, ASF_CHAR (*acceptHead)(ASF_CHAR), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout));
ASF_ASFImplies ASF_visitASFImplies(ASF_ASFImplies arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST));
ASF_ASFConditionalEquation ASF_visitASFConditionalEquation(ASF_ASFConditionalEquation arg, ASF_ASFTag (*acceptASFTag)(ASF_ASFTag), ASF_OptLayout (*acceptWsAfterASFTag)(ASF_OptLayout), ASF_ASFEquation (*acceptASFEquation)(ASF_ASFEquation), ASF_ASFConditions (*acceptASFConditions)(ASF_ASFConditions), ASF_OptLayout (*acceptWsAfterASFConditions)(ASF_OptLayout), ASF_ASFImplies (*acceptASFImplies)(ASF_ASFImplies), ASF_OptLayout (*acceptWsAfterASFImplies)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterASFEquation)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterWhen)(ASF_OptLayout));
ASF_ASFEquation ASF_visitASFEquation(ASF_ASFEquation arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquals)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree));
ASF_ASFModule ASF_visitASFModule(ASF_ASFModule arg, ASF_ASFSectionList (*acceptList)(ASF_ASFSectionList));
ASF_ASFSectionList ASF_visitASFSectionList(ASF_ASFSectionList arg, ASF_ASFSection (*acceptHead)(ASF_ASFSection), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout));
ASF_ASFSection ASF_visitASFSection(ASF_ASFSection arg, ASF_OptLayout (*acceptWsAfterEquations)(ASF_OptLayout), ASF_ASFConditionalEquationList (*acceptList)(ASF_ASFConditionalEquationList), ASF_OptLayout (*acceptWsAfterTests)(ASF_OptLayout), ASF_ASFTestEquationTestList (*acceptTestList)(ASF_ASFTestEquationTestList));
ASF_ASFConditionalEquationList ASF_visitASFConditionalEquationList(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation (*acceptHead)(ASF_ASFConditionalEquation), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout));
ASF_ASFTestEquationTestList ASF_visitASFTestEquationTestList(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquation (*acceptHead)(ASF_ASFTestEquation), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout));
ASF_ASFTagId ASF_visitASFTagId(ASF_ASFTagId arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST));
ASF_ASFTag ASF_visitASFTag(ASF_ASFTag arg, ASF_OptLayout (*acceptWsAfterBracketOpen)(ASF_OptLayout), ASF_ASFTagId (*acceptASFTagId)(ASF_ASFTagId), ASF_OptLayout (*acceptWsAfterASFTagId)(ASF_OptLayout));
ASF_ASFTestEquation ASF_visitASFTestEquation(ASF_ASFTestEquation arg, ASF_ASFTag (*acceptASFTag)(ASF_ASFTag), ASF_OptLayout (*acceptWsAfterASFTag)(ASF_OptLayout), ASF_ASFCondition (*acceptASFCondition)(ASF_ASFCondition), ASF_ASFConditions (*acceptASFConditions)(ASF_ASFConditions), ASF_OptLayout (*acceptWsAfterASFConditions)(ASF_OptLayout), ASF_ASFImplies (*acceptASFImplies)(ASF_ASFImplies), ASF_OptLayout (*acceptWsAfterASFImplies)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterASFCondition)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterWhen)(ASF_OptLayout));
ASF_Start ASF_visitStart(ASF_Start arg, ASF_OptLayout (*acceptWsBefore)(ASF_OptLayout), ASF_ASFTestEquation (*acceptTopASFTestEquation)(ASF_ASFTestEquation), ASF_OptLayout (*acceptWsAfter)(ASF_OptLayout), int (*acceptAmbCnt)(int), ASF_ASFTag (*acceptTopASFTag)(ASF_ASFTag), ASF_ASFTagId (*acceptTopASFTagId)(ASF_ASFTagId), ASF_ASFSection (*acceptTopASFSection)(ASF_ASFSection), ASF_ASFModule (*acceptTopASFModule)(ASF_ASFModule), ASF_ASFConditionalEquation (*acceptTopASFConditionalEquation)(ASF_ASFConditionalEquation), ASF_ASFEquation (*acceptTopASFEquation)(ASF_ASFEquation), ASF_ASFImplies (*acceptTopASFImplies)(ASF_ASFImplies), ASF_Tree (*acceptTopTree)(ASF_Tree), ASF_ASFConditions (*acceptTopASFConditions)(ASF_ASFConditions), ASF_ASFCondition (*acceptTopASFCondition)(ASF_ASFCondition));
ASF_OptLayout ASF_visitOptLayout(ASF_OptLayout arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST));

/*}}}  */

#endif /* _ASFME_H */
