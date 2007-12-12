/*$Id$*/

/** \file 
 * \ingroup gss 
 */

#ifndef __GSSNODE_API_
#define __GSSNODE_API_

#include <aterm2.h>
#include <MEPT.h>
#include "gssEdgeList.h"
#include "gssNode-data.h"
#include "gssEdge-data.h"
#include "parseTable.h"

GSSNode     GSSNode_createNode(int stateNum, ATbool isShift);
void        GSSNode_deleteGSSNode(GSSNode gssNode);
GSSEdge     GSSNode_addEdge(GSSNode source, GSSNode target, PT_Tree t, size_t tl, ATbool rejected);
int       GSSNode_getStateNumber(GSSNode gssNode);
GSSEdgeList GSSNode_getEdgeList(GSSNode gssNode);
void        GSSNode_increaseRefCount(GSSNode gssNode);
void        GSSNode_decreaseRefCount(GSSNode gssNode);
short       GSSNode_getRefCount(GSSNode gssNode);
ATbool      GSSNode_isShift(GSSNode gssNode); /* currently not used. */
ATbool      GSSNode_isRejected(GSSNode node);
int         GSSNode_rejectStatus(GSSNode source);

#endif /* _GSSNODE_API_ */
