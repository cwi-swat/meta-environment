#ifndef _METACONFIG_H
#define _METACONFIG_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "MetaConfig_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _MC_Configuration *MC_Configuration;
typedef struct _MC_Properties *MC_Properties;
typedef struct _MC_Property *MC_Property;
typedef struct _MC_ButtonDescriptionList *MC_ButtonDescriptionList;
typedef struct _MC_ButtonDescription *MC_ButtonDescription;
typedef struct _MC_ButtonType *MC_ButtonType;
typedef struct _MC_ButtonArgs *MC_ButtonArgs;
typedef struct _MC_MenuTitles *MC_MenuTitles;
typedef struct _MC_ModuleName *MC_ModuleName;

/*}}}  */

/*{{{  definition of bottom types */


/*}}}  */

/*{{{  protect macros */

#define MC_protectConfiguration(arg) (ATprotect((ATerm*)((void*) arg)))
#define MC_protectProperties(arg) (ATprotect((ATerm*)((void*) arg)))
#define MC_protectProperty(arg) (ATprotect((ATerm*)((void*) arg)))
#define MC_protectButtonDescriptionList(arg) (ATprotect((ATerm*)((void*) arg)))
#define MC_protectButtonDescription(arg) (ATprotect((ATerm*)((void*) arg)))
#define MC_protectButtonType(arg) (ATprotect((ATerm*)((void*) arg)))
#define MC_protectButtonArgs(arg) (ATprotect((ATerm*)((void*) arg)))
#define MC_protectMenuTitles(arg) (ATprotect((ATerm*)((void*) arg)))
#define MC_protectModuleName(arg) (ATprotect((ATerm*)((void*) arg)))

/*}}}  */
void MC_initMetaConfigApi(void);

/*{{{  term conversion functions */

MC_Configuration MC_ConfigurationFromTerm(ATerm t);
ATerm MC_ConfigurationToTerm(MC_Configuration arg);
MC_Properties MC_PropertiesFromTerm(ATerm t);
ATerm MC_PropertiesToTerm(MC_Properties arg);
MC_Property MC_PropertyFromTerm(ATerm t);
ATerm MC_PropertyToTerm(MC_Property arg);
MC_ButtonDescriptionList MC_ButtonDescriptionListFromTerm(ATerm t);
ATerm MC_ButtonDescriptionListToTerm(MC_ButtonDescriptionList arg);
MC_ButtonDescription MC_ButtonDescriptionFromTerm(ATerm t);
ATerm MC_ButtonDescriptionToTerm(MC_ButtonDescription arg);
MC_ButtonType MC_ButtonTypeFromTerm(ATerm t);
ATerm MC_ButtonTypeToTerm(MC_ButtonType arg);
MC_ButtonArgs MC_ButtonArgsFromTerm(ATerm t);
ATerm MC_ButtonArgsToTerm(MC_ButtonArgs arg);
MC_MenuTitles MC_MenuTitlesFromTerm(ATerm t);
ATerm MC_MenuTitlesToTerm(MC_MenuTitles arg);
MC_ModuleName MC_ModuleNameFromTerm(ATerm t);
ATerm MC_ModuleNameToTerm(MC_ModuleName arg);

/*}}}  */
/*{{{  list functions */

