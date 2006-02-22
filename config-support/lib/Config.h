#ifndef _CONFIG_H
#define _CONFIG_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Config_dict.h"

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
typedef struct _CFG_ItemList *CFG_ItemList;
typedef struct _CFG_KeyModifierList *CFG_KeyModifierList;

void CFG_initConfigApi (void);

void CFG_protectKeyModifier (CFG_KeyModifier * arg);
void CFG_unprotectKeyModifier (CFG_KeyModifier * arg);
void CFG_protectVirtualKey (CFG_VirtualKey * arg);
void CFG_unprotectVirtualKey (CFG_VirtualKey * arg);
void CFG_protectColor (CFG_Color * arg);
void CFG_unprotectColor (CFG_Color * arg);
void CFG_protectConfiguration (CFG_Configuration * arg);
void CFG_unprotectConfiguration (CFG_Configuration * arg);
void CFG_protectProperty (CFG_Property * arg);
void CFG_unprotectProperty (CFG_Property * arg);
void CFG_protectActionDescription (CFG_ActionDescription * arg);
void CFG_unprotectActionDescription (CFG_ActionDescription * arg);
void CFG_protectEvent (CFG_Event * arg);
void CFG_unprotectEvent (CFG_Event * arg);
void CFG_protectItem (CFG_Item * arg);
void CFG_unprotectItem (CFG_Item * arg);
void CFG_protectTextCategoryName (CFG_TextCategoryName * arg);
void CFG_unprotectTextCategoryName (CFG_TextCategoryName * arg);
void CFG_protectTextAttribute (CFG_TextAttribute * arg);
void CFG_unprotectTextAttribute (CFG_TextAttribute * arg);
void CFG_protectShortCut (CFG_ShortCut * arg);
void CFG_unprotectShortCut (CFG_ShortCut * arg);
void CFG_protectTextStyle (CFG_TextStyle * arg);
void CFG_unprotectTextStyle (CFG_TextStyle * arg);
void CFG_protectPropertyList (CFG_PropertyList * arg);
void CFG_unprotectPropertyList (CFG_PropertyList * arg);
void CFG_protectActionDescriptionList (CFG_ActionDescriptionList * arg);
void CFG_unprotectActionDescriptionList (CFG_ActionDescriptionList * arg);
void CFG_protectTextAttributeMap (CFG_TextAttributeMap * arg);
void CFG_unprotectTextAttributeMap (CFG_TextAttributeMap * arg);
void CFG_protectItemList (CFG_ItemList * arg);
void CFG_unprotectItemList (CFG_ItemList * arg);
void CFG_protectKeyModifierList (CFG_KeyModifierList * arg);
void CFG_unprotectKeyModifierList (CFG_KeyModifierList * arg);
CFG_KeyModifier CFG_KeyModifierFromTerm (ATerm t);
ATerm CFG_KeyModifierToTerm (CFG_KeyModifier arg);
CFG_VirtualKey CFG_VirtualKeyFromTerm (ATerm t);
ATerm CFG_VirtualKeyToTerm (CFG_VirtualKey arg);
CFG_Color CFG_ColorFromTerm (ATerm t);
ATerm CFG_ColorToTerm (CFG_Color arg);
CFG_Configuration CFG_ConfigurationFromTerm (ATerm t);
ATerm CFG_ConfigurationToTerm (CFG_Configuration arg);
CFG_Property CFG_PropertyFromTerm (ATerm t);
ATerm CFG_PropertyToTerm (CFG_Property arg);
CFG_ActionDescription CFG_ActionDescriptionFromTerm (ATerm t);
ATerm CFG_ActionDescriptionToTerm (CFG_ActionDescription arg);
CFG_Event CFG_EventFromTerm (ATerm t);
ATerm CFG_EventToTerm (CFG_Event arg);
CFG_Item CFG_ItemFromTerm (ATerm t);
ATerm CFG_ItemToTerm (CFG_Item arg);
CFG_TextCategoryName CFG_TextCategoryNameFromTerm (ATerm t);
ATerm CFG_TextCategoryNameToTerm (CFG_TextCategoryName arg);
CFG_TextAttribute CFG_TextAttributeFromTerm (ATerm t);
ATerm CFG_TextAttributeToTerm (CFG_TextAttribute arg);
CFG_ShortCut CFG_ShortCutFromTerm (ATerm t);
ATerm CFG_ShortCutToTerm (CFG_ShortCut arg);
CFG_TextStyle CFG_TextStyleFromTerm (ATerm t);
ATerm CFG_TextStyleToTerm (CFG_TextStyle arg);
CFG_PropertyList CFG_PropertyListFromTerm (ATerm t);
ATerm CFG_PropertyListToTerm (CFG_PropertyList arg);
CFG_ActionDescriptionList CFG_ActionDescriptionListFromTerm (ATerm t);
ATerm CFG_ActionDescriptionListToTerm (CFG_ActionDescriptionList arg);
CFG_TextAttributeMap CFG_TextAttributeMapFromTerm (ATerm t);
ATerm CFG_TextAttributeMapToTerm (CFG_TextAttributeMap arg);
CFG_ItemList CFG_ItemListFromTerm (ATerm t);
ATerm CFG_ItemListToTerm (CFG_ItemList arg);
CFG_KeyModifierList CFG_KeyModifierListFromTerm (ATerm t);
ATerm CFG_KeyModifierListToTerm (CFG_KeyModifierList arg);
int CFG_getPropertyListLength (CFG_PropertyList arg);
CFG_PropertyList CFG_reversePropertyList (CFG_PropertyList arg);
CFG_PropertyList CFG_appendPropertyList (CFG_PropertyList arg,
					 CFG_Property elem);
