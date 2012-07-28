#ifndef _ERROR_H
#define _ERROR_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Error_dict.h"

typedef struct _ERR_StrChar *ERR_StrChar;
typedef struct _ERR_StrCon *ERR_StrCon;
typedef struct _ERR_NatCon *ERR_NatCon;
typedef struct _ERR_Subject *ERR_Subject;
typedef struct _ERR_Error *ERR_Error;
typedef struct _ERR_Summary *ERR_Summary;
typedef struct _ERR_SubjectList *ERR_SubjectList;
typedef struct _ERR_ErrorList *ERR_ErrorList;
typedef struct _ERR_Location *ERR_Location;
typedef struct _ERR_Area *ERR_Area;
typedef struct _ERR_Slice *ERR_Slice;
typedef struct _ERR_AreaAreas *ERR_AreaAreas;

#ifdef FAST_API
#define ERR_initErrorApi() (init_Error_dict())
#else
void _ERR_initErrorApi (void);
#define ERR_initErrorApi() (_ERR_initErrorApi())
#endif

#ifdef FAST_API
#define ERR_protectStrChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ERR_protectStrChar (ERR_StrChar * arg);
#define ERR_protectStrChar(arg) (_ERR_protectStrChar(arg))
#endif
#ifdef FAST_API
#define ERR_unprotectStrChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ERR_unprotectStrChar (ERR_StrChar * arg);
#define ERR_unprotectStrChar(arg) (_ERR_unprotectStrChar(arg))
#endif
#ifdef FAST_API
#define ERR_protectStrCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ERR_protectStrCon (ERR_StrCon * arg);
#define ERR_protectStrCon(arg) (_ERR_protectStrCon(arg))
#endif
#ifdef FAST_API
#define ERR_unprotectStrCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ERR_unprotectStrCon (ERR_StrCon * arg);
#define ERR_unprotectStrCon(arg) (_ERR_unprotectStrCon(arg))
#endif
#ifdef FAST_API
#define ERR_protectNatCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ERR_protectNatCon (ERR_NatCon * arg);
#define ERR_protectNatCon(arg) (_ERR_protectNatCon(arg))
#endif
#ifdef FAST_API
#define ERR_unprotectNatCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ERR_unprotectNatCon (ERR_NatCon * arg);
#define ERR_unprotectNatCon(arg) (_ERR_unprotectNatCon(arg))
#endif
#ifdef FAST_API
#define ERR_protectSubject(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ERR_protectSubject (ERR_Subject * arg);
#define ERR_protectSubject(arg) (_ERR_protectSubject(arg))
#endif
#ifdef FAST_API
#define ERR_unprotectSubject(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ERR_unprotectSubject (ERR_Subject * arg);
#define ERR_unprotectSubject(arg) (_ERR_unprotectSubject(arg))
#endif
#ifdef FAST_API
#define ERR_protectError(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ERR_protectError (ERR_Error * arg);
#define ERR_protectError(arg) (_ERR_protectError(arg))
#endif
#ifdef FAST_API
#define ERR_unprotectError(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ERR_unprotectError (ERR_Error * arg);
#define ERR_unprotectError(arg) (_ERR_unprotectError(arg))
#endif
#ifdef FAST_API
#define ERR_protectSummary(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ERR_protectSummary (ERR_Summary * arg);
#define ERR_protectSummary(arg) (_ERR_protectSummary(arg))
#endif
#ifdef FAST_API
#define ERR_unprotectSummary(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ERR_unprotectSummary (ERR_Summary * arg);
#define ERR_unprotectSummary(arg) (_ERR_unprotectSummary(arg))
#endif
#ifdef FAST_API
#define ERR_protectSubjectList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ERR_protectSubjectList (ERR_SubjectList * arg);
#define ERR_protectSubjectList(arg) (_ERR_protectSubjectList(arg))
#endif
#ifdef FAST_API
#define ERR_unprotectSubjectList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ERR_unprotectSubjectList (ERR_SubjectList * arg);
#define ERR_unprotectSubjectList(arg) (_ERR_unprotectSubjectList(arg))
#endif
#ifdef FAST_API
#define ERR_protectErrorList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ERR_protectErrorList (ERR_ErrorList * arg);
#define ERR_protectErrorList(arg) (_ERR_protectErrorList(arg))
#endif
#ifdef FAST_API
#define ERR_unprotectErrorList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ERR_unprotectErrorList (ERR_ErrorList * arg);
#define ERR_unprotectErrorList(arg) (_ERR_unprotectErrorList(arg))
#endif
#ifdef FAST_API
#define ERR_protectLocation(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ERR_protectLocation (ERR_Location * arg);
#define ERR_protectLocation(arg) (_ERR_protectLocation(arg))
#endif
#ifdef FAST_API
#define ERR_unprotectLocation(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ERR_unprotectLocation (ERR_Location * arg);
#define ERR_unprotectLocation(arg) (_ERR_unprotectLocation(arg))
#endif
#ifdef FAST_API
#define ERR_protectArea(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ERR_protectArea (ERR_Area * arg);
#define ERR_protectArea(arg) (_ERR_protectArea(arg))
#endif
#ifdef FAST_API
#define ERR_unprotectArea(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ERR_unprotectArea (ERR_Area * arg);
#define ERR_unprotectArea(arg) (_ERR_unprotectArea(arg))
#endif
#ifdef FAST_API
#define ERR_protectSlice(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ERR_protectSlice (ERR_Slice * arg);
#define ERR_protectSlice(arg) (_ERR_protectSlice(arg))
#endif
#ifdef FAST_API
#define ERR_unprotectSlice(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ERR_unprotectSlice (ERR_Slice * arg);
#define ERR_unprotectSlice(arg) (_ERR_unprotectSlice(arg))
#endif
#ifdef FAST_API
#define ERR_protectAreaAreas(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ERR_protectAreaAreas (ERR_AreaAreas * arg);
#define ERR_protectAreaAreas(arg) (_ERR_protectAreaAreas(arg))
#endif
#ifdef FAST_API
#define ERR_unprotectAreaAreas(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ERR_unprotectAreaAreas (ERR_AreaAreas * arg);
#define ERR_unprotectAreaAreas(arg) (_ERR_unprotectAreaAreas(arg))
#endif
#ifdef FAST_API
#define ERR_StrCharFromTerm(t) ((((union {ERR_StrChar target; ATerm source; })(t)).target))
#else
ERR_StrChar _ERR_StrCharFromTerm (ATerm t);
#define ERR_StrCharFromTerm(t) (_ERR_StrCharFromTerm(t))
#endif
#ifdef FAST_API
#define ERR_StrCharToTerm(arg) ((((union {ERR_StrChar source; ATerm target; })(arg)).target))
#else
ATerm _ERR_StrCharToTerm (ERR_StrChar arg);
#define ERR_StrCharToTerm(arg) (_ERR_StrCharToTerm(arg))
#endif
#ifdef FAST_API
#define ERR_StrConFromTerm(t) ((((union {ERR_StrCon target; ATerm source; })(t)).target))
#else
ERR_StrCon _ERR_StrConFromTerm (ATerm t);
#define ERR_StrConFromTerm(t) (_ERR_StrConFromTerm(t))
#endif
#ifdef FAST_API
#define ERR_StrConToTerm(arg) ((((union {ERR_StrCon source; ATerm target; })(arg)).target))
#else
ATerm _ERR_StrConToTerm (ERR_StrCon arg);
#define ERR_StrConToTerm(arg) (_ERR_StrConToTerm(arg))
#endif
#ifdef FAST_API
#define ERR_NatConFromTerm(t) ((((union {ERR_NatCon target; ATerm source; })(t)).target))
#else
ERR_NatCon _ERR_NatConFromTerm (ATerm t);
#define ERR_NatConFromTerm(t) (_ERR_NatConFromTerm(t))
#endif
#ifdef FAST_API
#define ERR_NatConToTerm(arg) ((((union {ERR_NatCon source; ATerm target; })(arg)).target))
#else
ATerm _ERR_NatConToTerm (ERR_NatCon arg);
#define ERR_NatConToTerm(arg) (_ERR_NatConToTerm(arg))
#endif
#ifdef FAST_API
#define ERR_SubjectFromTerm(t) ((((union {ERR_Subject target; ATerm source; })(t)).target))
#else
ERR_Subject _ERR_SubjectFromTerm (ATerm t);
#define ERR_SubjectFromTerm(t) (_ERR_SubjectFromTerm(t))
#endif
#ifdef FAST_API
#define ERR_SubjectToTerm(arg) ((((union {ERR_Subject source; ATerm target; })(arg)).target))
#else
ATerm _ERR_SubjectToTerm (ERR_Subject arg);
#define ERR_SubjectToTerm(arg) (_ERR_SubjectToTerm(arg))
#endif
#ifdef FAST_API
#define ERR_ErrorFromTerm(t) ((((union {ERR_Error target; ATerm source; })(t)).target))
#else
ERR_Error _ERR_ErrorFromTerm (ATerm t);
#define ERR_ErrorFromTerm(t) (_ERR_ErrorFromTerm(t))
#endif
#ifdef FAST_API
#define ERR_ErrorToTerm(arg) ((((union {ERR_Error source; ATerm target; })(arg)).target))
#else
ATerm _ERR_ErrorToTerm (ERR_Error arg);
#define ERR_ErrorToTerm(arg) (_ERR_ErrorToTerm(arg))
#endif
#ifdef FAST_API
#define ERR_SummaryFromTerm(t) ((((union {ERR_Summary target; ATerm source; })(t)).target))
#else
ERR_Summary _ERR_SummaryFromTerm (ATerm t);
#define ERR_SummaryFromTerm(t) (_ERR_SummaryFromTerm(t))
#endif
#ifdef FAST_API
#define ERR_SummaryToTerm(arg) ((((union {ERR_Summary source; ATerm target; })(arg)).target))
#else
ATerm _ERR_SummaryToTerm (ERR_Summary arg);
#define ERR_SummaryToTerm(arg) (_ERR_SummaryToTerm(arg))
#endif
#ifdef FAST_API
#define ERR_SubjectListFromTerm(t) ((((union {ERR_SubjectList target; ATerm source; })(t)).target))
#else
ERR_SubjectList _ERR_SubjectListFromTerm (ATerm t);
#define ERR_SubjectListFromTerm(t) (_ERR_SubjectListFromTerm(t))
#endif
#ifdef FAST_API
#define ERR_SubjectListToTerm(arg) ((((union {ERR_SubjectList source; ATerm target; })(arg)).target))
#else
ATerm _ERR_SubjectListToTerm (ERR_SubjectList arg);
#define ERR_SubjectListToTerm(arg) (_ERR_SubjectListToTerm(arg))
#endif
#ifdef FAST_API
#define ERR_ErrorListFromTerm(t) ((((union {ERR_ErrorList target; ATerm source; })(t)).target))
#else
ERR_ErrorList _ERR_ErrorListFromTerm (ATerm t);
#define ERR_ErrorListFromTerm(t) (_ERR_ErrorListFromTerm(t))
#endif
#ifdef FAST_API
#define ERR_ErrorListToTerm(arg) ((((union {ERR_ErrorList source; ATerm target; })(arg)).target))
#else
ATerm _ERR_ErrorListToTerm (ERR_ErrorList arg);
#define ERR_ErrorListToTerm(arg) (_ERR_ErrorListToTerm(arg))
#endif
#ifdef FAST_API
#define ERR_LocationFromTerm(t) ((((union {ERR_Location target; ATerm source; })(t)).target))
#else
ERR_Location _ERR_LocationFromTerm (ATerm t);
#define ERR_LocationFromTerm(t) (_ERR_LocationFromTerm(t))
#endif
#ifdef FAST_API
#define ERR_LocationToTerm(arg) ((((union {ERR_Location source; ATerm target; })(arg)).target))
#else
ATerm _ERR_LocationToTerm (ERR_Location arg);
#define ERR_LocationToTerm(arg) (_ERR_LocationToTerm(arg))
#endif
#ifdef FAST_API
#define ERR_AreaFromTerm(t) ((((union {ERR_Area target; ATerm source; })(t)).target))
#else
ERR_Area _ERR_AreaFromTerm (ATerm t);
#define ERR_AreaFromTerm(t) (_ERR_AreaFromTerm(t))
#endif
#ifdef FAST_API
#define ERR_AreaToTerm(arg) ((((union {ERR_Area source; ATerm target; })(arg)).target))
#else
ATerm _ERR_AreaToTerm (ERR_Area arg);
#define ERR_AreaToTerm(arg) (_ERR_AreaToTerm(arg))
#endif
#ifdef FAST_API
#define ERR_SliceFromTerm(t) ((((union {ERR_Slice target; ATerm source; })(t)).target))
#else
ERR_Slice _ERR_SliceFromTerm (ATerm t);
#define ERR_SliceFromTerm(t) (_ERR_SliceFromTerm(t))
#endif
#ifdef FAST_API
#define ERR_SliceToTerm(arg) ((((union {ERR_Slice source; ATerm target; })(arg)).target))
#else
ATerm _ERR_SliceToTerm (ERR_Slice arg);
#define ERR_SliceToTerm(arg) (_ERR_SliceToTerm(arg))
#endif
#ifdef FAST_API
#define ERR_AreaAreasFromTerm(t) ((((union {ERR_AreaAreas target; ATerm source; })(t)).target))
#else
ERR_AreaAreas _ERR_AreaAreasFromTerm (ATerm t);
#define ERR_AreaAreasFromTerm(t) (_ERR_AreaAreasFromTerm(t))
#endif
#ifdef FAST_API
#define ERR_AreaAreasToTerm(arg) ((((union {ERR_AreaAreas source; ATerm target; })(arg)).target))
#else
ATerm _ERR_AreaAreasToTerm (ERR_AreaAreas arg);
#define ERR_AreaAreasToTerm(arg) (_ERR_AreaAreasToTerm(arg))
#endif
#ifdef FAST_API
#define ERR_getSubjectListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _ERR_getSubjectListLength (ERR_SubjectList arg);
#define ERR_getSubjectListLength(arg) (_ERR_getSubjectListLength(arg))
#endif
#ifdef FAST_API
#define ERR_reverseSubjectList(arg) ((ERR_SubjectList) ATreverse((ATermList) (arg)))
#else
ERR_SubjectList _ERR_reverseSubjectList (ERR_SubjectList arg);
#define ERR_reverseSubjectList(arg) (_ERR_reverseSubjectList(arg))
#endif
#ifdef FAST_API
#define ERR_appendSubjectList(arg, elem) ((ERR_SubjectList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
ERR_SubjectList _ERR_appendSubjectList (ERR_SubjectList arg,
					ERR_Subject elem);
