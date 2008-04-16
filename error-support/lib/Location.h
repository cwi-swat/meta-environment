#ifndef _LOCATION_H
#define _LOCATION_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Location_dict.h"

typedef struct _LOC_StrChar *LOC_StrChar;
typedef struct _LOC_StrCon *LOC_StrCon;
typedef struct _LOC_NatCon *LOC_NatCon;
typedef struct _LOC_Location *LOC_Location;
typedef struct _LOC_Area *LOC_Area;
typedef struct _LOC_Slice *LOC_Slice;
typedef struct _LOC_AreaAreas *LOC_AreaAreas;

#ifdef FAST_API
#define LOC_initLocationApi() (init_Location_dict())
#else
void _LOC_initLocationApi (void);
#define LOC_initLocationApi() (_LOC_initLocationApi())
#endif

#ifdef FAST_API
#define LOC_protectStrChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _LOC_protectStrChar (LOC_StrChar * arg);
#define LOC_protectStrChar(arg) (_LOC_protectStrChar(arg))
#endif
#ifdef FAST_API
#define LOC_unprotectStrChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _LOC_unprotectStrChar (LOC_StrChar * arg);
#define LOC_unprotectStrChar(arg) (_LOC_unprotectStrChar(arg))
#endif
#ifdef FAST_API
#define LOC_protectStrCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _LOC_protectStrCon (LOC_StrCon * arg);
#define LOC_protectStrCon(arg) (_LOC_protectStrCon(arg))
#endif
#ifdef FAST_API
#define LOC_unprotectStrCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _LOC_unprotectStrCon (LOC_StrCon * arg);
#define LOC_unprotectStrCon(arg) (_LOC_unprotectStrCon(arg))
#endif
#ifdef FAST_API
#define LOC_protectNatCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _LOC_protectNatCon (LOC_NatCon * arg);
#define LOC_protectNatCon(arg) (_LOC_protectNatCon(arg))
#endif
#ifdef FAST_API
#define LOC_unprotectNatCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _LOC_unprotectNatCon (LOC_NatCon * arg);
#define LOC_unprotectNatCon(arg) (_LOC_unprotectNatCon(arg))
#endif
#ifdef FAST_API
#define LOC_protectLocation(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _LOC_protectLocation (LOC_Location * arg);
#define LOC_protectLocation(arg) (_LOC_protectLocation(arg))
#endif
#ifdef FAST_API
#define LOC_unprotectLocation(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _LOC_unprotectLocation (LOC_Location * arg);
#define LOC_unprotectLocation(arg) (_LOC_unprotectLocation(arg))
#endif
#ifdef FAST_API
#define LOC_protectArea(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _LOC_protectArea (LOC_Area * arg);
#define LOC_protectArea(arg) (_LOC_protectArea(arg))
#endif
#ifdef FAST_API
#define LOC_unprotectArea(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _LOC_unprotectArea (LOC_Area * arg);
#define LOC_unprotectArea(arg) (_LOC_unprotectArea(arg))
#endif
#ifdef FAST_API
#define LOC_protectSlice(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _LOC_protectSlice (LOC_Slice * arg);
#define LOC_protectSlice(arg) (_LOC_protectSlice(arg))
#endif
#ifdef FAST_API
#define LOC_unprotectSlice(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _LOC_unprotectSlice (LOC_Slice * arg);
#define LOC_unprotectSlice(arg) (_LOC_unprotectSlice(arg))
#endif
#ifdef FAST_API
#define LOC_protectAreaAreas(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _LOC_protectAreaAreas (LOC_AreaAreas * arg);
#define LOC_protectAreaAreas(arg) (_LOC_protectAreaAreas(arg))
#endif
#ifdef FAST_API
#define LOC_unprotectAreaAreas(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _LOC_unprotectAreaAreas (LOC_AreaAreas * arg);
#define LOC_unprotectAreaAreas(arg) (_LOC_unprotectAreaAreas(arg))
#endif
#ifdef FAST_API
#define LOC_StrCharFromTerm(t) ((((union {LOC_StrChar target; ATerm source; })(t)).target))
#else
LOC_StrChar _LOC_StrCharFromTerm (ATerm t);
#define LOC_StrCharFromTerm(t) (_LOC_StrCharFromTerm(t))
#endif
#ifdef FAST_API
#define LOC_StrCharToTerm(arg) ((((union {LOC_StrChar source; ATerm target; })(arg)).target))
#else
ATerm _LOC_StrCharToTerm (LOC_StrChar arg);
#define LOC_StrCharToTerm(arg) (_LOC_StrCharToTerm(arg))
#endif
#ifdef FAST_API
#define LOC_StrConFromTerm(t) ((((union {LOC_StrCon target; ATerm source; })(t)).target))
#else
LOC_StrCon _LOC_StrConFromTerm (ATerm t);
#define LOC_StrConFromTerm(t) (_LOC_StrConFromTerm(t))
#endif
#ifdef FAST_API
#define LOC_StrConToTerm(arg) ((((union {LOC_StrCon source; ATerm target; })(arg)).target))
#else
ATerm _LOC_StrConToTerm (LOC_StrCon arg);
#define LOC_StrConToTerm(arg) (_LOC_StrConToTerm(arg))
#endif
#ifdef FAST_API
#define LOC_NatConFromTerm(t) ((((union {LOC_NatCon target; ATerm source; })(t)).target))
#else
LOC_NatCon _LOC_NatConFromTerm (ATerm t);
#define LOC_NatConFromTerm(t) (_LOC_NatConFromTerm(t))
#endif
#ifdef FAST_API
#define LOC_NatConToTerm(arg) ((((union {LOC_NatCon source; ATerm target; })(arg)).target))
#else
ATerm _LOC_NatConToTerm (LOC_NatCon arg);
#define LOC_NatConToTerm(arg) (_LOC_NatConToTerm(arg))
#endif
#ifdef FAST_API
#define LOC_LocationFromTerm(t) ((((union {LOC_Location target; ATerm source; })(t)).target))
#else
LOC_Location _LOC_LocationFromTerm (ATerm t);
#define LOC_LocationFromTerm(t) (_LOC_LocationFromTerm(t))
#endif
#ifdef FAST_API
#define LOC_LocationToTerm(arg) ((((union {LOC_Location source; ATerm target; })(arg)).target))
#else
ATerm _LOC_LocationToTerm (LOC_Location arg);
#define LOC_LocationToTerm(arg) (_LOC_LocationToTerm(arg))
#endif
#ifdef FAST_API
#define LOC_AreaFromTerm(t) ((((union {LOC_Area target; ATerm source; })(t)).target))
#else
LOC_Area _LOC_AreaFromTerm (ATerm t);
#define LOC_AreaFromTerm(t) (_LOC_AreaFromTerm(t))
#endif
#ifdef FAST_API
#define LOC_AreaToTerm(arg) ((((union {LOC_Area source; ATerm target; })(arg)).target))
#else
ATerm _LOC_AreaToTerm (LOC_Area arg);
#define LOC_AreaToTerm(arg) (_LOC_AreaToTerm(arg))
#endif
#ifdef FAST_API
#define LOC_SliceFromTerm(t) ((((union {LOC_Slice target; ATerm source; })(t)).target))
#else
LOC_Slice _LOC_SliceFromTerm (ATerm t);
#define LOC_SliceFromTerm(t) (_LOC_SliceFromTerm(t))
#endif
#ifdef FAST_API
#define LOC_SliceToTerm(arg) ((((union {LOC_Slice source; ATerm target; })(arg)).target))
#else
ATerm _LOC_SliceToTerm (LOC_Slice arg);
#define LOC_SliceToTerm(arg) (_LOC_SliceToTerm(arg))
#endif
#ifdef FAST_API
#define LOC_AreaAreasFromTerm(t) ((((union {LOC_AreaAreas target; ATerm source; })(t)).target))
#else
LOC_AreaAreas _LOC_AreaAreasFromTerm (ATerm t);
#define LOC_AreaAreasFromTerm(t) (_LOC_AreaAreasFromTerm(t))
#endif
#ifdef FAST_API
#define LOC_AreaAreasToTerm(arg) ((((union {LOC_AreaAreas source; ATerm target; })(arg)).target))
#else
ATerm _LOC_AreaAreasToTerm (LOC_AreaAreas arg);
#define LOC_AreaAreasToTerm(arg) (_LOC_AreaAreasToTerm(arg))
#endif
#ifdef FAST_API
#define LOC_getAreaAreasLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _LOC_getAreaAreasLength (LOC_AreaAreas arg);
#define LOC_getAreaAreasLength(arg) (_LOC_getAreaAreasLength(arg))
#endif
#ifdef FAST_API
#define LOC_reverseAreaAreas(arg) ((LOC_AreaAreas) ATreverse((ATermList) (arg)))
#else
LOC_AreaAreas _LOC_reverseAreaAreas (LOC_AreaAreas arg);
#define LOC_reverseAreaAreas(arg) (_LOC_reverseAreaAreas(arg))
#endif
#ifdef FAST_API
#define LOC_appendAreaAreas(arg, elem) ((LOC_AreaAreas) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
LOC_AreaAreas _LOC_appendAreaAreas (LOC_AreaAreas arg, LOC_Area elem);
#define LOC_appendAreaAreas(arg, elem) (_LOC_appendAreaAreas(arg, elem))
#endif
#ifdef FAST_API
#define LOC_concatAreaAreas(arg0, arg1) ((LOC_AreaAreas) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
LOC_AreaAreas _LOC_concatAreaAreas (LOC_AreaAreas arg0, LOC_AreaAreas arg1);
#define LOC_concatAreaAreas(arg0, arg1) (_LOC_concatAreaAreas(arg0, arg1))
#endif
#ifdef FAST_API
#define LOC_sliceAreaAreas(arg, start, end) ((LOC_AreaAreas) ATgetSlice((ATermList) (arg), (start), (end)))
#else
LOC_AreaAreas _LOC_sliceAreaAreas (LOC_AreaAreas arg, int start, int end);
#define LOC_sliceAreaAreas(arg, start, end) (_LOC_sliceAreaAreas(arg, start, end))
#endif
#ifdef FAST_API
#define LOC_getAreaAreasAreaAt(arg, index) ((LOC_Area) (ATelementAt((ATermList) arg,index)))
#else
LOC_Area _LOC_getAreaAreasAreaAt (LOC_AreaAreas arg, int index);
#define LOC_getAreaAreasAreaAt(arg, index) (_LOC_getAreaAreasAreaAt(arg, index))
#endif
#ifdef FAST_API
#define LOC_replaceAreaAreasAreaAt(arg, elem, index) ((LOC_AreaAreas) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
LOC_AreaAreas _LOC_replaceAreaAreasAreaAt (LOC_AreaAreas arg, LOC_Area elem,
					   int index);
