#ifndef _PARSEDERROR_H
#define _PARSEDERROR_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "ParsedError_dict.h"

typedef struct _PERR_OptLayout *PERR_OptLayout;
typedef struct _PERR_Layout *PERR_Layout;
typedef struct _PERR_LexLayoutList *PERR_LexLayoutList;
typedef struct _PERR_LexStrChar *PERR_LexStrChar;
typedef struct _PERR_StrChar *PERR_StrChar;
typedef struct _PERR_LexStrCon *PERR_LexStrCon;
typedef struct _PERR_StrCon *PERR_StrCon;
typedef struct _PERR_LexStrCharChars *PERR_LexStrCharChars;
typedef struct _PERR_LexNatCon *PERR_LexNatCon;
typedef struct _PERR_NatCon *PERR_NatCon;
typedef struct _PERR_LexLayout *PERR_LexLayout;
typedef struct _PERR_Start *PERR_Start;
typedef struct _PERR_Subject *PERR_Subject;
typedef struct _PERR_Error *PERR_Error;
typedef struct _PERR_Summary *PERR_Summary;
typedef struct _PERR_SubjectList *PERR_SubjectList;
typedef struct _PERR_ErrorList *PERR_ErrorList;
typedef struct _PERR_Location *PERR_Location;
typedef struct _PERR_Area *PERR_Area;
typedef struct _PERR_Slice *PERR_Slice;
typedef struct _PERR_AreaAreas *PERR_AreaAreas;

#ifdef FAST_API
#define PERR_initParsedErrorApi() (init_ParsedError_dict())
#else
void _PERR_initParsedErrorApi (void);
#define PERR_initParsedErrorApi() (_PERR_initParsedErrorApi())
#endif

#ifdef FAST_API
#define PERR_protectOptLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectOptLayout (PERR_OptLayout * arg);
#define PERR_protectOptLayout(arg) (_PERR_protectOptLayout(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectOptLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectOptLayout (PERR_OptLayout * arg);
#define PERR_unprotectOptLayout(arg) (_PERR_unprotectOptLayout(arg))
#endif
#ifdef FAST_API
#define PERR_protectLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectLayout (PERR_Layout * arg);
#define PERR_protectLayout(arg) (_PERR_protectLayout(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectLayout (PERR_Layout * arg);
#define PERR_unprotectLayout(arg) (_PERR_unprotectLayout(arg))
#endif
#ifdef FAST_API
#define PERR_protectLexLayoutList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectLexLayoutList (PERR_LexLayoutList * arg);
#define PERR_protectLexLayoutList(arg) (_PERR_protectLexLayoutList(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectLexLayoutList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectLexLayoutList (PERR_LexLayoutList * arg);
#define PERR_unprotectLexLayoutList(arg) (_PERR_unprotectLexLayoutList(arg))
#endif
#ifdef FAST_API
#define PERR_protectLexStrChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectLexStrChar (PERR_LexStrChar * arg);
#define PERR_protectLexStrChar(arg) (_PERR_protectLexStrChar(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectLexStrChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectLexStrChar (PERR_LexStrChar * arg);
#define PERR_unprotectLexStrChar(arg) (_PERR_unprotectLexStrChar(arg))
#endif
#ifdef FAST_API
#define PERR_protectStrChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectStrChar (PERR_StrChar * arg);
#define PERR_protectStrChar(arg) (_PERR_protectStrChar(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectStrChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectStrChar (PERR_StrChar * arg);
#define PERR_unprotectStrChar(arg) (_PERR_unprotectStrChar(arg))
#endif
#ifdef FAST_API
#define PERR_protectLexStrCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectLexStrCon (PERR_LexStrCon * arg);
#define PERR_protectLexStrCon(arg) (_PERR_protectLexStrCon(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectLexStrCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectLexStrCon (PERR_LexStrCon * arg);
#define PERR_unprotectLexStrCon(arg) (_PERR_unprotectLexStrCon(arg))
#endif
#ifdef FAST_API
#define PERR_protectStrCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectStrCon (PERR_StrCon * arg);
#define PERR_protectStrCon(arg) (_PERR_protectStrCon(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectStrCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectStrCon (PERR_StrCon * arg);
#define PERR_unprotectStrCon(arg) (_PERR_unprotectStrCon(arg))
#endif
#ifdef FAST_API
#define PERR_protectLexStrCharChars(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectLexStrCharChars (PERR_LexStrCharChars * arg);
#define PERR_protectLexStrCharChars(arg) (_PERR_protectLexStrCharChars(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectLexStrCharChars(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectLexStrCharChars (PERR_LexStrCharChars * arg);
#define PERR_unprotectLexStrCharChars(arg) (_PERR_unprotectLexStrCharChars(arg))
#endif
#ifdef FAST_API
#define PERR_protectLexNatCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectLexNatCon (PERR_LexNatCon * arg);
#define PERR_protectLexNatCon(arg) (_PERR_protectLexNatCon(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectLexNatCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectLexNatCon (PERR_LexNatCon * arg);
#define PERR_unprotectLexNatCon(arg) (_PERR_unprotectLexNatCon(arg))
#endif
#ifdef FAST_API
#define PERR_protectNatCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectNatCon (PERR_NatCon * arg);
#define PERR_protectNatCon(arg) (_PERR_protectNatCon(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectNatCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectNatCon (PERR_NatCon * arg);
#define PERR_unprotectNatCon(arg) (_PERR_unprotectNatCon(arg))
#endif
#ifdef FAST_API
#define PERR_protectLexLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectLexLayout (PERR_LexLayout * arg);
#define PERR_protectLexLayout(arg) (_PERR_protectLexLayout(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectLexLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectLexLayout (PERR_LexLayout * arg);
#define PERR_unprotectLexLayout(arg) (_PERR_unprotectLexLayout(arg))
#endif
#ifdef FAST_API
#define PERR_protectStart(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectStart (PERR_Start * arg);
#define PERR_protectStart(arg) (_PERR_protectStart(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectStart(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectStart (PERR_Start * arg);
#define PERR_unprotectStart(arg) (_PERR_unprotectStart(arg))
#endif
#ifdef FAST_API
#define PERR_protectSubject(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectSubject (PERR_Subject * arg);
#define PERR_protectSubject(arg) (_PERR_protectSubject(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectSubject(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectSubject (PERR_Subject * arg);
#define PERR_unprotectSubject(arg) (_PERR_unprotectSubject(arg))
#endif
#ifdef FAST_API
#define PERR_protectError(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectError (PERR_Error * arg);
#define PERR_protectError(arg) (_PERR_protectError(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectError(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectError (PERR_Error * arg);
#define PERR_unprotectError(arg) (_PERR_unprotectError(arg))
#endif
#ifdef FAST_API
#define PERR_protectSummary(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectSummary (PERR_Summary * arg);
#define PERR_protectSummary(arg) (_PERR_protectSummary(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectSummary(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectSummary (PERR_Summary * arg);
#define PERR_unprotectSummary(arg) (_PERR_unprotectSummary(arg))
#endif
#ifdef FAST_API
#define PERR_protectSubjectList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectSubjectList (PERR_SubjectList * arg);
#define PERR_protectSubjectList(arg) (_PERR_protectSubjectList(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectSubjectList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectSubjectList (PERR_SubjectList * arg);
#define PERR_unprotectSubjectList(arg) (_PERR_unprotectSubjectList(arg))
#endif
#ifdef FAST_API
#define PERR_protectErrorList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectErrorList (PERR_ErrorList * arg);
#define PERR_protectErrorList(arg) (_PERR_protectErrorList(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectErrorList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectErrorList (PERR_ErrorList * arg);
#define PERR_unprotectErrorList(arg) (_PERR_unprotectErrorList(arg))
#endif
#ifdef FAST_API
#define PERR_protectLocation(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectLocation (PERR_Location * arg);
#define PERR_protectLocation(arg) (_PERR_protectLocation(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectLocation(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectLocation (PERR_Location * arg);
#define PERR_unprotectLocation(arg) (_PERR_unprotectLocation(arg))
#endif
#ifdef FAST_API
#define PERR_protectArea(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectArea (PERR_Area * arg);
#define PERR_protectArea(arg) (_PERR_protectArea(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectArea(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectArea (PERR_Area * arg);
#define PERR_unprotectArea(arg) (_PERR_unprotectArea(arg))
#endif
#ifdef FAST_API
#define PERR_protectSlice(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectSlice (PERR_Slice * arg);
#define PERR_protectSlice(arg) (_PERR_protectSlice(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectSlice(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectSlice (PERR_Slice * arg);
#define PERR_unprotectSlice(arg) (_PERR_unprotectSlice(arg))
#endif
#ifdef FAST_API
#define PERR_protectAreaAreas(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PERR_protectAreaAreas (PERR_AreaAreas * arg);
#define PERR_protectAreaAreas(arg) (_PERR_protectAreaAreas(arg))
#endif
#ifdef FAST_API
#define PERR_unprotectAreaAreas(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PERR_unprotectAreaAreas (PERR_AreaAreas * arg);
#define PERR_unprotectAreaAreas(arg) (_PERR_unprotectAreaAreas(arg))
#endif
#ifdef FAST_API
#define PERR_OptLayoutFromTerm(t) ((((union {PERR_OptLayout target; ATerm source; })(t)).target))
#else
PERR_OptLayout _PERR_OptLayoutFromTerm (ATerm t);
#define PERR_OptLayoutFromTerm(t) (_PERR_OptLayoutFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_OptLayoutToTerm(arg) ((((union {PERR_OptLayout source; ATerm target; })(arg)).target))
#else
ATerm _PERR_OptLayoutToTerm (PERR_OptLayout arg);
#define PERR_OptLayoutToTerm(arg) (_PERR_OptLayoutToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_LayoutFromTerm(t) ((((union {PERR_Layout target; ATerm source; })(t)).target))
#else
PERR_Layout _PERR_LayoutFromTerm (ATerm t);
#define PERR_LayoutFromTerm(t) (_PERR_LayoutFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_LayoutToTerm(arg) ((((union {PERR_Layout source; ATerm target; })(arg)).target))
#else
ATerm _PERR_LayoutToTerm (PERR_Layout arg);
#define PERR_LayoutToTerm(arg) (_PERR_LayoutToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_LexLayoutListFromTerm(t) ((((union {PERR_LexLayoutList target; ATerm source; })(t)).target))
#else
PERR_LexLayoutList _PERR_LexLayoutListFromTerm (ATerm t);
#define PERR_LexLayoutListFromTerm(t) (_PERR_LexLayoutListFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_LexLayoutListToTerm(arg) ((((union {PERR_LexLayoutList source; ATerm target; })(arg)).target))
#else
ATerm _PERR_LexLayoutListToTerm (PERR_LexLayoutList arg);
#define PERR_LexLayoutListToTerm(arg) (_PERR_LexLayoutListToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_LexStrCharFromTerm(t) ((((union {PERR_LexStrChar target; ATerm source; })(t)).target))
#else
PERR_LexStrChar _PERR_LexStrCharFromTerm (ATerm t);
#define PERR_LexStrCharFromTerm(t) (_PERR_LexStrCharFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_LexStrCharToTerm(arg) ((((union {PERR_LexStrChar source; ATerm target; })(arg)).target))
#else
ATerm _PERR_LexStrCharToTerm (PERR_LexStrChar arg);
#define PERR_LexStrCharToTerm(arg) (_PERR_LexStrCharToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_StrCharFromTerm(t) ((((union {PERR_StrChar target; ATerm source; })(t)).target))
#else
PERR_StrChar _PERR_StrCharFromTerm (ATerm t);
#define PERR_StrCharFromTerm(t) (_PERR_StrCharFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_StrCharToTerm(arg) ((((union {PERR_StrChar source; ATerm target; })(arg)).target))
#else
ATerm _PERR_StrCharToTerm (PERR_StrChar arg);
#define PERR_StrCharToTerm(arg) (_PERR_StrCharToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_LexStrConFromTerm(t) ((((union {PERR_LexStrCon target; ATerm source; })(t)).target))
#else
PERR_LexStrCon _PERR_LexStrConFromTerm (ATerm t);
#define PERR_LexStrConFromTerm(t) (_PERR_LexStrConFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_LexStrConToTerm(arg) ((((union {PERR_LexStrCon source; ATerm target; })(arg)).target))
#else
ATerm _PERR_LexStrConToTerm (PERR_LexStrCon arg);
#define PERR_LexStrConToTerm(arg) (_PERR_LexStrConToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_StrConFromTerm(t) ((((union {PERR_StrCon target; ATerm source; })(t)).target))
#else
PERR_StrCon _PERR_StrConFromTerm (ATerm t);
#define PERR_StrConFromTerm(t) (_PERR_StrConFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_StrConToTerm(arg) ((((union {PERR_StrCon source; ATerm target; })(arg)).target))
#else
ATerm _PERR_StrConToTerm (PERR_StrCon arg);
#define PERR_StrConToTerm(arg) (_PERR_StrConToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_LexStrCharCharsFromTerm(t) ((((union {PERR_LexStrCharChars target; ATerm source; })(t)).target))
#else
PERR_LexStrCharChars _PERR_LexStrCharCharsFromTerm (ATerm t);
#define PERR_LexStrCharCharsFromTerm(t) (_PERR_LexStrCharCharsFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_LexStrCharCharsToTerm(arg) ((((union {PERR_LexStrCharChars source; ATerm target; })(arg)).target))
#else
ATerm _PERR_LexStrCharCharsToTerm (PERR_LexStrCharChars arg);
#define PERR_LexStrCharCharsToTerm(arg) (_PERR_LexStrCharCharsToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_LexNatConFromTerm(t) ((((union {PERR_LexNatCon target; ATerm source; })(t)).target))
#else
PERR_LexNatCon _PERR_LexNatConFromTerm (ATerm t);
#define PERR_LexNatConFromTerm(t) (_PERR_LexNatConFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_LexNatConToTerm(arg) ((((union {PERR_LexNatCon source; ATerm target; })(arg)).target))
#else
ATerm _PERR_LexNatConToTerm (PERR_LexNatCon arg);
#define PERR_LexNatConToTerm(arg) (_PERR_LexNatConToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_NatConFromTerm(t) ((((union {PERR_NatCon target; ATerm source; })(t)).target))
#else
PERR_NatCon _PERR_NatConFromTerm (ATerm t);
#define PERR_NatConFromTerm(t) (_PERR_NatConFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_NatConToTerm(arg) ((((union {PERR_NatCon source; ATerm target; })(arg)).target))
#else
ATerm _PERR_NatConToTerm (PERR_NatCon arg);
#define PERR_NatConToTerm(arg) (_PERR_NatConToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_LexLayoutFromTerm(t) ((((union {PERR_LexLayout target; ATerm source; })(t)).target))
#else
PERR_LexLayout _PERR_LexLayoutFromTerm (ATerm t);
#define PERR_LexLayoutFromTerm(t) (_PERR_LexLayoutFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_LexLayoutToTerm(arg) ((((union {PERR_LexLayout source; ATerm target; })(arg)).target))
#else
ATerm _PERR_LexLayoutToTerm (PERR_LexLayout arg);
#define PERR_LexLayoutToTerm(arg) (_PERR_LexLayoutToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_StartFromTerm(t) ((((union {PERR_Start target; ATerm source; })(t)).target))
#else
PERR_Start _PERR_StartFromTerm (ATerm t);
#define PERR_StartFromTerm(t) (_PERR_StartFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_StartToTerm(arg) ((((union {PERR_Start source; ATerm target; })(arg)).target))
#else
ATerm _PERR_StartToTerm (PERR_Start arg);
#define PERR_StartToTerm(arg) (_PERR_StartToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_SubjectFromTerm(t) ((((union {PERR_Subject target; ATerm source; })(t)).target))
#else
PERR_Subject _PERR_SubjectFromTerm (ATerm t);
#define PERR_SubjectFromTerm(t) (_PERR_SubjectFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_SubjectToTerm(arg) ((((union {PERR_Subject source; ATerm target; })(arg)).target))
#else
ATerm _PERR_SubjectToTerm (PERR_Subject arg);
#define PERR_SubjectToTerm(arg) (_PERR_SubjectToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_ErrorFromTerm(t) ((((union {PERR_Error target; ATerm source; })(t)).target))
#else
PERR_Error _PERR_ErrorFromTerm (ATerm t);
#define PERR_ErrorFromTerm(t) (_PERR_ErrorFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_ErrorToTerm(arg) ((((union {PERR_Error source; ATerm target; })(arg)).target))
#else
ATerm _PERR_ErrorToTerm (PERR_Error arg);
#define PERR_ErrorToTerm(arg) (_PERR_ErrorToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_SummaryFromTerm(t) ((((union {PERR_Summary target; ATerm source; })(t)).target))
#else
PERR_Summary _PERR_SummaryFromTerm (ATerm t);
#define PERR_SummaryFromTerm(t) (_PERR_SummaryFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_SummaryToTerm(arg) ((((union {PERR_Summary source; ATerm target; })(arg)).target))
#else
ATerm _PERR_SummaryToTerm (PERR_Summary arg);
#define PERR_SummaryToTerm(arg) (_PERR_SummaryToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_SubjectListFromTerm(t) ((((union {PERR_SubjectList target; ATerm source; })(t)).target))
#else
PERR_SubjectList _PERR_SubjectListFromTerm (ATerm t);
#define PERR_SubjectListFromTerm(t) (_PERR_SubjectListFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_SubjectListToTerm(arg) ((((union {PERR_SubjectList source; ATerm target; })(arg)).target))
#else
ATerm _PERR_SubjectListToTerm (PERR_SubjectList arg);
#define PERR_SubjectListToTerm(arg) (_PERR_SubjectListToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_ErrorListFromTerm(t) ((((union {PERR_ErrorList target; ATerm source; })(t)).target))
#else
PERR_ErrorList _PERR_ErrorListFromTerm (ATerm t);
#define PERR_ErrorListFromTerm(t) (_PERR_ErrorListFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_ErrorListToTerm(arg) ((((union {PERR_ErrorList source; ATerm target; })(arg)).target))
#else
ATerm _PERR_ErrorListToTerm (PERR_ErrorList arg);
#define PERR_ErrorListToTerm(arg) (_PERR_ErrorListToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_LocationFromTerm(t) ((((union {PERR_Location target; ATerm source; })(t)).target))
#else
PERR_Location _PERR_LocationFromTerm (ATerm t);
#define PERR_LocationFromTerm(t) (_PERR_LocationFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_LocationToTerm(arg) ((((union {PERR_Location source; ATerm target; })(arg)).target))
#else
ATerm _PERR_LocationToTerm (PERR_Location arg);
#define PERR_LocationToTerm(arg) (_PERR_LocationToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_AreaFromTerm(t) ((((union {PERR_Area target; ATerm source; })(t)).target))
#else
PERR_Area _PERR_AreaFromTerm (ATerm t);
#define PERR_AreaFromTerm(t) (_PERR_AreaFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_AreaToTerm(arg) ((((union {PERR_Area source; ATerm target; })(arg)).target))
#else
ATerm _PERR_AreaToTerm (PERR_Area arg);
#define PERR_AreaToTerm(arg) (_PERR_AreaToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_SliceFromTerm(t) ((((union {PERR_Slice target; ATerm source; })(t)).target))
#else
PERR_Slice _PERR_SliceFromTerm (ATerm t);
#define PERR_SliceFromTerm(t) (_PERR_SliceFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_SliceToTerm(arg) ((((union {PERR_Slice source; ATerm target; })(arg)).target))
#else
ATerm _PERR_SliceToTerm (PERR_Slice arg);
#define PERR_SliceToTerm(arg) (_PERR_SliceToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_AreaAreasFromTerm(t) ((((union {PERR_AreaAreas target; ATerm source; })(t)).target))
#else
PERR_AreaAreas _PERR_AreaAreasFromTerm (ATerm t);
#define PERR_AreaAreasFromTerm(t) (_PERR_AreaAreasFromTerm(t))
#endif
#ifdef FAST_API
#define PERR_AreaAreasToTerm(arg) ((((union {PERR_AreaAreas source; ATerm target; })(arg)).target))
#else
ATerm _PERR_AreaAreasToTerm (PERR_AreaAreas arg);
#define PERR_AreaAreasToTerm(arg) (_PERR_AreaAreasToTerm(arg))
#endif
#ifdef FAST_API
#define PERR_getLexLayoutListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PERR_getLexLayoutListLength (PERR_LexLayoutList arg);
#define PERR_getLexLayoutListLength(arg) (_PERR_getLexLayoutListLength(arg))
#endif
#ifdef FAST_API
#define PERR_reverseLexLayoutList(arg) ((PERR_LexLayoutList) ATreverse((ATermList) (arg)))
#else
PERR_LexLayoutList _PERR_reverseLexLayoutList (PERR_LexLayoutList arg);
#define PERR_reverseLexLayoutList(arg) (_PERR_reverseLexLayoutList(arg))
#endif
#ifdef FAST_API
#define PERR_appendLexLayoutList(arg, elem) ((PERR_LexLayoutList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PERR_LexLayoutList _PERR_appendLexLayoutList (PERR_LexLayoutList arg,
					      PERR_LexLayout elem);
