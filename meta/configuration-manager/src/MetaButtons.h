#ifndef _METABUTTONS_H
#define _METABUTTONS_H

/*{{{  includes */

#include <aterm1.h>
#include "MetaButtons_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _MB_Buttons *MB_Buttons;
typedef struct _MB_ButtonList *MB_ButtonList;
typedef struct _MB_Button *MB_Button;
typedef struct _MB_EditorType *MB_EditorType;
typedef struct _MB_ModuleName *MB_ModuleName;

/*}}}  */

void MB_initMetaButtonsApi(void);

/*{{{  term conversion functions */

MB_Buttons MB_ButtonsFromTerm(ATerm t);
ATerm MB_ButtonsToTerm(MB_Buttons arg);
MB_ButtonList MB_ButtonListFromTerm(ATerm t);
ATerm MB_ButtonListToTerm(MB_ButtonList arg);
MB_Button MB_ButtonFromTerm(ATerm t);
ATerm MB_ButtonToTerm(MB_Button arg);
MB_EditorType MB_EditorTypeFromTerm(ATerm t);
ATerm MB_EditorTypeToTerm(MB_EditorType arg);
MB_ModuleName MB_ModuleNameFromTerm(ATerm t);
ATerm MB_ModuleNameToTerm(MB_ModuleName arg);

/*}}}  */
/*{{{  constructors */

MB_Buttons MB_makeButtonsList(MB_ButtonList list);
MB_ButtonList MB_makeButtonListEmpty();
MB_ButtonList MB_makeButtonListMany(MB_Button head, MB_ButtonList tail);
MB_Button MB_makeButtonEditor(char * module, MB_EditorType type, ATerm name, ATerm actions);
MB_EditorType MB_makeEditorTypeTerm();
MB_EditorType MB_makeEditorTypeEquations();
MB_EditorType MB_makeEditorTypeSyntax();
MB_EditorType MB_makeEditorTypeMessageList();
MB_EditorType MB_makeEditorTypeAll();
MB_ModuleName MB_makeModuleNameAll();

/*}}}  */
/*{{{  equality functions */

ATbool MB_isEqualButtons(MB_Buttons arg0, MB_Buttons arg1);
ATbool MB_isEqualButtonList(MB_ButtonList arg0, MB_ButtonList arg1);
ATbool MB_isEqualButton(MB_Button arg0, MB_Button arg1);
ATbool MB_isEqualEditorType(MB_EditorType arg0, MB_EditorType arg1);
ATbool MB_isEqualModuleName(MB_ModuleName arg0, MB_ModuleName arg1);

/*}}}  */
/*{{{  MB_Buttons accessors */

ATbool MB_isValidButtons(MB_Buttons arg);
inline ATbool MB_isButtonsList(MB_Buttons arg);
ATbool MB_hasButtonsList(MB_Buttons arg);
MB_ButtonList MB_getButtonsList(MB_Buttons arg);
MB_Buttons MB_setButtonsList(MB_Buttons arg, MB_ButtonList list);

/*}}}  */
/*{{{  MB_ButtonList accessors */

ATbool MB_isValidButtonList(MB_ButtonList arg);
inline ATbool MB_isButtonListEmpty(MB_ButtonList arg);
inline ATbool MB_isButtonListMany(MB_ButtonList arg);
ATbool MB_hasButtonListHead(MB_ButtonList arg);
MB_Button MB_getButtonListHead(MB_ButtonList arg);
MB_ButtonList MB_setButtonListHead(MB_ButtonList arg, MB_Button head);
ATbool MB_hasButtonListTail(MB_ButtonList arg);
MB_ButtonList MB_getButtonListTail(MB_ButtonList arg);
MB_ButtonList MB_setButtonListTail(MB_ButtonList arg, MB_ButtonList tail);

/*}}}  */
/*{{{  MB_Button accessors */

ATbool MB_isValidButton(MB_Button arg);
inline ATbool MB_isButtonEditor(MB_Button arg);
ATbool MB_hasButtonModule(MB_Button arg);
char * MB_getButtonModule(MB_Button arg);
MB_Button MB_setButtonModule(MB_Button arg, char * module);
ATbool MB_hasButtonType(MB_Button arg);
MB_EditorType MB_getButtonType(MB_Button arg);
MB_Button MB_setButtonType(MB_Button arg, MB_EditorType type);
ATbool MB_hasButtonName(MB_Button arg);
ATerm MB_getButtonName(MB_Button arg);
MB_Button MB_setButtonName(MB_Button arg, ATerm name);
ATbool MB_hasButtonActions(MB_Button arg);
ATerm MB_getButtonActions(MB_Button arg);
MB_Button MB_setButtonActions(MB_Button arg, ATerm actions);

/*}}}  */
/*{{{  MB_EditorType accessors */

ATbool MB_isValidEditorType(MB_EditorType arg);
inline ATbool MB_isEditorTypeTerm(MB_EditorType arg);
inline ATbool MB_isEditorTypeEquations(MB_EditorType arg);
inline ATbool MB_isEditorTypeSyntax(MB_EditorType arg);
inline ATbool MB_isEditorTypeMessageList(MB_EditorType arg);
inline ATbool MB_isEditorTypeAll(MB_EditorType arg);

/*}}}  */
/*{{{  MB_ModuleName accessors */

ATbool MB_isValidModuleName(MB_ModuleName arg);
inline ATbool MB_isModuleNameAll(MB_ModuleName arg);

/*}}}  */
/*{{{  sort visitors */

MB_Buttons MB_visitButtons(MB_Buttons arg, MB_ButtonList (*acceptList)(MB_ButtonList));
MB_ButtonList MB_visitButtonList(MB_ButtonList arg, MB_Button (*acceptHead)(MB_Button));
MB_Button MB_visitButton(MB_Button arg, char * (*acceptModule)(char *), MB_EditorType (*acceptType)(MB_EditorType), ATerm (*acceptName)(ATerm), ATerm (*acceptActions)(ATerm));
MB_EditorType MB_visitEditorType(MB_EditorType arg);
MB_ModuleName MB_visitModuleName(MB_ModuleName arg);

/*}}}  */

#endif /* _METABUTTONS_H */
