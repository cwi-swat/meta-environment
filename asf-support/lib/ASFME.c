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


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _ASF_Production;
typedef struct ATerm _ASF_CHAR;
typedef struct ATerm _ASF_ASFCondition;
typedef struct ATerm _ASF_ASFConditions;
typedef struct ATerm _ASF_ASFConditionList;
typedef struct ATerm _ASF_Tree;
typedef struct ATerm _ASF_TreeAmbs;
typedef struct ATerm _ASF_CHARList;
typedef struct ATerm _ASF_ASFImplies;
typedef struct ATerm _ASF_ASFConditionalEquation;
typedef struct ATerm _ASF_ASFEquation;
typedef struct ATerm _ASF_ASFModule;
typedef struct ATerm _ASF_ASFSectionList;
typedef struct ATerm _ASF_ASFSection;
typedef struct ATerm _ASF_ASFConditionalEquationList;
typedef struct ATerm _ASF_ASFTestEquationTestList;
typedef struct ATerm _ASF_ASFTagId;
typedef struct ATerm _ASF_ASFTag;
typedef struct ATerm _ASF_ASFTestEquation;
typedef struct ATerm _ASF_Start;
typedef struct ATerm _ASF_OptLayout;

/*}}}  */

/*{{{  void ASF_initASFMEApi(void) */

void ASF_initASFMEApi(void)
{
  init_ASFME_dict();
}

/*}}}  */

/*{{{  protect functions */

void ASF_protectProduction(ASF_Production *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectCHAR(ASF_CHAR *arg)
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

void ASF_protectTree(ASF_Tree *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectTreeAmbs(ASF_TreeAmbs *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectCHARList(ASF_CHARList *arg)
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

void ASF_protectASFModule(ASF_ASFModule *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFSectionList(ASF_ASFSectionList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectASFSection(ASF_ASFSection *arg)
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

void ASF_protectStart(ASF_Start *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void ASF_protectOptLayout(ASF_OptLayout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  ASF_Production ASF_ProductionFromTerm(ATerm t) */

ASF_Production ASF_ProductionFromTerm(ATerm t)
{
  return (ASF_Production)t;
}

/*}}}  */
/*{{{  ATerm ASF_ProductionToTerm(ASF_Production arg) */

ATerm ASF_ProductionToTerm(ASF_Production arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_CHAR ASF_CHARFromTerm(ATerm t) */

ASF_CHAR ASF_CHARFromTerm(ATerm t)
{
  return (ASF_CHAR)t;
}

/*}}}  */
/*{{{  ATerm ASF_CHARToTerm(ASF_CHAR arg) */

ATerm ASF_CHARToTerm(ASF_CHAR arg)
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
/*{{{  ASF_TreeAmbs ASF_TreeAmbsFromTerm(ATerm t) */

ASF_TreeAmbs ASF_TreeAmbsFromTerm(ATerm t)
{
  return (ASF_TreeAmbs)t;
}

/*}}}  */
/*{{{  ATerm ASF_TreeAmbsToTerm(ASF_TreeAmbs arg) */

ATerm ASF_TreeAmbsToTerm(ASF_TreeAmbs arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_CHARListFromTerm(ATerm t) */

ASF_CHARList ASF_CHARListFromTerm(ATerm t)
{
  return (ASF_CHARList)t;
}

/*}}}  */
/*{{{  ATerm ASF_CHARListToTerm(ASF_CHARList arg) */

ATerm ASF_CHARListToTerm(ASF_CHARList arg)
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

/*}}}  */
/*{{{  list functions */

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
int ASF_getTreeAmbsLength (ASF_TreeAmbs arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
ASF_TreeAmbs ASF_reverseTreeAmbs(ASF_TreeAmbs arg) {
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

  return (ASF_TreeAmbs) result;
}
ASF_TreeAmbs ASF_appendTreeAmbs(ASF_TreeAmbs arg0, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_Tree arg1) {
  return ASF_concatTreeAmbs(arg0, wsAfterHead, wsAfterSep, ASF_makeTreeAmbsSingle(arg1));
}
ASF_TreeAmbs ASF_concatTreeAmbs(ASF_TreeAmbs arg0, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_TreeAmbs arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = ASF_makeTreeAmbsMany((ASF_Tree)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (ASF_TreeAmbs) ATgetNext((ATermList) arg1);
  return (ASF_TreeAmbs) ATconcat((ATermList) arg0, (ATermList) arg1);
}
ASF_TreeAmbs ASF_sliceTreeAmbs(ASF_TreeAmbs arg, int start, int end) {
  return (ASF_TreeAmbs) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
ASF_Tree ASF_getTreeAmbsTreeAt(ASF_TreeAmbs arg, int index) {
 return (ASF_Tree)ATelementAt((ATermList) arg,index * 4);
}
ASF_TreeAmbs ASF_replaceTreeAmbsTreeAt(ASF_TreeAmbs arg, ASF_Tree elem, int index) {
 return (ASF_TreeAmbs) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
ASF_TreeAmbs ASF_makeTreeAmbs2(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_Tree elem1, ASF_Tree elem2) {
  return ASF_makeTreeAmbsMany(elem1, wsAfterHead, wsAfterSep, ASF_makeTreeAmbsSingle(elem2));
}
ASF_TreeAmbs ASF_makeTreeAmbs3(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_Tree elem1, ASF_Tree elem2, ASF_Tree elem3) {
  return ASF_makeTreeAmbsMany(elem1, wsAfterHead, wsAfterSep, ASF_makeTreeAmbs2(wsAfterHead, wsAfterSep, elem2, elem3));
}
ASF_TreeAmbs ASF_makeTreeAmbs4(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_Tree elem1, ASF_Tree elem2, ASF_Tree elem3, ASF_Tree elem4) {
  return ASF_makeTreeAmbsMany(elem1, wsAfterHead, wsAfterSep, ASF_makeTreeAmbs3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
ASF_TreeAmbs ASF_makeTreeAmbs5(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_Tree elem1, ASF_Tree elem2, ASF_Tree elem3, ASF_Tree elem4, ASF_Tree elem5) {
  return ASF_makeTreeAmbsMany(elem1, wsAfterHead, wsAfterSep, ASF_makeTreeAmbs4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
ASF_TreeAmbs ASF_makeTreeAmbs6(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_Tree elem1, ASF_Tree elem2, ASF_Tree elem3, ASF_Tree elem4, ASF_Tree elem5, ASF_Tree elem6) {
  return ASF_makeTreeAmbsMany(elem1, wsAfterHead, wsAfterSep, ASF_makeTreeAmbs5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int ASF_getCHARListLength (ASF_CHARList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 2) + 1;
}
ASF_CHARList ASF_reverseCHARList(ASF_CHARList arg) {
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

  return (ASF_CHARList) result;
}
ASF_CHARList ASF_appendCHARList(ASF_CHARList arg0, ASF_OptLayout wsAfterHead, ASF_CHAR arg1) {
  return ASF_concatCHARList(arg0, wsAfterHead, ASF_makeCHARListSingle(arg1));
}
ASF_CHARList ASF_concatCHARList(ASF_CHARList arg0, ASF_OptLayout wsAfterHead, ASF_CHARList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = ASF_makeCHARListMany((ASF_CHAR)ATgetFirst((ATermList) arg0), wsAfterHead,  arg1);
  arg1 = (ASF_CHARList) ATgetNext((ATermList) arg1);
  return (ASF_CHARList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
ASF_CHARList ASF_sliceCHARList(ASF_CHARList arg, int start, int end) {
  return (ASF_CHARList) ATgetSlice((ATermList) arg, start * 2, end * 2);
}
ASF_CHAR ASF_getCHARListCHARAt(ASF_CHARList arg, int index) {
 return (ASF_CHAR)ATelementAt((ATermList) arg,index * 2);
}
ASF_CHARList ASF_replaceCHARListCHARAt(ASF_CHARList arg, ASF_CHAR elem, int index) {
 return (ASF_CHARList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 2);
}
ASF_CHARList ASF_makeCHARList2(ASF_OptLayout wsAfterHead, ASF_CHAR elem1, ASF_CHAR elem2) {
  return ASF_makeCHARListMany(elem1, wsAfterHead, ASF_makeCHARListSingle(elem2));
}
ASF_CHARList ASF_makeCHARList3(ASF_OptLayout wsAfterHead, ASF_CHAR elem1, ASF_CHAR elem2, ASF_CHAR elem3) {
  return ASF_makeCHARListMany(elem1, wsAfterHead, ASF_makeCHARList2(wsAfterHead, elem2, elem3));
}
ASF_CHARList ASF_makeCHARList4(ASF_OptLayout wsAfterHead, ASF_CHAR elem1, ASF_CHAR elem2, ASF_CHAR elem3, ASF_CHAR elem4) {
  return ASF_makeCHARListMany(elem1, wsAfterHead, ASF_makeCHARList3(wsAfterHead, elem2, elem3, elem4));
}
ASF_CHARList ASF_makeCHARList5(ASF_OptLayout wsAfterHead, ASF_CHAR elem1, ASF_CHAR elem2, ASF_CHAR elem3, ASF_CHAR elem4, ASF_CHAR elem5) {
  return ASF_makeCHARListMany(elem1, wsAfterHead, ASF_makeCHARList4(wsAfterHead, elem2, elem3, elem4, elem5));
}
ASF_CHARList ASF_makeCHARList6(ASF_OptLayout wsAfterHead, ASF_CHAR elem1, ASF_CHAR elem2, ASF_CHAR elem3, ASF_CHAR elem4, ASF_CHAR elem5, ASF_CHAR elem6) {
  return ASF_makeCHARListMany(elem1, wsAfterHead, ASF_makeCHARList5(wsAfterHead, elem2, elem3, elem4, elem5, elem6));
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

/*{{{  ASF_Production ASF_makeProductionLexicalConstructor(const char* formalName, ASF_Symbol symbol) */

ASF_Production ASF_makeProductionLexicalConstructor(const char* formalName, ASF_Symbol symbol)
{
  return (ASF_Production)(ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun2))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun8))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun9))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(formalName, 0, ATtrue)))), (ATerm) symbol, (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun13))))));
}

/*}}}  */
/*{{{  ASF_CHAR ASF_makeCHARDefault(const char* string) */

ASF_CHAR ASF_makeCHARDefault(const char* string)
{
  return (ASF_CHAR)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun8)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun8))), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun18, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun19, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm) ((ATerm) ASF_stringToChars(string)))));
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_makeASFConditionPositive(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquals, ASF_Tree rhs) */

ASF_ASFCondition ASF_makeASFConditionPositive(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquals, ASF_Tree rhs)
{
  return (ASF_ASFCondition)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun20))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm) lhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun22)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterEquals), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun20))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_makeASFConditionNegative(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterUnequal, ASF_Tree rhs) */

ASF_ASFCondition ASF_makeASFConditionNegative(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterUnequal, ASF_Tree rhs)
{
  return (ASF_ASFCondition)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun23))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm) lhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun24)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterUnequal), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun23))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_makeASFConditionEquality(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquality, ASF_Tree rhs) */

ASF_ASFCondition ASF_makeASFConditionEquality(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquality, ASF_Tree rhs)
{
  return (ASF_ASFCondition)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun25))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm) lhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun26)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterEquality), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun25))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_makeASFConditionMatch(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterMatch, ASF_Tree rhs) */

ASF_ASFCondition ASF_makeASFConditionMatch(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterMatch, ASF_Tree rhs)
{
  return (ASF_ASFCondition)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun27))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm) lhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun28)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterMatch), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun27))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_makeASFConditionNoMatch(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterMatch, ASF_Tree rhs) */