#define PERR_appendLexLayoutList(arg, elem) (_PERR_appendLexLayoutList(arg, elem))
#endif
#ifdef FAST_API
#define PERR_concatLexLayoutList(arg0, arg1) ((PERR_LexLayoutList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PERR_LexLayoutList _PERR_concatLexLayoutList (PERR_LexLayoutList arg0,
					      PERR_LexLayoutList arg1);
#define PERR_concatLexLayoutList(arg0, arg1) (_PERR_concatLexLayoutList(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_sliceLexLayoutList(arg, start, end) ((PERR_LexLayoutList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PERR_LexLayoutList _PERR_sliceLexLayoutList (PERR_LexLayoutList arg,
					     int start, int end);
#define PERR_sliceLexLayoutList(arg, start, end) (_PERR_sliceLexLayoutList(arg, start, end))
#endif
#ifdef FAST_API
#define PERR_getLexLayoutListLexLayoutAt(arg, index) ((PERR_LexLayout) (ATelementAt((ATermList) arg,index)))
#else
PERR_LexLayout _PERR_getLexLayoutListLexLayoutAt (PERR_LexLayoutList arg,
						  int index);
#define PERR_getLexLayoutListLexLayoutAt(arg, index) (_PERR_getLexLayoutListLexLayoutAt(arg, index))
#endif
#ifdef FAST_API
#define PERR_replaceLexLayoutListLexLayoutAt(arg, elem, index) ((PERR_LexLayoutList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PERR_LexLayoutList _PERR_replaceLexLayoutListLexLayoutAt (PERR_LexLayoutList
							  arg,
							  PERR_LexLayout elem,
							  int index);
#define PERR_replaceLexLayoutListLexLayoutAt(arg, elem, index) (_PERR_replaceLexLayoutListLexLayoutAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PERR_makeLexLayoutList2(elem1,  elem2) ((PERR_LexLayoutList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PERR_LexLayoutList _PERR_makeLexLayoutList2 (PERR_LexLayout elem1,
					     PERR_LexLayout elem2);
#define PERR_makeLexLayoutList2(elem1,  elem2) (_PERR_makeLexLayoutList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PERR_makeLexLayoutList3(elem1, elem2,  elem3) ((PERR_LexLayoutList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PERR_LexLayoutList _PERR_makeLexLayoutList3 (PERR_LexLayout elem1,
					     PERR_LexLayout elem2,
					     PERR_LexLayout elem3);
#define PERR_makeLexLayoutList3(elem1, elem2,  elem3) (_PERR_makeLexLayoutList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PERR_makeLexLayoutList4(elem1, elem2, elem3,  elem4) ((PERR_LexLayoutList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PERR_LexLayoutList _PERR_makeLexLayoutList4 (PERR_LexLayout elem1,
					     PERR_LexLayout elem2,
					     PERR_LexLayout elem3,
					     PERR_LexLayout elem4);
