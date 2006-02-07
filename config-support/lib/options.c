/*$Id$*/

#include "options.h"
#include <assert.h>

static ATermTable optionsTable;
static ATerm on = NULL;
static ATerm off = NULL;

void OPT_initialize() {
  static ATbool initialized = ATfalse;

  if (!initialized) {
    /* There are 16 options in SGLR and 8 in asc-support. 75% of 32 = 24 */
    optionsTable = ATtableCreate(32,75);
    on = ATparse("on");
    ATprotect(&on);
    off = ATparse("off");
    ATprotect(&off);
    initialized = ATtrue;
  }
}

void OPT_cleanup() {
  ATtableDestroy(optionsTable);
  ATunprotect(&on);
  on = NULL;
  ATunprotect(&off);
  off = NULL;
}

/* We use ATerms to index into the hash table. For different types of option 
 * values the names are wrapped with different names, like flag, or string.
 */
static ATerm stringToATerm(const char *name) {
  return (ATerm) ATmakeAppl0(ATmakeAFun(name, 0, ATfalse));
}

static char* ATermToString(ATerm term) {
  assert(ATgetType(term) == AT_APPL);

  return ATgetName(ATgetAFun((ATermAppl) term));
}

static ATerm intName(const char *name) {
  return ATmake("int(<term>)", stringToATerm(name));
}

static ATerm flagName(const char *name) {
  return ATmake("flag(<term>)", stringToATerm(name));
}

static ATerm stringName(const char *name) {
  return ATmake("string(<term>)", stringToATerm(name));
}

static ATerm stringValue(const char* value) {
  return stringToATerm(value);
}

void OPT_setFlag(const char *name, ATbool value)  {
  ATtablePut(optionsTable, flagName(name), value ? on : off);
}

ATbool OPT_getFlag(const char *name) {
  ATerm value = ATtableGet(optionsTable, flagName(name));

  if (ATisEqual(value,on)) {
    return ATtrue;
  }
  else {
    return ATfalse;
  }
}

void   OPT_setStringValue(const char *name, const char *value) {
  ATtablePut(optionsTable, stringName(name), stringValue(value));
}

const char* OPT_getStringValue(const char *name) {
  ATerm value = ATtableGet(optionsTable, stringName(name));
  assert(value != NULL);
  return  ATermToString(value);
}

void OPT_setIntValue(const char *name, int value) {
  ATtablePut(optionsTable, intName(name), (ATerm)ATmakeInt(value));
}

int OPT_getIntValue(const char *name) {
  ATerm value = ATtableGet(optionsTable, intName(name));
  assert(value != NULL);
  return ATgetInt((ATermInt)value);
}