int MC_getPropertiesLength (MC_Properties arg);
MC_Properties MC_reverseProperties(MC_Properties arg);
MC_Properties MC_appendProperties(MC_Properties arg, MC_Property elem);
MC_Properties MC_concatProperties(MC_Properties arg0, MC_Properties arg1);
MC_Properties MC_sliceProperties(MC_Properties arg, int start, int end);
MC_Property MC_getPropertiesPropertyAt(MC_Properties arg, int index);
MC_Properties MC_replacePropertiesPropertyAt(MC_Properties arg, MC_Property elem, int index);
MC_Properties MC_makeProperties2(MC_Property elem1, MC_Property elem2);
MC_Properties MC_makeProperties3(MC_Property elem1, MC_Property elem2, MC_Property elem3);
MC_Properties MC_makeProperties4(MC_Property elem1, MC_Property elem2, MC_Property elem3, MC_Property elem4);
MC_Properties MC_makeProperties5(MC_Property elem1, MC_Property elem2, MC_Property elem3, MC_Property elem4, MC_Property elem5);
MC_Properties MC_makeProperties6(MC_Property elem1, MC_Property elem2, MC_Property elem3, MC_Property elem4, MC_Property elem5, MC_Property elem6);
int MC_getButtonDescriptionListLength (MC_ButtonDescriptionList arg);
MC_ButtonDescriptionList MC_reverseButtonDescriptionList(MC_ButtonDescriptionList arg);
MC_ButtonDescriptionList MC_appendButtonDescriptionList(MC_ButtonDescriptionList arg, MC_ButtonDescription elem);
MC_ButtonDescriptionList MC_concatButtonDescriptionList(MC_ButtonDescriptionList arg0, MC_ButtonDescriptionList arg1);
MC_ButtonDescriptionList MC_sliceButtonDescriptionList(MC_ButtonDescriptionList arg, int start, int end);
MC_ButtonDescription MC_getButtonDescriptionListButtonDescriptionAt(MC_ButtonDescriptionList arg, int index);
MC_ButtonDescriptionList MC_replaceButtonDescriptionListButtonDescriptionAt(MC_ButtonDescriptionList arg, MC_ButtonDescription elem, int index);
MC_ButtonDescriptionList MC_makeButtonDescriptionList2(MC_ButtonDescription elem1, MC_ButtonDescription elem2);
MC_ButtonDescriptionList MC_makeButtonDescriptionList3(MC_ButtonDescription elem1, MC_ButtonDescription elem2, MC_ButtonDescription elem3);
MC_ButtonDescriptionList MC_makeButtonDescriptionList4(MC_ButtonDescription elem1, MC_ButtonDescription elem2, MC_ButtonDescription elem3, MC_ButtonDescription elem4);
MC_ButtonDescriptionList MC_makeButtonDescriptionList5(MC_ButtonDescription elem1, MC_ButtonDescription elem2, MC_ButtonDescription elem3, MC_ButtonDescription elem4, MC_ButtonDescription elem5);
MC_ButtonDescriptionList MC_makeButtonDescriptionList6(MC_ButtonDescription elem1, MC_ButtonDescription elem2, MC_ButtonDescription elem3, MC_ButtonDescription elem4, MC_ButtonDescription elem5, MC_ButtonDescription elem6);
int MC_getMenuTitlesLength (MC_MenuTitles arg);
MC_MenuTitles MC_reverseMenuTitles(MC_MenuTitles arg);
MC_MenuTitles MC_appendMenuTitles(MC_MenuTitles arg, char* elem);
MC_MenuTitles MC_concatMenuTitles(MC_MenuTitles arg0, MC_MenuTitles arg1);
MC_MenuTitles MC_sliceMenuTitles(MC_MenuTitles arg, int start, int end);
char* MC_getMenuTitlesstrAt(MC_MenuTitles arg, int index);
MC_MenuTitles MC_replaceMenuTitlesstrAt(MC_MenuTitles arg, char* elem, int index);
MC_MenuTitles MC_makeMenuTitles2(char* elem1, char* elem2);
MC_MenuTitles MC_makeMenuTitles3(char* elem1, char* elem2, char* elem3);
MC_MenuTitles MC_makeMenuTitles4(char* elem1, char* elem2, char* elem3, char* elem4);
MC_MenuTitles MC_makeMenuTitles5(char* elem1, char* elem2, char* elem3, char* elem4, char* elem5);
MC_MenuTitles MC_makeMenuTitles6(char* elem1, char* elem2, char* elem3, char* elem4, char* elem5, char* elem6);

/*}}}  */
/*{{{  constructors */