#define PERR_makeLexLayoutList4(elem1, elem2, elem3,  elem4) (_PERR_makeLexLayoutList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PERR_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5) ((PERR_LexLayoutList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PERR_LexLayoutList _PERR_makeLexLayoutList5 (PERR_LexLayout elem1,
					     PERR_LexLayout elem2,
					     PERR_LexLayout elem3,
					     PERR_LexLayout elem4,
					     PERR_LexLayout elem5);
#define PERR_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5) (_PERR_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PERR_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PERR_LexLayoutList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PERR_LexLayoutList _PERR_makeLexLayoutList6 (PERR_LexLayout elem1,
					     PERR_LexLayout elem2,
					     PERR_LexLayout elem3,
					     PERR_LexLayout elem4,
					     PERR_LexLayout elem5,
					     PERR_LexLayout elem6);
#define PERR_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PERR_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define PERR_getLexStrCharCharsLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PERR_getLexStrCharCharsLength (PERR_LexStrCharChars arg);
#define PERR_getLexStrCharCharsLength(arg) (_PERR_getLexStrCharCharsLength(arg))
#endif
#ifdef FAST_API
#define PERR_reverseLexStrCharChars(arg) ((PERR_LexStrCharChars) ATreverse((ATermList) (arg)))
#else
PERR_LexStrCharChars _PERR_reverseLexStrCharChars (PERR_LexStrCharChars arg);
#define PERR_reverseLexStrCharChars(arg) (_PERR_reverseLexStrCharChars(arg))
#endif
#ifdef FAST_API
#define PERR_appendLexStrCharChars(arg, elem) ((PERR_LexStrCharChars) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PERR_LexStrCharChars _PERR_appendLexStrCharChars (PERR_LexStrCharChars arg,
						  PERR_LexStrChar elem);
#define PERR_appendLexStrCharChars(arg, elem) (_PERR_appendLexStrCharChars(arg, elem))
#endif
#ifdef FAST_API
#define PERR_concatLexStrCharChars(arg0, arg1) ((PERR_LexStrCharChars) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PERR_LexStrCharChars _PERR_concatLexStrCharChars (PERR_LexStrCharChars arg0,
						  PERR_LexStrCharChars arg1);
#define PERR_concatLexStrCharChars(arg0, arg1) (_PERR_concatLexStrCharChars(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_sliceLexStrCharChars(arg, start, end) ((PERR_LexStrCharChars) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PERR_LexStrCharChars _PERR_sliceLexStrCharChars (PERR_LexStrCharChars arg,
						 int start, int end);
#define PERR_sliceLexStrCharChars(arg, start, end) (_PERR_sliceLexStrCharChars(arg, start, end))
#endif
#ifdef FAST_API
#define PERR_getLexStrCharCharsLexStrCharAt(arg, index) ((PERR_LexStrChar) (ATelementAt((ATermList) arg,index)))
#else
PERR_LexStrChar _PERR_getLexStrCharCharsLexStrCharAt (PERR_LexStrCharChars
						      arg, int index);
#define PERR_getLexStrCharCharsLexStrCharAt(arg, index) (_PERR_getLexStrCharCharsLexStrCharAt(arg, index))
#endif
#ifdef FAST_API
#define PERR_replaceLexStrCharCharsLexStrCharAt(arg, elem, index) ((PERR_LexStrCharChars) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PERR_LexStrCharChars
_PERR_replaceLexStrCharCharsLexStrCharAt (PERR_LexStrCharChars arg,
					  PERR_LexStrChar elem, int index);
#define PERR_replaceLexStrCharCharsLexStrCharAt(arg, elem, index) (_PERR_replaceLexStrCharCharsLexStrCharAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PERR_makeLexStrCharChars2(elem1,  elem2) ((PERR_LexStrCharChars) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PERR_LexStrCharChars _PERR_makeLexStrCharChars2 (PERR_LexStrChar elem1,
						 PERR_LexStrChar elem2);
#define PERR_makeLexStrCharChars2(elem1,  elem2) (_PERR_makeLexStrCharChars2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PERR_makeLexStrCharChars3(elem1, elem2,  elem3) ((PERR_LexStrCharChars) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PERR_LexStrCharChars _PERR_makeLexStrCharChars3 (PERR_LexStrChar elem1,
						 PERR_LexStrChar elem2,
						 PERR_LexStrChar elem3);
#define PERR_makeLexStrCharChars3(elem1, elem2,  elem3) (_PERR_makeLexStrCharChars3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PERR_makeLexStrCharChars4(elem1, elem2, elem3,  elem4) ((PERR_LexStrCharChars) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PERR_LexStrCharChars _PERR_makeLexStrCharChars4 (PERR_LexStrChar elem1,
						 PERR_LexStrChar elem2,
						 PERR_LexStrChar elem3,
						 PERR_LexStrChar elem4);
#define PERR_makeLexStrCharChars4(elem1, elem2, elem3,  elem4) (_PERR_makeLexStrCharChars4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PERR_makeLexStrCharChars5(elem1, elem2, elem3, elem4,  elem5) ((PERR_LexStrCharChars) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PERR_LexStrCharChars _PERR_makeLexStrCharChars5 (PERR_LexStrChar elem1,
						 PERR_LexStrChar elem2,
						 PERR_LexStrChar elem3,
						 PERR_LexStrChar elem4,
						 PERR_LexStrChar elem5);
#define PERR_makeLexStrCharChars5(elem1, elem2, elem3, elem4,  elem5) (_PERR_makeLexStrCharChars5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PERR_makeLexStrCharChars6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PERR_LexStrCharChars) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PERR_LexStrCharChars _PERR_makeLexStrCharChars6 (PERR_LexStrChar elem1,
						 PERR_LexStrChar elem2,
						 PERR_LexStrChar elem3,
						 PERR_LexStrChar elem4,
						 PERR_LexStrChar elem5,
						 PERR_LexStrChar elem6);
#define PERR_makeLexStrCharChars6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PERR_makeLexStrCharChars6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define PERR_getSubjectListLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _PERR_getSubjectListLength (PERR_SubjectList arg);
#define PERR_getSubjectListLength(arg) (_PERR_getSubjectListLength(arg))
#endif
PERR_SubjectList PERR_reverseSubjectList (PERR_SubjectList arg);
PERR_SubjectList PERR_appendSubjectList (PERR_SubjectList arg0,
					 PERR_OptLayout wsAfterHead,
					 PERR_OptLayout wsAfterSep,
					 PERR_Subject arg1);
PERR_SubjectList PERR_concatSubjectList (PERR_SubjectList arg0,
					 PERR_OptLayout wsAfterHead,
					 PERR_OptLayout wsAfterSep,
					 PERR_SubjectList arg1);
#ifdef FAST_API
#define PERR_sliceSubjectList(arg, start, end) ((PERR_SubjectList) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
PERR_SubjectList _PERR_sliceSubjectList (PERR_SubjectList arg, int start,
					 int end);
#define PERR_sliceSubjectList(arg, start, end) (_PERR_sliceSubjectList(arg, start, end))
#endif
#ifdef FAST_API
#define PERR_getSubjectListSubjectAt(arg, index) ((PERR_Subject) (ATelementAt((ATermList) arg,index * 4)))
#else
PERR_Subject _PERR_getSubjectListSubjectAt (PERR_SubjectList arg, int index);
#define PERR_getSubjectListSubjectAt(arg, index) (_PERR_getSubjectListSubjectAt(arg, index))
#endif
#ifdef FAST_API
#define PERR_replaceSubjectListSubjectAt(arg, elem, index) ((PERR_SubjectList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
PERR_SubjectList _PERR_replaceSubjectListSubjectAt (PERR_SubjectList arg,
						    PERR_Subject elem,
						    int index);
#define PERR_replaceSubjectListSubjectAt(arg, elem, index) (_PERR_replaceSubjectListSubjectAt(arg, elem, index))
#endif
PERR_SubjectList PERR_makeSubjectList2 (PERR_OptLayout wsAfterHead,
					PERR_OptLayout wsAfterSep,
					PERR_Subject elem1,
					PERR_Subject elem2);
PERR_SubjectList PERR_makeSubjectList3 (PERR_OptLayout wsAfterHead,
					PERR_OptLayout wsAfterSep,
					PERR_Subject elem1,
					PERR_Subject elem2,
					PERR_Subject elem3);
PERR_SubjectList PERR_makeSubjectList4 (PERR_OptLayout wsAfterHead,
					PERR_OptLayout wsAfterSep,
					PERR_Subject elem1,
					PERR_Subject elem2,
					PERR_Subject elem3,
					PERR_Subject elem4);
PERR_SubjectList PERR_makeSubjectList5 (PERR_OptLayout wsAfterHead,
					PERR_OptLayout wsAfterSep,
					PERR_Subject elem1,
					PERR_Subject elem2,
					PERR_Subject elem3,
					PERR_Subject elem4,
					PERR_Subject elem5);
PERR_SubjectList PERR_makeSubjectList6 (PERR_OptLayout wsAfterHead,
					PERR_OptLayout wsAfterSep,
					PERR_Subject elem1,
					PERR_Subject elem2,
					PERR_Subject elem3,
					PERR_Subject elem4,
					PERR_Subject elem5,
					PERR_Subject elem6);
#ifdef FAST_API
#define PERR_getErrorListLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _PERR_getErrorListLength (PERR_ErrorList arg);
#define PERR_getErrorListLength(arg) (_PERR_getErrorListLength(arg))
#endif
PERR_ErrorList PERR_reverseErrorList (PERR_ErrorList arg);
PERR_ErrorList PERR_appendErrorList (PERR_ErrorList arg0,
				     PERR_OptLayout wsAfterHead,
				     PERR_OptLayout wsAfterSep,
				     PERR_Error arg1);
PERR_ErrorList PERR_concatErrorList (PERR_ErrorList arg0,
				     PERR_OptLayout wsAfterHead,
				     PERR_OptLayout wsAfterSep,
				     PERR_ErrorList arg1);
#ifdef FAST_API
#define PERR_sliceErrorList(arg, start, end) ((PERR_ErrorList) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
PERR_ErrorList _PERR_sliceErrorList (PERR_ErrorList arg, int start, int end);
#define PERR_sliceErrorList(arg, start, end) (_PERR_sliceErrorList(arg, start, end))
#endif
#ifdef FAST_API
#define PERR_getErrorListErrorAt(arg, index) ((PERR_Error) (ATelementAt((ATermList) arg,index * 4)))
#else
PERR_Error _PERR_getErrorListErrorAt (PERR_ErrorList arg, int index);
#define PERR_getErrorListErrorAt(arg, index) (_PERR_getErrorListErrorAt(arg, index))
#endif
#ifdef FAST_API
#define PERR_replaceErrorListErrorAt(arg, elem, index) ((PERR_ErrorList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
PERR_ErrorList _PERR_replaceErrorListErrorAt (PERR_ErrorList arg,
					      PERR_Error elem, int index);
#define PERR_replaceErrorListErrorAt(arg, elem, index) (_PERR_replaceErrorListErrorAt(arg, elem, index))
#endif
PERR_ErrorList PERR_makeErrorList2 (PERR_OptLayout wsAfterHead,
				    PERR_OptLayout wsAfterSep,
				    PERR_Error elem1, PERR_Error elem2);
PERR_ErrorList PERR_makeErrorList3 (PERR_OptLayout wsAfterHead,
				    PERR_OptLayout wsAfterSep,
				    PERR_Error elem1, PERR_Error elem2,
				    PERR_Error elem3);
PERR_ErrorList PERR_makeErrorList4 (PERR_OptLayout wsAfterHead,
				    PERR_OptLayout wsAfterSep,
				    PERR_Error elem1, PERR_Error elem2,
				    PERR_Error elem3, PERR_Error elem4);
PERR_ErrorList PERR_makeErrorList5 (PERR_OptLayout wsAfterHead,
				    PERR_OptLayout wsAfterSep,
				    PERR_Error elem1, PERR_Error elem2,
				    PERR_Error elem3, PERR_Error elem4,
				    PERR_Error elem5);
