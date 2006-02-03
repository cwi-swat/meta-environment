#ifndef _CONFIG_H
#define _CONFIG_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Config_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _CFG_Configuration *CFG_Configuration;
typedef struct _CFG_Properties *CFG_Properties;
typedef struct _CFG_Property *CFG_Property;
typedef struct _CFG_ActionDescription *CFG_ActionDescription;
typedef struct _CFG_ActionDescriptionList *CFG_ActionDescriptionList;
typedef struct _CFG_ActionType *CFG_ActionType;
typedef struct _CFG_Event *CFG_Event;
typedef struct _CFG_Items *CFG_Items;
typedef struct _CFG_ModuleName *CFG_ModuleName;
typedef struct _CFG_TextCategoryName *CFG_TextCategoryName;
typedef struct _CFG_TextAttributes *CFG_TextAttributes;
typedef struct _CFG_TextAttribute *CFG_TextAttribute;
typedef struct _CFG_TextStyle *CFG_TextStyle;
typedef struct _CFG_Color *CFG_Color;

/*}}}  */

void CFG_initConfigApi(void);

/*{{{  protect functions */

void CFG_protectConfiguration(CFG_Configuration *arg);
void CFG_protectProperties(CFG_Properties *arg);
void CFG_protectProperty(CFG_Property *arg);
void CFG_protectActionDescription(CFG_ActionDescription *arg);
void CFG_protectActionDescriptionList(CFG_ActionDescriptionList *arg);
void CFG_protectActionType(CFG_ActionType *arg);
void CFG_protectEvent(CFG_Event *arg);
void CFG_protectItems(CFG_Items *arg);
void CFG_protectModuleName(CFG_ModuleName *arg);
void CFG_protectTextCategoryName(CFG_TextCategoryName *arg);
void CFG_protectTextAttributes(CFG_TextAttributes *arg);
void CFG_protectTextAttribute(CFG_TextAttribute *arg);
void CFG_protectTextStyle(CFG_TextStyle *arg);
void CFG_protectColor(CFG_Color *arg);

/*}}}  */
/*{{{  term conversion functions */

CFG_Configuration CFG_ConfigurationFromTerm(ATerm t);
ATerm CFG_ConfigurationToTerm(CFG_Configuration arg);
CFG_Properties CFG_PropertiesFromTerm(ATerm t);
ATerm CFG_PropertiesToTerm(CFG_Properties arg);
CFG_Property CFG_PropertyFromTerm(ATerm t);
ATerm CFG_PropertyToTerm(CFG_Property arg);
CFG_ActionDescription CFG_ActionDescriptionFromTerm(ATerm t);
ATerm CFG_ActionDescriptionToTerm(CFG_ActionDescription arg);
CFG_ActionDescriptionList CFG_ActionDescriptionListFromTerm(ATerm t);
ATerm CFG_ActionDescriptionListToTerm(CFG_ActionDescriptionList arg);
CFG_ActionType CFG_ActionTypeFromTerm(ATerm t);
ATerm CFG_ActionTypeToTerm(CFG_ActionType arg);
CFG_Event CFG_EventFromTerm(ATerm t);
ATerm CFG_EventToTerm(CFG_Event arg);
CFG_Items CFG_ItemsFromTerm(ATerm t);
ATerm CFG_ItemsToTerm(CFG_Items arg);
CFG_ModuleName CFG_ModuleNameFromTerm(ATerm t);
ATerm CFG_ModuleNameToTerm(CFG_ModuleName arg);
CFG_TextCategoryName CFG_TextCategoryNameFromTerm(ATerm t);
ATerm CFG_TextCategoryNameToTerm(CFG_TextCategoryName arg);
CFG_TextAttributes CFG_TextAttributesFromTerm(ATerm t);
ATerm CFG_TextAttributesToTerm(CFG_TextAttributes arg);
CFG_TextAttribute CFG_TextAttributeFromTerm(ATerm t);
ATerm CFG_TextAttributeToTerm(CFG_TextAttribute arg);
CFG_TextStyle CFG_TextStyleFromTerm(ATerm t);
ATerm CFG_TextStyleToTerm(CFG_TextStyle arg);
CFG_Color CFG_ColorFromTerm(ATerm t);
ATerm CFG_ColorToTerm(CFG_Color arg);

