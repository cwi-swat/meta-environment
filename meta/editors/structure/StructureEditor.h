#ifndef _STRUCTUREEDITOR_H
#define _STRUCTUREEDITOR_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "StructureEditor_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _SE_Area *SE_Area;
typedef struct _SE_Location *SE_Location;
typedef struct _SE_Direction *SE_Direction;

/*}}}  */

void SE_initStructureEditorApi(void);

/*{{{  protect functions */

void SE_protectArea(SE_Area *arg);
void SE_protectLocation(SE_Location *arg);
void SE_protectDirection(SE_Direction *arg);

/*}}}  */
/*{{{  term conversion functions */

SE_Area SE_AreaFromTerm(ATerm t);
ATerm SE_AreaToTerm(SE_Area arg);
SE_Location SE_LocationFromTerm(ATerm t);
ATerm SE_LocationToTerm(SE_Location arg);
SE_Direction SE_DirectionFromTerm(ATerm t);
ATerm SE_DirectionToTerm(SE_Direction arg);

/*}}}  */
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */

SE_Area SE_makeAreaArea(int beginLine, int beginColumn, int endLine, int endColumn, int offset, int length);
SE_Location SE_makeLocationFile(const char* filename);
SE_Location SE_makeLocationAreaInFile(const char* filename, SE_Area Area);
SE_Direction SE_makeDirectionUp();
SE_Direction SE_makeDirectionLeft();
SE_Direction SE_makeDirectionDown();
SE_Direction SE_makeDirectionRight();

/*}}}  */
/*{{{  equality functions */

ATbool SE_isEqualArea(SE_Area arg0, SE_Area arg1);
ATbool SE_isEqualLocation(SE_Location arg0, SE_Location arg1);
ATbool SE_isEqualDirection(SE_Direction arg0, SE_Direction arg1);

/*}}}  */
/*{{{  SE_Area accessors */

ATbool SE_isValidArea(SE_Area arg);
inline ATbool SE_isAreaArea(SE_Area arg);
ATbool SE_hasAreaBeginLine(SE_Area arg);
int SE_getAreaBeginLine(SE_Area arg);
SE_Area SE_setAreaBeginLine(SE_Area arg, int beginLine);
ATbool SE_hasAreaBeginColumn(SE_Area arg);
int SE_getAreaBeginColumn(SE_Area arg);
SE_Area SE_setAreaBeginColumn(SE_Area arg, int beginColumn);
ATbool SE_hasAreaEndLine(SE_Area arg);
int SE_getAreaEndLine(SE_Area arg);
SE_Area SE_setAreaEndLine(SE_Area arg, int endLine);
ATbool SE_hasAreaEndColumn(SE_Area arg);
int SE_getAreaEndColumn(SE_Area arg);
SE_Area SE_setAreaEndColumn(SE_Area arg, int endColumn);
ATbool SE_hasAreaOffset(SE_Area arg);
int SE_getAreaOffset(SE_Area arg);
SE_Area SE_setAreaOffset(SE_Area arg, int offset);
ATbool SE_hasAreaLength(SE_Area arg);
int SE_getAreaLength(SE_Area arg);
SE_Area SE_setAreaLength(SE_Area arg, int length);

/*}}}  */
/*{{{  SE_Location accessors */

ATbool SE_isValidLocation(SE_Location arg);
inline ATbool SE_isLocationFile(SE_Location arg);
inline ATbool SE_isLocationAreaInFile(SE_Location arg);
ATbool SE_hasLocationFilename(SE_Location arg);
char* SE_getLocationFilename(SE_Location arg);
SE_Location SE_setLocationFilename(SE_Location arg, const char* filename);
ATbool SE_hasLocationArea(SE_Location arg);
SE_Area SE_getLocationArea(SE_Location arg);
SE_Location SE_setLocationArea(SE_Location arg, SE_Area Area);

/*}}}  */
/*{{{  SE_Direction accessors */

ATbool SE_isValidDirection(SE_Direction arg);
inline ATbool SE_isDirectionUp(SE_Direction arg);
inline ATbool SE_isDirectionLeft(SE_Direction arg);
inline ATbool SE_isDirectionDown(SE_Direction arg);
inline ATbool SE_isDirectionRight(SE_Direction arg);

/*}}}  */
/*{{{  sort visitors */

SE_Area SE_visitArea(SE_Area arg, int (*acceptBeginLine)(int), int (*acceptBeginColumn)(int), int (*acceptEndLine)(int), int (*acceptEndColumn)(int), int (*acceptOffset)(int), int (*acceptLength)(int));
SE_Location SE_visitLocation(SE_Location arg, char* (*acceptFilename)(char*), SE_Area (*acceptArea)(SE_Area));
SE_Direction SE_visitDirection(SE_Direction arg);

/*}}}  */

#endif /* _STRUCTUREEDITOR_H */
