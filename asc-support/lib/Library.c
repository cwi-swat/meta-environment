#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Library.h"

/**
 * Converts a string to an ATermList of integers (ASCII values). 
 * \param[in] str An ASCII string
 * \return An ATermList containing the ASCII values of #arg as ATermInts
 */
ATerm CO_stringToChars(const char *str) {
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
ATerm CO_byteToChar(char ch) {
    return (ATerm) ATmakeInt(ch);
}

/**
 * Converts a list of integers (ASCII values) to a C string. 
 * \param[in] arg An ATermList with ATermInts, such as [32,32,10]
 * \return String containing the characters from #arg as characters
 */
char *CO_charsToString(ATerm arg) {
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

char CO_charToByte(ATerm arg) {
    return (char) ATgetInt((ATermInt) arg);
}


typedef struct ATerm _CO_OptLayout;
typedef struct ATerm _CO_Layout;
typedef struct ATerm _CO_LexLayoutList;
typedef struct ATerm _CO_LexLayout;
typedef struct ATerm _CO_Start;
typedef struct ATerm _CO_LexStrChar;
typedef struct ATerm _CO_StrChar;
typedef struct ATerm _CO_LexStrCon;
typedef struct ATerm _CO_StrCon;
typedef struct ATerm _CO_LexStrCharChars;
typedef struct ATerm _CO_BoolCon;
typedef struct ATerm _CO_LexNatCon;
typedef struct ATerm _CO_NatCon;
typedef struct ATerm _CO_LexByte;
typedef struct ATerm _CO_Byte;
typedef struct ATerm _CO_LexBytes;
typedef struct ATerm _CO_Bytes;
typedef struct ATerm _CO_LexByteList;
typedef struct ATerm _CO_Subject;
typedef struct ATerm _CO_Error;
typedef struct ATerm _CO_Summary;
typedef struct ATerm _CO_SubjectList;
typedef struct ATerm _CO_ErrorList;
typedef struct ATerm _CO_Location;
typedef struct ATerm _CO_Area;
typedef struct ATerm _CO_Read;
typedef struct ATerm _CO_Write;
typedef struct ATerm _CO_ParsetreeX;
typedef struct ATerm _CO_X;
typedef struct ATerm _CO_Boolean;

/**
 * Initializes the full API. Forgetting to call this function before using the API will lead to strange behaviour. ATinit() needs to be called before this function.
 */
void CO_initLibraryApi(void) {
  init_Library_dict();
}

/**
 * Protect a CO_OptLayout from the ATerm garbage collector. Every CO_OptLayout that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_OptLayout
 */
void CO_protectOptLayout(CO_OptLayout *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_OptLayout from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_OptLayout
 */
void CO_unprotectOptLayout(CO_OptLayout *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_Layout from the ATerm garbage collector. Every CO_Layout that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_Layout
 */
void CO_protectLayout(CO_Layout *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_Layout from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_Layout
 */
void CO_unprotectLayout(CO_Layout *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_LexLayoutList from the ATerm garbage collector. Every CO_LexLayoutList that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_LexLayoutList
 */
void CO_protectLexLayoutList(CO_LexLayoutList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_LexLayoutList from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_LexLayoutList
 */
void CO_unprotectLexLayoutList(CO_LexLayoutList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_LexLayout from the ATerm garbage collector. Every CO_LexLayout that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_LexLayout
 */
void CO_protectLexLayout(CO_LexLayout *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_LexLayout from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_LexLayout
 */
void CO_unprotectLexLayout(CO_LexLayout *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_Start from the ATerm garbage collector. Every CO_Start that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_Start
 */
void CO_protectStart(CO_Start *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_Start from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_Start
 */
void CO_unprotectStart(CO_Start *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_LexStrChar from the ATerm garbage collector. Every CO_LexStrChar that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_LexStrChar
 */
void CO_protectLexStrChar(CO_LexStrChar *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_LexStrChar from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_LexStrChar
 */
void CO_unprotectLexStrChar(CO_LexStrChar *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_StrChar from the ATerm garbage collector. Every CO_StrChar that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_StrChar
 */
void CO_protectStrChar(CO_StrChar *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_StrChar from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_StrChar
 */
void CO_unprotectStrChar(CO_StrChar *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_LexStrCon from the ATerm garbage collector. Every CO_LexStrCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_LexStrCon
 */
void CO_protectLexStrCon(CO_LexStrCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_LexStrCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_LexStrCon
 */
void CO_unprotectLexStrCon(CO_LexStrCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_StrCon from the ATerm garbage collector. Every CO_StrCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_StrCon
 */
void CO_protectStrCon(CO_StrCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_StrCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_StrCon
 */
void CO_unprotectStrCon(CO_StrCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_LexStrCharChars from the ATerm garbage collector. Every CO_LexStrCharChars that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_LexStrCharChars
 */
void CO_protectLexStrCharChars(CO_LexStrCharChars *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_LexStrCharChars from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_LexStrCharChars
 */
void CO_unprotectLexStrCharChars(CO_LexStrCharChars *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_BoolCon from the ATerm garbage collector. Every CO_BoolCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_BoolCon
 */
void CO_protectBoolCon(CO_BoolCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_BoolCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_BoolCon
 */
void CO_unprotectBoolCon(CO_BoolCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_LexNatCon from the ATerm garbage collector. Every CO_LexNatCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_LexNatCon
 */
void CO_protectLexNatCon(CO_LexNatCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_LexNatCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_LexNatCon
 */
void CO_unprotectLexNatCon(CO_LexNatCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_NatCon from the ATerm garbage collector. Every CO_NatCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_NatCon
 */
void CO_protectNatCon(CO_NatCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_NatCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_NatCon
 */
void CO_unprotectNatCon(CO_NatCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_LexByte from the ATerm garbage collector. Every CO_LexByte that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_LexByte
 */
void CO_protectLexByte(CO_LexByte *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_LexByte from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_LexByte
 */
void CO_unprotectLexByte(CO_LexByte *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_Byte from the ATerm garbage collector. Every CO_Byte that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_Byte
 */
void CO_protectByte(CO_Byte *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_Byte from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_Byte
 */
void CO_unprotectByte(CO_Byte *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_LexBytes from the ATerm garbage collector. Every CO_LexBytes that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_LexBytes
 */
void CO_protectLexBytes(CO_LexBytes *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_LexBytes from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_LexBytes
 */
void CO_unprotectLexBytes(CO_LexBytes *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_Bytes from the ATerm garbage collector. Every CO_Bytes that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_Bytes
 */
void CO_protectBytes(CO_Bytes *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_Bytes from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_Bytes
 */
void CO_unprotectBytes(CO_Bytes *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_LexByteList from the ATerm garbage collector. Every CO_LexByteList that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_LexByteList
 */
void CO_protectLexByteList(CO_LexByteList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_LexByteList from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_LexByteList
 */
void CO_unprotectLexByteList(CO_LexByteList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_Subject from the ATerm garbage collector. Every CO_Subject that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_Subject
 */
void CO_protectSubject(CO_Subject *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_Subject from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_Subject
 */
void CO_unprotectSubject(CO_Subject *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_Error from the ATerm garbage collector. Every CO_Error that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_Error
 */
void CO_protectError(CO_Error *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_Error from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_Error
 */
void CO_unprotectError(CO_Error *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_Summary from the ATerm garbage collector. Every CO_Summary that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_Summary
 */
void CO_protectSummary(CO_Summary *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_Summary from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_Summary
 */
void CO_unprotectSummary(CO_Summary *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_SubjectList from the ATerm garbage collector. Every CO_SubjectList that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_SubjectList
 */
void CO_protectSubjectList(CO_SubjectList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_SubjectList from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_SubjectList
 */
void CO_unprotectSubjectList(CO_SubjectList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_ErrorList from the ATerm garbage collector. Every CO_ErrorList that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_ErrorList
 */
void CO_protectErrorList(CO_ErrorList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_ErrorList from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_ErrorList
 */
void CO_unprotectErrorList(CO_ErrorList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_Location from the ATerm garbage collector. Every CO_Location that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_Location
 */
void CO_protectLocation(CO_Location *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_Location from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_Location
 */
void CO_unprotectLocation(CO_Location *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_Area from the ATerm garbage collector. Every CO_Area that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_Area
 */
void CO_protectArea(CO_Area *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_Area from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_Area
 */
void CO_unprotectArea(CO_Area *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_Read from the ATerm garbage collector. Every CO_Read that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_Read
 */
void CO_protectRead(CO_Read *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_Read from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_Read
 */
void CO_unprotectRead(CO_Read *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_Write from the ATerm garbage collector. Every CO_Write that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_Write
 */
void CO_protectWrite(CO_Write *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_Write from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_Write
 */
void CO_unprotectWrite(CO_Write *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_ParsetreeX from the ATerm garbage collector. Every CO_ParsetreeX that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_ParsetreeX
 */
void CO_protectParsetreeX(CO_ParsetreeX *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_ParsetreeX from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_ParsetreeX
 */
void CO_unprotectParsetreeX(CO_ParsetreeX *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_X from the ATerm garbage collector. Every CO_X that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_X
 */
void CO_protectX(CO_X *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_X from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_X
 */
void CO_unprotectX(CO_X *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a CO_Boolean from the ATerm garbage collector. Every CO_Boolean that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a CO_Boolean
 */
void CO_protectBoolean(CO_Boolean *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a CO_Boolean from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a CO_Boolean
 */
void CO_unprotectBoolean(CO_Boolean *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Transforms an ATerm to a CO_OptLayout. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_OptLayout that was encoded by \arg
 */
CO_OptLayout CO_OptLayoutFromTerm(ATerm t) {
  return (CO_OptLayout)t;
}

/**
 * Transforms a CO_OptLayoutto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_OptLayout to be converted
 * \return ATerm that represents the CO_OptLayout
 */
ATerm CO_OptLayoutToTerm(CO_OptLayout arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_Layout. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_Layout that was encoded by \arg
 */
CO_Layout CO_LayoutFromTerm(ATerm t) {
  return (CO_Layout)t;
}

/**
 * Transforms a CO_Layoutto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_Layout to be converted
 * \return ATerm that represents the CO_Layout
 */
ATerm CO_LayoutToTerm(CO_Layout arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_LexLayoutList. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_LexLayoutList that was encoded by \arg
 */
CO_LexLayoutList CO_LexLayoutListFromTerm(ATerm t) {
  return (CO_LexLayoutList)t;
}

/**
 * Transforms a CO_LexLayoutListto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_LexLayoutList to be converted
 * \return ATerm that represents the CO_LexLayoutList
 */
ATerm CO_LexLayoutListToTerm(CO_LexLayoutList arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_LexLayout. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_LexLayout that was encoded by \arg
 */
CO_LexLayout CO_LexLayoutFromTerm(ATerm t) {
  return (CO_LexLayout)t;
}

/**
 * Transforms a CO_LexLayoutto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_LexLayout to be converted
 * \return ATerm that represents the CO_LexLayout
 */
ATerm CO_LexLayoutToTerm(CO_LexLayout arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_Start. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_Start that was encoded by \arg
 */
CO_Start CO_StartFromTerm(ATerm t) {
  return (CO_Start)t;
}

/**
 * Transforms a CO_Startto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_Start to be converted
 * \return ATerm that represents the CO_Start
 */
ATerm CO_StartToTerm(CO_Start arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_LexStrChar. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_LexStrChar that was encoded by \arg
 */
CO_LexStrChar CO_LexStrCharFromTerm(ATerm t) {
  return (CO_LexStrChar)t;
}

/**
 * Transforms a CO_LexStrCharto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_LexStrChar to be converted
 * \return ATerm that represents the CO_LexStrChar
 */
ATerm CO_LexStrCharToTerm(CO_LexStrChar arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_StrChar. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_StrChar that was encoded by \arg
 */
CO_StrChar CO_StrCharFromTerm(ATerm t) {
  return (CO_StrChar)t;
}

/**
 * Transforms a CO_StrCharto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_StrChar to be converted
 * \return ATerm that represents the CO_StrChar
 */
ATerm CO_StrCharToTerm(CO_StrChar arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_LexStrCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_LexStrCon that was encoded by \arg
 */
CO_LexStrCon CO_LexStrConFromTerm(ATerm t) {
  return (CO_LexStrCon)t;
}

/**
 * Transforms a CO_LexStrConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_LexStrCon to be converted
 * \return ATerm that represents the CO_LexStrCon
 */
ATerm CO_LexStrConToTerm(CO_LexStrCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_StrCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_StrCon that was encoded by \arg
 */
CO_StrCon CO_StrConFromTerm(ATerm t) {
  return (CO_StrCon)t;
}

/**
 * Transforms a CO_StrConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_StrCon to be converted
 * \return ATerm that represents the CO_StrCon
 */
ATerm CO_StrConToTerm(CO_StrCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_LexStrCharChars. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_LexStrCharChars that was encoded by \arg
 */
CO_LexStrCharChars CO_LexStrCharCharsFromTerm(ATerm t) {
  return (CO_LexStrCharChars)t;
}

/**
 * Transforms a CO_LexStrCharCharsto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_LexStrCharChars to be converted
 * \return ATerm that represents the CO_LexStrCharChars
 */
ATerm CO_LexStrCharCharsToTerm(CO_LexStrCharChars arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_BoolCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_BoolCon that was encoded by \arg
 */
CO_BoolCon CO_BoolConFromTerm(ATerm t) {
  return (CO_BoolCon)t;
}

/**
 * Transforms a CO_BoolConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_BoolCon to be converted
 * \return ATerm that represents the CO_BoolCon
 */
ATerm CO_BoolConToTerm(CO_BoolCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_LexNatCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_LexNatCon that was encoded by \arg
 */
CO_LexNatCon CO_LexNatConFromTerm(ATerm t) {
  return (CO_LexNatCon)t;
}

/**
 * Transforms a CO_LexNatConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_LexNatCon to be converted
 * \return ATerm that represents the CO_LexNatCon
 */
ATerm CO_LexNatConToTerm(CO_LexNatCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_NatCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_NatCon that was encoded by \arg
 */
CO_NatCon CO_NatConFromTerm(ATerm t) {
  return (CO_NatCon)t;
}

/**
 * Transforms a CO_NatConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_NatCon to be converted
 * \return ATerm that represents the CO_NatCon
 */
ATerm CO_NatConToTerm(CO_NatCon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_LexByte. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_LexByte that was encoded by \arg
 */
CO_LexByte CO_LexByteFromTerm(ATerm t) {
  return (CO_LexByte)t;
}

/**
 * Transforms a CO_LexByteto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_LexByte to be converted
 * \return ATerm that represents the CO_LexByte
 */
ATerm CO_LexByteToTerm(CO_LexByte arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_Byte. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_Byte that was encoded by \arg
 */
CO_Byte CO_ByteFromTerm(ATerm t) {
  return (CO_Byte)t;
}

/**
 * Transforms a CO_Byteto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_Byte to be converted
 * \return ATerm that represents the CO_Byte
 */
ATerm CO_ByteToTerm(CO_Byte arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_LexBytes. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_LexBytes that was encoded by \arg
 */
CO_LexBytes CO_LexBytesFromTerm(ATerm t) {
  return (CO_LexBytes)t;
}

/**
 * Transforms a CO_LexBytesto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_LexBytes to be converted
 * \return ATerm that represents the CO_LexBytes
 */
ATerm CO_LexBytesToTerm(CO_LexBytes arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_Bytes. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_Bytes that was encoded by \arg
 */
CO_Bytes CO_BytesFromTerm(ATerm t) {
  return (CO_Bytes)t;
}

/**
 * Transforms a CO_Bytesto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_Bytes to be converted
 * \return ATerm that represents the CO_Bytes
 */
ATerm CO_BytesToTerm(CO_Bytes arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_LexByteList. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_LexByteList that was encoded by \arg
 */
CO_LexByteList CO_LexByteListFromTerm(ATerm t) {
  return (CO_LexByteList)t;
}

/**
 * Transforms a CO_LexByteListto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_LexByteList to be converted
 * \return ATerm that represents the CO_LexByteList
 */
ATerm CO_LexByteListToTerm(CO_LexByteList arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_Subject. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_Subject that was encoded by \arg
 */
CO_Subject CO_SubjectFromTerm(ATerm t) {
  return (CO_Subject)t;
}

/**
 * Transforms a CO_Subjectto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_Subject to be converted
 * \return ATerm that represents the CO_Subject
 */
ATerm CO_SubjectToTerm(CO_Subject arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_Error. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_Error that was encoded by \arg
 */
CO_Error CO_ErrorFromTerm(ATerm t) {
  return (CO_Error)t;
}

/**
 * Transforms a CO_Errorto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_Error to be converted
 * \return ATerm that represents the CO_Error
 */
ATerm CO_ErrorToTerm(CO_Error arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_Summary. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_Summary that was encoded by \arg
 */
CO_Summary CO_SummaryFromTerm(ATerm t) {
  return (CO_Summary)t;
}

/**
 * Transforms a CO_Summaryto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_Summary to be converted
 * \return ATerm that represents the CO_Summary
 */
ATerm CO_SummaryToTerm(CO_Summary arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_SubjectList. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_SubjectList that was encoded by \arg
 */
CO_SubjectList CO_SubjectListFromTerm(ATerm t) {
  return (CO_SubjectList)t;
}

/**
 * Transforms a CO_SubjectListto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_SubjectList to be converted
 * \return ATerm that represents the CO_SubjectList
 */
ATerm CO_SubjectListToTerm(CO_SubjectList arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_ErrorList. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_ErrorList that was encoded by \arg
 */
CO_ErrorList CO_ErrorListFromTerm(ATerm t) {
  return (CO_ErrorList)t;
}

/**
 * Transforms a CO_ErrorListto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_ErrorList to be converted
 * \return ATerm that represents the CO_ErrorList
 */
ATerm CO_ErrorListToTerm(CO_ErrorList arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_Location. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_Location that was encoded by \arg
 */
CO_Location CO_LocationFromTerm(ATerm t) {
  return (CO_Location)t;
}

/**
 * Transforms a CO_Locationto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_Location to be converted
 * \return ATerm that represents the CO_Location
 */
ATerm CO_LocationToTerm(CO_Location arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_Area. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_Area that was encoded by \arg
 */
CO_Area CO_AreaFromTerm(ATerm t) {
  return (CO_Area)t;
}

/**
 * Transforms a CO_Areato an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_Area to be converted
 * \return ATerm that represents the CO_Area
 */
ATerm CO_AreaToTerm(CO_Area arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_Read. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_Read that was encoded by \arg
 */
CO_Read CO_ReadFromTerm(ATerm t) {
  return (CO_Read)t;
}

/**
 * Transforms a CO_Readto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_Read to be converted
 * \return ATerm that represents the CO_Read
 */
ATerm CO_ReadToTerm(CO_Read arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_Write. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_Write that was encoded by \arg
 */
CO_Write CO_WriteFromTerm(ATerm t) {
  return (CO_Write)t;
}

/**
 * Transforms a CO_Writeto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_Write to be converted
 * \return ATerm that represents the CO_Write
 */
ATerm CO_WriteToTerm(CO_Write arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_ParsetreeX. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_ParsetreeX that was encoded by \arg
 */
CO_ParsetreeX CO_ParsetreeXFromTerm(ATerm t) {
  return (CO_ParsetreeX)t;
}

/**
 * Transforms a CO_ParsetreeXto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_ParsetreeX to be converted
 * \return ATerm that represents the CO_ParsetreeX
 */
ATerm CO_ParsetreeXToTerm(CO_ParsetreeX arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_X. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_X that was encoded by \arg
 */
CO_X CO_XFromTerm(ATerm t) {
  return (CO_X)t;
}

/**
 * Transforms a CO_Xto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_X to be converted
 * \return ATerm that represents the CO_X
 */
ATerm CO_XToTerm(CO_X arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a CO_Boolean. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return CO_Boolean that was encoded by \arg
 */
CO_Boolean CO_BooleanFromTerm(ATerm t) {
  return (CO_Boolean)t;
}

/**
 * Transforms a CO_Booleanto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg CO_Boolean to be converted
 * \return ATerm that represents the CO_Boolean
 */
ATerm CO_BooleanToTerm(CO_Boolean arg) {
  return (ATerm)arg;
}

/**
 * Retrieve the length of a CO_LexLayoutList. 
 * \param[in] arg input CO_LexLayoutList
 * \return The number of elements in the CO_LexLayoutList
 */
int CO_getLexLayoutListLength (CO_LexLayoutList arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a CO_LexLayoutList. 
 * \param[in] arg CO_LexLayoutList to be reversed
 * \return a reversed #arg
 */
CO_LexLayoutList CO_reverseLexLayoutList(CO_LexLayoutList arg) {
  return (CO_LexLayoutList) ATreverse((ATermList) arg);
}

/**
 * Append a CO_LexLayout to the end of a CO_LexLayoutList. 
 * \param[in] arg CO_LexLayoutList to append the CO_LexLayout to
 * \param[in] elem CO_LexLayout to be appended
 * \return new CO_LexLayoutList with #elem appended
 */
CO_LexLayoutList CO_appendLexLayoutList(CO_LexLayoutList arg, CO_LexLayout elem) {
  return (CO_LexLayoutList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two CO_LexLayoutLists. 
 * \param[in] arg0 first CO_LexLayoutList
 * \param[in] arg1 second CO_LexLayoutList
 * \return CO_LexLayoutList with the elements of #arg0 before the elements of #arg1
 */
CO_LexLayoutList CO_concatLexLayoutList(CO_LexLayoutList arg0, CO_LexLayoutList arg1) {
  return (CO_LexLayoutList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a CO_LexLayoutList. 
 * \param[in] arg CO_LexLayoutList to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new CO_LexLayoutList with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
CO_LexLayoutList CO_sliceLexLayoutList(CO_LexLayoutList arg, int start, int end) {
  return (CO_LexLayoutList) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the CO_LexLayout at #index from a CO_LexLayoutList. 
 * \param[in] arg CO_LexLayoutList to retrieve the CO_LexLayout from
 * \param[in] index index to use to point in the CO_LexLayoutList
 * \return CO_LexLayout at position #index in #arg
 */
CO_LexLayout CO_getLexLayoutListLexLayoutAt(CO_LexLayoutList arg, int index) {
 return (CO_LexLayout)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the CO_LexLayout at #index from a CO_LexLayoutList by a new one. 
 * \param[in] arg CO_LexLayoutList to retrieve the CO_LexLayout from
 * \param[in] elem new CO_LexLayout to replace another
 * \param[in] index index to use to point in the CO_LexLayoutList
 * \return A new CO_LexLayoutListwith #elem replaced in #arg at position #index
 */
CO_LexLayoutList CO_replaceLexLayoutListLexLayoutAt(CO_LexLayoutList arg, CO_LexLayout elem, int index) {
 return (CO_LexLayoutList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a CO_LexLayoutList of 2 consecutive elements. 
 * \param[in] elem1 One CO_LexLayout element of the new CO_LexLayoutList
 * \param[in] elem2 One CO_LexLayout element of the new CO_LexLayoutList
 * \return A new CO_LexLayoutList consisting of 2 CO_LexLayouts
 */
CO_LexLayoutList CO_makeLexLayoutList2(CO_LexLayout elem1, CO_LexLayout elem2) {
  return (CO_LexLayoutList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a CO_LexLayoutList of 3 consecutive elements. 
 * \param[in] elem1 One CO_LexLayout element of the new CO_LexLayoutList
 * \param[in] elem2 One CO_LexLayout element of the new CO_LexLayoutList
 * \param[in] elem3 One CO_LexLayout element of the new CO_LexLayoutList
 * \return A new CO_LexLayoutList consisting of 3 CO_LexLayouts
 */
CO_LexLayoutList CO_makeLexLayoutList3(CO_LexLayout elem1, CO_LexLayout elem2, CO_LexLayout elem3) {
  return (CO_LexLayoutList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a CO_LexLayoutList of 4 consecutive elements. 
 * \param[in] elem1 One CO_LexLayout element of the new CO_LexLayoutList
 * \param[in] elem2 One CO_LexLayout element of the new CO_LexLayoutList
 * \param[in] elem3 One CO_LexLayout element of the new CO_LexLayoutList
 * \param[in] elem4 One CO_LexLayout element of the new CO_LexLayoutList
 * \return A new CO_LexLayoutList consisting of 4 CO_LexLayouts
 */
CO_LexLayoutList CO_makeLexLayoutList4(CO_LexLayout elem1, CO_LexLayout elem2, CO_LexLayout elem3, CO_LexLayout elem4) {
  return (CO_LexLayoutList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a CO_LexLayoutList of 5 consecutive elements. 
 * \param[in] elem1 One CO_LexLayout element of the new CO_LexLayoutList
 * \param[in] elem2 One CO_LexLayout element of the new CO_LexLayoutList
 * \param[in] elem3 One CO_LexLayout element of the new CO_LexLayoutList
 * \param[in] elem4 One CO_LexLayout element of the new CO_LexLayoutList
 * \param[in] elem5 One CO_LexLayout element of the new CO_LexLayoutList
 * \return A new CO_LexLayoutList consisting of 5 CO_LexLayouts
 */
CO_LexLayoutList CO_makeLexLayoutList5(CO_LexLayout elem1, CO_LexLayout elem2, CO_LexLayout elem3, CO_LexLayout elem4, CO_LexLayout elem5) {
  return (CO_LexLayoutList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a CO_LexLayoutList of 6 consecutive elements. 
 * \param[in] elem1 One CO_LexLayout element of the new CO_LexLayoutList
 * \param[in] elem2 One CO_LexLayout element of the new CO_LexLayoutList
 * \param[in] elem3 One CO_LexLayout element of the new CO_LexLayoutList
 * \param[in] elem4 One CO_LexLayout element of the new CO_LexLayoutList
 * \param[in] elem5 One CO_LexLayout element of the new CO_LexLayoutList
 * \param[in] elem6 One CO_LexLayout element of the new CO_LexLayoutList
 * \return A new CO_LexLayoutList consisting of 6 CO_LexLayouts
 */
CO_LexLayoutList CO_makeLexLayoutList6(CO_LexLayout elem1, CO_LexLayout elem2, CO_LexLayout elem3, CO_LexLayout elem4, CO_LexLayout elem5, CO_LexLayout elem6) {
  return (CO_LexLayoutList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a CO_LexStrCharChars. 
 * \param[in] arg input CO_LexStrCharChars
 * \return The number of elements in the CO_LexStrCharChars
 */
int CO_getLexStrCharCharsLength (CO_LexStrCharChars arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a CO_LexStrCharChars. 
 * \param[in] arg CO_LexStrCharChars to be reversed
 * \return a reversed #arg
 */
CO_LexStrCharChars CO_reverseLexStrCharChars(CO_LexStrCharChars arg) {
  return (CO_LexStrCharChars) ATreverse((ATermList) arg);
}

/**
 * Append a CO_LexStrChar to the end of a CO_LexStrCharChars. 
 * \param[in] arg CO_LexStrCharChars to append the CO_LexStrChar to
 * \param[in] elem CO_LexStrChar to be appended
 * \return new CO_LexStrCharChars with #elem appended
 */
CO_LexStrCharChars CO_appendLexStrCharChars(CO_LexStrCharChars arg, CO_LexStrChar elem) {
  return (CO_LexStrCharChars) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two CO_LexStrCharCharss. 
 * \param[in] arg0 first CO_LexStrCharChars
 * \param[in] arg1 second CO_LexStrCharChars
 * \return CO_LexStrCharChars with the elements of #arg0 before the elements of #arg1
 */
CO_LexStrCharChars CO_concatLexStrCharChars(CO_LexStrCharChars arg0, CO_LexStrCharChars arg1) {
  return (CO_LexStrCharChars) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a CO_LexStrCharChars. 
 * \param[in] arg CO_LexStrCharChars to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new CO_LexStrCharChars with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
CO_LexStrCharChars CO_sliceLexStrCharChars(CO_LexStrCharChars arg, int start, int end) {
  return (CO_LexStrCharChars) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the CO_LexStrChar at #index from a CO_LexStrCharChars. 
 * \param[in] arg CO_LexStrCharChars to retrieve the CO_LexStrChar from
 * \param[in] index index to use to point in the CO_LexStrCharChars
 * \return CO_LexStrChar at position #index in #arg
 */
CO_LexStrChar CO_getLexStrCharCharsLexStrCharAt(CO_LexStrCharChars arg, int index) {
 return (CO_LexStrChar)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the CO_LexStrChar at #index from a CO_LexStrCharChars by a new one. 
 * \param[in] arg CO_LexStrCharChars to retrieve the CO_LexStrChar from
 * \param[in] elem new CO_LexStrChar to replace another
 * \param[in] index index to use to point in the CO_LexStrCharChars
 * \return A new CO_LexStrCharCharswith #elem replaced in #arg at position #index
 */
CO_LexStrCharChars CO_replaceLexStrCharCharsLexStrCharAt(CO_LexStrCharChars arg, CO_LexStrChar elem, int index) {
 return (CO_LexStrCharChars) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a CO_LexStrCharChars of 2 consecutive elements. 
 * \param[in] elem1 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \param[in] elem2 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \return A new CO_LexStrCharChars consisting of 2 CO_LexStrChars
 */
CO_LexStrCharChars CO_makeLexStrCharChars2(CO_LexStrChar elem1, CO_LexStrChar elem2) {
  return (CO_LexStrCharChars) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a CO_LexStrCharChars of 3 consecutive elements. 
 * \param[in] elem1 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \param[in] elem2 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \param[in] elem3 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \return A new CO_LexStrCharChars consisting of 3 CO_LexStrChars
 */
CO_LexStrCharChars CO_makeLexStrCharChars3(CO_LexStrChar elem1, CO_LexStrChar elem2, CO_LexStrChar elem3) {
  return (CO_LexStrCharChars) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a CO_LexStrCharChars of 4 consecutive elements. 
 * \param[in] elem1 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \param[in] elem2 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \param[in] elem3 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \param[in] elem4 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \return A new CO_LexStrCharChars consisting of 4 CO_LexStrChars
 */
CO_LexStrCharChars CO_makeLexStrCharChars4(CO_LexStrChar elem1, CO_LexStrChar elem2, CO_LexStrChar elem3, CO_LexStrChar elem4) {
  return (CO_LexStrCharChars) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a CO_LexStrCharChars of 5 consecutive elements. 
 * \param[in] elem1 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \param[in] elem2 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \param[in] elem3 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \param[in] elem4 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \param[in] elem5 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \return A new CO_LexStrCharChars consisting of 5 CO_LexStrChars
 */
CO_LexStrCharChars CO_makeLexStrCharChars5(CO_LexStrChar elem1, CO_LexStrChar elem2, CO_LexStrChar elem3, CO_LexStrChar elem4, CO_LexStrChar elem5) {
  return (CO_LexStrCharChars) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a CO_LexStrCharChars of 6 consecutive elements. 
 * \param[in] elem1 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \param[in] elem2 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \param[in] elem3 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \param[in] elem4 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \param[in] elem5 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \param[in] elem6 One CO_LexStrChar element of the new CO_LexStrCharChars
 * \return A new CO_LexStrCharChars consisting of 6 CO_LexStrChars
 */
CO_LexStrCharChars CO_makeLexStrCharChars6(CO_LexStrChar elem1, CO_LexStrChar elem2, CO_LexStrChar elem3, CO_LexStrChar elem4, CO_LexStrChar elem5, CO_LexStrChar elem6) {
  return (CO_LexStrCharChars) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a CO_LexByteList. 
 * \param[in] arg input CO_LexByteList
 * \return The number of elements in the CO_LexByteList
 */
int CO_getLexByteListLength (CO_LexByteList arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a CO_LexByteList. 
 * \param[in] arg CO_LexByteList to be reversed
 * \return a reversed #arg
 */
CO_LexByteList CO_reverseLexByteList(CO_LexByteList arg) {
  return (CO_LexByteList) ATreverse((ATermList) arg);
}

/**
 * Append a CO_LexByte to the end of a CO_LexByteList. 
 * \param[in] arg CO_LexByteList to append the CO_LexByte to
 * \param[in] elem CO_LexByte to be appended
 * \return new CO_LexByteList with #elem appended
 */
CO_LexByteList CO_appendLexByteList(CO_LexByteList arg, CO_LexByte elem) {
  return (CO_LexByteList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two CO_LexByteLists. 
 * \param[in] arg0 first CO_LexByteList
 * \param[in] arg1 second CO_LexByteList
 * \return CO_LexByteList with the elements of #arg0 before the elements of #arg1
 */
CO_LexByteList CO_concatLexByteList(CO_LexByteList arg0, CO_LexByteList arg1) {
  return (CO_LexByteList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a CO_LexByteList. 
 * \param[in] arg CO_LexByteList to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new CO_LexByteList with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
CO_LexByteList CO_sliceLexByteList(CO_LexByteList arg, int start, int end) {
  return (CO_LexByteList) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the CO_LexByte at #index from a CO_LexByteList. 
 * \param[in] arg CO_LexByteList to retrieve the CO_LexByte from
 * \param[in] index index to use to point in the CO_LexByteList
 * \return CO_LexByte at position #index in #arg
 */
CO_LexByte CO_getLexByteListLexByteAt(CO_LexByteList arg, int index) {
 return (CO_LexByte)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the CO_LexByte at #index from a CO_LexByteList by a new one. 
 * \param[in] arg CO_LexByteList to retrieve the CO_LexByte from
 * \param[in] elem new CO_LexByte to replace another
 * \param[in] index index to use to point in the CO_LexByteList
 * \return A new CO_LexByteListwith #elem replaced in #arg at position #index
 */
CO_LexByteList CO_replaceLexByteListLexByteAt(CO_LexByteList arg, CO_LexByte elem, int index) {
 return (CO_LexByteList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a CO_LexByteList of 2 consecutive elements. 
 * \param[in] elem1 One CO_LexByte element of the new CO_LexByteList
 * \param[in] elem2 One CO_LexByte element of the new CO_LexByteList
 * \return A new CO_LexByteList consisting of 2 CO_LexBytes
 */
CO_LexByteList CO_makeLexByteList2(CO_LexByte elem1, CO_LexByte elem2) {
  return (CO_LexByteList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a CO_LexByteList of 3 consecutive elements. 
 * \param[in] elem1 One CO_LexByte element of the new CO_LexByteList
 * \param[in] elem2 One CO_LexByte element of the new CO_LexByteList
 * \param[in] elem3 One CO_LexByte element of the new CO_LexByteList
 * \return A new CO_LexByteList consisting of 3 CO_LexBytes
 */
CO_LexByteList CO_makeLexByteList3(CO_LexByte elem1, CO_LexByte elem2, CO_LexByte elem3) {
  return (CO_LexByteList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a CO_LexByteList of 4 consecutive elements. 
 * \param[in] elem1 One CO_LexByte element of the new CO_LexByteList
 * \param[in] elem2 One CO_LexByte element of the new CO_LexByteList
 * \param[in] elem3 One CO_LexByte element of the new CO_LexByteList
 * \param[in] elem4 One CO_LexByte element of the new CO_LexByteList
 * \return A new CO_LexByteList consisting of 4 CO_LexBytes
 */
CO_LexByteList CO_makeLexByteList4(CO_LexByte elem1, CO_LexByte elem2, CO_LexByte elem3, CO_LexByte elem4) {
  return (CO_LexByteList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a CO_LexByteList of 5 consecutive elements. 
 * \param[in] elem1 One CO_LexByte element of the new CO_LexByteList
 * \param[in] elem2 One CO_LexByte element of the new CO_LexByteList
 * \param[in] elem3 One CO_LexByte element of the new CO_LexByteList
 * \param[in] elem4 One CO_LexByte element of the new CO_LexByteList
 * \param[in] elem5 One CO_LexByte element of the new CO_LexByteList
 * \return A new CO_LexByteList consisting of 5 CO_LexBytes
 */
CO_LexByteList CO_makeLexByteList5(CO_LexByte elem1, CO_LexByte elem2, CO_LexByte elem3, CO_LexByte elem4, CO_LexByte elem5) {
  return (CO_LexByteList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a CO_LexByteList of 6 consecutive elements. 
 * \param[in] elem1 One CO_LexByte element of the new CO_LexByteList
 * \param[in] elem2 One CO_LexByte element of the new CO_LexByteList
 * \param[in] elem3 One CO_LexByte element of the new CO_LexByteList
 * \param[in] elem4 One CO_LexByte element of the new CO_LexByteList
 * \param[in] elem5 One CO_LexByte element of the new CO_LexByteList
 * \param[in] elem6 One CO_LexByte element of the new CO_LexByteList
 * \return A new CO_LexByteList consisting of 6 CO_LexBytes
 */
CO_LexByteList CO_makeLexByteList6(CO_LexByte elem1, CO_LexByte elem2, CO_LexByte elem3, CO_LexByte elem4, CO_LexByte elem5, CO_LexByte elem6) {
  return (CO_LexByteList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the number of elements in a CO_SubjectList. 
 * \param[in] arg input CO_SubjectList
 * \return The number of elements in #arg, excluding any separators
 */
int CO_getSubjectListLength (CO_SubjectList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}

/**
 * Reverses the elements of a CO_SubjectList. Note that separators are reversed with the list, but the order in which each set of separators inbetween two elements occurs does not change
 * \param[in] arg CO_SubjectList to be reversed
 * \return #arg reversed
 */
CO_SubjectList CO_reverseSubjectList(CO_SubjectList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (CO_SubjectList) result;
}

/**
 * Append a CO_Subject to the end of a CO_SubjectList. 
 * \param[in] arg CO_SubjectList to append the CO_Subject to
 * \param[in] elem CO_Subject to be appended
 * \return new CO_SubjectList with #elem appended after the separators
 */
CO_SubjectList CO_appendSubjectList(CO_SubjectList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject arg1) {
  return CO_concatSubjectList(arg0, wsAfterHead, wsAfterSep, CO_makeSubjectListSingle(arg1));
}

/**
 * Concatenate two CO_SubjectLists. 
 * \param[in] arg0 first CO_SubjectList
 * \param[in] arg1 second CO_SubjectList
 * \return CO_SubjectList with the elements of #arg0 before the elements of #arg1, with the separators in between.
 */
CO_SubjectList CO_concatSubjectList(CO_SubjectList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_SubjectList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = CO_makeSubjectListMany((CO_Subject)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (CO_SubjectList) ATgetNext((ATermList) arg1);
  return (CO_SubjectList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a CO_SubjectList. 
 * \param[in] arg CO_SubjectList to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new CO_SubjectList with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
CO_SubjectList CO_sliceSubjectList(CO_SubjectList arg, int start, int end) {
  return (CO_SubjectList) ATgetSlice((ATermList) arg, start * 4, end * 4);
}

/**
 * Retrieve the CO_Subject at #index from a CO_SubjectList. 
 * \param[in] arg CO_SubjectList to retrieve the CO_Subject from
 * \param[in] index index to use to point in the CO_SubjectList
 * \return CO_Subject at position #index in #arg
 */
CO_Subject CO_getSubjectListSubjectAt(CO_SubjectList arg, int index) {
 return (CO_Subject)ATelementAt((ATermList) arg,index * 4);
}

/**
 * Replace the CO_Subject at #index from a CO_SubjectList by a new one. 
 * \param[in] arg CO_SubjectList to retrieve the CO_Subject from
 * \param[in] elem new CO_Subject to replace another
 * \param[in] index index to use to point in the CO_SubjectList
 * \return A new CO_SubjectListwith #elem replaced in #arg at position #index
 */
CO_SubjectList CO_replaceSubjectListSubjectAt(CO_SubjectList arg, CO_Subject elem, int index) {
 return (CO_SubjectList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}

/**
 * Builds a CO_SubjectList of 2 consecutive elements. The elements are separated.
 * \param[in] elem1 One CO_Subject element of the new CO_SubjectList
 * \param[in] elem2 One CO_Subject element of the new CO_SubjectList
 * \return A new CO_SubjectList consisting of 2 CO_Subjects
 */
CO_SubjectList CO_makeSubjectList2(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2) {
  return CO_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, CO_makeSubjectListSingle(elem2));
}

/**
 * Builds a CO_SubjectList of 3 consecutive elements. The elements are separated.
 * \param[in] elem1 One CO_Subject element of the new CO_SubjectList
 * \param[in] elem2 One CO_Subject element of the new CO_SubjectList
 * \param[in] elem3 One CO_Subject element of the new CO_SubjectList
 * \return A new CO_SubjectList consisting of 3 CO_Subjects
 */
CO_SubjectList CO_makeSubjectList3(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3) {
  return CO_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, CO_makeSubjectList2(wsAfterHead, wsAfterSep, elem2, elem3));
}

/**
 * Builds a CO_SubjectList of 4 consecutive elements. The elements are separated.
 * \param[in] elem1 One CO_Subject element of the new CO_SubjectList
 * \param[in] elem2 One CO_Subject element of the new CO_SubjectList
 * \param[in] elem3 One CO_Subject element of the new CO_SubjectList
 * \param[in] elem4 One CO_Subject element of the new CO_SubjectList
 * \return A new CO_SubjectList consisting of 4 CO_Subjects
 */
CO_SubjectList CO_makeSubjectList4(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3, CO_Subject elem4) {
  return CO_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, CO_makeSubjectList3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}

/**
 * Builds a CO_SubjectList of 5 consecutive elements. The elements are separated.
 * \param[in] elem1 One CO_Subject element of the new CO_SubjectList
 * \param[in] elem2 One CO_Subject element of the new CO_SubjectList
 * \param[in] elem3 One CO_Subject element of the new CO_SubjectList
 * \param[in] elem4 One CO_Subject element of the new CO_SubjectList
 * \param[in] elem5 One CO_Subject element of the new CO_SubjectList
 * \return A new CO_SubjectList consisting of 5 CO_Subjects
 */
CO_SubjectList CO_makeSubjectList5(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3, CO_Subject elem4, CO_Subject elem5) {
  return CO_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, CO_makeSubjectList4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}

/**
 * Builds a CO_SubjectList of 6 consecutive elements. The elements are separated.
 * \param[in] elem1 One CO_Subject element of the new CO_SubjectList
 * \param[in] elem2 One CO_Subject element of the new CO_SubjectList
 * \param[in] elem3 One CO_Subject element of the new CO_SubjectList
 * \param[in] elem4 One CO_Subject element of the new CO_SubjectList
 * \param[in] elem5 One CO_Subject element of the new CO_SubjectList
 * \param[in] elem6 One CO_Subject element of the new CO_SubjectList
 * \return A new CO_SubjectList consisting of 6 CO_Subjects
 */
CO_SubjectList CO_makeSubjectList6(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3, CO_Subject elem4, CO_Subject elem5, CO_Subject elem6) {
  return CO_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, CO_makeSubjectList5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}

/**
 * Retrieve the number of elements in a CO_ErrorList. 
 * \param[in] arg input CO_ErrorList
 * \return The number of elements in #arg, excluding any separators
 */
int CO_getErrorListLength (CO_ErrorList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}

/**
 * Reverses the elements of a CO_ErrorList. Note that separators are reversed with the list, but the order in which each set of separators inbetween two elements occurs does not change
 * \param[in] arg CO_ErrorList to be reversed
 * \return #arg reversed
 */
CO_ErrorList CO_reverseErrorList(CO_ErrorList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (CO_ErrorList) result;
}

/**
 * Append a CO_Error to the end of a CO_ErrorList. 
 * \param[in] arg CO_ErrorList to append the CO_Error to
 * \param[in] elem CO_Error to be appended
 * \return new CO_ErrorList with #elem appended after the separators
 */
CO_ErrorList CO_appendErrorList(CO_ErrorList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error arg1) {
  return CO_concatErrorList(arg0, wsAfterHead, wsAfterSep, CO_makeErrorListSingle(arg1));
}

/**
 * Concatenate two CO_ErrorLists. 
 * \param[in] arg0 first CO_ErrorList
 * \param[in] arg1 second CO_ErrorList
 * \return CO_ErrorList with the elements of #arg0 before the elements of #arg1, with the separators in between.
 */
CO_ErrorList CO_concatErrorList(CO_ErrorList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_ErrorList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = CO_makeErrorListMany((CO_Error)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (CO_ErrorList) ATgetNext((ATermList) arg1);
  return (CO_ErrorList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a CO_ErrorList. 
 * \param[in] arg CO_ErrorList to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new CO_ErrorList with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
CO_ErrorList CO_sliceErrorList(CO_ErrorList arg, int start, int end) {
  return (CO_ErrorList) ATgetSlice((ATermList) arg, start * 4, end * 4);
}

/**
 * Retrieve the CO_Error at #index from a CO_ErrorList. 
 * \param[in] arg CO_ErrorList to retrieve the CO_Error from
 * \param[in] index index to use to point in the CO_ErrorList
 * \return CO_Error at position #index in #arg
 */
CO_Error CO_getErrorListErrorAt(CO_ErrorList arg, int index) {
 return (CO_Error)ATelementAt((ATermList) arg,index * 4);
}

/**
 * Replace the CO_Error at #index from a CO_ErrorList by a new one. 
 * \param[in] arg CO_ErrorList to retrieve the CO_Error from
 * \param[in] elem new CO_Error to replace another
 * \param[in] index index to use to point in the CO_ErrorList
 * \return A new CO_ErrorListwith #elem replaced in #arg at position #index
 */
CO_ErrorList CO_replaceErrorListErrorAt(CO_ErrorList arg, CO_Error elem, int index) {
 return (CO_ErrorList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}

/**
 * Builds a CO_ErrorList of 2 consecutive elements. The elements are separated.
 * \param[in] elem1 One CO_Error element of the new CO_ErrorList
 * \param[in] elem2 One CO_Error element of the new CO_ErrorList
 * \return A new CO_ErrorList consisting of 2 CO_Errors
 */
CO_ErrorList CO_makeErrorList2(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2) {
  return CO_makeErrorListMany(elem1, wsAfterHead, wsAfterSep, CO_makeErrorListSingle(elem2));
}

/**
 * Builds a CO_ErrorList of 3 consecutive elements. The elements are separated.
 * \param[in] elem1 One CO_Error element of the new CO_ErrorList
 * \param[in] elem2 One CO_Error element of the new CO_ErrorList
 * \param[in] elem3 One CO_Error element of the new CO_ErrorList
 * \return A new CO_ErrorList consisting of 3 CO_Errors
 */
CO_ErrorList CO_makeErrorList3(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3) {
  return CO_makeErrorListMany(elem1, wsAfterHead, wsAfterSep, CO_makeErrorList2(wsAfterHead, wsAfterSep, elem2, elem3));
}

/**
 * Builds a CO_ErrorList of 4 consecutive elements. The elements are separated.
 * \param[in] elem1 One CO_Error element of the new CO_ErrorList
 * \param[in] elem2 One CO_Error element of the new CO_ErrorList
 * \param[in] elem3 One CO_Error element of the new CO_ErrorList
 * \param[in] elem4 One CO_Error element of the new CO_ErrorList
 * \return A new CO_ErrorList consisting of 4 CO_Errors
 */
CO_ErrorList CO_makeErrorList4(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3, CO_Error elem4) {
  return CO_makeErrorListMany(elem1, wsAfterHead, wsAfterSep, CO_makeErrorList3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}

/**
 * Builds a CO_ErrorList of 5 consecutive elements. The elements are separated.
 * \param[in] elem1 One CO_Error element of the new CO_ErrorList
 * \param[in] elem2 One CO_Error element of the new CO_ErrorList
 * \param[in] elem3 One CO_Error element of the new CO_ErrorList
 * \param[in] elem4 One CO_Error element of the new CO_ErrorList
 * \param[in] elem5 One CO_Error element of the new CO_ErrorList
 * \return A new CO_ErrorList consisting of 5 CO_Errors
 */
CO_ErrorList CO_makeErrorList5(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3, CO_Error elem4, CO_Error elem5) {
  return CO_makeErrorListMany(elem1, wsAfterHead, wsAfterSep, CO_makeErrorList4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}

/**
 * Builds a CO_ErrorList of 6 consecutive elements. The elements are separated.
 * \param[in] elem1 One CO_Error element of the new CO_ErrorList
 * \param[in] elem2 One CO_Error element of the new CO_ErrorList
 * \param[in] elem3 One CO_Error element of the new CO_ErrorList
 * \param[in] elem4 One CO_Error element of the new CO_ErrorList
 * \param[in] elem5 One CO_Error element of the new CO_ErrorList
 * \param[in] elem6 One CO_Error element of the new CO_ErrorList
 * \return A new CO_ErrorList consisting of 6 CO_Errors
 */
CO_ErrorList CO_makeErrorList6(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3, CO_Error elem4, CO_Error elem5, CO_Error elem6) {
  return CO_makeErrorListMany(elem1, wsAfterHead, wsAfterSep, CO_makeErrorList5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}

/**
 * Constructs a Absent of type CO_OptLayout. Like all ATerm types, CO_OptLayouts are maximally shared.
 * \return A pointer to a Absent, either newly constructed or shared
 */
CO_OptLayout CO_makeOptLayoutAbsent(void) {
  return (CO_OptLayout)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4))), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATempty);
}
/**
 * Constructs a Present of type CO_OptLayout. Like all ATerm types, CO_OptLayouts are maximally shared.
 * \param[in] layout a child of the new Present
 * \return A pointer to a Present, either newly constructed or shared
 */
CO_OptLayout CO_makeOptLayoutPresent(CO_Layout layout) {
  return (CO_OptLayout)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun4))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4))), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm) layout));
}
/**
 * Constructs a Lex-to-cf of type CO_Layout. Like all ATerm types, CO_Layouts are maximally shared.
 * \param[in] list a child of the new Lex-to-cf
 * \return A pointer to a Lex-to-cf, either newly constructed or shared
 */
CO_Layout CO_makeLayoutLexToCf(CO_LexLayoutList list) {
  return (CO_Layout)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun4)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm) list)));
}
/**
 * Constructs a empty of type CO_LexLayoutList. Like all ATerm types, CO_LexLayoutLists are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
CO_LexLayoutList CO_makeLexLayoutListEmpty(void) {
  return (CO_LexLayoutList)(ATerm)ATempty;
}
/**
 * Constructs a single of type CO_LexLayoutList. Like all ATerm types, CO_LexLayoutLists are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
CO_LexLayoutList CO_makeLexLayoutListSingle(CO_LexLayout head) {
  return (CO_LexLayoutList)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type CO_LexLayoutList. Like all ATerm types, CO_LexLayoutLists are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
CO_LexLayoutList CO_makeLexLayoutListMany(CO_LexLayout head, CO_LexLayoutList tail) {
  return (CO_LexLayoutList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a whitespace of type CO_LexLayout. Like all ATerm types, CO_LexLayouts are maximally shared.
 * \param[in] ch a child of the new whitespace
 * \return A pointer to a whitespace, either newly constructed or shared
 */
CO_LexLayout CO_makeLexLayoutWhitespace(char ch) {
  return (CO_LexLayout)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(32)), (ATerm)ATmakeInt(13)), (ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(9), (ATerm)ATmakeInt(10))))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl0(CO_afun4)), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun14)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) CO_byteToChar(ch))));
}
/**
 * Constructs a StrCon of type CO_Start. Like all ATerm types, CO_Starts are maximally shared.
 * \param[in] wsBefore a child of the new StrCon
 * \param[in] topStrCon a child of the new StrCon
 * \param[in] wsAfter a child of the new StrCon
 * \param[in] ambCnt a child of the new StrCon
 * \return A pointer to a StrCon, either newly constructed or shared
 */
CO_Start CO_makeStartStrCon(CO_OptLayout wsBefore, CO_StrCon topStrCon, CO_OptLayout wsAfter, int ambCnt) {
  return (CO_Start)(ATerm)ATmakeAppl2(CO_afun15, (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun18)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topStrCon), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}
/**
 * Constructs a BoolCon of type CO_Start. Like all ATerm types, CO_Starts are maximally shared.
 * \param[in] wsBefore a child of the new BoolCon
 * \param[in] topBoolCon a child of the new BoolCon
 * \param[in] wsAfter a child of the new BoolCon
 * \param[in] ambCnt a child of the new BoolCon
 * \return A pointer to a BoolCon, either newly constructed or shared
 */
CO_Start CO_makeStartBoolCon(CO_OptLayout wsBefore, CO_BoolCon topBoolCon, CO_OptLayout wsAfter, int ambCnt) {
  return (CO_Start)(ATerm)ATmakeAppl2(CO_afun15, (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun19)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun18)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topBoolCon), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}
/**
 * Constructs a Summary of type CO_Start. Like all ATerm types, CO_Starts are maximally shared.
 * \param[in] wsBefore a child of the new Summary
 * \param[in] topSummary a child of the new Summary
 * \param[in] wsAfter a child of the new Summary
 * \param[in] ambCnt a child of the new Summary
 * \return A pointer to a Summary, either newly constructed or shared
 */
CO_Start CO_makeStartSummary(CO_OptLayout wsBefore, CO_Summary topSummary, CO_OptLayout wsAfter, int ambCnt) {
  return (CO_Start)(ATerm)ATmakeAppl2(CO_afun15, (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun20)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun18)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topSummary), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}
/**
 * Constructs a Error of type CO_Start. Like all ATerm types, CO_Starts are maximally shared.
 * \param[in] wsBefore a child of the new Error
 * \param[in] topError a child of the new Error
 * \param[in] wsAfter a child of the new Error
 * \param[in] ambCnt a child of the new Error
 * \return A pointer to a Error, either newly constructed or shared
 */
CO_Start CO_makeStartError(CO_OptLayout wsBefore, CO_Error topError, CO_OptLayout wsAfter, int ambCnt) {
  return (CO_Start)(ATerm)ATmakeAppl2(CO_afun15, (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun21)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun18)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topError), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}
/**
 * Constructs a Boolean of type CO_Start. Like all ATerm types, CO_Starts are maximally shared.
 * \param[in] wsBefore a child of the new Boolean
 * \param[in] topBoolean a child of the new Boolean
 * \param[in] wsAfter a child of the new Boolean
 * \param[in] ambCnt a child of the new Boolean
 * \return A pointer to a Boolean, either newly constructed or shared
 */
CO_Start CO_makeStartBoolean(CO_OptLayout wsBefore, CO_Boolean topBoolean, CO_OptLayout wsAfter, int ambCnt) {
  return (CO_Start)(ATerm)ATmakeAppl2(CO_afun15, (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun22)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun18)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topBoolean), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}
/**
 * Constructs a newline of type CO_LexStrChar. Like all ATerm types, CO_LexStrChars are maximally shared.
 * \return A pointer to a newline, either newly constructed or shared
 */
CO_LexStrChar CO_makeLexStrCharNewline(void) {
  return (CO_LexStrChar)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun24))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun25))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun26)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun24)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(92)))));
}
/**
 * Constructs a tab of type CO_LexStrChar. Like all ATerm types, CO_LexStrChars are maximally shared.
 * \return A pointer to a tab, either newly constructed or shared
 */
CO_LexStrChar CO_makeLexStrCharTab(void) {
  return (CO_LexStrChar)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun25))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun28)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(92)))));
}
/**
 * Constructs a quote of type CO_LexStrChar. Like all ATerm types, CO_LexStrChars are maximally shared.
 * \return A pointer to a quote, either newly constructed or shared
 */
CO_LexStrChar CO_makeLexStrCharQuote(void) {
  return (CO_LexStrChar)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun29))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun25))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun30)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun29)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(34)), (ATerm)ATmakeInt(92)))));
}
/**
 * Constructs a backslash of type CO_LexStrChar. Like all ATerm types, CO_LexStrChars are maximally shared.
 * \return A pointer to a backslash, either newly constructed or shared
 */
CO_LexStrChar CO_makeLexStrCharBackslash(void) {
  return (CO_LexStrChar)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun31))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun25))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun32)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun31)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(92)), (ATerm)ATmakeInt(92)))));
}
/**
 * Constructs a decimal of type CO_LexStrChar. Like all ATerm types, CO_LexStrChars are maximally shared.
 * \param[in] a a child of the new decimal
 * \param[in] b a child of the new decimal
 * \param[in] c a child of the new decimal
 * \return A pointer to a decimal, either newly constructed or shared
 */
CO_LexStrChar CO_makeLexStrCharDecimal(char a, char b, char c) {
  return (CO_LexStrChar)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun33))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun25))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun34)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) ((ATerm) CO_byteToChar(c))), (ATerm) ((ATerm) CO_byteToChar(b))), (ATerm) ((ATerm) CO_byteToChar(a))), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun33)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))));
}
/**
 * Constructs a normal of type CO_LexStrChar. Like all ATerm types, CO_LexStrChars are maximally shared.
 * \param[in] ch a child of the new normal
 * \return A pointer to a normal, either newly constructed or shared
 */
CO_LexStrChar CO_makeLexStrCharNormal(char ch) {
  return (CO_LexStrChar)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(93), (ATerm)ATmakeInt(255))), (ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(35), (ATerm)ATmakeInt(91))), (ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(32), (ATerm)ATmakeInt(33))))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun25))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun35)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) CO_byteToChar(ch))));
}
/**
 * Constructs a Lex-to-cf of type CO_StrChar. Like all ATerm types, CO_StrChars are maximally shared.
 * \param[in] StrChar a child of the new Lex-to-cf
 * \return A pointer to a Lex-to-cf, either newly constructed or shared
 */
CO_StrChar CO_makeStrCharLexToCf(CO_LexStrChar StrChar) {
  return (CO_StrChar)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun25)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun25))), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm) StrChar));
}
/**
 * Constructs a default of type CO_LexStrCon. Like all ATerm types, CO_LexStrCons are maximally shared.
 * \param[in] chars a child of the new default
 * \return A pointer to a default, either newly constructed or shared
 */
CO_LexStrCon CO_makeLexStrConDefault(CO_LexStrCharChars chars) {
  return (CO_LexStrCon)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun36, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun25))))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun17))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun37)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(34)), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun36, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun25))))), (ATerm) chars)), (ATerm)ATmakeInt(34)));
}
/**
 * Constructs a Lex-to-cf of type CO_StrCon. Like all ATerm types, CO_StrCons are maximally shared.
 * \param[in] StrCon a child of the new Lex-to-cf
 * \return A pointer to a Lex-to-cf, either newly constructed or shared
 */
CO_StrCon CO_makeStrConLexToCf(CO_LexStrCon StrCon) {
  return (CO_StrCon)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun17))), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm) StrCon));
}
/**
 * Constructs a empty of type CO_LexStrCharChars. Like all ATerm types, CO_LexStrCharCharss are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
CO_LexStrCharChars CO_makeLexStrCharCharsEmpty(void) {
  return (CO_LexStrCharChars)(ATerm)ATempty;
}
/**
 * Constructs a single of type CO_LexStrCharChars. Like all ATerm types, CO_LexStrCharCharss are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
CO_LexStrCharChars CO_makeLexStrCharCharsSingle(CO_LexStrChar head) {
  return (CO_LexStrCharChars)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type CO_LexStrCharChars. Like all ATerm types, CO_LexStrCharCharss are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
CO_LexStrCharChars CO_makeLexStrCharCharsMany(CO_LexStrChar head, CO_LexStrCharChars tail) {
  return (CO_LexStrCharChars)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a true of type CO_BoolCon. Like all ATerm types, CO_BoolCons are maximally shared.
 * \return A pointer to a true, either newly constructed or shared
 */
CO_BoolCon CO_makeBoolConTrue(void) {
  return (CO_BoolCon)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun38))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun19))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun38)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun38)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(116)))));
}
/**
 * Constructs a false of type CO_BoolCon. Like all ATerm types, CO_BoolCons are maximally shared.
 * \return A pointer to a false, either newly constructed or shared
 */
CO_BoolCon CO_makeBoolConFalse(void) {
  return (CO_BoolCon)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun39))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun19))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun39)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun39)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(102)))));
}
/**
 * Constructs a digits of type CO_LexNatCon. Like all ATerm types, CO_LexNatCons are maximally shared.
 * \param[in] list a child of the new digits
 * \return A pointer to a digits, either newly constructed or shared
 */
CO_LexNatCon CO_makeLexNatConDigits(const char* list) {
  return (CO_LexNatCon)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun40))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun41)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm) ((ATerm) CO_stringToChars(list)))));
}
/**
 * Constructs a Lex-to-cf of type CO_NatCon. Like all ATerm types, CO_NatCons are maximally shared.
 * \param[in] NatCon a child of the new Lex-to-cf
 * \return A pointer to a Lex-to-cf, either newly constructed or shared
 */
