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

typedef struct ATerm _SE_Area;
typedef struct ATerm _SE_Location;
typedef struct ATerm _SE_Direction;

/*}}}  */

/*{{{  void SE_initStructureEditorApi(void) */

void SE_initStructureEditorApi(void)
{
  init_StructureEditor_dict();
}

/*}}}  */

/*{{{  protect functions */

void SE_protectArea(SE_Area *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void SE_protectLocation(SE_Location *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void SE_protectDirection(SE_Direction *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

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
/*{{{  SE_Location SE_LocationFromTerm(ATerm t) */

SE_Location SE_LocationFromTerm(ATerm t)
{
  return (SE_Location)t;
}

/*}}}  */
/*{{{  ATerm SE_LocationToTerm(SE_Location arg) */

ATerm SE_LocationToTerm(SE_Location arg)
{
  return (ATerm)arg;
}

/*}}}  */
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

/*}}}  */
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */

/*{{{  SE_Area SE_makeAreaArea(int beginLine, int beginColumn, int endLine, int endColumn, int offset, int length) */

SE_Area SE_makeAreaArea(int beginLine, int beginColumn, int endLine, int endColumn, int offset, int length)
{
  return (SE_Area)(ATerm)ATmakeAppl6(SE_afun0, (ATerm) (ATerm) ATmakeInt(beginLine), (ATerm) (ATerm) ATmakeInt(beginColumn), (ATerm) (ATerm) ATmakeInt(endLine), (ATerm) (ATerm) ATmakeInt(endColumn), (ATerm) (ATerm) ATmakeInt(offset), (ATerm) (ATerm) ATmakeInt(length));
}

/*}}}  */
/*{{{  SE_Location SE_makeLocationFile(const char* filename) */

SE_Location SE_makeLocationFile(const char* filename)
{
  return (SE_Location)(ATerm)ATmakeAppl1(SE_afun1, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue)));
}

/*}}}  */
/*{{{  SE_Location SE_makeLocationAreaInFile(const char* filename, SE_Area Area) */

SE_Location SE_makeLocationAreaInFile(const char* filename, SE_Area Area)
{
  return (SE_Location)(ATerm)ATmakeAppl2(SE_afun2, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue)), (ATerm) Area);
}

/*}}}  */
/*{{{  SE_Direction SE_makeDirectionUp() */

SE_Direction SE_makeDirectionUp()
{
  return (SE_Direction)(ATerm)ATmakeAppl0(SE_afun3);
}

/*}}}  */
/*{{{  SE_Direction SE_makeDirectionLeft() */

SE_Direction SE_makeDirectionLeft()
{
  return (SE_Direction)(ATerm)ATmakeAppl0(SE_afun4);
}

/*}}}  */
/*{{{  SE_Direction SE_makeDirectionDown() */

SE_Direction SE_makeDirectionDown()
{
  return (SE_Direction)(ATerm)ATmakeAppl0(SE_afun5);
}

/*}}}  */
/*{{{  SE_Direction SE_makeDirectionRight() */

