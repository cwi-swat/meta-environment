#ifndef _PT_H
#define _PT_H

/*{{{  includes */

#include <aterm1.h>
#include "PT_dict.h"

/*}}}  */

/*{{{  prologue */

typedef ATerm String;
typedef ATerm Tree;

/*}}}  */
/*{{{  typedefs */

typedef struct _AsFix *AsFix;
typedef struct _ModuleName *ModuleName;
typedef struct _Layout *Layout;

/*}}}  */

void initPTApi(void);

AsFix makeAsFixFromTerm(ATerm t);
ATerm makeTermFromAsFix(AsFix arg);
ModuleName makeModuleNameFromTerm(ATerm t);
ATerm makeTermFromModuleName(ModuleName arg);
Layout makeLayoutFromTerm(ATerm t);
ATerm makeTermFromLayout(Layout arg);

AsFix makeAsFixTree(ModuleName moduleName, Layout wsBeforeTree, Tree tree, Layout wsAfterTree);
ModuleName makeModuleNameDefault(String id);
Layout makeLayoutEmpty();
Layout makeLayoutNewline();
Layout makeLayoutSpace();

/*{{{  AsFix accessor prototypes */

ATbool isValidAsFix(AsFix arg);
ATbool isAsFixTree(AsFix arg);
ATbool hasAsFixWsAfterTree(AsFix arg);
Layout getAsFixWsAfterTree(AsFix arg);
AsFix setAsFixWsAfterTree(AsFix arg, Layout wsAfterTree);
ATbool hasAsFixWsBeforeTree(AsFix arg);
Layout getAsFixWsBeforeTree(AsFix arg);
AsFix setAsFixWsBeforeTree(AsFix arg, Layout wsBeforeTree);
ATbool hasAsFixModuleName(AsFix arg);
ModuleName getAsFixModuleName(AsFix arg);
AsFix setAsFixModuleName(AsFix arg, ModuleName moduleName);
ATbool hasAsFixTree(AsFix arg);
Tree getAsFixTree(AsFix arg);
AsFix setAsFixTree(AsFix arg, Tree tree);

/*}}}  */
/*{{{  ModuleName accessor prototypes */

ATbool isValidModuleName(ModuleName arg);
ATbool isModuleNameDefault(ModuleName arg);
ATbool hasModuleNameId(ModuleName arg);
String getModuleNameId(ModuleName arg);
ModuleName setModuleNameId(ModuleName arg, String id);

/*}}}  */
/*{{{  Layout accessor prototypes */

ATbool isValidLayout(Layout arg);
ATbool isLayoutEmpty(Layout arg);
ATbool isLayoutNewline(Layout arg);
ATbool isLayoutSpace(Layout arg);

/*}}}  */

#endif /* _PT_H */
