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
typedef struct _MC_ActionDescription *MC_ActionDescription;
typedef struct _MC_ActionDescriptionList *MC_ActionDescriptionList;
typedef struct _MC_ActionType *MC_ActionType;
typedef struct _MC_Event *MC_Event;
typedef struct _MC_Items *MC_Items;
typedef struct _MC_ModuleName *MC_ModuleName;
typedef struct _MC_TextCategoryName *MC_TextCategoryName;
typedef struct _MC_TextAttributes *MC_TextAttributes;
typedef struct _MC_TextAttribute *MC_TextAttribute;
typedef struct _MC_TextStyle *MC_TextStyle;
typedef struct _MC_Color *MC_Color;

/*}}}  */

void MC_initMetaConfigApi(void);

/*{{{  protect functions */

void MC_protectConfiguration(MC_Configuration *arg);
void MC_protectProperties(MC_Properties *arg);
void MC_protectProperty(MC_Property *arg);
void MC_protectActionDescription(MC_ActionDescription *arg);
void MC_protectActionDescriptionList(MC_ActionDescriptionList *arg);
void MC_protectActionType(MC_ActionType *arg);
void MC_protectEvent(MC_Event *arg);
void MC_protectItems(MC_Items *arg);
void MC_protectModuleName(MC_ModuleName *arg);
void MC_protectTextCategoryName(MC_TextCategoryName *arg);
void MC_protectTextAttributes(MC_TextAttributes *arg);
void MC_protectTextAttribute(MC_TextAttribute *arg);
void MC_protectTextStyle(MC_TextStyle *arg);
void MC_protectColor(MC_Color *arg);

/*}}}  */
/*{{{  term conversion functions */

