#ifndef _CONFIG_H
#define _CONFIG_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Config_dict.h"

typedef struct _CFG_VirtualButton *CFG_VirtualButton;
typedef struct _CFG_KeyModifier *CFG_KeyModifier;
typedef struct _CFG_VirtualKey *CFG_VirtualKey;
typedef struct _CFG_Color *CFG_Color;
typedef struct _CFG_Configuration *CFG_Configuration;
typedef struct _CFG_Property *CFG_Property;
typedef struct _CFG_ActionDescription *CFG_ActionDescription;
typedef struct _CFG_Event *CFG_Event;
typedef struct _CFG_Item *CFG_Item;
typedef struct _CFG_TextCategoryName *CFG_TextCategoryName;
typedef struct _CFG_TextAttribute *CFG_TextAttribute;
typedef struct _CFG_ShortCut *CFG_ShortCut;
typedef struct _CFG_TextStyle *CFG_TextStyle;
typedef struct _CFG_PropertyList *CFG_PropertyList;
typedef struct _CFG_ActionDescriptionList *CFG_ActionDescriptionList;
typedef struct _CFG_TextAttributeMap *CFG_TextAttributeMap;
typedef struct _CFG_KeyModifierList *CFG_KeyModifierList;
typedef struct _CFG_ItemLabels *CFG_ItemLabels;

#ifdef FAST_API
#define CFG_initConfigApi() (init_Config_dict())
#else
void _CFG_initConfigApi (void);
#define CFG_initConfigApi() (_CFG_initConfigApi())
#endif

