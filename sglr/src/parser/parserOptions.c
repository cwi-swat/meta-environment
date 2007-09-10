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
int OUTPUT_FLAG;
int AMBIGUITY_ERROR_FLAG;

/** \todo Check whether this is compatible with the previous version */
void PARSER_initializeDefaultOptions() {
  VERBOSE_FLAG = OPT_getFlagOptionId();
  DEBUG_FLAG = OPT_getFlagOptionId();
  OUTPUT_FLAG = OPT_getFlagOptionId();
  AMBIGUITY_ERROR_FLAG = OPT_getFlagOptionId();

  PARSER_setVerboseFlag(ATfalse);
  PARSER_setDebugFlag(ATfalse);
  PARSER_setOutputFlag(ATtrue);
  PARSER_setAmbiguityErrorFlag(ATfalse);
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