MC_Configuration MC_ConfigurationFromTerm(ATerm t);
ATerm MC_ConfigurationToTerm(MC_Configuration arg);
MC_Properties MC_PropertiesFromTerm(ATerm t);
ATerm MC_PropertiesToTerm(MC_Properties arg);
MC_Property MC_PropertyFromTerm(ATerm t);
ATerm MC_PropertyToTerm(MC_Property arg);
MC_ActionDescription MC_ActionDescriptionFromTerm(ATerm t);
ATerm MC_ActionDescriptionToTerm(MC_ActionDescription arg);
MC_ActionDescriptionList MC_ActionDescriptionListFromTerm(ATerm t);
ATerm MC_ActionDescriptionListToTerm(MC_ActionDescriptionList arg);
MC_ActionType MC_ActionTypeFromTerm(ATerm t);
ATerm MC_ActionTypeToTerm(MC_ActionType arg);
MC_Event MC_EventFromTerm(ATerm t);
ATerm MC_EventToTerm(MC_Event arg);
MC_Items MC_ItemsFromTerm(ATerm t);
ATerm MC_ItemsToTerm(MC_Items arg);
MC_ModuleName MC_ModuleNameFromTerm(ATerm t);
ATerm MC_ModuleNameToTerm(MC_ModuleName arg);
MC_TextCategoryName MC_TextCategoryNameFromTerm(ATerm t);
ATerm MC_TextCategoryNameToTerm(MC_TextCategoryName arg);
MC_TextAttributes MC_TextAttributesFromTerm(ATerm t);
ATerm MC_TextAttributesToTerm(MC_TextAttributes arg);
MC_TextAttribute MC_TextAttributeFromTerm(ATerm t);
ATerm MC_TextAttributeToTerm(MC_TextAttribute arg);
MC_TextStyle MC_TextStyleFromTerm(ATerm t);
ATerm MC_TextStyleToTerm(MC_TextStyle arg);
MC_Color MC_ColorFromTerm(ATerm t);
ATerm MC_ColorToTerm(MC_Color arg);

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
int MC_getActionDescriptionListLength (MC_ActionDescriptionList arg);
MC_ActionDescriptionList MC_reverseActionDescriptionList(MC_ActionDescriptionList arg);
MC_ActionDescriptionList MC_appendActionDescriptionList(MC_ActionDescriptionList arg, MC_ActionDescription elem);
MC_ActionDescriptionList MC_concatActionDescriptionList(MC_ActionDescriptionList arg0, MC_ActionDescriptionList arg1);
MC_ActionDescriptionList MC_sliceActionDescriptionList(MC_ActionDescriptionList arg, int start, int end);
MC_ActionDescription MC_getActionDescriptionListActionDescriptionAt(MC_ActionDescriptionList arg, int index);
MC_ActionDescriptionList MC_replaceActionDescriptionListActionDescriptionAt(MC_ActionDescriptionList arg, MC_ActionDescription elem, int index);
MC_ActionDescriptionList MC_makeActionDescriptionList2(MC_ActionDescription elem1, MC_ActionDescription elem2);
MC_ActionDescriptionList MC_makeActionDescriptionList3(MC_ActionDescription elem1, MC_ActionDescription elem2, MC_ActionDescription elem3);
MC_ActionDescriptionList MC_makeActionDescriptionList4(MC_ActionDescription elem1, MC_ActionDescription elem2, MC_ActionDescription elem3, MC_ActionDescription elem4);
MC_ActionDescriptionList MC_makeActionDescriptionList5(MC_ActionDescription elem1, MC_ActionDescription elem2, MC_ActionDescription elem3, MC_ActionDescription elem4, MC_ActionDescription elem5);
MC_ActionDescriptionList MC_makeActionDescriptionList6(MC_ActionDescription elem1, MC_ActionDescription elem2, MC_ActionDescription elem3, MC_ActionDescription elem4, MC_ActionDescription elem5, MC_ActionDescription elem6);
int MC_getItemsLength (MC_Items arg);
MC_Items MC_reverseItems(MC_Items arg);
MC_Items MC_appendItems(MC_Items arg, char* elem);
MC_Items MC_concatItems(MC_Items arg0, MC_Items arg1);
MC_Items MC_sliceItems(MC_Items arg, int start, int end);
char* MC_getItemsstrAt(MC_Items arg, int index);
MC_Items MC_replaceItemsstrAt(MC_Items arg, char* elem, int index);
MC_Items MC_makeItems2(char* elem1, char* elem2);
MC_Items MC_makeItems3(char* elem1, char* elem2, char* elem3);
MC_Items MC_makeItems4(char* elem1, char* elem2, char* elem3, char* elem4);
MC_Items MC_makeItems5(char* elem1, char* elem2, char* elem3, char* elem4, char* elem5);
MC_Items MC_makeItems6(char* elem1, char* elem2, char* elem3, char* elem4, char* elem5, char* elem6);
int MC_getTextAttributesLength (MC_TextAttributes arg);
MC_TextAttributes MC_reverseTextAttributes(MC_TextAttributes arg);
MC_TextAttributes MC_appendTextAttributes(MC_TextAttributes arg, MC_TextAttribute elem);
MC_TextAttributes MC_concatTextAttributes(MC_TextAttributes arg0, MC_TextAttributes arg1);
MC_TextAttributes MC_sliceTextAttributes(MC_TextAttributes arg, int start, int end);
MC_TextAttribute MC_getTextAttributesTextAttributeAt(MC_TextAttributes arg, int index);
MC_TextAttributes MC_replaceTextAttributesTextAttributeAt(MC_TextAttributes arg, MC_TextAttribute elem, int index);
MC_TextAttributes MC_makeTextAttributes2(MC_TextAttribute elem1, MC_TextAttribute elem2);
MC_TextAttributes MC_makeTextAttributes3(MC_TextAttribute elem1, MC_TextAttribute elem2, MC_TextAttribute elem3);
MC_TextAttributes MC_makeTextAttributes4(MC_TextAttribute elem1, MC_TextAttribute elem2, MC_TextAttribute elem3, MC_TextAttribute elem4);
MC_TextAttributes MC_makeTextAttributes5(MC_TextAttribute elem1, MC_TextAttribute elem2, MC_TextAttribute elem3, MC_TextAttribute elem4, MC_TextAttribute elem5);
MC_TextAttributes MC_makeTextAttributes6(MC_TextAttribute elem1, MC_TextAttribute elem2, MC_TextAttribute elem3, MC_TextAttribute elem4, MC_TextAttribute elem5, MC_TextAttribute elem6);

