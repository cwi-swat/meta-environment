#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "EditorData.h"

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

/*{{{  void SE_initEditorDataApi(void) */

void SE_initEditorDataApi(void)
{
  init_EditorData_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  SE_Editor SE_EditorFromTerm(ATerm t) */

SE_Editor SE_EditorFromTerm(ATerm t)
{
  return (SE_Editor)t;
}

/*}}}  */
/*{{{  ATerm SE_EditorToTerm(SE_Editor arg) */

ATerm SE_EditorToTerm(SE_Editor arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SE_Focus SE_FocusFromTerm(ATerm t) */

SE_Focus SE_FocusFromTerm(ATerm t)
{
  return (SE_Focus)t;
}

/*}}}  */
/*{{{  ATerm SE_FocusToTerm(SE_Focus arg) */

ATerm SE_FocusToTerm(SE_Focus arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SE_Area SE_AreaFromTerm(ATerm t) */

SE_Area SE_AreaFromTerm(ATerm t)
{
  return (SE_Area)t;
}

/*}}}  */
/*{{{  ATerm SE_AreaToTerm(SE_Area arg) */

ATerm SE_AreaToTerm(SE_Area arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SE_FocusList SE_FocusListFromTerm(ATerm t) */

SE_FocusList SE_FocusListFromTerm(ATerm t)
{
  return (SE_FocusList)t;
}

/*}}}  */
/*{{{  ATerm SE_FocusListToTerm(SE_FocusList arg) */

ATerm SE_FocusListToTerm(SE_FocusList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SE_SymbolList SE_SymbolListFromTerm(ATerm t) */

SE_SymbolList SE_SymbolListFromTerm(ATerm t)
{
  return (SE_SymbolList)t;
}

/*}}}  */
/*{{{  ATerm SE_SymbolListToTerm(SE_SymbolList arg) */

ATerm SE_SymbolListToTerm(SE_SymbolList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SE_Path SE_PathFromTerm(ATerm t) */

SE_Path SE_PathFromTerm(ATerm t)
{
  return (SE_Path)t;
}

/*}}}  */
/*{{{  ATerm SE_PathToTerm(SE_Path arg) */

ATerm SE_PathToTerm(SE_Path arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SE_Steps SE_StepsFromTerm(ATerm t) */

SE_Steps SE_StepsFromTerm(ATerm t)
{
  return (SE_Steps)t;
}

/*}}}  */
/*{{{  ATerm SE_StepsToTerm(SE_Steps arg) */

ATerm SE_StepsToTerm(SE_Steps arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SE_Move SE_MoveFromTerm(ATerm t) */

SE_Move SE_MoveFromTerm(ATerm t)
{
  return (SE_Move)t;
}

/*}}}  */
/*{{{  ATerm SE_MoveToTerm(SE_Move arg) */

ATerm SE_MoveToTerm(SE_Move arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */

/*{{{  SE_Editor SE_makeEditorDefault(SE_ParseTree parseTree, SE_Focus focus, SE_FocusList unparsedFoci, int modified, SE_SymbolList startSymbols) */

SE_Editor SE_makeEditorDefault(SE_ParseTree parseTree, SE_Focus focus, SE_FocusList unparsedFoci, int modified, SE_SymbolList startSymbols)
{
  return (SE_Editor)(ATerm)ATmakeAppl5(SE_afun0, (ATerm)parseTree, (ATerm)focus, (ATerm)unparsedFoci, (ATerm)ATmakeInt(modified), (ATerm)startSymbols);
}

/*}}}  */
/*{{{  SE_Focus SE_makeFocusEmpty() */

SE_Focus SE_makeFocusEmpty()
{
  return (SE_Focus)(ATerm)ATmakeAppl0(SE_afun1);
}

/*}}}  */
/*{{{  SE_Focus SE_makeFocusNotEmpty(SE_Path path, char* sort, SE_Area area, int unparsed) */

SE_Focus SE_makeFocusNotEmpty(SE_Path path, char* sort, SE_Area area, int unparsed)
{
  return (SE_Focus)(ATerm)ATmakeAppl4(SE_afun2, (ATerm)path, (ATerm)ATmakeAppl0(ATmakeAFun(sort, 0, ATtrue)), (ATerm)area, (ATerm)ATmakeInt(unparsed));
}

/*}}}  */
/*{{{  SE_Area SE_makeAreaDefault(int start, int length) */

SE_Area SE_makeAreaDefault(int start, int length)
{
  return (SE_Area)(ATerm)ATmakeAppl2(SE_afun3, (ATerm)ATmakeInt(start), (ATerm)ATmakeInt(length));
}

/*}}}  */
/*{{{  SE_FocusList SE_makeFocusListEmpty() */

SE_FocusList SE_makeFocusListEmpty()
{
  return (SE_FocusList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SE_FocusList SE_makeFocusListMulti(SE_Focus head, SE_FocusList tail) */

SE_FocusList SE_makeFocusListMulti(SE_Focus head, SE_FocusList tail)
{
  return (SE_FocusList)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  SE_SymbolList SE_makeSymbolListEmpty() */

SE_SymbolList SE_makeSymbolListEmpty()
{
  return (SE_SymbolList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SE_SymbolList SE_makeSymbolListMulti(char* head, SE_SymbolList tail) */

SE_SymbolList SE_makeSymbolListMulti(char* head, SE_SymbolList tail)
{
  return (SE_SymbolList)(ATerm)ATinsert((ATermList)tail, (ATerm)ATmakeAppl0(ATmakeAFun(head, 0, ATtrue)));
}

/*}}}  */
/*{{{  SE_Path SE_makePathRoot() */

SE_Path SE_makePathRoot()
{
  return (SE_Path)(ATerm)ATmakeAppl0(SE_afun4);
}

/*}}}  */
/*{{{  SE_Path SE_makePathLeftLayout() */

SE_Path SE_makePathLeftLayout()
{
  return (SE_Path)(ATerm)ATmakeAppl0(SE_afun5);
}

/*}}}  */
/*{{{  SE_Path SE_makePathTree(SE_Steps steps) */

SE_Path SE_makePathTree(SE_Steps steps)
{
  return (SE_Path)(ATerm)ATmakeAppl1(SE_afun6, (ATerm)steps);
}

/*}}}  */
/*{{{  SE_Path SE_makePathRightLayout() */

SE_Path SE_makePathRightLayout()
{
  return (SE_Path)(ATerm)ATmakeAppl0(SE_afun7);
}

/*}}}  */
/*{{{  SE_Steps SE_makeStepsEmpty() */

SE_Steps SE_makeStepsEmpty()
{
  return (SE_Steps)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SE_Steps SE_makeStepsMulti(int head, SE_Steps tail) */

SE_Steps SE_makeStepsMulti(int head, SE_Steps tail)
{
  return (SE_Steps)(ATerm)ATinsert((ATermList)tail, (ATerm)ATmakeInt(head));
}

/*}}}  */
/*{{{  SE_Move SE_makeMoveLeft() */

SE_Move SE_makeMoveLeft()
{
  return (SE_Move)(ATerm)ATmakeAppl0(SE_afun8);
}

/*}}}  */
/*{{{  SE_Move SE_makeMoveRight() */

SE_Move SE_makeMoveRight()
{
  return (SE_Move)(ATerm)ATmakeAppl0(SE_afun9);
}

/*}}}  */
/*{{{  SE_Move SE_makeMoveUp() */

SE_Move SE_makeMoveUp()
{
  return (SE_Move)(ATerm)ATmakeAppl0(SE_afun10);
}

/*}}}  */
/*{{{  SE_Move SE_makeMoveDown() */

SE_Move SE_makeMoveDown()
{
  return (SE_Move)(ATerm)ATmakeAppl0(SE_afun11);
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
/*{{{  inline ATbool SE_isEditorDefault(SE_Editor arg) */

inline ATbool SE_isEditorDefault(SE_Editor arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SE_patternEditorDefault, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
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
  
    return (SE_ParseTree)ATgetArgument((ATermAppl)arg, 0);
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
  
    return (SE_Focus)ATgetArgument((ATermAppl)arg, 1);
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
/*{{{  ATbool SE_hasEditorUnparsedFoci(SE_Editor arg) */

ATbool SE_hasEditorUnparsedFoci(SE_Editor arg)
{
  if (SE_isEditorDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SE_FocusList SE_getEditorUnparsedFoci(SE_Editor arg) */

SE_FocusList SE_getEditorUnparsedFoci(SE_Editor arg)
{
  
    return (SE_FocusList)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  SE_Editor SE_setEditorUnparsedFoci(SE_Editor arg, SE_FocusList unparsedFoci) */

SE_Editor SE_setEditorUnparsedFoci(SE_Editor arg, SE_FocusList unparsedFoci)
{
  if (SE_isEditorDefault(arg)) {
    return (SE_Editor)ATsetArgument((ATermAppl)arg, (ATerm)unparsedFoci, 2);
  }

  ATabort("Editor has no UnparsedFoci: %t\n", arg);
  return (SE_Editor)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasEditorModified(SE_Editor arg) */

ATbool SE_hasEditorModified(SE_Editor arg)
{
  if (SE_isEditorDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int SE_getEditorModified(SE_Editor arg) */

int SE_getEditorModified(SE_Editor arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 3));
}

/*}}}  */
/*{{{  SE_Editor SE_setEditorModified(SE_Editor arg, int modified) */

SE_Editor SE_setEditorModified(SE_Editor arg, int modified)
{
  if (SE_isEditorDefault(arg)) {
    return (SE_Editor)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(modified), 3);
  }

  ATabort("Editor has no Modified: %t\n", arg);
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
  
    return (SE_SymbolList)ATgetArgument((ATermAppl)arg, 4);
}

/*}}}  */
/*{{{  SE_Editor SE_setEditorStartSymbols(SE_Editor arg, SE_SymbolList startSymbols) */

SE_Editor SE_setEditorStartSymbols(SE_Editor arg, SE_SymbolList startSymbols)
{
  if (SE_isEditorDefault(arg)) {
    return (SE_Editor)ATsetArgument((ATermAppl)arg, (ATerm)startSymbols, 4);
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
/*{{{  inline ATbool SE_isFocusEmpty(SE_Focus arg) */

inline ATbool SE_isFocusEmpty(SE_Focus arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternFocusEmpty);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SE_isFocusNotEmpty(SE_Focus arg) */

inline ATbool SE_isFocusNotEmpty(SE_Focus arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternFocusNotEmpty, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
  
    return (SE_Path)ATgetArgument((ATermAppl)arg, 0);
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
/*{{{  char* SE_getFocusSort(SE_Focus arg) */

char* SE_getFocusSort(SE_Focus arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  SE_Focus SE_setFocusSort(SE_Focus arg, char* sort) */

SE_Focus SE_setFocusSort(SE_Focus arg, char* sort)
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
  
    return (SE_Area)ATgetArgument((ATermAppl)arg, 2);
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
/*{{{  ATbool SE_hasFocusUnparsed(SE_Focus arg) */

ATbool SE_hasFocusUnparsed(SE_Focus arg)
{
  if (SE_isFocusNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int SE_getFocusUnparsed(SE_Focus arg) */

int SE_getFocusUnparsed(SE_Focus arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 3));
}

/*}}}  */
/*{{{  SE_Focus SE_setFocusUnparsed(SE_Focus arg, int unparsed) */

SE_Focus SE_setFocusUnparsed(SE_Focus arg, int unparsed)
{
  if (SE_isFocusNotEmpty(arg)) {
    return (SE_Focus)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(unparsed), 3);
  }

  ATabort("Focus has no Unparsed: %t\n", arg);
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
/*{{{  inline ATbool SE_isAreaDefault(SE_Area arg) */

inline ATbool SE_isAreaDefault(SE_Area arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SE_patternAreaDefault, NULL, NULL));
#endif
  return ATtrue;
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
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
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
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
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
/*{{{  inline ATbool SE_isFocusListEmpty(SE_FocusList arg) */

inline ATbool SE_isFocusListEmpty(SE_FocusList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SE_patternFocusListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SE_isFocusListMulti(SE_FocusList arg) */

inline ATbool SE_isFocusListMulti(SE_FocusList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SE_patternFocusListMulti, NULL, NULL));
#endif
  return ATtrue;
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
  
    return (SE_Focus)ATgetFirst((ATermList)arg);
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
  
    return (SE_FocusList)ATgetNext((ATermList)arg);
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
/*{{{  inline ATbool SE_isSymbolListEmpty(SE_SymbolList arg) */

inline ATbool SE_isSymbolListEmpty(SE_SymbolList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SE_patternSymbolListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SE_isSymbolListMulti(SE_SymbolList arg) */

inline ATbool SE_isSymbolListMulti(SE_SymbolList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SE_patternSymbolListMulti, NULL, NULL));
#endif
  return ATtrue;
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
/*{{{  char* SE_getSymbolListHead(SE_SymbolList arg) */

char* SE_getSymbolListHead(SE_SymbolList arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetFirst((ATermList)arg)));
}

/*}}}  */
/*{{{  SE_SymbolList SE_setSymbolListHead(SE_SymbolList arg, char* head) */

SE_SymbolList SE_setSymbolListHead(SE_SymbolList arg, char* head)
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
  
    return (SE_SymbolList)ATgetNext((ATermList)arg);
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
  else if (SE_isPathTree(arg)) {
    return ATtrue;
  }
  else if (SE_isPathRightLayout(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SE_isPathRoot(SE_Path arg) */

inline ATbool SE_isPathRoot(SE_Path arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternPathRoot);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SE_isPathLeftLayout(SE_Path arg) */

inline ATbool SE_isPathLeftLayout(SE_Path arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternPathLeftLayout);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SE_isPathTree(SE_Path arg) */

inline ATbool SE_isPathTree(SE_Path arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternPathTree, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SE_isPathRightLayout(SE_Path arg) */

inline ATbool SE_isPathRightLayout(SE_Path arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternPathRightLayout);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SE_hasPathSteps(SE_Path arg) */

ATbool SE_hasPathSteps(SE_Path arg)
{
  if (SE_isPathTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SE_Steps SE_getPathSteps(SE_Path arg) */

SE_Steps SE_getPathSteps(SE_Path arg)
{
  
    return (SE_Steps)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  SE_Path SE_setPathSteps(SE_Path arg, SE_Steps steps) */

SE_Path SE_setPathSteps(SE_Path arg, SE_Steps steps)
{
  if (SE_isPathTree(arg)) {
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
/*{{{  inline ATbool SE_isStepsEmpty(SE_Steps arg) */

inline ATbool SE_isStepsEmpty(SE_Steps arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SE_patternStepsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SE_isStepsMulti(SE_Steps arg) */

inline ATbool SE_isStepsMulti(SE_Steps arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SE_patternStepsMulti, NULL, NULL));
#endif
  return ATtrue;
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
  
    return (int)ATgetInt((ATermInt)ATgetFirst((ATermList)arg));
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
  
    return (SE_Steps)ATgetNext((ATermList)arg);
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
/*{{{  inline ATbool SE_isMoveLeft(SE_Move arg) */

inline ATbool SE_isMoveLeft(SE_Move arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternMoveLeft);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SE_isMoveRight(SE_Move arg) */

inline ATbool SE_isMoveRight(SE_Move arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternMoveRight);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SE_isMoveUp(SE_Move arg) */

inline ATbool SE_isMoveUp(SE_Move arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternMoveUp);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SE_isMoveDown(SE_Move arg) */

inline ATbool SE_isMoveDown(SE_Move arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternMoveDown);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  SE_Editor SE_visitEditor(SE_Editor arg, SE_ParseTree (*acceptParseTree)(SE_ParseTree), SE_Focus (*acceptFocus)(SE_Focus), SE_FocusList (*acceptUnparsedFoci)(SE_FocusList), int (*acceptModified)(int), SE_SymbolList (*acceptStartSymbols)(SE_SymbolList)) */

SE_Editor SE_visitEditor(SE_Editor arg, SE_ParseTree (*acceptParseTree)(SE_ParseTree), SE_Focus (*acceptFocus)(SE_Focus), SE_FocusList (*acceptUnparsedFoci)(SE_FocusList), int (*acceptModified)(int), SE_SymbolList (*acceptStartSymbols)(SE_SymbolList))
{
  if (SE_isEditorDefault(arg)) {
    return SE_makeEditorDefault(
        acceptParseTree ? acceptParseTree(SE_getEditorParseTree(arg)) : SE_getEditorParseTree(arg),
        acceptFocus ? acceptFocus(SE_getEditorFocus(arg)) : SE_getEditorFocus(arg),
        acceptUnparsedFoci ? acceptUnparsedFoci(SE_getEditorUnparsedFoci(arg)) : SE_getEditorUnparsedFoci(arg),
        acceptModified ? acceptModified(SE_getEditorModified(arg)) : SE_getEditorModified(arg),
        acceptStartSymbols ? acceptStartSymbols(SE_getEditorStartSymbols(arg)) : SE_getEditorStartSymbols(arg));
  }
  ATabort("not a Editor: %t\n", arg);
  return (SE_Editor)NULL;
}

/*}}}  */
/*{{{  SE_Focus SE_visitFocus(SE_Focus arg, SE_Path (*acceptPath)(SE_Path), char* (*acceptSort)(char*), SE_Area (*acceptArea)(SE_Area), int (*acceptUnparsed)(int)) */

SE_Focus SE_visitFocus(SE_Focus arg, SE_Path (*acceptPath)(SE_Path), char* (*acceptSort)(char*), SE_Area (*acceptArea)(SE_Area), int (*acceptUnparsed)(int))
{
  if (SE_isFocusEmpty(arg)) {
    return SE_makeFocusEmpty();
  }
  if (SE_isFocusNotEmpty(arg)) {
    return SE_makeFocusNotEmpty(
        acceptPath ? acceptPath(SE_getFocusPath(arg)) : SE_getFocusPath(arg),
        acceptSort ? acceptSort(SE_getFocusSort(arg)) : SE_getFocusSort(arg),
        acceptArea ? acceptArea(SE_getFocusArea(arg)) : SE_getFocusArea(arg),
        acceptUnparsed ? acceptUnparsed(SE_getFocusUnparsed(arg)) : SE_getFocusUnparsed(arg));
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
/*{{{  SE_SymbolList SE_visitSymbolList(SE_SymbolList arg, char* (*acceptHead)(char*)) */

SE_SymbolList SE_visitSymbolList(SE_SymbolList arg, char* (*acceptHead)(char*))
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
  if (SE_isPathTree(arg)) {
    return SE_makePathTree(
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
