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
typedef struct _ASF_TreeAmbs *ASF_TreeAmbs;
typedef struct _ASF_CHAR *ASF_CHAR;
typedef struct _ASF_OptLayout *ASF_OptLayout;
typedef struct _ASF_Start *ASF_Start;

/*}}}  */

void ASF_initASFMEApi(void);

/*{{{  term conversion functions */

#define ASF_makeProductionFromTerm(t) (ASF_ProductionFromTerm(t))
ASF_Production ASF_ProductionFromTerm(ATerm t);
#define ASF_makeTermFromProduction(t) (ASF_ProductionToTerm(t))
ATerm ASF_ProductionToTerm(ASF_Production arg);
#define ASF_makeImpliesFromTerm(t) (ASF_ImpliesFromTerm(t))
ASF_Implies ASF_ImpliesFromTerm(ATerm t);
#define ASF_makeTermFromImplies(t) (ASF_ImpliesToTerm(t))
ATerm ASF_ImpliesToTerm(ASF_Implies arg);
#define ASF_makeTagIdFromTerm(t) (ASF_TagIdFromTerm(t))
ASF_TagId ASF_TagIdFromTerm(ATerm t);
#define ASF_makeTermFromTagId(t) (ASF_TagIdToTerm(t))
ATerm ASF_TagIdToTerm(ASF_TagId arg);
#define ASF_makeConditionsFromTerm(t) (ASF_ConditionsFromTerm(t))
ASF_Conditions ASF_ConditionsFromTerm(ATerm t);
#define ASF_makeTermFromConditions(t) (ASF_ConditionsToTerm(t))
ATerm ASF_ConditionsToTerm(ASF_Conditions arg);
#define ASF_makeConditionListFromTerm(t) (ASF_ConditionListFromTerm(t))
ASF_ConditionList ASF_ConditionListFromTerm(ATerm t);
#define ASF_makeTermFromConditionList(t) (ASF_ConditionListToTerm(t))
ATerm ASF_ConditionListToTerm(ASF_ConditionList arg);
#define ASF_makeEquationsFromTerm(t) (ASF_EquationsFromTerm(t))
ASF_Equations ASF_EquationsFromTerm(ATerm t);
#define ASF_makeTermFromEquations(t) (ASF_EquationsToTerm(t))
ATerm ASF_EquationsToTerm(ASF_Equations arg);
#define ASF_makeCondEquationListFromTerm(t) (ASF_CondEquationListFromTerm(t))
ASF_CondEquationList ASF_CondEquationListFromTerm(ATerm t);
#define ASF_makeTermFromCondEquationList(t) (ASF_CondEquationListToTerm(t))
ATerm ASF_CondEquationListToTerm(ASF_CondEquationList arg);
#define ASF_makeCondEquationFromTerm(t) (ASF_CondEquationFromTerm(t))
ASF_CondEquation ASF_CondEquationFromTerm(ATerm t);
#define ASF_makeTermFromCondEquation(t) (ASF_CondEquationToTerm(t))
ATerm ASF_CondEquationToTerm(ASF_CondEquation arg);
#define ASF_makeTagFromTerm(t) (ASF_TagFromTerm(t))
ASF_Tag ASF_TagFromTerm(ATerm t);
#define ASF_makeTermFromTag(t) (ASF_TagToTerm(t))
ATerm ASF_TagToTerm(ASF_Tag arg);
#define ASF_makeTreeFromTerm(t) (ASF_TreeFromTerm(t))
ASF_Tree ASF_TreeFromTerm(ATerm t);
#define ASF_makeTermFromTree(t) (ASF_TreeToTerm(t))
ATerm ASF_TreeToTerm(ASF_Tree arg);
#define ASF_makeCHARListFromTerm(t) (ASF_CHARListFromTerm(t))
ASF_CHARList ASF_CHARListFromTerm(ATerm t);
#define ASF_makeTermFromCHARList(t) (ASF_CHARListToTerm(t))
ATerm ASF_CHARListToTerm(ASF_CHARList arg);
#define ASF_makeEquationFromTerm(t) (ASF_EquationFromTerm(t))
ASF_Equation ASF_EquationFromTerm(ATerm t);
#define ASF_makeTermFromEquation(t) (ASF_EquationToTerm(t))
ATerm ASF_EquationToTerm(ASF_Equation arg);
#define ASF_makeConditionFromTerm(t) (ASF_ConditionFromTerm(t))
ASF_Condition ASF_ConditionFromTerm(ATerm t);
#define ASF_makeTermFromCondition(t) (ASF_ConditionToTerm(t))
ATerm ASF_ConditionToTerm(ASF_Condition arg);
#define ASF_makeTreeAmbsFromTerm(t) (ASF_TreeAmbsFromTerm(t))
ASF_TreeAmbs ASF_TreeAmbsFromTerm(ATerm t);
#define ASF_makeTermFromTreeAmbs(t) (ASF_TreeAmbsToTerm(t))
ATerm ASF_TreeAmbsToTerm(ASF_TreeAmbs arg);
#define ASF_makeCHARFromTerm(t) (ASF_CHARFromTerm(t))
ASF_CHAR ASF_CHARFromTerm(ATerm t);
#define ASF_makeTermFromCHAR(t) (ASF_CHARToTerm(t))
ATerm ASF_CHARToTerm(ASF_CHAR arg);
#define ASF_makeOptLayoutFromTerm(t) (ASF_OptLayoutFromTerm(t))
ASF_OptLayout ASF_OptLayoutFromTerm(ATerm t);
#define ASF_makeTermFromOptLayout(t) (ASF_OptLayoutToTerm(t))
ATerm ASF_OptLayoutToTerm(ASF_OptLayout arg);
#define ASF_makeStartFromTerm(t) (ASF_StartFromTerm(t))
ASF_Start ASF_StartFromTerm(ATerm t);
#define ASF_makeTermFromStart(t) (ASF_StartToTerm(t))
ATerm ASF_StartToTerm(ASF_Start arg);

