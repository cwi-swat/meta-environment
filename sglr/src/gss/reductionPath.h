/*$Id$*/

/** \file
 * \ingroup gss
 */

#ifndef _REDUCTION_PATH_
#define _REDUCTION_PATH_

#include "gssNode-api.h"
#include "aterm1.h"

typedef struct _ReductionPath *ReductionPath;

ReductionPath GSS_addReductionPath(GSSNode targetGSSNode, PT_Args treeNodes, 
				   size_t length, ReductionPath path);
void          GSS_clearReductionPath(ReductionPath path);
GSSNode       GSS_getReductionPathTargetGSSNode(ReductionPath path);
PT_Args       GSS_getReductionPathTreeNodes(ReductionPath path); 
size_t        GSS_getReductionPathLength(ReductionPath path);
ReductionPath GSS_getNextReductionPath(ReductionPath path);
void GSS_printReductionPath(ReductionPath path);

#endif
