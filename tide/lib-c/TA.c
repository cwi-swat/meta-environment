#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "TA.h"

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
/*{{{  constructors */

/*{{{  TA_Location TA_makeLocationLine(char * file, int line) */

TA_Location TA_makeLocationLine(char * file, int line)
{
  return (TA_Location)(ATerm)ATmakeAppl2(TA_afun0, (ATerm)ATmakeAppl0(ATmakeAFun(file, 0, ATtrue)), (ATerm)ATmakeInt(line));
}

/*}}}  */
/*{{{  TA_Location TA_makeLocationArea(char * file, int startLine, int startCol, int endLine, int endCol) */

TA_Location TA_makeLocationArea(char * file, int startLine, int startCol, int endLine, int endCol)
{
  return (TA_Location)(ATerm)ATmakeAppl5(TA_afun1, (ATerm)ATmakeAppl0(ATmakeAFun(file, 0, ATtrue)), (ATerm)ATmakeInt(startLine), (ATerm)ATmakeInt(startCol), (ATerm)ATmakeInt(endLine), (ATerm)ATmakeInt(endCol));
}

/*}}}  */
/*{{{  TA_Location TA_makeLocationLineCol(char * file, int line, int col) */

TA_Location TA_makeLocationLineCol(char * file, int line, int col)
{
  return (TA_Location)(ATerm)ATmakeAppl3(TA_afun2, (ATerm)ATmakeAppl0(ATmakeAFun(file, 0, ATtrue)), (ATerm)ATmakeInt(line), (ATerm)ATmakeInt(col));
}

/*}}}  */
/*{{{  TA_Location TA_makeLocationUnknown() */

TA_Location TA_makeLocationUnknown()
{
  return (TA_Location)(ATerm)ATmakeAppl0(TA_afun3);
}

/*}}}  */
/*{{{  TA_Port TA_makePortStep() */

TA_Port TA_makePortStep()
{
  return (TA_Port)(ATerm)ATmakeAppl0(TA_afun4);
}

/*}}}  */
/*{{{  TA_Port TA_makePortStopped() */

TA_Port TA_makePortStopped()
{
  return (TA_Port)(ATerm)ATmakeAppl0(TA_afun5);
}

/*}}}  */
/*{{{  TA_Port TA_makePortStarted() */

