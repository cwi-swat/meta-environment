/*$Id$*/

#include "options.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static int* intOptions = NULL;
static ATbool* flagOptions = NULL;
static char** stringOptions = NULL;

static int maxOptionId = 0;
static int lastIntOptionId = 0;
static int lastFlagOptionId = 0;
static int lastStringOptionId = 0;

void OPT_initialize(int maxOptions) {
  static ATbool initialized = ATfalse;

  if (!initialized) {
    maxOptionId = maxOptions;
    intOptions = (int*) calloc(maxOptions, sizeof(int));
    flagOptions = (ATbool*) calloc(maxOptions, sizeof(ATbool));
    stringOptions = (char**) calloc(maxOptions, sizeof(char*));
    initialized = ATtrue;
  }
}

int OPT_getIntOptionId() {
  assert(lastIntOptionId < maxOptionId);
  return lastIntOptionId++;
}

int OPT_getFlagOptionId() {
  assert(lastFlagOptionId < maxOptionId);
  return lastFlagOptionId++;
}

int OPT_getStringOptionId() {
  assert(lastStringOptionId < maxOptionId);
  return lastStringOptionId++;
}

void OPT_cleanup() {
  free(intOptions); intOptions = NULL;
  free(flagOptions); flagOptions = NULL;
  free(stringOptions); stringOptions = NULL;
}

void OPT_setFlag(int flagOptionId, ATbool value)  {
  flagOptions[flagOptionId] = value;
}

ATbool OPT_getFlag(int flagOptionId) {
  return flagOptions[flagOptionId];
}

void   OPT_setStringValue(int stringOptionId, const char *value) {
  stringOptions[stringOptionId] = strdup(value);
}

const char* OPT_getStringValue(int stringOptionId) {
  return stringOptions[stringOptionId];
}

void OPT_setIntValue(int intOptionId, int value) {
  intOptions[intOptionId] = value;
}

int OPT_getIntValue(int intOptionId) {
  return intOptions[intOptionId];
}
