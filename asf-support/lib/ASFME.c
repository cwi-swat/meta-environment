#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "ASFME.h"

/*{{{  conversion functions */

ATerm ASF_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

ATerm ASF_byteToChar(char ch)
{
    return (ATerm) ATmakeInt(ch);
}

char *ASF_charsToString(ATerm arg)
{
  ATermList list = (ATermList) arg;
  int len = ATgetLength(list);
  int i;
  char *str;

  str = (char *) malloc(len+1);
  if (str == NULL) {
      return NULL;
  }

  for (i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    str[i] = (char) ATgetInt((ATermInt) ATgetFirst(list));
  }
  str[i] = '\0';

  return str;
}

char ASF_charToByte(ATerm arg)
{
    return (char) ATgetInt((ATermInt) arg);
}


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _ASF_OptLayout;
typedef struct ATerm _ASF_Layout;
typedef struct ATerm _ASF_LexLayoutList;
typedef struct ATerm _ASF_Tree;
typedef struct ATerm _ASF_ASFCondition;
typedef struct ATerm _ASF_ASFConditions;
typedef struct ATerm _ASF_ASFConditionList;
typedef struct ATerm _ASF_LexASFBarEnd;
typedef struct ATerm _ASF_ASFBarEnd;
typedef struct ATerm _ASF_LexASFImplies;
typedef struct ATerm _ASF_ASFImplies;
typedef struct ATerm _ASF_ASFConditionalEquation;
typedef struct ATerm _ASF_ASFEquation;
typedef struct ATerm _ASF_Start;
typedef struct ATerm _ASF_ASFModule;
typedef struct ATerm _ASF_ASFSection;
typedef struct ATerm _ASF_ASFSectionList;
typedef struct ATerm _ASF_ASFConditionalEquationList;
typedef struct ATerm _ASF_ASFTestEquationTestList;
typedef struct ATerm _ASF_LexASFTagId;
typedef struct ATerm _ASF_ASFTagId;
typedef struct ATerm _ASF_ASFTag;
typedef struct ATerm _ASF_ASFTestEquation;
typedef struct ATerm _ASF_LexLayout;
typedef struct ATerm _ASF_LexNumChar;
typedef struct ATerm _ASF_NumChar;
typedef struct ATerm _ASF_LexShortChar;
typedef struct ATerm _ASF_ShortChar;
typedef struct ATerm _ASF_Character;

/*}}}  */

/*{{{  void ASF_initASFMEApi(void) */

void ASF_initASFMEApi(void)
{
  init_ASFME_dict();
}

/*}}}  */

/*{{{  protect functions */

void ASF_protectOptLayout(ASF_OptLayout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectLayout(ASF_Layout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectLexLayoutList(ASF_LexLayoutList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectTree(ASF_Tree *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFCondition(ASF_ASFCondition *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFConditions(ASF_ASFConditions *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFConditionList(ASF_ASFConditionList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectLexASFBarEnd(ASF_LexASFBarEnd *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFBarEnd(ASF_ASFBarEnd *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectLexASFImplies(ASF_LexASFImplies *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFImplies(ASF_ASFImplies *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFConditionalEquation(ASF_ASFConditionalEquation *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFEquation(ASF_ASFEquation *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectStart(ASF_Start *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFModule(ASF_ASFModule *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFSection(ASF_ASFSection *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFSectionList(ASF_ASFSectionList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFConditionalEquationList(ASF_ASFConditionalEquationList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFTestEquationTestList(ASF_ASFTestEquationTestList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectLexASFTagId(ASF_LexASFTagId *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFTagId(ASF_ASFTagId *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFTag(ASF_ASFTag *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFTestEquation(ASF_ASFTestEquation *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectLexLayout(ASF_LexLayout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectLexNumChar(ASF_LexNumChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectNumChar(ASF_NumChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectLexShortChar(ASF_LexShortChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectShortChar(ASF_ShortChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectCharacter(ASF_Character *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  ASF_OptLayout ASF_OptLayoutFromTerm(ATerm t) */

ASF_OptLayout ASF_OptLayoutFromTerm(ATerm t)
{
  return (ASF_OptLayout)t;
}

/*}}}  */
/*{{{  ATerm ASF_OptLayoutToTerm(ASF_OptLayout arg) */

ATerm ASF_OptLayoutToTerm(ASF_OptLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Layout ASF_LayoutFromTerm(ATerm t) */

ASF_Layout ASF_LayoutFromTerm(ATerm t)
{
  return (ASF_Layout)t;
}

/*}}}  */
/*{{{  ATerm ASF_LayoutToTerm(ASF_Layout arg) */

ATerm ASF_LayoutToTerm(ASF_Layout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_LexLayoutList ASF_LexLayoutListFromTerm(ATerm t) */

ASF_LexLayoutList ASF_LexLayoutListFromTerm(ATerm t)
{
  return (ASF_LexLayoutList)t;
}

/*}}}  */
/*{{{  ATerm ASF_LexLayoutListToTerm(ASF_LexLayoutList arg) */

ATerm ASF_LexLayoutListToTerm(ASF_LexLayoutList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Tree ASF_TreeFromTerm(ATerm t) */

ASF_Tree ASF_TreeFromTerm(ATerm t)
{
  return (ASF_Tree)t;
}

/*}}}  */
/*{{{  ATerm ASF_TreeToTerm(ASF_Tree arg) */

ATerm ASF_TreeToTerm(ASF_Tree arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_ASFConditionFromTerm(ATerm t) */

ASF_ASFCondition ASF_ASFConditionFromTerm(ATerm t)
{
  return (ASF_ASFCondition)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFConditionToTerm(ASF_ASFCondition arg) */

ATerm ASF_ASFConditionToTerm(ASF_ASFCondition arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFConditions ASF_ASFConditionsFromTerm(ATerm t) */

ASF_ASFConditions ASF_ASFConditionsFromTerm(ATerm t)
{
  return (ASF_ASFConditions)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFConditionsToTerm(ASF_ASFConditions arg) */

ATerm ASF_ASFConditionsToTerm(ASF_ASFConditions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_ASFConditionListFromTerm(ATerm t) */

ASF_ASFConditionList ASF_ASFConditionListFromTerm(ATerm t)
{
  return (ASF_ASFConditionList)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFConditionListToTerm(ASF_ASFConditionList arg) */

ATerm ASF_ASFConditionListToTerm(ASF_ASFConditionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_LexASFBarEnd ASF_LexASFBarEndFromTerm(ATerm t) */

ASF_LexASFBarEnd ASF_LexASFBarEndFromTerm(ATerm t)
{
  return (ASF_LexASFBarEnd)t;
}

/*}}}  */
/*{{{  ATerm ASF_LexASFBarEndToTerm(ASF_LexASFBarEnd arg) */

ATerm ASF_LexASFBarEndToTerm(ASF_LexASFBarEnd arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFBarEnd ASF_ASFBarEndFromTerm(ATerm t) */

ASF_ASFBarEnd ASF_ASFBarEndFromTerm(ATerm t)
{
  return (ASF_ASFBarEnd)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFBarEndToTerm(ASF_ASFBarEnd arg) */

ATerm ASF_ASFBarEndToTerm(ASF_ASFBarEnd arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_LexASFImplies ASF_LexASFImpliesFromTerm(ATerm t) */

ASF_LexASFImplies ASF_LexASFImpliesFromTerm(ATerm t)
{
  return (ASF_LexASFImplies)t;
}

/*}}}  */
/*{{{  ATerm ASF_LexASFImpliesToTerm(ASF_LexASFImplies arg) */

ATerm ASF_LexASFImpliesToTerm(ASF_LexASFImplies arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFImplies ASF_ASFImpliesFromTerm(ATerm t) */

ASF_ASFImplies ASF_ASFImpliesFromTerm(ATerm t)
{
  return (ASF_ASFImplies)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFImpliesToTerm(ASF_ASFImplies arg) */

ATerm ASF_ASFImpliesToTerm(ASF_ASFImplies arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_ASFConditionalEquationFromTerm(ATerm t) */

ASF_ASFConditionalEquation ASF_ASFConditionalEquationFromTerm(ATerm t)
{
  return (ASF_ASFConditionalEquation)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFConditionalEquationToTerm(ASF_ASFConditionalEquation arg) */

ATerm ASF_ASFConditionalEquationToTerm(ASF_ASFConditionalEquation arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_ASFEquationFromTerm(ATerm t) */

ASF_ASFEquation ASF_ASFEquationFromTerm(ATerm t)
{
  return (ASF_ASFEquation)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFEquationToTerm(ASF_ASFEquation arg) */

ATerm ASF_ASFEquationToTerm(ASF_ASFEquation arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Start ASF_StartFromTerm(ATerm t) */

ASF_Start ASF_StartFromTerm(ATerm t)
{
  return (ASF_Start)t;
}

/*}}}  */
/*{{{  ATerm ASF_StartToTerm(ASF_Start arg) */

ATerm ASF_StartToTerm(ASF_Start arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFModule ASF_ASFModuleFromTerm(ATerm t) */

ASF_ASFModule ASF_ASFModuleFromTerm(ATerm t)
{
  return (ASF_ASFModule)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFModuleToTerm(ASF_ASFModule arg) */

ATerm ASF_ASFModuleToTerm(ASF_ASFModule arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFSection ASF_ASFSectionFromTerm(ATerm t) */

ASF_ASFSection ASF_ASFSectionFromTerm(ATerm t)
{
  return (ASF_ASFSection)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFSectionToTerm(ASF_ASFSection arg) */

ATerm ASF_ASFSectionToTerm(ASF_ASFSection arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFSectionList ASF_ASFSectionListFromTerm(ATerm t) */

ASF_ASFSectionList ASF_ASFSectionListFromTerm(ATerm t)
{
  return (ASF_ASFSectionList)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFSectionListToTerm(ASF_ASFSectionList arg) */

ATerm ASF_ASFSectionListToTerm(ASF_ASFSectionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_ASFConditionalEquationListFromTerm(ATerm t) */

ASF_ASFConditionalEquationList ASF_ASFConditionalEquationListFromTerm(ATerm t)
{
  return (ASF_ASFConditionalEquationList)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFConditionalEquationListToTerm(ASF_ASFConditionalEquationList arg) */

ATerm ASF_ASFConditionalEquationListToTerm(ASF_ASFConditionalEquationList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFTestEquationTestList ASF_ASFTestEquationTestListFromTerm(ATerm t) */

ASF_ASFTestEquationTestList ASF_ASFTestEquationTestListFromTerm(ATerm t)
{
  return (ASF_ASFTestEquationTestList)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFTestEquationTestListToTerm(ASF_ASFTestEquationTestList arg) */

ATerm ASF_ASFTestEquationTestListToTerm(ASF_ASFTestEquationTestList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_LexASFTagId ASF_LexASFTagIdFromTerm(ATerm t) */

ASF_LexASFTagId ASF_LexASFTagIdFromTerm(ATerm t)
{
  return (ASF_LexASFTagId)t;
}

/*}}}  */
/*{{{  ATerm ASF_LexASFTagIdToTerm(ASF_LexASFTagId arg) */

ATerm ASF_LexASFTagIdToTerm(ASF_LexASFTagId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFTagId ASF_ASFTagIdFromTerm(ATerm t) */

ASF_ASFTagId ASF_ASFTagIdFromTerm(ATerm t)
{
  return (ASF_ASFTagId)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFTagIdToTerm(ASF_ASFTagId arg) */

ATerm ASF_ASFTagIdToTerm(ASF_ASFTagId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_ASFTagFromTerm(ATerm t) */

ASF_ASFTag ASF_ASFTagFromTerm(ATerm t)
{
  return (ASF_ASFTag)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFTagToTerm(ASF_ASFTag arg) */

ATerm ASF_ASFTagToTerm(ASF_ASFTag arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_ASFTestEquationFromTerm(ATerm t) */

ASF_ASFTestEquation ASF_ASFTestEquationFromTerm(ATerm t)
{
  return (ASF_ASFTestEquation)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFTestEquationToTerm(ASF_ASFTestEquation arg) */

ATerm ASF_ASFTestEquationToTerm(ASF_ASFTestEquation arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_LexLayout ASF_LexLayoutFromTerm(ATerm t) */

ASF_LexLayout ASF_LexLayoutFromTerm(ATerm t)
{
  return (ASF_LexLayout)t;
}

/*}}}  */
/*{{{  ATerm ASF_LexLayoutToTerm(ASF_LexLayout arg) */

ATerm ASF_LexLayoutToTerm(ASF_LexLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_LexNumChar ASF_LexNumCharFromTerm(ATerm t) */

ASF_LexNumChar ASF_LexNumCharFromTerm(ATerm t)
{
  return (ASF_LexNumChar)t;
}

/*}}}  */
/*{{{  ATerm ASF_LexNumCharToTerm(ASF_LexNumChar arg) */

ATerm ASF_LexNumCharToTerm(ASF_LexNumChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_NumChar ASF_NumCharFromTerm(ATerm t) */

ASF_NumChar ASF_NumCharFromTerm(ATerm t)
{
  return (ASF_NumChar)t;
}

/*}}}  */
/*{{{  ATerm ASF_NumCharToTerm(ASF_NumChar arg) */

ATerm ASF_NumCharToTerm(ASF_NumChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_LexShortChar ASF_LexShortCharFromTerm(ATerm t) */

ASF_LexShortChar ASF_LexShortCharFromTerm(ATerm t)
{
  return (ASF_LexShortChar)t;
}

/*}}}  */
/*{{{  ATerm ASF_LexShortCharToTerm(ASF_LexShortChar arg) */

ATerm ASF_LexShortCharToTerm(ASF_LexShortChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ShortChar ASF_ShortCharFromTerm(ATerm t) */

ASF_ShortChar ASF_ShortCharFromTerm(ATerm t)
{
  return (ASF_ShortChar)t;
}

/*}}}  */
/*{{{  ATerm ASF_ShortCharToTerm(ASF_ShortChar arg) */

ATerm ASF_ShortCharToTerm(ASF_ShortChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Character ASF_CharacterFromTerm(ATerm t) */

ASF_Character ASF_CharacterFromTerm(ATerm t)
{
  return (ASF_Character)t;
}

/*}}}  */
/*{{{  ATerm ASF_CharacterToTerm(ASF_Character arg) */

ATerm ASF_CharacterToTerm(ASF_Character arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int ASF_getLexLayoutListLength (ASF_LexLayoutList arg) {
  return ATgetLength((ATermList) arg);
}
ASF_LexLayoutList ASF_reverseLexLayoutList(ASF_LexLayoutList arg) {
  return (ASF_LexLayoutList) ATreverse((ATermList) arg);
}
ASF_LexLayoutList ASF_appendLexLayoutList(ASF_LexLayoutList arg, ASF_LexLayout elem) {
  return (ASF_LexLayoutList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
ASF_LexLayoutList ASF_concatLexLayoutList(ASF_LexLayoutList arg0, ASF_LexLayoutList arg1) {
  return (ASF_LexLayoutList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
ASF_LexLayoutList ASF_sliceLexLayoutList(ASF_LexLayoutList arg, int start, int end) {
  return (ASF_LexLayoutList) ATgetSlice((ATermList) arg, start, end);
}
ASF_LexLayout ASF_getLexLayoutListLexLayoutAt(ASF_LexLayoutList arg, int index) {
 return (ASF_LexLayout)ATelementAt((ATermList) arg,index);
}
ASF_LexLayoutList ASF_replaceLexLayoutListLexLayoutAt(ASF_LexLayoutList arg, ASF_LexLayout elem, int index) {
 return (ASF_LexLayoutList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
ASF_LexLayoutList ASF_makeLexLayoutList2(ASF_LexLayout elem1, ASF_LexLayout elem2) {
  return (ASF_LexLayoutList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
ASF_LexLayoutList ASF_makeLexLayoutList3(ASF_LexLayout elem1, ASF_LexLayout elem2, ASF_LexLayout elem3) {
  return (ASF_LexLayoutList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
ASF_LexLayoutList ASF_makeLexLayoutList4(ASF_LexLayout elem1, ASF_LexLayout elem2, ASF_LexLayout elem3, ASF_LexLayout elem4) {
  return (ASF_LexLayoutList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
ASF_LexLayoutList ASF_makeLexLayoutList5(ASF_LexLayout elem1, ASF_LexLayout elem2, ASF_LexLayout elem3, ASF_LexLayout elem4, ASF_LexLayout elem5) {
  return (ASF_LexLayoutList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
ASF_LexLayoutList ASF_makeLexLayoutList6(ASF_LexLayout elem1, ASF_LexLayout elem2, ASF_LexLayout elem3, ASF_LexLayout elem4, ASF_LexLayout elem5, ASF_LexLayout elem6) {
  return (ASF_LexLayoutList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int ASF_getASFConditionListLength (ASF_ASFConditionList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
ASF_ASFConditionList ASF_reverseASFConditionList(ASF_ASFConditionList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (ASF_ASFConditionList) result;
}
ASF_ASFConditionList ASF_appendASFConditionList(ASF_ASFConditionList arg0, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition arg1) {
  return ASF_concatASFConditionList(arg0, wsAfterHead, wsAfterSep, ASF_makeASFConditionListSingle(arg1));
}
ASF_ASFConditionList ASF_concatASFConditionList(ASF_ASFConditionList arg0, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFConditionList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = ASF_makeASFConditionListMany((ASF_ASFCondition)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (ASF_ASFConditionList) ATgetNext((ATermList) arg1);
  return (ASF_ASFConditionList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
ASF_ASFConditionList ASF_sliceASFConditionList(ASF_ASFConditionList arg, int start, int end) {
  return (ASF_ASFConditionList) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
ASF_ASFCondition ASF_getASFConditionListASFConditionAt(ASF_ASFConditionList arg, int index) {
 return (ASF_ASFCondition)ATelementAt((ATermList) arg,index * 4);
}
ASF_ASFConditionList ASF_replaceASFConditionListASFConditionAt(ASF_ASFConditionList arg, ASF_ASFCondition elem, int index) {
 return (ASF_ASFConditionList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
ASF_ASFConditionList ASF_makeASFConditionList2(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition elem1, ASF_ASFCondition elem2) {
  return ASF_makeASFConditionListMany(elem1, wsAfterHead, wsAfterSep, ASF_makeASFConditionListSingle(elem2));
}
ASF_ASFConditionList ASF_makeASFConditionList3(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition elem1, ASF_ASFCondition elem2, ASF_ASFCondition elem3) {
  return ASF_makeASFConditionListMany(elem1, wsAfterHead, wsAfterSep, ASF_makeASFConditionList2(wsAfterHead, wsAfterSep, elem2, elem3));
}
ASF_ASFConditionList ASF_makeASFConditionList4(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition elem1, ASF_ASFCondition elem2, ASF_ASFCondition elem3, ASF_ASFCondition elem4) {
  return ASF_makeASFConditionListMany(elem1, wsAfterHead, wsAfterSep, ASF_makeASFConditionList3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
ASF_ASFConditionList ASF_makeASFConditionList5(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition elem1, ASF_ASFCondition elem2, ASF_ASFCondition elem3, ASF_ASFCondition elem4, ASF_ASFCondition elem5) {
  return ASF_makeASFConditionListMany(elem1, wsAfterHead, wsAfterSep, ASF_makeASFConditionList4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
ASF_ASFConditionList ASF_makeASFConditionList6(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition elem1, ASF_ASFCondition elem2, ASF_ASFCondition elem3, ASF_ASFCondition elem4, ASF_ASFCondition elem5, ASF_ASFCondition elem6) {
  return ASF_makeASFConditionListMany(elem1, wsAfterHead, wsAfterSep, ASF_makeASFConditionList5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int ASF_getASFSectionListLength (ASF_ASFSectionList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 2) + 1;
}
ASF_ASFSectionList ASF_reverseASFSectionList(ASF_ASFSectionList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (ASF_ASFSectionList) result;
}
ASF_ASFSectionList ASF_appendASFSectionList(ASF_ASFSectionList arg0, ASF_OptLayout wsAfterHead, ASF_ASFSection arg1) {
  return ASF_concatASFSectionList(arg0, wsAfterHead, ASF_makeASFSectionListSingle(arg1));
}
ASF_ASFSectionList ASF_concatASFSectionList(ASF_ASFSectionList arg0, ASF_OptLayout wsAfterHead, ASF_ASFSectionList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = ASF_makeASFSectionListMany((ASF_ASFSection)ATgetFirst((ATermList) arg0), wsAfterHead,  arg1);
  arg1 = (ASF_ASFSectionList) ATgetNext((ATermList) arg1);
  return (ASF_ASFSectionList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
ASF_ASFSectionList ASF_sliceASFSectionList(ASF_ASFSectionList arg, int start, int end) {
  return (ASF_ASFSectionList) ATgetSlice((ATermList) arg, start * 2, end * 2);
}
ASF_ASFSection ASF_getASFSectionListASFSectionAt(ASF_ASFSectionList arg, int index) {
 return (ASF_ASFSection)ATelementAt((ATermList) arg,index * 2);
}
ASF_ASFSectionList ASF_replaceASFSectionListASFSectionAt(ASF_ASFSectionList arg, ASF_ASFSection elem, int index) {
 return (ASF_ASFSectionList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 2);
}
ASF_ASFSectionList ASF_makeASFSectionList2(ASF_OptLayout wsAfterHead, ASF_ASFSection elem1, ASF_ASFSection elem2) {
  return ASF_makeASFSectionListMany(elem1, wsAfterHead, ASF_makeASFSectionListSingle(elem2));
}
ASF_ASFSectionList ASF_makeASFSectionList3(ASF_OptLayout wsAfterHead, ASF_ASFSection elem1, ASF_ASFSection elem2, ASF_ASFSection elem3) {
  return ASF_makeASFSectionListMany(elem1, wsAfterHead, ASF_makeASFSectionList2(wsAfterHead, elem2, elem3));
}
ASF_ASFSectionList ASF_makeASFSectionList4(ASF_OptLayout wsAfterHead, ASF_ASFSection elem1, ASF_ASFSection elem2, ASF_ASFSection elem3, ASF_ASFSection elem4) {
  return ASF_makeASFSectionListMany(elem1, wsAfterHead, ASF_makeASFSectionList3(wsAfterHead, elem2, elem3, elem4));
}
ASF_ASFSectionList ASF_makeASFSectionList5(ASF_OptLayout wsAfterHead, ASF_ASFSection elem1, ASF_ASFSection elem2, ASF_ASFSection elem3, ASF_ASFSection elem4, ASF_ASFSection elem5) {
  return ASF_makeASFSectionListMany(elem1, wsAfterHead, ASF_makeASFSectionList4(wsAfterHead, elem2, elem3, elem4, elem5));
}
ASF_ASFSectionList ASF_makeASFSectionList6(ASF_OptLayout wsAfterHead, ASF_ASFSection elem1, ASF_ASFSection elem2, ASF_ASFSection elem3, ASF_ASFSection elem4, ASF_ASFSection elem5, ASF_ASFSection elem6) {
  return ASF_makeASFSectionListMany(elem1, wsAfterHead, ASF_makeASFSectionList5(wsAfterHead, elem2, elem3, elem4, elem5, elem6));
}
int ASF_getASFConditionalEquationListLength (ASF_ASFConditionalEquationList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 2) + 1;
}
ASF_ASFConditionalEquationList ASF_reverseASFConditionalEquationList(ASF_ASFConditionalEquationList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (ASF_ASFConditionalEquationList) result;
}
ASF_ASFConditionalEquationList ASF_appendASFConditionalEquationList(ASF_ASFConditionalEquationList arg0, ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation arg1) {
  return ASF_concatASFConditionalEquationList(arg0, wsAfterHead, ASF_makeASFConditionalEquationListSingle(arg1));
}
ASF_ASFConditionalEquationList ASF_concatASFConditionalEquationList(ASF_ASFConditionalEquationList arg0, ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquationList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = ASF_makeASFConditionalEquationListMany((ASF_ASFConditionalEquation)ATgetFirst((ATermList) arg0), wsAfterHead,  arg1);
  arg1 = (ASF_ASFConditionalEquationList) ATgetNext((ATermList) arg1);
  return (ASF_ASFConditionalEquationList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
ASF_ASFConditionalEquationList ASF_sliceASFConditionalEquationList(ASF_ASFConditionalEquationList arg, int start, int end) {
  return (ASF_ASFConditionalEquationList) ATgetSlice((ATermList) arg, start * 2, end * 2);
}
ASF_ASFConditionalEquation ASF_getASFConditionalEquationListASFConditionalEquationAt(ASF_ASFConditionalEquationList arg, int index) {
 return (ASF_ASFConditionalEquation)ATelementAt((ATermList) arg,index * 2);
}
ASF_ASFConditionalEquationList ASF_replaceASFConditionalEquationListASFConditionalEquationAt(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation elem, int index) {
 return (ASF_ASFConditionalEquationList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 2);
}
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList2(ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation elem1, ASF_ASFConditionalEquation elem2) {
  return ASF_makeASFConditionalEquationListMany(elem1, wsAfterHead, ASF_makeASFConditionalEquationListSingle(elem2));
}
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList3(ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation elem1, ASF_ASFConditionalEquation elem2, ASF_ASFConditionalEquation elem3) {
  return ASF_makeASFConditionalEquationListMany(elem1, wsAfterHead, ASF_makeASFConditionalEquationList2(wsAfterHead, elem2, elem3));
}
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList4(ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation elem1, ASF_ASFConditionalEquation elem2, ASF_ASFConditionalEquation elem3, ASF_ASFConditionalEquation elem4) {
  return ASF_makeASFConditionalEquationListMany(elem1, wsAfterHead, ASF_makeASFConditionalEquationList3(wsAfterHead, elem2, elem3, elem4));
}
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList5(ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation elem1, ASF_ASFConditionalEquation elem2, ASF_ASFConditionalEquation elem3, ASF_ASFConditionalEquation elem4, ASF_ASFConditionalEquation elem5) {
  return ASF_makeASFConditionalEquationListMany(elem1, wsAfterHead, ASF_makeASFConditionalEquationList4(wsAfterHead, elem2, elem3, elem4, elem5));
}
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList6(ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation elem1, ASF_ASFConditionalEquation elem2, ASF_ASFConditionalEquation elem3, ASF_ASFConditionalEquation elem4, ASF_ASFConditionalEquation elem5, ASF_ASFConditionalEquation elem6) {
  return ASF_makeASFConditionalEquationListMany(elem1, wsAfterHead, ASF_makeASFConditionalEquationList5(wsAfterHead, elem2, elem3, elem4, elem5, elem6));
}
int ASF_getASFTestEquationTestListLength (ASF_ASFTestEquationTestList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 2) + 1;
}
ASF_ASFTestEquationTestList ASF_reverseASFTestEquationTestList(ASF_ASFTestEquationTestList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (ASF_ASFTestEquationTestList) result;
}
ASF_ASFTestEquationTestList ASF_appendASFTestEquationTestList(ASF_ASFTestEquationTestList arg0, ASF_OptLayout wsAfterHead, ASF_ASFTestEquation arg1) {
  return ASF_concatASFTestEquationTestList(arg0, wsAfterHead, ASF_makeASFTestEquationTestListSingle(arg1));
}
ASF_ASFTestEquationTestList ASF_concatASFTestEquationTestList(ASF_ASFTestEquationTestList arg0, ASF_OptLayout wsAfterHead, ASF_ASFTestEquationTestList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = ASF_makeASFTestEquationTestListMany((ASF_ASFTestEquation)ATgetFirst((ATermList) arg0), wsAfterHead,  arg1);
  arg1 = (ASF_ASFTestEquationTestList) ATgetNext((ATermList) arg1);
  return (ASF_ASFTestEquationTestList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
ASF_ASFTestEquationTestList ASF_sliceASFTestEquationTestList(ASF_ASFTestEquationTestList arg, int start, int end) {
  return (ASF_ASFTestEquationTestList) ATgetSlice((ATermList) arg, start * 2, end * 2);
}
ASF_ASFTestEquation ASF_getASFTestEquationTestListASFTestEquationAt(ASF_ASFTestEquationTestList arg, int index) {
 return (ASF_ASFTestEquation)ATelementAt((ATermList) arg,index * 2);
}
ASF_ASFTestEquationTestList ASF_replaceASFTestEquationTestListASFTestEquationAt(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquation elem, int index) {
 return (ASF_ASFTestEquationTestList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 2);
}
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestList2(ASF_OptLayout wsAfterHead, ASF_ASFTestEquation elem1, ASF_ASFTestEquation elem2) {
  return ASF_makeASFTestEquationTestListMany(elem1, wsAfterHead, ASF_makeASFTestEquationTestListSingle(elem2));
}
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestList3(ASF_OptLayout wsAfterHead, ASF_ASFTestEquation elem1, ASF_ASFTestEquation elem2, ASF_ASFTestEquation elem3) {
  return ASF_makeASFTestEquationTestListMany(elem1, wsAfterHead, ASF_makeASFTestEquationTestList2(wsAfterHead, elem2, elem3));
}
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestList4(ASF_OptLayout wsAfterHead, ASF_ASFTestEquation elem1, ASF_ASFTestEquation elem2, ASF_ASFTestEquation elem3, ASF_ASFTestEquation elem4) {
  return ASF_makeASFTestEquationTestListMany(elem1, wsAfterHead, ASF_makeASFTestEquationTestList3(wsAfterHead, elem2, elem3, elem4));
}
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestList5(ASF_OptLayout wsAfterHead, ASF_ASFTestEquation elem1, ASF_ASFTestEquation elem2, ASF_ASFTestEquation elem3, ASF_ASFTestEquation elem4, ASF_ASFTestEquation elem5) {
  return ASF_makeASFTestEquationTestListMany(elem1, wsAfterHead, ASF_makeASFTestEquationTestList4(wsAfterHead, elem2, elem3, elem4, elem5));
}
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestList6(ASF_OptLayout wsAfterHead, ASF_ASFTestEquation elem1, ASF_ASFTestEquation elem2, ASF_ASFTestEquation elem3, ASF_ASFTestEquation elem4, ASF_ASFTestEquation elem5, ASF_ASFTestEquation elem6) {
  return ASF_makeASFTestEquationTestListMany(elem1, wsAfterHead, ASF_makeASFTestEquationTestList5(wsAfterHead, elem2, elem3, elem4, elem5, elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  ASF_OptLayout ASF_makeOptLayoutAbsent(void) */

ASF_OptLayout ASF_makeOptLayoutAbsent(void)
{
  return (ASF_OptLayout)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4))), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_makeOptLayoutPresent(ASF_Layout layout) */

ASF_OptLayout ASF_makeOptLayoutPresent(ASF_Layout layout)
{
  return (ASF_OptLayout)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl0(ASF_afun4))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4))), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATmakeList1((ATerm) layout));
}

/*}}}  */
/*{{{  ASF_Layout ASF_makeLayoutLexToCf(ASF_LexLayoutList list) */

ASF_Layout ASF_makeLayoutLexToCf(ASF_LexLayoutList list)
{
  return (ASF_Layout)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl0(ASF_afun4)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl1(ASF_afun8, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm) list)));
}

/*}}}  */
/*{{{  ASF_LexLayoutList ASF_makeLexLayoutListEmpty(void) */

ASF_LexLayoutList ASF_makeLexLayoutListEmpty(void)
{
  return (ASF_LexLayoutList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  ASF_LexLayoutList ASF_makeLexLayoutListSingle(ASF_LexLayout head) */

ASF_LexLayoutList ASF_makeLexLayoutListSingle(ASF_LexLayout head)
{
  return (ASF_LexLayoutList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  ASF_LexLayoutList ASF_makeLexLayoutListMany(ASF_LexLayout head, ASF_LexLayoutList tail) */

ASF_LexLayoutList ASF_makeLexLayoutListMany(ASF_LexLayout head, ASF_LexLayoutList tail)
{
  return (ASF_LexLayoutList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  ASF_Tree ASF_makeTreeCast(ATerm Tree) */

ASF_Tree ASF_makeTreeCast(ATerm Tree)
{
  return (ASF_Tree)(ATerm) Tree;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_makeASFConditionNegative(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterUnequal, ASF_Tree rhs) */

ASF_ASFCondition ASF_makeASFConditionNegative(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterUnequal, ASF_Tree rhs)
{
  return (ASF_ASFCondition)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) typeOfRhs), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun10))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm) typeOfLhs), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun12))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun16)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterUnequal), (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(33)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun10)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(61)), (ATerm)ATmakeInt(33)))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_makeASFConditionEquality(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquality, ASF_Tree rhs) */

ASF_ASFCondition ASF_makeASFConditionEquality(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquality, ASF_Tree rhs)
{
  return (ASF_ASFCondition)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) typeOfRhs), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun18))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm) typeOfLhs), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun12))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun19)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterEquality), (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun18)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(61)), (ATerm)ATmakeInt(61)))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_makeASFConditionMatch(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterMatch, ASF_Tree rhs) */

ASF_ASFCondition ASF_makeASFConditionMatch(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterMatch, ASF_Tree rhs)
{
  return (ASF_ASFCondition)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) typeOfRhs), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun20))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm) typeOfLhs), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun12))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun21)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterMatch), (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(58)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun20)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(61)), (ATerm)ATmakeInt(58)))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_makeASFConditionNoMatch(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterMatch, ASF_Tree rhs) */

ASF_ASFCondition ASF_makeASFConditionNoMatch(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterMatch, ASF_Tree rhs)
{
  return (ASF_ASFCondition)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) typeOfRhs), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun22))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm) typeOfLhs), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun12))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun23)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterMatch), (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(58)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(33)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun22)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(61)), (ATerm)ATmakeInt(58)), (ATerm)ATmakeInt(33)))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  ASF_ASFConditions ASF_makeASFConditionsDefault(ASF_ASFConditionList list) */

ASF_ASFConditions ASF_makeASFConditionsDefault(ASF_ASFConditionList list)
{
  return (ASF_ASFConditions)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl2(ASF_afun24, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun12)), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun25))))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun26))), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl1(ASF_afun8, (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl2(ASF_afun24, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun12)), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun25))))), (ATerm) list)));
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_makeASFConditionListEmpty(void) */

ASF_ASFConditionList ASF_makeASFConditionListEmpty(void)
{
  return (ASF_ASFConditionList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_makeASFConditionListSingle(ASF_ASFCondition head) */

ASF_ASFConditionList ASF_makeASFConditionListSingle(ASF_ASFCondition head)
{
  return (ASF_ASFConditionList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_makeASFConditionListMany(ASF_ASFCondition head, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFConditionList tail) */

ASF_ASFConditionList ASF_makeASFConditionListMany(ASF_ASFCondition head, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFConditionList tail)
{
  if (ASF_isASFConditionListEmpty(tail)) {
    return ASF_makeASFConditionListSingle(head);
  }
  return (ASF_ASFConditionList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun25)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  ASF_LexASFBarEnd ASF_makeLexASFBarEndAbsent(void) */

ASF_LexASFBarEnd ASF_makeLexASFBarEndAbsent(void)
{
  return (ASF_LexASFBarEnd)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun27))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun28)))))), (ATerm)ATempty);
}

/*}}}  */
/*{{{  ASF_LexASFBarEnd ASF_makeLexASFBarEndPresent(void) */

ASF_LexASFBarEnd ASF_makeLexASFBarEndPresent(void)
{
  return (ASF_LexASFBarEnd)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(62)))), (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun27))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun29)))))), (ATerm)ATmakeList1((ATerm)ATmakeInt(62)));
}

/*}}}  */
/*{{{  ASF_ASFBarEnd ASF_makeASFBarEndLexToCf(ASF_LexASFBarEnd ASFBarEnd) */

ASF_ASFBarEnd ASF_makeASFBarEndLexToCf(ASF_LexASFBarEnd ASFBarEnd)
{
  return (ASF_ASFBarEnd)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun27)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun27))), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATmakeList1((ATerm) ASFBarEnd));
}

/*}}}  */
/*{{{  ASF_LexASFImplies ASF_makeLexASFImpliesDefault(const char* bar, ASF_LexASFBarEnd end) */

ASF_LexASFImplies ASF_makeLexASFImpliesDefault(const char* bar, ASF_LexASFBarEnd end)
{
  return (ASF_LexASFImplies)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun27)))), (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun30, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun31))), (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun32))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun33)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) end), (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl1(ASF_afun8, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun30, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))))), (ATerm) ((ATerm) ASF_stringToChars(bar)))), (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun31)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(61)), (ATerm)ATmakeInt(61)), (ATerm)ATmakeInt(61)))));
}

/*}}}  */
/*{{{  ASF_ASFImplies ASF_makeASFImpliesLexToCf(ASF_LexASFImplies ASFImplies) */

ASF_ASFImplies ASF_makeASFImpliesLexToCf(ASF_LexASFImplies ASFImplies)
{
  return (ASF_ASFImplies)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun32)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun32))), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATmakeList1((ATerm) ASFImplies));
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_makeASFConditionalEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation) */

