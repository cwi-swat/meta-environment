#ifndef _PT_H
#define _PT_H

/*{{{  includes */

#include <aterm1.h>
#include "PT_dict.h"

/*}}}  */

/*{{{  prologue */

typedef ATerm PT_String;
typedef ATerm PT_Tree;

/*}}}  */
/*{{{  typedefs */

typedef struct _PT_AsFix *PT_AsFix;
typedef struct _PT_ModuleName *PT_ModuleName;
typedef struct _PT_Layout *PT_Layout;

/*}}}  */

void PT_initPTApi(void);

PT_AsFix PT_makeAsFixFromTerm(ATerm t);
ATerm PT_makeTermFromAsFix(PT_AsFix arg);
PT_ModuleName PT_makeModuleNameFromTerm(ATerm t);
ATerm PT_makeTermFromModuleName(PT_ModuleName arg);
PT_Layout PT_makeLayoutFromTerm(ATerm t);
ATerm PT_makeTermFromLayout(PT_Layout arg);

PT_AsFix PT_makeAsFixTree(PT_Layout wsAfterTerm, PT_Layout wsAfterPath, PT_ModuleName moduleName, PT_Layout wsBeforeTree, PT_Tree tree, PT_Layout wsAfterTree);
PT_ModuleName PT_makeModuleNameDefault(PT_String id);
PT_Layout PT_makeLayoutEmpty();
PT_Layout PT_makeLayoutNewline();
PT_Layout PT_makeLayoutSpace();

/*{{{  equality functions */

ATbool PT_isEqualAsFix(PT_AsFix arg0, PT_AsFix arg1);
ATbool PT_isEqualModuleName(PT_ModuleName arg0, PT_ModuleName arg1);
ATbool PT_isEqualLayout(PT_Layout arg0, PT_Layout arg1);

/*}}}  */
/*{{{  PT_AsFix accessor prototypes */

ATbool PT_isValidAsFix(PT_AsFix arg);
ATbool PT_isAsFixTree(PT_AsFix arg);
ATbool PT_hasAsFixWsAfterPath(PT_AsFix arg);
PT_Layout PT_getAsFixWsAfterPath(PT_AsFix arg);
PT_AsFix PT_setAsFixWsAfterPath(PT_AsFix arg, PT_Layout wsAfterPath);
ATbool PT_hasAsFixWsAfterTree(PT_AsFix arg);
PT_Layout PT_getAsFixWsAfterTree(PT_AsFix arg);
PT_AsFix PT_setAsFixWsAfterTree(PT_AsFix arg, PT_Layout wsAfterTree);
ATbool PT_hasAsFixWsBeforeTree(PT_AsFix arg);
PT_Layout PT_getAsFixWsBeforeTree(PT_AsFix arg);
PT_AsFix PT_setAsFixWsBeforeTree(PT_AsFix arg, PT_Layout wsBeforeTree);
ATbool PT_hasAsFixWsAfterTerm(PT_AsFix arg);
PT_Layout PT_getAsFixWsAfterTerm(PT_AsFix arg);
PT_AsFix PT_setAsFixWsAfterTerm(PT_AsFix arg, PT_Layout wsAfterTerm);
ATbool PT_hasAsFixModuleName(PT_AsFix arg);
PT_ModuleName PT_getAsFixModuleName(PT_AsFix arg);
PT_AsFix PT_setAsFixModuleName(PT_AsFix arg, PT_ModuleName moduleName);
ATbool PT_hasAsFixTree(PT_AsFix arg);
PT_Tree PT_getAsFixTree(PT_AsFix arg);
PT_AsFix PT_setAsFixTree(PT_AsFix arg, PT_Tree tree);

/*}}}  */
/*{{{  PT_ModuleName accessor prototypes */

ATbool PT_isValidModuleName(PT_ModuleName arg);
ATbool PT_isModuleNameDefault(PT_ModuleName arg);
ATbool PT_hasModuleNameId(PT_ModuleName arg);
PT_String PT_getModuleNameId(PT_ModuleName arg);
PT_ModuleName PT_setModuleNameId(PT_ModuleName arg, PT_String id);

/*}}}  */
/*{{{  PT_Layout accessor prototypes */

ATbool PT_isValidLayout(PT_Layout arg);
ATbool PT_isLayoutEmpty(PT_Layout arg);
ATbool PT_isLayoutNewline(PT_Layout arg);
ATbool PT_isLayoutSpace(PT_Layout arg);

/*}}}  */

#endif /* _PT_H */
