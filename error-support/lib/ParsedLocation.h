#ifndef _PARSEDLOCATION_H
#define _PARSEDLOCATION_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "ParsedLocation_dict.h"

typedef struct _PLOC_OptLayout *PLOC_OptLayout;
typedef struct _PLOC_Layout *PLOC_Layout;
typedef struct _PLOC_LexLayoutList *PLOC_LexLayoutList;
typedef struct _PLOC_LexStrChar *PLOC_LexStrChar;
typedef struct _PLOC_StrChar *PLOC_StrChar;
typedef struct _PLOC_LexStrCon *PLOC_LexStrCon;
typedef struct _PLOC_StrCon *PLOC_StrCon;
typedef struct _PLOC_LexStrCharChars *PLOC_LexStrCharChars;
typedef struct _PLOC_LexNatCon *PLOC_LexNatCon;
typedef struct _PLOC_NatCon *PLOC_NatCon;
typedef struct _PLOC_LexLayout *PLOC_LexLayout;
typedef struct _PLOC_Location *PLOC_Location;
typedef struct _PLOC_Area *PLOC_Area;
typedef struct _PLOC_Slice *PLOC_Slice;
typedef struct _PLOC_AreaAreas *PLOC_AreaAreas;

#ifdef FAST_API
#define PLOC_initParsedLocationApi() (init_ParsedLocation_dict())
#else
void _PLOC_initParsedLocationApi (void);
#define PLOC_initParsedLocationApi() (_PLOC_initParsedLocationApi())
#endif