/*}}}  */
/*{{{  constructors */

ASF_Production ASF_makeProductionLexicalConstructor(char * formalName, ASF_Symbol symbol);
ASF_Implies ASF_makeImpliesDefault(ASF_CHARLIST chars);
ASF_TagId ASF_makeTagIdOneChar(ASF_CHARLIST chars);
ASF_TagId ASF_makeTagIdManyChars(ASF_CHARLIST chars);
ASF_Conditions ASF_makeConditionsDefault(ASF_ConditionList list);
ASF_ConditionList ASF_makeConditionListSingle(ASF_Condition head);
ASF_ConditionList ASF_makeConditionListMany(ASF_Condition head, ASF_OptLayout wsAfterFirst, char * sep, ASF_OptLayout wsAfterSep, ASF_ConditionList tail);
ASF_Equations ASF_makeEquationsAbsent();
ASF_Equations ASF_makeEquationsPresent(ASF_OptLayout wsAfterEquations, ASF_CondEquationList list);
ASF_CondEquationList ASF_makeCondEquationListEmpty();
ASF_CondEquationList ASF_makeCondEquationListSingle(ASF_CondEquation head);
ASF_CondEquationList ASF_makeCondEquationListMany(ASF_CondEquation head, ASF_OptLayout wsAfterFirst, ASF_CondEquationList tail);
ASF_CondEquation ASF_makeCondEquationSimple(ASF_Tag Tag, ASF_OptLayout wsAfterTag, ASF_Equation Equation);
ASF_CondEquation ASF_makeCondEquationImplies(ASF_Tag Tag, ASF_OptLayout wsAfterTag, ASF_Conditions Conditions, ASF_OptLayout wsAfterConditions, ASF_Implies Implies, ASF_OptLayout wsAfterImplies, ASF_Equation Equation);
ASF_CondEquation ASF_makeCondEquationWhen(ASF_Tag Tag, ASF_OptLayout wsAfterTag, ASF_Equation Equation, ASF_OptLayout wsAfterEquation, ASF_OptLayout wsAfterWhen, ASF_Conditions Conditions);
ASF_Tag ASF_makeTagEmpty(ASF_OptLayout wsAfterBracketOpen);
ASF_Tag ASF_makeTagNotEmpty(ASF_OptLayout wsAfterBracketOpen, ASF_TagId TagId, ASF_OptLayout wsAfterTagId);
ASF_Tree ASF_makeTreeLexicalConstructor(char * formalName, ASF_Symbol symbol, ASF_Tree name, ASF_OptLayout wsAfterName, ASF_OptLayout wsAfterParenOpen, ASF_CHARList list, ASF_OptLayout wsAfterList);
ASF_Tree ASF_makeTreeAmbiguityConstructor(ASF_Symbol amb, ASF_Symbol symbol, ASF_OptLayout wsAfterAmb, ASF_OptLayout wsAfterParenOpen, ASF_Symbol listSymbol, ASF_TreeAmbs ambs, ASF_OptLayout wsAfterAmbs);
ASF_CHARList ASF_makeCHARListEmpty();
ASF_CHARList ASF_makeCHARListSingle(ASF_CHAR head);
ASF_CHARList ASF_makeCHARListMany(ASF_CHAR head, ASF_OptLayout wsAfterFirst, ASF_CHARList tail);
ASF_Equation ASF_makeEquationDefault(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquals, ASF_Tree rhs);
ASF_Condition ASF_makeConditionPositive(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquals, ASF_Tree rhs);
ASF_Condition ASF_makeConditionNegative(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterUnequal, ASF_Tree rhs);
ASF_TreeAmbs ASF_makeTreeAmbsEmpty();
ASF_TreeAmbs ASF_makeTreeAmbsSingle(ASF_Tree head);
ASF_TreeAmbs ASF_makeTreeAmbsMany(ASF_Tree head, ASF_OptLayout wsAfterFirst, char * sep, ASF_OptLayout wsAfterSep, ASF_TreeAmbs tail);
ASF_CHAR ASF_makeCHARDefault(ASF_CHARLIST chars);
ASF_OptLayout ASF_makeOptLayoutAbsent();
ASF_OptLayout ASF_makeOptLayoutPresent(ASF_CHARLIST chars);
ASF_Start ASF_makeStartEquations(ASF_OptLayout wsBefore, ASF_Equations topEquations, ASF_OptLayout wsAfter, int ambCnt);

