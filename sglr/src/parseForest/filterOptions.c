/*$Id$*/

/** \file 
 * \ingroup parseForest
 */

#include "filterOptions.h"
#include "options.h"

static int FILTER_FLAG;
static int DIRECT_PREFERENCE_FLAG;
static int INDIRECT_PREFERENCE_FLAG;
static int PREFERENCE_COUNT_FLAG;
static int INJECTION_COUNT_FLAG;
static int PRIORITY_FLAG;
static int REJECT_FLAG;
static int SELECTTOPNONTERMINAL_FLAG;
static int SELECTTOPNONTERMINAL_VALUE;
static int REMOVECYCLES_FLAG;


void FLT_initializeDefaultOptions() {
  FILTER_FLAG = OPT_getFlagOptionId();
  DIRECT_PREFERENCE_FLAG = OPT_getFlagOptionId();
  INDIRECT_PREFERENCE_FLAG = OPT_getFlagOptionId();
  PREFERENCE_COUNT_FLAG = OPT_getFlagOptionId();
  INJECTION_COUNT_FLAG = OPT_getFlagOptionId();
  PRIORITY_FLAG = OPT_getFlagOptionId();
  REJECT_FLAG = OPT_getFlagOptionId();
  SELECTTOPNONTERMINAL_FLAG = OPT_getFlagOptionId();
  SELECTTOPNONTERMINAL_VALUE = OPT_getStringOptionId();
  REMOVECYCLES_FLAG = OPT_getFlagOptionId();
  FLT_setFilterFlag(ATtrue);
  FLT_setIndirectPreferenceFlag(ATtrue);
  FLT_setPreferenceCountFlag(ATtrue);
  FLT_setInjectionCountFlag(ATtrue);
  FLT_setPriorityFlag(ATtrue);
  FLT_setRejectFlag(ATtrue);
  FLT_setSelectTopNonterminalFlag(ATfalse);
  FLT_setTopNonterminal("***NOT SET***");
}

void FLT_setFilterFlag(ATbool value) {
  OPT_setFlag(FILTER_FLAG, value);
}

ATbool FLT_getFilterFlag() {
  return OPT_getFlag(FILTER_FLAG);
}

void FLT_setDirectPreferenceFlag(ATbool value) {
  OPT_setFlag(DIRECT_PREFERENCE_FLAG, value);
}

ATbool FLT_getDirectPreferenceFlag() {
  return OPT_getFlag(DIRECT_PREFERENCE_FLAG);
}

void FLT_setIndirectPreferenceFlag(ATbool value) {
  OPT_setFlag(INDIRECT_PREFERENCE_FLAG, value);
}

ATbool FLT_getIndirectPreferenceFlag() {
  return OPT_getFlag(INDIRECT_PREFERENCE_FLAG);
}

void FLT_setPreferenceCountFlag(ATbool value) {
  OPT_setFlag(PREFERENCE_COUNT_FLAG, value);
}

ATbool FLT_getPreferenceCountFlag() {
  return OPT_getFlag(PREFERENCE_COUNT_FLAG);
}

void FLT_setInjectionCountFlag(ATbool value) {
  OPT_setFlag(INJECTION_COUNT_FLAG, value);
}

ATbool FLT_getInjectionCountFlag() {
  return OPT_getFlag(INJECTION_COUNT_FLAG);
}

void FLT_setPriorityFlag(ATbool value) {
  OPT_setFlag(PRIORITY_FLAG, value);
}

ATbool FLT_getPriorityFlag() {
  return OPT_getFlag(PRIORITY_FLAG);
}

void FLT_setRejectFlag(ATbool value) {
  OPT_setFlag(REJECT_FLAG, value);
}

ATbool FLT_getRejectFlag() {
  return OPT_getFlag(REJECT_FLAG);
}

void FLT_setSelectTopNonterminalFlag(ATbool value) {
  OPT_setFlag(SELECTTOPNONTERMINAL_FLAG, value);
}

ATbool FLT_getSelectTopNonterminalFlag() {
  return OPT_getFlag(SELECTTOPNONTERMINAL_FLAG);
}

void   FLT_setTopNonterminal(const char* nonterminal) {
  OPT_setStringValue(SELECTTOPNONTERMINAL_VALUE, nonterminal);
}

const char* FLT_getTopNonterminal() { 
  return OPT_getStringValue(SELECTTOPNONTERMINAL_VALUE);
}

void FLT_setRemoveCyclesFlag(ATbool value) {
  OPT_setFlag(REMOVECYCLES_FLAG, value);
}

ATbool FLT_getRemoveCyclesFlag() {
  return OPT_getFlag(REMOVECYCLES_FLAG);
}

void FLT_printOptions() {
  ATwarning("%s = %d\n", FILTER_FLAG, FLT_getFilterFlag());
  ATwarning("%s = %d\n", DIRECT_PREFERENCE_FLAG, FLT_getDirectPreferenceFlag());
  ATwarning("%s = %d\n", INDIRECT_PREFERENCE_FLAG, FLT_getIndirectPreferenceFlag());
  ATwarning("%s = %d\n", PREFERENCE_COUNT_FLAG, FLT_getPreferenceCountFlag());
  ATwarning("%s = %d\n", INJECTION_COUNT_FLAG, FLT_getInjectionCountFlag());
  ATwarning("%s = %d\n", PRIORITY_FLAG, FLT_getPriorityFlag());
  ATwarning("%s = %d\n", REJECT_FLAG, FLT_getRejectFlag());
  ATwarning("%s = %d\n", SELECTTOPNONTERMINAL_FLAG, FLT_getSelectTopNonterminalFlag());
  ATwarning("%s = %s\n", SELECTTOPNONTERMINAL_VALUE, FLT_getTopNonterminal());
  ATwarning("%s = %d\n", REMOVECYCLES_FLAG, FLT_getRemoveCyclesFlag());
}