PERR_ErrorList PERR_makeErrorList6 (PERR_OptLayout wsAfterHead,
				    PERR_OptLayout wsAfterSep,
				    PERR_Error elem1, PERR_Error elem2,
				    PERR_Error elem3, PERR_Error elem4,
				    PERR_Error elem5, PERR_Error elem6);
#ifdef FAST_API
#define PERR_getAreaAreasLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _PERR_getAreaAreasLength (PERR_AreaAreas arg);
#define PERR_getAreaAreasLength(arg) (_PERR_getAreaAreasLength(arg))
#endif
PERR_AreaAreas PERR_reverseAreaAreas (PERR_AreaAreas arg);
PERR_AreaAreas PERR_appendAreaAreas (PERR_AreaAreas arg0,
				     PERR_OptLayout wsAfterHead,
				     PERR_OptLayout wsAfterSep,
				     PERR_Area arg1);
PERR_AreaAreas PERR_concatAreaAreas (PERR_AreaAreas arg0,
				     PERR_OptLayout wsAfterHead,
				     PERR_OptLayout wsAfterSep,
				     PERR_AreaAreas arg1);
#ifdef FAST_API
#define PERR_sliceAreaAreas(arg, start, end) ((PERR_AreaAreas) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
PERR_AreaAreas _PERR_sliceAreaAreas (PERR_AreaAreas arg, int start, int end);
#define PERR_sliceAreaAreas(arg, start, end) (_PERR_sliceAreaAreas(arg, start, end))
#endif
#ifdef FAST_API
#define PERR_getAreaAreasAreaAt(arg, index) ((PERR_Area) (ATelementAt((ATermList) arg,index * 4)))
#else
PERR_Area _PERR_getAreaAreasAreaAt (PERR_AreaAreas arg, int index);
#define PERR_getAreaAreasAreaAt(arg, index) (_PERR_getAreaAreasAreaAt(arg, index))
#endif
#ifdef FAST_API
#define PERR_replaceAreaAreasAreaAt(arg, elem, index) ((PERR_AreaAreas) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
PERR_AreaAreas _PERR_replaceAreaAreasAreaAt (PERR_AreaAreas arg,
					     PERR_Area elem, int index);
#define PERR_replaceAreaAreasAreaAt(arg, elem, index) (_PERR_replaceAreaAreasAreaAt(arg, elem, index))
#endif
PERR_AreaAreas PERR_makeAreaAreas2 (PERR_OptLayout wsAfterHead,
				    PERR_OptLayout wsAfterSep,
				    PERR_Area elem1, PERR_Area elem2);
PERR_AreaAreas PERR_makeAreaAreas3 (PERR_OptLayout wsAfterHead,
				    PERR_OptLayout wsAfterSep,
				    PERR_Area elem1, PERR_Area elem2,
				    PERR_Area elem3);
PERR_AreaAreas PERR_makeAreaAreas4 (PERR_OptLayout wsAfterHead,
				    PERR_OptLayout wsAfterSep,
				    PERR_Area elem1, PERR_Area elem2,
				    PERR_Area elem3, PERR_Area elem4);
PERR_AreaAreas PERR_makeAreaAreas5 (PERR_OptLayout wsAfterHead,
				    PERR_OptLayout wsAfterSep,
				    PERR_Area elem1, PERR_Area elem2,
				    PERR_Area elem3, PERR_Area elem4,
				    PERR_Area elem5);
PERR_AreaAreas PERR_makeAreaAreas6 (PERR_OptLayout wsAfterHead,
				    PERR_OptLayout wsAfterSep,
				    PERR_Area elem1, PERR_Area elem2,
				    PERR_Area elem3, PERR_Area elem4,
				    PERR_Area elem5, PERR_Area elem6);
PERR_OptLayout PERR_makeOptLayoutAbsent (void);
PERR_OptLayout PERR_makeOptLayoutPresent (PERR_Layout layout);
PERR_Layout PERR_makeLayoutLexToCf (PERR_LexLayoutList list);
PERR_LexLayoutList PERR_makeLexLayoutListEmpty (void);
PERR_LexLayoutList PERR_makeLexLayoutListSingle (PERR_LexLayout head);
PERR_LexLayoutList PERR_makeLexLayoutListMany (PERR_LexLayout head,
					       PERR_LexLayoutList tail);
PERR_LexStrChar PERR_makeLexStrCharNewline (void);
PERR_LexStrChar PERR_makeLexStrCharTab (void);
PERR_LexStrChar PERR_makeLexStrCharQuote (void);
PERR_LexStrChar PERR_makeLexStrCharBackslash (void);
PERR_LexStrChar PERR_makeLexStrCharDecimal (char a, char b, char c);
PERR_LexStrChar PERR_makeLexStrCharNormal (char ch);
PERR_StrChar PERR_makeStrCharLexToCf (PERR_LexStrChar StrChar);
PERR_LexStrCon PERR_makeLexStrConDefault (PERR_LexStrCharChars chars);
PERR_StrCon PERR_makeStrConLexToCf (PERR_LexStrCon StrCon);
PERR_LexStrCharChars PERR_makeLexStrCharCharsEmpty (void);
PERR_LexStrCharChars PERR_makeLexStrCharCharsSingle (PERR_LexStrChar head);
PERR_LexStrCharChars PERR_makeLexStrCharCharsMany (PERR_LexStrChar head,
						   PERR_LexStrCharChars tail);
PERR_LexNatCon PERR_makeLexNatConDigits (const char *list);
PERR_NatCon PERR_makeNatConLexToCf (PERR_LexNatCon NatCon);
PERR_LexLayout PERR_makeLexLayoutWhitespace (char ch);
PERR_Start PERR_makeStartSummary (PERR_OptLayout wsBefore,
				  PERR_Summary topSummary,
				  PERR_OptLayout wsAfter, int ambCnt);
PERR_Start PERR_makeStartError (PERR_OptLayout wsBefore, PERR_Error topError,
				PERR_OptLayout wsAfter, int ambCnt);
PERR_Subject PERR_makeSubjectSubject (PERR_OptLayout wsAfterSubject,
				      PERR_OptLayout wsAfterParenOpen,
				      PERR_StrCon description,
				      PERR_OptLayout wsAfterDescription);
PERR_Subject PERR_makeSubjectLocalized (PERR_OptLayout wsAfterLocalized,
					PERR_OptLayout wsAfterParenOpen,
					PERR_StrCon description,
					PERR_OptLayout wsAfterDescription,
					PERR_OptLayout wsAfterComma,
					PERR_Location Location,
					PERR_OptLayout wsAfterLocation);
PERR_Error PERR_makeErrorInfo (PERR_OptLayout wsAfterInfo,
			       PERR_OptLayout wsAfterParenOpen,
			       PERR_StrCon description,
			       PERR_OptLayout wsAfterDescription,
			       PERR_OptLayout wsAfterComma,
			       PERR_OptLayout wsAfterBracketOpen,
			       PERR_SubjectList list,
			       PERR_OptLayout wsAfterList,
			       PERR_OptLayout wsAfterBracketClose);
PERR_Error PERR_makeErrorWarning (PERR_OptLayout wsAfterWarning,
				  PERR_OptLayout wsAfterParenOpen,
				  PERR_StrCon description,
				  PERR_OptLayout wsAfterDescription,
				  PERR_OptLayout wsAfterComma,
				  PERR_OptLayout wsAfterBracketOpen,
				  PERR_SubjectList list,
				  PERR_OptLayout wsAfterList,
				  PERR_OptLayout wsAfterBracketClose);
PERR_Error PERR_makeErrorError (PERR_OptLayout wsAfterError,
				PERR_OptLayout wsAfterParenOpen,
				PERR_StrCon description,
				PERR_OptLayout wsAfterDescription,
				PERR_OptLayout wsAfterComma,
				PERR_OptLayout wsAfterBracketOpen,
				PERR_SubjectList list,
				PERR_OptLayout wsAfterList,
				PERR_OptLayout wsAfterBracketClose);
PERR_Error PERR_makeErrorFatal (PERR_OptLayout wsAfterFatal,
				PERR_OptLayout wsAfterParenOpen,
				PERR_StrCon description,
				PERR_OptLayout wsAfterDescription,
				PERR_OptLayout wsAfterComma,
				PERR_OptLayout wsAfterBracketOpen,
				PERR_SubjectList list,
				PERR_OptLayout wsAfterList,
				PERR_OptLayout wsAfterBracketClose);
PERR_Summary PERR_makeSummarySummary (PERR_OptLayout wsAfterSummary,
				      PERR_OptLayout wsAfterParenOpen,
				      PERR_StrCon producer,
				      PERR_OptLayout wsAfterProducer,
				      PERR_OptLayout wsAfterComma,
				      PERR_StrCon id,
				      PERR_OptLayout wsAfterId,
				      PERR_OptLayout wsAfterComma1,
				      PERR_OptLayout wsAfterBracketOpen,
				      PERR_ErrorList list,
				      PERR_OptLayout wsAfterList,
				      PERR_OptLayout wsAfterBracketClose);
PERR_SubjectList PERR_makeSubjectListEmpty (void);
PERR_SubjectList PERR_makeSubjectListSingle (PERR_Subject head);
PERR_SubjectList PERR_makeSubjectListMany (PERR_Subject head,
					   PERR_OptLayout wsAfterHead,
					   PERR_OptLayout wsAfterSep,
					   PERR_SubjectList tail);
PERR_ErrorList PERR_makeErrorListEmpty (void);
PERR_ErrorList PERR_makeErrorListSingle (PERR_Error head);
PERR_ErrorList PERR_makeErrorListMany (PERR_Error head,
				       PERR_OptLayout wsAfterHead,
				       PERR_OptLayout wsAfterSep,
				       PERR_ErrorList tail);
PERR_Location PERR_makeLocationFile (PERR_OptLayout wsAfterFile,
				     PERR_OptLayout wsAfterParenOpen,
				     PERR_StrCon filename,
				     PERR_OptLayout wsAfterFilename);
PERR_Location PERR_makeLocationArea (PERR_OptLayout wsAfterA,
				     PERR_OptLayout wsAfterParenOpen,
				     PERR_Area Area,
				     PERR_OptLayout wsAfterArea);
PERR_Location PERR_makeLocationAreaInFile (PERR_OptLayout wsAfterAreaInFile,
					   PERR_OptLayout wsAfterParenOpen,
					   PERR_StrCon filename,
					   PERR_OptLayout wsAfterFilename,
					   PERR_OptLayout wsAfterComma,
					   PERR_Area Area,
					   PERR_OptLayout wsAfterArea);
PERR_Area PERR_makeAreaArea (PERR_OptLayout wsAfterArea,
			     PERR_OptLayout wsAfterParenOpen,
			     PERR_NatCon beginLine,
			     PERR_OptLayout wsAfterBeginLine,
			     PERR_OptLayout wsAfterComma,
			     PERR_NatCon beginColumn,
			     PERR_OptLayout wsAfterBeginColumn,
			     PERR_OptLayout wsAfterComma1,
			     PERR_NatCon endLine,
			     PERR_OptLayout wsAfterEndLine,
			     PERR_OptLayout wsAfterComma2,
			     PERR_NatCon endColumn,
			     PERR_OptLayout wsAfterEndColumn,
			     PERR_OptLayout wsAfterComma3, PERR_NatCon offset,
			     PERR_OptLayout wsAfterOffset,
			     PERR_OptLayout wsAfterComma4, PERR_NatCon length,
			     PERR_OptLayout wsAfterLength);
PERR_Slice PERR_makeSliceSlice (PERR_OptLayout wsAfterSlice,
				PERR_OptLayout wsAfterParenOpen,
				PERR_StrCon id, PERR_OptLayout wsAfterId,
				PERR_OptLayout wsAfterComma,
				PERR_OptLayout wsAfterBracketOpen,
				PERR_AreaAreas areas,
				PERR_OptLayout wsAfterAreas,
				PERR_OptLayout wsAfterBracketClose);
