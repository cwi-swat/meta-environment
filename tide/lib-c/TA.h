#ifndef _TA_H
#define _TA_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "TA_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _TA_Location *TA_Location;
typedef struct _TA_Port *TA_Port;

/*}}}  */

void TA_initTAApi(void);

/*{{{  protect functions */

void TA_protectLocation(TA_Location *arg);
void TA_protectPort(TA_Port *arg);

/*}}}  */
/*{{{  term conversion functions */

TA_Location TA_LocationFromTerm(ATerm t);
ATerm TA_LocationToTerm(TA_Location arg);
TA_Port TA_PortFromTerm(ATerm t);
ATerm TA_PortToTerm(TA_Port arg);

/*}}}  */
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */

TA_Location TA_makeLocationLine(const char* file, int line);
TA_Location TA_makeLocationArea(const char* file, int startLine, int startCol, int endLine, int endCol, int offset, int length);
TA_Location TA_makeLocationLineCol(const char* file, int line, int col);
TA_Location TA_makeLocationUnknown(void);
TA_Port TA_makePortStep(void);
TA_Port TA_makePortStopped(void);
TA_Port TA_makePortStarted(void);

/*}}}  */
/*{{{  equality functions */

ATbool TA_isEqualLocation(TA_Location arg0, TA_Location arg1);
ATbool TA_isEqualPort(TA_Port arg0, TA_Port arg1);

/*}}}  */
/*{{{  TA_Location accessors */

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

/*}}}  */
/*{{{  TA_Port accessors */

ATbool TA_isValidPort(TA_Port arg);
inline ATbool TA_isPortStep(TA_Port arg);
inline ATbool TA_isPortStopped(TA_Port arg);
inline ATbool TA_isPortStarted(TA_Port arg);

/*}}}  */
/*{{{  sort visitors */

TA_Location TA_visitLocation(TA_Location arg, char* (*acceptFile)(char*), int (*acceptLine)(int), int (*acceptStartLine)(int), int (*acceptStartCol)(int), int (*acceptEndLine)(int), int (*acceptEndCol)(int), int (*acceptOffset)(int), int (*acceptLength)(int), int (*acceptCol)(int));
TA_Port TA_visitPort(TA_Port arg);

/*}}}  */

#endif /* _TA_H */
