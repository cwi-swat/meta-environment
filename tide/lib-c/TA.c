#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "TA.h"

/*{{{  conversion functions */

ATerm TA_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

char *TA_charsToString(ATerm arg)
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

typedef struct ATerm _TA_Location;
typedef struct ATerm _TA_Port;

/*}}}  */

/*{{{  void TA_initTAApi(void) */

void TA_initTAApi(void)
{
  init_TA_dict();
}

/*}}}  */

/*{{{  protect functions */

void TA_protectLocation(TA_Location *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void TA_protectPort(TA_Port *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  TA_Location TA_LocationFromTerm(ATerm t) */

TA_Location TA_LocationFromTerm(ATerm t)
{
  return (TA_Location)t;
}

/*}}}  */
/*{{{  ATerm TA_LocationToTerm(TA_Location arg) */

ATerm TA_LocationToTerm(TA_Location arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  TA_Port TA_PortFromTerm(ATerm t) */

TA_Port TA_PortFromTerm(ATerm t)
{
  return (TA_Port)t;
}

/*}}}  */
/*{{{  ATerm TA_PortToTerm(TA_Port arg) */

ATerm TA_PortToTerm(TA_Port arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */

/*{{{  TA_Location TA_makeLocationLine(const char* file, int line) */

TA_Location TA_makeLocationLine(const char* file, int line)
{
  return (TA_Location)(ATerm)ATmakeAppl2(TA_afun0, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(file, 0, ATtrue)), (ATerm) (ATerm) ATmakeInt(line));
}

/*}}}  */
/*{{{  TA_Location TA_makeLocationArea(const char* file, int startLine, int startCol, int endLine, int endCol, int offset, int length) */

TA_Location TA_makeLocationArea(const char* file, int startLine, int startCol, int endLine, int endCol, int offset, int length)
{
  return (TA_Location)(ATerm)ATmakeAppl2(TA_afun1, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(file, 0, ATtrue)), (ATerm)ATmakeAppl6(TA_afun2, (ATerm) (ATerm) ATmakeInt(startLine), (ATerm) (ATerm) ATmakeInt(startCol), (ATerm) (ATerm) ATmakeInt(endLine), (ATerm) (ATerm) ATmakeInt(endCol), (ATerm) (ATerm) ATmakeInt(offset), (ATerm) (ATerm) ATmakeInt(length)));
}

/*}}}  */
/*{{{  TA_Location TA_makeLocationLineCol(const char* file, int line, int col) */

TA_Location TA_makeLocationLineCol(const char* file, int line, int col)
{
  return (TA_Location)(ATerm)ATmakeAppl3(TA_afun3, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(file, 0, ATtrue)), (ATerm) (ATerm) ATmakeInt(line), (ATerm) (ATerm) ATmakeInt(col));
}

/*}}}  */
/*{{{  TA_Location TA_makeLocationUnknown(void) */

TA_Location TA_makeLocationUnknown(void)
{
  return (TA_Location)(ATerm)ATmakeAppl0(TA_afun4);
}

/*}}}  */
/*{{{  TA_Port TA_makePortStep(void) */

TA_Port TA_makePortStep(void)
{
  return (TA_Port)(ATerm)ATmakeAppl0(TA_afun5);
}

/*}}}  */
/*{{{  TA_Port TA_makePortStopped(void) */

TA_Port TA_makePortStopped(void)
{
  return (TA_Port)(ATerm)ATmakeAppl0(TA_afun6);
}

/*}}}  */
/*{{{  TA_Port TA_makePortStarted(void) */

TA_Port TA_makePortStarted(void)
{
  return (TA_Port)(ATerm)ATmakeAppl0(TA_afun7);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool TA_isEqualLocation(TA_Location arg0, TA_Location arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool TA_isEqualPort(TA_Port arg0, TA_Port arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  TA_Location accessors */

/*{{{  ATbool TA_isValidLocation(TA_Location arg) */

ATbool TA_isValidLocation(TA_Location arg)
{
  if (TA_isLocationLine(arg)) {
    return ATtrue;
  }
  else if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (TA_isLocationLineCol(arg)) {
    return ATtrue;
  }
  else if (TA_isLocationUnknown(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool TA_isLocationLine(TA_Location arg) */

inline ATbool TA_isLocationLine(TA_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TA_patternLocationLine, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TA_isLocationArea(TA_Location arg) */

inline ATbool TA_isLocationArea(TA_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TA_patternLocationArea, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TA_isLocationLineCol(TA_Location arg) */

inline ATbool TA_isLocationLineCol(TA_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TA_patternLocationLineCol, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TA_isLocationUnknown(TA_Location arg) */

inline ATbool TA_isLocationUnknown(TA_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TA_patternLocationUnknown);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool TA_hasLocationFile(TA_Location arg) */

ATbool TA_hasLocationFile(TA_Location arg)
{
  if (TA_isLocationLine(arg)) {
    return ATtrue;
  }
  else if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (TA_isLocationLineCol(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool TA_hasLocationLine(TA_Location arg) */

ATbool TA_hasLocationLine(TA_Location arg)
{
  if (TA_isLocationLine(arg)) {
    return ATtrue;
  }
  else if (TA_isLocationLineCol(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool TA_hasLocationStartLine(TA_Location arg) */

ATbool TA_hasLocationStartLine(TA_Location arg)
{
  if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool TA_hasLocationStartCol(TA_Location arg) */

ATbool TA_hasLocationStartCol(TA_Location arg)
{
  if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool TA_hasLocationEndLine(TA_Location arg) */

ATbool TA_hasLocationEndLine(TA_Location arg)
{
  if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool TA_hasLocationEndCol(TA_Location arg) */

ATbool TA_hasLocationEndCol(TA_Location arg)
{
  if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool TA_hasLocationOffset(TA_Location arg) */

ATbool TA_hasLocationOffset(TA_Location arg)
{
  if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool TA_hasLocationLength(TA_Location arg) */

ATbool TA_hasLocationLength(TA_Location arg)
{
  if (TA_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool TA_hasLocationCol(TA_Location arg) */

ATbool TA_hasLocationCol(TA_Location arg)
{
  if (TA_isLocationLineCol(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* TA_getLocationFile(TA_Location arg) */

char* TA_getLocationFile(TA_Location arg)
{
  if (TA_isLocationLine(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (TA_isLocationArea(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  int TA_getLocationLine(TA_Location arg) */

int TA_getLocationLine(TA_Location arg)
{
  if (TA_isLocationLine(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  int TA_getLocationStartLine(TA_Location arg) */

int TA_getLocationStartLine(TA_Location arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), 0));
}

/*}}}  */
/*{{{  int TA_getLocationStartCol(TA_Location arg) */

int TA_getLocationStartCol(TA_Location arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), 1));
}

/*}}}  */
/*{{{  int TA_getLocationEndLine(TA_Location arg) */

int TA_getLocationEndLine(TA_Location arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), 2));
}

/*}}}  */
/*{{{  int TA_getLocationEndCol(TA_Location arg) */

int TA_getLocationEndCol(TA_Location arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), 3));
}

/*}}}  */
/*{{{  int TA_getLocationOffset(TA_Location arg) */

int TA_getLocationOffset(TA_Location arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), 4));
}

/*}}}  */
/*{{{  int TA_getLocationLength(TA_Location arg) */

int TA_getLocationLength(TA_Location arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), 5));
}

/*}}}  */
/*{{{  int TA_getLocationCol(TA_Location arg) */

int TA_getLocationCol(TA_Location arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  TA_Location TA_setLocationFile(TA_Location arg, const char* file) */

TA_Location TA_setLocationFile(TA_Location arg, const char* file)
{
  if (TA_isLocationLine(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(file, 0, ATtrue))), 0);
  }
  else if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(file, 0, ATtrue))), 0);
  }
  else if (TA_isLocationLineCol(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(file, 0, ATtrue))), 0);
  }

  ATabort("Location has no File: %t\n", arg);
  return (TA_Location)NULL;
}

/*}}}  */
/*{{{  TA_Location TA_setLocationLine(TA_Location arg, int line) */

TA_Location TA_setLocationLine(TA_Location arg, int line)
{
  if (TA_isLocationLine(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(line)), 1);
  }
  else if (TA_isLocationLineCol(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(line)), 1);
  }

  ATabort("Location has no Line: %t\n", arg);
  return (TA_Location)NULL;
}

/*}}}  */
/*{{{  TA_Location TA_setLocationStartLine(TA_Location arg, int startLine) */

TA_Location TA_setLocationStartLine(TA_Location arg, int startLine)
{
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) (ATerm) ATmakeInt(startLine)), 0), 1);
  }

  ATabort("Location has no StartLine: %t\n", arg);
  return (TA_Location)NULL;
}

/*}}}  */
/*{{{  TA_Location TA_setLocationStartCol(TA_Location arg, int startCol) */

TA_Location TA_setLocationStartCol(TA_Location arg, int startCol)
{
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) (ATerm) ATmakeInt(startCol)), 1), 1);
  }

  ATabort("Location has no StartCol: %t\n", arg);
  return (TA_Location)NULL;
}

