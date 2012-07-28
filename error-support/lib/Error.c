#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Error.h"

/**
 * Converts a string to an ATermList of integers (ASCII values). 
 * \param[in] str An ASCII string
 * \return An ATermList containing the ASCII values of #arg as ATermInts
 */
ATerm ERR_stringToChars(const char *str) {
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
ATerm ERR_byteToChar(char ch) {
    return (ATerm) ATmakeInt(ch);
}

/**
 * Converts a list of integers (ASCII values) to a C string. 
 * \param[in] arg An ATermList with ATermInts, such as [32,32,10]
 * \return String containing the characters from #arg as characters
 */
char *ERR_charsToString(ATerm arg) {
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

char ERR_charToByte(ATerm arg) {
    return (char) ATgetInt((ATermInt) arg);
}


typedef struct ATerm _ERR_StrChar;
typedef struct ATerm _ERR_StrCon;
typedef struct ATerm _ERR_NatCon;
typedef struct ATerm _ERR_Subject;
typedef struct ATerm _ERR_Error;
typedef struct ATerm _ERR_Summary;
typedef struct ATerm _ERR_SubjectList;
typedef struct ATerm _ERR_ErrorList;
typedef struct ATerm _ERR_Location;
typedef struct ATerm _ERR_Area;
typedef struct ATerm _ERR_Slice;
typedef struct ATerm _ERR_AreaAreas;


/**
 * Initializes the full API. Forgetting to call this function before using the API will lead to strange behaviour. ATinit() needs to be called before this function.
 */
void _ERR_initErrorApi(void) {
  init_Error_dict();

}

/**
 * Protect a ERR_StrChar from the ATerm garbage collector. Every ERR_StrChar that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a ERR_StrChar
 */
void _ERR_protectStrChar(ERR_StrChar *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a ERR_StrChar from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a ERR_StrChar
 */
void _ERR_unprotectStrChar(ERR_StrChar *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a ERR_StrCon from the ATerm garbage collector. Every ERR_StrCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a ERR_StrCon
 */
void _ERR_protectStrCon(ERR_StrCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a ERR_StrCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a ERR_StrCon
 */
void _ERR_unprotectStrCon(ERR_StrCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a ERR_NatCon from the ATerm garbage collector. Every ERR_NatCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a ERR_NatCon
 */
void _ERR_protectNatCon(ERR_NatCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a ERR_NatCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a ERR_NatCon
 */
void _ERR_unprotectNatCon(ERR_NatCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a ERR_Subject from the ATerm garbage collector. Every ERR_Subject that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a ERR_Subject
 */
void _ERR_protectSubject(ERR_Subject *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a ERR_Subject from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a ERR_Subject
 */
void _ERR_unprotectSubject(ERR_Subject *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a ERR_Error from the ATerm garbage collector. Every ERR_Error that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a ERR_Error
 */
void _ERR_protectError(ERR_Error *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a ERR_Error from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a ERR_Error
 */
void _ERR_unprotectError(ERR_Error *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a ERR_Summary from the ATerm garbage collector. Every ERR_Summary that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a ERR_Summary
 */
void _ERR_protectSummary(ERR_Summary *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a ERR_Summary from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a ERR_Summary
 */
void _ERR_unprotectSummary(ERR_Summary *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a ERR_SubjectList from the ATerm garbage collector. Every ERR_SubjectList that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a ERR_SubjectList
 */
void _ERR_protectSubjectList(ERR_SubjectList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a ERR_SubjectList from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a ERR_SubjectList
 */
void _ERR_unprotectSubjectList(ERR_SubjectList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a ERR_ErrorList from the ATerm garbage collector. Every ERR_ErrorList that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a ERR_ErrorList
 */
void _ERR_protectErrorList(ERR_ErrorList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a ERR_ErrorList from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a ERR_ErrorList
 */
void _ERR_unprotectErrorList(ERR_ErrorList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a ERR_Location from the ATerm garbage collector. Every ERR_Location that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a ERR_Location
 */
void _ERR_protectLocation(ERR_Location *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a ERR_Location from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a ERR_Location
 */
void _ERR_unprotectLocation(ERR_Location *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a ERR_Area from the ATerm garbage collector. Every ERR_Area that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a ERR_Area
 */
void _ERR_protectArea(ERR_Area *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a ERR_Area from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a ERR_Area
 */
void _ERR_unprotectArea(ERR_Area *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a ERR_Slice from the ATerm garbage collector. Every ERR_Slice that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a ERR_Slice
 */
void _ERR_protectSlice(ERR_Slice *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a ERR_Slice from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a ERR_Slice
 */
void _ERR_unprotectSlice(ERR_Slice *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a ERR_AreaAreas from the ATerm garbage collector. Every ERR_AreaAreas that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a ERR_AreaAreas
 */
void _ERR_protectAreaAreas(ERR_AreaAreas *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a ERR_AreaAreas from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a ERR_AreaAreas
 */
void _ERR_unprotectAreaAreas(ERR_AreaAreas *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Transforms an ATerm to a ERR_StrChar. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return ERR_StrChar that was encoded by \arg
 */
ERR_StrChar _ERR_StrCharFromTerm(ATerm t) {
  return (((union {ERR_StrChar target; ATerm source; })(t)).target);
}

/**
 * Transforms a ERR_StrCharto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg ERR_StrChar to be converted
 * \return ATerm that represents the ERR_StrChar
 */
ATerm _ERR_StrCharToTerm(ERR_StrChar arg) {
  return (((union {ERR_StrChar source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a ERR_StrCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return ERR_StrCon that was encoded by \arg
 */
ERR_StrCon _ERR_StrConFromTerm(ATerm t) {
  return (((union {ERR_StrCon target; ATerm source; })(t)).target);
}

/**
 * Transforms a ERR_StrConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg ERR_StrCon to be converted
 * \return ATerm that represents the ERR_StrCon
 */
ATerm _ERR_StrConToTerm(ERR_StrCon arg) {
  return (((union {ERR_StrCon source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a ERR_NatCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return ERR_NatCon that was encoded by \arg
 */
ERR_NatCon _ERR_NatConFromTerm(ATerm t) {
  return (((union {ERR_NatCon target; ATerm source; })(t)).target);
}

/**
 * Transforms a ERR_NatConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg ERR_NatCon to be converted
 * \return ATerm that represents the ERR_NatCon
 */
ATerm _ERR_NatConToTerm(ERR_NatCon arg) {
  return (((union {ERR_NatCon source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a ERR_Subject. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return ERR_Subject that was encoded by \arg
 */
ERR_Subject _ERR_SubjectFromTerm(ATerm t) {
  return (((union {ERR_Subject target; ATerm source; })(t)).target);
}

/**
 * Transforms a ERR_Subjectto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg ERR_Subject to be converted
 * \return ATerm that represents the ERR_Subject
 */
ATerm _ERR_SubjectToTerm(ERR_Subject arg) {
  return (((union {ERR_Subject source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a ERR_Error. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return ERR_Error that was encoded by \arg
 */
ERR_Error _ERR_ErrorFromTerm(ATerm t) {
  return (((union {ERR_Error target; ATerm source; })(t)).target);
}

/**
 * Transforms a ERR_Errorto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg ERR_Error to be converted
 * \return ATerm that represents the ERR_Error
 */
ATerm _ERR_ErrorToTerm(ERR_Error arg) {
  return (((union {ERR_Error source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a ERR_Summary. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return ERR_Summary that was encoded by \arg
 */
ERR_Summary _ERR_SummaryFromTerm(ATerm t) {
  return (((union {ERR_Summary target; ATerm source; })(t)).target);
}

/**
 * Transforms a ERR_Summaryto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg ERR_Summary to be converted
 * \return ATerm that represents the ERR_Summary
 */
ATerm _ERR_SummaryToTerm(ERR_Summary arg) {
  return (((union {ERR_Summary source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a ERR_SubjectList. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return ERR_SubjectList that was encoded by \arg
 */
ERR_SubjectList _ERR_SubjectListFromTerm(ATerm t) {
  return (((union {ERR_SubjectList target; ATerm source; })(t)).target);
}

/**
 * Transforms a ERR_SubjectListto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg ERR_SubjectList to be converted
 * \return ATerm that represents the ERR_SubjectList
 */
ATerm _ERR_SubjectListToTerm(ERR_SubjectList arg) {
  return (((union {ERR_SubjectList source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a ERR_ErrorList. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return ERR_ErrorList that was encoded by \arg
 */
ERR_ErrorList _ERR_ErrorListFromTerm(ATerm t) {
  return (((union {ERR_ErrorList target; ATerm source; })(t)).target);
}

/**
 * Transforms a ERR_ErrorListto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg ERR_ErrorList to be converted
 * \return ATerm that represents the ERR_ErrorList
 */
ATerm _ERR_ErrorListToTerm(ERR_ErrorList arg) {
  return (((union {ERR_ErrorList source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a ERR_Location. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return ERR_Location that was encoded by \arg
 */
ERR_Location _ERR_LocationFromTerm(ATerm t) {
  return (((union {ERR_Location target; ATerm source; })(t)).target);
}

/**
 * Transforms a ERR_Locationto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg ERR_Location to be converted
 * \return ATerm that represents the ERR_Location
 */
ATerm _ERR_LocationToTerm(ERR_Location arg) {
  return (((union {ERR_Location source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a ERR_Area. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return ERR_Area that was encoded by \arg
 */
ERR_Area _ERR_AreaFromTerm(ATerm t) {
  return (((union {ERR_Area target; ATerm source; })(t)).target);
}

/**
 * Transforms a ERR_Areato an ATerm. This is just a wrapper for a cast.
 * \param[in] arg ERR_Area to be converted
 * \return ATerm that represents the ERR_Area
 */
ATerm _ERR_AreaToTerm(ERR_Area arg) {
  return (((union {ERR_Area source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a ERR_Slice. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return ERR_Slice that was encoded by \arg
 */
ERR_Slice _ERR_SliceFromTerm(ATerm t) {
  return (((union {ERR_Slice target; ATerm source; })(t)).target);
}

/**
 * Transforms a ERR_Sliceto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg ERR_Slice to be converted
 * \return ATerm that represents the ERR_Slice
 */
ATerm _ERR_SliceToTerm(ERR_Slice arg) {
  return (((union {ERR_Slice source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a ERR_AreaAreas. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return ERR_AreaAreas that was encoded by \arg
 */
ERR_AreaAreas _ERR_AreaAreasFromTerm(ATerm t) {
  return (((union {ERR_AreaAreas target; ATerm source; })(t)).target);
}

/**
 * Transforms a ERR_AreaAreasto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg ERR_AreaAreas to be converted
 * \return ATerm that represents the ERR_AreaAreas
 */
ATerm _ERR_AreaAreasToTerm(ERR_AreaAreas arg) {
  return (((union {ERR_AreaAreas source; ATerm target; })(arg)).target);
}

/**
 * Retrieve the length of a ERR_SubjectList. 
 * \param[in] arg input ERR_SubjectList
 * \return The number of elements in the ERR_SubjectList
 */
int _ERR_getSubjectListLength(ERR_SubjectList arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a ERR_SubjectList. 
 * \param[in] arg ERR_SubjectList to be reversed
 * \return a reversed #arg
 */
ERR_SubjectList _ERR_reverseSubjectList(ERR_SubjectList arg) {
  return (ERR_SubjectList) ATreverse((ATermList) arg);
}

/**
 * Append a ERR_Subject to the end of a ERR_SubjectList. 
 * \param[in] arg ERR_SubjectList to append the ERR_Subject to
 * \param[in] elem ERR_Subject to be appended
 * \return new ERR_SubjectList with #elem appended
 */
ERR_SubjectList _ERR_appendSubjectList(ERR_SubjectList arg, ERR_Subject elem) {
  return (ERR_SubjectList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two ERR_SubjectLists. 
 * \param[in] arg0 first ERR_SubjectList
 * \param[in] arg1 second ERR_SubjectList
 * \return ERR_SubjectList with the elements of #arg0 before the elements of #arg1
 */
ERR_SubjectList _ERR_concatSubjectList(ERR_SubjectList arg0, ERR_SubjectList arg1) {
  return (ERR_SubjectList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a ERR_SubjectList. 
 * \param[in] arg ERR_SubjectList to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new ERR_SubjectList with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
ERR_SubjectList _ERR_sliceSubjectList(ERR_SubjectList arg, int start, int end) {
  return (ERR_SubjectList) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the ERR_Subject at #index from a ERR_SubjectList. 
 * \param[in] arg ERR_SubjectList to retrieve the ERR_Subject from
 * \param[in] index index to use to point in the ERR_SubjectList
 * \return ERR_Subject at position #index in #arg
 */
ERR_Subject _ERR_getSubjectListSubjectAt(ERR_SubjectList arg, int index) {
 return (ERR_Subject)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the ERR_Subject at #index from a ERR_SubjectList by a new one. 
 * \param[in] arg ERR_SubjectList to retrieve the ERR_Subject from
 * \param[in] elem new ERR_Subject to replace another
 * \param[in] index index to use to point in the ERR_SubjectList
 * \return A new ERR_SubjectListwith #elem replaced in #arg at position #index
 */
ERR_SubjectList _ERR_replaceSubjectListSubjectAt(ERR_SubjectList arg, ERR_Subject elem, int index) {
 return (ERR_SubjectList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a ERR_SubjectList of 2 consecutive elements. 
 * \param[in] elem1 One ERR_Subject element of the new ERR_SubjectList
 * \param[in] elem2 One ERR_Subject element of the new ERR_SubjectList
 * \return A new ERR_SubjectList consisting of 2 ERR_Subjects
 */
ERR_SubjectList _ERR_makeSubjectList2(ERR_Subject elem1, ERR_Subject elem2) {
  return (ERR_SubjectList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a ERR_SubjectList of 3 consecutive elements. 
 * \param[in] elem1 One ERR_Subject element of the new ERR_SubjectList
 * \param[in] elem2 One ERR_Subject element of the new ERR_SubjectList
 * \param[in] elem3 One ERR_Subject element of the new ERR_SubjectList
 * \return A new ERR_SubjectList consisting of 3 ERR_Subjects
 */
ERR_SubjectList _ERR_makeSubjectList3(ERR_Subject elem1, ERR_Subject elem2, ERR_Subject elem3) {
  return (ERR_SubjectList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a ERR_SubjectList of 4 consecutive elements. 
 * \param[in] elem1 One ERR_Subject element of the new ERR_SubjectList
 * \param[in] elem2 One ERR_Subject element of the new ERR_SubjectList
 * \param[in] elem3 One ERR_Subject element of the new ERR_SubjectList
 * \param[in] elem4 One ERR_Subject element of the new ERR_SubjectList
 * \return A new ERR_SubjectList consisting of 4 ERR_Subjects
 */
ERR_SubjectList _ERR_makeSubjectList4(ERR_Subject elem1, ERR_Subject elem2, ERR_Subject elem3, ERR_Subject elem4) {
  return (ERR_SubjectList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a ERR_SubjectList of 5 consecutive elements. 
 * \param[in] elem1 One ERR_Subject element of the new ERR_SubjectList
 * \param[in] elem2 One ERR_Subject element of the new ERR_SubjectList
 * \param[in] elem3 One ERR_Subject element of the new ERR_SubjectList
 * \param[in] elem4 One ERR_Subject element of the new ERR_SubjectList
 * \param[in] elem5 One ERR_Subject element of the new ERR_SubjectList
 * \return A new ERR_SubjectList consisting of 5 ERR_Subjects
 */
ERR_SubjectList _ERR_makeSubjectList5(ERR_Subject elem1, ERR_Subject elem2, ERR_Subject elem3, ERR_Subject elem4, ERR_Subject elem5) {
  return (ERR_SubjectList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a ERR_SubjectList of 6 consecutive elements. 
 * \param[in] elem1 One ERR_Subject element of the new ERR_SubjectList
 * \param[in] elem2 One ERR_Subject element of the new ERR_SubjectList
 * \param[in] elem3 One ERR_Subject element of the new ERR_SubjectList
 * \param[in] elem4 One ERR_Subject element of the new ERR_SubjectList
 * \param[in] elem5 One ERR_Subject element of the new ERR_SubjectList
 * \param[in] elem6 One ERR_Subject element of the new ERR_SubjectList
 * \return A new ERR_SubjectList consisting of 6 ERR_Subjects
 */
ERR_SubjectList _ERR_makeSubjectList6(ERR_Subject elem1, ERR_Subject elem2, ERR_Subject elem3, ERR_Subject elem4, ERR_Subject elem5, ERR_Subject elem6) {
  return (ERR_SubjectList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a ERR_ErrorList. 
 * \param[in] arg input ERR_ErrorList
 * \return The number of elements in the ERR_ErrorList
 */
int _ERR_getErrorListLength(ERR_ErrorList arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a ERR_ErrorList. 
 * \param[in] arg ERR_ErrorList to be reversed
 * \return a reversed #arg
 */
ERR_ErrorList _ERR_reverseErrorList(ERR_ErrorList arg) {
  return (ERR_ErrorList) ATreverse((ATermList) arg);
}

/**
 * Append a ERR_Error to the end of a ERR_ErrorList. 
 * \param[in] arg ERR_ErrorList to append the ERR_Error to
 * \param[in] elem ERR_Error to be appended
 * \return new ERR_ErrorList with #elem appended
 */
ERR_ErrorList _ERR_appendErrorList(ERR_ErrorList arg, ERR_Error elem) {
  return (ERR_ErrorList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two ERR_ErrorLists. 
 * \param[in] arg0 first ERR_ErrorList
 * \param[in] arg1 second ERR_ErrorList
 * \return ERR_ErrorList with the elements of #arg0 before the elements of #arg1
 */
ERR_ErrorList _ERR_concatErrorList(ERR_ErrorList arg0, ERR_ErrorList arg1) {
  return (ERR_ErrorList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a ERR_ErrorList. 
 * \param[in] arg ERR_ErrorList to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new ERR_ErrorList with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
ERR_ErrorList _ERR_sliceErrorList(ERR_ErrorList arg, int start, int end) {
  return (ERR_ErrorList) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the ERR_Error at #index from a ERR_ErrorList. 
 * \param[in] arg ERR_ErrorList to retrieve the ERR_Error from
 * \param[in] index index to use to point in the ERR_ErrorList
 * \return ERR_Error at position #index in #arg
 */
ERR_Error _ERR_getErrorListErrorAt(ERR_ErrorList arg, int index) {
 return (ERR_Error)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the ERR_Error at #index from a ERR_ErrorList by a new one. 
 * \param[in] arg ERR_ErrorList to retrieve the ERR_Error from
 * \param[in] elem new ERR_Error to replace another
 * \param[in] index index to use to point in the ERR_ErrorList
 * \return A new ERR_ErrorListwith #elem replaced in #arg at position #index
 */
ERR_ErrorList _ERR_replaceErrorListErrorAt(ERR_ErrorList arg, ERR_Error elem, int index) {
 return (ERR_ErrorList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a ERR_ErrorList of 2 consecutive elements. 
 * \param[in] elem1 One ERR_Error element of the new ERR_ErrorList
 * \param[in] elem2 One ERR_Error element of the new ERR_ErrorList
 * \return A new ERR_ErrorList consisting of 2 ERR_Errors
 */
ERR_ErrorList _ERR_makeErrorList2(ERR_Error elem1, ERR_Error elem2) {
  return (ERR_ErrorList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a ERR_ErrorList of 3 consecutive elements. 
 * \param[in] elem1 One ERR_Error element of the new ERR_ErrorList
 * \param[in] elem2 One ERR_Error element of the new ERR_ErrorList
 * \param[in] elem3 One ERR_Error element of the new ERR_ErrorList
 * \return A new ERR_ErrorList consisting of 3 ERR_Errors
 */
ERR_ErrorList _ERR_makeErrorList3(ERR_Error elem1, ERR_Error elem2, ERR_Error elem3) {
  return (ERR_ErrorList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a ERR_ErrorList of 4 consecutive elements. 
 * \param[in] elem1 One ERR_Error element of the new ERR_ErrorList
 * \param[in] elem2 One ERR_Error element of the new ERR_ErrorList
 * \param[in] elem3 One ERR_Error element of the new ERR_ErrorList
 * \param[in] elem4 One ERR_Error element of the new ERR_ErrorList
 * \return A new ERR_ErrorList consisting of 4 ERR_Errors
 */
ERR_ErrorList _ERR_makeErrorList4(ERR_Error elem1, ERR_Error elem2, ERR_Error elem3, ERR_Error elem4) {
  return (ERR_ErrorList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a ERR_ErrorList of 5 consecutive elements. 
 * \param[in] elem1 One ERR_Error element of the new ERR_ErrorList
 * \param[in] elem2 One ERR_Error element of the new ERR_ErrorList
 * \param[in] elem3 One ERR_Error element of the new ERR_ErrorList
 * \param[in] elem4 One ERR_Error element of the new ERR_ErrorList
 * \param[in] elem5 One ERR_Error element of the new ERR_ErrorList
 * \return A new ERR_ErrorList consisting of 5 ERR_Errors
 */
ERR_ErrorList _ERR_makeErrorList5(ERR_Error elem1, ERR_Error elem2, ERR_Error elem3, ERR_Error elem4, ERR_Error elem5) {
  return (ERR_ErrorList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a ERR_ErrorList of 6 consecutive elements. 
 * \param[in] elem1 One ERR_Error element of the new ERR_ErrorList
 * \param[in] elem2 One ERR_Error element of the new ERR_ErrorList
 * \param[in] elem3 One ERR_Error element of the new ERR_ErrorList
 * \param[in] elem4 One ERR_Error element of the new ERR_ErrorList
 * \param[in] elem5 One ERR_Error element of the new ERR_ErrorList
 * \param[in] elem6 One ERR_Error element of the new ERR_ErrorList
 * \return A new ERR_ErrorList consisting of 6 ERR_Errors
 */
ERR_ErrorList _ERR_makeErrorList6(ERR_Error elem1, ERR_Error elem2, ERR_Error elem3, ERR_Error elem4, ERR_Error elem5, ERR_Error elem6) {
  return (ERR_ErrorList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a ERR_AreaAreas. 
 * \param[in] arg input ERR_AreaAreas
 * \return The number of elements in the ERR_AreaAreas
 */
int _ERR_getAreaAreasLength(ERR_AreaAreas arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a ERR_AreaAreas. 
 * \param[in] arg ERR_AreaAreas to be reversed
 * \return a reversed #arg
 */
ERR_AreaAreas _ERR_reverseAreaAreas(ERR_AreaAreas arg) {
  return (ERR_AreaAreas) ATreverse((ATermList) arg);
}

/**
 * Append a ERR_Area to the end of a ERR_AreaAreas. 
 * \param[in] arg ERR_AreaAreas to append the ERR_Area to
 * \param[in] elem ERR_Area to be appended
 * \return new ERR_AreaAreas with #elem appended
 */
ERR_AreaAreas _ERR_appendAreaAreas(ERR_AreaAreas arg, ERR_Area elem) {
  return (ERR_AreaAreas) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two ERR_AreaAreass. 
 * \param[in] arg0 first ERR_AreaAreas
 * \param[in] arg1 second ERR_AreaAreas
 * \return ERR_AreaAreas with the elements of #arg0 before the elements of #arg1
 */
ERR_AreaAreas _ERR_concatAreaAreas(ERR_AreaAreas arg0, ERR_AreaAreas arg1) {
  return (ERR_AreaAreas) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a ERR_AreaAreas. 
 * \param[in] arg ERR_AreaAreas to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new ERR_AreaAreas with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
ERR_AreaAreas _ERR_sliceAreaAreas(ERR_AreaAreas arg, int start, int end) {
  return (ERR_AreaAreas) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the ERR_Area at #index from a ERR_AreaAreas. 
 * \param[in] arg ERR_AreaAreas to retrieve the ERR_Area from
 * \param[in] index index to use to point in the ERR_AreaAreas
 * \return ERR_Area at position #index in #arg
 */
ERR_Area _ERR_getAreaAreasAreaAt(ERR_AreaAreas arg, int index) {
 return (ERR_Area)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the ERR_Area at #index from a ERR_AreaAreas by a new one. 
 * \param[in] arg ERR_AreaAreas to retrieve the ERR_Area from
 * \param[in] elem new ERR_Area to replace another
 * \param[in] index index to use to point in the ERR_AreaAreas
 * \return A new ERR_AreaAreaswith #elem replaced in #arg at position #index
 */
ERR_AreaAreas _ERR_replaceAreaAreasAreaAt(ERR_AreaAreas arg, ERR_Area elem, int index) {
 return (ERR_AreaAreas) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a ERR_AreaAreas of 2 consecutive elements. 
 * \param[in] elem1 One ERR_Area element of the new ERR_AreaAreas
 * \param[in] elem2 One ERR_Area element of the new ERR_AreaAreas
 * \return A new ERR_AreaAreas consisting of 2 ERR_Areas
 */
ERR_AreaAreas _ERR_makeAreaAreas2(ERR_Area elem1, ERR_Area elem2) {
  return (ERR_AreaAreas) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a ERR_AreaAreas of 3 consecutive elements. 
 * \param[in] elem1 One ERR_Area element of the new ERR_AreaAreas
 * \param[in] elem2 One ERR_Area element of the new ERR_AreaAreas
 * \param[in] elem3 One ERR_Area element of the new ERR_AreaAreas
 * \return A new ERR_AreaAreas consisting of 3 ERR_Areas
 */
ERR_AreaAreas _ERR_makeAreaAreas3(ERR_Area elem1, ERR_Area elem2, ERR_Area elem3) {
  return (ERR_AreaAreas) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a ERR_AreaAreas of 4 consecutive elements. 
 * \param[in] elem1 One ERR_Area element of the new ERR_AreaAreas
 * \param[in] elem2 One ERR_Area element of the new ERR_AreaAreas
 * \param[in] elem3 One ERR_Area element of the new ERR_AreaAreas
 * \param[in] elem4 One ERR_Area element of the new ERR_AreaAreas
 * \return A new ERR_AreaAreas consisting of 4 ERR_Areas
 */
ERR_AreaAreas _ERR_makeAreaAreas4(ERR_Area elem1, ERR_Area elem2, ERR_Area elem3, ERR_Area elem4) {
  return (ERR_AreaAreas) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a ERR_AreaAreas of 5 consecutive elements. 
 * \param[in] elem1 One ERR_Area element of the new ERR_AreaAreas
 * \param[in] elem2 One ERR_Area element of the new ERR_AreaAreas
 * \param[in] elem3 One ERR_Area element of the new ERR_AreaAreas
 * \param[in] elem4 One ERR_Area element of the new ERR_AreaAreas
 * \param[in] elem5 One ERR_Area element of the new ERR_AreaAreas
 * \return A new ERR_AreaAreas consisting of 5 ERR_Areas
 */
ERR_AreaAreas _ERR_makeAreaAreas5(ERR_Area elem1, ERR_Area elem2, ERR_Area elem3, ERR_Area elem4, ERR_Area elem5) {
  return (ERR_AreaAreas) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a ERR_AreaAreas of 6 consecutive elements. 
 * \param[in] elem1 One ERR_Area element of the new ERR_AreaAreas
 * \param[in] elem2 One ERR_Area element of the new ERR_AreaAreas
 * \param[in] elem3 One ERR_Area element of the new ERR_AreaAreas
 * \param[in] elem4 One ERR_Area element of the new ERR_AreaAreas
 * \param[in] elem5 One ERR_Area element of the new ERR_AreaAreas
 * \param[in] elem6 One ERR_Area element of the new ERR_AreaAreas
 * \return A new ERR_AreaAreas consisting of 6 ERR_Areas
 */
ERR_AreaAreas _ERR_makeAreaAreas6(ERR_Area elem1, ERR_Area elem2, ERR_Area elem3, ERR_Area elem4, ERR_Area elem5, ERR_Area elem6) {
  return (ERR_AreaAreas) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Constructs a StrChar of type ERR_StrChar. Like all ATerm types, ERR_StrChars are maximally shared.
 * \param[in] string a child of the new StrChar
 * \return A pointer to a StrChar, either newly constructed or shared
 */
ERR_StrChar ERR_makeStrCharStrChar(const char* string) {
  return (ERR_StrChar)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}
/**
 * Constructs a StrCon of type ERR_StrCon. Like all ATerm types, ERR_StrCons are maximally shared.
 * \param[in] string a child of the new StrCon
 * \return A pointer to a StrCon, either newly constructed or shared
 */
ERR_StrCon ERR_makeStrConStrCon(const char* string) {
  return (ERR_StrCon)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}
/**
 * Constructs a NatCon of type ERR_NatCon. Like all ATerm types, ERR_NatCons are maximally shared.
 * \param[in] string a child of the new NatCon
 * \return A pointer to a NatCon, either newly constructed or shared
 */
ERR_NatCon ERR_makeNatConNatCon(const char* string) {
  return (ERR_NatCon)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}
/**
 * Constructs a subject of type ERR_Subject. Like all ATerm types, ERR_Subjects are maximally shared.
 * \param[in] description a child of the new subject
 * \return A pointer to a subject, either newly constructed or shared
 */
ERR_Subject ERR_makeSubjectSubject(const char* description) {
  return (ERR_Subject)(ATerm)ATmakeAppl1(ERR_afun0, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue)));
}
/**
 * Constructs a localized of type ERR_Subject. Like all ATerm types, ERR_Subjects are maximally shared.
 * \param[in] description a child of the new localized
 * \param[in] Location a child of the new localized
 * \return A pointer to a localized, either newly constructed or shared
 */
ERR_Subject ERR_makeSubjectLocalized(const char* description, ERR_Location Location) {
  return (ERR_Subject)(ATerm)ATmakeAppl2(ERR_afun1, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue)), (ATerm) Location);
}
/**
 * Constructs a info of type ERR_Error. Like all ATerm types, ERR_Errors are maximally shared.
 * \param[in] description a child of the new info
 * \param[in] list a child of the new info
 * \return A pointer to a info, either newly constructed or shared
 */
ERR_Error ERR_makeErrorInfo(const char* description, ERR_SubjectList list) {
  return (ERR_Error)(ATerm)ATmakeAppl2(ERR_afun2, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue)), (ATerm) list);
}
/**
 * Constructs a warning of type ERR_Error. Like all ATerm types, ERR_Errors are maximally shared.
 * \param[in] description a child of the new warning
 * \param[in] list a child of the new warning
 * \return A pointer to a warning, either newly constructed or shared
 */
ERR_Error ERR_makeErrorWarning(const char* description, ERR_SubjectList list) {
  return (ERR_Error)(ATerm)ATmakeAppl2(ERR_afun3, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue)), (ATerm) list);
}
/**
 * Constructs a error of type ERR_Error. Like all ATerm types, ERR_Errors are maximally shared.
 * \param[in] description a child of the new error
 * \param[in] list a child of the new error
 * \return A pointer to a error, either newly constructed or shared
 */
ERR_Error ERR_makeErrorError(const char* description, ERR_SubjectList list) {
  return (ERR_Error)(ATerm)ATmakeAppl2(ERR_afun4, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue)), (ATerm) list);
}
/**
 * Constructs a fatal of type ERR_Error. Like all ATerm types, ERR_Errors are maximally shared.
 * \param[in] description a child of the new fatal
 * \param[in] list a child of the new fatal
 * \return A pointer to a fatal, either newly constructed or shared
 */
ERR_Error ERR_makeErrorFatal(const char* description, ERR_SubjectList list) {
  return (ERR_Error)(ATerm)ATmakeAppl2(ERR_afun5, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue)), (ATerm) list);
}
/**
 * Constructs a summary of type ERR_Summary. Like all ATerm types, ERR_Summarys are maximally shared.
 * \param[in] producer a child of the new summary
 * \param[in] id a child of the new summary
 * \param[in] list a child of the new summary
 * \return A pointer to a summary, either newly constructed or shared
 */
ERR_Summary ERR_makeSummarySummary(const char* producer, const char* id, ERR_ErrorList list) {
  return (ERR_Summary)(ATerm)ATmakeAppl3(ERR_afun6, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producer, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)), (ATerm) list);
}
/**
 * Constructs a empty of type ERR_SubjectList. Like all ATerm types, ERR_SubjectLists are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
ERR_SubjectList ERR_makeSubjectListEmpty(void) {
  return (ERR_SubjectList)(ATerm)ATempty;
}
/**
 * Constructs a single of type ERR_SubjectList. Like all ATerm types, ERR_SubjectLists are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
ERR_SubjectList ERR_makeSubjectListSingle(ERR_Subject head) {
  return (ERR_SubjectList)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type ERR_SubjectList. Like all ATerm types, ERR_SubjectLists are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
ERR_SubjectList ERR_makeSubjectListMany(ERR_Subject head, ERR_SubjectList tail) {
  return (ERR_SubjectList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a empty of type ERR_ErrorList. Like all ATerm types, ERR_ErrorLists are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
ERR_ErrorList ERR_makeErrorListEmpty(void) {
  return (ERR_ErrorList)(ATerm)ATempty;
}
/**
 * Constructs a single of type ERR_ErrorList. Like all ATerm types, ERR_ErrorLists are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
ERR_ErrorList ERR_makeErrorListSingle(ERR_Error head) {
  return (ERR_ErrorList)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type ERR_ErrorList. Like all ATerm types, ERR_ErrorLists are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
ERR_ErrorList ERR_makeErrorListMany(ERR_Error head, ERR_ErrorList tail) {
  return (ERR_ErrorList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a file of type ERR_Location. Like all ATerm types, ERR_Locations are maximally shared.
 * \param[in] filename a child of the new file
 * \return A pointer to a file, either newly constructed or shared
 */
ERR_Location ERR_makeLocationFile(const char* filename) {
  return (ERR_Location)(ATerm)ATmakeAppl1(ERR_afun7, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue)));
}
/**
 * Constructs a area of type ERR_Location. Like all ATerm types, ERR_Locations are maximally shared.
 * \param[in] Area a child of the new area
 * \return A pointer to a area, either newly constructed or shared
 */
ERR_Location ERR_makeLocationArea(ERR_Area Area) {
  return (ERR_Location)(ATerm)ATmakeAppl1(ERR_afun8, (ATerm) Area);
}
/**
 * Constructs a area-in-file of type ERR_Location. Like all ATerm types, ERR_Locations are maximally shared.
 * \param[in] filename a child of the new area-in-file
 * \param[in] Area a child of the new area-in-file
 * \return A pointer to a area-in-file, either newly constructed or shared
 */
ERR_Location ERR_makeLocationAreaInFile(const char* filename, ERR_Area Area) {
  return (ERR_Location)(ATerm)ATmakeAppl2(ERR_afun9, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue)), (ATerm) Area);
}
/**
 * Constructs a area of type ERR_Area. Like all ATerm types, ERR_Areas are maximally shared.
 * \param[in] beginLine a child of the new area
 * \param[in] beginColumn a child of the new area
 * \param[in] endLine a child of the new area
 * \param[in] endColumn a child of the new area
 * \param[in] offset a child of the new area
 * \param[in] length a child of the new area
 * \return A pointer to a area, either newly constructed or shared
 */
ERR_Area ERR_makeAreaArea(int beginLine, int beginColumn, int endLine, int endColumn, int offset, int length) {
  return (ERR_Area)(ATerm)ATmakeAppl6(ERR_afun10, (ATerm) (ATerm) ATmakeInt(beginLine), (ATerm) (ATerm) ATmakeInt(beginColumn), (ATerm) (ATerm) ATmakeInt(endLine), (ATerm) (ATerm) ATmakeInt(endColumn), (ATerm) (ATerm) ATmakeInt(offset), (ATerm) (ATerm) ATmakeInt(length));
}
/**
 * Constructs a slice of type ERR_Slice. Like all ATerm types, ERR_Slices are maximally shared.
 * \param[in] id a child of the new slice
 * \param[in] areas a child of the new slice
 * \return A pointer to a slice, either newly constructed or shared
 */
ERR_Slice ERR_makeSliceSlice(const char* id, ERR_AreaAreas areas) {
  return (ERR_Slice)(ATerm)ATmakeAppl2(ERR_afun11, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)), (ATerm) areas);
}
/**
 * Constructs a empty of type ERR_AreaAreas. Like all ATerm types, ERR_AreaAreass are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
ERR_AreaAreas ERR_makeAreaAreasEmpty(void) {
  return (ERR_AreaAreas)(ATerm)ATempty;
}
/**
 * Constructs a single of type ERR_AreaAreas. Like all ATerm types, ERR_AreaAreass are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
ERR_AreaAreas ERR_makeAreaAreasSingle(ERR_Area head) {
  return (ERR_AreaAreas)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type ERR_AreaAreas. Like all ATerm types, ERR_AreaAreass are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
ERR_AreaAreas ERR_makeAreaAreasMany(ERR_Area head, ERR_AreaAreas tail) {
  return (ERR_AreaAreas)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/**
 * Tests equality of two ERR_StrChars. A constant time operation.
 * \param[in] arg0 first ERR_StrChar to be compared
 * \param[in] arg1 second ERR_StrChar to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _ERR_isEqualStrChar(ERR_StrChar arg0, ERR_StrChar arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two ERR_StrCons. A constant time operation.
 * \param[in] arg0 first ERR_StrCon to be compared
 * \param[in] arg1 second ERR_StrCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _ERR_isEqualStrCon(ERR_StrCon arg0, ERR_StrCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two ERR_NatCons. A constant time operation.
 * \param[in] arg0 first ERR_NatCon to be compared
 * \param[in] arg1 second ERR_NatCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _ERR_isEqualNatCon(ERR_NatCon arg0, ERR_NatCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two ERR_Subjects. A constant time operation.
 * \param[in] arg0 first ERR_Subject to be compared
 * \param[in] arg1 second ERR_Subject to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _ERR_isEqualSubject(ERR_Subject arg0, ERR_Subject arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two ERR_Errors. A constant time operation.
 * \param[in] arg0 first ERR_Error to be compared
 * \param[in] arg1 second ERR_Error to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _ERR_isEqualError(ERR_Error arg0, ERR_Error arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two ERR_Summarys. A constant time operation.
 * \param[in] arg0 first ERR_Summary to be compared
 * \param[in] arg1 second ERR_Summary to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _ERR_isEqualSummary(ERR_Summary arg0, ERR_Summary arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two ERR_SubjectLists. A constant time operation.
 * \param[in] arg0 first ERR_SubjectList to be compared
 * \param[in] arg1 second ERR_SubjectList to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _ERR_isEqualSubjectList(ERR_SubjectList arg0, ERR_SubjectList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two ERR_ErrorLists. A constant time operation.
 * \param[in] arg0 first ERR_ErrorList to be compared
 * \param[in] arg1 second ERR_ErrorList to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _ERR_isEqualErrorList(ERR_ErrorList arg0, ERR_ErrorList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two ERR_Locations. A constant time operation.
 * \param[in] arg0 first ERR_Location to be compared
 * \param[in] arg1 second ERR_Location to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _ERR_isEqualLocation(ERR_Location arg0, ERR_Location arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two ERR_Areas. A constant time operation.
 * \param[in] arg0 first ERR_Area to be compared
 * \param[in] arg1 second ERR_Area to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _ERR_isEqualArea(ERR_Area arg0, ERR_Area arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two ERR_Slices. A constant time operation.
 * \param[in] arg0 first ERR_Slice to be compared
 * \param[in] arg1 second ERR_Slice to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _ERR_isEqualSlice(ERR_Slice arg0, ERR_Slice arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two ERR_AreaAreass. A constant time operation.
 * \param[in] arg0 first ERR_AreaAreas to be compared
 * \param[in] arg1 second ERR_AreaAreas to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _ERR_isEqualAreaAreas(ERR_AreaAreas arg0, ERR_AreaAreas arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Assert whether a ERR_StrChar is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input ERR_StrChar
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool ERR_isValidStrChar(ERR_StrChar arg) {
  if (ERR_isStrCharStrChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_StrChar is a StrChar by checking against the following ATerm pattern: <string(str)>. Always returns ATtrue
 * \param[in] arg input ERR_StrChar
 * \return ATtrue if #arg corresponds to the signature of a StrChar, or ATfalse otherwise
 */
inline ATbool ERR_isStrCharStrChar(ERR_StrChar arg){
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg)) == ATtrue) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_StrChar has a string. 
 * \param[in] arg input ERR_StrChar
 * \return ATtrue if the ERR_StrChar had a string, or ATfalse otherwise
 */
ATbool ERR_hasStrCharString(ERR_StrChar arg) {
  if (ERR_isStrCharStrChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the string char* of a ERR_StrChar. Note that the precondition is that this ERR_StrChar actually has a string
 * \param[in] arg input ERR_StrChar
 * \return the string of #arg, if it exist or an undefined value if it does not
 */
char* ERR_getStrCharString(ERR_StrChar arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/**
 * Set the string of a ERR_StrChar. The precondition being that this ERR_StrChar actually has a string
 * \param[in] arg input ERR_StrChar
 * \param[in] string new const char* to set in #arg
 * \return A new ERR_StrChar with string at the right place, or a core dump if #arg did not have a string
 */
ERR_StrChar ERR_setStrCharString(ERR_StrChar arg, const char* string) {
  if (ERR_isStrCharStrChar(arg)) {
    return (ERR_StrChar)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("StrChar has no String: %t\n", arg);
  return (ERR_StrChar)NULL;
}

/**
 * Assert whether a ERR_StrCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input ERR_StrCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool ERR_isValidStrCon(ERR_StrCon arg) {
  if (ERR_isStrConStrCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_StrCon is a StrCon by checking against the following ATerm pattern: <string(str)>. Always returns ATtrue
 * \param[in] arg input ERR_StrCon
 * \return ATtrue if #arg corresponds to the signature of a StrCon, or ATfalse otherwise
 */
inline ATbool ERR_isStrConStrCon(ERR_StrCon arg){
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg)) == ATtrue) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_StrCon has a string. 
 * \param[in] arg input ERR_StrCon
 * \return ATtrue if the ERR_StrCon had a string, or ATfalse otherwise
 */
ATbool ERR_hasStrConString(ERR_StrCon arg) {
  if (ERR_isStrConStrCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the string char* of a ERR_StrCon. Note that the precondition is that this ERR_StrCon actually has a string
 * \param[in] arg input ERR_StrCon
 * \return the string of #arg, if it exist or an undefined value if it does not
 */
char* ERR_getStrConString(ERR_StrCon arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/**
 * Set the string of a ERR_StrCon. The precondition being that this ERR_StrCon actually has a string
 * \param[in] arg input ERR_StrCon
 * \param[in] string new const char* to set in #arg
 * \return A new ERR_StrCon with string at the right place, or a core dump if #arg did not have a string
 */
ERR_StrCon ERR_setStrConString(ERR_StrCon arg, const char* string) {
  if (ERR_isStrConStrCon(arg)) {
    return (ERR_StrCon)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("StrCon has no String: %t\n", arg);
  return (ERR_StrCon)NULL;
}

/**
 * Assert whether a ERR_NatCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input ERR_NatCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool ERR_isValidNatCon(ERR_NatCon arg) {
  if (ERR_isNatConNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_NatCon is a NatCon by checking against the following ATerm pattern: <string(str)>. Always returns ATtrue
 * \param[in] arg input ERR_NatCon
 * \return ATtrue if #arg corresponds to the signature of a NatCon, or ATfalse otherwise
 */
inline ATbool ERR_isNatConNatCon(ERR_NatCon arg){
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg)) == ATtrue) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_NatCon has a string. 
 * \param[in] arg input ERR_NatCon
 * \return ATtrue if the ERR_NatCon had a string, or ATfalse otherwise
 */
ATbool ERR_hasNatConString(ERR_NatCon arg) {
  if (ERR_isNatConNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the string char* of a ERR_NatCon. Note that the precondition is that this ERR_NatCon actually has a string
 * \param[in] arg input ERR_NatCon
 * \return the string of #arg, if it exist or an undefined value if it does not
 */
char* ERR_getNatConString(ERR_NatCon arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/**
 * Set the string of a ERR_NatCon. The precondition being that this ERR_NatCon actually has a string
 * \param[in] arg input ERR_NatCon
 * \param[in] string new const char* to set in #arg
 * \return A new ERR_NatCon with string at the right place, or a core dump if #arg did not have a string
 */
ERR_NatCon ERR_setNatConString(ERR_NatCon arg, const char* string) {
  if (ERR_isNatConNatCon(arg)) {
    return (ERR_NatCon)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("NatCon has no String: %t\n", arg);
  return (ERR_NatCon)NULL;
}

/**
 * Assert whether a ERR_Subject is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input ERR_Subject
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool ERR_isValidSubject(ERR_Subject arg) {
  if (ERR_isSubjectSubject(arg)) {
    return ATtrue;
  }
  else if (ERR_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Subject is a subject by checking against the following ATerm pattern: subject(<"description"(str)>). May not be used to assert correctness of the ERR_Subject
 * \param[in] arg input ERR_Subject
 * \return ATtrue if #arg corresponds to the signature of a subject, or ATfalse otherwise
 */
inline ATbool ERR_isSubjectSubject(ERR_Subject arg){
  /* checking for: subject */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == ERR_afun0) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Subject is a localized by checking against the following ATerm pattern: localized(<"description"(str)>,<"Location"("Location")>). May not be used to assert correctness of the ERR_Subject
 * \param[in] arg input ERR_Subject
 * \return ATtrue if #arg corresponds to the signature of a localized, or ATfalse otherwise
 */
inline ATbool ERR_isSubjectLocalized(ERR_Subject arg){
  /* checking for: localized */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == ERR_afun1) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Subject has a description. 
 * \param[in] arg input ERR_Subject
 * \return ATtrue if the ERR_Subject had a description, or ATfalse otherwise
 */
ATbool ERR_hasSubjectDescription(ERR_Subject arg) {
  if (ERR_isSubjectSubject(arg)) {
    return ATtrue;
  }
  else if (ERR_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Subject has a Location. 
 * \param[in] arg input ERR_Subject
 * \return ATtrue if the ERR_Subject had a Location, or ATfalse otherwise
 */
ATbool ERR_hasSubjectLocation(ERR_Subject arg) {
  if (ERR_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the description char* of a ERR_Subject. Note that the precondition is that this ERR_Subject actually has a description
 * \param[in] arg input ERR_Subject
 * \return the description of #arg, if it exist or an undefined value if it does not
 */
char* ERR_getSubjectDescription(ERR_Subject arg) {
  if (ERR_isSubjectSubject(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the Location ERR_Location of a ERR_Subject. Note that the precondition is that this ERR_Subject actually has a Location
 * \param[in] arg input ERR_Subject
 * \return the Location of #arg, if it exist or an undefined value if it does not
 */
ERR_Location ERR_getSubjectLocation(ERR_Subject arg) {
  
    return (ERR_Location)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Set the description of a ERR_Subject. The precondition being that this ERR_Subject actually has a description
 * \param[in] arg input ERR_Subject
 * \param[in] description new const char* to set in #arg
 * \return A new ERR_Subject with description at the right place, or a core dump if #arg did not have a description
 */
ERR_Subject ERR_setSubjectDescription(ERR_Subject arg, const char* description) {
  if (ERR_isSubjectSubject(arg)) {
    return (ERR_Subject)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue))), 0);
  }
  else if (ERR_isSubjectLocalized(arg)) {
    return (ERR_Subject)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue))), 0);
  }

  ATabort("Subject has no Description: %t\n", arg);
  return (ERR_Subject)NULL;
}

/**
 * Set the Location of a ERR_Subject. The precondition being that this ERR_Subject actually has a Location
 * \param[in] arg input ERR_Subject
 * \param[in] Location new ERR_Location to set in #arg
 * \return A new ERR_Subject with Location at the right place, or a core dump if #arg did not have a Location
 */
ERR_Subject ERR_setSubjectLocation(ERR_Subject arg, ERR_Location Location) {
  if (ERR_isSubjectLocalized(arg)) {
    return (ERR_Subject)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Location), 1);
  }

  ATabort("Subject has no Location: %t\n", arg);
  return (ERR_Subject)NULL;
}

/**
 * Assert whether a ERR_Error is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input ERR_Error
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool ERR_isValidError(ERR_Error arg) {
  if (ERR_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (ERR_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (ERR_isErrorError(arg)) {
    return ATtrue;
  }
  else if (ERR_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Error is a info by checking against the following ATerm pattern: info(<"description"(str)>,<"list"("Subject-list")>). May not be used to assert correctness of the ERR_Error
 * \param[in] arg input ERR_Error
 * \return ATtrue if #arg corresponds to the signature of a info, or ATfalse otherwise
 */
inline ATbool ERR_isErrorInfo(ERR_Error arg){
  /* checking for: info */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == ERR_afun2) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Error is a warning by checking against the following ATerm pattern: warning(<"description"(str)>,<"list"("Subject-list")>). May not be used to assert correctness of the ERR_Error
 * \param[in] arg input ERR_Error
 * \return ATtrue if #arg corresponds to the signature of a warning, or ATfalse otherwise
 */
inline ATbool ERR_isErrorWarning(ERR_Error arg){
  /* checking for: warning */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == ERR_afun3) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Error is a error by checking against the following ATerm pattern: error(<"description"(str)>,<"list"("Subject-list")>). May not be used to assert correctness of the ERR_Error
 * \param[in] arg input ERR_Error
 * \return ATtrue if #arg corresponds to the signature of a error, or ATfalse otherwise
 */
inline ATbool ERR_isErrorError(ERR_Error arg){
  /* checking for: error */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == ERR_afun4) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Error is a fatal by checking against the following ATerm pattern: fatal(<"description"(str)>,<"list"("Subject-list")>). May not be used to assert correctness of the ERR_Error
 * \param[in] arg input ERR_Error
 * \return ATtrue if #arg corresponds to the signature of a fatal, or ATfalse otherwise
 */
inline ATbool ERR_isErrorFatal(ERR_Error arg){
  /* checking for: fatal */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == ERR_afun5) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Error has a description. 
 * \param[in] arg input ERR_Error
 * \return ATtrue if the ERR_Error had a description, or ATfalse otherwise
 */
ATbool ERR_hasErrorDescription(ERR_Error arg) {
  if (ERR_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (ERR_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (ERR_isErrorError(arg)) {
    return ATtrue;
  }
  else if (ERR_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Error has a list. 
 * \param[in] arg input ERR_Error
 * \return ATtrue if the ERR_Error had a list, or ATfalse otherwise
 */
ATbool ERR_hasErrorList(ERR_Error arg) {
  if (ERR_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (ERR_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (ERR_isErrorError(arg)) {
    return ATtrue;
  }
  else if (ERR_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the description char* of a ERR_Error. Note that the precondition is that this ERR_Error actually has a description
 * \param[in] arg input ERR_Error
 * \return the description of #arg, if it exist or an undefined value if it does not
 */
char* ERR_getErrorDescription(ERR_Error arg) {
  if (ERR_isErrorInfo(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (ERR_isErrorWarning(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (ERR_isErrorError(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the list ERR_SubjectList of a ERR_Error. Note that the precondition is that this ERR_Error actually has a list
 * \param[in] arg input ERR_Error
 * \return the list of #arg, if it exist or an undefined value if it does not
 */
ERR_SubjectList ERR_getErrorList(ERR_Error arg) {
  if (ERR_isErrorInfo(arg)) {
    return (ERR_SubjectList)ATgetArgument((ATermAppl)arg, 1);
  }
  else if (ERR_isErrorWarning(arg)) {
    return (ERR_SubjectList)ATgetArgument((ATermAppl)arg, 1);
  }
  else if (ERR_isErrorError(arg)) {
    return (ERR_SubjectList)ATgetArgument((ATermAppl)arg, 1);
  }
  else 
    return (ERR_SubjectList)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Set the description of a ERR_Error. The precondition being that this ERR_Error actually has a description
 * \param[in] arg input ERR_Error
 * \param[in] description new const char* to set in #arg
 * \return A new ERR_Error with description at the right place, or a core dump if #arg did not have a description
 */
ERR_Error ERR_setErrorDescription(ERR_Error arg, const char* description) {
  if (ERR_isErrorInfo(arg)) {
    return (ERR_Error)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue))), 0);
  }
  else if (ERR_isErrorWarning(arg)) {
    return (ERR_Error)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue))), 0);
  }
  else if (ERR_isErrorError(arg)) {
    return (ERR_Error)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue))), 0);
  }
  else if (ERR_isErrorFatal(arg)) {
    return (ERR_Error)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue))), 0);
  }

  ATabort("Error has no Description: %t\n", arg);
  return (ERR_Error)NULL;
}

/**
 * Set the list of a ERR_Error. The precondition being that this ERR_Error actually has a list
 * \param[in] arg input ERR_Error
 * \param[in] list new ERR_SubjectList to set in #arg
 * \return A new ERR_Error with list at the right place, or a core dump if #arg did not have a list
 */
ERR_Error ERR_setErrorList(ERR_Error arg, ERR_SubjectList list) {
  if (ERR_isErrorInfo(arg)) {
    return (ERR_Error)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 1);
  }
  else if (ERR_isErrorWarning(arg)) {
    return (ERR_Error)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 1);
  }
  else if (ERR_isErrorError(arg)) {
    return (ERR_Error)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 1);
  }
  else if (ERR_isErrorFatal(arg)) {
    return (ERR_Error)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 1);
  }

  ATabort("Error has no List: %t\n", arg);
  return (ERR_Error)NULL;
}

/**
 * Assert whether a ERR_Summary is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input ERR_Summary
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool ERR_isValidSummary(ERR_Summary arg) {
  if (ERR_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Summary is a summary by checking against the following ATerm pattern: summary(<"producer"(str)>,<"id"(str)>,<"list"("Error-list")>). Always returns ATtrue
 * \param[in] arg input ERR_Summary
 * \return ATtrue if #arg corresponds to the signature of a summary, or ATfalse otherwise
 */
inline ATbool ERR_isSummarySummary(ERR_Summary arg){
  /* checking for: summary */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == ERR_afun6) {
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
 * Assert whether a ERR_Summary has a producer. 
 * \param[in] arg input ERR_Summary
 * \return ATtrue if the ERR_Summary had a producer, or ATfalse otherwise
 */
ATbool ERR_hasSummaryProducer(ERR_Summary arg) {
  if (ERR_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Summary has a id. 
 * \param[in] arg input ERR_Summary
 * \return ATtrue if the ERR_Summary had a id, or ATfalse otherwise
 */
ATbool ERR_hasSummaryId(ERR_Summary arg) {
  if (ERR_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Summary has a list. 
 * \param[in] arg input ERR_Summary
 * \return ATtrue if the ERR_Summary had a list, or ATfalse otherwise
 */
ATbool ERR_hasSummaryList(ERR_Summary arg) {
  if (ERR_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the producer char* of a ERR_Summary. Note that the precondition is that this ERR_Summary actually has a producer
 * \param[in] arg input ERR_Summary
 * \return the producer of #arg, if it exist or an undefined value if it does not
 */
char* ERR_getSummaryProducer(ERR_Summary arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the id char* of a ERR_Summary. Note that the precondition is that this ERR_Summary actually has a id
 * \param[in] arg input ERR_Summary
 * \return the id of #arg, if it exist or an undefined value if it does not
 */
char* ERR_getSummaryId(ERR_Summary arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/**
 * Get the list ERR_ErrorList of a ERR_Summary. Note that the precondition is that this ERR_Summary actually has a list
 * \param[in] arg input ERR_Summary
 * \return the list of #arg, if it exist or an undefined value if it does not
 */
ERR_ErrorList ERR_getSummaryList(ERR_Summary arg) {
  
    return (ERR_ErrorList)ATgetArgument((ATermAppl)arg, 2);
}

/**
 * Set the producer of a ERR_Summary. The precondition being that this ERR_Summary actually has a producer
 * \param[in] arg input ERR_Summary
 * \param[in] producer new const char* to set in #arg
 * \return A new ERR_Summary with producer at the right place, or a core dump if #arg did not have a producer
 */
ERR_Summary ERR_setSummaryProducer(ERR_Summary arg, const char* producer) {
  if (ERR_isSummarySummary(arg)) {
    return (ERR_Summary)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producer, 0, ATtrue))), 0);
  }

  ATabort("Summary has no Producer: %t\n", arg);
  return (ERR_Summary)NULL;
}

/**
 * Set the id of a ERR_Summary. The precondition being that this ERR_Summary actually has a id
 * \param[in] arg input ERR_Summary
 * \param[in] id new const char* to set in #arg
 * \return A new ERR_Summary with id at the right place, or a core dump if #arg did not have a id
 */
ERR_Summary ERR_setSummaryId(ERR_Summary arg, const char* id) {
  if (ERR_isSummarySummary(arg)) {
    return (ERR_Summary)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue))), 1);
  }

  ATabort("Summary has no Id: %t\n", arg);
  return (ERR_Summary)NULL;
}

/**
 * Set the list of a ERR_Summary. The precondition being that this ERR_Summary actually has a list
 * \param[in] arg input ERR_Summary
 * \param[in] list new ERR_ErrorList to set in #arg
 * \return A new ERR_Summary with list at the right place, or a core dump if #arg did not have a list
 */
ERR_Summary ERR_setSummaryList(ERR_Summary arg, ERR_ErrorList list) {
  if (ERR_isSummarySummary(arg)) {
    return (ERR_Summary)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 2);
  }

  ATabort("Summary has no List: %t\n", arg);
  return (ERR_Summary)NULL;
}

/**
 * Assert whether a ERR_SubjectList is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input ERR_SubjectList
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool ERR_isValidSubjectList(ERR_SubjectList arg) {
  if (ERR_isSubjectListEmpty(arg)) {
    return ATtrue;
  }
  else if (ERR_isSubjectListSingle(arg)) {
    return ATtrue;
  }
  else if (ERR_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_SubjectList is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the ERR_SubjectList
 * \param[in] arg input ERR_SubjectList
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool ERR_isSubjectListEmpty(ERR_SubjectList arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_SubjectList is a single by checking against the following ATerm pattern: [<head(Subject)>]. May not be used to assert correctness of the ERR_SubjectList
 * \param[in] arg input ERR_SubjectList
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool ERR_isSubjectListSingle(ERR_SubjectList arg){
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
 * Assert whether a ERR_SubjectList is a many by checking against the following ATerm pattern: [<head(Subject)>,<[tail(Subject-list)]>]. May not be used to assert correctness of the ERR_SubjectList
 * \param[in] arg input ERR_SubjectList
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool ERR_isSubjectListMany(ERR_SubjectList arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_SubjectList has a head. 
 * \param[in] arg input ERR_SubjectList
 * \return ATtrue if the ERR_SubjectList had a head, or ATfalse otherwise
 */
ATbool ERR_hasSubjectListHead(ERR_SubjectList arg) {
  if (ERR_isSubjectListSingle(arg)) {
    return ATtrue;
  }
  else if (ERR_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_SubjectList has a tail. 
 * \param[in] arg input ERR_SubjectList
 * \return ATtrue if the ERR_SubjectList had a tail, or ATfalse otherwise
 */
ATbool ERR_hasSubjectListTail(ERR_SubjectList arg) {
  if (ERR_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head ERR_Subject of a ERR_SubjectList. Note that the precondition is that this ERR_SubjectList actually has a head
 * \param[in] arg input ERR_SubjectList
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
ERR_Subject ERR_getSubjectListHead(ERR_SubjectList arg) {
  if (ERR_isSubjectListSingle(arg)) {
    return (ERR_Subject)ATgetFirst((ATermList)arg);
  }
  else 
    return (ERR_Subject)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail ERR_SubjectList of a ERR_SubjectList. Note that the precondition is that this ERR_SubjectList actually has a tail
 * \param[in] arg input ERR_SubjectList
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
ERR_SubjectList ERR_getSubjectListTail(ERR_SubjectList arg) {
  
    return (ERR_SubjectList)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a ERR_SubjectList. The precondition being that this ERR_SubjectList actually has a head
 * \param[in] arg input ERR_SubjectList
 * \param[in] head new ERR_Subject to set in #arg
 * \return A new ERR_SubjectList with head at the right place, or a core dump if #arg did not have a head
 */
ERR_SubjectList ERR_setSubjectListHead(ERR_SubjectList arg, ERR_Subject head) {
  if (ERR_isSubjectListSingle(arg)) {
    return (ERR_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (ERR_isSubjectListMany(arg)) {
    return (ERR_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("SubjectList has no Head: %t\n", arg);
  return (ERR_SubjectList)NULL;
}

/**
 * Set the tail of a ERR_SubjectList. The precondition being that this ERR_SubjectList actually has a tail
 * \param[in] arg input ERR_SubjectList
 * \param[in] tail new ERR_SubjectList to set in #arg
 * \return A new ERR_SubjectList with tail at the right place, or a core dump if #arg did not have a tail
 */
ERR_SubjectList ERR_setSubjectListTail(ERR_SubjectList arg, ERR_SubjectList tail) {
  if (ERR_isSubjectListMany(arg)) {
    return (ERR_SubjectList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("SubjectList has no Tail: %t\n", arg);
  return (ERR_SubjectList)NULL;
}

/**
 * Assert whether a ERR_ErrorList is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input ERR_ErrorList
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool ERR_isValidErrorList(ERR_ErrorList arg) {
  if (ERR_isErrorListEmpty(arg)) {
    return ATtrue;
  }
  else if (ERR_isErrorListSingle(arg)) {
    return ATtrue;
  }
  else if (ERR_isErrorListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_ErrorList is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the ERR_ErrorList
 * \param[in] arg input ERR_ErrorList
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool ERR_isErrorListEmpty(ERR_ErrorList arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_ErrorList is a single by checking against the following ATerm pattern: [<head(Error)>]. May not be used to assert correctness of the ERR_ErrorList
 * \param[in] arg input ERR_ErrorList
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool ERR_isErrorListSingle(ERR_ErrorList arg){
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
 * Assert whether a ERR_ErrorList is a many by checking against the following ATerm pattern: [<head(Error)>,<[tail(Error-list)]>]. May not be used to assert correctness of the ERR_ErrorList
 * \param[in] arg input ERR_ErrorList
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool ERR_isErrorListMany(ERR_ErrorList arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_ErrorList has a head. 
 * \param[in] arg input ERR_ErrorList
 * \return ATtrue if the ERR_ErrorList had a head, or ATfalse otherwise
 */
ATbool ERR_hasErrorListHead(ERR_ErrorList arg) {
  if (ERR_isErrorListSingle(arg)) {
    return ATtrue;
  }
  else if (ERR_isErrorListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_ErrorList has a tail. 
 * \param[in] arg input ERR_ErrorList
 * \return ATtrue if the ERR_ErrorList had a tail, or ATfalse otherwise
 */
ATbool ERR_hasErrorListTail(ERR_ErrorList arg) {
  if (ERR_isErrorListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head ERR_Error of a ERR_ErrorList. Note that the precondition is that this ERR_ErrorList actually has a head
 * \param[in] arg input ERR_ErrorList
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
ERR_Error ERR_getErrorListHead(ERR_ErrorList arg) {
  if (ERR_isErrorListSingle(arg)) {
    return (ERR_Error)ATgetFirst((ATermList)arg);
  }
  else 
    return (ERR_Error)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail ERR_ErrorList of a ERR_ErrorList. Note that the precondition is that this ERR_ErrorList actually has a tail
 * \param[in] arg input ERR_ErrorList
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
ERR_ErrorList ERR_getErrorListTail(ERR_ErrorList arg) {
  
    return (ERR_ErrorList)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a ERR_ErrorList. The precondition being that this ERR_ErrorList actually has a head
 * \param[in] arg input ERR_ErrorList
 * \param[in] head new ERR_Error to set in #arg
 * \return A new ERR_ErrorList with head at the right place, or a core dump if #arg did not have a head
 */
ERR_ErrorList ERR_setErrorListHead(ERR_ErrorList arg, ERR_Error head) {
  if (ERR_isErrorListSingle(arg)) {
    return (ERR_ErrorList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (ERR_isErrorListMany(arg)) {
    return (ERR_ErrorList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ErrorList has no Head: %t\n", arg);
  return (ERR_ErrorList)NULL;
}

/**
 * Set the tail of a ERR_ErrorList. The precondition being that this ERR_ErrorList actually has a tail
 * \param[in] arg input ERR_ErrorList
 * \param[in] tail new ERR_ErrorList to set in #arg
 * \return A new ERR_ErrorList with tail at the right place, or a core dump if #arg did not have a tail
 */
ERR_ErrorList ERR_setErrorListTail(ERR_ErrorList arg, ERR_ErrorList tail) {
  if (ERR_isErrorListMany(arg)) {
    return (ERR_ErrorList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("ErrorList has no Tail: %t\n", arg);
  return (ERR_ErrorList)NULL;
}

/**
 * Assert whether a ERR_Location is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input ERR_Location
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool ERR_isValidLocation(ERR_Location arg) {
  if (ERR_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (ERR_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (ERR_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Location is a file by checking against the following ATerm pattern: file(<"filename"(str)>). May not be used to assert correctness of the ERR_Location
 * \param[in] arg input ERR_Location
 * \return ATtrue if #arg corresponds to the signature of a file, or ATfalse otherwise
 */
inline ATbool ERR_isLocationFile(ERR_Location arg){
  /* checking for: file */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == ERR_afun7) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Location is a area by checking against the following ATerm pattern: area(<"Area"("Area")>). May not be used to assert correctness of the ERR_Location
 * \param[in] arg input ERR_Location
 * \return ATtrue if #arg corresponds to the signature of a area, or ATfalse otherwise
 */
inline ATbool ERR_isLocationArea(ERR_Location arg){
  /* checking for: area */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == ERR_afun8) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Location is a area-in-file by checking against the following ATerm pattern: area-in-file(<"filename"(str)>,<"Area"("Area")>). May not be used to assert correctness of the ERR_Location
 * \param[in] arg input ERR_Location
 * \return ATtrue if #arg corresponds to the signature of a area-in-file, or ATfalse otherwise
 */
inline ATbool ERR_isLocationAreaInFile(ERR_Location arg){
  /* checking for: area-in-file */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == ERR_afun9) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Location has a filename. 
 * \param[in] arg input ERR_Location
 * \return ATtrue if the ERR_Location had a filename, or ATfalse otherwise
 */
ATbool ERR_hasLocationFilename(ERR_Location arg) {
  if (ERR_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (ERR_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Location has a Area. 
 * \param[in] arg input ERR_Location
 * \return ATtrue if the ERR_Location had a Area, or ATfalse otherwise
 */
ATbool ERR_hasLocationArea(ERR_Location arg) {
  if (ERR_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (ERR_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the filename char* of a ERR_Location. Note that the precondition is that this ERR_Location actually has a filename
 * \param[in] arg input ERR_Location
 * \return the filename of #arg, if it exist or an undefined value if it does not
 */
char* ERR_getLocationFilename(ERR_Location arg) {
  if (ERR_isLocationFile(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the Area ERR_Area of a ERR_Location. Note that the precondition is that this ERR_Location actually has a Area
 * \param[in] arg input ERR_Location
 * \return the Area of #arg, if it exist or an undefined value if it does not
 */
ERR_Area ERR_getLocationArea(ERR_Location arg) {
  if (ERR_isLocationArea(arg)) {
    return (ERR_Area)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (ERR_Area)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Set the filename of a ERR_Location. The precondition being that this ERR_Location actually has a filename
 * \param[in] arg input ERR_Location
 * \param[in] filename new const char* to set in #arg
 * \return A new ERR_Location with filename at the right place, or a core dump if #arg did not have a filename
 */
ERR_Location ERR_setLocationFilename(ERR_Location arg, const char* filename) {
  if (ERR_isLocationFile(arg)) {
    return (ERR_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue))), 0);
  }
  else if (ERR_isLocationAreaInFile(arg)) {
    return (ERR_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue))), 0);
  }

  ATabort("Location has no Filename: %t\n", arg);
  return (ERR_Location)NULL;
}

/**
 * Set the Area of a ERR_Location. The precondition being that this ERR_Location actually has a Area
 * \param[in] arg input ERR_Location
 * \param[in] Area new ERR_Area to set in #arg
 * \return A new ERR_Location with Area at the right place, or a core dump if #arg did not have a Area
 */
ERR_Location ERR_setLocationArea(ERR_Location arg, ERR_Area Area) {
  if (ERR_isLocationArea(arg)) {
    return (ERR_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Area), 0);
  }
  else if (ERR_isLocationAreaInFile(arg)) {
    return (ERR_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Area), 1);
  }

  ATabort("Location has no Area: %t\n", arg);
  return (ERR_Location)NULL;
}

/**
 * Assert whether a ERR_Area is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input ERR_Area
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool ERR_isValidArea(ERR_Area arg) {
  if (ERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Area is a area by checking against the following ATerm pattern: area(<"begin-line"(int)>,<"begin-column"(int)>,<"end-line"(int)>,<"end-column"(int)>,<"offset"(int)>,<"length"(int)>). Always returns ATtrue
 * \param[in] arg input ERR_Area
 * \return ATtrue if #arg corresponds to the signature of a area, or ATfalse otherwise
 */
inline ATbool ERR_isAreaArea(ERR_Area arg){
  /* checking for: area */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == ERR_afun10) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_INT) {
      ATerm arg_arg1 = ATgetArgument(arg, 1);
      if (ATgetType((ATerm)arg_arg1) == AT_INT) {
        ATerm arg_arg2 = ATgetArgument(arg, 2);
        if (ATgetType((ATerm)arg_arg2) == AT_INT) {
          ATerm arg_arg3 = ATgetArgument(arg, 3);
          if (ATgetType((ATerm)arg_arg3) == AT_INT) {
            ATerm arg_arg4 = ATgetArgument(arg, 4);
            if (ATgetType((ATerm)arg_arg4) == AT_INT) {
              ATerm arg_arg5 = ATgetArgument(arg, 5);
              if (ATgetType((ATerm)arg_arg5) == AT_INT) {
                return ATtrue;
              }
            }
          }
        }
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Area has a begin-line. 
 * \param[in] arg input ERR_Area
 * \return ATtrue if the ERR_Area had a begin-line, or ATfalse otherwise
 */
ATbool ERR_hasAreaBeginLine(ERR_Area arg) {
  if (ERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Area has a begin-column. 
 * \param[in] arg input ERR_Area
 * \return ATtrue if the ERR_Area had a begin-column, or ATfalse otherwise
 */
ATbool ERR_hasAreaBeginColumn(ERR_Area arg) {
  if (ERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Area has a end-line. 
 * \param[in] arg input ERR_Area
 * \return ATtrue if the ERR_Area had a end-line, or ATfalse otherwise
 */
ATbool ERR_hasAreaEndLine(ERR_Area arg) {
  if (ERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Area has a end-column. 
 * \param[in] arg input ERR_Area
 * \return ATtrue if the ERR_Area had a end-column, or ATfalse otherwise
 */
ATbool ERR_hasAreaEndColumn(ERR_Area arg) {
  if (ERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Area has a offset. 
 * \param[in] arg input ERR_Area
 * \return ATtrue if the ERR_Area had a offset, or ATfalse otherwise
 */
ATbool ERR_hasAreaOffset(ERR_Area arg) {
  if (ERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Area has a length. 
 * \param[in] arg input ERR_Area
 * \return ATtrue if the ERR_Area had a length, or ATfalse otherwise
 */
ATbool ERR_hasAreaLength(ERR_Area arg) {
  if (ERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the begin-line int of a ERR_Area. Note that the precondition is that this ERR_Area actually has a begin-line
 * \param[in] arg input ERR_Area
 * \return the begin-line of #arg, if it exist or an undefined value if it does not
 */
int ERR_getAreaBeginLine(ERR_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Get the begin-column int of a ERR_Area. Note that the precondition is that this ERR_Area actually has a begin-column
 * \param[in] arg input ERR_Area
 * \return the begin-column of #arg, if it exist or an undefined value if it does not
 */
int ERR_getAreaBeginColumn(ERR_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the end-line int of a ERR_Area. Note that the precondition is that this ERR_Area actually has a end-line
 * \param[in] arg input ERR_Area
 * \return the end-line of #arg, if it exist or an undefined value if it does not
 */
int ERR_getAreaEndLine(ERR_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/**
 * Get the end-column int of a ERR_Area. Note that the precondition is that this ERR_Area actually has a end-column
 * \param[in] arg input ERR_Area
 * \return the end-column of #arg, if it exist or an undefined value if it does not
 */
int ERR_getAreaEndColumn(ERR_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 3));
}

/**
 * Get the offset int of a ERR_Area. Note that the precondition is that this ERR_Area actually has a offset
 * \param[in] arg input ERR_Area
 * \return the offset of #arg, if it exist or an undefined value if it does not
 */
int ERR_getAreaOffset(ERR_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 4));
}

/**
 * Get the length int of a ERR_Area. Note that the precondition is that this ERR_Area actually has a length
 * \param[in] arg input ERR_Area
 * \return the length of #arg, if it exist or an undefined value if it does not
 */
int ERR_getAreaLength(ERR_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 5));
}

/**
 * Set the begin-line of a ERR_Area. The precondition being that this ERR_Area actually has a begin-line
 * \param[in] arg input ERR_Area
 * \param[in] beginLine new int to set in #arg
 * \return A new ERR_Area with beginLine at the right place, or a core dump if #arg did not have a beginLine
 */
ERR_Area ERR_setAreaBeginLine(ERR_Area arg, int beginLine) {
  if (ERR_isAreaArea(arg)) {
    return (ERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(beginLine)), 0);
  }

  ATabort("Area has no BeginLine: %t\n", arg);
  return (ERR_Area)NULL;
}

/**
 * Set the begin-column of a ERR_Area. The precondition being that this ERR_Area actually has a begin-column
 * \param[in] arg input ERR_Area
 * \param[in] beginColumn new int to set in #arg
 * \return A new ERR_Area with beginColumn at the right place, or a core dump if #arg did not have a beginColumn
 */
ERR_Area ERR_setAreaBeginColumn(ERR_Area arg, int beginColumn) {
  if (ERR_isAreaArea(arg)) {
    return (ERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(beginColumn)), 1);
  }

  ATabort("Area has no BeginColumn: %t\n", arg);
  return (ERR_Area)NULL;
}

/**
 * Set the end-line of a ERR_Area. The precondition being that this ERR_Area actually has a end-line
 * \param[in] arg input ERR_Area
 * \param[in] endLine new int to set in #arg
 * \return A new ERR_Area with endLine at the right place, or a core dump if #arg did not have a endLine
 */
ERR_Area ERR_setAreaEndLine(ERR_Area arg, int endLine) {
  if (ERR_isAreaArea(arg)) {
    return (ERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endLine)), 2);
  }

  ATabort("Area has no EndLine: %t\n", arg);
  return (ERR_Area)NULL;
}

/**
 * Set the end-column of a ERR_Area. The precondition being that this ERR_Area actually has a end-column
 * \param[in] arg input ERR_Area
 * \param[in] endColumn new int to set in #arg
 * \return A new ERR_Area with endColumn at the right place, or a core dump if #arg did not have a endColumn
 */
ERR_Area ERR_setAreaEndColumn(ERR_Area arg, int endColumn) {
  if (ERR_isAreaArea(arg)) {
    return (ERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endColumn)), 3);
  }

  ATabort("Area has no EndColumn: %t\n", arg);
  return (ERR_Area)NULL;
}

/**
 * Set the offset of a ERR_Area. The precondition being that this ERR_Area actually has a offset
 * \param[in] arg input ERR_Area
 * \param[in] offset new int to set in #arg
 * \return A new ERR_Area with offset at the right place, or a core dump if #arg did not have a offset
 */
ERR_Area ERR_setAreaOffset(ERR_Area arg, int offset) {
  if (ERR_isAreaArea(arg)) {
    return (ERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(offset)), 4);
  }

  ATabort("Area has no Offset: %t\n", arg);
  return (ERR_Area)NULL;
}

/**
 * Set the length of a ERR_Area. The precondition being that this ERR_Area actually has a length
 * \param[in] arg input ERR_Area
 * \param[in] length new int to set in #arg
 * \return A new ERR_Area with length at the right place, or a core dump if #arg did not have a length
 */
ERR_Area ERR_setAreaLength(ERR_Area arg, int length) {
  if (ERR_isAreaArea(arg)) {
    return (ERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(length)), 5);
  }

  ATabort("Area has no Length: %t\n", arg);
  return (ERR_Area)NULL;
}

/**
 * Assert whether a ERR_Slice is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input ERR_Slice
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool ERR_isValidSlice(ERR_Slice arg) {
  if (ERR_isSliceSlice(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Slice is a slice by checking against the following ATerm pattern: slice(<"id"(str)>,<"areas"("Area-areas")>). Always returns ATtrue
 * \param[in] arg input ERR_Slice
 * \return ATtrue if #arg corresponds to the signature of a slice, or ATfalse otherwise
 */
inline ATbool ERR_isSliceSlice(ERR_Slice arg){
  /* checking for: slice */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == ERR_afun11) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Slice has a id. 
 * \param[in] arg input ERR_Slice
 * \return ATtrue if the ERR_Slice had a id, or ATfalse otherwise
 */
ATbool ERR_hasSliceId(ERR_Slice arg) {
  if (ERR_isSliceSlice(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_Slice has a areas. 
 * \param[in] arg input ERR_Slice
 * \return ATtrue if the ERR_Slice had a areas, or ATfalse otherwise
 */
ATbool ERR_hasSliceAreas(ERR_Slice arg) {
  if (ERR_isSliceSlice(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the id char* of a ERR_Slice. Note that the precondition is that this ERR_Slice actually has a id
 * \param[in] arg input ERR_Slice
 * \return the id of #arg, if it exist or an undefined value if it does not
 */
char* ERR_getSliceId(ERR_Slice arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the areas ERR_AreaAreas of a ERR_Slice. Note that the precondition is that this ERR_Slice actually has a areas
 * \param[in] arg input ERR_Slice
 * \return the areas of #arg, if it exist or an undefined value if it does not
 */
ERR_AreaAreas ERR_getSliceAreas(ERR_Slice arg) {
  
    return (ERR_AreaAreas)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Set the id of a ERR_Slice. The precondition being that this ERR_Slice actually has a id
 * \param[in] arg input ERR_Slice
 * \param[in] id new const char* to set in #arg
 * \return A new ERR_Slice with id at the right place, or a core dump if #arg did not have a id
 */
ERR_Slice ERR_setSliceId(ERR_Slice arg, const char* id) {
  if (ERR_isSliceSlice(arg)) {
    return (ERR_Slice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue))), 0);
  }

  ATabort("Slice has no Id: %t\n", arg);
  return (ERR_Slice)NULL;
}

/**
 * Set the areas of a ERR_Slice. The precondition being that this ERR_Slice actually has a areas
 * \param[in] arg input ERR_Slice
 * \param[in] areas new ERR_AreaAreas to set in #arg
 * \return A new ERR_Slice with areas at the right place, or a core dump if #arg did not have a areas
 */
ERR_Slice ERR_setSliceAreas(ERR_Slice arg, ERR_AreaAreas areas) {
  if (ERR_isSliceSlice(arg)) {
    return (ERR_Slice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) areas), 1);
  }

  ATabort("Slice has no Areas: %t\n", arg);
  return (ERR_Slice)NULL;
}

/**
 * Assert whether a ERR_AreaAreas is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input ERR_AreaAreas
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool ERR_isValidAreaAreas(ERR_AreaAreas arg) {
  if (ERR_isAreaAreasEmpty(arg)) {
    return ATtrue;
  }
  else if (ERR_isAreaAreasSingle(arg)) {
    return ATtrue;
  }
  else if (ERR_isAreaAreasMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_AreaAreas is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the ERR_AreaAreas
 * \param[in] arg input ERR_AreaAreas
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool ERR_isAreaAreasEmpty(ERR_AreaAreas arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_AreaAreas is a single by checking against the following ATerm pattern: [<head(Area)>]. May not be used to assert correctness of the ERR_AreaAreas
 * \param[in] arg input ERR_AreaAreas
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool ERR_isAreaAreasSingle(ERR_AreaAreas arg){
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
 * Assert whether a ERR_AreaAreas is a many by checking against the following ATerm pattern: [<head(Area)>,<[tail(Area-areas)]>]. May not be used to assert correctness of the ERR_AreaAreas
 * \param[in] arg input ERR_AreaAreas
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool ERR_isAreaAreasMany(ERR_AreaAreas arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_AreaAreas has a head. 
 * \param[in] arg input ERR_AreaAreas
 * \return ATtrue if the ERR_AreaAreas had a head, or ATfalse otherwise
 */
ATbool ERR_hasAreaAreasHead(ERR_AreaAreas arg) {
  if (ERR_isAreaAreasSingle(arg)) {
    return ATtrue;
  }
  else if (ERR_isAreaAreasMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a ERR_AreaAreas has a tail. 
 * \param[in] arg input ERR_AreaAreas
 * \return ATtrue if the ERR_AreaAreas had a tail, or ATfalse otherwise
 */
ATbool ERR_hasAreaAreasTail(ERR_AreaAreas arg) {
  if (ERR_isAreaAreasMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head ERR_Area of a ERR_AreaAreas. Note that the precondition is that this ERR_AreaAreas actually has a head
 * \param[in] arg input ERR_AreaAreas
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
ERR_Area ERR_getAreaAreasHead(ERR_AreaAreas arg) {
  if (ERR_isAreaAreasSingle(arg)) {
    return (ERR_Area)ATgetFirst((ATermList)arg);
  }
  else 
    return (ERR_Area)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail ERR_AreaAreas of a ERR_AreaAreas. Note that the precondition is that this ERR_AreaAreas actually has a tail
 * \param[in] arg input ERR_AreaAreas
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
ERR_AreaAreas ERR_getAreaAreasTail(ERR_AreaAreas arg) {
  
    return (ERR_AreaAreas)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a ERR_AreaAreas. The precondition being that this ERR_AreaAreas actually has a head
 * \param[in] arg input ERR_AreaAreas
 * \param[in] head new ERR_Area to set in #arg
 * \return A new ERR_AreaAreas with head at the right place, or a core dump if #arg did not have a head
 */
ERR_AreaAreas ERR_setAreaAreasHead(ERR_AreaAreas arg, ERR_Area head) {
  if (ERR_isAreaAreasSingle(arg)) {
    return (ERR_AreaAreas)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (ERR_isAreaAreasMany(arg)) {
    return (ERR_AreaAreas)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("AreaAreas has no Head: %t\n", arg);
  return (ERR_AreaAreas)NULL;
}

/**
 * Set the tail of a ERR_AreaAreas. The precondition being that this ERR_AreaAreas actually has a tail
 * \param[in] arg input ERR_AreaAreas
 * \param[in] tail new ERR_AreaAreas to set in #arg
 * \return A new ERR_AreaAreas with tail at the right place, or a core dump if #arg did not have a tail
 */
ERR_AreaAreas ERR_setAreaAreasTail(ERR_AreaAreas arg, ERR_AreaAreas tail) {
  if (ERR_isAreaAreasMany(arg)) {
    return (ERR_AreaAreas)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("AreaAreas has no Tail: %t\n", arg);
  return (ERR_AreaAreas)NULL;
}

/**
 * Apply functions to the children of a ERR_StrChar. 
 * \return A new ERR_StrChar with new children where the argument functions might have applied
 */
ERR_StrChar ERR_visitStrChar(ERR_StrChar arg, char* (*acceptString)(char*)) {
  if (ERR_isStrCharStrChar(arg)) {
    return ERR_makeStrCharStrChar(
        acceptString ? acceptString(ERR_getStrCharString(arg)) : ERR_getStrCharString(arg));
  }
  ATabort("not a StrChar: %t\n", arg);
  return (ERR_StrChar)NULL;
}
/**
 * Apply functions to the children of a ERR_StrCon. 
 * \return A new ERR_StrCon with new children where the argument functions might have applied
 */
ERR_StrCon ERR_visitStrCon(ERR_StrCon arg, char* (*acceptString)(char*)) {
  if (ERR_isStrConStrCon(arg)) {
    return ERR_makeStrConStrCon(
        acceptString ? acceptString(ERR_getStrConString(arg)) : ERR_getStrConString(arg));
  }
  ATabort("not a StrCon: %t\n", arg);
  return (ERR_StrCon)NULL;
}
/**
 * Apply functions to the children of a ERR_NatCon. 
 * \return A new ERR_NatCon with new children where the argument functions might have applied
 */
ERR_NatCon ERR_visitNatCon(ERR_NatCon arg, char* (*acceptString)(char*)) {
  if (ERR_isNatConNatCon(arg)) {
    return ERR_makeNatConNatCon(
        acceptString ? acceptString(ERR_getNatConString(arg)) : ERR_getNatConString(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (ERR_NatCon)NULL;
}
/**
 * Apply functions to the children of a ERR_Subject. 
 * \return A new ERR_Subject with new children where the argument functions might have applied
 */
ERR_Subject ERR_visitSubject(ERR_Subject arg, char* (*acceptDescription)(char*), ERR_Location (*acceptLocation)(ERR_Location)) {
  if (ERR_isSubjectSubject(arg)) {
    return ERR_makeSubjectSubject(
        acceptDescription ? acceptDescription(ERR_getSubjectDescription(arg)) : ERR_getSubjectDescription(arg));
  }
  if (ERR_isSubjectLocalized(arg)) {
    return ERR_makeSubjectLocalized(
        acceptDescription ? acceptDescription(ERR_getSubjectDescription(arg)) : ERR_getSubjectDescription(arg),
        acceptLocation ? acceptLocation(ERR_getSubjectLocation(arg)) : ERR_getSubjectLocation(arg));
  }
  ATabort("not a Subject: %t\n", arg);
  return (ERR_Subject)NULL;
}
/**
 * Apply functions to the children of a ERR_Error. 
 * \return A new ERR_Error with new children where the argument functions might have applied
 */
ERR_Error ERR_visitError(ERR_Error arg, char* (*acceptDescription)(char*), ERR_SubjectList (*acceptList)(ERR_SubjectList)) {
  if (ERR_isErrorInfo(arg)) {
    return ERR_makeErrorInfo(
        acceptDescription ? acceptDescription(ERR_getErrorDescription(arg)) : ERR_getErrorDescription(arg),
        acceptList ? acceptList(ERR_getErrorList(arg)) : ERR_getErrorList(arg));
  }
  if (ERR_isErrorWarning(arg)) {
    return ERR_makeErrorWarning(
        acceptDescription ? acceptDescription(ERR_getErrorDescription(arg)) : ERR_getErrorDescription(arg),
        acceptList ? acceptList(ERR_getErrorList(arg)) : ERR_getErrorList(arg));
  }
  if (ERR_isErrorError(arg)) {
    return ERR_makeErrorError(
        acceptDescription ? acceptDescription(ERR_getErrorDescription(arg)) : ERR_getErrorDescription(arg),
        acceptList ? acceptList(ERR_getErrorList(arg)) : ERR_getErrorList(arg));
  }
  if (ERR_isErrorFatal(arg)) {
    return ERR_makeErrorFatal(
        acceptDescription ? acceptDescription(ERR_getErrorDescription(arg)) : ERR_getErrorDescription(arg),
        acceptList ? acceptList(ERR_getErrorList(arg)) : ERR_getErrorList(arg));
  }
  ATabort("not a Error: %t\n", arg);
  return (ERR_Error)NULL;
}
/**
 * Apply functions to the children of a ERR_Summary. 
 * \return A new ERR_Summary with new children where the argument functions might have applied
 */
ERR_Summary ERR_visitSummary(ERR_Summary arg, char* (*acceptProducer)(char*), char* (*acceptId)(char*), ERR_ErrorList (*acceptList)(ERR_ErrorList)) {
  if (ERR_isSummarySummary(arg)) {
    return ERR_makeSummarySummary(
        acceptProducer ? acceptProducer(ERR_getSummaryProducer(arg)) : ERR_getSummaryProducer(arg),
        acceptId ? acceptId(ERR_getSummaryId(arg)) : ERR_getSummaryId(arg),
        acceptList ? acceptList(ERR_getSummaryList(arg)) : ERR_getSummaryList(arg));
  }
  ATabort("not a Summary: %t\n", arg);
  return (ERR_Summary)NULL;
}
/**
 * Apply functions to the children of a ERR_SubjectList. 
 * \return A new ERR_SubjectList with new children where the argument functions might have applied
 */
ERR_SubjectList ERR_visitSubjectList(ERR_SubjectList arg, ERR_Subject (*acceptHead)(ERR_Subject)) {
  if (ERR_isSubjectListEmpty(arg)) {
    return ERR_makeSubjectListEmpty();
  }
  if (ERR_isSubjectListSingle(arg)) {
    return ERR_makeSubjectListSingle(
        acceptHead ? acceptHead(ERR_getSubjectListHead(arg)) : ERR_getSubjectListHead(arg));
  }
  if (ERR_isSubjectListMany(arg)) {
    return ERR_makeSubjectListMany(
        acceptHead ? acceptHead(ERR_getSubjectListHead(arg)) : ERR_getSubjectListHead(arg),
        ERR_visitSubjectList(ERR_getSubjectListTail(arg), acceptHead));
  }
  ATabort("not a SubjectList: %t\n", arg);
  return (ERR_SubjectList)NULL;
}
/**
 * Apply functions to the children of a ERR_ErrorList. 
 * \return A new ERR_ErrorList with new children where the argument functions might have applied
 */
ERR_ErrorList ERR_visitErrorList(ERR_ErrorList arg, ERR_Error (*acceptHead)(ERR_Error)) {
  if (ERR_isErrorListEmpty(arg)) {
    return ERR_makeErrorListEmpty();
  }
  if (ERR_isErrorListSingle(arg)) {
    return ERR_makeErrorListSingle(
        acceptHead ? acceptHead(ERR_getErrorListHead(arg)) : ERR_getErrorListHead(arg));
  }
  if (ERR_isErrorListMany(arg)) {
    return ERR_makeErrorListMany(
        acceptHead ? acceptHead(ERR_getErrorListHead(arg)) : ERR_getErrorListHead(arg),
        ERR_visitErrorList(ERR_getErrorListTail(arg), acceptHead));
  }
  ATabort("not a ErrorList: %t\n", arg);
  return (ERR_ErrorList)NULL;
}
/**
 * Apply functions to the children of a ERR_Location. 
 * \return A new ERR_Location with new children where the argument functions might have applied
 */
ERR_Location ERR_visitLocation(ERR_Location arg, char* (*acceptFilename)(char*), ERR_Area (*acceptArea)(ERR_Area)) {
  if (ERR_isLocationFile(arg)) {
    return ERR_makeLocationFile(
        acceptFilename ? acceptFilename(ERR_getLocationFilename(arg)) : ERR_getLocationFilename(arg));
  }
  if (ERR_isLocationArea(arg)) {
    return ERR_makeLocationArea(
        acceptArea ? acceptArea(ERR_getLocationArea(arg)) : ERR_getLocationArea(arg));
  }
  if (ERR_isLocationAreaInFile(arg)) {
    return ERR_makeLocationAreaInFile(
        acceptFilename ? acceptFilename(ERR_getLocationFilename(arg)) : ERR_getLocationFilename(arg),
        acceptArea ? acceptArea(ERR_getLocationArea(arg)) : ERR_getLocationArea(arg));
  }
  ATabort("not a Location: %t\n", arg);
  return (ERR_Location)NULL;
}
/**
 * Apply functions to the children of a ERR_Area. 
 * \return A new ERR_Area with new children where the argument functions might have applied
 */
ERR_Area ERR_visitArea(ERR_Area arg, int (*acceptBeginLine)(int), int (*acceptBeginColumn)(int), int (*acceptEndLine)(int), int (*acceptEndColumn)(int), int (*acceptOffset)(int), int (*acceptLength)(int)) {
  if (ERR_isAreaArea(arg)) {
    return ERR_makeAreaArea(
        acceptBeginLine ? acceptBeginLine(ERR_getAreaBeginLine(arg)) : ERR_getAreaBeginLine(arg),
        acceptBeginColumn ? acceptBeginColumn(ERR_getAreaBeginColumn(arg)) : ERR_getAreaBeginColumn(arg),
        acceptEndLine ? acceptEndLine(ERR_getAreaEndLine(arg)) : ERR_getAreaEndLine(arg),
        acceptEndColumn ? acceptEndColumn(ERR_getAreaEndColumn(arg)) : ERR_getAreaEndColumn(arg),
        acceptOffset ? acceptOffset(ERR_getAreaOffset(arg)) : ERR_getAreaOffset(arg),
        acceptLength ? acceptLength(ERR_getAreaLength(arg)) : ERR_getAreaLength(arg));
  }
  ATabort("not a Area: %t\n", arg);
  return (ERR_Area)NULL;
}
/**
 * Apply functions to the children of a ERR_Slice. 
 * \return A new ERR_Slice with new children where the argument functions might have applied
 */
ERR_Slice ERR_visitSlice(ERR_Slice arg, char* (*acceptId)(char*), ERR_AreaAreas (*acceptAreas)(ERR_AreaAreas)) {
  if (ERR_isSliceSlice(arg)) {
    return ERR_makeSliceSlice(
        acceptId ? acceptId(ERR_getSliceId(arg)) : ERR_getSliceId(arg),
        acceptAreas ? acceptAreas(ERR_getSliceAreas(arg)) : ERR_getSliceAreas(arg));
  }
  ATabort("not a Slice: %t\n", arg);
  return (ERR_Slice)NULL;
}
/**
 * Apply functions to the children of a ERR_AreaAreas. 
 * \return A new ERR_AreaAreas with new children where the argument functions might have applied
 */
ERR_AreaAreas ERR_visitAreaAreas(ERR_AreaAreas arg, ERR_Area (*acceptHead)(ERR_Area)) {
  if (ERR_isAreaAreasEmpty(arg)) {
    return ERR_makeAreaAreasEmpty();
  }
  if (ERR_isAreaAreasSingle(arg)) {
    return ERR_makeAreaAreasSingle(
        acceptHead ? acceptHead(ERR_getAreaAreasHead(arg)) : ERR_getAreaAreasHead(arg));
  }
  if (ERR_isAreaAreasMany(arg)) {
    return ERR_makeAreaAreasMany(
        acceptHead ? acceptHead(ERR_getAreaAreasHead(arg)) : ERR_getAreaAreasHead(arg),
        ERR_visitAreaAreas(ERR_getAreaAreasTail(arg), acceptHead));
  }
  ATabort("not a AreaAreas: %t\n", arg);
  return (ERR_AreaAreas)NULL;
}

