#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "TextEditor.h"

/*{{{  typedefs */

typedef struct ATerm _TE_Action;
typedef struct ATerm _TE_ActionList;
typedef struct ATerm _TE_Menu;
typedef struct ATerm _TE_Event;
typedef struct ATerm _TE_Process;
typedef struct ATerm _TE_Pipe;

/*}}}  */

/*{{{  void TE_initTextEditorApi(void) */

void TE_initTextEditorApi(void)
{
  init_TextEditor_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  TE_Action TE_ActionFromTerm(ATerm t) */

TE_Action TE_ActionFromTerm(ATerm t)
{
  return (TE_Action)t;
}

/*}}}  */
/*{{{  ATerm TE_ActionToTerm(TE_Action arg) */

ATerm TE_ActionToTerm(TE_Action arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  TE_ActionList TE_ActionListFromTerm(ATerm t) */

TE_ActionList TE_ActionListFromTerm(ATerm t)
{
  return (TE_ActionList)t;
}

/*}}}  */
/*{{{  ATerm TE_ActionListToTerm(TE_ActionList arg) */

ATerm TE_ActionListToTerm(TE_ActionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  TE_Menu TE_MenuFromTerm(ATerm t) */

TE_Menu TE_MenuFromTerm(ATerm t)
{
  return (TE_Menu)t;
}

/*}}}  */
/*{{{  ATerm TE_MenuToTerm(TE_Menu arg) */

ATerm TE_MenuToTerm(TE_Menu arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  TE_Event TE_EventFromTerm(ATerm t) */

TE_Event TE_EventFromTerm(ATerm t)
{
  return (TE_Event)t;
}

/*}}}  */
/*{{{  ATerm TE_EventToTerm(TE_Event arg) */

ATerm TE_EventToTerm(TE_Event arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  TE_Process TE_ProcessFromTerm(ATerm t) */

TE_Process TE_ProcessFromTerm(ATerm t)
{
  return (TE_Process)t;
}

/*}}}  */
/*{{{  ATerm TE_ProcessToTerm(TE_Process arg) */

ATerm TE_ProcessToTerm(TE_Process arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  TE_Pipe TE_PipeFromTerm(ATerm t) */

TE_Pipe TE_PipeFromTerm(ATerm t)
{
  return (TE_Pipe)t;
}

/*}}}  */
/*{{{  ATerm TE_PipeToTerm(TE_Pipe arg) */

ATerm TE_PipeToTerm(TE_Pipe arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  TE_Action TE_makeActionToFront() */

TE_Action TE_makeActionToFront()
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl0(TE_afun1));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionRereadContents() */

TE_Action TE_makeActionRereadContents()
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl0(TE_afun2));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionDisplayMessage(char * message) */

TE_Action TE_makeActionDisplayMessage(char * message)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl1(TE_afun3, (ATerm)ATmakeAppl0(ATmakeAFun(message, 0, ATtrue))));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionSetCursorAtLocation(int location) */

TE_Action TE_makeActionSetCursorAtLocation(int location)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl1(TE_afun4, (ATerm)ATmakeInt(location)));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionSetCursorAtFocus(ATerm focus) */

TE_Action TE_makeActionSetCursorAtFocus(ATerm focus)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl1(TE_afun5, (ATerm)focus));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionClearFocus() */

TE_Action TE_makeActionClearFocus()
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl0(TE_afun6));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionSetFocus(ATerm focus) */

TE_Action TE_makeActionSetFocus(ATerm focus)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl1(TE_afun7, (ATerm)focus));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionGetContents(ATerm focus) */

TE_Action TE_makeActionGetContents(ATerm focus)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl1(TE_afun8, (ATerm)focus));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionSetActions(TE_ActionList actions) */

TE_Action TE_makeActionSetActions(TE_ActionList actions)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl1(TE_afun9, (ATerm)actions));
}

/*}}}  */
/*{{{  TE_ActionList TE_makeActionListEmpty() */

