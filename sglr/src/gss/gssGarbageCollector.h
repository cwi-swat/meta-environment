/*$Id$*/

/** \file
 * \ingroup gss 
 */

#ifndef _GSSMEMORYMANAGEMENT_H_
#define _GSSMEMORYMANAGEMENT_H_

#include "gssNode-api.h"
#include "gssEdge-api.h"
#include "gssNodeList.h"

void        GC_gssBranch(GSSNode st);
GSSNodeList GC_gssBranches(GSSNodeList *old, int nr_old, 
			   GSSNodeList new, GSSNode accept);

#endif //_GSSMEMORYMANAGEMENT_H_