/*}}}  */
/*{{{  equality functions */

ATbool ASF_isEqualProduction(ASF_Production arg0, ASF_Production arg1);
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
ATbool ASF_isEqualTreeAmbs(ASF_TreeAmbs arg0, ASF_TreeAmbs arg1);
ATbool ASF_isEqualCHAR(ASF_CHAR arg0, ASF_CHAR arg1);
ATbool ASF_isEqualOptLayout(ASF_OptLayout arg0, ASF_OptLayout arg1);
ATbool ASF_isEqualStart(ASF_Start arg0, ASF_Start arg1);

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
/*{{{  ASF_Implies accessors */

ATbool ASF_isValidImplies(ASF_Implies arg);
inline ATbool ASF_isImpliesDefault(ASF_Implies arg);
ATbool ASF_hasImpliesChars(ASF_Implies arg);
ASF_CHARLIST ASF_getImpliesChars(ASF_Implies arg);
ASF_Implies ASF_setImpliesChars(ASF_Implies arg, ASF_CHARLIST chars);

/*}}}  */
/*{{{  ASF_TagId accessors */

ATbool ASF_isValidTagId(ASF_TagId arg);
inline ATbool ASF_isTagIdOneChar(ASF_TagId arg);
inline ATbool ASF_isTagIdManyChars(ASF_TagId arg);
ATbool ASF_hasTagIdChars(ASF_TagId arg);
ASF_CHARLIST ASF_getTagIdChars(ASF_TagId arg);
ASF_TagId ASF_setTagIdChars(ASF_TagId arg, ASF_CHARLIST chars);

/*}}}  */
/*{{{  ASF_Conditions accessors */

