/* $Id$ */

/** \file
 * \ingroup parser
 *
 * Storage of parsing algorithm's performance statistics. Implemented as macros
 * for performance. 
 */
#ifndef __PARSER_STATISTICS__
#define __PARSER_STATISTICS__

#include <stdlib.h>
#include <aterm1.h>
#include <mainOptions.h>

extern ATbool SGLR_STATS_rejects;
extern ATbool SGLR_STATS_priorities;
extern ATbool SGLR_STATS_prefers;
extern ATbool SGLR_STATS_avoids;

extern int SGLR_STATS_gotos;
extern int SGLR_STATS_actions;
extern int SGLR_STATS_states;
extern int SGLR_STATS_prods;
extern int SGLR_STATS_actionEntries;
extern int SGLR_STATS_gotoEntries;

extern long SGLR_STATS_initialMemAllocated;
extern long SGLR_STATS_initialMRSS; 
extern long SGLR_STATS_endMRSS;
extern long SGLR_STATS_emptyParseTableMemAllocated;
extern long SGLR_STATS_fullParseTableMemAllocated;
extern long SGLR_STATS_beforeParseTableCreationMRSS;
extern long SGLR_STATS_emptyParseTableMRSS;
extern long SGLR_STATS_fullParseTableMRSS;
extern long SGLR_STATS_parsingMemAllocated;
extern long SGLR_STATS_majorPageFaults; 
extern long SGLR_STATS_minorPageFaults;

extern int SGLR_STATS_linesParsed;
extern int SGLR_STATS_charactersParsed;

extern int SGLR_STATS_rejectedTreesCreated; /* these two are prob the same */
extern int SGLR_STATS_rejectedEdgesCreated;
extern int SGLR_STATS_existingEdgesRejected;
extern int SGLR_STATS_rejectedReductionsDone;
extern unsigned int SGLR_STATS_nodesNormal;
extern unsigned int SGLR_STATS_nodesRejected;
extern unsigned int SGLR_STATS_nodesPartiallyRejected;

extern long long SGLR_STATS_gssLimitedEdgesTraversed;
extern long long SGLR_STATS_gssLimitedEdgesSearched;
extern long long SGLR_STATS_gssEdgesTraversed;
extern long long SGLR_STATS_gssEdgesSearched;
extern unsigned int SGLR_STATS_gssEdgesCreated;
extern unsigned int SGLR_STATS_gssNodesCreated;
extern unsigned int SGLR_STATS_gssNodesDeleted;

extern unsigned int SGLR_STATS_shiftsDone;
extern unsigned int SGLR_STATS_reductionsDone;
extern unsigned int SGLR_STATS_reductionsLADone;
extern unsigned int SGLR_STATS_limitedReductionsDone;
extern unsigned int SGLR_STATS_limitedLAReductionsDone;
extern int SGLR_STATS_shiftsAddedToShiftQueue;
extern int SGLR_STATS_maxSizeOfShiftQueue;

extern int *SGLR_STATS_reductionLengthsDone;
extern int *SGLR_STATS_edgeVisitsPerReductionLength;
/*extern int *SGLR_STATS_edgeVisitsPerLevel;*/

/* Tree construction statistics. */
extern int SGLR_STATS_ambiguityClustersCreated;
extern int SGLR_STATS_existingAmbiguityClustersFound;
extern int SGLR_STATS_maxClusterLength; 
extern int *SGLR_STATS_clusterHistogram;

extern unsigned int SGLR_STATS_prodTreeNodesCreated;
extern int SGLR_STATS_symbolTreeNodesCreated;
extern int SGLR_STATS_cyclicTreeNodesCreated;
extern int SGLR_STATS_cyclesDetected;

extern int SGLR_STATS_treesDirectPreferenceFiltered;
extern int SGLR_STATS_treesIndirectPreferenceFiltered;
extern int SGLR_STATS_treesPreferred;
extern int SGLR_STATS_treesPreferenceCountFiltered;
extern int SGLR_STATS_treesInjectionCountFiltered;
extern int SGLR_STATS_ambiguityPriorityFiltered;
extern int SGLR_STATS_treesPriorityFiltered;
extern int SGLR_STATS_treesRejectFiltered;