#define ERR_appendSubjectList(arg, elem) (_ERR_appendSubjectList(arg, elem))
#endif
#ifdef FAST_API
#define ERR_concatSubjectList(arg0, arg1) ((ERR_SubjectList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
ERR_SubjectList _ERR_concatSubjectList (ERR_SubjectList arg0,
					ERR_SubjectList arg1);
#define ERR_concatSubjectList(arg0, arg1) (_ERR_concatSubjectList(arg0, arg1))
#endif
#ifdef FAST_API
#define ERR_sliceSubjectList(arg, start, end) ((ERR_SubjectList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
ERR_SubjectList _ERR_sliceSubjectList (ERR_SubjectList arg, int start,
				       int end);
#define ERR_sliceSubjectList(arg, start, end) (_ERR_sliceSubjectList(arg, start, end))
#endif
#ifdef FAST_API
#define ERR_getSubjectListSubjectAt(arg, index) ((ERR_Subject) (ATelementAt((ATermList) arg,index)))
#else
ERR_Subject _ERR_getSubjectListSubjectAt (ERR_SubjectList arg, int index);
#define ERR_getSubjectListSubjectAt(arg, index) (_ERR_getSubjectListSubjectAt(arg, index))
#endif
#ifdef FAST_API
#define ERR_replaceSubjectListSubjectAt(arg, elem, index) ((ERR_SubjectList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
ERR_SubjectList _ERR_replaceSubjectListSubjectAt (ERR_SubjectList arg,
						  ERR_Subject elem,
						  int index);