MC_Configuration MC_makeConfigurationList(MC_Properties list);
MC_Properties MC_makePropertiesEmpty();
MC_Properties MC_makePropertiesSingle(MC_Property head);
MC_Properties MC_makePropertiesMany(MC_Property head, MC_Properties tail);
MC_Property MC_makePropertyButton(char* module, MC_ButtonDescriptionList descriptions, ATerm actions);
MC_Property MC_makePropertyExtension(char* language, char* extension);
MC_ButtonDescriptionList MC_makeButtonDescriptionListEmpty();
MC_ButtonDescriptionList MC_makeButtonDescriptionListSingle(MC_ButtonDescription head);
MC_ButtonDescriptionList MC_makeButtonDescriptionListMany(MC_ButtonDescription head, MC_ButtonDescriptionList tail);
MC_ButtonDescription MC_makeButtonDescriptionDefault(MC_ButtonType type, MC_ButtonArgs args);
MC_ButtonType MC_makeButtonTypeTermEditor();
MC_ButtonType MC_makeButtonTypeEquationsEditor();
MC_ButtonType MC_makeButtonTypeSyntaxEditor();
MC_ButtonType MC_makeButtonTypeMessageList();
MC_ButtonType MC_makeButtonTypeFeedbackList();
MC_ButtonType MC_makeButtonTypeTreePanel();
MC_ButtonType MC_makeButtonTypeModulePopup();
MC_ButtonType MC_makeButtonTypeNewModulePopup();
MC_ButtonType MC_makeButtonTypeStudioMenubar();
MC_ButtonType MC_makeButtonTypeStudioToolbar();
MC_ButtonType MC_makeButtonTypeWildcard();
MC_ButtonArgs MC_makeButtonArgsClick();
MC_ButtonArgs MC_makeButtonArgsMenu(MC_MenuTitles list);
MC_ButtonArgs MC_makeButtonArgsMenuwithshortcut(MC_MenuTitles list, char* shortcut);
MC_ButtonArgs MC_makeButtonArgsIcon(char* title, char* path);
MC_MenuTitles MC_makeMenuTitlesEmpty();
MC_MenuTitles MC_makeMenuTitlesSingle(char* head);
MC_MenuTitles MC_makeMenuTitlesMany(char* head, MC_MenuTitles tail);
MC_ModuleName MC_makeModuleNameWildcard();

/*}}}  */
/*{{{  equality functions */

ATbool MC_isEqualConfiguration(MC_Configuration arg0, MC_Configuration arg1);
ATbool MC_isEqualProperties(MC_Properties arg0, MC_Properties arg1);
ATbool MC_isEqualProperty(MC_Property arg0, MC_Property arg1);
ATbool MC_isEqualButtonDescriptionList(MC_ButtonDescriptionList arg0, MC_ButtonDescriptionList arg1);
ATbool MC_isEqualButtonDescription(MC_ButtonDescription arg0, MC_ButtonDescription arg1);
ATbool MC_isEqualButtonType(MC_ButtonType arg0, MC_ButtonType arg1);
ATbool MC_isEqualButtonArgs(MC_ButtonArgs arg0, MC_ButtonArgs arg1);
ATbool MC_isEqualMenuTitles(MC_MenuTitles arg0, MC_MenuTitles arg1);
ATbool MC_isEqualModuleName(MC_ModuleName arg0, MC_ModuleName arg1);

/*}}}  */
/*{{{  MC_Configuration accessors */

ATbool MC_isValidConfiguration(MC_Configuration arg);
inline ATbool MC_isConfigurationList(MC_Configuration arg);
ATbool MC_hasConfigurationList(MC_Configuration arg);
MC_Properties MC_getConfigurationList(MC_Configuration arg);
MC_Configuration MC_setConfigurationList(MC_Configuration arg, MC_Properties list);

/*}}}  */
/*{{{  MC_Properties accessors */

ATbool MC_isValidProperties(MC_Properties arg);
inline ATbool MC_isPropertiesEmpty(MC_Properties arg);
inline ATbool MC_isPropertiesSingle(MC_Properties arg);
inline ATbool MC_isPropertiesMany(MC_Properties arg);
ATbool MC_hasPropertiesHead(MC_Properties arg);
MC_Property MC_getPropertiesHead(MC_Properties arg);
MC_Properties MC_setPropertiesHead(MC_Properties arg, MC_Property head);
ATbool MC_hasPropertiesTail(MC_Properties arg);
MC_Properties MC_getPropertiesTail(MC_Properties arg);
MC_Properties MC_setPropertiesTail(MC_Properties arg, MC_Properties tail);

/*}}}  */
/*{{{  MC_Property accessors */