ASF_ASFCondition ASF_makeASFConditionNoMatch(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterMatch, ASF_Tree rhs)
{
  return (ASF_ASFCondition)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun29))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm) lhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun30)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterMatch), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun29))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  ASF_ASFConditions ASF_makeASFConditionsDefault(ASF_ASFConditionList list) */

ASF_ASFConditions ASF_makeASFConditionsDefault(ASF_ASFConditionList list)
{
  return (ASF_ASFConditions)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl2(ASF_afun31, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21)), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun32))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun33))), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl2(ASF_afun31, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21)), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun32))))), (ATerm) list)));
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
  return (ASF_ASFConditionList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun32))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  ASF_Tree ASF_makeTreeAmbiguityConstructor(ASF_Symbol amb, ASF_Symbol symbol, ASF_OptLayout wsAfterAmb, ASF_OptLayout wsAfterParenOpen, ASF_Symbol listSymbol, ASF_TreeAmbs ambs, ASF_OptLayout wsAfterAmbs) */

ASF_Tree ASF_makeTreeAmbiguityConstructor(ASF_Symbol amb, ASF_Symbol symbol, ASF_OptLayout wsAfterAmb, ASF_OptLayout wsAfterParenOpen, ASF_Symbol listSymbol, ASF_TreeAmbs ambs, ASF_OptLayout wsAfterAmbs)
{
  return (ASF_Tree)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun2))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl2(ASF_afun34, (ATerm) amb, (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun32))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun9))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun35))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm) symbol), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun36)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun2))), (ATerm) wsAfterAmbs), (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl2(ASF_afun34, (ATerm) listSymbol, (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun32))))), (ATerm) ambs)), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun9))), (ATerm) wsAfterAmb), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun35))));
}

/*}}}  */
/*{{{  ASF_Tree ASF_makeTreeLexicalConstructor(const char* formalName, ASF_Symbol symbol, ASF_Tree name, ASF_OptLayout wsAfterName, ASF_OptLayout wsAfterParenOpen, ASF_CHARList list, ASF_OptLayout wsAfterList) */

ASF_Tree ASF_makeTreeLexicalConstructor(const char* formalName, ASF_Symbol symbol, ASF_Tree name, ASF_OptLayout wsAfterName, ASF_OptLayout wsAfterParenOpen, ASF_CHARList list, ASF_OptLayout wsAfterList)
{
  return (ASF_Tree)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun2))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun8))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun9))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(formalName, 0, ATtrue)))), (ATerm) symbol, (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun13)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun2))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun8))))), (ATerm) list)), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun9))), (ATerm) wsAfterName), (ATerm) name));
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_makeTreeAmbsEmpty(void) */

ASF_TreeAmbs ASF_makeTreeAmbsEmpty(void)
{
  return (ASF_TreeAmbs)(ATerm)ATempty;
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_makeTreeAmbsSingle(ASF_Tree head) */

ASF_TreeAmbs ASF_makeTreeAmbsSingle(ASF_Tree head)
{
  return (ASF_TreeAmbs)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_makeTreeAmbsMany(ASF_Tree head, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_TreeAmbs tail) */

ASF_TreeAmbs ASF_makeTreeAmbsMany(ASF_Tree head, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_TreeAmbs tail)
{
  if (ASF_isTreeAmbsEmpty(tail)) {
    return ASF_makeTreeAmbsSingle(head);
  }
  return (ASF_TreeAmbs)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun32))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  ASF_CHARList ASF_makeCHARListEmpty(void) */

ASF_CHARList ASF_makeCHARListEmpty(void)
{
  return (ASF_CHARList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_makeCHARListSingle(ASF_CHAR head) */

ASF_CHARList ASF_makeCHARListSingle(ASF_CHAR head)
{
  return (ASF_CHARList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  ASF_CHARList ASF_makeCHARListMany(ASF_CHAR head, ASF_OptLayout wsAfterHead, ASF_CHARList tail) */

ASF_CHARList ASF_makeCHARListMany(ASF_CHAR head, ASF_OptLayout wsAfterHead, ASF_CHARList tail)
{
  if (ASF_isCHARListEmpty(tail)) {
    return ASF_makeCHARListSingle(head);
  }
  return (ASF_CHARList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  ASF_ASFImplies ASF_makeASFImpliesDefault(const char* string) */

ASF_ASFImplies ASF_makeASFImpliesDefault(const char* string)
{
  return (ASF_ASFImplies)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun37)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun37))), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun18, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun19, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm) ((ATerm) ASF_stringToChars(string)))));
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_makeASFConditionalEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation) */

ASF_ASFConditionalEquation ASF_makeASFConditionalEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation)
{
  return (ASF_ASFConditionalEquation)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun38)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun39)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun40))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun41)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) ASFEquation), (ATerm) wsAfterASFTag), (ATerm) ASFTag));
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_makeASFConditionalEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFEquation ASFEquation) */

ASF_ASFConditionalEquation ASF_makeASFConditionalEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFEquation ASFEquation)
{
  return (ASF_ASFConditionalEquation)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun38)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun37)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun33)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun39)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun40))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun42)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) ASFEquation), (ATerm) wsAfterASFImplies), (ATerm) ASFImplies), (ATerm) wsAfterASFConditions), (ATerm) ASFConditions), (ATerm) wsAfterASFTag), (ATerm) ASFTag));
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_makeASFConditionalEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation, ASF_OptLayout wsAfterASFEquation, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions) */

ASF_ASFConditionalEquation ASF_makeASFConditionalEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation, ASF_OptLayout wsAfterASFEquation, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions)
{
  return (ASF_ASFConditionalEquation)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun33)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun43))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun38)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun39)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun40))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun43)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) ASFConditions), (ATerm) wsAfterWhen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun43))), (ATerm) wsAfterASFEquation), (ATerm) ASFEquation), (ATerm) wsAfterASFTag), (ATerm) ASFTag));
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_makeASFEquationDefault(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquals, ASF_Tree rhs) */

ASF_ASFEquation ASF_makeASFEquationDefault(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquals, ASF_Tree rhs)
{
  return (ASF_ASFEquation)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun20))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm) lhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun38))), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterEquals), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun20))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  ASF_ASFModule ASF_makeASFModuleDefault(ASF_ASFSectionList list) */

ASF_ASFModule ASF_makeASFModuleDefault(ASF_ASFSectionList list)
{
  return (ASF_ASFModule)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun44))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun45))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun46)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun44))))), (ATerm) list)));
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
/*{{{  ASF_ASFSection ASF_makeASFSectionEquations(ASF_OptLayout wsAfterEquations, ASF_ASFConditionalEquationList list) */

ASF_ASFSection ASF_makeASFSectionEquations(ASF_OptLayout wsAfterEquations, ASF_ASFConditionalEquationList list)
{
  return (ASF_ASFSection)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun40))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun47))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun44))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun47)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun40))))), (ATerm) list)), (ATerm) wsAfterEquations), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun47))));
}

/*}}}  */
/*{{{  ASF_ASFSection ASF_makeASFSectionTests(ASF_OptLayout wsAfterTests, ASF_ASFTestEquationTestList testList) */

ASF_ASFSection ASF_makeASFSectionTests(ASF_OptLayout wsAfterTests, ASF_ASFTestEquationTestList testList)
{
  return (ASF_ASFSection)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun48))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun49))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun44))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun49)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun48))))), (ATerm) testList)), (ATerm) wsAfterTests), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun49))));
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
/*{{{  ASF_ASFTagId ASF_makeASFTagIdOneChar(const char* string) */

ASF_ASFTagId ASF_makeASFTagIdOneChar(const char* string)
{
  return (ASF_ASFTagId)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun50)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun50))), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun18, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun19, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm) ((ATerm) ASF_stringToChars(string)))));
}

/*}}}  */
/*{{{  ASF_ASFTagId ASF_makeASFTagIdManyChars(const char* string) */

ASF_ASFTagId ASF_makeASFTagIdManyChars(const char* string)
{
  return (ASF_ASFTagId)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun50)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun50))), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun17, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun18, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun19, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm) ((ATerm) ASF_stringToChars(string)))));
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_makeASFTagEmpty(ASF_OptLayout wsAfterBracketOpen) */

ASF_ASFTag ASF_makeASFTagEmpty(ASF_OptLayout wsAfterBracketOpen)
{
  return (ASF_ASFTag)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun51))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun52))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun39))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun53)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun51))), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun52))));
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_makeASFTagNotEmpty(ASF_OptLayout wsAfterBracketOpen, ASF_ASFTagId ASFTagId, ASF_OptLayout wsAfterASFTagId) */

ASF_ASFTag ASF_makeASFTagNotEmpty(ASF_OptLayout wsAfterBracketOpen, ASF_ASFTagId ASFTagId, ASF_OptLayout wsAfterASFTagId)
{
  return (ASF_ASFTag)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun51))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun50)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun52))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun39))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun54)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun51))), (ATerm) wsAfterASFTagId), (ATerm) ASFTagId), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun52))));
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_makeASFTestEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFCondition ASFCondition) */

ASF_ASFTestEquation ASF_makeASFTestEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFCondition ASFCondition)
{
  return (ASF_ASFTestEquation)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun39)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun48))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun41)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) ASFCondition), (ATerm) wsAfterASFTag), (ATerm) ASFTag));
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_makeASFTestEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFCondition ASFCondition) */

ASF_ASFTestEquation ASF_makeASFTestEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFCondition ASFCondition)
{
  return (ASF_ASFTestEquation)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun37)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun33)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun39)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun48))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun42)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) ASFCondition), (ATerm) wsAfterASFImplies), (ATerm) ASFImplies), (ATerm) wsAfterASFConditions), (ATerm) ASFConditions), (ATerm) wsAfterASFTag), (ATerm) ASFTag));
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_makeASFTestEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFCondition ASFCondition, ASF_OptLayout wsAfterASFCondition, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions) */

ASF_ASFTestEquation ASF_makeASFTestEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFCondition ASFCondition, ASF_OptLayout wsAfterASFCondition, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions)
{
  return (ASF_ASFTestEquation)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun33)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun43))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun39)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun48))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun43)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) ASFConditions), (ATerm) wsAfterWhen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun43))), (ATerm) wsAfterASFCondition), (ATerm) ASFCondition), (ATerm) wsAfterASFTag), (ATerm) ASFTag));
}

/*}}}  */
/*{{{  ASF_Start ASF_makeStartASFTestEquation(ASF_OptLayout wsBefore, ASF_ASFTestEquation topASFTestEquation, ASF_OptLayout wsAfter, int ambCnt) */

ASF_Start ASF_makeStartASFTestEquation(ASF_OptLayout wsBefore, ASF_ASFTestEquation topASFTestEquation, ASF_OptLayout wsAfter, int ambCnt)
{
  return (ASF_Start)(ATerm)ATmakeAppl2(ASF_afun55, (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun48)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun56)), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topASFTestEquation), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  ASF_Start ASF_makeStartASFTag(ASF_OptLayout wsBefore, ASF_ASFTag topASFTag, ASF_OptLayout wsAfter, int ambCnt) */

ASF_Start ASF_makeStartASFTag(ASF_OptLayout wsBefore, ASF_ASFTag topASFTag, ASF_OptLayout wsAfter, int ambCnt)
{
  return (ASF_Start)(ATerm)ATmakeAppl2(ASF_afun55, (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun39)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun56)), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topASFTag), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  ASF_Start ASF_makeStartASFTagId(ASF_OptLayout wsBefore, ASF_ASFTagId topASFTagId, ASF_OptLayout wsAfter, int ambCnt) */

