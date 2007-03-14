/* $Id$ */

#include <options.h>

#include "pgenOptions.h"

static int BAF_MODE_FLAG;
static int ATERM_DEBUG_FLAG; 
static int GENERATION_MODE_FLAG;
static int INPUT_FILENAME_VALUE;
static int STATS_FLAG;
static int TOP_MODULE_VALUE;
static int NORMALIZATION_MODE_FLAG;
static int OUTPUT_FILENAME_VALUE;
static int VERBOSE_MODE_FLAG;

void PGEN_initializeDefaultOptions(void) {
  BAF_MODE_FLAG           = OPT_getFlagOptionId();
  ATERM_DEBUG_FLAG        = OPT_getFlagOptionId(); 
  GENERATION_MODE_FLAG    = OPT_getFlagOptionId();
  INPUT_FILENAME_VALUE    = OPT_getStringOptionId();
  STATS_FLAG              = OPT_getFlagOptionId();
  TOP_MODULE_VALUE        = OPT_getStringOptionId();
  NORMALIZATION_MODE_FLAG = OPT_getFlagOptionId();
  OUTPUT_FILENAME_VALUE   = OPT_getStringOptionId();
  VERBOSE_MODE_FLAG       = OPT_getFlagOptionId();

  PGEN_setBafModeFlag(ATtrue);
  PGEN_setATermDebugFlag(ATfalse);
  PGEN_setGenerationModeFlag(ATfalse);
  PGEN_setInputFilename("-");
  PGEN_setStatsFlag(ATfalse);
  PGEN_setTopModule("-");
  PGEN_setNormalizationModeFlag(ATfalse);
  PGEN_setOutputFilename("-");
  PGEN_setVerboseModeFlag(ATfalse);
}

void PGEN_setBafModeFlag(ATbool value) {
  OPT_setFlag(BAF_MODE_FLAG, value);
}

ATbool PGEN_getBafModeFlag(void) {
  return OPT_getFlag(BAF_MODE_FLAG);
}

void PGEN_setATermDebugFlag(ATbool value) {
  OPT_setFlag(ATERM_DEBUG_FLAG,value);
}

ATbool PGEN_getATermDebugFlag(void) {
  return OPT_getFlag(ATERM_DEBUG_FLAG);
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

ATbool PGEN_getNormalizationModeFlag(void) {
  return OPT_getFlag(NORMALIZATION_MODE_FLAG);
}

void PGEN_setOutputFilename(const char *value) {
  OPT_setStringValue(OUTPUT_FILENAME_VALUE,value);
}

const char *PGEN_getOutputFilename(void) {
  return OPT_getStringValue(OUTPUT_FILENAME_VALUE);
}

void PGEN_setVerboseModeFlag(ATbool value) {
  OPT_setFlag(VERBOSE_MODE_FLAG,value);
}

ATbool PGEN_getVerboseModeFlag(void) {
  return OPT_getFlag(VERBOSE_MODE_FLAG);
}