CO_NatCon CO_makeNatConLexToCf(CO_LexNatCon NatCon) {
  return (CO_NatCon)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun40)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun40))), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm) NatCon));
}
/**
 * Constructs a byte of type CO_LexByte. Like all ATerm types, CO_LexBytes are maximally shared.
 * \param[in] ch a child of the new byte
 * \return A pointer to a byte, either newly constructed or shared
 */
CO_LexByte CO_makeLexByteByte(char ch) {
  return (CO_LexByte)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255))))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun42))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun43)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) CO_byteToChar(ch))));
}
/**
 * Constructs a Lex-to-cf of type CO_Byte. Like all ATerm types, CO_Bytes are maximally shared.
 * \param[in] Byte a child of the new Lex-to-cf
 * \return A pointer to a Lex-to-cf, either newly constructed or shared
 */
CO_Byte CO_makeByteLexToCf(CO_LexByte Byte) {
  return (CO_Byte)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun42)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun42))), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm) Byte));
}
/**
 * Constructs a bytes of type CO_LexBytes. Like all ATerm types, CO_LexBytess are maximally shared.
 * \param[in] list a child of the new bytes
 * \return A pointer to a bytes, either newly constructed or shared
 */
CO_LexBytes CO_makeLexBytesBytes(CO_LexByteList list) {
  return (CO_LexBytes)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun36, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun42))))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun44))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun45)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun36, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun42))))), (ATerm) list)));
}
/**
 * Constructs a Lex-to-cf of type CO_Bytes. Like all ATerm types, CO_Bytess are maximally shared.
 * \param[in] Bytes a child of the new Lex-to-cf
 * \return A pointer to a Lex-to-cf, either newly constructed or shared
 */
CO_Bytes CO_makeBytesLexToCf(CO_LexBytes Bytes) {
  return (CO_Bytes)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun44)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun44))), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm) Bytes));
}
/**
 * Constructs a empty of type CO_LexByteList. Like all ATerm types, CO_LexByteLists are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
CO_LexByteList CO_makeLexByteListEmpty(void) {
  return (CO_LexByteList)(ATerm)ATempty;
}
/**
 * Constructs a single of type CO_LexByteList. Like all ATerm types, CO_LexByteLists are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
CO_LexByteList CO_makeLexByteListSingle(CO_LexByte head) {
  return (CO_LexByteList)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type CO_LexByteList. Like all ATerm types, CO_LexByteLists are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
CO_LexByteList CO_makeLexByteListMany(CO_LexByte head, CO_LexByteList tail) {
  return (CO_LexByteList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a subject of type CO_Subject. Like all ATerm types, CO_Subjects are maximally shared.
 * \param[in] wsAfterSubject a child of the new subject
 * \param[in] wsAfterParenOpen a child of the new subject
 * \param[in] description a child of the new subject
 * \param[in] wsAfterDescription a child of the new subject
 * \return A pointer to a subject, either newly constructed or shared
 */
CO_Subject CO_makeSubjectSubject(CO_OptLayout wsAfterSubject, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription) {
  return (CO_Subject)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun48))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun49))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun48)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterSubject), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(106)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(98)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun48)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(106)), (ATerm)ATmakeInt(98)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(115)))));
}
/**
 * Constructs a localized of type CO_Subject. Like all ATerm types, CO_Subjects are maximally shared.
 * \param[in] wsAfterLocalized a child of the new localized
 * \param[in] wsAfterParenOpen a child of the new localized
 * \param[in] description a child of the new localized
 * \param[in] wsAfterDescription a child of the new localized
 * \param[in] wsAfterComma a child of the new localized
 * \param[in] Location a child of the new localized
 * \param[in] wsAfterLocation a child of the new localized
 * \return A pointer to a localized, either newly constructed or shared
 */
CO_Subject CO_makeSubjectLocalized(CO_OptLayout wsAfterLocalized, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_Location Location, CO_OptLayout wsAfterLocation) {
  return (CO_Subject)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun50)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun52))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun49))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun52)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterLocation), (ATerm) Location), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterLocalized), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(100)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(122)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun52)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(100)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(122)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(108)))));
}
/**
 * Constructs a info of type CO_Error. Like all ATerm types, CO_Errors are maximally shared.
 * \param[in] wsAfterInfo a child of the new info
 * \param[in] wsAfterParenOpen a child of the new info
 * \param[in] description a child of the new info
 * \param[in] wsAfterDescription a child of the new info
 * \param[in] wsAfterComma a child of the new info
 * \param[in] wsAfterBracketOpen a child of the new info
 * \param[in] list a child of the new info
 * \param[in] wsAfterList a child of the new info
 * \param[in] wsAfterBracketClose a child of the new info
 * \return A pointer to a info, either newly constructed or shared
 */
CO_Error CO_makeErrorInfo(CO_OptLayout wsAfterInfo, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose) {
  return (CO_Error)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun53))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun54, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun49)), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun55))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun56))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun21))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun56)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun53)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun54, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun49)), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun55)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterInfo), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun56)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(102)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(105)))));
}
/**
 * Constructs a warning of type CO_Error. Like all ATerm types, CO_Errors are maximally shared.
 * \param[in] wsAfterWarning a child of the new warning
 * \param[in] wsAfterParenOpen a child of the new warning
 * \param[in] description a child of the new warning
 * \param[in] wsAfterDescription a child of the new warning
 * \param[in] wsAfterComma a child of the new warning
 * \param[in] wsAfterBracketOpen a child of the new warning
 * \param[in] list a child of the new warning
 * \param[in] wsAfterList a child of the new warning
 * \param[in] wsAfterBracketClose a child of the new warning
 * \return A pointer to a warning, either newly constructed or shared
 */
CO_Error CO_makeErrorWarning(CO_OptLayout wsAfterWarning, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose) {
  return (CO_Error)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun53))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun54, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun49)), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun55))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun57))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun21))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun57)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun53)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun54, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun49)), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun55)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterWarning), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(103)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(119)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun57)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(103)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(119)))));
}
/**
 * Constructs a error of type CO_Error. Like all ATerm types, CO_Errors are maximally shared.
 * \param[in] wsAfterError a child of the new error
 * \param[in] wsAfterParenOpen a child of the new error
 * \param[in] description a child of the new error
 * \param[in] wsAfterDescription a child of the new error
 * \param[in] wsAfterComma a child of the new error
 * \param[in] wsAfterBracketOpen a child of the new error
 * \param[in] list a child of the new error
 * \param[in] wsAfterList a child of the new error
 * \param[in] wsAfterBracketClose a child of the new error
 * \return A pointer to a error, either newly constructed or shared
 */
CO_Error CO_makeErrorError(CO_OptLayout wsAfterError, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose) {
  return (CO_Error)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun53))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun54, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun49)), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun55))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun58))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun21))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun58)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun53)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun54, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun49)), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun55)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterError), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun58)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)))));
}
/**
 * Constructs a fatal of type CO_Error. Like all ATerm types, CO_Errors are maximally shared.
 * \param[in] wsAfterFatal a child of the new fatal
 * \param[in] wsAfterParenOpen a child of the new fatal
 * \param[in] description a child of the new fatal
 * \param[in] wsAfterDescription a child of the new fatal
 * \param[in] wsAfterComma a child of the new fatal
 * \param[in] wsAfterBracketOpen a child of the new fatal
 * \param[in] list a child of the new fatal
 * \param[in] wsAfterList a child of the new fatal
 * \param[in] wsAfterBracketClose a child of the new fatal
 * \return A pointer to a fatal, either newly constructed or shared
 */
CO_Error CO_makeErrorFatal(CO_OptLayout wsAfterFatal, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose) {
  return (CO_Error)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun53))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun54, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun49)), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun55))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun59))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun21))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun59)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun53)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun54, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun49)), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun55)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterFatal), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun59)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(102)))));
}
/**
 * Constructs a summary of type CO_Summary. Like all ATerm types, CO_Summarys are maximally shared.
 * \param[in] wsAfterSummary a child of the new summary
 * \param[in] wsAfterParenOpen a child of the new summary
 * \param[in] producer a child of the new summary
 * \param[in] wsAfterProducer a child of the new summary
 * \param[in] wsAfterComma a child of the new summary
 * \param[in] id a child of the new summary
 * \param[in] wsAfterId a child of the new summary
 * \param[in] wsAfterComma1 a child of the new summary
 * \param[in] wsAfterBracketOpen a child of the new summary
 * \param[in] list a child of the new summary
 * \param[in] wsAfterList a child of the new summary
 * \param[in] wsAfterBracketClose a child of the new summary
 * \return A pointer to a summary, either newly constructed or shared
 */
CO_Summary CO_makeSummarySummary(CO_OptLayout wsAfterSummary, CO_OptLayout wsAfterParenOpen, CO_StrCon producer, CO_OptLayout wsAfterProducer, CO_OptLayout wsAfterComma, CO_StrCon id, CO_OptLayout wsAfterId, CO_OptLayout wsAfterComma1, CO_OptLayout wsAfterBracketOpen, CO_ErrorList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose) {
  return (CO_Summary)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun53))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun54, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun21)), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun55))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun20))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun60)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun53)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun54, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun21)), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun55)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterId), (ATerm) id), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterProducer), (ATerm) producer), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterSummary), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(121)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(109)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(109)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(121)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(109)), (ATerm)ATmakeInt(109)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(115)))));
}
/**
 * Constructs a empty of type CO_SubjectList. Like all ATerm types, CO_SubjectLists are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
CO_SubjectList CO_makeSubjectListEmpty(void) {
  return (CO_SubjectList)(ATerm)ATempty;
}
/**
 * Constructs a single of type CO_SubjectList. Like all ATerm types, CO_SubjectLists are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
CO_SubjectList CO_makeSubjectListSingle(CO_Subject head) {
  return (CO_SubjectList)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type CO_SubjectList. Like all ATerm types, CO_SubjectLists are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] wsAfterHead a child of the new many
 * \param[in] wsAfterSep a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
CO_SubjectList CO_makeSubjectListMany(CO_Subject head, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_SubjectList tail) {
  if (CO_isSubjectListEmpty(tail)) {
    return CO_makeSubjectListSingle(head);
  }
  return (CO_SubjectList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}
/**
 * Constructs a empty of type CO_ErrorList. Like all ATerm types, CO_ErrorLists are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
CO_ErrorList CO_makeErrorListEmpty(void) {
  return (CO_ErrorList)(ATerm)ATempty;
}
/**
 * Constructs a single of type CO_ErrorList. Like all ATerm types, CO_ErrorLists are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
CO_ErrorList CO_makeErrorListSingle(CO_Error head) {
  return (CO_ErrorList)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type CO_ErrorList. Like all ATerm types, CO_ErrorLists are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] wsAfterHead a child of the new many
 * \param[in] wsAfterSep a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
CO_ErrorList CO_makeErrorListMany(CO_Error head, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_ErrorList tail) {
  if (CO_isErrorListEmpty(tail)) {
    return CO_makeErrorListSingle(head);
  }
  return (CO_ErrorList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}
/**
 * Constructs a file of type CO_Location. Like all ATerm types, CO_Locations are maximally shared.
 * \param[in] wsAfterFile a child of the new file
 * \param[in] wsAfterParenOpen a child of the new file
 * \param[in] filename a child of the new file
 * \param[in] wsAfterFilename a child of the new file
 * \return A pointer to a file, either newly constructed or shared
 */
CO_Location CO_makeLocationFile(CO_OptLayout wsAfterFile, CO_OptLayout wsAfterParenOpen, CO_StrCon filename, CO_OptLayout wsAfterFilename) {
  return (CO_Location)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun61))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun50))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun61)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterFilename), (ATerm) filename), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterFile), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun61)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(102)))));
}
/**
 * Constructs a area of type CO_Location. Like all ATerm types, CO_Locations are maximally shared.
 * \param[in] wsAfterA a child of the new area
 * \param[in] wsAfterParenOpen a child of the new area
 * \param[in] Area a child of the new area
 * \param[in] wsAfterArea a child of the new area
 * \return A pointer to a area, either newly constructed or shared
 */
CO_Location CO_makeLocationArea(CO_OptLayout wsAfterA, CO_OptLayout wsAfterParenOpen, CO_Area Area, CO_OptLayout wsAfterArea) {
  return (CO_Location)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun62)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun63))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun50))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun63)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterArea), (ATerm) Area), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterA), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun63)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)))));
}
/**
 * Constructs a area-in-file of type CO_Location. Like all ATerm types, CO_Locations are maximally shared.
 * \param[in] wsAfterAreaInFile a child of the new area-in-file
 * \param[in] wsAfterParenOpen a child of the new area-in-file
 * \param[in] filename a child of the new area-in-file
 * \param[in] wsAfterFilename a child of the new area-in-file
 * \param[in] wsAfterComma a child of the new area-in-file
 * \param[in] Area a child of the new area-in-file
 * \param[in] wsAfterArea a child of the new area-in-file
 * \return A pointer to a area-in-file, either newly constructed or shared
 */
CO_Location CO_makeLocationAreaInFile(CO_OptLayout wsAfterAreaInFile, CO_OptLayout wsAfterParenOpen, CO_StrCon filename, CO_OptLayout wsAfterFilename, CO_OptLayout wsAfterComma, CO_Area Area, CO_OptLayout wsAfterArea) {
  return (CO_Location)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun62)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun64))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun50))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun64)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterArea), (ATerm) Area), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterFilename), (ATerm) filename), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterAreaInFile), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun64)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(102)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)))));
}
/**
 * Constructs a area of type CO_Area. Like all ATerm types, CO_Areas are maximally shared.
 * \param[in] wsAfterArea a child of the new area
 * \param[in] wsAfterParenOpen a child of the new area
 * \param[in] beginLine a child of the new area
 * \param[in] wsAfterBeginLine a child of the new area
 * \param[in] wsAfterComma a child of the new area
 * \param[in] beginColumn a child of the new area
 * \param[in] wsAfterBeginColumn a child of the new area
 * \param[in] wsAfterComma1 a child of the new area
 * \param[in] endLine a child of the new area
 * \param[in] wsAfterEndLine a child of the new area
 * \param[in] wsAfterComma2 a child of the new area
 * \param[in] endColumn a child of the new area
 * \param[in] wsAfterEndColumn a child of the new area
 * \param[in] wsAfterComma3 a child of the new area
 * \param[in] offset a child of the new area
 * \param[in] wsAfterOffset a child of the new area
 * \param[in] wsAfterComma4 a child of the new area
 * \param[in] length a child of the new area
 * \param[in] wsAfterLength a child of the new area
 * \return A pointer to a area, either newly constructed or shared
 */
CO_Area CO_makeAreaArea(CO_OptLayout wsAfterArea, CO_OptLayout wsAfterParenOpen, CO_NatCon beginLine, CO_OptLayout wsAfterBeginLine, CO_OptLayout wsAfterComma, CO_NatCon beginColumn, CO_OptLayout wsAfterBeginColumn, CO_OptLayout wsAfterComma1, CO_NatCon endLine, CO_OptLayout wsAfterEndLine, CO_OptLayout wsAfterComma2, CO_NatCon endColumn, CO_OptLayout wsAfterEndColumn, CO_OptLayout wsAfterComma3, CO_NatCon offset, CO_OptLayout wsAfterOffset, CO_OptLayout wsAfterComma4, CO_NatCon length, CO_OptLayout wsAfterLength) {
  return (CO_Area)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun40)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun40)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun40)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun40)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun40)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun40)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun63))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun62))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun63)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterLength), (ATerm) length), (ATerm) wsAfterComma4), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterOffset), (ATerm) offset), (ATerm) wsAfterComma3), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterEndColumn), (ATerm) endColumn), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterEndLine), (ATerm) endLine), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterBeginColumn), (ATerm) beginColumn), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterBeginLine), (ATerm) beginLine), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterArea), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun63)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)))));
}
/**
 * Constructs a success of type CO_Read. Like all ATerm types, CO_Reads are maximally shared.
 * \param[in] wsAfterRead a child of the new success
 * \param[in] wsAfterParenOpen a child of the new success
 * \param[in] value a child of the new success
 * \param[in] wsAfterValue a child of the new success
 * \return A pointer to a success, either newly constructed or shared
 */
CO_Read CO_makeReadSuccess(CO_OptLayout wsAfterRead, CO_OptLayout wsAfterParenOpen, CO_Bytes value, CO_OptLayout wsAfterValue) {
  return (CO_Read)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun44)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun65))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun66))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun67)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterValue), (ATerm) value), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterRead), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(100)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun65)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(100)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)))));
}
/**
 * Constructs a failure of type CO_Read. Like all ATerm types, CO_Reads are maximally shared.
 * \param[in] wsAfterReadError a child of the new failure
 * \param[in] wsAfterParenOpen a child of the new failure
 * \param[in] Summary a child of the new failure
 * \param[in] wsAfterSummary a child of the new failure
 * \return A pointer to a failure, either newly constructed or shared
 */
CO_Read CO_makeReadFailure(CO_OptLayout wsAfterReadError, CO_OptLayout wsAfterParenOpen, CO_Summary Summary, CO_OptLayout wsAfterSummary) {
  return (CO_Read)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun20)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun68))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun66))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun69)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSummary), (ATerm) Summary), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterReadError), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(100)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun68)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(100)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)))));
}
/**
 * Constructs a success of type CO_Write. Like all ATerm types, CO_Writes are maximally shared.
 * \return A pointer to a success, either newly constructed or shared
 */
CO_Write CO_makeWriteSuccess(void) {
  return (CO_Write)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun70))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun71))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun67)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(119)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun70)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(119)))));
}
/**
 * Constructs a failure of type CO_Write. Like all ATerm types, CO_Writes are maximally shared.
 * \param[in] wsAfterWriteError a child of the new failure
 * \param[in] wsAfterParenOpen a child of the new failure
 * \param[in] Summary a child of the new failure
 * \param[in] wsAfterSummary a child of the new failure
 * \return A pointer to a failure, either newly constructed or shared
 */
