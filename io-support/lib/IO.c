#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "IO.h"

/**
 * Converts a string to an ATermList of integers (ASCII values). 
 * \param[in] str An ASCII string
 * \return An ATermList containing the ASCII values of #arg as ATermInts
 */
ATerm IO_stringToChars(const char *str) {
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
ATerm IO_byteToChar(char ch) {
    return (ATerm) ATmakeInt(ch);
}

/**
 * Converts a list of integers (ASCII values) to a C string. 
 * \param[in] arg An ATermList with ATermInts, such as [32,32,10]
 * \return String containing the characters from #arg as characters
 */
char *IO_charsToString(ATerm arg) {
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

char IO_charToByte(ATerm arg) {
    return (char) ATgetInt((ATermInt) arg);
}


typedef struct ATerm _IO_File;
typedef struct ATerm _IO_Path;
typedef struct ATerm _IO_Segment;
typedef struct ATerm _IO_SegmentList;
typedef struct ATerm _IO_StrChar;
typedef struct ATerm _IO_StrCon;


/**
 * Initializes the full API. Forgetting to call this function before using the API will lead to strange behaviour. ATinit() needs to be called before this function.
 */
void _IO_initIOApi(void) {
  init_IO_dict();

}

/**
 * Protect a IO_File from the ATerm garbage collector. Every IO_File that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a IO_File
 */
void _IO_protectFile(IO_File *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a IO_File from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a IO_File
 */
void _IO_unprotectFile(IO_File *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a IO_Path from the ATerm garbage collector. Every IO_Path that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a IO_Path
 */
void _IO_protectPath(IO_Path *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a IO_Path from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a IO_Path
 */
void _IO_unprotectPath(IO_Path *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a IO_Segment from the ATerm garbage collector. Every IO_Segment that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a IO_Segment
 */
void _IO_protectSegment(IO_Segment *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a IO_Segment from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a IO_Segment
 */
void _IO_unprotectSegment(IO_Segment *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a IO_SegmentList from the ATerm garbage collector. Every IO_SegmentList that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a IO_SegmentList
 */
void _IO_protectSegmentList(IO_SegmentList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a IO_SegmentList from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a IO_SegmentList
 */
void _IO_unprotectSegmentList(IO_SegmentList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a IO_StrChar from the ATerm garbage collector. Every IO_StrChar that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a IO_StrChar
 */
void _IO_protectStrChar(IO_StrChar *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a IO_StrChar from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a IO_StrChar
 */
void _IO_unprotectStrChar(IO_StrChar *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a IO_StrCon from the ATerm garbage collector. Every IO_StrCon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a IO_StrCon
 */
void _IO_protectStrCon(IO_StrCon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a IO_StrCon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a IO_StrCon
 */
void _IO_unprotectStrCon(IO_StrCon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Transforms an ATerm to a IO_File. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return IO_File that was encoded by \arg
 */
IO_File _IO_FileFromTerm(ATerm t) {
  return (IO_File)t;
}

/**
 * Transforms a IO_Fileto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg IO_File to be converted
 * \return ATerm that represents the IO_File
 */
ATerm _IO_FileToTerm(IO_File arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a IO_Path. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return IO_Path that was encoded by \arg
 */
IO_Path _IO_PathFromTerm(ATerm t) {
  return (IO_Path)t;
}

/**
 * Transforms a IO_Pathto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg IO_Path to be converted
 * \return ATerm that represents the IO_Path
 */
ATerm _IO_PathToTerm(IO_Path arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a IO_Segment. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return IO_Segment that was encoded by \arg
 */
IO_Segment _IO_SegmentFromTerm(ATerm t) {
  return (IO_Segment)t;
}

/**
 * Transforms a IO_Segmentto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg IO_Segment to be converted
 * \return ATerm that represents the IO_Segment
 */
ATerm _IO_SegmentToTerm(IO_Segment arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a IO_SegmentList. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return IO_SegmentList that was encoded by \arg
 */
IO_SegmentList _IO_SegmentListFromTerm(ATerm t) {
  return (IO_SegmentList)t;
}

/**
 * Transforms a IO_SegmentListto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg IO_SegmentList to be converted
 * \return ATerm that represents the IO_SegmentList
 */
ATerm _IO_SegmentListToTerm(IO_SegmentList arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a IO_StrChar. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return IO_StrChar that was encoded by \arg
 */
IO_StrChar _IO_StrCharFromTerm(ATerm t) {
  return (IO_StrChar)t;
}

/**
 * Transforms a IO_StrCharto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg IO_StrChar to be converted
 * \return ATerm that represents the IO_StrChar
 */
ATerm _IO_StrCharToTerm(IO_StrChar arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a IO_StrCon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return IO_StrCon that was encoded by \arg
 */
IO_StrCon _IO_StrConFromTerm(ATerm t) {
  return (IO_StrCon)t;
}

/**
 * Transforms a IO_StrConto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg IO_StrCon to be converted
 * \return ATerm that represents the IO_StrCon
 */
ATerm _IO_StrConToTerm(IO_StrCon arg) {
  return (ATerm)arg;
}

/**
 * Retrieve the length of a IO_SegmentList. 
 * \param[in] arg input IO_SegmentList
 * \return The number of elements in the IO_SegmentList
 */
int _IO_getSegmentListLength(IO_SegmentList arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a IO_SegmentList. 
 * \param[in] arg IO_SegmentList to be reversed
 * \return a reversed #arg
 */
IO_SegmentList _IO_reverseSegmentList(IO_SegmentList arg) {
  return (IO_SegmentList) ATreverse((ATermList) arg);
}

/**
 * Append a IO_Segment to the end of a IO_SegmentList. 
 * \param[in] arg IO_SegmentList to append the IO_Segment to
 * \param[in] elem IO_Segment to be appended
 * \return new IO_SegmentList with #elem appended
 */
IO_SegmentList _IO_appendSegmentList(IO_SegmentList arg, IO_Segment elem) {
  return (IO_SegmentList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two IO_SegmentLists. 
 * \param[in] arg0 first IO_SegmentList
 * \param[in] arg1 second IO_SegmentList
 * \return IO_SegmentList with the elements of #arg0 before the elements of #arg1
 */
IO_SegmentList _IO_concatSegmentList(IO_SegmentList arg0, IO_SegmentList arg1) {
  return (IO_SegmentList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a IO_SegmentList. 
 * \param[in] arg IO_SegmentList to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new IO_SegmentList with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
IO_SegmentList _IO_sliceSegmentList(IO_SegmentList arg, int start, int end) {
  return (IO_SegmentList) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the IO_Segment at #index from a IO_SegmentList. 
 * \param[in] arg IO_SegmentList to retrieve the IO_Segment from
 * \param[in] index index to use to point in the IO_SegmentList
 * \return IO_Segment at position #index in #arg
 */
IO_Segment _IO_getSegmentListSegmentAt(IO_SegmentList arg, int index) {
 return (IO_Segment)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the IO_Segment at #index from a IO_SegmentList by a new one. 
 * \param[in] arg IO_SegmentList to retrieve the IO_Segment from
 * \param[in] elem new IO_Segment to replace another
 * \param[in] index index to use to point in the IO_SegmentList
 * \return A new IO_SegmentListwith #elem replaced in #arg at position #index
 */
IO_SegmentList _IO_replaceSegmentListSegmentAt(IO_SegmentList arg, IO_Segment elem, int index) {
 return (IO_SegmentList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a IO_SegmentList of 2 consecutive elements. 
 * \param[in] elem1 One IO_Segment element of the new IO_SegmentList
 * \param[in] elem2 One IO_Segment element of the new IO_SegmentList
 * \return A new IO_SegmentList consisting of 2 IO_Segments
 */
IO_SegmentList _IO_makeSegmentList2(IO_Segment elem1, IO_Segment elem2) {
  return (IO_SegmentList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a IO_SegmentList of 3 consecutive elements. 
 * \param[in] elem1 One IO_Segment element of the new IO_SegmentList
 * \param[in] elem2 One IO_Segment element of the new IO_SegmentList
 * \param[in] elem3 One IO_Segment element of the new IO_SegmentList
 * \return A new IO_SegmentList consisting of 3 IO_Segments
 */
IO_SegmentList _IO_makeSegmentList3(IO_Segment elem1, IO_Segment elem2, IO_Segment elem3) {
  return (IO_SegmentList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a IO_SegmentList of 4 consecutive elements. 
 * \param[in] elem1 One IO_Segment element of the new IO_SegmentList
 * \param[in] elem2 One IO_Segment element of the new IO_SegmentList
 * \param[in] elem3 One IO_Segment element of the new IO_SegmentList
 * \param[in] elem4 One IO_Segment element of the new IO_SegmentList
 * \return A new IO_SegmentList consisting of 4 IO_Segments
 */
IO_SegmentList _IO_makeSegmentList4(IO_Segment elem1, IO_Segment elem2, IO_Segment elem3, IO_Segment elem4) {
  return (IO_SegmentList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a IO_SegmentList of 5 consecutive elements. 
 * \param[in] elem1 One IO_Segment element of the new IO_SegmentList
 * \param[in] elem2 One IO_Segment element of the new IO_SegmentList
 * \param[in] elem3 One IO_Segment element of the new IO_SegmentList
 * \param[in] elem4 One IO_Segment element of the new IO_SegmentList
 * \param[in] elem5 One IO_Segment element of the new IO_SegmentList
 * \return A new IO_SegmentList consisting of 5 IO_Segments
 */
IO_SegmentList _IO_makeSegmentList5(IO_Segment elem1, IO_Segment elem2, IO_Segment elem3, IO_Segment elem4, IO_Segment elem5) {
  return (IO_SegmentList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a IO_SegmentList of 6 consecutive elements. 
 * \param[in] elem1 One IO_Segment element of the new IO_SegmentList
 * \param[in] elem2 One IO_Segment element of the new IO_SegmentList
 * \param[in] elem3 One IO_Segment element of the new IO_SegmentList
 * \param[in] elem4 One IO_Segment element of the new IO_SegmentList
 * \param[in] elem5 One IO_Segment element of the new IO_SegmentList
 * \param[in] elem6 One IO_Segment element of the new IO_SegmentList
 * \return A new IO_SegmentList consisting of 6 IO_Segments
 */
IO_SegmentList _IO_makeSegmentList6(IO_Segment elem1, IO_Segment elem2, IO_Segment elem3, IO_Segment elem4, IO_Segment elem5, IO_Segment elem6) {
  return (IO_SegmentList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Constructs a file of type IO_File. Like all ATerm types, IO_Files are maximally shared.
 * \param[in] path a child of the new file
 * \param[in] name a child of the new file
 * \param[in] extension a child of the new file
 * \return A pointer to a file, either newly constructed or shared
 */
IO_File IO_makeFileFile(IO_Path path, const char* name, const char* extension) {
  return (IO_File)(ATerm)ATmakeAppl3(IO_afun0, (ATerm) path, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(extension, 0, ATtrue)));
}
/**
 * Constructs a absolute of type IO_Path. Like all ATerm types, IO_Paths are maximally shared.
 * \param[in] list a child of the new absolute
 * \return A pointer to a absolute, either newly constructed or shared
 */
IO_Path IO_makePathAbsolute(IO_SegmentList list) {
  return (IO_Path)(ATerm)ATmakeAppl1(IO_afun1, (ATerm) list);
}
/**
 * Constructs a relative of type IO_Path. Like all ATerm types, IO_Paths are maximally shared.
 * \param[in] list a child of the new relative
 * \return A pointer to a relative, either newly constructed or shared
 */
IO_Path IO_makePathRelative(IO_SegmentList list) {
  return (IO_Path)(ATerm)ATmakeAppl1(IO_afun2, (ATerm) list);
}
/**
 * Constructs a segment of type IO_Segment. Like all ATerm types, IO_Segments are maximally shared.
 * \param[in] name a child of the new segment
 * \return A pointer to a segment, either newly constructed or shared
 */
IO_Segment IO_makeSegmentSegment(const char* name) {
  return (IO_Segment)(ATerm)ATmakeAppl1(IO_afun3, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}
/**
 * Constructs a empty of type IO_SegmentList. Like all ATerm types, IO_SegmentLists are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
IO_SegmentList IO_makeSegmentListEmpty(void) {
  return (IO_SegmentList)(ATerm)ATempty;
}
/**
 * Constructs a single of type IO_SegmentList. Like all ATerm types, IO_SegmentLists are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
IO_SegmentList IO_makeSegmentListSingle(IO_Segment head) {
  return (IO_SegmentList)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type IO_SegmentList. Like all ATerm types, IO_SegmentLists are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
IO_SegmentList IO_makeSegmentListMany(IO_Segment head, IO_SegmentList tail) {
  return (IO_SegmentList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a StrChar of type IO_StrChar. Like all ATerm types, IO_StrChars are maximally shared.
 * \param[in] string a child of the new StrChar
 * \return A pointer to a StrChar, either newly constructed or shared
 */
IO_StrChar IO_makeStrCharStrChar(const char* string) {
  return (IO_StrChar)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}
/**
 * Constructs a StrCon of type IO_StrCon. Like all ATerm types, IO_StrCons are maximally shared.
 * \param[in] string a child of the new StrCon
 * \return A pointer to a StrCon, either newly constructed or shared
 */
IO_StrCon IO_makeStrConStrCon(const char* string) {
  return (IO_StrCon)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}

/**
 * Tests equality of two IO_Files. A constant time operation.
 * \param[in] arg0 first IO_File to be compared
 * \param[in] arg1 second IO_File to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _IO_isEqualFile(IO_File arg0, IO_File arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two IO_Paths. A constant time operation.
 * \param[in] arg0 first IO_Path to be compared
 * \param[in] arg1 second IO_Path to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _IO_isEqualPath(IO_Path arg0, IO_Path arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two IO_Segments. A constant time operation.
 * \param[in] arg0 first IO_Segment to be compared
 * \param[in] arg1 second IO_Segment to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _IO_isEqualSegment(IO_Segment arg0, IO_Segment arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two IO_SegmentLists. A constant time operation.
 * \param[in] arg0 first IO_SegmentList to be compared
 * \param[in] arg1 second IO_SegmentList to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _IO_isEqualSegmentList(IO_SegmentList arg0, IO_SegmentList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two IO_StrChars. A constant time operation.
 * \param[in] arg0 first IO_StrChar to be compared
 * \param[in] arg1 second IO_StrChar to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _IO_isEqualStrChar(IO_StrChar arg0, IO_StrChar arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two IO_StrCons. A constant time operation.
 * \param[in] arg0 first IO_StrCon to be compared
 * \param[in] arg1 second IO_StrCon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool _IO_isEqualStrCon(IO_StrCon arg0, IO_StrCon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Assert whether a IO_File is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input IO_File
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool IO_isValidFile(IO_File arg) {
  if (IO_isFileFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a IO_File is a file by checking against the following ATerm pattern: file(<"path"("Path")>,<"name"(str)>,<"extension"(str)>). Always returns ATtrue
 * \param[in] arg input IO_File
 * \return ATtrue if #arg corresponds to the signature of a file, or ATfalse otherwise
 */
inline ATbool IO_isFileFile(IO_File arg){
  /* checking for: file */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == IO_afun0) {
    ATerm arg_arg1 = ATgetArgument(arg, 1);
    if (ATgetType((ATerm)arg_arg1) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg1)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg1)) == ATtrue) {
      ATerm arg_arg2 = ATgetArgument(arg, 2);
      if (ATgetType((ATerm)arg_arg2) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg2)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg2)) == ATtrue) {
        return ATtrue;
      }
    }
  }
  return ATfalse;
}

/**
 * Assert whether a IO_File has a path. 
 * \param[in] arg input IO_File
 * \return ATtrue if the IO_File had a path, or ATfalse otherwise
 */
ATbool IO_hasFilePath(IO_File arg) {
  if (IO_isFileFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a IO_File has a name. 
 * \param[in] arg input IO_File
 * \return ATtrue if the IO_File had a name, or ATfalse otherwise
 */
ATbool IO_hasFileName(IO_File arg) {
  if (IO_isFileFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a IO_File has a extension. 
 * \param[in] arg input IO_File
 * \return ATtrue if the IO_File had a extension, or ATfalse otherwise
 */
ATbool IO_hasFileExtension(IO_File arg) {
  if (IO_isFileFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the path IO_Path of a IO_File. Note that the precondition is that this IO_File actually has a path
 * \param[in] arg input IO_File
 * \return the path of #arg, if it exist or an undefined value if it does not
 */
IO_Path IO_getFilePath(IO_File arg) {
  
    return (IO_Path)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the name char* of a IO_File. Note that the precondition is that this IO_File actually has a name
 * \param[in] arg input IO_File
 * \return the name of #arg, if it exist or an undefined value if it does not
 */
char* IO_getFileName(IO_File arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/**
 * Get the extension char* of a IO_File. Note that the precondition is that this IO_File actually has a extension
 * \param[in] arg input IO_File
 * \return the extension of #arg, if it exist or an undefined value if it does not
 */
char* IO_getFileExtension(IO_File arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 2)));
}

/**
 * Set the path of a IO_File. The precondition being that this IO_File actually has a path
 * \param[in] arg input IO_File
 * \param[in] path new IO_Path to set in #arg
 * \return A new IO_File with path at the right place, or a core dump if #arg did not have a path
 */
IO_File IO_setFilePath(IO_File arg, IO_Path path) {
  if (IO_isFileFile(arg)) {
    return (IO_File)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) path), 0);
  }

  ATabort("File has no Path: %t\n", arg);
  return (IO_File)NULL;
}

/**
 * Set the name of a IO_File. The precondition being that this IO_File actually has a name
 * \param[in] arg input IO_File
 * \param[in] name new const char* to set in #arg
 * \return A new IO_File with name at the right place, or a core dump if #arg did not have a name
 */
IO_File IO_setFileName(IO_File arg, const char* name) {
  if (IO_isFileFile(arg)) {
    return (IO_File)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 1);
  }

  ATabort("File has no Name: %t\n", arg);
  return (IO_File)NULL;
}

/**
 * Set the extension of a IO_File. The precondition being that this IO_File actually has a extension
 * \param[in] arg input IO_File
 * \param[in] extension new const char* to set in #arg
 * \return A new IO_File with extension at the right place, or a core dump if #arg did not have a extension
 */
IO_File IO_setFileExtension(IO_File arg, const char* extension) {
  if (IO_isFileFile(arg)) {
    return (IO_File)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(extension, 0, ATtrue))), 2);
  }

  ATabort("File has no Extension: %t\n", arg);
  return (IO_File)NULL;
}

/**
 * Assert whether a IO_Path is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input IO_Path
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool IO_isValidPath(IO_Path arg) {
  if (IO_isPathAbsolute(arg)) {
    return ATtrue;
  }
  else if (IO_isPathRelative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a IO_Path is a absolute by checking against the following ATerm pattern: absolute(<"list"("Segment-list")>). May not be used to assert correctness of the IO_Path
 * \param[in] arg input IO_Path
 * \return ATtrue if #arg corresponds to the signature of a absolute, or ATfalse otherwise
 */
inline ATbool IO_isPathAbsolute(IO_Path arg){
  /* checking for: absolute */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == IO_afun1) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a IO_Path is a relative by checking against the following ATerm pattern: relative(<"list"("Segment-list")>). May not be used to assert correctness of the IO_Path
 * \param[in] arg input IO_Path
 * \return ATtrue if #arg corresponds to the signature of a relative, or ATfalse otherwise
 */
inline ATbool IO_isPathRelative(IO_Path arg){
  /* checking for: relative */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == IO_afun2) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a IO_Path has a list. 
 * \param[in] arg input IO_Path
 * \return ATtrue if the IO_Path had a list, or ATfalse otherwise
 */
ATbool IO_hasPathList(IO_Path arg) {
  if (IO_isPathAbsolute(arg)) {
    return ATtrue;
  }
  else if (IO_isPathRelative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the list IO_SegmentList of a IO_Path. Note that the precondition is that this IO_Path actually has a list
 * \param[in] arg input IO_Path
 * \return the list of #arg, if it exist or an undefined value if it does not
 */
IO_SegmentList IO_getPathList(IO_Path arg) {
  if (IO_isPathAbsolute(arg)) {
    return (IO_SegmentList)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (IO_SegmentList)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Set the list of a IO_Path. The precondition being that this IO_Path actually has a list
 * \param[in] arg input IO_Path
 * \param[in] list new IO_SegmentList to set in #arg
 * \return A new IO_Path with list at the right place, or a core dump if #arg did not have a list
 */
IO_Path IO_setPathList(IO_Path arg, IO_SegmentList list) {
  if (IO_isPathAbsolute(arg)) {
    return (IO_Path)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }
  else if (IO_isPathRelative(arg)) {
    return (IO_Path)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }

  ATabort("Path has no List: %t\n", arg);
  return (IO_Path)NULL;
}

/**
 * Assert whether a IO_Segment is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input IO_Segment
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool IO_isValidSegment(IO_Segment arg) {
  if (IO_isSegmentSegment(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a IO_Segment is a segment by checking against the following ATerm pattern: segment(<"name"(str)>). Always returns ATtrue
 * \param[in] arg input IO_Segment
 * \return ATtrue if #arg corresponds to the signature of a segment, or ATfalse otherwise
 */
inline ATbool IO_isSegmentSegment(IO_Segment arg){
  /* checking for: segment */
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetAFun((ATermAppl)arg) == IO_afun3) {
    ATerm arg_arg0 = ATgetArgument(arg, 0);
    if (ATgetType((ATerm)arg_arg0) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg_arg0)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg_arg0)) == ATtrue) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/**
 * Assert whether a IO_Segment has a name. 
 * \param[in] arg input IO_Segment
 * \return ATtrue if the IO_Segment had a name, or ATfalse otherwise
 */
ATbool IO_hasSegmentName(IO_Segment arg) {
  if (IO_isSegmentSegment(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the name char* of a IO_Segment. Note that the precondition is that this IO_Segment actually has a name
 * \param[in] arg input IO_Segment
 * \return the name of #arg, if it exist or an undefined value if it does not
 */
char* IO_getSegmentName(IO_Segment arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Set the name of a IO_Segment. The precondition being that this IO_Segment actually has a name
 * \param[in] arg input IO_Segment
 * \param[in] name new const char* to set in #arg
 * \return A new IO_Segment with name at the right place, or a core dump if #arg did not have a name
 */
IO_Segment IO_setSegmentName(IO_Segment arg, const char* name) {
  if (IO_isSegmentSegment(arg)) {
    return (IO_Segment)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("Segment has no Name: %t\n", arg);
  return (IO_Segment)NULL;
}

/**
 * Assert whether a IO_SegmentList is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input IO_SegmentList
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool IO_isValidSegmentList(IO_SegmentList arg) {
  if (IO_isSegmentListEmpty(arg)) {
    return ATtrue;
  }
  else if (IO_isSegmentListSingle(arg)) {
    return ATtrue;
  }
  else if (IO_isSegmentListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a IO_SegmentList is a empty by checking against the following ATerm pattern: []. May not be used to assert correctness of the IO_SegmentList
 * \param[in] arg input IO_SegmentList
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool IO_isSegmentListEmpty(IO_SegmentList arg){
  if (ATisEmpty((ATermList)arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a IO_SegmentList is a single by checking against the following ATerm pattern: [<head(Segment)>]. May not be used to assert correctness of the IO_SegmentList
 * \param[in] arg input IO_SegmentList
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool IO_isSegmentListSingle(IO_SegmentList arg){
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
 * Assert whether a IO_SegmentList is a many by checking against the following ATerm pattern: [<head(Segment)>,<[tail(Segment-list)]>]. May not be used to assert correctness of the IO_SegmentList
 * \param[in] arg input IO_SegmentList
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool IO_isSegmentListMany(IO_SegmentList arg){
  if (ATgetType((ATerm)arg) == AT_LIST && ATisEmpty((ATermList)arg) == ATfalse) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a IO_SegmentList has a head. 
 * \param[in] arg input IO_SegmentList
 * \return ATtrue if the IO_SegmentList had a head, or ATfalse otherwise
 */
ATbool IO_hasSegmentListHead(IO_SegmentList arg) {
  if (IO_isSegmentListSingle(arg)) {
    return ATtrue;
  }
  else if (IO_isSegmentListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a IO_SegmentList has a tail. 
 * \param[in] arg input IO_SegmentList
 * \return ATtrue if the IO_SegmentList had a tail, or ATfalse otherwise
 */
ATbool IO_hasSegmentListTail(IO_SegmentList arg) {
  if (IO_isSegmentListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head IO_Segment of a IO_SegmentList. Note that the precondition is that this IO_SegmentList actually has a head
 * \param[in] arg input IO_SegmentList
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
IO_Segment IO_getSegmentListHead(IO_SegmentList arg) {
  if (IO_isSegmentListSingle(arg)) {
    return (IO_Segment)ATgetFirst((ATermList)arg);
  }
  else 
    return (IO_Segment)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail IO_SegmentList of a IO_SegmentList. Note that the precondition is that this IO_SegmentList actually has a tail
 * \param[in] arg input IO_SegmentList
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
IO_SegmentList IO_getSegmentListTail(IO_SegmentList arg) {
  
    return (IO_SegmentList)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a IO_SegmentList. The precondition being that this IO_SegmentList actually has a head
 * \param[in] arg input IO_SegmentList
 * \param[in] head new IO_Segment to set in #arg
 * \return A new IO_SegmentList with head at the right place, or a core dump if #arg did not have a head
 */
IO_SegmentList IO_setSegmentListHead(IO_SegmentList arg, IO_Segment head) {
  if (IO_isSegmentListSingle(arg)) {
    return (IO_SegmentList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (IO_isSegmentListMany(arg)) {
    return (IO_SegmentList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("SegmentList has no Head: %t\n", arg);
  return (IO_SegmentList)NULL;
}

/**
 * Set the tail of a IO_SegmentList. The precondition being that this IO_SegmentList actually has a tail
 * \param[in] arg input IO_SegmentList
 * \param[in] tail new IO_SegmentList to set in #arg
 * \return A new IO_SegmentList with tail at the right place, or a core dump if #arg did not have a tail
 */
IO_SegmentList IO_setSegmentListTail(IO_SegmentList arg, IO_SegmentList tail) {
  if (IO_isSegmentListMany(arg)) {
    return (IO_SegmentList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("SegmentList has no Tail: %t\n", arg);
  return (IO_SegmentList)NULL;
}

/**
 * Assert whether a IO_StrChar is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input IO_StrChar
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool IO_isValidStrChar(IO_StrChar arg) {
  if (IO_isStrCharStrChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a IO_StrChar is a StrChar by checking against the following ATerm pattern: <string(str)>. Always returns ATtrue
 * \param[in] arg input IO_StrChar
 * \return ATtrue if #arg corresponds to the signature of a StrChar, or ATfalse otherwise
 */
inline ATbool IO_isStrCharStrChar(IO_StrChar arg){
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg)) == ATtrue) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a IO_StrChar has a string. 
 * \param[in] arg input IO_StrChar
 * \return ATtrue if the IO_StrChar had a string, or ATfalse otherwise
 */
ATbool IO_hasStrCharString(IO_StrChar arg) {
  if (IO_isStrCharStrChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the string char* of a IO_StrChar. Note that the precondition is that this IO_StrChar actually has a string
 * \param[in] arg input IO_StrChar
 * \return the string of #arg, if it exist or an undefined value if it does not
 */
char* IO_getStrCharString(IO_StrChar arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/**
 * Set the string of a IO_StrChar. The precondition being that this IO_StrChar actually has a string
 * \param[in] arg input IO_StrChar
 * \param[in] string new const char* to set in #arg
 * \return A new IO_StrChar with string at the right place, or a core dump if #arg did not have a string
 */
IO_StrChar IO_setStrCharString(IO_StrChar arg, const char* string) {
  if (IO_isStrCharStrChar(arg)) {
    return (IO_StrChar)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("StrChar has no String: %t\n", arg);
  return (IO_StrChar)NULL;
}

/**
 * Assert whether a IO_StrCon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input IO_StrCon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool IO_isValidStrCon(IO_StrCon arg) {
  if (IO_isStrConStrCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a IO_StrCon is a StrCon by checking against the following ATerm pattern: <string(str)>. Always returns ATtrue
 * \param[in] arg input IO_StrCon
 * \return ATtrue if #arg corresponds to the signature of a StrCon, or ATfalse otherwise
 */
inline ATbool IO_isStrConStrCon(IO_StrCon arg){
  if (ATgetType((ATerm)arg) == AT_APPL && ATgetArity(ATgetAFun((ATermAppl)arg)) == 0 && ATisQuoted(ATgetAFun((ATermAppl)arg)) == ATtrue) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a IO_StrCon has a string. 
 * \param[in] arg input IO_StrCon
 * \return ATtrue if the IO_StrCon had a string, or ATfalse otherwise
 */
ATbool IO_hasStrConString(IO_StrCon arg) {
  if (IO_isStrConStrCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the string char* of a IO_StrCon. Note that the precondition is that this IO_StrCon actually has a string
 * \param[in] arg input IO_StrCon
 * \return the string of #arg, if it exist or an undefined value if it does not
 */
char* IO_getStrConString(IO_StrCon arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/**
 * Set the string of a IO_StrCon. The precondition being that this IO_StrCon actually has a string
 * \param[in] arg input IO_StrCon
 * \param[in] string new const char* to set in #arg
 * \return A new IO_StrCon with string at the right place, or a core dump if #arg did not have a string
 */
IO_StrCon IO_setStrConString(IO_StrCon arg, const char* string) {
  if (IO_isStrConStrCon(arg)) {
    return (IO_StrCon)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("StrCon has no String: %t\n", arg);
  return (IO_StrCon)NULL;
}

/**
 * Apply functions to the children of a IO_File. 
 * \return A new IO_File with new children where the argument functions might have applied
 */
IO_File IO_visitFile(IO_File arg, IO_Path (*acceptPath)(IO_Path), char* (*acceptName)(char*), char* (*acceptExtension)(char*)) {
  if (IO_isFileFile(arg)) {
    return IO_makeFileFile(
        acceptPath ? acceptPath(IO_getFilePath(arg)) : IO_getFilePath(arg),
        acceptName ? acceptName(IO_getFileName(arg)) : IO_getFileName(arg),
        acceptExtension ? acceptExtension(IO_getFileExtension(arg)) : IO_getFileExtension(arg));
  }
  ATabort("not a File: %t\n", arg);
  return (IO_File)NULL;
}
/**
 * Apply functions to the children of a IO_Path. 
 * \return A new IO_Path with new children where the argument functions might have applied
 */
IO_Path IO_visitPath(IO_Path arg, IO_SegmentList (*acceptList)(IO_SegmentList)) {
  if (IO_isPathAbsolute(arg)) {
    return IO_makePathAbsolute(
        acceptList ? acceptList(IO_getPathList(arg)) : IO_getPathList(arg));
  }
  if (IO_isPathRelative(arg)) {
    return IO_makePathRelative(
        acceptList ? acceptList(IO_getPathList(arg)) : IO_getPathList(arg));
  }
  ATabort("not a Path: %t\n", arg);
  return (IO_Path)NULL;
}
/**
 * Apply functions to the children of a IO_Segment. 
 * \return A new IO_Segment with new children where the argument functions might have applied
 */
IO_Segment IO_visitSegment(IO_Segment arg, char* (*acceptName)(char*)) {
  if (IO_isSegmentSegment(arg)) {
    return IO_makeSegmentSegment(
        acceptName ? acceptName(IO_getSegmentName(arg)) : IO_getSegmentName(arg));
  }
  ATabort("not a Segment: %t\n", arg);
  return (IO_Segment)NULL;
}
/**
 * Apply functions to the children of a IO_SegmentList. 
 * \return A new IO_SegmentList with new children where the argument functions might have applied
 */
IO_SegmentList IO_visitSegmentList(IO_SegmentList arg, IO_Segment (*acceptHead)(IO_Segment)) {
  if (IO_isSegmentListEmpty(arg)) {
    return IO_makeSegmentListEmpty();
  }
  if (IO_isSegmentListSingle(arg)) {
    return IO_makeSegmentListSingle(
        acceptHead ? acceptHead(IO_getSegmentListHead(arg)) : IO_getSegmentListHead(arg));
  }
  if (IO_isSegmentListMany(arg)) {
    return IO_makeSegmentListMany(
        acceptHead ? acceptHead(IO_getSegmentListHead(arg)) : IO_getSegmentListHead(arg),
        IO_visitSegmentList(IO_getSegmentListTail(arg), acceptHead));
  }
  ATabort("not a SegmentList: %t\n", arg);
  return (IO_SegmentList)NULL;
}
/**
 * Apply functions to the children of a IO_StrChar. 
 * \return A new IO_StrChar with new children where the argument functions might have applied
 */
IO_StrChar IO_visitStrChar(IO_StrChar arg, char* (*acceptString)(char*)) {
  if (IO_isStrCharStrChar(arg)) {
    return IO_makeStrCharStrChar(
        acceptString ? acceptString(IO_getStrCharString(arg)) : IO_getStrCharString(arg));
  }
  ATabort("not a StrChar: %t\n", arg);
  return (IO_StrChar)NULL;
}
/**
 * Apply functions to the children of a IO_StrCon. 
 * \return A new IO_StrCon with new children where the argument functions might have applied
 */
IO_StrCon IO_visitStrCon(IO_StrCon arg, char* (*acceptString)(char*)) {
  if (IO_isStrConStrCon(arg)) {
    return IO_makeStrConStrCon(
        acceptString ? acceptString(IO_getStrConString(arg)) : IO_getStrConString(arg));
  }
  ATabort("not a StrCon: %t\n", arg);
  return (IO_StrCon)NULL;
}

