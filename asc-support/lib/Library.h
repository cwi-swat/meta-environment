#ifndef _LIBRARY_H
#define _LIBRARY_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Library_dict.h"

typedef struct _CO_OptLayout *CO_OptLayout;
typedef struct _CO_Layout *CO_Layout;
typedef struct _CO_LexLayoutList *CO_LexLayoutList;
typedef struct _CO_LexLayout *CO_LexLayout;
typedef struct _CO_Start *CO_Start;
typedef struct _CO_LexStrChar *CO_LexStrChar;
typedef struct _CO_StrChar *CO_StrChar;
typedef struct _CO_LexStrCon *CO_LexStrCon;
typedef struct _CO_StrCon *CO_StrCon;
typedef struct _CO_LexStrCharChars *CO_LexStrCharChars;
typedef struct _CO_BoolCon *CO_BoolCon;
typedef struct _CO_LexNatCon *CO_LexNatCon;
typedef struct _CO_NatCon *CO_NatCon;
typedef struct _CO_LexByte *CO_LexByte;
typedef struct _CO_Byte *CO_Byte;
typedef struct _CO_LexBytes *CO_LexBytes;
typedef struct _CO_Bytes *CO_Bytes;
typedef struct _CO_LexByteList *CO_LexByteList;
typedef struct _CO_Subject *CO_Subject;
typedef struct _CO_Error *CO_Error;
typedef struct _CO_Summary *CO_Summary;
typedef struct _CO_SubjectList *CO_SubjectList;
typedef struct _CO_ErrorList *CO_ErrorList;
typedef struct _CO_Location *CO_Location;
typedef struct _CO_Area *CO_Area;
typedef struct _CO_Read *CO_Read;
typedef struct _CO_Write *CO_Write;
typedef struct _CO_ParsetreeX *CO_ParsetreeX;
typedef struct _CO_X *CO_X;
typedef struct _CO_Boolean *CO_Boolean;

#ifdef FAST_API
#define CO_initLibraryApi() (init_Library_dict())
#else
void _CO_initLibraryApi(void);
#define CO_initLibraryApi() (_CO_initLibraryApi())
#endif

