#include <stdio.h>
#include <aterm2.h>

#include "asc-support-me.h"

static SGLR_ParseTable parseTable = NULL;

/*{{{  void setParseTable(SGLR_ParseTable pt)  */

void setParseTable(SGLR_ParseTable pt) 
{
  ATprotect((ATerm *)((void *)&parseTable));
  parseTable = pt;
}

/*}}}  */
/*{{{  SGLR_ParseTable getParseTable()  */

SGLR_ParseTable getParseTable() 
{
  return parseTable;
}

/*}}}  */