#define ERR_replaceSubjectListSubjectAt(arg, elem, index) (_ERR_replaceSubjectListSubjectAt(arg, elem, index))
#endif
#ifdef FAST_API
#define ERR_makeSubjectList2(elem1,  elem2) ((ERR_SubjectList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
ERR_SubjectList _ERR_makeSubjectList2 (ERR_Subject elem1, ERR_Subject elem2);
#define ERR_makeSubjectList2(elem1,  elem2) (_ERR_makeSubjectList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define ERR_makeSubjectList3(elem1, elem2,  elem3) ((ERR_SubjectList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
ERR_SubjectList _ERR_makeSubjectList3 (ERR_Subject elem1, ERR_Subject elem2,
				       ERR_Subject elem3);
#define ERR_makeSubjectList3(elem1, elem2,  elem3) (_ERR_makeSubjectList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define ERR_makeSubjectList4(elem1, elem2, elem3,  elem4) ((ERR_SubjectList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
ERR_SubjectList _ERR_makeSubjectList4 (ERR_Subject elem1, ERR_Subject elem2,
				       ERR_Subject elem3, ERR_Subject elem4);
#define ERR_makeSubjectList4(elem1, elem2, elem3,  elem4) (_ERR_makeSubjectList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define ERR_makeSubjectList5(elem1, elem2, elem3, elem4,  elem5) ((ERR_SubjectList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
ERR_SubjectList _ERR_makeSubjectList5 (ERR_Subject elem1, ERR_Subject elem2,
				       ERR_Subject elem3, ERR_Subject elem4,
				       ERR_Subject elem5);
