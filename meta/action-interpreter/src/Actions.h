#ifndef _ACTIONS_H
#define _ACTIONS_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Actions_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _AC_Script *AC_Script;
typedef struct _AC_Actions *AC_Actions;
typedef struct _AC_Action *AC_Action;
typedef struct _AC_Signature *AC_Signature;
typedef struct _AC_Descriptions *AC_Descriptions;
typedef struct _AC_Description *AC_Description;
typedef struct _AC_Args *AC_Args;
typedef struct _AC_Arg *AC_Arg;
typedef struct _AC_Message *AC_Message;
typedef struct _AC_Stack *AC_Stack;
typedef struct _AC_Item *AC_Item;

/*}}}  */

void AC_initActionsApi(void);

/*{{{  protect functions */

void AC_protectScript(AC_Script *arg);
void AC_protectActions(AC_Actions *arg);
void AC_protectAction(AC_Action *arg);
void AC_protectSignature(AC_Signature *arg);
void AC_protectDescriptions(AC_Descriptions *arg);
void AC_protectDescription(AC_Description *arg);
void AC_protectArgs(AC_Args *arg);
void AC_protectArg(AC_Arg *arg);
void AC_protectMessage(AC_Message *arg);
void AC_protectStack(AC_Stack *arg);
void AC_protectItem(AC_Item *arg);

/*}}}  */
/*{{{  term conversion functions */

AC_Script AC_ScriptFromTerm(ATerm t);
ATerm AC_ScriptToTerm(AC_Script arg);
AC_Actions AC_ActionsFromTerm(ATerm t);
ATerm AC_ActionsToTerm(AC_Actions arg);
AC_Action AC_ActionFromTerm(ATerm t);
ATerm AC_ActionToTerm(AC_Action arg);
AC_Signature AC_SignatureFromTerm(ATerm t);
ATerm AC_SignatureToTerm(AC_Signature arg);
AC_Descriptions AC_DescriptionsFromTerm(ATerm t);
ATerm AC_DescriptionsToTerm(AC_Descriptions arg);
AC_Description AC_DescriptionFromTerm(ATerm t);
ATerm AC_DescriptionToTerm(AC_Description arg);
AC_Args AC_ArgsFromTerm(ATerm t);
ATerm AC_ArgsToTerm(AC_Args arg);
AC_Arg AC_ArgFromTerm(ATerm t);
ATerm AC_ArgToTerm(AC_Arg arg);
AC_Message AC_MessageFromTerm(ATerm t);
ATerm AC_MessageToTerm(AC_Message arg);
AC_Stack AC_StackFromTerm(ATerm t);
ATerm AC_StackToTerm(AC_Stack arg);
AC_Item AC_ItemFromTerm(ATerm t);
ATerm AC_ItemToTerm(AC_Item arg);

/*}}}  */
/*{{{  list functions */

