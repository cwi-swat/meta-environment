#ifndef _ASFME_H
#define _ASFME_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "ASFME_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _ASF_OptLayout *ASF_OptLayout;
typedef struct _ASF_Layout *ASF_Layout;
typedef struct _ASF_LexLayoutList *ASF_LexLayoutList;
typedef struct _ASF_Tree *ASF_Tree;
typedef struct _ASF_ASFCondition *ASF_ASFCondition;
typedef struct _ASF_ASFConditions *ASF_ASFConditions;
typedef struct _ASF_ASFConditionList *ASF_ASFConditionList;
typedef struct _ASF_LexASFBarEnd *ASF_LexASFBarEnd;
typedef struct _ASF_ASFBarEnd *ASF_ASFBarEnd;
typedef struct _ASF_LexASFImplies *ASF_LexASFImplies;
typedef struct _ASF_ASFImplies *ASF_ASFImplies;
typedef struct _ASF_ASFConditionalEquation *ASF_ASFConditionalEquation;
typedef struct _ASF_ASFEquation *ASF_ASFEquation;
typedef struct _ASF_Start *ASF_Start;
typedef struct _ASF_ASFModule *ASF_ASFModule;
typedef struct _ASF_ASFSection *ASF_ASFSection;
typedef struct _ASF_ASFSectionList *ASF_ASFSectionList;
typedef struct _ASF_ASFConditionalEquationList *ASF_ASFConditionalEquationList;
typedef struct _ASF_ASFTestEquationTestList *ASF_ASFTestEquationTestList;
typedef struct _ASF_LexASFTagId *ASF_LexASFTagId;
typedef struct _ASF_ASFTagId *ASF_ASFTagId;
typedef struct _ASF_ASFTag *ASF_ASFTag;
typedef struct _ASF_ASFTestEquation *ASF_ASFTestEquation;
typedef struct _ASF_LexLayout *ASF_LexLayout;
typedef struct _ASF_LexNumChar *ASF_LexNumChar;
typedef struct _ASF_NumChar *ASF_NumChar;
typedef struct _ASF_LexShortChar *ASF_LexShortChar;
typedef struct _ASF_ShortChar *ASF_ShortChar;
typedef struct _ASF_Character *ASF_Character;

/*}}}  */

void ASF_initASFMEApi(void);

/*{{{  protect functions */

void ASF_protectOptLayout(ASF_OptLayout *arg);
void ASF_protectLayout(ASF_Layout *arg);
void ASF_protectLexLayoutList(ASF_LexLayoutList *arg);
void ASF_protectTree(ASF_Tree *arg);
void ASF_protectASFCondition(ASF_ASFCondition *arg);
void ASF_protectASFConditions(ASF_ASFConditions *arg);
void ASF_protectASFConditionList(ASF_ASFConditionList *arg);
void ASF_protectLexASFBarEnd(ASF_LexASFBarEnd *arg);
void ASF_protectASFBarEnd(ASF_ASFBarEnd *arg);
void ASF_protectLexASFImplies(ASF_LexASFImplies *arg);
void ASF_protectASFImplies(ASF_ASFImplies *arg);
void ASF_protectASFConditionalEquation(ASF_ASFConditionalEquation *arg);
void ASF_protectASFEquation(ASF_ASFEquation *arg);
void ASF_protectStart(ASF_Start *arg);
void ASF_protectASFModule(ASF_ASFModule *arg);
void ASF_protectASFSection(ASF_ASFSection *arg);
void ASF_protectASFSectionList(ASF_ASFSectionList *arg);
void ASF_protectASFConditionalEquationList(ASF_ASFConditionalEquationList *arg);
void ASF_protectASFTestEquationTestList(ASF_ASFTestEquationTestList *arg);
void ASF_protectLexASFTagId(ASF_LexASFTagId *arg);
void ASF_protectASFTagId(ASF_ASFTagId *arg);
void ASF_protectASFTag(ASF_ASFTag *arg);
void ASF_protectASFTestEquation(ASF_ASFTestEquation *arg);
void ASF_protectLexLayout(ASF_LexLayout *arg);
void ASF_protectLexNumChar(ASF_LexNumChar *arg);
void ASF_protectNumChar(ASF_NumChar *arg);
void ASF_protectLexShortChar(ASF_LexShortChar *arg);
void ASF_protectShortChar(ASF_ShortChar *arg);
void ASF_protectCharacter(ASF_Character *arg);

/*}}}  */
/*{{{  term conversion functions */

ASF_OptLayout ASF_OptLayoutFromTerm(ATerm t);
ATerm ASF_OptLayoutToTerm(ASF_OptLayout arg);
ASF_Layout ASF_LayoutFromTerm(ATerm t);
ATerm ASF_LayoutToTerm(ASF_Layout arg);
ASF_LexLayoutList ASF_LexLayoutListFromTerm(ATerm t);
ATerm ASF_LexLayoutListToTerm(ASF_LexLayoutList arg);
ASF_Tree ASF_TreeFromTerm(ATerm t);
ATerm ASF_TreeToTerm(ASF_Tree arg);
ASF_ASFCondition ASF_ASFConditionFromTerm(ATerm t);
ATerm ASF_ASFConditionToTerm(ASF_ASFCondition arg);
ASF_ASFConditions ASF_ASFConditionsFromTerm(ATerm t);
ATerm ASF_ASFConditionsToTerm(ASF_ASFConditions arg);
ASF_ASFConditionList ASF_ASFConditionListFromTerm(ATerm t);
ATerm ASF_ASFConditionListToTerm(ASF_ASFConditionList arg);
ASF_LexASFBarEnd ASF_LexASFBarEndFromTerm(ATerm t);
ATerm ASF_LexASFBarEndToTerm(ASF_LexASFBarEnd arg);
ASF_ASFBarEnd ASF_ASFBarEndFromTerm(ATerm t);
ATerm ASF_ASFBarEndToTerm(ASF_ASFBarEnd arg);
ASF_LexASFImplies ASF_LexASFImpliesFromTerm(ATerm t);
ATerm ASF_LexASFImpliesToTerm(ASF_LexASFImplies arg);
ASF_ASFImplies ASF_ASFImpliesFromTerm(ATerm t);
ATerm ASF_ASFImpliesToTerm(ASF_ASFImplies arg);
ASF_ASFConditionalEquation ASF_ASFConditionalEquationFromTerm(ATerm t);
ATerm ASF_ASFConditionalEquationToTerm(ASF_ASFConditionalEquation arg);
ASF_ASFEquation ASF_ASFEquationFromTerm(ATerm t);
ATerm ASF_ASFEquationToTerm(ASF_ASFEquation arg);
ASF_Start ASF_StartFromTerm(ATerm t);
ATerm ASF_StartToTerm(ASF_Start arg);
ASF_ASFModule ASF_ASFModuleFromTerm(ATerm t);
ATerm ASF_ASFModuleToTerm(ASF_ASFModule arg);
ASF_ASFSection ASF_ASFSectionFromTerm(ATerm t);
ATerm ASF_ASFSectionToTerm(ASF_ASFSection arg);
ASF_ASFSectionList ASF_ASFSectionListFromTerm(ATerm t);
ATerm ASF_ASFSectionListToTerm(ASF_ASFSectionList arg);
ASF_ASFConditionalEquationList ASF_ASFConditionalEquationListFromTerm(ATerm t);
ATerm ASF_ASFConditionalEquationListToTerm(ASF_ASFConditionalEquationList arg);
ASF_ASFTestEquationTestList ASF_ASFTestEquationTestListFromTerm(ATerm t);
ATerm ASF_ASFTestEquationTestListToTerm(ASF_ASFTestEquationTestList arg);
ASF_LexASFTagId ASF_LexASFTagIdFromTerm(ATerm t);
ATerm ASF_LexASFTagIdToTerm(ASF_LexASFTagId arg);
ASF_ASFTagId ASF_ASFTagIdFromTerm(ATerm t);
ATerm ASF_ASFTagIdToTerm(ASF_ASFTagId arg);
ASF_ASFTag ASF_ASFTagFromTerm(ATerm t);
ATerm ASF_ASFTagToTerm(ASF_ASFTag arg);
ASF_ASFTestEquation ASF_ASFTestEquationFromTerm(ATerm t);
ATerm ASF_ASFTestEquationToTerm(ASF_ASFTestEquation arg);
ASF_LexLayout ASF_LexLayoutFromTerm(ATerm t);
ATerm ASF_LexLayoutToTerm(ASF_LexLayout arg);
ASF_LexNumChar ASF_LexNumCharFromTerm(ATerm t);
ATerm ASF_LexNumCharToTerm(ASF_LexNumChar arg);
ASF_NumChar ASF_NumCharFromTerm(ATerm t);
ATerm ASF_NumCharToTerm(ASF_NumChar arg);
ASF_LexShortChar ASF_LexShortCharFromTerm(ATerm t);
ATerm ASF_LexShortCharToTerm(ASF_LexShortChar arg);
ASF_ShortChar ASF_ShortCharFromTerm(ATerm t);
ATerm ASF_ShortCharToTerm(ASF_ShortChar arg);
ASF_Character ASF_CharacterFromTerm(ATerm t);
ATerm ASF_CharacterToTerm(ASF_Character arg);

