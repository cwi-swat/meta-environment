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
typedef struct _TE_ActionList *TE_ActionList;
typedef struct _TE_Menu *TE_Menu;
typedef struct _TE_Event *TE_Event;
typedef struct _TE_Process *TE_Process;
typedef struct _TE_Pipe *TE_Pipe;

/*}}}  */

void TE_initTextEditorApi(void);

/*{{{  protect functions */

void TE_protectAction(TE_Action *arg);
void TE_protectActionList(TE_ActionList *arg);
void TE_protectMenu(TE_Menu *arg);
void TE_protectEvent(TE_Event *arg);
void TE_protectProcess(TE_Process *arg);
void TE_protectPipe(TE_Pipe *arg);

/*}}}  */
/*{{{  term conversion functions */

TE_Action TE_ActionFromTerm(ATerm t);
ATerm TE_ActionToTerm(TE_Action arg);
TE_ActionList TE_ActionListFromTerm(ATerm t);
ATerm TE_ActionListToTerm(TE_ActionList arg);
TE_Menu TE_MenuFromTerm(ATerm t);
ATerm TE_MenuToTerm(TE_Menu arg);
TE_Event TE_EventFromTerm(ATerm t);
ATerm TE_EventToTerm(TE_Event arg);
TE_Process TE_ProcessFromTerm(ATerm t);
ATerm TE_ProcessToTerm(TE_Process arg);
TE_Pipe TE_PipeFromTerm(ATerm t);
ATerm TE_PipeToTerm(TE_Pipe arg);

/*}}}  */
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */

TE_Action TE_makeActionToFront(void);
TE_Action TE_makeActionWriteContents(void);
TE_Action TE_makeActionRereadContents(void);
TE_Action TE_makeActionGetContents(void);
TE_Action TE_makeActionDisplayMessage(const char* message);
TE_Action TE_makeActionSetCursorAtOffset(int offset);
TE_Action TE_makeActionSetFocusAtArea(ATerm area);
TE_Action TE_makeActionClearFocus(void);
TE_Action TE_makeActionSetFocus(ATerm focus, const char* sort);
TE_Action TE_makeActionSetActions(TE_ActionList actions);
TE_ActionList TE_makeActionListEmpty(void);
TE_ActionList TE_makeActionListMulti(TE_Menu head, TE_ActionList tail);
TE_Menu TE_makeMenuDefault(const char* main, const char* sub);
TE_Menu TE_makeMenuShortcut(const char* main, const char* sub, const char* shortcut);
TE_Event TE_makeEventMenu(TE_Menu menu);
TE_Event TE_makeEventMouse(int location);
TE_Event TE_makeEventContents(const char* text);
TE_Event TE_makeEventModified(void);
TE_Process TE_makeProcessDefault(TE_Pipe toChild, TE_Pipe fromChild);
TE_Pipe TE_makePipeDefault(int read, int write);

/*}}}  */
/*{{{  equality functions */

ATbool TE_isEqualAction(TE_Action arg0, TE_Action arg1);
ATbool TE_isEqualActionList(TE_ActionList arg0, TE_ActionList arg1);
ATbool TE_isEqualMenu(TE_Menu arg0, TE_Menu arg1);
ATbool TE_isEqualEvent(TE_Event arg0, TE_Event arg1);
ATbool TE_isEqualProcess(TE_Process arg0, TE_Process arg1);
ATbool TE_isEqualPipe(TE_Pipe arg0, TE_Pipe arg1);

/*}}}  */
/*{{{  TE_Action accessors */

