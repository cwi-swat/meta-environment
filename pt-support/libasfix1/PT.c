#include <aterm2.h>
#include <deprecated.h>
#include "PT.h"

/*{{{  typedefs */

typedef struct ATerm _AsFix;
typedef struct ATerm _ModuleName;
typedef struct ATerm _Layout;

/*}}}  */

/*{{{  void initPTApi(void) */

void initPTApi(void)
{
  init_PT_dict();
}

/*}}}  */

/*{{{  AsFix makeAsFixFromTerm(ATerm t) */

AsFix makeAsFixFromTerm(ATerm t)
{
  return (AsFix)t;
}

/*}}}  */
/*{{{  ATerm makeTermFromAsFix(AsFix arg) */

ATerm makeTermFromAsFix(AsFix arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ModuleName makeModuleNameFromTerm(ATerm t) */

ModuleName makeModuleNameFromTerm(ATerm t)
{
  return (ModuleName)t;
}

/*}}}  */
/*{{{  ATerm makeTermFromModuleName(ModuleName arg) */

ATerm makeTermFromModuleName(ModuleName arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  Layout makeLayoutFromTerm(ATerm t) */

Layout makeLayoutFromTerm(ATerm t)
{
  return (Layout)t;
}

/*}}}  */
/*{{{  ATerm makeTermFromLayout(Layout arg) */

ATerm makeTermFromLayout(Layout arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*{{{  AsFix makeAsFixTree(ModuleName moduleName, Layout wsBeforeTree, Tree tree, Layout wsAfterTree) */

AsFix makeAsFixTree(ModuleName moduleName, Layout wsBeforeTree, Tree tree, Layout wsAfterTree)
{
  return (AsFix)ATmakeTerm(patternAsFixTree, moduleName, wsBeforeTree, tree, wsAfterTree);
}

/*}}}  */
/*{{{  ModuleName makeModuleNameDefault(String id) */

ModuleName makeModuleNameDefault(String id)
{
  return (ModuleName)ATmakeTerm(patternModuleNameDefault, id);
}

/*}}}  */
/*{{{  Layout makeLayoutEmpty() */

Layout makeLayoutEmpty()
{
  return (Layout)ATmakeTerm(patternLayoutEmpty);
}

/*}}}  */
/*{{{  Layout makeLayoutNewline() */

Layout makeLayoutNewline()
{
  return (Layout)ATmakeTerm(patternLayoutNewline);
}

/*}}}  */
/*{{{  Layout makeLayoutSpace() */

Layout makeLayoutSpace()
{
  return (Layout)ATmakeTerm(patternLayoutSpace);
}

/*}}}  */

/*{{{  AsFix accessor implementations */

/*{{{  ATbool isValidAsFix(AsFix arg) */

ATbool isValidAsFix(AsFix arg)
{
  if (isAsFixTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool isAsFixTree(AsFix arg) */

ATbool isAsFixTree(AsFix arg)
{
  return ATmatchTerm((ATerm)arg, patternAsFixTree, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool hasAsFixWsAfterTree(AsFix arg) */

ATbool hasAsFixWsAfterTree(AsFix arg)
{
  if (isAsFixTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Layout getAsFixWsAfterTree(AsFix arg) */

Layout getAsFixWsAfterTree(AsFix arg)
{
  if (isAsFixTree(arg)) {
    return (Layout)ATgetArgument((ATermAppl)arg, 7);
  }

  ATabort("AsFix has no WsAfterTree: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  AsFix setAsFixWsAfterTree(AsFix arg, Layout wsAfterTree) */

AsFix setAsFixWsAfterTree(AsFix arg, Layout wsAfterTree)
{
  if (isAsFixTree(arg)) {
    return (AsFix)ATsetArgument((ATermAppl)arg, (ATerm)wsAfterTree, 7);
  }

  ATabort("AsFix has no WsAfterTree: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool hasAsFixWsBeforeTree(AsFix arg) */

ATbool hasAsFixWsBeforeTree(AsFix arg)
{
  if (isAsFixTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Layout getAsFixWsBeforeTree(AsFix arg) */

Layout getAsFixWsBeforeTree(AsFix arg)
{
  if (isAsFixTree(arg)) {
    return (Layout)ATgetArgument((ATermAppl)arg, 5);
  }

  ATabort("AsFix has no WsBeforeTree: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  AsFix setAsFixWsBeforeTree(AsFix arg, Layout wsBeforeTree) */

AsFix setAsFixWsBeforeTree(AsFix arg, Layout wsBeforeTree)
{
  if (isAsFixTree(arg)) {
    return (AsFix)ATsetArgument((ATermAppl)arg, (ATerm)wsBeforeTree, 5);
  }

  ATabort("AsFix has no WsBeforeTree: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool hasAsFixModuleName(AsFix arg) */

ATbool hasAsFixModuleName(AsFix arg)
{
  if (isAsFixTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ModuleName getAsFixModuleName(AsFix arg) */

ModuleName getAsFixModuleName(AsFix arg)
{
  if (isAsFixTree(arg)) {
    return (ModuleName)ATgetArgument((ATermAppl)arg, 4);
  }

  ATabort("AsFix has no ModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  AsFix setAsFixModuleName(AsFix arg, ModuleName moduleName) */

AsFix setAsFixModuleName(AsFix arg, ModuleName moduleName)
{
  if (isAsFixTree(arg)) {
    return (AsFix)ATsetArgument((ATermAppl)arg, (ATerm)moduleName, 4);
  }

  ATabort("AsFix has no ModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool hasAsFixTree(AsFix arg) */

ATbool hasAsFixTree(AsFix arg)
{
  if (isAsFixTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Tree getAsFixTree(AsFix arg) */

Tree getAsFixTree(AsFix arg)
{
  if (isAsFixTree(arg)) {
    return (Tree)ATgetArgument((ATermAppl)arg, 6);
  }

  ATabort("AsFix has no Tree: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  AsFix setAsFixTree(AsFix arg, Tree tree) */

AsFix setAsFixTree(AsFix arg, Tree tree)
{
  if (isAsFixTree(arg)) {
    return (AsFix)ATsetArgument((ATermAppl)arg, (ATerm)tree, 6);
  }

  ATabort("AsFix has no Tree: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ModuleName accessor implementations */

/*{{{  ATbool isValidModuleName(ModuleName arg) */

ATbool isValidModuleName(ModuleName arg)
{
  if (isModuleNameDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool isModuleNameDefault(ModuleName arg) */

ATbool isModuleNameDefault(ModuleName arg)
{
  return ATmatchTerm((ATerm)arg, patternModuleNameDefault, NULL);
}

/*}}}  */
/*{{{  ATbool hasModuleNameId(ModuleName arg) */

ATbool hasModuleNameId(ModuleName arg)
{
  if (isModuleNameDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  String getModuleNameId(ModuleName arg) */

String getModuleNameId(ModuleName arg)
{
  if (isModuleNameDefault(arg)) {
    return (String)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("ModuleName has no Id: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ModuleName setModuleNameId(ModuleName arg, String id) */

ModuleName setModuleNameId(ModuleName arg, String id)
{
  if (isModuleNameDefault(arg)) {
    return (ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)id, 0);
  }

  ATabort("ModuleName has no Id: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  Layout accessor implementations */

/*{{{  ATbool isValidLayout(Layout arg) */

ATbool isValidLayout(Layout arg)
{
  if (isLayoutEmpty(arg)) {
    return ATtrue;
  }
  else if (isLayoutNewline(arg)) {
    return ATtrue;
  }
  else if (isLayoutSpace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool isLayoutEmpty(Layout arg) */

ATbool isLayoutEmpty(Layout arg)
{
  return ATmatchTerm((ATerm)arg, patternLayoutEmpty);
}

/*}}}  */
/*{{{  ATbool isLayoutNewline(Layout arg) */

ATbool isLayoutNewline(Layout arg)
{
  return ATmatchTerm((ATerm)arg, patternLayoutNewline);
}

/*}}}  */
/*{{{  ATbool isLayoutSpace(Layout arg) */

ATbool isLayoutSpace(Layout arg)
{
  return ATmatchTerm((ATerm)arg, patternLayoutSpace);
}

/*}}}  */

/*}}}  */