TE_ActionList TE_makeActionListEmpty()
{
  return (TE_ActionList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  TE_ActionList TE_makeActionListMulti(TE_Menu head, TE_ActionList tail) */

TE_ActionList TE_makeActionListMulti(TE_Menu head, TE_ActionList tail)
{
  return (TE_ActionList)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  TE_Menu TE_makeMenuDefault(char * main, char * sub) */

TE_Menu TE_makeMenuDefault(char * main, char * sub)
{
  return (TE_Menu)(ATerm)ATmakeAppl1(TE_afun10, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl0(ATmakeAFun(sub, 0, ATtrue))), (ATerm)ATmakeAppl0(ATmakeAFun(main, 0, ATtrue))));
}

/*}}}  */
/*{{{  TE_Menu TE_makeMenuShortcut(char * main, char * sub, char * shortcut) */

TE_Menu TE_makeMenuShortcut(char * main, char * sub, char * shortcut)
{
  return (TE_Menu)(ATerm)ATmakeAppl2(TE_afun11, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl0(ATmakeAFun(sub, 0, ATtrue))), (ATerm)ATmakeAppl0(ATmakeAFun(main, 0, ATtrue))), (ATerm)ATmakeAppl0(ATmakeAFun(shortcut, 0, ATtrue)));
}

/*}}}  */
/*{{{  TE_Event TE_makeEventMenu(TE_Menu menu) */

TE_Event TE_makeEventMenu(TE_Menu menu)
{
  return (TE_Event)(ATerm)ATmakeAppl1(TE_afun12, (ATerm)menu);
}

/*}}}  */
/*{{{  TE_Event TE_makeEventMouse(int location) */

TE_Event TE_makeEventMouse(int location)
{
  return (TE_Event)(ATerm)ATmakeAppl1(TE_afun13, (ATerm)ATmakeInt(location));
}

/*}}}  */
/*{{{  TE_Event TE_makeEventContents(char * text) */

TE_Event TE_makeEventContents(char * text)
{
  return (TE_Event)(ATerm)ATmakeAppl1(TE_afun14, (ATerm)ATmakeAppl0(ATmakeAFun(text, 0, ATtrue)));
}

/*}}}  */
/*{{{  TE_Event TE_makeEventModified() */

TE_Event TE_makeEventModified()
{
  return (TE_Event)(ATerm)ATmakeAppl0(TE_afun15);
}

/*}}}  */
/*{{{  TE_Process TE_makeProcessDefault(TE_Pipe toChild, TE_Pipe fromChild) */

TE_Process TE_makeProcessDefault(TE_Pipe toChild, TE_Pipe fromChild)
{
  return (TE_Process)(ATerm)ATmakeAppl2(TE_afun16, (ATerm)toChild, (ATerm)fromChild);
}

/*}}}  */
/*{{{  TE_Pipe TE_makePipeDefault(int read, int write) */