PERR_AreaAreas PERR_makeAreaAreasEmpty (void);
PERR_AreaAreas PERR_makeAreaAreasSingle (PERR_Area head);
PERR_AreaAreas PERR_makeAreaAreasMany (PERR_Area head,
				       PERR_OptLayout wsAfterHead,
				       PERR_OptLayout wsAfterSep,
				       PERR_AreaAreas tail);
#ifdef FAST_API
#define PERR_isEqualOptLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualOptLayout (PERR_OptLayout arg0, PERR_OptLayout arg1);
#define PERR_isEqualOptLayout(arg0, arg1) (_PERR_isEqualOptLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualLayout (PERR_Layout arg0, PERR_Layout arg1);
#define PERR_isEqualLayout(arg0, arg1) (_PERR_isEqualLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualLexLayoutList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualLexLayoutList (PERR_LexLayoutList arg0,
				   PERR_LexLayoutList arg1);
#define PERR_isEqualLexLayoutList(arg0, arg1) (_PERR_isEqualLexLayoutList(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualLexStrChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualLexStrChar (PERR_LexStrChar arg0, PERR_LexStrChar arg1);
#define PERR_isEqualLexStrChar(arg0, arg1) (_PERR_isEqualLexStrChar(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualStrChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualStrChar (PERR_StrChar arg0, PERR_StrChar arg1);
#define PERR_isEqualStrChar(arg0, arg1) (_PERR_isEqualStrChar(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualLexStrCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualLexStrCon (PERR_LexStrCon arg0, PERR_LexStrCon arg1);
#define PERR_isEqualLexStrCon(arg0, arg1) (_PERR_isEqualLexStrCon(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualStrCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualStrCon (PERR_StrCon arg0, PERR_StrCon arg1);
#define PERR_isEqualStrCon(arg0, arg1) (_PERR_isEqualStrCon(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualLexStrCharChars(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualLexStrCharChars (PERR_LexStrCharChars arg0,
				     PERR_LexStrCharChars arg1);
#define PERR_isEqualLexStrCharChars(arg0, arg1) (_PERR_isEqualLexStrCharChars(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualLexNatCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualLexNatCon (PERR_LexNatCon arg0, PERR_LexNatCon arg1);
#define PERR_isEqualLexNatCon(arg0, arg1) (_PERR_isEqualLexNatCon(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualNatCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualNatCon (PERR_NatCon arg0, PERR_NatCon arg1);
#define PERR_isEqualNatCon(arg0, arg1) (_PERR_isEqualNatCon(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualLexLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualLexLayout (PERR_LexLayout arg0, PERR_LexLayout arg1);
#define PERR_isEqualLexLayout(arg0, arg1) (_PERR_isEqualLexLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualStart(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualStart (PERR_Start arg0, PERR_Start arg1);
#define PERR_isEqualStart(arg0, arg1) (_PERR_isEqualStart(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualSubject(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualSubject (PERR_Subject arg0, PERR_Subject arg1);
#define PERR_isEqualSubject(arg0, arg1) (_PERR_isEqualSubject(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualError(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualError (PERR_Error arg0, PERR_Error arg1);
#define PERR_isEqualError(arg0, arg1) (_PERR_isEqualError(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualSummary(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualSummary (PERR_Summary arg0, PERR_Summary arg1);
#define PERR_isEqualSummary(arg0, arg1) (_PERR_isEqualSummary(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualSubjectList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualSubjectList (PERR_SubjectList arg0,
				 PERR_SubjectList arg1);
#define PERR_isEqualSubjectList(arg0, arg1) (_PERR_isEqualSubjectList(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualErrorList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualErrorList (PERR_ErrorList arg0, PERR_ErrorList arg1);
#define PERR_isEqualErrorList(arg0, arg1) (_PERR_isEqualErrorList(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualLocation(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualLocation (PERR_Location arg0, PERR_Location arg1);
#define PERR_isEqualLocation(arg0, arg1) (_PERR_isEqualLocation(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualArea(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualArea (PERR_Area arg0, PERR_Area arg1);
#define PERR_isEqualArea(arg0, arg1) (_PERR_isEqualArea(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualSlice(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualSlice (PERR_Slice arg0, PERR_Slice arg1);
#define PERR_isEqualSlice(arg0, arg1) (_PERR_isEqualSlice(arg0, arg1))
#endif
#ifdef FAST_API
#define PERR_isEqualAreaAreas(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PERR_isEqualAreaAreas (PERR_AreaAreas arg0, PERR_AreaAreas arg1);
#define PERR_isEqualAreaAreas(arg0, arg1) (_PERR_isEqualAreaAreas(arg0, arg1))
#endif
ATbool PERR_isValidOptLayout (PERR_OptLayout arg);
inline ATbool PERR_isOptLayoutAbsent (PERR_OptLayout arg);
inline ATbool PERR_isOptLayoutPresent (PERR_OptLayout arg);
ATbool PERR_hasOptLayoutLayout (PERR_OptLayout arg);
PERR_Layout PERR_getOptLayoutLayout (PERR_OptLayout arg);
PERR_OptLayout PERR_setOptLayoutLayout (PERR_OptLayout arg,
					PERR_Layout layout);
ATbool PERR_isValidLayout (PERR_Layout arg);
inline ATbool PERR_isLayoutLexToCf (PERR_Layout arg);
ATbool PERR_hasLayoutList (PERR_Layout arg);
PERR_LexLayoutList PERR_getLayoutList (PERR_Layout arg);
PERR_Layout PERR_setLayoutList (PERR_Layout arg, PERR_LexLayoutList list);
ATbool PERR_isValidLexLayoutList (PERR_LexLayoutList arg);
inline ATbool PERR_isLexLayoutListEmpty (PERR_LexLayoutList arg);
inline ATbool PERR_isLexLayoutListSingle (PERR_LexLayoutList arg);
inline ATbool PERR_isLexLayoutListMany (PERR_LexLayoutList arg);
ATbool PERR_hasLexLayoutListHead (PERR_LexLayoutList arg);
ATbool PERR_hasLexLayoutListTail (PERR_LexLayoutList arg);
PERR_LexLayout PERR_getLexLayoutListHead (PERR_LexLayoutList arg);
PERR_LexLayoutList PERR_getLexLayoutListTail (PERR_LexLayoutList arg);
PERR_LexLayoutList PERR_setLexLayoutListHead (PERR_LexLayoutList arg,
					      PERR_LexLayout head);
PERR_LexLayoutList PERR_setLexLayoutListTail (PERR_LexLayoutList arg,
					      PERR_LexLayoutList tail);
ATbool PERR_isValidLexStrChar (PERR_LexStrChar arg);
inline ATbool PERR_isLexStrCharNewline (PERR_LexStrChar arg);
inline ATbool PERR_isLexStrCharTab (PERR_LexStrChar arg);
inline ATbool PERR_isLexStrCharQuote (PERR_LexStrChar arg);
inline ATbool PERR_isLexStrCharBackslash (PERR_LexStrChar arg);
inline ATbool PERR_isLexStrCharDecimal (PERR_LexStrChar arg);
inline ATbool PERR_isLexStrCharNormal (PERR_LexStrChar arg);
ATbool PERR_hasLexStrCharA (PERR_LexStrChar arg);
ATbool PERR_hasLexStrCharB (PERR_LexStrChar arg);
ATbool PERR_hasLexStrCharC (PERR_LexStrChar arg);
ATbool PERR_hasLexStrCharCh (PERR_LexStrChar arg);
char PERR_getLexStrCharA (PERR_LexStrChar arg);
char PERR_getLexStrCharB (PERR_LexStrChar arg);
char PERR_getLexStrCharC (PERR_LexStrChar arg);
char PERR_getLexStrCharCh (PERR_LexStrChar arg);
PERR_LexStrChar PERR_setLexStrCharA (PERR_LexStrChar arg, char a);
PERR_LexStrChar PERR_setLexStrCharB (PERR_LexStrChar arg, char b);
PERR_LexStrChar PERR_setLexStrCharC (PERR_LexStrChar arg, char c);
PERR_LexStrChar PERR_setLexStrCharCh (PERR_LexStrChar arg, char ch);
ATbool PERR_isValidStrChar (PERR_StrChar arg);
inline ATbool PERR_isStrCharLexToCf (PERR_StrChar arg);
ATbool PERR_hasStrCharStrChar (PERR_StrChar arg);
PERR_LexStrChar PERR_getStrCharStrChar (PERR_StrChar arg);
PERR_StrChar PERR_setStrCharStrChar (PERR_StrChar arg,
				     PERR_LexStrChar StrChar);
ATbool PERR_isValidLexStrCon (PERR_LexStrCon arg);
inline ATbool PERR_isLexStrConDefault (PERR_LexStrCon arg);
ATbool PERR_hasLexStrConChars (PERR_LexStrCon arg);
PERR_LexStrCharChars PERR_getLexStrConChars (PERR_LexStrCon arg);
PERR_LexStrCon PERR_setLexStrConChars (PERR_LexStrCon arg,
				       PERR_LexStrCharChars chars);
ATbool PERR_isValidStrCon (PERR_StrCon arg);
inline ATbool PERR_isStrConLexToCf (PERR_StrCon arg);
ATbool PERR_hasStrConStrCon (PERR_StrCon arg);
PERR_LexStrCon PERR_getStrConStrCon (PERR_StrCon arg);
PERR_StrCon PERR_setStrConStrCon (PERR_StrCon arg, PERR_LexStrCon StrCon);
ATbool PERR_isValidLexStrCharChars (PERR_LexStrCharChars arg);
inline ATbool PERR_isLexStrCharCharsEmpty (PERR_LexStrCharChars arg);
inline ATbool PERR_isLexStrCharCharsSingle (PERR_LexStrCharChars arg);
inline ATbool PERR_isLexStrCharCharsMany (PERR_LexStrCharChars arg);
ATbool PERR_hasLexStrCharCharsHead (PERR_LexStrCharChars arg);
ATbool PERR_hasLexStrCharCharsTail (PERR_LexStrCharChars arg);
PERR_LexStrChar PERR_getLexStrCharCharsHead (PERR_LexStrCharChars arg);
PERR_LexStrCharChars PERR_getLexStrCharCharsTail (PERR_LexStrCharChars arg);
PERR_LexStrCharChars PERR_setLexStrCharCharsHead (PERR_LexStrCharChars arg,
						  PERR_LexStrChar head);
PERR_LexStrCharChars PERR_setLexStrCharCharsTail (PERR_LexStrCharChars arg,
						  PERR_LexStrCharChars tail);