/*}}}  */
/*{{{  constructors */

MC_Configuration MC_makeConfigurationList(MC_Properties list);
MC_Properties MC_makePropertiesEmpty(void);
MC_Properties MC_makePropertiesSingle(MC_Property head);
MC_Properties MC_makePropertiesMany(MC_Property head, MC_Properties tail);
MC_Property MC_makePropertyAction(MC_ActionDescriptionList descriptions, ATerm actions);
MC_Property MC_makePropertyExtension(const char* language, const char* extension);
MC_Property MC_makePropertyModulePath(const char* path);
MC_Property MC_makePropertyTextCategory(MC_TextCategoryName category, MC_TextAttributes attributes);
MC_ActionDescription MC_makeActionDescriptionDefault(MC_ActionType actionType, MC_Event event);
MC_ActionDescriptionList MC_makeActionDescriptionListEmpty(void);
MC_ActionDescriptionList MC_makeActionDescriptionListSingle(MC_ActionDescription head);
MC_ActionDescriptionList MC_makeActionDescriptionListMany(MC_ActionDescription head, MC_ActionDescriptionList tail);
MC_ActionType MC_makeActionTypeTermEditor(void);
MC_ActionType MC_makeActionTypeTermEditorForModule(const char* moduleId);
MC_ActionType MC_makeActionTypeEquationsEditor(void);
MC_ActionType MC_makeActionTypeSyntaxEditor(void);
MC_ActionType MC_makeActionTypeFeedbackList(void);
MC_ActionType MC_makeActionTypeTreePanel(void);
MC_ActionType MC_makeActionTypeModulePopup(const char* moduleId);
MC_ActionType MC_makeActionTypeNewModulePopup(void);
MC_ActionType MC_makeActionTypeStudioMenubar(void);
MC_ActionType MC_makeActionTypeStudioToolbar(void);
MC_ActionType MC_makeActionTypeWildcard(void);
MC_Event MC_makeEventClick(void);
MC_Event MC_makeEventIcon(const char* title, const char* path);
MC_Event MC_makeEventDefault(MC_Items items);
MC_Event MC_makeEventShortcut(MC_Items items, const char* shortcut);
MC_Items MC_makeItemsEmpty(void);
MC_Items MC_makeItemsSingle(const char* head);
MC_Items MC_makeItemsMany(const char* head, MC_Items tail);
MC_ModuleName MC_makeModuleNameWildcard(void);
MC_TextCategoryName MC_makeTextCategoryNameFocus(void);
MC_TextCategoryName MC_makeTextCategoryNameSelection(void);
MC_TextCategoryName MC_makeTextCategoryNameNormal(void);
MC_TextCategoryName MC_makeTextCategoryNameExtern(const char* name);
MC_TextAttributes MC_makeTextAttributesEmpty(void);
MC_TextAttributes MC_makeTextAttributesSingle(MC_TextAttribute head);
MC_TextAttributes MC_makeTextAttributesMany(MC_TextAttribute head, MC_TextAttributes tail);
MC_TextAttribute MC_makeTextAttributeForegroundColor(MC_Color color);
MC_TextAttribute MC_makeTextAttributeBackgroundColor(MC_Color color);
MC_TextAttribute MC_makeTextAttributeStyle(MC_TextStyle style);
MC_TextAttribute MC_makeTextAttributeFont(const char* name);
MC_TextAttribute MC_makeTextAttributeSize(int points);
MC_TextStyle MC_makeTextStyleBold(void);
MC_TextStyle MC_makeTextStyleItalics(void);
MC_TextStyle MC_makeTextStyleUnderlined(void);
MC_Color MC_makeColorRgb(int red, int green, int blue);

