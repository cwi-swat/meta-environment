#ifndef _IO_H
#define _IO_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "IO_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _IO_File *IO_File;
typedef struct _IO_Path *IO_Path;
typedef struct _IO_Segment *IO_Segment;
typedef struct _IO_SegmentList *IO_SegmentList;
typedef struct _IO_StrChar *IO_StrChar;
typedef struct _IO_StrCon *IO_StrCon;

/*}}}  */

void IO_initIOApi (void);

/*{{{  protect functions */

void IO_protectFile (IO_File * arg);
void IO_protectPath (IO_Path * arg);
void IO_protectSegment (IO_Segment * arg);
void IO_protectSegmentList (IO_SegmentList * arg);
void IO_protectStrChar (IO_StrChar * arg);
void IO_protectStrCon (IO_StrCon * arg);

/*}}}  */
/*{{{  term conversion functions */

IO_File IO_FileFromTerm (ATerm t);
ATerm IO_FileToTerm (IO_File arg);
IO_Path IO_PathFromTerm (ATerm t);
ATerm IO_PathToTerm (IO_Path arg);
IO_Segment IO_SegmentFromTerm (ATerm t);
ATerm IO_SegmentToTerm (IO_Segment arg);
IO_SegmentList IO_SegmentListFromTerm (ATerm t);
ATerm IO_SegmentListToTerm (IO_SegmentList arg);
IO_StrChar IO_StrCharFromTerm (ATerm t);
ATerm IO_StrCharToTerm (IO_StrChar arg);
IO_StrCon IO_StrConFromTerm (ATerm t);
ATerm IO_StrConToTerm (IO_StrCon arg);

/*}}}  */
/*{{{  list functions */

int IO_getSegmentListLength (IO_SegmentList arg);
IO_SegmentList IO_reverseSegmentList (IO_SegmentList arg);
IO_SegmentList IO_appendSegmentList (IO_SegmentList arg, IO_Segment elem);
IO_SegmentList IO_concatSegmentList (IO_SegmentList arg0,
				     IO_SegmentList arg1);
IO_SegmentList IO_sliceSegmentList (IO_SegmentList arg, int start, int end);
IO_Segment IO_getSegmentListSegmentAt (IO_SegmentList arg, int index);
IO_SegmentList IO_replaceSegmentListSegmentAt (IO_SegmentList arg,
					       IO_Segment elem, int index);
IO_SegmentList IO_makeSegmentList2 (IO_Segment elem1, IO_Segment elem2);
IO_SegmentList IO_makeSegmentList3 (IO_Segment elem1, IO_Segment elem2,
				    IO_Segment elem3);
IO_SegmentList IO_makeSegmentList4 (IO_Segment elem1, IO_Segment elem2,
				    IO_Segment elem3, IO_Segment elem4);
IO_SegmentList IO_makeSegmentList5 (IO_Segment elem1, IO_Segment elem2,
				    IO_Segment elem3, IO_Segment elem4,
				    IO_Segment elem5);
IO_SegmentList IO_makeSegmentList6 (IO_Segment elem1, IO_Segment elem2,
				    IO_Segment elem3, IO_Segment elem4,
				    IO_Segment elem5, IO_Segment elem6);

/*}}}  */
/*{{{  constructors */

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

/*}}}  */
/*{{{  equality functions */

ATbool IO_isEqualFile (IO_File arg0, IO_File arg1);
ATbool IO_isEqualPath (IO_Path arg0, IO_Path arg1);
ATbool IO_isEqualSegment (IO_Segment arg0, IO_Segment arg1);
ATbool IO_isEqualSegmentList (IO_SegmentList arg0, IO_SegmentList arg1);
ATbool IO_isEqualStrChar (IO_StrChar arg0, IO_StrChar arg1);
ATbool IO_isEqualStrCon (IO_StrCon arg0, IO_StrCon arg1);

/*}}}  */
/*{{{  IO_File accessors */

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

/*}}}  */
/*{{{  IO_Path accessors */

ATbool IO_isValidPath (IO_Path arg);
inline ATbool IO_isPathAbsolute (IO_Path arg);
inline ATbool IO_isPathRelative (IO_Path arg);
ATbool IO_hasPathList (IO_Path arg);
IO_SegmentList IO_getPathList (IO_Path arg);
IO_Path IO_setPathList (IO_Path arg, IO_SegmentList list);

/*}}}  */
/*{{{  IO_Segment accessors */

ATbool IO_isValidSegment (IO_Segment arg);
inline ATbool IO_isSegmentSegment (IO_Segment arg);
ATbool IO_hasSegmentName (IO_Segment arg);
char *IO_getSegmentName (IO_Segment arg);
IO_Segment IO_setSegmentName (IO_Segment arg, const char *name);

/*}}}  */
/*{{{  IO_SegmentList accessors */

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

/*}}}  */
/*{{{  IO_StrChar accessors */

ATbool IO_isValidStrChar (IO_StrChar arg);
inline ATbool IO_isStrCharStrChar (IO_StrChar arg);
ATbool IO_hasStrCharString (IO_StrChar arg);
char *IO_getStrCharString (IO_StrChar arg);
IO_StrChar IO_setStrCharString (IO_StrChar arg, const char *string);

/*}}}  */
/*{{{  IO_StrCon accessors */

ATbool IO_isValidStrCon (IO_StrCon arg);
inline ATbool IO_isStrConStrCon (IO_StrCon arg);
ATbool IO_hasStrConString (IO_StrCon arg);
char *IO_getStrConString (IO_StrCon arg);
IO_StrCon IO_setStrConString (IO_StrCon arg, const char *string);

/*}}}  */
/*{{{  sort visitors */

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

/*}}}  */

#endif /* _IO_H */