ASF_ASFConditionalEquation ASF_makeASFConditionalEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation)
{
  return (ASF_ASFConditionalEquation)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun34)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun35)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun36))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun37)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) ASFEquation), (ATerm) wsAfterASFTag), (ATerm) ASFTag));
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_makeASFConditionalEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFEquation ASFEquation) */

ASF_ASFConditionalEquation ASF_makeASFConditionalEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFEquation ASFEquation)
{
  return (ASF_ASFConditionalEquation)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun34)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun32)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun26)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun35)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun36))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun38)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) ASFEquation), (ATerm) wsAfterASFImplies), (ATerm) ASFImplies), (ATerm) wsAfterASFConditions), (ATerm) ASFConditions), (ATerm) wsAfterASFTag), (ATerm) ASFTag));
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_makeASFConditionalEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation, ASF_OptLayout wsAfterASFEquation, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions) */

ASF_ASFConditionalEquation ASF_makeASFConditionalEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation, ASF_OptLayout wsAfterASFEquation, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions)
{
  return (ASF_ASFConditionalEquation)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun26)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun39))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun34)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun35)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun36))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun39)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) ASFConditions), (ATerm) wsAfterWhen), (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(104)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(119)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun39)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(104)), (ATerm)ATmakeInt(119)))), (ATerm) wsAfterASFEquation), (ATerm) ASFEquation), (ATerm) wsAfterASFTag), (ATerm) ASFTag));
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_makeASFEquationDefault(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquals, ASF_Tree rhs) */

ASF_ASFEquation ASF_makeASFEquationDefault(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquals, ASF_Tree rhs)
{
  return (ASF_ASFEquation)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) typeOfRhs), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun40))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm) typeOfLhs), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun34))), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterEquals), (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun40)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  ASF_Start ASF_makeStartASFModule(ASF_OptLayout wsBefore, ASF_ASFModule topASFModule, ASF_OptLayout wsAfter, int ambCnt) */

ASF_Start ASF_makeStartASFModule(ASF_OptLayout wsBefore, ASF_ASFModule topASFModule, ASF_OptLayout wsAfter, int ambCnt)
{
  return (ASF_Start)(ATerm)ATmakeAppl2(ASF_afun41, (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun42))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun43)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topASFModule), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  ASF_Start ASF_makeStartASFSection(ASF_OptLayout wsBefore, ASF_ASFSection topASFSection, ASF_OptLayout wsAfter, int ambCnt) */

ASF_Start ASF_makeStartASFSection(ASF_OptLayout wsBefore, ASF_ASFSection topASFSection, ASF_OptLayout wsAfter, int ambCnt)
{
  return (ASF_Start)(ATerm)ATmakeAppl2(ASF_afun41, (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun44))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun43)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topASFSection), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  ASF_ASFModule ASF_makeASFModuleDefault(ASF_ASFSectionList list) */

ASF_ASFModule ASF_makeASFModuleDefault(ASF_ASFSectionList list)
{
  return (ASF_ASFModule)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun30, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun44))))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun42))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun33)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl1(ASF_afun8, (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun30, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun44))))), (ATerm) list)));
}

/*}}}  */
/*{{{  ASF_ASFSection ASF_makeASFSectionEquations(ASF_OptLayout wsAfterEquations, ASF_ASFConditionalEquationList list) */

ASF_ASFSection ASF_makeASFSectionEquations(ASF_OptLayout wsAfterEquations, ASF_ASFConditionalEquationList list)
{
  return (ASF_ASFSection)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun30, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun36))))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun45))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun44))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun45)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl1(ASF_afun8, (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun30, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun36))))), (ATerm) list)), (ATerm) wsAfterEquations), (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(113)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun45)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(113)), (ATerm)ATmakeInt(101)))));
}

/*}}}  */
/*{{{  ASF_ASFSection ASF_makeASFSectionTests(ASF_OptLayout wsAfterTests, ASF_ASFTestEquationTestList testList) */

ASF_ASFSection ASF_makeASFSectionTests(ASF_OptLayout wsAfterTests, ASF_ASFTestEquationTestList testList)
{
  return (ASF_ASFSection)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun30, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun46))))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun47))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun44))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun47)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl1(ASF_afun8, (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun30, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun46))))), (ATerm) testList)), (ATerm) wsAfterTests), (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun47)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(116)))));
}

/*}}}  */
/*{{{  ASF_ASFSectionList ASF_makeASFSectionListEmpty(void) */

ASF_ASFSectionList ASF_makeASFSectionListEmpty(void)
{
  return (ASF_ASFSectionList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  ASF_ASFSectionList ASF_makeASFSectionListSingle(ASF_ASFSection head) */

ASF_ASFSectionList ASF_makeASFSectionListSingle(ASF_ASFSection head)
{
  return (ASF_ASFSectionList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  ASF_ASFSectionList ASF_makeASFSectionListMany(ASF_ASFSection head, ASF_OptLayout wsAfterHead, ASF_ASFSectionList tail) */

ASF_ASFSectionList ASF_makeASFSectionListMany(ASF_ASFSection head, ASF_OptLayout wsAfterHead, ASF_ASFSectionList tail)
{
  if (ASF_isASFSectionListEmpty(tail)) {
    return ASF_makeASFSectionListSingle(head);
  }
  return (ASF_ASFSectionList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListEmpty(void) */

ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListEmpty(void)
{
  return (ASF_ASFConditionalEquationList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListSingle(ASF_ASFConditionalEquation head) */

ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListSingle(ASF_ASFConditionalEquation head)
{
  return (ASF_ASFConditionalEquationList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListMany(ASF_ASFConditionalEquation head, ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquationList tail) */

ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListMany(ASF_ASFConditionalEquation head, ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquationList tail)
{
  if (ASF_isASFConditionalEquationListEmpty(tail)) {
    return ASF_makeASFConditionalEquationListSingle(head);
  }
  return (ASF_ASFConditionalEquationList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestListEmpty(void) */

ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestListEmpty(void)
{
  return (ASF_ASFTestEquationTestList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestListSingle(ASF_ASFTestEquation head) */

ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestListSingle(ASF_ASFTestEquation head)
{
  return (ASF_ASFTestEquationTestList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestListMany(ASF_ASFTestEquation head, ASF_OptLayout wsAfterHead, ASF_ASFTestEquationTestList tail) */

ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestListMany(ASF_ASFTestEquation head, ASF_OptLayout wsAfterHead, ASF_ASFTestEquationTestList tail)
{
  if (ASF_isASFTestEquationTestListEmpty(tail)) {
    return ASF_makeASFTestEquationTestListSingle(head);
  }
  return (ASF_ASFTestEquationTestList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  ASF_LexASFTagId ASF_makeLexASFTagIdOneChar(char head) */

ASF_LexASFTagId ASF_makeLexASFTagIdOneChar(char head)
{
  return (ASF_LexASFTagId)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))), (ATerm)ATmakeInt(39)), (ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun49))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun50)))), (ATerm)ATmakeAppl0(ASF_afun51)))), (ATerm)ATmakeList1((ATerm) ((ATerm) ASF_byteToChar(head))));
}

/*}}}  */
/*{{{  ASF_LexASFTagId ASF_makeLexASFTagIdManyChars(char head, const char* middle, char last) */

ASF_LexASFTagId ASF_makeLexASFTagIdManyChars(char head, const char* middle, char last)
{
  return (ASF_LexASFTagId)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))), (ATerm)ATmakeInt(39)), (ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun30, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(39)), (ATerm)ATmakeInt(34)))))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))), (ATerm)ATmakeInt(39)), (ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun49))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun52)))), (ATerm)ATmakeAppl0(ASF_afun51)))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) ((ATerm) ASF_byteToChar(last))), (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl1(ASF_afun8, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun30, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(39)), (ATerm)ATmakeInt(34)))))), (ATerm) ((ATerm) ASF_stringToChars(middle)))), (ATerm) ((ATerm) ASF_byteToChar(head))));
}

