#ifndef _TA_H
#define _TA_H

/*{{{  includes */

#include <aterm1.h>
#include "TA_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _TA_Location *TA_Location;
typedef struct _TA_Port *TA_Port;

/*}}}  */

void TA_initTAApi(void);

/*{{{  term conversion functions */

TA_Location TA_LocationFromTerm(ATerm t);
ATerm TA_LocationToTerm(TA_Location arg);
TA_Port TA_PortFromTerm(ATerm t);
ATerm TA_PortToTerm(TA_Port arg);

/*}}}  */
/*{{{  constructors */

TA_Location TA_makeLocationLine(char * file, int line);
TA_Location TA_makeLocationArea(char * file, int startLine, int startCol, int endLine, int endCol);
TA_Location TA_makeLocationLineCol(char * file, int line, int col);
TA_Location TA_makeLocationUnknown();
TA_Port TA_makePortStep();
TA_Port TA_makePortStopped();
TA_Port TA_makePortStarted();

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
char * TA_getLocationFile(TA_Location arg);
TA_Location TA_setLocationFile(TA_Location arg, char * file);
ATbool TA_hasLocationLine(TA_Location arg);
int TA_getLocationLine(TA_Location arg);
TA_Location TA_setLocationLine(TA_Location arg, int line);
ATbool TA_hasLocationStartLine(TA_Location arg);
int TA_getLocationStartLine(TA_Location arg);
TA_Location TA_setLocationStartLine(TA_Location arg, int startLine);
ATbool TA_hasLocationStartCol(TA_Location arg);
int TA_getLocationStartCol(TA_Location arg);
TA_Location TA_setLocationStartCol(TA_Location arg, int startCol);
ATbool TA_hasLocationEndLine(TA_Location arg);
int TA_getLocationEndLine(TA_Location arg);
TA_Location TA_setLocationEndLine(TA_Location arg, int endLine);
ATbool TA_hasLocationEndCol(TA_Location arg);
int TA_getLocationEndCol(TA_Location arg);
TA_Location TA_setLocationEndCol(TA_Location arg, int endCol);
ATbool TA_hasLocationCol(TA_Location arg);
int TA_getLocationCol(TA_Location arg);
TA_Location TA_setLocationCol(TA_Location arg, int col);

/*}}}  */
/*{{{  TA_Port accessors */

ATbool TA_isValidPort(TA_Port arg);
inline ATbool TA_isPortStep(TA_Port arg);
inline ATbool TA_isPortStopped(TA_Port arg);
inline ATbool TA_isPortStarted(TA_Port arg);

/*}}}  */
/*{{{  sort visitors */

TA_Location TA_visitLocation(TA_Location arg, char * (*acceptFile)(char *), int (*acceptLine)(int), int (*acceptStartLine)(int), int (*acceptStartCol)(int), int (*acceptEndLine)(int), int (*acceptEndCol)(int), int (*acceptCol)(int));
TA_Port TA_visitPort(TA_Port arg);

/*}}}  */

#endif /* _TA_H */