ATbool ASF_isValidConditions(ASF_Conditions arg);
inline ATbool ASF_isConditionsDefault(ASF_Conditions arg);
ATbool ASF_hasConditionsList(ASF_Conditions arg);
ASF_ConditionList ASF_getConditionsList(ASF_Conditions arg);
ASF_Conditions ASF_setConditionsList(ASF_Conditions arg, ASF_ConditionList list);

/*}}}  */
/*{{{  ASF_ConditionList accessors */

ATbool ASF_isValidConditionList(ASF_ConditionList arg);
inline ATbool ASF_isConditionListSingle(ASF_ConditionList arg);
inline ATbool ASF_isConditionListMany(ASF_ConditionList arg);
ATbool ASF_hasConditionListHead(ASF_ConditionList arg);
ASF_Condition ASF_getConditionListHead(ASF_ConditionList arg);
ASF_ConditionList ASF_setConditionListHead(ASF_ConditionList arg, ASF_Condition head);
ATbool ASF_hasConditionListWsAfterFirst(ASF_ConditionList arg);
ASF_OptLayout ASF_getConditionListWsAfterFirst(ASF_ConditionList arg);
ASF_ConditionList ASF_setConditionListWsAfterFirst(ASF_ConditionList arg, ASF_OptLayout wsAfterFirst);
ATbool ASF_hasConditionListSep(ASF_ConditionList arg);
char * ASF_getConditionListSep(ASF_ConditionList arg);
ASF_ConditionList ASF_setConditionListSep(ASF_ConditionList arg, char * sep);
ATbool ASF_hasConditionListWsAfterSep(ASF_ConditionList arg);
ASF_OptLayout ASF_getConditionListWsAfterSep(ASF_ConditionList arg);
ASF_ConditionList ASF_setConditionListWsAfterSep(ASF_ConditionList arg, ASF_OptLayout wsAfterSep);
ATbool ASF_hasConditionListTail(ASF_ConditionList arg);
ASF_ConditionList ASF_getConditionListTail(ASF_ConditionList arg);
ASF_ConditionList ASF_setConditionListTail(ASF_ConditionList arg, ASF_ConditionList tail);

/*}}}  */
/*{{{  ASF_Equations accessors */

ATbool ASF_isValidEquations(ASF_Equations arg);
inline ATbool ASF_isEquationsAbsent(ASF_Equations arg);
inline ATbool ASF_isEquationsPresent(ASF_Equations arg);
ATbool ASF_hasEquationsWsAfterEquations(ASF_Equations arg);
ASF_OptLayout ASF_getEquationsWsAfterEquations(ASF_Equations arg);
ASF_Equations ASF_setEquationsWsAfterEquations(ASF_Equations arg, ASF_OptLayout wsAfterEquations);
ATbool ASF_hasEquationsList(ASF_Equations arg);
ASF_CondEquationList ASF_getEquationsList(ASF_Equations arg);
ASF_Equations ASF_setEquationsList(ASF_Equations arg, ASF_CondEquationList list);

/*}}}  */
/*{{{  ASF_CondEquationList accessors */

ATbool ASF_isValidCondEquationList(ASF_CondEquationList arg);
inline ATbool ASF_isCondEquationListEmpty(ASF_CondEquationList arg);
inline ATbool ASF_isCondEquationListSingle(ASF_CondEquationList arg);
inline ATbool ASF_isCondEquationListMany(ASF_CondEquationList arg);
ATbool ASF_hasCondEquationListHead(ASF_CondEquationList arg);
ASF_CondEquation ASF_getCondEquationListHead(ASF_CondEquationList arg);
ASF_CondEquationList ASF_setCondEquationListHead(ASF_CondEquationList arg, ASF_CondEquation head);
ATbool ASF_hasCondEquationListWsAfterFirst(ASF_CondEquationList arg);
ASF_OptLayout ASF_getCondEquationListWsAfterFirst(ASF_CondEquationList arg);
ASF_CondEquationList ASF_setCondEquationListWsAfterFirst(ASF_CondEquationList arg, ASF_OptLayout wsAfterFirst);
ATbool ASF_hasCondEquationListTail(ASF_CondEquationList arg);
ASF_CondEquationList ASF_getCondEquationListTail(ASF_CondEquationList arg);
ASF_CondEquationList ASF_setCondEquationListTail(ASF_CondEquationList arg, ASF_CondEquationList tail);

