#ifndef _IO_H
#define _IO_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "IO_dict.h"

typedef struct _IO_File *IO_File;
typedef struct _IO_Path *IO_Path;
typedef struct _IO_Segment *IO_Segment;
typedef struct _IO_SegmentList *IO_SegmentList;
typedef struct _IO_StrChar *IO_StrChar;
typedef struct _IO_StrCon *IO_StrCon;

#ifdef FAST_API
#define IO_initIOApi() (init_IO_dict())
#else
void _IO_initIOApi (void);
#define IO_initIOApi() (_IO_initIOApi())
#endif

#ifdef FAST_API
#define IO_protectFile(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _IO_protectFile (IO_File * arg);
#define IO_protectFile(arg) (_IO_protectFile(arg))
#endif
#ifdef FAST_API
#define IO_unprotectFile(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _IO_unprotectFile (IO_File * arg);
#define IO_unprotectFile(arg) (_IO_unprotectFile(arg))
#endif
#ifdef FAST_API
#define IO_protectPath(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _IO_protectPath (IO_Path * arg);
#define IO_protectPath(arg) (_IO_protectPath(arg))
#endif
#ifdef FAST_API
#define IO_unprotectPath(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _IO_unprotectPath (IO_Path * arg);
#define IO_unprotectPath(arg) (_IO_unprotectPath(arg))
#endif
#ifdef FAST_API
#define IO_protectSegment(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _IO_protectSegment (IO_Segment * arg);
#define IO_protectSegment(arg) (_IO_protectSegment(arg))
#endif
#ifdef FAST_API
#define IO_unprotectSegment(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _IO_unprotectSegment (IO_Segment * arg);
#define IO_unprotectSegment(arg) (_IO_unprotectSegment(arg))
#endif
#ifdef FAST_API
#define IO_protectSegmentList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _IO_protectSegmentList (IO_SegmentList * arg);
#define IO_protectSegmentList(arg) (_IO_protectSegmentList(arg))
#endif
#ifdef FAST_API
#define IO_unprotectSegmentList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _IO_unprotectSegmentList (IO_SegmentList * arg);
#define IO_unprotectSegmentList(arg) (_IO_unprotectSegmentList(arg))
#endif
#ifdef FAST_API
#define IO_protectStrChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _IO_protectStrChar (IO_StrChar * arg);
#define IO_protectStrChar(arg) (_IO_protectStrChar(arg))
#endif
#ifdef FAST_API
#define IO_unprotectStrChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _IO_unprotectStrChar (IO_StrChar * arg);
#define IO_unprotectStrChar(arg) (_IO_unprotectStrChar(arg))
#endif
#ifdef FAST_API
#define IO_protectStrCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _IO_protectStrCon (IO_StrCon * arg);
#define IO_protectStrCon(arg) (_IO_protectStrCon(arg))
#endif
#ifdef FAST_API
#define IO_unprotectStrCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _IO_unprotectStrCon (IO_StrCon * arg);
#define IO_unprotectStrCon(arg) (_IO_unprotectStrCon(arg))
#endif
#ifdef FAST_API
#define IO_FileFromTerm(t) ((IO_File)(t))
#else
IO_File _IO_FileFromTerm (ATerm t);
#define IO_FileFromTerm(t) (_IO_FileFromTerm(t))
#endif
#ifdef FAST_API
#define IO_FileToTerm(arg) ((ATerm)(arg))
#else
ATerm _IO_FileToTerm (IO_File arg);
#define IO_FileToTerm(arg) (_IO_FileToTerm(arg))
#endif
#ifdef FAST_API
#define IO_PathFromTerm(t) ((IO_Path)(t))
#else
IO_Path _IO_PathFromTerm (ATerm t);
#define IO_PathFromTerm(t) (_IO_PathFromTerm(t))
#endif
#ifdef FAST_API
#define IO_PathToTerm(arg) ((ATerm)(arg))
#else
ATerm _IO_PathToTerm (IO_Path arg);
#define IO_PathToTerm(arg) (_IO_PathToTerm(arg))
#endif
#ifdef FAST_API
#define IO_SegmentFromTerm(t) ((IO_Segment)(t))
#else
IO_Segment _IO_SegmentFromTerm (ATerm t);
#define IO_SegmentFromTerm(t) (_IO_SegmentFromTerm(t))
#endif
#ifdef FAST_API
#define IO_SegmentToTerm(arg) ((ATerm)(arg))
#else
ATerm _IO_SegmentToTerm (IO_Segment arg);
#define IO_SegmentToTerm(arg) (_IO_SegmentToTerm(arg))
#endif
#ifdef FAST_API
#define IO_SegmentListFromTerm(t) ((IO_SegmentList)(t))
#else
IO_SegmentList _IO_SegmentListFromTerm (ATerm t);
#define IO_SegmentListFromTerm(t) (_IO_SegmentListFromTerm(t))
#endif
#ifdef FAST_API
#define IO_SegmentListToTerm(arg) ((ATerm)(arg))
#else
ATerm _IO_SegmentListToTerm (IO_SegmentList arg);
#define IO_SegmentListToTerm(arg) (_IO_SegmentListToTerm(arg))
#endif
#ifdef FAST_API
#define IO_StrCharFromTerm(t) ((IO_StrChar)(t))
#else
IO_StrChar _IO_StrCharFromTerm (ATerm t);
#define IO_StrCharFromTerm(t) (_IO_StrCharFromTerm(t))
#endif
#ifdef FAST_API
#define IO_StrCharToTerm(arg) ((ATerm)(arg))
#else
ATerm _IO_StrCharToTerm (IO_StrChar arg);
#define IO_StrCharToTerm(arg) (_IO_StrCharToTerm(arg))
#endif
#ifdef FAST_API
#define IO_StrConFromTerm(t) ((IO_StrCon)(t))
#else
IO_StrCon _IO_StrConFromTerm (ATerm t);
#define IO_StrConFromTerm(t) (_IO_StrConFromTerm(t))
#endif
#ifdef FAST_API
#define IO_StrConToTerm(arg) ((ATerm)(arg))
#else
ATerm _IO_StrConToTerm (IO_StrCon arg);
#define IO_StrConToTerm(arg) (_IO_StrConToTerm(arg))
#endif
#ifdef FAST_API
#define IO_getSegmentListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _IO_getSegmentListLength (IO_SegmentList arg);
#define IO_getSegmentListLength(arg) (_IO_getSegmentListLength(arg))
#endif
#ifdef FAST_API
#define IO_reverseSegmentList(arg) ((IO_SegmentList) ATreverse((ATermList) (arg)))
#else
IO_SegmentList _IO_reverseSegmentList (IO_SegmentList arg);
#define IO_reverseSegmentList(arg) (_IO_reverseSegmentList(arg))
#endif
#ifdef FAST_API
#define IO_appendSegmentList(arg, elem) ((IO_SegmentList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
IO_SegmentList _IO_appendSegmentList (IO_SegmentList arg, IO_Segment elem);
#define IO_appendSegmentList(arg, elem) (_IO_appendSegmentList(arg, elem))
#endif
#ifdef FAST_API
#define IO_concatSegmentList(arg0, arg1) ((IO_SegmentList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
IO_SegmentList _IO_concatSegmentList (IO_SegmentList arg0,
				      IO_SegmentList arg1);