#ifdef FAST_API
#define CFG_protectVirtualButton(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectVirtualButton (CFG_VirtualButton * arg);
#define CFG_protectVirtualButton(arg) (_CFG_protectVirtualButton(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectVirtualButton(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectVirtualButton (CFG_VirtualButton * arg);
#define CFG_unprotectVirtualButton(arg) (_CFG_unprotectVirtualButton(arg))
#endif
#ifdef FAST_API
#define CFG_protectKeyModifier(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectKeyModifier (CFG_KeyModifier * arg);
#define CFG_protectKeyModifier(arg) (_CFG_protectKeyModifier(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectKeyModifier(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectKeyModifier (CFG_KeyModifier * arg);
#define CFG_unprotectKeyModifier(arg) (_CFG_unprotectKeyModifier(arg))
#endif
#ifdef FAST_API
#define CFG_protectVirtualKey(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectVirtualKey (CFG_VirtualKey * arg);
#define CFG_protectVirtualKey(arg) (_CFG_protectVirtualKey(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectVirtualKey(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectVirtualKey (CFG_VirtualKey * arg);
#define CFG_unprotectVirtualKey(arg) (_CFG_unprotectVirtualKey(arg))
#endif
#ifdef FAST_API
#define CFG_protectColor(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectColor (CFG_Color * arg);
#define CFG_protectColor(arg) (_CFG_protectColor(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectColor(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectColor (CFG_Color * arg);
#define CFG_unprotectColor(arg) (_CFG_unprotectColor(arg))
#endif
#ifdef FAST_API
#define CFG_protectConfiguration(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectConfiguration (CFG_Configuration * arg);
#define CFG_protectConfiguration(arg) (_CFG_protectConfiguration(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectConfiguration(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectConfiguration (CFG_Configuration * arg);
#define CFG_unprotectConfiguration(arg) (_CFG_unprotectConfiguration(arg))
#endif
#ifdef FAST_API
#define CFG_protectProperty(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectProperty (CFG_Property * arg);
#define CFG_protectProperty(arg) (_CFG_protectProperty(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectProperty(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectProperty (CFG_Property * arg);
#define CFG_unprotectProperty(arg) (_CFG_unprotectProperty(arg))
#endif
#ifdef FAST_API
#define CFG_protectActionDescription(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectActionDescription (CFG_ActionDescription * arg);
#define CFG_protectActionDescription(arg) (_CFG_protectActionDescription(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectActionDescription(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectActionDescription (CFG_ActionDescription * arg);
#define CFG_unprotectActionDescription(arg) (_CFG_unprotectActionDescription(arg))
#endif
#ifdef FAST_API
#define CFG_protectEvent(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectEvent (CFG_Event * arg);
#define CFG_protectEvent(arg) (_CFG_protectEvent(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectEvent(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectEvent (CFG_Event * arg);
#define CFG_unprotectEvent(arg) (_CFG_unprotectEvent(arg))
#endif
#ifdef FAST_API
#define CFG_protectItem(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectItem (CFG_Item * arg);
#define CFG_protectItem(arg) (_CFG_protectItem(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectItem(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectItem (CFG_Item * arg);
#define CFG_unprotectItem(arg) (_CFG_unprotectItem(arg))
#endif
#ifdef FAST_API
#define CFG_protectTextCategoryName(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectTextCategoryName (CFG_TextCategoryName * arg);
#define CFG_protectTextCategoryName(arg) (_CFG_protectTextCategoryName(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectTextCategoryName(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectTextCategoryName (CFG_TextCategoryName * arg);
#define CFG_unprotectTextCategoryName(arg) (_CFG_unprotectTextCategoryName(arg))
#endif
#ifdef FAST_API
#define CFG_protectTextAttribute(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectTextAttribute (CFG_TextAttribute * arg);
#define CFG_protectTextAttribute(arg) (_CFG_protectTextAttribute(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectTextAttribute(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectTextAttribute (CFG_TextAttribute * arg);
#define CFG_unprotectTextAttribute(arg) (_CFG_unprotectTextAttribute(arg))
#endif
#ifdef FAST_API
#define CFG_protectShortCut(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectShortCut (CFG_ShortCut * arg);
#define CFG_protectShortCut(arg) (_CFG_protectShortCut(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectShortCut(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectShortCut (CFG_ShortCut * arg);
#define CFG_unprotectShortCut(arg) (_CFG_unprotectShortCut(arg))
#endif
#ifdef FAST_API
#define CFG_protectTextStyle(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectTextStyle (CFG_TextStyle * arg);
#define CFG_protectTextStyle(arg) (_CFG_protectTextStyle(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectTextStyle(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectTextStyle (CFG_TextStyle * arg);
#define CFG_unprotectTextStyle(arg) (_CFG_unprotectTextStyle(arg))
#endif
#ifdef FAST_API
#define CFG_protectPropertyList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectPropertyList (CFG_PropertyList * arg);
#define CFG_protectPropertyList(arg) (_CFG_protectPropertyList(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectPropertyList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectPropertyList (CFG_PropertyList * arg);
#define CFG_unprotectPropertyList(arg) (_CFG_unprotectPropertyList(arg))
#endif
#ifdef FAST_API
#define CFG_protectActionDescriptionList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectActionDescriptionList (CFG_ActionDescriptionList * arg);
#define CFG_protectActionDescriptionList(arg) (_CFG_protectActionDescriptionList(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectActionDescriptionList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectActionDescriptionList (CFG_ActionDescriptionList * arg);
#define CFG_unprotectActionDescriptionList(arg) (_CFG_unprotectActionDescriptionList(arg))
#endif
#ifdef FAST_API
#define CFG_protectTextAttributeMap(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectTextAttributeMap (CFG_TextAttributeMap * arg);
#define CFG_protectTextAttributeMap(arg) (_CFG_protectTextAttributeMap(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectTextAttributeMap(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectTextAttributeMap (CFG_TextAttributeMap * arg);
#define CFG_unprotectTextAttributeMap(arg) (_CFG_unprotectTextAttributeMap(arg))
#endif
#ifdef FAST_API
#define CFG_protectKeyModifierList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectKeyModifierList (CFG_KeyModifierList * arg);
#define CFG_protectKeyModifierList(arg) (_CFG_protectKeyModifierList(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectKeyModifierList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectKeyModifierList (CFG_KeyModifierList * arg);
#define CFG_unprotectKeyModifierList(arg) (_CFG_unprotectKeyModifierList(arg))
#endif
#ifdef FAST_API
#define CFG_protectItemLabels(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CFG_protectItemLabels (CFG_ItemLabels * arg);
#define CFG_protectItemLabels(arg) (_CFG_protectItemLabels(arg))
#endif
#ifdef FAST_API
#define CFG_unprotectItemLabels(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CFG_unprotectItemLabels (CFG_ItemLabels * arg);
#define CFG_unprotectItemLabels(arg) (_CFG_unprotectItemLabels(arg))
#endif
#ifdef FAST_API
#define CFG_VirtualButtonFromTerm(t) ((CFG_VirtualButton)(t))
#else
CFG_VirtualButton _CFG_VirtualButtonFromTerm (ATerm t);
#define CFG_VirtualButtonFromTerm(t) (_CFG_VirtualButtonFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_VirtualButtonToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_VirtualButtonToTerm (CFG_VirtualButton arg);
#define CFG_VirtualButtonToTerm(arg) (_CFG_VirtualButtonToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_KeyModifierFromTerm(t) ((CFG_KeyModifier)(t))
#else
CFG_KeyModifier _CFG_KeyModifierFromTerm (ATerm t);
#define CFG_KeyModifierFromTerm(t) (_CFG_KeyModifierFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_KeyModifierToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_KeyModifierToTerm (CFG_KeyModifier arg);
#define CFG_KeyModifierToTerm(arg) (_CFG_KeyModifierToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_VirtualKeyFromTerm(t) ((CFG_VirtualKey)(t))
#else
CFG_VirtualKey _CFG_VirtualKeyFromTerm (ATerm t);
#define CFG_VirtualKeyFromTerm(t) (_CFG_VirtualKeyFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_VirtualKeyToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_VirtualKeyToTerm (CFG_VirtualKey arg);
#define CFG_VirtualKeyToTerm(arg) (_CFG_VirtualKeyToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_ColorFromTerm(t) ((CFG_Color)(t))
#else
CFG_Color _CFG_ColorFromTerm (ATerm t);
#define CFG_ColorFromTerm(t) (_CFG_ColorFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_ColorToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_ColorToTerm (CFG_Color arg);
#define CFG_ColorToTerm(arg) (_CFG_ColorToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_ConfigurationFromTerm(t) ((CFG_Configuration)(t))
#else
CFG_Configuration _CFG_ConfigurationFromTerm (ATerm t);
#define CFG_ConfigurationFromTerm(t) (_CFG_ConfigurationFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_ConfigurationToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_ConfigurationToTerm (CFG_Configuration arg);
#define CFG_ConfigurationToTerm(arg) (_CFG_ConfigurationToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_PropertyFromTerm(t) ((CFG_Property)(t))
#else
CFG_Property _CFG_PropertyFromTerm (ATerm t);
#define CFG_PropertyFromTerm(t) (_CFG_PropertyFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_PropertyToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_PropertyToTerm (CFG_Property arg);
#define CFG_PropertyToTerm(arg) (_CFG_PropertyToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_ActionDescriptionFromTerm(t) ((CFG_ActionDescription)(t))
#else
CFG_ActionDescription _CFG_ActionDescriptionFromTerm (ATerm t);
#define CFG_ActionDescriptionFromTerm(t) (_CFG_ActionDescriptionFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_ActionDescriptionToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_ActionDescriptionToTerm (CFG_ActionDescription arg);
#define CFG_ActionDescriptionToTerm(arg) (_CFG_ActionDescriptionToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_EventFromTerm(t) ((CFG_Event)(t))
#else
CFG_Event _CFG_EventFromTerm (ATerm t);
#define CFG_EventFromTerm(t) (_CFG_EventFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_EventToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_EventToTerm (CFG_Event arg);
#define CFG_EventToTerm(arg) (_CFG_EventToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_ItemFromTerm(t) ((CFG_Item)(t))
#else
CFG_Item _CFG_ItemFromTerm (ATerm t);
#define CFG_ItemFromTerm(t) (_CFG_ItemFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_ItemToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_ItemToTerm (CFG_Item arg);
#define CFG_ItemToTerm(arg) (_CFG_ItemToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_TextCategoryNameFromTerm(t) ((CFG_TextCategoryName)(t))
#else
CFG_TextCategoryName _CFG_TextCategoryNameFromTerm (ATerm t);
#define CFG_TextCategoryNameFromTerm(t) (_CFG_TextCategoryNameFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_TextCategoryNameToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_TextCategoryNameToTerm (CFG_TextCategoryName arg);
#define CFG_TextCategoryNameToTerm(arg) (_CFG_TextCategoryNameToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_TextAttributeFromTerm(t) ((CFG_TextAttribute)(t))
#else
CFG_TextAttribute _CFG_TextAttributeFromTerm (ATerm t);
#define CFG_TextAttributeFromTerm(t) (_CFG_TextAttributeFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_TextAttributeToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_TextAttributeToTerm (CFG_TextAttribute arg);
#define CFG_TextAttributeToTerm(arg) (_CFG_TextAttributeToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_ShortCutFromTerm(t) ((CFG_ShortCut)(t))
#else
CFG_ShortCut _CFG_ShortCutFromTerm (ATerm t);
#define CFG_ShortCutFromTerm(t) (_CFG_ShortCutFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_ShortCutToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_ShortCutToTerm (CFG_ShortCut arg);
#define CFG_ShortCutToTerm(arg) (_CFG_ShortCutToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_TextStyleFromTerm(t) ((CFG_TextStyle)(t))
#else
CFG_TextStyle _CFG_TextStyleFromTerm (ATerm t);
#define CFG_TextStyleFromTerm(t) (_CFG_TextStyleFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_TextStyleToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_TextStyleToTerm (CFG_TextStyle arg);
#define CFG_TextStyleToTerm(arg) (_CFG_TextStyleToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_PropertyListFromTerm(t) ((CFG_PropertyList)(t))
#else
CFG_PropertyList _CFG_PropertyListFromTerm (ATerm t);
#define CFG_PropertyListFromTerm(t) (_CFG_PropertyListFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_PropertyListToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_PropertyListToTerm (CFG_PropertyList arg);
#define CFG_PropertyListToTerm(arg) (_CFG_PropertyListToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_ActionDescriptionListFromTerm(t) ((CFG_ActionDescriptionList)(t))
#else
CFG_ActionDescriptionList _CFG_ActionDescriptionListFromTerm (ATerm t);
#define CFG_ActionDescriptionListFromTerm(t) (_CFG_ActionDescriptionListFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_ActionDescriptionListToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_ActionDescriptionListToTerm (CFG_ActionDescriptionList arg);
#define CFG_ActionDescriptionListToTerm(arg) (_CFG_ActionDescriptionListToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_TextAttributeMapFromTerm(t) ((CFG_TextAttributeMap)(t))
#else
CFG_TextAttributeMap _CFG_TextAttributeMapFromTerm (ATerm t);
#define CFG_TextAttributeMapFromTerm(t) (_CFG_TextAttributeMapFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_TextAttributeMapToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_TextAttributeMapToTerm (CFG_TextAttributeMap arg);
#define CFG_TextAttributeMapToTerm(arg) (_CFG_TextAttributeMapToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_KeyModifierListFromTerm(t) ((CFG_KeyModifierList)(t))
#else
CFG_KeyModifierList _CFG_KeyModifierListFromTerm (ATerm t);
#define CFG_KeyModifierListFromTerm(t) (_CFG_KeyModifierListFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_KeyModifierListToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_KeyModifierListToTerm (CFG_KeyModifierList arg);
#define CFG_KeyModifierListToTerm(arg) (_CFG_KeyModifierListToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_ItemLabelsFromTerm(t) ((CFG_ItemLabels)(t))
#else
CFG_ItemLabels _CFG_ItemLabelsFromTerm (ATerm t);
#define CFG_ItemLabelsFromTerm(t) (_CFG_ItemLabelsFromTerm(t))
#endif
#ifdef FAST_API
#define CFG_ItemLabelsToTerm(arg) ((ATerm)(arg))
#else
ATerm _CFG_ItemLabelsToTerm (CFG_ItemLabels arg);
#define CFG_ItemLabelsToTerm(arg) (_CFG_ItemLabelsToTerm(arg))
#endif
#ifdef FAST_API
#define CFG_getPropertyListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _CFG_getPropertyListLength (CFG_PropertyList arg);
#define CFG_getPropertyListLength(arg) (_CFG_getPropertyListLength(arg))
#endif
#ifdef FAST_API
#define CFG_reversePropertyList(arg) ((CFG_PropertyList) ATreverse((ATermList) (arg)))
#else
CFG_PropertyList _CFG_reversePropertyList (CFG_PropertyList arg);
#define CFG_reversePropertyList(arg) (_CFG_reversePropertyList(arg))
#endif
#ifdef FAST_API
#define CFG_appendPropertyList(arg, elem) ((CFG_PropertyList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
CFG_PropertyList _CFG_appendPropertyList (CFG_PropertyList arg,
					  CFG_Property elem);
#define CFG_appendPropertyList(arg, elem) (_CFG_appendPropertyList(arg, elem))
#endif
#ifdef FAST_API
#define CFG_concatPropertyList(arg0, arg1) ((CFG_PropertyList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
CFG_PropertyList _CFG_concatPropertyList (CFG_PropertyList arg0,
					  CFG_PropertyList arg1);
#define CFG_concatPropertyList(arg0, arg1) (_CFG_concatPropertyList(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_slicePropertyList(arg, start, end) ((CFG_PropertyList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
CFG_PropertyList _CFG_slicePropertyList (CFG_PropertyList arg, int start,
					 int end);
#define CFG_slicePropertyList(arg, start, end) (_CFG_slicePropertyList(arg, start, end))
#endif
#ifdef FAST_API
#define CFG_getPropertyListPropertyAt(arg, index) ((CFG_Property) (ATelementAt((ATermList) arg,index)))
#else
CFG_Property _CFG_getPropertyListPropertyAt (CFG_PropertyList arg, int index);
#define CFG_getPropertyListPropertyAt(arg, index) (_CFG_getPropertyListPropertyAt(arg, index))
#endif
#ifdef FAST_API
#define CFG_replacePropertyListPropertyAt(arg, elem, index) ((CFG_PropertyList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
CFG_PropertyList _CFG_replacePropertyListPropertyAt (CFG_PropertyList arg,
						     CFG_Property elem,
						     int index);
