/*$Id$*/

/** 
 * \file
 * \ingroup parser
 */

#include "parserOptions.h"
#include "options.h"

/** \todo Should these options be only for the parser or all of SGLR? */
int VERBOSE_FLAG;
int DEBUG_FLAG;
static int OUTPUT_FLAG;
static int PARSER_FLAG;
static int AMBIGUITY_ERROR_FLAG;
static int DEBUGFILENAME_VALUE;

/** \todo Check whether this is compatible with the previous version */
void PARSER_initializeDefaultOptions() {
  VERBOSE_FLAG = OPT_getFlagOptionId();
  DEBUG_FLAG = OPT_getFlagOptionId();
  PARSER_FLAG = OPT_getFlagOptionId();
  OUTPUT_FLAG = OPT_getFlagOptionId();
  AMBIGUITY_ERROR_FLAG = OPT_getFlagOptionId();
  DEBUGFILENAME_VALUE = OPT_getStringOptionId();

  PARSER_setVerboseFlag(ATfalse);
  PARSER_setDebugFlag(ATfalse);
  PARSER_setParserFlag(ATtrue);
  PARSER_setOutputFlag(ATtrue);
  PARSER_setAmbiguityErrorFlag(ATfalse);
  PARSER_setDebugFilename("");
}

void PARSER_setVerboseFlag(ATbool value) {
  OPT_setFlag(VERBOSE_FLAG, value);
}

/*ATbool PARSER_getVerboseFlag() {
  return OPT_getFlag(VERBOSE_FLAG);
}*/

void PARSER_setDebugFlag(ATbool value) {
  OPT_setFlag(DEBUG_FLAG, value);
}

void PARSER_setParserFlag(ATbool value) {
  OPT_setFlag(PARSER_FLAG, value);
}

ATbool PARSER_getParserFlag() {
  return OPT_getFlag(PARSER_FLAG);
}

void PARSER_setOutputFlag(ATbool value) {
  OPT_setFlag(OUTPUT_FLAG, value);
}

ATbool PARSER_getOutputFlag() {
  return OPT_getFlag(OUTPUT_FLAG);
}

void PARSER_setAmbiguityErrorFlag(ATbool value) {
  OPT_setFlag(AMBIGUITY_ERROR_FLAG, value);
}

ATbool PARSER_getAmbiguityErrorFlag() {
  return OPT_getFlag(AMBIGUITY_ERROR_FLAG);
}

void PARSER_setDebugFilename(const char *filename) {
  OPT_setStringValue(DEBUGFILENAME_VALUE, filename);
}

const char *PARSER_gerDebugFilename() {
  return OPT_getStringValue(DEBUGFILENAME_VALUE);
}