/*}}}  */
/*{{{  ASF_ASFTagId ASF_makeASFTagIdLexToCf(ASF_LexASFTagId ASFTagId) */

ASF_ASFTagId ASF_makeASFTagIdLexToCf(ASF_LexASFTagId ASFTagId)
{
  return (ASF_ASFTagId)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun49)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun49))), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATmakeList1((ATerm) ASFTagId));
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_makeASFTagEmpty(ASF_OptLayout wsAfterBracketOpen) */

ASF_ASFTag ASF_makeASFTagEmpty(ASF_OptLayout wsAfterBracketOpen)
{
  return (ASF_ASFTag)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun53))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun54))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun35))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun55)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun53)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun54)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))));
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_makeASFTagNotEmpty(ASF_OptLayout wsAfterBracketOpen, ASF_ASFTagId ASFTagId, ASF_OptLayout wsAfterASFTagId) */

ASF_ASFTag ASF_makeASFTagNotEmpty(ASF_OptLayout wsAfterBracketOpen, ASF_ASFTagId ASFTagId, ASF_OptLayout wsAfterASFTagId)
{
  return (ASF_ASFTag)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun53))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun49)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun54))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun35))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun56)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun53)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterASFTagId), (ATerm) ASFTagId), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun54)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))));
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_makeASFTestEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFCondition ASFCondition) */

ASF_ASFTestEquation ASF_makeASFTestEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFCondition ASFCondition)
{
  return (ASF_ASFTestEquation)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun12)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun35)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun46))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun37)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) ASFCondition), (ATerm) wsAfterASFTag), (ATerm) ASFTag));
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_makeASFTestEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFCondition ASFCondition) */

ASF_ASFTestEquation ASF_makeASFTestEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFCondition ASFCondition)
{
  return (ASF_ASFTestEquation)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun12)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun32)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun26)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun35)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun46))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun38)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) ASFCondition), (ATerm) wsAfterASFImplies), (ATerm) ASFImplies), (ATerm) wsAfterASFConditions), (ATerm) ASFConditions), (ATerm) wsAfterASFTag), (ATerm) ASFTag));
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_makeASFTestEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFCondition ASFCondition, ASF_OptLayout wsAfterASFCondition, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions) */

ASF_ASFTestEquation ASF_makeASFTestEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFCondition ASFCondition, ASF_OptLayout wsAfterASFCondition, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions)
{
  return (ASF_ASFTestEquation)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun26)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun39))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun12)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun4)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun35)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun46))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun39)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) ASFConditions), (ATerm) wsAfterWhen), (ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(104)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(119)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun39)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(104)), (ATerm)ATmakeInt(119)))), (ATerm) wsAfterASFCondition), (ATerm) ASFCondition), (ATerm) wsAfterASFTag), (ATerm) ASFTag));
}

/*}}}  */
/*{{{  ASF_LexLayout ASF_makeLexLayoutWhitespace(char ch) */

ASF_LexLayout ASF_makeLexLayoutWhitespace(char ch)
{
  return (ASF_LexLayout)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(32)), (ATerm)ATmakeInt(13)), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(9), (ATerm)ATmakeInt(10))))), (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl0(ASF_afun4)), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun57)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) ASF_byteToChar(ch))));
}

/*}}}  */
/*{{{  ASF_LexNumChar ASF_makeLexNumCharDigits(const char* number) */

ASF_LexNumChar ASF_makeLexNumCharDigits(const char* number)
{
  return (ASF_LexNumChar)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun58))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun59)))))), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl1(ASF_afun8, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm) ((ATerm) ASF_stringToChars(number)))), (ATerm)ATmakeInt(92)));
}

/*}}}  */
/*{{{  ASF_NumChar ASF_makeNumCharLexToCf(ASF_LexNumChar NumChar) */

ASF_NumChar ASF_makeNumCharLexToCf(ASF_LexNumChar NumChar)
{
  return (ASF_NumChar)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun58)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun58))), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATmakeList1((ATerm) NumChar));
}

/*}}}  */
/*{{{  ASF_LexShortChar ASF_makeLexShortCharRegular(char character) */

ASF_LexShortChar ASF_makeLexShortCharRegular(char character)
{
  return (ASF_LexShortChar)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun60))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun61)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) ASF_byteToChar(character))));
}

/*}}}  */
/*{{{  ASF_LexShortChar ASF_makeLexShortCharEscaped(char escape) */

ASF_LexShortChar ASF_makeLexShortCharEscaped(char escape)
{
  return (ASF_LexShortChar)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(123), (ATerm)ATmakeInt(255))), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(91), (ATerm)ATmakeInt(96))), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(58), (ATerm)ATmakeInt(64))), (ATerm)ATmakeAppl2(ASF_afun48, (ATerm)ATmakeInt(32), (ATerm)ATmakeInt(47))))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun60))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun62)))))), (ATerm)ATinsert(ATmakeList1((ATerm) ((ATerm) ASF_byteToChar(escape))), (ATerm)ATmakeInt(92)));
}

/*}}}  */
/*{{{  ASF_ShortChar ASF_makeShortCharLexToCf(ASF_LexShortChar ShortChar) */

ASF_ShortChar ASF_makeShortCharLexToCf(ASF_LexShortChar ShortChar)
{
  return (ASF_ShortChar)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun60)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun60))), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATmakeList1((ATerm) ShortChar));
}

/*}}}  */
/*{{{  ASF_Character ASF_makeCharacterNumeric(ASF_NumChar NumChar) */

ASF_Character ASF_makeCharacterNumeric(ASF_NumChar NumChar)
{
  return (ASF_Character)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun58)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun63))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun64)))))), (ATerm)ATmakeList1((ATerm) NumChar));
}

/*}}}  */
/*{{{  ASF_Character ASF_makeCharacterShort(ASF_ShortChar ShortChar) */

ASF_Character ASF_makeCharacterShort(ASF_ShortChar ShortChar)
{
  return (ASF_Character)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun60)))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun63))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun65)))))), (ATerm)ATmakeList1((ATerm) ShortChar));
}

/*}}}  */
/*{{{  ASF_Character ASF_makeCharacterTop(void) */

ASF_Character ASF_makeCharacterTop(void)
{
  return (ASF_Character)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun66))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun63))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun67)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(80)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(79)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(84)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun66)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(80)), (ATerm)ATmakeInt(79)), (ATerm)ATmakeInt(84)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  ASF_Character ASF_makeCharacterEof(void) */

ASF_Character ASF_makeCharacterEof(void)
{
  return (ASF_Character)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun68))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun63))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun69)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(70)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(79)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(69)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun68)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(70)), (ATerm)ATmakeInt(79)), (ATerm)ATmakeInt(69)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  ASF_Character ASF_makeCharacterBot(void) */

ASF_Character ASF_makeCharacterBot(void)
{
  return (ASF_Character)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun70))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun63))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun71)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(84)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(79)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(66)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun70)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(84)), (ATerm)ATmakeInt(79)), (ATerm)ATmakeInt(66)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  ASF_Character ASF_makeCharacterLabelUnderscoreStart(void) */

