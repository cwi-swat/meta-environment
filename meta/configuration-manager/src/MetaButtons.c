#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "MetaButtons.h"

/*{{{  typedefs */

typedef struct ATerm _MB_Buttons;
typedef struct ATerm _MB_ButtonList;
typedef struct ATerm _MB_Button;
typedef struct ATerm _MB_ButtonDescriptionList;
typedef struct ATerm _MB_ButtonDescription;
typedef struct ATerm _MB_ButtonType;
typedef struct ATerm _MB_ButtonArgs;
typedef struct ATerm _MB_MenuTitles;
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
/*{{{  MB_ButtonDescriptionList MB_ButtonDescriptionListFromTerm(ATerm t) */

MB_ButtonDescriptionList MB_ButtonDescriptionListFromTerm(ATerm t)
{
  return (MB_ButtonDescriptionList)t;
}

/*}}}  */
/*{{{  ATerm MB_ButtonDescriptionListToTerm(MB_ButtonDescriptionList arg) */

ATerm MB_ButtonDescriptionListToTerm(MB_ButtonDescriptionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MB_ButtonDescription MB_ButtonDescriptionFromTerm(ATerm t) */

MB_ButtonDescription MB_ButtonDescriptionFromTerm(ATerm t)
{
  return (MB_ButtonDescription)t;
}

/*}}}  */
/*{{{  ATerm MB_ButtonDescriptionToTerm(MB_ButtonDescription arg) */

ATerm MB_ButtonDescriptionToTerm(MB_ButtonDescription arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MB_ButtonType MB_ButtonTypeFromTerm(ATerm t) */

MB_ButtonType MB_ButtonTypeFromTerm(ATerm t)
{
  return (MB_ButtonType)t;
}

/*}}}  */
/*{{{  ATerm MB_ButtonTypeToTerm(MB_ButtonType arg) */

ATerm MB_ButtonTypeToTerm(MB_ButtonType arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MB_ButtonArgs MB_ButtonArgsFromTerm(ATerm t) */

MB_ButtonArgs MB_ButtonArgsFromTerm(ATerm t)
{
  return (MB_ButtonArgs)t;
}

/*}}}  */
/*{{{  ATerm MB_ButtonArgsToTerm(MB_ButtonArgs arg) */

ATerm MB_ButtonArgsToTerm(MB_ButtonArgs arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MB_MenuTitles MB_MenuTitlesFromTerm(ATerm t) */

MB_MenuTitles MB_MenuTitlesFromTerm(ATerm t)
{
  return (MB_MenuTitles)t;
}

/*}}}  */
/*{{{  ATerm MB_MenuTitlesToTerm(MB_MenuTitles arg) */

ATerm MB_MenuTitlesToTerm(MB_MenuTitles arg)
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
/*{{{  MB_Button MB_makeButtonDefault(char* module, MB_ButtonDescriptionList descriptions, ATerm actions) */

MB_Button MB_makeButtonDefault(char* module, MB_ButtonDescriptionList descriptions, ATerm actions)
{
  return (MB_Button)(ATerm)ATmakeAppl3(MB_afun1, (ATerm)ATmakeAppl0(ATmakeAFun(module, 0, ATtrue)), (ATerm)descriptions, (ATerm)actions);
}

/*}}}  */
/*{{{  MB_ButtonDescriptionList MB_makeButtonDescriptionListEmpty() */

MB_ButtonDescriptionList MB_makeButtonDescriptionListEmpty()
{
  return (MB_ButtonDescriptionList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MB_ButtonDescriptionList MB_makeButtonDescriptionListMany(MB_ButtonDescription head, MB_ButtonDescriptionList tail) */

MB_ButtonDescriptionList MB_makeButtonDescriptionListMany(MB_ButtonDescription head, MB_ButtonDescriptionList tail)
{
  return (MB_ButtonDescriptionList)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  MB_ButtonDescription MB_makeButtonDescriptionDefault(MB_ButtonType type, MB_ButtonArgs args) */

MB_ButtonDescription MB_makeButtonDescriptionDefault(MB_ButtonType type, MB_ButtonArgs args)
{
  return (MB_ButtonDescription)(ATerm)ATmakeAppl2(MB_afun2, (ATerm)type, (ATerm)args);
}

/*}}}  */
/*{{{  MB_ButtonType MB_makeButtonTypeTerm() */

MB_ButtonType MB_makeButtonTypeTerm()
{
  return (MB_ButtonType)(ATerm)ATmakeAppl0(MB_afun3);
}

/*}}}  */
/*{{{  MB_ButtonType MB_makeButtonTypeEquations() */

MB_ButtonType MB_makeButtonTypeEquations()
{
  return (MB_ButtonType)(ATerm)ATmakeAppl0(MB_afun4);
}

/*}}}  */
/*{{{  MB_ButtonType MB_makeButtonTypeSyntax() */

MB_ButtonType MB_makeButtonTypeSyntax()
{
  return (MB_ButtonType)(ATerm)ATmakeAppl0(MB_afun5);
}

/*}}}  */
/*{{{  MB_ButtonType MB_makeButtonTypeMessageList() */

MB_ButtonType MB_makeButtonTypeMessageList()
{
  return (MB_ButtonType)(ATerm)ATmakeAppl0(MB_afun6);
}

/*}}}  */
/*{{{  MB_ButtonType MB_makeButtonTypeModulePopup() */

MB_ButtonType MB_makeButtonTypeModulePopup()
{
  return (MB_ButtonType)(ATerm)ATmakeAppl0(MB_afun7);
}

/*}}}  */
/*{{{  MB_ButtonType MB_makeButtonTypeNewModulePopup() */

MB_ButtonType MB_makeButtonTypeNewModulePopup()
{
  return (MB_ButtonType)(ATerm)ATmakeAppl0(MB_afun8);
}

/*}}}  */
/*{{{  MB_ButtonType MB_makeButtonTypeStudioMenubar() */

MB_ButtonType MB_makeButtonTypeStudioMenubar()
{
  return (MB_ButtonType)(ATerm)ATmakeAppl0(MB_afun9);
}

/*}}}  */
/*{{{  MB_ButtonType MB_makeButtonTypeStudioToolbar() */

MB_ButtonType MB_makeButtonTypeStudioToolbar()
{
  return (MB_ButtonType)(ATerm)ATmakeAppl0(MB_afun10);
}

/*}}}  */
/*{{{  MB_ButtonType MB_makeButtonTypeWildcard() */

MB_ButtonType MB_makeButtonTypeWildcard()
{
  return (MB_ButtonType)(ATerm)ATmakeAppl0(MB_afun11);
}

/*}}}  */
/*{{{  MB_ButtonArgs MB_makeButtonArgsMenu(MB_MenuTitles list) */

MB_ButtonArgs MB_makeButtonArgsMenu(MB_MenuTitles list)
{
  return (MB_ButtonArgs)(ATerm)ATmakeAppl1(MB_afun12, (ATerm)list);
}

/*}}}  */
/*{{{  MB_ButtonArgs MB_makeButtonArgsIcon(char* title, char* path) */

MB_ButtonArgs MB_makeButtonArgsIcon(char* title, char* path)
{
  return (MB_ButtonArgs)(ATerm)ATmakeAppl2(MB_afun13, (ATerm)ATmakeAppl0(ATmakeAFun(title, 0, ATtrue)), (ATerm)ATmakeAppl0(ATmakeAFun(path, 0, ATtrue)));
}

/*}}}  */
/*{{{  MB_MenuTitles MB_makeMenuTitlesEmpty() */

MB_MenuTitles MB_makeMenuTitlesEmpty()
{
  return (MB_MenuTitles)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MB_MenuTitles MB_makeMenuTitlesMany(char* head, MB_MenuTitles tail) */

MB_MenuTitles MB_makeMenuTitlesMany(char* head, MB_MenuTitles tail)
{
  return (MB_MenuTitles)(ATerm)ATinsert((ATermList)tail, (ATerm)ATmakeAppl0(ATmakeAFun(head, 0, ATtrue)));
}

/*}}}  */
/*{{{  MB_ModuleName MB_makeModuleNameWildcard() */

MB_ModuleName MB_makeModuleNameWildcard()
{
  return (MB_ModuleName)(ATerm)ATmakeAppl0(MB_afun11);
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

ATbool MB_isEqualButtonDescriptionList(MB_ButtonDescriptionList arg0, MB_ButtonDescriptionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MB_isEqualButtonDescription(MB_ButtonDescription arg0, MB_ButtonDescription arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MB_isEqualButtonType(MB_ButtonType arg0, MB_ButtonType arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MB_isEqualButtonArgs(MB_ButtonArgs arg0, MB_ButtonArgs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MB_isEqualMenuTitles(MB_MenuTitles arg0, MB_MenuTitles arg1)
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
  if (MB_isButtonDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonDefault(MB_Button arg) */

inline ATbool MB_isButtonDefault(MB_Button arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MB_patternButtonDefault, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonModule(MB_Button arg) */

ATbool MB_hasButtonModule(MB_Button arg)
{
  if (MB_isButtonDefault(arg)) {
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
  if (MB_isButtonDefault(arg)) {
    return (MB_Button)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(module, 0, ATtrue)), 0);
  }

  ATabort("Button has no Module: %t\n", arg);
  return (MB_Button)NULL;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonDescriptions(MB_Button arg) */

ATbool MB_hasButtonDescriptions(MB_Button arg)
{
  if (MB_isButtonDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MB_ButtonDescriptionList MB_getButtonDescriptions(MB_Button arg) */

MB_ButtonDescriptionList MB_getButtonDescriptions(MB_Button arg)
{
  
    return (MB_ButtonDescriptionList)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  MB_Button MB_setButtonDescriptions(MB_Button arg, MB_ButtonDescriptionList descriptions) */

MB_Button MB_setButtonDescriptions(MB_Button arg, MB_ButtonDescriptionList descriptions)
{
  if (MB_isButtonDefault(arg)) {
    return (MB_Button)ATsetArgument((ATermAppl)arg, (ATerm)descriptions, 1);
  }

  ATabort("Button has no Descriptions: %t\n", arg);
  return (MB_Button)NULL;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonActions(MB_Button arg) */

ATbool MB_hasButtonActions(MB_Button arg)
{
  if (MB_isButtonDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm MB_getButtonActions(MB_Button arg) */

ATerm MB_getButtonActions(MB_Button arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  MB_Button MB_setButtonActions(MB_Button arg, ATerm actions) */

MB_Button MB_setButtonActions(MB_Button arg, ATerm actions)
{
  if (MB_isButtonDefault(arg)) {
    return (MB_Button)ATsetArgument((ATermAppl)arg, (ATerm)actions, 2);
  }

  ATabort("Button has no Actions: %t\n", arg);
  return (MB_Button)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MB_ButtonDescriptionList accessors */

/*{{{  ATbool MB_isValidButtonDescriptionList(MB_ButtonDescriptionList arg) */

ATbool MB_isValidButtonDescriptionList(MB_ButtonDescriptionList arg)
{
  if (MB_isButtonDescriptionListEmpty(arg)) {
    return ATtrue;
  }
  else if (MB_isButtonDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonDescriptionListEmpty(MB_ButtonDescriptionList arg) */

inline ATbool MB_isButtonDescriptionListEmpty(MB_ButtonDescriptionList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MB_patternButtonDescriptionListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonDescriptionListMany(MB_ButtonDescriptionList arg) */

inline ATbool MB_isButtonDescriptionListMany(MB_ButtonDescriptionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MB_patternButtonDescriptionListMany, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonDescriptionListHead(MB_ButtonDescriptionList arg) */

ATbool MB_hasButtonDescriptionListHead(MB_ButtonDescriptionList arg)
{
  if (MB_isButtonDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MB_ButtonDescription MB_getButtonDescriptionListHead(MB_ButtonDescriptionList arg) */

MB_ButtonDescription MB_getButtonDescriptionListHead(MB_ButtonDescriptionList arg)
{
  
    return (MB_ButtonDescription)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MB_ButtonDescriptionList MB_setButtonDescriptionListHead(MB_ButtonDescriptionList arg, MB_ButtonDescription head) */

MB_ButtonDescriptionList MB_setButtonDescriptionListHead(MB_ButtonDescriptionList arg, MB_ButtonDescription head)
{
  if (MB_isButtonDescriptionListMany(arg)) {
    return (MB_ButtonDescriptionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ButtonDescriptionList has no Head: %t\n", arg);
  return (MB_ButtonDescriptionList)NULL;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonDescriptionListTail(MB_ButtonDescriptionList arg) */

ATbool MB_hasButtonDescriptionListTail(MB_ButtonDescriptionList arg)
{
  if (MB_isButtonDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MB_ButtonDescriptionList MB_getButtonDescriptionListTail(MB_ButtonDescriptionList arg) */

MB_ButtonDescriptionList MB_getButtonDescriptionListTail(MB_ButtonDescriptionList arg)
{
  
    return (MB_ButtonDescriptionList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  MB_ButtonDescriptionList MB_setButtonDescriptionListTail(MB_ButtonDescriptionList arg, MB_ButtonDescriptionList tail) */

MB_ButtonDescriptionList MB_setButtonDescriptionListTail(MB_ButtonDescriptionList arg, MB_ButtonDescriptionList tail)
{
  if (MB_isButtonDescriptionListMany(arg)) {
    return (MB_ButtonDescriptionList)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("ButtonDescriptionList has no Tail: %t\n", arg);
  return (MB_ButtonDescriptionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MB_ButtonDescription accessors */

/*{{{  ATbool MB_isValidButtonDescription(MB_ButtonDescription arg) */

ATbool MB_isValidButtonDescription(MB_ButtonDescription arg)
{
  if (MB_isButtonDescriptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonDescriptionDefault(MB_ButtonDescription arg) */

inline ATbool MB_isButtonDescriptionDefault(MB_ButtonDescription arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MB_patternButtonDescriptionDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonDescriptionType(MB_ButtonDescription arg) */

ATbool MB_hasButtonDescriptionType(MB_ButtonDescription arg)
{
  if (MB_isButtonDescriptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MB_ButtonType MB_getButtonDescriptionType(MB_ButtonDescription arg) */

MB_ButtonType MB_getButtonDescriptionType(MB_ButtonDescription arg)
{
  
    return (MB_ButtonType)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  MB_ButtonDescription MB_setButtonDescriptionType(MB_ButtonDescription arg, MB_ButtonType type) */

MB_ButtonDescription MB_setButtonDescriptionType(MB_ButtonDescription arg, MB_ButtonType type)
{
  if (MB_isButtonDescriptionDefault(arg)) {
    return (MB_ButtonDescription)ATsetArgument((ATermAppl)arg, (ATerm)type, 0);
  }

  ATabort("ButtonDescription has no Type: %t\n", arg);
  return (MB_ButtonDescription)NULL;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonDescriptionArgs(MB_ButtonDescription arg) */

ATbool MB_hasButtonDescriptionArgs(MB_ButtonDescription arg)
{
  if (MB_isButtonDescriptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MB_ButtonArgs MB_getButtonDescriptionArgs(MB_ButtonDescription arg) */

MB_ButtonArgs MB_getButtonDescriptionArgs(MB_ButtonDescription arg)
{
  
    return (MB_ButtonArgs)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  MB_ButtonDescription MB_setButtonDescriptionArgs(MB_ButtonDescription arg, MB_ButtonArgs args) */

MB_ButtonDescription MB_setButtonDescriptionArgs(MB_ButtonDescription arg, MB_ButtonArgs args)
{
  if (MB_isButtonDescriptionDefault(arg)) {
    return (MB_ButtonDescription)ATsetArgument((ATermAppl)arg, (ATerm)args, 1);
  }

  ATabort("ButtonDescription has no Args: %t\n", arg);
  return (MB_ButtonDescription)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MB_ButtonType accessors */

/*{{{  ATbool MB_isValidButtonType(MB_ButtonType arg) */

ATbool MB_isValidButtonType(MB_ButtonType arg)
{
  if (MB_isButtonTypeTerm(arg)) {
    return ATtrue;
  }
  else if (MB_isButtonTypeEquations(arg)) {
    return ATtrue;
  }
  else if (MB_isButtonTypeSyntax(arg)) {
    return ATtrue;
  }
  else if (MB_isButtonTypeMessageList(arg)) {
    return ATtrue;
  }
  else if (MB_isButtonTypeModulePopup(arg)) {
    return ATtrue;
  }
  else if (MB_isButtonTypeNewModulePopup(arg)) {
    return ATtrue;
  }
  else if (MB_isButtonTypeStudioMenubar(arg)) {
    return ATtrue;
  }
  else if (MB_isButtonTypeStudioToolbar(arg)) {
    return ATtrue;
  }
  else if (MB_isButtonTypeWildcard(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonTypeTerm(MB_ButtonType arg) */

inline ATbool MB_isButtonTypeTerm(MB_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MB_patternButtonTypeTerm);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonTypeEquations(MB_ButtonType arg) */

inline ATbool MB_isButtonTypeEquations(MB_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MB_patternButtonTypeEquations);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonTypeSyntax(MB_ButtonType arg) */

inline ATbool MB_isButtonTypeSyntax(MB_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MB_patternButtonTypeSyntax);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonTypeMessageList(MB_ButtonType arg) */

inline ATbool MB_isButtonTypeMessageList(MB_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MB_patternButtonTypeMessageList);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonTypeModulePopup(MB_ButtonType arg) */

inline ATbool MB_isButtonTypeModulePopup(MB_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MB_patternButtonTypeModulePopup);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonTypeNewModulePopup(MB_ButtonType arg) */

inline ATbool MB_isButtonTypeNewModulePopup(MB_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MB_patternButtonTypeNewModulePopup);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonTypeStudioMenubar(MB_ButtonType arg) */

inline ATbool MB_isButtonTypeStudioMenubar(MB_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MB_patternButtonTypeStudioMenubar);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonTypeStudioToolbar(MB_ButtonType arg) */

inline ATbool MB_isButtonTypeStudioToolbar(MB_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MB_patternButtonTypeStudioToolbar);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonTypeWildcard(MB_ButtonType arg) */

inline ATbool MB_isButtonTypeWildcard(MB_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MB_patternButtonTypeWildcard);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  MB_ButtonArgs accessors */

/*{{{  ATbool MB_isValidButtonArgs(MB_ButtonArgs arg) */

ATbool MB_isValidButtonArgs(MB_ButtonArgs arg)
{
  if (MB_isButtonArgsMenu(arg)) {
    return ATtrue;
  }
  else if (MB_isButtonArgsIcon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonArgsMenu(MB_ButtonArgs arg) */

inline ATbool MB_isButtonArgsMenu(MB_ButtonArgs arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MB_patternButtonArgsMenu, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MB_isButtonArgsIcon(MB_ButtonArgs arg) */

inline ATbool MB_isButtonArgsIcon(MB_ButtonArgs arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MB_patternButtonArgsIcon, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MB_hasButtonArgsList(MB_ButtonArgs arg) */

ATbool MB_hasButtonArgsList(MB_ButtonArgs arg)
{
  if (MB_isButtonArgsMenu(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MB_MenuTitles MB_getButtonArgsList(MB_ButtonArgs arg) */

MB_MenuTitles MB_getButtonArgsList(MB_ButtonArgs arg)
{
  
    return (MB_MenuTitles)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  MB_ButtonArgs MB_setButtonArgsList(MB_ButtonArgs arg, MB_MenuTitles list) */

MB_ButtonArgs MB_setButtonArgsList(MB_ButtonArgs arg, MB_MenuTitles list)
{
  if (MB_isButtonArgsMenu(arg)) {
    return (MB_ButtonArgs)ATsetArgument((ATermAppl)arg, (ATerm)list, 0);
  }

  ATabort("ButtonArgs has no List: %t\n", arg);
  return (MB_ButtonArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonArgsTitle(MB_ButtonArgs arg) */

ATbool MB_hasButtonArgsTitle(MB_ButtonArgs arg)
{
  if (MB_isButtonArgsIcon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MB_getButtonArgsTitle(MB_ButtonArgs arg) */

char* MB_getButtonArgsTitle(MB_ButtonArgs arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  MB_ButtonArgs MB_setButtonArgsTitle(MB_ButtonArgs arg, char* title) */

MB_ButtonArgs MB_setButtonArgsTitle(MB_ButtonArgs arg, char* title)
{
  if (MB_isButtonArgsIcon(arg)) {
    return (MB_ButtonArgs)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(title, 0, ATtrue)), 0);
  }

  ATabort("ButtonArgs has no Title: %t\n", arg);
  return (MB_ButtonArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MB_hasButtonArgsPath(MB_ButtonArgs arg) */

ATbool MB_hasButtonArgsPath(MB_ButtonArgs arg)
{
  if (MB_isButtonArgsIcon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MB_getButtonArgsPath(MB_ButtonArgs arg) */

char* MB_getButtonArgsPath(MB_ButtonArgs arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  MB_ButtonArgs MB_setButtonArgsPath(MB_ButtonArgs arg, char* path) */

MB_ButtonArgs MB_setButtonArgsPath(MB_ButtonArgs arg, char* path)
{
  if (MB_isButtonArgsIcon(arg)) {
    return (MB_ButtonArgs)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(path, 0, ATtrue)), 1);
  }

  ATabort("ButtonArgs has no Path: %t\n", arg);
  return (MB_ButtonArgs)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MB_MenuTitles accessors */

/*{{{  ATbool MB_isValidMenuTitles(MB_MenuTitles arg) */

ATbool MB_isValidMenuTitles(MB_MenuTitles arg)
{
  if (MB_isMenuTitlesEmpty(arg)) {
    return ATtrue;
  }
  else if (MB_isMenuTitlesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MB_isMenuTitlesEmpty(MB_MenuTitles arg) */

inline ATbool MB_isMenuTitlesEmpty(MB_MenuTitles arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MB_patternMenuTitlesEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MB_isMenuTitlesMany(MB_MenuTitles arg) */

inline ATbool MB_isMenuTitlesMany(MB_MenuTitles arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MB_patternMenuTitlesMany, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MB_hasMenuTitlesHead(MB_MenuTitles arg) */

ATbool MB_hasMenuTitlesHead(MB_MenuTitles arg)
{
  if (MB_isMenuTitlesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MB_getMenuTitlesHead(MB_MenuTitles arg) */

char* MB_getMenuTitlesHead(MB_MenuTitles arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetFirst((ATermList)arg)));
}

/*}}}  */
/*{{{  MB_MenuTitles MB_setMenuTitlesHead(MB_MenuTitles arg, char* head) */

MB_MenuTitles MB_setMenuTitlesHead(MB_MenuTitles arg, char* head)
{
  if (MB_isMenuTitlesMany(arg)) {
    return (MB_MenuTitles)ATreplace((ATermList)arg, (ATerm)ATmakeAppl0(ATmakeAFun(head, 0, ATtrue)), 0);
  }

  ATabort("MenuTitles has no Head: %t\n", arg);
  return (MB_MenuTitles)NULL;
}

/*}}}  */
/*{{{  ATbool MB_hasMenuTitlesTail(MB_MenuTitles arg) */

ATbool MB_hasMenuTitlesTail(MB_MenuTitles arg)
{
  if (MB_isMenuTitlesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MB_MenuTitles MB_getMenuTitlesTail(MB_MenuTitles arg) */

MB_MenuTitles MB_getMenuTitlesTail(MB_MenuTitles arg)
{
  
    return (MB_MenuTitles)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  MB_MenuTitles MB_setMenuTitlesTail(MB_MenuTitles arg, MB_MenuTitles tail) */

MB_MenuTitles MB_setMenuTitlesTail(MB_MenuTitles arg, MB_MenuTitles tail)
{
  if (MB_isMenuTitlesMany(arg)) {
    return (MB_MenuTitles)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("MenuTitles has no Tail: %t\n", arg);
  return (MB_MenuTitles)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MB_ModuleName accessors */

/*{{{  ATbool MB_isValidModuleName(MB_ModuleName arg) */

ATbool MB_isValidModuleName(MB_ModuleName arg)
{
  if (MB_isModuleNameWildcard(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MB_isModuleNameWildcard(MB_ModuleName arg) */

inline ATbool MB_isModuleNameWildcard(MB_ModuleName arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MB_patternModuleNameWildcard));
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
/*{{{  MB_Button MB_visitButton(MB_Button arg, char* (*acceptModule)(char*), MB_ButtonDescriptionList (*acceptDescriptions)(MB_ButtonDescriptionList), ATerm (*acceptActions)(ATerm)) */

MB_Button MB_visitButton(MB_Button arg, char* (*acceptModule)(char*), MB_ButtonDescriptionList (*acceptDescriptions)(MB_ButtonDescriptionList), ATerm (*acceptActions)(ATerm))
{
  if (MB_isButtonDefault(arg)) {
    return MB_makeButtonDefault(
        acceptModule ? acceptModule(MB_getButtonModule(arg)) : MB_getButtonModule(arg),
        acceptDescriptions ? acceptDescriptions(MB_getButtonDescriptions(arg)) : MB_getButtonDescriptions(arg),
        acceptActions ? acceptActions(MB_getButtonActions(arg)) : MB_getButtonActions(arg));
  }
  ATabort("not a Button: %t\n", arg);
  return (MB_Button)NULL;
}

/*}}}  */
/*{{{  MB_ButtonDescriptionList MB_visitButtonDescriptionList(MB_ButtonDescriptionList arg, MB_ButtonDescription (*acceptHead)(MB_ButtonDescription)) */

MB_ButtonDescriptionList MB_visitButtonDescriptionList(MB_ButtonDescriptionList arg, MB_ButtonDescription (*acceptHead)(MB_ButtonDescription))
{
  if (MB_isButtonDescriptionListEmpty(arg)) {
    return MB_makeButtonDescriptionListEmpty();
  }
  if (MB_isButtonDescriptionListMany(arg)) {
    return MB_makeButtonDescriptionListMany(
        acceptHead ? acceptHead(MB_getButtonDescriptionListHead(arg)) : MB_getButtonDescriptionListHead(arg),
        MB_visitButtonDescriptionList(MB_getButtonDescriptionListTail(arg), acceptHead));
  }
  ATabort("not a ButtonDescriptionList: %t\n", arg);
  return (MB_ButtonDescriptionList)NULL;
}

/*}}}  */
/*{{{  MB_ButtonDescription MB_visitButtonDescription(MB_ButtonDescription arg, MB_ButtonType (*acceptType)(MB_ButtonType), MB_ButtonArgs (*acceptArgs)(MB_ButtonArgs)) */

MB_ButtonDescription MB_visitButtonDescription(MB_ButtonDescription arg, MB_ButtonType (*acceptType)(MB_ButtonType), MB_ButtonArgs (*acceptArgs)(MB_ButtonArgs))
{
  if (MB_isButtonDescriptionDefault(arg)) {
    return MB_makeButtonDescriptionDefault(
        acceptType ? acceptType(MB_getButtonDescriptionType(arg)) : MB_getButtonDescriptionType(arg),
        acceptArgs ? acceptArgs(MB_getButtonDescriptionArgs(arg)) : MB_getButtonDescriptionArgs(arg));
  }
  ATabort("not a ButtonDescription: %t\n", arg);
  return (MB_ButtonDescription)NULL;
}

/*}}}  */
/*{{{  MB_ButtonType MB_visitButtonType(MB_ButtonType arg) */

MB_ButtonType MB_visitButtonType(MB_ButtonType arg)
{
  if (MB_isButtonTypeTerm(arg)) {
    return MB_makeButtonTypeTerm();
  }
  if (MB_isButtonTypeEquations(arg)) {
    return MB_makeButtonTypeEquations();
  }
  if (MB_isButtonTypeSyntax(arg)) {
    return MB_makeButtonTypeSyntax();
  }
  if (MB_isButtonTypeMessageList(arg)) {
    return MB_makeButtonTypeMessageList();
  }
  if (MB_isButtonTypeModulePopup(arg)) {
    return MB_makeButtonTypeModulePopup();
  }
  if (MB_isButtonTypeNewModulePopup(arg)) {
    return MB_makeButtonTypeNewModulePopup();
  }
  if (MB_isButtonTypeStudioMenubar(arg)) {
    return MB_makeButtonTypeStudioMenubar();
  }
  if (MB_isButtonTypeStudioToolbar(arg)) {
    return MB_makeButtonTypeStudioToolbar();
  }
  if (MB_isButtonTypeWildcard(arg)) {
    return MB_makeButtonTypeWildcard();
  }
  ATabort("not a ButtonType: %t\n", arg);
  return (MB_ButtonType)NULL;
}

/*}}}  */
/*{{{  MB_ButtonArgs MB_visitButtonArgs(MB_ButtonArgs arg, MB_MenuTitles (*acceptList)(MB_MenuTitles), char* (*acceptTitle)(char*), char* (*acceptPath)(char*)) */

MB_ButtonArgs MB_visitButtonArgs(MB_ButtonArgs arg, MB_MenuTitles (*acceptList)(MB_MenuTitles), char* (*acceptTitle)(char*), char* (*acceptPath)(char*))
{
  if (MB_isButtonArgsMenu(arg)) {
    return MB_makeButtonArgsMenu(
        acceptList ? acceptList(MB_getButtonArgsList(arg)) : MB_getButtonArgsList(arg));
  }
  if (MB_isButtonArgsIcon(arg)) {
    return MB_makeButtonArgsIcon(
        acceptTitle ? acceptTitle(MB_getButtonArgsTitle(arg)) : MB_getButtonArgsTitle(arg),
        acceptPath ? acceptPath(MB_getButtonArgsPath(arg)) : MB_getButtonArgsPath(arg));
  }
  ATabort("not a ButtonArgs: %t\n", arg);
  return (MB_ButtonArgs)NULL;
}

/*}}}  */
/*{{{  MB_MenuTitles MB_visitMenuTitles(MB_MenuTitles arg, char* (*acceptHead)(char*)) */

MB_MenuTitles MB_visitMenuTitles(MB_MenuTitles arg, char* (*acceptHead)(char*))
{
  if (MB_isMenuTitlesEmpty(arg)) {
    return MB_makeMenuTitlesEmpty();
  }
  if (MB_isMenuTitlesMany(arg)) {
    return MB_makeMenuTitlesMany(
        acceptHead ? acceptHead(MB_getMenuTitlesHead(arg)) : MB_getMenuTitlesHead(arg),
        MB_visitMenuTitles(MB_getMenuTitlesTail(arg), acceptHead));
  }
  ATabort("not a MenuTitles: %t\n", arg);
  return (MB_MenuTitles)NULL;
}

/*}}}  */
/*{{{  MB_ModuleName MB_visitModuleName(MB_ModuleName arg) */

MB_ModuleName MB_visitModuleName(MB_ModuleName arg)
{
  if (MB_isModuleNameWildcard(arg)) {
    return MB_makeModuleNameWildcard();
  }
  ATabort("not a ModuleName: %t\n", arg);
  return (MB_ModuleName)NULL;
}

/*}}}  */

/*}}}  */
