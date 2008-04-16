#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Location.h"

/**
 * Converts a string to an ATermList of integers (ASCII values). 
 * \param[in] str An ASCII string
 * \return An ATermList containing the ASCII values of #arg as ATermInts
 */
ATerm LOC_stringToChars(const char *str) {
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
ATerm LOC_byteToChar(char ch) {
    return (ATerm) ATmakeInt(ch);
}

/**
 * Converts a list of integers (ASCII values) to a C string. 
 * \param[in] arg An ATermList with ATermInts, such as [32,32,10]
 * \return String containing the characters from #arg as characters
 */
char *LOC_charsToString(ATerm arg) {
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

char LOC_charToByte(ATerm arg) {
    return (char) ATgetInt((ATermInt) arg);
}


typedef struct ATerm _LOC_StrChar;
typedef struct ATerm _LOC_StrCon;
typedef struct ATerm _LOC_NatCon;
typedef struct ATerm _LOC_Location;
typedef struct ATerm _LOC_Area;
typedef struct ATerm _LOC_Slice;
typedef struct ATerm _LOC_AreaAreas;


/**
 * Initializes the full API. Forgetting to call this function before using the API will lead to strange behaviour. ATinit() needs to be called before this function.
 */
void _LOC_initLocationApi(void) {
  init_Location_dict();

}

/**
 * Protect a LOC_StrChar from the ATerm garbage collector. Every LOC_StrChar that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a LOC_StrChar
 */
void _LOC_protectStrChar(LOC_StrChar *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a LOC_StrChar from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a LOC_StrChar
 */
void _LOC_unprotectStrChar(LOC_StrChar *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a LOC_StrCon from the ATerm garbage collector. Every LOC_StrCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a LOC_StrCon
 */
void _LOC_protectStrCon(LOC_StrCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a LOC_StrCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a LOC_StrCon
 */
void _LOC_unprotectStrCon(LOC_StrCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a LOC_NatCon from the ATerm garbage collector. Every LOC_NatCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a LOC_NatCon
 */
void _LOC_protectNatCon(LOC_NatCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a LOC_NatCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a LOC_NatCon
 */
void _LOC_unprotectNatCon(LOC_NatCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a LOC_Location from the ATerm garbage collector. Every LOC_Location that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a LOC_Location
 */
void _LOC_protectLocation(LOC_Location *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a LOC_Location from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a LOC_Location
 */
void _LOC_unprotectLocation(LOC_Location *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a LOC_Area from the ATerm garbage collector. Every LOC_Area that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a LOC_Area
 */
void _LOC_protectArea(LOC_Area *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a LOC_Area from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a LOC_Area
 */
void _LOC_unprotectArea(LOC_Area *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a LOC_Slice from the ATerm garbage collector. Every LOC_Slice that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a LOC_Slice
 */
void _LOC_protectSlice(LOC_Slice *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a LOC_Slice from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a LOC_Slice
 */
void _LOC_unprotectSlice(LOC_Slice *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a LOC_AreaAreas from the ATerm garbage collector. Every LOC_AreaAreas that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a LOC_AreaAreas
 */
void _LOC_protectAreaAreas(LOC_AreaAreas *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a LOC_AreaAreas from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a LOC_AreaAreas
 */
void _LOC_unprotectAreaAreas(LOC_AreaAreas *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Transforms an ATerm to a LOC_StrChar. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return LOC_StrChar that was encoded by \arg
 */
LOC_StrChar _LOC_StrCharFromTerm(ATerm t) {
  return (((union {LOC_StrChar target; ATerm source; })(t)).target);
}

/**
 * Transforms a LOC_StrCharto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg LOC_StrChar to be converted
 * \return ATerm that represents the LOC_StrChar
 */
ATerm _LOC_StrCharToTerm(LOC_StrChar arg) {
  return (((union {LOC_StrChar source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a LOC_StrCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return LOC_StrCon that was encoded by \arg
 */
LOC_StrCon _LOC_StrConFromTerm(ATerm t) {
  return (((union {LOC_StrCon target; ATerm source; })(t)).target);
}

/**
 * Transforms a LOC_StrConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg LOC_StrCon to be converted
 * \return ATerm that represents the LOC_StrCon
 */
ATerm _LOC_StrConToTerm(LOC_StrCon arg) {
  return (((union {LOC_StrCon source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a LOC_NatCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return LOC_NatCon that was encoded by \arg
 */
LOC_NatCon _LOC_NatConFromTerm(ATerm t) {
  return (((union {LOC_NatCon target; ATerm source; })(t)).target);
}

/**
 * Transforms a LOC_NatConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg LOC_NatCon to be converted
 * \return ATerm that represents the LOC_NatCon
 */
ATerm _LOC_NatConToTerm(LOC_NatCon arg) {
  return (((union {LOC_NatCon source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a LOC_Location. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return LOC_Location that was encoded by \arg
 */
LOC_Location _LOC_LocationFromTerm(ATerm t) {
  return (((union {LOC_Location target; ATerm source; })(t)).target);
}

/**
 * Transforms a LOC_Locationto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg LOC_Location to be converted
 * \return ATerm that represents the LOC_Location
 */
ATerm _LOC_LocationToTerm(LOC_Location arg) {
  return (((union {LOC_Location source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a LOC_Area. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return LOC_Area that was encoded by \arg
 */
LOC_Area _LOC_AreaFromTerm(ATerm t) {
  return (((union {LOC_Area target; ATerm source; })(t)).target);
}

/**
 * Transforms a LOC_Areato an ATerm. This is just a wrapper for a cast.
 * \param[in] arg LOC_Area to be converted
 * \return ATerm that represents the LOC_Area
 */
ATerm _LOC_AreaToTerm(LOC_Area arg) {
  return (((union {LOC_Area source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a LOC_Slice. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return LOC_Slice that was encoded by \arg
 */
LOC_Slice _LOC_SliceFromTerm(ATerm t) {
  return (((union {LOC_Slice target; ATerm source; })(t)).target);
}

/**
 * Transforms a LOC_Sliceto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg LOC_Slice to be converted
 * \return ATerm that represents the LOC_Slice
 */
ATerm _LOC_SliceToTerm(LOC_Slice arg) {
  return (((union {LOC_Slice source; ATerm target; })(arg)).target);
}

/**
 * Transforms an ATerm to a LOC_AreaAreas. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return LOC_AreaAreas that was encoded by \arg
 */
LOC_AreaAreas _LOC_AreaAreasFromTerm(ATerm t) {
  return (((union {LOC_AreaAreas target; ATerm source; })(t)).target);
}

/**
 * Transforms a LOC_AreaAreasto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg LOC_AreaAreas to be converted
 * \return ATerm that represents the LOC_AreaAreas
 */
ATerm _LOC_AreaAreasToTerm(LOC_AreaAreas arg) {
  return (((union {LOC_AreaAreas source; ATerm target; })(arg)).target);
}

/**
 * Retrieve the length of a LOC_AreaAreas. 
 * \param[in] arg input LOC_AreaAreas
 * \return The number of elements in the LOC_AreaAreas
 */
int _LOC_getAreaAreasLength(LOC_AreaAreas arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a LOC_AreaAreas. 
 * \param[in] arg LOC_AreaAreas to be reversed
 * \return a reversed #arg
 */
LOC_AreaAreas _LOC_reverseAreaAreas(LOC_AreaAreas arg) {
  return (LOC_AreaAreas) ATreverse((ATermList) arg);
}

/**
 * Append a LOC_Area to the end of a LOC_AreaAreas. 
 * \param[in] arg LOC_AreaAreas to append the LOC_Area to
 * \param[in] elem LOC_Area to be appended
 * \return new LOC_AreaAreas with #elem appended
 */
LOC_AreaAreas _LOC_appendAreaAreas(LOC_AreaAreas arg, LOC_Area elem) {
  return (LOC_AreaAreas) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two LOC_AreaAreass. 
 * \param[in] arg0 first LOC_AreaAreas
 * \param[in] arg1 second LOC_AreaAreas
 * \return LOC_AreaAreas with the elements of #arg0 before the elements of #arg1
 */
LOC_AreaAreas _LOC_concatAreaAreas(LOC_AreaAreas arg0, LOC_AreaAreas arg1) {
  return (LOC_AreaAreas) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a LOC_AreaAreas. 
 * \param[in] arg LOC_AreaAreas to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new LOC_AreaAreas with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
LOC_AreaAreas _LOC_sliceAreaAreas(LOC_AreaAreas arg, int start, int end) {
  return (LOC_AreaAreas) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the LOC_Area at #index from a LOC_AreaAreas. 
 * \param[in] arg LOC_AreaAreas to retrieve the LOC_Area from
 * \param[in] index index to use to point in the LOC_AreaAreas
 * \return LOC_Area at position #index in #arg
 */
LOC_Area _LOC_getAreaAreasAreaAt(LOC_AreaAreas arg, int index) {
 return (LOC_Area)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the LOC_Area at #index from a LOC_AreaAreas by a new one. 
 * \param[in] arg LOC_AreaAreas to retrieve the LOC_Area from
 * \param[in] elem new LOC_Area to replace another
 * \param[in] index index to use to point in the LOC_AreaAreas
 * \return A new LOC_AreaAreaswith #elem replaced in #arg at position #index
 */
LOC_AreaAreas _LOC_replaceAreaAreasAreaAt(LOC_AreaAreas arg, LOC_Area elem, int index) {
 return (LOC_AreaAreas) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a LOC_AreaAreas of 2 consecutive elements. 
 * \param[in] elem1 One LOC_Area element of the new LOC_AreaAreas
 * \param[in] elem2 One LOC_Area element of the new LOC_AreaAreas
 * \return A new LOC_AreaAreas consisting of 2 LOC_Areas
 */
LOC_AreaAreas _LOC_makeAreaAreas2(LOC_Area elem1, LOC_Area elem2) {
  return (LOC_AreaAreas) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a LOC_AreaAreas of 3 consecutive elements. 
 * \param[in] elem1 One LOC_Area element of the new LOC_AreaAreas
 * \param[in] elem2 One LOC_Area element of the new LOC_AreaAreas
 * \param[in] elem3 One LOC_Area element of the new LOC_AreaAreas
 * \return A new LOC_AreaAreas consisting of 3 LOC_Areas
 */
LOC_AreaAreas _LOC_makeAreaAreas3(LOC_Area elem1, LOC_Area elem2, LOC_Area elem3) {
  return (LOC_AreaAreas) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a LOC_AreaAreas of 4 consecutive elements. 
 * \param[in] elem1 One LOC_Area element of the new LOC_AreaAreas
 * \param[in] elem2 One LOC_Area element of the new LOC_AreaAreas
 * \param[in] elem3 One LOC_Area element of the new LOC_AreaAreas
 * \param[in] elem4 One LOC_Area element of the new LOC_AreaAreas
 * \return A new LOC_AreaAreas consisting of 4 LOC_Areas
 */
LOC_AreaAreas _LOC_makeAreaAreas4(LOC_Area elem1, LOC_Area elem2, LOC_Area elem3, LOC_Area elem4) {
  return (LOC_AreaAreas) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a LOC_AreaAreas of 5 consecutive elements. 
 * \param[in] elem1 One LOC_Area element of the new LOC_AreaAreas
 * \param[in] elem2 One LOC_Area element of the new LOC_AreaAreas
 * \param[in] elem3 One LOC_Area element of the new LOC_AreaAreas
 * \param[in] elem4 One LOC_Area element of the new LOC_AreaAreas
 * \param[in] elem5 One LOC_Area element of the new LOC_AreaAreas
 * \return A new LOC_AreaAreas consisting of 5 LOC_Areas
 */
LOC_AreaAreas _LOC_makeAreaAreas5(LOC_Area elem1, LOC_Area elem2, LOC_Area elem3, LOC_Area elem4, LOC_Area elem5) {
  return (LOC_AreaAreas) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a LOC_AreaAreas of 6 consecutive elements. 
 * \param[in] elem1 One LOC_Area element of the new LOC_AreaAreas
 * \param[in] elem2 One LOC_Area element of the new LOC_AreaAreas
 * \param[in] elem3 One LOC_Area element of the new LOC_AreaAreas
 * \param[in] elem4 One LOC_Area element of the new LOC_AreaAreas
 * \param[in] elem5 One LOC_Area element of the new LOC_AreaAreas
 * \param[in] elem6 One LOC_Area element of the new LOC_AreaAreas
 * \return A new LOC_AreaAreas consisting of 6 LOC_Areas
 */
LOC_AreaAreas _LOC_makeAreaAreas6(LOC_Area elem1, LOC_Area elem2, LOC_Area elem3, LOC_Area elem4, LOC_Area elem5, LOC_Area elem6) {
  return (LOC_AreaAreas) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Constructs a StrChar of type LOC_StrChar. Like all ATerm types, LOC_StrChars are maximally shared.
 * \param[in] string a child of the new StrChar
 * \return A pointer to a StrChar, either newly constructed or shared
 */
LOC_StrChar LOC_makeStrCharStrChar(const char* string) {
  return (LOC_StrChar)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}
/**
 * Constructs a StrCon of type LOC_StrCon. Like all ATerm types, LOC_StrCons are maximally shared.
 * \param[in] string a child of the new StrCon
 * \return A pointer to a StrCon, either newly constructed or shared
 */
LOC_StrCon LOC_makeStrConStrCon(const char* string) {
  return (LOC_StrCon)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}
/**
 * Constructs a NatCon of type LOC_NatCon. Like all ATerm types, LOC_NatCons are maximally shared.
 * \param[in] string a child of the new NatCon
 * \return A pointer to a NatCon, either newly constructed or shared
 */
LOC_NatCon LOC_makeNatConNatCon(const char* string) {
  return (LOC_NatCon)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}
/**
 * Constructs a file of type LOC_Location. Like all ATerm types, LOC_Locations are maximally shared.
 * \param[in] filename a child of the new file
 * \return A pointer to a file, either newly constructed or shared
 */
LOC_Location LOC_makeLocationFile(const char* filename) {
  return (LOC_Location)(ATerm)ATmakeAppl1(LOC_afun0, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue)));
}
/**
 * Constructs a area of type LOC_Location. Like all ATerm types, LOC_Locations are maximally shared.
 * \param[in] Area a child of the new area
 * \return A pointer to a area, either newly constructed or shared
 */
LOC_Location LOC_makeLocationArea(LOC_Area Area) {
  return (LOC_Location)(ATerm)ATmakeAppl1(LOC_afun1, (ATerm) Area);
}
/**
 * Constructs a area-in-file of type LOC_Location. Like all ATerm types, LOC_Locations are maximally shared.
 * \param[in] filename a child of the new area-in-file
 * \param[in] Area a child of the new area-in-file
 * \return A pointer to a area-in-file, either newly constructed or shared
 */
LOC_Location LOC_makeLocationAreaInFile(const char* filename, LOC_Area Area) {
  return (LOC_Location)(ATerm)ATmakeAppl2(LOC_afun2, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue)), (ATerm) Area);
}
/**
 * Constructs a area of type LOC_Area. Like all ATerm types, LOC_Areas are maximally shared.
 * \param[in] beginLine a child of the new area
 * \param[in] beginColumn a child of the new area
 * \param[in] endLine a child of the new area
 * \param[in] endColumn a child of the new area
 * \param[in] offset a child of the new area
 * \param[in] length a child of the new area
 * \return A pointer to a area, either newly constructed or shared
 */
LOC_Area LOC_makeAreaArea(int beginLine, int beginColumn, int endLine, int endColumn, int offset, int length) {
  return (LOC_Area)(ATerm)ATmakeAppl6(LOC_afun3, (ATerm) (ATerm) ATmakeInt(beginLine), (ATerm) (ATerm) ATmakeInt(beginColumn), (ATerm) (ATerm) ATmakeInt(endLine), (ATerm) (ATerm) ATmakeInt(endColumn), (ATerm) (ATerm) ATmakeInt(offset), (ATerm) (ATerm) ATmakeInt(length));
}
/**
 * Constructs a slice of type LOC_Slice. Like all ATerm types, LOC_Slices are maximally shared.
 * \param[in] id a child of the new slice
 * \param[in] areas a child of the new slice
 * \return A pointer to a slice, either newly constructed or shared
 */
LOC_Slice LOC_makeSliceSlice(const char* id, LOC_AreaAreas areas) {
  return (LOC_Slice)(ATerm)ATmakeAppl2(LOC_afun4, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)), (ATerm) areas);
}
/**
 * Constructs a empty of type LOC_AreaAreas. Like all ATerm types, LOC_AreaAreass are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
LOC_AreaAreas LOC_makeAreaAreasEmpty(void) {
  return (LOC_AreaAreas)(ATerm)ATempty;
}
/**
 * Constructs a single of type LOC_AreaAreas. Like all ATerm types, LOC_AreaAreass are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
LOC_AreaAreas LOC_makeAreaAreasSingle(LOC_Area head) {
  return (LOC_AreaAreas)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type LOC_AreaAreas. Like all ATerm types, LOC_AreaAreass are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
LOC_AreaAreas LOC_makeAreaAreasMany(LOC_Area head, LOC_AreaAreas tail) {
  return (LOC_AreaAreas)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/**
 * Tests equality of two LOC_StrChars. A constant time operation.
 * \param[in] arg0 first LOC_StrChar to be compared
 * \param[in] arg1 second LOC_StrChar to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _LOC_isEqualStrChar(LOC_StrChar arg0, LOC_StrChar arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two LOC_StrCons. A constant time operation.
 * \param[in] arg0 first LOC_StrCon to be compared
 * \param[in] arg1 second LOC_StrCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _LOC_isEqualStrCon(LOC_StrCon arg0, LOC_StrCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two LOC_NatCons. A constant time operation.
 * \param[in] arg0 first LOC_NatCon to be compared
 * \param[in] arg1 second LOC_NatCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _LOC_isEqualNatCon(LOC_NatCon arg0, LOC_NatCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two LOC_Locations. A constant time operation.
 * \param[in] arg0 first LOC_Location to be compared
 * \param[in] arg1 second LOC_Location to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _LOC_isEqualLocation(LOC_Location arg0, LOC_Location arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two LOC_Areas. A constant time operation.
 * \param[in] arg0 first LOC_Area to be compared
 * \param[in] arg1 second LOC_Area to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _LOC_isEqualArea(LOC_Area arg0, LOC_Area arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two LOC_Slices. A constant time operation.
 * \param[in] arg0 first LOC_Slice to be compared
 * \param[in] arg1 second LOC_Slice to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _LOC_isEqualSlice(LOC_Slice arg0, LOC_Slice arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two LOC_AreaAreass. A constant time operation.
 * \param[in] arg0 first LOC_AreaAreas to be compared
 * \param[in] arg1 second LOC_AreaAreas to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _LOC_isEqualAreaAreas(LOC_AreaAreas arg0, LOC_AreaAreas arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Assert whether a LOC_StrChar is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input LOC_StrChar
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool LOC_isValidStrChar(LOC_StrChar arg) {
  if (LOC_isStrCharStrChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_StrChar is a StrChar by checking against the following ATerm pattern: <string(str)>. Always returns ATtrue
 * \param[in] arg input LOC_StrChar
 * \return ATtrue if #arg corresponds to the signature of a StrChar, or ATfalse otherwise
 */
inline ATbool LOC_isStrCharStrChar(LOC_StrChar arg){
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg)) == ATtrue) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_StrChar has a string. 
 * \param[in] arg input LOC_StrChar
 * \return ATtrue if the LOC_StrChar had a string, or ATfalse otherwise
 */
ATbool LOC_hasStrCharString(LOC_StrChar arg) {
  if (LOC_isStrCharStrChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the string char* of a LOC_StrChar. Note that the precondition is that this LOC_StrChar actually has a string
 * \param[in] arg input LOC_StrChar
 * \return the string of #arg, if it exist or an undefined value if it does not
 */
char* LOC_getStrCharString(LOC_StrChar arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/**
 * Set the string of a LOC_StrChar. The precondition being that this LOC_StrChar actually has a string
 * \param[in] arg input LOC_StrChar
 * \param[in] string new const char* to set in #arg
 * \return A new LOC_StrChar with string at the right place, or a core dump if #arg did not have a string
 */
LOC_StrChar LOC_setStrCharString(LOC_StrChar arg, const char* string) {
  if (LOC_isStrCharStrChar(arg)) {
    return (LOC_StrChar)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("StrChar has no String: %t\n", arg);
  return (LOC_StrChar)NULL;
}

/**
 * Assert whether a LOC_StrCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input LOC_StrCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool LOC_isValidStrCon(LOC_StrCon arg) {
  if (LOC_isStrConStrCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_StrCon is a StrCon by checking against the following ATerm pattern: <string(str)>. Always returns ATtrue
 * \param[in] arg input LOC_StrCon
 * \return ATtrue if #arg corresponds to the signature of a StrCon, or ATfalse otherwise
 */
inline ATbool LOC_isStrConStrCon(LOC_StrCon arg){
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg)) == ATtrue) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_StrCon has a string. 
 * \param[in] arg input LOC_StrCon
 * \return ATtrue if the LOC_StrCon had a string, or ATfalse otherwise
 */
ATbool LOC_hasStrConString(LOC_StrCon arg) {
  if (LOC_isStrConStrCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the string char* of a LOC_StrCon. Note that the precondition is that this LOC_StrCon actually has a string
 * \param[in] arg input LOC_StrCon
 * \return the string of #arg, if it exist or an undefined value if it does not
 */
char* LOC_getStrConString(LOC_StrCon arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/**
 * Set the string of a LOC_StrCon. The precondition being that this LOC_StrCon actually has a string
 * \param[in] arg input LOC_StrCon
 * \param[in] string new const char* to set in #arg
 * \return A new LOC_StrCon with string at the right place, or a core dump if #arg did not have a string
 */
LOC_StrCon LOC_setStrConString(LOC_StrCon arg, const char* string) {
  if (LOC_isStrConStrCon(arg)) {
    return (LOC_StrCon)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("StrCon has no String: %t\n", arg);
  return (LOC_StrCon)NULL;
}

/**
 * Assert whether a LOC_NatCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input LOC_NatCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool LOC_isValidNatCon(LOC_NatCon arg) {
  if (LOC_isNatConNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_NatCon is a NatCon by checking against the following ATerm pattern: <string(str)>. Always returns ATtrue
 * \param[in] arg input LOC_NatCon
 * \return ATtrue if #arg corresponds to the signature of a NatCon, or ATfalse otherwise
 */
inline ATbool LOC_isNatConNatCon(LOC_NatCon arg){
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg)) == ATtrue) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_NatCon has a string. 
 * \param[in] arg input LOC_NatCon
 * \return ATtrue if the LOC_NatCon had a string, or ATfalse otherwise
 */
ATbool LOC_hasNatConString(LOC_NatCon arg) {
  if (LOC_isNatConNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the string char* of a LOC_NatCon. Note that the precondition is that this LOC_NatCon actually has a string
 * \param[in] arg input LOC_NatCon
 * \return the string of #arg, if it exist or an undefined value if it does not
 */
char* LOC_getNatConString(LOC_NatCon arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/**
 * Set the string of a LOC_NatCon. The precondition being that this LOC_NatCon actually has a string
 * \param[in] arg input LOC_NatCon
 * \param[in] string new const char* to set in #arg
 * \return A new LOC_NatCon with string at the right place, or a core dump if #arg did not have a string
 */
LOC_NatCon LOC_setNatConString(LOC_NatCon arg, const char* string) {
  if (LOC_isNatConNatCon(arg)) {
    return (LOC_NatCon)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("NatCon has no String: %t\n", arg);
  return (LOC_NatCon)NULL;
}

/**
 * Assert whether a LOC_Location is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input LOC_Location
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool LOC_isValidLocation(LOC_Location arg) {
  if (LOC_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (LOC_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (LOC_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_Location is a file by checking against the following ATerm pattern: file(<"filename"(str)>). May not be used to assert correctness of the LOC_Location
 * \param[in] arg input LOC_Location
 * \return ATtrue if #arg corresponds to the signature of a file, or ATfalse otherwise
 */
inline ATbool LOC_isLocationFile(LOC_Location arg){
  /* checking for: file */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == LOC_afun0) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_Location is a area by checking against the following ATerm pattern: area(<"Area"("Area")>). May not be used to assert correctness of the LOC_Location
 * \param[in] arg input LOC_Location
 * \return ATtrue if #arg corresponds to the signature of a area, or ATfalse otherwise
 */
inline ATbool LOC_isLocationArea(LOC_Location arg){
  /* checking for: area */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == LOC_afun1) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_Location is a area-in-file by checking against the following ATerm pattern: area-in-file(<"filename"(str)>,<"Area"("Area")>). May not be used to assert correctness of the LOC_Location
 * \param[in] arg input LOC_Location
 * \return ATtrue if #arg corresponds to the signature of a area-in-file, or ATfalse otherwise
 */
inline ATbool LOC_isLocationAreaInFile(LOC_Location arg){
  /* checking for: area-in-file */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == LOC_afun2) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_Location has a filename. 
 * \param[in] arg input LOC_Location
 * \return ATtrue if the LOC_Location had a filename, or ATfalse otherwise
 */
ATbool LOC_hasLocationFilename(LOC_Location arg) {
  if (LOC_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (LOC_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_Location has a Area. 
 * \param[in] arg input LOC_Location
 * \return ATtrue if the LOC_Location had a Area, or ATfalse otherwise
 */
ATbool LOC_hasLocationArea(LOC_Location arg) {
  if (LOC_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (LOC_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the filename char* of a LOC_Location. Note that the precondition is that this LOC_Location actually has a filename
 * \param[in] arg input LOC_Location
 * \return the filename of #arg, if it exist or an undefined value if it does not
 */
char* LOC_getLocationFilename(LOC_Location arg) {
  if (LOC_isLocationFile(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the Area LOC_Area of a LOC_Location. Note that the precondition is that this LOC_Location actually has a Area
 * \param[in] arg input LOC_Location
 * \return the Area of #arg, if it exist or an undefined value if it does not
 */
LOC_Area LOC_getLocationArea(LOC_Location arg) {
  if (LOC_isLocationArea(arg)) {
    return (LOC_Area)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (LOC_Area)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Set the filename of a LOC_Location. The precondition being that this LOC_Location actually has a filename
 * \param[in] arg input LOC_Location
 * \param[in] filename new const char* to set in #arg
 * \return A new LOC_Location with filename at the right place, or a core dump if #arg did not have a filename
 */
LOC_Location LOC_setLocationFilename(LOC_Location arg, const char* filename) {
  if (LOC_isLocationFile(arg)) {
    return (LOC_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue))), 0);
  }
  else if (LOC_isLocationAreaInFile(arg)) {
    return (LOC_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue))), 0);
  }

  ATabort("Location has no Filename: %t\n", arg);
  return (LOC_Location)NULL;
}

/**
 * Set the Area of a LOC_Location. The precondition being that this LOC_Location actually has a Area
 * \param[in] arg input LOC_Location
 * \param[in] Area new LOC_Area to set in #arg
 * \return A new LOC_Location with Area at the right place, or a core dump if #arg did not have a Area
 */
LOC_Location LOC_setLocationArea(LOC_Location arg, LOC_Area Area) {
  if (LOC_isLocationArea(arg)) {
    return (LOC_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Area), 0);
  }
  else if (LOC_isLocationAreaInFile(arg)) {
    return (LOC_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Area), 1);
  }

  ATabort("Location has no Area: %t\n", arg);
  return (LOC_Location)NULL;
}

/**
 * Assert whether a LOC_Area is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input LOC_Area
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool LOC_isValidArea(LOC_Area arg) {
  if (LOC_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_Area is a area by checking against the following ATerm pattern: area(<"begin-line"(int)>,<"begin-column"(int)>,<"end-line"(int)>,<"end-column"(int)>,<"offset"(int)>,<"length"(int)>). Always returns ATtrue
 * \param[in] arg input LOC_Area
 * \return ATtrue if #arg corresponds to the signature of a area, or ATfalse otherwise
 */
inline ATbool LOC_isAreaArea(LOC_Area arg){
  /* checking for: area */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == LOC_afun3) {
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
 * Assert whether a LOC_Area has a begin-line. 
 * \param[in] arg input LOC_Area
 * \return ATtrue if the LOC_Area had a begin-line, or ATfalse otherwise
 */
ATbool LOC_hasAreaBeginLine(LOC_Area arg) {
  if (LOC_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_Area has a begin-column. 
 * \param[in] arg input LOC_Area
 * \return ATtrue if the LOC_Area had a begin-column, or ATfalse otherwise
 */
ATbool LOC_hasAreaBeginColumn(LOC_Area arg) {
  if (LOC_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_Area has a end-line. 
 * \param[in] arg input LOC_Area
 * \return ATtrue if the LOC_Area had a end-line, or ATfalse otherwise
 */
ATbool LOC_hasAreaEndLine(LOC_Area arg) {
  if (LOC_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_Area has a end-column. 
 * \param[in] arg input LOC_Area
 * \return ATtrue if the LOC_Area had a end-column, or ATfalse otherwise
 */
ATbool LOC_hasAreaEndColumn(LOC_Area arg) {
  if (LOC_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_Area has a offset. 
 * \param[in] arg input LOC_Area
 * \return ATtrue if the LOC_Area had a offset, or ATfalse otherwise
 */
ATbool LOC_hasAreaOffset(LOC_Area arg) {
  if (LOC_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_Area has a length. 
 * \param[in] arg input LOC_Area
 * \return ATtrue if the LOC_Area had a length, or ATfalse otherwise
 */
ATbool LOC_hasAreaLength(LOC_Area arg) {
  if (LOC_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the begin-line int of a LOC_Area. Note that the precondition is that this LOC_Area actually has a begin-line
 * \param[in] arg input LOC_Area
 * \return the begin-line of #arg, if it exist or an undefined value if it does not
 */
int LOC_getAreaBeginLine(LOC_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Get the begin-column int of a LOC_Area. Note that the precondition is that this LOC_Area actually has a begin-column
 * \param[in] arg input LOC_Area
 * \return the begin-column of #arg, if it exist or an undefined value if it does not
 */
int LOC_getAreaBeginColumn(LOC_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the end-line int of a LOC_Area. Note that the precondition is that this LOC_Area actually has a end-line
 * \param[in] arg input LOC_Area
 * \return the end-line of #arg, if it exist or an undefined value if it does not
 */
int LOC_getAreaEndLine(LOC_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/**
 * Get the end-column int of a LOC_Area. Note that the precondition is that this LOC_Area actually has a end-column
 * \param[in] arg input LOC_Area
 * \return the end-column of #arg, if it exist or an undefined value if it does not
 */
int LOC_getAreaEndColumn(LOC_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 3));
}

/**
 * Get the offset int of a LOC_Area. Note that the precondition is that this LOC_Area actually has a offset
 * \param[in] arg input LOC_Area
 * \return the offset of #arg, if it exist or an undefined value if it does not
 */
int LOC_getAreaOffset(LOC_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 4));
}

/**
 * Get the length int of a LOC_Area. Note that the precondition is that this LOC_Area actually has a length
 * \param[in] arg input LOC_Area
 * \return the length of #arg, if it exist or an undefined value if it does not
 */
int LOC_getAreaLength(LOC_Area arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 5));
}

/**
 * Set the begin-line of a LOC_Area. The precondition being that this LOC_Area actually has a begin-line
 * \param[in] arg input LOC_Area
 * \param[in] beginLine new int to set in #arg
 * \return A new LOC_Area with beginLine at the right place, or a core dump if #arg did not have a beginLine
 */
LOC_Area LOC_setAreaBeginLine(LOC_Area arg, int beginLine) {
  if (LOC_isAreaArea(arg)) {
    return (LOC_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(beginLine)), 0);
  }

  ATabort("Area has no BeginLine: %t\n", arg);
  return (LOC_Area)NULL;
}

/**
 * Set the begin-column of a LOC_Area. The precondition being that this LOC_Area actually has a begin-column
 * \param[in] arg input LOC_Area
 * \param[in] beginColumn new int to set in #arg
 * \return A new LOC_Area with beginColumn at the right place, or a core dump if #arg did not have a beginColumn
 */
LOC_Area LOC_setAreaBeginColumn(LOC_Area arg, int beginColumn) {
  if (LOC_isAreaArea(arg)) {
    return (LOC_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(beginColumn)), 1);
  }

  ATabort("Area has no BeginColumn: %t\n", arg);
  return (LOC_Area)NULL;
}

/**
 * Set the end-line of a LOC_Area. The precondition being that this LOC_Area actually has a end-line
 * \param[in] arg input LOC_Area
 * \param[in] endLine new int to set in #arg
 * \return A new LOC_Area with endLine at the right place, or a core dump if #arg did not have a endLine
 */
LOC_Area LOC_setAreaEndLine(LOC_Area arg, int endLine) {
  if (LOC_isAreaArea(arg)) {
    return (LOC_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endLine)), 2);
  }

  ATabort("Area has no EndLine: %t\n", arg);
  return (LOC_Area)NULL;
}

/**
 * Set the end-column of a LOC_Area. The precondition being that this LOC_Area actually has a end-column
 * \param[in] arg input LOC_Area
 * \param[in] endColumn new int to set in #arg
 * \return A new LOC_Area with endColumn at the right place, or a core dump if #arg did not have a endColumn
 */
LOC_Area LOC_setAreaEndColumn(LOC_Area arg, int endColumn) {
  if (LOC_isAreaArea(arg)) {
    return (LOC_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endColumn)), 3);
  }

  ATabort("Area has no EndColumn: %t\n", arg);
  return (LOC_Area)NULL;
}

/**
 * Set the offset of a LOC_Area. The precondition being that this LOC_Area actually has a offset
 * \param[in] arg input LOC_Area
 * \param[in] offset new int to set in #arg
 * \return A new LOC_Area with offset at the right place, or a core dump if #arg did not have a offset
 */
LOC_Area LOC_setAreaOffset(LOC_Area arg, int offset) {
  if (LOC_isAreaArea(arg)) {
    return (LOC_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(offset)), 4);
  }

  ATabort("Area has no Offset: %t\n", arg);
  return (LOC_Area)NULL;
}

/**
 * Set the length of a LOC_Area. The precondition being that this LOC_Area actually has a length
 * \param[in] arg input LOC_Area
 * \param[in] length new int to set in #arg
 * \return A new LOC_Area with length at the right place, or a core dump if #arg did not have a length
 */
LOC_Area LOC_setAreaLength(LOC_Area arg, int length) {
  if (LOC_isAreaArea(arg)) {
    return (LOC_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(length)), 5);
  }

  ATabort("Area has no Length: %t\n", arg);
  return (LOC_Area)NULL;
}

/**
 * Assert whether a LOC_Slice is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input LOC_Slice
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool LOC_isValidSlice(LOC_Slice arg) {
  if (LOC_isSliceSlice(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_Slice is a slice by checking against the following ATerm pattern: slice(<"id"(str)>,<"areas"("Area-areas")>). Always returns ATtrue
 * \param[in] arg input LOC_Slice
 * \return ATtrue if #arg corresponds to the signature of a slice, or ATfalse otherwise
 */
inline ATbool LOC_isSliceSlice(LOC_Slice arg){
  /* checking for: slice */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == LOC_afun4) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_Slice has a id. 
 * \param[in] arg input LOC_Slice
 * \return ATtrue if the LOC_Slice had a id, or ATfalse otherwise
 */
ATbool LOC_hasSliceId(LOC_Slice arg) {
  if (LOC_isSliceSlice(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_Slice has a areas. 
 * \param[in] arg input LOC_Slice
 * \return ATtrue if the LOC_Slice had a areas, or ATfalse otherwise
 */
ATbool LOC_hasSliceAreas(LOC_Slice arg) {
  if (LOC_isSliceSlice(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the id char* of a LOC_Slice. Note that the precondition is that this LOC_Slice actually has a id
 * \param[in] arg input LOC_Slice
 * \return the id of #arg, if it exist or an undefined value if it does not
 */
char* LOC_getSliceId(LOC_Slice arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the areas LOC_AreaAreas of a LOC_Slice. Note that the precondition is that this LOC_Slice actually has a areas
 * \param[in] arg input LOC_Slice
 * \return the areas of #arg, if it exist or an undefined value if it does not
 */
LOC_AreaAreas LOC_getSliceAreas(LOC_Slice arg) {
  
    return (LOC_AreaAreas)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Set the id of a LOC_Slice. The precondition being that this LOC_Slice actually has a id
 * \param[in] arg input LOC_Slice
 * \param[in] id new const char* to set in #arg
 * \return A new LOC_Slice with id at the right place, or a core dump if #arg did not have a id
 */
LOC_Slice LOC_setSliceId(LOC_Slice arg, const char* id) {
  if (LOC_isSliceSlice(arg)) {
    return (LOC_Slice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue))), 0);
  }

  ATabort("Slice has no Id: %t\n", arg);
  return (LOC_Slice)NULL;
}

/**
 * Set the areas of a LOC_Slice. The precondition being that this LOC_Slice actually has a areas
 * \param[in] arg input LOC_Slice
 * \param[in] areas new LOC_AreaAreas to set in #arg
 * \return A new LOC_Slice with areas at the right place, or a core dump if #arg did not have a areas
 */
LOC_Slice LOC_setSliceAreas(LOC_Slice arg, LOC_AreaAreas areas) {
  if (LOC_isSliceSlice(arg)) {
    return (LOC_Slice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) areas), 1);
  }

  ATabort("Slice has no Areas: %t\n", arg);
  return (LOC_Slice)NULL;
}

/**
 * Assert whether a LOC_AreaAreas is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input LOC_AreaAreas
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool LOC_isValidAreaAreas(LOC_AreaAreas arg) {
  if (LOC_isAreaAreasEmpty(arg)) {
    return ATtrue;
  }
  else if (LOC_isAreaAreasSingle(arg)) {
    return ATtrue;
  }
  else if (LOC_isAreaAreasMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_AreaAreas is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the LOC_AreaAreas
 * \param[in] arg input LOC_AreaAreas
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool LOC_isAreaAreasEmpty(LOC_AreaAreas arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_AreaAreas is a single by checking against the following ATerm pattern: [<head(Area)>]. May not be used to assert correctness of the LOC_AreaAreas
 * \param[in] arg input LOC_AreaAreas
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool LOC_isAreaAreasSingle(LOC_AreaAreas arg){
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
 * Assert whether a LOC_AreaAreas is a many by checking against the following ATerm pattern: [<head(Area)>,<[tail(Area-areas)]>]. May not be used to assert correctness of the LOC_AreaAreas
 * \param[in] arg input LOC_AreaAreas
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool LOC_isAreaAreasMany(LOC_AreaAreas arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_AreaAreas has a head. 
 * \param[in] arg input LOC_AreaAreas
 * \return ATtrue if the LOC_AreaAreas had a head, or ATfalse otherwise
 */
ATbool LOC_hasAreaAreasHead(LOC_AreaAreas arg) {
  if (LOC_isAreaAreasSingle(arg)) {
    return ATtrue;
  }
  else if (LOC_isAreaAreasMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a LOC_AreaAreas has a tail. 
 * \param[in] arg input LOC_AreaAreas
 * \return ATtrue if the LOC_AreaAreas had a tail, or ATfalse otherwise
 */
ATbool LOC_hasAreaAreasTail(LOC_AreaAreas arg) {
  if (LOC_isAreaAreasMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head LOC_Area of a LOC_AreaAreas. Note that the precondition is that this LOC_AreaAreas actually has a head
 * \param[in] arg input LOC_AreaAreas
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
LOC_Area LOC_getAreaAreasHead(LOC_AreaAreas arg) {
  if (LOC_isAreaAreasSingle(arg)) {
    return (LOC_Area)ATgetFirst((ATermList)arg);
  }
  else 
    return (LOC_Area)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail LOC_AreaAreas of a LOC_AreaAreas. Note that the precondition is that this LOC_AreaAreas actually has a tail
 * \param[in] arg input LOC_AreaAreas
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
LOC_AreaAreas LOC_getAreaAreasTail(LOC_AreaAreas arg) {
  
    return (LOC_AreaAreas)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a LOC_AreaAreas. The precondition being that this LOC_AreaAreas actually has a head
 * \param[in] arg input LOC_AreaAreas
 * \param[in] head new LOC_Area to set in #arg
 * \return A new LOC_AreaAreas with head at the right place, or a core dump if #arg did not have a head
 */
LOC_AreaAreas LOC_setAreaAreasHead(LOC_AreaAreas arg, LOC_Area head) {
  if (LOC_isAreaAreasSingle(arg)) {
    return (LOC_AreaAreas)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (LOC_isAreaAreasMany(arg)) {
    return (LOC_AreaAreas)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("AreaAreas has no Head: %t\n", arg);
  return (LOC_AreaAreas)NULL;
}

/**
 * Set the tail of a LOC_AreaAreas. The precondition being that this LOC_AreaAreas actually has a tail
 * \param[in] arg input LOC_AreaAreas
 * \param[in] tail new LOC_AreaAreas to set in #arg
 * \return A new LOC_AreaAreas with tail at the right place, or a core dump if #arg did not have a tail
 */
LOC_AreaAreas LOC_setAreaAreasTail(LOC_AreaAreas arg, LOC_AreaAreas tail) {
  if (LOC_isAreaAreasMany(arg)) {
    return (LOC_AreaAreas)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("AreaAreas has no Tail: %t\n", arg);
  return (LOC_AreaAreas)NULL;
}

/**
 * Apply functions to the children of a LOC_StrChar. 
 * \return A new LOC_StrChar with new children where the argument functions might have applied
 */
LOC_StrChar LOC_visitStrChar(LOC_StrChar arg, char* (*acceptString)(char*)) {
  if (LOC_isStrCharStrChar(arg)) {
    return LOC_makeStrCharStrChar(
        acceptString ? acceptString(LOC_getStrCharString(arg)) : LOC_getStrCharString(arg));
  }
  ATabort("not a StrChar: %t\n", arg);
  return (LOC_StrChar)NULL;
}
/**
 * Apply functions to the children of a LOC_StrCon. 
 * \return A new LOC_StrCon with new children where the argument functions might have applied
 */
LOC_StrCon LOC_visitStrCon(LOC_StrCon arg, char* (*acceptString)(char*)) {
  if (LOC_isStrConStrCon(arg)) {
    return LOC_makeStrConStrCon(
        acceptString ? acceptString(LOC_getStrConString(arg)) : LOC_getStrConString(arg));
  }
  ATabort("not a StrCon: %t\n", arg);
  return (LOC_StrCon)NULL;
}
/**
 * Apply functions to the children of a LOC_NatCon. 
 * \return A new LOC_NatCon with new children where the argument functions might have applied
 */
LOC_NatCon LOC_visitNatCon(LOC_NatCon arg, char* (*acceptString)(char*)) {
  if (LOC_isNatConNatCon(arg)) {
    return LOC_makeNatConNatCon(
        acceptString ? acceptString(LOC_getNatConString(arg)) : LOC_getNatConString(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (LOC_NatCon)NULL;
}
/**
 * Apply functions to the children of a LOC_Location. 
 * \return A new LOC_Location with new children where the argument functions might have applied
 */
LOC_Location LOC_visitLocation(LOC_Location arg, char* (*acceptFilename)(char*), LOC_Area (*acceptArea)(LOC_Area)) {
  if (LOC_isLocationFile(arg)) {
    return LOC_makeLocationFile(
        acceptFilename ? acceptFilename(LOC_getLocationFilename(arg)) : LOC_getLocationFilename(arg));
  }
  if (LOC_isLocationArea(arg)) {
    return LOC_makeLocationArea(
        acceptArea ? acceptArea(LOC_getLocationArea(arg)) : LOC_getLocationArea(arg));
  }
  if (LOC_isLocationAreaInFile(arg)) {
    return LOC_makeLocationAreaInFile(
        acceptFilename ? acceptFilename(LOC_getLocationFilename(arg)) : LOC_getLocationFilename(arg),
        acceptArea ? acceptArea(LOC_getLocationArea(arg)) : LOC_getLocationArea(arg));
  }
  ATabort("not a Location: %t\n", arg);
  return (LOC_Location)NULL;
}
/**
 * Apply functions to the children of a LOC_Area. 
 * \return A new LOC_Area with new children where the argument functions might have applied
 */
LOC_Area LOC_visitArea(LOC_Area arg, int (*acceptBeginLine)(int), int (*acceptBeginColumn)(int), int (*acceptEndLine)(int), int (*acceptEndColumn)(int), int (*acceptOffset)(int), int (*acceptLength)(int)) {
  if (LOC_isAreaArea(arg)) {
    return LOC_makeAreaArea(
        acceptBeginLine ? acceptBeginLine(LOC_getAreaBeginLine(arg)) : LOC_getAreaBeginLine(arg),
        acceptBeginColumn ? acceptBeginColumn(LOC_getAreaBeginColumn(arg)) : LOC_getAreaBeginColumn(arg),
        acceptEndLine ? acceptEndLine(LOC_getAreaEndLine(arg)) : LOC_getAreaEndLine(arg),
        acceptEndColumn ? acceptEndColumn(LOC_getAreaEndColumn(arg)) : LOC_getAreaEndColumn(arg),
        acceptOffset ? acceptOffset(LOC_getAreaOffset(arg)) : LOC_getAreaOffset(arg),
        acceptLength ? acceptLength(LOC_getAreaLength(arg)) : LOC_getAreaLength(arg));
  }
  ATabort("not a Area: %t\n", arg);
  return (LOC_Area)NULL;
}
/**
 * Apply functions to the children of a LOC_Slice. 
 * \return A new LOC_Slice with new children where the argument functions might have applied
 */
LOC_Slice LOC_visitSlice(LOC_Slice arg, char* (*acceptId)(char*), LOC_AreaAreas (*acceptAreas)(LOC_AreaAreas)) {
  if (LOC_isSliceSlice(arg)) {
    return LOC_makeSliceSlice(
        acceptId ? acceptId(LOC_getSliceId(arg)) : LOC_getSliceId(arg),
        acceptAreas ? acceptAreas(LOC_getSliceAreas(arg)) : LOC_getSliceAreas(arg));
  }
  ATabort("not a Slice: %t\n", arg);
  return (LOC_Slice)NULL;
}
/**
 * Apply functions to the children of a LOC_AreaAreas. 
 * \return A new LOC_AreaAreas with new children where the argument functions might have applied
 */
LOC_AreaAreas LOC_visitAreaAreas(LOC_AreaAreas arg, LOC_Area (*acceptHead)(LOC_Area)) {
  if (LOC_isAreaAreasEmpty(arg)) {
    return LOC_makeAreaAreasEmpty();
  }
  if (LOC_isAreaAreasSingle(arg)) {
    return LOC_makeAreaAreasSingle(
        acceptHead ? acceptHead(LOC_getAreaAreasHead(arg)) : LOC_getAreaAreasHead(arg));
  }
  if (LOC_isAreaAreasMany(arg)) {
    return LOC_makeAreaAreasMany(
        acceptHead ? acceptHead(LOC_getAreaAreasHead(arg)) : LOC_getAreaAreasHead(arg),
        LOC_visitAreaAreas(LOC_getAreaAreasTail(arg), acceptHead));
  }
  ATabort("not a AreaAreas: %t\n", arg);
  return (LOC_AreaAreas)NULL;
}

