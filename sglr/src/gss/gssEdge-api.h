/*$Id$*/

/** \file 
 * \ingroup gss
 */

#ifndef __GSSEDGE_API_
#define __GSSEDGE_API_

#include <aterm2.h>
#include <MEPT.h>
#include "gssEdge-data.h"
#include "gssNode-data.h"

GSSEdge GSSEdge_createEdge(PT_Tree t, size_t numberOfLeavesInTree, GSSNode target, ATbool rejected);
void    GSSEdge_deleteGSSEdge(GSSEdge edge);
void    GSSEdge_setTargetGSSNode(GSSEdge edge, GSSNode target);
void    GSSEdge_setTree(GSSEdge edge, PT_Tree t);
void    GSSEdge_setNumberOfLeavesInTree(GSSEdge edge, size_t numberOfLeaves);
void    GSSEdge_setRejected(GSSEdge gssEdge);

GSSNode GSSEdge_getTargetGSSNode(GSSEdge edge);
PT_Tree GSSEdge_getTree(GSSEdge edge);
int     GSSEdge_getNumberOfLeavesInTree(GSSEdge edge);
ATbool  GSSEdge_isRejected(GSSEdge edge);

#endif //_GSSEDGE_API_