/*}}}  */
/*{{{  TA_Location TA_setLocationEndLine(TA_Location arg, int endLine) */

TA_Location TA_setLocationEndLine(TA_Location arg, int endLine)
{
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) (ATerm) ATmakeInt(endLine)), 2), 1);
  }

  ATabort("Location has no EndLine: %t\n", arg);
  return (TA_Location)NULL;
}

/*}}}  */
/*{{{  TA_Location TA_setLocationEndCol(TA_Location arg, int endCol) */

TA_Location TA_setLocationEndCol(TA_Location arg, int endCol)
{
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) (ATerm) ATmakeInt(endCol)), 3), 1);
  }

  ATabort("Location has no EndCol: %t\n", arg);
  return (TA_Location)NULL;
}

/*}}}  */
/*{{{  TA_Location TA_setLocationOffset(TA_Location arg, int offset) */

TA_Location TA_setLocationOffset(TA_Location arg, int offset)
{
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) (ATerm) ATmakeInt(offset)), 4), 1);
  }

  ATabort("Location has no Offset: %t\n", arg);
  return (TA_Location)NULL;
}

/*}}}  */
/*{{{  TA_Location TA_setLocationLength(TA_Location arg, int length) */

TA_Location TA_setLocationLength(TA_Location arg, int length)
{
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) (ATerm) ATmakeInt(length)), 5), 1);
  }

  ATabort("Location has no Length: %t\n", arg);
  return (TA_Location)NULL;
}