int AC_getActionsLength (AC_Actions arg);
AC_Actions AC_reverseActions(AC_Actions arg);
AC_Actions AC_appendActions(AC_Actions arg, AC_Action elem);
AC_Actions AC_concatActions(AC_Actions arg0, AC_Actions arg1);
AC_Actions AC_sliceActions(AC_Actions arg, int start, int end);
AC_Action AC_getActionsActionAt(AC_Actions arg, int index);
AC_Actions AC_replaceActionsActionAt(AC_Actions arg, AC_Action elem, int index);
AC_Actions AC_makeActions2(AC_Action elem1, AC_Action elem2);
AC_Actions AC_makeActions3(AC_Action elem1, AC_Action elem2, AC_Action elem3);
AC_Actions AC_makeActions4(AC_Action elem1, AC_Action elem2, AC_Action elem3, AC_Action elem4);
AC_Actions AC_makeActions5(AC_Action elem1, AC_Action elem2, AC_Action elem3, AC_Action elem4, AC_Action elem5);
AC_Actions AC_makeActions6(AC_Action elem1, AC_Action elem2, AC_Action elem3, AC_Action elem4, AC_Action elem5, AC_Action elem6);
int AC_getDescriptionsLength (AC_Descriptions arg);
AC_Descriptions AC_reverseDescriptions(AC_Descriptions arg);
AC_Descriptions AC_appendDescriptions(AC_Descriptions arg, AC_Description elem);
AC_Descriptions AC_concatDescriptions(AC_Descriptions arg0, AC_Descriptions arg1);
AC_Descriptions AC_sliceDescriptions(AC_Descriptions arg, int start, int end);
AC_Description AC_getDescriptionsDescriptionAt(AC_Descriptions arg, int index);
AC_Descriptions AC_replaceDescriptionsDescriptionAt(AC_Descriptions arg, AC_Description elem, int index);
AC_Descriptions AC_makeDescriptions2(AC_Description elem1, AC_Description elem2);
AC_Descriptions AC_makeDescriptions3(AC_Description elem1, AC_Description elem2, AC_Description elem3);
AC_Descriptions AC_makeDescriptions4(AC_Description elem1, AC_Description elem2, AC_Description elem3, AC_Description elem4);
AC_Descriptions AC_makeDescriptions5(AC_Description elem1, AC_Description elem2, AC_Description elem3, AC_Description elem4, AC_Description elem5);
AC_Descriptions AC_makeDescriptions6(AC_Description elem1, AC_Description elem2, AC_Description elem3, AC_Description elem4, AC_Description elem5, AC_Description elem6);
int AC_getArgsLength (AC_Args arg);
AC_Args AC_reverseArgs(AC_Args arg);
AC_Args AC_appendArgs(AC_Args arg, AC_Arg elem);
AC_Args AC_concatArgs(AC_Args arg0, AC_Args arg1);
AC_Args AC_sliceArgs(AC_Args arg, int start, int end);
AC_Arg AC_getArgsArgAt(AC_Args arg, int index);
AC_Args AC_replaceArgsArgAt(AC_Args arg, AC_Arg elem, int index);
AC_Args AC_makeArgs2(AC_Arg elem1, AC_Arg elem2);
AC_Args AC_makeArgs3(AC_Arg elem1, AC_Arg elem2, AC_Arg elem3);
AC_Args AC_makeArgs4(AC_Arg elem1, AC_Arg elem2, AC_Arg elem3, AC_Arg elem4);
AC_Args AC_makeArgs5(AC_Arg elem1, AC_Arg elem2, AC_Arg elem3, AC_Arg elem4, AC_Arg elem5);
AC_Args AC_makeArgs6(AC_Arg elem1, AC_Arg elem2, AC_Arg elem3, AC_Arg elem4, AC_Arg elem5, AC_Arg elem6);
int AC_getStackLength (AC_Stack arg);
AC_Stack AC_reverseStack(AC_Stack arg);
AC_Stack AC_appendStack(AC_Stack arg, AC_Item elem);
AC_Stack AC_concatStack(AC_Stack arg0, AC_Stack arg1);
AC_Stack AC_sliceStack(AC_Stack arg, int start, int end);
AC_Item AC_getStackItemAt(AC_Stack arg, int index);
AC_Stack AC_replaceStackItemAt(AC_Stack arg, AC_Item elem, int index);
AC_Stack AC_makeStack2(AC_Item elem1, AC_Item elem2);
AC_Stack AC_makeStack3(AC_Item elem1, AC_Item elem2, AC_Item elem3);
AC_Stack AC_makeStack4(AC_Item elem1, AC_Item elem2, AC_Item elem3, AC_Item elem4);
AC_Stack AC_makeStack5(AC_Item elem1, AC_Item elem2, AC_Item elem3, AC_Item elem4, AC_Item elem5);
AC_Stack AC_makeStack6(AC_Item elem1, AC_Item elem2, AC_Item elem3, AC_Item elem4, AC_Item elem5, AC_Item elem6);

/*}}}  */
/*{{{  constructors */

