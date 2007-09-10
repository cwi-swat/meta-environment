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
extern int SGLR_STATS_nodesRejected;

extern int SGLR_STATS_gssEdgesTraversed;
extern int SGLR_STATS_gssEdgesSearched;
extern int SGLR_STATS_gssEdgesCreated;
extern int SGLR_STATS_gssNodesCreated;
extern int SGLR_STATS_gssNodesDeleted;

extern int SGLR_STATS_shiftsDone;
extern int SGLR_STATS_reductionsDone;
extern int SGLR_STATS_reductionsLADone;
extern int SGLR_STATS_reductionsAddedToReductionQueue;
extern int SGLR_STATS_maxSizeOfReductionQueue;
extern int SGLR_STATS_shiftsAddedToShiftQueue;
extern int SGLR_STATS_maxSizeOfShiftQueue;

extern int *SGLR_STATS_reductionLengthsDone;
extern int *SGLR_STATS_edgeVisitsPerReductionLength;
/* Tree construction statistics. */
extern int SGLR_STATS_ambiguityClustersCreated;
extern int SGLR_STATS_existingAmbiguityClustersFound;
extern int SGLR_STATS_prodTreeNodesCreated;
extern int SGLR_STATS_symbolTreeNodesCreated;

extern int SGLR_STATS_preferenceCount;
extern int SGLR_STATS_preferenceCountCalls;
extern int SGLR_STATS_injectionCount;
extern int SGLR_STATS_injectionCountCalls;
extern int SGLR_STATS_ambNodesCreated;
extern int SGLR_STATS_totalAmbCount;
extern int SGLR_STATS_ambCallsCount;
extern int SGLR_STATS_clustersVisitedCount;

extern double SGLR_STATS_parseTableTime;
extern double SGLR_STATS_parsingTime;
extern double SGLR_STATS_flatteningTime;
extern double SGLR_STATS_filteringTime;

extern const char *SGLR_STATS_inputStringFilename;
extern const char *SGLR_STATS_parseTableFilename;

void SGLR_STATS_initializeHistograms(int length);
void SGLR_STATS_print(void);

#if SGLR_COLLECT_STATISTICS
#define SGLR_STATS_addReductionLength(length)\
  SGLR_STATS_reductionLengthsDone[length]++;
#else
#define SGLR_STATS_addReductionLength(length) ;
#endif

#if SGLR_COLLECT_STATISTICS
#define SGLR_STATS_addEdgeVisitForReductionLength(reductionLength, edgeVisits)\
  SGLR_STATS_edgeVisitsPerReductionLength[reductionLength]+=edgeVisits;
#else
#define SGLR_STATS_edgeVisitiForReductionLength(reductionLength, edgeVisits) ;
#endif

#endif /* __PARSER_STATISTICS__ */