/*}}}  */
/*{{{  TA_Location TA_setLocationCol(TA_Location arg, int col) */

TA_Location TA_setLocationCol(TA_Location arg, int col)
{
  if (TA_isLocationLineCol(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(col)), 2);
  }

  ATabort("Location has no Col: %t\n", arg);
  return (TA_Location)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  TA_Port accessors */

/*{{{  ATbool TA_isValidPort(TA_Port arg) */

ATbool TA_isValidPort(TA_Port arg)
{
  if (TA_isPortStep(arg)) {
    return ATtrue;
  }
  else if (TA_isPortStopped(arg)) {
    return ATtrue;
  }
  else if (TA_isPortStarted(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool TA_isPortStep(TA_Port arg) */

inline ATbool TA_isPortStep(TA_Port arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TA_patternPortStep);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TA_isPortStopped(TA_Port arg) */

inline ATbool TA_isPortStopped(TA_Port arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TA_patternPortStopped);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool TA_isPortStarted(TA_Port arg) */

inline ATbool TA_isPortStarted(TA_Port arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, TA_patternPortStarted);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  TA_Location TA_visitLocation(TA_Location arg, char* (*acceptFile)(char*), int (*acceptLine)(int), int (*acceptStartLine)(int), int (*acceptStartCol)(int), int (*acceptEndLine)(int), int (*acceptEndCol)(int), int (*acceptOffset)(int), int (*acceptLength)(int), int (*acceptCol)(int)) */

TA_Location TA_visitLocation(TA_Location arg, char* (*acceptFile)(char*), int (*acceptLine)(int), int (*acceptStartLine)(int), int (*acceptStartCol)(int), int (*acceptEndLine)(int), int (*acceptEndCol)(int), int (*acceptOffset)(int), int (*acceptLength)(int), int (*acceptCol)(int))
{
  if (TA_isLocationLine(arg)) {
    return TA_makeLocationLine(
        acceptFile ? acceptFile(TA_getLocationFile(arg)) : TA_getLocationFile(arg),
        acceptLine ? acceptLine(TA_getLocationLine(arg)) : TA_getLocationLine(arg));
  }
  if (TA_isLocationArea(arg)) {
    return TA_makeLocationArea(
        acceptFile ? acceptFile(TA_getLocationFile(arg)) : TA_getLocationFile(arg),
        acceptStartLine ? acceptStartLine(TA_getLocationStartLine(arg)) : TA_getLocationStartLine(arg),
        acceptStartCol ? acceptStartCol(TA_getLocationStartCol(arg)) : TA_getLocationStartCol(arg),
        acceptEndLine ? acceptEndLine(TA_getLocationEndLine(arg)) : TA_getLocationEndLine(arg),
        acceptEndCol ? acceptEndCol(TA_getLocationEndCol(arg)) : TA_getLocationEndCol(arg),
        acceptOffset ? acceptOffset(TA_getLocationOffset(arg)) : TA_getLocationOffset(arg),
        acceptLength ? acceptLength(TA_getLocationLength(arg)) : TA_getLocationLength(arg));
  }
  if (TA_isLocationLineCol(arg)) {
    return TA_makeLocationLineCol(
        acceptFile ? acceptFile(TA_getLocationFile(arg)) : TA_getLocationFile(arg),
        acceptLine ? acceptLine(TA_getLocationLine(arg)) : TA_getLocationLine(arg),
        acceptCol ? acceptCol(TA_getLocationCol(arg)) : TA_getLocationCol(arg));
  }
  if (TA_isLocationUnknown(arg)) {
    return TA_makeLocationUnknown();
  }
  ATabort("not a Location: %t\n", arg);
  return (TA_Location)NULL;
}

/*}}}  */
/*{{{  TA_Port TA_visitPort(TA_Port arg) */

TA_Port TA_visitPort(TA_Port arg)
{
  if (TA_isPortStep(arg)) {
    return TA_makePortStep();
  }
  if (TA_isPortStopped(arg)) {
    return TA_makePortStopped();
  }
  if (TA_isPortStarted(arg)) {
    return TA_makePortStarted();
  }
  ATabort("not a Port: %t\n", arg);
  return (TA_Port)NULL;
}

/*}}}  */

/*}}}  */