/*}}}  */
/*{{{  list functions */

int CFG_getPropertiesLength (CFG_Properties arg);
CFG_Properties CFG_reverseProperties(CFG_Properties arg);
CFG_Properties CFG_appendProperties(CFG_Properties arg, CFG_Property elem);
CFG_Properties CFG_concatProperties(CFG_Properties arg0, CFG_Properties arg1);
CFG_Properties CFG_sliceProperties(CFG_Properties arg, int start, int end);
CFG_Property CFG_getPropertiesPropertyAt(CFG_Properties arg, int index);
CFG_Properties CFG_replacePropertiesPropertyAt(CFG_Properties arg, CFG_Property elem, int index);
CFG_Properties CFG_makeProperties2(CFG_Property elem1, CFG_Property elem2);
CFG_Properties CFG_makeProperties3(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3);
CFG_Properties CFG_makeProperties4(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3, CFG_Property elem4);
CFG_Properties CFG_makeProperties5(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3, CFG_Property elem4, CFG_Property elem5);
CFG_Properties CFG_makeProperties6(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3, CFG_Property elem4, CFG_Property elem5, CFG_Property elem6);
int CFG_getActionDescriptionListLength (CFG_ActionDescriptionList arg);
CFG_ActionDescriptionList CFG_reverseActionDescriptionList(CFG_ActionDescriptionList arg);
CFG_ActionDescriptionList CFG_appendActionDescriptionList(CFG_ActionDescriptionList arg, CFG_ActionDescription elem);
CFG_ActionDescriptionList CFG_concatActionDescriptionList(CFG_ActionDescriptionList arg0, CFG_ActionDescriptionList arg1);
CFG_ActionDescriptionList CFG_sliceActionDescriptionList(CFG_ActionDescriptionList arg, int start, int end);
CFG_ActionDescription CFG_getActionDescriptionListActionDescriptionAt(CFG_ActionDescriptionList arg, int index);
CFG_ActionDescriptionList CFG_replaceActionDescriptionListActionDescriptionAt(CFG_ActionDescriptionList arg, CFG_ActionDescription elem, int index);
CFG_ActionDescriptionList CFG_makeActionDescriptionList2(CFG_ActionDescription elem1, CFG_ActionDescription elem2);
CFG_ActionDescriptionList CFG_makeActionDescriptionList3(CFG_ActionDescription elem1, CFG_ActionDescription elem2, CFG_ActionDescription elem3);
CFG_ActionDescriptionList CFG_makeActionDescriptionList4(CFG_ActionDescription elem1, CFG_ActionDescription elem2, CFG_ActionDescription elem3, CFG_ActionDescription elem4);
CFG_ActionDescriptionList CFG_makeActionDescriptionList5(CFG_ActionDescription elem1, CFG_ActionDescription elem2, CFG_ActionDescription elem3, CFG_ActionDescription elem4, CFG_ActionDescription elem5);
CFG_ActionDescriptionList CFG_makeActionDescriptionList6(CFG_ActionDescription elem1, CFG_ActionDescription elem2, CFG_ActionDescription elem3, CFG_ActionDescription elem4, CFG_ActionDescription elem5, CFG_ActionDescription elem6);
int CFG_getItemsLength (CFG_Items arg);
CFG_Items CFG_reverseItems(CFG_Items arg);
CFG_Items CFG_appendItems(CFG_Items arg, char* elem);
CFG_Items CFG_concatItems(CFG_Items arg0, CFG_Items arg1);
CFG_Items CFG_sliceItems(CFG_Items arg, int start, int end);
char* CFG_getItemsstrAt(CFG_Items arg, int index);
CFG_Items CFG_replaceItemsstrAt(CFG_Items arg, char* elem, int index);
CFG_Items CFG_makeItems2(char* elem1, char* elem2);
CFG_Items CFG_makeItems3(char* elem1, char* elem2, char* elem3);
CFG_Items CFG_makeItems4(char* elem1, char* elem2, char* elem3, char* elem4);
CFG_Items CFG_makeItems5(char* elem1, char* elem2, char* elem3, char* elem4, char* elem5);
CFG_Items CFG_makeItems6(char* elem1, char* elem2, char* elem3, char* elem4, char* elem5, char* elem6);
int CFG_getTextAttributesLength (CFG_TextAttributes arg);
CFG_TextAttributes CFG_reverseTextAttributes(CFG_TextAttributes arg);
CFG_TextAttributes CFG_appendTextAttributes(CFG_TextAttributes arg, CFG_TextAttribute elem);
CFG_TextAttributes CFG_concatTextAttributes(CFG_TextAttributes arg0, CFG_TextAttributes arg1);
CFG_TextAttributes CFG_sliceTextAttributes(CFG_TextAttributes arg, int start, int end);
CFG_TextAttribute CFG_getTextAttributesTextAttributeAt(CFG_TextAttributes arg, int index);
CFG_TextAttributes CFG_replaceTextAttributesTextAttributeAt(CFG_TextAttributes arg, CFG_TextAttribute elem, int index);
CFG_TextAttributes CFG_makeTextAttributes2(CFG_TextAttribute elem1, CFG_TextAttribute elem2);
CFG_TextAttributes CFG_makeTextAttributes3(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3);
CFG_TextAttributes CFG_makeTextAttributes4(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3, CFG_TextAttribute elem4);
CFG_TextAttributes CFG_makeTextAttributes5(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3, CFG_TextAttribute elem4, CFG_TextAttribute elem5);
CFG_TextAttributes CFG_makeTextAttributes6(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3, CFG_TextAttribute elem4, CFG_TextAttribute elem5, CFG_TextAttribute elem6);

