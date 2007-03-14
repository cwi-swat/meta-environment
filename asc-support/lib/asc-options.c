/* $Id$ */

#include "asc-options.h"
#include <options.h>

static int VERBOSE_FLAG;
static int STATS_FLAG;
static int BAFMODE_FLAG;
static int OUTPUT_FLAG;
static int PREFIX_FUNCTION_VALUE;
static int OUTPUT_FILENAME_VALUE;
static int RESULT_NONTERM_VALUE;
static int NUMOFPARSETREES_VALUE;

void ASC_initializeDefaultOptions() {
  VERBOSE_FLAG          = OPT_getFlagOptionId();
  STATS_FLAG            = OPT_getFlagOptionId();
  BAFMODE_FLAG          = OPT_getFlagOptionId();
  OUTPUT_FLAG           = OPT_getFlagOptionId();
  PREFIX_FUNCTION_VALUE = OPT_getStringOptionId();
  OUTPUT_FILENAME_VALUE = OPT_getStringOptionId();
  RESULT_NONTERM_VALUE  = OPT_getStringOptionId();
  NUMOFPARSETREES_VALUE = OPT_getIntOptionId();

  ASC_setVerboseFlag(ATfalse);
  ASC_setStatsFlag(ATfalse);
  ASC_setBafmodeFlag(ATtrue);
  ASC_setOutputFlag(ATtrue);
  ASC_setPrefixFunction("");
  ASC_setOutputFilename("-");
  ASC_setResultNonTermName("");
  ASC_setNumberOfParseTrees(0);
}

void ASC_setVerboseFlag(ATbool value) {
  OPT_setFlag(VERBOSE_FLAG, value);
}

void ASC_setPrefixFunction(const char *function) {
  OPT_setStringValue(PREFIX_FUNCTION_VALUE, function);
}

void ASC_setOutputFilename(const char *output) {
  OPT_setStringValue(OUTPUT_FILENAME_VALUE, output);
}

void ASC_setResultNonTermName(const char *result) {
  OPT_setStringValue(RESULT_NONTERM_VALUE, result);
}

void ASC_setStatsFlag(ATbool value) {
  OPT_setFlag(STATS_FLAG, value);
}

void ASC_setBafmodeFlag(ATbool value) {
  OPT_setFlag(BAFMODE_FLAG, value);
}

void ASC_setOutputFlag(ATbool value) {
  OPT_setFlag(OUTPUT_FLAG, value);
}

void ASC_setNumberOfParseTrees(int nInputs) {
  OPT_setIntValue(NUMOFPARSETREES_VALUE, nInputs);
}


ATbool ASC_getVerboseFlag() {
  return OPT_getFlag(VERBOSE_FLAG);
}

const char *ASC_getPrefixFunction() {
  return OPT_getStringValue(PREFIX_FUNCTION_VALUE);
}

const char *ASC_getOutputFilename() {
  return OPT_getStringValue(OUTPUT_FILENAME_VALUE);
}

const char *ASC_getResultNonTermName() {
  return OPT_getStringValue(RESULT_NONTERM_VALUE);
}

ATbool ASC_getStatsFlag() {
  return OPT_getFlag(STATS_FLAG);
}

ATbool ASC_getBafmodeFlag() {
  return OPT_getFlag(BAFMODE_FLAG);
}

ATbool ASC_getOutputFlag() {
  return OPT_getFlag(OUTPUT_FLAG);
}

int ASC_getNumberOfParseTrees() {
  return OPT_getIntValue(NUMOFPARSETREES_VALUE);
}