#define CFG_replacePropertyListPropertyAt(arg, elem, index) (_CFG_replacePropertyListPropertyAt(arg, elem, index))
#endif
#ifdef FAST_API
#define CFG_makePropertyList2(elem1,  elem2) ((CFG_PropertyList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
CFG_PropertyList _CFG_makePropertyList2 (CFG_Property elem1,
					 CFG_Property elem2);
#define CFG_makePropertyList2(elem1,  elem2) (_CFG_makePropertyList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define CFG_makePropertyList3(elem1, elem2,  elem3) ((CFG_PropertyList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
CFG_PropertyList _CFG_makePropertyList3 (CFG_Property elem1,
					 CFG_Property elem2,
					 CFG_Property elem3);
#define CFG_makePropertyList3(elem1, elem2,  elem3) (_CFG_makePropertyList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define CFG_makePropertyList4(elem1, elem2, elem3,  elem4) ((CFG_PropertyList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
CFG_PropertyList _CFG_makePropertyList4 (CFG_Property elem1,
					 CFG_Property elem2,
					 CFG_Property elem3,
					 CFG_Property elem4);
#define CFG_makePropertyList4(elem1, elem2, elem3,  elem4) (_CFG_makePropertyList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define CFG_makePropertyList5(elem1, elem2, elem3, elem4,  elem5) ((CFG_PropertyList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
CFG_PropertyList _CFG_makePropertyList5 (CFG_Property elem1,
					 CFG_Property elem2,
					 CFG_Property elem3,
					 CFG_Property elem4,
					 CFG_Property elem5);
#define CFG_makePropertyList5(elem1, elem2, elem3, elem4,  elem5) (_CFG_makePropertyList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define CFG_makePropertyList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((CFG_PropertyList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
CFG_PropertyList _CFG_makePropertyList6 (CFG_Property elem1,
					 CFG_Property elem2,
					 CFG_Property elem3,
					 CFG_Property elem4,
					 CFG_Property elem5,
					 CFG_Property elem6);
#define CFG_makePropertyList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_CFG_makePropertyList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define CFG_getActionDescriptionListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _CFG_getActionDescriptionListLength (CFG_ActionDescriptionList arg);
#define CFG_getActionDescriptionListLength(arg) (_CFG_getActionDescriptionListLength(arg))
#endif
#ifdef FAST_API
#define CFG_reverseActionDescriptionList(arg) ((CFG_ActionDescriptionList) ATreverse((ATermList) (arg)))
#else
CFG_ActionDescriptionList
_CFG_reverseActionDescriptionList (CFG_ActionDescriptionList arg);
#define CFG_reverseActionDescriptionList(arg) (_CFG_reverseActionDescriptionList(arg))
#endif
#ifdef FAST_API
#define CFG_appendActionDescriptionList(arg, elem) ((CFG_ActionDescriptionList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
CFG_ActionDescriptionList
_CFG_appendActionDescriptionList (CFG_ActionDescriptionList arg,
				  CFG_ActionDescription elem);
#define CFG_appendActionDescriptionList(arg, elem) (_CFG_appendActionDescriptionList(arg, elem))
#endif
#ifdef FAST_API
#define CFG_concatActionDescriptionList(arg0, arg1) ((CFG_ActionDescriptionList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
CFG_ActionDescriptionList
_CFG_concatActionDescriptionList (CFG_ActionDescriptionList arg0,
				  CFG_ActionDescriptionList arg1);
#define CFG_concatActionDescriptionList(arg0, arg1) (_CFG_concatActionDescriptionList(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_sliceActionDescriptionList(arg, start, end) ((CFG_ActionDescriptionList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
CFG_ActionDescriptionList
_CFG_sliceActionDescriptionList (CFG_ActionDescriptionList arg, int start,
				 int end);
#define CFG_sliceActionDescriptionList(arg, start, end) (_CFG_sliceActionDescriptionList(arg, start, end))
#endif
#ifdef FAST_API
#define CFG_getActionDescriptionListActionDescriptionAt(arg, index) ((CFG_ActionDescription) (ATelementAt((ATermList) arg,index)))
#else
CFG_ActionDescription
_CFG_getActionDescriptionListActionDescriptionAt (CFG_ActionDescriptionList
						  arg, int index);
#define CFG_getActionDescriptionListActionDescriptionAt(arg, index) (_CFG_getActionDescriptionListActionDescriptionAt(arg, index))
#endif
#ifdef FAST_API
#define CFG_replaceActionDescriptionListActionDescriptionAt(arg, elem, index) ((CFG_ActionDescriptionList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
CFG_ActionDescriptionList
_CFG_replaceActionDescriptionListActionDescriptionAt
(CFG_ActionDescriptionList arg, CFG_ActionDescription elem, int index);
#define CFG_replaceActionDescriptionListActionDescriptionAt(arg, elem, index) (_CFG_replaceActionDescriptionListActionDescriptionAt(arg, elem, index))
#endif
#ifdef FAST_API
#define CFG_makeActionDescriptionList2(elem1,  elem2) ((CFG_ActionDescriptionList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
CFG_ActionDescriptionList
_CFG_makeActionDescriptionList2 (CFG_ActionDescription elem1,
				 CFG_ActionDescription elem2);
#define CFG_makeActionDescriptionList2(elem1,  elem2) (_CFG_makeActionDescriptionList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define CFG_makeActionDescriptionList3(elem1, elem2,  elem3) ((CFG_ActionDescriptionList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
CFG_ActionDescriptionList
_CFG_makeActionDescriptionList3 (CFG_ActionDescription elem1,
				 CFG_ActionDescription elem2,
				 CFG_ActionDescription elem3);
#define CFG_makeActionDescriptionList3(elem1, elem2,  elem3) (_CFG_makeActionDescriptionList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define CFG_makeActionDescriptionList4(elem1, elem2, elem3,  elem4) ((CFG_ActionDescriptionList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
CFG_ActionDescriptionList
_CFG_makeActionDescriptionList4 (CFG_ActionDescription elem1,
				 CFG_ActionDescription elem2,
				 CFG_ActionDescription elem3,
				 CFG_ActionDescription elem4);
#define CFG_makeActionDescriptionList4(elem1, elem2, elem3,  elem4) (_CFG_makeActionDescriptionList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define CFG_makeActionDescriptionList5(elem1, elem2, elem3, elem4,  elem5) ((CFG_ActionDescriptionList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
CFG_ActionDescriptionList
_CFG_makeActionDescriptionList5 (CFG_ActionDescription elem1,
				 CFG_ActionDescription elem2,
				 CFG_ActionDescription elem3,
				 CFG_ActionDescription elem4,
				 CFG_ActionDescription elem5);
#define CFG_makeActionDescriptionList5(elem1, elem2, elem3, elem4,  elem5) (_CFG_makeActionDescriptionList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define CFG_makeActionDescriptionList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((CFG_ActionDescriptionList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
CFG_ActionDescriptionList
_CFG_makeActionDescriptionList6 (CFG_ActionDescription elem1,
				 CFG_ActionDescription elem2,
				 CFG_ActionDescription elem3,
				 CFG_ActionDescription elem4,
				 CFG_ActionDescription elem5,
				 CFG_ActionDescription elem6);
#define CFG_makeActionDescriptionList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_CFG_makeActionDescriptionList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define CFG_getTextAttributeMapLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _CFG_getTextAttributeMapLength (CFG_TextAttributeMap arg);
#define CFG_getTextAttributeMapLength(arg) (_CFG_getTextAttributeMapLength(arg))
#endif
#ifdef FAST_API
#define CFG_reverseTextAttributeMap(arg) ((CFG_TextAttributeMap) ATreverse((ATermList) (arg)))
#else
CFG_TextAttributeMap _CFG_reverseTextAttributeMap (CFG_TextAttributeMap arg);
#define CFG_reverseTextAttributeMap(arg) (_CFG_reverseTextAttributeMap(arg))
#endif
#ifdef FAST_API
#define CFG_appendTextAttributeMap(arg, elem) ((CFG_TextAttributeMap) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
CFG_TextAttributeMap _CFG_appendTextAttributeMap (CFG_TextAttributeMap arg,
						  CFG_TextAttribute elem);
#define CFG_appendTextAttributeMap(arg, elem) (_CFG_appendTextAttributeMap(arg, elem))
#endif
#ifdef FAST_API
#define CFG_concatTextAttributeMap(arg0, arg1) ((CFG_TextAttributeMap) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
CFG_TextAttributeMap _CFG_concatTextAttributeMap (CFG_TextAttributeMap arg0,
						  CFG_TextAttributeMap arg1);
#define CFG_concatTextAttributeMap(arg0, arg1) (_CFG_concatTextAttributeMap(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_sliceTextAttributeMap(arg, start, end) ((CFG_TextAttributeMap) ATgetSlice((ATermList) (arg), (start), (end)))
#else
CFG_TextAttributeMap _CFG_sliceTextAttributeMap (CFG_TextAttributeMap arg,
						 int start, int end);