#define IO_concatSegmentList(arg0, arg1) (_IO_concatSegmentList(arg0, arg1))
#endif
#ifdef FAST_API
#define IO_sliceSegmentList(arg, start, end) ((IO_SegmentList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
IO_SegmentList _IO_sliceSegmentList (IO_SegmentList arg, int start, int end);
#define IO_sliceSegmentList(arg, start, end) (_IO_sliceSegmentList(arg, start, end))
#endif
#ifdef FAST_API
#define IO_getSegmentListSegmentAt(arg, index) ((IO_Segment) (ATelementAt((ATermList) arg,index)))
#else
IO_Segment _IO_getSegmentListSegmentAt (IO_SegmentList arg, int index);
#define IO_getSegmentListSegmentAt(arg, index) (_IO_getSegmentListSegmentAt(arg, index))
#endif
#ifdef FAST_API
#define IO_replaceSegmentListSegmentAt(arg, elem, index) ((IO_SegmentList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
IO_SegmentList _IO_replaceSegmentListSegmentAt (IO_SegmentList arg,
						IO_Segment elem, int index);
#define IO_replaceSegmentListSegmentAt(arg, elem, index) (_IO_replaceSegmentListSegmentAt(arg, elem, index))
#endif
#ifdef FAST_API
#define IO_makeSegmentList2(elem1,  elem2) ((IO_SegmentList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
IO_SegmentList _IO_makeSegmentList2 (IO_Segment elem1, IO_Segment elem2);
#define IO_makeSegmentList2(elem1,  elem2) (_IO_makeSegmentList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define IO_makeSegmentList3(elem1, elem2,  elem3) ((IO_SegmentList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
IO_SegmentList _IO_makeSegmentList3 (IO_Segment elem1, IO_Segment elem2,
				     IO_Segment elem3);
