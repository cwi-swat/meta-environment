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
/*{{{  void initParser(const char *toolname, const char *filename) */

void initParser(const char *toolname, const char *filename)
{
  static ATbool initialized = ATfalse;
  ATerm language = ATparse(toolname);

  if (!initialized && parseTable != NULL) {
    SGinitParser(ATfalse);
    SG_ASFIX2ME_ON();
    SG_OUTPUT_ON();
    SG_TOOLBUS_OFF();

    initialized = ATtrue;
    
    SG_FILTER_INJECTIONCOUNT_OFF(); 
    SG_FILTER_EAGERNESS_OFF();

    SGopenLanguageFromTerm(language, parseTable, filename);
  }
}

/*}}}  */