ASF_Start ASF_makeStartASFTagId(ASF_OptLayout wsBefore, ASF_ASFTagId topASFTagId, ASF_OptLayout wsAfter, int ambCnt)
{
  return (ASF_Start)(ATerm)ATmakeAppl2(ASF_afun55, (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun50)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun56)), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topASFTagId), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  ASF_Start ASF_makeStartASFSection(ASF_OptLayout wsBefore, ASF_ASFSection topASFSection, ASF_OptLayout wsAfter, int ambCnt) */

ASF_Start ASF_makeStartASFSection(ASF_OptLayout wsBefore, ASF_ASFSection topASFSection, ASF_OptLayout wsAfter, int ambCnt)
{
  return (ASF_Start)(ATerm)ATmakeAppl2(ASF_afun55, (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun44)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun56)), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topASFSection), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  ASF_Start ASF_makeStartASFModule(ASF_OptLayout wsBefore, ASF_ASFModule topASFModule, ASF_OptLayout wsAfter, int ambCnt) */

ASF_Start ASF_makeStartASFModule(ASF_OptLayout wsBefore, ASF_ASFModule topASFModule, ASF_OptLayout wsAfter, int ambCnt)
{
  return (ASF_Start)(ATerm)ATmakeAppl2(ASF_afun55, (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun45)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun56)), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topASFModule), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  ASF_Start ASF_makeStartASFConditionalEquation(ASF_OptLayout wsBefore, ASF_ASFConditionalEquation topASFConditionalEquation, ASF_OptLayout wsAfter, int ambCnt) */

ASF_Start ASF_makeStartASFConditionalEquation(ASF_OptLayout wsBefore, ASF_ASFConditionalEquation topASFConditionalEquation, ASF_OptLayout wsAfter, int ambCnt)
{
  return (ASF_Start)(ATerm)ATmakeAppl2(ASF_afun55, (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun40)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun56)), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topASFConditionalEquation), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  ASF_Start ASF_makeStartASFEquation(ASF_OptLayout wsBefore, ASF_ASFEquation topASFEquation, ASF_OptLayout wsAfter, int ambCnt) */

ASF_Start ASF_makeStartASFEquation(ASF_OptLayout wsBefore, ASF_ASFEquation topASFEquation, ASF_OptLayout wsAfter, int ambCnt)
{
  return (ASF_Start)(ATerm)ATmakeAppl2(ASF_afun55, (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun38)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun56)), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topASFEquation), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  ASF_Start ASF_makeStartASFImplies(ASF_OptLayout wsBefore, ASF_ASFImplies topASFImplies, ASF_OptLayout wsAfter, int ambCnt) */

ASF_Start ASF_makeStartASFImplies(ASF_OptLayout wsBefore, ASF_ASFImplies topASFImplies, ASF_OptLayout wsAfter, int ambCnt)
{
  return (ASF_Start)(ATerm)ATmakeAppl2(ASF_afun55, (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun37)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun56)), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topASFImplies), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  ASF_Start ASF_makeStartTree(ASF_OptLayout wsBefore, ASF_Tree topTree, ASF_OptLayout wsAfter, int ambCnt) */

ASF_Start ASF_makeStartTree(ASF_OptLayout wsBefore, ASF_Tree topTree, ASF_OptLayout wsAfter, int ambCnt)
{
  return (ASF_Start)(ATerm)ATmakeAppl2(ASF_afun55, (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun57)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun56)), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topTree), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  ASF_Start ASF_makeStartASFConditions(ASF_OptLayout wsBefore, ASF_ASFConditions topASFConditions, ASF_OptLayout wsAfter, int ambCnt) */

ASF_Start ASF_makeStartASFConditions(ASF_OptLayout wsBefore, ASF_ASFConditions topASFConditions, ASF_OptLayout wsAfter, int ambCnt)
{
  return (ASF_Start)(ATerm)ATmakeAppl2(ASF_afun55, (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun33)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun56)), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topASFConditions), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  ASF_Start ASF_makeStartASFCondition(ASF_OptLayout wsBefore, ASF_ASFCondition topASFCondition, ASF_OptLayout wsAfter, int ambCnt) */

ASF_Start ASF_makeStartASFCondition(ASF_OptLayout wsBefore, ASF_ASFCondition topASFCondition, ASF_OptLayout wsAfter, int ambCnt)
{
  return (ASF_Start)(ATerm)ATmakeAppl2(ASF_afun55, (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun56)), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topASFCondition), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_makeOptLayoutAbsent(void) */

ASF_OptLayout ASF_makeOptLayoutAbsent(void)
{
  return (ASF_OptLayout)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATempty, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5))), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_makeOptLayoutPresent(const char* string) */

ASF_OptLayout ASF_makeOptLayoutPresent(const char* string)
{
  return (ASF_OptLayout)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun5))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5))), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm) ((ATerm) ASF_stringToChars(string)));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool ASF_isEqualProduction(ASF_Production arg0, ASF_Production arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualCHAR(ASF_CHAR arg0, ASF_CHAR arg1)
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

ATbool ASF_isEqualTree(ASF_Tree arg0, ASF_Tree arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualTreeAmbs(ASF_TreeAmbs arg0, ASF_TreeAmbs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualCHARList(ASF_CHARList arg0, ASF_CHARList arg1)
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

ATbool ASF_isEqualASFModule(ASF_ASFModule arg0, ASF_ASFModule arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFSectionList(ASF_ASFSectionList arg0, ASF_ASFSectionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFSection(ASF_ASFSection arg0, ASF_ASFSection arg1)
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

ATbool ASF_isEqualStart(ASF_Start arg0, ASF_Start arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualOptLayout(ASF_OptLayout arg0, ASF_OptLayout arg1)
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
/*{{{  inline ATbool ASF_isProductionLexicalConstructor(ASF_Production arg) */

inline ATbool ASF_isProductionLexicalConstructor(ASF_Production arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternProductionLexicalConstructor, NULL, NULL));
#endif
  return ATtrue;
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
/*{{{  ATbool ASF_hasProductionSymbol(ASF_Production arg) */

ATbool ASF_hasProductionSymbol(ASF_Production arg)
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ASF_getProductionFormalName(ASF_Production arg) */

char* ASF_getProductionFormalName(ASF_Production arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 0)), 0)));
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getProductionSymbol(ASF_Production arg) */

ASF_Symbol ASF_getProductionSymbol(ASF_Production arg)
{
  
    return (ASF_Symbol)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  ASF_Production ASF_setProductionFormalName(ASF_Production arg, const char* formalName) */

ASF_Production ASF_setProductionFormalName(ASF_Production arg, const char* formalName)
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return (ASF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 0)), (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(formalName, 0, ATtrue))), 0), 0), 0);
  }

  ATabort("Production has no FormalName: %t\n", arg);
  return (ASF_Production)NULL;
}

/*}}}  */
/*{{{  ASF_Production ASF_setProductionSymbol(ASF_Production arg, ASF_Symbol symbol) */

ASF_Production ASF_setProductionSymbol(ASF_Production arg, ASF_Symbol symbol)
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return (ASF_Production)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) symbol), 1);
  }

  ATabort("Production has no Symbol: %t\n", arg);
  return (ASF_Production)NULL;
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
/*{{{  inline ATbool ASF_isCHARDefault(ASF_CHAR arg) */

inline ATbool ASF_isCHARDefault(ASF_CHAR arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternCHARDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasCHARString(ASF_CHAR arg) */

ATbool ASF_hasCHARString(ASF_CHAR arg)
{
  if (ASF_isCHARDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ASF_getCHARString(ASF_CHAR arg) */

char* ASF_getCHARString(ASF_CHAR arg)
{
  
    return (char*)ASF_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  ASF_CHAR ASF_setCHARString(ASF_CHAR arg, const char* string) */

ASF_CHAR ASF_setCHARString(ASF_CHAR arg, const char* string)
{
  if (ASF_isCHARDefault(arg)) {
    return (ASF_CHAR)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) ASF_stringToChars(string))), 1), 0), 1);
  }

  ATabort("CHAR has no String: %t\n", arg);
  return (ASF_CHAR)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFCondition accessors */

/*{{{  ATbool ASF_isValidASFCondition(ASF_ASFCondition arg) */

ATbool ASF_isValidASFCondition(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNegative(arg)) {
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
/*{{{  inline ATbool ASF_isASFConditionPositive(ASF_ASFCondition arg) */

inline ATbool ASF_isASFConditionPositive(ASF_ASFCondition arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionPositive, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
/*{{{  ATbool ASF_hasASFConditionLhsSymbol(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionLhsSymbol(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNegative(arg)) {
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
/*{{{  ATbool ASF_hasASFConditionRhsSymbol(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionRhsSymbol(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNegative(arg)) {
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
  if (ASF_isASFConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNegative(arg)) {
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
  if (ASF_isASFConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNegative(arg)) {
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
/*{{{  ATbool ASF_hasASFConditionWsAfterEquals(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionWsAfterEquals(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionRhs(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionRhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNegative(arg)) {
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
/*{{{  ASF_Symbol ASF_getASFConditionLhsSymbol(ASF_ASFCondition arg) */

ASF_Symbol ASF_getASFConditionLhsSymbol(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
  }
  else if (ASF_isASFConditionNegative(arg)) {
    return (ASF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return (ASF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return (ASF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
  }
  else 
    return (ASF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getASFConditionRhsSymbol(ASF_ASFCondition arg) */

ASF_Symbol ASF_getASFConditionRhsSymbol(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
  }
  else if (ASF_isASFConditionNegative(arg)) {
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
  }
  else 
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
}

/*}}}  */
/*{{{  ASF_Tree ASF_getASFConditionLhs(ASF_ASFCondition arg) */

ASF_Tree ASF_getASFConditionLhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_Tree)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isASFConditionNegative(arg)) {
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
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (ASF_isASFConditionNegative(arg)) {
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
/*{{{  ASF_OptLayout ASF_getASFConditionWsAfterEquals(ASF_ASFCondition arg) */

ASF_OptLayout ASF_getASFConditionWsAfterEquals(ASF_ASFCondition arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_Tree ASF_getASFConditionRhs(ASF_ASFCondition arg) */

ASF_Tree ASF_getASFConditionRhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (ASF_isASFConditionNegative(arg)) {
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
/*{{{  ASF_OptLayout ASF_getASFConditionWsAfterUnequal(ASF_ASFCondition arg) */

ASF_OptLayout ASF_getASFConditionWsAfterUnequal(ASF_ASFCondition arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
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
/*{{{  ASF_ASFCondition ASF_setASFConditionLhsSymbol(ASF_ASFCondition arg, ASF_Symbol lhsSymbol) */

ASF_ASFCondition ASF_setASFConditionLhsSymbol(ASF_ASFCondition arg, ASF_Symbol lhsSymbol)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) lhsSymbol), 0), 0), 0);
  }
  else if (ASF_isASFConditionNegative(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) lhsSymbol), 0), 0), 0);
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) lhsSymbol), 0), 0), 0);
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) lhsSymbol), 0), 0), 0);
  }
  else if (ASF_isASFConditionNoMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) lhsSymbol), 0), 0), 0);
  }

  ATabort("ASFCondition has no LhsSymbol: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionRhsSymbol(ASF_ASFCondition arg, ASF_Symbol rhsSymbol) */

ASF_ASFCondition ASF_setASFConditionRhsSymbol(ASF_ASFCondition arg, ASF_Symbol rhsSymbol)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) rhsSymbol), 4), 0), 0);
  }
  else if (ASF_isASFConditionNegative(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) rhsSymbol), 4), 0), 0);
  }
  else if (ASF_isASFConditionEquality(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) rhsSymbol), 4), 0), 0);
  }
  else if (ASF_isASFConditionMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) rhsSymbol), 4), 0), 0);
  }
  else if (ASF_isASFConditionNoMatch(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) rhsSymbol), 4), 0), 0);
  }

  ATabort("ASFCondition has no RhsSymbol: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionLhs(ASF_ASFCondition arg, ASF_Tree lhs) */

ASF_ASFCondition ASF_setASFConditionLhs(ASF_ASFCondition arg, ASF_Tree lhs)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }
  else if (ASF_isASFConditionNegative(arg)) {
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
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }
  else if (ASF_isASFConditionNegative(arg)) {
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
/*{{{  ASF_ASFCondition ASF_setASFConditionWsAfterEquals(ASF_ASFCondition arg, ASF_OptLayout wsAfterEquals) */

ASF_ASFCondition ASF_setASFConditionWsAfterEquals(ASF_ASFCondition arg, ASF_OptLayout wsAfterEquals)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEquals), 3), 1);
  }

  ATabort("ASFCondition has no WsAfterEquals: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionRhs(ASF_ASFCondition arg, ASF_Tree rhs) */

ASF_ASFCondition ASF_setASFConditionRhs(ASF_ASFCondition arg, ASF_Tree rhs)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }
  else if (ASF_isASFConditionNegative(arg)) {
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
/*{{{  ASF_Tree accessors */

/*{{{  ATbool ASF_isValidTree(ASF_Tree arg) */

ATbool ASF_isValidTree(ASF_Tree arg)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return ATtrue;
  }
  else if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isTreeAmbiguityConstructor(ASF_Tree arg) */

