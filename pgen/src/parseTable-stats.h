/* $Id$ */

#ifndef __PARSETABLESTATS_H__
#define __PARSETABLESTATS_H__

#include <pgenOptions.h>

extern unsigned int PGEN_STATS_actions; 
extern unsigned int PGEN_STATS_gotos;  
extern unsigned int PGEN_STATS_items; 

extern unsigned int PGEN_STATS_maxActionsInStates;
extern unsigned int PGEN_STATS_maxGotosInState; 
extern unsigned int PGEN_STATS_maxItemsInState; 

extern int PGEN_STATS_kernelProductions;
extern int PGEN_STATS_productions;
extern int PGEN_STATS_maxProductionLhsLength;
extern int PGEN_STATS_conficts;
extern unsigned int PGEN_STATS_reductions;
extern unsigned int PGEN_STATS_shifts;
extern unsigned int PGEN_STATS_followRestrictedReductions;
extern int PGEN_STATS_priorities;

extern double PGEN_STATS_normalizationTime;
extern double PGEN_STATS_generationTime;

void PGEN_STATS_initialize(void);
void PGEN_STATS_print(void);

#if PGEN_COLLECT_STATISTICS
#define PGEN_STATS_increaseActions(value)\
  if (PGEN_getStatsFlag) {\
    PGEN_STATS_actions += value;\
    if (value > PGEN_STATS_maxActionsInStates) {\
      PGEN_STATS_maxActionsInStates = value;\
    }\
  }
#else 
#define PGEN_STATS_increaseActions(value) ;
#endif

#if PGEN_COLLECT_STATISTICS
#define PGEN_STATS_increaseGotos(value)\
  if (PGEN_getStatsFlag) {\
    PGEN_STATS_gotos += value;\
    if (value > PGEN_STATS_maxGotosInState) {\
      PGEN_STATS_maxGotosInState = value;\
    }\
  }
#else 
#define PGEN_STATS_increaseGotos(value) ;
#endif

#if PGEN_COLLECT_STATISTICS
#define PGEN_STATS_increaseItems(value)\
  if (PGEN_getStatsFlag) {\
    PGEN_STATS_items += value;\
    if (value > PGEN_STATS_maxItemsInState) {\
      PGEN_STATS_maxItemsInState = value;\
    }\
  }
#else 
#define PGEN_STATS_increaseItems(value) ;
#endif

#if PGEN_COLLECT_STATISTICS
#define PGEN_STATS_setCount(counter, value)\
  if (PGEN_getStatsFlag) {\
    counter = value;\
  }
#else
#define PGEN_STATS_setCount(counter, value) ;
#endif


#endif /* __PARSETABLESTATS_H__ */
