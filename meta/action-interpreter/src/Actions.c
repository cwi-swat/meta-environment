#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Actions.h"

/*{{{  conversion functions */

ATerm AC_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

char *AC_charsToString(ATerm arg)
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

typedef struct ATerm _AC_Script;
typedef struct ATerm _AC_Actions;
typedef struct ATerm _AC_Action;
typedef struct ATerm _AC_Signature;
typedef struct ATerm _AC_Descriptions;
typedef struct ATerm _AC_Description;
typedef struct ATerm _AC_Args;
typedef struct ATerm _AC_Arg;
typedef struct ATerm _AC_Message;
typedef struct ATerm _AC_Stack;
typedef struct ATerm _AC_Item;

/*}}}  */

/*{{{  void AC_initActionsApi(void) */

void AC_initActionsApi(void)
{
  init_Actions_dict();
}

/*}}}  */

/*{{{  protect functions */

void AC_protectScript(AC_Script *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void AC_protectActions(AC_Actions *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void AC_protectAction(AC_Action *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void AC_protectSignature(AC_Signature *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void AC_protectDescriptions(AC_Descriptions *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void AC_protectDescription(AC_Description *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void AC_protectArgs(AC_Args *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void AC_protectArg(AC_Arg *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void AC_protectMessage(AC_Message *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void AC_protectStack(AC_Stack *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void AC_protectItem(AC_Item *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  AC_Script AC_ScriptFromTerm(ATerm t) */

AC_Script AC_ScriptFromTerm(ATerm t)
{
  return (AC_Script)t;
}

/*}}}  */
/*{{{  ATerm AC_ScriptToTerm(AC_Script arg) */

ATerm AC_ScriptToTerm(AC_Script arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  AC_Actions AC_ActionsFromTerm(ATerm t) */

AC_Actions AC_ActionsFromTerm(ATerm t)
{
  return (AC_Actions)t;
}

/*}}}  */
/*{{{  ATerm AC_ActionsToTerm(AC_Actions arg) */

ATerm AC_ActionsToTerm(AC_Actions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  AC_Action AC_ActionFromTerm(ATerm t) */

AC_Action AC_ActionFromTerm(ATerm t)
{
  return (AC_Action)t;
}

/*}}}  */
/*{{{  ATerm AC_ActionToTerm(AC_Action arg) */

ATerm AC_ActionToTerm(AC_Action arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  AC_Signature AC_SignatureFromTerm(ATerm t) */

AC_Signature AC_SignatureFromTerm(ATerm t)
{
  return (AC_Signature)t;
}

/*}}}  */
/*{{{  ATerm AC_SignatureToTerm(AC_Signature arg) */

ATerm AC_SignatureToTerm(AC_Signature arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  AC_Descriptions AC_DescriptionsFromTerm(ATerm t) */

AC_Descriptions AC_DescriptionsFromTerm(ATerm t)
{
  return (AC_Descriptions)t;
}

/*}}}  */
/*{{{  ATerm AC_DescriptionsToTerm(AC_Descriptions arg) */

ATerm AC_DescriptionsToTerm(AC_Descriptions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  AC_Description AC_DescriptionFromTerm(ATerm t) */

AC_Description AC_DescriptionFromTerm(ATerm t)
{
  return (AC_Description)t;
}

/*}}}  */
/*{{{  ATerm AC_DescriptionToTerm(AC_Description arg) */

ATerm AC_DescriptionToTerm(AC_Description arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  AC_Args AC_ArgsFromTerm(ATerm t) */

AC_Args AC_ArgsFromTerm(ATerm t)
{
  return (AC_Args)t;
}

/*}}}  */
/*{{{  ATerm AC_ArgsToTerm(AC_Args arg) */

ATerm AC_ArgsToTerm(AC_Args arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  AC_Arg AC_ArgFromTerm(ATerm t) */

AC_Arg AC_ArgFromTerm(ATerm t)
{
  return (AC_Arg)t;
}

/*}}}  */
/*{{{  ATerm AC_ArgToTerm(AC_Arg arg) */

ATerm AC_ArgToTerm(AC_Arg arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  AC_Message AC_MessageFromTerm(ATerm t) */

AC_Message AC_MessageFromTerm(ATerm t)
{
  return (AC_Message)t;
}

/*}}}  */
/*{{{  ATerm AC_MessageToTerm(AC_Message arg) */

ATerm AC_MessageToTerm(AC_Message arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  AC_Stack AC_StackFromTerm(ATerm t) */

AC_Stack AC_StackFromTerm(ATerm t)
{
  return (AC_Stack)t;
}

/*}}}  */
/*{{{  ATerm AC_StackToTerm(AC_Stack arg) */

ATerm AC_StackToTerm(AC_Stack arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  AC_Item AC_ItemFromTerm(ATerm t) */

AC_Item AC_ItemFromTerm(ATerm t)
{
  return (AC_Item)t;
}

/*}}}  */
/*{{{  ATerm AC_ItemToTerm(AC_Item arg) */

ATerm AC_ItemToTerm(AC_Item arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int AC_getActionsLength (AC_Actions arg) {
  return ATgetLength((ATermList) arg);
}
AC_Actions AC_reverseActions(AC_Actions arg) {
  return (AC_Actions) ATreverse((ATermList) arg);
}
AC_Actions AC_appendActions(AC_Actions arg, AC_Action elem) {
  return (AC_Actions) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
AC_Actions AC_concatActions(AC_Actions arg0, AC_Actions arg1) {
  return (AC_Actions) ATconcat((ATermList) arg0, (ATermList) arg1);
}
AC_Actions AC_sliceActions(AC_Actions arg, int start, int end) {
  return (AC_Actions) ATgetSlice((ATermList) arg, start, end);
}
AC_Action AC_getActionsActionAt(AC_Actions arg, int index) {
 return (AC_Action)ATelementAt((ATermList) arg,index);
}
AC_Actions AC_replaceActionsActionAt(AC_Actions arg, AC_Action elem, int index) {
 return (AC_Actions) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
AC_Actions AC_makeActions2(AC_Action elem1, AC_Action elem2) {
  return (AC_Actions) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
AC_Actions AC_makeActions3(AC_Action elem1, AC_Action elem2, AC_Action elem3) {
  return (AC_Actions) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
AC_Actions AC_makeActions4(AC_Action elem1, AC_Action elem2, AC_Action elem3, AC_Action elem4) {
  return (AC_Actions) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
AC_Actions AC_makeActions5(AC_Action elem1, AC_Action elem2, AC_Action elem3, AC_Action elem4, AC_Action elem5) {
  return (AC_Actions) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
AC_Actions AC_makeActions6(AC_Action elem1, AC_Action elem2, AC_Action elem3, AC_Action elem4, AC_Action elem5, AC_Action elem6) {
  return (AC_Actions) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int AC_getDescriptionsLength (AC_Descriptions arg) {
  return ATgetLength((ATermList) arg);
}
AC_Descriptions AC_reverseDescriptions(AC_Descriptions arg) {
  return (AC_Descriptions) ATreverse((ATermList) arg);
}
AC_Descriptions AC_appendDescriptions(AC_Descriptions arg, AC_Description elem) {
  return (AC_Descriptions) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
AC_Descriptions AC_concatDescriptions(AC_Descriptions arg0, AC_Descriptions arg1) {
  return (AC_Descriptions) ATconcat((ATermList) arg0, (ATermList) arg1);
}
AC_Descriptions AC_sliceDescriptions(AC_Descriptions arg, int start, int end) {
  return (AC_Descriptions) ATgetSlice((ATermList) arg, start, end);
}
AC_Description AC_getDescriptionsDescriptionAt(AC_Descriptions arg, int index) {
 return (AC_Description)ATelementAt((ATermList) arg,index);
}
AC_Descriptions AC_replaceDescriptionsDescriptionAt(AC_Descriptions arg, AC_Description elem, int index) {
 return (AC_Descriptions) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
AC_Descriptions AC_makeDescriptions2(AC_Description elem1, AC_Description elem2) {
  return (AC_Descriptions) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
AC_Descriptions AC_makeDescriptions3(AC_Description elem1, AC_Description elem2, AC_Description elem3) {
  return (AC_Descriptions) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
AC_Descriptions AC_makeDescriptions4(AC_Description elem1, AC_Description elem2, AC_Description elem3, AC_Description elem4) {
  return (AC_Descriptions) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
AC_Descriptions AC_makeDescriptions5(AC_Description elem1, AC_Description elem2, AC_Description elem3, AC_Description elem4, AC_Description elem5) {
  return (AC_Descriptions) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
AC_Descriptions AC_makeDescriptions6(AC_Description elem1, AC_Description elem2, AC_Description elem3, AC_Description elem4, AC_Description elem5, AC_Description elem6) {
  return (AC_Descriptions) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int AC_getArgsLength (AC_Args arg) {
  return ATgetLength((ATermList) arg);
}
AC_Args AC_reverseArgs(AC_Args arg) {
  return (AC_Args) ATreverse((ATermList) arg);
}
AC_Args AC_appendArgs(AC_Args arg, AC_Arg elem) {
  return (AC_Args) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
AC_Args AC_concatArgs(AC_Args arg0, AC_Args arg1) {
  return (AC_Args) ATconcat((ATermList) arg0, (ATermList) arg1);
}
AC_Args AC_sliceArgs(AC_Args arg, int start, int end) {
  return (AC_Args) ATgetSlice((ATermList) arg, start, end);
}
AC_Arg AC_getArgsArgAt(AC_Args arg, int index) {
 return (AC_Arg)ATelementAt((ATermList) arg,index);
}
AC_Args AC_replaceArgsArgAt(AC_Args arg, AC_Arg elem, int index) {
 return (AC_Args) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
AC_Args AC_makeArgs2(AC_Arg elem1, AC_Arg elem2) {
  return (AC_Args) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
AC_Args AC_makeArgs3(AC_Arg elem1, AC_Arg elem2, AC_Arg elem3) {
  return (AC_Args) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
AC_Args AC_makeArgs4(AC_Arg elem1, AC_Arg elem2, AC_Arg elem3, AC_Arg elem4) {
  return (AC_Args) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
AC_Args AC_makeArgs5(AC_Arg elem1, AC_Arg elem2, AC_Arg elem3, AC_Arg elem4, AC_Arg elem5) {
  return (AC_Args) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
AC_Args AC_makeArgs6(AC_Arg elem1, AC_Arg elem2, AC_Arg elem3, AC_Arg elem4, AC_Arg elem5, AC_Arg elem6) {
  return (AC_Args) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int AC_getStackLength (AC_Stack arg) {
  return ATgetLength((ATermList) arg);
}
AC_Stack AC_reverseStack(AC_Stack arg) {
  return (AC_Stack) ATreverse((ATermList) arg);
}
AC_Stack AC_appendStack(AC_Stack arg, AC_Item elem) {
  return (AC_Stack) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
AC_Stack AC_concatStack(AC_Stack arg0, AC_Stack arg1) {
  return (AC_Stack) ATconcat((ATermList) arg0, (ATermList) arg1);
}
AC_Stack AC_sliceStack(AC_Stack arg, int start, int end) {
  return (AC_Stack) ATgetSlice((ATermList) arg, start, end);
}
AC_Item AC_getStackItemAt(AC_Stack arg, int index) {
 return (AC_Item)ATelementAt((ATermList) arg,index);
}
AC_Stack AC_replaceStackItemAt(AC_Stack arg, AC_Item elem, int index) {
 return (AC_Stack) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
AC_Stack AC_makeStack2(AC_Item elem1, AC_Item elem2) {
  return (AC_Stack) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
AC_Stack AC_makeStack3(AC_Item elem1, AC_Item elem2, AC_Item elem3) {
  return (AC_Stack) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
AC_Stack AC_makeStack4(AC_Item elem1, AC_Item elem2, AC_Item elem3, AC_Item elem4) {
  return (AC_Stack) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
AC_Stack AC_makeStack5(AC_Item elem1, AC_Item elem2, AC_Item elem3, AC_Item elem4, AC_Item elem5) {
  return (AC_Stack) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
AC_Stack AC_makeStack6(AC_Item elem1, AC_Item elem2, AC_Item elem3, AC_Item elem4, AC_Item elem5, AC_Item elem6) {
  return (AC_Stack) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  AC_Script AC_makeScriptList(AC_Actions list) */

AC_Script AC_makeScriptList(AC_Actions list)
{
  return (AC_Script)(ATerm) list;
}

/*}}}  */
/*{{{  AC_Actions AC_makeActionsEmpty(void) */

AC_Actions AC_makeActionsEmpty(void)
{
  return (AC_Actions)(ATerm)ATempty;
}

/*}}}  */
/*{{{  AC_Actions AC_makeActionsSingle(AC_Action head) */

AC_Actions AC_makeActionsSingle(AC_Action head)
{
  return (AC_Actions)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  AC_Actions AC_makeActionsMany(AC_Action head, AC_Actions tail) */

AC_Actions AC_makeActionsMany(AC_Action head, AC_Actions tail)
{
  return (AC_Actions)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  AC_Action AC_makeActionDup(void) */

AC_Action AC_makeActionDup(void)
{
  return (AC_Action)(ATerm)ATmakeAppl0(AC_afun0);
}

/*}}}  */
/*{{{  AC_Action AC_makeActionPop(void) */

AC_Action AC_makeActionPop(void)
{
  return (AC_Action)(ATerm)ATmakeAppl0(AC_afun1);
}

/*}}}  */
/*{{{  AC_Action AC_makeActionPushString(const char* string) */

AC_Action AC_makeActionPushString(const char* string)
{
  return (AC_Action)(ATerm)ATmakeAppl1(AC_afun2, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
}

/*}}}  */
/*{{{  AC_Action AC_makeActionApply(const char* functionName, const char* resultSort, int argumentsNumber) */

AC_Action AC_makeActionApply(const char* functionName, const char* resultSort, int argumentsNumber)
{
  return (AC_Action)(ATerm)ATmakeAppl3(AC_afun3, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(functionName, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(resultSort, 0, ATtrue)), (ATerm) (ATerm) ATmakeInt(argumentsNumber));
}

/*}}}  */
/*{{{  AC_Action AC_makeActionPushTerm(ATerm term) */

AC_Action AC_makeActionPushTerm(ATerm term)
{
  return (AC_Action)(ATerm)ATmakeAppl1(AC_afun4, (ATerm) term);
}

/*}}}  */
/*{{{  AC_Action AC_makeActionPushFilename(const char* string) */

AC_Action AC_makeActionPushFilename(const char* string)
{
  return (AC_Action)(ATerm)ATmakeAppl1(AC_afun5, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
}

/*}}}  */
/*{{{  AC_Action AC_makeActionPushModulename(const char* string) */

AC_Action AC_makeActionPushModulename(const char* string)
{
  return (AC_Action)(ATerm)ATmakeAppl1(AC_afun6, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
}

/*}}}  */
/*{{{  AC_Action AC_makeActionCondition(AC_Actions thenList, AC_Actions elseList) */

AC_Action AC_makeActionCondition(AC_Actions thenList, AC_Actions elseList)
{
  return (AC_Action)(ATerm)ATmakeAppl2(AC_afun7, (ATerm) thenList, (ATerm) elseList);
}

/*}}}  */
/*{{{  AC_Action AC_makeActionGeneric(ATerm name) */

AC_Action AC_makeActionGeneric(ATerm name)
{
  return (AC_Action)(ATerm) name;
}

/*}}}  */
/*{{{  AC_Signature AC_makeSignatureList(AC_Descriptions list) */

AC_Signature AC_makeSignatureList(AC_Descriptions list)
{
  return (AC_Signature)(ATerm) list;
}

/*}}}  */
/*{{{  AC_Descriptions AC_makeDescriptionsEmpty(void) */

AC_Descriptions AC_makeDescriptionsEmpty(void)
{
  return (AC_Descriptions)(ATerm)ATempty;
}

/*}}}  */
/*{{{  AC_Descriptions AC_makeDescriptionsSingle(AC_Description head) */

AC_Descriptions AC_makeDescriptionsSingle(AC_Description head)
{
  return (AC_Descriptions)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  AC_Descriptions AC_makeDescriptionsMany(AC_Description head, AC_Descriptions tail) */

AC_Descriptions AC_makeDescriptionsMany(AC_Description head, AC_Descriptions tail)
{
  return (AC_Descriptions)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  AC_Description AC_makeDescriptionAction(ATerm name, AC_Args arguments) */

AC_Description AC_makeDescriptionAction(ATerm name, AC_Args arguments)
{
  return (AC_Description)(ATerm)ATmakeAppl2(AC_afun8, (ATerm) name, (ATerm) arguments);
}

/*}}}  */
/*{{{  AC_Args AC_makeArgsEmpty(void) */

AC_Args AC_makeArgsEmpty(void)
{
  return (AC_Args)(ATerm)ATempty;
}

/*}}}  */
/*{{{  AC_Args AC_makeArgsSingle(AC_Arg head) */

AC_Args AC_makeArgsSingle(AC_Arg head)
{
  return (AC_Args)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  AC_Args AC_makeArgsMany(AC_Arg head, AC_Args tail) */

AC_Args AC_makeArgsMany(AC_Arg head, AC_Args tail)
{
  return (AC_Args)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  AC_Arg AC_makeArgString(void) */

AC_Arg AC_makeArgString(void)
{
  return (AC_Arg)(ATerm)ATmakeAppl0(AC_afun9);
}

/*}}}  */
/*{{{  AC_Arg AC_makeArgTree(void) */

AC_Arg AC_makeArgTree(void)
{
  return (AC_Arg)(ATerm)ATmakeAppl0(AC_afun10);
}

/*}}}  */
/*{{{  AC_Message AC_makeMessagePromptForFile(const char* title, const char* path, const char* modulename) */

AC_Message AC_makeMessagePromptForFile(const char* title, const char* path, const char* modulename)
{
  return (AC_Message)(ATerm)ATmakeAppl3(AC_afun11, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(title, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(modulename, 0, ATtrue)));
}

/*}}}  */
/*{{{  AC_Message AC_makeMessageEditTerm(const char* filename, const char* modulename) */

AC_Message AC_makeMessageEditTerm(const char* filename, const char* modulename)
{
  return (AC_Message)(ATerm)ATmakeAppl2(AC_afun12, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(modulename, 0, ATtrue)));
}

/*}}}  */
/*{{{  AC_Stack AC_makeStackEmpty(void) */

AC_Stack AC_makeStackEmpty(void)
{
  return (AC_Stack)(ATerm)ATempty;
}

/*}}}  */
/*{{{  AC_Stack AC_makeStackSingle(AC_Item head) */

AC_Stack AC_makeStackSingle(AC_Item head)
{
  return (AC_Stack)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  AC_Stack AC_makeStackMany(AC_Item head, AC_Stack tail) */

AC_Stack AC_makeStackMany(AC_Item head, AC_Stack tail)
{
  return (AC_Stack)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  AC_Item AC_makeItemString(const char* string) */

AC_Item AC_makeItemString(const char* string)
{
  return (AC_Item)(ATerm)ATmakeAppl1(AC_afun13, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool AC_isEqualScript(AC_Script arg0, AC_Script arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool AC_isEqualActions(AC_Actions arg0, AC_Actions arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool AC_isEqualAction(AC_Action arg0, AC_Action arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool AC_isEqualSignature(AC_Signature arg0, AC_Signature arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool AC_isEqualDescriptions(AC_Descriptions arg0, AC_Descriptions arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool AC_isEqualDescription(AC_Description arg0, AC_Description arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool AC_isEqualArgs(AC_Args arg0, AC_Args arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool AC_isEqualArg(AC_Arg arg0, AC_Arg arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool AC_isEqualMessage(AC_Message arg0, AC_Message arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool AC_isEqualStack(AC_Stack arg0, AC_Stack arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool AC_isEqualItem(AC_Item arg0, AC_Item arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  AC_Script accessors */

/*{{{  ATbool AC_isValidScript(AC_Script arg) */

ATbool AC_isValidScript(AC_Script arg)
{
  if (AC_isScriptList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool AC_isScriptList(AC_Script arg) */

inline ATbool AC_isScriptList(AC_Script arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, AC_patternScriptList, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool AC_hasScriptList(AC_Script arg) */

ATbool AC_hasScriptList(AC_Script arg)
{
  if (AC_isScriptList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  AC_Actions AC_getScriptList(AC_Script arg) */

AC_Actions AC_getScriptList(AC_Script arg)
{
  
    return (AC_Actions)arg;
}

/*}}}  */
/*{{{  AC_Script AC_setScriptList(AC_Script arg, AC_Actions list) */

AC_Script AC_setScriptList(AC_Script arg, AC_Actions list)
{
  if (AC_isScriptList(arg)) {
    return (AC_Script)((ATerm) list);
  }

  ATabort("Script has no List: %t\n", arg);
  return (AC_Script)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  AC_Actions accessors */

/*{{{  ATbool AC_isValidActions(AC_Actions arg) */

ATbool AC_isValidActions(AC_Actions arg)
{
  if (AC_isActionsEmpty(arg)) {
    return ATtrue;
  }
  else if (AC_isActionsSingle(arg)) {
    return ATtrue;
  }
  else if (AC_isActionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool AC_isActionsEmpty(AC_Actions arg) */

inline ATbool AC_isActionsEmpty(AC_Actions arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, AC_patternActionsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool AC_isActionsSingle(AC_Actions arg) */

inline ATbool AC_isActionsSingle(AC_Actions arg)
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
      last_result = ATmatchTerm((ATerm)arg, AC_patternActionsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool AC_isActionsMany(AC_Actions arg) */

inline ATbool AC_isActionsMany(AC_Actions arg)
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
      last_result = ATmatchTerm((ATerm)arg, AC_patternActionsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool AC_hasActionsHead(AC_Actions arg) */

ATbool AC_hasActionsHead(AC_Actions arg)
{
  if (AC_isActionsSingle(arg)) {
    return ATtrue;
  }
  else if (AC_isActionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool AC_hasActionsTail(AC_Actions arg) */

ATbool AC_hasActionsTail(AC_Actions arg)
{
  if (AC_isActionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  AC_Action AC_getActionsHead(AC_Actions arg) */

AC_Action AC_getActionsHead(AC_Actions arg)
{
  if (AC_isActionsSingle(arg)) {
    return (AC_Action)ATgetFirst((ATermList)arg);
  }
  else 
    return (AC_Action)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  AC_Actions AC_getActionsTail(AC_Actions arg) */

AC_Actions AC_getActionsTail(AC_Actions arg)
{
  
    return (AC_Actions)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  AC_Actions AC_setActionsHead(AC_Actions arg, AC_Action head) */

AC_Actions AC_setActionsHead(AC_Actions arg, AC_Action head)
{
  if (AC_isActionsSingle(arg)) {
    return (AC_Actions)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (AC_isActionsMany(arg)) {
    return (AC_Actions)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Actions has no Head: %t\n", arg);
  return (AC_Actions)NULL;
}

/*}}}  */
/*{{{  AC_Actions AC_setActionsTail(AC_Actions arg, AC_Actions tail) */

AC_Actions AC_setActionsTail(AC_Actions arg, AC_Actions tail)
{
  if (AC_isActionsMany(arg)) {
    return (AC_Actions)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Actions has no Tail: %t\n", arg);
  return (AC_Actions)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  AC_Action accessors */

/*{{{  ATbool AC_isValidAction(AC_Action arg) */

ATbool AC_isValidAction(AC_Action arg)
{
  if (AC_isActionDup(arg)) {
    return ATtrue;
  }
  else if (AC_isActionPop(arg)) {
    return ATtrue;
  }
  else if (AC_isActionPushString(arg)) {
    return ATtrue;
  }
  else if (AC_isActionApply(arg)) {
    return ATtrue;
  }
  else if (AC_isActionPushTerm(arg)) {
    return ATtrue;
  }
  else if (AC_isActionPushFilename(arg)) {
    return ATtrue;
  }
  else if (AC_isActionPushModulename(arg)) {
    return ATtrue;
  }
  else if (AC_isActionCondition(arg)) {
    return ATtrue;
  }
  else if (AC_isActionGeneric(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool AC_isActionDup(AC_Action arg) */

inline ATbool AC_isActionDup(AC_Action arg)
{
  if (ATgetType((ATerm)arg) != AT_APPL) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, AC_patternActionDup);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool AC_isActionPop(AC_Action arg) */

inline ATbool AC_isActionPop(AC_Action arg)
{
  if (ATgetType((ATerm)arg) != AT_APPL) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, AC_patternActionPop);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool AC_isActionPushString(AC_Action arg) */

inline ATbool AC_isActionPushString(AC_Action arg)
{
  if (ATgetType((ATerm)arg) != AT_APPL) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, AC_patternActionPushString, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool AC_isActionApply(AC_Action arg) */

inline ATbool AC_isActionApply(AC_Action arg)
{
  if (ATgetType((ATerm)arg) != AT_APPL) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, AC_patternActionApply, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool AC_isActionPushTerm(AC_Action arg) */

inline ATbool AC_isActionPushTerm(AC_Action arg)
{
  if (ATgetType((ATerm)arg) != AT_APPL) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, AC_patternActionPushTerm, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool AC_isActionPushFilename(AC_Action arg) */

inline ATbool AC_isActionPushFilename(AC_Action arg)
{
  if (ATgetType((ATerm)arg) != AT_APPL) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, AC_patternActionPushFilename, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool AC_isActionPushModulename(AC_Action arg) */

inline ATbool AC_isActionPushModulename(AC_Action arg)
{
  if (ATgetType((ATerm)arg) != AT_APPL) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, AC_patternActionPushModulename, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool AC_isActionCondition(AC_Action arg) */

inline ATbool AC_isActionCondition(AC_Action arg)
{
  if (ATgetType((ATerm)arg) != AT_APPL) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, AC_patternActionCondition, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool AC_isActionGeneric(AC_Action arg) */

inline ATbool AC_isActionGeneric(AC_Action arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, AC_patternActionGeneric, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool AC_hasActionString(AC_Action arg) */

ATbool AC_hasActionString(AC_Action arg)
{
  if (AC_isActionPushString(arg)) {
    return ATtrue;
  }
  else if (AC_isActionPushFilename(arg)) {
    return ATtrue;
  }
  else if (AC_isActionPushModulename(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool AC_hasActionFunctionName(AC_Action arg) */

ATbool AC_hasActionFunctionName(AC_Action arg)
{
  if (AC_isActionApply(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool AC_hasActionResultSort(AC_Action arg) */

ATbool AC_hasActionResultSort(AC_Action arg)
{
  if (AC_isActionApply(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool AC_hasActionArgumentsNumber(AC_Action arg) */

ATbool AC_hasActionArgumentsNumber(AC_Action arg)
{
  if (AC_isActionApply(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool AC_hasActionTerm(AC_Action arg) */

ATbool AC_hasActionTerm(AC_Action arg)
{
  if (AC_isActionPushTerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool AC_hasActionThenList(AC_Action arg) */

ATbool AC_hasActionThenList(AC_Action arg)
{
  if (AC_isActionCondition(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool AC_hasActionElseList(AC_Action arg) */

ATbool AC_hasActionElseList(AC_Action arg)
{
  if (AC_isActionCondition(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool AC_hasActionName(AC_Action arg) */

ATbool AC_hasActionName(AC_Action arg)
{
  if (AC_isActionGeneric(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* AC_getActionString(AC_Action arg) */

char* AC_getActionString(AC_Action arg)
{
  if (AC_isActionPushString(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (AC_isActionPushFilename(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  char* AC_getActionFunctionName(AC_Action arg) */

char* AC_getActionFunctionName(AC_Action arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  char* AC_getActionResultSort(AC_Action arg) */

char* AC_getActionResultSort(AC_Action arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  int AC_getActionArgumentsNumber(AC_Action arg) */

int AC_getActionArgumentsNumber(AC_Action arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  ATerm AC_getActionTerm(AC_Action arg) */

ATerm AC_getActionTerm(AC_Action arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  AC_Actions AC_getActionThenList(AC_Action arg) */

AC_Actions AC_getActionThenList(AC_Action arg)
{
  
    return (AC_Actions)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  AC_Actions AC_getActionElseList(AC_Action arg) */

AC_Actions AC_getActionElseList(AC_Action arg)
{
  
    return (AC_Actions)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  ATerm AC_getActionName(AC_Action arg) */

ATerm AC_getActionName(AC_Action arg)
{
  
    return (ATerm)arg;
}

/*}}}  */
/*{{{  AC_Action AC_setActionString(AC_Action arg, const char* string) */

AC_Action AC_setActionString(AC_Action arg, const char* string)
{
  if (AC_isActionPushString(arg)) {
    return (AC_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue))), 0);
  }
  else if (AC_isActionPushFilename(arg)) {
    return (AC_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue))), 0);
  }
  else if (AC_isActionPushModulename(arg)) {
    return (AC_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue))), 0);
  }

  ATabort("Action has no String: %t\n", arg);
  return (AC_Action)NULL;
}

/*}}}  */
/*{{{  AC_Action AC_setActionFunctionName(AC_Action arg, const char* functionName) */

AC_Action AC_setActionFunctionName(AC_Action arg, const char* functionName)
{
  if (AC_isActionApply(arg)) {
    return (AC_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(functionName, 0, ATtrue))), 0);
  }

  ATabort("Action has no FunctionName: %t\n", arg);
  return (AC_Action)NULL;
}

/*}}}  */
/*{{{  AC_Action AC_setActionResultSort(AC_Action arg, const char* resultSort) */

AC_Action AC_setActionResultSort(AC_Action arg, const char* resultSort)
{
  if (AC_isActionApply(arg)) {
    return (AC_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(resultSort, 0, ATtrue))), 1);
  }

  ATabort("Action has no ResultSort: %t\n", arg);
  return (AC_Action)NULL;
}

/*}}}  */
/*{{{  AC_Action AC_setActionArgumentsNumber(AC_Action arg, int argumentsNumber) */

AC_Action AC_setActionArgumentsNumber(AC_Action arg, int argumentsNumber)
{
  if (AC_isActionApply(arg)) {
    return (AC_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(argumentsNumber)), 2);
  }

  ATabort("Action has no ArgumentsNumber: %t\n", arg);
  return (AC_Action)NULL;
}

/*}}}  */
/*{{{  AC_Action AC_setActionTerm(AC_Action arg, ATerm term) */

AC_Action AC_setActionTerm(AC_Action arg, ATerm term)
{
  if (AC_isActionPushTerm(arg)) {
    return (AC_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) term), 0);
  }

  ATabort("Action has no Term: %t\n", arg);
  return (AC_Action)NULL;
}

/*}}}  */
/*{{{  AC_Action AC_setActionThenList(AC_Action arg, AC_Actions thenList) */

AC_Action AC_setActionThenList(AC_Action arg, AC_Actions thenList)
{
  if (AC_isActionCondition(arg)) {
    return (AC_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) thenList), 0);
  }

  ATabort("Action has no ThenList: %t\n", arg);
  return (AC_Action)NULL;
}

/*}}}  */
/*{{{  AC_Action AC_setActionElseList(AC_Action arg, AC_Actions elseList) */

AC_Action AC_setActionElseList(AC_Action arg, AC_Actions elseList)
{
  if (AC_isActionCondition(arg)) {
    return (AC_Action)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) elseList), 1);
  }

  ATabort("Action has no ElseList: %t\n", arg);
  return (AC_Action)NULL;
}

/*}}}  */
/*{{{  AC_Action AC_setActionName(AC_Action arg, ATerm name) */

AC_Action AC_setActionName(AC_Action arg, ATerm name)
{
  if (AC_isActionGeneric(arg)) {
    return (AC_Action)((ATerm) name);
  }

  ATabort("Action has no Name: %t\n", arg);
  return (AC_Action)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  AC_Signature accessors */

/*{{{  ATbool AC_isValidSignature(AC_Signature arg) */

ATbool AC_isValidSignature(AC_Signature arg)
{
  if (AC_isSignatureList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool AC_isSignatureList(AC_Signature arg) */

inline ATbool AC_isSignatureList(AC_Signature arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, AC_patternSignatureList, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool AC_hasSignatureList(AC_Signature arg) */

ATbool AC_hasSignatureList(AC_Signature arg)
{
  if (AC_isSignatureList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  AC_Descriptions AC_getSignatureList(AC_Signature arg) */

AC_Descriptions AC_getSignatureList(AC_Signature arg)
{
  
    return (AC_Descriptions)arg;
}

/*}}}  */
/*{{{  AC_Signature AC_setSignatureList(AC_Signature arg, AC_Descriptions list) */

AC_Signature AC_setSignatureList(AC_Signature arg, AC_Descriptions list)
{
  if (AC_isSignatureList(arg)) {
    return (AC_Signature)((ATerm) list);
  }

  ATabort("Signature has no List: %t\n", arg);
  return (AC_Signature)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  AC_Descriptions accessors */

/*{{{  ATbool AC_isValidDescriptions(AC_Descriptions arg) */

ATbool AC_isValidDescriptions(AC_Descriptions arg)
{
  if (AC_isDescriptionsEmpty(arg)) {
    return ATtrue;
  }
  else if (AC_isDescriptionsSingle(arg)) {
    return ATtrue;
  }
  else if (AC_isDescriptionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool AC_isDescriptionsEmpty(AC_Descriptions arg) */

inline ATbool AC_isDescriptionsEmpty(AC_Descriptions arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, AC_patternDescriptionsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool AC_isDescriptionsSingle(AC_Descriptions arg) */

inline ATbool AC_isDescriptionsSingle(AC_Descriptions arg)
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
      last_result = ATmatchTerm((ATerm)arg, AC_patternDescriptionsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool AC_isDescriptionsMany(AC_Descriptions arg) */

inline ATbool AC_isDescriptionsMany(AC_Descriptions arg)
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
      last_result = ATmatchTerm((ATerm)arg, AC_patternDescriptionsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool AC_hasDescriptionsHead(AC_Descriptions arg) */

ATbool AC_hasDescriptionsHead(AC_Descriptions arg)
{
  if (AC_isDescriptionsSingle(arg)) {
    return ATtrue;
  }
  else if (AC_isDescriptionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool AC_hasDescriptionsTail(AC_Descriptions arg) */

ATbool AC_hasDescriptionsTail(AC_Descriptions arg)
{
  if (AC_isDescriptionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  AC_Description AC_getDescriptionsHead(AC_Descriptions arg) */

AC_Description AC_getDescriptionsHead(AC_Descriptions arg)
{
  if (AC_isDescriptionsSingle(arg)) {
    return (AC_Description)ATgetFirst((ATermList)arg);
  }
  else 
    return (AC_Description)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  AC_Descriptions AC_getDescriptionsTail(AC_Descriptions arg) */

AC_Descriptions AC_getDescriptionsTail(AC_Descriptions arg)
{
  
    return (AC_Descriptions)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  AC_Descriptions AC_setDescriptionsHead(AC_Descriptions arg, AC_Description head) */

AC_Descriptions AC_setDescriptionsHead(AC_Descriptions arg, AC_Description head)
{
  if (AC_isDescriptionsSingle(arg)) {
    return (AC_Descriptions)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (AC_isDescriptionsMany(arg)) {
    return (AC_Descriptions)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Descriptions has no Head: %t\n", arg);
  return (AC_Descriptions)NULL;
}

/*}}}  */
/*{{{  AC_Descriptions AC_setDescriptionsTail(AC_Descriptions arg, AC_Descriptions tail) */

AC_Descriptions AC_setDescriptionsTail(AC_Descriptions arg, AC_Descriptions tail)
{
  if (AC_isDescriptionsMany(arg)) {
    return (AC_Descriptions)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Descriptions has no Tail: %t\n", arg);
  return (AC_Descriptions)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  AC_Description accessors */

/*{{{  ATbool AC_isValidDescription(AC_Description arg) */

ATbool AC_isValidDescription(AC_Description arg)
{
  if (AC_isDescriptionAction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool AC_isDescriptionAction(AC_Description arg) */

inline ATbool AC_isDescriptionAction(AC_Description arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, AC_patternDescriptionAction, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool AC_hasDescriptionName(AC_Description arg) */

ATbool AC_hasDescriptionName(AC_Description arg)
{
  if (AC_isDescriptionAction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool AC_hasDescriptionArguments(AC_Description arg) */

ATbool AC_hasDescriptionArguments(AC_Description arg)
{
  if (AC_isDescriptionAction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm AC_getDescriptionName(AC_Description arg) */

ATerm AC_getDescriptionName(AC_Description arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  AC_Args AC_getDescriptionArguments(AC_Description arg) */

AC_Args AC_getDescriptionArguments(AC_Description arg)
{
  
    return (AC_Args)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  AC_Description AC_setDescriptionName(AC_Description arg, ATerm name) */

AC_Description AC_setDescriptionName(AC_Description arg, ATerm name)
{
  if (AC_isDescriptionAction(arg)) {
    return (AC_Description)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) name), 0);
  }

  ATabort("Description has no Name: %t\n", arg);
  return (AC_Description)NULL;
}

/*}}}  */
/*{{{  AC_Description AC_setDescriptionArguments(AC_Description arg, AC_Args arguments) */

AC_Description AC_setDescriptionArguments(AC_Description arg, AC_Args arguments)
{
  if (AC_isDescriptionAction(arg)) {
    return (AC_Description)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) arguments), 1);
  }

  ATabort("Description has no Arguments: %t\n", arg);
  return (AC_Description)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  AC_Args accessors */

/*{{{  ATbool AC_isValidArgs(AC_Args arg) */

ATbool AC_isValidArgs(AC_Args arg)
{
  if (AC_isArgsEmpty(arg)) {
    return ATtrue;
  }
  else if (AC_isArgsSingle(arg)) {
    return ATtrue;
  }
  else if (AC_isArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool AC_isArgsEmpty(AC_Args arg) */

inline ATbool AC_isArgsEmpty(AC_Args arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, AC_patternArgsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool AC_isArgsSingle(AC_Args arg) */

inline ATbool AC_isArgsSingle(AC_Args arg)
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
      last_result = ATmatchTerm((ATerm)arg, AC_patternArgsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool AC_isArgsMany(AC_Args arg) */

inline ATbool AC_isArgsMany(AC_Args arg)
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
      last_result = ATmatchTerm((ATerm)arg, AC_patternArgsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool AC_hasArgsHead(AC_Args arg) */

ATbool AC_hasArgsHead(AC_Args arg)
{
  if (AC_isArgsSingle(arg)) {
    return ATtrue;
  }
  else if (AC_isArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool AC_hasArgsTail(AC_Args arg) */

ATbool AC_hasArgsTail(AC_Args arg)
{
  if (AC_isArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  AC_Arg AC_getArgsHead(AC_Args arg) */

AC_Arg AC_getArgsHead(AC_Args arg)
{
  if (AC_isArgsSingle(arg)) {
    return (AC_Arg)ATgetFirst((ATermList)arg);
  }
  else 
    return (AC_Arg)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  AC_Args AC_getArgsTail(AC_Args arg) */

AC_Args AC_getArgsTail(AC_Args arg)
{
  
    return (AC_Args)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  AC_Args AC_setArgsHead(AC_Args arg, AC_Arg head) */

AC_Args AC_setArgsHead(AC_Args arg, AC_Arg head)
{
  if (AC_isArgsSingle(arg)) {
    return (AC_Args)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (AC_isArgsMany(arg)) {
    return (AC_Args)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Args has no Head: %t\n", arg);
  return (AC_Args)NULL;
}

/*}}}  */
/*{{{  AC_Args AC_setArgsTail(AC_Args arg, AC_Args tail) */

AC_Args AC_setArgsTail(AC_Args arg, AC_Args tail)
{
  if (AC_isArgsMany(arg)) {
    return (AC_Args)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Args has no Tail: %t\n", arg);
  return (AC_Args)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  AC_Arg accessors */

/*{{{  ATbool AC_isValidArg(AC_Arg arg) */

ATbool AC_isValidArg(AC_Arg arg)
{
  if (AC_isArgString(arg)) {
    return ATtrue;
  }
  else if (AC_isArgTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool AC_isArgString(AC_Arg arg) */

inline ATbool AC_isArgString(AC_Arg arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, AC_patternArgString);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool AC_isArgTree(AC_Arg arg) */

inline ATbool AC_isArgTree(AC_Arg arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, AC_patternArgTree);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  AC_Message accessors */

/*{{{  ATbool AC_isValidMessage(AC_Message arg) */

ATbool AC_isValidMessage(AC_Message arg)
{
  if (AC_isMessagePromptForFile(arg)) {
    return ATtrue;
  }
  else if (AC_isMessageEditTerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool AC_isMessagePromptForFile(AC_Message arg) */

inline ATbool AC_isMessagePromptForFile(AC_Message arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, AC_patternMessagePromptForFile, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool AC_isMessageEditTerm(AC_Message arg) */

inline ATbool AC_isMessageEditTerm(AC_Message arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, AC_patternMessageEditTerm, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool AC_hasMessageTitle(AC_Message arg) */

ATbool AC_hasMessageTitle(AC_Message arg)
{
  if (AC_isMessagePromptForFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool AC_hasMessagePath(AC_Message arg) */

ATbool AC_hasMessagePath(AC_Message arg)
{
  if (AC_isMessagePromptForFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool AC_hasMessageModulename(AC_Message arg) */

ATbool AC_hasMessageModulename(AC_Message arg)
{
  if (AC_isMessagePromptForFile(arg)) {
    return ATtrue;
  }
  else if (AC_isMessageEditTerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool AC_hasMessageFilename(AC_Message arg) */

ATbool AC_hasMessageFilename(AC_Message arg)
{
  if (AC_isMessageEditTerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* AC_getMessageTitle(AC_Message arg) */

char* AC_getMessageTitle(AC_Message arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  char* AC_getMessagePath(AC_Message arg) */

char* AC_getMessagePath(AC_Message arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  char* AC_getMessageModulename(AC_Message arg) */

char* AC_getMessageModulename(AC_Message arg)
{
  if (AC_isMessagePromptForFile(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 2)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  char* AC_getMessageFilename(AC_Message arg) */

char* AC_getMessageFilename(AC_Message arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  AC_Message AC_setMessageTitle(AC_Message arg, const char* title) */

AC_Message AC_setMessageTitle(AC_Message arg, const char* title)
{
  if (AC_isMessagePromptForFile(arg)) {
    return (AC_Message)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(title, 0, ATtrue))), 0);
  }

  ATabort("Message has no Title: %t\n", arg);
  return (AC_Message)NULL;
}

/*}}}  */
/*{{{  AC_Message AC_setMessagePath(AC_Message arg, const char* path) */

AC_Message AC_setMessagePath(AC_Message arg, const char* path)
{
  if (AC_isMessagePromptForFile(arg)) {
    return (AC_Message)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 1);
  }

  ATabort("Message has no Path: %t\n", arg);
  return (AC_Message)NULL;
}

/*}}}  */
/*{{{  AC_Message AC_setMessageModulename(AC_Message arg, const char* modulename) */

AC_Message AC_setMessageModulename(AC_Message arg, const char* modulename)
{
  if (AC_isMessagePromptForFile(arg)) {
    return (AC_Message)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(modulename, 0, ATtrue))), 2);
  }
  else if (AC_isMessageEditTerm(arg)) {
    return (AC_Message)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(modulename, 0, ATtrue))), 1);
  }

  ATabort("Message has no Modulename: %t\n", arg);
  return (AC_Message)NULL;
}

/*}}}  */
/*{{{  AC_Message AC_setMessageFilename(AC_Message arg, const char* filename) */

AC_Message AC_setMessageFilename(AC_Message arg, const char* filename)
{
  if (AC_isMessageEditTerm(arg)) {
    return (AC_Message)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue))), 0);
  }

  ATabort("Message has no Filename: %t\n", arg);
  return (AC_Message)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  AC_Stack accessors */

/*{{{  ATbool AC_isValidStack(AC_Stack arg) */

ATbool AC_isValidStack(AC_Stack arg)
{
  if (AC_isStackEmpty(arg)) {
    return ATtrue;
  }
  else if (AC_isStackSingle(arg)) {
    return ATtrue;
  }
  else if (AC_isStackMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool AC_isStackEmpty(AC_Stack arg) */

inline ATbool AC_isStackEmpty(AC_Stack arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, AC_patternStackEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool AC_isStackSingle(AC_Stack arg) */

inline ATbool AC_isStackSingle(AC_Stack arg)
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
      last_result = ATmatchTerm((ATerm)arg, AC_patternStackSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool AC_isStackMany(AC_Stack arg) */

inline ATbool AC_isStackMany(AC_Stack arg)
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
      last_result = ATmatchTerm((ATerm)arg, AC_patternStackMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool AC_hasStackHead(AC_Stack arg) */

ATbool AC_hasStackHead(AC_Stack arg)
{
  if (AC_isStackSingle(arg)) {
    return ATtrue;
  }
  else if (AC_isStackMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool AC_hasStackTail(AC_Stack arg) */

ATbool AC_hasStackTail(AC_Stack arg)
{
  if (AC_isStackMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  AC_Item AC_getStackHead(AC_Stack arg) */

AC_Item AC_getStackHead(AC_Stack arg)
{
  if (AC_isStackSingle(arg)) {
    return (AC_Item)ATgetFirst((ATermList)arg);
  }
  else 
    return (AC_Item)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  AC_Stack AC_getStackTail(AC_Stack arg) */

AC_Stack AC_getStackTail(AC_Stack arg)
{
  
    return (AC_Stack)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  AC_Stack AC_setStackHead(AC_Stack arg, AC_Item head) */

AC_Stack AC_setStackHead(AC_Stack arg, AC_Item head)
{
  if (AC_isStackSingle(arg)) {
    return (AC_Stack)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (AC_isStackMany(arg)) {
    return (AC_Stack)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Stack has no Head: %t\n", arg);
  return (AC_Stack)NULL;
}

/*}}}  */
/*{{{  AC_Stack AC_setStackTail(AC_Stack arg, AC_Stack tail) */

AC_Stack AC_setStackTail(AC_Stack arg, AC_Stack tail)
{
  if (AC_isStackMany(arg)) {
    return (AC_Stack)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Stack has no Tail: %t\n", arg);
  return (AC_Stack)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  AC_Item accessors */

/*{{{  ATbool AC_isValidItem(AC_Item arg) */

ATbool AC_isValidItem(AC_Item arg)
{
  if (AC_isItemString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool AC_isItemString(AC_Item arg) */

inline ATbool AC_isItemString(AC_Item arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, AC_patternItemString, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool AC_hasItemString(AC_Item arg) */

ATbool AC_hasItemString(AC_Item arg)
{
  if (AC_isItemString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* AC_getItemString(AC_Item arg) */

char* AC_getItemString(AC_Item arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  AC_Item AC_setItemString(AC_Item arg, const char* string) */

AC_Item AC_setItemString(AC_Item arg, const char* string)
{
  if (AC_isItemString(arg)) {
    return (AC_Item)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue))), 0);
  }

  ATabort("Item has no String: %t\n", arg);
  return (AC_Item)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  AC_Script AC_visitScript(AC_Script arg, AC_Actions (*acceptList)(AC_Actions)) */

AC_Script AC_visitScript(AC_Script arg, AC_Actions (*acceptList)(AC_Actions))
{
  if (AC_isScriptList(arg)) {
    return AC_makeScriptList(
        acceptList ? acceptList(AC_getScriptList(arg)) : AC_getScriptList(arg));
  }
  ATabort("not a Script: %t\n", arg);
  return (AC_Script)NULL;
}

/*}}}  */
/*{{{  AC_Actions AC_visitActions(AC_Actions arg, AC_Action (*acceptHead)(AC_Action)) */

AC_Actions AC_visitActions(AC_Actions arg, AC_Action (*acceptHead)(AC_Action))
{
  if (AC_isActionsEmpty(arg)) {
    return AC_makeActionsEmpty();
  }
  if (AC_isActionsSingle(arg)) {
    return AC_makeActionsSingle(
        acceptHead ? acceptHead(AC_getActionsHead(arg)) : AC_getActionsHead(arg));
  }
  if (AC_isActionsMany(arg)) {
    return AC_makeActionsMany(
        acceptHead ? acceptHead(AC_getActionsHead(arg)) : AC_getActionsHead(arg),
        AC_visitActions(AC_getActionsTail(arg), acceptHead));
  }
  ATabort("not a Actions: %t\n", arg);
  return (AC_Actions)NULL;
}

/*}}}  */
/*{{{  AC_Action AC_visitAction(AC_Action arg, char* (*acceptString)(char*), char* (*acceptFunctionName)(char*), char* (*acceptResultSort)(char*), int (*acceptArgumentsNumber)(int), ATerm (*acceptTerm)(ATerm), AC_Actions (*acceptThenList)(AC_Actions), AC_Actions (*acceptElseList)(AC_Actions), ATerm (*acceptName)(ATerm)) */

AC_Action AC_visitAction(AC_Action arg, char* (*acceptString)(char*), char* (*acceptFunctionName)(char*), char* (*acceptResultSort)(char*), int (*acceptArgumentsNumber)(int), ATerm (*acceptTerm)(ATerm), AC_Actions (*acceptThenList)(AC_Actions), AC_Actions (*acceptElseList)(AC_Actions), ATerm (*acceptName)(ATerm))
{
  if (AC_isActionDup(arg)) {
    return AC_makeActionDup();
  }
  if (AC_isActionPop(arg)) {
    return AC_makeActionPop();
  }
  if (AC_isActionPushString(arg)) {
    return AC_makeActionPushString(
        acceptString ? acceptString(AC_getActionString(arg)) : AC_getActionString(arg));
  }
  if (AC_isActionApply(arg)) {
    return AC_makeActionApply(
        acceptFunctionName ? acceptFunctionName(AC_getActionFunctionName(arg)) : AC_getActionFunctionName(arg),
        acceptResultSort ? acceptResultSort(AC_getActionResultSort(arg)) : AC_getActionResultSort(arg),
        acceptArgumentsNumber ? acceptArgumentsNumber(AC_getActionArgumentsNumber(arg)) : AC_getActionArgumentsNumber(arg));
  }
  if (AC_isActionPushTerm(arg)) {
    return AC_makeActionPushTerm(
        acceptTerm ? acceptTerm(AC_getActionTerm(arg)) : AC_getActionTerm(arg));
  }
  if (AC_isActionPushFilename(arg)) {
    return AC_makeActionPushFilename(
        acceptString ? acceptString(AC_getActionString(arg)) : AC_getActionString(arg));
  }
  if (AC_isActionPushModulename(arg)) {
    return AC_makeActionPushModulename(
        acceptString ? acceptString(AC_getActionString(arg)) : AC_getActionString(arg));
  }
  if (AC_isActionCondition(arg)) {
    return AC_makeActionCondition(
        acceptThenList ? acceptThenList(AC_getActionThenList(arg)) : AC_getActionThenList(arg),
        acceptElseList ? acceptElseList(AC_getActionElseList(arg)) : AC_getActionElseList(arg));
  }
  if (AC_isActionGeneric(arg)) {
    return AC_makeActionGeneric(
        acceptName ? acceptName(AC_getActionName(arg)) : AC_getActionName(arg));
  }
  ATabort("not a Action: %t\n", arg);
  return (AC_Action)NULL;
}

/*}}}  */
/*{{{  AC_Signature AC_visitSignature(AC_Signature arg, AC_Descriptions (*acceptList)(AC_Descriptions)) */

AC_Signature AC_visitSignature(AC_Signature arg, AC_Descriptions (*acceptList)(AC_Descriptions))
{
  if (AC_isSignatureList(arg)) {
    return AC_makeSignatureList(
        acceptList ? acceptList(AC_getSignatureList(arg)) : AC_getSignatureList(arg));
  }
  ATabort("not a Signature: %t\n", arg);
  return (AC_Signature)NULL;
}

/*}}}  */
/*{{{  AC_Descriptions AC_visitDescriptions(AC_Descriptions arg, AC_Description (*acceptHead)(AC_Description)) */

AC_Descriptions AC_visitDescriptions(AC_Descriptions arg, AC_Description (*acceptHead)(AC_Description))
{
  if (AC_isDescriptionsEmpty(arg)) {
    return AC_makeDescriptionsEmpty();
  }
  if (AC_isDescriptionsSingle(arg)) {
    return AC_makeDescriptionsSingle(
        acceptHead ? acceptHead(AC_getDescriptionsHead(arg)) : AC_getDescriptionsHead(arg));
  }
  if (AC_isDescriptionsMany(arg)) {
    return AC_makeDescriptionsMany(
        acceptHead ? acceptHead(AC_getDescriptionsHead(arg)) : AC_getDescriptionsHead(arg),
        AC_visitDescriptions(AC_getDescriptionsTail(arg), acceptHead));
  }
  ATabort("not a Descriptions: %t\n", arg);
  return (AC_Descriptions)NULL;
}

/*}}}  */
/*{{{  AC_Description AC_visitDescription(AC_Description arg, ATerm (*acceptName)(ATerm), AC_Args (*acceptArguments)(AC_Args)) */

AC_Description AC_visitDescription(AC_Description arg, ATerm (*acceptName)(ATerm), AC_Args (*acceptArguments)(AC_Args))
{
  if (AC_isDescriptionAction(arg)) {
    return AC_makeDescriptionAction(
        acceptName ? acceptName(AC_getDescriptionName(arg)) : AC_getDescriptionName(arg),
        acceptArguments ? acceptArguments(AC_getDescriptionArguments(arg)) : AC_getDescriptionArguments(arg));
  }
  ATabort("not a Description: %t\n", arg);
  return (AC_Description)NULL;
}

/*}}}  */
/*{{{  AC_Args AC_visitArgs(AC_Args arg, AC_Arg (*acceptHead)(AC_Arg)) */

AC_Args AC_visitArgs(AC_Args arg, AC_Arg (*acceptHead)(AC_Arg))
{
  if (AC_isArgsEmpty(arg)) {
    return AC_makeArgsEmpty();
  }
  if (AC_isArgsSingle(arg)) {
    return AC_makeArgsSingle(
        acceptHead ? acceptHead(AC_getArgsHead(arg)) : AC_getArgsHead(arg));
  }
  if (AC_isArgsMany(arg)) {
    return AC_makeArgsMany(
        acceptHead ? acceptHead(AC_getArgsHead(arg)) : AC_getArgsHead(arg),
        AC_visitArgs(AC_getArgsTail(arg), acceptHead));
  }
  ATabort("not a Args: %t\n", arg);
  return (AC_Args)NULL;
}

/*}}}  */
/*{{{  AC_Arg AC_visitArg(AC_Arg arg) */

AC_Arg AC_visitArg(AC_Arg arg)
{
  if (AC_isArgString(arg)) {
    return AC_makeArgString();
  }
  if (AC_isArgTree(arg)) {
    return AC_makeArgTree();
  }
  ATabort("not a Arg: %t\n", arg);
  return (AC_Arg)NULL;
}

/*}}}  */
/*{{{  AC_Message AC_visitMessage(AC_Message arg, char* (*acceptTitle)(char*), char* (*acceptPath)(char*), char* (*acceptModulename)(char*), char* (*acceptFilename)(char*)) */

AC_Message AC_visitMessage(AC_Message arg, char* (*acceptTitle)(char*), char* (*acceptPath)(char*), char* (*acceptModulename)(char*), char* (*acceptFilename)(char*))
{
  if (AC_isMessagePromptForFile(arg)) {
    return AC_makeMessagePromptForFile(
        acceptTitle ? acceptTitle(AC_getMessageTitle(arg)) : AC_getMessageTitle(arg),
        acceptPath ? acceptPath(AC_getMessagePath(arg)) : AC_getMessagePath(arg),
        acceptModulename ? acceptModulename(AC_getMessageModulename(arg)) : AC_getMessageModulename(arg));
  }
  if (AC_isMessageEditTerm(arg)) {
    return AC_makeMessageEditTerm(
        acceptFilename ? acceptFilename(AC_getMessageFilename(arg)) : AC_getMessageFilename(arg),
        acceptModulename ? acceptModulename(AC_getMessageModulename(arg)) : AC_getMessageModulename(arg));
  }
  ATabort("not a Message: %t\n", arg);
  return (AC_Message)NULL;
}

/*}}}  */
/*{{{  AC_Stack AC_visitStack(AC_Stack arg, AC_Item (*acceptHead)(AC_Item)) */

AC_Stack AC_visitStack(AC_Stack arg, AC_Item (*acceptHead)(AC_Item))
{
  if (AC_isStackEmpty(arg)) {
    return AC_makeStackEmpty();
  }
  if (AC_isStackSingle(arg)) {
    return AC_makeStackSingle(
        acceptHead ? acceptHead(AC_getStackHead(arg)) : AC_getStackHead(arg));
  }
  if (AC_isStackMany(arg)) {
    return AC_makeStackMany(
        acceptHead ? acceptHead(AC_getStackHead(arg)) : AC_getStackHead(arg),
        AC_visitStack(AC_getStackTail(arg), acceptHead));
  }
  ATabort("not a Stack: %t\n", arg);
  return (AC_Stack)NULL;
}

/*}}}  */
/*{{{  AC_Item AC_visitItem(AC_Item arg, char* (*acceptString)(char*)) */

AC_Item AC_visitItem(AC_Item arg, char* (*acceptString)(char*))
{
  if (AC_isItemString(arg)) {
    return AC_makeItemString(
        acceptString ? acceptString(AC_getItemString(arg)) : AC_getItemString(arg));
  }
  ATabort("not a Item: %t\n", arg);
  return (AC_Item)NULL;
}

/*}}}  */

/*}}}  */
