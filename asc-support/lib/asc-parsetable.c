#include <stdio.h>
#include <aterm2.h>

#include "asc-support-me.h"

static ATerm parseTable = NULL;

/*{{{  void setParseTable(ATerm pt)  */

void setParseTable(ATerm pt) 
{
  ATprotect((ATerm *)((void *)&parseTable));
  parseTable = pt;
}

/*}}}  */
/*{{{  ATerm getParseTable()  */

ATerm getParseTable() 
{
  return parseTable;
}

/*}}}  */
