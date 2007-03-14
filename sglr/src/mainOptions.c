/*$Id$*/

/** \file
 *
 */

#include "mainOptions.h"
#include "options.h"

static int TOOLBUS_FLAG;
static int FLATTEN_TREE_FLAG;
static int TEXTUALOUTPUT_FLAG;
static int OUTPUTFILENAME_VALUE;
static int INPUTFILENAME_VALUE;
static int PARSETABLENAME_VALUE;


void MAIN_initializeDefaultOptions()  {
  TOOLBUS_FLAG = OPT_getFlagOptionId();
  FLATTEN_TREE_FLAG = OPT_getFlagOptionId();
  TEXTUALOUTPUT_FLAG = OPT_getFlagOptionId();
  OUTPUTFILENAME_VALUE = OPT_getStringOptionId();
  INPUTFILENAME_VALUE = OPT_getStringOptionId();
  PARSETABLENAME_VALUE = OPT_getStringOptionId();

  MAIN_setFlattenTreeFlag(ATtrue);
  MAIN_setTextualOutputFlag(ATfalse);
  MAIN_setOutputFileName("-");
}

void MAIN_setFlattenTreeFlag(ATbool value) {
  OPT_setFlag(FLATTEN_TREE_FLAG, value);
}

ATbool MAIN_getFlattenTreeFlag() {
  return OPT_getFlag(FLATTEN_TREE_FLAG);
}

void MAIN_setTextualOutputFlag(ATbool value) {
  OPT_setFlag(TEXTUALOUTPUT_FLAG, value);
}

ATbool MAIN_getTextualOutputFlag() {
  return OPT_getFlag(TEXTUALOUTPUT_FLAG);
}

void MAIN_setOutputFileName(const char* outputFileName) {
  OPT_setStringValue(OUTPUTFILENAME_VALUE, outputFileName);
}

const char *MAIN_getOutputFileName() {
  return OPT_getStringValue(OUTPUTFILENAME_VALUE);
}

void MAIN_setInputFileName(const char* inputFileName) {
  OPT_setStringValue(INPUTFILENAME_VALUE, inputFileName);
}

const char *MAIN_getInputFileName() {
  return OPT_getStringValue(INPUTFILENAME_VALUE);
}

void MAIN_setParseTableName(const char* parseTableName) {
  OPT_setStringValue(PARSETABLENAME_VALUE, parseTableName);
}

const char *MAIN_getParseTableName() {
  return OPT_getStringValue(PARSETABLENAME_VALUE);
}