SE_Direction SE_makeDirectionRight()
{
  return (SE_Direction)(ATerm)ATmakeAppl0(SE_afun6);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool SE_isEqualArea(SE_Area arg0, SE_Area arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SE_isEqualLocation(SE_Location arg0, SE_Location arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SE_isEqualDirection(SE_Direction arg0, SE_Direction arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  SE_Area accessors */

/*{{{  ATbool SE_isValidArea(SE_Area arg) */

ATbool SE_isValidArea(SE_Area arg)
{
  if (SE_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SE_isAreaArea(SE_Area arg) */

inline ATbool SE_isAreaArea(SE_Area arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SE_patternAreaArea, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool SE_hasAreaBeginLine(SE_Area arg) */

ATbool SE_hasAreaBeginLine(SE_Area arg)
{
  if (SE_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int SE_getAreaBeginLine(SE_Area arg) */

int SE_getAreaBeginLine(SE_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  SE_Area SE_setAreaBeginLine(SE_Area arg, int beginLine) */

SE_Area SE_setAreaBeginLine(SE_Area arg, int beginLine)
{
  if (SE_isAreaArea(arg)) {
    return (SE_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(beginLine)), 0);
  }

  ATabort("Area has no BeginLine: %t\n", arg);
  return (SE_Area)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasAreaBeginColumn(SE_Area arg) */

ATbool SE_hasAreaBeginColumn(SE_Area arg)
{
  if (SE_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int SE_getAreaBeginColumn(SE_Area arg) */

int SE_getAreaBeginColumn(SE_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  SE_Area SE_setAreaBeginColumn(SE_Area arg, int beginColumn) */

SE_Area SE_setAreaBeginColumn(SE_Area arg, int beginColumn)
{
  if (SE_isAreaArea(arg)) {
    return (SE_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(beginColumn)), 1);
  }

  ATabort("Area has no BeginColumn: %t\n", arg);
  return (SE_Area)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasAreaEndLine(SE_Area arg) */

ATbool SE_hasAreaEndLine(SE_Area arg)
{
  if (SE_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int SE_getAreaEndLine(SE_Area arg) */

int SE_getAreaEndLine(SE_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  SE_Area SE_setAreaEndLine(SE_Area arg, int endLine) */

SE_Area SE_setAreaEndLine(SE_Area arg, int endLine)
{
  if (SE_isAreaArea(arg)) {
    return (SE_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endLine)), 2);
  }

  ATabort("Area has no EndLine: %t\n", arg);
  return (SE_Area)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasAreaEndColumn(SE_Area arg) */

ATbool SE_hasAreaEndColumn(SE_Area arg)
{
  if (SE_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int SE_getAreaEndColumn(SE_Area arg) */

int SE_getAreaEndColumn(SE_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 3));
}

/*}}}  */
/*{{{  SE_Area SE_setAreaEndColumn(SE_Area arg, int endColumn) */

SE_Area SE_setAreaEndColumn(SE_Area arg, int endColumn)
{
  if (SE_isAreaArea(arg)) {
    return (SE_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endColumn)), 3);
  }

  ATabort("Area has no EndColumn: %t\n", arg);
  return (SE_Area)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasAreaOffset(SE_Area arg) */

ATbool SE_hasAreaOffset(SE_Area arg)
{
  if (SE_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int SE_getAreaOffset(SE_Area arg) */

int SE_getAreaOffset(SE_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 4));
}

/*}}}  */
/*{{{  SE_Area SE_setAreaOffset(SE_Area arg, int offset) */

SE_Area SE_setAreaOffset(SE_Area arg, int offset)
{
  if (SE_isAreaArea(arg)) {
    return (SE_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(offset)), 4);
  }

  ATabort("Area has no Offset: %t\n", arg);
  return (SE_Area)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasAreaLength(SE_Area arg) */

ATbool SE_hasAreaLength(SE_Area arg)
{
  if (SE_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int SE_getAreaLength(SE_Area arg) */

int SE_getAreaLength(SE_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 5));
}

/*}}}  */
/*{{{  SE_Area SE_setAreaLength(SE_Area arg, int length) */

SE_Area SE_setAreaLength(SE_Area arg, int length)
{
  if (SE_isAreaArea(arg)) {
    return (SE_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(length)), 5);
  }

  ATabort("Area has no Length: %t\n", arg);
  return (SE_Area)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SE_Location accessors */

/*{{{  ATbool SE_isValidLocation(SE_Location arg) */

ATbool SE_isValidLocation(SE_Location arg)
{
  if (SE_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (SE_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SE_isLocationFile(SE_Location arg) */

inline ATbool SE_isLocationFile(SE_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternLocationFile, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SE_isLocationAreaInFile(SE_Location arg) */

inline ATbool SE_isLocationAreaInFile(SE_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SE_patternLocationAreaInFile, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SE_hasLocationFilename(SE_Location arg) */

ATbool SE_hasLocationFilename(SE_Location arg)
{
  if (SE_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (SE_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* SE_getLocationFilename(SE_Location arg) */

char* SE_getLocationFilename(SE_Location arg)
{
  if (SE_isLocationFile(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  SE_Location SE_setLocationFilename(SE_Location arg, const char* filename) */

SE_Location SE_setLocationFilename(SE_Location arg, const char* filename)
{
  if (SE_isLocationFile(arg)) {
    return (SE_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue))), 0);
  }
  else if (SE_isLocationAreaInFile(arg)) {
    return (SE_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue))), 0);
  }

  ATabort("Location has no Filename: %t\n", arg);
  return (SE_Location)NULL;
}

/*}}}  */
/*{{{  ATbool SE_hasLocationArea(SE_Location arg) */

ATbool SE_hasLocationArea(SE_Location arg)
{
  if (SE_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SE_Area SE_getLocationArea(SE_Location arg) */

SE_Area SE_getLocationArea(SE_Location arg)
{
  
    return (SE_Area)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  SE_Location SE_setLocationArea(SE_Location arg, SE_Area Area) */

SE_Location SE_setLocationArea(SE_Location arg, SE_Area Area)
{
  if (SE_isLocationAreaInFile(arg)) {
    return (SE_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Area), 1);
  }

  ATabort("Location has no Area: %t\n", arg);
  return (SE_Location)NULL;
}

/*}}}  */

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
/*{{{  sort visitors */

/*{{{  SE_Area SE_visitArea(SE_Area arg, int (*acceptBeginLine)(int), int (*acceptBeginColumn)(int), int (*acceptEndLine)(int), int (*acceptEndColumn)(int), int (*acceptOffset)(int), int (*acceptLength)(int)) */

SE_Area SE_visitArea(SE_Area arg, int (*acceptBeginLine)(int), int (*acceptBeginColumn)(int), int (*acceptEndLine)(int), int (*acceptEndColumn)(int), int (*acceptOffset)(int), int (*acceptLength)(int))
{
  if (SE_isAreaArea(arg)) {
    return SE_makeAreaArea(
        acceptBeginLine ? acceptBeginLine(SE_getAreaBeginLine(arg)) : SE_getAreaBeginLine(arg),
        acceptBeginColumn ? acceptBeginColumn(SE_getAreaBeginColumn(arg)) : SE_getAreaBeginColumn(arg),
        acceptEndLine ? acceptEndLine(SE_getAreaEndLine(arg)) : SE_getAreaEndLine(arg),
        acceptEndColumn ? acceptEndColumn(SE_getAreaEndColumn(arg)) : SE_getAreaEndColumn(arg),
        acceptOffset ? acceptOffset(SE_getAreaOffset(arg)) : SE_getAreaOffset(arg),
        acceptLength ? acceptLength(SE_getAreaLength(arg)) : SE_getAreaLength(arg));
  }
  ATabort("not a Area: %t\n", arg);
  return (SE_Area)NULL;
}

/*}}}  */
/*{{{  SE_Location SE_visitLocation(SE_Location arg, char* (*acceptFilename)(char*), SE_Area (*acceptArea)(SE_Area)) */

SE_Location SE_visitLocation(SE_Location arg, char* (*acceptFilename)(char*), SE_Area (*acceptArea)(SE_Area))
{
  if (SE_isLocationFile(arg)) {
    return SE_makeLocationFile(
        acceptFilename ? acceptFilename(SE_getLocationFilename(arg)) : SE_getLocationFilename(arg));
  }
  if (SE_isLocationAreaInFile(arg)) {
    return SE_makeLocationAreaInFile(
        acceptFilename ? acceptFilename(SE_getLocationFilename(arg)) : SE_getLocationFilename(arg),
        acceptArea ? acceptArea(SE_getLocationArea(arg)) : SE_getLocationArea(arg));
  }
  ATabort("not a Location: %t\n", arg);
  return (SE_Location)NULL;
}

/*}}}  */
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

/*}}}  */