#define ERR_makeSubjectList5(elem1, elem2, elem3, elem4,  elem5) (_ERR_makeSubjectList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define ERR_makeSubjectList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((ERR_SubjectList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
ERR_SubjectList _ERR_makeSubjectList6 (ERR_Subject elem1, ERR_Subject elem2,
				       ERR_Subject elem3, ERR_Subject elem4,
				       ERR_Subject elem5, ERR_Subject elem6);
#define ERR_makeSubjectList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_ERR_makeSubjectList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define ERR_getErrorListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _ERR_getErrorListLength (ERR_ErrorList arg);
#define ERR_getErrorListLength(arg) (_ERR_getErrorListLength(arg))
#endif
#ifdef FAST_API
#define ERR_reverseErrorList(arg) ((ERR_ErrorList) ATreverse((ATermList) (arg)))
#else
ERR_ErrorList _ERR_reverseErrorList (ERR_ErrorList arg);
#define ERR_reverseErrorList(arg) (_ERR_reverseErrorList(arg))
#endif
#ifdef FAST_API
#define ERR_appendErrorList(arg, elem) ((ERR_ErrorList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
ERR_ErrorList _ERR_appendErrorList (ERR_ErrorList arg, ERR_Error elem);
#define ERR_appendErrorList(arg, elem) (_ERR_appendErrorList(arg, elem))
#endif
#ifdef FAST_API
#define ERR_concatErrorList(arg0, arg1) ((ERR_ErrorList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
ERR_ErrorList _ERR_concatErrorList (ERR_ErrorList arg0, ERR_ErrorList arg1);
#define ERR_concatErrorList(arg0, arg1) (_ERR_concatErrorList(arg0, arg1))
#endif
#ifdef FAST_API
#define ERR_sliceErrorList(arg, start, end) ((ERR_ErrorList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
ERR_ErrorList _ERR_sliceErrorList (ERR_ErrorList arg, int start, int end);
#define ERR_sliceErrorList(arg, start, end) (_ERR_sliceErrorList(arg, start, end))
#endif
#ifdef FAST_API
#define ERR_getErrorListErrorAt(arg, index) ((ERR_Error) (ATelementAt((ATermList) arg,index)))
#else
ERR_Error _ERR_getErrorListErrorAt (ERR_ErrorList arg, int index);
#define ERR_getErrorListErrorAt(arg, index) (_ERR_getErrorListErrorAt(arg, index))
#endif
#ifdef FAST_API
#define ERR_replaceErrorListErrorAt(arg, elem, index) ((ERR_ErrorList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
ERR_ErrorList _ERR_replaceErrorListErrorAt (ERR_ErrorList arg, ERR_Error elem,
					    int index);
#define ERR_replaceErrorListErrorAt(arg, elem, index) (_ERR_replaceErrorListErrorAt(arg, elem, index))
#endif
#ifdef FAST_API
#define ERR_makeErrorList2(elem1,  elem2) ((ERR_ErrorList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
ERR_ErrorList _ERR_makeErrorList2 (ERR_Error elem1, ERR_Error elem2);
#define ERR_makeErrorList2(elem1,  elem2) (_ERR_makeErrorList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define ERR_makeErrorList3(elem1, elem2,  elem3) ((ERR_ErrorList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
ERR_ErrorList _ERR_makeErrorList3 (ERR_Error elem1, ERR_Error elem2,
				   ERR_Error elem3);
#define ERR_makeErrorList3(elem1, elem2,  elem3) (_ERR_makeErrorList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define ERR_makeErrorList4(elem1, elem2, elem3,  elem4) ((ERR_ErrorList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
ERR_ErrorList _ERR_makeErrorList4 (ERR_Error elem1, ERR_Error elem2,
				   ERR_Error elem3, ERR_Error elem4);