#ifdef FAST_API
#define PLOC_protectOptLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_protectOptLayout (PLOC_OptLayout * arg);
#define PLOC_protectOptLayout(arg) (_PLOC_protectOptLayout(arg))
#endif
#ifdef FAST_API
#define PLOC_unprotectOptLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_unprotectOptLayout (PLOC_OptLayout * arg);
#define PLOC_unprotectOptLayout(arg) (_PLOC_unprotectOptLayout(arg))
#endif
#ifdef FAST_API
#define PLOC_protectLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_protectLayout (PLOC_Layout * arg);
#define PLOC_protectLayout(arg) (_PLOC_protectLayout(arg))
#endif
#ifdef FAST_API
#define PLOC_unprotectLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_unprotectLayout (PLOC_Layout * arg);
#define PLOC_unprotectLayout(arg) (_PLOC_unprotectLayout(arg))
#endif
#ifdef FAST_API
#define PLOC_protectLexLayoutList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_protectLexLayoutList (PLOC_LexLayoutList * arg);
#define PLOC_protectLexLayoutList(arg) (_PLOC_protectLexLayoutList(arg))
#endif
#ifdef FAST_API
#define PLOC_unprotectLexLayoutList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_unprotectLexLayoutList (PLOC_LexLayoutList * arg);
#define PLOC_unprotectLexLayoutList(arg) (_PLOC_unprotectLexLayoutList(arg))
#endif
#ifdef FAST_API
#define PLOC_protectLexStrChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_protectLexStrChar (PLOC_LexStrChar * arg);
#define PLOC_protectLexStrChar(arg) (_PLOC_protectLexStrChar(arg))
#endif
#ifdef FAST_API
#define PLOC_unprotectLexStrChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_unprotectLexStrChar (PLOC_LexStrChar * arg);
#define PLOC_unprotectLexStrChar(arg) (_PLOC_unprotectLexStrChar(arg))
#endif
#ifdef FAST_API
#define PLOC_protectStrChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_protectStrChar (PLOC_StrChar * arg);
#define PLOC_protectStrChar(arg) (_PLOC_protectStrChar(arg))
#endif
#ifdef FAST_API
#define PLOC_unprotectStrChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_unprotectStrChar (PLOC_StrChar * arg);
#define PLOC_unprotectStrChar(arg) (_PLOC_unprotectStrChar(arg))
#endif
#ifdef FAST_API
#define PLOC_protectLexStrCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_protectLexStrCon (PLOC_LexStrCon * arg);
#define PLOC_protectLexStrCon(arg) (_PLOC_protectLexStrCon(arg))
#endif
#ifdef FAST_API
#define PLOC_unprotectLexStrCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_unprotectLexStrCon (PLOC_LexStrCon * arg);
#define PLOC_unprotectLexStrCon(arg) (_PLOC_unprotectLexStrCon(arg))
#endif
#ifdef FAST_API
#define PLOC_protectStrCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_protectStrCon (PLOC_StrCon * arg);
#define PLOC_protectStrCon(arg) (_PLOC_protectStrCon(arg))
#endif
#ifdef FAST_API
#define PLOC_unprotectStrCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_unprotectStrCon (PLOC_StrCon * arg);
#define PLOC_unprotectStrCon(arg) (_PLOC_unprotectStrCon(arg))
#endif
#ifdef FAST_API
#define PLOC_protectLexStrCharChars(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_protectLexStrCharChars (PLOC_LexStrCharChars * arg);
#define PLOC_protectLexStrCharChars(arg) (_PLOC_protectLexStrCharChars(arg))
#endif
#ifdef FAST_API
#define PLOC_unprotectLexStrCharChars(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_unprotectLexStrCharChars (PLOC_LexStrCharChars * arg);
#define PLOC_unprotectLexStrCharChars(arg) (_PLOC_unprotectLexStrCharChars(arg))
#endif
#ifdef FAST_API
#define PLOC_protectLexNatCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_protectLexNatCon (PLOC_LexNatCon * arg);
#define PLOC_protectLexNatCon(arg) (_PLOC_protectLexNatCon(arg))
#endif
#ifdef FAST_API
#define PLOC_unprotectLexNatCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_unprotectLexNatCon (PLOC_LexNatCon * arg);
#define PLOC_unprotectLexNatCon(arg) (_PLOC_unprotectLexNatCon(arg))
#endif
#ifdef FAST_API
#define PLOC_protectNatCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_protectNatCon (PLOC_NatCon * arg);
#define PLOC_protectNatCon(arg) (_PLOC_protectNatCon(arg))
#endif
#ifdef FAST_API
#define PLOC_unprotectNatCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_unprotectNatCon (PLOC_NatCon * arg);
#define PLOC_unprotectNatCon(arg) (_PLOC_unprotectNatCon(arg))
#endif
#ifdef FAST_API
#define PLOC_protectLexLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_protectLexLayout (PLOC_LexLayout * arg);
#define PLOC_protectLexLayout(arg) (_PLOC_protectLexLayout(arg))
#endif
#ifdef FAST_API
#define PLOC_unprotectLexLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_unprotectLexLayout (PLOC_LexLayout * arg);
#define PLOC_unprotectLexLayout(arg) (_PLOC_unprotectLexLayout(arg))
#endif
#ifdef FAST_API
#define PLOC_protectLocation(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_protectLocation (PLOC_Location * arg);
#define PLOC_protectLocation(arg) (_PLOC_protectLocation(arg))
#endif
#ifdef FAST_API
#define PLOC_unprotectLocation(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_unprotectLocation (PLOC_Location * arg);
#define PLOC_unprotectLocation(arg) (_PLOC_unprotectLocation(arg))
#endif
#ifdef FAST_API
#define PLOC_protectArea(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_protectArea (PLOC_Area * arg);
#define PLOC_protectArea(arg) (_PLOC_protectArea(arg))
#endif
#ifdef FAST_API
#define PLOC_unprotectArea(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_unprotectArea (PLOC_Area * arg);
#define PLOC_unprotectArea(arg) (_PLOC_unprotectArea(arg))
#endif
#ifdef FAST_API
#define PLOC_protectSlice(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_protectSlice (PLOC_Slice * arg);
#define PLOC_protectSlice(arg) (_PLOC_protectSlice(arg))
#endif
#ifdef FAST_API
#define PLOC_unprotectSlice(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_unprotectSlice (PLOC_Slice * arg);
#define PLOC_unprotectSlice(arg) (_PLOC_unprotectSlice(arg))
#endif
#ifdef FAST_API
#define PLOC_protectAreaAreas(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_protectAreaAreas (PLOC_AreaAreas * arg);
#define PLOC_protectAreaAreas(arg) (_PLOC_protectAreaAreas(arg))
#endif
#ifdef FAST_API
#define PLOC_unprotectAreaAreas(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PLOC_unprotectAreaAreas (PLOC_AreaAreas * arg);
#define PLOC_unprotectAreaAreas(arg) (_PLOC_unprotectAreaAreas(arg))
#endif
#ifdef FAST_API
#define PLOC_OptLayoutFromTerm(t) ((((union {PLOC_OptLayout target; ATerm source; })(t)).target))
#else
PLOC_OptLayout _PLOC_OptLayoutFromTerm (ATerm t);
#define PLOC_OptLayoutFromTerm(t) (_PLOC_OptLayoutFromTerm(t))
#endif
#ifdef FAST_API
#define PLOC_OptLayoutToTerm(arg) ((((union {PLOC_OptLayout source; ATerm target; })(arg)).target))
#else
ATerm _PLOC_OptLayoutToTerm (PLOC_OptLayout arg);
#define PLOC_OptLayoutToTerm(arg) (_PLOC_OptLayoutToTerm(arg))
#endif
#ifdef FAST_API
#define PLOC_LayoutFromTerm(t) ((((union {PLOC_Layout target; ATerm source; })(t)).target))
#else
PLOC_Layout _PLOC_LayoutFromTerm (ATerm t);
#define PLOC_LayoutFromTerm(t) (_PLOC_LayoutFromTerm(t))
#endif
#ifdef FAST_API
#define PLOC_LayoutToTerm(arg) ((((union {PLOC_Layout source; ATerm target; })(arg)).target))
#else
ATerm _PLOC_LayoutToTerm (PLOC_Layout arg);
#define PLOC_LayoutToTerm(arg) (_PLOC_LayoutToTerm(arg))
#endif
#ifdef FAST_API
#define PLOC_LexLayoutListFromTerm(t) ((((union {PLOC_LexLayoutList target; ATerm source; })(t)).target))
#else
PLOC_LexLayoutList _PLOC_LexLayoutListFromTerm (ATerm t);
#define PLOC_LexLayoutListFromTerm(t) (_PLOC_LexLayoutListFromTerm(t))
#endif
#ifdef FAST_API
#define PLOC_LexLayoutListToTerm(arg) ((((union {PLOC_LexLayoutList source; ATerm target; })(arg)).target))
#else
ATerm _PLOC_LexLayoutListToTerm (PLOC_LexLayoutList arg);
#define PLOC_LexLayoutListToTerm(arg) (_PLOC_LexLayoutListToTerm(arg))
#endif
#ifdef FAST_API
#define PLOC_LexStrCharFromTerm(t) ((((union {PLOC_LexStrChar target; ATerm source; })(t)).target))
#else
PLOC_LexStrChar _PLOC_LexStrCharFromTerm (ATerm t);
#define PLOC_LexStrCharFromTerm(t) (_PLOC_LexStrCharFromTerm(t))
#endif
#ifdef FAST_API
#define PLOC_LexStrCharToTerm(arg) ((((union {PLOC_LexStrChar source; ATerm target; })(arg)).target))
#else
ATerm _PLOC_LexStrCharToTerm (PLOC_LexStrChar arg);
#define PLOC_LexStrCharToTerm(arg) (_PLOC_LexStrCharToTerm(arg))
#endif
#ifdef FAST_API
#define PLOC_StrCharFromTerm(t) ((((union {PLOC_StrChar target; ATerm source; })(t)).target))
#else
PLOC_StrChar _PLOC_StrCharFromTerm (ATerm t);
#define PLOC_StrCharFromTerm(t) (_PLOC_StrCharFromTerm(t))
#endif
#ifdef FAST_API
#define PLOC_StrCharToTerm(arg) ((((union {PLOC_StrChar source; ATerm target; })(arg)).target))
#else
ATerm _PLOC_StrCharToTerm (PLOC_StrChar arg);
#define PLOC_StrCharToTerm(arg) (_PLOC_StrCharToTerm(arg))
#endif
#ifdef FAST_API
#define PLOC_LexStrConFromTerm(t) ((((union {PLOC_LexStrCon target; ATerm source; })(t)).target))
#else
PLOC_LexStrCon _PLOC_LexStrConFromTerm (ATerm t);
#define PLOC_LexStrConFromTerm(t) (_PLOC_LexStrConFromTerm(t))
#endif
#ifdef FAST_API
#define PLOC_LexStrConToTerm(arg) ((((union {PLOC_LexStrCon source; ATerm target; })(arg)).target))
#else
ATerm _PLOC_LexStrConToTerm (PLOC_LexStrCon arg);
#define PLOC_LexStrConToTerm(arg) (_PLOC_LexStrConToTerm(arg))
#endif
#ifdef FAST_API
#define PLOC_StrConFromTerm(t) ((((union {PLOC_StrCon target; ATerm source; })(t)).target))
#else
PLOC_StrCon _PLOC_StrConFromTerm (ATerm t);
#define PLOC_StrConFromTerm(t) (_PLOC_StrConFromTerm(t))
#endif
#ifdef FAST_API
#define PLOC_StrConToTerm(arg) ((((union {PLOC_StrCon source; ATerm target; })(arg)).target))
#else
ATerm _PLOC_StrConToTerm (PLOC_StrCon arg);
#define PLOC_StrConToTerm(arg) (_PLOC_StrConToTerm(arg))
#endif
#ifdef FAST_API
#define PLOC_LexStrCharCharsFromTerm(t) ((((union {PLOC_LexStrCharChars target; ATerm source; })(t)).target))
#else
PLOC_LexStrCharChars _PLOC_LexStrCharCharsFromTerm (ATerm t);
#define PLOC_LexStrCharCharsFromTerm(t) (_PLOC_LexStrCharCharsFromTerm(t))
#endif
#ifdef FAST_API
#define PLOC_LexStrCharCharsToTerm(arg) ((((union {PLOC_LexStrCharChars source; ATerm target; })(arg)).target))
#else
ATerm _PLOC_LexStrCharCharsToTerm (PLOC_LexStrCharChars arg);
#define PLOC_LexStrCharCharsToTerm(arg) (_PLOC_LexStrCharCharsToTerm(arg))
#endif
#ifdef FAST_API
#define PLOC_LexNatConFromTerm(t) ((((union {PLOC_LexNatCon target; ATerm source; })(t)).target))
#else
PLOC_LexNatCon _PLOC_LexNatConFromTerm (ATerm t);
#define PLOC_LexNatConFromTerm(t) (_PLOC_LexNatConFromTerm(t))
#endif
#ifdef FAST_API
#define PLOC_LexNatConToTerm(arg) ((((union {PLOC_LexNatCon source; ATerm target; })(arg)).target))
#else
ATerm _PLOC_LexNatConToTerm (PLOC_LexNatCon arg);
#define PLOC_LexNatConToTerm(arg) (_PLOC_LexNatConToTerm(arg))
#endif
#ifdef FAST_API
#define PLOC_NatConFromTerm(t) ((((union {PLOC_NatCon target; ATerm source; })(t)).target))
#else
PLOC_NatCon _PLOC_NatConFromTerm (ATerm t);
#define PLOC_NatConFromTerm(t) (_PLOC_NatConFromTerm(t))
#endif
#ifdef FAST_API
#define PLOC_NatConToTerm(arg) ((((union {PLOC_NatCon source; ATerm target; })(arg)).target))
#else
ATerm _PLOC_NatConToTerm (PLOC_NatCon arg);
#define PLOC_NatConToTerm(arg) (_PLOC_NatConToTerm(arg))
#endif
#ifdef FAST_API
#define PLOC_LexLayoutFromTerm(t) ((((union {PLOC_LexLayout target; ATerm source; })(t)).target))
#else
PLOC_LexLayout _PLOC_LexLayoutFromTerm (ATerm t);
#define PLOC_LexLayoutFromTerm(t) (_PLOC_LexLayoutFromTerm(t))
#endif
#ifdef FAST_API
#define PLOC_LexLayoutToTerm(arg) ((((union {PLOC_LexLayout source; ATerm target; })(arg)).target))
#else
ATerm _PLOC_LexLayoutToTerm (PLOC_LexLayout arg);
#define PLOC_LexLayoutToTerm(arg) (_PLOC_LexLayoutToTerm(arg))
#endif
#ifdef FAST_API
#define PLOC_LocationFromTerm(t) ((((union {PLOC_Location target; ATerm source; })(t)).target))
#else
PLOC_Location _PLOC_LocationFromTerm (ATerm t);
#define PLOC_LocationFromTerm(t) (_PLOC_LocationFromTerm(t))
#endif
#ifdef FAST_API
#define PLOC_LocationToTerm(arg) ((((union {PLOC_Location source; ATerm target; })(arg)).target))
#else
ATerm _PLOC_LocationToTerm (PLOC_Location arg);
#define PLOC_LocationToTerm(arg) (_PLOC_LocationToTerm(arg))
#endif
#ifdef FAST_API
#define PLOC_AreaFromTerm(t) ((((union {PLOC_Area target; ATerm source; })(t)).target))
#else
PLOC_Area _PLOC_AreaFromTerm (ATerm t);
#define PLOC_AreaFromTerm(t) (_PLOC_AreaFromTerm(t))
#endif
#ifdef FAST_API
#define PLOC_AreaToTerm(arg) ((((union {PLOC_Area source; ATerm target; })(arg)).target))
#else
ATerm _PLOC_AreaToTerm (PLOC_Area arg);
#define PLOC_AreaToTerm(arg) (_PLOC_AreaToTerm(arg))
#endif
#ifdef FAST_API
#define PLOC_SliceFromTerm(t) ((((union {PLOC_Slice target; ATerm source; })(t)).target))
#else
PLOC_Slice _PLOC_SliceFromTerm (ATerm t);
#define PLOC_SliceFromTerm(t) (_PLOC_SliceFromTerm(t))
#endif
#ifdef FAST_API
#define PLOC_SliceToTerm(arg) ((((union {PLOC_Slice source; ATerm target; })(arg)).target))
#else
ATerm _PLOC_SliceToTerm (PLOC_Slice arg);
#define PLOC_SliceToTerm(arg) (_PLOC_SliceToTerm(arg))
#endif
#ifdef FAST_API
#define PLOC_AreaAreasFromTerm(t) ((((union {PLOC_AreaAreas target; ATerm source; })(t)).target))
#else
PLOC_AreaAreas _PLOC_AreaAreasFromTerm (ATerm t);
#define PLOC_AreaAreasFromTerm(t) (_PLOC_AreaAreasFromTerm(t))
#endif
#ifdef FAST_API
#define PLOC_AreaAreasToTerm(arg) ((((union {PLOC_AreaAreas source; ATerm target; })(arg)).target))
#else
ATerm _PLOC_AreaAreasToTerm (PLOC_AreaAreas arg);
#define PLOC_AreaAreasToTerm(arg) (_PLOC_AreaAreasToTerm(arg))
#endif
#ifdef FAST_API
#define PLOC_getLexLayoutListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PLOC_getLexLayoutListLength (PLOC_LexLayoutList arg);
#define PLOC_getLexLayoutListLength(arg) (_PLOC_getLexLayoutListLength(arg))
#endif
#ifdef FAST_API
#define PLOC_reverseLexLayoutList(arg) ((PLOC_LexLayoutList) ATreverse((ATermList) (arg)))
#else
PLOC_LexLayoutList _PLOC_reverseLexLayoutList (PLOC_LexLayoutList arg);
#define PLOC_reverseLexLayoutList(arg) (_PLOC_reverseLexLayoutList(arg))
#endif
#ifdef FAST_API
#define PLOC_appendLexLayoutList(arg, elem) ((PLOC_LexLayoutList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PLOC_LexLayoutList _PLOC_appendLexLayoutList (PLOC_LexLayoutList arg,
					      PLOC_LexLayout elem);