/*}}}  */
/*{{{  constructors */

CFG_Configuration CFG_makeConfigurationList(CFG_Properties list);
CFG_Properties CFG_makePropertiesEmpty(void);
CFG_Properties CFG_makePropertiesSingle(CFG_Property head);
CFG_Properties CFG_makePropertiesMany(CFG_Property head, CFG_Properties tail);
CFG_Property CFG_makePropertyImport(const char* path);
CFG_Property CFG_makePropertyAction(CFG_ActionDescriptionList descriptions, const char* action);
CFG_Property CFG_makePropertyExtension(const char* language, const char* extension);
CFG_Property CFG_makePropertyLibraryPath(const char* label, const char* path);
CFG_Property CFG_makePropertyModulePath(const char* label, const char* path);
CFG_Property CFG_makePropertyTextCategory(CFG_TextCategoryName category, CFG_TextAttributes attributes);
CFG_ActionDescription CFG_makeActionDescriptionDefault(CFG_ActionType actionType, CFG_Event event);
CFG_ActionDescriptionList CFG_makeActionDescriptionListEmpty(void);
CFG_ActionDescriptionList CFG_makeActionDescriptionListSingle(CFG_ActionDescription head);
CFG_ActionDescriptionList CFG_makeActionDescriptionListMany(CFG_ActionDescription head, CFG_ActionDescriptionList tail);
CFG_ActionType CFG_makeActionTypeTermEditor(void);
CFG_ActionType CFG_makeActionTypeTermEditorForModule(const char* moduleId);
CFG_ActionType CFG_makeActionTypeEquationsEditor(void);
CFG_ActionType CFG_makeActionTypeSyntaxEditor(void);
CFG_ActionType CFG_makeActionTypeFeedbackList(void);
CFG_ActionType CFG_makeActionTypeTreePanel(void);
CFG_ActionType CFG_makeActionTypeModulePopup(const char* moduleId);
CFG_ActionType CFG_makeActionTypeNewModulePopup(void);
CFG_ActionType CFG_makeActionTypeStudioMenubar(void);
CFG_ActionType CFG_makeActionTypeStudioToolbar(void);
CFG_ActionType CFG_makeActionTypeWildcard(void);
CFG_Event CFG_makeEventClick(void);
CFG_Event CFG_makeEventIcon(const char* title, const char* path);
CFG_Event CFG_makeEventDefault(CFG_Items items);
CFG_Event CFG_makeEventShortcut(CFG_Items items, const char* shortcut);
CFG_Items CFG_makeItemsEmpty(void);
CFG_Items CFG_makeItemsSingle(const char* head);
CFG_Items CFG_makeItemsMany(const char* head, CFG_Items tail);
CFG_ModuleName CFG_makeModuleNameWildcard(void);
CFG_TextCategoryName CFG_makeTextCategoryNameFocus(void);
CFG_TextCategoryName CFG_makeTextCategoryNameSelection(void);
CFG_TextCategoryName CFG_makeTextCategoryNameNormal(void);
CFG_TextCategoryName CFG_makeTextCategoryNameExtern(const char* name);
CFG_TextAttributes CFG_makeTextAttributesEmpty(void);
CFG_TextAttributes CFG_makeTextAttributesSingle(CFG_TextAttribute head);
CFG_TextAttributes CFG_makeTextAttributesMany(CFG_TextAttribute head, CFG_TextAttributes tail);
CFG_TextAttribute CFG_makeTextAttributeForegroundColor(CFG_Color color);
CFG_TextAttribute CFG_makeTextAttributeBackgroundColor(CFG_Color color);
CFG_TextAttribute CFG_makeTextAttributeStyle(CFG_TextStyle style);
CFG_TextAttribute CFG_makeTextAttributeFont(const char* name);
CFG_TextAttribute CFG_makeTextAttributeSize(int points);
CFG_TextStyle CFG_makeTextStyleBold(void);
CFG_TextStyle CFG_makeTextStyleItalics(void);
CFG_TextStyle CFG_makeTextStyleUnderlined(void);
CFG_Color CFG_makeColorRgb(int red, int green, int blue);