CFG_PropertyList CFG_concatPropertyList (CFG_PropertyList arg0,
					 CFG_PropertyList arg1);
CFG_PropertyList CFG_slicePropertyList (CFG_PropertyList arg, int start,
					int end);
CFG_Property CFG_getPropertyListPropertyAt (CFG_PropertyList arg, int index);
CFG_PropertyList CFG_replacePropertyListPropertyAt (CFG_PropertyList arg,
						    CFG_Property elem,
						    int index);
CFG_PropertyList CFG_makePropertyList2 (CFG_Property elem1,
					CFG_Property elem2);
CFG_PropertyList CFG_makePropertyList3 (CFG_Property elem1,
					CFG_Property elem2,
					CFG_Property elem3);
CFG_PropertyList CFG_makePropertyList4 (CFG_Property elem1,
					CFG_Property elem2,
					CFG_Property elem3,
					CFG_Property elem4);
CFG_PropertyList CFG_makePropertyList5 (CFG_Property elem1,
					CFG_Property elem2,
					CFG_Property elem3,
					CFG_Property elem4,
					CFG_Property elem5);
CFG_PropertyList CFG_makePropertyList6 (CFG_Property elem1,
					CFG_Property elem2,
					CFG_Property elem3,
					CFG_Property elem4,
					CFG_Property elem5,
					CFG_Property elem6);
int CFG_getActionDescriptionListLength (CFG_ActionDescriptionList arg);
CFG_ActionDescriptionList
CFG_reverseActionDescriptionList (CFG_ActionDescriptionList arg);
CFG_ActionDescriptionList
CFG_appendActionDescriptionList (CFG_ActionDescriptionList arg,
				 CFG_ActionDescription elem);
CFG_ActionDescriptionList
CFG_concatActionDescriptionList (CFG_ActionDescriptionList arg0,
				 CFG_ActionDescriptionList arg1);
CFG_ActionDescriptionList
CFG_sliceActionDescriptionList (CFG_ActionDescriptionList arg, int start,
				int end);
CFG_ActionDescription
CFG_getActionDescriptionListActionDescriptionAt (CFG_ActionDescriptionList
						 arg, int index);
CFG_ActionDescriptionList
CFG_replaceActionDescriptionListActionDescriptionAt (CFG_ActionDescriptionList
						     arg,
						     CFG_ActionDescription
						     elem, int index);
CFG_ActionDescriptionList
CFG_makeActionDescriptionList2 (CFG_ActionDescription elem1,
				CFG_ActionDescription elem2);
CFG_ActionDescriptionList
CFG_makeActionDescriptionList3 (CFG_ActionDescription elem1,
				CFG_ActionDescription elem2,
				CFG_ActionDescription elem3);
CFG_ActionDescriptionList
CFG_makeActionDescriptionList4 (CFG_ActionDescription elem1,
				CFG_ActionDescription elem2,
				CFG_ActionDescription elem3,
				CFG_ActionDescription elem4);
CFG_ActionDescriptionList
CFG_makeActionDescriptionList5 (CFG_ActionDescription elem1,
				CFG_ActionDescription elem2,
				CFG_ActionDescription elem3,
				CFG_ActionDescription elem4,
				CFG_ActionDescription elem5);
