/*$Id$*/

/** \file
 * \ingroup parseTable
 */

#ifndef _PARSETABLEDB_
#define _PARSETABLEDB_

#include "parseTable.h"

ParseTable  *SG_AddParseTable(const char *filename);
void         SG_CacheParseTable(const char *L, ParseTable *pt);
ParseTable  *SG_LookupParseTable(const char *L);

#endif /* _PARSETABLEDB_ */