/*}}}  */
/*{{{  equality functions */

ATbool CFG_isEqualConfiguration(CFG_Configuration arg0, CFG_Configuration arg1);
ATbool CFG_isEqualProperties(CFG_Properties arg0, CFG_Properties arg1);
ATbool CFG_isEqualProperty(CFG_Property arg0, CFG_Property arg1);
ATbool CFG_isEqualActionDescription(CFG_ActionDescription arg0, CFG_ActionDescription arg1);
ATbool CFG_isEqualActionDescriptionList(CFG_ActionDescriptionList arg0, CFG_ActionDescriptionList arg1);
ATbool CFG_isEqualActionType(CFG_ActionType arg0, CFG_ActionType arg1);
ATbool CFG_isEqualEvent(CFG_Event arg0, CFG_Event arg1);
ATbool CFG_isEqualItems(CFG_Items arg0, CFG_Items arg1);
ATbool CFG_isEqualModuleName(CFG_ModuleName arg0, CFG_ModuleName arg1);
ATbool CFG_isEqualTextCategoryName(CFG_TextCategoryName arg0, CFG_TextCategoryName arg1);
ATbool CFG_isEqualTextAttributes(CFG_TextAttributes arg0, CFG_TextAttributes arg1);
ATbool CFG_isEqualTextAttribute(CFG_TextAttribute arg0, CFG_TextAttribute arg1);
ATbool CFG_isEqualTextStyle(CFG_TextStyle arg0, CFG_TextStyle arg1);
ATbool CFG_isEqualColor(CFG_Color arg0, CFG_Color arg1);

/*}}}  */
/*{{{  CFG_Configuration accessors */

ATbool CFG_isValidConfiguration(CFG_Configuration arg);
inline ATbool CFG_isConfigurationList(CFG_Configuration arg);
ATbool CFG_hasConfigurationList(CFG_Configuration arg);
CFG_Properties CFG_getConfigurationList(CFG_Configuration arg);
CFG_Configuration CFG_setConfigurationList(CFG_Configuration arg, CFG_Properties list);

/*}}}  */
/*{{{  CFG_Properties accessors */