/*}}}  */
/*{{{  list functions */

int ASF_getLexLayoutListLength (ASF_LexLayoutList arg);
ASF_LexLayoutList ASF_reverseLexLayoutList(ASF_LexLayoutList arg);
ASF_LexLayoutList ASF_appendLexLayoutList(ASF_LexLayoutList arg, ASF_LexLayout elem);
ASF_LexLayoutList ASF_concatLexLayoutList(ASF_LexLayoutList arg0, ASF_LexLayoutList arg1);
ASF_LexLayoutList ASF_sliceLexLayoutList(ASF_LexLayoutList arg, int start, int end);
ASF_LexLayout ASF_getLexLayoutListLexLayoutAt(ASF_LexLayoutList arg, int index);
ASF_LexLayoutList ASF_replaceLexLayoutListLexLayoutAt(ASF_LexLayoutList arg, ASF_LexLayout elem, int index);
ASF_LexLayoutList ASF_makeLexLayoutList2(ASF_LexLayout elem1, ASF_LexLayout elem2);
ASF_LexLayoutList ASF_makeLexLayoutList3(ASF_LexLayout elem1, ASF_LexLayout elem2, ASF_LexLayout elem3);
ASF_LexLayoutList ASF_makeLexLayoutList4(ASF_LexLayout elem1, ASF_LexLayout elem2, ASF_LexLayout elem3, ASF_LexLayout elem4);
ASF_LexLayoutList ASF_makeLexLayoutList5(ASF_LexLayout elem1, ASF_LexLayout elem2, ASF_LexLayout elem3, ASF_LexLayout elem4, ASF_LexLayout elem5);
ASF_LexLayoutList ASF_makeLexLayoutList6(ASF_LexLayout elem1, ASF_LexLayout elem2, ASF_LexLayout elem3, ASF_LexLayout elem4, ASF_LexLayout elem5, ASF_LexLayout elem6);
int ASF_getASFConditionListLength (ASF_ASFConditionList arg);
ASF_ASFConditionList ASF_reverseASFConditionList(ASF_ASFConditionList arg);
ASF_ASFConditionList ASF_appendASFConditionList(ASF_ASFConditionList arg0, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition arg1);
ASF_ASFConditionList ASF_concatASFConditionList(ASF_ASFConditionList arg0, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFConditionList arg1);
ASF_ASFConditionList ASF_sliceASFConditionList(ASF_ASFConditionList arg, int start, int end);
ASF_ASFCondition ASF_getASFConditionListASFConditionAt(ASF_ASFConditionList arg, int index);
ASF_ASFConditionList ASF_replaceASFConditionListASFConditionAt(ASF_ASFConditionList arg, ASF_ASFCondition elem, int index);
ASF_ASFConditionList ASF_makeASFConditionList2(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition elem1, ASF_ASFCondition elem2);
ASF_ASFConditionList ASF_makeASFConditionList3(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition elem1, ASF_ASFCondition elem2, ASF_ASFCondition elem3);
ASF_ASFConditionList ASF_makeASFConditionList4(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition elem1, ASF_ASFCondition elem2, ASF_ASFCondition elem3, ASF_ASFCondition elem4);
ASF_ASFConditionList ASF_makeASFConditionList5(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition elem1, ASF_ASFCondition elem2, ASF_ASFCondition elem3, ASF_ASFCondition elem4, ASF_ASFCondition elem5);
ASF_ASFConditionList ASF_makeASFConditionList6(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition elem1, ASF_ASFCondition elem2, ASF_ASFCondition elem3, ASF_ASFCondition elem4, ASF_ASFCondition elem5, ASF_ASFCondition elem6);
int ASF_getASFSectionListLength (ASF_ASFSectionList arg);
ASF_ASFSectionList ASF_reverseASFSectionList(ASF_ASFSectionList arg);
ASF_ASFSectionList ASF_appendASFSectionList(ASF_ASFSectionList arg0, ASF_OptLayout wsAfterHead, ASF_ASFSection arg1);
ASF_ASFSectionList ASF_concatASFSectionList(ASF_ASFSectionList arg0, ASF_OptLayout wsAfterHead, ASF_ASFSectionList arg1);
ASF_ASFSectionList ASF_sliceASFSectionList(ASF_ASFSectionList arg, int start, int end);
ASF_ASFSection ASF_getASFSectionListASFSectionAt(ASF_ASFSectionList arg, int index);
ASF_ASFSectionList ASF_replaceASFSectionListASFSectionAt(ASF_ASFSectionList arg, ASF_ASFSection elem, int index);
ASF_ASFSectionList ASF_makeASFSectionList2(ASF_OptLayout wsAfterHead, ASF_ASFSection elem1, ASF_ASFSection elem2);
ASF_ASFSectionList ASF_makeASFSectionList3(ASF_OptLayout wsAfterHead, ASF_ASFSection elem1, ASF_ASFSection elem2, ASF_ASFSection elem3);
ASF_ASFSectionList ASF_makeASFSectionList4(ASF_OptLayout wsAfterHead, ASF_ASFSection elem1, ASF_ASFSection elem2, ASF_ASFSection elem3, ASF_ASFSection elem4);
ASF_ASFSectionList ASF_makeASFSectionList5(ASF_OptLayout wsAfterHead, ASF_ASFSection elem1, ASF_ASFSection elem2, ASF_ASFSection elem3, ASF_ASFSection elem4, ASF_ASFSection elem5);
ASF_ASFSectionList ASF_makeASFSectionList6(ASF_OptLayout wsAfterHead, ASF_ASFSection elem1, ASF_ASFSection elem2, ASF_ASFSection elem3, ASF_ASFSection elem4, ASF_ASFSection elem5, ASF_ASFSection elem6);
int ASF_getASFConditionalEquationListLength (ASF_ASFConditionalEquationList arg);
ASF_ASFConditionalEquationList ASF_reverseASFConditionalEquationList(ASF_ASFConditionalEquationList arg);
ASF_ASFConditionalEquationList ASF_appendASFConditionalEquationList(ASF_ASFConditionalEquationList arg0, ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation arg1);
ASF_ASFConditionalEquationList ASF_concatASFConditionalEquationList(ASF_ASFConditionalEquationList arg0, ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquationList arg1);
ASF_ASFConditionalEquationList ASF_sliceASFConditionalEquationList(ASF_ASFConditionalEquationList arg, int start, int end);
ASF_ASFConditionalEquation ASF_getASFConditionalEquationListASFConditionalEquationAt(ASF_ASFConditionalEquationList arg, int index);
ASF_ASFConditionalEquationList ASF_replaceASFConditionalEquationListASFConditionalEquationAt(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation elem, int index);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList2(ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation elem1, ASF_ASFConditionalEquation elem2);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList3(ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation elem1, ASF_ASFConditionalEquation elem2, ASF_ASFConditionalEquation elem3);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList4(ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation elem1, ASF_ASFConditionalEquation elem2, ASF_ASFConditionalEquation elem3, ASF_ASFConditionalEquation elem4);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList5(ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation elem1, ASF_ASFConditionalEquation elem2, ASF_ASFConditionalEquation elem3, ASF_ASFConditionalEquation elem4, ASF_ASFConditionalEquation elem5);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList6(ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation elem1, ASF_ASFConditionalEquation elem2, ASF_ASFConditionalEquation elem3, ASF_ASFConditionalEquation elem4, ASF_ASFConditionalEquation elem5, ASF_ASFConditionalEquation elem6);
int ASF_getASFTestEquationTestListLength (ASF_ASFTestEquationTestList arg);
ASF_ASFTestEquationTestList ASF_reverseASFTestEquationTestList(ASF_ASFTestEquationTestList arg);
ASF_ASFTestEquationTestList ASF_appendASFTestEquationTestList(ASF_ASFTestEquationTestList arg0, ASF_OptLayout wsAfterHead, ASF_ASFTestEquation arg1);
ASF_ASFTestEquationTestList ASF_concatASFTestEquationTestList(ASF_ASFTestEquationTestList arg0, ASF_OptLayout wsAfterHead, ASF_ASFTestEquationTestList arg1);
ASF_ASFTestEquationTestList ASF_sliceASFTestEquationTestList(ASF_ASFTestEquationTestList arg, int start, int end);
ASF_ASFTestEquation ASF_getASFTestEquationTestListASFTestEquationAt(ASF_ASFTestEquationTestList arg, int index);
ASF_ASFTestEquationTestList ASF_replaceASFTestEquationTestListASFTestEquationAt(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquation elem, int index);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestList2(ASF_OptLayout wsAfterHead, ASF_ASFTestEquation elem1, ASF_ASFTestEquation elem2);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestList3(ASF_OptLayout wsAfterHead, ASF_ASFTestEquation elem1, ASF_ASFTestEquation elem2, ASF_ASFTestEquation elem3);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestList4(ASF_OptLayout wsAfterHead, ASF_ASFTestEquation elem1, ASF_ASFTestEquation elem2, ASF_ASFTestEquation elem3, ASF_ASFTestEquation elem4);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestList5(ASF_OptLayout wsAfterHead, ASF_ASFTestEquation elem1, ASF_ASFTestEquation elem2, ASF_ASFTestEquation elem3, ASF_ASFTestEquation elem4, ASF_ASFTestEquation elem5);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestList6(ASF_OptLayout wsAfterHead, ASF_ASFTestEquation elem1, ASF_ASFTestEquation elem2, ASF_ASFTestEquation elem3, ASF_ASFTestEquation elem4, ASF_ASFTestEquation elem5, ASF_ASFTestEquation elem6);

