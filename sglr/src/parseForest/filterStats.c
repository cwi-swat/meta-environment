/* $Id$ */

/** \file
 * \ingroup parseForest
 *
 */

#include "filterStats.h"

static int numPreferenceCount;
static int numPreferenceCountCalls;
static int numInjectionCount;
static int numInjectionCountCalls;
static int ambCount = 0;      /**<  */
static int totalAmbCount = 0; /**< the total number of ambiguities created. */
static int ambCallsCount = 0; /**< the number of times a call to 
                                SG_CreateAmbCluster() is done.*/
static int clustersVisitedCount = 0;


void FLT_resetNumPreferenceCount() {
      numPreferenceCount = 0;
}

int FLT_getNumPreferenceCount() {
      return numPreferenceCount;
}

int FLT_incrementNumPreferenceCount() {
      return ++numPreferenceCount;
}

int FLT_decrementNumPreferenceCount() {
      return --numPreferenceCount;
}


void FLT_resetNumPreferenceCountCalls() {
    numPreferenceCountCalls = 0;
}

int FLT_getNumPreferenceCountCalls() {
    return numPreferenceCountCalls;
}

int FLT_incrementNumPreferenceCountCalls() {
    return ++numPreferenceCountCalls;
}

int FLT_decrementNumPreferenceCountCalls() {
    return --numPreferenceCountCalls;
}


void FLT_resetNumInjectionCount() {
    numInjectionCount = 0;
}

int FLT_getNumInjectionCount() {
    return numInjectionCount;
}

int FLT_incrementNumInjectionCount() {
    return ++numInjectionCount;
}

int FLT_decrementNumInjectionCount() {
    return --numInjectionCount;
}


void FLT_resetNumInjectionCountCalls() {
  numInjectionCountCalls = 0;
}

int FLT_getNumInjectionCountCalls() {
  return numInjectionCountCalls;
}

int FLT_incrementNumInjectionCountCalls() {
  return ++numInjectionCountCalls;
}

int FLT_decrementNumInjectionCountCalls() {
  return --numInjectionCountCalls;
}


void FLT_resetAmbCallsCount() {
    ambCallsCount = 0;
}

int FLT_getAmbCallsCount() {
    return ambCallsCount;
}

int FLT_incrementAmbCallsCount() {
    return ++ambCallsCount;
}

int FLT_decrementAmbCallsCount() {
    return --ambCallsCount;
}


void FLT_resetTotalAmbCount() {
    totalAmbCount = 0;
}

int FLT_getTotalAmbCount() {
    return totalAmbCount;
}

int FLT_incrementTotalAmbCount() {
    return ++totalAmbCount;
}

int FLT_decrementTotalAmbCount() {
    return --totalAmbCount;
}


void FLT_resetAmbCount() {
  ambCount = 0;  
}

int FLT_getAmbCount() {
  return ambCount;
}

int FLT_incrementAmbCount() {
  return ++ambCount;
}

int FLT_decrementAmbCount() {
  return --ambCount;
}


void FLT_resetClustersVisitedCount() {
    clustersVisitedCount = 0;
}

int FLT_getClustersVisitedCount() {
    return clustersVisitedCount;
}

int FLT_incrementClustersVisitedCount() {
    return ++clustersVisitedCount;
}

int FLT_decrementClustersVisitedCount() {
    return --clustersVisitedCount;
}