ATbool CFG_isValidProperties(CFG_Properties arg);
inline ATbool CFG_isPropertiesEmpty(CFG_Properties arg);
inline ATbool CFG_isPropertiesSingle(CFG_Properties arg);
inline ATbool CFG_isPropertiesMany(CFG_Properties arg);
ATbool CFG_hasPropertiesHead(CFG_Properties arg);
ATbool CFG_hasPropertiesTail(CFG_Properties arg);
CFG_Property CFG_getPropertiesHead(CFG_Properties arg);
CFG_Properties CFG_getPropertiesTail(CFG_Properties arg);
CFG_Properties CFG_setPropertiesHead(CFG_Properties arg, CFG_Property head);
CFG_Properties CFG_setPropertiesTail(CFG_Properties arg, CFG_Properties tail);

/*}}}  */
/*{{{  CFG_Property accessors */

ATbool CFG_isValidProperty(CFG_Property arg);
inline ATbool CFG_isPropertyImport(CFG_Property arg);
inline ATbool CFG_isPropertyAction(CFG_Property arg);
inline ATbool CFG_isPropertyExtension(CFG_Property arg);
inline ATbool CFG_isPropertyLibraryPath(CFG_Property arg);
inline ATbool CFG_isPropertyModulePath(CFG_Property arg);
inline ATbool CFG_isPropertyTextCategory(CFG_Property arg);
ATbool CFG_hasPropertyPath(CFG_Property arg);
ATbool CFG_hasPropertyDescriptions(CFG_Property arg);
ATbool CFG_hasPropertyAction(CFG_Property arg);
ATbool CFG_hasPropertyLanguage(CFG_Property arg);
ATbool CFG_hasPropertyExtension(CFG_Property arg);
ATbool CFG_hasPropertyLabel(CFG_Property arg);
ATbool CFG_hasPropertyCategory(CFG_Property arg);
ATbool CFG_hasPropertyAttributes(CFG_Property arg);
char* CFG_getPropertyPath(CFG_Property arg);
CFG_ActionDescriptionList CFG_getPropertyDescriptions(CFG_Property arg);
char* CFG_getPropertyAction(CFG_Property arg);
char* CFG_getPropertyLanguage(CFG_Property arg);
char* CFG_getPropertyExtension(CFG_Property arg);
char* CFG_getPropertyLabel(CFG_Property arg);
CFG_TextCategoryName CFG_getPropertyCategory(CFG_Property arg);
CFG_TextAttributes CFG_getPropertyAttributes(CFG_Property arg);
CFG_Property CFG_setPropertyPath(CFG_Property arg, const char* path);
CFG_Property CFG_setPropertyDescriptions(CFG_Property arg, CFG_ActionDescriptionList descriptions);
CFG_Property CFG_setPropertyAction(CFG_Property arg, const char* action);
CFG_Property CFG_setPropertyLanguage(CFG_Property arg, const char* language);
CFG_Property CFG_setPropertyExtension(CFG_Property arg, const char* extension);
CFG_Property CFG_setPropertyLabel(CFG_Property arg, const char* label);
CFG_Property CFG_setPropertyCategory(CFG_Property arg, CFG_TextCategoryName category);
CFG_Property CFG_setPropertyAttributes(CFG_Property arg, CFG_TextAttributes attributes);

/*}}}  */
/*{{{  CFG_ActionDescription accessors */

ATbool CFG_isValidActionDescription(CFG_ActionDescription arg);
inline ATbool CFG_isActionDescriptionDefault(CFG_ActionDescription arg);
ATbool CFG_hasActionDescriptionActionType(CFG_ActionDescription arg);
ATbool CFG_hasActionDescriptionEvent(CFG_ActionDescription arg);
CFG_ActionType CFG_getActionDescriptionActionType(CFG_ActionDescription arg);
CFG_Event CFG_getActionDescriptionEvent(CFG_ActionDescription arg);
CFG_ActionDescription CFG_setActionDescriptionActionType(CFG_ActionDescription arg, CFG_ActionType actionType);
CFG_ActionDescription CFG_setActionDescriptionEvent(CFG_ActionDescription arg, CFG_Event event);