#define CFG_sliceTextAttributeMap(arg, start, end) (_CFG_sliceTextAttributeMap(arg, start, end))
#endif
#ifdef FAST_API
#define CFG_getTextAttributeMapTextAttributeAt(arg, index) ((CFG_TextAttribute) (ATelementAt((ATermList) arg,index)))
#else
CFG_TextAttribute
_CFG_getTextAttributeMapTextAttributeAt (CFG_TextAttributeMap arg, int index);
#define CFG_getTextAttributeMapTextAttributeAt(arg, index) (_CFG_getTextAttributeMapTextAttributeAt(arg, index))
#endif
#ifdef FAST_API
#define CFG_replaceTextAttributeMapTextAttributeAt(arg, elem, index) ((CFG_TextAttributeMap) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
CFG_TextAttributeMap
_CFG_replaceTextAttributeMapTextAttributeAt (CFG_TextAttributeMap arg,
					     CFG_TextAttribute elem,
					     int index);
#define CFG_replaceTextAttributeMapTextAttributeAt(arg, elem, index) (_CFG_replaceTextAttributeMapTextAttributeAt(arg, elem, index))
#endif
#ifdef FAST_API
#define CFG_makeTextAttributeMap2(elem1,  elem2) ((CFG_TextAttributeMap) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
CFG_TextAttributeMap _CFG_makeTextAttributeMap2 (CFG_TextAttribute elem1,
						 CFG_TextAttribute elem2);
#define CFG_makeTextAttributeMap2(elem1,  elem2) (_CFG_makeTextAttributeMap2(elem1,  elem2))
#endif
#ifdef FAST_API
#define CFG_makeTextAttributeMap3(elem1, elem2,  elem3) ((CFG_TextAttributeMap) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
CFG_TextAttributeMap _CFG_makeTextAttributeMap3 (CFG_TextAttribute elem1,
						 CFG_TextAttribute elem2,
						 CFG_TextAttribute elem3);
#define CFG_makeTextAttributeMap3(elem1, elem2,  elem3) (_CFG_makeTextAttributeMap3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define CFG_makeTextAttributeMap4(elem1, elem2, elem3,  elem4) ((CFG_TextAttributeMap) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
CFG_TextAttributeMap _CFG_makeTextAttributeMap4 (CFG_TextAttribute elem1,
						 CFG_TextAttribute elem2,
						 CFG_TextAttribute elem3,
						 CFG_TextAttribute elem4);
#define CFG_makeTextAttributeMap4(elem1, elem2, elem3,  elem4) (_CFG_makeTextAttributeMap4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define CFG_makeTextAttributeMap5(elem1, elem2, elem3, elem4,  elem5) ((CFG_TextAttributeMap) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
CFG_TextAttributeMap _CFG_makeTextAttributeMap5 (CFG_TextAttribute elem1,
						 CFG_TextAttribute elem2,
						 CFG_TextAttribute elem3,
						 CFG_TextAttribute elem4,
						 CFG_TextAttribute elem5);
#define CFG_makeTextAttributeMap5(elem1, elem2, elem3, elem4,  elem5) (_CFG_makeTextAttributeMap5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define CFG_makeTextAttributeMap6(elem1, elem2, elem3, elem4, elem5,  elem6) ((CFG_TextAttributeMap) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
CFG_TextAttributeMap _CFG_makeTextAttributeMap6 (CFG_TextAttribute elem1,
						 CFG_TextAttribute elem2,
						 CFG_TextAttribute elem3,
						 CFG_TextAttribute elem4,
						 CFG_TextAttribute elem5,
						 CFG_TextAttribute elem6);
#define CFG_makeTextAttributeMap6(elem1, elem2, elem3, elem4, elem5,  elem6) (_CFG_makeTextAttributeMap6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define CFG_getKeyModifierListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _CFG_getKeyModifierListLength (CFG_KeyModifierList arg);
#define CFG_getKeyModifierListLength(arg) (_CFG_getKeyModifierListLength(arg))
#endif
#ifdef FAST_API
#define CFG_reverseKeyModifierList(arg) ((CFG_KeyModifierList) ATreverse((ATermList) (arg)))
#else
CFG_KeyModifierList _CFG_reverseKeyModifierList (CFG_KeyModifierList arg);
#define CFG_reverseKeyModifierList(arg) (_CFG_reverseKeyModifierList(arg))
#endif
#ifdef FAST_API
#define CFG_appendKeyModifierList(arg, elem) ((CFG_KeyModifierList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
CFG_KeyModifierList _CFG_appendKeyModifierList (CFG_KeyModifierList arg,
						CFG_KeyModifier elem);
#define CFG_appendKeyModifierList(arg, elem) (_CFG_appendKeyModifierList(arg, elem))
#endif
#ifdef FAST_API
#define CFG_concatKeyModifierList(arg0, arg1) ((CFG_KeyModifierList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
CFG_KeyModifierList _CFG_concatKeyModifierList (CFG_KeyModifierList arg0,
						CFG_KeyModifierList arg1);
#define CFG_concatKeyModifierList(arg0, arg1) (_CFG_concatKeyModifierList(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_sliceKeyModifierList(arg, start, end) ((CFG_KeyModifierList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
CFG_KeyModifierList _CFG_sliceKeyModifierList (CFG_KeyModifierList arg,
					       int start, int end);
#define CFG_sliceKeyModifierList(arg, start, end) (_CFG_sliceKeyModifierList(arg, start, end))
#endif
#ifdef FAST_API
#define CFG_getKeyModifierListKeyModifierAt(arg, index) ((CFG_KeyModifier) (ATelementAt((ATermList) arg,index)))
#else
CFG_KeyModifier _CFG_getKeyModifierListKeyModifierAt (CFG_KeyModifierList arg,
						      int index);
#define CFG_getKeyModifierListKeyModifierAt(arg, index) (_CFG_getKeyModifierListKeyModifierAt(arg, index))
#endif
#ifdef FAST_API
#define CFG_replaceKeyModifierListKeyModifierAt(arg, elem, index) ((CFG_KeyModifierList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
CFG_KeyModifierList
_CFG_replaceKeyModifierListKeyModifierAt (CFG_KeyModifierList arg,
					  CFG_KeyModifier elem, int index);
#define CFG_replaceKeyModifierListKeyModifierAt(arg, elem, index) (_CFG_replaceKeyModifierListKeyModifierAt(arg, elem, index))
#endif
#ifdef FAST_API
#define CFG_makeKeyModifierList2(elem1,  elem2) ((CFG_KeyModifierList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
CFG_KeyModifierList _CFG_makeKeyModifierList2 (CFG_KeyModifier elem1,
					       CFG_KeyModifier elem2);
#define CFG_makeKeyModifierList2(elem1,  elem2) (_CFG_makeKeyModifierList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define CFG_makeKeyModifierList3(elem1, elem2,  elem3) ((CFG_KeyModifierList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
CFG_KeyModifierList _CFG_makeKeyModifierList3 (CFG_KeyModifier elem1,
					       CFG_KeyModifier elem2,
					       CFG_KeyModifier elem3);
#define CFG_makeKeyModifierList3(elem1, elem2,  elem3) (_CFG_makeKeyModifierList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define CFG_makeKeyModifierList4(elem1, elem2, elem3,  elem4) ((CFG_KeyModifierList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
CFG_KeyModifierList _CFG_makeKeyModifierList4 (CFG_KeyModifier elem1,
					       CFG_KeyModifier elem2,
					       CFG_KeyModifier elem3,
					       CFG_KeyModifier elem4);
#define CFG_makeKeyModifierList4(elem1, elem2, elem3,  elem4) (_CFG_makeKeyModifierList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define CFG_makeKeyModifierList5(elem1, elem2, elem3, elem4,  elem5) ((CFG_KeyModifierList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
CFG_KeyModifierList _CFG_makeKeyModifierList5 (CFG_KeyModifier elem1,
					       CFG_KeyModifier elem2,
					       CFG_KeyModifier elem3,
					       CFG_KeyModifier elem4,
					       CFG_KeyModifier elem5);
#define CFG_makeKeyModifierList5(elem1, elem2, elem3, elem4,  elem5) (_CFG_makeKeyModifierList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define CFG_makeKeyModifierList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((CFG_KeyModifierList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
CFG_KeyModifierList _CFG_makeKeyModifierList6 (CFG_KeyModifier elem1,
					       CFG_KeyModifier elem2,
					       CFG_KeyModifier elem3,
					       CFG_KeyModifier elem4,
					       CFG_KeyModifier elem5,
					       CFG_KeyModifier elem6);
#define CFG_makeKeyModifierList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_CFG_makeKeyModifierList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define CFG_getItemLabelsLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _CFG_getItemLabelsLength (CFG_ItemLabels arg);
#define CFG_getItemLabelsLength(arg) (_CFG_getItemLabelsLength(arg))
#endif
#ifdef FAST_API
#define CFG_reverseItemLabels(arg) ((CFG_ItemLabels) ATreverse((ATermList) (arg)))
#else
CFG_ItemLabels _CFG_reverseItemLabels (CFG_ItemLabels arg);
#define CFG_reverseItemLabels(arg) (_CFG_reverseItemLabels(arg))
#endif
#ifdef FAST_API
#define CFG_appendItemLabels(arg, elem) ((CFG_ItemLabels) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
CFG_ItemLabels _CFG_appendItemLabels (CFG_ItemLabels arg, CFG_Item elem);
#define CFG_appendItemLabels(arg, elem) (_CFG_appendItemLabels(arg, elem))
#endif
#ifdef FAST_API
#define CFG_concatItemLabels(arg0, arg1) ((CFG_ItemLabels) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
CFG_ItemLabels _CFG_concatItemLabels (CFG_ItemLabels arg0,
				      CFG_ItemLabels arg1);
