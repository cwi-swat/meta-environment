#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "TextEditor.h"

/*{{{  conversion functions */

ATerm TE_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

char *TE_charsToString(ATerm arg)
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

typedef struct ATerm _TE_Action;
typedef struct ATerm _TE_Menu;
typedef struct ATerm _TE_ActionList;
typedef struct ATerm _TE_Items;
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

/*{{{  protect functions */

void TE_protectAction(TE_Action *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void TE_protectMenu(TE_Menu *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void TE_protectActionList(TE_ActionList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void TE_protectItems(TE_Items *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void TE_protectEvent(TE_Event *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void TE_protectProcess(TE_Process *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void TE_protectPipe(TE_Pipe *arg)
{
  ATprotect((ATerm*)((void*) arg));
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
/*{{{  TE_Items TE_ItemsFromTerm(ATerm t) */

TE_Items TE_ItemsFromTerm(ATerm t)
{
  return (TE_Items)t;
}

/*}}}  */
/*{{{  ATerm TE_ItemsToTerm(TE_Items arg) */

ATerm TE_ItemsToTerm(TE_Items arg)
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
/*{{{  list functions */

int TE_getActionListLength (TE_ActionList arg) {
  return ATgetLength((ATermList) arg);
}
TE_ActionList TE_reverseActionList(TE_ActionList arg) {
  return (TE_ActionList) ATreverse((ATermList) arg);
}
TE_ActionList TE_appendActionList(TE_ActionList arg, TE_Menu elem) {
  return (TE_ActionList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
TE_ActionList TE_concatActionList(TE_ActionList arg0, TE_ActionList arg1) {
  return (TE_ActionList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
TE_ActionList TE_sliceActionList(TE_ActionList arg, int start, int end) {
  return (TE_ActionList) ATgetSlice((ATermList) arg, start, end);
}
TE_Menu TE_getActionListMenuAt(TE_ActionList arg, int index) {
 return (TE_Menu)ATelementAt((ATermList) arg,index);
}
TE_ActionList TE_replaceActionListMenuAt(TE_ActionList arg, TE_Menu elem, int index) {
 return (TE_ActionList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
TE_ActionList TE_makeActionList2(TE_Menu elem1, TE_Menu elem2) {
  return (TE_ActionList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
TE_ActionList TE_makeActionList3(TE_Menu elem1, TE_Menu elem2, TE_Menu elem3) {
  return (TE_ActionList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
TE_ActionList TE_makeActionList4(TE_Menu elem1, TE_Menu elem2, TE_Menu elem3, TE_Menu elem4) {
  return (TE_ActionList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
TE_ActionList TE_makeActionList5(TE_Menu elem1, TE_Menu elem2, TE_Menu elem3, TE_Menu elem4, TE_Menu elem5) {
  return (TE_ActionList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
TE_ActionList TE_makeActionList6(TE_Menu elem1, TE_Menu elem2, TE_Menu elem3, TE_Menu elem4, TE_Menu elem5, TE_Menu elem6) {
  return (TE_ActionList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int TE_getItemsLength (TE_Items arg) {
  return ATgetLength((ATermList) arg);
}
TE_Items TE_reverseItems(TE_Items arg) {
  return (TE_Items) ATreverse((ATermList) arg);
}
TE_Items TE_appendItems(TE_Items arg, char* elem) {
  return (TE_Items) ATappend((ATermList) arg, (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem, 0, ATtrue))));
}
TE_Items TE_concatItems(TE_Items arg0, TE_Items arg1) {
  return (TE_Items) ATconcat((ATermList) arg0, (ATermList) arg1);
}
TE_Items TE_sliceItems(TE_Items arg, int start, int end) {
  return (TE_Items) ATgetSlice((ATermList) arg, start, end);
}
char* TE_getItemsstrAt(TE_Items arg, int index) {
 return (char*)ATgetName(ATgetAFun((ATermAppl) ATelementAt((ATermList) arg,index)));
}
TE_Items TE_replaceItemsstrAt(TE_Items arg, char* elem, int index) {
 return (TE_Items) ATreplace((ATermList) arg, (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem, 0, ATtrue))), index);
}
TE_Items TE_makeItems2(char* elem1, char* elem2) {
  return (TE_Items) ATmakeList2((ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem2, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem2, 0, ATtrue))));
}
TE_Items TE_makeItems3(char* elem1, char* elem2, char* elem3) {
  return (TE_Items) ATmakeList3((ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem3, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem3, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem3, 0, ATtrue))));
}
TE_Items TE_makeItems4(char* elem1, char* elem2, char* elem3, char* elem4) {
  return (TE_Items) ATmakeList4((ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem4, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem4, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem4, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem4, 0, ATtrue))));
}
TE_Items TE_makeItems5(char* elem1, char* elem2, char* elem3, char* elem4, char* elem5) {
  return (TE_Items) ATmakeList5((ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem5, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem5, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem5, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem5, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem5, 0, ATtrue))));
}
TE_Items TE_makeItems6(char* elem1, char* elem2, char* elem3, char* elem4, char* elem5, char* elem6) {
  return (TE_Items) ATmakeList6((ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))));
}

/*}}}  */
/*{{{  constructors */

/*{{{  TE_Action TE_makeActionToFront(void) */

TE_Action TE_makeActionToFront(void)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl0(TE_afun1));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionQuit(void) */

TE_Action TE_makeActionQuit(void)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl0(TE_afun2));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionIsModified(void) */

TE_Action TE_makeActionIsModified(void)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl0(TE_afun3));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionWriteContents(void) */

TE_Action TE_makeActionWriteContents(void)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl0(TE_afun4));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionRereadContents(void) */

TE_Action TE_makeActionRereadContents(void)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl0(TE_afun5));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionDisplayMessage(const char* message) */

TE_Action TE_makeActionDisplayMessage(const char* message)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl1(TE_afun6, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(message, 0, ATtrue))));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionSetCursorAtOffset(int offset) */

TE_Action TE_makeActionSetCursorAtOffset(int offset)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl1(TE_afun7, (ATerm) (ATerm) ATmakeInt(offset)));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionSetFocus(ATerm focus) */

TE_Action TE_makeActionSetFocus(ATerm focus)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl1(TE_afun8, (ATerm) focus));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionClearFocus(void) */