AC_Script AC_makeScriptList(AC_Actions list);
AC_Actions AC_makeActionsEmpty(void);
AC_Actions AC_makeActionsSingle(AC_Action head);
AC_Actions AC_makeActionsMany(AC_Action head, AC_Actions tail);
AC_Action AC_makeActionDup(void);
AC_Action AC_makeActionPop(void);
AC_Action AC_makeActionPushString(const char* string);
AC_Action AC_makeActionApply(const char* functionName, const char* resultSort, int argumentsNumber);
AC_Action AC_makeActionPushTerm(ATerm term);
AC_Action AC_makeActionPushFilename(const char* string);
AC_Action AC_makeActionPushModulename(const char* string);
AC_Action AC_makeActionCondition(AC_Actions thenList, AC_Actions elseList);
AC_Action AC_makeActionGeneric(ATerm name);
AC_Signature AC_makeSignatureList(AC_Descriptions list);
AC_Descriptions AC_makeDescriptionsEmpty(void);
AC_Descriptions AC_makeDescriptionsSingle(AC_Description head);
AC_Descriptions AC_makeDescriptionsMany(AC_Description head, AC_Descriptions tail);
AC_Description AC_makeDescriptionAction(ATerm name, AC_Args arguments);
AC_Args AC_makeArgsEmpty(void);
AC_Args AC_makeArgsSingle(AC_Arg head);
AC_Args AC_makeArgsMany(AC_Arg head, AC_Args tail);
AC_Arg AC_makeArgString(void);
AC_Arg AC_makeArgTree(void);
AC_Message AC_makeMessagePromptForFile(const char* title, const char* path, const char* modulename);
AC_Message AC_makeMessageEditTerm(const char* filename, const char* modulename);
AC_Stack AC_makeStackEmpty(void);
AC_Stack AC_makeStackSingle(AC_Item head);
AC_Stack AC_makeStackMany(AC_Item head, AC_Stack tail);
AC_Item AC_makeItemString(const char* string);

/*}}}  */
/*{{{  equality functions */

ATbool AC_isEqualScript(AC_Script arg0, AC_Script arg1);
ATbool AC_isEqualActions(AC_Actions arg0, AC_Actions arg1);
ATbool AC_isEqualAction(AC_Action arg0, AC_Action arg1);
ATbool AC_isEqualSignature(AC_Signature arg0, AC_Signature arg1);
ATbool AC_isEqualDescriptions(AC_Descriptions arg0, AC_Descriptions arg1);
ATbool AC_isEqualDescription(AC_Description arg0, AC_Description arg1);
ATbool AC_isEqualArgs(AC_Args arg0, AC_Args arg1);
ATbool AC_isEqualArg(AC_Arg arg0, AC_Arg arg1);
ATbool AC_isEqualMessage(AC_Message arg0, AC_Message arg1);
ATbool AC_isEqualStack(AC_Stack arg0, AC_Stack arg1);
ATbool AC_isEqualItem(AC_Item arg0, AC_Item arg1);

/*}}}  */
/*{{{  AC_Script accessors */

ATbool AC_isValidScript(AC_Script arg);
inline ATbool AC_isScriptList(AC_Script arg);
ATbool AC_hasScriptList(AC_Script arg);
AC_Actions AC_getScriptList(AC_Script arg);
AC_Script AC_setScriptList(AC_Script arg, AC_Actions list);

/*}}}  */
/*{{{  AC_Actions accessors */

ATbool AC_isValidActions(AC_Actions arg);
inline ATbool AC_isActionsEmpty(AC_Actions arg);
inline ATbool AC_isActionsSingle(AC_Actions arg);
inline ATbool AC_isActionsMany(AC_Actions arg);
ATbool AC_hasActionsHead(AC_Actions arg);
ATbool AC_hasActionsTail(AC_Actions arg);
AC_Action AC_getActionsHead(AC_Actions arg);
AC_Actions AC_getActionsTail(AC_Actions arg);
AC_Actions AC_setActionsHead(AC_Actions arg, AC_Action head);
AC_Actions AC_setActionsTail(AC_Actions arg, AC_Actions tail);

/*}}}  */
/*{{{  AC_Action accessors */