CFG_ActionDescriptionList
CFG_makeActionDescriptionList6 (CFG_ActionDescription elem1,
				CFG_ActionDescription elem2,
				CFG_ActionDescription elem3,
				CFG_ActionDescription elem4,
				CFG_ActionDescription elem5,
				CFG_ActionDescription elem6);
int CFG_getTextAttributeMapLength (CFG_TextAttributeMap arg);
CFG_TextAttributeMap CFG_reverseTextAttributeMap (CFG_TextAttributeMap arg);
CFG_TextAttributeMap CFG_appendTextAttributeMap (CFG_TextAttributeMap arg,
						 CFG_TextAttribute elem);
CFG_TextAttributeMap CFG_concatTextAttributeMap (CFG_TextAttributeMap arg0,
						 CFG_TextAttributeMap arg1);
CFG_TextAttributeMap CFG_sliceTextAttributeMap (CFG_TextAttributeMap arg,
						int start, int end);
CFG_TextAttribute CFG_getTextAttributeMapTextAttributeAt (CFG_TextAttributeMap
							  arg, int index);
CFG_TextAttributeMap
CFG_replaceTextAttributeMapTextAttributeAt (CFG_TextAttributeMap arg,
					    CFG_TextAttribute elem,
					    int index);
CFG_TextAttributeMap CFG_makeTextAttributeMap2 (CFG_TextAttribute elem1,
						CFG_TextAttribute elem2);
CFG_TextAttributeMap CFG_makeTextAttributeMap3 (CFG_TextAttribute elem1,
						CFG_TextAttribute elem2,
						CFG_TextAttribute elem3);
CFG_TextAttributeMap CFG_makeTextAttributeMap4 (CFG_TextAttribute elem1,
						CFG_TextAttribute elem2,
						CFG_TextAttribute elem3,
						CFG_TextAttribute elem4);
CFG_TextAttributeMap CFG_makeTextAttributeMap5 (CFG_TextAttribute elem1,
						CFG_TextAttribute elem2,
						CFG_TextAttribute elem3,
						CFG_TextAttribute elem4,
						CFG_TextAttribute elem5);
CFG_TextAttributeMap CFG_makeTextAttributeMap6 (CFG_TextAttribute elem1,
						CFG_TextAttribute elem2,
						CFG_TextAttribute elem3,
						CFG_TextAttribute elem4,
						CFG_TextAttribute elem5,
						CFG_TextAttribute elem6);
int CFG_getItemListLength (CFG_ItemList arg);
CFG_ItemList CFG_reverseItemList (CFG_ItemList arg);
CFG_ItemList CFG_appendItemList (CFG_ItemList arg, CFG_Item elem);
CFG_ItemList CFG_concatItemList (CFG_ItemList arg0, CFG_ItemList arg1);
CFG_ItemList CFG_sliceItemList (CFG_ItemList arg, int start, int end);
CFG_Item CFG_getItemListItemAt (CFG_ItemList arg, int index);
CFG_ItemList CFG_replaceItemListItemAt (CFG_ItemList arg, CFG_Item elem,
					int index);
CFG_ItemList CFG_makeItemList2 (CFG_Item elem1, CFG_Item elem2);
CFG_ItemList CFG_makeItemList3 (CFG_Item elem1, CFG_Item elem2,
				CFG_Item elem3);
CFG_ItemList CFG_makeItemList4 (CFG_Item elem1, CFG_Item elem2,
				CFG_Item elem3, CFG_Item elem4);
CFG_ItemList CFG_makeItemList5 (CFG_Item elem1, CFG_Item elem2,
				CFG_Item elem3, CFG_Item elem4,
				CFG_Item elem5);
CFG_ItemList CFG_makeItemList6 (CFG_Item elem1, CFG_Item elem2,
				CFG_Item elem3, CFG_Item elem4,
				CFG_Item elem5, CFG_Item elem6);
int CFG_getKeyModifierListLength (CFG_KeyModifierList arg);
CFG_KeyModifierList CFG_reverseKeyModifierList (CFG_KeyModifierList arg);
CFG_KeyModifierList CFG_appendKeyModifierList (CFG_KeyModifierList arg,
					       CFG_KeyModifier elem);
CFG_KeyModifierList CFG_concatKeyModifierList (CFG_KeyModifierList arg0,
					       CFG_KeyModifierList arg1);
CFG_KeyModifierList CFG_sliceKeyModifierList (CFG_KeyModifierList arg,
					      int start, int end);
CFG_KeyModifier CFG_getKeyModifierListKeyModifierAt (CFG_KeyModifierList arg,
						     int index);
