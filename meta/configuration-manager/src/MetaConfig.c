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
typedef struct ATerm _MC_ActionDescription;
typedef struct ATerm _MC_ActionDescriptionList;
typedef struct ATerm _MC_ActionType;
typedef struct ATerm _MC_Event;
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
/*{{{  MC_Property MC_makePropertyAction(MC_ActionDescriptionList descriptions, ATerm actions) */

MC_Property MC_makePropertyAction(MC_ActionDescriptionList descriptions, ATerm actions)
{
  return (MC_Property)(ATerm)ATmakeAppl2(MC_afun1, (ATerm) descriptions, (ATerm) actions);
}

/*}}}  */
/*{{{  MC_Property MC_makePropertyExtension(const char* language, const char* extension) */

MC_Property MC_makePropertyExtension(const char* language, const char* extension)
{
  return (MC_Property)(ATerm)ATmakeAppl2(MC_afun2, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(language, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(extension, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_Property MC_makePropertyModulePath(const char* name) */

MC_Property MC_makePropertyModulePath(const char* name)
{
  return (MC_Property)(ATerm)ATmakeAppl1(MC_afun3, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_ActionDescription MC_makeActionDescriptionDefault(MC_ActionType type, MC_Event event) */

MC_ActionDescription MC_makeActionDescriptionDefault(MC_ActionType type, MC_Event event)
{
  return (MC_ActionDescription)(ATerm)ATmakeAppl2(MC_afun4, (ATerm) type, (ATerm) event);
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
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun5);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeTermEditorForModule(const char* moduleId) */

MC_ActionType MC_makeActionTypeTermEditorForModule(const char* moduleId)
{
  return (MC_ActionType)(ATerm)ATmakeAppl1(MC_afun6, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(moduleId, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeEquationsEditor(void) */

MC_ActionType MC_makeActionTypeEquationsEditor(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun7);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeSyntaxEditor(void) */

MC_ActionType MC_makeActionTypeSyntaxEditor(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun8);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeFeedbackList(void) */

MC_ActionType MC_makeActionTypeFeedbackList(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun9);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeTreePanel(void) */

MC_ActionType MC_makeActionTypeTreePanel(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun10);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeModulePopup(const char* moduleId) */

MC_ActionType MC_makeActionTypeModulePopup(const char* moduleId)
{
  return (MC_ActionType)(ATerm)ATmakeAppl1(MC_afun11, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(moduleId, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeNewModulePopup(void) */

MC_ActionType MC_makeActionTypeNewModulePopup(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun12);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeStudioMenubar(void) */

MC_ActionType MC_makeActionTypeStudioMenubar(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun13);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeStudioToolbar(void) */

MC_ActionType MC_makeActionTypeStudioToolbar(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun14);
}

/*}}}  */
/*{{{  MC_ActionType MC_makeActionTypeWildcard(void) */

MC_ActionType MC_makeActionTypeWildcard(void)
{
  return (MC_ActionType)(ATerm)ATmakeAppl0(MC_afun15);
}

/*}}}  */
/*{{{  MC_Event MC_makeEventClick(void) */

MC_Event MC_makeEventClick(void)
{
  return (MC_Event)(ATerm)ATmakeAppl0(MC_afun16);
}

/*}}}  */
/*{{{  MC_Event MC_makeEventIcon(const char* title, const char* path) */

MC_Event MC_makeEventIcon(const char* title, const char* path)
{
  return (MC_Event)(ATerm)ATmakeAppl2(MC_afun17, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(title, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}

/*}}}  */
/*{{{  MC_Event MC_makeEventDefault(MC_Items items) */

MC_Event MC_makeEventDefault(MC_Items items)
{
  return (MC_Event)(ATerm)ATmakeAppl1(MC_afun18, (ATerm) items);
}

/*}}}  */
/*{{{  MC_Event MC_makeEventShortcut(MC_Items items, const char* shortcut) */

MC_Event MC_makeEventShortcut(MC_Items items, const char* shortcut)
{
  return (MC_Event)(ATerm)ATmakeAppl2(MC_afun19, (ATerm) items, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(shortcut, 0, ATtrue)));
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
  return (MC_ModuleName)(ATerm)ATmakeAppl0(MC_afun15);
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
  if (MC_isPropertyAction(arg)) {
    return ATtrue;
  }
  else if (MC_isPropertyExtension(arg)) {
    return ATtrue;
  }
  else if (MC_isPropertyModulePath(arg)) {
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
/*{{{  ATbool MC_hasPropertyDescriptions(MC_Property arg) */

ATbool MC_hasPropertyDescriptions(MC_Property arg)
{
  if (MC_isPropertyAction(arg)) {
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
/*{{{  ATbool MC_hasPropertyActions(MC_Property arg) */

ATbool MC_hasPropertyActions(MC_Property arg)
{
  if (MC_isPropertyAction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm MC_getPropertyActions(MC_Property arg) */

ATerm MC_getPropertyActions(MC_Property arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  MC_Property MC_setPropertyActions(MC_Property arg, ATerm actions) */

MC_Property MC_setPropertyActions(MC_Property arg, ATerm actions)
{
  if (MC_isPropertyAction(arg)) {
    return (MC_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) actions), 1);
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
/*{{{  ATbool MC_hasPropertyName(MC_Property arg) */

ATbool MC_hasPropertyName(MC_Property arg)
{
  if (MC_isPropertyModulePath(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MC_getPropertyName(MC_Property arg) */

char* MC_getPropertyName(MC_Property arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  MC_Property MC_setPropertyName(MC_Property arg, const char* name) */

MC_Property MC_setPropertyName(MC_Property arg, const char* name)
{
  if (MC_isPropertyModulePath(arg)) {
    return (MC_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("Property has no Name: %t\n", arg);
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
/*{{{  ATbool MC_hasActionDescriptionType(MC_ActionDescription arg) */

ATbool MC_hasActionDescriptionType(MC_ActionDescription arg)
{
  if (MC_isActionDescriptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_ActionType MC_getActionDescriptionType(MC_ActionDescription arg) */

MC_ActionType MC_getActionDescriptionType(MC_ActionDescription arg)
{
  
    return (MC_ActionType)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  MC_ActionDescription MC_setActionDescriptionType(MC_ActionDescription arg, MC_ActionType type) */

MC_ActionDescription MC_setActionDescriptionType(MC_ActionDescription arg, MC_ActionType type)
{
  if (MC_isActionDescriptionDefault(arg)) {
    return (MC_ActionDescription)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) type), 0);
  }

  ATabort("ActionDescription has no Type: %t\n", arg);
  return (MC_ActionDescription)NULL;
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
/*{{{  MC_Event MC_getActionDescriptionEvent(MC_ActionDescription arg) */

MC_Event MC_getActionDescriptionEvent(MC_ActionDescription arg)
{
  
    return (MC_Event)ATgetArgument((ATermAppl)arg, 1);
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
/*{{{  ATbool MC_hasActionDescriptionListTail(MC_ActionDescriptionList arg) */

ATbool MC_hasActionDescriptionListTail(MC_ActionDescriptionList arg)
{
  if (MC_isActionDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MC_ActionDescriptionList MC_getActionDescriptionListTail(MC_ActionDescriptionList arg) */

MC_ActionDescriptionList MC_getActionDescriptionListTail(MC_ActionDescriptionList arg)
{
  
    return (MC_ActionDescriptionList)ATgetNext((ATermList)arg);
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
/*{{{  char* MC_getEventTitle(MC_Event arg) */

char* MC_getEventTitle(MC_Event arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
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
/*{{{  ATbool MC_hasEventPath(MC_Event arg) */

ATbool MC_hasEventPath(MC_Event arg)
{
  if (MC_isEventIcon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MC_getEventPath(MC_Event arg) */

char* MC_getEventPath(MC_Event arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
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
/*{{{  ATbool MC_hasEventShortcut(MC_Event arg) */

ATbool MC_hasEventShortcut(MC_Event arg)
{
  if (MC_isEventShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MC_getEventShortcut(MC_Event arg) */

char* MC_getEventShortcut(MC_Event arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
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
/*{{{  MC_Property MC_visitProperty(MC_Property arg, MC_ActionDescriptionList (*acceptDescriptions)(MC_ActionDescriptionList), ATerm (*acceptActions)(ATerm), char* (*acceptLanguage)(char*), char* (*acceptExtension)(char*), char* (*acceptName)(char*)) */

MC_Property MC_visitProperty(MC_Property arg, MC_ActionDescriptionList (*acceptDescriptions)(MC_ActionDescriptionList), ATerm (*acceptActions)(ATerm), char* (*acceptLanguage)(char*), char* (*acceptExtension)(char*), char* (*acceptName)(char*))
{
  if (MC_isPropertyAction(arg)) {
    return MC_makePropertyAction(
        acceptDescriptions ? acceptDescriptions(MC_getPropertyDescriptions(arg)) : MC_getPropertyDescriptions(arg),
        acceptActions ? acceptActions(MC_getPropertyActions(arg)) : MC_getPropertyActions(arg));
  }
  if (MC_isPropertyExtension(arg)) {
    return MC_makePropertyExtension(
        acceptLanguage ? acceptLanguage(MC_getPropertyLanguage(arg)) : MC_getPropertyLanguage(arg),
        acceptExtension ? acceptExtension(MC_getPropertyExtension(arg)) : MC_getPropertyExtension(arg));
  }
  if (MC_isPropertyModulePath(arg)) {
    return MC_makePropertyModulePath(
        acceptName ? acceptName(MC_getPropertyName(arg)) : MC_getPropertyName(arg));
  }
  ATabort("not a Property: %t\n", arg);
  return (MC_Property)NULL;
}

/*}}}  */
/*{{{  MC_ActionDescription MC_visitActionDescription(MC_ActionDescription arg, MC_ActionType (*acceptType)(MC_ActionType), MC_Event (*acceptEvent)(MC_Event)) */

MC_ActionDescription MC_visitActionDescription(MC_ActionDescription arg, MC_ActionType (*acceptType)(MC_ActionType), MC_Event (*acceptEvent)(MC_Event))
{
  if (MC_isActionDescriptionDefault(arg)) {
    return MC_makeActionDescriptionDefault(
        acceptType ? acceptType(MC_getActionDescriptionType(arg)) : MC_getActionDescriptionType(arg),
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

/*}}}  */
