#ifndef _TEXTEDITOR_H
#define _TEXTEDITOR_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "TextEditor_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _TE_Action *TE_Action;
typedef struct _TE_Menu *TE_Menu;
typedef struct _TE_ActionList *TE_ActionList;
typedef struct _TE_Items *TE_Items;
typedef struct _TE_Event *TE_Event;
typedef struct _TE_Process *TE_Process;
typedef struct _TE_Pipe *TE_Pipe;

/*}}}  */

void TE_initTextEditorApi(void);

/*{{{  protect functions */

void TE_protectAction(TE_Action *arg);
void TE_protectMenu(TE_Menu *arg);
void TE_protectActionList(TE_ActionList *arg);
void TE_protectItems(TE_Items *arg);
void TE_protectEvent(TE_Event *arg);
void TE_protectProcess(TE_Process *arg);
void TE_protectPipe(TE_Pipe *arg);

/*}}}  */
/*{{{  term conversion functions */

TE_Action TE_ActionFromTerm(ATerm t);
ATerm TE_ActionToTerm(TE_Action arg);
TE_Menu TE_MenuFromTerm(ATerm t);
ATerm TE_MenuToTerm(TE_Menu arg);
TE_ActionList TE_ActionListFromTerm(ATerm t);
ATerm TE_ActionListToTerm(TE_ActionList arg);
TE_Items TE_ItemsFromTerm(ATerm t);
ATerm TE_ItemsToTerm(TE_Items arg);
TE_Event TE_EventFromTerm(ATerm t);
ATerm TE_EventToTerm(TE_Event arg);
TE_Process TE_ProcessFromTerm(ATerm t);
ATerm TE_ProcessToTerm(TE_Process arg);
TE_Pipe TE_PipeFromTerm(ATerm t);
ATerm TE_PipeToTerm(TE_Pipe arg);

/*}}}  */
/*{{{  list functions */

int TE_getActionListLength (TE_ActionList arg);
TE_ActionList TE_reverseActionList(TE_ActionList arg);
TE_ActionList TE_appendActionList(TE_ActionList arg, TE_Menu elem);
TE_ActionList TE_concatActionList(TE_ActionList arg0, TE_ActionList arg1);
TE_ActionList TE_sliceActionList(TE_ActionList arg, int start, int end);
TE_Menu TE_getActionListMenuAt(TE_ActionList arg, int index);
TE_ActionList TE_replaceActionListMenuAt(TE_ActionList arg, TE_Menu elem, int index);
TE_ActionList TE_makeActionList2(TE_Menu elem1, TE_Menu elem2);
TE_ActionList TE_makeActionList3(TE_Menu elem1, TE_Menu elem2, TE_Menu elem3);
TE_ActionList TE_makeActionList4(TE_Menu elem1, TE_Menu elem2, TE_Menu elem3, TE_Menu elem4);
TE_ActionList TE_makeActionList5(TE_Menu elem1, TE_Menu elem2, TE_Menu elem3, TE_Menu elem4, TE_Menu elem5);
TE_ActionList TE_makeActionList6(TE_Menu elem1, TE_Menu elem2, TE_Menu elem3, TE_Menu elem4, TE_Menu elem5, TE_Menu elem6);
int TE_getItemsLength (TE_Items arg);
TE_Items TE_reverseItems(TE_Items arg);
TE_Items TE_appendItems(TE_Items arg, char* elem);
TE_Items TE_concatItems(TE_Items arg0, TE_Items arg1);
TE_Items TE_sliceItems(TE_Items arg, int start, int end);
char* TE_getItemsstrAt(TE_Items arg, int index);
TE_Items TE_replaceItemsstrAt(TE_Items arg, char* elem, int index);
TE_Items TE_makeItems2(char* elem1, char* elem2);
TE_Items TE_makeItems3(char* elem1, char* elem2, char* elem3);
TE_Items TE_makeItems4(char* elem1, char* elem2, char* elem3, char* elem4);
TE_Items TE_makeItems5(char* elem1, char* elem2, char* elem3, char* elem4, char* elem5);
TE_Items TE_makeItems6(char* elem1, char* elem2, char* elem3, char* elem4, char* elem5, char* elem6);

/*}}}  */
/*{{{  constructors */