TA_Port TA_makePortStarted()
{
  return (TA_Port)(ATerm)ATmakeAppl0(TA_afun6);
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
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(TA_patternLocationLine)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, TA_patternLocationLine, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool TA_isLocationArea(TA_Location arg) */

inline ATbool TA_isLocationArea(TA_Location arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(TA_patternLocationArea)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, TA_patternLocationArea, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool TA_isLocationLineCol(TA_Location arg) */

inline ATbool TA_isLocationLineCol(TA_Location arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(TA_patternLocationLineCol)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, TA_patternLocationLineCol, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool TA_isLocationUnknown(TA_Location arg) */

inline ATbool TA_isLocationUnknown(TA_Location arg)
{
  return ATmatchTerm((ATerm)arg, TA_patternLocationUnknown);
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
/*{{{  char * TA_getLocationFile(TA_Location arg) */

char * TA_getLocationFile(TA_Location arg)
{
  if (TA_isLocationLine(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (TA_isLocationArea(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  TA_Location TA_setLocationFile(TA_Location arg, char * file) */

TA_Location TA_setLocationFile(TA_Location arg, char * file)
{
  if (TA_isLocationLine(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(file, 0, ATtrue)), 0);
  }
  else if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(file, 0, ATtrue)), 0);
  }
  else if (TA_isLocationLineCol(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(file, 0, ATtrue)), 0);
  }

  ATabort("Location has no File: %t\n", arg);
  return (TA_Location)NULL;
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
/*{{{  int TA_getLocationLine(TA_Location arg) */

int TA_getLocationLine(TA_Location arg)
{
  if (TA_isLocationLine(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  TA_Location TA_setLocationLine(TA_Location arg, int line) */

TA_Location TA_setLocationLine(TA_Location arg, int line)
{
  if (TA_isLocationLine(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(line), 1);
  }
  else if (TA_isLocationLineCol(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(line), 1);
  }

  ATabort("Location has no Line: %t\n", arg);
  return (TA_Location)NULL;
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
/*{{{  int TA_getLocationStartLine(TA_Location arg) */

int TA_getLocationStartLine(TA_Location arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  TA_Location TA_setLocationStartLine(TA_Location arg, int startLine) */

TA_Location TA_setLocationStartLine(TA_Location arg, int startLine)
{
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(startLine), 1);
  }

  ATabort("Location has no StartLine: %t\n", arg);
  return (TA_Location)NULL;
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
/*{{{  int TA_getLocationStartCol(TA_Location arg) */

int TA_getLocationStartCol(TA_Location arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  TA_Location TA_setLocationStartCol(TA_Location arg, int startCol) */

TA_Location TA_setLocationStartCol(TA_Location arg, int startCol)
{
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(startCol), 2);
  }

  ATabort("Location has no StartCol: %t\n", arg);
  return (TA_Location)NULL;
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
/*{{{  int TA_getLocationEndLine(TA_Location arg) */

int TA_getLocationEndLine(TA_Location arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 3));
}

/*}}}  */
/*{{{  TA_Location TA_setLocationEndLine(TA_Location arg, int endLine) */

TA_Location TA_setLocationEndLine(TA_Location arg, int endLine)
{
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(endLine), 3);
  }

  ATabort("Location has no EndLine: %t\n", arg);
  return (TA_Location)NULL;
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
/*{{{  int TA_getLocationEndCol(TA_Location arg) */

int TA_getLocationEndCol(TA_Location arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 4));
}

/*}}}  */
/*{{{  TA_Location TA_setLocationEndCol(TA_Location arg, int endCol) */

TA_Location TA_setLocationEndCol(TA_Location arg, int endCol)
{
  if (TA_isLocationArea(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(endCol), 4);
  }

  ATabort("Location has no EndCol: %t\n", arg);
  return (TA_Location)NULL;
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
/*{{{  int TA_getLocationCol(TA_Location arg) */

int TA_getLocationCol(TA_Location arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  TA_Location TA_setLocationCol(TA_Location arg, int col) */

TA_Location TA_setLocationCol(TA_Location arg, int col)
{
  if (TA_isLocationLineCol(arg)) {
    return (TA_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(col), 2);
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
  return ATmatchTerm((ATerm)arg, TA_patternPortStep);
}

/*}}}  */
/*{{{  inline ATbool TA_isPortStopped(TA_Port arg) */

inline ATbool TA_isPortStopped(TA_Port arg)
{
  return ATmatchTerm((ATerm)arg, TA_patternPortStopped);
}

/*}}}  */
/*{{{  inline ATbool TA_isPortStarted(TA_Port arg) */

inline ATbool TA_isPortStarted(TA_Port arg)
{
  return ATmatchTerm((ATerm)arg, TA_patternPortStarted);
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  TA_Location TA_visitLocation(TA_Location arg, char * (*acceptFile)(char *), int (*acceptLine)(int), int (*acceptStartLine)(int), int (*acceptStartCol)(int), int (*acceptEndLine)(int), int (*acceptEndCol)(int), int (*acceptCol)(int)) */

TA_Location TA_visitLocation(TA_Location arg, char * (*acceptFile)(char *), int (*acceptLine)(int), int (*acceptStartLine)(int), int (*acceptStartCol)(int), int (*acceptEndLine)(int), int (*acceptEndCol)(int), int (*acceptCol)(int))
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
        acceptEndCol ? acceptEndCol(TA_getLocationEndCol(arg)) : TA_getLocationEndCol(arg));
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
