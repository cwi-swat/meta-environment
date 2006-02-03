#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Config.h"

/*{{{  conversion functions */

ATerm CFG_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

ATerm CFG_byteToChar(char ch)
{
    return (ATerm) ATmakeInt(ch);
}

char *CFG_charsToString(ATerm arg)
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

char CFG_charToByte(ATerm arg)
{
    return (char) ATgetInt((ATermInt) arg);
}


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _CFG_Configuration;
typedef struct ATerm _CFG_Properties;
typedef struct ATerm _CFG_Property;
typedef struct ATerm _CFG_ActionDescription;
typedef struct ATerm _CFG_ActionDescriptionList;
typedef struct ATerm _CFG_ActionType;
typedef struct ATerm _CFG_Event;
typedef struct ATerm _CFG_Items;
typedef struct ATerm _CFG_ModuleName;
typedef struct ATerm _CFG_TextCategoryName;
typedef struct ATerm _CFG_TextAttributes;
typedef struct ATerm _CFG_TextAttribute;
typedef struct ATerm _CFG_TextStyle;
typedef struct ATerm _CFG_Color;

/*}}}  */

/*{{{  void CFG_initConfigApi(void) */

void CFG_initConfigApi(void)
{
  init_Config_dict();
}

/*}}}  */

/*{{{  protect functions */

