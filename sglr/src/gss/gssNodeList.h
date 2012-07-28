/*$Id$*/

/** \file 
 * \ingroup gss
 */

#ifndef _GSSNODELIST_H_
#define _GSSNODELIST_H_

#include <aterm2.h>
#include "list.h"
#include "gssNode-data.h"
#include "gssNode-api.h"
#include "parseTable.h"

typedef List GSSNodeList;

#define     GSS_getNodeListHead(list) ((GSSNode)SGLR_UTIL_getHead(list))
#define     GSS_getNodeListTail(list) ((GSSNodeList)SGLR_UTIL_getTail(list))
/*GSSNode     GSS_getNodeListHead(GSSNodeList list);*/
/*GSSNodeList GSS_getNodeListTail(GSSNodeList list);*/
GSSNodeList GSS_addNodeListElement(GSSNode element, GSSNodeList list);
void        GSS_deleteNodeList(GSSNodeList list);
GSSNode     GSS_findElementInNodeList(GSSNode element, GSSNodeList list);
GSSNode     GSS_findStateInNodeList(int stateNum, GSSNodeList list);
GSSNodeList GSS_reverseNodeList(GSSNodeList list);

#endif /*_GSSNODELIST_H_*/
