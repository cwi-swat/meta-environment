#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "StructureEditor.h"

/*{{{  conversion functions */

ATerm SE_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

char *SE_charsToString(ATerm arg)
{
  ATermList list = (ATermList) arg;
  int len = ATgetLength(list);
  int i;
  char *str;

  str = (char *) malloc(len+1);
  if (str == NULL) {
      return NULL;
  }

  for (i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    str[i] = (char) ATgetInt((ATermInt) ATgetFirst(list));
  }
  str[i] = '\0';

  return str;
}


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _SE_Direction;
typedef struct ATerm _SE_StructureEditor;

/*}}}  */

/*{{{  void SE_initStructureEditorApi(void) */

void SE_initStructureEditorApi(void)
{
  init_StructureEditor_dict();
}

/*}}}  */

/*{{{  protect functions */

void SE_protectDirection(SE_Direction *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void SE_protectStructureEditor(SE_StructureEditor *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  SE_Direction SE_DirectionFromTerm(ATerm t) */

SE_Direction SE_DirectionFromTerm(ATerm t)
{
  return (SE_Direction)t;
}

/*}}}  */
/*{{{  ATerm SE_DirectionToTerm(SE_Direction arg) */

ATerm SE_DirectionToTerm(SE_Direction arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SE_StructureEditor SE_StructureEditorFromTerm(ATerm t) */

SE_StructureEditor SE_StructureEditorFromTerm(ATerm t)
{
  return (SE_StructureEditor)t;
}

/*}}}  */
/*{{{  ATerm SE_StructureEditorToTerm(SE_StructureEditor arg) */

ATerm SE_StructureEditorToTerm(SE_StructureEditor arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */

/*{{{  SE_Direction SE_makeDirectionUp() */

SE_Direction SE_makeDirectionUp()
{
  return (SE_Direction)(ATerm)ATmakeAppl0(SE_afun0);
}

/*}}}  */
/*{{{  SE_Direction SE_makeDirectionLeft() */

SE_Direction SE_makeDirectionLeft()
{
  return (SE_Direction)(ATerm)ATmakeAppl0(SE_afun1);
}

/*}}}  */
/*{{{  SE_Direction SE_makeDirectionDown() */

SE_Direction SE_makeDirectionDown()
{
  return (SE_Direction)(ATerm)ATmakeAppl0(SE_afun2);
}

/*}}}  */
/*{{{  SE_Direction SE_makeDirectionRight() */

SE_Direction SE_makeDirectionRight()
{
  return (SE_Direction)(ATerm)ATmakeAppl0(SE_afun3);
}

/*}}}  */
/*{{{  SE_StructureEditor SE_makeStructureEditorDefault(SE_ParseTree parseTree, int cursor) */

SE_StructureEditor SE_makeStructureEditorDefault(SE_ParseTree parseTree, int cursor)
{
  return (SE_StructureEditor)(ATerm)ATmakeAppl2(SE_afun4, (ATerm) parseTree, (ATerm) (ATerm) ATmakeInt(cursor));
}

/*}}}  */
/*{{{  SE_StructureEditor SE_makeStructureEditorUnedited(SE_ParseTree parseTree) */

SE_StructureEditor SE_makeStructureEditorUnedited(SE_ParseTree parseTree)
{
  return (SE_StructureEditor)(ATerm)ATmakeAppl1(SE_afun5, (ATerm) parseTree);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool SE_isEqualDirection(SE_Direction arg0, SE_Direction arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SE_isEqualStructureEditor(SE_StructureEditor arg0, SE_StructureEditor arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  SE_Direction accessors */

/*{{{  ATbool SE_isValidDirection(SE_Direction arg) */

ATbool SE_isValidDirection(SE_Direction arg)
{
  if (SE_isDirectionUp(arg)) {
    return ATtrue;
  }
  else if (SE_isDirectionLeft(arg)) {
    return ATtrue;
  }
  else if (SE_isDirectionDown(arg)) {
    return ATtrue;
  }
  else if (SE_isDirectionRight(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SE_isDirectionUp(SE_Direction arg) */

inline ATbool SE_isDirectionUp(SE_Direction arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternDirectionUp);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SE_isDirectionLeft(SE_Direction arg) */

inline ATbool SE_isDirectionLeft(SE_Direction arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternDirectionLeft);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SE_isDirectionDown(SE_Direction arg) */

inline ATbool SE_isDirectionDown(SE_Direction arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternDirectionDown);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SE_isDirectionRight(SE_Direction arg) */

inline ATbool SE_isDirectionRight(SE_Direction arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternDirectionRight);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  SE_StructureEditor accessors */

/*{{{  ATbool SE_isValidStructureEditor(SE_StructureEditor arg) */

ATbool SE_isValidStructureEditor(SE_StructureEditor arg)
{
  if (SE_isStructureEditorDefault(arg)) {
    return ATtrue;
  }
  else if (SE_isStructureEditorUnedited(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SE_isStructureEditorDefault(SE_StructureEditor arg) */

inline ATbool SE_isStructureEditorDefault(SE_StructureEditor arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternStructureEditorDefault, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SE_isStructureEditorUnedited(SE_StructureEditor arg) */

inline ATbool SE_isStructureEditorUnedited(SE_StructureEditor arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternStructureEditorUnedited, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SE_hasStructureEditorParseTree(SE_StructureEditor arg) */

ATbool SE_hasStructureEditorParseTree(SE_StructureEditor arg)
{
  if (SE_isStructureEditorDefault(arg)) {
    return ATtrue;
  }
  else if (SE_isStructureEditorUnedited(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SE_ParseTree SE_getStructureEditorParseTree(SE_StructureEditor arg) */

SE_ParseTree SE_getStructureEditorParseTree(SE_StructureEditor arg)
{
  if (SE_isStructureEditorDefault(arg)) {
    return (SE_ParseTree)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (SE_ParseTree)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  SE_StructureEditor SE_setStructureEditorParseTree(SE_StructureEditor arg, SE_ParseTree parseTree) */

SE_StructureEditor SE_setStructureEditorParseTree(SE_StructureEditor arg, SE_ParseTree parseTree)
{
  if (SE_isStructureEditorDefault(arg)) {
    return (SE_StructureEditor)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) parseTree), 0);
  }
  else if (SE_isStructureEditorUnedited(arg)) {
    return (SE_StructureEditor)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) parseTree), 0);
  }

  ATabort("StructureEditor has no ParseTree: %t\n", arg);
  return (SE_StructureEditor)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasStructureEditorCursor(SE_StructureEditor arg) */

ATbool SE_hasStructureEditorCursor(SE_StructureEditor arg)
{
  if (SE_isStructureEditorDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int SE_getStructureEditorCursor(SE_StructureEditor arg) */

int SE_getStructureEditorCursor(SE_StructureEditor arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SE_StructureEditor SE_setStructureEditorCursor(SE_StructureEditor arg, int cursor) */

SE_StructureEditor SE_setStructureEditorCursor(SE_StructureEditor arg, int cursor)
{
  if (SE_isStructureEditorDefault(arg)) {
    return (SE_StructureEditor)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(cursor)), 1);
  }

  ATabort("StructureEditor has no Cursor: %t\n", arg);
  return (SE_StructureEditor)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  SE_Direction SE_visitDirection(SE_Direction arg) */

SE_Direction SE_visitDirection(SE_Direction arg)
{
  if (SE_isDirectionUp(arg)) {
    return SE_makeDirectionUp();
  }
  if (SE_isDirectionLeft(arg)) {
    return SE_makeDirectionLeft();
  }
  if (SE_isDirectionDown(arg)) {
    return SE_makeDirectionDown();
  }
  if (SE_isDirectionRight(arg)) {
    return SE_makeDirectionRight();
  }
  ATabort("not a Direction: %t\n", arg);
  return (SE_Direction)NULL;
}

/*}}}  */
/*{{{  SE_StructureEditor SE_visitStructureEditor(SE_StructureEditor arg, SE_ParseTree (*acceptParseTree)(SE_ParseTree), int (*acceptCursor)(int)) */

SE_StructureEditor SE_visitStructureEditor(SE_StructureEditor arg, SE_ParseTree (*acceptParseTree)(SE_ParseTree), int (*acceptCursor)(int))
{
  if (SE_isStructureEditorDefault(arg)) {
    return SE_makeStructureEditorDefault(
        acceptParseTree ? acceptParseTree(SE_getStructureEditorParseTree(arg)) : SE_getStructureEditorParseTree(arg),
        acceptCursor ? acceptCursor(SE_getStructureEditorCursor(arg)) : SE_getStructureEditorCursor(arg));
  }
  if (SE_isStructureEditorUnedited(arg)) {
    return SE_makeStructureEditorUnedited(
        acceptParseTree ? acceptParseTree(SE_getStructureEditorParseTree(arg)) : SE_getStructureEditorParseTree(arg));
  }
  ATabort("not a StructureEditor: %t\n", arg);
  return (SE_StructureEditor)NULL;
}

/*}}}  */

/*}}}  */