#define PLOC_appendLexLayoutList(arg, elem) (_PLOC_appendLexLayoutList(arg, elem))
#endif
#ifdef FAST_API
#define PLOC_concatLexLayoutList(arg0, arg1) ((PLOC_LexLayoutList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PLOC_LexLayoutList _PLOC_concatLexLayoutList (PLOC_LexLayoutList arg0,
					      PLOC_LexLayoutList arg1);
#define PLOC_concatLexLayoutList(arg0, arg1) (_PLOC_concatLexLayoutList(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_sliceLexLayoutList(arg, start, end) ((PLOC_LexLayoutList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PLOC_LexLayoutList _PLOC_sliceLexLayoutList (PLOC_LexLayoutList arg,
					     int start, int end);
#define PLOC_sliceLexLayoutList(arg, start, end) (_PLOC_sliceLexLayoutList(arg, start, end))
#endif
#ifdef FAST_API
#define PLOC_getLexLayoutListLexLayoutAt(arg, index) ((PLOC_LexLayout) (ATelementAt((ATermList) arg,index)))
#else
PLOC_LexLayout _PLOC_getLexLayoutListLexLayoutAt (PLOC_LexLayoutList arg,
						  int index);
#define PLOC_getLexLayoutListLexLayoutAt(arg, index) (_PLOC_getLexLayoutListLexLayoutAt(arg, index))
#endif
#ifdef FAST_API
#define PLOC_replaceLexLayoutListLexLayoutAt(arg, elem, index) ((PLOC_LexLayoutList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PLOC_LexLayoutList _PLOC_replaceLexLayoutListLexLayoutAt (PLOC_LexLayoutList
							  arg,
							  PLOC_LexLayout elem,
							  int index);
#define PLOC_replaceLexLayoutListLexLayoutAt(arg, elem, index) (_PLOC_replaceLexLayoutListLexLayoutAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PLOC_makeLexLayoutList2(elem1,  elem2) ((PLOC_LexLayoutList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PLOC_LexLayoutList _PLOC_makeLexLayoutList2 (PLOC_LexLayout elem1,
					     PLOC_LexLayout elem2);
#define PLOC_makeLexLayoutList2(elem1,  elem2) (_PLOC_makeLexLayoutList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PLOC_makeLexLayoutList3(elem1, elem2,  elem3) ((PLOC_LexLayoutList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PLOC_LexLayoutList _PLOC_makeLexLayoutList3 (PLOC_LexLayout elem1,
					     PLOC_LexLayout elem2,
					     PLOC_LexLayout elem3);
#define PLOC_makeLexLayoutList3(elem1, elem2,  elem3) (_PLOC_makeLexLayoutList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PLOC_makeLexLayoutList4(elem1, elem2, elem3,  elem4) ((PLOC_LexLayoutList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PLOC_LexLayoutList _PLOC_makeLexLayoutList4 (PLOC_LexLayout elem1,
					     PLOC_LexLayout elem2,
					     PLOC_LexLayout elem3,
					     PLOC_LexLayout elem4);
#define PLOC_makeLexLayoutList4(elem1, elem2, elem3,  elem4) (_PLOC_makeLexLayoutList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PLOC_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5) ((PLOC_LexLayoutList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PLOC_LexLayoutList _PLOC_makeLexLayoutList5 (PLOC_LexLayout elem1,
					     PLOC_LexLayout elem2,
					     PLOC_LexLayout elem3,
					     PLOC_LexLayout elem4,
					     PLOC_LexLayout elem5);
#define PLOC_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5) (_PLOC_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PLOC_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PLOC_LexLayoutList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PLOC_LexLayoutList _PLOC_makeLexLayoutList6 (PLOC_LexLayout elem1,
					     PLOC_LexLayout elem2,
					     PLOC_LexLayout elem3,
					     PLOC_LexLayout elem4,
					     PLOC_LexLayout elem5,
					     PLOC_LexLayout elem6);
#define PLOC_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PLOC_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define PLOC_getLexStrCharCharsLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PLOC_getLexStrCharCharsLength (PLOC_LexStrCharChars arg);
#define PLOC_getLexStrCharCharsLength(arg) (_PLOC_getLexStrCharCharsLength(arg))
#endif
#ifdef FAST_API
#define PLOC_reverseLexStrCharChars(arg) ((PLOC_LexStrCharChars) ATreverse((ATermList) (arg)))
#else
PLOC_LexStrCharChars _PLOC_reverseLexStrCharChars (PLOC_LexStrCharChars arg);
#define PLOC_reverseLexStrCharChars(arg) (_PLOC_reverseLexStrCharChars(arg))
#endif
#ifdef FAST_API
#define PLOC_appendLexStrCharChars(arg, elem) ((PLOC_LexStrCharChars) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PLOC_LexStrCharChars _PLOC_appendLexStrCharChars (PLOC_LexStrCharChars arg,
						  PLOC_LexStrChar elem);
#define PLOC_appendLexStrCharChars(arg, elem) (_PLOC_appendLexStrCharChars(arg, elem))
#endif
#ifdef FAST_API
#define PLOC_concatLexStrCharChars(arg0, arg1) ((PLOC_LexStrCharChars) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PLOC_LexStrCharChars _PLOC_concatLexStrCharChars (PLOC_LexStrCharChars arg0,
						  PLOC_LexStrCharChars arg1);