inline ATbool ASF_isTreeAmbiguityConstructor(ASF_Tree arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternTreeAmbiguityConstructor, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isTreeLexicalConstructor(ASF_Tree arg) */

inline ATbool ASF_isTreeLexicalConstructor(ASF_Tree arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternTreeLexicalConstructor, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeAmb(ASF_Tree arg) */

ATbool ASF_hasTreeAmb(ASF_Tree arg)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeSymbol(ASF_Tree arg) */

ATbool ASF_hasTreeSymbol(ASF_Tree arg)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return ATtrue;
  }
  else if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeWsAfterAmb(ASF_Tree arg) */

ATbool ASF_hasTreeWsAfterAmb(ASF_Tree arg)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeWsAfterParenOpen(ASF_Tree arg) */

ATbool ASF_hasTreeWsAfterParenOpen(ASF_Tree arg)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return ATtrue;
  }
  else if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeListSymbol(ASF_Tree arg) */

ATbool ASF_hasTreeListSymbol(ASF_Tree arg)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeAmbs(ASF_Tree arg) */

ATbool ASF_hasTreeAmbs(ASF_Tree arg)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeWsAfterAmbs(ASF_Tree arg) */

ATbool ASF_hasTreeWsAfterAmbs(ASF_Tree arg)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  ATbool ASF_hasTreeName(ASF_Tree arg) */

ATbool ASF_hasTreeName(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  ATbool ASF_hasTreeList(ASF_Tree arg) */

ATbool ASF_hasTreeList(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  ASF_Symbol ASF_getTreeAmb(ASF_Tree arg) */

ASF_Symbol ASF_getTreeAmb(ASF_Tree arg)
{
  
    return (ASF_Symbol)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4), 0), 0);
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getTreeSymbol(ASF_Tree arg) */

ASF_Symbol ASF_getTreeSymbol(ASF_Tree arg)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return (ASF_Symbol)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 0);
  }
  else 
    return (ASF_Symbol)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getTreeWsAfterAmb(ASF_Tree arg) */

ASF_OptLayout ASF_getTreeWsAfterAmb(ASF_Tree arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getTreeWsAfterParenOpen(ASF_Tree arg) */

ASF_OptLayout ASF_getTreeWsAfterParenOpen(ASF_Tree arg)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getTreeListSymbol(ASF_Tree arg) */

ASF_Symbol ASF_getTreeListSymbol(ASF_Tree arg)
{
  
    return (ASF_Symbol)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 0), 0), 0), 0);
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_getTreeAmbs(ASF_Tree arg) */

ASF_TreeAmbs ASF_getTreeAmbs(ASF_Tree arg)
{
  
    return (ASF_TreeAmbs)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getTreeWsAfterAmbs(ASF_Tree arg) */

ASF_OptLayout ASF_getTreeWsAfterAmbs(ASF_Tree arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  char* ASF_getTreeFormalName(ASF_Tree arg) */

char* ASF_getTreeFormalName(ASF_Tree arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0)), 0)));
}

/*}}}  */
/*{{{  ASF_Tree ASF_getTreeName(ASF_Tree arg) */

