#ifndef _TA_H
#define _TA_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "TA_dict.h"

typedef struct _TA_Location *TA_Location;
typedef struct _TA_Port *TA_Port;

#ifdef FAST_API
#define TA_initTAApi() (init_TA_dict())
#else
void _TA_initTAApi(void);
#define TA_initTAApi() (_TA_initTAApi())
#endif

#ifdef FAST_API
#define TA_protectLocation(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _TA_protectLocation(TA_Location *arg);
#define TA_protectLocation(arg) (_TA_protectLocation(arg))
#endif
#ifdef FAST_API
#define TA_unprotectLocation(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _TA_unprotectLocation(TA_Location *arg);
#define TA_unprotectLocation(arg) (_TA_unprotectLocation(arg))
#endif
#ifdef FAST_API
#define TA_protectPort(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _TA_protectPort(TA_Port *arg);
#define TA_protectPort(arg) (_TA_protectPort(arg))
#endif
#ifdef FAST_API
#define TA_unprotectPort(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _TA_unprotectPort(TA_Port *arg);
#define TA_unprotectPort(arg) (_TA_unprotectPort(arg))
#endif
#ifdef FAST_API
#define TA_LocationFromTerm(t) ((TA_Location)(t))
#else
TA_Location _TA_LocationFromTerm(ATerm t);
#define TA_LocationFromTerm(t) (_TA_LocationFromTerm(t))
#endif
#ifdef FAST_API
#define TA_LocationToTerm(arg) ((ATerm)(arg))
#else
ATerm _TA_LocationToTerm(TA_Location arg);
#define TA_LocationToTerm(arg) (_TA_LocationToTerm(arg))
#endif
#ifdef FAST_API
#define TA_PortFromTerm(t) ((TA_Port)(t))
#else
TA_Port _TA_PortFromTerm(ATerm t);
#define TA_PortFromTerm(t) (_TA_PortFromTerm(t))
#endif
#ifdef FAST_API
#define TA_PortToTerm(arg) ((ATerm)(arg))
#else
ATerm _TA_PortToTerm(TA_Port arg);
#define TA_PortToTerm(arg) (_TA_PortToTerm(arg))
#endif
TA_Location TA_makeLocationLine(const char* file, int line);
TA_Location TA_makeLocationArea(const char* file, int startLine, int startCol, int endLine, int endCol, int offset, int length);
TA_Location TA_makeLocationLineCol(const char* file, int line, int col);
TA_Location TA_makeLocationUnknown(void);
TA_Port TA_makePortStep(void);
TA_Port TA_makePortStopped(void);
TA_Port TA_makePortStarted(void);
#ifdef FAST_API
#define TA_isEqualLocation(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _TA_isEqualLocation(TA_Location arg0, TA_Location arg1);
#define TA_isEqualLocation(arg0, arg1) (_TA_isEqualLocation(arg0, arg1))
#endif
#ifdef FAST_API
#define TA_isEqualPort(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _TA_isEqualPort(TA_Port arg0, TA_Port arg1);
#define TA_isEqualPort(arg0, arg1) (_TA_isEqualPort(arg0, arg1))
#endif
ATbool TA_isValidLocation(TA_Location arg);
inline ATbool TA_isLocationLine(TA_Location arg);
inline ATbool TA_isLocationArea(TA_Location arg);
inline ATbool TA_isLocationLineCol(TA_Location arg);
inline ATbool TA_isLocationUnknown(TA_Location arg);
ATbool TA_hasLocationFile(TA_Location arg);
ATbool TA_hasLocationLine(TA_Location arg);
ATbool TA_hasLocationStartLine(TA_Location arg);
ATbool TA_hasLocationStartCol(TA_Location arg);
ATbool TA_hasLocationEndLine(TA_Location arg);
ATbool TA_hasLocationEndCol(TA_Location arg);
ATbool TA_hasLocationOffset(TA_Location arg);
ATbool TA_hasLocationLength(TA_Location arg);
ATbool TA_hasLocationCol(TA_Location arg);
char* TA_getLocationFile(TA_Location arg);
int TA_getLocationLine(TA_Location arg);
int TA_getLocationStartLine(TA_Location arg);
int TA_getLocationStartCol(TA_Location arg);
int TA_getLocationEndLine(TA_Location arg);
int TA_getLocationEndCol(TA_Location arg);
int TA_getLocationOffset(TA_Location arg);
int TA_getLocationLength(TA_Location arg);
int TA_getLocationCol(TA_Location arg);
TA_Location TA_setLocationFile(TA_Location arg, const char* file);
TA_Location TA_setLocationLine(TA_Location arg, int line);
TA_Location TA_setLocationStartLine(TA_Location arg, int startLine);
TA_Location TA_setLocationStartCol(TA_Location arg, int startCol);
TA_Location TA_setLocationEndLine(TA_Location arg, int endLine);
TA_Location TA_setLocationEndCol(TA_Location arg, int endCol);
TA_Location TA_setLocationOffset(TA_Location arg, int offset);
TA_Location TA_setLocationLength(TA_Location arg, int length);
TA_Location TA_setLocationCol(TA_Location arg, int col);
ATbool TA_isValidPort(TA_Port arg);
inline ATbool TA_isPortStep(TA_Port arg);
inline ATbool TA_isPortStopped(TA_Port arg);
inline ATbool TA_isPortStarted(TA_Port arg);
TA_Location TA_visitLocation(TA_Location arg, char* (*acceptFile)(char*), int (*acceptLine)(int), int (*acceptStartLine)(int), int (*acceptStartCol)(int), int (*acceptEndLine)(int), int (*acceptEndCol)(int), int (*acceptOffset)(int), int (*acceptLength)(int), int (*acceptCol)(int));
TA_Port TA_visitPort(TA_Port arg);

#endif /* _TA_H */
