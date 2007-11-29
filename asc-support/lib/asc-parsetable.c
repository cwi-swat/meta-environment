#include <stdio.h>
#include <aterm2.h>

#include "asc-support-me.h"
#include <sglrInterface.h>
#include <ptable.h>

static PTBL_ParseTable parseTable = NULL;
static const char PARSETABLE_ID[] = "ascParseTable";
static ATbool initialized = ATfalse;

void setParseTable(PTBL_ParseTable pt) {
  ATprotect((ATerm *)((void *)&parseTable));
  parseTable = pt;
}

const char *getParseTableID() {
  return PARSETABLE_ID;
}

PTBL_ParseTable getParseTable() {
  return parseTable;
}

ATbool loadParseTable() {
  if (!initialized) {
    SGLR_initialize();
    initialized = ATtrue;
  }

  if (!SGLR_isParseTableLoaded(PARSETABLE_ID)) { 
    if (parseTable != NULL) {
      SGLR_loadParseTable(PARSETABLE_ID, parseTable);
      return ATtrue;
    }
    return ATfalse;
  }
  return ATtrue;
}