TE_Action TE_makeActionClearFocus(void)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl0(TE_afun9));
}

/*}}}  */
/*{{{  TE_Action TE_makeActionAddActions(TE_ActionList actions) */

TE_Action TE_makeActionAddActions(TE_ActionList actions)
{
  return (TE_Action)(ATerm)ATmakeAppl1(TE_afun0, (ATerm)ATmakeAppl1(TE_afun10, (ATerm) actions));
}

/*}}}  */
/*{{{  TE_Menu TE_makeMenuDefault(TE_Items items) */

TE_Menu TE_makeMenuDefault(TE_Items items)
{
  return (TE_Menu)(ATerm)ATmakeAppl1(TE_afun11, (ATerm) items);
}

/*}}}  */
/*{{{  TE_Menu TE_makeMenuShortcut(TE_Items items, const char* shortcut) */

TE_Menu TE_makeMenuShortcut(TE_Items items, const char* shortcut)
{
  return (TE_Menu)(ATerm)ATmakeAppl2(TE_afun12, (ATerm) items, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(shortcut, 0, ATtrue)));
}

/*}}}  */
/*{{{  TE_ActionList TE_makeActionListEmpty(void) */

TE_ActionList TE_makeActionListEmpty(void)
{
  return (TE_ActionList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  TE_ActionList TE_makeActionListSingle(TE_Menu head) */

TE_ActionList TE_makeActionListSingle(TE_Menu head)
{
  return (TE_ActionList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  TE_ActionList TE_makeActionListMany(TE_Menu head, TE_ActionList tail) */

TE_ActionList TE_makeActionListMany(TE_Menu head, TE_ActionList tail)
{
  return (TE_ActionList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  TE_Items TE_makeItemsEmpty(void) */

TE_Items TE_makeItemsEmpty(void)
{
  return (TE_Items)(ATerm)ATempty;
}

/*}}}  */
/*{{{  TE_Items TE_makeItemsSingle(const char* head) */

TE_Items TE_makeItemsSingle(const char* head)
{
  return (TE_Items)(ATerm)ATmakeList1((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(head, 0, ATtrue)));
}

/*}}}  */
/*{{{  TE_Items TE_makeItemsMany(const char* head, TE_Items tail) */

TE_Items TE_makeItemsMany(const char* head, TE_Items tail)
{
  return (TE_Items)(ATerm)ATinsert((ATermList)tail, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(head, 0, ATtrue)));
}

/*}}}  */
/*{{{  TE_Event TE_makeEventMenu(TE_Menu menu) */

TE_Event TE_makeEventMenu(TE_Menu menu)
{
  return (TE_Event)(ATerm)ATmakeAppl1(TE_afun13, (ATerm) menu);
}

/*}}}  */
/*{{{  TE_Event TE_makeEventMouse(int location) */

TE_Event TE_makeEventMouse(int location)
{
  return (TE_Event)(ATerm)ATmakeAppl1(TE_afun14, (ATerm) (ATerm) ATmakeInt(location));
}

/*}}}  */
/*{{{  TE_Event TE_makeEventContentsWritten(void) */

TE_Event TE_makeEventContentsWritten(void)
{
  return (TE_Event)(ATerm)ATmakeAppl0(TE_afun15);
}

/*}}}  */
/*{{{  TE_Event TE_makeEventModified(void) */

TE_Event TE_makeEventModified(void)
{
  return (TE_Event)(ATerm)ATmakeAppl0(TE_afun16);
}

/*}}}  */
/*{{{  TE_Event TE_makeEventIsModified(int modified) */

TE_Event TE_makeEventIsModified(int modified)
{
  return (TE_Event)(ATerm)ATmakeAppl1(TE_afun17, (ATerm) (ATerm) ATmakeInt(modified));
}

/*}}}  */
/*{{{  TE_Process TE_makeProcessDefault(TE_Pipe toChild, TE_Pipe fromChild) */

TE_Process TE_makeProcessDefault(TE_Pipe toChild, TE_Pipe fromChild)
{
  return (TE_Process)(ATerm)ATmakeAppl2(TE_afun18, (ATerm) toChild, (ATerm) fromChild);
}

/*}}}  */
/*{{{  TE_Pipe TE_makePipeDefault(int read, int write) */

TE_Pipe TE_makePipeDefault(int read, int write)
{
  return (TE_Pipe)(ATerm)ATmakeAppl2(TE_afun19, (ATerm) (ATerm) ATmakeInt(read), (ATerm) (ATerm) ATmakeInt(write));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool TE_isEqualAction(TE_Action arg0, TE_Action arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool TE_isEqualMenu(TE_Menu arg0, TE_Menu arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool TE_isEqualActionList(TE_ActionList arg0, TE_ActionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool TE_isEqualItems(TE_Items arg0, TE_Items arg1)
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
  else if (TE_isActionQuit(arg)) {
    return ATtrue;
  }
  else if (TE_isActionIsModified(arg)) {
    return ATtrue;
  }
  else if (TE_isActionWriteContents(arg)) {
    return ATtrue;
  }
  else if (TE_isActionRereadContents(arg)) {
    return ATtrue;
  }
  else if (TE_isActionDisplayMessage(arg)) {
    return ATtrue;
  }
  else if (TE_isActionSetCursorAtOffset(arg)) {
    return ATtrue;
  }
  else if (TE_isActionSetFocus(arg)) {
    return ATtrue;
  }
  else if (TE_isActionClearFocus(arg)) {
    return ATtrue;
  }
  else if (TE_isActionAddActions(arg)) {
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
/*{{{  inline ATbool TE_isActionQuit(TE_Action arg) */

inline ATbool TE_isActionQuit(TE_Action arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionQuit);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isActionIsModified(TE_Action arg) */

inline ATbool TE_isActionIsModified(TE_Action arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionIsModified);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isActionWriteContents(TE_Action arg) */

inline ATbool TE_isActionWriteContents(TE_Action arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionWriteContents);
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
/*{{{  inline ATbool TE_isActionSetCursorAtOffset(TE_Action arg) */

inline ATbool TE_isActionSetCursorAtOffset(TE_Action arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionSetCursorAtOffset, NULL);
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
/*{{{  inline ATbool TE_isActionAddActions(TE_Action arg) */

inline ATbool TE_isActionAddActions(TE_Action arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionAddActions, NULL);
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
/*{{{  ATbool TE_hasActionOffset(TE_Action arg) */

ATbool TE_hasActionOffset(TE_Action arg)
{
  if (TE_isActionSetCursorAtOffset(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool TE_hasActionFocus(TE_Action arg) */

ATbool TE_hasActionFocus(TE_Action arg)
{
  if (TE_isActionSetFocus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool TE_hasActionActions(TE_Action arg) */

ATbool TE_hasActionActions(TE_Action arg)
{
  if (TE_isActionAddActions(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* TE_getActionMessage(TE_Action arg) */

char* TE_getActionMessage(TE_Action arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0)));
}

/*}}}  */
/*{{{  int TE_getActionOffset(TE_Action arg) */

int TE_getActionOffset(TE_Action arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
}

/*}}}  */
/*{{{  ATerm TE_getActionFocus(TE_Action arg) */

ATerm TE_getActionFocus(TE_Action arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0);
}

/*}}}  */
/*{{{  TE_ActionList TE_getActionActions(TE_Action arg) */

TE_ActionList TE_getActionActions(TE_Action arg)
{
  
    return (TE_ActionList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0);
}

/*}}}  */
/*{{{  TE_Action TE_setActionMessage(TE_Action arg, const char* message) */

TE_Action TE_setActionMessage(TE_Action arg, const char* message)
{
  if (TE_isActionDisplayMessage(arg)) {
    return (TE_Action)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(message, 0, ATtrue))), 0), 0);
  }

  ATabort("Action has no Message: %t\n", arg);
  return (TE_Action)NULL;
}

/*}}}  */
/*{{{  TE_Action TE_setActionOffset(TE_Action arg, int offset) */

TE_Action TE_setActionOffset(TE_Action arg, int offset)
{
  if (TE_isActionSetCursorAtOffset(arg)) {
    return (TE_Action)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)((ATerm) (ATerm) ATmakeInt(offset)), 0), 0);
  }

  ATabort("Action has no Offset: %t\n", arg);
  return (TE_Action)NULL;
}

/*}}}  */
/*{{{  TE_Action TE_setActionFocus(TE_Action arg, ATerm focus) */

TE_Action TE_setActionFocus(TE_Action arg, ATerm focus)
{
  if (TE_isActionSetFocus(arg)) {
    return (TE_Action)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)((ATerm) focus), 0), 0);
  }

  ATabort("Action has no Focus: %t\n", arg);
  return (TE_Action)NULL;
}

/*}}}  */
/*{{{  TE_Action TE_setActionActions(TE_Action arg, TE_ActionList actions) */

TE_Action TE_setActionActions(TE_Action arg, TE_ActionList actions)
{
  if (TE_isActionAddActions(arg)) {
    return (TE_Action)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)((ATerm) actions), 0), 0);
  }

  ATabort("Action has no Actions: %t\n", arg);
  return (TE_Action)NULL;
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
      last_result = ATmatchTerm((ATerm)arg, TE_patternMenuDefault, NULL);
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
      last_result = ATmatchTerm((ATerm)arg, TE_patternMenuShortcut, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool TE_hasMenuItems(TE_Menu arg) */

ATbool TE_hasMenuItems(TE_Menu arg)
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
/*{{{  ATbool TE_hasMenuShortcut(TE_Menu arg) */

ATbool TE_hasMenuShortcut(TE_Menu arg)
{
  if (TE_isMenuShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  TE_Items TE_getMenuItems(TE_Menu arg) */

TE_Items TE_getMenuItems(TE_Menu arg)
{
  if (TE_isMenuDefault(arg)) {
    return (TE_Items)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (TE_Items)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  char* TE_getMenuShortcut(TE_Menu arg) */

char* TE_getMenuShortcut(TE_Menu arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  TE_Menu TE_setMenuItems(TE_Menu arg, TE_Items items) */

TE_Menu TE_setMenuItems(TE_Menu arg, TE_Items items)
{
  if (TE_isMenuDefault(arg)) {
    return (TE_Menu)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) items), 0);
  }
  else if (TE_isMenuShortcut(arg)) {
    return (TE_Menu)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) items), 0);
  }

  ATabort("Menu has no Items: %t\n", arg);
  return (TE_Menu)NULL;
}

/*}}}  */
/*{{{  TE_Menu TE_setMenuShortcut(TE_Menu arg, const char* shortcut) */

TE_Menu TE_setMenuShortcut(TE_Menu arg, const char* shortcut)
{
  if (TE_isMenuShortcut(arg)) {
    return (TE_Menu)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(shortcut, 0, ATtrue))), 1);
  }

  ATabort("Menu has no Shortcut: %t\n", arg);
  return (TE_Menu)NULL;
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
  else if (TE_isActionListSingle(arg)) {
    return ATtrue;
  }
  else if (TE_isActionListMany(arg)) {
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
/*{{{  inline ATbool TE_isActionListSingle(TE_ActionList arg) */

inline ATbool TE_isActionListSingle(TE_ActionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isActionListMany(TE_ActionList arg) */

inline ATbool TE_isActionListMany(TE_ActionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, TE_patternActionListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool TE_hasActionListHead(TE_ActionList arg) */

ATbool TE_hasActionListHead(TE_ActionList arg)
{
  if (TE_isActionListSingle(arg)) {
    return ATtrue;
  }
  else if (TE_isActionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool TE_hasActionListTail(TE_ActionList arg) */

ATbool TE_hasActionListTail(TE_ActionList arg)
{
  if (TE_isActionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  TE_Menu TE_getActionListHead(TE_ActionList arg) */

TE_Menu TE_getActionListHead(TE_ActionList arg)
{
  if (TE_isActionListSingle(arg)) {
    return (TE_Menu)ATgetFirst((ATermList)arg);
  }
  else 
    return (TE_Menu)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  TE_ActionList TE_getActionListTail(TE_ActionList arg) */

TE_ActionList TE_getActionListTail(TE_ActionList arg)
{
  
    return (TE_ActionList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  TE_ActionList TE_setActionListHead(TE_ActionList arg, TE_Menu head) */

TE_ActionList TE_setActionListHead(TE_ActionList arg, TE_Menu head)
{
  if (TE_isActionListSingle(arg)) {
    return (TE_ActionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (TE_isActionListMany(arg)) {
    return (TE_ActionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ActionList has no Head: %t\n", arg);
  return (TE_ActionList)NULL;
}

/*}}}  */
/*{{{  TE_ActionList TE_setActionListTail(TE_ActionList arg, TE_ActionList tail) */

TE_ActionList TE_setActionListTail(TE_ActionList arg, TE_ActionList tail)
{
  if (TE_isActionListMany(arg)) {
    return (TE_ActionList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("ActionList has no Tail: %t\n", arg);
  return (TE_ActionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  TE_Items accessors */

/*{{{  ATbool TE_isValidItems(TE_Items arg) */

ATbool TE_isValidItems(TE_Items arg)
{
  if (TE_isItemsEmpty(arg)) {
    return ATtrue;
  }
  else if (TE_isItemsSingle(arg)) {
    return ATtrue;
  }
  else if (TE_isItemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool TE_isItemsEmpty(TE_Items arg) */

inline ATbool TE_isItemsEmpty(TE_Items arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, TE_patternItemsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool TE_isItemsSingle(TE_Items arg) */

inline ATbool TE_isItemsSingle(TE_Items arg)
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
      last_result = ATmatchTerm((ATerm)arg, TE_patternItemsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TE_isItemsMany(TE_Items arg) */

inline ATbool TE_isItemsMany(TE_Items arg)
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
      last_result = ATmatchTerm((ATerm)arg, TE_patternItemsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool TE_hasItemsHead(TE_Items arg) */

ATbool TE_hasItemsHead(TE_Items arg)
{
  if (TE_isItemsSingle(arg)) {
    return ATtrue;
  }
  else if (TE_isItemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool TE_hasItemsTail(TE_Items arg) */

ATbool TE_hasItemsTail(TE_Items arg)
{
  if (TE_isItemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* TE_getItemsHead(TE_Items arg) */

char* TE_getItemsHead(TE_Items arg)
{
  if (TE_isItemsSingle(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetFirst((ATermList)arg)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetFirst((ATermList)arg)));
}

/*}}}  */
/*{{{  TE_Items TE_getItemsTail(TE_Items arg) */

TE_Items TE_getItemsTail(TE_Items arg)
{
  
    return (TE_Items)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  TE_Items TE_setItemsHead(TE_Items arg, const char* head) */

TE_Items TE_setItemsHead(TE_Items arg, const char* head)
{
  if (TE_isItemsSingle(arg)) {
    return (TE_Items)ATreplace((ATermList)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(head, 0, ATtrue))), 0);
  }
  else if (TE_isItemsMany(arg)) {
    return (TE_Items)ATreplace((ATermList)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(head, 0, ATtrue))), 0);
  }

  ATabort("Items has no Head: %t\n", arg);
  return (TE_Items)NULL;
}

/*}}}  */
/*{{{  TE_Items TE_setItemsTail(TE_Items arg, TE_Items tail) */

TE_Items TE_setItemsTail(TE_Items arg, TE_Items tail)
{
  if (TE_isItemsMany(arg)) {
    return (TE_Items)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Items has no Tail: %t\n", arg);
  return (TE_Items)NULL;
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
  else if (TE_isEventContentsWritten(arg)) {
    return ATtrue;
  }
  else if (TE_isEventModified(arg)) {
    return ATtrue;
  }
  else if (TE_isEventIsModified(arg)) {
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
/*{{{  inline ATbool TE_isEventContentsWritten(TE_Event arg) */

inline ATbool TE_isEventContentsWritten(TE_Event arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternEventContentsWritten);
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
/*{{{  inline ATbool TE_isEventIsModified(TE_Event arg) */

inline ATbool TE_isEventIsModified(TE_Event arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TE_patternEventIsModified, NULL);
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
/*{{{  ATbool TE_hasEventLocation(TE_Event arg) */

ATbool TE_hasEventLocation(TE_Event arg)
{
  if (TE_isEventMouse(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool TE_hasEventModified(TE_Event arg) */

ATbool TE_hasEventModified(TE_Event arg)
{
  if (TE_isEventIsModified(arg)) {
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
/*{{{  int TE_getEventLocation(TE_Event arg) */

int TE_getEventLocation(TE_Event arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  int TE_getEventModified(TE_Event arg) */

int TE_getEventModified(TE_Event arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  TE_Event TE_setEventMenu(TE_Event arg, TE_Menu menu) */

TE_Event TE_setEventMenu(TE_Event arg, TE_Menu menu)
{
  if (TE_isEventMenu(arg)) {
    return (TE_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) menu), 0);
  }

  ATabort("Event has no Menu: %t\n", arg);
  return (TE_Event)NULL;
}

/*}}}  */
/*{{{  TE_Event TE_setEventLocation(TE_Event arg, int location) */

TE_Event TE_setEventLocation(TE_Event arg, int location)
{
  if (TE_isEventMouse(arg)) {
    return (TE_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(location)), 0);
  }

  ATabort("Event has no Location: %t\n", arg);
  return (TE_Event)NULL;
}

/*}}}  */
/*{{{  TE_Event TE_setEventModified(TE_Event arg, int modified) */

TE_Event TE_setEventModified(TE_Event arg, int modified)
{
  if (TE_isEventIsModified(arg)) {
    return (TE_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(modified)), 0);
  }

  ATabort("Event has no Modified: %t\n", arg);
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
/*{{{  ATbool TE_hasProcessFromChild(TE_Process arg) */

ATbool TE_hasProcessFromChild(TE_Process arg)
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
/*{{{  TE_Pipe TE_getProcessFromChild(TE_Process arg) */

TE_Pipe TE_getProcessFromChild(TE_Process arg)
{
  
    return (TE_Pipe)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  TE_Process TE_setProcessToChild(TE_Process arg, TE_Pipe toChild) */

TE_Process TE_setProcessToChild(TE_Process arg, TE_Pipe toChild)
{
  if (TE_isProcessDefault(arg)) {
    return (TE_Process)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) toChild), 0);
  }

  ATabort("Process has no ToChild: %t\n", arg);
  return (TE_Process)NULL;
}

/*}}}  */
/*{{{  TE_Process TE_setProcessFromChild(TE_Process arg, TE_Pipe fromChild) */

TE_Process TE_setProcessFromChild(TE_Process arg, TE_Pipe fromChild)
{
  if (TE_isProcessDefault(arg)) {
    return (TE_Process)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) fromChild), 1);
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
/*{{{  ATbool TE_hasPipeWrite(TE_Pipe arg) */

ATbool TE_hasPipeWrite(TE_Pipe arg)
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
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  int TE_getPipeWrite(TE_Pipe arg) */

int TE_getPipeWrite(TE_Pipe arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  TE_Pipe TE_setPipeRead(TE_Pipe arg, int read) */

TE_Pipe TE_setPipeRead(TE_Pipe arg, int read)
{
  if (TE_isPipeDefault(arg)) {
    return (TE_Pipe)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(read)), 0);
  }

  ATabort("Pipe has no Read: %t\n", arg);
  return (TE_Pipe)NULL;
}

/*}}}  */
/*{{{  TE_Pipe TE_setPipeWrite(TE_Pipe arg, int write) */

TE_Pipe TE_setPipeWrite(TE_Pipe arg, int write)
{
  if (TE_isPipeDefault(arg)) {
    return (TE_Pipe)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(write)), 1);
  }

  ATabort("Pipe has no Write: %t\n", arg);
  return (TE_Pipe)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  TE_Action TE_visitAction(TE_Action arg, char* (*acceptMessage)(char*), int (*acceptOffset)(int), ATerm (*acceptFocus)(ATerm), TE_ActionList (*acceptActions)(TE_ActionList)) */

TE_Action TE_visitAction(TE_Action arg, char* (*acceptMessage)(char*), int (*acceptOffset)(int), ATerm (*acceptFocus)(ATerm), TE_ActionList (*acceptActions)(TE_ActionList))
{
  if (TE_isActionToFront(arg)) {
    return TE_makeActionToFront();
  }
  if (TE_isActionQuit(arg)) {
    return TE_makeActionQuit();
  }
  if (TE_isActionIsModified(arg)) {
    return TE_makeActionIsModified();
  }
  if (TE_isActionWriteContents(arg)) {
    return TE_makeActionWriteContents();
  }
  if (TE_isActionRereadContents(arg)) {
    return TE_makeActionRereadContents();
  }
  if (TE_isActionDisplayMessage(arg)) {
    return TE_makeActionDisplayMessage(
        acceptMessage ? acceptMessage(TE_getActionMessage(arg)) : TE_getActionMessage(arg));
  }
  if (TE_isActionSetCursorAtOffset(arg)) {
    return TE_makeActionSetCursorAtOffset(
        acceptOffset ? acceptOffset(TE_getActionOffset(arg)) : TE_getActionOffset(arg));
  }
  if (TE_isActionSetFocus(arg)) {
    return TE_makeActionSetFocus(
        acceptFocus ? acceptFocus(TE_getActionFocus(arg)) : TE_getActionFocus(arg));
  }
  if (TE_isActionClearFocus(arg)) {
    return TE_makeActionClearFocus();
  }
  if (TE_isActionAddActions(arg)) {
    return TE_makeActionAddActions(
        acceptActions ? acceptActions(TE_getActionActions(arg)) : TE_getActionActions(arg));
  }
  ATabort("not a Action: %t\n", arg);
  return (TE_Action)NULL;
}

/*}}}  */
/*{{{  TE_Menu TE_visitMenu(TE_Menu arg, TE_Items (*acceptItems)(TE_Items), char* (*acceptShortcut)(char*)) */

TE_Menu TE_visitMenu(TE_Menu arg, TE_Items (*acceptItems)(TE_Items), char* (*acceptShortcut)(char*))
{
  if (TE_isMenuDefault(arg)) {
    return TE_makeMenuDefault(
        acceptItems ? acceptItems(TE_getMenuItems(arg)) : TE_getMenuItems(arg));
  }
  if (TE_isMenuShortcut(arg)) {
    return TE_makeMenuShortcut(
        acceptItems ? acceptItems(TE_getMenuItems(arg)) : TE_getMenuItems(arg),
        acceptShortcut ? acceptShortcut(TE_getMenuShortcut(arg)) : TE_getMenuShortcut(arg));
  }
  ATabort("not a Menu: %t\n", arg);
  return (TE_Menu)NULL;
}

/*}}}  */
/*{{{  TE_ActionList TE_visitActionList(TE_ActionList arg, TE_Menu (*acceptHead)(TE_Menu)) */

TE_ActionList TE_visitActionList(TE_ActionList arg, TE_Menu (*acceptHead)(TE_Menu))
{
  if (TE_isActionListEmpty(arg)) {
    return TE_makeActionListEmpty();
  }
  if (TE_isActionListSingle(arg)) {
    return TE_makeActionListSingle(
        acceptHead ? acceptHead(TE_getActionListHead(arg)) : TE_getActionListHead(arg));
  }
  if (TE_isActionListMany(arg)) {
    return TE_makeActionListMany(
        acceptHead ? acceptHead(TE_getActionListHead(arg)) : TE_getActionListHead(arg),
        TE_visitActionList(TE_getActionListTail(arg), acceptHead));
  }
  ATabort("not a ActionList: %t\n", arg);
  return (TE_ActionList)NULL;
}

/*}}}  */
/*{{{  TE_Items TE_visitItems(TE_Items arg, char* (*acceptHead)(char*)) */

TE_Items TE_visitItems(TE_Items arg, char* (*acceptHead)(char*))
{
  if (TE_isItemsEmpty(arg)) {
    return TE_makeItemsEmpty();
  }
  if (TE_isItemsSingle(arg)) {
    return TE_makeItemsSingle(
        acceptHead ? acceptHead(TE_getItemsHead(arg)) : TE_getItemsHead(arg));
  }
  if (TE_isItemsMany(arg)) {
    return TE_makeItemsMany(
        acceptHead ? acceptHead(TE_getItemsHead(arg)) : TE_getItemsHead(arg),
        TE_visitItems(TE_getItemsTail(arg), acceptHead));
  }
  ATabort("not a Items: %t\n", arg);
  return (TE_Items)NULL;
}

/*}}}  */
/*{{{  TE_Event TE_visitEvent(TE_Event arg, TE_Menu (*acceptMenu)(TE_Menu), int (*acceptLocation)(int), int (*acceptModified)(int)) */

TE_Event TE_visitEvent(TE_Event arg, TE_Menu (*acceptMenu)(TE_Menu), int (*acceptLocation)(int), int (*acceptModified)(int))
{
  if (TE_isEventMenu(arg)) {
    return TE_makeEventMenu(
        acceptMenu ? acceptMenu(TE_getEventMenu(arg)) : TE_getEventMenu(arg));
  }
  if (TE_isEventMouse(arg)) {
    return TE_makeEventMouse(
        acceptLocation ? acceptLocation(TE_getEventLocation(arg)) : TE_getEventLocation(arg));
  }
  if (TE_isEventContentsWritten(arg)) {
    return TE_makeEventContentsWritten();
  }
  if (TE_isEventModified(arg)) {
    return TE_makeEventModified();
  }
  if (TE_isEventIsModified(arg)) {
    return TE_makeEventIsModified(
        acceptModified ? acceptModified(TE_getEventModified(arg)) : TE_getEventModified(arg));
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