/*}}}  */
/*{{{  constructors */

ASF_OptLayout ASF_makeOptLayoutAbsent(void);
ASF_OptLayout ASF_makeOptLayoutPresent(ASF_Layout layout);
ASF_Layout ASF_makeLayoutLexToCf(ASF_LexLayoutList list);
ASF_LexLayoutList ASF_makeLexLayoutListEmpty(void);
ASF_LexLayoutList ASF_makeLexLayoutListSingle(ASF_LexLayout head);
ASF_LexLayoutList ASF_makeLexLayoutListMany(ASF_LexLayout head, ASF_LexLayoutList tail);
ASF_Tree ASF_makeTreeCast(ATerm Tree);
ASF_ASFCondition ASF_makeASFConditionNegative(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterUnequal, ASF_Tree rhs);
ASF_ASFCondition ASF_makeASFConditionEquality(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquality, ASF_Tree rhs);
ASF_ASFCondition ASF_makeASFConditionMatch(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterMatch, ASF_Tree rhs);
ASF_ASFCondition ASF_makeASFConditionNoMatch(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterMatch, ASF_Tree rhs);
ASF_ASFConditions ASF_makeASFConditionsDefault(ASF_ASFConditionList list);
ASF_ASFConditionList ASF_makeASFConditionListEmpty(void);
ASF_ASFConditionList ASF_makeASFConditionListSingle(ASF_ASFCondition head);
ASF_ASFConditionList ASF_makeASFConditionListMany(ASF_ASFCondition head, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFConditionList tail);
ASF_LexASFBarEnd ASF_makeLexASFBarEndAbsent(void);
ASF_LexASFBarEnd ASF_makeLexASFBarEndPresent(void);
ASF_ASFBarEnd ASF_makeASFBarEndLexToCf(ASF_LexASFBarEnd ASFBarEnd);
ASF_LexASFImplies ASF_makeLexASFImpliesDefault(const char* bar, ASF_LexASFBarEnd end);
ASF_ASFImplies ASF_makeASFImpliesLexToCf(ASF_LexASFImplies ASFImplies);
ASF_ASFConditionalEquation ASF_makeASFConditionalEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation);
ASF_ASFConditionalEquation ASF_makeASFConditionalEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFEquation ASFEquation);
ASF_ASFConditionalEquation ASF_makeASFConditionalEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation, ASF_OptLayout wsAfterASFEquation, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions);
ASF_ASFEquation ASF_makeASFEquationDefault(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquals, ASF_Tree rhs);
ASF_Start ASF_makeStartASFModule(ASF_OptLayout wsBefore, ASF_ASFModule topASFModule, ASF_OptLayout wsAfter, int ambCnt);
ASF_Start ASF_makeStartASFSection(ASF_OptLayout wsBefore, ASF_ASFSection topASFSection, ASF_OptLayout wsAfter, int ambCnt);
ASF_ASFModule ASF_makeASFModuleDefault(ASF_ASFSectionList list);
ASF_ASFSection ASF_makeASFSectionEquations(ASF_OptLayout wsAfterEquations, ASF_ASFConditionalEquationList list);
ASF_ASFSection ASF_makeASFSectionTests(ASF_OptLayout wsAfterTests, ASF_ASFTestEquationTestList testList);
ASF_ASFSectionList ASF_makeASFSectionListEmpty(void);
ASF_ASFSectionList ASF_makeASFSectionListSingle(ASF_ASFSection head);
ASF_ASFSectionList ASF_makeASFSectionListMany(ASF_ASFSection head, ASF_OptLayout wsAfterHead, ASF_ASFSectionList tail);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListEmpty(void);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListSingle(ASF_ASFConditionalEquation head);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListMany(ASF_ASFConditionalEquation head, ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquationList tail);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestListEmpty(void);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestListSingle(ASF_ASFTestEquation head);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestListMany(ASF_ASFTestEquation head, ASF_OptLayout wsAfterHead, ASF_ASFTestEquationTestList tail);
ASF_LexASFTagId ASF_makeLexASFTagIdOneChar(char head);
ASF_LexASFTagId ASF_makeLexASFTagIdManyChars(char head, const char* middle, char last);
ASF_ASFTagId ASF_makeASFTagIdLexToCf(ASF_LexASFTagId ASFTagId);
ASF_ASFTag ASF_makeASFTagEmpty(ASF_OptLayout wsAfterBracketOpen);
ASF_ASFTag ASF_makeASFTagNotEmpty(ASF_OptLayout wsAfterBracketOpen, ASF_ASFTagId ASFTagId, ASF_OptLayout wsAfterASFTagId);
ASF_ASFTestEquation ASF_makeASFTestEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFCondition ASFCondition);
ASF_ASFTestEquation ASF_makeASFTestEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFCondition ASFCondition);
ASF_ASFTestEquation ASF_makeASFTestEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFCondition ASFCondition, ASF_OptLayout wsAfterASFCondition, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions);
ASF_LexLayout ASF_makeLexLayoutWhitespace(char ch);
ASF_LexNumChar ASF_makeLexNumCharDigits(const char* number);
ASF_NumChar ASF_makeNumCharLexToCf(ASF_LexNumChar NumChar);
ASF_LexShortChar ASF_makeLexShortCharRegular(char character);
ASF_LexShortChar ASF_makeLexShortCharEscaped(char escape);
ASF_ShortChar ASF_makeShortCharLexToCf(ASF_LexShortChar ShortChar);
ASF_Character ASF_makeCharacterNumeric(ASF_NumChar NumChar);
ASF_Character ASF_makeCharacterShort(ASF_ShortChar ShortChar);
ASF_Character ASF_makeCharacterTop(void);
ASF_Character ASF_makeCharacterEof(void);
ASF_Character ASF_makeCharacterBot(void);
ASF_Character ASF_makeCharacterLabelUnderscoreStart(void);

