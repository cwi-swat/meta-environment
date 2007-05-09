#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Config.h"

/**
 * Converts a string to an ATermList of integers (ASCII values). 
 * \param[in] str An ASCII string
 * \return An ATermList containing the ASCII values of #arg as ATermInts
 */
ATerm CFG_stringToChars(const char *str) {
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

/**
 * Converts an ASCII char to an ATermInt. 
 * \param[in] ch an ASCII character
 * \return An ATerm representing the ASCII value of #arg
 */
ATerm CFG_byteToChar(char ch) {
    return (ATerm) ATmakeInt(ch);
}

/**
 * Converts a list of integers (ASCII values) to a C string. 
 * \param[in] arg An ATermList with ATermInts, such as [32,32,10]
 * \return String containing the characters from #arg as characters
 */
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


typedef struct ATerm _CFG_VirtualButton;
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
typedef struct ATerm _CFG_KeyModifierList;
typedef struct ATerm _CFG_ItemLabels;


/**
 * Initializes the full API. Forgetting to call this function before using the API will lead to strange behaviour. ATinit() needs to be called before this function.
 */
void _CFG_initConfigApi(void) {
  init_Config_dict();

}

/**
 * Protect a CFG_VirtualButton from the ATerm garbage collector. Every CFG_VirtualButton that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_VirtualButton
 */
void _CFG_protectVirtualButton(CFG_VirtualButton *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_VirtualButton from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_VirtualButton
 */
void _CFG_unprotectVirtualButton(CFG_VirtualButton *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_KeyModifier from the ATerm garbage collector. Every CFG_KeyModifier that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_KeyModifier
 */
void _CFG_protectKeyModifier(CFG_KeyModifier *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_KeyModifier from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_KeyModifier
 */
void _CFG_unprotectKeyModifier(CFG_KeyModifier *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_VirtualKey from the ATerm garbage collector. Every CFG_VirtualKey that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_VirtualKey
 */
void _CFG_protectVirtualKey(CFG_VirtualKey *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_VirtualKey from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_VirtualKey
 */
void _CFG_unprotectVirtualKey(CFG_VirtualKey *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_Color from the ATerm garbage collector. Every CFG_Color that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_Color
 */
void _CFG_protectColor(CFG_Color *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_Color from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_Color
 */
void _CFG_unprotectColor(CFG_Color *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_Configuration from the ATerm garbage collector. Every CFG_Configuration that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_Configuration
 */
void _CFG_protectConfiguration(CFG_Configuration *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_Configuration from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_Configuration
 */
void _CFG_unprotectConfiguration(CFG_Configuration *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_Property from the ATerm garbage collector. Every CFG_Property that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_Property
 */
void _CFG_protectProperty(CFG_Property *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_Property from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_Property
 */
void _CFG_unprotectProperty(CFG_Property *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_ActionDescription from the ATerm garbage collector. Every CFG_ActionDescription that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_ActionDescription
 */
void _CFG_protectActionDescription(CFG_ActionDescription *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_ActionDescription from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_ActionDescription
 */
void _CFG_unprotectActionDescription(CFG_ActionDescription *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_Event from the ATerm garbage collector. Every CFG_Event that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_Event
 */
void _CFG_protectEvent(CFG_Event *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_Event from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_Event
 */
void _CFG_unprotectEvent(CFG_Event *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_Item from the ATerm garbage collector. Every CFG_Item that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_Item
 */
void _CFG_protectItem(CFG_Item *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_Item from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_Item
 */
void _CFG_unprotectItem(CFG_Item *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_TextCategoryName from the ATerm garbage collector. Every CFG_TextCategoryName that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_TextCategoryName
 */
void _CFG_protectTextCategoryName(CFG_TextCategoryName *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_TextCategoryName from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_TextCategoryName
 */
void _CFG_unprotectTextCategoryName(CFG_TextCategoryName *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_TextAttribute from the ATerm garbage collector. Every CFG_TextAttribute that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_TextAttribute
 */
void _CFG_protectTextAttribute(CFG_TextAttribute *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_TextAttribute from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_TextAttribute
 */
void _CFG_unprotectTextAttribute(CFG_TextAttribute *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_ShortCut from the ATerm garbage collector. Every CFG_ShortCut that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_ShortCut
 */
void _CFG_protectShortCut(CFG_ShortCut *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_ShortCut from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_ShortCut
 */
void _CFG_unprotectShortCut(CFG_ShortCut *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_TextStyle from the ATerm garbage collector. Every CFG_TextStyle that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_TextStyle
 */
void _CFG_protectTextStyle(CFG_TextStyle *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_TextStyle from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_TextStyle
 */
void _CFG_unprotectTextStyle(CFG_TextStyle *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_PropertyList from the ATerm garbage collector. Every CFG_PropertyList that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_PropertyList
 */
void _CFG_protectPropertyList(CFG_PropertyList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_PropertyList from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_PropertyList
 */
void _CFG_unprotectPropertyList(CFG_PropertyList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_ActionDescriptionList from the ATerm garbage collector. Every CFG_ActionDescriptionList that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_ActionDescriptionList
 */
void _CFG_protectActionDescriptionList(CFG_ActionDescriptionList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_ActionDescriptionList from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_ActionDescriptionList
 */
void _CFG_unprotectActionDescriptionList(CFG_ActionDescriptionList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_TextAttributeMap from the ATerm garbage collector. Every CFG_TextAttributeMap that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_TextAttributeMap
 */
void _CFG_protectTextAttributeMap(CFG_TextAttributeMap *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_TextAttributeMap from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_TextAttributeMap
 */
void _CFG_unprotectTextAttributeMap(CFG_TextAttributeMap *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_KeyModifierList from the ATerm garbage collector. Every CFG_KeyModifierList that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_KeyModifierList
 */
void _CFG_protectKeyModifierList(CFG_KeyModifierList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_KeyModifierList from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_KeyModifierList
 */
void _CFG_unprotectKeyModifierList(CFG_KeyModifierList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CFG_ItemLabels from the ATerm garbage collector. Every CFG_ItemLabels that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CFG_ItemLabels
 */
void _CFG_protectItemLabels(CFG_ItemLabels *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CFG_ItemLabels from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CFG_ItemLabels
 */
void _CFG_unprotectItemLabels(CFG_ItemLabels *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Transforms an ATerm to a CFG_VirtualButton. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_VirtualButton that was encoded by \arg
 */
CFG_VirtualButton _CFG_VirtualButtonFromTerm(ATerm t) {
  return (CFG_VirtualButton)t;
}

/**
 * Transforms a CFG_VirtualButtonto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_VirtualButton to be converted
 * \return ATerm that represents the CFG_VirtualButton
 */
ATerm _CFG_VirtualButtonToTerm(CFG_VirtualButton arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_KeyModifier. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_KeyModifier that was encoded by \arg
 */
CFG_KeyModifier _CFG_KeyModifierFromTerm(ATerm t) {
  return (CFG_KeyModifier)t;
}

/**
 * Transforms a CFG_KeyModifierto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_KeyModifier to be converted
 * \return ATerm that represents the CFG_KeyModifier
 */
ATerm _CFG_KeyModifierToTerm(CFG_KeyModifier arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_VirtualKey. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_VirtualKey that was encoded by \arg
 */
CFG_VirtualKey _CFG_VirtualKeyFromTerm(ATerm t) {
  return (CFG_VirtualKey)t;
}

/**
 * Transforms a CFG_VirtualKeyto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_VirtualKey to be converted
 * \return ATerm that represents the CFG_VirtualKey
 */
ATerm _CFG_VirtualKeyToTerm(CFG_VirtualKey arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_Color. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_Color that was encoded by \arg
 */
CFG_Color _CFG_ColorFromTerm(ATerm t) {
  return (CFG_Color)t;
}

/**
 * Transforms a CFG_Colorto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_Color to be converted
 * \return ATerm that represents the CFG_Color
 */
ATerm _CFG_ColorToTerm(CFG_Color arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_Configuration. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_Configuration that was encoded by \arg
 */
CFG_Configuration _CFG_ConfigurationFromTerm(ATerm t) {
  return (CFG_Configuration)t;
}

/**
 * Transforms a CFG_Configurationto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_Configuration to be converted
 * \return ATerm that represents the CFG_Configuration
 */
ATerm _CFG_ConfigurationToTerm(CFG_Configuration arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_Property. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_Property that was encoded by \arg
 */
CFG_Property _CFG_PropertyFromTerm(ATerm t) {
  return (CFG_Property)t;
}

/**
 * Transforms a CFG_Propertyto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_Property to be converted
 * \return ATerm that represents the CFG_Property
 */
ATerm _CFG_PropertyToTerm(CFG_Property arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_ActionDescription. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_ActionDescription that was encoded by \arg
 */
CFG_ActionDescription _CFG_ActionDescriptionFromTerm(ATerm t) {
  return (CFG_ActionDescription)t;
}

/**
 * Transforms a CFG_ActionDescriptionto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_ActionDescription to be converted
 * \return ATerm that represents the CFG_ActionDescription
 */
ATerm _CFG_ActionDescriptionToTerm(CFG_ActionDescription arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_Event. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_Event that was encoded by \arg
 */
CFG_Event _CFG_EventFromTerm(ATerm t) {
  return (CFG_Event)t;
}

/**
 * Transforms a CFG_Eventto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_Event to be converted
 * \return ATerm that represents the CFG_Event
 */
ATerm _CFG_EventToTerm(CFG_Event arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_Item. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_Item that was encoded by \arg
 */
CFG_Item _CFG_ItemFromTerm(ATerm t) {
  return (CFG_Item)t;
}

/**
 * Transforms a CFG_Itemto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_Item to be converted
 * \return ATerm that represents the CFG_Item
 */
ATerm _CFG_ItemToTerm(CFG_Item arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_TextCategoryName. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_TextCategoryName that was encoded by \arg
 */
CFG_TextCategoryName _CFG_TextCategoryNameFromTerm(ATerm t) {
  return (CFG_TextCategoryName)t;
}

/**
 * Transforms a CFG_TextCategoryNameto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_TextCategoryName to be converted
 * \return ATerm that represents the CFG_TextCategoryName
 */
ATerm _CFG_TextCategoryNameToTerm(CFG_TextCategoryName arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_TextAttribute. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_TextAttribute that was encoded by \arg
 */
CFG_TextAttribute _CFG_TextAttributeFromTerm(ATerm t) {
  return (CFG_TextAttribute)t;
}

/**
 * Transforms a CFG_TextAttributeto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_TextAttribute to be converted
 * \return ATerm that represents the CFG_TextAttribute
 */
ATerm _CFG_TextAttributeToTerm(CFG_TextAttribute arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_ShortCut. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_ShortCut that was encoded by \arg
 */
CFG_ShortCut _CFG_ShortCutFromTerm(ATerm t) {
  return (CFG_ShortCut)t;
}

/**
 * Transforms a CFG_ShortCutto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_ShortCut to be converted
 * \return ATerm that represents the CFG_ShortCut
 */
ATerm _CFG_ShortCutToTerm(CFG_ShortCut arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_TextStyle. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_TextStyle that was encoded by \arg
 */
CFG_TextStyle _CFG_TextStyleFromTerm(ATerm t) {
  return (CFG_TextStyle)t;
}

/**
 * Transforms a CFG_TextStyleto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_TextStyle to be converted
 * \return ATerm that represents the CFG_TextStyle
 */
ATerm _CFG_TextStyleToTerm(CFG_TextStyle arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_PropertyList. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_PropertyList that was encoded by \arg
 */
CFG_PropertyList _CFG_PropertyListFromTerm(ATerm t) {
  return (CFG_PropertyList)t;
}

/**
 * Transforms a CFG_PropertyListto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_PropertyList to be converted
 * \return ATerm that represents the CFG_PropertyList
 */
ATerm _CFG_PropertyListToTerm(CFG_PropertyList arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_ActionDescriptionList. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_ActionDescriptionList that was encoded by \arg
 */
CFG_ActionDescriptionList _CFG_ActionDescriptionListFromTerm(ATerm t) {
  return (CFG_ActionDescriptionList)t;
}

/**
 * Transforms a CFG_ActionDescriptionListto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_ActionDescriptionList to be converted
 * \return ATerm that represents the CFG_ActionDescriptionList
 */
ATerm _CFG_ActionDescriptionListToTerm(CFG_ActionDescriptionList arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_TextAttributeMap. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_TextAttributeMap that was encoded by \arg
 */
CFG_TextAttributeMap _CFG_TextAttributeMapFromTerm(ATerm t) {
  return (CFG_TextAttributeMap)t;
}

/**
 * Transforms a CFG_TextAttributeMapto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_TextAttributeMap to be converted
 * \return ATerm that represents the CFG_TextAttributeMap
 */
ATerm _CFG_TextAttributeMapToTerm(CFG_TextAttributeMap arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_KeyModifierList. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_KeyModifierList that was encoded by \arg
 */
CFG_KeyModifierList _CFG_KeyModifierListFromTerm(ATerm t) {
  return (CFG_KeyModifierList)t;
}

/**
 * Transforms a CFG_KeyModifierListto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_KeyModifierList to be converted
 * \return ATerm that represents the CFG_KeyModifierList
 */
ATerm _CFG_KeyModifierListToTerm(CFG_KeyModifierList arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CFG_ItemLabels. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CFG_ItemLabels that was encoded by \arg
 */
CFG_ItemLabels _CFG_ItemLabelsFromTerm(ATerm t) {
  return (CFG_ItemLabels)t;
}

/**
 * Transforms a CFG_ItemLabelsto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CFG_ItemLabels to be converted
 * \return ATerm that represents the CFG_ItemLabels
 */
ATerm _CFG_ItemLabelsToTerm(CFG_ItemLabels arg) {
  return (ATerm)arg;
}

/**
 * Retrieve the length of a CFG_PropertyList. 
 * \param[in] arg input CFG_PropertyList
 * \return The number of elements in the CFG_PropertyList
 */
int _CFG_getPropertyListLength(CFG_PropertyList arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a CFG_PropertyList. 
 * \param[in] arg CFG_PropertyList to be reversed
 * \return a reversed #arg
 */
CFG_PropertyList _CFG_reversePropertyList(CFG_PropertyList arg) {
  return (CFG_PropertyList) ATreverse((ATermList) arg);
}

/**
 * Append a CFG_Property to the end of a CFG_PropertyList. 
 * \param[in] arg CFG_PropertyList to append the CFG_Property to
 * \param[in] elem CFG_Property to be appended
 * \return new CFG_PropertyList with #elem appended
 */
CFG_PropertyList _CFG_appendPropertyList(CFG_PropertyList arg, CFG_Property elem) {
  return (CFG_PropertyList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two CFG_PropertyLists. 
 * \param[in] arg0 first CFG_PropertyList
 * \param[in] arg1 second CFG_PropertyList
 * \return CFG_PropertyList with the elements of #arg0 before the elements of #arg1
 */
CFG_PropertyList _CFG_concatPropertyList(CFG_PropertyList arg0, CFG_PropertyList arg1) {
  return (CFG_PropertyList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a CFG_PropertyList. 
 * \param[in] arg CFG_PropertyList to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new CFG_PropertyList with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
CFG_PropertyList _CFG_slicePropertyList(CFG_PropertyList arg, int start, int end) {
  return (CFG_PropertyList) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the CFG_Property at #index from a CFG_PropertyList. 
 * \param[in] arg CFG_PropertyList to retrieve the CFG_Property from
 * \param[in] index index to use to point in the CFG_PropertyList
 * \return CFG_Property at position #index in #arg
 */
CFG_Property _CFG_getPropertyListPropertyAt(CFG_PropertyList arg, int index) {
 return (CFG_Property)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the CFG_Property at #index from a CFG_PropertyList by a new one. 
 * \param[in] arg CFG_PropertyList to retrieve the CFG_Property from
 * \param[in] elem new CFG_Property to replace another
 * \param[in] index index to use to point in the CFG_PropertyList
 * \return A new CFG_PropertyListwith #elem replaced in #arg at position #index
 */
CFG_PropertyList _CFG_replacePropertyListPropertyAt(CFG_PropertyList arg, CFG_Property elem, int index) {
 return (CFG_PropertyList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a CFG_PropertyList of 2 consecutive elements. 
 * \param[in] elem1 One CFG_Property element of the new CFG_PropertyList
 * \param[in] elem2 One CFG_Property element of the new CFG_PropertyList
 * \return A new CFG_PropertyList consisting of 2 CFG_Propertys
 */
CFG_PropertyList _CFG_makePropertyList2(CFG_Property elem1, CFG_Property elem2) {
  return (CFG_PropertyList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a CFG_PropertyList of 3 consecutive elements. 
 * \param[in] elem1 One CFG_Property element of the new CFG_PropertyList
 * \param[in] elem2 One CFG_Property element of the new CFG_PropertyList
 * \param[in] elem3 One CFG_Property element of the new CFG_PropertyList
 * \return A new CFG_PropertyList consisting of 3 CFG_Propertys
 */
CFG_PropertyList _CFG_makePropertyList3(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3) {
  return (CFG_PropertyList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a CFG_PropertyList of 4 consecutive elements. 
 * \param[in] elem1 One CFG_Property element of the new CFG_PropertyList
 * \param[in] elem2 One CFG_Property element of the new CFG_PropertyList
 * \param[in] elem3 One CFG_Property element of the new CFG_PropertyList
 * \param[in] elem4 One CFG_Property element of the new CFG_PropertyList
 * \return A new CFG_PropertyList consisting of 4 CFG_Propertys
 */
CFG_PropertyList _CFG_makePropertyList4(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3, CFG_Property elem4) {
  return (CFG_PropertyList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a CFG_PropertyList of 5 consecutive elements. 
 * \param[in] elem1 One CFG_Property element of the new CFG_PropertyList
 * \param[in] elem2 One CFG_Property element of the new CFG_PropertyList
 * \param[in] elem3 One CFG_Property element of the new CFG_PropertyList
 * \param[in] elem4 One CFG_Property element of the new CFG_PropertyList
 * \param[in] elem5 One CFG_Property element of the new CFG_PropertyList
 * \return A new CFG_PropertyList consisting of 5 CFG_Propertys
 */
CFG_PropertyList _CFG_makePropertyList5(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3, CFG_Property elem4, CFG_Property elem5) {
  return (CFG_PropertyList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a CFG_PropertyList of 6 consecutive elements. 
 * \param[in] elem1 One CFG_Property element of the new CFG_PropertyList
 * \param[in] elem2 One CFG_Property element of the new CFG_PropertyList
 * \param[in] elem3 One CFG_Property element of the new CFG_PropertyList
 * \param[in] elem4 One CFG_Property element of the new CFG_PropertyList
 * \param[in] elem5 One CFG_Property element of the new CFG_PropertyList
 * \param[in] elem6 One CFG_Property element of the new CFG_PropertyList
 * \return A new CFG_PropertyList consisting of 6 CFG_Propertys
 */
CFG_PropertyList _CFG_makePropertyList6(CFG_Property elem1, CFG_Property elem2, CFG_Property elem3, CFG_Property elem4, CFG_Property elem5, CFG_Property elem6) {
  return (CFG_PropertyList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a CFG_ActionDescriptionList. 
 * \param[in] arg input CFG_ActionDescriptionList
 * \return The number of elements in the CFG_ActionDescriptionList
 */
int _CFG_getActionDescriptionListLength(CFG_ActionDescriptionList arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a CFG_ActionDescriptionList. 
 * \param[in] arg CFG_ActionDescriptionList to be reversed
 * \return a reversed #arg
 */
CFG_ActionDescriptionList _CFG_reverseActionDescriptionList(CFG_ActionDescriptionList arg) {
  return (CFG_ActionDescriptionList) ATreverse((ATermList) arg);
}

/**
 * Append a CFG_ActionDescription to the end of a CFG_ActionDescriptionList. 
 * \param[in] arg CFG_ActionDescriptionList to append the CFG_ActionDescription to
 * \param[in] elem CFG_ActionDescription to be appended
 * \return new CFG_ActionDescriptionList with #elem appended
 */
CFG_ActionDescriptionList _CFG_appendActionDescriptionList(CFG_ActionDescriptionList arg, CFG_ActionDescription elem) {
  return (CFG_ActionDescriptionList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two CFG_ActionDescriptionLists. 
 * \param[in] arg0 first CFG_ActionDescriptionList
 * \param[in] arg1 second CFG_ActionDescriptionList
 * \return CFG_ActionDescriptionList with the elements of #arg0 before the elements of #arg1
 */
CFG_ActionDescriptionList _CFG_concatActionDescriptionList(CFG_ActionDescriptionList arg0, CFG_ActionDescriptionList arg1) {
  return (CFG_ActionDescriptionList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a CFG_ActionDescriptionList. 
 * \param[in] arg CFG_ActionDescriptionList to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new CFG_ActionDescriptionList with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
CFG_ActionDescriptionList _CFG_sliceActionDescriptionList(CFG_ActionDescriptionList arg, int start, int end) {
  return (CFG_ActionDescriptionList) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the CFG_ActionDescription at #index from a CFG_ActionDescriptionList. 
 * \param[in] arg CFG_ActionDescriptionList to retrieve the CFG_ActionDescription from
 * \param[in] index index to use to point in the CFG_ActionDescriptionList
 * \return CFG_ActionDescription at position #index in #arg
 */
CFG_ActionDescription _CFG_getActionDescriptionListActionDescriptionAt(CFG_ActionDescriptionList arg, int index) {
 return (CFG_ActionDescription)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the CFG_ActionDescription at #index from a CFG_ActionDescriptionList by a new one. 
 * \param[in] arg CFG_ActionDescriptionList to retrieve the CFG_ActionDescription from
 * \param[in] elem new CFG_ActionDescription to replace another
 * \param[in] index index to use to point in the CFG_ActionDescriptionList
 * \return A new CFG_ActionDescriptionListwith #elem replaced in #arg at position #index
 */
CFG_ActionDescriptionList _CFG_replaceActionDescriptionListActionDescriptionAt(CFG_ActionDescriptionList arg, CFG_ActionDescription elem, int index) {
 return (CFG_ActionDescriptionList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a CFG_ActionDescriptionList of 2 consecutive elements. 
 * \param[in] elem1 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \param[in] elem2 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \return A new CFG_ActionDescriptionList consisting of 2 CFG_ActionDescriptions
 */
CFG_ActionDescriptionList _CFG_makeActionDescriptionList2(CFG_ActionDescription elem1, CFG_ActionDescription elem2) {
  return (CFG_ActionDescriptionList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a CFG_ActionDescriptionList of 3 consecutive elements. 
 * \param[in] elem1 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \param[in] elem2 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \param[in] elem3 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \return A new CFG_ActionDescriptionList consisting of 3 CFG_ActionDescriptions
 */
CFG_ActionDescriptionList _CFG_makeActionDescriptionList3(CFG_ActionDescription elem1, CFG_ActionDescription elem2, CFG_ActionDescription elem3) {
  return (CFG_ActionDescriptionList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a CFG_ActionDescriptionList of 4 consecutive elements. 
 * \param[in] elem1 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \param[in] elem2 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \param[in] elem3 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \param[in] elem4 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \return A new CFG_ActionDescriptionList consisting of 4 CFG_ActionDescriptions
 */
CFG_ActionDescriptionList _CFG_makeActionDescriptionList4(CFG_ActionDescription elem1, CFG_ActionDescription elem2, CFG_ActionDescription elem3, CFG_ActionDescription elem4) {
  return (CFG_ActionDescriptionList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a CFG_ActionDescriptionList of 5 consecutive elements. 
 * \param[in] elem1 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \param[in] elem2 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \param[in] elem3 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \param[in] elem4 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \param[in] elem5 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \return A new CFG_ActionDescriptionList consisting of 5 CFG_ActionDescriptions
 */
CFG_ActionDescriptionList _CFG_makeActionDescriptionList5(CFG_ActionDescription elem1, CFG_ActionDescription elem2, CFG_ActionDescription elem3, CFG_ActionDescription elem4, CFG_ActionDescription elem5) {
  return (CFG_ActionDescriptionList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a CFG_ActionDescriptionList of 6 consecutive elements. 
 * \param[in] elem1 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \param[in] elem2 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \param[in] elem3 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \param[in] elem4 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \param[in] elem5 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \param[in] elem6 One CFG_ActionDescription element of the new CFG_ActionDescriptionList
 * \return A new CFG_ActionDescriptionList consisting of 6 CFG_ActionDescriptions
 */
CFG_ActionDescriptionList _CFG_makeActionDescriptionList6(CFG_ActionDescription elem1, CFG_ActionDescription elem2, CFG_ActionDescription elem3, CFG_ActionDescription elem4, CFG_ActionDescription elem5, CFG_ActionDescription elem6) {
  return (CFG_ActionDescriptionList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a CFG_TextAttributeMap. 
 * \param[in] arg input CFG_TextAttributeMap
 * \return The number of elements in the CFG_TextAttributeMap
 */
int _CFG_getTextAttributeMapLength(CFG_TextAttributeMap arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a CFG_TextAttributeMap. 
 * \param[in] arg CFG_TextAttributeMap to be reversed
 * \return a reversed #arg
 */
CFG_TextAttributeMap _CFG_reverseTextAttributeMap(CFG_TextAttributeMap arg) {
  return (CFG_TextAttributeMap) ATreverse((ATermList) arg);
}

/**
 * Append a CFG_TextAttribute to the end of a CFG_TextAttributeMap. 
 * \param[in] arg CFG_TextAttributeMap to append the CFG_TextAttribute to
 * \param[in] elem CFG_TextAttribute to be appended
 * \return new CFG_TextAttributeMap with #elem appended
 */
CFG_TextAttributeMap _CFG_appendTextAttributeMap(CFG_TextAttributeMap arg, CFG_TextAttribute elem) {
  return (CFG_TextAttributeMap) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two CFG_TextAttributeMaps. 
 * \param[in] arg0 first CFG_TextAttributeMap
 * \param[in] arg1 second CFG_TextAttributeMap
 * \return CFG_TextAttributeMap with the elements of #arg0 before the elements of #arg1
 */
CFG_TextAttributeMap _CFG_concatTextAttributeMap(CFG_TextAttributeMap arg0, CFG_TextAttributeMap arg1) {
  return (CFG_TextAttributeMap) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a CFG_TextAttributeMap. 
 * \param[in] arg CFG_TextAttributeMap to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new CFG_TextAttributeMap with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
CFG_TextAttributeMap _CFG_sliceTextAttributeMap(CFG_TextAttributeMap arg, int start, int end) {
  return (CFG_TextAttributeMap) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the CFG_TextAttribute at #index from a CFG_TextAttributeMap. 
 * \param[in] arg CFG_TextAttributeMap to retrieve the CFG_TextAttribute from
 * \param[in] index index to use to point in the CFG_TextAttributeMap
 * \return CFG_TextAttribute at position #index in #arg
 */
CFG_TextAttribute _CFG_getTextAttributeMapTextAttributeAt(CFG_TextAttributeMap arg, int index) {
 return (CFG_TextAttribute)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the CFG_TextAttribute at #index from a CFG_TextAttributeMap by a new one. 
 * \param[in] arg CFG_TextAttributeMap to retrieve the CFG_TextAttribute from
 * \param[in] elem new CFG_TextAttribute to replace another
 * \param[in] index index to use to point in the CFG_TextAttributeMap
 * \return A new CFG_TextAttributeMapwith #elem replaced in #arg at position #index
 */
CFG_TextAttributeMap _CFG_replaceTextAttributeMapTextAttributeAt(CFG_TextAttributeMap arg, CFG_TextAttribute elem, int index) {
 return (CFG_TextAttributeMap) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a CFG_TextAttributeMap of 2 consecutive elements. 
 * \param[in] elem1 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \param[in] elem2 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \return A new CFG_TextAttributeMap consisting of 2 CFG_TextAttributes
 */
CFG_TextAttributeMap _CFG_makeTextAttributeMap2(CFG_TextAttribute elem1, CFG_TextAttribute elem2) {
  return (CFG_TextAttributeMap) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a CFG_TextAttributeMap of 3 consecutive elements. 
 * \param[in] elem1 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \param[in] elem2 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \param[in] elem3 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \return A new CFG_TextAttributeMap consisting of 3 CFG_TextAttributes
 */
CFG_TextAttributeMap _CFG_makeTextAttributeMap3(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3) {
  return (CFG_TextAttributeMap) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a CFG_TextAttributeMap of 4 consecutive elements. 
 * \param[in] elem1 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \param[in] elem2 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \param[in] elem3 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \param[in] elem4 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \return A new CFG_TextAttributeMap consisting of 4 CFG_TextAttributes
 */
CFG_TextAttributeMap _CFG_makeTextAttributeMap4(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3, CFG_TextAttribute elem4) {
  return (CFG_TextAttributeMap) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a CFG_TextAttributeMap of 5 consecutive elements. 
 * \param[in] elem1 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \param[in] elem2 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \param[in] elem3 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \param[in] elem4 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \param[in] elem5 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \return A new CFG_TextAttributeMap consisting of 5 CFG_TextAttributes
 */
CFG_TextAttributeMap _CFG_makeTextAttributeMap5(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3, CFG_TextAttribute elem4, CFG_TextAttribute elem5) {
  return (CFG_TextAttributeMap) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a CFG_TextAttributeMap of 6 consecutive elements. 
 * \param[in] elem1 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \param[in] elem2 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \param[in] elem3 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \param[in] elem4 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \param[in] elem5 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \param[in] elem6 One CFG_TextAttribute element of the new CFG_TextAttributeMap
 * \return A new CFG_TextAttributeMap consisting of 6 CFG_TextAttributes
 */
CFG_TextAttributeMap _CFG_makeTextAttributeMap6(CFG_TextAttribute elem1, CFG_TextAttribute elem2, CFG_TextAttribute elem3, CFG_TextAttribute elem4, CFG_TextAttribute elem5, CFG_TextAttribute elem6) {
  return (CFG_TextAttributeMap) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a CFG_KeyModifierList. 
 * \param[in] arg input CFG_KeyModifierList
 * \return The number of elements in the CFG_KeyModifierList
 */
int _CFG_getKeyModifierListLength(CFG_KeyModifierList arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a CFG_KeyModifierList. 
 * \param[in] arg CFG_KeyModifierList to be reversed
 * \return a reversed #arg
 */
CFG_KeyModifierList _CFG_reverseKeyModifierList(CFG_KeyModifierList arg) {
  return (CFG_KeyModifierList) ATreverse((ATermList) arg);
}

/**
 * Append a CFG_KeyModifier to the end of a CFG_KeyModifierList. 
 * \param[in] arg CFG_KeyModifierList to append the CFG_KeyModifier to
 * \param[in] elem CFG_KeyModifier to be appended
 * \return new CFG_KeyModifierList with #elem appended
 */
CFG_KeyModifierList _CFG_appendKeyModifierList(CFG_KeyModifierList arg, CFG_KeyModifier elem) {
  return (CFG_KeyModifierList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two CFG_KeyModifierLists. 
 * \param[in] arg0 first CFG_KeyModifierList
 * \param[in] arg1 second CFG_KeyModifierList
 * \return CFG_KeyModifierList with the elements of #arg0 before the elements of #arg1
 */
CFG_KeyModifierList _CFG_concatKeyModifierList(CFG_KeyModifierList arg0, CFG_KeyModifierList arg1) {
  return (CFG_KeyModifierList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a CFG_KeyModifierList. 
 * \param[in] arg CFG_KeyModifierList to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new CFG_KeyModifierList with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
CFG_KeyModifierList _CFG_sliceKeyModifierList(CFG_KeyModifierList arg, int start, int end) {
  return (CFG_KeyModifierList) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the CFG_KeyModifier at #index from a CFG_KeyModifierList. 
 * \param[in] arg CFG_KeyModifierList to retrieve the CFG_KeyModifier from
 * \param[in] index index to use to point in the CFG_KeyModifierList
 * \return CFG_KeyModifier at position #index in #arg
 */
CFG_KeyModifier _CFG_getKeyModifierListKeyModifierAt(CFG_KeyModifierList arg, int index) {
 return (CFG_KeyModifier)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the CFG_KeyModifier at #index from a CFG_KeyModifierList by a new one. 
 * \param[in] arg CFG_KeyModifierList to retrieve the CFG_KeyModifier from
 * \param[in] elem new CFG_KeyModifier to replace another
 * \param[in] index index to use to point in the CFG_KeyModifierList
 * \return A new CFG_KeyModifierListwith #elem replaced in #arg at position #index
 */
CFG_KeyModifierList _CFG_replaceKeyModifierListKeyModifierAt(CFG_KeyModifierList arg, CFG_KeyModifier elem, int index) {
 return (CFG_KeyModifierList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a CFG_KeyModifierList of 2 consecutive elements. 
 * \param[in] elem1 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \param[in] elem2 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \return A new CFG_KeyModifierList consisting of 2 CFG_KeyModifiers
 */
CFG_KeyModifierList _CFG_makeKeyModifierList2(CFG_KeyModifier elem1, CFG_KeyModifier elem2) {
  return (CFG_KeyModifierList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a CFG_KeyModifierList of 3 consecutive elements. 
 * \param[in] elem1 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \param[in] elem2 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \param[in] elem3 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \return A new CFG_KeyModifierList consisting of 3 CFG_KeyModifiers
 */
CFG_KeyModifierList _CFG_makeKeyModifierList3(CFG_KeyModifier elem1, CFG_KeyModifier elem2, CFG_KeyModifier elem3) {
  return (CFG_KeyModifierList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a CFG_KeyModifierList of 4 consecutive elements. 
 * \param[in] elem1 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \param[in] elem2 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \param[in] elem3 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \param[in] elem4 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \return A new CFG_KeyModifierList consisting of 4 CFG_KeyModifiers
 */
CFG_KeyModifierList _CFG_makeKeyModifierList4(CFG_KeyModifier elem1, CFG_KeyModifier elem2, CFG_KeyModifier elem3, CFG_KeyModifier elem4) {
  return (CFG_KeyModifierList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a CFG_KeyModifierList of 5 consecutive elements. 
 * \param[in] elem1 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \param[in] elem2 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \param[in] elem3 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \param[in] elem4 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \param[in] elem5 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \return A new CFG_KeyModifierList consisting of 5 CFG_KeyModifiers
 */
CFG_KeyModifierList _CFG_makeKeyModifierList5(CFG_KeyModifier elem1, CFG_KeyModifier elem2, CFG_KeyModifier elem3, CFG_KeyModifier elem4, CFG_KeyModifier elem5) {
  return (CFG_KeyModifierList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a CFG_KeyModifierList of 6 consecutive elements. 
 * \param[in] elem1 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \param[in] elem2 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \param[in] elem3 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \param[in] elem4 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \param[in] elem5 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \param[in] elem6 One CFG_KeyModifier element of the new CFG_KeyModifierList
 * \return A new CFG_KeyModifierList consisting of 6 CFG_KeyModifiers
 */
CFG_KeyModifierList _CFG_makeKeyModifierList6(CFG_KeyModifier elem1, CFG_KeyModifier elem2, CFG_KeyModifier elem3, CFG_KeyModifier elem4, CFG_KeyModifier elem5, CFG_KeyModifier elem6) {
  return (CFG_KeyModifierList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a CFG_ItemLabels. 
 * \param[in] arg input CFG_ItemLabels
 * \return The number of elements in the CFG_ItemLabels
 */
int _CFG_getItemLabelsLength(CFG_ItemLabels arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a CFG_ItemLabels. 
 * \param[in] arg CFG_ItemLabels to be reversed
 * \return a reversed #arg
 */
CFG_ItemLabels _CFG_reverseItemLabels(CFG_ItemLabels arg) {
  return (CFG_ItemLabels) ATreverse((ATermList) arg);
}

/**
 * Append a CFG_Item to the end of a CFG_ItemLabels. 
 * \param[in] arg CFG_ItemLabels to append the CFG_Item to
 * \param[in] elem CFG_Item to be appended
 * \return new CFG_ItemLabels with #elem appended
 */
CFG_ItemLabels _CFG_appendItemLabels(CFG_ItemLabels arg, CFG_Item elem) {
  return (CFG_ItemLabels) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two CFG_ItemLabelss. 
 * \param[in] arg0 first CFG_ItemLabels
 * \param[in] arg1 second CFG_ItemLabels
 * \return CFG_ItemLabels with the elements of #arg0 before the elements of #arg1
 */
CFG_ItemLabels _CFG_concatItemLabels(CFG_ItemLabels arg0, CFG_ItemLabels arg1) {
  return (CFG_ItemLabels) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a CFG_ItemLabels. 
 * \param[in] arg CFG_ItemLabels to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new CFG_ItemLabels with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
CFG_ItemLabels _CFG_sliceItemLabels(CFG_ItemLabels arg, int start, int end) {
  return (CFG_ItemLabels) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the CFG_Item at #index from a CFG_ItemLabels. 
 * \param[in] arg CFG_ItemLabels to retrieve the CFG_Item from
 * \param[in] index index to use to point in the CFG_ItemLabels
 * \return CFG_Item at position #index in #arg
 */
CFG_Item _CFG_getItemLabelsItemAt(CFG_ItemLabels arg, int index) {
 return (CFG_Item)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the CFG_Item at #index from a CFG_ItemLabels by a new one. 
 * \param[in] arg CFG_ItemLabels to retrieve the CFG_Item from
 * \param[in] elem new CFG_Item to replace another
 * \param[in] index index to use to point in the CFG_ItemLabels
 * \return A new CFG_ItemLabelswith #elem replaced in #arg at position #index
 */
CFG_ItemLabels _CFG_replaceItemLabelsItemAt(CFG_ItemLabels arg, CFG_Item elem, int index) {
 return (CFG_ItemLabels) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a CFG_ItemLabels of 2 consecutive elements. 
 * \param[in] elem1 One CFG_Item element of the new CFG_ItemLabels
 * \param[in] elem2 One CFG_Item element of the new CFG_ItemLabels
 * \return A new CFG_ItemLabels consisting of 2 CFG_Items
 */
CFG_ItemLabels _CFG_makeItemLabels2(CFG_Item elem1, CFG_Item elem2) {
  return (CFG_ItemLabels) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a CFG_ItemLabels of 3 consecutive elements. 
 * \param[in] elem1 One CFG_Item element of the new CFG_ItemLabels
 * \param[in] elem2 One CFG_Item element of the new CFG_ItemLabels
 * \param[in] elem3 One CFG_Item element of the new CFG_ItemLabels
 * \return A new CFG_ItemLabels consisting of 3 CFG_Items
 */
CFG_ItemLabels _CFG_makeItemLabels3(CFG_Item elem1, CFG_Item elem2, CFG_Item elem3) {
  return (CFG_ItemLabels) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a CFG_ItemLabels of 4 consecutive elements. 
 * \param[in] elem1 One CFG_Item element of the new CFG_ItemLabels
 * \param[in] elem2 One CFG_Item element of the new CFG_ItemLabels
 * \param[in] elem3 One CFG_Item element of the new CFG_ItemLabels
 * \param[in] elem4 One CFG_Item element of the new CFG_ItemLabels
 * \return A new CFG_ItemLabels consisting of 4 CFG_Items
 */
CFG_ItemLabels _CFG_makeItemLabels4(CFG_Item elem1, CFG_Item elem2, CFG_Item elem3, CFG_Item elem4) {
  return (CFG_ItemLabels) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a CFG_ItemLabels of 5 consecutive elements. 
 * \param[in] elem1 One CFG_Item element of the new CFG_ItemLabels
 * \param[in] elem2 One CFG_Item element of the new CFG_ItemLabels
 * \param[in] elem3 One CFG_Item element of the new CFG_ItemLabels
 * \param[in] elem4 One CFG_Item element of the new CFG_ItemLabels
 * \param[in] elem5 One CFG_Item element of the new CFG_ItemLabels
 * \return A new CFG_ItemLabels consisting of 5 CFG_Items
 */
CFG_ItemLabels _CFG_makeItemLabels5(CFG_Item elem1, CFG_Item elem2, CFG_Item elem3, CFG_Item elem4, CFG_Item elem5) {
  return (CFG_ItemLabels) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a CFG_ItemLabels of 6 consecutive elements. 
 * \param[in] elem1 One CFG_Item element of the new CFG_ItemLabels
 * \param[in] elem2 One CFG_Item element of the new CFG_ItemLabels
 * \param[in] elem3 One CFG_Item element of the new CFG_ItemLabels
 * \param[in] elem4 One CFG_Item element of the new CFG_ItemLabels
 * \param[in] elem5 One CFG_Item element of the new CFG_ItemLabels
 * \param[in] elem6 One CFG_Item element of the new CFG_ItemLabels
 * \return A new CFG_ItemLabels consisting of 6 CFG_Items
 */
CFG_ItemLabels _CFG_makeItemLabels6(CFG_Item elem1, CFG_Item elem2, CFG_Item elem3, CFG_Item elem4, CFG_Item elem5, CFG_Item elem6) {
  return (CFG_ItemLabels) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Constructs a NOBUTTON of type CFG_VirtualButton. Like all ATerm types, CFG_VirtualButtons are maximally shared.
 * \return A pointer to a NOBUTTON, either newly constructed or shared
 */
CFG_VirtualButton CFG_makeVirtualButtonNOBUTTON(void) {
  return (CFG_VirtualButton)(ATerm)ATmakeAppl0(CFG_afun0);
}
/**
 * Constructs a BUTTON1 of type CFG_VirtualButton. Like all ATerm types, CFG_VirtualButtons are maximally shared.
 * \return A pointer to a BUTTON1, either newly constructed or shared
 */
CFG_VirtualButton CFG_makeVirtualButtonBUTTON1(void) {
  return (CFG_VirtualButton)(ATerm)ATmakeAppl0(CFG_afun1);
}
/**
 * Constructs a BUTTON2 of type CFG_VirtualButton. Like all ATerm types, CFG_VirtualButtons are maximally shared.
 * \return A pointer to a BUTTON2, either newly constructed or shared
 */
CFG_VirtualButton CFG_makeVirtualButtonBUTTON2(void) {
  return (CFG_VirtualButton)(ATerm)ATmakeAppl0(CFG_afun2);
}
/**
 * Constructs a BUTTON3 of type CFG_VirtualButton. Like all ATerm types, CFG_VirtualButtons are maximally shared.
 * \return A pointer to a BUTTON3, either newly constructed or shared
 */
CFG_VirtualButton CFG_makeVirtualButtonBUTTON3(void) {
  return (CFG_VirtualButton)(ATerm)ATmakeAppl0(CFG_afun3);
}
/**
 * Constructs a M_ALT of type CFG_KeyModifier. Like all ATerm types, CFG_KeyModifiers are maximally shared.
 * \return A pointer to a M_ALT, either newly constructed or shared
 */
CFG_KeyModifier CFG_makeKeyModifierMUnderscoreALT(void) {
  return (CFG_KeyModifier)(ATerm)ATmakeAppl0(CFG_afun4);
}
/**
 * Constructs a M_CTRL of type CFG_KeyModifier. Like all ATerm types, CFG_KeyModifiers are maximally shared.
 * \return A pointer to a M_CTRL, either newly constructed or shared
 */
CFG_KeyModifier CFG_makeKeyModifierMUnderscoreCTRL(void) {
  return (CFG_KeyModifier)(ATerm)ATmakeAppl0(CFG_afun5);
}
/**
 * Constructs a M_SHIFT of type CFG_KeyModifier. Like all ATerm types, CFG_KeyModifiers are maximally shared.
 * \return A pointer to a M_SHIFT, either newly constructed or shared
 */
CFG_KeyModifier CFG_makeKeyModifierMUnderscoreSHIFT(void) {
  return (CFG_KeyModifier)(ATerm)ATmakeAppl0(CFG_afun6);
}
/**
 * Constructs a VK_0 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_0, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore0(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun7);
}
/**
 * Constructs a VK_1 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_1, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore1(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun8);
}
/**
 * Constructs a VK_2 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_2, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore2(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun9);
}
/**
 * Constructs a VK_3 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_3, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore3(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun10);
}
/**
 * Constructs a VK_4 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_4, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore4(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun11);
}
/**
 * Constructs a VK_5 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_5, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore5(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun12);
}
/**
 * Constructs a VK_6 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_6, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore6(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun13);
}
/**
 * Constructs a VK_7 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_7, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore7(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun14);
}
/**
 * Constructs a VK_8 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_8, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore8(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun15);
}
/**
 * Constructs a VK_9 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_9, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscore9(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun16);
}
/**
 * Constructs a VK_A of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_A, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreA(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun17);
}
/**
 * Constructs a VK_B of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_B, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreB(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun18);
}
/**
 * Constructs a VK_C of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_C, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreC(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun19);
}
/**
 * Constructs a VK_D of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_D, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreD(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun20);
}
/**
 * Constructs a VK_E of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_E, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun21);
}
/**
 * Constructs a VK_F of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_F, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun22);
}
/**
 * Constructs a VK_G of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_G, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreG(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun23);
}
/**
 * Constructs a VK_H of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_H, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreH(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun24);
}
/**
 * Constructs a VK_I of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_I, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreI(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun25);
}
/**
 * Constructs a VK_J of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_J, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreJ(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun26);
}
/**
 * Constructs a VK_K of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_K, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreK(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun27);
}
/**
 * Constructs a VK_L of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_L, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreL(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun28);
}
/**
 * Constructs a VK_M of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_M, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreM(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun29);
}
/**
 * Constructs a VK_N of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_N, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreN(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun30);
}
/**
 * Constructs a VK_O of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_O, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreO(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun31);
}
/**
 * Constructs a VK_P of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_P, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreP(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun32);
}
/**
 * Constructs a VK_Q of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_Q, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreQ(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun33);
}
/**
 * Constructs a VK_R of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_R, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreR(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun34);
}
/**
 * Constructs a VK_S of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_S, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreS(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun35);
}
/**
 * Constructs a VK_T of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_T, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun36);
}
/**
 * Constructs a VK_U of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_U, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreU(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun37);
}
/**
 * Constructs a VK_V of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_V, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreV(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun38);
}
/**
 * Constructs a VK_W of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_W, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreW(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun39);
}
/**
 * Constructs a VK_X of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_X, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreX(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun40);
}
/**
 * Constructs a VK_Y of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_Y, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreY(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun41);
}
/**
 * Constructs a VK_Z of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_Z, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreZ(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun42);
}
/**
 * Constructs a VK_AMPERSAND of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_AMPERSAND, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreAMPERSAND(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun43);
}
/**
 * Constructs a VK_ASTERISK of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_ASTERISK, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreASTERISK(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun44);
}
/**
 * Constructs a VK_AT of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_AT, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreAT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun45);
}
/**
 * Constructs a VK_BACK_QUOTE of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_BACK_QUOTE, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBACKUnderscoreQUOTE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun46);
}
/**
 * Constructs a VK_BACK_SLASH of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_BACK_SLASH, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBACKUnderscoreSLASH(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun47);
}
/**
 * Constructs a VK_BACK_SPACE of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_BACK_SPACE, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBACKUnderscoreSPACE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun48);
}
/**
 * Constructs a VK_BEGIN of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_BEGIN, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBEGIN(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun49);
}
/**
 * Constructs a VK_BRACE_LEFT of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_BRACE_LEFT, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBRACEUnderscoreLEFT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun50);
}
/**
 * Constructs a VK_BRACE_RIGHT of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_BRACE_RIGHT, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreBRACEUnderscoreRIGHT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun51);
}
/**
 * Constructs a VK_CIRCUMFLEX of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_CIRCUMFLEX, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreCIRCUMFLEX(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun52);
}
/**
 * Constructs a VK_CLEAR of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_CLEAR, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreCLEAR(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun53);
}
/**
 * Constructs a VK_CLOSE_BRACKET of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_CLOSE_BRACKET, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreCLOSEUnderscoreBRACKET(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun54);
}
/**
 * Constructs a VK_COLON of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_COLON, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreCOLON(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun55);
}
/**
 * Constructs a VK_COMMA of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_COMMA, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreCOMMA(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun56);
}
/**
 * Constructs a VK_DECIMAL of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_DECIMAL, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreDECIMAL(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun57);
}
/**
 * Constructs a VK_DELETE of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_DELETE, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreDELETE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun58);
}
/**
 * Constructs a VK_DIVIDE of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_DIVIDE, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreDIVIDE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun59);
}
/**
 * Constructs a VK_DOLLAR of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_DOLLAR, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreDOLLAR(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun60);
}
/**
 * Constructs a VK_DOWN of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_DOWN, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreDOWN(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun61);
}
/**
 * Constructs a VK_END of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_END, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreEND(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun62);
}
/**
 * Constructs a VK_ENTER of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_ENTER, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreENTER(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun63);
}
/**
 * Constructs a VK_EQUALS of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_EQUALS, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreEQUALS(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun64);
}
/**
 * Constructs a VK_ESCAPE of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_ESCAPE, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreESCAPE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun65);
}
/**
 * Constructs a VK_EXCLAMATION_MARK of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_EXCLAMATION_MARK, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreEXCLAMATIONUnderscoreMARK(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun66);
}
/**
 * Constructs a VK_F1 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_F1, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF1(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun67);
}
/**
 * Constructs a VK_F2 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_F2, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF2(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun68);
}
/**
 * Constructs a VK_F3 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_F3, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF3(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun69);
}
/**
 * Constructs a VK_F4 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_F4, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF4(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun70);
}
/**
 * Constructs a VK_F5 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_F5, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF5(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun71);
}
/**
 * Constructs a VK_F6 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_F6, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF6(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun72);
}
/**
 * Constructs a VK_F7 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_F7, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF7(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun73);
}
/**
 * Constructs a VK_F8 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_F8, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF8(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun74);
}
/**
 * Constructs a VK_F9 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_F9, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF9(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun75);
}
/**
 * Constructs a VK_F10 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_F10, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF10(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun76);
}
/**
 * Constructs a VK_F11 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_F11, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF11(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun77);
}
/**
 * Constructs a VK_F12 of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_F12, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreF12(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun78);
}
/**
 * Constructs a VK_GREATER of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_GREATER, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreGREATER(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun79);
}
/**
 * Constructs a VK_HOME of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_HOME, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreHOME(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun80);
}
/**
 * Constructs a VK_INSERT of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_INSERT, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreINSERT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun81);
}
/**
 * Constructs a VK_LEFT of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_LEFT, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreLEFT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun82);
}
/**
 * Constructs a VK_LEFT_PARENTHESIS of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_LEFT_PARENTHESIS, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreLEFTUnderscorePARENTHESIS(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun83);
}
/**
 * Constructs a VK_MINUS of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_MINUS, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreMINUS(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun84);
}
/**
 * Constructs a VK_MULTIPLY of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_MULTIPLY, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreMULTIPLY(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun85);
}
/**
 * Constructs a VK_NUMBER_SIGN of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_NUMBER_SIGN, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreNUMBERUnderscoreSIGN(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun86);
}
/**
 * Constructs a VK_OPEN_BRACKET of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_OPEN_BRACKET, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreOPENUnderscoreBRACKET(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun87);
}
/**
 * Constructs a VK_PAGE_DOWN of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_PAGE_DOWN, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePAGEUnderscoreDOWN(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun88);
}
/**
 * Constructs a VK_PAGE_UP of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_PAGE_UP, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePAGEUnderscoreUP(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun89);
}
/**
 * Constructs a VK_PAUSE of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_PAUSE, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePAUSE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun90);
}
/**
 * Constructs a VK_PERIOD of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_PERIOD, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePERIOD(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun91);
}
/**
 * Constructs a VK_PLUS of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_PLUS, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePLUS(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun92);
}
/**
 * Constructs a VK_PRINTSCREEN of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_PRINTSCREEN, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscorePRINTSCREEN(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun93);
}
/**
 * Constructs a VK_QUOTE of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_QUOTE, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreQUOTE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun94);
}
/**
 * Constructs a VK_QUOTEDBL of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_QUOTEDBL, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreQUOTEDBL(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun95);
}
/**
 * Constructs a VK_RIGHT of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_RIGHT, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreRIGHT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun96);
}
/**
 * Constructs a VK_RIGHT_PARENTHESIS of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_RIGHT_PARENTHESIS, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreRIGHTUnderscorePARENTHESIS(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun97);
}
/**
 * Constructs a VK_SEMICOLON of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_SEMICOLON, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreSEMICOLON(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun98);
}
/**
 * Constructs a VK_SLASH of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_SLASH, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreSLASH(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun99);
}
/**
 * Constructs a VK_SPACE of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_SPACE, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreSPACE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun100);
}
/**
 * Constructs a VK_SUBTRACT of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_SUBTRACT, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreSUBTRACT(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun101);
}
/**
 * Constructs a VK_TAB of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_TAB, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreTAB(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun102);
}
/**
 * Constructs a VK_UNDERSCORE of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_UNDERSCORE, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreUNDERSCORE(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun103);
}
/**
 * Constructs a VK_UP of type CFG_VirtualKey. Like all ATerm types, CFG_VirtualKeys are maximally shared.
 * \return A pointer to a VK_UP, either newly constructed or shared
 */
CFG_VirtualKey CFG_makeVirtualKeyVKUnderscoreUP(void) {
  return (CFG_VirtualKey)(ATerm)ATmakeAppl0(CFG_afun104);
}
/**
 * Constructs a rgb of type CFG_Color. Like all ATerm types, CFG_Colors are maximally shared.
 * \param[in] red a child of the new rgb
 * \param[in] green a child of the new rgb
 * \param[in] blue a child of the new rgb
 * \return A pointer to a rgb, either newly constructed or shared
 */
CFG_Color CFG_makeColorRgb(int red, int green, int blue) {
  return (CFG_Color)(ATerm)ATmakeAppl3(CFG_afun105, (ATerm) (ATerm) ATmakeInt(red), (ATerm) (ATerm) ATmakeInt(green), (ATerm) (ATerm) ATmakeInt(blue));
}
/**
 * Constructs a configuration of type CFG_Configuration. Like all ATerm types, CFG_Configurations are maximally shared.
 * \param[in] list a child of the new configuration
 * \return A pointer to a configuration, either newly constructed or shared
 */
CFG_Configuration CFG_makeConfigurationConfiguration(CFG_PropertyList list) {
  return (CFG_Configuration)(ATerm)ATmakeAppl1(CFG_afun106, (ATerm) list);
}
/**
 * Constructs a import of type CFG_Property. Like all ATerm types, CFG_Propertys are maximally shared.
 * \param[in] path a child of the new import
 * \return A pointer to a import, either newly constructed or shared
 */
CFG_Property CFG_makePropertyImport(const char* path) {
  return (CFG_Property)(ATerm)ATmakeAppl1(CFG_afun107, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}
/**
 * Constructs a script of type CFG_Property. Like all ATerm types, CFG_Propertys are maximally shared.
 * \param[in] path a child of the new script
 * \return A pointer to a script, either newly constructed or shared
 */
CFG_Property CFG_makePropertyScript(const char* path) {
  return (CFG_Property)(ATerm)ATmakeAppl1(CFG_afun108, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}
/**
 * Constructs a script-path of type CFG_Property. Like all ATerm types, CFG_Propertys are maximally shared.
 * \param[in] path a child of the new script-path
 * \return A pointer to a script-path, either newly constructed or shared
 */
CFG_Property CFG_makePropertyScriptPath(const char* path) {
  return (CFG_Property)(ATerm)ATmakeAppl1(CFG_afun109, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}
/**
 * Constructs a action of type CFG_Property. Like all ATerm types, CFG_Propertys are maximally shared.
 * \param[in] list a child of the new action
 * \param[in] action a child of the new action
 * \return A pointer to a action, either newly constructed or shared
 */
CFG_Property CFG_makePropertyAction(CFG_ActionDescriptionList list, const char* action) {
  return (CFG_Property)(ATerm)ATmakeAppl2(CFG_afun110, (ATerm) list, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(action, 0, ATtrue)));
}
/**
 * Constructs a editor of type CFG_Property. Like all ATerm types, CFG_Propertys are maximally shared.
 * \param[in] editor a child of the new editor
 * \param[in] language a child of the new editor
 * \param[in] extension a child of the new editor
 * \return A pointer to a editor, either newly constructed or shared
 */
CFG_Property CFG_makePropertyEditor(const char* editor, const char* language, const char* extension) {
  return (CFG_Property)(ATerm)ATmakeAppl3(CFG_afun111, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(editor, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(language, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(extension, 0, ATtrue)));
}
/**
 * Constructs a library-path of type CFG_Property. Like all ATerm types, CFG_Propertys are maximally shared.
 * \param[in] label a child of the new library-path
 * \param[in] path a child of the new library-path
 * \return A pointer to a library-path, either newly constructed or shared
 */
CFG_Property CFG_makePropertyLibraryPath(const char* label, const char* path) {
  return (CFG_Property)(ATerm)ATmakeAppl2(CFG_afun112, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(label, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}
/**
 * Constructs a module-path of type CFG_Property. Like all ATerm types, CFG_Propertys are maximally shared.
 * \param[in] label a child of the new module-path
 * \param[in] path a child of the new module-path
 * \return A pointer to a module-path, either newly constructed or shared
 */
CFG_Property CFG_makePropertyModulePath(const char* label, const char* path) {
  return (CFG_Property)(ATerm)ATmakeAppl2(CFG_afun113, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(label, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}
/**
 * Constructs a text-category of type CFG_Property. Like all ATerm types, CFG_Propertys are maximally shared.
 * \param[in] category a child of the new text-category
 * \param[in] map a child of the new text-category
 * \return A pointer to a text-category, either newly constructed or shared
 */
CFG_Property CFG_makePropertyTextCategory(CFG_TextCategoryName category, CFG_TextAttributeMap map) {
  return (CFG_Property)(ATerm)ATmakeAppl2(CFG_afun114, (ATerm) category, (ATerm) map);
}
/**
 * Constructs a description of type CFG_ActionDescription. Like all ATerm types, CFG_ActionDescriptions are maximally shared.
 * \param[in] context a child of the new description
 * \param[in] event a child of the new description
 * \return A pointer to a description, either newly constructed or shared
 */
CFG_ActionDescription CFG_makeActionDescriptionDescription(ATerm context, CFG_Event event) {
  return (CFG_ActionDescription)(ATerm)ATmakeAppl2(CFG_afun115, (ATerm) context, (ATerm) event);
}
/**
 * Constructs a popup of type CFG_Event. Like all ATerm types, CFG_Events are maximally shared.
 * \return A pointer to a popup, either newly constructed or shared
 */
CFG_Event CFG_makeEventPopup(void) {
  return (CFG_Event)(ATerm)ATmakeAppl0(CFG_afun116);
}
/**
 * Constructs a click of type CFG_Event. Like all ATerm types, CFG_Events are maximally shared.
 * \param[in] list a child of the new click
 * \param[in] button a child of the new click
 * \return A pointer to a click, either newly constructed or shared
 */
CFG_Event CFG_makeEventClick(CFG_KeyModifierList list, CFG_VirtualButton button) {
  return (CFG_Event)(ATerm)ATmakeAppl2(CFG_afun117, (ATerm) list, (ATerm) button);
}
/**
 * Constructs a icon of type CFG_Event. Like all ATerm types, CFG_Events are maximally shared.
 * \param[in] title a child of the new icon
 * \param[in] path a child of the new icon
 * \return A pointer to a icon, either newly constructed or shared
 */
CFG_Event CFG_makeEventIcon(const char* title, const char* path) {
  return (CFG_Event)(ATerm)ATmakeAppl2(CFG_afun118, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(title, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue)));
}
/**
 * Constructs a menu of type CFG_Event. Like all ATerm types, CFG_Events are maximally shared.
 * \param[in] labels a child of the new menu
 * \param[in] info a child of the new menu
 * \return A pointer to a menu, either newly constructed or shared
 */
CFG_Event CFG_makeEventMenu(CFG_ItemLabels labels, const char* info) {
  return (CFG_Event)(ATerm)ATmakeAppl2(CFG_afun119, (ATerm) labels, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(info, 0, ATtrue)));
}
/**
 * Constructs a menu-shortcut of type CFG_Event. Like all ATerm types, CFG_Events are maximally shared.
 * \param[in] labels a child of the new menu-shortcut
 * \param[in] shortcut a child of the new menu-shortcut
 * \param[in] info a child of the new menu-shortcut
 * \return A pointer to a menu-shortcut, either newly constructed or shared
 */
CFG_Event CFG_makeEventMenuShortcut(CFG_ItemLabels labels, CFG_ShortCut shortcut, const char* info) {
  return (CFG_Event)(ATerm)ATmakeAppl3(CFG_afun120, (ATerm) labels, (ATerm) shortcut, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(info, 0, ATtrue)));
}
/**
 * Constructs a label of type CFG_Item. Like all ATerm types, CFG_Items are maximally shared.
 * \param[in] name a child of the new label
 * \return A pointer to a label, either newly constructed or shared
 */
CFG_Item CFG_makeItemLabel(const char* name) {
  return (CFG_Item)(ATerm)ATmakeAppl1(CFG_afun121, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}
/**
 * Constructs a focus of type CFG_TextCategoryName. Like all ATerm types, CFG_TextCategoryNames are maximally shared.
 * \return A pointer to a focus, either newly constructed or shared
 */
CFG_TextCategoryName CFG_makeTextCategoryNameFocus(void) {
  return (CFG_TextCategoryName)(ATerm)ATmakeAppl0(CFG_afun122);
}
/**
 * Constructs a selection of type CFG_TextCategoryName. Like all ATerm types, CFG_TextCategoryNames are maximally shared.
 * \return A pointer to a selection, either newly constructed or shared
 */
CFG_TextCategoryName CFG_makeTextCategoryNameSelection(void) {
  return (CFG_TextCategoryName)(ATerm)ATmakeAppl0(CFG_afun123);
}
/**
 * Constructs a normal of type CFG_TextCategoryName. Like all ATerm types, CFG_TextCategoryNames are maximally shared.
 * \return A pointer to a normal, either newly constructed or shared
 */
CFG_TextCategoryName CFG_makeTextCategoryNameNormal(void) {
  return (CFG_TextCategoryName)(ATerm)ATmakeAppl0(CFG_afun124);
}
/**
 * Constructs a extern of type CFG_TextCategoryName. Like all ATerm types, CFG_TextCategoryNames are maximally shared.
 * \param[in] name a child of the new extern
 * \return A pointer to a extern, either newly constructed or shared
 */
CFG_TextCategoryName CFG_makeTextCategoryNameExtern(const char* name) {
  return (CFG_TextCategoryName)(ATerm)ATmakeAppl1(CFG_afun125, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}
/**
 * Constructs a foreground-color of type CFG_TextAttribute. Like all ATerm types, CFG_TextAttributes are maximally shared.
 * \param[in] color a child of the new foreground-color
 * \return A pointer to a foreground-color, either newly constructed or shared
 */
CFG_TextAttribute CFG_makeTextAttributeForegroundColor(CFG_Color color) {
  return (CFG_TextAttribute)(ATerm)ATmakeAppl1(CFG_afun126, (ATerm) color);
}
/**
 * Constructs a background-color of type CFG_TextAttribute. Like all ATerm types, CFG_TextAttributes are maximally shared.
 * \param[in] color a child of the new background-color
 * \return A pointer to a background-color, either newly constructed or shared
 */
CFG_TextAttribute CFG_makeTextAttributeBackgroundColor(CFG_Color color) {
  return (CFG_TextAttribute)(ATerm)ATmakeAppl1(CFG_afun127, (ATerm) color);
}
/**
 * Constructs a style of type CFG_TextAttribute. Like all ATerm types, CFG_TextAttributes are maximally shared.
 * \param[in] style a child of the new style
 * \return A pointer to a style, either newly constructed or shared
 */
CFG_TextAttribute CFG_makeTextAttributeStyle(CFG_TextStyle style) {
  return (CFG_TextAttribute)(ATerm)ATmakeAppl1(CFG_afun128, (ATerm) style);
}
/**
 * Constructs a font of type CFG_TextAttribute. Like all ATerm types, CFG_TextAttributes are maximally shared.
 * \param[in] name a child of the new font
 * \return A pointer to a font, either newly constructed or shared
 */
CFG_TextAttribute CFG_makeTextAttributeFont(const char* name) {
  return (CFG_TextAttribute)(ATerm)ATmakeAppl1(CFG_afun129, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}
/**
 * Constructs a size of type CFG_TextAttribute. Like all ATerm types, CFG_TextAttributes are maximally shared.
 * \param[in] point a child of the new size
 * \return A pointer to a size, either newly constructed or shared
 */
CFG_TextAttribute CFG_makeTextAttributeSize(int point) {
  return (CFG_TextAttribute)(ATerm)ATmakeAppl1(CFG_afun130, (ATerm) (ATerm) ATmakeInt(point));
}
/**
 * Constructs a shortcut of type CFG_ShortCut. Like all ATerm types, CFG_ShortCuts are maximally shared.
 * \param[in] list a child of the new shortcut
 * \param[in] key a child of the new shortcut
 * \return A pointer to a shortcut, either newly constructed or shared
 */
CFG_ShortCut CFG_makeShortCutShortcut(CFG_KeyModifierList list, CFG_VirtualKey key) {
  return (CFG_ShortCut)(ATerm)ATmakeAppl2(CFG_afun131, (ATerm) list, (ATerm) key);
}
/**
 * Constructs a bold of type CFG_TextStyle. Like all ATerm types, CFG_TextStyles are maximally shared.
 * \return A pointer to a bold, either newly constructed or shared
 */
CFG_TextStyle CFG_makeTextStyleBold(void) {
  return (CFG_TextStyle)(ATerm)ATmakeAppl0(CFG_afun132);
}
/**
 * Constructs a italics of type CFG_TextStyle. Like all ATerm types, CFG_TextStyles are maximally shared.
 * \return A pointer to a italics, either newly constructed or shared
 */
CFG_TextStyle CFG_makeTextStyleItalics(void) {
  return (CFG_TextStyle)(ATerm)ATmakeAppl0(CFG_afun133);
}
/**
 * Constructs a underlined of type CFG_TextStyle. Like all ATerm types, CFG_TextStyles are maximally shared.
 * \return A pointer to a underlined, either newly constructed or shared
 */
CFG_TextStyle CFG_makeTextStyleUnderlined(void) {
  return (CFG_TextStyle)(ATerm)ATmakeAppl0(CFG_afun134);
}
/**
 * Constructs a empty of type CFG_PropertyList. Like all ATerm types, CFG_PropertyLists are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
CFG_PropertyList CFG_makePropertyListEmpty(void) {
  return (CFG_PropertyList)(ATerm)ATempty;
}
/**
 * Constructs a single of type CFG_PropertyList. Like all ATerm types, CFG_PropertyLists are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
CFG_PropertyList CFG_makePropertyListSingle(CFG_Property head) {
  return (CFG_PropertyList)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type CFG_PropertyList. Like all ATerm types, CFG_PropertyLists are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
CFG_PropertyList CFG_makePropertyListMany(CFG_Property head, CFG_PropertyList tail) {
  return (CFG_PropertyList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a empty of type CFG_ActionDescriptionList. Like all ATerm types, CFG_ActionDescriptionLists are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
CFG_ActionDescriptionList CFG_makeActionDescriptionListEmpty(void) {
  return (CFG_ActionDescriptionList)(ATerm)ATempty;
}
/**
 * Constructs a single of type CFG_ActionDescriptionList. Like all ATerm types, CFG_ActionDescriptionLists are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
CFG_ActionDescriptionList CFG_makeActionDescriptionListSingle(CFG_ActionDescription head) {
  return (CFG_ActionDescriptionList)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type CFG_ActionDescriptionList. Like all ATerm types, CFG_ActionDescriptionLists are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
CFG_ActionDescriptionList CFG_makeActionDescriptionListMany(CFG_ActionDescription head, CFG_ActionDescriptionList tail) {
  return (CFG_ActionDescriptionList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a empty of type CFG_TextAttributeMap. Like all ATerm types, CFG_TextAttributeMaps are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
CFG_TextAttributeMap CFG_makeTextAttributeMapEmpty(void) {
  return (CFG_TextAttributeMap)(ATerm)ATempty;
}
/**
 * Constructs a single of type CFG_TextAttributeMap. Like all ATerm types, CFG_TextAttributeMaps are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
CFG_TextAttributeMap CFG_makeTextAttributeMapSingle(CFG_TextAttribute head) {
  return (CFG_TextAttributeMap)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type CFG_TextAttributeMap. Like all ATerm types, CFG_TextAttributeMaps are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
CFG_TextAttributeMap CFG_makeTextAttributeMapMany(CFG_TextAttribute head, CFG_TextAttributeMap tail) {
  return (CFG_TextAttributeMap)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a empty of type CFG_KeyModifierList. Like all ATerm types, CFG_KeyModifierLists are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
CFG_KeyModifierList CFG_makeKeyModifierListEmpty(void) {
  return (CFG_KeyModifierList)(ATerm)ATempty;
}
/**
 * Constructs a single of type CFG_KeyModifierList. Like all ATerm types, CFG_KeyModifierLists are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
CFG_KeyModifierList CFG_makeKeyModifierListSingle(CFG_KeyModifier head) {
  return (CFG_KeyModifierList)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type CFG_KeyModifierList. Like all ATerm types, CFG_KeyModifierLists are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
CFG_KeyModifierList CFG_makeKeyModifierListMany(CFG_KeyModifier head, CFG_KeyModifierList tail) {
  return (CFG_KeyModifierList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a empty of type CFG_ItemLabels. Like all ATerm types, CFG_ItemLabelss are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
CFG_ItemLabels CFG_makeItemLabelsEmpty(void) {
  return (CFG_ItemLabels)(ATerm)ATempty;
}
/**
 * Constructs a single of type CFG_ItemLabels. Like all ATerm types, CFG_ItemLabelss are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
CFG_ItemLabels CFG_makeItemLabelsSingle(CFG_Item head) {
  return (CFG_ItemLabels)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type CFG_ItemLabels. Like all ATerm types, CFG_ItemLabelss are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
CFG_ItemLabels CFG_makeItemLabelsMany(CFG_Item head, CFG_ItemLabels tail) {
  return (CFG_ItemLabels)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/**
 * Tests equality of two CFG_VirtualButtons. A constant time operation.
 * \param[in] arg0 first CFG_VirtualButton to be compared
 * \param[in] arg1 second CFG_VirtualButton to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualVirtualButton(CFG_VirtualButton arg0, CFG_VirtualButton arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_KeyModifiers. A constant time operation.
 * \param[in] arg0 first CFG_KeyModifier to be compared
 * \param[in] arg1 second CFG_KeyModifier to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualKeyModifier(CFG_KeyModifier arg0, CFG_KeyModifier arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_VirtualKeys. A constant time operation.
 * \param[in] arg0 first CFG_VirtualKey to be compared
 * \param[in] arg1 second CFG_VirtualKey to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualVirtualKey(CFG_VirtualKey arg0, CFG_VirtualKey arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_Colors. A constant time operation.
 * \param[in] arg0 first CFG_Color to be compared
 * \param[in] arg1 second CFG_Color to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualColor(CFG_Color arg0, CFG_Color arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_Configurations. A constant time operation.
 * \param[in] arg0 first CFG_Configuration to be compared
 * \param[in] arg1 second CFG_Configuration to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualConfiguration(CFG_Configuration arg0, CFG_Configuration arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_Propertys. A constant time operation.
 * \param[in] arg0 first CFG_Property to be compared
 * \param[in] arg1 second CFG_Property to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualProperty(CFG_Property arg0, CFG_Property arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_ActionDescriptions. A constant time operation.
 * \param[in] arg0 first CFG_ActionDescription to be compared
 * \param[in] arg1 second CFG_ActionDescription to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualActionDescription(CFG_ActionDescription arg0, CFG_ActionDescription arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_Events. A constant time operation.
 * \param[in] arg0 first CFG_Event to be compared
 * \param[in] arg1 second CFG_Event to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualEvent(CFG_Event arg0, CFG_Event arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_Items. A constant time operation.
 * \param[in] arg0 first CFG_Item to be compared
 * \param[in] arg1 second CFG_Item to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualItem(CFG_Item arg0, CFG_Item arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_TextCategoryNames. A constant time operation.
 * \param[in] arg0 first CFG_TextCategoryName to be compared
 * \param[in] arg1 second CFG_TextCategoryName to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualTextCategoryName(CFG_TextCategoryName arg0, CFG_TextCategoryName arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_TextAttributes. A constant time operation.
 * \param[in] arg0 first CFG_TextAttribute to be compared
 * \param[in] arg1 second CFG_TextAttribute to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualTextAttribute(CFG_TextAttribute arg0, CFG_TextAttribute arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_ShortCuts. A constant time operation.
 * \param[in] arg0 first CFG_ShortCut to be compared
 * \param[in] arg1 second CFG_ShortCut to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualShortCut(CFG_ShortCut arg0, CFG_ShortCut arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_TextStyles. A constant time operation.
 * \param[in] arg0 first CFG_TextStyle to be compared
 * \param[in] arg1 second CFG_TextStyle to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualTextStyle(CFG_TextStyle arg0, CFG_TextStyle arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_PropertyLists. A constant time operation.
 * \param[in] arg0 first CFG_PropertyList to be compared
 * \param[in] arg1 second CFG_PropertyList to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualPropertyList(CFG_PropertyList arg0, CFG_PropertyList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_ActionDescriptionLists. A constant time operation.
 * \param[in] arg0 first CFG_ActionDescriptionList to be compared
 * \param[in] arg1 second CFG_ActionDescriptionList to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualActionDescriptionList(CFG_ActionDescriptionList arg0, CFG_ActionDescriptionList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_TextAttributeMaps. A constant time operation.
 * \param[in] arg0 first CFG_TextAttributeMap to be compared
 * \param[in] arg1 second CFG_TextAttributeMap to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualTextAttributeMap(CFG_TextAttributeMap arg0, CFG_TextAttributeMap arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_KeyModifierLists. A constant time operation.
 * \param[in] arg0 first CFG_KeyModifierList to be compared
 * \param[in] arg1 second CFG_KeyModifierList to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualKeyModifierList(CFG_KeyModifierList arg0, CFG_KeyModifierList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CFG_ItemLabelss. A constant time operation.
 * \param[in] arg0 first CFG_ItemLabels to be compared
 * \param[in] arg1 second CFG_ItemLabels to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _CFG_isEqualItemLabels(CFG_ItemLabels arg0, CFG_ItemLabels arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Assert whether a CFG_VirtualButton is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_VirtualButton
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CFG_isValidVirtualButton(CFG_VirtualButton arg) {
  if (CFG_isVirtualButtonNOBUTTON(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualButtonBUTTON1(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualButtonBUTTON2(arg)) {
    return ATtrue;
  }
  else if (CFG_isVirtualButtonBUTTON3(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualButton is a NOBUTTON by checking against the following ATerm pattern: NOBUTTON. May not be used to assert correctness of the CFG_VirtualButton
 * \param[in] arg input CFG_VirtualButton
 * \return ATtrue if #arg corresponds to the signature of a NOBUTTON, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualButtonNOBUTTON(CFG_VirtualButton arg){
  /* checking for: NOBUTTON */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun0) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualButton is a BUTTON1 by checking against the following ATerm pattern: BUTTON1. May not be used to assert correctness of the CFG_VirtualButton
 * \param[in] arg input CFG_VirtualButton
 * \return ATtrue if #arg corresponds to the signature of a BUTTON1, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualButtonBUTTON1(CFG_VirtualButton arg){
  /* checking for: BUTTON1 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun1) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualButton is a BUTTON2 by checking against the following ATerm pattern: BUTTON2. May not be used to assert correctness of the CFG_VirtualButton
 * \param[in] arg input CFG_VirtualButton
 * \return ATtrue if #arg corresponds to the signature of a BUTTON2, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualButtonBUTTON2(CFG_VirtualButton arg){
  /* checking for: BUTTON2 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun2) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualButton is a BUTTON3 by checking against the following ATerm pattern: BUTTON3. May not be used to assert correctness of the CFG_VirtualButton
 * \param[in] arg input CFG_VirtualButton
 * \return ATtrue if #arg corresponds to the signature of a BUTTON3, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualButtonBUTTON3(CFG_VirtualButton arg){
  /* checking for: BUTTON3 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun3) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_KeyModifier is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_KeyModifier
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
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

/**
 * Assert whether a CFG_KeyModifier is a M_ALT by checking against the following ATerm pattern: M_ALT. May not be used to assert correctness of the CFG_KeyModifier
 * \param[in] arg input CFG_KeyModifier
 * \return ATtrue if #arg corresponds to the signature of a M_ALT, or ATfalse otherwise
 */
inline ATbool CFG_isKeyModifierMUnderscoreALT(CFG_KeyModifier arg){
  /* checking for: M_ALT */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun4) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_KeyModifier is a M_CTRL by checking against the following ATerm pattern: M_CTRL. May not be used to assert correctness of the CFG_KeyModifier
 * \param[in] arg input CFG_KeyModifier
 * \return ATtrue if #arg corresponds to the signature of a M_CTRL, or ATfalse otherwise
 */
inline ATbool CFG_isKeyModifierMUnderscoreCTRL(CFG_KeyModifier arg){
  /* checking for: M_CTRL */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun5) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_KeyModifier is a M_SHIFT by checking against the following ATerm pattern: M_SHIFT. May not be used to assert correctness of the CFG_KeyModifier
 * \param[in] arg input CFG_KeyModifier
 * \return ATtrue if #arg corresponds to the signature of a M_SHIFT, or ATfalse otherwise
 */
inline ATbool CFG_isKeyModifierMUnderscoreSHIFT(CFG_KeyModifier arg){
  /* checking for: M_SHIFT */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun6) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
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

/**
 * Assert whether a CFG_VirtualKey is a VK_0 by checking against the following ATerm pattern: VK_0. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_0, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscore0(CFG_VirtualKey arg){
  /* checking for: VK_0 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun7) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_1 by checking against the following ATerm pattern: VK_1. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_1, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscore1(CFG_VirtualKey arg){
  /* checking for: VK_1 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun8) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_2 by checking against the following ATerm pattern: VK_2. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_2, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscore2(CFG_VirtualKey arg){
  /* checking for: VK_2 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun9) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_3 by checking against the following ATerm pattern: VK_3. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_3, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscore3(CFG_VirtualKey arg){
  /* checking for: VK_3 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun10) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_4 by checking against the following ATerm pattern: VK_4. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_4, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscore4(CFG_VirtualKey arg){
  /* checking for: VK_4 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun11) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_5 by checking against the following ATerm pattern: VK_5. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_5, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscore5(CFG_VirtualKey arg){
  /* checking for: VK_5 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun12) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_6 by checking against the following ATerm pattern: VK_6. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_6, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscore6(CFG_VirtualKey arg){
  /* checking for: VK_6 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun13) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_7 by checking against the following ATerm pattern: VK_7. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_7, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscore7(CFG_VirtualKey arg){
  /* checking for: VK_7 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun14) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_8 by checking against the following ATerm pattern: VK_8. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_8, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscore8(CFG_VirtualKey arg){
  /* checking for: VK_8 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun15) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_9 by checking against the following ATerm pattern: VK_9. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_9, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscore9(CFG_VirtualKey arg){
  /* checking for: VK_9 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun16) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_A by checking against the following ATerm pattern: VK_A. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_A, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreA(CFG_VirtualKey arg){
  /* checking for: VK_A */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun17) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_B by checking against the following ATerm pattern: VK_B. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_B, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreB(CFG_VirtualKey arg){
  /* checking for: VK_B */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun18) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_C by checking against the following ATerm pattern: VK_C. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_C, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreC(CFG_VirtualKey arg){
  /* checking for: VK_C */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun19) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_D by checking against the following ATerm pattern: VK_D. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_D, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreD(CFG_VirtualKey arg){
  /* checking for: VK_D */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun20) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_E by checking against the following ATerm pattern: VK_E. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_E, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreE(CFG_VirtualKey arg){
  /* checking for: VK_E */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun21) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_F by checking against the following ATerm pattern: VK_F. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_F, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreF(CFG_VirtualKey arg){
  /* checking for: VK_F */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun22) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_G by checking against the following ATerm pattern: VK_G. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_G, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreG(CFG_VirtualKey arg){
  /* checking for: VK_G */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun23) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_H by checking against the following ATerm pattern: VK_H. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_H, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreH(CFG_VirtualKey arg){
  /* checking for: VK_H */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun24) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_I by checking against the following ATerm pattern: VK_I. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_I, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreI(CFG_VirtualKey arg){
  /* checking for: VK_I */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun25) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_J by checking against the following ATerm pattern: VK_J. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_J, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreJ(CFG_VirtualKey arg){
  /* checking for: VK_J */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun26) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_K by checking against the following ATerm pattern: VK_K. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_K, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreK(CFG_VirtualKey arg){
  /* checking for: VK_K */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun27) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_L by checking against the following ATerm pattern: VK_L. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_L, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreL(CFG_VirtualKey arg){
  /* checking for: VK_L */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun28) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_M by checking against the following ATerm pattern: VK_M. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_M, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreM(CFG_VirtualKey arg){
  /* checking for: VK_M */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun29) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_N by checking against the following ATerm pattern: VK_N. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_N, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreN(CFG_VirtualKey arg){
  /* checking for: VK_N */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun30) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_O by checking against the following ATerm pattern: VK_O. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_O, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreO(CFG_VirtualKey arg){
  /* checking for: VK_O */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun31) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_P by checking against the following ATerm pattern: VK_P. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_P, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreP(CFG_VirtualKey arg){
  /* checking for: VK_P */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun32) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_Q by checking against the following ATerm pattern: VK_Q. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_Q, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreQ(CFG_VirtualKey arg){
  /* checking for: VK_Q */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun33) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_R by checking against the following ATerm pattern: VK_R. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_R, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreR(CFG_VirtualKey arg){
  /* checking for: VK_R */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun34) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_S by checking against the following ATerm pattern: VK_S. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_S, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreS(CFG_VirtualKey arg){
  /* checking for: VK_S */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun35) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_T by checking against the following ATerm pattern: VK_T. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_T, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreT(CFG_VirtualKey arg){
  /* checking for: VK_T */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun36) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_U by checking against the following ATerm pattern: VK_U. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_U, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreU(CFG_VirtualKey arg){
  /* checking for: VK_U */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun37) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_V by checking against the following ATerm pattern: VK_V. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_V, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreV(CFG_VirtualKey arg){
  /* checking for: VK_V */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun38) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_W by checking against the following ATerm pattern: VK_W. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_W, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreW(CFG_VirtualKey arg){
  /* checking for: VK_W */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun39) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_X by checking against the following ATerm pattern: VK_X. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_X, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreX(CFG_VirtualKey arg){
  /* checking for: VK_X */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun40) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_Y by checking against the following ATerm pattern: VK_Y. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_Y, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreY(CFG_VirtualKey arg){
  /* checking for: VK_Y */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun41) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_Z by checking against the following ATerm pattern: VK_Z. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_Z, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreZ(CFG_VirtualKey arg){
  /* checking for: VK_Z */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun42) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_AMPERSAND by checking against the following ATerm pattern: VK_AMPERSAND. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_AMPERSAND, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreAMPERSAND(CFG_VirtualKey arg){
  /* checking for: VK_AMPERSAND */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun43) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_ASTERISK by checking against the following ATerm pattern: VK_ASTERISK. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_ASTERISK, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreASTERISK(CFG_VirtualKey arg){
  /* checking for: VK_ASTERISK */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun44) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_AT by checking against the following ATerm pattern: VK_AT. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_AT, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreAT(CFG_VirtualKey arg){
  /* checking for: VK_AT */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun45) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_BACK_QUOTE by checking against the following ATerm pattern: VK_BACK_QUOTE. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_BACK_QUOTE, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreBACKUnderscoreQUOTE(CFG_VirtualKey arg){
  /* checking for: VK_BACK_QUOTE */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun46) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_BACK_SLASH by checking against the following ATerm pattern: VK_BACK_SLASH. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_BACK_SLASH, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreBACKUnderscoreSLASH(CFG_VirtualKey arg){
  /* checking for: VK_BACK_SLASH */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun47) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_BACK_SPACE by checking against the following ATerm pattern: VK_BACK_SPACE. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_BACK_SPACE, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreBACKUnderscoreSPACE(CFG_VirtualKey arg){
  /* checking for: VK_BACK_SPACE */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun48) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_BEGIN by checking against the following ATerm pattern: VK_BEGIN. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_BEGIN, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreBEGIN(CFG_VirtualKey arg){
  /* checking for: VK_BEGIN */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun49) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_BRACE_LEFT by checking against the following ATerm pattern: VK_BRACE_LEFT. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_BRACE_LEFT, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreBRACEUnderscoreLEFT(CFG_VirtualKey arg){
  /* checking for: VK_BRACE_LEFT */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun50) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_BRACE_RIGHT by checking against the following ATerm pattern: VK_BRACE_RIGHT. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_BRACE_RIGHT, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreBRACEUnderscoreRIGHT(CFG_VirtualKey arg){
  /* checking for: VK_BRACE_RIGHT */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun51) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_CIRCUMFLEX by checking against the following ATerm pattern: VK_CIRCUMFLEX. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_CIRCUMFLEX, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreCIRCUMFLEX(CFG_VirtualKey arg){
  /* checking for: VK_CIRCUMFLEX */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun52) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_CLEAR by checking against the following ATerm pattern: VK_CLEAR. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_CLEAR, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreCLEAR(CFG_VirtualKey arg){
  /* checking for: VK_CLEAR */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun53) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_CLOSE_BRACKET by checking against the following ATerm pattern: VK_CLOSE_BRACKET. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_CLOSE_BRACKET, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreCLOSEUnderscoreBRACKET(CFG_VirtualKey arg){
  /* checking for: VK_CLOSE_BRACKET */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun54) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_COLON by checking against the following ATerm pattern: VK_COLON. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_COLON, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreCOLON(CFG_VirtualKey arg){
  /* checking for: VK_COLON */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun55) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_COMMA by checking against the following ATerm pattern: VK_COMMA. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_COMMA, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreCOMMA(CFG_VirtualKey arg){
  /* checking for: VK_COMMA */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun56) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_DECIMAL by checking against the following ATerm pattern: VK_DECIMAL. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_DECIMAL, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreDECIMAL(CFG_VirtualKey arg){
  /* checking for: VK_DECIMAL */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun57) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_DELETE by checking against the following ATerm pattern: VK_DELETE. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_DELETE, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreDELETE(CFG_VirtualKey arg){
  /* checking for: VK_DELETE */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun58) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_DIVIDE by checking against the following ATerm pattern: VK_DIVIDE. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_DIVIDE, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreDIVIDE(CFG_VirtualKey arg){
  /* checking for: VK_DIVIDE */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun59) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_DOLLAR by checking against the following ATerm pattern: VK_DOLLAR. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_DOLLAR, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreDOLLAR(CFG_VirtualKey arg){
  /* checking for: VK_DOLLAR */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun60) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_DOWN by checking against the following ATerm pattern: VK_DOWN. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_DOWN, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreDOWN(CFG_VirtualKey arg){
  /* checking for: VK_DOWN */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun61) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_END by checking against the following ATerm pattern: VK_END. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_END, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreEND(CFG_VirtualKey arg){
  /* checking for: VK_END */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun62) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_ENTER by checking against the following ATerm pattern: VK_ENTER. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_ENTER, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreENTER(CFG_VirtualKey arg){
  /* checking for: VK_ENTER */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun63) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_EQUALS by checking against the following ATerm pattern: VK_EQUALS. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_EQUALS, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreEQUALS(CFG_VirtualKey arg){
  /* checking for: VK_EQUALS */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun64) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_ESCAPE by checking against the following ATerm pattern: VK_ESCAPE. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_ESCAPE, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreESCAPE(CFG_VirtualKey arg){
  /* checking for: VK_ESCAPE */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun65) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_EXCLAMATION_MARK by checking against the following ATerm pattern: VK_EXCLAMATION_MARK. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_EXCLAMATION_MARK, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreEXCLAMATIONUnderscoreMARK(CFG_VirtualKey arg){
  /* checking for: VK_EXCLAMATION_MARK */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun66) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_F1 by checking against the following ATerm pattern: VK_F1. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_F1, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreF1(CFG_VirtualKey arg){
  /* checking for: VK_F1 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun67) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_F2 by checking against the following ATerm pattern: VK_F2. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_F2, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreF2(CFG_VirtualKey arg){
  /* checking for: VK_F2 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun68) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_F3 by checking against the following ATerm pattern: VK_F3. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_F3, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreF3(CFG_VirtualKey arg){
  /* checking for: VK_F3 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun69) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_F4 by checking against the following ATerm pattern: VK_F4. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_F4, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreF4(CFG_VirtualKey arg){
  /* checking for: VK_F4 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun70) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_F5 by checking against the following ATerm pattern: VK_F5. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_F5, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreF5(CFG_VirtualKey arg){
  /* checking for: VK_F5 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun71) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_F6 by checking against the following ATerm pattern: VK_F6. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_F6, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreF6(CFG_VirtualKey arg){
  /* checking for: VK_F6 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun72) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_F7 by checking against the following ATerm pattern: VK_F7. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_F7, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreF7(CFG_VirtualKey arg){
  /* checking for: VK_F7 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun73) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_F8 by checking against the following ATerm pattern: VK_F8. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_F8, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreF8(CFG_VirtualKey arg){
  /* checking for: VK_F8 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun74) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_F9 by checking against the following ATerm pattern: VK_F9. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_F9, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreF9(CFG_VirtualKey arg){
  /* checking for: VK_F9 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun75) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_F10 by checking against the following ATerm pattern: VK_F10. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_F10, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreF10(CFG_VirtualKey arg){
  /* checking for: VK_F10 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun76) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_F11 by checking against the following ATerm pattern: VK_F11. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_F11, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreF11(CFG_VirtualKey arg){
  /* checking for: VK_F11 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun77) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_F12 by checking against the following ATerm pattern: VK_F12. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_F12, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreF12(CFG_VirtualKey arg){
  /* checking for: VK_F12 */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun78) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_GREATER by checking against the following ATerm pattern: VK_GREATER. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_GREATER, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreGREATER(CFG_VirtualKey arg){
  /* checking for: VK_GREATER */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun79) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_HOME by checking against the following ATerm pattern: VK_HOME. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_HOME, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreHOME(CFG_VirtualKey arg){
  /* checking for: VK_HOME */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun80) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_INSERT by checking against the following ATerm pattern: VK_INSERT. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_INSERT, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreINSERT(CFG_VirtualKey arg){
  /* checking for: VK_INSERT */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun81) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_LEFT by checking against the following ATerm pattern: VK_LEFT. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_LEFT, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreLEFT(CFG_VirtualKey arg){
  /* checking for: VK_LEFT */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun82) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_LEFT_PARENTHESIS by checking against the following ATerm pattern: VK_LEFT_PARENTHESIS. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_LEFT_PARENTHESIS, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreLEFTUnderscorePARENTHESIS(CFG_VirtualKey arg){
  /* checking for: VK_LEFT_PARENTHESIS */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun83) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_MINUS by checking against the following ATerm pattern: VK_MINUS. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_MINUS, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreMINUS(CFG_VirtualKey arg){
  /* checking for: VK_MINUS */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun84) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_MULTIPLY by checking against the following ATerm pattern: VK_MULTIPLY. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_MULTIPLY, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreMULTIPLY(CFG_VirtualKey arg){
  /* checking for: VK_MULTIPLY */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun85) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_NUMBER_SIGN by checking against the following ATerm pattern: VK_NUMBER_SIGN. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_NUMBER_SIGN, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreNUMBERUnderscoreSIGN(CFG_VirtualKey arg){
  /* checking for: VK_NUMBER_SIGN */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun86) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_OPEN_BRACKET by checking against the following ATerm pattern: VK_OPEN_BRACKET. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_OPEN_BRACKET, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreOPENUnderscoreBRACKET(CFG_VirtualKey arg){
  /* checking for: VK_OPEN_BRACKET */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun87) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_PAGE_DOWN by checking against the following ATerm pattern: VK_PAGE_DOWN. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_PAGE_DOWN, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscorePAGEUnderscoreDOWN(CFG_VirtualKey arg){
  /* checking for: VK_PAGE_DOWN */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun88) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_PAGE_UP by checking against the following ATerm pattern: VK_PAGE_UP. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_PAGE_UP, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscorePAGEUnderscoreUP(CFG_VirtualKey arg){
  /* checking for: VK_PAGE_UP */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun89) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_PAUSE by checking against the following ATerm pattern: VK_PAUSE. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_PAUSE, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscorePAUSE(CFG_VirtualKey arg){
  /* checking for: VK_PAUSE */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun90) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_PERIOD by checking against the following ATerm pattern: VK_PERIOD. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_PERIOD, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscorePERIOD(CFG_VirtualKey arg){
  /* checking for: VK_PERIOD */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun91) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_PLUS by checking against the following ATerm pattern: VK_PLUS. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_PLUS, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscorePLUS(CFG_VirtualKey arg){
  /* checking for: VK_PLUS */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun92) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_PRINTSCREEN by checking against the following ATerm pattern: VK_PRINTSCREEN. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_PRINTSCREEN, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscorePRINTSCREEN(CFG_VirtualKey arg){
  /* checking for: VK_PRINTSCREEN */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun93) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_QUOTE by checking against the following ATerm pattern: VK_QUOTE. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_QUOTE, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreQUOTE(CFG_VirtualKey arg){
  /* checking for: VK_QUOTE */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun94) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_QUOTEDBL by checking against the following ATerm pattern: VK_QUOTEDBL. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_QUOTEDBL, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreQUOTEDBL(CFG_VirtualKey arg){
  /* checking for: VK_QUOTEDBL */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun95) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_RIGHT by checking against the following ATerm pattern: VK_RIGHT. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_RIGHT, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreRIGHT(CFG_VirtualKey arg){
  /* checking for: VK_RIGHT */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun96) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_RIGHT_PARENTHESIS by checking against the following ATerm pattern: VK_RIGHT_PARENTHESIS. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_RIGHT_PARENTHESIS, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreRIGHTUnderscorePARENTHESIS(CFG_VirtualKey arg){
  /* checking for: VK_RIGHT_PARENTHESIS */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun97) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_SEMICOLON by checking against the following ATerm pattern: VK_SEMICOLON. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_SEMICOLON, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreSEMICOLON(CFG_VirtualKey arg){
  /* checking for: VK_SEMICOLON */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun98) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_SLASH by checking against the following ATerm pattern: VK_SLASH. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_SLASH, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreSLASH(CFG_VirtualKey arg){
  /* checking for: VK_SLASH */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun99) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_SPACE by checking against the following ATerm pattern: VK_SPACE. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_SPACE, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreSPACE(CFG_VirtualKey arg){
  /* checking for: VK_SPACE */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun100) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_SUBTRACT by checking against the following ATerm pattern: VK_SUBTRACT. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_SUBTRACT, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreSUBTRACT(CFG_VirtualKey arg){
  /* checking for: VK_SUBTRACT */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun101) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_TAB by checking against the following ATerm pattern: VK_TAB. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_TAB, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreTAB(CFG_VirtualKey arg){
  /* checking for: VK_TAB */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun102) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_UNDERSCORE by checking against the following ATerm pattern: VK_UNDERSCORE. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_UNDERSCORE, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreUNDERSCORE(CFG_VirtualKey arg){
  /* checking for: VK_UNDERSCORE */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun103) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_VirtualKey is a VK_UP by checking against the following ATerm pattern: VK_UP. May not be used to assert correctness of the CFG_VirtualKey
 * \param[in] arg input CFG_VirtualKey
 * \return ATtrue if #arg corresponds to the signature of a VK_UP, or ATfalse otherwise
 */
inline ATbool CFG_isVirtualKeyVKUnderscoreUP(CFG_VirtualKey arg){
  /* checking for: VK_UP */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun104) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Color is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_Color
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CFG_isValidColor(CFG_Color arg) {
  if (CFG_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Color is a rgb by checking against the following ATerm pattern: rgb(<"red"(int)>,<"green"(int)>,<"blue"(int)>). Always returns ATtrue
 * \param[in] arg input CFG_Color
 * \return ATtrue if #arg corresponds to the signature of a rgb, or ATfalse otherwise
 */
inline ATbool CFG_isColorRgb(CFG_Color arg){
  /* checking for: rgb */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun105) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_INT) {
      ATerm arg_arg1 = ATgetArgument(arg, 1);
      if (ATgetType((ATerm)arg_arg1) == AT_INT) {
        ATerm arg_arg2 = ATgetArgument(arg, 2);
        if (ATgetType((ATerm)arg_arg2) == AT_INT) {
          return ATtrue;
        }
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Color has a red. 
 * \param[in] arg input CFG_Color
 * \return ATtrue if the CFG_Color had a red, or ATfalse otherwise
 */
ATbool CFG_hasColorRed(CFG_Color arg) {
  if (CFG_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Color has a green. 
 * \param[in] arg input CFG_Color
 * \return ATtrue if the CFG_Color had a green, or ATfalse otherwise
 */
ATbool CFG_hasColorGreen(CFG_Color arg) {
  if (CFG_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Color has a blue. 
 * \param[in] arg input CFG_Color
 * \return ATtrue if the CFG_Color had a blue, or ATfalse otherwise
 */
ATbool CFG_hasColorBlue(CFG_Color arg) {
  if (CFG_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the red int of a CFG_Color. Note that the precondition is that this CFG_Color actually has a red
 * \param[in] arg input CFG_Color
 * \return the red of #arg, if it exist or an undefined value if it does not
 */
int CFG_getColorRed(CFG_Color arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Get the green int of a CFG_Color. Note that the precondition is that this CFG_Color actually has a green
 * \param[in] arg input CFG_Color
 * \return the green of #arg, if it exist or an undefined value if it does not
 */
int CFG_getColorGreen(CFG_Color arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the blue int of a CFG_Color. Note that the precondition is that this CFG_Color actually has a blue
 * \param[in] arg input CFG_Color
 * \return the blue of #arg, if it exist or an undefined value if it does not
 */
int CFG_getColorBlue(CFG_Color arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/**
 * Set the red of a CFG_Color. The precondition being that this CFG_Color actually has a red
 * \param[in] arg input CFG_Color
 * \param[in] red new int to set in #arg
 * \return A new CFG_Color with red at the right place, or a core dump if #arg did not have a red
 */
CFG_Color CFG_setColorRed(CFG_Color arg, int red) {
  if (CFG_isColorRgb(arg)) {
    return (CFG_Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(red)), 0);
  }

  ATabort("Color has no Red: %t\n", arg);
  return (CFG_Color)NULL;
}

/**
 * Set the green of a CFG_Color. The precondition being that this CFG_Color actually has a green
 * \param[in] arg input CFG_Color
 * \param[in] green new int to set in #arg
 * \return A new CFG_Color with green at the right place, or a core dump if #arg did not have a green
 */
CFG_Color CFG_setColorGreen(CFG_Color arg, int green) {
  if (CFG_isColorRgb(arg)) {
    return (CFG_Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(green)), 1);
  }

  ATabort("Color has no Green: %t\n", arg);
  return (CFG_Color)NULL;
}

/**
 * Set the blue of a CFG_Color. The precondition being that this CFG_Color actually has a blue
 * \param[in] arg input CFG_Color
 * \param[in] blue new int to set in #arg
 * \return A new CFG_Color with blue at the right place, or a core dump if #arg did not have a blue
 */
CFG_Color CFG_setColorBlue(CFG_Color arg, int blue) {
  if (CFG_isColorRgb(arg)) {
    return (CFG_Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(blue)), 2);
  }

  ATabort("Color has no Blue: %t\n", arg);
  return (CFG_Color)NULL;
}

/**
 * Assert whether a CFG_Configuration is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_Configuration
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CFG_isValidConfiguration(CFG_Configuration arg) {
  if (CFG_isConfigurationConfiguration(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Configuration is a configuration by checking against the following ATerm pattern: configuration(<"list"("Property-list")>). Always returns ATtrue
 * \param[in] arg input CFG_Configuration
 * \return ATtrue if #arg corresponds to the signature of a configuration, or ATfalse otherwise
 */
inline ATbool CFG_isConfigurationConfiguration(CFG_Configuration arg){
  /* checking for: configuration */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun106) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Configuration has a list. 
 * \param[in] arg input CFG_Configuration
 * \return ATtrue if the CFG_Configuration had a list, or ATfalse otherwise
 */
ATbool CFG_hasConfigurationList(CFG_Configuration arg) {
  if (CFG_isConfigurationConfiguration(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the list CFG_PropertyList of a CFG_Configuration. Note that the precondition is that this CFG_Configuration actually has a list
 * \param[in] arg input CFG_Configuration
 * \return the list of #arg, if it exist or an undefined value if it does not
 */
CFG_PropertyList CFG_getConfigurationList(CFG_Configuration arg) {
  
    return (CFG_PropertyList)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Set the list of a CFG_Configuration. The precondition being that this CFG_Configuration actually has a list
 * \param[in] arg input CFG_Configuration
 * \param[in] list new CFG_PropertyList to set in #arg
 * \return A new CFG_Configuration with list at the right place, or a core dump if #arg did not have a list
 */
CFG_Configuration CFG_setConfigurationList(CFG_Configuration arg, CFG_PropertyList list) {
  if (CFG_isConfigurationConfiguration(arg)) {
    return (CFG_Configuration)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }

  ATabort("Configuration has no List: %t\n", arg);
  return (CFG_Configuration)NULL;
}

/**
 * Assert whether a CFG_Property is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_Property
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CFG_isValidProperty(CFG_Property arg) {
  if (CFG_isPropertyImport(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyScript(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyScriptPath(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyAction(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyEditor(arg)) {
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

/**
 * Assert whether a CFG_Property is a import by checking against the following ATerm pattern: import(<"path"(str)>). May not be used to assert correctness of the CFG_Property
 * \param[in] arg input CFG_Property
 * \return ATtrue if #arg corresponds to the signature of a import, or ATfalse otherwise
 */
inline ATbool CFG_isPropertyImport(CFG_Property arg){
  /* checking for: import */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun107) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Property is a script by checking against the following ATerm pattern: script(<"path"(str)>). May not be used to assert correctness of the CFG_Property
 * \param[in] arg input CFG_Property
 * \return ATtrue if #arg corresponds to the signature of a script, or ATfalse otherwise
 */
inline ATbool CFG_isPropertyScript(CFG_Property arg){
  /* checking for: script */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun108) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Property is a script-path by checking against the following ATerm pattern: script-path(<"path"(str)>). May not be used to assert correctness of the CFG_Property
 * \param[in] arg input CFG_Property
 * \return ATtrue if #arg corresponds to the signature of a script-path, or ATfalse otherwise
 */
inline ATbool CFG_isPropertyScriptPath(CFG_Property arg){
  /* checking for: script-path */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun109) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Property is a action by checking against the following ATerm pattern: action(<"list"("ActionDescription-list")>,<"action"(str)>). May not be used to assert correctness of the CFG_Property
 * \param[in] arg input CFG_Property
 * \return ATtrue if #arg corresponds to the signature of a action, or ATfalse otherwise
 */
inline ATbool CFG_isPropertyAction(CFG_Property arg){
  /* checking for: action */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun110) {
    ATerm arg_arg1 = ATgetArgument(arg, 1);
    if (ATgetType((ATerm)arg_arg1) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg1)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg1)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Property is a editor by checking against the following ATerm pattern: editor(<"editor"(str)>,<"language"(str)>,<"extension"(str)>). May not be used to assert correctness of the CFG_Property
 * \param[in] arg input CFG_Property
 * \return ATtrue if #arg corresponds to the signature of a editor, or ATfalse otherwise
 */
inline ATbool CFG_isPropertyEditor(CFG_Property arg){
  /* checking for: editor */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun111) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      ATerm arg_arg1 = ATgetArgument(arg, 1);
      if (ATgetType((ATerm)arg_arg1) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg1)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg1)) == ATtrue) {
        ATerm arg_arg2 = ATgetArgument(arg, 2);
        if (ATgetType((ATerm)arg_arg2) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg2)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg2)) == ATtrue) {
          return ATtrue;
        }
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Property is a library-path by checking against the following ATerm pattern: library-path(<"label"(str)>,<"path"(str)>). May not be used to assert correctness of the CFG_Property
 * \param[in] arg input CFG_Property
 * \return ATtrue if #arg corresponds to the signature of a library-path, or ATfalse otherwise
 */
inline ATbool CFG_isPropertyLibraryPath(CFG_Property arg){
  /* checking for: library-path */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun112) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      ATerm arg_arg1 = ATgetArgument(arg, 1);
      if (ATgetType((ATerm)arg_arg1) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg1)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg1)) == ATtrue) {
        return ATtrue;
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Property is a module-path by checking against the following ATerm pattern: module-path(<"label"(str)>,<"path"(str)>). May not be used to assert correctness of the CFG_Property
 * \param[in] arg input CFG_Property
 * \return ATtrue if #arg corresponds to the signature of a module-path, or ATfalse otherwise
 */
inline ATbool CFG_isPropertyModulePath(CFG_Property arg){
  /* checking for: module-path */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun113) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      ATerm arg_arg1 = ATgetArgument(arg, 1);
      if (ATgetType((ATerm)arg_arg1) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg1)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg1)) == ATtrue) {
        return ATtrue;
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Property is a text-category by checking against the following ATerm pattern: text-category(<"category"("TextCategoryName")>,<"map"("TextAttribute-map")>). May not be used to assert correctness of the CFG_Property
 * \param[in] arg input CFG_Property
 * \return ATtrue if #arg corresponds to the signature of a text-category, or ATfalse otherwise
 */
inline ATbool CFG_isPropertyTextCategory(CFG_Property arg){
  /* checking for: text-category */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun114) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Property has a path. 
 * \param[in] arg input CFG_Property
 * \return ATtrue if the CFG_Property had a path, or ATfalse otherwise
 */
ATbool CFG_hasPropertyPath(CFG_Property arg) {
  if (CFG_isPropertyImport(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyScript(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyScriptPath(arg)) {
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

/**
 * Assert whether a CFG_Property has a list. 
 * \param[in] arg input CFG_Property
 * \return ATtrue if the CFG_Property had a list, or ATfalse otherwise
 */
ATbool CFG_hasPropertyList(CFG_Property arg) {
  if (CFG_isPropertyAction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Property has a action. 
 * \param[in] arg input CFG_Property
 * \return ATtrue if the CFG_Property had a action, or ATfalse otherwise
 */
ATbool CFG_hasPropertyAction(CFG_Property arg) {
  if (CFG_isPropertyAction(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Property has a editor. 
 * \param[in] arg input CFG_Property
 * \return ATtrue if the CFG_Property had a editor, or ATfalse otherwise
 */
ATbool CFG_hasPropertyEditor(CFG_Property arg) {
  if (CFG_isPropertyEditor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Property has a language. 
 * \param[in] arg input CFG_Property
 * \return ATtrue if the CFG_Property had a language, or ATfalse otherwise
 */
ATbool CFG_hasPropertyLanguage(CFG_Property arg) {
  if (CFG_isPropertyEditor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Property has a extension. 
 * \param[in] arg input CFG_Property
 * \return ATtrue if the CFG_Property had a extension, or ATfalse otherwise
 */
ATbool CFG_hasPropertyExtension(CFG_Property arg) {
  if (CFG_isPropertyEditor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Property has a label. 
 * \param[in] arg input CFG_Property
 * \return ATtrue if the CFG_Property had a label, or ATfalse otherwise
 */
ATbool CFG_hasPropertyLabel(CFG_Property arg) {
  if (CFG_isPropertyLibraryPath(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyModulePath(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Property has a category. 
 * \param[in] arg input CFG_Property
 * \return ATtrue if the CFG_Property had a category, or ATfalse otherwise
 */
ATbool CFG_hasPropertyCategory(CFG_Property arg) {
  if (CFG_isPropertyTextCategory(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Property has a map. 
 * \param[in] arg input CFG_Property
 * \return ATtrue if the CFG_Property had a map, or ATfalse otherwise
 */
ATbool CFG_hasPropertyMap(CFG_Property arg) {
  if (CFG_isPropertyTextCategory(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the path char* of a CFG_Property. Note that the precondition is that this CFG_Property actually has a path
 * \param[in] arg input CFG_Property
 * \return the path of #arg, if it exist or an undefined value if it does not
 */
char* CFG_getPropertyPath(CFG_Property arg) {
  if (CFG_isPropertyImport(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (CFG_isPropertyScript(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (CFG_isPropertyScriptPath(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (CFG_isPropertyLibraryPath(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/**
 * Get the list CFG_ActionDescriptionList of a CFG_Property. Note that the precondition is that this CFG_Property actually has a list
 * \param[in] arg input CFG_Property
 * \return the list of #arg, if it exist or an undefined value if it does not
 */
CFG_ActionDescriptionList CFG_getPropertyList(CFG_Property arg) {
  
    return (CFG_ActionDescriptionList)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the action char* of a CFG_Property. Note that the precondition is that this CFG_Property actually has a action
 * \param[in] arg input CFG_Property
 * \return the action of #arg, if it exist or an undefined value if it does not
 */
char* CFG_getPropertyAction(CFG_Property arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/**
 * Get the editor char* of a CFG_Property. Note that the precondition is that this CFG_Property actually has a editor
 * \param[in] arg input CFG_Property
 * \return the editor of #arg, if it exist or an undefined value if it does not
 */
char* CFG_getPropertyEditor(CFG_Property arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the language char* of a CFG_Property. Note that the precondition is that this CFG_Property actually has a language
 * \param[in] arg input CFG_Property
 * \return the language of #arg, if it exist or an undefined value if it does not
 */
char* CFG_getPropertyLanguage(CFG_Property arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/**
 * Get the extension char* of a CFG_Property. Note that the precondition is that this CFG_Property actually has a extension
 * \param[in] arg input CFG_Property
 * \return the extension of #arg, if it exist or an undefined value if it does not
 */
char* CFG_getPropertyExtension(CFG_Property arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 2)));
}

/**
 * Get the label char* of a CFG_Property. Note that the precondition is that this CFG_Property actually has a label
 * \param[in] arg input CFG_Property
 * \return the label of #arg, if it exist or an undefined value if it does not
 */
char* CFG_getPropertyLabel(CFG_Property arg) {
  if (CFG_isPropertyLibraryPath(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the category CFG_TextCategoryName of a CFG_Property. Note that the precondition is that this CFG_Property actually has a category
 * \param[in] arg input CFG_Property
 * \return the category of #arg, if it exist or an undefined value if it does not
 */
CFG_TextCategoryName CFG_getPropertyCategory(CFG_Property arg) {
  
    return (CFG_TextCategoryName)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the map CFG_TextAttributeMap of a CFG_Property. Note that the precondition is that this CFG_Property actually has a map
 * \param[in] arg input CFG_Property
 * \return the map of #arg, if it exist or an undefined value if it does not
 */
CFG_TextAttributeMap CFG_getPropertyMap(CFG_Property arg) {
  
    return (CFG_TextAttributeMap)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Set the path of a CFG_Property. The precondition being that this CFG_Property actually has a path
 * \param[in] arg input CFG_Property
 * \param[in] path new const char* to set in #arg
 * \return A new CFG_Property with path at the right place, or a core dump if #arg did not have a path
 */
CFG_Property CFG_setPropertyPath(CFG_Property arg, const char* path) {
  if (CFG_isPropertyImport(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 0);
  }
  else if (CFG_isPropertyScript(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 0);
  }
  else if (CFG_isPropertyScriptPath(arg)) {
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

/**
 * Set the list of a CFG_Property. The precondition being that this CFG_Property actually has a list
 * \param[in] arg input CFG_Property
 * \param[in] list new CFG_ActionDescriptionList to set in #arg
 * \return A new CFG_Property with list at the right place, or a core dump if #arg did not have a list
 */
CFG_Property CFG_setPropertyList(CFG_Property arg, CFG_ActionDescriptionList list) {
  if (CFG_isPropertyAction(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }

  ATabort("Property has no List: %t\n", arg);
  return (CFG_Property)NULL;
}

/**
 * Set the action of a CFG_Property. The precondition being that this CFG_Property actually has a action
 * \param[in] arg input CFG_Property
 * \param[in] action new const char* to set in #arg
 * \return A new CFG_Property with action at the right place, or a core dump if #arg did not have a action
 */
CFG_Property CFG_setPropertyAction(CFG_Property arg, const char* action) {
  if (CFG_isPropertyAction(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(action, 0, ATtrue))), 1);
  }

  ATabort("Property has no Action: %t\n", arg);
  return (CFG_Property)NULL;
}

/**
 * Set the editor of a CFG_Property. The precondition being that this CFG_Property actually has a editor
 * \param[in] arg input CFG_Property
 * \param[in] editor new const char* to set in #arg
 * \return A new CFG_Property with editor at the right place, or a core dump if #arg did not have a editor
 */
CFG_Property CFG_setPropertyEditor(CFG_Property arg, const char* editor) {
  if (CFG_isPropertyEditor(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(editor, 0, ATtrue))), 0);
  }

  ATabort("Property has no Editor: %t\n", arg);
  return (CFG_Property)NULL;
}

/**
 * Set the language of a CFG_Property. The precondition being that this CFG_Property actually has a language
 * \param[in] arg input CFG_Property
 * \param[in] language new const char* to set in #arg
 * \return A new CFG_Property with language at the right place, or a core dump if #arg did not have a language
 */
CFG_Property CFG_setPropertyLanguage(CFG_Property arg, const char* language) {
  if (CFG_isPropertyEditor(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(language, 0, ATtrue))), 1);
  }

  ATabort("Property has no Language: %t\n", arg);
  return (CFG_Property)NULL;
}

/**
 * Set the extension of a CFG_Property. The precondition being that this CFG_Property actually has a extension
 * \param[in] arg input CFG_Property
 * \param[in] extension new const char* to set in #arg
 * \return A new CFG_Property with extension at the right place, or a core dump if #arg did not have a extension
 */
CFG_Property CFG_setPropertyExtension(CFG_Property arg, const char* extension) {
  if (CFG_isPropertyEditor(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(extension, 0, ATtrue))), 2);
  }

  ATabort("Property has no Extension: %t\n", arg);
  return (CFG_Property)NULL;
}

/**
 * Set the label of a CFG_Property. The precondition being that this CFG_Property actually has a label
 * \param[in] arg input CFG_Property
 * \param[in] label new const char* to set in #arg
 * \return A new CFG_Property with label at the right place, or a core dump if #arg did not have a label
 */
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

/**
 * Set the category of a CFG_Property. The precondition being that this CFG_Property actually has a category
 * \param[in] arg input CFG_Property
 * \param[in] category new CFG_TextCategoryName to set in #arg
 * \return A new CFG_Property with category at the right place, or a core dump if #arg did not have a category
 */
CFG_Property CFG_setPropertyCategory(CFG_Property arg, CFG_TextCategoryName category) {
  if (CFG_isPropertyTextCategory(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) category), 0);
  }

  ATabort("Property has no Category: %t\n", arg);
  return (CFG_Property)NULL;
}

/**
 * Set the map of a CFG_Property. The precondition being that this CFG_Property actually has a map
 * \param[in] arg input CFG_Property
 * \param[in] map new CFG_TextAttributeMap to set in #arg
 * \return A new CFG_Property with map at the right place, or a core dump if #arg did not have a map
 */
CFG_Property CFG_setPropertyMap(CFG_Property arg, CFG_TextAttributeMap map) {
  if (CFG_isPropertyTextCategory(arg)) {
    return (CFG_Property)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) map), 1);
  }

  ATabort("Property has no Map: %t\n", arg);
  return (CFG_Property)NULL;
}

/**
 * Assert whether a CFG_ActionDescription is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_ActionDescription
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CFG_isValidActionDescription(CFG_ActionDescription arg) {
  if (CFG_isActionDescriptionDescription(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_ActionDescription is a description by checking against the following ATerm pattern: description(<"context"(term)>,<"event"("Event")>). Always returns ATtrue
 * \param[in] arg input CFG_ActionDescription
 * \return ATtrue if #arg corresponds to the signature of a description, or ATfalse otherwise
 */
inline ATbool CFG_isActionDescriptionDescription(CFG_ActionDescription arg){
  /* checking for: description */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun115) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (arg_arg0 != NULL) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_ActionDescription has a context. 
 * \param[in] arg input CFG_ActionDescription
 * \return ATtrue if the CFG_ActionDescription had a context, or ATfalse otherwise
 */
ATbool CFG_hasActionDescriptionContext(CFG_ActionDescription arg) {
  if (CFG_isActionDescriptionDescription(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_ActionDescription has a event. 
 * \param[in] arg input CFG_ActionDescription
 * \return ATtrue if the CFG_ActionDescription had a event, or ATfalse otherwise
 */
ATbool CFG_hasActionDescriptionEvent(CFG_ActionDescription arg) {
  if (CFG_isActionDescriptionDescription(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the context ATerm of a CFG_ActionDescription. Note that the precondition is that this CFG_ActionDescription actually has a context
 * \param[in] arg input CFG_ActionDescription
 * \return the context of #arg, if it exist or an undefined value if it does not
 */
ATerm CFG_getActionDescriptionContext(CFG_ActionDescription arg) {
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the event CFG_Event of a CFG_ActionDescription. Note that the precondition is that this CFG_ActionDescription actually has a event
 * \param[in] arg input CFG_ActionDescription
 * \return the event of #arg, if it exist or an undefined value if it does not
 */
CFG_Event CFG_getActionDescriptionEvent(CFG_ActionDescription arg) {
  
    return (CFG_Event)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Set the context of a CFG_ActionDescription. The precondition being that this CFG_ActionDescription actually has a context
 * \param[in] arg input CFG_ActionDescription
 * \param[in] context new ATerm to set in #arg
 * \return A new CFG_ActionDescription with context at the right place, or a core dump if #arg did not have a context
 */
CFG_ActionDescription CFG_setActionDescriptionContext(CFG_ActionDescription arg, ATerm context) {
  if (CFG_isActionDescriptionDescription(arg)) {
    return (CFG_ActionDescription)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) context), 0);
  }

  ATabort("ActionDescription has no Context: %t\n", arg);
  return (CFG_ActionDescription)NULL;
}

/**
 * Set the event of a CFG_ActionDescription. The precondition being that this CFG_ActionDescription actually has a event
 * \param[in] arg input CFG_ActionDescription
 * \param[in] event new CFG_Event to set in #arg
 * \return A new CFG_ActionDescription with event at the right place, or a core dump if #arg did not have a event
 */
CFG_ActionDescription CFG_setActionDescriptionEvent(CFG_ActionDescription arg, CFG_Event event) {
  if (CFG_isActionDescriptionDescription(arg)) {
    return (CFG_ActionDescription)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) event), 1);
  }

  ATabort("ActionDescription has no Event: %t\n", arg);
  return (CFG_ActionDescription)NULL;
}

/**
 * Assert whether a CFG_Event is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_Event
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CFG_isValidEvent(CFG_Event arg) {
  if (CFG_isEventPopup(arg)) {
    return ATtrue;
  }
  else if (CFG_isEventClick(arg)) {
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

/**
 * Assert whether a CFG_Event is a popup by checking against the following ATerm pattern: popup. May not be used to assert correctness of the CFG_Event
 * \param[in] arg input CFG_Event
 * \return ATtrue if #arg corresponds to the signature of a popup, or ATfalse otherwise
 */
inline ATbool CFG_isEventPopup(CFG_Event arg){
  /* checking for: popup */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun116) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Event is a click by checking against the following ATerm pattern: click(<"list"("KeyModifier-list")>,<"button"("VirtualButton")>). May not be used to assert correctness of the CFG_Event
 * \param[in] arg input CFG_Event
 * \return ATtrue if #arg corresponds to the signature of a click, or ATfalse otherwise
 */
inline ATbool CFG_isEventClick(CFG_Event arg){
  /* checking for: click */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun117) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Event is a icon by checking against the following ATerm pattern: icon(<"title"(str)>,<"path"(str)>). May not be used to assert correctness of the CFG_Event
 * \param[in] arg input CFG_Event
 * \return ATtrue if #arg corresponds to the signature of a icon, or ATfalse otherwise
 */
inline ATbool CFG_isEventIcon(CFG_Event arg){
  /* checking for: icon */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun118) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      ATerm arg_arg1 = ATgetArgument(arg, 1);
      if (ATgetType((ATerm)arg_arg1) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg1)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg1)) == ATtrue) {
        return ATtrue;
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Event is a menu by checking against the following ATerm pattern: menu(<"labels"("Item-labels")>,<"info"(str)>). May not be used to assert correctness of the CFG_Event
 * \param[in] arg input CFG_Event
 * \return ATtrue if #arg corresponds to the signature of a menu, or ATfalse otherwise
 */
inline ATbool CFG_isEventMenu(CFG_Event arg){
  /* checking for: menu */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun119) {
    ATerm arg_arg1 = ATgetArgument(arg, 1);
    if (ATgetType((ATerm)arg_arg1) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg1)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg1)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Event is a menu-shortcut by checking against the following ATerm pattern: menu-shortcut(<"labels"("Item-labels")>,<"shortcut"("ShortCut")>,<"info"(str)>). May not be used to assert correctness of the CFG_Event
 * \param[in] arg input CFG_Event
 * \return ATtrue if #arg corresponds to the signature of a menu-shortcut, or ATfalse otherwise
 */
inline ATbool CFG_isEventMenuShortcut(CFG_Event arg){
  /* checking for: menu-shortcut */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun120) {
    ATerm arg_arg2 = ATgetArgument(arg, 2);
    if (ATgetType((ATerm)arg_arg2) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg2)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg2)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Event has a list. 
 * \param[in] arg input CFG_Event
 * \return ATtrue if the CFG_Event had a list, or ATfalse otherwise
 */
ATbool CFG_hasEventList(CFG_Event arg) {
  if (CFG_isEventClick(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Event has a button. 
 * \param[in] arg input CFG_Event
 * \return ATtrue if the CFG_Event had a button, or ATfalse otherwise
 */
ATbool CFG_hasEventButton(CFG_Event arg) {
  if (CFG_isEventClick(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Event has a title. 
 * \param[in] arg input CFG_Event
 * \return ATtrue if the CFG_Event had a title, or ATfalse otherwise
 */
ATbool CFG_hasEventTitle(CFG_Event arg) {
  if (CFG_isEventIcon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Event has a path. 
 * \param[in] arg input CFG_Event
 * \return ATtrue if the CFG_Event had a path, or ATfalse otherwise
 */
ATbool CFG_hasEventPath(CFG_Event arg) {
  if (CFG_isEventIcon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Event has a labels. 
 * \param[in] arg input CFG_Event
 * \return ATtrue if the CFG_Event had a labels, or ATfalse otherwise
 */
ATbool CFG_hasEventLabels(CFG_Event arg) {
  if (CFG_isEventMenu(arg)) {
    return ATtrue;
  }
  else if (CFG_isEventMenuShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Event has a info. 
 * \param[in] arg input CFG_Event
 * \return ATtrue if the CFG_Event had a info, or ATfalse otherwise
 */
ATbool CFG_hasEventInfo(CFG_Event arg) {
  if (CFG_isEventMenu(arg)) {
    return ATtrue;
  }
  else if (CFG_isEventMenuShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Event has a shortcut. 
 * \param[in] arg input CFG_Event
 * \return ATtrue if the CFG_Event had a shortcut, or ATfalse otherwise
 */
ATbool CFG_hasEventShortcut(CFG_Event arg) {
  if (CFG_isEventMenuShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the list CFG_KeyModifierList of a CFG_Event. Note that the precondition is that this CFG_Event actually has a list
 * \param[in] arg input CFG_Event
 * \return the list of #arg, if it exist or an undefined value if it does not
 */
CFG_KeyModifierList CFG_getEventList(CFG_Event arg) {
  
    return (CFG_KeyModifierList)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the button CFG_VirtualButton of a CFG_Event. Note that the precondition is that this CFG_Event actually has a button
 * \param[in] arg input CFG_Event
 * \return the button of #arg, if it exist or an undefined value if it does not
 */
CFG_VirtualButton CFG_getEventButton(CFG_Event arg) {
  
    return (CFG_VirtualButton)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Get the title char* of a CFG_Event. Note that the precondition is that this CFG_Event actually has a title
 * \param[in] arg input CFG_Event
 * \return the title of #arg, if it exist or an undefined value if it does not
 */
char* CFG_getEventTitle(CFG_Event arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the path char* of a CFG_Event. Note that the precondition is that this CFG_Event actually has a path
 * \param[in] arg input CFG_Event
 * \return the path of #arg, if it exist or an undefined value if it does not
 */
char* CFG_getEventPath(CFG_Event arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/**
 * Get the labels CFG_ItemLabels of a CFG_Event. Note that the precondition is that this CFG_Event actually has a labels
 * \param[in] arg input CFG_Event
 * \return the labels of #arg, if it exist or an undefined value if it does not
 */
CFG_ItemLabels CFG_getEventLabels(CFG_Event arg) {
  if (CFG_isEventMenu(arg)) {
    return (CFG_ItemLabels)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (CFG_ItemLabels)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the info char* of a CFG_Event. Note that the precondition is that this CFG_Event actually has a info
 * \param[in] arg input CFG_Event
 * \return the info of #arg, if it exist or an undefined value if it does not
 */
char* CFG_getEventInfo(CFG_Event arg) {
  if (CFG_isEventMenu(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 2)));
}

/**
 * Get the shortcut CFG_ShortCut of a CFG_Event. Note that the precondition is that this CFG_Event actually has a shortcut
 * \param[in] arg input CFG_Event
 * \return the shortcut of #arg, if it exist or an undefined value if it does not
 */
CFG_ShortCut CFG_getEventShortcut(CFG_Event arg) {
  
    return (CFG_ShortCut)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Set the list of a CFG_Event. The precondition being that this CFG_Event actually has a list
 * \param[in] arg input CFG_Event
 * \param[in] list new CFG_KeyModifierList to set in #arg
 * \return A new CFG_Event with list at the right place, or a core dump if #arg did not have a list
 */
CFG_Event CFG_setEventList(CFG_Event arg, CFG_KeyModifierList list) {
  if (CFG_isEventClick(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }

  ATabort("Event has no List: %t\n", arg);
  return (CFG_Event)NULL;
}

/**
 * Set the button of a CFG_Event. The precondition being that this CFG_Event actually has a button
 * \param[in] arg input CFG_Event
 * \param[in] button new CFG_VirtualButton to set in #arg
 * \return A new CFG_Event with button at the right place, or a core dump if #arg did not have a button
 */
CFG_Event CFG_setEventButton(CFG_Event arg, CFG_VirtualButton button) {
  if (CFG_isEventClick(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) button), 1);
  }

  ATabort("Event has no Button: %t\n", arg);
  return (CFG_Event)NULL;
}

/**
 * Set the title of a CFG_Event. The precondition being that this CFG_Event actually has a title
 * \param[in] arg input CFG_Event
 * \param[in] title new const char* to set in #arg
 * \return A new CFG_Event with title at the right place, or a core dump if #arg did not have a title
 */
CFG_Event CFG_setEventTitle(CFG_Event arg, const char* title) {
  if (CFG_isEventIcon(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(title, 0, ATtrue))), 0);
  }

  ATabort("Event has no Title: %t\n", arg);
  return (CFG_Event)NULL;
}

/**
 * Set the path of a CFG_Event. The precondition being that this CFG_Event actually has a path
 * \param[in] arg input CFG_Event
 * \param[in] path new const char* to set in #arg
 * \return A new CFG_Event with path at the right place, or a core dump if #arg did not have a path
 */
CFG_Event CFG_setEventPath(CFG_Event arg, const char* path) {
  if (CFG_isEventIcon(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(path, 0, ATtrue))), 1);
  }

  ATabort("Event has no Path: %t\n", arg);
  return (CFG_Event)NULL;
}

/**
 * Set the labels of a CFG_Event. The precondition being that this CFG_Event actually has a labels
 * \param[in] arg input CFG_Event
 * \param[in] labels new CFG_ItemLabels to set in #arg
 * \return A new CFG_Event with labels at the right place, or a core dump if #arg did not have a labels
 */
CFG_Event CFG_setEventLabels(CFG_Event arg, CFG_ItemLabels labels) {
  if (CFG_isEventMenu(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) labels), 0);
  }
  else if (CFG_isEventMenuShortcut(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) labels), 0);
  }

  ATabort("Event has no Labels: %t\n", arg);
  return (CFG_Event)NULL;
}

/**
 * Set the info of a CFG_Event. The precondition being that this CFG_Event actually has a info
 * \param[in] arg input CFG_Event
 * \param[in] info new const char* to set in #arg
 * \return A new CFG_Event with info at the right place, or a core dump if #arg did not have a info
 */
CFG_Event CFG_setEventInfo(CFG_Event arg, const char* info) {
  if (CFG_isEventMenu(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(info, 0, ATtrue))), 1);
  }
  else if (CFG_isEventMenuShortcut(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(info, 0, ATtrue))), 2);
  }

  ATabort("Event has no Info: %t\n", arg);
  return (CFG_Event)NULL;
}

/**
 * Set the shortcut of a CFG_Event. The precondition being that this CFG_Event actually has a shortcut
 * \param[in] arg input CFG_Event
 * \param[in] shortcut new CFG_ShortCut to set in #arg
 * \return A new CFG_Event with shortcut at the right place, or a core dump if #arg did not have a shortcut
 */
CFG_Event CFG_setEventShortcut(CFG_Event arg, CFG_ShortCut shortcut) {
  if (CFG_isEventMenuShortcut(arg)) {
    return (CFG_Event)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) shortcut), 1);
  }

  ATabort("Event has no Shortcut: %t\n", arg);
  return (CFG_Event)NULL;
}

/**
 * Assert whether a CFG_Item is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_Item
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CFG_isValidItem(CFG_Item arg) {
  if (CFG_isItemLabel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Item is a label by checking against the following ATerm pattern: label(<"name"(str)>). Always returns ATtrue
 * \param[in] arg input CFG_Item
 * \return ATtrue if #arg corresponds to the signature of a label, or ATfalse otherwise
 */
inline ATbool CFG_isItemLabel(CFG_Item arg){
  /* checking for: label */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun121) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_Item has a name. 
 * \param[in] arg input CFG_Item
 * \return ATtrue if the CFG_Item had a name, or ATfalse otherwise
 */
ATbool CFG_hasItemName(CFG_Item arg) {
  if (CFG_isItemLabel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the name char* of a CFG_Item. Note that the precondition is that this CFG_Item actually has a name
 * \param[in] arg input CFG_Item
 * \return the name of #arg, if it exist or an undefined value if it does not
 */
char* CFG_getItemName(CFG_Item arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Set the name of a CFG_Item. The precondition being that this CFG_Item actually has a name
 * \param[in] arg input CFG_Item
 * \param[in] name new const char* to set in #arg
 * \return A new CFG_Item with name at the right place, or a core dump if #arg did not have a name
 */
CFG_Item CFG_setItemName(CFG_Item arg, const char* name) {
  if (CFG_isItemLabel(arg)) {
    return (CFG_Item)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("Item has no Name: %t\n", arg);
  return (CFG_Item)NULL;
}

/**
 * Assert whether a CFG_TextCategoryName is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_TextCategoryName
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
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

/**
 * Assert whether a CFG_TextCategoryName is a focus by checking against the following ATerm pattern: focus. May not be used to assert correctness of the CFG_TextCategoryName
 * \param[in] arg input CFG_TextCategoryName
 * \return ATtrue if #arg corresponds to the signature of a focus, or ATfalse otherwise
 */
inline ATbool CFG_isTextCategoryNameFocus(CFG_TextCategoryName arg){
  /* checking for: focus */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun122) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextCategoryName is a selection by checking against the following ATerm pattern: selection. May not be used to assert correctness of the CFG_TextCategoryName
 * \param[in] arg input CFG_TextCategoryName
 * \return ATtrue if #arg corresponds to the signature of a selection, or ATfalse otherwise
 */
inline ATbool CFG_isTextCategoryNameSelection(CFG_TextCategoryName arg){
  /* checking for: selection */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun123) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextCategoryName is a normal by checking against the following ATerm pattern: normal. May not be used to assert correctness of the CFG_TextCategoryName
 * \param[in] arg input CFG_TextCategoryName
 * \return ATtrue if #arg corresponds to the signature of a normal, or ATfalse otherwise
 */
inline ATbool CFG_isTextCategoryNameNormal(CFG_TextCategoryName arg){
  /* checking for: normal */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun124) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextCategoryName is a extern by checking against the following ATerm pattern: extern(<"name"(str)>). May not be used to assert correctness of the CFG_TextCategoryName
 * \param[in] arg input CFG_TextCategoryName
 * \return ATtrue if #arg corresponds to the signature of a extern, or ATfalse otherwise
 */
inline ATbool CFG_isTextCategoryNameExtern(CFG_TextCategoryName arg){
  /* checking for: extern */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun125) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextCategoryName has a name. 
 * \param[in] arg input CFG_TextCategoryName
 * \return ATtrue if the CFG_TextCategoryName had a name, or ATfalse otherwise
 */
ATbool CFG_hasTextCategoryNameName(CFG_TextCategoryName arg) {
  if (CFG_isTextCategoryNameExtern(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the name char* of a CFG_TextCategoryName. Note that the precondition is that this CFG_TextCategoryName actually has a name
 * \param[in] arg input CFG_TextCategoryName
 * \return the name of #arg, if it exist or an undefined value if it does not
 */
char* CFG_getTextCategoryNameName(CFG_TextCategoryName arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Set the name of a CFG_TextCategoryName. The precondition being that this CFG_TextCategoryName actually has a name
 * \param[in] arg input CFG_TextCategoryName
 * \param[in] name new const char* to set in #arg
 * \return A new CFG_TextCategoryName with name at the right place, or a core dump if #arg did not have a name
 */
CFG_TextCategoryName CFG_setTextCategoryNameName(CFG_TextCategoryName arg, const char* name) {
  if (CFG_isTextCategoryNameExtern(arg)) {
    return (CFG_TextCategoryName)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("TextCategoryName has no Name: %t\n", arg);
  return (CFG_TextCategoryName)NULL;
}

/**
 * Assert whether a CFG_TextAttribute is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_TextAttribute
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
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

/**
 * Assert whether a CFG_TextAttribute is a foreground-color by checking against the following ATerm pattern: foreground-color(<"color"("Color")>). May not be used to assert correctness of the CFG_TextAttribute
 * \param[in] arg input CFG_TextAttribute
 * \return ATtrue if #arg corresponds to the signature of a foreground-color, or ATfalse otherwise
 */
inline ATbool CFG_isTextAttributeForegroundColor(CFG_TextAttribute arg){
  /* checking for: foreground-color */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun126) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextAttribute is a background-color by checking against the following ATerm pattern: background-color(<"color"("Color")>). May not be used to assert correctness of the CFG_TextAttribute
 * \param[in] arg input CFG_TextAttribute
 * \return ATtrue if #arg corresponds to the signature of a background-color, or ATfalse otherwise
 */
inline ATbool CFG_isTextAttributeBackgroundColor(CFG_TextAttribute arg){
  /* checking for: background-color */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun127) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextAttribute is a style by checking against the following ATerm pattern: style(<"style"("TextStyle")>). May not be used to assert correctness of the CFG_TextAttribute
 * \param[in] arg input CFG_TextAttribute
 * \return ATtrue if #arg corresponds to the signature of a style, or ATfalse otherwise
 */
inline ATbool CFG_isTextAttributeStyle(CFG_TextAttribute arg){
  /* checking for: style */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun128) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextAttribute is a font by checking against the following ATerm pattern: font(<"name"(str)>). May not be used to assert correctness of the CFG_TextAttribute
 * \param[in] arg input CFG_TextAttribute
 * \return ATtrue if #arg corresponds to the signature of a font, or ATfalse otherwise
 */
inline ATbool CFG_isTextAttributeFont(CFG_TextAttribute arg){
  /* checking for: font */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun129) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextAttribute is a size by checking against the following ATerm pattern: size(<"point"(int)>). May not be used to assert correctness of the CFG_TextAttribute
 * \param[in] arg input CFG_TextAttribute
 * \return ATtrue if #arg corresponds to the signature of a size, or ATfalse otherwise
 */
inline ATbool CFG_isTextAttributeSize(CFG_TextAttribute arg){
  /* checking for: size */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun130) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_INT) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextAttribute has a color. 
 * \param[in] arg input CFG_TextAttribute
 * \return ATtrue if the CFG_TextAttribute had a color, or ATfalse otherwise
 */
ATbool CFG_hasTextAttributeColor(CFG_TextAttribute arg) {
  if (CFG_isTextAttributeForegroundColor(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextAttributeBackgroundColor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextAttribute has a style. 
 * \param[in] arg input CFG_TextAttribute
 * \return ATtrue if the CFG_TextAttribute had a style, or ATfalse otherwise
 */
ATbool CFG_hasTextAttributeStyle(CFG_TextAttribute arg) {
  if (CFG_isTextAttributeStyle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextAttribute has a name. 
 * \param[in] arg input CFG_TextAttribute
 * \return ATtrue if the CFG_TextAttribute had a name, or ATfalse otherwise
 */
ATbool CFG_hasTextAttributeName(CFG_TextAttribute arg) {
  if (CFG_isTextAttributeFont(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextAttribute has a point. 
 * \param[in] arg input CFG_TextAttribute
 * \return ATtrue if the CFG_TextAttribute had a point, or ATfalse otherwise
 */
ATbool CFG_hasTextAttributePoint(CFG_TextAttribute arg) {
  if (CFG_isTextAttributeSize(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the color CFG_Color of a CFG_TextAttribute. Note that the precondition is that this CFG_TextAttribute actually has a color
 * \param[in] arg input CFG_TextAttribute
 * \return the color of #arg, if it exist or an undefined value if it does not
 */
CFG_Color CFG_getTextAttributeColor(CFG_TextAttribute arg) {
  if (CFG_isTextAttributeForegroundColor(arg)) {
    return (CFG_Color)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (CFG_Color)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the style CFG_TextStyle of a CFG_TextAttribute. Note that the precondition is that this CFG_TextAttribute actually has a style
 * \param[in] arg input CFG_TextAttribute
 * \return the style of #arg, if it exist or an undefined value if it does not
 */
CFG_TextStyle CFG_getTextAttributeStyle(CFG_TextAttribute arg) {
  
    return (CFG_TextStyle)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the name char* of a CFG_TextAttribute. Note that the precondition is that this CFG_TextAttribute actually has a name
 * \param[in] arg input CFG_TextAttribute
 * \return the name of #arg, if it exist or an undefined value if it does not
 */
char* CFG_getTextAttributeName(CFG_TextAttribute arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the point int of a CFG_TextAttribute. Note that the precondition is that this CFG_TextAttribute actually has a point
 * \param[in] arg input CFG_TextAttribute
 * \return the point of #arg, if it exist or an undefined value if it does not
 */
int CFG_getTextAttributePoint(CFG_TextAttribute arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Set the color of a CFG_TextAttribute. The precondition being that this CFG_TextAttribute actually has a color
 * \param[in] arg input CFG_TextAttribute
 * \param[in] color new CFG_Color to set in #arg
 * \return A new CFG_TextAttribute with color at the right place, or a core dump if #arg did not have a color
 */
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

/**
 * Set the style of a CFG_TextAttribute. The precondition being that this CFG_TextAttribute actually has a style
 * \param[in] arg input CFG_TextAttribute
 * \param[in] style new CFG_TextStyle to set in #arg
 * \return A new CFG_TextAttribute with style at the right place, or a core dump if #arg did not have a style
 */
CFG_TextAttribute CFG_setTextAttributeStyle(CFG_TextAttribute arg, CFG_TextStyle style) {
  if (CFG_isTextAttributeStyle(arg)) {
    return (CFG_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) style), 0);
  }

  ATabort("TextAttribute has no Style: %t\n", arg);
  return (CFG_TextAttribute)NULL;
}

/**
 * Set the name of a CFG_TextAttribute. The precondition being that this CFG_TextAttribute actually has a name
 * \param[in] arg input CFG_TextAttribute
 * \param[in] name new const char* to set in #arg
 * \return A new CFG_TextAttribute with name at the right place, or a core dump if #arg did not have a name
 */
CFG_TextAttribute CFG_setTextAttributeName(CFG_TextAttribute arg, const char* name) {
  if (CFG_isTextAttributeFont(arg)) {
    return (CFG_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("TextAttribute has no Name: %t\n", arg);
  return (CFG_TextAttribute)NULL;
}

/**
 * Set the point of a CFG_TextAttribute. The precondition being that this CFG_TextAttribute actually has a point
 * \param[in] arg input CFG_TextAttribute
 * \param[in] point new int to set in #arg
 * \return A new CFG_TextAttribute with point at the right place, or a core dump if #arg did not have a point
 */
CFG_TextAttribute CFG_setTextAttributePoint(CFG_TextAttribute arg, int point) {
  if (CFG_isTextAttributeSize(arg)) {
    return (CFG_TextAttribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(point)), 0);
  }

  ATabort("TextAttribute has no Point: %t\n", arg);
  return (CFG_TextAttribute)NULL;
}

/**
 * Assert whether a CFG_ShortCut is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_ShortCut
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CFG_isValidShortCut(CFG_ShortCut arg) {
  if (CFG_isShortCutShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_ShortCut is a shortcut by checking against the following ATerm pattern: shortcut(<"list"("KeyModifier-list")>,<"key"("VirtualKey")>). Always returns ATtrue
 * \param[in] arg input CFG_ShortCut
 * \return ATtrue if #arg corresponds to the signature of a shortcut, or ATfalse otherwise
 */
inline ATbool CFG_isShortCutShortcut(CFG_ShortCut arg){
  /* checking for: shortcut */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun131) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_ShortCut has a list. 
 * \param[in] arg input CFG_ShortCut
 * \return ATtrue if the CFG_ShortCut had a list, or ATfalse otherwise
 */
ATbool CFG_hasShortCutList(CFG_ShortCut arg) {
  if (CFG_isShortCutShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_ShortCut has a key. 
 * \param[in] arg input CFG_ShortCut
 * \return ATtrue if the CFG_ShortCut had a key, or ATfalse otherwise
 */
ATbool CFG_hasShortCutKey(CFG_ShortCut arg) {
  if (CFG_isShortCutShortcut(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the list CFG_KeyModifierList of a CFG_ShortCut. Note that the precondition is that this CFG_ShortCut actually has a list
 * \param[in] arg input CFG_ShortCut
 * \return the list of #arg, if it exist or an undefined value if it does not
 */
CFG_KeyModifierList CFG_getShortCutList(CFG_ShortCut arg) {
  
    return (CFG_KeyModifierList)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the key CFG_VirtualKey of a CFG_ShortCut. Note that the precondition is that this CFG_ShortCut actually has a key
 * \param[in] arg input CFG_ShortCut
 * \return the key of #arg, if it exist or an undefined value if it does not
 */
CFG_VirtualKey CFG_getShortCutKey(CFG_ShortCut arg) {
  
    return (CFG_VirtualKey)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Set the list of a CFG_ShortCut. The precondition being that this CFG_ShortCut actually has a list
 * \param[in] arg input CFG_ShortCut
 * \param[in] list new CFG_KeyModifierList to set in #arg
 * \return A new CFG_ShortCut with list at the right place, or a core dump if #arg did not have a list
 */
CFG_ShortCut CFG_setShortCutList(CFG_ShortCut arg, CFG_KeyModifierList list) {
  if (CFG_isShortCutShortcut(arg)) {
    return (CFG_ShortCut)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }

  ATabort("ShortCut has no List: %t\n", arg);
  return (CFG_ShortCut)NULL;
}

/**
 * Set the key of a CFG_ShortCut. The precondition being that this CFG_ShortCut actually has a key
 * \param[in] arg input CFG_ShortCut
 * \param[in] key new CFG_VirtualKey to set in #arg
 * \return A new CFG_ShortCut with key at the right place, or a core dump if #arg did not have a key
 */
CFG_ShortCut CFG_setShortCutKey(CFG_ShortCut arg, CFG_VirtualKey key) {
  if (CFG_isShortCutShortcut(arg)) {
    return (CFG_ShortCut)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) key), 1);
  }

  ATabort("ShortCut has no Key: %t\n", arg);
  return (CFG_ShortCut)NULL;
}

/**
 * Assert whether a CFG_TextStyle is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_TextStyle
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
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

/**
 * Assert whether a CFG_TextStyle is a bold by checking against the following ATerm pattern: bold. May not be used to assert correctness of the CFG_TextStyle
 * \param[in] arg input CFG_TextStyle
 * \return ATtrue if #arg corresponds to the signature of a bold, or ATfalse otherwise
 */
inline ATbool CFG_isTextStyleBold(CFG_TextStyle arg){
  /* checking for: bold */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun132) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextStyle is a italics by checking against the following ATerm pattern: italics. May not be used to assert correctness of the CFG_TextStyle
 * \param[in] arg input CFG_TextStyle
 * \return ATtrue if #arg corresponds to the signature of a italics, or ATfalse otherwise
 */
inline ATbool CFG_isTextStyleItalics(CFG_TextStyle arg){
  /* checking for: italics */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun133) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextStyle is a underlined by checking against the following ATerm pattern: underlined. May not be used to assert correctness of the CFG_TextStyle
 * \param[in] arg input CFG_TextStyle
 * \return ATtrue if #arg corresponds to the signature of a underlined, or ATfalse otherwise
 */
inline ATbool CFG_isTextStyleUnderlined(CFG_TextStyle arg){
  /* checking for: underlined */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == CFG_afun134) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_PropertyList is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_PropertyList
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
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

/**
 * Assert whether a CFG_PropertyList is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the CFG_PropertyList
 * \param[in] arg input CFG_PropertyList
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool CFG_isPropertyListEmpty(CFG_PropertyList arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_PropertyList is a single by checking against the following ATerm pattern: [<head(Property)>]. May not be used to assert correctness of the CFG_PropertyList
 * \param[in] arg input CFG_PropertyList
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool CFG_isPropertyListSingle(CFG_PropertyList arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_PropertyList is a many by checking against the following ATerm pattern: [<head(Property)>,<[tail(Property-list)]>]. May not be used to assert correctness of the CFG_PropertyList
 * \param[in] arg input CFG_PropertyList
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool CFG_isPropertyListMany(CFG_PropertyList arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_PropertyList has a head. 
 * \param[in] arg input CFG_PropertyList
 * \return ATtrue if the CFG_PropertyList had a head, or ATfalse otherwise
 */
ATbool CFG_hasPropertyListHead(CFG_PropertyList arg) {
  if (CFG_isPropertyListSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isPropertyListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_PropertyList has a tail. 
 * \param[in] arg input CFG_PropertyList
 * \return ATtrue if the CFG_PropertyList had a tail, or ATfalse otherwise
 */
ATbool CFG_hasPropertyListTail(CFG_PropertyList arg) {
  if (CFG_isPropertyListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head CFG_Property of a CFG_PropertyList. Note that the precondition is that this CFG_PropertyList actually has a head
 * \param[in] arg input CFG_PropertyList
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
CFG_Property CFG_getPropertyListHead(CFG_PropertyList arg) {
  if (CFG_isPropertyListSingle(arg)) {
    return (CFG_Property)ATgetFirst((ATermList)arg);
  }
  else 
    return (CFG_Property)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail CFG_PropertyList of a CFG_PropertyList. Note that the precondition is that this CFG_PropertyList actually has a tail
 * \param[in] arg input CFG_PropertyList
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
CFG_PropertyList CFG_getPropertyListTail(CFG_PropertyList arg) {
  
    return (CFG_PropertyList)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a CFG_PropertyList. The precondition being that this CFG_PropertyList actually has a head
 * \param[in] arg input CFG_PropertyList
 * \param[in] head new CFG_Property to set in #arg
 * \return A new CFG_PropertyList with head at the right place, or a core dump if #arg did not have a head
 */
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

/**
 * Set the tail of a CFG_PropertyList. The precondition being that this CFG_PropertyList actually has a tail
 * \param[in] arg input CFG_PropertyList
 * \param[in] tail new CFG_PropertyList to set in #arg
 * \return A new CFG_PropertyList with tail at the right place, or a core dump if #arg did not have a tail
 */
CFG_PropertyList CFG_setPropertyListTail(CFG_PropertyList arg, CFG_PropertyList tail) {
  if (CFG_isPropertyListMany(arg)) {
    return (CFG_PropertyList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("PropertyList has no Tail: %t\n", arg);
  return (CFG_PropertyList)NULL;
}

/**
 * Assert whether a CFG_ActionDescriptionList is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_ActionDescriptionList
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
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

/**
 * Assert whether a CFG_ActionDescriptionList is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the CFG_ActionDescriptionList
 * \param[in] arg input CFG_ActionDescriptionList
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool CFG_isActionDescriptionListEmpty(CFG_ActionDescriptionList arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_ActionDescriptionList is a single by checking against the following ATerm pattern: [<head(ActionDescription)>]. May not be used to assert correctness of the CFG_ActionDescriptionList
 * \param[in] arg input CFG_ActionDescriptionList
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool CFG_isActionDescriptionListSingle(CFG_ActionDescriptionList arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_ActionDescriptionList is a many by checking against the following ATerm pattern: [<head(ActionDescription)>,<[tail(ActionDescription-list)]>]. May not be used to assert correctness of the CFG_ActionDescriptionList
 * \param[in] arg input CFG_ActionDescriptionList
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool CFG_isActionDescriptionListMany(CFG_ActionDescriptionList arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_ActionDescriptionList has a head. 
 * \param[in] arg input CFG_ActionDescriptionList
 * \return ATtrue if the CFG_ActionDescriptionList had a head, or ATfalse otherwise
 */
ATbool CFG_hasActionDescriptionListHead(CFG_ActionDescriptionList arg) {
  if (CFG_isActionDescriptionListSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isActionDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_ActionDescriptionList has a tail. 
 * \param[in] arg input CFG_ActionDescriptionList
 * \return ATtrue if the CFG_ActionDescriptionList had a tail, or ATfalse otherwise
 */
ATbool CFG_hasActionDescriptionListTail(CFG_ActionDescriptionList arg) {
  if (CFG_isActionDescriptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head CFG_ActionDescription of a CFG_ActionDescriptionList. Note that the precondition is that this CFG_ActionDescriptionList actually has a head
 * \param[in] arg input CFG_ActionDescriptionList
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
CFG_ActionDescription CFG_getActionDescriptionListHead(CFG_ActionDescriptionList arg) {
  if (CFG_isActionDescriptionListSingle(arg)) {
    return (CFG_ActionDescription)ATgetFirst((ATermList)arg);
  }
  else 
    return (CFG_ActionDescription)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail CFG_ActionDescriptionList of a CFG_ActionDescriptionList. Note that the precondition is that this CFG_ActionDescriptionList actually has a tail
 * \param[in] arg input CFG_ActionDescriptionList
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
CFG_ActionDescriptionList CFG_getActionDescriptionListTail(CFG_ActionDescriptionList arg) {
  
    return (CFG_ActionDescriptionList)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a CFG_ActionDescriptionList. The precondition being that this CFG_ActionDescriptionList actually has a head
 * \param[in] arg input CFG_ActionDescriptionList
 * \param[in] head new CFG_ActionDescription to set in #arg
 * \return A new CFG_ActionDescriptionList with head at the right place, or a core dump if #arg did not have a head
 */
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

/**
 * Set the tail of a CFG_ActionDescriptionList. The precondition being that this CFG_ActionDescriptionList actually has a tail
 * \param[in] arg input CFG_ActionDescriptionList
 * \param[in] tail new CFG_ActionDescriptionList to set in #arg
 * \return A new CFG_ActionDescriptionList with tail at the right place, or a core dump if #arg did not have a tail
 */
CFG_ActionDescriptionList CFG_setActionDescriptionListTail(CFG_ActionDescriptionList arg, CFG_ActionDescriptionList tail) {
  if (CFG_isActionDescriptionListMany(arg)) {
    return (CFG_ActionDescriptionList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("ActionDescriptionList has no Tail: %t\n", arg);
  return (CFG_ActionDescriptionList)NULL;
}

/**
 * Assert whether a CFG_TextAttributeMap is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_TextAttributeMap
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
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

/**
 * Assert whether a CFG_TextAttributeMap is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the CFG_TextAttributeMap
 * \param[in] arg input CFG_TextAttributeMap
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool CFG_isTextAttributeMapEmpty(CFG_TextAttributeMap arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextAttributeMap is a single by checking against the following ATerm pattern: [<head(TextAttribute)>]. May not be used to assert correctness of the CFG_TextAttributeMap
 * \param[in] arg input CFG_TextAttributeMap
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool CFG_isTextAttributeMapSingle(CFG_TextAttributeMap arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextAttributeMap is a many by checking against the following ATerm pattern: [<head(TextAttribute)>,<[tail(TextAttribute-map)]>]. May not be used to assert correctness of the CFG_TextAttributeMap
 * \param[in] arg input CFG_TextAttributeMap
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool CFG_isTextAttributeMapMany(CFG_TextAttributeMap arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextAttributeMap has a head. 
 * \param[in] arg input CFG_TextAttributeMap
 * \return ATtrue if the CFG_TextAttributeMap had a head, or ATfalse otherwise
 */
ATbool CFG_hasTextAttributeMapHead(CFG_TextAttributeMap arg) {
  if (CFG_isTextAttributeMapSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isTextAttributeMapMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_TextAttributeMap has a tail. 
 * \param[in] arg input CFG_TextAttributeMap
 * \return ATtrue if the CFG_TextAttributeMap had a tail, or ATfalse otherwise
 */
ATbool CFG_hasTextAttributeMapTail(CFG_TextAttributeMap arg) {
  if (CFG_isTextAttributeMapMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head CFG_TextAttribute of a CFG_TextAttributeMap. Note that the precondition is that this CFG_TextAttributeMap actually has a head
 * \param[in] arg input CFG_TextAttributeMap
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
CFG_TextAttribute CFG_getTextAttributeMapHead(CFG_TextAttributeMap arg) {
  if (CFG_isTextAttributeMapSingle(arg)) {
    return (CFG_TextAttribute)ATgetFirst((ATermList)arg);
  }
  else 
    return (CFG_TextAttribute)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail CFG_TextAttributeMap of a CFG_TextAttributeMap. Note that the precondition is that this CFG_TextAttributeMap actually has a tail
 * \param[in] arg input CFG_TextAttributeMap
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
CFG_TextAttributeMap CFG_getTextAttributeMapTail(CFG_TextAttributeMap arg) {
  
    return (CFG_TextAttributeMap)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a CFG_TextAttributeMap. The precondition being that this CFG_TextAttributeMap actually has a head
 * \param[in] arg input CFG_TextAttributeMap
 * \param[in] head new CFG_TextAttribute to set in #arg
 * \return A new CFG_TextAttributeMap with head at the right place, or a core dump if #arg did not have a head
 */
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

/**
 * Set the tail of a CFG_TextAttributeMap. The precondition being that this CFG_TextAttributeMap actually has a tail
 * \param[in] arg input CFG_TextAttributeMap
 * \param[in] tail new CFG_TextAttributeMap to set in #arg
 * \return A new CFG_TextAttributeMap with tail at the right place, or a core dump if #arg did not have a tail
 */
CFG_TextAttributeMap CFG_setTextAttributeMapTail(CFG_TextAttributeMap arg, CFG_TextAttributeMap tail) {
  if (CFG_isTextAttributeMapMany(arg)) {
    return (CFG_TextAttributeMap)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("TextAttributeMap has no Tail: %t\n", arg);
  return (CFG_TextAttributeMap)NULL;
}

/**
 * Assert whether a CFG_KeyModifierList is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_KeyModifierList
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CFG_isValidKeyModifierList(CFG_KeyModifierList arg) {
  if (CFG_isKeyModifierListEmpty(arg)) {
    return ATtrue;
  }
  else if (CFG_isKeyModifierListSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isKeyModifierListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_KeyModifierList is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the CFG_KeyModifierList
 * \param[in] arg input CFG_KeyModifierList
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool CFG_isKeyModifierListEmpty(CFG_KeyModifierList arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_KeyModifierList is a single by checking against the following ATerm pattern: [<head(KeyModifier)>]. May not be used to assert correctness of the CFG_KeyModifierList
 * \param[in] arg input CFG_KeyModifierList
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool CFG_isKeyModifierListSingle(CFG_KeyModifierList arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_KeyModifierList is a many by checking against the following ATerm pattern: [<head(KeyModifier)>,<[tail(KeyModifier-list)]>]. May not be used to assert correctness of the CFG_KeyModifierList
 * \param[in] arg input CFG_KeyModifierList
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool CFG_isKeyModifierListMany(CFG_KeyModifierList arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_KeyModifierList has a head. 
 * \param[in] arg input CFG_KeyModifierList
 * \return ATtrue if the CFG_KeyModifierList had a head, or ATfalse otherwise
 */
ATbool CFG_hasKeyModifierListHead(CFG_KeyModifierList arg) {
  if (CFG_isKeyModifierListSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isKeyModifierListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_KeyModifierList has a tail. 
 * \param[in] arg input CFG_KeyModifierList
 * \return ATtrue if the CFG_KeyModifierList had a tail, or ATfalse otherwise
 */
ATbool CFG_hasKeyModifierListTail(CFG_KeyModifierList arg) {
  if (CFG_isKeyModifierListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head CFG_KeyModifier of a CFG_KeyModifierList. Note that the precondition is that this CFG_KeyModifierList actually has a head
 * \param[in] arg input CFG_KeyModifierList
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
CFG_KeyModifier CFG_getKeyModifierListHead(CFG_KeyModifierList arg) {
  if (CFG_isKeyModifierListSingle(arg)) {
    return (CFG_KeyModifier)ATgetFirst((ATermList)arg);
  }
  else 
    return (CFG_KeyModifier)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail CFG_KeyModifierList of a CFG_KeyModifierList. Note that the precondition is that this CFG_KeyModifierList actually has a tail
 * \param[in] arg input CFG_KeyModifierList
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
CFG_KeyModifierList CFG_getKeyModifierListTail(CFG_KeyModifierList arg) {
  
    return (CFG_KeyModifierList)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a CFG_KeyModifierList. The precondition being that this CFG_KeyModifierList actually has a head
 * \param[in] arg input CFG_KeyModifierList
 * \param[in] head new CFG_KeyModifier to set in #arg
 * \return A new CFG_KeyModifierList with head at the right place, or a core dump if #arg did not have a head
 */
CFG_KeyModifierList CFG_setKeyModifierListHead(CFG_KeyModifierList arg, CFG_KeyModifier head) {
  if (CFG_isKeyModifierListSingle(arg)) {
    return (CFG_KeyModifierList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CFG_isKeyModifierListMany(arg)) {
    return (CFG_KeyModifierList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("KeyModifierList has no Head: %t\n", arg);
  return (CFG_KeyModifierList)NULL;
}

/**
 * Set the tail of a CFG_KeyModifierList. The precondition being that this CFG_KeyModifierList actually has a tail
 * \param[in] arg input CFG_KeyModifierList
 * \param[in] tail new CFG_KeyModifierList to set in #arg
 * \return A new CFG_KeyModifierList with tail at the right place, or a core dump if #arg did not have a tail
 */
CFG_KeyModifierList CFG_setKeyModifierListTail(CFG_KeyModifierList arg, CFG_KeyModifierList tail) {
  if (CFG_isKeyModifierListMany(arg)) {
    return (CFG_KeyModifierList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("KeyModifierList has no Tail: %t\n", arg);
  return (CFG_KeyModifierList)NULL;
}

/**
 * Assert whether a CFG_ItemLabels is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CFG_ItemLabels
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CFG_isValidItemLabels(CFG_ItemLabels arg) {
  if (CFG_isItemLabelsEmpty(arg)) {
    return ATtrue;
  }
  else if (CFG_isItemLabelsSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isItemLabelsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_ItemLabels is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the CFG_ItemLabels
 * \param[in] arg input CFG_ItemLabels
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool CFG_isItemLabelsEmpty(CFG_ItemLabels arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_ItemLabels is a single by checking against the following ATerm pattern: [<head(Item)>]. May not be used to assert correctness of the CFG_ItemLabels
 * \param[in] arg input CFG_ItemLabels
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool CFG_isItemLabelsSingle(CFG_ItemLabels arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    ATermList arg_list = (ATermList)arg;
    arg_list = ATgetNext(arg_list);
    if (ATgetType((ATerm)arg_list) == AT_LIST && ATisEmpty((ATermList)arg_list) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_ItemLabels is a many by checking against the following ATerm pattern: [<head(Item)>,<[tail(Item-labels)]>]. May not be used to assert correctness of the CFG_ItemLabels
 * \param[in] arg input CFG_ItemLabels
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool CFG_isItemLabelsMany(CFG_ItemLabels arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_ItemLabels has a head. 
 * \param[in] arg input CFG_ItemLabels
 * \return ATtrue if the CFG_ItemLabels had a head, or ATfalse otherwise
 */
ATbool CFG_hasItemLabelsHead(CFG_ItemLabels arg) {
  if (CFG_isItemLabelsSingle(arg)) {
    return ATtrue;
  }
  else if (CFG_isItemLabelsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CFG_ItemLabels has a tail. 
 * \param[in] arg input CFG_ItemLabels
 * \return ATtrue if the CFG_ItemLabels had a tail, or ATfalse otherwise
 */
ATbool CFG_hasItemLabelsTail(CFG_ItemLabels arg) {
  if (CFG_isItemLabelsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head CFG_Item of a CFG_ItemLabels. Note that the precondition is that this CFG_ItemLabels actually has a head
 * \param[in] arg input CFG_ItemLabels
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
CFG_Item CFG_getItemLabelsHead(CFG_ItemLabels arg) {
  if (CFG_isItemLabelsSingle(arg)) {
    return (CFG_Item)ATgetFirst((ATermList)arg);
  }
  else 
    return (CFG_Item)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail CFG_ItemLabels of a CFG_ItemLabels. Note that the precondition is that this CFG_ItemLabels actually has a tail
 * \param[in] arg input CFG_ItemLabels
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
CFG_ItemLabels CFG_getItemLabelsTail(CFG_ItemLabels arg) {
  
    return (CFG_ItemLabels)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a CFG_ItemLabels. The precondition being that this CFG_ItemLabels actually has a head
 * \param[in] arg input CFG_ItemLabels
 * \param[in] head new CFG_Item to set in #arg
 * \return A new CFG_ItemLabels with head at the right place, or a core dump if #arg did not have a head
 */
CFG_ItemLabels CFG_setItemLabelsHead(CFG_ItemLabels arg, CFG_Item head) {
  if (CFG_isItemLabelsSingle(arg)) {
    return (CFG_ItemLabels)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CFG_isItemLabelsMany(arg)) {
    return (CFG_ItemLabels)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ItemLabels has no Head: %t\n", arg);
  return (CFG_ItemLabels)NULL;
}

/**
 * Set the tail of a CFG_ItemLabels. The precondition being that this CFG_ItemLabels actually has a tail
 * \param[in] arg input CFG_ItemLabels
 * \param[in] tail new CFG_ItemLabels to set in #arg
 * \return A new CFG_ItemLabels with tail at the right place, or a core dump if #arg did not have a tail
 */
CFG_ItemLabels CFG_setItemLabelsTail(CFG_ItemLabels arg, CFG_ItemLabels tail) {
  if (CFG_isItemLabelsMany(arg)) {
    return (CFG_ItemLabels)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("ItemLabels has no Tail: %t\n", arg);
  return (CFG_ItemLabels)NULL;
}

/**
 * Apply functions to the children of a CFG_VirtualButton. 
 * \return A new CFG_VirtualButton with new children where the argument functions might have applied
 */
CFG_VirtualButton CFG_visitVirtualButton(CFG_VirtualButton arg) {
  if (CFG_isVirtualButtonNOBUTTON(arg)) {
    return CFG_makeVirtualButtonNOBUTTON();
  }
  if (CFG_isVirtualButtonBUTTON1(arg)) {
    return CFG_makeVirtualButtonBUTTON1();
  }
  if (CFG_isVirtualButtonBUTTON2(arg)) {
    return CFG_makeVirtualButtonBUTTON2();
  }
  if (CFG_isVirtualButtonBUTTON3(arg)) {
    return CFG_makeVirtualButtonBUTTON3();
  }
  ATabort("not a VirtualButton: %t\n", arg);
  return (CFG_VirtualButton)NULL;
}
/**
 * Apply functions to the children of a CFG_KeyModifier. 
 * \return A new CFG_KeyModifier with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a CFG_VirtualKey. 
 * \return A new CFG_VirtualKey with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a CFG_Color. 
 * \return A new CFG_Color with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a CFG_Configuration. 
 * \return A new CFG_Configuration with new children where the argument functions might have applied
 */
CFG_Configuration CFG_visitConfiguration(CFG_Configuration arg, CFG_PropertyList (*acceptList)(CFG_PropertyList)) {
  if (CFG_isConfigurationConfiguration(arg)) {
    return CFG_makeConfigurationConfiguration(
        acceptList ? acceptList(CFG_getConfigurationList(arg)) : CFG_getConfigurationList(arg));
  }
  ATabort("not a Configuration: %t\n", arg);
  return (CFG_Configuration)NULL;
}
/**
 * Apply functions to the children of a CFG_Property. 
 * \return A new CFG_Property with new children where the argument functions might have applied
 */
CFG_Property CFG_visitProperty(CFG_Property arg, char* (*acceptPath)(char*), CFG_ActionDescriptionList (*acceptList)(CFG_ActionDescriptionList), char* (*acceptAction)(char*), char* (*acceptEditor)(char*), char* (*acceptLanguage)(char*), char* (*acceptExtension)(char*), char* (*acceptLabel)(char*), CFG_TextCategoryName (*acceptCategory)(CFG_TextCategoryName), CFG_TextAttributeMap (*acceptMap)(CFG_TextAttributeMap)) {
  if (CFG_isPropertyImport(arg)) {
    return CFG_makePropertyImport(
        acceptPath ? acceptPath(CFG_getPropertyPath(arg)) : CFG_getPropertyPath(arg));
  }
  if (CFG_isPropertyScript(arg)) {
    return CFG_makePropertyScript(
        acceptPath ? acceptPath(CFG_getPropertyPath(arg)) : CFG_getPropertyPath(arg));
  }
  if (CFG_isPropertyScriptPath(arg)) {
    return CFG_makePropertyScriptPath(
        acceptPath ? acceptPath(CFG_getPropertyPath(arg)) : CFG_getPropertyPath(arg));
  }
  if (CFG_isPropertyAction(arg)) {
    return CFG_makePropertyAction(
        acceptList ? acceptList(CFG_getPropertyList(arg)) : CFG_getPropertyList(arg),
        acceptAction ? acceptAction(CFG_getPropertyAction(arg)) : CFG_getPropertyAction(arg));
  }
  if (CFG_isPropertyEditor(arg)) {
    return CFG_makePropertyEditor(
        acceptEditor ? acceptEditor(CFG_getPropertyEditor(arg)) : CFG_getPropertyEditor(arg),
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
/**
 * Apply functions to the children of a CFG_ActionDescription. 
 * \return A new CFG_ActionDescription with new children where the argument functions might have applied
 */
CFG_ActionDescription CFG_visitActionDescription(CFG_ActionDescription arg, ATerm (*acceptContext)(ATerm), CFG_Event (*acceptEvent)(CFG_Event)) {
  if (CFG_isActionDescriptionDescription(arg)) {
    return CFG_makeActionDescriptionDescription(
        acceptContext ? acceptContext(CFG_getActionDescriptionContext(arg)) : CFG_getActionDescriptionContext(arg),
        acceptEvent ? acceptEvent(CFG_getActionDescriptionEvent(arg)) : CFG_getActionDescriptionEvent(arg));
  }
  ATabort("not a ActionDescription: %t\n", arg);
  return (CFG_ActionDescription)NULL;
}
/**
 * Apply functions to the children of a CFG_Event. 
 * \return A new CFG_Event with new children where the argument functions might have applied
 */
CFG_Event CFG_visitEvent(CFG_Event arg, CFG_KeyModifierList (*acceptList)(CFG_KeyModifierList), CFG_VirtualButton (*acceptButton)(CFG_VirtualButton), char* (*acceptTitle)(char*), char* (*acceptPath)(char*), CFG_ItemLabels (*acceptLabels)(CFG_ItemLabels), char* (*acceptInfo)(char*), CFG_ShortCut (*acceptShortcut)(CFG_ShortCut)) {
  if (CFG_isEventPopup(arg)) {
    return CFG_makeEventPopup();
  }
  if (CFG_isEventClick(arg)) {
    return CFG_makeEventClick(
        acceptList ? acceptList(CFG_getEventList(arg)) : CFG_getEventList(arg),
        acceptButton ? acceptButton(CFG_getEventButton(arg)) : CFG_getEventButton(arg));
  }
  if (CFG_isEventIcon(arg)) {
    return CFG_makeEventIcon(
        acceptTitle ? acceptTitle(CFG_getEventTitle(arg)) : CFG_getEventTitle(arg),
        acceptPath ? acceptPath(CFG_getEventPath(arg)) : CFG_getEventPath(arg));
  }
  if (CFG_isEventMenu(arg)) {
    return CFG_makeEventMenu(
        acceptLabels ? acceptLabels(CFG_getEventLabels(arg)) : CFG_getEventLabels(arg),
        acceptInfo ? acceptInfo(CFG_getEventInfo(arg)) : CFG_getEventInfo(arg));
  }
  if (CFG_isEventMenuShortcut(arg)) {
    return CFG_makeEventMenuShortcut(
        acceptLabels ? acceptLabels(CFG_getEventLabels(arg)) : CFG_getEventLabels(arg),
        acceptShortcut ? acceptShortcut(CFG_getEventShortcut(arg)) : CFG_getEventShortcut(arg),
        acceptInfo ? acceptInfo(CFG_getEventInfo(arg)) : CFG_getEventInfo(arg));
  }
  ATabort("not a Event: %t\n", arg);
  return (CFG_Event)NULL;
}
/**
 * Apply functions to the children of a CFG_Item. 
 * \return A new CFG_Item with new children where the argument functions might have applied
 */
CFG_Item CFG_visitItem(CFG_Item arg, char* (*acceptName)(char*)) {
  if (CFG_isItemLabel(arg)) {
    return CFG_makeItemLabel(
        acceptName ? acceptName(CFG_getItemName(arg)) : CFG_getItemName(arg));
  }
  ATabort("not a Item: %t\n", arg);
  return (CFG_Item)NULL;
}
/**
 * Apply functions to the children of a CFG_TextCategoryName. 
 * \return A new CFG_TextCategoryName with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a CFG_TextAttribute. 
 * \return A new CFG_TextAttribute with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a CFG_ShortCut. 
 * \return A new CFG_ShortCut with new children where the argument functions might have applied
 */
CFG_ShortCut CFG_visitShortCut(CFG_ShortCut arg, CFG_KeyModifierList (*acceptList)(CFG_KeyModifierList), CFG_VirtualKey (*acceptKey)(CFG_VirtualKey)) {
  if (CFG_isShortCutShortcut(arg)) {
    return CFG_makeShortCutShortcut(
        acceptList ? acceptList(CFG_getShortCutList(arg)) : CFG_getShortCutList(arg),
        acceptKey ? acceptKey(CFG_getShortCutKey(arg)) : CFG_getShortCutKey(arg));
  }
  ATabort("not a ShortCut: %t\n", arg);
  return (CFG_ShortCut)NULL;
}
/**
 * Apply functions to the children of a CFG_TextStyle. 
 * \return A new CFG_TextStyle with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a CFG_PropertyList. 
 * \return A new CFG_PropertyList with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a CFG_ActionDescriptionList. 
 * \return A new CFG_ActionDescriptionList with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a CFG_TextAttributeMap. 
 * \return A new CFG_TextAttributeMap with new children where the argument functions might have applied
 */
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
/**
 * Apply functions to the children of a CFG_KeyModifierList. 
 * \return A new CFG_KeyModifierList with new children where the argument functions might have applied
 */
CFG_KeyModifierList CFG_visitKeyModifierList(CFG_KeyModifierList arg, CFG_KeyModifier (*acceptHead)(CFG_KeyModifier)) {
  if (CFG_isKeyModifierListEmpty(arg)) {
    return CFG_makeKeyModifierListEmpty();
  }
  if (CFG_isKeyModifierListSingle(arg)) {
    return CFG_makeKeyModifierListSingle(
        acceptHead ? acceptHead(CFG_getKeyModifierListHead(arg)) : CFG_getKeyModifierListHead(arg));
  }
  if (CFG_isKeyModifierListMany(arg)) {
    return CFG_makeKeyModifierListMany(
        acceptHead ? acceptHead(CFG_getKeyModifierListHead(arg)) : CFG_getKeyModifierListHead(arg),
        CFG_visitKeyModifierList(CFG_getKeyModifierListTail(arg), acceptHead));
  }
  ATabort("not a KeyModifierList: %t\n", arg);
  return (CFG_KeyModifierList)NULL;
}
/**
 * Apply functions to the children of a CFG_ItemLabels. 
 * \return A new CFG_ItemLabels with new children where the argument functions might have applied
 */
CFG_ItemLabels CFG_visitItemLabels(CFG_ItemLabels arg, CFG_Item (*acceptHead)(CFG_Item)) {
  if (CFG_isItemLabelsEmpty(arg)) {
    return CFG_makeItemLabelsEmpty();
  }
  if (CFG_isItemLabelsSingle(arg)) {
    return CFG_makeItemLabelsSingle(
        acceptHead ? acceptHead(CFG_getItemLabelsHead(arg)) : CFG_getItemLabelsHead(arg));
  }
  if (CFG_isItemLabelsMany(arg)) {
    return CFG_makeItemLabelsMany(
        acceptHead ? acceptHead(CFG_getItemLabelsHead(arg)) : CFG_getItemLabelsHead(arg),
        CFG_visitItemLabels(CFG_getItemLabelsTail(arg), acceptHead));
  }
  ATabort("not a ItemLabels: %t\n", arg);
  return (CFG_ItemLabels)NULL;
}