#define PLOC_concatLexStrCharChars(arg0, arg1) (_PLOC_concatLexStrCharChars(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_sliceLexStrCharChars(arg, start, end) ((PLOC_LexStrCharChars) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PLOC_LexStrCharChars _PLOC_sliceLexStrCharChars (PLOC_LexStrCharChars arg,
						 int start, int end);
#define PLOC_sliceLexStrCharChars(arg, start, end) (_PLOC_sliceLexStrCharChars(arg, start, end))
#endif
#ifdef FAST_API
#define PLOC_getLexStrCharCharsLexStrCharAt(arg, index) ((PLOC_LexStrChar) (ATelementAt((ATermList) arg,index)))
#else
PLOC_LexStrChar _PLOC_getLexStrCharCharsLexStrCharAt (PLOC_LexStrCharChars
						      arg, int index);
#define PLOC_getLexStrCharCharsLexStrCharAt(arg, index) (_PLOC_getLexStrCharCharsLexStrCharAt(arg, index))
#endif
#ifdef FAST_API
#define PLOC_replaceLexStrCharCharsLexStrCharAt(arg, elem, index) ((PLOC_LexStrCharChars) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PLOC_LexStrCharChars
_PLOC_replaceLexStrCharCharsLexStrCharAt (PLOC_LexStrCharChars arg,
					  PLOC_LexStrChar elem, int index);
#define PLOC_replaceLexStrCharCharsLexStrCharAt(arg, elem, index) (_PLOC_replaceLexStrCharCharsLexStrCharAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PLOC_makeLexStrCharChars2(elem1,  elem2) ((PLOC_LexStrCharChars) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PLOC_LexStrCharChars _PLOC_makeLexStrCharChars2 (PLOC_LexStrChar elem1,
						 PLOC_LexStrChar elem2);
#define PLOC_makeLexStrCharChars2(elem1,  elem2) (_PLOC_makeLexStrCharChars2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PLOC_makeLexStrCharChars3(elem1, elem2,  elem3) ((PLOC_LexStrCharChars) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PLOC_LexStrCharChars _PLOC_makeLexStrCharChars3 (PLOC_LexStrChar elem1,
						 PLOC_LexStrChar elem2,
						 PLOC_LexStrChar elem3);
#define PLOC_makeLexStrCharChars3(elem1, elem2,  elem3) (_PLOC_makeLexStrCharChars3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PLOC_makeLexStrCharChars4(elem1, elem2, elem3,  elem4) ((PLOC_LexStrCharChars) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PLOC_LexStrCharChars _PLOC_makeLexStrCharChars4 (PLOC_LexStrChar elem1,
						 PLOC_LexStrChar elem2,
						 PLOC_LexStrChar elem3,
						 PLOC_LexStrChar elem4);
#define PLOC_makeLexStrCharChars4(elem1, elem2, elem3,  elem4) (_PLOC_makeLexStrCharChars4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PLOC_makeLexStrCharChars5(elem1, elem2, elem3, elem4,  elem5) ((PLOC_LexStrCharChars) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PLOC_LexStrCharChars _PLOC_makeLexStrCharChars5 (PLOC_LexStrChar elem1,
						 PLOC_LexStrChar elem2,
						 PLOC_LexStrChar elem3,
						 PLOC_LexStrChar elem4,
						 PLOC_LexStrChar elem5);
#define PLOC_makeLexStrCharChars5(elem1, elem2, elem3, elem4,  elem5) (_PLOC_makeLexStrCharChars5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PLOC_makeLexStrCharChars6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PLOC_LexStrCharChars) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PLOC_LexStrCharChars _PLOC_makeLexStrCharChars6 (PLOC_LexStrChar elem1,
						 PLOC_LexStrChar elem2,
						 PLOC_LexStrChar elem3,
						 PLOC_LexStrChar elem4,
						 PLOC_LexStrChar elem5,
						 PLOC_LexStrChar elem6);
#define PLOC_makeLexStrCharChars6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PLOC_makeLexStrCharChars6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define PLOC_getAreaAreasLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _PLOC_getAreaAreasLength (PLOC_AreaAreas arg);
#define PLOC_getAreaAreasLength(arg) (_PLOC_getAreaAreasLength(arg))
#endif
PLOC_AreaAreas PLOC_reverseAreaAreas (PLOC_AreaAreas arg);
PLOC_AreaAreas PLOC_appendAreaAreas (PLOC_AreaAreas arg0,
				     PLOC_OptLayout wsAfterHead,
				     PLOC_OptLayout wsAfterSep,
				     PLOC_Area arg1);
PLOC_AreaAreas PLOC_concatAreaAreas (PLOC_AreaAreas arg0,
				     PLOC_OptLayout wsAfterHead,
				     PLOC_OptLayout wsAfterSep,
				     PLOC_AreaAreas arg1);
#ifdef FAST_API
#define PLOC_sliceAreaAreas(arg, start, end) ((PLOC_AreaAreas) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
PLOC_AreaAreas _PLOC_sliceAreaAreas (PLOC_AreaAreas arg, int start, int end);
#define PLOC_sliceAreaAreas(arg, start, end) (_PLOC_sliceAreaAreas(arg, start, end))
#endif
#ifdef FAST_API
#define PLOC_getAreaAreasAreaAt(arg, index) ((PLOC_Area) (ATelementAt((ATermList) arg,index * 4)))
#else
PLOC_Area _PLOC_getAreaAreasAreaAt (PLOC_AreaAreas arg, int index);
#define PLOC_getAreaAreasAreaAt(arg, index) (_PLOC_getAreaAreasAreaAt(arg, index))
#endif
#ifdef FAST_API
#define PLOC_replaceAreaAreasAreaAt(arg, elem, index) ((PLOC_AreaAreas) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
PLOC_AreaAreas _PLOC_replaceAreaAreasAreaAt (PLOC_AreaAreas arg,
					     PLOC_Area elem, int index);
#define PLOC_replaceAreaAreasAreaAt(arg, elem, index) (_PLOC_replaceAreaAreasAreaAt(arg, elem, index))
#endif
PLOC_AreaAreas PLOC_makeAreaAreas2 (PLOC_OptLayout wsAfterHead,
				    PLOC_OptLayout wsAfterSep,
				    PLOC_Area elem1, PLOC_Area elem2);
PLOC_AreaAreas PLOC_makeAreaAreas3 (PLOC_OptLayout wsAfterHead,
				    PLOC_OptLayout wsAfterSep,
				    PLOC_Area elem1, PLOC_Area elem2,
				    PLOC_Area elem3);
PLOC_AreaAreas PLOC_makeAreaAreas4 (PLOC_OptLayout wsAfterHead,
				    PLOC_OptLayout wsAfterSep,
				    PLOC_Area elem1, PLOC_Area elem2,
				    PLOC_Area elem3, PLOC_Area elem4);
PLOC_AreaAreas PLOC_makeAreaAreas5 (PLOC_OptLayout wsAfterHead,
				    PLOC_OptLayout wsAfterSep,
				    PLOC_Area elem1, PLOC_Area elem2,
				    PLOC_Area elem3, PLOC_Area elem4,
				    PLOC_Area elem5);
PLOC_AreaAreas PLOC_makeAreaAreas6 (PLOC_OptLayout wsAfterHead,
				    PLOC_OptLayout wsAfterSep,
				    PLOC_Area elem1, PLOC_Area elem2,
				    PLOC_Area elem3, PLOC_Area elem4,
				    PLOC_Area elem5, PLOC_Area elem6);
PLOC_OptLayout PLOC_makeOptLayoutAbsent (void);
PLOC_OptLayout PLOC_makeOptLayoutPresent (PLOC_Layout layout);
PLOC_Layout PLOC_makeLayoutLexToCf (PLOC_LexLayoutList list);
PLOC_LexLayoutList PLOC_makeLexLayoutListEmpty (void);
PLOC_LexLayoutList PLOC_makeLexLayoutListSingle (PLOC_LexLayout head);
PLOC_LexLayoutList PLOC_makeLexLayoutListMany (PLOC_LexLayout head,
					       PLOC_LexLayoutList tail);
