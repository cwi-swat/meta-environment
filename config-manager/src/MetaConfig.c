#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "MetaConfig.h"

/*{{{  conversion functions */

ATerm MC_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

ATerm MC_byteToChar(char ch)
{
    return (ATerm) ATmakeInt(ch);
}

char *MC_charsToString(ATerm arg)
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

char MC_charToByte(ATerm arg)
{
    return (char) ATgetInt((ATermInt) arg);
}


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _MC_Configuration;
typedef struct ATerm _MC_Properties;
typedef struct ATerm _MC_Property;
typedef struct ATerm _MC_ActionDescription;
typedef struct ATerm _MC_ActionDescriptionList;
typedef struct ATerm _MC_ActionType;
typedef struct ATerm _MC_Event;
typedef struct ATerm _MC_Items;
typedef struct ATerm _MC_ModuleName;
typedef struct ATerm _MC_TextCategoryName;
typedef struct ATerm _MC_TextAttributes;
typedef struct ATerm _MC_TextAttribute;
typedef struct ATerm _MC_TextStyle;
typedef struct ATerm _MC_Color;

/*}}}  */

/*{{{  void MC_initMetaConfigApi(void) */

void MC_initMetaConfigApi(void)
{
  init_MetaConfig_dict();
}

/*}}}  */

/*{{{  protect functions */

