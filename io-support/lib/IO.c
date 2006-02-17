#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "IO.h"

/*{{{  conversion functions */

ATerm IO_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

ATerm IO_byteToChar(char ch)
{
    return (ATerm) ATmakeInt(ch);
}

char *IO_charsToString(ATerm arg)
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

char IO_charToByte(ATerm arg)
{
    return (char) ATgetInt((ATermInt) arg);
}


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _IO_File;
typedef struct ATerm _IO_Path;
typedef struct ATerm _IO_Segment;
typedef struct ATerm _IO_SegmentList;
typedef struct ATerm _IO_StrChar;
typedef struct ATerm _IO_StrCon;

/*}}}  */

/*{{{  void IO_initIOApi(void) */

void IO_initIOApi(void)
{
  init_IO_dict();
}

/*}}}  */

/*{{{  protect functions */

void IO_protectFile(IO_File *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void IO_protectPath(IO_Path *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void IO_protectSegment(IO_Segment *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void IO_protectSegmentList(IO_SegmentList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void IO_protectStrChar(IO_StrChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void IO_protectStrCon(IO_StrCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  IO_File IO_FileFromTerm(ATerm t) */

IO_File IO_FileFromTerm(ATerm t)
{
  return (IO_File)t;
}

/*}}}  */
/*{{{  ATerm IO_FileToTerm(IO_File arg) */

ATerm IO_FileToTerm(IO_File arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  IO_Path IO_PathFromTerm(ATerm t) */

IO_Path IO_PathFromTerm(ATerm t)
{
  return (IO_Path)t;
}

/*}}}  */
/*{{{  ATerm IO_PathToTerm(IO_Path arg) */

ATerm IO_PathToTerm(IO_Path arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  IO_Segment IO_SegmentFromTerm(ATerm t) */

IO_Segment IO_SegmentFromTerm(ATerm t)
{
  return (IO_Segment)t;
}

/*}}}  */
/*{{{  ATerm IO_SegmentToTerm(IO_Segment arg) */

ATerm IO_SegmentToTerm(IO_Segment arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  IO_SegmentList IO_SegmentListFromTerm(ATerm t) */

IO_SegmentList IO_SegmentListFromTerm(ATerm t)
{
  return (IO_SegmentList)t;
}

/*}}}  */
/*{{{  ATerm IO_SegmentListToTerm(IO_SegmentList arg) */

ATerm IO_SegmentListToTerm(IO_SegmentList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  IO_StrChar IO_StrCharFromTerm(ATerm t) */

IO_StrChar IO_StrCharFromTerm(ATerm t)
{
  return (IO_StrChar)t;
}

/*}}}  */
/*{{{  ATerm IO_StrCharToTerm(IO_StrChar arg) */

ATerm IO_StrCharToTerm(IO_StrChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  IO_StrCon IO_StrConFromTerm(ATerm t) */

IO_StrCon IO_StrConFromTerm(ATerm t)
{
  return (IO_StrCon)t;
}

/*}}}  */
/*{{{  ATerm IO_StrConToTerm(IO_StrCon arg) */

ATerm IO_StrConToTerm(IO_StrCon arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int IO_getSegmentListLength (IO_SegmentList arg) {
  return ATgetLength((ATermList) arg);
}
IO_SegmentList IO_reverseSegmentList(IO_SegmentList arg) {
  return (IO_SegmentList) ATreverse((ATermList) arg);
}
IO_SegmentList IO_appendSegmentList(IO_SegmentList arg, IO_Segment elem) {
  return (IO_SegmentList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
IO_SegmentList IO_concatSegmentList(IO_SegmentList arg0, IO_SegmentList arg1) {
  return (IO_SegmentList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
IO_SegmentList IO_sliceSegmentList(IO_SegmentList arg, int start, int end) {
  return (IO_SegmentList) ATgetSlice((ATermList) arg, start, end);
}
IO_Segment IO_getSegmentListSegmentAt(IO_SegmentList arg, int index) {
 return (IO_Segment)ATelementAt((ATermList) arg,index);
}
IO_SegmentList IO_replaceSegmentListSegmentAt(IO_SegmentList arg, IO_Segment elem, int index) {
 return (IO_SegmentList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
IO_SegmentList IO_makeSegmentList2(IO_Segment elem1, IO_Segment elem2) {
  return (IO_SegmentList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
IO_SegmentList IO_makeSegmentList3(IO_Segment elem1, IO_Segment elem2, IO_Segment elem3) {
  return (IO_SegmentList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
IO_SegmentList IO_makeSegmentList4(IO_Segment elem1, IO_Segment elem2, IO_Segment elem3, IO_Segment elem4) {
  return (IO_SegmentList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
IO_SegmentList IO_makeSegmentList5(IO_Segment elem1, IO_Segment elem2, IO_Segment elem3, IO_Segment elem4, IO_Segment elem5) {
  return (IO_SegmentList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
IO_SegmentList IO_makeSegmentList6(IO_Segment elem1, IO_Segment elem2, IO_Segment elem3, IO_Segment elem4, IO_Segment elem5, IO_Segment elem6) {
  return (IO_SegmentList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  IO_File IO_makeFileFile(IO_Path path, const char* name, const char* extension) */

IO_File IO_makeFileFile(IO_Path path, const char* name, const char* extension)
{
  return (IO_File)(ATerm)ATmakeAppl3(IO_afun0, (ATerm) path, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(extension, 0, ATtrue)));
}

/*}}}  */
/*{{{  IO_Path IO_makePathAbsolute(IO_SegmentList list) */

IO_Path IO_makePathAbsolute(IO_SegmentList list)
{
  return (IO_Path)(ATerm)ATmakeAppl1(IO_afun1, (ATerm) list);
}

/*}}}  */
/*{{{  IO_Path IO_makePathRelative(IO_SegmentList list) */

IO_Path IO_makePathRelative(IO_SegmentList list)
{
  return (IO_Path)(ATerm)ATmakeAppl1(IO_afun2, (ATerm) list);
}

/*}}}  */
/*{{{  IO_Segment IO_makeSegmentSegment(const char* name) */

IO_Segment IO_makeSegmentSegment(const char* name)
{
  return (IO_Segment)(ATerm)ATmakeAppl1(IO_afun3, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}

/*}}}  */
/*{{{  IO_SegmentList IO_makeSegmentListEmpty(void) */

IO_SegmentList IO_makeSegmentListEmpty(void)
{
  return (IO_SegmentList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  IO_SegmentList IO_makeSegmentListSingle(IO_Segment head) */

IO_SegmentList IO_makeSegmentListSingle(IO_Segment head)
{
  return (IO_SegmentList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  IO_SegmentList IO_makeSegmentListMany(IO_Segment head, IO_SegmentList tail) */

IO_SegmentList IO_makeSegmentListMany(IO_Segment head, IO_SegmentList tail)
{
  return (IO_SegmentList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  IO_StrChar IO_makeStrCharStrChar(const char* string) */

IO_StrChar IO_makeStrCharStrChar(const char* string)
{
  return (IO_StrChar)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}

/*}}}  */
/*{{{  IO_StrCon IO_makeStrConStrCon(const char* string) */

IO_StrCon IO_makeStrConStrCon(const char* string)
{
  return (IO_StrCon)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool IO_isEqualFile(IO_File arg0, IO_File arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool IO_isEqualPath(IO_Path arg0, IO_Path arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool IO_isEqualSegment(IO_Segment arg0, IO_Segment arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool IO_isEqualSegmentList(IO_SegmentList arg0, IO_SegmentList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool IO_isEqualStrChar(IO_StrChar arg0, IO_StrChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool IO_isEqualStrCon(IO_StrCon arg0, IO_StrCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  IO_File accessors */

/*{{{  ATbool IO_isValidFile(IO_File arg) */

ATbool IO_isValidFile(IO_File arg)
{
  if (IO_isFileFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool IO_isFileFile(IO_File arg) */

inline ATbool IO_isFileFile(IO_File arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, IO_patternFileFile, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool IO_hasFilePath(IO_File arg) */

ATbool IO_hasFilePath(IO_File arg)
{
  if (IO_isFileFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool IO_hasFileName(IO_File arg) */

ATbool IO_hasFileName(IO_File arg)
{
  if (IO_isFileFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool IO_hasFileExtension(IO_File arg) */

ATbool IO_hasFileExtension(IO_File arg)
{
  if (IO_isFileFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  IO_Path IO_getFilePath(IO_File arg) */

IO_Path IO_getFilePath(IO_File arg)
{
  
    return (IO_Path)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  char* IO_getFileName(IO_File arg) */

char* IO_getFileName(IO_File arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  char* IO_getFileExtension(IO_File arg) */

char* IO_getFileExtension(IO_File arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 2)));
}

/*}}}  */
/*{{{  IO_File IO_setFilePath(IO_File arg, IO_Path path) */

IO_File IO_setFilePath(IO_File arg, IO_Path path)
{
  if (IO_isFileFile(arg)) {
    return (IO_File)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) path), 0);
  }

  ATabort("File has no Path: %t\n", arg);
  return (IO_File)NULL;
}

/*}}}  */
/*{{{  IO_File IO_setFileName(IO_File arg, const char* name) */

IO_File IO_setFileName(IO_File arg, const char* name)
{
  if (IO_isFileFile(arg)) {
    return (IO_File)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 1);
  }

  ATabort("File has no Name: %t\n", arg);
  return (IO_File)NULL;
}

/*}}}  */
/*{{{  IO_File IO_setFileExtension(IO_File arg, const char* extension) */

IO_File IO_setFileExtension(IO_File arg, const char* extension)
{
  if (IO_isFileFile(arg)) {
    return (IO_File)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(extension, 0, ATtrue))), 2);
  }

  ATabort("File has no Extension: %t\n", arg);
  return (IO_File)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  IO_Path accessors */

/*{{{  ATbool IO_isValidPath(IO_Path arg) */

ATbool IO_isValidPath(IO_Path arg)
{
  if (IO_isPathAbsolute(arg)) {
    return ATtrue;
  }
  else if (IO_isPathRelative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool IO_isPathAbsolute(IO_Path arg) */

inline ATbool IO_isPathAbsolute(IO_Path arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, IO_patternPathAbsolute, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool IO_isPathRelative(IO_Path arg) */

inline ATbool IO_isPathRelative(IO_Path arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, IO_patternPathRelative, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool IO_hasPathList(IO_Path arg) */

ATbool IO_hasPathList(IO_Path arg)
{
  if (IO_isPathAbsolute(arg)) {
    return ATtrue;
  }
  else if (IO_isPathRelative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  IO_SegmentList IO_getPathList(IO_Path arg) */

IO_SegmentList IO_getPathList(IO_Path arg)
{
  if (IO_isPathAbsolute(arg)) {
    return (IO_SegmentList)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (IO_SegmentList)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  IO_Path IO_setPathList(IO_Path arg, IO_SegmentList list) */

IO_Path IO_setPathList(IO_Path arg, IO_SegmentList list)
{
  if (IO_isPathAbsolute(arg)) {
    return (IO_Path)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }
  else if (IO_isPathRelative(arg)) {
    return (IO_Path)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 0);
  }

  ATabort("Path has no List: %t\n", arg);
  return (IO_Path)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  IO_Segment accessors */

/*{{{  ATbool IO_isValidSegment(IO_Segment arg) */

ATbool IO_isValidSegment(IO_Segment arg)
{
  if (IO_isSegmentSegment(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool IO_isSegmentSegment(IO_Segment arg) */

inline ATbool IO_isSegmentSegment(IO_Segment arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, IO_patternSegmentSegment, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool IO_hasSegmentName(IO_Segment arg) */

ATbool IO_hasSegmentName(IO_Segment arg)
{
  if (IO_isSegmentSegment(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* IO_getSegmentName(IO_Segment arg) */

char* IO_getSegmentName(IO_Segment arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  IO_Segment IO_setSegmentName(IO_Segment arg, const char* name) */

IO_Segment IO_setSegmentName(IO_Segment arg, const char* name)
{
  if (IO_isSegmentSegment(arg)) {
    return (IO_Segment)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("Segment has no Name: %t\n", arg);
  return (IO_Segment)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  IO_SegmentList accessors */

/*{{{  ATbool IO_isValidSegmentList(IO_SegmentList arg) */

ATbool IO_isValidSegmentList(IO_SegmentList arg)
{
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

/*}}}  */
/*{{{  inline ATbool IO_isSegmentListEmpty(IO_SegmentList arg) */

inline ATbool IO_isSegmentListEmpty(IO_SegmentList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, IO_patternSegmentListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool IO_isSegmentListSingle(IO_SegmentList arg) */

inline ATbool IO_isSegmentListSingle(IO_SegmentList arg)
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
      last_result = ATmatchTerm((ATerm)arg, IO_patternSegmentListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool IO_isSegmentListMany(IO_SegmentList arg) */

inline ATbool IO_isSegmentListMany(IO_SegmentList arg)
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
      last_result = ATmatchTerm((ATerm)arg, IO_patternSegmentListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool IO_hasSegmentListHead(IO_SegmentList arg) */

ATbool IO_hasSegmentListHead(IO_SegmentList arg)
{
  if (IO_isSegmentListSingle(arg)) {
    return ATtrue;
  }
  else if (IO_isSegmentListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool IO_hasSegmentListTail(IO_SegmentList arg) */

ATbool IO_hasSegmentListTail(IO_SegmentList arg)
{
  if (IO_isSegmentListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  IO_Segment IO_getSegmentListHead(IO_SegmentList arg) */

IO_Segment IO_getSegmentListHead(IO_SegmentList arg)
{
  if (IO_isSegmentListSingle(arg)) {
    return (IO_Segment)ATgetFirst((ATermList)arg);
  }
  else 
    return (IO_Segment)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  IO_SegmentList IO_getSegmentListTail(IO_SegmentList arg) */

IO_SegmentList IO_getSegmentListTail(IO_SegmentList arg)
{
  
    return (IO_SegmentList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  IO_SegmentList IO_setSegmentListHead(IO_SegmentList arg, IO_Segment head) */

IO_SegmentList IO_setSegmentListHead(IO_SegmentList arg, IO_Segment head)
{
  if (IO_isSegmentListSingle(arg)) {
    return (IO_SegmentList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (IO_isSegmentListMany(arg)) {
    return (IO_SegmentList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("SegmentList has no Head: %t\n", arg);
  return (IO_SegmentList)NULL;
}

/*}}}  */
/*{{{  IO_SegmentList IO_setSegmentListTail(IO_SegmentList arg, IO_SegmentList tail) */

IO_SegmentList IO_setSegmentListTail(IO_SegmentList arg, IO_SegmentList tail)
{
  if (IO_isSegmentListMany(arg)) {
    return (IO_SegmentList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("SegmentList has no Tail: %t\n", arg);
  return (IO_SegmentList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  IO_StrChar accessors */

/*{{{  ATbool IO_isValidStrChar(IO_StrChar arg) */

ATbool IO_isValidStrChar(IO_StrChar arg)
{
  if (IO_isStrCharStrChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool IO_isStrCharStrChar(IO_StrChar arg) */

inline ATbool IO_isStrCharStrChar(IO_StrChar arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, IO_patternStrCharStrChar, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool IO_hasStrCharString(IO_StrChar arg) */

ATbool IO_hasStrCharString(IO_StrChar arg)
{
  if (IO_isStrCharStrChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* IO_getStrCharString(IO_StrChar arg) */

char* IO_getStrCharString(IO_StrChar arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/*}}}  */
/*{{{  IO_StrChar IO_setStrCharString(IO_StrChar arg, const char* string) */

IO_StrChar IO_setStrCharString(IO_StrChar arg, const char* string)
{
  if (IO_isStrCharStrChar(arg)) {
    return (IO_StrChar)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("StrChar has no String: %t\n", arg);
  return (IO_StrChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  IO_StrCon accessors */

/*{{{  ATbool IO_isValidStrCon(IO_StrCon arg) */

ATbool IO_isValidStrCon(IO_StrCon arg)
{
  if (IO_isStrConStrCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool IO_isStrConStrCon(IO_StrCon arg) */

inline ATbool IO_isStrConStrCon(IO_StrCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, IO_patternStrConStrCon, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool IO_hasStrConString(IO_StrCon arg) */

ATbool IO_hasStrConString(IO_StrCon arg)
{
  if (IO_isStrConStrCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* IO_getStrConString(IO_StrCon arg) */

char* IO_getStrConString(IO_StrCon arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/*}}}  */
/*{{{  IO_StrCon IO_setStrConString(IO_StrCon arg, const char* string) */

IO_StrCon IO_setStrConString(IO_StrCon arg, const char* string)
{
  if (IO_isStrConStrCon(arg)) {
    return (IO_StrCon)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("StrCon has no String: %t\n", arg);
  return (IO_StrCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  IO_File IO_visitFile(IO_File arg, IO_Path (*acceptPath)(IO_Path), char* (*acceptName)(char*), char* (*acceptExtension)(char*)) */

IO_File IO_visitFile(IO_File arg, IO_Path (*acceptPath)(IO_Path), char* (*acceptName)(char*), char* (*acceptExtension)(char*))
{
  if (IO_isFileFile(arg)) {
    return IO_makeFileFile(
        acceptPath ? acceptPath(IO_getFilePath(arg)) : IO_getFilePath(arg),
        acceptName ? acceptName(IO_getFileName(arg)) : IO_getFileName(arg),
        acceptExtension ? acceptExtension(IO_getFileExtension(arg)) : IO_getFileExtension(arg));
  }
  ATabort("not a File: %t\n", arg);
  return (IO_File)NULL;
}

/*}}}  */
/*{{{  IO_Path IO_visitPath(IO_Path arg, IO_SegmentList (*acceptList)(IO_SegmentList)) */

IO_Path IO_visitPath(IO_Path arg, IO_SegmentList (*acceptList)(IO_SegmentList))
{
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

/*}}}  */
/*{{{  IO_Segment IO_visitSegment(IO_Segment arg, char* (*acceptName)(char*)) */

IO_Segment IO_visitSegment(IO_Segment arg, char* (*acceptName)(char*))
{
  if (IO_isSegmentSegment(arg)) {
    return IO_makeSegmentSegment(
        acceptName ? acceptName(IO_getSegmentName(arg)) : IO_getSegmentName(arg));
  }
  ATabort("not a Segment: %t\n", arg);
  return (IO_Segment)NULL;
}

/*}}}  */
/*{{{  IO_SegmentList IO_visitSegmentList(IO_SegmentList arg, IO_Segment (*acceptHead)(IO_Segment)) */

IO_SegmentList IO_visitSegmentList(IO_SegmentList arg, IO_Segment (*acceptHead)(IO_Segment))
{
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

/*}}}  */
/*{{{  IO_StrChar IO_visitStrChar(IO_StrChar arg, char* (*acceptString)(char*)) */

IO_StrChar IO_visitStrChar(IO_StrChar arg, char* (*acceptString)(char*))
{
  if (IO_isStrCharStrChar(arg)) {
    return IO_makeStrCharStrChar(
        acceptString ? acceptString(IO_getStrCharString(arg)) : IO_getStrCharString(arg));
  }
  ATabort("not a StrChar: %t\n", arg);
  return (IO_StrChar)NULL;
}

/*}}}  */
/*{{{  IO_StrCon IO_visitStrCon(IO_StrCon arg, char* (*acceptString)(char*)) */

IO_StrCon IO_visitStrCon(IO_StrCon arg, char* (*acceptString)(char*))
{
  if (IO_isStrConStrCon(arg)) {
    return IO_makeStrConStrCon(
        acceptString ? acceptString(IO_getStrConString(arg)) : IO_getStrConString(arg));
  }
  ATabort("not a StrCon: %t\n", arg);
  return (IO_StrCon)NULL;
}

/*}}}  */

/*}}}  */