ATbool PERR_isValidLexNatCon (PERR_LexNatCon arg);
inline ATbool PERR_isLexNatConDigits (PERR_LexNatCon arg);
ATbool PERR_hasLexNatConList (PERR_LexNatCon arg);
char *PERR_getLexNatConList (PERR_LexNatCon arg);
PERR_LexNatCon PERR_setLexNatConList (PERR_LexNatCon arg, const char *list);
ATbool PERR_isValidNatCon (PERR_NatCon arg);
inline ATbool PERR_isNatConLexToCf (PERR_NatCon arg);
ATbool PERR_hasNatConNatCon (PERR_NatCon arg);
PERR_LexNatCon PERR_getNatConNatCon (PERR_NatCon arg);
PERR_NatCon PERR_setNatConNatCon (PERR_NatCon arg, PERR_LexNatCon NatCon);
ATbool PERR_isValidLexLayout (PERR_LexLayout arg);
inline ATbool PERR_isLexLayoutWhitespace (PERR_LexLayout arg);
ATbool PERR_hasLexLayoutCh (PERR_LexLayout arg);
char PERR_getLexLayoutCh (PERR_LexLayout arg);
PERR_LexLayout PERR_setLexLayoutCh (PERR_LexLayout arg, char ch);
ATbool PERR_isValidStart (PERR_Start arg);
inline ATbool PERR_isStartSummary (PERR_Start arg);
inline ATbool PERR_isStartError (PERR_Start arg);
ATbool PERR_hasStartWsBefore (PERR_Start arg);
ATbool PERR_hasStartTopSummary (PERR_Start arg);
ATbool PERR_hasStartWsAfter (PERR_Start arg);
ATbool PERR_hasStartAmbCnt (PERR_Start arg);
ATbool PERR_hasStartTopError (PERR_Start arg);
PERR_OptLayout PERR_getStartWsBefore (PERR_Start arg);
PERR_Summary PERR_getStartTopSummary (PERR_Start arg);
PERR_OptLayout PERR_getStartWsAfter (PERR_Start arg);
int PERR_getStartAmbCnt (PERR_Start arg);
PERR_Error PERR_getStartTopError (PERR_Start arg);
PERR_Start PERR_setStartWsBefore (PERR_Start arg, PERR_OptLayout wsBefore);
PERR_Start PERR_setStartTopSummary (PERR_Start arg, PERR_Summary topSummary);
PERR_Start PERR_setStartWsAfter (PERR_Start arg, PERR_OptLayout wsAfter);
PERR_Start PERR_setStartAmbCnt (PERR_Start arg, int ambCnt);
PERR_Start PERR_setStartTopError (PERR_Start arg, PERR_Error topError);
ATbool PERR_isValidSubject (PERR_Subject arg);
inline ATbool PERR_isSubjectSubject (PERR_Subject arg);
inline ATbool PERR_isSubjectLocalized (PERR_Subject arg);
ATbool PERR_hasSubjectWsAfterSubject (PERR_Subject arg);
ATbool PERR_hasSubjectWsAfterParenOpen (PERR_Subject arg);
ATbool PERR_hasSubjectDescription (PERR_Subject arg);
ATbool PERR_hasSubjectWsAfterDescription (PERR_Subject arg);
ATbool PERR_hasSubjectWsAfterLocalized (PERR_Subject arg);
ATbool PERR_hasSubjectWsAfterComma (PERR_Subject arg);
ATbool PERR_hasSubjectLocation (PERR_Subject arg);
ATbool PERR_hasSubjectWsAfterLocation (PERR_Subject arg);
PERR_OptLayout PERR_getSubjectWsAfterSubject (PERR_Subject arg);
PERR_OptLayout PERR_getSubjectWsAfterParenOpen (PERR_Subject arg);
PERR_StrCon PERR_getSubjectDescription (PERR_Subject arg);
PERR_OptLayout PERR_getSubjectWsAfterDescription (PERR_Subject arg);
PERR_OptLayout PERR_getSubjectWsAfterLocalized (PERR_Subject arg);
PERR_OptLayout PERR_getSubjectWsAfterComma (PERR_Subject arg);
PERR_Location PERR_getSubjectLocation (PERR_Subject arg);
PERR_OptLayout PERR_getSubjectWsAfterLocation (PERR_Subject arg);
PERR_Subject PERR_setSubjectWsAfterSubject (PERR_Subject arg,
					    PERR_OptLayout wsAfterSubject);
PERR_Subject PERR_setSubjectWsAfterParenOpen (PERR_Subject arg,
					      PERR_OptLayout
					      wsAfterParenOpen);
PERR_Subject PERR_setSubjectDescription (PERR_Subject arg,
					 PERR_StrCon description);
PERR_Subject PERR_setSubjectWsAfterDescription (PERR_Subject arg,
						PERR_OptLayout
						wsAfterDescription);
PERR_Subject PERR_setSubjectWsAfterLocalized (PERR_Subject arg,
					      PERR_OptLayout
					      wsAfterLocalized);
PERR_Subject PERR_setSubjectWsAfterComma (PERR_Subject arg,
					  PERR_OptLayout wsAfterComma);
PERR_Subject PERR_setSubjectLocation (PERR_Subject arg,
				      PERR_Location Location);
PERR_Subject PERR_setSubjectWsAfterLocation (PERR_Subject arg,
					     PERR_OptLayout wsAfterLocation);
ATbool PERR_isValidError (PERR_Error arg);
inline ATbool PERR_isErrorInfo (PERR_Error arg);
inline ATbool PERR_isErrorWarning (PERR_Error arg);
inline ATbool PERR_isErrorError (PERR_Error arg);
inline ATbool PERR_isErrorFatal (PERR_Error arg);
ATbool PERR_hasErrorWsAfterInfo (PERR_Error arg);
ATbool PERR_hasErrorWsAfterParenOpen (PERR_Error arg);
ATbool PERR_hasErrorDescription (PERR_Error arg);
ATbool PERR_hasErrorWsAfterDescription (PERR_Error arg);
ATbool PERR_hasErrorWsAfterComma (PERR_Error arg);
ATbool PERR_hasErrorWsAfterBracketOpen (PERR_Error arg);
ATbool PERR_hasErrorList (PERR_Error arg);
ATbool PERR_hasErrorWsAfterList (PERR_Error arg);
ATbool PERR_hasErrorWsAfterBracketClose (PERR_Error arg);
ATbool PERR_hasErrorWsAfterWarning (PERR_Error arg);
ATbool PERR_hasErrorWsAfterError (PERR_Error arg);
ATbool PERR_hasErrorWsAfterFatal (PERR_Error arg);
PERR_OptLayout PERR_getErrorWsAfterInfo (PERR_Error arg);
PERR_OptLayout PERR_getErrorWsAfterParenOpen (PERR_Error arg);
PERR_StrCon PERR_getErrorDescription (PERR_Error arg);
PERR_OptLayout PERR_getErrorWsAfterDescription (PERR_Error arg);
PERR_OptLayout PERR_getErrorWsAfterComma (PERR_Error arg);
PERR_OptLayout PERR_getErrorWsAfterBracketOpen (PERR_Error arg);
PERR_SubjectList PERR_getErrorList (PERR_Error arg);
PERR_OptLayout PERR_getErrorWsAfterList (PERR_Error arg);
PERR_OptLayout PERR_getErrorWsAfterBracketClose (PERR_Error arg);
PERR_OptLayout PERR_getErrorWsAfterWarning (PERR_Error arg);
PERR_OptLayout PERR_getErrorWsAfterError (PERR_Error arg);
PERR_OptLayout PERR_getErrorWsAfterFatal (PERR_Error arg);
PERR_Error PERR_setErrorWsAfterInfo (PERR_Error arg,
				     PERR_OptLayout wsAfterInfo);
PERR_Error PERR_setErrorWsAfterParenOpen (PERR_Error arg,
					  PERR_OptLayout wsAfterParenOpen);
PERR_Error PERR_setErrorDescription (PERR_Error arg, PERR_StrCon description);
PERR_Error PERR_setErrorWsAfterDescription (PERR_Error arg,
					    PERR_OptLayout
					    wsAfterDescription);
PERR_Error PERR_setErrorWsAfterComma (PERR_Error arg,
				      PERR_OptLayout wsAfterComma);
PERR_Error PERR_setErrorWsAfterBracketOpen (PERR_Error arg,
					    PERR_OptLayout
					    wsAfterBracketOpen);
PERR_Error PERR_setErrorList (PERR_Error arg, PERR_SubjectList list);
PERR_Error PERR_setErrorWsAfterList (PERR_Error arg,
				     PERR_OptLayout wsAfterList);
PERR_Error PERR_setErrorWsAfterBracketClose (PERR_Error arg,
					     PERR_OptLayout
					     wsAfterBracketClose);
PERR_Error PERR_setErrorWsAfterWarning (PERR_Error arg,
					PERR_OptLayout wsAfterWarning);
PERR_Error PERR_setErrorWsAfterError (PERR_Error arg,
				      PERR_OptLayout wsAfterError);
PERR_Error PERR_setErrorWsAfterFatal (PERR_Error arg,
				      PERR_OptLayout wsAfterFatal);
ATbool PERR_isValidSummary (PERR_Summary arg);
inline ATbool PERR_isSummarySummary (PERR_Summary arg);
ATbool PERR_hasSummaryWsAfterSummary (PERR_Summary arg);
ATbool PERR_hasSummaryWsAfterParenOpen (PERR_Summary arg);
ATbool PERR_hasSummaryProducer (PERR_Summary arg);
ATbool PERR_hasSummaryWsAfterProducer (PERR_Summary arg);
ATbool PERR_hasSummaryWsAfterComma (PERR_Summary arg);
ATbool PERR_hasSummaryId (PERR_Summary arg);
ATbool PERR_hasSummaryWsAfterId (PERR_Summary arg);
ATbool PERR_hasSummaryWsAfterComma1 (PERR_Summary arg);
ATbool PERR_hasSummaryWsAfterBracketOpen (PERR_Summary arg);
ATbool PERR_hasSummaryList (PERR_Summary arg);
ATbool PERR_hasSummaryWsAfterList (PERR_Summary arg);
ATbool PERR_hasSummaryWsAfterBracketClose (PERR_Summary arg);
PERR_OptLayout PERR_getSummaryWsAfterSummary (PERR_Summary arg);
PERR_OptLayout PERR_getSummaryWsAfterParenOpen (PERR_Summary arg);
PERR_StrCon PERR_getSummaryProducer (PERR_Summary arg);
PERR_OptLayout PERR_getSummaryWsAfterProducer (PERR_Summary arg);
PERR_OptLayout PERR_getSummaryWsAfterComma (PERR_Summary arg);
PERR_StrCon PERR_getSummaryId (PERR_Summary arg);
PERR_OptLayout PERR_getSummaryWsAfterId (PERR_Summary arg);
PERR_OptLayout PERR_getSummaryWsAfterComma1 (PERR_Summary arg);
PERR_OptLayout PERR_getSummaryWsAfterBracketOpen (PERR_Summary arg);
PERR_ErrorList PERR_getSummaryList (PERR_Summary arg);
PERR_OptLayout PERR_getSummaryWsAfterList (PERR_Summary arg);
PERR_OptLayout PERR_getSummaryWsAfterBracketClose (PERR_Summary arg);
PERR_Summary PERR_setSummaryWsAfterSummary (PERR_Summary arg,
					    PERR_OptLayout wsAfterSummary);
PERR_Summary PERR_setSummaryWsAfterParenOpen (PERR_Summary arg,
					      PERR_OptLayout
					      wsAfterParenOpen);
PERR_Summary PERR_setSummaryProducer (PERR_Summary arg, PERR_StrCon producer);
PERR_Summary PERR_setSummaryWsAfterProducer (PERR_Summary arg,
					     PERR_OptLayout wsAfterProducer);
PERR_Summary PERR_setSummaryWsAfterComma (PERR_Summary arg,
					  PERR_OptLayout wsAfterComma);
PERR_Summary PERR_setSummaryId (PERR_Summary arg, PERR_StrCon id);
PERR_Summary PERR_setSummaryWsAfterId (PERR_Summary arg,
				       PERR_OptLayout wsAfterId);
PERR_Summary PERR_setSummaryWsAfterComma1 (PERR_Summary arg,
					   PERR_OptLayout wsAfterComma1);
PERR_Summary PERR_setSummaryWsAfterBracketOpen (PERR_Summary arg,
						PERR_OptLayout
						wsAfterBracketOpen);
PERR_Summary PERR_setSummaryList (PERR_Summary arg, PERR_ErrorList list);
PERR_Summary PERR_setSummaryWsAfterList (PERR_Summary arg,
					 PERR_OptLayout wsAfterList);
PERR_Summary PERR_setSummaryWsAfterBracketClose (PERR_Summary arg,
						 PERR_OptLayout
						 wsAfterBracketClose);
ATbool PERR_isValidSubjectList (PERR_SubjectList arg);
inline ATbool PERR_isSubjectListEmpty (PERR_SubjectList arg);
inline ATbool PERR_isSubjectListSingle (PERR_SubjectList arg);
inline ATbool PERR_isSubjectListMany (PERR_SubjectList arg);
ATbool PERR_hasSubjectListHead (PERR_SubjectList arg);
ATbool PERR_hasSubjectListWsAfterHead (PERR_SubjectList arg);
ATbool PERR_hasSubjectListWsAfterSep (PERR_SubjectList arg);
ATbool PERR_hasSubjectListTail (PERR_SubjectList arg);
PERR_SubjectList PERR_getSubjectListTail (PERR_SubjectList arg);
PERR_Subject PERR_getSubjectListHead (PERR_SubjectList arg);
PERR_OptLayout PERR_getSubjectListWsAfterHead (PERR_SubjectList arg);
PERR_OptLayout PERR_getSubjectListWsAfterSep (PERR_SubjectList arg);
PERR_SubjectList PERR_setSubjectListHead (PERR_SubjectList arg,
					  PERR_Subject head);