#define LOC_replaceAreaAreasAreaAt(arg, elem, index) (_LOC_replaceAreaAreasAreaAt(arg, elem, index))
#endif
#ifdef FAST_API
#define LOC_makeAreaAreas2(elem1,  elem2) ((LOC_AreaAreas) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
LOC_AreaAreas _LOC_makeAreaAreas2 (LOC_Area elem1, LOC_Area elem2);
#define LOC_makeAreaAreas2(elem1,  elem2) (_LOC_makeAreaAreas2(elem1,  elem2))
#endif
#ifdef FAST_API
#define LOC_makeAreaAreas3(elem1, elem2,  elem3) ((LOC_AreaAreas) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
LOC_AreaAreas _LOC_makeAreaAreas3 (LOC_Area elem1, LOC_Area elem2,
				   LOC_Area elem3);
#define LOC_makeAreaAreas3(elem1, elem2,  elem3) (_LOC_makeAreaAreas3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define LOC_makeAreaAreas4(elem1, elem2, elem3,  elem4) ((LOC_AreaAreas) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
LOC_AreaAreas _LOC_makeAreaAreas4 (LOC_Area elem1, LOC_Area elem2,
				   LOC_Area elem3, LOC_Area elem4);
#define LOC_makeAreaAreas4(elem1, elem2, elem3,  elem4) (_LOC_makeAreaAreas4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define LOC_makeAreaAreas5(elem1, elem2, elem3, elem4,  elem5) ((LOC_AreaAreas) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
LOC_AreaAreas _LOC_makeAreaAreas5 (LOC_Area elem1, LOC_Area elem2,
				   LOC_Area elem3, LOC_Area elem4,
				   LOC_Area elem5);
