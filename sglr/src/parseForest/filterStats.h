/* $Idi$ */

/** \file
 * \ingroup parseForest
 * 
 */

#ifndef _FILTER_STATS_H_
#define _FILTER_STATS_H_

void FLT_resetNumPreferenceCount();
int  FLT_getNumPreferenceCount();
int  FLT_incrementNumPreferenceCount();
int  FLT_decrementNumPreferenceCount();
  
void FLT_resetNumPreferenceCountCalls();
int  FLT_getNumPreferenceCountCalls();
int  FLT_incrementNumPreferenceCountCalls();
int  FLT_decrementNumPreferenceCountCalls();

void FLT_resetNumInjectionCount();
int  FLT_getNumInjectionCount();
int  FLT_incrementNumInjectionCount();
int  FLT_decrementNumInjectionCount();

void FLT_resetNumInjectionCountCalls();
int  FLT_getNumInjectionCountCalls();
int  FLT_incrementNumInjectionCountCalls();
int  FLT_decrementNumInjectionCountCalls();

void FLT_resetAmbCallsCount();
int  FLT_getAmbCallsCount();
int  FLT_incrementAmbCallsCount();
int  FLT_decrementAmbCallsCount();

void FLT_resetClustersVisitedCount();
int  FLT_getClustersVisitedCount();
int  FLT_incrementClustersVisitedCount();
int  FLT_decrementClustersVisitedCount();

void FLT_resetTotalAmbCount();
int  FLT_getTotalAmbCount();
int  FLT_incrementTotalAmbCount();
int  FLT_decrementTotalAmbCount();

void FLT_resetAmbCount();
int  FLT_getAmbCount();
int  FLT_incrementAmbCount();
int  FLT_decrementAmbCount();

#endif /* _FILTER_STATS_H_ */