PERR_SubjectList PERR_setSubjectListWsAfterHead (PERR_SubjectList arg,
						 PERR_OptLayout wsAfterHead);
PERR_SubjectList PERR_setSubjectListWsAfterSep (PERR_SubjectList arg,
						PERR_OptLayout wsAfterSep);
PERR_SubjectList PERR_setSubjectListTail (PERR_SubjectList arg,
					  PERR_SubjectList tail);
ATbool PERR_isValidErrorList (PERR_ErrorList arg);
inline ATbool PERR_isErrorListEmpty (PERR_ErrorList arg);
inline ATbool PERR_isErrorListSingle (PERR_ErrorList arg);
inline ATbool PERR_isErrorListMany (PERR_ErrorList arg);
ATbool PERR_hasErrorListHead (PERR_ErrorList arg);
ATbool PERR_hasErrorListWsAfterHead (PERR_ErrorList arg);
ATbool PERR_hasErrorListWsAfterSep (PERR_ErrorList arg);
ATbool PERR_hasErrorListTail (PERR_ErrorList arg);
PERR_ErrorList PERR_getErrorListTail (PERR_ErrorList arg);
PERR_Error PERR_getErrorListHead (PERR_ErrorList arg);
PERR_OptLayout PERR_getErrorListWsAfterHead (PERR_ErrorList arg);
PERR_OptLayout PERR_getErrorListWsAfterSep (PERR_ErrorList arg);
PERR_ErrorList PERR_setErrorListHead (PERR_ErrorList arg, PERR_Error head);
PERR_ErrorList PERR_setErrorListWsAfterHead (PERR_ErrorList arg,
					     PERR_OptLayout wsAfterHead);
PERR_ErrorList PERR_setErrorListWsAfterSep (PERR_ErrorList arg,
					    PERR_OptLayout wsAfterSep);
PERR_ErrorList PERR_setErrorListTail (PERR_ErrorList arg,
				      PERR_ErrorList tail);
ATbool PERR_isValidLocation (PERR_Location arg);
inline ATbool PERR_isLocationFile (PERR_Location arg);
inline ATbool PERR_isLocationArea (PERR_Location arg);
inline ATbool PERR_isLocationAreaInFile (PERR_Location arg);
ATbool PERR_hasLocationWsAfterFile (PERR_Location arg);
ATbool PERR_hasLocationWsAfterParenOpen (PERR_Location arg);
ATbool PERR_hasLocationFilename (PERR_Location arg);
ATbool PERR_hasLocationWsAfterFilename (PERR_Location arg);
ATbool PERR_hasLocationWsAfterA (PERR_Location arg);
ATbool PERR_hasLocationArea (PERR_Location arg);
ATbool PERR_hasLocationWsAfterArea (PERR_Location arg);
ATbool PERR_hasLocationWsAfterAreaInFile (PERR_Location arg);
ATbool PERR_hasLocationWsAfterComma (PERR_Location arg);
PERR_OptLayout PERR_getLocationWsAfterFile (PERR_Location arg);
PERR_OptLayout PERR_getLocationWsAfterParenOpen (PERR_Location arg);
PERR_StrCon PERR_getLocationFilename (PERR_Location arg);
PERR_OptLayout PERR_getLocationWsAfterFilename (PERR_Location arg);
PERR_OptLayout PERR_getLocationWsAfterA (PERR_Location arg);
PERR_Area PERR_getLocationArea (PERR_Location arg);
PERR_OptLayout PERR_getLocationWsAfterArea (PERR_Location arg);
PERR_OptLayout PERR_getLocationWsAfterAreaInFile (PERR_Location arg);
PERR_OptLayout PERR_getLocationWsAfterComma (PERR_Location arg);
PERR_Location PERR_setLocationWsAfterFile (PERR_Location arg,
					   PERR_OptLayout wsAfterFile);
PERR_Location PERR_setLocationWsAfterParenOpen (PERR_Location arg,
						PERR_OptLayout
						wsAfterParenOpen);
PERR_Location PERR_setLocationFilename (PERR_Location arg,
					PERR_StrCon filename);
PERR_Location PERR_setLocationWsAfterFilename (PERR_Location arg,
					       PERR_OptLayout
					       wsAfterFilename);
PERR_Location PERR_setLocationWsAfterA (PERR_Location arg,
					PERR_OptLayout wsAfterA);
PERR_Location PERR_setLocationArea (PERR_Location arg, PERR_Area Area);
PERR_Location PERR_setLocationWsAfterArea (PERR_Location arg,
					   PERR_OptLayout wsAfterArea);
PERR_Location PERR_setLocationWsAfterAreaInFile (PERR_Location arg,
						 PERR_OptLayout
						 wsAfterAreaInFile);
PERR_Location PERR_setLocationWsAfterComma (PERR_Location arg,
					    PERR_OptLayout wsAfterComma);