ATbool MC_isValidProperty(MC_Property arg);
inline ATbool MC_isPropertyButton(MC_Property arg);
inline ATbool MC_isPropertyExtension(MC_Property arg);
ATbool MC_hasPropertyModule(MC_Property arg);
char* MC_getPropertyModule(MC_Property arg);
MC_Property MC_setPropertyModule(MC_Property arg, char* module);
ATbool MC_hasPropertyDescriptions(MC_Property arg);
MC_ButtonDescriptionList MC_getPropertyDescriptions(MC_Property arg);
MC_Property MC_setPropertyDescriptions(MC_Property arg, MC_ButtonDescriptionList descriptions);
ATbool MC_hasPropertyActions(MC_Property arg);
ATerm MC_getPropertyActions(MC_Property arg);
MC_Property MC_setPropertyActions(MC_Property arg, ATerm actions);
ATbool MC_hasPropertyLanguage(MC_Property arg);
char* MC_getPropertyLanguage(MC_Property arg);
MC_Property MC_setPropertyLanguage(MC_Property arg, char* language);
ATbool MC_hasPropertyExtension(MC_Property arg);
char* MC_getPropertyExtension(MC_Property arg);
MC_Property MC_setPropertyExtension(MC_Property arg, char* extension);

/*}}}  */
/*{{{  MC_ButtonDescriptionList accessors */

ATbool MC_isValidButtonDescriptionList(MC_ButtonDescriptionList arg);
inline ATbool MC_isButtonDescriptionListEmpty(MC_ButtonDescriptionList arg);
inline ATbool MC_isButtonDescriptionListSingle(MC_ButtonDescriptionList arg);
inline ATbool MC_isButtonDescriptionListMany(MC_ButtonDescriptionList arg);
ATbool MC_hasButtonDescriptionListHead(MC_ButtonDescriptionList arg);
MC_ButtonDescription MC_getButtonDescriptionListHead(MC_ButtonDescriptionList arg);
MC_ButtonDescriptionList MC_setButtonDescriptionListHead(MC_ButtonDescriptionList arg, MC_ButtonDescription head);
ATbool MC_hasButtonDescriptionListTail(MC_ButtonDescriptionList arg);
MC_ButtonDescriptionList MC_getButtonDescriptionListTail(MC_ButtonDescriptionList arg);
MC_ButtonDescriptionList MC_setButtonDescriptionListTail(MC_ButtonDescriptionList arg, MC_ButtonDescriptionList tail);

/*}}}  */
/*{{{  MC_ButtonDescription accessors */

ATbool MC_isValidButtonDescription(MC_ButtonDescription arg);
inline ATbool MC_isButtonDescriptionDefault(MC_ButtonDescription arg);
ATbool MC_hasButtonDescriptionType(MC_ButtonDescription arg);
MC_ButtonType MC_getButtonDescriptionType(MC_ButtonDescription arg);
MC_ButtonDescription MC_setButtonDescriptionType(MC_ButtonDescription arg, MC_ButtonType type);
ATbool MC_hasButtonDescriptionArgs(MC_ButtonDescription arg);
MC_ButtonArgs MC_getButtonDescriptionArgs(MC_ButtonDescription arg);
MC_ButtonDescription MC_setButtonDescriptionArgs(MC_ButtonDescription arg, MC_ButtonArgs args);

/*}}}  */
/*{{{  MC_ButtonType accessors */

ATbool MC_isValidButtonType(MC_ButtonType arg);
inline ATbool MC_isButtonTypeTermEditor(MC_ButtonType arg);
inline ATbool MC_isButtonTypeEquationsEditor(MC_ButtonType arg);
inline ATbool MC_isButtonTypeSyntaxEditor(MC_ButtonType arg);
inline ATbool MC_isButtonTypeMessageList(MC_ButtonType arg);
inline ATbool MC_isButtonTypeFeedbackList(MC_ButtonType arg);
inline ATbool MC_isButtonTypeTreePanel(MC_ButtonType arg);
inline ATbool MC_isButtonTypeModulePopup(MC_ButtonType arg);
inline ATbool MC_isButtonTypeNewModulePopup(MC_ButtonType arg);
inline ATbool MC_isButtonTypeStudioMenubar(MC_ButtonType arg);
inline ATbool MC_isButtonTypeStudioToolbar(MC_ButtonType arg);
inline ATbool MC_isButtonTypeWildcard(MC_ButtonType arg);

/*}}}  */
/*{{{  MC_ButtonArgs accessors */