ATbool AC_isValidAction(AC_Action arg);
inline ATbool AC_isActionDup(AC_Action arg);
inline ATbool AC_isActionPop(AC_Action arg);
inline ATbool AC_isActionPushString(AC_Action arg);
inline ATbool AC_isActionApply(AC_Action arg);
inline ATbool AC_isActionPushTerm(AC_Action arg);
inline ATbool AC_isActionPushFilename(AC_Action arg);
inline ATbool AC_isActionPushModulename(AC_Action arg);
inline ATbool AC_isActionCondition(AC_Action arg);
inline ATbool AC_isActionGeneric(AC_Action arg);
ATbool AC_hasActionString(AC_Action arg);
ATbool AC_hasActionFunctionName(AC_Action arg);
ATbool AC_hasActionResultSort(AC_Action arg);
ATbool AC_hasActionArgumentsNumber(AC_Action arg);
ATbool AC_hasActionTerm(AC_Action arg);
ATbool AC_hasActionThenList(AC_Action arg);
ATbool AC_hasActionElseList(AC_Action arg);
ATbool AC_hasActionName(AC_Action arg);
char* AC_getActionString(AC_Action arg);
char* AC_getActionFunctionName(AC_Action arg);
char* AC_getActionResultSort(AC_Action arg);
int AC_getActionArgumentsNumber(AC_Action arg);
ATerm AC_getActionTerm(AC_Action arg);
AC_Actions AC_getActionThenList(AC_Action arg);
AC_Actions AC_getActionElseList(AC_Action arg);
ATerm AC_getActionName(AC_Action arg);
AC_Action AC_setActionString(AC_Action arg, const char* string);
AC_Action AC_setActionFunctionName(AC_Action arg, const char* functionName);
AC_Action AC_setActionResultSort(AC_Action arg, const char* resultSort);
AC_Action AC_setActionArgumentsNumber(AC_Action arg, int argumentsNumber);
AC_Action AC_setActionTerm(AC_Action arg, ATerm term);
AC_Action AC_setActionThenList(AC_Action arg, AC_Actions thenList);
AC_Action AC_setActionElseList(AC_Action arg, AC_Actions elseList);
AC_Action AC_setActionName(AC_Action arg, ATerm name);

/*}}}  */
/*{{{  AC_Signature accessors */

ATbool AC_isValidSignature(AC_Signature arg);
inline ATbool AC_isSignatureList(AC_Signature arg);
ATbool AC_hasSignatureList(AC_Signature arg);
AC_Descriptions AC_getSignatureList(AC_Signature arg);
AC_Signature AC_setSignatureList(AC_Signature arg, AC_Descriptions list);

/*}}}  */
/*{{{  AC_Descriptions accessors */

ATbool AC_isValidDescriptions(AC_Descriptions arg);
inline ATbool AC_isDescriptionsEmpty(AC_Descriptions arg);
inline ATbool AC_isDescriptionsSingle(AC_Descriptions arg);
inline ATbool AC_isDescriptionsMany(AC_Descriptions arg);
ATbool AC_hasDescriptionsHead(AC_Descriptions arg);
ATbool AC_hasDescriptionsTail(AC_Descriptions arg);
AC_Description AC_getDescriptionsHead(AC_Descriptions arg);
AC_Descriptions AC_getDescriptionsTail(AC_Descriptions arg);
AC_Descriptions AC_setDescriptionsHead(AC_Descriptions arg, AC_Description head);
AC_Descriptions AC_setDescriptionsTail(AC_Descriptions arg, AC_Descriptions tail);

/*}}}  */
/*{{{  AC_Description accessors */

ATbool AC_isValidDescription(AC_Description arg);
inline ATbool AC_isDescriptionAction(AC_Description arg);
ATbool AC_hasDescriptionName(AC_Description arg);
ATbool AC_hasDescriptionArguments(AC_Description arg);
ATerm AC_getDescriptionName(AC_Description arg);
AC_Args AC_getDescriptionArguments(AC_Description arg);
AC_Description AC_setDescriptionName(AC_Description arg, ATerm name);
AC_Description AC_setDescriptionArguments(AC_Description arg, AC_Args arguments);

/*}}}  */
/*{{{  AC_Args accessors */

ATbool AC_isValidArgs(AC_Args arg);
inline ATbool AC_isArgsEmpty(AC_Args arg);
inline ATbool AC_isArgsSingle(AC_Args arg);
inline ATbool AC_isArgsMany(AC_Args arg);
ATbool AC_hasArgsHead(AC_Args arg);
ATbool AC_hasArgsTail(AC_Args arg);
AC_Arg AC_getArgsHead(AC_Args arg);
AC_Args AC_getArgsTail(AC_Args arg);
AC_Args AC_setArgsHead(AC_Args arg, AC_Arg head);
AC_Args AC_setArgsTail(AC_Args arg, AC_Args tail);