/*}}}  */
/*{{{  equality functions */

ATbool ASF_isEqualOptLayout(ASF_OptLayout arg0, ASF_OptLayout arg1);
ATbool ASF_isEqualLayout(ASF_Layout arg0, ASF_Layout arg1);
ATbool ASF_isEqualLexLayoutList(ASF_LexLayoutList arg0, ASF_LexLayoutList arg1);
ATbool ASF_isEqualTree(ASF_Tree arg0, ASF_Tree arg1);
ATbool ASF_isEqualASFCondition(ASF_ASFCondition arg0, ASF_ASFCondition arg1);
ATbool ASF_isEqualASFConditions(ASF_ASFConditions arg0, ASF_ASFConditions arg1);
ATbool ASF_isEqualASFConditionList(ASF_ASFConditionList arg0, ASF_ASFConditionList arg1);
ATbool ASF_isEqualLexASFBarEnd(ASF_LexASFBarEnd arg0, ASF_LexASFBarEnd arg1);
ATbool ASF_isEqualASFBarEnd(ASF_ASFBarEnd arg0, ASF_ASFBarEnd arg1);
ATbool ASF_isEqualLexASFImplies(ASF_LexASFImplies arg0, ASF_LexASFImplies arg1);
ATbool ASF_isEqualASFImplies(ASF_ASFImplies arg0, ASF_ASFImplies arg1);
ATbool ASF_isEqualASFConditionalEquation(ASF_ASFConditionalEquation arg0, ASF_ASFConditionalEquation arg1);
ATbool ASF_isEqualASFEquation(ASF_ASFEquation arg0, ASF_ASFEquation arg1);
ATbool ASF_isEqualStart(ASF_Start arg0, ASF_Start arg1);
ATbool ASF_isEqualASFModule(ASF_ASFModule arg0, ASF_ASFModule arg1);
ATbool ASF_isEqualASFSection(ASF_ASFSection arg0, ASF_ASFSection arg1);
ATbool ASF_isEqualASFSectionList(ASF_ASFSectionList arg0, ASF_ASFSectionList arg1);
ATbool ASF_isEqualASFConditionalEquationList(ASF_ASFConditionalEquationList arg0, ASF_ASFConditionalEquationList arg1);
ATbool ASF_isEqualASFTestEquationTestList(ASF_ASFTestEquationTestList arg0, ASF_ASFTestEquationTestList arg1);
ATbool ASF_isEqualLexASFTagId(ASF_LexASFTagId arg0, ASF_LexASFTagId arg1);
ATbool ASF_isEqualASFTagId(ASF_ASFTagId arg0, ASF_ASFTagId arg1);
ATbool ASF_isEqualASFTag(ASF_ASFTag arg0, ASF_ASFTag arg1);
ATbool ASF_isEqualASFTestEquation(ASF_ASFTestEquation arg0, ASF_ASFTestEquation arg1);
ATbool ASF_isEqualLexLayout(ASF_LexLayout arg0, ASF_LexLayout arg1);
ATbool ASF_isEqualLexNumChar(ASF_LexNumChar arg0, ASF_LexNumChar arg1);
ATbool ASF_isEqualNumChar(ASF_NumChar arg0, ASF_NumChar arg1);
ATbool ASF_isEqualLexShortChar(ASF_LexShortChar arg0, ASF_LexShortChar arg1);
ATbool ASF_isEqualShortChar(ASF_ShortChar arg0, ASF_ShortChar arg1);
ATbool ASF_isEqualCharacter(ASF_Character arg0, ASF_Character arg1);

/*}}}  */
/*{{{  ASF_OptLayout accessors */

ATbool ASF_isValidOptLayout(ASF_OptLayout arg);
inline ATbool ASF_isOptLayoutAbsent(ASF_OptLayout arg);
inline ATbool ASF_isOptLayoutPresent(ASF_OptLayout arg);
ATbool ASF_hasOptLayoutLayout(ASF_OptLayout arg);
ASF_Layout ASF_getOptLayoutLayout(ASF_OptLayout arg);
ASF_OptLayout ASF_setOptLayoutLayout(ASF_OptLayout arg, ASF_Layout layout);

/*}}}  */
/*{{{  ASF_Layout accessors */

ATbool ASF_isValidLayout(ASF_Layout arg);
inline ATbool ASF_isLayoutLexToCf(ASF_Layout arg);
ATbool ASF_hasLayoutList(ASF_Layout arg);
ASF_LexLayoutList ASF_getLayoutList(ASF_Layout arg);
ASF_Layout ASF_setLayoutList(ASF_Layout arg, ASF_LexLayoutList list);

/*}}}  */
/*{{{  ASF_LexLayoutList accessors */

ATbool ASF_isValidLexLayoutList(ASF_LexLayoutList arg);
inline ATbool ASF_isLexLayoutListEmpty(ASF_LexLayoutList arg);
inline ATbool ASF_isLexLayoutListSingle(ASF_LexLayoutList arg);
inline ATbool ASF_isLexLayoutListMany(ASF_LexLayoutList arg);
ATbool ASF_hasLexLayoutListHead(ASF_LexLayoutList arg);
ATbool ASF_hasLexLayoutListTail(ASF_LexLayoutList arg);
ASF_LexLayout ASF_getLexLayoutListHead(ASF_LexLayoutList arg);
ASF_LexLayoutList ASF_getLexLayoutListTail(ASF_LexLayoutList arg);
ASF_LexLayoutList ASF_setLexLayoutListHead(ASF_LexLayoutList arg, ASF_LexLayout head);
ASF_LexLayoutList ASF_setLexLayoutListTail(ASF_LexLayoutList arg, ASF_LexLayoutList tail);

/*}}}  */
/*{{{  ASF_Tree accessors */

ATbool ASF_isValidTree(ASF_Tree arg);
inline ATbool ASF_isTreeCast(ASF_Tree arg);
ATbool ASF_hasTreeTree(ASF_Tree arg);
ATerm ASF_getTreeTree(ASF_Tree arg);
ASF_Tree ASF_setTreeTree(ASF_Tree arg, ATerm Tree);

/*}}}  */
/*{{{  ASF_ASFCondition accessors */

