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
typedef struct _MB_ButtonDescriptionList *MB_ButtonDescriptionList;
typedef struct _MB_ButtonDescription *MB_ButtonDescription;
typedef struct _MB_ButtonType *MB_ButtonType;
typedef struct _MB_ButtonArgs *MB_ButtonArgs;
typedef struct _MB_MenuTitles *MB_MenuTitles;
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
MB_ButtonDescriptionList MB_ButtonDescriptionListFromTerm(ATerm t);
ATerm MB_ButtonDescriptionListToTerm(MB_ButtonDescriptionList arg);
MB_ButtonDescription MB_ButtonDescriptionFromTerm(ATerm t);
ATerm MB_ButtonDescriptionToTerm(MB_ButtonDescription arg);
MB_ButtonType MB_ButtonTypeFromTerm(ATerm t);
ATerm MB_ButtonTypeToTerm(MB_ButtonType arg);
MB_ButtonArgs MB_ButtonArgsFromTerm(ATerm t);
ATerm MB_ButtonArgsToTerm(MB_ButtonArgs arg);
MB_MenuTitles MB_MenuTitlesFromTerm(ATerm t);
ATerm MB_MenuTitlesToTerm(MB_MenuTitles arg);
MB_ModuleName MB_ModuleNameFromTerm(ATerm t);
ATerm MB_ModuleNameToTerm(MB_ModuleName arg);

/*}}}  */
/*{{{  constructors */

MB_Buttons MB_makeButtonsList(MB_ButtonList list);
MB_ButtonList MB_makeButtonListEmpty();
MB_ButtonList MB_makeButtonListMany(MB_Button head, MB_ButtonList tail);
MB_Button MB_makeButtonDefault(char* module, MB_ButtonDescriptionList descriptions, ATerm actions);
MB_ButtonDescriptionList MB_makeButtonDescriptionListEmpty();
MB_ButtonDescriptionList MB_makeButtonDescriptionListMany(MB_ButtonDescription head, MB_ButtonDescriptionList tail);
MB_ButtonDescription MB_makeButtonDescriptionDefault(MB_ButtonType type, MB_ButtonArgs args);
MB_ButtonType MB_makeButtonTypeTerm();
MB_ButtonType MB_makeButtonTypeEquations();
MB_ButtonType MB_makeButtonTypeSyntax();
MB_ButtonType MB_makeButtonTypeMessageList();
MB_ButtonType MB_makeButtonTypeModulePopup();
MB_ButtonType MB_makeButtonTypeNewModulePopup();
MB_ButtonType MB_makeButtonTypeStudioMenubar();
MB_ButtonType MB_makeButtonTypeStudioToolbar();
MB_ButtonType MB_makeButtonTypeWildcard();
MB_ButtonArgs MB_makeButtonArgsMenu(MB_MenuTitles list);
MB_ButtonArgs MB_makeButtonArgsIcon(char* title, char* path);
MB_MenuTitles MB_makeMenuTitlesEmpty();
MB_MenuTitles MB_makeMenuTitlesMany(char* head, MB_MenuTitles tail);
MB_ModuleName MB_makeModuleNameWildcard();

/*}}}  */
/*{{{  equality functions */

ATbool MB_isEqualButtons(MB_Buttons arg0, MB_Buttons arg1);
ATbool MB_isEqualButtonList(MB_ButtonList arg0, MB_ButtonList arg1);
ATbool MB_isEqualButton(MB_Button arg0, MB_Button arg1);
ATbool MB_isEqualButtonDescriptionList(MB_ButtonDescriptionList arg0, MB_ButtonDescriptionList arg1);
ATbool MB_isEqualButtonDescription(MB_ButtonDescription arg0, MB_ButtonDescription arg1);
ATbool MB_isEqualButtonType(MB_ButtonType arg0, MB_ButtonType arg1);
ATbool MB_isEqualButtonArgs(MB_ButtonArgs arg0, MB_ButtonArgs arg1);
ATbool MB_isEqualMenuTitles(MB_MenuTitles arg0, MB_MenuTitles arg1);
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
inline ATbool MB_isButtonDefault(MB_Button arg);
ATbool MB_hasButtonModule(MB_Button arg);
char* MB_getButtonModule(MB_Button arg);
MB_Button MB_setButtonModule(MB_Button arg, char* module);
ATbool MB_hasButtonDescriptions(MB_Button arg);
MB_ButtonDescriptionList MB_getButtonDescriptions(MB_Button arg);
MB_Button MB_setButtonDescriptions(MB_Button arg, MB_ButtonDescriptionList descriptions);
ATbool MB_hasButtonActions(MB_Button arg);
ATerm MB_getButtonActions(MB_Button arg);
MB_Button MB_setButtonActions(MB_Button arg, ATerm actions);

/*}}}  */
/*{{{  MB_ButtonDescriptionList accessors */

ATbool MB_isValidButtonDescriptionList(MB_ButtonDescriptionList arg);
inline ATbool MB_isButtonDescriptionListEmpty(MB_ButtonDescriptionList arg);
inline ATbool MB_isButtonDescriptionListMany(MB_ButtonDescriptionList arg);
ATbool MB_hasButtonDescriptionListHead(MB_ButtonDescriptionList arg);
MB_ButtonDescription MB_getButtonDescriptionListHead(MB_ButtonDescriptionList arg);
MB_ButtonDescriptionList MB_setButtonDescriptionListHead(MB_ButtonDescriptionList arg, MB_ButtonDescription head);
ATbool MB_hasButtonDescriptionListTail(MB_ButtonDescriptionList arg);
MB_ButtonDescriptionList MB_getButtonDescriptionListTail(MB_ButtonDescriptionList arg);
MB_ButtonDescriptionList MB_setButtonDescriptionListTail(MB_ButtonDescriptionList arg, MB_ButtonDescriptionList tail);

