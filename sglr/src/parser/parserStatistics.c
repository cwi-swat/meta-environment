/* $Id$ */

/** \file
 * \ingroup parser
 *
 */

#include <logging.h>
#include <rsrc-usage.h>

#include "parserStatistics.h"
#include "parserOptions.h"

ATbool SGLR_STATS_rejects = ATfalse;
ATbool SGLR_STATS_priorities = ATfalse;
ATbool SGLR_STATS_prefers = ATfalse;
ATbool SGLR_STATS_avoids = ATfalse;

int SGLR_STATS_gotos = 0;
int SGLR_STATS_actions = 0;
int SGLR_STATS_states = 0;
int SGLR_STATS_prods = 0;
int SGLR_STATS_actionEntries = 0;
int SGLR_STATS_gotoEntries = 0;

long SGLR_STATS_initialMemAllocated = 0;
long SGLR_STATS_initialMRSS = 0; 
long SGLR_STATS_endMRSS = 0;
long SGLR_STATS_emptyParseTableMemAllocated = 0;
long SGLR_STATS_fullParseTableMemAllocated = 0;
long SGLR_STATS_beforeParseTableCreationMRSS = 0;
long SGLR_STATS_emptyParseTableMRSS = 0;
long SGLR_STATS_fullParseTableMRSS = 0;
long SGLR_STATS_parsingMemAllocated = 0;
long SGLR_STATS_majorPageFaults = 0; 
long SGLR_STATS_minorPageFaults = 0;

int SGLR_STATS_linesParsed = 0;
int SGLR_STATS_charactersParsed = 0;

int SGLR_STATS_rejectedTreesCreated = 0; /* these two are prob the same */
int SGLR_STATS_rejectedEdgesCreated = 0;
int SGLR_STATS_existingEdgesRejected = 0;
int SGLR_STATS_rejectedReductionsDone = 0;
int SGLR_STATS_nodesRejected = 0;

int SGLR_STATS_gssEdgesTraversed = 0;
int SGLR_STATS_gssEdgesSearched = 0;
int SGLR_STATS_gssEdgesCreated = 0;
int SGLR_STATS_gssNodesCreated = 0;
int SGLR_STATS_gssNodesDeleted = 0;

int SGLR_STATS_shiftsDone = 0;
int SGLR_STATS_reductionsDone = 0;
int SGLR_STATS_reductionsLADone = 0;
int SGLR_STATS_reductionsAddedToReductionQueue = 0;
int SGLR_STATS_maxSizeOfReductionQueue = 0;
int SGLR_STATS_shiftsAddedToShiftQueue = 0;
int SGLR_STATS_maxSizeOfShiftQueue = 0;

int *SGLR_STATS_reductionLengthsDone = 0;
int *SGLR_STATS_edgeVisitsPerReductionLength = 0;

/* Tree construction statistics. */
int SGLR_STATS_ambiguityClustersCreated = 0;
int SGLR_STATS_existingAmbiguityClustersFound = 0;
int SGLR_STATS_prodTreeNodesCreated = 0;
int SGLR_STATS_symbolTreeNodesCreated = 0;

/* Post parse filtering statistics. */
int SGLR_STATS_treeNodesVisited = 0;
int SGLR_STATS_treesFiltered = 0;
int SGLR_STATS_priorityConflictsFound = 0;
int SGLR_STATS_rejectedTreesFound = 0;

int SGLR_STATS_preferenceCount = 0;
int SGLR_STATS_preferenceCountCalls = 0;
int SGLR_STATS_injectionCount = 0;
int SGLR_STATS_injectionCountCalls = 0;
int SGLR_STATS_ambNodesCreated = 0; /**< post parse creation of amb nodes */
int SGLR_STATS_totalAmbCount = 0; /**< the total number of ambiguities created. */
int SGLR_STATS_ambCallsCount = 0; /**< the number of times a call to 
                                SG_CreateAmbCluster() is done.*/
int SGLR_STATS_clustersVisitedCount = 0;




double SGLR_STATS_parseTableTime = 0.0;
double SGLR_STATS_parsingTime = 0.0;
double SGLR_STATS_flatteningTime = 0.0;
double SGLR_STATS_filteringTime = 0.0;

const char *SGLR_STATS_inputStringFilename;
const char *SGLR_STATS_parseTableFilename;
static int maxReductionLength = 0;