void CFG_protectConfiguration(CFG_Configuration *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CFG_protectProperties(CFG_Properties *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CFG_protectProperty(CFG_Property *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CFG_protectActionDescription(CFG_ActionDescription *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CFG_protectActionDescriptionList(CFG_ActionDescriptionList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CFG_protectActionType(CFG_ActionType *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CFG_protectEvent(CFG_Event *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CFG_protectItems(CFG_Items *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CFG_protectModuleName(CFG_ModuleName *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CFG_protectTextCategoryName(CFG_TextCategoryName *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CFG_protectTextAttributes(CFG_TextAttributes *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CFG_protectTextAttribute(CFG_TextAttribute *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CFG_protectTextStyle(CFG_TextStyle *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CFG_protectColor(CFG_Color *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  CFG_Configuration CFG_ConfigurationFromTerm(ATerm t) */

CFG_Configuration CFG_ConfigurationFromTerm(ATerm t)
{
  return (CFG_Configuration)t;
}

/*}}}  */
/*{{{  ATerm CFG_ConfigurationToTerm(CFG_Configuration arg) */

ATerm CFG_ConfigurationToTerm(CFG_Configuration arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CFG_Properties CFG_PropertiesFromTerm(ATerm t) */

CFG_Properties CFG_PropertiesFromTerm(ATerm t)
{
  return (CFG_Properties)t;
}

/*}}}  */
/*{{{  ATerm CFG_PropertiesToTerm(CFG_Properties arg) */

ATerm CFG_PropertiesToTerm(CFG_Properties arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CFG_Property CFG_PropertyFromTerm(ATerm t) */

CFG_Property CFG_PropertyFromTerm(ATerm t)
{
  return (CFG_Property)t;
}

/*}}}  */
/*{{{  ATerm CFG_PropertyToTerm(CFG_Property arg) */

ATerm CFG_PropertyToTerm(CFG_Property arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CFG_ActionDescription CFG_ActionDescriptionFromTerm(ATerm t) */

CFG_ActionDescription CFG_ActionDescriptionFromTerm(ATerm t)
{
  return (CFG_ActionDescription)t;
}

/*}}}  */
/*{{{  ATerm CFG_ActionDescriptionToTerm(CFG_ActionDescription arg) */

ATerm CFG_ActionDescriptionToTerm(CFG_ActionDescription arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CFG_ActionDescriptionList CFG_ActionDescriptionListFromTerm(ATerm t) */

CFG_ActionDescriptionList CFG_ActionDescriptionListFromTerm(ATerm t)
{
  return (CFG_ActionDescriptionList)t;
}

/*}}}  */
/*{{{  ATerm CFG_ActionDescriptionListToTerm(CFG_ActionDescriptionList arg) */

ATerm CFG_ActionDescriptionListToTerm(CFG_ActionDescriptionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CFG_ActionType CFG_ActionTypeFromTerm(ATerm t) */

CFG_ActionType CFG_ActionTypeFromTerm(ATerm t)
{
  return (CFG_ActionType)t;
}

/*}}}  */
/*{{{  ATerm CFG_ActionTypeToTerm(CFG_ActionType arg) */

ATerm CFG_ActionTypeToTerm(CFG_ActionType arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CFG_Event CFG_EventFromTerm(ATerm t) */

CFG_Event CFG_EventFromTerm(ATerm t)
{
  return (CFG_Event)t;
}

/*}}}  */
/*{{{  ATerm CFG_EventToTerm(CFG_Event arg) */

ATerm CFG_EventToTerm(CFG_Event arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CFG_Items CFG_ItemsFromTerm(ATerm t) */

CFG_Items CFG_ItemsFromTerm(ATerm t)
{
  return (CFG_Items)t;
}

/*}}}  */
/*{{{  ATerm CFG_ItemsToTerm(CFG_Items arg) */

ATerm CFG_ItemsToTerm(CFG_Items arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CFG_ModuleName CFG_ModuleNameFromTerm(ATerm t) */

CFG_ModuleName CFG_ModuleNameFromTerm(ATerm t)
{
  return (CFG_ModuleName)t;
}

/*}}}  */
/*{{{  ATerm CFG_ModuleNameToTerm(CFG_ModuleName arg) */

ATerm CFG_ModuleNameToTerm(CFG_ModuleName arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CFG_TextCategoryName CFG_TextCategoryNameFromTerm(ATerm t) */

CFG_TextCategoryName CFG_TextCategoryNameFromTerm(ATerm t)
{
  return (CFG_TextCategoryName)t;
}

/*}}}  */
/*{{{  ATerm CFG_TextCategoryNameToTerm(CFG_TextCategoryName arg) */

ATerm CFG_TextCategoryNameToTerm(CFG_TextCategoryName arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CFG_TextAttributes CFG_TextAttributesFromTerm(ATerm t) */

CFG_TextAttributes CFG_TextAttributesFromTerm(ATerm t)
{
  return (CFG_TextAttributes)t;
}

/*}}}  */
/*{{{  ATerm CFG_TextAttributesToTerm(CFG_TextAttributes arg) */

ATerm CFG_TextAttributesToTerm(CFG_TextAttributes arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CFG_TextAttribute CFG_TextAttributeFromTerm(ATerm t) */

CFG_TextAttribute CFG_TextAttributeFromTerm(ATerm t)
{
  return (CFG_TextAttribute)t;
}

/*}}}  */
/*{{{  ATerm CFG_TextAttributeToTerm(CFG_TextAttribute arg) */

ATerm CFG_TextAttributeToTerm(CFG_TextAttribute arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CFG_TextStyle CFG_TextStyleFromTerm(ATerm t) */

CFG_TextStyle CFG_TextStyleFromTerm(ATerm t)
{
  return (CFG_TextStyle)t;
}

/*}}}  */
/*{{{  ATerm CFG_TextStyleToTerm(CFG_TextStyle arg) */

ATerm CFG_TextStyleToTerm(CFG_TextStyle arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CFG_Color CFG_ColorFromTerm(ATerm t) */

CFG_Color CFG_ColorFromTerm(ATerm t)
{
  return (CFG_Color)t;
}

/*}}}  */
/*{{{  ATerm CFG_ColorToTerm(CFG_Color arg) */

ATerm CFG_ColorToTerm(CFG_Color arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int CFG_getPropertiesLength (CFG_Properties arg) {
  return ATgetLength((ATermList) arg);
}
CFG_Properties CFG_reverseProperties(CFG_Properties arg) {
  return (CFG_Properties) ATreverse((ATermList) arg);
}
CFG_Properties CFG_appendProperties(CFG_Properties arg, CFG_Property elem) {
  return (CFG_Properties) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
CFG_Properties CFG_concatProperties(CFG_Properties arg0, CFG_Properties arg1) {
  return (CFG_Properties) ATconcat((ATermList) arg0, (ATermList) arg1);
}
CFG_Properties CFG_sliceProperties(CFG_Properties arg, int start, int end) {
  return (CFG_Properties) ATgetSlice((ATermList) arg, start, end);
}
CFG_Property CFG_getPropertiesPropertyAt(CFG_Properties arg, int index) {
 return (CFG_Property)ATelementAt((ATermList) arg,index);
}
CFG_Properties CFG_replacePropertiesPropertyAt(CFG_Properties arg, CFG_Property elem, int index) {
 return (CFG_Properties) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
CFG_Properties CFG_makeProperties2(CFG_Property elem1, CFG_Property elem2) {
  return (CFG_Properties) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
CFG_Properties CFG_makeProperties3(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3) {
  return (CFG_Properties) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
CFG_Properties CFG_makeProperties4(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3, CFG_Property elem4) {
  return (CFG_Properties) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
CFG_Properties CFG_makeProperties5(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3, CFG_Property elem4, CFG_Property elem5) {
  return (CFG_Properties) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
CFG_Properties CFG_makeProperties6(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3, CFG_Property elem4, CFG_Property elem5, CFG_Property elem6) {
  return (CFG_Properties) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int CFG_getActionDescriptionListLength (CFG_ActionDescriptionList arg) {
  return ATgetLength((ATermList) arg);
}
CFG_ActionDescriptionList CFG_reverseActionDescriptionList(CFG_ActionDescriptionList arg) {
  return (CFG_ActionDescriptionList) ATreverse((ATermList) arg);
}
CFG_ActionDescriptionList CFG_appendActionDescriptionList(CFG_ActionDescriptionList arg, CFG_ActionDescription elem) {
  return (CFG_ActionDescriptionList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
CFG_ActionDescriptionList CFG_concatActionDescriptionList(CFG_ActionDescriptionList arg0, CFG_ActionDescriptionList arg1) {
  return (CFG_ActionDescriptionList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
CFG_ActionDescriptionList CFG_sliceActionDescriptionList(CFG_ActionDescriptionList arg, int start, int end) {
  return (CFG_ActionDescriptionList) ATgetSlice((ATermList) arg, start, end);
}
CFG_ActionDescription CFG_getActionDescriptionListActionDescriptionAt(CFG_ActionDescriptionList arg, int index) {
 return (CFG_ActionDescription)ATelementAt((ATermList) arg,index);
}
CFG_ActionDescriptionList CFG_replaceActionDescriptionListActionDescriptionAt(CFG_ActionDescriptionList arg, CFG_ActionDescription elem, int index) {
 return (CFG_ActionDescriptionList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
CFG_ActionDescriptionList CFG_makeActionDescriptionList2(CFG_ActionDescription elem1, CFG_ActionDescription elem2) {
  return (CFG_ActionDescriptionList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
CFG_ActionDescriptionList CFG_makeActionDescriptionList3(CFG_ActionDescription elem1, CFG_ActionDescription elem2, CFG_ActionDescription elem3) {
  return (CFG_ActionDescriptionList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
CFG_ActionDescriptionList CFG_makeActionDescriptionList4(CFG_ActionDescription elem1, CFG_ActionDescription elem2, CFG_ActionDescription elem3, CFG_ActionDescription elem4) {
  return (CFG_ActionDescriptionList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
CFG_ActionDescriptionList CFG_makeActionDescriptionList5(CFG_ActionDescription elem1, CFG_ActionDescription elem2, CFG_ActionDescription elem3, CFG_ActionDescription elem4, CFG_ActionDescription elem5) {
  return (CFG_ActionDescriptionList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
CFG_ActionDescriptionList CFG_makeActionDescriptionList6(CFG_ActionDescription elem1, CFG_ActionDescription elem2, CFG_ActionDescription elem3, CFG_ActionDescription elem4, CFG_ActionDescription elem5, CFG_ActionDescription elem6) {
  return (CFG_ActionDescriptionList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int CFG_getItemsLength (CFG_Items arg) {
  return ATgetLength((ATermList) arg);
}
CFG_Items CFG_reverseItems(CFG_Items arg) {
  return (CFG_Items) ATreverse((ATermList) arg);
}
CFG_Items CFG_appendItems(CFG_Items arg, char* elem) {
  return (CFG_Items) ATappend((ATermList) arg, (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem, 0, ATtrue))));
}
CFG_Items CFG_concatItems(CFG_Items arg0, CFG_Items arg1) {
  return (CFG_Items) ATconcat((ATermList) arg0, (ATermList) arg1);
}
CFG_Items CFG_sliceItems(CFG_Items arg, int start, int end) {
  return (CFG_Items) ATgetSlice((ATermList) arg, start, end);
}
char* CFG_getItemsstrAt(CFG_Items arg, int index) {
 return (char*)ATgetName(ATgetAFun((ATermAppl) ATelementAt((ATermList) arg,index)));
}
CFG_Items CFG_replaceItemsstrAt(CFG_Items arg, char* elem, int index) {
 return (CFG_Items) ATreplace((ATermList) arg, (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem, 0, ATtrue))), index);
}
CFG_Items CFG_makeItems2(char* elem1, char* elem2) {
  return (CFG_Items) ATmakeList2((ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem2, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem2, 0, ATtrue))));
}
CFG_Items CFG_makeItems3(char* elem1, char* elem2, char* elem3) {
  return (CFG_Items) ATmakeList3((ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem3, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem3, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem3, 0, ATtrue))));
}
CFG_Items CFG_makeItems4(char* elem1, char* elem2, char* elem3, char* elem4) {
  return (CFG_Items) ATmakeList4((ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem4, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem4, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem4, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem4, 0, ATtrue))));
}
CFG_Items CFG_makeItems5(char* elem1, char* elem2, char* elem3, char* elem4, char* elem5) {
  return (CFG_Items) ATmakeList5((ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem5, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem5, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem5, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem5, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem5, 0, ATtrue))));
}
CFG_Items CFG_makeItems6(char* elem1, char* elem2, char* elem3, char* elem4, char* elem5, char* elem6) {
  return (CFG_Items) ATmakeList6((ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))), (ATerm) ((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(elem6, 0, ATtrue))));
}
int CFG_getTextAttributesLength (CFG_TextAttributes arg) {
  return ATgetLength((ATermList) arg);
}
CFG_TextAttributes CFG_reverseTextAttributes(CFG_TextAttributes arg) {
  return (CFG_TextAttributes) ATreverse((ATermList) arg);
}
CFG_TextAttributes CFG_appendTextAttributes(CFG_TextAttributes arg, CFG_TextAttribute elem) {
  return (CFG_TextAttributes) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
CFG_TextAttributes CFG_concatTextAttributes(CFG_TextAttributes arg0, CFG_TextAttributes arg1) {
  return (CFG_TextAttributes) ATconcat((ATermList) arg0, (ATermList) arg1);
}
CFG_TextAttributes CFG_sliceTextAttributes(CFG_TextAttributes arg, int start, int end) {
  return (CFG_TextAttributes) ATgetSlice((ATermList) arg, start, end);
}
CFG_TextAttribute CFG_getTextAttributesTextAttributeAt(CFG_TextAttributes arg, int index) {
 return (CFG_TextAttribute)ATelementAt((ATermList) arg,index);
}
CFG_TextAttributes CFG_replaceTextAttributesTextAttributeAt(CFG_TextAttributes arg, CFG_TextAttribute elem, int index) {
 return (CFG_TextAttributes) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
CFG_TextAttributes CFG_makeTextAttributes2(CFG_TextAttribute elem1, CFG_TextAttribute elem2) {
  return (CFG_TextAttributes) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
CFG_TextAttributes CFG_makeTextAttributes3(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3) {
  return (CFG_TextAttributes) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
CFG_TextAttributes CFG_makeTextAttributes4(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3, CFG_TextAttribute elem4) {
  return (CFG_TextAttributes) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
CFG_TextAttributes CFG_makeTextAttributes5(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3, CFG_TextAttribute elem4, CFG_TextAttribute elem5) {
  return (CFG_TextAttributes) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
CFG_TextAttributes CFG_makeTextAttributes6(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3, CFG_TextAttribute elem4, CFG_TextAttribute elem5, CFG_TextAttribute elem6) {
  return (CFG_TextAttributes) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  CFG_Configuration CFG_makeConfigurationImport(const char* path) */

CFG_Configuration CFG_makeConfigurationImport(const char* path)
{
  return (CFG_Configuration)(ATerm)ATmakeAppl1(CFG_afun0, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}

/*}}}  */
/*{{{  CFG_Configuration CFG_makeConfigurationList(CFG_Properties list) */

CFG_Configuration CFG_makeConfigurationList(CFG_Properties list)
{
  return (CFG_Configuration)(ATerm)ATmakeAppl1(CFG_afun1, (ATerm) list);
}

/*}}}  */
/*{{{  CFG_Properties CFG_makePropertiesEmpty(void) */

CFG_Properties CFG_makePropertiesEmpty(void)
{
  return (CFG_Properties)(ATerm)ATempty;
}

/*}}}  */
/*{{{  CFG_Properties CFG_makePropertiesSingle(CFG_Property head) */

CFG_Properties CFG_makePropertiesSingle(CFG_Property head)
{
  return (CFG_Properties)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  CFG_Properties CFG_makePropertiesMany(CFG_Property head, CFG_Properties tail) */

CFG_Properties CFG_makePropertiesMany(CFG_Property head, CFG_Properties tail)
{
  return (CFG_Properties)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  CFG_Property CFG_makePropertyAction(CFG_ActionDescriptionList descriptions, const char* action) */

CFG_Property CFG_makePropertyAction(CFG_ActionDescriptionList descriptions, const char* action)
{
  return (CFG_Property)(ATerm)ATmakeAppl2(CFG_afun2, (ATerm) descriptions, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(action, 0, ATtrue)));
}

/*}}}  */
/*{{{  CFG_Property CFG_makePropertyExtension(const char* language, const char* extension) */

CFG_Property CFG_makePropertyExtension(const char* language, const char* extension)
{
  return (CFG_Property)(ATerm)ATmakeAppl2(CFG_afun3, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(language, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(extension, 0, ATtrue)));
}

/*}}}  */
/*{{{  CFG_Property CFG_makePropertyLibraryPath(const char* label, const char* path) */

CFG_Property CFG_makePropertyLibraryPath(const char* label, const char* path)
{
  return (CFG_Property)(ATerm)ATmakeAppl2(CFG_afun4, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(label, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}

/*}}}  */
/*{{{  CFG_Property CFG_makePropertyModulePath(const char* label, const char* path) */

CFG_Property CFG_makePropertyModulePath(const char* label, const char* path)
{
  return (CFG_Property)(ATerm)ATmakeAppl2(CFG_afun5, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(label, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}

/*}}}  */
/*{{{  CFG_Property CFG_makePropertyTextCategory(CFG_TextCategoryName category, CFG_TextAttributes attributes) */

CFG_Property CFG_makePropertyTextCategory(CFG_TextCategoryName category, CFG_TextAttributes attributes)
{
  return (CFG_Property)(ATerm)ATmakeAppl2(CFG_afun6, (ATerm) category, (ATerm) attributes);
}

/*}}}  */
/*{{{  CFG_ActionDescription CFG_makeActionDescriptionDefault(CFG_ActionType actionType, CFG_Event event) */

CFG_ActionDescription CFG_makeActionDescriptionDefault(CFG_ActionType actionType, CFG_Event event)
{
  return (CFG_ActionDescription)(ATerm)ATmakeAppl2(CFG_afun7, (ATerm) actionType, (ATerm) event);
}

/*}}}  */
/*{{{  CFG_ActionDescriptionList CFG_makeActionDescriptionListEmpty(void) */

CFG_ActionDescriptionList CFG_makeActionDescriptionListEmpty(void)
{
  return (CFG_ActionDescriptionList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  CFG_ActionDescriptionList CFG_makeActionDescriptionListSingle(CFG_ActionDescription head) */

CFG_ActionDescriptionList CFG_makeActionDescriptionListSingle(CFG_ActionDescription head)
{
  return (CFG_ActionDescriptionList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  CFG_ActionDescriptionList CFG_makeActionDescriptionListMany(CFG_ActionDescription head, CFG_ActionDescriptionList tail) */

CFG_ActionDescriptionList CFG_makeActionDescriptionListMany(CFG_ActionDescription head, CFG_ActionDescriptionList tail)
{
  return (CFG_ActionDescriptionList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  CFG_ActionType CFG_makeActionTypeTermEditor(void) */

CFG_ActionType CFG_makeActionTypeTermEditor(void)
{
  return (CFG_ActionType)(ATerm)ATmakeAppl0(CFG_afun8);
}

/*}}}  */
/*{{{  CFG_ActionType CFG_makeActionTypeTermEditorForModule(const char* moduleId) */

CFG_ActionType CFG_makeActionTypeTermEditorForModule(const char* moduleId)
{
  return (CFG_ActionType)(ATerm)ATmakeAppl1(CFG_afun9, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(moduleId, 0, ATtrue)));
}

/*}}}  */
/*{{{  CFG_ActionType CFG_makeActionTypeEquationsEditor(void) */

CFG_ActionType CFG_makeActionTypeEquationsEditor(void)
{
  return (CFG_ActionType)(ATerm)ATmakeAppl0(CFG_afun10);
}

/*}}}  */
/*{{{  CFG_ActionType CFG_makeActionTypeSyntaxEditor(void) */

CFG_ActionType CFG_makeActionTypeSyntaxEditor(void)
{
  return (CFG_ActionType)(ATerm)ATmakeAppl0(CFG_afun11);
}

/*}}}  */
/*{{{  CFG_ActionType CFG_makeActionTypeFeedbackList(void) */

CFG_ActionType CFG_makeActionTypeFeedbackList(void)
{
  return (CFG_ActionType)(ATerm)ATmakeAppl0(CFG_afun12);
}

/*}}}  */
/*{{{  CFG_ActionType CFG_makeActionTypeTreePanel(void) */

CFG_ActionType CFG_makeActionTypeTreePanel(void)
{
  return (CFG_ActionType)(ATerm)ATmakeAppl0(CFG_afun13);
}

/*}}}  */
/*{{{  CFG_ActionType CFG_makeActionTypeModulePopup(const char* moduleId) */

CFG_ActionType CFG_makeActionTypeModulePopup(const char* moduleId)
{
  return (CFG_ActionType)(ATerm)ATmakeAppl1(CFG_afun14, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(moduleId, 0, ATtrue)));
}

/*}}}  */
/*{{{  CFG_ActionType CFG_makeActionTypeNewModulePopup(void) */

CFG_ActionType CFG_makeActionTypeNewModulePopup(void)
{
  return (CFG_ActionType)(ATerm)ATmakeAppl0(CFG_afun15);
}

/*}}}  */
/*{{{  CFG_ActionType CFG_makeActionTypeStudioMenubar(void) */

CFG_ActionType CFG_makeActionTypeStudioMenubar(void)
{
  return (CFG_ActionType)(ATerm)ATmakeAppl0(CFG_afun16);
}

/*}}}  */
/*{{{  CFG_ActionType CFG_makeActionTypeStudioToolbar(void) */

CFG_ActionType CFG_makeActionTypeStudioToolbar(void)
{
  return (CFG_ActionType)(ATerm)ATmakeAppl0(CFG_afun17);
}

/*}}}  */
/*{{{  CFG_ActionType CFG_makeActionTypeWildcard(void) */

CFG_ActionType CFG_makeActionTypeWildcard(void)
{
  return (CFG_ActionType)(ATerm)ATmakeAppl0(CFG_afun18);
}

/*}}}  */
/*{{{  CFG_Event CFG_makeEventClick(void) */

CFG_Event CFG_makeEventClick(void)
{
  return (CFG_Event)(ATerm)ATmakeAppl0(CFG_afun19);
}

/*}}}  */
/*{{{  CFG_Event CFG_makeEventIcon(const char* title, const char* path) */

CFG_Event CFG_makeEventIcon(const char* title, const char* path)
{
  return (CFG_Event)(ATerm)ATmakeAppl2(CFG_afun20, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(title, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}

/*}}}  */
/*{{{  CFG_Event CFG_makeEventDefault(CFG_Items items) */

CFG_Event CFG_makeEventDefault(CFG_Items items)
{
  return (CFG_Event)(ATerm)ATmakeAppl1(CFG_afun21, (ATerm) items);
}

/*}}}  */
/*{{{  CFG_Event CFG_makeEventShortcut(CFG_Items items, const char* shortcut) */

CFG_Event CFG_makeEventShortcut(CFG_Items items, const char* shortcut)
{
  return (CFG_Event)(ATerm)ATmakeAppl2(CFG_afun22, (ATerm) items, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(shortcut, 0, ATtrue)));
}

/*}}}  */
/*{{{  CFG_Items CFG_makeItemsEmpty(void) */

CFG_Items CFG_makeItemsEmpty(void)
{
  return (CFG_Items)(ATerm)ATempty;
}

/*}}}  */
/*{{{  CFG_Items CFG_makeItemsSingle(const char* head) */

CFG_Items CFG_makeItemsSingle(const char* head)
{
  return (CFG_Items)(ATerm)ATmakeList1((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(head, 0, ATtrue)));
}

/*}}}  */
/*{{{  CFG_Items CFG_makeItemsMany(const char* head, CFG_Items tail) */

CFG_Items CFG_makeItemsMany(const char* head, CFG_Items tail)
{
  return (CFG_Items)(ATerm)ATinsert((ATermList)tail, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(head, 0, ATtrue)));
}

/*}}}  */
/*{{{  CFG_ModuleName CFG_makeModuleNameWildcard(void) */

CFG_ModuleName CFG_makeModuleNameWildcard(void)
{
  return (CFG_ModuleName)(ATerm)ATmakeAppl0(CFG_afun18);
}

/*}}}  */
/*{{{  CFG_TextCategoryName CFG_makeTextCategoryNameFocus(void) */

CFG_TextCategoryName CFG_makeTextCategoryNameFocus(void)
{
  return (CFG_TextCategoryName)(ATerm)ATmakeAppl0(CFG_afun23);
}

/*}}}  */
/*{{{  CFG_TextCategoryName CFG_makeTextCategoryNameSelection(void) */

CFG_TextCategoryName CFG_makeTextCategoryNameSelection(void)
{
  return (CFG_TextCategoryName)(ATerm)ATmakeAppl0(CFG_afun24);
}

/*}}}  */
/*{{{  CFG_TextCategoryName CFG_makeTextCategoryNameNormal(void) */

CFG_TextCategoryName CFG_makeTextCategoryNameNormal(void)
{
  return (CFG_TextCategoryName)(ATerm)ATmakeAppl0(CFG_afun25);
}

/*}}}  */
/*{{{  CFG_TextCategoryName CFG_makeTextCategoryNameExtern(const char* name) */

CFG_TextCategoryName CFG_makeTextCategoryNameExtern(const char* name)
{
  return (CFG_TextCategoryName)(ATerm)ATmakeAppl1(CFG_afun26, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}

/*}}}  */
/*{{{  CFG_TextAttributes CFG_makeTextAttributesEmpty(void) */

CFG_TextAttributes CFG_makeTextAttributesEmpty(void)
{
  return (CFG_TextAttributes)(ATerm)ATempty;
}

/*}}}  */
/*{{{  CFG_TextAttributes CFG_makeTextAttributesSingle(CFG_TextAttribute head) */

CFG_TextAttributes CFG_makeTextAttributesSingle(CFG_TextAttribute head)
{
  return (CFG_TextAttributes)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  CFG_TextAttributes CFG_makeTextAttributesMany(CFG_TextAttribute head, CFG_TextAttributes tail) */

CFG_TextAttributes CFG_makeTextAttributesMany(CFG_TextAttribute head, CFG_TextAttributes tail)
{
  return (CFG_TextAttributes)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  CFG_TextAttribute CFG_makeTextAttributeForegroundColor(CFG_Color color) */

CFG_TextAttribute CFG_makeTextAttributeForegroundColor(CFG_Color color)
{
  return (CFG_TextAttribute)(ATerm)ATmakeAppl1(CFG_afun27, (ATerm) color);
}

/*}}}  */
/*{{{  CFG_TextAttribute CFG_makeTextAttributeBackgroundColor(CFG_Color color) */

CFG_TextAttribute CFG_makeTextAttributeBackgroundColor(CFG_Color color)
{
  return (CFG_TextAttribute)(ATerm)ATmakeAppl1(CFG_afun28, (ATerm) color);
}

/*}}}  */
/*{{{  CFG_TextAttribute CFG_makeTextAttributeStyle(CFG_TextStyle style) */

CFG_TextAttribute CFG_makeTextAttributeStyle(CFG_TextStyle style)
{
  return (CFG_TextAttribute)(ATerm)ATmakeAppl1(CFG_afun29, (ATerm) style);
}

/*}}}  */
/*{{{  CFG_TextAttribute CFG_makeTextAttributeFont(const char* name) */

CFG_TextAttribute CFG_makeTextAttributeFont(const char* name)
{
  return (CFG_TextAttribute)(ATerm)ATmakeAppl1(CFG_afun30, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}

/*}}}  */
/*{{{  CFG_TextAttribute CFG_makeTextAttributeSize(int points) */

CFG_TextAttribute CFG_makeTextAttributeSize(int points)
{
  return (CFG_TextAttribute)(ATerm)ATmakeAppl1(CFG_afun31, (ATerm) (ATerm) ATmakeInt(points));
}

/*}}}  */
/*{{{  CFG_TextStyle CFG_makeTextStyleBold(void) */

CFG_TextStyle CFG_makeTextStyleBold(void)
{
  return (CFG_TextStyle)(ATerm)ATmakeAppl0(CFG_afun32);
}

/*}}}  */
/*{{{  CFG_TextStyle CFG_makeTextStyleItalics(void) */

CFG_TextStyle CFG_makeTextStyleItalics(void)
{
  return (CFG_TextStyle)(ATerm)ATmakeAppl0(CFG_afun33);
}

/*}}}  */
/*{{{  CFG_TextStyle CFG_makeTextStyleUnderlined(void) */

CFG_TextStyle CFG_makeTextStyleUnderlined(void)
{
  return (CFG_TextStyle)(ATerm)ATmakeAppl0(CFG_afun34);
}

/*}}}  */
/*{{{  CFG_Color CFG_makeColorRgb(int red, int green, int blue) */

CFG_Color CFG_makeColorRgb(int red, int green, int blue)
{
  return (CFG_Color)(ATerm)ATmakeAppl3(CFG_afun35, (ATerm) (ATerm) ATmakeInt(red), (ATerm) (ATerm) ATmakeInt(green), (ATerm) (ATerm) ATmakeInt(blue));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool CFG_isEqualConfiguration(CFG_Configuration arg0, CFG_Configuration arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualProperties(CFG_Properties arg0, CFG_Properties arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualProperty(CFG_Property arg0, CFG_Property arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualActionDescription(CFG_ActionDescription arg0, CFG_ActionDescription arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualActionDescriptionList(CFG_ActionDescriptionList arg0, CFG_ActionDescriptionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualActionType(CFG_ActionType arg0, CFG_ActionType arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualEvent(CFG_Event arg0, CFG_Event arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualItems(CFG_Items arg0, CFG_Items arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualModuleName(CFG_ModuleName arg0, CFG_ModuleName arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualTextCategoryName(CFG_TextCategoryName arg0, CFG_TextCategoryName arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualTextAttributes(CFG_TextAttributes arg0, CFG_TextAttributes arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualTextAttribute(CFG_TextAttribute arg0, CFG_TextAttribute arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualTextStyle(CFG_TextStyle arg0, CFG_TextStyle arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualColor(CFG_Color arg0, CFG_Color arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  CFG_Configuration accessors */

/*{{{  ATbool CFG_isValidConfiguration(CFG_Configuration arg) */

ATbool CFG_isValidConfiguration(CFG_Configuration arg)
{
  if (CFG_isConfigurationImport(arg)) {
    return ATtrue;
  }
  else if (CFG_isConfigurationList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CFG_isConfigurationImport(CFG_Configuration arg) */

inline ATbool CFG_isConfigurationImport(CFG_Configuration arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternConfigurationImport, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isConfigurationList(CFG_Configuration arg) */

inline ATbool CFG_isConfigurationList(CFG_Configuration arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternConfigurationList, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CFG_hasConfigurationPath(CFG_Configuration arg) */

ATbool CFG_hasConfigurationPath(CFG_Configuration arg)
{
  if (CFG_isConfigurationImport(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasConfigurationList(CFG_Configuration arg) */

ATbool CFG_hasConfigurationList(CFG_Configuration arg)
{
  if (CFG_isConfigurationList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* CFG_getConfigurationPath(CFG_Configuration arg) */

char* CFG_getConfigurationPath(CFG_Configuration arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  CFG_Properties CFG_getConfigurationList(CFG_Configuration arg) */

CFG_Properties CFG_getConfigurationList(CFG_Configuration arg)
{
  
    return (CFG_Properties)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  CFG_Configuration CFG_setConfigurationPath(CFG_Configuration arg, const char* path) */

CFG_Configuration CFG_setConfigurationPath(CFG_Configuration arg, const char* path)
{
  if (CFG_isConfigurationImport(arg)) {
    return (CFG_Configuration)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 0);
  }

  ATabort("Configuration has no Path: %t\n", arg);
  return (CFG_Configuration)NULL;
}

/*}}}  */
/*{{{  CFG_Configuration CFG_setConfigurationList(CFG_Configuration arg, CFG_Properties list) */

CFG_Configuration CFG_setConfigurationList(CFG_Configuration arg, CFG_Properties list)
{
  if (CFG_isConfigurationList(arg)) {
    return (CFG_Configuration)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }

  ATabort("Configuration has no List: %t\n", arg);
  return (CFG_Configuration)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CFG_Properties accessors */

/*{{{  ATbool CFG_isValidProperties(CFG_Properties arg) */

ATbool CFG_isValidProperties(CFG_Properties arg)
{
  if (CFG_isPropertiesEmpty(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertiesSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertiesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CFG_isPropertiesEmpty(CFG_Properties arg) */

inline ATbool CFG_isPropertiesEmpty(CFG_Properties arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternPropertiesEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool CFG_isPropertiesSingle(CFG_Properties arg) */

inline ATbool CFG_isPropertiesSingle(CFG_Properties arg)
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
      last_result = ATmatchTerm((ATerm)arg, CFG_patternPropertiesSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isPropertiesMany(CFG_Properties arg) */

inline ATbool CFG_isPropertiesMany(CFG_Properties arg)
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
      last_result = ATmatchTerm((ATerm)arg, CFG_patternPropertiesMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CFG_hasPropertiesHead(CFG_Properties arg) */

ATbool CFG_hasPropertiesHead(CFG_Properties arg)
{
  if (CFG_isPropertiesSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertiesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasPropertiesTail(CFG_Properties arg) */

ATbool CFG_hasPropertiesTail(CFG_Properties arg)
{
  if (CFG_isPropertiesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CFG_Property CFG_getPropertiesHead(CFG_Properties arg) */

CFG_Property CFG_getPropertiesHead(CFG_Properties arg)
{
  if (CFG_isPropertiesSingle(arg)) {
    return (CFG_Property)ATgetFirst((ATermList)arg);
  }
  else 
    return (CFG_Property)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  CFG_Properties CFG_getPropertiesTail(CFG_Properties arg) */

CFG_Properties CFG_getPropertiesTail(CFG_Properties arg)
{
  
    return (CFG_Properties)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  CFG_Properties CFG_setPropertiesHead(CFG_Properties arg, CFG_Property head) */

CFG_Properties CFG_setPropertiesHead(CFG_Properties arg, CFG_Property head)
{
  if (CFG_isPropertiesSingle(arg)) {
    return (CFG_Properties)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CFG_isPropertiesMany(arg)) {
    return (CFG_Properties)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Properties has no Head: %t\n", arg);
  return (CFG_Properties)NULL;
}

/*}}}  */
/*{{{  CFG_Properties CFG_setPropertiesTail(CFG_Properties arg, CFG_Properties tail) */

CFG_Properties CFG_setPropertiesTail(CFG_Properties arg, CFG_Properties tail)
{
  if (CFG_isPropertiesMany(arg)) {
    return (CFG_Properties)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Properties has no Tail: %t\n", arg);
  return (CFG_Properties)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CFG_Property accessors */

/*{{{  ATbool CFG_isValidProperty(CFG_Property arg) */

ATbool CFG_isValidProperty(CFG_Property arg)
{
  if (CFG_isPropertyAction(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyExtension(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyLibraryPath(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyModulePath(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyTextCategory(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CFG_isPropertyAction(CFG_Property arg) */

inline ATbool CFG_isPropertyAction(CFG_Property arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternPropertyAction, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isPropertyExtension(CFG_Property arg) */

inline ATbool CFG_isPropertyExtension(CFG_Property arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternPropertyExtension, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isPropertyLibraryPath(CFG_Property arg) */

inline ATbool CFG_isPropertyLibraryPath(CFG_Property arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternPropertyLibraryPath, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isPropertyModulePath(CFG_Property arg) */

inline ATbool CFG_isPropertyModulePath(CFG_Property arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternPropertyModulePath, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isPropertyTextCategory(CFG_Property arg) */

inline ATbool CFG_isPropertyTextCategory(CFG_Property arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternPropertyTextCategory, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CFG_hasPropertyDescriptions(CFG_Property arg) */

ATbool CFG_hasPropertyDescriptions(CFG_Property arg)
{
  if (CFG_isPropertyAction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasPropertyAction(CFG_Property arg) */

ATbool CFG_hasPropertyAction(CFG_Property arg)
{
  if (CFG_isPropertyAction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasPropertyLanguage(CFG_Property arg) */

ATbool CFG_hasPropertyLanguage(CFG_Property arg)
{
  if (CFG_isPropertyExtension(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasPropertyExtension(CFG_Property arg) */

ATbool CFG_hasPropertyExtension(CFG_Property arg)
{
  if (CFG_isPropertyExtension(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasPropertyLabel(CFG_Property arg) */

ATbool CFG_hasPropertyLabel(CFG_Property arg)
{
  if (CFG_isPropertyLibraryPath(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyModulePath(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasPropertyPath(CFG_Property arg) */

ATbool CFG_hasPropertyPath(CFG_Property arg)
{
  if (CFG_isPropertyLibraryPath(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyModulePath(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasPropertyCategory(CFG_Property arg) */

ATbool CFG_hasPropertyCategory(CFG_Property arg)
{
  if (CFG_isPropertyTextCategory(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasPropertyAttributes(CFG_Property arg) */

ATbool CFG_hasPropertyAttributes(CFG_Property arg)
{
  if (CFG_isPropertyTextCategory(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CFG_ActionDescriptionList CFG_getPropertyDescriptions(CFG_Property arg) */

CFG_ActionDescriptionList CFG_getPropertyDescriptions(CFG_Property arg)
{
  
    return (CFG_ActionDescriptionList)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  char* CFG_getPropertyAction(CFG_Property arg) */

char* CFG_getPropertyAction(CFG_Property arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  char* CFG_getPropertyLanguage(CFG_Property arg) */

char* CFG_getPropertyLanguage(CFG_Property arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  char* CFG_getPropertyExtension(CFG_Property arg) */

char* CFG_getPropertyExtension(CFG_Property arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  char* CFG_getPropertyLabel(CFG_Property arg) */

char* CFG_getPropertyLabel(CFG_Property arg)
{
  if (CFG_isPropertyLibraryPath(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  char* CFG_getPropertyPath(CFG_Property arg) */

char* CFG_getPropertyPath(CFG_Property arg)
{
  if (CFG_isPropertyLibraryPath(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  CFG_TextCategoryName CFG_getPropertyCategory(CFG_Property arg) */

CFG_TextCategoryName CFG_getPropertyCategory(CFG_Property arg)
{
  
    return (CFG_TextCategoryName)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  CFG_TextAttributes CFG_getPropertyAttributes(CFG_Property arg) */

CFG_TextAttributes CFG_getPropertyAttributes(CFG_Property arg)
{
  
    return (CFG_TextAttributes)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  CFG_Property CFG_setPropertyDescriptions(CFG_Property arg, CFG_ActionDescriptionList descriptions) */

CFG_Property CFG_setPropertyDescriptions(CFG_Property arg, CFG_ActionDescriptionList descriptions)
{
  if (CFG_isPropertyAction(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) descriptions), 0);
  }

  ATabort("Property has no Descriptions: %t\n", arg);
  return (CFG_Property)NULL;
}

/*}}}  */
/*{{{  CFG_Property CFG_setPropertyAction(CFG_Property arg, const char* action) */

CFG_Property CFG_setPropertyAction(CFG_Property arg, const char* action)
{
  if (CFG_isPropertyAction(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(action, 0, ATtrue))), 1);
  }

  ATabort("Property has no Action: %t\n", arg);
  return (CFG_Property)NULL;
}

/*}}}  */
/*{{{  CFG_Property CFG_setPropertyLanguage(CFG_Property arg, const char* language) */

CFG_Property CFG_setPropertyLanguage(CFG_Property arg, const char* language)
{
  if (CFG_isPropertyExtension(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(language, 0, ATtrue))), 0);
  }

  ATabort("Property has no Language: %t\n", arg);
  return (CFG_Property)NULL;
}

/*}}}  */
/*{{{  CFG_Property CFG_setPropertyExtension(CFG_Property arg, const char* extension) */

CFG_Property CFG_setPropertyExtension(CFG_Property arg, const char* extension)
{
  if (CFG_isPropertyExtension(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(extension, 0, ATtrue))), 1);
  }

  ATabort("Property has no Extension: %t\n", arg);
  return (CFG_Property)NULL;
}

/*}}}  */
/*{{{  CFG_Property CFG_setPropertyLabel(CFG_Property arg, const char* label) */

CFG_Property CFG_setPropertyLabel(CFG_Property arg, const char* label)
{
  if (CFG_isPropertyLibraryPath(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(label, 0, ATtrue))), 0);
  }
  else if (CFG_isPropertyModulePath(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(label, 0, ATtrue))), 0);
  }

  ATabort("Property has no Label: %t\n", arg);
  return (CFG_Property)NULL;
}

/*}}}  */
/*{{{  CFG_Property CFG_setPropertyPath(CFG_Property arg, const char* path) */

CFG_Property CFG_setPropertyPath(CFG_Property arg, const char* path)
{
  if (CFG_isPropertyLibraryPath(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 1);
  }
  else if (CFG_isPropertyModulePath(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 1);
  }

  ATabort("Property has no Path: %t\n", arg);
  return (CFG_Property)NULL;
}

/*}}}  */
/*{{{  CFG_Property CFG_setPropertyCategory(CFG_Property arg, CFG_TextCategoryName category) */

CFG_Property CFG_setPropertyCategory(CFG_Property arg, CFG_TextCategoryName category)
{
  if (CFG_isPropertyTextCategory(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) category), 0);
  }

  ATabort("Property has no Category: %t\n", arg);
  return (CFG_Property)NULL;
}

/*}}}  */
/*{{{  CFG_Property CFG_setPropertyAttributes(CFG_Property arg, CFG_TextAttributes attributes) */

CFG_Property CFG_setPropertyAttributes(CFG_Property arg, CFG_TextAttributes attributes)
{
  if (CFG_isPropertyTextCategory(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) attributes), 1);
  }

  ATabort("Property has no Attributes: %t\n", arg);
  return (CFG_Property)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CFG_ActionDescription accessors */

/*{{{  ATbool CFG_isValidActionDescription(CFG_ActionDescription arg) */

ATbool CFG_isValidActionDescription(CFG_ActionDescription arg)
{
  if (CFG_isActionDescriptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CFG_isActionDescriptionDefault(CFG_ActionDescription arg) */

inline ATbool CFG_isActionDescriptionDefault(CFG_ActionDescription arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternActionDescriptionDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CFG_hasActionDescriptionActionType(CFG_ActionDescription arg) */

ATbool CFG_hasActionDescriptionActionType(CFG_ActionDescription arg)
{
  if (CFG_isActionDescriptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasActionDescriptionEvent(CFG_ActionDescription arg) */

ATbool CFG_hasActionDescriptionEvent(CFG_ActionDescription arg)
{
  if (CFG_isActionDescriptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CFG_ActionType CFG_getActionDescriptionActionType(CFG_ActionDescription arg) */

CFG_ActionType CFG_getActionDescriptionActionType(CFG_ActionDescription arg)
{
  
    return (CFG_ActionType)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  CFG_Event CFG_getActionDescriptionEvent(CFG_ActionDescription arg) */

CFG_Event CFG_getActionDescriptionEvent(CFG_ActionDescription arg)
{
  
    return (CFG_Event)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  CFG_ActionDescription CFG_setActionDescriptionActionType(CFG_ActionDescription arg, CFG_ActionType actionType) */

CFG_ActionDescription CFG_setActionDescriptionActionType(CFG_ActionDescription arg, CFG_ActionType actionType)
{
  if (CFG_isActionDescriptionDefault(arg)) {
    return (CFG_ActionDescription)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) actionType), 0);
  }

  ATabort("ActionDescription has no ActionType: %t\n", arg);
  return (CFG_ActionDescription)NULL;
}

/*}}}  */
/*{{{  CFG_ActionDescription CFG_setActionDescriptionEvent(CFG_ActionDescription arg, CFG_Event event) */

CFG_ActionDescription CFG_setActionDescriptionEvent(CFG_ActionDescription arg, CFG_Event event)
{
  if (CFG_isActionDescriptionDefault(arg)) {
    return (CFG_ActionDescription)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) event), 1);
  }

  ATabort("ActionDescription has no Event: %t\n", arg);
  return (CFG_ActionDescription)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CFG_ActionDescriptionList accessors */

/*{{{  ATbool CFG_isValidActionDescriptionList(CFG_ActionDescriptionList arg) */

ATbool CFG_isValidActionDescriptionList(CFG_ActionDescriptionList arg)
{
  if (CFG_isActionDescriptionListEmpty(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionDescriptionListSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CFG_isActionDescriptionListEmpty(CFG_ActionDescriptionList arg) */

inline ATbool CFG_isActionDescriptionListEmpty(CFG_ActionDescriptionList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternActionDescriptionListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool CFG_isActionDescriptionListSingle(CFG_ActionDescriptionList arg) */

inline ATbool CFG_isActionDescriptionListSingle(CFG_ActionDescriptionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, CFG_patternActionDescriptionListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isActionDescriptionListMany(CFG_ActionDescriptionList arg) */

inline ATbool CFG_isActionDescriptionListMany(CFG_ActionDescriptionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, CFG_patternActionDescriptionListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CFG_hasActionDescriptionListHead(CFG_ActionDescriptionList arg) */

ATbool CFG_hasActionDescriptionListHead(CFG_ActionDescriptionList arg)
{
  if (CFG_isActionDescriptionListSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasActionDescriptionListTail(CFG_ActionDescriptionList arg) */

ATbool CFG_hasActionDescriptionListTail(CFG_ActionDescriptionList arg)
{
  if (CFG_isActionDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CFG_ActionDescription CFG_getActionDescriptionListHead(CFG_ActionDescriptionList arg) */

CFG_ActionDescription CFG_getActionDescriptionListHead(CFG_ActionDescriptionList arg)
{
  if (CFG_isActionDescriptionListSingle(arg)) {
    return (CFG_ActionDescription)ATgetFirst((ATermList)arg);
  }
  else 
    return (CFG_ActionDescription)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  CFG_ActionDescriptionList CFG_getActionDescriptionListTail(CFG_ActionDescriptionList arg) */

CFG_ActionDescriptionList CFG_getActionDescriptionListTail(CFG_ActionDescriptionList arg)
{
  
    return (CFG_ActionDescriptionList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  CFG_ActionDescriptionList CFG_setActionDescriptionListHead(CFG_ActionDescriptionList arg, CFG_ActionDescription head) */

CFG_ActionDescriptionList CFG_setActionDescriptionListHead(CFG_ActionDescriptionList arg, CFG_ActionDescription head)
{
  if (CFG_isActionDescriptionListSingle(arg)) {
    return (CFG_ActionDescriptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CFG_isActionDescriptionListMany(arg)) {
    return (CFG_ActionDescriptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ActionDescriptionList has no Head: %t\n", arg);
  return (CFG_ActionDescriptionList)NULL;
}

/*}}}  */
/*{{{  CFG_ActionDescriptionList CFG_setActionDescriptionListTail(CFG_ActionDescriptionList arg, CFG_ActionDescriptionList tail) */

CFG_ActionDescriptionList CFG_setActionDescriptionListTail(CFG_ActionDescriptionList arg, CFG_ActionDescriptionList tail)
{
  if (CFG_isActionDescriptionListMany(arg)) {
    return (CFG_ActionDescriptionList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("ActionDescriptionList has no Tail: %t\n", arg);
  return (CFG_ActionDescriptionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CFG_ActionType accessors */

/*{{{  ATbool CFG_isValidActionType(CFG_ActionType arg) */

ATbool CFG_isValidActionType(CFG_ActionType arg)
{
  if (CFG_isActionTypeTermEditor(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionTypeTermEditorForModule(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionTypeEquationsEditor(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionTypeSyntaxEditor(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionTypeFeedbackList(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionTypeTreePanel(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionTypeModulePopup(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionTypeNewModulePopup(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionTypeStudioMenubar(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionTypeStudioToolbar(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionTypeWildcard(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CFG_isActionTypeTermEditor(CFG_ActionType arg) */

inline ATbool CFG_isActionTypeTermEditor(CFG_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternActionTypeTermEditor);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isActionTypeTermEditorForModule(CFG_ActionType arg) */

inline ATbool CFG_isActionTypeTermEditorForModule(CFG_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternActionTypeTermEditorForModule, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isActionTypeEquationsEditor(CFG_ActionType arg) */

inline ATbool CFG_isActionTypeEquationsEditor(CFG_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternActionTypeEquationsEditor);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isActionTypeSyntaxEditor(CFG_ActionType arg) */

inline ATbool CFG_isActionTypeSyntaxEditor(CFG_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternActionTypeSyntaxEditor);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isActionTypeFeedbackList(CFG_ActionType arg) */

inline ATbool CFG_isActionTypeFeedbackList(CFG_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternActionTypeFeedbackList);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isActionTypeTreePanel(CFG_ActionType arg) */

inline ATbool CFG_isActionTypeTreePanel(CFG_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternActionTypeTreePanel);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isActionTypeModulePopup(CFG_ActionType arg) */

inline ATbool CFG_isActionTypeModulePopup(CFG_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternActionTypeModulePopup, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isActionTypeNewModulePopup(CFG_ActionType arg) */

inline ATbool CFG_isActionTypeNewModulePopup(CFG_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternActionTypeNewModulePopup);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isActionTypeStudioMenubar(CFG_ActionType arg) */

inline ATbool CFG_isActionTypeStudioMenubar(CFG_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternActionTypeStudioMenubar);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isActionTypeStudioToolbar(CFG_ActionType arg) */

inline ATbool CFG_isActionTypeStudioToolbar(CFG_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternActionTypeStudioToolbar);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isActionTypeWildcard(CFG_ActionType arg) */

inline ATbool CFG_isActionTypeWildcard(CFG_ActionType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternActionTypeWildcard);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CFG_hasActionTypeModuleId(CFG_ActionType arg) */

ATbool CFG_hasActionTypeModuleId(CFG_ActionType arg)
{
  if (CFG_isActionTypeTermEditorForModule(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionTypeModulePopup(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* CFG_getActionTypeModuleId(CFG_ActionType arg) */

char* CFG_getActionTypeModuleId(CFG_ActionType arg)
{
  if (CFG_isActionTypeTermEditorForModule(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  CFG_ActionType CFG_setActionTypeModuleId(CFG_ActionType arg, const char* moduleId) */

CFG_ActionType CFG_setActionTypeModuleId(CFG_ActionType arg, const char* moduleId)
{
  if (CFG_isActionTypeTermEditorForModule(arg)) {
    return (CFG_ActionType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(moduleId, 0, ATtrue))), 0);
  }
  else if (CFG_isActionTypeModulePopup(arg)) {
    return (CFG_ActionType)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(moduleId, 0, ATtrue))), 0);
  }

  ATabort("ActionType has no ModuleId: %t\n", arg);
  return (CFG_ActionType)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CFG_Event accessors */

/*{{{  ATbool CFG_isValidEvent(CFG_Event arg) */

ATbool CFG_isValidEvent(CFG_Event arg)
{
  if (CFG_isEventClick(arg)) {
    return ATtrue;
  }
  else if (CFG_isEventIcon(arg)) {
    return ATtrue;
  }
  else if (CFG_isEventDefault(arg)) {
    return ATtrue;
  }
  else if (CFG_isEventShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CFG_isEventClick(CFG_Event arg) */

inline ATbool CFG_isEventClick(CFG_Event arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternEventClick);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isEventIcon(CFG_Event arg) */

inline ATbool CFG_isEventIcon(CFG_Event arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternEventIcon, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isEventDefault(CFG_Event arg) */

inline ATbool CFG_isEventDefault(CFG_Event arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternEventDefault, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isEventShortcut(CFG_Event arg) */

inline ATbool CFG_isEventShortcut(CFG_Event arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternEventShortcut, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CFG_hasEventTitle(CFG_Event arg) */

ATbool CFG_hasEventTitle(CFG_Event arg)
{
  if (CFG_isEventIcon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasEventPath(CFG_Event arg) */

ATbool CFG_hasEventPath(CFG_Event arg)
{
  if (CFG_isEventIcon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasEventItems(CFG_Event arg) */

ATbool CFG_hasEventItems(CFG_Event arg)
{
  if (CFG_isEventDefault(arg)) {
    return ATtrue;
  }
  else if (CFG_isEventShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasEventShortcut(CFG_Event arg) */

ATbool CFG_hasEventShortcut(CFG_Event arg)
{
  if (CFG_isEventShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* CFG_getEventTitle(CFG_Event arg) */

char* CFG_getEventTitle(CFG_Event arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  char* CFG_getEventPath(CFG_Event arg) */

char* CFG_getEventPath(CFG_Event arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  CFG_Items CFG_getEventItems(CFG_Event arg) */

CFG_Items CFG_getEventItems(CFG_Event arg)
{
  if (CFG_isEventDefault(arg)) {
    return (CFG_Items)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (CFG_Items)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  char* CFG_getEventShortcut(CFG_Event arg) */

char* CFG_getEventShortcut(CFG_Event arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  CFG_Event CFG_setEventTitle(CFG_Event arg, const char* title) */

CFG_Event CFG_setEventTitle(CFG_Event arg, const char* title)
{
  if (CFG_isEventIcon(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(title, 0, ATtrue))), 0);
  }

  ATabort("Event has no Title: %t\n", arg);
  return (CFG_Event)NULL;
}

/*}}}  */
/*{{{  CFG_Event CFG_setEventPath(CFG_Event arg, const char* path) */

CFG_Event CFG_setEventPath(CFG_Event arg, const char* path)
{
  if (CFG_isEventIcon(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 1);
  }

  ATabort("Event has no Path: %t\n", arg);
  return (CFG_Event)NULL;
}

/*}}}  */
/*{{{  CFG_Event CFG_setEventItems(CFG_Event arg, CFG_Items items) */

CFG_Event CFG_setEventItems(CFG_Event arg, CFG_Items items)
{
  if (CFG_isEventDefault(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) items), 0);
  }
  else if (CFG_isEventShortcut(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) items), 0);
  }

  ATabort("Event has no Items: %t\n", arg);
  return (CFG_Event)NULL;
}

/*}}}  */
/*{{{  CFG_Event CFG_setEventShortcut(CFG_Event arg, const char* shortcut) */

CFG_Event CFG_setEventShortcut(CFG_Event arg, const char* shortcut)
{
  if (CFG_isEventShortcut(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(shortcut, 0, ATtrue))), 1);
  }

  ATabort("Event has no Shortcut: %t\n", arg);
  return (CFG_Event)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CFG_Items accessors */

/*{{{  ATbool CFG_isValidItems(CFG_Items arg) */

ATbool CFG_isValidItems(CFG_Items arg)
{
  if (CFG_isItemsEmpty(arg)) {
    return ATtrue;
  }
  else if (CFG_isItemsSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isItemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CFG_isItemsEmpty(CFG_Items arg) */

inline ATbool CFG_isItemsEmpty(CFG_Items arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternItemsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool CFG_isItemsSingle(CFG_Items arg) */

inline ATbool CFG_isItemsSingle(CFG_Items arg)
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
      last_result = ATmatchTerm((ATerm)arg, CFG_patternItemsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isItemsMany(CFG_Items arg) */

inline ATbool CFG_isItemsMany(CFG_Items arg)
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
      last_result = ATmatchTerm((ATerm)arg, CFG_patternItemsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CFG_hasItemsHead(CFG_Items arg) */

ATbool CFG_hasItemsHead(CFG_Items arg)
{
  if (CFG_isItemsSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isItemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasItemsTail(CFG_Items arg) */

ATbool CFG_hasItemsTail(CFG_Items arg)
{
  if (CFG_isItemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* CFG_getItemsHead(CFG_Items arg) */

char* CFG_getItemsHead(CFG_Items arg)
{
  if (CFG_isItemsSingle(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetFirst((ATermList)arg)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetFirst((ATermList)arg)));
}

/*}}}  */
/*{{{  CFG_Items CFG_getItemsTail(CFG_Items arg) */

CFG_Items CFG_getItemsTail(CFG_Items arg)
{
  
    return (CFG_Items)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  CFG_Items CFG_setItemsHead(CFG_Items arg, const char* head) */

CFG_Items CFG_setItemsHead(CFG_Items arg, const char* head)
{
  if (CFG_isItemsSingle(arg)) {
    return (CFG_Items)ATreplace((ATermList)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(head, 0, ATtrue))), 0);
  }
  else if (CFG_isItemsMany(arg)) {
    return (CFG_Items)ATreplace((ATermList)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(head, 0, ATtrue))), 0);
  }

  ATabort("Items has no Head: %t\n", arg);
  return (CFG_Items)NULL;
}

/*}}}  */
/*{{{  CFG_Items CFG_setItemsTail(CFG_Items arg, CFG_Items tail) */

CFG_Items CFG_setItemsTail(CFG_Items arg, CFG_Items tail)
{
  if (CFG_isItemsMany(arg)) {
    return (CFG_Items)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Items has no Tail: %t\n", arg);
  return (CFG_Items)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CFG_ModuleName accessors */

/*{{{  ATbool CFG_isValidModuleName(CFG_ModuleName arg) */

ATbool CFG_isValidModuleName(CFG_ModuleName arg)
{
  if (CFG_isModuleNameWildcard(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CFG_isModuleNameWildcard(CFG_ModuleName arg) */

inline ATbool CFG_isModuleNameWildcard(CFG_ModuleName arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternModuleNameWildcard));
#endif
  return ATtrue;
}

/*}}}  */

/*}}}  */
/*{{{  CFG_TextCategoryName accessors */

/*{{{  ATbool CFG_isValidTextCategoryName(CFG_TextCategoryName arg) */

ATbool CFG_isValidTextCategoryName(CFG_TextCategoryName arg)
{
  if (CFG_isTextCategoryNameFocus(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextCategoryNameSelection(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextCategoryNameNormal(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextCategoryNameExtern(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CFG_isTextCategoryNameFocus(CFG_TextCategoryName arg) */

inline ATbool CFG_isTextCategoryNameFocus(CFG_TextCategoryName arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextCategoryNameFocus);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isTextCategoryNameSelection(CFG_TextCategoryName arg) */

inline ATbool CFG_isTextCategoryNameSelection(CFG_TextCategoryName arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextCategoryNameSelection);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isTextCategoryNameNormal(CFG_TextCategoryName arg) */

inline ATbool CFG_isTextCategoryNameNormal(CFG_TextCategoryName arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextCategoryNameNormal);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isTextCategoryNameExtern(CFG_TextCategoryName arg) */

inline ATbool CFG_isTextCategoryNameExtern(CFG_TextCategoryName arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextCategoryNameExtern, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CFG_hasTextCategoryNameName(CFG_TextCategoryName arg) */

ATbool CFG_hasTextCategoryNameName(CFG_TextCategoryName arg)
{
  if (CFG_isTextCategoryNameExtern(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* CFG_getTextCategoryNameName(CFG_TextCategoryName arg) */

char* CFG_getTextCategoryNameName(CFG_TextCategoryName arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  CFG_TextCategoryName CFG_setTextCategoryNameName(CFG_TextCategoryName arg, const char* name) */

CFG_TextCategoryName CFG_setTextCategoryNameName(CFG_TextCategoryName arg, const char* name)
{
  if (CFG_isTextCategoryNameExtern(arg)) {
    return (CFG_TextCategoryName)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("TextCategoryName has no Name: %t\n", arg);
  return (CFG_TextCategoryName)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CFG_TextAttributes accessors */

/*{{{  ATbool CFG_isValidTextAttributes(CFG_TextAttributes arg) */

ATbool CFG_isValidTextAttributes(CFG_TextAttributes arg)
{
  if (CFG_isTextAttributesEmpty(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextAttributesSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CFG_isTextAttributesEmpty(CFG_TextAttributes arg) */

inline ATbool CFG_isTextAttributesEmpty(CFG_TextAttributes arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternTextAttributesEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool CFG_isTextAttributesSingle(CFG_TextAttributes arg) */

inline ATbool CFG_isTextAttributesSingle(CFG_TextAttributes arg)
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
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextAttributesSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isTextAttributesMany(CFG_TextAttributes arg) */

inline ATbool CFG_isTextAttributesMany(CFG_TextAttributes arg)
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
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextAttributesMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CFG_hasTextAttributesHead(CFG_TextAttributes arg) */

ATbool CFG_hasTextAttributesHead(CFG_TextAttributes arg)
{
  if (CFG_isTextAttributesSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasTextAttributesTail(CFG_TextAttributes arg) */

ATbool CFG_hasTextAttributesTail(CFG_TextAttributes arg)
{
  if (CFG_isTextAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CFG_TextAttribute CFG_getTextAttributesHead(CFG_TextAttributes arg) */

CFG_TextAttribute CFG_getTextAttributesHead(CFG_TextAttributes arg)
{
  if (CFG_isTextAttributesSingle(arg)) {
    return (CFG_TextAttribute)ATgetFirst((ATermList)arg);
  }
  else 
    return (CFG_TextAttribute)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  CFG_TextAttributes CFG_getTextAttributesTail(CFG_TextAttributes arg) */

CFG_TextAttributes CFG_getTextAttributesTail(CFG_TextAttributes arg)
{
  
    return (CFG_TextAttributes)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  CFG_TextAttributes CFG_setTextAttributesHead(CFG_TextAttributes arg, CFG_TextAttribute head) */

CFG_TextAttributes CFG_setTextAttributesHead(CFG_TextAttributes arg, CFG_TextAttribute head)
{
  if (CFG_isTextAttributesSingle(arg)) {
    return (CFG_TextAttributes)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CFG_isTextAttributesMany(arg)) {
    return (CFG_TextAttributes)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("TextAttributes has no Head: %t\n", arg);
  return (CFG_TextAttributes)NULL;
}

/*}}}  */
/*{{{  CFG_TextAttributes CFG_setTextAttributesTail(CFG_TextAttributes arg, CFG_TextAttributes tail) */

CFG_TextAttributes CFG_setTextAttributesTail(CFG_TextAttributes arg, CFG_TextAttributes tail)
{
  if (CFG_isTextAttributesMany(arg)) {
    return (CFG_TextAttributes)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("TextAttributes has no Tail: %t\n", arg);
  return (CFG_TextAttributes)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CFG_TextAttribute accessors */

/*{{{  ATbool CFG_isValidTextAttribute(CFG_TextAttribute arg) */

ATbool CFG_isValidTextAttribute(CFG_TextAttribute arg)
{
  if (CFG_isTextAttributeForegroundColor(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextAttributeBackgroundColor(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextAttributeStyle(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextAttributeFont(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextAttributeSize(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CFG_isTextAttributeForegroundColor(CFG_TextAttribute arg) */

inline ATbool CFG_isTextAttributeForegroundColor(CFG_TextAttribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextAttributeForegroundColor, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isTextAttributeBackgroundColor(CFG_TextAttribute arg) */

inline ATbool CFG_isTextAttributeBackgroundColor(CFG_TextAttribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextAttributeBackgroundColor, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isTextAttributeStyle(CFG_TextAttribute arg) */

inline ATbool CFG_isTextAttributeStyle(CFG_TextAttribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextAttributeStyle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isTextAttributeFont(CFG_TextAttribute arg) */

inline ATbool CFG_isTextAttributeFont(CFG_TextAttribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextAttributeFont, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isTextAttributeSize(CFG_TextAttribute arg) */

inline ATbool CFG_isTextAttributeSize(CFG_TextAttribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextAttributeSize, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CFG_hasTextAttributeColor(CFG_TextAttribute arg) */

ATbool CFG_hasTextAttributeColor(CFG_TextAttribute arg)
{
  if (CFG_isTextAttributeForegroundColor(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextAttributeBackgroundColor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasTextAttributeStyle(CFG_TextAttribute arg) */

ATbool CFG_hasTextAttributeStyle(CFG_TextAttribute arg)
{
  if (CFG_isTextAttributeStyle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasTextAttributeName(CFG_TextAttribute arg) */

ATbool CFG_hasTextAttributeName(CFG_TextAttribute arg)
{
  if (CFG_isTextAttributeFont(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasTextAttributePoints(CFG_TextAttribute arg) */

ATbool CFG_hasTextAttributePoints(CFG_TextAttribute arg)
{
  if (CFG_isTextAttributeSize(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CFG_Color CFG_getTextAttributeColor(CFG_TextAttribute arg) */

CFG_Color CFG_getTextAttributeColor(CFG_TextAttribute arg)
{
  if (CFG_isTextAttributeForegroundColor(arg)) {
    return (CFG_Color)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (CFG_Color)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  CFG_TextStyle CFG_getTextAttributeStyle(CFG_TextAttribute arg) */

CFG_TextStyle CFG_getTextAttributeStyle(CFG_TextAttribute arg)
{
  
    return (CFG_TextStyle)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  char* CFG_getTextAttributeName(CFG_TextAttribute arg) */

char* CFG_getTextAttributeName(CFG_TextAttribute arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  int CFG_getTextAttributePoints(CFG_TextAttribute arg) */

int CFG_getTextAttributePoints(CFG_TextAttribute arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  CFG_TextAttribute CFG_setTextAttributeColor(CFG_TextAttribute arg, CFG_Color color) */

CFG_TextAttribute CFG_setTextAttributeColor(CFG_TextAttribute arg, CFG_Color color)
{
  if (CFG_isTextAttributeForegroundColor(arg)) {
    return (CFG_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) color), 0);
  }
  else if (CFG_isTextAttributeBackgroundColor(arg)) {
    return (CFG_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) color), 0);
  }

  ATabort("TextAttribute has no Color: %t\n", arg);
  return (CFG_TextAttribute)NULL;
}

/*}}}  */
/*{{{  CFG_TextAttribute CFG_setTextAttributeStyle(CFG_TextAttribute arg, CFG_TextStyle style) */

CFG_TextAttribute CFG_setTextAttributeStyle(CFG_TextAttribute arg, CFG_TextStyle style)
{
  if (CFG_isTextAttributeStyle(arg)) {
    return (CFG_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) style), 0);
  }

  ATabort("TextAttribute has no Style: %t\n", arg);
  return (CFG_TextAttribute)NULL;
}

/*}}}  */
/*{{{  CFG_TextAttribute CFG_setTextAttributeName(CFG_TextAttribute arg, const char* name) */

CFG_TextAttribute CFG_setTextAttributeName(CFG_TextAttribute arg, const char* name)
{
  if (CFG_isTextAttributeFont(arg)) {
    return (CFG_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("TextAttribute has no Name: %t\n", arg);
  return (CFG_TextAttribute)NULL;
}

/*}}}  */
/*{{{  CFG_TextAttribute CFG_setTextAttributePoints(CFG_TextAttribute arg, int points) */

CFG_TextAttribute CFG_setTextAttributePoints(CFG_TextAttribute arg, int points)
{
  if (CFG_isTextAttributeSize(arg)) {
    return (CFG_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(points)), 0);
  }

  ATabort("TextAttribute has no Points: %t\n", arg);
  return (CFG_TextAttribute)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CFG_TextStyle accessors */

/*{{{  ATbool CFG_isValidTextStyle(CFG_TextStyle arg) */

ATbool CFG_isValidTextStyle(CFG_TextStyle arg)
{
  if (CFG_isTextStyleBold(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextStyleItalics(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextStyleUnderlined(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CFG_isTextStyleBold(CFG_TextStyle arg) */

inline ATbool CFG_isTextStyleBold(CFG_TextStyle arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextStyleBold);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isTextStyleItalics(CFG_TextStyle arg) */

inline ATbool CFG_isTextStyleItalics(CFG_TextStyle arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextStyleItalics);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CFG_isTextStyleUnderlined(CFG_TextStyle arg) */

inline ATbool CFG_isTextStyleUnderlined(CFG_TextStyle arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextStyleUnderlined);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  CFG_Color accessors */

/*{{{  ATbool CFG_isValidColor(CFG_Color arg) */

ATbool CFG_isValidColor(CFG_Color arg)
{
  if (CFG_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CFG_isColorRgb(CFG_Color arg) */

inline ATbool CFG_isColorRgb(CFG_Color arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternColorRgb, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CFG_hasColorRed(CFG_Color arg) */

ATbool CFG_hasColorRed(CFG_Color arg)
{
  if (CFG_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasColorGreen(CFG_Color arg) */

ATbool CFG_hasColorGreen(CFG_Color arg)
{
  if (CFG_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CFG_hasColorBlue(CFG_Color arg) */

ATbool CFG_hasColorBlue(CFG_Color arg)
{
  if (CFG_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int CFG_getColorRed(CFG_Color arg) */

int CFG_getColorRed(CFG_Color arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  int CFG_getColorGreen(CFG_Color arg) */

int CFG_getColorGreen(CFG_Color arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  int CFG_getColorBlue(CFG_Color arg) */

int CFG_getColorBlue(CFG_Color arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  CFG_Color CFG_setColorRed(CFG_Color arg, int red) */

CFG_Color CFG_setColorRed(CFG_Color arg, int red)
{
  if (CFG_isColorRgb(arg)) {
    return (CFG_Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(red)), 0);
  }

  ATabort("Color has no Red: %t\n", arg);
  return (CFG_Color)NULL;
}

/*}}}  */
/*{{{  CFG_Color CFG_setColorGreen(CFG_Color arg, int green) */

CFG_Color CFG_setColorGreen(CFG_Color arg, int green)
{
  if (CFG_isColorRgb(arg)) {
    return (CFG_Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(green)), 1);
  }

  ATabort("Color has no Green: %t\n", arg);
  return (CFG_Color)NULL;
}

/*}}}  */
/*{{{  CFG_Color CFG_setColorBlue(CFG_Color arg, int blue) */

CFG_Color CFG_setColorBlue(CFG_Color arg, int blue)
{
  if (CFG_isColorRgb(arg)) {
    return (CFG_Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(blue)), 2);
  }

  ATabort("Color has no Blue: %t\n", arg);
  return (CFG_Color)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  CFG_Configuration CFG_visitConfiguration(CFG_Configuration arg, char* (*acceptPath)(char*), CFG_Properties (*acceptList)(CFG_Properties)) */

CFG_Configuration CFG_visitConfiguration(CFG_Configuration arg, char* (*acceptPath)(char*), CFG_Properties (*acceptList)(CFG_Properties))
{
  if (CFG_isConfigurationImport(arg)) {
    return CFG_makeConfigurationImport(
        acceptPath ? acceptPath(CFG_getConfigurationPath(arg)) : CFG_getConfigurationPath(arg));
  }
  if (CFG_isConfigurationList(arg)) {
    return CFG_makeConfigurationList(
        acceptList ? acceptList(CFG_getConfigurationList(arg)) : CFG_getConfigurationList(arg));
  }
  ATabort("not a Configuration: %t\n", arg);
  return (CFG_Configuration)NULL;
}

/*}}}  */
/*{{{  CFG_Properties CFG_visitProperties(CFG_Properties arg, CFG_Property (*acceptHead)(CFG_Property)) */

CFG_Properties CFG_visitProperties(CFG_Properties arg, CFG_Property (*acceptHead)(CFG_Property))
{
  if (CFG_isPropertiesEmpty(arg)) {
    return CFG_makePropertiesEmpty();
  }
  if (CFG_isPropertiesSingle(arg)) {
    return CFG_makePropertiesSingle(
        acceptHead ? acceptHead(CFG_getPropertiesHead(arg)) : CFG_getPropertiesHead(arg));
  }
  if (CFG_isPropertiesMany(arg)) {
    return CFG_makePropertiesMany(
        acceptHead ? acceptHead(CFG_getPropertiesHead(arg)) : CFG_getPropertiesHead(arg),
        CFG_visitProperties(CFG_getPropertiesTail(arg), acceptHead));
  }
  ATabort("not a Properties: %t\n", arg);
  return (CFG_Properties)NULL;
}

/*}}}  */
/*{{{  CFG_Property CFG_visitProperty(CFG_Property arg, CFG_ActionDescriptionList (*acceptDescriptions)(CFG_ActionDescriptionList), char* (*acceptAction)(char*), char* (*acceptLanguage)(char*), char* (*acceptExtension)(char*), char* (*acceptLabel)(char*), char* (*acceptPath)(char*), CFG_TextCategoryName (*acceptCategory)(CFG_TextCategoryName), CFG_TextAttributes (*acceptAttributes)(CFG_TextAttributes)) */

CFG_Property CFG_visitProperty(CFG_Property arg, CFG_ActionDescriptionList (*acceptDescriptions)(CFG_ActionDescriptionList), char* (*acceptAction)(char*), char* (*acceptLanguage)(char*), char* (*acceptExtension)(char*), char* (*acceptLabel)(char*), char* (*acceptPath)(char*), CFG_TextCategoryName (*acceptCategory)(CFG_TextCategoryName), CFG_TextAttributes (*acceptAttributes)(CFG_TextAttributes))
{
  if (CFG_isPropertyAction(arg)) {
    return CFG_makePropertyAction(
        acceptDescriptions ? acceptDescriptions(CFG_getPropertyDescriptions(arg)) : CFG_getPropertyDescriptions(arg),
        acceptAction ? acceptAction(CFG_getPropertyAction(arg)) : CFG_getPropertyAction(arg));
  }
  if (CFG_isPropertyExtension(arg)) {
    return CFG_makePropertyExtension(
        acceptLanguage ? acceptLanguage(CFG_getPropertyLanguage(arg)) : CFG_getPropertyLanguage(arg),
        acceptExtension ? acceptExtension(CFG_getPropertyExtension(arg)) : CFG_getPropertyExtension(arg));
  }
  if (CFG_isPropertyLibraryPath(arg)) {
    return CFG_makePropertyLibraryPath(
        acceptLabel ? acceptLabel(CFG_getPropertyLabel(arg)) : CFG_getPropertyLabel(arg),
        acceptPath ? acceptPath(CFG_getPropertyPath(arg)) : CFG_getPropertyPath(arg));
  }
  if (CFG_isPropertyModulePath(arg)) {
    return CFG_makePropertyModulePath(
        acceptLabel ? acceptLabel(CFG_getPropertyLabel(arg)) : CFG_getPropertyLabel(arg),
        acceptPath ? acceptPath(CFG_getPropertyPath(arg)) : CFG_getPropertyPath(arg));
  }
  if (CFG_isPropertyTextCategory(arg)) {
    return CFG_makePropertyTextCategory(
        acceptCategory ? acceptCategory(CFG_getPropertyCategory(arg)) : CFG_getPropertyCategory(arg),
        acceptAttributes ? acceptAttributes(CFG_getPropertyAttributes(arg)) : CFG_getPropertyAttributes(arg));
  }
  ATabort("not a Property: %t\n", arg);
  return (CFG_Property)NULL;
}

/*}}}  */
/*{{{  CFG_ActionDescription CFG_visitActionDescription(CFG_ActionDescription arg, CFG_ActionType (*acceptActionType)(CFG_ActionType), CFG_Event (*acceptEvent)(CFG_Event)) */

CFG_ActionDescription CFG_visitActionDescription(CFG_ActionDescription arg, CFG_ActionType (*acceptActionType)(CFG_ActionType), CFG_Event (*acceptEvent)(CFG_Event))
{
  if (CFG_isActionDescriptionDefault(arg)) {
    return CFG_makeActionDescriptionDefault(
        acceptActionType ? acceptActionType(CFG_getActionDescriptionActionType(arg)) : CFG_getActionDescriptionActionType(arg),
        acceptEvent ? acceptEvent(CFG_getActionDescriptionEvent(arg)) : CFG_getActionDescriptionEvent(arg));
  }
  ATabort("not a ActionDescription: %t\n", arg);
  return (CFG_ActionDescription)NULL;
}

/*}}}  */
/*{{{  CFG_ActionDescriptionList CFG_visitActionDescriptionList(CFG_ActionDescriptionList arg, CFG_ActionDescription (*acceptHead)(CFG_ActionDescription)) */

CFG_ActionDescriptionList CFG_visitActionDescriptionList(CFG_ActionDescriptionList arg, CFG_ActionDescription (*acceptHead)(CFG_ActionDescription))
{
  if (CFG_isActionDescriptionListEmpty(arg)) {
    return CFG_makeActionDescriptionListEmpty();
  }
  if (CFG_isActionDescriptionListSingle(arg)) {
    return CFG_makeActionDescriptionListSingle(
        acceptHead ? acceptHead(CFG_getActionDescriptionListHead(arg)) : CFG_getActionDescriptionListHead(arg));
  }
  if (CFG_isActionDescriptionListMany(arg)) {
    return CFG_makeActionDescriptionListMany(
        acceptHead ? acceptHead(CFG_getActionDescriptionListHead(arg)) : CFG_getActionDescriptionListHead(arg),
        CFG_visitActionDescriptionList(CFG_getActionDescriptionListTail(arg), acceptHead));
  }
  ATabort("not a ActionDescriptionList: %t\n", arg);
  return (CFG_ActionDescriptionList)NULL;
}

/*}}}  */
/*{{{  CFG_ActionType CFG_visitActionType(CFG_ActionType arg, char* (*acceptModuleId)(char*)) */

CFG_ActionType CFG_visitActionType(CFG_ActionType arg, char* (*acceptModuleId)(char*))
{
  if (CFG_isActionTypeTermEditor(arg)) {
    return CFG_makeActionTypeTermEditor();
  }
  if (CFG_isActionTypeTermEditorForModule(arg)) {
    return CFG_makeActionTypeTermEditorForModule(
        acceptModuleId ? acceptModuleId(CFG_getActionTypeModuleId(arg)) : CFG_getActionTypeModuleId(arg));
  }
  if (CFG_isActionTypeEquationsEditor(arg)) {
    return CFG_makeActionTypeEquationsEditor();
  }
  if (CFG_isActionTypeSyntaxEditor(arg)) {
    return CFG_makeActionTypeSyntaxEditor();
  }
  if (CFG_isActionTypeFeedbackList(arg)) {
    return CFG_makeActionTypeFeedbackList();
  }
  if (CFG_isActionTypeTreePanel(arg)) {
    return CFG_makeActionTypeTreePanel();
  }
  if (CFG_isActionTypeModulePopup(arg)) {
    return CFG_makeActionTypeModulePopup(
        acceptModuleId ? acceptModuleId(CFG_getActionTypeModuleId(arg)) : CFG_getActionTypeModuleId(arg));
  }
  if (CFG_isActionTypeNewModulePopup(arg)) {
    return CFG_makeActionTypeNewModulePopup();
  }
  if (CFG_isActionTypeStudioMenubar(arg)) {
    return CFG_makeActionTypeStudioMenubar();
  }
  if (CFG_isActionTypeStudioToolbar(arg)) {
    return CFG_makeActionTypeStudioToolbar();
  }
  if (CFG_isActionTypeWildcard(arg)) {
    return CFG_makeActionTypeWildcard();
  }
  ATabort("not a ActionType: %t\n", arg);
  return (CFG_ActionType)NULL;
}

/*}}}  */
/*{{{  CFG_Event CFG_visitEvent(CFG_Event arg, char* (*acceptTitle)(char*), char* (*acceptPath)(char*), CFG_Items (*acceptItems)(CFG_Items), char* (*acceptShortcut)(char*)) */

CFG_Event CFG_visitEvent(CFG_Event arg, char* (*acceptTitle)(char*), char* (*acceptPath)(char*), CFG_Items (*acceptItems)(CFG_Items), char* (*acceptShortcut)(char*))
{
  if (CFG_isEventClick(arg)) {
    return CFG_makeEventClick();
  }
  if (CFG_isEventIcon(arg)) {
    return CFG_makeEventIcon(
        acceptTitle ? acceptTitle(CFG_getEventTitle(arg)) : CFG_getEventTitle(arg),
        acceptPath ? acceptPath(CFG_getEventPath(arg)) : CFG_getEventPath(arg));
  }
  if (CFG_isEventDefault(arg)) {
    return CFG_makeEventDefault(
        acceptItems ? acceptItems(CFG_getEventItems(arg)) : CFG_getEventItems(arg));
  }
  if (CFG_isEventShortcut(arg)) {
    return CFG_makeEventShortcut(
        acceptItems ? acceptItems(CFG_getEventItems(arg)) : CFG_getEventItems(arg),
        acceptShortcut ? acceptShortcut(CFG_getEventShortcut(arg)) : CFG_getEventShortcut(arg));
  }
  ATabort("not a Event: %t\n", arg);
  return (CFG_Event)NULL;
}

/*}}}  */
/*{{{  CFG_Items CFG_visitItems(CFG_Items arg, char* (*acceptHead)(char*)) */

CFG_Items CFG_visitItems(CFG_Items arg, char* (*acceptHead)(char*))
{
  if (CFG_isItemsEmpty(arg)) {
    return CFG_makeItemsEmpty();
  }
  if (CFG_isItemsSingle(arg)) {
    return CFG_makeItemsSingle(
        acceptHead ? acceptHead(CFG_getItemsHead(arg)) : CFG_getItemsHead(arg));
  }
  if (CFG_isItemsMany(arg)) {
    return CFG_makeItemsMany(
        acceptHead ? acceptHead(CFG_getItemsHead(arg)) : CFG_getItemsHead(arg),
        CFG_visitItems(CFG_getItemsTail(arg), acceptHead));
  }
  ATabort("not a Items: %t\n", arg);
  return (CFG_Items)NULL;
}

/*}}}  */
/*{{{  CFG_ModuleName CFG_visitModuleName(CFG_ModuleName arg) */

CFG_ModuleName CFG_visitModuleName(CFG_ModuleName arg)
{
  if (CFG_isModuleNameWildcard(arg)) {
    return CFG_makeModuleNameWildcard();
  }
  ATabort("not a ModuleName: %t\n", arg);
  return (CFG_ModuleName)NULL;
}

/*}}}  */
/*{{{  CFG_TextCategoryName CFG_visitTextCategoryName(CFG_TextCategoryName arg, char* (*acceptName)(char*)) */

CFG_TextCategoryName CFG_visitTextCategoryName(CFG_TextCategoryName arg, char* (*acceptName)(char*))
{
  if (CFG_isTextCategoryNameFocus(arg)) {
    return CFG_makeTextCategoryNameFocus();
  }
  if (CFG_isTextCategoryNameSelection(arg)) {
    return CFG_makeTextCategoryNameSelection();
  }
  if (CFG_isTextCategoryNameNormal(arg)) {
    return CFG_makeTextCategoryNameNormal();
  }
  if (CFG_isTextCategoryNameExtern(arg)) {
    return CFG_makeTextCategoryNameExtern(
        acceptName ? acceptName(CFG_getTextCategoryNameName(arg)) : CFG_getTextCategoryNameName(arg));
  }
  ATabort("not a TextCategoryName: %t\n", arg);
  return (CFG_TextCategoryName)NULL;
}

/*}}}  */
/*{{{  CFG_TextAttributes CFG_visitTextAttributes(CFG_TextAttributes arg, CFG_TextAttribute (*acceptHead)(CFG_TextAttribute)) */

CFG_TextAttributes CFG_visitTextAttributes(CFG_TextAttributes arg, CFG_TextAttribute (*acceptHead)(CFG_TextAttribute))
{
  if (CFG_isTextAttributesEmpty(arg)) {
    return CFG_makeTextAttributesEmpty();
  }
  if (CFG_isTextAttributesSingle(arg)) {
    return CFG_makeTextAttributesSingle(
        acceptHead ? acceptHead(CFG_getTextAttributesHead(arg)) : CFG_getTextAttributesHead(arg));
  }
  if (CFG_isTextAttributesMany(arg)) {
    return CFG_makeTextAttributesMany(
        acceptHead ? acceptHead(CFG_getTextAttributesHead(arg)) : CFG_getTextAttributesHead(arg),
        CFG_visitTextAttributes(CFG_getTextAttributesTail(arg), acceptHead));
  }
  ATabort("not a TextAttributes: %t\n", arg);
  return (CFG_TextAttributes)NULL;
}

/*}}}  */
/*{{{  CFG_TextAttribute CFG_visitTextAttribute(CFG_TextAttribute arg, CFG_Color (*acceptColor)(CFG_Color), CFG_TextStyle (*acceptStyle)(CFG_TextStyle), char* (*acceptName)(char*), int (*acceptPoints)(int)) */

CFG_TextAttribute CFG_visitTextAttribute(CFG_TextAttribute arg, CFG_Color (*acceptColor)(CFG_Color), CFG_TextStyle (*acceptStyle)(CFG_TextStyle), char* (*acceptName)(char*), int (*acceptPoints)(int))
{
  if (CFG_isTextAttributeForegroundColor(arg)) {
    return CFG_makeTextAttributeForegroundColor(
        acceptColor ? acceptColor(CFG_getTextAttributeColor(arg)) : CFG_getTextAttributeColor(arg));
  }
  if (CFG_isTextAttributeBackgroundColor(arg)) {
    return CFG_makeTextAttributeBackgroundColor(
        acceptColor ? acceptColor(CFG_getTextAttributeColor(arg)) : CFG_getTextAttributeColor(arg));
  }
  if (CFG_isTextAttributeStyle(arg)) {
    return CFG_makeTextAttributeStyle(
        acceptStyle ? acceptStyle(CFG_getTextAttributeStyle(arg)) : CFG_getTextAttributeStyle(arg));
  }
  if (CFG_isTextAttributeFont(arg)) {
    return CFG_makeTextAttributeFont(
        acceptName ? acceptName(CFG_getTextAttributeName(arg)) : CFG_getTextAttributeName(arg));
  }
  if (CFG_isTextAttributeSize(arg)) {
    return CFG_makeTextAttributeSize(
        acceptPoints ? acceptPoints(CFG_getTextAttributePoints(arg)) : CFG_getTextAttributePoints(arg));
  }
  ATabort("not a TextAttribute: %t\n", arg);
  return (CFG_TextAttribute)NULL;
}

/*}}}  */
/*{{{  CFG_TextStyle CFG_visitTextStyle(CFG_TextStyle arg) */

CFG_TextStyle CFG_visitTextStyle(CFG_TextStyle arg)
{
  if (CFG_isTextStyleBold(arg)) {
    return CFG_makeTextStyleBold();
  }
  if (CFG_isTextStyleItalics(arg)) {
    return CFG_makeTextStyleItalics();
  }
  if (CFG_isTextStyleUnderlined(arg)) {
    return CFG_makeTextStyleUnderlined();
  }
  ATabort("not a TextStyle: %t\n", arg);
  return (CFG_TextStyle)NULL;
}

/*}}}  */
/*{{{  CFG_Color CFG_visitColor(CFG_Color arg, int (*acceptRed)(int), int (*acceptGreen)(int), int (*acceptBlue)(int)) */

CFG_Color CFG_visitColor(CFG_Color arg, int (*acceptRed)(int), int (*acceptGreen)(int), int (*acceptBlue)(int))
{
  if (CFG_isColorRgb(arg)) {
    return CFG_makeColorRgb(
        acceptRed ? acceptRed(CFG_getColorRed(arg)) : CFG_getColorRed(arg),
        acceptGreen ? acceptGreen(CFG_getColorGreen(arg)) : CFG_getColorGreen(arg),
        acceptBlue ? acceptBlue(CFG_getColorBlue(arg)) : CFG_getColorBlue(arg));
  }
  ATabort("not a Color: %t\n", arg);
  return (CFG_Color)NULL;
}

/*}}}  */

/*}}}  */