ATbool ASF_isValidASFCondition(ASF_ASFCondition arg);
inline ATbool ASF_isASFConditionNegative(ASF_ASFCondition arg);
inline ATbool ASF_isASFConditionEquality(ASF_ASFCondition arg);
inline ATbool ASF_isASFConditionMatch(ASF_ASFCondition arg);
inline ATbool ASF_isASFConditionNoMatch(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionTypeOfLhs(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionTypeOfRhs(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionLhs(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionWsAfterLhs(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionWsAfterUnequal(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionRhs(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionWsAfterEquality(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionWsAfterMatch(ASF_ASFCondition arg);
ATerm ASF_getASFConditionTypeOfLhs(ASF_ASFCondition arg);
ATerm ASF_getASFConditionTypeOfRhs(ASF_ASFCondition arg);
ASF_Tree ASF_getASFConditionLhs(ASF_ASFCondition arg);
ASF_OptLayout ASF_getASFConditionWsAfterLhs(ASF_ASFCondition arg);
ASF_OptLayout ASF_getASFConditionWsAfterUnequal(ASF_ASFCondition arg);
ASF_Tree ASF_getASFConditionRhs(ASF_ASFCondition arg);
ASF_OptLayout ASF_getASFConditionWsAfterEquality(ASF_ASFCondition arg);
ASF_OptLayout ASF_getASFConditionWsAfterMatch(ASF_ASFCondition arg);
ASF_ASFCondition ASF_setASFConditionTypeOfLhs(ASF_ASFCondition arg, ATerm typeOfLhs);
ASF_ASFCondition ASF_setASFConditionTypeOfRhs(ASF_ASFCondition arg, ATerm typeOfRhs);
ASF_ASFCondition ASF_setASFConditionLhs(ASF_ASFCondition arg, ASF_Tree lhs);
ASF_ASFCondition ASF_setASFConditionWsAfterLhs(ASF_ASFCondition arg, ASF_OptLayout wsAfterLhs);
ASF_ASFCondition ASF_setASFConditionWsAfterUnequal(ASF_ASFCondition arg, ASF_OptLayout wsAfterUnequal);
ASF_ASFCondition ASF_setASFConditionRhs(ASF_ASFCondition arg, ASF_Tree rhs);
ASF_ASFCondition ASF_setASFConditionWsAfterEquality(ASF_ASFCondition arg, ASF_OptLayout wsAfterEquality);
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
inline ATbool ASF_isASFConditionListEmpty(ASF_ASFConditionList arg);
inline ATbool ASF_isASFConditionListSingle(ASF_ASFConditionList arg);
inline ATbool ASF_isASFConditionListMany(ASF_ASFConditionList arg);
ATbool ASF_hasASFConditionListHead(ASF_ASFConditionList arg);
ATbool ASF_hasASFConditionListWsAfterHead(ASF_ASFConditionList arg);
ATbool ASF_hasASFConditionListWsAfterSep(ASF_ASFConditionList arg);
ATbool ASF_hasASFConditionListTail(ASF_ASFConditionList arg);
ASF_ASFConditionList ASF_getASFConditionListTail(ASF_ASFConditionList arg);
ASF_ASFCondition ASF_getASFConditionListHead(ASF_ASFConditionList arg);
ASF_OptLayout ASF_getASFConditionListWsAfterHead(ASF_ASFConditionList arg);
ASF_OptLayout ASF_getASFConditionListWsAfterSep(ASF_ASFConditionList arg);
ASF_ASFConditionList ASF_setASFConditionListHead(ASF_ASFConditionList arg, ASF_ASFCondition head);
ASF_ASFConditionList ASF_setASFConditionListWsAfterHead(ASF_ASFConditionList arg, ASF_OptLayout wsAfterHead);
ASF_ASFConditionList ASF_setASFConditionListWsAfterSep(ASF_ASFConditionList arg, ASF_OptLayout wsAfterSep);
ASF_ASFConditionList ASF_setASFConditionListTail(ASF_ASFConditionList arg, ASF_ASFConditionList tail);

/*}}}  */
/*{{{  ASF_LexASFBarEnd accessors */

ATbool ASF_isValidLexASFBarEnd(ASF_LexASFBarEnd arg);
inline ATbool ASF_isLexASFBarEndAbsent(ASF_LexASFBarEnd arg);
inline ATbool ASF_isLexASFBarEndPresent(ASF_LexASFBarEnd arg);

/*}}}  */
/*{{{  ASF_ASFBarEnd accessors */

ATbool ASF_isValidASFBarEnd(ASF_ASFBarEnd arg);
inline ATbool ASF_isASFBarEndLexToCf(ASF_ASFBarEnd arg);
ATbool ASF_hasASFBarEndASFBarEnd(ASF_ASFBarEnd arg);
ASF_LexASFBarEnd ASF_getASFBarEndASFBarEnd(ASF_ASFBarEnd arg);
ASF_ASFBarEnd ASF_setASFBarEndASFBarEnd(ASF_ASFBarEnd arg, ASF_LexASFBarEnd ASFBarEnd);

/*}}}  */
/*{{{  ASF_LexASFImplies accessors */

ATbool ASF_isValidLexASFImplies(ASF_LexASFImplies arg);
inline ATbool ASF_isLexASFImpliesDefault(ASF_LexASFImplies arg);
ATbool ASF_hasLexASFImpliesBar(ASF_LexASFImplies arg);
ATbool ASF_hasLexASFImpliesEnd(ASF_LexASFImplies arg);
char* ASF_getLexASFImpliesBar(ASF_LexASFImplies arg);
ASF_LexASFBarEnd ASF_getLexASFImpliesEnd(ASF_LexASFImplies arg);
ASF_LexASFImplies ASF_setLexASFImpliesBar(ASF_LexASFImplies arg, const char* bar);
ASF_LexASFImplies ASF_setLexASFImpliesEnd(ASF_LexASFImplies arg, ASF_LexASFBarEnd end);

/*}}}  */
/*{{{  ASF_ASFImplies accessors */

ATbool ASF_isValidASFImplies(ASF_ASFImplies arg);
inline ATbool ASF_isASFImpliesLexToCf(ASF_ASFImplies arg);
ATbool ASF_hasASFImpliesASFImplies(ASF_ASFImplies arg);
ASF_LexASFImplies ASF_getASFImpliesASFImplies(ASF_ASFImplies arg);
ASF_ASFImplies ASF_setASFImpliesASFImplies(ASF_ASFImplies arg, ASF_LexASFImplies ASFImplies);

/*}}}  */
/*{{{  ASF_ASFConditionalEquation accessors */

ATbool ASF_isValidASFConditionalEquation(ASF_ASFConditionalEquation arg);
inline ATbool ASF_isASFConditionalEquationSimple(ASF_ASFConditionalEquation arg);
inline ATbool ASF_isASFConditionalEquationImplies(ASF_ASFConditionalEquation arg);
inline ATbool ASF_isASFConditionalEquationWhen(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg);
ASF_ASFTag ASF_getASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg);
ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg);
ASF_ASFEquation ASF_getASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg);
ASF_ASFConditions ASF_getASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg);
ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg);
ASF_ASFImplies ASF_getASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg);
ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg);
ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg);
ASF_OptLayout ASF_getASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg, ASF_ASFTag ASFTag);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFTag);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg, ASF_ASFEquation ASFEquation);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg, ASF_ASFConditions ASFConditions);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFConditions);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg, ASF_ASFImplies ASFImplies);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFImplies);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFEquation);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterWhen);

/*}}}  */
/*{{{  ASF_ASFEquation accessors */

ATbool ASF_isValidASFEquation(ASF_ASFEquation arg);
inline ATbool ASF_isASFEquationDefault(ASF_ASFEquation arg);
ATbool ASF_hasASFEquationTypeOfLhs(ASF_ASFEquation arg);
ATbool ASF_hasASFEquationTypeOfRhs(ASF_ASFEquation arg);
ATbool ASF_hasASFEquationLhs(ASF_ASFEquation arg);
ATbool ASF_hasASFEquationWsAfterLhs(ASF_ASFEquation arg);
ATbool ASF_hasASFEquationWsAfterEquals(ASF_ASFEquation arg);
ATbool ASF_hasASFEquationRhs(ASF_ASFEquation arg);
ATerm ASF_getASFEquationTypeOfLhs(ASF_ASFEquation arg);
ATerm ASF_getASFEquationTypeOfRhs(ASF_ASFEquation arg);
ASF_Tree ASF_getASFEquationLhs(ASF_ASFEquation arg);
ASF_OptLayout ASF_getASFEquationWsAfterLhs(ASF_ASFEquation arg);
ASF_OptLayout ASF_getASFEquationWsAfterEquals(ASF_ASFEquation arg);
ASF_Tree ASF_getASFEquationRhs(ASF_ASFEquation arg);
ASF_ASFEquation ASF_setASFEquationTypeOfLhs(ASF_ASFEquation arg, ATerm typeOfLhs);
ASF_ASFEquation ASF_setASFEquationTypeOfRhs(ASF_ASFEquation arg, ATerm typeOfRhs);
ASF_ASFEquation ASF_setASFEquationLhs(ASF_ASFEquation arg, ASF_Tree lhs);
ASF_ASFEquation ASF_setASFEquationWsAfterLhs(ASF_ASFEquation arg, ASF_OptLayout wsAfterLhs);
ASF_ASFEquation ASF_setASFEquationWsAfterEquals(ASF_ASFEquation arg, ASF_OptLayout wsAfterEquals);
ASF_ASFEquation ASF_setASFEquationRhs(ASF_ASFEquation arg, ASF_Tree rhs);