/*}}}  */
/*{{{  AC_Arg accessors */

ATbool AC_isValidArg(AC_Arg arg);
inline ATbool AC_isArgString(AC_Arg arg);
inline ATbool AC_isArgTree(AC_Arg arg);

/*}}}  */
/*{{{  AC_Message accessors */

ATbool AC_isValidMessage(AC_Message arg);
inline ATbool AC_isMessagePromptForFile(AC_Message arg);
inline ATbool AC_isMessageEditTerm(AC_Message arg);
ATbool AC_hasMessageTitle(AC_Message arg);
ATbool AC_hasMessagePath(AC_Message arg);
ATbool AC_hasMessageModulename(AC_Message arg);
ATbool AC_hasMessageFilename(AC_Message arg);
char* AC_getMessageTitle(AC_Message arg);
char* AC_getMessagePath(AC_Message arg);
char* AC_getMessageModulename(AC_Message arg);
char* AC_getMessageFilename(AC_Message arg);
AC_Message AC_setMessageTitle(AC_Message arg, const char* title);
AC_Message AC_setMessagePath(AC_Message arg, const char* path);
AC_Message AC_setMessageModulename(AC_Message arg, const char* modulename);
AC_Message AC_setMessageFilename(AC_Message arg, const char* filename);

/*}}}  */
/*{{{  AC_Stack accessors */

ATbool AC_isValidStack(AC_Stack arg);
inline ATbool AC_isStackEmpty(AC_Stack arg);
inline ATbool AC_isStackSingle(AC_Stack arg);
inline ATbool AC_isStackMany(AC_Stack arg);
ATbool AC_hasStackHead(AC_Stack arg);
ATbool AC_hasStackTail(AC_Stack arg);
AC_Item AC_getStackHead(AC_Stack arg);
AC_Stack AC_getStackTail(AC_Stack arg);
AC_Stack AC_setStackHead(AC_Stack arg, AC_Item head);
AC_Stack AC_setStackTail(AC_Stack arg, AC_Stack tail);

/*}}}  */
/*{{{  AC_Item accessors */

ATbool AC_isValidItem(AC_Item arg);
inline ATbool AC_isItemString(AC_Item arg);
ATbool AC_hasItemString(AC_Item arg);
char* AC_getItemString(AC_Item arg);
AC_Item AC_setItemString(AC_Item arg, const char* string);

/*}}}  */
/*{{{  sort visitors */

AC_Script AC_visitScript(AC_Script arg, AC_Actions (*acceptList)(AC_Actions));
AC_Actions AC_visitActions(AC_Actions arg, AC_Action (*acceptHead)(AC_Action));
AC_Action AC_visitAction(AC_Action arg, char* (*acceptString)(char*), char* (*acceptFunctionName)(char*), char* (*acceptResultSort)(char*), int (*acceptArgumentsNumber)(int), ATerm (*acceptTerm)(ATerm), AC_Actions (*acceptThenList)(AC_Actions), AC_Actions (*acceptElseList)(AC_Actions), ATerm (*acceptName)(ATerm));
AC_Signature AC_visitSignature(AC_Signature arg, AC_Descriptions (*acceptList)(AC_Descriptions));
AC_Descriptions AC_visitDescriptions(AC_Descriptions arg, AC_Description (*acceptHead)(AC_Description));
AC_Description AC_visitDescription(AC_Description arg, ATerm (*acceptName)(ATerm), AC_Args (*acceptArguments)(AC_Args));
AC_Args AC_visitArgs(AC_Args arg, AC_Arg (*acceptHead)(AC_Arg));
AC_Arg AC_visitArg(AC_Arg arg);
AC_Message AC_visitMessage(AC_Message arg, char* (*acceptTitle)(char*), char* (*acceptPath)(char*), char* (*acceptModulename)(char*), char* (*acceptFilename)(char*));
AC_Stack AC_visitStack(AC_Stack arg, AC_Item (*acceptHead)(AC_Item));
AC_Item AC_visitItem(AC_Item arg, char* (*acceptString)(char*));

/*}}}  */

#endif /* _ACTIONS_H */