#define ERR_makeErrorList4(elem1, elem2, elem3,  elem4) (_ERR_makeErrorList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define ERR_makeErrorList5(elem1, elem2, elem3, elem4,  elem5) ((ERR_ErrorList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
ERR_ErrorList _ERR_makeErrorList5 (ERR_Error elem1, ERR_Error elem2,
				   ERR_Error elem3, ERR_Error elem4,
				   ERR_Error elem5);
#define ERR_makeErrorList5(elem1, elem2, elem3, elem4,  elem5) (_ERR_makeErrorList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define ERR_makeErrorList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((ERR_ErrorList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
ERR_ErrorList _ERR_makeErrorList6 (ERR_Error elem1, ERR_Error elem2,
				   ERR_Error elem3, ERR_Error elem4,
				   ERR_Error elem5, ERR_Error elem6);
#define ERR_makeErrorList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_ERR_makeErrorList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define ERR_getAreaAreasLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _ERR_getAreaAreasLength (ERR_AreaAreas arg);
#define ERR_getAreaAreasLength(arg) (_ERR_getAreaAreasLength(arg))
#endif
#ifdef FAST_API
#define ERR_reverseAreaAreas(arg) ((ERR_AreaAreas) ATreverse((ATermList) (arg)))
#else
ERR_AreaAreas _ERR_reverseAreaAreas (ERR_AreaAreas arg);
#define ERR_reverseAreaAreas(arg) (_ERR_reverseAreaAreas(arg))
#endif
#ifdef FAST_API
#define ERR_appendAreaAreas(arg, elem) ((ERR_AreaAreas) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
ERR_AreaAreas _ERR_appendAreaAreas (ERR_AreaAreas arg, ERR_Area elem);
#define ERR_appendAreaAreas(arg, elem) (_ERR_appendAreaAreas(arg, elem))
#endif
#ifdef FAST_API
#define ERR_concatAreaAreas(arg0, arg1) ((ERR_AreaAreas) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
ERR_AreaAreas _ERR_concatAreaAreas (ERR_AreaAreas arg0, ERR_AreaAreas arg1);
#define ERR_concatAreaAreas(arg0, arg1) (_ERR_concatAreaAreas(arg0, arg1))
#endif
#ifdef FAST_API
#define ERR_sliceAreaAreas(arg, start, end) ((ERR_AreaAreas) ATgetSlice((ATermList) (arg), (start), (end)))
#else
ERR_AreaAreas _ERR_sliceAreaAreas (ERR_AreaAreas arg, int start, int end);
#define ERR_sliceAreaAreas(arg, start, end) (_ERR_sliceAreaAreas(arg, start, end))
#endif
#ifdef FAST_API
#define ERR_getAreaAreasAreaAt(arg, index) ((ERR_Area) (ATelementAt((ATermList) arg,index)))
#else
ERR_Area _ERR_getAreaAreasAreaAt (ERR_AreaAreas arg, int index);
#define ERR_getAreaAreasAreaAt(arg, index) (_ERR_getAreaAreasAreaAt(arg, index))
#endif
#ifdef FAST_API
#define ERR_replaceAreaAreasAreaAt(arg, elem, index) ((ERR_AreaAreas) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
ERR_AreaAreas _ERR_replaceAreaAreasAreaAt (ERR_AreaAreas arg, ERR_Area elem,
					   int index);
#define ERR_replaceAreaAreasAreaAt(arg, elem, index) (_ERR_replaceAreaAreasAreaAt(arg, elem, index))
#endif
#ifdef FAST_API
#define ERR_makeAreaAreas2(elem1,  elem2) ((ERR_AreaAreas) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
ERR_AreaAreas _ERR_makeAreaAreas2 (ERR_Area elem1, ERR_Area elem2);
#define ERR_makeAreaAreas2(elem1,  elem2) (_ERR_makeAreaAreas2(elem1,  elem2))
#endif
#ifdef FAST_API
#define ERR_makeAreaAreas3(elem1, elem2,  elem3) ((ERR_AreaAreas) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
ERR_AreaAreas _ERR_makeAreaAreas3 (ERR_Area elem1, ERR_Area elem2,
				   ERR_Area elem3);
#define ERR_makeAreaAreas3(elem1, elem2,  elem3) (_ERR_makeAreaAreas3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define ERR_makeAreaAreas4(elem1, elem2, elem3,  elem4) ((ERR_AreaAreas) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
ERR_AreaAreas _ERR_makeAreaAreas4 (ERR_Area elem1, ERR_Area elem2,
				   ERR_Area elem3, ERR_Area elem4);
#define ERR_makeAreaAreas4(elem1, elem2, elem3,  elem4) (_ERR_makeAreaAreas4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define ERR_makeAreaAreas5(elem1, elem2, elem3, elem4,  elem5) ((ERR_AreaAreas) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
ERR_AreaAreas _ERR_makeAreaAreas5 (ERR_Area elem1, ERR_Area elem2,
				   ERR_Area elem3, ERR_Area elem4,
				   ERR_Area elem5);
#define ERR_makeAreaAreas5(elem1, elem2, elem3, elem4,  elem5) (_ERR_makeAreaAreas5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define ERR_makeAreaAreas6(elem1, elem2, elem3, elem4, elem5,  elem6) ((ERR_AreaAreas) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
ERR_AreaAreas _ERR_makeAreaAreas6 (ERR_Area elem1, ERR_Area elem2,
				   ERR_Area elem3, ERR_Area elem4,
				   ERR_Area elem5, ERR_Area elem6);
