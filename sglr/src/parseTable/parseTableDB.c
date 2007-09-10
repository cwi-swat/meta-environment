/*$Id$*/

/** \file 
 * \ingroup parseTable
 */

#include "parseTableDB.h"
#include "parseTableBuilder.h"
#include "parserOptions.h"
#include "mainOptions.h"
#include "parserStatistics.h"

#include <aterm2.h>
#include <logging.h>
#include <rsrc-usage.h>

#define MAX_TABLES 1

/* Parse Table Database */
typedef struct _ptdb {
  const char *name;
  ParseTable *table;
} PTDB;

static PTDB tables[MAX_TABLES];


/* Read a parse table term, build a parse table, and add it to the
 * parse table database.
 */
ParseTable *SG_AddParseTable(const char *filename) {
  FILE       *input_file;
  ParseTable *intParseTable = NULL;
  PTBL_ParseTable extParseTable;

  input_file = LOG_OpenFile("parse table not specified", filename);
  if (!input_file) {
    return NULL;
  }

  if (MAIN_getStatsFlag) { STATS_Timer(); }

  extParseTable = PTBL_ParseTableFromTerm(ATreadFromFile(input_file));
  intParseTable = SG_BuildParseTable(extParseTable, filename);

  if (MAIN_getStatsFlag) { SGLR_STATS_parseTableTime = STATS_Timer(); }

  LOG_CloseFile(input_file);

  if (intParseTable != NULL) { 
    SG_CacheParseTable(filename, intParseTable);
  }

  return intParseTable;
}

/* Store parse table in parse table database; if the parse table database is 
 * full, ditch its first entry to make room.
 */
void SG_CacheParseTable(const char *parseTableName, ParseTable *pt) {
  if (tables[0].table) {
    SGLR_PTBL_discardParseTable(tables[0].table);
  }
  tables[0].name  = parseTableName;
  tables[0].table = pt;
  if (PARSER_getDebugFlag == ATtrue) {
    ATfprintf(LOG_log(), "Table for %s added to parse table database\n", parseTableName);
  }
}

ParseTable *SG_LookupParseTable(const char *parseTableName) {
  int i = 0;
  /*static char contentDescription[1024];*/

  SGLR_PTBL_initErrorList();

  if (parseTableName == NULL) {
    return NULL;
  }
  if (ATisEqual(parseTableName, tables[0].name)) {
    if (PARSER_getDebugFlag == ATtrue) {
      ATfprintf(LOG_log(), "Table for language %s available\n", parseTableName);
    }
    return tables[i].table;
  }

  /*sprintf(contentDescription, "Table for %s not stored", 
	  parseTableName ? "XXX" : "[undefined]");*/

  /*  SG_addParseTableErrorError(inFile, contentDescription); */

  return NULL;
}