CFG_KeyModifierList
CFG_replaceKeyModifierListKeyModifierAt (CFG_KeyModifierList arg,
					 CFG_KeyModifier elem, int index);
CFG_KeyModifierList CFG_makeKeyModifierList2 (CFG_KeyModifier elem1,
					      CFG_KeyModifier elem2);
CFG_KeyModifierList CFG_makeKeyModifierList3 (CFG_KeyModifier elem1,
					      CFG_KeyModifier elem2,
					      CFG_KeyModifier elem3);
CFG_KeyModifierList CFG_makeKeyModifierList4 (CFG_KeyModifier elem1,
					      CFG_KeyModifier elem2,
					      CFG_KeyModifier elem3,
					      CFG_KeyModifier elem4);
CFG_KeyModifierList CFG_makeKeyModifierList5 (CFG_KeyModifier elem1,
					      CFG_KeyModifier elem2,
					      CFG_KeyModifier elem3,
					      CFG_KeyModifier elem4,
					      CFG_KeyModifier elem5);
CFG_KeyModifierList CFG_makeKeyModifierList6 (CFG_KeyModifier elem1,
					      CFG_KeyModifier elem2,
					      CFG_KeyModifier elem3,
					      CFG_KeyModifier elem4,
					      CFG_KeyModifier elem5,
					      CFG_KeyModifier elem6);
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
CFG_Property CFG_makePropertyAction (CFG_ActionDescriptionList list,
				     const char *action);
CFG_Property CFG_makePropertyExtension (const char *language,
					const char *extension);
CFG_Property CFG_makePropertyLibraryPath (const char *label,
					  const char *path);
CFG_Property CFG_makePropertyModulePath (const char *label, const char *path);
CFG_Property CFG_makePropertyTextCategory (CFG_TextCategoryName category,
					   CFG_TextAttributeMap map);
CFG_ActionDescription CFG_makeActionDescriptionDescription (ATerm context,
							    CFG_Event event);
CFG_Event CFG_makeEventClick (void);
CFG_Event CFG_makeEventIcon (const char *title, const char *path);
CFG_Event CFG_makeEventMenu (CFG_ItemList list);
CFG_Event CFG_makeEventMenuShortcut (CFG_ItemList list,
				     CFG_ShortCut shortcut);
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
CFG_ItemList CFG_makeItemListEmpty (void);
CFG_ItemList CFG_makeItemListSingle (CFG_Item head);
CFG_ItemList CFG_makeItemListMany (CFG_Item head, CFG_ItemList tail);
CFG_KeyModifierList CFG_makeKeyModifierListEmpty (void);
CFG_KeyModifierList CFG_makeKeyModifierListSingle (CFG_KeyModifier head);
CFG_KeyModifierList CFG_makeKeyModifierListMany (CFG_KeyModifier head,
						 CFG_KeyModifierList tail);
ATbool CFG_isEqualKeyModifier (CFG_KeyModifier arg0, CFG_KeyModifier arg1);
ATbool CFG_isEqualVirtualKey (CFG_VirtualKey arg0, CFG_VirtualKey arg1);
ATbool CFG_isEqualColor (CFG_Color arg0, CFG_Color arg1);
ATbool CFG_isEqualConfiguration (CFG_Configuration arg0,
				 CFG_Configuration arg1);
ATbool CFG_isEqualProperty (CFG_Property arg0, CFG_Property arg1);
ATbool CFG_isEqualActionDescription (CFG_ActionDescription arg0,
				     CFG_ActionDescription arg1);
ATbool CFG_isEqualEvent (CFG_Event arg0, CFG_Event arg1);
ATbool CFG_isEqualItem (CFG_Item arg0, CFG_Item arg1);
ATbool CFG_isEqualTextCategoryName (CFG_TextCategoryName arg0,
				    CFG_TextCategoryName arg1);
ATbool CFG_isEqualTextAttribute (CFG_TextAttribute arg0,
				 CFG_TextAttribute arg1);
ATbool CFG_isEqualShortCut (CFG_ShortCut arg0, CFG_ShortCut arg1);
ATbool CFG_isEqualTextStyle (CFG_TextStyle arg0, CFG_TextStyle arg1);
ATbool CFG_isEqualPropertyList (CFG_PropertyList arg0, CFG_PropertyList arg1);
ATbool CFG_isEqualActionDescriptionList (CFG_ActionDescriptionList arg0,
					 CFG_ActionDescriptionList arg1);
ATbool CFG_isEqualTextAttributeMap (CFG_TextAttributeMap arg0,
				    CFG_TextAttributeMap arg1);
