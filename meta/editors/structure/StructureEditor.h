#ifndef _STRUCTUREEDITOR_H
#define _STRUCTUREEDITOR_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "StructureEditor_dict.h"

/*}}}  */

/*{{{  prologue */

#include <MEPT.h>

typedef PT_Tree SE_Tree;
typedef PT_ParseTree SE_ParseTree;

/*}}}  */
/*{{{  typedefs */

typedef struct _SE_Direction *SE_Direction;
typedef struct _SE_StructureEditor *SE_StructureEditor;

/*}}}  */

void SE_initStructureEditorApi(void);

/*{{{  protect functions */

void SE_protectDirection(SE_Direction *arg);
void SE_protectStructureEditor(SE_StructureEditor *arg);

/*}}}  */
/*{{{  term conversion functions */

SE_Direction SE_DirectionFromTerm(ATerm t);
ATerm SE_DirectionToTerm(SE_Direction arg);
SE_StructureEditor SE_StructureEditorFromTerm(ATerm t);
ATerm SE_StructureEditorToTerm(SE_StructureEditor arg);

/*}}}  */
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */

SE_Direction SE_makeDirectionUp();
SE_Direction SE_makeDirectionLeft();
SE_Direction SE_makeDirectionDown();
SE_Direction SE_makeDirectionRight();
SE_StructureEditor SE_makeStructureEditorDefault(SE_ParseTree parseTree, SE_Tree cursor);
SE_StructureEditor SE_makeStructureEditorUnedited(SE_ParseTree parseTree);

/*}}}  */
/*{{{  equality functions */

ATbool SE_isEqualDirection(SE_Direction arg0, SE_Direction arg1);
ATbool SE_isEqualStructureEditor(SE_StructureEditor arg0, SE_StructureEditor arg1);

/*}}}  */
/*{{{  SE_Direction accessors */

ATbool SE_isValidDirection(SE_Direction arg);
inline ATbool SE_isDirectionUp(SE_Direction arg);
inline ATbool SE_isDirectionLeft(SE_Direction arg);
inline ATbool SE_isDirectionDown(SE_Direction arg);
inline ATbool SE_isDirectionRight(SE_Direction arg);

/*}}}  */
/*{{{  SE_StructureEditor accessors */

ATbool SE_isValidStructureEditor(SE_StructureEditor arg);
inline ATbool SE_isStructureEditorDefault(SE_StructureEditor arg);
inline ATbool SE_isStructureEditorUnedited(SE_StructureEditor arg);
ATbool SE_hasStructureEditorParseTree(SE_StructureEditor arg);
SE_ParseTree SE_getStructureEditorParseTree(SE_StructureEditor arg);
SE_StructureEditor SE_setStructureEditorParseTree(SE_StructureEditor arg, SE_ParseTree parseTree);
ATbool SE_hasStructureEditorCursor(SE_StructureEditor arg);
SE_Tree SE_getStructureEditorCursor(SE_StructureEditor arg);
SE_StructureEditor SE_setStructureEditorCursor(SE_StructureEditor arg, SE_Tree cursor);

/*}}}  */
/*{{{  sort visitors */

SE_Direction SE_visitDirection(SE_Direction arg);
SE_StructureEditor SE_visitStructureEditor(SE_StructureEditor arg, SE_ParseTree (*acceptParseTree)(SE_ParseTree), SE_Tree (*acceptCursor)(SE_Tree));

/*}}}  */

#endif /* _STRUCTUREEDITOR_H */