TE_Action TE_makeActionToFront(void);
TE_Action TE_makeActionQuit(void);
TE_Action TE_makeActionWriteContents(void);
TE_Action TE_makeActionRereadContents(void);
TE_Action TE_makeActionGetContents(void);
TE_Action TE_makeActionDisplayMessage(const char* message);
TE_Action TE_makeActionSetCursorAtOffset(int offset);
TE_Action TE_makeActionSetFocus(ATerm focus);
TE_Action TE_makeActionClearFocus(void);
TE_Action TE_makeActionSetActions(TE_ActionList actions);
TE_Menu TE_makeMenuDefault(TE_Items items);
TE_Menu TE_makeMenuShortcut(TE_Items items, const char* shortcut);
TE_ActionList TE_makeActionListEmpty(void);
TE_ActionList TE_makeActionListSingle(TE_Menu head);
TE_ActionList TE_makeActionListMany(TE_Menu head, TE_ActionList tail);
TE_Items TE_makeItemsEmpty(void);
TE_Items TE_makeItemsSingle(const char* head);
TE_Items TE_makeItemsMany(const char* head, TE_Items tail);
TE_Event TE_makeEventMenu(TE_Menu menu);
TE_Event TE_makeEventMouse(int location);
TE_Event TE_makeEventContents(const char* text);
TE_Event TE_makeEventModified(void);
TE_Process TE_makeProcessDefault(TE_Pipe toChild, TE_Pipe fromChild);
TE_Pipe TE_makePipeDefault(int read, int write);

/*}}}  */
/*{{{  equality functions */

ATbool TE_isEqualAction(TE_Action arg0, TE_Action arg1);
ATbool TE_isEqualMenu(TE_Menu arg0, TE_Menu arg1);
ATbool TE_isEqualActionList(TE_ActionList arg0, TE_ActionList arg1);
ATbool TE_isEqualItems(TE_Items arg0, TE_Items arg1);
ATbool TE_isEqualEvent(TE_Event arg0, TE_Event arg1);
ATbool TE_isEqualProcess(TE_Process arg0, TE_Process arg1);
ATbool TE_isEqualPipe(TE_Pipe arg0, TE_Pipe arg1);

/*}}}  */
/*{{{  TE_Action accessors */

ATbool TE_isValidAction(TE_Action arg);
inline ATbool TE_isActionToFront(TE_Action arg);
inline ATbool TE_isActionQuit(TE_Action arg);
inline ATbool TE_isActionWriteContents(TE_Action arg);
inline ATbool TE_isActionRereadContents(TE_Action arg);
inline ATbool TE_isActionGetContents(TE_Action arg);
inline ATbool TE_isActionDisplayMessage(TE_Action arg);
inline ATbool TE_isActionSetCursorAtOffset(TE_Action arg);
inline ATbool TE_isActionSetFocus(TE_Action arg);
inline ATbool TE_isActionClearFocus(TE_Action arg);
inline ATbool TE_isActionSetActions(TE_Action arg);
ATbool TE_hasActionMessage(TE_Action arg);
char* TE_getActionMessage(TE_Action arg);
TE_Action TE_setActionMessage(TE_Action arg, const char* message);
ATbool TE_hasActionOffset(TE_Action arg);
int TE_getActionOffset(TE_Action arg);
TE_Action TE_setActionOffset(TE_Action arg, int offset);
ATbool TE_hasActionFocus(TE_Action arg);
ATerm TE_getActionFocus(TE_Action arg);
TE_Action TE_setActionFocus(TE_Action arg, ATerm focus);
ATbool TE_hasActionActions(TE_Action arg);
TE_ActionList TE_getActionActions(TE_Action arg);
TE_Action TE_setActionActions(TE_Action arg, TE_ActionList actions);

/*}}}  */
/*{{{  TE_Menu accessors */

ATbool TE_isValidMenu(TE_Menu arg);
inline ATbool TE_isMenuDefault(TE_Menu arg);
inline ATbool TE_isMenuShortcut(TE_Menu arg);
ATbool TE_hasMenuItems(TE_Menu arg);
TE_Items TE_getMenuItems(TE_Menu arg);
TE_Menu TE_setMenuItems(TE_Menu arg, TE_Items items);
ATbool TE_hasMenuShortcut(TE_Menu arg);
char* TE_getMenuShortcut(TE_Menu arg);
TE_Menu TE_setMenuShortcut(TE_Menu arg, const char* shortcut);

/*}}}  */
/*{{{  TE_ActionList accessors */

