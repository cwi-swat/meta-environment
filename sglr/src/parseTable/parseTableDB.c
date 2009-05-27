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
#include <Error-manager.h>
#include <rsrc-usage.h>

#define MAX_TABLES 1

/* Parse Table Database */
typedef struct _ptdb {
  char *name;
  ParseTable *table;
} PTDB;

static PTDB cachedTable = { "", NULL};
static double timeTakeToAllocateTable = 0.0;

/* Read a parse table term, build a parse table, and add it to the
 * parse table database.
 */
ParseTable *SG_AddParseTable(const char *filename) {
  FILE       *inputFile;
  ParseTable *intParseTable = NULL;
  PTBL_ParseTable extParseTable;
  ATbool readFromStdin = ATfalse;

  if (filename == NULL || strcmp(filename,"") == 0 || strcmp(filename,"-") == 0) {
    inputFile = stdin;
    readFromStdin = ATtrue;
  }
  else {
    inputFile = fopen(filename, "rb");
  }

  if (!inputFile) {
    ERR_managerStoreError("could not open parse table file", ERR_makeSubjectListEmpty());
    return NULL;
  }

  STATS_Timer();
  extParseTable = PTBL_ParseTableFromTerm(ATreadFromFile(inputFile));
  intParseTable = SG_BuildParseTable(extParseTable, filename);
  timeTakeToAllocateTable = STATS_Timer();
  SGLR_STATS_setCount(SGLR_STATS_parseTableTime, timeTakeToAllocateTable);

  if (!readFromStdin) {
    fclose(inputFile);
  }

  if (intParseTable != NULL) { 
    SG_CacheParseTable(filename, intParseTable);
  }

  return intParseTable;
}

/* Store parse table in parse table database; if the parse table database is 
 * full, ditch its first entry to make room.
 */
void SG_CacheParseTable(const char *parseTableName, ParseTable *pt) {
  if (cachedTable.table) {
    free(cachedTable.name);
    
    SGLR_PTBL_discardParseTable(cachedTable.table);
  }
  cachedTable.name  = strdup(parseTableName);
  cachedTable.table = pt;
  if (PARSER_getDebugFlag == ATtrue) {
    /*ATfprintf(LOG_log(), "Table for %s added to parse table database\n", parseTableName);*/
  }
}

ParseTable *SG_LookupParseTable(const char *parseTableName) {
  /*static char contentDescription[1024];*/

  SGLR_PTBL_initErrorList();

  if (parseTableName == NULL || cachedTable.table == NULL) {
    return NULL;
  }
  if (strcmp(parseTableName, cachedTable.name) == 0) {
    if (PARSER_getDebugFlag == ATtrue) {
      /*ATfprintf(LOG_log(), "Table for language %s available\n", parseTableName);*/
    }
    return cachedTable.table;
  }

  /*sprintf(contentDescription, "Table for %s not stored", 
	  parseTableName ? "XXX" : "[undefined]");*/

  /*  SG_addParseTableErrorError(inFile, contentDescription); */

  return NULL;
}

double SG_getTimeTakenToAllocateTable(void) {
  return timeTakeToAllocateTable;
}
