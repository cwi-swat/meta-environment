#include <aterm2.h>
#include <stdio.h>

static ATerm parseTable = NULL;

/*{{{  void setParseTable(ATerm pt)  */

void setParseTable(ATerm pt) 
{
  ATprotect(&parseTable);
  parseTable = pt;
}

/*}}}  */
/*{{{  ATerm getParseTable()  */

ATerm getParseTable() 
{
  return parseTable;
}

/*}}}  */