PLOC_LexStrChar PLOC_makeLexStrCharNewline (void);
PLOC_LexStrChar PLOC_makeLexStrCharTab (void);
PLOC_LexStrChar PLOC_makeLexStrCharQuote (void);
PLOC_LexStrChar PLOC_makeLexStrCharBackslash (void);
PLOC_LexStrChar PLOC_makeLexStrCharDecimal (char a, char b, char c);
PLOC_LexStrChar PLOC_makeLexStrCharNormal (char ch);
PLOC_StrChar PLOC_makeStrCharLexToCf (PLOC_LexStrChar StrChar);
PLOC_LexStrCon PLOC_makeLexStrConDefault (PLOC_LexStrCharChars chars);
PLOC_StrCon PLOC_makeStrConLexToCf (PLOC_LexStrCon StrCon);
PLOC_LexStrCharChars PLOC_makeLexStrCharCharsEmpty (void);
PLOC_LexStrCharChars PLOC_makeLexStrCharCharsSingle (PLOC_LexStrChar head);
PLOC_LexStrCharChars PLOC_makeLexStrCharCharsMany (PLOC_LexStrChar head,
						   PLOC_LexStrCharChars tail);
PLOC_LexNatCon PLOC_makeLexNatConDigits (const char *list);
PLOC_NatCon PLOC_makeNatConLexToCf (PLOC_LexNatCon NatCon);
PLOC_LexLayout PLOC_makeLexLayoutWhitespace (char ch);
PLOC_Location PLOC_makeLocationFile (PLOC_OptLayout wsAfterFile,
				     PLOC_OptLayout wsAfterParenOpen,
				     PLOC_StrCon filename,
				     PLOC_OptLayout wsAfterFilename);
PLOC_Location PLOC_makeLocationArea (PLOC_OptLayout wsAfterA,
				     PLOC_OptLayout wsAfterParenOpen,
				     PLOC_Area Area,
				     PLOC_OptLayout wsAfterArea);
PLOC_Location PLOC_makeLocationAreaInFile (PLOC_OptLayout wsAfterAreaInFile,
					   PLOC_OptLayout wsAfterParenOpen,
					   PLOC_StrCon filename,
					   PLOC_OptLayout wsAfterFilename,
					   PLOC_OptLayout wsAfterComma,
					   PLOC_Area Area,
					   PLOC_OptLayout wsAfterArea);
PLOC_Area PLOC_makeAreaArea (PLOC_OptLayout wsAfterArea,
			     PLOC_OptLayout wsAfterParenOpen,
			     PLOC_NatCon beginLine,
			     PLOC_OptLayout wsAfterBeginLine,
			     PLOC_OptLayout wsAfterComma,
			     PLOC_NatCon beginColumn,
			     PLOC_OptLayout wsAfterBeginColumn,
			     PLOC_OptLayout wsAfterComma1,
			     PLOC_NatCon endLine,
			     PLOC_OptLayout wsAfterEndLine,
			     PLOC_OptLayout wsAfterComma2,
			     PLOC_NatCon endColumn,
			     PLOC_OptLayout wsAfterEndColumn,
			     PLOC_OptLayout wsAfterComma3, PLOC_NatCon offset,
			     PLOC_OptLayout wsAfterOffset,
			     PLOC_OptLayout wsAfterComma4, PLOC_NatCon length,
			     PLOC_OptLayout wsAfterLength);
PLOC_Slice PLOC_makeSliceSlice (PLOC_OptLayout wsAfterSlice,
				PLOC_OptLayout wsAfterParenOpen,
				PLOC_StrCon id, PLOC_OptLayout wsAfterId,
				PLOC_OptLayout wsAfterComma,
				PLOC_OptLayout wsAfterBracketOpen,
				PLOC_AreaAreas areas,
				PLOC_OptLayout wsAfterAreas,
				PLOC_OptLayout wsAfterBracketClose);
PLOC_AreaAreas PLOC_makeAreaAreasEmpty (void);
PLOC_AreaAreas PLOC_makeAreaAreasSingle (PLOC_Area head);
PLOC_AreaAreas PLOC_makeAreaAreasMany (PLOC_Area head,
				       PLOC_OptLayout wsAfterHead,
				       PLOC_OptLayout wsAfterSep,
				       PLOC_AreaAreas tail);
#ifdef FAST_API
#define PLOC_isEqualOptLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PLOC_isEqualOptLayout (PLOC_OptLayout arg0, PLOC_OptLayout arg1);
#define PLOC_isEqualOptLayout(arg0, arg1) (_PLOC_isEqualOptLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_isEqualLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PLOC_isEqualLayout (PLOC_Layout arg0, PLOC_Layout arg1);
#define PLOC_isEqualLayout(arg0, arg1) (_PLOC_isEqualLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_isEqualLexLayoutList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PLOC_isEqualLexLayoutList (PLOC_LexLayoutList arg0,
				   PLOC_LexLayoutList arg1);
#define PLOC_isEqualLexLayoutList(arg0, arg1) (_PLOC_isEqualLexLayoutList(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_isEqualLexStrChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PLOC_isEqualLexStrChar (PLOC_LexStrChar arg0, PLOC_LexStrChar arg1);
#define PLOC_isEqualLexStrChar(arg0, arg1) (_PLOC_isEqualLexStrChar(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_isEqualStrChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PLOC_isEqualStrChar (PLOC_StrChar arg0, PLOC_StrChar arg1);
#define PLOC_isEqualStrChar(arg0, arg1) (_PLOC_isEqualStrChar(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_isEqualLexStrCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PLOC_isEqualLexStrCon (PLOC_LexStrCon arg0, PLOC_LexStrCon arg1);
#define PLOC_isEqualLexStrCon(arg0, arg1) (_PLOC_isEqualLexStrCon(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_isEqualStrCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PLOC_isEqualStrCon (PLOC_StrCon arg0, PLOC_StrCon arg1);
#define PLOC_isEqualStrCon(arg0, arg1) (_PLOC_isEqualStrCon(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_isEqualLexStrCharChars(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PLOC_isEqualLexStrCharChars (PLOC_LexStrCharChars arg0,
				     PLOC_LexStrCharChars arg1);
#define PLOC_isEqualLexStrCharChars(arg0, arg1) (_PLOC_isEqualLexStrCharChars(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_isEqualLexNatCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PLOC_isEqualLexNatCon (PLOC_LexNatCon arg0, PLOC_LexNatCon arg1);
#define PLOC_isEqualLexNatCon(arg0, arg1) (_PLOC_isEqualLexNatCon(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_isEqualNatCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PLOC_isEqualNatCon (PLOC_NatCon arg0, PLOC_NatCon arg1);
#define PLOC_isEqualNatCon(arg0, arg1) (_PLOC_isEqualNatCon(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_isEqualLexLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PLOC_isEqualLexLayout (PLOC_LexLayout arg0, PLOC_LexLayout arg1);
#define PLOC_isEqualLexLayout(arg0, arg1) (_PLOC_isEqualLexLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_isEqualLocation(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PLOC_isEqualLocation (PLOC_Location arg0, PLOC_Location arg1);
#define PLOC_isEqualLocation(arg0, arg1) (_PLOC_isEqualLocation(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_isEqualArea(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PLOC_isEqualArea (PLOC_Area arg0, PLOC_Area arg1);
#define PLOC_isEqualArea(arg0, arg1) (_PLOC_isEqualArea(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_isEqualSlice(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PLOC_isEqualSlice (PLOC_Slice arg0, PLOC_Slice arg1);
#define PLOC_isEqualSlice(arg0, arg1) (_PLOC_isEqualSlice(arg0, arg1))
#endif
#ifdef FAST_API
#define PLOC_isEqualAreaAreas(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PLOC_isEqualAreaAreas (PLOC_AreaAreas arg0, PLOC_AreaAreas arg1);
#define PLOC_isEqualAreaAreas(arg0, arg1) (_PLOC_isEqualAreaAreas(arg0, arg1))
#endif
ATbool PLOC_isValidOptLayout (PLOC_OptLayout arg);
inline ATbool PLOC_isOptLayoutAbsent (PLOC_OptLayout arg);
inline ATbool PLOC_isOptLayoutPresent (PLOC_OptLayout arg);
ATbool PLOC_hasOptLayoutLayout (PLOC_OptLayout arg);
PLOC_Layout PLOC_getOptLayoutLayout (PLOC_OptLayout arg);
PLOC_OptLayout PLOC_setOptLayoutLayout (PLOC_OptLayout arg,
					PLOC_Layout layout);