#ifdef FAST_API
#define CO_protectOptLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectOptLayout(CO_OptLayout *arg);
#define CO_protectOptLayout(arg) (_CO_protectOptLayout(arg))
#endif
#ifdef FAST_API
#define CO_unprotectOptLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectOptLayout(CO_OptLayout *arg);
#define CO_unprotectOptLayout(arg) (_CO_unprotectOptLayout(arg))
#endif
#ifdef FAST_API
#define CO_protectLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectLayout(CO_Layout *arg);
#define CO_protectLayout(arg) (_CO_protectLayout(arg))
#endif
#ifdef FAST_API
#define CO_unprotectLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectLayout(CO_Layout *arg);
#define CO_unprotectLayout(arg) (_CO_unprotectLayout(arg))
#endif
#ifdef FAST_API
#define CO_protectLexLayoutList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectLexLayoutList(CO_LexLayoutList *arg);
#define CO_protectLexLayoutList(arg) (_CO_protectLexLayoutList(arg))
#endif
#ifdef FAST_API
#define CO_unprotectLexLayoutList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectLexLayoutList(CO_LexLayoutList *arg);
#define CO_unprotectLexLayoutList(arg) (_CO_unprotectLexLayoutList(arg))
#endif
#ifdef FAST_API
#define CO_protectLexLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectLexLayout(CO_LexLayout *arg);
#define CO_protectLexLayout(arg) (_CO_protectLexLayout(arg))
#endif
#ifdef FAST_API
#define CO_unprotectLexLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectLexLayout(CO_LexLayout *arg);
#define CO_unprotectLexLayout(arg) (_CO_unprotectLexLayout(arg))
#endif
#ifdef FAST_API
#define CO_protectStart(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectStart(CO_Start *arg);
#define CO_protectStart(arg) (_CO_protectStart(arg))
#endif
#ifdef FAST_API
#define CO_unprotectStart(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectStart(CO_Start *arg);
#define CO_unprotectStart(arg) (_CO_unprotectStart(arg))
#endif
#ifdef FAST_API
#define CO_protectLexStrChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectLexStrChar(CO_LexStrChar *arg);
#define CO_protectLexStrChar(arg) (_CO_protectLexStrChar(arg))
#endif
#ifdef FAST_API
#define CO_unprotectLexStrChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectLexStrChar(CO_LexStrChar *arg);
#define CO_unprotectLexStrChar(arg) (_CO_unprotectLexStrChar(arg))
#endif
#ifdef FAST_API
#define CO_protectStrChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectStrChar(CO_StrChar *arg);
#define CO_protectStrChar(arg) (_CO_protectStrChar(arg))
#endif
#ifdef FAST_API
#define CO_unprotectStrChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectStrChar(CO_StrChar *arg);
#define CO_unprotectStrChar(arg) (_CO_unprotectStrChar(arg))
#endif
#ifdef FAST_API
#define CO_protectLexStrCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectLexStrCon(CO_LexStrCon *arg);
#define CO_protectLexStrCon(arg) (_CO_protectLexStrCon(arg))
#endif
#ifdef FAST_API
#define CO_unprotectLexStrCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectLexStrCon(CO_LexStrCon *arg);
#define CO_unprotectLexStrCon(arg) (_CO_unprotectLexStrCon(arg))
#endif
#ifdef FAST_API
#define CO_protectStrCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectStrCon(CO_StrCon *arg);
#define CO_protectStrCon(arg) (_CO_protectStrCon(arg))
#endif
#ifdef FAST_API
#define CO_unprotectStrCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectStrCon(CO_StrCon *arg);
#define CO_unprotectStrCon(arg) (_CO_unprotectStrCon(arg))
#endif
#ifdef FAST_API
#define CO_protectLexStrCharChars(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectLexStrCharChars(CO_LexStrCharChars *arg);
#define CO_protectLexStrCharChars(arg) (_CO_protectLexStrCharChars(arg))
#endif
#ifdef FAST_API
#define CO_unprotectLexStrCharChars(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectLexStrCharChars(CO_LexStrCharChars *arg);
#define CO_unprotectLexStrCharChars(arg) (_CO_unprotectLexStrCharChars(arg))
#endif
#ifdef FAST_API
#define CO_protectBoolCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectBoolCon(CO_BoolCon *arg);
#define CO_protectBoolCon(arg) (_CO_protectBoolCon(arg))
#endif
#ifdef FAST_API
#define CO_unprotectBoolCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectBoolCon(CO_BoolCon *arg);
#define CO_unprotectBoolCon(arg) (_CO_unprotectBoolCon(arg))
#endif
#ifdef FAST_API
#define CO_protectLexNatCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectLexNatCon(CO_LexNatCon *arg);
#define CO_protectLexNatCon(arg) (_CO_protectLexNatCon(arg))
#endif
#ifdef FAST_API
#define CO_unprotectLexNatCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectLexNatCon(CO_LexNatCon *arg);
#define CO_unprotectLexNatCon(arg) (_CO_unprotectLexNatCon(arg))
#endif
#ifdef FAST_API
#define CO_protectNatCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectNatCon(CO_NatCon *arg);
#define CO_protectNatCon(arg) (_CO_protectNatCon(arg))
#endif
#ifdef FAST_API
#define CO_unprotectNatCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectNatCon(CO_NatCon *arg);
#define CO_unprotectNatCon(arg) (_CO_unprotectNatCon(arg))
#endif
#ifdef FAST_API
#define CO_protectLexByte(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectLexByte(CO_LexByte *arg);
#define CO_protectLexByte(arg) (_CO_protectLexByte(arg))
#endif
#ifdef FAST_API
#define CO_unprotectLexByte(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectLexByte(CO_LexByte *arg);
#define CO_unprotectLexByte(arg) (_CO_unprotectLexByte(arg))
#endif
#ifdef FAST_API
#define CO_protectByte(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectByte(CO_Byte *arg);
#define CO_protectByte(arg) (_CO_protectByte(arg))
#endif
#ifdef FAST_API
#define CO_unprotectByte(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectByte(CO_Byte *arg);
#define CO_unprotectByte(arg) (_CO_unprotectByte(arg))
#endif
#ifdef FAST_API
#define CO_protectLexBytes(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectLexBytes(CO_LexBytes *arg);
#define CO_protectLexBytes(arg) (_CO_protectLexBytes(arg))
#endif
#ifdef FAST_API
#define CO_unprotectLexBytes(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectLexBytes(CO_LexBytes *arg);
#define CO_unprotectLexBytes(arg) (_CO_unprotectLexBytes(arg))
#endif
#ifdef FAST_API
#define CO_protectBytes(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectBytes(CO_Bytes *arg);
#define CO_protectBytes(arg) (_CO_protectBytes(arg))
#endif
#ifdef FAST_API
#define CO_unprotectBytes(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectBytes(CO_Bytes *arg);
#define CO_unprotectBytes(arg) (_CO_unprotectBytes(arg))
#endif
#ifdef FAST_API
#define CO_protectLexByteList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectLexByteList(CO_LexByteList *arg);
#define CO_protectLexByteList(arg) (_CO_protectLexByteList(arg))
#endif
#ifdef FAST_API
#define CO_unprotectLexByteList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectLexByteList(CO_LexByteList *arg);
#define CO_unprotectLexByteList(arg) (_CO_unprotectLexByteList(arg))
#endif
#ifdef FAST_API
#define CO_protectSubject(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectSubject(CO_Subject *arg);
#define CO_protectSubject(arg) (_CO_protectSubject(arg))
#endif
#ifdef FAST_API
#define CO_unprotectSubject(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectSubject(CO_Subject *arg);
#define CO_unprotectSubject(arg) (_CO_unprotectSubject(arg))
#endif
#ifdef FAST_API
#define CO_protectError(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectError(CO_Error *arg);
#define CO_protectError(arg) (_CO_protectError(arg))
#endif
#ifdef FAST_API
#define CO_unprotectError(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectError(CO_Error *arg);
#define CO_unprotectError(arg) (_CO_unprotectError(arg))
#endif
#ifdef FAST_API
#define CO_protectSummary(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectSummary(CO_Summary *arg);
#define CO_protectSummary(arg) (_CO_protectSummary(arg))
#endif
#ifdef FAST_API
#define CO_unprotectSummary(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectSummary(CO_Summary *arg);
#define CO_unprotectSummary(arg) (_CO_unprotectSummary(arg))
#endif
#ifdef FAST_API
#define CO_protectSubjectList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectSubjectList(CO_SubjectList *arg);
#define CO_protectSubjectList(arg) (_CO_protectSubjectList(arg))
#endif
#ifdef FAST_API
#define CO_unprotectSubjectList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectSubjectList(CO_SubjectList *arg);
#define CO_unprotectSubjectList(arg) (_CO_unprotectSubjectList(arg))
#endif
#ifdef FAST_API
#define CO_protectErrorList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectErrorList(CO_ErrorList *arg);
#define CO_protectErrorList(arg) (_CO_protectErrorList(arg))
#endif
#ifdef FAST_API
#define CO_unprotectErrorList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectErrorList(CO_ErrorList *arg);
#define CO_unprotectErrorList(arg) (_CO_unprotectErrorList(arg))
#endif
#ifdef FAST_API
#define CO_protectLocation(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectLocation(CO_Location *arg);
#define CO_protectLocation(arg) (_CO_protectLocation(arg))
#endif
#ifdef FAST_API
#define CO_unprotectLocation(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectLocation(CO_Location *arg);
#define CO_unprotectLocation(arg) (_CO_unprotectLocation(arg))
#endif
#ifdef FAST_API
#define CO_protectArea(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectArea(CO_Area *arg);
#define CO_protectArea(arg) (_CO_protectArea(arg))
#endif
#ifdef FAST_API
#define CO_unprotectArea(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectArea(CO_Area *arg);
#define CO_unprotectArea(arg) (_CO_unprotectArea(arg))
#endif
#ifdef FAST_API
#define CO_protectRead(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectRead(CO_Read *arg);
#define CO_protectRead(arg) (_CO_protectRead(arg))
#endif
#ifdef FAST_API
#define CO_unprotectRead(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectRead(CO_Read *arg);
#define CO_unprotectRead(arg) (_CO_unprotectRead(arg))
#endif
#ifdef FAST_API
#define CO_protectWrite(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectWrite(CO_Write *arg);
#define CO_protectWrite(arg) (_CO_protectWrite(arg))
#endif
#ifdef FAST_API
#define CO_unprotectWrite(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectWrite(CO_Write *arg);
#define CO_unprotectWrite(arg) (_CO_unprotectWrite(arg))
#endif
#ifdef FAST_API
#define CO_protectParsetreeX(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectParsetreeX(CO_ParsetreeX *arg);
#define CO_protectParsetreeX(arg) (_CO_protectParsetreeX(arg))
#endif
#ifdef FAST_API
#define CO_unprotectParsetreeX(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectParsetreeX(CO_ParsetreeX *arg);
#define CO_unprotectParsetreeX(arg) (_CO_unprotectParsetreeX(arg))
#endif
#ifdef FAST_API
#define CO_protectX(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectX(CO_X *arg);
#define CO_protectX(arg) (_CO_protectX(arg))
#endif
#ifdef FAST_API
#define CO_unprotectX(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectX(CO_X *arg);
#define CO_unprotectX(arg) (_CO_unprotectX(arg))
#endif
#ifdef FAST_API
#define CO_protectBoolean(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _CO_protectBoolean(CO_Boolean *arg);
#define CO_protectBoolean(arg) (_CO_protectBoolean(arg))
#endif
#ifdef FAST_API
#define CO_unprotectBoolean(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _CO_unprotectBoolean(CO_Boolean *arg);
#define CO_unprotectBoolean(arg) (_CO_unprotectBoolean(arg))
#endif
#ifdef FAST_API
#define CO_OptLayoutFromTerm(t) ((((union {CO_OptLayout target; ATerm source; })(t)).target))
#else
CO_OptLayout _CO_OptLayoutFromTerm(ATerm t);
#define CO_OptLayoutFromTerm(t) (_CO_OptLayoutFromTerm(t))
#endif
#ifdef FAST_API
#define CO_OptLayoutToTerm(arg) ((((union {CO_OptLayout source; ATerm target; })(arg)).target))
#else
ATerm _CO_OptLayoutToTerm(CO_OptLayout arg);
#define CO_OptLayoutToTerm(arg) (_CO_OptLayoutToTerm(arg))
#endif
#ifdef FAST_API
#define CO_LayoutFromTerm(t) ((((union {CO_Layout target; ATerm source; })(t)).target))
#else
CO_Layout _CO_LayoutFromTerm(ATerm t);
#define CO_LayoutFromTerm(t) (_CO_LayoutFromTerm(t))
#endif
#ifdef FAST_API
#define CO_LayoutToTerm(arg) ((((union {CO_Layout source; ATerm target; })(arg)).target))
#else
ATerm _CO_LayoutToTerm(CO_Layout arg);
#define CO_LayoutToTerm(arg) (_CO_LayoutToTerm(arg))
#endif
#ifdef FAST_API
#define CO_LexLayoutListFromTerm(t) ((((union {CO_LexLayoutList target; ATerm source; })(t)).target))
#else
CO_LexLayoutList _CO_LexLayoutListFromTerm(ATerm t);
#define CO_LexLayoutListFromTerm(t) (_CO_LexLayoutListFromTerm(t))
#endif
#ifdef FAST_API
#define CO_LexLayoutListToTerm(arg) ((((union {CO_LexLayoutList source; ATerm target; })(arg)).target))
#else
ATerm _CO_LexLayoutListToTerm(CO_LexLayoutList arg);
#define CO_LexLayoutListToTerm(arg) (_CO_LexLayoutListToTerm(arg))
#endif
#ifdef FAST_API
#define CO_LexLayoutFromTerm(t) ((((union {CO_LexLayout target; ATerm source; })(t)).target))
#else
CO_LexLayout _CO_LexLayoutFromTerm(ATerm t);
#define CO_LexLayoutFromTerm(t) (_CO_LexLayoutFromTerm(t))
#endif
#ifdef FAST_API
#define CO_LexLayoutToTerm(arg) ((((union {CO_LexLayout source; ATerm target; })(arg)).target))
#else
ATerm _CO_LexLayoutToTerm(CO_LexLayout arg);
#define CO_LexLayoutToTerm(arg) (_CO_LexLayoutToTerm(arg))
#endif
#ifdef FAST_API
#define CO_StartFromTerm(t) ((((union {CO_Start target; ATerm source; })(t)).target))
#else
CO_Start _CO_StartFromTerm(ATerm t);
#define CO_StartFromTerm(t) (_CO_StartFromTerm(t))
#endif
#ifdef FAST_API
#define CO_StartToTerm(arg) ((((union {CO_Start source; ATerm target; })(arg)).target))
#else
ATerm _CO_StartToTerm(CO_Start arg);
#define CO_StartToTerm(arg) (_CO_StartToTerm(arg))
#endif
#ifdef FAST_API
#define CO_LexStrCharFromTerm(t) ((((union {CO_LexStrChar target; ATerm source; })(t)).target))
#else
CO_LexStrChar _CO_LexStrCharFromTerm(ATerm t);
#define CO_LexStrCharFromTerm(t) (_CO_LexStrCharFromTerm(t))
#endif
#ifdef FAST_API
#define CO_LexStrCharToTerm(arg) ((((union {CO_LexStrChar source; ATerm target; })(arg)).target))
#else
ATerm _CO_LexStrCharToTerm(CO_LexStrChar arg);
#define CO_LexStrCharToTerm(arg) (_CO_LexStrCharToTerm(arg))
#endif
#ifdef FAST_API
#define CO_StrCharFromTerm(t) ((((union {CO_StrChar target; ATerm source; })(t)).target))
#else
CO_StrChar _CO_StrCharFromTerm(ATerm t);
#define CO_StrCharFromTerm(t) (_CO_StrCharFromTerm(t))
#endif
#ifdef FAST_API
#define CO_StrCharToTerm(arg) ((((union {CO_StrChar source; ATerm target; })(arg)).target))
#else
ATerm _CO_StrCharToTerm(CO_StrChar arg);
#define CO_StrCharToTerm(arg) (_CO_StrCharToTerm(arg))
#endif
#ifdef FAST_API
#define CO_LexStrConFromTerm(t) ((((union {CO_LexStrCon target; ATerm source; })(t)).target))
#else
CO_LexStrCon _CO_LexStrConFromTerm(ATerm t);
#define CO_LexStrConFromTerm(t) (_CO_LexStrConFromTerm(t))
#endif
#ifdef FAST_API
#define CO_LexStrConToTerm(arg) ((((union {CO_LexStrCon source; ATerm target; })(arg)).target))
#else
ATerm _CO_LexStrConToTerm(CO_LexStrCon arg);
#define CO_LexStrConToTerm(arg) (_CO_LexStrConToTerm(arg))
#endif
#ifdef FAST_API
#define CO_StrConFromTerm(t) ((((union {CO_StrCon target; ATerm source; })(t)).target))
#else
CO_StrCon _CO_StrConFromTerm(ATerm t);
#define CO_StrConFromTerm(t) (_CO_StrConFromTerm(t))
#endif
#ifdef FAST_API
#define CO_StrConToTerm(arg) ((((union {CO_StrCon source; ATerm target; })(arg)).target))
#else
ATerm _CO_StrConToTerm(CO_StrCon arg);
#define CO_StrConToTerm(arg) (_CO_StrConToTerm(arg))
#endif
#ifdef FAST_API
#define CO_LexStrCharCharsFromTerm(t) ((((union {CO_LexStrCharChars target; ATerm source; })(t)).target))
#else
CO_LexStrCharChars _CO_LexStrCharCharsFromTerm(ATerm t);
#define CO_LexStrCharCharsFromTerm(t) (_CO_LexStrCharCharsFromTerm(t))
#endif
#ifdef FAST_API
#define CO_LexStrCharCharsToTerm(arg) ((((union {CO_LexStrCharChars source; ATerm target; })(arg)).target))
#else
ATerm _CO_LexStrCharCharsToTerm(CO_LexStrCharChars arg);
#define CO_LexStrCharCharsToTerm(arg) (_CO_LexStrCharCharsToTerm(arg))
#endif
#ifdef FAST_API
#define CO_BoolConFromTerm(t) ((((union {CO_BoolCon target; ATerm source; })(t)).target))
#else
CO_BoolCon _CO_BoolConFromTerm(ATerm t);
#define CO_BoolConFromTerm(t) (_CO_BoolConFromTerm(t))
#endif
#ifdef FAST_API
#define CO_BoolConToTerm(arg) ((((union {CO_BoolCon source; ATerm target; })(arg)).target))
#else
ATerm _CO_BoolConToTerm(CO_BoolCon arg);
#define CO_BoolConToTerm(arg) (_CO_BoolConToTerm(arg))
#endif
#ifdef FAST_API
#define CO_LexNatConFromTerm(t) ((((union {CO_LexNatCon target; ATerm source; })(t)).target))
#else
CO_LexNatCon _CO_LexNatConFromTerm(ATerm t);
#define CO_LexNatConFromTerm(t) (_CO_LexNatConFromTerm(t))
#endif
#ifdef FAST_API
#define CO_LexNatConToTerm(arg) ((((union {CO_LexNatCon source; ATerm target; })(arg)).target))
#else
ATerm _CO_LexNatConToTerm(CO_LexNatCon arg);
#define CO_LexNatConToTerm(arg) (_CO_LexNatConToTerm(arg))
#endif
#ifdef FAST_API
#define CO_NatConFromTerm(t) ((((union {CO_NatCon target; ATerm source; })(t)).target))
#else
CO_NatCon _CO_NatConFromTerm(ATerm t);
#define CO_NatConFromTerm(t) (_CO_NatConFromTerm(t))
#endif
#ifdef FAST_API
#define CO_NatConToTerm(arg) ((((union {CO_NatCon source; ATerm target; })(arg)).target))
#else
ATerm _CO_NatConToTerm(CO_NatCon arg);
#define CO_NatConToTerm(arg) (_CO_NatConToTerm(arg))
#endif
#ifdef FAST_API
#define CO_LexByteFromTerm(t) ((((union {CO_LexByte target; ATerm source; })(t)).target))
#else
CO_LexByte _CO_LexByteFromTerm(ATerm t);
#define CO_LexByteFromTerm(t) (_CO_LexByteFromTerm(t))
#endif
#ifdef FAST_API
#define CO_LexByteToTerm(arg) ((((union {CO_LexByte source; ATerm target; })(arg)).target))
#else
ATerm _CO_LexByteToTerm(CO_LexByte arg);
#define CO_LexByteToTerm(arg) (_CO_LexByteToTerm(arg))
#endif
#ifdef FAST_API
#define CO_ByteFromTerm(t) ((((union {CO_Byte target; ATerm source; })(t)).target))
#else
CO_Byte _CO_ByteFromTerm(ATerm t);
#define CO_ByteFromTerm(t) (_CO_ByteFromTerm(t))
#endif
#ifdef FAST_API
#define CO_ByteToTerm(arg) ((((union {CO_Byte source; ATerm target; })(arg)).target))
#else
ATerm _CO_ByteToTerm(CO_Byte arg);
#define CO_ByteToTerm(arg) (_CO_ByteToTerm(arg))
#endif
#ifdef FAST_API
#define CO_LexBytesFromTerm(t) ((((union {CO_LexBytes target; ATerm source; })(t)).target))
#else
CO_LexBytes _CO_LexBytesFromTerm(ATerm t);
#define CO_LexBytesFromTerm(t) (_CO_LexBytesFromTerm(t))
#endif
#ifdef FAST_API
#define CO_LexBytesToTerm(arg) ((((union {CO_LexBytes source; ATerm target; })(arg)).target))
#else
ATerm _CO_LexBytesToTerm(CO_LexBytes arg);
#define CO_LexBytesToTerm(arg) (_CO_LexBytesToTerm(arg))
#endif
#ifdef FAST_API
#define CO_BytesFromTerm(t) ((((union {CO_Bytes target; ATerm source; })(t)).target))
#else
CO_Bytes _CO_BytesFromTerm(ATerm t);
#define CO_BytesFromTerm(t) (_CO_BytesFromTerm(t))
#endif
#ifdef FAST_API
#define CO_BytesToTerm(arg) ((((union {CO_Bytes source; ATerm target; })(arg)).target))
#else
ATerm _CO_BytesToTerm(CO_Bytes arg);
#define CO_BytesToTerm(arg) (_CO_BytesToTerm(arg))
#endif
#ifdef FAST_API
#define CO_LexByteListFromTerm(t) ((((union {CO_LexByteList target; ATerm source; })(t)).target))
#else
CO_LexByteList _CO_LexByteListFromTerm(ATerm t);
#define CO_LexByteListFromTerm(t) (_CO_LexByteListFromTerm(t))
#endif
#ifdef FAST_API
#define CO_LexByteListToTerm(arg) ((((union {CO_LexByteList source; ATerm target; })(arg)).target))
#else
ATerm _CO_LexByteListToTerm(CO_LexByteList arg);
#define CO_LexByteListToTerm(arg) (_CO_LexByteListToTerm(arg))
#endif
#ifdef FAST_API
#define CO_SubjectFromTerm(t) ((((union {CO_Subject target; ATerm source; })(t)).target))
#else
CO_Subject _CO_SubjectFromTerm(ATerm t);
#define CO_SubjectFromTerm(t) (_CO_SubjectFromTerm(t))
#endif
#ifdef FAST_API
#define CO_SubjectToTerm(arg) ((((union {CO_Subject source; ATerm target; })(arg)).target))
#else
ATerm _CO_SubjectToTerm(CO_Subject arg);
#define CO_SubjectToTerm(arg) (_CO_SubjectToTerm(arg))
#endif
#ifdef FAST_API
#define CO_ErrorFromTerm(t) ((((union {CO_Error target; ATerm source; })(t)).target))
#else
CO_Error _CO_ErrorFromTerm(ATerm t);
#define CO_ErrorFromTerm(t) (_CO_ErrorFromTerm(t))
#endif
#ifdef FAST_API
#define CO_ErrorToTerm(arg) ((((union {CO_Error source; ATerm target; })(arg)).target))
#else
ATerm _CO_ErrorToTerm(CO_Error arg);
#define CO_ErrorToTerm(arg) (_CO_ErrorToTerm(arg))
#endif
#ifdef FAST_API
#define CO_SummaryFromTerm(t) ((((union {CO_Summary target; ATerm source; })(t)).target))
#else
CO_Summary _CO_SummaryFromTerm(ATerm t);
#define CO_SummaryFromTerm(t) (_CO_SummaryFromTerm(t))
#endif
#ifdef FAST_API
#define CO_SummaryToTerm(arg) ((((union {CO_Summary source; ATerm target; })(arg)).target))
#else
ATerm _CO_SummaryToTerm(CO_Summary arg);
#define CO_SummaryToTerm(arg) (_CO_SummaryToTerm(arg))
#endif
#ifdef FAST_API
#define CO_SubjectListFromTerm(t) ((((union {CO_SubjectList target; ATerm source; })(t)).target))
#else
CO_SubjectList _CO_SubjectListFromTerm(ATerm t);
#define CO_SubjectListFromTerm(t) (_CO_SubjectListFromTerm(t))
#endif
#ifdef FAST_API
#define CO_SubjectListToTerm(arg) ((((union {CO_SubjectList source; ATerm target; })(arg)).target))
#else
ATerm _CO_SubjectListToTerm(CO_SubjectList arg);
#define CO_SubjectListToTerm(arg) (_CO_SubjectListToTerm(arg))
#endif
#ifdef FAST_API
#define CO_ErrorListFromTerm(t) ((((union {CO_ErrorList target; ATerm source; })(t)).target))
#else
CO_ErrorList _CO_ErrorListFromTerm(ATerm t);
#define CO_ErrorListFromTerm(t) (_CO_ErrorListFromTerm(t))
#endif
#ifdef FAST_API
#define CO_ErrorListToTerm(arg) ((((union {CO_ErrorList source; ATerm target; })(arg)).target))
#else
ATerm _CO_ErrorListToTerm(CO_ErrorList arg);
#define CO_ErrorListToTerm(arg) (_CO_ErrorListToTerm(arg))
#endif
#ifdef FAST_API
#define CO_LocationFromTerm(t) ((((union {CO_Location target; ATerm source; })(t)).target))
#else
CO_Location _CO_LocationFromTerm(ATerm t);
#define CO_LocationFromTerm(t) (_CO_LocationFromTerm(t))
#endif
#ifdef FAST_API
#define CO_LocationToTerm(arg) ((((union {CO_Location source; ATerm target; })(arg)).target))
#else
ATerm _CO_LocationToTerm(CO_Location arg);
#define CO_LocationToTerm(arg) (_CO_LocationToTerm(arg))
#endif
#ifdef FAST_API
#define CO_AreaFromTerm(t) ((((union {CO_Area target; ATerm source; })(t)).target))
#else
CO_Area _CO_AreaFromTerm(ATerm t);
#define CO_AreaFromTerm(t) (_CO_AreaFromTerm(t))
#endif
#ifdef FAST_API
#define CO_AreaToTerm(arg) ((((union {CO_Area source; ATerm target; })(arg)).target))
#else
ATerm _CO_AreaToTerm(CO_Area arg);
#define CO_AreaToTerm(arg) (_CO_AreaToTerm(arg))
#endif
#ifdef FAST_API
#define CO_ReadFromTerm(t) ((((union {CO_Read target; ATerm source; })(t)).target))
#else
CO_Read _CO_ReadFromTerm(ATerm t);
#define CO_ReadFromTerm(t) (_CO_ReadFromTerm(t))
#endif
#ifdef FAST_API
#define CO_ReadToTerm(arg) ((((union {CO_Read source; ATerm target; })(arg)).target))
#else
ATerm _CO_ReadToTerm(CO_Read arg);
#define CO_ReadToTerm(arg) (_CO_ReadToTerm(arg))
#endif
#ifdef FAST_API
#define CO_WriteFromTerm(t) ((((union {CO_Write target; ATerm source; })(t)).target))
#else
CO_Write _CO_WriteFromTerm(ATerm t);
#define CO_WriteFromTerm(t) (_CO_WriteFromTerm(t))
#endif
#ifdef FAST_API
#define CO_WriteToTerm(arg) ((((union {CO_Write source; ATerm target; })(arg)).target))
#else
ATerm _CO_WriteToTerm(CO_Write arg);
#define CO_WriteToTerm(arg) (_CO_WriteToTerm(arg))
#endif
#ifdef FAST_API
#define CO_ParsetreeXFromTerm(t) ((((union {CO_ParsetreeX target; ATerm source; })(t)).target))
#else
CO_ParsetreeX _CO_ParsetreeXFromTerm(ATerm t);
#define CO_ParsetreeXFromTerm(t) (_CO_ParsetreeXFromTerm(t))
#endif
#ifdef FAST_API
#define CO_ParsetreeXToTerm(arg) ((((union {CO_ParsetreeX source; ATerm target; })(arg)).target))
#else
ATerm _CO_ParsetreeXToTerm(CO_ParsetreeX arg);
#define CO_ParsetreeXToTerm(arg) (_CO_ParsetreeXToTerm(arg))
#endif
#ifdef FAST_API
#define CO_XFromTerm(t) ((((union {CO_X target; ATerm source; })(t)).target))
#else
CO_X _CO_XFromTerm(ATerm t);
#define CO_XFromTerm(t) (_CO_XFromTerm(t))
#endif
#ifdef FAST_API
#define CO_XToTerm(arg) ((((union {CO_X source; ATerm target; })(arg)).target))
#else
ATerm _CO_XToTerm(CO_X arg);
#define CO_XToTerm(arg) (_CO_XToTerm(arg))
#endif
#ifdef FAST_API
#define CO_BooleanFromTerm(t) ((((union {CO_Boolean target; ATerm source; })(t)).target))
#else
CO_Boolean _CO_BooleanFromTerm(ATerm t);
#define CO_BooleanFromTerm(t) (_CO_BooleanFromTerm(t))
#endif
#ifdef FAST_API
#define CO_BooleanToTerm(arg) ((((union {CO_Boolean source; ATerm target; })(arg)).target))
#else
ATerm _CO_BooleanToTerm(CO_Boolean arg);
#define CO_BooleanToTerm(arg) (_CO_BooleanToTerm(arg))
#endif
#ifdef FAST_API
#define CO_getLexLayoutListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _CO_getLexLayoutListLength(CO_LexLayoutList arg);
#define CO_getLexLayoutListLength(arg) (_CO_getLexLayoutListLength(arg))
#endif
#ifdef FAST_API
#define CO_reverseLexLayoutList(arg) ((CO_LexLayoutList) ATreverse((ATermList) (arg)))
#else
CO_LexLayoutList _CO_reverseLexLayoutList(CO_LexLayoutList arg);
#define CO_reverseLexLayoutList(arg) (_CO_reverseLexLayoutList(arg))
#endif
#ifdef FAST_API
#define CO_appendLexLayoutList(arg, elem) ((CO_LexLayoutList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
CO_LexLayoutList _CO_appendLexLayoutList(CO_LexLayoutList arg, CO_LexLayout elem);
#define CO_appendLexLayoutList(arg, elem) (_CO_appendLexLayoutList(arg, elem))
#endif
#ifdef FAST_API
#define CO_concatLexLayoutList(arg0, arg1) ((CO_LexLayoutList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
CO_LexLayoutList _CO_concatLexLayoutList(CO_LexLayoutList arg0, CO_LexLayoutList arg1);
#define CO_concatLexLayoutList(arg0, arg1) (_CO_concatLexLayoutList(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_sliceLexLayoutList(arg, start, end) ((CO_LexLayoutList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
CO_LexLayoutList _CO_sliceLexLayoutList(CO_LexLayoutList arg, int start, int end);
#define CO_sliceLexLayoutList(arg, start, end) (_CO_sliceLexLayoutList(arg, start, end))
#endif
#ifdef FAST_API
#define CO_getLexLayoutListLexLayoutAt(arg, index) ((CO_LexLayout) (ATelementAt((ATermList) arg,index)))
#else
CO_LexLayout _CO_getLexLayoutListLexLayoutAt(CO_LexLayoutList arg, int index);
#define CO_getLexLayoutListLexLayoutAt(arg, index) (_CO_getLexLayoutListLexLayoutAt(arg, index))
#endif
#ifdef FAST_API
#define CO_replaceLexLayoutListLexLayoutAt(arg, elem, index) ((CO_LexLayoutList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
CO_LexLayoutList _CO_replaceLexLayoutListLexLayoutAt(CO_LexLayoutList arg, CO_LexLayout elem, int index);
#define CO_replaceLexLayoutListLexLayoutAt(arg, elem, index) (_CO_replaceLexLayoutListLexLayoutAt(arg, elem, index))
#endif
#ifdef FAST_API
#define CO_makeLexLayoutList2(elem1,  elem2) ((CO_LexLayoutList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
CO_LexLayoutList _CO_makeLexLayoutList2(CO_LexLayout elem1, CO_LexLayout elem2);
#define CO_makeLexLayoutList2(elem1,  elem2) (_CO_makeLexLayoutList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define CO_makeLexLayoutList3(elem1, elem2,  elem3) ((CO_LexLayoutList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
CO_LexLayoutList _CO_makeLexLayoutList3(CO_LexLayout elem1, CO_LexLayout elem2, CO_LexLayout elem3);
#define CO_makeLexLayoutList3(elem1, elem2,  elem3) (_CO_makeLexLayoutList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define CO_makeLexLayoutList4(elem1, elem2, elem3,  elem4) ((CO_LexLayoutList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
CO_LexLayoutList _CO_makeLexLayoutList4(CO_LexLayout elem1, CO_LexLayout elem2, CO_LexLayout elem3, CO_LexLayout elem4);
#define CO_makeLexLayoutList4(elem1, elem2, elem3,  elem4) (_CO_makeLexLayoutList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define CO_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5) ((CO_LexLayoutList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
CO_LexLayoutList _CO_makeLexLayoutList5(CO_LexLayout elem1, CO_LexLayout elem2, CO_LexLayout elem3, CO_LexLayout elem4, CO_LexLayout elem5);
#define CO_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5) (_CO_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define CO_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((CO_LexLayoutList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
CO_LexLayoutList _CO_makeLexLayoutList6(CO_LexLayout elem1, CO_LexLayout elem2, CO_LexLayout elem3, CO_LexLayout elem4, CO_LexLayout elem5, CO_LexLayout elem6);
#define CO_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_CO_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define CO_getLexStrCharCharsLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _CO_getLexStrCharCharsLength(CO_LexStrCharChars arg);
#define CO_getLexStrCharCharsLength(arg) (_CO_getLexStrCharCharsLength(arg))
#endif
#ifdef FAST_API
#define CO_reverseLexStrCharChars(arg) ((CO_LexStrCharChars) ATreverse((ATermList) (arg)))
#else
CO_LexStrCharChars _CO_reverseLexStrCharChars(CO_LexStrCharChars arg);
#define CO_reverseLexStrCharChars(arg) (_CO_reverseLexStrCharChars(arg))
#endif
#ifdef FAST_API
#define CO_appendLexStrCharChars(arg, elem) ((CO_LexStrCharChars) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
CO_LexStrCharChars _CO_appendLexStrCharChars(CO_LexStrCharChars arg, CO_LexStrChar elem);
#define CO_appendLexStrCharChars(arg, elem) (_CO_appendLexStrCharChars(arg, elem))
#endif
#ifdef FAST_API
#define CO_concatLexStrCharChars(arg0, arg1) ((CO_LexStrCharChars) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
CO_LexStrCharChars _CO_concatLexStrCharChars(CO_LexStrCharChars arg0, CO_LexStrCharChars arg1);
#define CO_concatLexStrCharChars(arg0, arg1) (_CO_concatLexStrCharChars(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_sliceLexStrCharChars(arg, start, end) ((CO_LexStrCharChars) ATgetSlice((ATermList) (arg), (start), (end)))
#else
CO_LexStrCharChars _CO_sliceLexStrCharChars(CO_LexStrCharChars arg, int start, int end);
#define CO_sliceLexStrCharChars(arg, start, end) (_CO_sliceLexStrCharChars(arg, start, end))
#endif
#ifdef FAST_API
#define CO_getLexStrCharCharsLexStrCharAt(arg, index) ((CO_LexStrChar) (ATelementAt((ATermList) arg,index)))
#else
CO_LexStrChar _CO_getLexStrCharCharsLexStrCharAt(CO_LexStrCharChars arg, int index);
#define CO_getLexStrCharCharsLexStrCharAt(arg, index) (_CO_getLexStrCharCharsLexStrCharAt(arg, index))
#endif
#ifdef FAST_API
#define CO_replaceLexStrCharCharsLexStrCharAt(arg, elem, index) ((CO_LexStrCharChars) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
CO_LexStrCharChars _CO_replaceLexStrCharCharsLexStrCharAt(CO_LexStrCharChars arg, CO_LexStrChar elem, int index);
#define CO_replaceLexStrCharCharsLexStrCharAt(arg, elem, index) (_CO_replaceLexStrCharCharsLexStrCharAt(arg, elem, index))
#endif
#ifdef FAST_API
#define CO_makeLexStrCharChars2(elem1,  elem2) ((CO_LexStrCharChars) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
CO_LexStrCharChars _CO_makeLexStrCharChars2(CO_LexStrChar elem1, CO_LexStrChar elem2);
#define CO_makeLexStrCharChars2(elem1,  elem2) (_CO_makeLexStrCharChars2(elem1,  elem2))
#endif
#ifdef FAST_API
#define CO_makeLexStrCharChars3(elem1, elem2,  elem3) ((CO_LexStrCharChars) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
CO_LexStrCharChars _CO_makeLexStrCharChars3(CO_LexStrChar elem1, CO_LexStrChar elem2, CO_LexStrChar elem3);
#define CO_makeLexStrCharChars3(elem1, elem2,  elem3) (_CO_makeLexStrCharChars3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define CO_makeLexStrCharChars4(elem1, elem2, elem3,  elem4) ((CO_LexStrCharChars) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
CO_LexStrCharChars _CO_makeLexStrCharChars4(CO_LexStrChar elem1, CO_LexStrChar elem2, CO_LexStrChar elem3, CO_LexStrChar elem4);
#define CO_makeLexStrCharChars4(elem1, elem2, elem3,  elem4) (_CO_makeLexStrCharChars4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define CO_makeLexStrCharChars5(elem1, elem2, elem3, elem4,  elem5) ((CO_LexStrCharChars) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
CO_LexStrCharChars _CO_makeLexStrCharChars5(CO_LexStrChar elem1, CO_LexStrChar elem2, CO_LexStrChar elem3, CO_LexStrChar elem4, CO_LexStrChar elem5);
#define CO_makeLexStrCharChars5(elem1, elem2, elem3, elem4,  elem5) (_CO_makeLexStrCharChars5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define CO_makeLexStrCharChars6(elem1, elem2, elem3, elem4, elem5,  elem6) ((CO_LexStrCharChars) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
CO_LexStrCharChars _CO_makeLexStrCharChars6(CO_LexStrChar elem1, CO_LexStrChar elem2, CO_LexStrChar elem3, CO_LexStrChar elem4, CO_LexStrChar elem5, CO_LexStrChar elem6);
#define CO_makeLexStrCharChars6(elem1, elem2, elem3, elem4, elem5,  elem6) (_CO_makeLexStrCharChars6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define CO_getLexByteListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _CO_getLexByteListLength(CO_LexByteList arg);
#define CO_getLexByteListLength(arg) (_CO_getLexByteListLength(arg))
#endif
#ifdef FAST_API
#define CO_reverseLexByteList(arg) ((CO_LexByteList) ATreverse((ATermList) (arg)))
#else
CO_LexByteList _CO_reverseLexByteList(CO_LexByteList arg);
#define CO_reverseLexByteList(arg) (_CO_reverseLexByteList(arg))
#endif
#ifdef FAST_API
#define CO_appendLexByteList(arg, elem) ((CO_LexByteList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
CO_LexByteList _CO_appendLexByteList(CO_LexByteList arg, CO_LexByte elem);
#define CO_appendLexByteList(arg, elem) (_CO_appendLexByteList(arg, elem))
#endif
#ifdef FAST_API
#define CO_concatLexByteList(arg0, arg1) ((CO_LexByteList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
CO_LexByteList _CO_concatLexByteList(CO_LexByteList arg0, CO_LexByteList arg1);
#define CO_concatLexByteList(arg0, arg1) (_CO_concatLexByteList(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_sliceLexByteList(arg, start, end) ((CO_LexByteList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
CO_LexByteList _CO_sliceLexByteList(CO_LexByteList arg, int start, int end);
#define CO_sliceLexByteList(arg, start, end) (_CO_sliceLexByteList(arg, start, end))
#endif
#ifdef FAST_API
#define CO_getLexByteListLexByteAt(arg, index) ((CO_LexByte) (ATelementAt((ATermList) arg,index)))
#else
CO_LexByte _CO_getLexByteListLexByteAt(CO_LexByteList arg, int index);
#define CO_getLexByteListLexByteAt(arg, index) (_CO_getLexByteListLexByteAt(arg, index))
#endif
#ifdef FAST_API
#define CO_replaceLexByteListLexByteAt(arg, elem, index) ((CO_LexByteList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
CO_LexByteList _CO_replaceLexByteListLexByteAt(CO_LexByteList arg, CO_LexByte elem, int index);
#define CO_replaceLexByteListLexByteAt(arg, elem, index) (_CO_replaceLexByteListLexByteAt(arg, elem, index))
#endif
#ifdef FAST_API
#define CO_makeLexByteList2(elem1,  elem2) ((CO_LexByteList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
CO_LexByteList _CO_makeLexByteList2(CO_LexByte elem1, CO_LexByte elem2);
#define CO_makeLexByteList2(elem1,  elem2) (_CO_makeLexByteList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define CO_makeLexByteList3(elem1, elem2,  elem3) ((CO_LexByteList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
CO_LexByteList _CO_makeLexByteList3(CO_LexByte elem1, CO_LexByte elem2, CO_LexByte elem3);
#define CO_makeLexByteList3(elem1, elem2,  elem3) (_CO_makeLexByteList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define CO_makeLexByteList4(elem1, elem2, elem3,  elem4) ((CO_LexByteList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
CO_LexByteList _CO_makeLexByteList4(CO_LexByte elem1, CO_LexByte elem2, CO_LexByte elem3, CO_LexByte elem4);
#define CO_makeLexByteList4(elem1, elem2, elem3,  elem4) (_CO_makeLexByteList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define CO_makeLexByteList5(elem1, elem2, elem3, elem4,  elem5) ((CO_LexByteList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
CO_LexByteList _CO_makeLexByteList5(CO_LexByte elem1, CO_LexByte elem2, CO_LexByte elem3, CO_LexByte elem4, CO_LexByte elem5);
#define CO_makeLexByteList5(elem1, elem2, elem3, elem4,  elem5) (_CO_makeLexByteList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define CO_makeLexByteList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((CO_LexByteList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
CO_LexByteList _CO_makeLexByteList6(CO_LexByte elem1, CO_LexByte elem2, CO_LexByte elem3, CO_LexByte elem4, CO_LexByte elem5, CO_LexByte elem6);
#define CO_makeLexByteList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_CO_makeLexByteList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define CO_getSubjectListLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _CO_getSubjectListLength(CO_SubjectList arg);
#define CO_getSubjectListLength(arg) (_CO_getSubjectListLength(arg))
#endif
CO_SubjectList CO_reverseSubjectList(CO_SubjectList arg);
CO_SubjectList CO_appendSubjectList(CO_SubjectList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject arg1);
CO_SubjectList CO_concatSubjectList(CO_SubjectList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_SubjectList arg1);
#ifdef FAST_API
#define CO_sliceSubjectList(arg, start, end) ((CO_SubjectList) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
CO_SubjectList _CO_sliceSubjectList(CO_SubjectList arg, int start, int end);
#define CO_sliceSubjectList(arg, start, end) (_CO_sliceSubjectList(arg, start, end))
#endif
#ifdef FAST_API
#define CO_getSubjectListSubjectAt(arg, index) ((CO_Subject) (ATelementAt((ATermList) arg,index * 4)))
#else
CO_Subject _CO_getSubjectListSubjectAt(CO_SubjectList arg, int index);
#define CO_getSubjectListSubjectAt(arg, index) (_CO_getSubjectListSubjectAt(arg, index))
#endif
#ifdef FAST_API
#define CO_replaceSubjectListSubjectAt(arg, elem, index) ((CO_SubjectList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
CO_SubjectList _CO_replaceSubjectListSubjectAt(CO_SubjectList arg, CO_Subject elem, int index);
#define CO_replaceSubjectListSubjectAt(arg, elem, index) (_CO_replaceSubjectListSubjectAt(arg, elem, index))
#endif
CO_SubjectList CO_makeSubjectList2(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2);
CO_SubjectList CO_makeSubjectList3(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3);
CO_SubjectList CO_makeSubjectList4(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3, CO_Subject elem4);
CO_SubjectList CO_makeSubjectList5(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3, CO_Subject elem4, CO_Subject elem5);
CO_SubjectList CO_makeSubjectList6(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3, CO_Subject elem4, CO_Subject elem5, CO_Subject elem6);
#ifdef FAST_API
#define CO_getErrorListLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _CO_getErrorListLength(CO_ErrorList arg);
#define CO_getErrorListLength(arg) (_CO_getErrorListLength(arg))
#endif
CO_ErrorList CO_reverseErrorList(CO_ErrorList arg);
CO_ErrorList CO_appendErrorList(CO_ErrorList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error arg1);
CO_ErrorList CO_concatErrorList(CO_ErrorList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_ErrorList arg1);
#ifdef FAST_API
#define CO_sliceErrorList(arg, start, end) ((CO_ErrorList) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
CO_ErrorList _CO_sliceErrorList(CO_ErrorList arg, int start, int end);
#define CO_sliceErrorList(arg, start, end) (_CO_sliceErrorList(arg, start, end))
#endif
#ifdef FAST_API
#define CO_getErrorListErrorAt(arg, index) ((CO_Error) (ATelementAt((ATermList) arg,index * 4)))
#else
CO_Error _CO_getErrorListErrorAt(CO_ErrorList arg, int index);
#define CO_getErrorListErrorAt(arg, index) (_CO_getErrorListErrorAt(arg, index))
#endif
#ifdef FAST_API
#define CO_replaceErrorListErrorAt(arg, elem, index) ((CO_ErrorList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
CO_ErrorList _CO_replaceErrorListErrorAt(CO_ErrorList arg, CO_Error elem, int index);
#define CO_replaceErrorListErrorAt(arg, elem, index) (_CO_replaceErrorListErrorAt(arg, elem, index))
#endif
CO_ErrorList CO_makeErrorList2(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2);
CO_ErrorList CO_makeErrorList3(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3);
CO_ErrorList CO_makeErrorList4(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3, CO_Error elem4);
CO_ErrorList CO_makeErrorList5(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3, CO_Error elem4, CO_Error elem5);
CO_ErrorList CO_makeErrorList6(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3, CO_Error elem4, CO_Error elem5, CO_Error elem6);
CO_OptLayout CO_makeOptLayoutAbsent(void);
CO_OptLayout CO_makeOptLayoutPresent(CO_Layout layout);
CO_Layout CO_makeLayoutLexToCf(CO_LexLayoutList list);
CO_LexLayoutList CO_makeLexLayoutListEmpty(void);
CO_LexLayoutList CO_makeLexLayoutListSingle(CO_LexLayout head);
CO_LexLayoutList CO_makeLexLayoutListMany(CO_LexLayout head, CO_LexLayoutList tail);
CO_LexLayout CO_makeLexLayoutWhitespace(char ch);
CO_Start CO_makeStartStrCon(CO_OptLayout wsBefore, CO_StrCon topStrCon, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartBoolCon(CO_OptLayout wsBefore, CO_BoolCon topBoolCon, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartSummary(CO_OptLayout wsBefore, CO_Summary topSummary, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartError(CO_OptLayout wsBefore, CO_Error topError, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartBoolean(CO_OptLayout wsBefore, CO_Boolean topBoolean, CO_OptLayout wsAfter, int ambCnt);
CO_LexStrChar CO_makeLexStrCharNewline(void);
CO_LexStrChar CO_makeLexStrCharTab(void);
CO_LexStrChar CO_makeLexStrCharQuote(void);
CO_LexStrChar CO_makeLexStrCharBackslash(void);
CO_LexStrChar CO_makeLexStrCharDecimal(char a, char b, char c);
CO_LexStrChar CO_makeLexStrCharNormal(char ch);
CO_StrChar CO_makeStrCharLexToCf(CO_LexStrChar StrChar);
CO_LexStrCon CO_makeLexStrConDefault(CO_LexStrCharChars chars);
CO_StrCon CO_makeStrConLexToCf(CO_LexStrCon StrCon);
CO_LexStrCharChars CO_makeLexStrCharCharsEmpty(void);
CO_LexStrCharChars CO_makeLexStrCharCharsSingle(CO_LexStrChar head);
CO_LexStrCharChars CO_makeLexStrCharCharsMany(CO_LexStrChar head, CO_LexStrCharChars tail);
CO_BoolCon CO_makeBoolConTrue(void);
CO_BoolCon CO_makeBoolConFalse(void);
CO_LexNatCon CO_makeLexNatConDigits(const char* list);
CO_NatCon CO_makeNatConLexToCf(CO_LexNatCon NatCon);
CO_LexByte CO_makeLexByteByte(char ch);
CO_Byte CO_makeByteLexToCf(CO_LexByte Byte);
CO_LexBytes CO_makeLexBytesBytes(CO_LexByteList list);
CO_Bytes CO_makeBytesLexToCf(CO_LexBytes Bytes);
CO_LexByteList CO_makeLexByteListEmpty(void);
CO_LexByteList CO_makeLexByteListSingle(CO_LexByte head);
CO_LexByteList CO_makeLexByteListMany(CO_LexByte head, CO_LexByteList tail);
CO_Subject CO_makeSubjectSubject(CO_OptLayout wsAfterSubject, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription);
CO_Subject CO_makeSubjectLocalized(CO_OptLayout wsAfterLocalized, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_Location Location, CO_OptLayout wsAfterLocation);
CO_Error CO_makeErrorInfo(CO_OptLayout wsAfterInfo, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose);
CO_Error CO_makeErrorWarning(CO_OptLayout wsAfterWarning, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose);
CO_Error CO_makeErrorError(CO_OptLayout wsAfterError, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose);
CO_Error CO_makeErrorFatal(CO_OptLayout wsAfterFatal, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose);
CO_Summary CO_makeSummarySummary(CO_OptLayout wsAfterSummary, CO_OptLayout wsAfterParenOpen, CO_StrCon producer, CO_OptLayout wsAfterProducer, CO_OptLayout wsAfterComma, CO_StrCon id, CO_OptLayout wsAfterId, CO_OptLayout wsAfterComma1, CO_OptLayout wsAfterBracketOpen, CO_ErrorList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose);
CO_SubjectList CO_makeSubjectListEmpty(void);
CO_SubjectList CO_makeSubjectListSingle(CO_Subject head);
CO_SubjectList CO_makeSubjectListMany(CO_Subject head, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_SubjectList tail);
CO_ErrorList CO_makeErrorListEmpty(void);
CO_ErrorList CO_makeErrorListSingle(CO_Error head);
CO_ErrorList CO_makeErrorListMany(CO_Error head, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_ErrorList tail);
CO_Location CO_makeLocationFile(CO_OptLayout wsAfterFile, CO_OptLayout wsAfterParenOpen, CO_StrCon filename, CO_OptLayout wsAfterFilename);
CO_Location CO_makeLocationArea(CO_OptLayout wsAfterA, CO_OptLayout wsAfterParenOpen, CO_Area Area, CO_OptLayout wsAfterArea);
CO_Location CO_makeLocationAreaInFile(CO_OptLayout wsAfterAreaInFile, CO_OptLayout wsAfterParenOpen, CO_StrCon filename, CO_OptLayout wsAfterFilename, CO_OptLayout wsAfterComma, CO_Area Area, CO_OptLayout wsAfterArea);
CO_Area CO_makeAreaArea(CO_OptLayout wsAfterArea, CO_OptLayout wsAfterParenOpen, CO_NatCon beginLine, CO_OptLayout wsAfterBeginLine, CO_OptLayout wsAfterComma, CO_NatCon beginColumn, CO_OptLayout wsAfterBeginColumn, CO_OptLayout wsAfterComma1, CO_NatCon endLine, CO_OptLayout wsAfterEndLine, CO_OptLayout wsAfterComma2, CO_NatCon endColumn, CO_OptLayout wsAfterEndColumn, CO_OptLayout wsAfterComma3, CO_NatCon offset, CO_OptLayout wsAfterOffset, CO_OptLayout wsAfterComma4, CO_NatCon length, CO_OptLayout wsAfterLength);
CO_Read CO_makeReadSuccess(CO_OptLayout wsAfterRead, CO_OptLayout wsAfterParenOpen, CO_Bytes value, CO_OptLayout wsAfterValue);
CO_Read CO_makeReadFailure(CO_OptLayout wsAfterReadError, CO_OptLayout wsAfterParenOpen, CO_Summary Summary, CO_OptLayout wsAfterSummary);
CO_Write CO_makeWriteSuccess(void);
CO_Write CO_makeWriteFailure(CO_OptLayout wsAfterWriteError, CO_OptLayout wsAfterParenOpen, CO_Summary Summary, CO_OptLayout wsAfterSummary);
CO_ParsetreeX CO_makeParsetreeXSuccess(ATerm typeOfTree, ATerm typeOfX, CO_OptLayout wsAfterParseTree, CO_OptLayout wsAfterParenOpen, CO_Bytes leftLayout, CO_OptLayout wsAfterLeftLayout, CO_OptLayout wsAfterComma, CO_X tree, CO_OptLayout wsAfterTree, CO_OptLayout wsAfterComma1, CO_Bytes rightLayout, CO_OptLayout wsAfterRightLayout, CO_OptLayout wsAfterComma2, CO_NatCon ambCnt, CO_OptLayout wsAfterAmbCnt);
CO_ParsetreeX CO_makeParsetreeXFailure(ATerm typeOfX, CO_OptLayout wsAfterParseError, CO_OptLayout wsAfterParenOpen, CO_Summary Summary, CO_OptLayout wsAfterSummary);
CO_X CO_makeXCast(ATerm X);
CO_Boolean CO_makeBooleanConstant(CO_BoolCon BoolCon);
CO_Boolean CO_makeBooleanOr(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterBar, CO_Boolean rhs);
CO_Boolean CO_makeBooleanAnd(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterAmp, CO_Boolean rhs);
CO_Boolean CO_makeBooleanNot(CO_OptLayout wsAfterNot, CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean);
CO_Boolean CO_makeBooleanBracket(CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean);
#ifdef FAST_API
#define CO_isEqualOptLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualOptLayout(CO_OptLayout arg0, CO_OptLayout arg1);
#define CO_isEqualOptLayout(arg0, arg1) (_CO_isEqualOptLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualLayout(CO_Layout arg0, CO_Layout arg1);
#define CO_isEqualLayout(arg0, arg1) (_CO_isEqualLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualLexLayoutList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualLexLayoutList(CO_LexLayoutList arg0, CO_LexLayoutList arg1);
#define CO_isEqualLexLayoutList(arg0, arg1) (_CO_isEqualLexLayoutList(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualLexLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualLexLayout(CO_LexLayout arg0, CO_LexLayout arg1);
#define CO_isEqualLexLayout(arg0, arg1) (_CO_isEqualLexLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualStart(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualStart(CO_Start arg0, CO_Start arg1);
#define CO_isEqualStart(arg0, arg1) (_CO_isEqualStart(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualLexStrChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualLexStrChar(CO_LexStrChar arg0, CO_LexStrChar arg1);
#define CO_isEqualLexStrChar(arg0, arg1) (_CO_isEqualLexStrChar(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualStrChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualStrChar(CO_StrChar arg0, CO_StrChar arg1);
#define CO_isEqualStrChar(arg0, arg1) (_CO_isEqualStrChar(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualLexStrCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualLexStrCon(CO_LexStrCon arg0, CO_LexStrCon arg1);
#define CO_isEqualLexStrCon(arg0, arg1) (_CO_isEqualLexStrCon(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualStrCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualStrCon(CO_StrCon arg0, CO_StrCon arg1);
#define CO_isEqualStrCon(arg0, arg1) (_CO_isEqualStrCon(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualLexStrCharChars(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualLexStrCharChars(CO_LexStrCharChars arg0, CO_LexStrCharChars arg1);
#define CO_isEqualLexStrCharChars(arg0, arg1) (_CO_isEqualLexStrCharChars(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualBoolCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualBoolCon(CO_BoolCon arg0, CO_BoolCon arg1);
#define CO_isEqualBoolCon(arg0, arg1) (_CO_isEqualBoolCon(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualLexNatCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualLexNatCon(CO_LexNatCon arg0, CO_LexNatCon arg1);
#define CO_isEqualLexNatCon(arg0, arg1) (_CO_isEqualLexNatCon(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualNatCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualNatCon(CO_NatCon arg0, CO_NatCon arg1);
#define CO_isEqualNatCon(arg0, arg1) (_CO_isEqualNatCon(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualLexByte(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualLexByte(CO_LexByte arg0, CO_LexByte arg1);
#define CO_isEqualLexByte(arg0, arg1) (_CO_isEqualLexByte(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualByte(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualByte(CO_Byte arg0, CO_Byte arg1);
#define CO_isEqualByte(arg0, arg1) (_CO_isEqualByte(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualLexBytes(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualLexBytes(CO_LexBytes arg0, CO_LexBytes arg1);
#define CO_isEqualLexBytes(arg0, arg1) (_CO_isEqualLexBytes(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualBytes(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualBytes(CO_Bytes arg0, CO_Bytes arg1);
#define CO_isEqualBytes(arg0, arg1) (_CO_isEqualBytes(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualLexByteList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualLexByteList(CO_LexByteList arg0, CO_LexByteList arg1);
#define CO_isEqualLexByteList(arg0, arg1) (_CO_isEqualLexByteList(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualSubject(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualSubject(CO_Subject arg0, CO_Subject arg1);
#define CO_isEqualSubject(arg0, arg1) (_CO_isEqualSubject(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualError(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualError(CO_Error arg0, CO_Error arg1);
#define CO_isEqualError(arg0, arg1) (_CO_isEqualError(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualSummary(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualSummary(CO_Summary arg0, CO_Summary arg1);
#define CO_isEqualSummary(arg0, arg1) (_CO_isEqualSummary(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualSubjectList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualSubjectList(CO_SubjectList arg0, CO_SubjectList arg1);
#define CO_isEqualSubjectList(arg0, arg1) (_CO_isEqualSubjectList(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualErrorList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualErrorList(CO_ErrorList arg0, CO_ErrorList arg1);
#define CO_isEqualErrorList(arg0, arg1) (_CO_isEqualErrorList(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualLocation(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualLocation(CO_Location arg0, CO_Location arg1);
#define CO_isEqualLocation(arg0, arg1) (_CO_isEqualLocation(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualArea(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualArea(CO_Area arg0, CO_Area arg1);
#define CO_isEqualArea(arg0, arg1) (_CO_isEqualArea(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualRead(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualRead(CO_Read arg0, CO_Read arg1);
#define CO_isEqualRead(arg0, arg1) (_CO_isEqualRead(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualWrite(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualWrite(CO_Write arg0, CO_Write arg1);
#define CO_isEqualWrite(arg0, arg1) (_CO_isEqualWrite(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualParsetreeX(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualParsetreeX(CO_ParsetreeX arg0, CO_ParsetreeX arg1);
#define CO_isEqualParsetreeX(arg0, arg1) (_CO_isEqualParsetreeX(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualX(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualX(CO_X arg0, CO_X arg1);
#define CO_isEqualX(arg0, arg1) (_CO_isEqualX(arg0, arg1))
#endif
#ifdef FAST_API
#define CO_isEqualBoolean(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _CO_isEqualBoolean(CO_Boolean arg0, CO_Boolean arg1);
#define CO_isEqualBoolean(arg0, arg1) (_CO_isEqualBoolean(arg0, arg1))
#endif
ATbool CO_isValidOptLayout(CO_OptLayout arg);
inline ATbool CO_isOptLayoutAbsent(CO_OptLayout arg);
inline ATbool CO_isOptLayoutPresent(CO_OptLayout arg);
ATbool CO_hasOptLayoutLayout(CO_OptLayout arg);
CO_Layout CO_getOptLayoutLayout(CO_OptLayout arg);
CO_OptLayout CO_setOptLayoutLayout(CO_OptLayout arg, CO_Layout layout);
ATbool CO_isValidLayout(CO_Layout arg);
inline ATbool CO_isLayoutLexToCf(CO_Layout arg);
ATbool CO_hasLayoutList(CO_Layout arg);
CO_LexLayoutList CO_getLayoutList(CO_Layout arg);
CO_Layout CO_setLayoutList(CO_Layout arg, CO_LexLayoutList list);
ATbool CO_isValidLexLayoutList(CO_LexLayoutList arg);
inline ATbool CO_isLexLayoutListEmpty(CO_LexLayoutList arg);
inline ATbool CO_isLexLayoutListSingle(CO_LexLayoutList arg);
inline ATbool CO_isLexLayoutListMany(CO_LexLayoutList arg);
ATbool CO_hasLexLayoutListHead(CO_LexLayoutList arg);
ATbool CO_hasLexLayoutListTail(CO_LexLayoutList arg);
CO_LexLayout CO_getLexLayoutListHead(CO_LexLayoutList arg);
CO_LexLayoutList CO_getLexLayoutListTail(CO_LexLayoutList arg);
CO_LexLayoutList CO_setLexLayoutListHead(CO_LexLayoutList arg, CO_LexLayout head);
CO_LexLayoutList CO_setLexLayoutListTail(CO_LexLayoutList arg, CO_LexLayoutList tail);
ATbool CO_isValidLexLayout(CO_LexLayout arg);
inline ATbool CO_isLexLayoutWhitespace(CO_LexLayout arg);
ATbool CO_hasLexLayoutCh(CO_LexLayout arg);
char CO_getLexLayoutCh(CO_LexLayout arg);
CO_LexLayout CO_setLexLayoutCh(CO_LexLayout arg, char ch);
ATbool CO_isValidStart(CO_Start arg);
inline ATbool CO_isStartStrCon(CO_Start arg);
inline ATbool CO_isStartBoolCon(CO_Start arg);
inline ATbool CO_isStartSummary(CO_Start arg);
inline ATbool CO_isStartError(CO_Start arg);
inline ATbool CO_isStartBoolean(CO_Start arg);
ATbool CO_hasStartWsBefore(CO_Start arg);
ATbool CO_hasStartTopStrCon(CO_Start arg);
ATbool CO_hasStartWsAfter(CO_Start arg);
ATbool CO_hasStartAmbCnt(CO_Start arg);
ATbool CO_hasStartTopBoolCon(CO_Start arg);
ATbool CO_hasStartTopSummary(CO_Start arg);
ATbool CO_hasStartTopError(CO_Start arg);
ATbool CO_hasStartTopBoolean(CO_Start arg);
CO_OptLayout CO_getStartWsBefore(CO_Start arg);
CO_StrCon CO_getStartTopStrCon(CO_Start arg);
CO_OptLayout CO_getStartWsAfter(CO_Start arg);
int CO_getStartAmbCnt(CO_Start arg);
CO_BoolCon CO_getStartTopBoolCon(CO_Start arg);
CO_Summary CO_getStartTopSummary(CO_Start arg);
CO_Error CO_getStartTopError(CO_Start arg);
CO_Boolean CO_getStartTopBoolean(CO_Start arg);
CO_Start CO_setStartWsBefore(CO_Start arg, CO_OptLayout wsBefore);
CO_Start CO_setStartTopStrCon(CO_Start arg, CO_StrCon topStrCon);
CO_Start CO_setStartWsAfter(CO_Start arg, CO_OptLayout wsAfter);
CO_Start CO_setStartAmbCnt(CO_Start arg, int ambCnt);
CO_Start CO_setStartTopBoolCon(CO_Start arg, CO_BoolCon topBoolCon);
CO_Start CO_setStartTopSummary(CO_Start arg, CO_Summary topSummary);
CO_Start CO_setStartTopError(CO_Start arg, CO_Error topError);
CO_Start CO_setStartTopBoolean(CO_Start arg, CO_Boolean topBoolean);
ATbool CO_isValidLexStrChar(CO_LexStrChar arg);
inline ATbool CO_isLexStrCharNewline(CO_LexStrChar arg);
inline ATbool CO_isLexStrCharTab(CO_LexStrChar arg);
inline ATbool CO_isLexStrCharQuote(CO_LexStrChar arg);
inline ATbool CO_isLexStrCharBackslash(CO_LexStrChar arg);
inline ATbool CO_isLexStrCharDecimal(CO_LexStrChar arg);
inline ATbool CO_isLexStrCharNormal(CO_LexStrChar arg);
ATbool CO_hasLexStrCharA(CO_LexStrChar arg);
ATbool CO_hasLexStrCharB(CO_LexStrChar arg);
ATbool CO_hasLexStrCharC(CO_LexStrChar arg);
ATbool CO_hasLexStrCharCh(CO_LexStrChar arg);
char CO_getLexStrCharA(CO_LexStrChar arg);
char CO_getLexStrCharB(CO_LexStrChar arg);
char CO_getLexStrCharC(CO_LexStrChar arg);
char CO_getLexStrCharCh(CO_LexStrChar arg);
CO_LexStrChar CO_setLexStrCharA(CO_LexStrChar arg, char a);
CO_LexStrChar CO_setLexStrCharB(CO_LexStrChar arg, char b);
CO_LexStrChar CO_setLexStrCharC(CO_LexStrChar arg, char c);
CO_LexStrChar CO_setLexStrCharCh(CO_LexStrChar arg, char ch);
ATbool CO_isValidStrChar(CO_StrChar arg);
inline ATbool CO_isStrCharLexToCf(CO_StrChar arg);
ATbool CO_hasStrCharStrChar(CO_StrChar arg);
CO_LexStrChar CO_getStrCharStrChar(CO_StrChar arg);
CO_StrChar CO_setStrCharStrChar(CO_StrChar arg, CO_LexStrChar StrChar);
ATbool CO_isValidLexStrCon(CO_LexStrCon arg);
inline ATbool CO_isLexStrConDefault(CO_LexStrCon arg);
ATbool CO_hasLexStrConChars(CO_LexStrCon arg);
CO_LexStrCharChars CO_getLexStrConChars(CO_LexStrCon arg);
CO_LexStrCon CO_setLexStrConChars(CO_LexStrCon arg, CO_LexStrCharChars chars);
ATbool CO_isValidStrCon(CO_StrCon arg);
inline ATbool CO_isStrConLexToCf(CO_StrCon arg);
ATbool CO_hasStrConStrCon(CO_StrCon arg);
CO_LexStrCon CO_getStrConStrCon(CO_StrCon arg);
CO_StrCon CO_setStrConStrCon(CO_StrCon arg, CO_LexStrCon StrCon);
ATbool CO_isValidLexStrCharChars(CO_LexStrCharChars arg);
inline ATbool CO_isLexStrCharCharsEmpty(CO_LexStrCharChars arg);
inline ATbool CO_isLexStrCharCharsSingle(CO_LexStrCharChars arg);
inline ATbool CO_isLexStrCharCharsMany(CO_LexStrCharChars arg);
ATbool CO_hasLexStrCharCharsHead(CO_LexStrCharChars arg);
ATbool CO_hasLexStrCharCharsTail(CO_LexStrCharChars arg);
CO_LexStrChar CO_getLexStrCharCharsHead(CO_LexStrCharChars arg);
CO_LexStrCharChars CO_getLexStrCharCharsTail(CO_LexStrCharChars arg);
CO_LexStrCharChars CO_setLexStrCharCharsHead(CO_LexStrCharChars arg, CO_LexStrChar head);
CO_LexStrCharChars CO_setLexStrCharCharsTail(CO_LexStrCharChars arg, CO_LexStrCharChars tail);
ATbool CO_isValidBoolCon(CO_BoolCon arg);
inline ATbool CO_isBoolConTrue(CO_BoolCon arg);
inline ATbool CO_isBoolConFalse(CO_BoolCon arg);
ATbool CO_isValidLexNatCon(CO_LexNatCon arg);
inline ATbool CO_isLexNatConDigits(CO_LexNatCon arg);
ATbool CO_hasLexNatConList(CO_LexNatCon arg);
char* CO_getLexNatConList(CO_LexNatCon arg);
CO_LexNatCon CO_setLexNatConList(CO_LexNatCon arg, const char* list);
ATbool CO_isValidNatCon(CO_NatCon arg);
inline ATbool CO_isNatConLexToCf(CO_NatCon arg);
ATbool CO_hasNatConNatCon(CO_NatCon arg);
CO_LexNatCon CO_getNatConNatCon(CO_NatCon arg);
CO_NatCon CO_setNatConNatCon(CO_NatCon arg, CO_LexNatCon NatCon);
ATbool CO_isValidLexByte(CO_LexByte arg);
inline ATbool CO_isLexByteByte(CO_LexByte arg);
ATbool CO_hasLexByteCh(CO_LexByte arg);
char CO_getLexByteCh(CO_LexByte arg);
CO_LexByte CO_setLexByteCh(CO_LexByte arg, char ch);
ATbool CO_isValidByte(CO_Byte arg);
inline ATbool CO_isByteLexToCf(CO_Byte arg);
ATbool CO_hasByteByte(CO_Byte arg);
CO_LexByte CO_getByteByte(CO_Byte arg);
CO_Byte CO_setByteByte(CO_Byte arg, CO_LexByte Byte);
ATbool CO_isValidLexBytes(CO_LexBytes arg);
inline ATbool CO_isLexBytesBytes(CO_LexBytes arg);
ATbool CO_hasLexBytesList(CO_LexBytes arg);
CO_LexByteList CO_getLexBytesList(CO_LexBytes arg);
CO_LexBytes CO_setLexBytesList(CO_LexBytes arg, CO_LexByteList list);
ATbool CO_isValidBytes(CO_Bytes arg);
inline ATbool CO_isBytesLexToCf(CO_Bytes arg);
ATbool CO_hasBytesBytes(CO_Bytes arg);
CO_LexBytes CO_getBytesBytes(CO_Bytes arg);
CO_Bytes CO_setBytesBytes(CO_Bytes arg, CO_LexBytes Bytes);
ATbool CO_isValidLexByteList(CO_LexByteList arg);
inline ATbool CO_isLexByteListEmpty(CO_LexByteList arg);
inline ATbool CO_isLexByteListSingle(CO_LexByteList arg);
inline ATbool CO_isLexByteListMany(CO_LexByteList arg);
ATbool CO_hasLexByteListHead(CO_LexByteList arg);
ATbool CO_hasLexByteListTail(CO_LexByteList arg);
CO_LexByte CO_getLexByteListHead(CO_LexByteList arg);
CO_LexByteList CO_getLexByteListTail(CO_LexByteList arg);
CO_LexByteList CO_setLexByteListHead(CO_LexByteList arg, CO_LexByte head);
CO_LexByteList CO_setLexByteListTail(CO_LexByteList arg, CO_LexByteList tail);
ATbool CO_isValidSubject(CO_Subject arg);
inline ATbool CO_isSubjectSubject(CO_Subject arg);
inline ATbool CO_isSubjectLocalized(CO_Subject arg);
ATbool CO_hasSubjectWsAfterSubject(CO_Subject arg);
ATbool CO_hasSubjectWsAfterParenOpen(CO_Subject arg);
ATbool CO_hasSubjectDescription(CO_Subject arg);
ATbool CO_hasSubjectWsAfterDescription(CO_Subject arg);
ATbool CO_hasSubjectWsAfterLocalized(CO_Subject arg);
ATbool CO_hasSubjectWsAfterComma(CO_Subject arg);
ATbool CO_hasSubjectLocation(CO_Subject arg);
ATbool CO_hasSubjectWsAfterLocation(CO_Subject arg);
CO_OptLayout CO_getSubjectWsAfterSubject(CO_Subject arg);
CO_OptLayout CO_getSubjectWsAfterParenOpen(CO_Subject arg);
CO_StrCon CO_getSubjectDescription(CO_Subject arg);
CO_OptLayout CO_getSubjectWsAfterDescription(CO_Subject arg);
CO_OptLayout CO_getSubjectWsAfterLocalized(CO_Subject arg);
CO_OptLayout CO_getSubjectWsAfterComma(CO_Subject arg);
CO_Location CO_getSubjectLocation(CO_Subject arg);
CO_OptLayout CO_getSubjectWsAfterLocation(CO_Subject arg);
CO_Subject CO_setSubjectWsAfterSubject(CO_Subject arg, CO_OptLayout wsAfterSubject);
CO_Subject CO_setSubjectWsAfterParenOpen(CO_Subject arg, CO_OptLayout wsAfterParenOpen);
CO_Subject CO_setSubjectDescription(CO_Subject arg, CO_StrCon description);
CO_Subject CO_setSubjectWsAfterDescription(CO_Subject arg, CO_OptLayout wsAfterDescription);
CO_Subject CO_setSubjectWsAfterLocalized(CO_Subject arg, CO_OptLayout wsAfterLocalized);
CO_Subject CO_setSubjectWsAfterComma(CO_Subject arg, CO_OptLayout wsAfterComma);
CO_Subject CO_setSubjectLocation(CO_Subject arg, CO_Location Location);
CO_Subject CO_setSubjectWsAfterLocation(CO_Subject arg, CO_OptLayout wsAfterLocation);
ATbool CO_isValidError(CO_Error arg);
inline ATbool CO_isErrorInfo(CO_Error arg);
inline ATbool CO_isErrorWarning(CO_Error arg);
inline ATbool CO_isErrorError(CO_Error arg);
inline ATbool CO_isErrorFatal(CO_Error arg);
ATbool CO_hasErrorWsAfterInfo(CO_Error arg);
ATbool CO_hasErrorWsAfterParenOpen(CO_Error arg);
ATbool CO_hasErrorDescription(CO_Error arg);
ATbool CO_hasErrorWsAfterDescription(CO_Error arg);
ATbool CO_hasErrorWsAfterComma(CO_Error arg);
ATbool CO_hasErrorWsAfterBracketOpen(CO_Error arg);
ATbool CO_hasErrorList(CO_Error arg);
ATbool CO_hasErrorWsAfterList(CO_Error arg);
ATbool CO_hasErrorWsAfterBracketClose(CO_Error arg);
ATbool CO_hasErrorWsAfterWarning(CO_Error arg);
ATbool CO_hasErrorWsAfterError(CO_Error arg);
ATbool CO_hasErrorWsAfterFatal(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterInfo(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterParenOpen(CO_Error arg);
CO_StrCon CO_getErrorDescription(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterDescription(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterComma(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterBracketOpen(CO_Error arg);
CO_SubjectList CO_getErrorList(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterList(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterBracketClose(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterWarning(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterError(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterFatal(CO_Error arg);
CO_Error CO_setErrorWsAfterInfo(CO_Error arg, CO_OptLayout wsAfterInfo);
CO_Error CO_setErrorWsAfterParenOpen(CO_Error arg, CO_OptLayout wsAfterParenOpen);
CO_Error CO_setErrorDescription(CO_Error arg, CO_StrCon description);
CO_Error CO_setErrorWsAfterDescription(CO_Error arg, CO_OptLayout wsAfterDescription);
CO_Error CO_setErrorWsAfterComma(CO_Error arg, CO_OptLayout wsAfterComma);
CO_Error CO_setErrorWsAfterBracketOpen(CO_Error arg, CO_OptLayout wsAfterBracketOpen);
CO_Error CO_setErrorList(CO_Error arg, CO_SubjectList list);
CO_Error CO_setErrorWsAfterList(CO_Error arg, CO_OptLayout wsAfterList);
CO_Error CO_setErrorWsAfterBracketClose(CO_Error arg, CO_OptLayout wsAfterBracketClose);
CO_Error CO_setErrorWsAfterWarning(CO_Error arg, CO_OptLayout wsAfterWarning);
CO_Error CO_setErrorWsAfterError(CO_Error arg, CO_OptLayout wsAfterError);
CO_Error CO_setErrorWsAfterFatal(CO_Error arg, CO_OptLayout wsAfterFatal);
ATbool CO_isValidSummary(CO_Summary arg);
inline ATbool CO_isSummarySummary(CO_Summary arg);
ATbool CO_hasSummaryWsAfterSummary(CO_Summary arg);
ATbool CO_hasSummaryWsAfterParenOpen(CO_Summary arg);
ATbool CO_hasSummaryProducer(CO_Summary arg);
ATbool CO_hasSummaryWsAfterProducer(CO_Summary arg);
ATbool CO_hasSummaryWsAfterComma(CO_Summary arg);
ATbool CO_hasSummaryId(CO_Summary arg);
ATbool CO_hasSummaryWsAfterId(CO_Summary arg);
ATbool CO_hasSummaryWsAfterComma1(CO_Summary arg);
ATbool CO_hasSummaryWsAfterBracketOpen(CO_Summary arg);
ATbool CO_hasSummaryList(CO_Summary arg);
ATbool CO_hasSummaryWsAfterList(CO_Summary arg);
ATbool CO_hasSummaryWsAfterBracketClose(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterSummary(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterParenOpen(CO_Summary arg);
CO_StrCon CO_getSummaryProducer(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterProducer(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterComma(CO_Summary arg);
CO_StrCon CO_getSummaryId(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterId(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterComma1(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterBracketOpen(CO_Summary arg);
CO_ErrorList CO_getSummaryList(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterList(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterBracketClose(CO_Summary arg);
CO_Summary CO_setSummaryWsAfterSummary(CO_Summary arg, CO_OptLayout wsAfterSummary);
CO_Summary CO_setSummaryWsAfterParenOpen(CO_Summary arg, CO_OptLayout wsAfterParenOpen);
CO_Summary CO_setSummaryProducer(CO_Summary arg, CO_StrCon producer);
CO_Summary CO_setSummaryWsAfterProducer(CO_Summary arg, CO_OptLayout wsAfterProducer);
CO_Summary CO_setSummaryWsAfterComma(CO_Summary arg, CO_OptLayout wsAfterComma);
CO_Summary CO_setSummaryId(CO_Summary arg, CO_StrCon id);
CO_Summary CO_setSummaryWsAfterId(CO_Summary arg, CO_OptLayout wsAfterId);
CO_Summary CO_setSummaryWsAfterComma1(CO_Summary arg, CO_OptLayout wsAfterComma1);
CO_Summary CO_setSummaryWsAfterBracketOpen(CO_Summary arg, CO_OptLayout wsAfterBracketOpen);
CO_Summary CO_setSummaryList(CO_Summary arg, CO_ErrorList list);
CO_Summary CO_setSummaryWsAfterList(CO_Summary arg, CO_OptLayout wsAfterList);
CO_Summary CO_setSummaryWsAfterBracketClose(CO_Summary arg, CO_OptLayout wsAfterBracketClose);
ATbool CO_isValidSubjectList(CO_SubjectList arg);
inline ATbool CO_isSubjectListEmpty(CO_SubjectList arg);
inline ATbool CO_isSubjectListSingle(CO_SubjectList arg);
inline ATbool CO_isSubjectListMany(CO_SubjectList arg);
ATbool CO_hasSubjectListHead(CO_SubjectList arg);
ATbool CO_hasSubjectListWsAfterHead(CO_SubjectList arg);
ATbool CO_hasSubjectListWsAfterSep(CO_SubjectList arg);
ATbool CO_hasSubjectListTail(CO_SubjectList arg);
CO_SubjectList CO_getSubjectListTail(CO_SubjectList arg);
CO_Subject CO_getSubjectListHead(CO_SubjectList arg);
CO_OptLayout CO_getSubjectListWsAfterHead(CO_SubjectList arg);
CO_OptLayout CO_getSubjectListWsAfterSep(CO_SubjectList arg);
CO_SubjectList CO_setSubjectListHead(CO_SubjectList arg, CO_Subject head);
CO_SubjectList CO_setSubjectListWsAfterHead(CO_SubjectList arg, CO_OptLayout wsAfterHead);
CO_SubjectList CO_setSubjectListWsAfterSep(CO_SubjectList arg, CO_OptLayout wsAfterSep);
CO_SubjectList CO_setSubjectListTail(CO_SubjectList arg, CO_SubjectList tail);
ATbool CO_isValidErrorList(CO_ErrorList arg);
inline ATbool CO_isErrorListEmpty(CO_ErrorList arg);
inline ATbool CO_isErrorListSingle(CO_ErrorList arg);
inline ATbool CO_isErrorListMany(CO_ErrorList arg);
ATbool CO_hasErrorListHead(CO_ErrorList arg);
ATbool CO_hasErrorListWsAfterHead(CO_ErrorList arg);
ATbool CO_hasErrorListWsAfterSep(CO_ErrorList arg);
ATbool CO_hasErrorListTail(CO_ErrorList arg);
CO_ErrorList CO_getErrorListTail(CO_ErrorList arg);
CO_Error CO_getErrorListHead(CO_ErrorList arg);
CO_OptLayout CO_getErrorListWsAfterHead(CO_ErrorList arg);
CO_OptLayout CO_getErrorListWsAfterSep(CO_ErrorList arg);
CO_ErrorList CO_setErrorListHead(CO_ErrorList arg, CO_Error head);
CO_ErrorList CO_setErrorListWsAfterHead(CO_ErrorList arg, CO_OptLayout wsAfterHead);
CO_ErrorList CO_setErrorListWsAfterSep(CO_ErrorList arg, CO_OptLayout wsAfterSep);
CO_ErrorList CO_setErrorListTail(CO_ErrorList arg, CO_ErrorList tail);
ATbool CO_isValidLocation(CO_Location arg);
inline ATbool CO_isLocationFile(CO_Location arg);
inline ATbool CO_isLocationArea(CO_Location arg);
inline ATbool CO_isLocationAreaInFile(CO_Location arg);
ATbool CO_hasLocationWsAfterFile(CO_Location arg);
ATbool CO_hasLocationWsAfterParenOpen(CO_Location arg);
ATbool CO_hasLocationFilename(CO_Location arg);
ATbool CO_hasLocationWsAfterFilename(CO_Location arg);
ATbool CO_hasLocationWsAfterA(CO_Location arg);
ATbool CO_hasLocationArea(CO_Location arg);
ATbool CO_hasLocationWsAfterArea(CO_Location arg);
ATbool CO_hasLocationWsAfterAreaInFile(CO_Location arg);
ATbool CO_hasLocationWsAfterComma(CO_Location arg);
CO_OptLayout CO_getLocationWsAfterFile(CO_Location arg);
CO_OptLayout CO_getLocationWsAfterParenOpen(CO_Location arg);
CO_StrCon CO_getLocationFilename(CO_Location arg);
CO_OptLayout CO_getLocationWsAfterFilename(CO_Location arg);
CO_OptLayout CO_getLocationWsAfterA(CO_Location arg);
CO_Area CO_getLocationArea(CO_Location arg);
CO_OptLayout CO_getLocationWsAfterArea(CO_Location arg);
CO_OptLayout CO_getLocationWsAfterAreaInFile(CO_Location arg);
CO_OptLayout CO_getLocationWsAfterComma(CO_Location arg);
CO_Location CO_setLocationWsAfterFile(CO_Location arg, CO_OptLayout wsAfterFile);
CO_Location CO_setLocationWsAfterParenOpen(CO_Location arg, CO_OptLayout wsAfterParenOpen);
CO_Location CO_setLocationFilename(CO_Location arg, CO_StrCon filename);
CO_Location CO_setLocationWsAfterFilename(CO_Location arg, CO_OptLayout wsAfterFilename);
CO_Location CO_setLocationWsAfterA(CO_Location arg, CO_OptLayout wsAfterA);
CO_Location CO_setLocationArea(CO_Location arg, CO_Area Area);
CO_Location CO_setLocationWsAfterArea(CO_Location arg, CO_OptLayout wsAfterArea);
CO_Location CO_setLocationWsAfterAreaInFile(CO_Location arg, CO_OptLayout wsAfterAreaInFile);
CO_Location CO_setLocationWsAfterComma(CO_Location arg, CO_OptLayout wsAfterComma);
ATbool CO_isValidArea(CO_Area arg);
inline ATbool CO_isAreaArea(CO_Area arg);
ATbool CO_hasAreaWsAfterArea(CO_Area arg);
ATbool CO_hasAreaWsAfterParenOpen(CO_Area arg);
ATbool CO_hasAreaBeginLine(CO_Area arg);
ATbool CO_hasAreaWsAfterBeginLine(CO_Area arg);
ATbool CO_hasAreaWsAfterComma(CO_Area arg);
ATbool CO_hasAreaBeginColumn(CO_Area arg);
ATbool CO_hasAreaWsAfterBeginColumn(CO_Area arg);
ATbool CO_hasAreaWsAfterComma1(CO_Area arg);
ATbool CO_hasAreaEndLine(CO_Area arg);
ATbool CO_hasAreaWsAfterEndLine(CO_Area arg);
ATbool CO_hasAreaWsAfterComma2(CO_Area arg);
ATbool CO_hasAreaEndColumn(CO_Area arg);
ATbool CO_hasAreaWsAfterEndColumn(CO_Area arg);
ATbool CO_hasAreaWsAfterComma3(CO_Area arg);
ATbool CO_hasAreaOffset(CO_Area arg);
ATbool CO_hasAreaWsAfterOffset(CO_Area arg);
ATbool CO_hasAreaWsAfterComma4(CO_Area arg);
ATbool CO_hasAreaLength(CO_Area arg);
ATbool CO_hasAreaWsAfterLength(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterArea(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterParenOpen(CO_Area arg);
CO_NatCon CO_getAreaBeginLine(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterBeginLine(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterComma(CO_Area arg);
CO_NatCon CO_getAreaBeginColumn(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterBeginColumn(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterComma1(CO_Area arg);
CO_NatCon CO_getAreaEndLine(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterEndLine(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterComma2(CO_Area arg);
CO_NatCon CO_getAreaEndColumn(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterEndColumn(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterComma3(CO_Area arg);
CO_NatCon CO_getAreaOffset(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterOffset(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterComma4(CO_Area arg);
CO_NatCon CO_getAreaLength(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterLength(CO_Area arg);
CO_Area CO_setAreaWsAfterArea(CO_Area arg, CO_OptLayout wsAfterArea);
CO_Area CO_setAreaWsAfterParenOpen(CO_Area arg, CO_OptLayout wsAfterParenOpen);
CO_Area CO_setAreaBeginLine(CO_Area arg, CO_NatCon beginLine);
CO_Area CO_setAreaWsAfterBeginLine(CO_Area arg, CO_OptLayout wsAfterBeginLine);
CO_Area CO_setAreaWsAfterComma(CO_Area arg, CO_OptLayout wsAfterComma);
CO_Area CO_setAreaBeginColumn(CO_Area arg, CO_NatCon beginColumn);
CO_Area CO_setAreaWsAfterBeginColumn(CO_Area arg, CO_OptLayout wsAfterBeginColumn);
CO_Area CO_setAreaWsAfterComma1(CO_Area arg, CO_OptLayout wsAfterComma1);
CO_Area CO_setAreaEndLine(CO_Area arg, CO_NatCon endLine);
CO_Area CO_setAreaWsAfterEndLine(CO_Area arg, CO_OptLayout wsAfterEndLine);
CO_Area CO_setAreaWsAfterComma2(CO_Area arg, CO_OptLayout wsAfterComma2);
CO_Area CO_setAreaEndColumn(CO_Area arg, CO_NatCon endColumn);
CO_Area CO_setAreaWsAfterEndColumn(CO_Area arg, CO_OptLayout wsAfterEndColumn);
CO_Area CO_setAreaWsAfterComma3(CO_Area arg, CO_OptLayout wsAfterComma3);
CO_Area CO_setAreaOffset(CO_Area arg, CO_NatCon offset);
CO_Area CO_setAreaWsAfterOffset(CO_Area arg, CO_OptLayout wsAfterOffset);
CO_Area CO_setAreaWsAfterComma4(CO_Area arg, CO_OptLayout wsAfterComma4);
CO_Area CO_setAreaLength(CO_Area arg, CO_NatCon length);
CO_Area CO_setAreaWsAfterLength(CO_Area arg, CO_OptLayout wsAfterLength);
ATbool CO_isValidRead(CO_Read arg);
inline ATbool CO_isReadSuccess(CO_Read arg);
inline ATbool CO_isReadFailure(CO_Read arg);
ATbool CO_hasReadWsAfterRead(CO_Read arg);
ATbool CO_hasReadWsAfterParenOpen(CO_Read arg);
ATbool CO_hasReadValue(CO_Read arg);
ATbool CO_hasReadWsAfterValue(CO_Read arg);
ATbool CO_hasReadWsAfterReadError(CO_Read arg);
ATbool CO_hasReadSummary(CO_Read arg);
ATbool CO_hasReadWsAfterSummary(CO_Read arg);
CO_OptLayout CO_getReadWsAfterRead(CO_Read arg);
CO_OptLayout CO_getReadWsAfterParenOpen(CO_Read arg);
CO_Bytes CO_getReadValue(CO_Read arg);
CO_OptLayout CO_getReadWsAfterValue(CO_Read arg);
CO_OptLayout CO_getReadWsAfterReadError(CO_Read arg);
CO_Summary CO_getReadSummary(CO_Read arg);
CO_OptLayout CO_getReadWsAfterSummary(CO_Read arg);
CO_Read CO_setReadWsAfterRead(CO_Read arg, CO_OptLayout wsAfterRead);
CO_Read CO_setReadWsAfterParenOpen(CO_Read arg, CO_OptLayout wsAfterParenOpen);
CO_Read CO_setReadValue(CO_Read arg, CO_Bytes value);
CO_Read CO_setReadWsAfterValue(CO_Read arg, CO_OptLayout wsAfterValue);
CO_Read CO_setReadWsAfterReadError(CO_Read arg, CO_OptLayout wsAfterReadError);
CO_Read CO_setReadSummary(CO_Read arg, CO_Summary Summary);
CO_Read CO_setReadWsAfterSummary(CO_Read arg, CO_OptLayout wsAfterSummary);
ATbool CO_isValidWrite(CO_Write arg);
inline ATbool CO_isWriteSuccess(CO_Write arg);
inline ATbool CO_isWriteFailure(CO_Write arg);
ATbool CO_hasWriteWsAfterWriteError(CO_Write arg);
ATbool CO_hasWriteWsAfterParenOpen(CO_Write arg);
ATbool CO_hasWriteSummary(CO_Write arg);
ATbool CO_hasWriteWsAfterSummary(CO_Write arg);
CO_OptLayout CO_getWriteWsAfterWriteError(CO_Write arg);
CO_OptLayout CO_getWriteWsAfterParenOpen(CO_Write arg);
CO_Summary CO_getWriteSummary(CO_Write arg);
CO_OptLayout CO_getWriteWsAfterSummary(CO_Write arg);
CO_Write CO_setWriteWsAfterWriteError(CO_Write arg, CO_OptLayout wsAfterWriteError);
CO_Write CO_setWriteWsAfterParenOpen(CO_Write arg, CO_OptLayout wsAfterParenOpen);
CO_Write CO_setWriteSummary(CO_Write arg, CO_Summary Summary);
CO_Write CO_setWriteWsAfterSummary(CO_Write arg, CO_OptLayout wsAfterSummary);
ATbool CO_isValidParsetreeX(CO_ParsetreeX arg);
inline ATbool CO_isParsetreeXSuccess(CO_ParsetreeX arg);
inline ATbool CO_isParsetreeXFailure(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXTypeOfTree(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXTypeOfX(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXWsAfterParseTree(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXWsAfterParenOpen(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXLeftLayout(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXWsAfterLeftLayout(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXWsAfterComma(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXTree(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXWsAfterTree(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXWsAfterComma1(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXRightLayout(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXWsAfterRightLayout(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXWsAfterComma2(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXAmbCnt(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXWsAfterAmbCnt(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXWsAfterParseError(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXSummary(CO_ParsetreeX arg);
ATbool CO_hasParsetreeXWsAfterSummary(CO_ParsetreeX arg);
ATerm CO_getParsetreeXTypeOfTree(CO_ParsetreeX arg);
ATerm CO_getParsetreeXTypeOfX(CO_ParsetreeX arg);
CO_OptLayout CO_getParsetreeXWsAfterParseTree(CO_ParsetreeX arg);
CO_OptLayout CO_getParsetreeXWsAfterParenOpen(CO_ParsetreeX arg);
CO_Bytes CO_getParsetreeXLeftLayout(CO_ParsetreeX arg);
CO_OptLayout CO_getParsetreeXWsAfterLeftLayout(CO_ParsetreeX arg);
CO_OptLayout CO_getParsetreeXWsAfterComma(CO_ParsetreeX arg);
CO_X CO_getParsetreeXTree(CO_ParsetreeX arg);
CO_OptLayout CO_getParsetreeXWsAfterTree(CO_ParsetreeX arg);
CO_OptLayout CO_getParsetreeXWsAfterComma1(CO_ParsetreeX arg);
CO_Bytes CO_getParsetreeXRightLayout(CO_ParsetreeX arg);
CO_OptLayout CO_getParsetreeXWsAfterRightLayout(CO_ParsetreeX arg);
CO_OptLayout CO_getParsetreeXWsAfterComma2(CO_ParsetreeX arg);
CO_NatCon CO_getParsetreeXAmbCnt(CO_ParsetreeX arg);
CO_OptLayout CO_getParsetreeXWsAfterAmbCnt(CO_ParsetreeX arg);
CO_OptLayout CO_getParsetreeXWsAfterParseError(CO_ParsetreeX arg);
CO_Summary CO_getParsetreeXSummary(CO_ParsetreeX arg);
CO_OptLayout CO_getParsetreeXWsAfterSummary(CO_ParsetreeX arg);
CO_ParsetreeX CO_setParsetreeXTypeOfTree(CO_ParsetreeX arg, ATerm typeOfTree);
CO_ParsetreeX CO_setParsetreeXTypeOfX(CO_ParsetreeX arg, ATerm typeOfX);
CO_ParsetreeX CO_setParsetreeXWsAfterParseTree(CO_ParsetreeX arg, CO_OptLayout wsAfterParseTree);
CO_ParsetreeX CO_setParsetreeXWsAfterParenOpen(CO_ParsetreeX arg, CO_OptLayout wsAfterParenOpen);
CO_ParsetreeX CO_setParsetreeXLeftLayout(CO_ParsetreeX arg, CO_Bytes leftLayout);
CO_ParsetreeX CO_setParsetreeXWsAfterLeftLayout(CO_ParsetreeX arg, CO_OptLayout wsAfterLeftLayout);
CO_ParsetreeX CO_setParsetreeXWsAfterComma(CO_ParsetreeX arg, CO_OptLayout wsAfterComma);
CO_ParsetreeX CO_setParsetreeXTree(CO_ParsetreeX arg, CO_X tree);
CO_ParsetreeX CO_setParsetreeXWsAfterTree(CO_ParsetreeX arg, CO_OptLayout wsAfterTree);
CO_ParsetreeX CO_setParsetreeXWsAfterComma1(CO_ParsetreeX arg, CO_OptLayout wsAfterComma1);
CO_ParsetreeX CO_setParsetreeXRightLayout(CO_ParsetreeX arg, CO_Bytes rightLayout);
CO_ParsetreeX CO_setParsetreeXWsAfterRightLayout(CO_ParsetreeX arg, CO_OptLayout wsAfterRightLayout);
CO_ParsetreeX CO_setParsetreeXWsAfterComma2(CO_ParsetreeX arg, CO_OptLayout wsAfterComma2);
CO_ParsetreeX CO_setParsetreeXAmbCnt(CO_ParsetreeX arg, CO_NatCon ambCnt);
CO_ParsetreeX CO_setParsetreeXWsAfterAmbCnt(CO_ParsetreeX arg, CO_OptLayout wsAfterAmbCnt);
CO_ParsetreeX CO_setParsetreeXWsAfterParseError(CO_ParsetreeX arg, CO_OptLayout wsAfterParseError);
CO_ParsetreeX CO_setParsetreeXSummary(CO_ParsetreeX arg, CO_Summary Summary);
CO_ParsetreeX CO_setParsetreeXWsAfterSummary(CO_ParsetreeX arg, CO_OptLayout wsAfterSummary);
ATbool CO_isValidX(CO_X arg);
inline ATbool CO_isXCast(CO_X arg);
ATbool CO_hasXX(CO_X arg);
ATerm CO_getXX(CO_X arg);
CO_X CO_setXX(CO_X arg, ATerm X);
ATbool CO_isValidBoolean(CO_Boolean arg);
inline ATbool CO_isBooleanConstant(CO_Boolean arg);
inline ATbool CO_isBooleanOr(CO_Boolean arg);
inline ATbool CO_isBooleanAnd(CO_Boolean arg);
inline ATbool CO_isBooleanNot(CO_Boolean arg);
inline ATbool CO_isBooleanBracket(CO_Boolean arg);
ATbool CO_hasBooleanBoolCon(CO_Boolean arg);
ATbool CO_hasBooleanLhs(CO_Boolean arg);
ATbool CO_hasBooleanWsAfterLhs(CO_Boolean arg);
ATbool CO_hasBooleanWsAfterBar(CO_Boolean arg);
ATbool CO_hasBooleanRhs(CO_Boolean arg);
ATbool CO_hasBooleanWsAfterAmp(CO_Boolean arg);
ATbool CO_hasBooleanWsAfterNot(CO_Boolean arg);
ATbool CO_hasBooleanWsAfterParenOpen(CO_Boolean arg);
ATbool CO_hasBooleanBoolean(CO_Boolean arg);
ATbool CO_hasBooleanWsAfterBoolean(CO_Boolean arg);
CO_BoolCon CO_getBooleanBoolCon(CO_Boolean arg);
CO_Boolean CO_getBooleanLhs(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterLhs(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterBar(CO_Boolean arg);
CO_Boolean CO_getBooleanRhs(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterAmp(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterNot(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterParenOpen(CO_Boolean arg);
CO_Boolean CO_getBooleanBoolean(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterBoolean(CO_Boolean arg);
CO_Boolean CO_setBooleanBoolCon(CO_Boolean arg, CO_BoolCon BoolCon);
CO_Boolean CO_setBooleanLhs(CO_Boolean arg, CO_Boolean lhs);
CO_Boolean CO_setBooleanWsAfterLhs(CO_Boolean arg, CO_OptLayout wsAfterLhs);
CO_Boolean CO_setBooleanWsAfterBar(CO_Boolean arg, CO_OptLayout wsAfterBar);
CO_Boolean CO_setBooleanRhs(CO_Boolean arg, CO_Boolean rhs);
CO_Boolean CO_setBooleanWsAfterAmp(CO_Boolean arg, CO_OptLayout wsAfterAmp);
CO_Boolean CO_setBooleanWsAfterNot(CO_Boolean arg, CO_OptLayout wsAfterNot);
CO_Boolean CO_setBooleanWsAfterParenOpen(CO_Boolean arg, CO_OptLayout wsAfterParenOpen);
CO_Boolean CO_setBooleanBoolean(CO_Boolean arg, CO_Boolean Boolean);
CO_Boolean CO_setBooleanWsAfterBoolean(CO_Boolean arg, CO_OptLayout wsAfterBoolean);
CO_OptLayout CO_visitOptLayout(CO_OptLayout arg, CO_Layout (*acceptLayout)(CO_Layout));
CO_Layout CO_visitLayout(CO_Layout arg, CO_LexLayoutList (*acceptList)(CO_LexLayoutList));
CO_LexLayoutList CO_visitLexLayoutList(CO_LexLayoutList arg, CO_LexLayout (*acceptHead)(CO_LexLayout));
CO_LexLayout CO_visitLexLayout(CO_LexLayout arg, char (*acceptCh)(char));
CO_Start CO_visitStart(CO_Start arg, CO_OptLayout (*acceptWsBefore)(CO_OptLayout), CO_StrCon (*acceptTopStrCon)(CO_StrCon), CO_OptLayout (*acceptWsAfter)(CO_OptLayout), int (*acceptAmbCnt)(int), CO_BoolCon (*acceptTopBoolCon)(CO_BoolCon), CO_Summary (*acceptTopSummary)(CO_Summary), CO_Error (*acceptTopError)(CO_Error), CO_Boolean (*acceptTopBoolean)(CO_Boolean));
CO_LexStrChar CO_visitLexStrChar(CO_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char));
CO_StrChar CO_visitStrChar(CO_StrChar arg, CO_LexStrChar (*acceptStrChar)(CO_LexStrChar));
CO_LexStrCon CO_visitLexStrCon(CO_LexStrCon arg, CO_LexStrCharChars (*acceptChars)(CO_LexStrCharChars));
CO_StrCon CO_visitStrCon(CO_StrCon arg, CO_LexStrCon (*acceptStrCon)(CO_LexStrCon));
CO_LexStrCharChars CO_visitLexStrCharChars(CO_LexStrCharChars arg, CO_LexStrChar (*acceptHead)(CO_LexStrChar));
CO_BoolCon CO_visitBoolCon(CO_BoolCon arg);
CO_LexNatCon CO_visitLexNatCon(CO_LexNatCon arg, char* (*acceptList)(char*));
CO_NatCon CO_visitNatCon(CO_NatCon arg, CO_LexNatCon (*acceptNatCon)(CO_LexNatCon));
CO_LexByte CO_visitLexByte(CO_LexByte arg, char (*acceptCh)(char));
CO_Byte CO_visitByte(CO_Byte arg, CO_LexByte (*acceptByte)(CO_LexByte));
CO_LexBytes CO_visitLexBytes(CO_LexBytes arg, CO_LexByteList (*acceptList)(CO_LexByteList));
CO_Bytes CO_visitBytes(CO_Bytes arg, CO_LexBytes (*acceptBytes)(CO_LexBytes));
CO_LexByteList CO_visitLexByteList(CO_LexByteList arg, CO_LexByte (*acceptHead)(CO_LexByte));
CO_Subject CO_visitSubject(CO_Subject arg, CO_OptLayout (*acceptWsAfterSubject)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptDescription)(CO_StrCon), CO_OptLayout (*acceptWsAfterDescription)(CO_OptLayout), CO_OptLayout (*acceptWsAfterLocalized)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_Location (*acceptLocation)(CO_Location), CO_OptLayout (*acceptWsAfterLocation)(CO_OptLayout));
CO_Error CO_visitError(CO_Error arg, CO_OptLayout (*acceptWsAfterInfo)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptDescription)(CO_StrCon), CO_OptLayout (*acceptWsAfterDescription)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketOpen)(CO_OptLayout), CO_SubjectList (*acceptList)(CO_SubjectList), CO_OptLayout (*acceptWsAfterList)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketClose)(CO_OptLayout), CO_OptLayout (*acceptWsAfterWarning)(CO_OptLayout), CO_OptLayout (*acceptWsAfterError)(CO_OptLayout), CO_OptLayout (*acceptWsAfterFatal)(CO_OptLayout));
CO_Summary CO_visitSummary(CO_Summary arg, CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptProducer)(CO_StrCon), CO_OptLayout (*acceptWsAfterProducer)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_StrCon (*acceptId)(CO_StrCon), CO_OptLayout (*acceptWsAfterId)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketOpen)(CO_OptLayout), CO_ErrorList (*acceptList)(CO_ErrorList), CO_OptLayout (*acceptWsAfterList)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketClose)(CO_OptLayout));
CO_SubjectList CO_visitSubjectList(CO_SubjectList arg, CO_Subject (*acceptHead)(CO_Subject), CO_OptLayout (*acceptWsAfterHead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterSep)(CO_OptLayout));
CO_ErrorList CO_visitErrorList(CO_ErrorList arg, CO_Error (*acceptHead)(CO_Error), CO_OptLayout (*acceptWsAfterHead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterSep)(CO_OptLayout));
CO_Location CO_visitLocation(CO_Location arg, CO_OptLayout (*acceptWsAfterFile)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptFilename)(CO_StrCon), CO_OptLayout (*acceptWsAfterFilename)(CO_OptLayout), CO_OptLayout (*acceptWsAfterA)(CO_OptLayout), CO_Area (*acceptArea)(CO_Area), CO_OptLayout (*acceptWsAfterArea)(CO_OptLayout), CO_OptLayout (*acceptWsAfterAreaInFile)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout));
CO_Area CO_visitArea(CO_Area arg, CO_OptLayout (*acceptWsAfterArea)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_NatCon (*acceptBeginLine)(CO_NatCon), CO_OptLayout (*acceptWsAfterBeginLine)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_NatCon (*acceptBeginColumn)(CO_NatCon), CO_OptLayout (*acceptWsAfterBeginColumn)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_NatCon (*acceptEndLine)(CO_NatCon), CO_OptLayout (*acceptWsAfterEndLine)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma2)(CO_OptLayout), CO_NatCon (*acceptEndColumn)(CO_NatCon), CO_OptLayout (*acceptWsAfterEndColumn)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma3)(CO_OptLayout), CO_NatCon (*acceptOffset)(CO_NatCon), CO_OptLayout (*acceptWsAfterOffset)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma4)(CO_OptLayout), CO_NatCon (*acceptLength)(CO_NatCon), CO_OptLayout (*acceptWsAfterLength)(CO_OptLayout));
CO_Read CO_visitRead(CO_Read arg, CO_OptLayout (*acceptWsAfterRead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Bytes (*acceptValue)(CO_Bytes), CO_OptLayout (*acceptWsAfterValue)(CO_OptLayout), CO_OptLayout (*acceptWsAfterReadError)(CO_OptLayout), CO_Summary (*acceptSummary)(CO_Summary), CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout));
CO_Write CO_visitWrite(CO_Write arg, CO_OptLayout (*acceptWsAfterWriteError)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Summary (*acceptSummary)(CO_Summary), CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout));
CO_ParsetreeX CO_visitParsetreeX(CO_ParsetreeX arg, ATerm (*acceptTypeOfTree)(ATerm), ATerm (*acceptTypeOfX)(ATerm), CO_OptLayout (*acceptWsAfterParseTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Bytes (*acceptLeftLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterLeftLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_X (*acceptTree)(CO_X), CO_OptLayout (*acceptWsAfterTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_Bytes (*acceptRightLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterRightLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma2)(CO_OptLayout), CO_NatCon (*acceptAmbCnt)(CO_NatCon), CO_OptLayout (*acceptWsAfterAmbCnt)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParseError)(CO_OptLayout), CO_Summary (*acceptSummary)(CO_Summary), CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout));
CO_X CO_visitX(CO_X arg, ATerm (*acceptX)(ATerm));
CO_Boolean CO_visitBoolean(CO_Boolean arg, CO_BoolCon (*acceptBoolCon)(CO_BoolCon), CO_OptLayout (*acceptWsAfterLhs)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBar)(CO_OptLayout), CO_OptLayout (*acceptWsAfterAmp)(CO_OptLayout), CO_OptLayout (*acceptWsAfterNot)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBoolean)(CO_OptLayout));

#endif /* _LIBRARY_H */