extern int SGLR_STATS_preferenceCount;
extern int SGLR_STATS_preferenceCountCalls;
extern int SGLR_STATS_injectionCount;
extern int SGLR_STATS_injectionCountCalls;
extern int SGLR_STATS_totalAmbCount;
extern int SGLR_STATS_ambCallsCount;
extern int SGLR_STATS_clustersVisitedCount;
extern int SGLR_STATS_prodTreeNodesCreatedDuringFiltering;
extern int SGLR_STATS_ambTreeNodesCreatedDuringFiltering;
extern int SGLR_STATS_cyclicTreeNodesCreatedDuringFiltering;

extern int SGLR_STATS_ambNodesInFilteredTree;
extern unsigned int SGLR_STATS_prodNodesInFilteredTree;
extern int SGLR_STATS_symbolNodesInFilteredTree;
extern int SGLR_STATS_cyclicNodesInFilteredTree;

extern double SGLR_STATS_parseTableTime;
extern double SGLR_STATS_parsingTime;
extern double SGLR_STATS_flatteningTime;
extern double SGLR_STATS_filteringTime;

extern const char *SGLR_STATS_inputStringFilename;
extern const char *SGLR_STATS_parseTableFilename;

void SGLR_STATS_initializeHistograms(int length, int inputLength);
void SGLR_STATS_initializeClusterHistogram(void);
void SGLR_STATS_destroyHistograms();
void SGLR_STATS_print(void);

#if SGLR_COLLECT_STATISTICS
#define SGLR_STATS_setCount(counter, value)\
  if (MAIN_getStatsFlag) {\
    counter = value;\
  }
#else
#define SGLR_STATS_setCount(counter, value) ;
#endif

#if SGLR_COLLECT_STATISTICS
#define SGLR_STATS_incrementCount(counter)\
  if (MAIN_getStatsFlag) {\
    counter++;\
  }
#else
#define SGLR_STATS_incrementCount(counter) ;
#endif

#if SGLR_COLLECT_STATISTICS
#define SGLR_STATS_incrementCountConditionally(counter, cond)\
  if (MAIN_getStatsFlag && cond) {\
    counter++;\
  }
#else
#define SGLR_STATS_incrementCountConditionally(counter, cond) ;
#endif

#if SGLR_COLLECT_STATISTICS
#define SGLR_STATS_addToCount(counter, addition)\
  if (MAIN_getStatsFlag) {\
    counter += addition;\
  }
#else
#define SGLR_STATS_addToCount(counter, addition) ;
#endif

#if SGLR_COLLECT_STATISTICS
#define SGLR_STATS_changeRejectedNodeCount(function)\
  if (MAIN_getStatsFlag) {\
    if (function) {\
      SGLR_STATS_nodesRejected++;\
      SGLR_STATS_nodesPartiallyRejected--;\
    }\
    else {\
      SGLR_STATS_nodesPartiallyRejected++;\
      SGLR_STATS_nodesRejected--;\
    }\
  }
#else
#define SGLR_STATS_changeRejectedNodeCount(function) ;
#endif

#if SGLR_COLLECT_STATISTICS
#define SGLR_STATS_addReductionLength(length)\
  if (MAIN_getStatsFlag) {\
    SGLR_STATS_reductionLengthsDone[length]++;\
  }
#else
#define SGLR_STATS_addReductionLength(length) ;
#endif

#if SGLR_COLLECT_STATISTICS
#define SGLR_STATS_addEdgeVisitForReductionLength(reductionLength, edgeVisits)\
  if (MAIN_getStatsFlag) {\
    SGLR_STATS_edgeVisitsPerReductionLength[reductionLength]+=edgeVisits;\
  }
#else
#define SGLR_STATS_addEdgeVisitForReductionLength(reductionLength, edgeVisits) ;
#endif

#if SGLR_COLLECT_STATISTICS
#define SGLR_STATS_addEdgeVisitsForLevel(level, edgeVisits)\
  if (MAIN_getStatsFlag) {\
    /*SGLR_STATS_edgeVisitsPerLevel[level] += edgeVisits;*/ ;\
  }
#else
#define SGLR_STATS_addEdgeVisitsForLevel(level, edgeVisits) ;
#endif

#if SGLR_COLLECT_STATISTICS
#define SGLR_STATS_clusterHistogramPut(clusterLength)\
  if (MAIN_getStatsFlag) {\
    SGLR_STATS_clusterHistogram[clusterLength]++;\
  }
#else
#define SGLR_STATS_clusterHistogramPut(clusterLength) ;
#endif

#endif /* __PARSER_STATISTICS__ */
