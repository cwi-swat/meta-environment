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
static int TOPNONTERMINALISATERM_FLAG;

void FLT_initialize(){
  FILTER_FLAG = OPT_getFlagOptionId();
  DIRECT_PREFERENCE_FLAG = OPT_getFlagOptionId();
  INDIRECT_PREFERENCE_FLAG = OPT_getFlagOptionId();
  PREFERENCE_COUNT_FLAG = OPT_getFlagOptionId();
  INJECTION_COUNT_FLAG = OPT_getFlagOptionId();
  PRIORITY_FLAG = OPT_getFlagOptionId();
  REJECT_FLAG = OPT_getFlagOptionId();
  SELECTTOPNONTERMINAL_FLAG = OPT_getFlagOptionId();
  SELECTTOPNONTERMINAL_VALUE = OPT_getStringOptionId();
  TOPNONTERMINALISATERM_FLAG = OPT_getFlagOptionId();
  REMOVECYCLES_FLAG = OPT_getFlagOptionId();
}

void FLT_initializeDefaultOptions() {
  FLT_setFilterFlag(ATtrue);
  FLT_setIndirectPreferenceFlag(ATtrue);
  FLT_setPreferenceCountFlag(ATfalse);
  FLT_setInjectionCountFlag(ATfalse);
  FLT_setPriorityFlag(ATtrue);
  FLT_setRejectFlag(ATtrue);
  FLT_setSelectTopNonterminalFlag(ATfalse);
  FLT_setTopNonterminalIsATermFlag(ATfalse);
  FLT_setTopNonterminal("***NOT SET***");
}

void FLT_setFilterFlag(ATbool value) {
  OPT_setFlag(FILTER_FLAG, value);

  if (value == ATfalse) {
    FLT_setDirectPreferenceFlag(ATfalse); 
    FLT_setIndirectPreferenceFlag(ATfalse); 
    FLT_setPreferenceCountFlag(ATfalse); 
    FLT_setInjectionCountFlag(ATfalse); 
    FLT_setPriorityFlag(ATfalse); 
    FLT_setRejectFlag(ATfalse); 
    FLT_setSelectTopNonterminalFlag(ATfalse);
    FLT_setTopNonterminalIsATermFlag(ATfalse);
    FLT_setRemoveCyclesFlag(ATfalse); 
  }
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

void FLT_setTopNonterminalIsATermFlag(ATbool value) {
  OPT_setFlag(TOPNONTERMINALISATERM_FLAG, value);
}

ATbool FLT_getTopNonterminalIsATermFlag() {
  return OPT_getFlag(TOPNONTERMINALISATERM_FLAG);
}

void FLT_setRemoveCyclesFlag(ATbool value) {
  OPT_setFlag(REMOVECYCLES_FLAG, value);
}

ATbool FLT_getRemoveCyclesFlag() {
  return OPT_getFlag(REMOVECYCLES_FLAG);
}

void FLT_printOptions() {
  ATwarning("FILTER_FLAG = %s\n", FLT_getFilterFlag()?"True":"False");
  ATwarning("DIRECT_PREFERENCE_FLAG = %s\n", FLT_getDirectPreferenceFlag()?"True":"False");
  ATwarning("INDIRECT_PREFERENCE_FLAG = %s\n", FLT_getIndirectPreferenceFlag()?"True":"False");
  ATwarning("PREFERENCE_COUNT_FLAG = %s\n", FLT_getPreferenceCountFlag()?"True":"False");
  ATwarning("INJECTION_COUNT_FLAG = %s\n", FLT_getInjectionCountFlag()?"True":"False");
  ATwarning("PRIORITY_FLAG = %s\n", FLT_getPriorityFlag()?"True":"False");
  ATwarning("REJECT_FLAG = %s\n", FLT_getRejectFlag()?"True":"False");
  ATwarning("SELECTTOPNONTERMINAL_FLAG = %s\n", FLT_getSelectTopNonterminalFlag()?"True":"False");
  ATwarning("SELECTTOPNONTERMINAL_VALUE = %s\n", FLT_getTopNonterminal()?"True":"False");
  ATwarning("TOPNONTERMINALISATERM_FLAG = %s\n", FLT_getTopNonterminalIsATermFlag()?"True":"False");
  ATwarning("REMOVECYCLES_FLAG = %s\n", FLT_getRemoveCyclesFlag()?"True":"False");
}

