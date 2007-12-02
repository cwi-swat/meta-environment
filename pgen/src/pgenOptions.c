/* $Id$ */

#include <options.h>

#include "pgenOptions.h"

static int BAF_MODE_FLAG;
static int COLLECT_FLAG; 
static int GENERATION_MODE_FLAG;
static int INPUT_FILENAME_VALUE;
static int STATS_FLAG;
static int TOP_MODULE_VALUE;
static int NORMALIZATION_MODE_FLAG;
static int DEFINITION_MODE_FLAG;
static int OUTPUT_FILENAME_VALUE;
static int SEARCH_PATH_VALUE;
static int VERBOSE_MODE_FLAG;

void PGEN_initializeDefaultOptions(void) {
  BAF_MODE_FLAG           = OPT_getFlagOptionId();
  COLLECT_FLAG        = OPT_getFlagOptionId(); 
  GENERATION_MODE_FLAG    = OPT_getFlagOptionId();
  INPUT_FILENAME_VALUE    = OPT_getStringOptionId();
  STATS_FLAG              = OPT_getFlagOptionId();
  TOP_MODULE_VALUE        = OPT_getStringOptionId();
  NORMALIZATION_MODE_FLAG = OPT_getFlagOptionId();
  DEFINITION_MODE_FLAG    = OPT_getFlagOptionId();
  OUTPUT_FILENAME_VALUE   = OPT_getStringOptionId();
  VERBOSE_MODE_FLAG       = OPT_getFlagOptionId();
  SEARCH_PATH_VALUE       = OPT_getStringOptionId();

  PGEN_setBafModeFlag(ATtrue);
  PGEN_setCollectFlag(ATfalse);
  PGEN_setGenerationModeFlag(ATfalse);
  PGEN_setInputFilename("-");
  PGEN_setStatsFlag(ATfalse);
  PGEN_setTopModule("Main");
  PGEN_setNormalizationModeFlag(ATfalse);
  PGEN_setDefinitionModeFlag(ATfalse);
  PGEN_setOutputFilename("-");
  PGEN_setVerboseModeFlag(ATfalse);
  PGEN_setSearchPath(".");
}

void PGEN_setBafModeFlag(ATbool value) {
  OPT_setFlag(BAF_MODE_FLAG, value);
}

ATbool PGEN_getBafModeFlag(void) {
  return OPT_getFlag(BAF_MODE_FLAG);
}

void PGEN_setCollectFlag(ATbool value) {
  OPT_setFlag(COLLECT_FLAG,value);
}

ATbool PGEN_getCollectFlag(void) {
  return OPT_getFlag(COLLECT_FLAG);
}

void PGEN_setGenerationModeFlag(ATbool value) {
  OPT_setFlag(GENERATION_MODE_FLAG,value);
}

ATbool PGEN_getGenerationModeFlag(void) {
  return OPT_getFlag(GENERATION_MODE_FLAG);
}

void PGEN_setInputFilename(const char *value) {
  OPT_setStringValue(INPUT_FILENAME_VALUE,value);
}

const char *PGEN_getInputFilename(void) {
  return OPT_getStringValue(INPUT_FILENAME_VALUE);
}

void PGEN_setStatsFlag(ATbool value) {
  OPT_setFlag(STATS_FLAG,value);
}

ATbool PGEN_getStatsFlag(void) {
  return OPT_getFlag(STATS_FLAG);
}

void PGEN_setTopModule(const char *value) {
  OPT_setStringValue(TOP_MODULE_VALUE,value);
}

const char *PGEN_getTopModule(void) {
  return OPT_getStringValue(TOP_MODULE_VALUE);
}

void PGEN_setNormalizationModeFlag(ATbool value) {
  OPT_setFlag(NORMALIZATION_MODE_FLAG,value);
}

ATbool PGEN_getDefinitionModeFlag(void) {
  return OPT_getFlag(DEFINITION_MODE_FLAG);
}

void PGEN_setDefinitionModeFlag(ATbool value) {
  OPT_setFlag(DEFINITION_MODE_FLAG,value);
}

ATbool PGEN_getNormalizationModeFlag(void) {
  return OPT_getFlag(NORMALIZATION_MODE_FLAG);
}

void PGEN_setOutputFilename(const char *value) {
  OPT_setStringValue(OUTPUT_FILENAME_VALUE,value);
}

const char *PGEN_getOutputFilename(void) {
  return OPT_getStringValue(OUTPUT_FILENAME_VALUE);
}

void PGEN_setSearchPath(const char *value) {
  OPT_setStringValue(SEARCH_PATH_VALUE ,value);
}

const char *PGEN_getSearchPath(void) {
  return OPT_getStringValue(SEARCH_PATH_VALUE);
}

void PGEN_setVerboseModeFlag(ATbool value) {
  OPT_setFlag(VERBOSE_MODE_FLAG,value);
}

ATbool PGEN_getVerboseModeFlag(void) {
  return OPT_getFlag(VERBOSE_MODE_FLAG);
}