#define CFG_concatItemLabels(arg0, arg1) (_CFG_concatItemLabels(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_sliceItemLabels(arg, start, end) ((CFG_ItemLabels) ATgetSlice((ATermList) (arg), (start), (end)))
#else
CFG_ItemLabels _CFG_sliceItemLabels (CFG_ItemLabels arg, int start, int end);
#define CFG_sliceItemLabels(arg, start, end) (_CFG_sliceItemLabels(arg, start, end))
#endif
#ifdef FAST_API
#define CFG_getItemLabelsItemAt(arg, index) ((CFG_Item) (ATelementAt((ATermList) arg,index)))
#else
CFG_Item _CFG_getItemLabelsItemAt (CFG_ItemLabels arg, int index);
#define CFG_getItemLabelsItemAt(arg, index) (_CFG_getItemLabelsItemAt(arg, index))
#endif
#ifdef FAST_API
#define CFG_replaceItemLabelsItemAt(arg, elem, index) ((CFG_ItemLabels) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
CFG_ItemLabels _CFG_replaceItemLabelsItemAt (CFG_ItemLabels arg,
					     CFG_Item elem, int index);
#define CFG_replaceItemLabelsItemAt(arg, elem, index) (_CFG_replaceItemLabelsItemAt(arg, elem, index))
#endif
#ifdef FAST_API
#define CFG_makeItemLabels2(elem1,  elem2) ((CFG_ItemLabels) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
CFG_ItemLabels _CFG_makeItemLabels2 (CFG_Item elem1, CFG_Item elem2);
#define CFG_makeItemLabels2(elem1,  elem2) (_CFG_makeItemLabels2(elem1,  elem2))
#endif
#ifdef FAST_API
#define CFG_makeItemLabels3(elem1, elem2,  elem3) ((CFG_ItemLabels) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
CFG_ItemLabels _CFG_makeItemLabels3 (CFG_Item elem1, CFG_Item elem2,
				     CFG_Item elem3);
#define CFG_makeItemLabels3(elem1, elem2,  elem3) (_CFG_makeItemLabels3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define CFG_makeItemLabels4(elem1, elem2, elem3,  elem4) ((CFG_ItemLabels) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
CFG_ItemLabels _CFG_makeItemLabels4 (CFG_Item elem1, CFG_Item elem2,
				     CFG_Item elem3, CFG_Item elem4);
#define CFG_makeItemLabels4(elem1, elem2, elem3,  elem4) (_CFG_makeItemLabels4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define CFG_makeItemLabels5(elem1, elem2, elem3, elem4,  elem5) ((CFG_ItemLabels) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
CFG_ItemLabels _CFG_makeItemLabels5 (CFG_Item elem1, CFG_Item elem2,
				     CFG_Item elem3, CFG_Item elem4,
				     CFG_Item elem5);
#define CFG_makeItemLabels5(elem1, elem2, elem3, elem4,  elem5) (_CFG_makeItemLabels5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define CFG_makeItemLabels6(elem1, elem2, elem3, elem4, elem5,  elem6) ((CFG_ItemLabels) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
CFG_ItemLabels _CFG_makeItemLabels6 (CFG_Item elem1, CFG_Item elem2,
				     CFG_Item elem3, CFG_Item elem4,
				     CFG_Item elem5, CFG_Item elem6);
