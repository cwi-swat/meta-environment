#include <aterm2.h>
#include <deprecated.h>
#include "Editor.h"

/*{{{  typedefs */

typedef struct ATerm _SE_Editor;
typedef struct ATerm _SE_Focus;
typedef struct ATerm _SE_Area;
typedef struct ATerm _SE_FocusList;
typedef struct ATerm _SE_SymbolList;
typedef struct ATerm _SE_Path;
typedef struct ATerm _SE_Steps;
typedef struct ATerm _SE_Move;

/*}}}  */

/*{{{  void SE_initEditorApi(void) */

void SE_initEditorApi(void)
{
  init_Editor_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  SE_Editor SE_makeEditorFromTerm(ATerm t) */

SE_Editor SE_makeEditorFromTerm(ATerm t)
{
  return (SE_Editor)t;
}

/*}}}  */
/*{{{  ATerm SE_makeTermFromEditor(SE_Editor arg) */

ATerm SE_makeTermFromEditor(SE_Editor arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SE_Focus SE_makeFocusFromTerm(ATerm t) */

SE_Focus SE_makeFocusFromTerm(ATerm t)
{
  return (SE_Focus)t;
}

/*}}}  */
/*{{{  ATerm SE_makeTermFromFocus(SE_Focus arg) */

ATerm SE_makeTermFromFocus(SE_Focus arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SE_Area SE_makeAreaFromTerm(ATerm t) */

SE_Area SE_makeAreaFromTerm(ATerm t)
{
  return (SE_Area)t;
}

/*}}}  */
/*{{{  ATerm SE_makeTermFromArea(SE_Area arg) */

ATerm SE_makeTermFromArea(SE_Area arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SE_FocusList SE_makeFocusListFromTerm(ATerm t) */

SE_FocusList SE_makeFocusListFromTerm(ATerm t)
{
  return (SE_FocusList)t;
}

/*}}}  */
/*{{{  ATerm SE_makeTermFromFocusList(SE_FocusList arg) */

ATerm SE_makeTermFromFocusList(SE_FocusList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SE_SymbolList SE_makeSymbolListFromTerm(ATerm t) */

SE_SymbolList SE_makeSymbolListFromTerm(ATerm t)
{
  return (SE_SymbolList)t;
}

/*}}}  */
/*{{{  ATerm SE_makeTermFromSymbolList(SE_SymbolList arg) */

ATerm SE_makeTermFromSymbolList(SE_SymbolList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SE_Path SE_makePathFromTerm(ATerm t) */

SE_Path SE_makePathFromTerm(ATerm t)
{
  return (SE_Path)t;
}

/*}}}  */
/*{{{  ATerm SE_makeTermFromPath(SE_Path arg) */

ATerm SE_makeTermFromPath(SE_Path arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SE_Steps SE_makeStepsFromTerm(ATerm t) */

SE_Steps SE_makeStepsFromTerm(ATerm t)
{
  return (SE_Steps)t;
}

/*}}}  */
/*{{{  ATerm SE_makeTermFromSteps(SE_Steps arg) */

ATerm SE_makeTermFromSteps(SE_Steps arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SE_Move SE_makeMoveFromTerm(ATerm t) */

SE_Move SE_makeMoveFromTerm(ATerm t)
{
  return (SE_Move)t;
}

/*}}}  */
/*{{{  ATerm SE_makeTermFromMove(SE_Move arg) */

ATerm SE_makeTermFromMove(SE_Move arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  SE_Editor SE_makeEditorDefault(SE_ParseTree parseTree, SE_Focus focus, SE_FocusList dirtyFoci, SE_SymbolList startSymbols) */

SE_Editor SE_makeEditorDefault(SE_ParseTree parseTree, SE_Focus focus, SE_FocusList dirtyFoci, SE_SymbolList startSymbols)
{
  return (SE_Editor)ATmakeTerm(SE_patternEditorDefault, parseTree, focus, dirtyFoci, startSymbols);
}

/*}}}  */
/*{{{  SE_Focus SE_makeFocusEmpty() */

SE_Focus SE_makeFocusEmpty()
{
  return (SE_Focus)ATmakeTerm(SE_patternFocusEmpty);
}

/*}}}  */
/*{{{  SE_Focus SE_makeFocusNotEmpty(SE_Path path, char * sort, SE_Area area, int dirty) */

SE_Focus SE_makeFocusNotEmpty(SE_Path path, char * sort, SE_Area area, int dirty)
{
  return (SE_Focus)ATmakeTerm(SE_patternFocusNotEmpty, path, sort, area, dirty);
}

/*}}}  */
/*{{{  SE_Area SE_makeAreaDefault(int start, int length) */

SE_Area SE_makeAreaDefault(int start, int length)
{
  return (SE_Area)ATmakeTerm(SE_patternAreaDefault, start, length);
}

/*}}}  */
/*{{{  SE_FocusList SE_makeFocusListEmpty() */

SE_FocusList SE_makeFocusListEmpty()
{
  return (SE_FocusList)ATmakeTerm(SE_patternFocusListEmpty);
}

/*}}}  */
/*{{{  SE_FocusList SE_makeFocusListMulti(SE_Focus head, SE_FocusList tail) */

SE_FocusList SE_makeFocusListMulti(SE_Focus head, SE_FocusList tail)
{
  return (SE_FocusList)ATmakeTerm(SE_patternFocusListMulti, head, tail);
}

/*}}}  */
/*{{{  SE_SymbolList SE_makeSymbolListEmpty() */

SE_SymbolList SE_makeSymbolListEmpty()
{
  return (SE_SymbolList)ATmakeTerm(SE_patternSymbolListEmpty);
}

/*}}}  */
/*{{{  SE_SymbolList SE_makeSymbolListMulti(char * head, SE_SymbolList tail) */

SE_SymbolList SE_makeSymbolListMulti(char * head, SE_SymbolList tail)
{
  return (SE_SymbolList)ATmakeTerm(SE_patternSymbolListMulti, head, tail);
}

/*}}}  */
/*{{{  SE_Path SE_makePathRoot() */

SE_Path SE_makePathRoot()
{
  return (SE_Path)ATmakeTerm(SE_patternPathRoot);
}

/*}}}  */
/*{{{  SE_Path SE_makePathLeftLayout() */

SE_Path SE_makePathLeftLayout()
{
  return (SE_Path)ATmakeTerm(SE_patternPathLeftLayout);
}

/*}}}  */
/*{{{  SE_Path SE_makePathTerm(SE_Steps steps) */

SE_Path SE_makePathTerm(SE_Steps steps)
{
  return (SE_Path)ATmakeTerm(SE_patternPathTerm, steps);
}

/*}}}  */
/*{{{  SE_Path SE_makePathRightLayout() */

SE_Path SE_makePathRightLayout()
{
  return (SE_Path)ATmakeTerm(SE_patternPathRightLayout);
}

/*}}}  */
/*{{{  SE_Steps SE_makeStepsEmpty() */

SE_Steps SE_makeStepsEmpty()
{
  return (SE_Steps)ATmakeTerm(SE_patternStepsEmpty);
}

/*}}}  */
/*{{{  SE_Steps SE_makeStepsMulti(int head, SE_Steps tail) */

SE_Steps SE_makeStepsMulti(int head, SE_Steps tail)
{
  return (SE_Steps)ATmakeTerm(SE_patternStepsMulti, head, tail);
}

/*}}}  */
/*{{{  SE_Move SE_makeMoveLeft() */

SE_Move SE_makeMoveLeft()
{
  return (SE_Move)ATmakeTerm(SE_patternMoveLeft);
}

/*}}}  */
/*{{{  SE_Move SE_makeMoveRight() */

SE_Move SE_makeMoveRight()
{
  return (SE_Move)ATmakeTerm(SE_patternMoveRight);
}

/*}}}  */
/*{{{  SE_Move SE_makeMoveUp() */

SE_Move SE_makeMoveUp()
{
  return (SE_Move)ATmakeTerm(SE_patternMoveUp);
}

/*}}}  */
/*{{{  SE_Move SE_makeMoveDown() */

SE_Move SE_makeMoveDown()
{
  return (SE_Move)ATmakeTerm(SE_patternMoveDown);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool SE_isEqualEditor(SE_Editor arg0, SE_Editor arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SE_isEqualFocus(SE_Focus arg0, SE_Focus arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SE_isEqualArea(SE_Area arg0, SE_Area arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SE_isEqualFocusList(SE_FocusList arg0, SE_FocusList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SE_isEqualSymbolList(SE_SymbolList arg0, SE_SymbolList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SE_isEqualPath(SE_Path arg0, SE_Path arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SE_isEqualSteps(SE_Steps arg0, SE_Steps arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SE_isEqualMove(SE_Move arg0, SE_Move arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  SE_Editor accessors */

/*{{{  ATbool SE_isValidEditor(SE_Editor arg) */

ATbool SE_isValidEditor(SE_Editor arg)
{
  if (SE_isEditorDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SE_isEditorDefault(SE_Editor arg) */

ATbool SE_isEditorDefault(SE_Editor arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternEditorDefault, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SE_hasEditorParseTree(SE_Editor arg) */

ATbool SE_hasEditorParseTree(SE_Editor arg)
{
  if (SE_isEditorDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SE_ParseTree SE_getEditorParseTree(SE_Editor arg) */

SE_ParseTree SE_getEditorParseTree(SE_Editor arg)
{
  if (SE_isEditorDefault(arg)) {
    return (SE_ParseTree)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Editor has no ParseTree: %t\n", arg);
  return (SE_ParseTree)NULL;
}

/*}}}  */
/*{{{  SE_Editor SE_setEditorParseTree(SE_Editor arg, SE_ParseTree parseTree) */

SE_Editor SE_setEditorParseTree(SE_Editor arg, SE_ParseTree parseTree)
{
  if (SE_isEditorDefault(arg)) {
    return (SE_Editor)ATsetArgument((ATermAppl)arg, (ATerm)parseTree, 0);
  }

  ATabort("Editor has no ParseTree: %t\n", arg);
  return (SE_Editor)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasEditorFocus(SE_Editor arg) */

ATbool SE_hasEditorFocus(SE_Editor arg)
{
  if (SE_isEditorDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SE_Focus SE_getEditorFocus(SE_Editor arg) */

SE_Focus SE_getEditorFocus(SE_Editor arg)
{
  if (SE_isEditorDefault(arg)) {
    return (SE_Focus)ATgetArgument((ATermAppl)arg, 1);
  }

  ATabort("Editor has no Focus: %t\n", arg);
  return (SE_Focus)NULL;
}

/*}}}  */
/*{{{  SE_Editor SE_setEditorFocus(SE_Editor arg, SE_Focus focus) */

SE_Editor SE_setEditorFocus(SE_Editor arg, SE_Focus focus)
{
  if (SE_isEditorDefault(arg)) {
    return (SE_Editor)ATsetArgument((ATermAppl)arg, (ATerm)focus, 1);
  }

  ATabort("Editor has no Focus: %t\n", arg);
  return (SE_Editor)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasEditorDirtyFoci(SE_Editor arg) */

ATbool SE_hasEditorDirtyFoci(SE_Editor arg)
{
  if (SE_isEditorDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SE_FocusList SE_getEditorDirtyFoci(SE_Editor arg) */

SE_FocusList SE_getEditorDirtyFoci(SE_Editor arg)
{
  if (SE_isEditorDefault(arg)) {
    return (SE_FocusList)ATgetArgument((ATermAppl)arg, 2);
  }

  ATabort("Editor has no DirtyFoci: %t\n", arg);
  return (SE_FocusList)NULL;
}

/*}}}  */
/*{{{  SE_Editor SE_setEditorDirtyFoci(SE_Editor arg, SE_FocusList dirtyFoci) */

SE_Editor SE_setEditorDirtyFoci(SE_Editor arg, SE_FocusList dirtyFoci)
{
  if (SE_isEditorDefault(arg)) {
    return (SE_Editor)ATsetArgument((ATermAppl)arg, (ATerm)dirtyFoci, 2);
  }

  ATabort("Editor has no DirtyFoci: %t\n", arg);
  return (SE_Editor)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasEditorStartSymbols(SE_Editor arg) */

ATbool SE_hasEditorStartSymbols(SE_Editor arg)
{
  if (SE_isEditorDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SE_SymbolList SE_getEditorStartSymbols(SE_Editor arg) */

SE_SymbolList SE_getEditorStartSymbols(SE_Editor arg)
{
  if (SE_isEditorDefault(arg)) {
    return (SE_SymbolList)ATgetArgument((ATermAppl)arg, 3);
  }

  ATabort("Editor has no StartSymbols: %t\n", arg);
  return (SE_SymbolList)NULL;
}

/*}}}  */
/*{{{  SE_Editor SE_setEditorStartSymbols(SE_Editor arg, SE_SymbolList startSymbols) */

SE_Editor SE_setEditorStartSymbols(SE_Editor arg, SE_SymbolList startSymbols)
{
  if (SE_isEditorDefault(arg)) {
    return (SE_Editor)ATsetArgument((ATermAppl)arg, (ATerm)startSymbols, 3);
  }

  ATabort("Editor has no StartSymbols: %t\n", arg);
  return (SE_Editor)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SE_Focus accessors */

/*{{{  ATbool SE_isValidFocus(SE_Focus arg) */

ATbool SE_isValidFocus(SE_Focus arg)
{
  if (SE_isFocusEmpty(arg)) {
    return ATtrue;
  }
  else if (SE_isFocusNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SE_isFocusEmpty(SE_Focus arg) */

ATbool SE_isFocusEmpty(SE_Focus arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternFocusEmpty);
}

/*}}}  */
/*{{{  ATbool SE_isFocusNotEmpty(SE_Focus arg) */

ATbool SE_isFocusNotEmpty(SE_Focus arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternFocusNotEmpty, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SE_hasFocusPath(SE_Focus arg) */

ATbool SE_hasFocusPath(SE_Focus arg)
{
  if (SE_isFocusNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SE_Path SE_getFocusPath(SE_Focus arg) */

SE_Path SE_getFocusPath(SE_Focus arg)
{
  if (SE_isFocusNotEmpty(arg)) {
    return (SE_Path)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Focus has no Path: %t\n", arg);
  return (SE_Path)NULL;
}

/*}}}  */
/*{{{  SE_Focus SE_setFocusPath(SE_Focus arg, SE_Path path) */

SE_Focus SE_setFocusPath(SE_Focus arg, SE_Path path)
{
  if (SE_isFocusNotEmpty(arg)) {
    return (SE_Focus)ATsetArgument((ATermAppl)arg, (ATerm)path, 0);
  }

  ATabort("Focus has no Path: %t\n", arg);
  return (SE_Focus)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasFocusSort(SE_Focus arg) */

ATbool SE_hasFocusSort(SE_Focus arg)
{
  if (SE_isFocusNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SE_getFocusSort(SE_Focus arg) */

char * SE_getFocusSort(SE_Focus arg)
{
  if (SE_isFocusNotEmpty(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 1)));
  }

  ATabort("Focus has no Sort: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SE_Focus SE_setFocusSort(SE_Focus arg, char * sort) */

SE_Focus SE_setFocusSort(SE_Focus arg, char * sort)
{
  if (SE_isFocusNotEmpty(arg)) {
    return (SE_Focus)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(sort, 0, ATtrue)), 1);
  }

  ATabort("Focus has no Sort: %t\n", arg);
  return (SE_Focus)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasFocusArea(SE_Focus arg) */

ATbool SE_hasFocusArea(SE_Focus arg)
{
  if (SE_isFocusNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SE_Area SE_getFocusArea(SE_Focus arg) */

SE_Area SE_getFocusArea(SE_Focus arg)
{
  if (SE_isFocusNotEmpty(arg)) {
    return (SE_Area)ATgetArgument((ATermAppl)arg, 2);
  }

  ATabort("Focus has no Area: %t\n", arg);
  return (SE_Area)NULL;
}

/*}}}  */
/*{{{  SE_Focus SE_setFocusArea(SE_Focus arg, SE_Area area) */

SE_Focus SE_setFocusArea(SE_Focus arg, SE_Area area)
{
  if (SE_isFocusNotEmpty(arg)) {
    return (SE_Focus)ATsetArgument((ATermAppl)arg, (ATerm)area, 2);
  }

  ATabort("Focus has no Area: %t\n", arg);
  return (SE_Focus)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasFocusDirty(SE_Focus arg) */

ATbool SE_hasFocusDirty(SE_Focus arg)
{
  if (SE_isFocusNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int SE_getFocusDirty(SE_Focus arg) */

int SE_getFocusDirty(SE_Focus arg)
{
  if (SE_isFocusNotEmpty(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 3));
  }

  ATabort("Focus has no Dirty: %t\n", arg);
  return (int)NULL;
}

/*}}}  */
/*{{{  SE_Focus SE_setFocusDirty(SE_Focus arg, int dirty) */

SE_Focus SE_setFocusDirty(SE_Focus arg, int dirty)
{
  if (SE_isFocusNotEmpty(arg)) {
    return (SE_Focus)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(dirty), 3);
  }

  ATabort("Focus has no Dirty: %t\n", arg);
  return (SE_Focus)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SE_Area accessors */

/*{{{  ATbool SE_isValidArea(SE_Area arg) */

ATbool SE_isValidArea(SE_Area arg)
{
  if (SE_isAreaDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SE_isAreaDefault(SE_Area arg) */

ATbool SE_isAreaDefault(SE_Area arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternAreaDefault, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SE_hasAreaStart(SE_Area arg) */

ATbool SE_hasAreaStart(SE_Area arg)
{
  if (SE_isAreaDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int SE_getAreaStart(SE_Area arg) */

int SE_getAreaStart(SE_Area arg)
{
  if (SE_isAreaDefault(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
  }

  ATabort("Area has no Start: %t\n", arg);
  return (int)NULL;
}

/*}}}  */
/*{{{  SE_Area SE_setAreaStart(SE_Area arg, int start) */

SE_Area SE_setAreaStart(SE_Area arg, int start)
{
  if (SE_isAreaDefault(arg)) {
    return (SE_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(start), 0);
  }

  ATabort("Area has no Start: %t\n", arg);
  return (SE_Area)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasAreaLength(SE_Area arg) */

ATbool SE_hasAreaLength(SE_Area arg)
{
  if (SE_isAreaDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int SE_getAreaLength(SE_Area arg) */

int SE_getAreaLength(SE_Area arg)
{
  if (SE_isAreaDefault(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }

  ATabort("Area has no Length: %t\n", arg);
  return (int)NULL;
}

/*}}}  */
/*{{{  SE_Area SE_setAreaLength(SE_Area arg, int length) */

SE_Area SE_setAreaLength(SE_Area arg, int length)
{
  if (SE_isAreaDefault(arg)) {
    return (SE_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(length), 1);
  }

  ATabort("Area has no Length: %t\n", arg);
  return (SE_Area)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SE_FocusList accessors */

/*{{{  ATbool SE_isValidFocusList(SE_FocusList arg) */

ATbool SE_isValidFocusList(SE_FocusList arg)
{
  if (SE_isFocusListEmpty(arg)) {
    return ATtrue;
  }
  else if (SE_isFocusListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SE_isFocusListEmpty(SE_FocusList arg) */

ATbool SE_isFocusListEmpty(SE_FocusList arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternFocusListEmpty);
}

/*}}}  */
/*{{{  ATbool SE_isFocusListMulti(SE_FocusList arg) */

ATbool SE_isFocusListMulti(SE_FocusList arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternFocusListMulti, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SE_hasFocusListHead(SE_FocusList arg) */

ATbool SE_hasFocusListHead(SE_FocusList arg)
{
  if (SE_isFocusListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SE_Focus SE_getFocusListHead(SE_FocusList arg) */

SE_Focus SE_getFocusListHead(SE_FocusList arg)
{
  if (SE_isFocusListMulti(arg)) {
    return (SE_Focus)ATelementAt((ATermList)arg, 0);
  }

  ATabort("FocusList has no Head: %t\n", arg);
  return (SE_Focus)NULL;
}

/*}}}  */
/*{{{  SE_FocusList SE_setFocusListHead(SE_FocusList arg, SE_Focus head) */

SE_FocusList SE_setFocusListHead(SE_FocusList arg, SE_Focus head)
{
  if (SE_isFocusListMulti(arg)) {
    return (SE_FocusList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("FocusList has no Head: %t\n", arg);
  return (SE_FocusList)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasFocusListTail(SE_FocusList arg) */

ATbool SE_hasFocusListTail(SE_FocusList arg)
{
  if (SE_isFocusListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SE_FocusList SE_getFocusListTail(SE_FocusList arg) */

SE_FocusList SE_getFocusListTail(SE_FocusList arg)
{
  if (SE_isFocusListMulti(arg)) {
    return (SE_FocusList)ATgetTail((ATermList)arg, 1);
  }

  ATabort("FocusList has no Tail: %t\n", arg);
  return (SE_FocusList)NULL;
}

/*}}}  */
/*{{{  SE_FocusList SE_setFocusListTail(SE_FocusList arg, SE_FocusList tail) */

SE_FocusList SE_setFocusListTail(SE_FocusList arg, SE_FocusList tail)
{
  if (SE_isFocusListMulti(arg)) {
    return (SE_FocusList)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("FocusList has no Tail: %t\n", arg);
  return (SE_FocusList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SE_SymbolList accessors */

/*{{{  ATbool SE_isValidSymbolList(SE_SymbolList arg) */

ATbool SE_isValidSymbolList(SE_SymbolList arg)
{
  if (SE_isSymbolListEmpty(arg)) {
    return ATtrue;
  }
  else if (SE_isSymbolListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SE_isSymbolListEmpty(SE_SymbolList arg) */

ATbool SE_isSymbolListEmpty(SE_SymbolList arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternSymbolListEmpty);
}

/*}}}  */
/*{{{  ATbool SE_isSymbolListMulti(SE_SymbolList arg) */

ATbool SE_isSymbolListMulti(SE_SymbolList arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternSymbolListMulti, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SE_hasSymbolListHead(SE_SymbolList arg) */

ATbool SE_hasSymbolListHead(SE_SymbolList arg)
{
  if (SE_isSymbolListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * SE_getSymbolListHead(SE_SymbolList arg) */

char * SE_getSymbolListHead(SE_SymbolList arg)
{
  if (SE_isSymbolListMulti(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATelementAt((ATermList)arg, 0)));
  }

  ATabort("SymbolList has no Head: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  SE_SymbolList SE_setSymbolListHead(SE_SymbolList arg, char * head) */

SE_SymbolList SE_setSymbolListHead(SE_SymbolList arg, char * head)
{
  if (SE_isSymbolListMulti(arg)) {
    return (SE_SymbolList)ATreplace((ATermList)arg, (ATerm)ATmakeAppl0(ATmakeAFun(head, 0, ATtrue)), 0);
  }

  ATabort("SymbolList has no Head: %t\n", arg);
  return (SE_SymbolList)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasSymbolListTail(SE_SymbolList arg) */

ATbool SE_hasSymbolListTail(SE_SymbolList arg)
{
  if (SE_isSymbolListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SE_SymbolList SE_getSymbolListTail(SE_SymbolList arg) */

SE_SymbolList SE_getSymbolListTail(SE_SymbolList arg)
{
  if (SE_isSymbolListMulti(arg)) {
    return (SE_SymbolList)ATgetTail((ATermList)arg, 1);
  }

  ATabort("SymbolList has no Tail: %t\n", arg);
  return (SE_SymbolList)NULL;
}

/*}}}  */
/*{{{  SE_SymbolList SE_setSymbolListTail(SE_SymbolList arg, SE_SymbolList tail) */

SE_SymbolList SE_setSymbolListTail(SE_SymbolList arg, SE_SymbolList tail)
{
  if (SE_isSymbolListMulti(arg)) {
    return (SE_SymbolList)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("SymbolList has no Tail: %t\n", arg);
  return (SE_SymbolList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SE_Path accessors */

/*{{{  ATbool SE_isValidPath(SE_Path arg) */

ATbool SE_isValidPath(SE_Path arg)
{
  if (SE_isPathRoot(arg)) {
    return ATtrue;
  }
  else if (SE_isPathLeftLayout(arg)) {
    return ATtrue;
  }
  else if (SE_isPathTerm(arg)) {
    return ATtrue;
  }
  else if (SE_isPathRightLayout(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SE_isPathRoot(SE_Path arg) */

ATbool SE_isPathRoot(SE_Path arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternPathRoot);
}

/*}}}  */
/*{{{  ATbool SE_isPathLeftLayout(SE_Path arg) */

ATbool SE_isPathLeftLayout(SE_Path arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternPathLeftLayout);
}

/*}}}  */
/*{{{  ATbool SE_isPathTerm(SE_Path arg) */

ATbool SE_isPathTerm(SE_Path arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternPathTerm, NULL);
}

/*}}}  */
/*{{{  ATbool SE_isPathRightLayout(SE_Path arg) */

ATbool SE_isPathRightLayout(SE_Path arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternPathRightLayout);
}

/*}}}  */
/*{{{  ATbool SE_hasPathSteps(SE_Path arg) */

ATbool SE_hasPathSteps(SE_Path arg)
{
  if (SE_isPathTerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SE_Steps SE_getPathSteps(SE_Path arg) */

SE_Steps SE_getPathSteps(SE_Path arg)
{
  if (SE_isPathTerm(arg)) {
    return (SE_Steps)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Path has no Steps: %t\n", arg);
  return (SE_Steps)NULL;
}

/*}}}  */
/*{{{  SE_Path SE_setPathSteps(SE_Path arg, SE_Steps steps) */

SE_Path SE_setPathSteps(SE_Path arg, SE_Steps steps)
{
  if (SE_isPathTerm(arg)) {
    return (SE_Path)ATsetArgument((ATermAppl)arg, (ATerm)steps, 0);
  }

  ATabort("Path has no Steps: %t\n", arg);
  return (SE_Path)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SE_Steps accessors */

/*{{{  ATbool SE_isValidSteps(SE_Steps arg) */

ATbool SE_isValidSteps(SE_Steps arg)
{
  if (SE_isStepsEmpty(arg)) {
    return ATtrue;
  }
  else if (SE_isStepsMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SE_isStepsEmpty(SE_Steps arg) */

ATbool SE_isStepsEmpty(SE_Steps arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternStepsEmpty);
}

/*}}}  */
/*{{{  ATbool SE_isStepsMulti(SE_Steps arg) */

ATbool SE_isStepsMulti(SE_Steps arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternStepsMulti, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool SE_hasStepsHead(SE_Steps arg) */

ATbool SE_hasStepsHead(SE_Steps arg)
{
  if (SE_isStepsMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int SE_getStepsHead(SE_Steps arg) */

int SE_getStepsHead(SE_Steps arg)
{
  if (SE_isStepsMulti(arg)) {
    return (int)ATgetInt((ATermInt)ATelementAt((ATermList)arg, 0));
  }

  ATabort("Steps has no Head: %t\n", arg);
  return (int)NULL;
}

/*}}}  */
/*{{{  SE_Steps SE_setStepsHead(SE_Steps arg, int head) */

SE_Steps SE_setStepsHead(SE_Steps arg, int head)
{
  if (SE_isStepsMulti(arg)) {
    return (SE_Steps)ATreplace((ATermList)arg, (ATerm)ATmakeInt(head), 0);
  }

  ATabort("Steps has no Head: %t\n", arg);
  return (SE_Steps)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasStepsTail(SE_Steps arg) */

ATbool SE_hasStepsTail(SE_Steps arg)
{
  if (SE_isStepsMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SE_Steps SE_getStepsTail(SE_Steps arg) */

SE_Steps SE_getStepsTail(SE_Steps arg)
{
  if (SE_isStepsMulti(arg)) {
    return (SE_Steps)ATgetTail((ATermList)arg, 1);
  }

  ATabort("Steps has no Tail: %t\n", arg);
  return (SE_Steps)NULL;
}

/*}}}  */
/*{{{  SE_Steps SE_setStepsTail(SE_Steps arg, SE_Steps tail) */

SE_Steps SE_setStepsTail(SE_Steps arg, SE_Steps tail)
{
  if (SE_isStepsMulti(arg)) {
    return (SE_Steps)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Steps has no Tail: %t\n", arg);
  return (SE_Steps)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SE_Move accessors */

/*{{{  ATbool SE_isValidMove(SE_Move arg) */

ATbool SE_isValidMove(SE_Move arg)
{
  if (SE_isMoveLeft(arg)) {
    return ATtrue;
  }
  else if (SE_isMoveRight(arg)) {
    return ATtrue;
  }
  else if (SE_isMoveUp(arg)) {
    return ATtrue;
  }
  else if (SE_isMoveDown(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool SE_isMoveLeft(SE_Move arg) */

ATbool SE_isMoveLeft(SE_Move arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternMoveLeft);
}

/*}}}  */
/*{{{  ATbool SE_isMoveRight(SE_Move arg) */

ATbool SE_isMoveRight(SE_Move arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternMoveRight);
}

/*}}}  */
/*{{{  ATbool SE_isMoveUp(SE_Move arg) */

ATbool SE_isMoveUp(SE_Move arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternMoveUp);
}

/*}}}  */
/*{{{  ATbool SE_isMoveDown(SE_Move arg) */

ATbool SE_isMoveDown(SE_Move arg)
{
  return ATmatchTerm((ATerm)arg, SE_patternMoveDown);
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  SE_Editor SE_visitEditor(SE_Editor arg, SE_ParseTree (*acceptParseTree)(SE_ParseTree), SE_Focus (*acceptFocus)(SE_Focus), SE_FocusList (*acceptDirtyFoci)(SE_FocusList), SE_SymbolList (*acceptStartSymbols)(SE_SymbolList)) */

SE_Editor SE_visitEditor(SE_Editor arg, SE_ParseTree (*acceptParseTree)(SE_ParseTree), SE_Focus (*acceptFocus)(SE_Focus), SE_FocusList (*acceptDirtyFoci)(SE_FocusList), SE_SymbolList (*acceptStartSymbols)(SE_SymbolList))
{
  if (SE_isEditorDefault(arg)) {
    return SE_makeEditorDefault(
        acceptParseTree ? acceptParseTree(SE_getEditorParseTree(arg)) : SE_getEditorParseTree(arg),
        acceptFocus ? acceptFocus(SE_getEditorFocus(arg)) : SE_getEditorFocus(arg),
        acceptDirtyFoci ? acceptDirtyFoci(SE_getEditorDirtyFoci(arg)) : SE_getEditorDirtyFoci(arg),
        acceptStartSymbols ? acceptStartSymbols(SE_getEditorStartSymbols(arg)) : SE_getEditorStartSymbols(arg));
  }
  ATabort("not a Editor: %t\n", arg);
  return (SE_Editor)NULL;
}

/*}}}  */
/*{{{  SE_Focus SE_visitFocus(SE_Focus arg, SE_Path (*acceptPath)(SE_Path), char * (*acceptSort)(char *), SE_Area (*acceptArea)(SE_Area), int (*acceptDirty)(int)) */

SE_Focus SE_visitFocus(SE_Focus arg, SE_Path (*acceptPath)(SE_Path), char * (*acceptSort)(char *), SE_Area (*acceptArea)(SE_Area), int (*acceptDirty)(int))
{
  if (SE_isFocusEmpty(arg)) {
    return SE_makeFocusEmpty();
  }
  if (SE_isFocusNotEmpty(arg)) {
    return SE_makeFocusNotEmpty(
        acceptPath ? acceptPath(SE_getFocusPath(arg)) : SE_getFocusPath(arg),
        acceptSort ? acceptSort(SE_getFocusSort(arg)) : SE_getFocusSort(arg),
        acceptArea ? acceptArea(SE_getFocusArea(arg)) : SE_getFocusArea(arg),
        acceptDirty ? acceptDirty(SE_getFocusDirty(arg)) : SE_getFocusDirty(arg));
  }
  ATabort("not a Focus: %t\n", arg);
  return (SE_Focus)NULL;
}

/*}}}  */
/*{{{  SE_Area SE_visitArea(SE_Area arg, int (*acceptStart)(int), int (*acceptLength)(int)) */

SE_Area SE_visitArea(SE_Area arg, int (*acceptStart)(int), int (*acceptLength)(int))
{
  if (SE_isAreaDefault(arg)) {
    return SE_makeAreaDefault(
        acceptStart ? acceptStart(SE_getAreaStart(arg)) : SE_getAreaStart(arg),
        acceptLength ? acceptLength(SE_getAreaLength(arg)) : SE_getAreaLength(arg));
  }
  ATabort("not a Area: %t\n", arg);
  return (SE_Area)NULL;
}

/*}}}  */
/*{{{  SE_FocusList SE_visitFocusList(SE_FocusList arg, SE_Focus (*acceptHead)(SE_Focus)) */

SE_FocusList SE_visitFocusList(SE_FocusList arg, SE_Focus (*acceptHead)(SE_Focus))
{
  if (SE_isFocusListEmpty(arg)) {
    return SE_makeFocusListEmpty();
  }
  if (SE_isFocusListMulti(arg)) {
    return SE_makeFocusListMulti(
        acceptHead ? acceptHead(SE_getFocusListHead(arg)) : SE_getFocusListHead(arg),
        SE_visitFocusList(SE_getFocusListTail(arg), acceptHead));
  }
  ATabort("not a FocusList: %t\n", arg);
  return (SE_FocusList)NULL;
}

/*}}}  */
/*{{{  SE_SymbolList SE_visitSymbolList(SE_SymbolList arg, char * (*acceptHead)(char *)) */

SE_SymbolList SE_visitSymbolList(SE_SymbolList arg, char * (*acceptHead)(char *))
{
  if (SE_isSymbolListEmpty(arg)) {
    return SE_makeSymbolListEmpty();
  }
  if (SE_isSymbolListMulti(arg)) {
    return SE_makeSymbolListMulti(
        acceptHead ? acceptHead(SE_getSymbolListHead(arg)) : SE_getSymbolListHead(arg),
        SE_visitSymbolList(SE_getSymbolListTail(arg), acceptHead));
  }
  ATabort("not a SymbolList: %t\n", arg);
  return (SE_SymbolList)NULL;
}

/*}}}  */
/*{{{  SE_Path SE_visitPath(SE_Path arg, SE_Steps (*acceptSteps)(SE_Steps)) */

SE_Path SE_visitPath(SE_Path arg, SE_Steps (*acceptSteps)(SE_Steps))
{
  if (SE_isPathRoot(arg)) {
    return SE_makePathRoot();
  }
  if (SE_isPathLeftLayout(arg)) {
    return SE_makePathLeftLayout();
  }
  if (SE_isPathTerm(arg)) {
    return SE_makePathTerm(
        acceptSteps ? acceptSteps(SE_getPathSteps(arg)) : SE_getPathSteps(arg));
  }
  if (SE_isPathRightLayout(arg)) {
    return SE_makePathRightLayout();
  }
  ATabort("not a Path: %t\n", arg);
  return (SE_Path)NULL;
}

/*}}}  */
/*{{{  SE_Steps SE_visitSteps(SE_Steps arg, int (*acceptHead)(int)) */

SE_Steps SE_visitSteps(SE_Steps arg, int (*acceptHead)(int))
{
  if (SE_isStepsEmpty(arg)) {
    return SE_makeStepsEmpty();
  }
  if (SE_isStepsMulti(arg)) {
    return SE_makeStepsMulti(
        acceptHead ? acceptHead(SE_getStepsHead(arg)) : SE_getStepsHead(arg),
        SE_visitSteps(SE_getStepsTail(arg), acceptHead));
  }
  ATabort("not a Steps: %t\n", arg);
  return (SE_Steps)NULL;
}

/*}}}  */
/*{{{  SE_Move SE_visitMove(SE_Move arg) */

SE_Move SE_visitMove(SE_Move arg)
{
  if (SE_isMoveLeft(arg)) {
    return SE_makeMoveLeft();
  }
  if (SE_isMoveRight(arg)) {
    return SE_makeMoveRight();
  }
  if (SE_isMoveUp(arg)) {
    return SE_makeMoveUp();
  }
  if (SE_isMoveDown(arg)) {
    return SE_makeMoveDown();
  }
  ATabort("not a Move: %t\n", arg);
  return (SE_Move)NULL;
}

/*}}}  */

/*}}}  */