/*}}}  */
/*{{{  MB_ButtonDescription accessors */

ATbool MB_isValidButtonDescription(MB_ButtonDescription arg);
inline ATbool MB_isButtonDescriptionDefault(MB_ButtonDescription arg);
ATbool MB_hasButtonDescriptionType(MB_ButtonDescription arg);
MB_ButtonType MB_getButtonDescriptionType(MB_ButtonDescription arg);
MB_ButtonDescription MB_setButtonDescriptionType(MB_ButtonDescription arg, MB_ButtonType type);
ATbool MB_hasButtonDescriptionArgs(MB_ButtonDescription arg);
MB_ButtonArgs MB_getButtonDescriptionArgs(MB_ButtonDescription arg);
MB_ButtonDescription MB_setButtonDescriptionArgs(MB_ButtonDescription arg, MB_ButtonArgs args);

/*}}}  */
/*{{{  MB_ButtonType accessors */

ATbool MB_isValidButtonType(MB_ButtonType arg);
inline ATbool MB_isButtonTypeTerm(MB_ButtonType arg);
inline ATbool MB_isButtonTypeEquations(MB_ButtonType arg);
inline ATbool MB_isButtonTypeSyntax(MB_ButtonType arg);
inline ATbool MB_isButtonTypeMessageList(MB_ButtonType arg);
inline ATbool MB_isButtonTypeModulePopup(MB_ButtonType arg);
inline ATbool MB_isButtonTypeNewModulePopup(MB_ButtonType arg);
inline ATbool MB_isButtonTypeStudioMenubar(MB_ButtonType arg);
inline ATbool MB_isButtonTypeStudioToolbar(MB_ButtonType arg);
inline ATbool MB_isButtonTypeWildcard(MB_ButtonType arg);

/*}}}  */
/*{{{  MB_ButtonArgs accessors */

ATbool MB_isValidButtonArgs(MB_ButtonArgs arg);
inline ATbool MB_isButtonArgsMenu(MB_ButtonArgs arg);
inline ATbool MB_isButtonArgsIcon(MB_ButtonArgs arg);
ATbool MB_hasButtonArgsList(MB_ButtonArgs arg);
MB_MenuTitles MB_getButtonArgsList(MB_ButtonArgs arg);
MB_ButtonArgs MB_setButtonArgsList(MB_ButtonArgs arg, MB_MenuTitles list);
ATbool MB_hasButtonArgsTitle(MB_ButtonArgs arg);
char* MB_getButtonArgsTitle(MB_ButtonArgs arg);
MB_ButtonArgs MB_setButtonArgsTitle(MB_ButtonArgs arg, char* title);
ATbool MB_hasButtonArgsPath(MB_ButtonArgs arg);
char* MB_getButtonArgsPath(MB_ButtonArgs arg);
MB_ButtonArgs MB_setButtonArgsPath(MB_ButtonArgs arg, char* path);

/*}}}  */
/*{{{  MB_MenuTitles accessors */

ATbool MB_isValidMenuTitles(MB_MenuTitles arg);
inline ATbool MB_isMenuTitlesEmpty(MB_MenuTitles arg);
inline ATbool MB_isMenuTitlesMany(MB_MenuTitles arg);
ATbool MB_hasMenuTitlesHead(MB_MenuTitles arg);
char* MB_getMenuTitlesHead(MB_MenuTitles arg);
MB_MenuTitles MB_setMenuTitlesHead(MB_MenuTitles arg, char* head);
ATbool MB_hasMenuTitlesTail(MB_MenuTitles arg);
MB_MenuTitles MB_getMenuTitlesTail(MB_MenuTitles arg);
MB_MenuTitles MB_setMenuTitlesTail(MB_MenuTitles arg, MB_MenuTitles tail);

/*}}}  */
/*{{{  MB_ModuleName accessors */

ATbool MB_isValidModuleName(MB_ModuleName arg);
inline ATbool MB_isModuleNameWildcard(MB_ModuleName arg);

/*}}}  */
/*{{{  sort visitors */

MB_Buttons MB_visitButtons(MB_Buttons arg, MB_ButtonList (*acceptList)(MB_ButtonList));
MB_ButtonList MB_visitButtonList(MB_ButtonList arg, MB_Button (*acceptHead)(MB_Button));
MB_Button MB_visitButton(MB_Button arg, char* (*acceptModule)(char*), MB_ButtonDescriptionList (*acceptDescriptions)(MB_ButtonDescriptionList), ATerm (*acceptActions)(ATerm));
MB_ButtonDescriptionList MB_visitButtonDescriptionList(MB_ButtonDescriptionList arg, MB_ButtonDescription (*acceptHead)(MB_ButtonDescription));
MB_ButtonDescription MB_visitButtonDescription(MB_ButtonDescription arg, MB_ButtonType (*acceptType)(MB_ButtonType), MB_ButtonArgs (*acceptArgs)(MB_ButtonArgs));
MB_ButtonType MB_visitButtonType(MB_ButtonType arg);
MB_ButtonArgs MB_visitButtonArgs(MB_ButtonArgs arg, MB_MenuTitles (*acceptList)(MB_MenuTitles), char* (*acceptTitle)(char*), char* (*acceptPath)(char*));
MB_MenuTitles MB_visitMenuTitles(MB_MenuTitles arg, char* (*acceptHead)(char*));
MB_ModuleName MB_visitModuleName(MB_ModuleName arg);

/*}}}  */

#endif /* _METABUTTONS_H */