TE_Pipe TE_makePipeDefault(int read, int write)
{
  return (TE_Pipe)(ATerm)ATmakeAppl2(TE_afun17, (ATerm)ATmakeInt(read), (ATerm)ATmakeInt(write));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool TE_isEqualAction(TE_Action arg0, TE_Action arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool TE_isEqualActionList(TE_ActionList arg0, TE_ActionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool TE_isEqualMenu(TE_Menu arg0, TE_Menu arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool TE_isEqualEvent(TE_Event arg0, TE_Event arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool TE_isEqualProcess(TE_Process arg0, TE_Process arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool TE_isEqualPipe(TE_Pipe arg0, TE_Pipe arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  TE_Action accessors */

/*{{{  ATbool TE_isValidAction(TE_Action arg) */

ATbool TE_isValidAction(TE_Action arg)
{
  if (TE_isActionToFront(arg)) {
    return ATtrue;
  }
  else if (TE_isActionRereadContents(arg)) {
    return ATtrue;
  }
  else if (TE_isActionDisplayMessage(arg)) {
    return ATtrue;
  }
  else if (TE_isActionSetCursorAtLocation(arg)) {
    return ATtrue;
  }
  else if (TE_isActionSetCursorAtFocus(arg)) {
    return ATtrue;
  }
  else if (TE_isActionClearFocus(arg)) {
    return ATtrue;
  }
  else if (TE_isActionSetFocus(arg)) {
    return ATtrue;
  }
  else if (TE_isActionGetContents(arg)) {
    return ATtrue;
  }
  else if (TE_isActionSetActions(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool TE_isActionToFront(TE_Action arg) */

inline ATbool TE_isActionToFront(TE_Action arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionToFront);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isActionRereadContents(TE_Action arg) */

inline ATbool TE_isActionRereadContents(TE_Action arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionRereadContents);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isActionDisplayMessage(TE_Action arg) */

inline ATbool TE_isActionDisplayMessage(TE_Action arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionDisplayMessage, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isActionSetCursorAtLocation(TE_Action arg) */

inline ATbool TE_isActionSetCursorAtLocation(TE_Action arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionSetCursorAtLocation, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isActionSetCursorAtFocus(TE_Action arg) */

inline ATbool TE_isActionSetCursorAtFocus(TE_Action arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionSetCursorAtFocus, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isActionClearFocus(TE_Action arg) */

inline ATbool TE_isActionClearFocus(TE_Action arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionClearFocus);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isActionSetFocus(TE_Action arg) */

inline ATbool TE_isActionSetFocus(TE_Action arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionSetFocus, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isActionGetContents(TE_Action arg) */

inline ATbool TE_isActionGetContents(TE_Action arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionGetContents, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isActionSetActions(TE_Action arg) */

inline ATbool TE_isActionSetActions(TE_Action arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionSetActions, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool TE_hasActionMessage(TE_Action arg) */

ATbool TE_hasActionMessage(TE_Action arg)
{
  if (TE_isActionDisplayMessage(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * TE_getActionMessage(TE_Action arg) */

char * TE_getActionMessage(TE_Action arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0)));
}

/*}}}  */
/*{{{  TE_Action TE_setActionMessage(TE_Action arg, char * message) */

TE_Action TE_setActionMessage(TE_Action arg, char * message)
{
  if (TE_isActionDisplayMessage(arg)) {
    return (TE_Action)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATmakeAppl0(ATmakeAFun(message, 0, ATtrue)), 0), 0);
  }

  ATabort("Action has no Message: %t\n", arg);
  return (TE_Action)NULL;
}

/*}}}  */
/*{{{  ATbool TE_hasActionLocation(TE_Action arg) */

ATbool TE_hasActionLocation(TE_Action arg)
{
  if (TE_isActionSetCursorAtLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int TE_getActionLocation(TE_Action arg) */

int TE_getActionLocation(TE_Action arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
}

/*}}}  */
/*{{{  TE_Action TE_setActionLocation(TE_Action arg, int location) */

TE_Action TE_setActionLocation(TE_Action arg, int location)
{
  if (TE_isActionSetCursorAtLocation(arg)) {
    return (TE_Action)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATmakeInt(location), 0), 0);
  }

  ATabort("Action has no Location: %t\n", arg);
  return (TE_Action)NULL;
}

/*}}}  */
/*{{{  ATbool TE_hasActionFocus(TE_Action arg) */

ATbool TE_hasActionFocus(TE_Action arg)
{
  if (TE_isActionSetCursorAtFocus(arg)) {
    return ATtrue;
  }
  else if (TE_isActionSetFocus(arg)) {
    return ATtrue;
  }
  else if (TE_isActionGetContents(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm TE_getActionFocus(TE_Action arg) */

ATerm TE_getActionFocus(TE_Action arg)
{
  if (TE_isActionSetCursorAtFocus(arg)) {
    return (ATerm)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0);
  }
  else if (TE_isActionSetFocus(arg)) {
    return (ATerm)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0);
  }
  else 
    return (ATerm)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0);
}

/*}}}  */
/*{{{  TE_Action TE_setActionFocus(TE_Action arg, ATerm focus) */

TE_Action TE_setActionFocus(TE_Action arg, ATerm focus)
{
  if (TE_isActionSetCursorAtFocus(arg)) {
    return (TE_Action)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)focus, 0), 0);
  }
  else if (TE_isActionSetFocus(arg)) {
    return (TE_Action)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)focus, 0), 0);
  }
  else if (TE_isActionGetContents(arg)) {
    return (TE_Action)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)focus, 0), 0);
  }

  ATabort("Action has no Focus: %t\n", arg);
  return (TE_Action)NULL;
}

/*}}}  */
/*{{{  ATbool TE_hasActionActions(TE_Action arg) */

ATbool TE_hasActionActions(TE_Action arg)
{
  if (TE_isActionSetActions(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  TE_ActionList TE_getActionActions(TE_Action arg) */

TE_ActionList TE_getActionActions(TE_Action arg)
{
  
    return (TE_ActionList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0);
}

/*}}}  */
/*{{{  TE_Action TE_setActionActions(TE_Action arg, TE_ActionList actions) */

TE_Action TE_setActionActions(TE_Action arg, TE_ActionList actions)
{
  if (TE_isActionSetActions(arg)) {
    return (TE_Action)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)actions, 0), 0);
  }

  ATabort("Action has no Actions: %t\n", arg);
  return (TE_Action)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  TE_ActionList accessors */

/*{{{  ATbool TE_isValidActionList(TE_ActionList arg) */

ATbool TE_isValidActionList(TE_ActionList arg)
{
  if (TE_isActionListEmpty(arg)) {
    return ATtrue;
  }
  else if (TE_isActionListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool TE_isActionListEmpty(TE_ActionList arg) */

inline ATbool TE_isActionListEmpty(TE_ActionList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, TE_patternActionListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool TE_isActionListMulti(TE_ActionList arg) */

inline ATbool TE_isActionListMulti(TE_ActionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, TE_patternActionListMulti, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool TE_hasActionListHead(TE_ActionList arg) */

ATbool TE_hasActionListHead(TE_ActionList arg)
{
  if (TE_isActionListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  TE_Menu TE_getActionListHead(TE_ActionList arg) */

TE_Menu TE_getActionListHead(TE_ActionList arg)
{
  
    return (TE_Menu)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  TE_ActionList TE_setActionListHead(TE_ActionList arg, TE_Menu head) */

TE_ActionList TE_setActionListHead(TE_ActionList arg, TE_Menu head)
{
  if (TE_isActionListMulti(arg)) {
    return (TE_ActionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ActionList has no Head: %t\n", arg);
  return (TE_ActionList)NULL;
}

/*}}}  */
/*{{{  ATbool TE_hasActionListTail(TE_ActionList arg) */

ATbool TE_hasActionListTail(TE_ActionList arg)
{
  if (TE_isActionListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  TE_ActionList TE_getActionListTail(TE_ActionList arg) */

TE_ActionList TE_getActionListTail(TE_ActionList arg)
{
  
    return (TE_ActionList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  TE_ActionList TE_setActionListTail(TE_ActionList arg, TE_ActionList tail) */

TE_ActionList TE_setActionListTail(TE_ActionList arg, TE_ActionList tail)
{
  if (TE_isActionListMulti(arg)) {
    return (TE_ActionList)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("ActionList has no Tail: %t\n", arg);
  return (TE_ActionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  TE_Menu accessors */

/*{{{  ATbool TE_isValidMenu(TE_Menu arg) */

ATbool TE_isValidMenu(TE_Menu arg)
{
  if (TE_isMenuDefault(arg)) {
    return ATtrue;
  }
  else if (TE_isMenuShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool TE_isMenuDefault(TE_Menu arg) */

inline ATbool TE_isMenuDefault(TE_Menu arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternMenuDefault, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isMenuShortcut(TE_Menu arg) */

inline ATbool TE_isMenuShortcut(TE_Menu arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternMenuShortcut, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool TE_hasMenuMain(TE_Menu arg) */

ATbool TE_hasMenuMain(TE_Menu arg)
{
  if (TE_isMenuDefault(arg)) {
    return ATtrue;
  }
  else if (TE_isMenuShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * TE_getMenuMain(TE_Menu arg) */

char * TE_getMenuMain(TE_Menu arg)
{
  if (TE_isMenuDefault(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 0))));
  }
  else 
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 0))));
}

/*}}}  */
/*{{{  TE_Menu TE_setMenuMain(TE_Menu arg, char * main) */

TE_Menu TE_setMenuMain(TE_Menu arg, char * main)
{
  if (TE_isMenuDefault(arg)) {
    return (TE_Menu)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATmakeAppl0(ATmakeAFun(main, 0, ATtrue)), 0), 0);
  }
  else if (TE_isMenuShortcut(arg)) {
    return (TE_Menu)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATmakeAppl0(ATmakeAFun(main, 0, ATtrue)), 0), 0);
  }

  ATabort("Menu has no Main: %t\n", arg);
  return (TE_Menu)NULL;
}

/*}}}  */
/*{{{  ATbool TE_hasMenuSub(TE_Menu arg) */

ATbool TE_hasMenuSub(TE_Menu arg)
{
  if (TE_isMenuDefault(arg)) {
    return ATtrue;
  }
  else if (TE_isMenuShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * TE_getMenuSub(TE_Menu arg) */

char * TE_getMenuSub(TE_Menu arg)
{
  if (TE_isMenuDefault(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 0), 1)));
  }
  else 
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 0), 1)));
}

/*}}}  */
/*{{{  TE_Menu TE_setMenuSub(TE_Menu arg, char * sub) */

TE_Menu TE_setMenuSub(TE_Menu arg, char * sub)
{
  if (TE_isMenuDefault(arg)) {
    return (TE_Menu)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATmakeAppl0(ATmakeAFun(sub, 0, ATtrue)), 1), 0);
  }
  else if (TE_isMenuShortcut(arg)) {
    return (TE_Menu)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATmakeAppl0(ATmakeAFun(sub, 0, ATtrue)), 1), 0);
  }

  ATabort("Menu has no Sub: %t\n", arg);
  return (TE_Menu)NULL;
}

/*}}}  */
/*{{{  ATbool TE_hasMenuShortcut(TE_Menu arg) */

ATbool TE_hasMenuShortcut(TE_Menu arg)
{
  if (TE_isMenuShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * TE_getMenuShortcut(TE_Menu arg) */

char * TE_getMenuShortcut(TE_Menu arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  TE_Menu TE_setMenuShortcut(TE_Menu arg, char * shortcut) */

TE_Menu TE_setMenuShortcut(TE_Menu arg, char * shortcut)
{
  if (TE_isMenuShortcut(arg)) {
    return (TE_Menu)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(shortcut, 0, ATtrue)), 1);
  }

  ATabort("Menu has no Shortcut: %t\n", arg);
  return (TE_Menu)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  TE_Event accessors */

/*{{{  ATbool TE_isValidEvent(TE_Event arg) */

ATbool TE_isValidEvent(TE_Event arg)
{
  if (TE_isEventMenu(arg)) {
    return ATtrue;
  }
  else if (TE_isEventMouse(arg)) {
    return ATtrue;
  }
  else if (TE_isEventContents(arg)) {
    return ATtrue;
  }
  else if (TE_isEventModified(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool TE_isEventMenu(TE_Event arg) */

inline ATbool TE_isEventMenu(TE_Event arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternEventMenu, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isEventMouse(TE_Event arg) */

inline ATbool TE_isEventMouse(TE_Event arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternEventMouse, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isEventContents(TE_Event arg) */

inline ATbool TE_isEventContents(TE_Event arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternEventContents, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isEventModified(TE_Event arg) */

inline ATbool TE_isEventModified(TE_Event arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternEventModified);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool TE_hasEventMenu(TE_Event arg) */

ATbool TE_hasEventMenu(TE_Event arg)
{
  if (TE_isEventMenu(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  TE_Menu TE_getEventMenu(TE_Event arg) */

TE_Menu TE_getEventMenu(TE_Event arg)
{
  
    return (TE_Menu)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  TE_Event TE_setEventMenu(TE_Event arg, TE_Menu menu) */

TE_Event TE_setEventMenu(TE_Event arg, TE_Menu menu)
{
  if (TE_isEventMenu(arg)) {
    return (TE_Event)ATsetArgument((ATermAppl)arg, (ATerm)menu, 0);
  }

  ATabort("Event has no Menu: %t\n", arg);
  return (TE_Event)NULL;
}

/*}}}  */
/*{{{  ATbool TE_hasEventLocation(TE_Event arg) */

ATbool TE_hasEventLocation(TE_Event arg)
{
  if (TE_isEventMouse(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int TE_getEventLocation(TE_Event arg) */

int TE_getEventLocation(TE_Event arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  TE_Event TE_setEventLocation(TE_Event arg, int location) */

TE_Event TE_setEventLocation(TE_Event arg, int location)
{
  if (TE_isEventMouse(arg)) {
    return (TE_Event)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(location), 0);
  }

  ATabort("Event has no Location: %t\n", arg);
  return (TE_Event)NULL;
}

/*}}}  */
/*{{{  ATbool TE_hasEventText(TE_Event arg) */

ATbool TE_hasEventText(TE_Event arg)
{
  if (TE_isEventContents(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * TE_getEventText(TE_Event arg) */

char * TE_getEventText(TE_Event arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  TE_Event TE_setEventText(TE_Event arg, char * text) */

TE_Event TE_setEventText(TE_Event arg, char * text)
{
  if (TE_isEventContents(arg)) {
    return (TE_Event)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(text, 0, ATtrue)), 0);
  }

  ATabort("Event has no Text: %t\n", arg);
  return (TE_Event)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  TE_Process accessors */

/*{{{  ATbool TE_isValidProcess(TE_Process arg) */

ATbool TE_isValidProcess(TE_Process arg)
{
  if (TE_isProcessDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool TE_isProcessDefault(TE_Process arg) */

inline ATbool TE_isProcessDefault(TE_Process arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, TE_patternProcessDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool TE_hasProcessToChild(TE_Process arg) */

ATbool TE_hasProcessToChild(TE_Process arg)
{
  if (TE_isProcessDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  TE_Pipe TE_getProcessToChild(TE_Process arg) */

TE_Pipe TE_getProcessToChild(TE_Process arg)
{
  
    return (TE_Pipe)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  TE_Process TE_setProcessToChild(TE_Process arg, TE_Pipe toChild) */

TE_Process TE_setProcessToChild(TE_Process arg, TE_Pipe toChild)
{
  if (TE_isProcessDefault(arg)) {
    return (TE_Process)ATsetArgument((ATermAppl)arg, (ATerm)toChild, 0);
  }

  ATabort("Process has no ToChild: %t\n", arg);
  return (TE_Process)NULL;
}

/*}}}  */
/*{{{  ATbool TE_hasProcessFromChild(TE_Process arg) */

ATbool TE_hasProcessFromChild(TE_Process arg)
{
  if (TE_isProcessDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  TE_Pipe TE_getProcessFromChild(TE_Process arg) */

TE_Pipe TE_getProcessFromChild(TE_Process arg)
{
  
    return (TE_Pipe)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  TE_Process TE_setProcessFromChild(TE_Process arg, TE_Pipe fromChild) */

TE_Process TE_setProcessFromChild(TE_Process arg, TE_Pipe fromChild)
{
  if (TE_isProcessDefault(arg)) {
    return (TE_Process)ATsetArgument((ATermAppl)arg, (ATerm)fromChild, 1);
  }

  ATabort("Process has no FromChild: %t\n", arg);
  return (TE_Process)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  TE_Pipe accessors */

/*{{{  ATbool TE_isValidPipe(TE_Pipe arg) */

ATbool TE_isValidPipe(TE_Pipe arg)
{
  if (TE_isPipeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool TE_isPipeDefault(TE_Pipe arg) */

inline ATbool TE_isPipeDefault(TE_Pipe arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, TE_patternPipeDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool TE_hasPipeRead(TE_Pipe arg) */

ATbool TE_hasPipeRead(TE_Pipe arg)
{
  if (TE_isPipeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int TE_getPipeRead(TE_Pipe arg) */

int TE_getPipeRead(TE_Pipe arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  TE_Pipe TE_setPipeRead(TE_Pipe arg, int read) */

TE_Pipe TE_setPipeRead(TE_Pipe arg, int read)
{
  if (TE_isPipeDefault(arg)) {
    return (TE_Pipe)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(read), 0);
  }

  ATabort("Pipe has no Read: %t\n", arg);
  return (TE_Pipe)NULL;
}

/*}}}  */
/*{{{  ATbool TE_hasPipeWrite(TE_Pipe arg) */

ATbool TE_hasPipeWrite(TE_Pipe arg)
{
  if (TE_isPipeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int TE_getPipeWrite(TE_Pipe arg) */

int TE_getPipeWrite(TE_Pipe arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  TE_Pipe TE_setPipeWrite(TE_Pipe arg, int write) */

TE_Pipe TE_setPipeWrite(TE_Pipe arg, int write)
{
  if (TE_isPipeDefault(arg)) {
    return (TE_Pipe)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(write), 1);
  }

  ATabort("Pipe has no Write: %t\n", arg);
  return (TE_Pipe)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  TE_Action TE_visitAction(TE_Action arg, char * (*acceptMessage)(char *), int (*acceptLocation)(int), ATerm (*acceptFocus)(ATerm), TE_ActionList (*acceptActions)(TE_ActionList)) */

TE_Action TE_visitAction(TE_Action arg, char * (*acceptMessage)(char *), int (*acceptLocation)(int), ATerm (*acceptFocus)(ATerm), TE_ActionList (*acceptActions)(TE_ActionList))
{
  if (TE_isActionToFront(arg)) {
    return TE_makeActionToFront();
  }
  if (TE_isActionRereadContents(arg)) {
    return TE_makeActionRereadContents();
  }
  if (TE_isActionDisplayMessage(arg)) {
    return TE_makeActionDisplayMessage(
        acceptMessage ? acceptMessage(TE_getActionMessage(arg)) : TE_getActionMessage(arg));
  }
  if (TE_isActionSetCursorAtLocation(arg)) {
    return TE_makeActionSetCursorAtLocation(
        acceptLocation ? acceptLocation(TE_getActionLocation(arg)) : TE_getActionLocation(arg));
  }
  if (TE_isActionSetCursorAtFocus(arg)) {
    return TE_makeActionSetCursorAtFocus(
        acceptFocus ? acceptFocus(TE_getActionFocus(arg)) : TE_getActionFocus(arg));
  }
  if (TE_isActionClearFocus(arg)) {
    return TE_makeActionClearFocus();
  }
  if (TE_isActionSetFocus(arg)) {
    return TE_makeActionSetFocus(
        acceptFocus ? acceptFocus(TE_getActionFocus(arg)) : TE_getActionFocus(arg));
  }
  if (TE_isActionGetContents(arg)) {
    return TE_makeActionGetContents(
        acceptFocus ? acceptFocus(TE_getActionFocus(arg)) : TE_getActionFocus(arg));
  }
  if (TE_isActionSetActions(arg)) {
    return TE_makeActionSetActions(
        acceptActions ? acceptActions(TE_getActionActions(arg)) : TE_getActionActions(arg));
  }
  ATabort("not a Action: %t\n", arg);
  return (TE_Action)NULL;
}

/*}}}  */
/*{{{  TE_ActionList TE_visitActionList(TE_ActionList arg, TE_Menu (*acceptHead)(TE_Menu)) */

TE_ActionList TE_visitActionList(TE_ActionList arg, TE_Menu (*acceptHead)(TE_Menu))
{
  if (TE_isActionListEmpty(arg)) {
    return TE_makeActionListEmpty();
  }
  if (TE_isActionListMulti(arg)) {
    return TE_makeActionListMulti(
        acceptHead ? acceptHead(TE_getActionListHead(arg)) : TE_getActionListHead(arg),
        TE_visitActionList(TE_getActionListTail(arg), acceptHead));
  }
  ATabort("not a ActionList: %t\n", arg);
  return (TE_ActionList)NULL;
}

/*}}}  */
/*{{{  TE_Menu TE_visitMenu(TE_Menu arg, char * (*acceptMain)(char *), char * (*acceptSub)(char *), char * (*acceptShortcut)(char *)) */

TE_Menu TE_visitMenu(TE_Menu arg, char * (*acceptMain)(char *), char * (*acceptSub)(char *), char * (*acceptShortcut)(char *))
{
  if (TE_isMenuDefault(arg)) {
    return TE_makeMenuDefault(
        acceptMain ? acceptMain(TE_getMenuMain(arg)) : TE_getMenuMain(arg),
        acceptSub ? acceptSub(TE_getMenuSub(arg)) : TE_getMenuSub(arg));
  }
  if (TE_isMenuShortcut(arg)) {
    return TE_makeMenuShortcut(
        acceptMain ? acceptMain(TE_getMenuMain(arg)) : TE_getMenuMain(arg),
        acceptSub ? acceptSub(TE_getMenuSub(arg)) : TE_getMenuSub(arg),
        acceptShortcut ? acceptShortcut(TE_getMenuShortcut(arg)) : TE_getMenuShortcut(arg));
  }
  ATabort("not a Menu: %t\n", arg);
  return (TE_Menu)NULL;
}

/*}}}  */
/*{{{  TE_Event TE_visitEvent(TE_Event arg, TE_Menu (*acceptMenu)(TE_Menu), int (*acceptLocation)(int), char * (*acceptText)(char *)) */

TE_Event TE_visitEvent(TE_Event arg, TE_Menu (*acceptMenu)(TE_Menu), int (*acceptLocation)(int), char * (*acceptText)(char *))
{
  if (TE_isEventMenu(arg)) {
    return TE_makeEventMenu(
        acceptMenu ? acceptMenu(TE_getEventMenu(arg)) : TE_getEventMenu(arg));
  }
  if (TE_isEventMouse(arg)) {
    return TE_makeEventMouse(
        acceptLocation ? acceptLocation(TE_getEventLocation(arg)) : TE_getEventLocation(arg));
  }
  if (TE_isEventContents(arg)) {
    return TE_makeEventContents(
        acceptText ? acceptText(TE_getEventText(arg)) : TE_getEventText(arg));
  }
  if (TE_isEventModified(arg)) {
    return TE_makeEventModified();
  }
  ATabort("not a Event: %t\n", arg);
  return (TE_Event)NULL;
}

/*}}}  */
/*{{{  TE_Process TE_visitProcess(TE_Process arg, TE_Pipe (*acceptToChild)(TE_Pipe), TE_Pipe (*acceptFromChild)(TE_Pipe)) */

TE_Process TE_visitProcess(TE_Process arg, TE_Pipe (*acceptToChild)(TE_Pipe), TE_Pipe (*acceptFromChild)(TE_Pipe))
{
  if (TE_isProcessDefault(arg)) {
    return TE_makeProcessDefault(
        acceptToChild ? acceptToChild(TE_getProcessToChild(arg)) : TE_getProcessToChild(arg),
        acceptFromChild ? acceptFromChild(TE_getProcessFromChild(arg)) : TE_getProcessFromChild(arg));
  }
  ATabort("not a Process: %t\n", arg);
  return (TE_Process)NULL;
}

/*}}}  */
/*{{{  TE_Pipe TE_visitPipe(TE_Pipe arg, int (*acceptRead)(int), int (*acceptWrite)(int)) */

TE_Pipe TE_visitPipe(TE_Pipe arg, int (*acceptRead)(int), int (*acceptWrite)(int))
{
  if (TE_isPipeDefault(arg)) {
    return TE_makePipeDefault(
        acceptRead ? acceptRead(TE_getPipeRead(arg)) : TE_getPipeRead(arg),
        acceptWrite ? acceptWrite(TE_getPipeWrite(arg)) : TE_getPipeWrite(arg));
  }
  ATabort("not a Pipe: %t\n", arg);
  return (TE_Pipe)NULL;
}

/*}}}  */

/*}}}  */