ATbool PLOC_isValidLayout (PLOC_Layout arg);
inline ATbool PLOC_isLayoutLexToCf (PLOC_Layout arg);
ATbool PLOC_hasLayoutList (PLOC_Layout arg);
PLOC_LexLayoutList PLOC_getLayoutList (PLOC_Layout arg);
PLOC_Layout PLOC_setLayoutList (PLOC_Layout arg, PLOC_LexLayoutList list);
ATbool PLOC_isValidLexLayoutList (PLOC_LexLayoutList arg);
inline ATbool PLOC_isLexLayoutListEmpty (PLOC_LexLayoutList arg);
inline ATbool PLOC_isLexLayoutListSingle (PLOC_LexLayoutList arg);
inline ATbool PLOC_isLexLayoutListMany (PLOC_LexLayoutList arg);
ATbool PLOC_hasLexLayoutListHead (PLOC_LexLayoutList arg);
ATbool PLOC_hasLexLayoutListTail (PLOC_LexLayoutList arg);
PLOC_LexLayout PLOC_getLexLayoutListHead (PLOC_LexLayoutList arg);
PLOC_LexLayoutList PLOC_getLexLayoutListTail (PLOC_LexLayoutList arg);
PLOC_LexLayoutList PLOC_setLexLayoutListHead (PLOC_LexLayoutList arg,
					      PLOC_LexLayout head);
PLOC_LexLayoutList PLOC_setLexLayoutListTail (PLOC_LexLayoutList arg,
					      PLOC_LexLayoutList tail);
ATbool PLOC_isValidLexStrChar (PLOC_LexStrChar arg);
inline ATbool PLOC_isLexStrCharNewline (PLOC_LexStrChar arg);
inline ATbool PLOC_isLexStrCharTab (PLOC_LexStrChar arg);
inline ATbool PLOC_isLexStrCharQuote (PLOC_LexStrChar arg);
inline ATbool PLOC_isLexStrCharBackslash (PLOC_LexStrChar arg);
inline ATbool PLOC_isLexStrCharDecimal (PLOC_LexStrChar arg);
inline ATbool PLOC_isLexStrCharNormal (PLOC_LexStrChar arg);
ATbool PLOC_hasLexStrCharA (PLOC_LexStrChar arg);
ATbool PLOC_hasLexStrCharB (PLOC_LexStrChar arg);
ATbool PLOC_hasLexStrCharC (PLOC_LexStrChar arg);
ATbool PLOC_hasLexStrCharCh (PLOC_LexStrChar arg);
char PLOC_getLexStrCharA (PLOC_LexStrChar arg);
char PLOC_getLexStrCharB (PLOC_LexStrChar arg);
char PLOC_getLexStrCharC (PLOC_LexStrChar arg);
char PLOC_getLexStrCharCh (PLOC_LexStrChar arg);
PLOC_LexStrChar PLOC_setLexStrCharA (PLOC_LexStrChar arg, char a);
PLOC_LexStrChar PLOC_setLexStrCharB (PLOC_LexStrChar arg, char b);
PLOC_LexStrChar PLOC_setLexStrCharC (PLOC_LexStrChar arg, char c);
PLOC_LexStrChar PLOC_setLexStrCharCh (PLOC_LexStrChar arg, char ch);
ATbool PLOC_isValidStrChar (PLOC_StrChar arg);
inline ATbool PLOC_isStrCharLexToCf (PLOC_StrChar arg);
ATbool PLOC_hasStrCharStrChar (PLOC_StrChar arg);
PLOC_LexStrChar PLOC_getStrCharStrChar (PLOC_StrChar arg);
PLOC_StrChar PLOC_setStrCharStrChar (PLOC_StrChar arg,
				     PLOC_LexStrChar StrChar);
ATbool PLOC_isValidLexStrCon (PLOC_LexStrCon arg);
inline ATbool PLOC_isLexStrConDefault (PLOC_LexStrCon arg);
ATbool PLOC_hasLexStrConChars (PLOC_LexStrCon arg);
PLOC_LexStrCharChars PLOC_getLexStrConChars (PLOC_LexStrCon arg);
PLOC_LexStrCon PLOC_setLexStrConChars (PLOC_LexStrCon arg,
				       PLOC_LexStrCharChars chars);
ATbool PLOC_isValidStrCon (PLOC_StrCon arg);
inline ATbool PLOC_isStrConLexToCf (PLOC_StrCon arg);
ATbool PLOC_hasStrConStrCon (PLOC_StrCon arg);
PLOC_LexStrCon PLOC_getStrConStrCon (PLOC_StrCon arg);
PLOC_StrCon PLOC_setStrConStrCon (PLOC_StrCon arg, PLOC_LexStrCon StrCon);
ATbool PLOC_isValidLexStrCharChars (PLOC_LexStrCharChars arg);
inline ATbool PLOC_isLexStrCharCharsEmpty (PLOC_LexStrCharChars arg);
inline ATbool PLOC_isLexStrCharCharsSingle (PLOC_LexStrCharChars arg);
inline ATbool PLOC_isLexStrCharCharsMany (PLOC_LexStrCharChars arg);
ATbool PLOC_hasLexStrCharCharsHead (PLOC_LexStrCharChars arg);
ATbool PLOC_hasLexStrCharCharsTail (PLOC_LexStrCharChars arg);
PLOC_LexStrChar PLOC_getLexStrCharCharsHead (PLOC_LexStrCharChars arg);
PLOC_LexStrCharChars PLOC_getLexStrCharCharsTail (PLOC_LexStrCharChars arg);
PLOC_LexStrCharChars PLOC_setLexStrCharCharsHead (PLOC_LexStrCharChars arg,
						  PLOC_LexStrChar head);
PLOC_LexStrCharChars PLOC_setLexStrCharCharsTail (PLOC_LexStrCharChars arg,
						  PLOC_LexStrCharChars tail);
ATbool PLOC_isValidLexNatCon (PLOC_LexNatCon arg);
inline ATbool PLOC_isLexNatConDigits (PLOC_LexNatCon arg);
ATbool PLOC_hasLexNatConList (PLOC_LexNatCon arg);
char *PLOC_getLexNatConList (PLOC_LexNatCon arg);
PLOC_LexNatCon PLOC_setLexNatConList (PLOC_LexNatCon arg, const char *list);
ATbool PLOC_isValidNatCon (PLOC_NatCon arg);
inline ATbool PLOC_isNatConLexToCf (PLOC_NatCon arg);
ATbool PLOC_hasNatConNatCon (PLOC_NatCon arg);
PLOC_LexNatCon PLOC_getNatConNatCon (PLOC_NatCon arg);
PLOC_NatCon PLOC_setNatConNatCon (PLOC_NatCon arg, PLOC_LexNatCon NatCon);
ATbool PLOC_isValidLexLayout (PLOC_LexLayout arg);
inline ATbool PLOC_isLexLayoutWhitespace (PLOC_LexLayout arg);
ATbool PLOC_hasLexLayoutCh (PLOC_LexLayout arg);
char PLOC_getLexLayoutCh (PLOC_LexLayout arg);
PLOC_LexLayout PLOC_setLexLayoutCh (PLOC_LexLayout arg, char ch);
ATbool PLOC_isValidLocation (PLOC_Location arg);
inline ATbool PLOC_isLocationFile (PLOC_Location arg);
inline ATbool PLOC_isLocationArea (PLOC_Location arg);
inline ATbool PLOC_isLocationAreaInFile (PLOC_Location arg);
ATbool PLOC_hasLocationWsAfterFile (PLOC_Location arg);
ATbool PLOC_hasLocationWsAfterParenOpen (PLOC_Location arg);
ATbool PLOC_hasLocationFilename (PLOC_Location arg);
ATbool PLOC_hasLocationWsAfterFilename (PLOC_Location arg);
ATbool PLOC_hasLocationWsAfterA (PLOC_Location arg);
ATbool PLOC_hasLocationArea (PLOC_Location arg);
ATbool PLOC_hasLocationWsAfterArea (PLOC_Location arg);
ATbool PLOC_hasLocationWsAfterAreaInFile (PLOC_Location arg);
ATbool PLOC_hasLocationWsAfterComma (PLOC_Location arg);
PLOC_OptLayout PLOC_getLocationWsAfterFile (PLOC_Location arg);
PLOC_OptLayout PLOC_getLocationWsAfterParenOpen (PLOC_Location arg);
PLOC_StrCon PLOC_getLocationFilename (PLOC_Location arg);
PLOC_OptLayout PLOC_getLocationWsAfterFilename (PLOC_Location arg);
PLOC_OptLayout PLOC_getLocationWsAfterA (PLOC_Location arg);
PLOC_Area PLOC_getLocationArea (PLOC_Location arg);
PLOC_OptLayout PLOC_getLocationWsAfterArea (PLOC_Location arg);
PLOC_OptLayout PLOC_getLocationWsAfterAreaInFile (PLOC_Location arg);
PLOC_OptLayout PLOC_getLocationWsAfterComma (PLOC_Location arg);
PLOC_Location PLOC_setLocationWsAfterFile (PLOC_Location arg,
					   PLOC_OptLayout wsAfterFile);