/*}}}  */
/*{{{  ASF_CondEquation accessors */

ATbool ASF_isValidCondEquation(ASF_CondEquation arg);
inline ATbool ASF_isCondEquationSimple(ASF_CondEquation arg);
inline ATbool ASF_isCondEquationImplies(ASF_CondEquation arg);
inline ATbool ASF_isCondEquationWhen(ASF_CondEquation arg);
ATbool ASF_hasCondEquationTag(ASF_CondEquation arg);
ASF_Tag ASF_getCondEquationTag(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationTag(ASF_CondEquation arg, ASF_Tag Tag);
ATbool ASF_hasCondEquationWsAfterTag(ASF_CondEquation arg);
ASF_OptLayout ASF_getCondEquationWsAfterTag(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationWsAfterTag(ASF_CondEquation arg, ASF_OptLayout wsAfterTag);
ATbool ASF_hasCondEquationEquation(ASF_CondEquation arg);
ASF_Equation ASF_getCondEquationEquation(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationEquation(ASF_CondEquation arg, ASF_Equation Equation);
ATbool ASF_hasCondEquationConditions(ASF_CondEquation arg);
ASF_Conditions ASF_getCondEquationConditions(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationConditions(ASF_CondEquation arg, ASF_Conditions Conditions);
ATbool ASF_hasCondEquationWsAfterConditions(ASF_CondEquation arg);
ASF_OptLayout ASF_getCondEquationWsAfterConditions(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationWsAfterConditions(ASF_CondEquation arg, ASF_OptLayout wsAfterConditions);
ATbool ASF_hasCondEquationImplies(ASF_CondEquation arg);
ASF_Implies ASF_getCondEquationImplies(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationImplies(ASF_CondEquation arg, ASF_Implies Implies);
ATbool ASF_hasCondEquationWsAfterImplies(ASF_CondEquation arg);
ASF_OptLayout ASF_getCondEquationWsAfterImplies(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationWsAfterImplies(ASF_CondEquation arg, ASF_OptLayout wsAfterImplies);
ATbool ASF_hasCondEquationWsAfterEquation(ASF_CondEquation arg);
ASF_OptLayout ASF_getCondEquationWsAfterEquation(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationWsAfterEquation(ASF_CondEquation arg, ASF_OptLayout wsAfterEquation);
ATbool ASF_hasCondEquationWsAfterWhen(ASF_CondEquation arg);
ASF_OptLayout ASF_getCondEquationWsAfterWhen(ASF_CondEquation arg);
ASF_CondEquation ASF_setCondEquationWsAfterWhen(ASF_CondEquation arg, ASF_OptLayout wsAfterWhen);

/*}}}  */
/*{{{  ASF_Tag accessors */

ATbool ASF_isValidTag(ASF_Tag arg);
inline ATbool ASF_isTagEmpty(ASF_Tag arg);
inline ATbool ASF_isTagNotEmpty(ASF_Tag arg);
ATbool ASF_hasTagWsAfterBracketOpen(ASF_Tag arg);
ASF_OptLayout ASF_getTagWsAfterBracketOpen(ASF_Tag arg);
ASF_Tag ASF_setTagWsAfterBracketOpen(ASF_Tag arg, ASF_OptLayout wsAfterBracketOpen);
ATbool ASF_hasTagTagId(ASF_Tag arg);
ASF_TagId ASF_getTagTagId(ASF_Tag arg);
ASF_Tag ASF_setTagTagId(ASF_Tag arg, ASF_TagId TagId);
ATbool ASF_hasTagWsAfterTagId(ASF_Tag arg);
ASF_OptLayout ASF_getTagWsAfterTagId(ASF_Tag arg);
ASF_Tag ASF_setTagWsAfterTagId(ASF_Tag arg, ASF_OptLayout wsAfterTagId);

/*}}}  */
/*{{{  ASF_Tree accessors */

ATbool ASF_isValidTree(ASF_Tree arg);
inline ATbool ASF_isTreeLexicalConstructor(ASF_Tree arg);
inline ATbool ASF_isTreeAmbiguityConstructor(ASF_Tree arg);
ATbool ASF_hasTreeFormalName(ASF_Tree arg);
char * ASF_getTreeFormalName(ASF_Tree arg);
ASF_Tree ASF_setTreeFormalName(ASF_Tree arg, char * formalName);
ATbool ASF_hasTreeSymbol(ASF_Tree arg);
ASF_Symbol ASF_getTreeSymbol(ASF_Tree arg);
ASF_Tree ASF_setTreeSymbol(ASF_Tree arg, ASF_Symbol symbol);
ATbool ASF_hasTreeName(ASF_Tree arg);
ASF_Tree ASF_getTreeName(ASF_Tree arg);
ASF_Tree ASF_setTreeName(ASF_Tree arg, ASF_Tree name);
ATbool ASF_hasTreeWsAfterName(ASF_Tree arg);
ASF_OptLayout ASF_getTreeWsAfterName(ASF_Tree arg);
ASF_Tree ASF_setTreeWsAfterName(ASF_Tree arg, ASF_OptLayout wsAfterName);
ATbool ASF_hasTreeWsAfterParenOpen(ASF_Tree arg);
ASF_OptLayout ASF_getTreeWsAfterParenOpen(ASF_Tree arg);
ASF_Tree ASF_setTreeWsAfterParenOpen(ASF_Tree arg, ASF_OptLayout wsAfterParenOpen);
ATbool ASF_hasTreeList(ASF_Tree arg);
ASF_CHARList ASF_getTreeList(ASF_Tree arg);
ASF_Tree ASF_setTreeList(ASF_Tree arg, ASF_CHARList list);
ATbool ASF_hasTreeWsAfterList(ASF_Tree arg);
ASF_OptLayout ASF_getTreeWsAfterList(ASF_Tree arg);
ASF_Tree ASF_setTreeWsAfterList(ASF_Tree arg, ASF_OptLayout wsAfterList);
ATbool ASF_hasTreeAmb(ASF_Tree arg);
ASF_Symbol ASF_getTreeAmb(ASF_Tree arg);
ASF_Tree ASF_setTreeAmb(ASF_Tree arg, ASF_Symbol amb);
ATbool ASF_hasTreeWsAfterAmb(ASF_Tree arg);
ASF_OptLayout ASF_getTreeWsAfterAmb(ASF_Tree arg);
ASF_Tree ASF_setTreeWsAfterAmb(ASF_Tree arg, ASF_OptLayout wsAfterAmb);
ATbool ASF_hasTreeListSymbol(ASF_Tree arg);
ASF_Symbol ASF_getTreeListSymbol(ASF_Tree arg);
ASF_Tree ASF_setTreeListSymbol(ASF_Tree arg, ASF_Symbol listSymbol);
ATbool ASF_hasTreeAmbs(ASF_Tree arg);
ASF_TreeAmbs ASF_getTreeAmbs(ASF_Tree arg);
ASF_Tree ASF_setTreeAmbs(ASF_Tree arg, ASF_TreeAmbs ambs);
ATbool ASF_hasTreeWsAfterAmbs(ASF_Tree arg);
ASF_OptLayout ASF_getTreeWsAfterAmbs(ASF_Tree arg);
ASF_Tree ASF_setTreeWsAfterAmbs(ASF_Tree arg, ASF_OptLayout wsAfterAmbs);

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
/*{{{  ASF_Equation accessors */

ATbool ASF_isValidEquation(ASF_Equation arg);
inline ATbool ASF_isEquationDefault(ASF_Equation arg);
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
ASF_OptLayout ASF_getEquationWsAfterLhs(ASF_Equation arg);
ASF_Equation ASF_setEquationWsAfterLhs(ASF_Equation arg, ASF_OptLayout wsAfterLhs);
ATbool ASF_hasEquationWsAfterEquals(ASF_Equation arg);
ASF_OptLayout ASF_getEquationWsAfterEquals(ASF_Equation arg);
ASF_Equation ASF_setEquationWsAfterEquals(ASF_Equation arg, ASF_OptLayout wsAfterEquals);
ATbool ASF_hasEquationRhs(ASF_Equation arg);
ASF_Tree ASF_getEquationRhs(ASF_Equation arg);
ASF_Equation ASF_setEquationRhs(ASF_Equation arg, ASF_Tree rhs);

/*}}}  */
/*{{{  ASF_Condition accessors */

ATbool ASF_isValidCondition(ASF_Condition arg);
inline ATbool ASF_isConditionPositive(ASF_Condition arg);
inline ATbool ASF_isConditionNegative(ASF_Condition arg);
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
ASF_OptLayout ASF_getConditionWsAfterLhs(ASF_Condition arg);
ASF_Condition ASF_setConditionWsAfterLhs(ASF_Condition arg, ASF_OptLayout wsAfterLhs);
ATbool ASF_hasConditionWsAfterEquals(ASF_Condition arg);
ASF_OptLayout ASF_getConditionWsAfterEquals(ASF_Condition arg);
ASF_Condition ASF_setConditionWsAfterEquals(ASF_Condition arg, ASF_OptLayout wsAfterEquals);
ATbool ASF_hasConditionRhs(ASF_Condition arg);
ASF_Tree ASF_getConditionRhs(ASF_Condition arg);
ASF_Condition ASF_setConditionRhs(ASF_Condition arg, ASF_Tree rhs);
ATbool ASF_hasConditionWsAfterUnequal(ASF_Condition arg);
ASF_OptLayout ASF_getConditionWsAfterUnequal(ASF_Condition arg);
ASF_Condition ASF_setConditionWsAfterUnequal(ASF_Condition arg, ASF_OptLayout wsAfterUnequal);

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
/*{{{  ASF_CHAR accessors */

ATbool ASF_isValidCHAR(ASF_CHAR arg);
inline ATbool ASF_isCHARDefault(ASF_CHAR arg);
ATbool ASF_hasCHARChars(ASF_CHAR arg);
ASF_CHARLIST ASF_getCHARChars(ASF_CHAR arg);
ASF_CHAR ASF_setCHARChars(ASF_CHAR arg, ASF_CHARLIST chars);

/*}}}  */
/*{{{  ASF_OptLayout accessors */

ATbool ASF_isValidOptLayout(ASF_OptLayout arg);
inline ATbool ASF_isOptLayoutAbsent(ASF_OptLayout arg);
inline ATbool ASF_isOptLayoutPresent(ASF_OptLayout arg);
ATbool ASF_hasOptLayoutChars(ASF_OptLayout arg);
ASF_CHARLIST ASF_getOptLayoutChars(ASF_OptLayout arg);
ASF_OptLayout ASF_setOptLayoutChars(ASF_OptLayout arg, ASF_CHARLIST chars);

/*}}}  */
/*{{{  ASF_Start accessors */

ATbool ASF_isValidStart(ASF_Start arg);
inline ATbool ASF_isStartEquations(ASF_Start arg);
ATbool ASF_hasStartWsBefore(ASF_Start arg);
ASF_OptLayout ASF_getStartWsBefore(ASF_Start arg);
ASF_Start ASF_setStartWsBefore(ASF_Start arg, ASF_OptLayout wsBefore);
ATbool ASF_hasStartTopEquations(ASF_Start arg);
ASF_Equations ASF_getStartTopEquations(ASF_Start arg);
ASF_Start ASF_setStartTopEquations(ASF_Start arg, ASF_Equations topEquations);
ATbool ASF_hasStartWsAfter(ASF_Start arg);
ASF_OptLayout ASF_getStartWsAfter(ASF_Start arg);
ASF_Start ASF_setStartWsAfter(ASF_Start arg, ASF_OptLayout wsAfter);
ATbool ASF_hasStartAmbCnt(ASF_Start arg);
int ASF_getStartAmbCnt(ASF_Start arg);
ASF_Start ASF_setStartAmbCnt(ASF_Start arg, int ambCnt);

/*}}}  */
/*{{{  sort visitors */

ASF_Production ASF_visitProduction(ASF_Production arg, char * (*acceptFormalName)(char *), ASF_Symbol (*acceptSymbol)(ASF_Symbol));
ASF_Implies ASF_visitImplies(ASF_Implies arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST));
ASF_TagId ASF_visitTagId(ASF_TagId arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST));
ASF_Conditions ASF_visitConditions(ASF_Conditions arg, ASF_ConditionList (*acceptList)(ASF_ConditionList));
ASF_ConditionList ASF_visitConditionList(ASF_ConditionList arg, ASF_Condition (*acceptHead)(ASF_Condition), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout), char * (*acceptSep)(char *), ASF_OptLayout (*acceptWsAfterSep)(ASF_OptLayout));
ASF_Equations ASF_visitEquations(ASF_Equations arg, ASF_OptLayout (*acceptWsAfterEquations)(ASF_OptLayout), ASF_CondEquationList (*acceptList)(ASF_CondEquationList));
ASF_CondEquationList ASF_visitCondEquationList(ASF_CondEquationList arg, ASF_CondEquation (*acceptHead)(ASF_CondEquation), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout));
ASF_CondEquation ASF_visitCondEquation(ASF_CondEquation arg, ASF_Tag (*acceptTag)(ASF_Tag), ASF_OptLayout (*acceptWsAfterTag)(ASF_OptLayout), ASF_Equation (*acceptEquation)(ASF_Equation), ASF_Conditions (*acceptConditions)(ASF_Conditions), ASF_OptLayout (*acceptWsAfterConditions)(ASF_OptLayout), ASF_Implies (*acceptImplies)(ASF_Implies), ASF_OptLayout (*acceptWsAfterImplies)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquation)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterWhen)(ASF_OptLayout));
ASF_Tag ASF_visitTag(ASF_Tag arg, ASF_OptLayout (*acceptWsAfterBracketOpen)(ASF_OptLayout), ASF_TagId (*acceptTagId)(ASF_TagId), ASF_OptLayout (*acceptWsAfterTagId)(ASF_OptLayout));
ASF_Tree ASF_visitTree(ASF_Tree arg, char * (*acceptFormalName)(char *), ASF_Symbol (*acceptSymbol)(ASF_Symbol), ASF_OptLayout (*acceptWsAfterName)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterParenOpen)(ASF_OptLayout), ASF_CHARList (*acceptList)(ASF_CHARList), ASF_OptLayout (*acceptWsAfterList)(ASF_OptLayout), ASF_Symbol (*acceptAmb)(ASF_Symbol), ASF_OptLayout (*acceptWsAfterAmb)(ASF_OptLayout), ASF_Symbol (*acceptListSymbol)(ASF_Symbol), ASF_TreeAmbs (*acceptAmbs)(ASF_TreeAmbs), ASF_OptLayout (*acceptWsAfterAmbs)(ASF_OptLayout));
ASF_CHARList ASF_visitCHARList(ASF_CHARList arg, ASF_CHAR (*acceptHead)(ASF_CHAR), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout));
ASF_Equation ASF_visitEquation(ASF_Equation arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquals)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree));
ASF_Condition ASF_visitCondition(ASF_Condition arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquals)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterUnequal)(ASF_OptLayout));
ASF_TreeAmbs ASF_visitTreeAmbs(ASF_TreeAmbs arg, ASF_Tree (*acceptHead)(ASF_Tree), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout), char * (*acceptSep)(char *), ASF_OptLayout (*acceptWsAfterSep)(ASF_OptLayout));
ASF_CHAR ASF_visitCHAR(ASF_CHAR arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST));
ASF_OptLayout ASF_visitOptLayout(ASF_OptLayout arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST));
ASF_Start ASF_visitStart(ASF_Start arg, ASF_OptLayout (*acceptWsBefore)(ASF_OptLayout), ASF_Equations (*acceptTopEquations)(ASF_Equations), ASF_OptLayout (*acceptWsAfter)(ASF_OptLayout), int (*acceptAmbCnt)(int));

/*}}}  */

#endif /* _ASFME_H */