ASF_Character ASF_makeCharacterLabelUnderscoreStart(void)
{
  return (ASF_Character)(ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun72))), (ATerm)ATmakeAppl1(ASF_afun2, (ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun63))), (ATerm)ATmakeAppl1(ASF_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl0(ASF_afun73)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun0, (ATerm)ATmakeAppl3(ASF_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(84)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(82)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(65)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(84)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(83)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(95)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(76)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(69)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(66)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(65)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(76)))), (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(ASF_afun9, (ATerm)ATmakeAppl0(ASF_afun72)), (ATerm)ATmakeAppl0(ASF_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(84)), (ATerm)ATmakeInt(82)), (ATerm)ATmakeInt(65)), (ATerm)ATmakeInt(84)), (ATerm)ATmakeInt(83)), (ATerm)ATmakeInt(95)), (ATerm)ATmakeInt(76)), (ATerm)ATmakeInt(69)), (ATerm)ATmakeInt(66)), (ATerm)ATmakeInt(65)), (ATerm)ATmakeInt(76)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool ASF_isEqualOptLayout(ASF_OptLayout arg0, ASF_OptLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualLayout(ASF_Layout arg0, ASF_Layout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualLexLayoutList(ASF_LexLayoutList arg0, ASF_LexLayoutList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualTree(ASF_Tree arg0, ASF_Tree arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFCondition(ASF_ASFCondition arg0, ASF_ASFCondition arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFConditions(ASF_ASFConditions arg0, ASF_ASFConditions arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFConditionList(ASF_ASFConditionList arg0, ASF_ASFConditionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualLexASFBarEnd(ASF_LexASFBarEnd arg0, ASF_LexASFBarEnd arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFBarEnd(ASF_ASFBarEnd arg0, ASF_ASFBarEnd arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualLexASFImplies(ASF_LexASFImplies arg0, ASF_LexASFImplies arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFImplies(ASF_ASFImplies arg0, ASF_ASFImplies arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFConditionalEquation(ASF_ASFConditionalEquation arg0, ASF_ASFConditionalEquation arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFEquation(ASF_ASFEquation arg0, ASF_ASFEquation arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualStart(ASF_Start arg0, ASF_Start arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFModule(ASF_ASFModule arg0, ASF_ASFModule arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFSection(ASF_ASFSection arg0, ASF_ASFSection arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFSectionList(ASF_ASFSectionList arg0, ASF_ASFSectionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFConditionalEquationList(ASF_ASFConditionalEquationList arg0, ASF_ASFConditionalEquationList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFTestEquationTestList(ASF_ASFTestEquationTestList arg0, ASF_ASFTestEquationTestList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualLexASFTagId(ASF_LexASFTagId arg0, ASF_LexASFTagId arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFTagId(ASF_ASFTagId arg0, ASF_ASFTagId arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFTag(ASF_ASFTag arg0, ASF_ASFTag arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFTestEquation(ASF_ASFTestEquation arg0, ASF_ASFTestEquation arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualLexLayout(ASF_LexLayout arg0, ASF_LexLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualLexNumChar(ASF_LexNumChar arg0, ASF_LexNumChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualNumChar(ASF_NumChar arg0, ASF_NumChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualLexShortChar(ASF_LexShortChar arg0, ASF_LexShortChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualShortChar(ASF_ShortChar arg0, ASF_ShortChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualCharacter(ASF_Character arg0, ASF_Character arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  ASF_OptLayout accessors */

/*{{{  ATbool ASF_isValidOptLayout(ASF_OptLayout arg) */

ATbool ASF_isValidOptLayout(ASF_OptLayout arg)
{
  if (ASF_isOptLayoutAbsent(arg)) {
    return ATtrue;
  }
  else if (ASF_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isOptLayoutAbsent(ASF_OptLayout arg) */

inline ATbool ASF_isOptLayoutAbsent(ASF_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternOptLayoutAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isOptLayoutPresent(ASF_OptLayout arg) */

inline ATbool ASF_isOptLayoutPresent(ASF_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternOptLayoutPresent, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasOptLayoutLayout(ASF_OptLayout arg) */

ATbool ASF_hasOptLayoutLayout(ASF_OptLayout arg)
{
  if (ASF_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getOptLayoutLayout(ASF_OptLayout arg) */

ASF_Layout ASF_getOptLayoutLayout(ASF_OptLayout arg)
{
  
    return (ASF_Layout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_setOptLayoutLayout(ASF_OptLayout arg, ASF_Layout layout) */

ASF_OptLayout ASF_setOptLayoutLayout(ASF_OptLayout arg, ASF_Layout layout)
{
  if (ASF_isOptLayoutPresent(arg)) {
    return (ASF_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) layout), 0), 1);
  }

  ATabort("OptLayout has no Layout: %t\n", arg);
  return (ASF_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Layout accessors */

/*{{{  ATbool ASF_isValidLayout(ASF_Layout arg) */

ATbool ASF_isValidLayout(ASF_Layout arg)
{
  if (ASF_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isLayoutLexToCf(ASF_Layout arg) */

inline ATbool ASF_isLayoutLexToCf(ASF_Layout arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternLayoutLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasLayoutList(ASF_Layout arg) */

ATbool ASF_hasLayoutList(ASF_Layout arg)
{
  if (ASF_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_LexLayoutList ASF_getLayoutList(ASF_Layout arg) */

ASF_LexLayoutList ASF_getLayoutList(ASF_Layout arg)
{
  
    return (ASF_LexLayoutList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  ASF_Layout ASF_setLayoutList(ASF_Layout arg, ASF_LexLayoutList list) */

ASF_Layout ASF_setLayoutList(ASF_Layout arg, ASF_LexLayoutList list)
{
  if (ASF_isLayoutLexToCf(arg)) {
    return (ASF_Layout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) list), 1), 0), 1);
  }

  ATabort("Layout has no List: %t\n", arg);
  return (ASF_Layout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_LexLayoutList accessors */

/*{{{  ATbool ASF_isValidLexLayoutList(ASF_LexLayoutList arg) */

ATbool ASF_isValidLexLayoutList(ASF_LexLayoutList arg)
{
  if (ASF_isLexLayoutListEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isLexLayoutListEmpty(ASF_LexLayoutList arg) */

inline ATbool ASF_isLexLayoutListEmpty(ASF_LexLayoutList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternLexLayoutListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool ASF_isLexLayoutListSingle(ASF_LexLayoutList arg) */

inline ATbool ASF_isLexLayoutListSingle(ASF_LexLayoutList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternLexLayoutListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isLexLayoutListMany(ASF_LexLayoutList arg) */

inline ATbool ASF_isLexLayoutListMany(ASF_LexLayoutList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternLexLayoutListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasLexLayoutListHead(ASF_LexLayoutList arg) */

ATbool ASF_hasLexLayoutListHead(ASF_LexLayoutList arg)
{
  if (ASF_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasLexLayoutListTail(ASF_LexLayoutList arg) */

ATbool ASF_hasLexLayoutListTail(ASF_LexLayoutList arg)
{
  if (ASF_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_LexLayout ASF_getLexLayoutListHead(ASF_LexLayoutList arg) */

ASF_LexLayout ASF_getLexLayoutListHead(ASF_LexLayoutList arg)
{
  if (ASF_isLexLayoutListSingle(arg)) {
    return (ASF_LexLayout)ATgetFirst((ATermList)arg);
  }
  else 
    return (ASF_LexLayout)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ASF_LexLayoutList ASF_getLexLayoutListTail(ASF_LexLayoutList arg) */

ASF_LexLayoutList ASF_getLexLayoutListTail(ASF_LexLayoutList arg)
{
  
    return (ASF_LexLayoutList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  ASF_LexLayoutList ASF_setLexLayoutListHead(ASF_LexLayoutList arg, ASF_LexLayout head) */

ASF_LexLayoutList ASF_setLexLayoutListHead(ASF_LexLayoutList arg, ASF_LexLayout head)
{
  if (ASF_isLexLayoutListSingle(arg)) {
    return (ASF_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (ASF_isLexLayoutListMany(arg)) {
    return (ASF_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexLayoutList has no Head: %t\n", arg);
  return (ASF_LexLayoutList)NULL;
}

/*}}}  */
/*{{{  ASF_LexLayoutList ASF_setLexLayoutListTail(ASF_LexLayoutList arg, ASF_LexLayoutList tail) */

ASF_LexLayoutList ASF_setLexLayoutListTail(ASF_LexLayoutList arg, ASF_LexLayoutList tail)
{
  if (ASF_isLexLayoutListMany(arg)) {
    return (ASF_LexLayoutList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexLayoutList has no Tail: %t\n", arg);
  return (ASF_LexLayoutList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Tree accessors */

/*{{{  ATbool ASF_isValidTree(ASF_Tree arg) */

ATbool ASF_isValidTree(ASF_Tree arg)
{
  if (ASF_isTreeCast(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isTreeCast(ASF_Tree arg) */

inline ATbool ASF_isTreeCast(ASF_Tree arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternTreeCast, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeTree(ASF_Tree arg) */

ATbool ASF_hasTreeTree(ASF_Tree arg)
{
  if (ASF_isTreeCast(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm ASF_getTreeTree(ASF_Tree arg) */

ATerm ASF_getTreeTree(ASF_Tree arg)
{
  
    return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeTree(ASF_Tree arg, ATerm Tree) */

ASF_Tree ASF_setTreeTree(ASF_Tree arg, ATerm Tree)
{
  if (ASF_isTreeCast(arg)) {
    return (ASF_Tree)((ATerm) Tree);
  }

  ATabort("Tree has no Tree: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFCondition accessors */

/*{{{  ATbool ASF_isValidASFCondition(ASF_ASFCondition arg) */

ATbool ASF_isValidASFCondition(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionNegative(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNoMatch(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionNegative(ASF_ASFCondition arg) */

inline ATbool ASF_isASFConditionNegative(ASF_ASFCondition arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionNegative, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionEquality(ASF_ASFCondition arg) */

inline ATbool ASF_isASFConditionEquality(ASF_ASFCondition arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionEquality, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionMatch(ASF_ASFCondition arg) */

inline ATbool ASF_isASFConditionMatch(ASF_ASFCondition arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionMatch, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionNoMatch(ASF_ASFCondition arg) */

inline ATbool ASF_isASFConditionNoMatch(ASF_ASFCondition arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionNoMatch, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionTypeOfLhs(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionTypeOfLhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionNegative(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNoMatch(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionTypeOfRhs(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionTypeOfRhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionNegative(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNoMatch(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionLhs(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionLhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionNegative(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNoMatch(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionWsAfterLhs(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionWsAfterLhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionNegative(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNoMatch(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionWsAfterUnequal(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionWsAfterUnequal(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionRhs(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionRhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionNegative(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNoMatch(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionWsAfterEquality(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionWsAfterEquality(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionEquality(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionWsAfterMatch(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionWsAfterMatch(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionMatch(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNoMatch(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm ASF_getASFConditionTypeOfLhs(ASF_ASFCondition arg) */

ATerm ASF_getASFConditionTypeOfLhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionNegative(arg)) {
    return (ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return (ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return (ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
  }
  else 
    return (ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
}

/*}}}  */
/*{{{  ATerm ASF_getASFConditionTypeOfRhs(ASF_ASFCondition arg) */

ATerm ASF_getASFConditionTypeOfRhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionNegative(arg)) {
    return (ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return (ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return (ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
  }
  else 
    return (ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
}

/*}}}  */
/*{{{  ASF_Tree ASF_getASFConditionLhs(ASF_ASFCondition arg) */

ASF_Tree ASF_getASFConditionLhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionNegative(arg)) {
    return (ASF_Tree)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return (ASF_Tree)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return (ASF_Tree)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (ASF_Tree)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionWsAfterLhs(ASF_ASFCondition arg) */

ASF_OptLayout ASF_getASFConditionWsAfterLhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionNegative(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionWsAfterUnequal(ASF_ASFCondition arg) */

ASF_OptLayout ASF_getASFConditionWsAfterUnequal(ASF_ASFCondition arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_Tree ASF_getASFConditionRhs(ASF_ASFCondition arg) */

ASF_Tree ASF_getASFConditionRhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionNegative(arg)) {
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionWsAfterEquality(ASF_ASFCondition arg) */

ASF_OptLayout ASF_getASFConditionWsAfterEquality(ASF_ASFCondition arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionWsAfterMatch(ASF_ASFCondition arg) */

ASF_OptLayout ASF_getASFConditionWsAfterMatch(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionMatch(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionTypeOfLhs(ASF_ASFCondition arg, ATerm typeOfLhs) */

ASF_ASFCondition ASF_setASFConditionTypeOfLhs(ASF_ASFCondition arg, ATerm typeOfLhs)
{
  if (ASF_isASFConditionNegative(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) typeOfLhs), 0), 0), 0);
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) typeOfLhs), 0), 0), 0);
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) typeOfLhs), 0), 0), 0);
  }
  else if (ASF_isASFConditionNoMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) typeOfLhs), 0), 0), 0);
  }

  ATabort("ASFCondition has no TypeOfLhs: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionTypeOfRhs(ASF_ASFCondition arg, ATerm typeOfRhs) */

ASF_ASFCondition ASF_setASFConditionTypeOfRhs(ASF_ASFCondition arg, ATerm typeOfRhs)
{
  if (ASF_isASFConditionNegative(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) typeOfRhs), 4), 0), 0);
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) typeOfRhs), 4), 0), 0);
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) typeOfRhs), 4), 0), 0);
  }
  else if (ASF_isASFConditionNoMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) typeOfRhs), 4), 0), 0);
  }

  ATabort("ASFCondition has no TypeOfRhs: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionLhs(ASF_ASFCondition arg, ASF_Tree lhs) */

ASF_ASFCondition ASF_setASFConditionLhs(ASF_ASFCondition arg, ASF_Tree lhs)
{
  if (ASF_isASFConditionNegative(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }
  else if (ASF_isASFConditionNoMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }

  ATabort("ASFCondition has no Lhs: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionWsAfterLhs(ASF_ASFCondition arg, ASF_OptLayout wsAfterLhs) */

ASF_ASFCondition ASF_setASFConditionWsAfterLhs(ASF_ASFCondition arg, ASF_OptLayout wsAfterLhs)
{
  if (ASF_isASFConditionNegative(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }
  else if (ASF_isASFConditionNoMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }

  ATabort("ASFCondition has no WsAfterLhs: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionWsAfterUnequal(ASF_ASFCondition arg, ASF_OptLayout wsAfterUnequal) */

ASF_ASFCondition ASF_setASFConditionWsAfterUnequal(ASF_ASFCondition arg, ASF_OptLayout wsAfterUnequal)
{
  if (ASF_isASFConditionNegative(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterUnequal), 3), 1);
  }

  ATabort("ASFCondition has no WsAfterUnequal: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionRhs(ASF_ASFCondition arg, ASF_Tree rhs) */

ASF_ASFCondition ASF_setASFConditionRhs(ASF_ASFCondition arg, ASF_Tree rhs)
{
  if (ASF_isASFConditionNegative(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }
  else if (ASF_isASFConditionNoMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }

  ATabort("ASFCondition has no Rhs: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionWsAfterEquality(ASF_ASFCondition arg, ASF_OptLayout wsAfterEquality) */

ASF_ASFCondition ASF_setASFConditionWsAfterEquality(ASF_ASFCondition arg, ASF_OptLayout wsAfterEquality)
{
  if (ASF_isASFConditionEquality(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEquality), 3), 1);
  }

  ATabort("ASFCondition has no WsAfterEquality: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionWsAfterMatch(ASF_ASFCondition arg, ASF_OptLayout wsAfterMatch) */

ASF_ASFCondition ASF_setASFConditionWsAfterMatch(ASF_ASFCondition arg, ASF_OptLayout wsAfterMatch)
{
  if (ASF_isASFConditionMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterMatch), 3), 1);
  }
  else if (ASF_isASFConditionNoMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterMatch), 3), 1);
  }

  ATabort("ASFCondition has no WsAfterMatch: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFConditions accessors */

/*{{{  ATbool ASF_isValidASFConditions(ASF_ASFConditions arg) */

ATbool ASF_isValidASFConditions(ASF_ASFConditions arg)
{
  if (ASF_isASFConditionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionsDefault(ASF_ASFConditions arg) */

inline ATbool ASF_isASFConditionsDefault(ASF_ASFConditions arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternASFConditionsDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionsList(ASF_ASFConditions arg) */

ATbool ASF_hasASFConditionsList(ASF_ASFConditions arg)
{
  if (ASF_isASFConditionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_getASFConditionsList(ASF_ASFConditions arg) */

ASF_ASFConditionList ASF_getASFConditionsList(ASF_ASFConditions arg)
{
  
    return (ASF_ASFConditionList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  ASF_ASFConditions ASF_setASFConditionsList(ASF_ASFConditions arg, ASF_ASFConditionList list) */

ASF_ASFConditions ASF_setASFConditionsList(ASF_ASFConditions arg, ASF_ASFConditionList list)
{
  if (ASF_isASFConditionsDefault(arg)) {
    return (ASF_ASFConditions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) list), 1), 0), 1);
  }

  ATabort("ASFConditions has no List: %t\n", arg);
  return (ASF_ASFConditions)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFConditionList accessors */

/*{{{  ATbool ASF_isValidASFConditionList(ASF_ASFConditionList arg) */

ATbool ASF_isValidASFConditionList(ASF_ASFConditionList arg)
{
  if (ASF_isASFConditionListEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionListEmpty(ASF_ASFConditionList arg) */

inline ATbool ASF_isASFConditionListEmpty(ASF_ASFConditionList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternASFConditionListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionListSingle(ASF_ASFConditionList arg) */

inline ATbool ASF_isASFConditionListSingle(ASF_ASFConditionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionListMany(ASF_ASFConditionList arg) */

inline ATbool ASF_isASFConditionListMany(ASF_ASFConditionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionListMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionListHead(ASF_ASFConditionList arg) */

ATbool ASF_hasASFConditionListHead(ASF_ASFConditionList arg)
{
  if (ASF_isASFConditionListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionListWsAfterHead(ASF_ASFConditionList arg) */

ATbool ASF_hasASFConditionListWsAfterHead(ASF_ASFConditionList arg)
{
  if (ASF_isASFConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionListWsAfterSep(ASF_ASFConditionList arg) */

ATbool ASF_hasASFConditionListWsAfterSep(ASF_ASFConditionList arg)
{
  if (ASF_isASFConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionListTail(ASF_ASFConditionList arg) */

ATbool ASF_hasASFConditionListTail(ASF_ASFConditionList arg)
{
  if (ASF_isASFConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_getASFConditionListTail(ASF_ASFConditionList arg) */

ASF_ASFConditionList ASF_getASFConditionListTail(ASF_ASFConditionList arg)
{
  assert(!ASF_isASFConditionListEmpty(arg) && "getTail on an empty list");
  if (ASF_isASFConditionListSingle(arg)) {
    return (ASF_ASFConditionList) ASF_makeASFConditionListEmpty();
  }
  else {
  
    return (ASF_ASFConditionList)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_getASFConditionListHead(ASF_ASFConditionList arg) */

ASF_ASFCondition ASF_getASFConditionListHead(ASF_ASFConditionList arg)
{
  if (ASF_isASFConditionListSingle(arg)) {
    return (ASF_ASFCondition)ATgetFirst((ATermList)arg);
  }
  else 
    return (ASF_ASFCondition)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionListWsAfterHead(ASF_ASFConditionList arg) */

ASF_OptLayout ASF_getASFConditionListWsAfterHead(ASF_ASFConditionList arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionListWsAfterSep(ASF_ASFConditionList arg) */

ASF_OptLayout ASF_getASFConditionListWsAfterSep(ASF_ASFConditionList arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_setASFConditionListHead(ASF_ASFConditionList arg, ASF_ASFCondition head) */

ASF_ASFConditionList ASF_setASFConditionListHead(ASF_ASFConditionList arg, ASF_ASFCondition head)
{
  if (ASF_isASFConditionListSingle(arg)) {
    return (ASF_ASFConditionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (ASF_isASFConditionListMany(arg)) {
    return (ASF_ASFConditionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ASFConditionList has no Head: %t\n", arg);
  return (ASF_ASFConditionList)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_setASFConditionListWsAfterHead(ASF_ASFConditionList arg, ASF_OptLayout wsAfterHead) */

ASF_ASFConditionList ASF_setASFConditionListWsAfterHead(ASF_ASFConditionList arg, ASF_OptLayout wsAfterHead)
{
  if (ASF_isASFConditionListMany(arg)) {
    return (ASF_ASFConditionList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("ASFConditionList has no WsAfterHead: %t\n", arg);
  return (ASF_ASFConditionList)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_setASFConditionListWsAfterSep(ASF_ASFConditionList arg, ASF_OptLayout wsAfterSep) */

ASF_ASFConditionList ASF_setASFConditionListWsAfterSep(ASF_ASFConditionList arg, ASF_OptLayout wsAfterSep)
{
  if (ASF_isASFConditionListMany(arg)) {
    return (ASF_ASFConditionList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("ASFConditionList has no WsAfterSep: %t\n", arg);
  return (ASF_ASFConditionList)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_setASFConditionListTail(ASF_ASFConditionList arg, ASF_ASFConditionList tail) */

ASF_ASFConditionList ASF_setASFConditionListTail(ASF_ASFConditionList arg, ASF_ASFConditionList tail)
{
  if (ASF_isASFConditionListMany(arg)) {
    return (ASF_ASFConditionList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("ASFConditionList has no Tail: %t\n", arg);
  return (ASF_ASFConditionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_LexASFBarEnd accessors */

/*{{{  ATbool ASF_isValidLexASFBarEnd(ASF_LexASFBarEnd arg) */

ATbool ASF_isValidLexASFBarEnd(ASF_LexASFBarEnd arg)
{
  if (ASF_isLexASFBarEndAbsent(arg)) {
    return ATtrue;
  }
  else if (ASF_isLexASFBarEndPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isLexASFBarEndAbsent(ASF_LexASFBarEnd arg) */

inline ATbool ASF_isLexASFBarEndAbsent(ASF_LexASFBarEnd arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternLexASFBarEndAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isLexASFBarEndPresent(ASF_LexASFBarEnd arg) */

inline ATbool ASF_isLexASFBarEndPresent(ASF_LexASFBarEnd arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternLexASFBarEndPresent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFBarEnd accessors */

/*{{{  ATbool ASF_isValidASFBarEnd(ASF_ASFBarEnd arg) */

ATbool ASF_isValidASFBarEnd(ASF_ASFBarEnd arg)
{
  if (ASF_isASFBarEndLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFBarEndLexToCf(ASF_ASFBarEnd arg) */

inline ATbool ASF_isASFBarEndLexToCf(ASF_ASFBarEnd arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternASFBarEndLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFBarEndASFBarEnd(ASF_ASFBarEnd arg) */

ATbool ASF_hasASFBarEndASFBarEnd(ASF_ASFBarEnd arg)
{
  if (ASF_isASFBarEndLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_LexASFBarEnd ASF_getASFBarEndASFBarEnd(ASF_ASFBarEnd arg) */

ASF_LexASFBarEnd ASF_getASFBarEndASFBarEnd(ASF_ASFBarEnd arg)
{
  
    return (ASF_LexASFBarEnd)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_ASFBarEnd ASF_setASFBarEndASFBarEnd(ASF_ASFBarEnd arg, ASF_LexASFBarEnd ASFBarEnd) */

ASF_ASFBarEnd ASF_setASFBarEndASFBarEnd(ASF_ASFBarEnd arg, ASF_LexASFBarEnd ASFBarEnd)
{
  if (ASF_isASFBarEndLexToCf(arg)) {
    return (ASF_ASFBarEnd)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFBarEnd), 0), 1);
  }

  ATabort("ASFBarEnd has no ASFBarEnd: %t\n", arg);
  return (ASF_ASFBarEnd)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_LexASFImplies accessors */

/*{{{  ATbool ASF_isValidLexASFImplies(ASF_LexASFImplies arg) */

ATbool ASF_isValidLexASFImplies(ASF_LexASFImplies arg)
{
  if (ASF_isLexASFImpliesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isLexASFImpliesDefault(ASF_LexASFImplies arg) */

inline ATbool ASF_isLexASFImpliesDefault(ASF_LexASFImplies arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternLexASFImpliesDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasLexASFImpliesBar(ASF_LexASFImplies arg) */

ATbool ASF_hasLexASFImpliesBar(ASF_LexASFImplies arg)
{
  if (ASF_isLexASFImpliesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasLexASFImpliesEnd(ASF_LexASFImplies arg) */

ATbool ASF_hasLexASFImpliesEnd(ASF_LexASFImplies arg)
{
  if (ASF_isLexASFImpliesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ASF_getLexASFImpliesBar(ASF_LexASFImplies arg) */

char* ASF_getLexASFImpliesBar(ASF_LexASFImplies arg)
{
  
    return (char*)ASF_charsToString((ATerm)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), 1));
}

/*}}}  */
/*{{{  ASF_LexASFBarEnd ASF_getLexASFImpliesEnd(ASF_LexASFImplies arg) */

ASF_LexASFBarEnd ASF_getLexASFImpliesEnd(ASF_LexASFImplies arg)
{
  
    return (ASF_LexASFBarEnd)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  ASF_LexASFImplies ASF_setLexASFImpliesBar(ASF_LexASFImplies arg, const char* bar) */

ASF_LexASFImplies ASF_setLexASFImpliesBar(ASF_LexASFImplies arg, const char* bar)
{
  if (ASF_isLexASFImpliesDefault(arg)) {
    return (ASF_LexASFImplies)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), (ATerm)((ATerm) ((ATerm) ASF_stringToChars(bar))), 1), 1), 1);
  }

  ATabort("LexASFImplies has no Bar: %t\n", arg);
  return (ASF_LexASFImplies)NULL;
}

/*}}}  */
/*{{{  ASF_LexASFImplies ASF_setLexASFImpliesEnd(ASF_LexASFImplies arg, ASF_LexASFBarEnd end) */

ASF_LexASFImplies ASF_setLexASFImpliesEnd(ASF_LexASFImplies arg, ASF_LexASFBarEnd end)
{
  if (ASF_isLexASFImpliesDefault(arg)) {
    return (ASF_LexASFImplies)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) end), 2), 1);
  }

  ATabort("LexASFImplies has no End: %t\n", arg);
  return (ASF_LexASFImplies)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFImplies accessors */

/*{{{  ATbool ASF_isValidASFImplies(ASF_ASFImplies arg) */

ATbool ASF_isValidASFImplies(ASF_ASFImplies arg)
{
  if (ASF_isASFImpliesLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFImpliesLexToCf(ASF_ASFImplies arg) */

inline ATbool ASF_isASFImpliesLexToCf(ASF_ASFImplies arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternASFImpliesLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFImpliesASFImplies(ASF_ASFImplies arg) */

ATbool ASF_hasASFImpliesASFImplies(ASF_ASFImplies arg)
{
  if (ASF_isASFImpliesLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_LexASFImplies ASF_getASFImpliesASFImplies(ASF_ASFImplies arg) */

ASF_LexASFImplies ASF_getASFImpliesASFImplies(ASF_ASFImplies arg)
{
  
    return (ASF_LexASFImplies)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_ASFImplies ASF_setASFImpliesASFImplies(ASF_ASFImplies arg, ASF_LexASFImplies ASFImplies) */

ASF_ASFImplies ASF_setASFImpliesASFImplies(ASF_ASFImplies arg, ASF_LexASFImplies ASFImplies)
{
  if (ASF_isASFImpliesLexToCf(arg)) {
    return (ASF_ASFImplies)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFImplies), 0), 1);
  }

  ATabort("ASFImplies has no ASFImplies: %t\n", arg);
  return (ASF_ASFImplies)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFConditionalEquation accessors */

/*{{{  ATbool ASF_isValidASFConditionalEquation(ASF_ASFConditionalEquation arg) */

ATbool ASF_isValidASFConditionalEquation(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionalEquationSimple(ASF_ASFConditionalEquation arg) */

inline ATbool ASF_isASFConditionalEquationSimple(ASF_ASFConditionalEquation arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionalEquationSimple, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionalEquationImplies(ASF_ASFConditionalEquation arg) */

inline ATbool ASF_isASFConditionalEquationImplies(ASF_ASFConditionalEquation arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionalEquationImplies, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionalEquationWhen(ASF_ASFConditionalEquation arg) */

inline ATbool ASF_isASFConditionalEquationWhen(ASF_ASFConditionalEquation arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionalEquationWhen, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_getASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg) */

ASF_ASFTag ASF_getASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return (ASF_ASFTag)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFTag)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (ASF_ASFTag)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg) */

ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_getASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg) */

ASF_ASFEquation ASF_getASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return (ASF_ASFEquation)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFEquation)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
  }
  else 
    return (ASF_ASFEquation)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  ASF_ASFConditions ASF_getASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg) */

ASF_ASFConditions ASF_getASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (ASF_ASFConditions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg) */

ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_ASFImplies ASF_getASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg) */

ASF_ASFImplies ASF_getASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg)
{
  
    return (ASF_ASFImplies)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg) */

ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg) */

ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg) */

ASF_OptLayout ASF_getASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg, ASF_ASFTag ASFTag) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg, ASF_ASFTag ASFTag)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFTag), 0), 1);
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFTag), 0), 1);
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFTag), 0), 1);
  }

  ATabort("ASFConditionalEquation has no ASFTag: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFTag) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFTag)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterASFTag), 1), 1);
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterASFTag), 1), 1);
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterASFTag), 1), 1);
  }

  ATabort("ASFConditionalEquation has no WsAfterASFTag: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg, ASF_ASFEquation ASFEquation) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg, ASF_ASFEquation ASFEquation)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFEquation), 2), 1);
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFEquation), 6), 1);
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFEquation), 2), 1);
  }

  ATabort("ASFConditionalEquation has no ASFEquation: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg, ASF_ASFConditions ASFConditions) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg, ASF_ASFConditions ASFConditions)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFConditions), 2), 1);
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFConditions), 6), 1);
  }

  ATabort("ASFConditionalEquation has no ASFConditions: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFConditions) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFConditions)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterASFConditions), 3), 1);
  }

  ATabort("ASFConditionalEquation has no WsAfterASFConditions: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg, ASF_ASFImplies ASFImplies) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg, ASF_ASFImplies ASFImplies)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFImplies), 4), 1);
  }

  ATabort("ASFConditionalEquation has no ASFImplies: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFImplies) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFImplies)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterASFImplies), 5), 1);
  }

  ATabort("ASFConditionalEquation has no WsAfterASFImplies: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFEquation) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFEquation)
{
  if (ASF_isASFConditionalEquationWhen(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterASFEquation), 3), 1);
  }

  ATabort("ASFConditionalEquation has no WsAfterASFEquation: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterWhen) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterWhen)
{
  if (ASF_isASFConditionalEquationWhen(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterWhen), 5), 1);
  }

  ATabort("ASFConditionalEquation has no WsAfterWhen: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFEquation accessors */

/*{{{  ATbool ASF_isValidASFEquation(ASF_ASFEquation arg) */

ATbool ASF_isValidASFEquation(ASF_ASFEquation arg)
{
  if (ASF_isASFEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFEquationDefault(ASF_ASFEquation arg) */

inline ATbool ASF_isASFEquationDefault(ASF_ASFEquation arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternASFEquationDefault, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFEquationTypeOfLhs(ASF_ASFEquation arg) */

ATbool ASF_hasASFEquationTypeOfLhs(ASF_ASFEquation arg)
{
  if (ASF_isASFEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFEquationTypeOfRhs(ASF_ASFEquation arg) */

ATbool ASF_hasASFEquationTypeOfRhs(ASF_ASFEquation arg)
{
  if (ASF_isASFEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFEquationLhs(ASF_ASFEquation arg) */

ATbool ASF_hasASFEquationLhs(ASF_ASFEquation arg)
{
  if (ASF_isASFEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFEquationWsAfterLhs(ASF_ASFEquation arg) */

ATbool ASF_hasASFEquationWsAfterLhs(ASF_ASFEquation arg)
{
  if (ASF_isASFEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFEquationWsAfterEquals(ASF_ASFEquation arg) */

ATbool ASF_hasASFEquationWsAfterEquals(ASF_ASFEquation arg)
{
  if (ASF_isASFEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFEquationRhs(ASF_ASFEquation arg) */

ATbool ASF_hasASFEquationRhs(ASF_ASFEquation arg)
{
  if (ASF_isASFEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm ASF_getASFEquationTypeOfLhs(ASF_ASFEquation arg) */

ATerm ASF_getASFEquationTypeOfLhs(ASF_ASFEquation arg)
{
  
    return (ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
}

/*}}}  */
/*{{{  ATerm ASF_getASFEquationTypeOfRhs(ASF_ASFEquation arg) */

ATerm ASF_getASFEquationTypeOfRhs(ASF_ASFEquation arg)
{
  
    return (ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
}

/*}}}  */
/*{{{  ASF_Tree ASF_getASFEquationLhs(ASF_ASFEquation arg) */

ASF_Tree ASF_getASFEquationLhs(ASF_ASFEquation arg)
{
  
    return (ASF_Tree)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFEquationWsAfterLhs(ASF_ASFEquation arg) */

ASF_OptLayout ASF_getASFEquationWsAfterLhs(ASF_ASFEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFEquationWsAfterEquals(ASF_ASFEquation arg) */

ASF_OptLayout ASF_getASFEquationWsAfterEquals(ASF_ASFEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_Tree ASF_getASFEquationRhs(ASF_ASFEquation arg) */

ASF_Tree ASF_getASFEquationRhs(ASF_ASFEquation arg)
{
  
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_setASFEquationTypeOfLhs(ASF_ASFEquation arg, ATerm typeOfLhs) */

ASF_ASFEquation ASF_setASFEquationTypeOfLhs(ASF_ASFEquation arg, ATerm typeOfLhs)
{
  if (ASF_isASFEquationDefault(arg)) {
    return (ASF_ASFEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) typeOfLhs), 0), 0), 0);
  }

  ATabort("ASFEquation has no TypeOfLhs: %t\n", arg);
  return (ASF_ASFEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_setASFEquationTypeOfRhs(ASF_ASFEquation arg, ATerm typeOfRhs) */

ASF_ASFEquation ASF_setASFEquationTypeOfRhs(ASF_ASFEquation arg, ATerm typeOfRhs)
{
  if (ASF_isASFEquationDefault(arg)) {
    return (ASF_ASFEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) typeOfRhs), 4), 0), 0);
  }

  ATabort("ASFEquation has no TypeOfRhs: %t\n", arg);
  return (ASF_ASFEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_setASFEquationLhs(ASF_ASFEquation arg, ASF_Tree lhs) */

ASF_ASFEquation ASF_setASFEquationLhs(ASF_ASFEquation arg, ASF_Tree lhs)
{
  if (ASF_isASFEquationDefault(arg)) {
    return (ASF_ASFEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }

  ATabort("ASFEquation has no Lhs: %t\n", arg);
  return (ASF_ASFEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_setASFEquationWsAfterLhs(ASF_ASFEquation arg, ASF_OptLayout wsAfterLhs) */

ASF_ASFEquation ASF_setASFEquationWsAfterLhs(ASF_ASFEquation arg, ASF_OptLayout wsAfterLhs)
{
  if (ASF_isASFEquationDefault(arg)) {
    return (ASF_ASFEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }

  ATabort("ASFEquation has no WsAfterLhs: %t\n", arg);
  return (ASF_ASFEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_setASFEquationWsAfterEquals(ASF_ASFEquation arg, ASF_OptLayout wsAfterEquals) */

ASF_ASFEquation ASF_setASFEquationWsAfterEquals(ASF_ASFEquation arg, ASF_OptLayout wsAfterEquals)
{
  if (ASF_isASFEquationDefault(arg)) {
    return (ASF_ASFEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEquals), 3), 1);
  }

  ATabort("ASFEquation has no WsAfterEquals: %t\n", arg);
  return (ASF_ASFEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_setASFEquationRhs(ASF_ASFEquation arg, ASF_Tree rhs) */

ASF_ASFEquation ASF_setASFEquationRhs(ASF_ASFEquation arg, ASF_Tree rhs)
{
  if (ASF_isASFEquationDefault(arg)) {
    return (ASF_ASFEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }

  ATabort("ASFEquation has no Rhs: %t\n", arg);
  return (ASF_ASFEquation)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Start accessors */

/*{{{  ATbool ASF_isValidStart(ASF_Start arg) */

ATbool ASF_isValidStart(ASF_Start arg)
{
  if (ASF_isStartASFModule(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFSection(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isStartASFModule(ASF_Start arg) */

inline ATbool ASF_isStartASFModule(ASF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternStartASFModule, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isStartASFSection(ASF_Start arg) */

inline ATbool ASF_isStartASFSection(ASF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternStartASFSection, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasStartWsBefore(ASF_Start arg) */

ATbool ASF_hasStartWsBefore(ASF_Start arg)
{
  if (ASF_isStartASFModule(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFSection(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartTopASFModule(ASF_Start arg) */

ATbool ASF_hasStartTopASFModule(ASF_Start arg)
{
  if (ASF_isStartASFModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartWsAfter(ASF_Start arg) */

ATbool ASF_hasStartWsAfter(ASF_Start arg)
{
  if (ASF_isStartASFModule(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFSection(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartAmbCnt(ASF_Start arg) */

ATbool ASF_hasStartAmbCnt(ASF_Start arg)
{
  if (ASF_isStartASFModule(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFSection(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartTopASFSection(ASF_Start arg) */

ATbool ASF_hasStartTopASFSection(ASF_Start arg)
{
  if (ASF_isStartASFSection(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getStartWsBefore(ASF_Start arg) */

ASF_OptLayout ASF_getStartWsBefore(ASF_Start arg)
{
  if (ASF_isStartASFModule(arg)) {
    return (ASF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else 
    return (ASF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
}

/*}}}  */
/*{{{  ASF_ASFModule ASF_getStartTopASFModule(ASF_Start arg) */

ASF_ASFModule ASF_getStartTopASFModule(ASF_Start arg)
{
  
    return (ASF_ASFModule)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getStartWsAfter(ASF_Start arg) */

ASF_OptLayout ASF_getStartWsAfter(ASF_Start arg)
{
  if (ASF_isStartASFModule(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else 
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
}

/*}}}  */
/*{{{  int ASF_getStartAmbCnt(ASF_Start arg) */

int ASF_getStartAmbCnt(ASF_Start arg)
{
  if (ASF_isStartASFModule(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_ASFSection ASF_getStartTopASFSection(ASF_Start arg) */

ASF_ASFSection ASF_getStartTopASFSection(ASF_Start arg)
{
  
    return (ASF_ASFSection)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartWsBefore(ASF_Start arg, ASF_OptLayout wsBefore) */

ASF_Start ASF_setStartWsBefore(ASF_Start arg, ASF_OptLayout wsBefore)
{
  if (ASF_isStartASFModule(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (ASF_isStartASFSection(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }

  ATabort("Start has no WsBefore: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartTopASFModule(ASF_Start arg, ASF_ASFModule topASFModule) */

ASF_Start ASF_setStartTopASFModule(ASF_Start arg, ASF_ASFModule topASFModule)
{
  if (ASF_isStartASFModule(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topASFModule), 1), 1), 0);
  }

  ATabort("Start has no TopASFModule: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartWsAfter(ASF_Start arg, ASF_OptLayout wsAfter) */

ASF_Start ASF_setStartWsAfter(ASF_Start arg, ASF_OptLayout wsAfter)
{
  if (ASF_isStartASFModule(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (ASF_isStartASFSection(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }

  ATabort("Start has no WsAfter: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartAmbCnt(ASF_Start arg, int ambCnt) */

ASF_Start ASF_setStartAmbCnt(ASF_Start arg, int ambCnt)
{
  if (ASF_isStartASFModule(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (ASF_isStartASFSection(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }

  ATabort("Start has no AmbCnt: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartTopASFSection(ASF_Start arg, ASF_ASFSection topASFSection) */

ASF_Start ASF_setStartTopASFSection(ASF_Start arg, ASF_ASFSection topASFSection)
{
  if (ASF_isStartASFSection(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topASFSection), 1), 1), 0);
  }

  ATabort("Start has no TopASFSection: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFModule accessors */

/*{{{  ATbool ASF_isValidASFModule(ASF_ASFModule arg) */

ATbool ASF_isValidASFModule(ASF_ASFModule arg)
{
  if (ASF_isASFModuleDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFModuleDefault(ASF_ASFModule arg) */

inline ATbool ASF_isASFModuleDefault(ASF_ASFModule arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternASFModuleDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFModuleList(ASF_ASFModule arg) */

ATbool ASF_hasASFModuleList(ASF_ASFModule arg)
{
  if (ASF_isASFModuleDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFSectionList ASF_getASFModuleList(ASF_ASFModule arg) */

ASF_ASFSectionList ASF_getASFModuleList(ASF_ASFModule arg)
{
  
    return (ASF_ASFSectionList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  ASF_ASFModule ASF_setASFModuleList(ASF_ASFModule arg, ASF_ASFSectionList list) */

ASF_ASFModule ASF_setASFModuleList(ASF_ASFModule arg, ASF_ASFSectionList list)
{
  if (ASF_isASFModuleDefault(arg)) {
    return (ASF_ASFModule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) list), 1), 0), 1);
  }

  ATabort("ASFModule has no List: %t\n", arg);
  return (ASF_ASFModule)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFSection accessors */

/*{{{  ATbool ASF_isValidASFSection(ASF_ASFSection arg) */

ATbool ASF_isValidASFSection(ASF_ASFSection arg)
{
  if (ASF_isASFSectionEquations(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFSectionTests(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFSectionEquations(ASF_ASFSection arg) */

inline ATbool ASF_isASFSectionEquations(ASF_ASFSection arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFSectionEquations, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFSectionTests(ASF_ASFSection arg) */

inline ATbool ASF_isASFSectionTests(ASF_ASFSection arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFSectionTests, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFSectionWsAfterEquations(ASF_ASFSection arg) */

ATbool ASF_hasASFSectionWsAfterEquations(ASF_ASFSection arg)
{
  if (ASF_isASFSectionEquations(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFSectionList(ASF_ASFSection arg) */

ATbool ASF_hasASFSectionList(ASF_ASFSection arg)
{
  if (ASF_isASFSectionEquations(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFSectionWsAfterTests(ASF_ASFSection arg) */

ATbool ASF_hasASFSectionWsAfterTests(ASF_ASFSection arg)
{
  if (ASF_isASFSectionTests(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFSectionTestList(ASF_ASFSection arg) */

ATbool ASF_hasASFSectionTestList(ASF_ASFSection arg)
{
  if (ASF_isASFSectionTests(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFSectionWsAfterEquations(ASF_ASFSection arg) */

ASF_OptLayout ASF_getASFSectionWsAfterEquations(ASF_ASFSection arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_getASFSectionList(ASF_ASFSection arg) */

ASF_ASFConditionalEquationList ASF_getASFSectionList(ASF_ASFSection arg)
{
  
    return (ASF_ASFConditionalEquationList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFSectionWsAfterTests(ASF_ASFSection arg) */

ASF_OptLayout ASF_getASFSectionWsAfterTests(ASF_ASFSection arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFTestEquationTestList ASF_getASFSectionTestList(ASF_ASFSection arg) */

ASF_ASFTestEquationTestList ASF_getASFSectionTestList(ASF_ASFSection arg)
{
  
    return (ASF_ASFTestEquationTestList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  ASF_ASFSection ASF_setASFSectionWsAfterEquations(ASF_ASFSection arg, ASF_OptLayout wsAfterEquations) */

ASF_ASFSection ASF_setASFSectionWsAfterEquations(ASF_ASFSection arg, ASF_OptLayout wsAfterEquations)
{
  if (ASF_isASFSectionEquations(arg)) {
    return (ASF_ASFSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEquations), 1), 1);
  }

  ATabort("ASFSection has no WsAfterEquations: %t\n", arg);
  return (ASF_ASFSection)NULL;
}

/*}}}  */
/*{{{  ASF_ASFSection ASF_setASFSectionList(ASF_ASFSection arg, ASF_ASFConditionalEquationList list) */

ASF_ASFSection ASF_setASFSectionList(ASF_ASFSection arg, ASF_ASFConditionalEquationList list)
{
  if (ASF_isASFSectionEquations(arg)) {
    return (ASF_ASFSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) list), 1), 2), 1);
  }

  ATabort("ASFSection has no List: %t\n", arg);
  return (ASF_ASFSection)NULL;
}

/*}}}  */
/*{{{  ASF_ASFSection ASF_setASFSectionWsAfterTests(ASF_ASFSection arg, ASF_OptLayout wsAfterTests) */

ASF_ASFSection ASF_setASFSectionWsAfterTests(ASF_ASFSection arg, ASF_OptLayout wsAfterTests)
{
  if (ASF_isASFSectionTests(arg)) {
    return (ASF_ASFSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTests), 1), 1);
  }

  ATabort("ASFSection has no WsAfterTests: %t\n", arg);
  return (ASF_ASFSection)NULL;
}

/*}}}  */
/*{{{  ASF_ASFSection ASF_setASFSectionTestList(ASF_ASFSection arg, ASF_ASFTestEquationTestList testList) */

ASF_ASFSection ASF_setASFSectionTestList(ASF_ASFSection arg, ASF_ASFTestEquationTestList testList)
{
  if (ASF_isASFSectionTests(arg)) {
    return (ASF_ASFSection)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) testList), 1), 2), 1);
  }

  ATabort("ASFSection has no TestList: %t\n", arg);
  return (ASF_ASFSection)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFSectionList accessors */

/*{{{  ATbool ASF_isValidASFSectionList(ASF_ASFSectionList arg) */

ATbool ASF_isValidASFSectionList(ASF_ASFSectionList arg)
{
  if (ASF_isASFSectionListEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFSectionListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFSectionListEmpty(ASF_ASFSectionList arg) */

inline ATbool ASF_isASFSectionListEmpty(ASF_ASFSectionList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternASFSectionListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFSectionListSingle(ASF_ASFSectionList arg) */

inline ATbool ASF_isASFSectionListSingle(ASF_ASFSectionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFSectionListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFSectionListMany(ASF_ASFSectionList arg) */

inline ATbool ASF_isASFSectionListMany(ASF_ASFSectionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFSectionListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFSectionListHead(ASF_ASFSectionList arg) */

ATbool ASF_hasASFSectionListHead(ASF_ASFSectionList arg)
{
  if (ASF_isASFSectionListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFSectionListWsAfterHead(ASF_ASFSectionList arg) */

ATbool ASF_hasASFSectionListWsAfterHead(ASF_ASFSectionList arg)
{
  if (ASF_isASFSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFSectionListTail(ASF_ASFSectionList arg) */

ATbool ASF_hasASFSectionListTail(ASF_ASFSectionList arg)
{
  if (ASF_isASFSectionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFSectionList ASF_getASFSectionListTail(ASF_ASFSectionList arg) */

ASF_ASFSectionList ASF_getASFSectionListTail(ASF_ASFSectionList arg)
{
  assert(!ASF_isASFSectionListEmpty(arg) && "getTail on an empty list");
  if (ASF_isASFSectionListSingle(arg)) {
    return (ASF_ASFSectionList) ASF_makeASFSectionListEmpty();
  }
  else {
  
    return (ASF_ASFSectionList)ATgetTail((ATermList)arg, 2);
  }
}

/*}}}  */
/*{{{  ASF_ASFSection ASF_getASFSectionListHead(ASF_ASFSectionList arg) */

ASF_ASFSection ASF_getASFSectionListHead(ASF_ASFSectionList arg)
{
  if (ASF_isASFSectionListSingle(arg)) {
    return (ASF_ASFSection)ATgetFirst((ATermList)arg);
  }
  else 
    return (ASF_ASFSection)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFSectionListWsAfterHead(ASF_ASFSectionList arg) */

ASF_OptLayout ASF_getASFSectionListWsAfterHead(ASF_ASFSectionList arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  ASF_ASFSectionList ASF_setASFSectionListHead(ASF_ASFSectionList arg, ASF_ASFSection head) */

ASF_ASFSectionList ASF_setASFSectionListHead(ASF_ASFSectionList arg, ASF_ASFSection head)
{
  if (ASF_isASFSectionListSingle(arg)) {
    return (ASF_ASFSectionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (ASF_isASFSectionListMany(arg)) {
    return (ASF_ASFSectionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ASFSectionList has no Head: %t\n", arg);
  return (ASF_ASFSectionList)NULL;
}

/*}}}  */
/*{{{  ASF_ASFSectionList ASF_setASFSectionListWsAfterHead(ASF_ASFSectionList arg, ASF_OptLayout wsAfterHead) */

ASF_ASFSectionList ASF_setASFSectionListWsAfterHead(ASF_ASFSectionList arg, ASF_OptLayout wsAfterHead)
{
  if (ASF_isASFSectionListMany(arg)) {
    return (ASF_ASFSectionList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("ASFSectionList has no WsAfterHead: %t\n", arg);
  return (ASF_ASFSectionList)NULL;
}

/*}}}  */
/*{{{  ASF_ASFSectionList ASF_setASFSectionListTail(ASF_ASFSectionList arg, ASF_ASFSectionList tail) */

ASF_ASFSectionList ASF_setASFSectionListTail(ASF_ASFSectionList arg, ASF_ASFSectionList tail)
{
  if (ASF_isASFSectionListMany(arg)) {
    return (ASF_ASFSectionList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 2);
  }

  ATabort("ASFSectionList has no Tail: %t\n", arg);
  return (ASF_ASFSectionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList accessors */

/*{{{  ATbool ASF_isValidASFConditionalEquationList(ASF_ASFConditionalEquationList arg) */

ATbool ASF_isValidASFConditionalEquationList(ASF_ASFConditionalEquationList arg)
{
  if (ASF_isASFConditionalEquationListEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionalEquationListEmpty(ASF_ASFConditionalEquationList arg) */

inline ATbool ASF_isASFConditionalEquationListEmpty(ASF_ASFConditionalEquationList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternASFConditionalEquationListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionalEquationListSingle(ASF_ASFConditionalEquationList arg) */

inline ATbool ASF_isASFConditionalEquationListSingle(ASF_ASFConditionalEquationList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionalEquationListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionalEquationListMany(ASF_ASFConditionalEquationList arg) */

inline ATbool ASF_isASFConditionalEquationListMany(ASF_ASFConditionalEquationList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionalEquationListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg) */

ATbool ASF_hasASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg)
{
  if (ASF_isASFConditionalEquationListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationListWsAfterHead(ASF_ASFConditionalEquationList arg) */

ATbool ASF_hasASFConditionalEquationListWsAfterHead(ASF_ASFConditionalEquationList arg)
{
  if (ASF_isASFConditionalEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg) */

ATbool ASF_hasASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg)
{
  if (ASF_isASFConditionalEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_getASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg) */

ASF_ASFConditionalEquationList ASF_getASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg)
{
  assert(!ASF_isASFConditionalEquationListEmpty(arg) && "getTail on an empty list");
  if (ASF_isASFConditionalEquationListSingle(arg)) {
    return (ASF_ASFConditionalEquationList) ASF_makeASFConditionalEquationListEmpty();
  }
  else {
  
    return (ASF_ASFConditionalEquationList)ATgetTail((ATermList)arg, 2);
  }
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_getASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg) */

ASF_ASFConditionalEquation ASF_getASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg)
{
  if (ASF_isASFConditionalEquationListSingle(arg)) {
    return (ASF_ASFConditionalEquation)ATgetFirst((ATermList)arg);
  }
  else 
    return (ASF_ASFConditionalEquation)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionalEquationListWsAfterHead(ASF_ASFConditionalEquationList arg) */

ASF_OptLayout ASF_getASFConditionalEquationListWsAfterHead(ASF_ASFConditionalEquationList arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation head) */

ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation head)
{
  if (ASF_isASFConditionalEquationListSingle(arg)) {
    return (ASF_ASFConditionalEquationList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (ASF_isASFConditionalEquationListMany(arg)) {
    return (ASF_ASFConditionalEquationList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ASFConditionalEquationList has no Head: %t\n", arg);
  return (ASF_ASFConditionalEquationList)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListWsAfterHead(ASF_ASFConditionalEquationList arg, ASF_OptLayout wsAfterHead) */

ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListWsAfterHead(ASF_ASFConditionalEquationList arg, ASF_OptLayout wsAfterHead)
{
  if (ASF_isASFConditionalEquationListMany(arg)) {
    return (ASF_ASFConditionalEquationList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("ASFConditionalEquationList has no WsAfterHead: %t\n", arg);
  return (ASF_ASFConditionalEquationList)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquationList tail) */

ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquationList tail)
{
  if (ASF_isASFConditionalEquationListMany(arg)) {
    return (ASF_ASFConditionalEquationList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 2);
  }

  ATabort("ASFConditionalEquationList has no Tail: %t\n", arg);
  return (ASF_ASFConditionalEquationList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFTestEquationTestList accessors */

/*{{{  ATbool ASF_isValidASFTestEquationTestList(ASF_ASFTestEquationTestList arg) */

ATbool ASF_isValidASFTestEquationTestList(ASF_ASFTestEquationTestList arg)
{
  if (ASF_isASFTestEquationTestListEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTestEquationTestListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTestEquationTestListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFTestEquationTestListEmpty(ASF_ASFTestEquationTestList arg) */

inline ATbool ASF_isASFTestEquationTestListEmpty(ASF_ASFTestEquationTestList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternASFTestEquationTestListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFTestEquationTestListSingle(ASF_ASFTestEquationTestList arg) */

inline ATbool ASF_isASFTestEquationTestListSingle(ASF_ASFTestEquationTestList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFTestEquationTestListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFTestEquationTestListMany(ASF_ASFTestEquationTestList arg) */

inline ATbool ASF_isASFTestEquationTestListMany(ASF_ASFTestEquationTestList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFTestEquationTestListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTestEquationTestListHead(ASF_ASFTestEquationTestList arg) */

ATbool ASF_hasASFTestEquationTestListHead(ASF_ASFTestEquationTestList arg)
{
  if (ASF_isASFTestEquationTestListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTestEquationTestListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTestEquationTestListWsAfterHead(ASF_ASFTestEquationTestList arg) */

ATbool ASF_hasASFTestEquationTestListWsAfterHead(ASF_ASFTestEquationTestList arg)
{
  if (ASF_isASFTestEquationTestListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTestEquationTestListTail(ASF_ASFTestEquationTestList arg) */

ATbool ASF_hasASFTestEquationTestListTail(ASF_ASFTestEquationTestList arg)
{
  if (ASF_isASFTestEquationTestListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFTestEquationTestList ASF_getASFTestEquationTestListTail(ASF_ASFTestEquationTestList arg) */

ASF_ASFTestEquationTestList ASF_getASFTestEquationTestListTail(ASF_ASFTestEquationTestList arg)
{
  assert(!ASF_isASFTestEquationTestListEmpty(arg) && "getTail on an empty list");
  if (ASF_isASFTestEquationTestListSingle(arg)) {
    return (ASF_ASFTestEquationTestList) ASF_makeASFTestEquationTestListEmpty();
  }
  else {
  
    return (ASF_ASFTestEquationTestList)ATgetTail((ATermList)arg, 2);
  }
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_getASFTestEquationTestListHead(ASF_ASFTestEquationTestList arg) */

ASF_ASFTestEquation ASF_getASFTestEquationTestListHead(ASF_ASFTestEquationTestList arg)
{
  if (ASF_isASFTestEquationTestListSingle(arg)) {
    return (ASF_ASFTestEquation)ATgetFirst((ATermList)arg);
  }
  else 
    return (ASF_ASFTestEquation)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFTestEquationTestListWsAfterHead(ASF_ASFTestEquationTestList arg) */

ASF_OptLayout ASF_getASFTestEquationTestListWsAfterHead(ASF_ASFTestEquationTestList arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  ASF_ASFTestEquationTestList ASF_setASFTestEquationTestListHead(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquation head) */

ASF_ASFTestEquationTestList ASF_setASFTestEquationTestListHead(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquation head)
{
  if (ASF_isASFTestEquationTestListSingle(arg)) {
    return (ASF_ASFTestEquationTestList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (ASF_isASFTestEquationTestListMany(arg)) {
    return (ASF_ASFTestEquationTestList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ASFTestEquationTestList has no Head: %t\n", arg);
  return (ASF_ASFTestEquationTestList)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTestEquationTestList ASF_setASFTestEquationTestListWsAfterHead(ASF_ASFTestEquationTestList arg, ASF_OptLayout wsAfterHead) */

ASF_ASFTestEquationTestList ASF_setASFTestEquationTestListWsAfterHead(ASF_ASFTestEquationTestList arg, ASF_OptLayout wsAfterHead)
{
  if (ASF_isASFTestEquationTestListMany(arg)) {
    return (ASF_ASFTestEquationTestList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("ASFTestEquationTestList has no WsAfterHead: %t\n", arg);
  return (ASF_ASFTestEquationTestList)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTestEquationTestList ASF_setASFTestEquationTestListTail(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquationTestList tail) */

ASF_ASFTestEquationTestList ASF_setASFTestEquationTestListTail(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquationTestList tail)
{
  if (ASF_isASFTestEquationTestListMany(arg)) {
    return (ASF_ASFTestEquationTestList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 2);
  }

  ATabort("ASFTestEquationTestList has no Tail: %t\n", arg);
  return (ASF_ASFTestEquationTestList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_LexASFTagId accessors */

/*{{{  ATbool ASF_isValidLexASFTagId(ASF_LexASFTagId arg) */

ATbool ASF_isValidLexASFTagId(ASF_LexASFTagId arg)
{
  if (ASF_isLexASFTagIdOneChar(arg)) {
    return ATtrue;
  }
  else if (ASF_isLexASFTagIdManyChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isLexASFTagIdOneChar(ASF_LexASFTagId arg) */

inline ATbool ASF_isLexASFTagIdOneChar(ASF_LexASFTagId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternLexASFTagIdOneChar, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isLexASFTagIdManyChars(ASF_LexASFTagId arg) */

inline ATbool ASF_isLexASFTagIdManyChars(ASF_LexASFTagId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternLexASFTagIdManyChars, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasLexASFTagIdHead(ASF_LexASFTagId arg) */

ATbool ASF_hasLexASFTagIdHead(ASF_LexASFTagId arg)
{
  if (ASF_isLexASFTagIdOneChar(arg)) {
    return ATtrue;
  }
  else if (ASF_isLexASFTagIdManyChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasLexASFTagIdMiddle(ASF_LexASFTagId arg) */

ATbool ASF_hasLexASFTagIdMiddle(ASF_LexASFTagId arg)
{
  if (ASF_isLexASFTagIdManyChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasLexASFTagIdLast(ASF_LexASFTagId arg) */

ATbool ASF_hasLexASFTagIdLast(ASF_LexASFTagId arg)
{
  if (ASF_isLexASFTagIdManyChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char ASF_getLexASFTagIdHead(ASF_LexASFTagId arg) */

char ASF_getLexASFTagIdHead(ASF_LexASFTagId arg)
{
  if (ASF_isLexASFTagIdOneChar(arg)) {
    return (char)ASF_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
  }
  else 
    return (char)ASF_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  char* ASF_getLexASFTagIdMiddle(ASF_LexASFTagId arg) */

char* ASF_getLexASFTagIdMiddle(ASF_LexASFTagId arg)
{
  
    return (char*)ASF_charsToString((ATerm)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), 1));
}

/*}}}  */
/*{{{  char ASF_getLexASFTagIdLast(ASF_LexASFTagId arg) */

char ASF_getLexASFTagIdLast(ASF_LexASFTagId arg)
{
  
    return (char)ASF_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2));
}

/*}}}  */
/*{{{  ASF_LexASFTagId ASF_setLexASFTagIdHead(ASF_LexASFTagId arg, char head) */

ASF_LexASFTagId ASF_setLexASFTagIdHead(ASF_LexASFTagId arg, char head)
{
  if (ASF_isLexASFTagIdOneChar(arg)) {
    return (ASF_LexASFTagId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) ASF_byteToChar(head))), 0), 1);
  }
  else if (ASF_isLexASFTagIdManyChars(arg)) {
    return (ASF_LexASFTagId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) ASF_byteToChar(head))), 0), 1);
  }

  ATabort("LexASFTagId has no Head: %t\n", arg);
  return (ASF_LexASFTagId)NULL;
}

/*}}}  */
/*{{{  ASF_LexASFTagId ASF_setLexASFTagIdMiddle(ASF_LexASFTagId arg, const char* middle) */

ASF_LexASFTagId ASF_setLexASFTagIdMiddle(ASF_LexASFTagId arg, const char* middle)
{
  if (ASF_isLexASFTagIdManyChars(arg)) {
    return (ASF_LexASFTagId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), (ATerm)((ATerm) ((ATerm) ASF_stringToChars(middle))), 1), 1), 1);
  }

  ATabort("LexASFTagId has no Middle: %t\n", arg);
  return (ASF_LexASFTagId)NULL;
}

/*}}}  */
/*{{{  ASF_LexASFTagId ASF_setLexASFTagIdLast(ASF_LexASFTagId arg, char last) */

ASF_LexASFTagId ASF_setLexASFTagIdLast(ASF_LexASFTagId arg, char last)
{
  if (ASF_isLexASFTagIdManyChars(arg)) {
    return (ASF_LexASFTagId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) ASF_byteToChar(last))), 2), 1);
  }

  ATabort("LexASFTagId has no Last: %t\n", arg);
  return (ASF_LexASFTagId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFTagId accessors */

/*{{{  ATbool ASF_isValidASFTagId(ASF_ASFTagId arg) */

ATbool ASF_isValidASFTagId(ASF_ASFTagId arg)
{
  if (ASF_isASFTagIdLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFTagIdLexToCf(ASF_ASFTagId arg) */

inline ATbool ASF_isASFTagIdLexToCf(ASF_ASFTagId arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternASFTagIdLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTagIdASFTagId(ASF_ASFTagId arg) */

ATbool ASF_hasASFTagIdASFTagId(ASF_ASFTagId arg)
{
  if (ASF_isASFTagIdLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_LexASFTagId ASF_getASFTagIdASFTagId(ASF_ASFTagId arg) */

ASF_LexASFTagId ASF_getASFTagIdASFTagId(ASF_ASFTagId arg)
{
  
    return (ASF_LexASFTagId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_ASFTagId ASF_setASFTagIdASFTagId(ASF_ASFTagId arg, ASF_LexASFTagId ASFTagId) */

ASF_ASFTagId ASF_setASFTagIdASFTagId(ASF_ASFTagId arg, ASF_LexASFTagId ASFTagId)
{
  if (ASF_isASFTagIdLexToCf(arg)) {
    return (ASF_ASFTagId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFTagId), 0), 1);
  }

  ATabort("ASFTagId has no ASFTagId: %t\n", arg);
  return (ASF_ASFTagId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFTag accessors */

/*{{{  ATbool ASF_isValidASFTag(ASF_ASFTag arg) */

ATbool ASF_isValidASFTag(ASF_ASFTag arg)
{
  if (ASF_isASFTagEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFTagEmpty(ASF_ASFTag arg) */

inline ATbool ASF_isASFTagEmpty(ASF_ASFTag arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFTagEmpty, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFTagNotEmpty(ASF_ASFTag arg) */

inline ATbool ASF_isASFTagNotEmpty(ASF_ASFTag arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFTagNotEmpty, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTagWsAfterBracketOpen(ASF_ASFTag arg) */

ATbool ASF_hasASFTagWsAfterBracketOpen(ASF_ASFTag arg)
{
  if (ASF_isASFTagEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTagASFTagId(ASF_ASFTag arg) */

ATbool ASF_hasASFTagASFTagId(ASF_ASFTag arg)
{
  if (ASF_isASFTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTagWsAfterASFTagId(ASF_ASFTag arg) */

ATbool ASF_hasASFTagWsAfterASFTagId(ASF_ASFTag arg)
{
  if (ASF_isASFTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFTagWsAfterBracketOpen(ASF_ASFTag arg) */

ASF_OptLayout ASF_getASFTagWsAfterBracketOpen(ASF_ASFTag arg)
{
  if (ASF_isASFTagEmpty(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFTagId ASF_getASFTagASFTagId(ASF_ASFTag arg) */

ASF_ASFTagId ASF_getASFTagASFTagId(ASF_ASFTag arg)
{
  
    return (ASF_ASFTagId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFTagWsAfterASFTagId(ASF_ASFTag arg) */

ASF_OptLayout ASF_getASFTagWsAfterASFTagId(ASF_ASFTag arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_setASFTagWsAfterBracketOpen(ASF_ASFTag arg, ASF_OptLayout wsAfterBracketOpen) */

ASF_ASFTag ASF_setASFTagWsAfterBracketOpen(ASF_ASFTag arg, ASF_OptLayout wsAfterBracketOpen)
{
  if (ASF_isASFTagEmpty(arg)) {
    return (ASF_ASFTag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 1), 1);
  }
  else if (ASF_isASFTagNotEmpty(arg)) {
    return (ASF_ASFTag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 1), 1);
  }

  ATabort("ASFTag has no WsAfterBracketOpen: %t\n", arg);
  return (ASF_ASFTag)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_setASFTagASFTagId(ASF_ASFTag arg, ASF_ASFTagId ASFTagId) */

ASF_ASFTag ASF_setASFTagASFTagId(ASF_ASFTag arg, ASF_ASFTagId ASFTagId)
{
  if (ASF_isASFTagNotEmpty(arg)) {
    return (ASF_ASFTag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFTagId), 2), 1);
  }

  ATabort("ASFTag has no ASFTagId: %t\n", arg);
  return (ASF_ASFTag)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_setASFTagWsAfterASFTagId(ASF_ASFTag arg, ASF_OptLayout wsAfterASFTagId) */

ASF_ASFTag ASF_setASFTagWsAfterASFTagId(ASF_ASFTag arg, ASF_OptLayout wsAfterASFTagId)
{
  if (ASF_isASFTagNotEmpty(arg)) {
    return (ASF_ASFTag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterASFTagId), 3), 1);
  }

  ATabort("ASFTag has no WsAfterASFTagId: %t\n", arg);
  return (ASF_ASFTag)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFTestEquation accessors */

/*{{{  ATbool ASF_isValidASFTestEquation(ASF_ASFTestEquation arg) */

ATbool ASF_isValidASFTestEquation(ASF_ASFTestEquation arg)
{
  if (ASF_isASFTestEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTestEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTestEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFTestEquationSimple(ASF_ASFTestEquation arg) */

inline ATbool ASF_isASFTestEquationSimple(ASF_ASFTestEquation arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFTestEquationSimple, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFTestEquationImplies(ASF_ASFTestEquation arg) */

inline ATbool ASF_isASFTestEquationImplies(ASF_ASFTestEquation arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFTestEquationImplies, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFTestEquationWhen(ASF_ASFTestEquation arg) */

inline ATbool ASF_isASFTestEquationWhen(ASF_ASFTestEquation arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFTestEquationWhen, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTestEquationASFTag(ASF_ASFTestEquation arg) */

ATbool ASF_hasASFTestEquationASFTag(ASF_ASFTestEquation arg)
{
  if (ASF_isASFTestEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTestEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTestEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTestEquationWsAfterASFTag(ASF_ASFTestEquation arg) */

ATbool ASF_hasASFTestEquationWsAfterASFTag(ASF_ASFTestEquation arg)
{
  if (ASF_isASFTestEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTestEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTestEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTestEquationASFCondition(ASF_ASFTestEquation arg) */

ATbool ASF_hasASFTestEquationASFCondition(ASF_ASFTestEquation arg)
{
  if (ASF_isASFTestEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTestEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTestEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTestEquationASFConditions(ASF_ASFTestEquation arg) */

ATbool ASF_hasASFTestEquationASFConditions(ASF_ASFTestEquation arg)
{
  if (ASF_isASFTestEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTestEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTestEquationWsAfterASFConditions(ASF_ASFTestEquation arg) */

ATbool ASF_hasASFTestEquationWsAfterASFConditions(ASF_ASFTestEquation arg)
{
  if (ASF_isASFTestEquationImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTestEquationASFImplies(ASF_ASFTestEquation arg) */

ATbool ASF_hasASFTestEquationASFImplies(ASF_ASFTestEquation arg)
{
  if (ASF_isASFTestEquationImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTestEquationWsAfterASFImplies(ASF_ASFTestEquation arg) */

ATbool ASF_hasASFTestEquationWsAfterASFImplies(ASF_ASFTestEquation arg)
{
  if (ASF_isASFTestEquationImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTestEquationWsAfterASFCondition(ASF_ASFTestEquation arg) */

ATbool ASF_hasASFTestEquationWsAfterASFCondition(ASF_ASFTestEquation arg)
{
  if (ASF_isASFTestEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTestEquationWsAfterWhen(ASF_ASFTestEquation arg) */

ATbool ASF_hasASFTestEquationWsAfterWhen(ASF_ASFTestEquation arg)
{
  if (ASF_isASFTestEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_getASFTestEquationASFTag(ASF_ASFTestEquation arg) */

ASF_ASFTag ASF_getASFTestEquationASFTag(ASF_ASFTestEquation arg)
{
  if (ASF_isASFTestEquationSimple(arg)) {
    return (ASF_ASFTag)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isASFTestEquationImplies(arg)) {
    return (ASF_ASFTag)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (ASF_ASFTag)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFTestEquationWsAfterASFTag(ASF_ASFTestEquation arg) */

ASF_OptLayout ASF_getASFTestEquationWsAfterASFTag(ASF_ASFTestEquation arg)
{
  if (ASF_isASFTestEquationSimple(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (ASF_isASFTestEquationImplies(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_getASFTestEquationASFCondition(ASF_ASFTestEquation arg) */

ASF_ASFCondition ASF_getASFTestEquationASFCondition(ASF_ASFTestEquation arg)
{
  if (ASF_isASFTestEquationSimple(arg)) {
    return (ASF_ASFCondition)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (ASF_isASFTestEquationImplies(arg)) {
    return (ASF_ASFCondition)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
  }
  else 
    return (ASF_ASFCondition)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  ASF_ASFConditions ASF_getASFTestEquationASFConditions(ASF_ASFTestEquation arg) */

ASF_ASFConditions ASF_getASFTestEquationASFConditions(ASF_ASFTestEquation arg)
{
  if (ASF_isASFTestEquationImplies(arg)) {
    return (ASF_ASFConditions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (ASF_ASFConditions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFTestEquationWsAfterASFConditions(ASF_ASFTestEquation arg) */

ASF_OptLayout ASF_getASFTestEquationWsAfterASFConditions(ASF_ASFTestEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_ASFImplies ASF_getASFTestEquationASFImplies(ASF_ASFTestEquation arg) */

ASF_ASFImplies ASF_getASFTestEquationASFImplies(ASF_ASFTestEquation arg)
{
  
    return (ASF_ASFImplies)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFTestEquationWsAfterASFImplies(ASF_ASFTestEquation arg) */

ASF_OptLayout ASF_getASFTestEquationWsAfterASFImplies(ASF_ASFTestEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFTestEquationWsAfterASFCondition(ASF_ASFTestEquation arg) */

ASF_OptLayout ASF_getASFTestEquationWsAfterASFCondition(ASF_ASFTestEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFTestEquationWsAfterWhen(ASF_ASFTestEquation arg) */

ASF_OptLayout ASF_getASFTestEquationWsAfterWhen(ASF_ASFTestEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_setASFTestEquationASFTag(ASF_ASFTestEquation arg, ASF_ASFTag ASFTag) */

ASF_ASFTestEquation ASF_setASFTestEquationASFTag(ASF_ASFTestEquation arg, ASF_ASFTag ASFTag)
{
  if (ASF_isASFTestEquationSimple(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFTag), 0), 1);
  }
  else if (ASF_isASFTestEquationImplies(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFTag), 0), 1);
  }
  else if (ASF_isASFTestEquationWhen(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFTag), 0), 1);
  }

  ATabort("ASFTestEquation has no ASFTag: %t\n", arg);
  return (ASF_ASFTestEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFTag(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFTag) */

ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFTag(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFTag)
{
  if (ASF_isASFTestEquationSimple(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterASFTag), 1), 1);
  }
  else if (ASF_isASFTestEquationImplies(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterASFTag), 1), 1);
  }
  else if (ASF_isASFTestEquationWhen(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterASFTag), 1), 1);
  }

  ATabort("ASFTestEquation has no WsAfterASFTag: %t\n", arg);
  return (ASF_ASFTestEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_setASFTestEquationASFCondition(ASF_ASFTestEquation arg, ASF_ASFCondition ASFCondition) */

ASF_ASFTestEquation ASF_setASFTestEquationASFCondition(ASF_ASFTestEquation arg, ASF_ASFCondition ASFCondition)
{
  if (ASF_isASFTestEquationSimple(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFCondition), 2), 1);
  }
  else if (ASF_isASFTestEquationImplies(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFCondition), 6), 1);
  }
  else if (ASF_isASFTestEquationWhen(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFCondition), 2), 1);
  }

  ATabort("ASFTestEquation has no ASFCondition: %t\n", arg);
  return (ASF_ASFTestEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_setASFTestEquationASFConditions(ASF_ASFTestEquation arg, ASF_ASFConditions ASFConditions) */

ASF_ASFTestEquation ASF_setASFTestEquationASFConditions(ASF_ASFTestEquation arg, ASF_ASFConditions ASFConditions)
{
  if (ASF_isASFTestEquationImplies(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFConditions), 2), 1);
  }
  else if (ASF_isASFTestEquationWhen(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFConditions), 6), 1);
  }

  ATabort("ASFTestEquation has no ASFConditions: %t\n", arg);
  return (ASF_ASFTestEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFConditions(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFConditions) */

ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFConditions(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFConditions)
{
  if (ASF_isASFTestEquationImplies(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterASFConditions), 3), 1);
  }

  ATabort("ASFTestEquation has no WsAfterASFConditions: %t\n", arg);
  return (ASF_ASFTestEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_setASFTestEquationASFImplies(ASF_ASFTestEquation arg, ASF_ASFImplies ASFImplies) */

ASF_ASFTestEquation ASF_setASFTestEquationASFImplies(ASF_ASFTestEquation arg, ASF_ASFImplies ASFImplies)
{
  if (ASF_isASFTestEquationImplies(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ASFImplies), 4), 1);
  }

  ATabort("ASFTestEquation has no ASFImplies: %t\n", arg);
  return (ASF_ASFTestEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFImplies(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFImplies) */

ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFImplies(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFImplies)
{
  if (ASF_isASFTestEquationImplies(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterASFImplies), 5), 1);
  }

  ATabort("ASFTestEquation has no WsAfterASFImplies: %t\n", arg);
  return (ASF_ASFTestEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFCondition(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFCondition) */

ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFCondition(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFCondition)
{
  if (ASF_isASFTestEquationWhen(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterASFCondition), 3), 1);
  }

  ATabort("ASFTestEquation has no WsAfterASFCondition: %t\n", arg);
  return (ASF_ASFTestEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_setASFTestEquationWsAfterWhen(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterWhen) */

ASF_ASFTestEquation ASF_setASFTestEquationWsAfterWhen(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterWhen)
{
  if (ASF_isASFTestEquationWhen(arg)) {
    return (ASF_ASFTestEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterWhen), 5), 1);
  }

  ATabort("ASFTestEquation has no WsAfterWhen: %t\n", arg);
  return (ASF_ASFTestEquation)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_LexLayout accessors */

/*{{{  ATbool ASF_isValidLexLayout(ASF_LexLayout arg) */

ATbool ASF_isValidLexLayout(ASF_LexLayout arg)
{
  if (ASF_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isLexLayoutWhitespace(ASF_LexLayout arg) */

inline ATbool ASF_isLexLayoutWhitespace(ASF_LexLayout arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternLexLayoutWhitespace, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasLexLayoutCh(ASF_LexLayout arg) */

ATbool ASF_hasLexLayoutCh(ASF_LexLayout arg)
{
  if (ASF_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char ASF_getLexLayoutCh(ASF_LexLayout arg) */

char ASF_getLexLayoutCh(ASF_LexLayout arg)
{
  
    return (char)ASF_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  ASF_LexLayout ASF_setLexLayoutCh(ASF_LexLayout arg, char ch) */

ASF_LexLayout ASF_setLexLayoutCh(ASF_LexLayout arg, char ch)
{
  if (ASF_isLexLayoutWhitespace(arg)) {
    return (ASF_LexLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) ASF_byteToChar(ch))), 0), 1);
  }

  ATabort("LexLayout has no Ch: %t\n", arg);
  return (ASF_LexLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_LexNumChar accessors */

/*{{{  ATbool ASF_isValidLexNumChar(ASF_LexNumChar arg) */

ATbool ASF_isValidLexNumChar(ASF_LexNumChar arg)
{
  if (ASF_isLexNumCharDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isLexNumCharDigits(ASF_LexNumChar arg) */

inline ATbool ASF_isLexNumCharDigits(ASF_LexNumChar arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternLexNumCharDigits, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasLexNumCharNumber(ASF_LexNumChar arg) */

ATbool ASF_hasLexNumCharNumber(ASF_LexNumChar arg)
{
  if (ASF_isLexNumCharDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ASF_getLexNumCharNumber(ASF_LexNumChar arg) */

char* ASF_getLexNumCharNumber(ASF_LexNumChar arg)
{
  
    return (char*)ASF_charsToString((ATerm)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), 1));
}

/*}}}  */
/*{{{  ASF_LexNumChar ASF_setLexNumCharNumber(ASF_LexNumChar arg, const char* number) */

ASF_LexNumChar ASF_setLexNumCharNumber(ASF_LexNumChar arg, const char* number)
{
  if (ASF_isLexNumCharDigits(arg)) {
    return (ASF_LexNumChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), (ATerm)((ATerm) ((ATerm) ASF_stringToChars(number))), 1), 1), 1);
  }

  ATabort("LexNumChar has no Number: %t\n", arg);
  return (ASF_LexNumChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_NumChar accessors */

/*{{{  ATbool ASF_isValidNumChar(ASF_NumChar arg) */

ATbool ASF_isValidNumChar(ASF_NumChar arg)
{
  if (ASF_isNumCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isNumCharLexToCf(ASF_NumChar arg) */

inline ATbool ASF_isNumCharLexToCf(ASF_NumChar arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternNumCharLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasNumCharNumChar(ASF_NumChar arg) */

ATbool ASF_hasNumCharNumChar(ASF_NumChar arg)
{
  if (ASF_isNumCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_LexNumChar ASF_getNumCharNumChar(ASF_NumChar arg) */

ASF_LexNumChar ASF_getNumCharNumChar(ASF_NumChar arg)
{
  
    return (ASF_LexNumChar)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_NumChar ASF_setNumCharNumChar(ASF_NumChar arg, ASF_LexNumChar NumChar) */

ASF_NumChar ASF_setNumCharNumChar(ASF_NumChar arg, ASF_LexNumChar NumChar)
{
  if (ASF_isNumCharLexToCf(arg)) {
    return (ASF_NumChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NumChar), 0), 1);
  }

  ATabort("NumChar has no NumChar: %t\n", arg);
  return (ASF_NumChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_LexShortChar accessors */

/*{{{  ATbool ASF_isValidLexShortChar(ASF_LexShortChar arg) */

ATbool ASF_isValidLexShortChar(ASF_LexShortChar arg)
{
  if (ASF_isLexShortCharRegular(arg)) {
    return ATtrue;
  }
  else if (ASF_isLexShortCharEscaped(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isLexShortCharRegular(ASF_LexShortChar arg) */

inline ATbool ASF_isLexShortCharRegular(ASF_LexShortChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternLexShortCharRegular, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isLexShortCharEscaped(ASF_LexShortChar arg) */

inline ATbool ASF_isLexShortCharEscaped(ASF_LexShortChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternLexShortCharEscaped, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasLexShortCharCharacter(ASF_LexShortChar arg) */

ATbool ASF_hasLexShortCharCharacter(ASF_LexShortChar arg)
{
  if (ASF_isLexShortCharRegular(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasLexShortCharEscape(ASF_LexShortChar arg) */

ATbool ASF_hasLexShortCharEscape(ASF_LexShortChar arg)
{
  if (ASF_isLexShortCharEscaped(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char ASF_getLexShortCharCharacter(ASF_LexShortChar arg) */

char ASF_getLexShortCharCharacter(ASF_LexShortChar arg)
{
  
    return (char)ASF_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  char ASF_getLexShortCharEscape(ASF_LexShortChar arg) */

char ASF_getLexShortCharEscape(ASF_LexShortChar arg)
{
  
    return (char)ASF_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1));
}

/*}}}  */
/*{{{  ASF_LexShortChar ASF_setLexShortCharCharacter(ASF_LexShortChar arg, char character) */

ASF_LexShortChar ASF_setLexShortCharCharacter(ASF_LexShortChar arg, char character)
{
  if (ASF_isLexShortCharRegular(arg)) {
    return (ASF_LexShortChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) ASF_byteToChar(character))), 0), 1);
  }

  ATabort("LexShortChar has no Character: %t\n", arg);
  return (ASF_LexShortChar)NULL;
}

/*}}}  */
/*{{{  ASF_LexShortChar ASF_setLexShortCharEscape(ASF_LexShortChar arg, char escape) */

ASF_LexShortChar ASF_setLexShortCharEscape(ASF_LexShortChar arg, char escape)
{
  if (ASF_isLexShortCharEscaped(arg)) {
    return (ASF_LexShortChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) ASF_byteToChar(escape))), 1), 1);
  }

  ATabort("LexShortChar has no Escape: %t\n", arg);
  return (ASF_LexShortChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ShortChar accessors */

/*{{{  ATbool ASF_isValidShortChar(ASF_ShortChar arg) */

ATbool ASF_isValidShortChar(ASF_ShortChar arg)
{
  if (ASF_isShortCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isShortCharLexToCf(ASF_ShortChar arg) */

inline ATbool ASF_isShortCharLexToCf(ASF_ShortChar arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternShortCharLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasShortCharShortChar(ASF_ShortChar arg) */

ATbool ASF_hasShortCharShortChar(ASF_ShortChar arg)
{
  if (ASF_isShortCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_LexShortChar ASF_getShortCharShortChar(ASF_ShortChar arg) */

ASF_LexShortChar ASF_getShortCharShortChar(ASF_ShortChar arg)
{
  
    return (ASF_LexShortChar)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_ShortChar ASF_setShortCharShortChar(ASF_ShortChar arg, ASF_LexShortChar ShortChar) */

ASF_ShortChar ASF_setShortCharShortChar(ASF_ShortChar arg, ASF_LexShortChar ShortChar)
{
  if (ASF_isShortCharLexToCf(arg)) {
    return (ASF_ShortChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ShortChar), 0), 1);
  }

  ATabort("ShortChar has no ShortChar: %t\n", arg);
  return (ASF_ShortChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Character accessors */

/*{{{  ATbool ASF_isValidCharacter(ASF_Character arg) */

ATbool ASF_isValidCharacter(ASF_Character arg)
{
  if (ASF_isCharacterNumeric(arg)) {
    return ATtrue;
  }
  else if (ASF_isCharacterShort(arg)) {
    return ATtrue;
  }
  else if (ASF_isCharacterTop(arg)) {
    return ATtrue;
  }
  else if (ASF_isCharacterEof(arg)) {
    return ATtrue;
  }
  else if (ASF_isCharacterBot(arg)) {
    return ATtrue;
  }
  else if (ASF_isCharacterLabelUnderscoreStart(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isCharacterNumeric(ASF_Character arg) */

inline ATbool ASF_isCharacterNumeric(ASF_Character arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternCharacterNumeric, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isCharacterShort(ASF_Character arg) */

inline ATbool ASF_isCharacterShort(ASF_Character arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternCharacterShort, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isCharacterTop(ASF_Character arg) */

inline ATbool ASF_isCharacterTop(ASF_Character arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternCharacterTop);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isCharacterEof(ASF_Character arg) */

inline ATbool ASF_isCharacterEof(ASF_Character arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternCharacterEof);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isCharacterBot(ASF_Character arg) */

inline ATbool ASF_isCharacterBot(ASF_Character arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternCharacterBot);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isCharacterLabelUnderscoreStart(ASF_Character arg) */

inline ATbool ASF_isCharacterLabelUnderscoreStart(ASF_Character arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternCharacterLabelUnderscoreStart);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasCharacterNumChar(ASF_Character arg) */

ATbool ASF_hasCharacterNumChar(ASF_Character arg)
{
  if (ASF_isCharacterNumeric(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasCharacterShortChar(ASF_Character arg) */

ATbool ASF_hasCharacterShortChar(ASF_Character arg)
{
  if (ASF_isCharacterShort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_NumChar ASF_getCharacterNumChar(ASF_Character arg) */

ASF_NumChar ASF_getCharacterNumChar(ASF_Character arg)
{
  
    return (ASF_NumChar)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_ShortChar ASF_getCharacterShortChar(ASF_Character arg) */

ASF_ShortChar ASF_getCharacterShortChar(ASF_Character arg)
{
  
    return (ASF_ShortChar)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_Character ASF_setCharacterNumChar(ASF_Character arg, ASF_NumChar NumChar) */

ASF_Character ASF_setCharacterNumChar(ASF_Character arg, ASF_NumChar NumChar)
{
  if (ASF_isCharacterNumeric(arg)) {
    return (ASF_Character)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NumChar), 0), 1);
  }

  ATabort("Character has no NumChar: %t\n", arg);
  return (ASF_Character)NULL;
}

/*}}}  */
/*{{{  ASF_Character ASF_setCharacterShortChar(ASF_Character arg, ASF_ShortChar ShortChar) */

ASF_Character ASF_setCharacterShortChar(ASF_Character arg, ASF_ShortChar ShortChar)
{
  if (ASF_isCharacterShort(arg)) {
    return (ASF_Character)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ShortChar), 0), 1);
  }

  ATabort("Character has no ShortChar: %t\n", arg);
  return (ASF_Character)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  ASF_OptLayout ASF_visitOptLayout(ASF_OptLayout arg, ASF_Layout (*acceptLayout)(ASF_Layout)) */

ASF_OptLayout ASF_visitOptLayout(ASF_OptLayout arg, ASF_Layout (*acceptLayout)(ASF_Layout))
{
  if (ASF_isOptLayoutAbsent(arg)) {
    return ASF_makeOptLayoutAbsent();
  }
  if (ASF_isOptLayoutPresent(arg)) {
    return ASF_makeOptLayoutPresent(
        acceptLayout ? acceptLayout(ASF_getOptLayoutLayout(arg)) : ASF_getOptLayoutLayout(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (ASF_OptLayout)NULL;
}

/*}}}  */
/*{{{  ASF_Layout ASF_visitLayout(ASF_Layout arg, ASF_LexLayoutList (*acceptList)(ASF_LexLayoutList)) */

ASF_Layout ASF_visitLayout(ASF_Layout arg, ASF_LexLayoutList (*acceptList)(ASF_LexLayoutList))
{
  if (ASF_isLayoutLexToCf(arg)) {
    return ASF_makeLayoutLexToCf(
        acceptList ? acceptList(ASF_getLayoutList(arg)) : ASF_getLayoutList(arg));
  }
  ATabort("not a Layout: %t\n", arg);
  return (ASF_Layout)NULL;
}

/*}}}  */
/*{{{  ASF_LexLayoutList ASF_visitLexLayoutList(ASF_LexLayoutList arg, ASF_LexLayout (*acceptHead)(ASF_LexLayout)) */

ASF_LexLayoutList ASF_visitLexLayoutList(ASF_LexLayoutList arg, ASF_LexLayout (*acceptHead)(ASF_LexLayout))
{
  if (ASF_isLexLayoutListEmpty(arg)) {
    return ASF_makeLexLayoutListEmpty();
  }
  if (ASF_isLexLayoutListSingle(arg)) {
    return ASF_makeLexLayoutListSingle(
        acceptHead ? acceptHead(ASF_getLexLayoutListHead(arg)) : ASF_getLexLayoutListHead(arg));
  }
  if (ASF_isLexLayoutListMany(arg)) {
    return ASF_makeLexLayoutListMany(
        acceptHead ? acceptHead(ASF_getLexLayoutListHead(arg)) : ASF_getLexLayoutListHead(arg),
        ASF_visitLexLayoutList(ASF_getLexLayoutListTail(arg), acceptHead));
  }
  ATabort("not a LexLayoutList: %t\n", arg);
  return (ASF_LexLayoutList)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_visitTree(ASF_Tree arg, ATerm (*acceptTree)(ATerm)) */

ASF_Tree ASF_visitTree(ASF_Tree arg, ATerm (*acceptTree)(ATerm))
{
  if (ASF_isTreeCast(arg)) {
    return ASF_makeTreeCast(
        acceptTree ? acceptTree(ASF_getTreeTree(arg)) : ASF_getTreeTree(arg));
  }
  ATabort("not a Tree: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_visitASFCondition(ASF_ASFCondition arg, ATerm (*acceptTypeOfLhs)(ATerm), ATerm (*acceptTypeOfRhs)(ATerm), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterUnequal)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterEquality)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterMatch)(ASF_OptLayout)) */

ASF_ASFCondition ASF_visitASFCondition(ASF_ASFCondition arg, ATerm (*acceptTypeOfLhs)(ATerm), ATerm (*acceptTypeOfRhs)(ATerm), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterUnequal)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterEquality)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterMatch)(ASF_OptLayout))
{
  if (ASF_isASFConditionNegative(arg)) {
    return ASF_makeASFConditionNegative(
        acceptTypeOfLhs ? acceptTypeOfLhs(ASF_getASFConditionTypeOfLhs(arg)) : ASF_getASFConditionTypeOfLhs(arg),
        acceptTypeOfRhs ? acceptTypeOfRhs(ASF_getASFConditionTypeOfRhs(arg)) : ASF_getASFConditionTypeOfRhs(arg),
        acceptLhs ? acceptLhs(ASF_getASFConditionLhs(arg)) : ASF_getASFConditionLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getASFConditionWsAfterLhs(arg)) : ASF_getASFConditionWsAfterLhs(arg),
        acceptWsAfterUnequal ? acceptWsAfterUnequal(ASF_getASFConditionWsAfterUnequal(arg)) : ASF_getASFConditionWsAfterUnequal(arg),
        acceptRhs ? acceptRhs(ASF_getASFConditionRhs(arg)) : ASF_getASFConditionRhs(arg));
  }
  if (ASF_isASFConditionEquality(arg)) {
    return ASF_makeASFConditionEquality(
        acceptTypeOfLhs ? acceptTypeOfLhs(ASF_getASFConditionTypeOfLhs(arg)) : ASF_getASFConditionTypeOfLhs(arg),
        acceptTypeOfRhs ? acceptTypeOfRhs(ASF_getASFConditionTypeOfRhs(arg)) : ASF_getASFConditionTypeOfRhs(arg),
        acceptLhs ? acceptLhs(ASF_getASFConditionLhs(arg)) : ASF_getASFConditionLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getASFConditionWsAfterLhs(arg)) : ASF_getASFConditionWsAfterLhs(arg),
        acceptWsAfterEquality ? acceptWsAfterEquality(ASF_getASFConditionWsAfterEquality(arg)) : ASF_getASFConditionWsAfterEquality(arg),
        acceptRhs ? acceptRhs(ASF_getASFConditionRhs(arg)) : ASF_getASFConditionRhs(arg));
  }
  if (ASF_isASFConditionMatch(arg)) {
    return ASF_makeASFConditionMatch(
        acceptTypeOfLhs ? acceptTypeOfLhs(ASF_getASFConditionTypeOfLhs(arg)) : ASF_getASFConditionTypeOfLhs(arg),
        acceptTypeOfRhs ? acceptTypeOfRhs(ASF_getASFConditionTypeOfRhs(arg)) : ASF_getASFConditionTypeOfRhs(arg),
        acceptLhs ? acceptLhs(ASF_getASFConditionLhs(arg)) : ASF_getASFConditionLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getASFConditionWsAfterLhs(arg)) : ASF_getASFConditionWsAfterLhs(arg),
        acceptWsAfterMatch ? acceptWsAfterMatch(ASF_getASFConditionWsAfterMatch(arg)) : ASF_getASFConditionWsAfterMatch(arg),
        acceptRhs ? acceptRhs(ASF_getASFConditionRhs(arg)) : ASF_getASFConditionRhs(arg));
  }
  if (ASF_isASFConditionNoMatch(arg)) {
    return ASF_makeASFConditionNoMatch(
        acceptTypeOfLhs ? acceptTypeOfLhs(ASF_getASFConditionTypeOfLhs(arg)) : ASF_getASFConditionTypeOfLhs(arg),
        acceptTypeOfRhs ? acceptTypeOfRhs(ASF_getASFConditionTypeOfRhs(arg)) : ASF_getASFConditionTypeOfRhs(arg),
        acceptLhs ? acceptLhs(ASF_getASFConditionLhs(arg)) : ASF_getASFConditionLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getASFConditionWsAfterLhs(arg)) : ASF_getASFConditionWsAfterLhs(arg),
        acceptWsAfterMatch ? acceptWsAfterMatch(ASF_getASFConditionWsAfterMatch(arg)) : ASF_getASFConditionWsAfterMatch(arg),
        acceptRhs ? acceptRhs(ASF_getASFConditionRhs(arg)) : ASF_getASFConditionRhs(arg));
  }
  ATabort("not a ASFCondition: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditions ASF_visitASFConditions(ASF_ASFConditions arg, ASF_ASFConditionList (*acceptList)(ASF_ASFConditionList)) */

ASF_ASFConditions ASF_visitASFConditions(ASF_ASFConditions arg, ASF_ASFConditionList (*acceptList)(ASF_ASFConditionList))
{
  if (ASF_isASFConditionsDefault(arg)) {
    return ASF_makeASFConditionsDefault(
        acceptList ? acceptList(ASF_getASFConditionsList(arg)) : ASF_getASFConditionsList(arg));
  }
  ATabort("not a ASFConditions: %t\n", arg);
  return (ASF_ASFConditions)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_visitASFConditionList(ASF_ASFConditionList arg, ASF_ASFCondition (*acceptHead)(ASF_ASFCondition), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterSep)(ASF_OptLayout)) */

ASF_ASFConditionList ASF_visitASFConditionList(ASF_ASFConditionList arg, ASF_ASFCondition (*acceptHead)(ASF_ASFCondition), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterSep)(ASF_OptLayout))
{
  if (ASF_isASFConditionListEmpty(arg)) {
    return ASF_makeASFConditionListEmpty();
  }
  if (ASF_isASFConditionListSingle(arg)) {
    return ASF_makeASFConditionListSingle(
        acceptHead ? acceptHead(ASF_getASFConditionListHead(arg)) : ASF_getASFConditionListHead(arg));
  }
  if (ASF_isASFConditionListMany(arg)) {
    return ASF_makeASFConditionListMany(
        acceptHead ? acceptHead(ASF_getASFConditionListHead(arg)) : ASF_getASFConditionListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(ASF_getASFConditionListWsAfterHead(arg)) : ASF_getASFConditionListWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(ASF_getASFConditionListWsAfterSep(arg)) : ASF_getASFConditionListWsAfterSep(arg),
        ASF_visitASFConditionList(ASF_getASFConditionListTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a ASFConditionList: %t\n", arg);
  return (ASF_ASFConditionList)NULL;
}

/*}}}  */
/*{{{  ASF_LexASFBarEnd ASF_visitLexASFBarEnd(ASF_LexASFBarEnd arg) */

ASF_LexASFBarEnd ASF_visitLexASFBarEnd(ASF_LexASFBarEnd arg)
{
  if (ASF_isLexASFBarEndAbsent(arg)) {
    return ASF_makeLexASFBarEndAbsent();
  }
  if (ASF_isLexASFBarEndPresent(arg)) {
    return ASF_makeLexASFBarEndPresent();
  }
  ATabort("not a LexASFBarEnd: %t\n", arg);
  return (ASF_LexASFBarEnd)NULL;
}

/*}}}  */
/*{{{  ASF_ASFBarEnd ASF_visitASFBarEnd(ASF_ASFBarEnd arg, ASF_LexASFBarEnd (*acceptASFBarEnd)(ASF_LexASFBarEnd)) */

ASF_ASFBarEnd ASF_visitASFBarEnd(ASF_ASFBarEnd arg, ASF_LexASFBarEnd (*acceptASFBarEnd)(ASF_LexASFBarEnd))
{
  if (ASF_isASFBarEndLexToCf(arg)) {
    return ASF_makeASFBarEndLexToCf(
        acceptASFBarEnd ? acceptASFBarEnd(ASF_getASFBarEndASFBarEnd(arg)) : ASF_getASFBarEndASFBarEnd(arg));
  }
  ATabort("not a ASFBarEnd: %t\n", arg);
  return (ASF_ASFBarEnd)NULL;
}

/*}}}  */
/*{{{  ASF_LexASFImplies ASF_visitLexASFImplies(ASF_LexASFImplies arg, char* (*acceptBar)(char*), ASF_LexASFBarEnd (*acceptEnd)(ASF_LexASFBarEnd)) */

ASF_LexASFImplies ASF_visitLexASFImplies(ASF_LexASFImplies arg, char* (*acceptBar)(char*), ASF_LexASFBarEnd (*acceptEnd)(ASF_LexASFBarEnd))
{
  if (ASF_isLexASFImpliesDefault(arg)) {
    return ASF_makeLexASFImpliesDefault(
        acceptBar ? acceptBar(ASF_getLexASFImpliesBar(arg)) : ASF_getLexASFImpliesBar(arg),
        acceptEnd ? acceptEnd(ASF_getLexASFImpliesEnd(arg)) : ASF_getLexASFImpliesEnd(arg));
  }
  ATabort("not a LexASFImplies: %t\n", arg);
  return (ASF_LexASFImplies)NULL;
}

/*}}}  */
/*{{{  ASF_ASFImplies ASF_visitASFImplies(ASF_ASFImplies arg, ASF_LexASFImplies (*acceptASFImplies)(ASF_LexASFImplies)) */

ASF_ASFImplies ASF_visitASFImplies(ASF_ASFImplies arg, ASF_LexASFImplies (*acceptASFImplies)(ASF_LexASFImplies))
{
  if (ASF_isASFImpliesLexToCf(arg)) {
    return ASF_makeASFImpliesLexToCf(
        acceptASFImplies ? acceptASFImplies(ASF_getASFImpliesASFImplies(arg)) : ASF_getASFImpliesASFImplies(arg));
  }
  ATabort("not a ASFImplies: %t\n", arg);
  return (ASF_ASFImplies)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_visitASFConditionalEquation(ASF_ASFConditionalEquation arg, ASF_ASFTag (*acceptASFTag)(ASF_ASFTag), ASF_OptLayout (*acceptWsAfterASFTag)(ASF_OptLayout), ASF_ASFEquation (*acceptASFEquation)(ASF_ASFEquation), ASF_ASFConditions (*acceptASFConditions)(ASF_ASFConditions), ASF_OptLayout (*acceptWsAfterASFConditions)(ASF_OptLayout), ASF_ASFImplies (*acceptASFImplies)(ASF_ASFImplies), ASF_OptLayout (*acceptWsAfterASFImplies)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterASFEquation)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterWhen)(ASF_OptLayout)) */

ASF_ASFConditionalEquation ASF_visitASFConditionalEquation(ASF_ASFConditionalEquation arg, ASF_ASFTag (*acceptASFTag)(ASF_ASFTag), ASF_OptLayout (*acceptWsAfterASFTag)(ASF_OptLayout), ASF_ASFEquation (*acceptASFEquation)(ASF_ASFEquation), ASF_ASFConditions (*acceptASFConditions)(ASF_ASFConditions), ASF_OptLayout (*acceptWsAfterASFConditions)(ASF_OptLayout), ASF_ASFImplies (*acceptASFImplies)(ASF_ASFImplies), ASF_OptLayout (*acceptWsAfterASFImplies)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterASFEquation)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterWhen)(ASF_OptLayout))
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return ASF_makeASFConditionalEquationSimple(
        acceptASFTag ? acceptASFTag(ASF_getASFConditionalEquationASFTag(arg)) : ASF_getASFConditionalEquationASFTag(arg),
        acceptWsAfterASFTag ? acceptWsAfterASFTag(ASF_getASFConditionalEquationWsAfterASFTag(arg)) : ASF_getASFConditionalEquationWsAfterASFTag(arg),
        acceptASFEquation ? acceptASFEquation(ASF_getASFConditionalEquationASFEquation(arg)) : ASF_getASFConditionalEquationASFEquation(arg));
  }
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return ASF_makeASFConditionalEquationImplies(
        acceptASFTag ? acceptASFTag(ASF_getASFConditionalEquationASFTag(arg)) : ASF_getASFConditionalEquationASFTag(arg),
        acceptWsAfterASFTag ? acceptWsAfterASFTag(ASF_getASFConditionalEquationWsAfterASFTag(arg)) : ASF_getASFConditionalEquationWsAfterASFTag(arg),
        acceptASFConditions ? acceptASFConditions(ASF_getASFConditionalEquationASFConditions(arg)) : ASF_getASFConditionalEquationASFConditions(arg),
        acceptWsAfterASFConditions ? acceptWsAfterASFConditions(ASF_getASFConditionalEquationWsAfterASFConditions(arg)) : ASF_getASFConditionalEquationWsAfterASFConditions(arg),
        acceptASFImplies ? acceptASFImplies(ASF_getASFConditionalEquationASFImplies(arg)) : ASF_getASFConditionalEquationASFImplies(arg),
        acceptWsAfterASFImplies ? acceptWsAfterASFImplies(ASF_getASFConditionalEquationWsAfterASFImplies(arg)) : ASF_getASFConditionalEquationWsAfterASFImplies(arg),
        acceptASFEquation ? acceptASFEquation(ASF_getASFConditionalEquationASFEquation(arg)) : ASF_getASFConditionalEquationASFEquation(arg));
  }
  if (ASF_isASFConditionalEquationWhen(arg)) {
    return ASF_makeASFConditionalEquationWhen(
        acceptASFTag ? acceptASFTag(ASF_getASFConditionalEquationASFTag(arg)) : ASF_getASFConditionalEquationASFTag(arg),
        acceptWsAfterASFTag ? acceptWsAfterASFTag(ASF_getASFConditionalEquationWsAfterASFTag(arg)) : ASF_getASFConditionalEquationWsAfterASFTag(arg),
        acceptASFEquation ? acceptASFEquation(ASF_getASFConditionalEquationASFEquation(arg)) : ASF_getASFConditionalEquationASFEquation(arg),
        acceptWsAfterASFEquation ? acceptWsAfterASFEquation(ASF_getASFConditionalEquationWsAfterASFEquation(arg)) : ASF_getASFConditionalEquationWsAfterASFEquation(arg),
        acceptWsAfterWhen ? acceptWsAfterWhen(ASF_getASFConditionalEquationWsAfterWhen(arg)) : ASF_getASFConditionalEquationWsAfterWhen(arg),
        acceptASFConditions ? acceptASFConditions(ASF_getASFConditionalEquationASFConditions(arg)) : ASF_getASFConditionalEquationASFConditions(arg));
  }
  ATabort("not a ASFConditionalEquation: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_visitASFEquation(ASF_ASFEquation arg, ATerm (*acceptTypeOfLhs)(ATerm), ATerm (*acceptTypeOfRhs)(ATerm), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquals)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree)) */

ASF_ASFEquation ASF_visitASFEquation(ASF_ASFEquation arg, ATerm (*acceptTypeOfLhs)(ATerm), ATerm (*acceptTypeOfRhs)(ATerm), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquals)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree))
{
  if (ASF_isASFEquationDefault(arg)) {
    return ASF_makeASFEquationDefault(
        acceptTypeOfLhs ? acceptTypeOfLhs(ASF_getASFEquationTypeOfLhs(arg)) : ASF_getASFEquationTypeOfLhs(arg),
        acceptTypeOfRhs ? acceptTypeOfRhs(ASF_getASFEquationTypeOfRhs(arg)) : ASF_getASFEquationTypeOfRhs(arg),
        acceptLhs ? acceptLhs(ASF_getASFEquationLhs(arg)) : ASF_getASFEquationLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getASFEquationWsAfterLhs(arg)) : ASF_getASFEquationWsAfterLhs(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(ASF_getASFEquationWsAfterEquals(arg)) : ASF_getASFEquationWsAfterEquals(arg),
        acceptRhs ? acceptRhs(ASF_getASFEquationRhs(arg)) : ASF_getASFEquationRhs(arg));
  }
  ATabort("not a ASFEquation: %t\n", arg);
  return (ASF_ASFEquation)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_visitStart(ASF_Start arg, ASF_OptLayout (*acceptWsBefore)(ASF_OptLayout), ASF_ASFModule (*acceptTopASFModule)(ASF_ASFModule), ASF_OptLayout (*acceptWsAfter)(ASF_OptLayout), int (*acceptAmbCnt)(int), ASF_ASFSection (*acceptTopASFSection)(ASF_ASFSection)) */

ASF_Start ASF_visitStart(ASF_Start arg, ASF_OptLayout (*acceptWsBefore)(ASF_OptLayout), ASF_ASFModule (*acceptTopASFModule)(ASF_ASFModule), ASF_OptLayout (*acceptWsAfter)(ASF_OptLayout), int (*acceptAmbCnt)(int), ASF_ASFSection (*acceptTopASFSection)(ASF_ASFSection))
{
  if (ASF_isStartASFModule(arg)) {
    return ASF_makeStartASFModule(
        acceptWsBefore ? acceptWsBefore(ASF_getStartWsBefore(arg)) : ASF_getStartWsBefore(arg),
        acceptTopASFModule ? acceptTopASFModule(ASF_getStartTopASFModule(arg)) : ASF_getStartTopASFModule(arg),
        acceptWsAfter ? acceptWsAfter(ASF_getStartWsAfter(arg)) : ASF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(ASF_getStartAmbCnt(arg)) : ASF_getStartAmbCnt(arg));
  }
  if (ASF_isStartASFSection(arg)) {
    return ASF_makeStartASFSection(
        acceptWsBefore ? acceptWsBefore(ASF_getStartWsBefore(arg)) : ASF_getStartWsBefore(arg),
        acceptTopASFSection ? acceptTopASFSection(ASF_getStartTopASFSection(arg)) : ASF_getStartTopASFSection(arg),
        acceptWsAfter ? acceptWsAfter(ASF_getStartWsAfter(arg)) : ASF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(ASF_getStartAmbCnt(arg)) : ASF_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_ASFModule ASF_visitASFModule(ASF_ASFModule arg, ASF_ASFSectionList (*acceptList)(ASF_ASFSectionList)) */

ASF_ASFModule ASF_visitASFModule(ASF_ASFModule arg, ASF_ASFSectionList (*acceptList)(ASF_ASFSectionList))
{
  if (ASF_isASFModuleDefault(arg)) {
    return ASF_makeASFModuleDefault(
        acceptList ? acceptList(ASF_getASFModuleList(arg)) : ASF_getASFModuleList(arg));
  }
  ATabort("not a ASFModule: %t\n", arg);
  return (ASF_ASFModule)NULL;
}

/*}}}  */
/*{{{  ASF_ASFSection ASF_visitASFSection(ASF_ASFSection arg, ASF_OptLayout (*acceptWsAfterEquations)(ASF_OptLayout), ASF_ASFConditionalEquationList (*acceptList)(ASF_ASFConditionalEquationList), ASF_OptLayout (*acceptWsAfterTests)(ASF_OptLayout), ASF_ASFTestEquationTestList (*acceptTestList)(ASF_ASFTestEquationTestList)) */

ASF_ASFSection ASF_visitASFSection(ASF_ASFSection arg, ASF_OptLayout (*acceptWsAfterEquations)(ASF_OptLayout), ASF_ASFConditionalEquationList (*acceptList)(ASF_ASFConditionalEquationList), ASF_OptLayout (*acceptWsAfterTests)(ASF_OptLayout), ASF_ASFTestEquationTestList (*acceptTestList)(ASF_ASFTestEquationTestList))
{
  if (ASF_isASFSectionEquations(arg)) {
    return ASF_makeASFSectionEquations(
        acceptWsAfterEquations ? acceptWsAfterEquations(ASF_getASFSectionWsAfterEquations(arg)) : ASF_getASFSectionWsAfterEquations(arg),
        acceptList ? acceptList(ASF_getASFSectionList(arg)) : ASF_getASFSectionList(arg));
  }
  if (ASF_isASFSectionTests(arg)) {
    return ASF_makeASFSectionTests(
        acceptWsAfterTests ? acceptWsAfterTests(ASF_getASFSectionWsAfterTests(arg)) : ASF_getASFSectionWsAfterTests(arg),
        acceptTestList ? acceptTestList(ASF_getASFSectionTestList(arg)) : ASF_getASFSectionTestList(arg));
  }
  ATabort("not a ASFSection: %t\n", arg);
  return (ASF_ASFSection)NULL;
}

/*}}}  */
/*{{{  ASF_ASFSectionList ASF_visitASFSectionList(ASF_ASFSectionList arg, ASF_ASFSection (*acceptHead)(ASF_ASFSection), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout)) */

ASF_ASFSectionList ASF_visitASFSectionList(ASF_ASFSectionList arg, ASF_ASFSection (*acceptHead)(ASF_ASFSection), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout))
{
  if (ASF_isASFSectionListEmpty(arg)) {
    return ASF_makeASFSectionListEmpty();
  }
  if (ASF_isASFSectionListSingle(arg)) {
    return ASF_makeASFSectionListSingle(
        acceptHead ? acceptHead(ASF_getASFSectionListHead(arg)) : ASF_getASFSectionListHead(arg));
  }
  if (ASF_isASFSectionListMany(arg)) {
    return ASF_makeASFSectionListMany(
        acceptHead ? acceptHead(ASF_getASFSectionListHead(arg)) : ASF_getASFSectionListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(ASF_getASFSectionListWsAfterHead(arg)) : ASF_getASFSectionListWsAfterHead(arg),
        ASF_visitASFSectionList(ASF_getASFSectionListTail(arg), acceptHead, acceptWsAfterHead));
  }
  ATabort("not a ASFSectionList: %t\n", arg);
  return (ASF_ASFSectionList)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_visitASFConditionalEquationList(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation (*acceptHead)(ASF_ASFConditionalEquation), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout)) */

ASF_ASFConditionalEquationList ASF_visitASFConditionalEquationList(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation (*acceptHead)(ASF_ASFConditionalEquation), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout))
{
  if (ASF_isASFConditionalEquationListEmpty(arg)) {
    return ASF_makeASFConditionalEquationListEmpty();
  }
  if (ASF_isASFConditionalEquationListSingle(arg)) {
    return ASF_makeASFConditionalEquationListSingle(
        acceptHead ? acceptHead(ASF_getASFConditionalEquationListHead(arg)) : ASF_getASFConditionalEquationListHead(arg));
  }
  if (ASF_isASFConditionalEquationListMany(arg)) {
    return ASF_makeASFConditionalEquationListMany(
        acceptHead ? acceptHead(ASF_getASFConditionalEquationListHead(arg)) : ASF_getASFConditionalEquationListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(ASF_getASFConditionalEquationListWsAfterHead(arg)) : ASF_getASFConditionalEquationListWsAfterHead(arg),
        ASF_visitASFConditionalEquationList(ASF_getASFConditionalEquationListTail(arg), acceptHead, acceptWsAfterHead));
  }
  ATabort("not a ASFConditionalEquationList: %t\n", arg);
  return (ASF_ASFConditionalEquationList)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTestEquationTestList ASF_visitASFTestEquationTestList(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquation (*acceptHead)(ASF_ASFTestEquation), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout)) */

ASF_ASFTestEquationTestList ASF_visitASFTestEquationTestList(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquation (*acceptHead)(ASF_ASFTestEquation), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout))
{
  if (ASF_isASFTestEquationTestListEmpty(arg)) {
    return ASF_makeASFTestEquationTestListEmpty();
  }
  if (ASF_isASFTestEquationTestListSingle(arg)) {
    return ASF_makeASFTestEquationTestListSingle(
        acceptHead ? acceptHead(ASF_getASFTestEquationTestListHead(arg)) : ASF_getASFTestEquationTestListHead(arg));
  }
  if (ASF_isASFTestEquationTestListMany(arg)) {
    return ASF_makeASFTestEquationTestListMany(
        acceptHead ? acceptHead(ASF_getASFTestEquationTestListHead(arg)) : ASF_getASFTestEquationTestListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(ASF_getASFTestEquationTestListWsAfterHead(arg)) : ASF_getASFTestEquationTestListWsAfterHead(arg),
        ASF_visitASFTestEquationTestList(ASF_getASFTestEquationTestListTail(arg), acceptHead, acceptWsAfterHead));
  }
  ATabort("not a ASFTestEquationTestList: %t\n", arg);
  return (ASF_ASFTestEquationTestList)NULL;
}

/*}}}  */
/*{{{  ASF_LexASFTagId ASF_visitLexASFTagId(ASF_LexASFTagId arg, char (*acceptHead)(char), char* (*acceptMiddle)(char*), char (*acceptLast)(char)) */

ASF_LexASFTagId ASF_visitLexASFTagId(ASF_LexASFTagId arg, char (*acceptHead)(char), char* (*acceptMiddle)(char*), char (*acceptLast)(char))
{
  if (ASF_isLexASFTagIdOneChar(arg)) {
    return ASF_makeLexASFTagIdOneChar(
        acceptHead ? acceptHead(ASF_getLexASFTagIdHead(arg)) : ASF_getLexASFTagIdHead(arg));
  }
  if (ASF_isLexASFTagIdManyChars(arg)) {
    return ASF_makeLexASFTagIdManyChars(
        acceptHead ? acceptHead(ASF_getLexASFTagIdHead(arg)) : ASF_getLexASFTagIdHead(arg),
        acceptMiddle ? acceptMiddle(ASF_getLexASFTagIdMiddle(arg)) : ASF_getLexASFTagIdMiddle(arg),
        acceptLast ? acceptLast(ASF_getLexASFTagIdLast(arg)) : ASF_getLexASFTagIdLast(arg));
  }
  ATabort("not a LexASFTagId: %t\n", arg);
  return (ASF_LexASFTagId)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTagId ASF_visitASFTagId(ASF_ASFTagId arg, ASF_LexASFTagId (*acceptASFTagId)(ASF_LexASFTagId)) */

ASF_ASFTagId ASF_visitASFTagId(ASF_ASFTagId arg, ASF_LexASFTagId (*acceptASFTagId)(ASF_LexASFTagId))
{
  if (ASF_isASFTagIdLexToCf(arg)) {
    return ASF_makeASFTagIdLexToCf(
        acceptASFTagId ? acceptASFTagId(ASF_getASFTagIdASFTagId(arg)) : ASF_getASFTagIdASFTagId(arg));
  }
  ATabort("not a ASFTagId: %t\n", arg);
  return (ASF_ASFTagId)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_visitASFTag(ASF_ASFTag arg, ASF_OptLayout (*acceptWsAfterBracketOpen)(ASF_OptLayout), ASF_ASFTagId (*acceptASFTagId)(ASF_ASFTagId), ASF_OptLayout (*acceptWsAfterASFTagId)(ASF_OptLayout)) */

ASF_ASFTag ASF_visitASFTag(ASF_ASFTag arg, ASF_OptLayout (*acceptWsAfterBracketOpen)(ASF_OptLayout), ASF_ASFTagId (*acceptASFTagId)(ASF_ASFTagId), ASF_OptLayout (*acceptWsAfterASFTagId)(ASF_OptLayout))
{
  if (ASF_isASFTagEmpty(arg)) {
    return ASF_makeASFTagEmpty(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(ASF_getASFTagWsAfterBracketOpen(arg)) : ASF_getASFTagWsAfterBracketOpen(arg));
  }
  if (ASF_isASFTagNotEmpty(arg)) {
    return ASF_makeASFTagNotEmpty(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(ASF_getASFTagWsAfterBracketOpen(arg)) : ASF_getASFTagWsAfterBracketOpen(arg),
        acceptASFTagId ? acceptASFTagId(ASF_getASFTagASFTagId(arg)) : ASF_getASFTagASFTagId(arg),
        acceptWsAfterASFTagId ? acceptWsAfterASFTagId(ASF_getASFTagWsAfterASFTagId(arg)) : ASF_getASFTagWsAfterASFTagId(arg));
  }
  ATabort("not a ASFTag: %t\n", arg);
  return (ASF_ASFTag)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_visitASFTestEquation(ASF_ASFTestEquation arg, ASF_ASFTag (*acceptASFTag)(ASF_ASFTag), ASF_OptLayout (*acceptWsAfterASFTag)(ASF_OptLayout), ASF_ASFCondition (*acceptASFCondition)(ASF_ASFCondition), ASF_ASFConditions (*acceptASFConditions)(ASF_ASFConditions), ASF_OptLayout (*acceptWsAfterASFConditions)(ASF_OptLayout), ASF_ASFImplies (*acceptASFImplies)(ASF_ASFImplies), ASF_OptLayout (*acceptWsAfterASFImplies)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterASFCondition)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterWhen)(ASF_OptLayout)) */

ASF_ASFTestEquation ASF_visitASFTestEquation(ASF_ASFTestEquation arg, ASF_ASFTag (*acceptASFTag)(ASF_ASFTag), ASF_OptLayout (*acceptWsAfterASFTag)(ASF_OptLayout), ASF_ASFCondition (*acceptASFCondition)(ASF_ASFCondition), ASF_ASFConditions (*acceptASFConditions)(ASF_ASFConditions), ASF_OptLayout (*acceptWsAfterASFConditions)(ASF_OptLayout), ASF_ASFImplies (*acceptASFImplies)(ASF_ASFImplies), ASF_OptLayout (*acceptWsAfterASFImplies)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterASFCondition)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterWhen)(ASF_OptLayout))
{
  if (ASF_isASFTestEquationSimple(arg)) {
    return ASF_makeASFTestEquationSimple(
        acceptASFTag ? acceptASFTag(ASF_getASFTestEquationASFTag(arg)) : ASF_getASFTestEquationASFTag(arg),
        acceptWsAfterASFTag ? acceptWsAfterASFTag(ASF_getASFTestEquationWsAfterASFTag(arg)) : ASF_getASFTestEquationWsAfterASFTag(arg),
        acceptASFCondition ? acceptASFCondition(ASF_getASFTestEquationASFCondition(arg)) : ASF_getASFTestEquationASFCondition(arg));
  }
  if (ASF_isASFTestEquationImplies(arg)) {
    return ASF_makeASFTestEquationImplies(
        acceptASFTag ? acceptASFTag(ASF_getASFTestEquationASFTag(arg)) : ASF_getASFTestEquationASFTag(arg),
        acceptWsAfterASFTag ? acceptWsAfterASFTag(ASF_getASFTestEquationWsAfterASFTag(arg)) : ASF_getASFTestEquationWsAfterASFTag(arg),
        acceptASFConditions ? acceptASFConditions(ASF_getASFTestEquationASFConditions(arg)) : ASF_getASFTestEquationASFConditions(arg),
        acceptWsAfterASFConditions ? acceptWsAfterASFConditions(ASF_getASFTestEquationWsAfterASFConditions(arg)) : ASF_getASFTestEquationWsAfterASFConditions(arg),
        acceptASFImplies ? acceptASFImplies(ASF_getASFTestEquationASFImplies(arg)) : ASF_getASFTestEquationASFImplies(arg),
        acceptWsAfterASFImplies ? acceptWsAfterASFImplies(ASF_getASFTestEquationWsAfterASFImplies(arg)) : ASF_getASFTestEquationWsAfterASFImplies(arg),
        acceptASFCondition ? acceptASFCondition(ASF_getASFTestEquationASFCondition(arg)) : ASF_getASFTestEquationASFCondition(arg));
  }
  if (ASF_isASFTestEquationWhen(arg)) {
    return ASF_makeASFTestEquationWhen(
        acceptASFTag ? acceptASFTag(ASF_getASFTestEquationASFTag(arg)) : ASF_getASFTestEquationASFTag(arg),
        acceptWsAfterASFTag ? acceptWsAfterASFTag(ASF_getASFTestEquationWsAfterASFTag(arg)) : ASF_getASFTestEquationWsAfterASFTag(arg),
        acceptASFCondition ? acceptASFCondition(ASF_getASFTestEquationASFCondition(arg)) : ASF_getASFTestEquationASFCondition(arg),
        acceptWsAfterASFCondition ? acceptWsAfterASFCondition(ASF_getASFTestEquationWsAfterASFCondition(arg)) : ASF_getASFTestEquationWsAfterASFCondition(arg),
        acceptWsAfterWhen ? acceptWsAfterWhen(ASF_getASFTestEquationWsAfterWhen(arg)) : ASF_getASFTestEquationWsAfterWhen(arg),
        acceptASFConditions ? acceptASFConditions(ASF_getASFTestEquationASFConditions(arg)) : ASF_getASFTestEquationASFConditions(arg));
  }
  ATabort("not a ASFTestEquation: %t\n", arg);
  return (ASF_ASFTestEquation)NULL;
}

/*}}}  */
/*{{{  ASF_LexLayout ASF_visitLexLayout(ASF_LexLayout arg, char (*acceptCh)(char)) */

ASF_LexLayout ASF_visitLexLayout(ASF_LexLayout arg, char (*acceptCh)(char))
{
  if (ASF_isLexLayoutWhitespace(arg)) {
    return ASF_makeLexLayoutWhitespace(
        acceptCh ? acceptCh(ASF_getLexLayoutCh(arg)) : ASF_getLexLayoutCh(arg));
  }
  ATabort("not a LexLayout: %t\n", arg);
  return (ASF_LexLayout)NULL;
}

/*}}}  */
/*{{{  ASF_LexNumChar ASF_visitLexNumChar(ASF_LexNumChar arg, char* (*acceptNumber)(char*)) */

ASF_LexNumChar ASF_visitLexNumChar(ASF_LexNumChar arg, char* (*acceptNumber)(char*))
{
  if (ASF_isLexNumCharDigits(arg)) {
    return ASF_makeLexNumCharDigits(
        acceptNumber ? acceptNumber(ASF_getLexNumCharNumber(arg)) : ASF_getLexNumCharNumber(arg));
  }
  ATabort("not a LexNumChar: %t\n", arg);
  return (ASF_LexNumChar)NULL;
}

/*}}}  */
/*{{{  ASF_NumChar ASF_visitNumChar(ASF_NumChar arg, ASF_LexNumChar (*acceptNumChar)(ASF_LexNumChar)) */

ASF_NumChar ASF_visitNumChar(ASF_NumChar arg, ASF_LexNumChar (*acceptNumChar)(ASF_LexNumChar))
{
  if (ASF_isNumCharLexToCf(arg)) {
    return ASF_makeNumCharLexToCf(
        acceptNumChar ? acceptNumChar(ASF_getNumCharNumChar(arg)) : ASF_getNumCharNumChar(arg));
  }
  ATabort("not a NumChar: %t\n", arg);
  return (ASF_NumChar)NULL;
}

/*}}}  */
/*{{{  ASF_LexShortChar ASF_visitLexShortChar(ASF_LexShortChar arg, char (*acceptCharacter)(char), char (*acceptEscape)(char)) */

ASF_LexShortChar ASF_visitLexShortChar(ASF_LexShortChar arg, char (*acceptCharacter)(char), char (*acceptEscape)(char))
{
  if (ASF_isLexShortCharRegular(arg)) {
    return ASF_makeLexShortCharRegular(
        acceptCharacter ? acceptCharacter(ASF_getLexShortCharCharacter(arg)) : ASF_getLexShortCharCharacter(arg));
  }
  if (ASF_isLexShortCharEscaped(arg)) {
    return ASF_makeLexShortCharEscaped(
        acceptEscape ? acceptEscape(ASF_getLexShortCharEscape(arg)) : ASF_getLexShortCharEscape(arg));
  }
  ATabort("not a LexShortChar: %t\n", arg);
  return (ASF_LexShortChar)NULL;
}

/*}}}  */
/*{{{  ASF_ShortChar ASF_visitShortChar(ASF_ShortChar arg, ASF_LexShortChar (*acceptShortChar)(ASF_LexShortChar)) */

ASF_ShortChar ASF_visitShortChar(ASF_ShortChar arg, ASF_LexShortChar (*acceptShortChar)(ASF_LexShortChar))
{
  if (ASF_isShortCharLexToCf(arg)) {
    return ASF_makeShortCharLexToCf(
        acceptShortChar ? acceptShortChar(ASF_getShortCharShortChar(arg)) : ASF_getShortCharShortChar(arg));
  }
  ATabort("not a ShortChar: %t\n", arg);
  return (ASF_ShortChar)NULL;
}

/*}}}  */
/*{{{  ASF_Character ASF_visitCharacter(ASF_Character arg, ASF_NumChar (*acceptNumChar)(ASF_NumChar), ASF_ShortChar (*acceptShortChar)(ASF_ShortChar)) */

ASF_Character ASF_visitCharacter(ASF_Character arg, ASF_NumChar (*acceptNumChar)(ASF_NumChar), ASF_ShortChar (*acceptShortChar)(ASF_ShortChar))
{
  if (ASF_isCharacterNumeric(arg)) {
    return ASF_makeCharacterNumeric(
        acceptNumChar ? acceptNumChar(ASF_getCharacterNumChar(arg)) : ASF_getCharacterNumChar(arg));
  }
  if (ASF_isCharacterShort(arg)) {
    return ASF_makeCharacterShort(
        acceptShortChar ? acceptShortChar(ASF_getCharacterShortChar(arg)) : ASF_getCharacterShortChar(arg));
  }
  if (ASF_isCharacterTop(arg)) {
    return ASF_makeCharacterTop();
  }
  if (ASF_isCharacterEof(arg)) {
    return ASF_makeCharacterEof();
  }
  if (ASF_isCharacterBot(arg)) {
    return ASF_makeCharacterBot();
  }
  if (ASF_isCharacterLabelUnderscoreStart(arg)) {
    return ASF_makeCharacterLabelUnderscoreStart();
  }
  ATabort("not a Character: %t\n", arg);
  return (ASF_Character)NULL;
}

/*}}}  */

/*}}}  */