ASF_Tree ASF_getTreeName(ASF_Tree arg)
{
  
    return (ASF_Tree)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getTreeWsAfterName(ASF_Tree arg) */

ASF_OptLayout ASF_getTreeWsAfterName(ASF_Tree arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_CHARList ASF_getTreeList(ASF_Tree arg) */

ASF_CHARList ASF_getTreeList(ASF_Tree arg)
{
  
    return (ASF_CHARList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getTreeWsAfterList(ASF_Tree arg) */

ASF_OptLayout ASF_getTreeWsAfterList(ASF_Tree arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeAmb(ASF_Tree arg, ASF_Symbol amb) */

ASF_Tree ASF_setTreeAmb(ASF_Tree arg, ASF_Symbol amb)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4), 0), (ATerm)((ATerm) amb), 0), 0), 4), 0), 0);
  }

  ATabort("Tree has no Amb: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeSymbol(ASF_Tree arg, ASF_Symbol symbol) */

ASF_Tree ASF_setTreeSymbol(ASF_Tree arg, ASF_Symbol symbol)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) symbol), 0), 1), 0);
  }
  else if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)((ATerm) symbol), 1), 0);
  }

  ATabort("Tree has no Symbol: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterAmb(ASF_Tree arg, ASF_OptLayout wsAfterAmb) */

ASF_Tree ASF_setTreeWsAfterAmb(ASF_Tree arg, ASF_OptLayout wsAfterAmb)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAmb), 1), 1);
  }

  ATabort("Tree has no WsAfterAmb: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterParenOpen(ASF_Tree arg, ASF_OptLayout wsAfterParenOpen) */

ASF_Tree ASF_setTreeWsAfterParenOpen(ASF_Tree arg, ASF_OptLayout wsAfterParenOpen)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Tree has no WsAfterParenOpen: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeListSymbol(ASF_Tree arg, ASF_Symbol listSymbol) */

ASF_Tree ASF_setTreeListSymbol(ASF_Tree arg, ASF_Symbol listSymbol)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 0), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 0), 0), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 0), 0), 0), (ATerm)((ATerm) listSymbol), 0), 0), 0), 0), 4), 1);
  }

  ATabort("Tree has no ListSymbol: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeAmbs(ASF_Tree arg, ASF_TreeAmbs ambs) */

ASF_Tree ASF_setTreeAmbs(ASF_Tree arg, ASF_TreeAmbs ambs)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)((ATerm) ambs), 1), 4), 1);
  }

  ATabort("Tree has no Ambs: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterAmbs(ASF_Tree arg, ASF_OptLayout wsAfterAmbs) */

ASF_Tree ASF_setTreeWsAfterAmbs(ASF_Tree arg, ASF_OptLayout wsAfterAmbs)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAmbs), 5), 1);
  }

  ATabort("Tree has no WsAfterAmbs: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeFormalName(ASF_Tree arg, const char* formalName) */

ASF_Tree ASF_setTreeFormalName(ASF_Tree arg, const char* formalName)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0)), (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(formalName, 0, ATtrue))), 0), 0), 0), 0);
  }

  ATabort("Tree has no FormalName: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeName(ASF_Tree arg, ASF_Tree name) */

ASF_Tree ASF_setTreeName(ASF_Tree arg, ASF_Tree name)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) name), 0), 1);
  }

  ATabort("Tree has no Name: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterName(ASF_Tree arg, ASF_OptLayout wsAfterName) */

ASF_Tree ASF_setTreeWsAfterName(ASF_Tree arg, ASF_OptLayout wsAfterName)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterName), 1), 1);
  }

  ATabort("Tree has no WsAfterName: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeList(ASF_Tree arg, ASF_CHARList list) */

ASF_Tree ASF_setTreeList(ASF_Tree arg, ASF_CHARList list)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)((ATerm) list), 1), 4), 1);
  }

  ATabort("Tree has no List: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterList(ASF_Tree arg, ASF_OptLayout wsAfterList) */

ASF_Tree ASF_setTreeWsAfterList(ASF_Tree arg, ASF_OptLayout wsAfterList)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 5), 1);
  }

  ATabort("Tree has no WsAfterList: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_TreeAmbs accessors */

/*{{{  ATbool ASF_isValidTreeAmbs(ASF_TreeAmbs arg) */

ATbool ASF_isValidTreeAmbs(ASF_TreeAmbs arg)
{
  if (ASF_isTreeAmbsEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isTreeAmbsSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isTreeAmbsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isTreeAmbsEmpty(ASF_TreeAmbs arg) */

inline ATbool ASF_isTreeAmbsEmpty(ASF_TreeAmbs arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternTreeAmbsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool ASF_isTreeAmbsSingle(ASF_TreeAmbs arg) */

inline ATbool ASF_isTreeAmbsSingle(ASF_TreeAmbs arg)
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
      last_result = ATmatchTerm((ATerm)arg, ASF_patternTreeAmbsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isTreeAmbsMany(ASF_TreeAmbs arg) */

inline ATbool ASF_isTreeAmbsMany(ASF_TreeAmbs arg)
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
      last_result = ATmatchTerm((ATerm)arg, ASF_patternTreeAmbsMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeAmbsHead(ASF_TreeAmbs arg) */

ATbool ASF_hasTreeAmbsHead(ASF_TreeAmbs arg)
{
  if (ASF_isTreeAmbsSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isTreeAmbsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeAmbsWsAfterHead(ASF_TreeAmbs arg) */

ATbool ASF_hasTreeAmbsWsAfterHead(ASF_TreeAmbs arg)
{
  if (ASF_isTreeAmbsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeAmbsWsAfterSep(ASF_TreeAmbs arg) */

ATbool ASF_hasTreeAmbsWsAfterSep(ASF_TreeAmbs arg)
{
  if (ASF_isTreeAmbsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeAmbsTail(ASF_TreeAmbs arg) */

ATbool ASF_hasTreeAmbsTail(ASF_TreeAmbs arg)
{
  if (ASF_isTreeAmbsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_getTreeAmbsTail(ASF_TreeAmbs arg) */

ASF_TreeAmbs ASF_getTreeAmbsTail(ASF_TreeAmbs arg)
{
  assert(!ASF_isTreeAmbsEmpty(arg) && "getTail on an empty list");
  if (ASF_isTreeAmbsSingle(arg)) {
    return (ASF_TreeAmbs) ASF_makeTreeAmbsEmpty();
  }
  else {
  
    return (ASF_TreeAmbs)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  ASF_Tree ASF_getTreeAmbsHead(ASF_TreeAmbs arg) */

ASF_Tree ASF_getTreeAmbsHead(ASF_TreeAmbs arg)
{
  if (ASF_isTreeAmbsSingle(arg)) {
    return (ASF_Tree)ATgetFirst((ATermList)arg);
  }
  else 
    return (ASF_Tree)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getTreeAmbsWsAfterHead(ASF_TreeAmbs arg) */

ASF_OptLayout ASF_getTreeAmbsWsAfterHead(ASF_TreeAmbs arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getTreeAmbsWsAfterSep(ASF_TreeAmbs arg) */

ASF_OptLayout ASF_getTreeAmbsWsAfterSep(ASF_TreeAmbs arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_setTreeAmbsHead(ASF_TreeAmbs arg, ASF_Tree head) */

ASF_TreeAmbs ASF_setTreeAmbsHead(ASF_TreeAmbs arg, ASF_Tree head)
{
  if (ASF_isTreeAmbsSingle(arg)) {
    return (ASF_TreeAmbs)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (ASF_isTreeAmbsMany(arg)) {
    return (ASF_TreeAmbs)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("TreeAmbs has no Head: %t\n", arg);
  return (ASF_TreeAmbs)NULL;
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_setTreeAmbsWsAfterHead(ASF_TreeAmbs arg, ASF_OptLayout wsAfterHead) */

ASF_TreeAmbs ASF_setTreeAmbsWsAfterHead(ASF_TreeAmbs arg, ASF_OptLayout wsAfterHead)
{
  if (ASF_isTreeAmbsMany(arg)) {
    return (ASF_TreeAmbs)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("TreeAmbs has no WsAfterHead: %t\n", arg);
  return (ASF_TreeAmbs)NULL;
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_setTreeAmbsWsAfterSep(ASF_TreeAmbs arg, ASF_OptLayout wsAfterSep) */

ASF_TreeAmbs ASF_setTreeAmbsWsAfterSep(ASF_TreeAmbs arg, ASF_OptLayout wsAfterSep)
{
  if (ASF_isTreeAmbsMany(arg)) {
    return (ASF_TreeAmbs)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("TreeAmbs has no WsAfterSep: %t\n", arg);
  return (ASF_TreeAmbs)NULL;
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_setTreeAmbsTail(ASF_TreeAmbs arg, ASF_TreeAmbs tail) */

ASF_TreeAmbs ASF_setTreeAmbsTail(ASF_TreeAmbs arg, ASF_TreeAmbs tail)
{
  if (ASF_isTreeAmbsMany(arg)) {
    return (ASF_TreeAmbs)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("TreeAmbs has no Tail: %t\n", arg);
  return (ASF_TreeAmbs)NULL;
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
/*{{{  inline ATbool ASF_isCHARListEmpty(ASF_CHARList arg) */

inline ATbool ASF_isCHARListEmpty(ASF_CHARList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternCHARListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool ASF_isCHARListSingle(ASF_CHARList arg) */

inline ATbool ASF_isCHARListSingle(ASF_CHARList arg)
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
      last_result = ATmatchTerm((ATerm)arg, ASF_patternCHARListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isCHARListMany(ASF_CHARList arg) */

inline ATbool ASF_isCHARListMany(ASF_CHARList arg)
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
      last_result = ATmatchTerm((ATerm)arg, ASF_patternCHARListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
/*{{{  ATbool ASF_hasCHARListWsAfterHead(ASF_CHARList arg) */

ATbool ASF_hasCHARListWsAfterHead(ASF_CHARList arg)
{
  if (ASF_isCHARListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
  assert(!ASF_isCHARListEmpty(arg) && "getTail on an empty list");
  if (ASF_isCHARListSingle(arg)) {
    return (ASF_CHARList) ASF_makeCHARListEmpty();
  }
  else {
  
    return (ASF_CHARList)ATgetTail((ATermList)arg, 2);
  }
}

/*}}}  */
/*{{{  ASF_CHAR ASF_getCHARListHead(ASF_CHARList arg) */

ASF_CHAR ASF_getCHARListHead(ASF_CHARList arg)
{
  if (ASF_isCHARListSingle(arg)) {
    return (ASF_CHAR)ATgetFirst((ATermList)arg);
  }
  else 
    return (ASF_CHAR)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getCHARListWsAfterHead(ASF_CHARList arg) */

ASF_OptLayout ASF_getCHARListWsAfterHead(ASF_CHARList arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  ASF_CHARList ASF_setCHARListHead(ASF_CHARList arg, ASF_CHAR head) */

ASF_CHARList ASF_setCHARListHead(ASF_CHARList arg, ASF_CHAR head)
{
  if (ASF_isCHARListSingle(arg)) {
    return (ASF_CHARList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (ASF_isCHARListMany(arg)) {
    return (ASF_CHARList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("CHARList has no Head: %t\n", arg);
  return (ASF_CHARList)NULL;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_setCHARListWsAfterHead(ASF_CHARList arg, ASF_OptLayout wsAfterHead) */

ASF_CHARList ASF_setCHARListWsAfterHead(ASF_CHARList arg, ASF_OptLayout wsAfterHead)
{
  if (ASF_isCHARListMany(arg)) {
    return (ASF_CHARList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("CHARList has no WsAfterHead: %t\n", arg);
  return (ASF_CHARList)NULL;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_setCHARListTail(ASF_CHARList arg, ASF_CHARList tail) */

ASF_CHARList ASF_setCHARListTail(ASF_CHARList arg, ASF_CHARList tail)
{
  if (ASF_isCHARListMany(arg)) {
    return (ASF_CHARList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 2);
  }

  ATabort("CHARList has no Tail: %t\n", arg);
  return (ASF_CHARList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFImplies accessors */

/*{{{  ATbool ASF_isValidASFImplies(ASF_ASFImplies arg) */

ATbool ASF_isValidASFImplies(ASF_ASFImplies arg)
{
  if (ASF_isASFImpliesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFImpliesDefault(ASF_ASFImplies arg) */

inline ATbool ASF_isASFImpliesDefault(ASF_ASFImplies arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternASFImpliesDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFImpliesString(ASF_ASFImplies arg) */

ATbool ASF_hasASFImpliesString(ASF_ASFImplies arg)
{
  if (ASF_isASFImpliesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ASF_getASFImpliesString(ASF_ASFImplies arg) */

char* ASF_getASFImpliesString(ASF_ASFImplies arg)
{
  
    return (char*)ASF_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  ASF_ASFImplies ASF_setASFImpliesString(ASF_ASFImplies arg, const char* string) */

ASF_ASFImplies ASF_setASFImpliesString(ASF_ASFImplies arg, const char* string)
{
  if (ASF_isASFImpliesDefault(arg)) {
    return (ASF_ASFImplies)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) ASF_stringToChars(string))), 1), 0), 1);
  }

  ATabort("ASFImplies has no String: %t\n", arg);
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
/*{{{  ATbool ASF_hasASFEquationLhsSymbol(ASF_ASFEquation arg) */

ATbool ASF_hasASFEquationLhsSymbol(ASF_ASFEquation arg)
{
  if (ASF_isASFEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFEquationRhsSymbol(ASF_ASFEquation arg) */

ATbool ASF_hasASFEquationRhsSymbol(ASF_ASFEquation arg)
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
/*{{{  ASF_Symbol ASF_getASFEquationLhsSymbol(ASF_ASFEquation arg) */

ASF_Symbol ASF_getASFEquationLhsSymbol(ASF_ASFEquation arg)
{
  
    return (ASF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getASFEquationRhsSymbol(ASF_ASFEquation arg) */

ASF_Symbol ASF_getASFEquationRhsSymbol(ASF_ASFEquation arg)
{
  
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
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
/*{{{  ASF_ASFEquation ASF_setASFEquationLhsSymbol(ASF_ASFEquation arg, ASF_Symbol lhsSymbol) */

ASF_ASFEquation ASF_setASFEquationLhsSymbol(ASF_ASFEquation arg, ASF_Symbol lhsSymbol)
{
  if (ASF_isASFEquationDefault(arg)) {
    return (ASF_ASFEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) lhsSymbol), 0), 0), 0);
  }

  ATabort("ASFEquation has no LhsSymbol: %t\n", arg);
  return (ASF_ASFEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_setASFEquationRhsSymbol(ASF_ASFEquation arg, ASF_Symbol rhsSymbol) */

ASF_ASFEquation ASF_setASFEquationRhsSymbol(ASF_ASFEquation arg, ASF_Symbol rhsSymbol)
{
  if (ASF_isASFEquationDefault(arg)) {
    return (ASF_ASFEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) rhsSymbol), 4), 0), 0);
  }

  ATabort("ASFEquation has no RhsSymbol: %t\n", arg);
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
/*{{{  ASF_ASFTagId accessors */

/*{{{  ATbool ASF_isValidASFTagId(ASF_ASFTagId arg) */

ATbool ASF_isValidASFTagId(ASF_ASFTagId arg)
{
  if (ASF_isASFTagIdOneChar(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTagIdManyChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFTagIdOneChar(ASF_ASFTagId arg) */

inline ATbool ASF_isASFTagIdOneChar(ASF_ASFTagId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFTagIdOneChar, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFTagIdManyChars(ASF_ASFTagId arg) */

inline ATbool ASF_isASFTagIdManyChars(ASF_ASFTagId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFTagIdManyChars, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTagIdString(ASF_ASFTagId arg) */

ATbool ASF_hasASFTagIdString(ASF_ASFTagId arg)
{
  if (ASF_isASFTagIdOneChar(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTagIdManyChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ASF_getASFTagIdString(ASF_ASFTagId arg) */

char* ASF_getASFTagIdString(ASF_ASFTagId arg)
{
  if (ASF_isASFTagIdOneChar(arg)) {
    return (char*)ASF_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
  }
  else 
    return (char*)ASF_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  ASF_ASFTagId ASF_setASFTagIdString(ASF_ASFTagId arg, const char* string) */

ASF_ASFTagId ASF_setASFTagIdString(ASF_ASFTagId arg, const char* string)
{
  if (ASF_isASFTagIdOneChar(arg)) {
    return (ASF_ASFTagId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) ASF_stringToChars(string))), 1), 0), 1);
  }
  else if (ASF_isASFTagIdManyChars(arg)) {
    return (ASF_ASFTagId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) ASF_stringToChars(string))), 1), 0), 1);
  }

  ATabort("ASFTagId has no String: %t\n", arg);
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
/*{{{  ASF_Start accessors */

/*{{{  ATbool ASF_isValidStart(ASF_Start arg) */

ATbool ASF_isValidStart(ASF_Start arg)
{
  if (ASF_isStartASFTestEquation(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFTag(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFTagId(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFSection(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFModule(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFConditionalEquation(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFEquation(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartTree(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFConditions(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFCondition(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isStartASFTestEquation(ASF_Start arg) */

inline ATbool ASF_isStartASFTestEquation(ASF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternStartASFTestEquation, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isStartASFTag(ASF_Start arg) */

inline ATbool ASF_isStartASFTag(ASF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternStartASFTag, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isStartASFTagId(ASF_Start arg) */

inline ATbool ASF_isStartASFTagId(ASF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternStartASFTagId, NULL, NULL, NULL, NULL);
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
/*{{{  inline ATbool ASF_isStartASFConditionalEquation(ASF_Start arg) */

inline ATbool ASF_isStartASFConditionalEquation(ASF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternStartASFConditionalEquation, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isStartASFEquation(ASF_Start arg) */

inline ATbool ASF_isStartASFEquation(ASF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternStartASFEquation, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isStartASFImplies(ASF_Start arg) */

inline ATbool ASF_isStartASFImplies(ASF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternStartASFImplies, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isStartTree(ASF_Start arg) */

inline ATbool ASF_isStartTree(ASF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternStartTree, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isStartASFConditions(ASF_Start arg) */

inline ATbool ASF_isStartASFConditions(ASF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternStartASFConditions, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isStartASFCondition(ASF_Start arg) */

inline ATbool ASF_isStartASFCondition(ASF_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternStartASFCondition, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasStartWsBefore(ASF_Start arg) */

ATbool ASF_hasStartWsBefore(ASF_Start arg)
{
  if (ASF_isStartASFTestEquation(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFTag(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFTagId(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFSection(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFModule(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFConditionalEquation(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFEquation(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartTree(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFConditions(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFCondition(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartTopASFTestEquation(ASF_Start arg) */

ATbool ASF_hasStartTopASFTestEquation(ASF_Start arg)
{
  if (ASF_isStartASFTestEquation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartWsAfter(ASF_Start arg) */

ATbool ASF_hasStartWsAfter(ASF_Start arg)
{
  if (ASF_isStartASFTestEquation(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFTag(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFTagId(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFSection(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFModule(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFConditionalEquation(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFEquation(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartTree(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFConditions(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFCondition(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartAmbCnt(ASF_Start arg) */

ATbool ASF_hasStartAmbCnt(ASF_Start arg)
{
  if (ASF_isStartASFTestEquation(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFTag(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFTagId(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFSection(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFModule(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFConditionalEquation(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFEquation(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartTree(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFConditions(arg)) {
    return ATtrue;
  }
  else if (ASF_isStartASFCondition(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartTopASFTag(ASF_Start arg) */

ATbool ASF_hasStartTopASFTag(ASF_Start arg)
{
  if (ASF_isStartASFTag(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartTopASFTagId(ASF_Start arg) */

ATbool ASF_hasStartTopASFTagId(ASF_Start arg)
{
  if (ASF_isStartASFTagId(arg)) {
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
/*{{{  ATbool ASF_hasStartTopASFModule(ASF_Start arg) */

ATbool ASF_hasStartTopASFModule(ASF_Start arg)
{
  if (ASF_isStartASFModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartTopASFConditionalEquation(ASF_Start arg) */

ATbool ASF_hasStartTopASFConditionalEquation(ASF_Start arg)
{
  if (ASF_isStartASFConditionalEquation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartTopASFEquation(ASF_Start arg) */

ATbool ASF_hasStartTopASFEquation(ASF_Start arg)
{
  if (ASF_isStartASFEquation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartTopASFImplies(ASF_Start arg) */

ATbool ASF_hasStartTopASFImplies(ASF_Start arg)
{
  if (ASF_isStartASFImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartTopTree(ASF_Start arg) */

ATbool ASF_hasStartTopTree(ASF_Start arg)
{
  if (ASF_isStartTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartTopASFConditions(ASF_Start arg) */

ATbool ASF_hasStartTopASFConditions(ASF_Start arg)
{
  if (ASF_isStartASFConditions(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartTopASFCondition(ASF_Start arg) */

ATbool ASF_hasStartTopASFCondition(ASF_Start arg)
{
  if (ASF_isStartASFCondition(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getStartWsBefore(ASF_Start arg) */

ASF_OptLayout ASF_getStartWsBefore(ASF_Start arg)
{
  if (ASF_isStartASFTestEquation(arg)) {
    return (ASF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (ASF_isStartASFTag(arg)) {
    return (ASF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (ASF_isStartASFTagId(arg)) {
    return (ASF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (ASF_isStartASFSection(arg)) {
    return (ASF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (ASF_isStartASFModule(arg)) {
    return (ASF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (ASF_isStartASFConditionalEquation(arg)) {
    return (ASF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (ASF_isStartASFEquation(arg)) {
    return (ASF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (ASF_isStartASFImplies(arg)) {
    return (ASF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (ASF_isStartTree(arg)) {
    return (ASF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (ASF_isStartASFConditions(arg)) {
    return (ASF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else 
    return (ASF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
}

/*}}}  */
/*{{{  ASF_ASFTestEquation ASF_getStartTopASFTestEquation(ASF_Start arg) */

ASF_ASFTestEquation ASF_getStartTopASFTestEquation(ASF_Start arg)
{
  
    return (ASF_ASFTestEquation)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getStartWsAfter(ASF_Start arg) */

ASF_OptLayout ASF_getStartWsAfter(ASF_Start arg)
{
  if (ASF_isStartASFTestEquation(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (ASF_isStartASFTag(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (ASF_isStartASFTagId(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (ASF_isStartASFSection(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (ASF_isStartASFModule(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (ASF_isStartASFConditionalEquation(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (ASF_isStartASFEquation(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (ASF_isStartASFImplies(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (ASF_isStartTree(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (ASF_isStartASFConditions(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else 
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
}

/*}}}  */
/*{{{  int ASF_getStartAmbCnt(ASF_Start arg) */

int ASF_getStartAmbCnt(ASF_Start arg)
{
  if (ASF_isStartASFTestEquation(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isStartASFTag(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isStartASFTagId(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isStartASFSection(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isStartASFModule(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isStartASFConditionalEquation(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isStartASFEquation(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isStartASFImplies(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isStartTree(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isStartASFConditions(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_getStartTopASFTag(ASF_Start arg) */

ASF_ASFTag ASF_getStartTopASFTag(ASF_Start arg)
{
  
    return (ASF_ASFTag)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFTagId ASF_getStartTopASFTagId(ASF_Start arg) */

ASF_ASFTagId ASF_getStartTopASFTagId(ASF_Start arg)
{
  
    return (ASF_ASFTagId)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFSection ASF_getStartTopASFSection(ASF_Start arg) */

ASF_ASFSection ASF_getStartTopASFSection(ASF_Start arg)
{
  
    return (ASF_ASFSection)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFModule ASF_getStartTopASFModule(ASF_Start arg) */

ASF_ASFModule ASF_getStartTopASFModule(ASF_Start arg)
{
  
    return (ASF_ASFModule)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_getStartTopASFConditionalEquation(ASF_Start arg) */

ASF_ASFConditionalEquation ASF_getStartTopASFConditionalEquation(ASF_Start arg)
{
  
    return (ASF_ASFConditionalEquation)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_getStartTopASFEquation(ASF_Start arg) */

ASF_ASFEquation ASF_getStartTopASFEquation(ASF_Start arg)
{
  
    return (ASF_ASFEquation)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFImplies ASF_getStartTopASFImplies(ASF_Start arg) */

ASF_ASFImplies ASF_getStartTopASFImplies(ASF_Start arg)
{
  
    return (ASF_ASFImplies)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  ASF_Tree ASF_getStartTopTree(ASF_Start arg) */

ASF_Tree ASF_getStartTopTree(ASF_Start arg)
{
  
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFConditions ASF_getStartTopASFConditions(ASF_Start arg) */

ASF_ASFConditions ASF_getStartTopASFConditions(ASF_Start arg)
{
  
    return (ASF_ASFConditions)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_getStartTopASFCondition(ASF_Start arg) */

ASF_ASFCondition ASF_getStartTopASFCondition(ASF_Start arg)
{
  
    return (ASF_ASFCondition)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartWsBefore(ASF_Start arg, ASF_OptLayout wsBefore) */

ASF_Start ASF_setStartWsBefore(ASF_Start arg, ASF_OptLayout wsBefore)
{
  if (ASF_isStartASFTestEquation(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (ASF_isStartASFTag(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (ASF_isStartASFTagId(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (ASF_isStartASFSection(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (ASF_isStartASFModule(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (ASF_isStartASFConditionalEquation(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (ASF_isStartASFEquation(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (ASF_isStartASFImplies(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (ASF_isStartTree(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (ASF_isStartASFConditions(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (ASF_isStartASFCondition(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }

  ATabort("Start has no WsBefore: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartTopASFTestEquation(ASF_Start arg, ASF_ASFTestEquation topASFTestEquation) */

ASF_Start ASF_setStartTopASFTestEquation(ASF_Start arg, ASF_ASFTestEquation topASFTestEquation)
{
  if (ASF_isStartASFTestEquation(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topASFTestEquation), 1), 1), 0);
  }

  ATabort("Start has no TopASFTestEquation: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartWsAfter(ASF_Start arg, ASF_OptLayout wsAfter) */

ASF_Start ASF_setStartWsAfter(ASF_Start arg, ASF_OptLayout wsAfter)
{
  if (ASF_isStartASFTestEquation(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (ASF_isStartASFTag(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (ASF_isStartASFTagId(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (ASF_isStartASFSection(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (ASF_isStartASFModule(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (ASF_isStartASFConditionalEquation(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (ASF_isStartASFEquation(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (ASF_isStartASFImplies(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (ASF_isStartTree(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (ASF_isStartASFConditions(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (ASF_isStartASFCondition(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }

  ATabort("Start has no WsAfter: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartAmbCnt(ASF_Start arg, int ambCnt) */

ASF_Start ASF_setStartAmbCnt(ASF_Start arg, int ambCnt)
{
  if (ASF_isStartASFTestEquation(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (ASF_isStartASFTag(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (ASF_isStartASFTagId(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (ASF_isStartASFSection(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (ASF_isStartASFModule(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (ASF_isStartASFConditionalEquation(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (ASF_isStartASFEquation(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (ASF_isStartASFImplies(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (ASF_isStartTree(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (ASF_isStartASFConditions(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (ASF_isStartASFCondition(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }

  ATabort("Start has no AmbCnt: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartTopASFTag(ASF_Start arg, ASF_ASFTag topASFTag) */

ASF_Start ASF_setStartTopASFTag(ASF_Start arg, ASF_ASFTag topASFTag)
{
  if (ASF_isStartASFTag(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topASFTag), 1), 1), 0);
  }

  ATabort("Start has no TopASFTag: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartTopASFTagId(ASF_Start arg, ASF_ASFTagId topASFTagId) */

ASF_Start ASF_setStartTopASFTagId(ASF_Start arg, ASF_ASFTagId topASFTagId)
{
  if (ASF_isStartASFTagId(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topASFTagId), 1), 1), 0);
  }

  ATabort("Start has no TopASFTagId: %t\n", arg);
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
/*{{{  ASF_Start ASF_setStartTopASFConditionalEquation(ASF_Start arg, ASF_ASFConditionalEquation topASFConditionalEquation) */

ASF_Start ASF_setStartTopASFConditionalEquation(ASF_Start arg, ASF_ASFConditionalEquation topASFConditionalEquation)
{
  if (ASF_isStartASFConditionalEquation(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topASFConditionalEquation), 1), 1), 0);
  }

  ATabort("Start has no TopASFConditionalEquation: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartTopASFEquation(ASF_Start arg, ASF_ASFEquation topASFEquation) */

ASF_Start ASF_setStartTopASFEquation(ASF_Start arg, ASF_ASFEquation topASFEquation)
{
  if (ASF_isStartASFEquation(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topASFEquation), 1), 1), 0);
  }

  ATabort("Start has no TopASFEquation: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartTopASFImplies(ASF_Start arg, ASF_ASFImplies topASFImplies) */

ASF_Start ASF_setStartTopASFImplies(ASF_Start arg, ASF_ASFImplies topASFImplies)
{
  if (ASF_isStartASFImplies(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topASFImplies), 1), 1), 0);
  }

  ATabort("Start has no TopASFImplies: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartTopTree(ASF_Start arg, ASF_Tree topTree) */

ASF_Start ASF_setStartTopTree(ASF_Start arg, ASF_Tree topTree)
{
  if (ASF_isStartTree(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topTree), 1), 1), 0);
  }

  ATabort("Start has no TopTree: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartTopASFConditions(ASF_Start arg, ASF_ASFConditions topASFConditions) */

ASF_Start ASF_setStartTopASFConditions(ASF_Start arg, ASF_ASFConditions topASFConditions)
{
  if (ASF_isStartASFConditions(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topASFConditions), 1), 1), 0);
  }

  ATabort("Start has no TopASFConditions: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartTopASFCondition(ASF_Start arg, ASF_ASFCondition topASFCondition) */

ASF_Start ASF_setStartTopASFCondition(ASF_Start arg, ASF_ASFCondition topASFCondition)
{
  if (ASF_isStartASFCondition(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topASFCondition), 1), 1), 0);
  }

  ATabort("Start has no TopASFCondition: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */

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
/*{{{  ATbool ASF_hasOptLayoutString(ASF_OptLayout arg) */

ATbool ASF_hasOptLayoutString(ASF_OptLayout arg)
{
  if (ASF_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ASF_getOptLayoutString(ASF_OptLayout arg) */

char* ASF_getOptLayoutString(ASF_OptLayout arg)
{
  
    return (char*)ASF_charsToString((ATerm)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_setOptLayoutString(ASF_OptLayout arg, const char* string) */

ASF_OptLayout ASF_setOptLayoutString(ASF_OptLayout arg, const char* string)
{
  if (ASF_isOptLayoutPresent(arg)) {
    return (ASF_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) ((ATerm) ASF_stringToChars(string))), 1);
  }

  ATabort("OptLayout has no String: %t\n", arg);
  return (ASF_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  ASF_Production ASF_visitProduction(ASF_Production arg, char* (*acceptFormalName)(char*), ASF_Symbol (*acceptSymbol)(ASF_Symbol)) */

ASF_Production ASF_visitProduction(ASF_Production arg, char* (*acceptFormalName)(char*), ASF_Symbol (*acceptSymbol)(ASF_Symbol))
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
/*{{{  ASF_CHAR ASF_visitCHAR(ASF_CHAR arg, char* (*acceptString)(char*)) */

ASF_CHAR ASF_visitCHAR(ASF_CHAR arg, char* (*acceptString)(char*))
{
  if (ASF_isCHARDefault(arg)) {
    return ASF_makeCHARDefault(
        acceptString ? acceptString(ASF_getCHARString(arg)) : ASF_getCHARString(arg));
  }
  ATabort("not a CHAR: %t\n", arg);
  return (ASF_CHAR)NULL;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_visitASFCondition(ASF_ASFCondition arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquals)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterUnequal)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquality)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterMatch)(ASF_OptLayout)) */

ASF_ASFCondition ASF_visitASFCondition(ASF_ASFCondition arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquals)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterUnequal)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquality)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterMatch)(ASF_OptLayout))
{
  if (ASF_isASFConditionPositive(arg)) {
    return ASF_makeASFConditionPositive(
        acceptLhsSymbol ? acceptLhsSymbol(ASF_getASFConditionLhsSymbol(arg)) : ASF_getASFConditionLhsSymbol(arg),
        acceptRhsSymbol ? acceptRhsSymbol(ASF_getASFConditionRhsSymbol(arg)) : ASF_getASFConditionRhsSymbol(arg),
        acceptLhs ? acceptLhs(ASF_getASFConditionLhs(arg)) : ASF_getASFConditionLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getASFConditionWsAfterLhs(arg)) : ASF_getASFConditionWsAfterLhs(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(ASF_getASFConditionWsAfterEquals(arg)) : ASF_getASFConditionWsAfterEquals(arg),
        acceptRhs ? acceptRhs(ASF_getASFConditionRhs(arg)) : ASF_getASFConditionRhs(arg));
  }
  if (ASF_isASFConditionNegative(arg)) {
    return ASF_makeASFConditionNegative(
        acceptLhsSymbol ? acceptLhsSymbol(ASF_getASFConditionLhsSymbol(arg)) : ASF_getASFConditionLhsSymbol(arg),
        acceptRhsSymbol ? acceptRhsSymbol(ASF_getASFConditionRhsSymbol(arg)) : ASF_getASFConditionRhsSymbol(arg),
        acceptLhs ? acceptLhs(ASF_getASFConditionLhs(arg)) : ASF_getASFConditionLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getASFConditionWsAfterLhs(arg)) : ASF_getASFConditionWsAfterLhs(arg),
        acceptWsAfterUnequal ? acceptWsAfterUnequal(ASF_getASFConditionWsAfterUnequal(arg)) : ASF_getASFConditionWsAfterUnequal(arg),
        acceptRhs ? acceptRhs(ASF_getASFConditionRhs(arg)) : ASF_getASFConditionRhs(arg));
  }
  if (ASF_isASFConditionEquality(arg)) {
    return ASF_makeASFConditionEquality(
        acceptLhsSymbol ? acceptLhsSymbol(ASF_getASFConditionLhsSymbol(arg)) : ASF_getASFConditionLhsSymbol(arg),
        acceptRhsSymbol ? acceptRhsSymbol(ASF_getASFConditionRhsSymbol(arg)) : ASF_getASFConditionRhsSymbol(arg),
        acceptLhs ? acceptLhs(ASF_getASFConditionLhs(arg)) : ASF_getASFConditionLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getASFConditionWsAfterLhs(arg)) : ASF_getASFConditionWsAfterLhs(arg),
        acceptWsAfterEquality ? acceptWsAfterEquality(ASF_getASFConditionWsAfterEquality(arg)) : ASF_getASFConditionWsAfterEquality(arg),
        acceptRhs ? acceptRhs(ASF_getASFConditionRhs(arg)) : ASF_getASFConditionRhs(arg));
  }
  if (ASF_isASFConditionMatch(arg)) {
    return ASF_makeASFConditionMatch(
        acceptLhsSymbol ? acceptLhsSymbol(ASF_getASFConditionLhsSymbol(arg)) : ASF_getASFConditionLhsSymbol(arg),
        acceptRhsSymbol ? acceptRhsSymbol(ASF_getASFConditionRhsSymbol(arg)) : ASF_getASFConditionRhsSymbol(arg),
        acceptLhs ? acceptLhs(ASF_getASFConditionLhs(arg)) : ASF_getASFConditionLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getASFConditionWsAfterLhs(arg)) : ASF_getASFConditionWsAfterLhs(arg),
        acceptWsAfterMatch ? acceptWsAfterMatch(ASF_getASFConditionWsAfterMatch(arg)) : ASF_getASFConditionWsAfterMatch(arg),
        acceptRhs ? acceptRhs(ASF_getASFConditionRhs(arg)) : ASF_getASFConditionRhs(arg));
  }
  if (ASF_isASFConditionNoMatch(arg)) {
    return ASF_makeASFConditionNoMatch(
        acceptLhsSymbol ? acceptLhsSymbol(ASF_getASFConditionLhsSymbol(arg)) : ASF_getASFConditionLhsSymbol(arg),
        acceptRhsSymbol ? acceptRhsSymbol(ASF_getASFConditionRhsSymbol(arg)) : ASF_getASFConditionRhsSymbol(arg),
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
/*{{{  ASF_Tree ASF_visitTree(ASF_Tree arg, ASF_Symbol (*acceptAmb)(ASF_Symbol), ASF_Symbol (*acceptSymbol)(ASF_Symbol), ASF_OptLayout (*acceptWsAfterAmb)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterParenOpen)(ASF_OptLayout), ASF_Symbol (*acceptListSymbol)(ASF_Symbol), ASF_TreeAmbs (*acceptAmbs)(ASF_TreeAmbs), ASF_OptLayout (*acceptWsAfterAmbs)(ASF_OptLayout), char* (*acceptFormalName)(char*), ASF_OptLayout (*acceptWsAfterName)(ASF_OptLayout), ASF_CHARList (*acceptList)(ASF_CHARList), ASF_OptLayout (*acceptWsAfterList)(ASF_OptLayout)) */

ASF_Tree ASF_visitTree(ASF_Tree arg, ASF_Symbol (*acceptAmb)(ASF_Symbol), ASF_Symbol (*acceptSymbol)(ASF_Symbol), ASF_OptLayout (*acceptWsAfterAmb)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterParenOpen)(ASF_OptLayout), ASF_Symbol (*acceptListSymbol)(ASF_Symbol), ASF_TreeAmbs (*acceptAmbs)(ASF_TreeAmbs), ASF_OptLayout (*acceptWsAfterAmbs)(ASF_OptLayout), char* (*acceptFormalName)(char*), ASF_OptLayout (*acceptWsAfterName)(ASF_OptLayout), ASF_CHARList (*acceptList)(ASF_CHARList), ASF_OptLayout (*acceptWsAfterList)(ASF_OptLayout))
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return ASF_makeTreeAmbiguityConstructor(
        acceptAmb ? acceptAmb(ASF_getTreeAmb(arg)) : ASF_getTreeAmb(arg),
        acceptSymbol ? acceptSymbol(ASF_getTreeSymbol(arg)) : ASF_getTreeSymbol(arg),
        acceptWsAfterAmb ? acceptWsAfterAmb(ASF_getTreeWsAfterAmb(arg)) : ASF_getTreeWsAfterAmb(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(ASF_getTreeWsAfterParenOpen(arg)) : ASF_getTreeWsAfterParenOpen(arg),
        acceptListSymbol ? acceptListSymbol(ASF_getTreeListSymbol(arg)) : ASF_getTreeListSymbol(arg),
        acceptAmbs ? acceptAmbs(ASF_getTreeAmbs(arg)) : ASF_getTreeAmbs(arg),
        acceptWsAfterAmbs ? acceptWsAfterAmbs(ASF_getTreeWsAfterAmbs(arg)) : ASF_getTreeWsAfterAmbs(arg));
  }
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ASF_makeTreeLexicalConstructor(
        acceptFormalName ? acceptFormalName(ASF_getTreeFormalName(arg)) : ASF_getTreeFormalName(arg),
        acceptSymbol ? acceptSymbol(ASF_getTreeSymbol(arg)) : ASF_getTreeSymbol(arg),
        ASF_visitTree(ASF_getTreeName(arg), acceptAmb, acceptSymbol, acceptWsAfterAmb, acceptWsAfterParenOpen, acceptListSymbol, acceptAmbs, acceptWsAfterAmbs, acceptFormalName, acceptWsAfterName, acceptList, acceptWsAfterList),
        acceptWsAfterName ? acceptWsAfterName(ASF_getTreeWsAfterName(arg)) : ASF_getTreeWsAfterName(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(ASF_getTreeWsAfterParenOpen(arg)) : ASF_getTreeWsAfterParenOpen(arg),
        acceptList ? acceptList(ASF_getTreeList(arg)) : ASF_getTreeList(arg),
        acceptWsAfterList ? acceptWsAfterList(ASF_getTreeWsAfterList(arg)) : ASF_getTreeWsAfterList(arg));
  }
  ATabort("not a Tree: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_visitTreeAmbs(ASF_TreeAmbs arg, ASF_Tree (*acceptHead)(ASF_Tree), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterSep)(ASF_OptLayout)) */

ASF_TreeAmbs ASF_visitTreeAmbs(ASF_TreeAmbs arg, ASF_Tree (*acceptHead)(ASF_Tree), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterSep)(ASF_OptLayout))
{
  if (ASF_isTreeAmbsEmpty(arg)) {
    return ASF_makeTreeAmbsEmpty();
  }
  if (ASF_isTreeAmbsSingle(arg)) {
    return ASF_makeTreeAmbsSingle(
        acceptHead ? acceptHead(ASF_getTreeAmbsHead(arg)) : ASF_getTreeAmbsHead(arg));
  }
  if (ASF_isTreeAmbsMany(arg)) {
    return ASF_makeTreeAmbsMany(
        acceptHead ? acceptHead(ASF_getTreeAmbsHead(arg)) : ASF_getTreeAmbsHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(ASF_getTreeAmbsWsAfterHead(arg)) : ASF_getTreeAmbsWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(ASF_getTreeAmbsWsAfterSep(arg)) : ASF_getTreeAmbsWsAfterSep(arg),
        ASF_visitTreeAmbs(ASF_getTreeAmbsTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a TreeAmbs: %t\n", arg);
  return (ASF_TreeAmbs)NULL;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_visitCHARList(ASF_CHARList arg, ASF_CHAR (*acceptHead)(ASF_CHAR), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout)) */

ASF_CHARList ASF_visitCHARList(ASF_CHARList arg, ASF_CHAR (*acceptHead)(ASF_CHAR), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout))
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
        acceptWsAfterHead ? acceptWsAfterHead(ASF_getCHARListWsAfterHead(arg)) : ASF_getCHARListWsAfterHead(arg),
        ASF_visitCHARList(ASF_getCHARListTail(arg), acceptHead, acceptWsAfterHead));
  }
  ATabort("not a CHARList: %t\n", arg);
  return (ASF_CHARList)NULL;
}

/*}}}  */
/*{{{  ASF_ASFImplies ASF_visitASFImplies(ASF_ASFImplies arg, char* (*acceptString)(char*)) */

ASF_ASFImplies ASF_visitASFImplies(ASF_ASFImplies arg, char* (*acceptString)(char*))
{
  if (ASF_isASFImpliesDefault(arg)) {
    return ASF_makeASFImpliesDefault(
        acceptString ? acceptString(ASF_getASFImpliesString(arg)) : ASF_getASFImpliesString(arg));
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
/*{{{  ASF_ASFEquation ASF_visitASFEquation(ASF_ASFEquation arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquals)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree)) */

ASF_ASFEquation ASF_visitASFEquation(ASF_ASFEquation arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquals)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree))
{
  if (ASF_isASFEquationDefault(arg)) {
    return ASF_makeASFEquationDefault(
        acceptLhsSymbol ? acceptLhsSymbol(ASF_getASFEquationLhsSymbol(arg)) : ASF_getASFEquationLhsSymbol(arg),
        acceptRhsSymbol ? acceptRhsSymbol(ASF_getASFEquationRhsSymbol(arg)) : ASF_getASFEquationRhsSymbol(arg),
        acceptLhs ? acceptLhs(ASF_getASFEquationLhs(arg)) : ASF_getASFEquationLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getASFEquationWsAfterLhs(arg)) : ASF_getASFEquationWsAfterLhs(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(ASF_getASFEquationWsAfterEquals(arg)) : ASF_getASFEquationWsAfterEquals(arg),
        acceptRhs ? acceptRhs(ASF_getASFEquationRhs(arg)) : ASF_getASFEquationRhs(arg));
  }
  ATabort("not a ASFEquation: %t\n", arg);
  return (ASF_ASFEquation)NULL;
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
/*{{{  ASF_ASFTagId ASF_visitASFTagId(ASF_ASFTagId arg, char* (*acceptString)(char*)) */

ASF_ASFTagId ASF_visitASFTagId(ASF_ASFTagId arg, char* (*acceptString)(char*))
{
  if (ASF_isASFTagIdOneChar(arg)) {
    return ASF_makeASFTagIdOneChar(
        acceptString ? acceptString(ASF_getASFTagIdString(arg)) : ASF_getASFTagIdString(arg));
  }
  if (ASF_isASFTagIdManyChars(arg)) {
    return ASF_makeASFTagIdManyChars(
        acceptString ? acceptString(ASF_getASFTagIdString(arg)) : ASF_getASFTagIdString(arg));
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
/*{{{  ASF_Start ASF_visitStart(ASF_Start arg, ASF_OptLayout (*acceptWsBefore)(ASF_OptLayout), ASF_ASFTestEquation (*acceptTopASFTestEquation)(ASF_ASFTestEquation), ASF_OptLayout (*acceptWsAfter)(ASF_OptLayout), int (*acceptAmbCnt)(int), ASF_ASFTag (*acceptTopASFTag)(ASF_ASFTag), ASF_ASFTagId (*acceptTopASFTagId)(ASF_ASFTagId), ASF_ASFSection (*acceptTopASFSection)(ASF_ASFSection), ASF_ASFModule (*acceptTopASFModule)(ASF_ASFModule), ASF_ASFConditionalEquation (*acceptTopASFConditionalEquation)(ASF_ASFConditionalEquation), ASF_ASFEquation (*acceptTopASFEquation)(ASF_ASFEquation), ASF_ASFImplies (*acceptTopASFImplies)(ASF_ASFImplies), ASF_Tree (*acceptTopTree)(ASF_Tree), ASF_ASFConditions (*acceptTopASFConditions)(ASF_ASFConditions), ASF_ASFCondition (*acceptTopASFCondition)(ASF_ASFCondition)) */

ASF_Start ASF_visitStart(ASF_Start arg, ASF_OptLayout (*acceptWsBefore)(ASF_OptLayout), ASF_ASFTestEquation (*acceptTopASFTestEquation)(ASF_ASFTestEquation), ASF_OptLayout (*acceptWsAfter)(ASF_OptLayout), int (*acceptAmbCnt)(int), ASF_ASFTag (*acceptTopASFTag)(ASF_ASFTag), ASF_ASFTagId (*acceptTopASFTagId)(ASF_ASFTagId), ASF_ASFSection (*acceptTopASFSection)(ASF_ASFSection), ASF_ASFModule (*acceptTopASFModule)(ASF_ASFModule), ASF_ASFConditionalEquation (*acceptTopASFConditionalEquation)(ASF_ASFConditionalEquation), ASF_ASFEquation (*acceptTopASFEquation)(ASF_ASFEquation), ASF_ASFImplies (*acceptTopASFImplies)(ASF_ASFImplies), ASF_Tree (*acceptTopTree)(ASF_Tree), ASF_ASFConditions (*acceptTopASFConditions)(ASF_ASFConditions), ASF_ASFCondition (*acceptTopASFCondition)(ASF_ASFCondition))
{
  if (ASF_isStartASFTestEquation(arg)) {
    return ASF_makeStartASFTestEquation(
        acceptWsBefore ? acceptWsBefore(ASF_getStartWsBefore(arg)) : ASF_getStartWsBefore(arg),
        acceptTopASFTestEquation ? acceptTopASFTestEquation(ASF_getStartTopASFTestEquation(arg)) : ASF_getStartTopASFTestEquation(arg),
        acceptWsAfter ? acceptWsAfter(ASF_getStartWsAfter(arg)) : ASF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(ASF_getStartAmbCnt(arg)) : ASF_getStartAmbCnt(arg));
  }
  if (ASF_isStartASFTag(arg)) {
    return ASF_makeStartASFTag(
        acceptWsBefore ? acceptWsBefore(ASF_getStartWsBefore(arg)) : ASF_getStartWsBefore(arg),
        acceptTopASFTag ? acceptTopASFTag(ASF_getStartTopASFTag(arg)) : ASF_getStartTopASFTag(arg),
        acceptWsAfter ? acceptWsAfter(ASF_getStartWsAfter(arg)) : ASF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(ASF_getStartAmbCnt(arg)) : ASF_getStartAmbCnt(arg));
  }
  if (ASF_isStartASFTagId(arg)) {
    return ASF_makeStartASFTagId(
        acceptWsBefore ? acceptWsBefore(ASF_getStartWsBefore(arg)) : ASF_getStartWsBefore(arg),
        acceptTopASFTagId ? acceptTopASFTagId(ASF_getStartTopASFTagId(arg)) : ASF_getStartTopASFTagId(arg),
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
  if (ASF_isStartASFModule(arg)) {
    return ASF_makeStartASFModule(
        acceptWsBefore ? acceptWsBefore(ASF_getStartWsBefore(arg)) : ASF_getStartWsBefore(arg),
        acceptTopASFModule ? acceptTopASFModule(ASF_getStartTopASFModule(arg)) : ASF_getStartTopASFModule(arg),
        acceptWsAfter ? acceptWsAfter(ASF_getStartWsAfter(arg)) : ASF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(ASF_getStartAmbCnt(arg)) : ASF_getStartAmbCnt(arg));
  }
  if (ASF_isStartASFConditionalEquation(arg)) {
    return ASF_makeStartASFConditionalEquation(
        acceptWsBefore ? acceptWsBefore(ASF_getStartWsBefore(arg)) : ASF_getStartWsBefore(arg),
        acceptTopASFConditionalEquation ? acceptTopASFConditionalEquation(ASF_getStartTopASFConditionalEquation(arg)) : ASF_getStartTopASFConditionalEquation(arg),
        acceptWsAfter ? acceptWsAfter(ASF_getStartWsAfter(arg)) : ASF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(ASF_getStartAmbCnt(arg)) : ASF_getStartAmbCnt(arg));
  }
  if (ASF_isStartASFEquation(arg)) {
    return ASF_makeStartASFEquation(
        acceptWsBefore ? acceptWsBefore(ASF_getStartWsBefore(arg)) : ASF_getStartWsBefore(arg),
        acceptTopASFEquation ? acceptTopASFEquation(ASF_getStartTopASFEquation(arg)) : ASF_getStartTopASFEquation(arg),
        acceptWsAfter ? acceptWsAfter(ASF_getStartWsAfter(arg)) : ASF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(ASF_getStartAmbCnt(arg)) : ASF_getStartAmbCnt(arg));
  }
  if (ASF_isStartASFImplies(arg)) {
    return ASF_makeStartASFImplies(
        acceptWsBefore ? acceptWsBefore(ASF_getStartWsBefore(arg)) : ASF_getStartWsBefore(arg),
        acceptTopASFImplies ? acceptTopASFImplies(ASF_getStartTopASFImplies(arg)) : ASF_getStartTopASFImplies(arg),
        acceptWsAfter ? acceptWsAfter(ASF_getStartWsAfter(arg)) : ASF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(ASF_getStartAmbCnt(arg)) : ASF_getStartAmbCnt(arg));
  }
  if (ASF_isStartTree(arg)) {
    return ASF_makeStartTree(
        acceptWsBefore ? acceptWsBefore(ASF_getStartWsBefore(arg)) : ASF_getStartWsBefore(arg),
        acceptTopTree ? acceptTopTree(ASF_getStartTopTree(arg)) : ASF_getStartTopTree(arg),
        acceptWsAfter ? acceptWsAfter(ASF_getStartWsAfter(arg)) : ASF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(ASF_getStartAmbCnt(arg)) : ASF_getStartAmbCnt(arg));
  }
  if (ASF_isStartASFConditions(arg)) {
    return ASF_makeStartASFConditions(
        acceptWsBefore ? acceptWsBefore(ASF_getStartWsBefore(arg)) : ASF_getStartWsBefore(arg),
        acceptTopASFConditions ? acceptTopASFConditions(ASF_getStartTopASFConditions(arg)) : ASF_getStartTopASFConditions(arg),
        acceptWsAfter ? acceptWsAfter(ASF_getStartWsAfter(arg)) : ASF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(ASF_getStartAmbCnt(arg)) : ASF_getStartAmbCnt(arg));
  }
  if (ASF_isStartASFCondition(arg)) {
    return ASF_makeStartASFCondition(
        acceptWsBefore ? acceptWsBefore(ASF_getStartWsBefore(arg)) : ASF_getStartWsBefore(arg),
        acceptTopASFCondition ? acceptTopASFCondition(ASF_getStartTopASFCondition(arg)) : ASF_getStartTopASFCondition(arg),
        acceptWsAfter ? acceptWsAfter(ASF_getStartWsAfter(arg)) : ASF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(ASF_getStartAmbCnt(arg)) : ASF_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_visitOptLayout(ASF_OptLayout arg, char* (*acceptString)(char*)) */

ASF_OptLayout ASF_visitOptLayout(ASF_OptLayout arg, char* (*acceptString)(char*))
{
  if (ASF_isOptLayoutAbsent(arg)) {
    return ASF_makeOptLayoutAbsent();
  }
  if (ASF_isOptLayoutPresent(arg)) {
    return ASF_makeOptLayoutPresent(
        acceptString ? acceptString(ASF_getOptLayoutString(arg)) : ASF_getOptLayoutString(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (ASF_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