ATbool CFG_isEqualItemList (CFG_ItemList arg0, CFG_ItemList arg1);
ATbool CFG_isEqualKeyModifierList (CFG_KeyModifierList arg0,
				   CFG_KeyModifierList arg1);
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
inline ATbool CFG_isPropertyAction (CFG_Property arg);
inline ATbool CFG_isPropertyExtension (CFG_Property arg);
inline ATbool CFG_isPropertyLibraryPath (CFG_Property arg);
inline ATbool CFG_isPropertyModulePath (CFG_Property arg);
inline ATbool CFG_isPropertyTextCategory (CFG_Property arg);
ATbool CFG_hasPropertyPath (CFG_Property arg);
ATbool CFG_hasPropertyList (CFG_Property arg);
ATbool CFG_hasPropertyAction (CFG_Property arg);
ATbool CFG_hasPropertyLanguage (CFG_Property arg);
ATbool CFG_hasPropertyExtension (CFG_Property arg);
ATbool CFG_hasPropertyLabel (CFG_Property arg);
ATbool CFG_hasPropertyCategory (CFG_Property arg);
ATbool CFG_hasPropertyMap (CFG_Property arg);
char *CFG_getPropertyPath (CFG_Property arg);
CFG_ActionDescriptionList CFG_getPropertyList (CFG_Property arg);
char *CFG_getPropertyAction (CFG_Property arg);
char *CFG_getPropertyLanguage (CFG_Property arg);
char *CFG_getPropertyExtension (CFG_Property arg);
char *CFG_getPropertyLabel (CFG_Property arg);
CFG_TextCategoryName CFG_getPropertyCategory (CFG_Property arg);
CFG_TextAttributeMap CFG_getPropertyMap (CFG_Property arg);
CFG_Property CFG_setPropertyPath (CFG_Property arg, const char *path);
CFG_Property CFG_setPropertyList (CFG_Property arg,
				  CFG_ActionDescriptionList list);
CFG_Property CFG_setPropertyAction (CFG_Property arg, const char *action);
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
inline ATbool CFG_isEventClick (CFG_Event arg);
inline ATbool CFG_isEventIcon (CFG_Event arg);
inline ATbool CFG_isEventMenu (CFG_Event arg);
inline ATbool CFG_isEventMenuShortcut (CFG_Event arg);
ATbool CFG_hasEventTitle (CFG_Event arg);
ATbool CFG_hasEventPath (CFG_Event arg);
ATbool CFG_hasEventList (CFG_Event arg);
ATbool CFG_hasEventShortcut (CFG_Event arg);
char *CFG_getEventTitle (CFG_Event arg);
char *CFG_getEventPath (CFG_Event arg);
CFG_ItemList CFG_getEventList (CFG_Event arg);
CFG_ShortCut CFG_getEventShortcut (CFG_Event arg);
CFG_Event CFG_setEventTitle (CFG_Event arg, const char *title);
CFG_Event CFG_setEventPath (CFG_Event arg, const char *path);
CFG_Event CFG_setEventList (CFG_Event arg, CFG_ItemList list);
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
ATbool CFG_isValidItemList (CFG_ItemList arg);
inline ATbool CFG_isItemListEmpty (CFG_ItemList arg);
inline ATbool CFG_isItemListSingle (CFG_ItemList arg);
inline ATbool CFG_isItemListMany (CFG_ItemList arg);
ATbool CFG_hasItemListHead (CFG_ItemList arg);
ATbool CFG_hasItemListTail (CFG_ItemList arg);
CFG_Item CFG_getItemListHead (CFG_ItemList arg);
CFG_ItemList CFG_getItemListTail (CFG_ItemList arg);
CFG_ItemList CFG_setItemListHead (CFG_ItemList arg, CFG_Item head);
CFG_ItemList CFG_setItemListTail (CFG_ItemList arg, CFG_ItemList tail);
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
CFG_Event CFG_visitEvent (CFG_Event arg, char *(*acceptTitle) (char *),
			  char *(*acceptPath) (char *),
			  CFG_ItemList (*acceptList) (CFG_ItemList),
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
CFG_ItemList CFG_visitItemList (CFG_ItemList arg,
				CFG_Item (*acceptHead) (CFG_Item));
CFG_KeyModifierList CFG_visitKeyModifierList (CFG_KeyModifierList arg,
					      CFG_KeyModifier (*acceptHead)
					      (CFG_KeyModifier));

#endif /* _CONFIG_H */