#define IO_makeSegmentList3(elem1, elem2,  elem3) (_IO_makeSegmentList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define IO_makeSegmentList4(elem1, elem2, elem3,  elem4) ((IO_SegmentList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
IO_SegmentList _IO_makeSegmentList4 (IO_Segment elem1, IO_Segment elem2,
				     IO_Segment elem3, IO_Segment elem4);
#define IO_makeSegmentList4(elem1, elem2, elem3,  elem4) (_IO_makeSegmentList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define IO_makeSegmentList5(elem1, elem2, elem3, elem4,  elem5) ((IO_SegmentList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
IO_SegmentList _IO_makeSegmentList5 (IO_Segment elem1, IO_Segment elem2,
				     IO_Segment elem3, IO_Segment elem4,
				     IO_Segment elem5);
#define IO_makeSegmentList5(elem1, elem2, elem3, elem4,  elem5) (_IO_makeSegmentList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define IO_makeSegmentList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((IO_SegmentList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
IO_SegmentList _IO_makeSegmentList6 (IO_Segment elem1, IO_Segment elem2,
				     IO_Segment elem3, IO_Segment elem4,
				     IO_Segment elem5, IO_Segment elem6);
#define IO_makeSegmentList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_IO_makeSegmentList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
IO_File IO_makeFileFile (IO_Path path, const char *name,
			 const char *extension);