/*}}}  */
/*{{{  ASF_Start accessors */

ATbool ASF_isValidStart(ASF_Start arg);
inline ATbool ASF_isStartASFModule(ASF_Start arg);
inline ATbool ASF_isStartASFSection(ASF_Start arg);
ATbool ASF_hasStartWsBefore(ASF_Start arg);
ATbool ASF_hasStartTopASFModule(ASF_Start arg);
ATbool ASF_hasStartWsAfter(ASF_Start arg);
ATbool ASF_hasStartAmbCnt(ASF_Start arg);
ATbool ASF_hasStartTopASFSection(ASF_Start arg);
ASF_OptLayout ASF_getStartWsBefore(ASF_Start arg);
ASF_ASFModule ASF_getStartTopASFModule(ASF_Start arg);
ASF_OptLayout ASF_getStartWsAfter(ASF_Start arg);
int ASF_getStartAmbCnt(ASF_Start arg);
ASF_ASFSection ASF_getStartTopASFSection(ASF_Start arg);
ASF_Start ASF_setStartWsBefore(ASF_Start arg, ASF_OptLayout wsBefore);
ASF_Start ASF_setStartTopASFModule(ASF_Start arg, ASF_ASFModule topASFModule);
ASF_Start ASF_setStartWsAfter(ASF_Start arg, ASF_OptLayout wsAfter);
ASF_Start ASF_setStartAmbCnt(ASF_Start arg, int ambCnt);
ASF_Start ASF_setStartTopASFSection(ASF_Start arg, ASF_ASFSection topASFSection);

/*}}}  */
/*{{{  ASF_ASFModule accessors */

ATbool ASF_isValidASFModule(ASF_ASFModule arg);
inline ATbool ASF_isASFModuleDefault(ASF_ASFModule arg);
ATbool ASF_hasASFModuleList(ASF_ASFModule arg);
ASF_ASFSectionList ASF_getASFModuleList(ASF_ASFModule arg);
ASF_ASFModule ASF_setASFModuleList(ASF_ASFModule arg, ASF_ASFSectionList list);

/*}}}  */
/*{{{  ASF_ASFSection accessors */

ATbool ASF_isValidASFSection(ASF_ASFSection arg);
inline ATbool ASF_isASFSectionEquations(ASF_ASFSection arg);
inline ATbool ASF_isASFSectionTests(ASF_ASFSection arg);
ATbool ASF_hasASFSectionWsAfterEquations(ASF_ASFSection arg);
ATbool ASF_hasASFSectionList(ASF_ASFSection arg);
ATbool ASF_hasASFSectionWsAfterTests(ASF_ASFSection arg);
ATbool ASF_hasASFSectionTestList(ASF_ASFSection arg);
ASF_OptLayout ASF_getASFSectionWsAfterEquations(ASF_ASFSection arg);
ASF_ASFConditionalEquationList ASF_getASFSectionList(ASF_ASFSection arg);
ASF_OptLayout ASF_getASFSectionWsAfterTests(ASF_ASFSection arg);
ASF_ASFTestEquationTestList ASF_getASFSectionTestList(ASF_ASFSection arg);
ASF_ASFSection ASF_setASFSectionWsAfterEquations(ASF_ASFSection arg, ASF_OptLayout wsAfterEquations);
ASF_ASFSection ASF_setASFSectionList(ASF_ASFSection arg, ASF_ASFConditionalEquationList list);
ASF_ASFSection ASF_setASFSectionWsAfterTests(ASF_ASFSection arg, ASF_OptLayout wsAfterTests);
ASF_ASFSection ASF_setASFSectionTestList(ASF_ASFSection arg, ASF_ASFTestEquationTestList testList);

/*}}}  */
/*{{{  ASF_ASFSectionList accessors */

ATbool ASF_isValidASFSectionList(ASF_ASFSectionList arg);
inline ATbool ASF_isASFSectionListEmpty(ASF_ASFSectionList arg);
inline ATbool ASF_isASFSectionListSingle(ASF_ASFSectionList arg);
inline ATbool ASF_isASFSectionListMany(ASF_ASFSectionList arg);
ATbool ASF_hasASFSectionListHead(ASF_ASFSectionList arg);
ATbool ASF_hasASFSectionListWsAfterHead(ASF_ASFSectionList arg);
ATbool ASF_hasASFSectionListTail(ASF_ASFSectionList arg);
ASF_ASFSectionList ASF_getASFSectionListTail(ASF_ASFSectionList arg);
ASF_ASFSection ASF_getASFSectionListHead(ASF_ASFSectionList arg);
ASF_OptLayout ASF_getASFSectionListWsAfterHead(ASF_ASFSectionList arg);
ASF_ASFSectionList ASF_setASFSectionListHead(ASF_ASFSectionList arg, ASF_ASFSection head);
ASF_ASFSectionList ASF_setASFSectionListWsAfterHead(ASF_ASFSectionList arg, ASF_OptLayout wsAfterHead);
ASF_ASFSectionList ASF_setASFSectionListTail(ASF_ASFSectionList arg, ASF_ASFSectionList tail);

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList accessors */

ATbool ASF_isValidASFConditionalEquationList(ASF_ASFConditionalEquationList arg);
inline ATbool ASF_isASFConditionalEquationListEmpty(ASF_ASFConditionalEquationList arg);
inline ATbool ASF_isASFConditionalEquationListSingle(ASF_ASFConditionalEquationList arg);
inline ATbool ASF_isASFConditionalEquationListMany(ASF_ASFConditionalEquationList arg);
ATbool ASF_hasASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg);
ATbool ASF_hasASFConditionalEquationListWsAfterHead(ASF_ASFConditionalEquationList arg);
ATbool ASF_hasASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg);
ASF_ASFConditionalEquationList ASF_getASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg);
ASF_ASFConditionalEquation ASF_getASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg);
ASF_OptLayout ASF_getASFConditionalEquationListWsAfterHead(ASF_ASFConditionalEquationList arg);
ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation head);
ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListWsAfterHead(ASF_ASFConditionalEquationList arg, ASF_OptLayout wsAfterHead);
ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquationList tail);

/*}}}  */
/*{{{  ASF_ASFTestEquationTestList accessors */

ATbool ASF_isValidASFTestEquationTestList(ASF_ASFTestEquationTestList arg);
inline ATbool ASF_isASFTestEquationTestListEmpty(ASF_ASFTestEquationTestList arg);
inline ATbool ASF_isASFTestEquationTestListSingle(ASF_ASFTestEquationTestList arg);
inline ATbool ASF_isASFTestEquationTestListMany(ASF_ASFTestEquationTestList arg);
ATbool ASF_hasASFTestEquationTestListHead(ASF_ASFTestEquationTestList arg);
ATbool ASF_hasASFTestEquationTestListWsAfterHead(ASF_ASFTestEquationTestList arg);
ATbool ASF_hasASFTestEquationTestListTail(ASF_ASFTestEquationTestList arg);
ASF_ASFTestEquationTestList ASF_getASFTestEquationTestListTail(ASF_ASFTestEquationTestList arg);
ASF_ASFTestEquation ASF_getASFTestEquationTestListHead(ASF_ASFTestEquationTestList arg);
ASF_OptLayout ASF_getASFTestEquationTestListWsAfterHead(ASF_ASFTestEquationTestList arg);
ASF_ASFTestEquationTestList ASF_setASFTestEquationTestListHead(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquation head);
ASF_ASFTestEquationTestList ASF_setASFTestEquationTestListWsAfterHead(ASF_ASFTestEquationTestList arg, ASF_OptLayout wsAfterHead);
ASF_ASFTestEquationTestList ASF_setASFTestEquationTestListTail(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquationTestList tail);

/*}}}  */
/*{{{  ASF_LexASFTagId accessors */

