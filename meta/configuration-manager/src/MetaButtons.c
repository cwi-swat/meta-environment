#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "MetaButtons.h"

/*{{{  typedefs */

typedef struct ATerm _MB_Buttons;
typedef struct ATerm _MB_ButtonList;
typedef struct ATerm _MB_Button;
typedef struct ATerm _MB_EditorType;
typedef struct ATerm _MB_ModuleName;

/*}}}  */

/*{{{  void MB_initMetaButtonsApi(void) */

void MB_initMetaButtonsApi(void)
{
  init_MetaButtons_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  MB_Buttons MB_ButtonsFromTerm(ATerm t) */

MB_Buttons MB_ButtonsFromTerm(ATerm t)
{
  return (MB_Buttons)t;
}

/*}}}  */
/*{{{  ATerm MB_ButtonsToTerm(MB_Buttons arg) */

ATerm MB_ButtonsToTerm(MB_Buttons arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MB_ButtonList MB_ButtonListFromTerm(ATerm t) */

MB_ButtonList MB_ButtonListFromTerm(ATerm t)
{
  return (MB_ButtonList)t;
}

/*}}}  */
/*{{{  ATerm MB_ButtonListToTerm(MB_ButtonList arg) */

ATerm MB_ButtonListToTerm(MB_ButtonList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MB_Button MB_ButtonFromTerm(ATerm t) */

MB_Button MB_ButtonFromTerm(ATerm t)
{
  return (MB_Button)t;
}

/*}}}  */
/*{{{  ATerm MB_ButtonToTerm(MB_Button arg) */

ATerm MB_ButtonToTerm(MB_Button arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MB_EditorType MB_EditorTypeFromTerm(ATerm t) */

MB_EditorType MB_EditorTypeFromTerm(ATerm t)
{
  return (MB_EditorType)t;
}

/*}}}  */
/*{{{  ATerm MB_EditorTypeToTerm(MB_EditorType arg) */

ATerm MB_EditorTypeToTerm(MB_EditorType arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MB_ModuleName MB_ModuleNameFromTerm(ATerm t) */

MB_ModuleName MB_ModuleNameFromTerm(ATerm t)
{
  return (MB_ModuleName)t;
}

/*}}}  */
/*{{{  ATerm MB_ModuleNameToTerm(MB_ModuleName arg) */

ATerm MB_ModuleNameToTerm(MB_ModuleName arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  MB_Buttons MB_makeButtonsList(MB_ButtonList list) */

MB_Buttons MB_makeButtonsList(MB_ButtonList list)
{
  return (MB_Buttons)(ATerm)ATmakeAppl1(MB_afun0, (ATerm)list);
}

/*}}}  */
/*{{{  MB_ButtonList MB_makeButtonListEmpty() */

MB_ButtonList MB_makeButtonListEmpty()
{
  return (MB_ButtonList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MB_ButtonList MB_makeButtonListMany(MB_Button head, MB_ButtonList tail) */

MB_ButtonList MB_makeButtonListMany(MB_Button head, MB_ButtonList tail)
{
  return (MB_ButtonList)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  MB_Button MB_makeButtonEditor(char* module, MB_EditorType type, ATerm name, ATerm actions) */

MB_Button MB_makeButtonEditor(char* module, MB_EditorType type, ATerm name, ATerm actions)
{
  return (MB_Button)(ATerm)ATmakeAppl4(MB_afun1, (ATerm)ATmakeAppl0(ATmakeAFun(module, 0, ATtrue)), (ATerm)type, (ATerm)name, (ATerm)actions);
}

/*}}}  */
/*{{{  MB_EditorType MB_makeEditorTypeTerm() */

MB_EditorType MB_makeEditorTypeTerm()
{
  return (MB_EditorType)(ATerm)ATmakeAppl0(MB_afun2);
}

/*}}}  */
/*{{{  MB_EditorType MB_makeEditorTypeEquations() */

MB_EditorType MB_makeEditorTypeEquations()
{
  return (MB_EditorType)(ATerm)ATmakeAppl0(MB_afun3);
}

/*}}}  */
/*{{{  MB_EditorType MB_makeEditorTypeSyntax() */

MB_EditorType MB_makeEditorTypeSyntax()
{
  return (MB_EditorType)(ATerm)ATmakeAppl0(MB_afun4);
}

/*}}}  */
/*{{{  MB_EditorType MB_makeEditorTypeAll() */

MB_EditorType MB_makeEditorTypeAll()
{
  return (MB_EditorType)(ATerm)ATmakeAppl0(MB_afun5);
}

/*}}}  */
/*{{{  MB_ModuleName MB_makeModuleNameAll() */

MB_ModuleName MB_makeModuleNameAll()
{
  return (MB_ModuleName)(ATerm)ATmakeAppl0(MB_afun5);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool MB_isEqualButtons(MB_Buttons arg0, MB_Buttons arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MB_isEqualButtonList(MB_ButtonList arg0, MB_ButtonList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MB_isEqualButton(MB_Button arg0, MB_Button arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MB_isEqualEditorType(MB_EditorType arg0, MB_EditorType arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MB_isEqualModuleName(MB_ModuleName arg0, MB_ModuleName arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  MB_Buttons accessors */

/*{{{  ATbool MB_isValidButtons(MB_Buttons arg) */

ATbool MB_isValidButtons(MB_Buttons arg)
{
  if (MB_isButtonsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonsList(MB_Buttons arg) */

inline ATbool MB_isButtonsList(MB_Buttons arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MB_patternButtonsList, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonsList(MB_Buttons arg) */

ATbool MB_hasButtonsList(MB_Buttons arg)
{
  if (MB_isButtonsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MB_ButtonList MB_getButtonsList(MB_Buttons arg) */

MB_ButtonList MB_getButtonsList(MB_Buttons arg)
{
  
    return (MB_ButtonList)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  MB_Buttons MB_setButtonsList(MB_Buttons arg, MB_ButtonList list) */

MB_Buttons MB_setButtonsList(MB_Buttons arg, MB_ButtonList list)
{
  if (MB_isButtonsList(arg)) {
    return (MB_Buttons)ATsetArgument((ATermAppl)arg, (ATerm)list, 0);
  }

  ATabort("Buttons has no List: %t\n", arg);
  return (MB_Buttons)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MB_ButtonList accessors */

/*{{{  ATbool MB_isValidButtonList(MB_ButtonList arg) */

ATbool MB_isValidButtonList(MB_ButtonList arg)
{
  if (MB_isButtonListEmpty(arg)) {
    return ATtrue;
  }
  else if (MB_isButtonListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonListEmpty(MB_ButtonList arg) */

inline ATbool MB_isButtonListEmpty(MB_ButtonList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MB_patternButtonListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonListMany(MB_ButtonList arg) */

inline ATbool MB_isButtonListMany(MB_ButtonList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MB_patternButtonListMany, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonListHead(MB_ButtonList arg) */

ATbool MB_hasButtonListHead(MB_ButtonList arg)
{
  if (MB_isButtonListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MB_Button MB_getButtonListHead(MB_ButtonList arg) */

MB_Button MB_getButtonListHead(MB_ButtonList arg)
{
  
    return (MB_Button)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MB_ButtonList MB_setButtonListHead(MB_ButtonList arg, MB_Button head) */

MB_ButtonList MB_setButtonListHead(MB_ButtonList arg, MB_Button head)
{
  if (MB_isButtonListMany(arg)) {
    return (MB_ButtonList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ButtonList has no Head: %t\n", arg);
  return (MB_ButtonList)NULL;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonListTail(MB_ButtonList arg) */

ATbool MB_hasButtonListTail(MB_ButtonList arg)
{
  if (MB_isButtonListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MB_ButtonList MB_getButtonListTail(MB_ButtonList arg) */

MB_ButtonList MB_getButtonListTail(MB_ButtonList arg)
{
  
    return (MB_ButtonList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  MB_ButtonList MB_setButtonListTail(MB_ButtonList arg, MB_ButtonList tail) */

MB_ButtonList MB_setButtonListTail(MB_ButtonList arg, MB_ButtonList tail)
{
  if (MB_isButtonListMany(arg)) {
    return (MB_ButtonList)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("ButtonList has no Tail: %t\n", arg);
  return (MB_ButtonList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MB_Button accessors */

/*{{{  ATbool MB_isValidButton(MB_Button arg) */

ATbool MB_isValidButton(MB_Button arg)
{
  if (MB_isButtonEditor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonEditor(MB_Button arg) */

inline ATbool MB_isButtonEditor(MB_Button arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MB_patternButtonEditor, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonModule(MB_Button arg) */

ATbool MB_hasButtonModule(MB_Button arg)
{
  if (MB_isButtonEditor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MB_getButtonModule(MB_Button arg) */

char* MB_getButtonModule(MB_Button arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  MB_Button MB_setButtonModule(MB_Button arg, char* module) */

MB_Button MB_setButtonModule(MB_Button arg, char* module)
{
  if (MB_isButtonEditor(arg)) {
    return (MB_Button)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(module, 0, ATtrue)), 0);
  }

  ATabort("Button has no Module: %t\n", arg);
  return (MB_Button)NULL;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonType(MB_Button arg) */

ATbool MB_hasButtonType(MB_Button arg)
{
  if (MB_isButtonEditor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MB_EditorType MB_getButtonType(MB_Button arg) */

MB_EditorType MB_getButtonType(MB_Button arg)
{
  
    return (MB_EditorType)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  MB_Button MB_setButtonType(MB_Button arg, MB_EditorType type) */

MB_Button MB_setButtonType(MB_Button arg, MB_EditorType type)
{
  if (MB_isButtonEditor(arg)) {
    return (MB_Button)ATsetArgument((ATermAppl)arg, (ATerm)type, 1);
  }

  ATabort("Button has no Type: %t\n", arg);
  return (MB_Button)NULL;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonName(MB_Button arg) */

ATbool MB_hasButtonName(MB_Button arg)
{
  if (MB_isButtonEditor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm MB_getButtonName(MB_Button arg) */

ATerm MB_getButtonName(MB_Button arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  MB_Button MB_setButtonName(MB_Button arg, ATerm name) */

MB_Button MB_setButtonName(MB_Button arg, ATerm name)
{
  if (MB_isButtonEditor(arg)) {
    return (MB_Button)ATsetArgument((ATermAppl)arg, (ATerm)name, 2);
  }

  ATabort("Button has no Name: %t\n", arg);
  return (MB_Button)NULL;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonActions(MB_Button arg) */

ATbool MB_hasButtonActions(MB_Button arg)
{
  if (MB_isButtonEditor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm MB_getButtonActions(MB_Button arg) */

ATerm MB_getButtonActions(MB_Button arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 3);
}

/*}}}  */
/*{{{  MB_Button MB_setButtonActions(MB_Button arg, ATerm actions) */

MB_Button MB_setButtonActions(MB_Button arg, ATerm actions)
{
  if (MB_isButtonEditor(arg)) {
    return (MB_Button)ATsetArgument((ATermAppl)arg, (ATerm)actions, 3);
  }

  ATabort("Button has no Actions: %t\n", arg);
  return (MB_Button)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MB_EditorType accessors */

/*{{{  ATbool MB_isValidEditorType(MB_EditorType arg) */

ATbool MB_isValidEditorType(MB_EditorType arg)
{
  if (MB_isEditorTypeTerm(arg)) {
    return ATtrue;
  }
  else if (MB_isEditorTypeEquations(arg)) {
    return ATtrue;
  }
  else if (MB_isEditorTypeSyntax(arg)) {
    return ATtrue;
  }
  else if (MB_isEditorTypeAll(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MB_isEditorTypeTerm(MB_EditorType arg) */

inline ATbool MB_isEditorTypeTerm(MB_EditorType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MB_patternEditorTypeTerm);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MB_isEditorTypeEquations(MB_EditorType arg) */

inline ATbool MB_isEditorTypeEquations(MB_EditorType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MB_patternEditorTypeEquations);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MB_isEditorTypeSyntax(MB_EditorType arg) */

inline ATbool MB_isEditorTypeSyntax(MB_EditorType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MB_patternEditorTypeSyntax);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MB_isEditorTypeAll(MB_EditorType arg) */

inline ATbool MB_isEditorTypeAll(MB_EditorType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MB_patternEditorTypeAll);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  MB_ModuleName accessors */

/*{{{  ATbool MB_isValidModuleName(MB_ModuleName arg) */

ATbool MB_isValidModuleName(MB_ModuleName arg)
{
  if (MB_isModuleNameAll(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MB_isModuleNameAll(MB_ModuleName arg) */

inline ATbool MB_isModuleNameAll(MB_ModuleName arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MB_patternModuleNameAll));
#endif
  return ATtrue;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  MB_Buttons MB_visitButtons(MB_Buttons arg, MB_ButtonList (*acceptList)(MB_ButtonList)) */

MB_Buttons MB_visitButtons(MB_Buttons arg, MB_ButtonList (*acceptList)(MB_ButtonList))
{
  if (MB_isButtonsList(arg)) {
    return MB_makeButtonsList(
        acceptList ? acceptList(MB_getButtonsList(arg)) : MB_getButtonsList(arg));
  }
  ATabort("not a Buttons: %t\n", arg);
  return (MB_Buttons)NULL;
}

/*}}}  */
/*{{{  MB_ButtonList MB_visitButtonList(MB_ButtonList arg, MB_Button (*acceptHead)(MB_Button)) */

MB_ButtonList MB_visitButtonList(MB_ButtonList arg, MB_Button (*acceptHead)(MB_Button))
{
  if (MB_isButtonListEmpty(arg)) {
    return MB_makeButtonListEmpty();
  }
  if (MB_isButtonListMany(arg)) {
    return MB_makeButtonListMany(
        acceptHead ? acceptHead(MB_getButtonListHead(arg)) : MB_getButtonListHead(arg),
        MB_visitButtonList(MB_getButtonListTail(arg), acceptHead));
  }
  ATabort("not a ButtonList: %t\n", arg);
  return (MB_ButtonList)NULL;
}

/*}}}  */
/*{{{  MB_Button MB_visitButton(MB_Button arg, char* (*acceptModule)(char*), MB_EditorType (*acceptType)(MB_EditorType), ATerm (*acceptName)(ATerm), ATerm (*acceptActions)(ATerm)) */

MB_Button MB_visitButton(MB_Button arg, char* (*acceptModule)(char*), MB_EditorType (*acceptType)(MB_EditorType), ATerm (*acceptName)(ATerm), ATerm (*acceptActions)(ATerm))
{
  if (MB_isButtonEditor(arg)) {
    return MB_makeButtonEditor(
        acceptModule ? acceptModule(MB_getButtonModule(arg)) : MB_getButtonModule(arg),
        acceptType ? acceptType(MB_getButtonType(arg)) : MB_getButtonType(arg),
        acceptName ? acceptName(MB_getButtonName(arg)) : MB_getButtonName(arg),
        acceptActions ? acceptActions(MB_getButtonActions(arg)) : MB_getButtonActions(arg));
  }
  ATabort("not a Button: %t\n", arg);
  return (MB_Button)NULL;
}

/*}}}  */
/*{{{  MB_EditorType MB_visitEditorType(MB_EditorType arg) */

MB_EditorType MB_visitEditorType(MB_EditorType arg)
{
  if (MB_isEditorTypeTerm(arg)) {
    return MB_makeEditorTypeTerm();
  }
  if (MB_isEditorTypeEquations(arg)) {
    return MB_makeEditorTypeEquations();
  }
  if (MB_isEditorTypeSyntax(arg)) {
    return MB_makeEditorTypeSyntax();
  }
  if (MB_isEditorTypeAll(arg)) {
    return MB_makeEditorTypeAll();
  }
  ATabort("not a EditorType: %t\n", arg);
  return (MB_EditorType)NULL;
}

/*}}}  */
/*{{{  MB_ModuleName MB_visitModuleName(MB_ModuleName arg) */

MB_ModuleName MB_visitModuleName(MB_ModuleName arg)
{
  if (MB_isModuleNameAll(arg)) {
    return MB_makeModuleNameAll();
  }
  ATabort("not a ModuleName: %t\n", arg);
  return (MB_ModuleName)NULL;
}

/*}}}  */

/*}}}  */