void SGLR_STATS_initializeHistograms(int length) {
  maxReductionLength = length;
  SGLR_STATS_reductionLengthsDone = (int*) calloc(maxReductionLength, sizeof(int));
  SGLR_STATS_edgeVisitsPerReductionLength = (int*) calloc(maxReductionLength, sizeof(int));
}

void SGLR_STATS_print(void) {
  int i;

  if (PARSER_getVerboseFlag) {
    ATwarning("Logging statistics\n");
  }

  fprintf(LOG_log(), "\n---Reading parse table ---\n");
  fprintf(LOG_log(), "Parse table name: %s\n", SGLR_STATS_parseTableFilename);
  fprintf(LOG_log(), "Obtaining parse table took %.6fs\n", SGLR_STATS_parseTableTime);
  fprintf(LOG_log(), "%scludes rejects\n", SGLR_STATS_rejects?"In":"Ex");
  fprintf(LOG_log(), "%scludes priorities\n", SGLR_STATS_priorities?"In":"Ex");
  fprintf(LOG_log(), "%scludes prefer actions\n", SGLR_STATS_prefers?"In":"Ex");
  fprintf(LOG_log(), "%scludes avoid actions\n", SGLR_STATS_avoids?"In":"Ex");

  fprintf(LOG_log(), "No. of gotos: %d\nNo. of actions: %d\n", SGLR_STATS_gotos, SGLR_STATS_actions);

  fprintf(LOG_log(), "No. of states: %ld\n" 
      "No. of productions: %ld\n"
      "No. of action entries: %ld\n"
      "No. of goto entries: %ld\n",
      (long) SGLR_STATS_states, (long) SGLR_STATS_prods,
      (long) SGLR_STATS_actionEntries, (long) SGLR_STATS_gotoEntries);

  fprintf(LOG_log(), "[mem] extra ATerm memory allocated for empty table: %ld\n", SGLR_STATS_emptyParseTableMemAllocated);
  fprintf(LOG_log(), "[mem] extra ATerm memory allocated while filling table: %ld\n", SGLR_STATS_fullParseTableMemAllocated);
  fprintf(LOG_log(), "[mem] PT build: %ld before, %ld after table creation\n", SGLR_STATS_beforeParseTableCreationMRSS, SGLR_STATS_emptyParseTableMRSS);
  fprintf(LOG_log(), "[mem] PT build: %ld before, %ld after filling table\n", SGLR_STATS_emptyParseTableMRSS, SGLR_STATS_fullParseTableMRSS);
 
  fprintf(LOG_log(), "\n--- Parsing ---\n");
  fprintf(LOG_log(), "Parse time: %.6fs\n", SGLR_STATS_parsingTime);
  fprintf(LOG_log(), "Lines parsed: %d\n", SGLR_STATS_linesParsed);
  fprintf(LOG_log(), "Characters/second: %.0f\n\n", SGLR_STATS_parsingTime < 1.0e-4 ? 0 : SGLR_STATS_charactersParsed/SGLR_STATS_parsingTime);

  fprintf(LOG_log(), "Reductions done: %d\n", SGLR_STATS_reductionsDone);
  fprintf(LOG_log(), "Follow restricted reductions done: %d\n", SGLR_STATS_reductionsLADone);
  fprintf(LOG_log(), "Rejected reductions done: %d\n", SGLR_STATS_rejectedReductionsDone);
  fprintf(LOG_log(), "Reductions/character: %f\n", (double)SGLR_STATS_reductionsDone/(double)SGLR_STATS_charactersParsed);
  fprintf(LOG_log(), "Reductions added to reduction queue: %d\n", SGLR_STATS_reductionsAddedToReductionQueue);
  fprintf(LOG_log(), "Max size of reduction queue: %d\n", SGLR_STATS_maxSizeOfReductionQueue);

  fprintf(LOG_log(), "Shifts done: %d\n", SGLR_STATS_shiftsDone);
  fprintf(LOG_log(), "Shifts added to shift queue: %d\n", SGLR_STATS_shiftsAddedToShiftQueue);
  fprintf(LOG_log(), "Max size of shift queue: %d\n\n", SGLR_STATS_maxSizeOfShiftQueue);

  fprintf(LOG_log(), "GSS nodes created: %d\n", SGLR_STATS_gssNodesCreated);
  fprintf(LOG_log(), "GSS nodes deleted: %d\n", SGLR_STATS_gssNodesDeleted);
  fprintf(LOG_log(), "GSS edges created: %d\n", SGLR_STATS_gssEdgesCreated);
  fprintf(LOG_log(), "GSS edges traversed: %d\n", SGLR_STATS_gssEdgesTraversed);
  fprintf(LOG_log(), "GSS edges searched: %d\n", SGLR_STATS_gssEdgesSearched);

  fprintf(LOG_log(), "Rejected trees created: %d\n\n", SGLR_STATS_rejectedTreesCreated);
  fprintf(LOG_log(), "Rejected GSS nodes: %d\n", SGLR_STATS_nodesRejected);
  fprintf(LOG_log(), "Rejected edges created: %d\n", SGLR_STATS_rejectedEdgesCreated);
  fprintf(LOG_log(), "Existing (non-rejected) edges marked rejected: %d\n", SGLR_STATS_existingEdgesRejected);


  fprintf(LOG_log(), "Production tree node created: %d\n", SGLR_STATS_prodTreeNodesCreated);
  fprintf(LOG_log(), "Leaf nodes created: %d\n", SGLR_STATS_symbolTreeNodesCreated);
  fprintf(LOG_log(), "Number of ambiguities created: %d\n", SGLR_STATS_ambiguityClustersCreated);
  fprintf(LOG_log(), "Existing ambiguities found: %d\n", SGLR_STATS_existingAmbiguityClustersFound);

  fprintf(LOG_log(), "Reduction lengths done histogram:\n");
  fprintf(LOG_log(), "rel[int, int] reductionLengths = \n");
  fprintf(LOG_log(), "{\n");
  for (i = 0; i < maxReductionLength; i++) {
    fprintf(LOG_log(), "<%d, %d>", i, SGLR_STATS_reductionLengthsDone[i]);
     if (i < maxReductionLength-1) {
      fprintf(LOG_log(), ",\n");
    }
  }
  fprintf(LOG_log(), "\n}\n");

  fprintf(LOG_log(), "Edge visits per reduction done histogram:\n");
  fprintf(LOG_log(), "rel[int, int] edgeVisitsPerReduction = \n");
  fprintf(LOG_log(), "{\n");
  for (i = 0; i < maxReductionLength; i++) {
    fprintf(LOG_log(), "<%d, %d>", i, SGLR_STATS_edgeVisitsPerReductionLength[i]);
    if (i < maxReductionLength-1) {
      fprintf(LOG_log(), ",\n");
    }
  }
  fprintf(LOG_log(), "\n}\n");

  fprintf(LOG_log(), "[mem] extra ATerm memory allocated while parsing: %ld\n", SGLR_STATS_parsingMemAllocated);

  fprintf(LOG_log(), "Minor page faults: %ld\n", SGLR_STATS_minorPageFaults);
  fprintf(LOG_log(), "Major page faults: %ld\n", SGLR_STATS_majorPageFaults);

  if(SGLR_STATS_minorPageFaults > 0)
    fprintf(LOG_log(), "Characters/minor fault: %ld\n", SGLR_STATS_charactersParsed/SGLR_STATS_minorPageFaults);


  fprintf(LOG_log(), "\n--- Filtering ---\n");
  fprintf(LOG_log(), "Filtering took %.6fs\n", SGLR_STATS_filteringTime);
  fprintf(LOG_log(), "Number of preference-count comparisons done: total %d, successful %d\n", SGLR_STATS_preferenceCountCalls, SGLR_STATS_preferenceCount);
  fprintf(LOG_log(), "Number of injection-count comparisons done: total %d, successful %d\n", SGLR_STATS_injectionCountCalls, SGLR_STATS_injectionCount);


  fprintf(LOG_log(), "\n--- Flattening ---\n");
  fprintf(LOG_log(), "Flattening took %.6fs\n", SGLR_STATS_flatteningTime);

  fprintf(LOG_log(), "[mem] initial ATerm memory: %ld\n", SGLR_STATS_initialMemAllocated);
  fprintf(LOG_log(), "[mem] ATerm init: %ld before, %ld after\n", SGLR_STATS_initialMRSS, SGLR_STATS_endMRSS);
}
