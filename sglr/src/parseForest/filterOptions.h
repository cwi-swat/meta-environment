/*$Id$*/

/** \file
 * \ingroup parseForest
 */

#ifndef __FILTER_OPTIONS_H__
#define __FILTER_OPTIONS_H__

#include <aterm2.h>

void   FLT_initialize();
void   FLT_initializeDefaultOptions();
void   FLT_setFilterFlag(ATbool value);
ATbool FLT_getFilterFlag();
void   FLT_setDirectPreferenceFlag(ATbool value);
ATbool FLT_getDirectPreferenceFlag();
void   FLT_setIndirectPreferenceFlag(ATbool value);
ATbool FLT_getIndirectPreferenceFlag();
void   FLT_setPreferenceCountFlag(ATbool value);
ATbool FLT_getPreferenceCountFlag();
void   FLT_setInjectionCountFlag(ATbool value);
ATbool FLT_getInjectionCountFlag();
void   FLT_setPriorityFlag(ATbool value);
ATbool FLT_getPriorityFlag();
void   FLT_setRejectFlag(ATbool value);
ATbool FLT_getRejectFlag();
void   FLT_setSelectTopNonterminalFlag(ATbool value);
ATbool FLT_getSelectTopNonterminalFlag();
void   FLT_setRemoveCyclesFlag(ATbool value);
ATbool FLT_getRemoveCyclesFlag();

void   FLT_setTopNonterminal(const char* nonterminal);
const char* FLT_getTopNonterminal();

void   FLT_setTopNonterminalIsATermFlag(ATbool value);
ATbool FLT_getTopNonterminalIsATermFlag();

void FLT_printOptions();

#endif /* __FILTER_OPTIONS_H__ */