#define LOC_makeAreaAreas5(elem1, elem2, elem3, elem4,  elem5) (_LOC_makeAreaAreas5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define LOC_makeAreaAreas6(elem1, elem2, elem3, elem4, elem5,  elem6) ((LOC_AreaAreas) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
LOC_AreaAreas _LOC_makeAreaAreas6 (LOC_Area elem1, LOC_Area elem2,
				   LOC_Area elem3, LOC_Area elem4,
				   LOC_Area elem5, LOC_Area elem6);
#define LOC_makeAreaAreas6(elem1, elem2, elem3, elem4, elem5,  elem6) (_LOC_makeAreaAreas6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
LOC_StrChar LOC_makeStrCharStrChar (const char *string);
LOC_StrCon LOC_makeStrConStrCon (const char *string);
LOC_NatCon LOC_makeNatConNatCon (const char *string);
LOC_Location LOC_makeLocationFile (const char *filename);
LOC_Location LOC_makeLocationArea (LOC_Area Area);
LOC_Location LOC_makeLocationAreaInFile (const char *filename, LOC_Area Area);
LOC_Area LOC_makeAreaArea (int beginLine, int beginColumn, int endLine,
			   int endColumn, int offset, int length);
LOC_Slice LOC_makeSliceSlice (const char *id, LOC_AreaAreas areas);
LOC_AreaAreas LOC_makeAreaAreasEmpty (void);
LOC_AreaAreas LOC_makeAreaAreasSingle (LOC_Area head);
LOC_AreaAreas LOC_makeAreaAreasMany (LOC_Area head, LOC_AreaAreas tail);
#ifdef FAST_API
#define LOC_isEqualStrChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _LOC_isEqualStrChar (LOC_StrChar arg0, LOC_StrChar arg1);
#define LOC_isEqualStrChar(arg0, arg1) (_LOC_isEqualStrChar(arg0, arg1))
#endif
#ifdef FAST_API
#define LOC_isEqualStrCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _LOC_isEqualStrCon (LOC_StrCon arg0, LOC_StrCon arg1);
#define LOC_isEqualStrCon(arg0, arg1) (_LOC_isEqualStrCon(arg0, arg1))
#endif
#ifdef FAST_API
#define LOC_isEqualNatCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _LOC_isEqualNatCon (LOC_NatCon arg0, LOC_NatCon arg1);
#define LOC_isEqualNatCon(arg0, arg1) (_LOC_isEqualNatCon(arg0, arg1))
#endif
#ifdef FAST_API
#define LOC_isEqualLocation(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _LOC_isEqualLocation (LOC_Location arg0, LOC_Location arg1);
#define LOC_isEqualLocation(arg0, arg1) (_LOC_isEqualLocation(arg0, arg1))
#endif
#ifdef FAST_API
#define LOC_isEqualArea(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _LOC_isEqualArea (LOC_Area arg0, LOC_Area arg1);
#define LOC_isEqualArea(arg0, arg1) (_LOC_isEqualArea(arg0, arg1))
#endif
#ifdef FAST_API
#define LOC_isEqualSlice(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _LOC_isEqualSlice (LOC_Slice arg0, LOC_Slice arg1);
#define LOC_isEqualSlice(arg0, arg1) (_LOC_isEqualSlice(arg0, arg1))
#endif
#ifdef FAST_API
#define LOC_isEqualAreaAreas(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _LOC_isEqualAreaAreas (LOC_AreaAreas arg0, LOC_AreaAreas arg1);
#define LOC_isEqualAreaAreas(arg0, arg1) (_LOC_isEqualAreaAreas(arg0, arg1))
#endif
ATbool LOC_isValidStrChar (LOC_StrChar arg);
inline ATbool LOC_isStrCharStrChar (LOC_StrChar arg);
ATbool LOC_hasStrCharString (LOC_StrChar arg);
char *LOC_getStrCharString (LOC_StrChar arg);
LOC_StrChar LOC_setStrCharString (LOC_StrChar arg, const char *string);
ATbool LOC_isValidStrCon (LOC_StrCon arg);
inline ATbool LOC_isStrConStrCon (LOC_StrCon arg);
ATbool LOC_hasStrConString (LOC_StrCon arg);
char *LOC_getStrConString (LOC_StrCon arg);
LOC_StrCon LOC_setStrConString (LOC_StrCon arg, const char *string);
ATbool LOC_isValidNatCon (LOC_NatCon arg);
inline ATbool LOC_isNatConNatCon (LOC_NatCon arg);
ATbool LOC_hasNatConString (LOC_NatCon arg);
char *LOC_getNatConString (LOC_NatCon arg);
LOC_NatCon LOC_setNatConString (LOC_NatCon arg, const char *string);
ATbool LOC_isValidLocation (LOC_Location arg);
inline ATbool LOC_isLocationFile (LOC_Location arg);
inline ATbool LOC_isLocationArea (LOC_Location arg);
inline ATbool LOC_isLocationAreaInFile (LOC_Location arg);
ATbool LOC_hasLocationFilename (LOC_Location arg);
ATbool LOC_hasLocationArea (LOC_Location arg);
char *LOC_getLocationFilename (LOC_Location arg);
LOC_Area LOC_getLocationArea (LOC_Location arg);
LOC_Location LOC_setLocationFilename (LOC_Location arg, const char *filename);
LOC_Location LOC_setLocationArea (LOC_Location arg, LOC_Area Area);
ATbool LOC_isValidArea (LOC_Area arg);
inline ATbool LOC_isAreaArea (LOC_Area arg);
ATbool LOC_hasAreaBeginLine (LOC_Area arg);
ATbool LOC_hasAreaBeginColumn (LOC_Area arg);
ATbool LOC_hasAreaEndLine (LOC_Area arg);
ATbool LOC_hasAreaEndColumn (LOC_Area arg);
ATbool LOC_hasAreaOffset (LOC_Area arg);
ATbool LOC_hasAreaLength (LOC_Area arg);
int LOC_getAreaBeginLine (LOC_Area arg);
int LOC_getAreaBeginColumn (LOC_Area arg);
int LOC_getAreaEndLine (LOC_Area arg);
int LOC_getAreaEndColumn (LOC_Area arg);
int LOC_getAreaOffset (LOC_Area arg);
int LOC_getAreaLength (LOC_Area arg);
LOC_Area LOC_setAreaBeginLine (LOC_Area arg, int beginLine);
LOC_Area LOC_setAreaBeginColumn (LOC_Area arg, int beginColumn);
LOC_Area LOC_setAreaEndLine (LOC_Area arg, int endLine);
LOC_Area LOC_setAreaEndColumn (LOC_Area arg, int endColumn);
LOC_Area LOC_setAreaOffset (LOC_Area arg, int offset);
LOC_Area LOC_setAreaLength (LOC_Area arg, int length);
ATbool LOC_isValidSlice (LOC_Slice arg);
inline ATbool LOC_isSliceSlice (LOC_Slice arg);
ATbool LOC_hasSliceId (LOC_Slice arg);
ATbool LOC_hasSliceAreas (LOC_Slice arg);
char *LOC_getSliceId (LOC_Slice arg);
LOC_AreaAreas LOC_getSliceAreas (LOC_Slice arg);
LOC_Slice LOC_setSliceId (LOC_Slice arg, const char *id);
LOC_Slice LOC_setSliceAreas (LOC_Slice arg, LOC_AreaAreas areas);
ATbool LOC_isValidAreaAreas (LOC_AreaAreas arg);
inline ATbool LOC_isAreaAreasEmpty (LOC_AreaAreas arg);
inline ATbool LOC_isAreaAreasSingle (LOC_AreaAreas arg);
inline ATbool LOC_isAreaAreasMany (LOC_AreaAreas arg);
ATbool LOC_hasAreaAreasHead (LOC_AreaAreas arg);
ATbool LOC_hasAreaAreasTail (LOC_AreaAreas arg);
LOC_Area LOC_getAreaAreasHead (LOC_AreaAreas arg);
LOC_AreaAreas LOC_getAreaAreasTail (LOC_AreaAreas arg);
LOC_AreaAreas LOC_setAreaAreasHead (LOC_AreaAreas arg, LOC_Area head);
LOC_AreaAreas LOC_setAreaAreasTail (LOC_AreaAreas arg, LOC_AreaAreas tail);
LOC_StrChar LOC_visitStrChar (LOC_StrChar arg,
			      char *(*acceptString) (char *));
LOC_StrCon LOC_visitStrCon (LOC_StrCon arg, char *(*acceptString) (char *));
LOC_NatCon LOC_visitNatCon (LOC_NatCon arg, char *(*acceptString) (char *));
LOC_Location LOC_visitLocation (LOC_Location arg,
				char *(*acceptFilename) (char *),
				LOC_Area (*acceptArea) (LOC_Area));
LOC_Area LOC_visitArea (LOC_Area arg, int (*acceptBeginLine) (int),
			int (*acceptBeginColumn) (int),
			int (*acceptEndLine) (int),
			int (*acceptEndColumn) (int),
			int (*acceptOffset) (int), int (*acceptLength) (int));
LOC_Slice LOC_visitSlice (LOC_Slice arg, char *(*acceptId) (char *),
			  LOC_AreaAreas (*acceptAreas) (LOC_AreaAreas));
LOC_AreaAreas LOC_visitAreaAreas (LOC_AreaAreas arg,
				  LOC_Area (*acceptHead) (LOC_Area));

#endif /* _LOCATION_H */