ATbool ASF_isValidLexASFTagId(ASF_LexASFTagId arg);
inline ATbool ASF_isLexASFTagIdOneChar(ASF_LexASFTagId arg);
inline ATbool ASF_isLexASFTagIdManyChars(ASF_LexASFTagId arg);
ATbool ASF_hasLexASFTagIdHead(ASF_LexASFTagId arg);
ATbool ASF_hasLexASFTagIdMiddle(ASF_LexASFTagId arg);
ATbool ASF_hasLexASFTagIdLast(ASF_LexASFTagId arg);
char ASF_getLexASFTagIdHead(ASF_LexASFTagId arg);
char* ASF_getLexASFTagIdMiddle(ASF_LexASFTagId arg);
char ASF_getLexASFTagIdLast(ASF_LexASFTagId arg);
ASF_LexASFTagId ASF_setLexASFTagIdHead(ASF_LexASFTagId arg, char head);
ASF_LexASFTagId ASF_setLexASFTagIdMiddle(ASF_LexASFTagId arg, const char* middle);
ASF_LexASFTagId ASF_setLexASFTagIdLast(ASF_LexASFTagId arg, char last);

/*}}}  */
/*{{{  ASF_ASFTagId accessors */

ATbool ASF_isValidASFTagId(ASF_ASFTagId arg);
inline ATbool ASF_isASFTagIdLexToCf(ASF_ASFTagId arg);
ATbool ASF_hasASFTagIdASFTagId(ASF_ASFTagId arg);
ASF_LexASFTagId ASF_getASFTagIdASFTagId(ASF_ASFTagId arg);
ASF_ASFTagId ASF_setASFTagIdASFTagId(ASF_ASFTagId arg, ASF_LexASFTagId ASFTagId);

/*}}}  */
/*{{{  ASF_ASFTag accessors */

ATbool ASF_isValidASFTag(ASF_ASFTag arg);
inline ATbool ASF_isASFTagEmpty(ASF_ASFTag arg);
inline ATbool ASF_isASFTagNotEmpty(ASF_ASFTag arg);
ATbool ASF_hasASFTagWsAfterBracketOpen(ASF_ASFTag arg);
ATbool ASF_hasASFTagASFTagId(ASF_ASFTag arg);
ATbool ASF_hasASFTagWsAfterASFTagId(ASF_ASFTag arg);
ASF_OptLayout ASF_getASFTagWsAfterBracketOpen(ASF_ASFTag arg);
ASF_ASFTagId ASF_getASFTagASFTagId(ASF_ASFTag arg);
ASF_OptLayout ASF_getASFTagWsAfterASFTagId(ASF_ASFTag arg);
ASF_ASFTag ASF_setASFTagWsAfterBracketOpen(ASF_ASFTag arg, ASF_OptLayout wsAfterBracketOpen);
ASF_ASFTag ASF_setASFTagASFTagId(ASF_ASFTag arg, ASF_ASFTagId ASFTagId);
ASF_ASFTag ASF_setASFTagWsAfterASFTagId(ASF_ASFTag arg, ASF_OptLayout wsAfterASFTagId);

/*}}}  */
/*{{{  ASF_ASFTestEquation accessors */