ATbool TE_isValidAction(TE_Action arg);
inline ATbool TE_isActionToFront(TE_Action arg);
inline ATbool TE_isActionWriteContents(TE_Action arg);
inline ATbool TE_isActionRereadContents(TE_Action arg);
inline ATbool TE_isActionGetContents(TE_Action arg);
inline ATbool TE_isActionDisplayMessage(TE_Action arg);
inline ATbool TE_isActionSetCursorAtOffset(TE_Action arg);
inline ATbool TE_isActionSetFocusAtArea(TE_Action arg);
inline ATbool TE_isActionClearFocus(TE_Action arg);
inline ATbool TE_isActionSetFocus(TE_Action arg);
inline ATbool TE_isActionSetActions(TE_Action arg);
ATbool TE_hasActionMessage(TE_Action arg);
char* TE_getActionMessage(TE_Action arg);
TE_Action TE_setActionMessage(TE_Action arg, const char* message);
ATbool TE_hasActionOffset(TE_Action arg);
int TE_getActionOffset(TE_Action arg);
TE_Action TE_setActionOffset(TE_Action arg, int offset);
ATbool TE_hasActionArea(TE_Action arg);
ATerm TE_getActionArea(TE_Action arg);
TE_Action TE_setActionArea(TE_Action arg, ATerm area);
ATbool TE_hasActionFocus(TE_Action arg);
ATerm TE_getActionFocus(TE_Action arg);
TE_Action TE_setActionFocus(TE_Action arg, ATerm focus);
ATbool TE_hasActionSort(TE_Action arg);
char* TE_getActionSort(TE_Action arg);
TE_Action TE_setActionSort(TE_Action arg, const char* sort);
ATbool TE_hasActionActions(TE_Action arg);
TE_ActionList TE_getActionActions(TE_Action arg);
TE_Action TE_setActionActions(TE_Action arg, TE_ActionList actions);

/*}}}  */
/*{{{  TE_ActionList accessors */

ATbool TE_isValidActionList(TE_ActionList arg);
inline ATbool TE_isActionListEmpty(TE_ActionList arg);
inline ATbool TE_isActionListMulti(TE_ActionList arg);
ATbool TE_hasActionListHead(TE_ActionList arg);
TE_Menu TE_getActionListHead(TE_ActionList arg);
TE_ActionList TE_setActionListHead(TE_ActionList arg, TE_Menu head);
ATbool TE_hasActionListTail(TE_ActionList arg);
TE_ActionList TE_getActionListTail(TE_ActionList arg);
TE_ActionList TE_setActionListTail(TE_ActionList arg, TE_ActionList tail);

/*}}}  */
/*{{{  TE_Menu accessors */

ATbool TE_isValidMenu(TE_Menu arg);
inline ATbool TE_isMenuDefault(TE_Menu arg);
inline ATbool TE_isMenuShortcut(TE_Menu arg);
ATbool TE_hasMenuMain(TE_Menu arg);
char* TE_getMenuMain(TE_Menu arg);
TE_Menu TE_setMenuMain(TE_Menu arg, const char* main);
ATbool TE_hasMenuSub(TE_Menu arg);
char* TE_getMenuSub(TE_Menu arg);
TE_Menu TE_setMenuSub(TE_Menu arg, const char* sub);
ATbool TE_hasMenuShortcut(TE_Menu arg);
char* TE_getMenuShortcut(TE_Menu arg);
TE_Menu TE_setMenuShortcut(TE_Menu arg, const char* shortcut);

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

TE_Action TE_visitAction(TE_Action arg, char* (*acceptMessage)(char*), int (*acceptOffset)(int), ATerm (*acceptArea)(ATerm), ATerm (*acceptFocus)(ATerm), char* (*acceptSort)(char*), TE_ActionList (*acceptActions)(TE_ActionList));
TE_ActionList TE_visitActionList(TE_ActionList arg, TE_Menu (*acceptHead)(TE_Menu));
TE_Menu TE_visitMenu(TE_Menu arg, char* (*acceptMain)(char*), char* (*acceptSub)(char*), char* (*acceptShortcut)(char*));
TE_Event TE_visitEvent(TE_Event arg, TE_Menu (*acceptMenu)(TE_Menu), int (*acceptLocation)(int), char* (*acceptText)(char*));
TE_Process TE_visitProcess(TE_Process arg, TE_Pipe (*acceptToChild)(TE_Pipe), TE_Pipe (*acceptFromChild)(TE_Pipe));
TE_Pipe TE_visitPipe(TE_Pipe arg, int (*acceptRead)(int), int (*acceptWrite)(int));

/*}}}  */

#endif /* _TEXTEDITOR_H */