IO_Path IO_makePathAbsolute (IO_SegmentList list);
IO_Path IO_makePathRelative (IO_SegmentList list);
IO_Segment IO_makeSegmentSegment (const char *name);
IO_SegmentList IO_makeSegmentListEmpty (void);
IO_SegmentList IO_makeSegmentListSingle (IO_Segment head);
IO_SegmentList IO_makeSegmentListMany (IO_Segment head, IO_SegmentList tail);
IO_StrChar IO_makeStrCharStrChar (const char *string);
IO_StrCon IO_makeStrConStrCon (const char *string);
#ifdef FAST_API
#define IO_isEqualFile(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _IO_isEqualFile (IO_File arg0, IO_File arg1);
#define IO_isEqualFile(arg0, arg1) (_IO_isEqualFile(arg0, arg1))
#endif
#ifdef FAST_API
#define IO_isEqualPath(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _IO_isEqualPath (IO_Path arg0, IO_Path arg1);
#define IO_isEqualPath(arg0, arg1) (_IO_isEqualPath(arg0, arg1))
#endif
#ifdef FAST_API
#define IO_isEqualSegment(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _IO_isEqualSegment (IO_Segment arg0, IO_Segment arg1);
#define IO_isEqualSegment(arg0, arg1) (_IO_isEqualSegment(arg0, arg1))
#endif
#ifdef FAST_API
#define IO_isEqualSegmentList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _IO_isEqualSegmentList (IO_SegmentList arg0, IO_SegmentList arg1);
#define IO_isEqualSegmentList(arg0, arg1) (_IO_isEqualSegmentList(arg0, arg1))
#endif
#ifdef FAST_API
#define IO_isEqualStrChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _IO_isEqualStrChar (IO_StrChar arg0, IO_StrChar arg1);
#define IO_isEqualStrChar(arg0, arg1) (_IO_isEqualStrChar(arg0, arg1))
#endif
#ifdef FAST_API
#define IO_isEqualStrCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _IO_isEqualStrCon (IO_StrCon arg0, IO_StrCon arg1);
#define IO_isEqualStrCon(arg0, arg1) (_IO_isEqualStrCon(arg0, arg1))
#endif
ATbool IO_isValidFile (IO_File arg);
inline ATbool IO_isFileFile (IO_File arg);
ATbool IO_hasFilePath (IO_File arg);
ATbool IO_hasFileName (IO_File arg);
ATbool IO_hasFileExtension (IO_File arg);
IO_Path IO_getFilePath (IO_File arg);
char *IO_getFileName (IO_File arg);
char *IO_getFileExtension (IO_File arg);
IO_File IO_setFilePath (IO_File arg, IO_Path path);
IO_File IO_setFileName (IO_File arg, const char *name);
IO_File IO_setFileExtension (IO_File arg, const char *extension);
ATbool IO_isValidPath (IO_Path arg);
inline ATbool IO_isPathAbsolute (IO_Path arg);
inline ATbool IO_isPathRelative (IO_Path arg);
ATbool IO_hasPathList (IO_Path arg);
IO_SegmentList IO_getPathList (IO_Path arg);
IO_Path IO_setPathList (IO_Path arg, IO_SegmentList list);
ATbool IO_isValidSegment (IO_Segment arg);
inline ATbool IO_isSegmentSegment (IO_Segment arg);
ATbool IO_hasSegmentName (IO_Segment arg);
char *IO_getSegmentName (IO_Segment arg);
IO_Segment IO_setSegmentName (IO_Segment arg, const char *name);
ATbool IO_isValidSegmentList (IO_SegmentList arg);
inline ATbool IO_isSegmentListEmpty (IO_SegmentList arg);
inline ATbool IO_isSegmentListSingle (IO_SegmentList arg);
inline ATbool IO_isSegmentListMany (IO_SegmentList arg);
ATbool IO_hasSegmentListHead (IO_SegmentList arg);
ATbool IO_hasSegmentListTail (IO_SegmentList arg);
IO_Segment IO_getSegmentListHead (IO_SegmentList arg);
IO_SegmentList IO_getSegmentListTail (IO_SegmentList arg);
IO_SegmentList IO_setSegmentListHead (IO_SegmentList arg, IO_Segment head);
IO_SegmentList IO_setSegmentListTail (IO_SegmentList arg,
				      IO_SegmentList tail);
ATbool IO_isValidStrChar (IO_StrChar arg);
inline ATbool IO_isStrCharStrChar (IO_StrChar arg);
ATbool IO_hasStrCharString (IO_StrChar arg);
char *IO_getStrCharString (IO_StrChar arg);
IO_StrChar IO_setStrCharString (IO_StrChar arg, const char *string);
ATbool IO_isValidStrCon (IO_StrCon arg);
inline ATbool IO_isStrConStrCon (IO_StrCon arg);
ATbool IO_hasStrConString (IO_StrCon arg);
char *IO_getStrConString (IO_StrCon arg);
IO_StrCon IO_setStrConString (IO_StrCon arg, const char *string);
IO_File IO_visitFile (IO_File arg, IO_Path (*acceptPath) (IO_Path),
		      char *(*acceptName) (char *),
		      char *(*acceptExtension) (char *));
IO_Path IO_visitPath (IO_Path arg,
		      IO_SegmentList (*acceptList) (IO_SegmentList));
IO_Segment IO_visitSegment (IO_Segment arg, char *(*acceptName) (char *));
IO_SegmentList IO_visitSegmentList (IO_SegmentList arg,
				    IO_Segment (*acceptHead) (IO_Segment));
IO_StrChar IO_visitStrChar (IO_StrChar arg, char *(*acceptString) (char *));
IO_StrCon IO_visitStrCon (IO_StrCon arg, char *(*acceptString) (char *));

#endif /* _IO_H */
