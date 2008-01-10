/*$Id$*/

/** \file
 * Handles and stores program options. Memory for the options is automatically 
 * allocated and extended as necessary.
 *
 * There are three types of option values that can be stored:
 * <ul>
 * <li>Integers</li>
 * <li>ATerm booleans</li>
 * <li>Strings</li>
 * </ul>
 */

#include "options.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static int* intOptions = NULL;
static ATbool* flagOptions = NULL;
static char** stringOptions = NULL;

const static int memBlock = 50;
static int maxOptionId = 0;
static int lastIntOptionId = 0;
static int lastFlagOptionId = 0;
static int lastStringOptionId = 0;

void OPT_initialize(void) {
  static ATbool initialized = ATfalse;

  if (!initialized) {
    maxOptionId = memBlock;
    intOptions = (int*) calloc(maxOptionId, sizeof(int));
    flagOptions = (ATbool*) calloc(maxOptionId, sizeof(ATbool));
    stringOptions = (char**) calloc(maxOptionId, sizeof(char*));
    initialized = ATtrue;
  }
}

static void grow(void) {
  maxOptionId += memBlock;
  intOptions = (int*) realloc(intOptions, maxOptionId);
  flagOptions = (ATbool*) realloc(flagOptions, maxOptionId);
  stringOptions = (char**) realloc(stringOptions, maxOptionId);
}

int OPT_getIntOptionId(void) {
  if (lastIntOptionId == maxOptionId) {
    grow();
  }
  return lastIntOptionId++;
}

int OPT_getFlagOptionId(void) {
  if (lastFlagOptionId == maxOptionId) {
    grow();
  }
  return lastFlagOptionId++;
}

int OPT_getStringOptionId(void) {
  if (lastStringOptionId == maxOptionId) {
    grow();
  }
  return lastStringOptionId++;
}

void OPT_cleanup(void) {
  free(intOptions); intOptions = NULL;
  free(flagOptions); flagOptions = NULL;
  free(stringOptions); stringOptions = NULL;
}

void OPT_setFlag(int flagOptionId, ATbool value)  {
  assert(flagOptionId < maxOptionId);
  flagOptions[flagOptionId] = value;
}

ATbool OPT_getFlag(int flagOptionId) {
  assert(flagOptionId < maxOptionId);
  return flagOptions[flagOptionId];
}

void OPT_setStringValue(int stringOptionId, const char *value) {
  assert(stringOptionId < maxOptionId);
  stringOptions[stringOptionId] = strdup(value);
}

const char* OPT_getStringValue(int stringOptionId) {
  assert(stringOptionId < maxOptionId);
  return stringOptions[stringOptionId];
}

void OPT_setIntValue(int intOptionId, int value) {
  assert(intOptionId < maxOptionId);
  intOptions[intOptionId] = value;
}

int OPT_getIntValue(int intOptionId) {
  assert(intOptionId < maxOptionId);
  return intOptions[intOptionId];
}