/*}}}  */
/*{{{  CFG_ActionDescriptionList accessors */

ATbool CFG_isValidActionDescriptionList(CFG_ActionDescriptionList arg);
inline ATbool CFG_isActionDescriptionListEmpty(CFG_ActionDescriptionList arg);
inline ATbool CFG_isActionDescriptionListSingle(CFG_ActionDescriptionList arg);
inline ATbool CFG_isActionDescriptionListMany(CFG_ActionDescriptionList arg);
ATbool CFG_hasActionDescriptionListHead(CFG_ActionDescriptionList arg);
ATbool CFG_hasActionDescriptionListTail(CFG_ActionDescriptionList arg);
CFG_ActionDescription CFG_getActionDescriptionListHead(CFG_ActionDescriptionList arg);
CFG_ActionDescriptionList CFG_getActionDescriptionListTail(CFG_ActionDescriptionList arg);
CFG_ActionDescriptionList CFG_setActionDescriptionListHead(CFG_ActionDescriptionList arg, CFG_ActionDescription head);
CFG_ActionDescriptionList CFG_setActionDescriptionListTail(CFG_ActionDescriptionList arg, CFG_ActionDescriptionList tail);

/*}}}  */
/*{{{  CFG_ActionType accessors */

ATbool CFG_isValidActionType(CFG_ActionType arg);
inline ATbool CFG_isActionTypeTermEditor(CFG_ActionType arg);
inline ATbool CFG_isActionTypeTermEditorForModule(CFG_ActionType arg);
inline ATbool CFG_isActionTypeEquationsEditor(CFG_ActionType arg);
inline ATbool CFG_isActionTypeSyntaxEditor(CFG_ActionType arg);
inline ATbool CFG_isActionTypeFeedbackList(CFG_ActionType arg);
inline ATbool CFG_isActionTypeTreePanel(CFG_ActionType arg);
inline ATbool CFG_isActionTypeModulePopup(CFG_ActionType arg);
inline ATbool CFG_isActionTypeNewModulePopup(CFG_ActionType arg);
inline ATbool CFG_isActionTypeStudioMenubar(CFG_ActionType arg);
inline ATbool CFG_isActionTypeStudioToolbar(CFG_ActionType arg);
inline ATbool CFG_isActionTypeWildcard(CFG_ActionType arg);
ATbool CFG_hasActionTypeModuleId(CFG_ActionType arg);
char* CFG_getActionTypeModuleId(CFG_ActionType arg);
CFG_ActionType CFG_setActionTypeModuleId(CFG_ActionType arg, const char* moduleId);

/*}}}  */
/*{{{  CFG_Event accessors */

ATbool CFG_isValidEvent(CFG_Event arg);
inline ATbool CFG_isEventClick(CFG_Event arg);
inline ATbool CFG_isEventIcon(CFG_Event arg);
inline ATbool CFG_isEventDefault(CFG_Event arg);
inline ATbool CFG_isEventShortcut(CFG_Event arg);
ATbool CFG_hasEventTitle(CFG_Event arg);
ATbool CFG_hasEventPath(CFG_Event arg);
ATbool CFG_hasEventItems(CFG_Event arg);
ATbool CFG_hasEventShortcut(CFG_Event arg);
char* CFG_getEventTitle(CFG_Event arg);
char* CFG_getEventPath(CFG_Event arg);
CFG_Items CFG_getEventItems(CFG_Event arg);
char* CFG_getEventShortcut(CFG_Event arg);
CFG_Event CFG_setEventTitle(CFG_Event arg, const char* title);
CFG_Event CFG_setEventPath(CFG_Event arg, const char* path);
CFG_Event CFG_setEventItems(CFG_Event arg, CFG_Items items);
CFG_Event CFG_setEventShortcut(CFG_Event arg, const char* shortcut);

/*}}}  */
/*{{{  CFG_Items accessors */