#define CFG_makeItemLabels6(elem1, elem2, elem3, elem4, elem5,  elem6) (_CFG_makeItemLabels6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
CFG_VirtualButton CFG_makeVirtualButtonNOBUTTON (void);
CFG_VirtualButton CFG_makeVirtualButtonBUTTON1 (void);
CFG_VirtualButton CFG_makeVirtualButtonBUTTON2 (void);
CFG_VirtualButton CFG_makeVirtualButtonBUTTON3 (void);
CFG_KeyModifier CFG_makeKeyModifierMUnderscoreALT (void);
CFG_KeyModifier CFG_makeKeyModifierMUnderscoreCTRL (void);
CFG_KeyModifier CFG_makeKeyModifierMUnderscoreSHIFT (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore0 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore1 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore2 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore3 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore4 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore5 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore6 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore7 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore8 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore9 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreA (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreB (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreC (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreD (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreE (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreG (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreH (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreI (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreJ (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreK (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreL (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreM (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreN (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreO (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreP (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreQ (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreR (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreS (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreT (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreU (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreV (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreW (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreX (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreY (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreZ (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreAMPERSAND (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreASTERISK (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreAT (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBACKUnderscoreQUOTE (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBACKUnderscoreSLASH (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBACKUnderscoreSPACE (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBEGIN (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBRACEUnderscoreLEFT (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBRACEUnderscoreRIGHT (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreCIRCUMFLEX (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreCLEAR (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreCLOSEUnderscoreBRACKET (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreCOLON (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreCOMMA (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreDECIMAL (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreDELETE (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreDIVIDE (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreDOLLAR (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreDOWN (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreEND (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreENTER (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreEQUALS (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreESCAPE (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreEXCLAMATIONUnderscoreMARK (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF1 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF2 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF3 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF4 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF5 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF6 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF7 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF8 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF9 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF10 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF11 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF12 (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreGREATER (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreHOME (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreINSERT (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreLEFT (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreLEFTUnderscorePARENTHESIS (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreMINUS (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreMULTIPLY (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreNUMBERUnderscoreSIGN (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreOPENUnderscoreBRACKET (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePAGEUnderscoreDOWN (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePAGEUnderscoreUP (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePAUSE (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePERIOD (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePLUS (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePRINTSCREEN (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreQUOTE (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreQUOTEDBL (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreRIGHT (void);
CFG_VirtualKey
CFG_makeVirtualKeyVKUnderscoreRIGHTUnderscorePARENTHESIS (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreSEMICOLON (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreSLASH (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreSPACE (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreSUBTRACT (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreTAB (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreUNDERSCORE (void);
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreUP (void);
CFG_Color CFG_makeColorRgb (int red, int green, int blue);
CFG_Configuration CFG_makeConfigurationConfiguration (CFG_PropertyList list);
CFG_Property CFG_makePropertyImport (const char *path);
CFG_Property CFG_makePropertyScript (const char *path);
CFG_Property CFG_makePropertyScriptPath (const char *path);
CFG_Property CFG_makePropertyAction (CFG_ActionDescriptionList list,
				     const char *action);
CFG_Property CFG_makePropertyEditor (const char *editor, const char *language,
				     const char *extension);
CFG_Property CFG_makePropertyLibraryPath (const char *label,
					  const char *path);
CFG_Property CFG_makePropertyModulePath (const char *label, const char *path);
CFG_Property CFG_makePropertyTextCategory (CFG_TextCategoryName category,
					   CFG_TextAttributeMap map);
CFG_ActionDescription CFG_makeActionDescriptionDescription (ATerm context,
							    CFG_Event event);
CFG_Event CFG_makeEventPopup (void);
CFG_Event CFG_makeEventClick (CFG_KeyModifierList list,
			      CFG_VirtualButton button);
CFG_Event CFG_makeEventIcon (const char *title, const char *path);
CFG_Event CFG_makeEventMenu (CFG_ItemLabels labels, const char *info);
CFG_Event CFG_makeEventMenuShortcut (CFG_ItemLabels labels,
				     CFG_ShortCut shortcut, const char *info);
CFG_Item CFG_makeItemLabel (const char *name);
CFG_TextCategoryName CFG_makeTextCategoryNameFocus (void);
CFG_TextCategoryName CFG_makeTextCategoryNameSelection (void);
CFG_TextCategoryName CFG_makeTextCategoryNameNormal (void);
CFG_TextCategoryName CFG_makeTextCategoryNameExtern (const char *name);
CFG_TextAttribute CFG_makeTextAttributeForegroundColor (CFG_Color color);
CFG_TextAttribute CFG_makeTextAttributeBackgroundColor (CFG_Color color);
CFG_TextAttribute CFG_makeTextAttributeStyle (CFG_TextStyle style);
CFG_TextAttribute CFG_makeTextAttributeFont (const char *name);
CFG_TextAttribute CFG_makeTextAttributeSize (int point);
CFG_ShortCut CFG_makeShortCutShortcut (CFG_KeyModifierList list,
				       CFG_VirtualKey key);
CFG_TextStyle CFG_makeTextStyleBold (void);
CFG_TextStyle CFG_makeTextStyleItalics (void);
CFG_TextStyle CFG_makeTextStyleUnderlined (void);
CFG_PropertyList CFG_makePropertyListEmpty (void);
CFG_PropertyList CFG_makePropertyListSingle (CFG_Property head);
CFG_PropertyList CFG_makePropertyListMany (CFG_Property head,
					   CFG_PropertyList tail);
CFG_ActionDescriptionList CFG_makeActionDescriptionListEmpty (void);
CFG_ActionDescriptionList
CFG_makeActionDescriptionListSingle (CFG_ActionDescription head);
CFG_ActionDescriptionList
CFG_makeActionDescriptionListMany (CFG_ActionDescription head,
				   CFG_ActionDescriptionList tail);
CFG_TextAttributeMap CFG_makeTextAttributeMapEmpty (void);
CFG_TextAttributeMap CFG_makeTextAttributeMapSingle (CFG_TextAttribute head);
CFG_TextAttributeMap CFG_makeTextAttributeMapMany (CFG_TextAttribute head,
						   CFG_TextAttributeMap tail);
CFG_KeyModifierList CFG_makeKeyModifierListEmpty (void);
CFG_KeyModifierList CFG_makeKeyModifierListSingle (CFG_KeyModifier head);
CFG_KeyModifierList CFG_makeKeyModifierListMany (CFG_KeyModifier head,
						 CFG_KeyModifierList tail);
CFG_ItemLabels CFG_makeItemLabelsEmpty (void);
CFG_ItemLabels CFG_makeItemLabelsSingle (CFG_Item head);
CFG_ItemLabels CFG_makeItemLabelsMany (CFG_Item head, CFG_ItemLabels tail);
#ifdef FAST_API
#define CFG_isEqualVirtualButton(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualVirtualButton (CFG_VirtualButton arg0,
				  CFG_VirtualButton arg1);
#define CFG_isEqualVirtualButton(arg0, arg1) (_CFG_isEqualVirtualButton(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualKeyModifier(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualKeyModifier (CFG_KeyModifier arg0, CFG_KeyModifier arg1);
#define CFG_isEqualKeyModifier(arg0, arg1) (_CFG_isEqualKeyModifier(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualVirtualKey(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualVirtualKey (CFG_VirtualKey arg0, CFG_VirtualKey arg1);
#define CFG_isEqualVirtualKey(arg0, arg1) (_CFG_isEqualVirtualKey(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualColor(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualColor (CFG_Color arg0, CFG_Color arg1);
#define CFG_isEqualColor(arg0, arg1) (_CFG_isEqualColor(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualConfiguration(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualConfiguration (CFG_Configuration arg0,
				  CFG_Configuration arg1);
#define CFG_isEqualConfiguration(arg0, arg1) (_CFG_isEqualConfiguration(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualProperty(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualProperty (CFG_Property arg0, CFG_Property arg1);
#define CFG_isEqualProperty(arg0, arg1) (_CFG_isEqualProperty(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualActionDescription(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualActionDescription (CFG_ActionDescription arg0,
				      CFG_ActionDescription arg1);
#define CFG_isEqualActionDescription(arg0, arg1) (_CFG_isEqualActionDescription(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualEvent(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualEvent (CFG_Event arg0, CFG_Event arg1);
#define CFG_isEqualEvent(arg0, arg1) (_CFG_isEqualEvent(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualItem(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualItem (CFG_Item arg0, CFG_Item arg1);
#define CFG_isEqualItem(arg0, arg1) (_CFG_isEqualItem(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualTextCategoryName(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualTextCategoryName (CFG_TextCategoryName arg0,
				     CFG_TextCategoryName arg1);
#define CFG_isEqualTextCategoryName(arg0, arg1) (_CFG_isEqualTextCategoryName(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualTextAttribute(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualTextAttribute (CFG_TextAttribute arg0,
				  CFG_TextAttribute arg1);
#define CFG_isEqualTextAttribute(arg0, arg1) (_CFG_isEqualTextAttribute(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualShortCut(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualShortCut (CFG_ShortCut arg0, CFG_ShortCut arg1);
#define CFG_isEqualShortCut(arg0, arg1) (_CFG_isEqualShortCut(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualTextStyle(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualTextStyle (CFG_TextStyle arg0, CFG_TextStyle arg1);
#define CFG_isEqualTextStyle(arg0, arg1) (_CFG_isEqualTextStyle(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualPropertyList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualPropertyList (CFG_PropertyList arg0,
				 CFG_PropertyList arg1);
#define CFG_isEqualPropertyList(arg0, arg1) (_CFG_isEqualPropertyList(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualActionDescriptionList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualActionDescriptionList (CFG_ActionDescriptionList arg0,
					  CFG_ActionDescriptionList arg1);
#define CFG_isEqualActionDescriptionList(arg0, arg1) (_CFG_isEqualActionDescriptionList(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualTextAttributeMap(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualTextAttributeMap (CFG_TextAttributeMap arg0,
				     CFG_TextAttributeMap arg1);
#define CFG_isEqualTextAttributeMap(arg0, arg1) (_CFG_isEqualTextAttributeMap(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualKeyModifierList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualKeyModifierList (CFG_KeyModifierList arg0,
				    CFG_KeyModifierList arg1);
#define CFG_isEqualKeyModifierList(arg0, arg1) (_CFG_isEqualKeyModifierList(arg0, arg1))
#endif
#ifdef FAST_API
#define CFG_isEqualItemLabels(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CFG_isEqualItemLabels (CFG_ItemLabels arg0, CFG_ItemLabels arg1);
#define CFG_isEqualItemLabels(arg0, arg1) (_CFG_isEqualItemLabels(arg0, arg1))
#endif
ATbool CFG_isValidVirtualButton (CFG_VirtualButton arg);
inline ATbool CFG_isVirtualButtonNOBUTTON (CFG_VirtualButton arg);
inline ATbool CFG_isVirtualButtonBUTTON1 (CFG_VirtualButton arg);
inline ATbool CFG_isVirtualButtonBUTTON2 (CFG_VirtualButton arg);
inline ATbool CFG_isVirtualButtonBUTTON3 (CFG_VirtualButton arg);
ATbool CFG_isValidKeyModifier (CFG_KeyModifier arg);
inline ATbool CFG_isKeyModifierMUnderscoreALT (CFG_KeyModifier arg);
inline ATbool CFG_isKeyModifierMUnderscoreCTRL (CFG_KeyModifier arg);
inline ATbool CFG_isKeyModifierMUnderscoreSHIFT (CFG_KeyModifier arg);
ATbool CFG_isValidVirtualKey (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscore0 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscore1 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscore2 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscore3 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscore4 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscore5 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscore6 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscore7 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscore8 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscore9 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreA (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreB (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreC (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreD (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreE (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreF (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreG (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreH (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreI (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreJ (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreK (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreL (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreM (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreN (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreO (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreP (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreQ (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreR (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreS (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreT (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreU (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreV (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreW (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreX (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreY (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreZ (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreAMPERSAND (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreASTERISK (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreAT (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreBACKUnderscoreQUOTE (CFG_VirtualKey
							       arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreBACKUnderscoreSLASH (CFG_VirtualKey
							       arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreBACKUnderscoreSPACE (CFG_VirtualKey
							       arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreBEGIN (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreBRACEUnderscoreLEFT (CFG_VirtualKey
							       arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreBRACEUnderscoreRIGHT (CFG_VirtualKey
								arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreCIRCUMFLEX (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreCLEAR (CFG_VirtualKey arg);
inline ATbool
CFG_isVirtualKeyVKUnderscoreCLOSEUnderscoreBRACKET (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreCOLON (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreCOMMA (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreDECIMAL (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreDELETE (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreDIVIDE (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreDOLLAR (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreDOWN (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreEND (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreENTER (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreEQUALS (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreESCAPE (CFG_VirtualKey arg);
inline ATbool
CFG_isVirtualKeyVKUnderscoreEXCLAMATIONUnderscoreMARK (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreF1 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreF2 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreF3 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreF4 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreF5 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreF6 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreF7 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreF8 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreF9 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreF10 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreF11 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreF12 (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreGREATER (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreHOME (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreINSERT (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreLEFT (CFG_VirtualKey arg);
inline ATbool
CFG_isVirtualKeyVKUnderscoreLEFTUnderscorePARENTHESIS (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreMINUS (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreMULTIPLY (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreNUMBERUnderscoreSIGN (CFG_VirtualKey
								arg);
inline ATbool
CFG_isVirtualKeyVKUnderscoreOPENUnderscoreBRACKET (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscorePAGEUnderscoreDOWN (CFG_VirtualKey
							      arg);
inline ATbool CFG_isVirtualKeyVKUnderscorePAGEUnderscoreUP (CFG_VirtualKey
							    arg);
inline ATbool CFG_isVirtualKeyVKUnderscorePAUSE (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscorePERIOD (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscorePLUS (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscorePRINTSCREEN (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreQUOTE (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreQUOTEDBL (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreRIGHT (CFG_VirtualKey arg);
inline ATbool
CFG_isVirtualKeyVKUnderscoreRIGHTUnderscorePARENTHESIS (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreSEMICOLON (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreSLASH (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreSPACE (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreSUBTRACT (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreTAB (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreUNDERSCORE (CFG_VirtualKey arg);
inline ATbool CFG_isVirtualKeyVKUnderscoreUP (CFG_VirtualKey arg);
ATbool CFG_isValidColor (CFG_Color arg);
inline ATbool CFG_isColorRgb (CFG_Color arg);
ATbool CFG_hasColorRed (CFG_Color arg);
ATbool CFG_hasColorGreen (CFG_Color arg);
ATbool CFG_hasColorBlue (CFG_Color arg);
int CFG_getColorRed (CFG_Color arg);
int CFG_getColorGreen (CFG_Color arg);
int CFG_getColorBlue (CFG_Color arg);
CFG_Color CFG_setColorRed (CFG_Color arg, int red);
CFG_Color CFG_setColorGreen (CFG_Color arg, int green);
CFG_Color CFG_setColorBlue (CFG_Color arg, int blue);
ATbool CFG_isValidConfiguration (CFG_Configuration arg);
inline ATbool CFG_isConfigurationConfiguration (CFG_Configuration arg);
ATbool CFG_hasConfigurationList (CFG_Configuration arg);
CFG_PropertyList CFG_getConfigurationList (CFG_Configuration arg);
CFG_Configuration CFG_setConfigurationList (CFG_Configuration arg,
					    CFG_PropertyList list);
ATbool CFG_isValidProperty (CFG_Property arg);
inline ATbool CFG_isPropertyImport (CFG_Property arg);
inline ATbool CFG_isPropertyScript (CFG_Property arg);
inline ATbool CFG_isPropertyScriptPath (CFG_Property arg);
inline ATbool CFG_isPropertyAction (CFG_Property arg);
inline ATbool CFG_isPropertyEditor (CFG_Property arg);
inline ATbool CFG_isPropertyLibraryPath (CFG_Property arg);
inline ATbool CFG_isPropertyModulePath (CFG_Property arg);
inline ATbool CFG_isPropertyTextCategory (CFG_Property arg);
ATbool CFG_hasPropertyPath (CFG_Property arg);
ATbool CFG_hasPropertyList (CFG_Property arg);
ATbool CFG_hasPropertyAction (CFG_Property arg);
ATbool CFG_hasPropertyEditor (CFG_Property arg);
ATbool CFG_hasPropertyLanguage (CFG_Property arg);
ATbool CFG_hasPropertyExtension (CFG_Property arg);
ATbool CFG_hasPropertyLabel (CFG_Property arg);
ATbool CFG_hasPropertyCategory (CFG_Property arg);
ATbool CFG_hasPropertyMap (CFG_Property arg);
char *CFG_getPropertyPath (CFG_Property arg);
CFG_ActionDescriptionList CFG_getPropertyList (CFG_Property arg);
char *CFG_getPropertyAction (CFG_Property arg);
char *CFG_getPropertyEditor (CFG_Property arg);
char *CFG_getPropertyLanguage (CFG_Property arg);
char *CFG_getPropertyExtension (CFG_Property arg);
char *CFG_getPropertyLabel (CFG_Property arg);
CFG_TextCategoryName CFG_getPropertyCategory (CFG_Property arg);
CFG_TextAttributeMap CFG_getPropertyMap (CFG_Property arg);
CFG_Property CFG_setPropertyPath (CFG_Property arg, const char *path);
CFG_Property CFG_setPropertyList (CFG_Property arg,
				  CFG_ActionDescriptionList list);
CFG_Property CFG_setPropertyAction (CFG_Property arg, const char *action);
CFG_Property CFG_setPropertyEditor (CFG_Property arg, const char *editor);
CFG_Property CFG_setPropertyLanguage (CFG_Property arg, const char *language);
CFG_Property CFG_setPropertyExtension (CFG_Property arg,
				       const char *extension);
CFG_Property CFG_setPropertyLabel (CFG_Property arg, const char *label);
CFG_Property CFG_setPropertyCategory (CFG_Property arg,
				      CFG_TextCategoryName category);
CFG_Property CFG_setPropertyMap (CFG_Property arg, CFG_TextAttributeMap map);
ATbool CFG_isValidActionDescription (CFG_ActionDescription arg);
inline ATbool CFG_isActionDescriptionDescription (CFG_ActionDescription arg);
ATbool CFG_hasActionDescriptionContext (CFG_ActionDescription arg);
ATbool CFG_hasActionDescriptionEvent (CFG_ActionDescription arg);
ATerm CFG_getActionDescriptionContext (CFG_ActionDescription arg);
CFG_Event CFG_getActionDescriptionEvent (CFG_ActionDescription arg);
CFG_ActionDescription CFG_setActionDescriptionContext (CFG_ActionDescription
						       arg, ATerm context);
CFG_ActionDescription CFG_setActionDescriptionEvent (CFG_ActionDescription
						     arg, CFG_Event event);
ATbool CFG_isValidEvent (CFG_Event arg);
inline ATbool CFG_isEventPopup (CFG_Event arg);
inline ATbool CFG_isEventClick (CFG_Event arg);
inline ATbool CFG_isEventIcon (CFG_Event arg);
inline ATbool CFG_isEventMenu (CFG_Event arg);
inline ATbool CFG_isEventMenuShortcut (CFG_Event arg);
ATbool CFG_hasEventList (CFG_Event arg);
ATbool CFG_hasEventButton (CFG_Event arg);
ATbool CFG_hasEventTitle (CFG_Event arg);
ATbool CFG_hasEventPath (CFG_Event arg);
ATbool CFG_hasEventLabels (CFG_Event arg);
ATbool CFG_hasEventInfo (CFG_Event arg);
ATbool CFG_hasEventShortcut (CFG_Event arg);
CFG_KeyModifierList CFG_getEventList (CFG_Event arg);
CFG_VirtualButton CFG_getEventButton (CFG_Event arg);
char *CFG_getEventTitle (CFG_Event arg);
char *CFG_getEventPath (CFG_Event arg);
CFG_ItemLabels CFG_getEventLabels (CFG_Event arg);
char *CFG_getEventInfo (CFG_Event arg);
CFG_ShortCut CFG_getEventShortcut (CFG_Event arg);
CFG_Event CFG_setEventList (CFG_Event arg, CFG_KeyModifierList list);
CFG_Event CFG_setEventButton (CFG_Event arg, CFG_VirtualButton button);
CFG_Event CFG_setEventTitle (CFG_Event arg, const char *title);
CFG_Event CFG_setEventPath (CFG_Event arg, const char *path);
CFG_Event CFG_setEventLabels (CFG_Event arg, CFG_ItemLabels labels);
CFG_Event CFG_setEventInfo (CFG_Event arg, const char *info);
CFG_Event CFG_setEventShortcut (CFG_Event arg, CFG_ShortCut shortcut);
ATbool CFG_isValidItem (CFG_Item arg);
inline ATbool CFG_isItemLabel (CFG_Item arg);
ATbool CFG_hasItemName (CFG_Item arg);
char *CFG_getItemName (CFG_Item arg);
CFG_Item CFG_setItemName (CFG_Item arg, const char *name);
ATbool CFG_isValidTextCategoryName (CFG_TextCategoryName arg);
inline ATbool CFG_isTextCategoryNameFocus (CFG_TextCategoryName arg);
inline ATbool CFG_isTextCategoryNameSelection (CFG_TextCategoryName arg);
inline ATbool CFG_isTextCategoryNameNormal (CFG_TextCategoryName arg);
inline ATbool CFG_isTextCategoryNameExtern (CFG_TextCategoryName arg);
ATbool CFG_hasTextCategoryNameName (CFG_TextCategoryName arg);
char *CFG_getTextCategoryNameName (CFG_TextCategoryName arg);
CFG_TextCategoryName CFG_setTextCategoryNameName (CFG_TextCategoryName arg,
						  const char *name);
ATbool CFG_isValidTextAttribute (CFG_TextAttribute arg);
inline ATbool CFG_isTextAttributeForegroundColor (CFG_TextAttribute arg);
inline ATbool CFG_isTextAttributeBackgroundColor (CFG_TextAttribute arg);
inline ATbool CFG_isTextAttributeStyle (CFG_TextAttribute arg);
inline ATbool CFG_isTextAttributeFont (CFG_TextAttribute arg);
inline ATbool CFG_isTextAttributeSize (CFG_TextAttribute arg);
ATbool CFG_hasTextAttributeColor (CFG_TextAttribute arg);
ATbool CFG_hasTextAttributeStyle (CFG_TextAttribute arg);
ATbool CFG_hasTextAttributeName (CFG_TextAttribute arg);
ATbool CFG_hasTextAttributePoint (CFG_TextAttribute arg);
CFG_Color CFG_getTextAttributeColor (CFG_TextAttribute arg);
CFG_TextStyle CFG_getTextAttributeStyle (CFG_TextAttribute arg);
char *CFG_getTextAttributeName (CFG_TextAttribute arg);
int CFG_getTextAttributePoint (CFG_TextAttribute arg);
CFG_TextAttribute CFG_setTextAttributeColor (CFG_TextAttribute arg,
					     CFG_Color color);
CFG_TextAttribute CFG_setTextAttributeStyle (CFG_TextAttribute arg,
					     CFG_TextStyle style);
CFG_TextAttribute CFG_setTextAttributeName (CFG_TextAttribute arg,
					    const char *name);
CFG_TextAttribute CFG_setTextAttributePoint (CFG_TextAttribute arg,
					     int point);
ATbool CFG_isValidShortCut (CFG_ShortCut arg);
inline ATbool CFG_isShortCutShortcut (CFG_ShortCut arg);
ATbool CFG_hasShortCutList (CFG_ShortCut arg);
ATbool CFG_hasShortCutKey (CFG_ShortCut arg);
CFG_KeyModifierList CFG_getShortCutList (CFG_ShortCut arg);
CFG_VirtualKey CFG_getShortCutKey (CFG_ShortCut arg);
CFG_ShortCut CFG_setShortCutList (CFG_ShortCut arg, CFG_KeyModifierList list);
CFG_ShortCut CFG_setShortCutKey (CFG_ShortCut arg, CFG_VirtualKey key);
ATbool CFG_isValidTextStyle (CFG_TextStyle arg);
inline ATbool CFG_isTextStyleBold (CFG_TextStyle arg);
inline ATbool CFG_isTextStyleItalics (CFG_TextStyle arg);
inline ATbool CFG_isTextStyleUnderlined (CFG_TextStyle arg);
ATbool CFG_isValidPropertyList (CFG_PropertyList arg);
inline ATbool CFG_isPropertyListEmpty (CFG_PropertyList arg);
inline ATbool CFG_isPropertyListSingle (CFG_PropertyList arg);
inline ATbool CFG_isPropertyListMany (CFG_PropertyList arg);
ATbool CFG_hasPropertyListHead (CFG_PropertyList arg);
ATbool CFG_hasPropertyListTail (CFG_PropertyList arg);
CFG_Property CFG_getPropertyListHead (CFG_PropertyList arg);
CFG_PropertyList CFG_getPropertyListTail (CFG_PropertyList arg);
CFG_PropertyList CFG_setPropertyListHead (CFG_PropertyList arg,
					  CFG_Property head);
CFG_PropertyList CFG_setPropertyListTail (CFG_PropertyList arg,
					  CFG_PropertyList tail);
ATbool CFG_isValidActionDescriptionList (CFG_ActionDescriptionList arg);
inline ATbool CFG_isActionDescriptionListEmpty (CFG_ActionDescriptionList
						arg);
inline ATbool CFG_isActionDescriptionListSingle (CFG_ActionDescriptionList
						 arg);
inline ATbool CFG_isActionDescriptionListMany (CFG_ActionDescriptionList arg);
ATbool CFG_hasActionDescriptionListHead (CFG_ActionDescriptionList arg);
ATbool CFG_hasActionDescriptionListTail (CFG_ActionDescriptionList arg);
CFG_ActionDescription
CFG_getActionDescriptionListHead (CFG_ActionDescriptionList arg);
CFG_ActionDescriptionList
CFG_getActionDescriptionListTail (CFG_ActionDescriptionList arg);
CFG_ActionDescriptionList
CFG_setActionDescriptionListHead (CFG_ActionDescriptionList arg,
				  CFG_ActionDescription head);
CFG_ActionDescriptionList
CFG_setActionDescriptionListTail (CFG_ActionDescriptionList arg,
				  CFG_ActionDescriptionList tail);
ATbool CFG_isValidTextAttributeMap (CFG_TextAttributeMap arg);
inline ATbool CFG_isTextAttributeMapEmpty (CFG_TextAttributeMap arg);
inline ATbool CFG_isTextAttributeMapSingle (CFG_TextAttributeMap arg);
inline ATbool CFG_isTextAttributeMapMany (CFG_TextAttributeMap arg);
ATbool CFG_hasTextAttributeMapHead (CFG_TextAttributeMap arg);
ATbool CFG_hasTextAttributeMapTail (CFG_TextAttributeMap arg);
CFG_TextAttribute CFG_getTextAttributeMapHead (CFG_TextAttributeMap arg);
CFG_TextAttributeMap CFG_getTextAttributeMapTail (CFG_TextAttributeMap arg);
CFG_TextAttributeMap CFG_setTextAttributeMapHead (CFG_TextAttributeMap arg,
						  CFG_TextAttribute head);
CFG_TextAttributeMap CFG_setTextAttributeMapTail (CFG_TextAttributeMap arg,
						  CFG_TextAttributeMap tail);
ATbool CFG_isValidKeyModifierList (CFG_KeyModifierList arg);
inline ATbool CFG_isKeyModifierListEmpty (CFG_KeyModifierList arg);
inline ATbool CFG_isKeyModifierListSingle (CFG_KeyModifierList arg);
inline ATbool CFG_isKeyModifierListMany (CFG_KeyModifierList arg);
ATbool CFG_hasKeyModifierListHead (CFG_KeyModifierList arg);
ATbool CFG_hasKeyModifierListTail (CFG_KeyModifierList arg);
CFG_KeyModifier CFG_getKeyModifierListHead (CFG_KeyModifierList arg);
CFG_KeyModifierList CFG_getKeyModifierListTail (CFG_KeyModifierList arg);
CFG_KeyModifierList CFG_setKeyModifierListHead (CFG_KeyModifierList arg,
						CFG_KeyModifier head);
CFG_KeyModifierList CFG_setKeyModifierListTail (CFG_KeyModifierList arg,
						CFG_KeyModifierList tail);
ATbool CFG_isValidItemLabels (CFG_ItemLabels arg);
inline ATbool CFG_isItemLabelsEmpty (CFG_ItemLabels arg);
inline ATbool CFG_isItemLabelsSingle (CFG_ItemLabels arg);
inline ATbool CFG_isItemLabelsMany (CFG_ItemLabels arg);
ATbool CFG_hasItemLabelsHead (CFG_ItemLabels arg);
ATbool CFG_hasItemLabelsTail (CFG_ItemLabels arg);
CFG_Item CFG_getItemLabelsHead (CFG_ItemLabels arg);
CFG_ItemLabels CFG_getItemLabelsTail (CFG_ItemLabels arg);
CFG_ItemLabels CFG_setItemLabelsHead (CFG_ItemLabels arg, CFG_Item head);
CFG_ItemLabels CFG_setItemLabelsTail (CFG_ItemLabels arg,
				      CFG_ItemLabels tail);
CFG_VirtualButton CFG_visitVirtualButton (CFG_VirtualButton arg);
CFG_KeyModifier CFG_visitKeyModifier (CFG_KeyModifier arg);
CFG_VirtualKey CFG_visitVirtualKey (CFG_VirtualKey arg);
CFG_Color CFG_visitColor (CFG_Color arg, int (*acceptRed) (int),
			  int (*acceptGreen) (int), int (*acceptBlue) (int));
CFG_Configuration CFG_visitConfiguration (CFG_Configuration arg,
					  CFG_PropertyList (*acceptList)
					  (CFG_PropertyList));
CFG_Property CFG_visitProperty (CFG_Property arg,
				char *(*acceptPath) (char *),
				CFG_ActionDescriptionList (*acceptList)
				(CFG_ActionDescriptionList),
				char *(*acceptAction) (char *),
				char *(*acceptEditor) (char *),
				char *(*acceptLanguage) (char *),
				char *(*acceptExtension) (char *),
				char *(*acceptLabel) (char *),
				CFG_TextCategoryName (*acceptCategory)
				(CFG_TextCategoryName),
				CFG_TextAttributeMap (*acceptMap)
				(CFG_TextAttributeMap));
CFG_ActionDescription CFG_visitActionDescription (CFG_ActionDescription arg,
						  ATerm (*acceptContext)
						  (ATerm),
						  CFG_Event (*acceptEvent)
						  (CFG_Event));
CFG_Event CFG_visitEvent (CFG_Event arg,
			  CFG_KeyModifierList (*acceptList)
			  (CFG_KeyModifierList),
			  CFG_VirtualButton (*acceptButton)
			  (CFG_VirtualButton), char *(*acceptTitle) (char *),
			  char *(*acceptPath) (char *),
			  CFG_ItemLabels (*acceptLabels) (CFG_ItemLabels),
			  char *(*acceptInfo) (char *),
			  CFG_ShortCut (*acceptShortcut) (CFG_ShortCut));
CFG_Item CFG_visitItem (CFG_Item arg, char *(*acceptName) (char *));
CFG_TextCategoryName CFG_visitTextCategoryName (CFG_TextCategoryName arg,
						char *(*acceptName) (char *));
CFG_TextAttribute CFG_visitTextAttribute (CFG_TextAttribute arg,
					  CFG_Color (*acceptColor)
					  (CFG_Color),
					  CFG_TextStyle (*acceptStyle)
					  (CFG_TextStyle),
					  char *(*acceptName) (char *),
					  int (*acceptPoint) (int));
CFG_ShortCut CFG_visitShortCut (CFG_ShortCut arg,
				CFG_KeyModifierList (*acceptList)
				(CFG_KeyModifierList),
				CFG_VirtualKey (*acceptKey) (CFG_VirtualKey));
CFG_TextStyle CFG_visitTextStyle (CFG_TextStyle arg);
CFG_PropertyList CFG_visitPropertyList (CFG_PropertyList arg,
					CFG_Property (*acceptHead)
					(CFG_Property));
CFG_ActionDescriptionList
CFG_visitActionDescriptionList (CFG_ActionDescriptionList arg,
				CFG_ActionDescription (*acceptHead)
				(CFG_ActionDescription));
CFG_TextAttributeMap CFG_visitTextAttributeMap (CFG_TextAttributeMap arg,
						CFG_TextAttribute
						(*acceptHead)
						(CFG_TextAttribute));
CFG_KeyModifierList CFG_visitKeyModifierList (CFG_KeyModifierList arg,
					      CFG_KeyModifier (*acceptHead)
					      (CFG_KeyModifier));
CFG_ItemLabels CFG_visitItemLabels (CFG_ItemLabels arg,
				    CFG_Item (*acceptHead) (CFG_Item));

#endif /* _CONFIG_H */
