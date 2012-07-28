#ifndef _STRUCTUREEDITOR_H
#define _STRUCTUREEDITOR_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "StructureEditor_dict.h"

#include <MEPT.h>

typedef PT_Tree SE_Tree;
typedef PT_ParseTree SE_ParseTree;
typedef struct _SE_Direction *SE_Direction;
typedef struct _SE_StructureEditor *SE_StructureEditor;

#ifdef FAST_API
#define SE_initStructureEditorApi() (init_StructureEditor_dict())
#else
void _SE_initStructureEditorApi(void);
#define SE_initStructureEditorApi() (_SE_initStructureEditorApi())
#endif

#ifdef FAST_API
#define SE_protectDirection(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _SE_protectDirection(SE_Direction *arg);
#define SE_protectDirection(arg) (_SE_protectDirection(arg))
#endif
#ifdef FAST_API
#define SE_unprotectDirection(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _SE_unprotectDirection(SE_Direction *arg);
#define SE_unprotectDirection(arg) (_SE_unprotectDirection(arg))
#endif
#ifdef FAST_API
#define SE_protectStructureEditor(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _SE_protectStructureEditor(SE_StructureEditor *arg);
#define SE_protectStructureEditor(arg) (_SE_protectStructureEditor(arg))
#endif
#ifdef FAST_API
#define SE_unprotectStructureEditor(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _SE_unprotectStructureEditor(SE_StructureEditor *arg);
#define SE_unprotectStructureEditor(arg) (_SE_unprotectStructureEditor(arg))
#endif
#ifdef FAST_API
#define SE_DirectionFromTerm(t) ((SE_Direction)(t))
#else
SE_Direction _SE_DirectionFromTerm(ATerm t);
#define SE_DirectionFromTerm(t) (_SE_DirectionFromTerm(t))
#endif
#ifdef FAST_API
#define SE_DirectionToTerm(arg) ((ATerm)(arg))
#else
ATerm _SE_DirectionToTerm(SE_Direction arg);
#define SE_DirectionToTerm(arg) (_SE_DirectionToTerm(arg))
#endif
#ifdef FAST_API
#define SE_StructureEditorFromTerm(t) ((SE_StructureEditor)(t))
#else
SE_StructureEditor _SE_StructureEditorFromTerm(ATerm t);
#define SE_StructureEditorFromTerm(t) (_SE_StructureEditorFromTerm(t))
#endif
#ifdef FAST_API
#define SE_StructureEditorToTerm(arg) ((ATerm)(arg))
#else
ATerm _SE_StructureEditorToTerm(SE_StructureEditor arg);
#define SE_StructureEditorToTerm(arg) (_SE_StructureEditorToTerm(arg))
#endif
SE_Direction SE_makeDirectionUp(void);
SE_Direction SE_makeDirectionLeft(void);
SE_Direction SE_makeDirectionDown(void);
SE_Direction SE_makeDirectionRight(void);
SE_StructureEditor SE_makeStructureEditorDefault(SE_ParseTree parseTree, SE_Tree cursor);
SE_StructureEditor SE_makeStructureEditorUnedited(SE_ParseTree parseTree);
#ifdef FAST_API
#define SE_isEqualDirection(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _SE_isEqualDirection(SE_Direction arg0, SE_Direction arg1);
#define SE_isEqualDirection(arg0, arg1) (_SE_isEqualDirection(arg0, arg1))
#endif
#ifdef FAST_API
#define SE_isEqualStructureEditor(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _SE_isEqualStructureEditor(SE_StructureEditor arg0, SE_StructureEditor arg1);
#define SE_isEqualStructureEditor(arg0, arg1) (_SE_isEqualStructureEditor(arg0, arg1))
#endif
ATbool SE_isValidDirection(SE_Direction arg);
inline ATbool SE_isDirectionUp(SE_Direction arg);
inline ATbool SE_isDirectionLeft(SE_Direction arg);
inline ATbool SE_isDirectionDown(SE_Direction arg);
inline ATbool SE_isDirectionRight(SE_Direction arg);
ATbool SE_isValidStructureEditor(SE_StructureEditor arg);
inline ATbool SE_isStructureEditorDefault(SE_StructureEditor arg);
inline ATbool SE_isStructureEditorUnedited(SE_StructureEditor arg);
ATbool SE_hasStructureEditorParseTree(SE_StructureEditor arg);
ATbool SE_hasStructureEditorCursor(SE_StructureEditor arg);
SE_ParseTree SE_getStructureEditorParseTree(SE_StructureEditor arg);
SE_Tree SE_getStructureEditorCursor(SE_StructureEditor arg);
SE_StructureEditor SE_setStructureEditorParseTree(SE_StructureEditor arg, SE_ParseTree parseTree);
SE_StructureEditor SE_setStructureEditorCursor(SE_StructureEditor arg, SE_Tree cursor);
SE_Direction SE_visitDirection(SE_Direction arg);
SE_StructureEditor SE_visitStructureEditor(SE_StructureEditor arg, SE_ParseTree (*acceptParseTree)(SE_ParseTree), SE_Tree (*acceptCursor)(SE_Tree));

#endif /* _STRUCTUREEDITOR_H */