/*}}}  */
/*{{{  equality functions */

ATbool MC_isEqualConfiguration(MC_Configuration arg0, MC_Configuration arg1);
ATbool MC_isEqualProperties(MC_Properties arg0, MC_Properties arg1);
ATbool MC_isEqualProperty(MC_Property arg0, MC_Property arg1);
ATbool MC_isEqualActionDescription(MC_ActionDescription arg0, MC_ActionDescription arg1);
ATbool MC_isEqualActionDescriptionList(MC_ActionDescriptionList arg0, MC_ActionDescriptionList arg1);
ATbool MC_isEqualActionType(MC_ActionType arg0, MC_ActionType arg1);
ATbool MC_isEqualEvent(MC_Event arg0, MC_Event arg1);
ATbool MC_isEqualItems(MC_Items arg0, MC_Items arg1);
ATbool MC_isEqualModuleName(MC_ModuleName arg0, MC_ModuleName arg1);
ATbool MC_isEqualTextCategoryName(MC_TextCategoryName arg0, MC_TextCategoryName arg1);
ATbool MC_isEqualTextAttributes(MC_TextAttributes arg0, MC_TextAttributes arg1);
ATbool MC_isEqualTextAttribute(MC_TextAttribute arg0, MC_TextAttribute arg1);
ATbool MC_isEqualTextStyle(MC_TextStyle arg0, MC_TextStyle arg1);
ATbool MC_isEqualColor(MC_Color arg0, MC_Color arg1);

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
ATbool MC_hasPropertiesTail(MC_Properties arg);
MC_Property MC_getPropertiesHead(MC_Properties arg);
MC_Properties MC_getPropertiesTail(MC_Properties arg);
MC_Properties MC_setPropertiesHead(MC_Properties arg, MC_Property head);
MC_Properties MC_setPropertiesTail(MC_Properties arg, MC_Properties tail);

/*}}}  */
/*{{{  MC_Property accessors */

ATbool MC_isValidProperty(MC_Property arg);
inline ATbool MC_isPropertyAction(MC_Property arg);
inline ATbool MC_isPropertyExtension(MC_Property arg);
inline ATbool MC_isPropertyModulePath(MC_Property arg);
inline ATbool MC_isPropertyTextCategory(MC_Property arg);
ATbool MC_hasPropertyDescriptions(MC_Property arg);
ATbool MC_hasPropertyActions(MC_Property arg);
ATbool MC_hasPropertyLanguage(MC_Property arg);
ATbool MC_hasPropertyExtension(MC_Property arg);
ATbool MC_hasPropertyPath(MC_Property arg);
ATbool MC_hasPropertyCategory(MC_Property arg);
ATbool MC_hasPropertyAttributes(MC_Property arg);
MC_ActionDescriptionList MC_getPropertyDescriptions(MC_Property arg);
ATerm MC_getPropertyActions(MC_Property arg);
char* MC_getPropertyLanguage(MC_Property arg);
char* MC_getPropertyExtension(MC_Property arg);
char* MC_getPropertyPath(MC_Property arg);
MC_TextCategoryName MC_getPropertyCategory(MC_Property arg);
MC_TextAttributes MC_getPropertyAttributes(MC_Property arg);
MC_Property MC_setPropertyDescriptions(MC_Property arg, MC_ActionDescriptionList descriptions);
MC_Property MC_setPropertyActions(MC_Property arg, ATerm actions);
MC_Property MC_setPropertyLanguage(MC_Property arg, const char* language);
MC_Property MC_setPropertyExtension(MC_Property arg, const char* extension);
MC_Property MC_setPropertyPath(MC_Property arg, const char* path);
MC_Property MC_setPropertyCategory(MC_Property arg, MC_TextCategoryName category);
MC_Property MC_setPropertyAttributes(MC_Property arg, MC_TextAttributes attributes);

/*}}}  */
/*{{{  MC_ActionDescription accessors */