ATbool TE_isValidActionList(TE_ActionList arg);
inline ATbool TE_isActionListEmpty(TE_ActionList arg);
inline ATbool TE_isActionListSingle(TE_ActionList arg);
inline ATbool TE_isActionListMany(TE_ActionList arg);
ATbool TE_hasActionListHead(TE_ActionList arg);
TE_Menu TE_getActionListHead(TE_ActionList arg);
TE_ActionList TE_setActionListHead(TE_ActionList arg, TE_Menu head);
ATbool TE_hasActionListTail(TE_ActionList arg);
TE_ActionList TE_getActionListTail(TE_ActionList arg);
TE_ActionList TE_setActionListTail(TE_ActionList arg, TE_ActionList tail);

/*}}}  */
/*{{{  TE_Items accessors */

ATbool TE_isValidItems(TE_Items arg);
inline ATbool TE_isItemsEmpty(TE_Items arg);
inline ATbool TE_isItemsSingle(TE_Items arg);
inline ATbool TE_isItemsMany(TE_Items arg);
ATbool TE_hasItemsHead(TE_Items arg);
char* TE_getItemsHead(TE_Items arg);
TE_Items TE_setItemsHead(TE_Items arg, const char* head);
ATbool TE_hasItemsTail(TE_Items arg);
TE_Items TE_getItemsTail(TE_Items arg);
TE_Items TE_setItemsTail(TE_Items arg, TE_Items tail);

/*}}}  */
/*{{{  TE_Event accessors */

ATbool TE_isValidEvent(TE_Event arg);
inline ATbool TE_isEventMenu(TE_Event arg);
inline ATbool TE_isEventMouse(TE_Event arg);
inline ATbool TE_isEventContents(TE_Event arg);
inline ATbool TE_isEventModified(TE_Event arg);
ATbool TE_hasEventMenu(TE_Event arg);
TE_Menu TE_getEventMenu(TE_Event arg);
TE_Event TE_setEventMenu(TE_Event arg, TE_Menu menu);
ATbool TE_hasEventLocation(TE_Event arg);
int TE_getEventLocation(TE_Event arg);
TE_Event TE_setEventLocation(TE_Event arg, int location);
ATbool TE_hasEventText(TE_Event arg);
char* TE_getEventText(TE_Event arg);
TE_Event TE_setEventText(TE_Event arg, const char* text);

/*}}}  */
/*{{{  TE_Process accessors */

ATbool TE_isValidProcess(TE_Process arg);
inline ATbool TE_isProcessDefault(TE_Process arg);
ATbool TE_hasProcessToChild(TE_Process arg);
TE_Pipe TE_getProcessToChild(TE_Process arg);
TE_Process TE_setProcessToChild(TE_Process arg, TE_Pipe toChild);
ATbool TE_hasProcessFromChild(TE_Process arg);
TE_Pipe TE_getProcessFromChild(TE_Process arg);
TE_Process TE_setProcessFromChild(TE_Process arg, TE_Pipe fromChild);

/*}}}  */
/*{{{  TE_Pipe accessors */

ATbool TE_isValidPipe(TE_Pipe arg);
inline ATbool TE_isPipeDefault(TE_Pipe arg);
ATbool TE_hasPipeRead(TE_Pipe arg);
int TE_getPipeRead(TE_Pipe arg);
TE_Pipe TE_setPipeRead(TE_Pipe arg, int read);
ATbool TE_hasPipeWrite(TE_Pipe arg);
int TE_getPipeWrite(TE_Pipe arg);
TE_Pipe TE_setPipeWrite(TE_Pipe arg, int write);

/*}}}  */
/*{{{  sort visitors */

TE_Action TE_visitAction(TE_Action arg, char* (*acceptMessage)(char*), int (*acceptOffset)(int), ATerm (*acceptFocus)(ATerm), TE_ActionList (*acceptActions)(TE_ActionList));
TE_Menu TE_visitMenu(TE_Menu arg, TE_Items (*acceptItems)(TE_Items), char* (*acceptShortcut)(char*));
TE_ActionList TE_visitActionList(TE_ActionList arg, TE_Menu (*acceptHead)(TE_Menu));
TE_Items TE_visitItems(TE_Items arg, char* (*acceptHead)(char*));
TE_Event TE_visitEvent(TE_Event arg, TE_Menu (*acceptMenu)(TE_Menu), int (*acceptLocation)(int), char* (*acceptText)(char*));
TE_Process TE_visitProcess(TE_Process arg, TE_Pipe (*acceptToChild)(TE_Pipe), TE_Pipe (*acceptFromChild)(TE_Pipe));
TE_Pipe TE_visitPipe(TE_Pipe arg, int (*acceptRead)(int), int (*acceptWrite)(int));

/*}}}  */

#endif /* _TEXTEDITOR_H */
