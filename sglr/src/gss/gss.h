/*$Id$*/

/** \file
 * \ingroup gss
 */

#ifndef _GSS_H_
#define _GSS_H_ 

#include <aterm1.h>
#include "gssNode-api.h"
#include "gssEdge-api.h"
#include "gssNodeList.h"
#include "reductionPath.h"
#include "parseTable.h"

void          GSS_createStartNode(GSSNode node);
void          GSS_setAcceptNode(GSSNode node);
GSSNode       GSS_getAcceptNode(void);
GSSNode       GSS_findNodeInCurrentLevel(int stateNum);
void          GSS_clearCurrentLevel(void);
GSSNodeList   GSS_getCurrentLevel(void);
void          GSS_addNewLevel(GSSNodeList list);
void          GSS_addToCurrentLevel(GSSNode node);
ReductionPath GSS_findAllPaths(GSSNode source, int reductionLength, int level);
ReductionPath GSS_findLimitedPaths(GSSNode source, int reductionLength, 
				   GSSEdge edge, int level);
GSSEdge       GSS_findDirectEdge(GSSNode source, GSSNode target);
void          GSS_freeGSS(void);

#endif  /* _GSS_H_ */