#define ERR_makeAreaAreas6(elem1, elem2, elem3, elem4, elem5,  elem6) (_ERR_makeAreaAreas6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
ERR_StrChar ERR_makeStrCharStrChar (const char *string);
ERR_StrCon ERR_makeStrConStrCon (const char *string);
ERR_NatCon ERR_makeNatConNatCon (const char *string);
ERR_Subject ERR_makeSubjectSubject (const char *description);
ERR_Subject ERR_makeSubjectLocalized (const char *description,
				      ERR_Location Location);
ERR_Error ERR_makeErrorInfo (const char *description, ERR_SubjectList list);
ERR_Error ERR_makeErrorWarning (const char *description,
				ERR_SubjectList list);
ERR_Error ERR_makeErrorError (const char *description, ERR_SubjectList list);
ERR_Error ERR_makeErrorFatal (const char *description, ERR_SubjectList list);
ERR_Summary ERR_makeSummarySummary (const char *producer, const char *id,
				    ERR_ErrorList list);
ERR_SubjectList ERR_makeSubjectListEmpty (void);
ERR_SubjectList ERR_makeSubjectListSingle (ERR_Subject head);
ERR_SubjectList ERR_makeSubjectListMany (ERR_Subject head,
					 ERR_SubjectList tail);
ERR_ErrorList ERR_makeErrorListEmpty (void);
ERR_ErrorList ERR_makeErrorListSingle (ERR_Error head);
ERR_ErrorList ERR_makeErrorListMany (ERR_Error head, ERR_ErrorList tail);
ERR_Location ERR_makeLocationFile (const char *filename);
ERR_Location ERR_makeLocationArea (ERR_Area Area);
ERR_Location ERR_makeLocationAreaInFile (const char *filename, ERR_Area Area);
ERR_Area ERR_makeAreaArea (int beginLine, int beginColumn, int endLine,
			   int endColumn, int offset, int length);
ERR_Slice ERR_makeSliceSlice (const char *id, ERR_AreaAreas areas);
ERR_AreaAreas ERR_makeAreaAreasEmpty (void);
ERR_AreaAreas ERR_makeAreaAreasSingle (ERR_Area head);
ERR_AreaAreas ERR_makeAreaAreasMany (ERR_Area head, ERR_AreaAreas tail);
#ifdef FAST_API
#define ERR_isEqualStrChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ERR_isEqualStrChar (ERR_StrChar arg0, ERR_StrChar arg1);
#define ERR_isEqualStrChar(arg0, arg1) (_ERR_isEqualStrChar(arg0, arg1))
#endif
#ifdef FAST_API
#define ERR_isEqualStrCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ERR_isEqualStrCon (ERR_StrCon arg0, ERR_StrCon arg1);
#define ERR_isEqualStrCon(arg0, arg1) (_ERR_isEqualStrCon(arg0, arg1))
#endif
#ifdef FAST_API
#define ERR_isEqualNatCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ERR_isEqualNatCon (ERR_NatCon arg0, ERR_NatCon arg1);
#define ERR_isEqualNatCon(arg0, arg1) (_ERR_isEqualNatCon(arg0, arg1))
#endif
#ifdef FAST_API
#define ERR_isEqualSubject(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ERR_isEqualSubject (ERR_Subject arg0, ERR_Subject arg1);
#define ERR_isEqualSubject(arg0, arg1) (_ERR_isEqualSubject(arg0, arg1))
#endif
#ifdef FAST_API
#define ERR_isEqualError(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ERR_isEqualError (ERR_Error arg0, ERR_Error arg1);
#define ERR_isEqualError(arg0, arg1) (_ERR_isEqualError(arg0, arg1))
#endif
#ifdef FAST_API
#define ERR_isEqualSummary(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ERR_isEqualSummary (ERR_Summary arg0, ERR_Summary arg1);
#define ERR_isEqualSummary(arg0, arg1) (_ERR_isEqualSummary(arg0, arg1))
#endif
#ifdef FAST_API
#define ERR_isEqualSubjectList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ERR_isEqualSubjectList (ERR_SubjectList arg0, ERR_SubjectList arg1);
#define ERR_isEqualSubjectList(arg0, arg1) (_ERR_isEqualSubjectList(arg0, arg1))
#endif
#ifdef FAST_API
#define ERR_isEqualErrorList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ERR_isEqualErrorList (ERR_ErrorList arg0, ERR_ErrorList arg1);
#define ERR_isEqualErrorList(arg0, arg1) (_ERR_isEqualErrorList(arg0, arg1))
#endif
#ifdef FAST_API
#define ERR_isEqualLocation(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ERR_isEqualLocation (ERR_Location arg0, ERR_Location arg1);
#define ERR_isEqualLocation(arg0, arg1) (_ERR_isEqualLocation(arg0, arg1))
#endif
#ifdef FAST_API
#define ERR_isEqualArea(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ERR_isEqualArea (ERR_Area arg0, ERR_Area arg1);
#define ERR_isEqualArea(arg0, arg1) (_ERR_isEqualArea(arg0, arg1))
#endif
#ifdef FAST_API
#define ERR_isEqualSlice(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ERR_isEqualSlice (ERR_Slice arg0, ERR_Slice arg1);
#define ERR_isEqualSlice(arg0, arg1) (_ERR_isEqualSlice(arg0, arg1))
#endif
#ifdef FAST_API
#define ERR_isEqualAreaAreas(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ERR_isEqualAreaAreas (ERR_AreaAreas arg0, ERR_AreaAreas arg1);
#define ERR_isEqualAreaAreas(arg0, arg1) (_ERR_isEqualAreaAreas(arg0, arg1))
#endif
ATbool ERR_isValidStrChar (ERR_StrChar arg);
inline ATbool ERR_isStrCharStrChar (ERR_StrChar arg);
ATbool ERR_hasStrCharString (ERR_StrChar arg);
char *ERR_getStrCharString (ERR_StrChar arg);
ERR_StrChar ERR_setStrCharString (ERR_StrChar arg, const char *string);
ATbool ERR_isValidStrCon (ERR_StrCon arg);
inline ATbool ERR_isStrConStrCon (ERR_StrCon arg);
ATbool ERR_hasStrConString (ERR_StrCon arg);
char *ERR_getStrConString (ERR_StrCon arg);
ERR_StrCon ERR_setStrConString (ERR_StrCon arg, const char *string);
ATbool ERR_isValidNatCon (ERR_NatCon arg);
inline ATbool ERR_isNatConNatCon (ERR_NatCon arg);
ATbool ERR_hasNatConString (ERR_NatCon arg);
char *ERR_getNatConString (ERR_NatCon arg);
ERR_NatCon ERR_setNatConString (ERR_NatCon arg, const char *string);
ATbool ERR_isValidSubject (ERR_Subject arg);
inline ATbool ERR_isSubjectSubject (ERR_Subject arg);
inline ATbool ERR_isSubjectLocalized (ERR_Subject arg);
ATbool ERR_hasSubjectDescription (ERR_Subject arg);
ATbool ERR_hasSubjectLocation (ERR_Subject arg);
char *ERR_getSubjectDescription (ERR_Subject arg);
ERR_Location ERR_getSubjectLocation (ERR_Subject arg);
ERR_Subject ERR_setSubjectDescription (ERR_Subject arg,
				       const char *description);
