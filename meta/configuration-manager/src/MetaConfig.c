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


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _MC_Configuration;
typedef struct ATerm _MC_Properties;
typedef struct ATerm _MC_Property;
typedef struct ATerm _MC_ButtonDescriptionList;
typedef struct ATerm _MC_ButtonDescription;
typedef struct ATerm _MC_ButtonType;
typedef struct ATerm _MC_ButtonArgs;
typedef struct ATerm _MC_Items;
typedef struct ATerm _MC_ModuleName;

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

void MC_protectButtonDescriptionList(MC_ButtonDescriptionList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectButtonDescription(MC_ButtonDescription *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectButtonType(MC_ButtonType *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MC_protectButtonArgs(MC_ButtonArgs *arg)
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
/*{{{  MC_ButtonDescriptionList MC_ButtonDescriptionListFromTerm(ATerm t) */

MC_ButtonDescriptionList MC_ButtonDescriptionListFromTerm(ATerm t)
{
  return (MC_ButtonDescriptionList)t;
}

/*}}}  */
/*{{{  ATerm MC_ButtonDescriptionListToTerm(MC_ButtonDescriptionList arg) */

ATerm MC_ButtonDescriptionListToTerm(MC_ButtonDescriptionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_ButtonDescription MC_ButtonDescriptionFromTerm(ATerm t) */

MC_ButtonDescription MC_ButtonDescriptionFromTerm(ATerm t)
{
  return (MC_ButtonDescription)t;
}

/*}}}  */
/*{{{  ATerm MC_ButtonDescriptionToTerm(MC_ButtonDescription arg) */

ATerm MC_ButtonDescriptionToTerm(MC_ButtonDescription arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_ButtonType MC_ButtonTypeFromTerm(ATerm t) */

MC_ButtonType MC_ButtonTypeFromTerm(ATerm t)
{
  return (MC_ButtonType)t;
}

/*}}}  */
/*{{{  ATerm MC_ButtonTypeToTerm(MC_ButtonType arg) */

ATerm MC_ButtonTypeToTerm(MC_ButtonType arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MC_ButtonArgs MC_ButtonArgsFromTerm(ATerm t) */

MC_ButtonArgs MC_ButtonArgsFromTerm(ATerm t)
{
  return (MC_ButtonArgs)t;
}

/*}}}  */
/*{{{  ATerm MC_ButtonArgsToTerm(MC_ButtonArgs arg) */

ATerm MC_ButtonArgsToTerm(MC_ButtonArgs arg)
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
int MC_getButtonDescriptionListLength (MC_ButtonDescriptionList arg) {
  return ATgetLength((ATermList) arg);
}
MC_ButtonDescriptionList MC_reverseButtonDescriptionList(MC_ButtonDescriptionList arg) {
  return (MC_ButtonDescriptionList) ATreverse((ATermList) arg);
}
MC_ButtonDescriptionList MC_appendButtonDescriptionList(MC_ButtonDescriptionList arg, MC_ButtonDescription elem) {
  return (MC_ButtonDescriptionList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
MC_ButtonDescriptionList MC_concatButtonDescriptionList(MC_ButtonDescriptionList arg0, MC_ButtonDescriptionList arg1) {
  return (MC_ButtonDescriptionList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
MC_ButtonDescriptionList MC_sliceButtonDescriptionList(MC_ButtonDescriptionList arg, int start, int end) {
  return (MC_ButtonDescriptionList) ATgetSlice((ATermList) arg, start, end);
}
MC_ButtonDescription MC_getButtonDescriptionListButtonDescriptionAt(MC_ButtonDescriptionList arg, int index) {
 return (MC_ButtonDescription)ATelementAt((ATermList) arg,index);
}
MC_ButtonDescriptionList MC_replaceButtonDescriptionListButtonDescriptionAt(MC_ButtonDescriptionList arg, MC_ButtonDescription elem, int index) {
 return (MC_ButtonDescriptionList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
MC_ButtonDescriptionList MC_makeButtonDescriptionList2(MC_ButtonDescription elem1, MC_ButtonDescription elem2) {
  return (MC_ButtonDescriptionList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
MC_ButtonDescriptionList MC_makeButtonDescriptionList3(MC_ButtonDescription elem1, MC_ButtonDescription elem2, MC_ButtonDescription elem3) {
  return (MC_ButtonDescriptionList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
MC_ButtonDescriptionList MC_makeButtonDescriptionList4(MC_ButtonDescription elem1, MC_ButtonDescription elem2, MC_ButtonDescription elem3, MC_ButtonDescription elem4) {
  return (MC_ButtonDescriptionList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
MC_ButtonDescriptionList MC_makeButtonDescriptionList5(MC_ButtonDescription elem1, MC_ButtonDescription elem2, MC_ButtonDescription elem3, MC_ButtonDescription elem4, MC_ButtonDescription elem5) {
  return (MC_ButtonDescriptionList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
MC_ButtonDescriptionList MC_makeButtonDescriptionList6(MC_ButtonDescription elem1, MC_ButtonDescription elem2, MC_ButtonDescription elem3, MC_ButtonDescription elem4, MC_ButtonDescription elem5, MC_ButtonDescription elem6) {
  return (MC_ButtonDescriptionList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
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
/*{{{  MC_Property MC_makePropertyButton(const char* module, MC_ButtonDescriptionList descriptions, ATerm actions) */

MC_Property MC_makePropertyButton(const char* module, MC_ButtonDescriptionList descriptions, ATerm actions)
{
  return (MC_Property)(ATerm)ATmakeAppl3(MC_afun1, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(module, 0, ATtrue)), (ATerm) descriptions, (ATerm) actions);
}

/*}}}  */
/*{{{  MC_Property MC_makePropertyExtension(const char* language, const char* extension) */

MC_Property MC_makePropertyExtension(const char* language, const char* extension)
{
  return (MC_Property)(ATerm)ATmakeAppl2(MC_afun2, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(language, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(extension, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_ButtonDescriptionList MC_makeButtonDescriptionListEmpty(void) */

MC_ButtonDescriptionList MC_makeButtonDescriptionListEmpty(void)
{
  return (MC_ButtonDescriptionList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MC_ButtonDescriptionList MC_makeButtonDescriptionListSingle(MC_ButtonDescription head) */

MC_ButtonDescriptionList MC_makeButtonDescriptionListSingle(MC_ButtonDescription head)
{
  return (MC_ButtonDescriptionList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  MC_ButtonDescriptionList MC_makeButtonDescriptionListMany(MC_ButtonDescription head, MC_ButtonDescriptionList tail) */

MC_ButtonDescriptionList MC_makeButtonDescriptionListMany(MC_ButtonDescription head, MC_ButtonDescriptionList tail)
{
  return (MC_ButtonDescriptionList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  MC_ButtonDescription MC_makeButtonDescriptionDefault(MC_ButtonType type, MC_ButtonArgs args) */

MC_ButtonDescription MC_makeButtonDescriptionDefault(MC_ButtonType type, MC_ButtonArgs args)
{
  return (MC_ButtonDescription)(ATerm)ATmakeAppl2(MC_afun3, (ATerm) type, (ATerm) args);
}

/*}}}  */
/*{{{  MC_ButtonType MC_makeButtonTypeTermEditor(void) */

MC_ButtonType MC_makeButtonTypeTermEditor(void)
{
  return (MC_ButtonType)(ATerm)ATmakeAppl0(MC_afun4);
}

/*}}}  */
/*{{{  MC_ButtonType MC_makeButtonTypeEquationsEditor(void) */

MC_ButtonType MC_makeButtonTypeEquationsEditor(void)
{
  return (MC_ButtonType)(ATerm)ATmakeAppl0(MC_afun5);
}

/*}}}  */
/*{{{  MC_ButtonType MC_makeButtonTypeSyntaxEditor(void) */

MC_ButtonType MC_makeButtonTypeSyntaxEditor(void)
{
  return (MC_ButtonType)(ATerm)ATmakeAppl0(MC_afun6);
}

/*}}}  */
/*{{{  MC_ButtonType MC_makeButtonTypeFeedbackList(void) */

MC_ButtonType MC_makeButtonTypeFeedbackList(void)
{
  return (MC_ButtonType)(ATerm)ATmakeAppl0(MC_afun7);
}

/*}}}  */
/*{{{  MC_ButtonType MC_makeButtonTypeTreePanel(void) */

MC_ButtonType MC_makeButtonTypeTreePanel(void)
{
  return (MC_ButtonType)(ATerm)ATmakeAppl0(MC_afun8);
}

/*}}}  */
/*{{{  MC_ButtonType MC_makeButtonTypeModulePopup(void) */

MC_ButtonType MC_makeButtonTypeModulePopup(void)
{
  return (MC_ButtonType)(ATerm)ATmakeAppl0(MC_afun9);
}

/*}}}  */
/*{{{  MC_ButtonType MC_makeButtonTypeNewModulePopup(void) */

MC_ButtonType MC_makeButtonTypeNewModulePopup(void)
{
  return (MC_ButtonType)(ATerm)ATmakeAppl0(MC_afun10);
}

/*}}}  */
/*{{{  MC_ButtonType MC_makeButtonTypeStudioMenubar(void) */

MC_ButtonType MC_makeButtonTypeStudioMenubar(void)
{
  return (MC_ButtonType)(ATerm)ATmakeAppl0(MC_afun11);
}

/*}}}  */
/*{{{  MC_ButtonType MC_makeButtonTypeStudioToolbar(void) */

MC_ButtonType MC_makeButtonTypeStudioToolbar(void)
{
  return (MC_ButtonType)(ATerm)ATmakeAppl0(MC_afun12);
}

/*}}}  */
/*{{{  MC_ButtonType MC_makeButtonTypeWildcard(void) */

MC_ButtonType MC_makeButtonTypeWildcard(void)
{
  return (MC_ButtonType)(ATerm)ATmakeAppl0(MC_afun13);
}

/*}}}  */
/*{{{  MC_ButtonArgs MC_makeButtonArgsClick(void) */

MC_ButtonArgs MC_makeButtonArgsClick(void)
{
  return (MC_ButtonArgs)(ATerm)ATmakeAppl0(MC_afun14);
}

/*}}}  */
/*{{{  MC_ButtonArgs MC_makeButtonArgsIcon(const char* title, const char* path) */

MC_ButtonArgs MC_makeButtonArgsIcon(const char* title, const char* path)
{
  return (MC_ButtonArgs)(ATerm)ATmakeAppl2(MC_afun15, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(title, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_ButtonArgs MC_makeButtonArgsDefault(MC_Items items) */

MC_ButtonArgs MC_makeButtonArgsDefault(MC_Items items)
{
  return (MC_ButtonArgs)(ATerm)ATmakeAppl1(MC_afun16, (ATerm) items);
}

/*}}}  */
/*{{{  MC_ButtonArgs MC_makeButtonArgsShortcut(MC_Items items, const char* shortcut) */

MC_ButtonArgs MC_makeButtonArgsShortcut(MC_Items items, const char* shortcut)
{
  return (MC_ButtonArgs)(ATerm)ATmakeAppl2(MC_afun17, (ATerm) items, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(shortcut, 0, ATtrue)));
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
  return (MC_ModuleName)(ATerm)ATmakeAppl0(MC_afun13);
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

ATbool MC_isEqualButtonDescriptionList(MC_ButtonDescriptionList arg0, MC_ButtonDescriptionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualButtonDescription(MC_ButtonDescription arg0, MC_ButtonDescription arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualButtonType(MC_ButtonType arg0, MC_ButtonType arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MC_isEqualButtonArgs(MC_ButtonArgs arg0, MC_ButtonArgs arg1)
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
/*{{{  ATbool MC_hasPropertiesTail(MC_Properties arg) */

ATbool MC_hasPropertiesTail(MC_Properties arg)
{
  if (MC_isPropertiesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_Properties MC_getPropertiesTail(MC_Properties arg) */

MC_Properties MC_getPropertiesTail(MC_Properties arg)
{
  
    return (MC_Properties)ATgetNext((ATermList)arg);
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
  if (MC_isPropertyButton(arg)) {
    return ATtrue;
  }
  else if (MC_isPropertyExtension(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isPropertyButton(MC_Property arg) */

inline ATbool MC_isPropertyButton(MC_Property arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternPropertyButton, NULL, NULL, NULL);
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
/*{{{  ATbool MC_hasPropertyModule(MC_Property arg) */

ATbool MC_hasPropertyModule(MC_Property arg)
{
  if (MC_isPropertyButton(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MC_getPropertyModule(MC_Property arg) */

char* MC_getPropertyModule(MC_Property arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  MC_Property MC_setPropertyModule(MC_Property arg, const char* module) */

MC_Property MC_setPropertyModule(MC_Property arg, const char* module)
{
  if (MC_isPropertyButton(arg)) {
    return (MC_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(module, 0, ATtrue))), 0);
  }

  ATabort("Property has no Module: %t\n", arg);
  return (MC_Property)NULL;
}

/*}}}  */
/*{{{  ATbool MC_hasPropertyDescriptions(MC_Property arg) */

ATbool MC_hasPropertyDescriptions(MC_Property arg)
{
  if (MC_isPropertyButton(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_ButtonDescriptionList MC_getPropertyDescriptions(MC_Property arg) */

MC_ButtonDescriptionList MC_getPropertyDescriptions(MC_Property arg)
{
  
    return (MC_ButtonDescriptionList)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  MC_Property MC_setPropertyDescriptions(MC_Property arg, MC_ButtonDescriptionList descriptions) */

MC_Property MC_setPropertyDescriptions(MC_Property arg, MC_ButtonDescriptionList descriptions)
{
  if (MC_isPropertyButton(arg)) {
    return (MC_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) descriptions), 1);
  }

  ATabort("Property has no Descriptions: %t\n", arg);
  return (MC_Property)NULL;
}

/*}}}  */
/*{{{  ATbool MC_hasPropertyActions(MC_Property arg) */

ATbool MC_hasPropertyActions(MC_Property arg)
{
  if (MC_isPropertyButton(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm MC_getPropertyActions(MC_Property arg) */

ATerm MC_getPropertyActions(MC_Property arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  MC_Property MC_setPropertyActions(MC_Property arg, ATerm actions) */

MC_Property MC_setPropertyActions(MC_Property arg, ATerm actions)
{
  if (MC_isPropertyButton(arg)) {
    return (MC_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) actions), 2);
  }

  ATabort("Property has no Actions: %t\n", arg);
  return (MC_Property)NULL;
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
/*{{{  char* MC_getPropertyLanguage(MC_Property arg) */

char* MC_getPropertyLanguage(MC_Property arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
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
/*{{{  ATbool MC_hasPropertyExtension(MC_Property arg) */

ATbool MC_hasPropertyExtension(MC_Property arg)
{
  if (MC_isPropertyExtension(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MC_getPropertyExtension(MC_Property arg) */

char* MC_getPropertyExtension(MC_Property arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
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

/*}}}  */
/*{{{  MC_ButtonDescriptionList accessors */

/*{{{  ATbool MC_isValidButtonDescriptionList(MC_ButtonDescriptionList arg) */

ATbool MC_isValidButtonDescriptionList(MC_ButtonDescriptionList arg)
{
  if (MC_isButtonDescriptionListEmpty(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonDescriptionListSingle(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonDescriptionListEmpty(MC_ButtonDescriptionList arg) */

inline ATbool MC_isButtonDescriptionListEmpty(MC_ButtonDescriptionList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MC_patternButtonDescriptionListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonDescriptionListSingle(MC_ButtonDescriptionList arg) */

inline ATbool MC_isButtonDescriptionListSingle(MC_ButtonDescriptionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonDescriptionListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonDescriptionListMany(MC_ButtonDescriptionList arg) */

inline ATbool MC_isButtonDescriptionListMany(MC_ButtonDescriptionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonDescriptionListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MC_hasButtonDescriptionListHead(MC_ButtonDescriptionList arg) */

ATbool MC_hasButtonDescriptionListHead(MC_ButtonDescriptionList arg)
{
  if (MC_isButtonDescriptionListSingle(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_ButtonDescription MC_getButtonDescriptionListHead(MC_ButtonDescriptionList arg) */

MC_ButtonDescription MC_getButtonDescriptionListHead(MC_ButtonDescriptionList arg)
{
  if (MC_isButtonDescriptionListSingle(arg)) {
    return (MC_ButtonDescription)ATgetFirst((ATermList)arg);
  }
  else 
    return (MC_ButtonDescription)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MC_ButtonDescriptionList MC_setButtonDescriptionListHead(MC_ButtonDescriptionList arg, MC_ButtonDescription head) */

MC_ButtonDescriptionList MC_setButtonDescriptionListHead(MC_ButtonDescriptionList arg, MC_ButtonDescription head)
{
  if (MC_isButtonDescriptionListSingle(arg)) {
    return (MC_ButtonDescriptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (MC_isButtonDescriptionListMany(arg)) {
    return (MC_ButtonDescriptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ButtonDescriptionList has no Head: %t\n", arg);
  return (MC_ButtonDescriptionList)NULL;
}

/*}}}  */
/*{{{  ATbool MC_hasButtonDescriptionListTail(MC_ButtonDescriptionList arg) */

ATbool MC_hasButtonDescriptionListTail(MC_ButtonDescriptionList arg)
{
  if (MC_isButtonDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_ButtonDescriptionList MC_getButtonDescriptionListTail(MC_ButtonDescriptionList arg) */

MC_ButtonDescriptionList MC_getButtonDescriptionListTail(MC_ButtonDescriptionList arg)
{
  
    return (MC_ButtonDescriptionList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  MC_ButtonDescriptionList MC_setButtonDescriptionListTail(MC_ButtonDescriptionList arg, MC_ButtonDescriptionList tail) */

MC_ButtonDescriptionList MC_setButtonDescriptionListTail(MC_ButtonDescriptionList arg, MC_ButtonDescriptionList tail)
{
  if (MC_isButtonDescriptionListMany(arg)) {
    return (MC_ButtonDescriptionList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("ButtonDescriptionList has no Tail: %t\n", arg);
  return (MC_ButtonDescriptionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MC_ButtonDescription accessors */

/*{{{  ATbool MC_isValidButtonDescription(MC_ButtonDescription arg) */

ATbool MC_isValidButtonDescription(MC_ButtonDescription arg)
{
  if (MC_isButtonDescriptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonDescriptionDefault(MC_ButtonDescription arg) */

inline ATbool MC_isButtonDescriptionDefault(MC_ButtonDescription arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MC_patternButtonDescriptionDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MC_hasButtonDescriptionType(MC_ButtonDescription arg) */

ATbool MC_hasButtonDescriptionType(MC_ButtonDescription arg)
{
  if (MC_isButtonDescriptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_ButtonType MC_getButtonDescriptionType(MC_ButtonDescription arg) */

MC_ButtonType MC_getButtonDescriptionType(MC_ButtonDescription arg)
{
  
    return (MC_ButtonType)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  MC_ButtonDescription MC_setButtonDescriptionType(MC_ButtonDescription arg, MC_ButtonType type) */

MC_ButtonDescription MC_setButtonDescriptionType(MC_ButtonDescription arg, MC_ButtonType type)
{
  if (MC_isButtonDescriptionDefault(arg)) {
    return (MC_ButtonDescription)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) type), 0);
  }

  ATabort("ButtonDescription has no Type: %t\n", arg);
  return (MC_ButtonDescription)NULL;
}

/*}}}  */
/*{{{  ATbool MC_hasButtonDescriptionArgs(MC_ButtonDescription arg) */

ATbool MC_hasButtonDescriptionArgs(MC_ButtonDescription arg)
{
  if (MC_isButtonDescriptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_ButtonArgs MC_getButtonDescriptionArgs(MC_ButtonDescription arg) */

MC_ButtonArgs MC_getButtonDescriptionArgs(MC_ButtonDescription arg)
{
  
    return (MC_ButtonArgs)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  MC_ButtonDescription MC_setButtonDescriptionArgs(MC_ButtonDescription arg, MC_ButtonArgs args) */

MC_ButtonDescription MC_setButtonDescriptionArgs(MC_ButtonDescription arg, MC_ButtonArgs args)
{
  if (MC_isButtonDescriptionDefault(arg)) {
    return (MC_ButtonDescription)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) args), 1);
  }

  ATabort("ButtonDescription has no Args: %t\n", arg);
  return (MC_ButtonDescription)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MC_ButtonType accessors */

/*{{{  ATbool MC_isValidButtonType(MC_ButtonType arg) */

ATbool MC_isValidButtonType(MC_ButtonType arg)
{
  if (MC_isButtonTypeTermEditor(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonTypeEquationsEditor(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonTypeSyntaxEditor(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonTypeFeedbackList(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonTypeTreePanel(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonTypeModulePopup(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonTypeNewModulePopup(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonTypeStudioMenubar(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonTypeStudioToolbar(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonTypeWildcard(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonTypeTermEditor(MC_ButtonType arg) */

inline ATbool MC_isButtonTypeTermEditor(MC_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonTypeTermEditor);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonTypeEquationsEditor(MC_ButtonType arg) */

inline ATbool MC_isButtonTypeEquationsEditor(MC_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonTypeEquationsEditor);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonTypeSyntaxEditor(MC_ButtonType arg) */

inline ATbool MC_isButtonTypeSyntaxEditor(MC_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonTypeSyntaxEditor);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonTypeFeedbackList(MC_ButtonType arg) */

inline ATbool MC_isButtonTypeFeedbackList(MC_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonTypeFeedbackList);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonTypeTreePanel(MC_ButtonType arg) */

inline ATbool MC_isButtonTypeTreePanel(MC_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonTypeTreePanel);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonTypeModulePopup(MC_ButtonType arg) */

inline ATbool MC_isButtonTypeModulePopup(MC_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonTypeModulePopup);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonTypeNewModulePopup(MC_ButtonType arg) */

inline ATbool MC_isButtonTypeNewModulePopup(MC_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonTypeNewModulePopup);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonTypeStudioMenubar(MC_ButtonType arg) */

inline ATbool MC_isButtonTypeStudioMenubar(MC_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonTypeStudioMenubar);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonTypeStudioToolbar(MC_ButtonType arg) */

inline ATbool MC_isButtonTypeStudioToolbar(MC_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonTypeStudioToolbar);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonTypeWildcard(MC_ButtonType arg) */

inline ATbool MC_isButtonTypeWildcard(MC_ButtonType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonTypeWildcard);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  MC_ButtonArgs accessors */

/*{{{  ATbool MC_isValidButtonArgs(MC_ButtonArgs arg) */

ATbool MC_isValidButtonArgs(MC_ButtonArgs arg)
{
  if (MC_isButtonArgsClick(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonArgsIcon(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonArgsDefault(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonArgsShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonArgsClick(MC_ButtonArgs arg) */

inline ATbool MC_isButtonArgsClick(MC_ButtonArgs arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonArgsClick);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonArgsIcon(MC_ButtonArgs arg) */

inline ATbool MC_isButtonArgsIcon(MC_ButtonArgs arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonArgsIcon, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonArgsDefault(MC_ButtonArgs arg) */

inline ATbool MC_isButtonArgsDefault(MC_ButtonArgs arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonArgsDefault, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MC_isButtonArgsShortcut(MC_ButtonArgs arg) */

inline ATbool MC_isButtonArgsShortcut(MC_ButtonArgs arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MC_patternButtonArgsShortcut, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MC_hasButtonArgsTitle(MC_ButtonArgs arg) */

ATbool MC_hasButtonArgsTitle(MC_ButtonArgs arg)
{
  if (MC_isButtonArgsIcon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MC_getButtonArgsTitle(MC_ButtonArgs arg) */

char* MC_getButtonArgsTitle(MC_ButtonArgs arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  MC_ButtonArgs MC_setButtonArgsTitle(MC_ButtonArgs arg, const char* title) */

MC_ButtonArgs MC_setButtonArgsTitle(MC_ButtonArgs arg, const char* title)
{
  if (MC_isButtonArgsIcon(arg)) {
    return (MC_ButtonArgs)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(title, 0, ATtrue))), 0);
  }

  ATabort("ButtonArgs has no Title: %t\n", arg);
  return (MC_ButtonArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MC_hasButtonArgsPath(MC_ButtonArgs arg) */

ATbool MC_hasButtonArgsPath(MC_ButtonArgs arg)
{
  if (MC_isButtonArgsIcon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MC_getButtonArgsPath(MC_ButtonArgs arg) */

char* MC_getButtonArgsPath(MC_ButtonArgs arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  MC_ButtonArgs MC_setButtonArgsPath(MC_ButtonArgs arg, const char* path) */

MC_ButtonArgs MC_setButtonArgsPath(MC_ButtonArgs arg, const char* path)
{
  if (MC_isButtonArgsIcon(arg)) {
    return (MC_ButtonArgs)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 1);
  }

  ATabort("ButtonArgs has no Path: %t\n", arg);
  return (MC_ButtonArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MC_hasButtonArgsItems(MC_ButtonArgs arg) */

ATbool MC_hasButtonArgsItems(MC_ButtonArgs arg)
{
  if (MC_isButtonArgsDefault(arg)) {
    return ATtrue;
  }
  else if (MC_isButtonArgsShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_Items MC_getButtonArgsItems(MC_ButtonArgs arg) */

MC_Items MC_getButtonArgsItems(MC_ButtonArgs arg)
{
  if (MC_isButtonArgsDefault(arg)) {
    return (MC_Items)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (MC_Items)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  MC_ButtonArgs MC_setButtonArgsItems(MC_ButtonArgs arg, MC_Items items) */

MC_ButtonArgs MC_setButtonArgsItems(MC_ButtonArgs arg, MC_Items items)
{
  if (MC_isButtonArgsDefault(arg)) {
    return (MC_ButtonArgs)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) items), 0);
  }
  else if (MC_isButtonArgsShortcut(arg)) {
    return (MC_ButtonArgs)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) items), 0);
  }

  ATabort("ButtonArgs has no Items: %t\n", arg);
  return (MC_ButtonArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MC_hasButtonArgsShortcut(MC_ButtonArgs arg) */

ATbool MC_hasButtonArgsShortcut(MC_ButtonArgs arg)
{
  if (MC_isButtonArgsShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MC_getButtonArgsShortcut(MC_ButtonArgs arg) */

char* MC_getButtonArgsShortcut(MC_ButtonArgs arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  MC_ButtonArgs MC_setButtonArgsShortcut(MC_ButtonArgs arg, const char* shortcut) */

MC_ButtonArgs MC_setButtonArgsShortcut(MC_ButtonArgs arg, const char* shortcut)
{
  if (MC_isButtonArgsShortcut(arg)) {
    return (MC_ButtonArgs)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(shortcut, 0, ATtrue))), 1);
  }

  ATabort("ButtonArgs has no Shortcut: %t\n", arg);
  return (MC_ButtonArgs)NULL;
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
/*{{{  ATbool MC_hasItemsTail(MC_Items arg) */

ATbool MC_hasItemsTail(MC_Items arg)
{
  if (MC_isItemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_Items MC_getItemsTail(MC_Items arg) */

MC_Items MC_getItemsTail(MC_Items arg)
{
  
    return (MC_Items)ATgetNext((ATermList)arg);
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
/*{{{  MC_Property MC_visitProperty(MC_Property arg, char* (*acceptModule)(char*), MC_ButtonDescriptionList (*acceptDescriptions)(MC_ButtonDescriptionList), ATerm (*acceptActions)(ATerm), char* (*acceptLanguage)(char*), char* (*acceptExtension)(char*)) */

MC_Property MC_visitProperty(MC_Property arg, char* (*acceptModule)(char*), MC_ButtonDescriptionList (*acceptDescriptions)(MC_ButtonDescriptionList), ATerm (*acceptActions)(ATerm), char* (*acceptLanguage)(char*), char* (*acceptExtension)(char*))
{
  if (MC_isPropertyButton(arg)) {
    return MC_makePropertyButton(
        acceptModule ? acceptModule(MC_getPropertyModule(arg)) : MC_getPropertyModule(arg),
        acceptDescriptions ? acceptDescriptions(MC_getPropertyDescriptions(arg)) : MC_getPropertyDescriptions(arg),
        acceptActions ? acceptActions(MC_getPropertyActions(arg)) : MC_getPropertyActions(arg));
  }
  if (MC_isPropertyExtension(arg)) {
    return MC_makePropertyExtension(
        acceptLanguage ? acceptLanguage(MC_getPropertyLanguage(arg)) : MC_getPropertyLanguage(arg),
        acceptExtension ? acceptExtension(MC_getPropertyExtension(arg)) : MC_getPropertyExtension(arg));
  }
  ATabort("not a Property: %t\n", arg);
  return (MC_Property)NULL;
}

/*}}}  */
/*{{{  MC_ButtonDescriptionList MC_visitButtonDescriptionList(MC_ButtonDescriptionList arg, MC_ButtonDescription (*acceptHead)(MC_ButtonDescription)) */

MC_ButtonDescriptionList MC_visitButtonDescriptionList(MC_ButtonDescriptionList arg, MC_ButtonDescription (*acceptHead)(MC_ButtonDescription))
{
  if (MC_isButtonDescriptionListEmpty(arg)) {
    return MC_makeButtonDescriptionListEmpty();
  }
  if (MC_isButtonDescriptionListSingle(arg)) {
    return MC_makeButtonDescriptionListSingle(
        acceptHead ? acceptHead(MC_getButtonDescriptionListHead(arg)) : MC_getButtonDescriptionListHead(arg));
  }
  if (MC_isButtonDescriptionListMany(arg)) {
    return MC_makeButtonDescriptionListMany(
        acceptHead ? acceptHead(MC_getButtonDescriptionListHead(arg)) : MC_getButtonDescriptionListHead(arg),
        MC_visitButtonDescriptionList(MC_getButtonDescriptionListTail(arg), acceptHead));
  }
  ATabort("not a ButtonDescriptionList: %t\n", arg);
  return (MC_ButtonDescriptionList)NULL;
}

/*}}}  */
/*{{{  MC_ButtonDescription MC_visitButtonDescription(MC_ButtonDescription arg, MC_ButtonType (*acceptType)(MC_ButtonType), MC_ButtonArgs (*acceptArgs)(MC_ButtonArgs)) */

MC_ButtonDescription MC_visitButtonDescription(MC_ButtonDescription arg, MC_ButtonType (*acceptType)(MC_ButtonType), MC_ButtonArgs (*acceptArgs)(MC_ButtonArgs))
{
  if (MC_isButtonDescriptionDefault(arg)) {
    return MC_makeButtonDescriptionDefault(
        acceptType ? acceptType(MC_getButtonDescriptionType(arg)) : MC_getButtonDescriptionType(arg),
        acceptArgs ? acceptArgs(MC_getButtonDescriptionArgs(arg)) : MC_getButtonDescriptionArgs(arg));
  }
  ATabort("not a ButtonDescription: %t\n", arg);
  return (MC_ButtonDescription)NULL;
}

/*}}}  */
/*{{{  MC_ButtonType MC_visitButtonType(MC_ButtonType arg) */

MC_ButtonType MC_visitButtonType(MC_ButtonType arg)
{
  if (MC_isButtonTypeTermEditor(arg)) {
    return MC_makeButtonTypeTermEditor();
  }
  if (MC_isButtonTypeEquationsEditor(arg)) {
    return MC_makeButtonTypeEquationsEditor();
  }
  if (MC_isButtonTypeSyntaxEditor(arg)) {
    return MC_makeButtonTypeSyntaxEditor();
  }
  if (MC_isButtonTypeFeedbackList(arg)) {
    return MC_makeButtonTypeFeedbackList();
  }
  if (MC_isButtonTypeTreePanel(arg)) {
    return MC_makeButtonTypeTreePanel();
  }
  if (MC_isButtonTypeModulePopup(arg)) {
    return MC_makeButtonTypeModulePopup();
  }
  if (MC_isButtonTypeNewModulePopup(arg)) {
    return MC_makeButtonTypeNewModulePopup();
  }
  if (MC_isButtonTypeStudioMenubar(arg)) {
    return MC_makeButtonTypeStudioMenubar();
  }
  if (MC_isButtonTypeStudioToolbar(arg)) {
    return MC_makeButtonTypeStudioToolbar();
  }
  if (MC_isButtonTypeWildcard(arg)) {
    return MC_makeButtonTypeWildcard();
  }
  ATabort("not a ButtonType: %t\n", arg);
  return (MC_ButtonType)NULL;
}

/*}}}  */
/*{{{  MC_ButtonArgs MC_visitButtonArgs(MC_ButtonArgs arg, char* (*acceptTitle)(char*), char* (*acceptPath)(char*), MC_Items (*acceptItems)(MC_Items), char* (*acceptShortcut)(char*)) */

MC_ButtonArgs MC_visitButtonArgs(MC_ButtonArgs arg, char* (*acceptTitle)(char*), char* (*acceptPath)(char*), MC_Items (*acceptItems)(MC_Items), char* (*acceptShortcut)(char*))
{
  if (MC_isButtonArgsClick(arg)) {
    return MC_makeButtonArgsClick();
  }
  if (MC_isButtonArgsIcon(arg)) {
    return MC_makeButtonArgsIcon(
        acceptTitle ? acceptTitle(MC_getButtonArgsTitle(arg)) : MC_getButtonArgsTitle(arg),
        acceptPath ? acceptPath(MC_getButtonArgsPath(arg)) : MC_getButtonArgsPath(arg));
  }
  if (MC_isButtonArgsDefault(arg)) {
    return MC_makeButtonArgsDefault(
        acceptItems ? acceptItems(MC_getButtonArgsItems(arg)) : MC_getButtonArgsItems(arg));
  }
  if (MC_isButtonArgsShortcut(arg)) {
    return MC_makeButtonArgsShortcut(
        acceptItems ? acceptItems(MC_getButtonArgsItems(arg)) : MC_getButtonArgsItems(arg),
        acceptShortcut ? acceptShortcut(MC_getButtonArgsShortcut(arg)) : MC_getButtonArgsShortcut(arg));
  }
  ATabort("not a ButtonArgs: %t\n", arg);
  return (MC_ButtonArgs)NULL;
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

/*}}}  */