ATbool ASF_isValidASFTestEquation(ASF_ASFTestEquation arg);
inline ATbool ASF_isASFTestEquationSimple(ASF_ASFTestEquation arg);
inline ATbool ASF_isASFTestEquationImplies(ASF_ASFTestEquation arg);
inline ATbool ASF_isASFTestEquationWhen(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationASFTag(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationWsAfterASFTag(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationASFCondition(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationASFConditions(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationWsAfterASFConditions(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationASFImplies(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationWsAfterASFImplies(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationWsAfterASFCondition(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationWsAfterWhen(ASF_ASFTestEquation arg);
ASF_ASFTag ASF_getASFTestEquationASFTag(ASF_ASFTestEquation arg);
ASF_OptLayout ASF_getASFTestEquationWsAfterASFTag(ASF_ASFTestEquation arg);
ASF_ASFCondition ASF_getASFTestEquationASFCondition(ASF_ASFTestEquation arg);
ASF_ASFConditions ASF_getASFTestEquationASFConditions(ASF_ASFTestEquation arg);
ASF_OptLayout ASF_getASFTestEquationWsAfterASFConditions(ASF_ASFTestEquation arg);
ASF_ASFImplies ASF_getASFTestEquationASFImplies(ASF_ASFTestEquation arg);
ASF_OptLayout ASF_getASFTestEquationWsAfterASFImplies(ASF_ASFTestEquation arg);
ASF_OptLayout ASF_getASFTestEquationWsAfterASFCondition(ASF_ASFTestEquation arg);
ASF_OptLayout ASF_getASFTestEquationWsAfterWhen(ASF_ASFTestEquation arg);
ASF_ASFTestEquation ASF_setASFTestEquationASFTag(ASF_ASFTestEquation arg, ASF_ASFTag ASFTag);
ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFTag(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFTag);
ASF_ASFTestEquation ASF_setASFTestEquationASFCondition(ASF_ASFTestEquation arg, ASF_ASFCondition ASFCondition);
ASF_ASFTestEquation ASF_setASFTestEquationASFConditions(ASF_ASFTestEquation arg, ASF_ASFConditions ASFConditions);
ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFConditions(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFConditions);
ASF_ASFTestEquation ASF_setASFTestEquationASFImplies(ASF_ASFTestEquation arg, ASF_ASFImplies ASFImplies);
ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFImplies(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFImplies);
ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFCondition(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFCondition);
ASF_ASFTestEquation ASF_setASFTestEquationWsAfterWhen(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterWhen);

/*}}}  */
/*{{{  ASF_LexLayout accessors */

ATbool ASF_isValidLexLayout(ASF_LexLayout arg);
inline ATbool ASF_isLexLayoutWhitespace(ASF_LexLayout arg);
ATbool ASF_hasLexLayoutCh(ASF_LexLayout arg);
char ASF_getLexLayoutCh(ASF_LexLayout arg);
ASF_LexLayout ASF_setLexLayoutCh(ASF_LexLayout arg, char ch);

/*}}}  */
/*{{{  ASF_LexNumChar accessors */

ATbool ASF_isValidLexNumChar(ASF_LexNumChar arg);
inline ATbool ASF_isLexNumCharDigits(ASF_LexNumChar arg);
ATbool ASF_hasLexNumCharNumber(ASF_LexNumChar arg);
char* ASF_getLexNumCharNumber(ASF_LexNumChar arg);
ASF_LexNumChar ASF_setLexNumCharNumber(ASF_LexNumChar arg, const char* number);

/*}}}  */
/*{{{  ASF_NumChar accessors */

ATbool ASF_isValidNumChar(ASF_NumChar arg);
inline ATbool ASF_isNumCharLexToCf(ASF_NumChar arg);
ATbool ASF_hasNumCharNumChar(ASF_NumChar arg);
ASF_LexNumChar ASF_getNumCharNumChar(ASF_NumChar arg);
ASF_NumChar ASF_setNumCharNumChar(ASF_NumChar arg, ASF_LexNumChar NumChar);

/*}}}  */
/*{{{  ASF_LexShortChar accessors */

ATbool ASF_isValidLexShortChar(ASF_LexShortChar arg);
inline ATbool ASF_isLexShortCharRegular(ASF_LexShortChar arg);
inline ATbool ASF_isLexShortCharEscaped(ASF_LexShortChar arg);
ATbool ASF_hasLexShortCharCharacter(ASF_LexShortChar arg);
ATbool ASF_hasLexShortCharEscape(ASF_LexShortChar arg);
char ASF_getLexShortCharCharacter(ASF_LexShortChar arg);
char ASF_getLexShortCharEscape(ASF_LexShortChar arg);
ASF_LexShortChar ASF_setLexShortCharCharacter(ASF_LexShortChar arg, char character);
ASF_LexShortChar ASF_setLexShortCharEscape(ASF_LexShortChar arg, char escape);

/*}}}  */
/*{{{  ASF_ShortChar accessors */

ATbool ASF_isValidShortChar(ASF_ShortChar arg);
inline ATbool ASF_isShortCharLexToCf(ASF_ShortChar arg);
ATbool ASF_hasShortCharShortChar(ASF_ShortChar arg);
ASF_LexShortChar ASF_getShortCharShortChar(ASF_ShortChar arg);
ASF_ShortChar ASF_setShortCharShortChar(ASF_ShortChar arg, ASF_LexShortChar ShortChar);

/*}}}  */
/*{{{  ASF_Character accessors */

ATbool ASF_isValidCharacter(ASF_Character arg);
inline ATbool ASF_isCharacterNumeric(ASF_Character arg);
inline ATbool ASF_isCharacterShort(ASF_Character arg);
inline ATbool ASF_isCharacterTop(ASF_Character arg);
inline ATbool ASF_isCharacterEof(ASF_Character arg);
inline ATbool ASF_isCharacterBot(ASF_Character arg);
inline ATbool ASF_isCharacterLabelUnderscoreStart(ASF_Character arg);
ATbool ASF_hasCharacterNumChar(ASF_Character arg);
ATbool ASF_hasCharacterShortChar(ASF_Character arg);
ASF_NumChar ASF_getCharacterNumChar(ASF_Character arg);
ASF_ShortChar ASF_getCharacterShortChar(ASF_Character arg);
ASF_Character ASF_setCharacterNumChar(ASF_Character arg, ASF_NumChar NumChar);
ASF_Character ASF_setCharacterShortChar(ASF_Character arg, ASF_ShortChar ShortChar);

/*}}}  */
/*{{{  sort visitors */

ASF_OptLayout ASF_visitOptLayout(ASF_OptLayout arg, ASF_Layout (*acceptLayout)(ASF_Layout));
ASF_Layout ASF_visitLayout(ASF_Layout arg, ASF_LexLayoutList (*acceptList)(ASF_LexLayoutList));
ASF_LexLayoutList ASF_visitLexLayoutList(ASF_LexLayoutList arg, ASF_LexLayout (*acceptHead)(ASF_LexLayout));
ASF_Tree ASF_visitTree(ASF_Tree arg, ATerm (*acceptTree)(ATerm));
ASF_ASFCondition ASF_visitASFCondition(ASF_ASFCondition arg, ATerm (*acceptTypeOfLhs)(ATerm), ATerm (*acceptTypeOfRhs)(ATerm), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterUnequal)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterEquality)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterMatch)(ASF_OptLayout));
ASF_ASFConditions ASF_visitASFConditions(ASF_ASFConditions arg, ASF_ASFConditionList (*acceptList)(ASF_ASFConditionList));
ASF_ASFConditionList ASF_visitASFConditionList(ASF_ASFConditionList arg, ASF_ASFCondition (*acceptHead)(ASF_ASFCondition), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterSep)(ASF_OptLayout));
ASF_LexASFBarEnd ASF_visitLexASFBarEnd(ASF_LexASFBarEnd arg);
ASF_ASFBarEnd ASF_visitASFBarEnd(ASF_ASFBarEnd arg, ASF_LexASFBarEnd (*acceptASFBarEnd)(ASF_LexASFBarEnd));
ASF_LexASFImplies ASF_visitLexASFImplies(ASF_LexASFImplies arg, char* (*acceptBar)(char*), ASF_LexASFBarEnd (*acceptEnd)(ASF_LexASFBarEnd));
ASF_ASFImplies ASF_visitASFImplies(ASF_ASFImplies arg, ASF_LexASFImplies (*acceptASFImplies)(ASF_LexASFImplies));
ASF_ASFConditionalEquation ASF_visitASFConditionalEquation(ASF_ASFConditionalEquation arg, ASF_ASFTag (*acceptASFTag)(ASF_ASFTag), ASF_OptLayout (*acceptWsAfterASFTag)(ASF_OptLayout), ASF_ASFEquation (*acceptASFEquation)(ASF_ASFEquation), ASF_ASFConditions (*acceptASFConditions)(ASF_ASFConditions), ASF_OptLayout (*acceptWsAfterASFConditions)(ASF_OptLayout), ASF_ASFImplies (*acceptASFImplies)(ASF_ASFImplies), ASF_OptLayout (*acceptWsAfterASFImplies)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterASFEquation)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterWhen)(ASF_OptLayout));
ASF_ASFEquation ASF_visitASFEquation(ASF_ASFEquation arg, ATerm (*acceptTypeOfLhs)(ATerm), ATerm (*acceptTypeOfRhs)(ATerm), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquals)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree));
ASF_Start ASF_visitStart(ASF_Start arg, ASF_OptLayout (*acceptWsBefore)(ASF_OptLayout), ASF_ASFModule (*acceptTopASFModule)(ASF_ASFModule), ASF_OptLayout (*acceptWsAfter)(ASF_OptLayout), int (*acceptAmbCnt)(int), ASF_ASFSection (*acceptTopASFSection)(ASF_ASFSection));
ASF_ASFModule ASF_visitASFModule(ASF_ASFModule arg, ASF_ASFSectionList (*acceptList)(ASF_ASFSectionList));
ASF_ASFSection ASF_visitASFSection(ASF_ASFSection arg, ASF_OptLayout (*acceptWsAfterEquations)(ASF_OptLayout), ASF_ASFConditionalEquationList (*acceptList)(ASF_ASFConditionalEquationList), ASF_OptLayout (*acceptWsAfterTests)(ASF_OptLayout), ASF_ASFTestEquationTestList (*acceptTestList)(ASF_ASFTestEquationTestList));
ASF_ASFSectionList ASF_visitASFSectionList(ASF_ASFSectionList arg, ASF_ASFSection (*acceptHead)(ASF_ASFSection), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout));
ASF_ASFConditionalEquationList ASF_visitASFConditionalEquationList(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation (*acceptHead)(ASF_ASFConditionalEquation), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout));
ASF_ASFTestEquationTestList ASF_visitASFTestEquationTestList(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquation (*acceptHead)(ASF_ASFTestEquation), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout));
ASF_LexASFTagId ASF_visitLexASFTagId(ASF_LexASFTagId arg, char (*acceptHead)(char), char* (*acceptMiddle)(char*), char (*acceptLast)(char));
ASF_ASFTagId ASF_visitASFTagId(ASF_ASFTagId arg, ASF_LexASFTagId (*acceptASFTagId)(ASF_LexASFTagId));
ASF_ASFTag ASF_visitASFTag(ASF_ASFTag arg, ASF_OptLayout (*acceptWsAfterBracketOpen)(ASF_OptLayout), ASF_ASFTagId (*acceptASFTagId)(ASF_ASFTagId), ASF_OptLayout (*acceptWsAfterASFTagId)(ASF_OptLayout));
ASF_ASFTestEquation ASF_visitASFTestEquation(ASF_ASFTestEquation arg, ASF_ASFTag (*acceptASFTag)(ASF_ASFTag), ASF_OptLayout (*acceptWsAfterASFTag)(ASF_OptLayout), ASF_ASFCondition (*acceptASFCondition)(ASF_ASFCondition), ASF_ASFConditions (*acceptASFConditions)(ASF_ASFConditions), ASF_OptLayout (*acceptWsAfterASFConditions)(ASF_OptLayout), ASF_ASFImplies (*acceptASFImplies)(ASF_ASFImplies), ASF_OptLayout (*acceptWsAfterASFImplies)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterASFCondition)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterWhen)(ASF_OptLayout));
ASF_LexLayout ASF_visitLexLayout(ASF_LexLayout arg, char (*acceptCh)(char));
ASF_LexNumChar ASF_visitLexNumChar(ASF_LexNumChar arg, char* (*acceptNumber)(char*));
ASF_NumChar ASF_visitNumChar(ASF_NumChar arg, ASF_LexNumChar (*acceptNumChar)(ASF_LexNumChar));
ASF_LexShortChar ASF_visitLexShortChar(ASF_LexShortChar arg, char (*acceptCharacter)(char), char (*acceptEscape)(char));
ASF_ShortChar ASF_visitShortChar(ASF_ShortChar arg, ASF_LexShortChar (*acceptShortChar)(ASF_LexShortChar));
ASF_Character ASF_visitCharacter(ASF_Character arg, ASF_NumChar (*acceptNumChar)(ASF_NumChar), ASF_ShortChar (*acceptShortChar)(ASF_ShortChar));

/*}}}  */

#endif /* _ASFME_H */