ERR_Subject ERR_setSubjectLocation (ERR_Subject arg, ERR_Location Location);
ATbool ERR_isValidError (ERR_Error arg);
inline ATbool ERR_isErrorInfo (ERR_Error arg);
inline ATbool ERR_isErrorWarning (ERR_Error arg);
inline ATbool ERR_isErrorError (ERR_Error arg);
inline ATbool ERR_isErrorFatal (ERR_Error arg);
ATbool ERR_hasErrorDescription (ERR_Error arg);
ATbool ERR_hasErrorList (ERR_Error arg);
char *ERR_getErrorDescription (ERR_Error arg);
ERR_SubjectList ERR_getErrorList (ERR_Error arg);
ERR_Error ERR_setErrorDescription (ERR_Error arg, const char *description);
ERR_Error ERR_setErrorList (ERR_Error arg, ERR_SubjectList list);
ATbool ERR_isValidSummary (ERR_Summary arg);
inline ATbool ERR_isSummarySummary (ERR_Summary arg);
ATbool ERR_hasSummaryProducer (ERR_Summary arg);
ATbool ERR_hasSummaryId (ERR_Summary arg);
ATbool ERR_hasSummaryList (ERR_Summary arg);
char *ERR_getSummaryProducer (ERR_Summary arg);
char *ERR_getSummaryId (ERR_Summary arg);
ERR_ErrorList ERR_getSummaryList (ERR_Summary arg);
ERR_Summary ERR_setSummaryProducer (ERR_Summary arg, const char *producer);
ERR_Summary ERR_setSummaryId (ERR_Summary arg, const char *id);
ERR_Summary ERR_setSummaryList (ERR_Summary arg, ERR_ErrorList list);
ATbool ERR_isValidSubjectList (ERR_SubjectList arg);
inline ATbool ERR_isSubjectListEmpty (ERR_SubjectList arg);
inline ATbool ERR_isSubjectListSingle (ERR_SubjectList arg);
inline ATbool ERR_isSubjectListMany (ERR_SubjectList arg);
ATbool ERR_hasSubjectListHead (ERR_SubjectList arg);
ATbool ERR_hasSubjectListTail (ERR_SubjectList arg);
ERR_Subject ERR_getSubjectListHead (ERR_SubjectList arg);
ERR_SubjectList ERR_getSubjectListTail (ERR_SubjectList arg);
ERR_SubjectList ERR_setSubjectListHead (ERR_SubjectList arg,
					ERR_Subject head);
ERR_SubjectList ERR_setSubjectListTail (ERR_SubjectList arg,
					ERR_SubjectList tail);