ATbool MC_isValidActionDescription(MC_ActionDescription arg);
inline ATbool MC_isActionDescriptionDefault(MC_ActionDescription arg);
ATbool MC_hasActionDescriptionActionType(MC_ActionDescription arg);
ATbool MC_hasActionDescriptionEvent(MC_ActionDescription arg);
MC_ActionType MC_getActionDescriptionActionType(MC_ActionDescription arg);
MC_Event MC_getActionDescriptionEvent(MC_ActionDescription arg);
MC_ActionDescription MC_setActionDescriptionActionType(MC_ActionDescription arg, MC_ActionType actionType);
MC_ActionDescription MC_setActionDescriptionEvent(MC_ActionDescription arg, MC_Event event);

/*}}}  */
/*{{{  MC_ActionDescriptionList accessors */

ATbool MC_isValidActionDescriptionList(MC_ActionDescriptionList arg);
inline ATbool MC_isActionDescriptionListEmpty(MC_ActionDescriptionList arg);
inline ATbool MC_isActionDescriptionListSingle(MC_ActionDescriptionList arg);
inline ATbool MC_isActionDescriptionListMany(MC_ActionDescriptionList arg);
ATbool MC_hasActionDescriptionListHead(MC_ActionDescriptionList arg);
ATbool MC_hasActionDescriptionListTail(MC_ActionDescriptionList arg);
MC_ActionDescription MC_getActionDescriptionListHead(MC_ActionDescriptionList arg);
MC_ActionDescriptionList MC_getActionDescriptionListTail(MC_ActionDescriptionList arg);
MC_ActionDescriptionList MC_setActionDescriptionListHead(MC_ActionDescriptionList arg, MC_ActionDescription head);
MC_ActionDescriptionList MC_setActionDescriptionListTail(MC_ActionDescriptionList arg, MC_ActionDescriptionList tail);

/*}}}  */
/*{{{  MC_ActionType accessors */

ATbool MC_isValidActionType(MC_ActionType arg);
inline ATbool MC_isActionTypeTermEditor(MC_ActionType arg);
inline ATbool MC_isActionTypeTermEditorForModule(MC_ActionType arg);
inline ATbool MC_isActionTypeEquationsEditor(MC_ActionType arg);
inline ATbool MC_isActionTypeSyntaxEditor(MC_ActionType arg);
inline ATbool MC_isActionTypeFeedbackList(MC_ActionType arg);
inline ATbool MC_isActionTypeTreePanel(MC_ActionType arg);
inline ATbool MC_isActionTypeModulePopup(MC_ActionType arg);
inline ATbool MC_isActionTypeNewModulePopup(MC_ActionType arg);
inline ATbool MC_isActionTypeStudioMenubar(MC_ActionType arg);
inline ATbool MC_isActionTypeStudioToolbar(MC_ActionType arg);
inline ATbool MC_isActionTypeWildcard(MC_ActionType arg);
ATbool MC_hasActionTypeModuleId(MC_ActionType arg);
char* MC_getActionTypeModuleId(MC_ActionType arg);
MC_ActionType MC_setActionTypeModuleId(MC_ActionType arg, const char* moduleId);

/*}}}  */
/*{{{  MC_Event accessors */

ATbool MC_isValidEvent(MC_Event arg);
inline ATbool MC_isEventClick(MC_Event arg);
inline ATbool MC_isEventIcon(MC_Event arg);
inline ATbool MC_isEventDefault(MC_Event arg);
inline ATbool MC_isEventShortcut(MC_Event arg);
ATbool MC_hasEventTitle(MC_Event arg);
ATbool MC_hasEventPath(MC_Event arg);
ATbool MC_hasEventItems(MC_Event arg);
ATbool MC_hasEventShortcut(MC_Event arg);
char* MC_getEventTitle(MC_Event arg);
char* MC_getEventPath(MC_Event arg);
MC_Items MC_getEventItems(MC_Event arg);
char* MC_getEventShortcut(MC_Event arg);
MC_Event MC_setEventTitle(MC_Event arg, const char* title);
MC_Event MC_setEventPath(MC_Event arg, const char* path);
MC_Event MC_setEventItems(MC_Event arg, MC_Items items);
MC_Event MC_setEventShortcut(MC_Event arg, const char* shortcut);