ATbool PERR_isValidArea (PERR_Area arg);
inline ATbool PERR_isAreaArea (PERR_Area arg);
ATbool PERR_hasAreaWsAfterArea (PERR_Area arg);
ATbool PERR_hasAreaWsAfterParenOpen (PERR_Area arg);
ATbool PERR_hasAreaBeginLine (PERR_Area arg);
ATbool PERR_hasAreaWsAfterBeginLine (PERR_Area arg);
ATbool PERR_hasAreaWsAfterComma (PERR_Area arg);
ATbool PERR_hasAreaBeginColumn (PERR_Area arg);
ATbool PERR_hasAreaWsAfterBeginColumn (PERR_Area arg);
ATbool PERR_hasAreaWsAfterComma1 (PERR_Area arg);
ATbool PERR_hasAreaEndLine (PERR_Area arg);
ATbool PERR_hasAreaWsAfterEndLine (PERR_Area arg);
ATbool PERR_hasAreaWsAfterComma2 (PERR_Area arg);
ATbool PERR_hasAreaEndColumn (PERR_Area arg);
ATbool PERR_hasAreaWsAfterEndColumn (PERR_Area arg);
ATbool PERR_hasAreaWsAfterComma3 (PERR_Area arg);
ATbool PERR_hasAreaOffset (PERR_Area arg);
ATbool PERR_hasAreaWsAfterOffset (PERR_Area arg);
ATbool PERR_hasAreaWsAfterComma4 (PERR_Area arg);
ATbool PERR_hasAreaLength (PERR_Area arg);
ATbool PERR_hasAreaWsAfterLength (PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterArea (PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterParenOpen (PERR_Area arg);
PERR_NatCon PERR_getAreaBeginLine (PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterBeginLine (PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterComma (PERR_Area arg);
PERR_NatCon PERR_getAreaBeginColumn (PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterBeginColumn (PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterComma1 (PERR_Area arg);
PERR_NatCon PERR_getAreaEndLine (PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterEndLine (PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterComma2 (PERR_Area arg);
PERR_NatCon PERR_getAreaEndColumn (PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterEndColumn (PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterComma3 (PERR_Area arg);
PERR_NatCon PERR_getAreaOffset (PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterOffset (PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterComma4 (PERR_Area arg);
PERR_NatCon PERR_getAreaLength (PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterLength (PERR_Area arg);
PERR_Area PERR_setAreaWsAfterArea (PERR_Area arg, PERR_OptLayout wsAfterArea);
PERR_Area PERR_setAreaWsAfterParenOpen (PERR_Area arg,
					PERR_OptLayout wsAfterParenOpen);
PERR_Area PERR_setAreaBeginLine (PERR_Area arg, PERR_NatCon beginLine);
PERR_Area PERR_setAreaWsAfterBeginLine (PERR_Area arg,
					PERR_OptLayout wsAfterBeginLine);
PERR_Area PERR_setAreaWsAfterComma (PERR_Area arg,
				    PERR_OptLayout wsAfterComma);
PERR_Area PERR_setAreaBeginColumn (PERR_Area arg, PERR_NatCon beginColumn);
PERR_Area PERR_setAreaWsAfterBeginColumn (PERR_Area arg,
					  PERR_OptLayout wsAfterBeginColumn);
PERR_Area PERR_setAreaWsAfterComma1 (PERR_Area arg,
				     PERR_OptLayout wsAfterComma1);
PERR_Area PERR_setAreaEndLine (PERR_Area arg, PERR_NatCon endLine);
PERR_Area PERR_setAreaWsAfterEndLine (PERR_Area arg,
				      PERR_OptLayout wsAfterEndLine);
PERR_Area PERR_setAreaWsAfterComma2 (PERR_Area arg,
				     PERR_OptLayout wsAfterComma2);
PERR_Area PERR_setAreaEndColumn (PERR_Area arg, PERR_NatCon endColumn);
PERR_Area PERR_setAreaWsAfterEndColumn (PERR_Area arg,
					PERR_OptLayout wsAfterEndColumn);
PERR_Area PERR_setAreaWsAfterComma3 (PERR_Area arg,
				     PERR_OptLayout wsAfterComma3);
PERR_Area PERR_setAreaOffset (PERR_Area arg, PERR_NatCon offset);
PERR_Area PERR_setAreaWsAfterOffset (PERR_Area arg,
				     PERR_OptLayout wsAfterOffset);
PERR_Area PERR_setAreaWsAfterComma4 (PERR_Area arg,
				     PERR_OptLayout wsAfterComma4);
PERR_Area PERR_setAreaLength (PERR_Area arg, PERR_NatCon length);
PERR_Area PERR_setAreaWsAfterLength (PERR_Area arg,
				     PERR_OptLayout wsAfterLength);
ATbool PERR_isValidSlice (PERR_Slice arg);
inline ATbool PERR_isSliceSlice (PERR_Slice arg);
ATbool PERR_hasSliceWsAfterSlice (PERR_Slice arg);
ATbool PERR_hasSliceWsAfterParenOpen (PERR_Slice arg);
ATbool PERR_hasSliceId (PERR_Slice arg);
ATbool PERR_hasSliceWsAfterId (PERR_Slice arg);
ATbool PERR_hasSliceWsAfterComma (PERR_Slice arg);
ATbool PERR_hasSliceWsAfterBracketOpen (PERR_Slice arg);
ATbool PERR_hasSliceAreas (PERR_Slice arg);
ATbool PERR_hasSliceWsAfterAreas (PERR_Slice arg);
ATbool PERR_hasSliceWsAfterBracketClose (PERR_Slice arg);
PERR_OptLayout PERR_getSliceWsAfterSlice (PERR_Slice arg);
PERR_OptLayout PERR_getSliceWsAfterParenOpen (PERR_Slice arg);
PERR_StrCon PERR_getSliceId (PERR_Slice arg);
PERR_OptLayout PERR_getSliceWsAfterId (PERR_Slice arg);
PERR_OptLayout PERR_getSliceWsAfterComma (PERR_Slice arg);
PERR_OptLayout PERR_getSliceWsAfterBracketOpen (PERR_Slice arg);
PERR_AreaAreas PERR_getSliceAreas (PERR_Slice arg);
PERR_OptLayout PERR_getSliceWsAfterAreas (PERR_Slice arg);
PERR_OptLayout PERR_getSliceWsAfterBracketClose (PERR_Slice arg);
PERR_Slice PERR_setSliceWsAfterSlice (PERR_Slice arg,
				      PERR_OptLayout wsAfterSlice);
PERR_Slice PERR_setSliceWsAfterParenOpen (PERR_Slice arg,
					  PERR_OptLayout wsAfterParenOpen);
PERR_Slice PERR_setSliceId (PERR_Slice arg, PERR_StrCon id);
PERR_Slice PERR_setSliceWsAfterId (PERR_Slice arg, PERR_OptLayout wsAfterId);
PERR_Slice PERR_setSliceWsAfterComma (PERR_Slice arg,
				      PERR_OptLayout wsAfterComma);
PERR_Slice PERR_setSliceWsAfterBracketOpen (PERR_Slice arg,
					    PERR_OptLayout
					    wsAfterBracketOpen);
PERR_Slice PERR_setSliceAreas (PERR_Slice arg, PERR_AreaAreas areas);
PERR_Slice PERR_setSliceWsAfterAreas (PERR_Slice arg,
				      PERR_OptLayout wsAfterAreas);
PERR_Slice PERR_setSliceWsAfterBracketClose (PERR_Slice arg,
					     PERR_OptLayout
					     wsAfterBracketClose);
ATbool PERR_isValidAreaAreas (PERR_AreaAreas arg);
inline ATbool PERR_isAreaAreasEmpty (PERR_AreaAreas arg);
inline ATbool PERR_isAreaAreasSingle (PERR_AreaAreas arg);
inline ATbool PERR_isAreaAreasMany (PERR_AreaAreas arg);
ATbool PERR_hasAreaAreasHead (PERR_AreaAreas arg);
ATbool PERR_hasAreaAreasWsAfterHead (PERR_AreaAreas arg);
ATbool PERR_hasAreaAreasWsAfterSep (PERR_AreaAreas arg);
ATbool PERR_hasAreaAreasTail (PERR_AreaAreas arg);
PERR_AreaAreas PERR_getAreaAreasTail (PERR_AreaAreas arg);
PERR_Area PERR_getAreaAreasHead (PERR_AreaAreas arg);
PERR_OptLayout PERR_getAreaAreasWsAfterHead (PERR_AreaAreas arg);
PERR_OptLayout PERR_getAreaAreasWsAfterSep (PERR_AreaAreas arg);
PERR_AreaAreas PERR_setAreaAreasHead (PERR_AreaAreas arg, PERR_Area head);
PERR_AreaAreas PERR_setAreaAreasWsAfterHead (PERR_AreaAreas arg,
					     PERR_OptLayout wsAfterHead);
PERR_AreaAreas PERR_setAreaAreasWsAfterSep (PERR_AreaAreas arg,
					    PERR_OptLayout wsAfterSep);
PERR_AreaAreas PERR_setAreaAreasTail (PERR_AreaAreas arg,
				      PERR_AreaAreas tail);
PERR_OptLayout PERR_visitOptLayout (PERR_OptLayout arg,
				    PERR_Layout (*acceptLayout)
				    (PERR_Layout));
PERR_Layout PERR_visitLayout (PERR_Layout arg,
			      PERR_LexLayoutList (*acceptList)
			      (PERR_LexLayoutList));
PERR_LexLayoutList PERR_visitLexLayoutList (PERR_LexLayoutList arg,
					    PERR_LexLayout (*acceptHead)
					    (PERR_LexLayout));
PERR_LexStrChar PERR_visitLexStrChar (PERR_LexStrChar arg,
				      char (*acceptA) (char),
				      char (*acceptB) (char),
				      char (*acceptC) (char),
				      char (*acceptCh) (char));
PERR_StrChar PERR_visitStrChar (PERR_StrChar arg,
				PERR_LexStrChar (*acceptStrChar)
				(PERR_LexStrChar));
PERR_LexStrCon PERR_visitLexStrCon (PERR_LexStrCon arg,
				    PERR_LexStrCharChars (*acceptChars)
				    (PERR_LexStrCharChars));
PERR_StrCon PERR_visitStrCon (PERR_StrCon arg,
			      PERR_LexStrCon (*acceptStrCon)
			      (PERR_LexStrCon));
PERR_LexStrCharChars PERR_visitLexStrCharChars (PERR_LexStrCharChars arg,
						PERR_LexStrChar (*acceptHead)
						(PERR_LexStrChar));
PERR_LexNatCon PERR_visitLexNatCon (PERR_LexNatCon arg,
				    char *(*acceptList) (char *));
PERR_NatCon PERR_visitNatCon (PERR_NatCon arg,
			      PERR_LexNatCon (*acceptNatCon)
			      (PERR_LexNatCon));
PERR_LexLayout PERR_visitLexLayout (PERR_LexLayout arg,
				    char (*acceptCh) (char));
PERR_Start PERR_visitStart (PERR_Start arg,
			    PERR_OptLayout (*acceptWsBefore) (PERR_OptLayout),
			    PERR_Summary (*acceptTopSummary) (PERR_Summary),
			    PERR_OptLayout (*acceptWsAfter) (PERR_OptLayout),
			    int (*acceptAmbCnt) (int),
			    PERR_Error (*acceptTopError) (PERR_Error));
PERR_Subject PERR_visitSubject (PERR_Subject arg,
				PERR_OptLayout (*acceptWsAfterSubject)
				(PERR_OptLayout),
				PERR_OptLayout (*acceptWsAfterParenOpen)
				(PERR_OptLayout),
				PERR_StrCon (*acceptDescription)
				(PERR_StrCon),
				PERR_OptLayout (*acceptWsAfterDescription)
				(PERR_OptLayout),
				PERR_OptLayout (*acceptWsAfterLocalized)
				(PERR_OptLayout),
				PERR_OptLayout (*acceptWsAfterComma)
				(PERR_OptLayout),
				PERR_Location (*acceptLocation)
				(PERR_Location),
				PERR_OptLayout (*acceptWsAfterLocation)
				(PERR_OptLayout));
PERR_Error PERR_visitError (PERR_Error arg,
			    PERR_OptLayout (*acceptWsAfterInfo)
			    (PERR_OptLayout),
			    PERR_OptLayout (*acceptWsAfterParenOpen)
			    (PERR_OptLayout),
			    PERR_StrCon (*acceptDescription) (PERR_StrCon),
			    PERR_OptLayout (*acceptWsAfterDescription)
			    (PERR_OptLayout),
			    PERR_OptLayout (*acceptWsAfterComma)
			    (PERR_OptLayout),
			    PERR_OptLayout (*acceptWsAfterBracketOpen)
			    (PERR_OptLayout),
			    PERR_SubjectList (*acceptList) (PERR_SubjectList),
			    PERR_OptLayout (*acceptWsAfterList)
			    (PERR_OptLayout),
			    PERR_OptLayout (*acceptWsAfterBracketClose)
			    (PERR_OptLayout),
			    PERR_OptLayout (*acceptWsAfterWarning)
			    (PERR_OptLayout),
			    PERR_OptLayout (*acceptWsAfterError)
			    (PERR_OptLayout),
			    PERR_OptLayout (*acceptWsAfterFatal)
			    (PERR_OptLayout));
PERR_Summary PERR_visitSummary (PERR_Summary arg,
				PERR_OptLayout (*acceptWsAfterSummary)
				(PERR_OptLayout),
				PERR_OptLayout (*acceptWsAfterParenOpen)
				(PERR_OptLayout),
				PERR_StrCon (*acceptProducer) (PERR_StrCon),
				PERR_OptLayout (*acceptWsAfterProducer)
				(PERR_OptLayout),
				PERR_OptLayout (*acceptWsAfterComma)
				(PERR_OptLayout),
				PERR_StrCon (*acceptId) (PERR_StrCon),
				PERR_OptLayout (*acceptWsAfterId)
				(PERR_OptLayout),
				PERR_OptLayout (*acceptWsAfterComma1)
				(PERR_OptLayout),
				PERR_OptLayout (*acceptWsAfterBracketOpen)
				(PERR_OptLayout),
				PERR_ErrorList (*acceptList) (PERR_ErrorList),
				PERR_OptLayout (*acceptWsAfterList)
				(PERR_OptLayout),
				PERR_OptLayout (*acceptWsAfterBracketClose)
				(PERR_OptLayout));
PERR_SubjectList PERR_visitSubjectList (PERR_SubjectList arg,
					PERR_Subject (*acceptHead)
					(PERR_Subject),
					PERR_OptLayout (*acceptWsAfterHead)
					(PERR_OptLayout),
					PERR_OptLayout (*acceptWsAfterSep)
					(PERR_OptLayout));
PERR_ErrorList PERR_visitErrorList (PERR_ErrorList arg,
				    PERR_Error (*acceptHead) (PERR_Error),
				    PERR_OptLayout (*acceptWsAfterHead)
				    (PERR_OptLayout),
				    PERR_OptLayout (*acceptWsAfterSep)
				    (PERR_OptLayout));
PERR_Location PERR_visitLocation (PERR_Location arg,
				  PERR_OptLayout (*acceptWsAfterFile)
				  (PERR_OptLayout),
				  PERR_OptLayout (*acceptWsAfterParenOpen)
				  (PERR_OptLayout),
				  PERR_StrCon (*acceptFilename) (PERR_StrCon),
				  PERR_OptLayout (*acceptWsAfterFilename)
				  (PERR_OptLayout),
				  PERR_OptLayout (*acceptWsAfterA)
				  (PERR_OptLayout),
				  PERR_Area (*acceptArea) (PERR_Area),
				  PERR_OptLayout (*acceptWsAfterArea)
				  (PERR_OptLayout),
				  PERR_OptLayout (*acceptWsAfterAreaInFile)
				  (PERR_OptLayout),
				  PERR_OptLayout (*acceptWsAfterComma)
				  (PERR_OptLayout));
PERR_Area PERR_visitArea (PERR_Area arg,
			  PERR_OptLayout (*acceptWsAfterArea)
			  (PERR_OptLayout),
			  PERR_OptLayout (*acceptWsAfterParenOpen)
			  (PERR_OptLayout),
			  PERR_NatCon (*acceptBeginLine) (PERR_NatCon),
			  PERR_OptLayout (*acceptWsAfterBeginLine)
			  (PERR_OptLayout),
			  PERR_OptLayout (*acceptWsAfterComma)
			  (PERR_OptLayout),
			  PERR_NatCon (*acceptBeginColumn) (PERR_NatCon),
			  PERR_OptLayout (*acceptWsAfterBeginColumn)
			  (PERR_OptLayout),
			  PERR_OptLayout (*acceptWsAfterComma1)
			  (PERR_OptLayout),
			  PERR_NatCon (*acceptEndLine) (PERR_NatCon),
			  PERR_OptLayout (*acceptWsAfterEndLine)
			  (PERR_OptLayout),
			  PERR_OptLayout (*acceptWsAfterComma2)
			  (PERR_OptLayout),
			  PERR_NatCon (*acceptEndColumn) (PERR_NatCon),
			  PERR_OptLayout (*acceptWsAfterEndColumn)
			  (PERR_OptLayout),
			  PERR_OptLayout (*acceptWsAfterComma3)
			  (PERR_OptLayout),
			  PERR_NatCon (*acceptOffset) (PERR_NatCon),
			  PERR_OptLayout (*acceptWsAfterOffset)
			  (PERR_OptLayout),
			  PERR_OptLayout (*acceptWsAfterComma4)
			  (PERR_OptLayout),
			  PERR_NatCon (*acceptLength) (PERR_NatCon),
			  PERR_OptLayout (*acceptWsAfterLength)
			  (PERR_OptLayout));
PERR_Slice PERR_visitSlice (PERR_Slice arg,
			    PERR_OptLayout (*acceptWsAfterSlice)
			    (PERR_OptLayout),
			    PERR_OptLayout (*acceptWsAfterParenOpen)
			    (PERR_OptLayout),
			    PERR_StrCon (*acceptId) (PERR_StrCon),
			    PERR_OptLayout (*acceptWsAfterId)
			    (PERR_OptLayout),
			    PERR_OptLayout (*acceptWsAfterComma)
			    (PERR_OptLayout),
			    PERR_OptLayout (*acceptWsAfterBracketOpen)
			    (PERR_OptLayout),
			    PERR_AreaAreas (*acceptAreas) (PERR_AreaAreas),
			    PERR_OptLayout (*acceptWsAfterAreas)
			    (PERR_OptLayout),
			    PERR_OptLayout (*acceptWsAfterBracketClose)
			    (PERR_OptLayout));
PERR_AreaAreas PERR_visitAreaAreas (PERR_AreaAreas arg,
				    PERR_Area (*acceptHead) (PERR_Area),
				    PERR_OptLayout (*acceptWsAfterHead)
				    (PERR_OptLayout),
				    PERR_OptLayout (*acceptWsAfterSep)
				    (PERR_OptLayout));

#endif /* _PARSEDERROR_H */