ATbool CFG_isValidItems(CFG_Items arg);
inline ATbool CFG_isItemsEmpty(CFG_Items arg);
inline ATbool CFG_isItemsSingle(CFG_Items arg);
inline ATbool CFG_isItemsMany(CFG_Items arg);
ATbool CFG_hasItemsHead(CFG_Items arg);
ATbool CFG_hasItemsTail(CFG_Items arg);
char* CFG_getItemsHead(CFG_Items arg);
CFG_Items CFG_getItemsTail(CFG_Items arg);
CFG_Items CFG_setItemsHead(CFG_Items arg, const char* head);
CFG_Items CFG_setItemsTail(CFG_Items arg, CFG_Items tail);

/*}}}  */
/*{{{  CFG_ModuleName accessors */

ATbool CFG_isValidModuleName(CFG_ModuleName arg);
inline ATbool CFG_isModuleNameWildcard(CFG_ModuleName arg);

/*}}}  */
/*{{{  CFG_TextCategoryName accessors */

ATbool CFG_isValidTextCategoryName(CFG_TextCategoryName arg);
inline ATbool CFG_isTextCategoryNameFocus(CFG_TextCategoryName arg);
inline ATbool CFG_isTextCategoryNameSelection(CFG_TextCategoryName arg);
inline ATbool CFG_isTextCategoryNameNormal(CFG_TextCategoryName arg);
inline ATbool CFG_isTextCategoryNameExtern(CFG_TextCategoryName arg);
ATbool CFG_hasTextCategoryNameName(CFG_TextCategoryName arg);
char* CFG_getTextCategoryNameName(CFG_TextCategoryName arg);
CFG_TextCategoryName CFG_setTextCategoryNameName(CFG_TextCategoryName arg, const char* name);

/*}}}  */
/*{{{  CFG_TextAttributes accessors */

ATbool CFG_isValidTextAttributes(CFG_TextAttributes arg);
inline ATbool CFG_isTextAttributesEmpty(CFG_TextAttributes arg);
inline ATbool CFG_isTextAttributesSingle(CFG_TextAttributes arg);
inline ATbool CFG_isTextAttributesMany(CFG_TextAttributes arg);
ATbool CFG_hasTextAttributesHead(CFG_TextAttributes arg);
ATbool CFG_hasTextAttributesTail(CFG_TextAttributes arg);
CFG_TextAttribute CFG_getTextAttributesHead(CFG_TextAttributes arg);
CFG_TextAttributes CFG_getTextAttributesTail(CFG_TextAttributes arg);
CFG_TextAttributes CFG_setTextAttributesHead(CFG_TextAttributes arg, CFG_TextAttribute head);
CFG_TextAttributes CFG_setTextAttributesTail(CFG_TextAttributes arg, CFG_TextAttributes tail);

/*}}}  */
/*{{{  CFG_TextAttribute accessors */

ATbool CFG_isValidTextAttribute(CFG_TextAttribute arg);
inline ATbool CFG_isTextAttributeForegroundColor(CFG_TextAttribute arg);
inline ATbool CFG_isTextAttributeBackgroundColor(CFG_TextAttribute arg);
inline ATbool CFG_isTextAttributeStyle(CFG_TextAttribute arg);
inline ATbool CFG_isTextAttributeFont(CFG_TextAttribute arg);
inline ATbool CFG_isTextAttributeSize(CFG_TextAttribute arg);
ATbool CFG_hasTextAttributeColor(CFG_TextAttribute arg);
ATbool CFG_hasTextAttributeStyle(CFG_TextAttribute arg);
ATbool CFG_hasTextAttributeName(CFG_TextAttribute arg);
ATbool CFG_hasTextAttributePoints(CFG_TextAttribute arg);
CFG_Color CFG_getTextAttributeColor(CFG_TextAttribute arg);
CFG_TextStyle CFG_getTextAttributeStyle(CFG_TextAttribute arg);
char* CFG_getTextAttributeName(CFG_TextAttribute arg);
int CFG_getTextAttributePoints(CFG_TextAttribute arg);
CFG_TextAttribute CFG_setTextAttributeColor(CFG_TextAttribute arg, CFG_Color color);
CFG_TextAttribute CFG_setTextAttributeStyle(CFG_TextAttribute arg, CFG_TextStyle style);
CFG_TextAttribute CFG_setTextAttributeName(CFG_TextAttribute arg, const char* name);
CFG_TextAttribute CFG_setTextAttributePoints(CFG_TextAttribute arg, int points);

