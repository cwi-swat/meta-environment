#include <aterm2.h>
#include <deprecated.h>
#include "PT.h"

/*{{{  typedefs */

typedef struct ATerm _AsFix;

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

/*{{{  AsFix makeAsFixTree(PathName path, ModuleName moduleName, Layout wsBeforeTree, Tree tree, Layout wsAfterTree) */

AsFix makeAsFixTree(PathName path, ModuleName moduleName, Layout wsBeforeTree, Tree tree, Layout wsAfterTree)
{
  return (AsFix)ATmakeTerm(patternAsFixTree, path, moduleName, wsBeforeTree, tree, wsAfterTree);
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
  return ATmatchTerm((ATerm)arg, patternAsFixTree, NULL, NULL, NULL, NULL, NULL);
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
/*{{{  ATbool hasAsFixPath(AsFix arg) */

ATbool hasAsFixPath(AsFix arg)
{
  if (isAsFixTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PathName getAsFixPath(AsFix arg) */

PathName getAsFixPath(AsFix arg)
{
  if (isAsFixTree(arg)) {
    return (PathName)ATgetArgument((ATermAppl)arg, 2);
  }

  ATabort("AsFix has no Path: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  AsFix setAsFixPath(AsFix arg, PathName path) */

AsFix setAsFixPath(AsFix arg, PathName path)
{
  if (isAsFixTree(arg)) {
    return (AsFix)ATsetArgument((ATermAppl)arg, (ATerm)path, 2);
  }

  ATabort("AsFix has no Path: %t\n", arg);
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