/*}}}  */
/*{{{  MC_Items accessors */

ATbool MC_isValidItems(MC_Items arg);
inline ATbool MC_isItemsEmpty(MC_Items arg);
inline ATbool MC_isItemsSingle(MC_Items arg);
inline ATbool MC_isItemsMany(MC_Items arg);
ATbool MC_hasItemsHead(MC_Items arg);
ATbool MC_hasItemsTail(MC_Items arg);
char* MC_getItemsHead(MC_Items arg);
MC_Items MC_getItemsTail(MC_Items arg);
MC_Items MC_setItemsHead(MC_Items arg, const char* head);
MC_Items MC_setItemsTail(MC_Items arg, MC_Items tail);

/*}}}  */
/*{{{  MC_ModuleName accessors */

ATbool MC_isValidModuleName(MC_ModuleName arg);
inline ATbool MC_isModuleNameWildcard(MC_ModuleName arg);

/*}}}  */
/*{{{  MC_TextCategoryName accessors */

ATbool MC_isValidTextCategoryName(MC_TextCategoryName arg);
inline ATbool MC_isTextCategoryNameFocus(MC_TextCategoryName arg);
inline ATbool MC_isTextCategoryNameSelection(MC_TextCategoryName arg);
inline ATbool MC_isTextCategoryNameNormal(MC_TextCategoryName arg);
inline ATbool MC_isTextCategoryNameExtern(MC_TextCategoryName arg);
ATbool MC_hasTextCategoryNameName(MC_TextCategoryName arg);
char* MC_getTextCategoryNameName(MC_TextCategoryName arg);
MC_TextCategoryName MC_setTextCategoryNameName(MC_TextCategoryName arg, const char* name);

/*}}}  */
/*{{{  MC_TextAttributes accessors */

ATbool MC_isValidTextAttributes(MC_TextAttributes arg);
inline ATbool MC_isTextAttributesEmpty(MC_TextAttributes arg);
inline ATbool MC_isTextAttributesSingle(MC_TextAttributes arg);
inline ATbool MC_isTextAttributesMany(MC_TextAttributes arg);
ATbool MC_hasTextAttributesHead(MC_TextAttributes arg);
ATbool MC_hasTextAttributesTail(MC_TextAttributes arg);
MC_TextAttribute MC_getTextAttributesHead(MC_TextAttributes arg);
MC_TextAttributes MC_getTextAttributesTail(MC_TextAttributes arg);
MC_TextAttributes MC_setTextAttributesHead(MC_TextAttributes arg, MC_TextAttribute head);
MC_TextAttributes MC_setTextAttributesTail(MC_TextAttributes arg, MC_TextAttributes tail);

/*}}}  */
/*{{{  MC_TextAttribute accessors */

ATbool MC_isValidTextAttribute(MC_TextAttribute arg);
inline ATbool MC_isTextAttributeForegroundColor(MC_TextAttribute arg);
inline ATbool MC_isTextAttributeBackgroundColor(MC_TextAttribute arg);
inline ATbool MC_isTextAttributeStyle(MC_TextAttribute arg);
inline ATbool MC_isTextAttributeFont(MC_TextAttribute arg);
inline ATbool MC_isTextAttributeSize(MC_TextAttribute arg);
ATbool MC_hasTextAttributeColor(MC_TextAttribute arg);
ATbool MC_hasTextAttributeStyle(MC_TextAttribute arg);
ATbool MC_hasTextAttributeName(MC_TextAttribute arg);
ATbool MC_hasTextAttributePoints(MC_TextAttribute arg);
MC_Color MC_getTextAttributeColor(MC_TextAttribute arg);
MC_TextStyle MC_getTextAttributeStyle(MC_TextAttribute arg);
char* MC_getTextAttributeName(MC_TextAttribute arg);
int MC_getTextAttributePoints(MC_TextAttribute arg);
MC_TextAttribute MC_setTextAttributeColor(MC_TextAttribute arg, MC_Color color);
MC_TextAttribute MC_setTextAttributeStyle(MC_TextAttribute arg, MC_TextStyle style);
MC_TextAttribute MC_setTextAttributeName(MC_TextAttribute arg, const char* name);
MC_TextAttribute MC_setTextAttributePoints(MC_TextAttribute arg, int points);