ATbool MC_isValidButtonArgs(MC_ButtonArgs arg);
inline ATbool MC_isButtonArgsClick(MC_ButtonArgs arg);
inline ATbool MC_isButtonArgsMenu(MC_ButtonArgs arg);
inline ATbool MC_isButtonArgsMenuwithshortcut(MC_ButtonArgs arg);
inline ATbool MC_isButtonArgsIcon(MC_ButtonArgs arg);
ATbool MC_hasButtonArgsList(MC_ButtonArgs arg);
MC_MenuTitles MC_getButtonArgsList(MC_ButtonArgs arg);
MC_ButtonArgs MC_setButtonArgsList(MC_ButtonArgs arg, MC_MenuTitles list);
ATbool MC_hasButtonArgsShortcut(MC_ButtonArgs arg);
char* MC_getButtonArgsShortcut(MC_ButtonArgs arg);
MC_ButtonArgs MC_setButtonArgsShortcut(MC_ButtonArgs arg, char* shortcut);
ATbool MC_hasButtonArgsTitle(MC_ButtonArgs arg);
char* MC_getButtonArgsTitle(MC_ButtonArgs arg);
MC_ButtonArgs MC_setButtonArgsTitle(MC_ButtonArgs arg, char* title);
ATbool MC_hasButtonArgsPath(MC_ButtonArgs arg);
char* MC_getButtonArgsPath(MC_ButtonArgs arg);
MC_ButtonArgs MC_setButtonArgsPath(MC_ButtonArgs arg, char* path);

/*}}}  */
/*{{{  MC_MenuTitles accessors */

ATbool MC_isValidMenuTitles(MC_MenuTitles arg);
inline ATbool MC_isMenuTitlesEmpty(MC_MenuTitles arg);
inline ATbool MC_isMenuTitlesSingle(MC_MenuTitles arg);
inline ATbool MC_isMenuTitlesMany(MC_MenuTitles arg);
ATbool MC_hasMenuTitlesHead(MC_MenuTitles arg);
char* MC_getMenuTitlesHead(MC_MenuTitles arg);
MC_MenuTitles MC_setMenuTitlesHead(MC_MenuTitles arg, char* head);
ATbool MC_hasMenuTitlesTail(MC_MenuTitles arg);
MC_MenuTitles MC_getMenuTitlesTail(MC_MenuTitles arg);
MC_MenuTitles MC_setMenuTitlesTail(MC_MenuTitles arg, MC_MenuTitles tail);

/*}}}  */
/*{{{  MC_ModuleName accessors */

ATbool MC_isValidModuleName(MC_ModuleName arg);
inline ATbool MC_isModuleNameWildcard(MC_ModuleName arg);

/*}}}  */
/*{{{  sort visitors */

MC_Configuration MC_visitConfiguration(MC_Configuration arg, MC_Properties (*acceptList)(MC_Properties));
MC_Properties MC_visitProperties(MC_Properties arg, MC_Property (*acceptHead)(MC_Property));
MC_Property MC_visitProperty(MC_Property arg, char* (*acceptModule)(char*), MC_ButtonDescriptionList (*acceptDescriptions)(MC_ButtonDescriptionList), ATerm (*acceptActions)(ATerm), char* (*acceptLanguage)(char*), char* (*acceptExtension)(char*));
MC_ButtonDescriptionList MC_visitButtonDescriptionList(MC_ButtonDescriptionList arg, MC_ButtonDescription (*acceptHead)(MC_ButtonDescription));
MC_ButtonDescription MC_visitButtonDescription(MC_ButtonDescription arg, MC_ButtonType (*acceptType)(MC_ButtonType), MC_ButtonArgs (*acceptArgs)(MC_ButtonArgs));
MC_ButtonType MC_visitButtonType(MC_ButtonType arg);
MC_ButtonArgs MC_visitButtonArgs(MC_ButtonArgs arg, MC_MenuTitles (*acceptList)(MC_MenuTitles), char* (*acceptShortcut)(char*), char* (*acceptTitle)(char*), char* (*acceptPath)(char*));
MC_MenuTitles MC_visitMenuTitles(MC_MenuTitles arg, char* (*acceptHead)(char*));
MC_ModuleName MC_visitModuleName(MC_ModuleName arg);

/*}}}  */

#endif /* _METACONFIG_H */