/*}}}  */
/*{{{  CFG_TextStyle accessors */

ATbool CFG_isValidTextStyle(CFG_TextStyle arg);
inline ATbool CFG_isTextStyleBold(CFG_TextStyle arg);
inline ATbool CFG_isTextStyleItalics(CFG_TextStyle arg);
inline ATbool CFG_isTextStyleUnderlined(CFG_TextStyle arg);

/*}}}  */
/*{{{  CFG_Color accessors */

ATbool CFG_isValidColor(CFG_Color arg);
inline ATbool CFG_isColorRgb(CFG_Color arg);
ATbool CFG_hasColorRed(CFG_Color arg);
ATbool CFG_hasColorGreen(CFG_Color arg);
ATbool CFG_hasColorBlue(CFG_Color arg);
int CFG_getColorRed(CFG_Color arg);
int CFG_getColorGreen(CFG_Color arg);
int CFG_getColorBlue(CFG_Color arg);
CFG_Color CFG_setColorRed(CFG_Color arg, int red);
CFG_Color CFG_setColorGreen(CFG_Color arg, int green);
CFG_Color CFG_setColorBlue(CFG_Color arg, int blue);

/*}}}  */
/*{{{  sort visitors */

CFG_Configuration CFG_visitConfiguration(CFG_Configuration arg, CFG_Properties (*acceptList)(CFG_Properties));
CFG_Properties CFG_visitProperties(CFG_Properties arg, CFG_Property (*acceptHead)(CFG_Property));
CFG_Property CFG_visitProperty(CFG_Property arg, char* (*acceptPath)(char*), CFG_ActionDescriptionList (*acceptDescriptions)(CFG_ActionDescriptionList), char* (*acceptAction)(char*), char* (*acceptLanguage)(char*), char* (*acceptExtension)(char*), char* (*acceptLabel)(char*), CFG_TextCategoryName (*acceptCategory)(CFG_TextCategoryName), CFG_TextAttributes (*acceptAttributes)(CFG_TextAttributes));
CFG_ActionDescription CFG_visitActionDescription(CFG_ActionDescription arg, CFG_ActionType (*acceptActionType)(CFG_ActionType), CFG_Event (*acceptEvent)(CFG_Event));
CFG_ActionDescriptionList CFG_visitActionDescriptionList(CFG_ActionDescriptionList arg, CFG_ActionDescription (*acceptHead)(CFG_ActionDescription));
CFG_ActionType CFG_visitActionType(CFG_ActionType arg, char* (*acceptModuleId)(char*));
CFG_Event CFG_visitEvent(CFG_Event arg, char* (*acceptTitle)(char*), char* (*acceptPath)(char*), CFG_Items (*acceptItems)(CFG_Items), char* (*acceptShortcut)(char*));
CFG_Items CFG_visitItems(CFG_Items arg, char* (*acceptHead)(char*));
CFG_ModuleName CFG_visitModuleName(CFG_ModuleName arg);
CFG_TextCategoryName CFG_visitTextCategoryName(CFG_TextCategoryName arg, char* (*acceptName)(char*));
CFG_TextAttributes CFG_visitTextAttributes(CFG_TextAttributes arg, CFG_TextAttribute (*acceptHead)(CFG_TextAttribute));
CFG_TextAttribute CFG_visitTextAttribute(CFG_TextAttribute arg, CFG_Color (*acceptColor)(CFG_Color), CFG_TextStyle (*acceptStyle)(CFG_TextStyle), char* (*acceptName)(char*), int (*acceptPoints)(int));
CFG_TextStyle CFG_visitTextStyle(CFG_TextStyle arg);
CFG_Color CFG_visitColor(CFG_Color arg, int (*acceptRed)(int), int (*acceptGreen)(int), int (*acceptBlue)(int));

/*}}}  */

#endif /* _CONFIG_H */
