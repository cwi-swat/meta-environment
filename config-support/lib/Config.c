#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Config.h"

ATerm CFG_stringToChars(const char *str) {
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

ATerm CFG_byteToChar(char ch) {
    return (ATerm) ATmakeInt(ch);
}

char *CFG_charsToString(ATerm arg) {
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

char CFG_charToByte(ATerm arg) {
    return (char) ATgetInt((ATermInt) arg);
}


typedef struct ATerm _CFG_KeyModifier;
typedef struct ATerm _CFG_VirtualKey;
typedef struct ATerm _CFG_Color;
typedef struct ATerm _CFG_Configuration;
typedef struct ATerm _CFG_Property;
typedef struct ATerm _CFG_ActionDescription;
typedef struct ATerm _CFG_Event;
typedef struct ATerm _CFG_Item;
typedef struct ATerm _CFG_TextCategoryName;
typedef struct ATerm _CFG_TextAttribute;
typedef struct ATerm _CFG_ShortCut;
typedef struct ATerm _CFG_TextStyle;
typedef struct ATerm _CFG_PropertyList;
typedef struct ATerm _CFG_ActionDescriptionList;
typedef struct ATerm _CFG_TextAttributeMap;
typedef struct ATerm _CFG_ItemList;

void CFG_initConfigApi(void) {
  init_Config_dict();
}

void CFG_protectKeyModifier(CFG_KeyModifier *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectKeyModifier(CFG_KeyModifier *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void CFG_protectVirtualKey(CFG_VirtualKey *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectVirtualKey(CFG_VirtualKey *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void CFG_protectColor(CFG_Color *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectColor(CFG_Color *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void CFG_protectConfiguration(CFG_Configuration *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectConfiguration(CFG_Configuration *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void CFG_protectProperty(CFG_Property *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectProperty(CFG_Property *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void CFG_protectActionDescription(CFG_ActionDescription *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectActionDescription(CFG_ActionDescription *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void CFG_protectEvent(CFG_Event *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectEvent(CFG_Event *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void CFG_protectItem(CFG_Item *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectItem(CFG_Item *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void CFG_protectTextCategoryName(CFG_TextCategoryName *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectTextCategoryName(CFG_TextCategoryName *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void CFG_protectTextAttribute(CFG_TextAttribute *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectTextAttribute(CFG_TextAttribute *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void CFG_protectShortCut(CFG_ShortCut *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectShortCut(CFG_ShortCut *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void CFG_protectTextStyle(CFG_TextStyle *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectTextStyle(CFG_TextStyle *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void CFG_protectPropertyList(CFG_PropertyList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectPropertyList(CFG_PropertyList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void CFG_protectActionDescriptionList(CFG_ActionDescriptionList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectActionDescriptionList(CFG_ActionDescriptionList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void CFG_protectTextAttributeMap(CFG_TextAttributeMap *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectTextAttributeMap(CFG_TextAttributeMap *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

void CFG_protectItemList(CFG_ItemList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

void CFG_unprotectItemList(CFG_ItemList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

CFG_KeyModifier CFG_KeyModifierFromTerm(ATerm t) {
  return (CFG_KeyModifier)t;
}

ATerm CFG_KeyModifierToTerm(CFG_KeyModifier arg) {
  return (ATerm)arg;
}

CFG_VirtualKey CFG_VirtualKeyFromTerm(ATerm t) {
  return (CFG_VirtualKey)t;
}

ATerm CFG_VirtualKeyToTerm(CFG_VirtualKey arg) {
  return (ATerm)arg;
}

CFG_Color CFG_ColorFromTerm(ATerm t) {
  return (CFG_Color)t;
}

ATerm CFG_ColorToTerm(CFG_Color arg) {
  return (ATerm)arg;
}

CFG_Configuration CFG_ConfigurationFromTerm(ATerm t) {
  return (CFG_Configuration)t;
}

ATerm CFG_ConfigurationToTerm(CFG_Configuration arg) {
  return (ATerm)arg;
}

CFG_Property CFG_PropertyFromTerm(ATerm t) {
  return (CFG_Property)t;
}

ATerm CFG_PropertyToTerm(CFG_Property arg) {
  return (ATerm)arg;
}

CFG_ActionDescription CFG_ActionDescriptionFromTerm(ATerm t) {
  return (CFG_ActionDescription)t;
}

ATerm CFG_ActionDescriptionToTerm(CFG_ActionDescription arg) {
  return (ATerm)arg;
}

CFG_Event CFG_EventFromTerm(ATerm t) {
  return (CFG_Event)t;
}

ATerm CFG_EventToTerm(CFG_Event arg) {
  return (ATerm)arg;
}

CFG_Item CFG_ItemFromTerm(ATerm t) {
  return (CFG_Item)t;
}

ATerm CFG_ItemToTerm(CFG_Item arg) {
  return (ATerm)arg;
}

CFG_TextCategoryName CFG_TextCategoryNameFromTerm(ATerm t) {
  return (CFG_TextCategoryName)t;
}

ATerm CFG_TextCategoryNameToTerm(CFG_TextCategoryName arg) {
  return (ATerm)arg;
}

CFG_TextAttribute CFG_TextAttributeFromTerm(ATerm t) {
  return (CFG_TextAttribute)t;
}

ATerm CFG_TextAttributeToTerm(CFG_TextAttribute arg) {
  return (ATerm)arg;
}

CFG_ShortCut CFG_ShortCutFromTerm(ATerm t) {
  return (CFG_ShortCut)t;
}

ATerm CFG_ShortCutToTerm(CFG_ShortCut arg) {
  return (ATerm)arg;
}

CFG_TextStyle CFG_TextStyleFromTerm(ATerm t) {
  return (CFG_TextStyle)t;
}

ATerm CFG_TextStyleToTerm(CFG_TextStyle arg) {
  return (ATerm)arg;
}

CFG_PropertyList CFG_PropertyListFromTerm(ATerm t) {
  return (CFG_PropertyList)t;
}

ATerm CFG_PropertyListToTerm(CFG_PropertyList arg) {
  return (ATerm)arg;
}

CFG_ActionDescriptionList CFG_ActionDescriptionListFromTerm(ATerm t) {
  return (CFG_ActionDescriptionList)t;
}

ATerm CFG_ActionDescriptionListToTerm(CFG_ActionDescriptionList arg) {
  return (ATerm)arg;
}

CFG_TextAttributeMap CFG_TextAttributeMapFromTerm(ATerm t) {
  return (CFG_TextAttributeMap)t;
}

ATerm CFG_TextAttributeMapToTerm(CFG_TextAttributeMap arg) {
  return (ATerm)arg;
}

CFG_ItemList CFG_ItemListFromTerm(ATerm t) {
  return (CFG_ItemList)t;
}

ATerm CFG_ItemListToTerm(CFG_ItemList arg) {
  return (ATerm)arg;
}

int CFG_getPropertyListLength (CFG_PropertyList arg) {
  return ATgetLength((ATermList) arg);
}

CFG_PropertyList CFG_reversePropertyList(CFG_PropertyList arg) {
  return (CFG_PropertyList) ATreverse((ATermList) arg);
}

CFG_PropertyList CFG_appendPropertyList(CFG_PropertyList arg, CFG_Property elem) {
  return (CFG_PropertyList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

CFG_PropertyList CFG_concatPropertyList(CFG_PropertyList arg0, CFG_PropertyList arg1) {
  return (CFG_PropertyList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

CFG_PropertyList CFG_slicePropertyList(CFG_PropertyList arg, int start, int end) {
  return (CFG_PropertyList) ATgetSlice((ATermList) arg, start, end);
}

CFG_Property CFG_getPropertyListPropertyAt(CFG_PropertyList arg, int index) {
 return (CFG_Property)ATelementAt((ATermList) arg,index);
}

CFG_PropertyList CFG_replacePropertyListPropertyAt(CFG_PropertyList arg, CFG_Property elem, int index) {
 return (CFG_PropertyList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

CFG_PropertyList CFG_makePropertyList2(CFG_Property elem1, CFG_Property elem2) {
  return (CFG_PropertyList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}

CFG_PropertyList CFG_makePropertyList3(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3) {
  return (CFG_PropertyList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}

CFG_PropertyList CFG_makePropertyList4(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3, CFG_Property elem4) {
  return (CFG_PropertyList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}

CFG_PropertyList CFG_makePropertyList5(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3, CFG_Property elem4, CFG_Property elem5) {
  return (CFG_PropertyList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}

CFG_PropertyList CFG_makePropertyList6(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3, CFG_Property elem4, CFG_Property elem5, CFG_Property elem6) {
  return (CFG_PropertyList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
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

int CFG_getTextAttributeMapLength (CFG_TextAttributeMap arg) {
  return ATgetLength((ATermList) arg);
}

CFG_TextAttributeMap CFG_reverseTextAttributeMap(CFG_TextAttributeMap arg) {
  return (CFG_TextAttributeMap) ATreverse((ATermList) arg);
}

CFG_TextAttributeMap CFG_appendTextAttributeMap(CFG_TextAttributeMap arg, CFG_TextAttribute elem) {
  return (CFG_TextAttributeMap) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

CFG_TextAttributeMap CFG_concatTextAttributeMap(CFG_TextAttributeMap arg0, CFG_TextAttributeMap arg1) {
  return (CFG_TextAttributeMap) ATconcat((ATermList) arg0, (ATermList) arg1);
}

CFG_TextAttributeMap CFG_sliceTextAttributeMap(CFG_TextAttributeMap arg, int start, int end) {
  return (CFG_TextAttributeMap) ATgetSlice((ATermList) arg, start, end);
}

CFG_TextAttribute CFG_getTextAttributeMapTextAttributeAt(CFG_TextAttributeMap arg, int index) {
 return (CFG_TextAttribute)ATelementAt((ATermList) arg,index);
}

CFG_TextAttributeMap CFG_replaceTextAttributeMapTextAttributeAt(CFG_TextAttributeMap arg, CFG_TextAttribute elem, int index) {
 return (CFG_TextAttributeMap) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

CFG_TextAttributeMap CFG_makeTextAttributeMap2(CFG_TextAttribute elem1, CFG_TextAttribute elem2) {
  return (CFG_TextAttributeMap) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}

CFG_TextAttributeMap CFG_makeTextAttributeMap3(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3) {
  return (CFG_TextAttributeMap) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}

CFG_TextAttributeMap CFG_makeTextAttributeMap4(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3, CFG_TextAttribute elem4) {
  return (CFG_TextAttributeMap) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}

CFG_TextAttributeMap CFG_makeTextAttributeMap5(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3, CFG_TextAttribute elem4, CFG_TextAttribute elem5) {
  return (CFG_TextAttributeMap) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}

CFG_TextAttributeMap CFG_makeTextAttributeMap6(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3, CFG_TextAttribute elem4, CFG_TextAttribute elem5, CFG_TextAttribute elem6) {
  return (CFG_TextAttributeMap) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

int CFG_getItemListLength (CFG_ItemList arg) {
  return ATgetLength((ATermList) arg);
}

CFG_ItemList CFG_reverseItemList(CFG_ItemList arg) {
  return (CFG_ItemList) ATreverse((ATermList) arg);
}

CFG_ItemList CFG_appendItemList(CFG_ItemList arg, CFG_Item elem) {
  return (CFG_ItemList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

CFG_ItemList CFG_concatItemList(CFG_ItemList arg0, CFG_ItemList arg1) {
  return (CFG_ItemList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

CFG_ItemList CFG_sliceItemList(CFG_ItemList arg, int start, int end) {
  return (CFG_ItemList) ATgetSlice((ATermList) arg, start, end);
}

CFG_Item CFG_getItemListItemAt(CFG_ItemList arg, int index) {
 return (CFG_Item)ATelementAt((ATermList) arg,index);
}

CFG_ItemList CFG_replaceItemListItemAt(CFG_ItemList arg, CFG_Item elem, int index) {
 return (CFG_ItemList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

CFG_ItemList CFG_makeItemList2(CFG_Item elem1, CFG_Item elem2) {
  return (CFG_ItemList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}

CFG_ItemList CFG_makeItemList3(CFG_Item elem1, CFG_Item elem2, CFG_Item elem3) {
  return (CFG_ItemList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}

CFG_ItemList CFG_makeItemList4(CFG_Item elem1, CFG_Item elem2, CFG_Item elem3, CFG_Item elem4) {
  return (CFG_ItemList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}

CFG_ItemList CFG_makeItemList5(CFG_Item elem1, CFG_Item elem2, CFG_Item elem3, CFG_Item elem4, CFG_Item elem5) {
  return (CFG_ItemList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}

CFG_ItemList CFG_makeItemList6(CFG_Item elem1, CFG_Item elem2, CFG_Item elem3, CFG_Item elem4, CFG_Item elem5, CFG_Item elem6) {
  return (CFG_ItemList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

CFG_KeyModifier CFG_makeKeyModifierMUnderscoreALT(void) {
  return (CFG_KeyModifier)(ATerm)ATmakeAppl0(CFG_afun0);
}
CFG_KeyModifier CFG_makeKeyModifierMUnderscoreCTRL(void) {
  return (CFG_KeyModifier)(ATerm)ATmakeAppl0(CFG_afun1);
}
CFG_KeyModifier CFG_makeKeyModifierMUnderscoreSHIFT(void) {
  return (CFG_KeyModifier)(ATerm)ATmakeAppl0(CFG_afun2);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore0(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun3);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore1(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun4);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore2(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun5);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore3(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun6);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore4(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun7);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore5(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun8);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore6(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun9);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore7(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun10);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore8(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun11);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore9(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun12);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreA(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun13);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreB(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun14);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreC(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun15);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreD(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun16);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun17);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun18);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreG(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun19);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreH(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun20);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreI(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun21);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreJ(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun22);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreK(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun23);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreL(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun24);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreM(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun25);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreN(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun26);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreO(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun27);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreP(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun28);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreQ(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun29);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreR(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun30);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreS(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun31);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun32);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreU(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun33);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreV(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun34);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreW(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun35);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreX(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun36);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreY(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun37);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreZ(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun38);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreAMPERSAND(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun39);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreASTERISK(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun40);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreAT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun41);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBACKUnderscoreQUOTE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun42);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBACKUnderscoreSLASH(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun43);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBACKUnderscoreSPACE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun44);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBEGIN(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun45);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBRACEUnderscoreLEFT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun46);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBRACEUnderscoreRIGHT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun47);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreCIRCUMFLEX(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun48);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreCLEAR(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun49);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreCLOSEUnderscoreBRACKET(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun50);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreCOLON(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun51);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreCOMMA(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun52);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreDECIMAL(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun53);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreDELETE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun54);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreDIVIDE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun55);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreDOLLAR(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun56);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreDOWN(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun57);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreEND(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun58);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreENTER(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun59);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreEQUALS(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun60);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreESCAPE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun61);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreEXCLAMATIONUnderscoreMARK(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun62);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF1(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun63);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF2(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun64);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF3(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun65);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF4(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun66);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF5(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun67);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF6(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun68);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF7(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun69);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF8(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun70);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF9(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun71);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF10(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun72);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF11(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun73);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF12(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun74);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreGREATER(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun75);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreHOME(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun76);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreINSERT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun77);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreLEFT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun78);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreLEFTUnderscorePARENTHESIS(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun79);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreMINUS(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun80);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreMULTIPLY(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun81);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreNUMBERUnderscoreSIGN(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun82);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreOPENUnderscoreBRACKET(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun83);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePAGEUnderscoreDOWN(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun84);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePAGEUnderscoreUP(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun85);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePAUSE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun86);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePERIOD(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun87);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePLUS(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun88);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePRINTSCREEN(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun89);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreQUOTE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun90);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreQUOTEDBL(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun91);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreRIGHT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun92);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreRIGHTUnderscorePARENTHESIS(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun93);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreSEMICOLON(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun94);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreSLASH(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun95);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreSPACE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun96);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreSUBTRACT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun97);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreTAB(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun98);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreUNDERSCORE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun99);
}
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreUP(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun100);
}
CFG_Color CFG_makeColorRgb(int red, int green, int blue) {
  return (CFG_Color)(ATerm)ATmakeAppl3(CFG_afun101, (ATerm) (ATerm) ATmakeInt(red), (ATerm) (ATerm) ATmakeInt(green), (ATerm) (ATerm) ATmakeInt(blue));
}
CFG_Configuration CFG_makeConfigurationConfiguration(CFG_PropertyList list) {
  return (CFG_Configuration)(ATerm)ATmakeAppl1(CFG_afun102, (ATerm) list);
}
CFG_Property CFG_makePropertyImport(const char* path) {
  return (CFG_Property)(ATerm)ATmakeAppl1(CFG_afun103, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}
CFG_Property CFG_makePropertyAction(CFG_ActionDescriptionList list, const char* action) {
  return (CFG_Property)(ATerm)ATmakeAppl2(CFG_afun104, (ATerm) list, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(action, 0, ATtrue)));
}
CFG_Property CFG_makePropertyExtension(const char* language, const char* extension) {
  return (CFG_Property)(ATerm)ATmakeAppl2(CFG_afun105, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(language, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(extension, 0, ATtrue)));
}
CFG_Property CFG_makePropertyLibraryPath(const char* label, const char* path) {
  return (CFG_Property)(ATerm)ATmakeAppl2(CFG_afun106, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(label, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}
CFG_Property CFG_makePropertyModulePath(const char* label, const char* path) {
  return (CFG_Property)(ATerm)ATmakeAppl2(CFG_afun107, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(label, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}
CFG_Property CFG_makePropertyTextCategory(CFG_TextCategoryName category, CFG_TextAttributeMap map) {
  return (CFG_Property)(ATerm)ATmakeAppl2(CFG_afun108, (ATerm) category, (ATerm) map);
}
CFG_ActionDescription CFG_makeActionDescriptionDescription(ATerm context, CFG_Event event) {
  return (CFG_ActionDescription)(ATerm)ATmakeAppl2(CFG_afun109, (ATerm) context, (ATerm) event);
}
CFG_Event CFG_makeEventClick(void) {
  return (CFG_Event)(ATerm)ATmakeAppl0(CFG_afun110);
}
CFG_Event CFG_makeEventIcon(const char* title, const char* path) {
  return (CFG_Event)(ATerm)ATmakeAppl2(CFG_afun111, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(title, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}
CFG_Event CFG_makeEventMenu(CFG_ItemList list) {
  return (CFG_Event)(ATerm)ATmakeAppl1(CFG_afun112, (ATerm) list);
}
CFG_Event CFG_makeEventMenuShortcut(CFG_ItemList list, CFG_ShortCut shortcut) {
  return (CFG_Event)(ATerm)ATmakeAppl2(CFG_afun113, (ATerm) list, (ATerm) shortcut);
}
CFG_Item CFG_makeItemLabel(const char* name) {
  return (CFG_Item)(ATerm)ATmakeAppl1(CFG_afun114, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}
CFG_TextCategoryName CFG_makeTextCategoryNameFocus(void) {
  return (CFG_TextCategoryName)(ATerm)ATmakeAppl0(CFG_afun115);
}
CFG_TextCategoryName CFG_makeTextCategoryNameSelection(void) {
  return (CFG_TextCategoryName)(ATerm)ATmakeAppl0(CFG_afun116);
}
CFG_TextCategoryName CFG_makeTextCategoryNameNormal(void) {
  return (CFG_TextCategoryName)(ATerm)ATmakeAppl0(CFG_afun117);
}
CFG_TextCategoryName CFG_makeTextCategoryNameExtern(const char* name) {
  return (CFG_TextCategoryName)(ATerm)ATmakeAppl1(CFG_afun118, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}
CFG_TextAttribute CFG_makeTextAttributeForegroundColor(CFG_Color color) {
  return (CFG_TextAttribute)(ATerm)ATmakeAppl1(CFG_afun119, (ATerm) color);
}
CFG_TextAttribute CFG_makeTextAttributeBackgroundColor(CFG_Color color) {
  return (CFG_TextAttribute)(ATerm)ATmakeAppl1(CFG_afun120, (ATerm) color);
}
CFG_TextAttribute CFG_makeTextAttributeStyle(CFG_TextStyle style) {
  return (CFG_TextAttribute)(ATerm)ATmakeAppl1(CFG_afun121, (ATerm) style);
}
CFG_TextAttribute CFG_makeTextAttributeFont(const char* name) {
  return (CFG_TextAttribute)(ATerm)ATmakeAppl1(CFG_afun122, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}
CFG_TextAttribute CFG_makeTextAttributeSize(int point) {
  return (CFG_TextAttribute)(ATerm)ATmakeAppl1(CFG_afun123, (ATerm) (ATerm) ATmakeInt(point));
}
CFG_ShortCut CFG_makeShortCutShortcut(CFG_KeyModifier modifier, CFG_VirtualKey key) {
  return (CFG_ShortCut)(ATerm)ATmakeAppl2(CFG_afun124, (ATerm) modifier, (ATerm) key);
}
CFG_TextStyle CFG_makeTextStyleBold(void) {
  return (CFG_TextStyle)(ATerm)ATmakeAppl0(CFG_afun125);
}
CFG_TextStyle CFG_makeTextStyleItalics(void) {
  return (CFG_TextStyle)(ATerm)ATmakeAppl0(CFG_afun126);
}
CFG_TextStyle CFG_makeTextStyleUnderlined(void) {
  return (CFG_TextStyle)(ATerm)ATmakeAppl0(CFG_afun127);
}
CFG_PropertyList CFG_makePropertyListEmpty(void) {
  return (CFG_PropertyList)(ATerm)ATempty;
}
CFG_PropertyList CFG_makePropertyListSingle(CFG_Property head) {
  return (CFG_PropertyList)(ATerm)ATmakeList1((ATerm) head);
}
CFG_PropertyList CFG_makePropertyListMany(CFG_Property head, CFG_PropertyList tail) {
  return (CFG_PropertyList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
CFG_ActionDescriptionList CFG_makeActionDescriptionListEmpty(void) {
  return (CFG_ActionDescriptionList)(ATerm)ATempty;
}
CFG_ActionDescriptionList CFG_makeActionDescriptionListSingle(CFG_ActionDescription head) {
  return (CFG_ActionDescriptionList)(ATerm)ATmakeList1((ATerm) head);
}
CFG_ActionDescriptionList CFG_makeActionDescriptionListMany(CFG_ActionDescription head, CFG_ActionDescriptionList tail) {
  return (CFG_ActionDescriptionList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
CFG_TextAttributeMap CFG_makeTextAttributeMapEmpty(void) {
  return (CFG_TextAttributeMap)(ATerm)ATempty;
}
CFG_TextAttributeMap CFG_makeTextAttributeMapSingle(CFG_TextAttribute head) {
  return (CFG_TextAttributeMap)(ATerm)ATmakeList1((ATerm) head);
}
CFG_TextAttributeMap CFG_makeTextAttributeMapMany(CFG_TextAttribute head, CFG_TextAttributeMap tail) {
  return (CFG_TextAttributeMap)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
CFG_ItemList CFG_makeItemListEmpty(void) {
  return (CFG_ItemList)(ATerm)ATempty;
}
CFG_ItemList CFG_makeItemListSingle(CFG_Item head) {
  return (CFG_ItemList)(ATerm)ATmakeList1((ATerm) head);
}
CFG_ItemList CFG_makeItemListMany(CFG_Item head, CFG_ItemList tail) {
  return (CFG_ItemList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

ATbool CFG_isEqualKeyModifier(CFG_KeyModifier arg0, CFG_KeyModifier arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualVirtualKey(CFG_VirtualKey arg0, CFG_VirtualKey arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualColor(CFG_Color arg0, CFG_Color arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualConfiguration(CFG_Configuration arg0, CFG_Configuration arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualProperty(CFG_Property arg0, CFG_Property arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualActionDescription(CFG_ActionDescription arg0, CFG_ActionDescription arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualEvent(CFG_Event arg0, CFG_Event arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualItem(CFG_Item arg0, CFG_Item arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualTextCategoryName(CFG_TextCategoryName arg0, CFG_TextCategoryName arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualTextAttribute(CFG_TextAttribute arg0, CFG_TextAttribute arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualShortCut(CFG_ShortCut arg0, CFG_ShortCut arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualTextStyle(CFG_TextStyle arg0, CFG_TextStyle arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualPropertyList(CFG_PropertyList arg0, CFG_PropertyList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualActionDescriptionList(CFG_ActionDescriptionList arg0, CFG_ActionDescriptionList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualTextAttributeMap(CFG_TextAttributeMap arg0, CFG_TextAttributeMap arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isEqualItemList(CFG_ItemList arg0, CFG_ItemList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CFG_isValidKeyModifier(CFG_KeyModifier arg) {
  if (CFG_isKeyModifierMUnderscoreALT(arg)) {
    return ATtrue;
  }
  else if (CFG_isKeyModifierMUnderscoreCTRL(arg)) {
    return ATtrue;
  }
  else if (CFG_isKeyModifierMUnderscoreSHIFT(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool CFG_isKeyModifierMUnderscoreALT(CFG_KeyModifier arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternKeyModifierMUnderscoreALT);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isKeyModifierMUnderscoreCTRL(CFG_KeyModifier arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternKeyModifierMUnderscoreCTRL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isKeyModifierMUnderscoreSHIFT(CFG_KeyModifier arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternKeyModifierMUnderscoreSHIFT);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool CFG_isValidVirtualKey(CFG_VirtualKey arg) {
  if (CFG_isVirtualKeyVKUnderscore0(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscore1(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscore2(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscore3(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscore4(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscore5(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscore6(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscore7(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscore8(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscore9(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreA(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreB(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreC(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreD(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreE(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreF(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreG(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreH(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreI(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreJ(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreK(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreL(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreM(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreN(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreO(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreP(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreQ(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreR(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreS(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreT(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreU(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreV(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreW(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreX(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreY(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreZ(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreAMPERSAND(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreASTERISK(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreAT(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreBACKUnderscoreQUOTE(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreBACKUnderscoreSLASH(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreBACKUnderscoreSPACE(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreBEGIN(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreBRACEUnderscoreLEFT(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreBRACEUnderscoreRIGHT(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreCIRCUMFLEX(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreCLEAR(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreCLOSEUnderscoreBRACKET(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreCOLON(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreCOMMA(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreDECIMAL(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreDELETE(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreDIVIDE(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreDOLLAR(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreDOWN(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreEND(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreENTER(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreEQUALS(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreESCAPE(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreEXCLAMATIONUnderscoreMARK(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreF1(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreF2(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreF3(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreF4(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreF5(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreF6(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreF7(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreF8(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreF9(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreF10(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreF11(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreF12(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreGREATER(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreHOME(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreINSERT(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreLEFT(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreLEFTUnderscorePARENTHESIS(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreMINUS(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreMULTIPLY(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreNUMBERUnderscoreSIGN(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreOPENUnderscoreBRACKET(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscorePAGEUnderscoreDOWN(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscorePAGEUnderscoreUP(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscorePAUSE(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscorePERIOD(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscorePLUS(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscorePRINTSCREEN(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreQUOTE(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreQUOTEDBL(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreRIGHT(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreRIGHTUnderscorePARENTHESIS(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreSEMICOLON(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreSLASH(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreSPACE(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreSUBTRACT(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreTAB(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreUNDERSCORE(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualKeyVKUnderscoreUP(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool CFG_isVirtualKeyVKUnderscore0(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscore0);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscore1(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscore1);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscore2(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscore2);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscore3(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscore3);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscore4(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscore4);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscore5(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscore5);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscore6(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscore6);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscore7(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscore7);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscore8(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscore8);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscore9(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscore9);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreA(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreA);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreB(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreB);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreC(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreC);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreD(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreD);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreE(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreE);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreF(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreF);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreG(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreG);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreH(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreH);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreI(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreI);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreJ(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreJ);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreK(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreK);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreL(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreM(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreM);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreN(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreN);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreO(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreO);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreP(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreP);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreQ(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreQ);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreR(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreR);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreS(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreS);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreT(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreT);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreU(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreU);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreV(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreV);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreW(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreW);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreX(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreX);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreY(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreY);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreZ(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreZ);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreAMPERSAND(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreAMPERSAND);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreASTERISK(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreASTERISK);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreAT(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreAT);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreBACKUnderscoreQUOTE(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreBACKUnderscoreQUOTE);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreBACKUnderscoreSLASH(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreBACKUnderscoreSLASH);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreBACKUnderscoreSPACE(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreBACKUnderscoreSPACE);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreBEGIN(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreBEGIN);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreBRACEUnderscoreLEFT(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreBRACEUnderscoreLEFT);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreBRACEUnderscoreRIGHT(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreBRACEUnderscoreRIGHT);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreCIRCUMFLEX(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreCIRCUMFLEX);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreCLEAR(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreCLEAR);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreCLOSEUnderscoreBRACKET(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreCLOSEUnderscoreBRACKET);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreCOLON(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreCOLON);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreCOMMA(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreCOMMA);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreDECIMAL(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreDECIMAL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreDELETE(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreDELETE);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreDIVIDE(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreDIVIDE);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreDOLLAR(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreDOLLAR);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreDOWN(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreDOWN);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreEND(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreEND);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreENTER(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreENTER);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreEQUALS(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreEQUALS);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreESCAPE(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreESCAPE);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreEXCLAMATIONUnderscoreMARK(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreEXCLAMATIONUnderscoreMARK);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreF1(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreF1);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreF2(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreF2);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreF3(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreF3);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreF4(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreF4);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreF5(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreF5);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreF6(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreF6);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreF7(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreF7);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreF8(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreF8);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreF9(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreF9);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreF10(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreF10);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreF11(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreF11);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreF12(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreF12);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreGREATER(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreGREATER);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreHOME(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreHOME);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreINSERT(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreINSERT);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreLEFT(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreLEFT);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreLEFTUnderscorePARENTHESIS(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreLEFTUnderscorePARENTHESIS);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreMINUS(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreMINUS);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreMULTIPLY(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreMULTIPLY);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreNUMBERUnderscoreSIGN(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreNUMBERUnderscoreSIGN);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreOPENUnderscoreBRACKET(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreOPENUnderscoreBRACKET);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscorePAGEUnderscoreDOWN(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscorePAGEUnderscoreDOWN);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscorePAGEUnderscoreUP(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscorePAGEUnderscoreUP);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscorePAUSE(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscorePAUSE);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscorePERIOD(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscorePERIOD);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscorePLUS(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscorePLUS);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscorePRINTSCREEN(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscorePRINTSCREEN);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreQUOTE(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreQUOTE);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreQUOTEDBL(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreQUOTEDBL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreRIGHT(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreRIGHT);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreRIGHTUnderscorePARENTHESIS(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreRIGHTUnderscorePARENTHESIS);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreSEMICOLON(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreSEMICOLON);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreSLASH(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreSLASH);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreSPACE(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreSPACE);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreSUBTRACT(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreSUBTRACT);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreTAB(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreTAB);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreUNDERSCORE(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreUNDERSCORE);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isVirtualKeyVKUnderscoreUP(CFG_VirtualKey arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternVirtualKeyVKUnderscoreUP);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool CFG_isValidColor(CFG_Color arg) {
  if (CFG_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool CFG_isColorRgb(CFG_Color arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternColorRgb, NULL, NULL, NULL));
#endif
  return ATtrue;
}

ATbool CFG_hasColorRed(CFG_Color arg) {
  if (CFG_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasColorGreen(CFG_Color arg) {
  if (CFG_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasColorBlue(CFG_Color arg) {
  if (CFG_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

int CFG_getColorRed(CFG_Color arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

int CFG_getColorGreen(CFG_Color arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

int CFG_getColorBlue(CFG_Color arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

CFG_Color CFG_setColorRed(CFG_Color arg, int red) {
  if (CFG_isColorRgb(arg)) {
    return (CFG_Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(red)), 0);
  }

  ATabort("Color has no Red: %t\n", arg);
  return (CFG_Color)NULL;
}

CFG_Color CFG_setColorGreen(CFG_Color arg, int green) {
  if (CFG_isColorRgb(arg)) {
    return (CFG_Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(green)), 1);
  }

  ATabort("Color has no Green: %t\n", arg);
  return (CFG_Color)NULL;
}

CFG_Color CFG_setColorBlue(CFG_Color arg, int blue) {
  if (CFG_isColorRgb(arg)) {
    return (CFG_Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(blue)), 2);
  }

  ATabort("Color has no Blue: %t\n", arg);
  return (CFG_Color)NULL;
}

ATbool CFG_isValidConfiguration(CFG_Configuration arg) {
  if (CFG_isConfigurationConfiguration(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool CFG_isConfigurationConfiguration(CFG_Configuration arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternConfigurationConfiguration, NULL));
#endif
  return ATtrue;
}

ATbool CFG_hasConfigurationList(CFG_Configuration arg) {
  if (CFG_isConfigurationConfiguration(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

CFG_PropertyList CFG_getConfigurationList(CFG_Configuration arg) {
  
    return (CFG_PropertyList)ATgetArgument((ATermAppl)arg, 0);
}

CFG_Configuration CFG_setConfigurationList(CFG_Configuration arg, CFG_PropertyList list) {
  if (CFG_isConfigurationConfiguration(arg)) {
    return (CFG_Configuration)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }

  ATabort("Configuration has no List: %t\n", arg);
  return (CFG_Configuration)NULL;
}

ATbool CFG_isValidProperty(CFG_Property arg) {
  if (CFG_isPropertyImport(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyAction(arg)) {
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

inline ATbool CFG_isPropertyImport(CFG_Property arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternPropertyImport, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isPropertyAction(CFG_Property arg) {
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

inline ATbool CFG_isPropertyExtension(CFG_Property arg) {
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

inline ATbool CFG_isPropertyLibraryPath(CFG_Property arg) {
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

inline ATbool CFG_isPropertyModulePath(CFG_Property arg) {
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

inline ATbool CFG_isPropertyTextCategory(CFG_Property arg) {
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

ATbool CFG_hasPropertyPath(CFG_Property arg) {
  if (CFG_isPropertyImport(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyLibraryPath(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyModulePath(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasPropertyList(CFG_Property arg) {
  if (CFG_isPropertyAction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasPropertyAction(CFG_Property arg) {
  if (CFG_isPropertyAction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasPropertyLanguage(CFG_Property arg) {
  if (CFG_isPropertyExtension(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasPropertyExtension(CFG_Property arg) {
  if (CFG_isPropertyExtension(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasPropertyLabel(CFG_Property arg) {
  if (CFG_isPropertyLibraryPath(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyModulePath(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasPropertyCategory(CFG_Property arg) {
  if (CFG_isPropertyTextCategory(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasPropertyMap(CFG_Property arg) {
  if (CFG_isPropertyTextCategory(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

char* CFG_getPropertyPath(CFG_Property arg) {
  if (CFG_isPropertyImport(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (CFG_isPropertyLibraryPath(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

CFG_ActionDescriptionList CFG_getPropertyList(CFG_Property arg) {
  
    return (CFG_ActionDescriptionList)ATgetArgument((ATermAppl)arg, 0);
}

char* CFG_getPropertyAction(CFG_Property arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

char* CFG_getPropertyLanguage(CFG_Property arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

char* CFG_getPropertyExtension(CFG_Property arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

char* CFG_getPropertyLabel(CFG_Property arg) {
  if (CFG_isPropertyLibraryPath(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

CFG_TextCategoryName CFG_getPropertyCategory(CFG_Property arg) {
  
    return (CFG_TextCategoryName)ATgetArgument((ATermAppl)arg, 0);
}

CFG_TextAttributeMap CFG_getPropertyMap(CFG_Property arg) {
  
    return (CFG_TextAttributeMap)ATgetArgument((ATermAppl)arg, 1);
}

CFG_Property CFG_setPropertyPath(CFG_Property arg, const char* path) {
  if (CFG_isPropertyImport(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 0);
  }
  else if (CFG_isPropertyLibraryPath(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 1);
  }
  else if (CFG_isPropertyModulePath(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 1);
  }

  ATabort("Property has no Path: %t\n", arg);
  return (CFG_Property)NULL;
}

CFG_Property CFG_setPropertyList(CFG_Property arg, CFG_ActionDescriptionList list) {
  if (CFG_isPropertyAction(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }

  ATabort("Property has no List: %t\n", arg);
  return (CFG_Property)NULL;
}

CFG_Property CFG_setPropertyAction(CFG_Property arg, const char* action) {
  if (CFG_isPropertyAction(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(action, 0, ATtrue))), 1);
  }

  ATabort("Property has no Action: %t\n", arg);
  return (CFG_Property)NULL;
}

CFG_Property CFG_setPropertyLanguage(CFG_Property arg, const char* language) {
  if (CFG_isPropertyExtension(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(language, 0, ATtrue))), 0);
  }

  ATabort("Property has no Language: %t\n", arg);
  return (CFG_Property)NULL;
}

CFG_Property CFG_setPropertyExtension(CFG_Property arg, const char* extension) {
  if (CFG_isPropertyExtension(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(extension, 0, ATtrue))), 1);
  }

  ATabort("Property has no Extension: %t\n", arg);
  return (CFG_Property)NULL;
}

CFG_Property CFG_setPropertyLabel(CFG_Property arg, const char* label) {
  if (CFG_isPropertyLibraryPath(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(label, 0, ATtrue))), 0);
  }
  else if (CFG_isPropertyModulePath(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(label, 0, ATtrue))), 0);
  }

  ATabort("Property has no Label: %t\n", arg);
  return (CFG_Property)NULL;
}

CFG_Property CFG_setPropertyCategory(CFG_Property arg, CFG_TextCategoryName category) {
  if (CFG_isPropertyTextCategory(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) category), 0);
  }

  ATabort("Property has no Category: %t\n", arg);
  return (CFG_Property)NULL;
}

CFG_Property CFG_setPropertyMap(CFG_Property arg, CFG_TextAttributeMap map) {
  if (CFG_isPropertyTextCategory(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) map), 1);
  }

  ATabort("Property has no Map: %t\n", arg);
  return (CFG_Property)NULL;
}

ATbool CFG_isValidActionDescription(CFG_ActionDescription arg) {
  if (CFG_isActionDescriptionDescription(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool CFG_isActionDescriptionDescription(CFG_ActionDescription arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternActionDescriptionDescription, NULL, NULL));
#endif
  return ATtrue;
}

ATbool CFG_hasActionDescriptionContext(CFG_ActionDescription arg) {
  if (CFG_isActionDescriptionDescription(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasActionDescriptionEvent(CFG_ActionDescription arg) {
  if (CFG_isActionDescriptionDescription(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATerm CFG_getActionDescriptionContext(CFG_ActionDescription arg) {
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 0);
}

CFG_Event CFG_getActionDescriptionEvent(CFG_ActionDescription arg) {
  
    return (CFG_Event)ATgetArgument((ATermAppl)arg, 1);
}

CFG_ActionDescription CFG_setActionDescriptionContext(CFG_ActionDescription arg, ATerm context) {
  if (CFG_isActionDescriptionDescription(arg)) {
    return (CFG_ActionDescription)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) context), 0);
  }

  ATabort("ActionDescription has no Context: %t\n", arg);
  return (CFG_ActionDescription)NULL;
}

CFG_ActionDescription CFG_setActionDescriptionEvent(CFG_ActionDescription arg, CFG_Event event) {
  if (CFG_isActionDescriptionDescription(arg)) {
    return (CFG_ActionDescription)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) event), 1);
  }

  ATabort("ActionDescription has no Event: %t\n", arg);
  return (CFG_ActionDescription)NULL;
}

ATbool CFG_isValidEvent(CFG_Event arg) {
  if (CFG_isEventClick(arg)) {
    return ATtrue;
  }
  else if (CFG_isEventIcon(arg)) {
    return ATtrue;
  }
  else if (CFG_isEventMenu(arg)) {
    return ATtrue;
  }
  else if (CFG_isEventMenuShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool CFG_isEventClick(CFG_Event arg) {
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

inline ATbool CFG_isEventIcon(CFG_Event arg) {
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

inline ATbool CFG_isEventMenu(CFG_Event arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternEventMenu, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isEventMenuShortcut(CFG_Event arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CFG_patternEventMenuShortcut, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool CFG_hasEventTitle(CFG_Event arg) {
  if (CFG_isEventIcon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasEventPath(CFG_Event arg) {
  if (CFG_isEventIcon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasEventList(CFG_Event arg) {
  if (CFG_isEventMenu(arg)) {
    return ATtrue;
  }
  else if (CFG_isEventMenuShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasEventShortcut(CFG_Event arg) {
  if (CFG_isEventMenuShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

char* CFG_getEventTitle(CFG_Event arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

char* CFG_getEventPath(CFG_Event arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

CFG_ItemList CFG_getEventList(CFG_Event arg) {
  if (CFG_isEventMenu(arg)) {
    return (CFG_ItemList)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (CFG_ItemList)ATgetArgument((ATermAppl)arg, 0);
}

CFG_ShortCut CFG_getEventShortcut(CFG_Event arg) {
  
    return (CFG_ShortCut)ATgetArgument((ATermAppl)arg, 1);
}

CFG_Event CFG_setEventTitle(CFG_Event arg, const char* title) {
  if (CFG_isEventIcon(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(title, 0, ATtrue))), 0);
  }

  ATabort("Event has no Title: %t\n", arg);
  return (CFG_Event)NULL;
}

CFG_Event CFG_setEventPath(CFG_Event arg, const char* path) {
  if (CFG_isEventIcon(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 1);
  }

  ATabort("Event has no Path: %t\n", arg);
  return (CFG_Event)NULL;
}

CFG_Event CFG_setEventList(CFG_Event arg, CFG_ItemList list) {
  if (CFG_isEventMenu(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }
  else if (CFG_isEventMenuShortcut(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }

  ATabort("Event has no List: %t\n", arg);
  return (CFG_Event)NULL;
}

CFG_Event CFG_setEventShortcut(CFG_Event arg, CFG_ShortCut shortcut) {
  if (CFG_isEventMenuShortcut(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) shortcut), 1);
  }

  ATabort("Event has no Shortcut: %t\n", arg);
  return (CFG_Event)NULL;
}

ATbool CFG_isValidItem(CFG_Item arg) {
  if (CFG_isItemLabel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool CFG_isItemLabel(CFG_Item arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternItemLabel, NULL));
#endif
  return ATtrue;
}

ATbool CFG_hasItemName(CFG_Item arg) {
  if (CFG_isItemLabel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

char* CFG_getItemName(CFG_Item arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

CFG_Item CFG_setItemName(CFG_Item arg, const char* name) {
  if (CFG_isItemLabel(arg)) {
    return (CFG_Item)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("Item has no Name: %t\n", arg);
  return (CFG_Item)NULL;
}

ATbool CFG_isValidTextCategoryName(CFG_TextCategoryName arg) {
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

inline ATbool CFG_isTextCategoryNameFocus(CFG_TextCategoryName arg) {
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

inline ATbool CFG_isTextCategoryNameSelection(CFG_TextCategoryName arg) {
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

inline ATbool CFG_isTextCategoryNameNormal(CFG_TextCategoryName arg) {
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

inline ATbool CFG_isTextCategoryNameExtern(CFG_TextCategoryName arg) {
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

ATbool CFG_hasTextCategoryNameName(CFG_TextCategoryName arg) {
  if (CFG_isTextCategoryNameExtern(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

char* CFG_getTextCategoryNameName(CFG_TextCategoryName arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

CFG_TextCategoryName CFG_setTextCategoryNameName(CFG_TextCategoryName arg, const char* name) {
  if (CFG_isTextCategoryNameExtern(arg)) {
    return (CFG_TextCategoryName)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("TextCategoryName has no Name: %t\n", arg);
  return (CFG_TextCategoryName)NULL;
}

ATbool CFG_isValidTextAttribute(CFG_TextAttribute arg) {
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

inline ATbool CFG_isTextAttributeForegroundColor(CFG_TextAttribute arg) {
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

inline ATbool CFG_isTextAttributeBackgroundColor(CFG_TextAttribute arg) {
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

inline ATbool CFG_isTextAttributeStyle(CFG_TextAttribute arg) {
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

inline ATbool CFG_isTextAttributeFont(CFG_TextAttribute arg) {
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

inline ATbool CFG_isTextAttributeSize(CFG_TextAttribute arg) {
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

ATbool CFG_hasTextAttributeColor(CFG_TextAttribute arg) {
  if (CFG_isTextAttributeForegroundColor(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextAttributeBackgroundColor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasTextAttributeStyle(CFG_TextAttribute arg) {
  if (CFG_isTextAttributeStyle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasTextAttributeName(CFG_TextAttribute arg) {
  if (CFG_isTextAttributeFont(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasTextAttributePoint(CFG_TextAttribute arg) {
  if (CFG_isTextAttributeSize(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

CFG_Color CFG_getTextAttributeColor(CFG_TextAttribute arg) {
  if (CFG_isTextAttributeForegroundColor(arg)) {
    return (CFG_Color)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (CFG_Color)ATgetArgument((ATermAppl)arg, 0);
}

CFG_TextStyle CFG_getTextAttributeStyle(CFG_TextAttribute arg) {
  
    return (CFG_TextStyle)ATgetArgument((ATermAppl)arg, 0);
}

char* CFG_getTextAttributeName(CFG_TextAttribute arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

int CFG_getTextAttributePoint(CFG_TextAttribute arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

CFG_TextAttribute CFG_setTextAttributeColor(CFG_TextAttribute arg, CFG_Color color) {
  if (CFG_isTextAttributeForegroundColor(arg)) {
    return (CFG_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) color), 0);
  }
  else if (CFG_isTextAttributeBackgroundColor(arg)) {
    return (CFG_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) color), 0);
  }

  ATabort("TextAttribute has no Color: %t\n", arg);
  return (CFG_TextAttribute)NULL;
}

CFG_TextAttribute CFG_setTextAttributeStyle(CFG_TextAttribute arg, CFG_TextStyle style) {
  if (CFG_isTextAttributeStyle(arg)) {
    return (CFG_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) style), 0);
  }

  ATabort("TextAttribute has no Style: %t\n", arg);
  return (CFG_TextAttribute)NULL;
}

CFG_TextAttribute CFG_setTextAttributeName(CFG_TextAttribute arg, const char* name) {
  if (CFG_isTextAttributeFont(arg)) {
    return (CFG_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("TextAttribute has no Name: %t\n", arg);
  return (CFG_TextAttribute)NULL;
}

CFG_TextAttribute CFG_setTextAttributePoint(CFG_TextAttribute arg, int point) {
  if (CFG_isTextAttributeSize(arg)) {
    return (CFG_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(point)), 0);
  }

  ATabort("TextAttribute has no Point: %t\n", arg);
  return (CFG_TextAttribute)NULL;
}

ATbool CFG_isValidShortCut(CFG_ShortCut arg) {
  if (CFG_isShortCutShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool CFG_isShortCutShortcut(CFG_ShortCut arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternShortCutShortcut, NULL, NULL));
#endif
  return ATtrue;
}

ATbool CFG_hasShortCutModifier(CFG_ShortCut arg) {
  if (CFG_isShortCutShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasShortCutKey(CFG_ShortCut arg) {
  if (CFG_isShortCutShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

CFG_KeyModifier CFG_getShortCutModifier(CFG_ShortCut arg) {
  
    return (CFG_KeyModifier)ATgetArgument((ATermAppl)arg, 0);
}

CFG_VirtualKey CFG_getShortCutKey(CFG_ShortCut arg) {
  
    return (CFG_VirtualKey)ATgetArgument((ATermAppl)arg, 1);
}

CFG_ShortCut CFG_setShortCutModifier(CFG_ShortCut arg, CFG_KeyModifier modifier) {
  if (CFG_isShortCutShortcut(arg)) {
    return (CFG_ShortCut)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) modifier), 0);
  }

  ATabort("ShortCut has no Modifier: %t\n", arg);
  return (CFG_ShortCut)NULL;
}

CFG_ShortCut CFG_setShortCutKey(CFG_ShortCut arg, CFG_VirtualKey key) {
  if (CFG_isShortCutShortcut(arg)) {
    return (CFG_ShortCut)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) key), 1);
  }

  ATabort("ShortCut has no Key: %t\n", arg);
  return (CFG_ShortCut)NULL;
}

ATbool CFG_isValidTextStyle(CFG_TextStyle arg) {
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

inline ATbool CFG_isTextStyleBold(CFG_TextStyle arg) {
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

inline ATbool CFG_isTextStyleItalics(CFG_TextStyle arg) {
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

inline ATbool CFG_isTextStyleUnderlined(CFG_TextStyle arg) {
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

ATbool CFG_isValidPropertyList(CFG_PropertyList arg) {
  if (CFG_isPropertyListEmpty(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyListSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool CFG_isPropertyListEmpty(CFG_PropertyList arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternPropertyListEmpty));
#endif
  return ATtrue;
}

inline ATbool CFG_isPropertyListSingle(CFG_PropertyList arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CFG_patternPropertyListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isPropertyListMany(CFG_PropertyList arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CFG_patternPropertyListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool CFG_hasPropertyListHead(CFG_PropertyList arg) {
  if (CFG_isPropertyListSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasPropertyListTail(CFG_PropertyList arg) {
  if (CFG_isPropertyListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

CFG_Property CFG_getPropertyListHead(CFG_PropertyList arg) {
  if (CFG_isPropertyListSingle(arg)) {
    return (CFG_Property)ATgetFirst((ATermList)arg);
  }
  else 
    return (CFG_Property)ATgetFirst((ATermList)arg);
}

CFG_PropertyList CFG_getPropertyListTail(CFG_PropertyList arg) {
  
    return (CFG_PropertyList)ATgetNext((ATermList)arg);
}

CFG_PropertyList CFG_setPropertyListHead(CFG_PropertyList arg, CFG_Property head) {
  if (CFG_isPropertyListSingle(arg)) {
    return (CFG_PropertyList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CFG_isPropertyListMany(arg)) {
    return (CFG_PropertyList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("PropertyList has no Head: %t\n", arg);
  return (CFG_PropertyList)NULL;
}

CFG_PropertyList CFG_setPropertyListTail(CFG_PropertyList arg, CFG_PropertyList tail) {
  if (CFG_isPropertyListMany(arg)) {
    return (CFG_PropertyList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("PropertyList has no Tail: %t\n", arg);
  return (CFG_PropertyList)NULL;
}

ATbool CFG_isValidActionDescriptionList(CFG_ActionDescriptionList arg) {
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

inline ATbool CFG_isActionDescriptionListEmpty(CFG_ActionDescriptionList arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternActionDescriptionListEmpty));
#endif
  return ATtrue;
}

inline ATbool CFG_isActionDescriptionListSingle(CFG_ActionDescriptionList arg) {
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

inline ATbool CFG_isActionDescriptionListMany(CFG_ActionDescriptionList arg) {
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

ATbool CFG_hasActionDescriptionListHead(CFG_ActionDescriptionList arg) {
  if (CFG_isActionDescriptionListSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasActionDescriptionListTail(CFG_ActionDescriptionList arg) {
  if (CFG_isActionDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

CFG_ActionDescription CFG_getActionDescriptionListHead(CFG_ActionDescriptionList arg) {
  if (CFG_isActionDescriptionListSingle(arg)) {
    return (CFG_ActionDescription)ATgetFirst((ATermList)arg);
  }
  else 
    return (CFG_ActionDescription)ATgetFirst((ATermList)arg);
}

CFG_ActionDescriptionList CFG_getActionDescriptionListTail(CFG_ActionDescriptionList arg) {
  
    return (CFG_ActionDescriptionList)ATgetNext((ATermList)arg);
}

CFG_ActionDescriptionList CFG_setActionDescriptionListHead(CFG_ActionDescriptionList arg, CFG_ActionDescription head) {
  if (CFG_isActionDescriptionListSingle(arg)) {
    return (CFG_ActionDescriptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CFG_isActionDescriptionListMany(arg)) {
    return (CFG_ActionDescriptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ActionDescriptionList has no Head: %t\n", arg);
  return (CFG_ActionDescriptionList)NULL;
}

CFG_ActionDescriptionList CFG_setActionDescriptionListTail(CFG_ActionDescriptionList arg, CFG_ActionDescriptionList tail) {
  if (CFG_isActionDescriptionListMany(arg)) {
    return (CFG_ActionDescriptionList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("ActionDescriptionList has no Tail: %t\n", arg);
  return (CFG_ActionDescriptionList)NULL;
}

ATbool CFG_isValidTextAttributeMap(CFG_TextAttributeMap arg) {
  if (CFG_isTextAttributeMapEmpty(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextAttributeMapSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextAttributeMapMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool CFG_isTextAttributeMapEmpty(CFG_TextAttributeMap arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternTextAttributeMapEmpty));
#endif
  return ATtrue;
}

inline ATbool CFG_isTextAttributeMapSingle(CFG_TextAttributeMap arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextAttributeMapSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isTextAttributeMapMany(CFG_TextAttributeMap arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CFG_patternTextAttributeMapMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool CFG_hasTextAttributeMapHead(CFG_TextAttributeMap arg) {
  if (CFG_isTextAttributeMapSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextAttributeMapMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasTextAttributeMapTail(CFG_TextAttributeMap arg) {
  if (CFG_isTextAttributeMapMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

CFG_TextAttribute CFG_getTextAttributeMapHead(CFG_TextAttributeMap arg) {
  if (CFG_isTextAttributeMapSingle(arg)) {
    return (CFG_TextAttribute)ATgetFirst((ATermList)arg);
  }
  else 
    return (CFG_TextAttribute)ATgetFirst((ATermList)arg);
}

CFG_TextAttributeMap CFG_getTextAttributeMapTail(CFG_TextAttributeMap arg) {
  
    return (CFG_TextAttributeMap)ATgetNext((ATermList)arg);
}

CFG_TextAttributeMap CFG_setTextAttributeMapHead(CFG_TextAttributeMap arg, CFG_TextAttribute head) {
  if (CFG_isTextAttributeMapSingle(arg)) {
    return (CFG_TextAttributeMap)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CFG_isTextAttributeMapMany(arg)) {
    return (CFG_TextAttributeMap)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("TextAttributeMap has no Head: %t\n", arg);
  return (CFG_TextAttributeMap)NULL;
}

CFG_TextAttributeMap CFG_setTextAttributeMapTail(CFG_TextAttributeMap arg, CFG_TextAttributeMap tail) {
  if (CFG_isTextAttributeMapMany(arg)) {
    return (CFG_TextAttributeMap)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("TextAttributeMap has no Tail: %t\n", arg);
  return (CFG_TextAttributeMap)NULL;
}

ATbool CFG_isValidItemList(CFG_ItemList arg) {
  if (CFG_isItemListEmpty(arg)) {
    return ATtrue;
  }
  else if (CFG_isItemListSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isItemListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

inline ATbool CFG_isItemListEmpty(CFG_ItemList arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CFG_patternItemListEmpty));
#endif
  return ATtrue;
}

inline ATbool CFG_isItemListSingle(CFG_ItemList arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CFG_patternItemListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

inline ATbool CFG_isItemListMany(CFG_ItemList arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CFG_patternItemListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

ATbool CFG_hasItemListHead(CFG_ItemList arg) {
  if (CFG_isItemListSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isItemListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

ATbool CFG_hasItemListTail(CFG_ItemList arg) {
  if (CFG_isItemListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

CFG_Item CFG_getItemListHead(CFG_ItemList arg) {
  if (CFG_isItemListSingle(arg)) {
    return (CFG_Item)ATgetFirst((ATermList)arg);
  }
  else 
    return (CFG_Item)ATgetFirst((ATermList)arg);
}

CFG_ItemList CFG_getItemListTail(CFG_ItemList arg) {
  
    return (CFG_ItemList)ATgetNext((ATermList)arg);
}

CFG_ItemList CFG_setItemListHead(CFG_ItemList arg, CFG_Item head) {
  if (CFG_isItemListSingle(arg)) {
    return (CFG_ItemList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CFG_isItemListMany(arg)) {
    return (CFG_ItemList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ItemList has no Head: %t\n", arg);
  return (CFG_ItemList)NULL;
}

CFG_ItemList CFG_setItemListTail(CFG_ItemList arg, CFG_ItemList tail) {
  if (CFG_isItemListMany(arg)) {
    return (CFG_ItemList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("ItemList has no Tail: %t\n", arg);
  return (CFG_ItemList)NULL;
}

CFG_KeyModifier CFG_visitKeyModifier(CFG_KeyModifier arg) {
  if (CFG_isKeyModifierMUnderscoreALT(arg)) {
    return CFG_makeKeyModifierMUnderscoreALT();
  }
  if (CFG_isKeyModifierMUnderscoreCTRL(arg)) {
    return CFG_makeKeyModifierMUnderscoreCTRL();
  }
  if (CFG_isKeyModifierMUnderscoreSHIFT(arg)) {
    return CFG_makeKeyModifierMUnderscoreSHIFT();
  }
  ATabort("not a KeyModifier: %t\n", arg);
  return (CFG_KeyModifier)NULL;
}
CFG_VirtualKey CFG_visitVirtualKey(CFG_VirtualKey arg) {
  if (CFG_isVirtualKeyVKUnderscore0(arg)) {
    return CFG_makeVirtualKeyVKUnderscore0();
  }
  if (CFG_isVirtualKeyVKUnderscore1(arg)) {
    return CFG_makeVirtualKeyVKUnderscore1();
  }
  if (CFG_isVirtualKeyVKUnderscore2(arg)) {
    return CFG_makeVirtualKeyVKUnderscore2();
  }
  if (CFG_isVirtualKeyVKUnderscore3(arg)) {
    return CFG_makeVirtualKeyVKUnderscore3();
  }
  if (CFG_isVirtualKeyVKUnderscore4(arg)) {
    return CFG_makeVirtualKeyVKUnderscore4();
  }
  if (CFG_isVirtualKeyVKUnderscore5(arg)) {
    return CFG_makeVirtualKeyVKUnderscore5();
  }
  if (CFG_isVirtualKeyVKUnderscore6(arg)) {
    return CFG_makeVirtualKeyVKUnderscore6();
  }
  if (CFG_isVirtualKeyVKUnderscore7(arg)) {
    return CFG_makeVirtualKeyVKUnderscore7();
  }
  if (CFG_isVirtualKeyVKUnderscore8(arg)) {
    return CFG_makeVirtualKeyVKUnderscore8();
  }
  if (CFG_isVirtualKeyVKUnderscore9(arg)) {
    return CFG_makeVirtualKeyVKUnderscore9();
  }
  if (CFG_isVirtualKeyVKUnderscoreA(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreA();
  }
  if (CFG_isVirtualKeyVKUnderscoreB(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreB();
  }
  if (CFG_isVirtualKeyVKUnderscoreC(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreC();
  }
  if (CFG_isVirtualKeyVKUnderscoreD(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreD();
  }
  if (CFG_isVirtualKeyVKUnderscoreE(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreE();
  }
  if (CFG_isVirtualKeyVKUnderscoreF(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreF();
  }
  if (CFG_isVirtualKeyVKUnderscoreG(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreG();
  }
  if (CFG_isVirtualKeyVKUnderscoreH(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreH();
  }
  if (CFG_isVirtualKeyVKUnderscoreI(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreI();
  }
  if (CFG_isVirtualKeyVKUnderscoreJ(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreJ();
  }
  if (CFG_isVirtualKeyVKUnderscoreK(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreK();
  }
  if (CFG_isVirtualKeyVKUnderscoreL(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreL();
  }
  if (CFG_isVirtualKeyVKUnderscoreM(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreM();
  }
  if (CFG_isVirtualKeyVKUnderscoreN(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreN();
  }
  if (CFG_isVirtualKeyVKUnderscoreO(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreO();
  }
  if (CFG_isVirtualKeyVKUnderscoreP(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreP();
  }
  if (CFG_isVirtualKeyVKUnderscoreQ(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreQ();
  }
  if (CFG_isVirtualKeyVKUnderscoreR(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreR();
  }
  if (CFG_isVirtualKeyVKUnderscoreS(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreS();
  }
  if (CFG_isVirtualKeyVKUnderscoreT(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreT();
  }
  if (CFG_isVirtualKeyVKUnderscoreU(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreU();
  }
  if (CFG_isVirtualKeyVKUnderscoreV(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreV();
  }
  if (CFG_isVirtualKeyVKUnderscoreW(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreW();
  }
  if (CFG_isVirtualKeyVKUnderscoreX(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreX();
  }
  if (CFG_isVirtualKeyVKUnderscoreY(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreY();
  }
  if (CFG_isVirtualKeyVKUnderscoreZ(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreZ();
  }
  if (CFG_isVirtualKeyVKUnderscoreAMPERSAND(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreAMPERSAND();
  }
  if (CFG_isVirtualKeyVKUnderscoreASTERISK(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreASTERISK();
  }
  if (CFG_isVirtualKeyVKUnderscoreAT(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreAT();
  }
  if (CFG_isVirtualKeyVKUnderscoreBACKUnderscoreQUOTE(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreBACKUnderscoreQUOTE();
  }
  if (CFG_isVirtualKeyVKUnderscoreBACKUnderscoreSLASH(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreBACKUnderscoreSLASH();
  }
  if (CFG_isVirtualKeyVKUnderscoreBACKUnderscoreSPACE(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreBACKUnderscoreSPACE();
  }
  if (CFG_isVirtualKeyVKUnderscoreBEGIN(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreBEGIN();
  }
  if (CFG_isVirtualKeyVKUnderscoreBRACEUnderscoreLEFT(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreBRACEUnderscoreLEFT();
  }
  if (CFG_isVirtualKeyVKUnderscoreBRACEUnderscoreRIGHT(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreBRACEUnderscoreRIGHT();
  }
  if (CFG_isVirtualKeyVKUnderscoreCIRCUMFLEX(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreCIRCUMFLEX();
  }
  if (CFG_isVirtualKeyVKUnderscoreCLEAR(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreCLEAR();
  }
  if (CFG_isVirtualKeyVKUnderscoreCLOSEUnderscoreBRACKET(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreCLOSEUnderscoreBRACKET();
  }
  if (CFG_isVirtualKeyVKUnderscoreCOLON(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreCOLON();
  }
  if (CFG_isVirtualKeyVKUnderscoreCOMMA(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreCOMMA();
  }
  if (CFG_isVirtualKeyVKUnderscoreDECIMAL(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreDECIMAL();
  }
  if (CFG_isVirtualKeyVKUnderscoreDELETE(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreDELETE();
  }
  if (CFG_isVirtualKeyVKUnderscoreDIVIDE(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreDIVIDE();
  }
  if (CFG_isVirtualKeyVKUnderscoreDOLLAR(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreDOLLAR();
  }
  if (CFG_isVirtualKeyVKUnderscoreDOWN(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreDOWN();
  }
  if (CFG_isVirtualKeyVKUnderscoreEND(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreEND();
  }
  if (CFG_isVirtualKeyVKUnderscoreENTER(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreENTER();
  }
  if (CFG_isVirtualKeyVKUnderscoreEQUALS(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreEQUALS();
  }
  if (CFG_isVirtualKeyVKUnderscoreESCAPE(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreESCAPE();
  }
  if (CFG_isVirtualKeyVKUnderscoreEXCLAMATIONUnderscoreMARK(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreEXCLAMATIONUnderscoreMARK();
  }
  if (CFG_isVirtualKeyVKUnderscoreF1(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreF1();
  }
  if (CFG_isVirtualKeyVKUnderscoreF2(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreF2();
  }
  if (CFG_isVirtualKeyVKUnderscoreF3(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreF3();
  }
  if (CFG_isVirtualKeyVKUnderscoreF4(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreF4();
  }
  if (CFG_isVirtualKeyVKUnderscoreF5(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreF5();
  }
  if (CFG_isVirtualKeyVKUnderscoreF6(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreF6();
  }
  if (CFG_isVirtualKeyVKUnderscoreF7(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreF7();
  }
  if (CFG_isVirtualKeyVKUnderscoreF8(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreF8();
  }
  if (CFG_isVirtualKeyVKUnderscoreF9(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreF9();
  }
  if (CFG_isVirtualKeyVKUnderscoreF10(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreF10();
  }
  if (CFG_isVirtualKeyVKUnderscoreF11(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreF11();
  }
  if (CFG_isVirtualKeyVKUnderscoreF12(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreF12();
  }
  if (CFG_isVirtualKeyVKUnderscoreGREATER(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreGREATER();
  }
  if (CFG_isVirtualKeyVKUnderscoreHOME(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreHOME();
  }
  if (CFG_isVirtualKeyVKUnderscoreINSERT(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreINSERT();
  }
  if (CFG_isVirtualKeyVKUnderscoreLEFT(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreLEFT();
  }
  if (CFG_isVirtualKeyVKUnderscoreLEFTUnderscorePARENTHESIS(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreLEFTUnderscorePARENTHESIS();
  }
  if (CFG_isVirtualKeyVKUnderscoreMINUS(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreMINUS();
  }
  if (CFG_isVirtualKeyVKUnderscoreMULTIPLY(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreMULTIPLY();
  }
  if (CFG_isVirtualKeyVKUnderscoreNUMBERUnderscoreSIGN(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreNUMBERUnderscoreSIGN();
  }
  if (CFG_isVirtualKeyVKUnderscoreOPENUnderscoreBRACKET(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreOPENUnderscoreBRACKET();
  }
  if (CFG_isVirtualKeyVKUnderscorePAGEUnderscoreDOWN(arg)) {
    return CFG_makeVirtualKeyVKUnderscorePAGEUnderscoreDOWN();
  }
  if (CFG_isVirtualKeyVKUnderscorePAGEUnderscoreUP(arg)) {
    return CFG_makeVirtualKeyVKUnderscorePAGEUnderscoreUP();
  }
  if (CFG_isVirtualKeyVKUnderscorePAUSE(arg)) {
    return CFG_makeVirtualKeyVKUnderscorePAUSE();
  }
  if (CFG_isVirtualKeyVKUnderscorePERIOD(arg)) {
    return CFG_makeVirtualKeyVKUnderscorePERIOD();
  }
  if (CFG_isVirtualKeyVKUnderscorePLUS(arg)) {
    return CFG_makeVirtualKeyVKUnderscorePLUS();
  }
  if (CFG_isVirtualKeyVKUnderscorePRINTSCREEN(arg)) {
    return CFG_makeVirtualKeyVKUnderscorePRINTSCREEN();
  }
  if (CFG_isVirtualKeyVKUnderscoreQUOTE(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreQUOTE();
  }
  if (CFG_isVirtualKeyVKUnderscoreQUOTEDBL(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreQUOTEDBL();
  }
  if (CFG_isVirtualKeyVKUnderscoreRIGHT(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreRIGHT();
  }
  if (CFG_isVirtualKeyVKUnderscoreRIGHTUnderscorePARENTHESIS(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreRIGHTUnderscorePARENTHESIS();
  }
  if (CFG_isVirtualKeyVKUnderscoreSEMICOLON(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreSEMICOLON();
  }
  if (CFG_isVirtualKeyVKUnderscoreSLASH(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreSLASH();
  }
  if (CFG_isVirtualKeyVKUnderscoreSPACE(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreSPACE();
  }
  if (CFG_isVirtualKeyVKUnderscoreSUBTRACT(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreSUBTRACT();
  }
  if (CFG_isVirtualKeyVKUnderscoreTAB(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreTAB();
  }
  if (CFG_isVirtualKeyVKUnderscoreUNDERSCORE(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreUNDERSCORE();
  }
  if (CFG_isVirtualKeyVKUnderscoreUP(arg)) {
    return CFG_makeVirtualKeyVKUnderscoreUP();
  }
  ATabort("not a VirtualKey: %t\n", arg);
  return (CFG_VirtualKey)NULL;
}
CFG_Color CFG_visitColor(CFG_Color arg, int (*acceptRed)(int), int (*acceptGreen)(int), int (*acceptBlue)(int)) {
  if (CFG_isColorRgb(arg)) {
    return CFG_makeColorRgb(
        acceptRed ? acceptRed(CFG_getColorRed(arg)) : CFG_getColorRed(arg),
        acceptGreen ? acceptGreen(CFG_getColorGreen(arg)) : CFG_getColorGreen(arg),
        acceptBlue ? acceptBlue(CFG_getColorBlue(arg)) : CFG_getColorBlue(arg));
  }
  ATabort("not a Color: %t\n", arg);
  return (CFG_Color)NULL;
}
CFG_Configuration CFG_visitConfiguration(CFG_Configuration arg, CFG_PropertyList (*acceptList)(CFG_PropertyList)) {
  if (CFG_isConfigurationConfiguration(arg)) {
    return CFG_makeConfigurationConfiguration(
        acceptList ? acceptList(CFG_getConfigurationList(arg)) : CFG_getConfigurationList(arg));
  }
  ATabort("not a Configuration: %t\n", arg);
  return (CFG_Configuration)NULL;
}
CFG_Property CFG_visitProperty(CFG_Property arg, char* (*acceptPath)(char*), CFG_ActionDescriptionList (*acceptList)(CFG_ActionDescriptionList), char* (*acceptAction)(char*), char* (*acceptLanguage)(char*), char* (*acceptExtension)(char*), char* (*acceptLabel)(char*), CFG_TextCategoryName (*acceptCategory)(CFG_TextCategoryName), CFG_TextAttributeMap (*acceptMap)(CFG_TextAttributeMap)) {
  if (CFG_isPropertyImport(arg)) {
    return CFG_makePropertyImport(
        acceptPath ? acceptPath(CFG_getPropertyPath(arg)) : CFG_getPropertyPath(arg));
  }
  if (CFG_isPropertyAction(arg)) {
    return CFG_makePropertyAction(
        acceptList ? acceptList(CFG_getPropertyList(arg)) : CFG_getPropertyList(arg),
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
        acceptMap ? acceptMap(CFG_getPropertyMap(arg)) : CFG_getPropertyMap(arg));
  }
  ATabort("not a Property: %t\n", arg);
  return (CFG_Property)NULL;
}
CFG_ActionDescription CFG_visitActionDescription(CFG_ActionDescription arg, ATerm (*acceptContext)(ATerm), CFG_Event (*acceptEvent)(CFG_Event)) {
  if (CFG_isActionDescriptionDescription(arg)) {
    return CFG_makeActionDescriptionDescription(
        acceptContext ? acceptContext(CFG_getActionDescriptionContext(arg)) : CFG_getActionDescriptionContext(arg),
        acceptEvent ? acceptEvent(CFG_getActionDescriptionEvent(arg)) : CFG_getActionDescriptionEvent(arg));
  }
  ATabort("not a ActionDescription: %t\n", arg);
  return (CFG_ActionDescription)NULL;
}
CFG_Event CFG_visitEvent(CFG_Event arg, char* (*acceptTitle)(char*), char* (*acceptPath)(char*), CFG_ItemList (*acceptList)(CFG_ItemList), CFG_ShortCut (*acceptShortcut)(CFG_ShortCut)) {
  if (CFG_isEventClick(arg)) {
    return CFG_makeEventClick();
  }
  if (CFG_isEventIcon(arg)) {
    return CFG_makeEventIcon(
        acceptTitle ? acceptTitle(CFG_getEventTitle(arg)) : CFG_getEventTitle(arg),
        acceptPath ? acceptPath(CFG_getEventPath(arg)) : CFG_getEventPath(arg));
  }
  if (CFG_isEventMenu(arg)) {
    return CFG_makeEventMenu(
        acceptList ? acceptList(CFG_getEventList(arg)) : CFG_getEventList(arg));
  }
  if (CFG_isEventMenuShortcut(arg)) {
    return CFG_makeEventMenuShortcut(
        acceptList ? acceptList(CFG_getEventList(arg)) : CFG_getEventList(arg),
        acceptShortcut ? acceptShortcut(CFG_getEventShortcut(arg)) : CFG_getEventShortcut(arg));
  }
  ATabort("not a Event: %t\n", arg);
  return (CFG_Event)NULL;
}
CFG_Item CFG_visitItem(CFG_Item arg, char* (*acceptName)(char*)) {
  if (CFG_isItemLabel(arg)) {
    return CFG_makeItemLabel(
        acceptName ? acceptName(CFG_getItemName(arg)) : CFG_getItemName(arg));
  }
  ATabort("not a Item: %t\n", arg);
  return (CFG_Item)NULL;
}
CFG_TextCategoryName CFG_visitTextCategoryName(CFG_TextCategoryName arg, char* (*acceptName)(char*)) {
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
CFG_TextAttribute CFG_visitTextAttribute(CFG_TextAttribute arg, CFG_Color (*acceptColor)(CFG_Color), CFG_TextStyle (*acceptStyle)(CFG_TextStyle), char* (*acceptName)(char*), int (*acceptPoint)(int)) {
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
        acceptPoint ? acceptPoint(CFG_getTextAttributePoint(arg)) : CFG_getTextAttributePoint(arg));
  }
  ATabort("not a TextAttribute: %t\n", arg);
  return (CFG_TextAttribute)NULL;
}
CFG_ShortCut CFG_visitShortCut(CFG_ShortCut arg, CFG_KeyModifier (*acceptModifier)(CFG_KeyModifier), CFG_VirtualKey (*acceptKey)(CFG_VirtualKey)) {
  if (CFG_isShortCutShortcut(arg)) {
    return CFG_makeShortCutShortcut(
        acceptModifier ? acceptModifier(CFG_getShortCutModifier(arg)) : CFG_getShortCutModifier(arg),
        acceptKey ? acceptKey(CFG_getShortCutKey(arg)) : CFG_getShortCutKey(arg));
  }
  ATabort("not a ShortCut: %t\n", arg);
  return (CFG_ShortCut)NULL;
}
CFG_TextStyle CFG_visitTextStyle(CFG_TextStyle arg) {
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
CFG_PropertyList CFG_visitPropertyList(CFG_PropertyList arg, CFG_Property (*acceptHead)(CFG_Property)) {
  if (CFG_isPropertyListEmpty(arg)) {
    return CFG_makePropertyListEmpty();
  }
  if (CFG_isPropertyListSingle(arg)) {
    return CFG_makePropertyListSingle(
        acceptHead ? acceptHead(CFG_getPropertyListHead(arg)) : CFG_getPropertyListHead(arg));
  }
  if (CFG_isPropertyListMany(arg)) {
    return CFG_makePropertyListMany(
        acceptHead ? acceptHead(CFG_getPropertyListHead(arg)) : CFG_getPropertyListHead(arg),
        CFG_visitPropertyList(CFG_getPropertyListTail(arg), acceptHead));
  }
  ATabort("not a PropertyList: %t\n", arg);
  return (CFG_PropertyList)NULL;
}
CFG_ActionDescriptionList CFG_visitActionDescriptionList(CFG_ActionDescriptionList arg, CFG_ActionDescription (*acceptHead)(CFG_ActionDescription)) {
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
CFG_TextAttributeMap CFG_visitTextAttributeMap(CFG_TextAttributeMap arg, CFG_TextAttribute (*acceptHead)(CFG_TextAttribute)) {
  if (CFG_isTextAttributeMapEmpty(arg)) {
    return CFG_makeTextAttributeMapEmpty();
  }
  if (CFG_isTextAttributeMapSingle(arg)) {
    return CFG_makeTextAttributeMapSingle(
        acceptHead ? acceptHead(CFG_getTextAttributeMapHead(arg)) : CFG_getTextAttributeMapHead(arg));
  }
  if (CFG_isTextAttributeMapMany(arg)) {
    return CFG_makeTextAttributeMapMany(
        acceptHead ? acceptHead(CFG_getTextAttributeMapHead(arg)) : CFG_getTextAttributeMapHead(arg),
        CFG_visitTextAttributeMap(CFG_getTextAttributeMapTail(arg), acceptHead));
  }
  ATabort("not a TextAttributeMap: %t\n", arg);
  return (CFG_TextAttributeMap)NULL;
}
CFG_ItemList CFG_visitItemList(CFG_ItemList arg, CFG_Item (*acceptHead)(CFG_Item)) {
  if (CFG_isItemListEmpty(arg)) {
    return CFG_makeItemListEmpty();
  }
  if (CFG_isItemListSingle(arg)) {
    return CFG_makeItemListSingle(
        acceptHead ? acceptHead(CFG_getItemListHead(arg)) : CFG_getItemListHead(arg));
  }
  if (CFG_isItemListMany(arg)) {
    return CFG_makeItemListMany(
        acceptHead ? acceptHead(CFG_getItemListHead(arg)) : CFG_getItemListHead(arg),
        CFG_visitItemList(CFG_getItemListTail(arg), acceptHead));
  }
  ATabort("not a ItemList: %t\n", arg);
  return (CFG_ItemList)NULL;
}