/*}}}  */
/*{{{  MC_TextStyle accessors */

ATbool MC_isValidTextStyle(MC_TextStyle arg);
inline ATbool MC_isTextStyleBold(MC_TextStyle arg);
inline ATbool MC_isTextStyleItalics(MC_TextStyle arg);
inline ATbool MC_isTextStyleUnderlined(MC_TextStyle arg);

/*}}}  */
/*{{{  MC_Color accessors */

ATbool MC_isValidColor(MC_Color arg);
inline ATbool MC_isColorRgb(MC_Color arg);
ATbool MC_hasColorRed(MC_Color arg);
ATbool MC_hasColorGreen(MC_Color arg);
ATbool MC_hasColorBlue(MC_Color arg);
int MC_getColorRed(MC_Color arg);
int MC_getColorGreen(MC_Color arg);
int MC_getColorBlue(MC_Color arg);
MC_Color MC_setColorRed(MC_Color arg, int red);
MC_Color MC_setColorGreen(MC_Color arg, int green);
MC_Color MC_setColorBlue(MC_Color arg, int blue);

/*}}}  */
/*{{{  sort visitors */

MC_Configuration MC_visitConfiguration(MC_Configuration arg, MC_Properties (*acceptList)(MC_Properties));
MC_Properties MC_visitProperties(MC_Properties arg, MC_Property (*acceptHead)(MC_Property));
MC_Property MC_visitProperty(MC_Property arg, MC_ActionDescriptionList (*acceptDescriptions)(MC_ActionDescriptionList), ATerm (*acceptActions)(ATerm), char* (*acceptLanguage)(char*), char* (*acceptExtension)(char*), char* (*acceptPath)(char*), MC_TextCategoryName (*acceptCategory)(MC_TextCategoryName), MC_TextAttributes (*acceptAttributes)(MC_TextAttributes));
MC_ActionDescription MC_visitActionDescription(MC_ActionDescription arg, MC_ActionType (*acceptActionType)(MC_ActionType), MC_Event (*acceptEvent)(MC_Event));
MC_ActionDescriptionList MC_visitActionDescriptionList(MC_ActionDescriptionList arg, MC_ActionDescription (*acceptHead)(MC_ActionDescription));
MC_ActionType MC_visitActionType(MC_ActionType arg, char* (*acceptModuleId)(char*));
MC_Event MC_visitEvent(MC_Event arg, char* (*acceptTitle)(char*), char* (*acceptPath)(char*), MC_Items (*acceptItems)(MC_Items), char* (*acceptShortcut)(char*));
MC_Items MC_visitItems(MC_Items arg, char* (*acceptHead)(char*));
MC_ModuleName MC_visitModuleName(MC_ModuleName arg);
MC_TextCategoryName MC_visitTextCategoryName(MC_TextCategoryName arg, char* (*acceptName)(char*));
MC_TextAttributes MC_visitTextAttributes(MC_TextAttributes arg, MC_TextAttribute (*acceptHead)(MC_TextAttribute));
MC_TextAttribute MC_visitTextAttribute(MC_TextAttribute arg, MC_Color (*acceptColor)(MC_Color), MC_TextStyle (*acceptStyle)(MC_TextStyle), char* (*acceptName)(char*), int (*acceptPoints)(int));
MC_TextStyle MC_visitTextStyle(MC_TextStyle arg);
MC_Color MC_visitColor(MC_Color arg, int (*acceptRed)(int), int (*acceptGreen)(int), int (*acceptBlue)(int));

/*}}}  */

#endif /* _METACONFIG_H */
