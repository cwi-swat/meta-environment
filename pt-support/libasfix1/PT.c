#include <aterm2.h>
#include <deprecated.h>
#include "PT.h"

/*{{{  typedefs */

typedef struct ATerm _PT_AsFix;
typedef struct ATerm _PT_ModuleName;
typedef struct ATerm _PT_Layout;

/*}}}  */

/*{{{  void PT_initPTApi(void) */

void PT_initPTApi(void)
{
  init_PT_dict();
}

/*}}}  */

/*{{{  PT_AsFix PT_makeAsFixFromTerm(ATerm t) */

PT_AsFix PT_makeAsFixFromTerm(ATerm t)
{
  return (PT_AsFix)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromAsFix(PT_AsFix arg) */

ATerm PT_makeTermFromAsFix(PT_AsFix arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_ModuleName PT_makeModuleNameFromTerm(ATerm t) */

PT_ModuleName PT_makeModuleNameFromTerm(ATerm t)
{
  return (PT_ModuleName)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromModuleName(PT_ModuleName arg) */

ATerm PT_makeTermFromModuleName(PT_ModuleName arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Layout PT_makeLayoutFromTerm(ATerm t) */

PT_Layout PT_makeLayoutFromTerm(ATerm t)
{
  return (PT_Layout)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromLayout(PT_Layout arg) */

ATerm PT_makeTermFromLayout(PT_Layout arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*{{{  PT_AsFix PT_makeAsFixTree(PT_Layout wsAfterTerm, PT_Layout wsAfterPath, PT_ModuleName moduleName, PT_Layout wsBeforeTree, PT_Tree tree, PT_Layout wsAfterTree) */

PT_AsFix PT_makeAsFixTree(PT_Layout wsAfterTerm, PT_Layout wsAfterPath, PT_ModuleName moduleName, PT_Layout wsBeforeTree, PT_Tree tree, PT_Layout wsAfterTree)
{
  return (PT_AsFix)ATmakeTerm(PT_patternAsFixTree, wsAfterTerm, wsAfterPath, moduleName, wsBeforeTree, tree, wsAfterTree);
}

/*}}}  */
/*{{{  PT_ModuleName PT_makeModuleNameDefault(PT_String id) */

PT_ModuleName PT_makeModuleNameDefault(PT_String id)
{
  return (PT_ModuleName)ATmakeTerm(PT_patternModuleNameDefault, id);
}

/*}}}  */
/*{{{  PT_Layout PT_makeLayoutEmpty() */

PT_Layout PT_makeLayoutEmpty()
{
  return (PT_Layout)ATmakeTerm(PT_patternLayoutEmpty);
}

/*}}}  */
/*{{{  PT_Layout PT_makeLayoutNewline() */

PT_Layout PT_makeLayoutNewline()
{
  return (PT_Layout)ATmakeTerm(PT_patternLayoutNewline);
}

/*}}}  */
/*{{{  PT_Layout PT_makeLayoutSpace() */

PT_Layout PT_makeLayoutSpace()
{
  return (PT_Layout)ATmakeTerm(PT_patternLayoutSpace);
}

/*}}}  */

/*{{{  equality functions */

ATbool PT_isEqualAsFix(PT_AsFix arg0, PT_AsFix arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualModuleName(PT_ModuleName arg0, PT_ModuleName arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualLayout(PT_Layout arg0, PT_Layout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  PT_AsFix accessor implementations */

/*{{{  ATbool PT_isValidAsFix(PT_AsFix arg) */

ATbool PT_isValidAsFix(PT_AsFix arg)
{
  if (PT_isAsFixTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isAsFixTree(PT_AsFix arg) */

ATbool PT_isAsFixTree(PT_AsFix arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAsFixTree, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasAsFixWsAfterPath(PT_AsFix arg) */

ATbool PT_hasAsFixWsAfterPath(PT_AsFix arg)
{
  if (PT_isAsFixTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Layout PT_getAsFixWsAfterPath(PT_AsFix arg) */

PT_Layout PT_getAsFixWsAfterPath(PT_AsFix arg)
{
  if (PT_isAsFixTree(arg)) {
    return (PT_Layout)ATgetArgument((ATermAppl)arg, 3);
  }

  ATabort("AsFix has no WsAfterPath: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_AsFix PT_setAsFixWsAfterPath(PT_AsFix arg, PT_Layout wsAfterPath) */

PT_AsFix PT_setAsFixWsAfterPath(PT_AsFix arg, PT_Layout wsAfterPath)
{
  if (PT_isAsFixTree(arg)) {
    return (PT_AsFix)ATsetArgument((ATermAppl)arg, (ATerm)wsAfterPath, 3);
  }

  ATabort("AsFix has no WsAfterPath: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasAsFixWsAfterTree(PT_AsFix arg) */

ATbool PT_hasAsFixWsAfterTree(PT_AsFix arg)
{
  if (PT_isAsFixTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Layout PT_getAsFixWsAfterTree(PT_AsFix arg) */

PT_Layout PT_getAsFixWsAfterTree(PT_AsFix arg)
{
  if (PT_isAsFixTree(arg)) {
    return (PT_Layout)ATgetArgument((ATermAppl)arg, 7);
  }

  ATabort("AsFix has no WsAfterTree: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_AsFix PT_setAsFixWsAfterTree(PT_AsFix arg, PT_Layout wsAfterTree) */

PT_AsFix PT_setAsFixWsAfterTree(PT_AsFix arg, PT_Layout wsAfterTree)
{
  if (PT_isAsFixTree(arg)) {
    return (PT_AsFix)ATsetArgument((ATermAppl)arg, (ATerm)wsAfterTree, 7);
  }

  ATabort("AsFix has no WsAfterTree: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasAsFixWsBeforeTree(PT_AsFix arg) */

ATbool PT_hasAsFixWsBeforeTree(PT_AsFix arg)
{
  if (PT_isAsFixTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Layout PT_getAsFixWsBeforeTree(PT_AsFix arg) */

PT_Layout PT_getAsFixWsBeforeTree(PT_AsFix arg)
{
  if (PT_isAsFixTree(arg)) {
    return (PT_Layout)ATgetArgument((ATermAppl)arg, 5);
  }

  ATabort("AsFix has no WsBeforeTree: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_AsFix PT_setAsFixWsBeforeTree(PT_AsFix arg, PT_Layout wsBeforeTree) */

PT_AsFix PT_setAsFixWsBeforeTree(PT_AsFix arg, PT_Layout wsBeforeTree)
{
  if (PT_isAsFixTree(arg)) {
    return (PT_AsFix)ATsetArgument((ATermAppl)arg, (ATerm)wsBeforeTree, 5);
  }

  ATabort("AsFix has no WsBeforeTree: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasAsFixWsAfterTerm(PT_AsFix arg) */

ATbool PT_hasAsFixWsAfterTerm(PT_AsFix arg)
{
  if (PT_isAsFixTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Layout PT_getAsFixWsAfterTerm(PT_AsFix arg) */

PT_Layout PT_getAsFixWsAfterTerm(PT_AsFix arg)
{
  if (PT_isAsFixTree(arg)) {
    return (PT_Layout)ATgetArgument((ATermAppl)arg, 1);
  }

  ATabort("AsFix has no WsAfterTerm: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_AsFix PT_setAsFixWsAfterTerm(PT_AsFix arg, PT_Layout wsAfterTerm) */

PT_AsFix PT_setAsFixWsAfterTerm(PT_AsFix arg, PT_Layout wsAfterTerm)
{
  if (PT_isAsFixTree(arg)) {
    return (PT_AsFix)ATsetArgument((ATermAppl)arg, (ATerm)wsAfterTerm, 1);
  }

  ATabort("AsFix has no WsAfterTerm: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasAsFixModuleName(PT_AsFix arg) */

ATbool PT_hasAsFixModuleName(PT_AsFix arg)
{
  if (PT_isAsFixTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_ModuleName PT_getAsFixModuleName(PT_AsFix arg) */

PT_ModuleName PT_getAsFixModuleName(PT_AsFix arg)
{
  if (PT_isAsFixTree(arg)) {
    return (PT_ModuleName)ATgetArgument((ATermAppl)arg, 4);
  }

  ATabort("AsFix has no ModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_AsFix PT_setAsFixModuleName(PT_AsFix arg, PT_ModuleName moduleName) */

PT_AsFix PT_setAsFixModuleName(PT_AsFix arg, PT_ModuleName moduleName)
{
  if (PT_isAsFixTree(arg)) {
    return (PT_AsFix)ATsetArgument((ATermAppl)arg, (ATerm)moduleName, 4);
  }

  ATabort("AsFix has no ModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasAsFixTree(PT_AsFix arg) */

ATbool PT_hasAsFixTree(PT_AsFix arg)
{
  if (PT_isAsFixTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Tree PT_getAsFixTree(PT_AsFix arg) */

PT_Tree PT_getAsFixTree(PT_AsFix arg)
{
  if (PT_isAsFixTree(arg)) {
    return (PT_Tree)ATgetArgument((ATermAppl)arg, 6);
  }

  ATabort("AsFix has no Tree: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_AsFix PT_setAsFixTree(PT_AsFix arg, PT_Tree tree) */

PT_AsFix PT_setAsFixTree(PT_AsFix arg, PT_Tree tree)
{
  if (PT_isAsFixTree(arg)) {
    return (PT_AsFix)ATsetArgument((ATermAppl)arg, (ATerm)tree, 6);
  }

  ATabort("AsFix has no Tree: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_ModuleName accessor implementations */

/*{{{  ATbool PT_isValidModuleName(PT_ModuleName arg) */

ATbool PT_isValidModuleName(PT_ModuleName arg)
{
  if (PT_isModuleNameDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isModuleNameDefault(PT_ModuleName arg) */

ATbool PT_isModuleNameDefault(PT_ModuleName arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternModuleNameDefault, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasModuleNameId(PT_ModuleName arg) */

ATbool PT_hasModuleNameId(PT_ModuleName arg)
{
  if (PT_isModuleNameDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_String PT_getModuleNameId(PT_ModuleName arg) */

PT_String PT_getModuleNameId(PT_ModuleName arg)
{
  if (PT_isModuleNameDefault(arg)) {
    return (PT_String)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("ModuleName has no Id: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_ModuleName PT_setModuleNameId(PT_ModuleName arg, PT_String id) */

PT_ModuleName PT_setModuleNameId(PT_ModuleName arg, PT_String id)
{
  if (PT_isModuleNameDefault(arg)) {
    return (PT_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)id, 0);
  }

  ATabort("ModuleName has no Id: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Layout accessor implementations */

/*{{{  ATbool PT_isValidLayout(PT_Layout arg) */

ATbool PT_isValidLayout(PT_Layout arg)
{
  if (PT_isLayoutEmpty(arg)) {
    return ATtrue;
  }
  else if (PT_isLayoutNewline(arg)) {
    return ATtrue;
  }
  else if (PT_isLayoutSpace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isLayoutEmpty(PT_Layout arg) */

ATbool PT_isLayoutEmpty(PT_Layout arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternLayoutEmpty);
}

/*}}}  */
/*{{{  ATbool PT_isLayoutNewline(PT_Layout arg) */

ATbool PT_isLayoutNewline(PT_Layout arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternLayoutNewline);
}

/*}}}  */
/*{{{  ATbool PT_isLayoutSpace(PT_Layout arg) */

ATbool PT_isLayoutSpace(PT_Layout arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternLayoutSpace);
}

/*}}}  */

/*}}}  */