CO_Write CO_makeWriteFailure(CO_OptLayout wsAfterWriteError, CO_OptLayout wsAfterParenOpen, CO_Summary Summary, CO_OptLayout wsAfterSummary) {
  return (CO_Write)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun20)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun72))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun71))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun69)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSummary), (ATerm) Summary), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterWriteError), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(119)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun72)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(119)))));
}
/**
 * Constructs a success of type CO_ParsetreeX. Like all ATerm types, CO_ParsetreeXs are maximally shared.
 * \param[in] typeOfTree a child of the new success
 * \param[in] typeOfX a child of the new success
 * \param[in] wsAfterParseTree a child of the new success
 * \param[in] wsAfterParenOpen a child of the new success
 * \param[in] leftLayout a child of the new success
 * \param[in] wsAfterLeftLayout a child of the new success
 * \param[in] wsAfterComma a child of the new success
 * \param[in] tree a child of the new success
 * \param[in] wsAfterTree a child of the new success
 * \param[in] wsAfterComma1 a child of the new success
 * \param[in] rightLayout a child of the new success
 * \param[in] wsAfterRightLayout a child of the new success
 * \param[in] wsAfterComma2 a child of the new success
 * \param[in] ambCnt a child of the new success
 * \param[in] wsAfterAmbCnt a child of the new success
 * \return A pointer to a success, either newly constructed or shared
 */
CO_ParsetreeX CO_makeParsetreeXSuccess(ATerm typeOfTree, ATerm typeOfX, CO_OptLayout wsAfterParseTree, CO_OptLayout wsAfterParenOpen, CO_Bytes leftLayout, CO_OptLayout wsAfterLeftLayout, CO_OptLayout wsAfterComma, CO_X tree, CO_OptLayout wsAfterTree, CO_OptLayout wsAfterComma1, CO_Bytes rightLayout, CO_OptLayout wsAfterRightLayout, CO_OptLayout wsAfterComma2, CO_NatCon ambCnt, CO_OptLayout wsAfterAmbCnt) {
  return (CO_ParsetreeX)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun40)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun44)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm) typeOfTree), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun44)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun73))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun74, (ATerm)ATmakeAppl0(CO_afun75), (ATerm)ATmakeList1((ATerm) typeOfX))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun67)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterAmbCnt), (ATerm) ambCnt), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterRightLayout), (ATerm) rightLayout), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterTree), (ATerm) tree), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterLeftLayout), (ATerm) leftLayout), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterParseTree), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun73)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(112)))));
}
/**
 * Constructs a failure of type CO_ParsetreeX. Like all ATerm types, CO_ParsetreeXs are maximally shared.
 * \param[in] typeOfX a child of the new failure
 * \param[in] wsAfterParseError a child of the new failure
 * \param[in] wsAfterParenOpen a child of the new failure
 * \param[in] Summary a child of the new failure
 * \param[in] wsAfterSummary a child of the new failure
 * \return A pointer to a failure, either newly constructed or shared
 */
CO_ParsetreeX CO_makeParsetreeXFailure(ATerm typeOfX, CO_OptLayout wsAfterParseError, CO_OptLayout wsAfterParenOpen, CO_Summary Summary, CO_OptLayout wsAfterSummary) {
  return (CO_ParsetreeX)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun20)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun76))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun74, (ATerm)ATmakeAppl0(CO_afun75), (ATerm)ATmakeList1((ATerm) typeOfX))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun69)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSummary), (ATerm) Summary), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterParseError), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun76)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(112)))));
}
/**
 * Constructs a cast of type CO_X. Like all ATerm types, CO_Xs are maximally shared.
 * \param[in] X a child of the new cast
 * \return A pointer to a cast, either newly constructed or shared
 */
CO_X CO_makeXCast(ATerm X) {
  return (CO_X)(ATerm) X;
}
/**
 * Constructs a constant of type CO_Boolean. Like all ATerm types, CO_Booleans are maximally shared.
 * \param[in] BoolCon a child of the new constant
 * \return A pointer to a constant, either newly constructed or shared
 */
CO_Boolean CO_makeBooleanConstant(CO_BoolCon BoolCon) {
  return (CO_Boolean)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun19)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun22))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun77)))))), (ATerm)ATmakeList1((ATerm) BoolCon));
}
/**
 * Constructs a or of type CO_Boolean. Like all ATerm types, CO_Booleans are maximally shared.
 * \param[in] lhs a child of the new or
 * \param[in] wsAfterLhs a child of the new or
 * \param[in] wsAfterBar a child of the new or
 * \param[in] rhs a child of the new or
 * \return A pointer to a or, either newly constructed or shared
 */
CO_Boolean CO_makeBooleanOr(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterBar, CO_Boolean rhs) {
  return (CO_Boolean)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun22)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun78))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun22)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun22))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun79)))), (ATerm)ATmakeAppl1(CO_afun80, (ATerm)ATmakeAppl0(CO_afun81))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterBar), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(124)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun78)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(124)))), (ATerm) wsAfterLhs), (ATerm) lhs));
}
/**
 * Constructs a and of type CO_Boolean. Like all ATerm types, CO_Booleans are maximally shared.
 * \param[in] lhs a child of the new and
 * \param[in] wsAfterLhs a child of the new and
 * \param[in] wsAfterAmp a child of the new and
 * \param[in] rhs a child of the new and
 * \return A pointer to a and, either newly constructed or shared
 */
CO_Boolean CO_makeBooleanAnd(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterAmp, CO_Boolean rhs) {
  return (CO_Boolean)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun22)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun82))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun22)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun22))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun83)))), (ATerm)ATmakeAppl1(CO_afun80, (ATerm)ATmakeAppl0(CO_afun81))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterAmp), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(38)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun82)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(38)))), (ATerm) wsAfterLhs), (ATerm) lhs));
}
/**
 * Constructs a not of type CO_Boolean. Like all ATerm types, CO_Booleans are maximally shared.
 * \param[in] wsAfterNot a child of the new not
 * \param[in] wsAfterParenOpen a child of the new not
 * \param[in] Boolean a child of the new not
 * \param[in] wsAfterBoolean a child of the new not
 * \return A pointer to a not, either newly constructed or shared
 */
CO_Boolean CO_makeBooleanNot(CO_OptLayout wsAfterNot, CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean) {
  return (CO_Boolean)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun22)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun84))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun22))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun84)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBoolean), (ATerm) Boolean), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterNot), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun84)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(110)))));
}
/**
 * Constructs a bracket of type CO_Boolean. Like all ATerm types, CO_Booleans are maximally shared.
 * \param[in] wsAfterParenOpen a child of the new bracket
 * \param[in] Boolean a child of the new bracket
 * \param[in] wsAfterBoolean a child of the new bracket
 * \return A pointer to a bracket, either newly constructed or shared
 */
CO_Boolean CO_makeBooleanBracket(CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean) {
  return (CO_Boolean)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun22)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun16, (ATerm)ATmakeAppl0(CO_afun22))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun85)))), (ATerm)ATmakeAppl0(CO_afun86)))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun46)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBoolean), (ATerm) Boolean), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun23, (ATerm)ATmakeAppl0(CO_afun47)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))));
}

/**
 * Tests equality of two CO_OptLayouts. A constant time operation.
 * \param[in] arg0 first CO_OptLayout to be compared
 * \param[in] arg1 second CO_OptLayout to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualOptLayout(CO_OptLayout arg0, CO_OptLayout arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_Layouts. A constant time operation.
 * \param[in] arg0 first CO_Layout to be compared
 * \param[in] arg1 second CO_Layout to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualLayout(CO_Layout arg0, CO_Layout arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_LexLayoutLists. A constant time operation.
 * \param[in] arg0 first CO_LexLayoutList to be compared
 * \param[in] arg1 second CO_LexLayoutList to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualLexLayoutList(CO_LexLayoutList arg0, CO_LexLayoutList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_LexLayouts. A constant time operation.
 * \param[in] arg0 first CO_LexLayout to be compared
 * \param[in] arg1 second CO_LexLayout to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualLexLayout(CO_LexLayout arg0, CO_LexLayout arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_Starts. A constant time operation.
 * \param[in] arg0 first CO_Start to be compared
 * \param[in] arg1 second CO_Start to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualStart(CO_Start arg0, CO_Start arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_LexStrChars. A constant time operation.
 * \param[in] arg0 first CO_LexStrChar to be compared
 * \param[in] arg1 second CO_LexStrChar to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualLexStrChar(CO_LexStrChar arg0, CO_LexStrChar arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_StrChars. A constant time operation.
 * \param[in] arg0 first CO_StrChar to be compared
 * \param[in] arg1 second CO_StrChar to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualStrChar(CO_StrChar arg0, CO_StrChar arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_LexStrCons. A constant time operation.
 * \param[in] arg0 first CO_LexStrCon to be compared
 * \param[in] arg1 second CO_LexStrCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualLexStrCon(CO_LexStrCon arg0, CO_LexStrCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_StrCons. A constant time operation.
 * \param[in] arg0 first CO_StrCon to be compared
 * \param[in] arg1 second CO_StrCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualStrCon(CO_StrCon arg0, CO_StrCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_LexStrCharCharss. A constant time operation.
 * \param[in] arg0 first CO_LexStrCharChars to be compared
 * \param[in] arg1 second CO_LexStrCharChars to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualLexStrCharChars(CO_LexStrCharChars arg0, CO_LexStrCharChars arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_BoolCons. A constant time operation.
 * \param[in] arg0 first CO_BoolCon to be compared
 * \param[in] arg1 second CO_BoolCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualBoolCon(CO_BoolCon arg0, CO_BoolCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_LexNatCons. A constant time operation.
 * \param[in] arg0 first CO_LexNatCon to be compared
 * \param[in] arg1 second CO_LexNatCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualLexNatCon(CO_LexNatCon arg0, CO_LexNatCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_NatCons. A constant time operation.
 * \param[in] arg0 first CO_NatCon to be compared
 * \param[in] arg1 second CO_NatCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualNatCon(CO_NatCon arg0, CO_NatCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_LexBytes. A constant time operation.
 * \param[in] arg0 first CO_LexByte to be compared
 * \param[in] arg1 second CO_LexByte to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualLexByte(CO_LexByte arg0, CO_LexByte arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_Bytes. A constant time operation.
 * \param[in] arg0 first CO_Byte to be compared
 * \param[in] arg1 second CO_Byte to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualByte(CO_Byte arg0, CO_Byte arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_LexBytess. A constant time operation.
 * \param[in] arg0 first CO_LexBytes to be compared
 * \param[in] arg1 second CO_LexBytes to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualLexBytes(CO_LexBytes arg0, CO_LexBytes arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_Bytess. A constant time operation.
 * \param[in] arg0 first CO_Bytes to be compared
 * \param[in] arg1 second CO_Bytes to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualBytes(CO_Bytes arg0, CO_Bytes arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_LexByteLists. A constant time operation.
 * \param[in] arg0 first CO_LexByteList to be compared
 * \param[in] arg1 second CO_LexByteList to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualLexByteList(CO_LexByteList arg0, CO_LexByteList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_Subjects. A constant time operation.
 * \param[in] arg0 first CO_Subject to be compared
 * \param[in] arg1 second CO_Subject to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualSubject(CO_Subject arg0, CO_Subject arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_Errors. A constant time operation.
 * \param[in] arg0 first CO_Error to be compared
 * \param[in] arg1 second CO_Error to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualError(CO_Error arg0, CO_Error arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_Summarys. A constant time operation.
 * \param[in] arg0 first CO_Summary to be compared
 * \param[in] arg1 second CO_Summary to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualSummary(CO_Summary arg0, CO_Summary arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_SubjectLists. A constant time operation.
 * \param[in] arg0 first CO_SubjectList to be compared
 * \param[in] arg1 second CO_SubjectList to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualSubjectList(CO_SubjectList arg0, CO_SubjectList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_ErrorLists. A constant time operation.
 * \param[in] arg0 first CO_ErrorList to be compared
 * \param[in] arg1 second CO_ErrorList to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualErrorList(CO_ErrorList arg0, CO_ErrorList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_Locations. A constant time operation.
 * \param[in] arg0 first CO_Location to be compared
 * \param[in] arg1 second CO_Location to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualLocation(CO_Location arg0, CO_Location arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_Areas. A constant time operation.
 * \param[in] arg0 first CO_Area to be compared
 * \param[in] arg1 second CO_Area to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualArea(CO_Area arg0, CO_Area arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_Reads. A constant time operation.
 * \param[in] arg0 first CO_Read to be compared
 * \param[in] arg1 second CO_Read to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualRead(CO_Read arg0, CO_Read arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_Writes. A constant time operation.
 * \param[in] arg0 first CO_Write to be compared
 * \param[in] arg1 second CO_Write to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualWrite(CO_Write arg0, CO_Write arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_ParsetreeXs. A constant time operation.
 * \param[in] arg0 first CO_ParsetreeX to be compared
 * \param[in] arg1 second CO_ParsetreeX to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualParsetreeX(CO_ParsetreeX arg0, CO_ParsetreeX arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_Xs. A constant time operation.
 * \param[in] arg0 first CO_X to be compared
 * \param[in] arg1 second CO_X to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualX(CO_X arg0, CO_X arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two CO_Booleans. A constant time operation.
 * \param[in] arg0 first CO_Boolean to be compared
 * \param[in] arg1 second CO_Boolean to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool CO_isEqualBoolean(CO_Boolean arg0, CO_Boolean arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Assert whether a CO_OptLayout is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_OptLayout
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidOptLayout(CO_OptLayout arg) {
  if (CO_isOptLayoutAbsent(arg)) {
    return ATtrue;
  }
  else if (CO_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_OptLayout is a Absent. . May not be used to assert correctness of the CO_OptLayout
 * \param[in] arg input CO_OptLayout
 * \return ATtrue if #arg corresponds to the signature of a Absent, or ATfalse otherwise
 */