PLOC_Location PLOC_setLocationWsAfterParenOpen (PLOC_Location arg,
						PLOC_OptLayout
						wsAfterParenOpen);
PLOC_Location PLOC_setLocationFilename (PLOC_Location arg,
					PLOC_StrCon filename);
PLOC_Location PLOC_setLocationWsAfterFilename (PLOC_Location arg,
					       PLOC_OptLayout
					       wsAfterFilename);
PLOC_Location PLOC_setLocationWsAfterA (PLOC_Location arg,
					PLOC_OptLayout wsAfterA);
PLOC_Location PLOC_setLocationArea (PLOC_Location arg, PLOC_Area Area);
PLOC_Location PLOC_setLocationWsAfterArea (PLOC_Location arg,
					   PLOC_OptLayout wsAfterArea);
PLOC_Location PLOC_setLocationWsAfterAreaInFile (PLOC_Location arg,
						 PLOC_OptLayout
						 wsAfterAreaInFile);
PLOC_Location PLOC_setLocationWsAfterComma (PLOC_Location arg,
					    PLOC_OptLayout wsAfterComma);
ATbool PLOC_isValidArea (PLOC_Area arg);
inline ATbool PLOC_isAreaArea (PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterArea (PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterParenOpen (PLOC_Area arg);
ATbool PLOC_hasAreaBeginLine (PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterBeginLine (PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterComma (PLOC_Area arg);
ATbool PLOC_hasAreaBeginColumn (PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterBeginColumn (PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterComma1 (PLOC_Area arg);
ATbool PLOC_hasAreaEndLine (PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterEndLine (PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterComma2 (PLOC_Area arg);
ATbool PLOC_hasAreaEndColumn (PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterEndColumn (PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterComma3 (PLOC_Area arg);
ATbool PLOC_hasAreaOffset (PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterOffset (PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterComma4 (PLOC_Area arg);
ATbool PLOC_hasAreaLength (PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterLength (PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterArea (PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterParenOpen (PLOC_Area arg);
PLOC_NatCon PLOC_getAreaBeginLine (PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterBeginLine (PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterComma (PLOC_Area arg);
PLOC_NatCon PLOC_getAreaBeginColumn (PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterBeginColumn (PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterComma1 (PLOC_Area arg);
PLOC_NatCon PLOC_getAreaEndLine (PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterEndLine (PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterComma2 (PLOC_Area arg);
PLOC_NatCon PLOC_getAreaEndColumn (PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterEndColumn (PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterComma3 (PLOC_Area arg);
PLOC_NatCon PLOC_getAreaOffset (PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterOffset (PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterComma4 (PLOC_Area arg);
PLOC_NatCon PLOC_getAreaLength (PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterLength (PLOC_Area arg);
PLOC_Area PLOC_setAreaWsAfterArea (PLOC_Area arg, PLOC_OptLayout wsAfterArea);
PLOC_Area PLOC_setAreaWsAfterParenOpen (PLOC_Area arg,
					PLOC_OptLayout wsAfterParenOpen);
PLOC_Area PLOC_setAreaBeginLine (PLOC_Area arg, PLOC_NatCon beginLine);
PLOC_Area PLOC_setAreaWsAfterBeginLine (PLOC_Area arg,
					PLOC_OptLayout wsAfterBeginLine);
PLOC_Area PLOC_setAreaWsAfterComma (PLOC_Area arg,
				    PLOC_OptLayout wsAfterComma);
PLOC_Area PLOC_setAreaBeginColumn (PLOC_Area arg, PLOC_NatCon beginColumn);
PLOC_Area PLOC_setAreaWsAfterBeginColumn (PLOC_Area arg,
					  PLOC_OptLayout wsAfterBeginColumn);
PLOC_Area PLOC_setAreaWsAfterComma1 (PLOC_Area arg,
				     PLOC_OptLayout wsAfterComma1);
PLOC_Area PLOC_setAreaEndLine (PLOC_Area arg, PLOC_NatCon endLine);
PLOC_Area PLOC_setAreaWsAfterEndLine (PLOC_Area arg,
				      PLOC_OptLayout wsAfterEndLine);
PLOC_Area PLOC_setAreaWsAfterComma2 (PLOC_Area arg,
				     PLOC_OptLayout wsAfterComma2);
PLOC_Area PLOC_setAreaEndColumn (PLOC_Area arg, PLOC_NatCon endColumn);
PLOC_Area PLOC_setAreaWsAfterEndColumn (PLOC_Area arg,
					PLOC_OptLayout wsAfterEndColumn);
PLOC_Area PLOC_setAreaWsAfterComma3 (PLOC_Area arg,
				     PLOC_OptLayout wsAfterComma3);
PLOC_Area PLOC_setAreaOffset (PLOC_Area arg, PLOC_NatCon offset);
PLOC_Area PLOC_setAreaWsAfterOffset (PLOC_Area arg,
				     PLOC_OptLayout wsAfterOffset);
PLOC_Area PLOC_setAreaWsAfterComma4 (PLOC_Area arg,
				     PLOC_OptLayout wsAfterComma4);
PLOC_Area PLOC_setAreaLength (PLOC_Area arg, PLOC_NatCon length);
PLOC_Area PLOC_setAreaWsAfterLength (PLOC_Area arg,
				     PLOC_OptLayout wsAfterLength);
ATbool PLOC_isValidSlice (PLOC_Slice arg);
inline ATbool PLOC_isSliceSlice (PLOC_Slice arg);
ATbool PLOC_hasSliceWsAfterSlice (PLOC_Slice arg);
ATbool PLOC_hasSliceWsAfterParenOpen (PLOC_Slice arg);
ATbool PLOC_hasSliceId (PLOC_Slice arg);
ATbool PLOC_hasSliceWsAfterId (PLOC_Slice arg);
ATbool PLOC_hasSliceWsAfterComma (PLOC_Slice arg);
ATbool PLOC_hasSliceWsAfterBracketOpen (PLOC_Slice arg);
ATbool PLOC_hasSliceAreas (PLOC_Slice arg);
ATbool PLOC_hasSliceWsAfterAreas (PLOC_Slice arg);
ATbool PLOC_hasSliceWsAfterBracketClose (PLOC_Slice arg);
PLOC_OptLayout PLOC_getSliceWsAfterSlice (PLOC_Slice arg);
PLOC_OptLayout PLOC_getSliceWsAfterParenOpen (PLOC_Slice arg);
PLOC_StrCon PLOC_getSliceId (PLOC_Slice arg);
PLOC_OptLayout PLOC_getSliceWsAfterId (PLOC_Slice arg);
PLOC_OptLayout PLOC_getSliceWsAfterComma (PLOC_Slice arg);
PLOC_OptLayout PLOC_getSliceWsAfterBracketOpen (PLOC_Slice arg);
PLOC_AreaAreas PLOC_getSliceAreas (PLOC_Slice arg);
PLOC_OptLayout PLOC_getSliceWsAfterAreas (PLOC_Slice arg);
PLOC_OptLayout PLOC_getSliceWsAfterBracketClose (PLOC_Slice arg);
PLOC_Slice PLOC_setSliceWsAfterSlice (PLOC_Slice arg,
				      PLOC_OptLayout wsAfterSlice);
PLOC_Slice PLOC_setSliceWsAfterParenOpen (PLOC_Slice arg,
					  PLOC_OptLayout wsAfterParenOpen);
PLOC_Slice PLOC_setSliceId (PLOC_Slice arg, PLOC_StrCon id);
PLOC_Slice PLOC_setSliceWsAfterId (PLOC_Slice arg, PLOC_OptLayout wsAfterId);
PLOC_Slice PLOC_setSliceWsAfterComma (PLOC_Slice arg,
				      PLOC_OptLayout wsAfterComma);
PLOC_Slice PLOC_setSliceWsAfterBracketOpen (PLOC_Slice arg,
					    PLOC_OptLayout
					    wsAfterBracketOpen);
PLOC_Slice PLOC_setSliceAreas (PLOC_Slice arg, PLOC_AreaAreas areas);
PLOC_Slice PLOC_setSliceWsAfterAreas (PLOC_Slice arg,
				      PLOC_OptLayout wsAfterAreas);
PLOC_Slice PLOC_setSliceWsAfterBracketClose (PLOC_Slice arg,
					     PLOC_OptLayout
					     wsAfterBracketClose);
ATbool PLOC_isValidAreaAreas (PLOC_AreaAreas arg);
inline ATbool PLOC_isAreaAreasEmpty (PLOC_AreaAreas arg);
inline ATbool PLOC_isAreaAreasSingle (PLOC_AreaAreas arg);
inline ATbool PLOC_isAreaAreasMany (PLOC_AreaAreas arg);
ATbool PLOC_hasAreaAreasHead (PLOC_AreaAreas arg);
ATbool PLOC_hasAreaAreasWsAfterHead (PLOC_AreaAreas arg);
ATbool PLOC_hasAreaAreasWsAfterSep (PLOC_AreaAreas arg);
ATbool PLOC_hasAreaAreasTail (PLOC_AreaAreas arg);
PLOC_AreaAreas PLOC_getAreaAreasTail (PLOC_AreaAreas arg);
PLOC_Area PLOC_getAreaAreasHead (PLOC_AreaAreas arg);
PLOC_OptLayout PLOC_getAreaAreasWsAfterHead (PLOC_AreaAreas arg);
PLOC_OptLayout PLOC_getAreaAreasWsAfterSep (PLOC_AreaAreas arg);
PLOC_AreaAreas PLOC_setAreaAreasHead (PLOC_AreaAreas arg, PLOC_Area head);
PLOC_AreaAreas PLOC_setAreaAreasWsAfterHead (PLOC_AreaAreas arg,
					     PLOC_OptLayout wsAfterHead);
PLOC_AreaAreas PLOC_setAreaAreasWsAfterSep (PLOC_AreaAreas arg,
					    PLOC_OptLayout wsAfterSep);
PLOC_AreaAreas PLOC_setAreaAreasTail (PLOC_AreaAreas arg,
				      PLOC_AreaAreas tail);
PLOC_OptLayout PLOC_visitOptLayout (PLOC_OptLayout arg,
				    PLOC_Layout (*acceptLayout)
				    (PLOC_Layout));
PLOC_Layout PLOC_visitLayout (PLOC_Layout arg,
			      PLOC_LexLayoutList (*acceptList)
			      (PLOC_LexLayoutList));
PLOC_LexLayoutList PLOC_visitLexLayoutList (PLOC_LexLayoutList arg,
					    PLOC_LexLayout (*acceptHead)
					    (PLOC_LexLayout));
PLOC_LexStrChar PLOC_visitLexStrChar (PLOC_LexStrChar arg,
				      char (*acceptA) (char),
				      char (*acceptB) (char),
				      char (*acceptC) (char),
				      char (*acceptCh) (char));
PLOC_StrChar PLOC_visitStrChar (PLOC_StrChar arg,
				PLOC_LexStrChar (*acceptStrChar)
				(PLOC_LexStrChar));
PLOC_LexStrCon PLOC_visitLexStrCon (PLOC_LexStrCon arg,
				    PLOC_LexStrCharChars (*acceptChars)
				    (PLOC_LexStrCharChars));
PLOC_StrCon PLOC_visitStrCon (PLOC_StrCon arg,
			      PLOC_LexStrCon (*acceptStrCon)
			      (PLOC_LexStrCon));
PLOC_LexStrCharChars PLOC_visitLexStrCharChars (PLOC_LexStrCharChars arg,
						PLOC_LexStrChar (*acceptHead)
						(PLOC_LexStrChar));
PLOC_LexNatCon PLOC_visitLexNatCon (PLOC_LexNatCon arg,
				    char *(*acceptList) (char *));
PLOC_NatCon PLOC_visitNatCon (PLOC_NatCon arg,
			      PLOC_LexNatCon (*acceptNatCon)
			      (PLOC_LexNatCon));
PLOC_LexLayout PLOC_visitLexLayout (PLOC_LexLayout arg,
				    char (*acceptCh) (char));
PLOC_Location PLOC_visitLocation (PLOC_Location arg,
				  PLOC_OptLayout (*acceptWsAfterFile)
				  (PLOC_OptLayout),
				  PLOC_OptLayout (*acceptWsAfterParenOpen)
				  (PLOC_OptLayout),
				  PLOC_StrCon (*acceptFilename) (PLOC_StrCon),
				  PLOC_OptLayout (*acceptWsAfterFilename)
				  (PLOC_OptLayout),
				  PLOC_OptLayout (*acceptWsAfterA)
				  (PLOC_OptLayout),
				  PLOC_Area (*acceptArea) (PLOC_Area),
				  PLOC_OptLayout (*acceptWsAfterArea)
				  (PLOC_OptLayout),
				  PLOC_OptLayout (*acceptWsAfterAreaInFile)
				  (PLOC_OptLayout),
				  PLOC_OptLayout (*acceptWsAfterComma)
				  (PLOC_OptLayout));
PLOC_Area PLOC_visitArea (PLOC_Area arg,
			  PLOC_OptLayout (*acceptWsAfterArea)
			  (PLOC_OptLayout),
			  PLOC_OptLayout (*acceptWsAfterParenOpen)
			  (PLOC_OptLayout),
			  PLOC_NatCon (*acceptBeginLine) (PLOC_NatCon),
			  PLOC_OptLayout (*acceptWsAfterBeginLine)
			  (PLOC_OptLayout),
			  PLOC_OptLayout (*acceptWsAfterComma)
			  (PLOC_OptLayout),
			  PLOC_NatCon (*acceptBeginColumn) (PLOC_NatCon),
			  PLOC_OptLayout (*acceptWsAfterBeginColumn)
			  (PLOC_OptLayout),
			  PLOC_OptLayout (*acceptWsAfterComma1)
			  (PLOC_OptLayout),
			  PLOC_NatCon (*acceptEndLine) (PLOC_NatCon),
			  PLOC_OptLayout (*acceptWsAfterEndLine)
			  (PLOC_OptLayout),
			  PLOC_OptLayout (*acceptWsAfterComma2)
			  (PLOC_OptLayout),
			  PLOC_NatCon (*acceptEndColumn) (PLOC_NatCon),
			  PLOC_OptLayout (*acceptWsAfterEndColumn)
			  (PLOC_OptLayout),
			  PLOC_OptLayout (*acceptWsAfterComma3)
			  (PLOC_OptLayout),
			  PLOC_NatCon (*acceptOffset) (PLOC_NatCon),
			  PLOC_OptLayout (*acceptWsAfterOffset)
			  (PLOC_OptLayout),
			  PLOC_OptLayout (*acceptWsAfterComma4)
			  (PLOC_OptLayout),
			  PLOC_NatCon (*acceptLength) (PLOC_NatCon),
			  PLOC_OptLayout (*acceptWsAfterLength)
			  (PLOC_OptLayout));
PLOC_Slice PLOC_visitSlice (PLOC_Slice arg,
			    PLOC_OptLayout (*acceptWsAfterSlice)
			    (PLOC_OptLayout),
			    PLOC_OptLayout (*acceptWsAfterParenOpen)
			    (PLOC_OptLayout),
			    PLOC_StrCon (*acceptId) (PLOC_StrCon),
			    PLOC_OptLayout (*acceptWsAfterId)
			    (PLOC_OptLayout),
			    PLOC_OptLayout (*acceptWsAfterComma)
			    (PLOC_OptLayout),
			    PLOC_OptLayout (*acceptWsAfterBracketOpen)
			    (PLOC_OptLayout),
			    PLOC_AreaAreas (*acceptAreas) (PLOC_AreaAreas),
			    PLOC_OptLayout (*acceptWsAfterAreas)
			    (PLOC_OptLayout),
			    PLOC_OptLayout (*acceptWsAfterBracketClose)
			    (PLOC_OptLayout));
PLOC_AreaAreas PLOC_visitAreaAreas (PLOC_AreaAreas arg,
				    PLOC_Area (*acceptHead) (PLOC_Area),
				    PLOC_OptLayout (*acceptWsAfterHead)
				    (PLOC_OptLayout),
				    PLOC_OptLayout (*acceptWsAfterSep)
				    (PLOC_OptLayout));

#endif /* _PARSEDLOCATION_H */