ATbool ERR_isValidErrorList (ERR_ErrorList arg);
inline ATbool ERR_isErrorListEmpty (ERR_ErrorList arg);
inline ATbool ERR_isErrorListSingle (ERR_ErrorList arg);
inline ATbool ERR_isErrorListMany (ERR_ErrorList arg);
ATbool ERR_hasErrorListHead (ERR_ErrorList arg);
ATbool ERR_hasErrorListTail (ERR_ErrorList arg);
ERR_Error ERR_getErrorListHead (ERR_ErrorList arg);
ERR_ErrorList ERR_getErrorListTail (ERR_ErrorList arg);
ERR_ErrorList ERR_setErrorListHead (ERR_ErrorList arg, ERR_Error head);
ERR_ErrorList ERR_setErrorListTail (ERR_ErrorList arg, ERR_ErrorList tail);
ATbool ERR_isValidLocation (ERR_Location arg);
inline ATbool ERR_isLocationFile (ERR_Location arg);
inline ATbool ERR_isLocationArea (ERR_Location arg);
inline ATbool ERR_isLocationAreaInFile (ERR_Location arg);
ATbool ERR_hasLocationFilename (ERR_Location arg);
ATbool ERR_hasLocationArea (ERR_Location arg);
char *ERR_getLocationFilename (ERR_Location arg);
ERR_Area ERR_getLocationArea (ERR_Location arg);
ERR_Location ERR_setLocationFilename (ERR_Location arg, const char *filename);
ERR_Location ERR_setLocationArea (ERR_Location arg, ERR_Area Area);
ATbool ERR_isValidArea (ERR_Area arg);
inline ATbool ERR_isAreaArea (ERR_Area arg);
ATbool ERR_hasAreaBeginLine (ERR_Area arg);
ATbool ERR_hasAreaBeginColumn (ERR_Area arg);
ATbool ERR_hasAreaEndLine (ERR_Area arg);
ATbool ERR_hasAreaEndColumn (ERR_Area arg);
ATbool ERR_hasAreaOffset (ERR_Area arg);
ATbool ERR_hasAreaLength (ERR_Area arg);
int ERR_getAreaBeginLine (ERR_Area arg);
int ERR_getAreaBeginColumn (ERR_Area arg);
int ERR_getAreaEndLine (ERR_Area arg);
int ERR_getAreaEndColumn (ERR_Area arg);
int ERR_getAreaOffset (ERR_Area arg);
int ERR_getAreaLength (ERR_Area arg);
ERR_Area ERR_setAreaBeginLine (ERR_Area arg, int beginLine);
ERR_Area ERR_setAreaBeginColumn (ERR_Area arg, int beginColumn);
ERR_Area ERR_setAreaEndLine (ERR_Area arg, int endLine);
ERR_Area ERR_setAreaEndColumn (ERR_Area arg, int endColumn);
ERR_Area ERR_setAreaOffset (ERR_Area arg, int offset);
ERR_Area ERR_setAreaLength (ERR_Area arg, int length);
ATbool ERR_isValidSlice (ERR_Slice arg);
inline ATbool ERR_isSliceSlice (ERR_Slice arg);
ATbool ERR_hasSliceId (ERR_Slice arg);
ATbool ERR_hasSliceAreas (ERR_Slice arg);
char *ERR_getSliceId (ERR_Slice arg);
ERR_AreaAreas ERR_getSliceAreas (ERR_Slice arg);
ERR_Slice ERR_setSliceId (ERR_Slice arg, const char *id);
ERR_Slice ERR_setSliceAreas (ERR_Slice arg, ERR_AreaAreas areas);
ATbool ERR_isValidAreaAreas (ERR_AreaAreas arg);
inline ATbool ERR_isAreaAreasEmpty (ERR_AreaAreas arg);
inline ATbool ERR_isAreaAreasSingle (ERR_AreaAreas arg);
inline ATbool ERR_isAreaAreasMany (ERR_AreaAreas arg);
ATbool ERR_hasAreaAreasHead (ERR_AreaAreas arg);
ATbool ERR_hasAreaAreasTail (ERR_AreaAreas arg);
ERR_Area ERR_getAreaAreasHead (ERR_AreaAreas arg);
ERR_AreaAreas ERR_getAreaAreasTail (ERR_AreaAreas arg);
ERR_AreaAreas ERR_setAreaAreasHead (ERR_AreaAreas arg, ERR_Area head);
ERR_AreaAreas ERR_setAreaAreasTail (ERR_AreaAreas arg, ERR_AreaAreas tail);
ERR_StrChar ERR_visitStrChar (ERR_StrChar arg,
			      char *(*acceptString) (char *));
ERR_StrCon ERR_visitStrCon (ERR_StrCon arg, char *(*acceptString) (char *));
ERR_NatCon ERR_visitNatCon (ERR_NatCon arg, char *(*acceptString) (char *));
ERR_Subject ERR_visitSubject (ERR_Subject arg,
			      char *(*acceptDescription) (char *),
			      ERR_Location (*acceptLocation) (ERR_Location));
ERR_Error ERR_visitError (ERR_Error arg, char *(*acceptDescription) (char *),
			  ERR_SubjectList (*acceptList) (ERR_SubjectList));
ERR_Summary ERR_visitSummary (ERR_Summary arg,
			      char *(*acceptProducer) (char *),
			      char *(*acceptId) (char *),
			      ERR_ErrorList (*acceptList) (ERR_ErrorList));
ERR_SubjectList ERR_visitSubjectList (ERR_SubjectList arg,
				      ERR_Subject (*acceptHead)
				      (ERR_Subject));
ERR_ErrorList ERR_visitErrorList (ERR_ErrorList arg,
				  ERR_Error (*acceptHead) (ERR_Error));
ERR_Location ERR_visitLocation (ERR_Location arg,
				char *(*acceptFilename) (char *),
				ERR_Area (*acceptArea) (ERR_Area));
ERR_Area ERR_visitArea (ERR_Area arg, int (*acceptBeginLine) (int),
			int (*acceptBeginColumn) (int),
			int (*acceptEndLine) (int),
			int (*acceptEndColumn) (int),
			int (*acceptOffset) (int), int (*acceptLength) (int));
ERR_Slice ERR_visitSlice (ERR_Slice arg, char *(*acceptId) (char *),
			  ERR_AreaAreas (*acceptAreas) (ERR_AreaAreas));
ERR_AreaAreas ERR_visitAreaAreas (ERR_AreaAreas arg,
				  ERR_Area (*acceptHead) (ERR_Area));

#endif /* _ERROR_H */