inline ATbool CO_isOptLayoutAbsent(CO_OptLayout arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternOptLayoutAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_OptLayout is a Present. . May not be used to assert correctness of the CO_OptLayout
 * \param[in] arg input CO_OptLayout
 * \return ATtrue if #arg corresponds to the signature of a Present, or ATfalse otherwise
 */
inline ATbool CO_isOptLayoutPresent(CO_OptLayout arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternOptLayoutPresent, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_OptLayout has a layout. 
 * \param[in] arg input CO_OptLayout
 * \return ATtrue if the CO_OptLayout had a layout, or ATfalse otherwise
 */
ATbool CO_hasOptLayoutLayout(CO_OptLayout arg) {
  if (CO_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the layout CO_Layout of a CO_OptLayout. Note that the precondition is that this CO_OptLayout actually has a layout
 * \param[in] arg input CO_OptLayout
 * \return the layout of #arg, if it exist or an undefined value if it does not
 */
CO_Layout CO_getOptLayoutLayout(CO_OptLayout arg) {
  
    return (CO_Layout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the layout of a CO_OptLayout. The precondition being that this CO_OptLayout actually has a layout
 * \param[in] arg input CO_OptLayout
 * \param[in] layout new CO_Layout to set in #arg
 * \return A new CO_OptLayout with layout at the right place, or a core dump if #arg did not have a layout
 */
CO_OptLayout CO_setOptLayoutLayout(CO_OptLayout arg, CO_Layout layout) {
  if (CO_isOptLayoutPresent(arg)) {
    return (CO_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) layout), 0), 1);
  }

  ATabort("OptLayout has no Layout: %t\n", arg);
  return (CO_OptLayout)NULL;
}

/**
 * Assert whether a CO_Layout is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_Layout
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidLayout(CO_Layout arg) {
  if (CO_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Layout is a Lex-to-cf. Always returns ATtrue
 * \param[in] arg input CO_Layout
 * \return ATtrue if #arg corresponds to the signature of a Lex-to-cf, or ATfalse otherwise
 */
inline ATbool CO_isLayoutLexToCf(CO_Layout arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLayoutLexToCf, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_Layout has a list. 
 * \param[in] arg input CO_Layout
 * \return ATtrue if the CO_Layout had a list, or ATfalse otherwise
 */
ATbool CO_hasLayoutList(CO_Layout arg) {
  if (CO_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the list CO_LexLayoutList of a CO_Layout. Note that the precondition is that this CO_Layout actually has a list
 * \param[in] arg input CO_Layout
 * \return the list of #arg, if it exist or an undefined value if it does not
 */
CO_LexLayoutList CO_getLayoutList(CO_Layout arg) {
  
    return (CO_LexLayoutList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/**
 * Set the list of a CO_Layout. The precondition being that this CO_Layout actually has a list
 * \param[in] arg input CO_Layout
 * \param[in] list new CO_LexLayoutList to set in #arg
 * \return A new CO_Layout with list at the right place, or a core dump if #arg did not have a list
 */
CO_Layout CO_setLayoutList(CO_Layout arg, CO_LexLayoutList list) {
  if (CO_isLayoutLexToCf(arg)) {
    return (CO_Layout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) list), 1), 0), 1);
  }

  ATabort("Layout has no List: %t\n", arg);
  return (CO_Layout)NULL;
}

/**
 * Assert whether a CO_LexLayoutList is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_LexLayoutList
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidLexLayoutList(CO_LexLayoutList arg) {
  if (CO_isLexLayoutListEmpty(arg)) {
    return ATtrue;
  }
  else if (CO_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_LexLayoutList is a empty. . May not be used to assert correctness of the CO_LexLayoutList
 * \param[in] arg input CO_LexLayoutList
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool CO_isLexLayoutListEmpty(CO_LexLayoutList arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexLayoutListEmpty));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_LexLayoutList is a single. . May not be used to assert correctness of the CO_LexLayoutList
 * \param[in] arg input CO_LexLayoutList
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool CO_isLexLayoutListSingle(CO_LexLayoutList arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexLayoutListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_LexLayoutList is a many. . May not be used to assert correctness of the CO_LexLayoutList
 * \param[in] arg input CO_LexLayoutList
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool CO_isLexLayoutListMany(CO_LexLayoutList arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexLayoutListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_LexLayoutList has a head. 
 * \param[in] arg input CO_LexLayoutList
 * \return ATtrue if the CO_LexLayoutList had a head, or ATfalse otherwise
 */
ATbool CO_hasLexLayoutListHead(CO_LexLayoutList arg) {
  if (CO_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_LexLayoutList has a tail. 
 * \param[in] arg input CO_LexLayoutList
 * \return ATtrue if the CO_LexLayoutList had a tail, or ATfalse otherwise
 */
ATbool CO_hasLexLayoutListTail(CO_LexLayoutList arg) {
  if (CO_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head CO_LexLayout of a CO_LexLayoutList. Note that the precondition is that this CO_LexLayoutList actually has a head
 * \param[in] arg input CO_LexLayoutList
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
CO_LexLayout CO_getLexLayoutListHead(CO_LexLayoutList arg) {
  if (CO_isLexLayoutListSingle(arg)) {
    return (CO_LexLayout)ATgetFirst((ATermList)arg);
  }
  else 
    return (CO_LexLayout)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail CO_LexLayoutList of a CO_LexLayoutList. Note that the precondition is that this CO_LexLayoutList actually has a tail
 * \param[in] arg input CO_LexLayoutList
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
CO_LexLayoutList CO_getLexLayoutListTail(CO_LexLayoutList arg) {
  
    return (CO_LexLayoutList)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a CO_LexLayoutList. The precondition being that this CO_LexLayoutList actually has a head
 * \param[in] arg input CO_LexLayoutList
 * \param[in] head new CO_LexLayout to set in #arg
 * \return A new CO_LexLayoutList with head at the right place, or a core dump if #arg did not have a head
 */
CO_LexLayoutList CO_setLexLayoutListHead(CO_LexLayoutList arg, CO_LexLayout head) {
  if (CO_isLexLayoutListSingle(arg)) {
    return (CO_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CO_isLexLayoutListMany(arg)) {
    return (CO_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexLayoutList has no Head: %t\n", arg);
  return (CO_LexLayoutList)NULL;
}

/**
 * Set the tail of a CO_LexLayoutList. The precondition being that this CO_LexLayoutList actually has a tail
 * \param[in] arg input CO_LexLayoutList
 * \param[in] tail new CO_LexLayoutList to set in #arg
 * \return A new CO_LexLayoutList with tail at the right place, or a core dump if #arg did not have a tail
 */
CO_LexLayoutList CO_setLexLayoutListTail(CO_LexLayoutList arg, CO_LexLayoutList tail) {
  if (CO_isLexLayoutListMany(arg)) {
    return (CO_LexLayoutList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexLayoutList has no Tail: %t\n", arg);
  return (CO_LexLayoutList)NULL;
}

/**
 * Assert whether a CO_LexLayout is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_LexLayout
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidLexLayout(CO_LexLayout arg) {
  if (CO_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_LexLayout is a whitespace. Always returns ATtrue
 * \param[in] arg input CO_LexLayout
 * \return ATtrue if #arg corresponds to the signature of a whitespace, or ATfalse otherwise
 */
inline ATbool CO_isLexLayoutWhitespace(CO_LexLayout arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexLayoutWhitespace, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_LexLayout has a ch. 
 * \param[in] arg input CO_LexLayout
 * \return ATtrue if the CO_LexLayout had a ch, or ATfalse otherwise
 */
ATbool CO_hasLexLayoutCh(CO_LexLayout arg) {
  if (CO_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ch char of a CO_LexLayout. Note that the precondition is that this CO_LexLayout actually has a ch
 * \param[in] arg input CO_LexLayout
 * \return the ch of #arg, if it exist or an undefined value if it does not
 */
char CO_getLexLayoutCh(CO_LexLayout arg) {
  
    return (char)CO_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/**
 * Set the ch of a CO_LexLayout. The precondition being that this CO_LexLayout actually has a ch
 * \param[in] arg input CO_LexLayout
 * \param[in] ch new char to set in #arg
 * \return A new CO_LexLayout with ch at the right place, or a core dump if #arg did not have a ch
 */
CO_LexLayout CO_setLexLayoutCh(CO_LexLayout arg, char ch) {
  if (CO_isLexLayoutWhitespace(arg)) {
    return (CO_LexLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) CO_byteToChar(ch))), 0), 1);
  }

  ATabort("LexLayout has no Ch: %t\n", arg);
  return (CO_LexLayout)NULL;
}

/**
 * Assert whether a CO_Start is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_Start
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidStart(CO_Start arg) {
  if (CO_isStartStrCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartSummary(arg)) {
    return ATtrue;
  }
  else if (CO_isStartError(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Start is a StrCon. . May not be used to assert correctness of the CO_Start
 * \param[in] arg input CO_Start
 * \return ATtrue if #arg corresponds to the signature of a StrCon, or ATfalse otherwise
 */
inline ATbool CO_isStartStrCon(CO_Start arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternStartStrCon, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Start is a BoolCon. . May not be used to assert correctness of the CO_Start
 * \param[in] arg input CO_Start
 * \return ATtrue if #arg corresponds to the signature of a BoolCon, or ATfalse otherwise
 */
inline ATbool CO_isStartBoolCon(CO_Start arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternStartBoolCon, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Start is a Summary. . May not be used to assert correctness of the CO_Start
 * \param[in] arg input CO_Start
 * \return ATtrue if #arg corresponds to the signature of a Summary, or ATfalse otherwise
 */
inline ATbool CO_isStartSummary(CO_Start arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternStartSummary, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Start is a Error. . May not be used to assert correctness of the CO_Start
 * \param[in] arg input CO_Start
 * \return ATtrue if #arg corresponds to the signature of a Error, or ATfalse otherwise
 */
inline ATbool CO_isStartError(CO_Start arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternStartError, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Start is a Boolean. . May not be used to assert correctness of the CO_Start
 * \param[in] arg input CO_Start
 * \return ATtrue if #arg corresponds to the signature of a Boolean, or ATfalse otherwise
 */
inline ATbool CO_isStartBoolean(CO_Start arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternStartBoolean, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Start has a ws-before. 
 * \param[in] arg input CO_Start
 * \return ATtrue if the CO_Start had a ws-before, or ATfalse otherwise
 */
ATbool CO_hasStartWsBefore(CO_Start arg) {
  if (CO_isStartStrCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartSummary(arg)) {
    return ATtrue;
  }
  else if (CO_isStartError(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Start has a top-StrCon. 
 * \param[in] arg input CO_Start
 * \return ATtrue if the CO_Start had a top-StrCon, or ATfalse otherwise
 */
ATbool CO_hasStartTopStrCon(CO_Start arg) {
  if (CO_isStartStrCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Start has a ws-after. 
 * \param[in] arg input CO_Start
 * \return ATtrue if the CO_Start had a ws-after, or ATfalse otherwise
 */
ATbool CO_hasStartWsAfter(CO_Start arg) {
  if (CO_isStartStrCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartSummary(arg)) {
    return ATtrue;
  }
  else if (CO_isStartError(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Start has a amb-cnt. 
 * \param[in] arg input CO_Start
 * \return ATtrue if the CO_Start had a amb-cnt, or ATfalse otherwise
 */
ATbool CO_hasStartAmbCnt(CO_Start arg) {
  if (CO_isStartStrCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartSummary(arg)) {
    return ATtrue;
  }
  else if (CO_isStartError(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Start has a top-BoolCon. 
 * \param[in] arg input CO_Start
 * \return ATtrue if the CO_Start had a top-BoolCon, or ATfalse otherwise
 */
ATbool CO_hasStartTopBoolCon(CO_Start arg) {
  if (CO_isStartBoolCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Start has a top-Summary. 
 * \param[in] arg input CO_Start
 * \return ATtrue if the CO_Start had a top-Summary, or ATfalse otherwise
 */
ATbool CO_hasStartTopSummary(CO_Start arg) {
  if (CO_isStartSummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Start has a top-Error. 
 * \param[in] arg input CO_Start
 * \return ATtrue if the CO_Start had a top-Error, or ATfalse otherwise
 */
ATbool CO_hasStartTopError(CO_Start arg) {
  if (CO_isStartError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Start has a top-Boolean. 
 * \param[in] arg input CO_Start
 * \return ATtrue if the CO_Start had a top-Boolean, or ATfalse otherwise
 */
ATbool CO_hasStartTopBoolean(CO_Start arg) {
  if (CO_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ws-before CO_OptLayout of a CO_Start. Note that the precondition is that this CO_Start actually has a ws-before
 * \param[in] arg input CO_Start
 * \return the ws-before of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getStartWsBefore(CO_Start arg) {
  if (CO_isStartStrCon(arg)) {
    return (CO_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (CO_isStartBoolCon(arg)) {
    return (CO_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (CO_isStartSummary(arg)) {
    return (CO_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (CO_isStartError(arg)) {
    return (CO_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else 
    return (CO_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
}

/**
 * Get the top-StrCon CO_StrCon of a CO_Start. Note that the precondition is that this CO_Start actually has a top-StrCon
 * \param[in] arg input CO_Start
 * \return the top-StrCon of #arg, if it exist or an undefined value if it does not
 */
CO_StrCon CO_getStartTopStrCon(CO_Start arg) {
  
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/**
 * Get the ws-after CO_OptLayout of a CO_Start. Note that the precondition is that this CO_Start actually has a ws-after
 * \param[in] arg input CO_Start
 * \return the ws-after of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getStartWsAfter(CO_Start arg) {
  if (CO_isStartStrCon(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (CO_isStartBoolCon(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (CO_isStartSummary(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (CO_isStartError(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
}

/**
 * Get the amb-cnt int of a CO_Start. Note that the precondition is that this CO_Start actually has a amb-cnt
 * \param[in] arg input CO_Start
 * \return the amb-cnt of #arg, if it exist or an undefined value if it does not
 */
int CO_getStartAmbCnt(CO_Start arg) {
  if (CO_isStartStrCon(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (CO_isStartBoolCon(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (CO_isStartSummary(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (CO_isStartError(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the top-BoolCon CO_BoolCon of a CO_Start. Note that the precondition is that this CO_Start actually has a top-BoolCon
 * \param[in] arg input CO_Start
 * \return the top-BoolCon of #arg, if it exist or an undefined value if it does not
 */
CO_BoolCon CO_getStartTopBoolCon(CO_Start arg) {
  
    return (CO_BoolCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/**
 * Get the top-Summary CO_Summary of a CO_Start. Note that the precondition is that this CO_Start actually has a top-Summary
 * \param[in] arg input CO_Start
 * \return the top-Summary of #arg, if it exist or an undefined value if it does not
 */
CO_Summary CO_getStartTopSummary(CO_Start arg) {
  
    return (CO_Summary)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/**
 * Get the top-Error CO_Error of a CO_Start. Note that the precondition is that this CO_Start actually has a top-Error
 * \param[in] arg input CO_Start
 * \return the top-Error of #arg, if it exist or an undefined value if it does not
 */
CO_Error CO_getStartTopError(CO_Start arg) {
  
    return (CO_Error)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/**
 * Get the top-Boolean CO_Boolean of a CO_Start. Note that the precondition is that this CO_Start actually has a top-Boolean
 * \param[in] arg input CO_Start
 * \return the top-Boolean of #arg, if it exist or an undefined value if it does not
 */
CO_Boolean CO_getStartTopBoolean(CO_Start arg) {
  
    return (CO_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/**
 * Set the ws-before of a CO_Start. The precondition being that this CO_Start actually has a ws-before
 * \param[in] arg input CO_Start
 * \param[in] wsBefore new CO_OptLayout to set in #arg
 * \return A new CO_Start with wsBefore at the right place, or a core dump if #arg did not have a wsBefore
 */
CO_Start CO_setStartWsBefore(CO_Start arg, CO_OptLayout wsBefore) {
  if (CO_isStartStrCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (CO_isStartBoolCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (CO_isStartSummary(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (CO_isStartError(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (CO_isStartBoolean(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }

  ATabort("Start has no WsBefore: %t\n", arg);
  return (CO_Start)NULL;
}

/**
 * Set the top-StrCon of a CO_Start. The precondition being that this CO_Start actually has a top-StrCon
 * \param[in] arg input CO_Start
 * \param[in] topStrCon new CO_StrCon to set in #arg
 * \return A new CO_Start with topStrCon at the right place, or a core dump if #arg did not have a topStrCon
 */
CO_Start CO_setStartTopStrCon(CO_Start arg, CO_StrCon topStrCon) {
  if (CO_isStartStrCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topStrCon), 1), 1), 0);
  }

  ATabort("Start has no TopStrCon: %t\n", arg);
  return (CO_Start)NULL;
}

/**
 * Set the ws-after of a CO_Start. The precondition being that this CO_Start actually has a ws-after
 * \param[in] arg input CO_Start
 * \param[in] wsAfter new CO_OptLayout to set in #arg
 * \return A new CO_Start with wsAfter at the right place, or a core dump if #arg did not have a wsAfter
 */
CO_Start CO_setStartWsAfter(CO_Start arg, CO_OptLayout wsAfter) {
  if (CO_isStartStrCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (CO_isStartBoolCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (CO_isStartSummary(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (CO_isStartError(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (CO_isStartBoolean(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }

  ATabort("Start has no WsAfter: %t\n", arg);
  return (CO_Start)NULL;
}

/**
 * Set the amb-cnt of a CO_Start. The precondition being that this CO_Start actually has a amb-cnt
 * \param[in] arg input CO_Start
 * \param[in] ambCnt new int to set in #arg
 * \return A new CO_Start with ambCnt at the right place, or a core dump if #arg did not have a ambCnt
 */
CO_Start CO_setStartAmbCnt(CO_Start arg, int ambCnt) {
  if (CO_isStartStrCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (CO_isStartBoolCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (CO_isStartSummary(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (CO_isStartError(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (CO_isStartBoolean(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }

  ATabort("Start has no AmbCnt: %t\n", arg);
  return (CO_Start)NULL;
}

/**
 * Set the top-BoolCon of a CO_Start. The precondition being that this CO_Start actually has a top-BoolCon
 * \param[in] arg input CO_Start
 * \param[in] topBoolCon new CO_BoolCon to set in #arg
 * \return A new CO_Start with topBoolCon at the right place, or a core dump if #arg did not have a topBoolCon
 */
CO_Start CO_setStartTopBoolCon(CO_Start arg, CO_BoolCon topBoolCon) {
  if (CO_isStartBoolCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topBoolCon), 1), 1), 0);
  }

  ATabort("Start has no TopBoolCon: %t\n", arg);
  return (CO_Start)NULL;
}

/**
 * Set the top-Summary of a CO_Start. The precondition being that this CO_Start actually has a top-Summary
 * \param[in] arg input CO_Start
 * \param[in] topSummary new CO_Summary to set in #arg
 * \return A new CO_Start with topSummary at the right place, or a core dump if #arg did not have a topSummary
 */
CO_Start CO_setStartTopSummary(CO_Start arg, CO_Summary topSummary) {
  if (CO_isStartSummary(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topSummary), 1), 1), 0);
  }

  ATabort("Start has no TopSummary: %t\n", arg);
  return (CO_Start)NULL;
}

/**
 * Set the top-Error of a CO_Start. The precondition being that this CO_Start actually has a top-Error
 * \param[in] arg input CO_Start
 * \param[in] topError new CO_Error to set in #arg
 * \return A new CO_Start with topError at the right place, or a core dump if #arg did not have a topError
 */
CO_Start CO_setStartTopError(CO_Start arg, CO_Error topError) {
  if (CO_isStartError(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topError), 1), 1), 0);
  }

  ATabort("Start has no TopError: %t\n", arg);
  return (CO_Start)NULL;
}

/**
 * Set the top-Boolean of a CO_Start. The precondition being that this CO_Start actually has a top-Boolean
 * \param[in] arg input CO_Start
 * \param[in] topBoolean new CO_Boolean to set in #arg
 * \return A new CO_Start with topBoolean at the right place, or a core dump if #arg did not have a topBoolean
 */
CO_Start CO_setStartTopBoolean(CO_Start arg, CO_Boolean topBoolean) {
  if (CO_isStartBoolean(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topBoolean), 1), 1), 0);
  }

  ATabort("Start has no TopBoolean: %t\n", arg);
  return (CO_Start)NULL;
}

/**
 * Assert whether a CO_LexStrChar is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_LexStrChar
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidLexStrChar(CO_LexStrChar arg) {
  if (CO_isLexStrCharNewline(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharTab(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharQuote(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharBackslash(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_LexStrChar is a newline. . May not be used to assert correctness of the CO_LexStrChar
 * \param[in] arg input CO_LexStrChar
 * \return ATtrue if #arg corresponds to the signature of a newline, or ATfalse otherwise
 */
inline ATbool CO_isLexStrCharNewline(CO_LexStrChar arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharNewline);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_LexStrChar is a tab. . May not be used to assert correctness of the CO_LexStrChar
 * \param[in] arg input CO_LexStrChar
 * \return ATtrue if #arg corresponds to the signature of a tab, or ATfalse otherwise
 */
inline ATbool CO_isLexStrCharTab(CO_LexStrChar arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharTab);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_LexStrChar is a quote. . May not be used to assert correctness of the CO_LexStrChar
 * \param[in] arg input CO_LexStrChar
 * \return ATtrue if #arg corresponds to the signature of a quote, or ATfalse otherwise
 */
inline ATbool CO_isLexStrCharQuote(CO_LexStrChar arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharQuote);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_LexStrChar is a backslash. . May not be used to assert correctness of the CO_LexStrChar
 * \param[in] arg input CO_LexStrChar
 * \return ATtrue if #arg corresponds to the signature of a backslash, or ATfalse otherwise
 */
inline ATbool CO_isLexStrCharBackslash(CO_LexStrChar arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharBackslash);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_LexStrChar is a decimal. . May not be used to assert correctness of the CO_LexStrChar
 * \param[in] arg input CO_LexStrChar
 * \return ATtrue if #arg corresponds to the signature of a decimal, or ATfalse otherwise
 */
inline ATbool CO_isLexStrCharDecimal(CO_LexStrChar arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharDecimal, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_LexStrChar is a normal. . May not be used to assert correctness of the CO_LexStrChar
 * \param[in] arg input CO_LexStrChar
 * \return ATtrue if #arg corresponds to the signature of a normal, or ATfalse otherwise
 */
inline ATbool CO_isLexStrCharNormal(CO_LexStrChar arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharNormal, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_LexStrChar has a a. 
 * \param[in] arg input CO_LexStrChar
 * \return ATtrue if the CO_LexStrChar had a a, or ATfalse otherwise
 */
ATbool CO_hasLexStrCharA(CO_LexStrChar arg) {
  if (CO_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_LexStrChar has a b. 
 * \param[in] arg input CO_LexStrChar
 * \return ATtrue if the CO_LexStrChar had a b, or ATfalse otherwise
 */
ATbool CO_hasLexStrCharB(CO_LexStrChar arg) {
  if (CO_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_LexStrChar has a c. 
 * \param[in] arg input CO_LexStrChar
 * \return ATtrue if the CO_LexStrChar had a c, or ATfalse otherwise
 */
ATbool CO_hasLexStrCharC(CO_LexStrChar arg) {
  if (CO_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_LexStrChar has a ch. 
 * \param[in] arg input CO_LexStrChar
 * \return ATtrue if the CO_LexStrChar had a ch, or ATfalse otherwise
 */
ATbool CO_hasLexStrCharCh(CO_LexStrChar arg) {
  if (CO_isLexStrCharNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the a char of a CO_LexStrChar. Note that the precondition is that this CO_LexStrChar actually has a a
 * \param[in] arg input CO_LexStrChar
 * \return the a of #arg, if it exist or an undefined value if it does not
 */
char CO_getLexStrCharA(CO_LexStrChar arg) {
  
    return (char)CO_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1));
}

/**
 * Get the b char of a CO_LexStrChar. Note that the precondition is that this CO_LexStrChar actually has a b
 * \param[in] arg input CO_LexStrChar
 * \return the b of #arg, if it exist or an undefined value if it does not
 */
char CO_getLexStrCharB(CO_LexStrChar arg) {
  
    return (char)CO_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2));
}

/**
 * Get the c char of a CO_LexStrChar. Note that the precondition is that this CO_LexStrChar actually has a c
 * \param[in] arg input CO_LexStrChar
 * \return the c of #arg, if it exist or an undefined value if it does not
 */
char CO_getLexStrCharC(CO_LexStrChar arg) {
  
    return (char)CO_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3));
}

/**
 * Get the ch char of a CO_LexStrChar. Note that the precondition is that this CO_LexStrChar actually has a ch
 * \param[in] arg input CO_LexStrChar
 * \return the ch of #arg, if it exist or an undefined value if it does not
 */
char CO_getLexStrCharCh(CO_LexStrChar arg) {
  
    return (char)CO_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/**
 * Set the a of a CO_LexStrChar. The precondition being that this CO_LexStrChar actually has a a
 * \param[in] arg input CO_LexStrChar
 * \param[in] a new char to set in #arg
 * \return A new CO_LexStrChar with a at the right place, or a core dump if #arg did not have a a
 */
CO_LexStrChar CO_setLexStrCharA(CO_LexStrChar arg, char a) {
  if (CO_isLexStrCharDecimal(arg)) {
    return (CO_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) CO_byteToChar(a))), 1), 1);
  }

  ATabort("LexStrChar has no A: %t\n", arg);
  return (CO_LexStrChar)NULL;
}

/**
 * Set the b of a CO_LexStrChar. The precondition being that this CO_LexStrChar actually has a b
 * \param[in] arg input CO_LexStrChar
 * \param[in] b new char to set in #arg
 * \return A new CO_LexStrChar with b at the right place, or a core dump if #arg did not have a b
 */
CO_LexStrChar CO_setLexStrCharB(CO_LexStrChar arg, char b) {
  if (CO_isLexStrCharDecimal(arg)) {
    return (CO_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) CO_byteToChar(b))), 2), 1);
  }

  ATabort("LexStrChar has no B: %t\n", arg);
  return (CO_LexStrChar)NULL;
}

/**
 * Set the c of a CO_LexStrChar. The precondition being that this CO_LexStrChar actually has a c
 * \param[in] arg input CO_LexStrChar
 * \param[in] c new char to set in #arg
 * \return A new CO_LexStrChar with c at the right place, or a core dump if #arg did not have a c
 */
CO_LexStrChar CO_setLexStrCharC(CO_LexStrChar arg, char c) {
  if (CO_isLexStrCharDecimal(arg)) {
    return (CO_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) CO_byteToChar(c))), 3), 1);
  }

  ATabort("LexStrChar has no C: %t\n", arg);
  return (CO_LexStrChar)NULL;
}

/**
 * Set the ch of a CO_LexStrChar. The precondition being that this CO_LexStrChar actually has a ch
 * \param[in] arg input CO_LexStrChar
 * \param[in] ch new char to set in #arg
 * \return A new CO_LexStrChar with ch at the right place, or a core dump if #arg did not have a ch
 */
CO_LexStrChar CO_setLexStrCharCh(CO_LexStrChar arg, char ch) {
  if (CO_isLexStrCharNormal(arg)) {
    return (CO_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) CO_byteToChar(ch))), 0), 1);
  }

  ATabort("LexStrChar has no Ch: %t\n", arg);
  return (CO_LexStrChar)NULL;
}

/**
 * Assert whether a CO_StrChar is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_StrChar
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidStrChar(CO_StrChar arg) {
  if (CO_isStrCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_StrChar is a Lex-to-cf. Always returns ATtrue
 * \param[in] arg input CO_StrChar
 * \return ATtrue if #arg corresponds to the signature of a Lex-to-cf, or ATfalse otherwise
 */
inline ATbool CO_isStrCharLexToCf(CO_StrChar arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternStrCharLexToCf, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_StrChar has a StrChar. 
 * \param[in] arg input CO_StrChar
 * \return ATtrue if the CO_StrChar had a StrChar, or ATfalse otherwise
 */
ATbool CO_hasStrCharStrChar(CO_StrChar arg) {
  if (CO_isStrCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the StrChar CO_LexStrChar of a CO_StrChar. Note that the precondition is that this CO_StrChar actually has a StrChar
 * \param[in] arg input CO_StrChar
 * \return the StrChar of #arg, if it exist or an undefined value if it does not
 */
CO_LexStrChar CO_getStrCharStrChar(CO_StrChar arg) {
  
    return (CO_LexStrChar)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the StrChar of a CO_StrChar. The precondition being that this CO_StrChar actually has a StrChar
 * \param[in] arg input CO_StrChar
 * \param[in] StrChar new CO_LexStrChar to set in #arg
 * \return A new CO_StrChar with StrChar at the right place, or a core dump if #arg did not have a StrChar
 */
CO_StrChar CO_setStrCharStrChar(CO_StrChar arg, CO_LexStrChar StrChar) {
  if (CO_isStrCharLexToCf(arg)) {
    return (CO_StrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrChar), 0), 1);
  }

  ATabort("StrChar has no StrChar: %t\n", arg);
  return (CO_StrChar)NULL;
}

/**
 * Assert whether a CO_LexStrCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_LexStrCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidLexStrCon(CO_LexStrCon arg) {
  if (CO_isLexStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_LexStrCon is a default. Always returns ATtrue
 * \param[in] arg input CO_LexStrCon
 * \return ATtrue if #arg corresponds to the signature of a default, or ATfalse otherwise
 */
inline ATbool CO_isLexStrConDefault(CO_LexStrCon arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexStrConDefault, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_LexStrCon has a chars. 
 * \param[in] arg input CO_LexStrCon
 * \return ATtrue if the CO_LexStrCon had a chars, or ATfalse otherwise
 */
ATbool CO_hasLexStrConChars(CO_LexStrCon arg) {
  if (CO_isLexStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the chars CO_LexStrCharChars of a CO_LexStrCon. Note that the precondition is that this CO_LexStrCon actually has a chars
 * \param[in] arg input CO_LexStrCon
 * \return the chars of #arg, if it exist or an undefined value if it does not
 */
CO_LexStrCharChars CO_getLexStrConChars(CO_LexStrCon arg) {
  
    return (CO_LexStrCharChars)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), 1);
}

/**
 * Set the chars of a CO_LexStrCon. The precondition being that this CO_LexStrCon actually has a chars
 * \param[in] arg input CO_LexStrCon
 * \param[in] chars new CO_LexStrCharChars to set in #arg
 * \return A new CO_LexStrCon with chars at the right place, or a core dump if #arg did not have a chars
 */
CO_LexStrCon CO_setLexStrConChars(CO_LexStrCon arg, CO_LexStrCharChars chars) {
  if (CO_isLexStrConDefault(arg)) {
    return (CO_LexStrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), (ATerm)((ATerm) chars), 1), 1), 1);
  }

  ATabort("LexStrCon has no Chars: %t\n", arg);
  return (CO_LexStrCon)NULL;
}

/**
 * Assert whether a CO_StrCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_StrCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidStrCon(CO_StrCon arg) {
  if (CO_isStrConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_StrCon is a Lex-to-cf. Always returns ATtrue
 * \param[in] arg input CO_StrCon
 * \return ATtrue if #arg corresponds to the signature of a Lex-to-cf, or ATfalse otherwise
 */
inline ATbool CO_isStrConLexToCf(CO_StrCon arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternStrConLexToCf, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_StrCon has a StrCon. 
 * \param[in] arg input CO_StrCon
 * \return ATtrue if the CO_StrCon had a StrCon, or ATfalse otherwise
 */
ATbool CO_hasStrConStrCon(CO_StrCon arg) {
  if (CO_isStrConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the StrCon CO_LexStrCon of a CO_StrCon. Note that the precondition is that this CO_StrCon actually has a StrCon
 * \param[in] arg input CO_StrCon
 * \return the StrCon of #arg, if it exist or an undefined value if it does not
 */
CO_LexStrCon CO_getStrConStrCon(CO_StrCon arg) {
  
    return (CO_LexStrCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the StrCon of a CO_StrCon. The precondition being that this CO_StrCon actually has a StrCon
 * \param[in] arg input CO_StrCon
 * \param[in] StrCon new CO_LexStrCon to set in #arg
 * \return A new CO_StrCon with StrCon at the right place, or a core dump if #arg did not have a StrCon
 */
CO_StrCon CO_setStrConStrCon(CO_StrCon arg, CO_LexStrCon StrCon) {
  if (CO_isStrConLexToCf(arg)) {
    return (CO_StrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrCon), 0), 1);
  }

  ATabort("StrCon has no StrCon: %t\n", arg);
  return (CO_StrCon)NULL;
}

/**
 * Assert whether a CO_LexStrCharChars is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_LexStrCharChars
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidLexStrCharChars(CO_LexStrCharChars arg) {
  if (CO_isLexStrCharCharsEmpty(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharCharsSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_LexStrCharChars is a empty. . May not be used to assert correctness of the CO_LexStrCharChars
 * \param[in] arg input CO_LexStrCharChars
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool CO_isLexStrCharCharsEmpty(CO_LexStrCharChars arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexStrCharCharsEmpty));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_LexStrCharChars is a single. . May not be used to assert correctness of the CO_LexStrCharChars
 * \param[in] arg input CO_LexStrCharChars
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool CO_isLexStrCharCharsSingle(CO_LexStrCharChars arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharCharsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_LexStrCharChars is a many. . May not be used to assert correctness of the CO_LexStrCharChars
 * \param[in] arg input CO_LexStrCharChars
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool CO_isLexStrCharCharsMany(CO_LexStrCharChars arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharCharsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_LexStrCharChars has a head. 
 * \param[in] arg input CO_LexStrCharChars
 * \return ATtrue if the CO_LexStrCharChars had a head, or ATfalse otherwise
 */
ATbool CO_hasLexStrCharCharsHead(CO_LexStrCharChars arg) {
  if (CO_isLexStrCharCharsSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_LexStrCharChars has a tail. 
 * \param[in] arg input CO_LexStrCharChars
 * \return ATtrue if the CO_LexStrCharChars had a tail, or ATfalse otherwise
 */
ATbool CO_hasLexStrCharCharsTail(CO_LexStrCharChars arg) {
  if (CO_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head CO_LexStrChar of a CO_LexStrCharChars. Note that the precondition is that this CO_LexStrCharChars actually has a head
 * \param[in] arg input CO_LexStrCharChars
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
CO_LexStrChar CO_getLexStrCharCharsHead(CO_LexStrCharChars arg) {
  if (CO_isLexStrCharCharsSingle(arg)) {
    return (CO_LexStrChar)ATgetFirst((ATermList)arg);
  }
  else 
    return (CO_LexStrChar)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail CO_LexStrCharChars of a CO_LexStrCharChars. Note that the precondition is that this CO_LexStrCharChars actually has a tail
 * \param[in] arg input CO_LexStrCharChars
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
CO_LexStrCharChars CO_getLexStrCharCharsTail(CO_LexStrCharChars arg) {
  
    return (CO_LexStrCharChars)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a CO_LexStrCharChars. The precondition being that this CO_LexStrCharChars actually has a head
 * \param[in] arg input CO_LexStrCharChars
 * \param[in] head new CO_LexStrChar to set in #arg
 * \return A new CO_LexStrCharChars with head at the right place, or a core dump if #arg did not have a head
 */
CO_LexStrCharChars CO_setLexStrCharCharsHead(CO_LexStrCharChars arg, CO_LexStrChar head) {
  if (CO_isLexStrCharCharsSingle(arg)) {
    return (CO_LexStrCharChars)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CO_isLexStrCharCharsMany(arg)) {
    return (CO_LexStrCharChars)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexStrCharChars has no Head: %t\n", arg);
  return (CO_LexStrCharChars)NULL;
}

/**
 * Set the tail of a CO_LexStrCharChars. The precondition being that this CO_LexStrCharChars actually has a tail
 * \param[in] arg input CO_LexStrCharChars
 * \param[in] tail new CO_LexStrCharChars to set in #arg
 * \return A new CO_LexStrCharChars with tail at the right place, or a core dump if #arg did not have a tail
 */
CO_LexStrCharChars CO_setLexStrCharCharsTail(CO_LexStrCharChars arg, CO_LexStrCharChars tail) {
  if (CO_isLexStrCharCharsMany(arg)) {
    return (CO_LexStrCharChars)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexStrCharChars has no Tail: %t\n", arg);
  return (CO_LexStrCharChars)NULL;
}

/**
 * Assert whether a CO_BoolCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_BoolCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidBoolCon(CO_BoolCon arg) {
  if (CO_isBoolConTrue(arg)) {
    return ATtrue;
  }
  else if (CO_isBoolConFalse(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_BoolCon is a true. . May not be used to assert correctness of the CO_BoolCon
 * \param[in] arg input CO_BoolCon
 * \return ATtrue if #arg corresponds to the signature of a true, or ATfalse otherwise
 */
inline ATbool CO_isBoolConTrue(CO_BoolCon arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBoolConTrue);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_BoolCon is a false. . May not be used to assert correctness of the CO_BoolCon
 * \param[in] arg input CO_BoolCon
 * \return ATtrue if #arg corresponds to the signature of a false, or ATfalse otherwise
 */
inline ATbool CO_isBoolConFalse(CO_BoolCon arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBoolConFalse);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_LexNatCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_LexNatCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidLexNatCon(CO_LexNatCon arg) {
  if (CO_isLexNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_LexNatCon is a digits. Always returns ATtrue
 * \param[in] arg input CO_LexNatCon
 * \return ATtrue if #arg corresponds to the signature of a digits, or ATfalse otherwise
 */
inline ATbool CO_isLexNatConDigits(CO_LexNatCon arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexNatConDigits, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_LexNatCon has a list. 
 * \param[in] arg input CO_LexNatCon
 * \return ATtrue if the CO_LexNatCon had a list, or ATfalse otherwise
 */
ATbool CO_hasLexNatConList(CO_LexNatCon arg) {
  if (CO_isLexNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the list char* of a CO_LexNatCon. Note that the precondition is that this CO_LexNatCon actually has a list
 * \param[in] arg input CO_LexNatCon
 * \return the list of #arg, if it exist or an undefined value if it does not
 */
char* CO_getLexNatConList(CO_LexNatCon arg) {
  
    return (char*)CO_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/**
 * Set the list of a CO_LexNatCon. The precondition being that this CO_LexNatCon actually has a list
 * \param[in] arg input CO_LexNatCon
 * \param[in] list new const char* to set in #arg
 * \return A new CO_LexNatCon with list at the right place, or a core dump if #arg did not have a list
 */
CO_LexNatCon CO_setLexNatConList(CO_LexNatCon arg, const char* list) {
  if (CO_isLexNatConDigits(arg)) {
    return (CO_LexNatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) CO_stringToChars(list))), 1), 0), 1);
  }

  ATabort("LexNatCon has no List: %t\n", arg);
  return (CO_LexNatCon)NULL;
}

/**
 * Assert whether a CO_NatCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_NatCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidNatCon(CO_NatCon arg) {
  if (CO_isNatConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_NatCon is a Lex-to-cf. Always returns ATtrue
 * \param[in] arg input CO_NatCon
 * \return ATtrue if #arg corresponds to the signature of a Lex-to-cf, or ATfalse otherwise
 */
inline ATbool CO_isNatConLexToCf(CO_NatCon arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternNatConLexToCf, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_NatCon has a NatCon. 
 * \param[in] arg input CO_NatCon
 * \return ATtrue if the CO_NatCon had a NatCon, or ATfalse otherwise
 */
ATbool CO_hasNatConNatCon(CO_NatCon arg) {
  if (CO_isNatConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the NatCon CO_LexNatCon of a CO_NatCon. Note that the precondition is that this CO_NatCon actually has a NatCon
 * \param[in] arg input CO_NatCon
 * \return the NatCon of #arg, if it exist or an undefined value if it does not
 */
CO_LexNatCon CO_getNatConNatCon(CO_NatCon arg) {
  
    return (CO_LexNatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the NatCon of a CO_NatCon. The precondition being that this CO_NatCon actually has a NatCon
 * \param[in] arg input CO_NatCon
 * \param[in] NatCon new CO_LexNatCon to set in #arg
 * \return A new CO_NatCon with NatCon at the right place, or a core dump if #arg did not have a NatCon
 */
CO_NatCon CO_setNatConNatCon(CO_NatCon arg, CO_LexNatCon NatCon) {
  if (CO_isNatConLexToCf(arg)) {
    return (CO_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NatCon), 0), 1);
  }

  ATabort("NatCon has no NatCon: %t\n", arg);
  return (CO_NatCon)NULL;
}

/**
 * Assert whether a CO_LexByte is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_LexByte
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidLexByte(CO_LexByte arg) {
  if (CO_isLexByteByte(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_LexByte is a byte. Always returns ATtrue
 * \param[in] arg input CO_LexByte
 * \return ATtrue if #arg corresponds to the signature of a byte, or ATfalse otherwise
 */
inline ATbool CO_isLexByteByte(CO_LexByte arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexByteByte, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_LexByte has a ch. 
 * \param[in] arg input CO_LexByte
 * \return ATtrue if the CO_LexByte had a ch, or ATfalse otherwise
 */
ATbool CO_hasLexByteCh(CO_LexByte arg) {
  if (CO_isLexByteByte(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ch char of a CO_LexByte. Note that the precondition is that this CO_LexByte actually has a ch
 * \param[in] arg input CO_LexByte
 * \return the ch of #arg, if it exist or an undefined value if it does not
 */
char CO_getLexByteCh(CO_LexByte arg) {
  
    return (char)CO_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/**
 * Set the ch of a CO_LexByte. The precondition being that this CO_LexByte actually has a ch
 * \param[in] arg input CO_LexByte
 * \param[in] ch new char to set in #arg
 * \return A new CO_LexByte with ch at the right place, or a core dump if #arg did not have a ch
 */
CO_LexByte CO_setLexByteCh(CO_LexByte arg, char ch) {
  if (CO_isLexByteByte(arg)) {
    return (CO_LexByte)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) CO_byteToChar(ch))), 0), 1);
  }

  ATabort("LexByte has no Ch: %t\n", arg);
  return (CO_LexByte)NULL;
}

/**
 * Assert whether a CO_Byte is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_Byte
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidByte(CO_Byte arg) {
  if (CO_isByteLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Byte is a Lex-to-cf. Always returns ATtrue
 * \param[in] arg input CO_Byte
 * \return ATtrue if #arg corresponds to the signature of a Lex-to-cf, or ATfalse otherwise
 */
inline ATbool CO_isByteLexToCf(CO_Byte arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternByteLexToCf, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_Byte has a Byte. 
 * \param[in] arg input CO_Byte
 * \return ATtrue if the CO_Byte had a Byte, or ATfalse otherwise
 */
ATbool CO_hasByteByte(CO_Byte arg) {
  if (CO_isByteLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the Byte CO_LexByte of a CO_Byte. Note that the precondition is that this CO_Byte actually has a Byte
 * \param[in] arg input CO_Byte
 * \return the Byte of #arg, if it exist or an undefined value if it does not
 */
CO_LexByte CO_getByteByte(CO_Byte arg) {
  
    return (CO_LexByte)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the Byte of a CO_Byte. The precondition being that this CO_Byte actually has a Byte
 * \param[in] arg input CO_Byte
 * \param[in] Byte new CO_LexByte to set in #arg
 * \return A new CO_Byte with Byte at the right place, or a core dump if #arg did not have a Byte
 */
CO_Byte CO_setByteByte(CO_Byte arg, CO_LexByte Byte) {
  if (CO_isByteLexToCf(arg)) {
    return (CO_Byte)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Byte), 0), 1);
  }

  ATabort("Byte has no Byte: %t\n", arg);
  return (CO_Byte)NULL;
}

/**
 * Assert whether a CO_LexBytes is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_LexBytes
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidLexBytes(CO_LexBytes arg) {
  if (CO_isLexBytesBytes(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_LexBytes is a bytes. Always returns ATtrue
 * \param[in] arg input CO_LexBytes
 * \return ATtrue if #arg corresponds to the signature of a bytes, or ATfalse otherwise
 */
inline ATbool CO_isLexBytesBytes(CO_LexBytes arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexBytesBytes, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_LexBytes has a list. 
 * \param[in] arg input CO_LexBytes
 * \return ATtrue if the CO_LexBytes had a list, or ATfalse otherwise
 */
ATbool CO_hasLexBytesList(CO_LexBytes arg) {
  if (CO_isLexBytesBytes(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the list CO_LexByteList of a CO_LexBytes. Note that the precondition is that this CO_LexBytes actually has a list
 * \param[in] arg input CO_LexBytes
 * \return the list of #arg, if it exist or an undefined value if it does not
 */
CO_LexByteList CO_getLexBytesList(CO_LexBytes arg) {
  
    return (CO_LexByteList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/**
 * Set the list of a CO_LexBytes. The precondition being that this CO_LexBytes actually has a list
 * \param[in] arg input CO_LexBytes
 * \param[in] list new CO_LexByteList to set in #arg
 * \return A new CO_LexBytes with list at the right place, or a core dump if #arg did not have a list
 */
CO_LexBytes CO_setLexBytesList(CO_LexBytes arg, CO_LexByteList list) {
  if (CO_isLexBytesBytes(arg)) {
    return (CO_LexBytes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) list), 1), 0), 1);
  }

  ATabort("LexBytes has no List: %t\n", arg);
  return (CO_LexBytes)NULL;
}

/**
 * Assert whether a CO_Bytes is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_Bytes
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidBytes(CO_Bytes arg) {
  if (CO_isBytesLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Bytes is a Lex-to-cf. Always returns ATtrue
 * \param[in] arg input CO_Bytes
 * \return ATtrue if #arg corresponds to the signature of a Lex-to-cf, or ATfalse otherwise
 */
inline ATbool CO_isBytesLexToCf(CO_Bytes arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternBytesLexToCf, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_Bytes has a Bytes. 
 * \param[in] arg input CO_Bytes
 * \return ATtrue if the CO_Bytes had a Bytes, or ATfalse otherwise
 */
ATbool CO_hasBytesBytes(CO_Bytes arg) {
  if (CO_isBytesLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the Bytes CO_LexBytes of a CO_Bytes. Note that the precondition is that this CO_Bytes actually has a Bytes
 * \param[in] arg input CO_Bytes
 * \return the Bytes of #arg, if it exist or an undefined value if it does not
 */
CO_LexBytes CO_getBytesBytes(CO_Bytes arg) {
  
    return (CO_LexBytes)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the Bytes of a CO_Bytes. The precondition being that this CO_Bytes actually has a Bytes
 * \param[in] arg input CO_Bytes
 * \param[in] Bytes new CO_LexBytes to set in #arg
 * \return A new CO_Bytes with Bytes at the right place, or a core dump if #arg did not have a Bytes
 */
CO_Bytes CO_setBytesBytes(CO_Bytes arg, CO_LexBytes Bytes) {
  if (CO_isBytesLexToCf(arg)) {
    return (CO_Bytes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Bytes), 0), 1);
  }

  ATabort("Bytes has no Bytes: %t\n", arg);
  return (CO_Bytes)NULL;
}

/**
 * Assert whether a CO_LexByteList is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_LexByteList
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidLexByteList(CO_LexByteList arg) {
  if (CO_isLexByteListEmpty(arg)) {
    return ATtrue;
  }
  else if (CO_isLexByteListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isLexByteListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_LexByteList is a empty. . May not be used to assert correctness of the CO_LexByteList
 * \param[in] arg input CO_LexByteList
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool CO_isLexByteListEmpty(CO_LexByteList arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexByteListEmpty));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_LexByteList is a single. . May not be used to assert correctness of the CO_LexByteList
 * \param[in] arg input CO_LexByteList
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool CO_isLexByteListSingle(CO_LexByteList arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexByteListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_LexByteList is a many. . May not be used to assert correctness of the CO_LexByteList
 * \param[in] arg input CO_LexByteList
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool CO_isLexByteListMany(CO_LexByteList arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexByteListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_LexByteList has a head. 
 * \param[in] arg input CO_LexByteList
 * \return ATtrue if the CO_LexByteList had a head, or ATfalse otherwise
 */
ATbool CO_hasLexByteListHead(CO_LexByteList arg) {
  if (CO_isLexByteListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isLexByteListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_LexByteList has a tail. 
 * \param[in] arg input CO_LexByteList
 * \return ATtrue if the CO_LexByteList had a tail, or ATfalse otherwise
 */
ATbool CO_hasLexByteListTail(CO_LexByteList arg) {
  if (CO_isLexByteListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head CO_LexByte of a CO_LexByteList. Note that the precondition is that this CO_LexByteList actually has a head
 * \param[in] arg input CO_LexByteList
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
CO_LexByte CO_getLexByteListHead(CO_LexByteList arg) {
  if (CO_isLexByteListSingle(arg)) {
    return (CO_LexByte)ATgetFirst((ATermList)arg);
  }
  else 
    return (CO_LexByte)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail CO_LexByteList of a CO_LexByteList. Note that the precondition is that this CO_LexByteList actually has a tail
 * \param[in] arg input CO_LexByteList
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
CO_LexByteList CO_getLexByteListTail(CO_LexByteList arg) {
  
    return (CO_LexByteList)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a CO_LexByteList. The precondition being that this CO_LexByteList actually has a head
 * \param[in] arg input CO_LexByteList
 * \param[in] head new CO_LexByte to set in #arg
 * \return A new CO_LexByteList with head at the right place, or a core dump if #arg did not have a head
 */
CO_LexByteList CO_setLexByteListHead(CO_LexByteList arg, CO_LexByte head) {
  if (CO_isLexByteListSingle(arg)) {
    return (CO_LexByteList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CO_isLexByteListMany(arg)) {
    return (CO_LexByteList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexByteList has no Head: %t\n", arg);
  return (CO_LexByteList)NULL;
}

/**
 * Set the tail of a CO_LexByteList. The precondition being that this CO_LexByteList actually has a tail
 * \param[in] arg input CO_LexByteList
 * \param[in] tail new CO_LexByteList to set in #arg
 * \return A new CO_LexByteList with tail at the right place, or a core dump if #arg did not have a tail
 */
CO_LexByteList CO_setLexByteListTail(CO_LexByteList arg, CO_LexByteList tail) {
  if (CO_isLexByteListMany(arg)) {
    return (CO_LexByteList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexByteList has no Tail: %t\n", arg);
  return (CO_LexByteList)NULL;
}

/**
 * Assert whether a CO_Subject is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_Subject
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidSubject(CO_Subject arg) {
  if (CO_isSubjectSubject(arg)) {
    return ATtrue;
  }
  else if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Subject is a subject. . May not be used to assert correctness of the CO_Subject
 * \param[in] arg input CO_Subject
 * \return ATtrue if #arg corresponds to the signature of a subject, or ATfalse otherwise
 */
inline ATbool CO_isSubjectSubject(CO_Subject arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternSubjectSubject, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Subject is a localized. . May not be used to assert correctness of the CO_Subject
 * \param[in] arg input CO_Subject
 * \return ATtrue if #arg corresponds to the signature of a localized, or ATfalse otherwise
 */
inline ATbool CO_isSubjectLocalized(CO_Subject arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternSubjectLocalized, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Subject has a ws-after-subject. 
 * \param[in] arg input CO_Subject
 * \return ATtrue if the CO_Subject had a ws-after-subject, or ATfalse otherwise
 */
ATbool CO_hasSubjectWsAfterSubject(CO_Subject arg) {
  if (CO_isSubjectSubject(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Subject has a ws-after-(. 
 * \param[in] arg input CO_Subject
 * \return ATtrue if the CO_Subject had a ws-after-(, or ATfalse otherwise
 */
ATbool CO_hasSubjectWsAfterParenOpen(CO_Subject arg) {
  if (CO_isSubjectSubject(arg)) {
    return ATtrue;
  }
  else if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Subject has a description. 
 * \param[in] arg input CO_Subject
 * \return ATtrue if the CO_Subject had a description, or ATfalse otherwise
 */
ATbool CO_hasSubjectDescription(CO_Subject arg) {
  if (CO_isSubjectSubject(arg)) {
    return ATtrue;
  }
  else if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Subject has a ws-after-description. 
 * \param[in] arg input CO_Subject
 * \return ATtrue if the CO_Subject had a ws-after-description, or ATfalse otherwise
 */
ATbool CO_hasSubjectWsAfterDescription(CO_Subject arg) {
  if (CO_isSubjectSubject(arg)) {
    return ATtrue;
  }
  else if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Subject has a ws-after-localized. 
 * \param[in] arg input CO_Subject
 * \return ATtrue if the CO_Subject had a ws-after-localized, or ATfalse otherwise
 */
ATbool CO_hasSubjectWsAfterLocalized(CO_Subject arg) {
  if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Subject has a ws-after-,. 
 * \param[in] arg input CO_Subject
 * \return ATtrue if the CO_Subject had a ws-after-,, or ATfalse otherwise
 */
ATbool CO_hasSubjectWsAfterComma(CO_Subject arg) {
  if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Subject has a Location. 
 * \param[in] arg input CO_Subject
 * \return ATtrue if the CO_Subject had a Location, or ATfalse otherwise
 */
ATbool CO_hasSubjectLocation(CO_Subject arg) {
  if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Subject has a ws-after-Location. 
 * \param[in] arg input CO_Subject
 * \return ATtrue if the CO_Subject had a ws-after-Location, or ATfalse otherwise
 */
ATbool CO_hasSubjectWsAfterLocation(CO_Subject arg) {
  if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ws-after-subject CO_OptLayout of a CO_Subject. Note that the precondition is that this CO_Subject actually has a ws-after-subject
 * \param[in] arg input CO_Subject
 * \return the ws-after-subject of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSubjectWsAfterSubject(CO_Subject arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-( CO_OptLayout of a CO_Subject. Note that the precondition is that this CO_Subject actually has a ws-after-(
 * \param[in] arg input CO_Subject
 * \return the ws-after-( of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSubjectWsAfterParenOpen(CO_Subject arg) {
  if (CO_isSubjectSubject(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the description CO_StrCon of a CO_Subject. Note that the precondition is that this CO_Subject actually has a description
 * \param[in] arg input CO_Subject
 * \return the description of #arg, if it exist or an undefined value if it does not
 */
CO_StrCon CO_getSubjectDescription(CO_Subject arg) {
  if (CO_isSubjectSubject(arg)) {
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/**
 * Get the ws-after-description CO_OptLayout of a CO_Subject. Note that the precondition is that this CO_Subject actually has a ws-after-description
 * \param[in] arg input CO_Subject
 * \return the ws-after-description of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSubjectWsAfterDescription(CO_Subject arg) {
  if (CO_isSubjectSubject(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Get the ws-after-localized CO_OptLayout of a CO_Subject. Note that the precondition is that this CO_Subject actually has a ws-after-localized
 * \param[in] arg input CO_Subject
 * \return the ws-after-localized of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSubjectWsAfterLocalized(CO_Subject arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-, CO_OptLayout of a CO_Subject. Note that the precondition is that this CO_Subject actually has a ws-after-,
 * \param[in] arg input CO_Subject
 * \return the ws-after-, of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSubjectWsAfterComma(CO_Subject arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/**
 * Get the Location CO_Location of a CO_Subject. Note that the precondition is that this CO_Subject actually has a Location
 * \param[in] arg input CO_Subject
 * \return the Location of #arg, if it exist or an undefined value if it does not
 */
CO_Location CO_getSubjectLocation(CO_Subject arg) {
  
    return (CO_Location)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/**
 * Get the ws-after-Location CO_OptLayout of a CO_Subject. Note that the precondition is that this CO_Subject actually has a ws-after-Location
 * \param[in] arg input CO_Subject
 * \return the ws-after-Location of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSubjectWsAfterLocation(CO_Subject arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/**
 * Set the ws-after-subject of a CO_Subject. The precondition being that this CO_Subject actually has a ws-after-subject
 * \param[in] arg input CO_Subject
 * \param[in] wsAfterSubject new CO_OptLayout to set in #arg
 * \return A new CO_Subject with wsAfterSubject at the right place, or a core dump if #arg did not have a wsAfterSubject
 */
CO_Subject CO_setSubjectWsAfterSubject(CO_Subject arg, CO_OptLayout wsAfterSubject) {
  if (CO_isSubjectSubject(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSubject), 1), 1);
  }

  ATabort("Subject has no WsAfterSubject: %t\n", arg);
  return (CO_Subject)NULL;
}

/**
 * Set the ws-after-( of a CO_Subject. The precondition being that this CO_Subject actually has a ws-after-(
 * \param[in] arg input CO_Subject
 * \param[in] wsAfterParenOpen new CO_OptLayout to set in #arg
 * \return A new CO_Subject with wsAfterParenOpen at the right place, or a core dump if #arg did not have a wsAfterParenOpen
 */
CO_Subject CO_setSubjectWsAfterParenOpen(CO_Subject arg, CO_OptLayout wsAfterParenOpen) {
  if (CO_isSubjectSubject(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isSubjectLocalized(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Subject has no WsAfterParenOpen: %t\n", arg);
  return (CO_Subject)NULL;
}

/**
 * Set the description of a CO_Subject. The precondition being that this CO_Subject actually has a description
 * \param[in] arg input CO_Subject
 * \param[in] description new CO_StrCon to set in #arg
 * \return A new CO_Subject with description at the right place, or a core dump if #arg did not have a description
 */
CO_Subject CO_setSubjectDescription(CO_Subject arg, CO_StrCon description) {
  if (CO_isSubjectSubject(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 4), 1);
  }
  else if (CO_isSubjectLocalized(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 4), 1);
  }

  ATabort("Subject has no Description: %t\n", arg);
  return (CO_Subject)NULL;
}

/**
 * Set the ws-after-description of a CO_Subject. The precondition being that this CO_Subject actually has a ws-after-description
 * \param[in] arg input CO_Subject
 * \param[in] wsAfterDescription new CO_OptLayout to set in #arg
 * \return A new CO_Subject with wsAfterDescription at the right place, or a core dump if #arg did not have a wsAfterDescription
 */
CO_Subject CO_setSubjectWsAfterDescription(CO_Subject arg, CO_OptLayout wsAfterDescription) {
  if (CO_isSubjectSubject(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 5), 1);
  }
  else if (CO_isSubjectLocalized(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 5), 1);
  }

  ATabort("Subject has no WsAfterDescription: %t\n", arg);
  return (CO_Subject)NULL;
}

/**
 * Set the ws-after-localized of a CO_Subject. The precondition being that this CO_Subject actually has a ws-after-localized
 * \param[in] arg input CO_Subject
 * \param[in] wsAfterLocalized new CO_OptLayout to set in #arg
 * \return A new CO_Subject with wsAfterLocalized at the right place, or a core dump if #arg did not have a wsAfterLocalized
 */
CO_Subject CO_setSubjectWsAfterLocalized(CO_Subject arg, CO_OptLayout wsAfterLocalized) {
  if (CO_isSubjectLocalized(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLocalized), 1), 1);
  }

  ATabort("Subject has no WsAfterLocalized: %t\n", arg);
  return (CO_Subject)NULL;
}

/**
 * Set the ws-after-, of a CO_Subject. The precondition being that this CO_Subject actually has a ws-after-,
 * \param[in] arg input CO_Subject
 * \param[in] wsAfterComma new CO_OptLayout to set in #arg
 * \return A new CO_Subject with wsAfterComma at the right place, or a core dump if #arg did not have a wsAfterComma
 */
CO_Subject CO_setSubjectWsAfterComma(CO_Subject arg, CO_OptLayout wsAfterComma) {
  if (CO_isSubjectLocalized(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Subject has no WsAfterComma: %t\n", arg);
  return (CO_Subject)NULL;
}

/**
 * Set the Location of a CO_Subject. The precondition being that this CO_Subject actually has a Location
 * \param[in] arg input CO_Subject
 * \param[in] Location new CO_Location to set in #arg
 * \return A new CO_Subject with Location at the right place, or a core dump if #arg did not have a Location
 */
CO_Subject CO_setSubjectLocation(CO_Subject arg, CO_Location Location) {
  if (CO_isSubjectLocalized(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Location), 8), 1);
  }

  ATabort("Subject has no Location: %t\n", arg);
  return (CO_Subject)NULL;
}

/**
 * Set the ws-after-Location of a CO_Subject. The precondition being that this CO_Subject actually has a ws-after-Location
 * \param[in] arg input CO_Subject
 * \param[in] wsAfterLocation new CO_OptLayout to set in #arg
 * \return A new CO_Subject with wsAfterLocation at the right place, or a core dump if #arg did not have a wsAfterLocation
 */
CO_Subject CO_setSubjectWsAfterLocation(CO_Subject arg, CO_OptLayout wsAfterLocation) {
  if (CO_isSubjectLocalized(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLocation), 9), 1);
  }

  ATabort("Subject has no WsAfterLocation: %t\n", arg);
  return (CO_Subject)NULL;
}

/**
 * Assert whether a CO_Error is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_Error
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidError(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Error is a info. . May not be used to assert correctness of the CO_Error
 * \param[in] arg input CO_Error
 * \return ATtrue if #arg corresponds to the signature of a info, or ATfalse otherwise
 */
inline ATbool CO_isErrorInfo(CO_Error arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternErrorInfo, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Error is a warning. . May not be used to assert correctness of the CO_Error
 * \param[in] arg input CO_Error
 * \return ATtrue if #arg corresponds to the signature of a warning, or ATfalse otherwise
 */
inline ATbool CO_isErrorWarning(CO_Error arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternErrorWarning, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Error is a error. . May not be used to assert correctness of the CO_Error
 * \param[in] arg input CO_Error
 * \return ATtrue if #arg corresponds to the signature of a error, or ATfalse otherwise
 */
inline ATbool CO_isErrorError(CO_Error arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternErrorError, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Error is a fatal. . May not be used to assert correctness of the CO_Error
 * \param[in] arg input CO_Error
 * \return ATtrue if #arg corresponds to the signature of a fatal, or ATfalse otherwise
 */
inline ATbool CO_isErrorFatal(CO_Error arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternErrorFatal, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Error has a ws-after-info. 
 * \param[in] arg input CO_Error
 * \return ATtrue if the CO_Error had a ws-after-info, or ATfalse otherwise
 */
ATbool CO_hasErrorWsAfterInfo(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Error has a ws-after-(. 
 * \param[in] arg input CO_Error
 * \return ATtrue if the CO_Error had a ws-after-(, or ATfalse otherwise
 */
ATbool CO_hasErrorWsAfterParenOpen(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Error has a description. 
 * \param[in] arg input CO_Error
 * \return ATtrue if the CO_Error had a description, or ATfalse otherwise
 */
ATbool CO_hasErrorDescription(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Error has a ws-after-description. 
 * \param[in] arg input CO_Error
 * \return ATtrue if the CO_Error had a ws-after-description, or ATfalse otherwise
 */
ATbool CO_hasErrorWsAfterDescription(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Error has a ws-after-,. 
 * \param[in] arg input CO_Error
 * \return ATtrue if the CO_Error had a ws-after-,, or ATfalse otherwise
 */
ATbool CO_hasErrorWsAfterComma(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Error has a ws-after-[. 
 * \param[in] arg input CO_Error
 * \return ATtrue if the CO_Error had a ws-after-[, or ATfalse otherwise
 */
ATbool CO_hasErrorWsAfterBracketOpen(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Error has a list. 
 * \param[in] arg input CO_Error
 * \return ATtrue if the CO_Error had a list, or ATfalse otherwise
 */
ATbool CO_hasErrorList(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Error has a ws-after-list. 
 * \param[in] arg input CO_Error
 * \return ATtrue if the CO_Error had a ws-after-list, or ATfalse otherwise
 */
ATbool CO_hasErrorWsAfterList(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Error has a ws-after-]. 
 * \param[in] arg input CO_Error
 * \return ATtrue if the CO_Error had a ws-after-], or ATfalse otherwise
 */
ATbool CO_hasErrorWsAfterBracketClose(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Error has a ws-after-warning. 
 * \param[in] arg input CO_Error
 * \return ATtrue if the CO_Error had a ws-after-warning, or ATfalse otherwise
 */
ATbool CO_hasErrorWsAfterWarning(CO_Error arg) {
  if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Error has a ws-after-error. 
 * \param[in] arg input CO_Error
 * \return ATtrue if the CO_Error had a ws-after-error, or ATfalse otherwise
 */
ATbool CO_hasErrorWsAfterError(CO_Error arg) {
  if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Error has a ws-after-fatal. 
 * \param[in] arg input CO_Error
 * \return ATtrue if the CO_Error had a ws-after-fatal, or ATfalse otherwise
 */
ATbool CO_hasErrorWsAfterFatal(CO_Error arg) {
  if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ws-after-info CO_OptLayout of a CO_Error. Note that the precondition is that this CO_Error actually has a ws-after-info
 * \param[in] arg input CO_Error
 * \return the ws-after-info of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getErrorWsAfterInfo(CO_Error arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-( CO_OptLayout of a CO_Error. Note that the precondition is that this CO_Error actually has a ws-after-(
 * \param[in] arg input CO_Error
 * \return the ws-after-( of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getErrorWsAfterParenOpen(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the description CO_StrCon of a CO_Error. Note that the precondition is that this CO_Error actually has a description
 * \param[in] arg input CO_Error
 * \return the description of #arg, if it exist or an undefined value if it does not
 */
CO_StrCon CO_getErrorDescription(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/**
 * Get the ws-after-description CO_OptLayout of a CO_Error. Note that the precondition is that this CO_Error actually has a ws-after-description
 * \param[in] arg input CO_Error
 * \return the ws-after-description of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getErrorWsAfterDescription(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Get the ws-after-, CO_OptLayout of a CO_Error. Note that the precondition is that this CO_Error actually has a ws-after-,
 * \param[in] arg input CO_Error
 * \return the ws-after-, of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getErrorWsAfterComma(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/**
 * Get the ws-after-[ CO_OptLayout of a CO_Error. Note that the precondition is that this CO_Error actually has a ws-after-[
 * \param[in] arg input CO_Error
 * \return the ws-after-[ of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getErrorWsAfterBracketOpen(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/**
 * Get the list CO_SubjectList of a CO_Error. Note that the precondition is that this CO_Error actually has a list
 * \param[in] arg input CO_Error
 * \return the list of #arg, if it exist or an undefined value if it does not
 */
CO_SubjectList CO_getErrorList(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return (CO_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), 1);
  }
  else 
    return (CO_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), 1);
}

/**
 * Get the ws-after-list CO_OptLayout of a CO_Error. Note that the precondition is that this CO_Error actually has a ws-after-list
 * \param[in] arg input CO_Error
 * \return the ws-after-list of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getErrorWsAfterList(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/**
 * Get the ws-after-] CO_OptLayout of a CO_Error. Note that the precondition is that this CO_Error actually has a ws-after-]
 * \param[in] arg input CO_Error
 * \return the ws-after-] of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getErrorWsAfterBracketClose(CO_Error arg) {
  if (CO_isErrorInfo(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/**
 * Get the ws-after-warning CO_OptLayout of a CO_Error. Note that the precondition is that this CO_Error actually has a ws-after-warning
 * \param[in] arg input CO_Error
 * \return the ws-after-warning of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getErrorWsAfterWarning(CO_Error arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-error CO_OptLayout of a CO_Error. Note that the precondition is that this CO_Error actually has a ws-after-error
 * \param[in] arg input CO_Error
 * \return the ws-after-error of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getErrorWsAfterError(CO_Error arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-fatal CO_OptLayout of a CO_Error. Note that the precondition is that this CO_Error actually has a ws-after-fatal
 * \param[in] arg input CO_Error
 * \return the ws-after-fatal of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getErrorWsAfterFatal(CO_Error arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Set the ws-after-info of a CO_Error. The precondition being that this CO_Error actually has a ws-after-info
 * \param[in] arg input CO_Error
 * \param[in] wsAfterInfo new CO_OptLayout to set in #arg
 * \return A new CO_Error with wsAfterInfo at the right place, or a core dump if #arg did not have a wsAfterInfo
 */
CO_Error CO_setErrorWsAfterInfo(CO_Error arg, CO_OptLayout wsAfterInfo) {
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterInfo), 1), 1);
  }

  ATabort("Error has no WsAfterInfo: %t\n", arg);
  return (CO_Error)NULL;
}

/**
 * Set the ws-after-( of a CO_Error. The precondition being that this CO_Error actually has a ws-after-(
 * \param[in] arg input CO_Error
 * \param[in] wsAfterParenOpen new CO_OptLayout to set in #arg
 * \return A new CO_Error with wsAfterParenOpen at the right place, or a core dump if #arg did not have a wsAfterParenOpen
 */
CO_Error CO_setErrorWsAfterParenOpen(CO_Error arg, CO_OptLayout wsAfterParenOpen) {
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Error has no WsAfterParenOpen: %t\n", arg);
  return (CO_Error)NULL;
}

/**
 * Set the description of a CO_Error. The precondition being that this CO_Error actually has a description
 * \param[in] arg input CO_Error
 * \param[in] description new CO_StrCon to set in #arg
 * \return A new CO_Error with description at the right place, or a core dump if #arg did not have a description
 */
CO_Error CO_setErrorDescription(CO_Error arg, CO_StrCon description) {
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 4), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 4), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 4), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 4), 1);
  }

  ATabort("Error has no Description: %t\n", arg);
  return (CO_Error)NULL;
}

/**
 * Set the ws-after-description of a CO_Error. The precondition being that this CO_Error actually has a ws-after-description
 * \param[in] arg input CO_Error
 * \param[in] wsAfterDescription new CO_OptLayout to set in #arg
 * \return A new CO_Error with wsAfterDescription at the right place, or a core dump if #arg did not have a wsAfterDescription
 */
CO_Error CO_setErrorWsAfterDescription(CO_Error arg, CO_OptLayout wsAfterDescription) {
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 5), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 5), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 5), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 5), 1);
  }

  ATabort("Error has no WsAfterDescription: %t\n", arg);
  return (CO_Error)NULL;
}

/**
 * Set the ws-after-, of a CO_Error. The precondition being that this CO_Error actually has a ws-after-,
 * \param[in] arg input CO_Error
 * \param[in] wsAfterComma new CO_OptLayout to set in #arg
 * \return A new CO_Error with wsAfterComma at the right place, or a core dump if #arg did not have a wsAfterComma
 */
CO_Error CO_setErrorWsAfterComma(CO_Error arg, CO_OptLayout wsAfterComma) {
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Error has no WsAfterComma: %t\n", arg);
  return (CO_Error)NULL;
}

/**
 * Set the ws-after-[ of a CO_Error. The precondition being that this CO_Error actually has a ws-after-[
 * \param[in] arg input CO_Error
 * \param[in] wsAfterBracketOpen new CO_OptLayout to set in #arg
 * \return A new CO_Error with wsAfterBracketOpen at the right place, or a core dump if #arg did not have a wsAfterBracketOpen
 */
CO_Error CO_setErrorWsAfterBracketOpen(CO_Error arg, CO_OptLayout wsAfterBracketOpen) {
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 9), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 9), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 9), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 9), 1);
  }

  ATabort("Error has no WsAfterBracketOpen: %t\n", arg);
  return (CO_Error)NULL;
}

/**
 * Set the list of a CO_Error. The precondition being that this CO_Error actually has a list
 * \param[in] arg input CO_Error
 * \param[in] list new CO_SubjectList to set in #arg
 * \return A new CO_Error with list at the right place, or a core dump if #arg did not have a list
 */
CO_Error CO_setErrorList(CO_Error arg, CO_SubjectList list) {
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), (ATerm)((ATerm) list), 1), 10), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), (ATerm)((ATerm) list), 1), 10), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), (ATerm)((ATerm) list), 1), 10), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), (ATerm)((ATerm) list), 1), 10), 1);
  }

  ATabort("Error has no List: %t\n", arg);
  return (CO_Error)NULL;
}

/**
 * Set the ws-after-list of a CO_Error. The precondition being that this CO_Error actually has a ws-after-list
 * \param[in] arg input CO_Error
 * \param[in] wsAfterList new CO_OptLayout to set in #arg
 * \return A new CO_Error with wsAfterList at the right place, or a core dump if #arg did not have a wsAfterList
 */
CO_Error CO_setErrorWsAfterList(CO_Error arg, CO_OptLayout wsAfterList) {
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 11), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 11), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 11), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 11), 1);
  }

  ATabort("Error has no WsAfterList: %t\n", arg);
  return (CO_Error)NULL;
}

/**
 * Set the ws-after-] of a CO_Error. The precondition being that this CO_Error actually has a ws-after-]
 * \param[in] arg input CO_Error
 * \param[in] wsAfterBracketClose new CO_OptLayout to set in #arg
 * \return A new CO_Error with wsAfterBracketClose at the right place, or a core dump if #arg did not have a wsAfterBracketClose
 */
CO_Error CO_setErrorWsAfterBracketClose(CO_Error arg, CO_OptLayout wsAfterBracketClose) {
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 13), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 13), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 13), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 13), 1);
  }

  ATabort("Error has no WsAfterBracketClose: %t\n", arg);
  return (CO_Error)NULL;
}

/**
 * Set the ws-after-warning of a CO_Error. The precondition being that this CO_Error actually has a ws-after-warning
 * \param[in] arg input CO_Error
 * \param[in] wsAfterWarning new CO_OptLayout to set in #arg
 * \return A new CO_Error with wsAfterWarning at the right place, or a core dump if #arg did not have a wsAfterWarning
 */
CO_Error CO_setErrorWsAfterWarning(CO_Error arg, CO_OptLayout wsAfterWarning) {
  if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterWarning), 1), 1);
  }

  ATabort("Error has no WsAfterWarning: %t\n", arg);
  return (CO_Error)NULL;
}

/**
 * Set the ws-after-error of a CO_Error. The precondition being that this CO_Error actually has a ws-after-error
 * \param[in] arg input CO_Error
 * \param[in] wsAfterError new CO_OptLayout to set in #arg
 * \return A new CO_Error with wsAfterError at the right place, or a core dump if #arg did not have a wsAfterError
 */
CO_Error CO_setErrorWsAfterError(CO_Error arg, CO_OptLayout wsAfterError) {
  if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterError), 1), 1);
  }

  ATabort("Error has no WsAfterError: %t\n", arg);
  return (CO_Error)NULL;
}

/**
 * Set the ws-after-fatal of a CO_Error. The precondition being that this CO_Error actually has a ws-after-fatal
 * \param[in] arg input CO_Error
 * \param[in] wsAfterFatal new CO_OptLayout to set in #arg
 * \return A new CO_Error with wsAfterFatal at the right place, or a core dump if #arg did not have a wsAfterFatal
 */
CO_Error CO_setErrorWsAfterFatal(CO_Error arg, CO_OptLayout wsAfterFatal) {
  if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFatal), 1), 1);
  }

  ATabort("Error has no WsAfterFatal: %t\n", arg);
  return (CO_Error)NULL;
}

/**
 * Assert whether a CO_Summary is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_Summary
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidSummary(CO_Summary arg) {
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Summary is a summary. Always returns ATtrue
 * \param[in] arg input CO_Summary
 * \return ATtrue if #arg corresponds to the signature of a summary, or ATfalse otherwise
 */
inline ATbool CO_isSummarySummary(CO_Summary arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternSummarySummary, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_Summary has a ws-after-summary. 
 * \param[in] arg input CO_Summary
 * \return ATtrue if the CO_Summary had a ws-after-summary, or ATfalse otherwise
 */
ATbool CO_hasSummaryWsAfterSummary(CO_Summary arg) {
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Summary has a ws-after-(. 
 * \param[in] arg input CO_Summary
 * \return ATtrue if the CO_Summary had a ws-after-(, or ATfalse otherwise
 */
ATbool CO_hasSummaryWsAfterParenOpen(CO_Summary arg) {
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Summary has a producer. 
 * \param[in] arg input CO_Summary
 * \return ATtrue if the CO_Summary had a producer, or ATfalse otherwise
 */
ATbool CO_hasSummaryProducer(CO_Summary arg) {
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Summary has a ws-after-producer. 
 * \param[in] arg input CO_Summary
 * \return ATtrue if the CO_Summary had a ws-after-producer, or ATfalse otherwise
 */
ATbool CO_hasSummaryWsAfterProducer(CO_Summary arg) {
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Summary has a ws-after-,. 
 * \param[in] arg input CO_Summary
 * \return ATtrue if the CO_Summary had a ws-after-,, or ATfalse otherwise
 */
ATbool CO_hasSummaryWsAfterComma(CO_Summary arg) {
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Summary has a id. 
 * \param[in] arg input CO_Summary
 * \return ATtrue if the CO_Summary had a id, or ATfalse otherwise
 */
ATbool CO_hasSummaryId(CO_Summary arg) {
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Summary has a ws-after-id. 
 * \param[in] arg input CO_Summary
 * \return ATtrue if the CO_Summary had a ws-after-id, or ATfalse otherwise
 */
ATbool CO_hasSummaryWsAfterId(CO_Summary arg) {
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Summary has a ws-after-,-1. 
 * \param[in] arg input CO_Summary
 * \return ATtrue if the CO_Summary had a ws-after-,-1, or ATfalse otherwise
 */
ATbool CO_hasSummaryWsAfterComma1(CO_Summary arg) {
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Summary has a ws-after-[. 
 * \param[in] arg input CO_Summary
 * \return ATtrue if the CO_Summary had a ws-after-[, or ATfalse otherwise
 */
ATbool CO_hasSummaryWsAfterBracketOpen(CO_Summary arg) {
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Summary has a list. 
 * \param[in] arg input CO_Summary
 * \return ATtrue if the CO_Summary had a list, or ATfalse otherwise
 */
ATbool CO_hasSummaryList(CO_Summary arg) {
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Summary has a ws-after-list. 
 * \param[in] arg input CO_Summary
 * \return ATtrue if the CO_Summary had a ws-after-list, or ATfalse otherwise
 */
ATbool CO_hasSummaryWsAfterList(CO_Summary arg) {
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Summary has a ws-after-]. 
 * \param[in] arg input CO_Summary
 * \return ATtrue if the CO_Summary had a ws-after-], or ATfalse otherwise
 */
ATbool CO_hasSummaryWsAfterBracketClose(CO_Summary arg) {
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ws-after-summary CO_OptLayout of a CO_Summary. Note that the precondition is that this CO_Summary actually has a ws-after-summary
 * \param[in] arg input CO_Summary
 * \return the ws-after-summary of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSummaryWsAfterSummary(CO_Summary arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-( CO_OptLayout of a CO_Summary. Note that the precondition is that this CO_Summary actually has a ws-after-(
 * \param[in] arg input CO_Summary
 * \return the ws-after-( of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSummaryWsAfterParenOpen(CO_Summary arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the producer CO_StrCon of a CO_Summary. Note that the precondition is that this CO_Summary actually has a producer
 * \param[in] arg input CO_Summary
 * \return the producer of #arg, if it exist or an undefined value if it does not
 */
CO_StrCon CO_getSummaryProducer(CO_Summary arg) {
  
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/**
 * Get the ws-after-producer CO_OptLayout of a CO_Summary. Note that the precondition is that this CO_Summary actually has a ws-after-producer
 * \param[in] arg input CO_Summary
 * \return the ws-after-producer of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSummaryWsAfterProducer(CO_Summary arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Get the ws-after-, CO_OptLayout of a CO_Summary. Note that the precondition is that this CO_Summary actually has a ws-after-,
 * \param[in] arg input CO_Summary
 * \return the ws-after-, of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSummaryWsAfterComma(CO_Summary arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/**
 * Get the id CO_StrCon of a CO_Summary. Note that the precondition is that this CO_Summary actually has a id
 * \param[in] arg input CO_Summary
 * \return the id of #arg, if it exist or an undefined value if it does not
 */
CO_StrCon CO_getSummaryId(CO_Summary arg) {
  
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/**
 * Get the ws-after-id CO_OptLayout of a CO_Summary. Note that the precondition is that this CO_Summary actually has a ws-after-id
 * \param[in] arg input CO_Summary
 * \return the ws-after-id of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSummaryWsAfterId(CO_Summary arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/**
 * Get the ws-after-,-1 CO_OptLayout of a CO_Summary. Note that the precondition is that this CO_Summary actually has a ws-after-,-1
 * \param[in] arg input CO_Summary
 * \return the ws-after-,-1 of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSummaryWsAfterComma1(CO_Summary arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/**
 * Get the ws-after-[ CO_OptLayout of a CO_Summary. Note that the precondition is that this CO_Summary actually has a ws-after-[
 * \param[in] arg input CO_Summary
 * \return the ws-after-[ of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSummaryWsAfterBracketOpen(CO_Summary arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/**
 * Get the list CO_ErrorList of a CO_Summary. Note that the precondition is that this CO_Summary actually has a list
 * \param[in] arg input CO_Summary
 * \return the list of #arg, if it exist or an undefined value if it does not
 */
CO_ErrorList CO_getSummaryList(CO_Summary arg) {
  
    return (CO_ErrorList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 14), 1);
}

/**
 * Get the ws-after-list CO_OptLayout of a CO_Summary. Note that the precondition is that this CO_Summary actually has a ws-after-list
 * \param[in] arg input CO_Summary
 * \return the ws-after-list of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSummaryWsAfterList(CO_Summary arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/**
 * Get the ws-after-] CO_OptLayout of a CO_Summary. Note that the precondition is that this CO_Summary actually has a ws-after-]
 * \param[in] arg input CO_Summary
 * \return the ws-after-] of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSummaryWsAfterBracketClose(CO_Summary arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/**
 * Set the ws-after-summary of a CO_Summary. The precondition being that this CO_Summary actually has a ws-after-summary
 * \param[in] arg input CO_Summary
 * \param[in] wsAfterSummary new CO_OptLayout to set in #arg
 * \return A new CO_Summary with wsAfterSummary at the right place, or a core dump if #arg did not have a wsAfterSummary
 */
CO_Summary CO_setSummaryWsAfterSummary(CO_Summary arg, CO_OptLayout wsAfterSummary) {
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSummary), 1), 1);
  }

  ATabort("Summary has no WsAfterSummary: %t\n", arg);
  return (CO_Summary)NULL;
}

/**
 * Set the ws-after-( of a CO_Summary. The precondition being that this CO_Summary actually has a ws-after-(
 * \param[in] arg input CO_Summary
 * \param[in] wsAfterParenOpen new CO_OptLayout to set in #arg
 * \return A new CO_Summary with wsAfterParenOpen at the right place, or a core dump if #arg did not have a wsAfterParenOpen
 */
CO_Summary CO_setSummaryWsAfterParenOpen(CO_Summary arg, CO_OptLayout wsAfterParenOpen) {
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Summary has no WsAfterParenOpen: %t\n", arg);
  return (CO_Summary)NULL;
}

/**
 * Set the producer of a CO_Summary. The precondition being that this CO_Summary actually has a producer
 * \param[in] arg input CO_Summary
 * \param[in] producer new CO_StrCon to set in #arg
 * \return A new CO_Summary with producer at the right place, or a core dump if #arg did not have a producer
 */
CO_Summary CO_setSummaryProducer(CO_Summary arg, CO_StrCon producer) {
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producer), 4), 1);
  }

  ATabort("Summary has no Producer: %t\n", arg);
  return (CO_Summary)NULL;
}

/**
 * Set the ws-after-producer of a CO_Summary. The precondition being that this CO_Summary actually has a ws-after-producer
 * \param[in] arg input CO_Summary
 * \param[in] wsAfterProducer new CO_OptLayout to set in #arg
 * \return A new CO_Summary with wsAfterProducer at the right place, or a core dump if #arg did not have a wsAfterProducer
 */
CO_Summary CO_setSummaryWsAfterProducer(CO_Summary arg, CO_OptLayout wsAfterProducer) {
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducer), 5), 1);
  }

  ATabort("Summary has no WsAfterProducer: %t\n", arg);
  return (CO_Summary)NULL;
}

/**
 * Set the ws-after-, of a CO_Summary. The precondition being that this CO_Summary actually has a ws-after-,
 * \param[in] arg input CO_Summary
 * \param[in] wsAfterComma new CO_OptLayout to set in #arg
 * \return A new CO_Summary with wsAfterComma at the right place, or a core dump if #arg did not have a wsAfterComma
 */
CO_Summary CO_setSummaryWsAfterComma(CO_Summary arg, CO_OptLayout wsAfterComma) {
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Summary has no WsAfterComma: %t\n", arg);
  return (CO_Summary)NULL;
}

/**
 * Set the id of a CO_Summary. The precondition being that this CO_Summary actually has a id
 * \param[in] arg input CO_Summary
 * \param[in] id new CO_StrCon to set in #arg
 * \return A new CO_Summary with id at the right place, or a core dump if #arg did not have a id
 */
CO_Summary CO_setSummaryId(CO_Summary arg, CO_StrCon id) {
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) id), 8), 1);
  }

  ATabort("Summary has no Id: %t\n", arg);
  return (CO_Summary)NULL;
}

/**
 * Set the ws-after-id of a CO_Summary. The precondition being that this CO_Summary actually has a ws-after-id
 * \param[in] arg input CO_Summary
 * \param[in] wsAfterId new CO_OptLayout to set in #arg
 * \return A new CO_Summary with wsAfterId at the right place, or a core dump if #arg did not have a wsAfterId
 */
CO_Summary CO_setSummaryWsAfterId(CO_Summary arg, CO_OptLayout wsAfterId) {
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterId), 9), 1);
  }

  ATabort("Summary has no WsAfterId: %t\n", arg);
  return (CO_Summary)NULL;
}

/**
 * Set the ws-after-,-1 of a CO_Summary. The precondition being that this CO_Summary actually has a ws-after-,-1
 * \param[in] arg input CO_Summary
 * \param[in] wsAfterComma1 new CO_OptLayout to set in #arg
 * \return A new CO_Summary with wsAfterComma1 at the right place, or a core dump if #arg did not have a wsAfterComma1
 */
CO_Summary CO_setSummaryWsAfterComma1(CO_Summary arg, CO_OptLayout wsAfterComma1) {
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }

  ATabort("Summary has no WsAfterComma1: %t\n", arg);
  return (CO_Summary)NULL;
}

/**
 * Set the ws-after-[ of a CO_Summary. The precondition being that this CO_Summary actually has a ws-after-[
 * \param[in] arg input CO_Summary
 * \param[in] wsAfterBracketOpen new CO_OptLayout to set in #arg
 * \return A new CO_Summary with wsAfterBracketOpen at the right place, or a core dump if #arg did not have a wsAfterBracketOpen
 */
CO_Summary CO_setSummaryWsAfterBracketOpen(CO_Summary arg, CO_OptLayout wsAfterBracketOpen) {
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 13), 1);
  }

  ATabort("Summary has no WsAfterBracketOpen: %t\n", arg);
  return (CO_Summary)NULL;
}

/**
 * Set the list of a CO_Summary. The precondition being that this CO_Summary actually has a list
 * \param[in] arg input CO_Summary
 * \param[in] list new CO_ErrorList to set in #arg
 * \return A new CO_Summary with list at the right place, or a core dump if #arg did not have a list
 */
CO_Summary CO_setSummaryList(CO_Summary arg, CO_ErrorList list) {
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 14), (ATerm)((ATerm) list), 1), 14), 1);
  }

  ATabort("Summary has no List: %t\n", arg);
  return (CO_Summary)NULL;
}

/**
 * Set the ws-after-list of a CO_Summary. The precondition being that this CO_Summary actually has a ws-after-list
 * \param[in] arg input CO_Summary
 * \param[in] wsAfterList new CO_OptLayout to set in #arg
 * \return A new CO_Summary with wsAfterList at the right place, or a core dump if #arg did not have a wsAfterList
 */
CO_Summary CO_setSummaryWsAfterList(CO_Summary arg, CO_OptLayout wsAfterList) {
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 15), 1);
  }

  ATabort("Summary has no WsAfterList: %t\n", arg);
  return (CO_Summary)NULL;
}

/**
 * Set the ws-after-] of a CO_Summary. The precondition being that this CO_Summary actually has a ws-after-]
 * \param[in] arg input CO_Summary
 * \param[in] wsAfterBracketClose new CO_OptLayout to set in #arg
 * \return A new CO_Summary with wsAfterBracketClose at the right place, or a core dump if #arg did not have a wsAfterBracketClose
 */
CO_Summary CO_setSummaryWsAfterBracketClose(CO_Summary arg, CO_OptLayout wsAfterBracketClose) {
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 17), 1);
  }

  ATabort("Summary has no WsAfterBracketClose: %t\n", arg);
  return (CO_Summary)NULL;
}

/**
 * Assert whether a CO_SubjectList is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_SubjectList
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidSubjectList(CO_SubjectList arg) {
  if (CO_isSubjectListEmpty(arg)) {
    return ATtrue;
  }
  else if (CO_isSubjectListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_SubjectList is a empty. . May not be used to assert correctness of the CO_SubjectList
 * \param[in] arg input CO_SubjectList
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool CO_isSubjectListEmpty(CO_SubjectList arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternSubjectListEmpty));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_SubjectList is a single. . May not be used to assert correctness of the CO_SubjectList
 * \param[in] arg input CO_SubjectList
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool CO_isSubjectListSingle(CO_SubjectList arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternSubjectListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_SubjectList is a many. . May not be used to assert correctness of the CO_SubjectList
 * \param[in] arg input CO_SubjectList
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool CO_isSubjectListMany(CO_SubjectList arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternSubjectListMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_SubjectList has a head. 
 * \param[in] arg input CO_SubjectList
 * \return ATtrue if the CO_SubjectList had a head, or ATfalse otherwise
 */
ATbool CO_hasSubjectListHead(CO_SubjectList arg) {
  if (CO_isSubjectListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_SubjectList has a ws-after-head. 
 * \param[in] arg input CO_SubjectList
 * \return ATtrue if the CO_SubjectList had a ws-after-head, or ATfalse otherwise
 */
ATbool CO_hasSubjectListWsAfterHead(CO_SubjectList arg) {
  if (CO_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_SubjectList has a ws-after-sep. 
 * \param[in] arg input CO_SubjectList
 * \return ATtrue if the CO_SubjectList had a ws-after-sep, or ATfalse otherwise
 */
ATbool CO_hasSubjectListWsAfterSep(CO_SubjectList arg) {
  if (CO_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_SubjectList has a tail. 
 * \param[in] arg input CO_SubjectList
 * \return ATtrue if the CO_SubjectList had a tail, or ATfalse otherwise
 */
ATbool CO_hasSubjectListTail(CO_SubjectList arg) {
  if (CO_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Returns a list of all but the first element of a CO_SubjectList. 
 * \param[in] arg input CO_SubjectList
 * \return A new CO_SubjectList, without the first element and the separator(s) just after it.)
 */
CO_SubjectList CO_getSubjectListTail(CO_SubjectList arg) {
  assert(!CO_isSubjectListEmpty(arg) && "getTail on an empty list");
  if (CO_isSubjectListSingle(arg)) {
    return (CO_SubjectList) CO_makeSubjectListEmpty();
  }
  else {
  
    return (CO_SubjectList)ATgetTail((ATermList)arg, 4);
  }
}

/**
 * Get the head CO_Subject of a CO_SubjectList. Note that the precondition is that this CO_SubjectList actually has a head
 * \param[in] arg input CO_SubjectList
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
CO_Subject CO_getSubjectListHead(CO_SubjectList arg) {
  if (CO_isSubjectListSingle(arg)) {
    return (CO_Subject)ATgetFirst((ATermList)arg);
  }
  else 
    return (CO_Subject)ATgetFirst((ATermList)arg);
}

/**
 * Get the ws-after-head CO_OptLayout of a CO_SubjectList. Note that the precondition is that this CO_SubjectList actually has a ws-after-head
 * \param[in] arg input CO_SubjectList
 * \return the ws-after-head of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSubjectListWsAfterHead(CO_SubjectList arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)arg, 1);
}

/**
 * Get the ws-after-sep CO_OptLayout of a CO_SubjectList. Note that the precondition is that this CO_SubjectList actually has a ws-after-sep
 * \param[in] arg input CO_SubjectList
 * \return the ws-after-sep of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getSubjectListWsAfterSep(CO_SubjectList arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)arg, 3);
}

/**
 * Set the head of a CO_SubjectList. The precondition being that this CO_SubjectList actually has a head
 * \param[in] arg input CO_SubjectList
 * \param[in] head new CO_Subject to set in #arg
 * \return A new CO_SubjectList with head at the right place, or a core dump if #arg did not have a head
 */
CO_SubjectList CO_setSubjectListHead(CO_SubjectList arg, CO_Subject head) {
  if (CO_isSubjectListSingle(arg)) {
    return (CO_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CO_isSubjectListMany(arg)) {
    return (CO_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("SubjectList has no Head: %t\n", arg);
  return (CO_SubjectList)NULL;
}

/**
 * Set the ws-after-head of a CO_SubjectList. The precondition being that this CO_SubjectList actually has a ws-after-head
 * \param[in] arg input CO_SubjectList
 * \param[in] wsAfterHead new CO_OptLayout to set in #arg
 * \return A new CO_SubjectList with wsAfterHead at the right place, or a core dump if #arg did not have a wsAfterHead
 */
CO_SubjectList CO_setSubjectListWsAfterHead(CO_SubjectList arg, CO_OptLayout wsAfterHead) {
  if (CO_isSubjectListMany(arg)) {
    return (CO_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("SubjectList has no WsAfterHead: %t\n", arg);
  return (CO_SubjectList)NULL;
}

/**
 * Set the ws-after-sep of a CO_SubjectList. The precondition being that this CO_SubjectList actually has a ws-after-sep
 * \param[in] arg input CO_SubjectList
 * \param[in] wsAfterSep new CO_OptLayout to set in #arg
 * \return A new CO_SubjectList with wsAfterSep at the right place, or a core dump if #arg did not have a wsAfterSep
 */
CO_SubjectList CO_setSubjectListWsAfterSep(CO_SubjectList arg, CO_OptLayout wsAfterSep) {
  if (CO_isSubjectListMany(arg)) {
    return (CO_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("SubjectList has no WsAfterSep: %t\n", arg);
  return (CO_SubjectList)NULL;
}

/**
 * Set the tail of a CO_SubjectList. The precondition being that this CO_SubjectList actually has a tail
 * \param[in] arg input CO_SubjectList
 * \param[in] tail new CO_SubjectList to set in #arg
 * \return A new CO_SubjectList with tail at the right place, or a core dump if #arg did not have a tail
 */
CO_SubjectList CO_setSubjectListTail(CO_SubjectList arg, CO_SubjectList tail) {
  if (CO_isSubjectListMany(arg)) {
    return (CO_SubjectList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("SubjectList has no Tail: %t\n", arg);
  return (CO_SubjectList)NULL;
}

/**
 * Assert whether a CO_ErrorList is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_ErrorList
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidErrorList(CO_ErrorList arg) {
  if (CO_isErrorListEmpty(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ErrorList is a empty. . May not be used to assert correctness of the CO_ErrorList
 * \param[in] arg input CO_ErrorList
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool CO_isErrorListEmpty(CO_ErrorList arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternErrorListEmpty));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_ErrorList is a single. . May not be used to assert correctness of the CO_ErrorList
 * \param[in] arg input CO_ErrorList
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool CO_isErrorListSingle(CO_ErrorList arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternErrorListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_ErrorList is a many. . May not be used to assert correctness of the CO_ErrorList
 * \param[in] arg input CO_ErrorList
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool CO_isErrorListMany(CO_ErrorList arg) {
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternErrorListMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_ErrorList has a head. 
 * \param[in] arg input CO_ErrorList
 * \return ATtrue if the CO_ErrorList had a head, or ATfalse otherwise
 */
ATbool CO_hasErrorListHead(CO_ErrorList arg) {
  if (CO_isErrorListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ErrorList has a ws-after-head. 
 * \param[in] arg input CO_ErrorList
 * \return ATtrue if the CO_ErrorList had a ws-after-head, or ATfalse otherwise
 */
ATbool CO_hasErrorListWsAfterHead(CO_ErrorList arg) {
  if (CO_isErrorListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ErrorList has a ws-after-sep. 
 * \param[in] arg input CO_ErrorList
 * \return ATtrue if the CO_ErrorList had a ws-after-sep, or ATfalse otherwise
 */
ATbool CO_hasErrorListWsAfterSep(CO_ErrorList arg) {
  if (CO_isErrorListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ErrorList has a tail. 
 * \param[in] arg input CO_ErrorList
 * \return ATtrue if the CO_ErrorList had a tail, or ATfalse otherwise
 */
ATbool CO_hasErrorListTail(CO_ErrorList arg) {
  if (CO_isErrorListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Returns a list of all but the first element of a CO_ErrorList. 
 * \param[in] arg input CO_ErrorList
 * \return A new CO_ErrorList, without the first element and the separator(s) just after it.)
 */
CO_ErrorList CO_getErrorListTail(CO_ErrorList arg) {
  assert(!CO_isErrorListEmpty(arg) && "getTail on an empty list");
  if (CO_isErrorListSingle(arg)) {
    return (CO_ErrorList) CO_makeErrorListEmpty();
  }
  else {
  
    return (CO_ErrorList)ATgetTail((ATermList)arg, 4);
  }
}

/**
 * Get the head CO_Error of a CO_ErrorList. Note that the precondition is that this CO_ErrorList actually has a head
 * \param[in] arg input CO_ErrorList
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
CO_Error CO_getErrorListHead(CO_ErrorList arg) {
  if (CO_isErrorListSingle(arg)) {
    return (CO_Error)ATgetFirst((ATermList)arg);
  }
  else 
    return (CO_Error)ATgetFirst((ATermList)arg);
}

/**
 * Get the ws-after-head CO_OptLayout of a CO_ErrorList. Note that the precondition is that this CO_ErrorList actually has a ws-after-head
 * \param[in] arg input CO_ErrorList
 * \return the ws-after-head of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getErrorListWsAfterHead(CO_ErrorList arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)arg, 1);
}

/**
 * Get the ws-after-sep CO_OptLayout of a CO_ErrorList. Note that the precondition is that this CO_ErrorList actually has a ws-after-sep
 * \param[in] arg input CO_ErrorList
 * \return the ws-after-sep of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getErrorListWsAfterSep(CO_ErrorList arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)arg, 3);
}

/**
 * Set the head of a CO_ErrorList. The precondition being that this CO_ErrorList actually has a head
 * \param[in] arg input CO_ErrorList
 * \param[in] head new CO_Error to set in #arg
 * \return A new CO_ErrorList with head at the right place, or a core dump if #arg did not have a head
 */
CO_ErrorList CO_setErrorListHead(CO_ErrorList arg, CO_Error head) {
  if (CO_isErrorListSingle(arg)) {
    return (CO_ErrorList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CO_isErrorListMany(arg)) {
    return (CO_ErrorList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ErrorList has no Head: %t\n", arg);
  return (CO_ErrorList)NULL;
}

/**
 * Set the ws-after-head of a CO_ErrorList. The precondition being that this CO_ErrorList actually has a ws-after-head
 * \param[in] arg input CO_ErrorList
 * \param[in] wsAfterHead new CO_OptLayout to set in #arg
 * \return A new CO_ErrorList with wsAfterHead at the right place, or a core dump if #arg did not have a wsAfterHead
 */
CO_ErrorList CO_setErrorListWsAfterHead(CO_ErrorList arg, CO_OptLayout wsAfterHead) {
  if (CO_isErrorListMany(arg)) {
    return (CO_ErrorList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("ErrorList has no WsAfterHead: %t\n", arg);
  return (CO_ErrorList)NULL;
}

/**
 * Set the ws-after-sep of a CO_ErrorList. The precondition being that this CO_ErrorList actually has a ws-after-sep
 * \param[in] arg input CO_ErrorList
 * \param[in] wsAfterSep new CO_OptLayout to set in #arg
 * \return A new CO_ErrorList with wsAfterSep at the right place, or a core dump if #arg did not have a wsAfterSep
 */
CO_ErrorList CO_setErrorListWsAfterSep(CO_ErrorList arg, CO_OptLayout wsAfterSep) {
  if (CO_isErrorListMany(arg)) {
    return (CO_ErrorList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("ErrorList has no WsAfterSep: %t\n", arg);
  return (CO_ErrorList)NULL;
}

/**
 * Set the tail of a CO_ErrorList. The precondition being that this CO_ErrorList actually has a tail
 * \param[in] arg input CO_ErrorList
 * \param[in] tail new CO_ErrorList to set in #arg
 * \return A new CO_ErrorList with tail at the right place, or a core dump if #arg did not have a tail
 */
CO_ErrorList CO_setErrorListTail(CO_ErrorList arg, CO_ErrorList tail) {
  if (CO_isErrorListMany(arg)) {
    return (CO_ErrorList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("ErrorList has no Tail: %t\n", arg);
  return (CO_ErrorList)NULL;
}

/**
 * Assert whether a CO_Location is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_Location
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidLocation(CO_Location arg) {
  if (CO_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Location is a file. . May not be used to assert correctness of the CO_Location
 * \param[in] arg input CO_Location
 * \return ATtrue if #arg corresponds to the signature of a file, or ATfalse otherwise
 */
inline ATbool CO_isLocationFile(CO_Location arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLocationFile, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Location is a area. . May not be used to assert correctness of the CO_Location
 * \param[in] arg input CO_Location
 * \return ATtrue if #arg corresponds to the signature of a area, or ATfalse otherwise
 */
inline ATbool CO_isLocationArea(CO_Location arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLocationArea, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Location is a area-in-file. . May not be used to assert correctness of the CO_Location
 * \param[in] arg input CO_Location
 * \return ATtrue if #arg corresponds to the signature of a area-in-file, or ATfalse otherwise
 */
inline ATbool CO_isLocationAreaInFile(CO_Location arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLocationAreaInFile, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Location has a ws-after-file. 
 * \param[in] arg input CO_Location
 * \return ATtrue if the CO_Location had a ws-after-file, or ATfalse otherwise
 */
ATbool CO_hasLocationWsAfterFile(CO_Location arg) {
  if (CO_isLocationFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Location has a ws-after-(. 
 * \param[in] arg input CO_Location
 * \return ATtrue if the CO_Location had a ws-after-(, or ATfalse otherwise
 */
ATbool CO_hasLocationWsAfterParenOpen(CO_Location arg) {
  if (CO_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Location has a filename. 
 * \param[in] arg input CO_Location
 * \return ATtrue if the CO_Location had a filename, or ATfalse otherwise
 */
ATbool CO_hasLocationFilename(CO_Location arg) {
  if (CO_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Location has a ws-after-filename. 
 * \param[in] arg input CO_Location
 * \return ATtrue if the CO_Location had a ws-after-filename, or ATfalse otherwise
 */
ATbool CO_hasLocationWsAfterFilename(CO_Location arg) {
  if (CO_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Location has a ws-after-a. 
 * \param[in] arg input CO_Location
 * \return ATtrue if the CO_Location had a ws-after-a, or ATfalse otherwise
 */
ATbool CO_hasLocationWsAfterA(CO_Location arg) {
  if (CO_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Location has a Area. 
 * \param[in] arg input CO_Location
 * \return ATtrue if the CO_Location had a Area, or ATfalse otherwise
 */
ATbool CO_hasLocationArea(CO_Location arg) {
  if (CO_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Location has a ws-after-Area. 
 * \param[in] arg input CO_Location
 * \return ATtrue if the CO_Location had a ws-after-Area, or ATfalse otherwise
 */
ATbool CO_hasLocationWsAfterArea(CO_Location arg) {
  if (CO_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Location has a ws-after-area-in-file. 
 * \param[in] arg input CO_Location
 * \return ATtrue if the CO_Location had a ws-after-area-in-file, or ATfalse otherwise
 */
ATbool CO_hasLocationWsAfterAreaInFile(CO_Location arg) {
  if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Location has a ws-after-,. 
 * \param[in] arg input CO_Location
 * \return ATtrue if the CO_Location had a ws-after-,, or ATfalse otherwise
 */
ATbool CO_hasLocationWsAfterComma(CO_Location arg) {
  if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ws-after-file CO_OptLayout of a CO_Location. Note that the precondition is that this CO_Location actually has a ws-after-file
 * \param[in] arg input CO_Location
 * \return the ws-after-file of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getLocationWsAfterFile(CO_Location arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-( CO_OptLayout of a CO_Location. Note that the precondition is that this CO_Location actually has a ws-after-(
 * \param[in] arg input CO_Location
 * \return the ws-after-( of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getLocationWsAfterParenOpen(CO_Location arg) {
  if (CO_isLocationFile(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (CO_isLocationArea(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the filename CO_StrCon of a CO_Location. Note that the precondition is that this CO_Location actually has a filename
 * \param[in] arg input CO_Location
 * \return the filename of #arg, if it exist or an undefined value if it does not
 */
CO_StrCon CO_getLocationFilename(CO_Location arg) {
  if (CO_isLocationFile(arg)) {
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/**
 * Get the ws-after-filename CO_OptLayout of a CO_Location. Note that the precondition is that this CO_Location actually has a ws-after-filename
 * \param[in] arg input CO_Location
 * \return the ws-after-filename of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getLocationWsAfterFilename(CO_Location arg) {
  if (CO_isLocationFile(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Get the ws-after-a CO_OptLayout of a CO_Location. Note that the precondition is that this CO_Location actually has a ws-after-a
 * \param[in] arg input CO_Location
 * \return the ws-after-a of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getLocationWsAfterA(CO_Location arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the Area CO_Area of a CO_Location. Note that the precondition is that this CO_Location actually has a Area
 * \param[in] arg input CO_Location
 * \return the Area of #arg, if it exist or an undefined value if it does not
 */
CO_Area CO_getLocationArea(CO_Location arg) {
  if (CO_isLocationArea(arg)) {
    return (CO_Area)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (CO_Area)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/**
 * Get the ws-after-Area CO_OptLayout of a CO_Location. Note that the precondition is that this CO_Location actually has a ws-after-Area
 * \param[in] arg input CO_Location
 * \return the ws-after-Area of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getLocationWsAfterArea(CO_Location arg) {
  if (CO_isLocationArea(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/**
 * Get the ws-after-area-in-file CO_OptLayout of a CO_Location. Note that the precondition is that this CO_Location actually has a ws-after-area-in-file
 * \param[in] arg input CO_Location
 * \return the ws-after-area-in-file of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getLocationWsAfterAreaInFile(CO_Location arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-, CO_OptLayout of a CO_Location. Note that the precondition is that this CO_Location actually has a ws-after-,
 * \param[in] arg input CO_Location
 * \return the ws-after-, of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getLocationWsAfterComma(CO_Location arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/**
 * Set the ws-after-file of a CO_Location. The precondition being that this CO_Location actually has a ws-after-file
 * \param[in] arg input CO_Location
 * \param[in] wsAfterFile new CO_OptLayout to set in #arg
 * \return A new CO_Location with wsAfterFile at the right place, or a core dump if #arg did not have a wsAfterFile
 */
CO_Location CO_setLocationWsAfterFile(CO_Location arg, CO_OptLayout wsAfterFile) {
  if (CO_isLocationFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFile), 1), 1);
  }

  ATabort("Location has no WsAfterFile: %t\n", arg);
  return (CO_Location)NULL;
}

/**
 * Set the ws-after-( of a CO_Location. The precondition being that this CO_Location actually has a ws-after-(
 * \param[in] arg input CO_Location
 * \param[in] wsAfterParenOpen new CO_OptLayout to set in #arg
 * \return A new CO_Location with wsAfterParenOpen at the right place, or a core dump if #arg did not have a wsAfterParenOpen
 */
CO_Location CO_setLocationWsAfterParenOpen(CO_Location arg, CO_OptLayout wsAfterParenOpen) {
  if (CO_isLocationFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isLocationArea(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Location has no WsAfterParenOpen: %t\n", arg);
  return (CO_Location)NULL;
}

/**
 * Set the filename of a CO_Location. The precondition being that this CO_Location actually has a filename
 * \param[in] arg input CO_Location
 * \param[in] filename new CO_StrCon to set in #arg
 * \return A new CO_Location with filename at the right place, or a core dump if #arg did not have a filename
 */
CO_Location CO_setLocationFilename(CO_Location arg, CO_StrCon filename) {
  if (CO_isLocationFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) filename), 4), 1);
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) filename), 4), 1);
  }

  ATabort("Location has no Filename: %t\n", arg);
  return (CO_Location)NULL;
}

/**
 * Set the ws-after-filename of a CO_Location. The precondition being that this CO_Location actually has a ws-after-filename
 * \param[in] arg input CO_Location
 * \param[in] wsAfterFilename new CO_OptLayout to set in #arg
 * \return A new CO_Location with wsAfterFilename at the right place, or a core dump if #arg did not have a wsAfterFilename
 */
CO_Location CO_setLocationWsAfterFilename(CO_Location arg, CO_OptLayout wsAfterFilename) {
  if (CO_isLocationFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFilename), 5), 1);
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFilename), 5), 1);
  }

  ATabort("Location has no WsAfterFilename: %t\n", arg);
  return (CO_Location)NULL;
}

/**
 * Set the ws-after-a of a CO_Location. The precondition being that this CO_Location actually has a ws-after-a
 * \param[in] arg input CO_Location
 * \param[in] wsAfterA new CO_OptLayout to set in #arg
 * \return A new CO_Location with wsAfterA at the right place, or a core dump if #arg did not have a wsAfterA
 */
CO_Location CO_setLocationWsAfterA(CO_Location arg, CO_OptLayout wsAfterA) {
  if (CO_isLocationArea(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterA), 1), 1);
  }

  ATabort("Location has no WsAfterA: %t\n", arg);
  return (CO_Location)NULL;
}

/**
 * Set the Area of a CO_Location. The precondition being that this CO_Location actually has a Area
 * \param[in] arg input CO_Location
 * \param[in] Area new CO_Area to set in #arg
 * \return A new CO_Location with Area at the right place, or a core dump if #arg did not have a Area
 */
CO_Location CO_setLocationArea(CO_Location arg, CO_Area Area) {
  if (CO_isLocationArea(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Area), 4), 1);
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Area), 8), 1);
  }

  ATabort("Location has no Area: %t\n", arg);
  return (CO_Location)NULL;
}

/**
 * Set the ws-after-Area of a CO_Location. The precondition being that this CO_Location actually has a ws-after-Area
 * \param[in] arg input CO_Location
 * \param[in] wsAfterArea new CO_OptLayout to set in #arg
 * \return A new CO_Location with wsAfterArea at the right place, or a core dump if #arg did not have a wsAfterArea
 */
CO_Location CO_setLocationWsAfterArea(CO_Location arg, CO_OptLayout wsAfterArea) {
  if (CO_isLocationArea(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 5), 1);
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 9), 1);
  }

  ATabort("Location has no WsAfterArea: %t\n", arg);
  return (CO_Location)NULL;
}

/**
 * Set the ws-after-area-in-file of a CO_Location. The precondition being that this CO_Location actually has a ws-after-area-in-file
 * \param[in] arg input CO_Location
 * \param[in] wsAfterAreaInFile new CO_OptLayout to set in #arg
 * \return A new CO_Location with wsAfterAreaInFile at the right place, or a core dump if #arg did not have a wsAfterAreaInFile
 */
CO_Location CO_setLocationWsAfterAreaInFile(CO_Location arg, CO_OptLayout wsAfterAreaInFile) {
  if (CO_isLocationAreaInFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAreaInFile), 1), 1);
  }

  ATabort("Location has no WsAfterAreaInFile: %t\n", arg);
  return (CO_Location)NULL;
}

/**
 * Set the ws-after-, of a CO_Location. The precondition being that this CO_Location actually has a ws-after-,
 * \param[in] arg input CO_Location
 * \param[in] wsAfterComma new CO_OptLayout to set in #arg
 * \return A new CO_Location with wsAfterComma at the right place, or a core dump if #arg did not have a wsAfterComma
 */
CO_Location CO_setLocationWsAfterComma(CO_Location arg, CO_OptLayout wsAfterComma) {
  if (CO_isLocationAreaInFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Location has no WsAfterComma: %t\n", arg);
  return (CO_Location)NULL;
}

/**
 * Assert whether a CO_Area is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_Area
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidArea(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area is a area. Always returns ATtrue
 * \param[in] arg input CO_Area
 * \return ATtrue if #arg corresponds to the signature of a area, or ATfalse otherwise
 */
inline ATbool CO_isAreaArea(CO_Area arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternAreaArea, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_Area has a ws-after-area. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a ws-after-area, or ATfalse otherwise
 */
ATbool CO_hasAreaWsAfterArea(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a ws-after-(. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a ws-after-(, or ATfalse otherwise
 */
ATbool CO_hasAreaWsAfterParenOpen(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a begin-line. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a begin-line, or ATfalse otherwise
 */
ATbool CO_hasAreaBeginLine(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a ws-after-begin-line. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a ws-after-begin-line, or ATfalse otherwise
 */
ATbool CO_hasAreaWsAfterBeginLine(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a ws-after-,. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a ws-after-,, or ATfalse otherwise
 */
ATbool CO_hasAreaWsAfterComma(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a begin-column. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a begin-column, or ATfalse otherwise
 */
ATbool CO_hasAreaBeginColumn(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a ws-after-begin-column. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a ws-after-begin-column, or ATfalse otherwise
 */
ATbool CO_hasAreaWsAfterBeginColumn(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a ws-after-,-1. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a ws-after-,-1, or ATfalse otherwise
 */
ATbool CO_hasAreaWsAfterComma1(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a end-line. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a end-line, or ATfalse otherwise
 */
ATbool CO_hasAreaEndLine(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a ws-after-end-line. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a ws-after-end-line, or ATfalse otherwise
 */
ATbool CO_hasAreaWsAfterEndLine(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a ws-after-,-2. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a ws-after-,-2, or ATfalse otherwise
 */
ATbool CO_hasAreaWsAfterComma2(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a end-column. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a end-column, or ATfalse otherwise
 */
ATbool CO_hasAreaEndColumn(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a ws-after-end-column. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a ws-after-end-column, or ATfalse otherwise
 */
ATbool CO_hasAreaWsAfterEndColumn(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a ws-after-,-3. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a ws-after-,-3, or ATfalse otherwise
 */
ATbool CO_hasAreaWsAfterComma3(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a offset. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a offset, or ATfalse otherwise
 */
ATbool CO_hasAreaOffset(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a ws-after-offset. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a ws-after-offset, or ATfalse otherwise
 */
ATbool CO_hasAreaWsAfterOffset(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a ws-after-,-4. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a ws-after-,-4, or ATfalse otherwise
 */
ATbool CO_hasAreaWsAfterComma4(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a length. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a length, or ATfalse otherwise
 */
ATbool CO_hasAreaLength(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Area has a ws-after-length. 
 * \param[in] arg input CO_Area
 * \return ATtrue if the CO_Area had a ws-after-length, or ATfalse otherwise
 */
ATbool CO_hasAreaWsAfterLength(CO_Area arg) {
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ws-after-area CO_OptLayout of a CO_Area. Note that the precondition is that this CO_Area actually has a ws-after-area
 * \param[in] arg input CO_Area
 * \return the ws-after-area of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getAreaWsAfterArea(CO_Area arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-( CO_OptLayout of a CO_Area. Note that the precondition is that this CO_Area actually has a ws-after-(
 * \param[in] arg input CO_Area
 * \return the ws-after-( of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getAreaWsAfterParenOpen(CO_Area arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the begin-line CO_NatCon of a CO_Area. Note that the precondition is that this CO_Area actually has a begin-line
 * \param[in] arg input CO_Area
 * \return the begin-line of #arg, if it exist or an undefined value if it does not
 */
CO_NatCon CO_getAreaBeginLine(CO_Area arg) {
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/**
 * Get the ws-after-begin-line CO_OptLayout of a CO_Area. Note that the precondition is that this CO_Area actually has a ws-after-begin-line
 * \param[in] arg input CO_Area
 * \return the ws-after-begin-line of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getAreaWsAfterBeginLine(CO_Area arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Get the ws-after-, CO_OptLayout of a CO_Area. Note that the precondition is that this CO_Area actually has a ws-after-,
 * \param[in] arg input CO_Area
 * \return the ws-after-, of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getAreaWsAfterComma(CO_Area arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/**
 * Get the begin-column CO_NatCon of a CO_Area. Note that the precondition is that this CO_Area actually has a begin-column
 * \param[in] arg input CO_Area
 * \return the begin-column of #arg, if it exist or an undefined value if it does not
 */
CO_NatCon CO_getAreaBeginColumn(CO_Area arg) {
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/**
 * Get the ws-after-begin-column CO_OptLayout of a CO_Area. Note that the precondition is that this CO_Area actually has a ws-after-begin-column
 * \param[in] arg input CO_Area
 * \return the ws-after-begin-column of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getAreaWsAfterBeginColumn(CO_Area arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/**
 * Get the ws-after-,-1 CO_OptLayout of a CO_Area. Note that the precondition is that this CO_Area actually has a ws-after-,-1
 * \param[in] arg input CO_Area
 * \return the ws-after-,-1 of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getAreaWsAfterComma1(CO_Area arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/**
 * Get the end-line CO_NatCon of a CO_Area. Note that the precondition is that this CO_Area actually has a end-line
 * \param[in] arg input CO_Area
 * \return the end-line of #arg, if it exist or an undefined value if it does not
 */
CO_NatCon CO_getAreaEndLine(CO_Area arg) {
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/**
 * Get the ws-after-end-line CO_OptLayout of a CO_Area. Note that the precondition is that this CO_Area actually has a ws-after-end-line
 * \param[in] arg input CO_Area
 * \return the ws-after-end-line of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getAreaWsAfterEndLine(CO_Area arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/**
 * Get the ws-after-,-2 CO_OptLayout of a CO_Area. Note that the precondition is that this CO_Area actually has a ws-after-,-2
 * \param[in] arg input CO_Area
 * \return the ws-after-,-2 of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getAreaWsAfterComma2(CO_Area arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/**
 * Get the end-column CO_NatCon of a CO_Area. Note that the precondition is that this CO_Area actually has a end-column
 * \param[in] arg input CO_Area
 * \return the end-column of #arg, if it exist or an undefined value if it does not
 */
CO_NatCon CO_getAreaEndColumn(CO_Area arg) {
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
}

/**
 * Get the ws-after-end-column CO_OptLayout of a CO_Area. Note that the precondition is that this CO_Area actually has a ws-after-end-column
 * \param[in] arg input CO_Area
 * \return the ws-after-end-column of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getAreaWsAfterEndColumn(CO_Area arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/**
 * Get the ws-after-,-3 CO_OptLayout of a CO_Area. Note that the precondition is that this CO_Area actually has a ws-after-,-3
 * \param[in] arg input CO_Area
 * \return the ws-after-,-3 of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getAreaWsAfterComma3(CO_Area arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 19);
}

/**
 * Get the offset CO_NatCon of a CO_Area. Note that the precondition is that this CO_Area actually has a offset
 * \param[in] arg input CO_Area
 * \return the offset of #arg, if it exist or an undefined value if it does not
 */
CO_NatCon CO_getAreaOffset(CO_Area arg) {
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 20);
}

/**
 * Get the ws-after-offset CO_OptLayout of a CO_Area. Note that the precondition is that this CO_Area actually has a ws-after-offset
 * \param[in] arg input CO_Area
 * \return the ws-after-offset of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getAreaWsAfterOffset(CO_Area arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 21);
}

/**
 * Get the ws-after-,-4 CO_OptLayout of a CO_Area. Note that the precondition is that this CO_Area actually has a ws-after-,-4
 * \param[in] arg input CO_Area
 * \return the ws-after-,-4 of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getAreaWsAfterComma4(CO_Area arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 23);
}

/**
 * Get the length CO_NatCon of a CO_Area. Note that the precondition is that this CO_Area actually has a length
 * \param[in] arg input CO_Area
 * \return the length of #arg, if it exist or an undefined value if it does not
 */
CO_NatCon CO_getAreaLength(CO_Area arg) {
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 24);
}

/**
 * Get the ws-after-length CO_OptLayout of a CO_Area. Note that the precondition is that this CO_Area actually has a ws-after-length
 * \param[in] arg input CO_Area
 * \return the ws-after-length of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getAreaWsAfterLength(CO_Area arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 25);
}

/**
 * Set the ws-after-area of a CO_Area. The precondition being that this CO_Area actually has a ws-after-area
 * \param[in] arg input CO_Area
 * \param[in] wsAfterArea new CO_OptLayout to set in #arg
 * \return A new CO_Area with wsAfterArea at the right place, or a core dump if #arg did not have a wsAfterArea
 */
CO_Area CO_setAreaWsAfterArea(CO_Area arg, CO_OptLayout wsAfterArea) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 1), 1);
  }

  ATabort("Area has no WsAfterArea: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the ws-after-( of a CO_Area. The precondition being that this CO_Area actually has a ws-after-(
 * \param[in] arg input CO_Area
 * \param[in] wsAfterParenOpen new CO_OptLayout to set in #arg
 * \return A new CO_Area with wsAfterParenOpen at the right place, or a core dump if #arg did not have a wsAfterParenOpen
 */
CO_Area CO_setAreaWsAfterParenOpen(CO_Area arg, CO_OptLayout wsAfterParenOpen) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Area has no WsAfterParenOpen: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the begin-line of a CO_Area. The precondition being that this CO_Area actually has a begin-line
 * \param[in] arg input CO_Area
 * \param[in] beginLine new CO_NatCon to set in #arg
 * \return A new CO_Area with beginLine at the right place, or a core dump if #arg did not have a beginLine
 */
CO_Area CO_setAreaBeginLine(CO_Area arg, CO_NatCon beginLine) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) beginLine), 4), 1);
  }

  ATabort("Area has no BeginLine: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the ws-after-begin-line of a CO_Area. The precondition being that this CO_Area actually has a ws-after-begin-line
 * \param[in] arg input CO_Area
 * \param[in] wsAfterBeginLine new CO_OptLayout to set in #arg
 * \return A new CO_Area with wsAfterBeginLine at the right place, or a core dump if #arg did not have a wsAfterBeginLine
 */
CO_Area CO_setAreaWsAfterBeginLine(CO_Area arg, CO_OptLayout wsAfterBeginLine) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBeginLine), 5), 1);
  }

  ATabort("Area has no WsAfterBeginLine: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the ws-after-, of a CO_Area. The precondition being that this CO_Area actually has a ws-after-,
 * \param[in] arg input CO_Area
 * \param[in] wsAfterComma new CO_OptLayout to set in #arg
 * \return A new CO_Area with wsAfterComma at the right place, or a core dump if #arg did not have a wsAfterComma
 */
CO_Area CO_setAreaWsAfterComma(CO_Area arg, CO_OptLayout wsAfterComma) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Area has no WsAfterComma: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the begin-column of a CO_Area. The precondition being that this CO_Area actually has a begin-column
 * \param[in] arg input CO_Area
 * \param[in] beginColumn new CO_NatCon to set in #arg
 * \return A new CO_Area with beginColumn at the right place, or a core dump if #arg did not have a beginColumn
 */
CO_Area CO_setAreaBeginColumn(CO_Area arg, CO_NatCon beginColumn) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) beginColumn), 8), 1);
  }

  ATabort("Area has no BeginColumn: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the ws-after-begin-column of a CO_Area. The precondition being that this CO_Area actually has a ws-after-begin-column
 * \param[in] arg input CO_Area
 * \param[in] wsAfterBeginColumn new CO_OptLayout to set in #arg
 * \return A new CO_Area with wsAfterBeginColumn at the right place, or a core dump if #arg did not have a wsAfterBeginColumn
 */
CO_Area CO_setAreaWsAfterBeginColumn(CO_Area arg, CO_OptLayout wsAfterBeginColumn) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBeginColumn), 9), 1);
  }

  ATabort("Area has no WsAfterBeginColumn: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the ws-after-,-1 of a CO_Area. The precondition being that this CO_Area actually has a ws-after-,-1
 * \param[in] arg input CO_Area
 * \param[in] wsAfterComma1 new CO_OptLayout to set in #arg
 * \return A new CO_Area with wsAfterComma1 at the right place, or a core dump if #arg did not have a wsAfterComma1
 */
CO_Area CO_setAreaWsAfterComma1(CO_Area arg, CO_OptLayout wsAfterComma1) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }

  ATabort("Area has no WsAfterComma1: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the end-line of a CO_Area. The precondition being that this CO_Area actually has a end-line
 * \param[in] arg input CO_Area
 * \param[in] endLine new CO_NatCon to set in #arg
 * \return A new CO_Area with endLine at the right place, or a core dump if #arg did not have a endLine
 */
CO_Area CO_setAreaEndLine(CO_Area arg, CO_NatCon endLine) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) endLine), 12), 1);
  }

  ATabort("Area has no EndLine: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the ws-after-end-line of a CO_Area. The precondition being that this CO_Area actually has a ws-after-end-line
 * \param[in] arg input CO_Area
 * \param[in] wsAfterEndLine new CO_OptLayout to set in #arg
 * \return A new CO_Area with wsAfterEndLine at the right place, or a core dump if #arg did not have a wsAfterEndLine
 */
CO_Area CO_setAreaWsAfterEndLine(CO_Area arg, CO_OptLayout wsAfterEndLine) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEndLine), 13), 1);
  }

  ATabort("Area has no WsAfterEndLine: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the ws-after-,-2 of a CO_Area. The precondition being that this CO_Area actually has a ws-after-,-2
 * \param[in] arg input CO_Area
 * \param[in] wsAfterComma2 new CO_OptLayout to set in #arg
 * \return A new CO_Area with wsAfterComma2 at the right place, or a core dump if #arg did not have a wsAfterComma2
 */
CO_Area CO_setAreaWsAfterComma2(CO_Area arg, CO_OptLayout wsAfterComma2) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }

  ATabort("Area has no WsAfterComma2: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the end-column of a CO_Area. The precondition being that this CO_Area actually has a end-column
 * \param[in] arg input CO_Area
 * \param[in] endColumn new CO_NatCon to set in #arg
 * \return A new CO_Area with endColumn at the right place, or a core dump if #arg did not have a endColumn
 */
CO_Area CO_setAreaEndColumn(CO_Area arg, CO_NatCon endColumn) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) endColumn), 16), 1);
  }

  ATabort("Area has no EndColumn: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the ws-after-end-column of a CO_Area. The precondition being that this CO_Area actually has a ws-after-end-column
 * \param[in] arg input CO_Area
 * \param[in] wsAfterEndColumn new CO_OptLayout to set in #arg
 * \return A new CO_Area with wsAfterEndColumn at the right place, or a core dump if #arg did not have a wsAfterEndColumn
 */
CO_Area CO_setAreaWsAfterEndColumn(CO_Area arg, CO_OptLayout wsAfterEndColumn) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEndColumn), 17), 1);
  }

  ATabort("Area has no WsAfterEndColumn: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the ws-after-,-3 of a CO_Area. The precondition being that this CO_Area actually has a ws-after-,-3
 * \param[in] arg input CO_Area
 * \param[in] wsAfterComma3 new CO_OptLayout to set in #arg
 * \return A new CO_Area with wsAfterComma3 at the right place, or a core dump if #arg did not have a wsAfterComma3
 */
CO_Area CO_setAreaWsAfterComma3(CO_Area arg, CO_OptLayout wsAfterComma3) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma3), 19), 1);
  }

  ATabort("Area has no WsAfterComma3: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the offset of a CO_Area. The precondition being that this CO_Area actually has a offset
 * \param[in] arg input CO_Area
 * \param[in] offset new CO_NatCon to set in #arg
 * \return A new CO_Area with offset at the right place, or a core dump if #arg did not have a offset
 */
CO_Area CO_setAreaOffset(CO_Area arg, CO_NatCon offset) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) offset), 20), 1);
  }

  ATabort("Area has no Offset: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the ws-after-offset of a CO_Area. The precondition being that this CO_Area actually has a ws-after-offset
 * \param[in] arg input CO_Area
 * \param[in] wsAfterOffset new CO_OptLayout to set in #arg
 * \return A new CO_Area with wsAfterOffset at the right place, or a core dump if #arg did not have a wsAfterOffset
 */
CO_Area CO_setAreaWsAfterOffset(CO_Area arg, CO_OptLayout wsAfterOffset) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterOffset), 21), 1);
  }

  ATabort("Area has no WsAfterOffset: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the ws-after-,-4 of a CO_Area. The precondition being that this CO_Area actually has a ws-after-,-4
 * \param[in] arg input CO_Area
 * \param[in] wsAfterComma4 new CO_OptLayout to set in #arg
 * \return A new CO_Area with wsAfterComma4 at the right place, or a core dump if #arg did not have a wsAfterComma4
 */
CO_Area CO_setAreaWsAfterComma4(CO_Area arg, CO_OptLayout wsAfterComma4) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma4), 23), 1);
  }

  ATabort("Area has no WsAfterComma4: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the length of a CO_Area. The precondition being that this CO_Area actually has a length
 * \param[in] arg input CO_Area
 * \param[in] length new CO_NatCon to set in #arg
 * \return A new CO_Area with length at the right place, or a core dump if #arg did not have a length
 */
CO_Area CO_setAreaLength(CO_Area arg, CO_NatCon length) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) length), 24), 1);
  }

  ATabort("Area has no Length: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Set the ws-after-length of a CO_Area. The precondition being that this CO_Area actually has a ws-after-length
 * \param[in] arg input CO_Area
 * \param[in] wsAfterLength new CO_OptLayout to set in #arg
 * \return A new CO_Area with wsAfterLength at the right place, or a core dump if #arg did not have a wsAfterLength
 */
CO_Area CO_setAreaWsAfterLength(CO_Area arg, CO_OptLayout wsAfterLength) {
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLength), 25), 1);
  }

  ATabort("Area has no WsAfterLength: %t\n", arg);
  return (CO_Area)NULL;
}

/**
 * Assert whether a CO_Read is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_Read
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidRead(CO_Read arg) {
  if (CO_isReadSuccess(arg)) {
    return ATtrue;
  }
  else if (CO_isReadFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Read is a success. . May not be used to assert correctness of the CO_Read
 * \param[in] arg input CO_Read
 * \return ATtrue if #arg corresponds to the signature of a success, or ATfalse otherwise
 */
inline ATbool CO_isReadSuccess(CO_Read arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternReadSuccess, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Read is a failure. . May not be used to assert correctness of the CO_Read
 * \param[in] arg input CO_Read
 * \return ATtrue if #arg corresponds to the signature of a failure, or ATfalse otherwise
 */
inline ATbool CO_isReadFailure(CO_Read arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternReadFailure, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Read has a ws-after-read. 
 * \param[in] arg input CO_Read
 * \return ATtrue if the CO_Read had a ws-after-read, or ATfalse otherwise
 */
ATbool CO_hasReadWsAfterRead(CO_Read arg) {
  if (CO_isReadSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Read has a ws-after-(. 
 * \param[in] arg input CO_Read
 * \return ATtrue if the CO_Read had a ws-after-(, or ATfalse otherwise
 */
ATbool CO_hasReadWsAfterParenOpen(CO_Read arg) {
  if (CO_isReadSuccess(arg)) {
    return ATtrue;
  }
  else if (CO_isReadFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Read has a value. 
 * \param[in] arg input CO_Read
 * \return ATtrue if the CO_Read had a value, or ATfalse otherwise
 */
ATbool CO_hasReadValue(CO_Read arg) {
  if (CO_isReadSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Read has a ws-after-value. 
 * \param[in] arg input CO_Read
 * \return ATtrue if the CO_Read had a ws-after-value, or ATfalse otherwise
 */
ATbool CO_hasReadWsAfterValue(CO_Read arg) {
  if (CO_isReadSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Read has a ws-after-read-error. 
 * \param[in] arg input CO_Read
 * \return ATtrue if the CO_Read had a ws-after-read-error, or ATfalse otherwise
 */
ATbool CO_hasReadWsAfterReadError(CO_Read arg) {
  if (CO_isReadFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Read has a Summary. 
 * \param[in] arg input CO_Read
 * \return ATtrue if the CO_Read had a Summary, or ATfalse otherwise
 */
ATbool CO_hasReadSummary(CO_Read arg) {
  if (CO_isReadFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Read has a ws-after-Summary. 
 * \param[in] arg input CO_Read
 * \return ATtrue if the CO_Read had a ws-after-Summary, or ATfalse otherwise
 */
ATbool CO_hasReadWsAfterSummary(CO_Read arg) {
  if (CO_isReadFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ws-after-read CO_OptLayout of a CO_Read. Note that the precondition is that this CO_Read actually has a ws-after-read
 * \param[in] arg input CO_Read
 * \return the ws-after-read of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getReadWsAfterRead(CO_Read arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-( CO_OptLayout of a CO_Read. Note that the precondition is that this CO_Read actually has a ws-after-(
 * \param[in] arg input CO_Read
 * \return the ws-after-( of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getReadWsAfterParenOpen(CO_Read arg) {
  if (CO_isReadSuccess(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the value CO_Bytes of a CO_Read. Note that the precondition is that this CO_Read actually has a value
 * \param[in] arg input CO_Read
 * \return the value of #arg, if it exist or an undefined value if it does not
 */
CO_Bytes CO_getReadValue(CO_Read arg) {
  
    return (CO_Bytes)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/**
 * Get the ws-after-value CO_OptLayout of a CO_Read. Note that the precondition is that this CO_Read actually has a ws-after-value
 * \param[in] arg input CO_Read
 * \return the ws-after-value of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getReadWsAfterValue(CO_Read arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Get the ws-after-read-error CO_OptLayout of a CO_Read. Note that the precondition is that this CO_Read actually has a ws-after-read-error
 * \param[in] arg input CO_Read
 * \return the ws-after-read-error of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getReadWsAfterReadError(CO_Read arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the Summary CO_Summary of a CO_Read. Note that the precondition is that this CO_Read actually has a Summary
 * \param[in] arg input CO_Read
 * \return the Summary of #arg, if it exist or an undefined value if it does not
 */
CO_Summary CO_getReadSummary(CO_Read arg) {
  
    return (CO_Summary)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/**
 * Get the ws-after-Summary CO_OptLayout of a CO_Read. Note that the precondition is that this CO_Read actually has a ws-after-Summary
 * \param[in] arg input CO_Read
 * \return the ws-after-Summary of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getReadWsAfterSummary(CO_Read arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Set the ws-after-read of a CO_Read. The precondition being that this CO_Read actually has a ws-after-read
 * \param[in] arg input CO_Read
 * \param[in] wsAfterRead new CO_OptLayout to set in #arg
 * \return A new CO_Read with wsAfterRead at the right place, or a core dump if #arg did not have a wsAfterRead
 */
CO_Read CO_setReadWsAfterRead(CO_Read arg, CO_OptLayout wsAfterRead) {
  if (CO_isReadSuccess(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRead), 1), 1);
  }

  ATabort("Read has no WsAfterRead: %t\n", arg);
  return (CO_Read)NULL;
}

/**
 * Set the ws-after-( of a CO_Read. The precondition being that this CO_Read actually has a ws-after-(
 * \param[in] arg input CO_Read
 * \param[in] wsAfterParenOpen new CO_OptLayout to set in #arg
 * \return A new CO_Read with wsAfterParenOpen at the right place, or a core dump if #arg did not have a wsAfterParenOpen
 */
CO_Read CO_setReadWsAfterParenOpen(CO_Read arg, CO_OptLayout wsAfterParenOpen) {
  if (CO_isReadSuccess(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isReadFailure(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Read has no WsAfterParenOpen: %t\n", arg);
  return (CO_Read)NULL;
}

/**
 * Set the value of a CO_Read. The precondition being that this CO_Read actually has a value
 * \param[in] arg input CO_Read
 * \param[in] value new CO_Bytes to set in #arg
 * \return A new CO_Read with value at the right place, or a core dump if #arg did not have a value
 */
CO_Read CO_setReadValue(CO_Read arg, CO_Bytes value) {
  if (CO_isReadSuccess(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) value), 4), 1);
  }

  ATabort("Read has no Value: %t\n", arg);
  return (CO_Read)NULL;
}

/**
 * Set the ws-after-value of a CO_Read. The precondition being that this CO_Read actually has a ws-after-value
 * \param[in] arg input CO_Read
 * \param[in] wsAfterValue new CO_OptLayout to set in #arg
 * \return A new CO_Read with wsAfterValue at the right place, or a core dump if #arg did not have a wsAfterValue
 */
CO_Read CO_setReadWsAfterValue(CO_Read arg, CO_OptLayout wsAfterValue) {
  if (CO_isReadSuccess(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterValue), 5), 1);
  }

  ATabort("Read has no WsAfterValue: %t\n", arg);
  return (CO_Read)NULL;
}

/**
 * Set the ws-after-read-error of a CO_Read. The precondition being that this CO_Read actually has a ws-after-read-error
 * \param[in] arg input CO_Read
 * \param[in] wsAfterReadError new CO_OptLayout to set in #arg
 * \return A new CO_Read with wsAfterReadError at the right place, or a core dump if #arg did not have a wsAfterReadError
 */
CO_Read CO_setReadWsAfterReadError(CO_Read arg, CO_OptLayout wsAfterReadError) {
  if (CO_isReadFailure(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterReadError), 1), 1);
  }

  ATabort("Read has no WsAfterReadError: %t\n", arg);
  return (CO_Read)NULL;
}

/**
 * Set the Summary of a CO_Read. The precondition being that this CO_Read actually has a Summary
 * \param[in] arg input CO_Read
 * \param[in] Summary new CO_Summary to set in #arg
 * \return A new CO_Read with Summary at the right place, or a core dump if #arg did not have a Summary
 */
CO_Read CO_setReadSummary(CO_Read arg, CO_Summary Summary) {
  if (CO_isReadFailure(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Summary), 4), 1);
  }

  ATabort("Read has no Summary: %t\n", arg);
  return (CO_Read)NULL;
}

/**
 * Set the ws-after-Summary of a CO_Read. The precondition being that this CO_Read actually has a ws-after-Summary
 * \param[in] arg input CO_Read
 * \param[in] wsAfterSummary new CO_OptLayout to set in #arg
 * \return A new CO_Read with wsAfterSummary at the right place, or a core dump if #arg did not have a wsAfterSummary
 */
CO_Read CO_setReadWsAfterSummary(CO_Read arg, CO_OptLayout wsAfterSummary) {
  if (CO_isReadFailure(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSummary), 5), 1);
  }

  ATabort("Read has no WsAfterSummary: %t\n", arg);
  return (CO_Read)NULL;
}

/**
 * Assert whether a CO_Write is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_Write
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidWrite(CO_Write arg) {
  if (CO_isWriteSuccess(arg)) {
    return ATtrue;
  }
  else if (CO_isWriteFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Write is a success. . May not be used to assert correctness of the CO_Write
 * \param[in] arg input CO_Write
 * \return ATtrue if #arg corresponds to the signature of a success, or ATfalse otherwise
 */
inline ATbool CO_isWriteSuccess(CO_Write arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternWriteSuccess);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Write is a failure. . May not be used to assert correctness of the CO_Write
 * \param[in] arg input CO_Write
 * \return ATtrue if #arg corresponds to the signature of a failure, or ATfalse otherwise
 */
inline ATbool CO_isWriteFailure(CO_Write arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternWriteFailure, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Write has a ws-after-write-error. 
 * \param[in] arg input CO_Write
 * \return ATtrue if the CO_Write had a ws-after-write-error, or ATfalse otherwise
 */
ATbool CO_hasWriteWsAfterWriteError(CO_Write arg) {
  if (CO_isWriteFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Write has a ws-after-(. 
 * \param[in] arg input CO_Write
 * \return ATtrue if the CO_Write had a ws-after-(, or ATfalse otherwise
 */
ATbool CO_hasWriteWsAfterParenOpen(CO_Write arg) {
  if (CO_isWriteFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Write has a Summary. 
 * \param[in] arg input CO_Write
 * \return ATtrue if the CO_Write had a Summary, or ATfalse otherwise
 */
ATbool CO_hasWriteSummary(CO_Write arg) {
  if (CO_isWriteFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Write has a ws-after-Summary. 
 * \param[in] arg input CO_Write
 * \return ATtrue if the CO_Write had a ws-after-Summary, or ATfalse otherwise
 */
ATbool CO_hasWriteWsAfterSummary(CO_Write arg) {
  if (CO_isWriteFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the ws-after-write-error CO_OptLayout of a CO_Write. Note that the precondition is that this CO_Write actually has a ws-after-write-error
 * \param[in] arg input CO_Write
 * \return the ws-after-write-error of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getWriteWsAfterWriteError(CO_Write arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-( CO_OptLayout of a CO_Write. Note that the precondition is that this CO_Write actually has a ws-after-(
 * \param[in] arg input CO_Write
 * \return the ws-after-( of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getWriteWsAfterParenOpen(CO_Write arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the Summary CO_Summary of a CO_Write. Note that the precondition is that this CO_Write actually has a Summary
 * \param[in] arg input CO_Write
 * \return the Summary of #arg, if it exist or an undefined value if it does not
 */
CO_Summary CO_getWriteSummary(CO_Write arg) {
  
    return (CO_Summary)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/**
 * Get the ws-after-Summary CO_OptLayout of a CO_Write. Note that the precondition is that this CO_Write actually has a ws-after-Summary
 * \param[in] arg input CO_Write
 * \return the ws-after-Summary of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getWriteWsAfterSummary(CO_Write arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Set the ws-after-write-error of a CO_Write. The precondition being that this CO_Write actually has a ws-after-write-error
 * \param[in] arg input CO_Write
 * \param[in] wsAfterWriteError new CO_OptLayout to set in #arg
 * \return A new CO_Write with wsAfterWriteError at the right place, or a core dump if #arg did not have a wsAfterWriteError
 */
CO_Write CO_setWriteWsAfterWriteError(CO_Write arg, CO_OptLayout wsAfterWriteError) {
  if (CO_isWriteFailure(arg)) {
    return (CO_Write)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterWriteError), 1), 1);
  }

  ATabort("Write has no WsAfterWriteError: %t\n", arg);
  return (CO_Write)NULL;
}

/**
 * Set the ws-after-( of a CO_Write. The precondition being that this CO_Write actually has a ws-after-(
 * \param[in] arg input CO_Write
 * \param[in] wsAfterParenOpen new CO_OptLayout to set in #arg
 * \return A new CO_Write with wsAfterParenOpen at the right place, or a core dump if #arg did not have a wsAfterParenOpen
 */
CO_Write CO_setWriteWsAfterParenOpen(CO_Write arg, CO_OptLayout wsAfterParenOpen) {
  if (CO_isWriteFailure(arg)) {
    return (CO_Write)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Write has no WsAfterParenOpen: %t\n", arg);
  return (CO_Write)NULL;
}

/**
 * Set the Summary of a CO_Write. The precondition being that this CO_Write actually has a Summary
 * \param[in] arg input CO_Write
 * \param[in] Summary new CO_Summary to set in #arg
 * \return A new CO_Write with Summary at the right place, or a core dump if #arg did not have a Summary
 */
CO_Write CO_setWriteSummary(CO_Write arg, CO_Summary Summary) {
  if (CO_isWriteFailure(arg)) {
    return (CO_Write)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Summary), 4), 1);
  }

  ATabort("Write has no Summary: %t\n", arg);
  return (CO_Write)NULL;
}

/**
 * Set the ws-after-Summary of a CO_Write. The precondition being that this CO_Write actually has a ws-after-Summary
 * \param[in] arg input CO_Write
 * \param[in] wsAfterSummary new CO_OptLayout to set in #arg
 * \return A new CO_Write with wsAfterSummary at the right place, or a core dump if #arg did not have a wsAfterSummary
 */
CO_Write CO_setWriteWsAfterSummary(CO_Write arg, CO_OptLayout wsAfterSummary) {
  if (CO_isWriteFailure(arg)) {
    return (CO_Write)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSummary), 5), 1);
  }

  ATabort("Write has no WsAfterSummary: %t\n", arg);
  return (CO_Write)NULL;
}

/**
 * Assert whether a CO_ParsetreeX is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidParsetreeX(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  else if (CO_isParsetreeXFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX is a success. . May not be used to assert correctness of the CO_ParsetreeX
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if #arg corresponds to the signature of a success, or ATfalse otherwise
 */
inline ATbool CO_isParsetreeXSuccess(CO_ParsetreeX arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternParsetreeXSuccess, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_ParsetreeX is a failure. . May not be used to assert correctness of the CO_ParsetreeX
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if #arg corresponds to the signature of a failure, or ATfalse otherwise
 */
inline ATbool CO_isParsetreeXFailure(CO_ParsetreeX arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternParsetreeXFailure, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_ParsetreeX has a type-of-tree. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a type-of-tree, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXTypeOfTree(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a type-of-X. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a type-of-X, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXTypeOfX(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  else if (CO_isParsetreeXFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a ws-after-parse-tree. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a ws-after-parse-tree, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXWsAfterParseTree(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a ws-after-(. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a ws-after-(, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXWsAfterParenOpen(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  else if (CO_isParsetreeXFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a left-layout. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a left-layout, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXLeftLayout(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a ws-after-left-layout. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a ws-after-left-layout, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXWsAfterLeftLayout(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a ws-after-,. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a ws-after-,, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXWsAfterComma(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a tree. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a tree, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXTree(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a ws-after-tree. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a ws-after-tree, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXWsAfterTree(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a ws-after-,-1. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a ws-after-,-1, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXWsAfterComma1(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a right-layout. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a right-layout, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXRightLayout(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a ws-after-right-layout. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a ws-after-right-layout, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXWsAfterRightLayout(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a ws-after-,-2. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a ws-after-,-2, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXWsAfterComma2(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a amb-cnt. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a amb-cnt, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXAmbCnt(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a ws-after-amb-cnt. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a ws-after-amb-cnt, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXWsAfterAmbCnt(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a ws-after-parse-error. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a ws-after-parse-error, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXWsAfterParseError(CO_ParsetreeX arg) {
  if (CO_isParsetreeXFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a Summary. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a Summary, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXSummary(CO_ParsetreeX arg) {
  if (CO_isParsetreeXFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_ParsetreeX has a ws-after-Summary. 
 * \param[in] arg input CO_ParsetreeX
 * \return ATtrue if the CO_ParsetreeX had a ws-after-Summary, or ATfalse otherwise
 */
ATbool CO_hasParsetreeXWsAfterSummary(CO_ParsetreeX arg) {
  if (CO_isParsetreeXFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the type-of-tree ATerm of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a type-of-tree
 * \param[in] arg input CO_ParsetreeX
 * \return the type-of-tree of #arg, if it exist or an undefined value if it does not
 */
ATerm CO_getParsetreeXTypeOfTree(CO_ParsetreeX arg) {
  
    return (ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 8);
}

/**
 * Get the type-of-X ATerm of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a type-of-X
 * \param[in] arg input CO_ParsetreeX
 * \return the type-of-X of #arg, if it exist or an undefined value if it does not
 */
ATerm CO_getParsetreeXTypeOfX(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 0), 1));
  }
  else 
    return (ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 0), 1));
}

/**
 * Get the ws-after-parse-tree CO_OptLayout of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a ws-after-parse-tree
 * \param[in] arg input CO_ParsetreeX
 * \return the ws-after-parse-tree of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getParsetreeXWsAfterParseTree(CO_ParsetreeX arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-( CO_OptLayout of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a ws-after-(
 * \param[in] arg input CO_ParsetreeX
 * \return the ws-after-( of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getParsetreeXWsAfterParenOpen(CO_ParsetreeX arg) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the left-layout CO_Bytes of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a left-layout
 * \param[in] arg input CO_ParsetreeX
 * \return the left-layout of #arg, if it exist or an undefined value if it does not
 */
CO_Bytes CO_getParsetreeXLeftLayout(CO_ParsetreeX arg) {
  
    return (CO_Bytes)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/**
 * Get the ws-after-left-layout CO_OptLayout of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a ws-after-left-layout
 * \param[in] arg input CO_ParsetreeX
 * \return the ws-after-left-layout of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getParsetreeXWsAfterLeftLayout(CO_ParsetreeX arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Get the ws-after-, CO_OptLayout of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a ws-after-,
 * \param[in] arg input CO_ParsetreeX
 * \return the ws-after-, of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getParsetreeXWsAfterComma(CO_ParsetreeX arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/**
 * Get the tree CO_X of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a tree
 * \param[in] arg input CO_ParsetreeX
 * \return the tree of #arg, if it exist or an undefined value if it does not
 */
CO_X CO_getParsetreeXTree(CO_ParsetreeX arg) {
  
    return (CO_X)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/**
 * Get the ws-after-tree CO_OptLayout of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a ws-after-tree
 * \param[in] arg input CO_ParsetreeX
 * \return the ws-after-tree of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getParsetreeXWsAfterTree(CO_ParsetreeX arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/**
 * Get the ws-after-,-1 CO_OptLayout of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a ws-after-,-1
 * \param[in] arg input CO_ParsetreeX
 * \return the ws-after-,-1 of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getParsetreeXWsAfterComma1(CO_ParsetreeX arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/**
 * Get the right-layout CO_Bytes of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a right-layout
 * \param[in] arg input CO_ParsetreeX
 * \return the right-layout of #arg, if it exist or an undefined value if it does not
 */
CO_Bytes CO_getParsetreeXRightLayout(CO_ParsetreeX arg) {
  
    return (CO_Bytes)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/**
 * Get the ws-after-right-layout CO_OptLayout of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a ws-after-right-layout
 * \param[in] arg input CO_ParsetreeX
 * \return the ws-after-right-layout of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getParsetreeXWsAfterRightLayout(CO_ParsetreeX arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/**
 * Get the ws-after-,-2 CO_OptLayout of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a ws-after-,-2
 * \param[in] arg input CO_ParsetreeX
 * \return the ws-after-,-2 of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getParsetreeXWsAfterComma2(CO_ParsetreeX arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/**
 * Get the amb-cnt CO_NatCon of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a amb-cnt
 * \param[in] arg input CO_ParsetreeX
 * \return the amb-cnt of #arg, if it exist or an undefined value if it does not
 */
CO_NatCon CO_getParsetreeXAmbCnt(CO_ParsetreeX arg) {
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
}

/**
 * Get the ws-after-amb-cnt CO_OptLayout of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a ws-after-amb-cnt
 * \param[in] arg input CO_ParsetreeX
 * \return the ws-after-amb-cnt of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getParsetreeXWsAfterAmbCnt(CO_ParsetreeX arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/**
 * Get the ws-after-parse-error CO_OptLayout of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a ws-after-parse-error
 * \param[in] arg input CO_ParsetreeX
 * \return the ws-after-parse-error of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getParsetreeXWsAfterParseError(CO_ParsetreeX arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the Summary CO_Summary of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a Summary
 * \param[in] arg input CO_ParsetreeX
 * \return the Summary of #arg, if it exist or an undefined value if it does not
 */
CO_Summary CO_getParsetreeXSummary(CO_ParsetreeX arg) {
  
    return (CO_Summary)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/**
 * Get the ws-after-Summary CO_OptLayout of a CO_ParsetreeX. Note that the precondition is that this CO_ParsetreeX actually has a ws-after-Summary
 * \param[in] arg input CO_ParsetreeX
 * \return the ws-after-Summary of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getParsetreeXWsAfterSummary(CO_ParsetreeX arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/**
 * Set the type-of-tree of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a type-of-tree
 * \param[in] arg input CO_ParsetreeX
 * \param[in] typeOfTree new ATerm to set in #arg
 * \return A new CO_ParsetreeX with typeOfTree at the right place, or a core dump if #arg did not have a typeOfTree
 */
CO_ParsetreeX CO_setParsetreeXTypeOfTree(CO_ParsetreeX arg, ATerm typeOfTree) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) typeOfTree), 8), 0), 0);
  }

  ATabort("ParsetreeX has no TypeOfTree: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the type-of-X of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a type-of-X
 * \param[in] arg input CO_ParsetreeX
 * \param[in] typeOfX new ATerm to set in #arg
 * \return A new CO_ParsetreeX with typeOfX at the right place, or a core dump if #arg did not have a typeOfX
 */
CO_ParsetreeX CO_setParsetreeXTypeOfX(CO_ParsetreeX arg, ATerm typeOfX) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 0), 1), (ATerm)((ATerm) typeOfX), 0), 1), 0), 1), 0);
  }
  else if (CO_isParsetreeXFailure(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 0), 1), (ATerm)((ATerm) typeOfX), 0), 1), 0), 1), 0);
  }

  ATabort("ParsetreeX has no TypeOfX: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the ws-after-parse-tree of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a ws-after-parse-tree
 * \param[in] arg input CO_ParsetreeX
 * \param[in] wsAfterParseTree new CO_OptLayout to set in #arg
 * \return A new CO_ParsetreeX with wsAfterParseTree at the right place, or a core dump if #arg did not have a wsAfterParseTree
 */
CO_ParsetreeX CO_setParsetreeXWsAfterParseTree(CO_ParsetreeX arg, CO_OptLayout wsAfterParseTree) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParseTree), 1), 1);
  }

  ATabort("ParsetreeX has no WsAfterParseTree: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the ws-after-( of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a ws-after-(
 * \param[in] arg input CO_ParsetreeX
 * \param[in] wsAfterParenOpen new CO_OptLayout to set in #arg
 * \return A new CO_ParsetreeX with wsAfterParenOpen at the right place, or a core dump if #arg did not have a wsAfterParenOpen
 */
CO_ParsetreeX CO_setParsetreeXWsAfterParenOpen(CO_ParsetreeX arg, CO_OptLayout wsAfterParenOpen) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isParsetreeXFailure(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("ParsetreeX has no WsAfterParenOpen: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the left-layout of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a left-layout
 * \param[in] arg input CO_ParsetreeX
 * \param[in] leftLayout new CO_Bytes to set in #arg
 * \return A new CO_ParsetreeX with leftLayout at the right place, or a core dump if #arg did not have a leftLayout
 */
CO_ParsetreeX CO_setParsetreeXLeftLayout(CO_ParsetreeX arg, CO_Bytes leftLayout) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) leftLayout), 4), 1);
  }

  ATabort("ParsetreeX has no LeftLayout: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the ws-after-left-layout of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a ws-after-left-layout
 * \param[in] arg input CO_ParsetreeX
 * \param[in] wsAfterLeftLayout new CO_OptLayout to set in #arg
 * \return A new CO_ParsetreeX with wsAfterLeftLayout at the right place, or a core dump if #arg did not have a wsAfterLeftLayout
 */
CO_ParsetreeX CO_setParsetreeXWsAfterLeftLayout(CO_ParsetreeX arg, CO_OptLayout wsAfterLeftLayout) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLeftLayout), 5), 1);
  }

  ATabort("ParsetreeX has no WsAfterLeftLayout: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the ws-after-, of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a ws-after-,
 * \param[in] arg input CO_ParsetreeX
 * \param[in] wsAfterComma new CO_OptLayout to set in #arg
 * \return A new CO_ParsetreeX with wsAfterComma at the right place, or a core dump if #arg did not have a wsAfterComma
 */
CO_ParsetreeX CO_setParsetreeXWsAfterComma(CO_ParsetreeX arg, CO_OptLayout wsAfterComma) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("ParsetreeX has no WsAfterComma: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the tree of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a tree
 * \param[in] arg input CO_ParsetreeX
 * \param[in] tree new CO_X to set in #arg
 * \return A new CO_ParsetreeX with tree at the right place, or a core dump if #arg did not have a tree
 */
CO_ParsetreeX CO_setParsetreeXTree(CO_ParsetreeX arg, CO_X tree) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) tree), 8), 1);
  }

  ATabort("ParsetreeX has no Tree: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the ws-after-tree of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a ws-after-tree
 * \param[in] arg input CO_ParsetreeX
 * \param[in] wsAfterTree new CO_OptLayout to set in #arg
 * \return A new CO_ParsetreeX with wsAfterTree at the right place, or a core dump if #arg did not have a wsAfterTree
 */
CO_ParsetreeX CO_setParsetreeXWsAfterTree(CO_ParsetreeX arg, CO_OptLayout wsAfterTree) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTree), 9), 1);
  }

  ATabort("ParsetreeX has no WsAfterTree: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the ws-after-,-1 of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a ws-after-,-1
 * \param[in] arg input CO_ParsetreeX
 * \param[in] wsAfterComma1 new CO_OptLayout to set in #arg
 * \return A new CO_ParsetreeX with wsAfterComma1 at the right place, or a core dump if #arg did not have a wsAfterComma1
 */
CO_ParsetreeX CO_setParsetreeXWsAfterComma1(CO_ParsetreeX arg, CO_OptLayout wsAfterComma1) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }

  ATabort("ParsetreeX has no WsAfterComma1: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the right-layout of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a right-layout
 * \param[in] arg input CO_ParsetreeX
 * \param[in] rightLayout new CO_Bytes to set in #arg
 * \return A new CO_ParsetreeX with rightLayout at the right place, or a core dump if #arg did not have a rightLayout
 */
CO_ParsetreeX CO_setParsetreeXRightLayout(CO_ParsetreeX arg, CO_Bytes rightLayout) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rightLayout), 12), 1);
  }

  ATabort("ParsetreeX has no RightLayout: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the ws-after-right-layout of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a ws-after-right-layout
 * \param[in] arg input CO_ParsetreeX
 * \param[in] wsAfterRightLayout new CO_OptLayout to set in #arg
 * \return A new CO_ParsetreeX with wsAfterRightLayout at the right place, or a core dump if #arg did not have a wsAfterRightLayout
 */
CO_ParsetreeX CO_setParsetreeXWsAfterRightLayout(CO_ParsetreeX arg, CO_OptLayout wsAfterRightLayout) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRightLayout), 13), 1);
  }

  ATabort("ParsetreeX has no WsAfterRightLayout: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the ws-after-,-2 of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a ws-after-,-2
 * \param[in] arg input CO_ParsetreeX
 * \param[in] wsAfterComma2 new CO_OptLayout to set in #arg
 * \return A new CO_ParsetreeX with wsAfterComma2 at the right place, or a core dump if #arg did not have a wsAfterComma2
 */
CO_ParsetreeX CO_setParsetreeXWsAfterComma2(CO_ParsetreeX arg, CO_OptLayout wsAfterComma2) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }

  ATabort("ParsetreeX has no WsAfterComma2: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the amb-cnt of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a amb-cnt
 * \param[in] arg input CO_ParsetreeX
 * \param[in] ambCnt new CO_NatCon to set in #arg
 * \return A new CO_ParsetreeX with ambCnt at the right place, or a core dump if #arg did not have a ambCnt
 */
CO_ParsetreeX CO_setParsetreeXAmbCnt(CO_ParsetreeX arg, CO_NatCon ambCnt) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ambCnt), 16), 1);
  }

  ATabort("ParsetreeX has no AmbCnt: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the ws-after-amb-cnt of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a ws-after-amb-cnt
 * \param[in] arg input CO_ParsetreeX
 * \param[in] wsAfterAmbCnt new CO_OptLayout to set in #arg
 * \return A new CO_ParsetreeX with wsAfterAmbCnt at the right place, or a core dump if #arg did not have a wsAfterAmbCnt
 */
CO_ParsetreeX CO_setParsetreeXWsAfterAmbCnt(CO_ParsetreeX arg, CO_OptLayout wsAfterAmbCnt) {
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAmbCnt), 17), 1);
  }

  ATabort("ParsetreeX has no WsAfterAmbCnt: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the ws-after-parse-error of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a ws-after-parse-error
 * \param[in] arg input CO_ParsetreeX
 * \param[in] wsAfterParseError new CO_OptLayout to set in #arg
 * \return A new CO_ParsetreeX with wsAfterParseError at the right place, or a core dump if #arg did not have a wsAfterParseError
 */
CO_ParsetreeX CO_setParsetreeXWsAfterParseError(CO_ParsetreeX arg, CO_OptLayout wsAfterParseError) {
  if (CO_isParsetreeXFailure(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParseError), 1), 1);
  }

  ATabort("ParsetreeX has no WsAfterParseError: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the Summary of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a Summary
 * \param[in] arg input CO_ParsetreeX
 * \param[in] Summary new CO_Summary to set in #arg
 * \return A new CO_ParsetreeX with Summary at the right place, or a core dump if #arg did not have a Summary
 */
CO_ParsetreeX CO_setParsetreeXSummary(CO_ParsetreeX arg, CO_Summary Summary) {
  if (CO_isParsetreeXFailure(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Summary), 4), 1);
  }

  ATabort("ParsetreeX has no Summary: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Set the ws-after-Summary of a CO_ParsetreeX. The precondition being that this CO_ParsetreeX actually has a ws-after-Summary
 * \param[in] arg input CO_ParsetreeX
 * \param[in] wsAfterSummary new CO_OptLayout to set in #arg
 * \return A new CO_ParsetreeX with wsAfterSummary at the right place, or a core dump if #arg did not have a wsAfterSummary
 */
CO_ParsetreeX CO_setParsetreeXWsAfterSummary(CO_ParsetreeX arg, CO_OptLayout wsAfterSummary) {
  if (CO_isParsetreeXFailure(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSummary), 5), 1);
  }

  ATabort("ParsetreeX has no WsAfterSummary: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/**
 * Assert whether a CO_X is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_X
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidX(CO_X arg) {
  if (CO_isXCast(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_X is a cast. Always returns ATtrue
 * \param[in] arg input CO_X
 * \return ATtrue if #arg corresponds to the signature of a cast, or ATfalse otherwise
 */
inline ATbool CO_isXCast(CO_X arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternXCast, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a CO_X has a X. 
 * \param[in] arg input CO_X
 * \return ATtrue if the CO_X had a X, or ATfalse otherwise
 */
ATbool CO_hasXX(CO_X arg) {
  if (CO_isXCast(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the X ATerm of a CO_X. Note that the precondition is that this CO_X actually has a X
 * \param[in] arg input CO_X
 * \return the X of #arg, if it exist or an undefined value if it does not
 */
ATerm CO_getXX(CO_X arg) {
  
    return (ATerm)arg;
}

/**
 * Set the X of a CO_X. The precondition being that this CO_X actually has a X
 * \param[in] arg input CO_X
 * \param[in] X new ATerm to set in #arg
 * \return A new CO_X with X at the right place, or a core dump if #arg did not have a X
 */
CO_X CO_setXX(CO_X arg, ATerm X) {
  if (CO_isXCast(arg)) {
    return (CO_X)((ATerm) X);
  }

  ATabort("X has no X: %t\n", arg);
  return (CO_X)NULL;
}

/**
 * Assert whether a CO_Boolean is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input CO_Boolean
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool CO_isValidBoolean(CO_Boolean arg) {
  if (CO_isBooleanConstant(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanAnd(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Boolean is a constant. . May not be used to assert correctness of the CO_Boolean
 * \param[in] arg input CO_Boolean
 * \return ATtrue if #arg corresponds to the signature of a constant, or ATfalse otherwise
 */
inline ATbool CO_isBooleanConstant(CO_Boolean arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBooleanConstant, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Boolean is a or. . May not be used to assert correctness of the CO_Boolean
 * \param[in] arg input CO_Boolean
 * \return ATtrue if #arg corresponds to the signature of a or, or ATfalse otherwise
 */
inline ATbool CO_isBooleanOr(CO_Boolean arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBooleanOr, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Boolean is a and. . May not be used to assert correctness of the CO_Boolean
 * \param[in] arg input CO_Boolean
 * \return ATtrue if #arg corresponds to the signature of a and, or ATfalse otherwise
 */
inline ATbool CO_isBooleanAnd(CO_Boolean arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBooleanAnd, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Boolean is a not. . May not be used to assert correctness of the CO_Boolean
 * \param[in] arg input CO_Boolean
 * \return ATtrue if #arg corresponds to the signature of a not, or ATfalse otherwise
 */
inline ATbool CO_isBooleanNot(CO_Boolean arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBooleanNot, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Boolean is a bracket. . May not be used to assert correctness of the CO_Boolean
 * \param[in] arg input CO_Boolean
 * \return ATtrue if #arg corresponds to the signature of a bracket, or ATfalse otherwise
 */
inline ATbool CO_isBooleanBracket(CO_Boolean arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBooleanBracket, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a CO_Boolean has a BoolCon. 
 * \param[in] arg input CO_Boolean
 * \return ATtrue if the CO_Boolean had a BoolCon, or ATfalse otherwise
 */
ATbool CO_hasBooleanBoolCon(CO_Boolean arg) {
  if (CO_isBooleanConstant(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Boolean has a lhs. 
 * \param[in] arg input CO_Boolean
 * \return ATtrue if the CO_Boolean had a lhs, or ATfalse otherwise
 */
ATbool CO_hasBooleanLhs(CO_Boolean arg) {
  if (CO_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Boolean has a ws-after-lhs. 
 * \param[in] arg input CO_Boolean
 * \return ATtrue if the CO_Boolean had a ws-after-lhs, or ATfalse otherwise
 */
ATbool CO_hasBooleanWsAfterLhs(CO_Boolean arg) {
  if (CO_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Boolean has a ws-after-|. 
 * \param[in] arg input CO_Boolean
 * \return ATtrue if the CO_Boolean had a ws-after-|, or ATfalse otherwise
 */
ATbool CO_hasBooleanWsAfterBar(CO_Boolean arg) {
  if (CO_isBooleanOr(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Boolean has a rhs. 
 * \param[in] arg input CO_Boolean
 * \return ATtrue if the CO_Boolean had a rhs, or ATfalse otherwise
 */
ATbool CO_hasBooleanRhs(CO_Boolean arg) {
  if (CO_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Boolean has a ws-after-&. 
 * \param[in] arg input CO_Boolean
 * \return ATtrue if the CO_Boolean had a ws-after-&, or ATfalse otherwise
 */
ATbool CO_hasBooleanWsAfterAmp(CO_Boolean arg) {
  if (CO_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Boolean has a ws-after-not. 
 * \param[in] arg input CO_Boolean
 * \return ATtrue if the CO_Boolean had a ws-after-not, or ATfalse otherwise
 */
ATbool CO_hasBooleanWsAfterNot(CO_Boolean arg) {
  if (CO_isBooleanNot(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Boolean has a ws-after-(. 
 * \param[in] arg input CO_Boolean
 * \return ATtrue if the CO_Boolean had a ws-after-(, or ATfalse otherwise
 */
ATbool CO_hasBooleanWsAfterParenOpen(CO_Boolean arg) {
  if (CO_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Boolean has a Boolean. 
 * \param[in] arg input CO_Boolean
 * \return ATtrue if the CO_Boolean had a Boolean, or ATfalse otherwise
 */
ATbool CO_hasBooleanBoolean(CO_Boolean arg) {
  if (CO_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a CO_Boolean has a ws-after-Boolean. 
 * \param[in] arg input CO_Boolean
 * \return ATtrue if the CO_Boolean had a ws-after-Boolean, or ATfalse otherwise
 */
ATbool CO_hasBooleanWsAfterBoolean(CO_Boolean arg) {
  if (CO_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the BoolCon CO_BoolCon of a CO_Boolean. Note that the precondition is that this CO_Boolean actually has a BoolCon
 * \param[in] arg input CO_Boolean
 * \return the BoolCon of #arg, if it exist or an undefined value if it does not
 */
CO_BoolCon CO_getBooleanBoolCon(CO_Boolean arg) {
  
    return (CO_BoolCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the lhs CO_Boolean of a CO_Boolean. Note that the precondition is that this CO_Boolean actually has a lhs
 * \param[in] arg input CO_Boolean
 * \return the lhs of #arg, if it exist or an undefined value if it does not
 */
CO_Boolean CO_getBooleanLhs(CO_Boolean arg) {
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (CO_Boolean)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the ws-after-lhs CO_OptLayout of a CO_Boolean. Note that the precondition is that this CO_Boolean actually has a ws-after-lhs
 * \param[in] arg input CO_Boolean
 * \return the ws-after-lhs of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getBooleanWsAfterLhs(CO_Boolean arg) {
  if (CO_isBooleanOr(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-| CO_OptLayout of a CO_Boolean. Note that the precondition is that this CO_Boolean actually has a ws-after-|
 * \param[in] arg input CO_Boolean
 * \return the ws-after-| of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getBooleanWsAfterBar(CO_Boolean arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the rhs CO_Boolean of a CO_Boolean. Note that the precondition is that this CO_Boolean actually has a rhs
 * \param[in] arg input CO_Boolean
 * \return the rhs of #arg, if it exist or an undefined value if it does not
 */
CO_Boolean CO_getBooleanRhs(CO_Boolean arg) {
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (CO_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/**
 * Get the ws-after-& CO_OptLayout of a CO_Boolean. Note that the precondition is that this CO_Boolean actually has a ws-after-&
 * \param[in] arg input CO_Boolean
 * \return the ws-after-& of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getBooleanWsAfterAmp(CO_Boolean arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Get the ws-after-not CO_OptLayout of a CO_Boolean. Note that the precondition is that this CO_Boolean actually has a ws-after-not
 * \param[in] arg input CO_Boolean
 * \return the ws-after-not of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getBooleanWsAfterNot(CO_Boolean arg) {
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the ws-after-( CO_OptLayout of a CO_Boolean. Note that the precondition is that this CO_Boolean actually has a ws-after-(
 * \param[in] arg input CO_Boolean
 * \return the ws-after-( of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getBooleanWsAfterParenOpen(CO_Boolean arg) {
  if (CO_isBooleanNot(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/**
 * Get the Boolean CO_Boolean of a CO_Boolean. Note that the precondition is that this CO_Boolean actually has a Boolean
 * \param[in] arg input CO_Boolean
 * \return the Boolean of #arg, if it exist or an undefined value if it does not
 */
CO_Boolean CO_getBooleanBoolean(CO_Boolean arg) {
  if (CO_isBooleanNot(arg)) {
    return (CO_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (CO_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/**
 * Get the ws-after-Boolean CO_OptLayout of a CO_Boolean. Note that the precondition is that this CO_Boolean actually has a ws-after-Boolean
 * \param[in] arg input CO_Boolean
 * \return the ws-after-Boolean of #arg, if it exist or an undefined value if it does not
 */
CO_OptLayout CO_getBooleanWsAfterBoolean(CO_Boolean arg) {
  if (CO_isBooleanNot(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/**
 * Set the BoolCon of a CO_Boolean. The precondition being that this CO_Boolean actually has a BoolCon
 * \param[in] arg input CO_Boolean
 * \param[in] BoolCon new CO_BoolCon to set in #arg
 * \return A new CO_Boolean with BoolCon at the right place, or a core dump if #arg did not have a BoolCon
 */
CO_Boolean CO_setBooleanBoolCon(CO_Boolean arg, CO_BoolCon BoolCon) {
  if (CO_isBooleanConstant(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) BoolCon), 0), 1);
  }

  ATabort("Boolean has no BoolCon: %t\n", arg);
  return (CO_Boolean)NULL;
}

/**
 * Set the lhs of a CO_Boolean. The precondition being that this CO_Boolean actually has a lhs
 * \param[in] arg input CO_Boolean
 * \param[in] lhs new CO_Boolean to set in #arg
 * \return A new CO_Boolean with lhs at the right place, or a core dump if #arg did not have a lhs
 */
CO_Boolean CO_setBooleanLhs(CO_Boolean arg, CO_Boolean lhs) {
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }
  else if (CO_isBooleanAnd(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }

  ATabort("Boolean has no Lhs: %t\n", arg);
  return (CO_Boolean)NULL;
}

/**
 * Set the ws-after-lhs of a CO_Boolean. The precondition being that this CO_Boolean actually has a ws-after-lhs
 * \param[in] arg input CO_Boolean
 * \param[in] wsAfterLhs new CO_OptLayout to set in #arg
 * \return A new CO_Boolean with wsAfterLhs at the right place, or a core dump if #arg did not have a wsAfterLhs
 */
CO_Boolean CO_setBooleanWsAfterLhs(CO_Boolean arg, CO_OptLayout wsAfterLhs) {
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }
  else if (CO_isBooleanAnd(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }

  ATabort("Boolean has no WsAfterLhs: %t\n", arg);
  return (CO_Boolean)NULL;
}

/**
 * Set the ws-after-| of a CO_Boolean. The precondition being that this CO_Boolean actually has a ws-after-|
 * \param[in] arg input CO_Boolean
 * \param[in] wsAfterBar new CO_OptLayout to set in #arg
 * \return A new CO_Boolean with wsAfterBar at the right place, or a core dump if #arg did not have a wsAfterBar
 */
CO_Boolean CO_setBooleanWsAfterBar(CO_Boolean arg, CO_OptLayout wsAfterBar) {
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBar), 3), 1);
  }

  ATabort("Boolean has no WsAfterBar: %t\n", arg);
  return (CO_Boolean)NULL;
}

/**
 * Set the rhs of a CO_Boolean. The precondition being that this CO_Boolean actually has a rhs
 * \param[in] arg input CO_Boolean
 * \param[in] rhs new CO_Boolean to set in #arg
 * \return A new CO_Boolean with rhs at the right place, or a core dump if #arg did not have a rhs
 */
CO_Boolean CO_setBooleanRhs(CO_Boolean arg, CO_Boolean rhs) {
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }
  else if (CO_isBooleanAnd(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }

  ATabort("Boolean has no Rhs: %t\n", arg);
  return (CO_Boolean)NULL;
}

/**
 * Set the ws-after-& of a CO_Boolean. The precondition being that this CO_Boolean actually has a ws-after-&
 * \param[in] arg input CO_Boolean
 * \param[in] wsAfterAmp new CO_OptLayout to set in #arg
 * \return A new CO_Boolean with wsAfterAmp at the right place, or a core dump if #arg did not have a wsAfterAmp
 */
CO_Boolean CO_setBooleanWsAfterAmp(CO_Boolean arg, CO_OptLayout wsAfterAmp) {
  if (CO_isBooleanAnd(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAmp), 3), 1);
  }

  ATabort("Boolean has no WsAfterAmp: %t\n", arg);
  return (CO_Boolean)NULL;
}

/**
 * Set the ws-after-not of a CO_Boolean. The precondition being that this CO_Boolean actually has a ws-after-not
 * \param[in] arg input CO_Boolean
 * \param[in] wsAfterNot new CO_OptLayout to set in #arg
 * \return A new CO_Boolean with wsAfterNot at the right place, or a core dump if #arg did not have a wsAfterNot
 */
CO_Boolean CO_setBooleanWsAfterNot(CO_Boolean arg, CO_OptLayout wsAfterNot) {
  if (CO_isBooleanNot(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterNot), 1), 1);
  }

  ATabort("Boolean has no WsAfterNot: %t\n", arg);
  return (CO_Boolean)NULL;
}

/**
 * Set the ws-after-( of a CO_Boolean. The precondition being that this CO_Boolean actually has a ws-after-(
 * \param[in] arg input CO_Boolean
 * \param[in] wsAfterParenOpen new CO_OptLayout to set in #arg
 * \return A new CO_Boolean with wsAfterParenOpen at the right place, or a core dump if #arg did not have a wsAfterParenOpen
 */
CO_Boolean CO_setBooleanWsAfterParenOpen(CO_Boolean arg, CO_OptLayout wsAfterParenOpen) {
  if (CO_isBooleanNot(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isBooleanBracket(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 1), 1);
  }

  ATabort("Boolean has no WsAfterParenOpen: %t\n", arg);
  return (CO_Boolean)NULL;
}

/**
 * Set the Boolean of a CO_Boolean. The precondition being that this CO_Boolean actually has a Boolean
 * \param[in] arg input CO_Boolean
 * \param[in] Boolean new CO_Boolean to set in #arg
 * \return A new CO_Boolean with Boolean at the right place, or a core dump if #arg did not have a Boolean
 */
CO_Boolean CO_setBooleanBoolean(CO_Boolean arg, CO_Boolean Boolean) {
  if (CO_isBooleanNot(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Boolean), 4), 1);
  }
  else if (CO_isBooleanBracket(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Boolean), 2), 1);
  }

  ATabort("Boolean has no Boolean: %t\n", arg);
  return (CO_Boolean)NULL;
}

/**
 * Set the ws-after-Boolean of a CO_Boolean. The precondition being that this CO_Boolean actually has a ws-after-Boolean
 * \param[in] arg input CO_Boolean
 * \param[in] wsAfterBoolean new CO_OptLayout to set in #arg
 * \return A new CO_Boolean with wsAfterBoolean at the right place, or a core dump if #arg did not have a wsAfterBoolean
 */
CO_Boolean CO_setBooleanWsAfterBoolean(CO_Boolean arg, CO_OptLayout wsAfterBoolean) {
  if (CO_isBooleanNot(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBoolean), 5), 1);
  }
  else if (CO_isBooleanBracket(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBoolean), 3), 1);
  }

  ATabort("Boolean has no WsAfterBoolean: %t\n", arg);
  return (CO_Boolean)NULL;
}

/**
 * Apply functions to the children of a CO_OptLayout. 
 * \return A new CO_OptLayout with new children where the argument functions might have applied
 */
CO_OptLayout CO_visitOptLayout(CO_OptLayout arg, CO_Layout (*acceptLayout)(CO_Layout)) {
  if (CO_isOptLayoutAbsent(arg)) {
    return CO_makeOptLayoutAbsent();
  }
  if (CO_isOptLayoutPresent(arg)) {
    return CO_makeOptLayoutPresent(
        acceptLayout ? acceptLayout(CO_getOptLayoutLayout(arg)) : CO_getOptLayoutLayout(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (CO_OptLayout)NULL;
}
/**
 * Apply functions to the children of a CO_Layout. 
 * \return A new CO_Layout with new children where the argument functions might have applied
 */
CO_Layout CO_visitLayout(CO_Layout arg, CO_LexLayoutList (*acceptList)(CO_LexLayoutList)) {
  if (CO_isLayoutLexToCf(arg)) {
    return CO_makeLayoutLexToCf(
        acceptList ? acceptList(CO_getLayoutList(arg)) : CO_getLayoutList(arg));
  }
  ATabort("not a Layout: %t\n", arg);
  return (CO_Layout)NULL;
}
/**
 * Apply functions to the children of a CO_LexLayoutList. 
 * \return A new CO_LexLayoutList with new children where the argument functions might have applied
 */
CO_LexLayoutList CO_visitLexLayoutList(CO_LexLayoutList arg, CO_LexLayout (*acceptHead)(CO_LexLayout)) {
  if (CO_isLexLayoutListEmpty(arg)) {
    return CO_makeLexLayoutListEmpty();
  }
  if (CO_isLexLayoutListSingle(arg)) {
    return CO_makeLexLayoutListSingle(
        acceptHead ? acceptHead(CO_getLexLayoutListHead(arg)) : CO_getLexLayoutListHead(arg));
  }
  if (CO_isLexLayoutListMany(arg)) {
    return CO_makeLexLayoutListMany(
        acceptHead ? acceptHead(CO_getLexLayoutListHead(arg)) : CO_getLexLayoutListHead(arg),
        CO_visitLexLayoutList(CO_getLexLayoutListTail(arg), acceptHead));
  }
  ATabort("not a LexLayoutList: %t\n", arg);
  return (CO_LexLayoutList)NULL;
}
/**
 * Apply functions to the children of a CO_LexLayout. 
 * \return A new CO_LexLayout with new children where the argument functions might have applied
 */
CO_LexLayout CO_visitLexLayout(CO_LexLayout arg, char (*acceptCh)(char)) {
  if (CO_isLexLayoutWhitespace(arg)) {
    return CO_makeLexLayoutWhitespace(
        acceptCh ? acceptCh(CO_getLexLayoutCh(arg)) : CO_getLexLayoutCh(arg));
  }
  ATabort("not a LexLayout: %t\n", arg);
  return (CO_LexLayout)NULL;
}
/**
 * Apply functions to the children of a CO_Start. 
 * \return A new CO_Start with new children where the argument functions might have applied
 */
CO_Start CO_visitStart(CO_Start arg, CO_OptLayout (*acceptWsBefore)(CO_OptLayout), CO_StrCon (*acceptTopStrCon)(CO_StrCon), CO_OptLayout (*acceptWsAfter)(CO_OptLayout), int (*acceptAmbCnt)(int), CO_BoolCon (*acceptTopBoolCon)(CO_BoolCon), CO_Summary (*acceptTopSummary)(CO_Summary), CO_Error (*acceptTopError)(CO_Error), CO_Boolean (*acceptTopBoolean)(CO_Boolean)) {
  if (CO_isStartStrCon(arg)) {
    return CO_makeStartStrCon(
        acceptWsBefore ? acceptWsBefore(CO_getStartWsBefore(arg)) : CO_getStartWsBefore(arg),
        acceptTopStrCon ? acceptTopStrCon(CO_getStartTopStrCon(arg)) : CO_getStartTopStrCon(arg),
        acceptWsAfter ? acceptWsAfter(CO_getStartWsAfter(arg)) : CO_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getStartAmbCnt(arg)) : CO_getStartAmbCnt(arg));
  }
  if (CO_isStartBoolCon(arg)) {
    return CO_makeStartBoolCon(
        acceptWsBefore ? acceptWsBefore(CO_getStartWsBefore(arg)) : CO_getStartWsBefore(arg),
        acceptTopBoolCon ? acceptTopBoolCon(CO_getStartTopBoolCon(arg)) : CO_getStartTopBoolCon(arg),
        acceptWsAfter ? acceptWsAfter(CO_getStartWsAfter(arg)) : CO_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getStartAmbCnt(arg)) : CO_getStartAmbCnt(arg));
  }
  if (CO_isStartSummary(arg)) {
    return CO_makeStartSummary(
        acceptWsBefore ? acceptWsBefore(CO_getStartWsBefore(arg)) : CO_getStartWsBefore(arg),
        acceptTopSummary ? acceptTopSummary(CO_getStartTopSummary(arg)) : CO_getStartTopSummary(arg),
        acceptWsAfter ? acceptWsAfter(CO_getStartWsAfter(arg)) : CO_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getStartAmbCnt(arg)) : CO_getStartAmbCnt(arg));
  }
  if (CO_isStartError(arg)) {
    return CO_makeStartError(
        acceptWsBefore ? acceptWsBefore(CO_getStartWsBefore(arg)) : CO_getStartWsBefore(arg),
        acceptTopError ? acceptTopError(CO_getStartTopError(arg)) : CO_getStartTopError(arg),
        acceptWsAfter ? acceptWsAfter(CO_getStartWsAfter(arg)) : CO_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getStartAmbCnt(arg)) : CO_getStartAmbCnt(arg));
  }
  if (CO_isStartBoolean(arg)) {
    return CO_makeStartBoolean(
        acceptWsBefore ? acceptWsBefore(CO_getStartWsBefore(arg)) : CO_getStartWsBefore(arg),
        acceptTopBoolean ? acceptTopBoolean(CO_getStartTopBoolean(arg)) : CO_getStartTopBoolean(arg),
        acceptWsAfter ? acceptWsAfter(CO_getStartWsAfter(arg)) : CO_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getStartAmbCnt(arg)) : CO_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (CO_Start)NULL;
}
/**
 * Apply functions to the children of a CO_LexStrChar. 
 * \return A new CO_LexStrChar with new children where the argument functions might have applied
 */
CO_LexStrChar CO_visitLexStrChar(CO_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char)) {
  if (CO_isLexStrCharNewline(arg)) {
    return CO_makeLexStrCharNewline();
  }
  if (CO_isLexStrCharTab(arg)) {
    return CO_makeLexStrCharTab();
  }
  if (CO_isLexStrCharQuote(arg)) {
    return CO_makeLexStrCharQuote();
  }
  if (CO_isLexStrCharBackslash(arg)) {
    return CO_makeLexStrCharBackslash();
  }
  if (CO_isLexStrCharDecimal(arg)) {
    return CO_makeLexStrCharDecimal(
        acceptA ? acceptA(CO_getLexStrCharA(arg)) : CO_getLexStrCharA(arg),
        acceptB ? acceptB(CO_getLexStrCharB(arg)) : CO_getLexStrCharB(arg),
        acceptC ? acceptC(CO_getLexStrCharC(arg)) : CO_getLexStrCharC(arg));
  }
  if (CO_isLexStrCharNormal(arg)) {
    return CO_makeLexStrCharNormal(
        acceptCh ? acceptCh(CO_getLexStrCharCh(arg)) : CO_getLexStrCharCh(arg));
  }
  ATabort("not a LexStrChar: %t\n", arg);
  return (CO_LexStrChar)NULL;
}
/**
 * Apply functions to the children of a CO_StrChar. 
 * \return A new CO_StrChar with new children where the argument functions might have applied
 */
CO_StrChar CO_visitStrChar(CO_StrChar arg, CO_LexStrChar (*acceptStrChar)(CO_LexStrChar)) {
  if (CO_isStrCharLexToCf(arg)) {
    return CO_makeStrCharLexToCf(
        acceptStrChar ? acceptStrChar(CO_getStrCharStrChar(arg)) : CO_getStrCharStrChar(arg));
  }
  ATabort("not a StrChar: %t\n", arg);
  return (CO_StrChar)NULL;
}
/**
 * Apply functions to the children of a CO_LexStrCon. 
 * \return A new CO_LexStrCon with new children where the argument functions might have applied
 */
CO_LexStrCon CO_visitLexStrCon(CO_LexStrCon arg, CO_LexStrCharChars (*acceptChars)(CO_LexStrCharChars)) {
  if (CO_isLexStrConDefault(arg)) {
    return CO_makeLexStrConDefault(
        acceptChars ? acceptChars(CO_getLexStrConChars(arg)) : CO_getLexStrConChars(arg));
  }
  ATabort("not a LexStrCon: %t\n", arg);
  return (CO_LexStrCon)NULL;
}
/**
 * Apply functions to the children of a CO_StrCon. 
 * \return A new CO_StrCon with new children where the argument functions might have applied
 */
CO_StrCon CO_visitStrCon(CO_StrCon arg, CO_LexStrCon (*acceptStrCon)(CO_LexStrCon)) {
  if (CO_isStrConLexToCf(arg)) {
    return CO_makeStrConLexToCf(
        acceptStrCon ? acceptStrCon(CO_getStrConStrCon(arg)) : CO_getStrConStrCon(arg));
  }
  ATabort("not a StrCon: %t\n", arg);
  return (CO_StrCon)NULL;
}
/**
 * Apply functions to the children of a CO_LexStrCharChars. 
 * \return A new CO_LexStrCharChars with new children where the argument functions might have applied
 */
CO_LexStrCharChars CO_visitLexStrCharChars(CO_LexStrCharChars arg, CO_LexStrChar (*acceptHead)(CO_LexStrChar)) {
  if (CO_isLexStrCharCharsEmpty(arg)) {
    return CO_makeLexStrCharCharsEmpty();
  }
  if (CO_isLexStrCharCharsSingle(arg)) {
    return CO_makeLexStrCharCharsSingle(
        acceptHead ? acceptHead(CO_getLexStrCharCharsHead(arg)) : CO_getLexStrCharCharsHead(arg));
  }
  if (CO_isLexStrCharCharsMany(arg)) {
    return CO_makeLexStrCharCharsMany(
        acceptHead ? acceptHead(CO_getLexStrCharCharsHead(arg)) : CO_getLexStrCharCharsHead(arg),
        CO_visitLexStrCharChars(CO_getLexStrCharCharsTail(arg), acceptHead));
  }
  ATabort("not a LexStrCharChars: %t\n", arg);
  return (CO_LexStrCharChars)NULL;
}
/**
 * Apply functions to the children of a CO_BoolCon. 
 * \return A new CO_BoolCon with new children where the argument functions might have applied
 */
CO_BoolCon CO_visitBoolCon(CO_BoolCon arg) {
  if (CO_isBoolConTrue(arg)) {
    return CO_makeBoolConTrue();
  }
  if (CO_isBoolConFalse(arg)) {
    return CO_makeBoolConFalse();
  }
  ATabort("not a BoolCon: %t\n", arg);
  return (CO_BoolCon)NULL;
}
/**
 * Apply functions to the children of a CO_LexNatCon. 
 * \return A new CO_LexNatCon with new children where the argument functions might have applied
 */
CO_LexNatCon CO_visitLexNatCon(CO_LexNatCon arg, char* (*acceptList)(char*)) {
  if (CO_isLexNatConDigits(arg)) {
    return CO_makeLexNatConDigits(
        acceptList ? acceptList(CO_getLexNatConList(arg)) : CO_getLexNatConList(arg));
  }
  ATabort("not a LexNatCon: %t\n", arg);
  return (CO_LexNatCon)NULL;
}
/**
 * Apply functions to the children of a CO_NatCon. 
 * \return A new CO_NatCon with new children where the argument functions might have applied
 */
CO_NatCon CO_visitNatCon(CO_NatCon arg, CO_LexNatCon (*acceptNatCon)(CO_LexNatCon)) {
  if (CO_isNatConLexToCf(arg)) {
    return CO_makeNatConLexToCf(
        acceptNatCon ? acceptNatCon(CO_getNatConNatCon(arg)) : CO_getNatConNatCon(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (CO_NatCon)NULL;
}
/**
 * Apply functions to the children of a CO_LexByte. 
 * \return A new CO_LexByte with new children where the argument functions might have applied
 */
CO_LexByte CO_visitLexByte(CO_LexByte arg, char (*acceptCh)(char)) {
  if (CO_isLexByteByte(arg)) {
    return CO_makeLexByteByte(
        acceptCh ? acceptCh(CO_getLexByteCh(arg)) : CO_getLexByteCh(arg));
  }
  ATabort("not a LexByte: %t\n", arg);
  return (CO_LexByte)NULL;
}
/**
 * Apply functions to the children of a CO_Byte. 
 * \return A new CO_Byte with new children where the argument functions might have applied
 */
CO_Byte CO_visitByte(CO_Byte arg, CO_LexByte (*acceptByte)(CO_LexByte)) {
  if (CO_isByteLexToCf(arg)) {
    return CO_makeByteLexToCf(
        acceptByte ? acceptByte(CO_getByteByte(arg)) : CO_getByteByte(arg));
  }
  ATabort("not a Byte: %t\n", arg);
  return (CO_Byte)NULL;
}
/**
 * Apply functions to the children of a CO_LexBytes. 
 * \return A new CO_LexBytes with new children where the argument functions might have applied
 */
CO_LexBytes CO_visitLexBytes(CO_LexBytes arg, CO_LexByteList (*acceptList)(CO_LexByteList)) {
  if (CO_isLexBytesBytes(arg)) {
    return CO_makeLexBytesBytes(
        acceptList ? acceptList(CO_getLexBytesList(arg)) : CO_getLexBytesList(arg));
  }
  ATabort("not a LexBytes: %t\n", arg);
  return (CO_LexBytes)NULL;
}
/**
 * Apply functions to the children of a CO_Bytes. 
 * \return A new CO_Bytes with new children where the argument functions might have applied
 */
CO_Bytes CO_visitBytes(CO_Bytes arg, CO_LexBytes (*acceptBytes)(CO_LexBytes)) {
  if (CO_isBytesLexToCf(arg)) {
    return CO_makeBytesLexToCf(
        acceptBytes ? acceptBytes(CO_getBytesBytes(arg)) : CO_getBytesBytes(arg));
  }
  ATabort("not a Bytes: %t\n", arg);
  return (CO_Bytes)NULL;
}
/**
 * Apply functions to the children of a CO_LexByteList. 
 * \return A new CO_LexByteList with new children where the argument functions might have applied
 */
CO_LexByteList CO_visitLexByteList(CO_LexByteList arg, CO_LexByte (*acceptHead)(CO_LexByte)) {
  if (CO_isLexByteListEmpty(arg)) {
    return CO_makeLexByteListEmpty();
  }
  if (CO_isLexByteListSingle(arg)) {
    return CO_makeLexByteListSingle(
        acceptHead ? acceptHead(CO_getLexByteListHead(arg)) : CO_getLexByteListHead(arg));
  }
  if (CO_isLexByteListMany(arg)) {
    return CO_makeLexByteListMany(
        acceptHead ? acceptHead(CO_getLexByteListHead(arg)) : CO_getLexByteListHead(arg),
        CO_visitLexByteList(CO_getLexByteListTail(arg), acceptHead));
  }
  ATabort("not a LexByteList: %t\n", arg);
  return (CO_LexByteList)NULL;
}
/**
 * Apply functions to the children of a CO_Subject. 
 * \return A new CO_Subject with new children where the argument functions might have applied
 */
CO_Subject CO_visitSubject(CO_Subject arg, CO_OptLayout (*acceptWsAfterSubject)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptDescription)(CO_StrCon), CO_OptLayout (*acceptWsAfterDescription)(CO_OptLayout), CO_OptLayout (*acceptWsAfterLocalized)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_Location (*acceptLocation)(CO_Location), CO_OptLayout (*acceptWsAfterLocation)(CO_OptLayout)) {
  if (CO_isSubjectSubject(arg)) {
    return CO_makeSubjectSubject(
        acceptWsAfterSubject ? acceptWsAfterSubject(CO_getSubjectWsAfterSubject(arg)) : CO_getSubjectWsAfterSubject(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getSubjectWsAfterParenOpen(arg)) : CO_getSubjectWsAfterParenOpen(arg),
        acceptDescription ? acceptDescription(CO_getSubjectDescription(arg)) : CO_getSubjectDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(CO_getSubjectWsAfterDescription(arg)) : CO_getSubjectWsAfterDescription(arg));
  }
  if (CO_isSubjectLocalized(arg)) {
    return CO_makeSubjectLocalized(
        acceptWsAfterLocalized ? acceptWsAfterLocalized(CO_getSubjectWsAfterLocalized(arg)) : CO_getSubjectWsAfterLocalized(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getSubjectWsAfterParenOpen(arg)) : CO_getSubjectWsAfterParenOpen(arg),
        acceptDescription ? acceptDescription(CO_getSubjectDescription(arg)) : CO_getSubjectDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(CO_getSubjectWsAfterDescription(arg)) : CO_getSubjectWsAfterDescription(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getSubjectWsAfterComma(arg)) : CO_getSubjectWsAfterComma(arg),
        acceptLocation ? acceptLocation(CO_getSubjectLocation(arg)) : CO_getSubjectLocation(arg),
        acceptWsAfterLocation ? acceptWsAfterLocation(CO_getSubjectWsAfterLocation(arg)) : CO_getSubjectWsAfterLocation(arg));
  }
  ATabort("not a Subject: %t\n", arg);
  return (CO_Subject)NULL;
}
/**
 * Apply functions to the children of a CO_Error. 
 * \return A new CO_Error with new children where the argument functions might have applied
 */
CO_Error CO_visitError(CO_Error arg, CO_OptLayout (*acceptWsAfterInfo)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptDescription)(CO_StrCon), CO_OptLayout (*acceptWsAfterDescription)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketOpen)(CO_OptLayout), CO_SubjectList (*acceptList)(CO_SubjectList), CO_OptLayout (*acceptWsAfterList)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketClose)(CO_OptLayout), CO_OptLayout (*acceptWsAfterWarning)(CO_OptLayout), CO_OptLayout (*acceptWsAfterError)(CO_OptLayout), CO_OptLayout (*acceptWsAfterFatal)(CO_OptLayout)) {
  if (CO_isErrorInfo(arg)) {
    return CO_makeErrorInfo(
        acceptWsAfterInfo ? acceptWsAfterInfo(CO_getErrorWsAfterInfo(arg)) : CO_getErrorWsAfterInfo(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getErrorWsAfterParenOpen(arg)) : CO_getErrorWsAfterParenOpen(arg),
        acceptDescription ? acceptDescription(CO_getErrorDescription(arg)) : CO_getErrorDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(CO_getErrorWsAfterDescription(arg)) : CO_getErrorWsAfterDescription(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getErrorWsAfterComma(arg)) : CO_getErrorWsAfterComma(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(CO_getErrorWsAfterBracketOpen(arg)) : CO_getErrorWsAfterBracketOpen(arg),
        acceptList ? acceptList(CO_getErrorList(arg)) : CO_getErrorList(arg),
        acceptWsAfterList ? acceptWsAfterList(CO_getErrorWsAfterList(arg)) : CO_getErrorWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(CO_getErrorWsAfterBracketClose(arg)) : CO_getErrorWsAfterBracketClose(arg));
  }
  if (CO_isErrorWarning(arg)) {
    return CO_makeErrorWarning(
        acceptWsAfterWarning ? acceptWsAfterWarning(CO_getErrorWsAfterWarning(arg)) : CO_getErrorWsAfterWarning(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getErrorWsAfterParenOpen(arg)) : CO_getErrorWsAfterParenOpen(arg),
        acceptDescription ? acceptDescription(CO_getErrorDescription(arg)) : CO_getErrorDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(CO_getErrorWsAfterDescription(arg)) : CO_getErrorWsAfterDescription(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getErrorWsAfterComma(arg)) : CO_getErrorWsAfterComma(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(CO_getErrorWsAfterBracketOpen(arg)) : CO_getErrorWsAfterBracketOpen(arg),
        acceptList ? acceptList(CO_getErrorList(arg)) : CO_getErrorList(arg),
        acceptWsAfterList ? acceptWsAfterList(CO_getErrorWsAfterList(arg)) : CO_getErrorWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(CO_getErrorWsAfterBracketClose(arg)) : CO_getErrorWsAfterBracketClose(arg));
  }
  if (CO_isErrorError(arg)) {
    return CO_makeErrorError(
        acceptWsAfterError ? acceptWsAfterError(CO_getErrorWsAfterError(arg)) : CO_getErrorWsAfterError(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getErrorWsAfterParenOpen(arg)) : CO_getErrorWsAfterParenOpen(arg),
        acceptDescription ? acceptDescription(CO_getErrorDescription(arg)) : CO_getErrorDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(CO_getErrorWsAfterDescription(arg)) : CO_getErrorWsAfterDescription(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getErrorWsAfterComma(arg)) : CO_getErrorWsAfterComma(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(CO_getErrorWsAfterBracketOpen(arg)) : CO_getErrorWsAfterBracketOpen(arg),
        acceptList ? acceptList(CO_getErrorList(arg)) : CO_getErrorList(arg),
        acceptWsAfterList ? acceptWsAfterList(CO_getErrorWsAfterList(arg)) : CO_getErrorWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(CO_getErrorWsAfterBracketClose(arg)) : CO_getErrorWsAfterBracketClose(arg));
  }
  if (CO_isErrorFatal(arg)) {
    return CO_makeErrorFatal(
        acceptWsAfterFatal ? acceptWsAfterFatal(CO_getErrorWsAfterFatal(arg)) : CO_getErrorWsAfterFatal(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getErrorWsAfterParenOpen(arg)) : CO_getErrorWsAfterParenOpen(arg),
        acceptDescription ? acceptDescription(CO_getErrorDescription(arg)) : CO_getErrorDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(CO_getErrorWsAfterDescription(arg)) : CO_getErrorWsAfterDescription(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getErrorWsAfterComma(arg)) : CO_getErrorWsAfterComma(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(CO_getErrorWsAfterBracketOpen(arg)) : CO_getErrorWsAfterBracketOpen(arg),
        acceptList ? acceptList(CO_getErrorList(arg)) : CO_getErrorList(arg),
        acceptWsAfterList ? acceptWsAfterList(CO_getErrorWsAfterList(arg)) : CO_getErrorWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(CO_getErrorWsAfterBracketClose(arg)) : CO_getErrorWsAfterBracketClose(arg));
  }
  ATabort("not a Error: %t\n", arg);
  return (CO_Error)NULL;
}
/**
 * Apply functions to the children of a CO_Summary. 
 * \return A new CO_Summary with new children where the argument functions might have applied
 */
CO_Summary CO_visitSummary(CO_Summary arg, CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptProducer)(CO_StrCon), CO_OptLayout (*acceptWsAfterProducer)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_StrCon (*acceptId)(CO_StrCon), CO_OptLayout (*acceptWsAfterId)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketOpen)(CO_OptLayout), CO_ErrorList (*acceptList)(CO_ErrorList), CO_OptLayout (*acceptWsAfterList)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketClose)(CO_OptLayout)) {
  if (CO_isSummarySummary(arg)) {
    return CO_makeSummarySummary(
        acceptWsAfterSummary ? acceptWsAfterSummary(CO_getSummaryWsAfterSummary(arg)) : CO_getSummaryWsAfterSummary(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getSummaryWsAfterParenOpen(arg)) : CO_getSummaryWsAfterParenOpen(arg),
        acceptProducer ? acceptProducer(CO_getSummaryProducer(arg)) : CO_getSummaryProducer(arg),
        acceptWsAfterProducer ? acceptWsAfterProducer(CO_getSummaryWsAfterProducer(arg)) : CO_getSummaryWsAfterProducer(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getSummaryWsAfterComma(arg)) : CO_getSummaryWsAfterComma(arg),
        acceptId ? acceptId(CO_getSummaryId(arg)) : CO_getSummaryId(arg),
        acceptWsAfterId ? acceptWsAfterId(CO_getSummaryWsAfterId(arg)) : CO_getSummaryWsAfterId(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(CO_getSummaryWsAfterComma1(arg)) : CO_getSummaryWsAfterComma1(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(CO_getSummaryWsAfterBracketOpen(arg)) : CO_getSummaryWsAfterBracketOpen(arg),
        acceptList ? acceptList(CO_getSummaryList(arg)) : CO_getSummaryList(arg),
        acceptWsAfterList ? acceptWsAfterList(CO_getSummaryWsAfterList(arg)) : CO_getSummaryWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(CO_getSummaryWsAfterBracketClose(arg)) : CO_getSummaryWsAfterBracketClose(arg));
  }
  ATabort("not a Summary: %t\n", arg);
  return (CO_Summary)NULL;
}
/**
 * Apply functions to the children of a CO_SubjectList. 
 * \return A new CO_SubjectList with new children where the argument functions might have applied
 */
CO_SubjectList CO_visitSubjectList(CO_SubjectList arg, CO_Subject (*acceptHead)(CO_Subject), CO_OptLayout (*acceptWsAfterHead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterSep)(CO_OptLayout)) {
  if (CO_isSubjectListEmpty(arg)) {
    return CO_makeSubjectListEmpty();
  }
  if (CO_isSubjectListSingle(arg)) {
    return CO_makeSubjectListSingle(
        acceptHead ? acceptHead(CO_getSubjectListHead(arg)) : CO_getSubjectListHead(arg));
  }
  if (CO_isSubjectListMany(arg)) {
    return CO_makeSubjectListMany(
        acceptHead ? acceptHead(CO_getSubjectListHead(arg)) : CO_getSubjectListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(CO_getSubjectListWsAfterHead(arg)) : CO_getSubjectListWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(CO_getSubjectListWsAfterSep(arg)) : CO_getSubjectListWsAfterSep(arg),
        CO_visitSubjectList(CO_getSubjectListTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a SubjectList: %t\n", arg);
  return (CO_SubjectList)NULL;
}
/**
 * Apply functions to the children of a CO_ErrorList. 
 * \return A new CO_ErrorList with new children where the argument functions might have applied
 */
CO_ErrorList CO_visitErrorList(CO_ErrorList arg, CO_Error (*acceptHead)(CO_Error), CO_OptLayout (*acceptWsAfterHead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterSep)(CO_OptLayout)) {
  if (CO_isErrorListEmpty(arg)) {
    return CO_makeErrorListEmpty();
  }
  if (CO_isErrorListSingle(arg)) {
    return CO_makeErrorListSingle(
        acceptHead ? acceptHead(CO_getErrorListHead(arg)) : CO_getErrorListHead(arg));
  }
  if (CO_isErrorListMany(arg)) {
    return CO_makeErrorListMany(
        acceptHead ? acceptHead(CO_getErrorListHead(arg)) : CO_getErrorListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(CO_getErrorListWsAfterHead(arg)) : CO_getErrorListWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(CO_getErrorListWsAfterSep(arg)) : CO_getErrorListWsAfterSep(arg),
        CO_visitErrorList(CO_getErrorListTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a ErrorList: %t\n", arg);
  return (CO_ErrorList)NULL;
}
/**
 * Apply functions to the children of a CO_Location. 
 * \return A new CO_Location with new children where the argument functions might have applied
 */
CO_Location CO_visitLocation(CO_Location arg, CO_OptLayout (*acceptWsAfterFile)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptFilename)(CO_StrCon), CO_OptLayout (*acceptWsAfterFilename)(CO_OptLayout), CO_OptLayout (*acceptWsAfterA)(CO_OptLayout), CO_Area (*acceptArea)(CO_Area), CO_OptLayout (*acceptWsAfterArea)(CO_OptLayout), CO_OptLayout (*acceptWsAfterAreaInFile)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout)) {
  if (CO_isLocationFile(arg)) {
    return CO_makeLocationFile(
        acceptWsAfterFile ? acceptWsAfterFile(CO_getLocationWsAfterFile(arg)) : CO_getLocationWsAfterFile(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getLocationWsAfterParenOpen(arg)) : CO_getLocationWsAfterParenOpen(arg),
        acceptFilename ? acceptFilename(CO_getLocationFilename(arg)) : CO_getLocationFilename(arg),
        acceptWsAfterFilename ? acceptWsAfterFilename(CO_getLocationWsAfterFilename(arg)) : CO_getLocationWsAfterFilename(arg));
  }
  if (CO_isLocationArea(arg)) {
    return CO_makeLocationArea(
        acceptWsAfterA ? acceptWsAfterA(CO_getLocationWsAfterA(arg)) : CO_getLocationWsAfterA(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getLocationWsAfterParenOpen(arg)) : CO_getLocationWsAfterParenOpen(arg),
        acceptArea ? acceptArea(CO_getLocationArea(arg)) : CO_getLocationArea(arg),
        acceptWsAfterArea ? acceptWsAfterArea(CO_getLocationWsAfterArea(arg)) : CO_getLocationWsAfterArea(arg));
  }
  if (CO_isLocationAreaInFile(arg)) {
    return CO_makeLocationAreaInFile(
        acceptWsAfterAreaInFile ? acceptWsAfterAreaInFile(CO_getLocationWsAfterAreaInFile(arg)) : CO_getLocationWsAfterAreaInFile(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getLocationWsAfterParenOpen(arg)) : CO_getLocationWsAfterParenOpen(arg),
        acceptFilename ? acceptFilename(CO_getLocationFilename(arg)) : CO_getLocationFilename(arg),
        acceptWsAfterFilename ? acceptWsAfterFilename(CO_getLocationWsAfterFilename(arg)) : CO_getLocationWsAfterFilename(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getLocationWsAfterComma(arg)) : CO_getLocationWsAfterComma(arg),
        acceptArea ? acceptArea(CO_getLocationArea(arg)) : CO_getLocationArea(arg),
        acceptWsAfterArea ? acceptWsAfterArea(CO_getLocationWsAfterArea(arg)) : CO_getLocationWsAfterArea(arg));
  }
  ATabort("not a Location: %t\n", arg);
  return (CO_Location)NULL;
}
/**
 * Apply functions to the children of a CO_Area. 
 * \return A new CO_Area with new children where the argument functions might have applied
 */
CO_Area CO_visitArea(CO_Area arg, CO_OptLayout (*acceptWsAfterArea)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_NatCon (*acceptBeginLine)(CO_NatCon), CO_OptLayout (*acceptWsAfterBeginLine)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_NatCon (*acceptBeginColumn)(CO_NatCon), CO_OptLayout (*acceptWsAfterBeginColumn)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_NatCon (*acceptEndLine)(CO_NatCon), CO_OptLayout (*acceptWsAfterEndLine)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma2)(CO_OptLayout), CO_NatCon (*acceptEndColumn)(CO_NatCon), CO_OptLayout (*acceptWsAfterEndColumn)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma3)(CO_OptLayout), CO_NatCon (*acceptOffset)(CO_NatCon), CO_OptLayout (*acceptWsAfterOffset)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma4)(CO_OptLayout), CO_NatCon (*acceptLength)(CO_NatCon), CO_OptLayout (*acceptWsAfterLength)(CO_OptLayout)) {
  if (CO_isAreaArea(arg)) {
    return CO_makeAreaArea(
        acceptWsAfterArea ? acceptWsAfterArea(CO_getAreaWsAfterArea(arg)) : CO_getAreaWsAfterArea(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getAreaWsAfterParenOpen(arg)) : CO_getAreaWsAfterParenOpen(arg),
        acceptBeginLine ? acceptBeginLine(CO_getAreaBeginLine(arg)) : CO_getAreaBeginLine(arg),
        acceptWsAfterBeginLine ? acceptWsAfterBeginLine(CO_getAreaWsAfterBeginLine(arg)) : CO_getAreaWsAfterBeginLine(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getAreaWsAfterComma(arg)) : CO_getAreaWsAfterComma(arg),
        acceptBeginColumn ? acceptBeginColumn(CO_getAreaBeginColumn(arg)) : CO_getAreaBeginColumn(arg),
        acceptWsAfterBeginColumn ? acceptWsAfterBeginColumn(CO_getAreaWsAfterBeginColumn(arg)) : CO_getAreaWsAfterBeginColumn(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(CO_getAreaWsAfterComma1(arg)) : CO_getAreaWsAfterComma1(arg),
        acceptEndLine ? acceptEndLine(CO_getAreaEndLine(arg)) : CO_getAreaEndLine(arg),
        acceptWsAfterEndLine ? acceptWsAfterEndLine(CO_getAreaWsAfterEndLine(arg)) : CO_getAreaWsAfterEndLine(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(CO_getAreaWsAfterComma2(arg)) : CO_getAreaWsAfterComma2(arg),
        acceptEndColumn ? acceptEndColumn(CO_getAreaEndColumn(arg)) : CO_getAreaEndColumn(arg),
        acceptWsAfterEndColumn ? acceptWsAfterEndColumn(CO_getAreaWsAfterEndColumn(arg)) : CO_getAreaWsAfterEndColumn(arg),
        acceptWsAfterComma3 ? acceptWsAfterComma3(CO_getAreaWsAfterComma3(arg)) : CO_getAreaWsAfterComma3(arg),
        acceptOffset ? acceptOffset(CO_getAreaOffset(arg)) : CO_getAreaOffset(arg),
        acceptWsAfterOffset ? acceptWsAfterOffset(CO_getAreaWsAfterOffset(arg)) : CO_getAreaWsAfterOffset(arg),
        acceptWsAfterComma4 ? acceptWsAfterComma4(CO_getAreaWsAfterComma4(arg)) : CO_getAreaWsAfterComma4(arg),
        acceptLength ? acceptLength(CO_getAreaLength(arg)) : CO_getAreaLength(arg),
        acceptWsAfterLength ? acceptWsAfterLength(CO_getAreaWsAfterLength(arg)) : CO_getAreaWsAfterLength(arg));
  }
  ATabort("not a Area: %t\n", arg);
  return (CO_Area)NULL;
}
/**
 * Apply functions to the children of a CO_Read. 
 * \return A new CO_Read with new children where the argument functions might have applied
 */
CO_Read CO_visitRead(CO_Read arg, CO_OptLayout (*acceptWsAfterRead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Bytes (*acceptValue)(CO_Bytes), CO_OptLayout (*acceptWsAfterValue)(CO_OptLayout), CO_OptLayout (*acceptWsAfterReadError)(CO_OptLayout), CO_Summary (*acceptSummary)(CO_Summary), CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout)) {
  if (CO_isReadSuccess(arg)) {
    return CO_makeReadSuccess(
        acceptWsAfterRead ? acceptWsAfterRead(CO_getReadWsAfterRead(arg)) : CO_getReadWsAfterRead(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getReadWsAfterParenOpen(arg)) : CO_getReadWsAfterParenOpen(arg),
        acceptValue ? acceptValue(CO_getReadValue(arg)) : CO_getReadValue(arg),
        acceptWsAfterValue ? acceptWsAfterValue(CO_getReadWsAfterValue(arg)) : CO_getReadWsAfterValue(arg));
  }
  if (CO_isReadFailure(arg)) {
    return CO_makeReadFailure(
        acceptWsAfterReadError ? acceptWsAfterReadError(CO_getReadWsAfterReadError(arg)) : CO_getReadWsAfterReadError(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getReadWsAfterParenOpen(arg)) : CO_getReadWsAfterParenOpen(arg),
        acceptSummary ? acceptSummary(CO_getReadSummary(arg)) : CO_getReadSummary(arg),
        acceptWsAfterSummary ? acceptWsAfterSummary(CO_getReadWsAfterSummary(arg)) : CO_getReadWsAfterSummary(arg));
  }
  ATabort("not a Read: %t\n", arg);
  return (CO_Read)NULL;
}
/**
 * Apply functions to the children of a CO_Write. 
 * \return A new CO_Write with new children where the argument functions might have applied
 */
CO_Write CO_visitWrite(CO_Write arg, CO_OptLayout (*acceptWsAfterWriteError)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Summary (*acceptSummary)(CO_Summary), CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout)) {
  if (CO_isWriteSuccess(arg)) {
    return CO_makeWriteSuccess();
  }
  if (CO_isWriteFailure(arg)) {
    return CO_makeWriteFailure(
        acceptWsAfterWriteError ? acceptWsAfterWriteError(CO_getWriteWsAfterWriteError(arg)) : CO_getWriteWsAfterWriteError(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getWriteWsAfterParenOpen(arg)) : CO_getWriteWsAfterParenOpen(arg),
        acceptSummary ? acceptSummary(CO_getWriteSummary(arg)) : CO_getWriteSummary(arg),
        acceptWsAfterSummary ? acceptWsAfterSummary(CO_getWriteWsAfterSummary(arg)) : CO_getWriteWsAfterSummary(arg));
  }
  ATabort("not a Write: %t\n", arg);
  return (CO_Write)NULL;
}
/**
 * Apply functions to the children of a CO_ParsetreeX. 
 * \return A new CO_ParsetreeX with new children where the argument functions might have applied
 */
CO_ParsetreeX CO_visitParsetreeX(CO_ParsetreeX arg, ATerm (*acceptTypeOfTree)(ATerm), ATerm (*acceptTypeOfX)(ATerm), CO_OptLayout (*acceptWsAfterParseTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Bytes (*acceptLeftLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterLeftLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_X (*acceptTree)(CO_X), CO_OptLayout (*acceptWsAfterTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_Bytes (*acceptRightLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterRightLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma2)(CO_OptLayout), CO_NatCon (*acceptAmbCnt)(CO_NatCon), CO_OptLayout (*acceptWsAfterAmbCnt)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParseError)(CO_OptLayout), CO_Summary (*acceptSummary)(CO_Summary), CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout)) {
  if (CO_isParsetreeXSuccess(arg)) {
    return CO_makeParsetreeXSuccess(
        acceptTypeOfTree ? acceptTypeOfTree(CO_getParsetreeXTypeOfTree(arg)) : CO_getParsetreeXTypeOfTree(arg),
        acceptTypeOfX ? acceptTypeOfX(CO_getParsetreeXTypeOfX(arg)) : CO_getParsetreeXTypeOfX(arg),
        acceptWsAfterParseTree ? acceptWsAfterParseTree(CO_getParsetreeXWsAfterParseTree(arg)) : CO_getParsetreeXWsAfterParseTree(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getParsetreeXWsAfterParenOpen(arg)) : CO_getParsetreeXWsAfterParenOpen(arg),
        acceptLeftLayout ? acceptLeftLayout(CO_getParsetreeXLeftLayout(arg)) : CO_getParsetreeXLeftLayout(arg),
        acceptWsAfterLeftLayout ? acceptWsAfterLeftLayout(CO_getParsetreeXWsAfterLeftLayout(arg)) : CO_getParsetreeXWsAfterLeftLayout(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getParsetreeXWsAfterComma(arg)) : CO_getParsetreeXWsAfterComma(arg),
        acceptTree ? acceptTree(CO_getParsetreeXTree(arg)) : CO_getParsetreeXTree(arg),
        acceptWsAfterTree ? acceptWsAfterTree(CO_getParsetreeXWsAfterTree(arg)) : CO_getParsetreeXWsAfterTree(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(CO_getParsetreeXWsAfterComma1(arg)) : CO_getParsetreeXWsAfterComma1(arg),
        acceptRightLayout ? acceptRightLayout(CO_getParsetreeXRightLayout(arg)) : CO_getParsetreeXRightLayout(arg),
        acceptWsAfterRightLayout ? acceptWsAfterRightLayout(CO_getParsetreeXWsAfterRightLayout(arg)) : CO_getParsetreeXWsAfterRightLayout(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(CO_getParsetreeXWsAfterComma2(arg)) : CO_getParsetreeXWsAfterComma2(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getParsetreeXAmbCnt(arg)) : CO_getParsetreeXAmbCnt(arg),
        acceptWsAfterAmbCnt ? acceptWsAfterAmbCnt(CO_getParsetreeXWsAfterAmbCnt(arg)) : CO_getParsetreeXWsAfterAmbCnt(arg));
  }
  if (CO_isParsetreeXFailure(arg)) {
    return CO_makeParsetreeXFailure(
        acceptTypeOfX ? acceptTypeOfX(CO_getParsetreeXTypeOfX(arg)) : CO_getParsetreeXTypeOfX(arg),
        acceptWsAfterParseError ? acceptWsAfterParseError(CO_getParsetreeXWsAfterParseError(arg)) : CO_getParsetreeXWsAfterParseError(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getParsetreeXWsAfterParenOpen(arg)) : CO_getParsetreeXWsAfterParenOpen(arg),
        acceptSummary ? acceptSummary(CO_getParsetreeXSummary(arg)) : CO_getParsetreeXSummary(arg),
        acceptWsAfterSummary ? acceptWsAfterSummary(CO_getParsetreeXWsAfterSummary(arg)) : CO_getParsetreeXWsAfterSummary(arg));
  }
  ATabort("not a ParsetreeX: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}
/**
 * Apply functions to the children of a CO_X. 
 * \return A new CO_X with new children where the argument functions might have applied
 */
CO_X CO_visitX(CO_X arg, ATerm (*acceptX)(ATerm)) {
  if (CO_isXCast(arg)) {
    return CO_makeXCast(
        acceptX ? acceptX(CO_getXX(arg)) : CO_getXX(arg));
  }
  ATabort("not a X: %t\n", arg);
  return (CO_X)NULL;
}
/**
 * Apply functions to the children of a CO_Boolean. 
 * \return A new CO_Boolean with new children where the argument functions might have applied
 */
CO_Boolean CO_visitBoolean(CO_Boolean arg, CO_BoolCon (*acceptBoolCon)(CO_BoolCon), CO_OptLayout (*acceptWsAfterLhs)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBar)(CO_OptLayout), CO_OptLayout (*acceptWsAfterAmp)(CO_OptLayout), CO_OptLayout (*acceptWsAfterNot)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBoolean)(CO_OptLayout)) {
  if (CO_isBooleanConstant(arg)) {
    return CO_makeBooleanConstant(
        acceptBoolCon ? acceptBoolCon(CO_getBooleanBoolCon(arg)) : CO_getBooleanBoolCon(arg));
  }
  if (CO_isBooleanOr(arg)) {
    return CO_makeBooleanOr(
        CO_visitBoolean(CO_getBooleanLhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterLhs ? acceptWsAfterLhs(CO_getBooleanWsAfterLhs(arg)) : CO_getBooleanWsAfterLhs(arg),
        acceptWsAfterBar ? acceptWsAfterBar(CO_getBooleanWsAfterBar(arg)) : CO_getBooleanWsAfterBar(arg),
        CO_visitBoolean(CO_getBooleanRhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean));
  }
  if (CO_isBooleanAnd(arg)) {
    return CO_makeBooleanAnd(
        CO_visitBoolean(CO_getBooleanLhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterLhs ? acceptWsAfterLhs(CO_getBooleanWsAfterLhs(arg)) : CO_getBooleanWsAfterLhs(arg),
        acceptWsAfterAmp ? acceptWsAfterAmp(CO_getBooleanWsAfterAmp(arg)) : CO_getBooleanWsAfterAmp(arg),
        CO_visitBoolean(CO_getBooleanRhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean));
  }
  if (CO_isBooleanNot(arg)) {
    return CO_makeBooleanNot(
        acceptWsAfterNot ? acceptWsAfterNot(CO_getBooleanWsAfterNot(arg)) : CO_getBooleanWsAfterNot(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getBooleanWsAfterParenOpen(arg)) : CO_getBooleanWsAfterParenOpen(arg),
        CO_visitBoolean(CO_getBooleanBoolean(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterBoolean ? acceptWsAfterBoolean(CO_getBooleanWsAfterBoolean(arg)) : CO_getBooleanWsAfterBoolean(arg));
  }
  if (CO_isBooleanBracket(arg)) {
    return CO_makeBooleanBracket(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getBooleanWsAfterParenOpen(arg)) : CO_getBooleanWsAfterParenOpen(arg),
        CO_visitBoolean(CO_getBooleanBoolean(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterBoolean ? acceptWsAfterBoolean(CO_getBooleanWsAfterBoolean(arg)) : CO_getBooleanWsAfterBoolean(arg));
  }
  ATabort("not a Boolean: %t\n", arg);
  return (CO_Boolean)NULL;
}