void MC_protectConfiguration(MC_Configuration *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectProperties(MC_Properties *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectProperty(MC_Property *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectActionDescription(MC_ActionDescription *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectActionDescriptionList(MC_ActionDescriptionList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectActionType(MC_ActionType *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectEvent(MC_Event *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectItems(MC_Items *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectModuleName(MC_ModuleName *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectTextCategoryName(MC_TextCategoryName *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectTextAttributes(MC_TextAttributes *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectTextAttribute(MC_TextAttribute *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectTextStyle(MC_TextStyle *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectColor(MC_Color *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  MC_Configuration MC_ConfigurationFromTerm(ATerm t) */

MC_Configuration MC_ConfigurationFromTerm(ATerm t)
{
  return (MC_Configuration)t;
}

/*}}}  */
/*{{{  ATerm MC_ConfigurationToTerm(MC_Configuration arg) */

ATerm MC_ConfigurationToTerm(MC_Configuration arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_Properties MC_PropertiesFromTerm(ATerm t) */

MC_Properties MC_PropertiesFromTerm(ATerm t)
{
  return (MC_Properties)t;
}

/*}}}  */
/*{{{  ATerm MC_PropertiesToTerm(MC_Properties arg) */

ATerm MC_PropertiesToTerm(MC_Properties arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_Property MC_PropertyFromTerm(ATerm t) */

MC_Property MC_PropertyFromTerm(ATerm t)
{
  return (MC_Property)t;
}

/*}}}  */
/*{{{  ATerm MC_PropertyToTerm(MC_Property arg) */

ATerm MC_PropertyToTerm(MC_Property arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_ActionDescription MC_ActionDescriptionFromTerm(ATerm t) */

MC_ActionDescription MC_ActionDescriptionFromTerm(ATerm t)
{
  return (MC_ActionDescription)t;
}

/*}}}  */
/*{{{  ATerm MC_ActionDescriptionToTerm(MC_ActionDescription arg) */

ATerm MC_ActionDescriptionToTerm(MC_ActionDescription arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_ActionDescriptionList MC_ActionDescriptionListFromTerm(ATerm t) */

MC_ActionDescriptionList MC_ActionDescriptionListFromTerm(ATerm t)
{
  return (MC_ActionDescriptionList)t;
}

/*}}}  */
/*{{{  ATerm MC_ActionDescriptionListToTerm(MC_ActionDescriptionList arg) */

ATerm MC_ActionDescriptionListToTerm(MC_ActionDescriptionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_ActionType MC_ActionTypeFromTerm(ATerm t) */

MC_ActionType MC_ActionTypeFromTerm(ATerm t)
{
  return (MC_ActionType)t;
}

/*}}}  */
/*{{{  ATerm MC_ActionTypeToTerm(MC_ActionType arg) */

ATerm MC_ActionTypeToTerm(MC_ActionType arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_Event MC_EventFromTerm(ATerm t) */

MC_Event MC_EventFromTerm(ATerm t)
{
  return (MC_Event)t;
}

/*}}}  */
/*{{{  ATerm MC_EventToTerm(MC_Event arg) */

ATerm MC_EventToTerm(MC_Event arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_Items MC_ItemsFromTerm(ATerm t) */

MC_Items MC_ItemsFromTerm(ATerm t)
{
  return (MC_Items)t;
}

/*}}}  */
/*{{{  ATerm MC_ItemsToTerm(MC_Items arg) */

ATerm MC_ItemsToTerm(MC_Items arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_ModuleName MC_ModuleNameFromTerm(ATerm t) */

MC_ModuleName MC_ModuleNameFromTerm(ATerm t)
{
  return (MC_ModuleName)t;
}

/*}}}  */
/*{{{  ATerm MC_ModuleNameToTerm(MC_ModuleName arg) */

ATerm MC_ModuleNameToTerm(MC_ModuleName arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_TextCategoryName MC_TextCategoryNameFromTerm(ATerm t) */

MC_TextCategoryName MC_TextCategoryNameFromTerm(ATerm t)
{
  return (MC_TextCategoryName)t;
}

/*}}}  */
/*{{{  ATerm MC_TextCategoryNameToTerm(MC_TextCategoryName arg) */

ATerm MC_TextCategoryNameToTerm(MC_TextCategoryName arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_TextAttributes MC_TextAttributesFromTerm(ATerm t) */

MC_TextAttributes MC_TextAttributesFromTerm(ATerm t)
{
  return (MC_TextAttributes)t;
}

/*}}}  */
/*{{{  ATerm MC_TextAttributesToTerm(MC_TextAttributes arg) */

ATerm MC_TextAttributesToTerm(MC_TextAttributes arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_TextAttribute MC_TextAttributeFromTerm(ATerm t) */

MC_TextAttribute MC_TextAttributeFromTerm(ATerm t)
{
  return (MC_TextAttribute)t;
}

/*}}}  */
/*{{{  ATerm MC_TextAttributeToTerm(MC_TextAttribute arg) */

ATerm MC_TextAttributeToTerm(MC_TextAttribute arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_TextStyle MC_TextStyleFromTerm(ATerm t) */

MC_TextStyle MC_TextStyleFromTerm(ATerm t)
{
  return (MC_TextStyle)t;
}

/*}}}  */
/*{{{  ATerm MC_TextStyleToTerm(MC_TextStyle arg) */

ATerm MC_TextStyleToTerm(MC_TextStyle arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_Color MC_ColorFromTerm(ATerm t) */

MC_Color MC_ColorFromTerm(ATerm t)
{
  return (MC_Color)t;
}

/*}}}  */
/*{{{  ATerm MC_ColorToTerm(MC_Color arg) */

ATerm MC_ColorToTerm(MC_Color arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int MC_getPropertiesLength (MC_Properties arg) {
  return ATgetLength((ATermList) arg);
}
MC_Properties MC_reverseProperties(MC_Properties arg) {
  return (MC_Properties) ATreverse((ATermList) arg);
}
MC_Properties MC_appendProperties(MC_Properties arg, MC_Property elem) {
  return (MC_Properties) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
MC_Properties MC_concatProperties(MC_Properties arg0, MC_Properties arg1) {
  return (MC_Properties) ATconcat((ATermList) arg0, (ATermList) arg1);
}
MC_Properties MC_sliceProperties(MC_Properties arg, int start, int end) {
  return (MC_Properties) ATgetSlice((ATermList) arg, start, end);
}
MC_Property MC_getPropertiesPropertyAt(MC_Properties arg, int index) {
 return (MC_Property)ATelementAt((ATermList) arg,index);
}
MC_Properties MC_replacePropertiesPropertyAt(MC_Properties arg, MC_Property elem, int index) {
 return (MC_Properties) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
MC_Properties MC_makeProperties2(MC_Property elem1, MC_Property elem2) {
  return (MC_Properties) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
MC_Properties MC_makeProperties3(MC_Property elem1, MC_Property elem2, MC_Property elem3) {
  return (MC_Properties) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
MC_Properties MC_makeProperties4(MC_Property elem1, MC_Property elem2, MC_Property elem3, MC_Property elem4) {
  return (MC_Properties) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
MC_Properties MC_makeProperties5(MC_Property elem1, MC_Property elem2, MC_Property elem3, MC_Property elem4, MC_Property elem5) {
  return (MC_Properties) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
MC_Properties MC_makeProperties6(MC_Property elem1, MC_Property elem2, MC_Property elem3, MC_Property elem4, MC_Property elem5, MC_Property elem6) {
  return (MC_Properties) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int MC_getActionDescriptionListLength (MC_ActionDescriptionList arg) {
  return ATgetLength((ATermList) arg);
}
MC_ActionDescriptionList MC_reverseActionDescriptionList(MC_ActionDescriptionList arg) {
  return (MC_ActionDescriptionList) ATreverse((ATermList) arg);
}
MC_ActionDescriptionList MC_appendActionDescriptionList(MC_ActionDescriptionList arg, MC_ActionDescription elem) {
  return (MC_ActionDescriptionList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
MC_ActionDescriptionList MC_concatActionDescriptionList(MC_ActionDescriptionList arg0, MC_ActionDescriptionList arg1) {
  return (MC_ActionDescriptionList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
MC_ActionDescriptionList MC_sliceActionDescriptionList(MC_ActionDescriptionList arg, int start, int end) {
  return (MC_ActionDescriptionList) ATgetSlice((ATermList) arg, start, end);
}
MC_ActionDescription MC_getActionDescriptionListActionDescriptionAt(MC_ActionDescriptionList arg, int index) {
 return (MC_ActionDescription)ATelementAt((ATermList) arg,index);
}
MC_ActionDescriptionList MC_replaceActionDescriptionListActionDescriptionAt(MC_ActionDescriptionList arg, MC_ActionDescription elem, int index) {
 return (MC_ActionDescriptionList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
MC_ActionDescriptionList MC_makeActionDescriptionList2(MC_ActionDescription elem1, MC_ActionDescription elem2) {
  return (MC_ActionDescriptionList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
MC_ActionDescriptionList MC_makeActionDescriptionList3(MC_ActionDescription elem1, MC_ActionDescription elem2, MC_ActionDescription elem3) {
  return (MC_ActionDescriptionList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
MC_ActionDescriptionList MC_makeActionDescriptionList4(MC_ActionDescription elem1, MC_ActionDescription elem2, MC_ActionDescription elem3, MC_ActionDescription elem4) {
  return (MC_ActionDescriptionList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
MC_ActionDescriptionList MC_makeActionDescriptionList5(MC_ActionDescription elem1, MC_ActionDescription elem2, MC_ActionDescription elem3, MC_ActionDescription elem4, MC_ActionDescription elem5) {
  return (MC_ActionDescriptionList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
MC_ActionDescriptionList MC_makeActionDescriptionList6(MC_ActionDescription elem1, MC_ActionDescription elem2, MC_ActionDescription elem3, MC_ActionDescription elem4, MC_ActionDescription elem5, MC_ActionDescription elem6) {
  return (MC_ActionDescriptionList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int MC_getItemsLength (MC_Items arg) {
  return ATgetLength((ATermList) arg);
}
MC_Items MC_reverseItems(MC_Items arg) {
  return (MC_Items) ATreverse((ATermList) arg);
}
MC_Items MC_appendItems(MC_Items arg, char* elem) {
  return (MC_Items) ATappend((ATermList) arg, (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem, 0, ATtrue))));
}
MC_Items MC_concatItems(MC_Items arg0, MC_Items arg1) {
  return (MC_Items) ATconcat((ATermList) arg0, (ATermList) arg1);
}
MC_Items MC_sliceItems(MC_Items arg, int start, int end) {
  return (MC_Items) ATgetSlice((ATermList) arg, start, end);
}
char* MC_getItemsstrAt(MC_Items arg, int index) {
 return (char*)ATgetName(ATgetAFun((ATermAppl) ATelementAt((ATermList) arg,index)));
}
MC_Items MC_replaceItemsstrAt(MC_Items arg, char* elem, int index) {
 return (MC_Items) ATreplace((ATermList) arg, (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem, 0, ATtrue))), index);
}
MC_Items MC_makeItems2(char* elem1, char* elem2) {
  return (MC_Items) ATmakeList2((ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem2, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem2, 0, ATtrue))));
}
MC_Items MC_makeItems3(char* elem1, char* elem2, char* elem3) {
  return (MC_Items) ATmakeList3((ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem3, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem3, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem3, 0, ATtrue))));
}
MC_Items MC_makeItems4(char* elem1, char* elem2, char* elem3, char* elem4) {
  return (MC_Items) ATmakeList4((ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem4, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem4, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem4, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem4, 0, ATtrue))));
}
MC_Items MC_makeItems5(char* elem1, char* elem2, char* elem3, char* elem4, char* elem5) {
  return (MC_Items) ATmakeList5((ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem5, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem5, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem5, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem5, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem5, 0, ATtrue))));
}
MC_Items MC_makeItems6(char* elem1, char* elem2, char* elem3, char* elem4, char* elem5, char* elem6) {
  return (MC_Items) ATmakeList6((ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))));
}
int MC_getTextAttributesLength (MC_TextAttributes arg) {
  return ATgetLength((ATermList) arg);
}
MC_TextAttributes MC_reverseTextAttributes(MC_TextAttributes arg) {
  return (MC_TextAttributes) ATreverse((ATermList) arg);
}
MC_TextAttributes MC_appendTextAttributes(MC_TextAttributes arg, MC_TextAttribute elem) {
  return (MC_TextAttributes) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
MC_TextAttributes MC_concatTextAttributes(MC_TextAttributes arg0, MC_TextAttributes arg1) {
  return (MC_TextAttributes) ATconcat((ATermList) arg0, (ATermList) arg1);
}
MC_TextAttributes MC_sliceTextAttributes(MC_TextAttributes arg, int start, int end) {
  return (MC_TextAttributes) ATgetSlice((ATermList) arg, start, end);
}
MC_TextAttribute MC_getTextAttributesTextAttributeAt(MC_TextAttributes arg, int index) {
 return (MC_TextAttribute)ATelementAt((ATermList) arg,index);
}
MC_TextAttributes MC_replaceTextAttributesTextAttributeAt(MC_TextAttributes arg, MC_TextAttribute elem, int index) {
 return (MC_TextAttributes) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
MC_TextAttributes MC_makeTextAttributes2(MC_TextAttribute elem1, MC_TextAttribute elem2) {
  return (MC_TextAttributes) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
MC_TextAttributes MC_makeTextAttributes3(MC_TextAttribute elem1, MC_TextAttribute elem2, MC_TextAttribute elem3) {
  return (MC_TextAttributes) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
MC_TextAttributes MC_makeTextAttributes4(MC_TextAttribute elem1, MC_TextAttribute elem2, MC_TextAttribute elem3, MC_TextAttribute elem4) {
  return (MC_TextAttributes) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
MC_TextAttributes MC_makeTextAttributes5(MC_TextAttribute elem1, MC_TextAttribute elem2, MC_TextAttribute elem3, MC_TextAttribute elem4, MC_TextAttribute elem5) {
  return (MC_TextAttributes) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
MC_TextAttributes MC_makeTextAttributes6(MC_TextAttribute elem1, MC_TextAttribute elem2, MC_TextAttribute elem3, MC_TextAttribute elem4, MC_TextAttribute elem5, MC_TextAttribute elem6) {
  return (MC_TextAttributes) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  MC_Configuration MC_makeConfigurationList(MC_Properties list) */

MC_Configuration MC_makeConfigurationList(MC_Properties list)
{
  return (MC_Configuration)(ATerm)ATmakeAppl1(MC_afun0, (ATerm) list);
}

/*}}}  */
/*{{{  MC_Properties MC_makePropertiesEmpty(void) */

MC_Properties MC_makePropertiesEmpty(void)
{
  return (MC_Properties)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MC_Properties MC_makePropertiesSingle(MC_Property head) */

MC_Properties MC_makePropertiesSingle(MC_Property head)
{
  return (MC_Properties)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  MC_Properties MC_makePropertiesMany(MC_Property head, MC_Properties tail) */

MC_Properties MC_makePropertiesMany(MC_Property head, MC_Properties tail)
{
  return (MC_Properties)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  MC_Property MC_makePropertyAction(MC_ActionDescriptionList descriptions, const char* action) */

MC_Property MC_makePropertyAction(MC_ActionDescriptionList descriptions, const char* action)
{
  return (MC_Property)(ATerm)ATmakeAppl2(MC_afun1, (ATerm) descriptions, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(action, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_Property MC_makePropertyExtension(const char* language, const char* extension) */

MC_Property MC_makePropertyExtension(const char* language, const char* extension)
{
  return (MC_Property)(ATerm)ATmakeAppl2(MC_afun2, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(language, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(extension, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_Property MC_makePropertyLibraryPath(const char* path) */

MC_Property MC_makePropertyLibraryPath(const char* path)
{
  return (MC_Property)(ATerm)ATmakeAppl1(MC_afun3, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_Property MC_makePropertyModulePath(const char* path) */

MC_Property MC_makePropertyModulePath(const char* path)
{
  return (MC_Property)(ATerm)ATmakeAppl1(MC_afun4, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_Property MC_makePropertyTextCategory(MC_TextCategoryName category, MC_TextAttributes attributes) */

MC_Property MC_makePropertyTextCategory(MC_TextCategoryName category, MC_TextAttributes attributes)
{
  return (MC_Property)(ATerm)ATmakeAppl2(MC_afun5, (ATerm) category, (ATerm) attributes);
}

/*}}}  */
/*{{{  MC_ActionDescription MC_makeActionDescriptionDefault(MC_ActionType actionType, MC_Event event) */

MC_ActionDescription MC_makeActionDescriptionDefault(MC_ActionType actionType, MC_Event event)
{
  return (MC_ActionDescription)(ATerm)ATmakeAppl2(MC_afun6, (ATerm) actionType, (ATerm) event);
}

/*}}}  */
/*{{{  MC_ActionDescriptionList MC_makeActionDescriptionListEmpty(void) */

MC_ActionDescriptionList MC_makeActionDescriptionListEmpty(void)
{
  return (MC_ActionDescriptionList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MC_ActionDescriptionList MC_makeActionDescriptionListSingle(MC_ActionDescription head) */

MC_ActionDescriptionList MC_makeActionDescriptionListSingle(MC_ActionDescription head)
{
  return (MC_ActionDescriptionList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  MC_ActionDescriptionList MC_makeActionDescriptionListMany(MC_ActionDescription head, MC_ActionDescriptionList tail) */

MC_ActionDescriptionList MC_makeActionDescriptionListMany(MC_ActionDescription head, MC_ActionDescriptionList tail)
{
  return (MC_ActionDescriptionList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeTermEditor(void) */

MC_ActionType MC_makeActionTypeTermEditor(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun7);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeTermEditorForModule(const char* moduleId) */

MC_ActionType MC_makeActionTypeTermEditorForModule(const char* moduleId)
{
  return (MC_ActionType)(ATerm)ATmakeAppl1(MC_afun8, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(moduleId, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeEquationsEditor(void) */

MC_ActionType MC_makeActionTypeEquationsEditor(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun9);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeSyntaxEditor(void) */

MC_ActionType MC_makeActionTypeSyntaxEditor(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun10);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeFeedbackList(void) */

MC_ActionType MC_makeActionTypeFeedbackList(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun11);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeTreePanel(void) */

MC_ActionType MC_makeActionTypeTreePanel(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun12);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeModulePopup(const char* moduleId) */

MC_ActionType MC_makeActionTypeModulePopup(const char* moduleId)
{
  return (MC_ActionType)(ATerm)ATmakeAppl1(MC_afun13, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(moduleId, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeNewModulePopup(void) */

MC_ActionType MC_makeActionTypeNewModulePopup(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun14);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeStudioMenubar(void) */

MC_ActionType MC_makeActionTypeStudioMenubar(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun15);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeStudioToolbar(void) */

MC_ActionType MC_makeActionTypeStudioToolbar(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun16);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeWildcard(void) */

MC_ActionType MC_makeActionTypeWildcard(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun17);
}

/*}}}  */
/*{{{  MC_Event MC_makeEventClick(void) */

MC_Event MC_makeEventClick(void)
{
  return (MC_Event)(ATerm)ATmakeAppl0(MC_afun18);
}

/*}}}  */
/*{{{  MC_Event MC_makeEventIcon(const char* title, const char* path) */

MC_Event MC_makeEventIcon(const char* title, const char* path)
{
  return (MC_Event)(ATerm)ATmakeAppl2(MC_afun19, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(title, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_Event MC_makeEventDefault(MC_Items items) */

MC_Event MC_makeEventDefault(MC_Items items)
{
  return (MC_Event)(ATerm)ATmakeAppl1(MC_afun20, (ATerm) items);
}

/*}}}  */
/*{{{  MC_Event MC_makeEventShortcut(MC_Items items, const char* shortcut) */

MC_Event MC_makeEventShortcut(MC_Items items, const char* shortcut)
{
  return (MC_Event)(ATerm)ATmakeAppl2(MC_afun21, (ATerm) items, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(shortcut, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_Items MC_makeItemsEmpty(void) */

MC_Items MC_makeItemsEmpty(void)
{
  return (MC_Items)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MC_Items MC_makeItemsSingle(const char* head) */

MC_Items MC_makeItemsSingle(const char* head)
{
  return (MC_Items)(ATerm)ATmakeList1((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(head, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_Items MC_makeItemsMany(const char* head, MC_Items tail) */

MC_Items MC_makeItemsMany(const char* head, MC_Items tail)
{
  return (MC_Items)(ATerm)ATinsert((ATermList)tail, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(head, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_ModuleName MC_makeModuleNameWildcard(void) */

MC_ModuleName MC_makeModuleNameWildcard(void)
{
  return (MC_ModuleName)(ATerm)ATmakeAppl0(MC_afun17);
}

/*}}}  */
/*{{{  MC_TextCategoryName MC_makeTextCategoryNameFocus(void) */

MC_TextCategoryName MC_makeTextCategoryNameFocus(void)
{
  return (MC_TextCategoryName)(ATerm)ATmakeAppl0(MC_afun22);
}

/*}}}  */
/*{{{  MC_TextCategoryName MC_makeTextCategoryNameSelection(void) */

MC_TextCategoryName MC_makeTextCategoryNameSelection(void)
{
  return (MC_TextCategoryName)(ATerm)ATmakeAppl0(MC_afun23);
}

/*}}}  */
/*{{{  MC_TextCategoryName MC_makeTextCategoryNameNormal(void) */

MC_TextCategoryName MC_makeTextCategoryNameNormal(void)
{
  return (MC_TextCategoryName)(ATerm)ATmakeAppl0(MC_afun24);
}

/*}}}  */
/*{{{  MC_TextCategoryName MC_makeTextCategoryNameExtern(const char* name) */

MC_TextCategoryName MC_makeTextCategoryNameExtern(const char* name)
{
  return (MC_TextCategoryName)(ATerm)ATmakeAppl1(MC_afun25, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_TextAttributes MC_makeTextAttributesEmpty(void) */

MC_TextAttributes MC_makeTextAttributesEmpty(void)
{
  return (MC_TextAttributes)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MC_TextAttributes MC_makeTextAttributesSingle(MC_TextAttribute head) */

MC_TextAttributes MC_makeTextAttributesSingle(MC_TextAttribute head)
{
  return (MC_TextAttributes)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  MC_TextAttributes MC_makeTextAttributesMany(MC_TextAttribute head, MC_TextAttributes tail) */

MC_TextAttributes MC_makeTextAttributesMany(MC_TextAttribute head, MC_TextAttributes tail)
{
  return (MC_TextAttributes)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  MC_TextAttribute MC_makeTextAttributeForegroundColor(MC_Color color) */

MC_TextAttribute MC_makeTextAttributeForegroundColor(MC_Color color)
{
  return (MC_TextAttribute)(ATerm)ATmakeAppl1(MC_afun26, (ATerm) color);
}

/*}}}  */
/*{{{  MC_TextAttribute MC_makeTextAttributeBackgroundColor(MC_Color color) */

MC_TextAttribute MC_makeTextAttributeBackgroundColor(MC_Color color)
{
  return (MC_TextAttribute)(ATerm)ATmakeAppl1(MC_afun27, (ATerm) color);
}

/*}}}  */
/*{{{  MC_TextAttribute MC_makeTextAttributeStyle(MC_TextStyle style) */

MC_TextAttribute MC_makeTextAttributeStyle(MC_TextStyle style)
{
  return (MC_TextAttribute)(ATerm)ATmakeAppl1(MC_afun28, (ATerm) style);
}

/*}}}  */
/*{{{  MC_TextAttribute MC_makeTextAttributeFont(const char* name) */

MC_TextAttribute MC_makeTextAttributeFont(const char* name)
{
  return (MC_TextAttribute)(ATerm)ATmakeAppl1(MC_afun29, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_TextAttribute MC_makeTextAttributeSize(int points) */

MC_TextAttribute MC_makeTextAttributeSize(int points)
{
  return (MC_TextAttribute)(ATerm)ATmakeAppl1(MC_afun30, (ATerm) (ATerm) ATmakeInt(points));
}

/*}}}  */
/*{{{  MC_TextStyle MC_makeTextStyleBold(void) */

MC_TextStyle MC_makeTextStyleBold(void)
{
  return (MC_TextStyle)(ATerm)ATmakeAppl0(MC_afun31);
}

/*}}}  */
/*{{{  MC_TextStyle MC_makeTextStyleItalics(void) */

MC_TextStyle MC_makeTextStyleItalics(void)
{
  return (MC_TextStyle)(ATerm)ATmakeAppl0(MC_afun32);
}

/*}}}  */
/*{{{  MC_TextStyle MC_makeTextStyleUnderlined(void) */

MC_TextStyle MC_makeTextStyleUnderlined(void)
{
  return (MC_TextStyle)(ATerm)ATmakeAppl0(MC_afun33);
}

/*}}}  */
/*{{{  MC_Color MC_makeColorRgb(int red, int green, int blue) */

MC_Color MC_makeColorRgb(int red, int green, int blue)
{
  return (MC_Color)(ATerm)ATmakeAppl3(MC_afun34, (ATerm) (ATerm) ATmakeInt(red), (ATerm) (ATerm) ATmakeInt(green), (ATerm) (ATerm) ATmakeInt(blue));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool MC_isEqualConfiguration(MC_Configuration arg0, MC_Configuration arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualProperties(MC_Properties arg0, MC_Properties arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualProperty(MC_Property arg0, MC_Property arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualActionDescription(MC_ActionDescription arg0, MC_ActionDescription arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualActionDescriptionList(MC_ActionDescriptionList arg0, MC_ActionDescriptionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualActionType(MC_ActionType arg0, MC_ActionType arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualEvent(MC_Event arg0, MC_Event arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualItems(MC_Items arg0, MC_Items arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualModuleName(MC_ModuleName arg0, MC_ModuleName arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualTextCategoryName(MC_TextCategoryName arg0, MC_TextCategoryName arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualTextAttributes(MC_TextAttributes arg0, MC_TextAttributes arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualTextAttribute(MC_TextAttribute arg0, MC_TextAttribute arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualTextStyle(MC_TextStyle arg0, MC_TextStyle arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualColor(MC_Color arg0, MC_Color arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  MC_Configuration accessors */

/*{{{  ATbool MC_isValidConfiguration(MC_Configuration arg) */

ATbool MC_isValidConfiguration(MC_Configuration arg)
{
  if (MC_isConfigurationList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isConfigurationList(MC_Configuration arg) */

inline ATbool MC_isConfigurationList(MC_Configuration arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MC_patternConfigurationList, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MC_hasConfigurationList(MC_Configuration arg) */

ATbool MC_hasConfigurationList(MC_Configuration arg)
{
  if (MC_isConfigurationList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_Properties MC_getConfigurationList(MC_Configuration arg) */

MC_Properties MC_getConfigurationList(MC_Configuration arg)
{
  
    return (MC_Properties)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  MC_Configuration MC_setConfigurationList(MC_Configuration arg, MC_Properties list) */

MC_Configuration MC_setConfigurationList(MC_Configuration arg, MC_Properties list)
{
  if (MC_isConfigurationList(arg)) {
    return (MC_Configuration)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }

  ATabort("Configuration has no List: %t\n", arg);
  return (MC_Configuration)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MC_Properties accessors */

/*{{{  ATbool MC_isValidProperties(MC_Properties arg) */

ATbool MC_isValidProperties(MC_Properties arg)
{
  if (MC_isPropertiesEmpty(arg)) {
    return ATtrue;
  }
  else if (MC_isPropertiesSingle(arg)) {
    return ATtrue;
  }
  else if (MC_isPropertiesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isPropertiesEmpty(MC_Properties arg) */

inline ATbool MC_isPropertiesEmpty(MC_Properties arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MC_patternPropertiesEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MC_isPropertiesSingle(MC_Properties arg) */

inline ATbool MC_isPropertiesSingle(MC_Properties arg)
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
      last_result = ATmatchTerm((ATerm)arg, MC_patternPropertiesSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isPropertiesMany(MC_Properties arg) */

inline ATbool MC_isPropertiesMany(MC_Properties arg)
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
      last_result = ATmatchTerm((ATerm)arg, MC_patternPropertiesMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MC_hasPropertiesHead(MC_Properties arg) */

ATbool MC_hasPropertiesHead(MC_Properties arg)
{
  if (MC_isPropertiesSingle(arg)) {
    return ATtrue;
  }
  else if (MC_isPropertiesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasPropertiesTail(MC_Properties arg) */

ATbool MC_hasPropertiesTail(MC_Properties arg)
{
  if (MC_isPropertiesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_Property MC_getPropertiesHead(MC_Properties arg) */

MC_Property MC_getPropertiesHead(MC_Properties arg)
{
  if (MC_isPropertiesSingle(arg)) {
    return (MC_Property)ATgetFirst((ATermList)arg);
  }
  else 
    return (MC_Property)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MC_Properties MC_getPropertiesTail(MC_Properties arg) */

MC_Properties MC_getPropertiesTail(MC_Properties arg)
{
  
    return (MC_Properties)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  MC_Properties MC_setPropertiesHead(MC_Properties arg, MC_Property head) */

MC_Properties MC_setPropertiesHead(MC_Properties arg, MC_Property head)
{
  if (MC_isPropertiesSingle(arg)) {
    return (MC_Properties)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (MC_isPropertiesMany(arg)) {
    return (MC_Properties)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Properties has no Head: %t\n", arg);
  return (MC_Properties)NULL;
}

/*}}}  */
/*{{{  MC_Properties MC_setPropertiesTail(MC_Properties arg, MC_Properties tail) */

MC_Properties MC_setPropertiesTail(MC_Properties arg, MC_Properties tail)
{
  if (MC_isPropertiesMany(arg)) {
    return (MC_Properties)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Properties has no Tail: %t\n", arg);
  return (MC_Properties)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MC_Property accessors */

/*{{{  ATbool MC_isValidProperty(MC_Property arg) */

ATbool MC_isValidProperty(MC_Property arg)
{
  if (MC_isPropertyAction(arg)) {
    return ATtrue;
  }
  else if (MC_isPropertyExtension(arg)) {
    return ATtrue;
  }
  else if (MC_isPropertyLibraryPath(arg)) {
    return ATtrue;
  }
  else if (MC_isPropertyModulePath(arg)) {
    return ATtrue;
  }
  else if (MC_isPropertyTextCategory(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isPropertyAction(MC_Property arg) */

inline ATbool MC_isPropertyAction(MC_Property arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternPropertyAction, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isPropertyExtension(MC_Property arg) */

inline ATbool MC_isPropertyExtension(MC_Property arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternPropertyExtension, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isPropertyLibraryPath(MC_Property arg) */

inline ATbool MC_isPropertyLibraryPath(MC_Property arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternPropertyLibraryPath, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isPropertyModulePath(MC_Property arg) */

inline ATbool MC_isPropertyModulePath(MC_Property arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternPropertyModulePath, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isPropertyTextCategory(MC_Property arg) */

inline ATbool MC_isPropertyTextCategory(MC_Property arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternPropertyTextCategory, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MC_hasPropertyDescriptions(MC_Property arg) */

ATbool MC_hasPropertyDescriptions(MC_Property arg)
{
  if (MC_isPropertyAction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasPropertyAction(MC_Property arg) */

ATbool MC_hasPropertyAction(MC_Property arg)
{
  if (MC_isPropertyAction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasPropertyLanguage(MC_Property arg) */

ATbool MC_hasPropertyLanguage(MC_Property arg)
{
  if (MC_isPropertyExtension(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasPropertyExtension(MC_Property arg) */

ATbool MC_hasPropertyExtension(MC_Property arg)
{
  if (MC_isPropertyExtension(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasPropertyPath(MC_Property arg) */

ATbool MC_hasPropertyPath(MC_Property arg)
{
  if (MC_isPropertyLibraryPath(arg)) {
    return ATtrue;
  }
  else if (MC_isPropertyModulePath(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasPropertyCategory(MC_Property arg) */

ATbool MC_hasPropertyCategory(MC_Property arg)
{
  if (MC_isPropertyTextCategory(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasPropertyAttributes(MC_Property arg) */

ATbool MC_hasPropertyAttributes(MC_Property arg)
{
  if (MC_isPropertyTextCategory(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_ActionDescriptionList MC_getPropertyDescriptions(MC_Property arg) */

MC_ActionDescriptionList MC_getPropertyDescriptions(MC_Property arg)
{
  
    return (MC_ActionDescriptionList)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  char* MC_getPropertyAction(MC_Property arg) */

char* MC_getPropertyAction(MC_Property arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  char* MC_getPropertyLanguage(MC_Property arg) */

char* MC_getPropertyLanguage(MC_Property arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  char* MC_getPropertyExtension(MC_Property arg) */

char* MC_getPropertyExtension(MC_Property arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  char* MC_getPropertyPath(MC_Property arg) */

char* MC_getPropertyPath(MC_Property arg)
{
  if (MC_isPropertyLibraryPath(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  MC_TextCategoryName MC_getPropertyCategory(MC_Property arg) */

MC_TextCategoryName MC_getPropertyCategory(MC_Property arg)
{
  
    return (MC_TextCategoryName)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  MC_TextAttributes MC_getPropertyAttributes(MC_Property arg) */

MC_TextAttributes MC_getPropertyAttributes(MC_Property arg)
{
  
    return (MC_TextAttributes)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  MC_Property MC_setPropertyDescriptions(MC_Property arg, MC_ActionDescriptionList descriptions) */

MC_Property MC_setPropertyDescriptions(MC_Property arg, MC_ActionDescriptionList descriptions)
{
  if (MC_isPropertyAction(arg)) {
    return (MC_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) descriptions), 0);
  }

  ATabort("Property has no Descriptions: %t\n", arg);
  return (MC_Property)NULL;
}

/*}}}  */
/*{{{  MC_Property MC_setPropertyAction(MC_Property arg, const char* action) */

MC_Property MC_setPropertyAction(MC_Property arg, const char* action)
{
  if (MC_isPropertyAction(arg)) {
    return (MC_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(action, 0, ATtrue))), 1);
  }

  ATabort("Property has no Action: %t\n", arg);
  return (MC_Property)NULL;
}

/*}}}  */
/*{{{  MC_Property MC_setPropertyLanguage(MC_Property arg, const char* language) */

MC_Property MC_setPropertyLanguage(MC_Property arg, const char* language)
{
  if (MC_isPropertyExtension(arg)) {
    return (MC_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(language, 0, ATtrue))), 0);
  }

  ATabort("Property has no Language: %t\n", arg);
  return (MC_Property)NULL;
}

/*}}}  */
/*{{{  MC_Property MC_setPropertyExtension(MC_Property arg, const char* extension) */

MC_Property MC_setPropertyExtension(MC_Property arg, const char* extension)
{
  if (MC_isPropertyExtension(arg)) {
    return (MC_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(extension, 0, ATtrue))), 1);
  }

  ATabort("Property has no Extension: %t\n", arg);
  return (MC_Property)NULL;
}

/*}}}  */
/*{{{  MC_Property MC_setPropertyPath(MC_Property arg, const char* path) */

MC_Property MC_setPropertyPath(MC_Property arg, const char* path)
{
  if (MC_isPropertyLibraryPath(arg)) {
    return (MC_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 0);
  }
  else if (MC_isPropertyModulePath(arg)) {
    return (MC_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 0);
  }

  ATabort("Property has no Path: %t\n", arg);
  return (MC_Property)NULL;
}

/*}}}  */
/*{{{  MC_Property MC_setPropertyCategory(MC_Property arg, MC_TextCategoryName category) */

MC_Property MC_setPropertyCategory(MC_Property arg, MC_TextCategoryName category)
{
  if (MC_isPropertyTextCategory(arg)) {
    return (MC_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) category), 0);
  }

  ATabort("Property has no Category: %t\n", arg);
  return (MC_Property)NULL;
}

/*}}}  */
/*{{{  MC_Property MC_setPropertyAttributes(MC_Property arg, MC_TextAttributes attributes) */

MC_Property MC_setPropertyAttributes(MC_Property arg, MC_TextAttributes attributes)
{
  if (MC_isPropertyTextCategory(arg)) {
    return (MC_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) attributes), 1);
  }

  ATabort("Property has no Attributes: %t\n", arg);
  return (MC_Property)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MC_ActionDescription accessors */

/*{{{  ATbool MC_isValidActionDescription(MC_ActionDescription arg) */

ATbool MC_isValidActionDescription(MC_ActionDescription arg)
{
  if (MC_isActionDescriptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isActionDescriptionDefault(MC_ActionDescription arg) */

inline ATbool MC_isActionDescriptionDefault(MC_ActionDescription arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MC_patternActionDescriptionDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MC_hasActionDescriptionActionType(MC_ActionDescription arg) */

ATbool MC_hasActionDescriptionActionType(MC_ActionDescription arg)
{
  if (MC_isActionDescriptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasActionDescriptionEvent(MC_ActionDescription arg) */

ATbool MC_hasActionDescriptionEvent(MC_ActionDescription arg)
{
  if (MC_isActionDescriptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_ActionType MC_getActionDescriptionActionType(MC_ActionDescription arg) */

MC_ActionType MC_getActionDescriptionActionType(MC_ActionDescription arg)
{
  
    return (MC_ActionType)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  MC_Event MC_getActionDescriptionEvent(MC_ActionDescription arg) */

MC_Event MC_getActionDescriptionEvent(MC_ActionDescription arg)
{
  
    return (MC_Event)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  MC_ActionDescription MC_setActionDescriptionActionType(MC_ActionDescription arg, MC_ActionType actionType) */

MC_ActionDescription MC_setActionDescriptionActionType(MC_ActionDescription arg, MC_ActionType actionType)
{
  if (MC_isActionDescriptionDefault(arg)) {
    return (MC_ActionDescription)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) actionType), 0);
  }

  ATabort("ActionDescription has no ActionType: %t\n", arg);
  return (MC_ActionDescription)NULL;
}

/*}}}  */
/*{{{  MC_ActionDescription MC_setActionDescriptionEvent(MC_ActionDescription arg, MC_Event event) */

MC_ActionDescription MC_setActionDescriptionEvent(MC_ActionDescription arg, MC_Event event)
{
  if (MC_isActionDescriptionDefault(arg)) {
    return (MC_ActionDescription)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) event), 1);
  }

  ATabort("ActionDescription has no Event: %t\n", arg);
  return (MC_ActionDescription)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MC_ActionDescriptionList accessors */

/*{{{  ATbool MC_isValidActionDescriptionList(MC_ActionDescriptionList arg) */

ATbool MC_isValidActionDescriptionList(MC_ActionDescriptionList arg)
{
  if (MC_isActionDescriptionListEmpty(arg)) {
    return ATtrue;
  }
  else if (MC_isActionDescriptionListSingle(arg)) {
    return ATtrue;
  }
  else if (MC_isActionDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isActionDescriptionListEmpty(MC_ActionDescriptionList arg) */

inline ATbool MC_isActionDescriptionListEmpty(MC_ActionDescriptionList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MC_patternActionDescriptionListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MC_isActionDescriptionListSingle(MC_ActionDescriptionList arg) */

inline ATbool MC_isActionDescriptionListSingle(MC_ActionDescriptionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, MC_patternActionDescriptionListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isActionDescriptionListMany(MC_ActionDescriptionList arg) */

inline ATbool MC_isActionDescriptionListMany(MC_ActionDescriptionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, MC_patternActionDescriptionListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MC_hasActionDescriptionListHead(MC_ActionDescriptionList arg) */

ATbool MC_hasActionDescriptionListHead(MC_ActionDescriptionList arg)
{
  if (MC_isActionDescriptionListSingle(arg)) {
    return ATtrue;
  }
  else if (MC_isActionDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasActionDescriptionListTail(MC_ActionDescriptionList arg) */

ATbool MC_hasActionDescriptionListTail(MC_ActionDescriptionList arg)
{
  if (MC_isActionDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_ActionDescription MC_getActionDescriptionListHead(MC_ActionDescriptionList arg) */

MC_ActionDescription MC_getActionDescriptionListHead(MC_ActionDescriptionList arg)
{
  if (MC_isActionDescriptionListSingle(arg)) {
    return (MC_ActionDescription)ATgetFirst((ATermList)arg);
  }
  else 
    return (MC_ActionDescription)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MC_ActionDescriptionList MC_getActionDescriptionListTail(MC_ActionDescriptionList arg) */

MC_ActionDescriptionList MC_getActionDescriptionListTail(MC_ActionDescriptionList arg)
{
  
    return (MC_ActionDescriptionList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  MC_ActionDescriptionList MC_setActionDescriptionListHead(MC_ActionDescriptionList arg, MC_ActionDescription head) */

MC_ActionDescriptionList MC_setActionDescriptionListHead(MC_ActionDescriptionList arg, MC_ActionDescription head)
{
  if (MC_isActionDescriptionListSingle(arg)) {
    return (MC_ActionDescriptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (MC_isActionDescriptionListMany(arg)) {
    return (MC_ActionDescriptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ActionDescriptionList has no Head: %t\n", arg);
  return (MC_ActionDescriptionList)NULL;
}

/*}}}  */
/*{{{  MC_ActionDescriptionList MC_setActionDescriptionListTail(MC_ActionDescriptionList arg, MC_ActionDescriptionList tail) */

MC_ActionDescriptionList MC_setActionDescriptionListTail(MC_ActionDescriptionList arg, MC_ActionDescriptionList tail)
{
  if (MC_isActionDescriptionListMany(arg)) {
    return (MC_ActionDescriptionList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("ActionDescriptionList has no Tail: %t\n", arg);
  return (MC_ActionDescriptionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MC_ActionType accessors */

/*{{{  ATbool MC_isValidActionType(MC_ActionType arg) */

ATbool MC_isValidActionType(MC_ActionType arg)
{
  if (MC_isActionTypeTermEditor(arg)) {
    return ATtrue;
  }
  else if (MC_isActionTypeTermEditorForModule(arg)) {
    return ATtrue;
  }
  else if (MC_isActionTypeEquationsEditor(arg)) {
    return ATtrue;
  }
  else if (MC_isActionTypeSyntaxEditor(arg)) {
    return ATtrue;
  }
  else if (MC_isActionTypeFeedbackList(arg)) {
    return ATtrue;
  }
  else if (MC_isActionTypeTreePanel(arg)) {
    return ATtrue;
  }
  else if (MC_isActionTypeModulePopup(arg)) {
    return ATtrue;
  }
  else if (MC_isActionTypeNewModulePopup(arg)) {
    return ATtrue;
  }
  else if (MC_isActionTypeStudioMenubar(arg)) {
    return ATtrue;
  }
  else if (MC_isActionTypeStudioToolbar(arg)) {
    return ATtrue;
  }
  else if (MC_isActionTypeWildcard(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isActionTypeTermEditor(MC_ActionType arg) */

inline ATbool MC_isActionTypeTermEditor(MC_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternActionTypeTermEditor);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isActionTypeTermEditorForModule(MC_ActionType arg) */

inline ATbool MC_isActionTypeTermEditorForModule(MC_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternActionTypeTermEditorForModule, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isActionTypeEquationsEditor(MC_ActionType arg) */

inline ATbool MC_isActionTypeEquationsEditor(MC_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternActionTypeEquationsEditor);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isActionTypeSyntaxEditor(MC_ActionType arg) */

inline ATbool MC_isActionTypeSyntaxEditor(MC_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternActionTypeSyntaxEditor);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isActionTypeFeedbackList(MC_ActionType arg) */

inline ATbool MC_isActionTypeFeedbackList(MC_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternActionTypeFeedbackList);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isActionTypeTreePanel(MC_ActionType arg) */

inline ATbool MC_isActionTypeTreePanel(MC_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternActionTypeTreePanel);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isActionTypeModulePopup(MC_ActionType arg) */

inline ATbool MC_isActionTypeModulePopup(MC_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternActionTypeModulePopup, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isActionTypeNewModulePopup(MC_ActionType arg) */

inline ATbool MC_isActionTypeNewModulePopup(MC_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternActionTypeNewModulePopup);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isActionTypeStudioMenubar(MC_ActionType arg) */

inline ATbool MC_isActionTypeStudioMenubar(MC_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternActionTypeStudioMenubar);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isActionTypeStudioToolbar(MC_ActionType arg) */

inline ATbool MC_isActionTypeStudioToolbar(MC_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternActionTypeStudioToolbar);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isActionTypeWildcard(MC_ActionType arg) */

inline ATbool MC_isActionTypeWildcard(MC_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternActionTypeWildcard);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MC_hasActionTypeModuleId(MC_ActionType arg) */

ATbool MC_hasActionTypeModuleId(MC_ActionType arg)
{
  if (MC_isActionTypeTermEditorForModule(arg)) {
    return ATtrue;
  }
  else if (MC_isActionTypeModulePopup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MC_getActionTypeModuleId(MC_ActionType arg) */

char* MC_getActionTypeModuleId(MC_ActionType arg)
{
  if (MC_isActionTypeTermEditorForModule(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  MC_ActionType MC_setActionTypeModuleId(MC_ActionType arg, const char* moduleId) */

MC_ActionType MC_setActionTypeModuleId(MC_ActionType arg, const char* moduleId)
{
  if (MC_isActionTypeTermEditorForModule(arg)) {
    return (MC_ActionType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(moduleId, 0, ATtrue))), 0);
  }
  else if (MC_isActionTypeModulePopup(arg)) {
    return (MC_ActionType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(moduleId, 0, ATtrue))), 0);
  }

  ATabort("ActionType has no ModuleId: %t\n", arg);
  return (MC_ActionType)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MC_Event accessors */

/*{{{  ATbool MC_isValidEvent(MC_Event arg) */

ATbool MC_isValidEvent(MC_Event arg)
{
  if (MC_isEventClick(arg)) {
    return ATtrue;
  }
  else if (MC_isEventIcon(arg)) {
    return ATtrue;
  }
  else if (MC_isEventDefault(arg)) {
    return ATtrue;
  }
  else if (MC_isEventShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isEventClick(MC_Event arg) */

inline ATbool MC_isEventClick(MC_Event arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternEventClick);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isEventIcon(MC_Event arg) */

inline ATbool MC_isEventIcon(MC_Event arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternEventIcon, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isEventDefault(MC_Event arg) */

inline ATbool MC_isEventDefault(MC_Event arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternEventDefault, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isEventShortcut(MC_Event arg) */

inline ATbool MC_isEventShortcut(MC_Event arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternEventShortcut, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MC_hasEventTitle(MC_Event arg) */

ATbool MC_hasEventTitle(MC_Event arg)
{
  if (MC_isEventIcon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasEventPath(MC_Event arg) */

ATbool MC_hasEventPath(MC_Event arg)
{
  if (MC_isEventIcon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasEventItems(MC_Event arg) */

ATbool MC_hasEventItems(MC_Event arg)
{
  if (MC_isEventDefault(arg)) {
    return ATtrue;
  }
  else if (MC_isEventShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasEventShortcut(MC_Event arg) */

ATbool MC_hasEventShortcut(MC_Event arg)
{
  if (MC_isEventShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MC_getEventTitle(MC_Event arg) */

char* MC_getEventTitle(MC_Event arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  char* MC_getEventPath(MC_Event arg) */

char* MC_getEventPath(MC_Event arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  MC_Items MC_getEventItems(MC_Event arg) */

MC_Items MC_getEventItems(MC_Event arg)
{
  if (MC_isEventDefault(arg)) {
    return (MC_Items)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (MC_Items)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  char* MC_getEventShortcut(MC_Event arg) */

char* MC_getEventShortcut(MC_Event arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  MC_Event MC_setEventTitle(MC_Event arg, const char* title) */

MC_Event MC_setEventTitle(MC_Event arg, const char* title)
{
  if (MC_isEventIcon(arg)) {
    return (MC_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(title, 0, ATtrue))), 0);
  }

  ATabort("Event has no Title: %t\n", arg);
  return (MC_Event)NULL;
}

/*}}}  */
/*{{{  MC_Event MC_setEventPath(MC_Event arg, const char* path) */

MC_Event MC_setEventPath(MC_Event arg, const char* path)
{
  if (MC_isEventIcon(arg)) {
    return (MC_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 1);
  }

  ATabort("Event has no Path: %t\n", arg);
  return (MC_Event)NULL;
}

/*}}}  */
/*{{{  MC_Event MC_setEventItems(MC_Event arg, MC_Items items) */

MC_Event MC_setEventItems(MC_Event arg, MC_Items items)
{
  if (MC_isEventDefault(arg)) {
    return (MC_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) items), 0);
  }
  else if (MC_isEventShortcut(arg)) {
    return (MC_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) items), 0);
  }

  ATabort("Event has no Items: %t\n", arg);
  return (MC_Event)NULL;
}

/*}}}  */
/*{{{  MC_Event MC_setEventShortcut(MC_Event arg, const char* shortcut) */

MC_Event MC_setEventShortcut(MC_Event arg, const char* shortcut)
{
  if (MC_isEventShortcut(arg)) {
    return (MC_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(shortcut, 0, ATtrue))), 1);
  }

  ATabort("Event has no Shortcut: %t\n", arg);
  return (MC_Event)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MC_Items accessors */

/*{{{  ATbool MC_isValidItems(MC_Items arg) */

ATbool MC_isValidItems(MC_Items arg)
{
  if (MC_isItemsEmpty(arg)) {
    return ATtrue;
  }
  else if (MC_isItemsSingle(arg)) {
    return ATtrue;
  }
  else if (MC_isItemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isItemsEmpty(MC_Items arg) */

inline ATbool MC_isItemsEmpty(MC_Items arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MC_patternItemsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MC_isItemsSingle(MC_Items arg) */

inline ATbool MC_isItemsSingle(MC_Items arg)
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
      last_result = ATmatchTerm((ATerm)arg, MC_patternItemsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isItemsMany(MC_Items arg) */

inline ATbool MC_isItemsMany(MC_Items arg)
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
      last_result = ATmatchTerm((ATerm)arg, MC_patternItemsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MC_hasItemsHead(MC_Items arg) */

ATbool MC_hasItemsHead(MC_Items arg)
{
  if (MC_isItemsSingle(arg)) {
    return ATtrue;
  }
  else if (MC_isItemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasItemsTail(MC_Items arg) */

ATbool MC_hasItemsTail(MC_Items arg)
{
  if (MC_isItemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MC_getItemsHead(MC_Items arg) */

char* MC_getItemsHead(MC_Items arg)
{
  if (MC_isItemsSingle(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetFirst((ATermList)arg)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetFirst((ATermList)arg)));
}

/*}}}  */
/*{{{  MC_Items MC_getItemsTail(MC_Items arg) */

MC_Items MC_getItemsTail(MC_Items arg)
{
  
    return (MC_Items)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  MC_Items MC_setItemsHead(MC_Items arg, const char* head) */

MC_Items MC_setItemsHead(MC_Items arg, const char* head)
{
  if (MC_isItemsSingle(arg)) {
    return (MC_Items)ATreplace((ATermList)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(head, 0, ATtrue))), 0);
  }
  else if (MC_isItemsMany(arg)) {
    return (MC_Items)ATreplace((ATermList)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(head, 0, ATtrue))), 0);
  }

  ATabort("Items has no Head: %t\n", arg);
  return (MC_Items)NULL;
}

/*}}}  */
/*{{{  MC_Items MC_setItemsTail(MC_Items arg, MC_Items tail) */

MC_Items MC_setItemsTail(MC_Items arg, MC_Items tail)
{
  if (MC_isItemsMany(arg)) {
    return (MC_Items)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Items has no Tail: %t\n", arg);
  return (MC_Items)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MC_ModuleName accessors */

/*{{{  ATbool MC_isValidModuleName(MC_ModuleName arg) */

ATbool MC_isValidModuleName(MC_ModuleName arg)
{
  if (MC_isModuleNameWildcard(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isModuleNameWildcard(MC_ModuleName arg) */

inline ATbool MC_isModuleNameWildcard(MC_ModuleName arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MC_patternModuleNameWildcard));
#endif
  return ATtrue;
}

/*}}}  */

/*}}}  */
/*{{{  MC_TextCategoryName accessors */

/*{{{  ATbool MC_isValidTextCategoryName(MC_TextCategoryName arg) */

ATbool MC_isValidTextCategoryName(MC_TextCategoryName arg)
{
  if (MC_isTextCategoryNameFocus(arg)) {
    return ATtrue;
  }
  else if (MC_isTextCategoryNameSelection(arg)) {
    return ATtrue;
  }
  else if (MC_isTextCategoryNameNormal(arg)) {
    return ATtrue;
  }
  else if (MC_isTextCategoryNameExtern(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isTextCategoryNameFocus(MC_TextCategoryName arg) */

inline ATbool MC_isTextCategoryNameFocus(MC_TextCategoryName arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternTextCategoryNameFocus);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isTextCategoryNameSelection(MC_TextCategoryName arg) */

inline ATbool MC_isTextCategoryNameSelection(MC_TextCategoryName arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternTextCategoryNameSelection);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isTextCategoryNameNormal(MC_TextCategoryName arg) */

inline ATbool MC_isTextCategoryNameNormal(MC_TextCategoryName arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternTextCategoryNameNormal);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isTextCategoryNameExtern(MC_TextCategoryName arg) */

inline ATbool MC_isTextCategoryNameExtern(MC_TextCategoryName arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternTextCategoryNameExtern, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MC_hasTextCategoryNameName(MC_TextCategoryName arg) */

ATbool MC_hasTextCategoryNameName(MC_TextCategoryName arg)
{
  if (MC_isTextCategoryNameExtern(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MC_getTextCategoryNameName(MC_TextCategoryName arg) */

char* MC_getTextCategoryNameName(MC_TextCategoryName arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  MC_TextCategoryName MC_setTextCategoryNameName(MC_TextCategoryName arg, const char* name) */

MC_TextCategoryName MC_setTextCategoryNameName(MC_TextCategoryName arg, const char* name)
{
  if (MC_isTextCategoryNameExtern(arg)) {
    return (MC_TextCategoryName)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("TextCategoryName has no Name: %t\n", arg);
  return (MC_TextCategoryName)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MC_TextAttributes accessors */

/*{{{  ATbool MC_isValidTextAttributes(MC_TextAttributes arg) */

ATbool MC_isValidTextAttributes(MC_TextAttributes arg)
{
  if (MC_isTextAttributesEmpty(arg)) {
    return ATtrue;
  }
  else if (MC_isTextAttributesSingle(arg)) {
    return ATtrue;
  }
  else if (MC_isTextAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isTextAttributesEmpty(MC_TextAttributes arg) */

inline ATbool MC_isTextAttributesEmpty(MC_TextAttributes arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MC_patternTextAttributesEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MC_isTextAttributesSingle(MC_TextAttributes arg) */

inline ATbool MC_isTextAttributesSingle(MC_TextAttributes arg)
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
      last_result = ATmatchTerm((ATerm)arg, MC_patternTextAttributesSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isTextAttributesMany(MC_TextAttributes arg) */

inline ATbool MC_isTextAttributesMany(MC_TextAttributes arg)
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
      last_result = ATmatchTerm((ATerm)arg, MC_patternTextAttributesMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MC_hasTextAttributesHead(MC_TextAttributes arg) */

ATbool MC_hasTextAttributesHead(MC_TextAttributes arg)
{
  if (MC_isTextAttributesSingle(arg)) {
    return ATtrue;
  }
  else if (MC_isTextAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasTextAttributesTail(MC_TextAttributes arg) */

ATbool MC_hasTextAttributesTail(MC_TextAttributes arg)
{
  if (MC_isTextAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_TextAttribute MC_getTextAttributesHead(MC_TextAttributes arg) */

MC_TextAttribute MC_getTextAttributesHead(MC_TextAttributes arg)
{
  if (MC_isTextAttributesSingle(arg)) {
    return (MC_TextAttribute)ATgetFirst((ATermList)arg);
  }
  else 
    return (MC_TextAttribute)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MC_TextAttributes MC_getTextAttributesTail(MC_TextAttributes arg) */

MC_TextAttributes MC_getTextAttributesTail(MC_TextAttributes arg)
{
  
    return (MC_TextAttributes)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  MC_TextAttributes MC_setTextAttributesHead(MC_TextAttributes arg, MC_TextAttribute head) */

MC_TextAttributes MC_setTextAttributesHead(MC_TextAttributes arg, MC_TextAttribute head)
{
  if (MC_isTextAttributesSingle(arg)) {
    return (MC_TextAttributes)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (MC_isTextAttributesMany(arg)) {
    return (MC_TextAttributes)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("TextAttributes has no Head: %t\n", arg);
  return (MC_TextAttributes)NULL;
}

/*}}}  */
/*{{{  MC_TextAttributes MC_setTextAttributesTail(MC_TextAttributes arg, MC_TextAttributes tail) */

MC_TextAttributes MC_setTextAttributesTail(MC_TextAttributes arg, MC_TextAttributes tail)
{
  if (MC_isTextAttributesMany(arg)) {
    return (MC_TextAttributes)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("TextAttributes has no Tail: %t\n", arg);
  return (MC_TextAttributes)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MC_TextAttribute accessors */

/*{{{  ATbool MC_isValidTextAttribute(MC_TextAttribute arg) */

ATbool MC_isValidTextAttribute(MC_TextAttribute arg)
{
  if (MC_isTextAttributeForegroundColor(arg)) {
    return ATtrue;
  }
  else if (MC_isTextAttributeBackgroundColor(arg)) {
    return ATtrue;
  }
  else if (MC_isTextAttributeStyle(arg)) {
    return ATtrue;
  }
  else if (MC_isTextAttributeFont(arg)) {
    return ATtrue;
  }
  else if (MC_isTextAttributeSize(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isTextAttributeForegroundColor(MC_TextAttribute arg) */

inline ATbool MC_isTextAttributeForegroundColor(MC_TextAttribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternTextAttributeForegroundColor, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isTextAttributeBackgroundColor(MC_TextAttribute arg) */

inline ATbool MC_isTextAttributeBackgroundColor(MC_TextAttribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternTextAttributeBackgroundColor, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isTextAttributeStyle(MC_TextAttribute arg) */

inline ATbool MC_isTextAttributeStyle(MC_TextAttribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternTextAttributeStyle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isTextAttributeFont(MC_TextAttribute arg) */

inline ATbool MC_isTextAttributeFont(MC_TextAttribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternTextAttributeFont, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isTextAttributeSize(MC_TextAttribute arg) */

inline ATbool MC_isTextAttributeSize(MC_TextAttribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternTextAttributeSize, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MC_hasTextAttributeColor(MC_TextAttribute arg) */

ATbool MC_hasTextAttributeColor(MC_TextAttribute arg)
{
  if (MC_isTextAttributeForegroundColor(arg)) {
    return ATtrue;
  }
  else if (MC_isTextAttributeBackgroundColor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasTextAttributeStyle(MC_TextAttribute arg) */

ATbool MC_hasTextAttributeStyle(MC_TextAttribute arg)
{
  if (MC_isTextAttributeStyle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasTextAttributeName(MC_TextAttribute arg) */

ATbool MC_hasTextAttributeName(MC_TextAttribute arg)
{
  if (MC_isTextAttributeFont(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasTextAttributePoints(MC_TextAttribute arg) */

ATbool MC_hasTextAttributePoints(MC_TextAttribute arg)
{
  if (MC_isTextAttributeSize(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_Color MC_getTextAttributeColor(MC_TextAttribute arg) */

MC_Color MC_getTextAttributeColor(MC_TextAttribute arg)
{
  if (MC_isTextAttributeForegroundColor(arg)) {
    return (MC_Color)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (MC_Color)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  MC_TextStyle MC_getTextAttributeStyle(MC_TextAttribute arg) */

MC_TextStyle MC_getTextAttributeStyle(MC_TextAttribute arg)
{
  
    return (MC_TextStyle)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  char* MC_getTextAttributeName(MC_TextAttribute arg) */

char* MC_getTextAttributeName(MC_TextAttribute arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  int MC_getTextAttributePoints(MC_TextAttribute arg) */

int MC_getTextAttributePoints(MC_TextAttribute arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  MC_TextAttribute MC_setTextAttributeColor(MC_TextAttribute arg, MC_Color color) */

MC_TextAttribute MC_setTextAttributeColor(MC_TextAttribute arg, MC_Color color)
{
  if (MC_isTextAttributeForegroundColor(arg)) {
    return (MC_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) color), 0);
  }
  else if (MC_isTextAttributeBackgroundColor(arg)) {
    return (MC_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) color), 0);
  }

  ATabort("TextAttribute has no Color: %t\n", arg);
  return (MC_TextAttribute)NULL;
}

/*}}}  */
/*{{{  MC_TextAttribute MC_setTextAttributeStyle(MC_TextAttribute arg, MC_TextStyle style) */

MC_TextAttribute MC_setTextAttributeStyle(MC_TextAttribute arg, MC_TextStyle style)
{
  if (MC_isTextAttributeStyle(arg)) {
    return (MC_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) style), 0);
  }

  ATabort("TextAttribute has no Style: %t\n", arg);
  return (MC_TextAttribute)NULL;
}

/*}}}  */
/*{{{  MC_TextAttribute MC_setTextAttributeName(MC_TextAttribute arg, const char* name) */

MC_TextAttribute MC_setTextAttributeName(MC_TextAttribute arg, const char* name)
{
  if (MC_isTextAttributeFont(arg)) {
    return (MC_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("TextAttribute has no Name: %t\n", arg);
  return (MC_TextAttribute)NULL;
}

/*}}}  */
/*{{{  MC_TextAttribute MC_setTextAttributePoints(MC_TextAttribute arg, int points) */

MC_TextAttribute MC_setTextAttributePoints(MC_TextAttribute arg, int points)
{
  if (MC_isTextAttributeSize(arg)) {
    return (MC_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(points)), 0);
  }

  ATabort("TextAttribute has no Points: %t\n", arg);
  return (MC_TextAttribute)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MC_TextStyle accessors */

/*{{{  ATbool MC_isValidTextStyle(MC_TextStyle arg) */

ATbool MC_isValidTextStyle(MC_TextStyle arg)
{
  if (MC_isTextStyleBold(arg)) {
    return ATtrue;
  }
  else if (MC_isTextStyleItalics(arg)) {
    return ATtrue;
  }
  else if (MC_isTextStyleUnderlined(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isTextStyleBold(MC_TextStyle arg) */

inline ATbool MC_isTextStyleBold(MC_TextStyle arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternTextStyleBold);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isTextStyleItalics(MC_TextStyle arg) */

inline ATbool MC_isTextStyleItalics(MC_TextStyle arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternTextStyleItalics);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isTextStyleUnderlined(MC_TextStyle arg) */

inline ATbool MC_isTextStyleUnderlined(MC_TextStyle arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternTextStyleUnderlined);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  MC_Color accessors */

/*{{{  ATbool MC_isValidColor(MC_Color arg) */

ATbool MC_isValidColor(MC_Color arg)
{
  if (MC_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isColorRgb(MC_Color arg) */

inline ATbool MC_isColorRgb(MC_Color arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MC_patternColorRgb, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MC_hasColorRed(MC_Color arg) */

ATbool MC_hasColorRed(MC_Color arg)
{
  if (MC_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasColorGreen(MC_Color arg) */

ATbool MC_hasColorGreen(MC_Color arg)
{
  if (MC_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MC_hasColorBlue(MC_Color arg) */

ATbool MC_hasColorBlue(MC_Color arg)
{
  if (MC_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int MC_getColorRed(MC_Color arg) */

int MC_getColorRed(MC_Color arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  int MC_getColorGreen(MC_Color arg) */

int MC_getColorGreen(MC_Color arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  int MC_getColorBlue(MC_Color arg) */

int MC_getColorBlue(MC_Color arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  MC_Color MC_setColorRed(MC_Color arg, int red) */

MC_Color MC_setColorRed(MC_Color arg, int red)
{
  if (MC_isColorRgb(arg)) {
    return (MC_Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(red)), 0);
  }

  ATabort("Color has no Red: %t\n", arg);
  return (MC_Color)NULL;
}

/*}}}  */
/*{{{  MC_Color MC_setColorGreen(MC_Color arg, int green) */

MC_Color MC_setColorGreen(MC_Color arg, int green)
{
  if (MC_isColorRgb(arg)) {
    return (MC_Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(green)), 1);
  }

  ATabort("Color has no Green: %t\n", arg);
  return (MC_Color)NULL;
}

/*}}}  */
/*{{{  MC_Color MC_setColorBlue(MC_Color arg, int blue) */

MC_Color MC_setColorBlue(MC_Color arg, int blue)
{
  if (MC_isColorRgb(arg)) {
    return (MC_Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(blue)), 2);
  }

  ATabort("Color has no Blue: %t\n", arg);
  return (MC_Color)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  MC_Configuration MC_visitConfiguration(MC_Configuration arg, MC_Properties (*acceptList)(MC_Properties)) */

MC_Configuration MC_visitConfiguration(MC_Configuration arg, MC_Properties (*acceptList)(MC_Properties))
{
  if (MC_isConfigurationList(arg)) {
    return MC_makeConfigurationList(
        acceptList ? acceptList(MC_getConfigurationList(arg)) : MC_getConfigurationList(arg));
  }
  ATabort("not a Configuration: %t\n", arg);
  return (MC_Configuration)NULL;
}

/*}}}  */
/*{{{  MC_Properties MC_visitProperties(MC_Properties arg, MC_Property (*acceptHead)(MC_Property)) */

MC_Properties MC_visitProperties(MC_Properties arg, MC_Property (*acceptHead)(MC_Property))
{
  if (MC_isPropertiesEmpty(arg)) {
    return MC_makePropertiesEmpty();
  }
  if (MC_isPropertiesSingle(arg)) {
    return MC_makePropertiesSingle(
        acceptHead ? acceptHead(MC_getPropertiesHead(arg)) : MC_getPropertiesHead(arg));
  }
  if (MC_isPropertiesMany(arg)) {
    return MC_makePropertiesMany(
        acceptHead ? acceptHead(MC_getPropertiesHead(arg)) : MC_getPropertiesHead(arg),
        MC_visitProperties(MC_getPropertiesTail(arg), acceptHead));
  }
  ATabort("not a Properties: %t\n", arg);
  return (MC_Properties)NULL;
}

/*}}}  */
/*{{{  MC_Property MC_visitProperty(MC_Property arg, MC_ActionDescriptionList (*acceptDescriptions)(MC_ActionDescriptionList), char* (*acceptAction)(char*), char* (*acceptLanguage)(char*), char* (*acceptExtension)(char*), char* (*acceptPath)(char*), MC_TextCategoryName (*acceptCategory)(MC_TextCategoryName), MC_TextAttributes (*acceptAttributes)(MC_TextAttributes)) */

MC_Property MC_visitProperty(MC_Property arg, MC_ActionDescriptionList (*acceptDescriptions)(MC_ActionDescriptionList), char* (*acceptAction)(char*), char* (*acceptLanguage)(char*), char* (*acceptExtension)(char*), char* (*acceptPath)(char*), MC_TextCategoryName (*acceptCategory)(MC_TextCategoryName), MC_TextAttributes (*acceptAttributes)(MC_TextAttributes))
{
  if (MC_isPropertyAction(arg)) {
    return MC_makePropertyAction(
        acceptDescriptions ? acceptDescriptions(MC_getPropertyDescriptions(arg)) : MC_getPropertyDescriptions(arg),
        acceptAction ? acceptAction(MC_getPropertyAction(arg)) : MC_getPropertyAction(arg));
  }
  if (MC_isPropertyExtension(arg)) {
    return MC_makePropertyExtension(
        acceptLanguage ? acceptLanguage(MC_getPropertyLanguage(arg)) : MC_getPropertyLanguage(arg),
        acceptExtension ? acceptExtension(MC_getPropertyExtension(arg)) : MC_getPropertyExtension(arg));
  }
  if (MC_isPropertyLibraryPath(arg)) {
    return MC_makePropertyLibraryPath(
        acceptPath ? acceptPath(MC_getPropertyPath(arg)) : MC_getPropertyPath(arg));
  }
  if (MC_isPropertyModulePath(arg)) {
    return MC_makePropertyModulePath(
        acceptPath ? acceptPath(MC_getPropertyPath(arg)) : MC_getPropertyPath(arg));
  }
  if (MC_isPropertyTextCategory(arg)) {
    return MC_makePropertyTextCategory(
        acceptCategory ? acceptCategory(MC_getPropertyCategory(arg)) : MC_getPropertyCategory(arg),
        acceptAttributes ? acceptAttributes(MC_getPropertyAttributes(arg)) : MC_getPropertyAttributes(arg));
  }
  ATabort("not a Property: %t\n", arg);
  return (MC_Property)NULL;
}

/*}}}  */
/*{{{  MC_ActionDescription MC_visitActionDescription(MC_ActionDescription arg, MC_ActionType (*acceptActionType)(MC_ActionType), MC_Event (*acceptEvent)(MC_Event)) */

MC_ActionDescription MC_visitActionDescription(MC_ActionDescription arg, MC_ActionType (*acceptActionType)(MC_ActionType), MC_Event (*acceptEvent)(MC_Event))
{
  if (MC_isActionDescriptionDefault(arg)) {
    return MC_makeActionDescriptionDefault(
        acceptActionType ? acceptActionType(MC_getActionDescriptionActionType(arg)) : MC_getActionDescriptionActionType(arg),
        acceptEvent ? acceptEvent(MC_getActionDescriptionEvent(arg)) : MC_getActionDescriptionEvent(arg));
  }
  ATabort("not a ActionDescription: %t\n", arg);
  return (MC_ActionDescription)NULL;
}

/*}}}  */
/*{{{  MC_ActionDescriptionList MC_visitActionDescriptionList(MC_ActionDescriptionList arg, MC_ActionDescription (*acceptHead)(MC_ActionDescription)) */

MC_ActionDescriptionList MC_visitActionDescriptionList(MC_ActionDescriptionList arg, MC_ActionDescription (*acceptHead)(MC_ActionDescription))
{
  if (MC_isActionDescriptionListEmpty(arg)) {
    return MC_makeActionDescriptionListEmpty();
  }
  if (MC_isActionDescriptionListSingle(arg)) {
    return MC_makeActionDescriptionListSingle(
        acceptHead ? acceptHead(MC_getActionDescriptionListHead(arg)) : MC_getActionDescriptionListHead(arg));
  }
  if (MC_isActionDescriptionListMany(arg)) {
    return MC_makeActionDescriptionListMany(
        acceptHead ? acceptHead(MC_getActionDescriptionListHead(arg)) : MC_getActionDescriptionListHead(arg),
        MC_visitActionDescriptionList(MC_getActionDescriptionListTail(arg), acceptHead));
  }
  ATabort("not a ActionDescriptionList: %t\n", arg);
  return (MC_ActionDescriptionList)NULL;
}

/*}}}  */
/*{{{  MC_ActionType MC_visitActionType(MC_ActionType arg, char* (*acceptModuleId)(char*)) */

MC_ActionType MC_visitActionType(MC_ActionType arg, char* (*acceptModuleId)(char*))
{
  if (MC_isActionTypeTermEditor(arg)) {
    return MC_makeActionTypeTermEditor();
  }
  if (MC_isActionTypeTermEditorForModule(arg)) {
    return MC_makeActionTypeTermEditorForModule(
        acceptModuleId ? acceptModuleId(MC_getActionTypeModuleId(arg)) : MC_getActionTypeModuleId(arg));
  }
  if (MC_isActionTypeEquationsEditor(arg)) {
    return MC_makeActionTypeEquationsEditor();
  }
  if (MC_isActionTypeSyntaxEditor(arg)) {
    return MC_makeActionTypeSyntaxEditor();
  }
  if (MC_isActionTypeFeedbackList(arg)) {
    return MC_makeActionTypeFeedbackList();
  }
  if (MC_isActionTypeTreePanel(arg)) {
    return MC_makeActionTypeTreePanel();
  }
  if (MC_isActionTypeModulePopup(arg)) {
    return MC_makeActionTypeModulePopup(
        acceptModuleId ? acceptModuleId(MC_getActionTypeModuleId(arg)) : MC_getActionTypeModuleId(arg));
  }
  if (MC_isActionTypeNewModulePopup(arg)) {
    return MC_makeActionTypeNewModulePopup();
  }
  if (MC_isActionTypeStudioMenubar(arg)) {
    return MC_makeActionTypeStudioMenubar();
  }
  if (MC_isActionTypeStudioToolbar(arg)) {
    return MC_makeActionTypeStudioToolbar();
  }
  if (MC_isActionTypeWildcard(arg)) {
    return MC_makeActionTypeWildcard();
  }
  ATabort("not a ActionType: %t\n", arg);
  return (MC_ActionType)NULL;
}

/*}}}  */
/*{{{  MC_Event MC_visitEvent(MC_Event arg, char* (*acceptTitle)(char*), char* (*acceptPath)(char*), MC_Items (*acceptItems)(MC_Items), char* (*acceptShortcut)(char*)) */

MC_Event MC_visitEvent(MC_Event arg, char* (*acceptTitle)(char*), char* (*acceptPath)(char*), MC_Items (*acceptItems)(MC_Items), char* (*acceptShortcut)(char*))
{
  if (MC_isEventClick(arg)) {
    return MC_makeEventClick();
  }
  if (MC_isEventIcon(arg)) {
    return MC_makeEventIcon(
        acceptTitle ? acceptTitle(MC_getEventTitle(arg)) : MC_getEventTitle(arg),
        acceptPath ? acceptPath(MC_getEventPath(arg)) : MC_getEventPath(arg));
  }
  if (MC_isEventDefault(arg)) {
    return MC_makeEventDefault(
        acceptItems ? acceptItems(MC_getEventItems(arg)) : MC_getEventItems(arg));
  }
  if (MC_isEventShortcut(arg)) {
    return MC_makeEventShortcut(
        acceptItems ? acceptItems(MC_getEventItems(arg)) : MC_getEventItems(arg),
        acceptShortcut ? acceptShortcut(MC_getEventShortcut(arg)) : MC_getEventShortcut(arg));
  }
  ATabort("not a Event: %t\n", arg);
  return (MC_Event)NULL;
}

/*}}}  */
/*{{{  MC_Items MC_visitItems(MC_Items arg, char* (*acceptHead)(char*)) */

MC_Items MC_visitItems(MC_Items arg, char* (*acceptHead)(char*))
{
  if (MC_isItemsEmpty(arg)) {
    return MC_makeItemsEmpty();
  }
  if (MC_isItemsSingle(arg)) {
    return MC_makeItemsSingle(
        acceptHead ? acceptHead(MC_getItemsHead(arg)) : MC_getItemsHead(arg));
  }
  if (MC_isItemsMany(arg)) {
    return MC_makeItemsMany(
        acceptHead ? acceptHead(MC_getItemsHead(arg)) : MC_getItemsHead(arg),
        MC_visitItems(MC_getItemsTail(arg), acceptHead));
  }
  ATabort("not a Items: %t\n", arg);
  return (MC_Items)NULL;
}

/*}}}  */
/*{{{  MC_ModuleName MC_visitModuleName(MC_ModuleName arg) */

MC_ModuleName MC_visitModuleName(MC_ModuleName arg)
{
  if (MC_isModuleNameWildcard(arg)) {
    return MC_makeModuleNameWildcard();
  }
  ATabort("not a ModuleName: %t\n", arg);
  return (MC_ModuleName)NULL;
}

/*}}}  */
/*{{{  MC_TextCategoryName MC_visitTextCategoryName(MC_TextCategoryName arg, char* (*acceptName)(char*)) */

MC_TextCategoryName MC_visitTextCategoryName(MC_TextCategoryName arg, char* (*acceptName)(char*))
{
  if (MC_isTextCategoryNameFocus(arg)) {
    return MC_makeTextCategoryNameFocus();
  }
  if (MC_isTextCategoryNameSelection(arg)) {
    return MC_makeTextCategoryNameSelection();
  }
  if (MC_isTextCategoryNameNormal(arg)) {
    return MC_makeTextCategoryNameNormal();
  }
  if (MC_isTextCategoryNameExtern(arg)) {
    return MC_makeTextCategoryNameExtern(
        acceptName ? acceptName(MC_getTextCategoryNameName(arg)) : MC_getTextCategoryNameName(arg));
  }
  ATabort("not a TextCategoryName: %t\n", arg);
  return (MC_TextCategoryName)NULL;
}

/*}}}  */
/*{{{  MC_TextAttributes MC_visitTextAttributes(MC_TextAttributes arg, MC_TextAttribute (*acceptHead)(MC_TextAttribute)) */

MC_TextAttributes MC_visitTextAttributes(MC_TextAttributes arg, MC_TextAttribute (*acceptHead)(MC_TextAttribute))
{
  if (MC_isTextAttributesEmpty(arg)) {
    return MC_makeTextAttributesEmpty();
  }
  if (MC_isTextAttributesSingle(arg)) {
    return MC_makeTextAttributesSingle(
        acceptHead ? acceptHead(MC_getTextAttributesHead(arg)) : MC_getTextAttributesHead(arg));
  }
  if (MC_isTextAttributesMany(arg)) {
    return MC_makeTextAttributesMany(
        acceptHead ? acceptHead(MC_getTextAttributesHead(arg)) : MC_getTextAttributesHead(arg),
        MC_visitTextAttributes(MC_getTextAttributesTail(arg), acceptHead));
  }
  ATabort("not a TextAttributes: %t\n", arg);
  return (MC_TextAttributes)NULL;
}

/*}}}  */
/*{{{  MC_TextAttribute MC_visitTextAttribute(MC_TextAttribute arg, MC_Color (*acceptColor)(MC_Color), MC_TextStyle (*acceptStyle)(MC_TextStyle), char* (*acceptName)(char*), int (*acceptPoints)(int)) */

MC_TextAttribute MC_visitTextAttribute(MC_TextAttribute arg, MC_Color (*acceptColor)(MC_Color), MC_TextStyle (*acceptStyle)(MC_TextStyle), char* (*acceptName)(char*), int (*acceptPoints)(int))
{
  if (MC_isTextAttributeForegroundColor(arg)) {
    return MC_makeTextAttributeForegroundColor(
        acceptColor ? acceptColor(MC_getTextAttributeColor(arg)) : MC_getTextAttributeColor(arg));
  }
  if (MC_isTextAttributeBackgroundColor(arg)) {
    return MC_makeTextAttributeBackgroundColor(
        acceptColor ? acceptColor(MC_getTextAttributeColor(arg)) : MC_getTextAttributeColor(arg));
  }
  if (MC_isTextAttributeStyle(arg)) {
    return MC_makeTextAttributeStyle(
        acceptStyle ? acceptStyle(MC_getTextAttributeStyle(arg)) : MC_getTextAttributeStyle(arg));
  }
  if (MC_isTextAttributeFont(arg)) {
    return MC_makeTextAttributeFont(
        acceptName ? acceptName(MC_getTextAttributeName(arg)) : MC_getTextAttributeName(arg));
  }
  if (MC_isTextAttributeSize(arg)) {
    return MC_makeTextAttributeSize(
        acceptPoints ? acceptPoints(MC_getTextAttributePoints(arg)) : MC_getTextAttributePoints(arg));
  }
  ATabort("not a TextAttribute: %t\n", arg);
  return (MC_TextAttribute)NULL;
}

/*}}}  */
/*{{{  MC_TextStyle MC_visitTextStyle(MC_TextStyle arg) */

MC_TextStyle MC_visitTextStyle(MC_TextStyle arg)
{
  if (MC_isTextStyleBold(arg)) {
    return MC_makeTextStyleBold();
  }
  if (MC_isTextStyleItalics(arg)) {
    return MC_makeTextStyleItalics();
  }
  if (MC_isTextStyleUnderlined(arg)) {
    return MC_makeTextStyleUnderlined();
  }
  ATabort("not a TextStyle: %t\n", arg);
  return (MC_TextStyle)NULL;
}

/*}}}  */
/*{{{  MC_Color MC_visitColor(MC_Color arg, int (*acceptRed)(int), int (*acceptGreen)(int), int (*acceptBlue)(int)) */

MC_Color MC_visitColor(MC_Color arg, int (*acceptRed)(int), int (*acceptGreen)(int), int (*acceptBlue)(int))
{
  if (MC_isColorRgb(arg)) {
    return MC_makeColorRgb(
        acceptRed ? acceptRed(MC_getColorRed(arg)) : MC_getColorRed(arg),
        acceptGreen ? acceptGreen(MC_getColorGreen(arg)) : MC_getColorGreen(arg),
        acceptBlue ? acceptBlue(MC_getColorBlue(arg)) : MC_getColorBlue(arg));
  }
  ATabort("not a Color: %t\n", arg);
  return (MC_Color)NULL;
}

/*}}}  */

/*}}}  */
