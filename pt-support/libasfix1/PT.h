#ifndef _PT_H
#define _PT_H

/*{{{  includes */

#include <aterm1.h>
#include "PT_dict.h"

/*}}}  */

/*{{{  prologue */

typedef ATerm Layout;
typedef ATerm ModuleName;
typedef ATerm PathName;
typedef ATerm Tree;

/*}}}  */
/*{{{  typedefs */

typedef struct _AsFix *AsFix;

/*}}}  */

void initPTApi(void);

AsFix makeAsFixFromTerm(ATerm t);
ATerm makeTermFromAsFix(AsFix arg);

AsFix makeAsFixTree(PathName path, ModuleName moduleName, Layout wsBeforeTree, Tree tree, Layout wsAfterTree);

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
ATbool hasAsFixPath(AsFix arg);
PathName getAsFixPath(AsFix arg);
AsFix setAsFixPath(AsFix arg, PathName path);
ATbool hasAsFixTree(AsFix arg);
Tree getAsFixTree(AsFix arg);
AsFix setAsFixTree(AsFix arg, Tree tree);

/*}}}  */

#endif /* _PT_H */
